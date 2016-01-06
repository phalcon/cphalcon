/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 28 "parser.lemon"


#include "php_phalcon.h"
#include "phalcon.h"

#include <ext/standard/php_smart_str.h>
#include <main/spprintf.h>

#include "parser.h"
#include "scanner.h"
#include "annot.h"

#include "kernel/main.h"
#include "kernel/exception.h"

static zval *phannot_ret_literal_zval(int type, phannot_parser_token *T)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, "type", type);
	if (T) {
		add_assoc_stringl(ret, "value", T->token, T->token_len, 0);
		efree(T);
	}

	return ret;
}

static zval *phannot_ret_array(zval *items)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, "type", PHANNOT_T_ARRAY);

	if (items) {
		add_assoc_zval(ret, "items", items);
	}

	return ret;
}

static zval *phannot_ret_zval_list(zval *list_left, zval *right_list)
{
	zval *ret;
	HashPosition pos;
	HashTable *list;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	if (list_left) {

		list = Z_ARRVAL_P(list_left);
		if (zend_hash_index_exists(list, 0)) {
			zend_hash_internal_pointer_reset_ex(list, &pos);
			for (;; zend_hash_move_forward_ex(list, &pos)) {

				zval ** item;

				if (zend_hash_get_current_data_ex(list, (void**) &item, &pos) == FAILURE) {
					break;
				}

				Z_ADDREF_PP(item);
				add_next_index_zval(ret, *item);

			}
			zval_ptr_dtor(&list_left);
		} else {
			add_next_index_zval(ret, list_left);
		}
	}

	add_next_index_zval(ret, right_list);

	return ret;
}

static zval *phannot_ret_named_item(phannot_parser_token *name, zval *expr)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_zval(ret, "expr", expr);
	if (name != NULL) {
		add_assoc_stringl(ret, "name", name->token, name->token_len, 0);
		efree(name);
	}

	return ret;
}

static zval *phannot_ret_annotation(phannot_parser_token *name, zval *arguments, phannot_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 5);

	add_assoc_long(ret, "type", PHANNOT_T_ANNOTATION);

	if (name) {
		add_assoc_stringl(ret, "name", name->token, name->token_len, 0);
		efree(name);
	}

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	add_assoc_string(ret, "file", (char*)state->active_file, !IS_INTERNED(state->active_file));
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}


// 131 "parser.c"
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
**    AACODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    AANOCODE           is a number of type AACODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    AAFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    AAACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    phannot_TOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    AAMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is phannot_TOKENTYPE.  The entry in the union
**                       for base tokens is called "aa0".
**    AASTACKDEPTH       is the maximum depth of the parser's stack.
**    phannot_ARG_SDECL     A static variable declaration for the %extra_argument
**    phannot_ARG_PDECL     A parameter declaration for the %extra_argument
**    phannot_ARG_STORE     Code to store %extra_argument into aapParser
**    phannot_ARG_FETCH     Code to extract %extra_argument from aapParser
**    AANSTATE           the combined number of states.
**    AANRULE            the number of rules in the grammar
**    AAERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define AACODETYPE unsigned char
#define AANOCODE 28
#define AAACTIONTYPE unsigned char
#define phannot_TOKENTYPE phannot_parser_token*
typedef union {
  phannot_TOKENTYPE aa0;
  zval* aa36;
  int aa55;
} AAMINORTYPE;
#define AASTACKDEPTH 100
#define phannot_ARG_SDECL phannot_parser_status *status;
#define phannot_ARG_PDECL ,phannot_parser_status *status
#define phannot_ARG_FETCH phannot_parser_status *status = aapParser->status
#define phannot_ARG_STORE aapParser->status = status
#define AANSTATE 40
#define AANRULE 25
#define AAERRORSYMBOL 18
#define AAERRSYMDT aa55
#define AA_NO_ACTION      (AANSTATE+AANRULE+2)
#define AA_ACCEPT_ACTION  (AANSTATE+AANRULE+1)
#define AA_ERROR_ACTION   (AANSTATE+AANRULE)

