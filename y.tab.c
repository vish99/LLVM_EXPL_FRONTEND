/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "exptree.y" /* yacc.c:339  */

    #include<stdio.h>
    #include<stdlib.h>
    #define YYSTYPE struct node*
    #include"exptree.c"
    char* ch;
    extern FILE *yyin;
    extern int line;
    extern int freeAdd;
    int classes = 0;
    int varType = -1;
    int phase = 0;
    int fieldSize = 0;
    struct Lsymbol* Ltable = NULL;
    struct Fieldlist* Fields = NULL;
    struct ClassTable* CurrentClass = NULL;

#line 84 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    ENDCLASS = 259,
    DECL = 260,
    ENDDECL = 261,
    TYPE = 262,
    ENDTYPE = 263,
    INT = 264,
    STR = 265,
    null = 266,
    STRNODE = 267,
    MAIN = 268,
    RETURN = 269,
    INIT = 270,
    ALLOC = 271,
    FREE = 272,
    NEW = 273,
    DELETE = 274,
    SELF = 275,
    EXTENDS = 276,
    BEGIN = 277,
    NUM = 278,
    EOS = 279,
    END_OF_FILE = 280,
    ID = 281,
    READ = 282,
    WRITE = 283,
    END = 284,
    IF = 285,
    ENDIF = 286,
    WHILE = 287,
    ENDWHILE = 288,
    THEN = 289,
    DO = 290,
    ELSE = 291,
    GT = 292,
    LT = 293,
    GE = 294,
    LE = 295,
    EQ = 296,
    NE = 297,
    AND = 298,
    OR = 299,
    BREAK = 300,
    CONTINUE = 301,
    REPEAT = 302,
    UNTIL = 303
  };
#endif
/* Tokens.  */
#define CLASS 258
#define ENDCLASS 259
#define DECL 260
#define ENDDECL 261
#define TYPE 262
#define ENDTYPE 263
#define INT 264
#define STR 265
#define null 266
#define STRNODE 267
#define MAIN 268
#define RETURN 269
#define INIT 270
#define ALLOC 271
#define FREE 272
#define NEW 273
#define DELETE 274
#define SELF 275
#define EXTENDS 276
#define BEGIN 277
#define NUM 278
#define EOS 279
#define END_OF_FILE 280
#define ID 281
#define READ 282
#define WRITE 283
#define END 284
#define IF 285
#define ENDIF 286
#define WHILE 287
#define ENDWHILE 288
#define THEN 289
#define DO 290
#define ELSE 291
#define GT 292
#define LT 293
#define GE 294
#define LE 295
#define EQ 296
#define NE 297
#define AND 298
#define OR 299
#define BREAK 300
#define CONTINUE 301
#define REPEAT 302
#define UNTIL 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 228 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   705

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  327

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    50,    63,     2,
      58,    59,    54,    52,    60,    53,    51,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    31,    31,    31,    34,    35,    38,    39,    42,    43,
      46,    46,    51,    52,    55,    58,    59,    60,    63,    64,
      67,    68,    71,    74,    75,    78,    79,    81,    84,    85,
      88,    92,    93,    98,    99,   100,   102,   102,   104,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   119,
     120,   123,   136,   150,   155,   157,   160,   168,   171,   172,
     173,   176,   177,   180,   183,   184,   187,   190,   191,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     205,   206,   207,   216,   218,   221,   223,   228,   233,   240,
     245,   250,   255,   263,   264,   266,   269,   272,   275,   276,
     278,   281,   285,   289,   290,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   320,   321,
     322,   325,   326,   328,   331,   334,   338,   342,   347,   348
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "ENDCLASS", "DECL", "ENDDECL",
  "TYPE", "ENDTYPE", "INT", "STR", "null", "STRNODE", "MAIN", "RETURN",
  "INIT", "ALLOC", "FREE", "NEW", "DELETE", "SELF", "EXTENDS", "BEGIN",
  "NUM", "EOS", "END_OF_FILE", "ID", "READ", "WRITE", "END", "IF", "ENDIF",
  "WHILE", "ENDWHILE", "THEN", "DO", "ELSE", "GT", "LT", "GE", "LE", "EQ",
  "NE", "AND", "OR", "BREAK", "CONTINUE", "REPEAT", "UNTIL", "'='", "'%'",
  "'.'", "'+'", "'-'", "'*'", "'/'", "'{'", "'}'", "'('", "')'", "','",
  "'['", "']'", "'&'", "$accept", "start", "$@1", "Program", "TypeBlock",
  "TypeDefList", "TypeDef", "$@2", "FieldDecList", "FieldDec", "TypeName",
  "ClassDefBlock", "ClassDefList", "ClassDef", "Cname", "Fieldlists",
  "Fld", "MethodDecl", "MDecl", "MethodDefs", "GDeclBlock", "GDeclList",
  "GDecl", "VarList", "FDeclBlock", "FDef", "Fhead", "ParamList", "Param",
  "MainBlock", "LDeclBlock", "LDeclList", "LDecl", "LidList", "Body",
  "Slist", "Stmt", "InputStmt", "OutputStmt", "AsgStmt", "IfStmt",
  "WhileStmt", "BrkStmt", "ContinueStmt", "DowhileStmt", "RetStmt",
  "FreeStmt", "DelStmt", "Array1", "expr", "ArgList", "Field",
  "FieldFunction", "IDfield", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    61,
      37,    46,    43,    45,    42,    47,   123,   125,    40,    41,
      44,    91,    93,    38
};
# endif

