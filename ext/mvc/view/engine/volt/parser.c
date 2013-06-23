/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 42 "parser.lemon"


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "ext/standard/php_smart_str.h"

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

static zval *phvolt_ret_set_assignment(phvolt_parser_token *variable, int operator, zval *expr, phvolt_scanner_state *state)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 5);

	add_assoc_stringl(ret, "variable", variable->token, variable->token_len, 0);
	efree(variable);

	add_assoc_long(ret, "op", operator);

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


// 553 "parser.c"
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
#define KKNOCODE 112
#define KKACTIONTYPE unsigned short int
#define phvolt_KTOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_KTOKENTYPE kk0;
  zval* kk96;
  int kk223;
} KKMINORTYPE;
#define KKSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = kkpParser->status
#define phvolt_ARG_STORE kkpParser->status = status
#define KKNSTATE 316
#define KKNRULE 129
#define KKERRORSYMBOL 76
#define KKERRSYMDT kk223
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
 /*     0 */    81,   89,  316,   59,   51,   53,   63,   61,   65,   71,
 /*    10 */    73,   75,   77,   67,   69,   47,   45,   49,   42,   39,
 /*    20 */    55,   86,   57,   83,  125,  125,   93,   79,  282,  159,
 /*    30 */    81,   89,  105,   59,   51,   53,   63,   61,   65,   71,
 /*    40 */    73,   75,   77,   67,   69,   47,   45,   49,   42,   39,
 /*    50 */    55,   86,   57,   83,  289,  157,   93,   79,   29,  210,
 /*    60 */    47,   45,   49,   42,   39,   55,   86,   57,   83,  124,
 /*    70 */   194,   93,   79,   86,   57,   83,  249,   31,   93,   79,
 /*    80 */    81,   89,  167,   59,   51,   53,   63,   61,   65,   71,
 /*    90 */    73,   75,   77,   67,   69,   47,   45,   49,   42,   39,
 /*   100 */    55,   86,   57,   83,   35,  109,   93,   79,   84,  220,
 /*   110 */    81,   89,  166,   59,   51,   53,   63,   61,   65,   71,
 /*   120 */    73,   75,   77,   67,   69,   47,   45,   49,   42,   39,
 /*   130 */    55,   86,   57,   83,  165,  180,   93,   79,  298,  293,
 /*   140 */    81,   89,  221,   59,   51,   53,   63,   61,   65,   71,
 /*   150 */    73,   75,   77,   67,   69,   47,   45,   49,   42,   39,
 /*   160 */    55,   86,   57,   83,  263,  281,   93,   79,  112,   25,
 /*   170 */    81,   89,  133,   59,   51,   53,   63,   61,   65,   71,
 /*   180 */    73,   75,   77,   67,   69,   47,   45,   49,   42,   39,
 /*   190 */    55,   86,   57,   83,  228,  243,   93,   79,  128,   38,
 /*   200 */    81,   89,  105,   59,   51,   53,   63,   61,   65,   71,
 /*   210 */    73,   75,   77,   67,   69,   47,   45,   49,   42,   39,
 /*   220 */    55,   86,   57,   83,  134,  425,   93,   79,  138,  426,
 /*   230 */    81,   89,   91,   59,   51,   53,   63,   61,   65,   71,
 /*   240 */    73,   75,   77,   67,   69,   47,   45,   49,   42,   39,
 /*   250 */    55,   86,   57,   83,   24,  140,   93,   79,   42,   39,
 /*   260 */    55,   86,   57,   83,  114,   83,   93,   79,   93,   79,
 /*   270 */    88,  270,  141,  104,   81,   89,  154,   59,   51,   53,
 /*   280 */    63,   61,   65,   71,   73,   75,   77,   67,   69,   47,
 /*   290 */    45,   49,   42,   39,   55,   86,   57,   83,  425,  426,
 /*   300 */    93,   79,  275,  276,  277,  278,  279,  280,  170,  172,
 /*   310 */   174,  176,  178,  156,   37,  163,  264,  169,   99,  168,
 /*   320 */   182,  183,   81,   89,  114,   59,   51,   53,   63,   61,
 /*   330 */    65,   71,   73,   75,   77,   67,   69,   47,   45,   49,
 /*   340 */    42,   39,   55,   86,   57,   83,  185,  189,   93,   79,
 /*   350 */   195,  223,   81,   89,  199,   59,   51,   53,   63,   61,
 /*   360 */    65,   71,   73,   75,   77,   67,   69,   47,   45,   49,
 /*   370 */    42,   39,   55,   86,   57,   83,  202,  203,   93,   79,
 /*   380 */   207,  226,   81,   89,  214,   59,   51,   53,   63,   61,
 /*   390 */    65,   71,   73,   75,   77,   67,   69,   47,   45,   49,
 /*   400 */    42,   39,   55,   86,   57,   83,  216,  217,   93,   79,
 /*   410 */   229,  260,   81,   89,  233,   59,   51,   53,   63,   61,
 /*   420 */    65,   71,   73,   75,   77,   67,   69,   47,   45,   49,
 /*   430 */    42,   39,   55,   86,   57,   83,  235,  240,   93,   79,
 /*   440 */   237,  284,   81,   89,  261,   59,   51,   53,   63,   61,
 /*   450 */    65,   71,   73,   75,   77,   67,   69,   47,   45,   49,
 /*   460 */    42,   39,   55,   86,   57,   83,  244,  248,   93,   79,
 /*   470 */   250,  300,   81,   89,  254,   59,   51,   53,   63,   61,
 /*   480 */    65,   71,   73,   75,   77,   67,   69,   47,   45,   49,
 /*   490 */    42,   39,   55,   86,   57,   83,  257,  259,   93,   79,
 /*   500 */   262,  272,   81,   89,  265,   59,   51,   53,   63,   61,
 /*   510 */    65,   71,   73,   75,   77,   67,   69,   47,   45,   49,
 /*   520 */    42,   39,   55,   86,   57,   83,  269,  271,  192,   79,
 /*   530 */    89,  273,   59,   51,   53,   63,   61,   65,   71,   73,
 /*   540 */    75,   77,   67,   69,   47,   45,   49,   42,   39,   55,
 /*   550 */    86,   57,   83,  274,  288,   93,   79,   59,   51,   53,
 /*   560 */    63,   61,   65,   71,   73,   75,   77,   67,   69,   47,
 /*   570 */    45,   49,   42,   39,   55,   86,   57,   83,  290,  291,
 /*   580 */    93,   79,  313,  446,    1,    2,  242,    4,    5,    6,
 /*   590 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   600 */    17,   18,   19,   20,   21,   51,   53,   63,   61,   65,
 /*   610 */    71,   73,   75,   77,   67,   69,   47,   45,   49,   42,
 /*   620 */    39,   55,   86,   57,   83,  297,  304,   93,   79,   26,
 /*   630 */   242,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   640 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   32,
 /*   650 */   242,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   660 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   63,
 /*   670 */    61,   65,   71,   73,   75,   77,   67,   69,   47,   45,
 /*   680 */    49,   42,   39,   55,   86,   57,   83,  307,  310,   93,
 /*   690 */    79,  160,  242,    4,    5,    6,    7,    8,    9,   10,
 /*   700 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   710 */    21,  186,  242,    4,    5,    6,    7,    8,    9,   10,
 /*   720 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   730 */    21,  196,  242,    4,    5,    6,    7,    8,    9,   10,
 /*   740 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   750 */    21,  204,  242,    4,    5,    6,    7,    8,    9,   10,
 /*   760 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   770 */    21,  211,  242,    4,    5,    6,    7,    8,    9,   10,
 /*   780 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   790 */    21,  230,  242,    4,    5,    6,    7,    8,    9,   10,
 /*   800 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   810 */    21,  245,  242,    4,    5,    6,    7,    8,    9,   10,
 /*   820 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   830 */    21,  251,  242,    4,    5,    6,    7,    8,    9,   10,
 /*   840 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   850 */    21,  266,  242,    4,    5,    6,    7,    8,    9,   10,
 /*   860 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   870 */    21,  285,  242,    4,    5,    6,    7,    8,    9,   10,
 /*   880 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   890 */    21,  294,  242,    4,    5,    6,    7,    8,    9,   10,
 /*   900 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   910 */    21,  301,  242,    4,    5,    6,    7,    8,    9,   10,
 /*   920 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   930 */    21,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   940 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   950 */    23,  200,   28,   30,   36,  153,  155,  317,   22,  164,
 /*   960 */   312,  242,  314,  152,  315,  181,   23,  200,  309,  311,
 /*   970 */    36,  153,  155,  114,  190,  164,  242,  242,  201,  242,
 /*   980 */   208,  181,  215,  218,   22,  224,  227,   87,  234,  236,
 /*   990 */   190,  272,  242,   41,  201,  137,  208,  114,  215,  218,
 /*  1000 */   184,  224,  227,  114,  234,  236,   23,  200,   34,  136,
 /*  1010 */    36,  153,  155,   94,  238,  164,  242,  101,  242,  123,
 /*  1020 */   135,  181,  101,  114,  131,  308,  122,  114,  241,  103,
 /*  1030 */   190,  110,  114,   27,  201,  136,  208,  242,  215,  218,
 /*  1040 */   238,  224,  227,  305,  234,  236,  135,   23,  200,  242,
 /*  1050 */   101,   36,  153,  155,  241,  162,  164,  108,   94,  110,
 /*  1060 */   114,  242,  181,  151,  193,  242,   44,  242,  114,  131,
 /*  1070 */   139,  190,  242,  114,  242,  201,  114,  208,  242,  215,
 /*  1080 */   218,  238,  224,  227,   33,  234,  236,   23,  200,  238,
 /*  1090 */    94,   36,  153,  155,  242,  241,  164,   46,   48,  238,
 /*  1100 */   114,  126,  181,  241,  188,  242,  161,  114,  114,  242,
 /*  1110 */   242,  190,  242,  241,   50,  201,  242,  208,  242,  215,
 /*  1120 */   218,   52,  224,  227,  114,  234,  236,  242,   23,  200,
 /*  1130 */   242,  114,   36,  153,  155,   54,  187,  164,   56,   58,
 /*  1140 */   238,  242,  242,  181,  242,  114,  242,   60,  114,  114,
 /*  1150 */   242,  242,  190,  198,  241,  242,  201,  114,  208,  242,
 /*  1160 */   215,  218,  238,  224,  227,  242,  234,  236,  242,   23,
 /*  1170 */   200,   62,  242,   36,  153,  155,  241,   64,  164,  242,
 /*  1180 */   242,  114,  242,  242,  181,   23,  200,  114,  242,   36,
 /*  1190 */   153,  155,  238,  190,  164,  242,  197,  201,  206,  208,
 /*  1200 */   181,  215,  218,  242,  224,  227,  241,  234,  236,  190,
 /*  1210 */   242,  242,  242,  201,  242,  208,  213,  215,  218,  255,
 /*  1220 */   224,  227,  242,  234,  236,   23,  200,  205,  212,   36,
 /*  1230 */   153,  155,  231,   66,  164,  242,  246,  242,  252,  242,
 /*  1240 */   181,   23,  200,  114,  242,   36,  153,  155,  267,  190,
 /*  1250 */   164,  242,  238,  201,  286,  208,  181,  215,  218,  295,
 /*  1260 */   224,  227,  232,  234,  236,  190,  241,  242,  242,  201,
 /*  1270 */   242,  208,  242,  215,  218,  238,  224,  227,  247,  234,
 /*  1280 */   236,   23,  200,  238,  238,   36,  153,  155,  238,  241,
 /*  1290 */   164,   68,  238,  242,  238,  242,  181,  241,  241,  242,
 /*  1300 */   302,  114,  241,  242,  238,  190,  241,  242,  241,  201,
 /*  1310 */   238,  208,  253,  215,  218,  238,  224,  227,  241,  234,
 /*  1320 */   236,  242,   23,  200,  241,  242,   36,  153,  155,  241,
 /*  1330 */   242,  164,   70,   72,  242,  242,  242,  181,   74,  242,
 /*  1340 */   242,  242,  114,  114,  242,  242,  190,  242,  114,  242,
 /*  1350 */   201,  256,  208,  242,  215,  218,  238,  224,  227,  242,
 /*  1360 */   234,  236,  242,   23,  200,   76,   78,   36,  153,  155,
 /*  1370 */   241,   80,  164,   82,   85,  114,  114,  242,  181,   90,
 /*  1380 */   268,  114,   92,  114,  114,  242,  242,  190,  242,  114,
 /*  1390 */   242,  201,  114,  208,  242,  215,  218,   96,  224,  227,
 /*  1400 */   242,  234,  236,  242,   23,  200,   98,  114,   36,  153,
 /*  1410 */   155,  113,  287,  164,  129,  148,  114,  150,  242,  181,
 /*  1420 */   158,  114,  242,  171,  114,  114,  242,  114,  190,  242,
 /*  1430 */   114,  242,  201,  114,  208,  242,  215,  218,  242,  224,
 /*  1440 */   227,  242,  234,  236,   23,  200,  173,  242,   36,  153,
 /*  1450 */   155,  175,  296,  164,  177,  179,  114,  191,  242,  181,
 /*  1460 */   209,  114,  242,  219,  114,  114,  242,  114,  190,  242,
 /*  1470 */   114,  222,  201,  114,  208,  242,  215,  218,  242,  224,
 /*  1480 */   227,  114,  234,  236,   23,  200,  242,  225,   36,  153,
 /*  1490 */   155,  242,  303,  164,  242,  242,  242,  114,  242,  181,
 /*  1500 */    23,  200,  306,  242,   36,  153,  155,  242,  190,  164,
 /*  1510 */   242,  239,  201,  242,  208,  181,  215,  218,  242,  224,
 /*  1520 */   227,  114,  234,  236,  190,  242,  242,  283,  201,  242,
 /*  1530 */   208,  242,  215,  218,  242,  224,  227,  114,  234,  236,
 /*  1540 */    23,  200,  292,  299,   36,  153,  155,  242,  242,  164,
 /*  1550 */   242,  242,  114,  114,  242,  181,  242,  242,  242,  242,
 /*  1560 */   242,  242,  242,  242,  190,  242,  242,  242,  201,  242,
 /*  1570 */   208,  242,  215,  218,  242,  224,  227,  242,  234,  236,
 /*  1580 */   242,  242,  242,  242,  149,  242,   43,   40,  242,  100,
 /*  1590 */   242,   95,  242,  242,   97,  242,  242,  242,  242,  242,
 /*  1600 */   242,  242,  242,  115,  242,  242,  242,  242,  242,  242,
 /*  1610 */   242,  242,  242,  242,  116,  117,  118,  119,  120,  121,
 /*  1620 */   242,  242,  147,  242,  242,   43,   40,  242,  100,  242,
 /*  1630 */    95,  242,  242,   97,  242,  242,  242,  242,  242,  106,
 /*  1640 */   242,  242,  115,  242,   43,   40,  242,  100,  242,  144,
 /*  1650 */   242,  242,   97,  116,  117,  118,  119,  120,  121,  242,
 /*  1660 */   242,  115,  242,  132,  242,  242,  242,  242,  242,  242,
 /*  1670 */   242,  242,  116,  117,  118,  119,  120,  121,  106,   43,
 /*  1680 */    40,  242,  100,  242,   95,  242,  242,   97,  242,  242,
 /*  1690 */   242,  242,  242,  242,  242,  146,  143,  106,   43,   40,
 /*  1700 */   242,  100,  242,   95,  242,  242,   97,  142,  117,  118,
 /*  1710 */   119,  120,  121,  242,  242,  115,  242,   43,   40,  242,
 /*  1720 */   100,  242,   95,  242,  130,   97,  116,  127,  118,  119,
 /*  1730 */   120,  121,  106,  242,  115,  242,  242,  242,  242,  242,
 /*  1740 */   242,  242,  242,  242,  242,  116,  111,  118,  119,  120,
 /*  1750 */   121,  106,  242,  242,   43,   40,  242,  100,  242,   95,
 /*  1760 */   242,  242,   97,  242,  242,  242,  242,  242,  242,  102,
 /*  1770 */   106,  115,   43,   40,  242,  100,  242,   95,  242,  242,
 /*  1780 */    97,  242,  116,  111,  118,  119,  120,  121,  242,  115,
 /*  1790 */   242,  242,  242,  242,  242,  242,  242,  242,  242,  242,
 /*  1800 */   116,  117,  118,  119,  120,  121,  242,  106,  107,   43,
 /*  1810 */    40,  242,  100,  242,   95,  242,  242,   97,  242,  242,
 /*  1820 */   242,  242,  242,  145,  242,  106,  115,  242,  242,  242,
 /*  1830 */   242,  242,  242,  242,  242,  258,  242,  116,  127,  118,
 /*  1840 */   119,  120,  121,  242,  242,  242,  242,   43,   40,  242,
 /*  1850 */   100,  242,   95,  242,  242,   97,  242,  242,  242,  242,
 /*  1860 */   242,  242,  106,  242,  115,  242,  242,  242,  242,  242,
 /*  1870 */   242,  242,  242,  242,  242,  116,  117,  118,  119,  120,
 /*  1880 */   121,  242,  242,  242,   43,   40,  242,  100,  242,   95,
 /*  1890 */   242,  242,   97,  242,  242,  242,  242,  242,  242,  242,
 /*  1900 */   106,  115,   43,   40,  242,  100,  242,   95,  242,  242,
 /*  1910 */    97,  242,  116,  111,  118,  119,  120,  121,  242,  115,
 /*  1920 */   242,  242,  242,  242,  242,  242,  242,  242,  242,  242,
 /*  1930 */   116,  127,  118,  119,  120,  121,  242,  106,  242,  242,
 /*  1940 */   242,  242,  242,  242,  242,  242,  242,  242,  242,  242,
 /*  1950 */   242,  242,  242,  242,  242,  106,
};
static KKCODETYPE kk_lookahead[] = {
 /*     0 */     3,    4,    0,    6,    7,    8,    9,   10,   11,   12,
 /*    10 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    20 */    23,   24,   25,   26,    2,    2,   29,   30,   31,   32,
 /*    30 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*    40 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    50 */    23,   24,   25,   26,    2,    3,   29,   30,   32,   32,
 /*    60 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   47,
 /*    70 */    47,   29,   30,   24,   25,   26,   49,   32,   29,   30,
 /*    80 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*    90 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   100 */    23,   24,   25,   26,   32,   75,   29,   30,    3,   32,
 /*   110 */     3,    4,   32,    6,    7,    8,    9,   10,   11,   12,
 /*   120 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   130 */    23,   24,   25,   26,  100,  101,   29,   30,   31,   32,
 /*   140 */     3,    4,   65,    6,    7,    8,    9,   10,   11,   12,
 /*   150 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   160 */    23,   24,   25,   26,  102,  103,   29,   30,    5,   32,
 /*   170 */     3,    4,  107,    6,    7,    8,    9,   10,   11,   12,
 /*   180 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   190 */    23,   24,   25,   26,   53,   54,   29,   30,    5,   32,
 /*   200 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*   210 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   220 */    23,   24,   25,   26,   73,   73,   29,   30,    5,   73,
 /*   230 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   240 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   250 */    23,   24,   25,   26,   99,  107,   29,   30,   21,   22,
 /*   260 */    23,   24,   25,   26,  109,   26,   29,   30,   29,   30,
 /*   270 */    73,    2,   73,   73,    3,    4,   32,    6,    7,    8,
 /*   280 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   290 */    19,   20,   21,   22,   23,   24,   25,   26,    5,    5,
 /*   300 */    29,   30,   49,   50,   51,   52,   53,   54,   41,   42,
 /*   310 */    43,   44,   45,   38,   99,   32,   47,   38,   47,  101,
 /*   320 */    38,   29,    3,    4,  109,    6,    7,    8,    9,   10,
 /*   330 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   340 */    21,   22,   23,   24,   25,   26,   32,   32,   29,   30,
 /*   350 */    32,   32,    3,    4,   32,    6,    7,    8,    9,   10,
 /*   360 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   370 */    21,   22,   23,   24,   25,   26,   38,   32,   29,   30,
 /*   380 */    32,   32,    3,    4,   32,    6,    7,    8,    9,   10,
 /*   390 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   400 */    21,   22,   23,   24,   25,   26,   50,   32,   29,   30,
 /*   410 */    32,    1,    3,    4,   32,    6,    7,    8,    9,   10,
 /*   420 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   430 */    21,   22,   23,   24,   25,   26,   32,   58,   29,   30,
 /*   440 */    32,   32,    3,    4,   56,    6,    7,    8,    9,   10,
 /*   450 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   460 */    21,   22,   23,   24,   25,   26,   32,   32,   29,   30,
 /*   470 */    32,   32,    3,    4,   32,    6,    7,    8,    9,   10,
 /*   480 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   490 */    21,   22,   23,   24,   25,   26,   32,   32,   29,   30,
 /*   500 */    32,   38,    3,    4,   32,    6,    7,    8,    9,   10,
 /*   510 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   520 */    21,   22,   23,   24,   25,   26,   32,  103,   29,   30,
 /*   530 */     4,   41,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   540 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   550 */    24,   25,   26,  104,   32,   29,   30,    6,    7,    8,
 /*   560 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   570 */    19,   20,   21,   22,   23,   24,   25,   26,   38,    3,
 /*   580 */    29,   30,    1,   77,   78,   79,   80,   81,   82,   83,
 /*   590 */    84,   85,   86,   87,   88,   89,   90,   91,   92,   93,
 /*   600 */    94,   95,   96,   97,   98,    7,    8,    9,   10,   11,
 /*   610 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   620 */    22,   23,   24,   25,   26,   32,   32,   29,   30,   79,
 /*   630 */    80,   81,   82,   83,   84,   85,   86,   87,   88,   89,
 /*   640 */    90,   91,   92,   93,   94,   95,   96,   97,   98,   79,
 /*   650 */    80,   81,   82,   83,   84,   85,   86,   87,   88,   89,
 /*   660 */    90,   91,   92,   93,   94,   95,   96,   97,   98,    9,
 /*   670 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   680 */    20,   21,   22,   23,   24,   25,   26,   32,   32,   29,
 /*   690 */    30,   79,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   700 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   710 */    98,   79,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   720 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   730 */    98,   79,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   740 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   750 */    98,   79,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   760 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   770 */    98,   79,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   780 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   790 */    98,   79,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   800 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   810 */    98,   79,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   820 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   830 */    98,   79,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   840 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   850 */    98,   79,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   860 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   870 */    98,   79,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   880 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   890 */    98,   79,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   900 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   910 */    98,   79,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   920 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   930 */    98,   80,   81,   82,   83,   84,   85,   86,   87,   88,
 /*   940 */    89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
 /*   950 */    31,   32,   33,   34,   35,   36,   37,    0,    1,   40,
 /*   960 */    32,  111,   33,   99,   32,   46,   31,   32,   33,   34,
 /*   970 */    35,   36,   37,  109,   55,   40,  111,  111,   59,  111,
 /*   980 */    61,   46,   63,   64,    1,   66,   67,   99,   69,   70,
 /*   990 */    55,   38,  111,   99,   59,  107,   61,  109,   63,   64,
 /*  1000 */    47,   66,   67,  109,   69,   70,   31,   32,   33,   38,
 /*  1010 */    35,   36,   37,   99,   57,   40,  111,   99,  111,  105,
 /*  1020 */    49,   46,   99,  109,  110,    1,  108,  109,   71,  106,
 /*  1030 */    55,  108,  109,    1,   59,   38,   61,  111,   63,   64,
 /*  1040 */    57,   66,   67,    1,   69,   70,   49,   31,   32,  111,
 /*  1050 */    99,   35,   36,   37,   71,   39,   40,  106,   99,  108,
 /*  1060 */   109,  111,   46,   99,  105,  111,   99,  111,  109,  110,
 /*  1070 */    73,   55,  111,  109,  111,   59,  109,   61,  111,   63,
 /*  1080 */    64,   57,   66,   67,    1,   69,   70,   31,   32,   57,
 /*  1090 */    99,   35,   36,   37,  111,   71,   40,   99,   99,   57,
 /*  1100 */   109,  110,   46,   71,   48,  111,    1,  109,  109,  111,
 /*  1110 */   111,   55,  111,   71,   99,   59,  111,   61,  111,   63,
 /*  1120 */    64,   99,   66,   67,  109,   69,   70,  111,   31,   32,
 /*  1130 */   111,  109,   35,   36,   37,   99,    1,   40,   99,   99,
 /*  1140 */    57,  111,  111,   46,  111,  109,  111,   99,  109,  109,
 /*  1150 */   111,  111,   55,   56,   71,  111,   59,  109,   61,  111,
 /*  1160 */    63,   64,   57,   66,   67,  111,   69,   70,  111,   31,
 /*  1170 */    32,   99,  111,   35,   36,   37,   71,   99,   40,  111,
 /*  1180 */   111,  109,  111,  111,   46,   31,   32,  109,  111,   35,
 /*  1190 */    36,   37,   57,   55,   40,  111,    1,   59,   60,   61,
 /*  1200 */    46,   63,   64,  111,   66,   67,   71,   69,   70,   55,
 /*  1210 */   111,  111,  111,   59,  111,   61,   62,   63,   64,    1,
 /*  1220 */    66,   67,  111,   69,   70,   31,   32,    1,    1,   35,
 /*  1230 */    36,   37,    1,   99,   40,  111,    1,  111,    1,  111,
 /*  1240 */    46,   31,   32,  109,  111,   35,   36,   37,    1,   55,
 /*  1250 */    40,  111,   57,   59,    1,   61,   46,   63,   64,    1,
 /*  1260 */    66,   67,   68,   69,   70,   55,   71,  111,  111,   59,
 /*  1270 */   111,   61,  111,   63,   64,   57,   66,   67,   68,   69,
 /*  1280 */    70,   31,   32,   57,   57,   35,   36,   37,   57,   71,
 /*  1290 */    40,   99,   57,  111,   57,  111,   46,   71,   71,  111,
 /*  1300 */     1,  109,   71,  111,   57,   55,   71,  111,   71,   59,
 /*  1310 */    57,   61,   62,   63,   64,   57,   66,   67,   71,   69,
 /*  1320 */    70,  111,   31,   32,   71,  111,   35,   36,   37,   71,
 /*  1330 */   111,   40,   99,   99,  111,  111,  111,   46,   99,  111,
 /*  1340 */   111,  111,  109,  109,  111,  111,   55,  111,  109,  111,
 /*  1350 */    59,   60,   61,  111,   63,   64,   57,   66,   67,  111,
 /*  1360 */    69,   70,  111,   31,   32,   99,   99,   35,   36,   37,
 /*  1370 */    71,   99,   40,   99,   99,  109,  109,  111,   46,   99,
 /*  1380 */    48,  109,   99,  109,  109,  111,  111,   55,  111,  109,
 /*  1390 */   111,   59,  109,   61,  111,   63,   64,   99,   66,   67,
 /*  1400 */   111,   69,   70,  111,   31,   32,   99,  109,   35,   36,
 /*  1410 */    37,   99,   39,   40,   99,   99,  109,   99,  111,   46,
 /*  1420 */    99,  109,  111,   99,  109,  109,  111,  109,   55,  111,
 /*  1430 */   109,  111,   59,  109,   61,  111,   63,   64,  111,   66,
 /*  1440 */    67,  111,   69,   70,   31,   32,   99,  111,   35,   36,
 /*  1450 */    37,   99,   39,   40,   99,   99,  109,   99,  111,   46,
 /*  1460 */    99,  109,  111,   99,  109,  109,  111,  109,   55,  111,
 /*  1470 */   109,   99,   59,  109,   61,  111,   63,   64,  111,   66,
 /*  1480 */    67,  109,   69,   70,   31,   32,  111,   99,   35,   36,
 /*  1490 */    37,  111,   39,   40,  111,  111,  111,  109,  111,   46,
 /*  1500 */    31,   32,   33,  111,   35,   36,   37,  111,   55,   40,
 /*  1510 */   111,   99,   59,  111,   61,   46,   63,   64,  111,   66,
 /*  1520 */    67,  109,   69,   70,   55,  111,  111,   99,   59,  111,
 /*  1530 */    61,  111,   63,   64,  111,   66,   67,  109,   69,   70,
 /*  1540 */    31,   32,   99,   99,   35,   36,   37,  111,  111,   40,
 /*  1550 */   111,  111,  109,  109,  111,   46,  111,  111,  111,  111,
 /*  1560 */   111,  111,  111,  111,   55,  111,  111,  111,   59,  111,
 /*  1570 */    61,  111,   63,   64,  111,   66,   67,  111,   69,   70,
 /*  1580 */   111,  111,  111,  111,   19,  111,   21,   22,  111,   24,
 /*  1590 */   111,   26,  111,  111,   29,  111,  111,  111,  111,  111,
 /*  1600 */   111,  111,  111,   38,  111,  111,  111,  111,  111,  111,
 /*  1610 */   111,  111,  111,  111,   49,   50,   51,   52,   53,   54,
 /*  1620 */   111,  111,   18,  111,  111,   21,   22,  111,   24,  111,
 /*  1630 */    26,  111,  111,   29,  111,  111,  111,  111,  111,   74,
 /*  1640 */   111,  111,   38,  111,   21,   22,  111,   24,  111,   26,
 /*  1650 */   111,  111,   29,   49,   50,   51,   52,   53,   54,  111,
 /*  1660 */   111,   38,  111,    5,  111,  111,  111,  111,  111,  111,
 /*  1670 */   111,  111,   49,   50,   51,   52,   53,   54,   74,   21,
 /*  1680 */    22,  111,   24,  111,   26,  111,  111,   29,  111,  111,
 /*  1690 */   111,  111,  111,  111,  111,   72,   38,   74,   21,   22,
 /*  1700 */   111,   24,  111,   26,  111,  111,   29,   49,   50,   51,
 /*  1710 */    52,   53,   54,  111,  111,   38,  111,   21,   22,  111,
 /*  1720 */    24,  111,   26,  111,   47,   29,   49,   50,   51,   52,
 /*  1730 */    53,   54,   74,  111,   38,  111,  111,  111,  111,  111,
 /*  1740 */   111,  111,  111,  111,  111,   49,   50,   51,   52,   53,
 /*  1750 */    54,   74,  111,  111,   21,   22,  111,   24,  111,   26,
 /*  1760 */   111,  111,   29,  111,  111,  111,  111,  111,  111,   73,
 /*  1770 */    74,   38,   21,   22,  111,   24,  111,   26,  111,  111,
 /*  1780 */    29,  111,   49,   50,   51,   52,   53,   54,  111,   38,
 /*  1790 */   111,  111,  111,  111,  111,  111,  111,  111,  111,  111,
 /*  1800 */    49,   50,   51,   52,   53,   54,  111,   74,   75,   21,
 /*  1810 */    22,  111,   24,  111,   26,  111,  111,   29,  111,  111,
 /*  1820 */   111,  111,  111,   72,  111,   74,   38,  111,  111,  111,
 /*  1830 */   111,  111,  111,  111,  111,   47,  111,   49,   50,   51,
 /*  1840 */    52,   53,   54,  111,  111,  111,  111,   21,   22,  111,
 /*  1850 */    24,  111,   26,  111,  111,   29,  111,  111,  111,  111,
 /*  1860 */   111,  111,   74,  111,   38,  111,  111,  111,  111,  111,
 /*  1870 */   111,  111,  111,  111,  111,   49,   50,   51,   52,   53,
 /*  1880 */    54,  111,  111,  111,   21,   22,  111,   24,  111,   26,
 /*  1890 */   111,  111,   29,  111,  111,  111,  111,  111,  111,  111,
 /*  1900 */    74,   38,   21,   22,  111,   24,  111,   26,  111,  111,
 /*  1910 */    29,  111,   49,   50,   51,   52,   53,   54,  111,   38,
 /*  1920 */   111,  111,  111,  111,  111,  111,  111,  111,  111,  111,
 /*  1930 */    49,   50,   51,   52,   53,   54,  111,   74,  111,  111,
 /*  1940 */   111,  111,  111,  111,  111,  111,  111,  111,  111,  111,
 /*  1950 */   111,  111,  111,  111,  111,   74,
};
#define KK_SHIFT_USE_DFLT (-4)
static short kk_shift_ofst[] = {
 /*     0 */   983,    2,  957,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    20 */    -4,   -4, 1509, 1826,  137, 1024, 1032,  919,   26,   -4,
 /*    30 */    45, 1042, 1083,  975,   72,   -4, 1826,  167,   -4, 1826,
 /*    40 */  1826,   49, 1826, 1826,   49, 1565,  237, 1604,  237, 1826,
 /*    50 */   237, 1826,  660, 1826,  660, 1826,   49, 1826,  239, 1826,
 /*    60 */   598, 1826,   42, 1623,   42, 1826,   42, 1826,   42, 1826,
 /*    70 */    42, 1826,   42, 1826,   42, 1826,   42, 1826,   42, 1826,
 /*    80 */    -4, 1826,  526,  105, 1826,  239, 1658,  197,   -4, 1826,
 /*    90 */   227, 1826,  551, 1677,  469, 1826,  239, 1826,  271,   -4,
 /*   100 */  1696,  469,   -4,  200,   -4, 1863, 1733,   -4,   30,   -4,
 /*   110 */    -4,  163, 1826,  469,   -4,   -4,   -4,   -4,   -4,   -4,
 /*   120 */    -4,   -4,   -4,   22,   -4, 1881,   -4,  193, 1826,  469,
 /*   130 */    -4,   -4,  971,  151,   -4,  152,  156,  223,  997,   -4,
 /*   140 */   199,   -4,  293,  294, 1751,   -4,   -4, 1826,  237, 1826,
 /*   150 */   237,   49,   49,  244,   -4,  275,   52, 1826,   -3,  983,
 /*   160 */  1105, 1016,  283,   -4,  279,   80,   -4,  279,   -4,  267,
 /*   170 */  1826,  469, 1826,  469, 1826,  469, 1826,  469, 1826,  469,
 /*   180 */    -4,  282,  292,  953,  314,  983, 1135, 1056,  315,   -4,
 /*   190 */  1826,  499, 1788,   23,  318,  983, 1195, 1097,  322,   -4,
 /*   200 */    -4,  338,  345, 1218, 1226, 1138,  348,   -4, 1826,   27,
 /*   210 */   983, 1227, 1154,  352,   -4,  356,  375,   -4, 1826,   77,
 /*   220 */    -4, 1826,  319,   -4, 1826,  349,   -4,  141,  378,  983,
 /*   230 */  1231, 1194,  382,   -4,  404,   -4,  408,   -4, 1826,  379,
 /*   240 */    -4,   -4,   -4,  434,  983, 1235, 1210,  435,   -4,  438,
 /*   250 */   983, 1237, 1250,  442,   -4, 1291,  464,   -4,  465,  410,
 /*   260 */   388,  468,   -4,  269,  472,  983, 1247, 1332,  494,   -4,
 /*   270 */   463,   -4,  490,  253,   -4,   -4,   -4,   -4,   -4,   -4,
 /*   280 */    -4,   -4, 1826,  409,  983, 1253, 1373,  522,   -4,  540,
 /*   290 */   576, 1826,  107,  983, 1258, 1413,  593,   -4, 1826,  439,
 /*   300 */   983, 1299, 1453,  594,   -4, 1469,  655,   -4,  935,  656,
 /*   310 */    -4,  928,  581,  929,  932,   -4,
};
#define KK_REDUCE_USE_DFLT (-1)
static short kk_reduce_ofst[] = {
 /*     0 */   506,   -1,  851,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*    10 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*    20 */    -1,   -1,   -1,  155,   -1,  550,  851,   -1,   -1,   -1,
 /*    30 */    -1,  570,  851,   -1,   -1,   -1,  215,   -1,   -1,  864,
 /*    40 */   894,   -1,  964,  967,   -1,  998,   -1,  999,   -1, 1015,
 /*    50 */    -1, 1022,   -1, 1036,   -1, 1039,   -1, 1040,   -1, 1048,
 /*    60 */    -1, 1072,   -1, 1078,   -1, 1134,   -1, 1192,   -1, 1233,
 /*    70 */    -1, 1234,   -1, 1239,   -1, 1266,   -1, 1267,   -1, 1272,
 /*    80 */    -1, 1274,   -1,   -1, 1275,   -1,  888,   -1,   -1, 1280,
 /*    90 */    -1, 1283,   -1,  914,   -1, 1298,   -1, 1307,   -1,   -1,
 /*   100 */   923,   -1,   -1,   -1,   -1,  918,  951,   -1,   -1,   -1,
 /*   110 */    -1,   -1, 1312,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   120 */    -1,   -1,   -1,   -1,   -1,  991,   -1,   -1, 1315,   -1,
 /*   130 */    -1,   -1,   65,   -1,   -1,   -1,   -1,   -1,  148,   -1,
 /*   140 */    -1,   -1,   -1,   -1, 1298,   -1,   -1, 1316,   -1, 1318,
 /*   150 */    -1,   -1,   -1,   -1,   -1,   -1,   -1, 1321,   -1,  612,
 /*   160 */   851,   -1,   -1,   -1,   34,   -1,   -1,  218,   -1,   -1,
 /*   170 */  1324,   -1, 1347,   -1, 1352,   -1, 1355,   -1, 1356,   -1,
 /*   180 */    -1,   -1,   -1,   62,   -1,  632,  851,   -1,   -1,   -1,
 /*   190 */  1358,   -1,  959,   -1,   -1,  652,  851,   -1,   -1,   -1,
 /*   200 */    -1,   -1,   -1,  672,  851,   -1,   -1,   -1, 1361,   -1,
 /*   210 */   692,  851,   -1,   -1,   -1,   -1,   -1,   -1, 1364,   -1,
 /*   220 */    -1, 1372,   -1,   -1, 1388,   -1,   -1,   -1,   -1,  712,
 /*   230 */   851,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 1412,   -1,
 /*   240 */    -1,   -1,   -1,   -1,  732,  851,   -1,   -1,   -1,   -1,
 /*   250 */   752,  851,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   260 */    -1,   -1,   -1,   -1,   -1,  772,  851,   -1,   -1,   -1,
 /*   270 */   424,   -1,   -1,  449,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   280 */    -1,   -1, 1428,   -1,  792,  851,   -1,   -1,   -1,   -1,
 /*   290 */    -1, 1443,   -1,  812,  851,   -1,   -1,   -1, 1444,   -1,
 /*   300 */   832,  851,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   310 */    -1,   -1,   -1,   -1,   -1,   -1,
};
static KKACTIONTYPE kk_default[] = {
 /*     0 */   445,  445,  445,  318,  320,  321,  322,  323,  324,  325,
 /*    10 */   326,  327,  328,  329,  330,  331,  332,  333,  334,  335,
 /*    20 */   336,  337,  445,  445,  445,  445,  445,  445,  445,  338,
 /*    30 */   445,  445,  445,  445,  445,  340,  445,  445,  343,  445,
 /*    40 */   445,  386,  445,  445,  387,  445,  390,  445,  392,  445,
 /*    50 */   394,  445,  395,  445,  396,  445,  397,  445,  398,  445,
 /*    60 */   399,  445,  400,  445,  403,  445,  404,  445,  405,  445,
 /*    70 */   406,  445,  407,  445,  408,  445,  409,  445,  410,  445,
 /*    80 */   411,  445,  412,  445,  445,  413,  445,  445,  420,  445,
 /*    90 */   445,  445,  421,  445,  436,  445,  414,  445,  445,  415,
 /*   100 */   445,  430,  416,  445,  417,  445,  445,  418,  445,  419,
 /*   110 */   428,  440,  445,  429,  431,  438,  439,  440,  441,  442,
 /*   120 */   443,  444,  427,  445,  432,  445,  434,  440,  445,  437,
 /*   130 */   433,  435,  445,  445,  422,  445,  445,  445,  445,  423,
 /*   140 */   445,  424,  439,  438,  445,  401,  402,  445,  393,  445,
 /*   150 */   391,  389,  388,  445,  344,  445,  445,  445,  445,  445,
 /*   160 */   445,  445,  445,  345,  445,  445,  349,  445,  350,  445,
 /*   170 */   445,  352,  445,  353,  445,  354,  445,  355,  445,  356,
 /*   180 */   351,  445,  445,  445,  445,  445,  445,  445,  445,  357,
 /*   190 */   445,  445,  445,  445,  432,  445,  445,  445,  445,  369,
 /*   200 */   371,  445,  445,  445,  445,  445,  445,  373,  445,  445,
 /*   210 */   445,  445,  445,  445,  375,  445,  445,  377,  445,  445,
 /*   220 */   378,  445,  445,  379,  445,  445,  380,  445,  445,  445,
 /*   230 */   445,  445,  445,  381,  445,  383,  445,  384,  445,  445,
 /*   240 */   372,  385,  319,  445,  445,  445,  445,  445,  382,  445,
 /*   250 */   445,  445,  445,  445,  376,  445,  445,  374,  433,  445,
 /*   260 */   445,  445,  370,  445,  445,  445,  445,  445,  445,  358,
 /*   270 */   445,  359,  361,  445,  362,  363,  364,  365,  366,  367,
 /*   280 */   368,  360,  445,  445,  445,  445,  445,  445,  346,  445,
 /*   290 */   445,  445,  445,  445,  445,  445,  445,  347,  445,  445,
 /*   300 */   445,  445,  445,  445,  348,  445,  445,  341,  445,  445,
 /*   310 */   339,  445,  445,  445,  445,  342,
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
  "QUESTION",      "COLON",         "RANGE",         "AND",         
  "OR",            "IS",            "EQUALS",        "NOTEQUALS",   
  "LESS",          "GREATER",       "GREATEREQUAL",  "LESSEQUAL",   
  "IDENTICAL",     "NOTIDENTICAL",  "DIVIDE",        "TIMES",       
  "MOD",           "PLUS",          "MINUS",         "CONCAT",      
  "SBRACKET_OPEN",  "PIPE",          "NOT",           "INCR",        
  "DECR",          "PARENTHESES_OPEN",  "DOT",           "IF",          
  "CLOSE_DELIMITER",  "ENDIF",         "ELSE",          "ELSEIF",      
  "ELSEFOR",       "FOR",           "IDENTIFIER",    "ENDFOR",      
  "SET",           "ASSIGN",        "ADD_ASSIGN",    "SUB_ASSIGN",  
  "MUL_ASSIGN",    "DIV_ASSIGN",    "MACRO",         "PARENTHESES_CLOSE",
  "ENDMACRO",      "INTEGER",       "STRING",        "DOUBLE",      
  "NULL",          "FALSE",         "TRUE",          "CALL",        
  "ENDCALL",       "OPEN_EDELIMITER",  "CLOSE_EDELIMITER",  "BLOCK",       
  "ENDBLOCK",      "CACHE",         "ENDCACHE",      "EXTENDS",     
  "INCLUDE",       "WITH",          "DO",            "AUTOESCAPE",  
  "ENDAUTOESCAPE",  "BREAK",         "CONTINUE",      "RAW_FRAGMENT",
  "DEFINED",       "SBRACKET_CLOSE",  "CBRACKET_OPEN",  "CBRACKET_CLOSE",
  "error",         "program",       "volt_language",  "statement_list",
  "statement",     "raw_fragment",  "if_statement",  "elseif_statement",
  "elsefor_statement",  "for_statement",  "set_statement",  "echo_statement",
  "block_statement",  "cache_statement",  "extends_statement",  "include_statement",
  "do_statement",  "autoescape_statement",  "break_statement",  "continue_statement",
  "macro_statement",  "empty_statement",  "macro_call_statement",  "expr",        
  "set_assignments",  "set_assignment",  "macro_parameters",  "macro_parameter",
  "macro_parameter_default",  "argument_list",  "array_list",    "slice_offset",
  "array_item",    "function_call",  "argument_item",
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
 /*  37 */ "set_assignment ::= IDENTIFIER ADD_ASSIGN expr",
 /*  38 */ "set_assignment ::= IDENTIFIER SUB_ASSIGN expr",
 /*  39 */ "set_assignment ::= IDENTIFIER MUL_ASSIGN expr",
 /*  40 */ "set_assignment ::= IDENTIFIER DIV_ASSIGN expr",
 /*  41 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  42 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN macro_parameters PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  43 */ "macro_parameters ::= macro_parameters COMMA macro_parameter",
 /*  44 */ "macro_parameters ::= macro_parameter",
 /*  45 */ "macro_parameter ::= IDENTIFIER",
 /*  46 */ "macro_parameter ::= IDENTIFIER ASSIGN macro_parameter_default",
 /*  47 */ "macro_parameter_default ::= INTEGER",
 /*  48 */ "macro_parameter_default ::= STRING",
 /*  49 */ "macro_parameter_default ::= DOUBLE",
 /*  50 */ "macro_parameter_default ::= NULL",
 /*  51 */ "macro_parameter_default ::= FALSE",
 /*  52 */ "macro_parameter_default ::= TRUE",
 /*  53 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  54 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  55 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  56 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  57 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  58 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  59 */ "cache_statement ::= OPEN_DELIMITER CACHE expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  60 */ "cache_statement ::= OPEN_DELIMITER CACHE expr INTEGER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  61 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  62 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr CLOSE_DELIMITER",
 /*  63 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr WITH expr CLOSE_DELIMITER",
 /*  64 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  65 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE FALSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  66 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE TRUE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  67 */ "break_statement ::= OPEN_DELIMITER BREAK CLOSE_DELIMITER",
 /*  68 */ "continue_statement ::= OPEN_DELIMITER CONTINUE CLOSE_DELIMITER",
 /*  69 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  70 */ "expr ::= MINUS expr",
 /*  71 */ "expr ::= PLUS expr",
 /*  72 */ "expr ::= expr MINUS expr",
 /*  73 */ "expr ::= expr PLUS expr",
 /*  74 */ "expr ::= expr TIMES expr",
 /*  75 */ "expr ::= expr TIMES TIMES expr",
 /*  76 */ "expr ::= expr DIVIDE expr",
 /*  77 */ "expr ::= expr DIVIDE DIVIDE expr",
 /*  78 */ "expr ::= expr MOD expr",
 /*  79 */ "expr ::= expr AND expr",
 /*  80 */ "expr ::= expr OR expr",
 /*  81 */ "expr ::= expr CONCAT expr",
 /*  82 */ "expr ::= expr PIPE expr",
 /*  83 */ "expr ::= expr RANGE expr",
 /*  84 */ "expr ::= expr EQUALS expr",
 /*  85 */ "expr ::= expr IS NOT DEFINED",
 /*  86 */ "expr ::= expr IS DEFINED",
 /*  87 */ "expr ::= expr IS expr",
 /*  88 */ "expr ::= expr NOTEQUALS expr",
 /*  89 */ "expr ::= expr IDENTICAL expr",
 /*  90 */ "expr ::= expr NOTIDENTICAL expr",
 /*  91 */ "expr ::= expr LESS expr",
 /*  92 */ "expr ::= expr GREATER expr",
 /*  93 */ "expr ::= expr GREATEREQUAL expr",
 /*  94 */ "expr ::= expr LESSEQUAL expr",
 /*  95 */ "expr ::= expr DOT expr",
 /*  96 */ "expr ::= expr IN expr",
 /*  97 */ "expr ::= expr NOT IN expr",
 /*  98 */ "expr ::= NOT expr",
 /*  99 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 100 */ "expr ::= SBRACKET_OPEN SBRACKET_CLOSE",
 /* 101 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /* 102 */ "expr ::= CBRACKET_OPEN CBRACKET_CLOSE",
 /* 103 */ "expr ::= CBRACKET_OPEN array_list CBRACKET_CLOSE",
 /* 104 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /* 105 */ "expr ::= expr QUESTION expr COLON expr",
 /* 106 */ "expr ::= expr SBRACKET_OPEN COLON slice_offset SBRACKET_CLOSE",
 /* 107 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON SBRACKET_CLOSE",
 /* 108 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON slice_offset SBRACKET_CLOSE",
 /* 109 */ "slice_offset ::= INTEGER",
 /* 110 */ "slice_offset ::= IDENTIFIER",
 /* 111 */ "array_list ::= array_list COMMA array_item",
 /* 112 */ "array_list ::= array_item",
 /* 113 */ "array_item ::= STRING COLON expr",
 /* 114 */ "array_item ::= expr",
 /* 115 */ "expr ::= function_call",
 /* 116 */ "function_call ::= expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 117 */ "function_call ::= expr PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 118 */ "argument_list ::= argument_list COMMA argument_item",
 /* 119 */ "argument_list ::= argument_item",
 /* 120 */ "argument_item ::= expr",
 /* 121 */ "argument_item ::= STRING COLON expr",
 /* 122 */ "expr ::= IDENTIFIER",
 /* 123 */ "expr ::= INTEGER",
 /* 124 */ "expr ::= STRING",
 /* 125 */ "expr ::= DOUBLE",
 /* 126 */ "expr ::= NULL",
 /* 127 */ "expr ::= FALSE",
 /* 128 */ "expr ::= TRUE",
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
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
// 685 "parser.lemon"
{
	if ((kkpminor->kk0)) {
		if ((kkpminor->kk0)->free_flag) {
			efree((kkpminor->kk0)->token);
		}
		efree((kkpminor->kk0));
	}
}
// 1560 "parser.c"
      break;
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
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
// 702 "parser.lemon"
{ zval_ptr_dtor(&(kkpminor->kk96)); }
// 1595 "parser.c"
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
  { 77, 1 },
  { 78, 1 },
  { 79, 2 },
  { 79, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 82, 8 },
  { 82, 7 },
  { 82, 12 },
  { 82, 11 },
  { 82, 10 },
  { 83, 4 },
  { 84, 3 },
  { 85, 10 },
  { 85, 12 },
  { 85, 12 },
  { 85, 14 },
  { 86, 4 },
  { 100, 3 },
  { 100, 1 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 96, 10 },
  { 96, 11 },
  { 102, 3 },
  { 102, 1 },
  { 103, 1 },
  { 103, 3 },
  { 104, 1 },
  { 104, 1 },
  { 104, 1 },
  { 104, 1 },
  { 104, 1 },
  { 104, 1 },
  { 98, 11 },
  { 98, 9 },
  { 97, 2 },
  { 87, 3 },
  { 88, 8 },
  { 88, 7 },
  { 89, 8 },
  { 89, 9 },
  { 90, 4 },
  { 91, 4 },
  { 91, 6 },
  { 92, 4 },
  { 93, 8 },
  { 93, 8 },
  { 94, 3 },
  { 95, 3 },
  { 81, 1 },
  { 99, 2 },
  { 99, 2 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 4 },
  { 99, 3 },
  { 99, 4 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 4 },
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
  { 99, 2 },
  { 99, 3 },
  { 99, 2 },
  { 99, 3 },
  { 99, 2 },
  { 99, 3 },
  { 99, 4 },
  { 99, 5 },
  { 99, 5 },
  { 99, 5 },
  { 99, 6 },
  { 107, 1 },
  { 107, 1 },
  { 106, 3 },
  { 106, 1 },
  { 108, 3 },
  { 108, 1 },
  { 99, 1 },
  { 109, 4 },
  { 109, 3 },
  { 105, 3 },
  { 105, 1 },
  { 110, 1 },
  { 110, 3 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
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
// 694 "parser.lemon"
{
	status->ret = kkmsp[0].minor.kk96;
}
// 1941 "parser.c"
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
      case 115:
// 698 "parser.lemon"
{
	kkgotominor.kk96 = kkmsp[0].minor.kk96;
}
// 1967 "parser.c"
        break;
      case 2:
// 704 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_zval_list(kkmsp[-1].minor.kk96, kkmsp[0].minor.kk96);
}
// 1974 "parser.c"
        break;
      case 3:
      case 35:
      case 44:
      case 112:
      case 119:
// 708 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_zval_list(NULL, kkmsp[0].minor.kk96);
}
// 1985 "parser.c"
        break;
      case 22:
