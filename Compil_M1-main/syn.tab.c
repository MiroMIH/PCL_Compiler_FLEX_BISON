/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

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
#line 1 "syn.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "TS.h"
#include "quads.h"
#include "TSM.h"

extern FILE* yyin ;


int qc = 0;
char tmp[20], tmp2[20], tmp3[20], tmp4[20], tabName[20];
/* IF */
int deb_if;
int fin_if;
int deb_else;
int fin_else;
/* WHILE */
int deb_while;
int fin_while;
/* FOR */
int deb_for;
int fin_for;

//save operateur comparaison
char opcomp[100];


extern int line;
extern int column;
int saveType;
int yyparse();
int yylex();
int yyerror(char *s); 
  
int t = -1;
int j;


/* Line 189 of yacc.c  */
#line 113 "syn.tab.c"

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
     LEFTACC = 258,
     RIGHTACC = 259,
     pvg = 260,
     vrg = 261,
     MC_VAR = 262,
     MC_CODE = 263,
     MC_INTEGER = 264,
     MCWHILE = 265,
     MC_FLOAT = 266,
     MC_CONST = 267,
     TADD = 268,
     TSUB = 269,
     TMUL = 270,
     TDIV = 271,
     TAFF = 272,
     TSUP = 273,
     TINF = 274,
     TSUPEQ = 275,
     TEQL = 276,
     TNEQL = 277,
     MC_IF = 278,
     MC_ELSE = 279,
     TPARLEFT = 280,
     TPARRIGHT = 281,
     TDOT = 282,
     TOR = 283,
     TAND = 284,
     TNOT = 285,
     TRBRACKET = 286,
     TLBRACKET = 287,
     MC_FOR = 288,
     dd = 289,
     MC_STRUCT = 290,
     TINFEQ = 291,
     idf = 292,
     var_int = 293,
     var_float = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 43 "syn.y"

    int entier;
    float FLOAT;
    char* str;
    struct {
		int intValue;
		char* strValue;
        int isInt;
        int val;
        int isComplex;
	} exp_type;



