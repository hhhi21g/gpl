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

#define LOOP_MAX_DEPTH 100

static SYM *g_for_start_stack[LOOP_MAX_DEPTH];
static SYM *g_for_cont_stack[LOOP_MAX_DEPTH];
static SYM *g_for_end_stack[LOOP_MAX_DEPTH];
static int g_for_depth = 0;


PATH *append_path_list(PATH *head, PATH *tail);



#line 100 "mini.y.c"

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
  YYSYMBOL_lvalue_tail_opt = 72,           /* lvalue_tail_opt  */
  YYSYMBOL_lvalue_tail = 73,               /* lvalue_tail  */
  YYSYMBOL_assignment_statement = 74,      /* assignment_statement  */
  YYSYMBOL_expression = 75,                /* expression  */
  YYSYMBOL_argument_list = 76,             /* argument_list  */
  YYSYMBOL_expression_list = 77,           /* expression_list  */
  YYSYMBOL_input_statement = 78,           /* input_statement  */
  YYSYMBOL_output_statement = 79,          /* output_statement  */
  YYSYMBOL_return_statement = 80,          /* return_statement  */
  YYSYMBOL_if_statement = 81,              /* if_statement  */
  YYSYMBOL_switch_statement = 82,          /* switch_statement  */
  YYSYMBOL_83_3 = 83,                      /* $@3  */
  YYSYMBOL_case_list = 84,                 /* case_list  */
  YYSYMBOL_case_item = 85,                 /* case_item  */
  YYSYMBOL_default_list = 86,              /* default_list  */
  YYSYMBOL_while_statement = 87,           /* while_statement  */
  YYSYMBOL_88_4 = 88,                      /* $@4  */
  YYSYMBOL_for_statement = 89,             /* for_statement  */
  YYSYMBOL_90_5 = 90,                      /* $@5  */
  YYSYMBOL_opt_statement = 91,             /* opt_statement  */
  YYSYMBOL_opt_expression = 92,            /* opt_expression  */
  YYSYMBOL_break_statement = 93,           /* break_statement  */
  YYSYMBOL_continue_statement = 94,        /* continue_statement  */
  YYSYMBOL_call_statement = 95,            /* call_statement  */
  YYSYMBOL_call_expression = 96            /* call_expression  */
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
typedef yytype_int16 yy_state_t;

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
#define YYLAST   425

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  266

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
       0,    57,    57,    65,    66,    72,    73,    74,    77,    81,
      89,    93,   101,   105,   109,   109,   116,   120,   126,   130,
     139,   138,   150,   153,   159,   164,   169,   173,   177,   182,
     187,   192,   199,   200,   206,   210,   214,   221,   222,   228,
     232,   236,   244,   250,   257,   263,   269,   277,   281,   285,
     289,   293,   297,   302,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   326,   333,   336,
     342,   343,   349,   355,   366,   367,   371,   375,   379,   383,
     389,   393,   397,   404,   411,   424,   431,   436,   440,   444,
     448,   452,   456,   460,   464,   468,   472,   476,   480,   484,
     488,   492,   496,   500,   504,   512,   522,   530,   533,   536,
     537,   544,   550,   554,   558,   566,   574,   578,   586,   585,
     599,   600,   606,   613,   616,   622,   621,   665,   664,   681,
     686,   691,   696,   701,   707,   713,   719
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
  "declaration_list", "statement_list", "lvalue_path", "lvalue_tail_opt",
  "lvalue_tail", "assignment_statement", "expression", "argument_list",
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

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-133)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,  -122,    96,   -18,  -122,   115,    12,    20,  -122,  -122,
    -122,  -122,     0,   -24,    28,    42,  -122,    60,   -23,    49,
     175,  -122,  -122,  -122,     3,    76,    86,  -122,  -122,   126,
      95,    88,    86,  -122,  -122,   135,   106,  -122,   131,    98,
     143,   121,   138,  -122,   138,   177,  -122,   138,  -122,  -122,
    -122,    23,   134,  -122,   148,    86,  -122,   155,     8,   161,
    -122,   164,  -122,  -122,  -122,   138,   137,   169,   141,   167,
    -122,  -122,  -122,   268,    86,    29,   181,   189,    46,   193,
    -122,  -122,   126,   197,   191,   195,   199,   200,  -122,  -122,
     211,    37,   133,   -16,   135,   215,  -122,  -122,  -122,   210,
     203,   206,   207,   209,   217,  -122,  -122,  -122,  -122,   218,
     223,   227,   222,  -122,   229,   120,   226,  -122,   230,  -122,
     133,   133,   133,   144,  -122,  -122,  -122,    27,  -122,  -122,
     133,   133,   241,  -122,   389,  -122,    27,   389,   133,    74,
     243,    94,    30,   228,  -122,  -122,   133,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,   242,  -122,   249,  -122,   244,  -122,
     305,   317,   327,    53,  -122,   247,    74,    38,  -122,   366,
      67,  -122,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   377,   389,   248,   260,    82,   253,   258,   389,
     133,   288,   133,   133,   389,   280,   286,   282,   134,  -122,
    -122,   111,   285,  -122,    38,   151,   151,   151,   151,   151,
     151,    10,    10,  -122,  -122,  -122,  -122,   133,   301,   298,
    -122,   101,  -122,   112,   383,    82,   389,   389,  -122,   293,
    -122,   323,   303,   134,   389,   306,  -122,   389,  -122,   318,
     298,  -122,  -122,  -122,   134,   328,  -122,   144,  -122,  -122,
     320,   202,  -122,   307,   302,   308,  -122,   315,  -122,   281,
     281,  -122,   134,   182,   238,  -122
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    43,     0,     0,    44,     0,     0,     0,     3,     6,
       7,     5,     0,    34,     0,     0,    32,    14,    39,     0,
       0,    37,     1,     4,    53,     0,    36,    35,    12,     0,
       0,     0,    41,    40,    13,     0,     0,    47,     0,     0,
       0,     0,    34,    33,    16,     0,    22,    39,    38,    49,
      50,     0,     0,     8,     0,    17,    15,     0,     0,     0,
      48,     0,    68,    42,     9,    18,     0,     0,     0,     0,
      23,    51,    52,     0,    19,     0,     0,     0,     0,     0,
      21,    66,     0,     0,     0,     0,     0,     0,   133,   134,
       0,     0,     0,     0,     0,     0,    69,    70,    54,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,     0,
       0,     0,     0,    24,     0,     0,     0,    25,     0,    14,
       0,     0,     0,   130,   111,   106,    99,    86,   113,   101,
       0,     0,     0,   100,   114,   103,    86,   115,     0,     0,
       0,     0,     0,     0,    67,    71,     0,    55,    56,    57,
      59,    64,    65,    58,     0,    26,     0,    30,     0,    27,
       0,     0,     0,     0,   129,     0,     0,   102,    91,     0,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,     0,   108,    74,     0,     0,    80,
       0,     0,     0,     0,    85,     0,     0,     0,     0,   118,
     125,     0,     0,    98,     0,    92,    93,    94,    95,    96,
      97,    87,    88,    89,    90,    10,   135,     0,     0,    77,
      72,    75,    84,   104,     0,    74,    81,    82,    28,     0,
      29,   116,     0,     0,   131,     0,   136,   110,    76,     0,
      79,    11,    73,    31,     0,     0,   126,   130,    78,   117,
       0,   123,   120,     0,     0,     0,   121,     0,   127,     0,
       0,   119,     0,     0,     0,   128
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,   349,    -8,  -114,   284,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,   329,  -122,   330,  -122,  -122,  -122,
     -98,   -52,  -122,   -33,   -70,   139,  -122,  -121,   -87,   201,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,   117,  -122,
    -122,  -122,  -122,  -122,   119,  -122,  -122,  -122,  -122,  -122
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,     7,     8,    26,   142,     9,    30,    45,    10,
      31,    58,    70,    15,    16,    20,    21,    11,    12,    39,
      97,    98,    73,    99,   133,   220,   221,   101,   183,   184,
     185,   102,   103,   104,   105,   106,   232,   251,   252,   257,
     107,   233,   108,   262,   165,   235,   109,   110,   111,   135
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,   145,   164,   100,   134,   137,    36,    25,    25,    17,
      32,    66,    22,   167,     1,   138,     2,   -45,   -46,    67,
      -2,     1,   167,     2,     3,   139,    59,   140,   141,   100,
      37,     3,    38,   160,   161,   162,    55,    68,   125,    32,
       4,    24,     5,   168,   169,   180,   181,     4,    69,     5,
      60,   182,    61,   100,   189,    27,   204,    74,   138,   194,
     112,   190,   171,   126,   127,   128,   113,   129,   166,   190,
     140,   130,   219,   191,   192,   125,    33,   116,   131,    28,
      29,   191,   132,   117,   138,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   125,   140,   141,   138,   -20,
     126,   136,    40,   224,   129,   226,   227,   240,   130,   204,
     140,   219,   125,   138,   234,   131,  -107,    41,   171,   132,
     126,   136,    44,    13,   129,   218,   164,    46,   130,   187,
     237,    14,   138,    49,   125,   131,    51,   126,   136,   188,
      52,   129,    18,   138,   239,   130,   231,    54,  -132,   -83,
      19,   156,   131,    42,   -83,   140,   132,   157,    50,   126,
     136,    14,    47,   129,    75,   145,   145,   130,    78,    25,
      19,   163,    76,    62,   131,    53,    79,   100,   132,    95,
      64,   246,    65,    81,   178,   179,   180,   181,    71,   100,
     100,    72,   249,   100,   100,    84,    77,    85,  -122,  -122,
      86,    87,    88,    89,    80,    90,    91,    92,   114,    93,
     265,    81,    34,    35,    56,    57,   115,    95,   250,   255,
     118,    62,  -122,    84,   119,    85,   263,   264,    86,    87,
      88,    89,   120,    90,    91,    92,   121,    93,   124,    81,
     122,   123,   143,   147,   148,    95,   149,   146,   154,    62,
     144,    84,   158,    85,   150,   151,    86,    87,    88,    89,
     152,    90,    91,    92,   153,    93,   155,   159,   170,    81,
     186,    82,   193,    95,   195,   196,   197,    62,  -124,    83,
     222,    84,    81,    85,   201,   223,    86,    87,    88,    89,
     216,    90,    91,    92,    84,    93,    85,    94,   217,    86,
      87,    88,    89,    95,    90,    91,    92,    62,    93,   172,
     173,   174,   175,   176,   177,   225,    95,   228,   229,   230,
      62,   172,   173,   174,   175,   176,   177,   236,   238,   190,
     243,   172,   173,   174,   175,   176,   177,   244,   178,   179,
     180,   181,   245,   247,   250,   248,   254,   198,   259,   258,
     178,   179,   180,   181,   260,   261,    23,    96,    43,   199,
     178,   179,   180,   181,   242,    48,   253,   202,   256,   200,
     172,   173,   174,   175,   176,   177,     0,     0,     0,     0,
       0,   172,   173,   174,   175,   176,   177,   172,   173,   174,
     175,   176,   177,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,     0,     0,     0,     0,     0,   203,   215,
     178,   179,   180,   181,     0,   241,   178,   179,   180,   181,
       0,     0,   178,   179,   180,   181
};

