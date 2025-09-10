%{
	int count=0;
%}

%%

[A-Za-z]([A-Za-z]|[0-9])* {  // 以字母开头，后面跟字母或数字的字符串，后接任意数量
	count = count + 1;
	printf("identifier_%d: %s\n", count, yytext);
}

.|\n  // 匹配但丢弃

%%

int yywrap() {
	return 1;
}

int main(int argc, char* argv[]) {
	if(argc != 2) {
		printf("usage: %s filename\n", argv[0]);
		return 0;
	}

	yyin = fopen(argv[1], "r");
	
	if(yyin == NULL) {
		printf("error: open %s failed\n", argv[1]);
		return 0;
	}

	yylex();

	fclose(yyin);
	return 0;
}
