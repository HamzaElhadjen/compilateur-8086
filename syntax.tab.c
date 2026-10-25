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
#line 1 "syntax.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

    /* Declarations forward pour les fonctions de TS.h */
    char* idf_type(char entite[]);
    char* newTemp();
    void quadr(char opr[], char op1[], char op2[], char res[]);
    void updateQuad(int num_quad, int colon_quad, char val[]);

    /* Variables globales definies dans TS.h (qc) */
    extern int qc;

    int yylex();
    extern int yylineno; 
    extern int yycolumn;
    void yyerror(char* s);
    char current_type[20];

#line 92 "syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_kw_begin_project = 3,           /* kw_begin_project  */
  YYSYMBOL_kw_end_project = 4,             /* kw_end_project  */
  YYSYMBOL_kw_setup = 5,                   /* kw_setup  */
  YYSYMBOL_kw_run = 6,                     /* kw_run  */
  YYSYMBOL_kw_define = 7,                  /* kw_define  */
  YYSYMBOL_kw_const = 8,                   /* kw_const  */
  YYSYMBOL_kw_if = 9,                      /* kw_if  */
  YYSYMBOL_kw_then = 10,                   /* kw_then  */
  YYSYMBOL_kw_else = 11,                   /* kw_else  */
  YYSYMBOL_kw_end_if = 12,                 /* kw_end_if  */
  YYSYMBOL_kw_loop_while = 13,             /* kw_loop_while  */
  YYSYMBOL_kw_end_loop = 14,               /* kw_end_loop  */
  YYSYMBOL_kw_for = 15,                    /* kw_for  */
  YYSYMBOL_kw_in = 16,                     /* kw_in  */
  YYSYMBOL_kw_to = 17,                     /* kw_to  */
  YYSYMBOL_kw_end_for = 18,                /* kw_end_for  */
  YYSYMBOL_kw_out = 19,                    /* kw_out  */
  YYSYMBOL_kw_input = 20,                  /* kw_input  */
  YYSYMBOL_kw_and = 21,                    /* kw_and  */
  YYSYMBOL_kw_or = 22,                     /* kw_or  */
  YYSYMBOL_kw_not = 23,                    /* kw_not  */
  YYSYMBOL_assign_arrow = 24,              /* assign_arrow  */
  YYSYMBOL_plus = 25,                      /* plus  */
  YYSYMBOL_minus = 26,                     /* minus  */
  YYSYMBOL_multiply = 27,                  /* multiply  */
  YYSYMBOL_divide = 28,                    /* divide  */
  YYSYMBOL_less_equal = 29,                /* less_equal  */
  YYSYMBOL_greater_equal = 30,             /* greater_equal  */
  YYSYMBOL_less_than = 31,                 /* less_than  */
  YYSYMBOL_greater_than = 32,              /* greater_than  */
  YYSYMBOL_equal_equal = 33,               /* equal_equal  */
  YYSYMBOL_not_equal = 34,                 /* not_equal  */
  YYSYMBOL_equal = 35,                     /* equal  */
  YYSYMBOL_semicolon = 36,                 /* semicolon  */
  YYSYMBOL_colon = 37,                     /* colon  */
  YYSYMBOL_comma = 38,                     /* comma  */
  YYSYMBOL_pipe = 39,                      /* pipe  */
  YYSYMBOL_lbrace = 40,                    /* lbrace  */
  YYSYMBOL_rbrace = 41,                    /* rbrace  */
  YYSYMBOL_lbracket = 42,                  /* lbracket  */
  YYSYMBOL_rbracket = 43,                  /* rbracket  */
  YYSYMBOL_lparen = 44,                    /* lparen  */
  YYSYMBOL_rparen = 45,                    /* rparen  */
  YYSYMBOL_identifier = 46,                /* identifier  */
  YYSYMBOL_kw_integer = 47,                /* kw_integer  */
  YYSYMBOL_kw_float = 48,                  /* kw_float  */
  YYSYMBOL_string_literal = 49,            /* string_literal  */
  YYSYMBOL_int_literal = 50,               /* int_literal  */
  YYSYMBOL_float_literal = 51,             /* float_literal  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_PROGRAMME = 53,                 /* PROGRAMME  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_PARTIE_DEC = 55,                /* PARTIE_DEC  */
  YYSYMBOL_DECLARATION = 56,               /* DECLARATION  */
  YYSYMBOL_DEC_VAR = 57,                   /* DEC_VAR  */
  YYSYMBOL_DEC_CONST = 58,                 /* DEC_CONST  */
  YYSYMBOL_DEC_TAB = 59,                   /* DEC_TAB  */
  YYSYMBOL_LISTE_IDF = 60,                 /* LISTE_IDF  */
  YYSYMBOL_TYPE = 61,                      /* TYPE  */
  YYSYMBOL_VALEUR = 62,                    /* VALEUR  */
  YYSYMBOL_PARTIE_INSTR = 63,              /* PARTIE_INSTR  */
  YYSYMBOL_LISTE_INSTR = 64,               /* LISTE_INSTR  */
  YYSYMBOL_INSTRUCTION = 65,               /* INSTRUCTION  */
  YYSYMBOL_INST_AFF = 66,                  /* INST_AFF  */
  YYSYMBOL_M_QUAD = 67,                    /* M_QUAD  */
  YYSYMBOL_N_BR = 68,                      /* N_BR  */
  YYSYMBOL_M_LOOP = 69,                    /* M_LOOP  */
  YYSYMBOL_INST_COND = 70,                 /* INST_COND  */
  YYSYMBOL_INST_LOOP_WHILE = 71,           /* INST_LOOP_WHILE  */
  YYSYMBOL_INST_FOR = 72,                  /* INST_FOR  */
  YYSYMBOL_73_2 = 73,                      /* $@2  */
  YYSYMBOL_74_3 = 74,                      /* $@3  */
  YYSYMBOL_75_4 = 75,                      /* $@4  */
  YYSYMBOL_INST_INPUT = 76,                /* INST_INPUT  */
  YYSYMBOL_INST_OUT = 77,                  /* INST_OUT  */
  YYSYMBOL_LISTE_OUT = 78,                 /* LISTE_OUT  */
  YYSYMBOL_ELEM_OUT = 79,                  /* ELEM_OUT  */
  YYSYMBOL_EXPR = 80,                      /* EXPR  */
  YYSYMBOL_COND = 81                       /* COND  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   188

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    67,    79,    80,    84,    85,    86,    90,
      97,   107,   121,   135,   154,   159,   169,   170,   174,   178,
     187,   188,   192,   193,   197,   198,   199,   200,   201,   202,
     206,   219,   237,   242,   250,   255,   274,   286,   305,   318,
     325,   304,   357,   371,   375,   376,   380,   384,   395,   406,
     417,   428,   442,   450,   454,   466,   487,   493,   503,   509,
     515,   521,   527,   533,   539,   540,   541,   542
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
  "\"end of file\"", "error", "\"invalid token\"", "kw_begin_project",
  "kw_end_project", "kw_setup", "kw_run", "kw_define", "kw_const", "kw_if",
  "kw_then", "kw_else", "kw_end_if", "kw_loop_while", "kw_end_loop",
  "kw_for", "kw_in", "kw_to", "kw_end_for", "kw_out", "kw_input", "kw_and",
  "kw_or", "kw_not", "assign_arrow", "plus", "minus", "multiply", "divide",
  "less_equal", "greater_equal", "less_than", "greater_than",
  "equal_equal", "not_equal", "equal", "semicolon", "colon", "comma",
  "pipe", "lbrace", "rbrace", "lbracket", "rbracket", "lparen", "rparen",
  "identifier", "kw_integer", "kw_float", "string_literal", "int_literal",
  "float_literal", "$accept", "PROGRAMME", "$@1", "PARTIE_DEC",
  "DECLARATION", "DEC_VAR", "DEC_CONST", "DEC_TAB", "LISTE_IDF", "TYPE",
  "VALEUR", "PARTIE_INSTR", "LISTE_INSTR", "INSTRUCTION", "INST_AFF",
  "M_QUAD", "N_BR", "M_LOOP", "INST_COND", "INST_LOOP_WHILE", "INST_FOR",
  "$@2", "$@3", "$@4", "INST_INPUT", "INST_OUT", "LISTE_OUT", "ELEM_OUT",
  "EXPR", "COND", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-87)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,    -4,    28,     9,   -87,   -87,    44,    30,     7,    34,
      72,    91,     7,   -87,   -87,   -87,    59,    73,    82,    83,
     -87,    26,    77,    23,    23,    81,    23,   -87,   -87,    76,
      74,   -87,    86,    90,    -3,    88,    64,   -87,   -87,    64,
      84,   -87,    80,    85,    87,   -11,    92,    -3,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,    93,   -87,   -87,    94,    96,
     -21,    95,   111,   -25,    98,     0,    97,   130,   -87,    99,
     -87,   -87,   101,     0,   -21,   104,   -87,   -87,    75,   103,
     -21,   100,   -87,   -87,   -27,   -87,   106,     0,    51,   109,
     102,   105,   -21,    89,    27,   -18,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,   108,   -87,
     -25,   113,   118,    37,   -87,   112,   -87,   -87,   110,   -87,
     -21,   -21,   -87,   115,    89,    89,   -87,   -87,    67,    67,
      67,    67,    67,    67,   119,   -87,   120,   -87,   -87,   -87,
       0,   -87,   114,   116,   -87,   -87,   122,   117,    63,   -87,
     -87,   123,    -3,   -87,   -87,    -3,   124,   -87,   127,   126,
     -87,   148,   128,   129,   134,   155,   -87,    -3,   -87,   131,
     132,    -3,   154,   133,   139,   164,   -87,   141,   -87
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,     0,     0,     5,     0,
       0,     0,     5,     6,     7,     8,     0,     0,     0,     0,
       4,     0,     0,     0,     0,     0,     0,    16,    17,     0,
      15,    14,     0,     0,    21,     0,     0,     9,    10,     0,
       0,    34,     0,     0,     0,     0,     0,    20,    23,    24,
      25,    26,    27,    28,    29,     0,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,     0,
      11,    12,     0,     0,     0,    54,    56,    57,     0,     0,
       0,     0,    47,    46,     0,    44,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,    30,     0,     3,    13,     0,    53,
       0,     0,    67,     0,    48,    49,    50,    51,    60,    61,
      58,    59,    62,    63,     0,    32,     0,    45,    43,    42,
       0,    66,     0,     0,    55,    32,     0,     0,     0,    64,
      65,     0,    21,    39,    31,    21,     0,    34,     0,     0,
      40,    33,     0,     0,     0,     0,    37,    21,    36,     0,
       0,    21,     0,     0,     0,     0,    41,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   166,   -87,   -87,   -87,   -87,   157,    60,
     142,   -86,   -87,   135,   -87,    35,   -87,    29,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,    78,   -65,   -73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     6,    11,    12,    13,    14,    15,    17,    29,
      58,    46,    47,    48,    49,   146,   165,    61,    50,    51,
      52,   136,   157,   163,    53,    54,    84,    85,    78,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      88,    95,    72,   120,   121,    73,    40,   108,    93,    94,
      41,   110,    42,    65,     9,    10,    43,    44,   111,   118,
       1,    82,   113,    74,    83,    75,    73,   122,     4,    76,
      77,    66,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,     3,    45,    87,     5,    75,   142,   143,     7,
      76,    77,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    97,    98,    99,   100,   156,     8,    26,   158,
      27,    28,   119,    27,    28,   148,    97,    98,    99,   100,
      16,   170,   119,    32,    33,   173,    35,   114,    97,    98,
      99,   100,    97,    98,    99,   100,    21,    19,    22,   154,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      23,    36,    37,    22,    56,    57,    99,   100,    18,    24,
      25,    34,    38,    30,    55,    39,    62,    81,    60,    63,
      70,    64,    71,    67,    90,   134,   140,   147,   116,    80,
     162,   117,    91,    69,    86,    92,    96,    89,   107,   138,
     109,   112,   115,   135,   139,   141,   145,   123,   144,   149,
     164,   150,   152,   155,   166,   159,   169,   153,   161,   167,
     168,   171,   174,   172,   175,   176,   177,   178,    20,    31,
     151,    59,    68,     0,     0,     0,   160,     0,   137
};

static const yytype_int16 yycheck[] =
{
      65,    74,    23,    21,    22,    26,     9,    80,    73,    74,
      13,    38,    15,    24,     7,     8,    19,    20,    45,    92,
       3,    46,    87,    44,    49,    46,    26,    45,     0,    50,
      51,    42,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    46,    46,    44,    36,    46,   120,   121,     5,
      50,    51,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    25,    26,    27,    28,   152,    37,    42,   155,
      47,    48,    45,    47,    48,   140,    25,    26,    27,    28,
      46,   167,    45,    23,    24,   171,    26,    36,    25,    26,
      27,    28,    25,    26,    27,    28,    37,     6,    39,    36,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      37,    35,    36,    39,    50,    51,    27,    28,    46,    37,
      37,    40,    36,    46,    36,    35,    46,    16,    44,    44,
      36,    44,    36,    41,     4,    10,    24,    17,    36,    44,
      14,    36,    43,    50,    46,    44,    42,    50,    45,    36,
      50,    45,    43,    45,    36,    45,    37,    50,    43,    45,
      12,    45,    40,    40,    36,    41,    11,    50,    41,    40,
      36,    40,    18,    41,    41,    36,    12,    36,    12,    22,
     145,    39,    47,    -1,    -1,    -1,   157,    -1,   110
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    53,    46,     0,    36,    54,     5,    37,     7,
       8,    55,    56,    57,    58,    59,    46,    60,    46,     6,
      55,    37,    39,    37,    37,    37,    42,    47,    48,    61,
      46,    60,    61,    61,    40,    61,    35,    36,    36,    35,
       9,    13,    15,    19,    20,    46,    63,    64,    65,    66,
      70,    71,    72,    76,    77,    36,    50,    51,    62,    62,
      44,    69,    46,    44,    44,    24,    42,    41,    65,    50,
      36,    36,    23,    26,    44,    46,    50,    51,    80,    81,
      44,    16,    46,    49,    78,    79,    46,    44,    80,    50,
       4,    43,    44,    80,    80,    81,    42,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    45,    81,    50,
      38,    45,    45,    80,    36,    43,    36,    36,    81,    45,
      21,    22,    45,    50,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    10,    45,    73,    79,    36,    36,
      24,    45,    81,    81,    43,    37,    67,    17,    80,    45,
      45,    67,    40,    50,    36,    40,    63,    74,    63,    41,
      69,    41,    14,    75,    12,    68,    36,    40,    36,    11,
      63,    40,    41,    63,    18,    41,    36,    12,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    54,    53,    55,    55,    56,    56,    56,    57,
      57,    57,    58,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    65,    65,    65,    65,    65,    65,
      66,    66,    67,    68,    69,    70,    70,    71,    73,    74,
      75,    72,    76,    77,    78,    78,    79,    79,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,    14,     2,     0,     1,     1,     1,     5,
       5,     7,     7,     9,     3,     1,     1,     1,     1,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     7,     0,     0,     0,    17,    12,    11,     0,     0,
       0,    15,     5,     5,     1,     3,     1,     1,     3,     3,
       3,     3,     2,     3,     1,     4,     1,     1,     3,     3,
       3,     3,     3,     3,     5,     5,     4,     3
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
  case 2: /* $@1: %empty  */
