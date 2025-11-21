#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "tac.h"
#include "optimize.h"

/* global var */
int scope, next_tmp, next_label;
SYM *sym_tab_global, *sym_tab_local;
TAC *tac_first, *tac_last;
BASIC_BLOCK *bb_list = NULL;
BASIC_BLOCK *bb_tail = NULL;

#define LOOP_MAX_DEPTH 100
static SYM *loop_continue_stack[LOOP_MAX_DEPTH];
static SYM *loop_end_stack[LOOP_MAX_DEPTH];
static int loop_depth = 0;

static STRUCT *structs = NULL;
static STRUCT *cur_structs = NULL;

int local_offset = 8;
// 常量符号表
typedef struct CMap
{
	SYM *var;		// 变量符号
	SYM *const_sym; // 对应常数符号
	struct CMap *next;
} CMap;

static SYM *cmap_get(CMap *m, SYM *v)
{
	for (; m; m = m->next)
	{
		if (m->var == v)
			return m->const_sym; // 若v在常量符号表中，则返回对应常数的符号项
	}
	return NULL;
}

static void cmap_set(CMap **m, SYM *v, SYM *c)
{
	for (CMap *p = *m; p; p = p->next)
	{
		if (p->var == v)
		{
			p->const_sym = c;
			return;
		}
	}

	// 没找到新建
	CMap *n = (CMap *)malloc(sizeof(CMap));
	n->var = v;
	n->const_sym = c;
	n->next = *m;
}

static void cmap_kill(CMap **m, SYM *v)
{
	for (CMap *p = *m; p; p = p->next)
	{
		if (p->var == v)
		{
			p->const_sym = NULL;
			return;
		}
	}
}

static int is_const_sym(SYM *s)
{
	return s && (s->type == SYM_INT || s->type == SYM_CHAR);
}

static SYM *mk_bool_const(int v)
{
	return mk_const(v ? 1 : 0);
}

// 在expMap链表中查找
SYM *lookup_exp(expMap *map, int op, SYM *b, SYM *c)
{
	normalize_operands(op, &b, &c);
	for (expMap *p = map; p; p = p->next)
	{
		if (p->op == op && p->b == b && p->c == c) // 表达式完全相同
			return p->t;
	}
	return NULL;
}

// 新增表达式节点
void insert_exp(expMap **map, int op, SYM *b, SYM *c, SYM *t)
{
	normalize_operands(op, &b, &c);
	expMap *node = malloc(sizeof(expMap));
	node->id = -1;
	node->op = op;
	node->b = b;
	node->c = c;
	node->t = t;
	node->next = *map;
	*map = node;
}

// 删除节点，同时维护tac双向链表和BB
void remove_tac_bb(BASIC_BLOCK *bb, TAC *p)
{
	// 双向tac链表删除节点
	if (p->prev)
		p->prev->next = p->next;
	else
		tac_first = p->next;

	if (p->next)
		p->next->prev = p->prev;
	else
		tac_last = p->prev;

	// 维护BBfirst和last
	if (bb->first == p)
		bb->first = p->next;
	if (bb->last == p)
		bb->last = p->prev;
}

int has_later_def(BASIC_BLOCK *bb, TAC *p, SYM *a)
{
	for (TAC *q = p->next; q && q != bb->last->next; q = q->next)
	{
		if (q->a == a && is_def_tac(q))
			return 1;
	}
	return 0;
}

// 替换
void replace_all(TAC *start, SYM *old, SYM *new)
{
	for (TAC *t = start->next; t; t = t->next)
	{
		if (t->b == old)
			t->b = new;
		if (t->c == old)
			t->c = new;
	}
}

int is_def_tac(TAC *p)
{
	switch (p->op)
	{
	case TAC_COPY:
	case TAC_ADD:
	case TAC_SUB:
	case TAC_MUL:
	case TAC_DIV:
	case TAC_NEG:
	case TAC_EQ:
	case TAC_NE:
	case TAC_LT:
	case TAC_LE:
	case TAC_GT:
	case TAC_GE:
	case TAC_LOAD:
		return 1;
	default:
		return 0;
	}
}

int live_contains(SYM **live, int live_cnt, SYM *v)
{
	if (!v)
		return 0;
	for (int i = 0; i < live_cnt; i++)
	{
		if (live[i] == v)
			return 1;
	}
	return 0;
}

void add_live(SYM **live, int *live_cnt, SYM *v)
{
	if (!v)
		return;
	if (!live_contains(live, *live_cnt, v))
	{
		live[(*live_cnt)++] = v;
	}
}

int local_copy_propagation()
{
	int changed = 0;

	for (BASIC_BLOCK *bb = bb_list; bb != NULL; bb = bb->next)
	{
		TAC *end = bb->last ? bb->last->next : NULL; // 固定BB结束位置

		for (TAC *t = bb->first; t != NULL && t != end;)
		{
			if (t->op != TAC_COPY)
			{
				t = t->next;
				continue;
			}

			SYM *x = t->a; // 左值
			SYM *y = t->b; // 右值

			if (!x || !y)
			{
				t = t->next;
				continue;
			}

			int rhs_is_const = (y->type == SYM_INT || y->type == SYM_CHAR);

			// 只允许两种情况进行传播
			int can_propagate = 0;
			if (rhs_is_const)
			{
				can_propagate = 1; // 常量传播
			}
			else if (x->type == SYM_TMP &&
					 y->type != SYM_FUNC &&
					 y->type != SYM_TEXT &&
					 y->type != SYM_LABEL)
			{
				can_propagate = 1; // TMP 复制传播
			}

			if (!can_propagate)
			{
				t = t->next;
				continue;
			}

			int propagated = 0;

			// 向后扫描当前BB
			for (TAC *i = t->next; i != end; i = i->next)
			{
				// x 或 y 被重新赋值，传播停止
				if (i->a == x || i->a == y)
					break;

				// 进行替换
				if (i->b == x)
				{
					i->b = y;
					propagated = 1;
				}
				if (i->c == x)
				{
					i->c = y;
					propagated = 1;
				}

				// 一元OUTPUT / RETURN / IFZ ：a 里也可能读 x
				if ((i->op == TAC_OUTPUT ||
					 i->op == TAC_RETURN ||
					 i->op == TAC_IFZ) &&
					i->a == x)
				{
					i->a = y;
					propagated = 1;
				}
			}

			if (!propagated)
			{
				t = t->next;
				continue;
			}
			//  x 是 TMP 且后续不再使用 x 的情况下，才删除 COPY
			int still_used = 0;
			for (TAC *i = t->next; i != end; i = i->next)
			{
				if (i->a == x || i->b == x || i->c == x ||
					((i->op == TAC_OUTPUT || i->op == TAC_RETURN || i->op == TAC_IFZ) && i->a == x))
				{
					still_used = 1;
					break;
				}
			}

			if (!still_used && x->type == SYM_TMP)
			{
				TAC *del = t;
				t = t->next;

				if (del->prev)
					del->prev->next = del->next;
				else
					tac_first = del->next;

				if (del->next)
					del->next->prev = del->prev;
				else
					tac_last = del->prev;

				if (bb->first == del)
					bb->first = del->next;
				if (bb->last == del)
					bb->last = del->prev;

				free(del);
				changed = 1;
			}
			else
			{
				// 不删（x 是普通变量，或者后面还会用到）
				t = t->next;
				changed = 1;
			}
		}
	}

	return changed;
}

