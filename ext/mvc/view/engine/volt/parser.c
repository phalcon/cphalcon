/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 41 "parser.lemon"


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "parser.h"
#include "scanner.h"
#include "volt.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

static zval *phvolt_ret_literal_zval(int type, phvolt_parser_token *T, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", type);
	if (T) {
		add_assoc_stringl(ret, "value", T->token, T->token_len, 0);
		efree(T);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_if_statement(zval *expr, zval *true_statements, zval *false_statements, phvolt_scanner_state *state)
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

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_elseif_statement(zval *expr, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_ELSEIF);
	add_assoc_zval(ret, "expr", expr);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_elsefor_statement(phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_ELSEFOR);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_for_statement(phvolt_parser_token *variable, phvolt_parser_token *key, zval *expr, zval *if_expr, zval *block_statements, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_FOR);

	add_assoc_stringl(ret, "variable", variable->token, variable->token_len, 0);
	efree(variable);

	if (key) {
		add_assoc_stringl(ret, "key", key->token, key->token_len, 0);
		efree(key);
	}

	add_assoc_zval(ret, "expr", expr);

	if (if_expr) {
		add_assoc_zval(ret, "if_expr", if_expr);
	}

	add_assoc_zval(ret, "block_statements", block_statements);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_cache_statement(zval *expr, phvolt_parser_token *lifetime, zval *block_statements, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_CACHE);
	add_assoc_zval(ret, "expr", expr);

	if (lifetime) {
		add_assoc_stringl(ret, "lifetime", lifetime->token, lifetime->token_len, 0);
		efree(lifetime);
	}
	add_assoc_zval(ret, "block_statements", block_statements);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_set_statement(phvolt_parser_token *variable, zval *expr, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 5);
	add_assoc_long(ret, "type", PHVOLT_T_SET);

	add_assoc_stringl(ret, "variable", variable->token, variable->token_len, 0);
	efree(variable);

	add_assoc_zval(ret, "expr", expr);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_echo_statement(zval *expr, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);
	add_assoc_long(ret, "type", PHVOLT_T_ECHO);
	add_assoc_zval(ret, "expr", expr);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_block_statement(phvolt_parser_token *name, zval *block_statements, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_BLOCK);

	add_assoc_stringl(ret, "name", name->token, name->token_len, 0);
	efree(name);

	if (block_statements) {
		add_assoc_zval(ret, "block_statements", block_statements);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_extends_statement(phvolt_parser_token *P, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	add_assoc_long(ret, "type", PHVOLT_T_EXTENDS);
	add_assoc_stringl(ret, "path", P->token, P->token_len, 0);
	efree(P);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_include_statement(phvolt_parser_token *P, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	add_assoc_long(ret, "type", PHVOLT_T_INCLUDE);

	add_assoc_stringl(ret, "path", P->token, P->token_len, 0);
	efree(P);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_do_statement(zval *expr, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	add_assoc_long(ret, "type", PHVOLT_T_DO);

	add_assoc_zval(ret, "expr", expr);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_autoescape_statement(int enable, zval *block_statements, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 5);

	add_assoc_long(ret, "type", PHVOLT_T_AUTOESCAPE);
	add_assoc_long(ret, "enable", enable);
	add_assoc_zval(ret, "block_statements", block_statements);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_empty_statement(phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 3);
	add_assoc_long(ret, "type", PHVOLT_T_EMPTY);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_break_statement(phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 3);
	add_assoc_long(ret, "type", PHVOLT_T_BREAK);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_continue_statement(phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 3);
	add_assoc_long(ret, "type", PHVOLT_T_CONTINUE);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_zval_list(zval *list_left, zval *right_list)
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

static zval *phvolt_ret_named_item(phvolt_parser_token *name, zval *expr, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_zval(ret, "expr", expr);
	if (name != NULL) {
		add_assoc_stringl(ret, "name", name->token, name->token_len, 0);
		efree(name);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_expr(int type, zval *left, zval *right, zval *ternary, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", type);

	if (ternary) {
		add_assoc_zval(ret, "ternary", ternary);
	}

	if (left) {
		add_assoc_zval(ret, "left", left);
	}

	if (right) {
		add_assoc_zval(ret, "right", right);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_slice(zval *left, zval *start, zval *end, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_SLICE);
	add_assoc_zval(ret, "left", left);

	if (start != NULL) {
		add_assoc_zval(ret, "start", start);
	}

	if (end != NULL) {
		add_assoc_zval(ret, "end", end);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_func_call(zval *expr, zval *arguments, phvolt_scanner_state *state)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_FCALL);
	add_assoc_zval(ret, "name", expr);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}


// 460 "parser.c"
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
**    phvolt_KTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    KKMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is phvolt_KTOKENTYPE.  The entry in the union
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
#define KKNOCODE 92
#define KKACTIONTYPE unsigned short int
#define phvolt_KTOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_KTOKENTYPE kk0;
  zval* kk176;
  int kk183;
} KKMINORTYPE;
#define KKSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = kkpParser->status
#define phvolt_ARG_STORE kkpParser->status = status
#define KKNSTATE 237
#define KKNRULE 98
#define KKERRORSYMBOL 63
#define KKERRSYMDT kk183
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
 /*     0 */    79,   87,  237,   84,   57,   49,   51,   61,   59,   63,
 /*    10 */    69,   71,   73,   75,   65,   67,   45,   43,   47,   40,
 /*    20 */    37,   53,   55,   81,   91,   77,  214,  149,   79,   87,
 /*    30 */    27,   84,   57,   49,   51,   61,   59,   63,   69,   71,
 /*    40 */    73,   75,   65,   67,   45,   43,   47,   40,   37,   53,
 /*    50 */    55,   81,   91,   77,   29,  169,   45,   43,   47,   40,
 /*    60 */    37,   53,   55,   81,   91,   77,   55,   81,   91,   77,
 /*    70 */    33,  205,   81,   91,   77,   79,   87,   82,   84,   57,
 /*    80 */    49,   51,   61,   59,   63,   69,   71,   73,   75,   65,
 /*    90 */    67,   45,   43,   47,   40,   37,   53,   55,   81,   91,
 /*   100 */    77,  230,  225,   79,   87,  127,   84,   57,   49,   51,
 /*   110 */    61,   59,   63,   69,   71,   73,   75,   65,   67,   45,
 /*   120 */    43,   47,   40,   37,   53,   55,   81,   91,   77,   22,
 /*   130 */    23,   79,   87,  108,   84,   57,   49,   51,   61,   59,
 /*   140 */    63,   69,   71,   73,   75,   65,   67,   45,   43,   47,
 /*   150 */    40,   37,   53,   55,   81,   91,   77,   35,   36,   79,
 /*   160 */    87,  108,   84,   57,   49,   51,   61,   59,   63,   69,
 /*   170 */    71,   73,   75,   65,   67,   45,   43,   47,   40,   37,
 /*   180 */    53,   55,   81,   91,   77,   79,   87,   89,   84,   57,
 /*   190 */    49,   51,   61,   59,   63,   69,   71,   73,   75,   65,
 /*   200 */    67,   45,   43,   47,   40,   37,   53,   55,   81,   91,
 /*   210 */    77,  221,  147,  106,   79,   87,   86,   84,   57,   49,
 /*   220 */    51,   61,   59,   63,   69,   71,   73,   75,   65,   67,
 /*   230 */    45,   43,   47,   40,   37,   53,   55,   81,   91,   77,
 /*   240 */    79,   87,  144,   84,   57,   49,   51,   61,   59,   63,
 /*   250 */    69,   71,   73,   75,   65,   67,   45,   43,   47,   40,
 /*   260 */    37,   53,   55,   81,   91,   77,  122,  158,   79,   87,
 /*   270 */    97,   84,   57,   49,   51,   61,   59,   63,   69,   71,
 /*   280 */    73,   75,   65,   67,   45,   43,   47,   40,   37,   53,
 /*   290 */    55,   81,   91,   77,  142,  182,   79,   87,  108,   84,
 /*   300 */    57,   49,   51,   61,   59,   63,   69,   71,   73,   75,
 /*   310 */    65,   67,   45,   43,   47,   40,   37,   53,   55,   81,
 /*   320 */    91,   77,   40,   37,   53,   55,   81,   91,   77,   99,
 /*   330 */   101,   92,  116,  108,  196,  108,  117,  125,   79,   87,
 /*   340 */   134,   84,   57,   49,   51,   61,   59,   63,   69,   71,
 /*   350 */    73,   75,   65,   67,   45,   43,   47,   40,   37,   53,
 /*   360 */    55,   81,   91,   77,   39,  216,   79,   87,  108,   84,
 /*   370 */    57,   49,   51,   61,   59,   63,   69,   71,   73,   75,
 /*   380 */    65,   67,   45,   43,   47,   40,   37,   53,   55,   81,
 /*   390 */    91,   77,  141,  232,   79,   87,  108,   84,   57,   49,
 /*   400 */    51,   61,   59,   63,   69,   71,   73,   75,   65,   67,
 /*   410 */    45,   43,   47,   40,   37,   53,   55,   81,   91,   77,
 /*   420 */    87,  128,   84,   57,   49,   51,   61,   59,   63,   69,
 /*   430 */    71,   73,   75,   65,   67,   45,   43,   47,   40,   37,
 /*   440 */    53,   55,   81,   91,   77,   84,   57,   49,   51,   61,
 /*   450 */    59,   63,   69,   71,   73,   75,   65,   67,   45,   43,
 /*   460 */    47,   40,   37,   53,   55,   81,   91,   77,   49,   51,
 /*   470 */    61,   59,   63,   69,   71,   73,   75,   65,   67,   45,
 /*   480 */    43,   47,   40,   37,   53,   55,   81,   91,   77,  336,
 /*   490 */     1,    2,  198,    4,    5,    6,    7,    8,    9,   10,
 /*   500 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   61,
 /*   510 */    59,   63,   69,   71,   73,   75,   65,   67,   45,   43,
 /*   520 */    47,   40,   37,   53,   55,   81,   91,   77,   24,  198,
 /*   530 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   540 */    14,   15,   16,   17,   18,   19,   30,  198,    4,    5,
 /*   550 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   560 */    16,   17,   18,   19,  150,  198,    4,    5,    6,    7,
 /*   570 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   580 */    18,   19,  163,  198,    4,    5,    6,    7,    8,    9,
 /*   590 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   600 */   170,  198,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   610 */    12,   13,   14,   15,   16,   17,   18,   19,  186,  198,
 /*   620 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   630 */    14,   15,   16,   17,   18,   19,  201,  198,    4,    5,
 /*   640 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   650 */    16,   17,   18,   19,  207,  198,    4,    5,    6,    7,
 /*   660 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   670 */    18,   19,  217,  198,    4,    5,    6,    7,    8,    9,
 /*   680 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   690 */   226,  198,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   700 */    12,   13,   14,   15,   16,   17,   18,   19,  233,  198,
 /*   710 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   720 */    14,   15,   16,   17,   18,   19,    3,    4,    5,    6,
 /*   730 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   740 */    17,   18,   19,   21,  159,   26,   28,   34,  143,  145,
 /*   750 */   238,   20,  154,   85,  103,  131,  160,  108,  167,  132,
 /*   760 */   315,  174,   92,  177,  180,  183,  108,  316,  120,  190,
 /*   770 */   192,   21,  159,   32,  119,   34,  143,  145,   99,   20,
 /*   780 */   154,  104,  108,   42,  160,  135,  167,  108,  315,  174,
 /*   790 */   194,  177,  180,  183,  316,   21,  159,  190,  192,   34,
 /*   800 */   143,  145,   44,  152,  154,   46,  108,  197,  160,  108,
 /*   810 */   167,  146,  102,  174,  153,  177,  180,  183,  194,   21,
 /*   820 */   159,  190,  192,   34,  143,  145,  156,   25,  154,  155,
 /*   830 */   161,  118,  160,  165,  167,  197,   31,  174,  222,  177,
 /*   840 */   180,  183,  151,   21,  159,  190,  192,   34,  143,  145,
 /*   850 */   162,  211,  154,   48,  166,  173,  160,  108,  167,  172,
 /*   860 */   184,  174,  199,  177,  180,  183,  194,   21,  159,  190,
 /*   870 */   192,   34,  143,  145,  176,  194,  154,  175,  178,  223,
 /*   880 */   160,  194,  167,  197,  179,  174,  185,  177,  180,  183,
 /*   890 */   194,  188,  197,  190,  192,   21,  159,  189,  197,   34,
 /*   900 */   143,  145,   50,  164,  154,   52,  108,  197,  160,  108,
 /*   910 */   167,  191,  193,  174,  200,  177,  180,  183,  204,  203,
 /*   920 */   206,  190,  192,   21,  159,  171,   54,   34,  143,  145,
 /*   930 */   108,  187,  154,   56,  210,  213,  160,  108,  167,  209,
 /*   940 */   220,  174,  194,  177,  180,  183,  202,   21,  159,  190,
 /*   950 */   192,   34,  143,  145,   58,  208,  154,  229,  108,  197,
 /*   960 */   160,  212,  167,  236,  194,  174,  191,  177,  180,  183,
 /*   970 */   194,   21,  159,  190,  192,   34,  143,  145,  191,  219,
 /*   980 */   154,  197,  191,  191,  160,  194,  167,  197,  191,  174,
 /*   990 */   191,  177,  180,  183,  194,   21,  159,  190,  192,   34,
 /*  1000 */   143,  145,  197,  228,  154,  191,  191,  191,  160,  191,
 /*  1010 */   167,  197,  191,  174,  191,  177,  180,  183,  191,   21,
 /*  1020 */   159,  190,  192,   34,  143,  145,  191,  235,  154,  191,
 /*  1030 */   191,   60,  160,  191,  167,  108,  218,  174,  227,  177,
 /*  1040 */   180,  183,  191,   21,  159,  190,  192,   34,  143,  145,
 /*  1050 */   191,   98,  154,   62,  191,   64,  160,  108,  167,  108,
 /*  1060 */   191,  174,   66,  177,  180,  183,  108,   41,   38,  190,
 /*  1070 */   192,  138,   95,  234,  130,  194,   68,  194,   70,   72,
 /*  1080 */   108,  109,  108,  108,  129,   74,   76,  126,   98,  108,
 /*  1090 */   108,  110,  197,  111,  197,  191,   78,  114,  133,  115,
 /*  1100 */   108,  130,  191,  140,   41,   38,  112,  113,   93,   95,
 /*  1110 */    80,  129,  194,   83,  108,  191,   88,  108,  137,  191,
 /*  1120 */   108,  191,  191,   90,  191,   98,  191,  108,  136,  197,
 /*  1130 */   111,   94,  191,   96,  114,  108,  115,  108,  191,  191,
 /*  1140 */   191,   41,   38,  112,  113,   93,   95,  107,  123,  191,
 /*  1150 */   148,  108,  108,  157,  108,  109,  191,  108,  168,  181,
 /*  1160 */   195,  191,  108,  108,  108,  110,  191,  121,  191,  191,
 /*  1170 */   215,  114,   98,  115,  108,  224,  191,  191,  124,  108,
 /*  1180 */   112,  113,  231,  191,  191,  191,  108,  191,   41,   38,
 /*  1190 */   191,  191,   93,   95,  191,  191,  191,  191,  191,  191,
 /*  1200 */   191,  191,  109,  191,  191,  191,  191,  191,  191,  191,
 /*  1210 */   191,  191,  110,  191,  105,  191,  191,  191,  114,   98,
 /*  1220 */   115,  191,  191,  191,  191,  191,  100,  112,  113,  191,
 /*  1230 */   191,  191,  191,  191,  191,   41,   38,  191,  191,   93,
 /*  1240 */    95,  191,  191,  191,  191,  191,  191,  191,  191,  109,
 /*  1250 */   191,  191,  191,  191,  191,  191,   98,  191,  191,  110,
 /*  1260 */   191,  111,  191,  191,  191,  114,  191,  115,  191,  191,
 /*  1270 */   191,  139,   41,   38,  112,  113,   93,   95,  191,  191,
 /*  1280 */   191,  191,  191,  191,  191,  191,  109,  191,  191,  191,
 /*  1290 */   191,  191,  191,   98,  191,  191,  110,  191,  111,  191,
 /*  1300 */   191,  191,  114,  191,  115,  191,  191,  191,  191,   41,
 /*  1310 */    38,  112,  113,   93,   95,  191,  191,  191,  191,  191,
 /*  1320 */   191,  191,  191,  109,  191,  191,  191,  191,  191,  191,
 /*  1330 */    98,  191,  191,  110,  191,  105,  191,  191,  191,  114,
 /*  1340 */   191,  115,  191,  191,  191,  191,   41,   38,  112,  113,
 /*  1350 */    93,   95,  191,  191,  191,  191,  191,  191,  191,  191,
 /*  1360 */   109,  191,  191,  191,  191,  191,  191,  191,  191,  191,
 /*  1370 */   110,  191,  121,  191,  191,  191,  114,  191,  115,  191,
 /*  1380 */   191,  191,  191,  191,  191,  112,  113,
};
static KKCODETYPE kk_lookahead[] = {
 /*     0 */     3,    4,    0,    6,    7,    8,    9,   10,   11,   12,
 /*    10 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    20 */    23,   24,   25,   26,   27,   28,   29,   30,    3,    4,
 /*    30 */    30,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*    40 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*    50 */    25,   26,   27,   28,   30,   30,   19,   20,   21,   22,
 /*    60 */    23,   24,   25,   26,   27,   28,   25,   26,   27,   28,
 /*    70 */    30,   46,   26,   27,   28,    3,    4,    3,    6,    7,
 /*    80 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    90 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   100 */    28,   29,   30,    3,    4,   86,    6,    7,    8,    9,
 /*   110 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   120 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   84,
 /*   130 */    30,    3,    4,   88,    6,    7,    8,    9,   10,   11,
 /*   140 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   150 */    22,   23,   24,   25,   26,   27,   28,   84,   30,    3,
 /*   160 */     4,   88,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   170 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   180 */    24,   25,   26,   27,   28,    3,    4,    5,    6,    7,
 /*   190 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   200 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   210 */    28,    2,    3,    5,    3,    4,   60,    6,    7,    8,
 /*   220 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   230 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   240 */     3,    4,   30,    6,    7,    8,    9,   10,   11,   12,
 /*   250 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   260 */    23,   24,   25,   26,   27,   28,    5,   30,    3,    4,
 /*   270 */    59,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   280 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   290 */    25,   26,   27,   28,   84,   30,    3,    4,   88,    6,
 /*   300 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   310 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   320 */    27,   28,   22,   23,   24,   25,   26,   27,   28,   84,
 /*   330 */    85,   84,   87,   88,   41,   88,   89,   90,    3,    4,
 /*   340 */    86,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   350 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   360 */    25,   26,   27,   28,   84,   30,    3,    4,   88,    6,
 /*   370 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   380 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   390 */    27,   28,   84,   30,    3,    4,   88,    6,    7,    8,
 /*   400 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   410 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   420 */     4,   60,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   430 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   440 */    24,   25,   26,   27,   28,    6,    7,    8,    9,   10,
 /*   450 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   460 */    21,   22,   23,   24,   25,   26,   27,   28,    8,    9,
 /*   470 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   480 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   64,
 /*   490 */    65,   66,   67,   68,   69,   70,   71,   72,   73,   74,
 /*   500 */    75,   76,   77,   78,   79,   80,   81,   82,   83,   10,
 /*   510 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   520 */    21,   22,   23,   24,   25,   26,   27,   28,   66,   67,
 /*   530 */    68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
 /*   540 */    78,   79,   80,   81,   82,   83,   66,   67,   68,   69,
 /*   550 */    70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
 /*   560 */    80,   81,   82,   83,   66,   67,   68,   69,   70,   71,
 /*   570 */    72,   73,   74,   75,   76,   77,   78,   79,   80,   81,
 /*   580 */    82,   83,   66,   67,   68,   69,   70,   71,   72,   73,
 /*   590 */    74,   75,   76,   77,   78,   79,   80,   81,   82,   83,
 /*   600 */    66,   67,   68,   69,   70,   71,   72,   73,   74,   75,
 /*   610 */    76,   77,   78,   79,   80,   81,   82,   83,   66,   67,
 /*   620 */    68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
 /*   630 */    78,   79,   80,   81,   82,   83,   66,   67,   68,   69,
 /*   640 */    70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
 /*   650 */    80,   81,   82,   83,   66,   67,   68,   69,   70,   71,
 /*   660 */    72,   73,   74,   75,   76,   77,   78,   79,   80,   81,
 /*   670 */    82,   83,   66,   67,   68,   69,   70,   71,   72,   73,
 /*   680 */    74,   75,   76,   77,   78,   79,   80,   81,   82,   83,
 /*   690 */    66,   67,   68,   69,   70,   71,   72,   73,   74,   75,
 /*   700 */    76,   77,   78,   79,   80,   81,   82,   83,   66,   67,
 /*   710 */    68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
 /*   720 */    78,   79,   80,   81,   82,   83,   67,   68,   69,   70,
 /*   730 */    71,   72,   73,   74,   75,   76,   77,   78,   79,   80,
 /*   740 */    81,   82,   83,   29,   30,   31,   32,   33,   34,   35,
 /*   750 */     0,    1,   38,   84,    2,   86,   42,   88,   44,    5,
 /*   760 */    60,   47,   84,   49,   50,   51,   88,   60,   90,   55,
 /*   770 */    56,   29,   30,   31,    2,   33,   34,   35,   84,    1,
 /*   780 */    38,   87,   88,   84,   42,   60,   44,   88,    5,   47,
 /*   790 */    40,   49,   50,   51,    5,   29,   30,   55,   56,   33,
 /*   800 */    34,   35,   84,   37,   38,   84,   88,   57,   42,   88,
 /*   810 */    44,   36,   60,   47,   30,   49,   50,   51,   40,   29,
 /*   820 */    30,   55,   56,   33,   34,   35,   39,    1,   38,   36,
 /*   830 */    36,   59,   42,   43,   44,   57,    1,   47,   36,   49,
 /*   840 */    50,   51,    1,   29,   30,   55,   56,   33,   34,   35,
 /*   850 */    30,    1,   38,   84,   30,   30,   42,   88,   44,   45,
 /*   860 */    52,   47,   54,   49,   50,   51,   40,   29,   30,   55,
 /*   870 */    56,   33,   34,   35,   30,   40,   38,   48,   48,    3,
 /*   880 */    42,   40,   44,   57,   30,   47,   30,   49,   50,   51,
 /*   890 */    40,   53,   57,   55,   56,   29,   30,   30,   57,   33,
 /*   900 */    34,   35,   84,    1,   38,   84,   88,   57,   42,   88,
 /*   910 */    44,   30,   30,   47,   30,   49,   50,   51,   30,   53,
 /*   920 */    30,   55,   56,   29,   30,    1,   84,   33,   34,   35,
 /*   930 */    88,    1,   38,   84,   30,   30,   42,   88,   44,   45,
 /*   940 */    30,   47,   40,   49,   50,   51,    1,   29,   30,   55,
 /*   950 */    56,   33,   34,   35,   84,    1,   38,   30,   88,   57,
 /*   960 */    42,   43,   44,   30,   40,   47,   91,   49,   50,   51,
 /*   970 */    40,   29,   30,   55,   56,   33,   34,   35,   91,   37,
 /*   980 */    38,   57,   91,   91,   42,   40,   44,   57,   91,   47,
 /*   990 */    91,   49,   50,   51,   40,   29,   30,   55,   56,   33,
 /*  1000 */    34,   35,   57,   37,   38,   91,   91,   91,   42,   91,
 /*  1010 */    44,   57,   91,   47,   91,   49,   50,   51,   91,   29,
 /*  1020 */    30,   55,   56,   33,   34,   35,   91,   37,   38,   91,
 /*  1030 */    91,   84,   42,   91,   44,   88,    1,   47,    1,   49,
 /*  1040 */    50,   51,   91,   29,   30,   55,   56,   33,   34,   35,
 /*  1050 */    91,    6,   38,   84,   91,   84,   42,   88,   44,   88,
 /*  1060 */    91,   47,   84,   49,   50,   51,   88,   22,   23,   55,
 /*  1070 */    56,   26,   27,    1,   36,   40,   84,   40,   84,   84,
 /*  1080 */    88,   36,   88,   88,   46,   84,   84,    5,    6,   88,
 /*  1090 */    88,   46,   57,   48,   57,   91,   84,   52,   60,   54,
 /*  1100 */    88,   36,   91,   58,   22,   23,   61,   62,   26,   27,
 /*  1110 */    84,   46,   40,   84,   88,   91,   84,   88,   36,   91,
 /*  1120 */    88,   91,   91,   84,   91,    6,   91,   88,   46,   57,
 /*  1130 */    48,   84,   91,   84,   52,   88,   54,   88,   91,   91,
 /*  1140 */    91,   22,   23,   61,   62,   26,   27,   84,   84,   91,
 /*  1150 */    84,   88,   88,   84,   88,   36,   91,   88,   84,   84,
 /*  1160 */    84,   91,   88,   88,   88,   46,   91,   48,   91,   91,
 /*  1170 */    84,   52,    6,   54,   88,   84,   91,   91,   59,   88,
 /*  1180 */    61,   62,   84,   91,   91,   91,   88,   91,   22,   23,
 /*  1190 */    91,   91,   26,   27,   91,   91,   91,   91,   91,   91,
 /*  1200 */    91,   91,   36,   91,   91,   91,   91,   91,   91,   91,
 /*  1210 */    91,   91,   46,   91,   48,   91,   91,   91,   52,    6,
 /*  1220 */    54,   91,   91,   91,   91,   91,   60,   61,   62,   91,
 /*  1230 */    91,   91,   91,   91,   91,   22,   23,   91,   91,   26,
 /*  1240 */    27,   91,   91,   91,   91,   91,   91,   91,   91,   36,
 /*  1250 */    91,   91,   91,   91,   91,   91,    6,   91,   91,   46,
 /*  1260 */    91,   48,   91,   91,   91,   52,   91,   54,   91,   91,
 /*  1270 */    91,   58,   22,   23,   61,   62,   26,   27,   91,   91,
 /*  1280 */    91,   91,   91,   91,   91,   91,   36,   91,   91,   91,
 /*  1290 */    91,   91,   91,    6,   91,   91,   46,   91,   48,   91,
 /*  1300 */    91,   91,   52,   91,   54,   91,   91,   91,   91,   22,
 /*  1310 */    23,   61,   62,   26,   27,   91,   91,   91,   91,   91,
 /*  1320 */    91,   91,   91,   36,   91,   91,   91,   91,   91,   91,
 /*  1330 */     6,   91,   91,   46,   91,   48,   91,   91,   91,   52,
 /*  1340 */    91,   54,   91,   91,   91,   91,   22,   23,   61,   62,
 /*  1350 */    26,   27,   91,   91,   91,   91,   91,   91,   91,   91,
 /*  1360 */    36,   91,   91,   91,   91,   91,   91,   91,   91,   91,
 /*  1370 */    46,   91,   48,   91,   91,   91,   52,   91,   54,   91,
 /*  1380 */    91,   91,   91,   91,   91,   61,   62,
};
#define KK_SHIFT_USE_DFLT (-4)
static short kk_shift_ofst[] = {
 /*     0 */   778,    2,  750,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    20 */  1014, 1250,  100,  778,  826,  714,    0,   -4,   24,  778,
 /*    30 */   835,  742,   40,   -4, 1250,  128,   -4, 1250, 1250,   41,
 /*    40 */  1250, 1250,   41, 1250,  300, 1250,  300, 1250,  300, 1250,
 /*    50 */   499, 1250,  499, 1250,   41, 1250,   46, 1250,  460, 1250,
 /*    60 */    37, 1045,   37, 1250,   37, 1250,   37, 1250,   37, 1250,
 /*    70 */    37, 1250,   37, 1250,   37, 1250,   37, 1250,   -4, 1250,
 /*    80 */   416,   74, 1250,   46, 1082,  156,   -4, 1250,  182, 1250,
 /*    90 */   439, 1119,  391, 1250,   46, 1250,  211,   -4, 1166,  391,
 /*   100 */    -4,  752,   -4, 1287,   -4,  208, 1250,  391,   -4,   -4,
 /*   110 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,  772,   -4, 1324,
 /*   120 */    -4,  261, 1250,  391,   -4,   -4, 1065,  361,   -4,  700,
 /*   130 */   707,  754, 1038,   -4,  725,   -4,  783,  789, 1213,   -4,
 /*   140 */    -4,   41,   41,  212,   -4,  775,  209, 1250,   -3,  778,
 /*   150 */   841,  766,  784,   -4,  793,  787, 1250,  237,   -4,   -4,
 /*   160 */   794,  820,  850,  902,  790,  824,   -4, 1250,   25,  778,
 /*   170 */   924,  814,  825,   -4,  829,  844,   -4,  830,  854,   -4,
 /*   180 */  1250,  265,   -4,  808,  856,  778,  930,  838,  867,   -4,
 /*   190 */   881,   -4,  882,   -4, 1250,  293,   -4,   -4,   -4,  884,
 /*   200 */   778,  945,  866,  888,   -4,  890,  778,  954,  894,  904,
 /*   210 */    -4,  918,  905,   -4, 1250,  335,  778, 1035,  942,  910,
 /*   220 */    -4,  802,  876, 1250,   72,  778, 1037,  966,  927,   -4,
 /*   230 */  1250,  363,  778, 1072,  990,  933,   -4,
};
#define KK_REDUCE_USE_DFLT (-1)
static short kk_reduce_ofst[] = {
 /*     0 */   425,   -1,  659,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*    10 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*    20 */    -1,   45,   -1,  462,  659,   -1,   -1,   -1,   -1,  480,
 /*    30 */   659,   -1,   -1,   -1,   73,   -1,   -1,  210,  280,   -1,
 /*    40 */   308,  699,   -1,  718,   -1,  721,   -1,  769,   -1,  818,
 /*    50 */    -1,  821,   -1,  842,   -1,  849,   -1,  870,   -1,  947,
 /*    60 */    -1,  969,   -1,  971,   -1,  978,   -1,  992,   -1,  994,
 /*    70 */    -1,  995,   -1, 1001,   -1, 1002,   -1, 1012,   -1, 1026,
 /*    80 */    -1,   -1, 1029,   -1,  669,   -1,   -1, 1032,   -1, 1039,
 /*    90 */    -1,  247,   -1, 1047,   -1, 1049,   -1,   -1,  245,   -1,
 /*   100 */    -1,   -1,   -1,  694,   -1,   -1, 1063,   -1,   -1,   -1,
 /*   110 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  678,
 /*   120 */    -1,   -1, 1064,   -1,   -1,   -1,   19,   -1,   -1,   -1,
 /*   130 */    -1,   -1,  254,   -1,   -1,   -1,   -1,   -1, 1047,   -1,
 /*   140 */    -1,   -1,   -1,   -1,   -1,   -1,   -1, 1066,   -1,  498,
 /*   150 */   659,   -1,   -1,   -1,   -1,   -1, 1069,   -1,   -1,   -1,
 /*   160 */    -1,   -1,  516,  659,   -1,   -1,   -1, 1074,   -1,  534,
 /*   170 */   659,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   180 */  1075,   -1,   -1,   -1,   -1,  552,  659,   -1,   -1,   -1,
 /*   190 */    -1,   -1,   -1,   -1, 1076,   -1,   -1,   -1,   -1,   -1,
 /*   200 */   570,  659,   -1,   -1,   -1,   -1,  588,  659,   -1,   -1,
 /*   210 */    -1,   -1,   -1,   -1, 1086,   -1,  606,  659,   -1,   -1,
 /*   220 */    -1,   -1,   -1, 1091,   -1,  624,  659,   -1,   -1,   -1,
 /*   230 */  1098,   -1,  642,  659,   -1,   -1,   -1,
};
static KKACTIONTYPE kk_default[] = {
 /*     0 */   335,  335,  335,  239,  241,  242,  243,  244,  245,  246,
 /*    10 */   247,  248,  249,  250,  251,  252,  253,  254,  255,  256,
 /*    20 */   335,  335,  335,  335,  335,  335,  335,  257,  335,  335,
 /*    30 */   335,  335,  335,  258,  335,  335,  259,  335,  335,  280,
 /*    40 */   335,  335,  281,  335,  284,  335,  285,  335,  286,  335,
 /*    50 */   287,  335,  288,  335,  289,  335,  290,  335,  291,  335,
 /*    60 */   292,  335,  295,  335,  296,  335,  297,  335,  298,  335,
 /*    70 */   299,  335,  300,  335,  301,  335,  302,  335,  303,  335,
 /*    80 */   304,  335,  335,  305,  335,  335,  310,  335,  335,  335,
 /*    90 */   311,  335,  326,  335,  306,  335,  335,  307,  335,  320,
 /*   100 */   308,  335,  309,  335,  317,  330,  335,  319,  321,  328,
 /*   110 */   329,  330,  331,  332,  333,  334,  318,  335,  322,  335,
 /*   120 */   324,  330,  335,  327,  323,  325,  335,  335,  312,  335,
 /*   130 */   335,  335,  335,  313,  335,  314,  329,  328,  335,  293,
 /*   140 */   294,  283,  282,  335,  260,  335,  335,  335,  335,  335,
 /*   150 */   335,  335,  335,  261,  335,  335,  335,  335,  265,  266,
 /*   160 */   335,  335,  335,  335,  335,  335,  268,  335,  335,  335,
 /*   170 */   335,  335,  335,  270,  335,  335,  272,  335,  335,  273,
 /*   180 */   335,  335,  274,  335,  335,  335,  335,  335,  335,  275,
 /*   190 */   335,  277,  335,  278,  335,  335,  267,  279,  240,  335,
 /*   200 */   335,  335,  335,  335,  276,  335,  335,  335,  335,  335,
 /*   210 */   271,  335,  335,  269,  335,  335,  335,  335,  335,  335,
 /*   220 */   262,  335,  335,  335,  335,  335,  335,  335,  335,  263,
 /*   230 */   335,  335,  335,  335,  335,  335,  264,
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
  "$",             "OPEN_DELIMITER",  "COMMA",         "IN",          
  "QUESTION",      "COLON",         "SBRACKET_OPEN",  "RANGE",       
  "AND",           "OR",            "IS",            "EQUALS",      
  "NOTEQUALS",     "LESS",          "GREATER",       "GREATEREQUAL",
  "LESSEQUAL",     "IDENTICAL",     "NOTIDENTICAL",  "DIVIDE",      
  "TIMES",         "MOD",           "PLUS",          "MINUS",       
  "CONCAT",        "PIPE",          "NOT",           "PARENTHESES_OPEN",
  "DOT",           "IF",            "CLOSE_DELIMITER",  "ENDIF",       
  "ELSE",          "ELSEIF",        "ELSEFOR",       "FOR",         
  "IDENTIFIER",    "ENDFOR",        "SET",           "ASSIGN",      
  "OPEN_EDELIMITER",  "CLOSE_EDELIMITER",  "BLOCK",         "ENDBLOCK",    
  "CACHE",         "ENDCACHE",      "INTEGER",       "EXTENDS",     
  "STRING",        "INCLUDE",       "DO",            "AUTOESCAPE",  
  "FALSE",         "ENDAUTOESCAPE",  "TRUE",          "BREAK",       
  "CONTINUE",      "RAW_FRAGMENT",  "DEFINED",       "PARENTHESES_CLOSE",
  "SBRACKET_CLOSE",  "DOUBLE",        "NULL",          "error",       
  "program",       "volt_language",  "statement_list",  "statement",   
  "raw_fragment",  "if_statement",  "elseif_statement",  "elsefor_statement",
  "for_statement",  "set_statement",  "echo_statement",  "block_statement",
  "cache_statement",  "extends_statement",  "include_statement",  "do_statement",
  "autoescape_statement",  "break_statement",  "continue_statement",  "empty_statement",
  "expr",          "array_list",    "slice_offset",  "array_item",  
  "function_call",  "argument_list",  "argument_item",
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
 /*   6 */ "statement ::= elseif_statement",
 /*   7 */ "statement ::= elsefor_statement",
 /*   8 */ "statement ::= for_statement",
 /*   9 */ "statement ::= set_statement",
 /*  10 */ "statement ::= echo_statement",
 /*  11 */ "statement ::= block_statement",
 /*  12 */ "statement ::= cache_statement",
 /*  13 */ "statement ::= extends_statement",
 /*  14 */ "statement ::= include_statement",
 /*  15 */ "statement ::= do_statement",
 /*  16 */ "statement ::= autoescape_statement",
 /*  17 */ "statement ::= break_statement",
 /*  18 */ "statement ::= continue_statement",
 /*  19 */ "statement ::= empty_statement",
 /*  20 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  21 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  22 */ "elseif_statement ::= OPEN_DELIMITER ELSEIF expr CLOSE_DELIMITER",
 /*  23 */ "elsefor_statement ::= OPEN_DELIMITER ELSEFOR CLOSE_DELIMITER",
 /*  24 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  25 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  26 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  27 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  28 */ "set_statement ::= OPEN_DELIMITER SET IDENTIFIER ASSIGN expr CLOSE_DELIMITER",
 /*  29 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  30 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  31 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  32 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  33 */ "cache_statement ::= OPEN_DELIMITER CACHE expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  34 */ "cache_statement ::= OPEN_DELIMITER CACHE expr INTEGER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  35 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  36 */ "include_statement ::= OPEN_DELIMITER INCLUDE STRING CLOSE_DELIMITER",
 /*  37 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  38 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE FALSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  39 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE TRUE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  40 */ "break_statement ::= OPEN_DELIMITER BREAK CLOSE_DELIMITER",
 /*  41 */ "continue_statement ::= OPEN_DELIMITER CONTINUE CLOSE_DELIMITER",
 /*  42 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  43 */ "expr ::= MINUS expr",
 /*  44 */ "expr ::= PLUS expr",
 /*  45 */ "expr ::= expr MINUS expr",
 /*  46 */ "expr ::= expr PLUS expr",
 /*  47 */ "expr ::= expr TIMES expr",
 /*  48 */ "expr ::= expr DIVIDE expr",
 /*  49 */ "expr ::= expr MOD expr",
 /*  50 */ "expr ::= expr AND expr",
 /*  51 */ "expr ::= expr OR expr",
 /*  52 */ "expr ::= expr CONCAT expr",
 /*  53 */ "expr ::= expr PIPE expr",
 /*  54 */ "expr ::= expr RANGE expr",
 /*  55 */ "expr ::= expr EQUALS expr",
 /*  56 */ "expr ::= expr IS NOT DEFINED",
 /*  57 */ "expr ::= expr IS DEFINED",
 /*  58 */ "expr ::= expr IS expr",
 /*  59 */ "expr ::= expr NOTEQUALS expr",
 /*  60 */ "expr ::= expr IDENTICAL expr",
 /*  61 */ "expr ::= expr NOTIDENTICAL expr",
 /*  62 */ "expr ::= expr LESS expr",
 /*  63 */ "expr ::= expr GREATER expr",
 /*  64 */ "expr ::= expr GREATEREQUAL expr",
 /*  65 */ "expr ::= expr LESSEQUAL expr",
 /*  66 */ "expr ::= expr DOT expr",
 /*  67 */ "expr ::= expr IN expr",
 /*  68 */ "expr ::= expr NOT IN expr",
 /*  69 */ "expr ::= NOT expr",
 /*  70 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /*  71 */ "expr ::= SBRACKET_OPEN SBRACKET_CLOSE",
 /*  72 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /*  73 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /*  74 */ "expr ::= expr QUESTION expr COLON expr",
 /*  75 */ "expr ::= expr SBRACKET_OPEN COLON slice_offset SBRACKET_CLOSE",
 /*  76 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON SBRACKET_CLOSE",
 /*  77 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON slice_offset SBRACKET_CLOSE",
 /*  78 */ "slice_offset ::= INTEGER",
 /*  79 */ "slice_offset ::= IDENTIFIER",
 /*  80 */ "array_list ::= array_list COMMA array_item",
 /*  81 */ "array_list ::= array_item",
 /*  82 */ "array_item ::= STRING COLON expr",
 /*  83 */ "array_item ::= expr",
 /*  84 */ "expr ::= function_call",
 /*  85 */ "function_call ::= expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /*  86 */ "function_call ::= expr PARENTHESES_OPEN PARENTHESES_CLOSE",
 /*  87 */ "argument_list ::= argument_list COMMA argument_item",
 /*  88 */ "argument_list ::= argument_item",
 /*  89 */ "argument_item ::= expr",
 /*  90 */ "argument_item ::= STRING COLON expr",
 /*  91 */ "expr ::= IDENTIFIER",
 /*  92 */ "expr ::= INTEGER",
 /*  93 */ "expr ::= STRING",
 /*  94 */ "expr ::= DOUBLE",
 /*  95 */ "expr ::= NULL",
 /*  96 */ "expr ::= FALSE",
 /*  97 */ "expr ::= TRUE",
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
// 539 "parser.lemon"
{
	if ((kkpminor->kk0)) {
		if ((kkpminor->kk0)->free_flag) {
			efree((kkpminor->kk0)->token);
		}
		efree((kkpminor->kk0));
	}
}
// 1280 "parser.c"
      break;
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
// 556 "parser.lemon"
{ zval_ptr_dtor(&(kkpminor->kk176)); }
// 1309 "parser.c"
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
  { 64, 1 },
  { 65, 1 },
  { 66, 2 },
  { 66, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 69, 8 },
  { 69, 12 },
  { 70, 4 },
  { 71, 3 },
  { 72, 10 },
  { 72, 12 },
  { 72, 12 },
  { 72, 14 },
  { 73, 6 },
  { 83, 2 },
  { 74, 3 },
  { 75, 8 },
  { 75, 7 },
  { 76, 8 },
  { 76, 9 },
  { 77, 4 },
  { 78, 4 },
  { 79, 4 },
  { 80, 8 },
  { 80, 8 },
  { 81, 3 },
  { 82, 3 },
  { 68, 1 },
  { 84, 2 },
  { 84, 2 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 4 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 3 },
  { 84, 4 },
  { 84, 2 },
  { 84, 3 },
  { 84, 2 },
  { 84, 3 },
  { 84, 4 },
  { 84, 5 },
  { 84, 5 },
  { 84, 5 },
  { 84, 6 },
  { 86, 1 },
  { 86, 1 },
  { 85, 3 },
  { 85, 1 },
  { 87, 3 },
  { 87, 1 },
  { 84, 1 },
  { 88, 4 },
  { 88, 3 },
  { 89, 3 },
  { 89, 1 },
  { 90, 1 },
  { 90, 3 },
  { 84, 1 },
  { 84, 1 },
  { 84, 1 },
  { 84, 1 },
  { 84, 1 },
  { 84, 1 },
  { 84, 1 },
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
// 548 "parser.lemon"
{
	status->ret = kkmsp[0].minor.kk176;
}
// 1624 "parser.c"
        break;
      case 1:
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
      case 84:
// 552 "parser.lemon"
{
	kkgotominor.kk176 = kkmsp[0].minor.kk176;
}
// 1648 "parser.c"
        break;
      case 2:
// 558 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_zval_list(kkmsp[-1].minor.kk176, kkmsp[0].minor.kk176);
}
// 1655 "parser.c"
        break;
      case 3:
      case 81:
      case 88:
// 562 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_zval_list(NULL, kkmsp[0].minor.kk176);
}
// 1664 "parser.c"
        break;
      case 20:
// 634 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_if_statement(kkmsp[-5].minor.kk176, kkmsp[-3].minor.kk176, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(29,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(31,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1677 "parser.c"
        break;
      case 21:
// 638 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_if_statement(kkmsp[-9].minor.kk176, kkmsp[-7].minor.kk176, kkmsp[-3].minor.kk176, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(29,&kkmsp[-10].minor);
  kk_destructor(30,&kkmsp[-8].minor);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(31,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1693 "parser.c"
        break;
      case 22:
// 644 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_elseif_statement(kkmsp[-1].minor.kk176, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(33,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1703 "parser.c"
        break;
      case 23:
// 650 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_elsefor_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(34,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1713 "parser.c"
        break;
      case 24:
// 656 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-5].minor.kk176, NULL, kkmsp[-3].minor.kk176, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(35,&kkmsp[-8].minor);
  kk_destructor(3,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1727 "parser.c"
        break;
      case 25:
// 660 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, NULL, kkmsp[-7].minor.kk176, kkmsp[-5].minor.kk176, kkmsp[-3].minor.kk176, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(35,&kkmsp[-10].minor);
  kk_destructor(3,&kkmsp[-8].minor);
  kk_destructor(29,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1742 "parser.c"
        break;
      case 26:
// 664 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, kkmsp[-9].minor.kk0, kkmsp[-5].minor.kk176, NULL, kkmsp[-3].minor.kk176, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(35,&kkmsp[-10].minor);
  kk_destructor(2,&kkmsp[-8].minor);
  kk_destructor(3,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1757 "parser.c"
        break;
      case 27:
// 668 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, kkmsp[-11].minor.kk0, kkmsp[-7].minor.kk176, kkmsp[-5].minor.kk176, kkmsp[-3].minor.kk176, status->scanner_state);
  kk_destructor(1,&kkmsp[-13].minor);
  kk_destructor(35,&kkmsp[-12].minor);
  kk_destructor(2,&kkmsp[-10].minor);
  kk_destructor(3,&kkmsp[-8].minor);
  kk_destructor(29,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1773 "parser.c"
        break;
      case 28:
// 674 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_set_statement(kkmsp[-3].minor.kk0, kkmsp[-1].minor.kk176, status->scanner_state);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(38,&kkmsp[-4].minor);
  kk_destructor(39,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1784 "parser.c"
        break;
      case 29:
// 680 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_empty_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1793 "parser.c"
        break;
      case 30:
// 686 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_echo_statement(kkmsp[-1].minor.kk176, status->scanner_state);
  kk_destructor(40,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[0].minor);
}
// 1802 "parser.c"
        break;
      case 31:
// 692 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_block_statement(kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk176, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(42,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(43,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1815 "parser.c"
        break;
      case 32:
// 696 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_block_statement(kkmsp[-4].minor.kk0, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(42,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(43,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1828 "parser.c"
        break;
      case 33:
// 702 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_cache_statement(kkmsp[-5].minor.kk176, NULL, kkmsp[-3].minor.kk176, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(44,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(45,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1841 "parser.c"
        break;
      case 34:
// 706 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_cache_statement(kkmsp[-6].minor.kk176, kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk176, status->scanner_state);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(44,&kkmsp[-7].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(45,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1854 "parser.c"
        break;
      case 35:
// 712 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_extends_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(47,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1864 "parser.c"
        break;
      case 36:
// 718 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_include_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(49,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1874 "parser.c"
        break;
      case 37:
// 724 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_do_statement(kkmsp[-1].minor.kk176, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(50,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1884 "parser.c"
        break;
      case 38:
// 730 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_autoescape_statement(0, kkmsp[-3].minor.kk176, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(51,&kkmsp[-6].minor);
  kk_destructor(52,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(53,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1898 "parser.c"
        break;
      case 39:
// 734 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_autoescape_statement(1, kkmsp[-3].minor.kk176, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(51,&kkmsp[-6].minor);
  kk_destructor(54,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(53,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1912 "parser.c"
        break;
      case 40:
// 740 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_break_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(55,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1922 "parser.c"
        break;
      case 41:
// 746 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_continue_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(56,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1932 "parser.c"
        break;
      case 42:
// 752 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, kkmsp[0].minor.kk0, status->scanner_state);
}
// 1939 "parser.c"
        break;
      case 43:
// 758 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
}
// 1947 "parser.c"
        break;
      case 44:
// 762 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_PLUS, NULL, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 1955 "parser.c"
        break;
      case 45:
// 766 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_SUB, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
}
// 1963 "parser.c"
        break;
      case 46:
// 770 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_ADD, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 1971 "parser.c"
        break;
      case 47:
// 774 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_MUL, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 1979 "parser.c"
        break;
      case 48:
// 778 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_DIV, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 1987 "parser.c"
        break;
      case 49:
// 782 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
// 1995 "parser.c"
        break;
      case 50:
// 786 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_AND, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(8,&kkmsp[-1].minor);
}
// 2003 "parser.c"
        break;
      case 51:
// 790 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_OR, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
}
// 2011 "parser.c"
        break;
      case 52:
// 794 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_CONCAT, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-1].minor);
}
// 2019 "parser.c"
        break;
      case 53:
// 798 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_PIPE, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(25,&kkmsp[-1].minor);
}
// 2027 "parser.c"
        break;
      case 54:
// 802 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_RANGE, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
}
// 2035 "parser.c"
        break;
      case 55:
// 806 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_EQUALS, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(11,&kkmsp[-1].minor);
}
// 2043 "parser.c"
        break;
      case 56:
// 810 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, kkmsp[-3].minor.kk176, NULL, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-2].minor);
  kk_destructor(26,&kkmsp[-1].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
// 2053 "parser.c"
        break;
      case 57:
// 814 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_ISSET, kkmsp[-2].minor.kk176, NULL, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
// 2062 "parser.c"
        break;
      case 58:
// 818 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_IS, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
}
// 2070 "parser.c"
        break;
      case 59:
// 822 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(12,&kkmsp[-1].minor);
}
// 2078 "parser.c"
        break;
      case 60:
// 826 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(17,&kkmsp[-1].minor);
}
// 2086 "parser.c"
        break;
      case 61:
// 830 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(18,&kkmsp[-1].minor);
}
// 2094 "parser.c"
        break;
      case 62:
// 834 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_LESS, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(13,&kkmsp[-1].minor);
}
// 2102 "parser.c"
        break;
      case 63:
// 838 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_GREATER, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(14,&kkmsp[-1].minor);
}
// 2110 "parser.c"
        break;
      case 64:
// 842 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(15,&kkmsp[-1].minor);
}
// 2118 "parser.c"
        break;
      case 65:
// 846 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(16,&kkmsp[-1].minor);
}
// 2126 "parser.c"
        break;
      case 66:
// 850 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_DOT, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(28,&kkmsp[-1].minor);
}
// 2134 "parser.c"
        break;
      case 67:
// 854 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_IN, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(3,&kkmsp[-1].minor);
}
// 2142 "parser.c"
        break;
      case 68:
// 858 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_NOT_IN, kkmsp[-3].minor.kk176, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(3,&kkmsp[-1].minor);
}
// 2151 "parser.c"
        break;
      case 69:
// 862 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, kkmsp[0].minor.kk176, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-1].minor);
}
// 2159 "parser.c"
        break;
      case 70:
// 866 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, kkmsp[-1].minor.kk176, NULL, NULL, status->scanner_state);
  kk_destructor(27,&kkmsp[-2].minor);
  kk_destructor(59,&kkmsp[0].minor);
}
// 2168 "parser.c"
        break;
      case 71:
// 870 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-1].minor);
  kk_destructor(60,&kkmsp[0].minor);
}
// 2177 "parser.c"
        break;
      case 72:
// 874 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk176, NULL, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-2].minor);
  kk_destructor(60,&kkmsp[0].minor);
}
// 2186 "parser.c"
        break;
      case 73:
// 878 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, kkmsp[-3].minor.kk176, kkmsp[-1].minor.kk176, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-2].minor);
  kk_destructor(60,&kkmsp[0].minor);
}
// 2195 "parser.c"
        break;
      case 74:
// 882 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_expr(PHVOLT_T_TERNARY, kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176, kkmsp[-4].minor.kk176, status->scanner_state);
  kk_destructor(4,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 2204 "parser.c"
        break;
      case 75:
// 886 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_slice(kkmsp[-4].minor.kk176, NULL, kkmsp[-1].minor.kk176, status->scanner_state);
  kk_destructor(6,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-2].minor);
  kk_destructor(60,&kkmsp[0].minor);
}
// 2214 "parser.c"
        break;
      case 76:
// 890 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_slice(kkmsp[-4].minor.kk176, kkmsp[-2].minor.kk176, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-1].minor);
  kk_destructor(60,&kkmsp[0].minor);
}
// 2224 "parser.c"
        break;
      case 77:
// 894 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_slice(kkmsp[-5].minor.kk176, kkmsp[-3].minor.kk176, kkmsp[-1].minor.kk176, status->scanner_state);
  kk_destructor(6,&kkmsp[-4].minor);
  kk_destructor(5,&kkmsp[-2].minor);
  kk_destructor(60,&kkmsp[0].minor);
}
// 2234 "parser.c"
        break;
      case 78:
      case 92:
// 900 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2242 "parser.c"
        break;
      case 79:
      case 91:
// 904 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2250 "parser.c"
        break;
      case 80:
      case 87:
// 910 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_zval_list(kkmsp[-2].minor.kk176, kkmsp[0].minor.kk176);
  kk_destructor(2,&kkmsp[-1].minor);
}
// 2259 "parser.c"
        break;
      case 82:
      case 90:
// 920 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_named_item(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk176, status->scanner_state);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 2268 "parser.c"
        break;
      case 83:
      case 89:
// 924 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_named_item(NULL, kkmsp[0].minor.kk176, status->scanner_state);
}
// 2276 "parser.c"
        break;
      case 85:
// 934 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_func_call(kkmsp[-3].minor.kk176, kkmsp[-1].minor.kk176, status->scanner_state);
  kk_destructor(27,&kkmsp[-2].minor);
  kk_destructor(59,&kkmsp[0].minor);
}
// 2285 "parser.c"
        break;
      case 86:
// 938 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_func_call(kkmsp[-2].minor.kk176, NULL, status->scanner_state);
  kk_destructor(27,&kkmsp[-1].minor);
  kk_destructor(59,&kkmsp[0].minor);
}
// 2294 "parser.c"
        break;
      case 93:
// 970 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_literal_zval(PHVOLT_T_STRING, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2301 "parser.c"
        break;
      case 94:
// 974 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2308 "parser.c"
        break;
      case 95:
// 978 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  kk_destructor(62,&kkmsp[0].minor);
}
// 2316 "parser.c"
        break;
      case 96:
// 982 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  kk_destructor(52,&kkmsp[0].minor);
}
// 2324 "parser.c"
        break;
      case 97:
// 986 "parser.lemon"
{
	kkgotominor.kk176 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  kk_destructor(54,&kkmsp[0].minor);
}
// 2332 "parser.c"
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
#define KTOKEN (kkminor.kk0)
// 493 "parser.lemon"

	if (status->scanner_state->start_length) {
		{

			char *token_name = NULL;
			const phvolt_token_names *tokens = phvolt_tokens;
			int token_found = 0;
			int active_token = status->scanner_state->active_token;

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

			status->syntax_error_len = 64 + strlen(token_name) + Z_STRLEN_P(status->scanner_state->active_file);
			status->syntax_error = emalloc(sizeof(char) * status->syntax_error_len);
			sprintf(status->syntax_error, "Syntax error, unexpected token %s in %s on line %d", token_name, Z_STRVAL_P(status->scanner_state->active_file), status->scanner_state->active_line);

			if (!token_found) {
				if (token_name) {
					efree(token_name);
				}
			}
		}
	} else {
		status->syntax_error_len = 48 + Z_STRLEN_P(status->scanner_state->active_file);
		status->syntax_error = emalloc(sizeof(char) * status->syntax_error_len);
		sprintf(status->syntax_error, "Syntax error, unexpected EOF in %s", Z_STRVAL_P(status->scanner_state->active_file));
	}

	status->status = PHVOLT_PARSING_FAILED;

