#include "php_phalcon.h"
#if PHP_VERSION_ID < 70000
/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 39 "parser.php5.lemon"

#include "parser.php5.inc.h"

// 12 "parser.php5.c"
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
**    PPCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    PPNOCODE           is a number of type PPCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    PPFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    PPACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    phql_TOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    PPMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is phql_TOKENTYPE.  The entry in the union
**                       for base tokens is called "pp0".
**    PPSTACKDEPTH       is the maximum depth of the parser's stack.
**    phql_ARG_SDECL     A static variable declaration for the %extra_argument
**    phql_ARG_PDECL     A parameter declaration for the %extra_argument
**    phql_ARG_STORE     Code to store %extra_argument into pppParser
**    phql_ARG_FETCH     Code to extract %extra_argument from pppParser
**    PPNSTATE           the combined number of states.
**    PPNRULE            the number of rules in the grammar
**    PPERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define PPCODETYPE unsigned char
#define PPNOCODE 134
#define PPACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE pp0;
  zval* pp162;
  int pp267;
} PPMINORTYPE;
#define PPSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = pppParser->status
#define phql_ARG_STORE pppParser->status = status
#define PPNSTATE 293
#define PPNRULE 161
#define PPERRORSYMBOL 79
#define PPERRSYMDT pp267
#define PP_NO_ACTION      (PPNSTATE+PPNRULE+2)
#define PP_ACCEPT_ACTION  (PPNSTATE+PPNRULE+1)
#define PP_ERROR_ACTION   (PPNSTATE+PPNRULE)