static const yytype_int16 yycheck[] =
{
      52,    99,   123,    73,    91,    92,     3,    31,    31,    27,
      18,     3,     0,   127,     1,    31,     3,    41,    41,    11,
       0,     1,   136,     3,    11,    41,     3,    43,    44,    99,
      27,    11,    29,   120,   121,   122,    44,    29,     1,    47,
      27,    41,    29,   130,   131,    35,    36,    27,    40,    29,
      27,   138,    29,   123,   141,    27,   170,    65,    31,   146,
      31,    31,   132,    26,    27,    28,    37,    30,    41,    31,
      43,    34,   186,    43,    44,     1,    27,    31,    41,    37,
      38,    43,    45,    37,    31,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,     1,    43,    44,    31,    39,
      26,    27,    26,   190,    30,   192,   193,   221,    34,   223,
      43,   225,     1,    31,   201,    41,    42,    31,   188,    45,
      26,    27,    27,    27,    30,    43,   247,    39,    34,    35,
     217,    35,    31,    27,     1,    41,    38,    26,    27,    45,
      42,    30,    27,    31,    43,    34,   198,    26,    37,    37,
      35,    31,    41,    27,    42,    43,    45,    37,    27,    26,
      27,    35,    27,    30,    27,   263,   264,    34,    27,    31,
      35,    27,    35,    39,    41,    32,    35,   247,    45,    35,
      32,   233,    27,     1,    33,    34,    35,    36,    27,   259,
     260,    27,   244,   263,   264,    13,    27,    15,    16,    17,
      18,    19,    20,    21,    37,    23,    24,    25,    27,    27,
     262,     1,    37,    38,    37,    38,    27,    35,    16,    17,
      27,    39,    40,    13,    27,    15,   259,   260,    18,    19,
      20,    21,    41,    23,    24,    25,    41,    27,    27,     1,
      41,    41,    27,    37,    37,    35,    37,    44,    26,    39,
      40,    13,    26,    15,    37,    37,    18,    19,    20,    21,
      37,    23,    24,    25,    37,    27,    37,    37,    27,     1,
      27,     3,    44,    35,    32,    26,    32,    39,    40,    11,
      27,    13,     1,    15,    37,    27,    18,    19,    20,    21,
      42,    23,    24,    25,    13,    27,    15,    29,    38,    18,
      19,    20,    21,    35,    23,    24,    25,    39,    27,     4,
       5,     6,     7,     8,     9,    27,    35,    37,    32,    37,
      39,     4,     5,     6,     7,     8,     9,    42,    27,    31,
      37,     4,     5,     6,     7,     8,     9,    14,    33,    34,
      35,    36,    39,    37,    16,    27,    26,    42,    46,    42,
      33,    34,    35,    36,    46,    40,     7,    73,    29,    42,
      33,    34,    35,    36,   225,    35,   247,   166,   251,    42,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,     7,     8,     9,     4,     5,     6,
       7,     8,     9,     4,     5,     6,     7,     8,     9,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,    32,
      33,    34,    35,    36,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    33,    34,    35,    36
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
      27,    38,    42,    32,    26,    51,    37,    38,    58,     3,
      27,    29,    39,    68,    32,    27,     3,    11,    29,    40,
      59,    27,    27,    69,    51,    27,    35,    27,    27,    35,
      37,     1,     3,    11,    13,    15,    18,    19,    20,    21,
      23,    24,    25,    27,    29,    35,    53,    67,    68,    70,
      71,    74,    78,    79,    80,    81,    82,    87,    89,    93,
      94,    95,    31,    37,    27,    27,    31,    37,    27,    27,
      41,    41,    41,    41,    27,     1,    26,    27,    28,    30,
      34,    41,    45,    71,    75,    96,    27,    75,    31,    41,
      43,    44,    52,    27,    40,    67,    44,    37,    37,    37,
      37,    37,    37,    37,    26,    37,    31,    37,    26,    37,
      75,    75,    75,    27,    74,    91,    41,    52,    75,    75,
      27,    71,     4,     5,     6,     7,     8,     9,    33,    34,
      35,    36,    75,    75,    76,    77,    27,    35,    45,    75,
      31,    43,    44,    44,    75,    32,    26,    32,    42,    42,
      42,    37,    76,    42,    52,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    32,    42,    38,    43,    52,
      72,    73,    27,    27,    75,    27,    75,    75,    37,    32,
      37,    68,    83,    88,    75,    92,    42,    75,    27,    43,
      52,    32,    72,    37,    14,    39,    68,    37,    27,    68,
      16,    84,    85,    91,    26,    17,    85,    86,    42,    46,
      46,    40,    90,    70,    70,    68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    53,    55,    55,    55,    55,
      57,    56,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    61,    61,    61,    62,    62,    63,
      63,    63,    64,    64,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    69,    69,
      70,    70,    71,    71,    72,    72,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    77,
      77,    78,    79,    79,    79,    80,    81,    81,    83,    82,
      84,    84,    85,    86,    86,    88,    87,    90,    89,    91,
      91,    92,    92,    93,    94,    95,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     3,     4,
       3,     4,     3,     3,     0,     5,     1,     2,     3,     4,
       0,     7,     0,     2,     3,     3,     4,     4,     6,     6,
       4,     7,     1,     3,     1,     2,     2,     1,     3,     1,
       2,     2,     5,     1,     1,     2,     2,     1,     3,     2,
       2,     4,     4,     0,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     2,     2,     1,     4,     0,     2,
       1,     2,     4,     5,     0,     1,     2,     1,     3,     2,
       3,     4,     4,     4,     4,     3,     1,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     2,     1,     2,     2,     1,     0,     1,     1,
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
#line 58 "mini.y"
{
	tac_last=(yyvsp[0].tac);
	tac_complete();
}
#line 1401 "mini.y.c"
    break;

  case 4: /* function_declaration_list: function_declaration_list function_declaration  */
#line 67 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1409 "mini.y.c"
    break;

  case 8: /* dims_decl: LBRACK INTEGER RBRACK  */
#line 78 "mini.y"
{
	(yyval.exp)=mk_exp(NULL,mk_const(atoi((yyvsp[-1].string))),NULL);
}
#line 1417 "mini.y.c"
    break;

  case 9: /* dims_decl: dims_decl LBRACK INTEGER RBRACK  */
#line 82 "mini.y"
{
	EXP *node = mk_exp(NULL,mk_const(atoi((yyvsp[-1].string))),NULL);
	node->next = (yyvsp[-3].exp);
	(yyval.exp) = node;
}
#line 1427 "mini.y.c"
    break;

  case 10: /* dims_idx: LBRACK expression RBRACK  */
#line 90 "mini.y"
{
	(yyval.exp) = mk_exp(NULL,(yyvsp[-1].exp)->ret,(yyvsp[-1].exp)->tac);
}
#line 1435 "mini.y.c"
    break;

  case 11: /* dims_idx: dims_idx LBRACK expression RBRACK  */
#line 94 "mini.y"
{
	EXP*node = mk_exp(NULL,(yyvsp[-1].exp)->ret,(yyvsp[-1].exp)->tac);
	node->next = (yyvsp[-3].exp);
	(yyval.exp) = node;
}
#line 1445 "mini.y.c"
    break;

  case 12: /* declaration: INT variable_list ';'  */
#line 102 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1453 "mini.y.c"
    break;

  case 13: /* declaration: CHAR variable_list_char ';'  */
#line 106 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1461 "mini.y.c"
    break;

  case 14: /* $@1: %empty  */
#line 109 "mini.y"
                        {g_cur_struct = (yyvsp[0].string);}
#line 1467 "mini.y.c"
    break;

  case 15: /* declaration: STRUCT_TOK IDENTIFIER $@1 struct_var_list ';'  */
#line 110 "mini.y"
{
	(yyval.tac) = (yyvsp[-1].tac);
	g_cur_struct = NULL;
}
#line 1476 "mini.y.c"
    break;

  case 16: /* struct_var_list: IDENTIFIER  */
#line 117 "mini.y"
{ 
	(yyval.tac) = declare_struct((yyvsp[0].string), g_cur_struct); 
}
#line 1484 "mini.y.c"
    break;

  case 17: /* struct_var_list: IDENTIFIER dims_decl  */
#line 121 "mini.y"
{
	(yyval.tac) = declare_array_typed((yyvsp[-1].string),SYM_STRUCT,(yyvsp[0].exp));
	SYM*sym = get_var((yyvsp[-1].string));
	sym->etc2 = find_struct(g_cur_struct);
}
#line 1494 "mini.y.c"
    break;

  case 18: /* struct_var_list: struct_var_list ',' IDENTIFIER  */
#line 127 "mini.y"
{ 
	(yyval.tac) = join_tac((yyvsp[-2].tac), declare_struct((yyvsp[0].string), g_cur_struct)); 
}
#line 1502 "mini.y.c"
    break;

  case 19: /* struct_var_list: struct_var_list ',' IDENTIFIER dims_decl  */
#line 130 "mini.y"
                                          {
	(yyval.tac) = declare_array_typed((yyvsp[-1].string),SYM_STRUCT,(yyvsp[0].exp));
	SYM*sym = get_var((yyvsp[-1].string));
	sym->etc2 = find_struct(g_cur_struct);
}
#line 1512 "mini.y.c"
    break;

  case 20: /* $@2: %empty  */
#line 139 "mini.y"
{
	begin_struct((yyvsp[0].string));
}
#line 1520 "mini.y.c"
    break;

  case 21: /* struct_definition: STRUCT_TOK IDENTIFIER $@2 '{' struct_member_list '}' ';'  */
#line 143 "mini.y"
{
	end_struct(NULL);
	(yyval.tac) = NULL;
}
#line 1529 "mini.y.c"
    break;

  case 22: /* struct_member_list: %empty  */
#line 150 "mini.y"
{
	 (yyval.tac) = NULL;
}
#line 1537 "mini.y.c"
    break;

  case 23: /* struct_member_list: struct_member_list struct_member_line  */
#line 154 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-1].tac),(yyvsp[0].tac));
}
#line 1545 "mini.y.c"
    break;

  case 24: /* struct_member_line: INT IDENTIFIER ';'  */
