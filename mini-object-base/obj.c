#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "tac.h"
#include "obj.h"

/* global var */
int tos; /* top of static */
int tof; /* top of frame */
int oof; /* offset of formal */
int oon; /* offset of next frame */
struct rdesc rdesc[R_NUM];
// int tmpoff;

void rdesc_clear(int r)
{
	rdesc[r].var = NULL;
	rdesc[r].mod = 0;
}

void rdesc_fill(int r, SYM *s, int mod)
{
	int old;
	for (old = R_GEN; old < R_NUM; old++)
	{
		if (rdesc[old].var == s)
		{
			rdesc_clear(old);
		}
	}

	rdesc[r].var = s;
	rdesc[r].mod = mod;
}

void asm_write_back(int r)
{
	if ((rdesc[r].var != NULL) && rdesc[r].mod)
	{
		if (rdesc[r].var->scope == 1) /* local var */
		{
			// out_str(file_s, "	STO (R%u+%u),R%u\n", R_BP, rdesc[r].var->offset, r);
			if (rdesc[r].var->offset >= 0)
				out_str(file_s, "    STO (R%u+%d),R%u\n", R_BP, rdesc[r].var->offset, r);
			else
				out_str(file_s, "    STO (R%u-%d),R%u\n", R_BP, -rdesc[r].var->offset, r);
		}
		else /* global var */
		{
			out_str(file_s, "	LOD R%u,STATIC\n", R_TP);
			out_str(file_s, "	STO (R%u+%u),R%u\n", R_TP, rdesc[r].var->offset, r);
		}
		rdesc[r].mod = UNMODIFIED;
	}
}

void asm_load(int r, SYM *s)
{
	/* already in a reg */
	for (int i = R_GEN; i < R_NUM; i++)
	{
		if (rdesc[i].var == s)
		{
			/* load from the reg */
			out_str(file_s, "	LOD R%u,R%u\n", r, i);

			/* update rdesc */
			// rdesc_fill(r, s, rdesc[i].mod);
			return;
		}
	}

	/* not in a reg */
	switch (s->type)
	{
	case SYM_INT:
	case SYM_CHAR:
		out_str(file_s, "	LOD R%u,%u\n", r, s->value);
		break;

	case SYM_VAR:
		if (s->scope == 1) /* local var */
		{
			if ((s->offset) >= 0)
				out_str(file_s, "	LOD R%u,(R%u+%d)\n", r, R_BP, s->offset);
			else
				out_str(file_s, "	LOD R%u,(R%u-%d)\n", r, R_BP, -(s->offset));
		}
		else /* global var */
		{
			out_str(file_s, "	LOD R%u,STATIC\n", R_TP);
			out_str(file_s, "	LOD R%u,(R%u+%d)\n", r, R_TP, s->offset);
		}
		break;

	case SYM_TEXT:
		out_str(file_s, "	LOD R%u,L%u\n", r, s->label);
		break;
	}

	// rdesc_fill(r, s, UNMODIFIED);
}

int reg_alloc(SYM *s)
{
	int r; /* already in a register */
	for (r = R_GEN; r < R_NUM; r++)
	{
		if (rdesc[r].var == s)
		{
			if (rdesc[r].mod)
				asm_write_back(r);
			return r;
		}
	} /* empty register */
	for (r = R_GEN; r < R_NUM; r++)
	{
		if (rdesc[r].var == NULL)
		{
			asm_load(r, s);
			rdesc_fill(r, s, UNMODIFIED);
			return r;
		}
	} /* unmodifed register */
	for (r = R_GEN; r < R_NUM; r++)
	{
		if (!rdesc[r].mod)
		{
			asm_load(r, s);
			rdesc_fill(r, s, UNMODIFIED);
			return r;
		}
	} /* random register */
	srand(time(NULL));
	int random = (rand() % (R_NUM - R_GEN)) + R_GEN;
	asm_write_back(random);
	asm_load(random, s);
	rdesc_fill(random, s, UNMODIFIED);
	return random;
}

int reg_alloc_temp()
{
	for (int r = R_GEN; r < R_NUM; r++)
		if (rdesc[r].var == NULL)
			return r;

	// 如果无空位，就随机选一个但不写入 rdesc
	return R_GEN;
}