// 2420 "parser.c"
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
  phvolt_KTOKENTYPE kkminor       /* The value for the token */
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
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
  { PHVOLT_T_NOT,           	"!" },
  { PHVOLT_T_CONCAT,           	"~" },
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
  { PHVOLT_T_COLON,       		"COLON" },
  { PHVOLT_T_QUESTION,       	"QUESTION MARK" },
  { PHVOLT_T_LESS,          	"<" },
  { PHVOLT_T_LESSEQUAL,     	"<=" },
  { PHVOLT_T_GREATER,       	">" },
  { PHVOLT_T_GREATEREQUAL,  	">=" },
  { PHVOLT_T_PARENTHESES_OPEN,  "(" },
  { PHVOLT_T_PARENTHESES_CLOSE, ")" },
  { PHVOLT_T_SBRACKET_OPEN,  	"[" },
  { PHVOLT_T_SBRACKET_CLOSE, 	"]" },
  { PHVOLT_T_OPEN_DELIMITER, 	"{%" },
  { PHVOLT_T_CLOSE_DELIMITER, 	"%}" },
  { PHVOLT_T_OPEN_EDELIMITER, 	"{{" },
  { PHVOLT_T_CLOSE_EDELIMITER, 	"}}" },
  { PHVOLT_T_IF,           		"IF" },
  { PHVOLT_T_ELSE,           	"ELSE" },
  { PHVOLT_T_ELSEIF,           	"ELSEIF" },
  { PHVOLT_T_ENDIF,           	"ENDIF" },
  { PHVOLT_T_FOR,           	"FOR" },
  { PHVOLT_T_IN, 	          	"IN" },
  { PHVOLT_T_ENDFOR,           	"ENDFOR" },
  { PHVOLT_T_SET,           	"SET" },
  { PHVOLT_T_ASSIGN,           	"ASSIGN" },
  { PHVOLT_T_BLOCK,           	"BLOCK" },
  { PHVOLT_T_ENDBLOCK,          "ENDBLOCK" },
  { PHVOLT_T_CACHE,           	"CACHE" },
  { PHVOLT_T_ENDCACHE,        	"ENDCACHE" },
  { PHVOLT_T_EXTENDS,			"EXTENDS" },
  { PHVOLT_T_IS,				"IS" },
  { PHVOLT_T_DEFINED,			"DEFINED" },
  { PHVOLT_T_INCLUDE,			"INCLUDE" },
  { PHVOLT_T_DO,				"DO" },
  { PHVOLT_T_IGNORE,			"WHITESPACE" },
  { PHVOLT_T_AUTOESCAPE,		"AUTOESCAPE" },
  { PHVOLT_T_ENDAUTOESCAPE,		"ENDAUTOESCAPE" },
  { PHVOLT_T_CONTINUE,			"CONTINUE" },
  { PHVOLT_T_BREAK,				"BREAK" },
  {  0, NULL }
};

