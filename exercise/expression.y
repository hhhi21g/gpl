%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE * yyin;
extern int yylineno;
int yylex();
void yyerror(char* msg);

%}

%left  EQ NE
%left  LE GE '>' '<'  
%left '+' '-'                   
%left '*' '/'                   
%right UMINUS                   
           

%token INTEGER
%token ID NUM
%token EQ NE LE GE


%%

start: expression  {  printf("%d\n", $1);  }
;

expression: INTEGER  			{  $$ = $1;  }
| '(' expression ')'  			{  $$ = $2;  }
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