// 788 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_if_statement(kkmsp[-5].minor.kk96, kkmsp[-3].minor.kk96, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(31,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 1998 "parser.c"
        break;
      case 23:
// 792 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_if_statement(kkmsp[-4].minor.kk96, NULL, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(31,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2011 "parser.c"
        break;
      case 24:
// 796 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_if_statement(kkmsp[-9].minor.kk96, kkmsp[-7].minor.kk96, kkmsp[-3].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(31,&kkmsp[-10].minor);
  kk_destructor(32,&kkmsp[-8].minor);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(34,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2027 "parser.c"
        break;
      case 25:
// 800 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_if_statement(kkmsp[-8].minor.kk96, kkmsp[-6].minor.kk96, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(31,&kkmsp[-9].minor);
  kk_destructor(32,&kkmsp[-7].minor);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(34,&kkmsp[-4].minor);
  kk_destructor(32,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2043 "parser.c"
        break;
      case 26:
// 804 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_if_statement(kkmsp[-7].minor.kk96, NULL, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(31,&kkmsp[-8].minor);
  kk_destructor(32,&kkmsp[-6].minor);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(34,&kkmsp[-4].minor);
  kk_destructor(32,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2059 "parser.c"
        break;
      case 27:
// 810 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_elseif_statement(kkmsp[-1].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(35,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2069 "parser.c"
        break;
      case 28:
// 816 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_elsefor_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(36,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2079 "parser.c"
        break;
      case 29:
// 822 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-5].minor.kk96, NULL, kkmsp[-3].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(37,&kkmsp[-8].minor);
  kk_destructor(3,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2093 "parser.c"
        break;
      case 30:
// 826 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, NULL, kkmsp[-7].minor.kk96, kkmsp[-5].minor.kk96, kkmsp[-3].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(37,&kkmsp[-10].minor);
  kk_destructor(3,&kkmsp[-8].minor);
  kk_destructor(31,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2108 "parser.c"
        break;
      case 31:
// 830 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, kkmsp[-9].minor.kk0, kkmsp[-5].minor.kk96, NULL, kkmsp[-3].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(37,&kkmsp[-10].minor);
  kk_destructor(2,&kkmsp[-8].minor);
  kk_destructor(3,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2123 "parser.c"
        break;
      case 32:
// 834 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, kkmsp[-11].minor.kk0, kkmsp[-7].minor.kk96, kkmsp[-5].minor.kk96, kkmsp[-3].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-13].minor);
  kk_destructor(37,&kkmsp[-12].minor);
  kk_destructor(2,&kkmsp[-10].minor);
  kk_destructor(3,&kkmsp[-8].minor);
  kk_destructor(31,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2139 "parser.c"
        break;
      case 33:
// 840 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_set_statement(kkmsp[-1].minor.kk96);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(40,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2149 "parser.c"
        break;
      case 34:
      case 43:
      case 111:
      case 118:
// 846 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_zval_list(kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96);
  kk_destructor(2,&kkmsp[-1].minor);
}
// 2160 "parser.c"
        break;
      case 36:
// 856 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_ASSIGN, kkmsp[0].minor.kk96, status->scanner_state);
  kk_destructor(41,&kkmsp[-1].minor);
}
// 2168 "parser.c"
        break;
      case 37:
// 860 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_ADD_ASSIGN, kkmsp[0].minor.kk96, status->scanner_state);
  kk_destructor(42,&kkmsp[-1].minor);
}
// 2176 "parser.c"
        break;
      case 38:
// 864 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_SUB_ASSIGN, kkmsp[0].minor.kk96, status->scanner_state);
  kk_destructor(43,&kkmsp[-1].minor);
}
// 2184 "parser.c"
        break;
      case 39:
// 868 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_MUL_ASSIGN, kkmsp[0].minor.kk96, status->scanner_state);
  kk_destructor(44,&kkmsp[-1].minor);
}
// 2192 "parser.c"
        break;
      case 40:
// 872 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_DIV_ASSIGN, kkmsp[0].minor.kk96, status->scanner_state);
  kk_destructor(45,&kkmsp[-1].minor);
}
// 2200 "parser.c"
        break;
      case 41:
// 878 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_macro_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-3].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(46,&kkmsp[-8].minor);
  kk_destructor(29,&kkmsp[-6].minor);
  kk_destructor(47,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(48,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2215 "parser.c"
        break;
      case 42:
// 882 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_macro_statement(kkmsp[-8].minor.kk0, kkmsp[-6].minor.kk96, kkmsp[-3].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(46,&kkmsp[-9].minor);
  kk_destructor(29,&kkmsp[-7].minor);
  kk_destructor(47,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(48,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2230 "parser.c"
        break;
      case 45:
// 898 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_macro_parameter(kkmsp[0].minor.kk0, NULL, status->scanner_state);
}
// 2237 "parser.c"
        break;
      case 46:
// 902 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_macro_parameter(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk96, status->scanner_state);
  kk_destructor(41,&kkmsp[-1].minor);
}
// 2245 "parser.c"
        break;
      case 47:
      case 109:
      case 123:
// 906 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2254 "parser.c"
        break;
      case 48:
      case 124:
// 910 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_literal_zval(PHVOLT_T_STRING, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2262 "parser.c"
        break;
      case 49:
      case 125:
// 914 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2270 "parser.c"
        break;
      case 50:
      case 126:
// 918 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  kk_destructor(52,&kkmsp[0].minor);
}
// 2279 "parser.c"
        break;
      case 51:
      case 127:
// 922 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  kk_destructor(53,&kkmsp[0].minor);
}
// 2288 "parser.c"
        break;
      case 52:
      case 128:
// 926 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  kk_destructor(54,&kkmsp[0].minor);
}
// 2297 "parser.c"
        break;
      case 53:
// 932 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_macro_call_statement(kkmsp[-8].minor.kk96, kkmsp[-6].minor.kk96, kkmsp[-3].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(55,&kkmsp[-9].minor);
  kk_destructor(29,&kkmsp[-7].minor);
  kk_destructor(47,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(56,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2312 "parser.c"
        break;
      case 54:
// 936 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_macro_call_statement(kkmsp[-6].minor.kk96, NULL, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(55,&kkmsp[-7].minor);
  kk_destructor(29,&kkmsp[-5].minor);
  kk_destructor(47,&kkmsp[-4].minor);
  kk_destructor(32,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(56,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2327 "parser.c"
        break;
      case 55:
// 942 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_empty_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2336 "parser.c"
        break;
      case 56:
// 948 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_echo_statement(kkmsp[-1].minor.kk96, status->scanner_state);
  kk_destructor(57,&kkmsp[-2].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
// 2345 "parser.c"
        break;
      case 57:
// 954 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_block_statement(kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(59,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(60,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2358 "parser.c"
        break;
      case 58:
// 958 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_block_statement(kkmsp[-4].minor.kk0, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(59,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(60,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2371 "parser.c"
        break;
      case 59:
// 964 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_cache_statement(kkmsp[-5].minor.kk96, NULL, kkmsp[-3].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(61,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(62,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2384 "parser.c"
        break;
      case 60:
// 968 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_cache_statement(kkmsp[-6].minor.kk96, kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(61,&kkmsp[-7].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(62,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2397 "parser.c"
        break;
      case 61:
// 974 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_extends_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(63,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2407 "parser.c"
        break;
      case 62:
// 980 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_include_statement(kkmsp[-1].minor.kk96, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(64,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2417 "parser.c"
        break;
      case 63:
// 984 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_include_statement(kkmsp[-3].minor.kk96, kkmsp[-1].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(64,&kkmsp[-4].minor);
  kk_destructor(65,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2428 "parser.c"
        break;
      case 64:
// 990 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_do_statement(kkmsp[-1].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(66,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2438 "parser.c"
        break;
      case 65:
// 996 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_autoescape_statement(0, kkmsp[-3].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(67,&kkmsp[-6].minor);
  kk_destructor(53,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(68,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2452 "parser.c"
        break;
      case 66:
// 1000 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_autoescape_statement(1, kkmsp[-3].minor.kk96, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(67,&kkmsp[-6].minor);
  kk_destructor(54,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(68,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2466 "parser.c"
        break;
      case 67:
// 1006 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_break_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(69,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2476 "parser.c"
        break;
      case 68:
// 1012 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_continue_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(70,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
// 2486 "parser.c"
        break;
      case 69:
// 1018 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2493 "parser.c"
        break;
      case 70:
// 1024 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 2501 "parser.c"
        break;
      case 71:
// 1028 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_PLUS, NULL, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
// 2509 "parser.c"
        break;
      case 72:
// 1032 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_SUB, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 2517 "parser.c"
        break;
      case 73:
// 1036 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_ADD, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
// 2525 "parser.c"
        break;
      case 74:
// 1040 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_MUL, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 2533 "parser.c"
        break;
      case 75:
// 1044 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_POW, kkmsp[-3].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(19,&kkmsp[-2].minor);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 2542 "parser.c"
        break;
      case 76:
// 1048 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_DIV, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(18,&kkmsp[-1].minor);
}
// 2550 "parser.c"
        break;
      case 77:
// 1052 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-3].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(18,&kkmsp[-2].minor);
  kk_destructor(18,&kkmsp[-1].minor);
}
// 2559 "parser.c"
        break;
      case 78:
// 1056 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 2567 "parser.c"
        break;
      case 79:
// 1060 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_AND, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
}
// 2575 "parser.c"
        break;
      case 80:
// 1064 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_OR, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(8,&kkmsp[-1].minor);
}
// 2583 "parser.c"
        break;
      case 81:
// 1068 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_CONCAT, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
}
// 2591 "parser.c"
        break;
      case 82:
// 1072 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_PIPE, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(25,&kkmsp[-1].minor);
}
// 2599 "parser.c"
        break;
      case 83:
// 1076 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_RANGE, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-1].minor);
}
// 2607 "parser.c"
        break;
      case 84:
// 1080 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_EQUALS, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
}
// 2615 "parser.c"
        break;
      case 85:
// 1084 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, kkmsp[-3].minor.kk96, NULL, NULL, status->scanner_state);
  kk_destructor(9,&kkmsp[-2].minor);
  kk_destructor(26,&kkmsp[-1].minor);
  kk_destructor(72,&kkmsp[0].minor);
}
// 2625 "parser.c"
        break;
      case 86:
// 1088 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_ISSET, kkmsp[-2].minor.kk96, NULL, NULL, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
  kk_destructor(72,&kkmsp[0].minor);
}
// 2634 "parser.c"
        break;
      case 87:
// 1092 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_IS, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
}
// 2642 "parser.c"
        break;
      case 88:
// 1096 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(11,&kkmsp[-1].minor);
}
// 2650 "parser.c"
        break;
      case 89:
// 1100 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(16,&kkmsp[-1].minor);
}
// 2658 "parser.c"
        break;
      case 90:
// 1104 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(17,&kkmsp[-1].minor);
}
// 2666 "parser.c"
        break;
      case 91:
// 1108 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_LESS, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(12,&kkmsp[-1].minor);
}
// 2674 "parser.c"
        break;
      case 92:
// 1112 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_GREATER, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(13,&kkmsp[-1].minor);
}
// 2682 "parser.c"
        break;
      case 93:
// 1116 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(14,&kkmsp[-1].minor);
}
// 2690 "parser.c"
        break;
      case 94:
// 1120 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(15,&kkmsp[-1].minor);
}
// 2698 "parser.c"
        break;
      case 95:
// 1124 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_DOT, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(30,&kkmsp[-1].minor);
}
// 2706 "parser.c"
        break;
      case 96:
// 1128 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_IN, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(3,&kkmsp[-1].minor);
}
// 2714 "parser.c"
        break;
      case 97:
// 1132 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_NOT_IN, kkmsp[-3].minor.kk96, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(3,&kkmsp[-1].minor);
}
// 2723 "parser.c"
        break;
      case 98:
// 1136 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, kkmsp[0].minor.kk96, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-1].minor);
}
// 2731 "parser.c"
        break;
      case 99:
// 1140 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, kkmsp[-1].minor.kk96, NULL, NULL, status->scanner_state);
  kk_destructor(29,&kkmsp[-2].minor);
  kk_destructor(47,&kkmsp[0].minor);
}
// 2740 "parser.c"
        break;
      case 100:
// 1144 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-1].minor);
  kk_destructor(73,&kkmsp[0].minor);
}
// 2749 "parser.c"
        break;
      case 101:
// 1148 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk96, NULL, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-2].minor);
  kk_destructor(73,&kkmsp[0].minor);
}
// 2758 "parser.c"
        break;
      case 102:
// 1152 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  kk_destructor(74,&kkmsp[-1].minor);
  kk_destructor(75,&kkmsp[0].minor);
}
// 2767 "parser.c"
        break;
      case 103:
// 1156 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk96, NULL, NULL, status->scanner_state);
  kk_destructor(74,&kkmsp[-2].minor);
  kk_destructor(75,&kkmsp[0].minor);
}
// 2776 "parser.c"
        break;
      case 104:
// 1160 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, kkmsp[-3].minor.kk96, kkmsp[-1].minor.kk96, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-2].minor);
  kk_destructor(73,&kkmsp[0].minor);
}
// 2785 "parser.c"
        break;
      case 105:
// 1164 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_expr(PHVOLT_T_TERNARY, kkmsp[-2].minor.kk96, kkmsp[0].minor.kk96, kkmsp[-4].minor.kk96, status->scanner_state);
  kk_destructor(4,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 2794 "parser.c"
        break;
      case 106:
// 1168 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_slice(kkmsp[-4].minor.kk96, NULL, kkmsp[-1].minor.kk96, status->scanner_state);
  kk_destructor(24,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-2].minor);
  kk_destructor(73,&kkmsp[0].minor);
}
// 2804 "parser.c"
        break;
      case 107:
// 1172 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_slice(kkmsp[-4].minor.kk96, kkmsp[-2].minor.kk96, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-1].minor);
  kk_destructor(73,&kkmsp[0].minor);
}
// 2814 "parser.c"
        break;
      case 108:
// 1176 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_slice(kkmsp[-5].minor.kk96, kkmsp[-3].minor.kk96, kkmsp[-1].minor.kk96, status->scanner_state);
  kk_destructor(24,&kkmsp[-4].minor);
  kk_destructor(5,&kkmsp[-2].minor);
  kk_destructor(73,&kkmsp[0].minor);
}
// 2824 "parser.c"
        break;
      case 110:
      case 122:
// 1186 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2832 "parser.c"
        break;
      case 113:
      case 121:
// 1202 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_named_item(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk96, status->scanner_state);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 2841 "parser.c"
        break;
      case 114:
      case 120:
// 1206 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_named_item(NULL, kkmsp[0].minor.kk96, status->scanner_state);
}
// 2849 "parser.c"
        break;
      case 116:
// 1216 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_func_call(kkmsp[-3].minor.kk96, kkmsp[-1].minor.kk96, status->scanner_state);
  kk_destructor(29,&kkmsp[-2].minor);
  kk_destructor(47,&kkmsp[0].minor);
}
// 2858 "parser.c"
        break;
      case 117:
// 1220 "parser.lemon"
{
	kkgotominor.kk96 = phvolt_ret_func_call(kkmsp[-2].minor.kk96, NULL, status->scanner_state);
  kk_destructor(29,&kkmsp[-1].minor);
  kk_destructor(47,&kkmsp[0].minor);
}
// 2867 "parser.c"
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
// 587 "parser.lemon"

	{

		smart_str error_str = {0};

		char *token_name = NULL;
		const phvolt_token_names *tokens = phvolt_tokens;
		int token_len = 0;
		int active_token = status->scanner_state->active_token;

		if (status->scanner_state->start_length) {

			if (active_token) {

				do {
					if (tokens->code == active_token) {
						token_name = tokens->name;
						token_len = tokens->len;
						break;
					}
					++tokens;
				} while (tokens[0].code != 0);

			}

			smart_str_appendl(&error_str, "Syntax error, unexpected token ", sizeof("Syntax error, unexpected token ") - 1);
			if (!token_name) {
				smart_str_appendl(&error_str, "UNKNOWN", sizeof("UNKNOWN") - 1);
			} else {
				smart_str_appendl(&error_str, token_name, token_len);
			}
			if (status->token->value) {
				smart_str_appendc(&error_str, '(');
				smart_str_appendl(&error_str, status->token->value, status->token->len);
				smart_str_appendc(&error_str, ')');
			}
			smart_str_appendl(&error_str, " in ", sizeof(" in ") - 1);
			smart_str_appendl(&error_str, Z_STRVAL_P(status->scanner_state->active_file), Z_STRLEN_P(status->scanner_state->active_file));
			smart_str_appendl(&error_str, " on line ", sizeof(" on line ") - 1);
			{
				char stmp[MAX_LENGTH_OF_LONG + 1];
				int str_len;
				str_len = slprintf(stmp, sizeof(stmp), "%ld", status->scanner_state->active_line);
				smart_str_appendl(&error_str, stmp, str_len);
			}

		} else {

			smart_str_appendl(&error_str, "Syntax error, unexpected EOF in ", sizeof("Syntax error, unexpected EOF in ") - 1);
			smart_str_appendl(&error_str, Z_STRVAL_P(status->scanner_state->active_file), Z_STRLEN_P(status->scanner_state->active_file));

			/* Report unclosed 'if' blocks */
			if ((status->scanner_state->if_level + status->scanner_state->old_if_level) > 0) {
				if ((status->scanner_state->if_level + status->scanner_state->old_if_level) == 1) {
					smart_str_appendl(&error_str, ", there is one 'if' block without close", sizeof(", there is one 'if' block without close") - 1);
				} else {
					smart_str_appendl(&error_str, ", there are ", sizeof(", there are ") - 1);
					{
						char stmp[MAX_LENGTH_OF_LONG + 1];
						int str_len;
						str_len = slprintf(stmp, sizeof(stmp), "%ld", status->scanner_state->if_level + status->scanner_state->old_if_level);
						smart_str_appendl(&error_str, stmp, str_len);
					}
					smart_str_appendl(&error_str, " 'if' blocks without close", sizeof(" 'if' blocks without close") - 1);
				}
			}

			/* Report unclosed 'for' blocks */
			if (status->scanner_state->for_level > 0) {
				if (status->scanner_state->for_level == 1) {
					smart_str_appendl(&error_str, ", there is one 'for' block without close", sizeof(", there is one 'for' block without close") - 1);
				} else {
					smart_str_appendl(&error_str, ", there are ", sizeof(", there are ") - 1);
					{
						char stmp[MAX_LENGTH_OF_LONG + 1];
						int str_len;
						str_len = slprintf(stmp, sizeof(stmp), "%ld", status->scanner_state->if_level);
						smart_str_appendl(&error_str, stmp, str_len);
					}
					smart_str_appendl(&error_str, " 'for' blocks without close", sizeof(" 'for' blocks without close") - 1);
				}
			}
		}

		smart_str_0(&error_str);

		if (error_str.len) {
			status->syntax_error = error_str.c;
			status->syntax_error_len = error_str.len;
		} else {
			status->syntax_error = NULL;
		}

	}

	status->status = PHVOLT_PARSING_FAILED;

