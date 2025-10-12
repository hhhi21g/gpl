%{
#include <stdlib.h>
#include "mini.y.h"
%}

%option yylineno

%%

"int"  {  return INT;  }

"char" { return CHAR; }

"string"  { return STRING; }


\'([^'\\]|\\.)\'  { return CHAR_CONST; }

\"([^"\n]|\\.)*\"  { return STRING_CONST; }


"[" { return LBRACKET; }

"]" { return RBRACKET; }

"{"  { return LBRACE; }

"}"  { return RBRACE; }


"input"  {  return INPUT;  }

"output"  {  return OUTPUT;  }

"return"  {  return RETURN;  }

"continue"  {  return CONTINUE;  }

"for" { return FOR; }

"if"  {  return IF;  }

"then"  {  return THEN;  }

"else"  {  return ELSE;  }

"fi"  {  return FI;  }

"while"  {  return WHILE;  }

"do"  {  return DO;  }

"done"  {  return DONE;  }

"switch" { return SWITCH; }

"case" { return CASE; }

"default" { return DEFAULT; }

"break" { return BREAK; }

[A-Za-z]([A-Za-z]|[0-9])*  {  return IDENTIFIER;  }

[0-9]+	{  return INTEGER;  }


"&&" { return AND; }

"||" { return OR; }

"!" { return NOT; }

"&" { return BITAND; }

"|" { return BITOR; }

"^" { return BITXOR; }

"=="  {  return EQ;  }

"!="  {  return NE;  }

"<="  {  return LE;  }

"<"  {  return LT;  }

">="  {  return GE;  }

">"  {  return GT;  }

"++" { return INC; }

"--" { return DEC; }

"+=" { return ADD_ASSIGN; }

"-=" { return SUB_ASSIGN; }

"*=" { return MUL_ASSIGN; }

"/=" { return DIV_ASSIGN; }

"<<=" { return SHL_ASSIGN; }

">>=" { return SHR_ASSIGN; }

"<<" { return SHL; }

">>" { return SHR; }

"//".*  ;  

"/*"([^*]|\*+[^/])*\*+"/" ;  

[ \t\r\n]|#.*

. 	{	return *yytext; }

%%

int yywrap()
{
	return 1;
}

