%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE * yyin;
extern int yylineno;
int yylex();
void yyerror(char* msg);

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

%union
{
	int num;
	char *str;
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

%type <num> expression
%type <num> assignments

%%

start:
	statements
	;

statements:
	statements statement
	|statement
	;

statement:
	assignments '\n'
	|assignments
	|if_statement
	|while_statement
	|'{' statements '}' '\n'
	|'{' statements '}'
	|'\n'
	;

assignments: IDENTIFIER '=' assignments
{  
	set_value($1,$3);
	printf("%s: %d\n", $1, $3); 
	$$ = $3;
}
|expression
;

expression: INTEGER  			{  $$ = $1;  }
| IDENTIFIER                    {  $$ = get_value($1);}
| expression '+' expression		{  $$ = $1 + $3;  }
| expression '-' expression  	{  $$ = $1 - $3;  }
| expression '*' expression  	{  $$ = $1 * $3;  }
| expression '/' expression  	{  $$ = $1 / $3;  }
| expression '>' expression     { $$ = ($1 > $3); }
| expression '<' expression     { $$ = ($1 < $3); }
| expression GE expression      { $$ = ($1 >= $3); }
| expression LE expression      { $$ = ($1 <= $3); }
| expression EQ expression      { $$ = ($1 == $3); }
| expression NE expression      { $$ = ($1 != $3); }
| '(' expression ')'  			{  $$ = $2;  }
;

if_statement:
	IF '(' expression ')' statement {printf("%d\n",$3);}
	|IF '(' expression ')' statement ELSE statement {printf("%d\n",$3);}

while_statement:
    WHILE '(' expression ')' '\n' statement   { printf("%d\n", $3); }
  | WHILE '(' expression ')' statement        { printf("%d\n", $3); }
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

	yyparse();

	fclose(yyin);
	return 0;
}