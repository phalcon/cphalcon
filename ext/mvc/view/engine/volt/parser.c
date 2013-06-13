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

	if (true_statements) {
		add_assoc_zval(ret, "true_statements", true_statements);
	}
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

static zval *phvolt_ret_set_statement(zval *assignments)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, "type", PHVOLT_T_SET);

	add_assoc_zval(ret, "assignments", assignments);

	return ret;
}

static zval *phvolt_ret_set_assignment(phvolt_parser_token *variable, zval *expr, phvolt_scanner_state *state)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

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

static zval *phvolt_ret_macro_statement(phvolt_parser_token *macro_name, zval *parameters, zval *block_statements, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_MACRO);

	add_assoc_stringl(ret, "name", macro_name->token, macro_name->token_len, 0);
	efree(macro_name);

	if (parameters) {
		add_assoc_zval(ret, "parameters", parameters);
	}

	if (block_statements) {
		add_assoc_zval(ret, "block_statements", block_statements);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_macro_parameter(phvolt_parser_token *variable, zval *default_value, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 5);

	add_assoc_stringl(ret, "variable", variable->token, variable->token_len, 0);
	efree(variable);

	if (default_value) {
		add_assoc_zval(ret, "default", default_value);
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

static zval *phvolt_ret_include_statement(zval *path, zval *params, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	add_assoc_long(ret, "type", PHVOLT_T_INCLUDE);

	add_assoc_zval(ret, "path", path);
	if (params) {
		add_assoc_zval(ret, "params", params);
	}

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

static zval *phvolt_ret_macro_call_statement(zval *expr, zval *arguments, zval *caller, phvolt_scanner_state *state)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_CALL);
	add_assoc_zval(ret, "name", expr);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	if (caller) {
		add_assoc_zval(ret, "caller", caller);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}


// 549 "parser.c"
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
#define KKNOCODE 106
#define KKACTIONTYPE unsigned short int
#define phvolt_KTOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_KTOKENTYPE kk0;
  zval* kk78;
  int kk211;
} KKMINORTYPE;
#define KKSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = kkpParser->status
#define phvolt_ARG_STORE kkpParser->status = status
#define KKNSTATE 308
#define KKNRULE 125
#define KKERRORSYMBOL 70
#define KKERRSYMDT kk211
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
 /*     0 */    81,   89,  105,   86,   59,   51,   53,   63,   61,   65,
 /*    10 */    71,   73,   75,   77,   67,   69,   47,   45,   49,   42,
 /*    20 */    39,   55,   57,   83,   93,   79,  274,  159,   81,   89,
 /*    30 */   308,   86,   59,   51,   53,   63,   61,   65,   71,   73,
 /*    40 */    75,   77,   67,   69,   47,   45,   49,   42,   39,   55,
 /*    50 */    57,   83,   93,   79,   29,  202,   47,   45,   49,   42,
 /*    60 */    39,   55,   57,   83,   93,   79,   31,  104,  241,   83,
 /*    70 */    93,   79,   81,   89,  167,   86,   59,   51,   53,   63,
 /*    80 */    61,   65,   71,   73,   75,   77,   67,   69,   47,   45,
 /*    90 */    49,   42,   39,   55,   57,   83,   93,   79,   35,  212,
 /*   100 */    81,   89,  166,   86,   59,   51,   53,   63,   61,   65,
 /*   110 */    71,   73,   75,   77,   67,   69,   47,   45,   49,   42,
 /*   120 */    39,   55,   57,   83,   93,   79,  290,  285,  213,   81,
 /*   130 */    89,   84,   86,   59,   51,   53,   63,   61,   65,   71,
 /*   140 */    73,   75,   77,   67,   69,   47,   45,   49,   42,   39,
 /*   150 */    55,   57,   83,   93,   79,  112,   25,   81,   89,  133,
 /*   160 */    86,   59,   51,   53,   63,   61,   65,   71,   73,   75,
 /*   170 */    77,   67,   69,   47,   45,   49,   42,   39,   55,   57,
 /*   180 */    83,   93,   79,  105,   38,   81,   89,  134,   86,   59,
 /*   190 */    51,   53,   63,   61,   65,   71,   73,   75,   77,   67,
 /*   200 */    69,   47,   45,   49,   42,   39,   55,   57,   83,   93,
 /*   210 */    79,   81,   89,   91,   86,   59,   51,   53,   63,   61,
 /*   220 */    65,   71,   73,   75,   77,   67,   69,   47,   45,   49,
 /*   230 */    42,   39,   55,   57,   83,   93,   79,   42,   39,   55,
 /*   240 */    57,   83,   93,   79,   57,   83,   93,   79,  125,   88,
 /*   250 */   109,  165,  172,   81,   89,  413,   86,   59,   51,   53,
 /*   260 */    63,   61,   65,   71,   73,   75,   77,   67,   69,   47,
 /*   270 */    45,   49,   42,   39,   55,   57,   83,   93,   79,  267,
 /*   280 */   268,  269,  270,  271,  272,  136,  125,  124,  281,  157,
 /*   290 */   136,   99,  135,  255,  273,   81,   89,  135,   86,   59,
 /*   300 */    51,   53,   63,   61,   65,   71,   73,   75,   77,   67,
 /*   310 */    69,   47,   45,   49,   42,   39,   55,   57,   83,   93,
 /*   320 */    79,  139,  215,   81,   89,  186,   86,   59,   51,   53,
 /*   330 */    63,   61,   65,   71,   73,   75,   77,   67,   69,   47,
 /*   340 */    45,   49,   42,   39,   55,   57,   83,   93,   79,  128,
 /*   350 */   218,   81,   89,  140,   86,   59,   51,   53,   63,   61,
 /*   360 */    65,   71,   73,   75,   77,   67,   69,   47,   45,   49,
 /*   370 */    42,   39,   55,   57,   83,   93,   79,   86,   59,   51,
 /*   380 */    53,   63,   61,   65,   71,   73,   75,   77,   67,   69,
 /*   390 */    47,   45,   49,   42,   39,   55,   57,   83,   93,   79,
 /*   400 */   232,  264,  220,  235,   81,   89,  176,   86,   59,   51,
 /*   410 */    53,   63,   61,   65,   71,   73,   75,   77,   67,   69,
 /*   420 */    47,   45,   49,   42,   39,   55,   57,   83,   93,   79,
 /*   430 */   414,  276,   81,   89,  141,   86,   59,   51,   53,   63,
 /*   440 */    61,   65,   71,   73,   75,   77,   67,   69,   47,   45,
 /*   450 */    49,   42,   39,   55,   57,   83,   93,   79,  138,  292,
 /*   460 */    81,   89,  154,   86,   59,   51,   53,   63,   61,   65,
 /*   470 */    71,   73,   75,   77,   67,   69,   47,   45,   49,   42,
 /*   480 */    39,   55,   57,   83,   93,   79,   81,   89,  156,   86,
 /*   490 */    59,   51,   53,   63,   61,   65,   71,   73,   75,   77,
 /*   500 */    67,   69,   47,   45,   49,   42,   39,   55,   57,   83,
 /*   510 */   184,   79,   89,  169,   86,   59,   51,   53,   63,   61,
 /*   520 */    65,   71,   73,   75,   77,   67,   69,   47,   45,   49,
 /*   530 */    42,   39,   55,   57,   83,   93,   79,  434,    1,    2,
 /*   540 */   234,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   550 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   51,
 /*   560 */    53,   63,   61,   65,   71,   73,   75,   77,   67,   69,
 /*   570 */    47,   45,   49,   42,   39,   55,   57,   83,   93,   79,
 /*   580 */    26,  234,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   590 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   600 */    32,  234,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   610 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   620 */   160,  234,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   630 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   640 */   178,  234,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   650 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   660 */   188,  234,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   670 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   680 */   196,  234,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   690 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   700 */   203,  234,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   710 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   720 */   222,  234,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   730 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   740 */   237,  234,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   750 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   760 */   243,  234,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   770 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   780 */   258,  234,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   790 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   800 */   277,  234,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   810 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   820 */   286,  234,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   830 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   840 */   293,  234,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   850 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   860 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   870 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   63,
 /*   880 */    61,   65,   71,   73,   75,   77,   67,   69,   47,   45,
 /*   890 */    49,   42,   39,   55,   57,   83,   93,   79,   22,   23,
 /*   900 */   192,   28,   30,   36,  153,  155,   94,  413,  164,  414,
 /*   910 */   173,  101,  123,  163,   87,  262,  114,  131,  103,  182,
 /*   920 */   110,  114,  137,  193,  114,  200,  168,  207,  210,  300,
 /*   930 */   216,  219,  174,  226,  228,   23,  192,  301,  303,   36,
 /*   940 */   153,  155,  101,  175,  164,  177,  173,   94,  230,  108,
 /*   950 */   170,  110,  114,  185,  256,  182,  194,  114,  131,  193,
 /*   960 */    27,  200,  233,  207,  210,  181,  216,  219,  187,  226,
 /*   970 */   228,   23,  192,   34,  101,   36,  153,  155,   94,  230,
 /*   980 */   164,  191,  173,  122,  114,  195,   24,  199,  114,  126,
 /*   990 */   206,  182,  208,  233,   37,  193,  114,  200,  209,  207,
 /*  1000 */   210,  297,  216,  219,  114,  226,  228,   23,  192,   33,
 /*  1010 */   230,   36,  153,  155,  221,  162,  164,  225,  173,  152,
 /*  1020 */   227,  229,   41,  236,  233,  240,  242,  182,  246,  114,
 /*  1030 */   151,  193,  114,  200,  249,  207,  210,  161,  216,  219,
 /*  1040 */   114,  226,  228,   23,  192,  179,  251,   36,  153,  155,
 /*  1050 */   252,  230,  164,  254,  173,  253,  180,  257,   44,  230,
 /*  1060 */    46,  261,  264,  182,  266,  233,   48,  193,  114,  200,
 /*  1070 */   114,  207,  210,  233,  216,  219,  114,  226,  228,   23,
 /*  1080 */   192,  189,   50,   36,  153,  155,  265,  230,  164,  263,
 /*  1090 */   173,  282,  114,  280,   52,  230,   54,  283,  289,  182,
 /*  1100 */   190,  233,   56,  193,  114,  200,  114,  207,  210,  233,
 /*  1110 */   216,  219,  114,  226,  228,   23,  192,  247,   58,   36,
 /*  1120 */   153,  155,  296,   60,  164,  299,  173,   62,  114,  302,
 /*  1130 */   304,  230,   64,  114,  306,  182,  232,  114,   66,  193,
 /*  1140 */   198,  200,  114,  207,  210,  233,  216,  219,  114,  226,
 /*  1150 */   228,   23,  192,  197,   68,   36,  153,  155,  305,   70,
 /*  1160 */   164,  307,  173,   72,  114,  232,   74,  230,  232,  114,
 /*  1170 */   232,  182,  232,  114,   76,  193,  114,  200,  205,  207,
 /*  1180 */   210,  233,  216,  219,  114,  226,  228,   23,  192,  204,
 /*  1190 */    78,   36,  153,  155,   80,   82,  164,  232,  173,   85,
 /*  1200 */   114,  232,   90,  230,  114,  114,  232,  182,  232,  114,
 /*  1210 */   232,  193,  114,  200,  232,  207,  210,  233,  216,  219,
 /*  1220 */   224,  226,  228,   23,  192,  223,   92,   36,  153,  155,
 /*  1230 */   232,   96,  164,  232,  173,   98,  114,  232,  113,  230,
 /*  1240 */   129,  114,  232,  182,  232,  114,  232,  193,  114,  200,
 /*  1250 */   114,  207,  210,  233,  216,  219,  239,  226,  228,   23,
 /*  1260 */   192,  238,  232,   36,  153,  155,  232,  148,  164,  232,
 /*  1270 */   173,  150,  158,  232,  171,  230,  232,  114,  232,  182,
 /*  1280 */   232,  114,  114,  193,  114,  200,  245,  207,  210,  233,
 /*  1290 */   216,  219,  183,  226,  228,   23,  192,  244,  201,   36,
 /*  1300 */   153,  155,  114,  211,  164,  232,  173,  214,  114,  232,
 /*  1310 */   232,  230,  217,  114,  232,  182,  232,  114,  231,  193,
 /*  1320 */   248,  200,  114,  207,  210,  233,  216,  219,  114,  226,
 /*  1330 */   228,   23,  192,  259,  232,   36,  153,  155,  232,  275,
 /*  1340 */   164,  232,  173,  284,  260,  232,  291,  230,  232,  114,
 /*  1350 */   232,  182,  232,  114,  232,  193,  114,  200,  232,  207,
 /*  1360 */   210,  233,  216,  219,  232,  226,  228,   23,  192,  278,
 /*  1370 */   232,   36,  153,  155,  232,  279,  164,  232,  173,  232,
 /*  1380 */   232,  232,  232,  230,  232,  232,  232,  182,  232,  232,
 /*  1390 */   232,  193,  232,  200,  232,  207,  210,  233,  216,  219,
 /*  1400 */   232,  226,  228,   23,  192,  287,  232,   36,  153,  155,
 /*  1410 */   232,  288,  164,  232,  173,  232,  232,  232,  232,  230,
 /*  1420 */   232,  232,  232,  182,  232,  232,  232,  193,  232,  200,
 /*  1430 */   232,  207,  210,  233,  216,  219,  232,  226,  228,   23,
 /*  1440 */   192,  294,  232,   36,  153,  155,  232,  295,  164,  232,
 /*  1450 */   173,  232,  232,  232,  232,  230,  232,  232,  232,  182,
 /*  1460 */   232,  232,  232,  193,  232,  200,  232,  207,  210,  233,
 /*  1470 */   216,  219,  232,  226,  228,   23,  192,  298,  232,   36,
 /*  1480 */   153,  155,  232,  232,  164,  232,  173,  232,  232,  232,
 /*  1490 */   232,  230,  232,  232,  232,  182,  232,  232,  232,  193,
 /*  1500 */   232,  200,  232,  207,  210,  233,  216,  219,  232,  226,
 /*  1510 */   228,   23,  192,  232,  232,   36,  153,  155,  232,  232,
 /*  1520 */   164,  232,  173,  232,  232,  232,  232,  232,  232,  232,
 /*  1530 */   232,  182,  232,  232,  232,  193,  232,  200,  100,  207,
 /*  1540 */   210,  232,  216,  219,  100,  226,  228,  232,  232,  232,
 /*  1550 */   232,  232,  149,  232,   43,   40,  232,  147,   95,   97,
 /*  1560 */    43,   40,  232,  232,   95,   97,  232,  232,  115,  309,
 /*  1570 */    22,  100,  232,  232,  115,  116,  117,  118,  119,  120,
 /*  1580 */   121,  116,  117,  118,  119,  120,  121,   43,   40,  232,
 /*  1590 */   232,  144,   97,  232,  232,  232,  232,  132,  100,  232,
 /*  1600 */   106,  115,  232,  232,  232,  232,  106,  232,  116,  117,
 /*  1610 */   118,  119,  120,  121,   43,   40,  232,  232,   95,   97,
 /*  1620 */   230,  232,  232,  232,  232,  232,  100,  232,  143,  232,
 /*  1630 */   232,  146,  232,  106,  233,  142,  117,  118,  119,  120,
 /*  1640 */   121,  232,   43,   40,  232,  232,   95,   97,  232,  232,
 /*  1650 */   232,  232,  232,  100,  232,  232,  115,  232,  232,  232,
 /*  1660 */   106,  130,  232,  116,  127,  118,  119,  120,  121,   43,
 /*  1670 */    40,  232,  232,   95,   97,  232,  232,  232,  232,  232,
 /*  1680 */   100,  232,  232,  115,  232,  232,  232,  232,  106,  232,
 /*  1690 */   116,  111,  118,  119,  120,  121,   43,   40,  232,  232,
 /*  1700 */    95,   97,  232,  232,  232,  232,  232,  100,  232,  232,
 /*  1710 */   115,  232,  232,  232,  102,  106,  232,  116,  111,  118,
 /*  1720 */   119,  120,  121,   43,   40,  232,  232,   95,   97,  232,
 /*  1730 */   232,  232,  232,  232,  232,  100,  232,  115,  232,  232,
 /*  1740 */   232,  232,  106,  107,  116,  117,  118,  119,  120,  121,
 /*  1750 */   232,   43,   40,  232,  232,   95,   97,  232,  232,  232,
 /*  1760 */   232,  232,  100,  232,  232,  115,  232,  145,  232,  106,
 /*  1770 */   250,  232,  116,  127,  118,  119,  120,  121,   43,   40,
 /*  1780 */   232,  232,   95,   97,  232,  232,  232,  232,  232,  100,
 /*  1790 */   232,  232,  115,  232,  232,  232,  232,  106,  232,  116,
 /*  1800 */   117,  118,  119,  120,  121,   43,   40,  232,  232,   95,
 /*  1810 */    97,  232,  232,  232,  232,  232,  100,  232,  232,  115,
 /*  1820 */   232,  232,  232,  232,  106,  232,  116,  111,  118,  119,
 /*  1830 */   120,  121,   43,   40,  232,  232,   95,   97,  232,  232,
 /*  1840 */   232,  232,  232,  232,  232,  232,  115,  232,  232,  232,
 /*  1850 */   232,  106,  232,  116,  127,  118,  119,  120,  121,  232,
 /*  1860 */   232,  232,  232,  232,  232,  232,  232,  232,  232,  232,
 /*  1870 */   232,  232,  232,  232,  232,  232,  232,  232,  106,
};
static KKCODETYPE kk_lookahead[] = {
 /*     0 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*    10 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    20 */    23,   24,   25,   26,   27,   28,   29,   30,    3,    4,
 /*    30 */     0,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*    40 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*    50 */    25,   26,   27,   28,   30,   30,   19,   20,   21,   22,
 /*    60 */    23,   24,   25,   26,   27,   28,   30,   67,   43,   26,
 /*    70 */    27,   28,    3,    4,    2,    6,    7,    8,    9,   10,
 /*    80 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    90 */    21,   22,   23,   24,   25,   26,   27,   28,   30,   30,
 /*   100 */     3,    4,   30,    6,    7,    8,    9,   10,   11,   12,
 /*   110 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   120 */    23,   24,   25,   26,   27,   28,   29,   30,   59,    3,
 /*   130 */     4,    3,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   140 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   150 */    24,   25,   26,   27,   28,    5,   30,    3,    4,  101,
 /*   160 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   170 */    16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
 /*   180 */    26,   27,   28,    2,   30,    3,    4,   67,    6,    7,
 /*   190 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   200 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   210 */    28,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   220 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   230 */    22,   23,   24,   25,   26,   27,   28,   22,   23,   24,
 /*   240 */    25,   26,   27,   28,   25,   26,   27,   28,    2,   67,
 /*   250 */    69,   94,   95,    3,    4,   67,    6,    7,    8,    9,
 /*   260 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   270 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   43,
 /*   280 */    44,   45,   46,   47,   48,   36,    2,   41,    2,    3,
 /*   290 */    36,   41,   43,   96,   97,    3,    4,   43,    6,    7,
 /*   300 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   310 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   320 */    28,   67,   30,    3,    4,   41,    6,    7,    8,    9,
 /*   330 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   340 */    20,   21,   22,   23,   24,   25,   26,   27,   28,    5,
 /*   350 */    30,    3,    4,  101,    6,    7,    8,    9,   10,   11,
 /*   360 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   370 */    22,   23,   24,   25,   26,   27,   28,    6,    7,    8,
 /*   380 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   390 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   400 */    52,   36,   47,   48,    3,    4,   41,    6,    7,    8,
 /*   410 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   420 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   430 */    67,   30,    3,    4,   67,    6,    7,    8,    9,   10,
 /*   440 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   450 */    21,   22,   23,   24,   25,   26,   27,   28,    5,   30,
 /*   460 */     3,    4,   30,    6,    7,    8,    9,   10,   11,   12,
 /*   470 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   480 */    23,   24,   25,   26,   27,   28,    3,    4,   36,    6,
 /*   490 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   500 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   510 */    27,   28,    4,   36,    6,    7,    8,    9,   10,   11,
 /*   520 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   530 */    22,   23,   24,   25,   26,   27,   28,   71,   72,   73,
 /*   540 */    74,   75,   76,   77,   78,   79,   80,   81,   82,   83,
 /*   550 */    84,   85,   86,   87,   88,   89,   90,   91,   92,    8,
 /*   560 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   570 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   580 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   590 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   600 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   610 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   620 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   630 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   640 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   650 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   660 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   670 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   680 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   690 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   700 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   710 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   720 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   730 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   740 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   750 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   760 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   770 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   780 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   790 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   800 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   810 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   820 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   830 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   840 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   850 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   860 */    74,   75,   76,   77,   78,   79,   80,   81,   82,   83,
 /*   870 */    84,   85,   86,   87,   88,   89,   90,   91,   92,   10,
 /*   880 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   890 */    21,   22,   23,   24,   25,   26,   27,   28,    1,   29,
 /*   900 */    30,   31,   32,   33,   34,   35,   93,    5,   38,    5,
 /*   910 */    40,   93,   99,   30,   93,    2,  103,  104,  100,   49,
 /*   920 */   102,  103,  101,   53,  103,   55,   95,   57,   58,    1,
 /*   930 */    60,   61,   36,   63,   64,   29,   30,   31,   32,   33,
 /*   940 */    34,   35,   93,   27,   38,   30,   40,   93,   51,  100,
 /*   950 */    39,  102,  103,   99,   41,   49,   36,  103,  104,   53,
 /*   960 */     1,   55,   65,   57,   58,   30,   60,   61,   30,   63,
 /*   970 */    64,   29,   30,   31,   93,   33,   34,   35,   93,   51,
 /*   980 */    38,   30,   40,  102,  103,   30,   93,   30,  103,  104,
 /*   990 */    30,   49,   44,   65,   93,   53,  103,   55,   30,   57,
 /*  1000 */    58,    1,   60,   61,  103,   63,   64,   29,   30,    1,
 /*  1010 */    51,   33,   34,   35,   30,   37,   38,   30,   40,   93,
 /*  1020 */    30,   30,   93,   30,   65,   30,   30,   49,   30,  103,
 /*  1030 */    93,   53,  103,   55,   30,   57,   58,    1,   60,   61,
 /*  1040 */   103,   63,   64,   29,   30,    1,   30,   33,   34,   35,
 /*  1050 */     1,   51,   38,   30,   40,   50,   42,   30,   93,   51,
 /*  1060 */    93,   30,   36,   49,   98,   65,   93,   53,  103,   55,
 /*  1070 */   103,   57,   58,   65,   60,   61,  103,   63,   64,   29,
 /*  1080 */    30,    1,   93,   33,   34,   35,   39,   51,   38,   97,
 /*  1090 */    40,   36,  103,   30,   93,   51,   93,    3,   30,   49,
 /*  1100 */    50,   65,   93,   53,  103,   55,  103,   57,   58,   65,
 /*  1110 */    60,   61,  103,   63,   64,   29,   30,    1,   93,   33,
 /*  1120 */    34,   35,   30,   93,   38,   30,   40,   93,  103,   30,
 /*  1130 */    30,   51,   93,  103,   31,   49,  105,  103,   93,   53,
 /*  1140 */    54,   55,  103,   57,   58,   65,   60,   61,  103,   63,
 /*  1150 */    64,   29,   30,    1,   93,   33,   34,   35,    1,   93,
 /*  1160 */    38,   30,   40,   93,  103,  105,   93,   51,  105,  103,
 /*  1170 */   105,   49,  105,  103,   93,   53,  103,   55,   56,   57,
 /*  1180 */    58,   65,   60,   61,  103,   63,   64,   29,   30,    1,
 /*  1190 */    93,   33,   34,   35,   93,   93,   38,  105,   40,   93,
 /*  1200 */   103,  105,   93,   51,  103,  103,  105,   49,  105,  103,
 /*  1210 */   105,   53,  103,   55,  105,   57,   58,   65,   60,   61,
 /*  1220 */    62,   63,   64,   29,   30,    1,   93,   33,   34,   35,
 /*  1230 */   105,   93,   38,  105,   40,   93,  103,  105,   93,   51,
 /*  1240 */    93,  103,  105,   49,  105,  103,  105,   53,  103,   55,
 /*  1250 */   103,   57,   58,   65,   60,   61,   62,   63,   64,   29,
 /*  1260 */    30,    1,  105,   33,   34,   35,  105,   93,   38,  105,
 /*  1270 */    40,   93,   93,  105,   93,   51,  105,  103,  105,   49,
 /*  1280 */   105,  103,  103,   53,  103,   55,   56,   57,   58,   65,
 /*  1290 */    60,   61,   93,   63,   64,   29,   30,    1,   93,   33,
 /*  1300 */    34,   35,  103,   93,   38,  105,   40,   93,  103,  105,
 /*  1310 */   105,   51,   93,  103,  105,   49,  105,  103,   93,   53,
 /*  1320 */    54,   55,  103,   57,   58,   65,   60,   61,  103,   63,
 /*  1330 */    64,   29,   30,    1,  105,   33,   34,   35,  105,   93,
 /*  1340 */    38,  105,   40,   93,   42,  105,   93,   51,  105,  103,
 /*  1350 */   105,   49,  105,  103,  105,   53,  103,   55,  105,   57,
 /*  1360 */    58,   65,   60,   61,  105,   63,   64,   29,   30,    1,
 /*  1370 */   105,   33,   34,   35,  105,   37,   38,  105,   40,  105,
 /*  1380 */   105,  105,  105,   51,  105,  105,  105,   49,  105,  105,
 /*  1390 */   105,   53,  105,   55,  105,   57,   58,   65,   60,   61,
 /*  1400 */   105,   63,   64,   29,   30,    1,  105,   33,   34,   35,
 /*  1410 */   105,   37,   38,  105,   40,  105,  105,  105,  105,   51,
 /*  1420 */   105,  105,  105,   49,  105,  105,  105,   53,  105,   55,
 /*  1430 */   105,   57,   58,   65,   60,   61,  105,   63,   64,   29,
 /*  1440 */    30,    1,  105,   33,   34,   35,  105,   37,   38,  105,
 /*  1450 */    40,  105,  105,  105,  105,   51,  105,  105,  105,   49,
 /*  1460 */   105,  105,  105,   53,  105,   55,  105,   57,   58,   65,
 /*  1470 */    60,   61,  105,   63,   64,   29,   30,   31,  105,   33,
 /*  1480 */    34,   35,  105,  105,   38,  105,   40,  105,  105,  105,
 /*  1490 */   105,   51,  105,  105,  105,   49,  105,  105,  105,   53,
 /*  1500 */   105,   55,  105,   57,   58,   65,   60,   61,  105,   63,
 /*  1510 */    64,   29,   30,  105,  105,   33,   34,   35,  105,  105,
 /*  1520 */    38,  105,   40,  105,  105,  105,  105,  105,  105,  105,
 /*  1530 */   105,   49,  105,  105,  105,   53,  105,   55,    6,   57,
 /*  1540 */    58,  105,   60,   61,    6,   63,   64,  105,  105,  105,
 /*  1550 */   105,  105,   20,  105,   22,   23,  105,   19,   26,   27,
 /*  1560 */    22,   23,  105,  105,   26,   27,  105,  105,   36,    0,
 /*  1570 */     1,    6,  105,  105,   36,   43,   44,   45,   46,   47,
 /*  1580 */    48,   43,   44,   45,   46,   47,   48,   22,   23,  105,
 /*  1590 */   105,   26,   27,  105,  105,  105,  105,    5,    6,  105,
 /*  1600 */    68,   36,  105,  105,  105,  105,   68,  105,   43,   44,
 /*  1610 */    45,   46,   47,   48,   22,   23,  105,  105,   26,   27,
 /*  1620 */    51,  105,  105,  105,  105,  105,    6,  105,   36,  105,
 /*  1630 */   105,   66,  105,   68,   65,   43,   44,   45,   46,   47,
 /*  1640 */    48,  105,   22,   23,  105,  105,   26,   27,  105,  105,
 /*  1650 */   105,  105,  105,    6,  105,  105,   36,  105,  105,  105,
 /*  1660 */    68,   41,  105,   43,   44,   45,   46,   47,   48,   22,
 /*  1670 */    23,  105,  105,   26,   27,  105,  105,  105,  105,  105,
 /*  1680 */     6,  105,  105,   36,  105,  105,  105,  105,   68,  105,
 /*  1690 */    43,   44,   45,   46,   47,   48,   22,   23,  105,  105,
 /*  1700 */    26,   27,  105,  105,  105,  105,  105,    6,  105,  105,
 /*  1710 */    36,  105,  105,  105,   67,   68,  105,   43,   44,   45,
 /*  1720 */    46,   47,   48,   22,   23,  105,  105,   26,   27,  105,
 /*  1730 */   105,  105,  105,  105,  105,    6,  105,   36,  105,  105,
 /*  1740 */   105,  105,   68,   69,   43,   44,   45,   46,   47,   48,
 /*  1750 */   105,   22,   23,  105,  105,   26,   27,  105,  105,  105,
 /*  1760 */   105,  105,    6,  105,  105,   36,  105,   66,  105,   68,
 /*  1770 */    41,  105,   43,   44,   45,   46,   47,   48,   22,   23,
 /*  1780 */   105,  105,   26,   27,  105,  105,  105,  105,  105,    6,
 /*  1790 */   105,  105,   36,  105,  105,  105,  105,   68,  105,   43,
 /*  1800 */    44,   45,   46,   47,   48,   22,   23,  105,  105,   26,
 /*  1810 */    27,  105,  105,  105,  105,  105,    6,  105,  105,   36,
 /*  1820 */   105,  105,  105,  105,   68,  105,   43,   44,   45,   46,
 /*  1830 */    47,   48,   22,   23,  105,  105,   26,   27,  105,  105,
 /*  1840 */   105,  105,  105,  105,  105,  105,   36,  105,  105,  105,
 /*  1850 */   105,   68,  105,   43,   44,   45,   46,   47,   48,  105,
 /*  1860 */   105,  105,  105,  105,  105,  105,  105,  105,  105,  105,
 /*  1870 */   105,  105,  105,  105,  105,  105,  105,  105,   68,
};
#define KK_SHIFT_USE_DFLT (-4)
static short kk_shift_ofst[] = {
 /*     0 */   897,   30, 1569,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    20 */    -4,   -4, 1482, 1756,  126,  928,  959,  870,   24,   -4,
 /*    30 */    36, 1000, 1008,  942,   68,   -4, 1756,  154,   -4, 1756,
 /*    40 */  1756,  219, 1756, 1756,  219, 1532,  215, 1538,  215, 1756,
 /*    50 */   215, 1756,  869, 1756,  869, 1756,  219, 1756,   43, 1756,
 /*    60 */   551, 1756,   37, 1565,   37, 1756,   37, 1756,   37, 1756,
 /*    70 */    37, 1756,   37, 1756,   37, 1756,   37, 1756,   37, 1756,
 /*    80 */    -4, 1756,  508,  128, 1756,   43, 1592,  182,   -4, 1756,
 /*    90 */   208, 1756,  371, 1620,  457, 1756,   43, 1756,  250,   -4,
 /*   100 */  1647,  457,   -4,    0,   -4, 1783, 1674,   -4,  181,   -4,
 /*   110 */    -4,  150, 1756,  457,   -4,   -4,   -4,   -4,   -4,   -4,
 /*   120 */    -4,   -4,   -4,  246,   -4, 1810,   -4,  344, 1756,  457,
 /*   130 */    -4,   -4,  249,  120,   -4,  188,  363,  453,  254,   -4,
 /*   140 */   367,   -4,  902,  904, 1701,   -4,   -4, 1756,  215, 1756,
 /*   150 */   215,  219,  219,  432,   -4,  452,  286, 1756,   -3,  897,
 /*   160 */  1036,  978,  883,   -4,  477,   72,   -4,  477,   -4,  911,
 /*   170 */  1756,  457,   -4,  896,  916,  365,  915,  897, 1044, 1014,
 /*   180 */   935,   -4, 1756,  483, 1729,  284,  938,  897, 1080, 1050,
 /*   190 */   951,   -4,   -4,  920,  955, 1116, 1152, 1086,  957,   -4,
 /*   200 */  1756,   25,  897, 1188, 1122,  960,   -4,  948,  968,   -4,
 /*   210 */  1756,   69,   -4, 1756,  292,   -4, 1756,  320,   -4,  355,
 /*   220 */   984,  897, 1224, 1158,  987,   -4,  990,   -4,  991,   -4,
 /*   230 */  1756,  348,   -4,   -4,   -4,  993,  897, 1260, 1194,  995,
 /*   240 */    -4,  996,  897, 1296, 1230,  998,   -4, 1266, 1004,   -4,
 /*   250 */  1016, 1049, 1005, 1023,   -4,  913, 1027,  897, 1332, 1302,
 /*   260 */  1031,   -4, 1026,   -4, 1047,  236,   -4,   -4,   -4,   -4,
 /*   270 */    -4,   -4,   -4,   -4, 1756,  401,  897, 1368, 1338, 1063,
 /*   280 */    -4, 1055, 1094, 1756,   97,  897, 1404, 1374, 1068,   -4,
 /*   290 */  1756,  429,  897, 1440, 1410, 1092,   -4, 1446, 1095,   -4,
 /*   300 */   906, 1099,   -4, 1100, 1157, 1103, 1131,   -4,
};
#define KK_REDUCE_USE_DFLT (-1)
static short kk_reduce_ofst[] = {
 /*     0 */   466,   -1,  786,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*    10 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*    20 */    -1,   -1,   -1,  893,   -1,  507,  786,   -1,   -1,   -1,
 /*    30 */    -1,  527,  786,   -1,   -1,   -1,  901,   -1,   -1,  926,
 /*    40 */   929,   -1,  937,  965,   -1,  967,   -1,  973,   -1,  989,
 /*    50 */    -1, 1001,   -1, 1003,   -1, 1009,   -1, 1025,   -1, 1030,
 /*    60 */    -1, 1034,   -1, 1039,   -1, 1045,   -1, 1061,   -1, 1066,
 /*    70 */    -1, 1070,   -1, 1073,   -1, 1081,   -1, 1097,   -1, 1101,
 /*    80 */    -1, 1102,   -1,   -1, 1106,   -1,  821,   -1,   -1, 1109,
 /*    90 */    -1, 1133,   -1,  813,   -1, 1138,   -1, 1142,   -1,   -1,
 /*   100 */   818,   -1,   -1,   -1,   -1,  881,  849,   -1,   -1,   -1,
 /*   110 */    -1,   -1, 1145,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   120 */    -1,   -1,   -1,   -1,   -1,  885,   -1,   -1, 1147,   -1,
 /*   130 */    -1,   -1,   58,   -1,   -1,   -1,   -1,   -1,  252,   -1,
 /*   140 */    -1,   -1,   -1,   -1, 1138,   -1,   -1, 1174,   -1, 1178,
 /*   150 */    -1,   -1,   -1,   -1,   -1,   -1,   -1, 1179,   -1,  547,
 /*   160 */   786,   -1,   -1,   -1,  157,   -1,   -1,  831,   -1,   -1,
 /*   170 */  1181,   -1,   -1,   -1,   -1,  197,   -1,  567,  786,   -1,
 /*   180 */    -1,   -1, 1199,   -1,  854,   -1,   -1,  587,  786,   -1,
 /*   190 */    -1,   -1,   -1,   -1,   -1,  607,  786,   -1,   -1,   -1,
 /*   200 */  1205,   -1,  627,  786,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   210 */  1210,   -1,   -1, 1214,   -1,   -1, 1219,   -1,   -1,   -1,
 /*   220 */    -1,  647,  786,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   230 */  1225,   -1,   -1,   -1,   -1,   -1,  667,  786,   -1,   -1,
 /*   240 */    -1,   -1,  687,  786,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   250 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,  707,  786,   -1,
 /*   260 */    -1,   -1,  992,   -1,   -1,  966,   -1,   -1,   -1,   -1,
 /*   270 */    -1,   -1,   -1,   -1, 1246,   -1,  727,  786,   -1,   -1,
 /*   280 */    -1,   -1,   -1, 1250,   -1,  747,  786,   -1,   -1,   -1,
 /*   290 */  1253,   -1,  767,  786,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   300 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
static KKACTIONTYPE kk_default[] = {
 /*     0 */   433,  433,  433,  310,  312,  313,  314,  315,  316,  317,
 /*    10 */   318,  319,  320,  321,  322,  323,  324,  325,  326,  327,
 /*    20 */   328,  329,  433,  433,  433,  433,  433,  433,  433,  330,
 /*    30 */   433,  433,  433,  433,  433,  332,  433,  433,  335,  433,
 /*    40 */   433,  374,  433,  433,  375,  433,  378,  433,  380,  433,
 /*    50 */   382,  433,  383,  433,  384,  433,  385,  433,  386,  433,
 /*    60 */   387,  433,  388,  433,  391,  433,  392,  433,  393,  433,
 /*    70 */   394,  433,  395,  433,  396,  433,  397,  433,  398,  433,
 /*    80 */   399,  433,  400,  433,  433,  401,  433,  433,  408,  433,
 /*    90 */   433,  433,  409,  433,  424,  433,  402,  433,  433,  403,
 /*   100 */   433,  418,  404,  433,  405,  433,  433,  406,  433,  407,
 /*   110 */   416,  428,  433,  417,  419,  426,  427,  428,  429,  430,
 /*   120 */   431,  432,  415,  433,  420,  433,  422,  428,  433,  425,
 /*   130 */   421,  423,  433,  433,  410,  433,  433,  433,  433,  411,
 /*   140 */   433,  412,  427,  426,  433,  389,  390,  433,  381,  433,
 /*   150 */   379,  377,  376,  433,  336,  433,  433,  433,  433,  433,
 /*   160 */   433,  433,  433,  337,  433,  433,  341,  433,  342,  433,
 /*   170 */   433,  344,  343,  433,  433,  433,  433,  433,  433,  433,
 /*   180 */   433,  345,  433,  433,  433,  433,  420,  433,  433,  433,
 /*   190 */   433,  357,  359,  433,  433,  433,  433,  433,  433,  361,
 /*   200 */   433,  433,  433,  433,  433,  433,  363,  433,  433,  365,
 /*   210 */   433,  433,  366,  433,  433,  367,  433,  433,  368,  433,
 /*   220 */   433,  433,  433,  433,  433,  369,  433,  371,  433,  372,
 /*   230 */   433,  433,  360,  373,  311,  433,  433,  433,  433,  433,
 /*   240 */   370,  433,  433,  433,  433,  433,  364,  433,  433,  362,
 /*   250 */   421,  433,  433,  433,  358,  433,  433,  433,  433,  433,
 /*   260 */   433,  346,  433,  347,  349,  433,  350,  351,  352,  353,
 /*   270 */   354,  355,  356,  348,  433,  433,  433,  433,  433,  433,
 /*   280 */   338,  433,  433,  433,  433,  433,  433,  433,  433,  339,
 /*   290 */   433,  433,  433,  433,  433,  433,  340,  433,  433,  333,
 /*   300 */   433,  433,  331,  433,  433,  433,  433,  334,
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
  "MACRO",         "PARENTHESES_CLOSE",  "ENDMACRO",      "INTEGER",     
  "STRING",        "DOUBLE",        "NULL",          "FALSE",       
  "TRUE",          "CALL",          "ENDCALL",       "OPEN_EDELIMITER",
  "CLOSE_EDELIMITER",  "BLOCK",         "ENDBLOCK",      "CACHE",       
  "ENDCACHE",      "EXTENDS",       "INCLUDE",       "WITH",        
  "DO",            "AUTOESCAPE",    "ENDAUTOESCAPE",  "BREAK",       
  "CONTINUE",      "RAW_FRAGMENT",  "DEFINED",       "SBRACKET_CLOSE",
  "CBRACKET_OPEN",  "CBRACKET_CLOSE",  "error",         "program",     
  "volt_language",  "statement_list",  "statement",     "raw_fragment",
  "if_statement",  "elseif_statement",  "elsefor_statement",  "for_statement",
  "set_statement",  "echo_statement",  "block_statement",  "cache_statement",
  "extends_statement",  "include_statement",  "do_statement",  "autoescape_statement",
  "break_statement",  "continue_statement",  "macro_statement",  "empty_statement",
  "macro_call_statement",  "expr",          "set_assignments",  "set_assignment",
  "macro_parameters",  "macro_parameter",  "macro_parameter_default",  "argument_list",
  "array_list",    "slice_offset",  "array_item",    "function_call",
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
 /*  19 */ "statement ::= macro_statement",
 /*  20 */ "statement ::= empty_statement",
 /*  21 */ "statement ::= macro_call_statement",
 /*  22 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  23 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  24 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  25 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  26 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER OPEN_DELIMITER ELSE CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  27 */ "elseif_statement ::= OPEN_DELIMITER ELSEIF expr CLOSE_DELIMITER",
 /*  28 */ "elsefor_statement ::= OPEN_DELIMITER ELSEFOR CLOSE_DELIMITER",
 /*  29 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  30 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  31 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  32 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  33 */ "set_statement ::= OPEN_DELIMITER SET set_assignments CLOSE_DELIMITER",
 /*  34 */ "set_assignments ::= set_assignments COMMA set_assignment",
 /*  35 */ "set_assignments ::= set_assignment",
 /*  36 */ "set_assignment ::= IDENTIFIER ASSIGN expr",
 /*  37 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  38 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN macro_parameters PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  39 */ "macro_parameters ::= macro_parameters COMMA macro_parameter",
 /*  40 */ "macro_parameters ::= macro_parameter",
 /*  41 */ "macro_parameter ::= IDENTIFIER",
 /*  42 */ "macro_parameter ::= IDENTIFIER ASSIGN macro_parameter_default",
 /*  43 */ "macro_parameter_default ::= INTEGER",
 /*  44 */ "macro_parameter_default ::= STRING",
 /*  45 */ "macro_parameter_default ::= DOUBLE",
 /*  46 */ "macro_parameter_default ::= NULL",
 /*  47 */ "macro_parameter_default ::= FALSE",
 /*  48 */ "macro_parameter_default ::= TRUE",
 /*  49 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  50 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  51 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  52 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  53 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  54 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  55 */ "cache_statement ::= OPEN_DELIMITER CACHE expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  56 */ "cache_statement ::= OPEN_DELIMITER CACHE expr INTEGER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  57 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  58 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr CLOSE_DELIMITER",
 /*  59 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr WITH expr CLOSE_DELIMITER",
 /*  60 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  61 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE FALSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  62 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE TRUE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  63 */ "break_statement ::= OPEN_DELIMITER BREAK CLOSE_DELIMITER",
 /*  64 */ "continue_statement ::= OPEN_DELIMITER CONTINUE CLOSE_DELIMITER",
 /*  65 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  66 */ "expr ::= MINUS expr",
 /*  67 */ "expr ::= PLUS expr",
 /*  68 */ "expr ::= expr MINUS expr",
 /*  69 */ "expr ::= expr PLUS expr",
 /*  70 */ "expr ::= expr TIMES expr",
 /*  71 */ "expr ::= expr TIMES TIMES expr",
 /*  72 */ "expr ::= expr DIVIDE expr",
 /*  73 */ "expr ::= expr DIVIDE DIVIDE expr",
 /*  74 */ "expr ::= expr MOD expr",
 /*  75 */ "expr ::= expr AND expr",
 /*  76 */ "expr ::= expr OR expr",
 /*  77 */ "expr ::= expr CONCAT expr",
 /*  78 */ "expr ::= expr PIPE expr",
 /*  79 */ "expr ::= expr RANGE expr",
 /*  80 */ "expr ::= expr EQUALS expr",
 /*  81 */ "expr ::= expr IS NOT DEFINED",
 /*  82 */ "expr ::= expr IS DEFINED",
 /*  83 */ "expr ::= expr IS expr",
 /*  84 */ "expr ::= expr NOTEQUALS expr",
 /*  85 */ "expr ::= expr IDENTICAL expr",
 /*  86 */ "expr ::= expr NOTIDENTICAL expr",
 /*  87 */ "expr ::= expr LESS expr",
 /*  88 */ "expr ::= expr GREATER expr",
 /*  89 */ "expr ::= expr GREATEREQUAL expr",
 /*  90 */ "expr ::= expr LESSEQUAL expr",
 /*  91 */ "expr ::= expr DOT expr",
 /*  92 */ "expr ::= expr IN expr",
 /*  93 */ "expr ::= expr NOT IN expr",
 /*  94 */ "expr ::= NOT expr",
 /*  95 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /*  96 */ "expr ::= SBRACKET_OPEN SBRACKET_CLOSE",
 /*  97 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /*  98 */ "expr ::= CBRACKET_OPEN CBRACKET_CLOSE",
 /*  99 */ "expr ::= CBRACKET_OPEN array_list CBRACKET_CLOSE",
 /* 100 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /* 101 */ "expr ::= expr QUESTION expr COLON expr",
 /* 102 */ "expr ::= expr SBRACKET_OPEN COLON slice_offset SBRACKET_CLOSE",
 /* 103 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON SBRACKET_CLOSE",
 /* 104 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON slice_offset SBRACKET_CLOSE",
 /* 105 */ "slice_offset ::= INTEGER",
 /* 106 */ "slice_offset ::= IDENTIFIER",
 /* 107 */ "array_list ::= array_list COMMA array_item",
 /* 108 */ "array_list ::= array_item",
 /* 109 */ "array_item ::= STRING COLON expr",
 /* 110 */ "array_item ::= expr",
 /* 111 */ "expr ::= function_call",
 /* 112 */ "function_call ::= expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 113 */ "function_call ::= expr PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 114 */ "argument_list ::= argument_list COMMA argument_item",
 /* 115 */ "argument_list ::= argument_item",
 /* 116 */ "argument_item ::= expr",
 /* 117 */ "argument_item ::= STRING COLON expr",
 /* 118 */ "expr ::= IDENTIFIER",
 /* 119 */ "expr ::= INTEGER",
 /* 120 */ "expr ::= STRING",
 /* 121 */ "expr ::= DOUBLE",
 /* 122 */ "expr ::= NULL",
 /* 123 */ "expr ::= FALSE",
 /* 124 */ "expr ::= TRUE",
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
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
// 630 "parser.lemon"
{
	if ((kkpminor->kk0)) {
		if ((kkpminor->kk0)->free_flag) {
			efree((kkpminor->kk0)->token);
		}
		efree((kkpminor->kk0));
	}
}
// 1526 "parser.c"
      break;
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
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
    case 96:
    case 97:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
// 647 "parser.lemon"
{ zval_ptr_dtor(&(kkpminor->kk78)); }
// 1561 "parser.c"
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
  { 71, 1 },
  { 72, 1 },
  { 73, 2 },
  { 73, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 76, 8 },
  { 76, 7 },
  { 76, 12 },
  { 76, 11 },
  { 76, 10 },
  { 77, 4 },
  { 78, 3 },
  { 79, 10 },
  { 79, 12 },
  { 79, 12 },
  { 79, 14 },
  { 80, 4 },
  { 94, 3 },
  { 94, 1 },
  { 95, 3 },
  { 90, 10 },
  { 90, 11 },
  { 96, 3 },
  { 96, 1 },
  { 97, 1 },
  { 97, 3 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 92, 11 },
  { 92, 9 },
  { 91, 2 },
  { 81, 3 },
  { 82, 8 },
  { 82, 7 },
  { 83, 8 },
  { 83, 9 },
  { 84, 4 },
  { 85, 4 },
  { 85, 6 },
  { 86, 4 },
  { 87, 8 },
  { 87, 8 },
  { 88, 3 },
  { 89, 3 },
  { 75, 1 },
  { 93, 2 },
  { 93, 2 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 4 },
  { 93, 3 },
  { 93, 4 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 4 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 3 },
  { 93, 4 },
  { 93, 2 },
  { 93, 3 },
  { 93, 2 },
  { 93, 3 },
  { 93, 2 },
  { 93, 3 },
  { 93, 4 },
  { 93, 5 },
  { 93, 5 },
  { 93, 5 },
  { 93, 6 },
  { 101, 1 },
  { 101, 1 },
  { 100, 3 },
  { 100, 1 },
  { 102, 3 },
  { 102, 1 },
  { 93, 1 },
  { 103, 4 },
  { 103, 3 },
  { 99, 3 },
  { 99, 1 },
  { 104, 1 },
  { 104, 3 },
  { 93, 1 },
  { 93, 1 },
  { 93, 1 },
  { 93, 1 },
  { 93, 1 },
  { 93, 1 },
  { 93, 1 },
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
// 639 "parser.lemon"
{
	status->ret = kkmsp[0].minor.kk78;
}
// 1903 "parser.c"
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
      case 20:
      case 21:
      case 111:
// 643 "parser.lemon"
{
	kkgotominor.kk78 = kkmsp[0].minor.kk78;
}
// 1929 "parser.c"
        break;
      case 2:
// 649 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_zval_list(kkmsp[-1].minor.kk78, kkmsp[0].minor.kk78);
}
// 1936 "parser.c"
        break;
      case 3:
      case 35:
      case 40:
      case 108:
      case 115:
// 653 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_zval_list(NULL, kkmsp[0].minor.kk78);
}
// 1947 "parser.c"
        break;
      case 22:
// 733 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_if_statement(kkmsp[-5].minor.kk78, kkmsp[-3].minor.kk78, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(29,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(31,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1960 "parser.c"
        break;
      case 23:
// 737 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_if_statement(kkmsp[-4].minor.kk78, NULL, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(29,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(31,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1973 "parser.c"
        break;
      case 24:
// 741 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_if_statement(kkmsp[-9].minor.kk78, kkmsp[-7].minor.kk78, kkmsp[-3].minor.kk78, status->scanner_state);
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
// 1989 "parser.c"
        break;
      case 25:
// 745 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_if_statement(kkmsp[-8].minor.kk78, kkmsp[-6].minor.kk78, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(29,&kkmsp[-9].minor);
  kk_destructor(30,&kkmsp[-7].minor);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(30,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(31,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2005 "parser.c"
        break;
      case 26:
// 749 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_if_statement(kkmsp[-7].minor.kk78, NULL, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(29,&kkmsp[-8].minor);
  kk_destructor(30,&kkmsp[-6].minor);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(30,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(31,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2021 "parser.c"
        break;
      case 27:
// 755 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_elseif_statement(kkmsp[-1].minor.kk78, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(33,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2031 "parser.c"
        break;
      case 28:
// 761 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_elsefor_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(34,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2041 "parser.c"
        break;
      case 29:
// 767 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-5].minor.kk78, NULL, kkmsp[-3].minor.kk78, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(35,&kkmsp[-8].minor);
  kk_destructor(3,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2055 "parser.c"
        break;
      case 30:
// 771 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, NULL, kkmsp[-7].minor.kk78, kkmsp[-5].minor.kk78, kkmsp[-3].minor.kk78, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(35,&kkmsp[-10].minor);
  kk_destructor(3,&kkmsp[-8].minor);
  kk_destructor(29,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2070 "parser.c"
        break;
      case 31:
// 775 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, kkmsp[-9].minor.kk0, kkmsp[-5].minor.kk78, NULL, kkmsp[-3].minor.kk78, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(35,&kkmsp[-10].minor);
  kk_destructor(2,&kkmsp[-8].minor);
  kk_destructor(3,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2085 "parser.c"
        break;
      case 32:
// 779 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, kkmsp[-11].minor.kk0, kkmsp[-7].minor.kk78, kkmsp[-5].minor.kk78, kkmsp[-3].minor.kk78, status->scanner_state);
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
// 2101 "parser.c"
        break;
      case 33:
// 785 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_set_statement(kkmsp[-1].minor.kk78);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(38,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2111 "parser.c"
        break;
      case 34:
      case 39:
      case 107:
      case 114:
// 791 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_zval_list(kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78);
  kk_destructor(2,&kkmsp[-1].minor);
}
// 2122 "parser.c"
        break;
      case 36:
// 801 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk78, status->scanner_state);
  kk_destructor(39,&kkmsp[-1].minor);
}
// 2130 "parser.c"
        break;
      case 37:
// 807 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_macro_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-3].minor.kk78, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(40,&kkmsp[-8].minor);
  kk_destructor(27,&kkmsp[-6].minor);
  kk_destructor(41,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(42,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2145 "parser.c"
        break;
      case 38:
// 811 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_macro_statement(kkmsp[-8].minor.kk0, kkmsp[-6].minor.kk78, kkmsp[-3].minor.kk78, status->scanner_state);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(40,&kkmsp[-9].minor);
  kk_destructor(27,&kkmsp[-7].minor);
  kk_destructor(41,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(42,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2160 "parser.c"
        break;
      case 41:
// 827 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_macro_parameter(kkmsp[0].minor.kk0, NULL, status->scanner_state);
}
// 2167 "parser.c"
        break;
      case 42:
// 831 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_macro_parameter(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk78, status->scanner_state);
  kk_destructor(39,&kkmsp[-1].minor);
}
// 2175 "parser.c"
        break;
      case 43:
      case 105:
      case 119:
// 835 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2184 "parser.c"
        break;
      case 44:
      case 120:
// 839 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_literal_zval(PHVOLT_T_STRING, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2192 "parser.c"
        break;
      case 45:
      case 121:
// 843 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2200 "parser.c"
        break;
      case 46:
      case 122:
// 847 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  kk_destructor(46,&kkmsp[0].minor);
}
// 2209 "parser.c"
        break;
      case 47:
      case 123:
// 851 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  kk_destructor(47,&kkmsp[0].minor);
}
// 2218 "parser.c"
        break;
      case 48:
      case 124:
// 855 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  kk_destructor(48,&kkmsp[0].minor);
}
// 2227 "parser.c"
        break;
      case 49:
// 861 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_macro_call_statement(kkmsp[-8].minor.kk78, kkmsp[-6].minor.kk78, kkmsp[-3].minor.kk78, status->scanner_state);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(49,&kkmsp[-9].minor);
  kk_destructor(27,&kkmsp[-7].minor);
  kk_destructor(41,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(50,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2242 "parser.c"
        break;
      case 50:
// 865 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_macro_call_statement(kkmsp[-6].minor.kk78, NULL, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(49,&kkmsp[-7].minor);
  kk_destructor(27,&kkmsp[-5].minor);
  kk_destructor(41,&kkmsp[-4].minor);
  kk_destructor(30,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(50,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2257 "parser.c"
        break;
      case 51:
// 871 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_empty_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2266 "parser.c"
        break;
      case 52:
// 877 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_echo_statement(kkmsp[-1].minor.kk78, status->scanner_state);
  kk_destructor(51,&kkmsp[-2].minor);
  kk_destructor(52,&kkmsp[0].minor);
}
// 2275 "parser.c"
        break;
      case 53:
// 883 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_block_statement(kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk78, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(53,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(54,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2288 "parser.c"
        break;
      case 54:
// 887 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_block_statement(kkmsp[-4].minor.kk0, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(53,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(54,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2301 "parser.c"
        break;
      case 55:
// 893 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_cache_statement(kkmsp[-5].minor.kk78, NULL, kkmsp[-3].minor.kk78, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(55,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(56,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2314 "parser.c"
        break;
      case 56:
// 897 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_cache_statement(kkmsp[-6].minor.kk78, kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk78, status->scanner_state);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(55,&kkmsp[-7].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(56,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2327 "parser.c"
        break;
      case 57:
// 903 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_extends_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(57,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2337 "parser.c"
        break;
      case 58:
// 909 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_include_statement(kkmsp[-1].minor.kk78, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(58,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2347 "parser.c"
        break;
      case 59:
// 913 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_include_statement(kkmsp[-3].minor.kk78, kkmsp[-1].minor.kk78, status->scanner_state);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(58,&kkmsp[-4].minor);
  kk_destructor(59,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2358 "parser.c"
        break;
      case 60:
// 919 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_do_statement(kkmsp[-1].minor.kk78, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(60,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2368 "parser.c"
        break;
      case 61:
// 925 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_autoescape_statement(0, kkmsp[-3].minor.kk78, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(61,&kkmsp[-6].minor);
  kk_destructor(47,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(62,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2382 "parser.c"
        break;
      case 62:
// 929 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_autoescape_statement(1, kkmsp[-3].minor.kk78, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(61,&kkmsp[-6].minor);
  kk_destructor(48,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(62,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2396 "parser.c"
        break;
      case 63:
// 935 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_break_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(63,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2406 "parser.c"
        break;
      case 64:
// 941 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_continue_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(64,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2416 "parser.c"
        break;
      case 65:
// 947 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2423 "parser.c"
        break;
      case 66:
// 953 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
}
// 2431 "parser.c"
        break;
      case 67:
// 957 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_PLUS, NULL, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 2439 "parser.c"
        break;
      case 68:
// 961 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_SUB, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
}
// 2447 "parser.c"
        break;
      case 69:
// 965 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_ADD, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 2455 "parser.c"
        break;
      case 70:
// 969 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_MUL, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 2463 "parser.c"
        break;
      case 71:
// 973 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_POW, kkmsp[-3].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(20,&kkmsp[-2].minor);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 2472 "parser.c"
        break;
      case 72:
// 977 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_DIV, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 2480 "parser.c"
        break;
      case 73:
// 981 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-3].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(19,&kkmsp[-2].minor);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 2489 "parser.c"
        break;
      case 74:
// 985 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
// 2497 "parser.c"
        break;
      case 75:
// 989 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_AND, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(8,&kkmsp[-1].minor);
}
// 2505 "parser.c"
        break;
      case 76:
// 993 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_OR, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
}
// 2513 "parser.c"
        break;
      case 77:
// 997 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_CONCAT, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-1].minor);
}
// 2521 "parser.c"
        break;
      case 78:
// 1001 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_PIPE, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(25,&kkmsp[-1].minor);
}
// 2529 "parser.c"
        break;
      case 79:
// 1005 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_RANGE, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
}
// 2537 "parser.c"
        break;
      case 80:
// 1009 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_EQUALS, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(11,&kkmsp[-1].minor);
}
// 2545 "parser.c"
        break;
      case 81:
// 1013 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, kkmsp[-3].minor.kk78, NULL, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-2].minor);
  kk_destructor(26,&kkmsp[-1].minor);
  kk_destructor(66,&kkmsp[0].minor);
}
// 2555 "parser.c"
        break;
      case 82:
// 1017 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_ISSET, kkmsp[-2].minor.kk78, NULL, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
  kk_destructor(66,&kkmsp[0].minor);
}
// 2564 "parser.c"
        break;
      case 83:
// 1021 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_IS, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
}
// 2572 "parser.c"
        break;
      case 84:
// 1025 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(12,&kkmsp[-1].minor);
}
// 2580 "parser.c"
        break;
      case 85:
// 1029 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(17,&kkmsp[-1].minor);
}
// 2588 "parser.c"
        break;
      case 86:
// 1033 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(18,&kkmsp[-1].minor);
}
// 2596 "parser.c"
        break;
      case 87:
// 1037 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_LESS, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(13,&kkmsp[-1].minor);
}
// 2604 "parser.c"
        break;
      case 88:
// 1041 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_GREATER, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(14,&kkmsp[-1].minor);
}
// 2612 "parser.c"
        break;
      case 89:
// 1045 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(15,&kkmsp[-1].minor);
}
// 2620 "parser.c"
        break;
      case 90:
// 1049 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(16,&kkmsp[-1].minor);
}
// 2628 "parser.c"
        break;
      case 91:
// 1053 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_DOT, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(28,&kkmsp[-1].minor);
}
// 2636 "parser.c"
        break;
      case 92:
// 1057 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_IN, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(3,&kkmsp[-1].minor);
}
// 2644 "parser.c"
        break;
      case 93:
// 1061 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_NOT_IN, kkmsp[-3].minor.kk78, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(3,&kkmsp[-1].minor);
}
// 2653 "parser.c"
        break;
      case 94:
// 1065 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, kkmsp[0].minor.kk78, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-1].minor);
}
// 2661 "parser.c"
        break;
      case 95:
// 1069 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, kkmsp[-1].minor.kk78, NULL, NULL, status->scanner_state);
  kk_destructor(27,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[0].minor);
}
// 2670 "parser.c"
        break;
      case 96:
// 1073 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-1].minor);
  kk_destructor(67,&kkmsp[0].minor);
}
// 2679 "parser.c"
        break;
      case 97:
// 1077 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk78, NULL, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-2].minor);
  kk_destructor(67,&kkmsp[0].minor);
}
// 2688 "parser.c"
        break;
      case 98:
// 1081 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  kk_destructor(68,&kkmsp[-1].minor);
  kk_destructor(69,&kkmsp[0].minor);
}
// 2697 "parser.c"
        break;
      case 99:
// 1085 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk78, NULL, NULL, status->scanner_state);
  kk_destructor(68,&kkmsp[-2].minor);
  kk_destructor(69,&kkmsp[0].minor);
}
// 2706 "parser.c"
        break;
      case 100:
// 1089 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, kkmsp[-3].minor.kk78, kkmsp[-1].minor.kk78, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-2].minor);
  kk_destructor(67,&kkmsp[0].minor);
}
// 2715 "parser.c"
        break;
      case 101:
// 1093 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_expr(PHVOLT_T_TERNARY, kkmsp[-2].minor.kk78, kkmsp[0].minor.kk78, kkmsp[-4].minor.kk78, status->scanner_state);
  kk_destructor(4,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 2724 "parser.c"
        break;
      case 102:
// 1097 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_slice(kkmsp[-4].minor.kk78, NULL, kkmsp[-1].minor.kk78, status->scanner_state);
  kk_destructor(6,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-2].minor);
  kk_destructor(67,&kkmsp[0].minor);
}
// 2734 "parser.c"
        break;
      case 103:
// 1101 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_slice(kkmsp[-4].minor.kk78, kkmsp[-2].minor.kk78, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-1].minor);
  kk_destructor(67,&kkmsp[0].minor);
}
// 2744 "parser.c"
        break;
      case 104:
// 1105 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_slice(kkmsp[-5].minor.kk78, kkmsp[-3].minor.kk78, kkmsp[-1].minor.kk78, status->scanner_state);
  kk_destructor(6,&kkmsp[-4].minor);
  kk_destructor(5,&kkmsp[-2].minor);
  kk_destructor(67,&kkmsp[0].minor);
}
// 2754 "parser.c"
        break;
      case 106:
      case 118:
// 1115 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2762 "parser.c"
        break;
      case 109:
      case 117:
// 1131 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_named_item(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk78, status->scanner_state);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 2771 "parser.c"
        break;
      case 110:
      case 116:
// 1135 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_named_item(NULL, kkmsp[0].minor.kk78, status->scanner_state);
}
// 2779 "parser.c"
        break;
      case 112:
// 1145 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_func_call(kkmsp[-3].minor.kk78, kkmsp[-1].minor.kk78, status->scanner_state);
  kk_destructor(27,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[0].minor);
}
// 2788 "parser.c"
        break;
      case 113:
// 1149 "parser.lemon"
{
	kkgotominor.kk78 = phvolt_ret_func_call(kkmsp[-2].minor.kk78, NULL, status->scanner_state);
  kk_destructor(27,&kkmsp[-1].minor);
  kk_destructor(41,&kkmsp[0].minor);
}
// 2797 "parser.c"
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
// 582 "parser.lemon"

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
			snprintf(status->syntax_error, status->syntax_error_len - 1, "Syntax error, unexpected token %s in %s on line %d", token_name, Z_STRVAL_P(status->scanner_state->active_file), status->scanner_state->active_line);
			status->syntax_error[status->syntax_error_len - 1] = '\0';

			if (!token_found) {
				if (token_name) {
					efree(token_name);
				}
			}
		}
	} else {
		status->syntax_error_len = 48 + Z_STRLEN_P(status->scanner_state->active_file);
		status->syntax_error = emalloc(sizeof(char) * status->syntax_error_len);
		snprintf(status->syntax_error, status->syntax_error_len - 1, "Syntax error, unexpected EOF in %s", Z_STRVAL_P(status->scanner_state->active_file));
		status->syntax_error[status->syntax_error_len - 1] = '\0';
	}

	status->status = PHVOLT_PARSING_FAILED;

