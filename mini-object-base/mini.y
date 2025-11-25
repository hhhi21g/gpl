%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tac.h"

int yylex();
void yyerror(char* msg);

static SYM *g_for_start = NULL;
static SYM *g_for_cont  = NULL;
static SYM *g_for_end   = NULL;
static SYM *g_switch_end = NULL;

static char *g_cur_struct = NULL;

#define LOOP_MAX_DEPTH 100

static SYM *g_for_start_stack[LOOP_MAX_DEPTH];
static SYM *g_for_cont_stack[LOOP_MAX_DEPTH];
static SYM *g_for_end_stack[LOOP_MAX_DEPTH];
static int g_for_depth = 0;


PATH *append_path_list(PATH *head, PATH *tail);


%}

%union
{
	char character;
	char *string;
	SYM *sym;
	TAC *tac;
	EXP	*exp;
	// PATH *path;
	LVALUE_PATH *lvalue_path;
}

%token INT EQ NE LT LE GT GE UMINUS STRUCT_TOK PTR_OP IF ELSE SWITCH CASE DEFAULT WHILE FOR BREAK CONTINUE FUNC INPUT OUTPUT RETURN
%token <string> INTEGER IDENTIFIER TEXT CHAR CHAR_CONST LBRACK RBRACK 

%left EQ NE LT LE GT GE
%left '+' '-'
%left '*' '/'
%right UMINUS

%type <tac> program function_declaration_list function_declaration function parameter_list variable_list statement assignment_statement return_statement if_statement switch_statement case_list case_item default_list while_statement for_statement break_statement continue_statement opt_statement call_statement block declaration_list declaration statement_list input_statement output_statement 
%type <tac> variable_list_char decl_item_char decl_item_int struct_definition struct_member_list struct_member_line struct_var_list
%type <exp> argument_list expression_list expression call_expression  opt_expression dims_decl dims_idx
%type <sym> function_head
%type <lvalue_path> lvalue_path lvalue_tail lvalue_tail_opt

%%

program : function_declaration_list
{
	tac_last=$1;
	tac_complete();
}
;


function_declaration_list : function_declaration
| function_declaration_list function_declaration
{
	$$=join_tac($1, $2);
}
;

function_declaration : function
| declaration
| struct_definition;
;

dims_decl:LBRACK INTEGER RBRACK
{
	$$=mk_exp(NULL,mk_const(atoi($2)),NULL);
}
| dims_decl LBRACK INTEGER RBRACK
{
	EXP *node = mk_exp(NULL,mk_const(atoi($3)),NULL);
	node->next = $1;
	$$ = node;
}
;

dims_idx:LBRACK expression RBRACK
{
	$$ = mk_exp(NULL,$2->ret,$2->tac);
}
| dims_idx LBRACK expression RBRACK
{
	EXP*node = mk_exp(NULL,$3->ret,$3->tac);
	node->next = $1;
	$$ = node;
}
;

declaration : INT variable_list ';'
{
	$$=$2;
}
| CHAR variable_list_char ';'
{
	$$=$2;
}
| STRUCT_TOK IDENTIFIER {g_cur_struct = $2;} struct_var_list ';'
{
	$$ = $4;
	g_cur_struct = NULL;
}
;

struct_var_list: IDENTIFIER
{ 
	$$ = declare_struct($1, g_cur_struct); 
}
| IDENTIFIER dims_decl
{
	$$ = declare_array_typed($1,SYM_STRUCT,$2);
	SYM*sym = get_var($1);
	sym->etc2 = find_struct(g_cur_struct);
}
| struct_var_list ',' IDENTIFIER
{ 
	$$ = join_tac($1, declare_struct($3, g_cur_struct)); 
}
| struct_var_list ',' IDENTIFIER dims_decl{
	$$ = declare_array_typed($3,SYM_STRUCT,$4);
	SYM*sym = get_var($3);
	sym->etc2 = find_struct(g_cur_struct);
}
;


struct_definition: STRUCT_TOK IDENTIFIER
{
	begin_struct($2);
}
'{' struct_member_list'}' ';'
{
	end_struct(NULL);
	$$ = NULL;
}
;

struct_member_list:
{
	 $$ = NULL;
}
| struct_member_list struct_member_line
{
	$$ = join_tac($1,$2);
}
;

