/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "mini.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tac.h"

int yylex();
void yyerror(char* msg);

static SYM *g_for_start = NULL;
static SYM *g_for_cont  = NULL;
static SYM *g_for_end   = NULL;
static SYM *g_switch_end = NULL;

static char *g_cur_struct = NULL;


#line 89 "mini.y.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "mini.y.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_EQ = 4,                         /* EQ  */
  YYSYMBOL_NE = 5,                         /* NE  */
  YYSYMBOL_LT = 6,                         /* LT  */
  YYSYMBOL_LE = 7,                         /* LE  */
  YYSYMBOL_GT = 8,                         /* GT  */
  YYSYMBOL_GE = 9,                         /* GE  */
  YYSYMBOL_UMINUS = 10,                    /* UMINUS  */
  YYSYMBOL_STRUCT_TOK = 11,                /* STRUCT_TOK  */
  YYSYMBOL_DOT = 12,                       /* DOT  */
  YYSYMBOL_PTR_OP = 13,                    /* PTR_OP  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_SWITCH = 16,                    /* SWITCH  */
  YYSYMBOL_CASE = 17,                      /* CASE  */
  YYSYMBOL_DEFAULT = 18,                   /* DEFAULT  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_BREAK = 21,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 22,                  /* CONTINUE  */
  YYSYMBOL_FUNC = 23,                      /* FUNC  */
  YYSYMBOL_INPUT = 24,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 25,                    /* OUTPUT  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_INTEGER = 27,                   /* INTEGER  */
  YYSYMBOL_IDENTIFIER = 28,                /* IDENTIFIER  */
  YYSYMBOL_TEXT = 29,                      /* TEXT  */
  YYSYMBOL_CHAR = 30,                      /* CHAR  */
  YYSYMBOL_CHAR_CONST = 31,                /* CHAR_CONST  */
  YYSYMBOL_LBRACK = 32,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 33,                    /* RBRACK  */
  YYSYMBOL_34_ = 34,                       /* '+'  */
  YYSYMBOL_35_ = 35,                       /* '-'  */
  YYSYMBOL_36_ = 36,                       /* '*'  */
  YYSYMBOL_37_ = 37,                       /* '/'  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* '='  */
  YYSYMBOL_45_ = 45,                       /* '&'  */
  YYSYMBOL_46_ = 46,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_function_declaration_list = 49, /* function_declaration_list  */
  YYSYMBOL_function_declaration = 50,      /* function_declaration  */
  YYSYMBOL_dims_decl = 51,                 /* dims_decl  */
  YYSYMBOL_dims_idx = 52,                  /* dims_idx  */
  YYSYMBOL_declaration = 53,               /* declaration  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_struct_var_list = 55,           /* struct_var_list  */
  YYSYMBOL_struct_definition = 56,         /* struct_definition  */
  YYSYMBOL_57_2 = 57,                      /* $@2  */
  YYSYMBOL_struct_member_list = 58,        /* struct_member_list  */
  YYSYMBOL_struct_member_line = 59,        /* struct_member_line  */
  YYSYMBOL_postfix_lvalue = 60,            /* postfix_lvalue  */
  YYSYMBOL_lvalue = 61,                    /* lvalue  */
  YYSYMBOL_variable_list = 62,             /* variable_list  */
  YYSYMBOL_decl_item_int = 63,             /* decl_item_int  */
  YYSYMBOL_variable_list_char = 64,        /* variable_list_char  */
  YYSYMBOL_decl_item_char = 65,            /* decl_item_char  */
  YYSYMBOL_function = 66,                  /* function  */
  YYSYMBOL_function_head = 67,             /* function_head  */
  YYSYMBOL_parameter_list = 68,            /* parameter_list  */
  YYSYMBOL_statement = 69,                 /* statement  */
  YYSYMBOL_block = 70,                     /* block  */
  YYSYMBOL_declaration_list = 71,          /* declaration_list  */
  YYSYMBOL_statement_list = 72,            /* statement_list  */
  YYSYMBOL_assignment_statement = 73,      /* assignment_statement  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_argument_list = 75,             /* argument_list  */
  YYSYMBOL_expression_list = 76,           /* expression_list  */
  YYSYMBOL_input_statement = 77,           /* input_statement  */
  YYSYMBOL_output_statement = 78,          /* output_statement  */
  YYSYMBOL_return_statement = 79,          /* return_statement  */
  YYSYMBOL_if_statement = 80,              /* if_statement  */
  YYSYMBOL_switch_statement = 81,          /* switch_statement  */
  YYSYMBOL_82_3 = 82,                      /* $@3  */
  YYSYMBOL_case_list = 83,                 /* case_list  */
  YYSYMBOL_case_item = 84,                 /* case_item  */
  YYSYMBOL_default_list = 85,              /* default_list  */
  YYSYMBOL_while_statement = 86,           /* while_statement  */
  YYSYMBOL_87_4 = 87,                      /* $@4  */
  YYSYMBOL_for_statement = 88,             /* for_statement  */
  YYSYMBOL_89_5 = 89,                      /* $@5  */
  YYSYMBOL_opt_statement = 90,             /* opt_statement  */
  YYSYMBOL_opt_expression = 91,            /* opt_expression  */
  YYSYMBOL_break_statement = 92,           /* break_statement  */
  YYSYMBOL_continue_statement = 93,        /* continue_statement  */
  YYSYMBOL_call_statement = 94,            /* call_statement  */
  YYSYMBOL_call_expression = 95            /* call_expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   394

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  246

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,     2,
      42,    43,    36,    34,    39,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    38,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    44,    44,    52,    53,    59,    60,    61,    64,    68,
      76,    80,    88,    92,    96,    96,   103,   107,   115,   114,
     126,   129,   135,   140,   145,   150,   155,   166,   180,   192,
     212,   219,   221,   222,   228,   232,   236,   243,   244,   250,
     254,   258,   266,   272,   279,   285,   291,   299,   303,   307,
     311,   315,   319,   324,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   348,   355,   358,
     364,   365,   371,   376,   380,   387,   394,   464,   468,   472,
     476,   480,   484,   488,   492,   496,   500,   504,   508,   512,
     516,   520,   525,   530,   534,   644,   647,   650,   651,   658,
     665,   669,   673,   681,   689,   693,   701,   700,   714,   715,
     721,   728,   731,   737,   736,   754,   753,   770,   775,   780,
     785,   790,   796,   802,   808
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "EQ", "NE",
  "LT", "LE", "GT", "GE", "UMINUS", "STRUCT_TOK", "DOT", "PTR_OP", "IF",
  "ELSE", "SWITCH", "CASE", "DEFAULT", "WHILE", "FOR", "BREAK", "CONTINUE",
  "FUNC", "INPUT", "OUTPUT", "RETURN", "INTEGER", "IDENTIFIER", "TEXT",
  "CHAR", "CHAR_CONST", "LBRACK", "RBRACK", "'+'", "'-'", "'*'", "'/'",
  "';'", "','", "'{'", "'}'", "'('", "')'", "'='", "'&'", "':'", "$accept",
  "program", "function_declaration_list", "function_declaration",
  "dims_decl", "dims_idx", "declaration", "$@1", "struct_var_list",
  "struct_definition", "$@2", "struct_member_list", "struct_member_line",
  "postfix_lvalue", "lvalue", "variable_list", "decl_item_int",
  "variable_list_char", "decl_item_char", "function", "function_head",
  "parameter_list", "statement", "block", "declaration_list",
  "statement_list", "assignment_statement", "expression", "argument_list",
  "expression_list", "input_statement", "output_statement",
  "return_statement", "if_statement", "switch_statement", "$@3",
  "case_list", "case_item", "default_list", "while_statement", "$@4",
  "for_statement", "$@5", "opt_statement", "opt_expression",
  "break_statement", "continue_statement", "call_statement",
  "call_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      64,  -117,    11,    12,  -117,    27,     9,    18,  -117,  -117,
    -117,  -117,    30,   -15,    63,   104,  -117,    56,    19,    90,
     107,  -117,  -117,  -117,    65,    93,    91,  -117,  -117,    41,
      98,    88,    91,  -117,  -117,    42,   137,  -117,   141,   101,
     119,   149,   140,  -117,  -117,   112,  -117,   140,  -117,  -117,
    -117,    77,   138,  -117,   147,  -117,   153,     1,   158,  -117,
     172,  -117,  -117,  -117,  -117,   173,   174,   178,   170,  -117,
    -117,  -117,   219,   -16,   181,    84,  -117,  -117,    41,   186,
     176,   179,   187,   192,  -117,  -117,   200,    31,    75,   -19,
      42,   208,  -117,    -2,   193,  -117,  -117,   163,   204,   212,
     213,   214,  -117,  -117,  -117,  -117,   215,   216,   218,   230,
    -117,    87,   231,  -117,  -117,    75,    75,    75,    43,  -117,
    -117,  -117,    22,  -117,  -117,    75,    75,  -117,   189,  -117,
      22,   189,    75,    10,   -21,   -24,   202,   232,    75,    75,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,   229,
     237,  -117,   241,   272,   284,   294,   -18,  -117,   227,    10,
     238,  -117,   334,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,   345,   189,   239,   245,   257,   258,    75,
      75,    75,  -117,   351,   189,   256,   262,   259,   138,  -117,
    -117,    73,   253,  -117,   121,   121,   121,   121,   121,   121,
     124,   124,  -117,  -117,  -117,  -117,    75,  -117,  -117,   357,
     189,   189,  -117,  -117,   266,  -117,   290,   270,   138,   189,
     273,  -117,   189,  -117,  -117,   138,   295,  -117,    43,  -117,
     286,   145,  -117,   271,   276,   277,  -117,   275,  -117,   247,
     247,  -117,   138,   113,   191,  -117
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    43,     0,     0,    44,     0,     0,     0,     3,     6,
       7,     5,     0,    34,     0,     0,    32,    14,    39,     0,
       0,    37,     1,     4,    53,     0,    36,    35,    12,     0,
       0,     0,    41,    40,    13,     0,     0,    47,     0,     0,
       0,     0,    34,    33,    16,     0,    20,    39,    38,    49,
      50,     0,     0,     8,     0,    15,     0,     0,     0,    48,
       0,    68,    42,     9,    17,     0,     0,     0,     0,    21,
      51,    52,     0,     0,     0,     0,    19,    66,     0,     0,
       0,     0,     0,     0,   121,   122,     0,     0,     0,    28,
       0,     0,    69,    31,     0,    70,    65,     0,     0,     0,
       0,     0,    59,    60,    61,    62,     0,     0,     0,     0,
      22,     0,     0,    23,    14,     0,     0,     0,   118,    99,
      94,    89,    28,   101,    90,     0,     0,    92,   102,    93,
      28,   103,     0,     0,     0,     0,     0,     0,     0,     0,
      67,    71,    54,    55,    56,    58,    63,    64,    57,     0,
       0,    26,     0,     0,     0,     0,    28,   117,     0,     0,
      91,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,    96,     0,     0,     0,
       0,     0,    29,     0,    72,     0,     0,     0,     0,   106,
     113,     0,     0,    88,    82,    83,    84,    85,    86,    87,
      77,    78,    79,    80,    10,   123,     0,    76,    75,     0,
      73,    74,    30,    24,     0,    25,   104,     0,     0,   119,
       0,   124,    98,    11,    27,     0,     0,   114,   118,   105,
       0,   111,   108,     0,     0,     0,   109,     0,   115,     0,
       0,   107,     0,     0,     0,   116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,  -117,   310,   -11,    -9,   252,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,   -69,  -117,   296,  -117,   291,  -117,
    -117,  -117,   -96,   -52,  -117,   -72,  -116,   -82,   175,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,   102,  -117,  -117,
    -117,  -117,  -117,   108,  -117,  -117,  -117,  -117,  -117
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,    26,   135,     9,    30,    45,    10,
      31,    57,    69,    93,   127,    15,    16,    20,    21,    11,
      12,    39,    95,    96,    72,    97,    98,   174,   175,   176,
      99,   100,   101,   102,   103,   217,   231,   232,   237,   104,
     218,   105,   242,   158,   220,   106,   107,   108,   129
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,   141,   157,    94,    65,   128,   131,    32,   179,    22,
     137,   120,    66,   132,   132,   177,   109,    25,    -2,     1,
     180,     2,   110,   133,   178,   134,   134,   -45,    94,     3,
     138,    67,   120,   153,   154,   155,    32,   121,   130,    13,
      17,   124,    68,   161,   162,   125,     4,    14,     5,    94,
     173,    25,   126,   -95,   132,    18,   183,   184,   121,   122,
     123,   -46,   124,    19,   159,     1,   125,     2,    36,    42,
      47,   156,    24,   126,   120,     3,   120,    14,    19,    91,
      58,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    27,     4,    37,     5,    38,   -18,   209,   210,   211,
     121,   130,   121,   130,   124,    59,   124,    60,   125,   219,
     125,  -120,   157,   160,    77,   126,   112,   126,    33,   150,
      40,   160,   113,    41,   222,   151,    44,    80,    46,    81,
    -110,  -110,    82,    83,    84,    85,   216,    86,    87,    88,
      51,    89,    28,    29,    52,    34,    35,   141,   141,    91,
      55,    56,    53,    61,  -110,   169,   170,   171,   172,    94,
     171,   172,   230,   235,    77,    49,   227,   243,   244,    50,
      94,    94,    25,   229,    94,    94,    54,    80,    61,    81,
      63,    64,    82,    83,    84,    85,    70,    86,    87,    88,
     245,    89,    77,   163,   164,   165,   166,   167,   168,    91,
      71,    73,    74,    61,   140,    80,    75,    81,    76,   111,
      82,    83,    84,    85,   114,    86,    87,    88,   115,    89,
      77,   116,    78,   169,   170,   171,   172,    91,   119,   117,
      79,    61,  -112,    80,   118,    81,   136,   139,    82,    83,
      84,    85,   142,    86,    87,    88,   181,    89,    77,    90,
     143,   144,   145,   146,   147,    91,   148,   149,   152,    61,
     182,    80,   185,    81,   186,   191,    82,    83,    84,    85,
     179,    86,    87,    88,   187,    89,   163,   164,   165,   166,
     167,   168,   205,    91,   206,   207,   208,    61,   163,   164,
     165,   166,   167,   168,   213,   214,   221,   215,   163,   164,
     165,   166,   167,   168,   224,   225,   169,   170,   171,   172,
     226,   228,   230,   234,   238,   188,   241,    23,   169,   170,
     171,   172,   239,   240,    92,    43,    48,   189,   169,   170,
     171,   172,     0,   236,   192,     0,   233,   190,   163,   164,
     165,   166,   167,   168,     0,     0,     0,     0,     0,   163,
     164,   165,   166,   167,   168,   163,   164,   165,   166,   167,
     168,   163,   164,   165,   166,   167,   168,     0,   169,   170,
     171,   172,     0,     0,     0,     0,     0,   193,   204,   169,
     170,   171,   172,     0,   212,   169,   170,   171,   172,     0,
     223,   169,   170,   171,   172
};

static const yytype_int16 yycheck[] =
{
      52,    97,   118,    72,     3,    87,    88,    18,    32,     0,
      12,     1,    11,    32,    32,    36,    32,    32,     0,     1,
      44,     3,    38,    42,    45,    44,    44,    42,    97,    11,
      32,    30,     1,   115,   116,   117,    47,    27,    28,    28,
      28,    31,    41,   125,   126,    35,    28,    36,    30,   118,
     132,    32,    42,    43,    32,    28,   138,   139,    27,    28,
      29,    42,    31,    36,    42,     1,    35,     3,     3,    28,
      28,    28,    42,    42,     1,    11,     1,    36,    36,    36,
       3,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    28,    28,    28,    30,    30,    40,   179,   180,   181,
      27,    28,    27,    28,    31,    28,    31,    30,    35,   191,
      35,    38,   228,   122,     1,    42,    32,    42,    28,    32,
      27,   130,    38,    32,   206,    38,    28,    14,    40,    16,
      17,    18,    19,    20,    21,    22,   188,    24,    25,    26,
      39,    28,    38,    39,    43,    38,    39,   243,   244,    36,
      38,    39,    33,    40,    41,    34,    35,    36,    37,   228,
      36,    37,    17,    18,     1,    28,   218,   239,   240,    28,
     239,   240,    32,   225,   243,   244,    27,    14,    40,    16,
      33,    28,    19,    20,    21,    22,    28,    24,    25,    26,
     242,    28,     1,     4,     5,     6,     7,     8,     9,    36,
      28,    28,    28,    40,    41,    14,    28,    16,    38,    28,
      19,    20,    21,    22,    28,    24,    25,    26,    42,    28,
       1,    42,     3,    34,    35,    36,    37,    36,    28,    42,
      11,    40,    41,    14,    42,    16,    28,    44,    19,    20,
      21,    22,    38,    24,    25,    26,    44,    28,     1,    30,
      38,    38,    38,    38,    38,    36,    38,    27,    27,    40,
      28,    14,    33,    16,    27,    38,    19,    20,    21,    22,
      32,    24,    25,    26,    33,    28,     4,     5,     6,     7,
       8,     9,    43,    36,    39,    28,    28,    40,     4,     5,
       6,     7,     8,     9,    38,    33,    43,    38,     4,     5,
       6,     7,     8,     9,    38,    15,    34,    35,    36,    37,
      40,    38,    17,    27,    43,    43,    41,     7,    34,    35,
      36,    37,    46,    46,    72,    29,    35,    43,    34,    35,
      36,    37,    -1,   231,   159,    -1,   228,    43,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,     7,     8,     9,     4,     5,     6,     7,     8,
       9,     4,     5,     6,     7,     8,     9,    -1,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    33,    34,
      35,    36,    37,    -1,    33,    34,    35,    36,    37,    -1,
      33,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    11,    28,    30,    48,    49,    50,    53,
      56,    66,    67,    28,    36,    62,    63,    28,    28,    36,
      64,    65,     0,    50,    42,    32,    51,    28,    38,    39,
      54,    57,    51,    28,    38,    39,     3,    28,    30,    68,
      27,    32,    28,    63,    28,    55,    40,    28,    65,    28,
      28,    39,    43,    33,    27,    38,    39,    58,     3,    28,
      30,    40,    70,    33,    28,     3,    11,    30,    41,    59,
      28,    28,    71,    28,    28,    28,    38,     1,     3,    11,
      14,    16,    19,    20,    21,    22,    24,    25,    26,    28,
      30,    36,    53,    60,    61,    69,    70,    72,    73,    77,
      78,    79,    80,    81,    86,    88,    92,    93,    94,    32,
      38,    28,    32,    38,    28,    42,    42,    42,    42,    28,
       1,    27,    28,    29,    31,    35,    42,    61,    74,    95,
      28,    74,    32,    42,    44,    52,    28,    12,    32,    44,
      41,    69,    38,    38,    38,    38,    38,    38,    38,    27,
      32,    38,    27,    74,    74,    74,    28,    73,    90,    42,
      52,    74,    74,     4,     5,     6,     7,     8,     9,    34,
      35,    36,    37,    74,    74,    75,    76,    36,    45,    32,
      44,    44,    28,    74,    74,    33,    27,    33,    43,    43,
      43,    38,    75,    43,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    33,    43,    39,    28,    28,    74,
      74,    74,    33,    38,    33,    38,    70,    82,    87,    74,
      91,    43,    74,    33,    38,    15,    40,    70,    38,    70,
      17,    83,    84,    90,    27,    18,    84,    85,    43,    46,
      46,    41,    89,    72,    72,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    53,    55,    55,    57,    56,
      58,    58,    59,    59,    59,    59,    59,    59,    60,    60,
      60,    61,    62,    62,    63,    63,    63,    64,    64,    65,
      65,    65,    66,    66,    67,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    70,    71,    71,
      72,    72,    73,    73,    73,    73,    73,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    76,    76,    77,
      78,    78,    78,    79,    80,    80,    82,    81,    83,    83,
      84,    85,    85,    87,    86,    89,    88,    90,    90,    91,
      91,    92,    93,    94,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     3,     4,
       3,     4,     3,     3,     0,     5,     1,     3,     0,     7,
       0,     2,     3,     3,     6,     6,     4,     7,     1,     3,
       4,     1,     1,     3,     1,     2,     2,     1,     3,     1,
       2,     2,     5,     1,     1,     2,     2,     1,     3,     2,
       2,     4,     4,     0,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     2,     2,     1,     1,     4,     0,     2,
       1,     2,     3,     4,     4,     4,     4,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     2,     1,     1,     1,     0,     1,     1,     3,     2,
       2,     2,     2,     2,     5,     7,     0,     9,     1,     2,
       4,     0,     3,     0,     6,     0,    10,     1,     0,     1,
       0,     1,     1,     4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: function_declaration_list  */
