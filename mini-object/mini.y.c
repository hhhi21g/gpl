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

int next_token();
int is_path_start();



#line 93 "mini.y.c"

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
  YYSYMBOL_PTR_OP = 12,                    /* PTR_OP  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_SWITCH = 15,                    /* SWITCH  */
  YYSYMBOL_CASE = 16,                      /* CASE  */
  YYSYMBOL_DEFAULT = 17,                   /* DEFAULT  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_BREAK = 20,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 21,                  /* CONTINUE  */
  YYSYMBOL_FUNC = 22,                      /* FUNC  */
  YYSYMBOL_INPUT = 23,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 24,                    /* OUTPUT  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_INTEGER = 26,                   /* INTEGER  */
  YYSYMBOL_IDENTIFIER = 27,                /* IDENTIFIER  */
  YYSYMBOL_TEXT = 28,                      /* TEXT  */
  YYSYMBOL_CHAR = 29,                      /* CHAR  */
  YYSYMBOL_CHAR_CONST = 30,                /* CHAR_CONST  */
  YYSYMBOL_LBRACK = 31,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 32,                    /* RBRACK  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '*'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '.'  */
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
  YYSYMBOL_variable_list = 60,             /* variable_list  */
  YYSYMBOL_decl_item_int = 61,             /* decl_item_int  */
  YYSYMBOL_variable_list_char = 62,        /* variable_list_char  */
  YYSYMBOL_decl_item_char = 63,            /* decl_item_char  */
  YYSYMBOL_function = 64,                  /* function  */
  YYSYMBOL_function_head = 65,             /* function_head  */
  YYSYMBOL_parameter_list = 66,            /* parameter_list  */
  YYSYMBOL_statement = 67,                 /* statement  */
  YYSYMBOL_block = 68,                     /* block  */
  YYSYMBOL_declaration_list = 69,          /* declaration_list  */
  YYSYMBOL_statement_list = 70,            /* statement_list  */
  YYSYMBOL_lvalue_path = 71,               /* lvalue_path  */
  YYSYMBOL_lvalue_tail = 72,               /* lvalue_tail  */
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
#define YYLAST   378

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  245

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      41,    42,    35,    33,    38,    34,    43,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    37,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    49,    49,    57,    58,    64,    65,    66,    69,    73,
      81,    85,    93,    97,   101,   101,   108,   112,   120,   119,
     131,   134,   140,   145,   150,   155,   160,   165,   172,   173,
     179,   183,   187,   194,   195,   201,   205,   209,   217,   223,
     230,   236,   242,   250,   254,   258,   262,   266,   270,   275,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   299,   306,   309,   315,   316,   322,   329,
     332,   336,   343,   347,   351,   358,   365,   378,   386,   391,
     395,   399,   403,   407,   411,   415,   419,   423,   427,   431,
     435,   439,   443,   447,   451,   455,   465,   473,   476,   479,
     480,   487,   493,   497,   501,   509,   517,   521,   529,   528,
     542,   543,   549,   556,   559,   565,   564,   582,   581,   598,
     603,   608,   613,   618,   624,   630,   636
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
  "LT", "LE", "GT", "GE", "UMINUS", "STRUCT_TOK", "PTR_OP", "IF", "ELSE",
  "SWITCH", "CASE", "DEFAULT", "WHILE", "FOR", "BREAK", "CONTINUE", "FUNC",
  "INPUT", "OUTPUT", "RETURN", "INTEGER", "IDENTIFIER", "TEXT", "CHAR",
  "CHAR_CONST", "LBRACK", "RBRACK", "'+'", "'-'", "'*'", "'/'", "';'",
  "','", "'{'", "'}'", "'('", "')'", "'.'", "'='", "'&'", "':'", "$accept",
  "program", "function_declaration_list", "function_declaration",
  "dims_decl", "dims_idx", "declaration", "$@1", "struct_var_list",
  "struct_definition", "$@2", "struct_member_list", "struct_member_line",
  "variable_list", "decl_item_int", "variable_list_char", "decl_item_char",
  "function", "function_head", "parameter_list", "statement", "block",
  "declaration_list", "statement_list", "lvalue_path", "lvalue_tail",
  "assignment_statement", "expression", "argument_list", "expression_list",
  "input_statement", "output_statement", "return_statement",
  "if_statement", "switch_statement", "$@3", "case_list", "case_item",
  "default_list", "while_statement", "$@4", "for_statement", "$@5",
  "opt_statement", "opt_expression", "break_statement",
  "continue_statement", "call_statement", "call_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-116)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-123)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     133,  -116,   -11,    12,  -116,   -10,    73,   139,  -116,  -116,
    -116,  -116,    37,   -18,    68,   119,  -116,    65,    22,    84,
     156,  -116,  -116,  -116,     1,    90,    82,  -116,  -116,    32,
      91,    81,    82,  -116,  -116,    66,   110,  -116,   128,   105,
      96,   135,   132,  -116,  -116,   158,  -116,   132,  -116,  -116,
    -116,    47,   120,  -116,   143,  -116,   140,     7,   144,  -116,
     150,  -116,  -116,  -116,  -116,   170,   174,   178,   148,  -116,
    -116,  -116,   221,    35,   186,    78,  -116,  -116,    32,   190,
     180,   182,   184,   187,  -116,  -116,   200,    64,    76,   -22,
      66,   202,  -116,  -116,  -116,   106,   147,   196,   201,   206,
     214,  -116,  -116,  -116,  -116,   231,   233,   235,   211,  -116,
     101,   245,  -116,  -116,    76,    76,    76,    87,  -116,  -116,
    -116,    58,  -116,  -116,    76,    76,  -116,   342,  -116,    58,
     342,    76,    28,    11,   -17,   -23,   236,  -116,  -116,    76,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,   249,   256,  -116,
     251,   258,   270,   280,     0,  -116,   253,    28,   264,  -116,
     319,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,   330,   342,   254,   259,   271,   272,   342,    76,    76,
     274,   264,    76,   342,   265,   275,   273,   120,  -116,  -116,
      34,   266,  -116,   118,   118,   118,   118,   118,   118,   164,
     164,  -116,  -116,  -116,  -116,    76,  -116,  -116,   336,   342,
    -116,   342,  -116,   281,  -116,   295,   278,   120,   342,   282,
    -116,   342,  -116,  -116,   120,   304,  -116,    87,  -116,   285,
     203,  -116,   279,   283,   284,  -116,   291,  -116,   234,   234,
    -116,   120,   163,   191,  -116
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    39,     0,     0,    40,     0,     0,     0,     3,     6,
       7,     5,     0,    30,     0,     0,    28,    14,    35,     0,
       0,    33,     1,     4,    49,     0,    32,    31,    12,     0,
       0,     0,    37,    36,    13,     0,     0,    43,     0,     0,
       0,     0,    30,    29,    16,     0,    20,    35,    34,    45,
      46,     0,     0,     8,     0,    15,     0,     0,     0,    44,
       0,    64,    38,     9,    17,     0,     0,     0,     0,    21,
      47,    48,     0,     0,     0,     0,    19,    62,     0,     0,
       0,     0,     0,     0,   123,   124,     0,     0,     0,    69,
       0,     0,    65,    66,    61,     0,     0,     0,     0,     0,
       0,    55,    56,    57,    58,     0,     0,     0,     0,    22,
       0,     0,    23,    14,     0,     0,     0,   120,   101,    96,
      91,    69,   103,    93,     0,     0,    92,   104,    95,    69,
     105,     0,     0,     0,     0,    68,     0,    63,    67,     0,
      50,    51,    52,    54,    59,    60,    53,     0,     0,    26,
       0,     0,     0,     0,    69,   119,     0,     0,    94,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,    98,     0,     0,    72,     0,     0,
       0,    71,     0,    77,     0,     0,     0,     0,   108,   115,
       0,     0,    90,    84,    85,    86,    87,    88,    89,    79,
      80,    81,    82,    10,   125,     0,    76,    75,     0,    73,
      70,    74,    24,     0,    25,   106,     0,     0,   121,     0,
     126,   100,    11,    27,     0,     0,   116,   120,   107,     0,
     113,   110,     0,     0,     0,   111,     0,   117,     0,     0,
     109,     0,     0,     0,   118
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,   325,    -7,  -114,   261,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,   327,  -116,   322,  -116,  -116,  -116,
     -94,   -52,  -116,   -31,   -69,  -116,  -115,   -82,   210,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,   129,  -116,  -116,
    -116,  -116,  -116,   131,  -116,  -116,  -116,  -116,  -116
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,    26,   134,     9,    30,    45,    10,
      31,    57,    69,    15,    16,    20,    21,    11,    12,    39,
      93,    94,    72,    95,   126,   135,    97,   172,   173,   174,
      98,    99,   100,   101,   102,   216,   230,   231,   236,   103,
     217,   104,   241,   156,   219,   105,   106,   107,   128
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,   138,   155,    96,    36,   127,   130,   158,   131,   131,
      65,    32,   119,    25,   178,   158,    13,    18,    66,   132,
     180,   181,   133,   -41,    14,    19,    96,   179,    37,   119,
      38,   131,   151,   152,   153,   119,    67,   120,   129,    17,
      32,   123,   159,   160,   133,   124,   175,    68,    96,   171,
      58,   177,   125,    25,   120,   129,   176,   183,   123,    42,
     120,   129,   124,   -42,   123,   119,   108,    14,   124,   125,
     -97,  -122,   109,    22,    59,   125,    60,   119,    24,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   131,
     120,   121,   122,    47,   123,    27,   208,   209,   124,   157,
     211,    19,   120,   129,   -18,   125,   123,    77,   218,   111,
     124,    33,   155,    41,   154,   112,    40,   125,    44,    80,
      46,    81,    91,   221,    82,    83,    84,    85,    53,    86,
      87,    88,   148,    89,     1,   215,     2,    49,   149,    -2,
       1,    91,     2,    51,     3,    61,   137,    52,   138,   138,
       3,   167,   168,   169,   170,    50,    28,    29,    96,    61,
       4,    54,     5,    25,    77,   226,     4,    64,     5,    96,
      96,    70,   228,    96,    96,    63,    80,    71,    81,  -112,
    -112,    82,    83,    84,    85,    76,    86,    87,    88,   244,
      89,   139,    77,    34,    35,    55,    56,    73,    91,   169,
     170,    74,    61,  -112,    80,    75,    81,   242,   243,    82,
      83,    84,    85,   110,    86,    87,    88,   113,    89,   229,
     234,   114,    77,   115,    78,   116,    91,   118,   117,   136,
      61,  -114,    79,   140,    80,    77,    81,   147,   141,    82,
      83,    84,    85,   142,    86,    87,    88,    80,    89,    81,
      90,   143,    82,    83,    84,    85,    91,    86,    87,    88,
      61,    89,   161,   162,   163,   164,   165,   166,   144,    91,
     145,   150,   146,    61,   161,   162,   163,   164,   165,   166,
     182,   184,   185,   186,   161,   162,   163,   164,   165,   166,
     190,   167,   168,   169,   170,   178,   204,   205,   206,   207,
     187,   210,   212,   167,   168,   169,   170,   213,   220,   224,
     214,   233,   188,   167,   168,   169,   170,   225,   223,   227,
     229,   237,   189,   161,   162,   163,   164,   165,   166,   238,
     239,   240,    23,    92,   161,   162,   163,   164,   165,   166,
     161,   162,   163,   164,   165,   166,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    43,    48,   232,   235,
       0,   192,   203,   167,   168,   169,   170,   191,   222,   167,
     168,   169,   170,     0,     0,   167,   168,   169,   170
};