/* Next are that tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < AANSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   AANSTATE <= N < AANSTATE+AANRULE   Reduce by rule N-AANSTATE.
**
**   N == AANSTATE+AANRULE              A syntax error has occurred.
**
**   N == AANSTATE+AANRULE+1            The parser accepts its input.
**
**   N == AANSTATE+AANRULE+2            No such action.  Denotes unused
**                                      slots in the aa_action[] table.
**
** The action table is constructed as a single large table named aa_action[].
** Given state S and lookahead X, the action is computed as
**
**      aa_action[ aa_shift_ofst[S] + X ]
**
** If the index value aa_shift_ofst[S]+X is out of range or if the value
** aa_lookahead[aa_shift_ofst[S]+X] is not equal to X or if aa_shift_ofst[S]
** is equal to AA_SHIFT_USE_DFLT, it means that the action is not in the table
** and that aa_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the aa_reduce_ofst[] array is used in place of
** the aa_shift_ofst[] array and AA_REDUCE_USE_DFLT is used in place of
** AA_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  aa_action[]        A single table containing all actions.
**  aa_lookahead[]     A table containing the lookahead for each entry in
**                     aa_action.  Used to detect hash collisions.
**  aa_shift_ofst[]    For each state, the offset into aa_action for
**                     shifting terminals.
**  aa_reduce_ofst[]   For each state, the offset into aa_action for
**                     shifting non-terminals after a reduce.
**  aa_default[]       Default action for each state.
*/
static AAACTIONTYPE aa_action[] = {
 /*     0 */     4,   28,   15,   38,   12,   14,   16,   18,   20,   21,
 /*    10 */    22,   23,   24,    4,   31,    4,   28,   15,   40,   12,
 /*    20 */    30,   16,   18,   20,   21,   22,   23,   24,    3,   31,
 /*    30 */     4,   17,   15,    6,   19,   35,   16,   18,   20,   21,
 /*    40 */    22,   23,   24,    5,   31,   15,    7,   27,   11,   16,
 /*    50 */    54,   54,   15,   25,   27,   11,   16,   15,   32,   27,
 /*    60 */    11,   16,   66,    1,    2,   39,   41,   15,    4,   10,
 /*    70 */    11,   16,   15,    9,    9,   37,   16,    8,   13,   36,
 /*    80 */     9,   29,   34,   54,   54,   54,   54,   54,   26,   54,
 /*    90 */    54,   54,   54,   54,   54,   54,   33,
};
static AACODETYPE aa_lookahead[] = {
 /*     0 */     2,    3,   22,    5,    6,   25,   26,    9,   10,   11,
 /*    10 */    12,   13,   14,    2,   16,    2,    3,   22,    0,    6,
 /*    20 */    25,   26,    9,   10,   11,   12,   13,   14,   22,   16,
 /*    30 */     2,    3,   22,    4,    6,   25,   26,    9,   10,   11,
 /*    40 */    12,   13,   14,    3,   16,   22,   23,   24,   25,   26,
 /*    50 */    27,   27,   22,   23,   24,   25,   26,   22,   23,   24,
 /*    60 */    25,   26,   19,   20,   21,   22,    0,   22,    2,   24,
 /*    70 */    25,   26,   22,    1,    1,   25,   26,    5,    7,    8,
 /*    80 */     1,    7,    8,   27,   27,   27,   27,   27,   15,   27,
 /*    90 */    27,   27,   27,   27,   27,   27,   17,
};
#define AA_SHIFT_USE_DFLT (-3)
static signed char aa_shift_ofst[] = {
 /*     0 */    11,   18,   66,   -3,   40,   29,   -2,   72,   -3,   13,
 /*    10 */    -3,   -3,   71,   28,   -3,   -3,   -3,   -3,   -3,   -3,
 /*    20 */    -3,   -3,   -3,   -3,   13,   73,   -3,   -3,   74,   28,
 /*    30 */    -3,   13,   79,   -3,   28,   -3,   28,   -3,   -3,   -3,
};
#define AA_REDUCE_USE_DFLT (-21)
static signed char aa_reduce_ofst[] = {
 /*     0 */    43,  -21,    6,  -21,  -21,  -21,   23,  -21,  -21,   45,
 /*    10 */   -21,  -21,  -21,  -20,  -21,  -21,  -21,  -21,  -21,  -21,
 /*    20 */   -21,  -21,  -21,  -21,   30,  -21,  -21,  -21,  -21,   -5,
 /*    30 */   -21,   35,  -21,  -21,   10,  -21,   50,  -21,  -21,  -21,
};
static AAACTIONTYPE aa_default[] = {
 /*     0 */    65,   65,   65,   42,   65,   46,   65,   65,   44,   65,
 /*    10 */    47,   49,   58,   65,   50,   54,   55,   56,   57,   58,
 /*    20 */    59,   60,   61,   62,   65,   65,   63,   48,   56,   65,
 /*    30 */    52,   65,   65,   64,   65,   53,   65,   51,   45,   43,
};
#define AA_SZ_ACTTAB (sizeof(aa_action)/sizeof(aa_action[0]))

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
#ifdef AAFALLBACK
static const AACODETYPE aaFallback[] = {
};
#endif /* AAFALLBACK */

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
struct aaStackEntry {
  int stateno;       /* The state-number */
  int major;         /* The major token value.  This is the code
                     ** number for the token at this stack level */
  AAMINORTYPE minor; /* The user-supplied minor token value.  This
                     ** is the value of the token  */
};
typedef struct aaStackEntry aaStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct aaParser {
  int aaidx;                    /* Index of top element in stack */
  int aaerrcnt;                 /* Shifts left before out of the error */
  phannot_ARG_SDECL                /* A place to hold %extra_argument */
  aaStackEntry aastack[AASTACKDEPTH];  /* The parser's stack */
};
typedef struct aaParser aaParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *aaTraceFILE = 0;
static char *aaTracePrompt = 0;
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
  aaTraceFILE = TraceFILE;
  aaTracePrompt = zTracePrompt;
  if( aaTraceFILE==0 ) aaTracePrompt = 0;
  else if( aaTracePrompt==0 ) aaTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *aaTokenName[] = { 
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
static const char *aaRuleName[] = {
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
  if( tokenType>0 && tokenType<(sizeof(aaTokenName)/sizeof(aaTokenName[0])) ){
    return aaTokenName[tokenType];
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
  aaParser *pParser;
  pParser = (aaParser*)(*mallocProc)( (size_t)sizeof(aaParser) );
  if( pParser ){
    pParser->aaidx = -1;
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "aamajor" is the symbol code, and "aapminor" is a pointer to
** the value.
*/
static void aa_destructor(AACODETYPE aamajor, AAMINORTYPE *aapminor){
  switch( aamajor ){
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
// 196 "parser.lemon"
{
	if ((aapminor->aa0)) {
		if ((aapminor->aa0)->free_flag) {
			efree((aapminor->aa0)->token);
		}
		efree((aapminor->aa0));
	}
}
// 499 "parser.c"
      break;
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
// 209 "parser.lemon"
{ zval_ptr_dtor(&(aapminor->aa36)); }
// 509 "parser.c"
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
static int aa_pop_parser_stack(aaParser *pParser){
  AACODETYPE aamajor;
  aaStackEntry *aatos = &pParser->aastack[pParser->aaidx];

  if( pParser->aaidx<0 ) return 0;
#ifndef NDEBUG
  if( aaTraceFILE && pParser->aaidx>=0 ){
    fprintf(aaTraceFILE,"%sPopping %s\n",
      aaTracePrompt,
      aaTokenName[aatos->major]);
  }
#endif
  aamajor = aatos->major;
  aa_destructor( aamajor, &aatos->minor);
  pParser->aaidx--;
  return aamajor;
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
  aaParser *pParser = (aaParser*)p;
  if( pParser==0 ) return;
  while( pParser->aaidx>=0 ) aa_pop_parser_stack(pParser);
  (*freeProc)((void*)pParser);
}

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is AANOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return AA_NO_ACTION.
*/
static int aa_find_shift_action(
  aaParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->aastack[pParser->aaidx].stateno;
 
  /* if( pParser->aaidx<0 ) return AA_NO_ACTION;  */
  i = aa_shift_ofst[stateno];
  if( i==AA_SHIFT_USE_DFLT ){
    return aa_default[stateno];
  }
  if( iLookAhead==AANOCODE ){
    return AA_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=AA_SZ_ACTTAB || aa_lookahead[i]!=iLookAhead ){
#ifdef AAFALLBACK
    int iFallback;            /* Fallback token */
    if( iLookAhead<sizeof(aaFallback)/sizeof(aaFallback[0])
           && (iFallback = aaFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
      if( aaTraceFILE ){
        fprintf(aaTraceFILE, "%sFALLBACK %s => %s\n",
           aaTracePrompt, aaTokenName[iLookAhead], aaTokenName[iFallback]);
      }
#endif
      return aa_find_shift_action(pParser, iFallback);
    }
#endif
    return aa_default[stateno];
  }else{
    return aa_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is AANOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return AA_NO_ACTION.
*/
static int aa_find_reduce_action(
  aaParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->aastack[pParser->aaidx].stateno;
 
  i = aa_reduce_ofst[stateno];
  if( i==AA_REDUCE_USE_DFLT ){
    return aa_default[stateno];
  }
  if( iLookAhead==AANOCODE ){
    return AA_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=AA_SZ_ACTTAB || aa_lookahead[i]!=iLookAhead ){
    return aa_default[stateno];
  }else{
    return aa_action[i];
  }
}

/*
** Perform a shift action.
*/
static void aa_shift(
  aaParser *aapParser,          /* The parser to be shifted */
  int aaNewState,               /* The new state to shift in */
  int aaMajor,                  /* The major token to shift in */
  AAMINORTYPE *aapMinor         /* Pointer ot the minor token to shift in */
){
  aaStackEntry *aatos;
  aapParser->aaidx++;
  if( aapParser->aaidx>=AASTACKDEPTH ){
     phannot_ARG_FETCH;
     aapParser->aaidx--;
#ifndef NDEBUG
     if( aaTraceFILE ){
       fprintf(aaTraceFILE,"%sStack Overflow!\n",aaTracePrompt);
     }
#endif
     while( aapParser->aaidx>=0 ) aa_pop_parser_stack(aapParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     phannot_ARG_STORE; /* Suppress warning about unused %extra_argument var */
     return;
  }
  aatos = &aapParser->aastack[aapParser->aaidx];
  aatos->stateno = aaNewState;
  aatos->major = aaMajor;
  aatos->minor = *aapMinor;
#ifndef NDEBUG
  if( aaTraceFILE && aapParser->aaidx>0 ){
    int i;
    fprintf(aaTraceFILE,"%sShift %d\n",aaTracePrompt,aaNewState);
    fprintf(aaTraceFILE,"%sStack:",aaTracePrompt);
    for(i=1; i<=aapParser->aaidx; i++)
      fprintf(aaTraceFILE," %s",aaTokenName[aapParser->aastack[i].major]);
    fprintf(aaTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static struct {
  AACODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} aaRuleInfo[] = {
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

static void aa_accept(aaParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void aa_reduce(
  aaParser *aapParser,         /* The parser */
  int aaruleno                 /* Number of the rule by which to reduce */
){
  int aagoto;                     /* The next state */
  int aaact;                      /* The next action */
  AAMINORTYPE aagotominor;        /* The LHS of the rule reduced */
  aaStackEntry *aamsp;            /* The top of the parser's stack */
  int aasize;                     /* Amount to pop the stack */
  phannot_ARG_FETCH;
  aamsp = &aapParser->aastack[aapParser->aaidx];
#ifndef NDEBUG
  if( aaTraceFILE && aaruleno>=0 
        && aaruleno<sizeof(aaRuleName)/sizeof(aaRuleName[0]) ){
    fprintf(aaTraceFILE, "%sReduce [%s].\n", aaTracePrompt,
      aaRuleName[aaruleno]);
  }
#endif /* NDEBUG */

  switch( aaruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  // <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  // <lineno> <thisfile>
  **     break;
  */
      case 0:
// 205 "parser.lemon"
{
	status->ret = aamsp[0].minor.aa36;
}
// 751 "parser.c"
        break;
      case 1:
      case 14:
      case 15:
// 211 "parser.lemon"
{
	aagotominor.aa36 = aamsp[0].minor.aa36;
}
// 760 "parser.c"
        break;
      case 2:
// 217 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_zval_list(aamsp[-1].minor.aa36, aamsp[0].minor.aa36);
}
// 767 "parser.c"
        break;
      case 3:
      case 8:
// 221 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_zval_list(NULL, aamsp[0].minor.aa36);
}
// 775 "parser.c"
        break;
      case 4:
// 228 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_annotation(aamsp[-3].minor.aa0, aamsp[-1].minor.aa36, status->scanner_state);
  aa_destructor(2,&aamsp[-4].minor);
  aa_destructor(4,&aamsp[-2].minor);
  aa_destructor(5,&aamsp[0].minor);
}
// 785 "parser.c"
        break;
      case 5:
// 232 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_annotation(aamsp[-2].minor.aa0, NULL, status->scanner_state);
  aa_destructor(2,&aamsp[-3].minor);
  aa_destructor(4,&aamsp[-1].minor);
  aa_destructor(5,&aamsp[0].minor);
}
// 795 "parser.c"
        break;
      case 6:
// 236 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_annotation(aamsp[0].minor.aa0, NULL, status->scanner_state);
  aa_destructor(2,&aamsp[-1].minor);
}
// 803 "parser.c"
        break;
      case 7:
// 242 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_zval_list(aamsp[-2].minor.aa36, aamsp[0].minor.aa36);
  aa_destructor(1,&aamsp[-1].minor);
}
// 811 "parser.c"
        break;
      case 9:
// 252 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_named_item(NULL, aamsp[0].minor.aa36);
}
// 818 "parser.c"
        break;
      case 10:
      case 12:
// 256 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_named_item(aamsp[-2].minor.aa0, aamsp[0].minor.aa36);
  aa_destructor(7,&aamsp[-1].minor);
}
// 827 "parser.c"
        break;
      case 11:
      case 13:
// 260 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_named_item(aamsp[-2].minor.aa0, aamsp[0].minor.aa36);
  aa_destructor(8,&aamsp[-1].minor);
}
// 836 "parser.c"
        break;
      case 16:
// 282 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_literal_zval(PHANNOT_T_IDENTIFIER, aamsp[0].minor.aa0);
}
// 843 "parser.c"
        break;
      case 17:
// 286 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_literal_zval(PHANNOT_T_INTEGER, aamsp[0].minor.aa0);
}
// 850 "parser.c"
        break;
      case 18:
// 290 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_literal_zval(PHANNOT_T_STRING, aamsp[0].minor.aa0);
}
// 857 "parser.c"
        break;
      case 19:
// 294 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_literal_zval(PHANNOT_T_DOUBLE, aamsp[0].minor.aa0);
}
// 864 "parser.c"
        break;
      case 20:
// 298 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_literal_zval(PHANNOT_T_NULL, NULL);
  aa_destructor(11,&aamsp[0].minor);
}
// 872 "parser.c"
        break;
      case 21:
// 302 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_literal_zval(PHANNOT_T_FALSE, NULL);
  aa_destructor(12,&aamsp[0].minor);
}
// 880 "parser.c"
        break;
      case 22:
// 306 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_literal_zval(PHANNOT_T_TRUE, NULL);
  aa_destructor(13,&aamsp[0].minor);
}
// 888 "parser.c"
        break;
      case 23:
// 310 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_array(aamsp[-1].minor.aa36);
  aa_destructor(14,&aamsp[-2].minor);
  aa_destructor(15,&aamsp[0].minor);
}
// 897 "parser.c"
        break;
      case 24:
// 314 "parser.lemon"
{
	aagotominor.aa36 = phannot_ret_array(aamsp[-1].minor.aa36);
  aa_destructor(16,&aamsp[-2].minor);
  aa_destructor(17,&aamsp[0].minor);
}
// 906 "parser.c"
        break;
  };
  aagoto = aaRuleInfo[aaruleno].lhs;
  aasize = aaRuleInfo[aaruleno].nrhs;
  aapParser->aaidx -= aasize;
  aaact = aa_find_reduce_action(aapParser,aagoto);
  if( aaact < AANSTATE ){
    aa_shift(aapParser,aaact,aagoto,&aagotominor);
  }else if( aaact == AANSTATE + AANRULE + 1 ){
    aa_accept(aapParser);
  }
}

/*
** The following code executes when the parse fails
*/
static void aa_parse_failed(
  aaParser *aapParser           /* The parser */
){
  phannot_ARG_FETCH;
#ifndef NDEBUG
  if( aaTraceFILE ){
    fprintf(aaTraceFILE,"%sFail!\n",aaTracePrompt);
  }
#endif
  while( aapParser->aaidx>=0 ) aa_pop_parser_stack(aapParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  phannot_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void aa_syntax_error(
  aaParser *aapParser,           /* The parser */
  int aamajor,                   /* The major type of the error token */
  AAMINORTYPE aaminor            /* The minor type of the error token */
){
  phannot_ARG_FETCH;
#define ATOKEN (aaminor.aa0)
// 151 "parser.lemon"

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

// 993 "parser.c"
  phannot_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void aa_accept(
  aaParser *aapParser           /* The parser */
){
  phannot_ARG_FETCH;
#ifndef NDEBUG
  if( aaTraceFILE ){
    fprintf(aaTraceFILE,"%sAccept!\n",aaTracePrompt);
  }
#endif
  while( aapParser->aaidx>=0 ) aa_pop_parser_stack(aapParser);
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
  void *aap,                   /* The parser */
  int aamajor,                 /* The major token code number */
  phannot_TOKENTYPE aaminor       /* The value for the token */
  phannot_ARG_PDECL               /* Optional %extra_argument parameter */
){
  AAMINORTYPE aaminorunion;
  int aaact;            /* The parser action. */
  int aaendofinput;     /* True if we are at the end of input */
  int aaerrorhit = 0;   /* True if aamajor has invoked an error */
  aaParser *aapParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  aapParser = (aaParser*)aap;
  if( aapParser->aaidx<0 ){
    if( aamajor==0 ) return;
    aapParser->aaidx = 0;
    aapParser->aaerrcnt = -1;
    aapParser->aastack[0].stateno = 0;
    aapParser->aastack[0].major = 0;
  }
  aaminorunion.aa0 = aaminor;
  aaendofinput = (aamajor==0);
  phannot_ARG_STORE;

#ifndef NDEBUG
  if( aaTraceFILE ){
    fprintf(aaTraceFILE,"%sInput %s\n",aaTracePrompt,aaTokenName[aamajor]);
  }
#endif

  do{
    aaact = aa_find_shift_action(aapParser,aamajor);
    if( aaact<AANSTATE ){
      aa_shift(aapParser,aaact,aamajor,&aaminorunion);
      aapParser->aaerrcnt--;
      if( aaendofinput && aapParser->aaidx>=0 ){
        aamajor = 0;
      }else{
        aamajor = AANOCODE;
      }
    }else if( aaact < AANSTATE + AANRULE ){
      aa_reduce(aapParser,aaact-AANSTATE);
    }else if( aaact == AA_ERROR_ACTION ){
      int aamx;
#ifndef NDEBUG
      if( aaTraceFILE ){
        fprintf(aaTraceFILE,"%sSyntax Error!\n",aaTracePrompt);
      }
#endif
#ifdef AAERRORSYMBOL
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
      if( aapParser->aaerrcnt<0 ){
        aa_syntax_error(aapParser,aamajor,aaminorunion);
      }
      aamx = aapParser->aastack[aapParser->aaidx].major;
      if( aamx==AAERRORSYMBOL || aaerrorhit ){
#ifndef NDEBUG
        if( aaTraceFILE ){
          fprintf(aaTraceFILE,"%sDiscard input token %s\n",
             aaTracePrompt,aaTokenName[aamajor]);
        }
#endif
        aa_destructor(aamajor,&aaminorunion);
        aamajor = AANOCODE;
      }else{
         while(
          aapParser->aaidx >= 0 &&
          aamx != AAERRORSYMBOL &&
          (aaact = aa_find_shift_action(aapParser,AAERRORSYMBOL)) >= AANSTATE
        ){
          aa_pop_parser_stack(aapParser);
        }
        if( aapParser->aaidx < 0 || aamajor==0 ){
          aa_destructor(aamajor,&aaminorunion);
          aa_parse_failed(aapParser);
          aamajor = AANOCODE;
        }else if( aamx!=AAERRORSYMBOL ){
          AAMINORTYPE u2;
          u2.AAERRSYMDT = 0;
          aa_shift(aapParser,aaact,AAERRORSYMBOL,&u2);
        }
      }
      aapParser->aaerrcnt = 3;
      aaerrorhit = 1;
#else  /* AAERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( aapParser->aaerrcnt<=0 ){
        aa_syntax_error(aapParser,aamajor,aaminorunion);
      }
      aapParser->aaerrcnt = 3;
      aa_destructor(aamajor,&aaminorunion);
      if( aaendofinput ){
        aa_parse_failed(aapParser);
      }
      aamajor = AANOCODE;
#endif
    }else{
      aa_accept(aapParser);
      aamajor = AANOCODE;
    }
  }while( aamajor!=AANOCODE && aapParser->aaidx>=0 );
  return;
}

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

const phannot_token_names phannot_tokens[] =
{
	{ "INTEGER",        PHANNOT_T_INTEGER },
	{ "DOUBLE",         PHANNOT_T_DOUBLE },
	{ "STRING",         PHANNOT_T_STRING },
	{ "IDENTIFIER",     PHANNOT_T_IDENTIFIER },
	{ "@",              PHANNOT_T_AT },
	{ ",",              PHANNOT_T_COMMA },
	{ "=",              PHANNOT_T_EQUALS },
	{ ":",              PHANNOT_T_COLON },
	{ "(",              PHANNOT_T_PARENTHESES_OPEN },
	{ ")",              PHANNOT_T_PARENTHESES_CLOSE },
	{ "{",              PHANNOT_T_BRACKET_OPEN },
	{ "}",              PHANNOT_T_BRACKET_CLOSE },
 	{ "[",              PHANNOT_T_SBRACKET_OPEN },
	{ "]",              PHANNOT_T_SBRACKET_CLOSE },
	{ "ARBITRARY TEXT", PHANNOT_T_ARBITRARY_TEXT },
	{ NULL, 0 }
};

/**
 * Wrapper to alloc memory within the parser
 */
static void *phannot_wrapper_alloc(size_t bytes){
	return emalloc(bytes);
}

/**
 * Wrapper to free memory within the parser
 */
static void phannot_wrapper_free(void *pointer){
	efree(pointer);
}

/**
 * Creates a parser_token to be passed to the parser
 */
static void phannot_parse_with_token(void* phannot_parser, int opcode, int parsercode, phannot_scanner_token *token, phannot_parser_status *parser_status){

	phannot_parser_token *pToken;

	pToken = emalloc(sizeof(phannot_parser_token));
	pToken->opcode = opcode;
	pToken->token = token->value;
	pToken->token_len = token->len;
	pToken->free_flag = 1;

	phannot_(phannot_parser, parsercode, pToken, parser_status);

	token->value = NULL;
	token->len = 0;
}

/**
 * Creates an error message when it's triggered by the scanner
 */
static void phannot_scanner_error_msg(phannot_parser_status *parser_status, char **error_msg TSRMLS_DC){

	phannot_scanner_state *state = parser_status->scanner_state;

	if (state->start) {
		if (state->start_length > 16) {
			spprintf(error_msg, 0, "Scanning error before '%.16s...' in %s on line %d", state->start, state->active_file, state->active_line);
		} else {
			spprintf(error_msg, 0, "Scanning error before '%s' in %s on line %d", state->start, state->active_file, state->active_line);
		}
	} else {
		spprintf(error_msg, 0, "Scanning error near to EOF in %s", state->active_file);
	}
}

/**
 * Receives the comment tokenizes and parses it
 */
int phannot_parse_annotations(zval *result, zval *comment, zval *file_path, zval *line TSRMLS_DC) {

	char *comment_str;
	zend_uint comment_len;
	char *file_path_str;
	zend_uint line_num;

	char *error_msg = NULL;

	ZVAL_NULL(result);

	if (Z_TYPE_P(comment) == IS_STRING) {
		comment_str = Z_STRVAL_P(comment);
		comment_len = Z_STRLEN_P(comment);
	} else {
		comment_str = "";
		comment_len = 0;
	}

	if (Z_TYPE_P(file_path) == IS_STRING) {
		file_path_str = Z_STRVAL_P(file_path);
	} else {
		file_path_str = "eval";
	}

	if (Z_TYPE_P(line) == IS_LONG) {
		line_num = Z_LVAL_P(line);
	} else {
		line_num = 0;
	}

	if (phannot_internal_parse_annotations(&result, comment_str, comment_len, file_path_str, line_num, &error_msg TSRMLS_CC) == FAILURE) {
		if (likely(error_msg != NULL)) {
			zephir_throw_exception_string(phalcon_annotations_exception_ce, error_msg, strlen(error_msg) TSRMLS_CC);
			efree(error_msg);
		}
		else {
			zephir_throw_exception_string(phalcon_annotations_exception_ce, SL("There was an error parsing annotation") TSRMLS_CC);
		}

		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Remove comment separators from a docblock
 */
static void phannot_remove_comment_separators(char **ret, zend_uint *ret_len, const char *comment, zend_uint length, zend_uint *start_lines)
{
	int start_mode = 1, j, i, open_parentheses;
	smart_str processed_str = {0};
	char ch;

	(*start_lines) = 0;

	for (i = 0; i < length; i++) {

		ch = comment[i];

		if (start_mode) {
			if (ch == ' ' || ch == '*' || ch == '/' || ch == '\t' || ch == 11) {
				continue;
			}
			start_mode = 0;
		}

		if (ch == '@') {

			smart_str_appendc(&processed_str, ch);
			i++;

			open_parentheses = 0;
			for (j = i; j < length; j++) {

				ch = comment[j];

				if (start_mode) {
					if (ch == ' ' || ch == '*' || ch == '/' || ch == '\t' || ch == 11) {
						continue;
					}
					start_mode = 0;
				}

				if (open_parentheses == 0) {

					if (isalnum(ch) || '_' == ch || '\\' == ch) {
						smart_str_appendc(&processed_str, ch);
						continue;
					}

					if (ch == '(') {
						smart_str_appendc(&processed_str, ch);
						open_parentheses++;
						continue;
					}

				} else {

					smart_str_appendc(&processed_str, ch);

					if (ch == '(') {
						open_parentheses++;
					} else if (ch == ')') {
						open_parentheses--;
					} else if (ch == '\n') {
						(*start_lines)++;
						start_mode = 1;
					}

					if (open_parentheses > 0) {
						continue;
					}
				}

				i = j;
				smart_str_appendc(&processed_str, ' ');
				break;
			}
		}

		if (ch == '\n') {
			(*start_lines)++;
			start_mode = 1;
		}
	}

	smart_str_0(&processed_str);

	if (processed_str.len) {
		*ret     = processed_str.c;
		*ret_len = processed_str.len;
	} else {
		*ret     = NULL;
		*ret_len = 0;
	}
}

/**
 * Parses a comment returning an intermediate array representation
 */
int phannot_internal_parse_annotations(zval **result, const char *comment, zend_uint comment_len, const char *file_path, zend_uint line, char **error_msg TSRMLS_DC)
{
	phannot_scanner_state *state;
	phannot_scanner_token token;
	zend_uint start_lines;
	int scanner_status, status = SUCCESS;
	phannot_parser_status *parser_status = NULL;
	void* phannot_parser;
	char *processed_comment;
	zend_uint processed_comment_len;

	*error_msg = NULL;

	/**
	 * Check if the comment has content
	 */
	if (UNEXPECTED(!comment)) {
		ZVAL_BOOL(*result, 0);
		spprintf(error_msg, 0, "Empty annotation");
		return FAILURE;
	}

	if (comment_len < 2) {
		ZVAL_BOOL(*result, 0);
		return SUCCESS;
	}

	/**
	 * Remove comment separators
	 */
	phannot_remove_comment_separators(&processed_comment, &processed_comment_len, comment, comment_len, &start_lines);

	if (processed_comment_len < 2) {
		ZVAL_BOOL(*result, 0);
		if (processed_comment) {
			efree(processed_comment);
		}

		return SUCCESS;
	}

	/**
	 * Start the reentrant parser
	 */
	phannot_parser = phannot_Alloc(phannot_wrapper_alloc);
	if (unlikely(!phannot_parser)) {
		ZVAL_BOOL(*result, 0);
		return FAILURE;
	}

	parser_status = emalloc(sizeof(phannot_parser_status) + sizeof(phannot_scanner_state));
	state         = (phannot_scanner_state*)((char*)parser_status + sizeof(phannot_parser_status));

	parser_status->status = PHANNOT_PARSING_OK;
	parser_status->scanner_state = state;
	parser_status->ret = NULL;
	parser_status->token = &token;
	parser_status->syntax_error = NULL;

	/**
	 * Initialize the scanner state
	 */
	state->active_token = 0;
	state->start = processed_comment;
	state->start_length = 0;
	state->mode = PHANNOT_MODE_RAW;
	state->active_file = file_path;

	token.value = NULL;
	token.len = 0;

	/**
	 * Possible start line
	 */
	if (line) {
		state->active_line = line - start_lines;
	} else {
		state->active_line = 1;
	}

	state->end = state->start;

	while(0 <= (scanner_status = phannot_get_token(state, &token))) {

		state->active_token = token.opcode;

		state->start_length = processed_comment + processed_comment_len - state->start;

		switch (token.opcode) {

			case PHANNOT_T_IGNORE:
				break;

			case PHANNOT_T_AT:
				phannot_(phannot_parser, PHANNOT_AT, NULL, parser_status);
				break;
			case PHANNOT_T_COMMA:
				phannot_(phannot_parser, PHANNOT_COMMA, NULL, parser_status);
				break;
			case PHANNOT_T_EQUALS:
				phannot_(phannot_parser, PHANNOT_EQUALS, NULL, parser_status);
				break;
			case PHANNOT_T_COLON:
				phannot_(phannot_parser, PHANNOT_COLON, NULL, parser_status);
				break;

			case PHANNOT_T_PARENTHESES_OPEN:
				phannot_(phannot_parser, PHANNOT_PARENTHESES_OPEN, NULL, parser_status);
				break;
			case PHANNOT_T_PARENTHESES_CLOSE:
				phannot_(phannot_parser, PHANNOT_PARENTHESES_CLOSE, NULL, parser_status);
				break;

			case PHANNOT_T_BRACKET_OPEN:
				phannot_(phannot_parser, PHANNOT_BRACKET_OPEN, NULL, parser_status);
				break;
			case PHANNOT_T_BRACKET_CLOSE:
				phannot_(phannot_parser, PHANNOT_BRACKET_CLOSE, NULL, parser_status);
				break;

			case PHANNOT_T_SBRACKET_OPEN:
				phannot_(phannot_parser, PHANNOT_SBRACKET_OPEN, NULL, parser_status);
				break;
			case PHANNOT_T_SBRACKET_CLOSE:
				phannot_(phannot_parser, PHANNOT_SBRACKET_CLOSE, NULL, parser_status);
				break;

			case PHANNOT_T_NULL:
				phannot_(phannot_parser, PHANNOT_NULL, NULL, parser_status);
				break;
			case PHANNOT_T_TRUE:
				phannot_(phannot_parser, PHANNOT_TRUE, NULL, parser_status);
				break;
			case PHANNOT_T_FALSE:
				phannot_(phannot_parser, PHANNOT_FALSE, NULL, parser_status);
				break;

			case PHANNOT_T_INTEGER:
				phannot_parse_with_token(phannot_parser, PHANNOT_T_INTEGER, PHANNOT_INTEGER, &token, parser_status);
				break;
			case PHANNOT_T_DOUBLE:
				phannot_parse_with_token(phannot_parser, PHANNOT_T_DOUBLE, PHANNOT_DOUBLE, &token, parser_status);
				break;
			case PHANNOT_T_STRING:
				phannot_parse_with_token(phannot_parser, PHANNOT_T_STRING, PHANNOT_STRING, &token, parser_status);
				break;
			case PHANNOT_T_IDENTIFIER:
				phannot_parse_with_token(phannot_parser, PHANNOT_T_IDENTIFIER, PHANNOT_IDENTIFIER, &token, parser_status);
				break;
			/*case PHANNOT_T_ARBITRARY_TEXT:
				phannot_parse_with_token(phannot_parser, PHANNOT_T_ARBITRARY_TEXT, PHANNOT_ARBITRARY_TEXT, &token, parser_status);
				break;*/

			default:
				parser_status->status = PHANNOT_PARSING_FAILED;
				if (!*error_msg) {
					spprintf(error_msg, 0, "Scanner: unknown opcode %d on in %s line %d", token.opcode, state->active_file, state->active_line);
				}
				break;
		}

		if (parser_status->status != PHANNOT_PARSING_OK) {
			status = FAILURE;
			break;
		}

		state->end = state->start;
	}

	if (status != FAILURE) {
		switch (scanner_status) {
			case PHANNOT_SCANNER_RETCODE_ERR:
			case PHANNOT_SCANNER_RETCODE_IMPOSSIBLE:
				if (!*error_msg) {
					phannot_scanner_error_msg(parser_status, error_msg TSRMLS_CC);
				}
				status = FAILURE;
				break;
			default:
				phannot_(phannot_parser, 0, NULL, parser_status);
		}
	}

	state->active_token = 0;
	state->start = NULL;

	if (parser_status->status != PHANNOT_PARSING_OK) {
		status = FAILURE;
		if (parser_status->syntax_error) {
			if (!*error_msg) {
				*error_msg = parser_status->syntax_error;
			}
			else {
				efree(parser_status->syntax_error);
			}
		}
	}

	phannot_Free(phannot_parser, phannot_wrapper_free);

	if (status != FAILURE) {
		if (parser_status->status == PHANNOT_PARSING_OK) {
			if (parser_status->ret) {
				ZVAL_ZVAL(*result, parser_status->ret, 0, 0);
				ZVAL_NULL(parser_status->ret);
				zval_ptr_dtor(&parser_status->ret);
			} else {
				array_init(*result);
			}
		}
	}

	efree(processed_comment);
	efree(parser_status);

	return status;
}
