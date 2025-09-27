%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE * yyin;
extern int yylineno;

int yylex();
void yyerror(char* msg);
%}

%token IDENTIFIER INTEGER TEXT INT CHAR
%token EQ NE LT LE GT GE UMINUS
%token IF THEN ELSE FI WHILE FOR DO DONE CONTINUE FUNC INPUT OUTPUT RETURN
%token LBRACKET RBRACKET
%token INC DEC ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%token SHL_ASSIGN SHR_ASSIGN SHL SHR
%token SWITCH CASE DEFAULT BREAK
%token AND OR NOT BITAND BITOR BITXOR
%token CHAR_CONST STRING_CONST
%token LBRACE RBRACE


%right UMINUS
%left INC DEC
%left '*' '/'
%left '+' '-'
%left SHL SHR
%left BITAND
%left BITXOR
%left BITOR
%left LT LE GT GE
%left EQ NE
%left AND
%left OR
%right '?' ':'
%right ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN SHL_ASSIGN SHR_ASSIGN
%right NOT
       



%%
program : function_declaration_list
{
	printf("acc\n");
}
;

function_declaration_list : function_declaration
| function_declaration_list function_declaration
;

function_declaration : function
| declaration
;

declaration : INT variable_list ';'
| CHAR variable_list ';'
;

declarator: IDENTIFIER
| IDENTIFIER array_suffix
;

init_declarator: declarator
| declarator '=' initializer
;

array_suffix: LBRACKET INTEGER RBRACKET
| array_suffix LBRACKET INTEGER RBRACKET
;

variable_list: init_declarator
| variable_list ',' init_declarator
;


initializer: INTEGER
| CHAR_CONST
| STRING_CONST
| LBRACE initializer_list RBRACE
;

initializer_list:initializer
| initializer_list ',' initializer
;

function : function_head '(' parameter_list ')' block
| error
;

function_head : IDENTIFIER
;

parameter_list : IDENTIFIER               
| parameter_list ',' IDENTIFIER               
|
;

statement : assignment_statement ';'
| input_statement ';'
| output_statement ';'
| call_statement ';'
| return_statement ';'
| null_statement ';'
| if_statement
| while_statement
| for_statement
| do_statement
| switch_statement
| break_statement
| block
| error
;

block : LBRACE declaration_list statement_list RBRACE
;

declaration_list  :
| declaration_list declaration
;

statement_list : 
| statement_list statement               
;

assignment_statement : IDENTIFIER '=' expression
| IDENTIFIER LBRACKET expression RBRACKET '=' expression
| IDENTIFIER ADD_ASSIGN expression
| IDENTIFIER SUB_ASSIGN expression
| IDENTIFIER MUL_ASSIGN expression
| IDENTIFIER DIV_ASSIGN expression
| IDENTIFIER SHL_ASSIGN expression
| IDENTIFIER SHR_ASSIGN expression
| IDENTIFIER LBRACKET expression RBRACKET ADD_ASSIGN expression
| IDENTIFIER LBRACKET expression RBRACKET SUB_ASSIGN expression
| IDENTIFIER LBRACKET expression RBRACKET MUL_ASSIGN expression
| IDENTIFIER LBRACKET expression RBRACKET DIV_ASSIGN expression
| IDENTIFIER LBRACKET expression RBRACKET SHL_ASSIGN expression
| IDENTIFIER LBRACKET expression RBRACKET SHR_ASSIGN expression
| IDENTIFIER INC
| IDENTIFIER DEC
| IDENTIFIER LBRACKET expression RBRACKET INC
| IDENTIFIER LBRACKET expression RBRACKET DEC
;

expression : expression '+' expression
| expression '-' expression
| expression '*' expression
| expression '/' expression
| expression SHL expression
| expression SHR expression
| '-' expression  %prec UMINUS
| expression EQ expression
| expression NE expression
| expression LT expression
| expression LE expression
| expression GT expression
| expression GE expression
| expression AND expression
| expression OR expression
| NOT expression
| expression BITAND expression
| expression BITOR expression
| expression BITXOR expression
| '(' expression ')'
| INTEGER
| IDENTIFIER
| IDENTIFIER LBRACKET expression RBRACKET
| call_expression
| expression INC
| expression DEC
| INC expression
| DEC expression
| expression '?' expression ':' expression
| error
;

argument_list  :
| expression_list
;

expression_list : expression
|  expression_list ',' expression
;

input_statement : INPUT IDENTIFIER
| INPUT IDENTIFIER LBRACKET expression RBRACKET
;

output_statement : OUTPUT IDENTIFIER
| OUTPUT TEXT
| OUTPUT IDENTIFIER LBRACKET expression RBRACKET
;

return_statement : RETURN expression
;

null_statement : CONTINUE
;

if_statement : IF '(' expression ')' block
| IF '(' expression ')' block ELSE block
;

while_statement : WHILE '(' expression ')' block
;

do_statement: DO block WHILE '(' expression ')' ';'
;

for_statement : FOR '(' assignment_statement ';' expression ';' assignment_statement ')' block
;

switch_statement: SWITCH '(' expression ')' '{' case_list default_clause'}'
;

case_list: case_list case_clause
| case_clause
;

case_clause: CASE INTEGER ':' statement_list
| CASE CHAR_CONST ':' statement_list
;

default_clause: DEFAULT ':' statement_list
|
;

break_statement: BREAK ';'
;

call_statement : IDENTIFIER '(' argument_list ')'
;

call_expression : IDENTIFIER '(' argument_list ')'
;


%%
	
void yyerror(char* msg) 
{
	printf("%s: line %d\n", msg, yylineno);
	exit(0);
}
