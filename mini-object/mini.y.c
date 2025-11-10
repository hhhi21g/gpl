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


#line 87 "mini.y.c"

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
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_SWITCH = 13,                    /* SWITCH  */
  YYSYMBOL_CASE = 14,                      /* CASE  */
  YYSYMBOL_DEFAULT = 15,                   /* DEFAULT  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_BREAK = 18,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 19,                  /* CONTINUE  */
  YYSYMBOL_FUNC = 20,                      /* FUNC  */
  YYSYMBOL_INPUT = 21,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 22,                    /* OUTPUT  */
  YYSYMBOL_RETURN = 23,                    /* RETURN  */
  YYSYMBOL_INTEGER = 24,                   /* INTEGER  */
  YYSYMBOL_IDENTIFIER = 25,                /* IDENTIFIER  */
  YYSYMBOL_TEXT = 26,                      /* TEXT  */
  YYSYMBOL_CHAR = 27,                      /* CHAR  */
  YYSYMBOL_CHAR_CONST = 28,                /* CHAR_CONST  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* ';'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* '='  */
  YYSYMBOL_40_ = 40,                       /* '&'  */
  YYSYMBOL_41_ = 41,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_function_declaration_list = 44, /* function_declaration_list  */
  YYSYMBOL_function_declaration = 45,      /* function_declaration  */
  YYSYMBOL_declaration = 46,               /* declaration  */
  YYSYMBOL_variable_list = 47,             /* variable_list  */
  YYSYMBOL_decl_item_int = 48,             /* decl_item_int  */
  YYSYMBOL_variable_list_char = 49,        /* variable_list_char  */
  YYSYMBOL_decl_item_char = 50,            /* decl_item_char  */
  YYSYMBOL_function = 51,                  /* function  */
  YYSYMBOL_function_head = 52,             /* function_head  */
  YYSYMBOL_parameter_list = 53,            /* parameter_list  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_block = 55,                     /* block  */
  YYSYMBOL_declaration_list = 56,          /* declaration_list  */
  YYSYMBOL_statement_list = 57,            /* statement_list  */
  YYSYMBOL_assignment_statement = 58,      /* assignment_statement  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_argument_list = 60,             /* argument_list  */
  YYSYMBOL_expression_list = 61,           /* expression_list  */
  YYSYMBOL_input_statement = 62,           /* input_statement  */
  YYSYMBOL_output_statement = 63,          /* output_statement  */
  YYSYMBOL_return_statement = 64,          /* return_statement  */
  YYSYMBOL_if_statement = 65,              /* if_statement  */
  YYSYMBOL_switch_statement = 66,          /* switch_statement  */
  YYSYMBOL_67_1 = 67,                      /* $@1  */
  YYSYMBOL_case_list = 68,                 /* case_list  */
  YYSYMBOL_case_item = 69,                 /* case_item  */
  YYSYMBOL_default_list = 70,              /* default_list  */
  YYSYMBOL_while_statement = 71,           /* while_statement  */
  YYSYMBOL_72_2 = 72,                      /* $@2  */
  YYSYMBOL_for_statement = 73,             /* for_statement  */
  YYSYMBOL_74_3 = 74,                      /* $@3  */
  YYSYMBOL_opt_statement = 75,             /* opt_statement  */
  YYSYMBOL_opt_expression = 76,            /* opt_expression  */
  YYSYMBOL_break_statement = 77,           /* break_statement  */
  YYSYMBOL_continue_statement = 78,        /* continue_statement  */
  YYSYMBOL_call_statement = 79,            /* call_statement  */
  YYSYMBOL_call_expression = 80            /* call_expression  */
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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   304

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
       2,     2,     2,     2,     2,     2,     2,     2,    40,     2,
      35,    36,    31,    29,    34,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    33,
       2,    39,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    41,    41,    48,    49,    55,    56,    59,    63,    70,
      71,    76,    78,    84,    85,    90,    92,    98,   104,   111,
     119,   123,   128,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   152,   159,   162,   168,
     169,   175,   179,   186,   193,   202,   206,   210,   214,   218,
     222,   226,   230,   234,   238,   242,   246,   250,   254,   258,
     262,   266,   274,   277,   280,   281,   288,   294,   298,   304,
     312,   316,   324,   323,   337,   338,   344,   351,   354,   360,
     359,   377,   376,   393,   398,   403,   408,   413,   419,   425,
     431
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
  "LT", "LE", "GT", "GE", "UMINUS", "IF", "ELSE", "SWITCH", "CASE",
  "DEFAULT", "WHILE", "FOR", "BREAK", "CONTINUE", "FUNC", "INPUT",
  "OUTPUT", "RETURN", "INTEGER", "IDENTIFIER", "TEXT", "CHAR",
  "CHAR_CONST", "'+'", "'-'", "'*'", "'/'", "';'", "','", "'('", "')'",
  "'{'", "'}'", "'='", "'&'", "':'", "$accept", "program",
  "function_declaration_list", "function_declaration", "declaration",
  "variable_list", "decl_item_int", "variable_list_char", "decl_item_char",
  "function", "function_head", "parameter_list", "statement", "block",
  "declaration_list", "statement_list", "assignment_statement",
  "expression", "argument_list", "expression_list", "input_statement",
  "output_statement", "return_statement", "if_statement",
  "switch_statement", "$@1", "case_list", "case_item", "default_list",
  "while_statement", "$@2", "for_statement", "$@3", "opt_statement",
  "opt_expression", "break_statement", "continue_statement",
  "call_statement", "call_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-87)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     135,   -67,   -21,   -67,   -20,    18,    22,   -67,   -67,   -67,
      -9,   -67,     9,   -26,   -67,   -67,    12,    20,   -67,   -67,
     -67,    17,   -67,   -67,   -21,   -67,   -67,   -20,   -67,    -7,
     -67,   -67,    25,    30,   -67,   -67,   -67,   156,   -67,    35,
      38,    41,    43,   -67,   -67,    59,    40,   183,   -11,    63,
     -67,   -67,   -67,   110,    58,    66,    70,    74,   -67,   -67,
     -67,   -67,    76,    85,    86,   183,   183,   183,   -19,   -67,
     -67,   -67,   -67,   -67,    77,   -67,   183,   183,   272,   -67,
      16,     8,    81,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   215,   223,   231,    83,   -67,    91,    16,   -67,
     264,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   272,    89,   103,   114,   115,   272,   183,    30,   -67,
     -67,    44,   106,   -67,   -16,   -16,   -16,   -16,   -16,   -16,
      50,    50,   -67,   -67,   -67,   183,   -67,   -67,   272,   131,
     108,    30,   272,   120,   -67,   272,    30,   147,   -67,   -19,
     -67,   139,    72,   -67,   129,   125,   127,   -67,   138,   -67,
     179,   179,   -67,    30,    79,   133,   -67
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    18,     0,    19,     0,     0,     0,     3,     6,     5,
       0,    11,     0,     0,     9,    15,     0,     0,    13,     1,
       4,    22,    12,     7,     0,    16,     8,     0,    20,     0,
      10,    14,     0,     0,    21,    37,    17,     0,    35,     0,
       0,     0,     0,    87,    88,     0,     0,     0,     0,     0,
      38,    39,    34,     0,     0,     0,     0,     0,    28,    29,
      30,    31,     0,     0,     0,     0,     0,     0,    84,    66,
      67,    68,    61,    57,    58,    59,     0,     0,    69,    60,
       0,     0,     0,    36,    40,    23,    24,    25,    27,    32,
      33,    26,     0,     0,     0,     0,    83,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    64,     0,    63,     0,     0,    41,     0,     0,    72,
      79,     0,     0,    56,    50,    51,    52,    53,    54,    55,
      45,    46,    47,    48,    89,     0,    44,    43,    42,    70,
       0,     0,    85,     0,    90,    65,     0,     0,    80,    84,
      71,     0,    77,    74,     0,     0,     0,    75,     0,    81,
       0,     0,    73,     0,     0,     0,    82
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   176,   148,   -67,   162,   -67,   161,   -67,
     -67,   -67,   -50,   -33,   -67,   -55,   -66,   -46,    93,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,    37,   -67,   -67,
     -67,   -67,   -67,    45,   -67,   -67,   -67,   -67,   -67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    13,    14,    17,    18,     9,
      10,    29,    51,    52,    37,    53,    54,   111,   112,   113,
      55,    56,    57,    58,    59,   140,   152,   153,   158,    60,
     141,    61,   163,    97,   143,    62,    63,    64,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    78,    96,    84,    11,    15,    95,    23,    24,    72,
      12,    16,    49,   107,   108,   109,   110,    72,    19,    92,
      93,    94,    -2,     1,    80,     2,    21,    32,    81,    33,
      99,   100,    73,    74,    22,   116,    75,    25,    76,   114,
      73,    74,    28,    77,    75,    72,    76,     3,   115,     4,
      34,    77,   -62,    26,    27,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    70,    71,    35,    73,    74,
      65,   138,    75,    66,    76,   142,    67,   -86,    68,    77,
      38,   109,   110,    96,    69,   139,   151,   156,    82,   145,
      39,    85,    40,   -76,   -76,    41,    42,    43,    44,    86,
      45,    46,    47,    87,    48,   164,   165,    88,   148,    89,
      49,    38,    98,   150,    84,    84,    35,   -76,    90,    91,
     117,    39,    81,    40,   121,   134,    41,    42,    43,    44,
     166,    45,    46,    47,    38,    48,     1,   135,     2,   136,
     137,    49,   144,   146,    39,   147,    40,    35,    83,    41,
      42,    43,    44,   149,    45,    46,    47,    38,    48,     2,
       3,   151,     4,   155,    49,   159,   160,    39,   161,    40,
      35,   -78,    41,    42,    43,    44,   162,    45,    46,    47,
      38,    48,    20,     4,    72,    50,    30,    49,    31,   157,
      39,   122,    40,    35,   154,    41,    42,    43,    44,     0,
      45,    46,    47,     0,    48,     0,     0,    73,    74,     0,
      49,    75,     0,    76,     0,     0,    35,     0,    77,   101,
     102,   103,   104,   105,   106,     0,     0,   101,   102,   103,
     104,   105,   106,     0,     0,   101,   102,   103,   104,   105,
     106,     0,     0,     0,   107,   108,   109,   110,     0,     0,
       0,   118,   107,   108,   109,   110,     0,     0,     0,   119,
     107,   108,   109,   110,     0,     0,     0,   120,   101,   102,
     103,   104,   105,   106,     0,     0,   101,   102,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,   108,   109,   110,     0,     0,     0,
     123,   107,   108,   109,   110
};