#define YYPACT_NINF -100

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-100)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -100,     7,    17,  -100,    16,    22,    54,  -100,    10,  -100,
    -100,    39,   101,    60,  -100,  -100,   104,    11,  -100,    92,
     141,    43,   152,   128,  -100,  -100,   160,  -100,  -100,  -100,
    -100,   -16,   143,  -100,   144,   140,    43,  -100,   112,  -100,
      -1,  -100,   147,  -100,  -100,    57,   153,   -19,  -100,  -100,
     114,   122,  -100,  -100,   165,  -100,  -100,   162,   152,   152,
     158,  -100,  -100,    -9,   132,   152,   149,   311,  -100,   168,
    -100,   206,  -100,   182,   -37,  -100,   151,    59,   193,   169,
      20,  -100,   201,   208,  -100,    55,   170,   171,   194,   -30,
     189,   191,   195,   196,   311,   231,   233,   311,   234,   202,
     311,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,   218,   219,  -100,    -8,   152,   239,  -100,
    -100,  -100,   152,   220,   152,   260,  -100,   165,  -100,  -100,
     -11,  -100,  -100,  -100,  -100,   235,  -100,    61,   268,    55,
    -100,   352,  -100,  -100,   269,   270,   274,    28,   275,    55,
       0,    55,    55,    55,   334,  -100,  -100,   216,   254,  -100,
    -100,    55,    50,  -100,   152,     2,  -100,   246,  -100,   286,
      34,   248,   311,  -100,   285,   287,   291,    55,  -100,   531,
    -100,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,   253,   262,   271,  -100,   266,   278,
     282,   300,   373,   271,  -100,   455,    13,   273,   290,   554,
     577,   600,   289,   292,    55,   394,   294,   415,    64,  -100,
    -100,   265,  -100,   283,   272,  -100,    26,   297,    63,   301,
     507,   304,  -100,   238,   238,   238,   238,   238,   238,   238,
     238,   146,    74,    74,   312,  -100,   321,   344,   313,   314,
     345,   346,  -100,   316,   350,   351,   354,   358,   349,   363,
      55,    55,   436,  -100,   359,  -100,   360,  -100,   364,  -100,
      55,    55,    55,    55,    55,  -100,  -100,  -100,   362,   375,
     341,  -100,    55,  -100,  -100,  -100,  -100,   311,   311,   623,
     646,  -100,   342,  -100,   347,   361,   365,   370,   371,  -100,
    -100,  -100,   379,   481,   157,   252,    36,   384,   395,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,   397,   311,   398,  -100,
    -100,  -100,  -100,   288,  -100,   416,  -100
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     7,     1,     0,     0,    19,    10,     0,     9,
       3,     0,    35,     0,     6,     8,    23,     0,    21,     0,
       0,     0,     0,     0,    18,    20,     0,    34,    15,    16,
      17,     0,     0,    37,    15,     0,     0,    50,     0,     5,
       0,    13,     0,    24,    26,    40,     0,     0,    33,    36,
       0,     0,    49,     4,    60,    11,    12,     0,     0,    55,
       0,    46,    38,     0,     0,    55,     0,     0,    14,     0,
      25,     0,    29,     0,     0,    54,     0,    39,     0,     0,
       0,    59,     0,     0,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,   131,     0,     0,     0,    28,
      56,    48,     0,    42,    55,     0,    45,    60,    52,    65,
       0,    58,    61,   117,   114,     0,   111,   112,     0,     0,
     115,     0,   116,   118,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,     0,     0,    51,
      67,     0,     0,    27,    55,     0,    32,     0,    53,     0,
       0,     0,     0,    63,     0,     0,     0,   130,   113,     0,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   132,   133,     0,     0,
       0,     0,     0,   139,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      31,     0,    47,    41,     0,    64,   132,   133,   139,   138,
     129,     0,   110,   121,   120,   123,   122,   124,   125,   126,
     127,   109,   105,   106,   107,   108,     0,     0,     0,     0,
       0,     0,    84,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,     0,    88,     0,    44,     0,    57,
     130,   130,   130,   130,   130,   119,   101,   102,     0,     0,
       0,    87,     0,    80,    81,    82,    83,     0,     0,     0,
       0,    86,     0,    30,     0,     0,     0,     0,     0,   128,
      89,    90,     0,     0,     0,     0,     0,     0,     0,    43,
     134,   135,   136,   137,    91,   104,     0,     0,     0,    98,
      99,    92,    94,     0,    95,     0,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,  -100,  -100,  -100,  -100,  -100,   433,  -100,  -100,   402,
     124,  -100,  -100,   426,  -100,  -100,  -100,  -100,   374,  -100,
    -100,  -100,   418,  -100,  -100,   -22,  -100,   -61,   329,   425,
     335,  -100,   380,  -100,   299,   -91,   -99,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,   -67,   -51,
       3,   -65,  -100,   -49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,     8,     9,    13,    40,    41,
      73,    12,    17,    18,    19,    58,    70,    71,    72,   165,
      21,    32,    33,    47,    36,    37,    38,    74,    75,    39,
      67,    83,    84,   130,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   140,   230,
     231,   142,   143,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     113,   160,   114,   154,    80,    62,   157,     3,    28,    29,
      45,    28,    29,   173,    52,    24,   163,    77,    14,   147,
      88,   148,   121,   122,     4,    30,   206,   113,    30,   114,
     113,   149,   114,   113,   141,   114,     7,    16,    46,   133,
     134,    63,     7,   198,   199,    78,   200,    10,   135,   174,
     164,   136,    34,    29,   137,   160,    55,    11,   160,   219,
     319,   133,   134,   170,   148,    16,   133,   134,   216,    30,
     135,   288,   254,   136,   149,   135,   137,   148,   136,   128,
     122,   137,   138,   207,   270,   208,   139,   113,   179,   114,
     113,   201,   114,   222,   122,   166,   202,   197,   205,   204,
     209,   210,   211,   218,   138,   113,    20,   114,   139,   138,
     215,   217,   176,   139,   148,    59,    22,   124,    60,   177,
     125,   272,   149,   266,   122,    23,   227,   229,   192,   193,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   220,    31,    35,    42,    27,    26,    48,
      28,    29,    28,    29,    43,    81,    31,    50,    28,    29,
      35,    28,    29,   262,    42,    44,    51,    30,    54,    30,
      66,    85,    64,    57,    86,    30,    87,    88,    30,    61,
      65,    76,    69,    89,    90,    91,    68,    92,   316,    93,
      82,    79,    94,   317,   116,   118,   304,   305,   190,   191,
     192,   193,    95,    96,    97,   160,   160,    82,   120,   289,
     290,    98,   117,   123,   131,    28,    29,    28,    29,   126,
     113,   113,   114,   114,   160,   127,   323,   129,   144,   145,
      85,   303,    30,    86,    30,    87,    88,   113,   113,   114,
     114,    35,    89,    90,    91,   146,    92,   150,    93,   151,
     113,    94,   114,   152,   153,   155,   113,   156,   114,   159,
     158,    95,    96,    97,   213,   167,    85,   161,   162,    86,
      98,    87,    88,   295,   296,   297,   298,   299,    89,    90,
      91,   169,    92,   171,    93,   318,   175,    94,   189,    35,
     190,   191,   192,   193,   178,   194,   195,    95,    96,    97,
     196,   203,    85,   214,   164,    86,    98,    87,    88,   221,
     223,   225,   246,   226,    89,    90,    91,   228,    92,   325,
      93,   247,   148,    94,   248,    85,   251,   267,    86,   269,
      87,    88,   255,    95,    96,    97,   249,    89,    90,    91,
     250,    92,    98,    93,   268,   276,    94,   260,    85,   256,
     261,    86,   264,    87,    88,   271,    95,    96,    97,   273,
      89,    90,    91,   275,    92,    98,   212,   193,   277,    94,
     281,   280,   278,   279,   283,   284,   180,   282,   285,    95,
      96,    97,   286,   287,   293,   292,   300,   294,    98,   181,
     182,   183,   184,   185,   186,   187,   188,   252,   288,   301,
     302,   308,   189,   314,   190,   191,   192,   193,   320,   309,
     181,   182,   183,   184,   185,   186,   187,   188,   263,   321,
     310,   322,   324,   189,   311,   190,   191,   192,   193,   312,
     313,   181,   182,   183,   184,   185,   186,   187,   188,   265,
     326,    15,    56,    25,   189,   119,   190,   191,   192,   193,
      49,   168,   181,   182,   183,   184,   185,   186,   187,   188,
     291,    53,   172,   132,     0,   189,     0,   190,   191,   192,
     193,   224,     0,   181,   182,   183,   184,   185,   186,   187,
     188,     0,     0,     0,     0,     0,   189,     0,   190,   191,
     192,   193,   181,   182,   183,   184,   185,   186,   187,   188,
       0,     0,     0,     0,     0,   189,     0,   190,   191,   192,
     193,     0,     0,     0,     0,     0,     0,   253,   181,   182,
     183,   184,   185,   186,   187,   188,     0,     0,     0,     0,
       0,   189,     0,   190,   191,   192,   193,     0,     0,     0,
       0,     0,     0,   315,   181,   182,   183,   184,   185,   186,
     187,   188,     0,     0,     0,     0,     0,   189,     0,   190,
     191,   192,   193,     0,     0,     0,     0,   274,   181,   182,
     183,   184,   185,   186,   187,   188,     0,     0,     0,     0,
       0,   189,     0,   190,   191,   192,   193,     0,     0,     0,
     232,   181,   182,   183,   184,   185,   186,   187,   188,     0,
       0,     0,     0,     0,   189,     0,   190,   191,   192,   193,
       0,     0,     0,   257,   181,   182,   183,   184,   185,   186,
     187,   188,     0,     0,     0,     0,     0,   189,     0,   190,
     191,   192,   193,     0,     0,     0,   258,   181,   182,   183,
     184,   185,   186,   187,   188,     0,     0,     0,     0,     0,
     189,     0,   190,   191,   192,   193,     0,     0,     0,   259,
     181,   182,   183,   184,   185,   186,   187,   188,     0,     0,
       0,     0,     0,   189,     0,   190,   191,   192,   193,     0,
       0,     0,   306,   181,   182,   183,   184,   185,   186,   187,
     188,     0,     0,     0,     0,     0,   189,     0,   190,   191,
     192,   193,     0,     0,     0,   307
};