#line 68 "syntax.y"
        { updateCode((yyvsp[-1].str), "Programme"); }
#line 1273 "syntax.tab.c"
    break;

  case 3: /* PROGRAMME: kw_begin_project identifier semicolon $@1 kw_setup colon PARTIE_DEC kw_run colon lbrace PARTIE_INSTR rbrace kw_end_project semicolon  */
#line 72 "syntax.y"
      {
          printf("\n>>> Programme '%s' syntaxiquement correct.\n", (yyvsp[-12].str));
          YYACCEPT;
      }
#line 1282 "syntax.tab.c"
    break;

  case 9: /* DEC_VAR: kw_define identifier colon TYPE semicolon  */
#line 91 "syntax.y"
        {   
            if(updateType((yyvsp[-3].str), current_type) == -1)
                printf("Erreur Semantique, ligne %d, colonne %d : double declaration de '%s'\n", yylineno, yycolumn, (yyvsp[-3].str));
            else 
                updateCode((yyvsp[-3].str), "Variable");
        }
#line 1293 "syntax.tab.c"
    break;

  case 10: /* DEC_VAR: kw_define LISTE_IDF colon TYPE semicolon  */
#line 98 "syntax.y"
        {   
            int i; 
            for(i = 0; i < (yyvsp[-3].idlist).count; i++) {
                if(updateType((yyvsp[-3].idlist).ids[i], current_type) == -1)
                    printf("Erreur Semantique, ligne %d, colonne %d : double declaration de '%s'\n", yylineno, yycolumn, (yyvsp[-3].idlist).ids[i]);
                else
                    updateCode((yyvsp[-3].idlist).ids[i], "Variable");
            }
        }
