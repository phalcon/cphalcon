/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
#line 28 "parser.php5.lemon"

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
**    phannot_TOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is phannot_TOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.
**    phannot_ARG_SDECL     A static variable declaration for the %extra_argument
**    phannot_ARG_PDECL     A parameter declaration for the %extra_argument
**    phannot_ARG_STORE     Code to store %extra_argument into yypParser
**    phannot_ARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 28
#define YYACTIONTYPE unsigned char
#define phannot_TOKENTYPE phannot_parser_token*
typedef union {
  phannot_TOKENTYPE yy0;
  zval* yy36;
  int yy55;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phannot_ARG_SDECL phannot_parser_status *status;
#define phannot_ARG_PDECL ,phannot_parser_status *status
#define phannot_ARG_FETCH phannot_parser_status *status = yypParser->status
#define phannot_ARG_STORE yypParser->status = status
#define YYNSTATE 40
#define YYNRULE 25
#define YYERRORSYMBOL 18
#define YYERRSYMDT yy55
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
 /*     0 */     4,   28,   15,   38,   12,   37,   16,   18,   20,   21,
 /*    10 */    22,   23,   24,    4,   31,    4,   17,   15,   40,   19,
 /*    20 */    35,   16,   18,   20,   21,   22,   23,   24,    3,   31,
 /*    30 */     4,   28,   15,    6,   12,   30,   16,   18,   20,   21,
 /*    40 */    22,   23,   24,   54,   31,   15,   25,   27,   11,   16,
 /*    50 */    13,   36,   15,    7,   27,   11,   16,   15,   32,   27,
 /*    60 */    11,   16,   15,    9,   10,   11,   16,   66,    1,    2,
 /*    70 */    39,   15,    9,    5,   14,   16,   41,   26,    4,    9,
 /*    80 */    29,   34,   54,    8,   54,   54,   54,   54,   33,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     2,    3,   22,    5,    6,   25,   26,    9,   10,   11,
 /*    10 */    12,   13,   14,    2,   16,    2,    3,   22,    0,    6,
 /*    20 */    25,   26,    9,   10,   11,   12,   13,   14,   22,   16,
 /*    30 */     2,    3,   22,    4,    6,   25,   26,    9,   10,   11,
 /*    40 */    12,   13,   14,   27,   16,   22,   23,   24,   25,   26,
 /*    50 */     7,    8,   22,   23,   24,   25,   26,   22,   23,   24,
 /*    60 */    25,   26,   22,    1,   24,   25,   26,   19,   20,   21,
 /*    70 */    22,   22,    1,    3,   25,   26,    0,   15,    2,    1,
 /*    80 */     7,    8,   27,    5,   27,   27,   27,   27,   17,
};
#define YY_SHIFT_USE_DFLT (-3)
static signed char yy_shift_ofst[] = {
 /*     0 */    11,   18,   76,   -3,   70,   29,   -2,   78,   -3,   28,
 /*    10 */    -3,   -3,   43,   13,   -3,   -3,   -3,   -3,   -3,   -3,
 /*    20 */    -3,   -3,   -3,   -3,   28,   62,   -3,   -3,   73,   13,
 /*    30 */    -3,   28,   71,   -3,   13,   -3,   13,   -3,   -3,   -3,
};
#define YY_REDUCE_USE_DFLT (-21)
static signed char yy_reduce_ofst[] = {
 /*     0 */    48,  -21,    6,  -21,  -21,  -21,   30,  -21,  -21,   40,
 /*    10 */   -21,  -21,  -21,   49,  -21,  -21,  -21,  -21,  -21,  -21,
 /*    20 */   -21,  -21,  -21,  -21,   23,  -21,  -21,  -21,  -21,   10,
 /*    30 */   -21,   35,  -21,  -21,   -5,  -21,  -20,  -21,  -21,  -21,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */    65,   65,   65,   42,   65,   46,   65,   65,   44,   65,
 /*    10 */    47,   49,   58,   65,   50,   54,   55,   56,   57,   58,
 /*    20 */    59,   60,   61,   62,   65,   65,   63,   48,   56,   65,
 /*    30 */    52,   65,   65,   64,   65,   53,   65,   51,   45,   43,
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
  phannot_ARG_SDECL                /* A place to hold %extra_argument */
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
void phannot_Trace(FILE *TraceFILE, char *zTracePrompt){
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
  "$",             "COMMA",         "AT",            "IDENTIFIER",  
  "PARENTHESES_OPEN",  "PARENTHESES_CLOSE",  "STRING",        "EQUALS",      
  "COLON",         "INTEGER",       "DOUBLE",        "NULL",        
  "FALSE",         "TRUE",          "BRACKET_OPEN",  "BRACKET_CLOSE",
  "SBRACKET_OPEN",  "SBRACKET_CLOSE",  "error",         "program",     
  "annotation_language",  "annotation_list",  "annotation",    "argument_list",
  "argument_item",  "expr",          "array",       
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *yyRuleName[] = {
 /*   0 */ "program ::= annotation_language",
 /*   1 */ "annotation_language ::= annotation_list",
 /*   2 */ "annotation_list ::= annotation_list annotation",
 /*   3 */ "annotation_list ::= annotation",
 /*   4 */ "annotation ::= AT IDENTIFIER PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /*   5 */ "annotation ::= AT IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE",
 /*   6 */ "annotation ::= AT IDENTIFIER",
 /*   7 */ "argument_list ::= argument_list COMMA argument_item",
 /*   8 */ "argument_list ::= argument_item",
 /*   9 */ "argument_item ::= expr",
 /*  10 */ "argument_item ::= STRING EQUALS expr",
 /*  11 */ "argument_item ::= STRING COLON expr",
 /*  12 */ "argument_item ::= IDENTIFIER EQUALS expr",
 /*  13 */ "argument_item ::= IDENTIFIER COLON expr",
 /*  14 */ "expr ::= annotation",
 /*  15 */ "expr ::= array",
 /*  16 */ "expr ::= IDENTIFIER",
 /*  17 */ "expr ::= INTEGER",
 /*  18 */ "expr ::= STRING",
 /*  19 */ "expr ::= DOUBLE",
 /*  20 */ "expr ::= NULL",
 /*  21 */ "expr ::= FALSE",
 /*  22 */ "expr ::= TRUE",
 /*  23 */ "array ::= BRACKET_OPEN argument_list BRACKET_CLOSE",
 /*  24 */ "array ::= SBRACKET_OPEN argument_list SBRACKET_CLOSE",
};
#endif /* NDEBUG */

/*
** This function returns the symbolic name associated with a token
** value.
*/
const char *phannot_TokenName(int tokenType){
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
** to phannot_ and phannot_Free.
*/
void *phannot_Alloc(void *(*mallocProc)(size_t)){
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
#line 77 "parser.php5.lemon"
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
#line 378 "parser.php5.c"
      break;
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
#line 90 "parser.php5.lemon"
{
    zval_ptr_dtor(&(yypminor->yy36));
}
#line 390 "parser.php5.c"
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
**       obtained from phannot_Alloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void phannot_Free(
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
     phannot_ARG_FETCH;
     yypParser->yyidx--;
#ifndef NDEBUG
     if( yyTraceFILE ){
       fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
     }
#endif
     while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     phannot_ARG_STORE; /* Suppress warning about unused %extra_argument var */
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
  { 19, 1 },
  { 20, 1 },
  { 21, 2 },
  { 21, 1 },
  { 22, 5 },
  { 22, 4 },
  { 22, 2 },
  { 23, 3 },
  { 23, 1 },
  { 24, 1 },
  { 24, 3 },
  { 24, 3 },
  { 24, 3 },
  { 24, 3 },
  { 25, 1 },
  { 25, 1 },
  { 25, 1 },
  { 25, 1 },
  { 25, 1 },
  { 25, 1 },
  { 25, 1 },
  { 25, 1 },
  { 25, 1 },
  { 26, 3 },
  { 26, 3 },
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
  phannot_ARG_FETCH;
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
#line 86 "parser.php5.lemon"
{
	status->ret = yymsp[0].minor.yy36;
}
#line 632 "parser.php5.c"
        break;
      case 1:
      case 14:
      case 15:
#line 94 "parser.php5.lemon"
{
	yygotominor.yy36 = yymsp[0].minor.yy36;
}
#line 641 "parser.php5.c"
        break;
      case 2:
#line 102 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_zval_list(yymsp[-1].minor.yy36, yymsp[0].minor.yy36);
}
#line 648 "parser.php5.c"
        break;
      case 3:
      case 8:
#line 106 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_zval_list(NULL, yymsp[0].minor.yy36);
}
#line 656 "parser.php5.c"
        break;
      case 4:
#line 114 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_annotation(yymsp[-3].minor.yy0, yymsp[-1].minor.yy36, status->scanner_state);
  yy_destructor(2,&yymsp[-4].minor);
  yy_destructor(4,&yymsp[-2].minor);
  yy_destructor(5,&yymsp[0].minor);
}
#line 666 "parser.php5.c"
        break;
      case 5:
#line 118 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_annotation(yymsp[-2].minor.yy0, NULL, status->scanner_state);
  yy_destructor(2,&yymsp[-3].minor);
  yy_destructor(4,&yymsp[-1].minor);
  yy_destructor(5,&yymsp[0].minor);
}
#line 676 "parser.php5.c"
        break;
      case 6:
#line 122 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_annotation(yymsp[0].minor.yy0, NULL, status->scanner_state);
  yy_destructor(2,&yymsp[-1].minor);
}
#line 684 "parser.php5.c"
        break;
      case 7:
#line 130 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_zval_list(yymsp[-2].minor.yy36, yymsp[0].minor.yy36);
  yy_destructor(1,&yymsp[-1].minor);
}
#line 692 "parser.php5.c"
        break;
      case 9:
#line 142 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_named_item(NULL, yymsp[0].minor.yy36);
}
#line 699 "parser.php5.c"
        break;
      case 10:
      case 12:
#line 146 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_named_item(yymsp[-2].minor.yy0, yymsp[0].minor.yy36);
  yy_destructor(7,&yymsp[-1].minor);
}
#line 708 "parser.php5.c"
        break;
      case 11:
      case 13:
#line 150 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_named_item(yymsp[-2].minor.yy0, yymsp[0].minor.yy36);
  yy_destructor(8,&yymsp[-1].minor);
}
#line 717 "parser.php5.c"
        break;
      case 16:
#line 174 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_literal_zval(PHANNOT_T_IDENTIFIER, yymsp[0].minor.yy0);
}
#line 724 "parser.php5.c"
        break;
      case 17:
#line 178 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_literal_zval(PHANNOT_T_INTEGER, yymsp[0].minor.yy0);
}
#line 731 "parser.php5.c"
        break;
      case 18:
#line 182 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_literal_zval(PHANNOT_T_STRING, yymsp[0].minor.yy0);
}
#line 738 "parser.php5.c"
        break;
      case 19:
#line 186 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_literal_zval(PHANNOT_T_DOUBLE, yymsp[0].minor.yy0);
}
#line 745 "parser.php5.c"
        break;
      case 20:
#line 190 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_literal_zval(PHANNOT_T_NULL, NULL);
  yy_destructor(11,&yymsp[0].minor);
}
#line 753 "parser.php5.c"
        break;
      case 21:
#line 194 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_literal_zval(PHANNOT_T_FALSE, NULL);
  yy_destructor(12,&yymsp[0].minor);
}
#line 761 "parser.php5.c"
        break;
      case 22:
#line 198 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_literal_zval(PHANNOT_T_TRUE, NULL);
  yy_destructor(13,&yymsp[0].minor);
}
#line 769 "parser.php5.c"
        break;
      case 23:
#line 202 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_array(yymsp[-1].minor.yy36);
  yy_destructor(14,&yymsp[-2].minor);
  yy_destructor(15,&yymsp[0].minor);
}
#line 778 "parser.php5.c"
        break;
      case 24:
#line 206 "parser.php5.lemon"
{
	yygotominor.yy36 = phannot_ret_array(yymsp[-1].minor.yy36);
  yy_destructor(16,&yymsp[-2].minor);
  yy_destructor(17,&yymsp[0].minor);
}
#line 787 "parser.php5.c"
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
  phannot_ARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  phannot_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  phannot_ARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 32 "parser.php5.lemon"

	if (status->scanner_state->start_length) {
		char *token_name = NULL;
		const phannot_token_names *tokens = phannot_tokens;
		uint active_token = status->scanner_state->active_token;
		uint near_length = status->scanner_state->start_length;

		if (active_token) {
			do {
				if (tokens->code == active_token) {
					token_name = tokens->name;
					break;
				}
				++tokens;
			} while (tokens[0].code != 0);
		}

		if (!token_name) {
			token_name  = "UNKNOWN";
		}

		if (near_length > 0) {
			if (status->token->value) {
				spprintf(&status->syntax_error, 0, "Syntax error, unexpected token %s(%s), near to '%s' in %s on line %d", token_name, status->token->value, status->scanner_state->start, status->scanner_state->active_file, status->scanner_state->active_line);
			} else {
				spprintf(&status->syntax_error, 0, "Syntax error, unexpected token %s, near to '%s' in %s on line %d", token_name, status->scanner_state->start, status->scanner_state->active_file, status->scanner_state->active_line);
			}
		} else {
			if (active_token != PHANNOT_T_IGNORE) {
				if (status->token->value) {
					spprintf(&status->syntax_error, 0, "Syntax error, unexpected token %s(%s), at the end of docblock in %s on line %d", token_name, status->token->value, status->scanner_state->active_file, status->scanner_state->active_line);
				} else {
					spprintf(&status->syntax_error, 0, "Syntax error, unexpected token %s, at the end of docblock in %s on line %d", token_name, status->scanner_state->active_file, status->scanner_state->active_line);
				}
			} else {
				spprintf(&status->syntax_error, 0, "Syntax error, unexpected EOF, at the end of docblock in %s on line %d", status->scanner_state->active_file, status->scanner_state->active_line);
			}
		}
	} else {
		spprintf(&status->syntax_error, 0, "Syntax error, unexpected EOF in %s", status->scanner_state->active_file);
	}

	status->status = PHANNOT_PARSING_FAILED;

#line 874 "parser.php5.c"
  phannot_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  phannot_ARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  phannot_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "phannot_Alloc" which describes the current state of the parser.
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
void phannot_(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  phannot_TOKENTYPE yyminor       /* The value for the token */
  phannot_ARG_PDECL               /* Optional %extra_argument parameter */
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
  phannot_ARG_STORE;

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