static const yytype_int16 yycheck[] =
{
      67,   100,    67,    94,    65,    24,    97,     0,     9,    10,
      26,     9,    10,    24,    36,     4,    24,    26,     8,    49,
      20,    51,    59,    60,     7,    26,    26,    94,    26,    94,
      97,    61,    97,   100,    85,   100,    26,    26,    54,    11,
      12,    60,    26,    15,    16,    54,    18,    25,    20,    60,
      58,    23,     9,    10,    26,   154,    57,     3,   157,    57,
      24,    11,    12,   124,    51,    26,    11,    12,    18,    26,
      20,    35,    59,    23,    61,    20,    26,    51,    23,    59,
      60,    26,    54,   150,    58,   150,    58,   154,   139,   154,
     157,    63,   157,    59,    60,   117,   147,   146,   149,   148,
     151,   152,   153,   164,    54,   172,     5,   172,    58,    54,
     161,   162,    51,    58,    51,    58,    56,    58,    61,    58,
      61,    58,    61,    59,    60,    21,   175,   176,    54,    55,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   165,    20,    21,    22,     6,    56,     6,
       9,    10,     9,    10,    26,     6,    32,    13,     9,    10,
      36,     9,    10,   214,    40,     5,    26,    26,    56,    26,
       5,    14,    58,    26,    17,    26,    19,    20,    26,    26,
      58,    23,    58,    26,    27,    28,    24,    30,    31,    32,
      66,    59,    35,    36,    26,    71,   287,   288,    52,    53,
      54,    55,    45,    46,    47,   304,   305,    83,    26,   260,
     261,    54,     6,    62,     6,     9,    10,     9,    10,    26,
     287,   288,   287,   288,   323,    56,   317,    26,    58,    58,
      14,   282,    26,    17,    26,    19,    20,   304,   305,   304,
     305,   117,    26,    27,    28,    51,    30,    58,    32,    58,
     317,    35,   317,    58,    58,    24,   323,    24,   323,    57,
      26,    45,    46,    47,    48,    26,    14,    49,    49,    17,
      54,    19,    20,   270,   271,   272,   273,   274,    26,    27,
      28,    61,    30,    23,    32,    33,    51,    35,    50,   165,
      52,    53,    54,    55,    26,    26,    26,    45,    46,    47,
      26,    26,    14,    49,    58,    17,    54,    19,    20,    23,
      62,    26,    59,    26,    26,    27,    28,    26,    30,    31,
      32,    59,    51,    35,    58,    14,    26,    62,    17,    57,
      19,    20,    59,    45,    46,    47,    58,    26,    27,    28,
      58,    30,    54,    32,    61,    24,    35,    58,    14,    59,
      58,    17,    58,    19,    20,    58,    45,    46,    47,    58,
      26,    27,    28,    59,    30,    54,    32,    55,    24,    35,
      24,    26,    59,    59,    24,    24,    24,    61,    24,    45,
      46,    47,    24,    34,    24,    26,    24,    23,    54,    37,
      38,    39,    40,    41,    42,    43,    44,    24,    35,    24,
      59,    59,    50,    24,    52,    53,    54,    55,    24,    62,
      37,    38,    39,    40,    41,    42,    43,    44,    24,    24,
      59,    24,    24,    50,    59,    52,    53,    54,    55,    59,
      59,    37,    38,    39,    40,    41,    42,    43,    44,    24,
      24,     8,    40,    17,    50,    71,    52,    53,    54,    55,
      32,   122,    37,    38,    39,    40,    41,    42,    43,    44,
      24,    36,   127,    83,    -1,    50,    -1,    52,    53,    54,
      55,   172,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,
      54,    55,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    60,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    54,    55,    -1,    -1,    -1,
      59,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,
      -1,    -1,    -1,    59,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    54,    55,    -1,    -1,    -1,    59,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    54,    55,    -1,    -1,    -1,    59,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,    -1,
      -1,    -1,    59,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,
      54,    55,    -1,    -1,    -1,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    65,    66,     0,     7,    67,    68,    26,    69,    70,
      25,     3,    75,    71,     8,    70,    26,    76,    77,    78,
       5,    84,    56,    21,     4,    77,    56,     6,     9,    10,
      26,    74,    85,    86,     9,    74,    88,    89,    90,    93,
      72,    73,    74,    26,     5,    26,    54,    87,     6,    86,
      13,    26,    89,    93,    56,    57,    73,    26,    79,    58,
      61,    26,    24,    60,    58,    58,     5,    94,    24,    74,
      80,    81,    82,    74,    91,    92,    23,    26,    54,    59,
      91,     6,    74,    95,    96,    14,    17,    19,    20,    26,
      27,    28,    30,    32,    35,    45,    46,    47,    54,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   115,   117,    26,     6,    74,    82,
      26,    59,    60,    62,    58,    61,    26,    56,    59,    26,
      97,     6,    96,    11,    12,    20,    23,    26,    54,    58,
     112,   113,   115,   116,    58,    58,    51,    49,    51,    61,
      58,    58,    58,    58,    99,    24,    24,    99,    26,    57,
     100,    49,    49,    24,    58,    83,    89,    26,    92,    61,
      91,    23,    94,    24,    60,    51,    51,    58,    26,   113,
      24,    37,    38,    39,    40,    41,    42,    43,    44,    50,
      52,    53,    54,    55,    26,    26,    26,   117,    15,    16,
      18,    63,   113,    26,   117,   113,    26,   112,   115,   113,
     113,   113,    32,    48,    49,   113,    18,   113,    91,    57,
      89,    23,    59,    62,    98,    26,    26,   117,    26,   117,
     113,   114,    59,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,    59,    59,    58,    58,
      58,    26,    24,    62,    59,    59,    59,    59,    59,    59,
      58,    58,   113,    24,    58,    24,    59,    62,    61,    57,
      58,    58,    58,    58,    60,    59,    24,    24,    59,    59,
      26,    24,    61,    24,    24,    24,    24,    34,    35,   113,
     113,    24,    26,    24,    23,   114,   114,   114,   114,   114,
      24,    24,    59,   113,    99,    99,    59,    59,    59,    62,
      59,    59,    59,    59,    24,    62,    31,    36,    33,    24,
      24,    24,    24,    99,    24,    31,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    66,    65,    67,    67,    68,    68,    69,    69,
      71,    70,    72,    72,    73,    74,    74,    74,    75,    75,
      76,    76,    77,    78,    78,    79,    79,    80,    81,    81,
      82,    83,    83,    84,    84,    84,    85,    85,    86,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    88,
      88,    89,    90,    91,    91,    91,    92,    93,    94,    94,
      94,    95,    95,    96,    97,    97,    98,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   101,   101,   102,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   104,   104,   105,   106,   107,   108,   108,
     109,   110,   111,   112,   112,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   114,   114,
     114,   115,   115,   115,   116,   116,   116,   116,   117,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     5,     4,     3,     0,     2,     1,
       0,     5,     2,     1,     3,     1,     1,     1,     3,     0,
       2,     1,     8,     1,     3,     2,     0,     3,     2,     1,
       6,     2,     1,     3,     2,     0,     2,     1,     3,     3,
       1,     6,     4,     9,     7,     4,     2,     6,     4,     2,
       1,     5,     5,     3,     1,     0,     2,     8,     3,     2,
       0,     2,     1,     3,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     5,     4,     4,     5,     5,     4,     6,
       6,     7,     7,    10,     8,     8,     2,     2,     7,     7,
       3,     5,     5,     4,     7,     3,     3,     3,     3,     3,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       0,     1,     3,     3,     6,     6,     6,     6,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 31 "exptree.y" /* yacc.c:1663  */
    {TypeTableInitialize();generateInitCode();}
#line 1605 "y.tab.c" /* yacc.c:1663  */
    break;

  case 3:
#line 31 "exptree.y" /* yacc.c:1663  */
    {printf("\n");return 1;}
#line 1611 "y.tab.c" /* yacc.c:1663  */
    break;

  case 6:
#line 38 "exptree.y" /* yacc.c:1663  */
    {phase = 1;}
#line 1617 "y.tab.c" /* yacc.c:1663  */
    break;

  case 7:
#line 39 "exptree.y" /* yacc.c:1663  */
    {phase = 1;}
#line 1623 "y.tab.c" /* yacc.c:1663  */
    break;

  case 10:
#line 46 "exptree.y" /* yacc.c:1663  */
    {TInstall((yyvsp[0])->varname);}
#line 1629 "y.tab.c" /* yacc.c:1663  */
    break;

  case 11:
#line 46 "exptree.y" /* yacc.c:1663  */
    {TInstallFields((yyvsp[-4])->varname,fieldSize,Fields);
							      free((yyvsp[-4]));fieldSize = 0;;
							      generateTypeDef((yyvsp[-4])->varname,Fields);Fields = NULL;}
#line 1637 "y.tab.c" /* yacc.c:1663  */
    break;

  case 14:
#line 55 "exptree.y" /* yacc.c:1663  */
    {Fields=FInstall(Fields,(yyvsp[-1])->varname,(yyvsp[-2])->varname,&fieldSize);free((yyvsp[-2]));free((yyvsp[-1]));}
#line 1643 "y.tab.c" /* yacc.c:1663  */
    break;

  case 15:
#line 58 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(EMPTY_NODE,0,"int",NULL,NULL,NULL,NULL);}
#line 1649 "y.tab.c" /* yacc.c:1663  */
    break;

  case 16:
#line 59 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(EMPTY_NODE,0,"str",NULL,NULL,NULL,NULL);}
#line 1655 "y.tab.c" /* yacc.c:1663  */
    break;

  case 17:
#line 60 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1661 "y.tab.c" /* yacc.c:1663  */
    break;

  case 18:
#line 63 "exptree.y" /* yacc.c:1663  */
    {phase = 2;freeAdd = 4096 + 8*classes;}
#line 1667 "y.tab.c" /* yacc.c:1663  */
    break;

  case 19:
#line 64 "exptree.y" /* yacc.c:1663  */
    {phase = 2;}
#line 1673 "y.tab.c" /* yacc.c:1663  */
    break;

  case 22:
#line 71 "exptree.y" /* yacc.c:1663  */
    {CurrentClass = NULL;}
#line 1679 "y.tab.c" /* yacc.c:1663  */
    break;

  case 23:
#line 74 "exptree.y" /* yacc.c:1663  */
    {CurrentClass = CInstall((yyvsp[0])->varname,NULL);free((yyvsp[0]));classes++;}
#line 1685 "y.tab.c" /* yacc.c:1663  */
    break;

  case 24:
#line 75 "exptree.y" /* yacc.c:1663  */
    {CurrentClass = CInstall((yyvsp[-2])->varname,(yyvsp[0])->varname);free((yyvsp[-2]));free((yyvsp[0]));classes++;}
#line 1691 "y.tab.c" /* yacc.c:1663  */
    break;

  case 27:
#line 81 "exptree.y" /* yacc.c:1663  */
    {ClassFInstall(CurrentClass,(yyvsp[-2])->varname,(yyvsp[-1])->varname);free((yyvsp[-2]));free((yyvsp[-1]));}
#line 1697 "y.tab.c" /* yacc.c:1663  */
    break;

  case 30:
#line 88 "exptree.y" /* yacc.c:1663  */
    {ClassMInstall(CurrentClass,(yyvsp[-4])->varname,(yyvsp[-5])->varname,(yyvsp[-2])->paramList);
						 free((yyvsp[-5]));free((yyvsp[-4]));free((yyvsp[-2]));}
#line 1704 "y.tab.c" /* yacc.c:1663  */
    break;

  case 33:
#line 98 "exptree.y" /* yacc.c:1663  */
    {phase = 3;}
#line 1710 "y.tab.c" /* yacc.c:1663  */
    break;

  case 34:
#line 99 "exptree.y" /* yacc.c:1663  */
    {phase = 3;Ltable = NULL;}
#line 1716 "y.tab.c" /* yacc.c:1663  */
    break;

  case 35:
#line 100 "exptree.y" /* yacc.c:1663  */
    {phase = 3;Ltable = NULL;}
#line 1722 "y.tab.c" /* yacc.c:1663  */
    break;

  case 39:
#line 107 "exptree.y" /* yacc.c:1663  */
    {Install((yyvsp[0]),(yyvsp[-3])->varname,1,0,NULL);free((yyvsp[0]));}
#line 1728 "y.tab.c" /* yacc.c:1663  */
    break;

  case 40:
#line 108 "exptree.y" /* yacc.c:1663  */
    {Install((yyvsp[0]),(yyvsp[-1])->varname,1,0,NULL);free((yyvsp[0]));}
#line 1734 "y.tab.c" /* yacc.c:1663  */
    break;

  case 41:
#line 109 "exptree.y" /* yacc.c:1663  */
    {Install((yyvsp[-3]),(yyvsp[-6])->varname,(yyvsp[-1])->val,0,NULL);free((yyvsp[-1]));free((yyvsp[-3]));}
#line 1740 "y.tab.c" /* yacc.c:1663  */
    break;

  case 42:
#line 110 "exptree.y" /* yacc.c:1663  */
    {Install((yyvsp[-3]),(yyvsp[-4])->varname,(yyvsp[-1])->val,0,NULL);free((yyvsp[-3]));free((yyvsp[-1]));}
#line 1746 "y.tab.c" /* yacc.c:1663  */
    break;

  case 43:
#line 111 "exptree.y" /* yacc.c:1663  */
    {Install((yyvsp[-6]),(yyvsp[-9])->varname,((yyvsp[-4])->val)*((yyvsp[-1])->val),(yyvsp[-4])->val,NULL);free((yyvsp[-4]));free((yyvsp[-1]));free((yyvsp[-8]));}
#line 1752 "y.tab.c" /* yacc.c:1663  */
    break;

  case 44:
#line 112 "exptree.y" /* yacc.c:1663  */
    {Install((yyvsp[-6]),(yyvsp[-7])->varname,((yyvsp[-4])->val)*((yyvsp[-1])->val),(yyvsp[-4])->val,NULL);free((yyvsp[-4]));free((yyvsp[-1]));free((yyvsp[-6]));}
#line 1758 "y.tab.c" /* yacc.c:1663  */
    break;

  case 45:
#line 113 "exptree.y" /* yacc.c:1663  */
    {Install((yyvsp[0]),(yyvsp[-4])->varname,1,0,NULL);free((yyvsp[0]));}
#line 1764 "y.tab.c" /* yacc.c:1663  */
    break;

  case 46:
#line 114 "exptree.y" /* yacc.c:1663  */
    {Install((yyvsp[0]),(yyvsp[-2])->varname,1,0,NULL);free((yyvsp[0]));}
#line 1770 "y.tab.c" /* yacc.c:1663  */
    break;

  case 47:
#line 115 "exptree.y" /* yacc.c:1663  */
    {Install((yyvsp[-3]),(yyvsp[-6])->varname,0,0,(yyvsp[-1])->paramList);free((yyvsp[-3]));free((yyvsp[-1]));}
#line 1776 "y.tab.c" /* yacc.c:1663  */
    break;

  case 48:
#line 116 "exptree.y" /* yacc.c:1663  */
    {Install((yyvsp[-3]),(yyvsp[-4])->varname,0,0,(yyvsp[-1])->paramList);free((yyvsp[-3]));free((yyvsp[-1]));}
#line 1782 "y.tab.c" /* yacc.c:1663  */
    break;

  case 51:
#line 123 "exptree.y" /* yacc.c:1663  */
    {printf("Ltable:\n");
                                    			struct Lsymbol* temp = Ltable;
                                    			while(temp != NULL)
                                    			{
							      
                                        			printf("%s \n",temp->name);
                                        			temp=temp->next;
                                   			 }
                                    			 printf("DONE Ltable\n");
							generateFuncCode((yyvsp[-1]),(yyvsp[-4])->varname);
							Ltable=NULL;free((yyvsp[-4]));}
#line 1798 "y.tab.c" /* yacc.c:1663  */
    break;

  case 52:
#line 136 "exptree.y" /* yacc.c:1663  */
    {
							     if(CurrentClass != NULL && phase < 2 )
								Ltable = LInstall(Ltable,"self",NULL);
							     checkParam((yyvsp[-3])->varname,(yyvsp[-1])->paramList);
							     struct Paramstruct* temp = (yyvsp[-1])->paramList;
							     while(temp != NULL)
							     {
								 Ltable = LInstall(Ltable,temp->name,temp->type->name);
								 temp = temp->next;
							     }
							     (yyval)=(yyvsp[-3]);free((yyvsp[-4]));
							}
#line 1815 "y.tab.c" /* yacc.c:1663  */
    break;

  case 53:
#line 150 "exptree.y" /* yacc.c:1663  */
    {struct Paramstruct* temp = (yyvsp[-2])->paramList;
						    while(temp != NULL && temp->next != NULL) temp = temp->next;
						    temp->next = (yyvsp[0])->paramList;
						    (yyval)=(yyvsp[-2]);}
#line 1824 "y.tab.c" /* yacc.c:1663  */
    break;

  case 54:
#line 155 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1830 "y.tab.c" /* yacc.c:1663  */
    break;

  case 55:
#line 157 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(EMPTY_NODE,0,NULL,NULL,NULL,NULL,NULL);}
#line 1836 "y.tab.c" /* yacc.c:1663  */
    break;

  case 56:
#line 160 "exptree.y" /* yacc.c:1663  */
    {struct Paramstruct* newNode = malloc(sizeof(struct Paramstruct));
						    newNode->name = (yyvsp[0])->varname;
						    newNode->type = TLookup((yyvsp[-1])->varname);
						    newNode->next = NULL;
						    (yyval)=makeNode(EMPTY_NODE,0,NULL,NULL,NULL,NULL,newNode);}
#line 1846 "y.tab.c" /* yacc.c:1663  */
    break;

  case 57:
#line 168 "exptree.y" /* yacc.c:1663  */
    {phase = 5;generateMainCode((yyvsp[-1]));generateGlobalVariableCode();}
#line 1852 "y.tab.c" /* yacc.c:1663  */
    break;

  case 64:
#line 183 "exptree.y" /* yacc.c:1663  */
    {Ltable=LInstall(Ltable,(yyvsp[0])->varname,(yyvsp[-3])->varname);}
#line 1858 "y.tab.c" /* yacc.c:1663  */
    break;

  case 65:
#line 184 "exptree.y" /* yacc.c:1663  */
    {Ltable=LInstall(Ltable,(yyvsp[0])->varname,(yyvsp[-1])->varname);}
#line 1864 "y.tab.c" /* yacc.c:1663  */
    break;

  case 66:
#line 187 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1870 "y.tab.c" /* yacc.c:1663  */
    break;

  case 67:
#line 190 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(5,0,NULL,(yyvsp[-1]),(yyvsp[0]),NULL,NULL);}
#line 1876 "y.tab.c" /* yacc.c:1663  */
    break;

  case 68:
#line 191 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1882 "y.tab.c" /* yacc.c:1663  */
    break;

  case 69:
#line 193 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1888 "y.tab.c" /* yacc.c:1663  */
    break;

  case 70:
#line 194 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1894 "y.tab.c" /* yacc.c:1663  */
    break;

  case 71:
#line 195 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1900 "y.tab.c" /* yacc.c:1663  */
    break;

  case 72:
#line 196 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1906 "y.tab.c" /* yacc.c:1663  */
    break;

  case 73:
#line 197 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1912 "y.tab.c" /* yacc.c:1663  */
    break;

  case 74:
#line 198 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1918 "y.tab.c" /* yacc.c:1663  */
    break;

  case 75:
#line 199 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1924 "y.tab.c" /* yacc.c:1663  */
    break;

  case 76:
#line 200 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1930 "y.tab.c" /* yacc.c:1663  */
    break;

  case 77:
#line 201 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1936 "y.tab.c" /* yacc.c:1663  */
    break;

  case 78:
#line 202 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1942 "y.tab.c" /* yacc.c:1663  */
    break;

  case 79:
#line 203 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 1948 "y.tab.c" /* yacc.c:1663  */
    break;

  case 80:
#line 205 "exptree.y" /* yacc.c:1663  */
    {(yyvsp[-2])=makeNode(1,0,(yyvsp[-2])->varname,NULL,NULL,NULL,NULL);(yyval)=makeNode(4,0,NULL,(yyvsp[-2]),NULL,NULL,NULL);}
#line 1954 "y.tab.c" /* yacc.c:1663  */
    break;

  case 81:
#line 206 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(4,0,NULL,(yyvsp[-2]),NULL,NULL,NULL);}
#line 1960 "y.tab.c" /* yacc.c:1663  */
    break;

  case 82:
#line 207 "exptree.y" /* yacc.c:1663  */
    {//$3=makeNode(1,0,$3->varname,$3->left,NULL,NULL,NULL);
                                     (yyvsp[-2])->nodetype = FIELD_NODE;
                                     (yyvsp[-2])->type=getType((yyvsp[-2])->varname,(yyvsp[-2])->type,(yyvsp[-2])->class,(yyvsp[-2])->left);
				     if((yyvsp[-2])->type != TLookup("int") || (yyvsp[-2])->type != TLookup("str"))
				     {
					 printf("Error!\n");
				     }
				     (yyval)=makeNode(4,0,NULL,(yyvsp[-2]),NULL,NULL,NULL);}
#line 1973 "y.tab.c" /* yacc.c:1663  */
    break;

  case 83:
#line 216 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(3,0,NULL,(yyvsp[-2]),NULL,NULL,NULL);}
#line 1979 "y.tab.c" /* yacc.c:1663  */
    break;

  case 84:
#line 218 "exptree.y" /* yacc.c:1663  */
    {(yyvsp[-3])=makeNode(1,0,(yyvsp[-3])->varname,NULL,NULL,NULL,NULL);ch = malloc(1);*ch='=';
			   (yyval)=makeNode(2,0,ch,(yyvsp[-3]),(yyvsp[-1]),NULL,NULL);}
#line 1986 "y.tab.c" /* yacc.c:1663  */
    break;

  case 85:
#line 221 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(1);*ch = '='; (yyval)=makeNode(2,0,ch,(yyvsp[-3]),(yyvsp[-1]),NULL,NULL);}
#line 1992 "y.tab.c" /* yacc.c:1663  */
    break;

  case 86:
#line 223 "exptree.y" /* yacc.c:1663  */
    {(yyvsp[-3])=makeNode(1,0,(yyvsp[-3])->varname,NULL,NULL,NULL,NULL);
			       ch = malloc(1);*ch = '=';
			       (yyvsp[-3])->nodetype=PTR_NODE;
			       (yyval)=makeNode(2,0,ch,(yyvsp[-3]),(yyvsp[-1]),NULL,NULL);}
#line 2001 "y.tab.c" /* yacc.c:1663  */
    break;

  case 87:
#line 228 "exptree.y" /* yacc.c:1663  */
    {(yyvsp[-4])=makeNode(1,0,(yyvsp[-4])->varname,NULL,NULL,NULL,NULL);
			       (yyvsp[-1])=makeNode(1,0,(yyvsp[-1])->varname,NULL,NULL,NULL,NULL);
			       ch = malloc(1);*ch = '=';
			       (yyvsp[-1])->nodetype=ADD_NODE;(yyval)=makeNode(2,0,ch,(yyvsp[-4]),(yyvsp[-1]),NULL,NULL);}
#line 2010 "y.tab.c" /* yacc.c:1663  */
    break;

  case 88:
#line 233 "exptree.y" /* yacc.c:1663  */
    {
				  (yyvsp[-3])->nodetype = FIELD_NODE;
	                          (yyvsp[-3])->type=getType((yyvsp[-3])->varname,(yyvsp[-3])->type,(yyvsp[-3])->class,(yyvsp[-3])->left);
				  ch = malloc(1);*ch = '=';
                                  (yyval)=makeNode(2,0,ch,(yyvsp[-3]),(yyvsp[-1]),NULL,NULL);
			       }
#line 2021 "y.tab.c" /* yacc.c:1663  */
    break;

  case 89:
#line 240 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(1);*ch = '=';
				    (yyvsp[-3]) = makeNode(INIT_NODE,0,NULL,NULL,NULL,NULL,NULL);
				    (yyvsp[-5]) = makeNode(1,0,(yyvsp[-5])->varname,NULL,NULL,NULL,NULL);
				   (yyval)=makeNode(2,0,ch,(yyvsp[-5]),(yyvsp[-3]),NULL,NULL);}
