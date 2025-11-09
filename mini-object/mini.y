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

%}

%union
{
	char character;
	char *string;
	SYM *sym;
	TAC *tac;
	EXP	*exp;
}

%token INT EQ NE LT LE GT GE UMINUS IF ELSE SWITCH CASE DEFAULT WHILE FOR BREAK CONTINUE FUNC INPUT OUTPUT RETURN
%token <string> INTEGER IDENTIFIER TEXT CHAR CHAR_CONST

%left EQ NE LT LE GT GE
%left '+' '-'
%left '*' '/'
%right UMINUS

%type <tac> program function_declaration_list function_declaration function parameter_list variable_list statement assignment_statement return_statement if_statement switch_statement case_list case_item default_list while_statement for_statement break_statement continue_statement opt_statement call_statement block declaration_list declaration statement_list input_statement output_statement 
%type <tac> variable_list_char decl_item_char decl_item_int
%type <exp> argument_list expression_list expression call_expression  opt_expression
%type <sym> function_head

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
;

declaration : INT variable_list ';'
{
	$$=$2;
}
| CHAR variable_list_char ';'
{
	$$=$2;
}
;

variable_list
    : decl_item_int
    | variable_list ',' decl_item_int
      { $$ = join_tac($1, $3); }
    ;

decl_item_int
    : IDENTIFIER
      { $$ = declare_var_typed($1, SYM_INT); }
    | '*' IDENTIFIER
      { $$ = declare_var_typed($2, SYM_PTR); }
    ;


variable_list_char
    : decl_item_char
    | variable_list_char ',' decl_item_char
      { $$ = join_tac($1, $3); }
    ;

decl_item_char
    : IDENTIFIER
      { $$ = declare_var_typed($1, SYM_CHAR); }
    | '*' IDENTIFIER
      { $$ = declare_var_typed($2, SYM_PTR); }
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
;

parameter_list : IDENTIFIER
{
	$$=declare_para($1);
}               
| parameter_list ',' IDENTIFIER
{
	$$=join_tac($1, declare_para($3));
}               
|
{
	$$=NULL;
}
;

statement : assignment_statement ';'
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
| block
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

assignment_statement : IDENTIFIER '=' expression
{
	$$=do_assign(get_var($1), $3);
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
;

expression : expression '+' expression
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
| IDENTIFIER
{
	$$=mk_exp(NULL, get_var($1), NULL);
}
| CHAR_CONST
{
	$$=mk_exp(NULL,mk_char($1[1]),NULL);
}
| call_expression
{
	$$=$1;
}
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
      /* 注意：switch 里只有 break，没有 continue，所以继续标签传 NULL */
      push_loop_labels(NULL, g_switch_end);
    }
    '{' case_list default_list '}'
    {
      /* 这里用“已经建好的 end 标签”收尾 */
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
{ $$ = NULL; }
| DEFAULT ':' statement_list { $$ = $3; }

while_statement : WHILE '(' expression ')' 
{
	g_for_start = mk_label(mk_lstr(next_label++));
    g_for_cont  = mk_label(mk_lstr(next_label++));
    g_for_end   = mk_label(mk_lstr(next_label++));
    push_loop_labels(g_for_cont, g_for_end);
}
block
{
	$$=do_while($3, $6,g_for_start,g_for_cont,g_for_end);
	pop_loop_labels();
	g_for_start = g_for_cont = g_for_end = NULL;
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

void yyerror(char* msg) 
{
	fprintf(stderr, "%s: line %d\n", msg, yylineno);
	exit(0);
}
