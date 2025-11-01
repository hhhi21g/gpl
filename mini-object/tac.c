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

void tac_init()
{
	scope = 0;
	sym_tab_global = NULL;
	sym_tab_local = NULL;
	next_tmp = 0;
	next_label = 1;
}

// 赋值传播
int tac_copy_propagation()
{
	int changed = 0;

	for (TAC *t = tac_first; t != NULL;)
	{
		if (t->op != TAC_COPY)
		{
			t = t->next;
			continue; // 只有赋值才需要判断
		}
		SYM *x = t->a; // 左值
		SYM *y = t->b; // 右值

		int is_propagation = 0;

		for (TAC *i = t->next; i != NULL; i = i->next)
		{
			if ((i->a == x) || (i->a == y))
				break; // 左值或右值被重新赋值，停止
			if (i->b == x)
			{
				i->b = y;
				is_propagation = 1;
			}
			if (i->c == x)
			{
				i->c = y;
				is_propagation = 1;
			}

			if ((i->op == TAC_OUTPUT || i->op == TAC_RETURN) && i->a == x)
			{
				i->a = y;
				is_propagation = 1;
			}
		}
		// 原赋值tac删除
		if (is_propagation)
		{
			TAC *del = t;
			t = t->next; // 保存位置
			if (del->prev)
				del->prev->next = del->next;
			else
				tac_first = del->next;

			if (del->next)
				del->next->prev = del->prev;
			else
				tac_last = del->prev;

			free(del);
			changed = 1;
			continue;
		}
		else
		{
			t = t->next;
		}
	}
	return changed;
}

