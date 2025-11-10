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

int tac_constant_fold(BASIC_BLOCK *bb)
{ // 每个BB内部
	int changed = 0;
	CMap *env = NULL;
	SYM *bc, *cc;

	for (TAC *t = bb->first; t; t = (t == bb->last ? NULL : t->next))
	{
		switch (t->op)
		{
		case TAC_COPY:
			SYM *c = is_const_sym(t->b) ? t->b : cmap_get(env, t->b);
			if (c)
			{ // b是常量，则a也是常量
				cmap_set(&env, t->a, c);
			}
			else
			{
				cmap_kill(&env, t->a);
			}
			break;
		case TAC_ADD:
		case TAC_SUB:
		case TAC_MUL:
		case TAC_DIV:
		case TAC_EQ:
		case TAC_NE:
		case TAC_LT:
		case TAC_LE:
		case TAC_GT:
		case TAC_GE:
			bc = is_const_sym(t->b) ? t->b : cmap_get(env, t->b);
			cc = is_const_sym(t->c) ? t->c : cmap_get(env, t->c);
			if (bc && cc)
			{
				SYM *rc = eval_bin(t->op, bc, cc);
				if (rc)
				{
					t->op = TAC_COPY;
					t->b = rc;
					t->c = NULL;
					changed = 1;
					cmap_set(&env, t->a, rc);
				}
				else
				{
					cmap_kill(&env, t->a);
				}
			}
			else
			{
				cmap_kill(&env, t->a);
			}
			break;
		case TAC_NEG:
			bc = is_const_sym(t->b) ? t->b : cmap_get(env, t->b);
			if (bc)
			{
				SYM *rc = eval_un(TAC_NEG, bc);
				if (rc)
				{
					t->op = TAC_COPY;
					t->b = rc;
					t->c = NULL;
					changed = 1;
					cmap_set(&env, t->a, rc);
				}
				else
				{
					cmap_kill(&env, t->a);
				}
			}
			break;
		case TAC_IFZ:
			bc = is_const_sym(t->b) ? t->b : cmap_get(env, t->b);
			if (bc)
			{
				changed = 1;
				t->b = bc;
			}
			break;
		}
		if (t == bb->last)
			break;
	}
	return changed;
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
		sym = lookup_sym(sym_tab_local, name);
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
	TAC *t;

	if (c1 == NULL)
		return c2;
	if (c2 == NULL)
		return c1;

	/* Run down c2, until we get to the beginning and then add c1 */
	t = c2;
	while (t->prev != NULL)
		t = t->prev;

	t->prev = c1;
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
	for (EXP *p = dims; p; p = p->next)
	{
		ndim++;
	}

	sym->ndim = ndim;
	sym->dims = malloc(sizeof(int) * ndim);

	int i = ndim - 1;

	for (EXP *p = dims; p; p = p->next)
	{
		sym->dims[i--] = p->ret->value;
	}

	sym->etc = malloc(sizeof(int));
	*((int *)sym->etc) = type; // 使用etc存储数组类型

	return mk_tac(TAC_VARARRAY, sym, mk_const(ndim), NULL);
}

// 将下标转换为偏移量
static EXP *cal_array_offset(SYM *arr, EXP *idxs)
{
	int ndim = arr->ndim;
	int *dims = arr->dims;

	EXP *result = idxs;
	int d = 1;
	for (EXP *p = idxs->next; p; p = p->next)
	{
		SYM *t = mk_tmp();
		TAC *decl = mk_tac(TAC_VAR, t, NULL, NULL);
		TAC *mul = mk_tac(TAC_MUL, t, result->ret, mk_const(dims[ndim - d]));
		TAC *add = mk_tac(TAC_ADD, t, mul->a, p->ret);

		add->prev = join_tac(join_tac(result->tac, p->tac), join_tac(decl, mul));
		result = mk_exp(NULL, t, add);

		d++;
	}

	// int*4, char*1
	SYM *t = mk_tmp();
	TAC *decl = mk_tac(TAC_VAR, t, NULL, NULL);
	TAC *mul;
	if (arr->etc == SYM_INT)
		mul = mk_tac(TAC_MUL, t, result->ret, mk_const(4));
	else
		mul = mk_tac(TAC_MUL, t, result->ret, mk_const(1));
	mul->prev = join_tac(result->tac, decl);
	result = mk_exp(NULL, t, mul);

	return result;
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
			error("func already declared");
			return NULL;
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

	/*
	if((exp1->ret->type==SYM_INT) && (exp2->ret->type==SYM_INT))
	{
		int newval;

		switch(binop)
		{
			case TAC_ADD:
			newval=exp1->ret->value + exp2->ret->value;
			break;

			case TAC_SUB:
			newval=exp1->ret->value - exp2->ret->value;
			break;

			case TAC_MUL:
			newval=exp1->ret->value * exp2->ret->value;
			break;

			case TAC_DIV:
			newval=exp1->ret->value / exp2->ret->value;
			break;
		}

		exp1->ret=mk_const(newval);

		return exp1;
	}
	*/

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

// 没有返回值的函数调用
TAC *do_call(char *name, EXP *arglist)
{
	EXP *alt;  /* For counting args */
	TAC *code; /* Resulting code */
	TAC *temp; /* Temporary for building code */

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

	temp = mk_tac(TAC_CALL, ret, (SYM *)strdup(name), NULL);
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

	if (sym->type != SYM_VAR && sym->type != SYM_ARRAY)
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
			fprintf(f, "call %s", (char *)i->b);
		else
			fprintf(f, "%s = call %s", to_str(i->a, sa), (char *)i->b);
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
