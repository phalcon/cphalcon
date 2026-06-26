/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
#line 31 "parser.php.lemon"

#include "parser.php.inc.h"

#line 12 "parser.php.c"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/*
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands.
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    phql_TOKENTYPE     is the data type used for minor tokens given
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is phql_TOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.
**    phql_ARG_SDECL     A static variable declaration for the %extra_argument
**    phql_ARG_PDECL     A parameter declaration for the %extra_argument
**    phql_ARG_STORE     Code to store %extra_argument into yypParser
**    phql_ARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 154
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval yy170;
  int yy307;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 346
#define YYNRULE 186
#define YYERRORSYMBOL 91
#define YYERRSYMDT yy307
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* Next are that tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
static YYACTIONTYPE yy_action[] = {
 /*     0 */   109,  115,  117,   78,   80,   82,   84,   86,   88,   60,
 /*    10 */    62,   64,   66,   50,   52,   90,   95,   54,   56,   58,
 /*    20 */    46,   44,   48,   42,   39,   68,  111,   97,   92,  136,
 /*    30 */    70,   72,   74,   76,   50,   52,   90,   95,   54,   56,
 /*    40 */    58,   46,   44,   48,   42,   39,   68,  111,   97,   92,
 /*    50 */   135,   70,   72,   74,   76,  111,   97,   92,  346,   70,
 /*    60 */    72,   74,   76,  347,   37,   38,  109,  115,  117,   78,
 /*    70 */    80,   82,   84,   86,   88,   60,   62,   64,   66,   50,
 /*    80 */    52,   90,   95,   54,   56,   58,   46,   44,   48,   42,
 /*    90 */    39,   68,  111,   97,   92,  348,   70,   72,   74,   76,
 /*   100 */   109,  115,  117,   78,   80,   82,   84,   86,   88,   60,
 /*   110 */    62,   64,   66,   50,   52,   90,   95,   54,   56,   58,
 /*   120 */    46,   44,   48,   42,   39,   68,  111,   97,   92,  120,
 /*   130 */    70,   72,   74,   76,   24,   25,   26,   27,   28,  349,
 /*   140 */   271,   92,  269,   70,   72,   74,   76,  242,  205,  240,
 /*   150 */   237,  166,  109,  115,  117,   78,   80,   82,   84,   86,
 /*   160 */    88,   60,   62,   64,   66,   50,   52,   90,   95,   54,
 /*   170 */    56,   58,   46,   44,   48,   42,   39,   68,  111,   97,
 /*   180 */    92,  350,   70,   72,   74,   76,    7,  243,  259,  245,
 /*   190 */   247,    9,  251,  255,  191,  304,  109,  115,  117,   78,
 /*   200 */    80,   82,   84,   86,   88,   60,   62,   64,   66,   50,
 /*   210 */    52,   90,   95,   54,   56,   58,   46,   44,   48,   42,
 /*   220 */    39,   68,  111,   97,   92,    8,   70,   72,   74,   76,
 /*   230 */   109,  115,  117,   78,   80,   82,   84,   86,   88,   60,
 /*   240 */    62,   64,   66,   50,   52,   90,   95,   54,   56,   58,
 /*   250 */    46,   44,   48,   42,   39,   68,  111,   97,   92,  303,
 /*   260 */    70,   72,   74,   76,   42,   39,   68,  111,   97,   92,
 /*   270 */    22,   70,   72,   74,   76,  197,  113,  109,  115,  117,
 /*   280 */    78,   80,   82,   84,   86,   88,   60,   62,   64,   66,
 /*   290 */    50,   52,   90,   95,   54,   56,   58,   46,   44,   48,
 /*   300 */    42,   39,   68,  111,   97,   92,   29,   70,   72,   74,
 /*   310 */    76,  170,  138,  207,   54,   56,   58,   46,   44,   48,
 /*   320 */    42,   39,   68,  111,   97,   92,  133,   70,   72,   74,
 /*   330 */    76,  183,  276,  112,  109,  115,  117,   78,   80,   82,
 /*   340 */    84,   86,   88,   60,   62,   64,   66,   50,   52,   90,
 /*   350 */    95,   54,   56,   58,   46,   44,   48,   42,   39,   68,
 /*   360 */   111,   97,   92,   10,   70,   72,   74,   76,  286,   78,
 /*   370 */    80,   82,   84,   86,   88,   60,   62,   64,   66,   50,
 /*   380 */    52,   90,   95,   54,   56,   58,   46,   44,   48,   42,
 /*   390 */    39,   68,  111,   97,   92,   12,   70,   72,   74,   76,
 /*   400 */   219,  203,  205,   40,  237,  277,  213,  220,  222,    6,
 /*   410 */   274,   11,  302,  273,   11,  136,  120,  279,   99,  210,
 /*   420 */   126,   99,  139,  134,  224,  138,  275,  120,  267,  243,
 /*   430 */   259,  245,  247,  119,  251,  255,  144,  216,  166,  142,
 /*   440 */   209,  305,  214,  235,  224,   36,  328,  154,  343,  166,
 /*   450 */   225,  226,  232,  233,  234,  164,  188,  194,   13,  200,
 /*   460 */   209,  139,  143,  224,  229,  227,  228,  230,  231,   14,
 /*   470 */   262,   33,  301,  314,  123,  284,   40,  139,  148,  209,
 /*   480 */   220,  222,  310,  122,  186,  315,  272,  268,    6,  120,
 /*   490 */    11,  224,  210,  224,  140,  290,  129,   99,  159,    6,
 /*   500 */   107,   11,   31,  281,  285,  224,  119,  209,   99,  209,
 /*   510 */   151,  166,  219,  146,  168,   40,  213,  421,  206,  220,
 /*   520 */   222,  209,   15,  225,  226,  232,  233,  234,  164,  188,
 /*   530 */   194,  210,  200,   20,  224,  138,  224,  229,  227,  228,
 /*   540 */   230,  231,   16,   93,  292,  119,  507,  288,   17,  147,
 /*   550 */   209,  264,  209,  235,   40,  294,  202,  239,  220,  222,
 /*   560 */   167,  185,  225,  226,  232,  233,  234,  164,  188,  194,
 /*   570 */   265,  200,  156,  157,  158,   18,  229,  227,  228,  230,
 /*   580 */   231,  332,  339,  335,  119,   19,  243,  259,  245,  247,
 /*   590 */   219,  251,  255,   40,   21,   36,  213,  220,  222,   32,
 /*   600 */   374,  225,  226,  232,  233,  234,  164,  188,  194,  210,
 /*   610 */   200,  184,  185,  224,  224,  229,  227,  228,  230,  231,
 /*   620 */   125,  153,   35,  119,  155,  260,  157,  158,   23,  209,
 /*   630 */   209,  136,   40,  218,  211,  177,  220,  222,  182,  307,
 /*   640 */   225,  226,  232,  233,  234,  164,  188,  194,  210,  200,
 /*   650 */   168,  151,  149,  422,  229,  227,  228,  230,  231,  308,
 /*   660 */   316,   30,  119,   46,   44,   48,   42,   39,   68,  111,
 /*   670 */    97,   92,  127,   70,   72,   74,   76,  128,   34,  225,
 /*   680 */   226,  232,  233,  234,  164,  188,  194,  317,  200,  151,
 /*   690 */   182,  178,  120,  229,  227,  228,  230,  231,   90,   95,
 /*   700 */    54,   56,   58,   46,   44,   48,   42,   39,   68,  111,
 /*   710 */    97,   92,  181,   70,   72,   74,   76,  330,   98,  334,
 /*   720 */   335,  155,  260,  157,  158,  533,    1,    2,    3,    4,
 /*   730 */     5,    6,  298,   11,  102,  100,    6,  124,   11,  314,
 /*   740 */    99,  261,  427,  174,  103,   99,  128,    6,  321,   11,
 /*   750 */   329,  315,  284,  213,  176,  128,   99,  224,  151,  263,
 /*   760 */   268,  338,  323,  250,  452,  314,  248,  151,  340,  254,
 /*   770 */   224,  224,  252,  209,  300,  104,  101,  313,  224,  224,
 /*   780 */   337,  283,   41,  224,  296,   43,  209,  209,  345,   45,
 /*   790 */   235,   47,  224,  128,  209,  209,   49,  217,  258,  209,
 /*   800 */   224,  256,   51,  224,   53,  151,  105,  224,  209,  224,
 /*   810 */    55,   57,  152,   59,  224,   61,  209,   63,  506,  209,
 /*   820 */   224,   65,  224,  209,   67,  209,  106,  266,  224,  224,
 /*   830 */   209,  224,   69,  224,  326,  224,  209,  114,  209,  224,
 /*   840 */   211,   71,  224,   73,  209,  209,   75,  209,  130,  209,
 /*   850 */   224,  209,   77,   79,   81,  209,   83,  121,  209,  224,
 /*   860 */   138,  224,  131,   85,  224,   87,  209,   89,  217,  132,
 /*   870 */   224,  224,  224,   91,  224,  209,   94,  209,   96,  217,
 /*   880 */   209,  224,  137,  224,  108,  224,  209,  209,  209,  289,
 /*   890 */   209,  224,  141,  110,  224,  116,  224,  209,  118,  209,
 /*   900 */   297,  209,  224,  163,  145,  190,  196,  209,  201,  150,
 /*   910 */   209,  224,  209,  224,  153,  208,  224,  154,  209,  160,
 /*   920 */   221,  224,  162,  224,  224,  223,  224,  209,  165,  209,
 /*   930 */   238,  312,  209,  224,  178,  287,  312,  209,  224,  209,
 /*   940 */   209,  161,  209,  224,  293,  170,  171,  169,  224,  209,
 /*   950 */   172,  175,  311,  224,  209,  318,  180,  322,  173,  209,
 /*   960 */   426,  187,  224,  179,  209,  189,  192,  193,  195,  209,
 /*   970 */   198,  204,  199,  236,  212,  215,  241,  244,  209,  382,
 /*   980 */   383,  246,  249,  384,  385,  253,  386,  387,  388,  257,
 /*   990 */   389,  390,  270,  282,  280,  393,  394,  278,  324,  325,
 /*  1000 */   401,  327,  451,  333,  291,  336,  407,  295,  306,  299,
 /*  1010 */   341,  309,  320,  319,  342,  344,  341,  341,  331,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   35,
 /*    30 */    31,   32,   33,   34,   14,   15,   16,   17,   18,   19,
 /*    40 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*    50 */    56,   31,   32,   33,   34,   27,   28,   29,    0,   31,
 /*    60 */    32,   33,   34,    0,   65,   66,    1,    2,    3,    4,
 /*    70 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*    80 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*    90 */    25,   26,   27,   28,   29,    0,   31,   32,   33,   34,
 /*   100 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   110 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   120 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   38,
 /*   130 */    31,   32,   33,   34,   72,   73,   74,   75,   76,    0,
 /*   140 */    41,   29,   43,   31,   32,   33,   34,   41,   83,   43,
 /*   150 */    85,   60,    1,    2,    3,    4,    5,    6,    7,    8,
 /*   160 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   170 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   180 */    29,    0,   31,   32,   33,   34,   99,   44,   45,   46,
 /*   190 */    47,   36,   49,   50,   43,  108,    1,    2,    3,    4,
 /*   200 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   210 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   220 */    25,   26,   27,   28,   29,  108,   31,   32,   33,   34,
 /*   230 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   240 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   250 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   37,
 /*   260 */    31,   32,   33,   34,   24,   25,   26,   27,   28,   29,
 /*   270 */    35,   31,   32,   33,   34,   80,   29,    1,    2,    3,
 /*   280 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   290 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   300 */    24,   25,   26,   27,   28,   29,   71,   31,   32,   33,
 /*   310 */    34,   41,   41,   84,   18,   19,   20,   21,   22,   23,
 /*   320 */    24,   25,   26,   27,   28,   29,   55,   31,   32,   33,
 /*   330 */    34,   61,   56,   86,    1,    2,    3,    4,    5,    6,
 /*   340 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   350 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   360 */    27,   28,   29,  109,   31,   32,   33,   34,   62,    4,
 /*   370 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   380 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   390 */    25,   26,   27,   28,   29,  101,   31,   32,   33,   34,
 /*   400 */    22,   82,   83,   25,   85,   94,  115,   29,   30,   98,
 /*   410 */    37,  100,   98,   40,  100,   35,   38,   67,  107,   41,
 /*   420 */    35,  107,  136,  137,  133,   41,  115,   38,   22,   44,
 /*   430 */    45,   46,   47,   55,   49,   50,   56,  146,   60,   55,
 /*   440 */   149,   52,  151,  152,  133,  115,   57,   41,   59,   60,
 /*   450 */    72,   73,   74,   75,   76,   77,   78,   79,  102,   81,
 /*   460 */   149,  136,  137,  133,   86,   87,   88,   89,   90,  103,
 /*   470 */    35,  141,  142,  115,   39,  115,   25,  136,  137,  149,
 /*   480 */    29,   30,  124,  111,   94,  127,  114,  115,   98,   38,
 /*   490 */   100,  133,   41,  133,   41,   94,   43,  107,  121,   98,
 /*   500 */    68,  100,   63,  143,  144,  133,   55,  149,  107,  149,
 /*   510 */   133,   60,   22,   60,   35,   25,  115,   38,  115,   29,
 /*   520 */    30,  149,  104,   72,   73,   74,   75,   76,   77,   78,
 /*   530 */    79,   41,   81,   70,  133,   41,  133,   86,   87,   88,
 /*   540 */    89,   90,  105,   16,   17,   55,   56,  146,  106,   55,
 /*   550 */   149,   22,  149,  152,   25,   28,  147,  148,   29,   30,
 /*   560 */   138,  139,   72,   73,   74,   75,   76,   77,   78,   79,
 /*   570 */    41,   81,  118,  119,  120,   69,   86,   87,   88,   89,
 /*   580 */    90,  131,  132,  133,   55,   57,   44,   45,   46,   47,
 /*   590 */    22,   49,   50,   25,  145,  115,  115,   29,   30,   64,
 /*   600 */    58,   72,   73,   74,   75,   76,   77,   78,   79,   41,
 /*   610 */    81,  138,  139,  133,  133,   86,   87,   88,   89,   90,
 /*   620 */   113,   42,  142,   55,  117,  118,  119,  120,  145,  149,
 /*   630 */   149,   35,   25,  152,   55,  125,   29,   30,  128,  121,
 /*   640 */    72,   73,   74,   75,   76,   77,   78,   79,   41,   81,
 /*   650 */    35,  133,   56,   38,   86,   87,   88,   89,   90,   54,
 /*   660 */    55,  145,   55,   21,   22,   23,   24,   25,   26,   27,
 /*   670 */    28,   29,  116,   31,   32,   33,   34,  121,   35,   72,
 /*   680 */    73,   74,   75,   76,   77,   78,   79,  125,   81,  133,
 /*   690 */   128,   35,   38,   86,   87,   88,   89,   90,   16,   17,
 /*   700 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   710 */    28,   29,   56,   31,   32,   33,   34,  113,   55,  132,
 /*   720 */   133,  117,  118,  119,  120,   92,   93,   94,   95,   96,
 /*   730 */    97,   98,   94,  100,  102,  100,   98,  112,  100,  115,
 /*   740 */   107,  116,   43,   94,  103,  107,  121,   98,  124,  100,
 /*   750 */   116,  127,  115,  115,   55,  121,  107,  133,  133,  114,
 /*   760 */   115,  115,  129,   45,    0,  115,   48,  133,  135,   45,
 /*   770 */   133,  133,   48,  149,  115,  104,  101,  127,  133,  133,
 /*   780 */   134,  144,  115,  133,  146,  115,  149,  149,  116,  115,
 /*   790 */   152,  115,  133,  121,  149,  149,  115,   35,   45,  149,
 /*   800 */   133,   48,  115,  133,  115,  133,  105,  133,  149,  133,
 /*   810 */   115,  115,   41,  115,  133,  115,  149,  115,   56,  149,
 /*   820 */   133,  115,  133,  149,  115,  149,  106,   42,  133,  133,
 /*   830 */   149,  133,  115,  133,   70,  133,  149,   86,  149,  133,
 /*   840 */    55,  115,  133,  115,  149,  149,  115,  149,   41,  149,
 /*   850 */   133,  149,  115,  115,  115,  149,  115,  110,  149,  133,
 /*   860 */    41,  133,   60,  115,  133,  115,  149,  115,   35,  136,
 /*   870 */   133,  133,  133,  115,  133,  149,  115,  149,  115,   35,
 /*   880 */   149,  133,  136,  133,  115,  133,  149,  149,  149,   56,
 /*   890 */   149,  133,   60,  115,  133,  115,  133,  149,  115,  149,
 /*   900 */    56,  149,  133,  115,  136,  115,  115,  149,  115,  136,
 /*   910 */   149,  133,  149,  133,   42,  115,  133,   41,  149,  122,
 /*   920 */   115,  133,   51,  133,  133,  115,  133,  149,   55,  149,
 /*   930 */   115,   35,  149,  133,   35,  115,   35,  149,  133,  149,
 /*   940 */   149,  123,  149,  133,  115,   41,  140,  139,  133,  149,
 /*   950 */    43,   56,   56,  133,  149,   56,   41,   56,   55,  149,
 /*   960 */    43,   56,  133,  128,  149,   55,   41,   56,   55,  149,
 /*   970 */    41,  148,   56,   40,  150,   56,   41,   45,  149,   41,
 /*   980 */    41,   45,   45,   41,   41,   45,   41,   41,   41,   45,
 /*   990 */    41,   41,   41,   35,   64,    0,    0,   56,  101,  130,
 /*  1000 */     0,  145,    0,   35,   56,    4,    0,   55,   53,   56,
 /*  1010 */   101,   55,   55,   54,  130,   39,  153,  153,   58,
};
#define YY_SHIFT_USE_DFLT (-7)
static short yy_shift_ofst[] = {
 /*     0 */   389,   58,   63,   95,  139,  181,  155,  155,   -7,  222,
 /*    10 */    91,  306,  350,  432,  439,  463,  506,   -7,  528,   -7,
 /*    20 */    62,  235,   62,   -7,   -7,   -7,   -7,   -7,   -7,   62,
 /*    30 */    -7,  535,  607,  643,  607,   -7,   -1,   -7,   -7,  607,
 /*    40 */   607,   28,  607,   28,  607,  240,  607,  240,  607,  240,
 /*    50 */   607,  682,  607,  682,  607,  642,  607,  642,  607,  642,
 /*    60 */   607,   20,  607,   20,  607,   20,  607,   20,  607,   28,
 /*    70 */   607,   -7,  607,   -7,  607,   -7,  607,   -7,  607,   20,
 /*    80 */   607,   20,  607,   20,  607,   20,  607,   20,  607,   20,
 /*    90 */   607,  296,  527,  607,  112,  607,  296,  663,  378,  654,
 /*   100 */   306,  350,  432,  439,  463,  506,   -7,  607,  333,  607,
 /*   110 */   333,  247,   -7,  751,   -7,  607,  365,  607,  365,  451,
 /*   120 */   373,  529,  435,  771,  385,   -7,  771,   -7,  453,  807,
 /*   130 */   802,  271,   -7,  819,   -6,   -7,  819,   -7,   -7,   -7,
 /*   140 */   832,  384,  819,  380,   -7,   -7,  494,  819,  596,   -7,
 /*   150 */    -7,   -7,  872,  876,   -7,  143,   -7,   -7,  771,  106,
 /*   160 */   871,   -7,  607,  333,  873,   91,  270,  479,  904,   -7,
 /*   170 */   699,  907,  903,   91,  895,   -7,  915,  656,  915,   -7,
 /*   180 */    -7,  917,   -7,  904,  615,   -7,  905,   -7,  910,  607,
 /*   190 */   151,  925,  911,   -7,  913,  607,  195,  929,  916,   -7,
 /*   200 */   607,   65,  319,   -7,   -7,  607,  229,  607,  333,   -7,
 /*   210 */   579,  933,  490,  333,  919,   -7,  762,  568,   -7,   -7,
 /*   220 */   607,  112,  607,  112,   -7,   -7,   -7,   -7,   -7,   -7,
 /*   230 */    -7,   -7,   -7,   -7,   -7,   -7,   -7,  607,  333,   -7,
 /*   240 */   935,   -7,   -7,  932,  938,  936,  939,  718,  937,  942,
 /*   250 */   943,  724,  940,  945,  946,  753,  944,  947,  949,  950,
 /*   260 */    -7,   -7,  529,   -7,   -7,  785,  406,   -7,   99,  951,
 /*   270 */    -7,   -7,   -7,   -7,   -7,  276,   -7,  941,   -7,  930,
 /*   280 */   607,  958,  607,   -7,  333,   -7,  607,  333,  833,   -7,
 /*   290 */   948,   -7,  607,  112,  952,  378,  844,   -7,  953,   -7,
 /*   300 */    28,   -7,   -7,   -7,   -7,  955,  771,  605,  956,  607,
 /*   310 */   896,  995,  607,   -7,  333,   -7,  915,  899,  959,  957,
 /*   320 */   607,  901,  996,  306,  764, 1000,   62, 1002,  771,  542,
 /*   330 */   960,  771,  968,  771,   -7, 1001,  607,   -7,  333,   -7,
 /*   340 */   306,  764, 1006,  976,  771,   -7,
};
#define YY_REDUCE_USE_DFLT (-1)
static short yy_reduce_ofst[] = {
 /*     0 */   633,   -1,   -1,   -1,   -1,   -1,   87,  117,   -1,  254,
 /*    10 */   314,  294,  356,  366,  418,  437,  442,   -1,   -1,   -1,
 /*    20 */   449,   -1,  483,   -1,   -1,   -1,   -1,   -1,   -1,  516,
 /*    30 */    -1,   -1,  330,   -1,  480,   -1,   -1,   -1,   -1,  659,
 /*    40 */   667,   -1,  670,   -1,  674,   -1,  676,   -1,  681,   -1,
 /*    50 */   687,   -1,  689,   -1,  695,   -1,  696,   -1,  698,   -1,
 /*    60 */   700,   -1,  702,   -1,  706,   -1,  709,   -1,  717,   -1,
 /*    70 */   726,   -1,  728,   -1,  731,   -1,  737,   -1,  738,   -1,
 /*    80 */   739,   -1,  741,   -1,  748,   -1,  750,   -1,  752,   -1,
 /*    90 */   758,   -1,   -1,  761,   -1,  763,   -1,   -1,  401,  635,
 /*   100 */   675,  632,  641,  671,  701,  720,   -1,  769,   -1,  778,
 /*   110 */    -1,   -1,   -1,   -1,   -1,  780,   -1,  783,   -1,  311,
 /*   120 */   747,  372,   -1,  625,  507,   -1,  556,   -1,   -1,   -1,
 /*   130 */    -1,  733,   -1,  286,   -1,   -1,  746,   -1,   -1,   -1,
 /*   140 */    -1,  768,  325,   -1,   -1,   -1,  773,  341,   -1,   -1,
 /*   150 */    -1,   -1,   -1,   -1,   -1,  454,   -1,   -1,  377,  797,
 /*   160 */   818,   -1,  788,   -1,   -1,  390,  422,   -1,  808,   -1,
 /*   170 */   806,   -1,   -1,  649,   -1,   -1,  510,   -1,  835,   -1,
 /*   180 */    -1,   -1,   -1,  473,   -1,   -1,   -1,   -1,   -1,  790,
 /*   190 */    -1,   -1,   -1,   -1,   -1,  791,   -1,   -1,   -1,   -1,
 /*   200 */   793,  409,  823,   -1,   -1,  403,   -1,  800,   -1,   -1,
 /*   210 */    -1,  824,  291,   -1,   -1,   -1,   -1,  481,   -1,   -1,
 /*   220 */   805,   -1,  810,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   230 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,  815,   -1,   -1,
 /*   240 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   250 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   260 */    -1,   -1,  645,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   270 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   280 */   360,   -1,  637,   -1,   -1,   -1,  820,   -1,   -1,   -1,
 /*   290 */    -1,   -1,  829,   -1,   -1,  638,   -1,   -1,   -1,   -1,
 /*   300 */    -1,   -1,   -1,   -1,   -1,   -1,  518,   -1,   -1,  358,
 /*   310 */    -1,   -1,  650,   -1,   -1,   -1,  562,   -1,   -1,   -1,
 /*   320 */   624,   -1,   -1,  897,  869,   -1,  856,   -1,  634,  604,
 /*   330 */    -1,  450,   -1,  587,   -1,   -1,  646,   -1,   -1,   -1,
 /*   340 */   909,  884,   -1,   -1,  672,   -1,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   532,  532,  532,  532,  532,  532,  351,  352,  355,  359,
 /*    10 */   532,  430,  439,  444,  432,  450,  446,  353,  532,  445,
 /*    20 */   532,  447,  532,  448,  453,  454,  455,  456,  457,  532,
 /*    30 */   449,  532,  532,  431,  532,  433,  435,  436,  437,  532,
 /*    40 */   532,  458,  532,  460,  532,  461,  532,  462,  532,  463,
 /*    50 */   532,  464,  532,  465,  532,  466,  532,  467,  532,  468,
 /*    60 */   532,  469,  532,  470,  532,  471,  532,  472,  532,  473,
 /*    70 */   532,  474,  532,  475,  532,  476,  532,  477,  532,  478,
 /*    80 */   532,  479,  532,  480,  532,  481,  532,  482,  532,  483,
 /*    90 */   532,  484,  532,  532,  485,  532,  486,  532,  532,  532,
 /*   100 */   430,  439,  444,  432,  450,  446,  354,  532,  443,  532,
 /*   110 */   494,  532,  512,  532,  513,  532,  514,  532,  515,  532,
 /*   120 */   363,  532,  532,  532,  374,  360,  532,  371,  411,  532,
 /*   130 */   409,  532,  412,  532,  532,  413,  532,  418,  420,  419,
 /*   140 */   410,  532,  532,  532,  414,  415,  532,  532,  532,  416,
 /*   150 */   417,  428,  531,  532,  530,  373,  375,  377,  532,  381,
 /*   160 */   392,  378,  532,  391,  532,  532,  532,  532,  532,  423,
 /*   170 */   532,  532,  532,  532,  532,  425,  532,  532,  532,  398,
 /*   180 */   400,  532,  399,  532,  532,  424,  532,  493,  532,  532,
 /*   190 */   532,  532,  532,  495,  532,  532,  532,  532,  532,  496,
 /*   200 */   532,  532,  532,  497,  498,  532,  532,  532,  500,  502,
 /*   210 */   531,  505,  532,  511,  532,  503,  532,  532,  508,  510,
 /*   220 */   532,  516,  532,  517,  519,  520,  521,  522,  523,  524,
 /*   230 */   525,  526,  527,  528,  529,  509,  504,  532,  501,  499,
 /*   240 */   532,  379,  380,  532,  532,  532,  532,  532,  532,  532,
 /*   250 */   532,  532,  532,  532,  532,  532,  532,  532,  532,  532,
 /*   260 */   376,  372,  532,  364,  366,  531,  532,  367,  370,  532,
 /*   270 */   368,  369,  365,  361,  362,  532,  518,  532,  490,  532,
 /*   280 */   532,  438,  532,  440,  442,  441,  532,  429,  532,  488,
 /*   290 */   532,  491,  532,  487,  532,  532,  532,  489,  532,  492,
 /*   300 */   459,  434,  357,  358,  356,  532,  532,  532,  532,  532,
 /*   310 */   532,  532,  532,  395,  397,  396,  532,  532,  532,  532,
 /*   320 */   532,  532,  532,  430,  532,  532,  532,  532,  532,  532,
 /*   330 */   532,  532,  402,  532,  403,  532,  532,  405,  406,  404,
 /*   340 */   430,  532,  532,  532,  532,  408,
};
#define YY_SZ_ACTTAB (sizeof(yy_action)/sizeof(yy_action[0]))

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
**
**      %fallback ID X Y Z.
**
** appears in the grammer, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  int stateno;       /* The state-number */
  int major;         /* The major token value.  This is the code
                     ** number for the token at this stack level */
  YYMINORTYPE minor; /* The user-supplied minor token value.  This
                     ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
  int yyerrcnt;                 /* Shifts left before out of the error */
  phql_ARG_SDECL                /* A place to hold %extra_argument */
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/*
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void phql_Trace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *yyTokenName[] = {
  "$",             "AGAINST",       "BETWEEN",       "BETWEEN_NOT",
  "EQUALS",        "NOTEQUALS",     "LESS",          "GREATER",
  "GREATEREQUAL",  "LESSEQUAL",     "OP_MATCHES",    "OP_CONTAINS",
  "OP_CONTAINED",  "OP_OVERLAPS",   "AND",           "OR",
  "LIKE",          "ILIKE",         "BITWISE_AND",   "BITWISE_OR",
  "BITWISE_XOR",   "DIVIDE",        "TIMES",         "MOD",
  "PLUS",          "MINUS",         "OP_CONCAT",     "IS",
  "IN",            "NOT",           "BITWISE_NOT",   "OP_JSON_GET",
  "OP_JSON_GET_TEXT",  "OP_JSON_PATH",  "OP_JSON_PATH_TEXT",  "COMMA",
  "UNION",         "ALL",           "SELECT",        "FROM",
  "DISTINCT",      "IDENTIFIER",    "DOT",           "AS",
  "INNER",         "JOIN",          "CROSS",         "LEFT",
  "OUTER",         "RIGHT",         "FULL",          "ON",
  "INSERT",        "INTO",          "VALUES",        "PARENTHESES_OPEN",
  "PARENTHESES_CLOSE",  "UPDATE",        "SET",           "DELETE",
  "WITH",          "RECURSIVE",     "WHERE",         "ORDER",
  "BY",            "ASC",           "DESC",          "GROUP",
  "HAVING",        "FOR",           "LIMIT",         "OFFSET",
  "INTEGER",       "HINTEGER",      "NPLACEHOLDER",  "SPLACEHOLDER",
  "BPLACEHOLDER",  "EXISTS",        "CAST",          "CONVERT",
  "USING",         "CASE",          "END",           "WHEN",
  "THEN",          "ELSE",          "NULL",          "STRING",
  "DOUBLE",        "TRUE",          "FALSE",         "error",
  "program",       "query_language",  "select_statement",  "insert_statement",
  "update_statement",  "delete_statement",  "select_base_statement",  "union_list",
  "select_clause",  "where_clause",  "group_clause",  "having_clause",
  "order_clause",  "select_limit_clause",  "for_update_clause",  "with_clause",
  "union_item",    "union_all",     "distinct_all",  "column_list",
  "associated_name_list",  "join_list_or_null",  "column_item",   "expr",
  "associated_name",  "join_list",     "join_item",     "join_clause",
  "join_type",     "aliased_or_qualified_name",  "join_associated_name",  "join_conditions",
  "values_list",   "field_list",    "value_list",    "value_item",
  "field_item",    "update_clause",  "limit_clause",  "update_item_list",
  "update_item",   "qualified_name",  "new_value",     "delete_clause",
  "with_item",     "with_list",     "cte_list",      "cte_item",
  "cte_column_list",  "order_list",    "order_item",    "group_list",
  "group_item",    "integer_or_placeholder",  "argument_list",  "when_clauses",
  "when_clause",   "function_call",  "distinct_or_null",  "argument_list_or_null",
  "argument_item",
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *yyRuleName[] = {
 /*   0 */ "program ::= query_language",
 /*   1 */ "query_language ::= select_statement",
 /*   2 */ "query_language ::= insert_statement",
 /*   3 */ "query_language ::= update_statement",
 /*   4 */ "query_language ::= delete_statement",
 /*   5 */ "select_statement ::= select_base_statement",
 /*   6 */ "select_statement ::= select_base_statement union_list",
 /*   7 */ "select_base_statement ::= select_clause where_clause group_clause having_clause order_clause select_limit_clause for_update_clause",
 /*   8 */ "select_base_statement ::= with_clause select_clause where_clause group_clause having_clause order_clause select_limit_clause for_update_clause",
 /*   9 */ "union_list ::= union_list union_item",
 /*  10 */ "union_list ::= union_item",
 /*  11 */ "union_item ::= UNION union_all select_base_statement",
 /*  12 */ "union_all ::= ALL",
 /*  13 */ "union_all ::=",
 /*  14 */ "select_clause ::= SELECT distinct_all column_list FROM associated_name_list join_list_or_null",
 /*  15 */ "distinct_all ::= DISTINCT",
 /*  16 */ "distinct_all ::= ALL",
 /*  17 */ "distinct_all ::=",
 /*  18 */ "column_list ::= column_list COMMA column_item",
 /*  19 */ "column_list ::= column_item",
 /*  20 */ "column_item ::= TIMES",
 /*  21 */ "column_item ::= IDENTIFIER DOT TIMES",
 /*  22 */ "column_item ::= expr AS IDENTIFIER",
 /*  23 */ "column_item ::= expr IDENTIFIER",
 /*  24 */ "column_item ::= expr",
 /*  25 */ "associated_name_list ::= associated_name_list COMMA associated_name",
 /*  26 */ "associated_name_list ::= associated_name",
 /*  27 */ "join_list_or_null ::= join_list",
 /*  28 */ "join_list_or_null ::=",
 /*  29 */ "join_list ::= join_list join_item",
 /*  30 */ "join_list ::= join_item",
 /*  31 */ "join_item ::= join_clause",
 /*  32 */ "join_clause ::= join_type aliased_or_qualified_name join_associated_name join_conditions",
 /*  33 */ "join_associated_name ::= AS IDENTIFIER",
 /*  34 */ "join_associated_name ::= IDENTIFIER",
 /*  35 */ "join_associated_name ::=",
 /*  36 */ "join_type ::= INNER JOIN",
 /*  37 */ "join_type ::= CROSS JOIN",
 /*  38 */ "join_type ::= LEFT OUTER JOIN",
 /*  39 */ "join_type ::= LEFT JOIN",
 /*  40 */ "join_type ::= RIGHT OUTER JOIN",
 /*  41 */ "join_type ::= RIGHT JOIN",
 /*  42 */ "join_type ::= FULL OUTER JOIN",
 /*  43 */ "join_type ::= FULL JOIN",
 /*  44 */ "join_type ::= JOIN",
 /*  45 */ "join_conditions ::= ON expr",
 /*  46 */ "join_conditions ::=",
 /*  47 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  48 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name PARENTHESES_OPEN field_list PARENTHESES_CLOSE VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  49 */ "values_list ::= values_list COMMA value_item",
 /*  50 */ "values_list ::= value_item",
 /*  51 */ "value_item ::= expr",
 /*  52 */ "field_list ::= field_list COMMA field_item",
 /*  53 */ "field_list ::= field_item",
 /*  54 */ "field_item ::= IDENTIFIER",
 /*  55 */ "update_statement ::= update_clause where_clause limit_clause",
 /*  56 */ "update_clause ::= UPDATE associated_name join_list_or_null SET update_item_list",
 /*  57 */ "update_item_list ::= update_item_list COMMA update_item",
 /*  58 */ "update_item_list ::= update_item",
 /*  59 */ "update_item ::= qualified_name EQUALS new_value",
 /*  60 */ "new_value ::= expr",
 /*  61 */ "delete_statement ::= delete_clause where_clause limit_clause",
 /*  62 */ "delete_clause ::= DELETE FROM associated_name",
 /*  63 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER",
 /*  64 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER",
 /*  65 */ "associated_name ::= aliased_or_qualified_name",
 /*  66 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER WITH with_item",
 /*  67 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER WITH PARENTHESES_OPEN with_list PARENTHESES_CLOSE",
 /*  68 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER WITH PARENTHESES_OPEN with_list PARENTHESES_CLOSE",
 /*  69 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER WITH with_item",
 /*  70 */ "associated_name ::= aliased_or_qualified_name WITH PARENTHESES_OPEN with_list PARENTHESES_CLOSE",
 /*  71 */ "associated_name ::= aliased_or_qualified_name WITH with_item",
 /*  72 */ "with_list ::= with_list COMMA with_item",
 /*  73 */ "with_list ::= with_item",
 /*  74 */ "with_item ::= IDENTIFIER",
 /*  75 */ "with_clause ::= WITH cte_list",
 /*  76 */ "with_clause ::= WITH RECURSIVE cte_list",
 /*  77 */ "cte_list ::= cte_list COMMA cte_item",
 /*  78 */ "cte_list ::= cte_item",
 /*  79 */ "cte_item ::= IDENTIFIER cte_column_list AS PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /*  80 */ "cte_column_list ::= PARENTHESES_OPEN field_list PARENTHESES_CLOSE",
 /*  81 */ "cte_column_list ::=",
 /*  82 */ "aliased_or_qualified_name ::= qualified_name",
 /*  83 */ "where_clause ::= WHERE expr",
 /*  84 */ "where_clause ::=",
 /*  85 */ "order_clause ::= ORDER BY order_list",
 /*  86 */ "order_clause ::=",
 /*  87 */ "order_list ::= order_list COMMA order_item",
 /*  88 */ "order_list ::= order_item",
 /*  89 */ "order_item ::= expr",
 /*  90 */ "order_item ::= expr ASC",
 /*  91 */ "order_item ::= expr DESC",
 /*  92 */ "group_clause ::= GROUP BY group_list",
 /*  93 */ "group_clause ::=",
 /*  94 */ "group_list ::= group_list COMMA group_item",
 /*  95 */ "group_list ::= group_item",
 /*  96 */ "group_item ::= expr",
 /*  97 */ "having_clause ::= HAVING expr",
 /*  98 */ "having_clause ::=",
 /*  99 */ "for_update_clause ::= FOR UPDATE",
 /* 100 */ "for_update_clause ::=",
 /* 101 */ "select_limit_clause ::= LIMIT integer_or_placeholder",
 /* 102 */ "select_limit_clause ::= LIMIT integer_or_placeholder COMMA integer_or_placeholder",
 /* 103 */ "select_limit_clause ::= LIMIT integer_or_placeholder OFFSET integer_or_placeholder",
 /* 104 */ "select_limit_clause ::=",
 /* 105 */ "limit_clause ::= LIMIT integer_or_placeholder",
 /* 106 */ "limit_clause ::=",
 /* 107 */ "integer_or_placeholder ::= INTEGER",
 /* 108 */ "integer_or_placeholder ::= HINTEGER",
 /* 109 */ "integer_or_placeholder ::= NPLACEHOLDER",
 /* 110 */ "integer_or_placeholder ::= SPLACEHOLDER",
 /* 111 */ "integer_or_placeholder ::= BPLACEHOLDER",
 /* 112 */ "expr ::= MINUS expr",
 /* 113 */ "expr ::= expr MINUS expr",
 /* 114 */ "expr ::= expr PLUS expr",
 /* 115 */ "expr ::= expr TIMES expr",
 /* 116 */ "expr ::= expr DIVIDE expr",
 /* 117 */ "expr ::= expr MOD expr",
 /* 118 */ "expr ::= expr AND expr",
 /* 119 */ "expr ::= expr OR expr",
 /* 120 */ "expr ::= expr BITWISE_AND expr",
 /* 121 */ "expr ::= expr BITWISE_OR expr",
 /* 122 */ "expr ::= expr BITWISE_XOR expr",
 /* 123 */ "expr ::= expr OP_MATCHES expr",
 /* 124 */ "expr ::= expr OP_CONTAINS expr",
 /* 125 */ "expr ::= expr OP_CONTAINED expr",
 /* 126 */ "expr ::= expr OP_OVERLAPS expr",
 /* 127 */ "expr ::= expr OP_CONCAT expr",
 /* 128 */ "expr ::= expr OP_JSON_GET expr",
 /* 129 */ "expr ::= expr OP_JSON_GET_TEXT expr",
 /* 130 */ "expr ::= expr OP_JSON_PATH expr",
 /* 131 */ "expr ::= expr OP_JSON_PATH_TEXT expr",
 /* 132 */ "expr ::= expr EQUALS expr",
 /* 133 */ "expr ::= expr NOTEQUALS expr",
 /* 134 */ "expr ::= expr LESS expr",
 /* 135 */ "expr ::= expr GREATER expr",
 /* 136 */ "expr ::= expr GREATEREQUAL expr",
 /* 137 */ "expr ::= expr LESSEQUAL expr",
 /* 138 */ "expr ::= expr LIKE expr",
 /* 139 */ "expr ::= expr NOT LIKE expr",
 /* 140 */ "expr ::= expr ILIKE expr",
 /* 141 */ "expr ::= expr NOT ILIKE expr",
 /* 142 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 143 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 144 */ "expr ::= PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 145 */ "expr ::= expr IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 146 */ "expr ::= expr NOT IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 147 */ "expr ::= EXISTS PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 148 */ "expr ::= expr AGAINST expr",
 /* 149 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 150 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 151 */ "expr ::= CASE expr when_clauses END",
 /* 152 */ "when_clauses ::= when_clauses when_clause",
 /* 153 */ "when_clauses ::= when_clause",
 /* 154 */ "when_clause ::= WHEN expr THEN expr",
 /* 155 */ "when_clause ::= ELSE expr",
 /* 156 */ "expr ::= function_call",
 /* 157 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN distinct_or_null argument_list_or_null PARENTHESES_CLOSE",
 /* 158 */ "distinct_or_null ::= DISTINCT",
 /* 159 */ "distinct_or_null ::=",
 /* 160 */ "argument_list_or_null ::= argument_list",
 /* 161 */ "argument_list_or_null ::=",
 /* 162 */ "argument_list ::= argument_list COMMA argument_item",
 /* 163 */ "argument_list ::= argument_item",
 /* 164 */ "argument_item ::= TIMES",
 /* 165 */ "argument_item ::= expr",
 /* 166 */ "expr ::= expr IS NULL",
 /* 167 */ "expr ::= expr IS NOT NULL",
 /* 168 */ "expr ::= expr BETWEEN expr",
 /* 169 */ "expr ::= expr BETWEEN_NOT expr",
 /* 170 */ "expr ::= NOT expr",
 /* 171 */ "expr ::= BITWISE_NOT expr",
 /* 172 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 173 */ "expr ::= qualified_name",
 /* 174 */ "expr ::= INTEGER",
 /* 175 */ "expr ::= HINTEGER",
 /* 176 */ "expr ::= STRING",
 /* 177 */ "expr ::= DOUBLE",
 /* 178 */ "expr ::= NULL",
 /* 179 */ "expr ::= TRUE",
 /* 180 */ "expr ::= FALSE",
 /* 181 */ "expr ::= NPLACEHOLDER",
 /* 182 */ "expr ::= SPLACEHOLDER",
 /* 183 */ "expr ::= BPLACEHOLDER",
 /* 184 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 185 */ "qualified_name ::= IDENTIFIER",
};
#endif /* NDEBUG */

