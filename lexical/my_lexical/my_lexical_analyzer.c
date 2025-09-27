#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct KEYWORDS
{
    int num;
    char name[50];
};

typedef struct
{
    FILE *input;
    int character;    // 当前字符
    char token[1000]; // 当前 token
    int token_len;
    int line;   // 行号
    int column; // 列号
} Lexer;

struct KEYWORDS keywords[1000] = { // 关键字补全
    {3, "auto"},
    {4, "break"},
    {5, "case"},
    {6, "char"},
    {7, "const"},
    {8, "continue"},
    {9, "default"},
    {10, "do"},
    {11, "double"},
    {12, "else"},
    {13, "enum"},
    {14, "extern"},
    {15, "float"},
    {16, "for"},
    {17, "goto"},
    {18, "if"},
    {19, "inline"},
    {20, "int"},
    {21, "long"},
    {22, "register"},
    {23, "restrict"},
    {24, "return"},
    {25, "short"},
    {26, "signed"},
    {27, "sizeof"},
    {28, "static"},
    {29, "struct"},
    {30, "switch"},
    {31, "typedef"},
    {32, "union"},
    {33, "unsigned"},
    {34, "void"},
    {35, "volatile"},
    {36, "while"},
    {37, "_Alignas"},
    {38, "_Alignof"},
    {39, "_Atomic"},
    {40, "_Bool"},
    {41, "_Complex"},
    {42, "_Generic"},
    {43, "_Imaginary"},
    {44, "_Noreturn"},
    {45, "_Static_assert"},
    {46, "_Thread_local"},
    {0, ""}};

void printToken(int id, const char *token)
{
    printf("( %d , %s )\n", id, token);
}

void printError(Lexer *lex, const char *msg)
{
    printf("error at line %d, col %d: %s\n", lex->line, lex->column, msg);
}

void getch(Lexer *lex)
{
    lex->character = fgetc(lex->input);
    if (lex->character == '\n')
    {
        lex->line++;
        lex->column = 0;
    }
    else
    {
        lex->column++;
    }
}

void getnbc(Lexer *lex)
{ // 跳过空格和注释
    while ((lex->character == ' ') || (lex->character == '\t') || (lex->character == '\r') || (lex->character == '\n'))
        lex->character = fgetc(lex->input);

    // 如果遇到注释
    if (lex->character == '/')
    {
        int next = fgetc(lex->input);

        if (next == '/')
        { // 单行注释，跳到行末文件结束即可
            while (lex->character != '\n' && lex->character != EOF)
            {
                lex->character = fgetc(lex->input);
            }

            lex->character = fgetc(lex->input);

            getnbc(lex); // 递归调用，确保出去不再有单行注释
        }
        else if (next == '*')
        { // 跳到'*/'或EOF
            int prev = 0;
            while (1)
            {
                prev = lex->character;
                lex->character = fgetc(lex->input);

                if (lex->character == EOF)
                {
                    printError(lex, "注释未闭合");
                    return;
                }
                if (prev == '*' && lex->character == '/')
                {
                    break;
                }
            }

            lex->character = fgetc(lex->input);

            getnbc(lex);
        }
        else
        { // 一个左斜杠，不能被认为是注释, 应该被识别为除号
            ungetc(next, lex->input);
        }
    }
}

void concat(Lexer *lex)
{
    if (lex->token_len < sizeof(lex->token) - 1)
    {
        lex->token[lex->token_len++] = lex->character;
        lex->token[lex->token_len] = '\0';
    }
}

int letter(Lexer *lex)
{ // 是否为合法identifier
    if (((lex->character >= 'a') && (lex->character <= 'z')) ||
        ((lex->character >= 'A') && (lex->character <= 'Z')) ||
        (lex->character == '_'))
        return 1;
    else
        return 0;
}

int digit(Lexer *lex)
{ // 是否为数字
    if ((lex->character >= '0') && (lex->character <= '9'))
        return 1;
    else
        return 0;
}

int isHexDigit(Lexer *lex)
{
    return ((lex->character >= '0' && lex->character <= '9') ||
            (lex->character >= 'a' && lex->character <= 'f') ||
            (lex->character >= 'A' && lex->character <= 'F'));
}

int isOctDigit(Lexer *lex)
{
    return (lex->character >= '0' && lex->character <= '7');
}

int isBinDigit(Lexer *lex)
{
    return (lex->character == '0' || lex->character == '1');
}

void retract(Lexer *lex)
{
    if (lex->character != EOF)
    {
        ungetc(lex->character, lex->input);
    }
    lex->character = '\0';
}