int local_constant_folding()
{
	int changed = 0;
	BASIC_BLOCK *bb;

	for (bb = bb_list; bb != NULL; bb = bb->next)
	{
		TAC *p = bb->first;
		TAC *end = bb->last ? bb->last->next : NULL;

		for (; p != end; p = p->next)
		{
			int op = p->op;

			// 二元运算
			if (op == TAC_ADD || op == TAC_SUB || op == TAC_MUL || op == TAC_DIV ||
				op == TAC_EQ || op == TAC_NE || op == TAC_LT ||
				op == TAC_LE || op == TAC_GT || op == TAC_GE)
			{
				SYM *x = p->b;
				SYM *y = p->c;

				if (!x || !y)
					continue;

				if (op == TAC_ADD)
				{
					if ((x->type == SYM_INT && x->value == 0) ||
						(x->type == SYM_CHAR && x->value == 0))
					{
						// 0 + y = y
						p->op = TAC_COPY;
						p->b = y;
						p->c = NULL;
						changed = 1;
						continue;
					}
					if ((y->type == SYM_INT && y->value == 0) ||
						(y->type == SYM_CHAR && y->value == 0))
					{
						// x + 0 = x
						p->op = TAC_COPY;
						p->b = x;
						p->c = NULL;
						changed = 1;
						continue;
					}
				}

				if (op == TAC_SUB)
				{
					if ((y->type == SYM_INT && y->value == 0) ||
						(y->type == SYM_CHAR && y->value == 0))
					{
						// x - 0 = x
						p->op = TAC_COPY;
						p->b = x;
						p->c = NULL;
						changed = 1;
						continue;
					}
					if ((x->type == SYM_INT && x->value == 0) ||
						(x->type == SYM_CHAR && x->value == 0))
					{
						// 0 - y = -y
						p->op = TAC_NEG;
						p->b = y;
						p->c = NULL;
						changed = 1;
						continue;
					}
				}

				if (op == TAC_MUL)
				{
					int x_is0 = (x->type == SYM_INT && x->value == 0) ||
								(x->type == SYM_CHAR && x->value == 0);
					int y_is0 = (y->type == SYM_INT && y->value == 0) ||
								(y->type == SYM_CHAR && y->value == 0);
					int x_is1 = (x->type == SYM_INT && x->value == 1) ||
								(x->type == SYM_CHAR && x->value == 1);
					int y_is1 = (y->type == SYM_INT && y->value == 1) ||
								(y->type == SYM_CHAR && y->value == 1);

					if (x_is0 || y_is0)
					{
						// x * 0 或 0 * y = 0
						p->op = TAC_COPY;
						p->b = mk_const(0);
						p->c = NULL;
						changed = 1;
						continue;
					}
					if (x_is1)
					{
						// 1 * y = y
						p->op = TAC_COPY;
						p->b = y;
						p->c = NULL;
						changed = 1;
						continue;
					}
					if (y_is1)
					{
						// x * 1 = x
						p->op = TAC_COPY;
						p->b = x;
						p->c = NULL;
						changed = 1;
						continue;
					}
				}

				if (op == TAC_DIV)
				{
					int x_is0 = (x->type == SYM_INT && x->value == 0) ||
								(x->type == SYM_CHAR && x->value == 0);
					int y_is1 = (y->type == SYM_INT && y->value == 1) ||
								(y->type == SYM_CHAR && y->value == 1);
					int y_is0 = (y->type == SYM_INT && y->value == 0) ||
								(y->type == SYM_CHAR && y->value == 0);

					if (x_is0 && !y_is0)
					{
						// 0 / y = 0
						p->op = TAC_COPY;
						p->b = mk_const(0);
						p->c = NULL;
						changed = 1;
						continue;
					}
					if (y_is1)
					{
						// x / 1 = x
						p->op = TAC_COPY;
						p->b = x;
						p->c = NULL;
						changed = 1;
						continue;
					}
					if (y_is0)
					{
						continue;
					}
				}

				// 两个操作符均为常量
				if (!((x->type == SYM_INT || x->type == SYM_CHAR) &&
					  (y->type == SYM_INT || y->type == SYM_CHAR)))
					continue;

				int v1 = x->value;
				int v2 = y->value;
				int result;

				switch (op)
				{
				case TAC_ADD:
					result = v1 + v2;
					break;
				case TAC_SUB:
					result = v1 - v2;
					break;
				case TAC_MUL:
					result = v1 * v2;
					break;

				case TAC_DIV:
					if (v2 == 0)
						continue;
					result = v1 / v2;
					break;

				case TAC_EQ:
					result = (v1 == v2);
					break;
				case TAC_NE:
					result = (v1 != v2);
					break;
				case TAC_LT:
					result = (v1 < v2);
					break;
				case TAC_LE:
					result = (v1 <= v2);
					break;
				case TAC_GT:
					result = (v1 > v2);
					break;
				case TAC_GE:
					result = (v1 >= v2);
					break;
				default:
					continue;
				}

				p->op = TAC_COPY;
				p->b = mk_const(result);
				p->c = NULL;
				changed = 1;
				continue;
			}

			// 一元运算
			if (op == TAC_NEG)
			{
				SYM *x = p->b;
				if (!x)
					continue;

				if (x->type == SYM_INT || x->type == SYM_CHAR)
				{
					int r = -x->value;
					p->op = TAC_COPY;
					p->b = mk_const(r);
					p->c = NULL;
					changed = 1;
					continue;
				}
			}
		}
	}

	return changed;
}

int local_expression_elimination()
{
	int changed = 0;

	for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
	{
		expMap *map = NULL;
		TAC *next;
		for (TAC *p = bb->first; p != bb->last->next; p = next)
		{
			next = p->next;

			int op = p->op;

			if (p->a)
				kill_expression(&map, p->a);

			if (!(op == TAC_ADD || op == TAC_SUB || op == TAC_MUL || op == TAC_DIV ||
				  op == TAC_EQ || op == TAC_NE || op == TAC_LT || op == TAC_LE ||
				  op == TAC_GT || op == TAC_GE))
				continue;

			SYM *b = p->b;
			SYM *c = p->c;
			if (!b || !c)
				continue;

			SYM *oldt = lookup_exp(map, op, b, c); // 查找公共表达式
			if (oldt)
			{
				// replace_all(p, p->a, oldt);
				// remove_tac_bb(bb, p);
				p->op = TAC_COPY;
				p->b = oldt;
				p->c = NULL;
				changed++;
			}
			else
			{
				insert_exp(&map, op, b, c, p->a);
			}
		}
	}
	return changed;
}

int local_dead_assignment()
{
	int changed = 0;

	for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
	{
		SYM *live[1024];
		int live_cnt = 0;

		TAC *first = bb->first;

		for (TAC *p = bb->last; p;)
		{
			TAC *prev = p->prev;
			int is_first = (p == first);

			SYM *a = p->a;
			SYM *b = p->b;
			SYM *c = p->c;

			// 使用则加入到live
			if (b)
				add_live(live, &live_cnt, b);
			if (c)
				add_live(live, &live_cnt, c);

			if (a && a->type == SYM_VAR && is_def_tac(p))
			{

				int used_later = live_contains(live, live_cnt, a);

				if (!used_later && has_later_def(bb, p, a)) // 同一BB内后面没被用过 且 后续还有定义则删除
				{
					remove_tac_bb(bb, p);
					changed = 1;

					if (is_first)
						break;

					p = prev;
					continue;
				}

				for (int i = 0; i < live_cnt; i++)
				{
					if (live[i] == a)
					{
						live[i] = live[--live_cnt];
						break;
					}
				}
			}

			if (is_first)
				break;
			p = prev;
		}
	}

	return changed;
}

// void local_optimize()
// {
// 	int changed;

// 	do
// 	{
// 		changed = 0;

// 		if (local_constant_folding())
// 			changed = 1;

// 		if (local_copy_propagation())
// 			changed = 1;

// 		if (local_dead_assignment())
// 			changed = 1;

// 		if (local_expression_elimination() != 0)
// 			changed = 1;

// 	} while (changed);
// }

void local_optimize()
{
	// ---- 第一次跑 copy propagation（原始 TAC 上）
	local_constant_folding();
	local_copy_propagation();
	local_dead_assignment();

	// ---- 然后进入循环做 CSE（但不再跑 copy propagation）
	int changed;
	do
	{
		changed = 0;
		changed |= local_constant_folding();
		changed |= local_dead_assignment();
		changed |= local_expression_elimination();
	} while (changed);
}

// 结构体定义中,还未添加成员
STRUCT *begin_struct(const char *name)
{
	STRUCT *s = (STRUCT *)malloc(sizeof(STRUCT));
	s->name = strdup(name);
	s->members = NULL;
	s->size = 0;
	s->next = structs;
	structs = s;
	cur_structs = s;
	return s;
}

TAC *declare_struct(const char *var_name, const char *struct_name)
{
	STRUCT *define = find_struct(struct_name);
	if (!define)
		error("no struct defined");

	SYM *sym = mk_var((char *)var_name);
	sym->type = SYM_STRUCT;
	sym->etc = define; // 使用etc指向结构体定义

	return mk_tac(TAC_VAR, sym, NULL, NULL);
}

void add_struct_member_base(int type, const char *mname, int array_len, STRUCT *sub)
{

	if (!cur_structs)
	{
		error("no declaring struct\n");
	}

	STRUCT_MEMBER *m = (STRUCT_MEMBER *)malloc(sizeof(STRUCT_MEMBER));
	m->name = strdup(mname);
	m->type = type;
	m->array_len = array_len;
	m->sub = sub;

	// 计算大小
	int elem_size = size_of_member(type, sub);
	int cnt = (array_len > 0) ? array_len : 1;
	m->offset = cur_structs->size;
	cur_structs->size += elem_size * cnt;
	m->elem_size = elem_size;

	// printf("[DEBUG] struct=%s add member %s, offset=%d, elem_size=%d, array_len=%d, new_size=%d\n",
	// 	   cur_structs->name, mname, m->offset, elem_size, array_len, cur_structs->size);

	m->next = NULL;
	if (!cur_structs->members)
		cur_structs->members = m;
	else
	{
		STRUCT_MEMBER *p = cur_structs->members;
		while (p->next)
			p = p->next;
		p->next = m;
	}
}

// INT,CHAR
void add_struct_member(STRUCT *unused, int member_type, const char *mname)
{
	add_struct_member_base(member_type, mname, 0, NULL);
}

// 数组
void add_struct_member_array(STRUCT *unused, int member_type, const char *mname, int array_len)
{
	add_struct_member_base(member_type, mname, array_len, NULL);
}

// 单个结构体
void add_struct_member_struct(const char *struct_name, const char *mname)
{
	STRUCT *sub = find_struct(struct_name);
	if (!sub)
	{
		error("unknown struct\n");
	}
	add_struct_member_base(SYM_STRUCT, mname, 0, sub);
}

// struct数组
void add_struct_member_struct_array(const char *struct_name, const char *mname, int array_len)
{
	STRUCT *sub = find_struct(struct_name);
	if (!sub)
	{
		error("unknown struct\n");
	}
	add_struct_member_base(SYM_STRUCT, mname, array_len, sub);
}

// 结束定义：成员添加完毕
void end_struct(STRUCT *def)
{
	if (!def)
		def = cur_structs;
	cur_structs = NULL;
}

// 查找结构体
STRUCT *find_struct(const char *name)
{
	for (STRUCT *d = structs; d; d = d->next)
	{
		if (strcmp(d->name, name) == 0)
			return d;
	}
	return NULL;
}

// 计算1个成员的大小
int size_of_member(int type, STRUCT *sub)
{
	switch (type)
	{
	case SYM_INT:
		return 4;
	case SYM_CHAR:
		return 1;
	case SYM_PTR:
		return 4;
	case SYM_STRUCT:
		if (!sub)
		{
			error("STRUCT member with sub\n");
			return 0;
		}
		return sub->size;
	default:
		error("unknown member type\n");
		return 0;
	}
}

