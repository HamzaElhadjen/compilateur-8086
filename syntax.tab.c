
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntax.y"

    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    extern int yylineno; 
    extern int yycolumn;
    void yyerror(char* s);
    char current_type[20] = "";


    


/* Line 189 of yacc.c  */
#line 87 "syntax.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     mc_BeginProject = 258,
     mc_EndProject = 259,
     mc_Setup = 260,
     mc_Run = 261,
     mc_define = 262,
     mc_const = 263,
     mc_if = 264,
     mc_then = 265,
     mc_else = 266,
     mc_endIf = 267,
     mc_loopwhile = 268,
     mc_endloop = 269,
     mc_for = 270,
     mc_in = 271,
     mc_to = 272,
     mc_endfor = 273,
     mc_out = 274,
     mc_AND = 275,
     mc_OR = 276,
     mc_NON = 277,
     PVG = 278,
     DPT = 279,
     PIPE = 280,
     ACCO = 281,
     ACCF = 282,
     CROV = 283,
     CRMF = 284,
     PARO = 285,
     PARF = 286,
     AFF = 287,
     PLUS = 288,
     MINS = 289,
     MULT = 290,
     DIV = 291,
     LEQ = 292,
     GEQ = 293,
     LT = 294,
     GT = 295,
     EQ = 296,
     NEQ = 297,
     EGAL = 298,
     IDF = 299,
     mc_integer = 300,
     mc_float = 301,
     CST_INT = 302,
     CST_FLOAT = 303,
     CHAINE = 304,
     UMINUS = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 14 "syntax.y"

    int entier;
    float numvrg;
    char* str;



