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
    INT = 258,                     /* INT  */
    EQ = 259,                      /* EQ  */
    NE = 260,                      /* NE  */
    LT = 261,                      /* LT  */
    LE = 262,                      /* LE  */
    GT = 263,                      /* GT  */
    GE = 264,                      /* GE  */
    UMINUS = 265,                  /* UMINUS  */
    STRUCT_TOK = 266,              /* STRUCT_TOK  */
    PTR_OP = 267,                  /* PTR_OP  */
    IF = 268,                      /* IF  */
    ELSE = 269,                    /* ELSE  */
    SWITCH = 270,                  /* SWITCH  */
    CASE = 271,                    /* CASE  */
    DEFAULT = 272,                 /* DEFAULT  */
    WHILE = 273,                   /* WHILE  */
    FOR = 274,                     /* FOR  */
    BREAK = 275,                   /* BREAK  */
    CONTINUE = 276,                /* CONTINUE  */
    FUNC = 277,                    /* FUNC  */
    INPUT = 278,                   /* INPUT  */
    OUTPUT = 279,                  /* OUTPUT  */
    RETURN = 280,                  /* RETURN  */
    INTEGER = 281,                 /* INTEGER  */
    IDENTIFIER = 282,              /* IDENTIFIER  */
    TEXT = 283,                    /* TEXT  */
    CHAR = 284,                    /* CHAR  */
    CHAR_CONST = 285,              /* CHAR_CONST  */
    LBRACK = 286,                  /* LBRACK  */
    RBRACK = 287                   /* RBRACK  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define EQ 259
#define NE 260
#define LT 261
#define LE 262
#define GT 263
#define GE 264
#define UMINUS 265
#define STRUCT_TOK 266
#define PTR_OP 267
#define IF 268
#define ELSE 269
#define SWITCH 270
#define CASE 271
#define DEFAULT 272
#define WHILE 273
#define FOR 274
#define BREAK 275
#define CONTINUE 276
#define FUNC 277
#define INPUT 278
#define OUTPUT 279
#define RETURN 280
#define INTEGER 281
#define IDENTIFIER 282
#define TEXT 283
#define CHAR 284
#define CHAR_CONST 285
#define LBRACK 286
#define RBRACK 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "mini.y"

	char character;
	char *string;
	SYM *sym;
	TAC *tac;
	EXP	*exp;
	PATH *path;

#line 140 "mini.y.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MINI_Y_H_INCLUDED  */
