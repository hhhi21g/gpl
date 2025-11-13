#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "tac.h"

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

void add_struct_member(STRUCT *unused, int member_type, const char *mname, int size)
{
	if (!cur_structs)
		error("no struct member");

	STRUCT_MEMBER *m = (STRUCT_MEMBER *)malloc(sizeof(STRUCT_MEMBER));
	m->name = strdup(mname);
	m->type = SYM_VAR;
	m->offset = cur_structs->size;
	m->etc = member_type;
	m->next = cur_structs->members;
	cur_structs->members = m; // 倒序

	cur_structs->size += size;
}

// 结构体成员类型：数组
void add_struct_array_member(SYM *cur, int base_type, char *name, int cnt)
{
	int elem_size = (base_type == SYM_CHAR) ? 1 : 4;
	for (int i = 0; i < cnt; i++)
	{
		char buf[32];
		sprintf(buf, "%s[%d]", name, i);
		add_struct_member(cur, base_type, strdup(buf), elem_size);
	}
}

// 结构体成员类型：结构体(数组)
void add_struct_struct_member(SYM *cur, SYM *struct_type, char *name, int cnt)
{
	STRUCT *def = (STRUCT *)struct_type->etc;
	int struct_size = def->size;
	for (int i = 0; i < cnt; i++)
	{
		STRUCT_MEMBER *m = malloc(sizeof(STRUCT_MEMBER));
		char buf[32];
		if (cnt > 1)
		{
			sprintf(buf, "%s[%d]", name, i);
		}
		else
		{
			strcpy(buf, name);
		}
		// add_struct_member(cur, SYM_STRUCT, strdup(buf), struct_size);
		m->name = strdup(buf);
		m->type = SYM_STRUCT;
		m->offset = cur_structs->size;
		m->etc = def;
		m->next = cur_structs->members;
		cur_structs->members = m;

		cur_structs->size += struct_size;
	}
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

// 根据变量查找结构体
static STRUCT *get_struct_var(SYM *var)
{
	if (!var || var->type != SYM_STRUCT)
	{
		printf("[DEBUG] get_struct_var: %s type=%d\n",
			   var ? var->name : "(null)",
			   var ? var->type : -1);
		printf("%d\n", yylineno);

		error("not a struct");
	}
	return (STRUCT *)var->etc;
}

// 返回成员
STRUCT_MEMBER *get_struct_member(SYM *struct_var, const char *name)
{
	STRUCT *def = get_struct_var(struct_var);
	// printf("%s\n", name);
	// printf("[DEBUG] lookup member '%s' in struct '%s'\n", name, def->name);

	for (STRUCT_MEMBER *m = def->members; m; m = m->next)
	{
		// printf("-%s\n", m->name);
		if (strcmp(m->name, name) == 0)
			return m;
		if (strncmp(m->name, name, strlen(name)) == 0 && m->name[strlen(name)] == '[') // 数组类型匹配名称即可
			return m;
	}
	error("struct member not found");
	return NULL;
}

// 得到成员偏移量
int get_struct_offset(SYM *struct_var, const char *name)
{
	STRUCT *def = get_struct_var(struct_var);
	// printf("%s\n", name);
	// printf("[DEBUG] lookup member '%s' in struct '%s'\n", name, def->name);

	for (STRUCT_MEMBER *m = def->members; m; m = m->next)
	{
		printf("-%s\n", m->name);
		if (strcmp(m->name, name) == 0)
			return m->offset;
		if (strncmp(m->name, name, strlen(name)) == 0 && m->name[strlen(name)] == '[') // 数组类型匹配名称即可
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

// 获得结构体成员地址(所在结构体地址+偏移)
EXP *make_struct_field_addr(EXP *base, int offset)
{
	SYM *tmp = mk_tmp();
	TAC *decl = mk_tac(TAC_VAR, tmp, NULL, NULL);

	SYM *off = mk_const(offset);
	TAC *add = mk_tac(TAC_ADD, tmp, base->ret, off);
	add->prev = join_tac(decl, base->tac);

	tmp->type = SYM_STRUCT;
	tmp->etc = base->ret->etc;

	return mk_exp(NULL, tmp, add);
}

// // 计算数组元素的地址(struct,int,char)
// EXP *make_array_elem_addr(EXP *base, EXP *index)
// {
// 	int elem_size = 0;
// 	int elem_type = 0;
// 	void *elem_etc = NULL;

// 	printf("%d\n", base->ret->type);
// 	if (base->ret)
// 	{
// 		switch (base->ret->type)
// 		{
// 		case SYM_STRUCT:
// 		{
// 			// 结构体数组
// 			STRUCT *sdef = (STRUCT *)base->ret->etc;
// 			elem_size = sdef->size;
// 			elem_type = SYM_STRUCT;
// 			elem_etc = sdef; // 保留结构体定义
// 			break;
// 		}

// 		case SYM_ARRAY:
// 		{
// 			// 普通数组 (etc里是元素类型)
// 			int t = *((int *)base->ret->etc);
// 			elem_size = (t == SYM_CHAR) ? 1 : 4;
// 			elem_type = SYM_ARRAY;
// 			// 为元素保存基础类型指针（int*）
// 			elem_etc = malloc(sizeof(int *));
// 			*((int *)elem_etc) = t;
// 			break;
// 		}

// 		case SYM_VAR:
// 		{
// 			printf("SYM_VAR\n");
// 			printf("%d\n", yylineno);
// 			int t = *((int *)base->ret->etc);
// 			printf("%d\n", t);
// 			elem_size = (t == SYM_CHAR) ? 1 : 4;
// 			elem_type = SYM_VAR;
// 			elem_etc = malloc(sizeof(int *));
// 			*((int *)elem_etc) = t;
// 			break;
// 		}

// 		default:
// 			printf("line:%d\n", yylineno);
// 			error("invalid array base type");
// 		}
// 	}

// 	SYM *t_mul = mk_tmp();
// 	TAC *decl1 = mk_tac(TAC_VAR, t_mul, NULL, NULL);

// 	// index * elem_size
// 	TAC *mul = mk_tac(TAC_MUL, t_mul, index->ret, mk_const(elem_size));
// 	mul->prev = join_tac(decl1, join_tac(base->tac, index->tac));

// 	// base + t_mul
// 	SYM *addr = mk_tmp();
// 	TAC *decl2 = mk_tac(TAC_VAR, addr, NULL, NULL);
// 	TAC *add = mk_tac(TAC_ADD, addr, base->ret, t_mul);
// 	add->prev = join_tac(decl2, mul);
// 	// addr->type = base->ret->type;

// 	addr->type = elem_type;
// 	addr->etc = elem_etc;

// 	printf("[DEBUG] make_array_elem_addr: base=%s type=%d etc=%p -> addr=%s type=%d etc=%p\n",
// 		   base->ret->name, base->ret->type, base->ret->etc,
// 		   addr->name, addr->type, addr->etc);

// 	return mk_exp(NULL, addr, add);
// }

// 计算数组元素的地址(struct,int,char)
EXP *make_array_elem_addr(EXP *base, EXP *index)
{
	int elem_size = 0;
	int elem_type = SYM_UNDEF;
	void *elem_etc = NULL;

	if (base && base->ret)
	{
		// 结构体数组
		if (base->ret->type == SYM_STRUCT && base->ret->etc)
		{
			STRUCT *sdef = (STRUCT *)base->ret->etc;
			elem_size = sdef->size;
			elem_type = SYM_STRUCT;
			elem_etc = sdef;
		}
		// 普通数组（如 int a[10]; char b[20];）
		else if (base->ret->type == SYM_ARRAY && base->ret->etc)
		{
			int t = *((int *)base->ret->etc);
			elem_size = (t == SYM_CHAR) ? 1 : 4;
			elem_type = SYM_VAR; // 元素是变量地址
			elem_etc = malloc(sizeof(int));
			*((int *)elem_etc) = t;
		}
		// 一般变量的数组成员（如 stu[3].name[2]）
		else if (base->ret->type == SYM_VAR && base->ret->etc)
		{
			int t = *((int *)base->ret->etc);
			elem_size = (t == SYM_CHAR) ? 1 : 4;
			elem_type = SYM_VAR;
			elem_etc = malloc(sizeof(int));
			*((int *)elem_etc) = t;
		}
		// 最后保险：未知情况
		else
		{
			elem_size = 1;
			elem_type = SYM_VAR;
			elem_etc = malloc(sizeof(int));
			*((int *)elem_etc) = SYM_CHAR;
		}
	}

	// index * elem_size
	SYM *t_mul = mk_tmp();
	TAC *decl1 = mk_tac(TAC_VAR, t_mul, NULL, NULL);
	TAC *mul = mk_tac(TAC_MUL, t_mul, index->ret, mk_const(elem_size));
	mul->prev = join_tac(decl1, join_tac(base->tac, index->tac));

	// base + t_mul
	SYM *addr = mk_tmp();
	TAC *decl2 = mk_tac(TAC_VAR, addr, NULL, NULL);
	TAC *add = mk_tac(TAC_ADD, addr, base->ret, t_mul);
	add->prev = join_tac(decl2, mul);

	// ✅ 修正类型语义
	addr->type = elem_type;
	addr->etc = elem_etc;

	printf("[DEBUG] make_array_elem_addr: base=%s type=%d etc=%p -> addr=%s type=%d etc=%p\n",
		   base->ret->name, base->ret->type, base->ret->etc,
		   addr->name, addr->type, addr->etc);

	return mk_exp(NULL, addr, add);
}

// 对 lvalue 赋值
TAC *do_assign_lvalue(EXP *lv, EXP *rhs)
{
	// 生成 *addr = value
	TAC *store = mk_tac(TAC_STORE, lv->ret, rhs->ret, NULL);
	store->prev = join_tac(lv->tac, rhs->tac);
	return store;
}

// 从 lvalue 加载值
EXP *do_load_lvalue(EXP *lv)
{
	SYM *tmp = mk_tmp();
	TAC *decl = mk_tac(TAC_VAR, tmp, NULL, NULL);
	TAC *load = mk_tac(TAC_LOAD, tmp, lv->ret, NULL);
	load->prev = join_tac(decl, lv->tac);
	return mk_exp(NULL, tmp, load);
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

int cfg_fold_if()
{
	int changed = 0;
	for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
	{
		TAC *t = bb->last;
		if (!t)
			continue;
		if (t->op == TAC_IFZ && is_const_sym(t->b))
		{
			if (t->b->value == 0)
			{ // GOTO L
				t->op = TAC_GOTO;
				t->b = NULL;
				changed = 1;
			}
			else
			{ // 永远不会跳转
				t->op = TAC_VAR;
				t->a = mk_tmp();
				t->b = t->c = NULL;
				changed = 1;
			}
		}
	}
}

// 标记可达块
static void mark_reachable(BASIC_BLOCK *start)
{
	for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
	{
		bb->mark = 0;
	}
	BASIC_BLOCK *stack[4096];
	int top = 0;
	if (start)
	{
		stack[top++] = start;
		start->mark = 1;
	}
	while (top)
	{
		BASIC_BLOCK *u = stack[--top];
		for (int i = 0; i < u->succ_count; i++)
		{
			BASIC_BLOCK *v = u->succ[i];
			if (v && !v->mark)
			{
				v->mark = 1;
				stack[top++] = v;
			}
		}
	}
}
void remove_unreachable_blocks()
{
	if (!bb_list)
		return;
	mark_reachable(bb_list);
	// 从块链表中摘掉不可达块
	BASIC_BLOCK *prev = NULL, *cur = bb_list;
	while (cur)
	{
		if (!cur->mark)
		{
			BASIC_BLOCK *del = cur;
			cur = cur->next;
			if (prev)
				prev->next = cur;
			else
				bb_list = cur;
			if (del == bb_tail)
				bb_tail = prev;
			// 这里可以 free(del->succ/pred)，简单起见略
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	// 可选：重建线性 TAC 链（让 tac_first/tac_last 与当前块列表一致）
	TAC *first = NULL, *last = NULL;
	for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
	{
		for (TAC *t = bb->first;; t = t->next)
		{
			t->prev = last;
			if (last)
				last->next = t;
			else
				first = t;
			last = t;
			if (t == bb->last)
				break;
		}
	}
	if (last)
		last->next = NULL;
	tac_first = first;
	tac_last = last; // （注意：你的 tac_last 是“反向链表尾”吗？按你当前结构，这样设置就够用）
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

	for (BASIC_BLOCK *bb = bb_list; bb != NULL; bb = bb->next)
	{
		TAC *last = bb->last;

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

// TAC *join_tac(TAC *c1, TAC *c2)
// {
// 	TAC *t;

// 	if (c1 == NULL)
// 		return c2;
// 	if (c2 == NULL)
// 		return c1;

// 	/* Run down c2, until we get to the beginning and then add c1 */
// 	t = c2;
// 	while (t->prev != NULL)
// 		t = t->prev;

// 	t->prev = c1;
// 	return c2;
// }

// 判断 x 链（沿 prev 走）里是否包含某节点 target
static int chain_contains(TAC *x, TAC *target)
{
	for (TAC *p = x; p; p = p->prev)
		if (p == target)
			return 1;
	return 0;
}

TAC *join_tac(TAC *c1, TAC *c2)
{
	if (!c1)
		return c2;
	if (!c2)
		return c1;

	// 保险：避免把同一条链 join 到自身造成环
	if (chain_contains(c1, c2) || chain_contains(c2, c1))
	{
		// 这里不直接报错，用更保守的策略：认为已经连接好，返回 c2
		// 也可以改成 error("join_tac: attempt to join overlapping chains");
		return c2;
	}

	// 找到 c2 的“头”（最早的指令）
	TAC *head2 = c2;
	while (head2->prev)
		head2 = head2->prev;

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
	SYM *sym;
	char *name;

	name = malloc(12);
	sprintf(name, "t%d", next_tmp++); /* Set up text */
	return mk_var(name);
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

	if ((exp1->ret->type == SYM_INT || exp1->ret->type == SYM_CHAR) && (exp2->ret->type == SYM_INT || exp1->ret->type == SYM_CHAR))
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
	case SYM_FUNC:
	case SYM_VAR:
	case SYM_ARRAY:
	case SYM_STRUCT:
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
