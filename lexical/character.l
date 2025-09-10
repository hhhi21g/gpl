
%%

.|\n {	  // 匹配单个字符或换行符
	printf("%c", *yytext);   // yytext：Flex自动提供的全局变量
}

%%

int yywrap() {  // Flex默认会调用的函数，用来判断输入是否结束
	return 1;
}

int main(int argc, char* argv[]) {
	if(argc != 2) {  // 程序运行时必须带一个参数：文件名，否则提示用法
		printf("usage: %s filename\n", argv[0]);
		return 0;
	}

	yyin = fopen(argv[1], "r");  // Flex内置的文件指针，这里将它设置为用户给的文件
	
	if(yyin == NULL) {
		printf("error: open %s failed\n", argv[1]);
		return 0;
	}

	yylex();  // 启动词法分析器，逐个匹配规则

	fclose(yyin);
	return 0;
}