// 2887 "parser.c"
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
  { PHVOLT_T_CBRACKET_OPEN,  	"{" },
  { PHVOLT_T_CBRACKET_CLOSE, 	"}" },
  { PHVOLT_T_OPEN_DELIMITER, 	"{%" },
  { PHVOLT_T_CLOSE_DELIMITER, 	"%}" },
  { PHVOLT_T_OPEN_EDELIMITER, 	"{{" },
  { PHVOLT_T_CLOSE_EDELIMITER, 	"}}" },
  { PHVOLT_T_IF,           		"IF" },
  { PHVOLT_T_ELSE,           	"ELSE" },
  { PHVOLT_T_ELSEIF,           	"ELSEIF" },
  { PHVOLT_T_ELSEFOR,           "ELSEFOR" },
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
  { PHVOLT_T_WITH,				"WITH" },
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
	int length;
	phvolt_scanner_state *state = parser_status->scanner_state;

	PHALCON_INIT_VAR(*error_msg);
	if (state->start) {
		error = emalloc(sizeof(char) * 72 + state->start_length +  Z_STRLEN_P(state->active_file));
		if (state->start_length > 16) {
			length = 72 + Z_STRLEN_P(state->active_file);
			error_part = estrndup(state->start, 16);
			snprintf(error, length, "Parsing error before '%s...' in %s on line %d", error_part, Z_STRVAL_P(state->active_file), state->active_line);
			efree(error_part);
		} else {
			length = 48 + state->start_length + Z_STRLEN_P(state->active_file);
			snprintf(error, length, "Parsing error before '%s' in %s on line %d", state->start, Z_STRVAL_P(state->active_file), state->active_line);
		}
	} else {
		error = emalloc(sizeof(char) * (32 + Z_STRLEN_P(state->active_file)));
		length = 32 + Z_STRLEN_P(state->active_file);
		snprintf(error, length, "Parsing error near to EOF in %s", Z_STRVAL_P(state->active_file));
	}

	error[length - 1] = '\0';
	ZVAL_STRING(*error_msg, error, 1);
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

	if (phvolt_internal_parse_view(&result, view_code, template_path, &error_msg TSRMLS_CC) == FAILURE) {
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
	state->macro_level = 0;
	state->start_length = 0;
	state->old_if_level = 0;
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
			case PHVOLT_T_CBRACKET_OPEN:
				phvolt_(phvolt_parser, PHVOLT_CBRACKET_OPEN, NULL, parser_status);
				break;
			case PHVOLT_T_CBRACKET_CLOSE:
				phvolt_(phvolt_parser, PHVOLT_CBRACKET_CLOSE, NULL, parser_status);
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

			case PHVOLT_T_ELSEFOR:
				phvolt_(phvolt_parser, PHVOLT_ELSEFOR, NULL, parser_status);
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
					state->old_if_level = state->if_level;
					state->if_level = 0;
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
				state->if_level = state->old_if_level;
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

			case PHVOLT_T_MACRO:
				if (state->macro_level > 0) {
					phvolt_create_error_msg(parser_status, "Embedding macros into other macros is not allowed");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				} else {
					state->macro_level++;
				}
				phvolt_(phvolt_parser, PHVOLT_MACRO, NULL, parser_status);
				break;
			case PHVOLT_T_ENDMACRO:
				state->macro_level--;
				phvolt_(phvolt_parser, PHVOLT_ENDMACRO, NULL, parser_status);
				break;

			case PHVOLT_T_CALL:
				phvolt_(phvolt_parser, PHVOLT_CALL, NULL, parser_status);
				break;
			case PHVOLT_T_ENDCALL:
				phvolt_(phvolt_parser, PHVOLT_ENDCALL, NULL, parser_status);
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

			case PHVOLT_T_WITH:
				phvolt_(phvolt_parser, PHVOLT_WITH, NULL, parser_status);
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
					snprintf(error, 48 + Z_STRLEN_P(state->active_file) + state->active_line, "Scanner: unknown opcode %d on in %s line %d", token.opcode, Z_STRVAL_P(state->active_file), state->active_line);
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