/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DUTOK_PROGRAM = 258,
     DUTOK_LABEL = 259,
     DUTOK_CONST = 260,
     DUTOK_TYPE = 261,
     DUTOK_VAR = 262,
     DUTOK_BEGIN = 263,
     DUTOK_END = 264,
     DUTOK_PROCEDURE = 265,
     DUTOK_FUNCTION = 266,
     DUTOK_ARRAY = 267,
     DUTOK_OF = 268,
     DUTOK_GOTO = 269,
     DUTOK_IF = 270,
     DUTOK_THEN = 271,
     DUTOK_ELSE = 272,
     DUTOK_WHILE = 273,
     DUTOK_DO = 274,
     DUTOK_REPEAT = 275,
     DUTOK_UNTIL = 276,
     DUTOK_FOR = 277,
     DUTOK_OR = 278,
     DUTOK_NOT = 279,
     DUTOK_RECORD = 280,
     DUTOK_IDENTIFIER = 281,
     DUTOK_UINT = 282,
     DUTOK_REAL = 283,
     DUTOK_STRING = 284,
     DUTOK_SEMICOLON = 285,
     DUTOK_DOT = 286,
     DUTOK_COMMA = 287,
     DUTOK_EQ = 288,
     DUTOK_COLON = 289,
     DUTOK_LPAR = 290,
     DUTOK_RPAR = 291,
     DUTOK_DOTDOT = 292,
     DUTOK_LSBRA = 293,
     DUTOK_RSBRA = 294,
     DUTOK_ASSIGN = 295,
     DUTOK_OPER_REL = 296,
     DUTOK_OPER_SIGNADD = 297,
     DUTOK_OPER_MUL = 298,
     DUTOK_FOR_DIRECTION = 299
   };
#endif
/* Tokens.  */
#define DUTOK_PROGRAM 258
#define DUTOK_LABEL 259
#define DUTOK_CONST 260
#define DUTOK_TYPE 261
#define DUTOK_VAR 262
#define DUTOK_BEGIN 263
#define DUTOK_END 264
#define DUTOK_PROCEDURE 265
#define DUTOK_FUNCTION 266
#define DUTOK_ARRAY 267
#define DUTOK_OF 268
#define DUTOK_GOTO 269
#define DUTOK_IF 270
#define DUTOK_THEN 271
#define DUTOK_ELSE 272
#define DUTOK_WHILE 273
#define DUTOK_DO 274
#define DUTOK_REPEAT 275
#define DUTOK_UNTIL 276
#define DUTOK_FOR 277
#define DUTOK_OR 278
#define DUTOK_NOT 279
#define DUTOK_RECORD 280
#define DUTOK_IDENTIFIER 281
#define DUTOK_UINT 282
#define DUTOK_REAL 283
#define DUTOK_STRING 284
#define DUTOK_SEMICOLON 285
#define DUTOK_DOT 286
#define DUTOK_COMMA 287
#define DUTOK_EQ 288
#define DUTOK_COLON 289
#define DUTOK_LPAR 290
#define DUTOK_RPAR 291
#define DUTOK_DOTDOT 292
#define DUTOK_LSBRA 293
#define DUTOK_RSBRA 294
#define DUTOK_ASSIGN 295
#define DUTOK_OPER_REL 296
#define DUTOK_OPER_SIGNADD 297
#define DUTOK_OPER_MUL 298
#define DUTOK_FOR_DIRECTION 299