#line 1307 "syntax.tab.c"
    break;

  case 11: /* DEC_VAR: kw_define identifier colon TYPE equal VALEUR semicolon  */
#line 108 "syntax.y"
        {   
            if(updateType((yyvsp[-5].str), current_type) == -1)
                printf("Erreur Semantique, ligne %d, colonne %d : double declaration de '%s'\n", yylineno, yycolumn, (yyvsp[-5].str));
            else if(checkTypeMismatch(current_type, (yyvsp[-1].val).type))
                printf("Erreur Semantique, ligne %d, colonne %d : incompatibilite de type pour '%s'\n", yylineno, yycolumn, (yyvsp[-5].str));
            else {
                updateCode((yyvsp[-5].str), "Variable");
                updateVal((yyvsp[-5].str), (yyvsp[-1].val).value);
            }
        }
#line 1322 "syntax.tab.c"
    break;

  case 12: /* DEC_CONST: kw_const identifier colon TYPE equal VALEUR semicolon  */
#line 122 "syntax.y"
        {
            if(updateType((yyvsp[-5].str), current_type) == -1)
                printf("Erreur Semantique, ligne %d, colonne %d : double declaration de '%s'\n", yylineno, yycolumn, (yyvsp[-5].str));
            else if(checkTypeMismatch(current_type, (yyvsp[-1].val).type))
                printf("Erreur Semantique, ligne %d, colonne %d : incompatibilite de type pour '%s'\n", yylineno, yycolumn, (yyvsp[-5].str));
            else { 
                updateCode((yyvsp[-5].str), "Constante");
                updateVal((yyvsp[-5].str), (yyvsp[-1].val).value); 
            }
        }
