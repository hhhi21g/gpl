%{
	int line=0;  // 统计当前已经处理到了第几行
%}

%%

^(.*)\n {  // 行首 + 任意字符 + 换行符
	line = line + 1;
	printf("%d\t%s", line, yytext);
}

%%

int yywrap() {  // 遇到EOF
	static int i=1;

	if(i==1) {
		yyin = fopen("input_1", "r");
		i=2;
		return 0;
	}

	if(i==2) {
		yyin = fopen("input_2", "r");
		i=3;
		return 0;
	}
	
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