/* Copy the first part of user declarations.  */
#line 1 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
  
  #include "du5.h"
  #include "du5lval.hpp"
  #include "duerr.h"
  #include "du5sem.h"
  #include "du5tok.h"

	/* Semantic value */
	#define YYSTYPE mlc::MlaskalLval

	/* Locations */
	#define YYLTYPE unsigned
	#define YYLLOC_DEFAULT(cur, rhs, n)	do { if(n) (cur)=(rhs)[1]; else (cur)=(rhs)[0]; } while(0)

	/* Local stuff */
	using namespace std;
	using namespace mlc;
	using namespace ai;
    
	/* Error stuff */
	#define YYERROR_VERBOSE 1
	static void yyerror(YYLTYPE *line, mlc::MlaskalCtx *ctx, const char *m);    


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 230 "du5g.cpp"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNRULES -- Number of states.  */
#define YYNSTATES  257

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    10,    13,    20,    22,    23,    27,
      31,    33,    35,    37,    38,    42,    46,    48,    52,    54,
      56,    58,    60,    62,    64,    66,    68,    71,    74,    76,
      77,    81,    85,    87,    91,    93,    95,    97,    99,   101,
     103,   105,   109,   113,   115,   117,   124,   128,   130,   132,
     134,   138,   140,   141,   144,   148,   150,   154,   158,   160,
     162,   163,   165,   166,   170,   174,   176,   180,   182,   184,
     186,   191,   195,   197,   201,   205,   207,   208,   211,   215,
     217,   219,   221,   225,   229,   233,   234,   238,   240,   242,
     244,   248,   253,   259,   263,   269,   271,   275,   279,   281,
     283,   285,   288,   291,   292,   294,   296,   298,   300,   302,
     304,   306,   308,   309,   313,   317,   321,   324,   326,   327,
     331,   335,   337,   339,   342,   349,   352,   356,   361,   364,
     372,   375,   377,   379,   381,   388,   393,   396,   399,   403,
     405,   407,   409,   412,   414,   415,   419,   421,   423,   425,
     429,   431,   433,   435,   437,   439,   441,   443,   447,   450
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    48,    30,    49,    31,    -1,
       3,    26,    -1,    50,    54,    63,    84,    92,   106,    -1,
      51,    -1,    -1,     4,    52,    30,    -1,    52,    32,    53,
      -1,    53,    -1,    27,    -1,    55,    -1,    -1,     5,    56,
      30,    -1,    56,    30,    57,    -1,    57,    -1,    26,    33,
      58,    -1,    59,    -1,    60,    -1,    26,    -1,    61,    -1,
      62,    -1,    27,    -1,    28,    -1,    29,    -1,    42,    27,
      -1,    42,    28,    -1,    64,    -1,    -1,     6,    65,    30,
      -1,    65,    30,    66,    -1,    66,    -1,    26,    33,    67,
      -1,    68,    -1,    69,    -1,    26,    -1,    70,    -1,    73,
      -1,    71,    -1,    72,    -1,    35,    82,    36,    -1,    58,
      37,    58,    -1,    74,    -1,    77,    -1,    12,    38,    75,
      39,    13,    67,    -1,    75,    32,    76,    -1,    76,    -1,
      26,    -1,    70,    -1,    25,    78,     9,    -1,    79,    -1,
      -1,    80,    83,    -1,    80,    30,    81,    -1,    81,    -1,
      82,    34,    67,    -1,    82,    32,    26,    -1,    26,    -1,
      30,    -1,    -1,    85,    -1,    -1,     7,    86,    30,    -1,
      86,    30,    87,    -1,    87,    -1,    82,    34,    67,    -1,
      26,    -1,    89,    -1,    91,    -1,    88,    38,    90,    39,
      -1,    90,    32,   131,    -1,   131,    -1,    91,    31,    26,
      -1,    26,    31,    26,    -1,    93,    -1,    -1,    94,    30,
      -1,    94,    30,    95,    -1,    95,    -1,    96,    -1,   104,
      -1,    97,    30,   103,    -1,    10,    26,    98,    -1,    35,
      99,    36,    -1,    -1,    99,    30,   100,    -1,   100,    -1,
     101,    -1,   102,    -1,    82,    34,    68,    -1,     7,    82,
      34,    68,    -1,    50,    54,    63,    84,   106,    -1,   105,
      30,   103,    -1,    11,    26,    98,    34,    68,    -1,   107,
      -1,     8,   108,     9,    -1,   108,    30,   109,    -1,   109,
      -1,   110,    -1,   126,    -1,   111,   112,    -1,    53,    34,
      -1,    -1,   113,    -1,   114,    -1,   119,    -1,   107,    -1,
     120,    -1,   121,    -1,   123,    -1,   124,    -1,    -1,    26,
      40,   131,    -1,    89,    40,   131,    -1,    91,    40,   131,
      -1,    26,   115,    -1,   116,    -1,    -1,    35,   117,    36,
      -1,   117,    32,   118,    -1,   118,    -1,   131,    -1,    14,
      53,    -1,    15,   131,    16,   110,    17,   110,    -1,   122,
     110,    -1,    18,   131,    19,    -1,    20,   108,    21,   131,
      -1,   125,   110,    -1,    22,    26,    40,   131,    44,   131,
      19,    -1,   111,   127,    -1,   128,    -1,   129,    -1,   130,
      -1,    15,   131,    16,   110,    17,   126,    -1,    15,   131,
      16,   109,    -1,   122,   126,    -1,   125,   126,    -1,   133,
     132,   133,    -1,   133,    -1,    41,    -1,    33,    -1,   134,
     135,    -1,    42,    -1,    -1,   135,   136,   137,    -1,   137,
      -1,    42,    -1,    23,    -1,   137,   138,   139,    -1,   139,
      -1,    43,    -1,    61,    -1,    26,    -1,    89,    -1,    91,
      -1,   140,    -1,    35,   131,    36,    -1,    24,   139,    -1,
      26,   116,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   170,   170,   176,   184,   192,   207,   208,   212,   216,
     217,   221,   231,   232,   236,   240,   241,   245,   255,   261,
     269,   277,   282,   290,   296,   302,   311,   317,   328,   329,
     333,   337,   338,   342,   352,   357,   365,   373,   377,   387,
     388,   392,   396,   402,   406,   416,   420,   421,   425,   426,
     432,   440,   446,   453,   461,   467,   475,   484,   492,   503,
     504,   510,   511,   515,   519,   520,   524,   534,   538,   542,
     549,   557,   558,   563,   568,   579,   580,   584,   588,   589,
     593,   594,   600,   609,   621,   627,   634,   640,   648,   653,
     661,   672,   683,   697,   707,   728,   736,   744,   750,   760,
     765,   775,   783,   784,   788,   793,   798,   802,   807,   812,
     817,   822,   828,   836,   842,   848,   859,   868,   874,   880,
     888,   895,   905,   915,   924,   933,   940,   946,   955,   962,
     968,   976,   981,   986,   996,  1000,  1009,  1018,  1027,  1028,
    1036,  1041,  1051,  1075,  1081,  1088,  1121,  1129,  1134,  1144,
    1189,  1197,  1207,  1218,  1294,  1314,  1334,  1339,  1344,  1351
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DUTOK_PROGRAM", "DUTOK_LABEL",
  "DUTOK_CONST", "DUTOK_TYPE", "DUTOK_VAR", "DUTOK_BEGIN", "DUTOK_END",
  "DUTOK_PROCEDURE", "DUTOK_FUNCTION", "DUTOK_ARRAY", "DUTOK_OF",
  "DUTOK_GOTO", "DUTOK_IF", "DUTOK_THEN", "DUTOK_ELSE", "DUTOK_WHILE",
  "DUTOK_DO", "DUTOK_REPEAT", "DUTOK_UNTIL", "DUTOK_FOR", "DUTOK_OR",
  "DUTOK_NOT", "DUTOK_RECORD", "DUTOK_IDENTIFIER", "DUTOK_UINT",
  "DUTOK_REAL", "DUTOK_STRING", "DUTOK_SEMICOLON", "DUTOK_DOT",
  "DUTOK_COMMA", "DUTOK_EQ", "DUTOK_COLON", "DUTOK_LPAR", "DUTOK_RPAR",
  "DUTOK_DOTDOT", "DUTOK_LSBRA", "DUTOK_RSBRA", "DUTOK_ASSIGN",
  "DUTOK_OPER_REL", "DUTOK_OPER_SIGNADD", "DUTOK_OPER_MUL",
  "DUTOK_FOR_DIRECTION", "$accept", "mlaskal", "program", "program_header",
  "program_block", "optional_label_declaration_section",
  "label_declaration_section", "label_list", "label_denoter",
  "optional_constant_definition_section", "constant_definition_section",
  "constant_definition_list", "constant_definition", "constant_denoter",
  "existing_constant", "new_constant", "new_signless_constant",
  "new_signful_constant", "optional_type_definition_section",
  "type_definition_section", "type_definition_list", "type_definition",
  "type_denoter", "existing_type", "new_type", "new_ordinal_type",
  "new_enumerated_type", "new_subrange_type", "new_structured_type",
  "new_array_type", "index_list", "ordinal_type_denoter",
  "new_record_type", "optional_field_specification", "field_specification",
  "field_group_definition_list", "field_group_definition",
  "identifier_list", "optional_semicolon",
  "optional_variable_definition_section", "variable_definition_section",
  "variable_group_definition_list", "variable_group_definition",
  "variable_access", "array_variable", "expression_list",
  "record_variable", "optional_subprogram_definition_section",
  "subprogram_definition_section", "subprogram_definition_list",
  "subprogram_definition", "procedure_definition", "procedure_header",
  "optional_formal_parameter_specification", "formal_parameter_group_list",
  "formal_parameter_group", "formal_parameter_group_passed_by_value",
  "formal_parameter_group_passed_by_reference", "subprogram_block",
  "function_definition", "function_header", "statement_section",
  "compound_statement", "statement_sequence", "statement",
  "matched_statement", "optional_label", "unlabeled_matched_statement",
  "assignment_statement", "procedure_call_statement",
  "optional_actual_parameter_specification",
  "actual_parameter_specification", "actual_parameter_list",
  "actual_parameter", "goto_statement", "matched_if_statement",
  "matched_while_statement", "while_header", "repeat_statement",
  "matched_for_statement", "for_header", "unmatched_statement",
  "unlabeled_unmatched_statement", "unmatched_if_statement",
  "unmatched_while_statement", "unmatched_for_statement", "expression",
  "relational_operator", "simple_expression", "optional_sign",
  "signless_simple_expression", "additive_operator", "term",
  "multiplicative_operator", "factor", "function_call", 0
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
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    48,    49,    50,    50,    51,    52,
      52,    53,    54,    54,    55,    56,    56,    57,    58,    58,
      59,    60,    60,    61,    61,    61,    62,    62,    63,    63,
      64,    65,    65,    66,    67,    67,    68,    69,    69,    70,
      70,    71,    72,    73,    73,    74,    75,    75,    76,    76,
      77,    78,    78,    79,    80,    80,    81,    82,    82,    83,
      83,    84,    84,    85,    86,    86,    87,    88,    88,    88,
      89,    90,    90,    91,    91,    92,    92,    93,    94,    94,
      95,    95,    96,    97,    98,    98,    99,    99,   100,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   108,   109,
     109,   110,   111,   111,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   113,   113,   113,   114,   115,   115,   116,
     117,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   127,   127,   128,   128,   129,   130,   131,   131,
     132,   132,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   139,   139,   139,   139,   139,   139,   139,   140
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     2,     6,     1,     0,     3,     3,
       1,     1,     1,     0,     3,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     0,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     6,     3,     1,     1,     1,
       3,     1,     0,     2,     3,     1,     3,     3,     1,     1,
       0,     1,     0,     3,     3,     1,     3,     1,     1,     1,
       4,     3,     1,     3,     3,     1,     0,     2,     3,     1,
       1,     1,     3,     3,     3,     0,     3,     1,     1,     1,
       3,     4,     5,     3,     5,     1,     3,     3,     1,     1,
       1,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     3,     3,     2,     1,     0,     3,
       3,     1,     1,     2,     6,     2,     3,     4,     2,     7,
       2,     1,     1,     1,     6,     4,     2,     2,     3,     1,
       1,     1,     2,     1,     0,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     4,     1,     7,     0,     0,
      13,     6,    11,     0,    10,     3,     0,    29,    12,     8,
       0,     0,     0,    16,     0,    62,    28,     9,     0,    14,
       0,     0,    32,     0,    76,    61,    20,    23,    24,    25,
       0,    17,    18,    19,    21,    22,    15,     0,    30,    58,
       0,     0,    65,     0,     0,     0,    75,     0,    79,    80,
       0,    81,     0,    26,    27,     0,    52,    36,     0,     0,
      33,    34,    35,    37,    39,    40,    38,    43,    44,    31,
       0,     0,    63,    85,    85,   103,     5,    95,    77,     7,
       7,     0,     0,    51,    60,    55,     0,     0,     0,    57,
      66,    64,     0,    83,     0,     0,     0,    98,    99,   112,
     100,    78,    13,    82,    93,    48,    49,     0,    47,    50,
      59,    53,     0,    41,    42,     0,     0,     0,    87,    88,
      89,     0,   102,    96,   103,     0,   144,   144,   103,     0,
     118,     0,    68,    69,   107,   101,   104,   105,   106,   108,
     109,   103,   110,   111,   103,   130,   131,   132,   133,    29,
       0,     0,    54,    56,     0,     0,     0,    84,    36,    94,
      97,   123,   143,     0,   139,     0,     0,     0,     0,     0,
     144,   144,   116,   117,   144,   144,     0,   144,   125,   136,
     128,   137,    62,    46,     0,     0,    90,    86,   103,   141,
     140,   144,     0,   153,   144,   152,   154,   155,   142,   146,
     150,   156,   126,   144,   144,    74,     0,   121,   122,   113,
       0,    72,   114,    73,   115,     0,    45,    91,   135,    99,
     138,   158,   159,     0,   148,   147,     0,   151,     0,   127,
       0,   144,   119,   144,    70,    92,   103,   157,   145,   149,
     144,   120,    71,   124,   134,     0,   129
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     9,   112,    11,    13,   105,    17,
      18,    22,    23,    69,    42,    43,    44,    45,    25,    26,
      31,    32,    70,    71,    72,    73,    74,    75,    76,    77,
     117,   118,    78,    92,    93,    94,    95,    50,   121,    34,
      35,    51,    52,   141,   206,   220,   207,    55,    56,    57,
      58,    59,    60,   103,   127,   128,   129,   130,   113,    61,
      62,    86,    87,   106,   107,   108,   109,   145,   146,   147,
     182,   183,   216,   217,   148,   149,   150,   151,   152,   153,
     154,   110,   155,   156,   157,   158,   218,   201,   174,   175,
     208,   236,   209,   238,   210,   211
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -188
static const yytype_int16 yypact[] =
{
      25,    19,    74,  -188,    88,  -188,  -188,   116,    96,    64,
     119,  -188,  -188,     1,  -188,  -188,   102,   124,  -188,  -188,
      96,   100,   104,  -188,   106,   128,  -188,  -188,    38,   102,
     103,   107,  -188,   112,    45,  -188,  -188,  -188,  -188,  -188,
      43,  -188,  -188,  -188,  -188,  -188,  -188,    63,   106,  -188,
      53,   109,  -188,   114,   115,   134,  -188,   113,  -188,  -188,
     117,  -188,   118,  -188,  -188,   108,   112,   120,   112,   121,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
     123,    63,   112,   110,   110,    96,  -188,  -188,    45,   116,
     116,    -3,   135,  -188,   122,  -188,    62,    40,    38,  -188,
    -188,  -188,    10,  -188,   125,   126,     7,  -188,  -188,    99,
    -188,  -188,   119,  -188,  -188,   120,  -188,     2,  -188,  -188,
     112,  -188,    63,  -188,  -188,   112,    77,    17,  -188,  -188,
    -188,   127,  -188,  -188,    96,    96,   129,   129,    96,   130,
      91,   131,   111,   -13,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,    96,  -188,  -188,    96,  -188,  -188,  -188,  -188,   124,
      -3,   137,  -188,  -188,    78,   127,    10,  -188,  -188,  -188,
    -188,  -188,  -188,   138,   -11,    33,   136,    -1,   132,   139,
     129,   129,  -188,  -188,   129,   129,   140,   129,  -188,  -188,
    -188,  -188,   128,  -188,    63,   127,  -188,  -188,    96,  -188,
    -188,   129,    33,    68,   129,  -188,   141,     4,    -4,   133,
    -188,  -188,  -188,   129,   129,  -188,    65,  -188,  -188,  -188,
      54,  -188,  -188,  -188,  -188,   134,  -188,  -188,  -188,   144,
    -188,  -188,  -188,   142,  -188,  -188,    33,  -188,    33,  -188,
     143,   129,  -188,   129,  -188,  -188,    96,  -188,   133,  -188,
     129,  -188,  -188,  -188,  -188,   145,  -188
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,  -188,  -188,  -188,  -188,   155,  -188,  -188,    -8,    51,
    -188,  -188,   146,   -17,  -188,  -188,  -154,  -188,     8,  -188,
    -188,   147,   -78,  -122,  -188,   -77,  -188,  -188,  -188,  -188,
    -188,    13,  -188,  -188,  -188,  -188,    48,   -62,  -188,   -22,
    -188,  -188,    92,  -188,    71,  -188,    72,  -188,  -188,  -188,
      89,  -188,  -188,    98,  -188,    18,  -188,  -188,    93,  -188,
    -188,   -40,    79,    52,  -121,  -144,  -188,  -188,  -188,  -188,
    -188,   -14,  -188,   -55,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -146,  -188,  -188,  -188,  -188,  -135,  -188,   -10,  -188,
    -188,  -188,   -44,  -188,  -187,  -188
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -70
static const yytype_int16 yytable[] =
{
      14,   173,   176,   100,    96,   189,    97,   188,   191,   169,
     190,    41,    27,   170,   116,   231,   133,   125,   186,   234,
     213,   205,   199,   115,    37,    38,    39,   187,     1,   134,
     200,    19,    68,    20,   160,   186,    49,   134,   235,    40,
     126,   161,   -69,   196,   163,     5,   219,   166,   205,   221,
     222,   249,   224,   167,   229,    53,    54,   202,    96,   203,
      37,    38,    39,   164,    36,    37,    38,    39,   204,   233,
      63,    64,    80,   227,     6,    65,   123,   228,   239,   240,
      40,   124,   205,   116,   205,    80,   243,    81,    66,    67,
      37,    38,    39,   244,    80,    15,   122,   241,    68,   179,
     254,   242,   253,   180,   126,    40,   -67,    85,   252,    80,
      80,   165,   195,   135,   136,   255,   226,   137,     7,   138,
       8,   139,   179,    12,    16,   140,   180,   171,    21,   -67,
      24,   181,    30,    28,    29,    33,    47,    48,    49,    82,
      83,    84,    85,    88,   119,   102,    91,    89,    90,    99,
     194,   185,   120,   168,   198,   212,   178,   -20,    98,   131,
     132,   246,    10,   159,   256,   215,   223,   192,   162,   184,
     225,   172,   214,   193,   101,    46,   237,   111,   247,   -68,
     142,   143,   104,   114,   197,   245,   251,   250,   144,   232,
     177,   230,   248,     0,     0,    79
};

static const yytype_int16 yycheck[] =
{
       8,   136,   137,    81,    66,   151,    68,   151,   154,   131,
     154,    28,    20,   134,    91,   202,     9,     7,    31,    23,
      21,   175,    33,    26,    27,    28,    29,    40,     3,    30,
      41,    30,    35,    32,    32,    31,    26,    30,    42,    42,
     102,    39,    38,   165,   122,    26,   181,    30,   202,   184,
     185,   238,   187,    36,   198,    10,    11,    24,   120,    26,
      27,    28,    29,   125,    26,    27,    28,    29,    35,   204,
      27,    28,    32,   195,     0,    12,    36,   198,   213,   214,
      42,    98,   236,   160,   238,    32,    32,    34,    25,    26,
      27,    28,    29,    39,    32,    31,    34,    32,    35,    31,
     246,    36,   246,    35,   166,    42,    38,     8,   243,    32,
      32,    34,    34,    14,    15,   250,   194,    18,    30,    20,
       4,    22,    31,    27,     5,    26,    35,   135,    26,    38,
       6,    40,    26,    33,    30,     7,    33,    30,    26,    30,
      26,    26,     8,    30,     9,    35,    38,    30,    30,    26,
      13,    40,    30,    26,    16,    19,    26,    37,    37,    34,
      34,    17,     7,   112,    19,    26,    26,   159,   120,    38,
     192,    42,    40,   160,    82,    29,    43,    88,    36,    38,
     109,   109,    84,    90,   166,   225,   241,    44,   109,   203,
     138,   201,   236,    -1,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    46,    47,    48,    26,     0,    30,     4,    49,
      50,    51,    27,    52,    53,    31,     5,    54,    55,    30,
      32,    26,    56,    57,     6,    63,    64,    53,    33,    30,
      26,    65,    66,     7,    84,    85,    26,    27,    28,    29,
      42,    58,    59,    60,    61,    62,    57,    33,    30,    26,
      82,    86,    87,    10,    11,    92,    93,    94,    95,    96,
      97,   104,   105,    27,    28,    12,    25,    26,    35,    58,
      67,    68,    69,    70,    71,    72,    73,    74,    77,    66,
      32,    34,    30,    26,    26,     8,   106,   107,    30,    30,
      30,    38,    78,    79,    80,    81,    82,    82,    37,    26,
      67,    87,    35,    98,    98,    53,   108,   109,   110,   111,
     126,    95,    50,   103,   103,    26,    70,    75,    76,     9,
      30,    83,    34,    36,    58,     7,    82,    99,   100,   101,
     102,    34,    34,     9,    30,    14,    15,    18,    20,    22,
      26,    88,    89,    91,   107,   112,   113,   114,   119,   120,
     121,   122,   123,   124,   125,   127,   128,   129,   130,    54,
      32,    39,    81,    67,    82,    34,    30,    36,    26,    68,
     109,    53,    42,   131,   133,   134,   131,   108,    26,    31,
      35,    40,   115,   116,    38,    40,    31,    40,   110,   126,
     110,   126,    63,    76,    13,    34,    68,   100,    16,    33,
      41,   132,    24,    26,    35,    61,    89,    91,   135,   137,
     139,   140,    19,    21,    40,    26,   117,   118,   131,   131,
      90,   131,   131,    26,   131,    84,    67,    68,   109,   110,
     133,   139,   116,   131,    23,    42,   136,    43,   138,   131,
     131,    32,    36,    32,    39,   106,    17,    36,   137,   139,
      44,   118,   131,   110,   126,   131,    19
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
      yyerror (&yylloc, ctx, YY_("syntax error: cannot back up")); \
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
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, ctx)
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
		  Type, Value, Location, ctx); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, mlc::MlaskalCtx *ctx)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, ctx)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    mlc::MlaskalCtx *ctx;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (ctx);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, mlc::MlaskalCtx *ctx)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, ctx)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    mlc::MlaskalCtx *ctx;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, ctx);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, mlc::MlaskalCtx *ctx)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, ctx)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    mlc::MlaskalCtx *ctx;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , ctx);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, ctx); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, mlc::MlaskalCtx *ctx)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, ctx)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    mlc::MlaskalCtx *ctx;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (ctx);

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
int yyparse (mlc::MlaskalCtx *ctx);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

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
yyparse (mlc::MlaskalCtx *ctx)
#else
int
yyparse (ctx)
    mlc::MlaskalCtx *ctx;