static const yytype_int16 yycheck[] =
{
      52,    95,   117,    72,     3,    87,    88,   121,    31,    31,
       3,    18,     1,    31,    31,   129,    27,    27,    11,    41,
      43,   135,    44,    41,    35,    35,    95,    44,    27,     1,
      29,    31,   114,   115,   116,     1,    29,    26,    27,    27,
      47,    30,   124,   125,    44,    34,    35,    40,   117,   131,
       3,   133,    41,    31,    26,    27,    45,   139,    30,    27,
      26,    27,    34,    41,    30,     1,    31,    35,    34,    41,
      42,    37,    37,     0,    27,    41,    29,     1,    41,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,    31,
      26,    27,    28,    27,    30,    27,   178,   179,    34,    41,
     182,    35,    26,    27,    39,    41,    30,     1,   190,    31,
      34,    27,   227,    31,    27,    37,    26,    41,    27,    13,
      39,    15,    35,   205,    18,    19,    20,    21,    32,    23,
      24,    25,    31,    27,     1,   187,     3,    27,    37,     0,
       1,    35,     3,    38,    11,    39,    40,    42,   242,   243,
      11,    33,    34,    35,    36,    27,    37,    38,   227,    39,
      27,    26,    29,    31,     1,   217,    27,    27,    29,   238,
     239,    27,   224,   242,   243,    32,    13,    27,    15,    16,
      17,    18,    19,    20,    21,    37,    23,    24,    25,   241,
      27,    44,     1,    37,    38,    37,    38,    27,    35,    35,
      36,    27,    39,    40,    13,    27,    15,   238,   239,    18,
      19,    20,    21,    27,    23,    24,    25,    27,    27,    16,
      17,    41,     1,    41,     3,    41,    35,    27,    41,    27,
      39,    40,    11,    37,    13,     1,    15,    26,    37,    18,
      19,    20,    21,    37,    23,    24,    25,    13,    27,    15,
      29,    37,    18,    19,    20,    21,    35,    23,    24,    25,
      39,    27,     4,     5,     6,     7,     8,     9,    37,    35,
      37,    26,    37,    39,     4,     5,     6,     7,     8,     9,
      44,    32,    26,    32,     4,     5,     6,     7,     8,     9,
      37,    33,    34,    35,    36,    31,    42,    38,    27,    27,
      42,    27,    37,    33,    34,    35,    36,    32,    42,    14,
      37,    26,    42,    33,    34,    35,    36,    39,    37,    37,
      16,    42,    42,     4,     5,     6,     7,     8,     9,    46,
      46,    40,     7,    72,     4,     5,     6,     7,     8,     9,
       4,     5,     6,     7,     8,     9,     4,     5,     6,     7,
       8,     9,    33,    34,    35,    36,    29,    35,   227,   230,
      -1,    42,    32,    33,    34,    35,    36,   157,    32,    33,
      34,    35,    36,    -1,    -1,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    11,    27,    29,    48,    49,    50,    53,
      56,    64,    65,    27,    35,    60,    61,    27,    27,    35,
      62,    63,     0,    50,    41,    31,    51,    27,    37,    38,
      54,    57,    51,    27,    37,    38,     3,    27,    29,    66,
      26,    31,    27,    61,    27,    55,    39,    27,    63,    27,
      27,    38,    42,    32,    26,    37,    38,    58,     3,    27,
      29,    39,    68,    32,    27,     3,    11,    29,    40,    59,
      27,    27,    69,    27,    27,    27,    37,     1,     3,    11,
      13,    15,    18,    19,    20,    21,    23,    24,    25,    27,
      29,    35,    53,    67,    68,    70,    71,    73,    77,    78,
      79,    80,    81,    86,    88,    92,    93,    94,    31,    37,
      27,    31,    37,    27,    41,    41,    41,    41,    27,     1,
      26,    27,    28,    30,    34,    41,    71,    74,    95,    27,
      74,    31,    41,    44,    52,    72,    27,    40,    67,    44,
      37,    37,    37,    37,    37,    37,    37,    26,    31,    37,
      26,    74,    74,    74,    27,    73,    90,    41,    52,    74,
      74,     4,     5,     6,     7,     8,     9,    33,    34,    35,
      36,    74,    74,    75,    76,    35,    45,    74,    31,    44,
      43,    52,    44,    74,    32,    26,    32,    42,    42,    42,
      37,    75,    42,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    32,    42,    38,    27,    27,    74,    74,
      27,    74,    37,    32,    37,    68,    82,    87,    74,    91,
      42,    74,    32,    37,    14,    39,    68,    37,    68,    16,
      83,    84,    90,    26,    17,    84,    85,    42,    46,    46,
      40,    89,    70,    70,    68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    53,    55,    55,    57,    56,
      58,    58,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    61,    62,    62,    63,    63,    63,    64,    64,
      65,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    69,    69,    70,    70,    71,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      76,    77,    78,    78,    78,    79,    80,    80,    82,    81,
      83,    83,    84,    85,    85,    87,    86,    89,    88,    90,
      90,    91,    91,    92,    93,    94,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     3,     4,
       3,     4,     3,     3,     0,     5,     1,     3,     0,     7,
       0,     2,     3,     3,     6,     6,     4,     7,     1,     3,
       1,     2,     2,     1,     3,     1,     2,     2,     5,     1,
       1,     2,     2,     1,     3,     2,     2,     4,     4,     0,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     4,     0,     2,     1,     2,     2,     0,
       3,     2,     3,     4,     4,     4,     4,     3,     1,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     2,     1,     1,     0,     1,     1,
       3,     2,     2,     2,     2,     2,     5,     7,     0,     9,
       1,     2,     4,     0,     3,     0,     6,     0,    10,     1,
       0,     1,     0,     1,     1,     4,     4
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
#line 50 "mini.y"
{
	tac_last=(yyvsp[0].tac);
	tac_complete();
}
#line 1373 "mini.y.c"
    break;

  case 4: /* function_declaration_list: function_declaration_list function_declaration  */
#line 59 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1381 "mini.y.c"
    break;

  case 8: /* dims_decl: LBRACK INTEGER RBRACK  */
#line 70 "mini.y"
{
	(yyval.exp)=mk_exp(NULL,mk_const(atoi((yyvsp[-1].string))),NULL);
}
#line 1389 "mini.y.c"
    break;

  case 9: /* dims_decl: dims_decl LBRACK INTEGER RBRACK  */
#line 74 "mini.y"
{
	EXP *node = mk_exp(NULL,mk_const(atoi((yyvsp[-1].string))),NULL);
	node->next = (yyvsp[-3].exp);
	(yyval.exp) = node;
}
#line 1399 "mini.y.c"
    break;

  case 10: /* dims_idx: LBRACK expression RBRACK  */
#line 82 "mini.y"
{
	(yyval.exp) = mk_exp(NULL,(yyvsp[-1].exp)->ret,(yyvsp[-1].exp)->tac);
}
#line 1407 "mini.y.c"
    break;

  case 11: /* dims_idx: dims_idx LBRACK expression RBRACK  */
#line 86 "mini.y"
{
	EXP*node = mk_exp(NULL,(yyvsp[-1].exp)->ret,(yyvsp[-1].exp)->tac);
	node->next = (yyvsp[-3].exp);
	(yyval.exp) = node;
}
#line 1417 "mini.y.c"
    break;

  case 12: /* declaration: INT variable_list ';'  */
#line 94 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1425 "mini.y.c"
    break;

  case 13: /* declaration: CHAR variable_list_char ';'  */
#line 98 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1433 "mini.y.c"
    break;

  case 14: /* $@1: %empty  */
#line 101 "mini.y"
                        {g_cur_struct = (yyvsp[0].string);}
#line 1439 "mini.y.c"
    break;

  case 15: /* declaration: STRUCT_TOK IDENTIFIER $@1 struct_var_list ';'  */
#line 102 "mini.y"
{
	(yyval.tac) = (yyvsp[-1].tac);
	g_cur_struct = NULL;
}
#line 1448 "mini.y.c"
    break;

  case 16: /* struct_var_list: IDENTIFIER  */
#line 109 "mini.y"
{ 
	(yyval.tac) = declare_struct((yyvsp[0].string), g_cur_struct); 
}
#line 1456 "mini.y.c"
    break;

  case 17: /* struct_var_list: struct_var_list ',' IDENTIFIER  */
#line 113 "mini.y"
{ 
	(yyval.tac) = join_tac((yyvsp[-2].tac), declare_struct((yyvsp[0].string), g_cur_struct)); 
}
#line 1464 "mini.y.c"
    break;

  case 18: /* $@2: %empty  */
#line 120 "mini.y"
{
	begin_struct((yyvsp[0].string));
}
#line 1472 "mini.y.c"
    break;

  case 19: /* struct_definition: STRUCT_TOK IDENTIFIER $@2 '{' struct_member_list '}' ';'  */
#line 124 "mini.y"
{
	end_struct(NULL);
	(yyval.tac) = NULL;
}
#line 1481 "mini.y.c"
    break;

  case 20: /* struct_member_list: %empty  */
#line 131 "mini.y"
{
	 (yyval.tac) = NULL;
}
#line 1489 "mini.y.c"
    break;

  case 21: /* struct_member_list: struct_member_list struct_member_line  */
#line 135 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-1].tac),(yyvsp[0].tac));
}
#line 1497 "mini.y.c"
    break;

  case 22: /* struct_member_line: INT IDENTIFIER ';'  */
