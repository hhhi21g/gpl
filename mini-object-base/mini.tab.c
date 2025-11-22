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


#line 89 "mini.tab.c"

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

#include "mini.tab.h"
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
  YYSYMBOL_41_ = 41,                       /* '.'  */
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
  YYSYMBOL_lvalue = 60,                    /* lvalue  */
  YYSYMBOL_variable_list = 61,             /* variable_list  */
  YYSYMBOL_decl_item_int = 62,             /* decl_item_int  */
  YYSYMBOL_variable_list_char = 63,        /* variable_list_char  */
  YYSYMBOL_decl_item_char = 64,            /* decl_item_char  */
  YYSYMBOL_function = 65,                  /* function  */
  YYSYMBOL_function_head = 66,             /* function_head  */
  YYSYMBOL_parameter_list = 67,            /* parameter_list  */
  YYSYMBOL_statement = 68,                 /* statement  */
  YYSYMBOL_block = 69,                     /* block  */
  YYSYMBOL_declaration_list = 70,          /* declaration_list  */
  YYSYMBOL_statement_list = 71,            /* statement_list  */
  YYSYMBOL_assignment_statement = 72,      /* assignment_statement  */
  YYSYMBOL_expression = 73,                /* expression  */
  YYSYMBOL_argument_list = 74,             /* argument_list  */
  YYSYMBOL_expression_list = 75,           /* expression_list  */
  YYSYMBOL_input_statement = 76,           /* input_statement  */
  YYSYMBOL_output_statement = 77,          /* output_statement  */
  YYSYMBOL_return_statement = 78,          /* return_statement  */
  YYSYMBOL_if_statement = 79,              /* if_statement  */
  YYSYMBOL_switch_statement = 80,          /* switch_statement  */
  YYSYMBOL_81_3 = 81,                      /* $@3  */
  YYSYMBOL_case_list = 82,                 /* case_list  */
  YYSYMBOL_case_item = 83,                 /* case_item  */
  YYSYMBOL_default_list = 84,              /* default_list  */
  YYSYMBOL_while_statement = 85,           /* while_statement  */
  YYSYMBOL_86_4 = 86,                      /* $@4  */
  YYSYMBOL_for_statement = 87,             /* for_statement  */
  YYSYMBOL_88_5 = 88,                      /* $@5  */
  YYSYMBOL_opt_statement = 89,             /* opt_statement  */
  YYSYMBOL_opt_expression = 90,            /* opt_expression  */
  YYSYMBOL_break_statement = 91,           /* break_statement  */
  YYSYMBOL_continue_statement = 92,        /* continue_statement  */
  YYSYMBOL_call_statement = 93,            /* call_statement  */
  YYSYMBOL_call_expression = 94            /* call_expression  */
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
#define YYLAST   385

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
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
      42,    43,    35,    33,    38,    34,    41,    36,     2,     2,
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
       0,    43,    43,    51,    52,    58,    59,    60,    63,    67,
      75,    79,    87,    91,    95,    95,   102,   106,   114,   113,
     125,   128,   134,   139,   144,   149,   154,   165,   179,   183,
     196,   201,   202,   208,   212,   216,   223,   224,   230,   234,
     238,   246,   252,   259,   265,   271,   279,   283,   287,   291,
     295,   299,   304,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   328,   335,   338,   344,
     345,   351,   355,   359,   366,   373,   388,   392,   396,   400,
     404,   408,   412,   416,   420,   424,   428,   432,   436,   444,
     448,   452,   456,   466,   474,   477,   480,   481,   488,   494,
     498,   502,   510,   518,   522,   530,   529,   543,   544,   550,
     557,   560,   566,   565,   583,   582,   599,   604,   609,   614,
     619,   625,   631,   637
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
  "','", "'{'", "'}'", "'.'", "'('", "')'", "'='", "'&'", "':'", "$accept",
  "program", "function_declaration_list", "function_declaration",
  "dims_decl", "dims_idx", "declaration", "$@1", "struct_var_list",
  "struct_definition", "$@2", "struct_member_list", "struct_member_line",
  "lvalue", "variable_list", "decl_item_int", "variable_list_char",
  "decl_item_char", "function", "function_head", "parameter_list",
  "statement", "block", "declaration_list", "statement_list",
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

