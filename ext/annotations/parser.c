/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
/* #line 28 "parser.y" */


#include "php_phalcon.h"

#include <ext/standard/php_smart_str.h>
#include <main/spprintf.h>

#include "annotations/parser.h"
#include "annotations/scanner.h"
#include "annotations/annot.h"
#include "annotations/exception.h"

#include "kernel/main.h"
#include "kernel/exception.h"

#include "interned-strings.h"

static zval *phannot_ret_literal_zval(int type, phannot_parser_token *T)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, phalcon_interned_type, type);
	if (T) {
		add_assoc_stringl(ret, phalcon_interned_value, T->token, T->token_len, 0);
		efree(T);
	}

	return ret;
}

static zval *phannot_ret_array(zval *items)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, phalcon_interned_type, PHANNOT_T_ARRAY);

	if (items) {
		add_assoc_zval(ret, phalcon_interned_items, items);
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
	add_assoc_zval(ret, phalcon_interned_expr, expr);
	if (name != NULL) {
		add_assoc_stringl(ret, phalcon_interned_name, name->token, name->token_len, 0);
		efree(name);
	}

	return ret;
}

static zval *phannot_ret_annotation(phannot_parser_token *name, zval *arguments, phannot_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 5);

	add_assoc_long(ret, phalcon_interned_type, PHANNOT_T_ANNOTATION);

	if (name) {
		add_assoc_stringl(ret, phalcon_interned_name, name->token, name->token_len, 0);
		efree(name);
	}

	if (arguments) {
		add_assoc_zval(ret, phalcon_interned_arguments, arguments);
	}

	add_assoc_string(ret, phalcon_interned_file, (char*)state->active_file, !IS_INTERNED(state->active_file));
	add_assoc_long(ret, phalcon_interned_line, state->active_line);

	return ret;
}


/* #line 133 "parser.c" */
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
**    JJCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    JJNOCODE           is a number of type JJCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    JJFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    JJACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    phannot_JTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    JJMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is phannot_JTOKENTYPE.  The entry in the union
**                       for base tokens is called "jj0".
**    JJSTACKDEPTH       is the maximum depth of the parser's stack.
**    phannot_ARG_SDECL     A static variable declaration for the %extra_argument
**    phannot_ARG_PDECL     A parameter declaration for the %extra_argument
**    phannot_ARG_STORE     Code to store %extra_argument into jjpParser
**    phannot_ARG_FETCH     Code to extract %extra_argument from jjpParser
**    JJNSTATE           the combined number of states.
**    JJNRULE            the number of rules in the grammar
**    JJERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define JJCODETYPE unsigned char
#define JJNOCODE 28
#define JJACTIONTYPE unsigned char
#define phannot_JTOKENTYPE phannot_parser_token*
typedef union {
  phannot_JTOKENTYPE jj0;
  zval* jj36;
  int jj55;
} JJMINORTYPE;
#define JJSTACKDEPTH 100
#define phannot_ARG_SDECL phannot_parser_status *status;
#define phannot_ARG_PDECL ,phannot_parser_status *status
#define phannot_ARG_FETCH phannot_parser_status *status = jjpParser->status
#define phannot_ARG_STORE jjpParser->status = status
#define JJNSTATE 40
#define JJNRULE 25
#define JJERRORSYMBOL 18
#define JJERRSYMDT jj55
#define JJ_NO_ACTION      (JJNSTATE+JJNRULE+2)
#define JJ_ACCEPT_ACTION  (JJNSTATE+JJNRULE+1)
#define JJ_ERROR_ACTION   (JJNSTATE+JJNRULE)

