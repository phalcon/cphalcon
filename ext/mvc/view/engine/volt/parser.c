/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 37 "parser.lemon"


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "parser.h"
#include "scanner.h"
#include "compiler.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

static zval *phvolt_ret_literal_zval(int type, phvolt_parser_token *T)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", type);
	if (T) {
		add_assoc_stringl(ret, "value", T->token, T->token_len, 1);
		efree(T->token);
		efree(T);
	}

	return ret;
}

static zval *phvolt_ret_if_statement(zval *expr, zval *true_statements, zval *false_statements)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_IF);
	add_assoc_zval(ret, "expr", expr);
	add_assoc_zval(ret, "true_statements", true_statements);
	if (false_statements) {
		add_assoc_zval(ret, "false_statements", false_statements);
	}

	return ret;
}

static zval *phvolt_ret_for_statement(zval *qualified_name, zval *expr, zval *block_statements)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_FOR);
	add_assoc_zval(ret, "qualified", qualified_name);
	add_assoc_zval(ret, "expr", expr);
	add_assoc_zval(ret, "block_statements", block_statements);

	return ret;
}

static zval *phvolt_ret_set_statement(zval *qualified_name, zval *expr)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_SET);
	add_assoc_zval(ret, "qualified", qualified_name);
	add_assoc_zval(ret, "expr", expr);

	return ret;
}

static zval *phvolt_ret_echo_statement(zval *expr)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_ECHO);
	add_assoc_zval(ret, "expr", expr);

	return ret;
}

static zval *phvolt_ret_empty_statement()
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_EMPTY);

	return ret;
}

static zval *phvolt_ret_qualified_name(zval *A, phvolt_parser_token *B)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_QUALIFIED);
	if (A != NULL) {
		add_assoc_zval(ret, "qualified", A);
	}

	add_assoc_stringl(ret, "name", B->token, B->token_len, 1);
	efree(B->token);
	efree(B);

	return ret;
}

static zval *phvolt_ret_zval_list(zval *list_left, zval *right_list)
{

	zval *ret;
	HashPosition pos;
	HashTable *list;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	list = Z_ARRVAL_P(list_left);
	if (zend_hash_index_exists(list, 0)) {
		zend_hash_internal_pointer_reset_ex(list, &pos);
		for (;; zend_hash_move_forward_ex(list, &pos)) {

			zval ** item;

			if (zend_hash_get_current_data_ex(list, (void**)&item, &pos) == FAILURE) {
				break;
			}

			Z_ADDREF_PP(item);
			add_next_index_zval(ret, *item);

		}
		zval_ptr_dtor(&list_left);
	} else {
		add_next_index_zval(ret, list_left);
	}

	add_next_index_zval(ret, right_list);

	return ret;
}

static zval *phvolt_ret_named_item(phvolt_parser_token *name, zval *expr)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_zval(ret, "expr", expr);
	if (name != NULL) {
		add_assoc_stringl(ret, "name", name->token, name->token_len, 1);
		efree(name->token);
		efree(name);
	}

	return ret;
}

static zval *phvolt_ret_expr(int type, zval *left, zval *right)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", type);
	if (left) {
		add_assoc_zval(ret, "left", left);
	}
	if (right) {
		add_assoc_zval(ret, "right", right);
	}

	return ret;
}

static zval *phvolt_ret_func_call(phvolt_parser_token *name, zval *arguments)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_FCALL);
	add_assoc_stringl(ret, "name", name->token, name->token_len, 1);
	efree(name->token);
	efree(name);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	return ret;
}


// 216 "parser.c"
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
**    KKCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    KKNOCODE           is a number of type KKCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    KKFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    KKACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    phvolt_TOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    KKMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is phvolt_TOKENTYPE.  The entry in the union
**                       for base tokens is called "kk0".
**    KKSTACKDEPTH       is the maximum depth of the parser's stack.
**    phvolt_ARG_SDECL     A static variable declaration for the %extra_argument
**    phvolt_ARG_PDECL     A parameter declaration for the %extra_argument
**    phvolt_ARG_STORE     Code to store %extra_argument into kkpParser
**    phvolt_ARG_FETCH     Code to extract %extra_argument from kkpParser
**    KKNSTATE           the combined number of states.
**    KKNRULE            the number of rules in the grammar
**    KKERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define KKCODETYPE unsigned char
#define KKNOCODE 66
#define KKACTIONTYPE unsigned char
#define phvolt_TOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_TOKENTYPE kk0;
  zval* kk98;
  int kk131;
} KKMINORTYPE;
#define KKSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = kkpParser->status
#define phvolt_ARG_STORE kkpParser->status = status
#define KKNSTATE 123
#define KKNRULE 60
#define KKERRORSYMBOL 47
#define KKERRSYMDT kk131
#define KK_NO_ACTION      (KKNSTATE+KKNRULE+2)
#define KK_ACCEPT_ACTION  (KKNSTATE+KKNRULE+1)
#define KK_ERROR_ACTION   (KKNSTATE+KKNRULE)