// 根据变量查找结构体
STRUCT *get_struct_var(SYM *var)
{
	if (!var)
		error("null struct var");

	if (var->type == SYM_STRUCT)
	{
		return (STRUCT *)var->etc; // 普通结构体变量
	}

	// 结构体数组：SYM_ARRAY 且 etc=SYM_STRUCT
	if (var->type == SYM_ARRAY)
	{
		int elem_type = *((int *)var->etc);
		if (elem_type == SYM_STRUCT)
		{
			return (STRUCT *)var->etc2;
		}
	}

	error("not a struct");
	return NULL;
}

// 得到成员偏移量
int get_struct_offset(SYM *struct_var, const char *name)
{
	STRUCT *def = get_struct_var(struct_var);
	for (STRUCT_MEMBER *m = def->members; m; m = m->next)
	{
		if (strcmp(m->name, name) == 0)
			return m->offset;
	}
	error("struct member not found");
	return -1;
}

// base.a(offset) = exp
TAC *make_struct_store_tac(SYM *base, int offset, EXP *exp)
{
	// t0 = &base
	SYM *t0 = mk_tmp();
	TAC *addr_base = mk_tac(TAC_VAR, t0, NULL, NULL);
	TAC *addr_cnt1 = mk_tac(TAC_ADDR, t0, base, NULL);
	addr_cnt1->prev = addr_base;

	// t1 = t1 + offset
	SYM *t1 = mk_tmp();
	TAC *addr_final = mk_tac(TAC_VAR, t1, NULL, NULL);
	TAC *addr_cnt2 = mk_tac(TAC_ADD, t1, t0, mk_const(offset));
	addr_cnt2->prev = addr_final;
	// addr_cnt2->prev = join_tac(addr_cnt1, addr_cnt2);

	TAC *addr_code = join_tac(join_tac(addr_base, addr_cnt1), join_tac(addr_final, addr_cnt2));
	// *t1 = exp
	TAC *store = mk_tac(TAC_STORE, t1, exp->ret, NULL);
	store->prev = join_tac(exp->tac, addr_code);

	return store;
}

// base.a(offset)
EXP *make_struct_load_exp(SYM *base, int offset)
{
	// t0 = &base
	SYM *t0 = mk_tmp();
	TAC *addr1 = mk_tac(TAC_VAR, t0, NULL, NULL);
	TAC *addr_base = mk_tac(TAC_ADDR, t0, base, NULL);
	addr_base->prev = addr1;

	// t1 = t0 + offset
	SYM *t1 = mk_tmp();
	TAC *addr2 = mk_tac(TAC_VAR, t1, NULL, NULL);
	TAC *addr_final = mk_tac(TAC_ADD, t1, mk_const(offset), t0);
	addr_final->prev = addr2;
	// addr_final->prev = join_tac(addr_base, addr_final);

	TAC *addr_code = join_tac(join_tac(addr1, addr_base), join_tac(addr2, addr_final));

	// t2 = *t1
	SYM *t2 = mk_tmp();
	TAC *tac_val = mk_tac(TAC_VAR, t2, NULL, NULL);
	TAC *load = mk_tac(TAC_LOAD, t2, t1, NULL);
	load->prev = tac_val;
	TAC *total_code = join_tac(addr_code, join_tac(tac_val, load));

	EXP *exp = mk_exp(NULL, t2, total_code);
	return exp;
}

// 新增一次访问，对结构体成员或数组元素
PATH *new_path_node(PATH_KIND kind)
{
	PATH *p = (PATH *)malloc(sizeof(PATH));
	p->kind = kind;
	p->member = NULL;
	p->index = NULL;
	p->next = NULL;
	return p;
}

// 访问路径中添加一次对结构体成员的访问
PATH *append_path_member(PATH *p, char *name)
{
	PATH *node = new_path_node(PATH_MEMBER);
	node->member = strdup(name);
	if (!p)
		return node;

	PATH *cur = p;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = node;
	return p;
}

// 访问路径中添加一次对数组元素的访问
PATH *append_path_index(PATH *p, EXP *idx)
{
	PATH *node = new_path_node(PATH_INDEX);
	node->index = idx;
	if (!p)
		return node;
	PATH *cur = p;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = node;
	return p;
}

// 形成LVALUE_PATH
LVALUE_PATH *mk_lvalue_path(char *root, PATH *tail)
{
	LVALUE_PATH *lv = (LVALUE_PATH *)malloc(sizeof(LVALUE_PATH));
	lv->root = strdup(root);
	lv->path = tail;
	return lv;
}

// 返回结构体成员地址(非相对于结构体的偏移)
SYM *make_struct_member_addr(SYM *base, STRUCT_MEMBER *m, TAC **code)
{
	// addr = base + m->offset
	SYM *t = mk_tmp();

	// t = base + offset
	TAC *decl = mk_tac(TAC_VAR, t, NULL, NULL);
	TAC *add = mk_tac(TAC_ADD, t, base, mk_const(m->offset));
	add->prev = decl;

	*code = join_tac(*code, decl);
	*code = join_tac(*code, add);
	// printf("[DEBUG] base = %s, member offset = %d\n", base->name, m->offset);

	return t;
}

SYM *make_array_elem_addr(SYM *base, EXP *idx, int elem_size, TAC **code)
{
	// printf("[DEBUG] INDEX idx->ret->value = %d, type = %d, elem_size = %d\n",
	// 	   idx->ret->value,
	// 	   idx->ret->type,
	// 	   elem_size);

	if ((!idx->tac || idx->tac == NULL) &&
		(idx->ret->type == SYM_INT || idx->ret->type == SYM_CHAR))
	{
		int off = idx->ret->value * elem_size;

		// addr = base + offset
		SYM *addr = mk_tmp();
		TAC *decl = mk_tac(TAC_VAR, addr, NULL, NULL);
		TAC *add = mk_tac(TAC_ADD, addr, base, mk_const(off));
		add->prev = decl;

		*code = join_tac(*code, decl);
		*code = join_tac(*code, add);

		return addr;
	}

	*code = join_tac(*code, idx->tac);

	SYM *mul = mk_tmp();
	SYM *addr = mk_tmp();

	// mul = idx * elem_size
	TAC *decl_mul = mk_tac(TAC_VAR, mul, NULL, NULL);
	TAC *mul_tac = mk_tac(TAC_MUL, mul, idx->ret, mk_const(elem_size));
	mul_tac->prev = decl_mul;

	// addr = base + mul
	TAC *decl_addr = mk_tac(TAC_VAR, addr, NULL, NULL);
	TAC *add_tac = mk_tac(TAC_ADD, addr, base, mul);
	add_tac->prev = decl_addr;

	*code = join_tac(*code, decl_mul);
	*code = join_tac(*code, mul_tac);
	*code = join_tac(*code, decl_addr);
	*code = join_tac(*code, add_tac);

	// printf("[DEBUG] array base = %s, index = %s, elem_size = %d\n",
	// 	   base->name, idx->ret->name, elem_size);

	return addr;
}

STRUCT_MEMBER *find_member(STRUCT *def, const char *name)
{
	if (!def)
		return NULL;
	for (STRUCT_MEMBER *m = def->members; m; m = m->next)
	{
		if (strcmp(m->name, name) == 0)
			return m;
	}
	return NULL;
}

// 根据路径逐步取地址并赋值
TAC *do_lvalue_store(LVALUE_PATH *lv, EXP *rhs)
{
	SYM *root = get_var(lv->root);

	TAC *code = NULL;

	// STEP 1: addr = &root
	SYM *addr = mk_tmp();
	TAC *decl_addr = mk_tac(TAC_VAR, addr, NULL, NULL);
	TAC *get_addr = mk_tac(TAC_ADDR, addr, root, NULL);
	get_addr->prev = decl_addr;
	code = join_tac(code, decl_addr);
	code = join_tac(code, get_addr);

	// STRUCT *cur_struct = get_struct_var(root); // 获得当前结构体

	STRUCT *cur_struct = NULL; // 初始为空

	if (root->type == SYM_STRUCT)
		cur_struct = (STRUCT *)root->etc;

	else if (root->type == SYM_ARRAY)
	{
		int elem = *((int *)root->etc);
		if (elem == SYM_STRUCT)
			cur_struct = (STRUCT *)root->etc2;
		else
			cur_struct = NULL;
	}

	else
		cur_struct = NULL;

	// 记录信息：当前是结构体成员，下一步是数组情况使用
	int pending_elem_size = 0;			// 数组元素大小
	int pending_elem_is_struct = 0;		// 元素是不是struct
	STRUCT *pending_elem_struct = NULL; // 记录元素对应的struct

	PATH *p = lv->path;

	while (p)
	{
		if (p->kind == PATH_MEMBER)
		{
			// printf("%s\n", cur_struct->name);
			// printf("%s\n", p->member);
			STRUCT_MEMBER *m = find_member(cur_struct, p->member);

			// if (!m)
			// 	error("unknown struct member2\n");

			addr = make_struct_member_addr(addr, m, &code);

			pending_elem_size = 0;
			pending_elem_is_struct = 0;
			pending_elem_struct = NULL;

			if (m->array_len > 0) // 需要更新pending信息，供下一步PATH_INDEX使用
			{
				// 数组成员
				pending_elem_size = m->elem_size;
				if (m->type == SYM_STRUCT)
				{
					pending_elem_is_struct = 1;
					pending_elem_struct = m->sub;
				}
				cur_struct = NULL;
				// printf("[LV] ARRAY member=%s, type=%d, elem_size=%d\n", m->name, m->type, m->elem_size);
			}
			else
			{
				// 普通成员：int/char 或 struct
				if (m->type == SYM_STRUCT)
				{
					cur_struct = m->sub; // 进入子 struct
				}
				else if (m->type == SYM_PTR)
				{
					cur_struct = NULL;
					// 不能后续访问
					pending_elem_size = 0;
					pending_elem_is_struct = 0;
					pending_elem_struct = NULL;
				}
				else
				{
					cur_struct = NULL;
				}
			}
		}
		else if (p->kind == PATH_INDEX)
		{

			int elem_size = pending_elem_size;

			if (elem_size == 0)
			{
				if (!cur_struct)
				{
					error("index on non-array\n");
				}
				elem_size = cur_struct->size;

				pending_elem_is_struct = 1;
				pending_elem_struct = cur_struct;
			}

			addr = make_array_elem_addr(addr, p->index, pending_elem_size, &code);

			if (pending_elem_is_struct)
			{
				cur_struct = pending_elem_struct;
			}
			else
			{
				cur_struct = NULL;
			}

			pending_elem_size = 0;
			pending_elem_is_struct = 0;
			pending_elem_struct = NULL;
		}

		p = p->next;
	}
	code = join_tac(code, rhs->tac);

	// TAC *st = mk_tac(TAC_STORE, addr, rhs->ret, NULL);

	int is_char = (rhs->ret->type == SYM_CHAR);

	TAC *st;
	if (is_char)
		st = mk_tac(TAC_STOREC, addr, rhs->ret, NULL);
	else
		st = mk_tac(TAC_STORE, addr, rhs->ret, NULL);

	code = join_tac(code, st);

	return code;
}