struct_member_line:INT IDENTIFIER ';'
{
	add_struct_member(NULL,SYM_INT,$2);
	$$ = NULL;
}
| CHAR IDENTIFIER ';'
{ 
	add_struct_member(NULL, SYM_CHAR, $2); 
	$$ = NULL; 
}
| INT '*' IDENTIFIER ';'
{
	add_struct_member(NULL,SYM_PTR,$3);
}
| CHAR '*' IDENTIFIER ';'
{
	add_struct_member(NULL,SYM_PTR,$3);
}
| INT IDENTIFIER LBRACK INTEGER RBRACK ';'
{
	add_struct_member_array(NULL,SYM_INT,$2,atoi($4));
	$$ = NULL;
}
| CHAR IDENTIFIER LBRACK INTEGER RBRACK ';'
{
	add_struct_member_array(NULL,SYM_CHAR,$2,atoi($4));
	$$ = NULL;
}
| STRUCT_TOK IDENTIFIER IDENTIFIER ';'
{
	add_struct_member_struct($2,$3);
	$$ = NULL;
}
| STRUCT_TOK IDENTIFIER IDENTIFIER LBRACK INTEGER RBRACK ';'
{
	add_struct_member_struct_array($2,$3,atoi($5));
	$$ = NULL;
}
;

variable_list: decl_item_int
| variable_list ',' decl_item_int
{ 
	$$ = join_tac($1, $3); 
}
;

decl_item_int: IDENTIFIER
{ 
	$$ = declare_var_typed($1, SYM_INT); 
}
| '*' IDENTIFIER
{ 
	$$ = declare_var_typed($2, SYM_PTR); 
}
| IDENTIFIER dims_decl
{
	$$ = declare_array_typed($1,SYM_INT,$2);
}
;


variable_list_char: decl_item_char
| variable_list_char ',' decl_item_char
{ 
	$$ = join_tac($1, $3); 
}
;

decl_item_char: IDENTIFIER
{ 
	$$ = declare_var_typed($1, SYM_CHAR); 
}
| '*' IDENTIFIER
{ 
	$$ = declare_var_typed($2, SYM_PTR); 
}
| IDENTIFIER dims_decl
{
	$$ = declare_array_typed($1,SYM_CHAR,$2);
}
;



function : function_head '(' parameter_list ')' block
{
	$$=do_func($1, $3, $5);
	scope=0; /* Leave local scope. */
	sym_tab_local=NULL; /* Clear local symbol table. */
}
| error
{
	error("Bad function syntax");
	$$=NULL;
}
;

function_head : IDENTIFIER
{
	$$=declare_func($1);
	scope=1; /* Enter local scope. */
	sym_tab_local=NULL; /* Init local symbol table. */
}
| INT IDENTIFIER
{
	$$ = declare_func($2);
	scope = 1;
	sym_tab_local = NULL;
}
| CHAR IDENTIFIER
{
	$$ = declare_func($2);
	scope = 1;
	sym_tab_local = NULL;
}
;

parameter_list : IDENTIFIER
{
	$$=declare_para($1);
}               
| parameter_list ',' IDENTIFIER
{
	$$=join_tac($1, declare_para($3));
}            
| INT IDENTIFIER
{
	$$ = declare_para($2);
}   
| CHAR IDENTIFIER
{
	$$ = declare_para($2);
}
| parameter_list ',' INT IDENTIFIER
{
	$$ = join_tac($1,declare_para($4));
}
| parameter_list ',' CHAR IDENTIFIER
{
	$$ = join_tac($1,declare_para($4));
}
|
{
	$$=NULL;
}
;

statement : block
| assignment_statement ';'
| input_statement ';'
| output_statement ';'
| call_statement ';'
| return_statement ';'
| if_statement
| switch_statement
| while_statement
| for_statement
| break_statement ';'
| continue_statement ';'
| error
{
	error("Bad statement syntax");
	$$=NULL;
}
;

block : '{' declaration_list statement_list '}'
{
	$$=join_tac($2, $3);
}               
;

declaration_list        :
{
	$$=NULL;
}
| declaration_list declaration
{
	$$=join_tac($1, $2);
}
;

statement_list : statement
| statement_list statement
{
	$$=join_tac($1, $2);
}               
;

lvalue_path:IDENTIFIER '.' IDENTIFIER lvalue_tail_opt
{
    PATH *p = append_path_member(NULL, $3);
    p = append_path_list(p, $4);
    $$ = mk_lvalue_path($1, p);
}
| IDENTIFIER dims_idx '.' IDENTIFIER lvalue_tail_opt
{
    PATH *p = append_path_index(NULL, $2); 
    p = append_path_list(p, append_path_member(NULL, $4));
    p = append_path_list(p, $5);

    $$ = mk_lvalue_path($1, p);
}
;