static const yytype_int16 yycheck[] =
{
      33,    47,    68,    53,    25,    25,    25,    33,    34,     1,
      31,    31,    31,    29,    30,    31,    32,     1,     0,    65,
      66,    67,     0,     1,    35,     3,    35,    34,    39,    36,
      76,    77,    24,    25,    25,    81,    28,    25,    30,    31,
      24,    25,    25,    35,    28,     1,    30,    25,    40,    27,
      25,    35,    36,    33,    34,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    25,    26,    37,    24,    25,
      35,   117,    28,    35,    30,   121,    35,    33,    35,    35,
       1,    31,    32,   149,    25,   118,    14,    15,    25,   135,
      11,    33,    13,    14,    15,    16,    17,    18,    19,    33,
      21,    22,    23,    33,    25,   160,   161,    33,   141,    33,
      31,     1,    35,   146,   164,   165,    37,    38,    33,    33,
      39,    11,    39,    13,    33,    36,    16,    17,    18,    19,
     163,    21,    22,    23,     1,    25,     1,    34,     3,    25,
      25,    31,    36,    12,    11,    37,    13,    37,    38,    16,
      17,    18,    19,    33,    21,    22,    23,     1,    25,     3,
      25,    14,    27,    24,    31,    36,    41,    11,    41,    13,
      37,    38,    16,    17,    18,    19,    38,    21,    22,    23,
       1,    25,     6,    27,     1,    37,    24,    31,    27,   152,
      11,    98,    13,    37,   149,    16,    17,    18,    19,    -1,
      21,    22,    23,    -1,    25,    -1,    -1,    24,    25,    -1,
      31,    28,    -1,    30,    -1,    -1,    37,    -1,    35,     4,
       5,     6,     7,     8,     9,    -1,    -1,     4,     5,     6,
       7,     8,     9,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    36,    29,    30,    31,    32,    -1,    -1,    -1,    36,
      29,    30,    31,    32,    -1,    -1,    -1,    36,     4,     5,
       6,     7,     8,     9,    -1,    -1,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,
      36,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    25,    27,    43,    44,    45,    46,    51,
      52,    25,    31,    47,    48,    25,    31,    49,    50,     0,
      45,    35,    25,    33,    34,    25,    33,    34,    25,    53,
      48,    50,    34,    36,    25,    37,    55,    56,     1,    11,
      13,    16,    17,    18,    19,    21,    22,    23,    25,    31,
      46,    54,    55,    57,    58,    62,    63,    64,    65,    66,
      71,    73,    77,    78,    79,    35,    35,    35,    35,    25,
      25,    26,     1,    24,    25,    28,    30,    35,    59,    80,
      35,    39,    25,    38,    54,    33,    33,    33,    33,    33,
      33,    33,    59,    59,    59,    25,    58,    75,    35,    59,
      59,     4,     5,     6,     7,     8,     9,    29,    30,    31,
      32,    59,    60,    61,    31,    40,    59,    39,    36,    36,
      36,    33,    60,    36,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    36,    34,    25,    25,    59,    55,
      67,    72,    59,    76,    36,    59,    12,    37,    55,    33,
      55,    14,    68,    69,    75,    24,    15,    69,    70,    36,
      41,    41,    38,    74,    57,    57,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    48,    48,    49,    49,    50,    50,    51,    51,    52,
      53,    53,    53,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    56,    56,    57,
      57,    58,    58,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    61,    61,    62,    63,    63,    64,
      65,    65,    67,    66,    68,    68,    69,    70,    70,    72,
      71,    74,    73,    75,    75,    76,    76,    77,    78,    79,
      80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     3,     1,
       3,     1,     2,     1,     3,     1,     2,     5,     1,     1,
       1,     3,     0,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     2,     1,     1,     4,     0,     2,     1,
       2,     3,     4,     4,     4,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     0,     1,     1,     3,     2,     2,     2,     2,
       5,     7,     0,     9,     1,     2,     4,     0,     3,     0,
       6,     0,    10,     1,     0,     1,     0,     1,     1,     4,
       4
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
#line 42 "mini.y"
{
	tac_last=(yyvsp[0].tac);
	tac_complete();
}
#line 1301 "mini.y.c"
    break;

  case 4: /* function_declaration_list: function_declaration_list function_declaration  */
#line 50 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1309 "mini.y.c"
    break;

  case 7: /* declaration: INT variable_list ';'  */
#line 60 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1317 "mini.y.c"
    break;

  case 8: /* declaration: CHAR variable_list_char ';'  */
#line 64 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1325 "mini.y.c"
    break;

  case 10: /* variable_list: variable_list ',' decl_item_int  */
#line 72 "mini.y"
      { (yyval.tac) = join_tac((yyvsp[-2].tac), (yyvsp[0].tac)); }
#line 1331 "mini.y.c"
    break;

  case 11: /* decl_item_int: IDENTIFIER  */
#line 77 "mini.y"
      { (yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_INT); }
#line 1337 "mini.y.c"
    break;

  case 12: /* decl_item_int: '*' IDENTIFIER  */
#line 79 "mini.y"
      { (yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_PTR); }
#line 1343 "mini.y.c"
    break;

  case 14: /* variable_list_char: variable_list_char ',' decl_item_char  */
#line 86 "mini.y"
      { (yyval.tac) = join_tac((yyvsp[-2].tac), (yyvsp[0].tac)); }
#line 1349 "mini.y.c"
    break;

  case 15: /* decl_item_char: IDENTIFIER  */
#line 91 "mini.y"
      { (yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_CHAR); }
#line 1355 "mini.y.c"
    break;

  case 16: /* decl_item_char: '*' IDENTIFIER  */
#line 93 "mini.y"
      { (yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_PTR); }
#line 1361 "mini.y.c"
    break;

  case 17: /* function: function_head '(' parameter_list ')' block  */
#line 99 "mini.y"
{
	(yyval.tac)=do_func((yyvsp[-4].sym), (yyvsp[-2].tac), (yyvsp[0].tac));
	scope=0; /* Leave local scope. */
	sym_tab_local=NULL; /* Clear local symbol table. */
}
#line 1371 "mini.y.c"
    break;

  case 18: /* function: error  */
#line 105 "mini.y"
{
	error("Bad function syntax");
	(yyval.tac)=NULL;
}
#line 1380 "mini.y.c"
    break;

  case 19: /* function_head: IDENTIFIER  */
#line 112 "mini.y"
{
	(yyval.sym)=declare_func((yyvsp[0].string));
	scope=1; /* Enter local scope. */
	sym_tab_local=NULL; /* Init local symbol table. */
}
#line 1390 "mini.y.c"
    break;

  case 20: /* parameter_list: IDENTIFIER  */
#line 120 "mini.y"
{
	(yyval.tac)=declare_para((yyvsp[0].string));
}
#line 1398 "mini.y.c"
    break;

  case 21: /* parameter_list: parameter_list ',' IDENTIFIER  */
#line 124 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), declare_para((yyvsp[0].string)));
}
#line 1406 "mini.y.c"
    break;

  case 22: /* parameter_list: %empty  */