#line 45 "mini.y"
{
	tac_last=(yyvsp[0].tac);
	tac_complete();
}
#line 1374 "mini.y.c"
    break;

  case 4: /* function_declaration_list: function_declaration_list function_declaration  */
#line 54 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1382 "mini.y.c"
    break;

  case 8: /* dims_decl: LBRACK INTEGER RBRACK  */
#line 65 "mini.y"
{
	(yyval.exp)=mk_exp(NULL,mk_const(atoi((yyvsp[-1].string))),NULL);
}
#line 1390 "mini.y.c"
    break;

  case 9: /* dims_decl: dims_decl LBRACK INTEGER RBRACK  */
#line 69 "mini.y"
{
	EXP *node = mk_exp(NULL,mk_const(atoi((yyvsp[-1].string))),NULL);
	node->next = (yyvsp[-3].exp);
	(yyval.exp) = node;
}
#line 1400 "mini.y.c"
    break;

  case 10: /* dims_idx: LBRACK expression RBRACK  */
#line 77 "mini.y"
{
	(yyval.exp) = mk_exp(NULL,(yyvsp[-1].exp)->ret,(yyvsp[-1].exp)->tac);
}
#line 1408 "mini.y.c"
    break;

  case 11: /* dims_idx: dims_idx LBRACK expression RBRACK  */
