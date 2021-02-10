/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
#line 30 "parser.php7.lemon"

#include "parser.php7.inc.h"

#line 12 "parser.php7.c"
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
#define YYNOCODE 135
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval yy202;
  int yy269;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 295
#define YYNRULE 162
#define YYERRORSYMBOL 80
#define YYERRSYMDT yy269
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
 /*     0 */   120,  126,  128,   55,   57,   59,   61,   63,   65,   45,
 /*    10 */    47,   67,   72,   49,   51,   53,   41,   39,   43,   37,
 /*    20 */    34,  122,   74,   69,  120,  126,  128,   55,   57,   59,
 /*    30 */    61,   63,   65,   45,   47,   67,   72,   49,   51,   53,
 /*    40 */    41,   39,   43,   37,   34,  122,   74,   69,   19,   20,
 /*    50 */    21,   22,   23,   32,   33,  120,  126,  128,   55,   57,
 /*    60 */    59,   61,   63,   65,   45,   47,   67,   72,   49,   51,
 /*    70 */    53,   41,   39,   43,   37,   34,  122,   74,   69,   37,
 /*    80 */    34,  122,   74,   69,   94,  222,   81,  220,   95,   90,
 /*    90 */   111,  211,  113,  114,  213,  156,   79,  188,   89,  120,
 /*   100 */   126,  128,   55,   57,   59,   61,   63,   65,   45,   47,
 /*   110 */    67,   72,   49,   51,   53,   41,   39,   43,   37,   34,
 /*   120 */   122,   74,   69,   55,   57,   59,   61,   63,   65,   45,
 /*   130 */    47,   67,   72,   49,   51,   53,   41,   39,   43,   37,
 /*   140 */    34,  122,   74,   69,  132,  249,  120,  126,  128,   55,
 /*   150 */    57,   59,   61,   63,   65,   45,   47,   67,   72,   49,
 /*   160 */    51,   53,   41,   39,   43,   37,   34,  122,   74,   69,
 /*   170 */    41,   39,   43,   37,   34,  122,   74,   69,  142,    7,
 /*   180 */   120,  126,  128,   55,   57,   59,   61,   63,   65,   45,
 /*   190 */    47,   67,   72,   49,   51,   53,   41,   39,   43,   37,
 /*   200 */    34,  122,   74,   69,  120,  126,  128,   55,   57,   59,
 /*   210 */    61,   63,   65,   45,   47,   67,   72,   49,   51,   53,
 /*   220 */    41,   39,   43,   37,   34,  122,   74,   69,   45,   47,
 /*   230 */    67,   72,   49,   51,   53,   41,   39,   43,   37,   34,
 /*   240 */   122,   74,   69,  122,   74,   69,  154,  156,  148,  188,
 /*   250 */   120,  126,  128,   55,   57,   59,   61,   63,   65,   45,
 /*   260 */    47,   67,   72,   49,   51,   53,   41,   39,   43,   37,
 /*   270 */    34,  122,   74,   69,  170,  242,  158,   35,   95,   99,
 /*   280 */   171,  173,    8,   76,  112,  113,  114,  161,   49,   51,
 /*   290 */    53,   41,   39,   43,   37,   34,  122,   74,   69,   83,
 /*   300 */   170,  130,  295,   35,   84,   92,  171,  173,  296,  194,
 /*   310 */   210,  196,  198,  161,  202,  206,  107,  176,  177,  183,
 /*   320 */   184,  185,  135,  139,  145,  100,  151,  130,  432,  124,
 /*   330 */    17,  180,  178,  179,  181,  182,  297,  228,  236,  224,
 /*   340 */   225,    6,    6,  176,  177,  183,  184,  185,  135,  139,
 /*   350 */   145,  115,  151,  164,  164,  298,   94,  180,  178,  179,
 /*   360 */   181,  182,  215,  107,   24,   35,   70,  230,  171,  173,
 /*   370 */    98,  175,  175,   95,  104,  216,   92,  232,   76,  299,
 /*   380 */   123,  226,  234,   92,  160,  160,  119,  186,  186,  130,
 /*   390 */   193,   35,  191,  251,  171,  173,   91,   76,  278,   94,
 /*   400 */   292,  161,  240,  105,  175,  176,  177,  183,  184,  185,
 /*   410 */   135,  139,  145,  103,  151,  130,   82,  160,    9,  180,
 /*   420 */   178,  179,  181,  182,  194,  210,  196,  198,   26,  202,
 /*   430 */   206,  176,  177,  183,  184,  185,  135,  139,  145,   10,
 /*   440 */   151,  164,   31,  153,  190,  180,  178,  179,  181,  182,
 /*   450 */   170,  218,   96,   35,   85,  109,  171,  173,  137,  175,
 /*   460 */   175,  168,    6,  161,  110,   28,  239,   15,  162,  167,
 /*   470 */   168,  102,  160,  160,  165,  186,   11,  130,  217,   35,
 /*   480 */    13,  431,  171,  173,   12,  201,  121,  247,  199,  161,
 /*   490 */   227,  162,   14,  176,  177,  183,  184,  185,  135,  139,
 /*   500 */   145,   27,  151,  130,  175,  175,   16,  180,  178,  179,
 /*   510 */   181,  182,  244,  248,  281,  288,  284,  160,  160,  176,
 /*   520 */   177,  183,  184,  185,  135,  139,  145,   18,  151,  205,
 /*   530 */   254,  262,  203,  180,  178,  179,  181,  182,   67,   72,
 /*   540 */    49,   51,   53,   41,   39,   43,   37,   34,  122,   74,
 /*   550 */    69,  209,   78,   25,  207,  223,  219,  253,  258,  458,
 /*   560 */     1,    2,    3,    4,    5,    6,  133,   29,  168,  107,
 /*   570 */     6,   77,  260,  263,  175,   31,  272,   69,  257,  283,
 /*   580 */   284,  256,  131,  260,  261,   75,  127,  160,  235,  108,
 /*   590 */   175,  273,  267,  175,   86,  261,  109,  289,   94,   30,
 /*   600 */   175,  175,  164,  160,  175,  279,  160,   80,  214,  219,
 /*   610 */    84,  212,  247,  160,  160,   87,   84,  160,   88,  260,
 /*   620 */   175,  238,  107,  287,   93,   97,   36,  175,  107,  101,
 /*   630 */   175,  259,  106,  160,  110,   38,  169,  175,  246,  175,
 /*   640 */   160,  175,  286,  160,  175,   40,   42,   44,  269,   46,
 /*   650 */   160,  386,  160,  175,  160,   48,   50,  160,  116,  125,
 /*   660 */   118,   52,  117,  175,  175,  175,  160,  175,  264,  258,
 /*   670 */    54,  134,   56,  175,  175,   58,  160,  160,  160,  175,
 /*   680 */   160,   60,   62,  136,   64,   76,  160,  160,  175,  268,
 /*   690 */   175,   66,  160,  175,  138,  140,  143,  149,  144,  175,
 /*   700 */   175,  160,  175,  160,  146,  187,  160,   68,   71,  175,
 /*   710 */   276,   73,  160,  160,  129,  160,  141,  147,  150,  152,
 /*   720 */   155,  163,  160,  157,  166,  175,  175,  192,  159,  175,
 /*   730 */   195,  172,  175,  174,  175,  175,  323,  175,  160,  160,
 /*   740 */   189,  175,  160,  231,  197,  160,  175,  160,  160,  175,
 /*   750 */   160,  175,  241,  324,  160,  250,  200,  325,  175,  160,
 /*   760 */   326,  175,  160,  204,  160,  327,  328,  294,  208,  329,
 /*   770 */   175,  160,   84,  175,  160,  330,  331,  221,  229,  245,
 /*   780 */   243,  233,  255,  160,  107,  237,  160,  334,  271,  335,
 /*   790 */   252,  270,  265,  342,  266,  274,  275,  277,  385,  280,
 /*   800 */   282,  285,  290,  291,  348,  293,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,   24,    1,    2,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,   18,   19,   20,   21,   22,   23,   24,   61,   62,
 /*    50 */    63,   64,   65,   54,   55,    1,    2,    3,    4,    5,
 /*    60 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*    70 */    16,   17,   18,   19,   20,   21,   22,   23,   24,   20,
 /*    80 */    21,   22,   23,   24,   31,   31,   97,   33,  120,  121,
 /*    90 */   101,  102,  103,  104,   26,   72,   28,   74,   45,    1,
 /*   100 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   110 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   120 */    22,   23,   24,    4,    5,    6,    7,    8,    9,   10,
 /*   130 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   140 */    21,   22,   23,   24,   46,   51,    1,    2,    3,    4,
 /*   150 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   160 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   170 */    17,   18,   19,   20,   21,   22,   23,   24,   33,   88,
 /*   180 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   190 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   200 */    21,   22,   23,   24,    1,    2,    3,    4,    5,    6,
 /*   210 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   220 */    17,   18,   19,   20,   21,   22,   23,   24,   10,   11,
 /*   230 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   240 */    22,   23,   24,   22,   23,   24,   71,   72,   69,   74,
 /*   250 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   260 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   270 */    21,   22,   23,   24,   18,   56,   73,   21,  120,  121,
 /*   280 */    24,   25,   89,   27,  102,  103,  104,   31,   14,   15,
 /*   290 */    16,   17,   18,   19,   20,   21,   22,   23,   24,  100,
 /*   300 */    18,   45,    0,   21,  105,   26,   24,   25,    0,   34,
 /*   310 */    35,   36,   37,   31,   39,   40,  117,   61,   62,   63,
 /*   320 */    64,   65,   66,   67,   68,   46,   70,   45,   46,   24,
 /*   330 */    26,   75,   76,   77,   78,   79,    0,   83,   83,   29,
 /*   340 */    30,   87,   87,   61,   62,   63,   64,   65,   66,   67,
 /*   350 */    68,  105,   70,   99,   99,    0,   31,   75,   76,   77,
 /*   360 */    78,   79,   18,  117,   60,   21,   12,   13,   24,   25,
 /*   370 */    45,  117,  117,  120,  121,   31,   26,   23,   27,    0,
 /*   380 */    75,  127,  127,   26,  130,  130,   99,  133,  133,   45,
 /*   390 */    31,   21,   33,   42,   24,   25,   46,   27,   47,   31,
 /*   400 */    49,   31,   57,   46,  117,   61,   62,   63,   64,   65,
 /*   410 */    66,   67,   68,   45,   70,   45,   26,  130,   90,   75,
 /*   420 */    76,   77,   78,   79,   34,   35,   36,   37,   52,   39,
 /*   430 */    40,   61,   62,   63,   64,   65,   66,   67,   68,   91,
 /*   440 */    70,   99,   99,  128,  129,   75,   76,   77,   78,   79,
 /*   450 */    18,   18,   31,   21,   33,   32,   24,   25,   83,  117,
 /*   460 */   117,   26,   87,   31,   31,  122,  123,   59,   45,  127,
 /*   470 */    26,   50,  130,  130,  132,  133,   92,   45,   32,   21,
 /*   480 */    58,   46,   24,   25,   93,   35,   99,   99,   38,   31,
 /*   490 */    46,   45,   47,   61,   62,   63,   64,   65,   66,   67,
 /*   500 */    68,   53,   70,   45,  117,  117,  126,   75,   76,   77,
 /*   510 */    78,   79,  124,  125,  115,  116,  117,  130,  130,   61,
 /*   520 */    62,   63,   64,   65,   66,   67,   68,  126,   70,   35,
 /*   530 */    44,   45,   38,   75,   76,   77,   78,   79,   12,   13,
 /*   540 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   550 */    24,   35,   95,  126,   38,   98,   99,  105,   26,   81,
 /*   560 */    82,   83,   84,   85,   86,   87,   83,   26,   26,  117,
 /*   570 */    87,   94,   99,  109,  117,   99,  112,   24,   46,  116,
 /*   580 */   117,  108,   99,   99,  111,   45,   99,  130,   46,   31,
 /*   590 */   117,  113,  108,  117,   31,  111,   32,  119,   31,  123,
 /*   600 */   117,  117,   99,  130,  117,  100,  130,   96,   98,   99,
 /*   610 */   105,  100,   99,  130,  130,   50,  105,  130,  120,   99,
 /*   620 */   117,   99,  117,   99,  120,   50,   99,  117,  117,  120,
 /*   630 */   117,  111,  120,  130,   31,   99,  133,  117,  125,  117,
 /*   640 */   130,  117,  118,  130,  117,   99,   99,   99,   26,   99,
 /*   650 */   130,    0,  130,  117,  130,   99,   99,  130,  106,   75,
 /*   660 */    41,   99,  107,  117,  117,  117,  130,  117,   46,   26,
 /*   670 */    99,   46,   99,  117,  117,   99,  130,  130,  130,  117,
 /*   680 */   130,   99,   99,   45,   99,   27,  130,  130,  117,   46,
 /*   690 */   117,   99,  130,  117,   46,   45,   31,   31,   46,  117,
 /*   700 */   117,  130,  117,  130,   45,   29,  130,   99,   99,  117,
 /*   710 */    59,   99,  130,  130,   99,  130,   99,   99,   46,   99,
 /*   720 */   129,  131,  130,   99,   46,  117,  117,   31,   99,  117,
 /*   730 */    35,   99,  117,   99,  117,  117,   31,  117,  130,  130,
 /*   740 */    99,  117,  130,   99,   35,  130,  117,  130,  130,  117,
 /*   750 */   130,  117,   99,   31,  130,   99,   35,   31,  117,  130,
 /*   760 */    31,  117,  130,   35,  130,   31,   31,  100,   35,   31,
 /*   770 */   117,  130,  105,  117,  130,   31,   31,   31,   46,   26,
 /*   780 */    53,   45,   45,  130,  117,   46,  130,    0,   31,    0,
 /*   790 */    43,  112,   44,    0,   45,   88,  114,  126,    0,   48,
 /*   800 */    26,    4,   88,  114,    0,   28,
};
#define YY_SHIFT_USE_DFLT (-14)
static short yy_shift_ofst[] = {
 /*     0 */   351,  302,  308,  336,  355,  379,   94,  219,  345,  376,
 /*    10 */   408,  422,  -14,  445,  -14,  -13,  304,  -13,  -14,  -14,
 /*    20 */   -14,  -14,  -14,  -14,  -13,  -14,  448,  458,  541,  458,
 /*    30 */   -14,   -1,  -14,  -14,  458,  458,  221,  458,  221,  458,
 /*    40 */    59,  458,   59,  458,   59,  458,  526,  458,  526,  458,
 /*    50 */   153,  458,  153,  458,  153,  458,  218,  458,  218,  458,
 /*    60 */   218,  458,  218,  458,  218,  458,  218,  458,  274,  354,
 /*    70 */   458,  553,  458,  274,  540,  256,  310,  344,   68,  558,
 /*    80 */   390,  -14,  558,  -14,  421,  563,  565,   53,  -14,  567,
 /*    90 */   350,  -14,  567,  -14,  -14,  -14,  575,  325,  567,  279,
 /*   100 */   -14,  -14,  368,  567,  357,  -14,  -14,  -14,  564,  603,
 /*   110 */   -14,  275,  -14,  -14,  558,  359,  619,  -14,  458,  249,
 /*   120 */   458,  249,  305,  -14,  584,  -14,  458,  119,  458,  119,
 /*   130 */   370,   98,  -14,  625,  -14,  638,  658,  648,  -14,  650,
 /*   140 */   458,  145,  665,  652,  -14,  659,  458,  179,  666,  672,
 /*   150 */   -14,  458,   23,  175,  -14,  -14,  458,  203,  458,  249,
 /*   160 */   -14,  423,  676,  282,  249,  678,  -14,  435,  432,  -14,
 /*   170 */   -14,  458,  553,  458,  553,  -14,  -14,  -14,  -14,  -14,
 /*   180 */   -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  458,  249,
 /*   190 */   -14,  696,  -14,  -14,  695,  705,  709,  722,  450,  721,
 /*   200 */   726,  729,  494,  728,  734,  735,  516,  733,  738,  744,
 /*   210 */   745,  -14,  -14,  344,  -14,  -14,  446,  433,  -14,   54,
 /*   220 */   746,  -14,  -14,  -14,  -14,  -14,  444,  -14,  732,  -14,
 /*   230 */   458,  553,  736,  256,  542,  -14,  739,  -14,  221,  -14,
 /*   240 */   458,  249,  727,  458,  753,  458,  -14,  249,  -14,  458,
 /*   250 */   249,  747,  558,  486,  737,  458,  532,  787,  458,  -14,
 /*   260 */   249,  -14,  757,  622,  748,  749,  458,  643,  789,  757,
 /*   270 */   -14,  -14,  -14,   94,  651,  793,  -13,  798,  558,  751,
 /*   280 */   558,  774,  558,  -14,  797,  458,  -14,  249,  -14,   94,
 /*   290 */   651,  804,  777,  558,  -14,
};
#define YY_REDUCE_USE_DFLT (-33)
static short yy_reduce_ofst[] = {
 /*     0 */   478,  -33,  -33,  -33,  -33,  -33,   91,  193,  328,  348,
 /*    10 */   384,  391,  -33,  -33,  -33,  380,  -33,  401,  -33,  -33,
 /*    20 */   -33,  -33,  -33,  -33,  427,  -33,  -33,  343,  -33,  476,
 /*    30 */   -33,  -33,  -33,  -33,  522,  527,  -33,  536,  -33,  546,
 /*    40 */   -33,  547,  -33,  548,  -33,  550,  -33,  556,  -33,  557,
 /*    50 */   -33,  562,  -33,  571,  -33,  573,  -33,  576,  -33,  582,
 /*    60 */   -33,  583,  -33,  585,  -33,  592,  -33,  608,  -33,  -33,
 /*    70 */   609,  -33,  612,  -33,  -33,  254,  477,  457,  -33,  511,
 /*    80 */   -11,  -33,  199,  -33,  -33,  -33,  -33,  498,  -33,  -32,
 /*    90 */   -33,  -33,  504,  -33,  -33,  -33,  -33,  509,  158,  -33,
 /*   100 */   -33,  -33,  512,  253,  -33,  -33,  -33,  -33,  -33,  -33,
 /*   110 */   -33,  182,  -33,  -33,  246,  552,  555,  -33,  287,  -33,
 /*   120 */   387,  -33,  -33,  -33,  -33,  -33,  487,  -33,  615,  -33,
 /*   130 */   483,  -33,  -33,  -33,  -33,  -33,  375,  -33,  -33,  -33,
 /*   140 */   617,  -33,  -33,  -33,  -33,  -33,  618,  -33,  -33,  -33,
 /*   150 */   -33,  620,  315,  591,  -33,  -33,  624,  -33,  629,  -33,
 /*   160 */   -33,  -33,  590,  342,  -33,  -33,  -33,  -33,  503,  -33,
 /*   170 */   -33,  632,  -33,  634,  -33,  -33,  -33,  -33,  -33,  -33,
 /*   180 */   -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  641,  -33,
 /*   190 */   -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
 /*   200 */   -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
 /*   210 */   -33,  -33,  -33,  510,  -33,  -33,  -33,  -33,  -33,  -33,
 /*   220 */   -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
 /*   230 */   644,  -33,  -33,  255,  -33,  -33,  -33,  -33,  -33,  -33,
 /*   240 */   653,  -33,  -33,  388,  -33,  513,  -33,  -33,  -33,  656,
 /*   250 */   -33,  -33,  452,  -33,  -33,  473,  -33,  -33,  520,  -33,
 /*   260 */   -33,  -33,  464,  -33,  -33,  -33,  484,  -33,  -33,  679,
 /*   270 */   -33,  -33,  -33,  707,  682,  -33,  671,  -33,  505,  -33,
 /*   280 */   399,  -33,  463,  -33,  -33,  524,  -33,  -33,  -33,  714,
 /*   290 */   689,  -33,  -33,  667,  -33,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   457,  457,  457,  457,  457,  457,  364,  373,  378,  366,
 /*    10 */   384,  380,  300,  457,  379,  457,  381,  457,  382,  387,
 /*    20 */   388,  389,  390,  391,  457,  383,  457,  457,  365,  457,
 /*    30 */   367,  369,  370,  371,  457,  457,  392,  457,  394,  457,
 /*    40 */   395,  457,  396,  457,  397,  457,  398,  457,  399,  457,
 /*    50 */   400,  457,  401,  457,  402,  457,  403,  457,  404,  457,
 /*    60 */   405,  457,  406,  457,  407,  457,  408,  457,  409,  457,
 /*    70 */   457,  410,  457,  411,  457,  457,  304,  457,  457,  457,
 /*    80 */   315,  301,  457,  312,  352,  457,  350,  457,  353,  457,
 /*    90 */   457,  354,  457,  359,  361,  360,  351,  457,  457,  457,
 /*   100 */   355,  356,  457,  457,  457,  357,  358,  362,  456,  457,
 /*   110 */   455,  314,  316,  318,  457,  322,  333,  319,  457,  332,
 /*   120 */   457,  419,  457,  437,  457,  438,  457,  439,  457,  440,
 /*   130 */   457,  457,  443,  457,  415,  457,  457,  457,  418,  457,
 /*   140 */   457,  457,  457,  457,  420,  457,  457,  457,  457,  457,
 /*   150 */   421,  457,  457,  457,  422,  423,  457,  457,  457,  425,
 /*   160 */   427,  456,  430,  457,  436,  457,  428,  457,  457,  433,
 /*   170 */   435,  457,  441,  457,  442,  444,  445,  446,  447,  448,
 /*   180 */   449,  450,  451,  452,  453,  454,  434,  429,  457,  426,
 /*   190 */   424,  457,  320,  321,  457,  457,  457,  457,  457,  457,
 /*   200 */   457,  457,  457,  457,  457,  457,  457,  457,  457,  457,
 /*   210 */   457,  317,  313,  457,  305,  307,  456,  457,  308,  311,
 /*   220 */   457,  309,  310,  306,  302,  303,  457,  413,  457,  416,
 /*   230 */   457,  412,  457,  457,  457,  414,  457,  417,  393,  368,
 /*   240 */   457,  377,  457,  457,  372,  457,  374,  376,  375,  457,
 /*   250 */   363,  457,  457,  457,  457,  457,  457,  457,  457,  336,
 /*   260 */   338,  337,  457,  457,  457,  457,  457,  457,  457,  457,
 /*   270 */   339,  341,  340,  364,  457,  457,  457,  457,  457,  457,
 /*   280 */   457,  343,  457,  344,  457,  457,  346,  347,  345,  364,
 /*   290 */   457,  457,  457,  457,  349,
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
  "GREATEREQUAL",  "LESSEQUAL",     "AND",           "OR",
  "LIKE",          "ILIKE",         "BITWISE_AND",   "BITWISE_OR",
  "BITWISE_XOR",   "DIVIDE",        "TIMES",         "MOD",
  "PLUS",          "MINUS",         "IS",            "IN",
  "NOT",           "BITWISE_NOT",   "COMMA",         "SELECT",
  "FROM",          "DISTINCT",      "ALL",           "IDENTIFIER",
  "DOT",           "AS",            "INNER",         "JOIN",
  "CROSS",         "LEFT",          "OUTER",         "RIGHT",
  "FULL",          "ON",            "INSERT",        "INTO",
  "VALUES",        "PARENTHESES_OPEN",  "PARENTHESES_CLOSE",  "UPDATE",
  "SET",           "DELETE",        "WITH",          "WHERE",
  "ORDER",         "BY",            "ASC",           "DESC",
  "GROUP",         "HAVING",        "FOR",           "LIMIT",
  "OFFSET",        "INTEGER",       "HINTEGER",      "NPLACEHOLDER",
  "SPLACEHOLDER",  "BPLACEHOLDER",  "EXISTS",        "CAST",
  "CONVERT",       "USING",         "CASE",          "END",
  "WHEN",          "THEN",          "ELSE",          "NULL",
  "STRING",        "DOUBLE",        "TRUE",          "FALSE",
  "error",         "program",       "query_language",  "select_statement",
  "insert_statement",  "update_statement",  "delete_statement",  "select_clause",
  "where_clause",  "group_clause",  "having_clause",  "order_clause",
  "select_limit_clause",  "for_update_clause",  "distinct_all",  "column_list",
  "associated_name_list",  "join_list_or_null",  "column_item",   "expr",
  "associated_name",  "join_list",     "join_item",     "join_clause",
  "join_type",     "aliased_or_qualified_name",  "join_associated_name",  "join_conditions",
  "values_list",   "field_list",    "value_list",    "value_item",
  "field_item",    "update_clause",  "limit_clause",  "update_item_list",
  "update_item",   "qualified_name",  "new_value",     "delete_clause",
  "with_item",     "with_list",     "order_list",    "order_item",
  "group_list",    "group_item",    "integer_or_placeholder",  "argument_list",
  "when_clauses",  "when_clause",   "function_call",  "distinct_or_null",
  "argument_list_or_null",  "argument_item",
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
 /* 145 */ "expr ::= expr BETWEEN_NOT expr",
 /* 146 */ "expr ::= NOT expr",
 /* 147 */ "expr ::= BITWISE_NOT expr",
 /* 148 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 149 */ "expr ::= qualified_name",
 /* 150 */ "expr ::= INTEGER",
 /* 151 */ "expr ::= HINTEGER",
 /* 152 */ "expr ::= STRING",
 /* 153 */ "expr ::= DOUBLE",
 /* 154 */ "expr ::= NULL",
 /* 155 */ "expr ::= TRUE",
 /* 156 */ "expr ::= FALSE",
 /* 157 */ "expr ::= NPLACEHOLDER",
 /* 158 */ "expr ::= SPLACEHOLDER",
 /* 159 */ "expr ::= BPLACEHOLDER",
 /* 160 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 161 */ "qualified_name ::= IDENTIFIER",
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
#line 101 "parser.php7.lemon"
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
#line 826 "parser.php7.c"
      break;
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 89:
    case 95:
    case 96:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 109:
    case 110:
    case 112:
    case 113:
    case 115:
    case 116:
    case 117:
    case 119:
    case 120:
    case 121:
    case 122:
    case 123:
    case 124:
    case 125:
    case 127:
    case 130:
    case 133:
#line 114 "parser.php7.lemon"
{
	zval_ptr_dtor(&(yypminor->yy202));
}
#line 866 "parser.php7.c"
      break;
    case 88:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 106:
    case 107:
    case 114:
    case 131:
    case 132:
#line 496 "parser.php7.lemon"
{
	zephir_safe_zval_ptr_dtor((yypminor->yy202));
}
#line 883 "parser.php7.c"
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
  { 81, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 83, 7 },
  { 87, 6 },
  { 94, 1 },
  { 94, 1 },
  { 94, 0 },
  { 95, 3 },
  { 95, 1 },
  { 98, 1 },
  { 98, 3 },
  { 98, 3 },
  { 98, 2 },
  { 98, 1 },
  { 96, 3 },
  { 96, 1 },
  { 97, 1 },
  { 97, 0 },
  { 101, 2 },
  { 101, 1 },
  { 102, 1 },
  { 103, 4 },
  { 106, 2 },
  { 106, 1 },
  { 106, 0 },
  { 104, 2 },
  { 104, 2 },
  { 104, 3 },
  { 104, 2 },
  { 104, 3 },
  { 104, 2 },
  { 104, 3 },
  { 104, 2 },
  { 104, 1 },
  { 107, 2 },
  { 107, 0 },
  { 84, 7 },
  { 84, 10 },
  { 108, 3 },
  { 108, 1 },
  { 111, 1 },
  { 109, 3 },
  { 109, 1 },
  { 112, 1 },
  { 85, 3 },
  { 113, 4 },
  { 115, 3 },
  { 115, 1 },
  { 116, 3 },
  { 118, 1 },
  { 86, 3 },
  { 119, 3 },
  { 100, 3 },
  { 100, 2 },
  { 100, 1 },
  { 100, 5 },
  { 100, 7 },
  { 100, 6 },
  { 100, 4 },
  { 100, 5 },
  { 100, 3 },
  { 121, 3 },
  { 121, 1 },
  { 120, 1 },
  { 105, 1 },
  { 88, 2 },
  { 88, 0 },
  { 91, 3 },
  { 91, 0 },
  { 122, 3 },
  { 122, 1 },
  { 123, 1 },
  { 123, 2 },
  { 123, 2 },
  { 89, 3 },
  { 89, 0 },
  { 124, 3 },
  { 124, 1 },
  { 125, 1 },
  { 90, 2 },
  { 90, 0 },
  { 93, 2 },
  { 93, 0 },
  { 92, 2 },
  { 92, 4 },
  { 92, 4 },
  { 92, 0 },
  { 114, 2 },
  { 114, 0 },
  { 126, 1 },
  { 126, 1 },
  { 126, 1 },
  { 126, 1 },
  { 126, 1 },
  { 99, 2 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 4 },
  { 99, 3 },
  { 99, 4 },
  { 99, 5 },
  { 99, 6 },
  { 99, 3 },
  { 99, 5 },
  { 99, 6 },
  { 99, 4 },
  { 99, 3 },
  { 99, 6 },
  { 99, 6 },
  { 99, 4 },
  { 128, 2 },
  { 128, 1 },
  { 129, 4 },
  { 129, 2 },
  { 99, 1 },
  { 130, 5 },
  { 131, 1 },
  { 131, 0 },
  { 132, 1 },
  { 132, 0 },
  { 127, 3 },
  { 127, 1 },
  { 133, 1 },
  { 133, 1 },
  { 99, 3 },
  { 99, 4 },
  { 99, 3 },
  { 99, 3 },
  { 99, 2 },
  { 99, 2 },
  { 99, 3 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 117, 3 },
  { 117, 1 },
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
#line 110 "parser.php7.lemon"
{
	ZVAL_ZVAL(&status->ret, &yymsp[0].minor.yy202, 1, 1);
}
#line 1262 "parser.php7.c"
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
      case 149:
#line 118 "parser.php7.lemon"
{
	yygotominor.yy202 = yymsp[0].minor.yy202;
}
#line 1288 "parser.php7.c"
        break;
      case 5:
#line 138 "parser.php7.lemon"
{
	phql_ret_select_statement(&yygotominor.yy202, &yymsp[-6].minor.yy202, &yymsp[-5].minor.yy202, &yymsp[-2].minor.yy202, &yymsp[-4].minor.yy202, &yymsp[-3].minor.yy202, &yymsp[-1].minor.yy202, &yymsp[0].minor.yy202);
}
#line 1295 "parser.php7.c"
        break;
      case 6:
#line 146 "parser.php7.lemon"
{
	phql_ret_select_clause(&yygotominor.yy202, &yymsp[-4].minor.yy202, &yymsp[-3].minor.yy202, &yymsp[-1].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(27,&yymsp[-5].minor);
  yy_destructor(28,&yymsp[-2].minor);
}
#line 1304 "parser.php7.c"
        break;
      case 7:
#line 154 "parser.php7.lemon"
{
	phql_ret_distinct_all(&yygotominor.yy202, 1);
  yy_destructor(29,&yymsp[0].minor);
}
#line 1312 "parser.php7.c"
        break;
      case 8:
#line 158 "parser.php7.lemon"
{
	phql_ret_distinct_all(&yygotominor.yy202, 0);
  yy_destructor(30,&yymsp[0].minor);
}
#line 1320 "parser.php7.c"
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
#line 162 "parser.php7.lemon"
{
	ZVAL_UNDEF(&yygotominor.yy202);
}
#line 1339 "parser.php7.c"
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
#line 170 "parser.php7.lemon"
{
	phql_ret_zval_list(&yygotominor.yy202, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(26,&yymsp[-1].minor);
}
#line 1355 "parser.php7.c"
        break;
      case 11:
      case 42:
      case 45:
      case 129:
      case 139:
#line 174 "parser.php7.lemon"
{
	phql_ret_zval_list(&yygotominor.yy202, &yymsp[0].minor.yy202, NULL);
}
#line 1366 "parser.php7.c"
        break;
      case 12:
      case 140:
#line 182 "parser.php7.lemon"
{
	phql_ret_column_item(&yygotominor.yy202, PHQL_T_STARALL, NULL, NULL, NULL);
  yy_destructor(18,&yymsp[0].minor);
}
#line 1375 "parser.php7.c"
        break;
      case 13:
#line 186 "parser.php7.lemon"
{
	phql_ret_column_item(&yygotominor.yy202, PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(32,&yymsp[-1].minor);
  yy_destructor(18,&yymsp[0].minor);
}
#line 1384 "parser.php7.c"
        break;
      case 14:
#line 190 "parser.php7.lemon"
{
	phql_ret_column_item(&yygotominor.yy202, PHQL_T_EXPR, &yymsp[-2].minor.yy202, NULL, yymsp[0].minor.yy0);
  yy_destructor(33,&yymsp[-1].minor);
}
#line 1392 "parser.php7.c"
        break;
      case 15:
#line 194 "parser.php7.lemon"
{
	phql_ret_column_item(&yygotominor.yy202, PHQL_T_EXPR, &yymsp[-1].minor.yy202, NULL, yymsp[0].minor.yy0);
}
#line 1399 "parser.php7.c"
        break;
      case 16:
#line 198 "parser.php7.lemon"
{
	phql_ret_column_item(&yygotominor.yy202, PHQL_T_EXPR, &yymsp[0].minor.yy202, NULL, NULL);
}
#line 1406 "parser.php7.c"
        break;
      case 21:
      case 128:
#line 226 "parser.php7.lemon"
{
	phql_ret_zval_list(&yygotominor.yy202, &yymsp[-1].minor.yy202, &yymsp[0].minor.yy202);
}
#line 1414 "parser.php7.c"
        break;
      case 24:
#line 247 "parser.php7.lemon"
{
	phql_ret_join_item(&yygotominor.yy202, &yymsp[-3].minor.yy202, &yymsp[-2].minor.yy202, &yymsp[-1].minor.yy202, &yymsp[0].minor.yy202);
}
#line 1421 "parser.php7.c"
        break;
      case 25:
#line 255 "parser.php7.lemon"
{
	phql_ret_qualified_name(&yygotominor.yy202, NULL, NULL, yymsp[0].minor.yy0);
  yy_destructor(33,&yymsp[-1].minor);
}
#line 1429 "parser.php7.c"
        break;
      case 26:
      case 46:
      case 66:
      case 161:
#line 259 "parser.php7.lemon"
{
	phql_ret_qualified_name(&yygotominor.yy202, NULL, NULL, yymsp[0].minor.yy0);
}
#line 1439 "parser.php7.c"
        break;
      case 28:
#line 271 "parser.php7.lemon"
{
	phql_ret_join_type(&yygotominor.yy202, PHQL_T_INNERJOIN);
  yy_destructor(34,&yymsp[-1].minor);
  yy_destructor(35,&yymsp[0].minor);
}
#line 1448 "parser.php7.c"
        break;
      case 29:
#line 275 "parser.php7.lemon"
{
	phql_ret_join_type(&yygotominor.yy202, PHQL_T_CROSSJOIN);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(35,&yymsp[0].minor);
}
#line 1457 "parser.php7.c"
        break;
      case 30:
#line 279 "parser.php7.lemon"
{
	phql_ret_join_type(&yygotominor.yy202, PHQL_T_LEFTJOIN);
  yy_destructor(37,&yymsp[-2].minor);
  yy_destructor(38,&yymsp[-1].minor);
  yy_destructor(35,&yymsp[0].minor);
}
#line 1467 "parser.php7.c"
        break;
      case 31:
#line 283 "parser.php7.lemon"
{
	phql_ret_join_type(&yygotominor.yy202, PHQL_T_LEFTJOIN);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(35,&yymsp[0].minor);
}
#line 1476 "parser.php7.c"
        break;
      case 32:
#line 287 "parser.php7.lemon"
{
	phql_ret_join_type(&yygotominor.yy202, PHQL_T_RIGHTJOIN);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(38,&yymsp[-1].minor);
  yy_destructor(35,&yymsp[0].minor);
}
#line 1486 "parser.php7.c"
        break;
      case 33:
#line 291 "parser.php7.lemon"
{
	phql_ret_join_type(&yygotominor.yy202, PHQL_T_RIGHTJOIN);
  yy_destructor(39,&yymsp[-1].minor);
  yy_destructor(35,&yymsp[0].minor);
}
#line 1495 "parser.php7.c"
        break;
      case 34:
#line 295 "parser.php7.lemon"
{
	phql_ret_join_type(&yygotominor.yy202, PHQL_T_FULLJOIN);
  yy_destructor(40,&yymsp[-2].minor);
  yy_destructor(38,&yymsp[-1].minor);
  yy_destructor(35,&yymsp[0].minor);
}
#line 1505 "parser.php7.c"
        break;
      case 35:
#line 299 "parser.php7.lemon"
{
	phql_ret_join_type(&yygotominor.yy202, PHQL_T_FULLJOIN);
  yy_destructor(40,&yymsp[-1].minor);
  yy_destructor(35,&yymsp[0].minor);
}
#line 1514 "parser.php7.c"
        break;
      case 36:
#line 303 "parser.php7.lemon"
{
	phql_ret_join_type(&yygotominor.yy202, PHQL_T_INNERJOIN);
  yy_destructor(35,&yymsp[0].minor);
}
#line 1522 "parser.php7.c"
        break;
      case 37:
#line 311 "parser.php7.lemon"
{
	yygotominor.yy202 = yymsp[0].minor.yy202;
  yy_destructor(41,&yymsp[-1].minor);
}
#line 1530 "parser.php7.c"
        break;
      case 39:
#line 324 "parser.php7.lemon"
{
	phql_ret_insert_statement(&yygotominor.yy202, &yymsp[-4].minor.yy202, NULL, &yymsp[-1].minor.yy202);
  yy_destructor(42,&yymsp[-6].minor);
  yy_destructor(43,&yymsp[-5].minor);
  yy_destructor(44,&yymsp[-3].minor);
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(46,&yymsp[0].minor);
}
#line 1542 "parser.php7.c"
        break;
      case 40:
#line 328 "parser.php7.lemon"
{
	phql_ret_insert_statement(&yygotominor.yy202, &yymsp[-7].minor.yy202, &yymsp[-5].minor.yy202, &yymsp[-1].minor.yy202);
  yy_destructor(42,&yymsp[-9].minor);
  yy_destructor(43,&yymsp[-8].minor);
  yy_destructor(45,&yymsp[-6].minor);
  yy_destructor(46,&yymsp[-4].minor);
  yy_destructor(44,&yymsp[-3].minor);
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(46,&yymsp[0].minor);
}
#line 1556 "parser.php7.c"
        break;
      case 47:
#line 374 "parser.php7.lemon"
{
	phql_ret_update_statement(&yygotominor.yy202, &yymsp[-2].minor.yy202, &yymsp[-1].minor.yy202, &yymsp[0].minor.yy202);
}
#line 1563 "parser.php7.c"
        break;
      case 48:
#line 382 "parser.php7.lemon"
{
	phql_ret_update_clause(&yygotominor.yy202, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(47,&yymsp[-3].minor);
  yy_destructor(48,&yymsp[-1].minor);
}
#line 1572 "parser.php7.c"
        break;
      case 51:
#line 402 "parser.php7.lemon"
{
	phql_ret_update_item(&yygotominor.yy202, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(4,&yymsp[-1].minor);
}
#line 1580 "parser.php7.c"
        break;
      case 53:
#line 416 "parser.php7.lemon"
{
	phql_ret_delete_statement(&yygotominor.yy202, &yymsp[-2].minor.yy202, &yymsp[-1].minor.yy202, &yymsp[0].minor.yy202);
}
#line 1587 "parser.php7.c"
        break;
      case 54:
#line 424 "parser.php7.lemon"
{
	phql_ret_delete_clause(&yygotominor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(49,&yymsp[-2].minor);
  yy_destructor(28,&yymsp[-1].minor);
}
#line 1596 "parser.php7.c"
        break;
      case 55:
#line 432 "parser.php7.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy202, &yymsp[-2].minor.yy202, yymsp[0].minor.yy0, NULL);
  yy_destructor(33,&yymsp[-1].minor);
}
#line 1604 "parser.php7.c"
        break;
      case 56:
#line 436 "parser.php7.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy202, &yymsp[-1].minor.yy202, yymsp[0].minor.yy0, NULL);
}
#line 1611 "parser.php7.c"
        break;
      case 57:
#line 440 "parser.php7.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy202, &yymsp[0].minor.yy202, NULL, NULL);
}
#line 1618 "parser.php7.c"
        break;
      case 58:
#line 444 "parser.php7.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy202, &yymsp[-4].minor.yy202, yymsp[-2].minor.yy0, &yymsp[0].minor.yy202);
  yy_destructor(33,&yymsp[-3].minor);
  yy_destructor(50,&yymsp[-1].minor);
}
#line 1627 "parser.php7.c"
        break;
      case 59:
#line 448 "parser.php7.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy202, &yymsp[-6].minor.yy202, yymsp[-4].minor.yy0, &yymsp[-1].minor.yy202);
  yy_destructor(33,&yymsp[-5].minor);
  yy_destructor(50,&yymsp[-3].minor);
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(46,&yymsp[0].minor);
}
#line 1638 "parser.php7.c"
        break;
      case 60:
#line 452 "parser.php7.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy202, &yymsp[-5].minor.yy202, yymsp[-4].minor.yy0, &yymsp[-1].minor.yy202);
  yy_destructor(50,&yymsp[-3].minor);
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(46,&yymsp[0].minor);
}
#line 1648 "parser.php7.c"
        break;
      case 61:
#line 456 "parser.php7.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy202, &yymsp[-3].minor.yy202, yymsp[-2].minor.yy0, &yymsp[0].minor.yy202);
  yy_destructor(50,&yymsp[-1].minor);
}
#line 1656 "parser.php7.c"
        break;
      case 62:
#line 460 "parser.php7.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy202, &yymsp[-4].minor.yy202, NULL, &yymsp[-1].minor.yy202);
  yy_destructor(50,&yymsp[-3].minor);
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(46,&yymsp[0].minor);
}
#line 1666 "parser.php7.c"
        break;
      case 63:
#line 464 "parser.php7.lemon"
{
	phql_ret_assoc_name(&yygotominor.yy202, &yymsp[-2].minor.yy202, NULL, &yymsp[0].minor.yy202);
  yy_destructor(50,&yymsp[-1].minor);
}
#line 1674 "parser.php7.c"
        break;
      case 68:
#line 500 "parser.php7.lemon"
{
	yygotominor.yy202 = yymsp[0].minor.yy202;
  yy_destructor(51,&yymsp[-1].minor);
}
#line 1682 "parser.php7.c"
        break;
      case 70:
#line 512 "parser.php7.lemon"
{
	yygotominor.yy202 = yymsp[0].minor.yy202;
  yy_destructor(52,&yymsp[-2].minor);
  yy_destructor(53,&yymsp[-1].minor);
}
#line 1691 "parser.php7.c"
        break;
      case 74:
#line 536 "parser.php7.lemon"
{
	phql_ret_order_item(&yygotominor.yy202, &yymsp[0].minor.yy202, 0);
}
#line 1698 "parser.php7.c"
        break;
      case 75:
#line 540 "parser.php7.lemon"
{
	phql_ret_order_item(&yygotominor.yy202, &yymsp[-1].minor.yy202, PHQL_T_ASC);
  yy_destructor(54,&yymsp[0].minor);
}
#line 1706 "parser.php7.c"
        break;
      case 76:
#line 544 "parser.php7.lemon"
{
	phql_ret_order_item(&yygotominor.yy202, &yymsp[-1].minor.yy202, PHQL_T_DESC);
  yy_destructor(55,&yymsp[0].minor);
}
#line 1714 "parser.php7.c"
        break;
      case 77:
#line 552 "parser.php7.lemon"
{
	yygotominor.yy202 = yymsp[0].minor.yy202;
  yy_destructor(56,&yymsp[-2].minor);
  yy_destructor(53,&yymsp[-1].minor);
}
#line 1723 "parser.php7.c"
        break;
      case 82:
#line 584 "parser.php7.lemon"
{
	yygotominor.yy202 = yymsp[0].minor.yy202;
  yy_destructor(57,&yymsp[-1].minor);
}
#line 1731 "parser.php7.c"
        break;
      case 84:
#line 596 "parser.php7.lemon"
{
	phql_ret_for_update_clause(&yygotominor.yy202);
  yy_destructor(58,&yymsp[-1].minor);
  yy_destructor(47,&yymsp[0].minor);
}
#line 1740 "parser.php7.c"
        break;
      case 86:
      case 90:
#line 608 "parser.php7.lemon"
{
	phql_ret_limit_clause(&yygotominor.yy202, &yymsp[0].minor.yy202, NULL);
  yy_destructor(59,&yymsp[-1].minor);
}
#line 1749 "parser.php7.c"
        break;
      case 87:
#line 612 "parser.php7.lemon"
{
	phql_ret_limit_clause(&yygotominor.yy202, &yymsp[0].minor.yy202, &yymsp[-2].minor.yy202);
  yy_destructor(59,&yymsp[-3].minor);
  yy_destructor(26,&yymsp[-1].minor);
}
#line 1758 "parser.php7.c"
        break;
      case 88:
#line 616 "parser.php7.lemon"
{
	phql_ret_limit_clause(&yygotominor.yy202, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(59,&yymsp[-3].minor);
  yy_destructor(60,&yymsp[-1].minor);
}
#line 1767 "parser.php7.c"
        break;
      case 92:
      case 150:
#line 636 "parser.php7.lemon"
{
	phql_ret_literal_zval(&yygotominor.yy202, PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
#line 1775 "parser.php7.c"
        break;
      case 93:
      case 151:
#line 640 "parser.php7.lemon"
{
	phql_ret_literal_zval(&yygotominor.yy202, PHQL_T_HINTEGER, yymsp[0].minor.yy0);
}
#line 1783 "parser.php7.c"
        break;
      case 94:
      case 157:
#line 644 "parser.php7.lemon"
{
	phql_ret_placeholder_zval(&yygotominor.yy202, PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 1791 "parser.php7.c"
        break;
      case 95:
      case 158:
#line 648 "parser.php7.lemon"
{
	phql_ret_placeholder_zval(&yygotominor.yy202, PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 1799 "parser.php7.c"
        break;
      case 96:
      case 159:
#line 652 "parser.php7.lemon"
{
	phql_ret_placeholder_zval(&yygotominor.yy202, PHQL_T_BPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 1807 "parser.php7.c"
        break;
      case 97:
#line 660 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_MINUS, NULL, &yymsp[0].minor.yy202);
  yy_destructor(21,&yymsp[-1].minor);
}
#line 1815 "parser.php7.c"
        break;
      case 98:
#line 664 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_SUB, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(21,&yymsp[-1].minor);
}
#line 1823 "parser.php7.c"
        break;
      case 99:
#line 668 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_ADD, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(20,&yymsp[-1].minor);
}
#line 1831 "parser.php7.c"
        break;
      case 100:
#line 672 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_MUL, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(18,&yymsp[-1].minor);
}
#line 1839 "parser.php7.c"
        break;
      case 101:
#line 676 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_DIV, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(17,&yymsp[-1].minor);
}
#line 1847 "parser.php7.c"
        break;
      case 102:
#line 680 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_MOD, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(19,&yymsp[-1].minor);
}
#line 1855 "parser.php7.c"
        break;
      case 103:
#line 684 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_AND, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(10,&yymsp[-1].minor);
}
#line 1863 "parser.php7.c"
        break;
      case 104:
#line 688 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_OR, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(11,&yymsp[-1].minor);
}
#line 1871 "parser.php7.c"
        break;
      case 105:
#line 692 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_BITWISE_AND, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(14,&yymsp[-1].minor);
}
#line 1879 "parser.php7.c"
        break;
      case 106:
#line 696 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_BITWISE_OR, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(15,&yymsp[-1].minor);
}
#line 1887 "parser.php7.c"
        break;
      case 107:
#line 700 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_BITWISE_XOR, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(16,&yymsp[-1].minor);
}
#line 1895 "parser.php7.c"
        break;
      case 108:
#line 704 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_EQUALS, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(4,&yymsp[-1].minor);
}
#line 1903 "parser.php7.c"
        break;
      case 109:
#line 708 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_NOTEQUALS, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(5,&yymsp[-1].minor);
}
#line 1911 "parser.php7.c"
        break;
      case 110:
#line 712 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_LESS, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(6,&yymsp[-1].minor);
}
#line 1919 "parser.php7.c"
        break;
      case 111:
#line 716 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_GREATER, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(7,&yymsp[-1].minor);
}
#line 1927 "parser.php7.c"
        break;
      case 112:
#line 720 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_GREATEREQUAL, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(8,&yymsp[-1].minor);
}
#line 1935 "parser.php7.c"
        break;
      case 113:
#line 724 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_LESSEQUAL, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(9,&yymsp[-1].minor);
}
#line 1943 "parser.php7.c"
        break;
      case 114:
#line 728 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_LIKE, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(12,&yymsp[-1].minor);
}
#line 1951 "parser.php7.c"
        break;
      case 115:
#line 732 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_NLIKE, &yymsp[-3].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(12,&yymsp[-1].minor);
}
#line 1960 "parser.php7.c"
        break;
      case 116:
#line 736 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_ILIKE, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(13,&yymsp[-1].minor);
}
#line 1968 "parser.php7.c"
        break;
      case 117:
#line 740 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_NILIKE, &yymsp[-3].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(13,&yymsp[-1].minor);
}
#line 1977 "parser.php7.c"
        break;
      case 118:
      case 121:
#line 744 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_IN, &yymsp[-4].minor.yy202, &yymsp[-1].minor.yy202);
  yy_destructor(23,&yymsp[-3].minor);
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(46,&yymsp[0].minor);
}
#line 1988 "parser.php7.c"
        break;
      case 119:
      case 122:
#line 748 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_NOTIN, &yymsp[-5].minor.yy202, &yymsp[-1].minor.yy202);
  yy_destructor(24,&yymsp[-4].minor);
  yy_destructor(23,&yymsp[-3].minor);
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(46,&yymsp[0].minor);
}
#line 2000 "parser.php7.c"
        break;
      case 120:
#line 752 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_SUBQUERY, &yymsp[-1].minor.yy202, NULL);
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(46,&yymsp[0].minor);
}
#line 2009 "parser.php7.c"
        break;
      case 123:
#line 764 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_EXISTS, NULL, &yymsp[-1].minor.yy202);
  yy_destructor(66,&yymsp[-3].minor);
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(46,&yymsp[0].minor);
}
#line 2019 "parser.php7.c"
        break;
      case 124:
#line 768 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_AGAINST, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(1,&yymsp[-1].minor);
}
#line 2027 "parser.php7.c"
        break;
      case 125:
#line 772 "parser.php7.lemon"
{
	{
		zval qualified;
		phql_ret_raw_qualified_name(&qualified, yymsp[-1].minor.yy0, NULL);
		phql_ret_expr(&yygotominor.yy202, PHQL_T_CAST, &yymsp[-3].minor.yy202, &qualified);
	}
  yy_destructor(67,&yymsp[-5].minor);
  yy_destructor(45,&yymsp[-4].minor);
  yy_destructor(33,&yymsp[-2].minor);
  yy_destructor(46,&yymsp[0].minor);
}
#line 2042 "parser.php7.c"
        break;
      case 126:
#line 780 "parser.php7.lemon"
{
	{
		zval qualified;
		phql_ret_raw_qualified_name(&qualified, yymsp[-1].minor.yy0, NULL);
		phql_ret_expr(&yygotominor.yy202, PHQL_T_CONVERT, &yymsp[-3].minor.yy202, &qualified);
	}
  yy_destructor(68,&yymsp[-5].minor);
  yy_destructor(45,&yymsp[-4].minor);
  yy_destructor(69,&yymsp[-2].minor);
  yy_destructor(46,&yymsp[0].minor);
}
#line 2057 "parser.php7.c"
        break;
      case 127:
#line 788 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_CASE, &yymsp[-2].minor.yy202, &yymsp[-1].minor.yy202);
  yy_destructor(70,&yymsp[-3].minor);
  yy_destructor(71,&yymsp[0].minor);
}
#line 2066 "parser.php7.c"
        break;
      case 130:
#line 800 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_WHEN, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(72,&yymsp[-3].minor);
  yy_destructor(73,&yymsp[-1].minor);
}
#line 2075 "parser.php7.c"
        break;
      case 131:
#line 804 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_ELSE, &yymsp[0].minor.yy202, NULL);
  yy_destructor(74,&yymsp[-1].minor);
}
#line 2083 "parser.php7.c"
        break;
      case 133:
#line 816 "parser.php7.lemon"
{
	phql_ret_func_call(&yygotominor.yy202, yymsp[-4].minor.yy0, &yymsp[-1].minor.yy202, &yymsp[-2].minor.yy202);
  yy_destructor(45,&yymsp[-3].minor);
  yy_destructor(46,&yymsp[0].minor);
}
#line 2092 "parser.php7.c"
        break;
      case 134:
#line 824 "parser.php7.lemon"
{
	phql_ret_distinct(&yygotominor.yy202);
  yy_destructor(29,&yymsp[0].minor);
}
#line 2100 "parser.php7.c"
        break;
      case 142:
#line 868 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_ISNULL, &yymsp[-2].minor.yy202, NULL);
  yy_destructor(22,&yymsp[-1].minor);
  yy_destructor(75,&yymsp[0].minor);
}
#line 2109 "parser.php7.c"
        break;
      case 143:
#line 872 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_ISNOTNULL, &yymsp[-3].minor.yy202, NULL);
  yy_destructor(22,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
  yy_destructor(75,&yymsp[0].minor);
}
#line 2119 "parser.php7.c"
        break;
      case 144:
#line 876 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_BETWEEN, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(2,&yymsp[-1].minor);
}
#line 2127 "parser.php7.c"
        break;
      case 145:
#line 880 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_BETWEEN_NOT, &yymsp[-2].minor.yy202, &yymsp[0].minor.yy202);
  yy_destructor(3,&yymsp[-1].minor);
}
#line 2135 "parser.php7.c"
        break;
      case 146:
#line 884 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_NOT, NULL, &yymsp[0].minor.yy202);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 2143 "parser.php7.c"
        break;
      case 147:
#line 888 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_BITWISE_NOT, NULL, &yymsp[0].minor.yy202);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 2151 "parser.php7.c"
        break;
      case 148:
#line 892 "parser.php7.lemon"
{
	phql_ret_expr(&yygotominor.yy202, PHQL_T_ENCLOSED, &yymsp[-1].minor.yy202, NULL);
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(46,&yymsp[0].minor);
}
#line 2160 "parser.php7.c"
        break;
      case 152:
#line 908 "parser.php7.lemon"
{
	phql_ret_literal_zval(&yygotominor.yy202, PHQL_T_STRING, yymsp[0].minor.yy0);
}
#line 2167 "parser.php7.c"
        break;
      case 153:
#line 912 "parser.php7.lemon"
{
	phql_ret_literal_zval(&yygotominor.yy202, PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
#line 2174 "parser.php7.c"
        break;
      case 154:
#line 916 "parser.php7.lemon"
{
	phql_ret_literal_zval(&yygotominor.yy202, PHQL_T_NULL, NULL);
  yy_destructor(75,&yymsp[0].minor);
}
#line 2182 "parser.php7.c"
        break;
      case 155:
#line 920 "parser.php7.lemon"
{
	phql_ret_literal_zval(&yygotominor.yy202, PHQL_T_TRUE, NULL);
  yy_destructor(78,&yymsp[0].minor);
}
#line 2190 "parser.php7.c"
        break;
      case 156:
#line 924 "parser.php7.lemon"
{
	phql_ret_literal_zval(&yygotominor.yy202, PHQL_T_FALSE, NULL);
  yy_destructor(79,&yymsp[0].minor);
}
#line 2198 "parser.php7.c"
        break;
      case 160:
#line 947 "parser.php7.lemon"
{
	phql_ret_qualified_name(&yygotominor.yy202, NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(32,&yymsp[-1].minor);
}
#line 2206 "parser.php7.c"
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
#line 34 "parser.php7.lemon"

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

#line 2315 "parser.php7.c"
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
