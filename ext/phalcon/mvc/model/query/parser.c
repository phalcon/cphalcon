#include "php_phalcon.h"
/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 31 "parser.php.lemon"

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
#define PPNOCODE 154
#define PPACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE pp0;
  zval pp170;
  int pp307;
} PPMINORTYPE;
#define PPSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = pppParser->status
#define phql_ARG_STORE pppParser->status = status
#define PPNSTATE 346
#define PPNRULE 186
#define PPERRORSYMBOL 91
#define PPERRSYMDT pp307
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
static PPCODETYPE pp_lookahead[] = {
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
#define PP_SHIFT_USE_DFLT (-7)
static short pp_shift_ofst[] = {
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
#define PP_REDUCE_USE_DFLT (-1)
static short pp_reduce_ofst[] = {
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
static PPACTIONTYPE pp_default[] = {
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
static const char *ppRuleName[] = {
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
// 102 "parser.php.lemon"
{
	if ((pppminor->pp0)) {
		if ((pppminor->pp0)->free_flag) {
			efree((pppminor->pp0)->token);
		}
		efree((pppminor->pp0));
	}
}
// 923 "parser.php.c"
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
// 115 "parser.php.lemon"
{
	zval_ptr_dtor(&(pppminor->pp170));
}
// 969 "parser.php.c"
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
// 591 "parser.php.lemon"
{
	zephir_safe_zval_ptr_dtor((pppminor->pp170));
}
// 988 "parser.php.c"
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
// 111 "parser.php.lemon"
{
	ZVAL_ZVAL(&status->ret, &ppmsp[0].minor.pp170, 1, 1);
}
// 1391 "parser.php.c"
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
// 119 "parser.php.lemon"
{
	ppgotominor.pp170 = ppmsp[0].minor.pp170;
}
// 1418 "parser.php.c"
        break;
      case 6:
// 143 "parser.php.lemon"
{
	ppgotominor.pp170 = ppmsp[-1].minor.pp170;
	phql_ret_select_statement_union(&ppgotominor.pp170, &ppmsp[0].minor.pp170);
}
// 1426 "parser.php.c"
        break;
      case 7:
// 152 "parser.php.lemon"
{
	phql_ret_select_statement(&ppgotominor.pp170, &ppmsp[-6].minor.pp170, &ppmsp[-5].minor.pp170, &ppmsp[-2].minor.pp170, &ppmsp[-4].minor.pp170, &ppmsp[-3].minor.pp170, &ppmsp[-1].minor.pp170, &ppmsp[0].minor.pp170);
}
// 1433 "parser.php.c"
        break;
      case 8:
// 156 "parser.php.lemon"
{
	phql_ret_select_statement(&ppgotominor.pp170, &ppmsp[-6].minor.pp170, &ppmsp[-5].minor.pp170, &ppmsp[-2].minor.pp170, &ppmsp[-4].minor.pp170, &ppmsp[-3].minor.pp170, &ppmsp[-1].minor.pp170, &ppmsp[0].minor.pp170);
	phql_ret_select_statement_with(&ppgotominor.pp170, &ppmsp[-7].minor.pp170);
}
// 1441 "parser.php.c"
        break;
      case 9:
      case 29:
      case 152:
// 165 "parser.php.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp170, &ppmsp[-1].minor.pp170, &ppmsp[0].minor.pp170);
}
// 1450 "parser.php.c"
        break;
      case 10:
      case 19:
      case 50:
      case 53:
      case 78:
      case 153:
      case 163:
// 169 "parser.php.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp170, &ppmsp[0].minor.pp170, NULL);
}
// 1463 "parser.php.c"
        break;
      case 11:
// 177 "parser.php.lemon"
{
	phql_ret_union_item(&ppgotominor.pp170, &ppmsp[-1].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(36,&ppmsp[-2].minor);
}
// 1471 "parser.php.c"
        break;
      case 12:
// 185 "parser.php.lemon"
{
	ZVAL_TRUE(&ppgotominor.pp170);
  pp_destructor(37,&ppmsp[0].minor);
}
// 1479 "parser.php.c"
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
// 189 "parser.php.lemon"
{
	ZVAL_UNDEF(&ppgotominor.pp170);
}
// 1500 "parser.php.c"
        break;
      case 14:
// 197 "parser.php.lemon"
{
	phql_ret_select_clause(&ppgotominor.pp170, &ppmsp[-4].minor.pp170, &ppmsp[-3].minor.pp170, &ppmsp[-1].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(38,&ppmsp[-5].minor);
  pp_destructor(39,&ppmsp[-2].minor);
}
// 1509 "parser.php.c"
        break;
      case 15:
// 205 "parser.php.lemon"
{
	phql_ret_distinct_all(&ppgotominor.pp170, 1);
  pp_destructor(40,&ppmsp[0].minor);
}
// 1517 "parser.php.c"
        break;
      case 16:
// 209 "parser.php.lemon"
{
	phql_ret_distinct_all(&ppgotominor.pp170, 0);
  pp_destructor(37,&ppmsp[0].minor);
}
// 1525 "parser.php.c"
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
// 221 "parser.php.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp170, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(35,&ppmsp[-1].minor);
}
// 1542 "parser.php.c"
        break;
      case 20:
      case 164:
// 233 "parser.php.lemon"
{
	phql_ret_column_item(&ppgotominor.pp170, PHQL_T_STARALL, NULL, NULL, NULL);
  pp_destructor(22,&ppmsp[0].minor);
}
// 1551 "parser.php.c"
        break;
      case 21:
// 237 "parser.php.lemon"
{
	phql_ret_column_item(&ppgotominor.pp170, PHQL_T_DOMAINALL, NULL, ppmsp[-2].minor.pp0, NULL);
  pp_destructor(42,&ppmsp[-1].minor);
  pp_destructor(22,&ppmsp[0].minor);
}
// 1560 "parser.php.c"
        break;
      case 22:
// 241 "parser.php.lemon"
{
	phql_ret_column_item(&ppgotominor.pp170, PHQL_T_EXPR, &ppmsp[-2].minor.pp170, NULL, ppmsp[0].minor.pp0);
  pp_destructor(43,&ppmsp[-1].minor);
}
// 1568 "parser.php.c"
        break;
      case 23:
// 245 "parser.php.lemon"
{
	phql_ret_column_item(&ppgotominor.pp170, PHQL_T_EXPR, &ppmsp[-1].minor.pp170, NULL, ppmsp[0].minor.pp0);
}
// 1575 "parser.php.c"
        break;
      case 24:
// 249 "parser.php.lemon"
{
	phql_ret_column_item(&ppgotominor.pp170, PHQL_T_EXPR, &ppmsp[0].minor.pp170, NULL, NULL);
}
// 1582 "parser.php.c"
        break;
      case 32:
// 298 "parser.php.lemon"
{
	phql_ret_join_item(&ppgotominor.pp170, &ppmsp[-3].minor.pp170, &ppmsp[-2].minor.pp170, &ppmsp[-1].minor.pp170, &ppmsp[0].minor.pp170);
}
// 1589 "parser.php.c"
        break;
      case 33:
// 306 "parser.php.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp170, NULL, NULL, ppmsp[0].minor.pp0);
  pp_destructor(43,&ppmsp[-1].minor);
}
// 1597 "parser.php.c"
        break;
      case 34:
      case 54:
      case 74:
      case 185:
// 310 "parser.php.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp170, NULL, NULL, ppmsp[0].minor.pp0);
}
// 1607 "parser.php.c"
        break;
      case 36:
// 322 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp170, PHQL_T_INNERJOIN);
  pp_destructor(44,&ppmsp[-1].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1616 "parser.php.c"
        break;
      case 37:
// 326 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp170, PHQL_T_CROSSJOIN);
  pp_destructor(46,&ppmsp[-1].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1625 "parser.php.c"
        break;
      case 38:
// 330 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp170, PHQL_T_LEFTJOIN);
  pp_destructor(47,&ppmsp[-2].minor);
  pp_destructor(48,&ppmsp[-1].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1635 "parser.php.c"
        break;
      case 39:
// 334 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp170, PHQL_T_LEFTJOIN);
  pp_destructor(47,&ppmsp[-1].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1644 "parser.php.c"
        break;
      case 40:
// 338 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp170, PHQL_T_RIGHTJOIN);
  pp_destructor(49,&ppmsp[-2].minor);
  pp_destructor(48,&ppmsp[-1].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1654 "parser.php.c"
        break;
      case 41:
// 342 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp170, PHQL_T_RIGHTJOIN);
  pp_destructor(49,&ppmsp[-1].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1663 "parser.php.c"
        break;
      case 42:
// 346 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp170, PHQL_T_FULLJOIN);
  pp_destructor(50,&ppmsp[-2].minor);
  pp_destructor(48,&ppmsp[-1].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1673 "parser.php.c"
        break;
      case 43:
// 350 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp170, PHQL_T_FULLJOIN);
  pp_destructor(50,&ppmsp[-1].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1682 "parser.php.c"
        break;
      case 44:
// 354 "parser.php.lemon"
{
	phql_ret_join_type(&ppgotominor.pp170, PHQL_T_INNERJOIN);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1690 "parser.php.c"
        break;
      case 45:
// 362 "parser.php.lemon"
{
	ppgotominor.pp170 = ppmsp[0].minor.pp170;
  pp_destructor(51,&ppmsp[-1].minor);
}
// 1698 "parser.php.c"
        break;
      case 47:
// 375 "parser.php.lemon"
{
	phql_ret_insert_statement(&ppgotominor.pp170, &ppmsp[-4].minor.pp170, NULL, &ppmsp[-1].minor.pp170);
  pp_destructor(52,&ppmsp[-6].minor);
  pp_destructor(53,&ppmsp[-5].minor);
  pp_destructor(54,&ppmsp[-3].minor);
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 1710 "parser.php.c"
        break;
      case 48:
// 379 "parser.php.lemon"
{
	phql_ret_insert_statement(&ppgotominor.pp170, &ppmsp[-7].minor.pp170, &ppmsp[-5].minor.pp170, &ppmsp[-1].minor.pp170);
  pp_destructor(52,&ppmsp[-9].minor);
  pp_destructor(53,&ppmsp[-8].minor);
  pp_destructor(55,&ppmsp[-6].minor);
  pp_destructor(56,&ppmsp[-4].minor);
  pp_destructor(54,&ppmsp[-3].minor);
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 1724 "parser.php.c"
        break;
      case 55:
// 425 "parser.php.lemon"
{
	phql_ret_update_statement(&ppgotominor.pp170, &ppmsp[-2].minor.pp170, &ppmsp[-1].minor.pp170, &ppmsp[0].minor.pp170);
}
// 1731 "parser.php.c"
        break;
      case 56:
// 433 "parser.php.lemon"
{
	phql_ret_update_clause(&ppgotominor.pp170, &ppmsp[-3].minor.pp170, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(57,&ppmsp[-4].minor);
  pp_destructor(58,&ppmsp[-1].minor);
}
// 1740 "parser.php.c"
        break;
      case 59:
// 453 "parser.php.lemon"
{
	phql_ret_update_item(&ppgotominor.pp170, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 1748 "parser.php.c"
        break;
      case 61:
// 467 "parser.php.lemon"
{
	phql_ret_delete_statement(&ppgotominor.pp170, &ppmsp[-2].minor.pp170, &ppmsp[-1].minor.pp170, &ppmsp[0].minor.pp170);
}
// 1755 "parser.php.c"
        break;
      case 62:
// 475 "parser.php.lemon"
{
	phql_ret_delete_clause(&ppgotominor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(59,&ppmsp[-2].minor);
  pp_destructor(39,&ppmsp[-1].minor);
}
// 1764 "parser.php.c"
        break;
      case 63:
// 483 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp170, &ppmsp[-2].minor.pp170, ppmsp[0].minor.pp0, NULL);
  pp_destructor(43,&ppmsp[-1].minor);
}
// 1772 "parser.php.c"
        break;
      case 64:
// 487 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp170, &ppmsp[-1].minor.pp170, ppmsp[0].minor.pp0, NULL);
}
// 1779 "parser.php.c"
        break;
      case 65:
// 491 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp170, &ppmsp[0].minor.pp170, NULL, NULL);
}
// 1786 "parser.php.c"
        break;
      case 66:
// 495 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp170, &ppmsp[-4].minor.pp170, ppmsp[-2].minor.pp0, &ppmsp[0].minor.pp170);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(60,&ppmsp[-1].minor);
}
// 1795 "parser.php.c"
        break;
      case 67:
// 499 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp170, &ppmsp[-6].minor.pp170, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp170);
  pp_destructor(43,&ppmsp[-5].minor);
  pp_destructor(60,&ppmsp[-3].minor);
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 1806 "parser.php.c"
        break;
      case 68:
// 503 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp170, &ppmsp[-5].minor.pp170, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp170);
  pp_destructor(60,&ppmsp[-3].minor);
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 1816 "parser.php.c"
        break;
      case 69:
// 507 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp170, &ppmsp[-3].minor.pp170, ppmsp[-2].minor.pp0, &ppmsp[0].minor.pp170);
  pp_destructor(60,&ppmsp[-1].minor);
}
// 1824 "parser.php.c"
        break;
      case 70:
// 511 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp170, &ppmsp[-4].minor.pp170, NULL, &ppmsp[-1].minor.pp170);
  pp_destructor(60,&ppmsp[-3].minor);
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 1834 "parser.php.c"
        break;
      case 71:
// 515 "parser.php.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp170, &ppmsp[-2].minor.pp170, NULL, &ppmsp[0].minor.pp170);
  pp_destructor(60,&ppmsp[-1].minor);
}
// 1842 "parser.php.c"
        break;
      case 75:
// 543 "parser.php.lemon"
{
	phql_ret_with_clause(&ppgotominor.pp170, &ppmsp[0].minor.pp170, 0);
  pp_destructor(60,&ppmsp[-1].minor);
}
// 1850 "parser.php.c"
        break;
      case 76:
// 547 "parser.php.lemon"
{
	phql_ret_with_clause(&ppgotominor.pp170, &ppmsp[0].minor.pp170, 1);
  pp_destructor(60,&ppmsp[-2].minor);
  pp_destructor(61,&ppmsp[-1].minor);
}
// 1859 "parser.php.c"
        break;
      case 79:
// 567 "parser.php.lemon"
{
	phql_ret_common_table_expression(&ppgotominor.pp170, ppmsp[-5].minor.pp0, &ppmsp[-4].minor.pp170, &ppmsp[-1].minor.pp170);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 1869 "parser.php.c"
        break;
      case 80:
// 575 "parser.php.lemon"
{
	ppgotominor.pp170 = ppmsp[-1].minor.pp170;
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 1878 "parser.php.c"
        break;
      case 83:
// 595 "parser.php.lemon"
{
	ppgotominor.pp170 = ppmsp[0].minor.pp170;
  pp_destructor(62,&ppmsp[-1].minor);
}
// 1886 "parser.php.c"
        break;
      case 85:
// 607 "parser.php.lemon"
{
	ppgotominor.pp170 = ppmsp[0].minor.pp170;
  pp_destructor(63,&ppmsp[-2].minor);
  pp_destructor(64,&ppmsp[-1].minor);
}
// 1895 "parser.php.c"
        break;
      case 89:
// 631 "parser.php.lemon"
{
	phql_ret_order_item(&ppgotominor.pp170, &ppmsp[0].minor.pp170, 0);
}
// 1902 "parser.php.c"
        break;
      case 90:
// 635 "parser.php.lemon"
{
	phql_ret_order_item(&ppgotominor.pp170, &ppmsp[-1].minor.pp170, PHQL_T_ASC);
  pp_destructor(65,&ppmsp[0].minor);
}
// 1910 "parser.php.c"
        break;
      case 91:
// 639 "parser.php.lemon"
{
	phql_ret_order_item(&ppgotominor.pp170, &ppmsp[-1].minor.pp170, PHQL_T_DESC);
  pp_destructor(66,&ppmsp[0].minor);
}
// 1918 "parser.php.c"
        break;
      case 92:
// 647 "parser.php.lemon"
{
	ppgotominor.pp170 = ppmsp[0].minor.pp170;
  pp_destructor(67,&ppmsp[-2].minor);
  pp_destructor(64,&ppmsp[-1].minor);
}
// 1927 "parser.php.c"
        break;
      case 97:
// 679 "parser.php.lemon"
{
	ppgotominor.pp170 = ppmsp[0].minor.pp170;
  pp_destructor(68,&ppmsp[-1].minor);
}
// 1935 "parser.php.c"
        break;
      case 99:
// 691 "parser.php.lemon"
{
	phql_ret_for_update_clause(&ppgotominor.pp170);
  pp_destructor(69,&ppmsp[-1].minor);
  pp_destructor(57,&ppmsp[0].minor);
}
// 1944 "parser.php.c"
        break;
      case 101:
      case 105:
// 703 "parser.php.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp170, &ppmsp[0].minor.pp170, NULL);
  pp_destructor(70,&ppmsp[-1].minor);
}
// 1953 "parser.php.c"
        break;
      case 102:
// 707 "parser.php.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp170, &ppmsp[0].minor.pp170, &ppmsp[-2].minor.pp170);
  pp_destructor(70,&ppmsp[-3].minor);
  pp_destructor(35,&ppmsp[-1].minor);
}
// 1962 "parser.php.c"
        break;
      case 103:
// 711 "parser.php.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp170, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(70,&ppmsp[-3].minor);
  pp_destructor(71,&ppmsp[-1].minor);
}
// 1971 "parser.php.c"
        break;
      case 107:
      case 174:
// 731 "parser.php.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp170, PHQL_T_INTEGER, ppmsp[0].minor.pp0);
}
// 1979 "parser.php.c"
        break;
      case 108:
      case 175:
// 735 "parser.php.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp170, PHQL_T_HINTEGER, ppmsp[0].minor.pp0);
}
// 1987 "parser.php.c"
        break;
      case 109:
      case 181:
// 739 "parser.php.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp170, PHQL_T_NPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1995 "parser.php.c"
        break;
      case 110:
      case 182:
// 743 "parser.php.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp170, PHQL_T_SPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2003 "parser.php.c"
        break;
      case 111:
      case 183:
// 747 "parser.php.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp170, PHQL_T_BPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2011 "parser.php.c"
        break;
      case 112:
// 755 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_MINUS, NULL, &ppmsp[0].minor.pp170);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 2019 "parser.php.c"
        break;
      case 113:
// 759 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_SUB, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 2027 "parser.php.c"
        break;
      case 114:
// 763 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_ADD, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(24,&ppmsp[-1].minor);
}
// 2035 "parser.php.c"
        break;
      case 115:
// 767 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_MUL, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(22,&ppmsp[-1].minor);
}
// 2043 "parser.php.c"
        break;
      case 116:
// 771 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_DIV, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(21,&ppmsp[-1].minor);
}
// 2051 "parser.php.c"
        break;
      case 117:
// 775 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_MOD, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(23,&ppmsp[-1].minor);
}
// 2059 "parser.php.c"
        break;
      case 118:
// 779 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_AND, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(14,&ppmsp[-1].minor);
}
// 2067 "parser.php.c"
        break;
      case 119:
// 783 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_OR, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(15,&ppmsp[-1].minor);
}
// 2075 "parser.php.c"
        break;
      case 120:
// 787 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_BITWISE_AND, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(18,&ppmsp[-1].minor);
}
// 2083 "parser.php.c"
        break;
      case 121:
// 791 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_BITWISE_OR, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(19,&ppmsp[-1].minor);
}
// 2091 "parser.php.c"
        break;
      case 122:
// 795 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_BITWISE_XOR, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2099 "parser.php.c"
        break;
      case 123:
// 799 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_OP_MATCHES, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(10,&ppmsp[-1].minor);
}
// 2107 "parser.php.c"
        break;
      case 124:
// 803 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_OP_CONTAINS, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2115 "parser.php.c"
        break;
      case 125:
// 807 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_OP_CONTAINED, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2123 "parser.php.c"
        break;
      case 126:
// 811 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_OP_OVERLAPS, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 2131 "parser.php.c"
        break;
      case 127:
// 815 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_OP_CONCAT, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(26,&ppmsp[-1].minor);
}
// 2139 "parser.php.c"
        break;
      case 128:
// 819 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_OP_JSON_GET, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(31,&ppmsp[-1].minor);
}
// 2147 "parser.php.c"
        break;
      case 129:
// 823 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_OP_JSON_GET_TEXT, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 2155 "parser.php.c"
        break;
      case 130:
// 827 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_OP_JSON_PATH, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(33,&ppmsp[-1].minor);
}
// 2163 "parser.php.c"
        break;
      case 131:
// 831 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_OP_JSON_PATH_TEXT, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(34,&ppmsp[-1].minor);
}
// 2171 "parser.php.c"
        break;
      case 132:
// 835 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_EQUALS, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 2179 "parser.php.c"
        break;
      case 133:
// 839 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_NOTEQUALS, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(5,&ppmsp[-1].minor);
}
// 2187 "parser.php.c"
        break;
      case 134:
// 843 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_LESS, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(6,&ppmsp[-1].minor);
}
// 2195 "parser.php.c"
        break;
      case 135:
// 847 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_GREATER, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(7,&ppmsp[-1].minor);
}
// 2203 "parser.php.c"
        break;
      case 136:
// 851 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_GREATEREQUAL, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(8,&ppmsp[-1].minor);
}
// 2211 "parser.php.c"
        break;
      case 137:
// 855 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_LESSEQUAL, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(9,&ppmsp[-1].minor);
}
// 2219 "parser.php.c"
        break;
      case 138:
// 859 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_LIKE, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 2227 "parser.php.c"
        break;
      case 139:
// 863 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_NLIKE, &ppmsp[-3].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(29,&ppmsp[-2].minor);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 2236 "parser.php.c"
        break;
      case 140:
// 867 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_ILIKE, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 2244 "parser.php.c"
        break;
      case 141:
// 871 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_NILIKE, &ppmsp[-3].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(29,&ppmsp[-2].minor);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 2253 "parser.php.c"
        break;
      case 142:
      case 145:
// 875 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_IN, &ppmsp[-4].minor.pp170, &ppmsp[-1].minor.pp170);
  pp_destructor(28,&ppmsp[-3].minor);
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 2264 "parser.php.c"
        break;
      case 143:
      case 146:
// 879 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_NOTIN, &ppmsp[-5].minor.pp170, &ppmsp[-1].minor.pp170);
  pp_destructor(29,&ppmsp[-4].minor);
  pp_destructor(28,&ppmsp[-3].minor);
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 2276 "parser.php.c"
        break;
      case 144:
// 883 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_SUBQUERY, &ppmsp[-1].minor.pp170, NULL);
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 2285 "parser.php.c"
        break;
      case 147:
// 895 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_EXISTS, NULL, &ppmsp[-1].minor.pp170);
  pp_destructor(77,&ppmsp[-3].minor);
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 2295 "parser.php.c"
        break;
      case 148:
// 899 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_AGAINST, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(1,&ppmsp[-1].minor);
}
// 2303 "parser.php.c"
        break;
      case 149:
// 903 "parser.php.lemon"
{
	{
		zval qualified;
		phql_ret_raw_qualified_name(&qualified, ppmsp[-1].minor.pp0, NULL);
		phql_ret_expr(&ppgotominor.pp170, PHQL_T_CAST, &ppmsp[-3].minor.pp170, &qualified);
	}
  pp_destructor(78,&ppmsp[-5].minor);
  pp_destructor(55,&ppmsp[-4].minor);
  pp_destructor(43,&ppmsp[-2].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 2318 "parser.php.c"
        break;
      case 150:
// 911 "parser.php.lemon"
{
	{
		zval qualified;
		phql_ret_raw_qualified_name(&qualified, ppmsp[-1].minor.pp0, NULL);
		phql_ret_expr(&ppgotominor.pp170, PHQL_T_CONVERT, &ppmsp[-3].minor.pp170, &qualified);
	}
  pp_destructor(79,&ppmsp[-5].minor);
  pp_destructor(55,&ppmsp[-4].minor);
  pp_destructor(80,&ppmsp[-2].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 2333 "parser.php.c"
        break;
      case 151:
// 919 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_CASE, &ppmsp[-2].minor.pp170, &ppmsp[-1].minor.pp170);
  pp_destructor(81,&ppmsp[-3].minor);
  pp_destructor(82,&ppmsp[0].minor);
}
// 2342 "parser.php.c"
        break;
      case 154:
// 931 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_WHEN, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(83,&ppmsp[-3].minor);
  pp_destructor(84,&ppmsp[-1].minor);
}
// 2351 "parser.php.c"
        break;
      case 155:
// 935 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_ELSE, &ppmsp[0].minor.pp170, NULL);
  pp_destructor(85,&ppmsp[-1].minor);
}
// 2359 "parser.php.c"
        break;
      case 157:
// 947 "parser.php.lemon"
{
	phql_ret_func_call(&ppgotominor.pp170, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp170, &ppmsp[-2].minor.pp170);
  pp_destructor(55,&ppmsp[-3].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 2368 "parser.php.c"
        break;
      case 158:
// 955 "parser.php.lemon"
{
	phql_ret_distinct(&ppgotominor.pp170);
  pp_destructor(40,&ppmsp[0].minor);
}
// 2376 "parser.php.c"
        break;
      case 166:
// 999 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_ISNULL, &ppmsp[-2].minor.pp170, NULL);
  pp_destructor(27,&ppmsp[-1].minor);
  pp_destructor(86,&ppmsp[0].minor);
}
// 2385 "parser.php.c"
        break;
      case 167:
// 1003 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_ISNOTNULL, &ppmsp[-3].minor.pp170, NULL);
  pp_destructor(27,&ppmsp[-2].minor);
  pp_destructor(29,&ppmsp[-1].minor);
  pp_destructor(86,&ppmsp[0].minor);
}
// 2395 "parser.php.c"
        break;
      case 168:
// 1007 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_BETWEEN, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(2,&ppmsp[-1].minor);
}
// 2403 "parser.php.c"
        break;
      case 169:
// 1011 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_BETWEEN_NOT, &ppmsp[-2].minor.pp170, &ppmsp[0].minor.pp170);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 2411 "parser.php.c"
        break;
      case 170:
// 1015 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_NOT, NULL, &ppmsp[0].minor.pp170);
  pp_destructor(29,&ppmsp[-1].minor);
}
// 2419 "parser.php.c"
        break;
      case 171:
// 1019 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_BITWISE_NOT, NULL, &ppmsp[0].minor.pp170);
  pp_destructor(30,&ppmsp[-1].minor);
}
// 2427 "parser.php.c"
        break;
      case 172:
// 1023 "parser.php.lemon"
{
	phql_ret_expr(&ppgotominor.pp170, PHQL_T_ENCLOSED, &ppmsp[-1].minor.pp170, NULL);
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(56,&ppmsp[0].minor);
}
// 2436 "parser.php.c"
        break;
      case 176:
// 1039 "parser.php.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp170, PHQL_T_STRING, ppmsp[0].minor.pp0);
}
// 2443 "parser.php.c"
        break;
      case 177:
// 1043 "parser.php.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp170, PHQL_T_DOUBLE, ppmsp[0].minor.pp0);
}
// 2450 "parser.php.c"
        break;
      case 178:
// 1047 "parser.php.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp170, PHQL_T_NULL, NULL);
  pp_destructor(86,&ppmsp[0].minor);
}
// 2458 "parser.php.c"
        break;
      case 179:
// 1051 "parser.php.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp170, PHQL_T_TRUE, NULL);
  pp_destructor(89,&ppmsp[0].minor);
}
// 2466 "parser.php.c"
        break;
      case 180:
// 1055 "parser.php.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp170, PHQL_T_FALSE, NULL);
  pp_destructor(90,&ppmsp[0].minor);
}
// 2474 "parser.php.c"
        break;
      case 184:
// 1078 "parser.php.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp170, NULL, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(42,&ppmsp[-1].minor);
}
// 2482 "parser.php.c"
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
// 35 "parser.php.lemon"

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

// 2591 "parser.php.c"
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
  { SL("@@"),				   PHQL_T_OP_MATCHES },
  { SL("@>"),				   PHQL_T_OP_CONTAINS },
  { SL("<@"),				   PHQL_T_OP_CONTAINED },
  { SL("&&"),				   PHQL_T_OP_OVERLAPS },
  { SL("||"),				   PHQL_T_OP_CONCAT },
  { SL("->"),				   PHQL_T_OP_JSON_GET },
  { SL("->>"),				   PHQL_T_OP_JSON_GET_TEXT },
  { SL("#>"),				   PHQL_T_OP_JSON_PATH },
  { SL("#>>"),				   PHQL_T_OP_JSON_PATH_TEXT },
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
	char *error, *token_start;
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

	while (1) {
		token_start = state->start;

		scanner_status = phql_get_token(state, &token);
		if (scanner_status < 0) {
			break;
		}

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
				if (token_start[0] != '[' && token.value && zend_binary_strcasecmp(token.value, token.len, ZEND_STRL("UNION")) == 0) {
					efree(token.value);
					token.value = NULL;
					token.len = 0;
					phql_(phql_parser, PHQL_UNION, NULL, parser_status);
				} else if (token_start[0] != '[' && token.value && zend_binary_strcasecmp(token.value, token.len, ZEND_STRL("RECURSIVE")) == 0) {
					efree(token.value);
					token.value = NULL;
					token.len = 0;
					phql_(phql_parser, PHQL_RECURSIVE, NULL, parser_status);
				} else {
					phql_parse_with_token(phql_parser, PHQL_T_IDENTIFIER, PHQL_IDENTIFIER, &token, parser_status);
				}
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
			case PHQL_T_OP_MATCHES:
				phql_(phql_parser, PHQL_OP_MATCHES, NULL, parser_status);
				break;
			case PHQL_T_OP_CONTAINS:
				phql_(phql_parser, PHQL_OP_CONTAINS, NULL, parser_status);
				break;
			case PHQL_T_OP_CONTAINED:
				phql_(phql_parser, PHQL_OP_CONTAINED, NULL, parser_status);
				break;
			case PHQL_T_OP_OVERLAPS:
				phql_(phql_parser, PHQL_OP_OVERLAPS, NULL, parser_status);
				break;
			case PHQL_T_OP_CONCAT:
				phql_(phql_parser, PHQL_OP_CONCAT, NULL, parser_status);
				break;
			case PHQL_T_OP_JSON_GET:
				phql_(phql_parser, PHQL_OP_JSON_GET, NULL, parser_status);
				break;
			case PHQL_T_OP_JSON_GET_TEXT:
				phql_(phql_parser, PHQL_OP_JSON_GET_TEXT, NULL, parser_status);
				break;
			case PHQL_T_OP_JSON_PATH:
				phql_(phql_parser, PHQL_OP_JSON_PATH, NULL, parser_status);
				break;
			case PHQL_T_OP_JSON_PATH_TEXT:
				phql_(phql_parser, PHQL_OP_JSON_PATH_TEXT, NULL, parser_status);
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
