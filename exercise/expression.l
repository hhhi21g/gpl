%{
#include <stdlib.h>
#include "y.tab.h"
%}

%option yylineno

%%

[0-9]+	{
			yylval = atoi(yytext);
			return INTEGER;
		}

">="                { return GE; }     
"<="                { return LE; }      
"=="                { return EQ; }
"!="                { return NE; }

"+"|"-"|"*"|"/"|"("|")"|">"|"<"	{
							return *yytext;
						}

[ \t\r\n]+ ;

.	{
		printf("lexical error: line %d\n", yylineno);
		exit(0);
	}

%%

int yywrap()
{
	return 1;
}