#line 2030 "y.tab.c" /* yacc.c:1663  */
    break;

  case 90:
#line 245 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(1);*ch = '=';
				   (yyvsp[-5]) = makeNode(1,0,(yyvsp[-5])->varname,NULL,NULL,NULL,NULL);
				   (yyvsp[-3]) = makeNode(ALLOC_NODE,0,NULL,NULL,NULL,NULL,NULL);
                                   (yyval)=makeNode(2,0,ch,(yyvsp[-5]),(yyvsp[-3]),NULL,NULL);}
#line 2039 "y.tab.c" /* yacc.c:1663  */
    break;

  case 91:
#line 250 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(1);*ch = '=';
                                       (yyvsp[-6]) = makeNode(1,0,(yyvsp[-6])->varname,NULL,NULL,NULL,NULL);
				       (yyvsp[-4]) = makeNode(NEW_NODE,0,NULL,(yyvsp[-2]),NULL,NULL,NULL);
				       (yyval) = makeNode(2,0,ch,(yyvsp[-6]),(yyvsp[-4]),NULL,NULL);}
#line 2048 "y.tab.c" /* yacc.c:1663  */
    break;

  case 92:
#line 255 "exptree.y" /* yacc.c:1663  */
    {(yyvsp[-6])->nodetype = FIELD_NODE;
                                        (yyvsp[-6])->type=getType((yyvsp[-6])->varname,(yyvsp[-6])->type,(yyvsp[-6])->class,(yyvsp[-6])->left);
					(yyvsp[-4]) = makeNode(NEW_NODE,0,NULL,(yyvsp[-2]),NULL,NULL,NULL);
                                        ch = malloc(1);*ch = '=';
                                        (yyval)=makeNode(2,0,ch,(yyvsp[-6]),(yyvsp[-4]),NULL,NULL);
				       }