void asm_bin(char *op, SYM *a, SYM *b, SYM *c)
{
	int reg_b, reg_c;

	if (b->type == SYM_INT)
	{
		reg_b = reg_alloc_temp();
		out_str(file_s, "    LOD R%u,%d\n", reg_b, b->value);
	}
	else
	{
		reg_b = reg_alloc(b);
	}

	if (c->type == SYM_INT)
	{
		reg_c = reg_alloc_temp();
		out_str(file_s, "    LOD R%u,%d\n", reg_c, c->value);
	}
	else
	{
		reg_c = reg_alloc(c);
	}

	if (reg_b == reg_c)
	{
		int new_reg_c = reg_alloc_temp();

		if (c->type == SYM_INT)
			out_str(file_s, "    LOD R%u,%d\n", new_reg_c, c->value);
		else
			out_str(file_s, "    LOD R%u,R%u\n", new_reg_c, reg_c);

		reg_c = new_reg_c;
	}

	out_str(file_s, "    %s R%u,R%u\n", op, reg_b, reg_c);

	rdesc_fill(reg_b, a, MODIFIED);
}

void asm_cmp(int op, SYM *a, SYM *b, SYM *c)
{
	int reg_b = -1, reg_c = -1;

	while (reg_b == reg_c)
	{
		reg_b = reg_alloc(b);
		reg_c = reg_alloc(c);
	}

	out_str(file_s, "	SUB R%u,R%u\n", reg_b, reg_c);
	out_str(file_s, "	TST R%u\n", reg_b);

	switch (op)
	{
	case TAC_EQ:
		out_str(file_s, "	LOD R3,R1+40\n");
		out_str(file_s, "	JEZ R3\n");
		out_str(file_s, "	LOD R%u,0\n", reg_b);
		out_str(file_s, "	LOD R3,R1+24\n");
		out_str(file_s, "	JMP R3\n");
		out_str(file_s, "	LOD R%u,1\n", reg_b);
		break;

	case TAC_NE:
		out_str(file_s, "	LOD R3,R1+40\n");
		out_str(file_s, "	JEZ R3\n");
		out_str(file_s, "	LOD R%u,1\n", reg_b);
		out_str(file_s, "	LOD R3,R1+24\n");
		out_str(file_s, "	JMP R3\n");
		out_str(file_s, "	LOD R%u,0\n", reg_b);
		break;

	case TAC_LT:
		out_str(file_s, "	LOD R3,R1+40\n");
		out_str(file_s, "	JLZ R3\n");
		out_str(file_s, "	LOD R%u,0\n", reg_b);
		out_str(file_s, "	LOD R3,R1+24\n");
		out_str(file_s, "	JMP R3\n");
		out_str(file_s, "	LOD R%u,1\n", reg_b);
		break;

	case TAC_LE:
		out_str(file_s, "	LOD R3,R1+40\n");
		out_str(file_s, "	JGZ R3\n");
		out_str(file_s, "	LOD R%u,1\n", reg_b);
		out_str(file_s, "	LOD R3,R1+24\n");
		out_str(file_s, "	JMP R3\n");
		out_str(file_s, "	LOD R%u,0\n", reg_b);
		break;

	case TAC_GT:
		out_str(file_s, "	LOD R3,R1+40\n");
		out_str(file_s, "	JGZ R3\n");
		out_str(file_s, "	LOD R%u,0\n", reg_b);
		out_str(file_s, "	LOD R3,R1+24\n");
		out_str(file_s, "	JMP R3\n");
		out_str(file_s, "	LOD R%u,1\n", reg_b);
		break;

	case TAC_GE:
		out_str(file_s, "	LOD R3,R1+40\n");
		out_str(file_s, "	JLZ R3\n");
		out_str(file_s, "	LOD R%u,1\n", reg_b);
		out_str(file_s, "	LOD R3,R1+24\n");
		out_str(file_s, "	JMP R3\n");
		out_str(file_s, "	LOD R%u,0\n", reg_b);
		break;
	}

	/* Delete c from the descriptors and insert a */
	rdesc_clear(reg_b);
	rdesc_fill(reg_b, a, MODIFIED);
}