/*
** This function returns the symbolic name associated with a token
** value.
*/
const char *phql_TokenName(int tokenType){
#ifndef NDEBUG
  if( tokenType>0 && tokenType<(sizeof(yyTokenName)/sizeof(yyTokenName[0])) ){
    return yyTokenName[tokenType];
  }else{
    return "Unknown";
  }
#else
  return "";
#endif
}

/*
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to phql_ and phql_Free.
*/
void *phql_Alloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(YYCODETYPE yymajor, YYMINORTYPE *yypminor){
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
#line 102 "parser.php.lemon"
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
#line 923 "parser.php.c"
      break;
    case 93:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 102:
    case 107:
    case 108:
    case 111:
    case 112:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 125:
    case 126:
    case 128:
    case 129:
    case 131:
    case 132:
    case 133:
    case 135:
    case 136:
    case 137:
    case 138:
    case 139:
    case 141:
    case 142:
    case 143:
    case 144:
    case 146:
    case 149:
    case 152:
#line 115 "parser.php.lemon"
{
	zval_ptr_dtor(&(yypminor->yy170));
}
#line 969 "parser.php.c"
      break;
    case 101:
    case 103:
    case 104:
    case 105:
    case 106:
    case 109:
    case 110:
    case 122:
    case 123:
    case 130:
    case 140:
    case 150:
    case 151:
#line 591 "parser.php.lemon"
{
	zephir_safe_zval_ptr_dtor((yypminor->yy170));
}
#line 988 "parser.php.c"
      break;
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor( yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/*
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from phql_Alloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void phql_Free(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
  (*freeProc)((void*)pParser);
}

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;

  /* if( pParser->yyidx<0 ) return YY_NO_ACTION;  */
  i = yy_shift_ofst[stateno];
  if( i==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  if( iLookAhead==YYNOCODE ){
    return YY_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
#ifdef YYFALLBACK
    int iFallback;            /* Fallback token */
    if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
           && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
           yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
      }
#endif
      return yy_find_shift_action(pParser, iFallback);
    }
#endif
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  yyParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;

  i = yy_reduce_ofst[stateno];
  if( i==YY_REDUCE_USE_DFLT ){
    return yy_default[stateno];
  }
  if( iLookAhead==YYNOCODE ){
    return YY_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer ot the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
  if( yypParser->yyidx>=YYSTACKDEPTH ){
     phql_ARG_FETCH;
     yypParser->yyidx--;
#ifndef NDEBUG
     if( yyTraceFILE ){
       fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
     }
#endif
     while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     phql_ARG_STORE; /* Suppress warning about unused %extra_argument var */
     return;
  }
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = yyNewState;
  yytos->major = yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 92, 1 },
  { 93, 1 },
  { 93, 1 },
  { 93, 1 },
  { 93, 1 },
  { 94, 1 },
  { 94, 2 },
  { 98, 7 },
  { 98, 8 },
  { 99, 2 },
  { 99, 1 },
  { 108, 3 },
  { 109, 1 },
  { 109, 0 },
  { 100, 6 },
  { 110, 1 },
  { 110, 1 },
  { 110, 0 },
  { 111, 3 },
  { 111, 1 },
  { 114, 1 },
  { 114, 3 },
  { 114, 3 },
  { 114, 2 },
  { 114, 1 },
  { 112, 3 },
  { 112, 1 },
  { 113, 1 },
  { 113, 0 },
  { 117, 2 },
  { 117, 1 },
  { 118, 1 },
  { 119, 4 },
  { 122, 2 },
  { 122, 1 },
  { 122, 0 },
  { 120, 2 },
  { 120, 2 },
  { 120, 3 },
  { 120, 2 },
  { 120, 3 },
  { 120, 2 },
  { 120, 3 },
  { 120, 2 },
  { 120, 1 },
  { 123, 2 },
  { 123, 0 },
  { 95, 7 },
  { 95, 10 },
  { 124, 3 },
  { 124, 1 },
  { 127, 1 },
  { 125, 3 },
  { 125, 1 },
  { 128, 1 },
  { 96, 3 },
  { 129, 5 },
  { 131, 3 },
  { 131, 1 },
  { 132, 3 },
  { 134, 1 },
  { 97, 3 },
  { 135, 3 },
  { 116, 3 },
  { 116, 2 },
  { 116, 1 },
  { 116, 5 },
  { 116, 7 },
  { 116, 6 },
  { 116, 4 },
  { 116, 5 },
  { 116, 3 },
  { 137, 3 },
  { 137, 1 },
  { 136, 1 },
  { 107, 2 },
  { 107, 3 },
  { 138, 3 },
  { 138, 1 },
  { 139, 6 },
  { 140, 3 },
  { 140, 0 },
  { 121, 1 },
  { 101, 2 },
  { 101, 0 },
  { 104, 3 },
  { 104, 0 },
  { 141, 3 },
  { 141, 1 },
  { 142, 1 },
  { 142, 2 },
  { 142, 2 },
  { 102, 3 },
  { 102, 0 },
  { 143, 3 },
  { 143, 1 },
  { 144, 1 },
  { 103, 2 },
  { 103, 0 },
  { 106, 2 },
  { 106, 0 },
  { 105, 2 },
  { 105, 4 },
  { 105, 4 },
  { 105, 0 },
  { 130, 2 },
  { 130, 0 },
  { 145, 1 },
  { 145, 1 },
  { 145, 1 },
  { 145, 1 },
  { 145, 1 },
  { 115, 2 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 3 },
  { 115, 4 },
  { 115, 3 },
  { 115, 4 },
  { 115, 5 },
  { 115, 6 },
  { 115, 3 },
  { 115, 5 },
  { 115, 6 },
  { 115, 4 },
  { 115, 3 },
  { 115, 6 },
  { 115, 6 },
  { 115, 4 },
  { 147, 2 },
  { 147, 1 },
  { 148, 4 },
  { 148, 2 },
  { 115, 1 },
  { 149, 5 },
  { 150, 1 },
  { 150, 0 },
  { 151, 1 },
  { 151, 0 },
  { 146, 3 },
  { 146, 1 },
  { 152, 1 },
  { 152, 1 },
  { 115, 3 },
  { 115, 4 },
  { 115, 3 },
  { 115, 3 },
  { 115, 2 },
  { 115, 2 },
  { 115, 3 },
  { 115, 1 },
  { 115, 1 },
  { 115, 1 },
  { 115, 1 },
  { 115, 1 },
  { 115, 1 },
  { 115, 1 },
  { 115, 1 },
  { 115, 1 },
  { 115, 1 },
  { 115, 1 },
  { 133, 3 },
  { 133, 1 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  phql_ARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0
        && yyruleno<sizeof(yyRuleName)/sizeof(yyRuleName[0]) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0:
#line 111 "parser.php.lemon"
{
	ZVAL_ZVAL(&status->ret, &yymsp[0].minor.yy170, 1, 1);
}
#line 1391 "parser.php.c"
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 26:
      case 27:
      case 30:
      case 31:
      case 51:
      case 58:
      case 60:
      case 73:
      case 82:
      case 88:
      case 95:
      case 96:
      case 156:
      case 160:
      case 165:
      case 173:
#line 119 "parser.php.lemon"
{
	yygotominor.yy170 = yymsp[0].minor.yy170;
}
#line 1418 "parser.php.c"
        break;
      case 6:
#line 143 "parser.php.lemon"
{
	yygotominor.yy170 = yymsp[-1].minor.yy170;
	phql_ret_select_statement_union(&yygotominor.yy170, &yymsp[0].minor.yy170);
}
#line 1426 "parser.php.c"
        break;
      case 7:
#line 152 "parser.php.lemon"
{
	phql_ret_select_statement(&yygotominor.yy170, &yymsp[-6].minor.yy170, &yymsp[-5].minor.yy170, &yymsp[-2].minor.yy170, &yymsp[-4].minor.yy170, &yymsp[-3].minor.yy170, &yymsp[-1].minor.yy170, &yymsp[0].minor.yy170);
}
#line 1433 "parser.php.c"
        break;
      case 8:
#line 156 "parser.php.lemon"
{
	phql_ret_select_statement(&yygotominor.yy170, &yymsp[-6].minor.yy170, &yymsp[-5].minor.yy170, &yymsp[-2].minor.yy170, &yymsp[-4].minor.yy170, &yymsp[-3].minor.yy170, &yymsp[-1].minor.yy170, &yymsp[0].minor.yy170);
	phql_ret_select_statement_with(&yygotominor.yy170, &yymsp[-7].minor.yy170);
}
#line 1441 "parser.php.c"
        break;
      case 9:
      case 29:
      case 152:
#line 165 "parser.php.lemon"
{
	phql_ret_zval_list(&yygotominor.yy170, &yymsp[-1].minor.yy170, &yymsp[0].minor.yy170);
}
#line 1450 "parser.php.c"
        break;
      case 10:
      case 19:
      case 50:
      case 53:
      case 78:
      case 153:
      case 163:
#line 169 "parser.php.lemon"
{
	phql_ret_zval_list(&yygotominor.yy170, &yymsp[0].minor.yy170, NULL);
}
#line 1463 "parser.php.c"
        break;
      case 11:
#line 177 "parser.php.lemon"
{
	phql_ret_union_item(&yygotominor.yy170, &yymsp[-1].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(36,&yymsp[-2].minor);
}
#line 1471 "parser.php.c"
        break;
      case 12:
#line 185 "parser.php.lemon"
{
	ZVAL_TRUE(&yygotominor.yy170);
  yy_destructor(37,&yymsp[0].minor);
}
#line 1479 "parser.php.c"
        break;
      case 13:
      case 17:
      case 28:
      case 35:
      case 46:
      case 81:
      case 84:
      case 86:
      case 93:
      case 98:
      case 100:
      case 104:
      case 106:
      case 159:
      case 161:
#line 189 "parser.php.lemon"
{
	ZVAL_UNDEF(&yygotominor.yy170);
}
#line 1500 "parser.php.c"
        break;
      case 14:
#line 197 "parser.php.lemon"
{
	phql_ret_select_clause(&yygotominor.yy170, &yymsp[-4].minor.yy170, &yymsp[-3].minor.yy170, &yymsp[-1].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(38,&yymsp[-5].minor);
  yy_destructor(39,&yymsp[-2].minor);
}
#line 1509 "parser.php.c"
        break;
      case 15:
#line 205 "parser.php.lemon"
{
	phql_ret_distinct_all(&yygotominor.yy170, 1);
  yy_destructor(40,&yymsp[0].minor);
}
#line 1517 "parser.php.c"
        break;
      case 16:
#line 209 "parser.php.lemon"
{
	phql_ret_distinct_all(&yygotominor.yy170, 0);
  yy_destructor(37,&yymsp[0].minor);
}
#line 1525 "parser.php.c"
        break;
      case 18:
      case 25:
      case 49:
      case 52:
      case 57:
      case 72:
      case 77:
      case 87:
      case 94:
      case 162:
#line 221 "parser.php.lemon"
{
	phql_ret_zval_list(&yygotominor.yy170, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(35,&yymsp[-1].minor);
}
#line 1542 "parser.php.c"
        break;
      case 20:
      case 164:
#line 233 "parser.php.lemon"
{
	phql_ret_column_item(&yygotominor.yy170, PHQL_T_STARALL, NULL, NULL, NULL);
  yy_destructor(22,&yymsp[0].minor);
}
#line 1551 "parser.php.c"
        break;
      case 21:
#line 237 "parser.php.lemon"
{
	phql_ret_column_item(&yygotominor.yy170, PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(42,&yymsp[-1].minor);
  yy_destructor(22,&yymsp[0].minor);
}
#line 1560 "parser.php.c"
        break;
      case 22:
#line 241 "parser.php.lemon"
{
	phql_ret_column_item(&yygotominor.yy170, PHQL_T_EXPR, &yymsp[-2].minor.yy170, NULL, yymsp[0].minor.yy0);
  yy_destructor(43,&yymsp[-1].minor);
}
#line 1568 "parser.php.c"
        break;
      case 23:
#line 245 "parser.php.lemon"
{
	phql_ret_column_item(&yygotominor.yy170, PHQL_T_EXPR, &yymsp[-1].minor.yy170, NULL, yymsp[0].minor.yy0);
}
#line 1575 "parser.php.c"
        break;
      case 24:
#line 249 "parser.php.lemon"
{
	phql_ret_column_item(&yygotominor.yy170, PHQL_T_EXPR, &yymsp[0].minor.yy170, NULL, NULL);
}
#line 1582 "parser.php.c"
        break;
      case 32:
#line 298 "parser.php.lemon"
{
	phql_ret_join_item(&yygotominor.yy170, &yymsp[-3].minor.yy170, &yymsp[-2].minor.yy170, &yymsp[-1].minor.yy170, &yymsp[0].minor.yy170);
}
#line 1589 "parser.php.c"
        break;
      case 33:
#line 306 "parser.php.lemon"
{
	phql_ret_qualified_name(&yygotominor.yy170, NULL, NULL, yymsp[0].minor.yy0);
  yy_destructor(43,&yymsp[-1].minor);
}
#line 1597 "parser.php.c"
        break;
      case 34:
      case 54:
      case 74:
      case 185:
#line 310 "parser.php.lemon"
{
	phql_ret_qualified_name(&yygotominor.yy170, NULL, NULL, yymsp[0].minor.yy0);
}
#line 1607 "parser.php.c"
        break;
      case 36:
#line 322 "parser.php.lemon"
{
	phql_ret_join_type(&yygotominor.yy170, PHQL_T_INNERJOIN);
  yy_destructor(44,&yymsp[-1].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1616 "parser.php.c"
        break;
      case 37:
#line 326 "parser.php.lemon"
{
	phql_ret_join_type(&yygotominor.yy170, PHQL_T_CROSSJOIN);
  yy_destructor(46,&yymsp[-1].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1625 "parser.php.c"
        break;
      case 38:
#line 330 "parser.php.lemon"
{
	phql_ret_join_type(&yygotominor.yy170, PHQL_T_LEFTJOIN);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[-1].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1635 "parser.php.c"
        break;
      case 39:
#line 334 "parser.php.lemon"
{
	phql_ret_join_type(&yygotominor.yy170, PHQL_T_LEFTJOIN);
  yy_destructor(47,&yymsp[-1].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1644 "parser.php.c"
        break;
      case 40:
#line 338 "parser.php.lemon"
{
	phql_ret_join_type(&yygotominor.yy170, PHQL_T_RIGHTJOIN);
  yy_destructor(49,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[-1].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1654 "parser.php.c"
        break;
      case 41:
#line 342 "parser.php.lemon"
{
	phql_ret_join_type(&yygotominor.yy170, PHQL_T_RIGHTJOIN);
  yy_destructor(49,&yymsp[-1].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1663 "parser.php.c"
        break;
      case 42:
#line 346 "parser.php.lemon"
{
	phql_ret_join_type(&yygotominor.yy170, PHQL_T_FULLJOIN);
  yy_destructor(50,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[-1].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1673 "parser.php.c"
        break;
      case 43:
#line 350 "parser.php.lemon"
{
	phql_ret_join_type(&yygotominor.yy170, PHQL_T_FULLJOIN);
  yy_destructor(50,&yymsp[-1].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1682 "parser.php.c"
        break;
      case 44:
#line 354 "parser.php.lemon"
{
	phql_ret_join_type(&yygotominor.yy170, PHQL_T_INNERJOIN);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1690 "parser.php.c"
        break;
      case 45:
#line 362 "parser.php.lemon"
{
	yygotominor.yy170 = yymsp[0].minor.yy170;
  yy_destructor(51,&yymsp[-1].minor);
}
#line 1698 "parser.php.c"
        break;
      case 47:
#line 375 "parser.php.lemon"
{
	phql_ret_insert_statement(&yygotominor.yy170, &yymsp[-4].minor.yy170, NULL, &yymsp[-1].minor.yy170);
  yy_destructor(52,&yymsp[-6].minor);
  yy_destructor(53,&yymsp[-5].minor);
  yy_destructor(54,&yymsp[-3].minor);
  yy_destructor(55,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 1710 "parser.php.c"
        break;
      case 48:
#line 379 "parser.php.lemon"
{
	phql_ret_insert_statement(&yygotominor.yy170, &yymsp[-7].minor.yy170, &yymsp[-5].minor.yy170, &yymsp[-1].minor.yy170);
  yy_destructor(52,&yymsp[-9].minor);
  yy_destructor(53,&yymsp[-8].minor);
  yy_destructor(55,&yymsp[-6].minor);
  yy_destructor(56,&yymsp[-4].minor);
  yy_destructor(54,&yymsp[-3].minor);
  yy_destructor(55,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 1724 "parser.php.c"
        break;
      case 55:
#line 425 "parser.php.lemon"
{
	phql_ret_update_statement(&yygotominor.yy170, &yymsp[-2].minor.yy170, &yymsp[-1].minor.yy170, &yymsp[0].minor.yy170);
}
#line 1731 "parser.php.c"
        break;
      case 56:
#line 433 "parser.php.lemon"
{
	phql_ret_update_clause(&yygotominor.yy170, &yymsp[-3].minor.yy170, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(57,&yymsp[-4].minor);
  yy_destructor(58,&yymsp[-1].minor);
}
#line 1740 "parser.php.c"
        break;
      case 59:
#line 453 "parser.php.lemon"
{
	phql_ret_update_item(&yygotominor.yy170, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(4,&yymsp[-1].minor);
}
#line 1748 "parser.php.c"
        break;
      case 61:
#line 467 "parser.php.lemon"
{
	phql_ret_delete_statement(&yygotominor.yy170, &yymsp[-2].minor.yy170, &yymsp[-1].minor.yy170, &yymsp[0].minor.yy170);
}
#line 1755 "parser.php.c"
        break;
      case 62:
#line 475 "parser.php.lemon"
{
	phql_ret_delete_clause(&yygotominor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(59,&yymsp[-2].minor);
  yy_destructor(39,&yymsp[-1].minor);
}
#line 1764 "parser.php.c"
        break;
      case 63:
#line 483 "parser.php.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy170, &yymsp[-2].minor.yy170, yymsp[0].minor.yy0, NULL);
  yy_destructor(43,&yymsp[-1].minor);
}
#line 1772 "parser.php.c"
        break;
      case 64:
#line 487 "parser.php.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy170, &yymsp[-1].minor.yy170, yymsp[0].minor.yy0, NULL);
}
#line 1779 "parser.php.c"
        break;
      case 65:
#line 491 "parser.php.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy170, &yymsp[0].minor.yy170, NULL, NULL);
}
#line 1786 "parser.php.c"
        break;
      case 66:
#line 495 "parser.php.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy170, &yymsp[-4].minor.yy170, yymsp[-2].minor.yy0, &yymsp[0].minor.yy170);
  yy_destructor(43,&yymsp[-3].minor);
  yy_destructor(60,&yymsp[-1].minor);
}
#line 1795 "parser.php.c"
        break;
      case 67:
#line 499 "parser.php.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy170, &yymsp[-6].minor.yy170, yymsp[-4].minor.yy0, &yymsp[-1].minor.yy170);
  yy_destructor(43,&yymsp[-5].minor);
  yy_destructor(60,&yymsp[-3].minor);
  yy_destructor(55,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 1806 "parser.php.c"
        break;
      case 68:
#line 503 "parser.php.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy170, &yymsp[-5].minor.yy170, yymsp[-4].minor.yy0, &yymsp[-1].minor.yy170);
  yy_destructor(60,&yymsp[-3].minor);
  yy_destructor(55,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 1816 "parser.php.c"
        break;
      case 69:
#line 507 "parser.php.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy170, &yymsp[-3].minor.yy170, yymsp[-2].minor.yy0, &yymsp[0].minor.yy170);
  yy_destructor(60,&yymsp[-1].minor);
}
#line 1824 "parser.php.c"
        break;
      case 70:
#line 511 "parser.php.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy170, &yymsp[-4].minor.yy170, NULL, &yymsp[-1].minor.yy170);
  yy_destructor(60,&yymsp[-3].minor);
  yy_destructor(55,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 1834 "parser.php.c"
        break;
      case 71:
#line 515 "parser.php.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy170, &yymsp[-2].minor.yy170, NULL, &yymsp[0].minor.yy170);
  yy_destructor(60,&yymsp[-1].minor);
}
#line 1842 "parser.php.c"
        break;
      case 75:
#line 543 "parser.php.lemon"
{
	phql_ret_with_clause(&yygotominor.yy170, &yymsp[0].minor.yy170, 0);
  yy_destructor(60,&yymsp[-1].minor);
}
#line 1850 "parser.php.c"
        break;
      case 76:
#line 547 "parser.php.lemon"
{
	phql_ret_with_clause(&yygotominor.yy170, &yymsp[0].minor.yy170, 1);
  yy_destructor(60,&yymsp[-2].minor);
  yy_destructor(61,&yymsp[-1].minor);
}
#line 1859 "parser.php.c"
        break;
      case 79:
#line 567 "parser.php.lemon"
{
	phql_ret_common_table_expression(&yygotominor.yy170, yymsp[-5].minor.yy0, &yymsp[-4].minor.yy170, &yymsp[-1].minor.yy170);
  yy_destructor(43,&yymsp[-3].minor);
  yy_destructor(55,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 1869 "parser.php.c"
        break;
      case 80:
#line 575 "parser.php.lemon"
{
	yygotominor.yy170 = yymsp[-1].minor.yy170;
  yy_destructor(55,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 1878 "parser.php.c"
        break;
      case 83:
#line 595 "parser.php.lemon"
{
	yygotominor.yy170 = yymsp[0].minor.yy170;
  yy_destructor(62,&yymsp[-1].minor);
}
#line 1886 "parser.php.c"
        break;
      case 85:
#line 607 "parser.php.lemon"
{
	yygotominor.yy170 = yymsp[0].minor.yy170;
  yy_destructor(63,&yymsp[-2].minor);
  yy_destructor(64,&yymsp[-1].minor);
}
#line 1895 "parser.php.c"
        break;
      case 89:
#line 631 "parser.php.lemon"
{
	phql_ret_order_item(&yygotominor.yy170, &yymsp[0].minor.yy170, 0);
}
#line 1902 "parser.php.c"
        break;
      case 90:
#line 635 "parser.php.lemon"
{
	phql_ret_order_item(&yygotominor.yy170, &yymsp[-1].minor.yy170, PHQL_T_ASC);
  yy_destructor(65,&yymsp[0].minor);
}
#line 1910 "parser.php.c"
        break;
      case 91:
#line 639 "parser.php.lemon"
{
	phql_ret_order_item(&yygotominor.yy170, &yymsp[-1].minor.yy170, PHQL_T_DESC);
  yy_destructor(66,&yymsp[0].minor);
}
#line 1918 "parser.php.c"
        break;
      case 92:
#line 647 "parser.php.lemon"
{
	yygotominor.yy170 = yymsp[0].minor.yy170;
  yy_destructor(67,&yymsp[-2].minor);
  yy_destructor(64,&yymsp[-1].minor);
}
#line 1927 "parser.php.c"
        break;
      case 97:
#line 679 "parser.php.lemon"
{
	yygotominor.yy170 = yymsp[0].minor.yy170;
  yy_destructor(68,&yymsp[-1].minor);
}
#line 1935 "parser.php.c"
        break;
      case 99:
#line 691 "parser.php.lemon"
{
	phql_ret_for_update_clause(&yygotominor.yy170);
  yy_destructor(69,&yymsp[-1].minor);
  yy_destructor(57,&yymsp[0].minor);
}
#line 1944 "parser.php.c"
        break;
      case 101:
      case 105:
#line 703 "parser.php.lemon"
{
	phql_ret_limit_clause(&yygotominor.yy170, &yymsp[0].minor.yy170, NULL);
  yy_destructor(70,&yymsp[-1].minor);
}
#line 1953 "parser.php.c"
        break;
      case 102:
#line 707 "parser.php.lemon"
{
	phql_ret_limit_clause(&yygotominor.yy170, &yymsp[0].minor.yy170, &yymsp[-2].minor.yy170);
  yy_destructor(70,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-1].minor);
}
#line 1962 "parser.php.c"
        break;
      case 103:
#line 711 "parser.php.lemon"
{
	phql_ret_limit_clause(&yygotominor.yy170, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(70,&yymsp[-3].minor);
  yy_destructor(71,&yymsp[-1].minor);
}
#line 1971 "parser.php.c"
        break;
      case 107:
      case 174:
#line 731 "parser.php.lemon"
{
	phql_ret_literal_zval(&yygotominor.yy170, PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
#line 1979 "parser.php.c"
        break;
      case 108:
      case 175:
#line 735 "parser.php.lemon"
{
	phql_ret_literal_zval(&yygotominor.yy170, PHQL_T_HINTEGER, yymsp[0].minor.yy0);
}
#line 1987 "parser.php.c"
        break;
      case 109:
      case 181:
#line 739 "parser.php.lemon"
{
	phql_ret_placeholder_zval(&yygotominor.yy170, PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 1995 "parser.php.c"
        break;
      case 110:
      case 182:
#line 743 "parser.php.lemon"
{
	phql_ret_placeholder_zval(&yygotominor.yy170, PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 2003 "parser.php.c"
        break;
      case 111:
      case 183:
#line 747 "parser.php.lemon"
{
	phql_ret_placeholder_zval(&yygotominor.yy170, PHQL_T_BPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 2011 "parser.php.c"
        break;
      case 112:
#line 755 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_MINUS, NULL, &yymsp[0].minor.yy170);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 2019 "parser.php.c"
        break;
      case 113:
#line 759 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_SUB, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 2027 "parser.php.c"
        break;
      case 114:
#line 763 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_ADD, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 2035 "parser.php.c"
        break;
      case 115:
#line 767 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_MUL, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(22,&yymsp[-1].minor);
}
#line 2043 "parser.php.c"
        break;
      case 116:
#line 771 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_DIV, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(21,&yymsp[-1].minor);
}
#line 2051 "parser.php.c"
        break;
      case 117:
#line 775 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_MOD, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 2059 "parser.php.c"
        break;
      case 118:
#line 779 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_AND, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(14,&yymsp[-1].minor);
}
#line 2067 "parser.php.c"
        break;
      case 119:
#line 783 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_OR, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(15,&yymsp[-1].minor);
}
#line 2075 "parser.php.c"
        break;
      case 120:
#line 787 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_BITWISE_AND, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(18,&yymsp[-1].minor);
}
#line 2083 "parser.php.c"
        break;
      case 121:
#line 791 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_BITWISE_OR, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(19,&yymsp[-1].minor);
}
#line 2091 "parser.php.c"
        break;
      case 122:
#line 795 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_BITWISE_XOR, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(20,&yymsp[-1].minor);
}
#line 2099 "parser.php.c"
        break;
      case 123:
#line 799 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_OP_MATCHES, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(10,&yymsp[-1].minor);
}
#line 2107 "parser.php.c"
        break;
      case 124:
#line 803 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_OP_CONTAINS, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(11,&yymsp[-1].minor);
}
#line 2115 "parser.php.c"
        break;
      case 125:
#line 807 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_OP_CONTAINED, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(12,&yymsp[-1].minor);
}
#line 2123 "parser.php.c"
        break;
      case 126:
#line 811 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_OP_OVERLAPS, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(13,&yymsp[-1].minor);
}
#line 2131 "parser.php.c"
        break;
      case 127:
#line 815 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_OP_CONCAT, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(26,&yymsp[-1].minor);
}
#line 2139 "parser.php.c"
        break;
      case 128:
#line 819 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_OP_JSON_GET, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(31,&yymsp[-1].minor);
}
#line 2147 "parser.php.c"
        break;
      case 129:
#line 823 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_OP_JSON_GET_TEXT, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(32,&yymsp[-1].minor);
}
#line 2155 "parser.php.c"
        break;
      case 130:
#line 827 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_OP_JSON_PATH, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(33,&yymsp[-1].minor);
}
#line 2163 "parser.php.c"
        break;
      case 131:
#line 831 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_OP_JSON_PATH_TEXT, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(34,&yymsp[-1].minor);
}
#line 2171 "parser.php.c"
        break;
      case 132:
#line 835 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_EQUALS, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(4,&yymsp[-1].minor);
}
#line 2179 "parser.php.c"
        break;
      case 133:
#line 839 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_NOTEQUALS, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(5,&yymsp[-1].minor);
}
#line 2187 "parser.php.c"
        break;
      case 134:
#line 843 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_LESS, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(6,&yymsp[-1].minor);
}
#line 2195 "parser.php.c"
        break;
      case 135:
#line 847 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_GREATER, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(7,&yymsp[-1].minor);
}
#line 2203 "parser.php.c"
        break;
      case 136:
#line 851 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_GREATEREQUAL, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(8,&yymsp[-1].minor);
}
#line 2211 "parser.php.c"
        break;
      case 137:
#line 855 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_LESSEQUAL, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(9,&yymsp[-1].minor);
}
#line 2219 "parser.php.c"
        break;
      case 138:
#line 859 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_LIKE, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(16,&yymsp[-1].minor);
}
#line 2227 "parser.php.c"
        break;
      case 139:
#line 863 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_NLIKE, &yymsp[-3].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(16,&yymsp[-1].minor);
}
#line 2236 "parser.php.c"
        break;
      case 140:
#line 867 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_ILIKE, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(17,&yymsp[-1].minor);
}
#line 2244 "parser.php.c"
        break;
      case 141:
#line 871 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_NILIKE, &yymsp[-3].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(17,&yymsp[-1].minor);
}
#line 2253 "parser.php.c"
        break;
      case 142:
      case 145:
#line 875 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_IN, &yymsp[-4].minor.yy170, &yymsp[-1].minor.yy170);
  yy_destructor(28,&yymsp[-3].minor);
  yy_destructor(55,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 2264 "parser.php.c"
        break;
      case 143:
      case 146:
#line 879 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_NOTIN, &yymsp[-5].minor.yy170, &yymsp[-1].minor.yy170);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(28,&yymsp[-3].minor);
  yy_destructor(55,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 2276 "parser.php.c"
        break;
      case 144:
#line 883 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_SUBQUERY, &yymsp[-1].minor.yy170, NULL);
  yy_destructor(55,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 2285 "parser.php.c"
        break;
      case 147:
#line 895 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_EXISTS, NULL, &yymsp[-1].minor.yy170);
  yy_destructor(77,&yymsp[-3].minor);
  yy_destructor(55,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 2295 "parser.php.c"
        break;
      case 148:
#line 899 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_AGAINST, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(1,&yymsp[-1].minor);
}
#line 2303 "parser.php.c"
        break;
      case 149:
#line 903 "parser.php.lemon"
{
	{
		zval qualified;
		phql_ret_raw_qualified_name(&qualified, yymsp[-1].minor.yy0, NULL);
		phql_ret_expr(&yygotominor.yy170, PHQL_T_CAST, &yymsp[-3].minor.yy170, &qualified);
	}
  yy_destructor(78,&yymsp[-5].minor);
  yy_destructor(55,&yymsp[-4].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 2318 "parser.php.c"
        break;
      case 150:
#line 911 "parser.php.lemon"
{
	{
		zval qualified;
		phql_ret_raw_qualified_name(&qualified, yymsp[-1].minor.yy0, NULL);
		phql_ret_expr(&yygotominor.yy170, PHQL_T_CONVERT, &yymsp[-3].minor.yy170, &qualified);
	}
  yy_destructor(79,&yymsp[-5].minor);
  yy_destructor(55,&yymsp[-4].minor);
  yy_destructor(80,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 2333 "parser.php.c"
        break;
      case 151:
#line 919 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_CASE, &yymsp[-2].minor.yy170, &yymsp[-1].minor.yy170);
  yy_destructor(81,&yymsp[-3].minor);
  yy_destructor(82,&yymsp[0].minor);
}
#line 2342 "parser.php.c"
        break;
      case 154:
#line 931 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_WHEN, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(83,&yymsp[-3].minor);
  yy_destructor(84,&yymsp[-1].minor);
}
#line 2351 "parser.php.c"
        break;
      case 155:
#line 935 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_ELSE, &yymsp[0].minor.yy170, NULL);
  yy_destructor(85,&yymsp[-1].minor);
}
#line 2359 "parser.php.c"
        break;
      case 157:
#line 947 "parser.php.lemon"
{
	phql_ret_func_call(&yygotominor.yy170, yymsp[-4].minor.yy0, &yymsp[-1].minor.yy170, &yymsp[-2].minor.yy170);
  yy_destructor(55,&yymsp[-3].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 2368 "parser.php.c"
        break;
      case 158:
#line 955 "parser.php.lemon"
{
	phql_ret_distinct(&yygotominor.yy170);
  yy_destructor(40,&yymsp[0].minor);
}
#line 2376 "parser.php.c"
        break;
      case 166:
#line 999 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_ISNULL, &yymsp[-2].minor.yy170, NULL);
  yy_destructor(27,&yymsp[-1].minor);
  yy_destructor(86,&yymsp[0].minor);
}
#line 2385 "parser.php.c"
        break;
      case 167:
#line 1003 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_ISNOTNULL, &yymsp[-3].minor.yy170, NULL);
  yy_destructor(27,&yymsp[-2].minor);
  yy_destructor(29,&yymsp[-1].minor);
  yy_destructor(86,&yymsp[0].minor);
}
#line 2395 "parser.php.c"
        break;
      case 168:
#line 1007 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_BETWEEN, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(2,&yymsp[-1].minor);
}
#line 2403 "parser.php.c"
        break;
      case 169:
#line 1011 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_BETWEEN_NOT, &yymsp[-2].minor.yy170, &yymsp[0].minor.yy170);
  yy_destructor(3,&yymsp[-1].minor);
}
#line 2411 "parser.php.c"
        break;
      case 170:
#line 1015 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_NOT, NULL, &yymsp[0].minor.yy170);
  yy_destructor(29,&yymsp[-1].minor);
}
#line 2419 "parser.php.c"
        break;
      case 171:
#line 1019 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_BITWISE_NOT, NULL, &yymsp[0].minor.yy170);
  yy_destructor(30,&yymsp[-1].minor);
}
#line 2427 "parser.php.c"
        break;
      case 172:
#line 1023 "parser.php.lemon"
{
	phql_ret_expr(&yygotominor.yy170, PHQL_T_ENCLOSED, &yymsp[-1].minor.yy170, NULL);
  yy_destructor(55,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[0].minor);
}
#line 2436 "parser.php.c"
        break;
      case 176:
#line 1039 "parser.php.lemon"
{
	phql_ret_literal_zval(&yygotominor.yy170, PHQL_T_STRING, yymsp[0].minor.yy0);
}
#line 2443 "parser.php.c"
        break;
      case 177:
#line 1043 "parser.php.lemon"
{
	phql_ret_literal_zval(&yygotominor.yy170, PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
#line 2450 "parser.php.c"
        break;
      case 178:
#line 1047 "parser.php.lemon"
{
	phql_ret_literal_zval(&yygotominor.yy170, PHQL_T_NULL, NULL);
  yy_destructor(86,&yymsp[0].minor);
}
#line 2458 "parser.php.c"
        break;
      case 179:
#line 1051 "parser.php.lemon"
{
	phql_ret_literal_zval(&yygotominor.yy170, PHQL_T_TRUE, NULL);
  yy_destructor(89,&yymsp[0].minor);
}
#line 2466 "parser.php.c"
        break;
      case 180:
#line 1055 "parser.php.lemon"
{
	phql_ret_literal_zval(&yygotominor.yy170, PHQL_T_FALSE, NULL);
  yy_destructor(90,&yymsp[0].minor);
}
#line 2474 "parser.php.c"
        break;
      case 184:
#line 1078 "parser.php.lemon"
{
	phql_ret_qualified_name(&yygotominor.yy170, NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(42,&yymsp[-1].minor);
}
#line 2482 "parser.php.c"
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yypParser,yygoto);
  if( yyact < YYNSTATE ){
    yy_shift(yypParser,yyact,yygoto,&yygotominor);
  }else if( yyact == YYNSTATE + YYNRULE + 1 ){
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  phql_ARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  phql_ARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 35 "parser.php.lemon"

	if (status->scanner_state->start_length) {
		{

			char *token_name = NULL;
			int token_found = 0;
			unsigned int token_length;
			const phql_token_names *tokens = phql_tokens;
			int active_token = status->scanner_state->active_token;
			int near_length = status->scanner_state->start_length;

			if (active_token) {

				do {
					if (tokens->code == active_token) {
						token_name = tokens->name;
						token_length = tokens->length;
						token_found = 1;
						break;
					}
					++tokens;
				} while (tokens[0].code != 0);

			}

			if (!token_name) {
				token_length = strlen("UNKNOWN");
				token_name = estrndup("UNKNOWN", token_length);
				token_found = 0;
			}

			status->syntax_error_len = 96 + status->token->len + token_length + near_length + status->phql_length;;
			status->syntax_error = emalloc(sizeof(char) * status->syntax_error_len);

			if (near_length > 0) {
				if (status->token->value) {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s(%s), near to '%s', when parsing: %s (%d)", token_name, status->token->value, status->scanner_state->start, status->phql, status->phql_length);
				} else {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s, near to '%s', when parsing: %s (%d)", token_name, status->scanner_state->start, status->phql, status->phql_length);
				}
			} else {
				if (active_token != PHQL_T_IGNORE) {
					if (status->token->value) {
						snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s(%s), at the end of query, when parsing: %s (%d)", token_name, status->token->value, status->phql, status->phql_length);
					} else {
						snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s, at the end of query, when parsing: %s (%d)", token_name, status->phql, status->phql_length);
					}
				} else {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected EOF, at the end of query");
				}
				status->syntax_error[status->syntax_error_len - 1] = '\0';
			}

			if (!token_found) {
				if (token_name) {
					efree(token_name);
				}
			}
		}
	} else {
		status->syntax_error_len = strlen("Syntax error, unexpected EOF");
		status->syntax_error = estrndup("Syntax error, unexpected EOF", status->syntax_error_len);
	}

	status->status = PHQL_PARSING_FAILED;

#line 2591 "parser.php.c"
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  phql_ARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "phql_Alloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void phql_(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  phql_TOKENTYPE yyminor       /* The value for the token */
  phql_ARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
    if( yymajor==0 ) return;
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  phql_ARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,yymajor);
    if( yyact<YYNSTATE ){
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      if( yyendofinput && yypParser->yyidx>=0 ){
        yymajor = 0;
      }else{
        yymajor = YYNOCODE;
      }
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else if( yyact == YY_ERROR_ACTION ){
      int yymx;
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_shift_action(yypParser,YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }else{
      yy_accept(yypParser);
      yymajor = YYNOCODE;
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}