lvalue_tail_opt:
    { $$ = NULL; }
    | lvalue_tail     { $$ = $1;   }
;


lvalue_tail:'.' IDENTIFIER
{
    $$ = append_path_member(NULL, $2);
}
| dims_idx
{
    $$ = append_path_index(NULL, $1);
}
| lvalue_tail '.' IDENTIFIER
{
    $$ = append_path_member($1, $3);
}
| lvalue_tail dims_idx
{
    $$ = append_path_index($1, $2);
}
;

assignment_statement : IDENTIFIER '=' expression
{
	$$=do_assign(get_var($1), $3);
}
| IDENTIFIER dims_idx '=' expression  // 存入数组
{
	$$ = do_array_store(get_var($1),$2,$4);
}
| '*' IDENTIFIER '=' expression    
{
	SYM *ptr = get_var($2);
	TAC *store = mk_tac(TAC_STORE, ptr, $4->ret, NULL);
	store->prev = $4->tac;
	$$ = store;
}
| IDENTIFIER '=' '&' IDENTIFIER        
{
    SYM *dst = get_var($1);
    SYM *src = get_var($4);
    TAC *addr = mk_tac(TAC_ADDR, dst, src, NULL);
    $$ = addr;
}
| IDENTIFIER '=' '*' IDENTIFIER      
{
    SYM *dst = get_var($1);
    SYM *src = get_var($4);
    TAC *load = mk_tac(TAC_LOAD, dst, src, NULL);
    $$ = load;
}
// | IDENTIFIER '.' IDENTIFIER '=' expression  // i.a = b
// {
// 	SYM*base = get_var($1);
// 	int offset = get_struct_offset(base,$3);
// 	$$ = make_struct_store_tac(base,offset,$5);
// }
| lvalue_path '=' expression
{
	$$ = do_lvalue_store($1,$3);
}
;


expression : IDENTIFIER
{
	// printf("identifier %s\n",$1);
	$$ = mk_exp(NULL, get_var($1), NULL);
}
| expression '+' expression
{
	$$=do_bin(TAC_ADD, $1, $3);
}
| expression '-' expression
{
	$$=do_bin(TAC_SUB, $1, $3);
}
| expression '*' expression
{
	$$=do_bin(TAC_MUL, $1, $3);
}
| expression '/' expression
{
	$$=do_bin(TAC_DIV, $1, $3);
}
| '-' expression  %prec UMINUS
{
	$$=do_un(TAC_NEG, $2);
}
| expression EQ expression
{
	$$=do_cmp(TAC_EQ, $1, $3);
}
| expression NE expression
{
	$$=do_cmp(TAC_NE, $1, $3);
}
| expression LT expression
{
	$$=do_cmp(TAC_LT, $1, $3);
}
| expression LE expression
{
	$$=do_cmp(TAC_LE, $1, $3);
}
| expression GT expression
{
	$$=do_cmp(TAC_GT, $1, $3);
}
| expression GE expression
{
	$$=do_cmp(TAC_GE, $1, $3);
}
| '(' expression ')'
{
	$$=$2;
}               
| INTEGER
{
	$$=mk_exp(NULL, mk_const(atoi($1)), NULL);
}
| lvalue_path
{
	$$ = do_lvalue_load($1);
}
| CHAR_CONST
{
	$$=mk_exp(NULL,mk_char($1[1]),NULL);
}
| IDENTIFIER dims_idx
{
	$$ = do_array_load(get_var($1),$2);  // 加载数组值
}
| call_expression
{
	$$=$1;
}
| '&' IDENTIFIER
{
	SYM*tmp = mk_tmp();
	TAC*decl = mk_tac(TAC_VAR,tmp,NULL,NULL);
	TAC*addr = mk_tac(TAC_ADDR,tmp,get_var($2),NULL);
	addr->prev = decl;
	$$ = mk_exp(NULL,tmp,addr);
} 
|'&' lvalue_path
{
	$$ = do_lvalue_addr($2);
}
// | IDENTIFIER '.' IDENTIFIER  // 结构体读值a.b
// {
// 	SYM *base = get_var($1);
// 	int offset = get_struct_offset(base,$3);
// 	$$ = make_struct_load_exp(base,offset);
// }
| error
{
	error("Bad expression syntax");
	$$=mk_exp(NULL, NULL, NULL);
}
;

argument_list           :
{
	$$=NULL;
}
| expression_list
;

expression_list : expression
|  expression_list ',' expression
{
	$3->next=$1;
	$$=$3;
}
;