void asm_cond(char *op, SYM *a, char *l)
{
	for (int r = R_GEN; r < R_NUM; r++)
		asm_write_back(r);

	if (a != NULL)
	{
		int r;

		for (r = R_GEN; r < R_NUM; r++) /* Is it in reg? */
		{
			if (rdesc[r].var == a)
				break;
		}

		if (r < R_NUM)
			out_str(file_s, "	TST R%u\n", r);
		else
			out_str(file_s, "	TST R%u\n", reg_alloc(a)); /* Load into new register */
	}

	out_str(file_s, "	%s %s\n", op, l);
}

static int ret_label_id = 1000; // 函数label

void asm_call(SYM *a, SYM *b) // a:返回值变量；b：函数名
{
	int r;
	for (int r = R_GEN; r < R_NUM; r++)
		asm_write_back(r);
	for (int r = R_GEN; r < R_NUM; r++)
		rdesc_clear(r);

	char ret_label[32];
	sprintf(ret_label, "L%d", ret_label_id++); // 跳转回的LABEL

	out_str(file_s, "	STO (R2+%d),R2\n", tof + oon);
	oon += 4;
	out_str(file_s, "	LOD R4,%s\n", ret_label);
	out_str(file_s, "	STO (R2+%d),R4\n", tof + oon);
	oon += 4;
	out_str(file_s, "	LOD R2,R2+%d\n", tof + oon - 8);
	out_str(file_s, "	JMP %s\n", b->name);
	// 返回点
	out_str(file_s, "%s:\n", ret_label);

	// 取返回值，R15保存
	if (a != NULL)
	{
		int ra = reg_alloc(a);
		out_str(file_s, "	LOD R%u,R15\n", ra);
		rdesc[ra].mod = MODIFIED;
	}
	oon = 0;
}

void asm_return(SYM *a)
{
	for (int r = R_GEN; r < R_NUM; r++)
		asm_write_back(r);
	for (int r = R_GEN; r < R_NUM; r++)
		rdesc_clear(r);

	if (a != NULL) /* return value */
	{
		int ra = reg_alloc(a);
		out_str(file_s, "    LOD R15,R%u\n", ra);
	}

	out_str(file_s, "	LOD R3,(R2+4)\n"); /* return address */
	out_str(file_s, "	LOD R2,(R2)\n");   /* restore bp */
	out_str(file_s, "	JMP R3\n");		   /* return */
}

void asm_head()
{
	char head[] =
		"	# head\n"
		"	LOD R2,STACK\n"
		"	STO (R2),0\n"
		"	LOD R4,EXIT\n"
		"	STO (R2+4),R4\n";

	out_str(file_s, "%s", head);
}

void asm_tail()
{
	char tail[] =
		"\n	# tail\n"
		"EXIT:\n"
		"	END\n";

	out_str(file_s, "%s", tail);
}

void asm_str(SYM *s)
{
	char *t = s->name; /* The text */
	int i;

	out_str(file_s, "L%u:\n", s->label); /* Label for the string */
	out_str(file_s, "	DBS ");			 /* Label for the string */

	for (i = 1; t[i + 1] != 0; i++)
	{
		if (t[i] == '\\')
		{
			switch (t[++i])
			{
			case 'n':
				out_str(file_s, "%u,", '\n');
				break;

			case '\"':
				out_str(file_s, "%u,", '\"');
				break;
			}
		}
		else
			out_str(file_s, "%u,", t[i]);
	}

	out_str(file_s, "0\n"); /* End of string */
}

void asm_static(void)
{
	int i;

	SYM *sl;

	for (sl = sym_tab_global; sl != NULL; sl = sl->next)
	{
		if (sl->type == SYM_TEXT)
			asm_str(sl);
	}

	out_str(file_s, "STATIC:\n");
	out_str(file_s, "	DBN 0,%u\n", tos);
	out_str(file_s, "STACK:\n");
}