#define YYTABLE_NINF (-120)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     100,  -116,   -19,    -5,  -116,    24,    46,    18,  -116,  -116,
    -116,  -116,     8,   -17,    73,   101,  -116,    71,    27,    89,
     103,  -116,  -116,  -116,    28,    49,   115,  -116,  -116,    43,
     123,    81,   115,  -116,  -116,    78,   135,  -116,   137,    90,
     104,   106,   148,  -116,  -116,   105,  -116,   148,  -116,  -116,
    -116,    36,   142,  -116,   151,  -116,   157,     1,   166,  -116,
     168,  -116,  -116,  -116,  -116,   170,   171,   172,   163,  -116,
    -116,  -116,   279,    84,   174,    93,  -116,  -116,    43,   176,
     162,   169,   175,   179,  -116,  -116,   178,    34,    92,   -18,
      78,   182,  -116,   -24,  -116,  -116,   167,   192,   194,   196,
     211,  -116,  -116,  -116,  -116,   212,   213,   214,   186,  -116,
      94,   206,  -116,  -116,    92,    92,    92,    79,  -116,  -116,
    -116,    48,  -116,  -116,    92,    92,    63,   349,  -116,    48,
     349,    92,    10,    32,   -21,   220,    92,   236,    92,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,   237,   244,
    -116,   245,   219,   232,   238,   -16,  -116,   239,    10,   247,
    -116,   252,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,   316,   349,   240,   241,   257,   262,    92,    92,
      92,   328,  -116,   349,   254,   264,   272,   142,  -116,  -116,
      65,   258,  -116,    38,    38,    38,    38,    38,    38,   109,
     109,  -116,  -116,  -116,  -116,    92,  -116,  -116,   334,   349,
     349,  -116,  -116,   289,  -116,   314,   290,   142,   349,   293,
    -116,   349,  -116,  -116,   142,   329,  -116,    79,  -116,   318,
     150,  -116,   303,   301,   313,  -116,   325,  -116,   292,   292,
    -116,   142,   136,   195,  -116
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    42,     0,     0,    43,     0,     0,     0,     3,     6,
       7,     5,     0,    33,     0,     0,    31,    14,    38,     0,
       0,    36,     1,     4,    52,     0,    35,    34,    12,     0,
       0,     0,    40,    39,    13,     0,     0,    46,     0,     0,
       0,     0,    33,    32,    16,     0,    20,    38,    37,    48,
      49,     0,     0,     8,     0,    15,     0,     0,     0,    47,
       0,    67,    41,     9,    17,     0,     0,     0,     0,    21,
      50,    51,     0,     0,     0,     0,    19,    65,     0,     0,
       0,     0,     0,     0,   120,   121,     0,     0,     0,    28,
       0,     0,    68,     0,    69,    64,     0,     0,     0,     0,
       0,    58,    59,    60,    61,     0,     0,     0,     0,    22,
       0,     0,    23,    14,     0,     0,     0,   117,    98,    93,
      88,    28,   100,    89,     0,     0,    92,   101,    91,    28,
     102,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      70,    53,    54,    55,    57,    62,    63,    56,     0,     0,
      26,     0,     0,     0,     0,    28,   116,     0,     0,    90,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,     0,    95,     0,     0,     0,     0,
       0,     0,    29,    71,     0,     0,     0,     0,   105,   112,
       0,     0,    87,    81,    82,    83,    84,    85,    86,    76,
      77,    78,    79,    10,   122,     0,    75,    74,     0,    72,
      73,    30,    24,     0,    25,   103,     0,     0,   118,     0,
     123,    97,    11,    27,     0,     0,   113,   117,   104,     0,
     110,   107,     0,     0,     0,   108,     0,   114,     0,     0,
     106,     0,     0,     0,   115
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,   364,    -9,   -12,   300,  -116,  -116,  -116,
    -116,  -116,  -116,   -69,  -116,   344,  -116,   339,  -116,  -116,
    -116,   -95,   -52,  -116,   -61,  -115,   -82,   217,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,   146,  -116,  -116,  -116,
    -116,  -116,   152,  -116,  -116,  -116,  -116,  -116
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,    26,   134,     9,    30,    45,    10,
      31,    57,    69,   126,    15,    16,    20,    21,    11,    12,
      39,    94,    95,    72,    96,    97,   173,   174,   175,    98,
      99,   100,   101,   102,   216,   230,   231,   236,   103,   217,
     104,   241,   157,   219,   105,   106,   107,   128
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,   140,   156,    93,    65,   127,   130,   136,    13,    32,
     178,   119,    66,   131,    25,   131,    14,   137,    -2,     1,
     138,     2,    17,   179,   132,   -44,   133,    93,   133,     3,
      67,    36,   152,   153,   154,   119,   120,   129,    32,    58,
     123,    68,   160,   161,   124,     4,    22,     5,    93,   172,
      24,    18,   125,   -94,   181,    37,   183,    38,    25,    19,
     120,   121,   122,    59,   123,    60,   119,   176,   124,   -45,
      42,   168,   169,   170,   171,    40,   125,   177,    14,   131,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     158,   120,   129,   119,   136,   123,   208,   209,   210,   124,
      27,     1,  -119,     2,   137,    47,   155,   125,   218,   159,
     -18,     3,   156,    19,    91,   108,    33,   159,   120,   129,
      46,   109,   123,   221,   111,   149,   124,     4,    51,     5,
     112,   150,    54,    52,   125,   215,    53,    77,    28,    29,
      34,    35,    55,    56,   170,   171,    41,   140,   140,    80,
      44,    81,  -109,  -109,    82,    83,    84,    85,    93,    86,
      87,    88,    49,    89,    50,   226,   229,   234,    77,    93,
      93,    91,   228,    93,    93,    61,  -109,   242,   243,    25,
      80,    61,    81,    63,    64,    82,    83,    84,    85,   244,
      86,    87,    88,    70,    89,    71,    77,    73,    74,    75,
      76,   110,    91,   113,   114,   118,    61,   139,    80,   135,
      81,   115,   148,    82,    83,    84,    85,   116,    86,    87,
      88,   117,    89,   162,   163,   164,   165,   166,   167,   141,
      91,   142,   151,   143,    61,  -111,   162,   163,   164,   165,
     166,   167,   162,   163,   164,   165,   166,   167,   144,   145,
     146,   147,   168,   169,   170,   171,   162,   163,   164,   165,
     166,   167,   187,   182,   180,   168,   169,   170,   171,   184,
     185,   168,   169,   170,   171,   188,   190,   186,   178,   205,
      77,   189,    78,   204,   206,   168,   169,   170,   171,   207,
      79,   212,    80,    77,    81,   192,   213,    82,    83,    84,
      85,   220,    86,    87,    88,    80,    89,    81,    90,   214,
      82,    83,    84,    85,    91,    86,    87,    88,    61,    89,
     162,   163,   164,   165,   166,   167,   223,    91,   224,   225,
     227,    61,   162,   163,   164,   165,   166,   167,   162,   163,
     164,   165,   166,   167,   233,   229,   237,   238,   203,   168,
     169,   170,   171,   162,   163,   164,   165,   166,   167,   239,
     211,   168,   169,   170,   171,   240,   222,   168,   169,   170,
     171,    23,    92,    43,    48,   191,   235,     0,     0,   232,
       0,     0,   168,   169,   170,   171
};