#line 1337 "syntax.tab.c"
    break;

  case 13: /* DEC_TAB: kw_define identifier colon lbracket TYPE semicolon int_literal rbracket semicolon  */
#line 136 "syntax.y"
        {
            if(updateType((yyvsp[-7].str), current_type) == -1) 
                printf("Erreur Semantique, ligne %d, colonne %d : double declaration de '%s'\n", yylineno, yycolumn, (yyvsp[-7].str));
            else if ((yyvsp[-2].entier) <= 0)
                printf("Erreur Semantique, ligne %d, colonne %d : taille du tableau '%s' doit etre > 0\n",
                       yylineno, yycolumn, (yyvsp[-7].str));
            else {
                char tailleStr[20];
                sprintf(tailleStr, "%d", (yyvsp[-2].entier));
                updateCode((yyvsp[-7].str), "Tableau");
                updateType((yyvsp[-7].str), current_type);
                updateVal((yyvsp[-7].str), tailleStr);
            }
        }
#line 1356 "syntax.tab.c"
    break;

  case 14: /* LISTE_IDF: identifier pipe LISTE_IDF  */
#line 155 "syntax.y"
        {
            (yyval.idlist) = (yyvsp[0].idlist);  
            (yyval.idlist).ids[(yyval.idlist).count++] = strdup((yyvsp[-2].str));
        }