/* Line 214 of yacc.c  */
#line 181 "syntax.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 193 "syntax.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  191

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    17,    19,    20,    23,    25,    27,    29,
      31,    37,    45,    49,    51,    53,    55,    57,    59,    61,
      66,    71,    76,    81,    91,    99,   101,   102,   105,   107,
     109,   111,   113,   115,   117,   119,   124,   132,   148,   160,
     170,   182,   188,   194,   198,   200,   202,   204,   208,   212,
     216,   220,   223,   227,   229,   234,   236,   238,   243,   248,
     253,   258,   262,   266,   270,   274,   278,   282,   288,   294,
     299
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,     3,    44,    23,     5,    24,    53,     6,
      24,    26,    63,    27,     4,    23,    -1,    54,    -1,    -1,
      54,    55,    -1,    55,    -1,    56,    -1,    61,    -1,    62,
      -1,     7,    57,    24,    59,    23,    -1,     7,    57,    24,
      59,    43,    60,    23,    -1,    57,    25,    58,    -1,    58,
      -1,    44,    -1,    45,    -1,    46,    -1,    47,    -1,    48,
      -1,    30,    33,    47,    31,    -1,    30,    34,    47,    31,
      -1,    30,    33,    48,    31,    -1,    30,    34,    48,    31,
      -1,     7,    44,    24,    28,    59,    23,    47,    29,    23,
      -1,     8,    44,    24,    59,    43,    60,    23,    -1,    64,
      -1,    -1,    64,    65,    -1,    65,    -1,    66,    -1,    67,
      -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,    44,
      32,    74,    23,    -1,    44,    28,    74,    29,    32,    74,
      23,    -1,     9,    30,    75,    31,    10,    24,    26,    63,
      27,    11,    26,    63,    27,    12,    23,    -1,     9,    30,
      75,    31,    10,    24,    26,    63,    27,    12,    23,    -1,
      13,    30,    75,    31,    26,    63,    27,    14,    23,    -1,
      15,    44,    16,    60,    17,    60,    26,    63,    27,    18,
      23,    -1,    16,    30,    44,    31,    23,    -1,    19,    30,
      72,    31,    23,    -1,    72,    25,    73,    -1,    73,    -1,
      49,    -1,    74,    -1,    74,    33,    74,    -1,    74,    34,
      74,    -1,    74,    35,    74,    -1,    74,    36,    74,    -1,
      34,    74,    -1,    30,    74,    31,    -1,    44,    -1,    44,
      28,    74,    29,    -1,    47,    -1,    48,    -1,    30,    33,
      47,    31,    -1,    30,    34,    47,    31,    -1,    30,    33,
      48,    31,    -1,    30,    34,    48,    31,    -1,    74,    39,
      74,    -1,    74,    40,    74,    -1,    74,    37,    74,    -1,
      74,    38,    74,    -1,    74,    41,    74,    -1,    74,    42,
      74,    -1,    30,    75,    20,    75,    31,    -1,    30,    75,
      21,    75,    31,    -1,    22,    30,    75,    31,    -1,    30,
      75,    31,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    62,    62,    65,    66,    70,    71,    72,
      76,    77,    81,    82,    86,    96,    97,   101,   102,   103,
     104,   105,   106,   110,   124,   133,   133,   136,   137,   141,
     142,   143,   144,   145,   146,   150,   153,   159,   163,   170,
     176,   184,   190,   194,   195,   199,   200,   204,   205,   206,
     207,   208,   209,   210,   216,   222,   223,   224,   225,   226,
     227,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_BeginProject", "mc_EndProject",
  "mc_Setup", "mc_Run", "mc_define", "mc_const", "mc_if", "mc_then",
  "mc_else", "mc_endIf", "mc_loopwhile", "mc_endloop", "mc_for", "mc_in",
  "mc_to", "mc_endfor", "mc_out", "mc_AND", "mc_OR", "mc_NON", "PVG",
  "DPT", "PIPE", "ACCO", "ACCF", "CROV", "CRMF", "PARO", "PARF", "AFF",
  "PLUS", "MINS", "MULT", "DIV", "LEQ", "GEQ", "LT", "GT", "EQ", "NEQ",
  "EGAL", "IDF", "mc_integer", "mc_float", "CST_INT", "CST_FLOAT",
  "CHAINE", "UMINUS", "$accept", "PROGRAMME", "PARTIE_DEC", "LISTE_DEC",
  "DECLARATION", "DEC_VAR", "LISTE_IDF", "IDF_DECL", "TYPE", "VALEUR",
  "DEC_TAB", "DEC_CONST", "PARTIE_INSTR", "LISTE_INSTR", "INSTRUCTION",
  "INST_AFF", "INST_COND", "INST_LOOP_WHILE", "INST_FOR", "INST_IN",
  "INST_OUT", "LISTE_OUT", "OUT_ARG", "EXPR", "COND", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    55,    55,
      56,    56,    57,    57,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    61,    62,    63,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    66,    66,    67,    67,    68,
      69,    70,    71,    72,    72,    73,    73,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    13,     1,     0,     2,     1,     1,     1,     1,
       5,     7,     3,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     9,     7,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     4,     7,    15,    11,     9,
      11,     5,     5,     3,     1,     1,     1,     3,     3,     3,
       3,     2,     3,     1,     4,     1,     1,     4,     4,     4,
       4,     3,     3,     3,     3,     3,     3,     5,     5,     4,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     4,     0,     0,
       0,     3,     6,     7,     8,     9,    14,     0,    13,     0,
       0,     5,     0,     0,     0,     0,     0,     0,    15,    16,
       0,    14,    12,     0,    26,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,    11,    24,     0,     0,     0,    53,    55,    56,
       0,     0,     0,     0,     0,     0,    45,     0,    44,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     2,    23,    19,    21,    20,    22,
       0,     0,     0,    55,    56,    52,     0,     0,    70,     0,
      47,    48,    49,    50,    63,    64,    61,    62,    65,    66,
       0,    26,     0,    41,    43,    42,     0,    69,    57,    59,
      58,    60,     0,     0,    54,     0,     0,     0,     0,    67,
      68,    26,     0,    26,    36,     0,     0,     0,     0,    39,
       0,     0,     0,     0,    26,    38,    40,     0,     0,     0,
      37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    10,    11,    12,    13,    17,    18,    30,    58,
      14,    15,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    87,    88,    80,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -149