/**
 * Wrapper to alloc memory within the parser
 */
static void *phvolt_wrapper_alloc(size_t bytes){
	return emalloc(bytes);
}

/**
 * Wrapper to free memory within the parser
 */
static void phvolt_wrapper_free(void *pointer){
	efree(pointer);
}

/**
 * Creates a parser_token to be passed to the parser
 */
static void phvolt_parse_with_token(void* phvolt_parser, int opcode, int parsercode, phvolt_scanner_token *token, phvolt_parser_status *parser_status){

	phvolt_parser_token *pToken;

	pToken = emalloc(sizeof(phvolt_parser_token));
	pToken->opcode = opcode;
	pToken->token = token->value;
	pToken->token_len = token->len;
	pToken->free_flag = 1;

	phvolt_(phvolt_parser, parsercode, pToken, parser_status);
}

/**
 * Creates an error message
 */
static void phvolt_create_error_msg(phvolt_parser_status *parser_status, char *message){

	unsigned int length = (128 + Z_STRLEN_P(parser_status->scanner_state->active_file));
	char *str = emalloc(sizeof(char) * length);

	snprintf(str, length, "%s in %s on line %d", message, Z_STRVAL_P(parser_status->scanner_state->active_file), parser_status->scanner_state->active_line);
	str[length - 1] = '\0';

	parser_status->syntax_error = estrndup(str, strlen(str));
	efree(str);
}

/**
 * Creates an error message when it's triggered by the scanner
 */
static void phvolt_scanner_error_msg(phvolt_parser_status *parser_status, zval **error_msg TSRMLS_DC){

	char *error, *error_part;
	phvolt_scanner_state *state = parser_status->scanner_state;

	PHALCON_INIT_VAR(*error_msg);
	if (state->start) {
		error = emalloc(sizeof(char) * 64 + state->start_length +  Z_STRLEN_P(state->active_file));
		if (state->start_length > 16) {
			error_part = estrndup(state->start, 16);
			sprintf(error, "Parsing error before '%s...' in %s on line %d", error_part, Z_STRVAL_P(state->active_file), state->active_line);
			efree(error_part);
		} else {
			sprintf(error, "Parsing error before '%s' in %s on line %d", state->start, Z_STRVAL_P(state->active_file), state->active_line);
		}
		ZVAL_STRING(*error_msg, error, 1);
	} else {
		error = emalloc(sizeof(char) * (32 + Z_STRLEN_P(state->active_file)));
		sprintf(error, "Parsing error near to EOF in %s", Z_STRVAL_P(state->active_file));
		ZVAL_STRING(*error_msg, error, 1);
	}
	efree(error);
}

/**
 * Receives the volt code tokenizes and parses it
 */