#line 128 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1414 "mini.y.c"
    break;

  case 35: /* statement: error  */
#line 146 "mini.y"
{
	error("Bad statement syntax");
	(yyval.tac)=NULL;
}
#line 1423 "mini.y.c"
    break;

  case 36: /* block: '{' declaration_list statement_list '}'  */
#line 153 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[-1].tac));
}
#line 1431 "mini.y.c"
    break;

  case 37: /* declaration_list: %empty  */
#line 159 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1439 "mini.y.c"
    break;

  case 38: /* declaration_list: declaration_list declaration  */
#line 163 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1447 "mini.y.c"
    break;

  case 40: /* statement_list: statement_list statement  */
#line 170 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1455 "mini.y.c"
    break;

  case 41: /* assignment_statement: IDENTIFIER '=' expression  */
#line 176 "mini.y"
{
	(yyval.tac)=do_assign(get_var((yyvsp[-2].string)), (yyvsp[0].exp));
}
#line 1463 "mini.y.c"
    break;

  case 42: /* assignment_statement: '*' IDENTIFIER '=' expression  */
#line 180 "mini.y"
      {
          SYM *ptr = get_var((yyvsp[-2].string));
          TAC *store = mk_tac(TAC_STORE, ptr, (yyvsp[0].exp)->ret, NULL);
          store->prev = (yyvsp[0].exp)->tac;
          (yyval.tac) = store;
      }