#line 1365 "syntax.tab.c"
    break;

  case 15: /* LISTE_IDF: identifier  */
#line 160 "syntax.y"
        {
            (yyval.idlist).count = 1;
            (yyval.idlist).ids[0] = strdup((yyvsp[0].str));
        }
#line 1374 "syntax.tab.c"
    break;

  case 16: /* TYPE: kw_integer  */
#line 169 "syntax.y"
                 {strcpy(current_type,"integer");}
#line 1380 "syntax.tab.c"
    break;

  case 17: /* TYPE: kw_float  */
#line 170 "syntax.y"
                 {strcpy(current_type,"float");}
#line 1386 "syntax.tab.c"
    break;

  case 18: /* VALEUR: int_literal  */
#line 174 "syntax.y"
                  {
        sprintf((yyval.val).value, "%d", (yyvsp[0].entier));
        strcpy((yyval.val).type, "integer");
    }
#line 1395 "syntax.tab.c"
    break;

  case 19: /* VALEUR: float_literal  */
#line 178 "syntax.y"
                    {
        sprintf((yyval.val).value, "%f", (yyvsp[0].numvrg));
        strcpy((yyval.val).type, "float");
    }
#line 1404 "syntax.tab.c"
    break;

  case 30: /* INST_AFF: identifier assign_arrow EXPR semicolon  */
#line 207 "syntax.y"
        {   
            if(checkUndeclared((yyvsp[-3].str)) == -1) 
                printf("Erreur Semantique, ligne %d, colonne %d : variable non declaree '%s'\n", yylineno, yycolumn, (yyvsp[-3].str));
            else if (isConstante((yyvsp[-3].str))) 
                printf("Erreur Semantique, ligne %d, colonne %d : modification d'une constante '%s'\n", yylineno, yycolumn, (yyvsp[-3].str)); 
            else if (checkTypeMismatch(idf_type((yyvsp[-3].str)), (yyvsp[-1].val).type)) 
                printf("Erreur Semantique, ligne %d, colonne %d : incompatibilite de type dans l'affectation de '%s'\n",
                       yylineno, yycolumn, (yyvsp[-3].str));
            else {
                quadr("=", (yyvsp[-1].val).result, "", (yyvsp[-3].str));
            }
        }
#line 1421 "syntax.tab.c"
    break;

  case 31: /* INST_AFF: identifier lbracket int_literal rbracket assign_arrow EXPR semicolon  */
#line 220 "syntax.y"
        { 
            if(checkUndeclared((yyvsp[-6].str)) == -1) 
                printf("Erreur Semantique, ligne %d, colonne %d : variable non declaree '%s'\n", yylineno, yycolumn, (yyvsp[-6].str));
            else if(checkTableIndex((yyvsp[-6].str), (yyvsp[-4].entier)) == -1) 
                printf("Erreur Semantique, ligne %d, colonne %d : index %d hors limites pour '%s'\n", yylineno, yycolumn, (yyvsp[-4].entier), (yyvsp[-6].str));
            else {
                char target[40];
                sprintf(target, "%s[%d]", (yyvsp[-6].str), (yyvsp[-4].entier));
                quadr("=", (yyvsp[-1].val).result, "", target);
            }
        }
#line 1437 "syntax.tab.c"
    break;

  case 32: /* M_QUAD: %empty  */
#line 237 "syntax.y"
        { (yyval.num) = qc; }
#line 1443 "syntax.tab.c"
    break;

  case 33: /* N_BR: %empty  */
#line 242 "syntax.y"
        { 
            quadr("BR", "", "", "?");
            (yyval.num) = qc;     /* $$ = position juste apres le BR = debut du else */
        }
#line 1452 "syntax.tab.c"
    break;

  case 34: /* M_LOOP: %empty  */
#line 250 "syntax.y"
        { (yyval.num) = qc; }
#line 1458 "syntax.tab.c"
    break;

  case 35: /* INST_COND: kw_if lparen COND rparen kw_then colon M_QUAD lbrace PARTIE_INSTR rbrace N_BR kw_else lbrace PARTIE_INSTR rbrace kw_end_if semicolon  */