static const yytype_int16 yycheck[] =
{
      52,    96,   117,    72,     3,    87,    88,    31,    27,    18,
      31,     1,    11,    31,    31,    31,    35,    41,     0,     1,
      44,     3,    27,    44,    42,    42,    44,    96,    44,    11,
      29,     3,   114,   115,   116,     1,    26,    27,    47,     3,
      30,    40,   124,   125,    34,    27,     0,    29,   117,   131,
      42,    27,    42,    43,   136,    27,   138,    29,    31,    35,
      26,    27,    28,    27,    30,    29,     1,    35,    34,    42,
      27,    33,    34,    35,    36,    26,    42,    45,    35,    31,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      42,    26,    27,     1,    31,    30,   178,   179,   180,    34,
      27,     1,    37,     3,    41,    27,    27,    42,   190,   121,
      39,    11,   227,    35,    35,    31,    27,   129,    26,    27,
      39,    37,    30,   205,    31,    31,    34,    27,    38,    29,
      37,    37,    26,    43,    42,   187,    32,     1,    37,    38,
      37,    38,    37,    38,    35,    36,    31,   242,   243,    13,
      27,    15,    16,    17,    18,    19,    20,    21,   227,    23,
      24,    25,    27,    27,    27,   217,    16,    17,     1,   238,
     239,    35,   224,   242,   243,    39,    40,   238,   239,    31,
      13,    39,    15,    32,    27,    18,    19,    20,    21,   241,
      23,    24,    25,    27,    27,    27,     1,    27,    27,    27,
      37,    27,    35,    27,    42,    27,    39,    40,    13,    27,
      15,    42,    26,    18,    19,    20,    21,    42,    23,    24,
      25,    42,    27,     4,     5,     6,     7,     8,     9,    37,
      35,    37,    26,    37,    39,    40,     4,     5,     6,     7,
       8,     9,     4,     5,     6,     7,     8,     9,    37,    37,
      37,    37,    33,    34,    35,    36,     4,     5,     6,     7,
       8,     9,    43,    27,    44,    33,    34,    35,    36,    32,
      26,    33,    34,    35,    36,    43,    37,    32,    31,    38,
       1,    43,     3,    43,    27,    33,    34,    35,    36,    27,
      11,    37,    13,     1,    15,    43,    32,    18,    19,    20,
      21,    43,    23,    24,    25,    13,    27,    15,    29,    37,
      18,    19,    20,    21,    35,    23,    24,    25,    39,    27,
       4,     5,     6,     7,     8,     9,    37,    35,    14,    39,
      37,    39,     4,     5,     6,     7,     8,     9,     4,     5,
       6,     7,     8,     9,    26,    16,    43,    46,    32,    33,
      34,    35,    36,     4,     5,     6,     7,     8,     9,    46,
      32,    33,    34,    35,    36,    40,    32,    33,    34,    35,
      36,     7,    72,    29,    35,   158,   230,    -1,    -1,   227,
      -1,    -1,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    11,    27,    29,    48,    49,    50,    53,
      56,    65,    66,    27,    35,    61,    62,    27,    27,    35,
      63,    64,     0,    50,    42,    31,    51,    27,    37,    38,
      54,    57,    51,    27,    37,    38,     3,    27,    29,    67,
      26,    31,    27,    62,    27,    55,    39,    27,    64,    27,
      27,    38,    43,    32,    26,    37,    38,    58,     3,    27,
      29,    39,    69,    32,    27,     3,    11,    29,    40,    59,
      27,    27,    70,    27,    27,    27,    37,     1,     3,    11,
      13,    15,    18,    19,    20,    21,    23,    24,    25,    27,
      29,    35,    53,    60,    68,    69,    71,    72,    76,    77,
      78,    79,    80,    85,    87,    91,    92,    93,    31,    37,
      27,    31,    37,    27,    42,    42,    42,    42,    27,     1,
      26,    27,    28,    30,    34,    42,    60,    73,    94,    27,
      73,    31,    42,    44,    52,    27,    31,    41,    44,    40,
      68,    37,    37,    37,    37,    37,    37,    37,    26,    31,
      37,    26,    73,    73,    73,    27,    72,    89,    42,    52,
      73,    73,     4,     5,     6,     7,     8,     9,    33,    34,
      35,    36,    73,    73,    74,    75,    35,    45,    31,    44,
      44,    73,    27,    73,    32,    26,    32,    43,    43,    43,
      37,    74,    43,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    32,    43,    38,    27,    27,    73,    73,
      73,    32,    37,    32,    37,    69,    81,    86,    73,    90,
      43,    73,    32,    37,    14,    39,    69,    37,    69,    16,
      82,    83,    89,    26,    17,    83,    84,    43,    46,    46,
      40,    88,    71,    71,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    53,    55,    55,    57,    56,
      58,    58,    59,    59,    59,    59,    59,    59,    60,    60,
      60,    61,    61,    62,    62,    62,    63,    63,    64,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    76,    77,
      77,    77,    78,    79,    79,    81,    80,    82,    82,    83,
      84,    84,    86,    85,    88,    87,    89,    89,    90,    90,
      91,    92,    93,    94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     3,     4,
       3,     4,     3,     3,     0,     5,     1,     3,     0,     7,
       0,     2,     3,     3,     6,     6,     4,     7,     1,     3,
       4,     1,     3,     1,     2,     2,     1,     3,     1,     2,
       2,     5,     1,     1,     2,     2,     1,     3,     2,     2,
       4,     4,     0,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     2,     1,     1,     4,     0,     2,     1,
       2,     3,     4,     4,     4,     4,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       2,     1,     1,     1,     0,     1,     1,     3,     2,     2,
       2,     2,     2,     5,     7,     0,     9,     1,     2,     4,
       0,     3,     0,     6,     0,    10,     1,     0,     1,     0,
       1,     1,     4,     4
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
#line 44 "mini.y"
{
	tac_last=(yyvsp[0].tac);
	tac_complete();
}
#line 1370 "mini.tab.c"
    break;

  case 4: /* function_declaration_list: function_declaration_list function_declaration  */
#line 53 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1378 "mini.tab.c"
    break;

  case 8: /* dims_decl: LBRACK INTEGER RBRACK  */
#line 64 "mini.y"
{
	(yyval.exp)=mk_exp(NULL,mk_const(atoi((yyvsp[-1].string))),NULL);
}
#line 1386 "mini.tab.c"
    break;

  case 9: /* dims_decl: dims_decl LBRACK INTEGER RBRACK  */
#line 68 "mini.y"
{
	EXP *node = mk_exp(NULL,mk_const(atoi((yyvsp[-1].string))),NULL);
	node->next = (yyvsp[-3].exp);
	(yyval.exp) = node;
}
#line 1396 "mini.tab.c"
    break;

  case 10: /* dims_idx: LBRACK expression RBRACK  */
#line 76 "mini.y"
{
	(yyval.exp) = mk_exp(NULL,(yyvsp[-1].exp)->ret,(yyvsp[-1].exp)->tac);
}
#line 1404 "mini.tab.c"
    break;

  case 11: /* dims_idx: dims_idx LBRACK expression RBRACK  */
#line 80 "mini.y"
{
	EXP*node = mk_exp(NULL,(yyvsp[-1].exp)->ret,(yyvsp[-1].exp)->tac);
	node->next = (yyvsp[-3].exp);
	(yyval.exp) = node;
}
#line 1414 "mini.tab.c"
    break;

  case 12: /* declaration: INT variable_list ';'  */
#line 88 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1422 "mini.tab.c"
    break;

  case 13: /* declaration: CHAR variable_list_char ';'  */
#line 92 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1430 "mini.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 95 "mini.y"
                        {g_cur_struct = (yyvsp[0].string);}
#line 1436 "mini.tab.c"
    break;

  case 15: /* declaration: STRUCT_TOK IDENTIFIER $@1 struct_var_list ';'  */
#line 96 "mini.y"
{
	(yyval.tac) = (yyvsp[-1].tac);
	g_cur_struct = NULL;
}
#line 1445 "mini.tab.c"
    break;

  case 16: /* struct_var_list: IDENTIFIER  */
#line 103 "mini.y"
{ 
	(yyval.tac) = declare_struct((yyvsp[0].string), g_cur_struct); 
}
#line 1453 "mini.tab.c"
    break;

  case 17: /* struct_var_list: struct_var_list ',' IDENTIFIER  */
#line 107 "mini.y"
{ 
	(yyval.tac) = join_tac((yyvsp[-2].tac), declare_struct((yyvsp[0].string), g_cur_struct)); 
}
#line 1461 "mini.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 114 "mini.y"
{
	begin_struct((yyvsp[0].string));
}
#line 1469 "mini.tab.c"
    break;

  case 19: /* struct_definition: STRUCT_TOK IDENTIFIER $@2 '{' struct_member_list '}' ';'  */
#line 118 "mini.y"
{
	end_struct(NULL);
	(yyval.tac) = NULL;
}
#line 1478 "mini.tab.c"
    break;

  case 20: /* struct_member_list: %empty  */
#line 125 "mini.y"
{
	 (yyval.tac) = NULL;
}
#line 1486 "mini.tab.c"
    break;

  case 21: /* struct_member_list: struct_member_list struct_member_line  */
#line 129 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-1].tac),(yyvsp[0].tac));
}
#line 1494 "mini.tab.c"
    break;

  case 22: /* struct_member_line: INT IDENTIFIER ';'  */
