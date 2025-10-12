/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MINI_Y_H_INCLUDED
# define YY_YY_MINI_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTEGER = 259,                 /* INTEGER  */
    TEXT = 260,                    /* TEXT  */
    INT = 261,                     /* INT  */
    CHAR = 262,                    /* CHAR  */
    STRING = 263,                  /* STRING  */
    EQ = 264,                      /* EQ  */
    NE = 265,                      /* NE  */
    LT = 266,                      /* LT  */
    LE = 267,                      /* LE  */
    GT = 268,                      /* GT  */
    GE = 269,                      /* GE  */
    UMINUS = 270,                  /* UMINUS  */
    IF = 271,                      /* IF  */
    THEN = 272,                    /* THEN  */
    ELSE = 273,                    /* ELSE  */
    FI = 274,                      /* FI  */
    WHILE = 275,                   /* WHILE  */
    FOR = 276,                     /* FOR  */
    DO = 277,                      /* DO  */
    DONE = 278,                    /* DONE  */
    CONTINUE = 279,                /* CONTINUE  */
    FUNC = 280,                    /* FUNC  */
    INPUT = 281,                   /* INPUT  */
    OUTPUT = 282,                  /* OUTPUT  */
    RETURN = 283,                  /* RETURN  */
    LBRACKET = 284,                /* LBRACKET  */
    RBRACKET = 285,                /* RBRACKET  */
    INC = 286,                     /* INC  */
    DEC = 287,                     /* DEC  */
    ADD_ASSIGN = 288,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 289,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 290,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 291,              /* DIV_ASSIGN  */
    SHL_ASSIGN = 292,              /* SHL_ASSIGN  */
    SHR_ASSIGN = 293,              /* SHR_ASSIGN  */
    SHL = 294,                     /* SHL  */
    SHR = 295,                     /* SHR  */
    SWITCH = 296,                  /* SWITCH  */
    CASE = 297,                    /* CASE  */
    DEFAULT = 298,                 /* DEFAULT  */
    BREAK = 299,                   /* BREAK  */
    AND = 300,                     /* AND  */
    OR = 301,                      /* OR  */
    NOT = 302,                     /* NOT  */
    BITAND = 303,                  /* BITAND  */
    BITOR = 304,                   /* BITOR  */
    BITXOR = 305,                  /* BITXOR  */
    CHAR_CONST = 306,              /* CHAR_CONST  */
    STRING_CONST = 307,            /* STRING_CONST  */
    LBRACE = 308,                  /* LBRACE  */
    RBRACE = 309,                  /* RBRACE  */
    LOWER_THAN_ELSE = 310          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define INTEGER 259
#define TEXT 260
#define INT 261
#define CHAR 262
#define STRING 263
#define EQ 264
#define NE 265
#define LT 266
#define LE 267
#define GT 268
#define GE 269
#define UMINUS 270
#define IF 271
#define THEN 272
#define ELSE 273
#define FI 274
#define WHILE 275
#define FOR 276
#define DO 277
#define DONE 278
#define CONTINUE 279
#define FUNC 280
#define INPUT 281
#define OUTPUT 282
#define RETURN 283
#define LBRACKET 284
#define RBRACKET 285
#define INC 286
#define DEC 287
#define ADD_ASSIGN 288
#define SUB_ASSIGN 289
#define MUL_ASSIGN 290
#define DIV_ASSIGN 291
#define SHL_ASSIGN 292
#define SHR_ASSIGN 293
#define SHL 294
#define SHR 295
#define SWITCH 296
#define CASE 297
#define DEFAULT 298
#define BREAK 299
#define AND 300
#define OR 301
#define NOT 302
#define BITAND 303
#define BITOR 304
#define BITXOR 305
#define CHAR_CONST 306
#define STRING_CONST 307
#define LBRACE 308
#define RBRACE 309
#define LOWER_THAN_ELSE 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MINI_Y_H_INCLUDED  */