#line 259 "syntax.y"
        {
            /* $7  = M_QUAD  = position juste apres BZ (debut du then)
               $11 = N_BR    = position juste apres BR (debut du else)
               qc courant    = fin du else

               BZ se trouve a la position $7 - 1. Il doit sauter au debut du else = $11.
               BR se trouve a la position $11 - 1. Il doit sauter a la fin du if = qc.
            */
            char tmp[20];
            sprintf(tmp, "%d", (yyvsp[-6].num));
            updateQuad((yyvsp[-10].num) - 1, 4, tmp);    
            
            sprintf(tmp, "%d", qc);
            updateQuad((yyvsp[-6].num) - 1, 4, tmp);    
        }
#line 1478 "syntax.tab.c"
    break;

  case 36: /* INST_COND: kw_if lparen COND rparen kw_then colon M_QUAD lbrace PARTIE_INSTR rbrace kw_end_if semicolon  */
#line 276 "syntax.y"
        {
            /* Pas de else : patcher BZ avec qc (fin du if) */
            char tmp[20];
            sprintf(tmp, "%d", qc);
            updateQuad((yyvsp[-5].num) - 1, 4, tmp);
        }
#line 1489 "syntax.tab.c"
    break;

  case 37: /* INST_LOOP_WHILE: kw_loop_while M_LOOP lparen COND rparen M_QUAD lbrace PARTIE_INSTR rbrace kw_end_loop semicolon  */
#line 289 "syntax.y"
        {
            
            char tmp[20];
            
            /* Generer le BR de retour au debut de la boucle */
            sprintf(tmp, "%d", (yyvsp[-9].num));
            quadr("BR", "", "", tmp);
            
            /* Patcher le BZ pour sortir de la boucle */
            sprintf(tmp, "%d", qc);
            updateQuad((yyvsp[-5].num) - 1, 4, tmp);
        }
#line 1506 "syntax.tab.c"
    break;

  case 38: /* $@2: %empty  */
#line 305 "syntax.y"
        {
            /* ACTION 1 : verifier idf + generer i <- val_init */
            if (checkUndeclared((yyvsp[-2].str)) == -1) {
                printf("Erreur Semantique, ligne %d, colonne %d : variable de boucle non declaree '%s'\n",
                       yylineno, yycolumn, (yyvsp[-2].str));
                updateType((yyvsp[-2].str), "integer");   /* evite cascade d'erreurs */
            }
            
            char valStr[20];
            sprintf(valStr, "%d", (yyvsp[0].entier));
            quadr("=", valStr, "", (yyvsp[-2].str));
        }
#line 1523 "syntax.tab.c"
    break;

  case 39: /* $@3: %empty  */
#line 318 "syntax.y"
        {
            /* ACTION 2 : verifier bornes */
            if ((yyvsp[-3].entier) > (yyvsp[0].entier))
                printf("Erreur Semantique, ligne %d, colonne %d : borne initiale (%d) superieure a la borne finale (%d) dans le for '%s'\n",
                       yylineno, yycolumn, (yyvsp[-3].entier), (yyvsp[0].entier), (yyvsp[-5].str));
        }
#line 1534 "syntax.tab.c"
    break;

  case 40: /* $@4: %empty  */
#line 325 "syntax.y"
        {
            /* ACTION 3 : generer le test i <= val_limit et le BZ */
            char limStr[20];
            char* t = newTemp();
            sprintf(limStr, "%d", (yyvsp[-2].entier));
            quadr("<=", (yyvsp[-7].str), limStr, t);
            quadr("BZ", t, "", "?");
        }
#line 1547 "syntax.tab.c"
    break;

  case 41: /* INST_FOR: kw_for identifier kw_in int_literal $@2 kw_to int_literal $@3 M_LOOP $@4 lbrace PARTIE_INSTR rbrace kw_end_for semicolon  */
#line 334 "syntax.y"
        {
            /* ACTION FINALE : generer l'increment i <- i + 1, BR de retour, et patcher le BZ */
            char tmp[20];
            char* t2 = newTemp();
            
            /* i <- i + 1 */
            quadr("+", (yyvsp[-13].str), "1", t2);
            quadr("=", t2, "", (yyvsp[-13].str));
            
            /* BR retour a M_LOOP ($9) */
            sprintf(tmp, "%d", (yyvsp[-6].num));
            quadr("BR", "", "", tmp);
            
            /* Patcher BZ (situe juste apres le test = qc au moment de l'action 3)
               Le BZ est a la position ($9 + 2) - 1 = $9 + 1 
               Car l'action 3 genere 2 quadruplets apres $9 : le test et le BZ
            */
            sprintf(tmp, "%d", qc);
            updateQuad((yyvsp[-6].num) + 1, 4, tmp);
        }
#line 1572 "syntax.tab.c"
    break;

  case 42: /* INST_INPUT: kw_input lparen identifier rparen semicolon  */