/* Line 214 of yacc.c  */
#line 203 "syn.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 215 "syn.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    15,    20,    27,    28,    37,    38,    47,
      48,    55,    56,    60,    62,    65,    67,    68,    70,    73,
      75,    77,    83,    88,    93,    97,   104,   110,   115,   120,
     125,   136,   138,   140,   144,   148,   152,   156,   160,   162,
     164,   166,   171,   175,   179,   181,   185,   187,   190,   192,
     194,   198,   202,   206,   210,   214,   218,   222,   226,   230,
     234,   236,   238,   240,   245
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    37,     3,     7,     3,    42,     4,     8,
       3,    47,     4,     4,    -1,    57,    46,     5,    42,    -1,
      12,    37,    17,    58,     5,    42,    -1,    -1,    57,    37,
      31,    43,    38,    32,     5,    42,    -1,    -1,    35,     3,
      42,     4,    37,    44,     5,    42,    -1,    -1,    35,    45,
      37,    46,     5,    42,    -1,    -1,    37,     6,    46,    -1,
      37,    -1,    48,    47,    -1,    48,    -1,    -1,    49,    -1,
      52,     5,    -1,    53,    -1,    55,    -1,    50,    24,     3,
      47,     4,    -1,    51,     3,    47,     4,    -1,    23,    25,
      59,    26,    -1,    37,    17,    58,    -1,    37,    31,    38,
      32,    17,    58,    -1,    37,    27,    37,    17,    58,    -1,
      54,     3,    47,     4,    -1,    10,    25,    59,    26,    -1,
      56,     3,    47,     4,    -1,    33,    25,    37,    34,    58,
      34,    58,    34,    58,    26,    -1,     9,    -1,    11,    -1,
      58,    13,    58,    -1,    58,    14,    58,    -1,    58,    15,
      58,    -1,    58,    16,    58,    -1,    25,    58,    26,    -1,
      37,    -1,    38,    -1,    39,    -1,    37,    31,    38,    32,
      -1,    37,    27,    37,    -1,    59,    28,    60,    -1,    60,
      -1,    60,    29,    61,    -1,    61,    -1,    30,    62,    -1,
      62,    -1,    63,    -1,    63,    13,    63,    -1,    63,    14,
      63,    -1,    63,    15,    63,    -1,    63,    16,    63,    -1,
      63,    18,    63,    -1,    63,    19,    63,    -1,    63,    36,
      63,    -1,    63,    20,    63,    -1,    63,    21,    63,    -1,
      63,    22,    63,    -1,    37,    -1,    38,    -1,    39,    -1,
      37,    31,    38,    32,    -1,    37,    27,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    76,    76,    77,    77,    78,    78,    79,
      79,    80,    82,    83,    85,    86,    87,    89,    90,    91,
      92,    94,   102,   113,   118,   143,   144,   146,   161,   166,
     180,   186,   186,   188,   221,   254,   287,   335,   336,   339,
     340,   341,   342,   344,   345,   347,   348,   350,   351,   353,
     355,   356,   357,   358,   359,   363,   369,   375,   379,   384,
     389,   390,   391,   392,   393
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LEFTACC", "RIGHTACC", "pvg", "vrg",
  "MC_VAR", "MC_CODE", "MC_INTEGER", "MCWHILE", "MC_FLOAT", "MC_CONST",
  "TADD", "TSUB", "TMUL", "TDIV", "TAFF", "TSUP", "TINF", "TSUPEQ", "TEQL",
  "TNEQL", "MC_IF", "MC_ELSE", "TPARLEFT", "TPARRIGHT", "TDOT", "TOR",
  "TAND", "TNOT", "TRBRACKET", "TLBRACKET", "MC_FOR", "dd", "MC_STRUCT",
  "TINFEQ", "idf", "var_int", "var_float", "$accept", "S", "DECLARATION",
  "$@1", "$@2", "$@3", "LISTIDF", "PARTINST", "INST", "INST_IF",
  "INST_IF_1", "INST_IF_2", "INST_AFF", "INST_WHILE", "INST_WHILE_COND",
  "INST_FOR", "INST_FOR_INDICE", "TYPE", "EXP", "COND_OR", "COND_AND",
  "COND_NOT", "COND_EXP", "EXP_COMP", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    42,    44,    42,    45,
      42,    42,    46,    46,    47,    47,    47,    48,    48,    48,
      48,    49,    50,    51,    52,    52,    52,    53,    54,    55,
      56,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    11,     4,     6,     0,     8,     0,     8,     0,
       6,     0,     3,     1,     2,     1,     0,     1,     2,     1,
       1,     5,     4,     4,     3,     6,     5,     4,     4,     4,
      10,     1,     1,     3,     3,     3,     3,     3,     1,     1,
       1,     4,     3,     3,     1,     3,     1,     2,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    11,    31,    32,     0,
       9,     0,     0,     0,    11,     0,     0,    13,     0,     0,
       0,     0,     0,     0,     5,    11,     0,    38,    39,    40,
       0,     0,    13,     0,    16,    12,     0,     3,     0,     0,
       0,    11,     0,     0,     0,     0,     7,    11,     0,     0,
       0,     0,     0,    15,    17,     0,     0,     0,    19,     0,
      20,     0,     0,    37,    42,     0,     4,    33,    34,    35,
      36,     0,    10,     0,     0,     0,     0,     0,     0,     0,
      14,     0,    16,    18,    16,    16,     0,    41,    11,     0,
      60,    61,    62,     0,    44,    46,    48,    49,     0,     0,
      24,     0,     0,     2,    16,     0,     0,     0,    11,     8,
      47,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,    22,    27,    29,     6,    64,     0,    43,    45,    50,
      51,    52,    53,    54,    55,    57,    58,    59,    56,     0,
      26,     0,    21,    63,     0,    25,     0,     0,     0,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    11,    36,    71,    15,    18,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    12,    30,    93,
      94,    95,    96,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -50