#line 141 "mini.y"
{
	add_struct_member(NULL,SYM_INT,(yyvsp[-1].string));
	(yyval.tac) = NULL;
}
#line 1506 "mini.y.c"
    break;

  case 23: /* struct_member_line: CHAR IDENTIFIER ';'  */
#line 146 "mini.y"
{ 
	add_struct_member(NULL, SYM_CHAR, (yyvsp[-1].string)); 
	(yyval.tac) = NULL; 
}
#line 1515 "mini.y.c"
    break;

  case 24: /* struct_member_line: INT IDENTIFIER LBRACK INTEGER RBRACK ';'  */
#line 151 "mini.y"
{
	add_struct_member_array(NULL,SYM_INT,(yyvsp[-4].string),atoi((yyvsp[-2].string)));
	(yyval.tac) = NULL;
}
#line 1524 "mini.y.c"
    break;

  case 25: /* struct_member_line: CHAR IDENTIFIER LBRACK INTEGER RBRACK ';'  */
#line 156 "mini.y"
{
	add_struct_member_array(NULL,SYM_CHAR,(yyvsp[-4].string),atoi((yyvsp[-2].string)));
	(yyval.tac) = NULL;
}
#line 1533 "mini.y.c"
    break;

  case 26: /* struct_member_line: STRUCT_TOK IDENTIFIER IDENTIFIER ';'  */