// 根据路径逐步取地址并从中取值
EXP *do_lvalue_load(LVALUE_PATH *lv)
{
	SYM *root = get_var(lv->root);

	TAC *code = NULL;

	// addr = &root
	SYM *addr = mk_tmp();
	TAC *decl_addr = mk_tac(TAC_VAR, addr, NULL, NULL);
	TAC *get_addr = mk_tac(TAC_ADDR, addr, root, NULL);
	get_addr->prev = decl_addr;

	code = join_tac(code, decl_addr);
	code = join_tac(code, get_addr);

	// STRUCT *cur_struct = get_struct_var(root); // 获得当前结构体

	STRUCT *cur_struct = NULL; // 初始为空

	// 结构体变量
	if (root->type == SYM_STRUCT)
		cur_struct = (STRUCT *)root->etc;

	else if (root->type == SYM_ARRAY)
	{
		int elem = *((int *)root->etc);
		if (elem == SYM_STRUCT)
			cur_struct = (STRUCT *)root->etc2;
		else
			cur_struct = NULL; // 普通数组
	}

	// 普通数组 / int 不需要结构体处理
	else
		cur_struct = NULL;

	// 如果是结构体变量
	if (root->type == SYM_STRUCT)
		cur_struct = (STRUCT *)root->etc;

	// 如果是结构体数组
	else if (root->type == SYM_ARRAY)
	{
		int elem = *((int *)root->etc);
		if (elem == SYM_STRUCT)
			cur_struct = (STRUCT *)root->etc2;
		else
			cur_struct = NULL; // 普通数组
	}

	// 普通数组 / int 变量 root 时不需要结构体处理
	else
		cur_struct = NULL;

	// 记录信息：当前是结构体成员，下一步是数组情况使用
	int pending_elem_size = 0;			// 数组元素大小
	int pending_elem_is_struct = 0;		// 元素是不是struct
	STRUCT *pending_elem_struct = NULL; // 记录元素对应的struct

	PATH *p = lv->path;
	// printf("come in load\n");
	int is_char = 0;

	while (p)
	{
		// printf("come in while\n");

		if (p->kind == PATH_MEMBER)
		{
			// printf("%s\n", cur_struct->name);
			// printf("%s\n", p->member);
			STRUCT_MEMBER *m = find_member(cur_struct, p->member);

			// if (!m)
			// 	error("unknown struct member1\n");

			if (m->type == SYM_CHAR)
				is_char = 1;
			else
				is_char = 0;

			addr = make_struct_member_addr(addr, m, &code);

			pending_elem_size = 0;
			pending_elem_is_struct = 0;
			pending_elem_struct = NULL;

			if (m->array_len > 0) // 需要更新pending信息，供下一步PATH_INDEX使用
			{
				// 数组成员
				pending_elem_size = m->elem_size;
				if (m->type == SYM_STRUCT)
				{
					pending_elem_is_struct = 1;
					pending_elem_struct = m->sub;
				}
				// printf("[LV] ARRAY member=%s, type=%d, elem_size=%d\n", m->name, m->type, m->elem_size);

				cur_struct = NULL;
			}
			else
			{
				// 普通成员：int/char 或 struct
				if (m->type == SYM_STRUCT)
				{
					cur_struct = m->sub; // 进入子 struct
				}
				else if (m->type == SYM_PTR)
				{
					cur_struct = NULL;
					// 不能后续访问
					pending_elem_size = 0;
					pending_elem_is_struct = 0;
					pending_elem_struct = NULL;
				}
				else
				{
					cur_struct = NULL;
				}
			}
		}
		else if (p->kind == PATH_INDEX)
		{

			int elem_size = pending_elem_size;

			if (elem_size == 0)
			{
				if (!cur_struct)
				{
					error("index on non-array\n");
				}
				elem_size = cur_struct->size;

				pending_elem_is_struct = 1;
				pending_elem_struct = cur_struct;
			}

			// printf("come in index1\n");
			addr = make_array_elem_addr(addr, p->index, pending_elem_size, &code);
			if (pending_elem_is_struct)
			{
				cur_struct = pending_elem_struct;
			}
			else
			{
				cur_struct = NULL;
			}

			pending_elem_size = 0;
			pending_elem_is_struct = 0;
			pending_elem_struct = NULL;
		}

		p = p->next;
	}

	SYM *t = mk_tmp();
	TAC *decl = mk_tac(TAC_VAR, t, NULL, NULL);
	// TAC *load = mk_tac(TAC_LOAD, t, addr, NULL);
	TAC *load;
	if (is_char)
		load = mk_tac(TAC_LOADC, t, addr, NULL);
	else
		load = mk_tac(TAC_LOAD, t, addr, NULL);
	load->prev = decl;

	code = join_tac(code, join_tac(decl, load));

	// printf("[LVALUE LOAD FINAL]: %s.%s offset chain done\n", root->name, lv->path->member);

	return mk_exp(NULL, t, code);
}

// 获得逐步访问形式的最终地址
EXP *do_lvalue_addr(LVALUE_PATH *lv)
{
	SYM *root = get_var(lv->root);

	TAC *code = NULL;

	// addr = &root
	SYM *addr = mk_tmp();
	addr->type = SYM_PTR;
	TAC *decl_addr = mk_tac(TAC_VAR, addr, NULL, NULL);
	TAC *get_addr = mk_tac(TAC_ADDR, addr, root, NULL);
	get_addr->prev = decl_addr;

	code = join_tac(code, decl_addr);
	code = join_tac(code, get_addr);

	// STRUCT *cur_struct = get_struct_var(root); // 获得当前结构体

	STRUCT *cur_struct = NULL; // 初始为空

	if (root->type == SYM_STRUCT)
		cur_struct = (STRUCT *)root->etc;

	else if (root->type == SYM_ARRAY)
	{
		int elem = *((int *)root->etc);
		if (elem == SYM_STRUCT)
			cur_struct = (STRUCT *)root->etc2;
		else
			cur_struct = NULL;
	}

	else
		cur_struct = NULL;

	// 如果是结构体变量
	if (root->type == SYM_STRUCT)
		cur_struct = (STRUCT *)root->etc;

	// 如果是结构体数组
	else if (root->type == SYM_ARRAY)
	{
		int elem = *((int *)root->etc);
		if (elem == SYM_STRUCT)
			cur_struct = (STRUCT *)root->etc2;
		else
			cur_struct = NULL; // 普通数组
	}

	// 普通数组 / int 变量 root 时不需要结构体处理
	else
		cur_struct = NULL;

	// 记录信息：当前是结构体成员，下一步是数组情况使用
	int pending_elem_size = 0;			// 数组元素大小
	int pending_elem_is_struct = 0;		// 元素是不是struct
	STRUCT *pending_elem_struct = NULL; // 记录元素对应的struct

	PATH *p = lv->path;
	// printf("come in load\n");
	int is_char = 0;

	while (p)
	{
		// printf("come in while\n");

		if (p->kind == PATH_MEMBER)
		{
			// printf("%s\n", cur_struct->name);
			// printf("%s\n", p->member);
			STRUCT_MEMBER *m = find_member(cur_struct, p->member);

			// if (!m)
			// 	error("unknown struct member1\n");

			if (m->type == SYM_CHAR)
				is_char = 1;
			else
				is_char = 0;

			addr = make_struct_member_addr(addr, m, &code);

			pending_elem_size = 0;
			pending_elem_is_struct = 0;
			pending_elem_struct = NULL;

			if (m->array_len > 0) // 需要更新pending信息，供下一步PATH_INDEX使用
			{
				// 数组成员
				pending_elem_size = m->elem_size;
				if (m->type == SYM_STRUCT)
				{
					pending_elem_is_struct = 1;
					pending_elem_struct = m->sub;
				}
				// printf("[LV] ARRAY member=%s, type=%d, elem_size=%d\n", m->name, m->type, m->elem_size);

				cur_struct = NULL;
			}
			else
			{
				// 普通成员：int/char 或 struct
				if (m->type == SYM_STRUCT)
				{
					cur_struct = m->sub; // 进入子 struct
				}
				else if (m->type == SYM_PTR)
				{
					cur_struct = NULL;
					// 不能后续访问
					pending_elem_size = 0;
					pending_elem_is_struct = 0;
					pending_elem_struct = NULL;
				}
				else
				{
					cur_struct = NULL;
				}
			}
		}
		else if (p->kind == PATH_INDEX)
		{

			int elem_size = pending_elem_size;

			if (elem_size == 0)
			{
				if (!cur_struct)
				{
					error("index on non-array\n");
				}
				elem_size = cur_struct->size;

				pending_elem_is_struct = 1;
				pending_elem_struct = cur_struct;
			}

			// printf("come in index1\n");
			addr = make_array_elem_addr(addr, p->index, pending_elem_size, &code);
			if (pending_elem_is_struct)
			{
				cur_struct = pending_elem_struct;
			}
			else
			{
				cur_struct = NULL;
			}

			pending_elem_size = 0;
			pending_elem_is_struct = 0;
			pending_elem_struct = NULL;
		}

		p = p->next;
	}

	return mk_exp(NULL, addr, code);
}