#line 358 "syntax.y"
        { 
            if (checkUndeclared((yyvsp[-2].str)) == -1)
                printf("Erreur Semantique, ligne %d, colonne %d : variable non declaree '%s'\n", yylineno, yycolumn, (yyvsp[-2].str));
            else if (isConstante((yyvsp[-2].str)))
                printf("Erreur Semantique, ligne %d, colonne %d : saisie dans une constante '%s'\n",
                       yylineno, yycolumn, (yyvsp[-2].str));
            else {
                quadr("READ", "", "", (yyvsp[-2].str));
            }
        }
#line 1587 "syntax.tab.c"
    break;

  case 46: /* ELEM_OUT: string_literal  */
#line 381 "syntax.y"
        {
            quadr("WRITE", (yyvsp[0].str), "", "");
        }
#line 1595 "syntax.tab.c"
    break;

  case 47: /* ELEM_OUT: identifier  */
#line 385 "syntax.y"
        {
            if (checkUndeclared((yyvsp[0].str)) == -1)
                printf("Erreur Semantique, ligne %d, colonne %d : variable non declaree '%s'\n", yylineno, yycolumn, (yyvsp[0].str));
            else
                quadr("WRITE", (yyvsp[0].str), "", "");
        }
#line 1606 "syntax.tab.c"
    break;

  case 48: /* EXPR: EXPR plus EXPR  */
#line 396 "syntax.y"
        {
            char* t = newTemp();
            if (strcmp((yyvsp[-2].val).type,"float")==0 || strcmp((yyvsp[0].val).type,"float")==0)
                strcpy((yyval.val).type, "float");
            else
                strcpy((yyval.val).type, "integer");
            strcpy((yyval.val).result, t);
            strcpy((yyval.val).value, "?");
            quadr("+", (yyvsp[-2].val).result, (yyvsp[0].val).result, t);
        }
#line 1621 "syntax.tab.c"
    break;

  case 49: /* EXPR: EXPR minus EXPR  */
#line 407 "syntax.y"
        {
            char* t = newTemp();
            if (strcmp((yyvsp[-2].val).type,"float")==0 || strcmp((yyvsp[0].val).type,"float")==0)
                strcpy((yyval.val).type, "float");
            else
                strcpy((yyval.val).type, "integer");
            strcpy((yyval.val).result, t);
            strcpy((yyval.val).value, "?");
            quadr("-", (yyvsp[-2].val).result, (yyvsp[0].val).result, t);
        }
#line 1636 "syntax.tab.c"
    break;

  case 50: /* EXPR: EXPR multiply EXPR  */
#line 418 "syntax.y"
        {
            char* t = newTemp();
            if (strcmp((yyvsp[-2].val).type,"float")==0 || strcmp((yyvsp[0].val).type,"float")==0)
                strcpy((yyval.val).type, "float");
            else
                strcpy((yyval.val).type, "integer");
            strcpy((yyval.val).result, t);
            strcpy((yyval.val).value, "?");
            quadr("*", (yyvsp[-2].val).result, (yyvsp[0].val).result, t);
        }
#line 1651 "syntax.tab.c"
    break;

  case 51: /* EXPR: EXPR divide EXPR  */
#line 429 "syntax.y"
        {
            char* t = newTemp();
            if (strcmp((yyvsp[0].val).value, "0") == 0 || strcmp((yyvsp[0].val).value, "0.000000") == 0)
                printf("Erreur Semantique, ligne %d, colonne %d : division par zero\n",
                       yylineno, yycolumn);
            if (strcmp((yyvsp[-2].val).type,"float")==0 || strcmp((yyvsp[0].val).type,"float")==0)
                strcpy((yyval.val).type, "float");
            else
                strcpy((yyval.val).type, "integer");
            strcpy((yyval.val).result, t);
            strcpy((yyval.val).value, "?");
            quadr("/", (yyvsp[-2].val).result, (yyvsp[0].val).result, t);
        }
#line 1669 "syntax.tab.c"
    break;

  case 52: /* EXPR: minus EXPR  */
#line 443 "syntax.y"
        {
            char* t = newTemp();
            strcpy((yyval.val).type, (yyvsp[0].val).type);
            strcpy((yyval.val).value, "?");
            strcpy((yyval.val).result, t);
            quadr("NEG", (yyvsp[0].val).result, "", t);
        }
#line 1681 "syntax.tab.c"
    break;

  case 53: /* EXPR: lparen EXPR rparen  */
#line 451 "syntax.y"
        {
            (yyval.val) = (yyvsp[-1].val);
        }
#line 1689 "syntax.tab.c"
    break;

  case 54: /* EXPR: identifier  */