#line 161 "mini.y"
{
	add_struct_member_struct((yyvsp[-2].string),(yyvsp[-1].string));
	(yyval.tac) = NULL;
}
#line 1542 "mini.y.c"
    break;

  case 27: /* struct_member_line: STRUCT_TOK IDENTIFIER IDENTIFIER LBRACK INTEGER RBRACK ';'  */
#line 166 "mini.y"
{
	add_struct_member_struct_array((yyvsp[-5].string),(yyvsp[-4].string),atoi((yyvsp[-2].string)));
	(yyval.tac) = NULL;
}
#line 1551 "mini.y.c"
    break;

  case 29: /* variable_list: variable_list ',' decl_item_int  */
#line 174 "mini.y"
{ 
	(yyval.tac) = join_tac((yyvsp[-2].tac), (yyvsp[0].tac)); 
}
#line 1559 "mini.y.c"
    break;

  case 30: /* decl_item_int: IDENTIFIER  */
#line 180 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_INT); 
}
#line 1567 "mini.y.c"
    break;

  case 31: /* decl_item_int: '*' IDENTIFIER  */
#line 184 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_PTR); 
}
#line 1575 "mini.y.c"
    break;

  case 32: /* decl_item_int: IDENTIFIER dims_decl  */
#line 188 "mini.y"
{
	(yyval.tac) = declare_array_typed((yyvsp[-1].string),SYM_INT,(yyvsp[0].exp));
}
#line 1583 "mini.y.c"
    break;

  case 34: /* variable_list_char: variable_list_char ',' decl_item_char  */
