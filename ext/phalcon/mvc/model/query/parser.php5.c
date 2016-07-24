/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
#line 39 "parser.php5.lemon"

#include "parser.php5.inc.h"

#line 12 "parser.php5.c"
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
#define YYNOCODE 134
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy162;
  int yy267;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 293
#define YYNRULE 161
#define YYERRORSYMBOL 79
#define YYERRSYMDT yy267
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
 /*     0 */   120,  126,   55,   57,   59,   61,   63,   65,   45,   47,
 /*    10 */    67,   72,   49,   51,   53,   41,   39,   43,   37,   34,
 /*    20 */   122,   74,   69,  120,  126,   55,   57,   59,   61,   63,
 /*    30 */    65,   45,   47,   67,   72,   49,   51,   53,   41,   39,
 /*    40 */    43,   37,   34,  122,   74,   69,   19,   20,   21,   22,
 /*    50 */    23,  293,   32,   33,  120,  126,   55,   57,   59,   61,
 /*    60 */    63,   65,   45,   47,   67,   72,   49,   51,   53,   41,
 /*    70 */    39,   43,   37,   34,  122,   74,   69,   37,   34,  122,
 /*    80 */    74,   69,  294,  220,   81,  218,   95,   90,  111,  209,
 /*    90 */   113,  114,  211,  154,   79,  186,  247,  120,  126,   55,
 /*   100 */    57,   59,   61,   63,   65,   45,   47,   67,   72,   49,
 /*   110 */    51,   53,   41,   39,   43,   37,   34,  122,   74,   69,
 /*   120 */    55,   57,   59,   61,   63,   65,   45,   47,   67,   72,
 /*   130 */    49,   51,   53,   41,   39,   43,   37,   34,  122,   74,
 /*   140 */    69,  130,    7,  120,  126,   55,   57,   59,   61,   63,
 /*   150 */    65,   45,   47,   67,   72,   49,   51,   53,   41,   39,
 /*   160 */    43,   37,   34,  122,   74,   69,   41,   39,   43,   37,
 /*   170 */    34,  122,   74,   69,  140,  240,  120,  126,   55,   57,
 /*   180 */    59,   61,   63,   65,   45,   47,   67,   72,   49,   51,
 /*   190 */    53,   41,   39,   43,   37,   34,  122,   74,   69,  120,
 /*   200 */   126,   55,   57,   59,   61,   63,   65,   45,   47,   67,
 /*   210 */    72,   49,   51,   53,   41,   39,   43,   37,   34,  122,
 /*   220 */    74,   69,   45,   47,   67,   72,   49,   51,   53,   41,
 /*   230 */    39,   43,   37,   34,  122,   74,   69,  122,   74,   69,
 /*   240 */   112,  113,  114,  146,    8,  120,  126,   55,   57,   59,
 /*   250 */    61,   63,   65,   45,   47,   67,   72,   49,   51,   53,
 /*   260 */    41,   39,   43,   37,   34,  122,   74,   69,  168,  295,
 /*   270 */   156,   35,  124,   17,  169,  171,  296,   76,  279,  286,
 /*   280 */   282,  159,   67,   72,   49,   51,   53,   41,   39,   43,
 /*   290 */    37,   34,  122,   74,   69,  128,   49,   51,   53,   41,
 /*   300 */    39,   43,   37,   34,  122,   74,   69,   24,   70,  228,
 /*   310 */    94,  174,  175,  181,  182,  183,  133,  137,  143,  230,
 /*   320 */   149,  222,  223,  123,   89,  178,  176,  177,  179,  180,
 /*   330 */   168,   82,   94,   35,   95,   99,  169,  171,   38,  192,
 /*   340 */   208,  194,  196,  159,  200,  204,   98,  192,  208,  194,
 /*   350 */   196,   80,  200,  204,   83,  210,  173,  128,  430,   84,
 /*   360 */    84,  297,  455,    1,    2,    3,    4,    5,    6,  158,
 /*   370 */    94,  107,  107,  174,  175,  181,  182,  183,  133,  137,
 /*   380 */   143,  226,  149,   92,  103,    6,   31,  178,  176,  177,
 /*   390 */   179,  180,  213,  162,  271,   35,   92,  162,  169,  171,
 /*   400 */   287,  212,  217,   91,  173,  214,   95,  104,  238,   28,
 /*   410 */   237,  173,   92,    9,  234,  173,  105,  158,    6,  128,
 /*   420 */   173,  165,  115,   26,  158,  224,  163,  184,  158,   10,
 /*   430 */   162,  184,  100,  158,  107,  174,  175,  181,  182,  183,
 /*   440 */   133,  137,  143,   78,  149,   11,  221,  217,  173,  178,
 /*   450 */   176,  177,  179,  180,  285,  216,   35,  245,  232,  169,
 /*   460 */   171,  158,   76,   31,  184,  173,  159,  135,  110,   76,
 /*   470 */   131,    6,  173,  284,    6,  173,  199,  236,  158,  197,
 /*   480 */   128,  173,  242,  246,  249,  158,  129,   30,  158,  276,
 /*   490 */   191,  290,  189,  109,  158,  173,  174,  175,  181,  182,
 /*   500 */   183,  133,  137,  143,  173,  149,  160,   15,  158,  245,
 /*   510 */   178,  176,  177,  179,  180,  168,   13,  158,   35,  277,
 /*   520 */   258,  169,  171,  162,   84,  258,  215,  173,  159,  254,
 /*   530 */    14,   96,  259,   85,  265,  244,  107,  259,  173,  160,
 /*   540 */   158,  173,  128,  173,  152,  154,  166,  186,  151,  188,
 /*   550 */   102,  158,  203,   36,  158,  201,  158,  167,  174,  175,
 /*   560 */   181,  182,  183,  133,  137,  143,  429,  149,  258,   40,
 /*   570 */    12,  173,  178,  176,  177,  179,  180,   42,   16,   35,
 /*   580 */   257,  166,  169,  171,  158,  292,  173,  173,  207,  159,
 /*   590 */    84,  205,  251,  252,  260,  173,   29,  166,   44,  158,
 /*   600 */   158,  225,  107,  128,  107,  384,   18,  261,  158,   46,
 /*   610 */   270,   75,   48,   50,   52,   25,  173,  233,  256,  174,
 /*   620 */   175,  181,  182,  183,  133,  137,  143,  173,  149,  158,
 /*   630 */   173,  173,  173,  178,  176,  177,  179,  180,  255,   54,
 /*   640 */   158,   56,   58,  158,  158,  158,  267,  281,  282,   69,
 /*   650 */    60,   87,   27,   62,   77,  256,   64,  173,   66,  173,
 /*   660 */   173,   68,   71,  274,   73,  108,  262,  119,  173,   86,
 /*   670 */   158,  173,  158,  158,  173,  266,  173,   94,  121,  173,
 /*   680 */   173,  158,  173,  127,  158,  173,  139,  158,  145,  158,
 /*   690 */    97,  109,  158,  158,  150,  158,  173,  155,  158,  110,
 /*   700 */    88,  173,  157,   93,  173,  101,  173,  118,  170,  158,
 /*   710 */   106,  172,  173,  187,  158,  173,  116,  158,  229,  158,
 /*   720 */   173,  132,  239,  248,  117,  158,  173,  125,  158,  173,
 /*   730 */   134,  173,   76,  158,  136,  138,  173,  141,  142,  158,
 /*   740 */   173,  173,  158,  144,  158,  147,  148,  153,  185,  158,
 /*   750 */   164,  190,  161,  158,  158,  321,  193,  195,  322,  323,
 /*   760 */   198,  324,  325,  326,  202,  327,  328,  329,  206,  219,
 /*   770 */   241,  243,  227,  332,  269,  333,  268,  272,  340,  273,
 /*   780 */   275,  383,  231,  250,  280,  235,  253,  264,  263,  283,
 /*   790 */   288,  289,  346,  291,  278,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,    1,    2,    3,    4,    5,    6,    7,
 /*    30 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    40 */    18,   19,   20,   21,   22,   23,   60,   61,   62,   63,
 /*    50 */    64,    0,   53,   54,    1,    2,    3,    4,    5,    6,
 /*    60 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    70 */    17,   18,   19,   20,   21,   22,   23,   19,   20,   21,
 /*    80 */    22,   23,    0,   30,   96,   32,  119,  120,  100,  101,
 /*    90 */   102,  103,   25,   71,   27,   73,   50,    1,    2,    3,
 /*   100 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   110 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   120 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   130 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   140 */    23,   45,   87,    1,    2,    3,    4,    5,    6,    7,
 /*   150 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   160 */    18,   19,   20,   21,   22,   23,   16,   17,   18,   19,
 /*   170 */    20,   21,   22,   23,   32,   55,    1,    2,    3,    4,
 /*   180 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   190 */    15,   16,   17,   18,   19,   20,   21,   22,   23,    1,
 /*   200 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   210 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   220 */    22,   23,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   230 */    17,   18,   19,   20,   21,   22,   23,   21,   22,   23,
 /*   240 */   101,  102,  103,   68,   88,    1,    2,    3,    4,    5,
 /*   250 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   260 */    16,   17,   18,   19,   20,   21,   22,   23,   17,    0,
 /*   270 */    72,   20,   23,   25,   23,   24,    0,   26,  114,  115,
 /*   280 */   116,   30,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   290 */    19,   20,   21,   22,   23,   44,   13,   14,   15,   16,
 /*   300 */    17,   18,   19,   20,   21,   22,   23,   59,   11,   12,
 /*   310 */    30,   60,   61,   62,   63,   64,   65,   66,   67,   22,
 /*   320 */    69,   28,   29,   74,   44,   74,   75,   76,   77,   78,
 /*   330 */    17,   25,   30,   20,  119,  120,   23,   24,   98,   33,
 /*   340 */    34,   35,   36,   30,   38,   39,   44,   33,   34,   35,
 /*   350 */    36,   95,   38,   39,   99,   99,  116,   44,   45,  104,
 /*   360 */   104,    0,   80,   81,   82,   83,   84,   85,   86,  129,
 /*   370 */    30,  116,  116,   60,   61,   62,   63,   64,   65,   66,
 /*   380 */    67,   82,   69,   25,   44,   86,   98,   74,   75,   76,
 /*   390 */    77,   78,   17,   98,  112,   20,   25,   98,   23,   24,
 /*   400 */   118,   97,   98,   45,  116,   30,  119,  120,   56,  121,
 /*   410 */   122,  116,   25,   89,   82,  116,   45,  129,   86,   44,
 /*   420 */   116,  126,  104,   51,  129,  126,  131,  132,  129,   90,
 /*   430 */    98,  132,   45,  129,  116,   60,   61,   62,   63,   64,
 /*   440 */    65,   66,   67,   94,   69,   91,   97,   98,  116,   74,
 /*   450 */    75,   76,   77,   78,   98,   17,   20,   98,  126,   23,
 /*   460 */    24,  129,   26,   98,  132,  116,   30,   82,   30,   26,
 /*   470 */    82,   86,  116,  117,   86,  116,   34,   98,  129,   37,
 /*   480 */    44,  116,  123,  124,   41,  129,   98,  122,  129,   46,
 /*   490 */    30,   48,   32,   31,  129,  116,   60,   61,   62,   63,
 /*   500 */    64,   65,   66,   67,  116,   69,   44,   58,  129,   98,
 /*   510 */    74,   75,   76,   77,   78,   17,   57,  129,   20,   99,
 /*   520 */    98,   23,   24,   98,  104,   98,   31,  116,   30,  107,
 /*   530 */    46,   30,  110,   32,  107,  124,  116,  110,  116,   44,
 /*   540 */   129,  116,   44,  116,   70,   71,   25,   73,  127,  128,
 /*   550 */    49,  129,   34,   98,  129,   37,  129,  132,   60,   61,
 /*   560 */    62,   63,   64,   65,   66,   67,   45,   69,   98,   98,
 /*   570 */    92,  116,   74,   75,   76,   77,   78,   98,  125,   20,
 /*   580 */   110,   25,   23,   24,  129,   99,  116,  116,   34,   30,
 /*   590 */   104,   37,  104,   43,   44,  116,   25,   25,   98,  129,
 /*   600 */   129,   45,  116,   44,  116,    0,  125,  108,  129,   98,
 /*   610 */   111,   44,   98,   98,   98,  125,  116,   45,   25,   60,
 /*   620 */    61,   62,   63,   64,   65,   66,   67,  116,   69,  129,
 /*   630 */   116,  116,  116,   74,   75,   76,   77,   78,   45,   98,
 /*   640 */   129,   98,   98,  129,  129,  129,   25,  115,  116,   23,
 /*   650 */    98,   49,   52,   98,   93,   25,   98,  116,   98,  116,
 /*   660 */   116,   98,   98,   58,   98,   30,   45,   98,  116,   30,
 /*   670 */   129,  116,  129,  129,  116,   45,  116,   30,   98,  116,
 /*   680 */   116,  129,  116,   98,  129,  116,   98,  129,   98,  129,
 /*   690 */    49,   31,  129,  129,   98,  129,  116,   98,  129,   30,
 /*   700 */   119,  116,   98,  119,  116,  119,  116,   40,   98,  129,
 /*   710 */   119,   98,  116,   98,  129,  116,  105,  129,   98,  129,
 /*   720 */   116,   45,   98,   98,  106,  129,  116,   74,  129,  116,
 /*   730 */    44,  116,   26,  129,   45,   44,  116,   30,   45,  129,
 /*   740 */   116,  116,  129,   44,  129,   30,   45,  128,   28,  129,
 /*   750 */    45,   30,  130,  129,  129,   30,   34,   34,   30,   30,
 /*   760 */    34,   30,   30,   30,   34,   30,   30,   30,   34,   30,
 /*   770 */    52,   25,   45,    0,   30,    0,  111,   87,    0,  113,
 /*   780 */   125,    0,   44,   42,   25,   45,   44,   44,   43,    3,
 /*   790 */    87,  113,    0,   27,   47,
};
#define YY_SHIFT_USE_DFLT (-15)
static short yy_shift_ofst[] = {
 /*     0 */   443,   51,   82,  269,  276,  361,   46,  120,  352,  372,
 /*    10 */   449,  459,  -15,  484,  -15,  -14,  248,  -14,  -15,  -15,
 /*    20 */   -15,  -15,  -15,  -15,  -14,  -15,  600,  559,  571,  559,
 /*    30 */   -15,   -1,  -15,  -15,  559,  559,  216,  559,  216,  559,
 /*    40 */    58,  559,   58,  559,   58,  559,  271,  559,  271,  559,
 /*    50 */   150,  559,  150,  559,  150,  559,  213,  559,  213,  559,
 /*    60 */   213,  559,  213,  559,  213,  559,  213,  559,  283,  297,
 /*    70 */   559,  626,  559,  283,  567,  251,  293,  375,   67,  635,
 /*    80 */   306,  -15,  635,  -15,  501,  639,  602,  280,  -15,  647,
 /*    90 */   358,  -15,  647,  -15,  -15,  -15,  641,  302,  647,  387,
 /*   100 */   -15,  -15,  340,  647,  371,  -15,  -15,  -15,  660,  669,
 /*   110 */   -15,  314,  -15,  -15,  635,  460,  667,  -15,  559,  244,
 /*   120 */   559,  244,  249,  -15,  653,  -15,  559,  117,  436,   96,
 /*   130 */   -15,  676,  -15,  686,  706,  689,  -15,  691,  559,  142,
 /*   140 */   707,  693,  -15,  699,  559,  175,  715,  701,  -15,  559,
 /*   150 */    22,  474,  -15,  -15,  559,  198,  559,  244,  -15,  462,
 /*   160 */   720,  313,  244,  705,  -15,  521,  498,  -15,  -15,  559,
 /*   170 */   626,  559,  626,  -15,  -15,  -15,  -15,  -15,  -15,  -15,
 /*   180 */   -15,  -15,  -15,  -15,  -15,  -15,  559,  244,  -15,  721,
 /*   190 */   -15,  -15,  722,  725,  723,  728,  442,  726,  729,  731,
 /*   200 */   518,  730,  732,  733,  554,  734,  735,  736,  737,  -15,
 /*   210 */   -15,  375,  -15,  -15,  495,  438,  -15,   53,  739,  -15,
 /*   220 */   -15,  -15,  -15,  -15,  556,  -15,  727,  -15,  559,  626,
 /*   230 */   738,  251,  572,  -15,  740,  -15,  216,  -15,  559,  244,
 /*   240 */   718,  559,  746,  559,  -15,  244,  -15,  559,  244,  741,
 /*   250 */   635,  550,  742,  559,  593,  773,  559,  -15,  244,  -15,
 /*   260 */   744,  621,  745,  743,  559,  630,  775,  744,  -15,  -15,
 /*   270 */   -15,   46,  605,  778,  -14,  781,  635,  747,  635,  759,
 /*   280 */   635,  -15,  786,  559,  -15,  244,  -15,   46,  605,  792,
 /*   290 */   766,  635,  -15,
};
#define YY_REDUCE_USE_DFLT (-34)
static short yy_reduce_ofst[] = {
 /*     0 */   282,  -34,  -34,  -34,  -34,  -34,   55,  156,  324,  339,
 /*    10 */   354,  478,  -34,  -34,  -34,  453,  -34,  481,  -34,  -34,
 /*    20 */   -34,  -34,  -34,  -34,  490,  -34,  -34,  288,  -34,  365,
 /*    30 */   -34,  -34,  -34,  -34,  379,  455,  -34,  240,  -34,  471,
 /*    40 */   -34,  479,  -34,  500,  -34,  511,  -34,  514,  -34,  515,
 /*    50 */   -34,  516,  -34,  541,  -34,  543,  -34,  544,  -34,  552,
 /*    60 */   -34,  555,  -34,  558,  -34,  560,  -34,  563,  -34,  -34,
 /*    70 */   564,  -34,  566,  -34,  -34,  299,  561,  349,  -34,  256,
 /*    80 */   -12,  -34,  255,  -34,  -34,  -34,  -34,  581,  -34,  -33,
 /*    90 */   -34,  -34,  584,  -34,  -34,  -34,  -34,  586,  215,  -34,
 /*   100 */   -34,  -34,  591,  287,  -34,  -34,  -34,  -34,  -34,  -34,
 /*   110 */   -34,  139,  -34,  -34,  318,  611,  618,  -34,  569,  -34,
 /*   120 */   580,  -34,  -34,  -34,  -34,  -34,  585,  -34,  388,  -34,
 /*   130 */   -34,  -34,  -34,  -34,  385,  -34,  -34,  -34,  588,  -34,
 /*   140 */   -34,  -34,  -34,  -34,  590,  -34,  -34,  -34,  -34,  596,
 /*   150 */   421,  619,  -34,  -34,  599,  -34,  604,  -34,  -34,  -34,
 /*   160 */   622,  295,  -34,  -34,  -34,  -34,  425,  -34,  -34,  610,
 /*   170 */   -34,  613,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
 /*   180 */   -34,  -34,  -34,  -34,  -34,  -34,  615,  -34,  -34,  -34,
 /*   190 */   -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
 /*   200 */   -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
 /*   210 */   -34,  304,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
 /*   220 */   -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  620,  -34,
 /*   230 */   -34,  332,  -34,  -34,  -34,  -34,  -34,  -34,  624,  -34,
 /*   240 */   -34,  359,  -34,  411,  -34,  -34,  -34,  625,  -34,  -34,
 /*   250 */   488,  -34,  -34,  422,  -34,  -34,  470,  -34,  -34,  -34,
 /*   260 */   499,  -34,  -34,  -34,  427,  -34,  -34,  665,  -34,  -34,
 /*   270 */   -34,  690,  666,  -34,  655,  -34,  420,  -34,  164,  -34,
 /*   280 */   532,  -34,  -34,  356,  -34,  -34,  -34,  703,  678,  -34,
 /*   290 */   -34,  486,  -34,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   454,  454,  454,  454,  454,  454,  362,  371,  376,  364,
 /*    10 */   382,  378,  298,  454,  377,  454,  379,  454,  380,  385,
 /*    20 */   386,  387,  388,  389,  454,  381,  454,  454,  363,  454,
 /*    30 */   365,  367,  368,  369,  454,  454,  390,  454,  392,  454,
 /*    40 */   393,  454,  394,  454,  395,  454,  396,  454,  397,  454,
 /*    50 */   398,  454,  399,  454,  400,  454,  401,  454,  402,  454,
 /*    60 */   403,  454,  404,  454,  405,  454,  406,  454,  407,  454,
 /*    70 */   454,  408,  454,  409,  454,  454,  302,  454,  454,  454,
 /*    80 */   313,  299,  454,  310,  350,  454,  348,  454,  351,  454,
 /*    90 */   454,  352,  454,  357,  359,  358,  349,  454,  454,  454,
 /*   100 */   353,  354,  454,  454,  454,  355,  356,  360,  453,  454,
 /*   110 */   452,  312,  314,  316,  454,  320,  331,  317,  454,  330,
 /*   120 */   454,  417,  454,  435,  454,  436,  454,  437,  454,  454,
 /*   130 */   440,  454,  413,  454,  454,  454,  416,  454,  454,  454,
 /*   140 */   454,  454,  418,  454,  454,  454,  454,  454,  419,  454,
 /*   150 */   454,  454,  420,  421,  454,  454,  454,  423,  425,  453,
 /*   160 */   428,  454,  434,  454,  426,  454,  454,  431,  433,  454,
 /*   170 */   438,  454,  439,  441,  442,  443,  444,  445,  446,  447,
 /*   180 */   448,  449,  450,  451,  432,  427,  454,  424,  422,  454,
 /*   190 */   318,  319,  454,  454,  454,  454,  454,  454,  454,  454,
 /*   200 */   454,  454,  454,  454,  454,  454,  454,  454,  454,  315,
 /*   210 */   311,  454,  303,  305,  453,  454,  306,  309,  454,  307,
 /*   220 */   308,  304,  300,  301,  454,  411,  454,  414,  454,  410,
 /*   230 */   454,  454,  454,  412,  454,  415,  391,  366,  454,  375,
 /*   240 */   454,  454,  370,  454,  372,  374,  373,  454,  361,  454,
 /*   250 */   454,  454,  454,  454,  454,  454,  454,  334,  336,  335,
 /*   260 */   454,  454,  454,  454,  454,  454,  454,  454,  337,  339,
 /*   270 */   338,  362,  454,  454,  454,  454,  454,  454,  454,  341,
 /*   280 */   454,  342,  454,  454,  344,  345,  343,  362,  454,  454,
 /*   290 */   454,  454,  347,
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
  "$",             "AGAINST",       "BETWEEN",       "EQUALS",      
  "NOTEQUALS",     "LESS",          "GREATER",       "GREATEREQUAL",
  "LESSEQUAL",     "AND",           "OR",            "LIKE",        
  "ILIKE",         "BITWISE_AND",   "BITWISE_OR",    "BITWISE_XOR", 
  "DIVIDE",        "TIMES",         "MOD",           "PLUS",        
  "MINUS",         "IS",            "IN",            "NOT",         
  "BITWISE_NOT",   "COMMA",         "SELECT",        "FROM",        
  "DISTINCT",      "ALL",           "IDENTIFIER",    "DOT",         
  "AS",            "INNER",         "JOIN",          "CROSS",       
  "LEFT",          "OUTER",         "RIGHT",         "FULL",        
  "ON",            "INSERT",        "INTO",          "VALUES",      
  "PARENTHESES_OPEN",  "PARENTHESES_CLOSE",  "UPDATE",        "SET",         
  "DELETE",        "WITH",          "WHERE",         "ORDER",       
  "BY",            "ASC",           "DESC",          "GROUP",       
  "HAVING",        "FOR",           "LIMIT",         "OFFSET",      
  "INTEGER",       "HINTEGER",      "NPLACEHOLDER",  "SPLACEHOLDER",
  "BPLACEHOLDER",  "EXISTS",        "CAST",          "CONVERT",     
  "USING",         "CASE",          "END",           "WHEN",        
  "THEN",          "ELSE",          "NULL",          "STRING",      
  "DOUBLE",        "TRUE",          "FALSE",         "error",       
  "program",       "query_language",  "select_statement",  "insert_statement",
  "update_statement",  "delete_statement",  "select_clause",  "where_clause",
  "group_clause",  "having_clause",  "order_clause",  "select_limit_clause",
  "for_update_clause",  "distinct_all",  "column_list",   "associated_name_list",
  "join_list_or_null",  "column_item",   "expr",          "associated_name",
  "join_list",     "join_item",     "join_clause",   "join_type",   
  "aliased_or_qualified_name",  "join_associated_name",  "join_conditions",  "values_list", 
  "field_list",    "value_list",    "value_item",    "field_item",  
  "update_clause",  "limit_clause",  "update_item_list",  "update_item", 
  "qualified_name",  "new_value",     "delete_clause",  "with_item",   
  "with_list",     "order_list",    "order_item",    "group_list",  
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
 /*   5 */ "select_statement ::= select_clause where_clause group_clause having_clause order_clause select_limit_clause for_update_clause",
 /*   6 */ "select_clause ::= SELECT distinct_all column_list FROM associated_name_list join_list_or_null",
 /*   7 */ "distinct_all ::= DISTINCT",
 /*   8 */ "distinct_all ::= ALL",
 /*   9 */ "distinct_all ::=",
 /*  10 */ "column_list ::= column_list COMMA column_item",
 /*  11 */ "column_list ::= column_item",
 /*  12 */ "column_item ::= TIMES",
 /*  13 */ "column_item ::= IDENTIFIER DOT TIMES",
 /*  14 */ "column_item ::= expr AS IDENTIFIER",
 /*  15 */ "column_item ::= expr IDENTIFIER",
 /*  16 */ "column_item ::= expr",
 /*  17 */ "associated_name_list ::= associated_name_list COMMA associated_name",
 /*  18 */ "associated_name_list ::= associated_name",
 /*  19 */ "join_list_or_null ::= join_list",
 /*  20 */ "join_list_or_null ::=",
 /*  21 */ "join_list ::= join_list join_item",
 /*  22 */ "join_list ::= join_item",
 /*  23 */ "join_item ::= join_clause",
 /*  24 */ "join_clause ::= join_type aliased_or_qualified_name join_associated_name join_conditions",
 /*  25 */ "join_associated_name ::= AS IDENTIFIER",
 /*  26 */ "join_associated_name ::= IDENTIFIER",
 /*  27 */ "join_associated_name ::=",
 /*  28 */ "join_type ::= INNER JOIN",
 /*  29 */ "join_type ::= CROSS JOIN",
 /*  30 */ "join_type ::= LEFT OUTER JOIN",
 /*  31 */ "join_type ::= LEFT JOIN",
 /*  32 */ "join_type ::= RIGHT OUTER JOIN",
 /*  33 */ "join_type ::= RIGHT JOIN",
 /*  34 */ "join_type ::= FULL OUTER JOIN",
 /*  35 */ "join_type ::= FULL JOIN",
 /*  36 */ "join_type ::= JOIN",
 /*  37 */ "join_conditions ::= ON expr",
 /*  38 */ "join_conditions ::=",
 /*  39 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  40 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name PARENTHESES_OPEN field_list PARENTHESES_CLOSE VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  41 */ "values_list ::= values_list COMMA value_item",
 /*  42 */ "values_list ::= value_item",
 /*  43 */ "value_item ::= expr",
 /*  44 */ "field_list ::= field_list COMMA field_item",
 /*  45 */ "field_list ::= field_item",
 /*  46 */ "field_item ::= IDENTIFIER",
 /*  47 */ "update_statement ::= update_clause where_clause limit_clause",
 /*  48 */ "update_clause ::= UPDATE associated_name SET update_item_list",
 /*  49 */ "update_item_list ::= update_item_list COMMA update_item",
 /*  50 */ "update_item_list ::= update_item",
 /*  51 */ "update_item ::= qualified_name EQUALS new_value",
 /*  52 */ "new_value ::= expr",
 /*  53 */ "delete_statement ::= delete_clause where_clause limit_clause",
 /*  54 */ "delete_clause ::= DELETE FROM associated_name",
 /*  55 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER",
 /*  56 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER",
 /*  57 */ "associated_name ::= aliased_or_qualified_name",
 /*  58 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER WITH with_item",
 /*  59 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER WITH PARENTHESES_OPEN with_list PARENTHESES_CLOSE",
 /*  60 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER WITH PARENTHESES_OPEN with_list PARENTHESES_CLOSE",
 /*  61 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER WITH with_item",
 /*  62 */ "associated_name ::= aliased_or_qualified_name WITH PARENTHESES_OPEN with_list PARENTHESES_CLOSE",
 /*  63 */ "associated_name ::= aliased_or_qualified_name WITH with_item",
 /*  64 */ "with_list ::= with_list COMMA with_item",
 /*  65 */ "with_list ::= with_item",
 /*  66 */ "with_item ::= IDENTIFIER",
 /*  67 */ "aliased_or_qualified_name ::= qualified_name",
 /*  68 */ "where_clause ::= WHERE expr",
 /*  69 */ "where_clause ::=",
 /*  70 */ "order_clause ::= ORDER BY order_list",
 /*  71 */ "order_clause ::=",
 /*  72 */ "order_list ::= order_list COMMA order_item",
 /*  73 */ "order_list ::= order_item",
 /*  74 */ "order_item ::= expr",
 /*  75 */ "order_item ::= expr ASC",
 /*  76 */ "order_item ::= expr DESC",
 /*  77 */ "group_clause ::= GROUP BY group_list",
 /*  78 */ "group_clause ::=",
 /*  79 */ "group_list ::= group_list COMMA group_item",
 /*  80 */ "group_list ::= group_item",
 /*  81 */ "group_item ::= expr",
 /*  82 */ "having_clause ::= HAVING expr",
 /*  83 */ "having_clause ::=",
 /*  84 */ "for_update_clause ::= FOR UPDATE",
 /*  85 */ "for_update_clause ::=",
 /*  86 */ "select_limit_clause ::= LIMIT integer_or_placeholder",
 /*  87 */ "select_limit_clause ::= LIMIT integer_or_placeholder COMMA integer_or_placeholder",
 /*  88 */ "select_limit_clause ::= LIMIT integer_or_placeholder OFFSET integer_or_placeholder",
 /*  89 */ "select_limit_clause ::=",
 /*  90 */ "limit_clause ::= LIMIT integer_or_placeholder",
 /*  91 */ "limit_clause ::=",
 /*  92 */ "integer_or_placeholder ::= INTEGER",
 /*  93 */ "integer_or_placeholder ::= HINTEGER",
 /*  94 */ "integer_or_placeholder ::= NPLACEHOLDER",
 /*  95 */ "integer_or_placeholder ::= SPLACEHOLDER",
 /*  96 */ "integer_or_placeholder ::= BPLACEHOLDER",
 /*  97 */ "expr ::= MINUS expr",
 /*  98 */ "expr ::= expr MINUS expr",
 /*  99 */ "expr ::= expr PLUS expr",
 /* 100 */ "expr ::= expr TIMES expr",
 /* 101 */ "expr ::= expr DIVIDE expr",
 /* 102 */ "expr ::= expr MOD expr",
 /* 103 */ "expr ::= expr AND expr",
 /* 104 */ "expr ::= expr OR expr",
 /* 105 */ "expr ::= expr BITWISE_AND expr",
 /* 106 */ "expr ::= expr BITWISE_OR expr",
 /* 107 */ "expr ::= expr BITWISE_XOR expr",
 /* 108 */ "expr ::= expr EQUALS expr",
 /* 109 */ "expr ::= expr NOTEQUALS expr",
 /* 110 */ "expr ::= expr LESS expr",
 /* 111 */ "expr ::= expr GREATER expr",
 /* 112 */ "expr ::= expr GREATEREQUAL expr",
 /* 113 */ "expr ::= expr LESSEQUAL expr",
 /* 114 */ "expr ::= expr LIKE expr",
 /* 115 */ "expr ::= expr NOT LIKE expr",
 /* 116 */ "expr ::= expr ILIKE expr",
 /* 117 */ "expr ::= expr NOT ILIKE expr",
 /* 118 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 119 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 120 */ "expr ::= PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 121 */ "expr ::= expr IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 122 */ "expr ::= expr NOT IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 123 */ "expr ::= EXISTS PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 124 */ "expr ::= expr AGAINST expr",
 /* 125 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 126 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 127 */ "expr ::= CASE expr when_clauses END",
 /* 128 */ "when_clauses ::= when_clauses when_clause",
 /* 129 */ "when_clauses ::= when_clause",
 /* 130 */ "when_clause ::= WHEN expr THEN expr",
 /* 131 */ "when_clause ::= ELSE expr",
 /* 132 */ "expr ::= function_call",
 /* 133 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN distinct_or_null argument_list_or_null PARENTHESES_CLOSE",
 /* 134 */ "distinct_or_null ::= DISTINCT",
 /* 135 */ "distinct_or_null ::=",
 /* 136 */ "argument_list_or_null ::= argument_list",
 /* 137 */ "argument_list_or_null ::=",
 /* 138 */ "argument_list ::= argument_list COMMA argument_item",
 /* 139 */ "argument_list ::= argument_item",
 /* 140 */ "argument_item ::= TIMES",
 /* 141 */ "argument_item ::= expr",
 /* 142 */ "expr ::= expr IS NULL",
 /* 143 */ "expr ::= expr IS NOT NULL",
 /* 144 */ "expr ::= expr BETWEEN expr",
 /* 145 */ "expr ::= NOT expr",
 /* 146 */ "expr ::= BITWISE_NOT expr",
 /* 147 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 148 */ "expr ::= qualified_name",
 /* 149 */ "expr ::= INTEGER",
 /* 150 */ "expr ::= HINTEGER",
 /* 151 */ "expr ::= STRING",
 /* 152 */ "expr ::= DOUBLE",
 /* 153 */ "expr ::= NULL",
 /* 154 */ "expr ::= TRUE",
 /* 155 */ "expr ::= FALSE",
 /* 156 */ "expr ::= NPLACEHOLDER",
 /* 157 */ "expr ::= SPLACEHOLDER",
 /* 158 */ "expr ::= BPLACEHOLDER",
 /* 159 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 160 */ "qualified_name ::= IDENTIFIER",
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
#line 110 "parser.php5.lemon"
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
#line 822 "parser.php5.c"
      break;
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 88:
    case 94:
    case 95:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 108:
    case 109:
    case 111:
    case 112:
    case 114:
    case 115:
    case 118:
    case 119:
    case 120:
    case 121:
    case 122:
    case 123:
#line 123 "parser.php5.lemon"
{
    zval_ptr_dtor(&(yypminor->yy162));
}
#line 857 "parser.php5.c"
      break;
    case 87:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 105:
    case 106:
    case 113:
    case 130:
    case 131:
#line 505 "parser.php5.lemon"
{
    zephir_safe_zval_ptr_dtor((yypminor->yy162));
}
#line 874 "parser.php5.c"
      break;
    case 116:
    case 124:
    case 126:
    case 129:
    case 132:
#line 940 "parser.php5.lemon"
{
	zval_ptr_dtor(&(yypminor->yy162));
}
#line 885 "parser.php5.c"
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
  { 80, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 82, 7 },
  { 86, 6 },
  { 93, 1 },
  { 93, 1 },
  { 93, 0 },
  { 94, 3 },
  { 94, 1 },
  { 97, 1 },
  { 97, 3 },
  { 97, 3 },
  { 97, 2 },
  { 97, 1 },
  { 95, 3 },
  { 95, 1 },
  { 96, 1 },
  { 96, 0 },
  { 100, 2 },
  { 100, 1 },
  { 101, 1 },
  { 102, 4 },
  { 105, 2 },
  { 105, 1 },
  { 105, 0 },
  { 103, 2 },
  { 103, 2 },
  { 103, 3 },
  { 103, 2 },
  { 103, 3 },
  { 103, 2 },
  { 103, 3 },
  { 103, 2 },
  { 103, 1 },
  { 106, 2 },
  { 106, 0 },
  { 83, 7 },
  { 83, 10 },
  { 107, 3 },
  { 107, 1 },
  { 110, 1 },
  { 108, 3 },
  { 108, 1 },
  { 111, 1 },
  { 84, 3 },
  { 112, 4 },
  { 114, 3 },
  { 114, 1 },
  { 115, 3 },
  { 117, 1 },
  { 85, 3 },
  { 118, 3 },
  { 99, 3 },
  { 99, 2 },
  { 99, 1 },
  { 99, 5 },
  { 99, 7 },
  { 99, 6 },
  { 99, 4 },
  { 99, 5 },
  { 99, 3 },
  { 120, 3 },
  { 120, 1 },
  { 119, 1 },
  { 104, 1 },
  { 87, 2 },
  { 87, 0 },
  { 90, 3 },
  { 90, 0 },
  { 121, 3 },
  { 121, 1 },
  { 122, 1 },
  { 122, 2 },
  { 122, 2 },
  { 88, 3 },
  { 88, 0 },
  { 123, 3 },
  { 123, 1 },
  { 124, 1 },
  { 89, 2 },
  { 89, 0 },
  { 92, 2 },
  { 92, 0 },
  { 91, 2 },
  { 91, 4 },
  { 91, 4 },
  { 91, 0 },
  { 113, 2 },
  { 113, 0 },
  { 125, 1 },
  { 125, 1 },
  { 125, 1 },
  { 125, 1 },
  { 125, 1 },
  { 98, 2 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 4 },
  { 98, 3 },
  { 98, 4 },
  { 98, 5 },
  { 98, 6 },
  { 98, 3 },
  { 98, 5 },
  { 98, 6 },
  { 98, 4 },
  { 98, 3 },
  { 98, 6 },
  { 98, 6 },
  { 98, 4 },
  { 127, 2 },
  { 127, 1 },
  { 128, 4 },
  { 128, 2 },
  { 98, 1 },
  { 129, 5 },
  { 130, 1 },
  { 130, 0 },
  { 131, 1 },
  { 131, 0 },
  { 126, 3 },
  { 126, 1 },
  { 132, 1 },
  { 132, 1 },
  { 98, 3 },
  { 98, 4 },
  { 98, 3 },
  { 98, 2 },
  { 98, 2 },
  { 98, 3 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 116, 3 },
  { 116, 1 },
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
#line 119 "parser.php5.lemon"
{
	status->ret = yymsp[0].minor.yy162;
}
#line 1263 "parser.php5.c"
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 18:
      case 19:
      case 22:
      case 23:
      case 43:
      case 50:
      case 52:
      case 65:
      case 67:
      case 73:
      case 80:
      case 81:
      case 132:
      case 136:
      case 141:
      case 148:
#line 127 "parser.php5.lemon"
{
	yygotominor.yy162 = yymsp[0].minor.yy162;
}
#line 1289 "parser.php5.c"
        break;
      case 5:
#line 147 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_select_statement(yymsp[-6].minor.yy162, yymsp[-5].minor.yy162, yymsp[-2].minor.yy162, yymsp[-4].minor.yy162, yymsp[-3].minor.yy162, yymsp[-1].minor.yy162, yymsp[0].minor.yy162);
}
#line 1296 "parser.php5.c"
        break;
      case 6:
#line 155 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_select_clause(yymsp[-4].minor.yy162, yymsp[-3].minor.yy162, yymsp[-1].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(26,&yymsp[-5].minor);
  yy_destructor(27,&yymsp[-2].minor);
}
#line 1305 "parser.php5.c"
        break;
      case 7:
#line 163 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_distinct_all(1);
  yy_destructor(28,&yymsp[0].minor);
}
#line 1313 "parser.php5.c"
        break;
      case 8:
#line 167 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_distinct_all(0);
  yy_destructor(29,&yymsp[0].minor);
}
#line 1321 "parser.php5.c"
        break;
      case 9:
      case 20:
      case 27:
      case 38:
      case 69:
      case 71:
      case 78:
      case 83:
      case 85:
      case 89:
      case 91:
      case 135:
      case 137:
#line 171 "parser.php5.lemon"
{
	yygotominor.yy162 = NULL;
}
#line 1340 "parser.php5.c"
        break;
      case 10:
      case 17:
      case 41:
      case 44:
      case 49:
      case 64:
      case 72:
      case 79:
      case 138:
#line 179 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_zval_list(yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1356 "parser.php5.c"
        break;
      case 11:
      case 42:
      case 45:
      case 129:
      case 139:
#line 183 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_zval_list(yymsp[0].minor.yy162, NULL);
}
#line 1367 "parser.php5.c"
        break;
      case 12:
      case 140:
#line 191 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
  yy_destructor(17,&yymsp[0].minor);
}
#line 1376 "parser.php5.c"
        break;
      case 13:
#line 195 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(31,&yymsp[-1].minor);
  yy_destructor(17,&yymsp[0].minor);
}
#line 1385 "parser.php5.c"
        break;
      case 14:
#line 199 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy162, NULL, yymsp[0].minor.yy0);
  yy_destructor(32,&yymsp[-1].minor);
}
#line 1393 "parser.php5.c"
        break;
      case 15:
#line 203 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy162, NULL, yymsp[0].minor.yy0);
}
#line 1400 "parser.php5.c"
        break;
      case 16:
#line 207 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy162, NULL, NULL);
}
#line 1407 "parser.php5.c"
        break;
      case 21:
      case 128:
#line 235 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_zval_list(yymsp[-1].minor.yy162, yymsp[0].minor.yy162);
}
#line 1415 "parser.php5.c"
        break;
      case 24:
#line 256 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_join_item(yymsp[-3].minor.yy162, yymsp[-2].minor.yy162, yymsp[-1].minor.yy162, yymsp[0].minor.yy162);
}
#line 1422 "parser.php5.c"
        break;
      case 25:
#line 264 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
  yy_destructor(32,&yymsp[-1].minor);
}
#line 1430 "parser.php5.c"
        break;
      case 26:
      case 46:
      case 66:
      case 160:
#line 268 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
}
#line 1440 "parser.php5.c"
        break;
      case 28:
#line 280 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
#line 1449 "parser.php5.c"
        break;
      case 29:
#line 284 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
#line 1458 "parser.php5.c"
        break;
      case 30:
#line 288 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(36,&yymsp[-2].minor);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
#line 1468 "parser.php5.c"
        break;
      case 31:
#line 292 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
#line 1477 "parser.php5.c"
        break;
      case 32:
#line 296 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(38,&yymsp[-2].minor);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
#line 1487 "parser.php5.c"
        break;
      case 33:
#line 300 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(38,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
#line 1496 "parser.php5.c"
        break;
      case 34:
#line 304 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
#line 1506 "parser.php5.c"
        break;
      case 35:
#line 308 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(39,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
#line 1515 "parser.php5.c"
        break;
      case 36:
#line 312 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(34,&yymsp[0].minor);
}
#line 1523 "parser.php5.c"
        break;
      case 37:
#line 320 "parser.php5.lemon"
{
	yygotominor.yy162 = yymsp[0].minor.yy162;
  yy_destructor(40,&yymsp[-1].minor);
}
#line 1531 "parser.php5.c"
        break;
      case 39:
#line 333 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_insert_statement(yymsp[-4].minor.yy162, NULL, yymsp[-1].minor.yy162);
  yy_destructor(41,&yymsp[-6].minor);
  yy_destructor(42,&yymsp[-5].minor);
  yy_destructor(43,&yymsp[-3].minor);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1543 "parser.php5.c"
        break;
      case 40:
#line 337 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_insert_statement(yymsp[-7].minor.yy162, yymsp[-5].minor.yy162, yymsp[-1].minor.yy162);
  yy_destructor(41,&yymsp[-9].minor);
  yy_destructor(42,&yymsp[-8].minor);
  yy_destructor(44,&yymsp[-6].minor);
  yy_destructor(45,&yymsp[-4].minor);
  yy_destructor(43,&yymsp[-3].minor);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1557 "parser.php5.c"
        break;
      case 47:
#line 383 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_update_statement(yymsp[-2].minor.yy162, yymsp[-1].minor.yy162, yymsp[0].minor.yy162);
}
#line 1564 "parser.php5.c"
        break;
      case 48:
#line 391 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_update_clause(yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(46,&yymsp[-3].minor);
  yy_destructor(47,&yymsp[-1].minor);
}
#line 1573 "parser.php5.c"
        break;
      case 51:
#line 411 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_update_item(yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(3,&yymsp[-1].minor);
}
#line 1581 "parser.php5.c"
        break;
      case 53:
#line 425 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_delete_statement(yymsp[-2].minor.yy162, yymsp[-1].minor.yy162, yymsp[0].minor.yy162);
}
#line 1588 "parser.php5.c"
        break;
      case 54:
#line 433 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_delete_clause(yymsp[0].minor.yy162);
  yy_destructor(48,&yymsp[-2].minor);
  yy_destructor(27,&yymsp[-1].minor);
}
#line 1597 "parser.php5.c"
        break;
      case 55:
#line 441 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_assoc_name(yymsp[-2].minor.yy162, yymsp[0].minor.yy0, NULL);
  yy_destructor(32,&yymsp[-1].minor);
}
#line 1605 "parser.php5.c"
        break;
      case 56:
#line 445 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_assoc_name(yymsp[-1].minor.yy162, yymsp[0].minor.yy0, NULL);
}
#line 1612 "parser.php5.c"
        break;
      case 57:
#line 449 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_assoc_name(yymsp[0].minor.yy162, NULL, NULL);
}
#line 1619 "parser.php5.c"
        break;
      case 58:
#line 453 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_assoc_name(yymsp[-4].minor.yy162, yymsp[-2].minor.yy0, yymsp[0].minor.yy162);
  yy_destructor(32,&yymsp[-3].minor);
  yy_destructor(49,&yymsp[-1].minor);
}
#line 1628 "parser.php5.c"
        break;
      case 59:
#line 457 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_assoc_name(yymsp[-6].minor.yy162, yymsp[-4].minor.yy0, yymsp[-1].minor.yy162);
  yy_destructor(32,&yymsp[-5].minor);
  yy_destructor(49,&yymsp[-3].minor);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1639 "parser.php5.c"
        break;
      case 60:
#line 461 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_assoc_name(yymsp[-5].minor.yy162, yymsp[-4].minor.yy0, yymsp[-1].minor.yy162);
  yy_destructor(49,&yymsp[-3].minor);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1649 "parser.php5.c"
        break;
      case 61:
#line 465 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_assoc_name(yymsp[-3].minor.yy162, yymsp[-2].minor.yy0, yymsp[0].minor.yy162);
  yy_destructor(49,&yymsp[-1].minor);
}
#line 1657 "parser.php5.c"
        break;
      case 62:
#line 469 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_assoc_name(yymsp[-4].minor.yy162, NULL, yymsp[-1].minor.yy162);
  yy_destructor(49,&yymsp[-3].minor);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1667 "parser.php5.c"
        break;
      case 63:
#line 473 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_assoc_name(yymsp[-2].minor.yy162, NULL, yymsp[0].minor.yy162);
  yy_destructor(49,&yymsp[-1].minor);
}
#line 1675 "parser.php5.c"
        break;
      case 68:
#line 509 "parser.php5.lemon"
{
	yygotominor.yy162 = yymsp[0].minor.yy162;
  yy_destructor(50,&yymsp[-1].minor);
}
#line 1683 "parser.php5.c"
        break;
      case 70:
#line 521 "parser.php5.lemon"
{
	yygotominor.yy162 = yymsp[0].minor.yy162;
  yy_destructor(51,&yymsp[-2].minor);
  yy_destructor(52,&yymsp[-1].minor);
}
#line 1692 "parser.php5.c"
        break;
      case 74:
#line 545 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_order_item(yymsp[0].minor.yy162, 0);
}
#line 1699 "parser.php5.c"
        break;
      case 75:
#line 549 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_order_item(yymsp[-1].minor.yy162, PHQL_T_ASC);
  yy_destructor(53,&yymsp[0].minor);
}
#line 1707 "parser.php5.c"
        break;
      case 76:
#line 553 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_order_item(yymsp[-1].minor.yy162, PHQL_T_DESC);
  yy_destructor(54,&yymsp[0].minor);
}
#line 1715 "parser.php5.c"
        break;
      case 77:
#line 561 "parser.php5.lemon"
{
	yygotominor.yy162 = yymsp[0].minor.yy162;
  yy_destructor(55,&yymsp[-2].minor);
  yy_destructor(52,&yymsp[-1].minor);
}
#line 1724 "parser.php5.c"
        break;
      case 82:
#line 593 "parser.php5.lemon"
{
	yygotominor.yy162 = yymsp[0].minor.yy162;
  yy_destructor(56,&yymsp[-1].minor);
}
#line 1732 "parser.php5.c"
        break;
      case 84:
#line 605 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_for_update_clause();
  yy_destructor(57,&yymsp[-1].minor);
  yy_destructor(46,&yymsp[0].minor);
}
#line 1741 "parser.php5.c"
        break;
      case 86:
      case 90:
#line 617 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_limit_clause(yymsp[0].minor.yy162, NULL);
  yy_destructor(58,&yymsp[-1].minor);
}
#line 1750 "parser.php5.c"
        break;
      case 87:
#line 621 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_limit_clause(yymsp[0].minor.yy162, yymsp[-2].minor.yy162);
  yy_destructor(58,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1759 "parser.php5.c"
        break;
      case 88:
#line 625 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_limit_clause(yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(58,&yymsp[-3].minor);
  yy_destructor(59,&yymsp[-1].minor);
}
#line 1768 "parser.php5.c"
        break;
      case 92:
      case 149:
#line 645 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
#line 1776 "parser.php5.c"
        break;
      case 93:
      case 150:
#line 649 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_literal_zval(PHQL_T_HINTEGER, yymsp[0].minor.yy0);
}
#line 1784 "parser.php5.c"
        break;
      case 94:
      case 156:
#line 653 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 1792 "parser.php5.c"
        break;
      case 95:
      case 157:
#line 657 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 1800 "parser.php5.c"
        break;
      case 96:
      case 158:
#line 661 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_placeholder_zval(PHQL_T_BPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 1808 "parser.php5.c"
        break;
      case 97:
#line 669 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy162);
  yy_destructor(20,&yymsp[-1].minor);
}
#line 1816 "parser.php5.c"
        break;
      case 98:
#line 673 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(20,&yymsp[-1].minor);
}
#line 1824 "parser.php5.c"
        break;
      case 99:
#line 677 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(19,&yymsp[-1].minor);
}
#line 1832 "parser.php5.c"
        break;
      case 100:
#line 681 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(17,&yymsp[-1].minor);
}
#line 1840 "parser.php5.c"
        break;
      case 101:
#line 685 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(16,&yymsp[-1].minor);
}
#line 1848 "parser.php5.c"
        break;
      case 102:
#line 689 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(18,&yymsp[-1].minor);
}
#line 1856 "parser.php5.c"
        break;
      case 103:
#line 693 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(9,&yymsp[-1].minor);
}
#line 1864 "parser.php5.c"
        break;
      case 104:
#line 697 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(10,&yymsp[-1].minor);
}
#line 1872 "parser.php5.c"
        break;
      case 105:
#line 701 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_BITWISE_AND, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(13,&yymsp[-1].minor);
}
#line 1880 "parser.php5.c"
        break;
      case 106:
#line 705 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_BITWISE_OR, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(14,&yymsp[-1].minor);
}
#line 1888 "parser.php5.c"
        break;
      case 107:
#line 709 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_BITWISE_XOR, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(15,&yymsp[-1].minor);
}
#line 1896 "parser.php5.c"
        break;
      case 108:
#line 713 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(3,&yymsp[-1].minor);
}
#line 1904 "parser.php5.c"
        break;
      case 109:
#line 717 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(4,&yymsp[-1].minor);
}
#line 1912 "parser.php5.c"
        break;
      case 110:
#line 721 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(5,&yymsp[-1].minor);
}
#line 1920 "parser.php5.c"
        break;
      case 111:
#line 725 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(6,&yymsp[-1].minor);
}
#line 1928 "parser.php5.c"
        break;
      case 112:
#line 729 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(7,&yymsp[-1].minor);
}
#line 1936 "parser.php5.c"
        break;
      case 113:
#line 733 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(8,&yymsp[-1].minor);
}
#line 1944 "parser.php5.c"
        break;
      case 114:
#line 737 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(11,&yymsp[-1].minor);
}
#line 1952 "parser.php5.c"
        break;
      case 115:
#line 741 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(23,&yymsp[-2].minor);
  yy_destructor(11,&yymsp[-1].minor);
}
#line 1961 "parser.php5.c"
        break;
      case 116:
#line 745 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_ILIKE, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(12,&yymsp[-1].minor);
}
#line 1969 "parser.php5.c"
        break;
      case 117:
#line 749 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_NILIKE, yymsp[-3].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(23,&yymsp[-2].minor);
  yy_destructor(12,&yymsp[-1].minor);
}
#line 1978 "parser.php5.c"
        break;
      case 118:
      case 121:
#line 753 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy162, yymsp[-1].minor.yy162);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 1989 "parser.php5.c"
        break;
      case 119:
      case 122:
#line 757 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy162, yymsp[-1].minor.yy162);
  yy_destructor(23,&yymsp[-4].minor);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 2001 "parser.php5.c"
        break;
      case 120:
#line 761 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_SUBQUERY, yymsp[-1].minor.yy162, NULL);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 2010 "parser.php5.c"
        break;
      case 123:
#line 773 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_EXISTS, NULL, yymsp[-1].minor.yy162);
  yy_destructor(65,&yymsp[-3].minor);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 2020 "parser.php5.c"
        break;
      case 124:
#line 777 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_AGAINST, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(1,&yymsp[-1].minor);
}
#line 2028 "parser.php5.c"
        break;
      case 125:
#line 781 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_CAST, yymsp[-3].minor.yy162, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(66,&yymsp[-5].minor);
  yy_destructor(44,&yymsp[-4].minor);
  yy_destructor(32,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 2039 "parser.php5.c"
        break;
      case 126:
#line 785 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_CONVERT, yymsp[-3].minor.yy162, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(67,&yymsp[-5].minor);
  yy_destructor(44,&yymsp[-4].minor);
  yy_destructor(68,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 2050 "parser.php5.c"
        break;
      case 127:
#line 789 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_CASE, yymsp[-2].minor.yy162, yymsp[-1].minor.yy162);
  yy_destructor(69,&yymsp[-3].minor);
  yy_destructor(70,&yymsp[0].minor);
}
#line 2059 "parser.php5.c"
        break;
      case 130:
#line 801 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_WHEN, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(71,&yymsp[-3].minor);
  yy_destructor(72,&yymsp[-1].minor);
}
#line 2068 "parser.php5.c"
        break;
      case 131:
#line 805 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_ELSE, yymsp[0].minor.yy162, NULL);
  yy_destructor(73,&yymsp[-1].minor);
}
#line 2076 "parser.php5.c"
        break;
      case 133:
#line 817 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_func_call(yymsp[-4].minor.yy0, yymsp[-1].minor.yy162, yymsp[-2].minor.yy162);
  yy_destructor(44,&yymsp[-3].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 2085 "parser.php5.c"
        break;
      case 134:
#line 825 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_distinct();
  yy_destructor(28,&yymsp[0].minor);
}
#line 2093 "parser.php5.c"
        break;
      case 142:
#line 869 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy162, NULL);
  yy_destructor(21,&yymsp[-1].minor);
  yy_destructor(74,&yymsp[0].minor);
}
#line 2102 "parser.php5.c"
        break;
      case 143:
#line 873 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy162, NULL);
  yy_destructor(21,&yymsp[-2].minor);
  yy_destructor(23,&yymsp[-1].minor);
  yy_destructor(74,&yymsp[0].minor);
}
#line 2112 "parser.php5.c"
        break;
      case 144:
#line 877 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_BETWEEN, yymsp[-2].minor.yy162, yymsp[0].minor.yy162);
  yy_destructor(2,&yymsp[-1].minor);
}
#line 2120 "parser.php5.c"
        break;
      case 145:
#line 881 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy162);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 2128 "parser.php5.c"
        break;
      case 146:
#line 885 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, yymsp[0].minor.yy162);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 2136 "parser.php5.c"
        break;
      case 147:
#line 889 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy162, NULL);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
#line 2145 "parser.php5.c"
        break;
      case 151:
#line 905 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
#line 2152 "parser.php5.c"
        break;
      case 152:
#line 909 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
#line 2159 "parser.php5.c"
        break;
      case 153:
#line 913 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(74,&yymsp[0].minor);
}
#line 2167 "parser.php5.c"
        break;
      case 154:
#line 917 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  yy_destructor(77,&yymsp[0].minor);
}
#line 2175 "parser.php5.c"
        break;
      case 155:
#line 921 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  yy_destructor(78,&yymsp[0].minor);
}
#line 2183 "parser.php5.c"
        break;
      case 159:
#line 944 "parser.php5.lemon"
{
	yygotominor.yy162 = phql_ret_qualified_name(NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
#line 2191 "parser.php5.c"
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
#line 43 "parser.php5.lemon"

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

#line 2300 "parser.php5.c"
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