int tac_constant_folding()
{
	int changed = 0;

	for (TAC *t = tac_first; t != NULL; t = t->next)
	{
		if (t->b && t->c &&
			(t->op == TAC_ADD || t->op == TAC_SUB ||
			 t->op == TAC_MUL || t->op == TAC_DIV ||
			 t->op == TAC_EQ || t->op == TAC_NE ||
			 t->op == TAC_LT || t->op == TAC_LE ||
			 t->op == TAC_GT || t->op == TAC_GE))
		{
			SYM *b = t->b;
			SYM *c = t->c;

			if ((b->type == SYM_INT || b->type == SYM_CHAR) && (c->type == SYM_INT || c->type == SYM_CHAR))
			{
				int x = b->value;
				int y = c->value;
				int v = 0;
				switch (t->op)
				{
				case TAC_ADD:
					v = x + y;
					break;
				case TAC_SUB:
					v = x - y;
					break;
				case TAC_MUL:
					v = x * y;
					break;
				case TAC_DIV:
					if (y == 0)
						continue;
					v = x / y;
					break;
				case TAC_EQ:
					v = (x == y);
					break;
				case TAC_NE:
					v = (x != y);
					break;
				case TAC_LT:
					v = (x < y);
					break;
				case TAC_LE:
					v = (x <= y);
					break;
				case TAC_GT:
					v = (x > y);
					break;
				case TAC_GE:
					v = (x >= y);
					break;
				}

				t->op = TAC_COPY; // 二元运算修改为赋值语句
				t->b = mk_const(v);
				t->c = NULL;
				changed = 1;
			}
			else if (t->op == TAC_ADD && b->type == SYM_INT && b->value == 0) // 0 + c = c
			{
				t->op = TAC_COPY;
				t->b = c;
				t->c = NULL;
				changed = 1;
			}
			else if (t->op == TAC_ADD && c->type == SYM_INT && c->value == 0) // b + 0 = b
			{
				t->op = TAC_COPY;
				t->b = b;
				t->c = NULL;
				changed = 1;
			}
			else if (t->op == TAC_SUB && b->type == SYM_INT && b->value == 0) // 0 - c = -c
			{
				if (c->type == SYM_INT)
				{
					// 0 - 常量
					t->op = TAC_COPY;
					t->b = mk_const(-(c->value));
					t->c = NULL;
				}
				else if (c->type != SYM_CHAR)
				{
					// 0 - 变量
					t->op = TAC_NEG;
					t->b = c;
					t->c = NULL;
				}
				changed = 1;
			}
			else if (t->op == TAC_SUB && c->type == SYM_INT && c->value == 0) // b - 0 = b
			{
				t->op = TAC_COPY;
				t->b = b;
				t->c = NULL;
				changed = 1;
			}
			else if (t->op == TAC_MUL && b->type == SYM_INT && b->value == 1) // 1 * c = c
			{
				t->op = TAC_COPY;
				t->b = c;
				t->c = NULL;
				changed = 1;
			}
			else if (t->op == TAC_MUL && c->type == SYM_INT && c->value == 1) // b * 1 = b
			{
				t->op = TAC_COPY;
				t->b = b;
				t->c = NULL;
				changed = 1;
			}
			else if (t->op == TAC_MUL && ((b->type == SYM_INT && b->value == 0) || (c->type == SYM_INT && c->value == 0)))
			{ // 0 * x = 0
				t->op = TAC_COPY;
				t->b = mk_const(0);
				t->c = NULL;
				changed = 1;
			}
			else if (t->op == TAC_DIV && b->type == SYM_INT && b->value == 0) // 0 / c = 0
			{
				t->op = TAC_COPY;
				t->b = mk_const(0);
				t->c = NULL;
				changed = 1;
			}
			else if (t->op == TAC_DIV && c->type == SYM_INT && c->value == 1) // b / 1 = b
			{
				t->op = TAC_COPY;
				t->b = b;
				t->c = NULL;
				changed = 1;
			}
		}
		else if (t->b && !t->c && t->op == TAC_NEG)
		{
			SYM *b = t->b;
			if (b->type == SYM_INT)
			{
				t->op = TAC_COPY;
				t->b = mk_const(-b->value);
				t->c = NULL;
				changed = 1;
			}
		}
	}
	return changed;
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
	*((int *)sym->etc) = sym_type;

	return mk_tac(TAC_VAR, sym, NULL, NULL);
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

	// 常量折叠
	// if ((exp1->ret->type == SYM_INT || exp1->ret->type == SYM_CHAR) && (exp2->ret->type == SYM_INT || exp1->ret->type == SYM_CHAR))
	// {
	// 	int newval;

	// 	switch (binop)
	// 	{
	// 	case TAC_ADD:
	// 		newval = exp1->ret->value + exp2->ret->value;
	// 		break;

	// 	case TAC_SUB:
	// 		newval = exp1->ret->value - exp2->ret->value;
	// 		break;

	// 	case TAC_MUL:
	// 		newval = exp1->ret->value * exp2->ret->value;
	// 		break;

	// 	case TAC_DIV:
	// 		newval = exp1->ret->value / exp2->ret->value;
	// 		break;
	// 	}

	// 	exp1->ret = mk_const(newval);

	// 	return exp1;
	// }

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

	// if ((exp1->ret->type == SYM_CHAR || exp1->ret->type == SYM_INT) && (exp2->ret->type == SYM_CHAR || exp2->ret->type == SYM_INT))
	// {
	// 	int newval;
	// 	switch (binop)
	// 	{
	// 	case TAC_EQ:
	// 		newval = (exp1->ret->value == exp2->ret->value);
	// 		break;
	// 	case TAC_NE:
	// 		newval = (exp1->ret->value != exp2->ret->value);
	// 		break;
	// 	case TAC_LT:
	// 		newval = (exp1->ret->value < exp2->ret->value);
	// 		break;
	// 	case TAC_LE:
	// 		newval = (exp1->ret->value <= exp2->ret->value);
	// 		break;
	// 	case TAC_GT:
	// 		newval = (exp1->ret->value > exp2->ret->value);
	// 		break;
	// 	case TAC_GE:
	// 		newval = (exp1->ret->value >= exp2->ret->value);
	// 		break;
	// 	}
	// 	exp1->ret = mk_const(newval);

	// 	return exp1;
	// }
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
	// if (exp->ret->type == SYM_INT)
	// {
	// 	int newval;
	// 	switch (unop)
	// 	{
	// 	case TAC_NEG:
	// 		newval = (-exp->ret->value);
	// 		break;
	// 	}
	// 	exp->ret = mk_const(newval);

	// 	return exp;
	// }

	temp = mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev = exp->tac;
	ret = mk_tac(unop, temp->a, exp->ret, NULL);
	ret->prev = temp;

	exp->ret = temp->a;
	exp->tac = ret;

	return exp;
}

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

TAC *do_while(EXP *exp, TAC *stmt)
{
	TAC *label = mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
	TAC *code = mk_tac(TAC_GOTO, label->a, NULL, NULL);

	code->prev = stmt; /* Bolt on the goto */

	return join_tac(label, do_if(exp, code));
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

	if (sym->type != SYM_VAR)
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