#line 196 "mini.y"
{ 
	(yyval.tac) = join_tac((yyvsp[-2].tac), (yyvsp[0].tac)); 
}
#line 1591 "mini.y.c"
    break;

  case 35: /* decl_item_char: IDENTIFIER  */
#line 202 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_CHAR); 
}
#line 1599 "mini.y.c"
    break;

  case 36: /* decl_item_char: '*' IDENTIFIER  */
#line 206 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_PTR); 
}
#line 1607 "mini.y.c"
    break;

  case 37: /* decl_item_char: IDENTIFIER dims_decl  */
#line 210 "mini.y"
{
	(yyval.tac) = declare_array_typed((yyvsp[-1].string),SYM_CHAR,(yyvsp[0].exp));
}
#line 1615 "mini.y.c"
    break;

  case 38: /* function: function_head '(' parameter_list ')' block  */
#line 218 "mini.y"
{
	(yyval.tac)=do_func((yyvsp[-4].sym), (yyvsp[-2].tac), (yyvsp[0].tac));
	scope=0; /* Leave local scope. */
	sym_tab_local=NULL; /* Clear local symbol table. */
}
#line 1625 "mini.y.c"
    break;

  case 39: /* function: error  */
#line 224 "mini.y"
{
	error("Bad function syntax");
	(yyval.tac)=NULL;
}
#line 1634 "mini.y.c"
    break;

  case 40: /* function_head: IDENTIFIER  */
#line 231 "mini.y"
{
	(yyval.sym)=declare_func((yyvsp[0].string));
	scope=1; /* Enter local scope. */
	sym_tab_local=NULL; /* Init local symbol table. */
}
#line 1644 "mini.y.c"
    break;

  case 41: /* function_head: INT IDENTIFIER  */
#line 237 "mini.y"
{
	(yyval.sym) = declare_func((yyvsp[0].string));
	scope = 1;
	sym_tab_local = NULL;
}
#line 1654 "mini.y.c"
    break;

  case 42: /* function_head: CHAR IDENTIFIER  */
#line 243 "mini.y"
{
	(yyval.sym) = declare_func((yyvsp[0].string));
	scope = 1;
	sym_tab_local = NULL;
}
#line 1664 "mini.y.c"
    break;

  case 43: /* parameter_list: IDENTIFIER  */