#line 135 "mini.y"
{
	add_struct_member(NULL,SYM_INT,(yyvsp[-1].string),4);
	(yyval.tac) = NULL;
}
#line 1503 "mini.tab.c"
    break;

  case 23: /* struct_member_line: CHAR IDENTIFIER ';'  */
#line 140 "mini.y"
{ 
	add_struct_member(NULL, SYM_CHAR, (yyvsp[-1].string),1); 
	(yyval.tac) = NULL; 
}
#line 1512 "mini.tab.c"
    break;

  case 24: /* struct_member_line: INT IDENTIFIER LBRACK INTEGER RBRACK ';'  */
#line 145 "mini.y"
{
	add_struct_array_member(NULL,SYM_INT,(yyvsp[-4].string),atoi((yyvsp[-2].string)));
	(yyval.tac) = NULL;
}
#line 1521 "mini.tab.c"
    break;

  case 25: /* struct_member_line: CHAR IDENTIFIER LBRACK INTEGER RBRACK ';'  */
#line 150 "mini.y"
{
	add_struct_array_member(NULL,SYM_CHAR,(yyvsp[-4].string),atoi((yyvsp[-2].string)));
	(yyval.tac)=NULL;
}
#line 1530 "mini.tab.c"
    break;

  case 26: /* struct_member_line: STRUCT_TOK IDENTIFIER IDENTIFIER ';'  */