/* Next are that tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < PPNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   PPNSTATE <= N < PPNSTATE+PPNRULE   Reduce by rule N-PPNSTATE.
**
**   N == PPNSTATE+PPNRULE              A syntax error has occurred.
**
**   N == PPNSTATE+PPNRULE+1            The parser accepts its input.
**
**   N == PPNSTATE+PPNRULE+2            No such action.  Denotes unused
**                                      slots in the pp_action[] table.
**
** The action table is constructed as a single large table named pp_action[].
** Given state S and lookahead X, the action is computed as
**
**      pp_action[ pp_shift_ofst[S] + X ]
**
** If the index value pp_shift_ofst[S]+X is out of range or if the value
** pp_lookahead[pp_shift_ofst[S]+X] is not equal to X or if pp_shift_ofst[S]
** is equal to PP_SHIFT_USE_DFLT, it means that the action is not in the table
** and that pp_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the pp_reduce_ofst[] array is used in place of
** the pp_shift_ofst[] array and PP_REDUCE_USE_DFLT is used in place of
** PP_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  pp_action[]        A single table containing all actions.
**  pp_lookahead[]     A table containing the lookahead for each entry in
**                     pp_action.  Used to detect hash collisions.
**  pp_shift_ofst[]    For each state, the offset into pp_action for
**                     shifting terminals.
**  pp_reduce_ofst[]   For each state, the offset into pp_action for
**                     shifting non-terminals after a reduce.
**  pp_default[]       Default action for each state.
*/
static PPACTIONTYPE pp_action[] = {
 /*     0 */   120,  126,   55,   57,   59,   61,   63,   65,   45,   47,
 /*    10 */    67,   72,   49,   51,   53,   41,   39,   43,   37,   34,
 /*    20 */   122,   74,   69,  120,  126,   55,   57,   59,   61,   63,
 /*    30 */    65,   45,   47,   67,   72,   49,   51,   53,   41,   39,
 /*    40 */    43,   37,   34,  122,   74,   69,   37,   34,  122,   74,
 /*    50 */    69,  166,  220,   92,  218,   45,   47,   67,   72,   49,
 /*    60 */    51,   53,   41,   39,   43,   37,   34,  122,   74,   69,
 /*    70 */   154,  429,  186,   91,  120,  126,   55,   57,   59,   61,
 /*    80 */    63,   65,   45,   47,   67,   72,   49,   51,   53,   41,
 /*    90 */    39,   43,   37,   34,  122,   74,   69,  120,  126,   55,
 /*   100 */    57,   59,   61,   63,   65,   45,   47,   67,   72,   49,
 /*   110 */    51,   53,   41,   39,   43,   37,   34,  122,   74,   69,
 /*   120 */    19,   20,   21,   22,   23,  227,   32,   33,   67,   72,
 /*   130 */    49,   51,   53,   41,   39,   43,   37,   34,  122,   74,
 /*   140 */    69,  130,  238,  120,  126,   55,   57,   59,   61,   63,
 /*   150 */    65,   45,   47,   67,   72,   49,   51,   53,   41,   39,
 /*   160 */    43,   37,   34,  122,   74,   69,   41,   39,   43,   37,
 /*   170 */    34,  122,   74,   69,  140,    8,  120,  126,   55,   57,
 /*   180 */    59,   61,   63,   65,   45,   47,   67,   72,   49,   51,
 /*   190 */    53,   41,   39,   43,   37,   34,  122,   74,   69,  120,
 /*   200 */   126,   55,   57,   59,   61,   63,   65,   45,   47,   67,
 /*   210 */    72,   49,   51,   53,   41,   39,   43,   37,   34,  122,
 /*   220 */    74,   69,  120,  126,   55,   57,   59,   61,   63,   65,
 /*   230 */    45,   47,   67,   72,   49,   51,   53,   41,   39,   43,
 /*   240 */    37,   34,  122,   74,   69,  168,  109,  156,   35,   95,
 /*   250 */    99,  169,  171,   26,   76,  151,  188,   81,  159,  160,
 /*   260 */    82,  111,  209,  113,  114,   17,  146,  285,  192,  208,
 /*   270 */   194,  196,  128,  200,  204,  222,  223,  455,    1,    2,
 /*   280 */     3,    4,    5,    6,  199,  173,  284,  197,  174,  175,
 /*   290 */   181,  182,  183,  133,  137,  143,   76,  149,  158,   24,
 /*   300 */   212,  217,  178,  176,  177,  179,  180,  168,  135,  271,
 /*   310 */    35,  249,    6,  169,  171,  287,  276,  110,  290,  173,
 /*   320 */   159,   49,   51,   53,   41,   39,   43,   37,   34,  122,
 /*   330 */    74,   69,  158,  384,  128,  430,  192,  208,  194,  196,
 /*   340 */    80,  200,  204,  292,  210,  122,   74,   69,   84,   84,
 /*   350 */   174,  175,  181,  182,  183,  133,  137,  143,  125,  149,
 /*   360 */   107,  107,   95,   90,  178,  176,  177,  179,  180,   55,
 /*   370 */    57,   59,   61,   63,   65,   45,   47,   67,   72,   49,
 /*   380 */    51,   53,   41,   39,   43,   37,   34,  122,   74,   69,
 /*   390 */   213,  274,  258,   35,   70,  228,  169,  171,  131,  109,
 /*   400 */   245,  265,    6,  214,  259,  230,  279,  286,  282,  234,
 /*   410 */   173,   83,  203,    6,  129,  201,   84,  128,  173,  152,
 /*   420 */   154,  207,  186,  158,  205,  162,  244,   96,  107,   85,
 /*   430 */   219,  158,  173,  174,  175,  181,  182,  183,  133,  137,
 /*   440 */   143,   94,  149,  173,    7,  158,  102,  178,  176,  177,
 /*   450 */   179,  180,  162,  232,   35,   89,  158,  169,  171,  184,
 /*   460 */    76,  112,  113,  114,  159,  211,  215,   79,   94,   78,
 /*   470 */   173,  226,  221,  217,   94,    6,  277,  240,  128,  160,
 /*   480 */   165,   84,   98,  158,  250,  163,  184,  162,  103,   95,
 /*   490 */   104,  173,   94,  107,  174,  175,  181,  182,  183,  133,
 /*   500 */   137,  143,   92,  149,  158,  173,  108,  155,  178,  176,
 /*   510 */   177,  179,  180,  168,   92,  224,   35,  258,  158,  169,
 /*   520 */   171,  184,  100,   27,  258,  173,  159,  166,  216,  257,
 /*   530 */   191,  115,  189,  254,  105,  173,  259,  124,  158,   69,
 /*   540 */   128,  110,  173,  107,  166,  281,  282,  225,  158,  252,
 /*   550 */   260,   31,  253,   10,  251,  158,  174,  175,  181,  182,
 /*   560 */   183,  133,  137,  143,  233,  149,  107,  106,   42,  173,
 /*   570 */   178,  176,  177,  179,  180,   30,  247,   35,  329,  245,
 /*   580 */   169,  171,  158,  147,   31,  229,  173,  159,  123,  328,
 /*   590 */   261,  332,  256,  270,  101,  327,  162,  173,  326,  158,
 /*   600 */   325,  128,  173,  173,  242,  246,  206,   28,  237,   18,
 /*   610 */   158,   50,  255,  202,  173,  158,  158,  174,  175,  181,
 /*   620 */   182,  183,  133,  137,  143,  121,  149,  158,  239,  173,
 /*   630 */   167,  178,  176,  177,  179,  180,   97,  269,  164,  119,
 /*   640 */   148,  263,  158,  173,  324,  264,  173,   71,   15,  132,
 /*   650 */   150,  267,  323,  161,  145,  256,  158,  173,   73,  158,
 /*   660 */   134,  170,  172,  198,   62,  173,  322,  333,  173,   60,
 /*   670 */   158,  262,  173,   66,   93,  266,  173,  195,  158,  173,
 /*   680 */   173,  158,  173,  187,  139,  158,  136,  173,  268,  158,
 /*   690 */    11,  173,  158,  158,   76,  158,  295,  185,   58,  340,
 /*   700 */   158,  173,  173,   56,  158,  272,  236,   36,  321,   54,
 /*   710 */    38,  383,  293,  157,  158,  158,  173,  127,   40,  273,
 /*   720 */   193,  173,  275,  278,  173,  173,  280,  173,  173,  158,
 /*   730 */   190,  173,   68,   52,  158,  173,  173,  158,  158,  138,
 /*   740 */   158,  158,   48,  283,  158,   13,   25,   88,  158,  158,
 /*   750 */   173,  173,   16,  248,   87,   86,   44,   46,   64,  297,
 /*   760 */   173,  294,  141,  158,  158,  296,  142,  288,  153,  289,
 /*   770 */   346,  173,  291,  158,  173,  173,  173,   12,   29,   75,
 /*   780 */    77,  144,    9,  235,  158,  117,  241,  158,  158,  158,
 /*   790 */   118,  231,  243,  296,  116,   14,
};
static PPCODETYPE pp_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,    1,    2,    3,    4,    5,    6,    7,
 /*    30 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    40 */    18,   19,   20,   21,   22,   23,   19,   20,   21,   22,
 /*    50 */    23,   25,   30,   25,   32,    9,   10,   11,   12,   13,
 /*    60 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*    70 */    71,   45,   73,   45,    1,    2,    3,    4,    5,    6,
 /*    80 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    90 */    17,   18,   19,   20,   21,   22,   23,    1,    2,    3,
 /*   100 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   110 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   120 */    60,   61,   62,   63,   64,   45,   53,   54,   11,   12,
 /*   130 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   140 */    23,   45,   56,    1,    2,    3,    4,    5,    6,    7,
 /*   150 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   160 */    18,   19,   20,   21,   22,   23,   16,   17,   18,   19,
 /*   170 */    20,   21,   22,   23,   32,   88,    1,    2,    3,    4,
 /*   180 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   190 */    15,   16,   17,   18,   19,   20,   21,   22,   23,    1,
 /*   200 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   210 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   220 */    22,   23,    1,    2,    3,    4,    5,    6,    7,    8,
 /*   230 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   240 */    19,   20,   21,   22,   23,   17,   31,   72,   20,  119,
 /*   250 */   120,   23,   24,   51,   26,  127,  128,   96,   30,   44,
 /*   260 */    25,  100,  101,  102,  103,   25,   68,   98,   33,   34,
 /*   270 */    35,   36,   44,   38,   39,   28,   29,   80,   81,   82,
 /*   280 */    83,   84,   85,   86,   34,  116,  117,   37,   60,   61,
 /*   290 */    62,   63,   64,   65,   66,   67,   26,   69,  129,   59,
 /*   300 */    97,   98,   74,   75,   76,   77,   78,   17,   82,  112,
 /*   310 */    20,   41,   86,   23,   24,  118,   46,   30,   48,  116,
 /*   320 */    30,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   330 */    22,   23,  129,    0,   44,   45,   33,   34,   35,   36,
 /*   340 */    95,   38,   39,   99,   99,   21,   22,   23,  104,  104,
 /*   350 */    60,   61,   62,   63,   64,   65,   66,   67,   74,   69,
 /*   360 */   116,  116,  119,  120,   74,   75,   76,   77,   78,    3,
 /*   370 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   380 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   390 */    17,   58,   98,   20,   11,   12,   23,   24,   82,   31,
 /*   400 */    98,  107,   86,   30,  110,   22,  114,  115,  116,   82,
 /*   410 */   116,   99,   34,   86,   98,   37,  104,   44,  116,   70,
 /*   420 */    71,   34,   73,  129,   37,   98,  124,   30,  116,   32,
 /*   430 */    30,  129,  116,   60,   61,   62,   63,   64,   65,   66,
 /*   440 */    67,   30,   69,  116,   87,  129,   49,   74,   75,   76,
 /*   450 */    77,   78,   98,  126,   20,   44,  129,   23,   24,  132,
 /*   460 */    26,  101,  102,  103,   30,   25,   31,   27,   30,   94,
 /*   470 */   116,   82,   97,   98,   30,   86,   99,   55,   44,   44,
 /*   480 */   126,  104,   44,  129,   42,  131,  132,   98,   44,  119,
 /*   490 */   120,  116,   30,  116,   60,   61,   62,   63,   64,   65,
 /*   500 */    66,   67,   25,   69,  129,  116,   30,   98,   74,   75,
 /*   510 */    76,   77,   78,   17,   25,  126,   20,   98,  129,   23,
 /*   520 */    24,  132,   45,   52,   98,  116,   30,   25,   17,  110,
 /*   530 */    30,  104,   32,  107,   45,  116,  110,   23,  129,   23,
 /*   540 */    44,   30,  116,  116,   25,  115,  116,   45,  129,   43,
 /*   550 */    44,   98,   44,   90,  104,  129,   60,   61,   62,   63,
 /*   560 */    64,   65,   66,   67,   45,   69,  116,  119,   98,  116,
 /*   570 */    74,   75,   76,   77,   78,  122,   50,   20,   30,   98,
 /*   580 */    23,   24,  129,   30,   98,   98,  116,   30,   74,   30,
 /*   590 */   108,    0,   25,  111,  119,   30,   98,  116,   30,  129,
 /*   600 */    30,   44,  116,  116,  123,  124,   34,  121,  122,  125,
 /*   610 */   129,   98,   45,   34,  116,  129,  129,   60,   61,   62,
 /*   620 */    63,   64,   65,   66,   67,   98,   69,  129,   98,  116,
 /*   630 */   132,   74,   75,   76,   77,   78,   49,   30,   45,   98,
 /*   640 */    45,   43,  129,  116,   30,   44,  116,   98,   58,   45,
 /*   650 */    98,   25,   30,  130,   98,   25,  129,  116,   98,  129,
 /*   660 */    44,   98,   98,   34,   98,  116,   30,    0,  116,   98,
 /*   670 */   129,   45,  116,   98,  119,   45,  116,   34,  129,  116,
 /*   680 */   116,  129,  116,   98,   98,  129,   45,  116,  111,  129,
 /*   690 */    91,  116,  129,  129,   26,  129,    0,   28,   98,    0,
 /*   700 */   129,  116,  116,   98,  129,   87,   98,   98,   30,   98,
 /*   710 */    98,    0,    0,   98,  129,  129,  116,   98,   98,  113,
 /*   720 */    34,  116,  125,   47,  116,  116,   25,  116,  116,  129,
 /*   730 */    30,  116,   98,   98,  129,  116,  116,  129,  129,   44,
 /*   740 */   129,  129,   98,    3,  129,   57,  125,  119,  129,  129,
 /*   750 */   116,  116,  125,   98,   49,   30,   98,   98,   98,    0,
 /*   760 */   116,    0,   30,  129,  129,    0,   45,   87,  128,  113,
 /*   770 */     0,  116,   27,  129,  116,  116,  116,   92,   25,   44,
 /*   780 */    93,   44,   89,   45,  129,  106,   52,  129,  129,  129,
 /*   790 */    40,   44,   25,  133,  105,   46,
};
#define PP_SHIFT_USE_DFLT (-2)
static short pp_shift_ofst[] = {
 /*     0 */   270,  712,  761,  696,  765,  759,  526,  422,   86,  202,
 /*    10 */   590,  688,   -2,  749,   -2,   60,  240,   60,   -2,   -2,
 /*    20 */    -2,   -2,   -2,   -2,   60,   -2,  471,  557,  753,  557,
 /*    30 */    -2,   73,   -2,   -2,  557,  557,  324,  557,  324,  557,
 /*    40 */    27,  557,   27,  557,   27,  557,  117,  557,  117,  557,
 /*    50 */   150,  557,  150,  557,  150,  557,   46,  557,   46,  557,
 /*    60 */    46,  557,   46,  557,   46,  557,   46,  557,  308,  383,
 /*    70 */   557,  516,  557,  308,  735,  228,  247,  373,  440,  476,
 /*    80 */   235,   -2,  476,   -2,  397,  725,  705,  411,   -2,  462,
 /*    90 */    28,   -2,  462,   -2,   -2,   -2,  587,  438,  462,  477,
 /*   100 */    -2,   -2,  444,  462,  489,   -2,   -2,   -2,  368,  287,
 /*   110 */    -2,  303,   -2,   -2,  476,  500,  750,   -2,  557,  221,
 /*   120 */   557,  221,  514,   -2,  284,   -2,  557,  366,  434,   96,
 /*   130 */    -2,  604,   -2,  616,  668,  641,   -2,  695,  557,  142,
 /*   140 */   732,  721,   -2,  737,  557,  198,  553,  595,   -2,  557,
 /*   150 */    -1,  349,   -2,   -2,  557,  175,  557,  221,   -2,  215,
 /*   160 */   669,  290,  221,  593,   -2,   26,  496,   -2,   -2,  557,
 /*   170 */   516,  557,  516,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   180 */    -2,   -2,   -2,   -2,   -2,   -2,  557,  221,   -2,  700,
 /*   190 */    -2,   -2,  686,  678,  643,  636,  250,  629,  622,  614,
 /*   200 */   378,  579,  570,  568,  387,  572,  565,  559,  548,   -2,
 /*   210 */    -2,  373,   -2,   -2,  435,  511,   -2,   22,  400,   -2,
 /*   220 */    -2,   -2,   -2,   -2,  502,   -2,   80,   -2,  557,  516,
 /*   230 */   747,  228,  519,   -2,  738,   -2,  324,   -2,  557,  221,
 /*   240 */   734,  557,  767,  557,   -2,  221,   -2,  557,  221,  442,
 /*   250 */   476,  506,  508,  557,  567,  591,  557,   -2,  221,   -2,
 /*   260 */   607,  626,  598,  601,  557,  630,  667,  607,   -2,   -2,
 /*   270 */    -2,  526,  333,  699,   60,  711,  476,  676,  476,  701,
 /*   280 */   476,   -2,  740,  557,   -2,  221,   -2,  526,  333,  770,
 /*   290 */   745,  476,   -2,
};
#define PP_REDUCE_USE_DFLT (-1)
static short pp_reduce_ofst[] = {
 /*     0 */   197,   -1,   -1,   -1,   -1,   -1,  357,   87,  693,  463,
 /*    10 */   599,  685,   -1,   -1,   -1,  627,   -1,  484,   -1,   -1,
 /*    20 */    -1,   -1,   -1,   -1,  621,   -1,   -1,  486,   -1,  453,
 /*    30 */    -1,   -1,   -1,   -1,  608,  609,   -1,  612,   -1,  620,
 /*    40 */    -1,  470,   -1,  658,   -1,  659,   -1,  644,   -1,  513,
 /*    50 */    -1,  635,   -1,  611,   -1,  605,   -1,  600,   -1,  571,
 /*    60 */    -1,  566,   -1,  660,   -1,  575,   -1,  634,   -1,   -1,
 /*    70 */   549,   -1,  560,   -1,   -1,  389,  687,  375,   -1,  245,
 /*    80 */   161,   -1,  312,   -1,   -1,   -1,   -1,  628,   -1,  243,
 /*    90 */    -1,   -1,  555,   -1,   -1,   -1,   -1,  475,  130,   -1,
 /*   100 */    -1,   -1,  448,  370,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   110 */    -1,  360,   -1,   -1,  427,  689,  679,   -1,  541,   -1,
 /*   120 */   527,   -1,   -1,   -1,   -1,   -1,  619,   -1,  316,   -1,
 /*   130 */    -1,   -1,   -1,   -1,  226,   -1,   -1,   -1,  586,   -1,
 /*   140 */    -1,   -1,   -1,   -1,  556,   -1,   -1,   -1,   -1,  552,
 /*   150 */   128,  640,   -1,   -1,  409,   -1,  615,   -1,   -1,   -1,
 /*   160 */   523,  354,   -1,   -1,   -1,   -1,  498,   -1,   -1,  563,
 /*   170 */    -1,  564,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   180 */    -1,   -1,   -1,   -1,   -1,   -1,  585,   -1,   -1,   -1,
 /*   190 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   200 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   210 */    -1,  203,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   220 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  487,   -1,
 /*   230 */    -1,  327,   -1,   -1,   -1,   -1,   -1,   -1,  530,   -1,
 /*   240 */    -1,  481,   -1,  302,   -1,   -1,   -1,  655,   -1,   -1,
 /*   250 */   450,   -1,   -1,  426,   -1,   -1,  419,   -1,   -1,   -1,
 /*   260 */   482,   -1,   -1,   -1,  294,   -1,   -1,  577,   -1,   -1,
 /*   270 */    -1,  618,  606,   -1,  597,   -1,  377,   -1,  292,   -1,
 /*   280 */   430,   -1,   -1,  169,   -1,   -1,   -1,  680,  656,   -1,
 /*   290 */    -1,  244,   -1,
};
static PPACTIONTYPE pp_default[] = {
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
#define PP_SZ_ACTTAB (sizeof(pp_action)/sizeof(pp_action[0]))

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
#ifdef PPFALLBACK
static const PPCODETYPE ppFallback[] = {
};
#endif /* PPFALLBACK */

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
struct ppStackEntry {
  int stateno;       /* The state-number */
  int major;         /* The major token value.  This is the code
                     ** number for the token at this stack level */
  PPMINORTYPE minor; /* The user-supplied minor token value.  This
                     ** is the value of the token  */
};
typedef struct ppStackEntry ppStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct ppParser {
  int ppidx;                    /* Index of top element in stack */
  int pperrcnt;                 /* Shifts left before out of the error */
  phql_ARG_SDECL                /* A place to hold %extra_argument */
  ppStackEntry ppstack[PPSTACKDEPTH];  /* The parser's stack */
};
typedef struct ppParser ppParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *ppTraceFILE = 0;
static char *ppTracePrompt = 0;
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
  ppTraceFILE = TraceFILE;
  ppTracePrompt = zTracePrompt;
  if( ppTraceFILE==0 ) ppTracePrompt = 0;
  else if( ppTracePrompt==0 ) ppTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *ppTokenName[] = { 
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
static const char *ppRuleName[] = {
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
  if( tokenType>0 && tokenType<(sizeof(ppTokenName)/sizeof(ppTokenName[0])) ){
    return ppTokenName[tokenType];
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
  ppParser *pParser;
  pParser = (ppParser*)(*mallocProc)( (size_t)sizeof(ppParser) );
  if( pParser ){
    pParser->ppidx = -1;
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "ppmajor" is the symbol code, and "pppminor" is a pointer to
** the value.
*/
static void pp_destructor(PPCODETYPE ppmajor, PPMINORTYPE *pppminor){
  switch( ppmajor ){
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
// 110 "parser.php5.lemon"
{
	if ((pppminor->pp0)) {
		if ((pppminor->pp0)->free_flag) {
			efree((pppminor->pp0)->token);
		}
		efree((pppminor->pp0));
	}
}
// 822 "parser.php5.c"
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
// 123 "parser.php5.lemon"
{
    zval_ptr_dtor(&(pppminor->pp162));
}
// 857 "parser.php5.c"
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
// 505 "parser.php5.lemon"
{
    zephir_safe_zval_ptr_dtor((pppminor->pp162));
}
// 874 "parser.php5.c"
      break;
    case 116:
    case 124:
    case 126:
    case 129:
    case 132:
// 940 "parser.php5.lemon"
{
	zval_ptr_dtor(&(pppminor->pp162));
}
// 885 "parser.php5.c"
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
static int pp_pop_parser_stack(ppParser *pParser){
  PPCODETYPE ppmajor;
  ppStackEntry *pptos = &pParser->ppstack[pParser->ppidx];

  if( pParser->ppidx<0 ) return 0;
#ifndef NDEBUG
  if( ppTraceFILE && pParser->ppidx>=0 ){
    fprintf(ppTraceFILE,"%sPopping %s\n",
      ppTracePrompt,
      ppTokenName[pptos->major]);
  }
#endif
  ppmajor = pptos->major;
  pp_destructor( ppmajor, &pptos->minor);
  pParser->ppidx--;
  return ppmajor;
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
  ppParser *pParser = (ppParser*)p;
  if( pParser==0 ) return;
  while( pParser->ppidx>=0 ) pp_pop_parser_stack(pParser);
  (*freeProc)((void*)pParser);
}

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is PPNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return PP_NO_ACTION.
*/
static int pp_find_shift_action(
  ppParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->ppstack[pParser->ppidx].stateno;
 
  /* if( pParser->ppidx<0 ) return PP_NO_ACTION;  */
  i = pp_shift_ofst[stateno];
  if( i==PP_SHIFT_USE_DFLT ){
    return pp_default[stateno];
  }
  if( iLookAhead==PPNOCODE ){
    return PP_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=PP_SZ_ACTTAB || pp_lookahead[i]!=iLookAhead ){
#ifdef PPFALLBACK
    int iFallback;            /* Fallback token */
    if( iLookAhead<sizeof(ppFallback)/sizeof(ppFallback[0])
           && (iFallback = ppFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
      if( ppTraceFILE ){
        fprintf(ppTraceFILE, "%sFALLBACK %s => %s\n",
           ppTracePrompt, ppTokenName[iLookAhead], ppTokenName[iFallback]);
      }
#endif
      return pp_find_shift_action(pParser, iFallback);
    }
#endif
    return pp_default[stateno];
  }else{
    return pp_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is PPNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return PP_NO_ACTION.
*/
static int pp_find_reduce_action(
  ppParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->ppstack[pParser->ppidx].stateno;
 
  i = pp_reduce_ofst[stateno];
  if( i==PP_REDUCE_USE_DFLT ){
    return pp_default[stateno];
  }
  if( iLookAhead==PPNOCODE ){
    return PP_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=PP_SZ_ACTTAB || pp_lookahead[i]!=iLookAhead ){
    return pp_default[stateno];
  }else{
    return pp_action[i];
  }
}

/*
** Perform a shift action.
*/
static void pp_shift(
  ppParser *pppParser,          /* The parser to be shifted */
  int ppNewState,               /* The new state to shift in */
  int ppMajor,                  /* The major token to shift in */
  PPMINORTYPE *pppMinor         /* Pointer ot the minor token to shift in */
){
  ppStackEntry *pptos;
  pppParser->ppidx++;
  if( pppParser->ppidx>=PPSTACKDEPTH ){
     phql_ARG_FETCH;
     pppParser->ppidx--;
#ifndef NDEBUG
     if( ppTraceFILE ){
       fprintf(ppTraceFILE,"%sStack Overflow!\n",ppTracePrompt);
     }
#endif
     while( pppParser->ppidx>=0 ) pp_pop_parser_stack(pppParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     phql_ARG_STORE; /* Suppress warning about unused %extra_argument var */
     return;
  }
  pptos = &pppParser->ppstack[pppParser->ppidx];
  pptos->stateno = ppNewState;
  pptos->major = ppMajor;
  pptos->minor = *pppMinor;
#ifndef NDEBUG
  if( ppTraceFILE && pppParser->ppidx>0 ){
    int i;
    fprintf(ppTraceFILE,"%sShift %d\n",ppTracePrompt,ppNewState);
    fprintf(ppTraceFILE,"%sStack:",ppTracePrompt);
    for(i=1; i<=pppParser->ppidx; i++)
      fprintf(ppTraceFILE," %s",ppTokenName[pppParser->ppstack[i].major]);
    fprintf(ppTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static struct {
  PPCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} ppRuleInfo[] = {
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

static void pp_accept(ppParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void pp_reduce(
  ppParser *pppParser,         /* The parser */
  int ppruleno                 /* Number of the rule by which to reduce */
){
  int ppgoto;                     /* The next state */
  int ppact;                      /* The next action */
  PPMINORTYPE ppgotominor;        /* The LHS of the rule reduced */
  ppStackEntry *ppmsp;            /* The top of the parser's stack */
  int ppsize;                     /* Amount to pop the stack */
  phql_ARG_FETCH;
  ppmsp = &pppParser->ppstack[pppParser->ppidx];
#ifndef NDEBUG
  if( ppTraceFILE && ppruleno>=0 
        && ppruleno<sizeof(ppRuleName)/sizeof(ppRuleName[0]) ){
    fprintf(ppTraceFILE, "%sReduce [%s].\n", ppTracePrompt,
      ppRuleName[ppruleno]);
  }
#endif /* NDEBUG */

  switch( ppruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  // <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  // <lineno> <thisfile>
  **     break;
  */
      case 0:
// 119 "parser.php5.lemon"
{
	status->ret = ppmsp[0].minor.pp162;
}
// 1263 "parser.php5.c"
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
// 127 "parser.php5.lemon"
{
	ppgotominor.pp162 = ppmsp[0].minor.pp162;
}
// 1289 "parser.php5.c"
        break;
      case 5:
// 147 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_select_statement(ppmsp[-6].minor.pp162, ppmsp[-5].minor.pp162, ppmsp[-2].minor.pp162, ppmsp[-4].minor.pp162, ppmsp[-3].minor.pp162, ppmsp[-1].minor.pp162, ppmsp[0].minor.pp162);
}
// 1296 "parser.php5.c"
        break;
      case 6:
// 155 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_select_clause(ppmsp[-4].minor.pp162, ppmsp[-3].minor.pp162, ppmsp[-1].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(26,&ppmsp[-5].minor);
  pp_destructor(27,&ppmsp[-2].minor);
}
// 1305 "parser.php5.c"
        break;
      case 7:
// 163 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_distinct_all(1);
  pp_destructor(28,&ppmsp[0].minor);
}
// 1313 "parser.php5.c"
        break;
      case 8:
// 167 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_distinct_all(0);
  pp_destructor(29,&ppmsp[0].minor);
}
// 1321 "parser.php5.c"
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
// 171 "parser.php5.lemon"
{
	ppgotominor.pp162 = NULL;
}
// 1340 "parser.php5.c"
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
// 179 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_zval_list(ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 1356 "parser.php5.c"
        break;
      case 11:
      case 42:
      case 45:
      case 129:
      case 139:
// 183 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_zval_list(ppmsp[0].minor.pp162, NULL);
}
// 1367 "parser.php5.c"
        break;
      case 12:
      case 140:
// 191 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1376 "parser.php5.c"
        break;
      case 13:
// 195 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, ppmsp[-2].minor.pp0, NULL);
  pp_destructor(31,&ppmsp[-1].minor);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1385 "parser.php5.c"
        break;
      case 14:
// 199 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-2].minor.pp162, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1393 "parser.php5.c"
        break;
      case 15:
// 203 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-1].minor.pp162, NULL, ppmsp[0].minor.pp0);
}
// 1400 "parser.php5.c"
        break;
      case 16:
// 207 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[0].minor.pp162, NULL, NULL);
}
// 1407 "parser.php5.c"
        break;
      case 21:
      case 128:
// 235 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_zval_list(ppmsp[-1].minor.pp162, ppmsp[0].minor.pp162);
}
// 1415 "parser.php5.c"
        break;
      case 24:
// 256 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_join_item(ppmsp[-3].minor.pp162, ppmsp[-2].minor.pp162, ppmsp[-1].minor.pp162, ppmsp[0].minor.pp162);
}
// 1422 "parser.php5.c"
        break;
      case 25:
// 264 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1430 "parser.php5.c"
        break;
      case 26:
      case 46:
      case 66:
      case 160:
// 268 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
}
// 1440 "parser.php5.c"
        break;
      case 28:
// 280 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(33,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1449 "parser.php5.c"
        break;
      case 29:
// 284 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  pp_destructor(35,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1458 "parser.php5.c"
        break;
      case 30:
// 288 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1468 "parser.php5.c"
        break;
      case 31:
// 292 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1477 "parser.php5.c"
        break;
      case 32:
// 296 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1487 "parser.php5.c"
        break;
      case 33:
// 300 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1496 "parser.php5.c"
        break;
      case 34:
// 304 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1506 "parser.php5.c"
        break;
      case 35:
// 308 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1515 "parser.php5.c"
        break;
      case 36:
// 312 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1523 "parser.php5.c"
        break;
      case 37:
// 320 "parser.php5.lemon"
{
	ppgotominor.pp162 = ppmsp[0].minor.pp162;
  pp_destructor(40,&ppmsp[-1].minor);
}
// 1531 "parser.php5.c"
        break;
      case 39:
// 333 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_insert_statement(ppmsp[-4].minor.pp162, NULL, ppmsp[-1].minor.pp162);
  pp_destructor(41,&ppmsp[-6].minor);
  pp_destructor(42,&ppmsp[-5].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1543 "parser.php5.c"
        break;
      case 40:
// 337 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_insert_statement(ppmsp[-7].minor.pp162, ppmsp[-5].minor.pp162, ppmsp[-1].minor.pp162);
  pp_destructor(41,&ppmsp[-9].minor);
  pp_destructor(42,&ppmsp[-8].minor);
  pp_destructor(44,&ppmsp[-6].minor);
  pp_destructor(45,&ppmsp[-4].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1557 "parser.php5.c"
        break;
      case 47:
// 383 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_update_statement(ppmsp[-2].minor.pp162, ppmsp[-1].minor.pp162, ppmsp[0].minor.pp162);
}
// 1564 "parser.php5.c"
        break;
      case 48:
// 391 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_update_clause(ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(46,&ppmsp[-3].minor);
  pp_destructor(47,&ppmsp[-1].minor);
}
// 1573 "parser.php5.c"
        break;
      case 51:
// 411 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_update_item(ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 1581 "parser.php5.c"
        break;
      case 53:
// 425 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_delete_statement(ppmsp[-2].minor.pp162, ppmsp[-1].minor.pp162, ppmsp[0].minor.pp162);
}
// 1588 "parser.php5.c"
        break;
      case 54:
// 433 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_delete_clause(ppmsp[0].minor.pp162);
  pp_destructor(48,&ppmsp[-2].minor);
  pp_destructor(27,&ppmsp[-1].minor);
}
// 1597 "parser.php5.c"
        break;
      case 55:
// 441 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_assoc_name(ppmsp[-2].minor.pp162, ppmsp[0].minor.pp0, NULL);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1605 "parser.php5.c"
        break;
      case 56:
// 445 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_assoc_name(ppmsp[-1].minor.pp162, ppmsp[0].minor.pp0, NULL);
}
// 1612 "parser.php5.c"
        break;
      case 57:
// 449 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_assoc_name(ppmsp[0].minor.pp162, NULL, NULL);
}
// 1619 "parser.php5.c"
        break;
      case 58:
// 453 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_assoc_name(ppmsp[-4].minor.pp162, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp162);
  pp_destructor(32,&ppmsp[-3].minor);
  pp_destructor(49,&ppmsp[-1].minor);
}
// 1628 "parser.php5.c"
        break;
      case 59:
// 457 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_assoc_name(ppmsp[-6].minor.pp162, ppmsp[-4].minor.pp0, ppmsp[-1].minor.pp162);
  pp_destructor(32,&ppmsp[-5].minor);
  pp_destructor(49,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1639 "parser.php5.c"
        break;
      case 60:
// 461 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_assoc_name(ppmsp[-5].minor.pp162, ppmsp[-4].minor.pp0, ppmsp[-1].minor.pp162);
  pp_destructor(49,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1649 "parser.php5.c"
        break;
      case 61:
// 465 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_assoc_name(ppmsp[-3].minor.pp162, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp162);
  pp_destructor(49,&ppmsp[-1].minor);
}
// 1657 "parser.php5.c"
        break;
      case 62:
// 469 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_assoc_name(ppmsp[-4].minor.pp162, NULL, ppmsp[-1].minor.pp162);
  pp_destructor(49,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1667 "parser.php5.c"
        break;
      case 63:
// 473 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_assoc_name(ppmsp[-2].minor.pp162, NULL, ppmsp[0].minor.pp162);
  pp_destructor(49,&ppmsp[-1].minor);
}
// 1675 "parser.php5.c"
        break;
      case 68:
// 509 "parser.php5.lemon"
{
	ppgotominor.pp162 = ppmsp[0].minor.pp162;
  pp_destructor(50,&ppmsp[-1].minor);
}
// 1683 "parser.php5.c"
        break;
      case 70:
// 521 "parser.php5.lemon"
{
	ppgotominor.pp162 = ppmsp[0].minor.pp162;
  pp_destructor(51,&ppmsp[-2].minor);
  pp_destructor(52,&ppmsp[-1].minor);
}
// 1692 "parser.php5.c"
        break;
      case 74:
// 545 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_order_item(ppmsp[0].minor.pp162, 0);
}
// 1699 "parser.php5.c"
        break;
      case 75:
// 549 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_order_item(ppmsp[-1].minor.pp162, PHQL_T_ASC);
  pp_destructor(53,&ppmsp[0].minor);
}
// 1707 "parser.php5.c"
        break;
      case 76:
// 553 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_order_item(ppmsp[-1].minor.pp162, PHQL_T_DESC);
  pp_destructor(54,&ppmsp[0].minor);
}
// 1715 "parser.php5.c"
        break;
      case 77:
// 561 "parser.php5.lemon"
{
	ppgotominor.pp162 = ppmsp[0].minor.pp162;
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(52,&ppmsp[-1].minor);
}
// 1724 "parser.php5.c"
        break;
      case 82:
// 593 "parser.php5.lemon"
{
	ppgotominor.pp162 = ppmsp[0].minor.pp162;
  pp_destructor(56,&ppmsp[-1].minor);
}
// 1732 "parser.php5.c"
        break;
      case 84:
// 605 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_for_update_clause();
  pp_destructor(57,&ppmsp[-1].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1741 "parser.php5.c"
        break;
      case 86:
      case 90:
// 617 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_limit_clause(ppmsp[0].minor.pp162, NULL);
  pp_destructor(58,&ppmsp[-1].minor);
}
// 1750 "parser.php5.c"
        break;
      case 87:
// 621 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_limit_clause(ppmsp[0].minor.pp162, ppmsp[-2].minor.pp162);
  pp_destructor(58,&ppmsp[-3].minor);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 1759 "parser.php5.c"
        break;
      case 88:
// 625 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_limit_clause(ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(58,&ppmsp[-3].minor);
  pp_destructor(59,&ppmsp[-1].minor);
}
// 1768 "parser.php5.c"
        break;
      case 92:
      case 149:
// 645 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_literal_zval(PHQL_T_INTEGER, ppmsp[0].minor.pp0);
}
// 1776 "parser.php5.c"
        break;
      case 93:
      case 150:
// 649 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_literal_zval(PHQL_T_HINTEGER, ppmsp[0].minor.pp0);
}
// 1784 "parser.php5.c"
        break;
      case 94:
      case 156:
// 653 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1792 "parser.php5.c"
        break;
      case 95:
      case 157:
// 657 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1800 "parser.php5.c"
        break;
      case 96:
      case 158:
// 661 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_placeholder_zval(PHQL_T_BPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1808 "parser.php5.c"
        break;
      case 97:
// 669 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_MINUS, NULL, ppmsp[0].minor.pp162);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 1816 "parser.php5.c"
        break;
      case 98:
// 673 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_SUB, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 1824 "parser.php5.c"
        break;
      case 99:
// 677 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_ADD, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(19,&ppmsp[-1].minor);
}
// 1832 "parser.php5.c"
        break;
      case 100:
// 681 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_MUL, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 1840 "parser.php5.c"
        break;
      case 101:
// 685 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_DIV, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 1848 "parser.php5.c"
        break;
      case 102:
// 689 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_MOD, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(18,&ppmsp[-1].minor);
}
// 1856 "parser.php5.c"
        break;
      case 103:
// 693 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_AND, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(9,&ppmsp[-1].minor);
}
// 1864 "parser.php5.c"
        break;
      case 104:
// 697 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_OR, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(10,&ppmsp[-1].minor);
}
// 1872 "parser.php5.c"
        break;
      case 105:
// 701 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_BITWISE_AND, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 1880 "parser.php5.c"
        break;
      case 106:
// 705 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_BITWISE_OR, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(14,&ppmsp[-1].minor);
}
// 1888 "parser.php5.c"
        break;
      case 107:
// 709 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_BITWISE_XOR, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(15,&ppmsp[-1].minor);
}
// 1896 "parser.php5.c"
        break;
      case 108:
// 713 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_EQUALS, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 1904 "parser.php5.c"
        break;
      case 109:
// 717 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_NOTEQUALS, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 1912 "parser.php5.c"
        break;
      case 110:
// 721 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_LESS, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(5,&ppmsp[-1].minor);
}
// 1920 "parser.php5.c"
        break;
      case 111:
// 725 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_GREATER, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(6,&ppmsp[-1].minor);
}
// 1928 "parser.php5.c"
        break;
      case 112:
// 729 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_GREATEREQUAL, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(7,&ppmsp[-1].minor);
}
// 1936 "parser.php5.c"
        break;
      case 113:
// 733 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_LESSEQUAL, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(8,&ppmsp[-1].minor);
}
// 1944 "parser.php5.c"
        break;
      case 114:
// 737 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_LIKE, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 1952 "parser.php5.c"
        break;
      case 115:
// 741 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_NLIKE, ppmsp[-3].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 1961 "parser.php5.c"
        break;
      case 116:
// 745 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_ILIKE, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 1969 "parser.php5.c"
        break;
      case 117:
// 749 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_NILIKE, ppmsp[-3].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 1978 "parser.php5.c"
        break;
      case 118:
      case 121:
// 753 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_IN, ppmsp[-4].minor.pp162, ppmsp[-1].minor.pp162);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1989 "parser.php5.c"
        break;
      case 119:
      case 122:
// 757 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_NOTIN, ppmsp[-5].minor.pp162, ppmsp[-1].minor.pp162);
  pp_destructor(23,&ppmsp[-4].minor);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2001 "parser.php5.c"
        break;
      case 120:
// 761 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_SUBQUERY, ppmsp[-1].minor.pp162, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2010 "parser.php5.c"
        break;
      case 123:
// 773 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_EXISTS, NULL, ppmsp[-1].minor.pp162);
  pp_destructor(65,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2020 "parser.php5.c"
        break;
      case 124:
// 777 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_AGAINST, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(1,&ppmsp[-1].minor);
}
// 2028 "parser.php5.c"
        break;
      case 125:
// 781 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_CAST, ppmsp[-3].minor.pp162, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(66,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(32,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2039 "parser.php5.c"
        break;
      case 126:
// 785 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_CONVERT, ppmsp[-3].minor.pp162, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(67,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(68,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2050 "parser.php5.c"
        break;
      case 127:
// 789 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_CASE, ppmsp[-2].minor.pp162, ppmsp[-1].minor.pp162);
  pp_destructor(69,&ppmsp[-3].minor);
  pp_destructor(70,&ppmsp[0].minor);
}
// 2059 "parser.php5.c"
        break;
      case 130:
// 801 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_WHEN, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(71,&ppmsp[-3].minor);
  pp_destructor(72,&ppmsp[-1].minor);
}
// 2068 "parser.php5.c"
        break;
      case 131:
// 805 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_ELSE, ppmsp[0].minor.pp162, NULL);
  pp_destructor(73,&ppmsp[-1].minor);
}
// 2076 "parser.php5.c"
        break;
      case 133:
// 817 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_func_call(ppmsp[-4].minor.pp0, ppmsp[-1].minor.pp162, ppmsp[-2].minor.pp162);
  pp_destructor(44,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2085 "parser.php5.c"
        break;
      case 134:
// 825 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_distinct();
  pp_destructor(28,&ppmsp[0].minor);
}
// 2093 "parser.php5.c"
        break;
      case 142:
// 869 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_ISNULL, ppmsp[-2].minor.pp162, NULL);
  pp_destructor(21,&ppmsp[-1].minor);
  pp_destructor(74,&ppmsp[0].minor);
}
// 2102 "parser.php5.c"
        break;
      case 143:
// 873 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_ISNOTNULL, ppmsp[-3].minor.pp162, NULL);
  pp_destructor(21,&ppmsp[-2].minor);
  pp_destructor(23,&ppmsp[-1].minor);
  pp_destructor(74,&ppmsp[0].minor);
}
// 2112 "parser.php5.c"
        break;
      case 144:
// 877 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_BETWEEN, ppmsp[-2].minor.pp162, ppmsp[0].minor.pp162);
  pp_destructor(2,&ppmsp[-1].minor);
}
// 2120 "parser.php5.c"
        break;
      case 145:
// 881 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_NOT, NULL, ppmsp[0].minor.pp162);
  pp_destructor(23,&ppmsp[-1].minor);
}
// 2128 "parser.php5.c"
        break;
      case 146:
// 885 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, ppmsp[0].minor.pp162);
  pp_destructor(24,&ppmsp[-1].minor);
}
// 2136 "parser.php5.c"
        break;
      case 147:
// 889 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_expr(PHQL_T_ENCLOSED, ppmsp[-1].minor.pp162, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2145 "parser.php5.c"
        break;
      case 151:
// 905 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_literal_zval(PHQL_T_STRING, ppmsp[0].minor.pp0);
}
// 2152 "parser.php5.c"
        break;
      case 152:
// 909 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_literal_zval(PHQL_T_DOUBLE, ppmsp[0].minor.pp0);
}
// 2159 "parser.php5.c"
        break;
      case 153:
// 913 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  pp_destructor(74,&ppmsp[0].minor);
}
// 2167 "parser.php5.c"
        break;
      case 154:
// 917 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  pp_destructor(77,&ppmsp[0].minor);
}
// 2175 "parser.php5.c"
        break;
      case 155:
// 921 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  pp_destructor(78,&ppmsp[0].minor);
}
// 2183 "parser.php5.c"
        break;
      case 159:
// 944 "parser.php5.lemon"
{
	ppgotominor.pp162 = phql_ret_qualified_name(NULL, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(31,&ppmsp[-1].minor);
}
// 2191 "parser.php5.c"
        break;
  };
  ppgoto = ppRuleInfo[ppruleno].lhs;
  ppsize = ppRuleInfo[ppruleno].nrhs;
  pppParser->ppidx -= ppsize;
  ppact = pp_find_reduce_action(pppParser,ppgoto);
  if( ppact < PPNSTATE ){
    pp_shift(pppParser,ppact,ppgoto,&ppgotominor);
  }else if( ppact == PPNSTATE + PPNRULE + 1 ){
    pp_accept(pppParser);
  }
}