#line 251 "mini.y"
{
	(yyval.tac)=declare_para((yyvsp[0].string));
}
#line 1672 "mini.y.c"
    break;

  case 44: /* parameter_list: parameter_list ',' IDENTIFIER  */
#line 255 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), declare_para((yyvsp[0].string)));
}
#line 1680 "mini.y.c"
    break;

  case 45: /* parameter_list: INT IDENTIFIER  */
#line 259 "mini.y"
{
	(yyval.tac) = declare_para((yyvsp[0].string));
}
#line 1688 "mini.y.c"
    break;

  case 46: /* parameter_list: CHAR IDENTIFIER  */
#line 263 "mini.y"
{
	(yyval.tac) = declare_para((yyvsp[0].string));
}
#line 1696 "mini.y.c"
    break;

  case 47: /* parameter_list: parameter_list ',' INT IDENTIFIER  */
#line 267 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-3].tac),declare_para((yyvsp[0].string)));
}
#line 1704 "mini.y.c"
    break;

  case 48: /* parameter_list: parameter_list ',' CHAR IDENTIFIER  */
#line 271 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-3].tac),declare_para((yyvsp[0].string)));
}
#line 1712 "mini.y.c"
    break;

  case 49: /* parameter_list: %empty  */
#line 275 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1720 "mini.y.c"
    break;

  case 62: /* statement: error  */
#line 293 "mini.y"
{
	error("Bad statement syntax");
	(yyval.tac)=NULL;
}
#line 1729 "mini.y.c"
    break;

  case 63: /* block: '{' declaration_list statement_list '}'  */
#line 300 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[-1].tac));
}
#line 1737 "mini.y.c"
    break;

  case 64: /* declaration_list: %empty  */
#line 306 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1745 "mini.y.c"
    break;

  case 65: /* declaration_list: declaration_list declaration  */
#line 310 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1753 "mini.y.c"
    break;

  case 67: /* statement_list: statement_list statement  */
#line 317 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1761 "mini.y.c"
    break;

  case 68: /* lvalue_path: IDENTIFIER lvalue_tail  */
#line 323 "mini.y"
{
	(yyval.path) = mk_lvalue_path((yyvsp[-1].string),(yyvsp[0].path));
}
#line 1769 "mini.y.c"
    break;

  case 69: /* lvalue_tail: %empty  */
#line 329 "mini.y"
{
	(yyval.path) = NULL;
}
#line 1777 "mini.y.c"
    break;

  case 70: /* lvalue_tail: lvalue_tail '.' IDENTIFIER  */
#line 333 "mini.y"
{
	(yyval.path) = append_path_member((yyvsp[-2].path),(yyvsp[0].string));
}
#line 1785 "mini.y.c"
    break;

  case 71: /* lvalue_tail: lvalue_tail dims_idx  */
#line 337 "mini.y"
{
	(yyval.path) = append_path_index((yyvsp[-1].path),(yyvsp[0].exp));
}
#line 1793 "mini.y.c"
    break;

  case 72: /* assignment_statement: IDENTIFIER '=' expression  */
#line 344 "mini.y"
{
	(yyval.tac)=do_assign(get_var((yyvsp[-2].string)), (yyvsp[0].exp));
}
#line 1801 "mini.y.c"
    break;

  case 73: /* assignment_statement: IDENTIFIER dims_idx '=' expression  */
#line 348 "mini.y"
{
	(yyval.tac) = do_array_store(get_var((yyvsp[-3].string)),(yyvsp[-2].exp),(yyvsp[0].exp));
}
#line 1809 "mini.y.c"
    break;

  case 74: /* assignment_statement: '*' IDENTIFIER '=' expression  */
#line 352 "mini.y"
{
	SYM *ptr = get_var((yyvsp[-2].string));
	TAC *store = mk_tac(TAC_STORE, ptr, (yyvsp[0].exp)->ret, NULL);
	store->prev = (yyvsp[0].exp)->tac;
	(yyval.tac) = store;
}
#line 1820 "mini.y.c"
    break;

  case 75: /* assignment_statement: IDENTIFIER '=' '&' IDENTIFIER  */
#line 359 "mini.y"
{
    SYM *dst = get_var((yyvsp[-3].string));
    SYM *src = get_var((yyvsp[0].string));
    TAC *addr = mk_tac(TAC_ADDR, dst, src, NULL);
    (yyval.tac) = addr;
}
#line 1831 "mini.y.c"
    break;

  case 76: /* assignment_statement: IDENTIFIER '=' '*' IDENTIFIER  */
#line 366 "mini.y"
{
    SYM *dst = get_var((yyvsp[-3].string));
    SYM *src = get_var((yyvsp[0].string));
    TAC *load = mk_tac(TAC_LOAD, dst, src, NULL);
    (yyval.tac) = load;
}
#line 1842 "mini.y.c"
    break;

  case 77: /* assignment_statement: lvalue_path '=' expression  */
#line 379 "mini.y"
{
	(yyval.tac) = do_lvalue_store((yyvsp[-2].path),(yyvsp[0].exp));
}
#line 1850 "mini.y.c"
    break;

  case 78: /* expression: IDENTIFIER  */
#line 387 "mini.y"
{
	(yyval.exp) = mk_exp(NULL, get_var((yyvsp[0].string)), NULL);
	
}
#line 1859 "mini.y.c"
    break;

  case 79: /* expression: expression '+' expression  */