#line 160 "mini.y"
{
	add_struct_member(NULL,SYM_INT,(yyvsp[-1].string));
	(yyval.tac) = NULL;
}
#line 1554 "mini.y.c"
    break;

  case 25: /* struct_member_line: CHAR IDENTIFIER ';'  */
#line 165 "mini.y"
{ 
	add_struct_member(NULL, SYM_CHAR, (yyvsp[-1].string)); 
	(yyval.tac) = NULL; 
}
#line 1563 "mini.y.c"
    break;

  case 26: /* struct_member_line: INT '*' IDENTIFIER ';'  */
#line 170 "mini.y"
{
	add_struct_member(NULL,SYM_PTR,(yyvsp[-1].string));
}
#line 1571 "mini.y.c"
    break;

  case 27: /* struct_member_line: CHAR '*' IDENTIFIER ';'  */
#line 174 "mini.y"
{
	add_struct_member(NULL,SYM_PTR,(yyvsp[-1].string));
}
#line 1579 "mini.y.c"
    break;

  case 28: /* struct_member_line: INT IDENTIFIER LBRACK INTEGER RBRACK ';'  */
#line 178 "mini.y"
{
	add_struct_member_array(NULL,SYM_INT,(yyvsp[-4].string),atoi((yyvsp[-2].string)));
	(yyval.tac) = NULL;
}
#line 1588 "mini.y.c"
    break;

  case 29: /* struct_member_line: CHAR IDENTIFIER LBRACK INTEGER RBRACK ';'  */
