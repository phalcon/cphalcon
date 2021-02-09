#include "php_phalcon.h"
/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 30 "parser.php7.lemon"

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
#define PPNOCODE 135
#define PPACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE pp0;
  zval pp202;
  int pp269;
} PPMINORTYPE;
#define PPSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = pppParser->status
#define phql_ARG_STORE pppParser->status = status
#define PPNSTATE 295
#define PPNRULE 162
#define PPERRORSYMBOL 80
#define PPERRSYMDT pp269
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
static PPCODETYPE pp_lookahead[] = {
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
#define PP_SHIFT_USE_DFLT (-14)
static short pp_shift_ofst[] = {
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
#define PP_REDUCE_USE_DFLT (-33)
static short pp_reduce_ofst[] = {
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
static PPACTIONTYPE pp_default[] = {
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
    case 79:
// 101 "parser.php7.lemon"
{
	if ((pppminor->pp0)) {
		if ((pppminor->pp0)->free_flag) {
			efree((pppminor->pp0)->token);
		}
		efree((pppminor->pp0));
	}
}
// 826 "parser.php7.c"
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
// 114 "parser.php7.lemon"
{
	zval_ptr_dtor(&(pppminor->pp202));
}
// 866 "parser.php7.c"
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
// 496 "parser.php7.lemon"
{
	zephir_safe_zval_ptr_dtor((pppminor->pp202));
}
// 883 "parser.php7.c"
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
// 110 "parser.php7.lemon"
{
	ZVAL_ZVAL(&status->ret, &ppmsp[0].minor.pp202, 1, 1);
}
// 1262 "parser.php7.c"
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
// 118 "parser.php7.lemon"
{
	ppgotominor.pp202 = ppmsp[0].minor.pp202;
}
// 1288 "parser.php7.c"
        break;
      case 5:
// 138 "parser.php7.lemon"
{
	phql_ret_select_statement(&ppgotominor.pp202, &ppmsp[-6].minor.pp202, &ppmsp[-5].minor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[-4].minor.pp202, &ppmsp[-3].minor.pp202, &ppmsp[-1].minor.pp202, &ppmsp[0].minor.pp202);
}
// 1295 "parser.php7.c"
        break;
      case 6:
// 146 "parser.php7.lemon"
{
	phql_ret_select_clause(&ppgotominor.pp202, &ppmsp[-4].minor.pp202, &ppmsp[-3].minor.pp202, &ppmsp[-1].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(27,&ppmsp[-5].minor);
  pp_destructor(28,&ppmsp[-2].minor);
}
// 1304 "parser.php7.c"
        break;
      case 7:
// 154 "parser.php7.lemon"
{
	phql_ret_distinct_all(&ppgotominor.pp202, 1);
  pp_destructor(29,&ppmsp[0].minor);
}
// 1312 "parser.php7.c"
        break;
      case 8:
// 158 "parser.php7.lemon"
{
	phql_ret_distinct_all(&ppgotominor.pp202, 0);
  pp_destructor(30,&ppmsp[0].minor);
}
// 1320 "parser.php7.c"
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
// 162 "parser.php7.lemon"
{
	ZVAL_UNDEF(&ppgotominor.pp202);
}
// 1339 "parser.php7.c"
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
// 170 "parser.php7.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(26,&ppmsp[-1].minor);
}
// 1355 "parser.php7.c"
        break;
      case 11:
      case 42:
      case 45:
      case 129:
      case 139:
// 174 "parser.php7.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp202, &ppmsp[0].minor.pp202, NULL);
}
// 1366 "parser.php7.c"
        break;
      case 12:
      case 140:
// 182 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp202, PHQL_T_STARALL, NULL, NULL, NULL);
  pp_destructor(18,&ppmsp[0].minor);
}
// 1375 "parser.php7.c"
        break;
      case 13:
// 186 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp202, PHQL_T_DOMAINALL, NULL, ppmsp[-2].minor.pp0, NULL);
  pp_destructor(32,&ppmsp[-1].minor);
  pp_destructor(18,&ppmsp[0].minor);
}
// 1384 "parser.php7.c"
        break;
      case 14:
// 190 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp202, PHQL_T_EXPR, &ppmsp[-2].minor.pp202, NULL, ppmsp[0].minor.pp0);
  pp_destructor(33,&ppmsp[-1].minor);
}
// 1392 "parser.php7.c"
        break;
      case 15:
// 194 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp202, PHQL_T_EXPR, &ppmsp[-1].minor.pp202, NULL, ppmsp[0].minor.pp0);
}
// 1399 "parser.php7.c"
        break;
      case 16:
// 198 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp202, PHQL_T_EXPR, &ppmsp[0].minor.pp202, NULL, NULL);
}
// 1406 "parser.php7.c"
        break;
      case 21:
      case 128:
// 226 "parser.php7.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp202, &ppmsp[-1].minor.pp202, &ppmsp[0].minor.pp202);
}
// 1414 "parser.php7.c"
        break;
      case 24:
// 247 "parser.php7.lemon"
{
	phql_ret_join_item(&ppgotominor.pp202, &ppmsp[-3].minor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[-1].minor.pp202, &ppmsp[0].minor.pp202);
}
// 1421 "parser.php7.c"
        break;
      case 25:
// 255 "parser.php7.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp202, NULL, NULL, ppmsp[0].minor.pp0);
  pp_destructor(33,&ppmsp[-1].minor);
}
// 1429 "parser.php7.c"
        break;
      case 26:
      case 46:
      case 66:
      case 161:
// 259 "parser.php7.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp202, NULL, NULL, ppmsp[0].minor.pp0);
}
// 1439 "parser.php7.c"
        break;
      case 28:
// 271 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_INNERJOIN);
  pp_destructor(34,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1448 "parser.php7.c"
        break;
      case 29:
// 275 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_CROSSJOIN);
  pp_destructor(36,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1457 "parser.php7.c"
        break;
      case 30:
// 279 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_LEFTJOIN);
  pp_destructor(37,&ppmsp[-2].minor);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1467 "parser.php7.c"
        break;
      case 31:
// 283 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_LEFTJOIN);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1476 "parser.php7.c"
        break;
      case 32:
// 287 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_RIGHTJOIN);
  pp_destructor(39,&ppmsp[-2].minor);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1486 "parser.php7.c"
        break;
      case 33:
// 291 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_RIGHTJOIN);
  pp_destructor(39,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1495 "parser.php7.c"
        break;
      case 34:
// 295 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_FULLJOIN);
  pp_destructor(40,&ppmsp[-2].minor);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1505 "parser.php7.c"
        break;
      case 35:
// 299 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_FULLJOIN);
  pp_destructor(40,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1514 "parser.php7.c"
        break;
      case 36:
// 303 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_INNERJOIN);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1522 "parser.php7.c"
        break;
      case 37:
// 311 "parser.php7.lemon"
{
	ppgotominor.pp202 = ppmsp[0].minor.pp202;
  pp_destructor(41,&ppmsp[-1].minor);
}
// 1530 "parser.php7.c"
        break;
      case 39:
// 324 "parser.php7.lemon"
{
	phql_ret_insert_statement(&ppgotominor.pp202, &ppmsp[-4].minor.pp202, NULL, &ppmsp[-1].minor.pp202);
  pp_destructor(42,&ppmsp[-6].minor);
  pp_destructor(43,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1542 "parser.php7.c"
        break;
      case 40:
// 328 "parser.php7.lemon"
{
	phql_ret_insert_statement(&ppgotominor.pp202, &ppmsp[-7].minor.pp202, &ppmsp[-5].minor.pp202, &ppmsp[-1].minor.pp202);
  pp_destructor(42,&ppmsp[-9].minor);
  pp_destructor(43,&ppmsp[-8].minor);
  pp_destructor(45,&ppmsp[-6].minor);
  pp_destructor(46,&ppmsp[-4].minor);
  pp_destructor(44,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1556 "parser.php7.c"
        break;
      case 47:
// 374 "parser.php7.lemon"
{
	phql_ret_update_statement(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[-1].minor.pp202, &ppmsp[0].minor.pp202);
}
// 1563 "parser.php7.c"
        break;
      case 48:
// 382 "parser.php7.lemon"
{
	phql_ret_update_clause(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(47,&ppmsp[-3].minor);
  pp_destructor(48,&ppmsp[-1].minor);
}
// 1572 "parser.php7.c"
        break;
      case 51:
// 402 "parser.php7.lemon"
{
	phql_ret_update_item(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 1580 "parser.php7.c"
        break;
      case 53:
// 416 "parser.php7.lemon"
{
	phql_ret_delete_statement(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[-1].minor.pp202, &ppmsp[0].minor.pp202);
}
// 1587 "parser.php7.c"
        break;
      case 54:
// 424 "parser.php7.lemon"
{
	phql_ret_delete_clause(&ppgotominor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(49,&ppmsp[-2].minor);
  pp_destructor(28,&ppmsp[-1].minor);
}
// 1596 "parser.php7.c"
        break;
      case 55:
// 432 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, ppmsp[0].minor.pp0, NULL);
  pp_destructor(33,&ppmsp[-1].minor);
}
// 1604 "parser.php7.c"
        break;
      case 56:
// 436 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-1].minor.pp202, ppmsp[0].minor.pp0, NULL);
}
// 1611 "parser.php7.c"
        break;
      case 57:
// 440 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[0].minor.pp202, NULL, NULL);
}
// 1618 "parser.php7.c"
        break;
      case 58:
// 444 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-4].minor.pp202, ppmsp[-2].minor.pp0, &ppmsp[0].minor.pp202);
  pp_destructor(33,&ppmsp[-3].minor);
  pp_destructor(50,&ppmsp[-1].minor);
}
// 1627 "parser.php7.c"
        break;
      case 59:
// 448 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-6].minor.pp202, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp202);
  pp_destructor(33,&ppmsp[-5].minor);
  pp_destructor(50,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1638 "parser.php7.c"
        break;
      case 60:
// 452 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-5].minor.pp202, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp202);
  pp_destructor(50,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1648 "parser.php7.c"
        break;
      case 61:
// 456 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-3].minor.pp202, ppmsp[-2].minor.pp0, &ppmsp[0].minor.pp202);
  pp_destructor(50,&ppmsp[-1].minor);
}
// 1656 "parser.php7.c"
        break;
      case 62:
// 460 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-4].minor.pp202, NULL, &ppmsp[-1].minor.pp202);
  pp_destructor(50,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1666 "parser.php7.c"
        break;
      case 63:
// 464 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, NULL, &ppmsp[0].minor.pp202);
  pp_destructor(50,&ppmsp[-1].minor);
}
// 1674 "parser.php7.c"
        break;
      case 68:
// 500 "parser.php7.lemon"
{
	ppgotominor.pp202 = ppmsp[0].minor.pp202;
  pp_destructor(51,&ppmsp[-1].minor);
}
// 1682 "parser.php7.c"
        break;
      case 70:
// 512 "parser.php7.lemon"
{
	ppgotominor.pp202 = ppmsp[0].minor.pp202;
  pp_destructor(52,&ppmsp[-2].minor);
  pp_destructor(53,&ppmsp[-1].minor);
}
// 1691 "parser.php7.c"
        break;
      case 74:
// 536 "parser.php7.lemon"
{
	phql_ret_order_item(&ppgotominor.pp202, &ppmsp[0].minor.pp202, 0);
}
// 1698 "parser.php7.c"
        break;
      case 75:
// 540 "parser.php7.lemon"
{
	phql_ret_order_item(&ppgotominor.pp202, &ppmsp[-1].minor.pp202, PHQL_T_ASC);
  pp_destructor(54,&ppmsp[0].minor);
}
// 1706 "parser.php7.c"
        break;
      case 76:
// 544 "parser.php7.lemon"
{
	phql_ret_order_item(&ppgotominor.pp202, &ppmsp[-1].minor.pp202, PHQL_T_DESC);
  pp_destructor(55,&ppmsp[0].minor);
}
// 1714 "parser.php7.c"
        break;
      case 77:
// 552 "parser.php7.lemon"
{
	ppgotominor.pp202 = ppmsp[0].minor.pp202;
  pp_destructor(56,&ppmsp[-2].minor);
  pp_destructor(53,&ppmsp[-1].minor);
}
// 1723 "parser.php7.c"
        break;
      case 82:
// 584 "parser.php7.lemon"
{
	ppgotominor.pp202 = ppmsp[0].minor.pp202;
  pp_destructor(57,&ppmsp[-1].minor);
}
// 1731 "parser.php7.c"
        break;
      case 84:
// 596 "parser.php7.lemon"
{
	phql_ret_for_update_clause(&ppgotominor.pp202);
  pp_destructor(58,&ppmsp[-1].minor);
  pp_destructor(47,&ppmsp[0].minor);
}
// 1740 "parser.php7.c"
        break;
      case 86:
      case 90:
// 608 "parser.php7.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp202, &ppmsp[0].minor.pp202, NULL);
  pp_destructor(59,&ppmsp[-1].minor);
}
// 1749 "parser.php7.c"
        break;
      case 87:
// 612 "parser.php7.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp202, &ppmsp[0].minor.pp202, &ppmsp[-2].minor.pp202);
  pp_destructor(59,&ppmsp[-3].minor);
  pp_destructor(26,&ppmsp[-1].minor);
}
// 1758 "parser.php7.c"
        break;
      case 88:
// 616 "parser.php7.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(59,&ppmsp[-3].minor);
  pp_destructor(60,&ppmsp[-1].minor);
}
// 1767 "parser.php7.c"
        break;
      case 92:
      case 150:
// 636 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp202, PHQL_T_INTEGER, ppmsp[0].minor.pp0);
}
// 1775 "parser.php7.c"
        break;
      case 93:
      case 151:
// 640 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp202, PHQL_T_HINTEGER, ppmsp[0].minor.pp0);
}
// 1783 "parser.php7.c"
        break;
      case 94:
      case 157:
// 644 "parser.php7.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp202, PHQL_T_NPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1791 "parser.php7.c"
        break;
      case 95:
      case 158:
// 648 "parser.php7.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp202, PHQL_T_SPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1799 "parser.php7.c"
        break;
      case 96:
      case 159:
// 652 "parser.php7.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp202, PHQL_T_BPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1807 "parser.php7.c"
        break;
      case 97:
// 660 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_MINUS, NULL, &ppmsp[0].minor.pp202);
  pp_destructor(21,&ppmsp[-1].minor);
}
// 1815 "parser.php7.c"
        break;
      case 98:
// 664 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_SUB, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(21,&ppmsp[-1].minor);
}
// 1823 "parser.php7.c"
        break;
      case 99:
// 668 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_ADD, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 1831 "parser.php7.c"
        break;
      case 100:
// 672 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_MUL, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(18,&ppmsp[-1].minor);
}
// 1839 "parser.php7.c"
        break;
      case 101:
// 676 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_DIV, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 1847 "parser.php7.c"
        break;
      case 102:
// 680 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_MOD, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(19,&ppmsp[-1].minor);
}
// 1855 "parser.php7.c"
        break;
      case 103:
// 684 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_AND, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(10,&ppmsp[-1].minor);
}
// 1863 "parser.php7.c"
        break;
      case 104:
// 688 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_OR, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 1871 "parser.php7.c"
        break;
      case 105:
// 692 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_BITWISE_AND, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(14,&ppmsp[-1].minor);
}
// 1879 "parser.php7.c"
        break;
      case 106:
// 696 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_BITWISE_OR, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(15,&ppmsp[-1].minor);
}
// 1887 "parser.php7.c"
        break;
      case 107:
// 700 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_BITWISE_XOR, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 1895 "parser.php7.c"
        break;
      case 108:
// 704 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_EQUALS, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 1903 "parser.php7.c"
        break;
      case 109:
// 708 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_NOTEQUALS, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(5,&ppmsp[-1].minor);
}
// 1911 "parser.php7.c"
        break;
      case 110:
// 712 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_LESS, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(6,&ppmsp[-1].minor);
}
// 1919 "parser.php7.c"
        break;
      case 111:
// 716 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_GREATER, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(7,&ppmsp[-1].minor);
}
// 1927 "parser.php7.c"
        break;
      case 112:
// 720 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_GREATEREQUAL, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(8,&ppmsp[-1].minor);
}
// 1935 "parser.php7.c"
        break;
      case 113:
// 724 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_LESSEQUAL, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(9,&ppmsp[-1].minor);
}
// 1943 "parser.php7.c"
        break;
      case 114:
// 728 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_LIKE, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 1951 "parser.php7.c"
        break;
      case 115:
// 732 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_NLIKE, &ppmsp[-3].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(24,&ppmsp[-2].minor);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 1960 "parser.php7.c"
        break;
      case 116:
// 736 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_ILIKE, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 1968 "parser.php7.c"
        break;
      case 117:
// 740 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_NILIKE, &ppmsp[-3].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(24,&ppmsp[-2].minor);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 1977 "parser.php7.c"
        break;
      case 118:
      case 121:
// 744 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_IN, &ppmsp[-4].minor.pp202, &ppmsp[-1].minor.pp202);
  pp_destructor(23,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1988 "parser.php7.c"
        break;
      case 119:
      case 122:
// 748 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_NOTIN, &ppmsp[-5].minor.pp202, &ppmsp[-1].minor.pp202);
  pp_destructor(24,&ppmsp[-4].minor);
  pp_destructor(23,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2000 "parser.php7.c"
        break;
      case 120:
// 752 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_SUBQUERY, &ppmsp[-1].minor.pp202, NULL);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2009 "parser.php7.c"
        break;
      case 123:
// 764 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_EXISTS, NULL, &ppmsp[-1].minor.pp202);
  pp_destructor(66,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2019 "parser.php7.c"
        break;
      case 124:
// 768 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_AGAINST, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(1,&ppmsp[-1].minor);
}
// 2027 "parser.php7.c"
        break;
      case 125:
// 772 "parser.php7.lemon"
{
	{
		zval qualified;
		phql_ret_raw_qualified_name(&qualified, ppmsp[-1].minor.pp0, NULL);
		phql_ret_expr(&ppgotominor.pp202, PHQL_T_CAST, &ppmsp[-3].minor.pp202, &qualified);
	}
  pp_destructor(67,&ppmsp[-5].minor);
  pp_destructor(45,&ppmsp[-4].minor);
  pp_destructor(33,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2042 "parser.php7.c"
        break;
      case 126:
// 780 "parser.php7.lemon"
{
	{
		zval qualified;
		phql_ret_raw_qualified_name(&qualified, ppmsp[-1].minor.pp0, NULL);
		phql_ret_expr(&ppgotominor.pp202, PHQL_T_CONVERT, &ppmsp[-3].minor.pp202, &qualified);
	}
  pp_destructor(68,&ppmsp[-5].minor);
  pp_destructor(45,&ppmsp[-4].minor);
  pp_destructor(69,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2057 "parser.php7.c"
        break;
      case 127:
// 788 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_CASE, &ppmsp[-2].minor.pp202, &ppmsp[-1].minor.pp202);
  pp_destructor(70,&ppmsp[-3].minor);
  pp_destructor(71,&ppmsp[0].minor);
}
// 2066 "parser.php7.c"
        break;
      case 130:
// 800 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_WHEN, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(72,&ppmsp[-3].minor);
  pp_destructor(73,&ppmsp[-1].minor);
}
// 2075 "parser.php7.c"
        break;
      case 131:
// 804 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_ELSE, &ppmsp[0].minor.pp202, NULL);
  pp_destructor(74,&ppmsp[-1].minor);
}
// 2083 "parser.php7.c"
        break;
      case 133:
// 816 "parser.php7.lemon"
{
	phql_ret_func_call(&ppgotominor.pp202, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp202, &ppmsp[-2].minor.pp202);
  pp_destructor(45,&ppmsp[-3].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2092 "parser.php7.c"
        break;
      case 134:
// 824 "parser.php7.lemon"
{
	phql_ret_distinct(&ppgotominor.pp202);
  pp_destructor(29,&ppmsp[0].minor);
}
// 2100 "parser.php7.c"
        break;
      case 142:
// 868 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_ISNULL, &ppmsp[-2].minor.pp202, NULL);
  pp_destructor(22,&ppmsp[-1].minor);
  pp_destructor(75,&ppmsp[0].minor);
}
// 2109 "parser.php7.c"
        break;
      case 143:
// 872 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_ISNOTNULL, &ppmsp[-3].minor.pp202, NULL);
  pp_destructor(22,&ppmsp[-2].minor);
  pp_destructor(24,&ppmsp[-1].minor);
  pp_destructor(75,&ppmsp[0].minor);
}
// 2119 "parser.php7.c"
        break;
      case 144:
// 876 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_BETWEEN, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(2,&ppmsp[-1].minor);
}
// 2127 "parser.php7.c"
        break;
      case 145:
// 880 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_BETWEEN_NOT, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 2135 "parser.php7.c"
        break;
      case 146:
// 884 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_NOT, NULL, &ppmsp[0].minor.pp202);
  pp_destructor(24,&ppmsp[-1].minor);
}
// 2143 "parser.php7.c"
        break;
      case 147:
// 888 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_BITWISE_NOT, NULL, &ppmsp[0].minor.pp202);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 2151 "parser.php7.c"
        break;
      case 148:
// 892 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_ENCLOSED, &ppmsp[-1].minor.pp202, NULL);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2160 "parser.php7.c"
        break;
      case 152:
// 908 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp202, PHQL_T_STRING, ppmsp[0].minor.pp0);
}
// 2167 "parser.php7.c"
        break;
      case 153:
// 912 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp202, PHQL_T_DOUBLE, ppmsp[0].minor.pp0);
}
// 2174 "parser.php7.c"
        break;
      case 154:
// 916 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp202, PHQL_T_NULL, NULL);
  pp_destructor(75,&ppmsp[0].minor);
}
// 2182 "parser.php7.c"
        break;
      case 155:
// 920 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp202, PHQL_T_TRUE, NULL);
  pp_destructor(78,&ppmsp[0].minor);
}
// 2190 "parser.php7.c"
        break;
      case 156:
// 924 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp202, PHQL_T_FALSE, NULL);
  pp_destructor(79,&ppmsp[0].minor);
}
// 2198 "parser.php7.c"
        break;
      case 160:
// 947 "parser.php7.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp202, NULL, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 2206 "parser.php7.c"
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
// 34 "parser.php7.lemon"

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

// 2315 "parser.php7.c"
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
/* base.c
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
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
static void phql_scanner_error_msg(phql_parser_status *parser_status, zval **error_msg)
{

	char *error = NULL, *error_part;
	unsigned int length;
	phql_scanner_state *state = parser_status->scanner_state;

	ZVAL_UNDEF(*error_msg);

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
		ZVAL_STRING(*error_msg, error);
	} else {
		ZVAL_STRING(*error_msg, "Scanning error near to EOF");
	}

	if (error) {
		efree(error);
	}
}

/**
 * Executes the internal PHQL parser/tokenizer
 */
int phql_parse_phql(zval *result, zval *phql)
{
	zval err_msg, *error_msg = &err_msg;
	ZVAL_UNDEF(error_msg);
	ZVAL_NULL(result);

	if (phql_internal_parse_phql(&result, Z_STRVAL_P(phql), Z_STRLEN_P(phql), &error_msg) == FAILURE) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg));
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Executes a PHQL parser/tokenizer
 */