#line 81 "mini.y"
{
	EXP*node = mk_exp(NULL,(yyvsp[-1].exp)->ret,(yyvsp[-1].exp)->tac);
	node->next = (yyvsp[-3].exp);
	(yyval.exp) = node;
}
#line 1418 "mini.y.c"
    break;

  case 12: /* declaration: INT variable_list ';'  */
#line 89 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1426 "mini.y.c"
    break;

  case 13: /* declaration: CHAR variable_list_char ';'  */
#line 93 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1434 "mini.y.c"
    break;

  case 14: /* $@1: %empty  */
#line 96 "mini.y"
                        {g_cur_struct = (yyvsp[0].string);}
#line 1440 "mini.y.c"
    break;

  case 15: /* declaration: STRUCT_TOK IDENTIFIER $@1 struct_var_list ';'  */
#line 97 "mini.y"
{
	(yyval.tac) = (yyvsp[-1].tac);
	g_cur_struct = NULL;
}
#line 1449 "mini.y.c"
    break;

  case 16: /* struct_var_list: IDENTIFIER  */
#line 104 "mini.y"
{ 
	(yyval.tac) = declare_struct((yyvsp[0].string), g_cur_struct); 
}
#line 1457 "mini.y.c"
    break;

  case 17: /* struct_var_list: struct_var_list ',' IDENTIFIER  */