/* Next are that tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < KKNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   KKNSTATE <= N < KKNSTATE+KKNRULE   Reduce by rule N-KKNSTATE.
**
**   N == KKNSTATE+KKNRULE              A syntax error has occurred.
**
**   N == KKNSTATE+KKNRULE+1            The parser accepts its input.
**
**   N == KKNSTATE+KKNRULE+2            No such action.  Denotes unused
**                                      slots in the kk_action[] table.
**
** The action table is constructed as a single large table named kk_action[].
** Given state S and lookahead X, the action is computed as
**
**      kk_action[ kk_shift_ofst[S] + X ]
**
** If the index value kk_shift_ofst[S]+X is out of range or if the value
** kk_lookahead[kk_shift_ofst[S]+X] is not equal to X or if kk_shift_ofst[S]
** is equal to KK_SHIFT_USE_DFLT, it means that the action is not in the table
** and that kk_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the kk_reduce_ofst[] array is used in place of
** the kk_shift_ofst[] array and KK_REDUCE_USE_DFLT is used in place of
** KK_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  kk_action[]        A single table containing all actions.
**  kk_lookahead[]     A table containing the lookahead for each entry in
**                     kk_action.  Used to detect hash collisions.
**  kk_shift_ofst[]    For each state, the offset into kk_action for
**                     shifting terminals.
**  kk_reduce_ofst[]   For each state, the offset into kk_action for
**                     shifting non-terminals after a reduce.
**  kk_default[]       Default action for each state.
*/
static KKACTIONTYPE kk_action[] = {
 /*     0 */    75,   57,   59,   61,   67,   69,   71,   73,   63,   65,
 /*    10 */    49,   51,   55,   45,   43,   47,   41,   38,   53,  123,
 /*    20 */    17,   84,  103,   13,   88,   92,   75,   57,   59,   61,
 /*    30 */    67,   69,   71,   73,   63,   65,   49,   51,   55,   45,
 /*    40 */    43,   47,   41,   38,   53,   19,   12,  103,   23,   28,
 /*    50 */    92,  116,   75,   57,   59,   61,   67,   69,   71,   73,
 /*    60 */    63,   65,   49,   51,   55,   45,   43,   47,   41,   38,
 /*    70 */    53,   25,   27,  103,   32,   37,   92,   34,   75,   57,
 /*    80 */    59,   61,   67,   69,   71,   73,   63,   65,   49,   51,
 /*    90 */    55,   45,   43,   47,   41,   38,   53,   59,   61,   67,
 /*   100 */    69,   71,   73,   63,   65,   49,   51,   55,   45,   43,
 /*   110 */    47,   41,   38,   53,   77,   98,   94,   75,   57,   59,
 /*   120 */    61,   67,   69,   71,   73,   63,   65,   49,   51,   55,
 /*   130 */    45,   43,   47,   41,   38,   53,  184,    1,    2,  122,
 /*   140 */     4,    5,    6,    7,    8,    9,   11,  117,   16,   18,
 /*   150 */    24,   97,   82,   33,  104,   75,   57,   59,   61,   67,
 /*   160 */    69,   71,   73,   63,   65,   49,   51,   55,   45,   43,
 /*   170 */    47,   41,   38,   53,   49,   51,   55,   45,   43,   47,
 /*   180 */    41,   38,   53,   90,   36,  103,  101,  120,   92,  105,
 /*   190 */    75,   57,   59,   61,   67,   69,   71,   73,   63,   65,
 /*   200 */    49,   51,   55,   45,   43,   47,   41,   38,   53,   83,
 /*   210 */    14,  122,    4,    5,    6,    7,    8,    9,   20,  122,
 /*   220 */     4,    5,    6,    7,    8,    9,   39,  127,   78,   29,
 /*   230 */   122,    4,    5,    6,    7,    8,    9,   45,   43,   47,
 /*   240 */    41,   38,   53,   80,  112,  127,  100,   83,   93,  106,
 /*   250 */   108,  109,  110,  111,    3,    4,    5,    6,    7,    8,
 /*   260 */     9,   87,  127,  127,   39,  127,   78,   55,   45,   43,
 /*   270 */    47,   41,   38,   53,  127,   11,  117,   22,  104,   24,
 /*   280 */   127,   80,   33,  127,  107,   26,   93,  106,  108,  109,
 /*   290 */   110,  111,   83,   11,  117,  127,   10,   24,   86,   31,
 /*   300 */    33,   84,  103,   85,  114,   92,  118,  127,  121,   39,
 /*   310 */   127,   78,   95,  103,  104,  127,   92,   96,  113,   95,
 /*   320 */   103,  127,  127,   92,   35,   99,   80,  124,  127,   89,
 /*   330 */   127,   93,  106,  108,  109,  110,  111,   83,   11,  117,
 /*   340 */   127,   15,   24,  127,  127,   33,  127,   21,  127,  127,
 /*   350 */    10,  118,  127,  121,   39,   30,   78,  118,  127,  121,
 /*   360 */   118,  127,  121,  127,  127,  118,  127,  121,  115,  103,
 /*   370 */   127,   80,   92,  127,  100,  127,   93,  106,  108,  109,
 /*   380 */   110,  111,  127,  127,   40,  103,   42,  103,   92,  127,
 /*   390 */    92,   44,  103,  127,  127,   92,   41,   38,   53,  127,
 /*   400 */    46,  103,  127,  127,   92,  127,   48,  103,  127,  127,
 /*   410 */    92,  127,   50,  103,   52,  103,   92,  127,   92,   54,
 /*   420 */   103,   56,  103,   92,  127,   92,   58,  103,   60,  103,
 /*   430 */    92,  127,   92,   62,  103,   64,  103,   92,  127,   92,
 /*   440 */    66,  103,  127,  127,   92,   68,  103,   70,  103,   92,
 /*   450 */   127,   92,  127,  127,   72,  103,   74,  103,   92,  127,
 /*   460 */    92,  127,  127,   76,  103,   79,  103,   92,  127,   92,
 /*   470 */   127,   81,  103,   91,  103,   92,  127,   92,  102,  103,
 /*   480 */   119,  103,   92,  127,   92,
};
static KKCODETYPE kk_lookahead[] = {
 /*     0 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*    10 */    12,   13,   14,   15,   16,   17,   18,   19,   20,    0,
 /*    20 */    25,   58,   59,   25,   61,   62,    2,    3,    4,    5,
 /*    30 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*    40 */    16,   17,   18,   19,   20,   25,   58,   59,   25,   25,
 /*    50 */    62,   41,    2,    3,    4,    5,    6,    7,    8,    9,
 /*    60 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*    70 */    20,   59,   58,   59,   25,   25,   62,   59,    2,    3,
 /*    80 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    90 */    14,   15,   16,   17,   18,   19,   20,    4,    5,    6,
 /*   100 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   110 */    17,   18,   19,   20,   38,    1,   36,    2,    3,    4,
 /*   120 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   130 */    15,   16,   17,   18,   19,   20,   48,   49,   50,   51,
 /*   140 */    52,   53,   54,   55,   56,   57,   24,   25,   26,   27,
 /*   150 */    28,   37,   37,   31,   22,    2,    3,    4,    5,    6,
 /*   160 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   170 */    17,   18,   19,   20,   12,   13,   14,   15,   16,   17,
 /*   180 */    18,   19,   20,   40,   58,   59,   40,   34,   62,   41,
 /*   190 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   200 */    12,   13,   14,   15,   16,   17,   18,   19,   20,    2,
 /*   210 */    50,   51,   52,   53,   54,   55,   56,   57,   50,   51,
 /*   220 */    52,   53,   54,   55,   56,   57,   19,   65,   21,   50,
 /*   230 */    51,   52,   53,   54,   55,   56,   57,   15,   16,   17,
 /*   240 */    18,   19,   20,   36,   37,   65,   39,    2,   41,   42,
 /*   250 */    43,   44,   45,   46,   51,   52,   53,   54,   55,   56,
 /*   260 */    57,    1,   65,   65,   19,   65,   21,   14,   15,   16,
 /*   270 */    17,   18,   19,   20,   65,   24,   25,   26,   22,   28,
 /*   280 */    65,   36,   31,   65,   39,   29,   41,   42,   43,   44,
 /*   290 */    45,   46,    2,   24,   25,   65,   23,   28,   38,   30,
 /*   300 */    31,   58,   59,   60,   61,   62,   33,   65,   35,   19,
 /*   310 */    65,   21,   58,   59,   22,   65,   62,   63,   64,   58,
 /*   320 */    59,   65,   65,   62,   32,   64,   36,    0,   65,   39,
 /*   330 */    65,   41,   42,   43,   44,   45,   46,    2,   24,   25,
 /*   340 */    65,   23,   28,   65,   65,   31,   65,   23,   65,   65,
 /*   350 */    23,   33,   65,   35,   19,   23,   21,   33,   65,   35,
 /*   360 */    33,   65,   35,   65,   65,   33,   65,   35,   58,   59,
 /*   370 */    65,   36,   62,   65,   39,   65,   41,   42,   43,   44,
 /*   380 */    45,   46,   65,   65,   58,   59,   58,   59,   62,   65,
 /*   390 */    62,   58,   59,   65,   65,   62,   18,   19,   20,   65,
 /*   400 */    58,   59,   65,   65,   62,   65,   58,   59,   65,   65,
 /*   410 */    62,   65,   58,   59,   58,   59,   62,   65,   62,   58,
 /*   420 */    59,   58,   59,   62,   65,   62,   58,   59,   58,   59,
 /*   430 */    62,   65,   62,   58,   59,   58,   59,   62,   65,   62,
 /*   440 */    58,   59,   65,   65,   62,   58,   59,   58,   59,   62,
 /*   450 */    65,   62,   65,   65,   58,   59,   58,   59,   62,   65,
 /*   460 */    62,   65,   65,   58,   59,   58,   59,   62,   65,   62,
 /*   470 */    65,   58,   59,   58,   59,   62,   65,   62,   58,   59,
 /*   480 */    58,   59,   62,   65,   62,
};
#define KK_SHIFT_USE_DFLT (-6)
static short kk_shift_ofst[] = {
 /*     0 */   273,   19,  327,   -6,   -6,   -6,   -6,   -6,   -6,   -6,
 /*    10 */   314,  245,   -2,  273,  318,  122,   -5,   -6,   20,  273,
 /*    20 */   324,  251,   23,   -6,   10,  256,  245,   24,  273,  332,
 /*    30 */   269,   49,   -6,   10,  292,  245,   50,   -6,  245,  245,
 /*    40 */    -6,  245,   -6,  245,  378,  245,  378,  245,  378,  245,
 /*    50 */   253,  245,  253,  245,   -6,  245,  222,  245,   93,  245,
 /*    60 */   162,  245,  162,  245,  162,  245,  162,  245,  162,  245,
 /*    70 */   162,  245,  162,  245,  162,  245,   76,   -6,  245,   -6,
 /*    80 */   245,  115,   -6,  290,  188,  260,   -6,  290,   -6,  143,
 /*    90 */   245,  188,   -6,   80,  207,  188,  114,   -6,  335,   -6,
 /*   100 */   146,  245,  188,  132,  148,   -6,   -6,   -6,   -6,   -6,
 /*   110 */    -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,  245,  153,
 /*   120 */    -6,   -6,   -6,
};
#define KK_REDUCE_USE_DFLT (-38)
static short kk_reduce_ofst[] = {
 /*     0 */    88,  -38,  203,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
 /*    10 */   -38,  -12,  -38,  160,  203,  -38,  -38,  -38,  -38,  168,
 /*    20 */   203,  -38,  -38,  -38,   12,  -38,   14,  -38,  179,  203,
 /*    30 */   -38,  -38,  -38,   18,  -38,  126,  -38,  -38,  310,  326,
 /*    40 */   -38,  328,  -38,  333,  -38,  342,  -38,  348,  -38,  354,
 /*    50 */   -38,  356,  -38,  361,  -38,  363,  -38,  368,  -38,  370,
 /*    60 */   -38,  375,  -38,  377,  -38,  382,  -38,  387,  -38,  389,
 /*    70 */   -38,  396,  -38,  398,  -38,  405,  -38,  -38,  407,  -38,
 /*    80 */   413,  -38,  -38,  243,  -38,  -38,  -38,  -37,  -38,  -38,
 /*    90 */   415,  -38,  -38,  -38,  254,  -38,  -38,  -38,  261,  -38,
 /*   100 */   -38,  420,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
 /*   110 */   -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  422,  -38,
 /*   120 */   -38,  -38,  -38,
};
static KKACTIONTYPE kk_default[] = {
 /*     0 */   183,  183,  183,  125,  127,  128,  129,  130,  131,  132,
 /*    10 */   183,  183,  183,  183,  183,  183,  183,  133,  183,  183,
 /*    20 */   183,  183,  183,  134,  183,  183,  183,  183,  183,  183,
 /*    30 */   183,  183,  135,  183,  183,  183,  183,  136,  183,  183,
 /*    40 */   140,  183,  142,  183,  143,  183,  144,  183,  145,  183,
 /*    50 */   146,  183,  147,  183,  148,  183,  149,  183,  150,  183,
 /*    60 */   151,  183,  152,  183,  153,  183,  154,  183,  155,  183,
 /*    70 */   156,  183,  157,  183,  158,  183,  183,  174,  183,  159,
 /*    80 */   183,  183,  160,  183,  165,  183,  161,  183,  162,  176,
 /*    90 */   183,  164,  166,  182,  183,  171,  183,  167,  183,  169,
 /*   100 */   176,  183,  172,  173,  183,  181,  175,  176,  177,  178,
 /*   110 */   179,  180,  168,  170,  163,  141,  182,  137,  183,  183,
 /*   120 */   138,  139,  126,
};
#define KK_SZ_ACTTAB (sizeof(kk_action)/sizeof(kk_action[0]))

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
#ifdef KKFALLBACK
static const KKCODETYPE kkFallback[] = {
};
#endif /* KKFALLBACK */

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
struct kkStackEntry {
  int stateno;       /* The state-number */
  int major;         /* The major token value.  This is the code
                     ** number for the token at this stack level */
  KKMINORTYPE minor; /* The user-supplied minor token value.  This
                     ** is the value of the token  */
};
typedef struct kkStackEntry kkStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct kkParser {
  int kkidx;                    /* Index of top element in stack */
  int kkerrcnt;                 /* Shifts left before out of the error */
  phvolt_ARG_SDECL                /* A place to hold %extra_argument */
  kkStackEntry kkstack[KKSTACKDEPTH];  /* The parser's stack */
};
typedef struct kkParser kkParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *kkTraceFILE = 0;
static char *kkTracePrompt = 0;
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
void phvolt_Trace(FILE *TraceFILE, char *zTracePrompt){
  kkTraceFILE = TraceFILE;
  kkTracePrompt = zTracePrompt;
  if( kkTraceFILE==0 ) kkTracePrompt = 0;
  else if( kkTracePrompt==0 ) kkTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *kkTokenName[] = { 
  "$",             "COMMA",         "SBRACKET_OPEN",  "RANGE",       
  "EQUALS",        "NOTEQUALS",     "LESS",          "GREATER",     
  "GREATEREQUAL",  "LESSEQUAL",     "IDENTICAL",     "NOTIDENTICAL",
  "AND",           "OR",            "PIPE",          "DIVIDE",      
  "TIMES",         "MOD",           "PLUS",          "MINUS",       
  "CONCAT",        "NOT",           "DOT",           "OPEN_DELIMITER",
  "IF",            "CLOSE_DELIMITER",  "ENDIF",         "ELSE",        
  "FOR",           "IN",            "ENDFOR",        "SET",         
  "ASSIGN",        "OPEN_EDELIMITER",  "CLOSE_EDELIMITER",  "RAW_FRAGMENT",
  "BRACKET_OPEN",  "BRACKET_CLOSE",  "SBRACKET_CLOSE",  "STRING",      
  "DOUBLECOLON",   "IDENTIFIER",    "INTEGER",       "DOUBLE",      
  "NULL",          "FALSE",         "TRUE",          "error",       
  "program",       "volt_language",  "statement_list",  "statement",   
  "raw_fragment",  "if_statement",  "for_statement",  "set_statement",
  "echo_statement",  "empty_statement",  "expr",          "qualified_name",
  "array_list",    "array_item",    "function_call",  "argument_list",
  "argument_item",
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *kkRuleName[] = {
 /*   0 */ "program ::= volt_language",
 /*   1 */ "volt_language ::= statement_list",
 /*   2 */ "statement_list ::= statement_list statement",
 /*   3 */ "statement_list ::= statement",
 /*   4 */ "statement ::= raw_fragment",
 /*   5 */ "statement ::= if_statement",
 /*   6 */ "statement ::= for_statement",
 /*   7 */ "statement ::= set_statement",
 /*   8 */ "statement ::= echo_statement",
 /*   9 */ "statement ::= empty_statement",
 /*  10 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  11 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  12 */ "for_statement ::= OPEN_DELIMITER FOR qualified_name IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  13 */ "set_statement ::= OPEN_DELIMITER SET qualified_name ASSIGN expr CLOSE_DELIMITER",
 /*  14 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  15 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  16 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  17 */ "expr ::= MINUS expr",
 /*  18 */ "expr ::= expr MINUS expr",
 /*  19 */ "expr ::= expr PLUS expr",
 /*  20 */ "expr ::= expr TIMES expr",
 /*  21 */ "expr ::= expr DIVIDE expr",
 /*  22 */ "expr ::= expr MOD expr",
 /*  23 */ "expr ::= expr AND expr",
 /*  24 */ "expr ::= expr OR expr",
 /*  25 */ "expr ::= expr CONCAT expr",
 /*  26 */ "expr ::= expr PIPE expr",
 /*  27 */ "expr ::= expr RANGE expr",
 /*  28 */ "expr ::= expr EQUALS expr",
 /*  29 */ "expr ::= expr NOTEQUALS expr",
 /*  30 */ "expr ::= expr IDENTICAL expr",
 /*  31 */ "expr ::= expr NOTIDENTICAL expr",
 /*  32 */ "expr ::= expr LESS expr",
 /*  33 */ "expr ::= expr GREATER expr",
 /*  34 */ "expr ::= expr GREATEREQUAL expr",
 /*  35 */ "expr ::= expr LESSEQUAL expr",
 /*  36 */ "expr ::= NOT expr",
 /*  37 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /*  38 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /*  39 */ "array_list ::= array_list COMMA array_item",
 /*  40 */ "array_list ::= array_item",
 /*  41 */ "array_item ::= STRING DOUBLECOLON expr",
 /*  42 */ "array_item ::= expr",
 /*  43 */ "expr ::= function_call",
 /*  44 */ "function_call ::= IDENTIFIER BRACKET_OPEN argument_list BRACKET_CLOSE",
 /*  45 */ "function_call ::= IDENTIFIER BRACKET_OPEN BRACKET_CLOSE",
 /*  46 */ "argument_list ::= argument_list COMMA argument_item",
 /*  47 */ "argument_list ::= argument_item",
 /*  48 */ "argument_item ::= expr",
 /*  49 */ "argument_item ::= STRING DOUBLECOLON expr",
 /*  50 */ "expr ::= qualified_name",
 /*  51 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /*  52 */ "expr ::= INTEGER",
 /*  53 */ "expr ::= STRING",
 /*  54 */ "expr ::= DOUBLE",
 /*  55 */ "expr ::= NULL",
 /*  56 */ "expr ::= FALSE",
 /*  57 */ "expr ::= TRUE",
 /*  58 */ "qualified_name ::= qualified_name DOT IDENTIFIER",
 /*  59 */ "qualified_name ::= IDENTIFIER",
};
#endif /* NDEBUG */

/*
** This function returns the symbolic name associated with a token
** value.
*/
const char *phvolt_TokenName(int tokenType){
#ifndef NDEBUG
  if( tokenType>0 && tokenType<(sizeof(kkTokenName)/sizeof(kkTokenName[0])) ){
    return kkTokenName[tokenType];
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
** to phvolt_ and phvolt_Free.
*/
void *phvolt_Alloc(void *(*mallocProc)(size_t)){
  kkParser *pParser;
  pParser = (kkParser*)(*mallocProc)( (size_t)sizeof(kkParser) );
  if( pParser ){
    pParser->kkidx = -1;
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "kkmajor" is the symbol code, and "kkpminor" is a pointer to
** the value.
*/
static void kk_destructor(KKCODETYPE kkmajor, KKMINORTYPE *kkpminor){
  switch( kkmajor ){
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
// 295 "parser.lemon"
{
	if ((kkpminor->kk0)) {
		efree((kkpminor->kk0)->token);
		efree((kkpminor->kk0));
	}
}
// 761 "parser.c"
      break;
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
    case 62:
    case 63:
    case 64:
// 310 "parser.lemon"
{ zval_ptr_dtor(&(kkpminor->kk98)); }
// 779 "parser.c"
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
static int kk_pop_parser_stack(kkParser *pParser){
  KKCODETYPE kkmajor;
  kkStackEntry *kktos = &pParser->kkstack[pParser->kkidx];

  if( pParser->kkidx<0 ) return 0;
#ifndef NDEBUG
  if( kkTraceFILE && pParser->kkidx>=0 ){
    fprintf(kkTraceFILE,"%sPopping %s\n",
      kkTracePrompt,
      kkTokenName[kktos->major]);
  }
#endif
  kkmajor = kktos->major;
  kk_destructor( kkmajor, &kktos->minor);
  pParser->kkidx--;
  return kkmajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from phvolt_Alloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void phvolt_Free(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  kkParser *pParser = (kkParser*)p;
  if( pParser==0 ) return;
  while( pParser->kkidx>=0 ) kk_pop_parser_stack(pParser);
  (*freeProc)((void*)pParser);
}

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is KKNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return KK_NO_ACTION.
*/
static int kk_find_shift_action(
  kkParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->kkstack[pParser->kkidx].stateno;
 
  /* if( pParser->kkidx<0 ) return KK_NO_ACTION;  */
  i = kk_shift_ofst[stateno];
  if( i==KK_SHIFT_USE_DFLT ){
    return kk_default[stateno];
  }
  if( iLookAhead==KKNOCODE ){
    return KK_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=KK_SZ_ACTTAB || kk_lookahead[i]!=iLookAhead ){
#ifdef KKFALLBACK
    int iFallback;            /* Fallback token */
    if( iLookAhead<sizeof(kkFallback)/sizeof(kkFallback[0])
           && (iFallback = kkFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
      if( kkTraceFILE ){
        fprintf(kkTraceFILE, "%sFALLBACK %s => %s\n",
           kkTracePrompt, kkTokenName[iLookAhead], kkTokenName[iFallback]);
      }
#endif
      return kk_find_shift_action(pParser, iFallback);
    }
#endif
    return kk_default[stateno];
  }else{
    return kk_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is KKNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return KK_NO_ACTION.
*/
static int kk_find_reduce_action(
  kkParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->kkstack[pParser->kkidx].stateno;
 
  i = kk_reduce_ofst[stateno];
  if( i==KK_REDUCE_USE_DFLT ){
    return kk_default[stateno];
  }
  if( iLookAhead==KKNOCODE ){
    return KK_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=KK_SZ_ACTTAB || kk_lookahead[i]!=iLookAhead ){
    return kk_default[stateno];
  }else{
    return kk_action[i];
  }
}

/*
** Perform a shift action.
*/
static void kk_shift(
  kkParser *kkpParser,          /* The parser to be shifted */
  int kkNewState,               /* The new state to shift in */
  int kkMajor,                  /* The major token to shift in */
  KKMINORTYPE *kkpMinor         /* Pointer ot the minor token to shift in */
){
  kkStackEntry *kktos;
  kkpParser->kkidx++;
  if( kkpParser->kkidx>=KKSTACKDEPTH ){
     phvolt_ARG_FETCH;
     kkpParser->kkidx--;
#ifndef NDEBUG
     if( kkTraceFILE ){
       fprintf(kkTraceFILE,"%sStack Overflow!\n",kkTracePrompt);
     }
#endif
     while( kkpParser->kkidx>=0 ) kk_pop_parser_stack(kkpParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     phvolt_ARG_STORE; /* Suppress warning about unused %extra_argument var */
     return;
  }
  kktos = &kkpParser->kkstack[kkpParser->kkidx];
  kktos->stateno = kkNewState;
  kktos->major = kkMajor;
  kktos->minor = *kkpMinor;
#ifndef NDEBUG
  if( kkTraceFILE && kkpParser->kkidx>0 ){
    int i;
    fprintf(kkTraceFILE,"%sShift %d\n",kkTracePrompt,kkNewState);
    fprintf(kkTraceFILE,"%sStack:",kkTracePrompt);
    for(i=1; i<=kkpParser->kkidx; i++)
      fprintf(kkTraceFILE," %s",kkTokenName[kkpParser->kkstack[i].major]);
    fprintf(kkTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static struct {
  KKCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} kkRuleInfo[] = {
  { 48, 1 },
  { 49, 1 },
  { 50, 2 },
  { 50, 1 },
  { 51, 1 },
  { 51, 1 },
  { 51, 1 },
  { 51, 1 },
  { 51, 1 },
  { 51, 1 },
  { 53, 8 },
  { 53, 12 },
  { 54, 10 },
  { 55, 6 },
  { 57, 2 },
  { 56, 3 },
  { 52, 1 },
  { 58, 2 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 2 },
  { 58, 3 },
  { 58, 3 },
  { 60, 3 },
  { 60, 1 },
  { 61, 3 },
  { 61, 1 },
  { 58, 1 },
  { 62, 4 },
  { 62, 3 },
  { 63, 3 },
  { 63, 1 },
  { 64, 1 },
  { 64, 3 },
  { 58, 1 },
  { 58, 4 },
  { 58, 1 },
  { 58, 1 },
  { 58, 1 },
  { 58, 1 },
  { 58, 1 },
  { 58, 1 },
  { 59, 3 },
  { 59, 1 },
};

static void kk_accept(kkParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void kk_reduce(
  kkParser *kkpParser,         /* The parser */
  int kkruleno                 /* Number of the rule by which to reduce */
){
  int kkgoto;                     /* The next state */
  int kkact;                      /* The next action */
  KKMINORTYPE kkgotominor;        /* The LHS of the rule reduced */
  kkStackEntry *kkmsp;            /* The top of the parser's stack */
  int kksize;                     /* Amount to pop the stack */
  phvolt_ARG_FETCH;
  kkmsp = &kkpParser->kkstack[kkpParser->kkidx];
#ifndef NDEBUG
  if( kkTraceFILE && kkruleno>=0 
        && kkruleno<sizeof(kkRuleName)/sizeof(kkRuleName[0]) ){
    fprintf(kkTraceFILE, "%sReduce [%s].\n", kkTracePrompt,
      kkRuleName[kkruleno]);
  }
#endif /* NDEBUG */

  switch( kkruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  // <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  // <lineno> <thisfile>
  **     break;
  */
      case 0:
// 302 "parser.lemon"
{
	status->ret = kkmsp[0].minor.kk98;
}
// 1056 "parser.c"
        break;
      case 1:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 40:
      case 43:
      case 47:
      case 50:
// 306 "parser.lemon"
{
	kkgotominor.kk98 = kkmsp[0].minor.kk98;
}
// 1074 "parser.c"
        break;
      case 2:
// 312 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_zval_list(kkmsp[-1].minor.kk98, kkmsp[0].minor.kk98);
}
// 1081 "parser.c"
        break;
      case 10:
// 348 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_if_statement(kkmsp[-5].minor.kk98, kkmsp[-3].minor.kk98, NULL);
  kk_destructor(23,&kkmsp[-7].minor);
  kk_destructor(24,&kkmsp[-6].minor);
  kk_destructor(25,&kkmsp[-4].minor);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(26,&kkmsp[-1].minor);
  kk_destructor(25,&kkmsp[0].minor);
}
// 1094 "parser.c"
        break;
      case 11:
// 352 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_if_statement(kkmsp[-9].minor.kk98, kkmsp[-7].minor.kk98, kkmsp[-3].minor.kk98);
  kk_destructor(23,&kkmsp[-11].minor);
  kk_destructor(24,&kkmsp[-10].minor);
  kk_destructor(25,&kkmsp[-8].minor);
  kk_destructor(23,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-5].minor);
  kk_destructor(25,&kkmsp[-4].minor);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(26,&kkmsp[-1].minor);
  kk_destructor(25,&kkmsp[0].minor);
}
// 1110 "parser.c"
        break;
      case 12:
// 358 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_for_statement(kkmsp[-7].minor.kk98, kkmsp[-5].minor.kk98, kkmsp[-3].minor.kk98);
  kk_destructor(23,&kkmsp[-9].minor);
  kk_destructor(28,&kkmsp[-8].minor);
  kk_destructor(29,&kkmsp[-6].minor);
  kk_destructor(25,&kkmsp[-4].minor);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[-1].minor);
  kk_destructor(25,&kkmsp[0].minor);
}
// 1124 "parser.c"
        break;
      case 13:
// 364 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_set_statement(kkmsp[-3].minor.kk98, kkmsp[-1].minor.kk98);
  kk_destructor(23,&kkmsp[-5].minor);
  kk_destructor(31,&kkmsp[-4].minor);
  kk_destructor(32,&kkmsp[-2].minor);
  kk_destructor(25,&kkmsp[0].minor);
}
// 1135 "parser.c"
        break;
      case 14:
// 370 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_empty_statement();
  kk_destructor(23,&kkmsp[-1].minor);
  kk_destructor(25,&kkmsp[0].minor);
}
// 1144 "parser.c"
        break;
      case 15:
// 376 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_echo_statement(kkmsp[-1].minor.kk98);
  kk_destructor(33,&kkmsp[-2].minor);
  kk_destructor(34,&kkmsp[0].minor);
}
// 1153 "parser.c"
        break;
      case 16:
// 382 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, kkmsp[0].minor.kk0);
}
// 1160 "parser.c"
        break;
      case 17:
// 388 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, kkmsp[0].minor.kk98);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 1168 "parser.c"
        break;
      case 18:
// 392 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_SUB, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 1176 "parser.c"
        break;
      case 19:
// 396 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_ADD, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(18,&kkmsp[-1].minor);
}
// 1184 "parser.c"
        break;
      case 20:
// 400 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_MUL, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(16,&kkmsp[-1].minor);
}
// 1192 "parser.c"
        break;
      case 21:
// 404 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_DIV, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(15,&kkmsp[-1].minor);
}
// 1200 "parser.c"
        break;
      case 22:
// 408 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(17,&kkmsp[-1].minor);
}
// 1208 "parser.c"
        break;
      case 23:
// 412 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_AND, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(12,&kkmsp[-1].minor);
}
// 1216 "parser.c"
        break;
      case 24:
// 416 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_OR, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(13,&kkmsp[-1].minor);
}
// 1224 "parser.c"
        break;
      case 25:
// 420 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_CONCAT, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 1232 "parser.c"
        break;
      case 26:
// 424 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_PIPE, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(14,&kkmsp[-1].minor);
}
// 1240 "parser.c"
        break;
      case 27:
// 428 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_RANGE, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(3,&kkmsp[-1].minor);
}
// 1248 "parser.c"
        break;
      case 28:
// 432 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_EQUALS, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(4,&kkmsp[-1].minor);
}
// 1256 "parser.c"
        break;
      case 29:
// 436 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 1264 "parser.c"
        break;
      case 30:
// 440 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(10,&kkmsp[-1].minor);
}
// 1272 "parser.c"
        break;
      case 31:
// 444 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(11,&kkmsp[-1].minor);
}
// 1280 "parser.c"
        break;
      case 32:
// 448 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_LESS, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(6,&kkmsp[-1].minor);
}
// 1288 "parser.c"
        break;
      case 33:
// 452 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_GREATER, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(7,&kkmsp[-1].minor);
}
// 1296 "parser.c"
        break;
      case 34:
// 456 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(8,&kkmsp[-1].minor);
}
// 1304 "parser.c"
        break;
      case 35:
// 460 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(9,&kkmsp[-1].minor);
}
// 1312 "parser.c"
        break;
      case 36:
// 464 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, kkmsp[0].minor.kk98);
  kk_destructor(21,&kkmsp[-1].minor);
}
// 1320 "parser.c"
        break;
      case 37:
// 468 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, kkmsp[-1].minor.kk98, NULL);
  kk_destructor(36,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[0].minor);
}
// 1329 "parser.c"
        break;
      case 38:
// 472 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk98, NULL);
  kk_destructor(2,&kkmsp[-2].minor);
  kk_destructor(38,&kkmsp[0].minor);
}
// 1338 "parser.c"
        break;
      case 39:
      case 46:
// 478 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_zval_list(kkmsp[-2].minor.kk98, kkmsp[0].minor.kk98);
  kk_destructor(1,&kkmsp[-1].minor);
}
// 1347 "parser.c"
        break;
      case 41:
      case 49:
// 486 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_named_item(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk98);
  kk_destructor(40,&kkmsp[-1].minor);
}
// 1356 "parser.c"
        break;
      case 42:
      case 48:
// 490 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_named_item(NULL, kkmsp[0].minor.kk98);
}
// 1364 "parser.c"
        break;
      case 44:
// 500 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_func_call(kkmsp[-3].minor.kk0, kkmsp[-1].minor.kk98);
  kk_destructor(36,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[0].minor);
}
// 1373 "parser.c"
        break;
      case 45:
// 504 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_func_call(kkmsp[-2].minor.kk0, NULL);
  kk_destructor(36,&kkmsp[-1].minor);
  kk_destructor(37,&kkmsp[0].minor);
}
// 1382 "parser.c"
        break;
      case 51:
// 532 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, kkmsp[-3].minor.kk98, kkmsp[-1].minor.kk98);
  kk_destructor(2,&kkmsp[-2].minor);
  kk_destructor(38,&kkmsp[0].minor);
}
// 1391 "parser.c"
        break;
      case 52:
// 536 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, kkmsp[0].minor.kk0);
}
// 1398 "parser.c"
        break;
      case 53:
// 540 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_literal_zval(PHVOLT_T_STRING, kkmsp[0].minor.kk0);
}
// 1405 "parser.c"
        break;
      case 54:
// 544 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, kkmsp[0].minor.kk0);
}
// 1412 "parser.c"
        break;
      case 55:
// 548 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL);
  kk_destructor(44,&kkmsp[0].minor);
}
// 1420 "parser.c"
        break;
      case 56:
// 552 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL);
  kk_destructor(45,&kkmsp[0].minor);
}
// 1428 "parser.c"
        break;
      case 57:
// 556 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL);
  kk_destructor(46,&kkmsp[0].minor);
}
// 1436 "parser.c"
        break;
      case 58:
// 562 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_qualified_name(kkmsp[-2].minor.kk98, kkmsp[0].minor.kk0);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 1444 "parser.c"
        break;
      case 59:
// 566 "parser.lemon"
{
	kkgotominor.kk98 = phvolt_ret_qualified_name(NULL, kkmsp[0].minor.kk0);
}
// 1451 "parser.c"
        break;
  };
  kkgoto = kkRuleInfo[kkruleno].lhs;
  kksize = kkRuleInfo[kkruleno].nrhs;
  kkpParser->kkidx -= kksize;
  kkact = kk_find_reduce_action(kkpParser,kkgoto);
  if( kkact < KKNSTATE ){
    kk_shift(kkpParser,kkact,kkgoto,&kkgotominor);
  }else if( kkact == KKNSTATE + KKNRULE + 1 ){
    kk_accept(kkpParser);
  }
}