#line 392 "mini.y"
{
	(yyval.exp)=do_bin(TAC_ADD, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1867 "mini.y.c"
    break;

  case 80: /* expression: expression '-' expression  */
#line 396 "mini.y"
{
	(yyval.exp)=do_bin(TAC_SUB, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1875 "mini.y.c"
    break;

  case 81: /* expression: expression '*' expression  */
#line 400 "mini.y"
{
	(yyval.exp)=do_bin(TAC_MUL, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1883 "mini.y.c"
    break;

  case 82: /* expression: expression '/' expression  */
#line 404 "mini.y"
{
	(yyval.exp)=do_bin(TAC_DIV, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1891 "mini.y.c"
    break;

  case 83: /* expression: '-' expression  */
#line 408 "mini.y"
{
	(yyval.exp)=do_un(TAC_NEG, (yyvsp[0].exp));
}
#line 1899 "mini.y.c"
    break;

  case 84: /* expression: expression EQ expression  */
#line 412 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_EQ, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1907 "mini.y.c"
    break;

  case 85: /* expression: expression NE expression  */
#line 416 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_NE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1915 "mini.y.c"
    break;

  case 86: /* expression: expression LT expression  */
#line 420 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1923 "mini.y.c"
    break;

  case 87: /* expression: expression LE expression  */
#line 424 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1931 "mini.y.c"
    break;

  case 88: /* expression: expression GT expression  */
#line 428 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1939 "mini.y.c"
    break;

  case 89: /* expression: expression GE expression  */
#line 432 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1947 "mini.y.c"
    break;

  case 90: /* expression: '(' expression ')'  */
#line 436 "mini.y"
{
	(yyval.exp)=(yyvsp[-1].exp);
}
#line 1955 "mini.y.c"
    break;

  case 91: /* expression: INTEGER  */
#line 440 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_const(atoi((yyvsp[0].string))), NULL);
}
#line 1963 "mini.y.c"
    break;

  case 92: /* expression: lvalue_path  */
#line 444 "mini.y"
{
	(yyval.exp) = do_lvalue_load((yyvsp[0].path));
}
#line 1971 "mini.y.c"
    break;

  case 93: /* expression: CHAR_CONST  */
#line 448 "mini.y"
{
	(yyval.exp)=mk_exp(NULL,mk_char((yyvsp[0].string)[1]),NULL);
}
#line 1979 "mini.y.c"
    break;

  case 94: /* expression: IDENTIFIER dims_idx  */
#line 452 "mini.y"
{
	(yyval.exp) = do_array_load(get_var((yyvsp[-1].string)),(yyvsp[0].exp));  // 加载数组值
}
#line 1987 "mini.y.c"
    break;

  case 95: /* expression: call_expression  */
#line 456 "mini.y"
{
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1995 "mini.y.c"
    break;

  case 96: /* expression: error  */
#line 466 "mini.y"
{
	error("Bad expression syntax");
	(yyval.exp)=mk_exp(NULL, NULL, NULL);
}
#line 2004 "mini.y.c"
    break;

  case 97: /* argument_list: %empty  */
#line 473 "mini.y"
{
	(yyval.exp)=NULL;
}
#line 2012 "mini.y.c"
    break;

  case 100: /* expression_list: expression_list ',' expression  */
#line 481 "mini.y"
{
	(yyvsp[0].exp)->next=(yyvsp[-2].exp);
	(yyval.exp)=(yyvsp[0].exp);
}
#line 2021 "mini.y.c"
    break;

  case 101: /* input_statement: INPUT IDENTIFIER  */
#line 488 "mini.y"
{
	(yyval.tac)=do_input(get_var((yyvsp[0].string)));
}
#line 2029 "mini.y.c"
    break;

  case 102: /* output_statement: OUTPUT IDENTIFIER  */
#line 494 "mini.y"
{
	(yyval.tac)=do_output(get_var((yyvsp[0].string)));
}
#line 2037 "mini.y.c"
    break;

  case 103: /* output_statement: OUTPUT TEXT  */
#line 498 "mini.y"
{
	(yyval.tac)=do_output(mk_text((yyvsp[0].string)));
}
#line 2045 "mini.y.c"
    break;

  case 104: /* output_statement: OUTPUT expression  */
#line 502 "mini.y"
{
	TAC*t = mk_tac(TAC_OUTPUT,(yyvsp[0].exp)->ret,NULL,NULL);
	t->prev = (yyvsp[0].exp)->tac;
	(yyval.tac) = t;
}
#line 2055 "mini.y.c"
    break;

  case 105: /* return_statement: RETURN expression  */
#line 510 "mini.y"
{
	TAC *t=mk_tac(TAC_RETURN, (yyvsp[0].exp)->ret, NULL, NULL);
	t->prev=(yyvsp[0].exp)->tac;
	(yyval.tac)=t;
}
#line 2065 "mini.y.c"
    break;

  case 106: /* if_statement: IF '(' expression ')' block  */
#line 518 "mini.y"
{
	(yyval.tac)=do_if((yyvsp[-2].exp), (yyvsp[0].tac));
}
#line 2073 "mini.y.c"
    break;

  case 107: /* if_statement: IF '(' expression ')' block ELSE block  */
#line 522 "mini.y"
{
	(yyval.tac)=do_test((yyvsp[-4].exp), (yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 2081 "mini.y.c"
    break;

  case 108: /* $@3: %empty  */
#line 529 "mini.y"
    {
      g_switch_end = mk_label(mk_lstr(next_label++));
      push_loop_labels(NULL, g_switch_end);  // 同for, 只有end
    }
#line 2090 "mini.y.c"
    break;

  case 109: /* switch_statement: SWITCH '(' expression ')' $@3 '{' case_list default_list '}'  */
#line 534 "mini.y"
    {
      (yyval.tac) = do_switch((yyvsp[-6].exp), (yyvsp[-2].tac), (yyvsp[-1].tac), g_switch_end);
      pop_loop_labels();
      g_switch_end = NULL;
    }
#line 2100 "mini.y.c"
    break;

  case 110: /* case_list: case_item  */
#line 542 "mini.y"
           { (yyval.tac) = (yyvsp[0].tac); }
#line 2106 "mini.y.c"
    break;

  case 111: /* case_list: case_list case_item  */
#line 544 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-1].tac),(yyvsp[0].tac));
}
#line 2114 "mini.y.c"
    break;

  case 112: /* case_item: CASE INTEGER ':' statement_list  */
#line 550 "mini.y"
{
	(yyval.tac) = do_case(atoi((yyvsp[-2].string)),(yyvsp[0].tac));
}
#line 2122 "mini.y.c"
    break;

  case 113: /* default_list: %empty  */
#line 556 "mini.y"
{
	 (yyval.tac) = NULL; 
}
#line 2130 "mini.y.c"
    break;

  case 114: /* default_list: DEFAULT ':' statement_list  */
#line 560 "mini.y"
{ 
	(yyval.tac) = (yyvsp[0].tac); 
}
#line 2138 "mini.y.c"
    break;

  case 115: /* $@4: %empty  */
#line 565 "mini.y"
{
	g_for_start = mk_label(mk_lstr(next_label++));
    g_for_cont  = mk_label(mk_lstr(next_label++));
    g_for_end   = mk_label(mk_lstr(next_label++));
    push_loop_labels(g_for_cont, g_for_end);
}
#line 2149 "mini.y.c"
    break;

  case 116: /* while_statement: WHILE '(' expression ')' $@4 block  */
#line 572 "mini.y"
{
	(yyval.tac)=do_while((yyvsp[-3].exp), (yyvsp[0].tac),g_for_start,g_for_cont,g_for_end);
	pop_loop_labels();
	g_for_start = g_for_cont = g_for_end = NULL;
}
#line 2159 "mini.y.c"
    break;

  case 117: /* $@5: %empty  */
#line 582 "mini.y"
    {
      g_for_start = mk_label(mk_lstr(next_label++));
      g_for_cont  = mk_label(mk_lstr(next_label++));
      g_for_end   = mk_label(mk_lstr(next_label++));
      push_loop_labels(g_for_cont, g_for_end);
    }
#line 2170 "mini.y.c"
    break;

  case 118: /* for_statement: FOR '(' opt_statement ';' opt_expression ';' opt_statement ')' $@5 block  */
#line 589 "mini.y"
    {
      (yyval.tac) = do_for((yyvsp[-7].tac), (yyvsp[-5].exp), (yyvsp[-3].tac), (yyvsp[0].tac), g_for_start, g_for_cont, g_for_end);
      pop_loop_labels();
      g_for_start = g_for_cont = g_for_end = NULL;
    }
#line 2180 "mini.y.c"
    break;

  case 119: /* opt_statement: assignment_statement  */
#line 599 "mini.y"
{
	(yyval.tac) = (yyvsp[0].tac);
}
#line 2188 "mini.y.c"
    break;

  case 120: /* opt_statement: %empty  */
#line 603 "mini.y"
{
	(yyval.tac) = NULL;
}
#line 2196 "mini.y.c"
    break;

  case 121: /* opt_expression: expression  */
#line 609 "mini.y"
{
	(yyval.exp) = (yyvsp[0].exp);
}
#line 2204 "mini.y.c"
    break;

  case 122: /* opt_expression: %empty  */
#line 613 "mini.y"
{
	(yyval.exp) = NULL;
}
#line 2212 "mini.y.c"
    break;

  case 123: /* break_statement: BREAK  */
#line 619 "mini.y"
{
	(yyval.tac)=do_break();
}
#line 2220 "mini.y.c"
    break;

  case 124: /* continue_statement: CONTINUE  */
#line 625 "mini.y"
{
	(yyval.tac)=do_continue();
}
#line 2228 "mini.y.c"
    break;

  case 125: /* call_statement: IDENTIFIER '(' argument_list ')'  */
#line 631 "mini.y"
{
	(yyval.tac)=do_call((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 2236 "mini.y.c"
    break;

  case 126: /* call_expression: IDENTIFIER '(' argument_list ')'  */
#line 637 "mini.y"
{
	(yyval.exp)=do_call_ret((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 2244 "mini.y.c"
    break;


#line 2248 "mini.y.c"

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

#line 642 "mini.y"


int next_token() {
    if (yychar >= 0)
        return yychar;
    yychar = yylex();
    return yychar;
}

int is_path_start() {
    int tok = next_token();
    return tok == '.' || tok == LBRACK;
}

void yyerror(char* msg) 
{
	fprintf(stderr, "%s: line %d\n", msg, yylineno);
	exit(0);
}