static const yytype_int16 yypact[] =
{
     -34,     3,    11,    20,   -50,    29,    -4,   -50,   -50,   -23,
      34,    39,    12,    62,    -4,    81,    63,     7,   117,   -16,
     119,    89,   121,    89,   -50,    -4,   -16,    -1,   -50,   -50,
      68,    90,   123,   125,    -8,   -50,    94,   -50,    50,    97,
      95,    -4,   -16,   -16,   -16,   -16,   -50,    -4,   110,   111,
     112,    -7,   134,    -8,   -50,   115,   137,   136,   -50,   139,
     -50,   140,   113,   -50,   -50,   114,   -50,    45,    45,   -50,
     -50,   142,   -50,    66,    66,   107,   -16,   116,   118,   144,
     -50,   146,    -8,   -50,    -8,    -8,   145,   -50,    -4,    73,
      47,   -50,   -50,    87,   122,   -50,   -50,    26,    88,   120,
      84,   135,   126,   -50,    -8,   151,   153,   155,    -4,   -50,
     -50,   124,   127,   -50,    66,    66,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,   -50,   -16,   -16,   143,
     158,   -50,   -50,   -50,   -50,   -50,   131,   122,   -50,   105,
     105,   -50,   -50,    93,    93,    93,    93,    93,    93,    38,
      84,   -16,   -50,   -50,   -16,    84,    43,   -16,    54,   -50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,   -13,   -50,   -50,   -50,    96,   -49,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -26,    92,
      53,    49,    79,   -31
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      38,    20,    48,     1,    80,     7,     3,     8,     9,    26,
      76,     4,    37,    23,    13,    49,    67,    68,    69,    70,
      77,    27,    28,    29,    78,    50,    39,     5,    66,    51,
      40,    10,     6,   105,    72,   106,   107,    14,    24,   116,
     117,   118,   119,    16,   120,   121,   122,   123,   124,    17,
     100,    42,    43,    44,    45,   130,    42,    43,    44,    45,
      44,    45,   125,    42,    43,    44,    45,    42,    43,    44,
      45,    22,   154,    41,   111,   109,    63,   157,   112,    19,
     159,    42,    43,    44,    45,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   134,    89,    42,    43,    44,
      45,   149,   150,    90,    91,    92,   116,   117,   118,   119,
      90,    91,    92,   113,   126,   114,   114,    33,    21,    35,
     118,   119,    25,    31,    34,   155,    32,    46,   156,    23,
      47,   158,    62,    65,    64,    73,    74,    75,    79,    81,
      82,    83,    84,    85,    99,    86,    87,    88,   103,   104,
     108,   115,   128,   101,   127,   131,   102,   132,   129,   133,
     151,   135,   152,   153,   138,   136,    98,   137,   110
};