#line 108 "mini.y"
{ 
	(yyval.tac) = join_tac((yyvsp[-2].tac), declare_struct((yyvsp[0].string), g_cur_struct)); 
}
#line 1465 "mini.y.c"
    break;

  case 18: /* $@2: %empty  */
#line 115 "mini.y"
{
	begin_struct((yyvsp[0].string));
}
#line 1473 "mini.y.c"
    break;

  case 19: /* struct_definition: STRUCT_TOK IDENTIFIER $@2 '{' struct_member_list '}' ';'  */
#line 119 "mini.y"
{
	end_struct(NULL);
	(yyval.tac) = NULL;
}
#line 1482 "mini.y.c"
    break;

  case 20: /* struct_member_list: %empty  */
#line 126 "mini.y"
{
	 (yyval.tac) = NULL;
}
#line 1490 "mini.y.c"
    break;

  case 21: /* struct_member_list: struct_member_list struct_member_line  */
#line 130 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-1].tac),(yyvsp[0].tac));
}
#line 1498 "mini.y.c"
    break;

  case 22: /* struct_member_line: INT IDENTIFIER ';'  */
#line 136 "mini.y"
{
	add_struct_member(NULL,SYM_INT,(yyvsp[-1].string),4);
	(yyval.tac) = NULL;
}
#line 1507 "mini.y.c"
    break;

  case 23: /* struct_member_line: CHAR IDENTIFIER ';'  */