int phvolt_parse_view(zval *result, zval *view_code, zval *template_path TSRMLS_DC){

	zval *error_msg = NULL;

	ZVAL_NULL(result);

	if (Z_TYPE_P(view_code) != IS_STRING) {
		phalcon_throw_exception_string(phalcon_mvc_view_exception_ce, SL("View code must be a string") TSRMLS_CC);
		return FAILURE;
	}

	if(phvolt_internal_parse_view(&result, view_code, template_path, &error_msg TSRMLS_CC) == FAILURE){
		phalcon_throw_exception_string(phalcon_mvc_view_exception_ce, Z_STRVAL_P(error_msg), Z_STRLEN_P(error_msg) TSRMLS_CC);
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Checks whether the token has only blank characters
 */
int phvolt_is_blank_string(phvolt_scanner_token *token){

	char *marker = token->value;
	unsigned int ch, i;

	for (i = 0; i < token->len; i++) {
		ch = *marker;
		if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' && ch != 11) {
			return 0;
		}
		marker++;
	}

	return 1;
}

/**
 * Parses a volt template returning an intermediate array representation
 */
int phvolt_internal_parse_view(zval **result, zval *view_code, zval *template_path, zval **error_msg TSRMLS_DC) {

	char *error;
	phvolt_scanner_state *state;
	phvolt_scanner_token token;
	int scanner_status, status = SUCCESS;
	phvolt_parser_status *parser_status = NULL;
	void* phvolt_parser;

	/** Check if the view has code */
	if (!Z_STRVAL_P(view_code)) {
		PHALCON_INIT_VAR(*error_msg);
		ZVAL_STRING(*error_msg, "View code cannot be null", 1);
		return FAILURE;
	}

	if (!Z_STRLEN_P(view_code)) {
		array_init(*result);
		return SUCCESS;
	}

	/** Start the reentrant parser */
	phvolt_parser = phvolt_Alloc(phvolt_wrapper_alloc);

	parser_status = emalloc(sizeof(phvolt_parser_status));
	state = emalloc(sizeof(phvolt_scanner_state));

	parser_status->status = PHVOLT_PARSING_OK;
	parser_status->scanner_state = state;
	parser_status->ret = NULL;
	parser_status->syntax_error = NULL;

	/** Initialize the scanner state */
	state->active_token = 0;
	state->start = Z_STRVAL_P(view_code);
	state->mode = PHVOLT_MODE_RAW;
	state->raw_buffer = emalloc(sizeof(char) * PHVOLT_RAW_BUFFER_SIZE);
	state->raw_buffer_size = PHVOLT_RAW_BUFFER_SIZE;
	state->raw_buffer_cursor = 0;
	state->active_file = template_path;
	state->active_line = 1;
	state->statement_position = 0;
	state->extends_mode = 0;
	state->block_level = 0;
	state->start_length = 0;
	state->if_level = 0;
	state->for_level = 0;
	state->whitespace_control = 0;

	state->end = state->start;

	while(0 <= (scanner_status = phvolt_get_token(state, &token))) {

		state->active_token = token.opcode;

		state->start_length = (Z_STRVAL_P(view_code) + Z_STRLEN_P(view_code) - state->start);

		switch(token.opcode){

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
			case PHVOLT_T_IS:
				phvolt_(phvolt_parser, PHVOLT_IS, NULL, parser_status);
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
			case PHVOLT_T_COLON:
				phvolt_(phvolt_parser, PHVOLT_COLON, NULL, parser_status);
				break;
			case PHVOLT_T_QUESTION:
				phvolt_(phvolt_parser, PHVOLT_QUESTION, NULL, parser_status);
				break;

			case PHVOLT_T_PARENTHESES_OPEN:
				phvolt_(phvolt_parser, PHVOLT_PARENTHESES_OPEN, NULL, parser_status);
				break;
			case PHVOLT_T_PARENTHESES_CLOSE:
				phvolt_(phvolt_parser, PHVOLT_PARENTHESES_CLOSE, NULL, parser_status);
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
				if (state->extends_mode == 1 && state->block_level == 0) {
					phvolt_create_error_msg(parser_status, "Child templates only may contain blocks");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				}
				phvolt_(phvolt_parser, PHVOLT_OPEN_EDELIMITER, NULL, parser_status);
				break;
			case PHVOLT_T_CLOSE_EDELIMITER:
				phvolt_(phvolt_parser, PHVOLT_CLOSE_EDELIMITER, NULL, parser_status);
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
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_INTEGER, PHVOLT_INTEGER, &token, parser_status);
				break;
			case PHVOLT_T_DOUBLE:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_DOUBLE, PHVOLT_DOUBLE, &token, parser_status);
				break;
			case PHVOLT_T_STRING:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_STRING, PHVOLT_STRING, &token, parser_status);
				break;
			case PHVOLT_T_IDENTIFIER:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_IDENTIFIER, PHVOLT_IDENTIFIER, &token, parser_status);
				break;

			case PHVOLT_T_IF:
				if (state->extends_mode == 1 && state->block_level == 0){
					phvolt_create_error_msg(parser_status, "Child templates only may contain blocks");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				} else {
					state->if_level++;
					state->block_level++;
				}
				phvolt_(phvolt_parser, PHVOLT_IF, NULL, parser_status);
				break;
			case PHVOLT_T_ELSE:
				if (state->if_level == 0 && state->for_level > 0) {
					phvolt_(phvolt_parser, PHVOLT_ELSEFOR, NULL, parser_status);
				} else {
					phvolt_(phvolt_parser, PHVOLT_ELSE, NULL, parser_status);
				}
				break;
			case PHVOLT_T_ELSEIF:
				if (state->if_level == 0) {
					phvolt_create_error_msg(parser_status, "Unexpected ENDIF");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				}
				phvolt_(phvolt_parser, PHVOLT_ELSEIF, NULL, parser_status);
				break;
			case PHVOLT_T_ENDIF:
				state->block_level--;
				state->if_level--;
				phvolt_(phvolt_parser, PHVOLT_ENDIF, NULL, parser_status);
				break;

			case PHVOLT_T_FOR:
				if (state->extends_mode == 1 && state->block_level == 0){
					phvolt_create_error_msg(parser_status, "Child templates only may contain blocks");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				} else {
					state->for_level++;
					state->block_level++;
				}
				phvolt_(phvolt_parser, PHVOLT_FOR, NULL, parser_status);
				break;
			case PHVOLT_T_IN:
				phvolt_(phvolt_parser, PHVOLT_IN, NULL, parser_status);
				break;
			case PHVOLT_T_ENDFOR:
				state->block_level--;
				state->for_level--;
				phvolt_(phvolt_parser, PHVOLT_ENDFOR, NULL, parser_status);
				break;

			case PHVOLT_T_RAW_FRAGMENT:
				if (token.len > 0) {
					if (state->extends_mode == 1 && state->block_level == 0){
						if(!phvolt_is_blank_string(&token)){
							phvolt_create_error_msg(parser_status, "Child templates only may contain blocks");
							parser_status->status = PHVOLT_PARSING_FAILED;
						}
						efree(token.value);
						break;
					} else {
						if (!phvolt_is_blank_string(&token)) {
							state->statement_position++;
						}
					}
					phvolt_parse_with_token(phvolt_parser, PHVOLT_T_RAW_FRAGMENT, PHVOLT_RAW_FRAGMENT, &token, parser_status);
				} else {
					efree(token.value);
				}
				break;

			case PHVOLT_T_SET:
				if (state->extends_mode == 1 && state->block_level == 0){
					phvolt_create_error_msg(parser_status, "Child templates only may contain blocks");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				}
				phvolt_(phvolt_parser, PHVOLT_SET, NULL, parser_status);
				break;
			case PHVOLT_T_ASSIGN:
				phvolt_(phvolt_parser, PHVOLT_ASSIGN, NULL, parser_status);
				break;

			case PHVOLT_T_BLOCK:
				if (state->block_level > 0) {
					phvolt_create_error_msg(parser_status, "Embedding blocks into other blocks is not supported");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				} else {
					state->block_level++;
				}
				phvolt_(phvolt_parser, PHVOLT_BLOCK, NULL, parser_status);
				break;
			case PHVOLT_T_ENDBLOCK:
				state->block_level--;
				phvolt_(phvolt_parser, PHVOLT_ENDBLOCK, NULL, parser_status);
				break;

			case PHVOLT_T_CACHE:
				phvolt_(phvolt_parser, PHVOLT_CACHE, NULL, parser_status);
				break;
			case PHVOLT_T_ENDCACHE:
				phvolt_(phvolt_parser, PHVOLT_ENDCACHE, NULL, parser_status);
				break;

			case PHVOLT_T_INCLUDE:
				phvolt_(phvolt_parser, PHVOLT_INCLUDE, NULL, parser_status);
				break;

			case PHVOLT_T_DEFINED:
				phvolt_(phvolt_parser, PHVOLT_DEFINED, NULL, parser_status);
				break;

			case PHVOLT_T_DO:
				phvolt_(phvolt_parser, PHVOLT_DO, NULL, parser_status);
				break;

			case PHVOLT_T_AUTOESCAPE:
				phvolt_(phvolt_parser, PHVOLT_AUTOESCAPE, NULL, parser_status);
				break;

			case PHVOLT_T_ENDAUTOESCAPE:
				phvolt_(phvolt_parser, PHVOLT_ENDAUTOESCAPE, NULL, parser_status);
				break;

			case PHVOLT_T_BREAK:
				phvolt_(phvolt_parser, PHVOLT_BREAK, NULL, parser_status);
				break;

			case PHVOLT_T_CONTINUE:
				phvolt_(phvolt_parser, PHVOLT_CONTINUE, NULL, parser_status);
				break;

			case PHVOLT_T_EXTENDS:
				if (state->statement_position != 1) {
					phvolt_create_error_msg(parser_status, "Extends statement must be placed at the first line in the template");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				} else {
					state->extends_mode = 1;
				}
				phvolt_(phvolt_parser, PHVOLT_EXTENDS, NULL, parser_status);
				break;

			default:
				parser_status->status = PHVOLT_PARSING_FAILED;
				if (!*error_msg) {
					error = emalloc(sizeof(char) * (48 + Z_STRLEN_P(state->active_file)));
					sprintf(error, "Scanner: unknown opcode %d on in %s line %d", token.opcode, Z_STRVAL_P(state->active_file), state->active_line);
					PHALCON_INIT_VAR(*error_msg);
					ZVAL_STRING(*error_msg, error, 1);
					efree(error);
				}
				break;
		}

		if (parser_status->status != PHVOLT_PARSING_OK) {
			status = FAILURE;
			break;
		}

		state->end = state->start;
	}

	if (status != FAILURE) {
		switch (scanner_status) {
			case PHVOLT_SCANNER_RETCODE_ERR:
			case PHVOLT_SCANNER_RETCODE_IMPOSSIBLE:
				if (!*error_msg) {
					phvolt_scanner_error_msg(parser_status, error_msg TSRMLS_CC);
				}
				status = FAILURE;
				break;
			default:
				phvolt_(phvolt_parser, 0, NULL, parser_status);
		}
	}

	state->active_token = 0;
	state->start = NULL;
	efree(state->raw_buffer);

	if (parser_status->status != PHVOLT_PARSING_OK) {
		status = FAILURE;
		if (parser_status->syntax_error) {
			if (!*error_msg) {
				PHALCON_INIT_VAR(*error_msg);
				ZVAL_STRING(*error_msg, parser_status->syntax_error, 1);
			}
			efree(parser_status->syntax_error);
		}
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

	return status;
}