#line 155 "mini.y"
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
#line 1545 "mini.tab.c"
    break;

  case 27: /* struct_member_line: STRUCT_TOK IDENTIFIER IDENTIFIER LBRACK INTEGER RBRACK ';'  */
#line 166 "mini.y"
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
#line 1560 "mini.tab.c"
    break;

  case 28: /* lvalue: IDENTIFIER  */
#line 180 "mini.y"
{
	(yyval.exp) = mk_exp(NULL,get_var((yyvsp[0].string)),NULL);
}
#line 1568 "mini.tab.c"
    break;

  case 29: /* lvalue: lvalue '.' IDENTIFIER  */
#line 184 "mini.y"
{
	// printf("[DEBUG] . access: %s\n", $3);
    // if (!$1 || !$1->ret)
    //     printf("[DEBUG] $1 or $1->ret is NULL!\n");
    // else
    //     printf("[DEBUG] base type=%d name=%s\n", $1->ret->type, $1->ret->name);
	// int offset = get_struct_offset($1->ret,$3);
	STRUCT_MEMBER *mem = get_struct_member((yyvsp[-2].exp)->ret,(yyvsp[0].string));
	(yyval.exp) = make_struct_field_addr((yyvsp[-2].exp),mem->offset);
	(yyval.exp)->ret->type = mem->type;
	(yyval.exp)->ret->etc = mem->etc;
}
#line 1585 "mini.tab.c"
    break;

  case 30: /* lvalue: lvalue LBRACK expression RBRACK  */
#line 197 "mini.y"
{
	(yyval.exp) = make_array_elem_addr((yyvsp[-3].exp),(yyvsp[-1].exp));
}
#line 1593 "mini.tab.c"
    break;

  case 32: /* variable_list: variable_list ',' decl_item_int  */
#line 203 "mini.y"
{ 
	(yyval.tac) = join_tac((yyvsp[-2].tac), (yyvsp[0].tac)); 
}
#line 1601 "mini.tab.c"
    break;

  case 33: /* decl_item_int: IDENTIFIER  */
#line 209 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_INT); 
}
#line 1609 "mini.tab.c"
    break;

  case 34: /* decl_item_int: '*' IDENTIFIER  */
#line 213 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_PTR); 
}
#line 1617 "mini.tab.c"
    break;

  case 35: /* decl_item_int: IDENTIFIER dims_decl  */
#line 217 "mini.y"
{
	(yyval.tac) = declare_array_typed((yyvsp[-1].string),SYM_INT,(yyvsp[0].exp));
}
#line 1625 "mini.tab.c"
    break;

  case 37: /* variable_list_char: variable_list_char ',' decl_item_char  */
#line 225 "mini.y"
{ 
	(yyval.tac) = join_tac((yyvsp[-2].tac), (yyvsp[0].tac)); 
}
#line 1633 "mini.tab.c"
    break;

  case 38: /* decl_item_char: IDENTIFIER  */
#line 231 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_CHAR); 
}
#line 1641 "mini.tab.c"
    break;

  case 39: /* decl_item_char: '*' IDENTIFIER  */
#line 235 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_PTR); 
}
#line 1649 "mini.tab.c"
    break;

  case 40: /* decl_item_char: IDENTIFIER dims_decl  */
#line 239 "mini.y"
{
	(yyval.tac) = declare_array_typed((yyvsp[-1].string),SYM_CHAR,(yyvsp[0].exp));
}
#line 1657 "mini.tab.c"
    break;

  case 41: /* function: function_head '(' parameter_list ')' block  */
