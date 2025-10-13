%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern FILE * yyin;
extern int yylineno;
int yylex();
void yyerror(char* msg);
AST*root;

#define MAXVARS 1000
typedef struct {char name[100]; int value;}Var;
Var sym[MAXVARS];
int sym_count = 0;

int find_var_idx(const char*name){
	for(int i = 0;i<sym_count;i++){
		if(strcmp(sym[i].name,name) == 0)return i;
	}
	return -1;
}

int get_value(const char*name){
	int id = find_var_idx(name);
	if(id != -1)return sym[id].value;
	else return 0;
}

void set_value(const char*name,int value){
	int id = find_var_idx(name);
	if(id == -1){
		strcpy(sym[sym_count].name,name);
		sym[sym_count].value = value;
		sym_count ++;
	}else{
		sym[id].value = value;
	}
}

%}

%locations

%union
{
	int num;
	char *str;
	AST* node;
}

%left  EQ NE
%left  LE GE '>' '<'  
%left '+' '-'                   
%left '*' '/'                   
%right UMINUS    

%token <num> INTEGER
%token <str> IDENTIFIER
%token IF ELSE WHILE
%token EQ NE LE GE

%type <node> start statements statement opt_nl
%type <node> assignments if_statement while_statement
%type <node> expression

%%

start:
	statements {root = $1;}
	;

statements:
	statements statement { $$=$1; ast_seq_push($1,$2); }
	|statement           { $$=ast_seq_new(@$.first_line);ast_seq_push($$,$1); }
	;

statement:
	assignments opt_nl              {$$ = $1;}
	|assignments                    {$$ = $1;}
	|if_statement                   {$$ = $1;}
	|while_statement                {$$ = $1;}
	|'{' statements '}' opt_nl      {$$ = $2;}
	|'{' statements '}'             {$$ = $2;}
	|opt_nl                         {$$ = ast_seq_new(@$.first_line);}
	;

opt_nl:'\n'   {$$=NULL;}
|             {$$=NULL;}
;
assignments: IDENTIFIER '=' assignments
{  
	int v = eval_expr($3);      
    set_value($1, v);
	$$ = ast_assign(@1.first_line,$1,$3);
	
}
|expression  { $$ = $1; }
;

expression: INTEGER  			{  $$ = ast_num(@$.first_line,$1);  }
| IDENTIFIER                    {  $$ = ast_var(@$.first_line,$1);}
| expression '+' expression		{  $$ = ast_binop(@$.first_line,OP_ADD,$1,$3);  }
| expression '-' expression  	{  $$ = ast_binop(@$.first_line,OP_SUB,$1,$3);  }
| expression '*' expression  	{  $$ = ast_binop(@$.first_line,OP_MUL,$1,$3);  }
| expression '/' expression  	{  $$ = ast_binop(@$.first_line,OP_DIV,$1,$3);  }
| expression '>' expression     { $$ = ast_binop(@$.first_line,OP_GT,$1,$3); }
| expression '<' expression     { $$ = ast_binop(@$.first_line,OP_LT,$1,$3); }
| expression GE expression      { $$ = ast_binop(@$.first_line,OP_GE,$1,$3); }
| expression LE expression      { $$ = ast_binop(@$.first_line,OP_LE,$1,$3); }
| expression EQ expression      { $$ = ast_binop(@$.first_line,OP_EQ,$1,$3); }
| expression NE expression      { $$ = ast_binop(@$.first_line,OP_NE,$1,$3); }
| '-' expression %prec UMINUS   { $$ = ast_unop(@$.first_line, OP_NEG, $2); }
| '(' expression ')'  			{  $$ = $2;  }
;

if_statement:
	IF '(' expression ')' statement {$$ = ast_if(@1.first_line,$3,$5,NULL);}
	|IF '(' expression ')' statement ELSE statement {$$ = ast_if(@1.first_line,$3,$5,$7);}

while_statement:
    WHILE '(' expression ')' opt_nl statement   { $$ = ast_while(@1.first_line,$3,$6);}
  | WHILE '(' expression ')' statement        { $$ = ast_while(@1.first_line,$3,$5); }
;

%%
	
void yyerror(char* msg) 
{
	printf("%s: line %d\n", msg, yylineno);
	exit(0);
}


int main(int argc, char *argv[]) 
{
	if(argc!=2) {
		printf("usage: %s filename\n", argv[0]);
		exit(0);
	}			

	if( (yyin=fopen(argv[1], "r")) ==NULL )
	{
		printf("open file %s failed\n", argv[1]);
		exit(0);
	}

	// yyparse();
	if (yyparse() != 0 || !root) {
		fprintf(stderr, "Parse failed: root is null\n");
		return 1;
	}	

	ast_print(root,0);
	exec_program(root);

	fclose(yyin);
	return 0;
}