static const yytype_int16 yypact[] =
{
      -1,    -7,    41,     8,  -149,    54,    39,    32,    23,    27,
      75,    32,  -149,  -149,  -149,  -149,    64,    19,  -149,    78,
      87,  -149,    99,    28,    69,    28,    91,    28,  -149,  -149,
     -19,  -149,  -149,   108,    13,   143,  -149,    62,    62,   127,
     144,   131,   146,   147,   -23,   151,    13,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,   126,    66,  -149,  -149,   156,   157,
      38,    38,   165,   138,   -14,    57,    57,   179,  -149,   155,
      68,   102,  -149,  -149,   158,    36,    57,   159,  -149,  -149,
     105,   154,   161,    62,   162,    31,  -149,   -12,  -149,   129,
      61,    85,   163,   166,   164,   167,   168,   169,    38,   120,
      59,    95,   -10,  -149,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,   180,   170,   174,   171,   125,
     -14,   178,   172,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
     175,   176,   177,   181,   182,  -149,    38,    38,  -149,   119,
     134,   134,  -149,  -149,   129,   129,   129,   129,   129,   129,
     173,    13,    62,  -149,  -149,  -149,    57,  -149,  -149,  -149,
    -149,  -149,   183,   184,  -149,   185,   189,   191,    89,  -149,
    -149,    13,   188,    13,  -149,   192,   186,   193,   160,  -149,
     187,   195,   199,   200,    13,  -149,  -149,   197,   198,   202,
    -149
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,  -149,  -149,   207,  -149,  -149,   203,   -13,   -38,
    -149,  -149,  -148,  -149,   190,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,    83,   -58,   -60
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      59,    82,     1,   166,    36,    65,    89,    90,    91,    66,
     136,   137,    33,   120,    35,   102,    85,   101,   103,   121,
      76,   138,    39,   175,    37,   177,    40,   119,    41,    42,
      77,     5,    43,    78,    79,    86,   187,     3,   130,     8,
       9,     4,   103,    23,    24,   117,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    44,    74,     6,
      74,    85,    89,     7,    99,   100,    75,    16,    75,    99,
     100,    19,    76,    28,    29,    77,   162,   163,    78,    79,
      77,    20,    77,    78,    79,    78,    79,    85,    22,    85,
     122,    76,    55,    76,   105,   106,   107,   108,   168,    70,
      71,    77,    25,    77,    78,    79,   133,   134,   123,    56,
      57,    26,   174,    31,   167,    94,    95,    34,   105,   106,
     107,   108,   105,   106,   107,   108,   135,    27,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   164,    96,
      97,    38,   105,   106,   107,   108,   135,    60,   105,   106,
     107,   108,   105,   106,   107,   108,    54,   131,   132,   107,
     108,   181,   182,    69,    61,    62,    63,    64,    67,    72,
      73,    83,    84,    92,    93,   115,   124,   104,    98,   125,
     150,   152,   116,   118,   153,   126,   151,   165,   127,   128,
     129,   155,   176,   154,   156,   183,   157,   158,   159,   179,
     189,   171,   160,   161,   169,   170,   172,   173,    21,   178,
     180,   184,   185,   186,   188,   190,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,    68
};