#line 247 "mini.y"
{
	(yyval.tac)=do_func((yyvsp[-4].sym), (yyvsp[-2].tac), (yyvsp[0].tac));
	scope=0; /* Leave local scope. */
	sym_tab_local=NULL; /* Clear local symbol table. */
}
#line 1667 "mini.tab.c"
    break;

  case 42: /* function: error  */
#line 253 "mini.y"
{
	error("Bad function syntax");
	(yyval.tac)=NULL;
}
#line 1676 "mini.tab.c"
    break;

  case 43: /* function_head: IDENTIFIER  */
#line 260 "mini.y"
{
	(yyval.sym)=declare_func((yyvsp[0].string));
	scope=1; /* Enter local scope. */
	sym_tab_local=NULL; /* Init local symbol table. */
}
#line 1686 "mini.tab.c"
    break;

  case 44: /* function_head: INT IDENTIFIER  */
#line 266 "mini.y"
{
	(yyval.sym) = declare_func((yyvsp[0].string));
	scope = 1;
	sym_tab_local = NULL;
}
#line 1696 "mini.tab.c"
    break;

  case 45: /* function_head: CHAR IDENTIFIER  */
#line 272 "mini.y"
{
	(yyval.sym) = declare_func((yyvsp[0].string));
	scope = 1;
	sym_tab_local = NULL;
}
#line 1706 "mini.tab.c"
    break;

  case 46: /* parameter_list: IDENTIFIER  */
#line 280 "mini.y"
{
	(yyval.tac)=declare_para((yyvsp[0].string));
}
#line 1714 "mini.tab.c"
    break;

  case 47: /* parameter_list: parameter_list ',' IDENTIFIER  */
#line 284 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), declare_para((yyvsp[0].string)));
}
#line 1722 "mini.tab.c"
    break;

  case 48: /* parameter_list: INT IDENTIFIER  */
#line 288 "mini.y"
{
	(yyval.tac) = declare_para((yyvsp[0].string));
}
#line 1730 "mini.tab.c"
    break;

  case 49: /* parameter_list: CHAR IDENTIFIER  */
#line 292 "mini.y"
{
	(yyval.tac) = declare_para((yyvsp[0].string));
}
#line 1738 "mini.tab.c"
    break;

  case 50: /* parameter_list: parameter_list ',' INT IDENTIFIER  */
#line 296 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-3].tac),declare_para((yyvsp[0].string)));
}
#line 1746 "mini.tab.c"
    break;

  case 51: /* parameter_list: parameter_list ',' CHAR IDENTIFIER  */
#line 300 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-3].tac),declare_para((yyvsp[0].string)));
}
#line 1754 "mini.tab.c"
    break;

  case 52: /* parameter_list: %empty  */
#line 304 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1762 "mini.tab.c"
    break;

  case 65: /* statement: error  */
#line 322 "mini.y"
{
	error("Bad statement syntax");
	(yyval.tac)=NULL;
}
#line 1771 "mini.tab.c"
    break;

  case 66: /* block: '{' declaration_list statement_list '}'  */
#line 329 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[-1].tac));
}
#line 1779 "mini.tab.c"
    break;

  case 67: /* declaration_list: %empty  */
#line 335 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1787 "mini.tab.c"
    break;

  case 68: /* declaration_list: declaration_list declaration  */
#line 339 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1795 "mini.tab.c"
    break;

  case 70: /* statement_list: statement_list statement  */
#line 346 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1803 "mini.tab.c"
    break;

  case 71: /* assignment_statement: lvalue '=' expression  */