#line 1474 "mini.y.c"
    break;

  case 43: /* assignment_statement: IDENTIFIER '=' '&' IDENTIFIER  */
#line 187 "mini.y"
{
    SYM *dst = get_var((yyvsp[-3].string));
    SYM *src = get_var((yyvsp[0].string));
    TAC *addr = mk_tac(TAC_ADDR, dst, src, NULL);
    (yyval.tac) = addr;
}
#line 1485 "mini.y.c"
    break;

  case 44: /* assignment_statement: IDENTIFIER '=' '*' IDENTIFIER  */
#line 194 "mini.y"
{
    SYM *dst = get_var((yyvsp[-3].string));
    SYM *src = get_var((yyvsp[0].string));
    TAC *load = mk_tac(TAC_LOAD, dst, src, NULL);
    (yyval.tac) = load;
}
#line 1496 "mini.y.c"
    break;

  case 45: /* expression: expression '+' expression  */
#line 203 "mini.y"
{
	(yyval.exp)=do_bin(TAC_ADD, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1504 "mini.y.c"
    break;

  case 46: /* expression: expression '-' expression  */
#line 207 "mini.y"
{
	(yyval.exp)=do_bin(TAC_SUB, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1512 "mini.y.c"
    break;

  case 47: /* expression: expression '*' expression  */
#line 211 "mini.y"
{
	(yyval.exp)=do_bin(TAC_MUL, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1520 "mini.y.c"
    break;

  case 48: /* expression: expression '/' expression  */
#line 215 "mini.y"
{
	(yyval.exp)=do_bin(TAC_DIV, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1528 "mini.y.c"
    break;

  case 49: /* expression: '-' expression  */
#line 219 "mini.y"
{
	(yyval.exp)=do_un(TAC_NEG, (yyvsp[0].exp));
}
#line 1536 "mini.y.c"
    break;

  case 50: /* expression: expression EQ expression  */
#line 223 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_EQ, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1544 "mini.y.c"
    break;

  case 51: /* expression: expression NE expression  */
#line 227 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_NE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1552 "mini.y.c"
    break;

  case 52: /* expression: expression LT expression  */
#line 231 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1560 "mini.y.c"
    break;

  case 53: /* expression: expression LE expression  */
#line 235 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1568 "mini.y.c"
    break;

  case 54: /* expression: expression GT expression  */
#line 239 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1576 "mini.y.c"
    break;

  case 55: /* expression: expression GE expression  */
#line 243 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1584 "mini.y.c"
    break;

  case 56: /* expression: '(' expression ')'  */
#line 247 "mini.y"
{
	(yyval.exp)=(yyvsp[-1].exp);
}
#line 1592 "mini.y.c"
    break;

  case 57: /* expression: INTEGER  */
#line 251 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_const(atoi((yyvsp[0].string))), NULL);
}
#line 1600 "mini.y.c"
    break;

  case 58: /* expression: IDENTIFIER  */
#line 255 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, get_var((yyvsp[0].string)), NULL);
}
#line 1608 "mini.y.c"
    break;

  case 59: /* expression: CHAR_CONST  */
#line 259 "mini.y"
{
	(yyval.exp)=mk_exp(NULL,mk_char((yyvsp[0].string)[1]),NULL);
}
#line 1616 "mini.y.c"
    break;

  case 60: /* expression: call_expression  */
#line 263 "mini.y"
{
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1624 "mini.y.c"
    break;

  case 61: /* expression: error  */
#line 267 "mini.y"
{
	error("Bad expression syntax");
	(yyval.exp)=mk_exp(NULL, NULL, NULL);
}
#line 1633 "mini.y.c"
    break;

  case 62: /* argument_list: %empty  */
#line 274 "mini.y"
{
	(yyval.exp)=NULL;
}
#line 1641 "mini.y.c"
    break;

  case 65: /* expression_list: expression_list ',' expression  */
#line 282 "mini.y"
{
	(yyvsp[0].exp)->next=(yyvsp[-2].exp);
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1650 "mini.y.c"
    break;

  case 66: /* input_statement: INPUT IDENTIFIER  */
#line 289 "mini.y"
{
	(yyval.tac)=do_input(get_var((yyvsp[0].string)));
}
#line 1658 "mini.y.c"
    break;

  case 67: /* output_statement: OUTPUT IDENTIFIER  */
#line 295 "mini.y"
{
	(yyval.tac)=do_output(get_var((yyvsp[0].string)));
}
#line 1666 "mini.y.c"
    break;

  case 68: /* output_statement: OUTPUT TEXT  */
#line 299 "mini.y"
{
	(yyval.tac)=do_output(mk_text((yyvsp[0].string)));
}
#line 1674 "mini.y.c"
    break;

  case 69: /* return_statement: RETURN expression  */
#line 305 "mini.y"
{
	TAC *t=mk_tac(TAC_RETURN, (yyvsp[0].exp)->ret, NULL, NULL);
	t->prev=(yyvsp[0].exp)->tac;
	(yyval.tac)=t;
}
#line 1684 "mini.y.c"
    break;

  case 70: /* if_statement: IF '(' expression ')' block  */
#line 313 "mini.y"
{
	(yyval.tac)=do_if((yyvsp[-2].exp), (yyvsp[0].tac));
}
#line 1692 "mini.y.c"
    break;

  case 71: /* if_statement: IF '(' expression ')' block ELSE block  */
#line 317 "mini.y"
{
	(yyval.tac)=do_test((yyvsp[-4].exp), (yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 1700 "mini.y.c"
    break;

  case 72: /* $@1: %empty  */
#line 324 "mini.y"
    {
      g_switch_end = mk_label(mk_lstr(next_label++));
      push_loop_labels(NULL, g_switch_end);  // 同for, 只有end
    }
#line 1709 "mini.y.c"
    break;

  case 73: /* switch_statement: SWITCH '(' expression ')' $@1 '{' case_list default_list '}'  */
#line 329 "mini.y"
    {
      (yyval.tac) = do_switch((yyvsp[-6].exp), (yyvsp[-2].tac), (yyvsp[-1].tac), g_switch_end);
      pop_loop_labels();
      g_switch_end = NULL;
    }
#line 1719 "mini.y.c"
    break;

  case 74: /* case_list: case_item  */
#line 337 "mini.y"
           { (yyval.tac) = (yyvsp[0].tac); }
#line 1725 "mini.y.c"
    break;

  case 75: /* case_list: case_list case_item  */
#line 339 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-1].tac),(yyvsp[0].tac));
}
#line 1733 "mini.y.c"
    break;

  case 76: /* case_item: CASE INTEGER ':' statement_list  */
#line 345 "mini.y"
{
	(yyval.tac) = do_case(atoi((yyvsp[-2].string)),(yyvsp[0].tac));
}
#line 1741 "mini.y.c"
    break;

  case 77: /* default_list: %empty  */
#line 351 "mini.y"
{
	 (yyval.tac) = NULL; 
}
#line 1749 "mini.y.c"
    break;

  case 78: /* default_list: DEFAULT ':' statement_list  */
#line 355 "mini.y"
{ 
	(yyval.tac) = (yyvsp[0].tac); 
}
#line 1757 "mini.y.c"
    break;

  case 79: /* $@2: %empty  */
#line 360 "mini.y"
{
	g_for_start = mk_label(mk_lstr(next_label++));
    g_for_cont  = mk_label(mk_lstr(next_label++));
    g_for_end   = mk_label(mk_lstr(next_label++));
    push_loop_labels(g_for_cont, g_for_end);
}
#line 1768 "mini.y.c"
    break;

  case 80: /* while_statement: WHILE '(' expression ')' $@2 block  */
#line 367 "mini.y"
{
	(yyval.tac)=do_while((yyvsp[-3].exp), (yyvsp[0].tac),g_for_start,g_for_cont,g_for_end);
	pop_loop_labels();
	g_for_start = g_for_cont = g_for_end = NULL;
}
#line 1778 "mini.y.c"
    break;

  case 81: /* $@3: %empty  */
#line 377 "mini.y"
    {
      g_for_start = mk_label(mk_lstr(next_label++));
      g_for_cont  = mk_label(mk_lstr(next_label++));
      g_for_end   = mk_label(mk_lstr(next_label++));
      push_loop_labels(g_for_cont, g_for_end);
    }
#line 1789 "mini.y.c"
    break;

  case 82: /* for_statement: FOR '(' opt_statement ';' opt_expression ';' opt_statement ')' $@3 block  */
#line 384 "mini.y"
    {
      (yyval.tac) = do_for((yyvsp[-7].tac), (yyvsp[-5].exp), (yyvsp[-3].tac), (yyvsp[0].tac), g_for_start, g_for_cont, g_for_end);
      pop_loop_labels();
      g_for_start = g_for_cont = g_for_end = NULL;
    }
#line 1799 "mini.y.c"
    break;

  case 83: /* opt_statement: assignment_statement  */
#line 394 "mini.y"
{
	(yyval.tac) = (yyvsp[0].tac);
}
#line 1807 "mini.y.c"
    break;

  case 84: /* opt_statement: %empty  */
#line 398 "mini.y"
{
	(yyval.tac) = NULL;
}
#line 1815 "mini.y.c"
    break;

  case 85: /* opt_expression: expression  */
#line 404 "mini.y"
{
	(yyval.exp) = (yyvsp[0].exp);
}
#line 1823 "mini.y.c"
    break;

  case 86: /* opt_expression: %empty  */
#line 408 "mini.y"
{
	(yyval.exp) = NULL;
}
#line 1831 "mini.y.c"
    break;

  case 87: /* break_statement: BREAK  */
#line 414 "mini.y"
{
	(yyval.tac)=do_break();
}
#line 1839 "mini.y.c"
    break;

  case 88: /* continue_statement: CONTINUE  */
#line 420 "mini.y"
{
	(yyval.tac)=do_continue();
}
#line 1847 "mini.y.c"
    break;

  case 89: /* call_statement: IDENTIFIER '(' argument_list ')'  */
#line 426 "mini.y"
{
	(yyval.tac)=do_call((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 1855 "mini.y.c"
    break;

  case 90: /* call_expression: IDENTIFIER '(' argument_list ')'  */
#line 432 "mini.y"
{
	(yyval.exp)=do_call_ret((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 1863 "mini.y.c"
    break;


#line 1867 "mini.y.c"

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

#line 437 "mini.y"


void yyerror(char* msg) 
{
	fprintf(stderr, "%s: line %d\n", msg, yylineno);
	exit(0);
}
