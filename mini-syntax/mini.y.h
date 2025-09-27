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
    EQ = 263,                      /* EQ  */
    NE = 264,                      /* NE  */
    LT = 265,                      /* LT  */
    LE = 266,                      /* LE  */
    GT = 267,                      /* GT  */
    GE = 268,                      /* GE  */
    UMINUS = 269,                  /* UMINUS  */
    IF = 270,                      /* IF  */
    THEN = 271,                    /* THEN  */
    ELSE = 272,                    /* ELSE  */
    FI = 273,                      /* FI  */
    WHILE = 274,                   /* WHILE  */
    FOR = 275,                     /* FOR  */
    DO = 276,                      /* DO  */
    DONE = 277,                    /* DONE  */
    CONTINUE = 278,                /* CONTINUE  */
    FUNC = 279,                    /* FUNC  */
    INPUT = 280,                   /* INPUT  */
    OUTPUT = 281,                  /* OUTPUT  */
    RETURN = 282,                  /* RETURN  */
    LBRACKET = 283,                /* LBRACKET  */
    RBRACKET = 284,                /* RBRACKET  */
    INC = 285,                     /* INC  */
    DEC = 286,                     /* DEC  */
    ADD_ASSIGN = 287,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 288,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 289,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 290,              /* DIV_ASSIGN  */
    SHL_ASSIGN = 291,              /* SHL_ASSIGN  */
    SHR_ASSIGN = 292,              /* SHR_ASSIGN  */
    SHL = 293,                     /* SHL  */
    SHR = 294,                     /* SHR  */
    SWITCH = 295,                  /* SWITCH  */
    CASE = 296,                    /* CASE  */
    DEFAULT = 297,                 /* DEFAULT  */
    BREAK = 298,                   /* BREAK  */
    AND = 299,                     /* AND  */
    OR = 300,                      /* OR  */
    NOT = 301,                     /* NOT  */
    BITAND = 302,                  /* BITAND  */
    BITOR = 303,                   /* BITOR  */
    BITXOR = 304,                  /* BITXOR  */
    CHAR_CONST = 305,              /* CHAR_CONST  */
    STRING_CONST = 306,            /* STRING_CONST  */
    LBRACE = 307,                  /* LBRACE  */
    RBRACE = 308                   /* RBRACE  */
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
#define EQ 263
#define NE 264
#define LT 265
#define LE 266
#define GT 267
#define GE 268
#define UMINUS 269
#define IF 270
#define THEN 271
#define ELSE 272
#define FI 273
#define WHILE 274
#define FOR 275
#define DO 276
#define DONE 277
#define CONTINUE 278
#define FUNC 279
#define INPUT 280
#define OUTPUT 281
#define RETURN 282
#define LBRACKET 283
#define RBRACKET 284
#define INC 285
#define DEC 286
#define ADD_ASSIGN 287
#define SUB_ASSIGN 288
#define MUL_ASSIGN 289
#define DIV_ASSIGN 290
#define SHL_ASSIGN 291
#define SHR_ASSIGN 292
#define SHL 293
#define SHR 294
#define SWITCH 295
#define CASE 296
#define DEFAULT 297
#define BREAK 298
#define AND 299
#define OR 300
#define NOT 301
#define BITAND 302
#define BITOR 303
#define BITXOR 304
#define CHAR_CONST 305
#define STRING_CONST 306
#define LBRACE 307
#define RBRACE 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MINI_Y_H_INCLUDED  */