#line 183 "mini.y"
{
	add_struct_member_array(NULL,SYM_CHAR,(yyvsp[-4].string),atoi((yyvsp[-2].string)));
	(yyval.tac) = NULL;
}
#line 1597 "mini.y.c"
    break;

  case 30: /* struct_member_line: STRUCT_TOK IDENTIFIER IDENTIFIER ';'  */
#line 188 "mini.y"
{
	add_struct_member_struct((yyvsp[-2].string),(yyvsp[-1].string));
	(yyval.tac) = NULL;
}
#line 1606 "mini.y.c"
    break;

  case 31: /* struct_member_line: STRUCT_TOK IDENTIFIER IDENTIFIER LBRACK INTEGER RBRACK ';'  */
#line 193 "mini.y"
{
	add_struct_member_struct_array((yyvsp[-5].string),(yyvsp[-4].string),atoi((yyvsp[-2].string)));
	(yyval.tac) = NULL;
}
#line 1615 "mini.y.c"
    break;

  case 33: /* variable_list: variable_list ',' decl_item_int  */
#line 201 "mini.y"
{ 
	(yyval.tac) = join_tac((yyvsp[-2].tac), (yyvsp[0].tac)); 
}
#line 1623 "mini.y.c"
    break;

  case 34: /* decl_item_int: IDENTIFIER  */
