%{
    int count = 0;
%}

%%

int|if|then|else|while|for|return|char|float|double|break|continue|switch|case|default {
	count++;
	printf("%d.keyword:\t%s\n", count, yytext);
}

\"([^"\n]|\\.)*\" {  // 字符串
    count = count++;
    char buf[1024];
    strncpy(buf, yytext + 1, yyleng - 2);
    buf[yyleng - 2] = '\0';
    printf("%d.string:\t%s\n", count, buf);
}

\'([^'\\]|\\.)\' {  // 单字符
    count++;
    printf("%d.char:\t%s\n", count, yytext);
}


[0-9]+ {  // 数字
    count++;
    printf("%d.number:\t%s\n",count, yytext);
}

("++"|"--"|"=="|"!="|"<="|">="|">>"|"<<")  {
    count++;
    printf("%d.operator:\t%s\n",count ,yytext);
}

("+"|"-"|"*"|"/"|"="|"<"|">"|"!") {
    count++;
    printf("%d.operator:\t%s\n", count, yytext);
}

("&&"|"||"|"&"|"|"|"^"|"~") {
    count++;
    printf("%d.operator:\t%s\n", count, yytext);
}

(","|";"|"{"|"}"|"("|")"|"["|"]") {
    count++;
    printf("%d.delimiter:\t%s\n", count, yytext);
}

[A-Za-z_][A-Za-z0-9_]*   {  // 标识符
    count++;
    printf("%d.identifier:\t%s\n", count, yytext);
}

"//".*  ;   // 丢弃单行注释

"/*"([^*]|\*+[^/])*\*+"/" ;  // 丢弃多行注释

[ \t\r\n]+    ;   // 空格、Tab、回车、换行全部跳过


[0-9]+[A-Za-z_][A-Za-z0-9_]* {  // 数字开头非法标识符
    printf("error: invalid identifier\t%s\n", yytext);
}

\"([^"\n]|\\.)*    {  // 未闭合字符串
    printf("error: unterminated string\t%s\n", yytext);
}

\'([^'\\]|\\.)*    {  // 未闭合字符
    printf("error: unterminated char\t%s\n", yytext);
}

"/*"([^*]|\*+[^/])*$ {  // 未闭合注释
    printf("error: unterminated comment\n");
}

. {  // 无法识别的字符
    printf("error: unrecognized symbol\t%s\n", yytext);
}

%%

int yywrap() {
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("usage: %s filename\n", argv[0]);
        return 0;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        printf("error: open %s failed\n", argv[1]);
        return 0;
    }

    yylex();
    fclose(yyin);
    return 0;
}