int phql_internal_parse_phql(zval **result, char *phql, unsigned int phql_length, zval **error_msg)
{
	zend_phalcon_globals *phalcon_globals_ptr = ZEPHIR_VGLOBAL;
	phql_parser_status *parser_status = NULL;
	int scanner_status, status = SUCCESS, error_length, cache_level;
	phql_scanner_state *state;
	phql_scanner_token token;
	void* phql_parser;
	char *error;
	unsigned long phql_key = 0;
	zval *temp_ast;

	if (!phql) {
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL");
		return FAILURE;
	}

	cache_level = phalcon_globals_ptr->orm.cache_level;
	if (cache_level >= 0) {
		phql_key = zend_inline_hash_func(phql, phql_length + 1);
		if (phalcon_globals_ptr->orm.parser_cache != NULL) {
			if ((temp_ast = zend_hash_index_find(phalcon_globals_ptr->orm.parser_cache, phql_key)) != NULL) {
				ZVAL_ZVAL(*result, temp_ast, 1, 0);
				Z_TRY_ADDREF_P(*result);
				return SUCCESS;
			}
		}
	}

	phql_parser = phql_Alloc(phql_wrapper_alloc);

	parser_status = emalloc(sizeof(phql_parser_status));
	state = emalloc(sizeof(phql_scanner_state));

	parser_status->status = PHQL_PARSING_OK;
	parser_status->scanner_state = state;
	ZVAL_UNDEF(&parser_status->ret);

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
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_DOUBLE:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_DOUBLE, PHQL_DOUBLE, &token, parser_status);
				} else {
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_STRING:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_STRING, PHQL_STRING, &token, parser_status);
				} else {
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_TRUE:
				if (parser_status->enable_literals) {
					phql_(phql_parser, PHQL_TRUE, NULL, parser_status);
				} else {
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_FALSE:
				if (parser_status->enable_literals) {
					phql_(phql_parser, PHQL_FALSE, NULL, parser_status);
				} else {
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_HINTEGER:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_HINTEGER, PHQL_HINTEGER, &token, parser_status);
				} else {
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
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
			case PHQL_T_BETWEEN_NOT:
				phql_(phql_parser, PHQL_BETWEEN_NOT, NULL, parser_status);
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
				ZVAL_STRING(*error_msg, error);
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
				if (Z_TYPE_P(*error_msg) == IS_UNDEF) {
					phql_scanner_error_msg(parser_status, error_msg);
				}

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
			if (Z_TYPE_P(*error_msg) == IS_UNDEF) {
				ZVAL_STRING(*error_msg, parser_status->syntax_error);
			}

			efree(parser_status->syntax_error);
		}
	}

	phql_Free(phql_parser, phql_wrapper_free);

	if (status != FAILURE) {
		if (parser_status->status == PHQL_PARSING_OK) {
			if (Z_TYPE_P(&parser_status->ret) == IS_ARRAY) {

				/**
				 * Set a unique id for the parsed ast
				 */
				if (phalcon_globals_ptr->orm.cache_level >= 1) {
					if (Z_TYPE_P(&parser_status->ret) == IS_ARRAY) {
						add_assoc_long(&parser_status->ret, "id", phalcon_globals_ptr->orm.unique_cache_id++);
					}
				}

				ZVAL_ZVAL(*result, &parser_status->ret, 1, 1);

				/**
				 * Store the parsed definition in the cache
				 */
				if (cache_level >= 0) {

					if (!phalcon_globals_ptr->orm.parser_cache) {
						ALLOC_HASHTABLE(phalcon_globals_ptr->orm.parser_cache);
						zend_hash_init(phalcon_globals_ptr->orm.parser_cache, 0, NULL, ZVAL_PTR_DTOR, 0);
					}

					Z_TRY_ADDREF_P(*result);

					zend_hash_index_update(
						phalcon_globals_ptr->orm.parser_cache,
						phql_key,
						*result
					);
				}

			}
		}
	}

	efree(parser_status);
	efree(state);

	return status;
}