#line 141 "mini.y"
{ 
	add_struct_member(NULL, SYM_CHAR, (yyvsp[-1].string),1); 
	(yyval.tac) = NULL; 
}
#line 1516 "mini.y.c"
    break;

  case 24: /* struct_member_line: INT IDENTIFIER LBRACK INTEGER RBRACK ';'  */
#line 146 "mini.y"
{
	add_struct_array_member(NULL,SYM_INT,(yyvsp[-4].string),atoi((yyvsp[-2].string)));
	(yyval.tac) = NULL;
}
#line 1525 "mini.y.c"
    break;

  case 25: /* struct_member_line: CHAR IDENTIFIER LBRACK INTEGER RBRACK ';'  */
#line 151 "mini.y"
{
	add_struct_array_member(NULL,SYM_CHAR,(yyvsp[-4].string),atoi((yyvsp[-2].string)));
	(yyval.tac)=NULL;
}
#line 1534 "mini.y.c"
    break;

  case 26: /* struct_member_line: STRUCT_TOK IDENTIFIER IDENTIFIER ';'  */
#line 156 "mini.y"
{
	STRUCT* stype = find_struct((yyvsp[-2].string));
	if(!stype)
		error("not defined struct");
	SYM*s = mk_sym();
	s->type = SYM_STRUCT;
	s->etc = stype;
	add_struct_struct_member(NULL,s,(yyvsp[-1].string),1);
	(yyval.tac)=NULL;
}
#line 1549 "mini.y.c"
    break;

  case 27: /* struct_member_line: STRUCT_TOK IDENTIFIER IDENTIFIER LBRACK INTEGER RBRACK ';'  */
#line 167 "mini.y"
{
	STRUCT* stype = find_struct((yyvsp[-5].string));
	if(!stype)
		error("not defined struct");
	SYM*s = mk_sym();
	s->type = SYM_STRUCT;
	s->etc = stype;
	add_struct_struct_member(NULL,s,(yyvsp[-4].string),atoi((yyvsp[-2].string)));
	(yyval.tac) = NULL;
}
#line 1564 "mini.y.c"
    break;

  case 28: /* postfix_lvalue: IDENTIFIER  */
#line 181 "mini.y"
{
	SYM *var = get_var((yyvsp[0].string));
	SYM*addr = mk_tmp();
	TAC*decl = mk_tac(TAC_VAR,addr,NULL,NULL);
	TAC*addr_tac = mk_tac(TAC_ADDR,addr,var,NULL);
	addr_tac->prev = decl;

	addr->type = var->type;
	addr->etc = var->etc;
	(yyval.exp) = mk_exp(NULL,addr,addr_tac);
}
#line 1580 "mini.y.c"
    break;

  case 29: /* postfix_lvalue: postfix_lvalue DOT IDENTIFIER  */
#line 193 "mini.y"
{
	// printf("[DEBUG] . access: %s\n", $3);
    // if (!$1 || !$1->ret)
    //     printf("[DEBUG] $1 or $1->ret is NULL!\n");
    // else
    //     printf("[DEBUG] base type=%d name=%s\n", $1->ret->type, $1->ret->name);
	// int offset = get_struct_offset($1->ret,$3);
	STRUCT_MEMBER *mem = get_struct_member((yyvsp[-2].exp)->ret,(yyvsp[0].string));
	(yyval.exp) = make_struct_field_addr((yyvsp[-2].exp),mem->offset);
	if (mem->type == SYM_STRUCT) {
		(yyval.exp)->ret->type = SYM_STRUCT;
		(yyval.exp)->ret->etc  = mem->etc;                 // STRUCT*
	} else {
		// 标量成员（int/char）作为“数组基址”的元素类型
		(yyval.exp)->ret->type = SYM_VAR;                  // 地址里是一个标量
		(yyval.exp)->ret->etc  = malloc(sizeof(int));
		*((int*)(yyval.exp)->ret->etc) = mem->type;        // 存 SYM_INT 或 SYM_CHAR
	}
}
#line 1604 "mini.y.c"
    break;

  case 30: /* postfix_lvalue: postfix_lvalue LBRACK expression RBRACK  */
#line 213 "mini.y"
{
	// printf("come in\n");
	(yyval.exp) = make_array_elem_addr((yyvsp[-3].exp),(yyvsp[-1].exp));
}
#line 1613 "mini.y.c"
    break;

  case 33: /* variable_list: variable_list ',' decl_item_int  */
#line 223 "mini.y"
{ 
	(yyval.tac) = join_tac((yyvsp[-2].tac), (yyvsp[0].tac)); 
}
#line 1621 "mini.y.c"
    break;

  case 34: /* decl_item_int: IDENTIFIER  */