static const yytype_uint8 yycheck[] =
{
      26,    14,    10,    37,    53,     9,     3,    11,    12,    25,
      17,     0,    25,     6,    37,    23,    42,    43,    44,    45,
      27,    37,    38,    39,    31,    33,    27,     7,    41,    37,
      31,    35,     3,    82,    47,    84,    85,     3,    31,    13,
      14,    15,    16,     4,    18,    19,    20,    21,    22,    37,
      76,    13,    14,    15,    16,   104,    13,    14,    15,    16,
      15,    16,    36,    13,    14,    15,    16,    13,    14,    15,
      16,     8,    34,     5,    27,    88,    26,    34,    31,    17,
      26,    13,    14,    15,    16,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   108,    30,    13,    14,    15,
      16,   127,   128,    37,    38,    39,    13,    14,    15,    16,
      37,    38,    39,    26,    26,    28,    28,    21,    37,    23,
      15,    16,     5,     4,     3,   151,    37,    37,   154,     6,
       5,   157,    38,    38,    37,    25,    25,    25,     4,    24,
       3,     5,     3,     3,    37,    32,    32,     5,     4,     3,
       5,    29,    17,    37,    34,     4,    38,     4,    32,     4,
      17,    37,     4,    32,   115,    38,    74,   114,    89
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    41,     3,     0,     7,     3,     9,    11,    12,
      35,    42,    57,    37,     3,    45,     4,    37,    46,    17,
      42,    37,     8,     6,    31,     5,    25,    37,    38,    39,
      58,     4,    37,    46,     3,    46,    43,    42,    58,    27,
      31,     5,    13,    14,    15,    16,    37,     5,    10,    23,
      33,    37,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    38,    26,    37,    38,    42,    58,    58,    58,
      58,    44,    42,    25,    25,    25,    17,    27,    31,     4,
      47,    24,     3,     5,     3,     3,    32,    32,     5,    30,
      37,    38,    39,    59,    60,    61,    62,    63,    59,    37,
      58,    37,    38,     4,     3,    47,    47,    47,     5,    42,
      62,    27,    31,    26,    28,    29,    13,    14,    15,    16,
      18,    19,    20,    21,    22,    36,    26,    34,    17,    32,
      47,     4,     4,     4,    42,    37,    38,    60,    61,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    58,
      58,    17,     4,    32,    34,    58,    58,    34,    58,    26
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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

/* Line 1464 of yacc.c  */
#line 74 "syn.y"
    {printf ("programme syntaxiquement juste \n");YYACCEPT ;;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 76 "syn.y"
    {insert((yyvsp[(2) - (6)].str),1,0); insertType((yyvsp[(2) - (6)].str),1);;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 77 "syn.y"
    {insert((yyvsp[(2) - (3)].str),0,1); insertType((yyvsp[(2) - (3)].str),saveType);;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 78 "syn.y"
    {insertTsT((yyvsp[(5) - (5)].str));;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 79 "syn.y"
    {saveType = 3;;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 79 "syn.y"
    {if(rechercherTsT((yyvsp[(3) - (6)].str))==0) printf("Erreur sémantique : La structure n'est pas declarée \n");;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 82 "syn.y"
    {insert((yyvsp[(1) - (3)].str),0,0); insertType((yyvsp[(1) - (3)].str),saveType);;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 83 "syn.y"
    {insert((yyvsp[(1) - (1)].str),0,0); insertType((yyvsp[(1) - (1)].str),saveType);;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 94 "syn.y"
    {
    fin_else = qc; 
    //add_quad(int num_quad, int colon_quad, char val[])
    char str[20];
    sprintf(str, "%d", fin_else);
    add_quad(fin_if,1,str);
;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 102 "syn.y"
    {
    fin_if = qc;
    quadr("BR","fin_else","",""); 
    /*deb else*/ 
    deb_else = qc; 
    //add_quad(int num_quad, int colon_quad, char val[])
    char str[20];
    sprintf(str, "%d", deb_else);
    add_quad(deb_if,1,str);
    ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 113 "syn.y"
    {
    deb_if = qc;
    quadr(opcomp,"","tmp_cond1","tmp_cond2");
    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 118 "syn.y"
    {if(lookup((yyvsp[(1) - (3)].str))==NULL) printf("Variable %s non declarée affectation\n",(yyvsp[(1) - (3)].str)); 

if(lookup((yyvsp[(1) - (3)].str))!=NULL) {
    updateVal((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].exp_type).val);

    if(lookup((yyvsp[(1) - (3)].str))->isConst ==1)
    {
        printf("ERREUR SEMANTIQUE : affectation à une constante %s\n",(yyvsp[(1) - (3)].str));
    }    
}
j = 0;
    if((yyvsp[(3) - (3)].exp_type).isComplex ==1)
    {
        quadr(":=",getTemp(),"",(yyvsp[(1) - (3)].str));    
    }else {
        if((yyvsp[(3) - (3)].exp_type).isInt==1)
        {
            char str1[10];
            sprintf(str1, "%d", (yyvsp[(3) - (3)].exp_type).intValue);
            quadr(":=",str1,"",(yyvsp[(1) - (3)].str));    
        }else {
            quadr(":=",(yyvsp[(3) - (3)].exp_type).strValue,"",(yyvsp[(1) - (3)].str));    
        }
    }
;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 146 "syn.y"
    {
    fin_while = qc;
    //fin_while++;
    char str[20];
    sprintf(str, "%d", fin_while);
    char str2[20];
    sprintf(str2, "%d", deb_while);
    quadr("BR",str2,"","");
    fin_while++; 
    sprintf(str, "%d", fin_while);
    add_quad(deb_while,1,str);
    //add_quad(fin_while,1,str);

;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 161 "syn.y"
    {
    deb_while = qc;
    quadr(opcomp,"","tmp_cond1","tmp_cond2");
    ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 166 "syn.y"
    {
     fin_for = qc;
    //fin_while++;
    char str[20];
    sprintf(str, "%d", fin_for);
    char str2[20];
    sprintf(str2, "%d", deb_for);
    quadr("BR",str2,"","");
    fin_for++;
    sprintf(str, "%d", fin_for);
    add_quad(deb_for,1,str);
    //add_quad(fin_while,1,str);
;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 180 "syn.y"
    {
    if(lookup((yyvsp[(3) - (10)].str))==NULL) printf("Variable %s non declarée boucle for \n",(yyvsp[(3) - (10)].str));
    deb_for = qc;
    quadr(opcomp,"","tmp_cond1","tmp_cond2");
;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 186 "syn.y"
    {saveType = 1;;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 186 "syn.y"
    {saveType = 2;;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 188 "syn.y"
    { 
    char str1[10];
    char str2[10];
    (yyval.exp_type).isComplex = 1;

    if((yyvsp[(1) - (3)].exp_type).isInt)
    {
        sprintf(str1, "%d", (yyvsp[(1) - (3)].exp_type).intValue);
        (yyval.exp_type).val = (yyvsp[(1) - (3)].exp_type).val;
            }else {
        strcpy(str1,(yyvsp[(1) - (3)].exp_type).strValue);
    }
     if((yyvsp[(3) - (3)].exp_type).isInt)
    {
        sprintf(str2, "%d", (yyvsp[(3) - (3)].exp_type).intValue);
        (yyval.exp_type).val = (yyval.exp_type).val + (yyvsp[(3) - (3)].exp_type).val;
        }else {
        strcpy(str2,(yyvsp[(3) - (3)].exp_type).strValue);
    }
     char str3[100] = "t";
     char str4[20];
   
    sprintf(str4, "%d", t);
    strcat(str3, str4);
        t++;
    if(j==0)
    {
        quadr("+",str1,str2,getTemp());
    }else {
        quadr("+",getTempMinus(),str2,getTemp());
    }
    j++;
    ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 221 "syn.y"
    { 
    char str1[10];
    char str2[10];
    (yyval.exp_type).isComplex = 1;

    if((yyvsp[(1) - (3)].exp_type).isInt)
    {
        sprintf(str1, "%d", (yyvsp[(1) - (3)].exp_type).intValue);
        (yyval.exp_type).val = (yyvsp[(1) - (3)].exp_type).val;
            }else {
        strcpy(str1,(yyvsp[(1) - (3)].exp_type).strValue);
    }
     if((yyvsp[(3) - (3)].exp_type).isInt)
    {
        sprintf(str2, "%d", (yyvsp[(3) - (3)].exp_type).intValue);
        (yyval.exp_type).val = (yyval.exp_type).val - (yyvsp[(3) - (3)].exp_type).val;
        }else {
        strcpy(str2,(yyvsp[(3) - (3)].exp_type).strValue);
    }
     char str3[100] = "t";
     char str4[20];
   
    sprintf(str4, "%d", t);
    strcat(str3, str4);
        t++;
    if(j==0)
    {
        quadr("-",str1,str2,getTemp());
    }else {
        quadr("-",getTempMinus(),str2,getTemp());
    }
    j++;
    ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 254 "syn.y"
    { 
    char str1[10];
    char str2[10];
    (yyval.exp_type).isComplex = 1;

    if((yyvsp[(1) - (3)].exp_type).isInt)
    {
        sprintf(str1, "%d", (yyvsp[(1) - (3)].exp_type).intValue);
        (yyval.exp_type).val = (yyvsp[(1) - (3)].exp_type).val;
            }else {
        strcpy(str1,(yyvsp[(1) - (3)].exp_type).strValue);
    }
     if((yyvsp[(3) - (3)].exp_type).isInt)
    {
        sprintf(str2, "%d", (yyvsp[(3) - (3)].exp_type).intValue);
        (yyval.exp_type).val = (yyval.exp_type).val * (yyvsp[(3) - (3)].exp_type).val;
        }else {
        strcpy(str2,(yyvsp[(3) - (3)].exp_type).strValue);
    }
     char str3[100] = "t";
     char str4[20];
   
    sprintf(str4, "%d", t);
    strcat(str3, str4);
        t++;
    if(j==0)
    {
        quadr("*",str1,str2,getTemp());
    }else {
        quadr("*",getTempMinus(),str2,getTemp());
    }
    j++;
    ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 287 "syn.y"
    { 
    char str1[10];
    char str2[10];
    (yyval.exp_type).isComplex = 1;
    if((yyvsp[(3) - (3)].exp_type).isInt == 1 && (yyvsp[(3) - (3)].exp_type).val == 0)
    {
        printf("Erreur sémantique : Division sur 0\n");
        printf("%d",(yyvsp[(3) - (3)].exp_type).val);
    }
    if((yyvsp[(3) - (3)].exp_type).isInt == 0 && lookup((yyvsp[(3) - (3)].exp_type).strValue) != NULL)
    {
        if(lookup((yyvsp[(3) - (3)].exp_type).strValue)->value == 0)
        {
            printf("Erreur sémantique : Division sur 0\n");
        }
    }

    if((yyvsp[(1) - (3)].exp_type).isInt)
    {
        sprintf(str1, "%d", (yyvsp[(1) - (3)].exp_type).intValue);
        (yyval.exp_type).val = (yyvsp[(1) - (3)].exp_type).val;
            }else {
        strcpy(str1,(yyvsp[(1) - (3)].exp_type).strValue);
    }
     if((yyvsp[(3) - (3)].exp_type).isInt)
    {
        sprintf(str2, "%d", (yyvsp[(3) - (3)].exp_type).intValue);
        if((yyvsp[(3) - (3)].exp_type).val != 0)
        {
            (yyval.exp_type).val = (yyval.exp_type).val / (yyvsp[(3) - (3)].exp_type).val;
        }
        }else {
        strcpy(str2,(yyvsp[(3) - (3)].exp_type).strValue);
    }
     char str3[100] = "t";
     char str4[20];
   
    sprintf(str4, "%d", t);
    strcat(str3, str4);
        t++;
    if(j==0)
    {
        quadr("/",str1,str2,getTemp());
    }else {
        quadr("/",getTempMinus(),str2,getTemp());
    }
    j++;
    ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 335 "syn.y"
    { (yyval.exp_type) = (yyvsp[(2) - (3)].exp_type); ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 337 "syn.y"
    {if(lookup((yyvsp[(1) - (1)].str))==NULL) printf("Variable %s non declarée expression \n",(yyvsp[(1) - (1)].str)); 
{            (yyval.exp_type).strValue = (yyvsp[(1) - (1)].str);  (yyval.exp_type).isInt = 0; (yyval.exp_type).isComplex = 0;};}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 339 "syn.y"
    {    (yyval.exp_type).intValue = (yyvsp[(1) - (1)].entier); (yyval.exp_type).isInt = 1; (yyval.exp_type).val = (yyvsp[(1) - (1)].entier); (yyval.exp_type).isComplex = 0; ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 340 "syn.y"
    {    (yyval.exp_type).intValue = (yyvsp[(1) - (1)].FLOAT); (yyval.exp_type).isInt = 1;  (yyval.exp_type).val = (yyvsp[(1) - (1)].FLOAT); (yyval.exp_type).isComplex = 0;;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 341 "syn.y"
    {(yyval.exp_type).intValue = atoi((yyvsp[(1) - (4)].str)); (yyval.exp_type).isInt = 1;  (yyval.exp_type).val = atoi((yyvsp[(1) - (4)].str)); (yyval.exp_type).isComplex = 0;;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 342 "syn.y"
    {(yyval.exp_type).intValue = atoi((yyvsp[(1) - (3)].str)); (yyval.exp_type).isInt = 1;  (yyval.exp_type).val = atoi((yyvsp[(1) - (3)].str)); (yyval.exp_type).isComplex = 0;;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 359 "syn.y"
    {
    char str[] = "BG";
    strcpy(opcomp,str);
    ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 363 "syn.y"
    {
    
    char str[] = "BL";
    strcpy(opcomp,str);
    
;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 369 "syn.y"
    {
    
    char str[] = "BLE";
    strcpy(opcomp,str);
    
;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 375 "syn.y"
    {
    char str[] = "BGE";
    strcpy(opcomp,str);
    ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 380 "syn.y"
    {
    char str[] = "BE";
    strcpy(opcomp,str);
    ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 385 "syn.y"
    {
    char str[] = "BNE";
    strcpy(opcomp,str);
    ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 389 "syn.y"
    {if(lookup((yyvsp[(1) - (1)].str))==NULL) printf("Variable %s non declarée expression comp\n",(yyvsp[(1) - (1)].str));;}
    break;



/* Line 1464 of yacc.c  */
#line 2030 "syn.tab.c"
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



/* Line 1684 of yacc.c  */
#line 395 "syn.y"

int yyerror(char* msg)
{printf("%s ligne %d et colonne %d",msg,line,column);
return 0;
}
int main()  {    

    /*printf("%d\n", lookup("x"));
    printf("%d\n", lookup("y"));
    printf("%d\n", lookup("z"));
    printf("%d\n", lookup("w")); // should return -1*/
    //print_symbol_table();
    yyin=fopen("example.txt","r");  
    yyparse();  
    afficherTS(); // Afficher la table des séparateurs
    afficherTM(); // Afficher la table des mots clés
    afficher(); // Afficher la table des symboles

    afficher_qdr(); //Afficher les quadruplets

    Propagation_de_expression();
    elimination_expression_commune();

    afficher_qdr_opti();
    generateCodeObjet();

 
return 0;  
} 