// 3007 "parser.c"
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
  { PHVOLT_T_INTEGER,       	SL("INTEGER") },
  { PHVOLT_T_DOUBLE,        	SL("DOUBLE") },
  { PHVOLT_T_STRING,        	SL("STRING") },
  { PHVOLT_T_IDENTIFIER,    	SL("IDENTIFIER") },
  { PHVOLT_T_MINUS,         	SL("MINUS") },
  { PHVOLT_T_ADD,           	SL("+") },
  { PHVOLT_T_SUB,           	SL("-") },
  { PHVOLT_T_MUL,           	SL("*") },
  { PHVOLT_T_DIV,           	SL("/") },
  { PHVOLT_T_MOD,           	SL("%%") },
  { PHVOLT_T_NOT,           	SL("!") },
  { PHVOLT_T_CONCAT,           	SL("~") },
  { PHVOLT_T_AND,           	SL("AND") },
  { PHVOLT_T_OR,            	SL("OR") },
  { PHVOLT_T_DOT,           	SL("DOT") },
  { PHVOLT_T_COMMA,         	SL("COMMA") },
  { PHVOLT_T_EQUALS,        	SL("EQUALS") },
  { PHVOLT_T_NOTEQUALS,     	SL("NOT EQUALS") },
  { PHVOLT_T_IDENTICAL,     	SL("IDENTICAL") },
  { PHVOLT_T_NOTIDENTICAL,  	SL("NOT IDENTICAL") },
  { PHVOLT_T_NOT,           	SL("NOT") },
  { PHVOLT_T_RANGE,           	SL("RANGE") },
  { PHVOLT_T_COLON,       		SL("COLON") },
  { PHVOLT_T_QUESTION,       	SL("QUESTION MARK") },
  { PHVOLT_T_LESS,          	SL("<") },
  { PHVOLT_T_LESSEQUAL,     	SL("<=") },
  { PHVOLT_T_GREATER,       	SL(">") },
  { PHVOLT_T_GREATEREQUAL,  	SL(">=") },
  { PHVOLT_T_PARENTHESES_OPEN,  SL("(") },
  { PHVOLT_T_PARENTHESES_CLOSE, SL(")") },
  { PHVOLT_T_SBRACKET_OPEN,  	SL("[") },
  { PHVOLT_T_SBRACKET_CLOSE, 	SL("]") },
  { PHVOLT_T_CBRACKET_OPEN,  	SL("{") },
  { PHVOLT_T_CBRACKET_CLOSE, 	SL("}") },
  { PHVOLT_T_OPEN_DELIMITER, 	SL("{%") },
  { PHVOLT_T_CLOSE_DELIMITER, 	SL("%}") },
  { PHVOLT_T_OPEN_EDELIMITER, 	SL("{{") },
  { PHVOLT_T_CLOSE_EDELIMITER, 	SL("}}") },
  { PHVOLT_T_IF,           		SL("IF") },
  { PHVOLT_T_ELSE,           	SL("ELSE") },
  { PHVOLT_T_ELSEIF,           	SL("ELSEIF") },
  { PHVOLT_T_ELSEFOR,           SL("ELSEFOR") },
  { PHVOLT_T_ENDIF,           	SL("ENDIF") },
  { PHVOLT_T_FOR,           	SL("FOR") },
  { PHVOLT_T_IN, 	          	SL("IN") },
  { PHVOLT_T_ENDFOR,           	SL("ENDFOR") },
  { PHVOLT_T_SET,           	SL("SET") },
  { PHVOLT_T_ASSIGN,           	SL("ASSIGN") },
  { PHVOLT_T_ADD_ASSIGN,       	SL("+=") },
  { PHVOLT_T_SUB_ASSIGN,       	SL("-=") },
  { PHVOLT_T_MUL_ASSIGN,       	SL("*=") },
  { PHVOLT_T_DIV_ASSIGN,       	SL("/=") },
  { PHVOLT_T_BLOCK,           	SL("BLOCK") },
  { PHVOLT_T_ENDBLOCK,          SL("ENDBLOCK") },
  { PHVOLT_T_CACHE,           	SL("CACHE") },
  { PHVOLT_T_ENDCACHE,        	SL("ENDCACHE") },
  { PHVOLT_T_EXTENDS,			SL("EXTENDS") },
  { PHVOLT_T_IS,				SL("IS") },
  { PHVOLT_T_DEFINED,			SL("DEFINED") },
  { PHVOLT_T_INCLUDE,			SL("INCLUDE") },
  { PHVOLT_T_DO,				SL("DO") },
  { PHVOLT_T_IGNORE,			SL("WHITESPACE") },
  { PHVOLT_T_AUTOESCAPE,		SL("AUTOESCAPE") },
  { PHVOLT_T_ENDAUTOESCAPE,		SL("ENDAUTOESCAPE") },
  { PHVOLT_T_CONTINUE,			SL("CONTINUE") },
  { PHVOLT_T_BREAK,				SL("BREAK") },
  { PHVOLT_T_WITH,				SL("WITH") },
  {  0, NULL, 0 }
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
			snprintf(error, length, "Scanning error before '%s...' in %s on line %d", error_part, Z_STRVAL_P(state->active_file), state->active_line);
			error[length - 1] = '\0';
		} else {
			length = 48 + state->start_length + Z_STRLEN_P(state->active_file);
			snprintf(error, length, "Scanning error before '%s' in %s on line %d", state->start, Z_STRVAL_P(state->active_file), state->active_line);
		}
	} else {
		error = emalloc(sizeof(char) * (32 + Z_STRLEN_P(state->active_file)));
		length = 32 + Z_STRLEN_P(state->active_file);
		snprintf(error, length, "Scanning error near to EOF in %s", Z_STRVAL_P(state->active_file));
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
		phalcon_throw_exception_string(phalcon_mvc_view_exception_ce, SL("View code must be a string"), 1 TSRMLS_CC);
		return FAILURE;
	}

	if (phvolt_internal_parse_view(&result, view_code, template_path, &error_msg TSRMLS_CC) == FAILURE) {
		phalcon_throw_exception_string(phalcon_mvc_view_exception_ce, Z_STRVAL_P(error_msg), Z_STRLEN_P(error_msg), 1 TSRMLS_CC);
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
	parser_status->token = &token;
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

	token.value = NULL;
	token.len = 0;

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
			case PHVOLT_T_ADD_ASSIGN:
				phvolt_(phvolt_parser, PHVOLT_ADD_ASSIGN, NULL, parser_status);
				break;
			case PHVOLT_T_SUB_ASSIGN:
				phvolt_(phvolt_parser, PHVOLT_SUB_ASSIGN, NULL, parser_status);
				break;
			case PHVOLT_T_MUL_ASSIGN:
				phvolt_(phvolt_parser, PHVOLT_MUL_ASSIGN, NULL, parser_status);
				break;
			case PHVOLT_T_DIV_ASSIGN:
				phvolt_(phvolt_parser, PHVOLT_DIV_ASSIGN, NULL, parser_status);
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