/*
** The following code executes when the parse fails
*/
static void kk_parse_failed(
  kkParser *kkpParser           /* The parser */
){
  phvolt_ARG_FETCH;
#ifndef NDEBUG
  if( kkTraceFILE ){
    fprintf(kkTraceFILE,"%sFail!\n",kkTracePrompt);
  }
#endif
  while( kkpParser->kkidx>=0 ) kk_pop_parser_stack(kkpParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  phvolt_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void kk_syntax_error(
  kkParser *kkpParser,           /* The parser */
  int kkmajor,                   /* The major type of the error token */
  KKMINORTYPE kkminor            /* The minor type of the error token */
){
  phvolt_ARG_FETCH;
#define TOKEN (kkminor.kk0)
// 245 "parser.lemon"

	if (status->scanner_state->start) {
		{

			char *token_name = NULL;
			const phvolt_token_names *tokens = phvolt_tokens;
			int token_found = 0;
			int active_token = status->scanner_state->active_token;
			int near_length = strlen(status->scanner_state->start);

			if (active_token) {

				do {
					if (tokens->code == active_token) {
						token_found = 1;
						token_name = tokens->name;
						break;
					}
					++tokens;
				} while (tokens[0].code != 0);

			}

			if (!token_name) {
				token_found = 0;
				token_name = estrndup("UNKNOWN", strlen("UNKNOWN"));
			}

			status->syntax_error_len = 64 + strlen(token_name) + near_length;
			status->syntax_error = emalloc(sizeof(char)*status->syntax_error_len);
			if (near_length > 0) {
				sprintf(status->syntax_error, "Syntax error, unexpected token %s, near to %s", token_name, status->scanner_state->start);
			} else {
				sprintf(status->syntax_error, "Syntax error, unexpected token %s, at the end of query", token_name);
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

	status->status = PHVOLT_PARSING_FAILED;

// 1543 "parser.c"
  phvolt_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void kk_accept(
  kkParser *kkpParser           /* The parser */
){
  phvolt_ARG_FETCH;
#ifndef NDEBUG
  if( kkTraceFILE ){
    fprintf(kkTraceFILE,"%sAccept!\n",kkTracePrompt);
  }
#endif
  while( kkpParser->kkidx>=0 ) kk_pop_parser_stack(kkpParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  phvolt_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "phvolt_Alloc" which describes the current state of the parser.
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
void phvolt_(
  void *kkp,                   /* The parser */
  int kkmajor,                 /* The major token code number */
  phvolt_TOKENTYPE kkminor       /* The value for the token */
  phvolt_ARG_PDECL               /* Optional %extra_argument parameter */
){
  KKMINORTYPE kkminorunion;
  int kkact;            /* The parser action. */
  int kkendofinput;     /* True if we are at the end of input */
  int kkerrorhit = 0;   /* True if kkmajor has invoked an error */
  kkParser *kkpParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  kkpParser = (kkParser*)kkp;
  if( kkpParser->kkidx<0 ){
    if( kkmajor==0 ) return;
    kkpParser->kkidx = 0;
    kkpParser->kkerrcnt = -1;
    kkpParser->kkstack[0].stateno = 0;
    kkpParser->kkstack[0].major = 0;
  }
  kkminorunion.kk0 = kkminor;
  kkendofinput = (kkmajor==0);
  phvolt_ARG_STORE;

#ifndef NDEBUG
  if( kkTraceFILE ){
    fprintf(kkTraceFILE,"%sInput %s\n",kkTracePrompt,kkTokenName[kkmajor]);
  }
#endif

  do{
    kkact = kk_find_shift_action(kkpParser,kkmajor);
    if( kkact<KKNSTATE ){
      kk_shift(kkpParser,kkact,kkmajor,&kkminorunion);
      kkpParser->kkerrcnt--;
      if( kkendofinput && kkpParser->kkidx>=0 ){
        kkmajor = 0;
      }else{
        kkmajor = KKNOCODE;
      }
    }else if( kkact < KKNSTATE + KKNRULE ){
      kk_reduce(kkpParser,kkact-KKNSTATE);
    }else if( kkact == KK_ERROR_ACTION ){
      int kkmx;
#ifndef NDEBUG
      if( kkTraceFILE ){
        fprintf(kkTraceFILE,"%sSyntax Error!\n",kkTracePrompt);
      }
#endif
#ifdef KKERRORSYMBOL
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
      if( kkpParser->kkerrcnt<0 ){
        kk_syntax_error(kkpParser,kkmajor,kkminorunion);
      }
      kkmx = kkpParser->kkstack[kkpParser->kkidx].major;
      if( kkmx==KKERRORSYMBOL || kkerrorhit ){
#ifndef NDEBUG
        if( kkTraceFILE ){
          fprintf(kkTraceFILE,"%sDiscard input token %s\n",
             kkTracePrompt,kkTokenName[kkmajor]);
        }
#endif
        kk_destructor(kkmajor,&kkminorunion);
        kkmajor = KKNOCODE;
      }else{
         while(
          kkpParser->kkidx >= 0 &&
          kkmx != KKERRORSYMBOL &&
          (kkact = kk_find_shift_action(kkpParser,KKERRORSYMBOL)) >= KKNSTATE
        ){
          kk_pop_parser_stack(kkpParser);
        }
        if( kkpParser->kkidx < 0 || kkmajor==0 ){
          kk_destructor(kkmajor,&kkminorunion);
          kk_parse_failed(kkpParser);
          kkmajor = KKNOCODE;
        }else if( kkmx!=KKERRORSYMBOL ){
          KKMINORTYPE u2;
          u2.KKERRSYMDT = 0;
          kk_shift(kkpParser,kkact,KKERRORSYMBOL,&u2);
        }
      }
      kkpParser->kkerrcnt = 3;
      kkerrorhit = 1;
#else  /* KKERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( kkpParser->kkerrcnt<=0 ){
        kk_syntax_error(kkpParser,kkmajor,kkminorunion);
      }
      kkpParser->kkerrcnt = 3;
      kk_destructor(kkmajor,&kkminorunion);
      if( kkendofinput ){
        kk_parse_failed(kkpParser);
      }
      kkmajor = KKNOCODE;
#endif
    }else{
      kk_accept(kkpParser);
      kkmajor = KKNOCODE;
    }
  }while( kkmajor!=KKNOCODE && kkpParser->kkidx>=0 );
  return;
}

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

const phvolt_token_names phvolt_tokens[] =
{
  { PHVOLT_T_INTEGER,       	"INTEGER" },
  { PHVOLT_T_DOUBLE,        	"DOUBLE" },
  { PHVOLT_T_STRING,        	"STRING" },
  { PHVOLT_T_IDENTIFIER,    	"IDENTIFIER" },
  { PHVOLT_T_MINUS,         	"MINUS" },
  { PHVOLT_T_ADD,           	"+" },
  { PHVOLT_T_SUB,           	"-" },
  { PHVOLT_T_MUL,           	"*" },
  { PHVOLT_T_DIV,           	"/" },
  { PHVOLT_T_MOD,           	"%%" },
  { PHVOLT_T_AND,           	"AND" },
  { PHVOLT_T_OR,            	"OR" },
  { PHVOLT_T_DOT,           	"DOT" },
  { PHVOLT_T_COMMA,         	"COMMA" },
  { PHVOLT_T_EQUALS,        	"EQUALS" },
  { PHVOLT_T_NOTEQUALS,     	"NOT EQUALS" },
  { PHVOLT_T_IDENTICAL,     	"IDENTICAL" },
  { PHVOLT_T_NOTIDENTICAL,  	"NOT IDENTICAL" },
  { PHVOLT_T_NOT,           	"NOT" },
  { PHVOLT_T_RANGE,           	"RANGE" },
  { PHVOLT_T_LESS,          	"<" },
  { PHVOLT_T_LESSEQUAL,     	"<=" },
  { PHVOLT_T_GREATER,       	">" },
  { PHVOLT_T_GREATEREQUAL,  	">=" },
  { PHVOLT_T_BRACKET_OPEN,  	"(" },
  { PHVOLT_T_BRACKET_CLOSE, 	")" },
  { PHVOLT_T_OPEN_DELIMITER, 	"{%" },
  { PHVOLT_T_CLOSE_DELIMITER, 	"%}" },
  { PHVOLT_T_OPEN_DELIMITER, 	"{{" },
  { PHVOLT_T_CLOSE_DELIMITER, 	"}}" },
  { PHVOLT_T_IF,           		"IF" },
  { PHVOLT_T_ELSE,           	"ELSE" },
  { PHVOLT_T_ENDIF,           	"ENDIF" },
  { PHVOLT_T_FOR,           	"FOR" },
  { PHVOLT_T_IN, 	          	"IN" },
  { PHVOLT_T_ENDFOR,           	"ENDFOR" },
  { PHVOLT_T_SET,           	"SET" },
  { PHVOLT_T_ASSIGN,           	"ASSIGN" },
  {  0, NULL }
};

static void *phvolt_wrapper_alloc(size_t bytes){
	return emalloc(bytes);
}

static void phvolt_wrapper_free(void *pointer){
	efree(pointer);
}

static void phvolt_parse_with_token(void* phvolt_parser, int opcode, int parsercode, phvolt_scanner_token *token, phvolt_parser_status *parser_status){
	phvolt_parser_token *pToken;
	pToken = emalloc(sizeof(phvolt_parser_token));
	pToken->opcode = opcode;
	pToken->token = token->value;
	pToken->token_len = token->len;
	phvolt_(phvolt_parser, parsercode, pToken, parser_status);
}

int phvolt_parse_view(zval *result, zval *view_code TSRMLS_DC){

	zval *error_msg;

	ZVAL_NULL(result);

	if(phvolt_internal_parse_view(&result, Z_STRVAL_P(view_code), &error_msg TSRMLS_CC) == FAILURE){
		phalcon_throw_exception_string(phalcon_mvc_view_exception_ce, Z_STRVAL_P(error_msg), Z_STRLEN_P(error_msg) TSRMLS_CC);
		return FAILURE;
	}

	return SUCCESS;
}

int phvolt_internal_parse_view(zval **result, char *view_code, zval **error_msg TSRMLS_DC) {

	char *error;
	phvolt_scanner_state *state;
	phvolt_scanner_token *token;
	int scanner_status, status = SUCCESS;
	phvolt_parser_status *parser_status = NULL;
	void* phvolt_parser;

	if (!view_code) {
		PHALCON_INIT_VAR(*error_msg);
		ZVAL_STRING(*error_msg, "View code cannot be null", 1);
		return FAILURE;
	}

	phvolt_parser = phvolt_Alloc(phvolt_wrapper_alloc);

	parser_status = emalloc(sizeof(phvolt_parser_status));
	state = emalloc(sizeof(phvolt_scanner_state));
	token = emalloc(sizeof(phvolt_scanner_token));

	parser_status->status = PHVOLT_PARSING_OK;
	parser_status->scanner_state = state;
	parser_status->ret = NULL;

	/** Initialize the scanner state */
	state->active_token = 0;
	state->start = view_code;
	state->mode = PHVOLT_MODE_RAW;
	state->raw_buffer = emalloc(sizeof(char) * PHVOLT_RAW_BUFFER_SIZE);
	state->raw_buffer_size = PHVOLT_RAW_BUFFER_SIZE;
	state->raw_buffer_cursor = 0;

	state->end = state->start;

	while(0 <= (scanner_status = phvolt_get_token(state, token))) {

		state->active_token = token->opcode;

		switch(token->opcode){

			case PHVOLT_T_IGNORE:
				break;

			case PHVOLT_T_ADD:
				phvolt_(phvolt_parser, PHVOLT_PLUS, NULL, parser_status);
				break;
			case PHVOLT_T_SUB:
				phvolt_(phvolt_parser, PHVOLT_MINUS, NULL, parser_status);
				break;
			case PHVOLT_T_MUL:
				phvolt_(phvolt_parser, PHVOLT_TIMES, NULL, parser_status);
				break;
			case PHVOLT_T_DIV:
				phvolt_(phvolt_parser, PHVOLT_DIVIDE, NULL, parser_status);
				break;
			case PHVOLT_T_MOD:
				phvolt_(phvolt_parser, PHVOLT_MOD, NULL, parser_status);
				break;
			case PHVOLT_T_AND:
				phvolt_(phvolt_parser, PHVOLT_AND, NULL, parser_status);
				break;
			case PHVOLT_T_OR:
				phvolt_(phvolt_parser, PHVOLT_OR, NULL, parser_status);
				break;
			case PHVOLT_T_EQUALS:
				phvolt_(phvolt_parser, PHVOLT_EQUALS, NULL, parser_status);
				break;
			case PHVOLT_T_NOTEQUALS:
				phvolt_(phvolt_parser, PHVOLT_NOTEQUALS, NULL, parser_status);
				break;
			case PHVOLT_T_LESS:
				phvolt_(phvolt_parser, PHVOLT_LESS, NULL, parser_status);
				break;
			case PHVOLT_T_GREATER:
				phvolt_(phvolt_parser, PHVOLT_GREATER, NULL, parser_status);
				break;
			case PHVOLT_T_GREATEREQUAL:
				phvolt_(phvolt_parser, PHVOLT_GREATEREQUAL, NULL, parser_status);
				break;
			case PHVOLT_T_LESSEQUAL:
				phvolt_(phvolt_parser, PHVOLT_LESSEQUAL, NULL, parser_status);
				break;
			case PHVOLT_T_IDENTICAL:
				phvolt_(phvolt_parser, PHVOLT_IDENTICAL, NULL, parser_status);
				break;
			case PHVOLT_T_NOTIDENTICAL:
				phvolt_(phvolt_parser, PHVOLT_NOTIDENTICAL, NULL, parser_status);
				break;
			case PHVOLT_T_NOT:
				phvolt_(phvolt_parser, PHVOLT_NOT, NULL, parser_status);
				break;
			case PHVOLT_T_DOT:
				phvolt_(phvolt_parser, PHVOLT_DOT, NULL, parser_status);
				break;
			case PHVOLT_T_CONCAT:
				phvolt_(phvolt_parser, PHVOLT_CONCAT, NULL, parser_status);
				break;
			case PHVOLT_T_RANGE:
				phvolt_(phvolt_parser, PHVOLT_RANGE, NULL, parser_status);
				break;
			case PHVOLT_T_PIPE:
				phvolt_(phvolt_parser, PHVOLT_PIPE, NULL, parser_status);
				break;
			case PHVOLT_T_COMMA:
				phvolt_(phvolt_parser, PHVOLT_COMMA, NULL, parser_status);
				break;
			case PHVOLT_T_DOUBLECOLON:
				phvolt_(phvolt_parser, PHVOLT_DOUBLECOLON, NULL, parser_status);
				break;

			case PHVOLT_T_BRACKET_OPEN:
				phvolt_(phvolt_parser, PHVOLT_BRACKET_OPEN, NULL, parser_status);
				break;
			case PHVOLT_T_BRACKET_CLOSE:
				phvolt_(phvolt_parser, PHVOLT_BRACKET_CLOSE, NULL, parser_status);
				break;
			case PHVOLT_T_SBRACKET_OPEN:
				phvolt_(phvolt_parser, PHVOLT_SBRACKET_OPEN, NULL, parser_status);
				break;
			case PHVOLT_T_SBRACKET_CLOSE:
				phvolt_(phvolt_parser, PHVOLT_SBRACKET_CLOSE, NULL, parser_status);
				break;

			case PHVOLT_T_OPEN_DELIMITER:
				phvolt_(phvolt_parser, PHVOLT_OPEN_DELIMITER, NULL, parser_status);
				break;
			case PHVOLT_T_CLOSE_DELIMITER:
				phvolt_(phvolt_parser, PHVOLT_CLOSE_DELIMITER, NULL, parser_status);
				break;

			case PHVOLT_T_OPEN_EDELIMITER:
				phvolt_(phvolt_parser, PHVOLT_OPEN_EDELIMITER, NULL, parser_status);
				break;
			case PHVOLT_T_CLOSE_EDELIMITER:
				phvolt_(phvolt_parser, PHVOLT_CLOSE_EDELIMITER, NULL, parser_status);
				break;

			case PHVOLT_T_IF:
				phvolt_(phvolt_parser, PHVOLT_IF, NULL, parser_status);
				break;
			case PHVOLT_T_ELSE:
				phvolt_(phvolt_parser, PHVOLT_ELSE, NULL, parser_status);
				break;
			case PHVOLT_T_ENDIF:
				phvolt_(phvolt_parser, PHVOLT_ENDIF, NULL, parser_status);
				break;
			case PHVOLT_T_FOR:
				phvolt_(phvolt_parser, PHVOLT_FOR, NULL, parser_status);
				break;
			case PHVOLT_T_IN:
				phvolt_(phvolt_parser, PHVOLT_IN, NULL, parser_status);
				break;
			case PHVOLT_T_ENDFOR:
				phvolt_(phvolt_parser, PHVOLT_ENDFOR, NULL, parser_status);
				break;

			case PHVOLT_T_RAW_FRAGMENT:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_RAW_FRAGMENT, PHVOLT_RAW_FRAGMENT, token, parser_status);
				break;

			case PHVOLT_T_SET:
				phvolt_(phvolt_parser, PHVOLT_SET, NULL, parser_status);
				break;
			case PHVOLT_T_ASSIGN:
				phvolt_(phvolt_parser, PHVOLT_ASSIGN, NULL, parser_status);
				break;

			case PHVOLT_T_NULL:
				phvolt_(phvolt_parser, PHVOLT_NULL, NULL, parser_status);
				break;
			case PHVOLT_T_TRUE:
				phvolt_(phvolt_parser, PHVOLT_TRUE, NULL, parser_status);
				break;
			case PHVOLT_T_FALSE:
				phvolt_(phvolt_parser, PHVOLT_FALSE, NULL, parser_status);
				break;

			case PHVOLT_T_INTEGER:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_INTEGER, PHVOLT_INTEGER, token, parser_status);
				break;
			case PHVOLT_T_DOUBLE:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_DOUBLE, PHVOLT_DOUBLE, token, parser_status);
				break;
			case PHVOLT_T_STRING:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_STRING, PHVOLT_STRING, token, parser_status);
				break;
			case PHVOLT_T_IDENTIFIER:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_IDENTIFIER, PHVOLT_IDENTIFIER, token, parser_status);
				break;

			default:
				status = FAILURE;
				error = emalloc(sizeof(char) * 32);
				sprintf(error, "scanner: unknown opcode %c", token->opcode);
				PHALCON_ALLOC_ZVAL_MM(*error_msg);
				ZVAL_STRING(*error_msg, error, 1);
				efree(error);
				break;
		}

		if (parser_status->status != PHVOLT_PARSING_OK) {
			status = FAILURE;
			break;
		}

		state->end = state->start;
	}

	state->active_token = 0;
	state->start = NULL;
	efree(state->raw_buffer);

	if (status != FAILURE) {
		switch (scanner_status) {
			case PHVOLT_SCANNER_RETCODE_ERR:
			case PHVOLT_SCANNER_RETCODE_IMPOSSIBLE:
				PHALCON_ALLOC_ZVAL_MM(*error_msg);
				if (state->start) {
					error = emalloc(sizeof(char)*(48+strlen(state->start)));
					sprintf(error, "Parsing error near to %s (%d)", state->start, status);
					ZVAL_STRING(*error_msg, error, 1);
					efree(error);
				} else {
					ZVAL_STRING(*error_msg, "Parsing error near to EOF", 1);
				}
				status = FAILURE;
				break;
			default:
				phvolt_(phvolt_parser, 0, NULL, parser_status);
		}
	}

	if (parser_status->status != PHVOLT_PARSING_OK) {
		status = FAILURE;
		PHALCON_ALLOC_ZVAL_MM(*error_msg);
		ZVAL_STRING(*error_msg, parser_status->syntax_error, 1);
		efree(parser_status->syntax_error);
	}

	phvolt_Free(phvolt_parser, phvolt_wrapper_free);

	if (status != FAILURE) {
		if (parser_status->status == PHVOLT_PARSING_OK) {
			if (parser_status->ret) {
				ZVAL_ZVAL(*result, parser_status->ret, 0, 0);
				ZVAL_NULL(parser_status->ret);
				zval_ptr_dtor(&parser_status->ret);
			} else {
				array_init(*result);
			}
		}
	}

	efree(parser_status);
	efree(state);
	efree(token);

	return status;
}