#line 207 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_INT); 
}
#line 1631 "mini.y.c"
    break;

  case 35: /* decl_item_int: '*' IDENTIFIER  */
#line 211 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_PTR); 
}
#line 1639 "mini.y.c"
    break;

  case 36: /* decl_item_int: IDENTIFIER dims_decl  */
#line 215 "mini.y"
{
	(yyval.tac) = declare_array_typed((yyvsp[-1].string),SYM_INT,(yyvsp[0].exp));
}
#line 1647 "mini.y.c"
    break;

  case 38: /* variable_list_char: variable_list_char ',' decl_item_char  */
#line 223 "mini.y"
{ 
	(yyval.tac) = join_tac((yyvsp[-2].tac), (yyvsp[0].tac)); 
}
#line 1655 "mini.y.c"
    break;

  case 39: /* decl_item_char: IDENTIFIER  */
#line 229 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_CHAR); 
}
#line 1663 "mini.y.c"
    break;

  case 40: /* decl_item_char: '*' IDENTIFIER  */
#line 233 "mini.y"
{ 
	(yyval.tac) = declare_var_typed((yyvsp[0].string), SYM_PTR); 
}
#line 1671 "mini.y.c"
    break;

  case 41: /* decl_item_char: IDENTIFIER dims_decl  */
#line 237 "mini.y"
{
	(yyval.tac) = declare_array_typed((yyvsp[-1].string),SYM_CHAR,(yyvsp[0].exp));
}
#line 1679 "mini.y.c"
    break;

  case 42: /* function: function_head '(' parameter_list ')' block  */
#line 245 "mini.y"
{
	(yyval.tac)=do_func((yyvsp[-4].sym), (yyvsp[-2].tac), (yyvsp[0].tac));
	scope=0; /* Leave local scope. */
	sym_tab_local=NULL; /* Clear local symbol table. */
}
#line 1689 "mini.y.c"
    break;

  case 43: /* function: error  */
#line 251 "mini.y"
{
	error("Bad function syntax");
	(yyval.tac)=NULL;
}
#line 1698 "mini.y.c"
    break;

  case 44: /* function_head: IDENTIFIER  */
#line 258 "mini.y"
{
	(yyval.sym)=declare_func((yyvsp[0].string));
	scope=1; /* Enter local scope. */
	sym_tab_local=NULL; /* Init local symbol table. */
}
#line 1708 "mini.y.c"
    break;

  case 45: /* function_head: INT IDENTIFIER  */
#line 264 "mini.y"
{
	(yyval.sym) = declare_func((yyvsp[0].string));
	scope = 1;
	sym_tab_local = NULL;
}
#line 1718 "mini.y.c"
    break;

  case 46: /* function_head: CHAR IDENTIFIER  */
#line 270 "mini.y"
{
	(yyval.sym) = declare_func((yyvsp[0].string));
	scope = 1;
	sym_tab_local = NULL;
}
#line 1728 "mini.y.c"
    break;

  case 47: /* parameter_list: IDENTIFIER  */
#line 278 "mini.y"
{
	(yyval.tac)=declare_para((yyvsp[0].string));
}
#line 1736 "mini.y.c"
    break;

  case 48: /* parameter_list: parameter_list ',' IDENTIFIER  */
#line 282 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), declare_para((yyvsp[0].string)));
}
#line 1744 "mini.y.c"
    break;

  case 49: /* parameter_list: INT IDENTIFIER  */
#line 286 "mini.y"
{
	(yyval.tac) = declare_para((yyvsp[0].string));
}
#line 1752 "mini.y.c"
    break;

  case 50: /* parameter_list: CHAR IDENTIFIER  */
#line 290 "mini.y"
{
	(yyval.tac) = declare_para((yyvsp[0].string));
}
#line 1760 "mini.y.c"
    break;

  case 51: /* parameter_list: parameter_list ',' INT IDENTIFIER  */
#line 294 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-3].tac),declare_para((yyvsp[0].string)));
}
#line 1768 "mini.y.c"
    break;

  case 52: /* parameter_list: parameter_list ',' CHAR IDENTIFIER  */
#line 298 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-3].tac),declare_para((yyvsp[0].string)));
}
#line 1776 "mini.y.c"
    break;

  case 53: /* parameter_list: %empty  */
#line 302 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1784 "mini.y.c"
    break;

  case 66: /* statement: error  */
#line 320 "mini.y"
{
	error("Bad statement syntax");
	(yyval.tac)=NULL;
}
#line 1793 "mini.y.c"
    break;

  case 67: /* block: '{' declaration_list statement_list '}'  */
#line 327 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[-1].tac));
}
#line 1801 "mini.y.c"
    break;

  case 68: /* declaration_list: %empty  */
#line 333 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1809 "mini.y.c"
    break;

  case 69: /* declaration_list: declaration_list declaration  */