/* Next are that tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < JJNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   JJNSTATE <= N < JJNSTATE+JJNRULE   Reduce by rule N-JJNSTATE.
**
**   N == JJNSTATE+JJNRULE              A syntax error has occurred.
**
**   N == JJNSTATE+JJNRULE+1            The parser accepts its input.
**
**   N == JJNSTATE+JJNRULE+2            No such action.  Denotes unused
**                                      slots in the jj_action[] table.
**
** The action table is constructed as a single large table named jj_action[].
** Given state S and lookahead X, the action is computed as
**
**      jj_action[ jj_shift_ofst[S] + X ]
**
** If the index value jj_shift_ofst[S]+X is out of range or if the value
** jj_lookahead[jj_shift_ofst[S]+X] is not equal to X or if jj_shift_ofst[S]
** is equal to JJ_SHIFT_USE_DFLT, it means that the action is not in the table
** and that jj_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the jj_reduce_ofst[] array is used in place of
** the jj_shift_ofst[] array and JJ_REDUCE_USE_DFLT is used in place of
** JJ_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  jj_action[]        A single table containing all actions.
**  jj_lookahead[]     A table containing the lookahead for each entry in
**                     jj_action.  Used to detect hash collisions.
**  jj_shift_ofst[]    For each state, the offset into jj_action for
**                     shifting terminals.
**  jj_reduce_ofst[]   For each state, the offset into jj_action for
**                     shifting non-terminals after a reduce.
**  jj_default[]       Default action for each state.
*/
static JJACTIONTYPE jj_action[] = {
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
static JJCODETYPE jj_lookahead[] = {
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
#define JJ_SHIFT_USE_DFLT (-3)
static signed char jj_shift_ofst[] = {
 /*     0 */    11,   18,   66,   -3,   40,   29,   -2,   72,   -3,   13,
 /*    10 */    -3,   -3,   71,   28,   -3,   -3,   -3,   -3,   -3,   -3,
 /*    20 */    -3,   -3,   -3,   -3,   13,   73,   -3,   -3,   74,   28,
 /*    30 */    -3,   13,   79,   -3,   28,   -3,   28,   -3,   -3,   -3,
};
#define JJ_REDUCE_USE_DFLT (-21)
static signed char jj_reduce_ofst[] = {
 /*     0 */    43,  -21,    6,  -21,  -21,  -21,   23,  -21,  -21,   45,
 /*    10 */   -21,  -21,  -21,  -20,  -21,  -21,  -21,  -21,  -21,  -21,
 /*    20 */   -21,  -21,  -21,  -21,   30,  -21,  -21,  -21,  -21,   -5,
 /*    30 */   -21,   35,  -21,  -21,   10,  -21,   50,  -21,  -21,  -21,
};
static JJACTIONTYPE jj_default[] = {
 /*     0 */    65,   65,   65,   42,   65,   46,   65,   65,   44,   65,
 /*    10 */    47,   49,   58,   65,   50,   54,   55,   56,   57,   58,
 /*    20 */    59,   60,   61,   62,   65,   65,   63,   48,   56,   65,
 /*    30 */    52,   65,   65,   64,   65,   53,   65,   51,   45,   43,
};
#define JJ_SZ_ACTTAB (sizeof(jj_action)/sizeof(jj_action[0]))

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
#ifdef JJFALLBACK
static const JJCODETYPE jjFallback[] = {
};
#endif /* JJFALLBACK */

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
struct jjStackEntry {
  int stateno;       /* The state-number */
  int major;         /* The major token value.  This is the code
                     ** number for the token at this stack level */
  JJMINORTYPE minor; /* The user-supplied minor token value.  This
                     ** is the value of the token  */
};
typedef struct jjStackEntry jjStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct jjParser {
  int jjidx;                    /* Index of top element in stack */
  int jjerrcnt;                 /* Shifts left before out of the error */
  phannot_ARG_SDECL                /* A place to hold %extra_argument */
  jjStackEntry jjstack[JJSTACKDEPTH];  /* The parser's stack */
};
typedef struct jjParser jjParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *jjTraceFILE = 0;
static char *jjTracePrompt = 0;
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
  jjTraceFILE = TraceFILE;
  jjTracePrompt = zTracePrompt;
  if( jjTraceFILE==0 ) jjTracePrompt = 0;
  else if( jjTracePrompt==0 ) jjTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *jjTokenName[] = { 
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
static const char *jjRuleName[] = {
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
  if( tokenType>0 && (size_t)tokenType<(sizeof(jjTokenName)/sizeof(jjTokenName[0])) ){
    return jjTokenName[tokenType];
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
  jjParser *pParser;
  pParser = (jjParser*)(*mallocProc)( (size_t)sizeof(jjParser) );
  if( pParser ){
    pParser->jjidx = -1;
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "jjmajor" is the symbol code, and "jjpminor" is a pointer to
** the value.
*/
static void jj_destructor(JJCODETYPE jjmajor, JJMINORTYPE *jjpminor){
  switch( jjmajor ){
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
/* #line 198 "parser.y" */
{
	if ((jjpminor->jj0)) {
		if ((jjpminor->jj0)->free_flag) {
			efree((jjpminor->jj0)->token);
		}
		efree((jjpminor->jj0));
	}
}
/* #line 501 "parser.c" */
      break;
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
/* #line 211 "parser.y" */
{ zval_ptr_dtor(&(jjpminor->jj36)); }
/* #line 511 "parser.c" */
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
static int jj_pop_parser_stack(jjParser *pParser){
  JJCODETYPE jjmajor;
  jjStackEntry *jjtos = &pParser->jjstack[pParser->jjidx];

  if( pParser->jjidx<0 ) return 0;
#ifndef NDEBUG
  if( jjTraceFILE && pParser->jjidx>=0 ){
    fprintf(jjTraceFILE,"%sPopping %s\n",
      jjTracePrompt,
      jjTokenName[jjtos->major]);
  }
#endif
  jjmajor = jjtos->major;
  jj_destructor( jjmajor, &jjtos->minor);
  pParser->jjidx--;
  return jjmajor;
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
  jjParser *pParser = (jjParser*)p;
  if( pParser==0 ) return;
  while( pParser->jjidx>=0 ) jj_pop_parser_stack(pParser);
  (*freeProc)((void*)pParser);
}

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is JJNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return JJ_NO_ACTION.
*/
static int jj_find_shift_action(
  jjParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->jjstack[pParser->jjidx].stateno;
 
  /* if( pParser->jjidx<0 ) return JJ_NO_ACTION;  */
  i = jj_shift_ofst[stateno];
  if( i==JJ_SHIFT_USE_DFLT ){
    return jj_default[stateno];
  }
  if( iLookAhead==JJNOCODE ){
    return JJ_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=(int)JJ_SZ_ACTTAB || jj_lookahead[i]!=iLookAhead ){
#ifdef JJFALLBACK
    int iFallback;            /* Fallback token */
    if( iLookAhead<sizeof(jjFallback)/sizeof(jjFallback[0])
           && (iFallback = jjFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
      if( jjTraceFILE ){
        fprintf(jjTraceFILE, "%sFALLBACK %s => %s\n",
           jjTracePrompt, jjTokenName[iLookAhead], jjTokenName[iFallback]);
      }
#endif
      return jj_find_shift_action(pParser, iFallback);
    }
#endif
    return jj_default[stateno];
  }else{
    return jj_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is JJNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return JJ_NO_ACTION.
*/
static int jj_find_reduce_action(
  jjParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->jjstack[pParser->jjidx].stateno;
 
  i = jj_reduce_ofst[stateno];
  if( i==JJ_REDUCE_USE_DFLT ){
    return jj_default[stateno];
  }
  if( iLookAhead==JJNOCODE ){
    return JJ_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=(int)JJ_SZ_ACTTAB || jj_lookahead[i]!=iLookAhead ){
    return jj_default[stateno];
  }else{
    return jj_action[i];
  }
}

/*
** Perform a shift action.
*/
static void jj_shift(
  jjParser *jjpParser,          /* The parser to be shifted */
  int jjNewState,               /* The new state to shift in */
  int jjMajor,                  /* The major token to shift in */
  JJMINORTYPE *jjpMinor         /* Pointer ot the minor token to shift in */
){
  jjStackEntry *jjtos;
  jjpParser->jjidx++;
  if( jjpParser->jjidx>=JJSTACKDEPTH ){
     phannot_ARG_FETCH;
     jjpParser->jjidx--;
#ifndef NDEBUG
     if( jjTraceFILE ){
       fprintf(jjTraceFILE,"%sStack Overflow!\n",jjTracePrompt);
     }
#endif
     while( jjpParser->jjidx>=0 ) jj_pop_parser_stack(jjpParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     phannot_ARG_STORE; /* Suppress warning about unused %extra_argument var */
     return;
  }
  jjtos = &jjpParser->jjstack[jjpParser->jjidx];
  jjtos->stateno = jjNewState;
  jjtos->major = jjMajor;
  jjtos->minor = *jjpMinor;
#ifndef NDEBUG
  if( jjTraceFILE && jjpParser->jjidx>0 ){
    int i;
    fprintf(jjTraceFILE,"%sShift %d\n",jjTracePrompt,jjNewState);
    fprintf(jjTraceFILE,"%sStack:",jjTracePrompt);
    for(i=1; i<=jjpParser->jjidx; i++)
      fprintf(jjTraceFILE," %s",jjTokenName[jjpParser->jjstack[i].major]);
    fprintf(jjTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static struct {
  JJCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} jjRuleInfo[] = {
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

static void jj_accept(jjParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void jj_reduce(
  jjParser *jjpParser,         /* The parser */
  int jjruleno                 /* Number of the rule by which to reduce */
){
  int jjgoto;                     /* The next state */
  int jjact;                      /* The next action */
  JJMINORTYPE jjgotominor;        /* The LHS of the rule reduced */
  jjStackEntry *jjmsp;            /* The top of the parser's stack */
  int jjsize;                     /* Amount to pop the stack */
  phannot_ARG_FETCH;
  jjmsp = &jjpParser->jjstack[jjpParser->jjidx];
#ifndef NDEBUG
  if( jjTraceFILE && jjruleno>=0 
        && jjruleno<(int)(sizeof(jjRuleName)/sizeof(jjRuleName[0])) ){
    fprintf(jjTraceFILE, "%sReduce [%s].\n", jjTracePrompt,
      jjRuleName[jjruleno]);
  }
#endif /* NDEBUG */

  switch( jjruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0:
/* #line 207 "parser.y" */
{
	status->ret = jjmsp[0].minor.jj36;
}
/* #line 753 "parser.c" */
        break;
      case 1:
      case 14:
      case 15:
/* #line 213 "parser.y" */
{
	jjgotominor.jj36 = jjmsp[0].minor.jj36;
}
/* #line 762 "parser.c" */
        break;
      case 2:
/* #line 219 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_zval_list(jjmsp[-1].minor.jj36, jjmsp[0].minor.jj36);
}
/* #line 769 "parser.c" */
        break;
      case 3:
      case 8:
/* #line 223 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_zval_list(NULL, jjmsp[0].minor.jj36);
}
/* #line 777 "parser.c" */
        break;
      case 4:
/* #line 230 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_annotation(jjmsp[-3].minor.jj0, jjmsp[-1].minor.jj36, status->scanner_state);
  jj_destructor(2,&jjmsp[-4].minor);
  jj_destructor(4,&jjmsp[-2].minor);
  jj_destructor(5,&jjmsp[0].minor);
}
/* #line 787 "parser.c" */
        break;
      case 5:
/* #line 234 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_annotation(jjmsp[-2].minor.jj0, NULL, status->scanner_state);
  jj_destructor(2,&jjmsp[-3].minor);
  jj_destructor(4,&jjmsp[-1].minor);
  jj_destructor(5,&jjmsp[0].minor);
}
/* #line 797 "parser.c" */
        break;
      case 6:
/* #line 238 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_annotation(jjmsp[0].minor.jj0, NULL, status->scanner_state);
  jj_destructor(2,&jjmsp[-1].minor);
}
/* #line 805 "parser.c" */
        break;
      case 7:
/* #line 244 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_zval_list(jjmsp[-2].minor.jj36, jjmsp[0].minor.jj36);
  jj_destructor(1,&jjmsp[-1].minor);
}
/* #line 813 "parser.c" */
        break;
      case 9:
/* #line 254 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_named_item(NULL, jjmsp[0].minor.jj36);
}
/* #line 820 "parser.c" */
        break;
      case 10:
      case 12:
/* #line 258 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_named_item(jjmsp[-2].minor.jj0, jjmsp[0].minor.jj36);
  jj_destructor(7,&jjmsp[-1].minor);
}
/* #line 829 "parser.c" */
        break;
      case 11:
      case 13:
/* #line 262 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_named_item(jjmsp[-2].minor.jj0, jjmsp[0].minor.jj36);
  jj_destructor(8,&jjmsp[-1].minor);
}
/* #line 838 "parser.c" */
        break;
      case 16:
/* #line 284 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_literal_zval(PHANNOT_T_IDENTIFIER, jjmsp[0].minor.jj0);
}
/* #line 845 "parser.c" */
        break;
      case 17:
/* #line 288 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_literal_zval(PHANNOT_T_INTEGER, jjmsp[0].minor.jj0);
}
/* #line 852 "parser.c" */
        break;
      case 18:
/* #line 292 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_literal_zval(PHANNOT_T_STRING, jjmsp[0].minor.jj0);
}
/* #line 859 "parser.c" */
        break;
      case 19:
/* #line 296 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_literal_zval(PHANNOT_T_DOUBLE, jjmsp[0].minor.jj0);
}
/* #line 866 "parser.c" */
        break;
      case 20:
/* #line 300 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_literal_zval(PHANNOT_T_NULL, NULL);
  jj_destructor(11,&jjmsp[0].minor);
}
/* #line 874 "parser.c" */
        break;
      case 21:
/* #line 304 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_literal_zval(PHANNOT_T_FALSE, NULL);
  jj_destructor(12,&jjmsp[0].minor);
}
/* #line 882 "parser.c" */
        break;
      case 22:
/* #line 308 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_literal_zval(PHANNOT_T_TRUE, NULL);
  jj_destructor(13,&jjmsp[0].minor);
}
/* #line 890 "parser.c" */
        break;
      case 23:
/* #line 312 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_array(jjmsp[-1].minor.jj36);
  jj_destructor(14,&jjmsp[-2].minor);
  jj_destructor(15,&jjmsp[0].minor);
}
/* #line 899 "parser.c" */
        break;
      case 24:
/* #line 316 "parser.y" */
{
	jjgotominor.jj36 = phannot_ret_array(jjmsp[-1].minor.jj36);
  jj_destructor(16,&jjmsp[-2].minor);
  jj_destructor(17,&jjmsp[0].minor);
}
/* #line 908 "parser.c" */
        break;
  };
  jjgoto = jjRuleInfo[jjruleno].lhs;
  jjsize = jjRuleInfo[jjruleno].nrhs;
  jjpParser->jjidx -= jjsize;
  jjact = jj_find_reduce_action(jjpParser,jjgoto);
  if( jjact < JJNSTATE ){
    jj_shift(jjpParser,jjact,jjgoto,&jjgotominor);
  }else if( jjact == JJNSTATE + JJNRULE + 1 ){
    jj_accept(jjpParser);
  }
}

/*
** The following code executes when the parse fails
*/
static void jj_parse_failed(
  jjParser *jjpParser           /* The parser */
){
  phannot_ARG_FETCH;
#ifndef NDEBUG
  if( jjTraceFILE ){
    fprintf(jjTraceFILE,"%sFail!\n",jjTracePrompt);
  }
#endif
  while( jjpParser->jjidx>=0 ) jj_pop_parser_stack(jjpParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  phannot_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void jj_syntax_error(
  jjParser *jjpParser,           /* The parser */
  int jjmajor,                   /* The major type of the error token */
  JJMINORTYPE jjminor            /* The minor type of the error token */
){
  phannot_ARG_FETCH;
#define JTOKEN (jjminor.jj0)
/* #line 153 "parser.y" */

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

/* #line 995 "parser.c" */
  phannot_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void jj_accept(
  jjParser *jjpParser           /* The parser */
){
  phannot_ARG_FETCH;
#ifndef NDEBUG
  if( jjTraceFILE ){
    fprintf(jjTraceFILE,"%sAccept!\n",jjTracePrompt);
  }
#endif
  while( jjpParser->jjidx>=0 ) jj_pop_parser_stack(jjpParser);
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
  void *jjp,                   /* The parser */
  int jjmajor,                 /* The major token code number */
  phannot_JTOKENTYPE jjminor       /* The value for the token */
  phannot_ARG_PDECL               /* Optional %extra_argument parameter */
){
  JJMINORTYPE jjminorunion;
  int jjact;            /* The parser action. */
  int jjendofinput;     /* True if we are at the end of input */
  int jjerrorhit = 0;   /* True if jjmajor has invoked an error */
  jjParser *jjpParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  jjpParser = (jjParser*)jjp;
  if( jjpParser->jjidx<0 ){
    if( jjmajor==0 ) return;
    jjpParser->jjidx = 0;
    jjpParser->jjerrcnt = -1;
    jjpParser->jjstack[0].stateno = 0;
    jjpParser->jjstack[0].major = 0;
  }
  jjminorunion.jj0 = jjminor;
  jjendofinput = (jjmajor==0);
  phannot_ARG_STORE;

#ifndef NDEBUG
  if( jjTraceFILE ){
    fprintf(jjTraceFILE,"%sInput %s\n",jjTracePrompt,jjTokenName[jjmajor]);
  }
#endif

  do{
    jjact = jj_find_shift_action(jjpParser,jjmajor);
    if( jjact<JJNSTATE ){
      jj_shift(jjpParser,jjact,jjmajor,&jjminorunion);
      jjpParser->jjerrcnt--;
      if( jjendofinput && jjpParser->jjidx>=0 ){
        jjmajor = 0;
      }else{
        jjmajor = JJNOCODE;
      }
    }else if( jjact < JJNSTATE + JJNRULE ){
      jj_reduce(jjpParser,jjact-JJNSTATE);
    }else if( jjact == JJ_ERROR_ACTION ){
      int jjmx;
#ifndef NDEBUG
      if( jjTraceFILE ){
        fprintf(jjTraceFILE,"%sSyntax Error!\n",jjTracePrompt);
      }
#endif
#ifdef JJERRORSYMBOL
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
      if( jjpParser->jjerrcnt<0 ){
        jj_syntax_error(jjpParser,jjmajor,jjminorunion);
      }
      jjmx = jjpParser->jjstack[jjpParser->jjidx].major;
      if( jjmx==JJERRORSYMBOL || jjerrorhit ){
#ifndef NDEBUG
        if( jjTraceFILE ){
          fprintf(jjTraceFILE,"%sDiscard input token %s\n",
             jjTracePrompt,jjTokenName[jjmajor]);
        }
#endif
        jj_destructor(jjmajor,&jjminorunion);
        jjmajor = JJNOCODE;
      }else{
         while(
          jjpParser->jjidx >= 0 &&
          jjmx != JJERRORSYMBOL &&
          (jjact = jj_find_shift_action(jjpParser,JJERRORSYMBOL)) >= JJNSTATE
        ){
          jj_pop_parser_stack(jjpParser);
        }
        if( jjpParser->jjidx < 0 || jjmajor==0 ){
          jj_destructor(jjmajor,&jjminorunion);
          jj_parse_failed(jjpParser);
          jjmajor = JJNOCODE;
        }else if( jjmx!=JJERRORSYMBOL ){
          JJMINORTYPE u2;
          u2.JJERRSYMDT = 0;
          jj_shift(jjpParser,jjact,JJERRORSYMBOL,&u2);
        }
      }
      jjpParser->jjerrcnt = 3;
      jjerrorhit = 1;
#else  /* JJERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( jjpParser->jjerrcnt<=0 ){
        jj_syntax_error(jjpParser,jjmajor,jjminorunion);
      }
      jjpParser->jjerrcnt = 3;
      jj_destructor(jjmajor,&jjminorunion);
      if( jjendofinput ){
        jj_parse_failed(jjpParser);
      }
      jjmajor = JJNOCODE;
#endif
    }else{
      jj_accept(jjpParser);
      jjmajor = JJNOCODE;
    }
  }while( jjmajor!=JJNOCODE && jjpParser->jjidx>=0 );
  return;
}

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#ifndef PHP_PHALCON_H
#include "php_phalcon.h"
#include "annotations/annot.h"
#include "annotations/parser.h"
#include "annotations/scanner.h"
#endif

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
int phannot_parse_annotations(zval *result, const char *comment, zend_uint comment_len, const char *file_path, zend_uint line TSRMLS_DC){

	char *error_msg = NULL;

	ZVAL_NULL(result);

	if (phannot_internal_parse_annotations(&result, comment, comment_len, file_path, line, &error_msg TSRMLS_CC) == FAILURE) {
		if (likely(error_msg != NULL)) {
			zend_throw_exception_ex(phalcon_annotations_exception_ce, 0 TSRMLS_CC, "%s", error_msg);
			efree(error_msg);
		}
		else {
			zend_throw_exception_ex(phalcon_annotations_exception_ce, 0 TSRMLS_CC, "Error parsing annotation");
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
	int start_mode = 1, open_parentheses;
	zend_uint i, j;
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
