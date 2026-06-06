#include "php_phalcon.h"
/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 30 "parser.php.lemon"

#include "parser.php.inc.h"

// 12 "parser.php.c"
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
#define PPNSTATE 296
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
 /*   300 */   170,  130,  296,   35,   84,   92,  171,  173,  297,  194,
 /*   310 */   210,  196,  198,  161,  202,  206,  107,  176,  177,  183,
 /*   320 */   184,  185,  135,  139,  145,  100,  151,  130,  433,  124,
 /*   330 */    17,  180,  178,  179,  181,  182,  298,  228,  236,  224,
 /*   340 */   225,    6,    6,  176,  177,  183,  184,  185,  135,  139,
 /*   350 */   145,  115,  151,  164,  164,   70,  230,  180,  178,  179,
 /*   360 */   181,  182,  215,  107,   24,   35,  232,  201,  171,  173,
 /*   370 */   199,  175,  175,   95,  104,  216,   94,   96,   76,   85,
 /*   380 */   123,  226,  234,   92,  160,  160,  119,  186,  186,  130,
 /*   390 */    98,   35,  299,  251,  171,  173,  102,   76,  278,  205,
 /*   400 */   293,  161,  203,   91,  175,  176,  177,  183,  184,  185,
 /*   410 */   135,  139,  145,  300,  151,  130,   82,  160,  240,  180,
 /*   420 */   178,  179,  181,  182,  194,  210,  196,  198,    9,  202,
 /*   430 */   206,  176,  177,  183,  184,  185,  135,  139,  145,   10,
 /*   440 */   151,   94,  282,  289,  285,  180,  178,  179,  181,  182,
 /*   450 */   170,  153,  190,   35,   31,  103,  171,  173,   26,  194,
 /*   460 */   210,  196,  198,  161,  202,  206,  137,  193,   92,  191,
 /*   470 */     6,  133,  175,  316,   15,    6,   11,  130,   30,   35,
 /*   480 */    13,  209,  171,  173,  207,  160,  121,  131,  105,  161,
 /*   490 */   284,  285,  168,  176,  177,  183,  184,  185,  135,  139,
 /*   500 */   145,  109,  151,  130,  175,  175,   14,  180,  178,  179,
 /*   510 */   181,  182,  432,  387,  162,   16,  218,  160,  160,  176,
 /*   520 */   177,  183,  184,  185,  135,  139,  145,   12,  151,  110,
 /*   530 */   254,  262,  168,  180,  178,  179,  181,  182,   67,   72,
 /*   540 */    49,   51,   53,   41,   39,   43,   37,   34,  122,   74,
 /*   550 */    69,  279,  227,  164,  217,   18,   84,  258,  253,  459,
 /*   560 */     1,    2,    3,    4,    5,    6,   25,  162,  107,  280,
 /*   570 */   107,  175,  276,  111,  211,  113,  114,  257,   29,   69,
 /*   580 */    75,  167,   31,  247,  160,   78,  165,  186,  223,  219,
 /*   590 */    80,  273,   27,  108,  212,   77,   86,  290,  164,   84,
 /*   600 */   175,  175,   88,  260,   87,   28,  239,  175,  244,  248,
 /*   610 */   260,  107,  256,  160,  160,  261,  175,  214,  219,  267,
 /*   620 */   160,  175,  261,   94,  247,   93,  260,  263,  175,  160,
 /*   630 */   272,   97,  169,  288,  160,  238,  175,  101,  259,  109,
 /*   640 */    36,  160,  175,   38,  175,   40,  110,   42,  168,  160,
 /*   650 */   246,  175,  287,  175,  118,  160,  116,  160,  175,   44,
 /*   660 */   106,  175,   46,  175,  160,  175,  160,  134,  235,   48,
 /*   670 */   125,  160,  269,   50,  160,  258,  160,  175,  160,  117,
 /*   680 */   175,   52,  136,   54,   56,   58,  138,  175,   60,   62,
 /*   690 */   160,  175,  264,  160,   76,  268,  140,  143,  144,  175,
 /*   700 */   160,  175,  175,  175,  160,   64,  175,  175,   66,   68,
 /*   710 */    71,   73,  160,  127,  160,  160,  160,  129,  146,  160,
 /*   720 */   160,  149,  150,  175,  187,  155,  175,  175,  175,  175,
 /*   730 */   163,  175,  141,  147,  152,  175,  160,  166,  157,  160,
 /*   740 */   160,  160,  160,  159,  160,  192,  195,  324,  160,  172,
 /*   750 */   175,  175,  175,  174,  197,  189,  175,  231,  241,  250,
 /*   760 */   325,  175,  200,  160,  160,  160,  326,  175,  327,  160,
 /*   770 */   328,  175,  329,  175,  160,  175,  175,  175,  295,  204,
 /*   780 */   160,  208,  330,   84,  160,  331,  160,  332,  160,  160,
 /*   790 */   160,  221,  245,  229,  233,  107,  237,  255,  243,  335,
 /*   800 */   252,  271,  265,  336,  266,  270,  274,  343,  275,  277,
 /*   810 */   386,  281,  283,  286,  291,  292,  349,  294,
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
 /*   350 */    68,  105,   70,   99,   99,   12,   13,   75,   76,   77,
 /*   360 */    78,   79,   18,  117,   60,   21,   23,   35,   24,   25,
 /*   370 */    38,  117,  117,  120,  121,   31,   31,   31,   27,   33,
 /*   380 */    75,  127,  127,   26,  130,  130,   99,  133,  133,   45,
 /*   390 */    45,   21,    0,   42,   24,   25,   50,   27,   47,   35,
 /*   400 */    49,   31,   38,   46,  117,   61,   62,   63,   64,   65,
 /*   410 */    66,   67,   68,    0,   70,   45,   26,  130,   57,   75,
 /*   420 */    76,   77,   78,   79,   34,   35,   36,   37,   90,   39,
 /*   430 */    40,   61,   62,   63,   64,   65,   66,   67,   68,   91,
 /*   440 */    70,   31,  115,  116,  117,   75,   76,   77,   78,   79,
 /*   450 */    18,  128,  129,   21,   99,   45,   24,   25,   52,   34,
 /*   460 */    35,   36,   37,   31,   39,   40,   83,   31,   26,   33,
 /*   470 */    87,   83,  117,   48,   59,   87,   92,   45,  123,   21,
 /*   480 */    58,   35,   24,   25,   38,  130,   99,   99,   46,   31,
 /*   490 */   116,  117,   26,   61,   62,   63,   64,   65,   66,   67,
 /*   500 */    68,   32,   70,   45,  117,  117,   47,   75,   76,   77,
 /*   510 */    78,   79,   46,    0,   45,  126,   18,  130,  130,   61,
 /*   520 */    62,   63,   64,   65,   66,   67,   68,   93,   70,   31,
 /*   530 */    44,   45,   26,   75,   76,   77,   78,   79,   12,   13,
 /*   540 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   550 */    24,  100,   46,   99,   32,  126,  105,   26,  105,   81,
 /*   560 */    82,   83,   84,   85,   86,   87,  126,   45,  117,   97,
 /*   570 */   117,  117,   59,  101,  102,  103,  104,   46,   26,   24,
 /*   580 */    45,  127,   99,   99,  130,   95,  132,  133,   98,   99,
 /*   590 */    96,  113,   53,   31,  100,   94,   31,  119,   99,  105,
 /*   600 */   117,  117,  120,   99,   50,  122,  123,  117,  124,  125,
 /*   610 */    99,  117,  108,  130,  130,  111,  117,   98,   99,  108,
 /*   620 */   130,  117,  111,   31,   99,  120,   99,  109,  117,  130,
 /*   630 */   112,   50,  133,   99,  130,   99,  117,  120,  111,   32,
 /*   640 */    99,  130,  117,   99,  117,   99,   31,   99,   26,  130,
 /*   650 */   125,  117,  118,  117,   41,  130,  106,  130,  117,   99,
 /*   660 */   120,  117,   99,  117,  130,  117,  130,   46,   46,   99,
 /*   670 */    75,  130,   26,   99,  130,   26,  130,  117,  130,  107,
 /*   680 */   117,   99,   45,   99,   99,   99,   46,  117,   99,   99,
 /*   690 */   130,  117,   46,  130,   27,   46,   45,   31,   46,  117,
 /*   700 */   130,  117,  117,  117,  130,   99,  117,  117,   99,   99,
 /*   710 */    99,   99,  130,   99,  130,  130,  130,   99,   45,  130,
 /*   720 */   130,   31,   46,  117,   29,  129,  117,  117,  117,  117,
 /*   730 */   131,  117,   99,   99,   99,  117,  130,   46,   99,  130,
 /*   740 */   130,  130,  130,   99,  130,   31,   35,   31,  130,   99,
 /*   750 */   117,  117,  117,   99,   35,   99,  117,   99,   99,   99,
 /*   760 */    31,  117,   35,  130,  130,  130,   31,  117,   31,  130,
 /*   770 */    31,  117,   31,  117,  130,  117,  117,  117,  100,   35,
 /*   780 */   130,   35,   31,  105,  130,   31,  130,   31,  130,  130,
 /*   790 */   130,   31,   26,   46,   45,  117,   46,   45,   53,    0,
 /*   800 */    43,   31,   44,    0,   45,  112,   88,    0,  114,  126,
 /*   810 */     0,   48,   26,    4,   88,  114,    0,   28,
};
#define PP_SHIFT_USE_DFLT (-14)
static short pp_shift_ofst[] = {
 /*     0 */   351,  302,  308,  336,  392,  413,   94,  219,  361,  406,
 /*    10 */   415,  422,  -14,  459,  -14,  -13,  304,  -13,  -14,  -14,
 /*    20 */   -14,  -14,  -14,  -14,  -13,  -14,  539,  458,  552,  458,
 /*    30 */   -14,   -1,  -14,  -14,  458,  458,  221,  458,  221,  458,
 /*    40 */    59,  458,   59,  458,   59,  458,  526,  458,  526,  458,
 /*    50 */   153,  458,  153,  458,  153,  458,  218,  458,  218,  458,
 /*    60 */   218,  458,  218,  458,  218,  458,  218,  458,  274,  343,
 /*    70 */   458,  555,  458,  274,  535,  256,  310,  344,   68,  562,
 /*    80 */   390,  -14,  562,  -14,  346,  565,  554,   53,  -14,  592,
 /*    90 */   357,  -14,  592,  -14,  -14,  -14,  581,  345,  592,  279,
 /*   100 */   -14,  -14,  410,  592,  442,  -14,  -14,  -14,  607,  615,
 /*   110 */   -14,  275,  -14,  -14,  562,  436,  613,  -14,  458,  249,
 /*   120 */   458,  249,  305,  -14,  595,  -14,  458,  119,  458,  119,
 /*   130 */   370,   98,  -14,  621,  -14,  637,  667,  640,  -14,  651,
 /*   140 */   458,  145,  666,  652,  -14,  673,  458,  179,  690,  676,
 /*   150 */   -14,  458,   23,  175,  -14,  -14,  458,  203,  458,  249,
 /*   160 */   -14,  469,  695,  282,  249,  691,  -14,  466,  432,  -14,
 /*   170 */   -14,  458,  555,  458,  555,  -14,  -14,  -14,  -14,  -14,
 /*   180 */   -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  458,  249,
 /*   190 */   -14,  714,  -14,  -14,  711,  716,  719,  729,  332,  727,
 /*   200 */   735,  737,  364,  744,  739,  741,  446,  746,  751,  754,
 /*   210 */   756,  -14,  -14,  344,  -14,  -14,  522,  498,  -14,   54,
 /*   220 */   760,  -14,  -14,  -14,  -14,  -14,  506,  -14,  747,  -14,
 /*   230 */   458,  555,  749,  256,  622,  -14,  750,  -14,  221,  -14,
 /*   240 */   458,  249,  745,  458,  766,  458,  -14,  249,  -14,  458,
 /*   250 */   249,  757,  562,  486,  752,  458,  531,  799,  458,  -14,
 /*   260 */   249,  -14,  770,  646,  758,  759,  458,  649,  803,  770,
 /*   270 */   -14,  -14,  -14,   94,  513,  807,  -13,  810,  562,  425,
 /*   280 */   763,  562,  786,  562,  -14,  809,  458,  -14,  249,  -14,
 /*   290 */    94,  513,  816,  789,  562,  -14,
};
#define PP_REDUCE_USE_DFLT (-33)
static short pp_reduce_ofst[] = {
 /*     0 */   478,  -33,  -33,  -33,  -33,  -33,   91,  193,  338,  348,
 /*    10 */   384,  434,  -33,  -33,  -33,  389,  -33,  429,  -33,  -33,
 /*    20 */   -33,  -33,  -33,  -33,  440,  -33,  -33,  483,  -33,  355,
 /*    30 */   -33,  -33,  -33,  -33,  536,  541,  -33,  544,  -33,  546,
 /*    40 */   -33,  548,  -33,  560,  -33,  563,  -33,  570,  -33,  574,
 /*    50 */   -33,  582,  -33,  584,  -33,  585,  -33,  586,  -33,  589,
 /*    60 */   -33,  590,  -33,  606,  -33,  609,  -33,  610,  -33,  -33,
 /*    70 */   611,  -33,  612,  -33,  -33,  254,  501,  490,  -33,  494,
 /*    80 */   -11,  -33,  199,  -33,  -33,  -33,  -33,  482,  -33,  -32,
 /*    90 */   -33,  -33,  505,  -33,  -33,  -33,  -33,  517,  158,  -33,
 /*   100 */   -33,  -33,  540,  253,  -33,  -33,  -33,  -33,  -33,  -33,
 /*   110 */   -33,  182,  -33,  -33,  246,  550,  572,  -33,  287,  -33,
 /*   120 */   387,  -33,  -33,  -33,  -33,  -33,  614,  -33,  618,  -33,
 /*   130 */   388,  -33,  -33,  -33,  -33,  -33,  383,  -33,  -33,  -33,
 /*   140 */   633,  -33,  -33,  -33,  -33,  -33,  634,  -33,  -33,  -33,
 /*   150 */   -33,  635,  323,  596,  -33,  -33,  639,  -33,  644,  -33,
 /*   160 */   -33,  -33,  599,  454,  -33,  -33,  -33,  -33,  499,  -33,
 /*   170 */   -33,  650,  -33,  654,  -33,  -33,  -33,  -33,  -33,  -33,
 /*   180 */   -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  656,  -33,
 /*   190 */   -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
 /*   200 */   -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
 /*   210 */   -33,  -33,  -33,  519,  -33,  -33,  -33,  -33,  -33,  -33,
 /*   220 */   -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
 /*   230 */   658,  -33,  -33,  255,  -33,  -33,  -33,  -33,  -33,  -33,
 /*   240 */   659,  -33,  -33,  484,  -33,  525,  -33,  -33,  -33,  660,
 /*   250 */   -33,  -33,  453,  -33,  -33,  504,  -33,  -33,  527,  -33,
 /*   260 */   -33,  -33,  518,  -33,  -33,  -33,  511,  -33,  -33,  693,
 /*   270 */   -33,  -33,  -33,  718,  694,  -33,  683,  -33,  451,  472,
 /*   280 */   -33,  327,  -33,  374,  -33,  -33,  534,  -33,  -33,  -33,
 /*   290 */   726,  701,  -33,  -33,  678,  -33,
};
static PPACTIONTYPE pp_default[] = {
 /*     0 */   458,  458,  458,  458,  458,  458,  365,  374,  379,  367,
 /*    10 */   385,  381,  301,  458,  380,  458,  382,  458,  383,  388,
 /*    20 */   389,  390,  391,  392,  458,  384,  458,  458,  366,  458,
 /*    30 */   368,  370,  371,  372,  458,  458,  393,  458,  395,  458,
 /*    40 */   396,  458,  397,  458,  398,  458,  399,  458,  400,  458,
 /*    50 */   401,  458,  402,  458,  403,  458,  404,  458,  405,  458,
 /*    60 */   406,  458,  407,  458,  408,  458,  409,  458,  410,  458,
 /*    70 */   458,  411,  458,  412,  458,  458,  305,  458,  458,  458,
 /*    80 */   316,  302,  458,  313,  353,  458,  351,  458,  354,  458,
 /*    90 */   458,  355,  458,  360,  362,  361,  352,  458,  458,  458,
 /*   100 */   356,  357,  458,  458,  458,  358,  359,  363,  457,  458,
 /*   110 */   456,  315,  317,  319,  458,  323,  334,  320,  458,  333,
 /*   120 */   458,  420,  458,  438,  458,  439,  458,  440,  458,  441,
 /*   130 */   458,  458,  444,  458,  416,  458,  458,  458,  419,  458,
 /*   140 */   458,  458,  458,  458,  421,  458,  458,  458,  458,  458,
 /*   150 */   422,  458,  458,  458,  423,  424,  458,  458,  458,  426,
 /*   160 */   428,  457,  431,  458,  437,  458,  429,  458,  458,  434,
 /*   170 */   436,  458,  442,  458,  443,  445,  446,  447,  448,  449,
 /*   180 */   450,  451,  452,  453,  454,  455,  435,  430,  458,  427,
 /*   190 */   425,  458,  321,  322,  458,  458,  458,  458,  458,  458,
 /*   200 */   458,  458,  458,  458,  458,  458,  458,  458,  458,  458,
 /*   210 */   458,  318,  314,  458,  306,  308,  457,  458,  309,  312,
 /*   220 */   458,  310,  311,  307,  303,  304,  458,  414,  458,  417,
 /*   230 */   458,  413,  458,  458,  458,  415,  458,  418,  394,  369,
 /*   240 */   458,  378,  458,  458,  373,  458,  375,  377,  376,  458,
 /*   250 */   364,  458,  458,  458,  458,  458,  458,  458,  458,  337,
 /*   260 */   339,  338,  458,  458,  458,  458,  458,  458,  458,  458,
 /*   270 */   340,  342,  341,  365,  458,  458,  458,  458,  458,  458,
 /*   280 */   458,  458,  344,  458,  345,  458,  458,  347,  348,  346,
 /*   290 */   365,  458,  458,  458,  458,  350,
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
 /*  48 */ "update_clause ::= UPDATE associated_name join_list_or_null SET update_item_list",
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
// 101 "parser.php.lemon"
{
	if ((pppminor->pp0)) {
		if ((pppminor->pp0)->free_flag) {
			efree((pppminor->pp0)->token);
		}
		efree((pppminor->pp0));
	}
}
// 828 "parser.php.c"
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
// 114 "parser.php.lemon"
{
	zval_ptr_dtor(&(pppminor->pp202));
}
// 868 "parser.php.c"
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
// 496 "parser.php.lemon"
{
	zephir_safe_zval_ptr_dtor((pppminor->pp202));
}
// 885 "parser.php.c"
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
  { 113, 5 },
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
// 110 "parser.php.lemon"
{
	ZVAL_ZVAL(&status->ret, &ppmsp[0].minor.pp202, 1, 1);
}
// 1264 "parser.php.c"
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
// 118 "parser.php.lemon"
{
	ppgotominor.pp202 = ppmsp[0].minor.pp202;
}
// 1290 "parser.php.c"
        break;
      case 5:
// 138 "parser.php.lemon"
{
	phql_ret_select_statement(&ppgotominor.pp202, &ppmsp[-6].minor.pp202, &ppmsp[-5].minor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[-4].minor.pp202, &ppmsp[-3].minor.pp202, &ppmsp[-1].minor.pp202, &ppmsp[0].minor.pp202);
}
// 1297 "parser.php.c"
        break;
      case 6:
// 146 "parser.php.lemon"
{
	phql_ret_select_clause(&ppgotominor.pp202, &ppmsp[-4].minor.pp202, &ppmsp[-3].minor.pp202, &ppmsp[-1].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(27,&ppmsp[-5].minor);
  pp_destructor(28,&ppmsp[-2].minor);
}
// 1306 "parser.php.c"
        break;
      case 7:
// 154 "parser.php.lemon"
{
	phql_ret_distinct_all(&ppgotominor.pp202, 1);
  pp_destructor(29,&ppmsp[0].minor);
}
// 1314 "parser.php.c"
        break;
      case 8:
// 158 "parser.php.lemon"
{
	phql_ret_distinct_all(&ppgotominor.pp202, 0);
  pp_destructor(30,&ppmsp[0].minor);
}
// 1322 "parser.php.c"
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
// 162 "parser.php.lemon"
{
	ZVAL_UNDEF(&ppgotominor.pp202);
}
// 1341 "parser.php.c"
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
// 170 "parser.php.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(26,&ppmsp[-1].minor);
}
// 1357 "parser.php.c"
        break;
      case 11:
      case 42:
      case 45:
      case 129:
      case 139:
// 174 "parser.php.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp202, &ppmsp[0].minor.pp202, NULL);
}
// 1368 "parser.php.c"
        break;
      case 12:
      case 140:
// 182 "parser.php.lemon"
{
	phql_ret_column_item(&ppgotominor.pp202, PHQL_T_STARALL, NULL, NULL, NULL);
  pp_destructor(18,&ppmsp[0].minor);
}
// 1377 "parser.php.c"
        break;
      case 13:
// 186 "parser.php.lemon"
{
	phql_ret_column_item(&ppgotominor.pp202, PHQL_T_DOMAINALL, NULL, ppmsp[-2].minor.pp0, NULL);
  pp_destructor(32,&ppmsp[-1].minor);
  pp_destructor(18,&ppmsp[0].minor);
}
// 1386 "parser.php.c"
        break;
      case 14:
// 190 "parser.php.lemon"
{
	phql_ret_column_item(&ppgotominor.pp202, PHQL_T_EXPR, &ppmsp[-2].minor.pp202, NULL, ppmsp[0].minor.pp0);
  pp_destructor(33,&ppmsp[-1].minor);
}
// 1394 "parser.php.c"
        break;
      case 15:
// 194 "parser.php.lemon"
{
	phql_ret_column_item(&ppgotominor.pp202, PHQL_T_EXPR, &ppmsp[-1].minor.pp202, NULL, ppmsp[0].minor.pp0);
}
// 1401 "parser.php.c"
        break;
      case 16:
// 198 "parser.php.lemon"
{
	phql_ret_column_item(&ppgotominor.pp202, PHQL_T_EXPR, &ppmsp[0].minor.pp202, NULL, NULL);
}
// 1408 "parser.php.c"
        break;
      case 21:
      case 128:
// 226 "parser.php.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp202, &ppmsp[-1].minor.pp202, &ppmsp[0].minor.pp202);
}
// 1416 "parser.php.c"
        break;
      case 24:
// 247 "parser.php.lemon"
{
	phql_ret_join_item(&ppgotominor.pp202, &ppmsp[-3].minor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[-1].minor.pp202, &ppmsp[0].minor.pp202);
}
// 1423 "parser.php.c"
        break;
      case 25:
// 255 "parser.php.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp202, NULL, NULL, ppmsp[0].minor.pp0);
  pp_destructor(33,&ppmsp[-1].minor);
}
// 1431 "parser.php.c"
        break;
      case 26:
      case 46:
      case 66:
      case 161:
// 259 "parser.php.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp202, NULL, NULL, ppmsp[0].minor.pp0);
}
// 1441 "parser.php.c"
        break;
      case 28:
// 271 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_INNERJOIN);
  pp_destructor(34,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1450 "parser.php.c"
        break;
      case 29:
// 275 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_CROSSJOIN);
  pp_destructor(36,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1459 "parser.php.c"
        break;
      case 30:
// 279 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_LEFTJOIN);
  pp_destructor(37,&ppmsp[-2].minor);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1469 "parser.php.c"
        break;
      case 31:
// 283 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_LEFTJOIN);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1478 "parser.php.c"
        break;
      case 32:
// 287 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_RIGHTJOIN);
  pp_destructor(39,&ppmsp[-2].minor);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1488 "parser.php.c"
        break;
      case 33:
// 291 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_RIGHTJOIN);
  pp_destructor(39,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1497 "parser.php.c"
        break;
      case 34:
// 295 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_FULLJOIN);
  pp_destructor(40,&ppmsp[-2].minor);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1507 "parser.php.c"
        break;
      case 35:
// 299 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_FULLJOIN);
  pp_destructor(40,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1516 "parser.php.c"
        break;
      case 36:
// 303 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp202, PHQL_T_INNERJOIN);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1524 "parser.php.c"
        break;
      case 37:
// 311 "parser.php.lemon"
{
	ppgotominor.pp202 = ppmsp[0].minor.pp202;
  pp_destructor(41,&ppmsp[-1].minor);
}
// 1532 "parser.php.c"
        break;
      case 39:
// 324 "parser.php.lemon"
{
	phql_ret_insert_statement(&ppgotominor.pp202, &ppmsp[-4].minor.pp202, NULL, &ppmsp[-1].minor.pp202);
  pp_destructor(42,&ppmsp[-6].minor);
  pp_destructor(43,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1544 "parser.php.c"
        break;
      case 40:
// 328 "parser.php.lemon"
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
// 1558 "parser.php.c"
        break;
      case 47:
// 374 "parser.php.lemon"
{
	phql_ret_update_statement(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[-1].minor.pp202, &ppmsp[0].minor.pp202);
}
// 1565 "parser.php.c"
        break;
      case 48:
// 382 "parser.php.lemon"
{
	phql_ret_update_clause(&ppgotominor.pp202, &ppmsp[-3].minor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(47,&ppmsp[-4].minor);
  pp_destructor(48,&ppmsp[-1].minor);
}
// 1574 "parser.php.c"
        break;
      case 51:
// 402 "parser.php.lemon"
{
	phql_ret_update_item(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 1582 "parser.php.c"
        break;
      case 53:
// 416 "parser.php.lemon"
{
	phql_ret_delete_statement(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[-1].minor.pp202, &ppmsp[0].minor.pp202);
}
// 1589 "parser.php.c"
        break;
      case 54:
// 424 "parser.php.lemon"
{
	phql_ret_delete_clause(&ppgotominor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(49,&ppmsp[-2].minor);
  pp_destructor(28,&ppmsp[-1].minor);
}
// 1598 "parser.php.c"
        break;
      case 55:
// 432 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, ppmsp[0].minor.pp0, NULL);
  pp_destructor(33,&ppmsp[-1].minor);
}
// 1606 "parser.php.c"
        break;
      case 56:
// 436 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-1].minor.pp202, ppmsp[0].minor.pp0, NULL);
}
// 1613 "parser.php.c"
        break;
      case 57:
// 440 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[0].minor.pp202, NULL, NULL);
}
// 1620 "parser.php.c"
        break;
      case 58:
// 444 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-4].minor.pp202, ppmsp[-2].minor.pp0, &ppmsp[0].minor.pp202);
  pp_destructor(33,&ppmsp[-3].minor);
  pp_destructor(50,&ppmsp[-1].minor);
}
// 1629 "parser.php.c"
        break;
      case 59:
// 448 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-6].minor.pp202, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp202);
  pp_destructor(33,&ppmsp[-5].minor);
  pp_destructor(50,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1640 "parser.php.c"
        break;
      case 60:
// 452 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-5].minor.pp202, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp202);
  pp_destructor(50,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1650 "parser.php.c"
        break;
      case 61:
// 456 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-3].minor.pp202, ppmsp[-2].minor.pp0, &ppmsp[0].minor.pp202);
  pp_destructor(50,&ppmsp[-1].minor);
}
// 1658 "parser.php.c"
        break;
      case 62:
// 460 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-4].minor.pp202, NULL, &ppmsp[-1].minor.pp202);
  pp_destructor(50,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1668 "parser.php.c"
        break;
      case 63:
// 464 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, NULL, &ppmsp[0].minor.pp202);
  pp_destructor(50,&ppmsp[-1].minor);
}
// 1676 "parser.php.c"
        break;
      case 68:
// 500 "parser.php.lemon"
{
	ppgotominor.pp202 = ppmsp[0].minor.pp202;
  pp_destructor(51,&ppmsp[-1].minor);
}
// 1684 "parser.php.c"
        break;
      case 70:
// 512 "parser.php.lemon"
{
	ppgotominor.pp202 = ppmsp[0].minor.pp202;
  pp_destructor(52,&ppmsp[-2].minor);
  pp_destructor(53,&ppmsp[-1].minor);
}
// 1693 "parser.php.c"
        break;
      case 74:
// 536 "parser.php.lemon"
{
	phql_ret_order_item(&ppgotominor.pp202, &ppmsp[0].minor.pp202, 0);
}
// 1700 "parser.php.c"
        break;
      case 75:
// 540 "parser.php.lemon"
{
	phql_ret_order_item(&ppgotominor.pp202, &ppmsp[-1].minor.pp202, PHQL_T_ASC);
  pp_destructor(54,&ppmsp[0].minor);
}
// 1708 "parser.php.c"
        break;
      case 76:
// 544 "parser.php.lemon"
{
	phql_ret_order_item(&ppgotominor.pp202, &ppmsp[-1].minor.pp202, PHQL_T_DESC);
  pp_destructor(55,&ppmsp[0].minor);
}
// 1716 "parser.php.c"
        break;
      case 77:
// 552 "parser.php.lemon"
{
	ppgotominor.pp202 = ppmsp[0].minor.pp202;
  pp_destructor(56,&ppmsp[-2].minor);
  pp_destructor(53,&ppmsp[-1].minor);
}
// 1725 "parser.php.c"
        break;
      case 82:
// 584 "parser.php.lemon"
{
	ppgotominor.pp202 = ppmsp[0].minor.pp202;
  pp_destructor(57,&ppmsp[-1].minor);
}
// 1733 "parser.php.c"
        break;
      case 84:
// 596 "parser.php.lemon"
{
	phql_ret_for_update_clause(&ppgotominor.pp202);
  pp_destructor(58,&ppmsp[-1].minor);
  pp_destructor(47,&ppmsp[0].minor);
}
// 1742 "parser.php.c"
        break;
      case 86:
      case 90:
// 608 "parser.php.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp202, &ppmsp[0].minor.pp202, NULL);
  pp_destructor(59,&ppmsp[-1].minor);
}
// 1751 "parser.php.c"
        break;
      case 87:
// 612 "parser.php.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp202, &ppmsp[0].minor.pp202, &ppmsp[-2].minor.pp202);
  pp_destructor(59,&ppmsp[-3].minor);
  pp_destructor(26,&ppmsp[-1].minor);
}
// 1760 "parser.php.c"
        break;
      case 88:
// 616 "parser.php.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp202, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(59,&ppmsp[-3].minor);
  pp_destructor(60,&ppmsp[-1].minor);
}
// 1769 "parser.php.c"
        break;
      case 92:
      case 150:
// 636 "parser.php.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp202, PHQL_T_INTEGER, ppmsp[0].minor.pp0);
}
// 1777 "parser.php.c"
        break;
      case 93:
      case 151:
// 640 "parser.php.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp202, PHQL_T_HINTEGER, ppmsp[0].minor.pp0);
}
// 1785 "parser.php.c"
        break;
      case 94:
      case 157:
// 644 "parser.php.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp202, PHQL_T_NPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1793 "parser.php.c"
        break;
      case 95:
      case 158:
// 648 "parser.php.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp202, PHQL_T_SPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1801 "parser.php.c"
        break;
      case 96:
      case 159:
// 652 "parser.php.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp202, PHQL_T_BPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1809 "parser.php.c"
        break;
      case 97:
// 660 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_MINUS, NULL, &ppmsp[0].minor.pp202);
  pp_destructor(21,&ppmsp[-1].minor);
}
// 1817 "parser.php.c"
        break;
      case 98:
// 664 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_SUB, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(21,&ppmsp[-1].minor);
}
// 1825 "parser.php.c"
        break;
      case 99:
// 668 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_ADD, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 1833 "parser.php.c"
        break;
      case 100:
// 672 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_MUL, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(18,&ppmsp[-1].minor);
}
// 1841 "parser.php.c"
        break;
      case 101:
// 676 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_DIV, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 1849 "parser.php.c"
        break;
      case 102:
// 680 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_MOD, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(19,&ppmsp[-1].minor);
}
// 1857 "parser.php.c"
        break;
      case 103:
// 684 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_AND, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(10,&ppmsp[-1].minor);
}
// 1865 "parser.php.c"
        break;
      case 104:
// 688 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_OR, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 1873 "parser.php.c"
        break;
      case 105:
// 692 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_BITWISE_AND, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(14,&ppmsp[-1].minor);
}
// 1881 "parser.php.c"
        break;
      case 106:
// 696 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_BITWISE_OR, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(15,&ppmsp[-1].minor);
}
// 1889 "parser.php.c"
        break;
      case 107:
// 700 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_BITWISE_XOR, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 1897 "parser.php.c"
        break;
      case 108:
// 704 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_EQUALS, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 1905 "parser.php.c"
        break;
      case 109:
// 708 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_NOTEQUALS, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(5,&ppmsp[-1].minor);
}
// 1913 "parser.php.c"
        break;
      case 110:
// 712 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_LESS, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(6,&ppmsp[-1].minor);
}
// 1921 "parser.php.c"
        break;
      case 111:
// 716 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_GREATER, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(7,&ppmsp[-1].minor);
}
// 1929 "parser.php.c"
        break;
      case 112:
// 720 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_GREATEREQUAL, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(8,&ppmsp[-1].minor);
}
// 1937 "parser.php.c"
        break;
      case 113:
// 724 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_LESSEQUAL, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(9,&ppmsp[-1].minor);
}
// 1945 "parser.php.c"
        break;
      case 114:
// 728 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_LIKE, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 1953 "parser.php.c"
        break;
      case 115:
// 732 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_NLIKE, &ppmsp[-3].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(24,&ppmsp[-2].minor);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 1962 "parser.php.c"
        break;
      case 116:
// 736 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_ILIKE, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 1970 "parser.php.c"
        break;
      case 117:
// 740 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_NILIKE, &ppmsp[-3].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(24,&ppmsp[-2].minor);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 1979 "parser.php.c"
        break;
      case 118:
      case 121:
// 744 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_IN, &ppmsp[-4].minor.pp202, &ppmsp[-1].minor.pp202);
  pp_destructor(23,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1990 "parser.php.c"
        break;
      case 119:
      case 122:
// 748 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_NOTIN, &ppmsp[-5].minor.pp202, &ppmsp[-1].minor.pp202);
  pp_destructor(24,&ppmsp[-4].minor);
  pp_destructor(23,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2002 "parser.php.c"
        break;
      case 120:
// 752 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_SUBQUERY, &ppmsp[-1].minor.pp202, NULL);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2011 "parser.php.c"
        break;
      case 123:
// 764 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_EXISTS, NULL, &ppmsp[-1].minor.pp202);
  pp_destructor(66,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2021 "parser.php.c"
        break;
      case 124:
// 768 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_AGAINST, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(1,&ppmsp[-1].minor);
}
// 2029 "parser.php.c"
        break;
      case 125:
// 772 "parser.php.lemon"
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
// 2044 "parser.php.c"
        break;
      case 126:
// 780 "parser.php.lemon"
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
// 2059 "parser.php.c"
        break;
      case 127:
// 788 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_CASE, &ppmsp[-2].minor.pp202, &ppmsp[-1].minor.pp202);
  pp_destructor(70,&ppmsp[-3].minor);
  pp_destructor(71,&ppmsp[0].minor);
}
// 2068 "parser.php.c"
        break;
      case 130:
// 800 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_WHEN, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(72,&ppmsp[-3].minor);
  pp_destructor(73,&ppmsp[-1].minor);
}
// 2077 "parser.php.c"
        break;
      case 131:
// 804 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_ELSE, &ppmsp[0].minor.pp202, NULL);
  pp_destructor(74,&ppmsp[-1].minor);
}
// 2085 "parser.php.c"
        break;
      case 133:
// 816 "parser.php.lemon"
{
	phql_ret_func_call(&ppgotominor.pp202, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp202, &ppmsp[-2].minor.pp202);
  pp_destructor(45,&ppmsp[-3].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2094 "parser.php.c"
        break;
      case 134:
// 824 "parser.php.lemon"
{
	phql_ret_distinct(&ppgotominor.pp202);
  pp_destructor(29,&ppmsp[0].minor);
}
// 2102 "parser.php.c"
        break;
      case 142:
// 868 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_ISNULL, &ppmsp[-2].minor.pp202, NULL);
  pp_destructor(22,&ppmsp[-1].minor);
  pp_destructor(75,&ppmsp[0].minor);
}
// 2111 "parser.php.c"
        break;
      case 143:
// 872 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_ISNOTNULL, &ppmsp[-3].minor.pp202, NULL);
  pp_destructor(22,&ppmsp[-2].minor);
  pp_destructor(24,&ppmsp[-1].minor);
  pp_destructor(75,&ppmsp[0].minor);
}
// 2121 "parser.php.c"
        break;
      case 144:
// 876 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_BETWEEN, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(2,&ppmsp[-1].minor);
}
// 2129 "parser.php.c"
        break;
      case 145:
// 880 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_BETWEEN_NOT, &ppmsp[-2].minor.pp202, &ppmsp[0].minor.pp202);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 2137 "parser.php.c"
        break;
      case 146:
// 884 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_NOT, NULL, &ppmsp[0].minor.pp202);
  pp_destructor(24,&ppmsp[-1].minor);
}
// 2145 "parser.php.c"
        break;
      case 147:
// 888 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_BITWISE_NOT, NULL, &ppmsp[0].minor.pp202);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 2153 "parser.php.c"
        break;
      case 148:
// 892 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp202, PHQL_T_ENCLOSED, &ppmsp[-1].minor.pp202, NULL);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2162 "parser.php.c"
        break;
      case 152:
// 908 "parser.php.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp202, PHQL_T_STRING, ppmsp[0].minor.pp0);
}
// 2169 "parser.php.c"
        break;
      case 153:
// 912 "parser.php.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp202, PHQL_T_DOUBLE, ppmsp[0].minor.pp0);
}
// 2176 "parser.php.c"
        break;
      case 154:
// 916 "parser.php.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp202, PHQL_T_NULL, NULL);
  pp_destructor(75,&ppmsp[0].minor);
}
// 2184 "parser.php.c"
        break;
      case 155:
// 920 "parser.php.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp202, PHQL_T_TRUE, NULL);
  pp_destructor(78,&ppmsp[0].minor);
}
// 2192 "parser.php.c"
        break;
      case 156:
// 924 "parser.php.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp202, PHQL_T_FALSE, NULL);
  pp_destructor(79,&ppmsp[0].minor);
}
// 2200 "parser.php.c"
        break;
      case 160:
// 947 "parser.php.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp202, NULL, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 2208 "parser.php.c"
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
// 34 "parser.php.lemon"

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

// 2317 "parser.php.c"
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
	zval *temp_ast;

	if (!phql) {
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL");
		return FAILURE;
	}

	cache_level = phalcon_globals_ptr->orm.cache_level;
	if (cache_level >= 0) {
		if (phalcon_globals_ptr->orm.parser_cache != NULL) {
			if ((temp_ast = zend_hash_str_find(phalcon_globals_ptr->orm.parser_cache, phql, phql_length)) != NULL) {
				ZVAL_ZVAL(*result, temp_ast, 1, 0);
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

					zend_hash_str_update(
						phalcon_globals_ptr->orm.parser_cache,
						phql,
						phql_length,
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
