/* type of symbol */
#define SYM_UNDEF 0
#define SYM_VAR 1
#define SYM_FUNC 2
#define SYM_TEXT 3
#define SYM_INT 4
#define SYM_LABEL 5
#define SYM_CHAR 6
#define SYM_PTR 7
#define SYM_ARRAY 8
#define SYM_STRUCT 9

/* type of tac */
#define TAC_UNDEF 0		 /* undefine */
#define TAC_ADD 1		 /* a=b+c */
#define TAC_SUB 2		 /* a=b-c */
#define TAC_MUL 3		 /* a=b*c */
#define TAC_DIV 4		 /* a=b/c */
#define TAC_EQ 5		 /* a=(b==c) */
#define TAC_NE 6		 /* a=(b!=c) */
#define TAC_LT 7		 /* a=(b<c) */
#define TAC_LE 8		 /* a=(b<=c) */
#define TAC_GT 9		 /* a=(b>c) */
#define TAC_GE 10		 /* a=(b>=c) */
#define TAC_NEG 11		 /* a=-b */
#define TAC_COPY 12		 /* a=b */
#define TAC_GOTO 13		 /* goto a */
#define TAC_IFZ 14		 /* ifz b goto a */
#define TAC_BEGINFUNC 15 /* function begin */
#define TAC_ENDFUNC 16	 /* function end */
#define TAC_LABEL 17	 /* label a */
#define TAC_VAR 18		 /* int a */
#define TAC_FORMAL 19	 /* formal a */
#define TAC_ACTUAL 20	 /* actual a */
#define TAC_CALL 21		 /* a=call b */
#define TAC_RETURN 22	 /* return a */
#define TAC_INPUT 23	 /* input a */
#define TAC_OUTPUT 24	 /* output a */
#define TAC_ADDR 25		 /* t = &a */
#define TAC_LOAD 26		 /* t = *a */
#define TAC_STORE 27	 /* *t = a */
#define TAC_CASE 28
#define TAC_VARARRAY 29
#define TAC_LOADIDX 30
#define TAC_STOREIDX 31

typedef struct sym
{
	/*
		type:SYM_VAR name:abc value:98 offset:-1
		type:SYM_VAR name:bcd value:99 offset:4
		type:SYM_LABEL name:L1/max
		type:SYM_INT value:1
		type:SYM_FUNC name:max address:1234
		type:SYM_TEXT name:"hello" label:10
	*/
	int type;
	int scope; /* 0:global, 1:local */
	char *name;
	int offset;
	int value;
	int label;
	struct tac *address; /* SYM_FUNC */
	struct sym *next;
	int ndim;  // 数组维度数
	int *dims; // 每个维度的长度
	void *etc;
} SYM;

typedef struct tac
{
	struct tac *next;
	struct tac *prev;
	int op;
	SYM *a;
	SYM *b;
	SYM *c;
	void *etc;
} TAC;

typedef struct exp
{
	struct exp *next; /* for argument list */
	TAC *tac;		  /* code */
	SYM *ret;		  /* return value */
	void *etc;
} EXP;

typedef struct basic_block
{
	int id;
	TAC *first;				   // 第1条tac
	TAC *last;				   // 最后1条tac
	struct basic_block **succ; // 后继块数组
	struct basic_block **pred; // 前驱块数组
	int succ_count;
	int pred_count;
	struct basic_block *next;
	int mark;
} BASIC_BLOCK;

typedef struct STRUCT_MEMBER
{
	char *name;
	int offset;
	int type;
	void *etc;
	struct STRUCT_MEMBER *next;
} STRUCT_MEMBER;

typedef struct STRUCT
{
	char *name;
	STRUCT_MEMBER *members;
	int size;
	struct STRUCT *next;
} STRUCT;

/* global var */
extern FILE *file_x, *file_s;
extern int yylineno, scope, next_tmp, next_label;
extern SYM *sym_tab_global, *sym_tab_local;
extern TAC *tac_first, *tac_last;
extern BASIC_BLOCK *bb_list; // 所有基本块链表

/* function */
void tac_init();
void tac_complete();
TAC *join_tac(TAC *c1, TAC *c2);
void out_str(FILE *f, const char *format, ...);
void out_sym(FILE *f, SYM *s);
void out_tac(FILE *f, TAC *i);
SYM *mk_var(char *name);
SYM *mk_label(char *name);
SYM *mk_tmp(void);
SYM *mk_const(int n);
SYM *mk_char(int c);
SYM *mk_text(char *text);
TAC *mk_tac(int op, SYM *a, SYM *b, SYM *c);
EXP *mk_exp(EXP *next, SYM *ret, TAC *code);
SYM *mk_sym(void);
char *mk_lstr(int i);
SYM *get_var(char *name);
SYM *declare_func(char *name);
TAC *declare_var(char *name);
TAC *declare_var_typed(const char *name, int sym_type);
TAC *declare_para(char *name);
TAC *do_func(SYM *name, TAC *args, TAC *code);
TAC *do_assign(SYM *var, EXP *exp);
TAC *do_output(SYM *var);
TAC *do_input(SYM *var);
TAC *do_call(char *name, EXP *arglist);
TAC *do_if(EXP *exp, TAC *stmt);
TAC *do_test(EXP *exp, TAC *stmt1, TAC *stmt2);
TAC *do_while(EXP *cond, TAC *body, SYM *start_sym, SYM *cont_sym, SYM *end_sym);
TAC *do_break();
TAC *do_continue();
TAC *do_switch(EXP *expr, TAC *cases, TAC *def, SYM *end_label);
TAC *do_case(int value, TAC *body);

TAC *do_for(TAC *init, EXP *cond, TAC *step, TAC *body,
			SYM *start_sym, SYM *cont_sym, SYM *end_sym);
void push_loop_labels(SYM *cont, SYM *end);
void pop_loop_labels(void);
SYM *get_break_label(void);
SYM *get_continue_label(void);

TAC *declare_array_typed(const char *name, int type, EXP *dims);
static EXP *cal_array_offset(SYM *arr, EXP *idxs);
EXP *do_array_load(SYM *arr, EXP *idxs);
TAC *do_array_store(SYM *arr, EXP *idxs, EXP *val);

EXP *do_bin(int binop, EXP *exp1, EXP *exp2);
EXP *do_cmp(int binop, EXP *exp1, EXP *exp2);
EXP *do_un(int unop, EXP *exp);
EXP *do_call_ret(char *name, EXP *arglist);

STRUCT *begin_struct(const char *name);
TAC *declare_struct(const char *var_name, const char *struct_name);
void add_struct_member(STRUCT *unused, int member_type, const char *mname, int size);
void add_struct_struct_member(SYM *cur, SYM *struct_type, char *name, int cnt);
void add_struct_array_member(SYM *cur, int base_type, char *name, int cnt);
void end_struct(STRUCT *def);
static STRUCT *get_struct_var(SYM *var);
int get_struct_offset(SYM *struct_var, const char *name);
TAC *make_struct_store_tac(SYM *base, int offset, EXP *exp);
EXP *make_struct_load_exp(SYM *base, int offset);
STRUCT *find_struct(const char *name);
EXP *make_struct_field_addr(EXP *base, int offset);
EXP *make_array_elem_addr(EXP *base, EXP *index);
TAC *do_assign_lvalue(EXP *lv, EXP *rhs);
EXP *do_load_lvalue(EXP *lv);
STRUCT_MEMBER *get_struct_member(SYM *struct_var, const char *name);

void error(const char *format, ...);