#line 337 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1817 "mini.y.c"
    break;

  case 71: /* statement_list: statement_list statement  */
#line 344 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1825 "mini.y.c"
    break;

  case 72: /* lvalue_path: IDENTIFIER '.' IDENTIFIER lvalue_tail_opt  */
#line 350 "mini.y"
{
    PATH *p = append_path_member(NULL, (yyvsp[-1].string));
    p = append_path_list(p, (yyvsp[0].lvalue_path));
    (yyval.lvalue_path) = mk_lvalue_path((yyvsp[-3].string), p);
}
#line 1835 "mini.y.c"
    break;

  case 73: /* lvalue_path: IDENTIFIER dims_idx '.' IDENTIFIER lvalue_tail_opt  */
#line 356 "mini.y"
{
    PATH *p = append_path_index(NULL, (yyvsp[-3].exp)); 
    p = append_path_list(p, append_path_member(NULL, (yyvsp[-1].string)));
    p = append_path_list(p, (yyvsp[0].lvalue_path));

    (yyval.lvalue_path) = mk_lvalue_path((yyvsp[-4].string), p);
}
#line 1847 "mini.y.c"
    break;

  case 74: /* lvalue_tail_opt: %empty  */
#line 366 "mini.y"
    { (yyval.lvalue_path) = NULL; }
#line 1853 "mini.y.c"
    break;

  case 75: /* lvalue_tail_opt: lvalue_tail  */
#line 367 "mini.y"
                      { (yyval.lvalue_path) = (yyvsp[0].lvalue_path);   }
#line 1859 "mini.y.c"
    break;

  case 76: /* lvalue_tail: '.' IDENTIFIER  */
#line 372 "mini.y"
{
    (yyval.lvalue_path) = append_path_member(NULL, (yyvsp[0].string));
}
#line 1867 "mini.y.c"
    break;

  case 77: /* lvalue_tail: dims_idx  */
#line 376 "mini.y"
{
    (yyval.lvalue_path) = append_path_index(NULL, (yyvsp[0].exp));
}
#line 1875 "mini.y.c"
    break;

  case 78: /* lvalue_tail: lvalue_tail '.' IDENTIFIER  */
#line 380 "mini.y"
{
    (yyval.lvalue_path) = append_path_member((yyvsp[-2].lvalue_path), (yyvsp[0].string));
}
#line 1883 "mini.y.c"
    break;

  case 79: /* lvalue_tail: lvalue_tail dims_idx  */
#line 384 "mini.y"
{
    (yyval.lvalue_path) = append_path_index((yyvsp[-1].lvalue_path), (yyvsp[0].exp));
}
#line 1891 "mini.y.c"
    break;

  case 80: /* assignment_statement: IDENTIFIER '=' expression  */
#line 390 "mini.y"
{
	(yyval.tac)=do_assign(get_var((yyvsp[-2].string)), (yyvsp[0].exp));
}
#line 1899 "mini.y.c"
    break;

  case 81: /* assignment_statement: IDENTIFIER dims_idx '=' expression  */
#line 394 "mini.y"
{
	(yyval.tac) = do_array_store(get_var((yyvsp[-3].string)),(yyvsp[-2].exp),(yyvsp[0].exp));
}
#line 1907 "mini.y.c"
    break;

  case 82: /* assignment_statement: '*' IDENTIFIER '=' expression  */
#line 398 "mini.y"
{
	SYM *ptr = get_var((yyvsp[-2].string));
	TAC *store = mk_tac(TAC_STORE, ptr, (yyvsp[0].exp)->ret, NULL);
	store->prev = (yyvsp[0].exp)->tac;
	(yyval.tac) = store;
}
#line 1918 "mini.y.c"
    break;

  case 83: /* assignment_statement: IDENTIFIER '=' '&' IDENTIFIER  */
#line 405 "mini.y"
{
    SYM *dst = get_var((yyvsp[-3].string));
    SYM *src = get_var((yyvsp[0].string));
    TAC *addr = mk_tac(TAC_ADDR, dst, src, NULL);
    (yyval.tac) = addr;
}
#line 1929 "mini.y.c"
    break;

  case 84: /* assignment_statement: IDENTIFIER '=' '*' IDENTIFIER  */
#line 412 "mini.y"
{
    SYM *dst = get_var((yyvsp[-3].string));
    SYM *src = get_var((yyvsp[0].string));
    TAC *load = mk_tac(TAC_LOAD, dst, src, NULL);
    (yyval.tac) = load;
}
#line 1940 "mini.y.c"
    break;

  case 85: /* assignment_statement: lvalue_path '=' expression  */
#line 425 "mini.y"
{
	(yyval.tac) = do_lvalue_store((yyvsp[-2].lvalue_path),(yyvsp[0].exp));
}
#line 1948 "mini.y.c"
    break;

  case 86: /* expression: IDENTIFIER  */
#line 432 "mini.y"
{
	// printf("identifier %s\n",$1);
	(yyval.exp) = mk_exp(NULL, get_var((yyvsp[0].string)), NULL);
}
#line 1957 "mini.y.c"
    break;

  case 87: /* expression: expression '+' expression  */