#line 229 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_INT); 
}
#line 1629 "mini.y.c"
    break;

  case 35: /* decl_item_int: '*' IDENTIFIER  */
#line 233 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_PTR); 
}
#line 1637 "mini.y.c"
    break;

  case 36: /* decl_item_int: IDENTIFIER dims_decl  */
#line 237 "mini.y"
{
	(yyval.tac) = declare_array_typed((yyvsp[-1].string),SYM_INT,(yyvsp[0].exp));
}
#line 1645 "mini.y.c"
    break;

  case 38: /* variable_list_char: variable_list_char ',' decl_item_char  */
#line 245 "mini.y"
{ 
	(yyval.tac) = join_tac((yyvsp[-2].tac), (yyvsp[0].tac)); 
}
#line 1653 "mini.y.c"
    break;

  case 39: /* decl_item_char: IDENTIFIER  */
#line 251 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_CHAR); 
}
#line 1661 "mini.y.c"
    break;

  case 40: /* decl_item_char: '*' IDENTIFIER  */
#line 255 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_PTR); 
}
#line 1669 "mini.y.c"
    break;

  case 41: /* decl_item_char: IDENTIFIER dims_decl  */
#line 259 "mini.y"
{
	(yyval.tac) = declare_array_typed((yyvsp[-1].string),SYM_CHAR,(yyvsp[0].exp));
}
#line 1677 "mini.y.c"
    break;

  case 42: /* function: function_head '(' parameter_list ')' block  */
#line 267 "mini.y"
{
	(yyval.tac)=do_func((yyvsp[-4].sym), (yyvsp[-2].tac), (yyvsp[0].tac));
	scope=0; /* Leave local scope. */
	sym_tab_local=NULL; /* Clear local symbol table. */
}
#line 1687 "mini.y.c"
    break;

  case 43: /* function: error  */
#line 273 "mini.y"
{
	error("Bad function syntax");
	(yyval.tac)=NULL;
}
#line 1696 "mini.y.c"
    break;

  case 44: /* function_head: IDENTIFIER  */
#line 280 "mini.y"
{
	(yyval.sym)=declare_func((yyvsp[0].string));
	scope=1; /* Enter local scope. */
	sym_tab_local=NULL; /* Init local symbol table. */
}
#line 1706 "mini.y.c"
    break;

  case 45: /* function_head: INT IDENTIFIER  */
#line 286 "mini.y"
{
	(yyval.sym) = declare_func((yyvsp[0].string));
	scope = 1;
	sym_tab_local = NULL;
}
#line 1716 "mini.y.c"
    break;

  case 46: /* function_head: CHAR IDENTIFIER  */
#line 292 "mini.y"
{
	(yyval.sym) = declare_func((yyvsp[0].string));
	scope = 1;
	sym_tab_local = NULL;
}
#line 1726 "mini.y.c"
    break;

  case 47: /* parameter_list: IDENTIFIER  */
#line 300 "mini.y"
{
	(yyval.tac)=declare_para((yyvsp[0].string));
}
#line 1734 "mini.y.c"
    break;

  case 48: /* parameter_list: parameter_list ',' IDENTIFIER  */
#line 304 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), declare_para((yyvsp[0].string)));
}
#line 1742 "mini.y.c"
    break;

  case 49: /* parameter_list: INT IDENTIFIER  */
#line 308 "mini.y"
{
	(yyval.tac) = declare_para((yyvsp[0].string));
}
#line 1750 "mini.y.c"
    break;

  case 50: /* parameter_list: CHAR IDENTIFIER  */
#line 312 "mini.y"
{
	(yyval.tac) = declare_para((yyvsp[0].string));
}
#line 1758 "mini.y.c"
    break;

  case 51: /* parameter_list: parameter_list ',' INT IDENTIFIER  */
#line 316 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-3].tac),declare_para((yyvsp[0].string)));
}
#line 1766 "mini.y.c"
    break;

  case 52: /* parameter_list: parameter_list ',' CHAR IDENTIFIER  */
#line 320 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-3].tac),declare_para((yyvsp[0].string)));
}
#line 1774 "mini.y.c"
    break;

  case 53: /* parameter_list: %empty  */
#line 324 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1782 "mini.y.c"
    break;

  case 66: /* statement: error  */
#line 342 "mini.y"
{
	error("Bad statement syntax");
	(yyval.tac)=NULL;
}
#line 1791 "mini.y.c"
    break;

  case 67: /* block: '{' declaration_list statement_list '}'  */
#line 349 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[-1].tac));
}
#line 1799 "mini.y.c"
    break;

  case 68: /* declaration_list: %empty  */
#line 355 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1807 "mini.y.c"
    break;

  case 69: /* declaration_list: declaration_list declaration  */
#line 359 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1815 "mini.y.c"
    break;

  case 71: /* statement_list: statement_list statement  */
#line 366 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1823 "mini.y.c"
    break;

  case 72: /* assignment_statement: lvalue '=' expression  */