static SYM *eval_bin(int op, SYM *b, SYM *c)
{
	if (!is_const_sym(b) || !is_const_sym(c))
		return NULL;
	int x = b->value;
	int y = c->value;
	int z = 0;
	int div_zero = 0;

	switch (op)
	{
	case TAC_ADD:
		z = x + y;
		break;
	case TAC_SUB:
		z = x - y;
		break;
	case TAC_MUL:
		z = x * y;
		break;
	case TAC_DIV:
		if (y == 0)
			div_zero = 1;
		else
			z = x / y;
		break;
	case TAC_EQ:
		return mk_bool_const(x == y);
	case TAC_NE:
		return mk_bool_const(x != y);
	case TAC_LT:
		return mk_bool_const(x < y);
	case TAC_LE:
		return mk_bool_const(x <= y);
	case TAC_GT:
		return mk_bool_const(x > y);
	case TAC_GE:
		return mk_bool_const(x >= y);
	}
	if (div_zero)
		return NULL;
	return mk_const(z);
}

static SYM *eval_un(int op, SYM *b)
{
	if (!is_const_sym(b))
		return NULL;
	if (op == TAC_NEG)
		return mk_const(-b->value);
	return NULL;
}

// 入栈:循环开始时
void push_loop_labels(SYM *cont, SYM *end)
{
	if (loop_depth >= LOOP_MAX_DEPTH)
		error("too many nested loops");
	loop_continue_stack[loop_depth] = cont;
	loop_end_stack[loop_depth] = end;
	loop_depth++;
}

// 出栈：循环结束后
void pop_loop_labels(void)
{
	if (loop_depth > 0)
		loop_depth--;
}

// 取break目标
SYM *get_break_label()
{
	if (loop_depth == 0)
	{
		printf("no Lbreak");
		return NULL;
	}
	return loop_end_stack[loop_depth - 1];
}

// 取continue目标
SYM *get_continue_label()
{
	if (loop_depth == 0)
	{
		printf("no Lcontinue");
		return NULL;
	}
	return loop_continue_stack[loop_depth - 1];
}

// 新建bb
BASIC_BLOCK *newblock(TAC *first)
{
	BASIC_BLOCK *bb = malloc(sizeof(BASIC_BLOCK));
	bb->id = 0;
	bb->first = first;
	bb->last = NULL;
	bb->succ = bb->pred = NULL;
	bb->succ_count = bb->pred_count = 0;
	bb->next = NULL;
	return bb;
}

// 根据name查找所在bb
BASIC_BLOCK *find_block_by_label(char *label_name)
{
	for (BASIC_BLOCK *bb = bb_list; bb != NULL; bb = bb->next)
	{
		if (bb->first && bb->first->op == TAC_LABEL)
		{
			SYM *sym = bb->first->a;
			if (sym && sym->name && strcmp(sym->name, label_name) == 0)
				return bb;
		}
	}
	return NULL;
}

void add_edge(BASIC_BLOCK *from, BASIC_BLOCK *to)
{
	if (from == NULL || to == NULL)
		return;

	from->succ = realloc(from->succ, sizeof(BASIC_BLOCK *) * (from->succ_count + 1));
	from->succ[from->succ_count++] = to;

	to->pred = realloc(to->pred, sizeof(BASIC_BLOCK *) * (to->pred_count + 1));
	to->pred[to->pred_count++] = from;
}

void build_cfg()
{
	TAC *t;
	BASIC_BLOCK *cur_bb = NULL;
	bb_list = bb_tail = NULL;

	for (t = tac_first; t != NULL; t = t->next)
	{
		// 跳过未被引用的
		if (t->op == TAC_LABEL)
		{
			int referenced = 0;
			for (TAC *p = tac_first; p != NULL; p = p->next)
			{
				if ((p->op == TAC_GOTO || p->op == TAC_IFZ) && p->a && p->a == t->a)
				{
					referenced = 1;
					break;
				}
			}

			// 如果该 label 没有被任何 GOTO/IFZ 引用，且当前 block 未结束，则认为是块内标签
			if (!referenced && cur_bb != NULL)
			{
				cur_bb->last = t; // 继续累积
				continue;
			}
			else
			{
				cur_bb = NULL; // 强制结束当前块，新建一个
			}
		}

		if (t->op == TAC_LABEL || t->op == TAC_BEGINFUNC || !cur_bb)
		{
			cur_bb = newblock(t);
			if (bb_list == NULL)
			{
				bb_list = bb_tail = cur_bb;
				cur_bb->id = 0;
			}
			else
			{
				cur_bb->id = bb_tail->id + 1;
				bb_tail->next = cur_bb;
				bb_tail = cur_bb;
			}
		}

		cur_bb->last = t;

		if (t->op == TAC_GOTO || t->op == TAC_IFZ ||
			t->op == TAC_RETURN || t->op == TAC_ENDFUNC)
		{
			cur_bb = NULL;
		}
	}

	int id = 0;

	for (BASIC_BLOCK *bb = bb_list; bb != NULL; bb = bb->next)
	{
		TAC *last = bb->last;

		bb->id = id++;

		if (last->op == TAC_GOTO)
		{
			BASIC_BLOCK *target = find_block_by_label(last->a->name);
			add_edge(bb, target);
		}
		else if (last->op == TAC_IFZ)
		{
			BASIC_BLOCK *if_target = find_block_by_label(last->a->name);
			add_edge(bb, if_target); // 条件不满足跳转

			if (bb->next)
				add_edge(bb, bb->next); // 条件满足顺序流
		}
		else if (last->op != TAC_RETURN && last->op != TAC_ENDFUNC && bb->next)
		{
			add_edge(bb, bb->next);
		}
	}
}

void cfg_dump(FILE *out)
{
	for (BASIC_BLOCK *bb = bb_list; bb != NULL; bb = bb->next)
	{
		fprintf(out, "\n[B%d]\n", bb->id);
		for (TAC *t = bb->first; t != bb->last->next; t = t->next)
			out_tac(out, t), fprintf(out, "\n");

		fprintf(out, "  succ: ");
		for (int i = 0; i < bb->succ_count; i++)
			fprintf(out, "B%d ", bb->succ[i]->id);
		fprintf(out, "\n");
	}
}

void tac_init()
{
	scope = 0;
	sym_tab_global = NULL;
	sym_tab_local = NULL;
	next_tmp = 0;
	next_label = 1;
}

void tac_complete()
{
	TAC *cur = NULL;	  /* Current TAC */
	TAC *prev = tac_last; /* Previous TAC */

	while (prev != NULL)
	{
		prev->next = cur;
		cur = prev;
		prev = prev->prev;
	}

	tac_first = cur;
}

SYM *lookup_sym(SYM *symtab, char *name)
{
	SYM *t = symtab;

	while (t != NULL)
	{
		if (strcmp(t->name, name) == 0)
			break;
		else
			t = t->next;
	}

	return t; /* NULL if not found */
}

void insert_sym(SYM **symtab, SYM *sym)
{
	if (symtab == NULL)
		printf("[DEBUG] lookup_sym: symtab NULL!\n");

	sym->next = *symtab; /* Insert at head */
	*symtab = sym;
}

SYM *mk_sym(void)
{
	SYM *t;
	t = (SYM *)malloc(sizeof(SYM));
	memset(t, 0, sizeof(SYM));
	t->type = SYM_UNDEF; // 未定义
	return t;
}

SYM *mk_var(char *name)
{
	SYM *sym = NULL;

	if (scope)
	{
		sym = lookup_sym(sym_tab_local, name);
		if (!sym)
			sym = lookup_sym(sym_tab_global, name);
	}
	else
		sym = lookup_sym(sym_tab_global, name);

	/* var already declared */
	if (sym != NULL)
	{
		error("variable already declared");
		return NULL;
	}

	/* var unseen before, set up a new symbol table node, insert_sym it into the symbol table. */
	sym = mk_sym();
	sym->type = SYM_VAR;
	sym->name = name;
	sym->offset = -1; /* Unset address */

	if (scope)
		insert_sym(&sym_tab_local, sym);
	else
		insert_sym(&sym_tab_global, sym);

	sym->scope = scope;
	return sym;
}

TAC *join_tac(TAC *c1, TAC *c2)
{
	if (!c1)
		return c2;
	if (!c2)
		return c1;

	TAC *head2 = c2;
	while (head2->prev)
		head2 = head2->prev;

	for (TAC *p = c1; p; p = p->prev)
		if (p == head2)
			return c2;

	head2->prev = c1;
	return c2;
}

TAC *declare_var(char *name)
{
	return mk_tac(TAC_VAR, mk_var(name), NULL, NULL);
}