int keyword(Lexer *lex)
{ // 判断当前token是否为关键字，如果是则返回编号
    int i = 0;
    while (strcmp(keywords[i].name, ""))
    {
        if (!strcmp(keywords[i].name, lex->token))
            return keywords[i].num;
        i++;
    }
    return 0;
}

void matchOperator(Lexer *lex, int id_single, const char *single,
                   int id_double, const char *dbl,
                   int id_eq, const char *eq)
{
    getch(lex);
    if (lex->character == single[0] && dbl != NULL)
    {
        printToken(id_double, dbl);
    }
    else if (lex->character == '=' && eq != NULL)
    {
        printToken(id_eq, eq);
    }
    else
    {
        retract(lex);
        printToken(id_single, single);
    }
}

int lex_analyze(Lexer *lex)
{
    int num;

    lex->token[0] = '\0';
    lex->token_len = 0;

    getch(lex);
    getnbc(lex);

    switch (lex->character)
    {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
    case '_':
        while (letter(lex) || digit(lex))
        { // 合法变量
            concat(lex);
            getch(lex);
        }

        retract(lex);
        num = keyword(lex);
        if (num != 0)
            printToken(num, lex->token); // keyword
        else
            printToken(1, lex->token); // 合法identifier
        break;

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        while (digit(lex))
        { // 如果以数字开头，继续读数字
            concat(lex);
            getch(lex);
        }

        // 如果数字后面跟了字母，报错
        if (letter(lex))
        {
            concat(lex);
            while (letter(lex) || digit(lex))
            {
                concat(lex);
                getch(lex);
            }
            char buf[200];
            snprintf(buf, sizeof(buf), "非法变量名 %s", lex->token);
            printError(lex, buf);
        }
        else
        {
            retract(lex);
            printToken(2, lex->token);
        }
        break;

    // 加减乘除及其复合运算符、自增自减
    case '+':
        matchOperator(lex, 49, "+", 47, "++", 48, "+=");
        break;

    case '-':
        matchOperator(lex, 52, "-", 50, "--", 51, "-=");
        break;

    case '*':
        matchOperator(lex, 54, "*", 0, NULL, 53, "*=");
        break;

    case '/':
        matchOperator(lex, 56, "/", 0, NULL, 55, "/=");
        break;
    // 其余需向后看一位
    case '<':
        concat(lex);
        getch(lex);
        if (lex->character == '=')
        {
            printToken(57, "<="); // <=
        }
        else if (lex->character == '<')
        {
            printToken(58, "<<"); // <<
        }
        else
        {
            retract(lex);
            printToken(59, "<"); // <
        }
        break;

    case '>':
        concat(lex);
        getch(lex);
        if (lex->character == '=')
        {
            printToken(60, ">="); // >=
        }
        else if (lex->character == '>')
        {
            printToken(61, ">>"); // >>
        }
        else
        {
            retract(lex);
            printToken(62, ">"); // >
        }
        break;

    case '!':
        matchOperator(lex, 64, "!", 0, NULL, 63, "!=");
        break;

    case '=':
        matchOperator(lex, 66, "=", 0, NULL, 65, "==");
        break;

    case '(':
        printToken(67, "("); // (
        break;

    case ')':
        printToken(68, ")"); // )
        break;

    case '"':
    {
        strcpy(lex->token, ""); // 清空 token
        getch(lex);             // 读下一个字符
        while (lex->character != '"' && lex->character != EOF)
        {
            concat(lex);
            getch(lex);
        }
        if (lex->character == EOF)
        {
            printError(lex, "字符串缺少引号");
        }
        else
        {
            printToken(73, lex->token);
        }
        break;
    }

    case ',':
        printToken(69, ","); // ,
        break;

    case ';':
        printToken(70, ";"); // ;
        break;

    case '{':
        printToken(71, "{");
        break;

    case '}':
        printToken(72, "}");
        break;

    case EOF:
        return 0;

    default:
        char buf[50];
        snprintf(buf, sizeof(buf), "非法字符 '%c'", lex->character);
        printError(lex, buf);
    }
    return 1;
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: %s input_file\n", argv[0]);
        exit(0);
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        printf("error: cannot open file \"%s\"\n", argv[1]);
        exit(1);
    }

    Lexer lex;
    lex.input = fp;
    lex.character = '\0';
    lex.token_len = 0;
    lex.line = 1;
    lex.column = 0;

    while (1)
    {
        if (lex_analyze(&lex) == 0)
            break;
    }

    fclose(fp);

    return 0;
}