#line 372 "mini.y"
{
	printf("lvalue assign\n");
	(yyval.tac)=do_assign_lvalue((yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1832 "mini.y.c"
    break;

  case 73: /* assignment_statement: IDENTIFIER dims_idx '=' expression  */
#line 377 "mini.y"
{
	(yyval.tac) = do_array_store(get_var((yyvsp[-3].string)),(yyvsp[-2].exp),(yyvsp[0].exp));
}
#line 1840 "mini.y.c"
    break;

  case 74: /* assignment_statement: '*' IDENTIFIER '=' expression  */
#line 381 "mini.y"
{
	SYM *ptr = get_var((yyvsp[-2].string));
	TAC *store = mk_tac(TAC_STORE, ptr, (yyvsp[0].exp)->ret, NULL);
	store->prev = (yyvsp[0].exp)->tac;
	(yyval.tac) = store;
}
#line 1851 "mini.y.c"
    break;

  case 75: /* assignment_statement: IDENTIFIER '=' '&' IDENTIFIER  */
#line 388 "mini.y"
{
    SYM *dst = get_var((yyvsp[-3].string));
    SYM *src = get_var((yyvsp[0].string));
    TAC *addr = mk_tac(TAC_ADDR, dst, src, NULL);
    (yyval.tac) = addr;
}
#line 1862 "mini.y.c"
    break;

  case 76: /* assignment_statement: IDENTIFIER '=' '*' IDENTIFIER  */
#line 395 "mini.y"
{
    SYM *dst = get_var((yyvsp[-3].string));
    SYM *src = get_var((yyvsp[0].string));
    TAC *load = mk_tac(TAC_LOAD, dst, src, NULL);
    (yyval.tac) = load;
}
#line 1873 "mini.y.c"
    break;

  case 77: /* expression: expression '+' expression  */
#line 465 "mini.y"
{
    (yyval.exp) = do_bin(TAC_ADD, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1881 "mini.y.c"
    break;

  case 78: /* expression: expression '-' expression  */
#line 469 "mini.y"
{
    (yyval.exp) = do_bin(TAC_SUB, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1889 "mini.y.c"
    break;

  case 79: /* expression: expression '*' expression  */
#line 473 "mini.y"
{
    (yyval.exp) = do_bin(TAC_MUL, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1897 "mini.y.c"
    break;

  case 80: /* expression: expression '/' expression  */
#line 477 "mini.y"
{
    (yyval.exp) = do_bin(TAC_DIV, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1905 "mini.y.c"
    break;

  case 81: /* expression: '-' expression  */
#line 481 "mini.y"
{
    (yyval.exp) = do_un(TAC_NEG, (yyvsp[0].exp));
}
#line 1913 "mini.y.c"
    break;

  case 82: /* expression: expression EQ expression  */
#line 485 "mini.y"
{
    (yyval.exp) = do_cmp(TAC_EQ, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1921 "mini.y.c"
    break;

  case 83: /* expression: expression NE expression  */
#line 489 "mini.y"
{
    (yyval.exp) = do_cmp(TAC_NE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1929 "mini.y.c"
    break;

  case 84: /* expression: expression LT expression  */
#line 493 "mini.y"
{
    (yyval.exp) = do_cmp(TAC_LT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1937 "mini.y.c"
    break;

  case 85: /* expression: expression LE expression  */
#line 497 "mini.y"
{
    (yyval.exp) = do_cmp(TAC_LE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1945 "mini.y.c"
    break;

  case 86: /* expression: expression GT expression  */
#line 501 "mini.y"
{
    (yyval.exp) = do_cmp(TAC_GT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1953 "mini.y.c"
    break;

  case 87: /* expression: expression GE expression  */
#line 505 "mini.y"
{
    (yyval.exp) = do_cmp(TAC_GE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1961 "mini.y.c"
    break;

  case 88: /* expression: '(' expression ')'  */
#line 509 "mini.y"
{
    (yyval.exp) = (yyvsp[-1].exp);
}
#line 1969 "mini.y.c"
    break;

  case 89: /* expression: INTEGER  */
#line 513 "mini.y"
{
    (yyval.exp) = mk_exp(NULL, mk_const(atoi((yyvsp[0].string))), NULL);
}
#line 1977 "mini.y.c"
    break;

  case 90: /* expression: CHAR_CONST  */
#line 517 "mini.y"
{
    (yyval.exp) = mk_exp(NULL, mk_char((yyvsp[0].string)[1]), NULL);
}
#line 1985 "mini.y.c"
    break;

  case 91: /* expression: IDENTIFIER dims_idx  */
#line 521 "mini.y"
{
    /* 纯数组访问（a[i][j]这种），你原来的实现 */
    (yyval.exp) = do_array_load(get_var((yyvsp[-1].string)), (yyvsp[0].exp));
}
#line 1994 "mini.y.c"
    break;

  case 92: /* expression: lvalue  */
#line 526 "mini.y"
{
    /* 统一右值加载：c1.num, c1.grp[2].stu[3].name[0] 全部走这里 */
    (yyval.exp) = do_load_lvalue((yyvsp[0].exp));
}
#line 2003 "mini.y.c"
    break;

  case 93: /* expression: call_expression  */
#line 531 "mini.y"
{
    (yyval.exp) = (yyvsp[0].exp);
}
#line 2011 "mini.y.c"
    break;

  case 94: /* expression: error  */
#line 535 "mini.y"
{
    error("Bad expression syntax");
    (yyval.exp) = mk_exp(NULL, NULL, NULL);
}
#line 2020 "mini.y.c"
    break;

  case 95: /* argument_list: %empty  */
#line 644 "mini.y"
{
	(yyval.exp)=NULL;
}
#line 2028 "mini.y.c"
    break;

  case 98: /* expression_list: expression_list ',' expression  */
#line 652 "mini.y"
{
	(yyvsp[0].exp)->next=(yyvsp[-2].exp);
	(yyval.exp)=(yyvsp[0].exp);
}
#line 2037 "mini.y.c"
    break;

  case 99: /* input_statement: INPUT IDENTIFIER  */
#line 659 "mini.y"
{
	(yyval.tac)=do_input(get_var((yyvsp[0].string)));
}
#line 2045 "mini.y.c"
    break;

  case 100: /* output_statement: OUTPUT IDENTIFIER  */
#line 666 "mini.y"
{
	(yyval.tac)=do_output(get_var((yyvsp[0].string)));
}
#line 2053 "mini.y.c"
    break;

  case 101: /* output_statement: OUTPUT TEXT  */
#line 670 "mini.y"
{
	(yyval.tac)=do_output(mk_text((yyvsp[0].string)));
}
#line 2061 "mini.y.c"
    break;

  case 102: /* output_statement: OUTPUT expression  */
#line 674 "mini.y"
{
	TAC*t = mk_tac(TAC_OUTPUT,(yyvsp[0].exp)->ret,NULL,NULL);
	t->prev = (yyvsp[0].exp)->tac;
	(yyval.tac) = t;
}
#line 2071 "mini.y.c"
    break;

  case 103: /* return_statement: RETURN expression  */
#line 682 "mini.y"
{
	TAC *t=mk_tac(TAC_RETURN, (yyvsp[0].exp)->ret, NULL, NULL);
	t->prev=(yyvsp[0].exp)->tac;
	(yyval.tac)=t;
}
#line 2081 "mini.y.c"
    break;

  case 104: /* if_statement: IF '(' expression ')' block  */
#line 690 "mini.y"
{
	(yyval.tac)=do_if((yyvsp[-2].exp), (yyvsp[0].tac));
}
#line 2089 "mini.y.c"
    break;

  case 105: /* if_statement: IF '(' expression ')' block ELSE block  */
#line 694 "mini.y"
{
	(yyval.tac)=do_test((yyvsp[-4].exp), (yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 2097 "mini.y.c"
    break;

  case 106: /* $@3: %empty  */
#line 701 "mini.y"
    {
      g_switch_end = mk_label(mk_lstr(next_label++));
      push_loop_labels(NULL, g_switch_end);  // 同for, 只有end
    }
#line 2106 "mini.y.c"
    break;

  case 107: /* switch_statement: SWITCH '(' expression ')' $@3 '{' case_list default_list '}'  */
#line 706 "mini.y"
    {
      (yyval.tac) = do_switch((yyvsp[-6].exp), (yyvsp[-2].tac), (yyvsp[-1].tac), g_switch_end);
      pop_loop_labels();
      g_switch_end = NULL;
    }
#line 2116 "mini.y.c"
    break;

  case 108: /* case_list: case_item  */
#line 714 "mini.y"
           { (yyval.tac) = (yyvsp[0].tac); }
#line 2122 "mini.y.c"
    break;

  case 109: /* case_list: case_list case_item  */
#line 716 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-1].tac),(yyvsp[0].tac));
}
#line 2130 "mini.y.c"
    break;

  case 110: /* case_item: CASE INTEGER ':' statement_list  */
#line 722 "mini.y"
{
	(yyval.tac) = do_case(atoi((yyvsp[-2].string)),(yyvsp[0].tac));
}
#line 2138 "mini.y.c"
    break;

  case 111: /* default_list: %empty  */
#line 728 "mini.y"
{
	 (yyval.tac) = NULL; 
}
#line 2146 "mini.y.c"
    break;

  case 112: /* default_list: DEFAULT ':' statement_list  */
#line 732 "mini.y"
{ 
	(yyval.tac) = (yyvsp[0].tac); 
}
#line 2154 "mini.y.c"
    break;

  case 113: /* $@4: %empty  */
#line 737 "mini.y"
{
	g_for_start = mk_label(mk_lstr(next_label++));
    g_for_cont  = mk_label(mk_lstr(next_label++));
    g_for_end   = mk_label(mk_lstr(next_label++));
    push_loop_labels(g_for_cont, g_for_end);
}
#line 2165 "mini.y.c"
    break;

  case 114: /* while_statement: WHILE '(' expression ')' $@4 block  */
#line 744 "mini.y"
{
	(yyval.tac)=do_while((yyvsp[-3].exp), (yyvsp[0].tac),g_for_start,g_for_cont,g_for_end);
	pop_loop_labels();
	g_for_start = g_for_cont = g_for_end = NULL;
}
#line 2175 "mini.y.c"
    break;

  case 115: /* $@5: %empty  */
#line 754 "mini.y"
    {
      g_for_start = mk_label(mk_lstr(next_label++));
      g_for_cont  = mk_label(mk_lstr(next_label++));
      g_for_end   = mk_label(mk_lstr(next_label++));
      push_loop_labels(g_for_cont, g_for_end);
    }
#line 2186 "mini.y.c"
    break;

  case 116: /* for_statement: FOR '(' opt_statement ';' opt_expression ';' opt_statement ')' $@5 block  */
#line 761 "mini.y"
    {
      (yyval.tac) = do_for((yyvsp[-7].tac), (yyvsp[-5].exp), (yyvsp[-3].tac), (yyvsp[0].tac), g_for_start, g_for_cont, g_for_end);
      pop_loop_labels();
      g_for_start = g_for_cont = g_for_end = NULL;
    }
#line 2196 "mini.y.c"
    break;

  case 117: /* opt_statement: assignment_statement  */
#line 771 "mini.y"
{
	(yyval.tac) = (yyvsp[0].tac);
}
#line 2204 "mini.y.c"
    break;

  case 118: /* opt_statement: %empty  */
#line 775 "mini.y"
{
	(yyval.tac) = NULL;
}
#line 2212 "mini.y.c"
    break;

  case 119: /* opt_expression: expression  */
#line 781 "mini.y"
{
	(yyval.exp) = (yyvsp[0].exp);
}
#line 2220 "mini.y.c"
    break;

  case 120: /* opt_expression: %empty  */
#line 785 "mini.y"
{
	(yyval.exp) = NULL;
}
#line 2228 "mini.y.c"
    break;

  case 121: /* break_statement: BREAK  */
#line 791 "mini.y"
{
	(yyval.tac)=do_break();
}
#line 2236 "mini.y.c"
    break;

  case 122: /* continue_statement: CONTINUE  */
#line 797 "mini.y"
{
	(yyval.tac)=do_continue();
}
#line 2244 "mini.y.c"
    break;

  case 123: /* call_statement: IDENTIFIER '(' argument_list ')'  */
#line 803 "mini.y"
{
	(yyval.tac)=do_call((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 2252 "mini.y.c"
    break;

  case 124: /* call_expression: IDENTIFIER '(' argument_list ')'  */
#line 809 "mini.y"
{
	(yyval.exp)=do_call_ret((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 2260 "mini.y.c"
    break;


#line 2264 "mini.y.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 814 "mini.y"


void yyerror(char* msg) 
{
	fprintf(stderr, "%s: line %d\n", msg, yylineno);
	exit(0);
}