#line 455 "syntax.y"
        {   
            if(checkUndeclared((yyvsp[0].str)) == -1) {
                printf("Erreur Semantique, ligne %d, colonne %d : variable non declaree '%s'\n", yylineno, yycolumn, (yyvsp[0].str));
                updateType((yyvsp[0].str), "integer");
                strcpy((yyval.val).type, "integer");
            } else {
                strcpy((yyval.val).type, idf_type((yyvsp[0].str)));
            }
            strcpy((yyval.val).value, "?");
            strcpy((yyval.val).result, (yyvsp[0].str));
        }
#line 1705 "syntax.tab.c"
    break;

  case 55: /* EXPR: identifier lbracket int_literal rbracket  */
#line 467 "syntax.y"
        {   
            char* t;
            char accessStr[40];
            if(checkUndeclared((yyvsp[-3].str)) == -1) {
                printf("Erreur Semantique, ligne %d, colonne %d : variable non declaree '%s'\n", yylineno, yycolumn, (yyvsp[-3].str));
                strcpy((yyval.val).type, "integer");
            }
            else if(checkTableIndex((yyvsp[-3].str), (yyvsp[-1].entier)) == -1) {
                printf("Erreur Semantique, ligne %d, colonne %d : index %d hors limites pour '%s'\n", yylineno, yycolumn, (yyvsp[-1].entier), (yyvsp[-3].str));
                strcpy((yyval.val).type, idf_type((yyvsp[-3].str)));
            }
            else {
                strcpy((yyval.val).type, idf_type((yyvsp[-3].str)));
            }
            strcpy((yyval.val).value, "?");
            sprintf(accessStr, "%s[%d]", (yyvsp[-3].str), (yyvsp[-1].entier));
            t = newTemp();
            strcpy((yyval.val).result, t);
            quadr("=", accessStr, "", t);
        }
#line 1730 "syntax.tab.c"
    break;

  case 56: /* EXPR: int_literal  */
#line 488 "syntax.y"
        {
            sprintf((yyval.val).value, "%d", (yyvsp[0].entier));
            strcpy((yyval.val).type, "integer");
            sprintf((yyval.val).result, "%d", (yyvsp[0].entier));
        }
#line 1740 "syntax.tab.c"
    break;

  case 57: /* EXPR: float_literal  */
#line 494 "syntax.y"
        {
            sprintf((yyval.val).value, "%f", (yyvsp[0].numvrg));
            strcpy((yyval.val).type, "float");
            sprintf((yyval.val).result, "%f", (yyvsp[0].numvrg));
        }
#line 1750 "syntax.tab.c"
    break;

  case 58: /* COND: EXPR less_than EXPR  */
#line 504 "syntax.y"
        { 
            char* t = newTemp();
            quadr("<", (yyvsp[-2].val).result, (yyvsp[0].val).result, t);
            quadr("BZ", t, "", "?");
        }
#line 1760 "syntax.tab.c"
    break;

  case 59: /* COND: EXPR greater_than EXPR  */
#line 510 "syntax.y"
        { 
            char* t = newTemp();
            quadr(">", (yyvsp[-2].val).result, (yyvsp[0].val).result, t);
            quadr("BZ", t, "", "?");
        }
#line 1770 "syntax.tab.c"
    break;

  case 60: /* COND: EXPR less_equal EXPR  */
#line 516 "syntax.y"
        { 
            char* t = newTemp();
            quadr("<=", (yyvsp[-2].val).result, (yyvsp[0].val).result, t);
            quadr("BZ", t, "", "?");
        }
#line 1780 "syntax.tab.c"
    break;

  case 61: /* COND: EXPR greater_equal EXPR  */
#line 522 "syntax.y"
        { 
            char* t = newTemp();
            quadr(">=", (yyvsp[-2].val).result, (yyvsp[0].val).result, t);
            quadr("BZ", t, "", "?");
        }
#line 1790 "syntax.tab.c"
    break;

  case 62: /* COND: EXPR equal_equal EXPR  */
#line 528 "syntax.y"
        { 
            char* t = newTemp();
            quadr("==", (yyvsp[-2].val).result, (yyvsp[0].val).result, t);
            quadr("BZ", t, "", "?");
        }
#line 1800 "syntax.tab.c"
    break;

  case 63: /* COND: EXPR not_equal EXPR  */
#line 534 "syntax.y"
        { 
            char* t = newTemp();
            quadr("!=", (yyvsp[-2].val).result, (yyvsp[0].val).result, t);
            quadr("BZ", t, "", "?");
        }
#line 1810 "syntax.tab.c"
    break;


#line 1814 "syntax.tab.c"

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

#line 545 "syntax.y"



int main(){
    Initialization();
    yyparse();
    afficher();
    
    printf("\n=== CODE AVANT OPTIMISATION ===");
    afficher_qdr(); 
    
    optimiser();
    
    printf("\n=== CODE APRES OPTIMISATION ===");
    afficher_qdr(); 
    
    return 0;
}

void yyerror(char* msg){
    printf("Erreur Syntaxique a la ligne : %d\n", yylineno);
}