input_statement : INPUT IDENTIFIER
{
	$$=do_input(get_var($2));
}
;

output_statement : OUTPUT IDENTIFIER
{
	$$=do_output(get_var($2));
}
| OUTPUT TEXT
{
	$$=do_output(mk_text($2));
}
| OUTPUT expression
{
	TAC*t = mk_tac(TAC_OUTPUT,$2->ret,NULL,NULL);
	t->prev = $2->tac;
	$$ = t;
}
;

return_statement : RETURN expression
{
	TAC *t=mk_tac(TAC_RETURN, $2->ret, NULL, NULL);
	t->prev=$2->tac;
	$$=t;
}               
;

if_statement : IF '(' expression ')' block
{
	$$=do_if($3, $5);
}
| IF '(' expression ')' block ELSE block
{
	$$=do_test($3, $5, $7);
}
;

switch_statement
  : SWITCH '(' expression ')'
    {
      g_switch_end = mk_label(mk_lstr(next_label++));
      push_loop_labels(NULL, g_switch_end);  // 同for, 只有end
    }
    '{' case_list default_list '}'
    {
      $$ = do_switch($3, $7, $8, g_switch_end);
      pop_loop_labels();
      g_switch_end = NULL;
    }
  ;

case_list:
case_item  { $$ = $1; }
| case_list case_item
{
	$$ = join_tac($1,$2);
}
;

case_item: CASE INTEGER ':' statement_list
{
	$$ = do_case(atoi($2),$4);
}
;

default_list:
{
	 $$ = NULL; 
}
| DEFAULT ':' statement_list 
{ 
	$$ = $3; 
}

while_statement : WHILE '(' expression ')' 
{
    g_for_start_stack[g_for_depth] = mk_label(mk_lstr(next_label++));
    g_for_cont_stack[g_for_depth]  = mk_label(mk_lstr(next_label++));
    g_for_end_stack[g_for_depth]   = mk_label(mk_lstr(next_label++));

    g_for_start = g_for_start_stack[g_for_depth];
    g_for_cont  = g_for_cont_stack[g_for_depth];
    g_for_end   = g_for_end_stack[g_for_depth];

    g_for_depth++;

    push_loop_labels(g_for_cont, g_for_end);
}
block
{
    SYM *start = g_for_start_stack[g_for_depth - 1];
    SYM *cont  = g_for_cont_stack[g_for_depth - 1];
    SYM *end   = g_for_end_stack[g_for_depth - 1];

    // if (start != NULL)
    //     printf("g_for_start\n");
    // elses
    //     printf("start null\n");

    $$ = do_while($3, $6, start, cont, end);

    g_for_depth--;

    if (g_for_depth > 0) {
        g_for_start = g_for_start_stack[g_for_depth - 1];
        g_for_cont  = g_for_cont_stack[g_for_depth - 1];
        g_for_end   = g_for_end_stack[g_for_depth - 1];
    } else {
        g_for_start = g_for_cont = g_for_end = NULL;
    }

    pop_loop_labels();
}
;


for_statement
  : FOR '(' opt_statement ';' opt_expression ';' opt_statement ')'
    {
      g_for_start = mk_label(mk_lstr(next_label++));
      g_for_cont  = mk_label(mk_lstr(next_label++));
      g_for_end   = mk_label(mk_lstr(next_label++));
      push_loop_labels(g_for_cont, g_for_end);
    }
    block
    {
      $$ = do_for($3, $5, $7, $10, g_for_start, g_for_cont, g_for_end);
      pop_loop_labels();
      g_for_start = g_for_cont = g_for_end = NULL;
    }
  ;



opt_statement: assignment_statement
{
	$$ = $1;
}
|
{
	$$ = NULL;
}
;

opt_expression: expression
{
	$$ = $1;
}
|
{
	$$ = NULL;
}
;

break_statement: BREAK
{
	$$=do_break();
}
;

continue_statement:CONTINUE
{
	$$=do_continue();
}
;

call_statement : IDENTIFIER '(' argument_list ')'
{
	$$=do_call($1, $3);
}
;

call_expression : IDENTIFIER '(' argument_list ')'
{
	$$=do_call_ret($1, $3);
}
;

%%

PATH *append_path_list(PATH *head, PATH *tail)
{
    if (!head) return tail;
    PATH *p = head;
    while (p->next) {
		p = p->next;
	}
    p->next = tail;
    return head;
}


void yyerror(char* msg) 
{
	fprintf(stderr, "%s: line %d\n", msg, yylineno);
	exit(0);
}