#line 352 "mini.y"
{
	(yyval.tac)=do_assign_lvalue((yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1811 "mini.tab.c"
    break;

  case 72: /* assignment_statement: IDENTIFIER dims_idx '=' expression  */
#line 356 "mini.y"
{
	(yyval.tac) = do_array_store(get_var((yyvsp[-3].string)),(yyvsp[-2].exp),(yyvsp[0].exp));
}
#line 1819 "mini.tab.c"
    break;

  case 73: /* assignment_statement: '*' IDENTIFIER '=' expression  */
#line 360 "mini.y"
{
	SYM *ptr = get_var((yyvsp[-2].string));
	TAC *store = mk_tac(TAC_STORE, ptr, (yyvsp[0].exp)->ret, NULL);
	store->prev = (yyvsp[0].exp)->tac;
	(yyval.tac) = store;
}
#line 1830 "mini.tab.c"
    break;

  case 74: /* assignment_statement: IDENTIFIER '=' '&' IDENTIFIER  */
#line 367 "mini.y"
{
    SYM *dst = get_var((yyvsp[-3].string));
    SYM *src = get_var((yyvsp[0].string));
    TAC *addr = mk_tac(TAC_ADDR, dst, src, NULL);
    (yyval.tac) = addr;
}
#line 1841 "mini.tab.c"
    break;

  case 75: /* assignment_statement: IDENTIFIER '=' '*' IDENTIFIER  */
#line 374 "mini.y"
{
    SYM *dst = get_var((yyvsp[-3].string));
    SYM *src = get_var((yyvsp[0].string));
    TAC *load = mk_tac(TAC_LOAD, dst, src, NULL);
    (yyval.tac) = load;
}
#line 1852 "mini.tab.c"
    break;

  case 76: /* expression: expression '+' expression  */
#line 389 "mini.y"
{
	(yyval.exp)=do_bin(TAC_ADD, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1860 "mini.tab.c"
    break;

  case 77: /* expression: expression '-' expression  */
#line 393 "mini.y"
{
	(yyval.exp)=do_bin(TAC_SUB, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1868 "mini.tab.c"
    break;

  case 78: /* expression: expression '*' expression  */
#line 397 "mini.y"
{
	(yyval.exp)=do_bin(TAC_MUL, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1876 "mini.tab.c"
    break;

  case 79: /* expression: expression '/' expression  */
#line 401 "mini.y"
{
	(yyval.exp)=do_bin(TAC_DIV, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1884 "mini.tab.c"
    break;

  case 80: /* expression: '-' expression  */
#line 405 "mini.y"
{
	(yyval.exp)=do_un(TAC_NEG, (yyvsp[0].exp));
}
#line 1892 "mini.tab.c"
    break;

  case 81: /* expression: expression EQ expression  */
#line 409 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_EQ, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1900 "mini.tab.c"
    break;

  case 82: /* expression: expression NE expression  */
#line 413 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_NE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1908 "mini.tab.c"
    break;

  case 83: /* expression: expression LT expression  */
#line 417 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1916 "mini.tab.c"
    break;

  case 84: /* expression: expression LE expression  */
#line 421 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1924 "mini.tab.c"
    break;

  case 85: /* expression: expression GT expression  */
#line 425 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1932 "mini.tab.c"
    break;

  case 86: /* expression: expression GE expression  */
#line 429 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1940 "mini.tab.c"
    break;

  case 87: /* expression: '(' expression ')'  */
#line 433 "mini.y"
{
	(yyval.exp)=(yyvsp[-1].exp);
}
#line 1948 "mini.tab.c"
    break;

  case 88: /* expression: INTEGER  */
#line 437 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_const(atoi((yyvsp[0].string))), NULL);
}
#line 1956 "mini.tab.c"
    break;

  case 89: /* expression: CHAR_CONST  */
#line 445 "mini.y"
{
	(yyval.exp)=mk_exp(NULL,mk_char((yyvsp[0].string)[1]),NULL);
}
#line 1964 "mini.tab.c"
    break;

  case 90: /* expression: IDENTIFIER dims_idx  */
#line 449 "mini.y"
{
	(yyval.exp) = do_array_load(get_var((yyvsp[-1].string)),(yyvsp[0].exp));  // 加载数组值
}
#line 1972 "mini.tab.c"
    break;

  case 91: /* expression: call_expression  */
#line 453 "mini.y"
{
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1980 "mini.tab.c"
    break;

  case 92: /* expression: lvalue  */
#line 457 "mini.y"
{
	(yyval.exp) = do_load_lvalue((yyvsp[0].exp));
}
#line 1988 "mini.tab.c"
    break;

  case 93: /* expression: error  */
#line 467 "mini.y"
{
	error("Bad expression syntax");
	(yyval.exp)=mk_exp(NULL, NULL, NULL);
}
#line 1997 "mini.tab.c"
    break;

  case 94: /* argument_list: %empty  */
#line 474 "mini.y"
{
	(yyval.exp)=NULL;
}
#line 2005 "mini.tab.c"
    break;

  case 97: /* expression_list: expression_list ',' expression  */
#line 482 "mini.y"
{
	(yyvsp[0].exp)->next=(yyvsp[-2].exp);
	(yyval.exp)=(yyvsp[0].exp);
}
#line 2014 "mini.tab.c"
    break;

  case 98: /* input_statement: INPUT IDENTIFIER  */
#line 489 "mini.y"
{
	(yyval.tac)=do_input(get_var((yyvsp[0].string)));
}
#line 2022 "mini.tab.c"
    break;

  case 99: /* output_statement: OUTPUT IDENTIFIER  */
#line 495 "mini.y"
{
	(yyval.tac)=do_output(get_var((yyvsp[0].string)));
}
#line 2030 "mini.tab.c"
    break;

  case 100: /* output_statement: OUTPUT TEXT  */
#line 499 "mini.y"
{
	(yyval.tac)=do_output(mk_text((yyvsp[0].string)));
}
#line 2038 "mini.tab.c"
    break;

  case 101: /* output_statement: OUTPUT expression  */
#line 503 "mini.y"
{
	TAC*t = mk_tac(TAC_OUTPUT,(yyvsp[0].exp)->ret,NULL,NULL);
	t->prev = (yyvsp[0].exp)->tac;
	(yyval.tac) = t;
}
#line 2048 "mini.tab.c"
    break;

  case 102: /* return_statement: RETURN expression  */
#line 511 "mini.y"
{
	TAC *t=mk_tac(TAC_RETURN, (yyvsp[0].exp)->ret, NULL, NULL);
	t->prev=(yyvsp[0].exp)->tac;
	(yyval.tac)=t;
}
#line 2058 "mini.tab.c"
    break;

  case 103: /* if_statement: IF '(' expression ')' block  */
#line 519 "mini.y"
{
	(yyval.tac)=do_if((yyvsp[-2].exp), (yyvsp[0].tac));
}
#line 2066 "mini.tab.c"
    break;

  case 104: /* if_statement: IF '(' expression ')' block ELSE block  */
#line 523 "mini.y"
{
	(yyval.tac)=do_test((yyvsp[-4].exp), (yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 2074 "mini.tab.c"
    break;

  case 105: /* $@3: %empty  */
#line 530 "mini.y"
    {
      g_switch_end = mk_label(mk_lstr(next_label++));
      push_loop_labels(NULL, g_switch_end);  // 同for, 只有end
    }
#line 2083 "mini.tab.c"
    break;

  case 106: /* switch_statement: SWITCH '(' expression ')' $@3 '{' case_list default_list '}'  */
#line 535 "mini.y"
    {
      (yyval.tac) = do_switch((yyvsp[-6].exp), (yyvsp[-2].tac), (yyvsp[-1].tac), g_switch_end);
      pop_loop_labels();
      g_switch_end = NULL;
    }
#line 2093 "mini.tab.c"
    break;

  case 107: /* case_list: case_item  */
#line 543 "mini.y"
           { (yyval.tac) = (yyvsp[0].tac); }
#line 2099 "mini.tab.c"
    break;

  case 108: /* case_list: case_list case_item  */
#line 545 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-1].tac),(yyvsp[0].tac));
}
#line 2107 "mini.tab.c"
    break;

  case 109: /* case_item: CASE INTEGER ':' statement_list  */
#line 551 "mini.y"
{
	(yyval.tac) = do_case(atoi((yyvsp[-2].string)),(yyvsp[0].tac));
}
#line 2115 "mini.tab.c"
    break;

  case 110: /* default_list: %empty  */
#line 557 "mini.y"
{
	 (yyval.tac) = NULL; 
}
#line 2123 "mini.tab.c"
    break;

  case 111: /* default_list: DEFAULT ':' statement_list  */
#line 561 "mini.y"
{ 
	(yyval.tac) = (yyvsp[0].tac); 
}
#line 2131 "mini.tab.c"
    break;

  case 112: /* $@4: %empty  */
#line 566 "mini.y"
{
	g_for_start = mk_label(mk_lstr(next_label++));
    g_for_cont  = mk_label(mk_lstr(next_label++));
    g_for_end   = mk_label(mk_lstr(next_label++));
    push_loop_labels(g_for_cont, g_for_end);
}
#line 2142 "mini.tab.c"
    break;

  case 113: /* while_statement: WHILE '(' expression ')' $@4 block  */
#line 573 "mini.y"
{
	(yyval.tac)=do_while((yyvsp[-3].exp), (yyvsp[0].tac),g_for_start,g_for_cont,g_for_end);
	pop_loop_labels();
	g_for_start = g_for_cont = g_for_end = NULL;
}
#line 2152 "mini.tab.c"
    break;

  case 114: /* $@5: %empty  */
#line 583 "mini.y"
    {
      g_for_start = mk_label(mk_lstr(next_label++));
      g_for_cont  = mk_label(mk_lstr(next_label++));
      g_for_end   = mk_label(mk_lstr(next_label++));
      push_loop_labels(g_for_cont, g_for_end);
    }
#line 2163 "mini.tab.c"
    break;

  case 115: /* for_statement: FOR '(' opt_statement ';' opt_expression ';' opt_statement ')' $@5 block  */
#line 590 "mini.y"
    {
      (yyval.tac) = do_for((yyvsp[-7].tac), (yyvsp[-5].exp), (yyvsp[-3].tac), (yyvsp[0].tac), g_for_start, g_for_cont, g_for_end);
      pop_loop_labels();
      g_for_start = g_for_cont = g_for_end = NULL;
    }
#line 2173 "mini.tab.c"
    break;

  case 116: /* opt_statement: assignment_statement  */
#line 600 "mini.y"
{
	(yyval.tac) = (yyvsp[0].tac);
}
#line 2181 "mini.tab.c"
    break;

  case 117: /* opt_statement: %empty  */
#line 604 "mini.y"
{
	(yyval.tac) = NULL;
}
#line 2189 "mini.tab.c"
    break;

  case 118: /* opt_expression: expression  */
#line 610 "mini.y"
{
	(yyval.exp) = (yyvsp[0].exp);
}
#line 2197 "mini.tab.c"
    break;

  case 119: /* opt_expression: %empty  */
#line 614 "mini.y"
{
	(yyval.exp) = NULL;
}
#line 2205 "mini.tab.c"
    break;

  case 120: /* break_statement: BREAK  */
#line 620 "mini.y"
{
	(yyval.tac)=do_break();
}
#line 2213 "mini.tab.c"
    break;

  case 121: /* continue_statement: CONTINUE  */
#line 626 "mini.y"
{
	(yyval.tac)=do_continue();
}
#line 2221 "mini.tab.c"
    break;

  case 122: /* call_statement: IDENTIFIER '(' argument_list ')'  */
#line 632 "mini.y"
{
	(yyval.tac)=do_call((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 2229 "mini.tab.c"
    break;

  case 123: /* call_expression: IDENTIFIER '(' argument_list ')'  */
#line 638 "mini.y"
{
	(yyval.exp)=do_call_ret((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 2237 "mini.tab.c"
    break;


#line 2241 "mini.tab.c"

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

#line 643 "mini.y"


void yyerror(char* msg) 
{
	fprintf(stderr, "%s: line %d\n", msg, yylineno);
	exit(0);
}