#line 437 "mini.y"
{
	(yyval.exp)=do_bin(TAC_ADD, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1965 "mini.y.c"
    break;

  case 88: /* expression: expression '-' expression  */
#line 441 "mini.y"
{
	(yyval.exp)=do_bin(TAC_SUB, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1973 "mini.y.c"
    break;

  case 89: /* expression: expression '*' expression  */
#line 445 "mini.y"
{
	(yyval.exp)=do_bin(TAC_MUL, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1981 "mini.y.c"
    break;

  case 90: /* expression: expression '/' expression  */
#line 449 "mini.y"
{
	(yyval.exp)=do_bin(TAC_DIV, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1989 "mini.y.c"
    break;

  case 91: /* expression: '-' expression  */
#line 453 "mini.y"
{
	(yyval.exp)=do_un(TAC_NEG, (yyvsp[0].exp));
}
#line 1997 "mini.y.c"
    break;

  case 92: /* expression: expression EQ expression  */
#line 457 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_EQ, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 2005 "mini.y.c"
    break;

  case 93: /* expression: expression NE expression  */
#line 461 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_NE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 2013 "mini.y.c"
    break;

  case 94: /* expression: expression LT expression  */
#line 465 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 2021 "mini.y.c"
    break;

  case 95: /* expression: expression LE expression  */
#line 469 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 2029 "mini.y.c"
    break;

  case 96: /* expression: expression GT expression  */
#line 473 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 2037 "mini.y.c"
    break;

  case 97: /* expression: expression GE expression  */
#line 477 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 2045 "mini.y.c"
    break;

  case 98: /* expression: '(' expression ')'  */
#line 481 "mini.y"
{
	(yyval.exp)=(yyvsp[-1].exp);
}
#line 2053 "mini.y.c"
    break;

  case 99: /* expression: INTEGER  */
#line 485 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_const(atoi((yyvsp[0].string))), NULL);
}
#line 2061 "mini.y.c"
    break;

  case 100: /* expression: lvalue_path  */
#line 489 "mini.y"
{
	(yyval.exp) = do_lvalue_load((yyvsp[0].lvalue_path));
}
#line 2069 "mini.y.c"
    break;

  case 101: /* expression: CHAR_CONST  */
#line 493 "mini.y"
{
	(yyval.exp)=mk_exp(NULL,mk_char((yyvsp[0].string)[1]),NULL);
}
#line 2077 "mini.y.c"
    break;

  case 102: /* expression: IDENTIFIER dims_idx  */
#line 497 "mini.y"
{
	(yyval.exp) = do_array_load(get_var((yyvsp[-1].string)),(yyvsp[0].exp));  // 加载数组值
}
#line 2085 "mini.y.c"
    break;

  case 103: /* expression: call_expression  */
#line 501 "mini.y"
{
	(yyval.exp)=(yyvsp[0].exp);
}
#line 2093 "mini.y.c"
    break;

  case 104: /* expression: '&' IDENTIFIER  */
#line 505 "mini.y"
{
	SYM*tmp = mk_tmp();
	TAC*decl = mk_tac(TAC_VAR,tmp,NULL,NULL);
	TAC*addr = mk_tac(TAC_ADDR,tmp,get_var((yyvsp[0].string)),NULL);
	addr->prev = decl;
	(yyval.exp) = mk_exp(NULL,tmp,addr);
}
#line 2105 "mini.y.c"
    break;

  case 105: /* expression: '&' lvalue_path  */
#line 513 "mini.y"
{
	(yyval.exp) = do_lvalue_addr((yyvsp[0].lvalue_path));
}
#line 2113 "mini.y.c"
    break;

  case 106: /* expression: error  */
#line 523 "mini.y"
{
	error("Bad expression syntax");
	(yyval.exp)=mk_exp(NULL, NULL, NULL);
}
#line 2122 "mini.y.c"
    break;

  case 107: /* argument_list: %empty  */
#line 530 "mini.y"
{
	(yyval.exp)=NULL;
}
#line 2130 "mini.y.c"
    break;

  case 110: /* expression_list: expression_list ',' expression  */
#line 538 "mini.y"
{
	(yyvsp[0].exp)->next=(yyvsp[-2].exp);
	(yyval.exp)=(yyvsp[0].exp);
}
#line 2139 "mini.y.c"
    break;

  case 111: /* input_statement: INPUT IDENTIFIER  */
#line 545 "mini.y"
{
	(yyval.tac)=do_input(get_var((yyvsp[0].string)));
}
#line 2147 "mini.y.c"
    break;

  case 112: /* output_statement: OUTPUT IDENTIFIER  */
#line 551 "mini.y"
{
	(yyval.tac)=do_output(get_var((yyvsp[0].string)));
}
#line 2155 "mini.y.c"
    break;

  case 113: /* output_statement: OUTPUT TEXT  */
#line 555 "mini.y"
{
	(yyval.tac)=do_output(mk_text((yyvsp[0].string)));
}
#line 2163 "mini.y.c"
    break;

  case 114: /* output_statement: OUTPUT expression  */
#line 559 "mini.y"
{
	TAC*t = mk_tac(TAC_OUTPUT,(yyvsp[0].exp)->ret,NULL,NULL);
	t->prev = (yyvsp[0].exp)->tac;
	(yyval.tac) = t;
}
#line 2173 "mini.y.c"
    break;

  case 115: /* return_statement: RETURN expression  */
#line 567 "mini.y"
{
	TAC *t=mk_tac(TAC_RETURN, (yyvsp[0].exp)->ret, NULL, NULL);
	t->prev=(yyvsp[0].exp)->tac;
	(yyval.tac)=t;
}
#line 2183 "mini.y.c"
    break;

  case 116: /* if_statement: IF '(' expression ')' block  */
#line 575 "mini.y"
{
	(yyval.tac)=do_if((yyvsp[-2].exp), (yyvsp[0].tac));
}
#line 2191 "mini.y.c"
    break;

  case 117: /* if_statement: IF '(' expression ')' block ELSE block  */
#line 579 "mini.y"
{
	(yyval.tac)=do_test((yyvsp[-4].exp), (yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 2199 "mini.y.c"
    break;

  case 118: /* $@3: %empty  */
#line 586 "mini.y"
    {
      g_switch_end = mk_label(mk_lstr(next_label++));
      push_loop_labels(NULL, g_switch_end);  // 同for, 只有end
    }
#line 2208 "mini.y.c"
    break;

  case 119: /* switch_statement: SWITCH '(' expression ')' $@3 '{' case_list default_list '}'  */
#line 591 "mini.y"
    {
      (yyval.tac) = do_switch((yyvsp[-6].exp), (yyvsp[-2].tac), (yyvsp[-1].tac), g_switch_end);
      pop_loop_labels();
      g_switch_end = NULL;
    }
#line 2218 "mini.y.c"
    break;

  case 120: /* case_list: case_item  */
#line 599 "mini.y"
           { (yyval.tac) = (yyvsp[0].tac); }
#line 2224 "mini.y.c"
    break;

  case 121: /* case_list: case_list case_item  */
#line 601 "mini.y"
{
	(yyval.tac) = join_tac((yyvsp[-1].tac),(yyvsp[0].tac));
}
#line 2232 "mini.y.c"
    break;

  case 122: /* case_item: CASE INTEGER ':' statement_list  */
#line 607 "mini.y"
{
	(yyval.tac) = do_case(atoi((yyvsp[-2].string)),(yyvsp[0].tac));
}
#line 2240 "mini.y.c"
    break;

  case 123: /* default_list: %empty  */
#line 613 "mini.y"
{
	 (yyval.tac) = NULL; 
}
#line 2248 "mini.y.c"
    break;

  case 124: /* default_list: DEFAULT ':' statement_list  */
#line 617 "mini.y"
{ 
	(yyval.tac) = (yyvsp[0].tac); 
}
#line 2256 "mini.y.c"
    break;

  case 125: /* $@4: %empty  */
#line 622 "mini.y"
{
    g_for_start_stack[g_for_depth] = mk_label(mk_lstr(next_label++));
    g_for_cont_stack[g_for_depth]  = mk_label(mk_lstr(next_label++));
    g_for_end_stack[g_for_depth]   = mk_label(mk_lstr(next_label++));

    g_for_start = g_for_start_stack[g_for_depth];
    g_for_cont  = g_for_cont_stack[g_for_depth];
    g_for_end   = g_for_end_stack[g_for_depth];

    g_for_depth++;

    push_loop_labels(g_for_cont, g_for_end);
}
#line 2274 "mini.y.c"
    break;

  case 126: /* while_statement: WHILE '(' expression ')' $@4 block  */
#line 636 "mini.y"
{
    SYM *start = g_for_start_stack[g_for_depth - 1];
    SYM *cont  = g_for_cont_stack[g_for_depth - 1];
    SYM *end   = g_for_end_stack[g_for_depth - 1];

    if (start != NULL)
        printf("g_for_start\n");
    else
        printf("start null\n");

    (yyval.tac) = do_while((yyvsp[-3].exp), (yyvsp[0].tac), start, cont, end);

    g_for_depth--;

    if (g_for_depth > 0) {
        g_for_start = g_for_start_stack[g_for_depth - 1];
        g_for_cont  = g_for_cont_stack[g_for_depth - 1];
        g_for_end   = g_for_end_stack[g_for_depth - 1];
    } else {
        g_for_start = g_for_cont = g_for_end = NULL;
    }

    pop_loop_labels();
}
#line 2303 "mini.y.c"
    break;

  case 127: /* $@5: %empty  */
#line 665 "mini.y"
    {
      g_for_start = mk_label(mk_lstr(next_label++));
      g_for_cont  = mk_label(mk_lstr(next_label++));
      g_for_end   = mk_label(mk_lstr(next_label++));
      push_loop_labels(g_for_cont, g_for_end);
    }
#line 2314 "mini.y.c"
    break;

  case 128: /* for_statement: FOR '(' opt_statement ';' opt_expression ';' opt_statement ')' $@5 block  */
#line 672 "mini.y"
    {
      (yyval.tac) = do_for((yyvsp[-7].tac), (yyvsp[-5].exp), (yyvsp[-3].tac), (yyvsp[0].tac), g_for_start, g_for_cont, g_for_end);
      pop_loop_labels();
      g_for_start = g_for_cont = g_for_end = NULL;
    }
#line 2324 "mini.y.c"
    break;

  case 129: /* opt_statement: assignment_statement  */
#line 682 "mini.y"
{
	(yyval.tac) = (yyvsp[0].tac);
}
#line 2332 "mini.y.c"
    break;

  case 130: /* opt_statement: %empty  */
#line 686 "mini.y"
{
	(yyval.tac) = NULL;
}
#line 2340 "mini.y.c"
    break;

  case 131: /* opt_expression: expression  */
#line 692 "mini.y"
{
	(yyval.exp) = (yyvsp[0].exp);
}
#line 2348 "mini.y.c"
    break;

  case 132: /* opt_expression: %empty  */
#line 696 "mini.y"
{
	(yyval.exp) = NULL;
}
#line 2356 "mini.y.c"
    break;

  case 133: /* break_statement: BREAK  */
#line 702 "mini.y"
{
	(yyval.tac)=do_break();
}
#line 2364 "mini.y.c"
    break;

  case 134: /* continue_statement: CONTINUE  */
#line 708 "mini.y"
{
	(yyval.tac)=do_continue();
}
#line 2372 "mini.y.c"
    break;

  case 135: /* call_statement: IDENTIFIER '(' argument_list ')'  */
#line 714 "mini.y"
{
	(yyval.tac)=do_call((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 2380 "mini.y.c"
    break;

  case 136: /* call_expression: IDENTIFIER '(' argument_list ')'  */
#line 720 "mini.y"
{
	(yyval.exp)=do_call_ret((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 2388 "mini.y.c"
    break;


#line 2392 "mini.y.c"

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

#line 725 "mini.y"


PATH *append_path_list(PATH *head, PATH *tail)
{
    if (!head) return tail;
    PATH *p = head;
    while (p->next) {
		p = p->next;
	}
    p->next = tail;
    return head;
}


void yyerror(char* msg) 
{
	fprintf(stderr, "%s: line %d\n", msg, yylineno);
	exit(0);
}