TAC *declare_var_typed(const char *name, int sym_type)
{

	SYM *sym = mk_var(name);

	sym->etc = malloc(sizeof(int));
	// printf("declare %d", sym_type);
	*((int *)sym->etc) = sym_type;

	return mk_tac(TAC_VAR, sym, NULL, NULL);
}

TAC *declare_array_typed(const char *name, int type, EXP *dims)
{
	SYM *sym = mk_var(name);
	sym->type = SYM_ARRAY;
	int ndim = 0;
	for (EXP *p = dims; p; p = p->next) // 倒序遍历
	{
		ndim++;
	}

	sym->ndim = ndim;
	sym->dims = malloc(sizeof(int) * ndim);

	int i = ndim - 1;

	for (EXP *p = dims; p; p = p->next)
	{
		sym->dims[i--] = p->ret->value; // 倒序存入相应维度
	}

	sym->etc = malloc(sizeof(int));
	*((int *)sym->etc) = type; // 使用etc存储数组类型

	return mk_tac(TAC_VARARRAY, sym, mk_const(ndim), NULL);
}

// 计算偏移量
static EXP *cal_array_offset(SYM *arr, EXP *idxs)
{
	int ndim = arr->ndim;
	int *dims = arr->dims;
	int elem_type = *((int *)arr->etc);
	int elem_size = (elem_type == SYM_CHAR) ? 1 : 4;

	EXP *idx_vec[10];
	int cnt = 0;
	for (EXP *p = idxs; p && cnt < 10; p = p->next)
		idx_vec[cnt++] = p;

	for (int i = 0; i < cnt / 2; ++i) // idx_vec中正向存储
	{
		EXP *tmp = idx_vec[i];
		idx_vec[i] = idx_vec[cnt - 1 - i];
		idx_vec[cnt - 1 - i] = tmp;
	}

	// 计算偏移中的不变项：跨过下一维一项的偏移
	// a[10][20][30]
	int stride[10];
	stride[ndim - 1] = elem_size; // 最后一维差一项差elem_size
	for (int i = ndim - 2; i >= 0; --i)
		stride[i] = stride[i + 1] * dims[i + 1]; // 倒数第二维：stride[1] = stride[2](4) * dims[2]（30）

	int const_offset = 0;
	TAC *code = NULL;
	SYM *sum_sym = NULL;

	for (int k = 0; k < ndim && k < 10; k++)
	{
		int s = stride[k];
		EXP *idx = idx_vec[k];
		SYM *term_sym = NULL;

		// 若索引是常量，直接累积,每一维*跨过下一维一项的固定偏移
		if (idx->ret->type == SYM_INT || idx->ret->type == SYM_CHAR)
		{
			const_offset += idx->ret->value * s;
			continue;
		}

		// 动态项
		SYM *t = mk_tmp();
		TAC *decl = mk_tac(TAC_VAR, t, NULL, NULL);
		TAC *mul = mk_tac(TAC_MUL, t, idx->ret, mk_const(s)); // t = idx * stride
		mul->prev = decl;
		code = join_tac(code, join_tac(idx->tac, mul));

		if (!sum_sym)
		{
			sum_sym = t;
		}
		else
		{
			SYM *tadd = mk_tmp();
			TAC *decl2 = mk_tac(TAC_VAR, tadd, NULL, NULL);
			TAC *add = mk_tac(TAC_ADD, tadd, sum_sym, t); // 与原有偏移相加
			add->prev = decl2;
			code = join_tac(code, add);
			sum_sym = tadd; // 更新
		}
	}

	// 若有常量偏移，则加上
	if (const_offset != 0)
	{
		if (!sum_sym) // 无变量
		{
			return mk_exp(NULL, mk_const(const_offset), NULL);
		}
		SYM *taddc = mk_tmp();
		TAC *decl3 = mk_tac(TAC_VAR, taddc, NULL, NULL);
		TAC *addc = mk_tac(TAC_ADD, taddc, sum_sym, mk_const(const_offset));
		addc->prev = decl3;
		code = join_tac(code, addc);
		sum_sym = taddc;
	}

	return mk_exp(NULL, sum_sym, code);
}

// 数组取值
EXP *do_array_load(SYM *arr, EXP *idxs)
{
	if (arr->type != SYM_ARRAY)
	{
		error("not an array");
	}

	EXP *offset = cal_array_offset(arr, idxs);

	SYM *t = mk_tmp();
	TAC *decl = mk_tac(TAC_VAR, t, NULL, NULL);
	TAC *load = mk_tac(TAC_LOADIDX, t, arr, offset->ret); // LOAD t = arr[offset]
	load->prev = join_tac(offset->tac, decl);

	return mk_exp(NULL, t, load);
}

// 数组赋值
TAC *do_array_store(SYM *arr, EXP *idxs, EXP *val)
{
	if (arr->type != SYM_ARRAY)
		error("not an array");

	EXP *offset = cal_array_offset(arr, idxs);
	TAC *store = mk_tac(TAC_STOREIDX, arr, offset->ret, val->ret); // STORE arr[offset] = val
	store->prev = join_tac(join_tac(offset->tac, val->tac), NULL);
	return store;
}

TAC *mk_tac(int op, SYM *a, SYM *b, SYM *c)
{
	TAC *t = (TAC *)malloc(sizeof(TAC));

	t->next = NULL; /* Set these for safety */
	t->prev = NULL;
	t->op = op;
	t->a = a;
	t->b = b;
	t->c = c;

	return t;
}

SYM *mk_label(char *name)
{
	SYM *t = mk_sym();
	t->type = SYM_LABEL;
	t->name = strdup(name);
	return t;
}

TAC *do_func(SYM *func, TAC *args, TAC *code)
{
	TAC *tlist; /* The backpatch list */

	TAC *tlab;	 /* Label at start of function */
	TAC *tbegin; /* BEGINFUNC marker */
	TAC *tend;	 /* ENDFUNC marker */

	tlab = mk_tac(TAC_LABEL, mk_label(func->name), NULL, NULL);
	tbegin = mk_tac(TAC_BEGINFUNC, NULL, NULL, NULL);
	tend = mk_tac(TAC_ENDFUNC, NULL, NULL, NULL);

	tbegin->prev = tlab;
	code = join_tac(args, code);
	tend->prev = join_tac(tbegin, code);

	// fprintf(stderr, "[FUNC] build func %s, tlab=%p tend=%p\n", func->name, tlab, tend);

	return tend;
}

SYM *mk_tmp(void)
{
	SYM *sym = mk_sym();
	char *name = malloc(12);
	sprintf(name, "t%d", next_tmp++);

	sym->type = SYM_TMP;
	sym->name = name;
	sym->offset = -1;
	sym->scope = scope;

	if (scope)
		insert_sym(&sym_tab_local, sym);
	else
		insert_sym(&sym_tab_global, sym);

	return sym;
}

TAC *declare_para(char *name)
{
	return mk_tac(TAC_FORMAL, mk_var(name), NULL, NULL);
}

SYM *declare_func(char *name)
{
	SYM *sym = NULL;

	sym = lookup_sym(sym_tab_global, name);

	/* name used before declared */
	if (sym != NULL)
	{
		if (sym->type == SYM_FUNC)
		{
			// error("func already declared");
			// return NULL;
			return sym;
		}

		if (sym->type != SYM_UNDEF)
		{
			error("func name already used");
			return NULL;
		}

		return sym;
	}

	sym = mk_sym();
	sym->type = SYM_FUNC;
	sym->name = name;
	sym->address = NULL;

	insert_sym(&sym_tab_global, sym);
	// fprintf(stderr, "[FUNC DECL] new func %s\n", name);
	return sym;
}

TAC *do_assign(SYM *var, EXP *exp)
{
	TAC *code;

	if (var->type != SYM_VAR)
		error("assignment to non-variable");

	code = mk_tac(TAC_COPY, var, exp->ret, NULL);
	code->prev = exp->tac;

	return code;
}

TAC *do_input(SYM *var)
{
	TAC *code;

	if (var->type != SYM_VAR)
		error("input to non-variable");

	code = mk_tac(TAC_INPUT, var, NULL, NULL);

	return code;
}

TAC *do_output(SYM *s)
{
	TAC *code;

	code = mk_tac(TAC_OUTPUT, s, NULL, NULL);

	return code;
}

