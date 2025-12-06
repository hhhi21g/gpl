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

void rdesc_clear_all()
{
	for (int r = R_GEN; r < R_NUM; r++)
	{
		rdesc_clear(r);
	}
}

static int is_temp_name(const char *name)
{
	if (!name)
		return 0;
	if (name[0] != 't')
		return 0;						  // 以 't' 开头
	if (!isdigit((unsigned char)name[1])) // 后面必须是数字
		return 0;

	// 检查剩余字符是否全是数字
	for (int i = 2; name[i]; i++)
	{
		if (!isdigit((unsigned char)name[i]))
			return 0;
	}
	return 1; // 形如 t0, t1, t23 ...
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
			// out_str(file_s, "	LOD R%u,STATIC\n", R_TP);
			out_str(file_s, "	STO (R%u+%u),R%u\n", R_TP, rdesc[r].var->offset, r);
		}
		rdesc[r].mod = UNMODIFIED;
	}
}

void asm_load(int r, SYM *s)
{
	// /* already in a reg */
	// for (int i = R_GEN; i < R_NUM; i++)
	// {
	// 	if (rdesc[i].var == s)
	// 	{
	// 		/* load from the reg */
	// 		out_str(file_s, "	LOD R%u,R%u\n", r, i);

	// 		/* update rdesc */
	// 		// rdesc_fill(r, s, rdesc[i].mod);
	// 		return;
	// 	}
	// }

	for (int i = R_GEN; i < R_NUM; i++)
	{
		if (rdesc[i].var == s)
		{
			// s 已经在寄存器 i 中
			// 如果 i != r，则复制寄存器即可，不用访问内存
			if (i != r)
				out_str(file_s, "    LOD R%u,R%u\n", r, i);

			// 更新寄存器描述符：现在 r 也保存 s 的值
			rdesc_fill(r, s, rdesc[i].mod);

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
			// out_str(file_s, "	LOD R%u,STATIC\n", R_TP);
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

	// 如果无空位，就随机选一个但不要写入 rdesc
	return R_GEN;
}

static int next_temp = R_GEN;

static int alloc_clean_temp_reg(int forbid1, int forbid2)
{
	for (int i = 0; i < (R_NUM - R_GEN); i++)
	{
		// 环形扫描，避免每次都从R_GEN开始，而是平均利用各个寄存器
		int r = R_GEN + (next_temp - R_GEN + i) % (R_NUM - R_GEN);

		// 不向传入的需要避免的寄存器内分配
		if (r == forbid1 || r == forbid2)
			continue;

		if (rdesc[r].var == NULL)
		{
			next_temp = r + 1;

			rdesc_clear(r); // 保证干净
			return r;
		}
	}

	// 若没有空寄存器，使用next_temp
	int r = R_GEN + (next_temp - R_GEN) % (R_NUM - R_GEN);
	next_temp++;

	// 若当前寄存器绑定某变量且被修改过
	if (rdesc[r].var && rdesc[r].mod)
		asm_write_back(r);

	rdesc_clear(r);
	return r;
}

void asm_bin(char *op, SYM *a, SYM *b, SYM *c)
{
	int reg_b = reg_alloc(b);
	int reg_c = reg_alloc(c);

	if (reg_b == reg_c)
	{
		// 避免给c分配b所在的寄存器
		int tmp = alloc_clean_temp_reg(reg_b, -1);
		out_str(file_s, "    LOD R%u,R%u\n", tmp, reg_b);
		reg_c = tmp;
	}

	out_str(file_s, "    %s R%u,R%u\n", op, reg_b, reg_c);

	// 结果放在reg_b，对应a
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

	out_str(file_s, "	STO (R2+%d),R2\n", tof + oon); /* store old bp */
	oon += 4;
	out_str(file_s, "	LOD R4,%s\n", ret_label);	   /* return addr: 4*8=32 */
	out_str(file_s, "	STO (R2+%d),R4\n", tof + oon); /* store return addr */
	oon += 4;
	out_str(file_s, "	LOD R2,R2+%d\n", tof + oon - 8); /* load new bp */
	out_str(file_s, "	JMP %s\n", b->name);			 /* jump to new func */

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

int is_cmp(int op)
{
	return op == TAC_LT || op == TAC_LE ||
		   op == TAC_GT || op == TAC_GE ||
		   op == TAC_EQ || op == TAC_NE;
}

int is_zero_const(SYM *s)
{
	if (!s)
		return 0;
	if (s->type != SYM_INT && s->type != SYM_CHAR)
		return 0;
	return s->value == 0;
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

	out_str(file_s, "	LOD R%u,STATIC\n", R_TP);
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
	// out_str(file_s, "    DBN 0,4096\n");
	out_str(file_s, "STACK:\n");
	// out_str(file_s, "    DBN 0,8192\n");
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
		// a = a
		if (c->a == c->b)
		{
			return; // 不生成任何指令
		}

		SYM *dst = c->a;
		SYM *src = c->b; // 原寄存器，需要被继承

		int rs = -1;

		for (int i = R_GEN; i < R_NUM; i++)
		{
			if (rdesc[i].var == src)
			{
				rs = i;
				// printf("rdesc[%d].var = %d\n", i, rdesc[i].var->value);
				break;
			}
		}

		if (rs < 0)
			rs = reg_alloc(src);

		// 左值是变量
		if (c->a->type == SYM_VAR)
		{
			if (c->a->scope == 1)
			{
				// 局部变量
				// out_str(file_s, "	STO (R%u+%d),R%u\n", R_BP, c->a->offset, rb);
				if (c->a->offset >= 0)
					out_str(file_s, "	STO (R%u+%d),R%u\n", R_BP, c->a->offset, rs);
				else
					out_str(file_s, "	STO (R%u-%d),R%u\n", R_BP, -c->a->offset, rs);
			}
			else
			{
				// 全局变量
				out_str(file_s, "	LOD R4,STATIC\n");
				out_str(file_s, "	STO (R4+%d),R%u\n", c->a->offset, rs);
			}
			if (!(c->b->type == SYM_TMP)) // src 不是临时变量
			{
				rdesc_fill(rs, dst, MODIFIED);
			}
			return;
		}
		else
		{
			// 临时变量或寄存器变量
			int ra = reg_alloc(c->a);
			out_str(file_s, "	LOD R%u,R%u\n", ra, rs);
			rdesc_fill(ra, c->a, UNMODIFIED);
		}

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
	{
		SYM *s = c->a;

		if (s->type == SYM_TEXT)
		{
			int r = reg_alloc(s);
			out_str(file_s, "    LOD R15,R%u\n", r);
			out_str(file_s, "    OTS\n");
			return;
		}

		int r = reg_alloc(s);

		out_str(file_s, "    LOD R15,R%u\n", r);

		int real_type = SYM_INT;
		if (s->etc)
			real_type = *((int *)s->etc);

		if (real_type == SYM_CHAR)
			out_str(file_s, "    OTC\n");
		else
			out_str(file_s, "    OTI\n");

		return;
	}

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

		if (c->a->type == SYM_TMP)
		{
			c->a->type = SYM_VAR;
		}
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

static void asm_cmp_ifz_zero(TAC *cmp, TAC *br)
{
	SYM *t = cmp->a;   // 比较运算布尔值
	SYM *lhs = cmp->b; // 左操作数
	SYM *rhs = cmp->c; // 右操作数
	SYM *lab = br->a;  // 跳转目标label

	// 暂只处理x > 0初步尝试
	if (cmp->op != TAC_GT)
		return;

	int rx = reg_alloc(lhs);

	out_str(file_s, "    TST R%u\n", rx);
	out_str(file_s, "    JEZ %s\n", lab->name);
	out_str(file_s, "    JLZ %s\n", lab->name);
}

static void asm_cmp_ifz_general(TAC *cmp, TAC *br)
{
	SYM *lhs = cmp->b;
	SYM *rhs = cmp->c;
	SYM *lab = br->a;

	// rhs 是常数
	if (!(rhs->type == SYM_INT || rhs->type == SYM_CHAR))
		return;

	// lhs - rhs与0比较得到条件
	int r_lhs = reg_alloc(lhs);

	// 寄存器rt
	int rt = alloc_clean_temp_reg(-1, -1);

	out_str(file_s, "    LOD R%u,R%u\n", rt, r_lhs);
	out_str(file_s, "	LOD R3,%d\n", rhs->value);
	out_str(file_s, "    SUB R%u,R3\n", rt);
	out_str(file_s, "    TST R%u\n", rt);

	switch (cmp->op)
	{
	case TAC_GT:
		// fail = R <= 0
		out_str(file_s, "    JEZ %s\n", lab->name);
		out_str(file_s, "    JLZ %s\n", lab->name);
		break;

	case TAC_GE:
		// fail = R < 0
		out_str(file_s, "    JLZ %s\n", lab->name);
		break;

	case TAC_LT:
		// fail = R >= 0
		out_str(file_s, "    JEZ %s\n", lab->name);
		out_str(file_s, "    JGZ %s\n", lab->name);
		break;

	case TAC_LE:
		// fail = R > 0
		out_str(file_s, "    JGZ %s\n", lab->name);
		break;

	case TAC_EQ:
		// fail = R != 0
		out_str(file_s, "    JLZ %s\n", lab->name);
		out_str(file_s, "    JGZ %s\n", lab->name);
		break;

	case TAC_NE:
		// fail = R == 0
		out_str(file_s, "    JEZ %s\n", lab->name);
		break;

	default:
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
	for (cur = tac_first; cur != NULL;)
	{
		out_str(file_s, "\n	# ");
		out_tac(file_s, cur);
		out_str(file_s, "\n");

		if (is_cmp(cur->op) && cur->op == TAC_GT && cur->a && cur->next &&
			cur->next->op == TAC_IFZ &&
			cur->next->b == cur->a && // ifz 使用比较产生的临时 t
			is_zero_const(cur->c))	  // x > 0形式
		{
			asm_cmp_ifz_zero(cur, cur->next); // 生成优化后的汇编
			cur = cur->next->next;			  // 跳过比较 + ifz两条 TAC
			continue;
		}

		if (is_cmp(cur->op) &&
			cur->next &&
			cur->next->op == TAC_IFZ &&
			cur->next->b == cur->a)
		{
			asm_cmp_ifz_general(cur, cur->next);
			cur = cur->next->next;
			continue;
		}
		asm_code(cur);
		cur = cur->next;
	}
	asm_tail();
	asm_static();
}