static const yytype_int16 yycheck[] =
{
      38,    61,     3,   151,    23,    28,    64,    65,    66,    32,
      20,    21,    25,    25,    27,    75,    30,    75,    76,    31,
      34,    31,     9,   171,    43,   173,    13,    85,    15,    16,
      44,    23,    19,    47,    48,    49,   184,    44,    98,     7,
       8,     0,   100,    24,    25,    83,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    44,    22,     5,
      22,    30,   120,    24,    33,    34,    30,    44,    30,    33,
      34,    44,    34,    45,    46,    44,   136,   137,    47,    48,
      44,     6,    44,    47,    48,    47,    48,    30,    24,    30,
      29,    34,    30,    34,    33,    34,    35,    36,   156,    33,
      34,    44,    24,    44,    47,    48,    47,    48,    23,    47,
      48,    24,    23,    44,   152,    47,    48,    26,    33,    34,
      35,    36,    33,    34,    35,    36,    31,    28,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    29,    47,
      48,    43,    33,    34,    35,    36,    31,    30,    33,    34,
      35,    36,    33,    34,    35,    36,    23,    47,    48,    35,
      36,    11,    12,    47,    30,    44,    30,    30,    27,    23,
      23,    16,    44,     4,    29,    31,    23,    28,    30,    23,
      10,    17,    31,    31,    23,    31,    26,    24,    31,    31,
      31,    23,    14,   120,    32,    18,    31,    31,    31,    23,
      12,    26,    31,    31,    31,    31,    27,    26,    11,    27,
      27,    26,    23,    23,    27,    23,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    52,    44,     0,    23,     5,    24,     7,     8,
      53,    54,    55,    56,    61,    62,    44,    57,    58,    44,
       6,    55,    24,    24,    25,    24,    24,    28,    45,    46,
      59,    44,    58,    59,    26,    59,    23,    43,    43,     9,
      13,    15,    16,    19,    44,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    23,    30,    47,    48,    60,    60,
      30,    30,    44,    30,    30,    28,    32,    27,    65,    47,
      33,    34,    23,    23,    22,    30,    34,    44,    47,    48,
      74,    75,    75,    16,    44,    30,    49,    72,    73,    74,
      74,    74,     4,    29,    47,    48,    47,    48,    30,    33,
      34,    74,    75,    74,    28,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    31,    31,    60,    31,    74,
      25,    31,    29,    23,    23,    23,    31,    31,    31,    31,
      75,    47,    48,    47,    48,    31,    20,    21,    31,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      10,    26,    17,    23,    73,    23,    32,    31,    31,    31,
      31,    31,    75,    75,    29,    24,    63,    60,    74,    31,
      31,    26,    27,    26,    23,    63,    14,    63,    27,    23,
      27,    11,    12,    18,    26,    23,    23,    63,    27,    12,
      23
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 56 "syntax.y"
    {
          printf("\n>>> Programme '%s' syntaxiquement correct.\n", (yyvsp[(2) - (13)].str));
          YYACCEPT;
      ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 87 "syntax.y"
    {
          if(checkNoDuplicate((yyvsp[(1) - (1)].str))==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable deja declaree)\n", yylineno, yycolumn, (yyvsp[(1) - (1)].str));
          updateCode((yyvsp[(1) - (1)].str), "Var");
          updateType((yyvsp[(1) - (1)].str), current_type);
      ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 96 "syntax.y"
    { strcpy(current_type, "integer"); (yyval.str) = "integer"; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 97 "syntax.y"
    { strcpy(current_type, "float");   (yyval.str) = "float";   ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 111 "syntax.y"
    {
          if(checkNoDuplicate((yyvsp[(2) - (9)].str))==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable deja declaree)\n", yylineno, yycolumn, (yyvsp[(2) - (9)].str));
          updateCode((yyvsp[(2) - (9)].str), "Tableau");
          updateType((yyvsp[(2) - (9)].str), current_type);
          if ((yyvsp[(7) - (9)].entier) <= 0)
              printf("Erreur_Semantique, ligne %d, taille du tableau '%s' doit etre > 0\n",
                     yylineno, (yyvsp[(2) - (9)].str));
      ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 125 "syntax.y"
    {
          if(checkNoDuplicate((yyvsp[(2) - (7)].str))==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable deja declaree)\n", yylineno, yycolumn, (yyvsp[(2) - (7)].str));
          updateCode((yyvsp[(2) - (7)].str), "Const");
          updateType((yyvsp[(2) - (7)].str), current_type);
      ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 151 "syntax.y"
    { if(checkDeclared((yyvsp[(1) - (4)].str))==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable non declaree)\n", yylineno, yycolumn, (yyvsp[(1) - (4)].str));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 154 "syntax.y"
    { if(checkDeclared((yyvsp[(1) - (7)].str))==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable non declaree)\n", yylineno, yycolumn, (yyvsp[(1) - (7)].str)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 179 "syntax.y"
    { if(checkDeclared((yyvsp[(2) - (11)].str))==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable non declaree)\n", yylineno, yycolumn, (yyvsp[(2) - (11)].str)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 185 "syntax.y"
    { if(checkDeclared((yyvsp[(3) - (5)].str))==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable non declaree)\n", yylineno, yycolumn, (yyvsp[(3) - (5)].str)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 204 "syntax.y"
    { (yyval.str) = "expr"; ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 205 "syntax.y"
    { (yyval.str) = "expr"; ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 206 "syntax.y"
    { (yyval.str) = "expr"; ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 207 "syntax.y"
    { (yyval.str) = "expr"; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 208 "syntax.y"
    { (yyval.str) = "expr"; ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 209 "syntax.y"
    { (yyval.str) = (yyvsp[(2) - (3)].str); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 211 "syntax.y"
    {
          if(checkDeclared((yyvsp[(1) - (1)].str))==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable non declaree)\n", yylineno, yycolumn, (yyvsp[(1) - (1)].str));
          (yyval.str) = (yyvsp[(1) - (1)].str);
      ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 217 "syntax.y"
    {
          if(checkDeclared((yyvsp[(1) - (4)].str))==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable non declaree)\n", yylineno, yycolumn, (yyvsp[(1) - (4)].str));
          (yyval.str) = (yyvsp[(1) - (4)].str);
      ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 222 "syntax.y"
    { (yyval.str) = "integer"; ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 223 "syntax.y"
    { (yyval.str) = "float";   ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 224 "syntax.y"
    { (yyval.str) = "integer"; ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 225 "syntax.y"
    { (yyval.str) = "integer"; ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 226 "syntax.y"
    { (yyval.str) = "float"; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 227 "syntax.y"
    { (yyval.str) = "float"; ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 231 "syntax.y"
    { (yyval.str) = "cond"; ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 232 "syntax.y"
    { (yyval.str) = "cond"; ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 233 "syntax.y"
    { (yyval.str) = "cond"; ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 234 "syntax.y"
    { (yyval.str) = "cond"; ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 235 "syntax.y"
    { (yyval.str) = "cond"; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 236 "syntax.y"
    { (yyval.str) = "cond"; ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 237 "syntax.y"
    { (yyval.str) = "cond"; ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 238 "syntax.y"
    { (yyval.str) = "cond"; ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 239 "syntax.y"
    { (yyval.str) = "cond"; ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 240 "syntax.y"
    { (yyval.str) = (yyvsp[(2) - (3)].str);     ;}
    break;



/* Line 1455 of yacc.c  */
#line 1826 "syntax.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 243 "syntax.y"



int main(){
    Initialization();
    yyparse();
    afficher();
return 0;
}
void yyerror(char* msg){
    printf("Erreur Syntaxique a la ligne : %d\n",yylineno);
}