EXP *do_bin(int binop, EXP *exp1, EXP *exp2)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret;  /* TAC code for result */

	SYM *x = exp1->ret; // 操作数1
	SYM *y = exp2->ret; // 操作数2

	if (binop == TAC_ADD)
	{
		// 0 + y = y
		if (x->type == SYM_INT && x->value == 0)
		{
			exp2->tac = join_tac(exp1->tac, exp2->tac);
			return exp2;
		}
		// x + 0 = x
		if (y->type == SYM_INT && y->value == 0)
		{
			exp1->tac = join_tac(exp1->tac, exp2->tac);
			return exp1;
		}
	}
	else if (binop == TAC_SUB)
	{
		// x - 0 = x
		if (y->type == SYM_INT && y->value == 0)
		{
			exp1->tac = join_tac(exp1->tac, exp2->tac);
			return exp1;
		}
		// 0 - y = -y
		if (x->type == SYM_INT && x->value == 0)
		{
			// 0 - 常量
			if (y->type == SYM_INT)
			{
				EXP *e = exp1;
				e->ret = mk_const(-(y->value));
				e->tac = join_tac(exp1->tac, exp2->tac);
				return e;
			}
			// 0 - 变量
			TAC *tmp = mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
			tmp->prev = join_tac(exp1->tac, exp2->tac);

			TAC *neg = mk_tac(TAC_NEG, tmp->a, y, NULL);
			neg->prev = tmp;
			exp2->ret = tmp->a;
			exp2->tac = neg;
			return exp2;
		}
	}
	else if (binop == TAC_MUL)
	{
		// 0 * y / x * 0 = 0
		if ((x->type == SYM_INT && x->value == 0) || (y->type == SYM_INT && y->value == 0))
		{
			EXP *e = exp1;
			e->ret = mk_const(0);
			e->tac = join_tac(exp1->tac, exp2->tac);
			return e;
		}
		// 1 * y = y
		if (x->type == SYM_INT && x->value == 1)
		{
			exp2->tac = join_tac(exp1->tac, exp2->tac);
			return exp2;
		}
		// x * 1 = x
		if (y->type == SYM_INT && y->value == 1)
		{
			exp1->tac = join_tac(exp1->tac, exp2->tac);
			return exp1;
		}
	}
	else if (binop == TAC_DIV)
	{
		// 0 / y = 0
		if (x->type == SYM_INT && x->value == 0)
		{
			EXP *e = exp1;
			e->ret = mk_const(0);
			e->tac = join_tac(exp1->tac, exp2->tac);
			return e;
		}
		// x / 1 = x
		if (y->type == SYM_INT && y->value == 1)
		{
			exp1->tac = join_tac(exp1->tac, exp2->tac);
			return exp1;
		}
		// x / 0 报错
		if (y->type == SYM_INT && y->value == 0)
		{
			error("divide by zero");
			exp1->tac = join_tac(exp1->tac, exp2->tac);
			return exp1;
		}
	}

	if ((exp1->ret->type == SYM_INT || exp1->ret->type == SYM_CHAR) &&
		(exp2->ret->type == SYM_INT || exp2->ret->type == SYM_CHAR))
	{
		int newval;

		switch (binop)
		{
		case TAC_ADD:
			newval = exp1->ret->value + exp2->ret->value;
			break;

		case TAC_SUB:
			newval = exp1->ret->value - exp2->ret->value;
			break;

		case TAC_MUL:
			newval = exp1->ret->value * exp2->ret->value;
			break;

		case TAC_DIV:
			newval = exp1->ret->value / exp2->ret->value;
			break;
		}

		exp1->ret = mk_const(newval);

		return exp1;
	}

	temp = mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev = join_tac(exp1->tac, exp2->tac);
	ret = mk_tac(binop, temp->a, exp1->ret, exp2->ret);
	ret->prev = temp;

	exp1->ret = temp->a;
	exp1->tac = ret;

	return exp1;
}

EXP *do_cmp(int binop, EXP *exp1, EXP *exp2)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret;  /* TAC code for result */

	if ((exp1->ret->type == SYM_INT || exp1->ret->type == SYM_CHAR) &&
		(exp2->ret->type == SYM_INT || exp2->ret->type == SYM_CHAR))

	{
		int newval;
		switch (binop)
		{
		case TAC_EQ:
			newval = (exp1->ret->value == exp2->ret->value);
			break;
		case TAC_NE:
			newval = (exp1->ret->value != exp2->ret->value);
			break;
		case TAC_LT:
			newval = (exp1->ret->value < exp2->ret->value);
			break;
		case TAC_LE:
			newval = (exp1->ret->value <= exp2->ret->value);
			break;
		case TAC_GT:
			newval = (exp1->ret->value > exp2->ret->value);
			break;
		case TAC_GE:
			newval = (exp1->ret->value >= exp2->ret->value);
			break;
		}
		exp1->ret = mk_const(newval);

		return exp1;
	}

	temp = mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev = join_tac(exp1->tac, exp2->tac);

	ret = mk_tac(binop, temp->a, exp1->ret, exp2->ret);
	ret->prev = temp;

	exp1->ret = temp->a;
	exp1->tac = ret;

	return exp1;
}

EXP *do_un(int unop, EXP *exp)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret;  /* TAC code for result */

	if (exp->ret->type == SYM_INT)
	{
		int newval;
		switch (unop)
		{
		case TAC_NEG:
			newval = (-exp->ret->value);
			break;
		}
		exp->ret = mk_const(newval);

		return exp;
	}

	temp = mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev = exp->tac;
	ret = mk_tac(unop, temp->a, exp->ret, NULL);
	ret->prev = temp;

	exp->ret = temp->a;
	exp->tac = ret;

	return exp;
}