/*
** The following code executes when the parse fails
*/
static void pp_parse_failed(
  ppParser *pppParser           /* The parser */
){
  phql_ARG_FETCH;
#ifndef NDEBUG
  if( ppTraceFILE ){
    fprintf(ppTraceFILE,"%sFail!\n",ppTracePrompt);
  }
#endif
  while( pppParser->ppidx>=0 ) pp_pop_parser_stack(pppParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void pp_syntax_error(
  ppParser *pppParser,           /* The parser */
  int ppmajor,                   /* The major type of the error token */
  PPMINORTYPE ppminor            /* The minor type of the error token */
){
  phql_ARG_FETCH;
#define PPTOKEN (ppminor.pp0)
// 43 "parser.php5.lemon"

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

// 2300 "parser.php5.c"
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void pp_accept(
  ppParser *pppParser           /* The parser */
){
  phql_ARG_FETCH;
#ifndef NDEBUG
  if( ppTraceFILE ){
    fprintf(ppTraceFILE,"%sAccept!\n",ppTracePrompt);
  }
#endif
  while( pppParser->ppidx>=0 ) pp_pop_parser_stack(pppParser);
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
  void *ppp,                   /* The parser */
  int ppmajor,                 /* The major token code number */
  phql_TOKENTYPE ppminor       /* The value for the token */
  phql_ARG_PDECL               /* Optional %extra_argument parameter */
){
  PPMINORTYPE ppminorunion;
  int ppact;            /* The parser action. */
  int ppendofinput;     /* True if we are at the end of input */
  int pperrorhit = 0;   /* True if ppmajor has invoked an error */
  ppParser *pppParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  pppParser = (ppParser*)ppp;
  if( pppParser->ppidx<0 ){
    if( ppmajor==0 ) return;
    pppParser->ppidx = 0;
    pppParser->pperrcnt = -1;
    pppParser->ppstack[0].stateno = 0;
    pppParser->ppstack[0].major = 0;
  }
  ppminorunion.pp0 = ppminor;
  ppendofinput = (ppmajor==0);
  phql_ARG_STORE;

#ifndef NDEBUG
  if( ppTraceFILE ){
    fprintf(ppTraceFILE,"%sInput %s\n",ppTracePrompt,ppTokenName[ppmajor]);
  }
#endif

  do{
    ppact = pp_find_shift_action(pppParser,ppmajor);
    if( ppact<PPNSTATE ){
      pp_shift(pppParser,ppact,ppmajor,&ppminorunion);
      pppParser->pperrcnt--;
      if( ppendofinput && pppParser->ppidx>=0 ){
        ppmajor = 0;
      }else{
        ppmajor = PPNOCODE;
      }
    }else if( ppact < PPNSTATE + PPNRULE ){
      pp_reduce(pppParser,ppact-PPNSTATE);
    }else if( ppact == PP_ERROR_ACTION ){
      int ppmx;
#ifndef NDEBUG
      if( ppTraceFILE ){
        fprintf(ppTraceFILE,"%sSyntax Error!\n",ppTracePrompt);
      }
#endif
#ifdef PPERRORSYMBOL
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
      if( pppParser->pperrcnt<0 ){
        pp_syntax_error(pppParser,ppmajor,ppminorunion);
      }
      ppmx = pppParser->ppstack[pppParser->ppidx].major;
      if( ppmx==PPERRORSYMBOL || pperrorhit ){
#ifndef NDEBUG
        if( ppTraceFILE ){
          fprintf(ppTraceFILE,"%sDiscard input token %s\n",
             ppTracePrompt,ppTokenName[ppmajor]);
        }
#endif
        pp_destructor(ppmajor,&ppminorunion);
        ppmajor = PPNOCODE;
      }else{
         while(
          pppParser->ppidx >= 0 &&
          ppmx != PPERRORSYMBOL &&
          (ppact = pp_find_shift_action(pppParser,PPERRORSYMBOL)) >= PPNSTATE
        ){
          pp_pop_parser_stack(pppParser);
        }
        if( pppParser->ppidx < 0 || ppmajor==0 ){
          pp_destructor(ppmajor,&ppminorunion);
          pp_parse_failed(pppParser);
          ppmajor = PPNOCODE;
        }else if( ppmx!=PPERRORSYMBOL ){
          PPMINORTYPE u2;
          u2.PPERRSYMDT = 0;
          pp_shift(pppParser,ppact,PPERRORSYMBOL,&u2);
        }
      }
      pppParser->pperrcnt = 3;
      pperrorhit = 1;
#else  /* PPERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( pppParser->pperrcnt<=0 ){
        pp_syntax_error(pppParser,ppmajor,ppminorunion);
      }
      pppParser->pperrcnt = 3;
      pp_destructor(ppmajor,&ppminorunion);
      if( ppendofinput ){
        pp_parse_failed(pppParser);
      }
      ppmajor = PPNOCODE;
#endif
    }else{
      pp_accept(pppParser);
      ppmajor = PPNOCODE;
    }
  }while( ppmajor!=PPNOCODE && pppParser->ppidx>=0 );
  return;
}
#else
/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 39 "parser.php7.lemon"

#include "parser.php7.inc.h"

// 12 "parser.php7.c"
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
**    PPCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    PPNOCODE           is a number of type PPCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    PPFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    PPACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    phql_TOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    PPMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is phql_TOKENTYPE.  The entry in the union
**                       for base tokens is called "pp0".
**    PPSTACKDEPTH       is the maximum depth of the parser's stack.
**    phql_ARG_SDECL     A static variable declaration for the %extra_argument
**    phql_ARG_PDECL     A parameter declaration for the %extra_argument
**    phql_ARG_STORE     Code to store %extra_argument into pppParser
**    phql_ARG_FETCH     Code to extract %extra_argument from pppParser
**    PPNSTATE           the combined number of states.
**    PPNRULE            the number of rules in the grammar
**    PPERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define PPCODETYPE unsigned char
#define PPNOCODE 134
#define PPACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE pp0;
  zval pp204;
  int pp267;
} PPMINORTYPE;
#define PPSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = pppParser->status
#define phql_ARG_STORE pppParser->status = status
#define PPNSTATE 293
#define PPNRULE 161
#define PPERRORSYMBOL 79
#define PPERRSYMDT pp267
#define PP_NO_ACTION      (PPNSTATE+PPNRULE+2)
#define PP_ACCEPT_ACTION  (PPNSTATE+PPNRULE+1)
#define PP_ERROR_ACTION   (PPNSTATE+PPNRULE)

/* Next are that tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < PPNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   PPNSTATE <= N < PPNSTATE+PPNRULE   Reduce by rule N-PPNSTATE.
**
**   N == PPNSTATE+PPNRULE              A syntax error has occurred.
**
**   N == PPNSTATE+PPNRULE+1            The parser accepts its input.
**
**   N == PPNSTATE+PPNRULE+2            No such action.  Denotes unused
**                                      slots in the pp_action[] table.
**
** The action table is constructed as a single large table named pp_action[].
** Given state S and lookahead X, the action is computed as
**
**      pp_action[ pp_shift_ofst[S] + X ]
**
** If the index value pp_shift_ofst[S]+X is out of range or if the value
** pp_lookahead[pp_shift_ofst[S]+X] is not equal to X or if pp_shift_ofst[S]
** is equal to PP_SHIFT_USE_DFLT, it means that the action is not in the table
** and that pp_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the pp_reduce_ofst[] array is used in place of
** the pp_shift_ofst[] array and PP_REDUCE_USE_DFLT is used in place of
** PP_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  pp_action[]        A single table containing all actions.
**  pp_lookahead[]     A table containing the lookahead for each entry in
**                     pp_action.  Used to detect hash collisions.
**  pp_shift_ofst[]    For each state, the offset into pp_action for
**                     shifting terminals.
**  pp_reduce_ofst[]   For each state, the offset into pp_action for
**                     shifting non-terminals after a reduce.
**  pp_default[]       Default action for each state.
*/
static PPACTIONTYPE pp_action[] = {
 /*     0 */   120,  126,   55,   57,   59,   61,   63,   65,   45,   47,
 /*    10 */    67,   72,   49,   51,   53,   41,   39,   43,   37,   34,
 /*    20 */   122,   74,   69,  120,  126,   55,   57,   59,   61,   63,
 /*    30 */    65,   45,   47,   67,   72,   49,   51,   53,   41,   39,
 /*    40 */    43,   37,   34,  122,   74,   69,   37,   34,  122,   74,
 /*    50 */    69,  166,  220,   92,  218,   45,   47,   67,   72,   49,
 /*    60 */    51,   53,   41,   39,   43,   37,   34,  122,   74,   69,
 /*    70 */   154,  429,  186,   91,  120,  126,   55,   57,   59,   61,
 /*    80 */    63,   65,   45,   47,   67,   72,   49,   51,   53,   41,
 /*    90 */    39,   43,   37,   34,  122,   74,   69,  120,  126,   55,
 /*   100 */    57,   59,   61,   63,   65,   45,   47,   67,   72,   49,
 /*   110 */    51,   53,   41,   39,   43,   37,   34,  122,   74,   69,
 /*   120 */    19,   20,   21,   22,   23,  227,   32,   33,   67,   72,
 /*   130 */    49,   51,   53,   41,   39,   43,   37,   34,  122,   74,
 /*   140 */    69,  130,  238,  120,  126,   55,   57,   59,   61,   63,
 /*   150 */    65,   45,   47,   67,   72,   49,   51,   53,   41,   39,
 /*   160 */    43,   37,   34,  122,   74,   69,   41,   39,   43,   37,
 /*   170 */    34,  122,   74,   69,  140,    8,  120,  126,   55,   57,
 /*   180 */    59,   61,   63,   65,   45,   47,   67,   72,   49,   51,
 /*   190 */    53,   41,   39,   43,   37,   34,  122,   74,   69,  120,
 /*   200 */   126,   55,   57,   59,   61,   63,   65,   45,   47,   67,
 /*   210 */    72,   49,   51,   53,   41,   39,   43,   37,   34,  122,
 /*   220 */    74,   69,  120,  126,   55,   57,   59,   61,   63,   65,
 /*   230 */    45,   47,   67,   72,   49,   51,   53,   41,   39,   43,
 /*   240 */    37,   34,  122,   74,   69,  168,  109,  156,   35,   95,
 /*   250 */    99,  169,  171,   26,   76,  151,  188,   81,  159,  160,
 /*   260 */    82,  111,  209,  113,  114,   17,  146,  285,  192,  208,
 /*   270 */   194,  196,  128,  200,  204,  222,  223,  455,    1,    2,
 /*   280 */     3,    4,    5,    6,  199,  173,  284,  197,  174,  175,
 /*   290 */   181,  182,  183,  133,  137,  143,   76,  149,  158,   24,
 /*   300 */   212,  217,  178,  176,  177,  179,  180,  168,  135,  271,
 /*   310 */    35,  249,    6,  169,  171,  287,  276,  110,  290,  173,
 /*   320 */   159,   49,   51,   53,   41,   39,   43,   37,   34,  122,
 /*   330 */    74,   69,  158,  384,  128,  430,  192,  208,  194,  196,
 /*   340 */    80,  200,  204,  292,  210,  122,   74,   69,   84,   84,
 /*   350 */   174,  175,  181,  182,  183,  133,  137,  143,  125,  149,
 /*   360 */   107,  107,   95,   90,  178,  176,  177,  179,  180,   55,
 /*   370 */    57,   59,   61,   63,   65,   45,   47,   67,   72,   49,
 /*   380 */    51,   53,   41,   39,   43,   37,   34,  122,   74,   69,
 /*   390 */   213,  274,  258,   35,   70,  228,  169,  171,  131,  109,
 /*   400 */   245,  265,    6,  214,  259,  230,  279,  286,  282,  234,
 /*   410 */   173,   83,  203,    6,  129,  201,   84,  128,  173,  152,
 /*   420 */   154,  207,  186,  158,  205,  162,  244,   96,  107,   85,
 /*   430 */   219,  158,  173,  174,  175,  181,  182,  183,  133,  137,
 /*   440 */   143,   94,  149,  173,    7,  158,  102,  178,  176,  177,
 /*   450 */   179,  180,  162,  232,   35,   89,  158,  169,  171,  184,
 /*   460 */    76,  112,  113,  114,  159,  211,  215,   79,   94,   78,
 /*   470 */   173,  226,  221,  217,   94,    6,  277,  240,  128,  160,
 /*   480 */   165,   84,   98,  158,  250,  163,  184,  162,  103,   95,
 /*   490 */   104,  173,   94,  107,  174,  175,  181,  182,  183,  133,
 /*   500 */   137,  143,   92,  149,  158,  173,  108,  155,  178,  176,
 /*   510 */   177,  179,  180,  168,   92,  224,   35,  258,  158,  169,
 /*   520 */   171,  184,  100,   27,  258,  173,  159,  166,  216,  257,
 /*   530 */   191,  115,  189,  254,  105,  173,  259,  124,  158,   69,
 /*   540 */   128,  110,  173,  107,  166,  281,  282,  225,  158,  252,
 /*   550 */   260,   31,  253,   10,  251,  158,  174,  175,  181,  182,
 /*   560 */   183,  133,  137,  143,  233,  149,  107,  106,   42,  173,
 /*   570 */   178,  176,  177,  179,  180,   30,  247,   35,  329,  245,
 /*   580 */   169,  171,  158,  147,   31,  229,  173,  159,  123,  328,
 /*   590 */   261,  332,  256,  270,  101,  327,  162,  173,  326,  158,
 /*   600 */   325,  128,  173,  173,  242,  246,  206,   28,  237,   18,
 /*   610 */   158,   50,  255,  202,  173,  158,  158,  174,  175,  181,
 /*   620 */   182,  183,  133,  137,  143,  121,  149,  158,  239,  173,
 /*   630 */   167,  178,  176,  177,  179,  180,   97,  269,  164,  119,
 /*   640 */   148,  263,  158,  173,  324,  264,  173,   71,   15,  132,
 /*   650 */   150,  267,  323,  161,  145,  256,  158,  173,   73,  158,
 /*   660 */   134,  170,  172,  198,   62,  173,  322,  333,  173,   60,
 /*   670 */   158,  262,  173,   66,   93,  266,  173,  195,  158,  173,
 /*   680 */   173,  158,  173,  187,  139,  158,  136,  173,  268,  158,
 /*   690 */    11,  173,  158,  158,   76,  158,  295,  185,   58,  340,
 /*   700 */   158,  173,  173,   56,  158,  272,  236,   36,  321,   54,
 /*   710 */    38,  383,  293,  157,  158,  158,  173,  127,   40,  273,
 /*   720 */   193,  173,  275,  278,  173,  173,  280,  173,  173,  158,
 /*   730 */   190,  173,   68,   52,  158,  173,  173,  158,  158,  138,
 /*   740 */   158,  158,   48,  283,  158,   13,   25,   88,  158,  158,
 /*   750 */   173,  173,   16,  248,   87,   86,   44,   46,   64,  297,
 /*   760 */   173,  294,  141,  158,  158,  296,  142,  288,  153,  289,
 /*   770 */   346,  173,  291,  158,  173,  173,  173,   12,   29,   75,
 /*   780 */    77,  144,    9,  235,  158,  117,  241,  158,  158,  158,
 /*   790 */   118,  231,  243,  296,  116,   14,
};
static PPCODETYPE pp_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,    1,    2,    3,    4,    5,    6,    7,
 /*    30 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    40 */    18,   19,   20,   21,   22,   23,   19,   20,   21,   22,
 /*    50 */    23,   25,   30,   25,   32,    9,   10,   11,   12,   13,
 /*    60 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*    70 */    71,   45,   73,   45,    1,    2,    3,    4,    5,    6,
 /*    80 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    90 */    17,   18,   19,   20,   21,   22,   23,    1,    2,    3,
 /*   100 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   110 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   120 */    60,   61,   62,   63,   64,   45,   53,   54,   11,   12,
 /*   130 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   140 */    23,   45,   56,    1,    2,    3,    4,    5,    6,    7,
 /*   150 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   160 */    18,   19,   20,   21,   22,   23,   16,   17,   18,   19,
 /*   170 */    20,   21,   22,   23,   32,   88,    1,    2,    3,    4,
 /*   180 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   190 */    15,   16,   17,   18,   19,   20,   21,   22,   23,    1,
 /*   200 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   210 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   220 */    22,   23,    1,    2,    3,    4,    5,    6,    7,    8,
 /*   230 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   240 */    19,   20,   21,   22,   23,   17,   31,   72,   20,  119,
 /*   250 */   120,   23,   24,   51,   26,  127,  128,   96,   30,   44,
 /*   260 */    25,  100,  101,  102,  103,   25,   68,   98,   33,   34,
 /*   270 */    35,   36,   44,   38,   39,   28,   29,   80,   81,   82,
 /*   280 */    83,   84,   85,   86,   34,  116,  117,   37,   60,   61,
 /*   290 */    62,   63,   64,   65,   66,   67,   26,   69,  129,   59,
 /*   300 */    97,   98,   74,   75,   76,   77,   78,   17,   82,  112,
 /*   310 */    20,   41,   86,   23,   24,  118,   46,   30,   48,  116,
 /*   320 */    30,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   330 */    22,   23,  129,    0,   44,   45,   33,   34,   35,   36,
 /*   340 */    95,   38,   39,   99,   99,   21,   22,   23,  104,  104,
 /*   350 */    60,   61,   62,   63,   64,   65,   66,   67,   74,   69,
 /*   360 */   116,  116,  119,  120,   74,   75,   76,   77,   78,    3,
 /*   370 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   380 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   390 */    17,   58,   98,   20,   11,   12,   23,   24,   82,   31,
 /*   400 */    98,  107,   86,   30,  110,   22,  114,  115,  116,   82,
 /*   410 */   116,   99,   34,   86,   98,   37,  104,   44,  116,   70,
 /*   420 */    71,   34,   73,  129,   37,   98,  124,   30,  116,   32,
 /*   430 */    30,  129,  116,   60,   61,   62,   63,   64,   65,   66,
 /*   440 */    67,   30,   69,  116,   87,  129,   49,   74,   75,   76,
 /*   450 */    77,   78,   98,  126,   20,   44,  129,   23,   24,  132,
 /*   460 */    26,  101,  102,  103,   30,   25,   31,   27,   30,   94,
 /*   470 */   116,   82,   97,   98,   30,   86,   99,   55,   44,   44,
 /*   480 */   126,  104,   44,  129,   42,  131,  132,   98,   44,  119,
 /*   490 */   120,  116,   30,  116,   60,   61,   62,   63,   64,   65,
 /*   500 */    66,   67,   25,   69,  129,  116,   30,   98,   74,   75,
 /*   510 */    76,   77,   78,   17,   25,  126,   20,   98,  129,   23,
 /*   520 */    24,  132,   45,   52,   98,  116,   30,   25,   17,  110,
 /*   530 */    30,  104,   32,  107,   45,  116,  110,   23,  129,   23,
 /*   540 */    44,   30,  116,  116,   25,  115,  116,   45,  129,   43,
 /*   550 */    44,   98,   44,   90,  104,  129,   60,   61,   62,   63,
 /*   560 */    64,   65,   66,   67,   45,   69,  116,  119,   98,  116,
 /*   570 */    74,   75,   76,   77,   78,  122,   50,   20,   30,   98,
 /*   580 */    23,   24,  129,   30,   98,   98,  116,   30,   74,   30,
 /*   590 */   108,    0,   25,  111,  119,   30,   98,  116,   30,  129,
 /*   600 */    30,   44,  116,  116,  123,  124,   34,  121,  122,  125,
 /*   610 */   129,   98,   45,   34,  116,  129,  129,   60,   61,   62,
 /*   620 */    63,   64,   65,   66,   67,   98,   69,  129,   98,  116,
 /*   630 */   132,   74,   75,   76,   77,   78,   49,   30,   45,   98,
 /*   640 */    45,   43,  129,  116,   30,   44,  116,   98,   58,   45,
 /*   650 */    98,   25,   30,  130,   98,   25,  129,  116,   98,  129,
 /*   660 */    44,   98,   98,   34,   98,  116,   30,    0,  116,   98,
 /*   670 */   129,   45,  116,   98,  119,   45,  116,   34,  129,  116,
 /*   680 */   116,  129,  116,   98,   98,  129,   45,  116,  111,  129,
 /*   690 */    91,  116,  129,  129,   26,  129,    0,   28,   98,    0,
 /*   700 */   129,  116,  116,   98,  129,   87,   98,   98,   30,   98,
 /*   710 */    98,    0,    0,   98,  129,  129,  116,   98,   98,  113,
 /*   720 */    34,  116,  125,   47,  116,  116,   25,  116,  116,  129,
 /*   730 */    30,  116,   98,   98,  129,  116,  116,  129,  129,   44,
 /*   740 */   129,  129,   98,    3,  129,   57,  125,  119,  129,  129,
 /*   750 */   116,  116,  125,   98,   49,   30,   98,   98,   98,    0,
 /*   760 */   116,    0,   30,  129,  129,    0,   45,   87,  128,  113,
 /*   770 */     0,  116,   27,  129,  116,  116,  116,   92,   25,   44,
 /*   780 */    93,   44,   89,   45,  129,  106,   52,  129,  129,  129,
 /*   790 */    40,   44,   25,  133,  105,   46,
};
#define PP_SHIFT_USE_DFLT (-2)
static short pp_shift_ofst[] = {
 /*     0 */   270,  712,  761,  696,  765,  759,  526,  422,   86,  202,
 /*    10 */   590,  688,   -2,  749,   -2,   60,  240,   60,   -2,   -2,
 /*    20 */    -2,   -2,   -2,   -2,   60,   -2,  471,  557,  753,  557,
 /*    30 */    -2,   73,   -2,   -2,  557,  557,  324,  557,  324,  557,
 /*    40 */    27,  557,   27,  557,   27,  557,  117,  557,  117,  557,
 /*    50 */   150,  557,  150,  557,  150,  557,   46,  557,   46,  557,
 /*    60 */    46,  557,   46,  557,   46,  557,   46,  557,  308,  383,
 /*    70 */   557,  516,  557,  308,  735,  228,  247,  373,  440,  476,
 /*    80 */   235,   -2,  476,   -2,  397,  725,  705,  411,   -2,  462,
 /*    90 */    28,   -2,  462,   -2,   -2,   -2,  587,  438,  462,  477,
 /*   100 */    -2,   -2,  444,  462,  489,   -2,   -2,   -2,  368,  287,
 /*   110 */    -2,  303,   -2,   -2,  476,  500,  750,   -2,  557,  221,
 /*   120 */   557,  221,  514,   -2,  284,   -2,  557,  366,  434,   96,
 /*   130 */    -2,  604,   -2,  616,  668,  641,   -2,  695,  557,  142,
 /*   140 */   732,  721,   -2,  737,  557,  198,  553,  595,   -2,  557,
 /*   150 */    -1,  349,   -2,   -2,  557,  175,  557,  221,   -2,  215,
 /*   160 */   669,  290,  221,  593,   -2,   26,  496,   -2,   -2,  557,
 /*   170 */   516,  557,  516,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   180 */    -2,   -2,   -2,   -2,   -2,   -2,  557,  221,   -2,  700,
 /*   190 */    -2,   -2,  686,  678,  643,  636,  250,  629,  622,  614,
 /*   200 */   378,  579,  570,  568,  387,  572,  565,  559,  548,   -2,
 /*   210 */    -2,  373,   -2,   -2,  435,  511,   -2,   22,  400,   -2,
 /*   220 */    -2,   -2,   -2,   -2,  502,   -2,   80,   -2,  557,  516,
 /*   230 */   747,  228,  519,   -2,  738,   -2,  324,   -2,  557,  221,
 /*   240 */   734,  557,  767,  557,   -2,  221,   -2,  557,  221,  442,
 /*   250 */   476,  506,  508,  557,  567,  591,  557,   -2,  221,   -2,
 /*   260 */   607,  626,  598,  601,  557,  630,  667,  607,   -2,   -2,
 /*   270 */    -2,  526,  333,  699,   60,  711,  476,  676,  476,  701,
 /*   280 */   476,   -2,  740,  557,   -2,  221,   -2,  526,  333,  770,
 /*   290 */   745,  476,   -2,
};
#define PP_REDUCE_USE_DFLT (-1)
static short pp_reduce_ofst[] = {
 /*     0 */   197,   -1,   -1,   -1,   -1,   -1,  357,   87,  693,  463,
 /*    10 */   599,  685,   -1,   -1,   -1,  627,   -1,  484,   -1,   -1,
 /*    20 */    -1,   -1,   -1,   -1,  621,   -1,   -1,  486,   -1,  453,
 /*    30 */    -1,   -1,   -1,   -1,  608,  609,   -1,  612,   -1,  620,
 /*    40 */    -1,  470,   -1,  658,   -1,  659,   -1,  644,   -1,  513,
 /*    50 */    -1,  635,   -1,  611,   -1,  605,   -1,  600,   -1,  571,
 /*    60 */    -1,  566,   -1,  660,   -1,  575,   -1,  634,   -1,   -1,
 /*    70 */   549,   -1,  560,   -1,   -1,  389,  687,  375,   -1,  245,
 /*    80 */   161,   -1,  312,   -1,   -1,   -1,   -1,  628,   -1,  243,
 /*    90 */    -1,   -1,  555,   -1,   -1,   -1,   -1,  475,  130,   -1,
 /*   100 */    -1,   -1,  448,  370,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   110 */    -1,  360,   -1,   -1,  427,  689,  679,   -1,  541,   -1,
 /*   120 */   527,   -1,   -1,   -1,   -1,   -1,  619,   -1,  316,   -1,
 /*   130 */    -1,   -1,   -1,   -1,  226,   -1,   -1,   -1,  586,   -1,
 /*   140 */    -1,   -1,   -1,   -1,  556,   -1,   -1,   -1,   -1,  552,
 /*   150 */   128,  640,   -1,   -1,  409,   -1,  615,   -1,   -1,   -1,
 /*   160 */   523,  354,   -1,   -1,   -1,   -1,  498,   -1,   -1,  563,
 /*   170 */    -1,  564,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   180 */    -1,   -1,   -1,   -1,   -1,   -1,  585,   -1,   -1,   -1,
 /*   190 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   200 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   210 */    -1,  203,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   220 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  487,   -1,
 /*   230 */    -1,  327,   -1,   -1,   -1,   -1,   -1,   -1,  530,   -1,
 /*   240 */    -1,  481,   -1,  302,   -1,   -1,   -1,  655,   -1,   -1,
 /*   250 */   450,   -1,   -1,  426,   -1,   -1,  419,   -1,   -1,   -1,
 /*   260 */   482,   -1,   -1,   -1,  294,   -1,   -1,  577,   -1,   -1,
 /*   270 */    -1,  618,  606,   -1,  597,   -1,  377,   -1,  292,   -1,
 /*   280 */   430,   -1,   -1,  169,   -1,   -1,   -1,  680,  656,   -1,
 /*   290 */    -1,  244,   -1,
};
static PPACTIONTYPE pp_default[] = {
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
#define PP_SZ_ACTTAB (sizeof(pp_action)/sizeof(pp_action[0]))

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
#ifdef PPFALLBACK
static const PPCODETYPE ppFallback[] = {
};
#endif /* PPFALLBACK */

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
struct ppStackEntry {
  int stateno;       /* The state-number */
  int major;         /* The major token value.  This is the code
                     ** number for the token at this stack level */
  PPMINORTYPE minor; /* The user-supplied minor token value.  This
                     ** is the value of the token  */
};
typedef struct ppStackEntry ppStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct ppParser {
  int ppidx;                    /* Index of top element in stack */
  int pperrcnt;                 /* Shifts left before out of the error */
  phql_ARG_SDECL                /* A place to hold %extra_argument */
  ppStackEntry ppstack[PPSTACKDEPTH];  /* The parser's stack */
};
typedef struct ppParser ppParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *ppTraceFILE = 0;
static char *ppTracePrompt = 0;
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
  ppTraceFILE = TraceFILE;
  ppTracePrompt = zTracePrompt;
  if( ppTraceFILE==0 ) ppTracePrompt = 0;
  else if( ppTracePrompt==0 ) ppTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *ppTokenName[] = { 
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
static const char *ppRuleName[] = {
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
  if( tokenType>0 && tokenType<(sizeof(ppTokenName)/sizeof(ppTokenName[0])) ){
    return ppTokenName[tokenType];
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
  ppParser *pParser;
  pParser = (ppParser*)(*mallocProc)( (size_t)sizeof(ppParser) );
  if( pParser ){
    pParser->ppidx = -1;
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "ppmajor" is the symbol code, and "pppminor" is a pointer to
** the value.
*/
static void pp_destructor(PPCODETYPE ppmajor, PPMINORTYPE *pppminor){
  switch( ppmajor ){
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
// 110 "parser.php7.lemon"
{
	if ((pppminor->pp0)) {
		if ((pppminor->pp0)->free_flag) {
			efree((pppminor->pp0)->token);
		}
		efree((pppminor->pp0));
	}
}
// 822 "parser.php7.c"
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
// 123 "parser.php7.lemon"
{
    zval_ptr_dtor(&(pppminor->pp204));
}
// 857 "parser.php7.c"
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
// 505 "parser.php7.lemon"
{
    zephir_safe_zval_ptr_dtor((pppminor->pp204));
}
// 874 "parser.php7.c"
      break;
    case 116:
    case 124:
    case 126:
    case 129:
    case 132:
// 948 "parser.php7.lemon"
{
	zval_ptr_dtor(&(pppminor->pp204));
}
// 885 "parser.php7.c"
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
static int pp_pop_parser_stack(ppParser *pParser){
  PPCODETYPE ppmajor;
  ppStackEntry *pptos = &pParser->ppstack[pParser->ppidx];

  if( pParser->ppidx<0 ) return 0;
#ifndef NDEBUG
  if( ppTraceFILE && pParser->ppidx>=0 ){
    fprintf(ppTraceFILE,"%sPopping %s\n",
      ppTracePrompt,
      ppTokenName[pptos->major]);
  }
#endif
  ppmajor = pptos->major;
  pp_destructor( ppmajor, &pptos->minor);
  pParser->ppidx--;
  return ppmajor;
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
  ppParser *pParser = (ppParser*)p;
  if( pParser==0 ) return;
  while( pParser->ppidx>=0 ) pp_pop_parser_stack(pParser);
  (*freeProc)((void*)pParser);
}

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is PPNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return PP_NO_ACTION.
*/
static int pp_find_shift_action(
  ppParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->ppstack[pParser->ppidx].stateno;
 
  /* if( pParser->ppidx<0 ) return PP_NO_ACTION;  */
  i = pp_shift_ofst[stateno];
  if( i==PP_SHIFT_USE_DFLT ){
    return pp_default[stateno];
  }
  if( iLookAhead==PPNOCODE ){
    return PP_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=PP_SZ_ACTTAB || pp_lookahead[i]!=iLookAhead ){
#ifdef PPFALLBACK
    int iFallback;            /* Fallback token */
    if( iLookAhead<sizeof(ppFallback)/sizeof(ppFallback[0])
           && (iFallback = ppFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
      if( ppTraceFILE ){
        fprintf(ppTraceFILE, "%sFALLBACK %s => %s\n",
           ppTracePrompt, ppTokenName[iLookAhead], ppTokenName[iFallback]);
      }
#endif
      return pp_find_shift_action(pParser, iFallback);
    }
#endif
    return pp_default[stateno];
  }else{
    return pp_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is PPNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return PP_NO_ACTION.
*/
static int pp_find_reduce_action(
  ppParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->ppstack[pParser->ppidx].stateno;
 
  i = pp_reduce_ofst[stateno];
  if( i==PP_REDUCE_USE_DFLT ){
    return pp_default[stateno];
  }
  if( iLookAhead==PPNOCODE ){
    return PP_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=PP_SZ_ACTTAB || pp_lookahead[i]!=iLookAhead ){
    return pp_default[stateno];
  }else{
    return pp_action[i];
  }
}

/*
** Perform a shift action.
*/
static void pp_shift(
  ppParser *pppParser,          /* The parser to be shifted */
  int ppNewState,               /* The new state to shift in */
  int ppMajor,                  /* The major token to shift in */
  PPMINORTYPE *pppMinor         /* Pointer ot the minor token to shift in */
){
  ppStackEntry *pptos;
  pppParser->ppidx++;
  if( pppParser->ppidx>=PPSTACKDEPTH ){
     phql_ARG_FETCH;
     pppParser->ppidx--;
#ifndef NDEBUG
     if( ppTraceFILE ){
       fprintf(ppTraceFILE,"%sStack Overflow!\n",ppTracePrompt);
     }
#endif
     while( pppParser->ppidx>=0 ) pp_pop_parser_stack(pppParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     phql_ARG_STORE; /* Suppress warning about unused %extra_argument var */
     return;
  }
  pptos = &pppParser->ppstack[pppParser->ppidx];
  pptos->stateno = ppNewState;
  pptos->major = ppMajor;
  pptos->minor = *pppMinor;
#ifndef NDEBUG
  if( ppTraceFILE && pppParser->ppidx>0 ){
    int i;
    fprintf(ppTraceFILE,"%sShift %d\n",ppTracePrompt,ppNewState);
    fprintf(ppTraceFILE,"%sStack:",ppTracePrompt);
    for(i=1; i<=pppParser->ppidx; i++)
      fprintf(ppTraceFILE," %s",ppTokenName[pppParser->ppstack[i].major]);
    fprintf(ppTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static struct {
  PPCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} ppRuleInfo[] = {
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

static void pp_accept(ppParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void pp_reduce(
  ppParser *pppParser,         /* The parser */
  int ppruleno                 /* Number of the rule by which to reduce */
){
  int ppgoto;                     /* The next state */
  int ppact;                      /* The next action */
  PPMINORTYPE ppgotominor;        /* The LHS of the rule reduced */
  ppStackEntry *ppmsp;            /* The top of the parser's stack */
  int ppsize;                     /* Amount to pop the stack */
  phql_ARG_FETCH;
  ppmsp = &pppParser->ppstack[pppParser->ppidx];
#ifndef NDEBUG
  if( ppTraceFILE && ppruleno>=0 
        && ppruleno<sizeof(ppRuleName)/sizeof(ppRuleName[0]) ){
    fprintf(ppTraceFILE, "%sReduce [%s].\n", ppTracePrompt,
      ppRuleName[ppruleno]);
  }
#endif /* NDEBUG */

  switch( ppruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  // <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  // <lineno> <thisfile>
  **     break;
  */
      case 0:
// 119 "parser.php7.lemon"
{
	ZVAL_ZVAL(&status->ret, &ppmsp[0].minor.pp204, 1, 1);
}
// 1263 "parser.php7.c"
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
// 127 "parser.php7.lemon"
{
	ppgotominor.pp204 = ppmsp[0].minor.pp204;
}
// 1289 "parser.php7.c"
        break;
      case 5:
// 147 "parser.php7.lemon"
{
	phql_ret_select_statement(&ppgotominor.pp204, &ppmsp[-6].minor.pp204, &ppmsp[-5].minor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[-4].minor.pp204, &ppmsp[-3].minor.pp204, &ppmsp[-1].minor.pp204, &ppmsp[0].minor.pp204);
}
// 1296 "parser.php7.c"
        break;
      case 6:
// 155 "parser.php7.lemon"
{
	phql_ret_select_clause(&ppgotominor.pp204, &ppmsp[-4].minor.pp204, &ppmsp[-3].minor.pp204, &ppmsp[-1].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(26,&ppmsp[-5].minor);
  pp_destructor(27,&ppmsp[-2].minor);
}
// 1305 "parser.php7.c"
        break;
      case 7:
// 163 "parser.php7.lemon"
{
	phql_ret_distinct_all(&ppgotominor.pp204, 1);
  pp_destructor(28,&ppmsp[0].minor);
}
// 1313 "parser.php7.c"
        break;
      case 8:
// 167 "parser.php7.lemon"
{
	phql_ret_distinct_all(&ppgotominor.pp204, 0);
  pp_destructor(29,&ppmsp[0].minor);
}
// 1321 "parser.php7.c"
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
// 171 "parser.php7.lemon"
{
	ZVAL_UNDEF(&ppgotominor.pp204);
}
// 1340 "parser.php7.c"
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
// 179 "parser.php7.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 1356 "parser.php7.c"
        break;
      case 11:
      case 42:
      case 45:
      case 129:
      case 139:
// 183 "parser.php7.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp204, &ppmsp[0].minor.pp204, NULL);
}
// 1367 "parser.php7.c"
        break;
      case 12:
      case 140:
// 191 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp204, PHQL_T_STARALL, NULL, NULL, NULL);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1376 "parser.php7.c"
        break;
      case 13:
// 195 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp204, PHQL_T_DOMAINALL, NULL, ppmsp[-2].minor.pp0, NULL);
  pp_destructor(31,&ppmsp[-1].minor);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1385 "parser.php7.c"
        break;
      case 14:
// 199 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp204, PHQL_T_EXPR, &ppmsp[-2].minor.pp204, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1393 "parser.php7.c"
        break;
      case 15:
// 203 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp204, PHQL_T_EXPR, &ppmsp[-1].minor.pp204, NULL, ppmsp[0].minor.pp0);
}
// 1400 "parser.php7.c"
        break;
      case 16:
// 207 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp204, PHQL_T_EXPR, &ppmsp[0].minor.pp204, NULL, NULL);
}
// 1407 "parser.php7.c"
        break;
      case 21:
      case 128:
// 235 "parser.php7.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp204, &ppmsp[-1].minor.pp204, &ppmsp[0].minor.pp204);
}
// 1415 "parser.php7.c"
        break;
      case 24:
// 256 "parser.php7.lemon"
{
	phql_ret_join_item(&ppgotominor.pp204, &ppmsp[-3].minor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[-1].minor.pp204, &ppmsp[0].minor.pp204);
}
// 1422 "parser.php7.c"
        break;
      case 25:
// 264 "parser.php7.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp204, NULL, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1430 "parser.php7.c"
        break;
      case 26:
      case 46:
      case 66:
      case 160:
// 268 "parser.php7.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp204, NULL, NULL, ppmsp[0].minor.pp0);
}
// 1440 "parser.php7.c"
        break;
      case 28:
// 280 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_INNERJOIN);
  pp_destructor(33,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1449 "parser.php7.c"
        break;
      case 29:
// 284 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_CROSSJOIN);
  pp_destructor(35,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1458 "parser.php7.c"
        break;
      case 30:
// 288 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1468 "parser.php7.c"
        break;
      case 31:
// 292 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1477 "parser.php7.c"
        break;
      case 32:
// 296 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1487 "parser.php7.c"
        break;
      case 33:
// 300 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1496 "parser.php7.c"
        break;
      case 34:
// 304 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1506 "parser.php7.c"
        break;
      case 35:
// 308 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1515 "parser.php7.c"
        break;
      case 36:
// 312 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_INNERJOIN);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1523 "parser.php7.c"
        break;
      case 37:
// 320 "parser.php7.lemon"
{
	ppgotominor.pp204 = ppmsp[0].minor.pp204;
  pp_destructor(40,&ppmsp[-1].minor);
}
// 1531 "parser.php7.c"
        break;
      case 39:
// 333 "parser.php7.lemon"
{
	phql_ret_insert_statement(&ppgotominor.pp204, &ppmsp[-4].minor.pp204, NULL, &ppmsp[-1].minor.pp204);
  pp_destructor(41,&ppmsp[-6].minor);
  pp_destructor(42,&ppmsp[-5].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1543 "parser.php7.c"
        break;
      case 40:
// 337 "parser.php7.lemon"
{
	phql_ret_insert_statement(&ppgotominor.pp204, &ppmsp[-7].minor.pp204, &ppmsp[-5].minor.pp204, &ppmsp[-1].minor.pp204);
  pp_destructor(41,&ppmsp[-9].minor);
  pp_destructor(42,&ppmsp[-8].minor);
  pp_destructor(44,&ppmsp[-6].minor);
  pp_destructor(45,&ppmsp[-4].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1557 "parser.php7.c"
        break;
      case 47:
// 383 "parser.php7.lemon"
{
	phql_ret_update_statement(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[-1].minor.pp204, &ppmsp[0].minor.pp204);
}
// 1564 "parser.php7.c"
        break;
      case 48:
// 391 "parser.php7.lemon"
{
	phql_ret_update_clause(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(46,&ppmsp[-3].minor);
  pp_destructor(47,&ppmsp[-1].minor);
}
// 1573 "parser.php7.c"
        break;
      case 51:
// 411 "parser.php7.lemon"
{
	phql_ret_update_item(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 1581 "parser.php7.c"
        break;
      case 53:
// 425 "parser.php7.lemon"
{
	phql_ret_delete_statement(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[-1].minor.pp204, &ppmsp[0].minor.pp204);
}
// 1588 "parser.php7.c"
        break;
      case 54:
// 433 "parser.php7.lemon"
{
	phql_ret_delete_clause(&ppgotominor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(48,&ppmsp[-2].minor);
  pp_destructor(27,&ppmsp[-1].minor);
}
// 1597 "parser.php7.c"
        break;
      case 55:
// 441 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, ppmsp[0].minor.pp0, NULL);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1605 "parser.php7.c"
        break;
      case 56:
// 445 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-1].minor.pp204, ppmsp[0].minor.pp0, NULL);
}
// 1612 "parser.php7.c"
        break;
      case 57:
// 449 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[0].minor.pp204, NULL, NULL);
}
// 1619 "parser.php7.c"
        break;
      case 58:
// 453 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-4].minor.pp204, ppmsp[-2].minor.pp0, &ppmsp[0].minor.pp204);
  pp_destructor(32,&ppmsp[-3].minor);
  pp_destructor(49,&ppmsp[-1].minor);
}
// 1628 "parser.php7.c"
        break;
      case 59:
// 457 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-6].minor.pp204, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp204);
  pp_destructor(32,&ppmsp[-5].minor);
  pp_destructor(49,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1639 "parser.php7.c"
        break;
      case 60:
// 461 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-5].minor.pp204, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp204);
  pp_destructor(49,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1649 "parser.php7.c"
        break;
      case 61:
// 465 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-3].minor.pp204, ppmsp[-2].minor.pp0, &ppmsp[0].minor.pp204);
  pp_destructor(49,&ppmsp[-1].minor);
}
// 1657 "parser.php7.c"
        break;
      case 62:
// 469 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-4].minor.pp204, NULL, &ppmsp[-1].minor.pp204);
  pp_destructor(49,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1667 "parser.php7.c"
        break;
      case 63:
// 473 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, NULL, &ppmsp[0].minor.pp204);
  pp_destructor(49,&ppmsp[-1].minor);
}
// 1675 "parser.php7.c"
        break;
      case 68:
// 509 "parser.php7.lemon"
{
	ppgotominor.pp204 = ppmsp[0].minor.pp204;
  pp_destructor(50,&ppmsp[-1].minor);
}
// 1683 "parser.php7.c"
        break;
      case 70:
// 521 "parser.php7.lemon"
{
	ppgotominor.pp204 = ppmsp[0].minor.pp204;
  pp_destructor(51,&ppmsp[-2].minor);
  pp_destructor(52,&ppmsp[-1].minor);
}
// 1692 "parser.php7.c"
        break;
      case 74:
// 545 "parser.php7.lemon"
{
	phql_ret_order_item(&ppgotominor.pp204, &ppmsp[0].minor.pp204, 0);
}
// 1699 "parser.php7.c"
        break;
      case 75:
// 549 "parser.php7.lemon"
{
	phql_ret_order_item(&ppgotominor.pp204, &ppmsp[-1].minor.pp204, PHQL_T_ASC);
  pp_destructor(53,&ppmsp[0].minor);
}
// 1707 "parser.php7.c"
        break;
      case 76:
// 553 "parser.php7.lemon"
{
	phql_ret_order_item(&ppgotominor.pp204, &ppmsp[-1].minor.pp204, PHQL_T_DESC);
  pp_destructor(54,&ppmsp[0].minor);
}
// 1715 "parser.php7.c"
        break;
      case 77:
// 561 "parser.php7.lemon"
{
	ppgotominor.pp204 = ppmsp[0].minor.pp204;
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(52,&ppmsp[-1].minor);
}
// 1724 "parser.php7.c"
        break;
      case 82:
// 593 "parser.php7.lemon"
{
	ppgotominor.pp204 = ppmsp[0].minor.pp204;
  pp_destructor(56,&ppmsp[-1].minor);
}
// 1732 "parser.php7.c"
        break;
      case 84:
// 605 "parser.php7.lemon"
{
	phql_ret_for_update_clause(&ppgotominor.pp204);
  pp_destructor(57,&ppmsp[-1].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1741 "parser.php7.c"
        break;
      case 86:
      case 90:
// 617 "parser.php7.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp204, &ppmsp[0].minor.pp204, NULL);
  pp_destructor(58,&ppmsp[-1].minor);
}
// 1750 "parser.php7.c"
        break;
      case 87:
// 621 "parser.php7.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp204, &ppmsp[0].minor.pp204, &ppmsp[-2].minor.pp204);
  pp_destructor(58,&ppmsp[-3].minor);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 1759 "parser.php7.c"
        break;
      case 88:
// 625 "parser.php7.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(58,&ppmsp[-3].minor);
  pp_destructor(59,&ppmsp[-1].minor);
}
// 1768 "parser.php7.c"
        break;
      case 92:
      case 149:
// 645 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp204, PHQL_T_INTEGER, ppmsp[0].minor.pp0);
}
// 1776 "parser.php7.c"
        break;
      case 93:
      case 150:
// 649 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp204, PHQL_T_HINTEGER, ppmsp[0].minor.pp0);
}
// 1784 "parser.php7.c"
        break;
      case 94:
      case 156:
// 653 "parser.php7.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp204, PHQL_T_NPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1792 "parser.php7.c"
        break;
      case 95:
      case 157:
// 657 "parser.php7.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp204, PHQL_T_SPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1800 "parser.php7.c"
        break;
      case 96:
      case 158:
// 661 "parser.php7.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp204, PHQL_T_BPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1808 "parser.php7.c"
        break;
      case 97:
// 669 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_MINUS, NULL, &ppmsp[0].minor.pp204);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 1816 "parser.php7.c"
        break;
      case 98:
// 673 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_SUB, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 1824 "parser.php7.c"
        break;
      case 99:
// 677 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_ADD, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(19,&ppmsp[-1].minor);
}
// 1832 "parser.php7.c"
        break;
      case 100:
// 681 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_MUL, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 1840 "parser.php7.c"
        break;
      case 101:
// 685 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_DIV, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 1848 "parser.php7.c"
        break;
      case 102:
// 689 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_MOD, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(18,&ppmsp[-1].minor);
}
// 1856 "parser.php7.c"
        break;
      case 103:
// 693 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_AND, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(9,&ppmsp[-1].minor);
}
// 1864 "parser.php7.c"
        break;
      case 104:
// 697 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_OR, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(10,&ppmsp[-1].minor);
}
// 1872 "parser.php7.c"
        break;
      case 105:
// 701 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_BITWISE_AND, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 1880 "parser.php7.c"
        break;
      case 106:
// 705 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_BITWISE_OR, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(14,&ppmsp[-1].minor);
}
// 1888 "parser.php7.c"
        break;
      case 107:
// 709 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_BITWISE_XOR, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(15,&ppmsp[-1].minor);
}
// 1896 "parser.php7.c"
        break;
      case 108:
// 713 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_EQUALS, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 1904 "parser.php7.c"
        break;
      case 109:
// 717 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_NOTEQUALS, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 1912 "parser.php7.c"
        break;
      case 110:
// 721 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_LESS, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(5,&ppmsp[-1].minor);
}
// 1920 "parser.php7.c"
        break;
      case 111:
// 725 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_GREATER, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(6,&ppmsp[-1].minor);
}
// 1928 "parser.php7.c"
        break;
      case 112:
// 729 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_GREATEREQUAL, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(7,&ppmsp[-1].minor);
}
// 1936 "parser.php7.c"
        break;
      case 113:
// 733 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_LESSEQUAL, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(8,&ppmsp[-1].minor);
}
// 1944 "parser.php7.c"
        break;
      case 114:
// 737 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_LIKE, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 1952 "parser.php7.c"
        break;
      case 115:
// 741 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_NLIKE, &ppmsp[-3].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 1961 "parser.php7.c"
        break;
      case 116:
// 745 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_ILIKE, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 1969 "parser.php7.c"
        break;
      case 117:
// 749 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_NILIKE, &ppmsp[-3].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 1978 "parser.php7.c"
        break;
      case 118:
      case 121:
// 753 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_IN, &ppmsp[-4].minor.pp204, &ppmsp[-1].minor.pp204);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1989 "parser.php7.c"
        break;
      case 119:
      case 122:
// 757 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_NOTIN, &ppmsp[-5].minor.pp204, &ppmsp[-1].minor.pp204);
  pp_destructor(23,&ppmsp[-4].minor);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2001 "parser.php7.c"
        break;
      case 120:
// 761 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_SUBQUERY, &ppmsp[-1].minor.pp204, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2010 "parser.php7.c"
        break;
      case 123:
// 773 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_EXISTS, NULL, &ppmsp[-1].minor.pp204);
  pp_destructor(65,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2020 "parser.php7.c"
        break;
      case 124:
// 777 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_AGAINST, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(1,&ppmsp[-1].minor);
}
// 2028 "parser.php7.c"
        break;
      case 125:
// 781 "parser.php7.lemon"
{
	{
		zval qualified;
		phql_ret_raw_qualified_name(&qualified, ppmsp[-1].minor.pp0, NULL);
		phql_ret_expr(&ppgotominor.pp204, PHQL_T_CAST, &ppmsp[-3].minor.pp204, &qualified);
	}
  pp_destructor(66,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(32,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2043 "parser.php7.c"
        break;
      case 126:
// 789 "parser.php7.lemon"
{
	{
		zval qualified;
		phql_ret_raw_qualified_name(&qualified, ppmsp[-1].minor.pp0, NULL);
		phql_ret_expr(&ppgotominor.pp204, PHQL_T_CONVERT, &ppmsp[-3].minor.pp204, &qualified);
	}
  pp_destructor(67,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(68,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2058 "parser.php7.c"
        break;
      case 127:
// 797 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_CASE, &ppmsp[-2].minor.pp204, &ppmsp[-1].minor.pp204);
  pp_destructor(69,&ppmsp[-3].minor);
  pp_destructor(70,&ppmsp[0].minor);
}
// 2067 "parser.php7.c"
        break;
      case 130:
// 809 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_WHEN, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(71,&ppmsp[-3].minor);
  pp_destructor(72,&ppmsp[-1].minor);
}
// 2076 "parser.php7.c"
        break;
      case 131:
// 813 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_ELSE, &ppmsp[0].minor.pp204, NULL);
  pp_destructor(73,&ppmsp[-1].minor);
}
// 2084 "parser.php7.c"
        break;
      case 133:
// 825 "parser.php7.lemon"
{
	phql_ret_func_call(&ppgotominor.pp204, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp204, &ppmsp[-2].minor.pp204);
  pp_destructor(44,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2093 "parser.php7.c"
        break;
      case 134:
// 833 "parser.php7.lemon"
{
	phql_ret_distinct(&ppgotominor.pp204);
  pp_destructor(28,&ppmsp[0].minor);
}
// 2101 "parser.php7.c"
        break;
      case 142:
// 877 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_ISNULL, &ppmsp[-2].minor.pp204, NULL);
  pp_destructor(21,&ppmsp[-1].minor);
  pp_destructor(74,&ppmsp[0].minor);
}
// 2110 "parser.php7.c"
        break;
      case 143:
// 881 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_ISNOTNULL, &ppmsp[-3].minor.pp204, NULL);
  pp_destructor(21,&ppmsp[-2].minor);
  pp_destructor(23,&ppmsp[-1].minor);
  pp_destructor(74,&ppmsp[0].minor);
}
// 2120 "parser.php7.c"
        break;
      case 144:
// 885 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_BETWEEN, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(2,&ppmsp[-1].minor);
}
// 2128 "parser.php7.c"
        break;
      case 145:
// 889 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_NOT, NULL, &ppmsp[0].minor.pp204);
  pp_destructor(23,&ppmsp[-1].minor);
}
// 2136 "parser.php7.c"
        break;
      case 146:
// 893 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_BITWISE_NOT, NULL, &ppmsp[0].minor.pp204);
  pp_destructor(24,&ppmsp[-1].minor);
}
// 2144 "parser.php7.c"
        break;
      case 147:
// 897 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_ENCLOSED, &ppmsp[-1].minor.pp204, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2153 "parser.php7.c"
        break;
      case 151:
// 913 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp204, PHQL_T_STRING, ppmsp[0].minor.pp0);
}
// 2160 "parser.php7.c"
        break;
      case 152:
// 917 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp204, PHQL_T_DOUBLE, ppmsp[0].minor.pp0);
}
// 2167 "parser.php7.c"
        break;
      case 153:
// 921 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp204, PHQL_T_NULL, NULL);
  pp_destructor(74,&ppmsp[0].minor);
}
// 2175 "parser.php7.c"
        break;
      case 154:
// 925 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp204, PHQL_T_TRUE, NULL);
  pp_destructor(77,&ppmsp[0].minor);
}
// 2183 "parser.php7.c"
        break;
      case 155:
// 929 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp204, PHQL_T_FALSE, NULL);
  pp_destructor(78,&ppmsp[0].minor);
}
// 2191 "parser.php7.c"
        break;
      case 159:
// 952 "parser.php7.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp204, NULL, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(31,&ppmsp[-1].minor);
}
// 2199 "parser.php7.c"
        break;
  };
  ppgoto = ppRuleInfo[ppruleno].lhs;
  ppsize = ppRuleInfo[ppruleno].nrhs;
  pppParser->ppidx -= ppsize;
  ppact = pp_find_reduce_action(pppParser,ppgoto);
  if( ppact < PPNSTATE ){
    pp_shift(pppParser,ppact,ppgoto,&ppgotominor);
  }else if( ppact == PPNSTATE + PPNRULE + 1 ){
    pp_accept(pppParser);
  }
}

/*
** The following code executes when the parse fails
*/
static void pp_parse_failed(
  ppParser *pppParser           /* The parser */
){
  phql_ARG_FETCH;
#ifndef NDEBUG
  if( ppTraceFILE ){
    fprintf(ppTraceFILE,"%sFail!\n",ppTracePrompt);
  }
#endif
  while( pppParser->ppidx>=0 ) pp_pop_parser_stack(pppParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void pp_syntax_error(
  ppParser *pppParser,           /* The parser */
  int ppmajor,                   /* The major type of the error token */
  PPMINORTYPE ppminor            /* The minor type of the error token */
){
  phql_ARG_FETCH;
#define PPTOKEN (ppminor.pp0)
// 43 "parser.php7.lemon"

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

// 2308 "parser.php7.c"
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void pp_accept(
  ppParser *pppParser           /* The parser */
){
  phql_ARG_FETCH;
#ifndef NDEBUG
  if( ppTraceFILE ){
    fprintf(ppTraceFILE,"%sAccept!\n",ppTracePrompt);
  }
#endif
  while( pppParser->ppidx>=0 ) pp_pop_parser_stack(pppParser);
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
  void *ppp,                   /* The parser */
  int ppmajor,                 /* The major token code number */
  phql_TOKENTYPE ppminor       /* The value for the token */
  phql_ARG_PDECL               /* Optional %extra_argument parameter */
){
  PPMINORTYPE ppminorunion;
  int ppact;            /* The parser action. */
  int ppendofinput;     /* True if we are at the end of input */
  int pperrorhit = 0;   /* True if ppmajor has invoked an error */
  ppParser *pppParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  pppParser = (ppParser*)ppp;
  if( pppParser->ppidx<0 ){
    if( ppmajor==0 ) return;
    pppParser->ppidx = 0;
    pppParser->pperrcnt = -1;
    pppParser->ppstack[0].stateno = 0;
    pppParser->ppstack[0].major = 0;
  }
  ppminorunion.pp0 = ppminor;
  ppendofinput = (ppmajor==0);
  phql_ARG_STORE;

#ifndef NDEBUG
  if( ppTraceFILE ){
    fprintf(ppTraceFILE,"%sInput %s\n",ppTracePrompt,ppTokenName[ppmajor]);
  }
#endif

  do{
    ppact = pp_find_shift_action(pppParser,ppmajor);
    if( ppact<PPNSTATE ){
      pp_shift(pppParser,ppact,ppmajor,&ppminorunion);
      pppParser->pperrcnt--;
      if( ppendofinput && pppParser->ppidx>=0 ){
        ppmajor = 0;
      }else{
        ppmajor = PPNOCODE;
      }
    }else if( ppact < PPNSTATE + PPNRULE ){
      pp_reduce(pppParser,ppact-PPNSTATE);
    }else if( ppact == PP_ERROR_ACTION ){
      int ppmx;
#ifndef NDEBUG
      if( ppTraceFILE ){
        fprintf(ppTraceFILE,"%sSyntax Error!\n",ppTracePrompt);
      }
#endif
#ifdef PPERRORSYMBOL
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
      if( pppParser->pperrcnt<0 ){
        pp_syntax_error(pppParser,ppmajor,ppminorunion);
      }
      ppmx = pppParser->ppstack[pppParser->ppidx].major;
      if( ppmx==PPERRORSYMBOL || pperrorhit ){
#ifndef NDEBUG
        if( ppTraceFILE ){
          fprintf(ppTraceFILE,"%sDiscard input token %s\n",
             ppTracePrompt,ppTokenName[ppmajor]);
        }
#endif
        pp_destructor(ppmajor,&ppminorunion);
        ppmajor = PPNOCODE;
      }else{
         while(
          pppParser->ppidx >= 0 &&
          ppmx != PPERRORSYMBOL &&
          (ppact = pp_find_shift_action(pppParser,PPERRORSYMBOL)) >= PPNSTATE
        ){
          pp_pop_parser_stack(pppParser);
        }
        if( pppParser->ppidx < 0 || ppmajor==0 ){
          pp_destructor(ppmajor,&ppminorunion);
          pp_parse_failed(pppParser);
          ppmajor = PPNOCODE;
        }else if( ppmx!=PPERRORSYMBOL ){
          PPMINORTYPE u2;
          u2.PPERRSYMDT = 0;
          pp_shift(pppParser,ppact,PPERRORSYMBOL,&u2);
        }
      }
      pppParser->pperrcnt = 3;
      pperrorhit = 1;
#else  /* PPERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( pppParser->pperrcnt<=0 ){
        pp_syntax_error(pppParser,ppmajor,ppminorunion);
      }
      pppParser->pperrcnt = 3;
      pp_destructor(ppmajor,&ppminorunion);
      if( ppendofinput ){
        pp_parse_failed(pppParser);
      }
      ppmajor = PPNOCODE;
#endif
    }else{
      pp_accept(pppParser);
      ppmajor = PPNOCODE;
    }
  }while( ppmajor!=PPNOCODE && pppParser->ppidx>=0 );
  return;
}
#endif

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework													  |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2016 Phalcon Team (http://www.phalconphp.com)	   |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled	   |
  | with this package in the file docs/LICENSE.txt.						   |
  |																	       |
  | If you did not receive a copy of the license and are unable to		   |
  | obtain it through the world-wide-web, please send an email			   |
  | to license@phalconphp.com so we can send you a copy immediately.	   |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>					   |
  |		  Eduar Carvajal <eduar@phalconphp.com>						       |
  +------------------------------------------------------------------------+
*/

const phql_token_names phql_tokens[] =
{
  { SL("INTEGER"),			   PHQL_T_INTEGER },
  { SL("DOUBLE"),			   PHQL_T_DOUBLE },
  { SL("STRING"),			   PHQL_T_STRING },
  { SL("IDENTIFIER"),		   PHQL_T_IDENTIFIER },
  { SL("HEXAINTEGER"),		   PHQL_T_HINTEGER },
  { SL("MINUS"),			   PHQL_T_MINUS },
  { SL("+"),				   PHQL_T_ADD },
  { SL("-"),				   PHQL_T_SUB },
  { SL("*"),				   PHQL_T_MUL },
  { SL("/"),				   PHQL_T_DIV },
  { SL("&"),				   PHQL_T_BITWISE_AND },
  { SL("|"),				   PHQL_T_BITWISE_OR },
  { SL("%%"),				   PHQL_T_MOD },
  { SL("AND"),				   PHQL_T_AND },
  { SL("OR"),				   PHQL_T_OR },
  { SL("LIKE"),				   PHQL_T_LIKE },
  { SL("ILIKE"),			   PHQL_T_ILIKE },
  { SL("DOT"),				   PHQL_T_DOT },
  { SL("COLON"),			   PHQL_T_COLON },
  { SL("COMMA"),			   PHQL_T_COMMA },
  { SL("EQUALS"),			   PHQL_T_EQUALS },
  { SL("NOT EQUALS"),		   PHQL_T_NOTEQUALS },
  { SL("NOT"),				   PHQL_T_NOT },
  { SL("<"),				   PHQL_T_LESS },
  { SL("<="),				   PHQL_T_LESSEQUAL },
  { SL(">"),				   PHQL_T_GREATER },
  { SL(">="),				   PHQL_T_GREATEREQUAL },
  { SL("("),				   PHQL_T_PARENTHESES_OPEN },
  { SL(")"),				   PHQL_T_PARENTHESES_CLOSE },
  { SL("NUMERIC PLACEHOLDER"), PHQL_T_NPLACEHOLDER },
  { SL("STRING PLACEHOLDER"),  PHQL_T_SPLACEHOLDER },
  { SL("UPDATE"),			   PHQL_T_UPDATE },
  { SL("SET"),				   PHQL_T_SET },
  { SL("WHERE"),			   PHQL_T_WHERE },
  { SL("DELETE"),			   PHQL_T_DELETE },
  { SL("FROM"),				   PHQL_T_FROM },
  { SL("AS"),				   PHQL_T_AS },
  { SL("INSERT"),			   PHQL_T_INSERT },
  { SL("INTO"),				   PHQL_T_INTO },
  { SL("VALUES"),			   PHQL_T_VALUES },
  { SL("SELECT"),			   PHQL_T_SELECT },
  { SL("ORDER"),			   PHQL_T_ORDER },
  { SL("BY"),			       PHQL_T_BY },
  { SL("LIMIT"),		       PHQL_T_LIMIT },
  { SL("OFFSET"),		       PHQL_T_OFFSET },
  { SL("GROUP"),		       PHQL_T_GROUP },
  { SL("HAVING"),		       PHQL_T_HAVING },
  { SL("IN"),			       PHQL_T_IN },
  { SL("ON"),			       PHQL_T_ON },
  { SL("INNER"),		       PHQL_T_INNER },
  { SL("JOIN"),		           PHQL_T_JOIN },
  { SL("LEFT"),		           PHQL_T_LEFT },
  { SL("RIGHT"),		       PHQL_T_RIGHT },
  { SL("IS"),			       PHQL_T_IS },
  { SL("NULL"),		           PHQL_T_NULL },
  { SL("NOT IN"),		       PHQL_T_NOTIN },
  { SL("CROSS"),		       PHQL_T_CROSS },
  { SL("OUTER"),		       PHQL_T_OUTER },
  { SL("FULL"),		           PHQL_T_FULL },
  { SL("ASC"),		           PHQL_T_ASC },
  { SL("DESC"),		           PHQL_T_DESC },
  { SL("BETWEEN"),	           PHQL_T_BETWEEN },
  { SL("DISTINCT"),	           PHQL_T_DISTINCT },
  { SL("AGAINST"),	           PHQL_T_AGAINST },
  { SL("CAST"),		           PHQL_T_CAST },
  { SL("CONVERT"),	           PHQL_T_CONVERT },
  { SL("USING"),		       PHQL_T_USING },
  { SL("ALL"),		           PHQL_T_ALL },
  { SL("EXISTS"),		       PHQL_T_EXISTS },
  { SL("CASE"),		           PHQL_T_CASE },
  { SL("WHEN"),		           PHQL_T_WHEN },
  { SL("THEN"),		           PHQL_T_THEN },
  { SL("ELSE"),		           PHQL_T_ELSE },
  { SL("END"),		           PHQL_T_END },
  { SL("FOR"),		           PHQL_T_FOR },
  { SL("WITH"),		           PHQL_T_WITH },
  { NULL, 0, 0 }
};

static void *phql_wrapper_alloc(size_t bytes)
{
	return emalloc(bytes);
}

static void phql_wrapper_free(void *pointer)
{
	efree(pointer);
}

static void phql_parse_with_token(void* phql_parser, int opcode, int parsercode, phql_scanner_token *token, phql_parser_status *parser_status)
{

	phql_parser_token *pToken;

	pToken = emalloc(sizeof(phql_parser_token));
	pToken->opcode = opcode;
	pToken->token = token->value;
	pToken->token_len = token->len;
	pToken->free_flag = 1;
	phql_(phql_parser, parsercode, pToken, parser_status);

	token->value = NULL;
	token->len = 0;
}

/**
 * Creates an error message when it's triggered by the scanner
 */
static void phql_scanner_error_msg(phql_parser_status *parser_status, zval **error_msg TSRMLS_DC)
{

	char *error = NULL, *error_part;
	unsigned int length;
	phql_scanner_state *state = parser_status->scanner_state;

#if PHP_VERSION_ID < 70000
	MAKE_STD_ZVAL(*error_msg);
#else
    ZVAL_UNDEF(*error_msg);
#endif

	if (state->start) {
		length = 64 + state->start_length + parser_status->phql_length;
		error = emalloc(sizeof(char) * length);
		if (state->start_length > 16) {
			error_part = estrndup(state->start, 16);
			snprintf(error, length, "Scanning error before '%s...' when parsing: %s (%d)", error_part, parser_status->phql, parser_status->phql_length);
			efree(error_part);
		} else {
			snprintf(error, length, "Scanning error before '%s' when parsing: %s (%d)", state->start, parser_status->phql, parser_status->phql_length);
		}
		error[length - 1] = '\0';
#if PHP_VERSION_ID < 70000
		ZVAL_STRING(*error_msg, error, 1);
#else
        ZVAL_STRING(*error_msg, error);
#endif
	} else {
#if PHP_VERSION_ID < 70000
		ZVAL_STRING(*error_msg, "Scanning error near to EOF", 1);
#else
		ZVAL_STRING(*error_msg, "Scanning error near to EOF");
#endif
	}

	if (error) {
		efree(error);
	}
}

/**
 * Executes the internal PHQL parser/tokenizer
 */
int phql_parse_phql(zval *result, zval *phql TSRMLS_DC)
{
#if PHP_VERSION_ID < 70000
	zval *error_msg = NULL;
#else
    zval err_msg, *error_msg = &err_msg;
    ZVAL_UNDEF(error_msg);
#endif

	ZVAL_NULL(result);

	if (phql_internal_parse_phql(&result, Z_STRVAL_P(phql), Z_STRLEN_P(phql), &error_msg TSRMLS_CC) == FAILURE) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg));
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Executes a PHQL parser/tokenizer
 */
int phql_internal_parse_phql(zval **result, char *phql, unsigned int phql_length, zval **error_msg TSRMLS_DC)
{
	zend_phalcon_globals *phalcon_globals_ptr = ZEPHIR_VGLOBAL;
	phql_parser_status *parser_status = NULL;
	int scanner_status, status = SUCCESS, error_length, cache_level;
	phql_scanner_state *state;
	phql_scanner_token token;
	void* phql_parser;
	char *error;
    unsigned long phql_key = 0;
#if PHP_VERSION_ID < 70000
	zval **temp_ast;
#else
    zval *temp_ast;
#endif

	if (!phql) {
#if PHP_VERSION_ID < 70000
		MAKE_STD_ZVAL(*error_msg);
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL", 1);
#else
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL");
#endif
		return FAILURE;
	}

	cache_level = phalcon_globals_ptr->orm.cache_level;
	if (cache_level >= 0) {
		phql_key = zend_inline_hash_func(phql, phql_length + 1);
		if (phalcon_globals_ptr->orm.parser_cache != NULL) {
#if PHP_VERSION_ID < 70000
			if (zend_hash_index_find(phalcon_globals_ptr->orm.parser_cache, phql_key, (void**) &temp_ast) == SUCCESS) {
				ZVAL_ZVAL(*result, *temp_ast, 1, 0);
				Z_SET_REFCOUNT_P(*result, 1);
				return SUCCESS;
			}
#else
            if ((temp_ast = zend_hash_index_find(phalcon_globals_ptr->orm.parser_cache, phql_key)) != NULL) {
                ZVAL_ZVAL(*result, temp_ast, 1, 0);
                Z_TRY_ADDREF_P(*result);
                return SUCCESS;
            }
#endif
		}
	}

	phql_parser = phql_Alloc(phql_wrapper_alloc);

	parser_status = emalloc(sizeof(phql_parser_status));
	state = emalloc(sizeof(phql_scanner_state));

	parser_status->status = PHQL_PARSING_OK;
	parser_status->scanner_state = state;
#if PHP_VERSION_ID < 70000
	parser_status->ret = NULL;
#else
    ZVAL_UNDEF(&parser_status->ret);
#endif
	parser_status->syntax_error = NULL;
	parser_status->token = &token;
	parser_status->enable_literals = phalcon_globals_ptr->orm.enable_literals;
	parser_status->phql = phql;
	parser_status->phql_length = phql_length;

	state->active_token = 0;
	state->start = phql;
	state->start_length = 0;
	state->end = state->start;

	token.value = NULL;
	token.len = 0;

	while (0 <= (scanner_status = phql_get_token(state, &token))) {

		/* Calculate the 'start' length */
		state->start_length = (phql + phql_length - state->start);

		state->active_token = token.opcode;

		/* Parse the token found */
		switch (token.opcode) {

			case PHQL_T_IGNORE:
				break;

			case PHQL_T_ADD:
				phql_(phql_parser, PHQL_PLUS, NULL, parser_status);
				break;
			case PHQL_T_SUB:
				phql_(phql_parser, PHQL_MINUS, NULL, parser_status);
				break;
			case PHQL_T_MUL:
				phql_(phql_parser, PHQL_TIMES, NULL, parser_status);
				break;
			case PHQL_T_DIV:
				phql_(phql_parser, PHQL_DIVIDE, NULL, parser_status);
				break;
			case PHQL_T_MOD:
				phql_(phql_parser, PHQL_MOD, NULL, parser_status);
				break;
			case PHQL_T_AND:
				phql_(phql_parser, PHQL_AND, NULL, parser_status);
				break;
			case PHQL_T_OR:
				phql_(phql_parser, PHQL_OR, NULL, parser_status);
				break;
			case PHQL_T_EQUALS:
				phql_(phql_parser, PHQL_EQUALS, NULL, parser_status);
				break;
			case PHQL_T_NOTEQUALS:
				phql_(phql_parser, PHQL_NOTEQUALS, NULL, parser_status);
				break;
			case PHQL_T_LESS:
				phql_(phql_parser, PHQL_LESS, NULL, parser_status);
				break;
			case PHQL_T_GREATER:
				phql_(phql_parser, PHQL_GREATER, NULL, parser_status);
				break;
			case PHQL_T_GREATEREQUAL:
				phql_(phql_parser, PHQL_GREATEREQUAL, NULL, parser_status);
				break;
			case PHQL_T_LESSEQUAL:
				phql_(phql_parser, PHQL_LESSEQUAL, NULL, parser_status);
				break;

			case PHQL_T_IDENTIFIER:
				phql_parse_with_token(phql_parser, PHQL_T_IDENTIFIER, PHQL_IDENTIFIER, &token, parser_status);
				break;

			case PHQL_T_DOT:
				phql_(phql_parser, PHQL_DOT, NULL, parser_status);
				break;
			case PHQL_T_COMMA:
				phql_(phql_parser, PHQL_COMMA, NULL, parser_status);
				break;

			case PHQL_T_PARENTHESES_OPEN:
				phql_(phql_parser, PHQL_PARENTHESES_OPEN, NULL, parser_status);
				break;
			case PHQL_T_PARENTHESES_CLOSE:
				phql_(phql_parser, PHQL_PARENTHESES_CLOSE, NULL, parser_status);
				break;

			case PHQL_T_LIKE:
				phql_(phql_parser, PHQL_LIKE, NULL, parser_status);
				break;
			case PHQL_T_ILIKE:
				phql_(phql_parser, PHQL_ILIKE, NULL, parser_status);
				break;
			case PHQL_T_NOT:
				phql_(phql_parser, PHQL_NOT, NULL, parser_status);
				break;
			case PHQL_T_BITWISE_AND:
				phql_(phql_parser, PHQL_BITWISE_AND, NULL, parser_status);
				break;
			case PHQL_T_BITWISE_OR:
				phql_(phql_parser, PHQL_BITWISE_OR, NULL, parser_status);
				break;
			case PHQL_T_BITWISE_NOT:
				phql_(phql_parser, PHQL_BITWISE_NOT, NULL, parser_status);
				break;
			case PHQL_T_BITWISE_XOR:
				phql_(phql_parser, PHQL_BITWISE_XOR, NULL, parser_status);
				break;
			case PHQL_T_AGAINST:
				phql_(phql_parser, PHQL_AGAINST, NULL, parser_status);
				break;
			case PHQL_T_CASE:
				phql_(phql_parser, PHQL_CASE, NULL, parser_status);
				break;
			case PHQL_T_WHEN:
				phql_(phql_parser, PHQL_WHEN, NULL, parser_status);
				break;
			case PHQL_T_THEN:
				phql_(phql_parser, PHQL_THEN, NULL, parser_status);
				break;
			case PHQL_T_END:
				phql_(phql_parser, PHQL_END, NULL, parser_status);
				break;
			case PHQL_T_ELSE:
				phql_(phql_parser, PHQL_ELSE, NULL, parser_status);
				break;
			case PHQL_T_FOR:
				phql_(phql_parser, PHQL_FOR, NULL, parser_status);
				break;
            case PHQL_T_WITH:
    			phql_(phql_parser, PHQL_WITH, NULL, parser_status);
    			break;

			case PHQL_T_INTEGER:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_INTEGER, PHQL_INTEGER, &token, parser_status);
				} else {
#if PHP_VERSION_ID < 70000
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
#else
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
#endif
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_DOUBLE:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_DOUBLE, PHQL_DOUBLE, &token, parser_status);
				} else {
#if PHP_VERSION_ID < 70000
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
#else
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
#endif
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_STRING:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_STRING, PHQL_STRING, &token, parser_status);
				} else {
#if PHP_VERSION_ID < 70000
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
#else
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
#endif
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_TRUE:
				if (parser_status->enable_literals) {
					phql_(phql_parser, PHQL_TRUE, NULL, parser_status);
				} else {
#if PHP_VERSION_ID < 70000
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
#else
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
#endif
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_FALSE:
				if (parser_status->enable_literals) {
					phql_(phql_parser, PHQL_FALSE, NULL, parser_status);
				} else {
#if PHP_VERSION_ID < 70000
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
#else
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
#endif
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_HINTEGER:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_HINTEGER, PHQL_HINTEGER, &token, parser_status);
				} else {
#if PHP_VERSION_ID < 70000
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
#else
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
#endif
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;

			case PHQL_T_NPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_NPLACEHOLDER, PHQL_NPLACEHOLDER, &token, parser_status);
				break;
			case PHQL_T_SPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_SPLACEHOLDER, PHQL_SPLACEHOLDER, &token, parser_status);
				break;
			case PHQL_T_BPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_BPLACEHOLDER, PHQL_BPLACEHOLDER, &token, parser_status);
				break;

			case PHQL_T_FROM:
				phql_(phql_parser, PHQL_FROM, NULL, parser_status);
				break;
			case PHQL_T_UPDATE:
				phql_(phql_parser, PHQL_UPDATE, NULL, parser_status);
				break;
			case PHQL_T_SET:
				phql_(phql_parser, PHQL_SET, NULL, parser_status);
				break;
			case PHQL_T_WHERE:
				phql_(phql_parser, PHQL_WHERE, NULL, parser_status);
				break;
			case PHQL_T_DELETE:
				phql_(phql_parser, PHQL_DELETE, NULL, parser_status);
				break;
			case PHQL_T_INSERT:
				phql_(phql_parser, PHQL_INSERT, NULL, parser_status);
				break;
			case PHQL_T_INTO:
				phql_(phql_parser, PHQL_INTO, NULL, parser_status);
				break;
			case PHQL_T_VALUES:
				phql_(phql_parser, PHQL_VALUES, NULL, parser_status);
				break;
			case PHQL_T_SELECT:
				phql_(phql_parser, PHQL_SELECT, NULL, parser_status);
				break;
			case PHQL_T_AS:
				phql_(phql_parser, PHQL_AS, NULL, parser_status);
				break;
			case PHQL_T_ORDER:
				phql_(phql_parser, PHQL_ORDER, NULL, parser_status);
				break;
			case PHQL_T_BY:
				phql_(phql_parser, PHQL_BY, NULL, parser_status);
				break;
			case PHQL_T_LIMIT:
				phql_(phql_parser, PHQL_LIMIT, NULL, parser_status);
				break;
			case PHQL_T_OFFSET:
				phql_(phql_parser, PHQL_OFFSET, NULL, parser_status);
				break;
			case PHQL_T_GROUP:
				phql_(phql_parser, PHQL_GROUP, NULL, parser_status);
				break;
			case PHQL_T_HAVING:
				phql_(phql_parser, PHQL_HAVING, NULL, parser_status);
				break;
			case PHQL_T_ASC:
				phql_(phql_parser, PHQL_ASC, NULL, parser_status);
				break;
			case PHQL_T_DESC:
				phql_(phql_parser, PHQL_DESC, NULL, parser_status);
				break;
			case PHQL_T_IN:
				phql_(phql_parser, PHQL_IN, NULL, parser_status);
				break;
			case PHQL_T_ON:
				phql_(phql_parser, PHQL_ON, NULL, parser_status);
				break;
			case PHQL_T_INNER:
				phql_(phql_parser, PHQL_INNER, NULL, parser_status);
				break;
			case PHQL_T_JOIN:
				phql_(phql_parser, PHQL_JOIN, NULL, parser_status);
				break;
			case PHQL_T_LEFT:
				phql_(phql_parser, PHQL_LEFT, NULL, parser_status);
				break;
			case PHQL_T_RIGHT:
				phql_(phql_parser, PHQL_RIGHT, NULL, parser_status);
				break;
			case PHQL_T_CROSS:
				phql_(phql_parser, PHQL_CROSS, NULL, parser_status);
				break;
			case PHQL_T_FULL:
				phql_(phql_parser, PHQL_FULL, NULL, parser_status);
				break;
			case PHQL_T_OUTER:
				phql_(phql_parser, PHQL_OUTER, NULL, parser_status);
				break;
			case PHQL_T_IS:
				phql_(phql_parser, PHQL_IS, NULL, parser_status);
				break;
			case PHQL_T_NULL:
				phql_(phql_parser, PHQL_NULL, NULL, parser_status);
				break;
			case PHQL_T_BETWEEN:
				phql_(phql_parser, PHQL_BETWEEN, NULL, parser_status);
				break;
			case PHQL_T_DISTINCT:
				phql_(phql_parser, PHQL_DISTINCT, NULL, parser_status);
				break;
			case PHQL_T_ALL:
				phql_(phql_parser, PHQL_ALL, NULL, parser_status);
				break;
			case PHQL_T_CAST:
				phql_(phql_parser, PHQL_CAST, NULL, parser_status);
				break;
			case PHQL_T_CONVERT:
				phql_(phql_parser, PHQL_CONVERT, NULL, parser_status);
				break;
			case PHQL_T_USING:
				phql_(phql_parser, PHQL_USING, NULL, parser_status);
				break;
			case PHQL_T_EXISTS:
				phql_(phql_parser, PHQL_EXISTS, NULL, parser_status);
				break;

			default:
				parser_status->status = PHQL_PARSING_FAILED;
				error_length = sizeof(char) * 32;
				error = emalloc(error_length);
				snprintf(error, error_length, "Scanner: Unknown opcode %d", token.opcode);
				error[error_length - 1] = '\0';
#if PHP_VERSION_ID < 70000
				MAKE_STD_ZVAL(*error_msg);
				ZVAL_STRING(*error_msg, error, 1);
#else
                ZVAL_STRING(*error_msg, error);
#endif
				efree(error);
				break;
		}

		if (parser_status->status != PHQL_PARSING_OK) {
			status = FAILURE;
			break;
		}

		state->end = state->start;
	}

	if (status != FAILURE) {
		switch (scanner_status) {

			case PHQL_SCANNER_RETCODE_ERR:
			case PHQL_SCANNER_RETCODE_IMPOSSIBLE:
#if PHP_VERSION_ID < 70000
				if (!*error_msg) {
					phql_scanner_error_msg(parser_status, error_msg TSRMLS_CC);
				}
#else
                if (Z_TYPE_P(*error_msg) == IS_UNDEF) {
                    phql_scanner_error_msg(parser_status, error_msg TSRMLS_CC);
                }
#endif
				status = FAILURE;
				break;

			default:
				phql_(phql_parser, 0, NULL, parser_status);
		}
	}

	state->active_token = 0;
	state->start = NULL;

	if (parser_status->status != PHQL_PARSING_OK) {
		status = FAILURE;
		if (parser_status->syntax_error) {
#if PHP_VERSION_ID < 70000
            if (!*error_msg) {
				MAKE_STD_ZVAL(*error_msg);
				ZVAL_STRING(*error_msg, parser_status->syntax_error, 1);
            }
#else
            if (Z_TYPE_P(*error_msg) == IS_UNDEF) {
                ZVAL_STRING(*error_msg, parser_status->syntax_error);
            }
#endif
			efree(parser_status->syntax_error);
		}
	}

	phql_Free(phql_parser, phql_wrapper_free);

	if (status != FAILURE) {
		if (parser_status->status == PHQL_PARSING_OK) {
#if PHP_VERSION_ID < 70000
			if (parser_status->ret) {
#else
			if (Z_TYPE_P(&parser_status->ret) == IS_ARRAY) {
#endif

				/**
				 * Set a unique id for the parsed ast
				 */
				if (phalcon_globals_ptr->orm.cache_level >= 1) {
#if PHP_VERSION_ID < 70000
					if (Z_TYPE_P(parser_status->ret) == IS_ARRAY) {
						add_assoc_long(parser_status->ret, "id", phalcon_globals_ptr->orm.unique_cache_id++);
					}
#else
                    if (Z_TYPE_P(&parser_status->ret) == IS_ARRAY) {
                        add_assoc_long(&parser_status->ret, "id", phalcon_globals_ptr->orm.unique_cache_id++);
                    }
#endif
				}

#if PHP_VERSION_ID < 70000
                ZVAL_ZVAL(*result, parser_status->ret, 0, 0);
                ZVAL_NULL(parser_status->ret);
				zval_ptr_dtor(&parser_status->ret);
#else
                ZVAL_ZVAL(*result, &parser_status->ret, 1, 1);
#endif

				/**
				 * Store the parsed definition in the cache
				 */
				if (cache_level >= 0) {

                    if (!phalcon_globals_ptr->orm.parser_cache) {
                        ALLOC_HASHTABLE(phalcon_globals_ptr->orm.parser_cache);
                        zend_hash_init(phalcon_globals_ptr->orm.parser_cache, 0, NULL, ZVAL_PTR_DTOR, 0);
                    }

#if PHP_VERSION_ID < 70000

					Z_ADDREF_PP(result);

					zend_hash_index_update(
						phalcon_globals_ptr->orm.parser_cache,
						phql_key,
						result,
						sizeof(zval *),
						NULL
					);
#else
                    Z_TRY_ADDREF_P(*result);

                    zend_hash_index_update(
                        phalcon_globals_ptr->orm.parser_cache,
                        phql_key,
                        *result
                    );
#endif
				}

			} else {
#if PHP_VERSION_ID < 70000
				efree(parser_status->ret);
#endif
			}
		}
	}

	efree(parser_status);
	efree(state);

	return status;
}