#line 2059 "y.tab.c" /* yacc.c:1663  */
    break;

  case 93:
#line 263 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(7,0,NULL,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]),NULL);}
#line 2065 "y.tab.c" /* yacc.c:1663  */
    break;

  case 94:
#line 264 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(6,0,NULL,(yyvsp[-5]),(yyvsp[-2]),NULL,NULL);}
#line 2071 "y.tab.c" /* yacc.c:1663  */
    break;

  case 95:
#line 266 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(8,0,NULL,(yyvsp[-5]),(yyvsp[-2]),NULL,NULL);}
#line 2077 "y.tab.c" /* yacc.c:1663  */
    break;

  case 96:
#line 269 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(9,0,NULL,NULL,NULL,NULL,NULL);}
#line 2083 "y.tab.c" /* yacc.c:1663  */
    break;

  case 97:
#line 272 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(10,0,NULL,NULL,NULL,NULL,NULL);}
#line 2089 "y.tab.c" /* yacc.c:1663  */
    break;

  case 98:
#line 275 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(11,0,NULL,(yyvsp[-5]),(yyvsp[-2]),NULL,NULL);}
#line 2095 "y.tab.c" /* yacc.c:1663  */
    break;

  case 99:
#line 276 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(11,0,NULL,(yyvsp[-5]),(yyvsp[-2]),NULL,NULL);}
#line 2101 "y.tab.c" /* yacc.c:1663  */
    break;

  case 100:
#line 278 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(RET_NODE,0,NULL,(yyvsp[-1]),NULL,NULL,NULL);}
#line 2107 "y.tab.c" /* yacc.c:1663  */
    break;

  case 101:
#line 281 "exptree.y" /* yacc.c:1663  */
    {(yyvsp[-2])=makeNode(1,0,(yyvsp[-2])->varname,NULL,NULL,NULL,NULL);
				     (yyval)=makeNode(FREE_NODE,0,NULL,(yyvsp[-2]),NULL,NULL,NULL);}
#line 2114 "y.tab.c" /* yacc.c:1663  */
    break;

  case 102:
#line 285 "exptree.y" /* yacc.c:1663  */
    {(yyvsp[-2])=makeNode(1,0,(yyvsp[-2])->varname,NULL,NULL,NULL,NULL);
				     (yyval)=makeNode(DELETE_NODE,0,NULL,(yyvsp[-2]),NULL,NULL,NULL);}
#line 2121 "y.tab.c" /* yacc.c:1663  */
    break;

  case 103:
#line 289 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(1,0,(yyvsp[-3])->varname,(yyvsp[-1]),NULL,NULL,NULL);(yyvsp[-3])=NULL;}
#line 2127 "y.tab.c" /* yacc.c:1663  */
    break;

  case 104:
#line 290 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(1,0,(yyvsp[-6])->varname,(yyvsp[-4]),(yyvsp[-1]),NULL,NULL);(yyvsp[-6])=NULL;}
#line 2133 "y.tab.c" /* yacc.c:1663  */
    break;

  case 105:
#line 293 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(1);*ch='+';(yyval)=makeNode(2,0,ch,(yyvsp[-2]),(yyvsp[0]),NULL,NULL);}
#line 2139 "y.tab.c" /* yacc.c:1663  */
    break;

  case 106:
#line 294 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(1);*ch='-';(yyval)=makeNode(2,0,ch,(yyvsp[-2]),(yyvsp[0]),NULL,NULL);}
#line 2145 "y.tab.c" /* yacc.c:1663  */
    break;

  case 107:
#line 295 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(1);*ch='*';(yyval)=makeNode(2,0,ch,(yyvsp[-2]),(yyvsp[0]),NULL,NULL);}
#line 2151 "y.tab.c" /* yacc.c:1663  */
    break;

  case 108:
#line 296 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(1);*ch='/';(yyval)=makeNode(2,0,ch,(yyvsp[-2]),(yyvsp[0]),NULL,NULL);}
#line 2157 "y.tab.c" /* yacc.c:1663  */
    break;

  case 109:
#line 297 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(1);*ch='%';(yyval)=makeNode(2,0,ch,(yyvsp[-2]),(yyvsp[0]),NULL,NULL);}
#line 2163 "y.tab.c" /* yacc.c:1663  */
    break;

  case 110:
#line 298 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[-1]);}
#line 2169 "y.tab.c" /* yacc.c:1663  */
    break;

  case 111:
#line 299 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 2175 "y.tab.c" /* yacc.c:1663  */
    break;

  case 112:
#line 300 "exptree.y" /* yacc.c:1663  */
    {(yyvsp[0])=makeNode(1,0,(yyvsp[0])->varname,NULL,NULL,NULL,NULL);(yyval)=(yyvsp[0]);}
#line 2181 "y.tab.c" /* yacc.c:1663  */
    break;

  case 113:
#line 301 "exptree.y" /* yacc.c:1663  */
    {(yyvsp[0])=makeNode(1,0,(yyvsp[0])->varname,NULL,NULL,NULL,NULL);(yyvsp[0])->nodetype=PTR_NODE;(yyval)=(yyvsp[0]);}
#line 2187 "y.tab.c" /* yacc.c:1663  */
    break;

  case 114:
#line 302 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 2193 "y.tab.c" /* yacc.c:1663  */
    break;

  case 115:
#line 303 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 2199 "y.tab.c" /* yacc.c:1663  */
    break;

  case 116:
#line 304 "exptree.y" /* yacc.c:1663  */
    {(yyvsp[0])->nodetype=FIELD_NODE;
			 (yyval)=(yyvsp[0]);
			 (yyval)->type=getType((yyvsp[0])->varname,(yyvsp[0])->type,(yyvsp[0])->class,(yyvsp[0])->left);}
#line 2207 "y.tab.c" /* yacc.c:1663  */
    break;

  case 117:
#line 307 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(NULL_NODE,0,NULL,NULL,NULL,NULL,NULL);}
#line 2213 "y.tab.c" /* yacc.c:1663  */
    break;

  case 118:
#line 308 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 2219 "y.tab.c" /* yacc.c:1663  */
    break;

  case 119:
#line 309 "exptree.y" /* yacc.c:1663  */
    {(yyval) = makeNode(FUNC_NODE,0,(yyvsp[-3])->varname,(yyvsp[-1]),NULL,NULL,NULL);(yyvsp[-3])=NULL;}
#line 2225 "y.tab.c" /* yacc.c:1663  */
    break;

  case 120:
#line 310 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(1);*ch='<';(yyval)=makeNode(2,0,ch,(yyvsp[-2]),(yyvsp[0]),NULL,NULL);}
#line 2231 "y.tab.c" /* yacc.c:1663  */
    break;

  case 121:
#line 311 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(1);*ch='>';(yyval)=makeNode(2,0,ch,(yyvsp[-2]),(yyvsp[0]),NULL,NULL);}
#line 2237 "y.tab.c" /* yacc.c:1663  */
    break;

  case 122:
#line 312 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(2);ch[0]='<';ch[1]= '=';(yyval)=makeNode(2,0,ch,(yyvsp[-2]),(yyvsp[0]),NULL,NULL);}
#line 2243 "y.tab.c" /* yacc.c:1663  */
    break;

  case 123:
#line 313 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(2);ch[0]='>';ch[1]= '=';(yyval)=makeNode(2,0,ch,(yyvsp[-2]),(yyvsp[0]),NULL,NULL);}
#line 2249 "y.tab.c" /* yacc.c:1663  */
    break;

  case 124:
#line 314 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(2);ch[0]='=';ch[1]= '=';(yyval)=makeNode(2,0,ch,(yyvsp[-2]),(yyvsp[0]),NULL,NULL);}
#line 2255 "y.tab.c" /* yacc.c:1663  */
    break;

  case 125:
#line 315 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(2);ch[0]='!';ch[1]= '=';(yyval)=makeNode(2,0,ch,(yyvsp[-2]),(yyvsp[0]),NULL,NULL);}
#line 2261 "y.tab.c" /* yacc.c:1663  */
    break;

  case 126:
#line 316 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(2);ch[0]='&';ch[1]= '&';(yyval)=makeNode(2,0,ch,(yyvsp[-2]),(yyvsp[0]),NULL,NULL);}
#line 2267 "y.tab.c" /* yacc.c:1663  */
    break;

  case 127:
#line 317 "exptree.y" /* yacc.c:1663  */
    {ch = malloc(2);ch[0]='|';ch[1]= '|';(yyval)=makeNode(2,0,ch,(yyvsp[-2]),(yyvsp[0]),NULL,NULL);}
#line 2273 "y.tab.c" /* yacc.c:1663  */
    break;

  case 128:
#line 320 "exptree.y" /* yacc.c:1663  */
    {(yyvsp[-2])->third=(yyvsp[0]);(yyval)=(yyvsp[-2]);}
#line 2279 "y.tab.c" /* yacc.c:1663  */
    break;

  case 129:
#line 321 "exptree.y" /* yacc.c:1663  */
    {(yyval)=(yyvsp[0]);}
#line 2285 "y.tab.c" /* yacc.c:1663  */
    break;

  case 130:
#line 322 "exptree.y" /* yacc.c:1663  */
    {(yyval)=NULL;}
#line 2291 "y.tab.c" /* yacc.c:1663  */
    break;

  case 131:
#line 325 "exptree.y" /* yacc.c:1663  */
    {(yyval)=makeNode(1,0,(yyvsp[0])->varname,(yyvsp[0])->left,NULL,NULL,NULL);}
#line 2297 "y.tab.c" /* yacc.c:1663  */
    break;

  case 132:
#line 326 "exptree.y" /* yacc.c:1663  */
    {(yyvsp[-2])=makeNode(SELF_NODE,0,"self",(yyvsp[0]),NULL,NULL,NULL);
				 (yyval)=(yyvsp[-2]);}
#line 2304 "y.tab.c" /* yacc.c:1663  */
    break;

  case 133:
#line 328 "exptree.y" /* yacc.c:1663  */
    {(yyval) = makeNode(SELF_NODE,0,"self",(yyvsp[0]),NULL,NULL,NULL);}
#line 2310 "y.tab.c" /* yacc.c:1663  */
    break;

  case 134:
#line 331 "exptree.y" /* yacc.c:1663  */
    {(yyval) = makeNode(SELF_NODE,0,"self",(yyvsp[-3]),(yyvsp[-1]),NULL,NULL);
							 (yyval)->nodetype = FIELDFUNC_NODE;
							 (yyval)->type = getFuncType("self",(yyval)->class,(yyvsp[-3]));}
#line 2318 "y.tab.c" /* yacc.c:1663  */
    break;

  case 135:
#line 334 "exptree.y" /* yacc.c:1663  */
    {(yyval) = makeNode(SELF_NODE,0,"self",(yyvsp[-3]),(yyvsp[-1]),NULL,NULL);
                                                         (yyval)->nodetype = FIELDFUNC_NODE;
                                                         (yyval)->type = getFuncType("self",(yyval)->class,(yyvsp[-3]));}
#line 2326 "y.tab.c" /* yacc.c:1663  */
    break;

  case 136:
#line 338 "exptree.y" /* yacc.c:1663  */
    {(yyval) = makeNode(1,0,(yyvsp[-5])->varname,(yyvsp[-3]),(yyvsp[-1]),NULL,NULL);
                                                         (yyval)->nodetype = FIELDFUNC_NODE;
							 (yyval)->type = getFuncType((yyvsp[-5])->varname,(yyval)->class,(yyvsp[-3]));}
#line 2334 "y.tab.c" /* yacc.c:1663  */
    break;

  case 137:
#line 342 "exptree.y" /* yacc.c:1663  */
    {(yyval) = makeNode(1,0,(yyvsp[-5])->varname,(yyvsp[-3]),(yyvsp[-1]),NULL,NULL);
                                                         (yyval)->nodetype = FIELDFUNC_NODE;
                                                         (yyval)->type = getFuncType((yyvsp[-5])->varname,(yyval)->class,(yyvsp[-3]));}
#line 2342 "y.tab.c" /* yacc.c:1663  */
    break;

  case 138:
#line 347 "exptree.y" /* yacc.c:1663  */
    {(yyvsp[-2])->left = (yyvsp[0]);(yyval)=(yyvsp[-2]);}
#line 2348 "y.tab.c" /* yacc.c:1663  */
    break;

  case 139:
#line 348 "exptree.y" /* yacc.c:1663  */
    {(yyvsp[-2])->left = (yyvsp[0]);(yyvsp[0])->left=NULL;(yyval)=(yyvsp[-2]);}
#line 2354 "y.tab.c" /* yacc.c:1663  */
    break;


#line 2358 "y.tab.c" /* yacc.c:1663  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  return yyresult;
}
#line 349 "exptree.y" /* yacc.c:1907  */


int yyerror()
{
    printf("LINE %d : Syntax error\n",line);
    return 0;
}

int main(int argc,char* argv[])
{
    FILE* fp = fopen(argv[1],"r");
    yyin = fp;
    yyparse();
    return 1;
}