// 反转参数链表
EXP *reverse_args(EXP *head)
{
	EXP *prev = NULL, *cur = head, *next;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

// 没有返回值的函数调用
TAC *do_call(char *name, EXP *arglist)
{
	EXP *alt;  /* For counting args */
	TAC *code; /* Resulting code */
	TAC *temp; /* Temporary for building code */

	arglist = reverse_args(arglist);

	code = NULL;
	for (alt = arglist; alt != NULL; alt = alt->next)
		code = join_tac(code, alt->tac);

	while (arglist != NULL) /* Generate ARG instructions */
	{
		temp = mk_tac(TAC_ACTUAL, arglist->ret, NULL, NULL);
		temp->prev = code;
		code = temp;

		alt = arglist->next;
		arglist = alt;
	};

	temp = mk_tac(TAC_CALL, NULL, (SYM *)strdup(name), NULL);
	temp->prev = code;
	code = temp;

	return code;
}

// 有返回值的函数调用
EXP *do_call_ret(char *name, EXP *arglist)
{
	EXP *alt;  /* For counting args */
	SYM *ret;  /* Where function result will go */
	TAC *code; /* Resulting code */
	TAC *temp; /* Temporary for building code */

	arglist = reverse_args(arglist);

	ret = mk_tmp(); /* For the result */
	code = mk_tac(TAC_VAR, ret, NULL, NULL);

	for (alt = arglist; alt != NULL; alt = alt->next)
		code = join_tac(code, alt->tac);

	while (arglist != NULL) /* Generate ARG instructions */
	{
		temp = mk_tac(TAC_ACTUAL, arglist->ret, NULL, NULL);
		temp->prev = code;
		code = temp;

		alt = arglist->next;
		arglist = alt;
	};

	SYM *func_sym = lookup_sym(sym_tab_global, name);
	if (!func_sym)
		func_sym = declare_func(name);

	temp = mk_tac(TAC_CALL, ret, func_sym, NULL);
	// temp = mk_tac(TAC_CALL, ret, (SYM *)strdup(name), NULL);

	temp->prev = code;
	code = temp;

	return mk_exp(NULL, ret, code);
}

char *mk_lstr(int i)
{
	char lstr[10] = "L";
	sprintf(lstr, "L%d", i);
	return (strdup(lstr));
}

TAC *do_if(EXP *exp, TAC *stmt)
{
	TAC *label = mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
	TAC *code = mk_tac(TAC_IFZ, label->a, exp->ret, NULL);

	code->prev = exp->tac;
	code = join_tac(code, stmt);
	label->prev = code;

	return label;
}

TAC *do_case(int value, TAC *body)
{
	// TAC中：统一先根据value,goto Label；再执行相应body,goto Lend
	SYM *val = mk_const(value);
	SYM *label = mk_label(mk_lstr(next_label++));

	TAC *body_chain = mk_tac(TAC_LABEL, label, NULL, NULL);
	body_chain = join_tac(body_chain, body);

	TAC *meta = mk_tac(TAC_CASE, val, label, NULL);
	meta->etc = body_chain; // 使用etc存放body

	return meta;
}

TAC *do_switch(EXP *expr, TAC *cases, TAC *def, SYM *end_label)
{
	TAC *code = expr ? expr->tac : NULL;

	SYM *default_label = NULL;
	if (def && def->op == TAC_LABEL)
		default_label = def->a;
	else if (def)
	{
		default_label = mk_label(mk_lstr(next_label++));
		def = join_tac(mk_tac(TAC_LABEL, default_label, NULL, NULL), def);
	}
	else // 没有default直接到end
		default_label = end_label;

	for (TAC *c = cases; c; c = c->prev) // cases:由join_tac连接，倒序
	{
		if (c->op != TAC_CASE)
			continue;

		// case a: goto b
		SYM *case_val = c->a;
		SYM *case_label = c->b;

		SYM *tcmp = mk_tmp();
		TAC *decl = mk_tac(TAC_VAR, tcmp, NULL, NULL);
		TAC *cmp = mk_tac(TAC_NE, tcmp, expr->ret, case_val); // expr->ret != val, 由于ifz
		TAC *ifz = mk_tac(TAC_IFZ, case_label, tcmp, NULL);

		TAC *part = join_tac(decl, cmp);
		part = join_tac(part, ifz);
		code = join_tac(part, code);
	}

	// 无default则到end
	code = join_tac(code, mk_tac(TAC_GOTO, default_label, NULL, NULL));

	for (TAC *c = cases; c; c = c->prev)
	{
		if (c->op != TAC_CASE)
			continue;
		TAC *body_chain = (TAC *)c->etc;
		code = join_tac(code, body_chain); // 拼接每个case的body
	}

	if (def)
		code = join_tac(code, def);
	code = join_tac(code, mk_tac(TAC_LABEL, end_label, NULL, NULL));
	return code;
}

TAC *do_test(EXP *exp, TAC *stmt1, TAC *stmt2)
{
	TAC *label1 = mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
	TAC *label2 = mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
	TAC *code1 = mk_tac(TAC_IFZ, label1->a, exp->ret, NULL);
	TAC *code2 = mk_tac(TAC_GOTO, label2->a, NULL, NULL);

	code1->prev = exp->tac; /* Join the code */
	code1 = join_tac(code1, stmt1);
	code2->prev = code1;
	label1->prev = code2;
	label1 = join_tac(label1, stmt2);
	label2->prev = label1;

	return label2;
}

TAC *do_while(EXP *cond, TAC *body, SYM *start_sym, SYM *cont_sym, SYM *end_sym)
{
	if (!start_sym)
		error("do_while: start_sym is NULL");
	if (!cont_sym)
		error("do_while: cont_sym is NULL");
	if (!end_sym)
		error("do_while: end_sym is NULL");
	TAC *t_start = mk_tac(TAC_LABEL, start_sym, NULL, NULL);
	TAC *t_cont = mk_tac(TAC_LABEL, cont_sym, NULL, NULL);
	TAC *t_end = mk_tac(TAC_LABEL, end_sym, NULL, NULL);

	TAC *code = NULL;

	code = join_tac(code, t_start);

	if (cond && cond->tac)
		code = join_tac(code, cond->tac);

	code = join_tac(code, mk_tac(TAC_IFZ, end_sym, cond ? cond->ret : NULL, NULL));

	if (body)
		code = join_tac(code, body);

	code = join_tac(code, t_cont);
	code = join_tac(code, mk_tac(TAC_GOTO, start_sym, NULL, NULL));
	code = join_tac(code, t_end); // 循环结束
	return code;
}

TAC *do_for(TAC *init, EXP *cond, TAC *step, TAC *body,
			SYM *start_sym, SYM *cont_sym, SYM *end_sym)
{
	TAC *t_start = mk_tac(TAC_LABEL, start_sym, NULL, NULL);
	TAC *t_cont = mk_tac(TAC_LABEL, cont_sym, NULL, NULL);
	TAC *t_end = mk_tac(TAC_LABEL, end_sym, NULL, NULL);

	TAC *code = NULL;

	code = join_tac(code, init);	// 初始化
	code = join_tac(code, t_start); // 循环开始标签

	if (cond && cond->tac)
		code = join_tac(code, cond->tac); // 条件

	// 判断是否继续：IFZ
	code = join_tac(code, mk_tac(TAC_IFZ, end_sym, cond ? cond->ret : NULL, NULL));

	if (body)
		code = join_tac(code, body); // 循环体

	code = join_tac(code, t_cont); // 继续标签

	if (step)
		code = join_tac(code, step); // 更新

	code = join_tac(code, mk_tac(TAC_GOTO, start_sym, NULL, NULL)); // goto Lstart
	code = join_tac(code, t_end);									// 循环结束
	return code;
}

// GOTO:Lend
TAC *do_break()
{
	SYM *end_label = get_break_label();
	// printf("[DEBUG] do_break: loop_depth=%d end_label=%p\n", loop_depth, end_label);
	return mk_tac(TAC_GOTO, end_label, NULL, NULL);
}

// GOTO:Lcontinue
TAC *do_continue()
{
	SYM *continue_label = get_continue_label();
	return mk_tac(TAC_GOTO, continue_label, NULL, NULL);
}

SYM *get_var(char *name)
{
	SYM *sym = NULL; /* Pointer to looked up symbol */

	if (scope)
		sym = lookup_sym(sym_tab_local, name);

	if (sym == NULL)
		sym = lookup_sym(sym_tab_global, name);

	if (sym == NULL)
	{
		error("name not declared as local/global variable");
		return NULL;
	}

	if (sym->type != SYM_VAR && sym->type != SYM_ARRAY && sym->type != SYM_STRUCT)
	{
		error("not a variable");
		return NULL;
	}

	return sym;
}

EXP *mk_exp(EXP *next, SYM *ret, TAC *code)
{
	EXP *exp = (EXP *)malloc(sizeof(EXP));

	exp->next = next;
	exp->ret = ret;
	exp->tac = code;

	return exp;
}

SYM *mk_text(char *text)
{
	SYM *sym = NULL; /* Pointer to looked up symbol */

	sym = lookup_sym(sym_tab_global, text);

	/* text already used */
	if (sym != NULL)
	{
		return sym;
	}

	/* text unseen before */
	sym = mk_sym();
	sym->type = SYM_TEXT;
	sym->name = strdup(text);
	sym->label = next_label++;

	insert_sym(&sym_tab_global, sym);
	return sym;
}

SYM *mk_const(int n)
{
	SYM *sym = NULL;

	char name[10];
	sprintf(name, "%d", n);

	sym = lookup_sym(sym_tab_global, name);
	if (sym != NULL)
	{
		return sym;
	}

	sym = mk_sym();
	sym->type = SYM_INT;
	sym->value = n;
	sym->name = strdup(name);
	insert_sym(&sym_tab_global, sym);

	return sym;
}

SYM *mk_char(int c)
{
	SYM *sym = NULL;

	char name[10];

	sprintf(name, "%c", c);

	sym = lookup_sym(sym_tab_global, name);
	if (sym != NULL)
	{
		return sym;
	}

	sym = mk_sym();
	sym->type = SYM_CHAR;
	sym->value = c;
	sym->name = strdup(name);
	insert_sym(&sym_tab_global, sym);

	return sym;
}

char *to_str(SYM *s, char *str)
{
	if (s == NULL)
		return "NULL";

	switch (s->type)
	{
	case SYM_TMP:
	case SYM_FUNC:
	case SYM_VAR:
	case SYM_ARRAY:
	case SYM_STRUCT:
	case SYM_PTR:
		/* Just return the name */
		return s->name;

	case SYM_TEXT:
		/* Put the address of the text */
		sprintf(str, "L%d", s->label);
		return str;

	case SYM_INT:
		/* Convert the number to string */
		sprintf(str, "%d", s->value);
		return str;

	case SYM_CHAR:
		sprintf(str, "'%c'", s->value);
		return str;

	default:
		/* Unknown arg type */
		error("unknown TAC arg type");
		return "?";
	}
}

void out_str(FILE *f, const char *format, ...)
{
	va_list args;
	va_start(args, format);
	vfprintf(f, format, args);
	va_end(args);
}

void out_sym(FILE *f, SYM *s)
{
	out_str(f, "%p\t%s", s, s->name);
}

void out_tac(FILE *f, TAC *i)
{
	char sa[12]; /* For text of TAC args */
	char sb[12];
	char sc[12];

	switch (i->op)
	{
	case TAC_UNDEF:
		fprintf(f, "undef");
		break;

	case TAC_ADD:
		fprintf(f, "%s = %s + %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

	case TAC_SUB:
		fprintf(f, "%s = %s - %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

	case TAC_MUL:
		fprintf(f, "%s = %s * %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

	case TAC_DIV:
		fprintf(f, "%s = %s / %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

	case TAC_EQ:
		fprintf(f, "%s = (%s == %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

	case TAC_NE:
		fprintf(f, "%s = (%s != %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

	case TAC_LT:
		fprintf(f, "%s = (%s < %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

	case TAC_LE:
		fprintf(f, "%s = (%s <= %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

	case TAC_GT:
		fprintf(f, "%s = (%s > %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

	case TAC_GE:
		fprintf(f, "%s = (%s >= %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

	case TAC_ADDR:
		fprintf(f, "%s = &%s", to_str(i->a, sa), to_str(i->b, sb));
		break;

	case TAC_LOAD:
		fprintf(f, "%s = *%s", to_str(i->a, sa), to_str(i->b, sb));
		break;

	case TAC_STORE:
		fprintf(f, "*%s = %s", to_str(i->a, sa), to_str(i->b, sb));
		break;

	case TAC_LOADC:
		fprintf(f, "%s = c*%s", to_str(i->a, sa), to_str(i->b, sb));
		break;

	case TAC_STOREC:
		fprintf(f, "c*%s = %s", to_str(i->a, sa), to_str(i->b, sb));
		break;

	case TAC_VARARRAY:
		fprintf(f, "vararray %s[%dD]", to_str(i->a, sa), i->b ? i->b->value : 0);
		break;

	case TAC_LOADIDX:
		fprintf(f, "%s = %s[%s]", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

	case TAC_STOREIDX:
		fprintf(f, "%s[%s] = %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

	case TAC_NEG:
		fprintf(f, "%s = - %s", to_str(i->a, sa), to_str(i->b, sb));
		break;

	case TAC_COPY:
		fprintf(f, "%s = %s", to_str(i->a, sa), to_str(i->b, sb));
		break;

	case TAC_GOTO:
		fprintf(f, "goto %s", i->a->name);
		break;

	case TAC_IFZ:
		fprintf(f, "ifz %s goto %s", to_str(i->b, sb), i->a->name);
		break;

	case TAC_ACTUAL:
		fprintf(f, "actual %s", to_str(i->a, sa));
		break;

	case TAC_FORMAL:
		fprintf(f, "formal %s", to_str(i->a, sa));
		break;

	case TAC_CALL:
		if (i->a == NULL)
			fprintf(f, "call %s", i->b ? i->b->name : "<null>");
		else
			fprintf(f, "%s = call %s", to_str(i->a, sa), i->b ? i->b->name : "<null>");
		break;

	case TAC_INPUT:
		fprintf(f, "input %s", to_str(i->a, sa));
		break;

	case TAC_OUTPUT:
		fprintf(f, "output %s", to_str(i->a, sa));
		break;

	case TAC_RETURN:
		fprintf(f, "return %s", to_str(i->a, sa));
		break;

	case TAC_LABEL:
		fprintf(f, "label %s", i->a->name);
		break;

	case TAC_VAR:
		fprintf(f, "var %s", to_str(i->a, sa));
		break;

	case TAC_BEGINFUNC:
		fprintf(f, "begin");
		break;

	case TAC_ENDFUNC:
		fprintf(f, "end");
		break;

	default:
		error("unknown TAC opcode");
		break;
	}
}