#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 177 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA, ICG
	  ctx->tab->set_main_code((yyvsp[(1) - (4)].id_ci_), (yyvsp[(3) - (4)].icblockPointer));
  ;}
    break;

  case 4:
#line 185 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA
	  (yyval.id_ci_) = (yyvsp[(2) - (2)].id_ci_);
  ;}
    break;

  case 5:
#line 198 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA
	  (yyval.icblockPointer) = (yyvsp[(6) - (6)].icblockPointer);
  ;}
    break;

  case 11:
#line 222 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		lukas::AddLabel(ctx, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].int_ci_));
	;}
    break;

  case 17:
#line 246 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA 
		lukas::AddConstant(ctx, (yylsp[(1) - (3)]), (yyvsp[(1) - (3)].id_ci_) , (yyvsp[(3) - (3)].constant));
	;}
    break;

  case 18:
#line 256 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.constant) = lukas::FindConstant(ctx, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id_ci_));
		
	;}
    break;

  case 19:
#line 262 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA (default)
		(yyval.constant) = (yyvsp[(1) - (1)].constant);
	;}
    break;

  case 20:
#line 270 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA (default)
		(yyval.id_ci_) = (yyvsp[(1) - (1)].id_ci_); 
	;}
    break;

  case 21:
#line 278 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA (default)
		(yyval.constant) = (yyvsp[(1) - (1)].constant);
	;}
    break;

  case 22:
#line 283 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA (default)
		(yyval.constant) = (yyvsp[(1) - (1)].constant);
	;}
    break;

  case 23:
#line 291 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.constant).typePointer = ctx->tab->logical_integer();
		(yyval.constant).integerValue = (yyvsp[(1) - (1)].int_ci_);
	;}
    break;

  case 24:
#line 297 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.constant).typePointer = ctx->tab->logical_real();
		(yyval.constant).realValue = (yyvsp[(1) - (1)].real_ci_);
	;}
    break;

  case 25:
#line 303 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.constant).typePointer = ctx->tab->logical_string();
		(yyval.constant).stringValue = (yyvsp[(1) - (1)].str_ci_);
	;}
    break;

  case 26:
#line 312 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.constant).typePointer = ctx->tab->logical_integer();
		(yyval.constant).integerValue = ((yyvsp[(1) - (2)].dtge_) == DUTOKGE_MINUS) ? ctx->tab->ls_int().add((-1) * (*(yyvsp[(2) - (2)].int_ci_))) : (yyvsp[(2) - (2)].int_ci_); 
	;}
    break;

  case 27:
#line 318 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.constant).typePointer = ctx->tab->logical_real();
		(yyval.constant).realValue = ((yyvsp[(1) - (2)].dtge_) == DUTOKGE_MINUS) ? ctx->tab->ls_real().add((-1) * (*(yyvsp[(2) - (2)].real_ci_))) : (yyvsp[(2) - (2)].real_ci_);
	;}
    break;

  case 33:
#line 343 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		lukas::AddType(ctx, (yylsp[(1) - (3)]), (yyvsp[(1) - (3)].id_ci_), (yyvsp[(3) - (3)].typePointer));
	;}
    break;

  case 34:
#line 353 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.typePointer) = lukas::FindType(ctx, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id_ci_));
	;}
    break;

  case 35:
#line 358 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA (default)
		(yyval.typePointer) = (yyvsp[(1) - (1)].typePointer);
	;}
    break;

  case 36:
#line 366 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA (default)
		(yyval.id_ci_) = (yyvsp[(1) - (1)].id_ci_);
	;}
    break;

  case 37:
#line 374 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
	;}
    break;

  case 38:
#line 378 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA (default)
		(yyval.typePointer) = (yyvsp[(1) - (1)].typePointer);
	;}
    break;

  case 43:
#line 403 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
	;}
    break;

  case 44:
#line 407 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA (default)
		(yyval.typePointer) = (yyvsp[(1) - (1)].typePointer);
	;}
    break;

  case 50:
#line 433 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.typePointer) = ctx->tab->create_record_type((yyvsp[(2) - (3)].fieldList), (yylsp[(1) - (3)]));
	;}
    break;

  case 51:
#line 441 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	 	// SA (default)
	  (yyval.fieldList) = (yyvsp[(1) - (1)].fieldList);
	;}
    break;

  case 52:
#line 446 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.fieldList) = create_field_list();
	;}
    break;

  case 53:
#line 454 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA
    (yyval.fieldList) = (yyvsp[(1) - (2)].fieldList);
  ;}
    break;

  case 54:
#line 462 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.fieldList) = (yyvsp[(1) - (3)].fieldList);
		(yyval.fieldList)->append_and_kill((yyvsp[(3) - (3)].fieldList));
	;}
    break;

  case 55:
#line 468 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA (default)
		(yyval.fieldList) = (yyvsp[(1) - (1)].fieldList);
	;}
    break;

  case 56:
#line 476 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.fieldList) = create_field_list();
		lukas::AppendFieldGroup((yyval.fieldList), (yyvsp[(1) - (3)].identifierList), (yyvsp[(3) - (3)].typePointer));
	;}
    break;

  case 57:
#line 485 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.identifierList) = (yyvsp[(1) - (3)].identifierList);
		
		lukas::linenumber_identifier_pair linenumberIdentifierPair((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].id_ci_)); 
		(yyval.identifierList).push_back(linenumberIdentifierPair);
	;}
    break;

  case 58:
#line 493 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.identifierList) = lukas::identifier_list();
		
		lukas::linenumber_identifier_pair linenumberIdentifierPair((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id_ci_));
		(yyval.identifierList).push_back(linenumberIdentifierPair); 
	;}
    break;

  case 66:
#line 525 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		lukas::AddVariableGroup(ctx, (yyvsp[(1) - (3)].identifierList), (yyvsp[(3) - (3)].typePointer));
	;}
    break;

  case 67:
#line 535 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA (empty)
  ;}
    break;

  case 68:
#line 539 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
  ;}
    break;

  case 69:
#line 543 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
  ;}
    break;

  case 70:
#line 550 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // TODO
    (yyval.variable) = lukas::Variable(SKIND_LOCAL_VARIABLE, ctx->tab->logical_undef(), 0);
  ;}
    break;

  case 73:
#line 564 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA
    (yyval.variable) = lukas::FindField(ctx, (yyvsp[(1) - (3)].variable), (yylsp[(3) - (3)]), (yyvsp[(3) - (3)].id_ci_));
  ;}
    break;

  case 74:
#line 569 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA
    lukas::Variable recordVariable = lukas::FindVariable(ctx, (yylsp[(1) - (3)]), (yyvsp[(1) - (3)].id_ci_));
    (yyval.variable) = lukas::FindField(ctx, recordVariable, (yylsp[(3) - (3)]), (yyvsp[(3) - (3)].id_ci_));
  ;}
    break;

  case 82:
#line 601 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA, ICG
		ctx->tab->set_subprogram_code((yyvsp[(1) - (3)].id_ci_), (yyvsp[(3) - (3)].icblockPointer));
		ctx->tab->leave((yylsp[(3) - (3)]));
	;}
    break;

  case 83:
#line 610 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
    // Pass the procedure identifier to the procedure definition.
		(yyval.id_ci_) = (yyvsp[(2) - (3)].id_ci_);
		
		ctx->tab->add_proc((yylsp[(2) - (3)]), (yyvsp[(2) - (3)].id_ci_), (yyvsp[(3) - (3)].formalParameterList));
		ctx->tab->enter((yylsp[(2) - (3)]), (yyvsp[(2) - (3)].id_ci_));
	;}
    break;

  case 84:
#line 622 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.formalParameterList) = (yyvsp[(2) - (3)].formalParameterList)
	;}
    break;

  case 85:
#line 627 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.formalParameterList) = create_parameter_list();
	;}
    break;

  case 86:
#line 635 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.formalParameterList) = (yyvsp[(1) - (3)].formalParameterList); 
		(yyval.formalParameterList)->append_and_kill((yyvsp[(3) - (3)].formalParameterList));
	;}
    break;

  case 87:
#line 641 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA (default)
		(yyval.formalParameterList) = (yyvsp[(1) - (1)].formalParameterList);
	;}
    break;

  case 88:
#line 649 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA (default)
		(yyval.formalParameterList) = (yyvsp[(1) - (1)].formalParameterList);
	;}
    break;

  case 89:
#line 654 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA (default)
		(yyval.formalParameterList) = (yyvsp[(1) - (1)].formalParameterList);
	;}
    break;

  case 90:
#line 662 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.formalParameterList) = create_parameter_list();
		
		// `true' as the second actual parameter specifies appending by value.
		lukas::AppendFormalParameterGroup(ctx, (yyval.formalParameterList), true, (yyvsp[(1) - (3)].identifierList), (yylsp[(3) - (3)]), (yyvsp[(3) - (3)].id_ci_));
	;}
    break;

  case 91:
#line 673 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA
		(yyval.formalParameterList) = create_parameter_list();
		
		// `false' as the second actual parameter specifies appending by reference.
		lukas::AppendFormalParameterGroup(ctx, (yyval.formalParameterList), false, (yyvsp[(2) - (4)].identifierList), (yylsp[(4) - (4)]), (yyvsp[(4) - (4)].id_ci_));
	;}
    break;

  case 92:
#line 688 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA
	  (yyval.icblockPointer) = (yyvsp[(5) - (5)].icblockPointer);
  ;}
    break;

  case 93:
#line 698 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
		// SA, ICG
		lukas::AppendSTInstruction((yyvsp[(3) - (3)].icblockPointer), SKIND_LOCAL_VARIABLE, (yyvsp[(1) - (3)].functionHeader).functionReturnTypePointer->cat(), ctx->tab->my_return_address());
		ctx->tab->set_subprogram_code((yyvsp[(1) - (3)].functionHeader).functionIdentifier, (yyvsp[(3) - (3)].icblockPointer));
		ctx->tab->leave((yylsp[(3) - (3)]));
	;}
    break;

  case 94:
#line 708 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // Ensure the function return type is scalar.
    type_pointer functionReturnTypePointer = lukas::FindType(ctx, (yylsp[(5) - (5)]), (yyvsp[(5) - (5)].id_ci_));
    if (!lukas::IsScalarType(functionReturnTypePointer->cat()))
    {
      // Error (The function return type is not scalar.)
      error(DUERR_NOTSCALAR, (yylsp[(5) - (5)]), (yyvsp[(5) - (5)].id_ci_)->c_str());
    }

    // Pass the function header to the function definition.
    (yyval.functionHeader) = lukas::FunctionHeader((yyvsp[(2) - (5)].id_ci_), functionReturnTypePointer);

		ctx->tab->add_fnc((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].id_ci_), functionReturnTypePointer, (yyvsp[(3) - (5)].formalParameterList));
		ctx->tab->enter((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].id_ci_));	
	;}
    break;

  case 95:
#line 729 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA (default)
	  (yyval.icblockPointer) = (yyvsp[(1) - (1)].icblockPointer);
  ;}
    break;

  case 96:
#line 737 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.icblockPointer) = (yyvsp[(2) - (3)].icblockPointer);
  ;}
    break;

  case 97:
#line 745 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA
	  (yyval.icblockPointer) = (yyvsp[(1) - (3)].icblockPointer);
	  icblock_append_delete((yyval.icblockPointer), (yyvsp[(3) - (3)].icblockPointer));
  ;}
    break;

  case 98:
#line 751 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.icblockPointer) = (yyvsp[(1) - (1)].icblockPointer);
  ;}
    break;

  case 99:
#line 761 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA (default)
	  (yyval.icblockPointer) = (yyvsp[(1) - (1)].icblockPointer);
  ;}
    break;

  case 100:
#line 766 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.icblockPointer) = (yyvsp[(1) - (1)].icblockPointer);
  ;}
    break;

  case 101:
#line 776 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA
	  (yyval.icblockPointer) = (yyvsp[(2) - (2)].icblockPointer);
  ;}
    break;

  case 104:
#line 789 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA (default)
	  (yyval.icblockPointer) = (yyvsp[(1) - (1)].icblockPointer);
  ;}
    break;

  case 105:
#line 794 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.icblockPointer) = (yyvsp[(1) - (1)].icblockPointer);
  ;}
    break;

  case 106:
#line 799 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
  ;}
    break;

  case 107:
#line 803 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.icblockPointer) = (yyvsp[(1) - (1)].icblockPointer);
  ;}
    break;

  case 108:
#line 808 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.icblockPointer) = (yyvsp[(1) - (1)].icblockPointer);
  ;}
    break;

  case 109:
#line 813 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.icblockPointer) = (yyvsp[(1) - (1)].icblockPointer);
  ;}
    break;

  case 110:
#line 818 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.icblockPointer) = (yyvsp[(1) - (1)].icblockPointer);
  ;}
    break;

  case 111:
#line 823 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.icblockPointer) = (yyvsp[(1) - (1)].icblockPointer);
  ;}
    break;

  case 112:
#line 828 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    (yyval.icblockPointer) = icblock_create();
  ;}
    break;

  case 113:
#line 837 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA
    (yyval.icblockPointer) = icblock_create();
    lukas::AppendAssignmentStatementICBlock(ctx, (yyloc), (yyval.icblockPointer), (yyvsp[(1) - (3)].id_ci_), (yyvsp[(3) - (3)].typedICBlock));
  ;}
    break;

  case 114:
#line 843 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA
    (yyval.icblockPointer) = icblock_create();
    lukas::AppendVariableAssignmentStatementICBlock((yyloc), (yyval.icblockPointer), (yyvsp[(1) - (3)].variable), (yyvsp[(3) - (3)].typedICBlock));
  ;}
    break;

  case 115:
#line 849 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA
    (yyval.icblockPointer) = icblock_create();
    lukas::AppendVariableAssignmentStatementICBlock((yyloc), (yyval.icblockPointer), (yyvsp[(1) - (3)].variable), (yyvsp[(3) - (3)].typedICBlock));
  ;}
    break;

  case 116:
#line 860 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA, ICG
    (yyval.icblockPointer) = icblock_create();
    lukas::AppendProcedureCallStatementICBlock(ctx, (yylsp[(1) - (2)]), (yyval.icblockPointer), (yyvsp[(1) - (2)].id_ci_), (yyvsp[(2) - (2)].actualParameterList));
  ;}
    break;

  case 117:
#line 869 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
	  (yyval.actualParameterList) = (yyvsp[(1) - (1)].actualParameterList);
  ;}
    break;

  case 118:
#line 874 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    (yyval.actualParameterList) = lukas::actual_parameter_list();
  ;}
    break;

  case 119:
#line 881 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA
    (yyval.actualParameterList) = (yyvsp[(2) - (3)].actualParameterList);
  ;}
    break;

  case 120:
#line 889 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA
	  (yyval.actualParameterList) = (yyvsp[(1) - (3)].actualParameterList);
	  
	  (yyval.actualParameterList).push_back((yyvsp[(3) - (3)].typedICBlock));
  ;}
    break;

  case 121:
#line 896 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA
    (yyval.actualParameterList) = lukas::actual_parameter_list();
    
    (yyval.actualParameterList).push_back((yyvsp[(1) - (1)].typedICBlock));
  ;}
    break;

  case 122:
#line 906 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA (default)
    (yyval.typedICBlock) = (yyvsp[(1) - (1)].typedICBlock);  
  ;}
    break;

  case 123:
#line 916 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
  ;}
    break;

  case 124:
#line 925 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
  ;}
    break;

  case 125:
#line 934 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
  ;}
    break;

  case 127:
#line 947 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
  ;}
    break;

  case 128:
#line 956 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
  ;}
    break;

  case 130:
#line 969 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA
	  (yyval.icblockPointer) = (yyvsp[(2) - (2)].icblockPointer);
  ;}
    break;

  case 131:
#line 977 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.icblockPointer) = (yyvsp[(1) - (1)].icblockPointer);
  ;}
    break;

  case 132:
#line 982 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.icblockPointer) = (yyvsp[(1) - (1)].icblockPointer);
  ;}
    break;

  case 133:
#line 987 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.icblockPointer) = (yyvsp[(1) - (1)].icblockPointer);
  ;}
    break;

  case 134:
#line 997 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
  ;}
    break;

  case 135:
#line 1001 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
  ;}
    break;

  case 136:
#line 1010 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
  ;}
    break;

  case 137:
#line 1019 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
  ;}
    break;

  case 139:
#line 1029 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.typedICBlock) = (yyvsp[(1) - (1)].typedICBlock);
  ;}
    break;

  case 140:
#line 1037 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.dtge_) = (yyvsp[(1) - (1)].dtge_);
  ;}
    break;

  case 141:
#line 1042 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.dtge_) = (yyvsp[(1) - (1)].dtge_);
  ;}
    break;

  case 142:
#line 1052 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA, ICG
    (yyval.typedICBlock).icblockPointer = icblock_create();

    // Depending on the operator ...
    switch ((yyvsp[(1) - (2)].dtge_))
    {
      case DUTOKGE_MINUS :
      {
        // ... append a (unary) minus operation.
        lukas::AppendMinusOperationTypedICBlock(ctx, (yyloc), (yyval.typedICBlock), (yyvsp[(2) - (2)].typedICBlock));
      }
      break;
      default :
      {
        (yyval.typedICBlock) = (yyvsp[(2) - (2)].typedICBlock);
      }
      break;
    }
  ;}
    break;

  case 143:
#line 1076 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.dtge_) = (yyvsp[(1) - (1)].dtge_);
  ;}
    break;

  case 144:
#line 1081 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA
    (yyval.dtge_) = -1;
  ;}
    break;

  case 145:
#line 1089 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA, ICG
    (yyval.typedICBlock).icblockPointer = icblock_create();

    // Depending on the opeartor ...
    switch ((yyvsp[(2) - (3)].dtge_))
    {
      case DUTOKGE_PLUS :
      {
        // ... append an addition operation.
        lukas::AppendAdditionOperationTypedICBlock(ctx, (yyloc), (yyval.typedICBlock), (yyvsp[(1) - (3)].typedICBlock), (yyvsp[(3) - (3)].typedICBlock));
      }
      break;
      case DUTOKGE_MINUS :
      {
        // ... append a subtraction operation.
        lukas::AppendSubtractionOperationTypedICBlock(ctx, (yyloc), (yyval.typedICBlock), (yyvsp[(1) - (3)].typedICBlock), (yyvsp[(3) - (3)].typedICBlock));
      }
      break;
      case DUTOK_OR :
      {
        // ... append a disjunction operation.
        lukas::AppendDisjunctionOperationTypedICBlock(ctx, (yyloc), (yyval.typedICBlock), (yyvsp[(1) - (3)].typedICBlock), (yyvsp[(3) - (3)].typedICBlock));
      }
      break;
      default:
      {
        // Error (Unsupported operator.)
      }
      break;
    }
  ;}
    break;

  case 146:
#line 1122 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {                                        
    // SA (default)
    (yyval.typedICBlock) = (yyvsp[(1) - (1)].typedICBlock);
  ;}
    break;

  case 147:
#line 1130 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.dtge_) = (yyvsp[(1) - (1)].dtge_);
  ;}
    break;

  case 148:
#line 1135 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.dtge_) = (yyvsp[(1) - (1)].dtge_);
  ;}
    break;

  case 149:
#line 1145 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA, ICG
    (yyval.typedICBlock).icblockPointer = icblock_create();

    // Depending on the operator ...
    switch ((yyvsp[(2) - (3)].dtge_))
    {
      case DUTOKGE_ASTERISK :
      {
        // ... append a multiplication operation.
        lukas::AppendMultiplicationOperationTypedICBlock(ctx, (yyloc), (yyval.typedICBlock), (yyvsp[(1) - (3)].typedICBlock), (yyvsp[(3) - (3)].typedICBlock));
      }
      break;
      case DUTOKGE_SOLIDUS :
      {
        // ... append a (real) division operation.
        lukas::AppendRealDivisionOperationTypedICBlock(ctx, (yyloc), (yyval.typedICBlock), (yyvsp[(1) - (3)].typedICBlock), (yyvsp[(3) - (3)].typedICBlock));
      }
      break;
      case DUTOKGE_DIV :
      {
        // ... append a (integral) division operation.
        lukas::AppendIntegerDivisionOperationTypedICBlock(ctx, (yyloc), (yyval.typedICBlock), (yyvsp[(1) - (3)].typedICBlock), (yyvsp[(3) - (3)].typedICBlock));
      }
      break;
      case DUTOKGE_MOD :
      {
        // ... append a modulo operation.
        lukas::AppendModuloOperationTypedICBlock(ctx, (yyloc), (yyval.typedICBlock), (yyvsp[(1) - (3)].typedICBlock), (yyvsp[(3) - (3)].typedICBlock));
      }
      break;
      case DUTOKGE_AND :
      {
        // ... append a conjunction operation.
        lukas::AppendConjunctionOperationTypedICBlock(ctx, (yyloc), (yyval.typedICBlock), (yyvsp[(1) - (3)].typedICBlock), (yyvsp[(3) - (3)].typedICBlock));
      }
      break;
      default :
      {
        // Error (Unsupported operand.)
      }
      break;
    }
  ;}
    break;

  case 150:
#line 1190 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
	  // SA (default)
	  (yyval.typedICBlock) = (yyvsp[(1) - (1)].typedICBlock);
  ;}
    break;

  case 151:
#line 1198 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.dtge_) = (yyvsp[(1) - (1)].dtge_);
  ;}
    break;

  case 152:
#line 1208 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA, ICG
    
    // type
    (yyval.typedICBlock).typePointer = (yyvsp[(1) - (1)].constant).typePointer;
    
    // IC block
    (yyval.typedICBlock).icblockPointer = icblock_create();
    lukas::AppendLDLITInstruction((yyval.typedICBlock).icblockPointer, (yyvsp[(1) - (1)].constant));
  ;}
    break;

  case 153:
#line 1219 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA, ICG
    
    // Find the symbol in the semantic tables.
    symbol_pointer sp = ctx->tab->find_symbol((yyvsp[(1) - (1)].id_ci_));
    if (!sp)
    {
      // Error (The symbol does not exist.)
      error(DUERR_NOTVAR, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id_ci_)->c_str());
    }
  
    // Depending on the kind of symbol ...
    (yyval.typedICBlock).icblockPointer = icblock_create();
    switch (sp->kind())
    {
      case SKIND_CONST :
      {
        // The symbol is a constant.
        
        // Find the constant in the semantic tables.
        lukas::Constant constant = lukas::FindConstant(ctx, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id_ci_));
        
        // type
        (yyval.typedICBlock).typePointer = constant.typePointer;
        
        // IC block
        lukas::AppendLDLITInstruction((yyval.typedICBlock).icblockPointer, constant);
      }
      break;
      case SKIND_GLOBAL_VARIABLE :
      case SKIND_LOCAL_VARIABLE :
      {
        // The symbol is a (global or local) variable.
        
        // Find the variable in the semantic tables.
        lukas::Variable variable = lukas::FindVariable(ctx, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id_ci_));
        
        // type
        (yyval.typedICBlock).typePointer = variable.typePointer;
        
        // IC block
        if (variable.typePointer->cat() == TCAT_RECORD)
        {
          // The variable is a record.
          (yyval.typedICBlock).stackAddress = sp->access_variable()->address();
        }
        else
        {
          // The variables is not a record.
          lukas::AppendLDInstruction((yyval.typedICBlock).icblockPointer, variable.symbolKind, variable.typePointer->cat(), variable.stackAddress);
        }
      }
      break;
      case SKIND_FUNCTION :
      {
        // The symbol is a function.

        (yyval.typedICBlock) = lukas::TypedICBlock();
        lukas::actual_parameter_list emptyActualParameterList = lukas::actual_parameter_list();
        lukas::AppendFunctionCallExpressionTypedICBlock(ctx, (yylsp[(1) - (1)]), (yyval.typedICBlock), (yyvsp[(1) - (1)].id_ci_), emptyActualParameterList); 
      }
      break;
      default :
      {
        // The symbol is not a constant nor a variable nor a function.
      
        // type
        (yyval.typedICBlock).typePointer = ctx->tab->logical_undef();
        
        // Error
        error(DUERR_NOTVAR, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id_ci_)->c_str());
      }
      break;
    }
  ;}
    break;

  case 154:
#line 1295 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA, ICG

    // type
    (yyval.typedICBlock).typePointer = (yyvsp[(1) - (1)].variable).typePointer;
    
    // IC block
    (yyval.typedICBlock).icblockPointer = icblock_create();
    if ((yyvsp[(1) - (1)].variable).typePointer->cat() == TCAT_RECORD)
    {
      // The field is a record.
      (yyval.typedICBlock).stackAddress = (yyvsp[(1) - (1)].variable).stackAddress;
    }
    else
    {
      // The field is not a record.
      lukas::AppendLDInstruction((yyval.typedICBlock).icblockPointer, (yyvsp[(1) - (1)].variable).symbolKind, (yyvsp[(1) - (1)].variable).typePointer->cat(), (yyvsp[(1) - (1)].variable).stackAddress);
    }
  ;}
    break;

  case 155:
#line 1315 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA, ICG
    
    // type
    (yyval.typedICBlock).typePointer = (yyvsp[(1) - (1)].variable).typePointer;
    
    // IC block
    (yyval.typedICBlock).icblockPointer = icblock_create();
    if ((yyvsp[(1) - (1)].variable).typePointer->cat() == TCAT_RECORD)
    {
      // The field is a record.
      (yyval.typedICBlock).stackAddress = (yyvsp[(1) - (1)].variable).stackAddress;
    }
    else
    {
      // The field is not a record.
      lukas::AppendLDInstruction((yyval.typedICBlock).icblockPointer, (yyvsp[(1) - (1)].variable).symbolKind, (yyvsp[(1) - (1)].variable).typePointer->cat(), (yyvsp[(1) - (1)].variable).stackAddress);
    }
  ;}
    break;

  case 156:
#line 1335 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.typedICBlock) = (yyvsp[(1) - (1)].typedICBlock);
  ;}
    break;

  case 157:
#line 1340 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (default)
    (yyval.typedICBlock) = (yyvsp[(2) - (3)].typedICBlock);
  ;}
    break;

  case 158:
#line 1345 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA (empty)
  ;}
    break;

  case 159:
#line 1352 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"
    {
    // SA, ICG 
    (yyval.typedICBlock) = lukas::TypedICBlock();
    lukas::AppendFunctionCallExpressionTypedICBlock(ctx, (yylsp[(1) - (2)]), (yyval.typedICBlock), (yyvsp[(1) - (2)].id_ci_), (yyvsp[(2) - (2)].actualParameterList));
  ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2847 "du5g.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
      yyerror (&yylloc, ctx, YY_("syntax error"));
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
	    yyerror (&yylloc, ctx, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, ctx, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc, ctx);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, ctx);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, ctx, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, ctx);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, ctx);
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


#line 1359 "c:\\Documents and Settings\\lukaskudela\\Dokumenty\\Visual Studio 2008\\Projects\\mlaskal\\public-rw\\SWI098\\du5\\du5g.y"


static void yyerror(unsigned *line, MlaskalCtx *, const char *m)
{
    error(DUERR_SYNTAX, *line, m);
}