static void asm_load_addr(int r, SYM *s) // 把 &s 放到寄存器 r
{
	switch (s->type)
	{
	case SYM_VAR:
	case SYM_ARRAY:
		if (s->scope == 1)
		{
			// 局部变量：地址 = R_BP + offset
			if (s->offset >= 0)
				out_str(file_s, "    LOD R%u,R%u+%d\n", r, R_BP, s->offset);
			else
				out_str(file_s, "    LOD R%u,R%u-%d\n", r, R_BP, -s->offset);
		}
		else
		{
			// 全局变量：地址 = STATIC + offset
			out_str(file_s, "    LOD R4,STATIC\n");
			out_str(file_s, "    LOD R%u,R4+%d\n", r, s->offset);
		}
		break;

	default:
		break;
	}
}

void asm_code(TAC *c)
{
	int r;

	switch (c->op)
	{
	case TAC_UNDEF:
		error("cannot translate TAC_UNDEF");
		return;

	case TAC_ADD:
		asm_bin("ADD", c->a, c->b, c->c);
		return;

	case TAC_SUB:
		asm_bin("SUB", c->a, c->b, c->c);
		return;

	case TAC_MUL:
		asm_bin("MUL", c->a, c->b, c->c);
		return;

	case TAC_DIV:
		asm_bin("DIV", c->a, c->b, c->c);
		return;

	case TAC_NEG:
		asm_bin("SUB", c->a, mk_const(0), c->b);
		return;

	case TAC_EQ:
	case TAC_NE:
	case TAC_LT:
	case TAC_LE:
	case TAC_GT:
	case TAC_GE:
		asm_cmp(c->op, c->a, c->b, c->c);
		return;

	case TAC_COPY:
	{
		int rb = reg_alloc(c->b);

		// 左值是变量
		if (c->a->type == SYM_VAR)
		{
			if (c->a->scope == 1)
			{
				// 局部变量
				// out_str(file_s, "	STO (R%u+%d),R%u\n", R_BP, c->a->offset, rb);
				if (c->a->offset >= 0)
					out_str(file_s, "   STO (R%u+%d),R%u\n", R_BP, c->a->offset, rb);
				else
					out_str(file_s, "   STO (R%u-%d),R%u\n", R_BP, -c->a->offset, rb);
			}
			else
			{
				// 全局变量
				out_str(file_s, "	LOD R4,STATIC\n");
				out_str(file_s, "	STO (R4+%d),R%u\n", c->a->offset, rb);
			}
		}
		else
		{
			// 临时变量或寄存器变量
			int ra = reg_alloc(c->a);
			out_str(file_s, "	LOD R%u,R%u\n", ra, rb);
		}

		rdesc_fill(rb, c->a, UNMODIFIED);
		return;
	}

	case TAC_INPUT:
		r = reg_alloc(c->a);
		int t = SYM_INT;
		if (c->a && c->a->etc)
			t = *((int *)c->a->etc);
		if (t == SYM_CHAR)
			out_str(file_s, "	ITC\n");
		else
			out_str(file_s, "	ITI\n");
		out_str(file_s, "	LOD R%u,R15\n", r);
		rdesc[r].mod = MODIFIED;
		return;

	case TAC_OUTPUT:
		if (c->a->type == SYM_VAR)
		{
			r = reg_alloc(c->a);
			int real_type = SYM_INT;
			if (c->a && c->a->etc)
			{
				real_type = *((int *)c->a->etc);
				// printf("%d", real_type);
			}
			// if (real_type != SYM_PTR)
			// 	out_str(file_s, "	LOD R15,R%u\n", r);
			// else
			if (c->a->scope == 1)
			{
				// 局部变量
				// out_str(file_s, "	LOD R15,(R%u+%d)\n", R_BP, c->a->offset);
				if (c->a->offset >= 0)
					out_str(file_s, "    LOD R15,(R%u+%d)\n", R_BP, c->a->offset);
				else
					out_str(file_s, "    LOD R15,(R%u-%d)\n", R_BP, -c->a->offset);
			}
			else
			{
				// 全局变量：从 STATIC 段取
				out_str(file_s, "	LOD R4,STATIC\n");
				out_str(file_s, "	LOD R15,(R4+%d)\n", c->a->offset);
			}

			if (real_type == SYM_CHAR)
				out_str(file_s, "	OTC\n");
			else
				out_str(file_s, "	OTI\n");
		}
		else if (c->a->type == SYM_TEXT)
		{
			r = reg_alloc(c->a);
			out_str(file_s, "	LOD R15,R%u\n", r);
			out_str(file_s, "	OTS\n");
		}
		return;

	case TAC_VARARRAY:
	{
		int elem_type = SYM_INT;
		if (c->a->etc)
			elem_type = *((int *)c->a->etc);

		int elem_size = (elem_type == SYM_CHAR) ? 1 : 4;

		int total_elems = 1;
		for (int i = 0; i < c->a->ndim; i++)
			total_elems *= c->a->dims[i];

		int total_size = total_elems * elem_size;

		if (scope)
		{
			c->a->scope = 1;
			c->a->offset = tof;
			tof += total_size;
		}
		else
		{
			c->a->scope = 0;
			c->a->offset = tos;
			tos += total_size;
		}

		out_str(file_s, "	# declare array %s [%d", c->a->name, c->a->dims[0]);
		for (int i = 1; i < c->a->ndim; i++)
			out_str(file_s, "][%d", c->a->dims[i]);
		out_str(file_s, "] elem=%s size=%d bytes\n",
				(elem_type == SYM_CHAR ? "char(1B)" : "int(4B)"), total_size);
		return;
	}

	case TAC_LOADIDX:
		int base_load = reg_alloc_temp();
		int offset_load = reg_alloc(c->c);
		int ra = reg_alloc(c->a);

		if (base_load == offset_load)
		{
			int new_off = reg_alloc_temp();
			out_str(file_s, "	LOD R%u, R%u\n", new_off, offset_load);
			offset_load = new_off;
		}

		if (base_load == ra)
		{
			int new_val = reg_alloc_temp();
			out_str(file_s, "	LOD R%u, R%u\n", new_val, ra);
			ra = new_val;
		}

		if (offset_load == ra)
		{
			int new_val = reg_alloc_temp();
			out_str(file_s, "	LOD R%u,R%u\n", new_val, ra);
			ra = new_val;
		}
		asm_load_addr(base_load, c->b);

		out_str(file_s, "	ADD R%u,R%u\n", base_load, offset_load);
		out_str(file_s, "	LOD R%u,(R%u)\n", ra, base_load);

		rdesc_fill(ra, c->a, MODIFIED);
		rdesc_clear(base_load);
		return;

	case TAC_STOREIDX:
		int base_store = reg_alloc_temp();
		int offset_store = reg_alloc(c->b);
		int rval = reg_alloc(c->c);

		if (base_store == offset_store)
		{
			int new_off = reg_alloc_temp();
			out_str(file_s, "	LOD R%u, R%u\n", new_off, offset_store);
			offset_store = new_off;
		}

		if (base_store == rval)
		{
			int new_val = reg_alloc_temp();
			out_str(file_s, "	LOD R%u, R%u\n", new_val, rval);
			rval = new_val;
		}

		if (offset_store == rval)
		{
			int new_val = reg_alloc_temp();
			out_str(file_s, "	LOD R%u,R%u\n", new_val, rval);
			rval = new_val;
		}

		asm_load_addr(base_store, c->a);

		out_str(file_s, "	ADD R%u,R%u\n", base_store, offset_store);
		out_str(file_s, "	STO (R%u),R%u\n", base_store, rval);
		rdesc_clear(base_store);
		return;

	case TAC_ADDR:
	{
		// a = &b
		int r = reg_alloc(c->a);
		if (c->b->scope == 1)
			// out_str(file_s, "    LOD R%u,R%u+%d\n", r, R_BP, c->b->offset);
			if (c->b->offset >= 0)
				out_str(file_s, "    LOD R%u,R%u+%d\n", r, R_BP, c->b->offset);
			else
				out_str(file_s, "    LOD R%u,R%u-%d\n", r, R_BP, -c->b->offset);

		else
			out_str(file_s, "    LOD R%u,STATIC+%d\n", r, c->b->offset);
		rdesc_fill(r, c->a, MODIFIED);
		return;
	}

	case TAC_LOAD:
	{
		// a = *b
		int rb = reg_alloc(c->b);
		int ra = reg_alloc(c->a);
		// out_str(file_s, "    LOD R%u,(R%u)\n", ra, rb);

		int elem_type = SYM_INT;
		if (c->a->etc)
			elem_type = *((int *)c->a->etc);

		out_str(file_s, "    LOD R%u,(R%u)\n", ra, rb);

		rdesc_fill(ra, c->a, MODIFIED);
		return;
	}

	case TAC_LOADC:
	{
		int ra = reg_alloc(c->a);
		int rb = reg_alloc(c->b);
		out_str(file_s, "    LDC R%u,(R%u)\n", ra, rb);
		return;
	}

	case TAC_STORE:
	{
		// *a = b
		int ra = reg_alloc(c->a);
		int rb = reg_alloc(c->b);

		if (c->a->offset >= 0)
			out_str(file_s, "    LOD R%u,(R%u+%d)\n", ra, R_BP, c->a->offset);
		else
			out_str(file_s, "    LOD R%u,(R%u-%d)\n", ra, R_BP, -c->a->offset);

		out_str(file_s, "    STO (R%u),R%u\n", ra, rb);

		return;
	}

	case TAC_STOREC:
	{
		int ra = reg_alloc(c->a);
		int rb = reg_alloc(c->b);

		if (c->a->offset >= 0)
			out_str(file_s, "    LOD R%u,(R%u+%d)\n", ra, R_BP, c->a->offset);
		else
			out_str(file_s, "    LOD R%u,(R%u-%d)\n", ra, R_BP, -c->a->offset);

		out_str(file_s, "    STC (R%u),R%u\n", ra, rb);

		return;
	}

	case TAC_GOTO:
		asm_cond("JMP", NULL, c->a->name);
		return;

	case TAC_IFZ:
		asm_cond("JEZ", c->b, c->a->name);
		return;

	case TAC_LABEL:
		for (int r = R_GEN; r < R_NUM; r++)
			asm_write_back(r);
		for (int r = R_GEN; r < R_NUM; r++)
			rdesc_clear(r);
		out_str(file_s, "%s:\n", c->a->name);
		return;

	case TAC_ACTUAL:
		r = reg_alloc(c->a);
		out_str(file_s, "	STO (R2+%d),R%u\n", tof + oon, r);
		oon += 4;
		return;

	case TAC_CALL:
		asm_call(c->a, c->b);
		return;

	case TAC_BEGINFUNC:
		/* We reset the top of stack, since it is currently empty apart from the link information. */
		scope = 1;
		tof = LOCAL_OFF;
		oof = FORMAL_OFF;
		oon = 0;
		// tmpoff = -4;
		return;

	case TAC_FORMAL:
		c->a->scope = 1; /* parameter is special local var */
		c->a->offset = oof;
		oof -= 4;
		return;

	case TAC_VAR:
		// if (c->a->name[0] == 't')
		// {
		// 	c->a->scope = 1;
		// 	c->a->offset = tmpoff;
		// 	tmpoff -= 4;
		// 	return;
		// }
		if (scope)
		{
			c->a->scope = 1; /* local var */
			c->a->offset = tof;
			tof += 4;
		}
		else
		{
			c->a->scope = 0; /* global var */
			c->a->offset = tos;
			tos += 4;
		}
		return;

	case TAC_RETURN:
		asm_return(c->a);
		return;

	case TAC_ENDFUNC:
		asm_return(NULL);
		scope = 0;
		return;

	default:
		/* Don't know what this one is */
		error("unknown TAC opcode to translate");
		return;
	}
}

void tac_obj()
{
	tof = LOCAL_OFF; /* TOS allows space for link info */
	oof = FORMAL_OFF;
	oon = 0;

	for (int r = 0; r < R_NUM; r++)
		rdesc[r].var = NULL;

	asm_head();

	TAC *cur;
	for (cur = tac_first; cur != NULL; cur = cur->next)
	{
		out_str(file_s, "\n	# ");
		out_tac(file_s, cur);
		out_str(file_s, "\n");
		// if (cur->a && cur->a->etc)
		// 	printf("asm_code %d", *((int *)cur->a->etc));
		asm_code(cur);
	}
	asm_tail();
	asm_static();
}
