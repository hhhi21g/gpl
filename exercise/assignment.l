%{
#include <stdlib.h>
#include "y.tab.h"


%}

%option yylineno

%%
"if" 	 {return IF;}
"else"   {return ELSE;}
"while"  {return WHILE;}

">="                { return GE; }     
"<="                { return LE; }      
"=="                { return EQ; }
"!="                { return NE; }

[A-Za-z]([A-Za-z]|[0-9])*	{  
								yylval.str = strdup(yytext); 
								return IDENTIFIER;  
							}

[0-9]+	{  
			yylval.num = atoi(yytext); return INTEGER;  
		}

"+"|"-"|"*"|"/"|"("|")"|"="|"<"|">"|"{"|"}" {  
								return *yytext;  
							}


\n  {return '\n';}
[ \t\r]

.	{
		printf("lexical error: line %d\n", yylineno);
		exit(0);
	}

%%

int yywrap()
{
	return 1;
}

