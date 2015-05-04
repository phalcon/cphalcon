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
	array_init_size(ret, 5);
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
	array_init_size(ret, 7);
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
	array_init_size(ret, 5);
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
	array_init_size(ret, 4);
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
	array_init_size(ret, 9);
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
	array_init_size(ret, 3);
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
	array_init_size(ret, 6);

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
	array_init_size(ret, 5);

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
	array_init_size(ret, 5);

	add_assoc_long(ret, "type", PHVOLT_T_DO);

	add_assoc_zval(ret, "expr", expr);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_return_statement(zval *expr, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	add_assoc_long(ret, "type", PHVOLT_T_RETURN);

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
	add_assoc_long(ret, "type", PHVOLT_T_EMPTY_STATEMENT);

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


// 570 "parser.c"
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
**    VVCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    VVNOCODE           is a number of type VVCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    VVFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    VVACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    phvolt_TOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    VVMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is phvolt_TOKENTYPE.  The entry in the union
**                       for base tokens is called "vv0".
**    VVSTACKDEPTH       is the maximum depth of the parser's stack.
**    phvolt_ARG_SDECL     A static variable declaration for the %extra_argument
**    phvolt_ARG_PDECL     A parameter declaration for the %extra_argument
**    phvolt_ARG_STORE     Code to store %extra_argument into vvpParser
**    phvolt_ARG_FETCH     Code to extract %extra_argument from vvpParser
**    VVNSTATE           the combined number of states.
**    VVNRULE            the number of rules in the grammar
**    VVERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define VVCODETYPE unsigned char
#define VVNOCODE 120
#define VVACTIONTYPE unsigned short int
#define phvolt_TOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_TOKENTYPE vv0;
  zval* vv92;
  int vv239;
} VVMINORTYPE;
#define VVSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = vvpParser->status
#define phvolt_ARG_STORE vvpParser->status = status
#define VVNSTATE 333
#define VVNRULE 145
#define VVERRORSYMBOL 83
#define VVERRSYMDT vv239
#define VV_NO_ACTION      (VVNSTATE+VVNRULE+2)
#define VV_ACCEPT_ACTION  (VVNSTATE+VVNRULE+1)
#define VV_ERROR_ACTION   (VVNSTATE+VVNRULE)

/* Next are that tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < VVNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   VVNSTATE <= N < VVNSTATE+VVNRULE   Reduce by rule N-VVNSTATE.
**
**   N == VVNSTATE+VVNRULE              A syntax error has occurred.
**
**   N == VVNSTATE+VVNRULE+1            The parser accepts its input.
**
**   N == VVNSTATE+VVNRULE+2            No such action.  Denotes unused
**                                      slots in the vv_action[] table.
**
** The action table is constructed as a single large table named vv_action[].
** Given state S and lookahead X, the action is computed as
**
**      vv_action[ vv_shift_ofst[S] + X ]
**
** If the index value vv_shift_ofst[S]+X is out of range or if the value
** vv_lookahead[vv_shift_ofst[S]+X] is not equal to X or if vv_shift_ofst[S]
** is equal to VV_SHIFT_USE_DFLT, it means that the action is not in the table
** and that vv_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the vv_reduce_ofst[] array is used in place of
** the vv_shift_ofst[] array and VV_REDUCE_USE_DFLT is used in place of
** VV_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  vv_action[]        A single table containing all actions.
**  vv_lookahead[]     A table containing the lookahead for each entry in
**                     vv_action.  Used to detect hash collisions.
**  vv_shift_ofst[]    For each state, the offset into vv_action for
**                     shifting terminals.
**  vv_reduce_ofst[]   For each state, the offset into vv_action for
**                     shifting non-terminals after a reduce.
**  vv_default[]       Default action for each state.
*/
static VVACTIONTYPE vv_action[] = {
 /*     0 */    82,   92,  181,   60,   52,   54,   66,   62,   64,   72,
 /*    10 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*    20 */    56,   89,   58,   84,   87,   88,   96,   80,  315,  310,
 /*    30 */    82,   92,  180,   60,   52,   54,   66,   62,   64,   72,
 /*    40 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*    50 */    56,   89,   58,   84,   87,   88,   96,   80,  299,  173,
 /*    60 */    82,   92,  108,   60,   52,   54,   66,   62,   64,   72,
 /*    70 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*    80 */    56,   89,   58,   84,   87,   88,   96,   80,  213,  234,
 /*    90 */    82,   92,  287,   60,   52,   54,   66,   62,   64,   72,
 /*   100 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   110 */    56,   89,   58,   84,   87,   88,   96,   80,  246,  224,
 /*   120 */   179,  194,  235,   48,   46,   50,   43,   40,   56,   89,
 /*   130 */    58,   84,   87,   88,   96,   80,  266,  281,  245,  260,
 /*   140 */    82,   92,  112,   60,   52,   54,   66,   62,   64,   72,
 /*   150 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   160 */    56,   89,   58,   84,   87,   88,   96,   80,  209,  301,
 /*   170 */    82,   92,  250,   60,   52,   54,   66,   62,   64,   72,
 /*   180 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   190 */    56,   89,   58,   84,   87,   88,   96,   80,  252,  243,
 /*   200 */    82,   92,  254,   60,   52,   54,   66,   62,   64,   72,
 /*   210 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   220 */    56,   89,   58,   84,   87,   88,   96,   80,   92,  136,
 /*   230 */    60,   52,   54,   66,   62,   64,   72,   74,   76,   78,
 /*   240 */    68,   70,   48,   46,   50,   43,   40,   56,   89,   58,
 /*   250 */    84,   87,   88,   96,   80,  257,  108,  280,  298,   82,
 /*   260 */    92,  332,   60,   52,   54,   66,   62,   64,   72,   74,
 /*   270 */    76,   78,   68,   70,   48,   46,   50,   43,   40,   56,
 /*   280 */    89,   58,   84,   87,   88,   96,   80,   82,   92,  261,
 /*   290 */    60,   52,   54,   66,   62,   64,   72,   74,   76,   78,
 /*   300 */    68,   70,   48,   46,   50,   43,   40,   56,   89,   58,
 /*   310 */    84,   87,   88,   96,   80,  131,   26,   43,   40,   56,
 /*   320 */    89,   58,   84,   87,   88,   96,   80,   89,   58,   84,
 /*   330 */    87,   88,   96,   80,  107,  137,   91,  306,  171,  321,
 /*   340 */    82,   92,  458,   60,   52,   54,   66,   62,   64,   72,
 /*   350 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   360 */    56,   89,   58,   84,   87,   88,   96,   80,  267,   39,
 /*   370 */    82,   92,   94,   60,   52,   54,   66,   62,   64,   72,
 /*   380 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   390 */    56,   89,   58,   84,   87,   88,   96,   80,   82,   92,
 /*   400 */   128,   60,   52,   54,   66,   62,   64,   72,   74,   76,
 /*   410 */    78,   68,   70,   48,   46,   50,   43,   40,   56,   89,
 /*   420 */    58,   84,   87,   88,   96,   80,  292,  293,  294,  295,
 /*   430 */   296,  297,  184,  186,  188,  190,  192,   84,   87,   88,
 /*   440 */    96,   80,  102,  459,   30,  127,   82,   92,  203,   60,
 /*   450 */    52,   54,   66,   62,   64,   72,   74,   76,   78,   68,
 /*   460 */    70,   48,   46,   50,   43,   40,   56,   89,   58,   84,
 /*   470 */    87,   88,   96,   80,  265,  317,   82,   92,  199,   60,
 /*   480 */    52,   54,   66,   62,   64,   72,   74,   76,   78,   68,
 /*   490 */    70,   48,   46,   50,   43,   40,   56,   89,   58,   84,
 /*   500 */    87,   88,   96,   80,  271,  237,   82,   92,  274,   60,
 /*   510 */    52,   54,   66,   62,   64,   72,   74,   76,   78,   68,
 /*   520 */    70,   48,   46,   50,   43,   40,   56,   89,   58,   84,
 /*   530 */    87,   88,   96,   80,  183,  240,   82,   92,   36,   60,
 /*   540 */    52,   54,   66,   62,   64,   72,   74,   76,   78,   68,
 /*   550 */    70,   48,   46,   50,   43,   40,   56,   89,   58,   84,
 /*   560 */    87,   88,   96,   80,   82,   92,  276,   60,   52,   54,
 /*   570 */    66,   62,   64,   72,   74,   76,   78,   68,   70,   48,
 /*   580 */    46,   50,   43,   40,   56,   89,   58,   84,   87,   88,
 /*   590 */   206,   80,   60,   52,   54,   66,   62,   64,   72,   74,
 /*   600 */    76,   78,   68,   70,   48,   46,   50,   43,   40,   56,
 /*   610 */    89,   58,   84,   87,   88,   96,   80,   52,   54,   66,
 /*   620 */    62,   64,   72,   74,   76,   78,   68,   70,   48,   46,
 /*   630 */    50,   43,   40,   56,   89,   58,   84,   87,   88,   96,
 /*   640 */    80,  479,    1,    2,  259,    4,    5,    6,    7,    8,
 /*   650 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   660 */    19,   20,   21,   22,   66,   62,   64,   72,   74,   76,
 /*   670 */    78,   68,   70,   48,   46,   50,   43,   40,   56,   89,
 /*   680 */    58,   84,   87,   88,   96,   80,  247,  259,    4,    5,
 /*   690 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   700 */    16,   17,   18,   19,   20,   21,   22,  302,  259,    4,
 /*   710 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   720 */    15,   16,   17,   18,   19,   20,   21,   22,  218,  259,
 /*   730 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   740 */    14,   15,   16,   17,   18,   19,   20,   21,   22,  210,
 /*   750 */   259,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   760 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   770 */    27,  259,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   780 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   790 */    22,  225,  259,    4,    5,    6,    7,    8,    9,   10,
 /*   800 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   810 */    21,   22,  311,  259,    4,    5,    6,    7,    8,    9,
 /*   820 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   830 */    20,   21,   22,  268,  259,    4,    5,    6,    7,    8,
 /*   840 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   850 */    19,   20,   21,   22,  262,  259,    4,    5,    6,    7,
 /*   860 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   870 */    18,   19,   20,   21,   22,  200,  259,    4,    5,    6,
 /*   880 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   890 */    17,   18,   19,   20,   21,   22,  283,  259,    4,    5,
 /*   900 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   910 */    16,   17,   18,   19,   20,   21,   22,  318,  259,    4,
 /*   920 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   930 */    15,   16,   17,   18,   19,   20,   21,   22,   33,  259,
 /*   940 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   950 */    14,   15,   16,   17,   18,   19,   20,   21,   22,  174,
 /*   960 */   259,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   970 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   980 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   990 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*  1000 */    44,   41,  141,  103,  128,   98,   59,  277,  100,  143,
 /*  1010 */    44,   41,  104,  103,   97,   98,  117,  118,  100,  111,
 /*  1020 */   126,  113,  117,  278,  117,  134,   34,  118,  119,  120,
 /*  1030 */   121,  122,  123,  124,  303,  239,  177,  104,  119,  120,
 /*  1040 */   121,  122,  123,  124,  106,  117,  113,  117,  144,  208,
 /*  1050 */   279,   90,  147,  148,  149,  150,  151,  152,  153,  140,
 /*  1060 */   109,  117,  154,  155,  156,  157,  158,  159,  160,  282,
 /*  1070 */   109,   24,  214,  326,  328,   37,  167,  169,  334,   23,
 /*  1080 */   178,   97,  255,   97,  324,   23,  195,  207,   65,  197,
 /*  1090 */   255,  117,  134,  117,  129,  204,  196,  258,  117,  215,
 /*  1100 */   458,  222,  286,  229,  232,  258,  238,  241,  244,   23,
 /*  1110 */   251,  253,   24,  214,   29,   31,   37,  167,  169,  104,
 /*  1120 */   201,  178,  459,  223,  316,  289,  139,  195,  125,  117,
 /*  1130 */   289,  288,  139,  117,  117,  255,  204,  138,  290,  198,
 /*  1140 */   215,  255,  222,  138,  229,  232,  291,  238,  241,  244,
 /*  1150 */   258,  251,  253,   24,  214,  323,  258,   37,  167,  169,
 /*  1160 */    45,  269,  178,  242,  168,  255,  327,  312,  195,  300,
 /*  1170 */   117,   85,   61,  117,  142,  329,  255,  204,  305,  117,
 /*  1180 */   258,  215,  117,  222,  308,  229,  232,  219,  238,  241,
 /*  1190 */   244,  258,  251,  253,   24,  214,  172,  170,   37,  167,
 /*  1200 */   169,  330,  320,  178,  221,  165,  117,  307,  115,  195,
 /*  1210 */   333,   53,  230,  216,  182,  117,  228,  255,  204,  217,
 /*  1220 */   266,  117,  215,  255,  222,  231,  229,  232,   32,  238,
 /*  1230 */   241,  244,  258,  251,  253,   24,  214,   49,  258,   37,
 /*  1240 */   167,  169,  132,  255,  178,  205,  314,  117,  331,  266,
 /*  1250 */   195,   73,  117,  266,  266,  117,   67,  266,  258,  204,
 /*  1260 */   212,  117,  266,  215,  266,  222,  117,  229,  232,  226,
 /*  1270 */   238,  241,  244,  272,  251,  253,   24,  214,   42,  266,
 /*  1280 */    37,  167,  169,  266,  176,  178,  266,   81,  117,   38,
 /*  1290 */   266,  195,  266,  266,  266,  309,  266,  117,  266,  117,
 /*  1300 */   204,  266,  266,  266,  215,  117,  222,  266,  229,  232,
 /*  1310 */   319,  238,  241,  244,  211,  251,  253,   24,  214,   35,
 /*  1320 */   266,   37,  167,  169,  266,  255,  178,  266,  266,  255,
 /*  1330 */   266,  266,  195,  266,  266,  266,  266,  266,  187,  266,
 /*  1340 */   258,  204,  266,  266,  258,  215,  322,  222,  117,  229,
 /*  1350 */   232,  248,  238,  241,  244,  284,  251,  253,   24,  214,
 /*  1360 */   266,  266,   37,  167,  169,  266,  255,  178,  101,   83,
 /*  1370 */   255,  266,  266,  195,  193,  266,  266,  266,  117,  117,
 /*  1380 */   266,  258,  204,  266,  117,  258,  215,  220,  222,  266,
 /*  1390 */   229,  232,  263,  238,  241,  244,  325,  251,  253,   24,
 /*  1400 */   214,  266,  255,   37,  167,  169,  266,  255,  178,  266,
 /*  1410 */   266,  255,  266,  175,  195,  266,  266,  258,  266,  266,
 /*  1420 */   266,  266,  258,  204,  266,  266,  258,  215,  273,  222,
 /*  1430 */   266,  229,  232,   28,  238,  241,  244,  191,  251,  253,
 /*  1440 */    24,  214,  266,  266,   37,  167,  169,  117,  255,  178,
 /*  1450 */   266,  266,  255,  266,  266,  195,   75,  266,  266,  266,
 /*  1460 */   266,  266,  266,  258,  204,  266,  117,  258,  215,  255,
 /*  1470 */   222,  270,  229,  232,  266,  238,  241,  244,  189,  251,
 /*  1480 */   253,   24,  214,  266,  258,   37,  167,  169,  117,  255,
 /*  1490 */   178,  266,  166,  185,  266,  266,  195,  266,  266,  266,
 /*  1500 */    47,  266,  117,  117,  258,  204,  266,  266,  266,  215,
 /*  1510 */   117,  222,  227,  229,  232,  164,  238,  241,  244,  266,
 /*  1520 */   251,  253,   24,  214,  266,  117,   37,  167,  169,  266,
 /*  1530 */   304,  178,  266,  266,   69,   77,  266,  195,  266,  266,
 /*  1540 */   266,   86,  266,  116,  117,  117,  204,  266,  266,  266,
 /*  1550 */   215,  117,  222,  117,  229,  232,   95,  238,  241,  244,
 /*  1560 */    71,  251,  253,   24,  214,  266,  117,   37,  167,  169,
 /*  1570 */   117,   63,  178,  266,   55,   93,  233,  266,  195,   79,
 /*  1580 */   285,  117,  266,  266,  117,  117,  117,  204,  266,  117,
 /*  1590 */   266,  215,  266,  222,  266,  229,  232,   57,  238,  241,
 /*  1600 */   244,   99,  251,  253,   24,  214,  266,  117,   37,  167,
 /*  1610 */   169,  117,  256,  178,  266,  266,  266,  236,  266,  195,
 /*  1620 */    51,  202,  117,  162,  266,   25,  266,  117,  204,  266,
 /*  1630 */   117,  266,  215,  117,  222,  117,  229,  232,  266,  238,
 /*  1640 */   241,  244,  266,  251,  253,   24,  214,  266,  266,   37,
 /*  1650 */   167,  169,  266,  266,  178,  266,  266,  266,  266,  266,
 /*  1660 */   195,  266,  266,  266,  266,  266,  266,  266,  266,  204,
 /*  1670 */   266,  266,  266,  215,  266,  222,  266,  229,  232,  266,
 /*  1680 */   238,  241,  244,  264,  251,  253,   24,  214,  266,  266,
 /*  1690 */    37,  167,  169,  266,  266,  178,  266,  266,  266,  266,
 /*  1700 */   266,  195,  266,  266,  266,  266,  266,  266,  266,  266,
 /*  1710 */   204,  266,  266,  266,  215,  266,  222,  266,  229,  232,
 /*  1720 */   266,  238,  241,  244,  249,  251,  253,   24,  214,  266,
 /*  1730 */   266,   37,  167,  169,  266,  313,  178,  266,  266,  266,
 /*  1740 */   266,  266,  195,  266,  266,  266,  266,  266,  266,  266,
 /*  1750 */   266,  204,  266,  266,  266,  215,  266,  222,  266,  229,
 /*  1760 */   232,  266,  238,  241,  244,  266,  251,  253,   24,  214,
 /*  1770 */   266,  266,   37,  167,  169,  266,  266,  178,  266,  266,
 /*  1780 */   266,  266,  266,  195,  266,   44,   41,  266,  103,  266,
 /*  1790 */    98,  266,  204,  100,  266,  266,  215,  266,  222,  266,
 /*  1800 */   229,  232,  118,  238,  241,  244,  266,  251,  253,  266,
 /*  1810 */   266,  266,  266,  119,  114,  121,  122,  123,  124,  266,
 /*  1820 */   266,  266,   44,   41,  266,  103,  266,   98,  266,  266,
 /*  1830 */   100,  266,  266,  266,  266,  266,  266,  266,  266,  118,
 /*  1840 */   266,  266,  266,  266,  266,  109,  110,  266,  133,  266,
 /*  1850 */   119,  130,  121,  122,  123,  124,  135,  266,  266,  266,
 /*  1860 */   266,  266,  266,  266,  266,  266,  266,  266,  266,  266,
 /*  1870 */   266,  266,   44,   41,  266,  103,  266,   98,  266,  266,
 /*  1880 */   100,  266,  109,  266,  266,  266,  266,  266,  266,  146,
 /*  1890 */   266,  266,  266,  266,  266,  266,  266,  266,  266,  266,
 /*  1900 */   145,  120,  121,  122,  123,  124,  266,  266,  161,  266,
 /*  1910 */   266,   44,   41,  266,  103,  266,   98,  266,  266,  100,
 /*  1920 */   266,  266,  266,  266,  266,  266,  266,  266,  118,  266,
 /*  1930 */    44,   41,  109,  103,  266,   98,  266,  266,  100,  119,
 /*  1940 */   120,  121,  122,  123,  124,  266,  266,  118,  266,  266,
 /*  1950 */   266,  266,  266,  266,  266,  266,  266,  266,  119,  114,
 /*  1960 */   121,  122,  123,  124,  266,   44,   41,  266,  103,  266,
 /*  1970 */    98,  109,  266,  100,  266,  266,  266,  266,  266,  266,
 /*  1980 */   266,  266,  118,  266,  266,  266,  266,  266,  266,  105,
 /*  1990 */   109,  275,  266,  119,  130,  121,  122,  123,  124,  266,
 /*  2000 */   266,  266,  163,  266,   44,   41,  266,  103,  266,   98,
 /*  2010 */   266,  266,  100,  266,  266,  266,  266,  266,  266,  266,
 /*  2020 */   266,  118,  266,  266,  266,  109,  266,  266,  266,  266,
 /*  2030 */   266,  266,  119,  120,  121,  122,  123,  124,  266,  266,
 /*  2040 */   266,  266,  266,   44,   41,  266,  103,  266,   98,  266,
 /*  2050 */   266,  100,  266,  266,  266,  266,  266,  266,  266,  266,
 /*  2060 */   118,  266,  266,  266,  109,  266,  266,  266,  266,  266,
 /*  2070 */   266,  119,  114,  121,  122,  123,  124,  266,  266,  266,
 /*  2080 */   266,  266,   44,   41,  266,  103,  266,   98,  266,  266,
 /*  2090 */   100,  266,  266,  266,  266,  266,  266,  266,  266,  118,
 /*  2100 */   266,  266,  266,  109,  266,  266,  266,  266,  266,  266,
 /*  2110 */   119,  120,  121,  122,  123,  124,  266,  266,  266,  266,
 /*  2120 */   266,   44,   41,  266,  103,  266,   98,  266,  266,  100,
 /*  2130 */   266,  266,  266,  266,  266,  266,  266,  266,  118,  266,
 /*  2140 */   266,  266,  109,  266,  266,  266,  266,  266,  266,  119,
 /*  2150 */   130,  121,  122,  123,  124,  266,  266,  266,  266,  266,
 /*  2160 */   266,  266,  266,  266,  266,  266,  266,  266,  266,  266,
 /*  2170 */   266,  266,  266,  266,  266,  266,  266,  266,  266,  266,
 /*  2180 */   266,  109,
};
static VVCODETYPE vv_lookahead[] = {
 /*     0 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*    10 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    20 */    23,   24,   25,   26,   27,   28,   29,   30,   31,   32,
 /*    30 */     3,    4,   32,    6,    7,    8,    9,   10,   11,   12,
 /*    40 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    50 */    23,   24,   25,   26,   27,   28,   29,   30,   31,   32,
 /*    60 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*    70 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    80 */    23,   24,   25,   26,   27,   28,   29,   30,   32,   32,
 /*    90 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*   100 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   110 */    23,   24,   25,   26,   27,   28,   29,   30,   32,   32,
 /*   120 */   108,  109,   65,   18,   19,   20,   21,   22,   23,   24,
 /*   130 */    25,   26,   27,   28,   29,   30,   49,   47,   53,   54,
 /*   140 */     3,    4,   82,    6,    7,    8,    9,   10,   11,   12,
 /*   150 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   160 */    23,   24,   25,   26,   27,   28,   29,   30,   32,   32,
 /*   170 */     3,    4,   32,    6,    7,    8,    9,   10,   11,   12,
 /*   180 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   190 */    23,   24,   25,   26,   27,   28,   29,   30,   32,   32,
 /*   200 */     3,    4,   32,    6,    7,    8,    9,   10,   11,   12,
 /*   210 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   220 */    23,   24,   25,   26,   27,   28,   29,   30,    4,  115,
 /*   230 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   240 */    16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
 /*   250 */    26,   27,   28,   29,   30,   58,    2,  110,  111,    3,
 /*   260 */     4,   32,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   270 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   280 */    24,   25,   26,   27,   28,   29,   30,    3,    4,   32,
 /*   290 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   300 */    16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
 /*   310 */    26,   27,   28,   29,   30,    5,   32,   21,   22,   23,
 /*   320 */    24,   25,   26,   27,   28,   29,   30,   24,   25,   26,
 /*   330 */    27,   28,   29,   30,   80,   80,   80,    2,    3,   32,
 /*   340 */     3,    4,   80,    6,    7,    8,    9,   10,   11,   12,
 /*   350 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   360 */    23,   24,   25,   26,   27,   28,   29,   30,   32,   32,
 /*   370 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   380 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   390 */    23,   24,   25,   26,   27,   28,   29,   30,    3,    4,
 /*   400 */     2,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   410 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   420 */    25,   26,   27,   28,   29,   30,   49,   50,   51,   52,
 /*   430 */    53,   54,   41,   42,   43,   44,   45,   26,   27,   28,
 /*   440 */    29,   30,   47,   80,   32,   47,    3,    4,   32,    6,
 /*   450 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   460 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   470 */    27,   28,   29,   30,   32,   32,    3,    4,   32,    6,
 /*   480 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   490 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   500 */    27,   28,   29,   30,   32,   32,    3,    4,   32,    6,
 /*   510 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   520 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   530 */    27,   28,   29,   30,   38,   32,    3,    4,   32,    6,
 /*   540 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   550 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   560 */    27,   28,   29,   30,    3,    4,   32,    6,    7,    8,
 /*   570 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   580 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   590 */    29,   30,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   600 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   610 */    24,   25,   26,   27,   28,   29,   30,    7,    8,    9,
 /*   620 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   630 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   640 */    30,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   650 */    93,   94,   95,   96,   97,   98,   99,  100,  101,  102,
 /*   660 */   103,  104,  105,  106,    9,   10,   11,   12,   13,   14,
 /*   670 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   680 */    25,   26,   27,   28,   29,   30,   86,   87,   88,   89,
 /*   690 */    90,   91,   92,   93,   94,   95,   96,   97,   98,   99,
 /*   700 */   100,  101,  102,  103,  104,  105,  106,   86,   87,   88,
 /*   710 */    89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
 /*   720 */    99,  100,  101,  102,  103,  104,  105,  106,   86,   87,
 /*   730 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   740 */    98,   99,  100,  101,  102,  103,  104,  105,  106,   86,
 /*   750 */    87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
 /*   760 */    97,   98,   99,  100,  101,  102,  103,  104,  105,  106,
 /*   770 */    86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
 /*   780 */    96,   97,   98,   99,  100,  101,  102,  103,  104,  105,
 /*   790 */   106,   86,   87,   88,   89,   90,   91,   92,   93,   94,
 /*   800 */    95,   96,   97,   98,   99,  100,  101,  102,  103,  104,
 /*   810 */   105,  106,   86,   87,   88,   89,   90,   91,   92,   93,
 /*   820 */    94,   95,   96,   97,   98,   99,  100,  101,  102,  103,
 /*   830 */   104,  105,  106,   86,   87,   88,   89,   90,   91,   92,
 /*   840 */    93,   94,   95,   96,   97,   98,   99,  100,  101,  102,
 /*   850 */   103,  104,  105,  106,   86,   87,   88,   89,   90,   91,
 /*   860 */    92,   93,   94,   95,   96,   97,   98,   99,  100,  101,
 /*   870 */   102,  103,  104,  105,  106,   86,   87,   88,   89,   90,
 /*   880 */    91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
 /*   890 */   101,  102,  103,  104,  105,  106,   86,   87,   88,   89,
 /*   900 */    90,   91,   92,   93,   94,   95,   96,   97,   98,   99,
 /*   910 */   100,  101,  102,  103,  104,  105,  106,   86,   87,   88,
 /*   920 */    89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
 /*   930 */    99,  100,  101,  102,  103,  104,  105,  106,   86,   87,
 /*   940 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   950 */    98,   99,  100,  101,  102,  103,  104,  105,  106,   86,
 /*   960 */    87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
 /*   970 */    97,   98,   99,  100,  101,  102,  103,  104,  105,  106,
 /*   980 */    87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
 /*   990 */    97,   98,   99,  100,  101,  102,  103,  104,  105,  106,
 /*  1000 */    21,   22,    5,   24,    2,   26,  107,    1,   29,  115,
 /*  1010 */    21,   22,  107,   24,  107,   26,  117,   38,   29,  114,
 /*  1020 */   113,  116,  117,   56,  117,  118,    1,   38,   49,   50,
 /*  1030 */    51,   52,   53,   54,    1,  107,   32,  107,   49,   50,
 /*  1040 */    51,   52,   53,   54,  114,  117,  116,  117,   80,   47,
 /*  1050 */    32,  107,   73,   74,   75,   76,   77,   78,   79,  115,
 /*  1060 */    81,  117,   73,   74,   75,   76,   77,   78,   79,   32,
 /*  1070 */    81,   31,   32,   33,   34,   35,   36,   37,    0,    1,
 /*  1080 */    40,  107,   57,  107,   32,    1,   46,  113,  107,   29,
 /*  1090 */    57,  117,  118,  117,  118,   55,   38,   72,  117,   59,
 /*  1100 */     5,   61,   32,   63,   64,   72,   66,   67,   68,    1,
 /*  1110 */    70,   71,   31,   32,   33,   34,   35,   36,   37,  107,
 /*  1120 */     1,   40,    5,  107,  107,   38,   38,   46,  116,  117,
 /*  1130 */    38,  111,   38,  117,  117,   57,   55,   49,   41,   47,
 /*  1140 */    59,   57,   61,   49,   63,   64,  112,   66,   67,   68,
 /*  1150 */    72,   70,   71,   31,   32,   33,   72,   35,   36,   37,
 /*  1160 */   107,    1,   40,  107,   32,   57,   32,    1,   46,  107,
 /*  1170 */   117,    3,  107,  117,   80,   32,   57,   55,   32,  117,
 /*  1180 */    72,   59,  117,   61,    3,   63,   64,    1,   66,   67,
 /*  1190 */    68,   72,   70,   71,   31,   32,  107,   38,   35,   36,
 /*  1200 */    37,    1,   39,   40,   32,  107,  117,   38,    5,   46,
 /*  1210 */     0,  107,   50,   38,  109,  117,   32,   57,   55,   32,
 /*  1220 */   119,  117,   59,   57,   61,   32,   63,   64,   32,   66,
 /*  1230 */    67,   68,   72,   70,   71,   31,   32,  107,   72,   35,
 /*  1240 */    36,   37,  107,   57,   40,  107,   32,  117,   33,  119,
 /*  1250 */    46,  107,  117,  119,  119,  117,  107,  119,   72,   55,
 /*  1260 */    56,  117,  119,   59,  119,   61,  117,   63,   64,    1,
 /*  1270 */    66,   67,   68,    1,   70,   71,   31,   32,  107,  119,
 /*  1280 */    35,   36,   37,  119,   39,   40,  119,  107,  117,  107,
 /*  1290 */   119,   46,  119,  119,  119,  107,  119,  117,  119,  117,
 /*  1300 */    55,  119,  119,  119,   59,  117,   61,  119,   63,   64,
 /*  1310 */     1,   66,   67,   68,    1,   70,   71,   31,   32,   33,
 /*  1320 */   119,   35,   36,   37,  119,   57,   40,  119,  119,   57,
 /*  1330 */   119,  119,   46,  119,  119,  119,  119,  119,  107,  119,
 /*  1340 */    72,   55,  119,  119,   72,   59,    1,   61,  117,   63,
 /*  1350 */    64,    1,   66,   67,   68,    1,   70,   71,   31,   32,
 /*  1360 */   119,  119,   35,   36,   37,  119,   57,   40,  107,  107,
 /*  1370 */    57,  119,  119,   46,  107,  119,  119,  119,  117,  117,
 /*  1380 */   119,   72,   55,  119,  117,   72,   59,   60,   61,  119,
 /*  1390 */    63,   64,    1,   66,   67,   68,    1,   70,   71,   31,
 /*  1400 */    32,  119,   57,   35,   36,   37,  119,   57,   40,  119,
 /*  1410 */   119,   57,  119,    1,   46,  119,  119,   72,  119,  119,
 /*  1420 */   119,  119,   72,   55,  119,  119,   72,   59,   60,   61,
 /*  1430 */   119,   63,   64,    1,   66,   67,   68,  107,   70,   71,
 /*  1440 */    31,   32,  119,  119,   35,   36,   37,  117,   57,   40,
 /*  1450 */   119,  119,   57,  119,  119,   46,  107,  119,  119,  119,
 /*  1460 */   119,  119,  119,   72,   55,  119,  117,   72,   59,   57,
 /*  1470 */    61,   62,   63,   64,  119,   66,   67,   68,  107,   70,
 /*  1480 */    71,   31,   32,  119,   72,   35,   36,   37,  117,   57,
 /*  1490 */    40,  119,  107,  107,  119,  119,   46,  119,  119,  119,
 /*  1500 */   107,  119,  117,  117,   72,   55,  119,  119,  119,   59,
 /*  1510 */   117,   61,   62,   63,   64,  107,   66,   67,   68,  119,
 /*  1520 */    70,   71,   31,   32,  119,  117,   35,   36,   37,  119,
 /*  1530 */    39,   40,  119,  119,  107,  107,  119,   46,  119,  119,
 /*  1540 */   119,  107,  119,  107,  117,  117,   55,  119,  119,  119,
 /*  1550 */    59,  117,   61,  117,   63,   64,  107,   66,   67,   68,
 /*  1560 */   107,   70,   71,   31,   32,  119,  117,   35,   36,   37,
 /*  1570 */   117,  107,   40,  119,  107,  107,  107,  119,   46,  107,
 /*  1580 */    48,  117,  119,  119,  117,  117,  117,   55,  119,  117,
 /*  1590 */   119,   59,  119,   61,  119,   63,   64,  107,   66,   67,
 /*  1600 */    68,  107,   70,   71,   31,   32,  119,  117,   35,   36,
 /*  1610 */    37,  117,  107,   40,  119,  119,  119,  107,  119,   46,
 /*  1620 */   107,   48,  117,  107,  119,  107,  119,  117,   55,  119,
 /*  1630 */   117,  119,   59,  117,   61,  117,   63,   64,  119,   66,
 /*  1640 */    67,   68,  119,   70,   71,   31,   32,  119,  119,   35,
 /*  1650 */    36,   37,  119,  119,   40,  119,  119,  119,  119,  119,
 /*  1660 */    46,  119,  119,  119,  119,  119,  119,  119,  119,   55,
 /*  1670 */   119,  119,  119,   59,  119,   61,  119,   63,   64,  119,
 /*  1680 */    66,   67,   68,   69,   70,   71,   31,   32,  119,  119,
 /*  1690 */    35,   36,   37,  119,  119,   40,  119,  119,  119,  119,
 /*  1700 */   119,   46,  119,  119,  119,  119,  119,  119,  119,  119,
 /*  1710 */    55,  119,  119,  119,   59,  119,   61,  119,   63,   64,
 /*  1720 */   119,   66,   67,   68,   69,   70,   71,   31,   32,  119,
 /*  1730 */   119,   35,   36,   37,  119,   39,   40,  119,  119,  119,
 /*  1740 */   119,  119,   46,  119,  119,  119,  119,  119,  119,  119,
 /*  1750 */   119,   55,  119,  119,  119,   59,  119,   61,  119,   63,
 /*  1760 */    64,  119,   66,   67,   68,  119,   70,   71,   31,   32,
 /*  1770 */   119,  119,   35,   36,   37,  119,  119,   40,  119,  119,
 /*  1780 */   119,  119,  119,   46,  119,   21,   22,  119,   24,  119,
 /*  1790 */    26,  119,   55,   29,  119,  119,   59,  119,   61,  119,
 /*  1800 */    63,   64,   38,   66,   67,   68,  119,   70,   71,  119,
 /*  1810 */   119,  119,  119,   49,   50,   51,   52,   53,   54,  119,
 /*  1820 */   119,  119,   21,   22,  119,   24,  119,   26,  119,  119,
 /*  1830 */    29,  119,  119,  119,  119,  119,  119,  119,  119,   38,
 /*  1840 */   119,  119,  119,  119,  119,   81,   82,  119,   47,  119,
 /*  1850 */    49,   50,   51,   52,   53,   54,    5,  119,  119,  119,
 /*  1860 */   119,  119,  119,  119,  119,  119,  119,  119,  119,  119,
 /*  1870 */   119,  119,   21,   22,  119,   24,  119,   26,  119,  119,
 /*  1880 */    29,  119,   81,  119,  119,  119,  119,  119,  119,   38,
 /*  1890 */   119,  119,  119,  119,  119,  119,  119,  119,  119,  119,
 /*  1900 */    49,   50,   51,   52,   53,   54,  119,  119,   18,  119,
 /*  1910 */   119,   21,   22,  119,   24,  119,   26,  119,  119,   29,
 /*  1920 */   119,  119,  119,  119,  119,  119,  119,  119,   38,  119,
 /*  1930 */    21,   22,   81,   24,  119,   26,  119,  119,   29,   49,
 /*  1940 */    50,   51,   52,   53,   54,  119,  119,   38,  119,  119,
 /*  1950 */   119,  119,  119,  119,  119,  119,  119,  119,   49,   50,
 /*  1960 */    51,   52,   53,   54,  119,   21,   22,  119,   24,  119,
 /*  1970 */    26,   81,  119,   29,  119,  119,  119,  119,  119,  119,
 /*  1980 */   119,  119,   38,  119,  119,  119,  119,  119,  119,   80,
 /*  1990 */    81,   47,  119,   49,   50,   51,   52,   53,   54,  119,
 /*  2000 */   119,  119,   19,  119,   21,   22,  119,   24,  119,   26,
 /*  2010 */   119,  119,   29,  119,  119,  119,  119,  119,  119,  119,
 /*  2020 */   119,   38,  119,  119,  119,   81,  119,  119,  119,  119,
 /*  2030 */   119,  119,   49,   50,   51,   52,   53,   54,  119,  119,
 /*  2040 */   119,  119,  119,   21,   22,  119,   24,  119,   26,  119,
 /*  2050 */   119,   29,  119,  119,  119,  119,  119,  119,  119,  119,
 /*  2060 */    38,  119,  119,  119,   81,  119,  119,  119,  119,  119,
 /*  2070 */   119,   49,   50,   51,   52,   53,   54,  119,  119,  119,
 /*  2080 */   119,  119,   21,   22,  119,   24,  119,   26,  119,  119,
 /*  2090 */    29,  119,  119,  119,  119,  119,  119,  119,  119,   38,
 /*  2100 */   119,  119,  119,   81,  119,  119,  119,  119,  119,  119,
 /*  2110 */    49,   50,   51,   52,   53,   54,  119,  119,  119,  119,
 /*  2120 */   119,   21,   22,  119,   24,  119,   26,  119,  119,   29,
 /*  2130 */   119,  119,  119,  119,  119,  119,  119,  119,   38,  119,
 /*  2140 */   119,  119,   81,  119,  119,  119,  119,  119,  119,   49,
 /*  2150 */    50,   51,   52,   53,   54,  119,  119,  119,  119,  119,
 /*  2160 */   119,  119,  119,  119,  119,  119,  119,  119,  119,  119,
 /*  2170 */   119,  119,  119,  119,  119,  119,  119,  119,  119,  119,
 /*  2180 */   119,   81,
};
#define VV_SHIFT_USE_DFLT (-4)
static short vv_shift_ofst[] = {
 /*     0 */  1084, 1210, 1078,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    20 */    -4,   -4,   -4, 1737, 2061,  284, 1395, 1432, 1081,  412,
 /*    30 */    -4, 1196, 1345, 1025, 1286,  506,   -4, 2061,  337,   -4,
 /*    40 */  2061, 2061,  303, 2061, 2061,  303, 1983,  296, 1890,  296,
 /*    50 */  2061,  296, 2061,  655, 2061,  655, 2061,  303, 2061,  411,
 /*    60 */  2061,  610, 2061,  105,  989,  105,  979,  105, 2061,  105,
 /*    70 */  2061,  105, 2061,  105, 2061,  105, 2061,  105, 2061,  105,
 /*    80 */  2061,   -4, 2061,  224, 1168, 2061,  411,   -4,   -4, 1851,
 /*    90 */   256,   -4, 2061,  367, 2061,  586, 1801,  533, 2061,  411,
 /*   100 */  2061,  395,   -4, 1909,  533,   -4,  254,   -4, 2022, 1764,
 /*   110 */    -4,   60,   -4,   -4, 1203, 2061,  533,   -4,   -4,   -4,
 /*   120 */    -4,   -4,   -4,   -4,   -4,   -4,  398,   -4, 2100,   -4,
 /*   130 */   310, 2061,  533,   -4,   -4, 1088,  255,   -4,  262,  363,
 /*   140 */   997, 1094,   -4,  968,   -4, 1095, 1117,   -4,   -4,   -4,
 /*   150 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*   160 */    -4, 2061,  296, 2061,  296,  303,  303, 1132,   -4, 1159,
 /*   170 */   335, 2061,   27, 1108, 1412, 1245, 1004,   -4,  496,    0,
 /*   180 */    -4,  496,   -4,  391, 2061,  533, 2061,  533, 2061,  533,
 /*   190 */  2061,  533, 2061,  533,   -4, 1058, 1060, 1092,  446, 1108,
 /*   200 */  1119, 1573,  416,   -4, 2061,  561, 1944, 1002,  136, 1084,
 /*   210 */  1313, 1204,   56,   -4,   -4, 1175, 1187, 1272, 1186, 1327,
 /*   220 */  1172,   -4, 2061,   87, 1108, 1268, 1450, 1184,   -4, 1162,
 /*   230 */  1193,   -4, 2061,   57,   -4, 2061,  473,   -4, 2061,  503,
 /*   240 */    -4, 2061,  167,   -4,   85,   86, 1084, 1350, 1655,  140,
 /*   250 */    -4,  166,   -4,  170,   -4, 2061,  197,   -4,   -4,   -4,
 /*   260 */   257, 1084, 1391, 1614,  442,   -4,  336, 1108, 1160, 1409,
 /*   270 */   472,   -4, 1368,  476,   -4,  534, 1006,  967, 1018,   -4,
 /*   280 */    90, 1037, 1084, 1354, 1532, 1070,   -4, 1087,   -4, 1097,
 /*   290 */   377,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4, 2061,
 /*   300 */   137, 1084, 1033, 1491, 1146,   -4, 1169, 1181, 2061,   -3,
 /*   310 */  1108, 1166, 1696, 1214,   -4, 2061,  443, 1084, 1309, 1163,
 /*   320 */   307,   -4, 1122, 1052,   -4, 1040, 1134,   -4, 1143, 1200,
 /*   330 */  1215,  229,   -4,
};
#define VV_REDUCE_USE_DFLT (-1)
static short vv_reduce_ofst[] = {
 /*     0 */   557,   -1,  893,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*    10 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*    20 */    -1,   -1,   -1,   -1, 1518,   -1,  684,  893,   -1,   -1,
 /*    30 */    -1,   -1,  852,  893,   -1,   -1,   -1, 1182,   -1,   -1,
 /*    40 */  1385, 1171,   -1, 1098, 1053,   -1, 1393,   -1, 1130,   -1,
 /*    50 */  1513,   -1, 1104,   -1, 1467,   -1, 1490,   -1,  899,   -1,
 /*    60 */  1065,   -1, 1464,   -1,  981,   -1, 1149,   -1, 1427,   -1,
 /*    70 */  1453,   -1, 1144,   -1, 1349,   -1, 1428,   -1, 1472,   -1,
 /*    80 */  1180,   -1, 1262,   -1,   -1, 1434,   -1,   -1,   -1,  944,
 /*    90 */    -1,   -1, 1468,   -1, 1449,   -1,  907,   -1, 1494,   -1,
 /*   100 */  1261,   -1,   -1,  930,   -1,   -1,   -1,   -1, 1012,  905,
 /*   110 */    -1,   -1,   -1,   -1,   -1, 1436,   -1,   -1,   -1,   -1,
 /*   120 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  976,   -1,
 /*   130 */    -1, 1135,   -1,   -1,   -1,  114,   -1,   -1,   -1,   -1,
 /*   140 */    -1,  894,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   150 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   160 */    -1, 1516,   -1, 1408,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   170 */    -1, 1089,   -1,  873,  893,   -1,   -1,   -1,   12,   -1,
 /*   180 */    -1, 1105,   -1,   -1, 1386,   -1, 1231,   -1, 1371,   -1,
 /*   190 */  1330,   -1, 1267,   -1,   -1,   -1,   -1,  147,   -1,  789,
 /*   200 */   893,   -1,   -1,   -1, 1138,   -1,  974,   -1,   -1,  663,
 /*   210 */   893,   -1,   -1,   -1,   -1,   -1,   -1,  642,  893,   -1,
 /*   220 */    -1,   -1, 1016,   -1,  705,  893,   -1,   -1,   -1,   -1,
 /*   230 */    -1,   -1, 1469,   -1,   -1, 1510,   -1,   -1,  928,   -1,
 /*   240 */    -1, 1056,   -1,   -1,   -1,   -1,  600,  893,   -1,   -1,
 /*   250 */    -1,   -1,   -1,   -1,   -1, 1505,   -1,   -1,   -1,   -1,
 /*   260 */    -1,  768,  893,   -1,   -1,   -1,   -1,  747,  893,   -1,
 /*   270 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   280 */    -1,   -1,  810,  893,   -1,   -1,   -1, 1020,   -1,   -1,
 /*   290 */  1034,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 1062,
 /*   300 */    -1,  621,  893,   -1,   -1,   -1,   -1,   -1, 1188,   -1,
 /*   310 */   726,  893,   -1,   -1,   -1, 1017,   -1,  831,  893,   -1,
 /*   320 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   330 */    -1,   -1,   -1,
};
static VVACTIONTYPE vv_default[] = {
 /*     0 */   478,  478,  478,  335,  337,  338,  339,  340,  341,  342,
 /*    10 */   343,  344,  345,  346,  347,  348,  349,  350,  351,  352,
 /*    20 */   353,  354,  355,  478,  478,  478,  478,  478,  478,  478,
 /*    30 */   356,  478,  478,  478,  478,  478,  358,  478,  478,  361,
 /*    40 */   478,  478,  405,  478,  478,  406,  478,  409,  478,  411,
 /*    50 */   478,  413,  478,  414,  478,  415,  478,  416,  478,  417,
 /*    60 */   478,  418,  478,  419,  478,  435,  478,  434,  478,  436,
 /*    70 */   478,  437,  478,  438,  478,  439,  478,  440,  478,  441,
 /*    80 */   478,  442,  478,  443,  478,  478,  444,  446,  447,  478,
 /*    90 */   478,  453,  478,  478,  478,  454,  478,  469,  478,  445,
 /*   100 */   478,  478,  448,  478,  463,  449,  478,  450,  478,  478,
 /*   110 */   451,  478,  452,  461,  473,  478,  462,  464,  471,  472,
 /*   120 */   473,  474,  475,  476,  477,  460,  478,  465,  478,  467,
 /*   130 */   473,  478,  470,  466,  468,  478,  478,  455,  478,  478,
 /*   140 */   478,  478,  456,  478,  457,  472,  471,  421,  423,  425,
 /*   150 */   427,  429,  431,  433,  420,  422,  424,  426,  428,  430,
 /*   160 */   432,  478,  412,  478,  410,  408,  407,  478,  362,  478,
 /*   170 */   478,  478,  478,  478,  478,  478,  478,  363,  478,  478,
 /*   180 */   367,  478,  368,  478,  478,  370,  478,  371,  478,  372,
 /*   190 */   478,  373,  478,  374,  369,  478,  478,  478,  478,  478,
 /*   200 */   478,  478,  478,  375,  478,  478,  478,  478,  465,  478,
 /*   210 */   478,  478,  478,  387,  389,  478,  478,  478,  478,  478,
 /*   220 */   478,  391,  478,  478,  478,  478,  478,  478,  393,  478,
 /*   230 */   478,  395,  478,  478,  396,  478,  478,  397,  478,  478,
 /*   240 */   398,  478,  478,  399,  478,  478,  478,  478,  478,  478,
 /*   250 */   400,  478,  402,  478,  403,  478,  478,  390,  404,  336,
 /*   260 */   478,  478,  478,  478,  478,  401,  478,  478,  478,  478,
 /*   270 */   478,  394,  478,  478,  392,  466,  478,  478,  478,  388,
 /*   280 */   478,  478,  478,  478,  478,  478,  376,  478,  377,  379,
 /*   290 */   478,  380,  381,  382,  383,  384,  385,  386,  378,  478,
 /*   300 */   478,  478,  478,  478,  478,  364,  478,  478,  478,  478,
 /*   310 */   478,  478,  478,  478,  365,  478,  478,  478,  478,  478,
 /*   320 */   478,  366,  478,  478,  359,  478,  478,  357,  478,  478,
 /*   330 */   478,  478,  360,
};
#define VV_SZ_ACTTAB (sizeof(vv_action)/sizeof(vv_action[0]))

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
#ifdef VVFALLBACK
static const VVCODETYPE vvFallback[] = {
};
#endif /* VVFALLBACK */

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
struct vvStackEntry {
  int stateno;       /* The state-number */
  int major;         /* The major token value.  This is the code
                     ** number for the token at this stack level */
  VVMINORTYPE minor; /* The user-supplied minor token value.  This
                     ** is the value of the token  */
};
typedef struct vvStackEntry vvStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct vvParser {
  int vvidx;                    /* Index of top element in stack */
  int vverrcnt;                 /* Shifts left before out of the error */
  phvolt_ARG_SDECL                /* A place to hold %extra_argument */
  vvStackEntry vvstack[VVSTACKDEPTH];  /* The parser's stack */
};
typedef struct vvParser vvParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *vvTraceFILE = 0;
static char *vvTracePrompt = 0;
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
  vvTraceFILE = TraceFILE;
  vvTracePrompt = zTracePrompt;
  if( vvTraceFILE==0 ) vvTracePrompt = 0;
  else if( vvTracePrompt==0 ) vvTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *vvTokenName[] = { 
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
  "INCLUDE",       "WITH",          "DO",            "RETURN",      
  "AUTOESCAPE",    "ENDAUTOESCAPE",  "BREAK",         "CONTINUE",    
  "RAW_FRAGMENT",  "DEFINED",       "EMPTY",         "EVEN",        
  "ODD",           "NUMERIC",       "SCALAR",        "ITERABLE",    
  "SBRACKET_CLOSE",  "CBRACKET_OPEN",  "CBRACKET_CLOSE",  "error",       
  "program",       "volt_language",  "statement_list",  "statement",   
  "raw_fragment",  "if_statement",  "elseif_statement",  "elsefor_statement",
  "for_statement",  "set_statement",  "echo_statement",  "block_statement",
  "cache_statement",  "extends_statement",  "include_statement",  "do_statement",
  "return_statement",  "autoescape_statement",  "break_statement",  "continue_statement",
  "macro_statement",  "empty_statement",  "macro_call_statement",  "expr",        
  "set_assignments",  "set_assignment",  "macro_parameters",  "macro_parameter",
  "macro_parameter_default",  "argument_list",  "array_list",    "slice_offset",
  "array_item",    "function_call",  "argument_item",
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *vvRuleName[] = {
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
 /*  16 */ "statement ::= return_statement",
 /*  17 */ "statement ::= autoescape_statement",
 /*  18 */ "statement ::= break_statement",
 /*  19 */ "statement ::= continue_statement",
 /*  20 */ "statement ::= macro_statement",
 /*  21 */ "statement ::= empty_statement",
 /*  22 */ "statement ::= macro_call_statement",
 /*  23 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  24 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  25 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  26 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  27 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER OPEN_DELIMITER ELSE CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  28 */ "elseif_statement ::= OPEN_DELIMITER ELSEIF expr CLOSE_DELIMITER",
 /*  29 */ "elsefor_statement ::= OPEN_DELIMITER ELSEFOR CLOSE_DELIMITER",
 /*  30 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  31 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  32 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  33 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  34 */ "set_statement ::= OPEN_DELIMITER SET set_assignments CLOSE_DELIMITER",
 /*  35 */ "set_assignments ::= set_assignments COMMA set_assignment",
 /*  36 */ "set_assignments ::= set_assignment",
 /*  37 */ "set_assignment ::= IDENTIFIER ASSIGN expr",
 /*  38 */ "set_assignment ::= IDENTIFIER ADD_ASSIGN expr",
 /*  39 */ "set_assignment ::= IDENTIFIER SUB_ASSIGN expr",
 /*  40 */ "set_assignment ::= IDENTIFIER MUL_ASSIGN expr",
 /*  41 */ "set_assignment ::= IDENTIFIER DIV_ASSIGN expr",
 /*  42 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  43 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN macro_parameters PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  44 */ "macro_parameters ::= macro_parameters COMMA macro_parameter",
 /*  45 */ "macro_parameters ::= macro_parameter",
 /*  46 */ "macro_parameter ::= IDENTIFIER",
 /*  47 */ "macro_parameter ::= IDENTIFIER ASSIGN macro_parameter_default",
 /*  48 */ "macro_parameter_default ::= INTEGER",
 /*  49 */ "macro_parameter_default ::= STRING",
 /*  50 */ "macro_parameter_default ::= DOUBLE",
 /*  51 */ "macro_parameter_default ::= NULL",
 /*  52 */ "macro_parameter_default ::= FALSE",
 /*  53 */ "macro_parameter_default ::= TRUE",
 /*  54 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  55 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  56 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  57 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  58 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  59 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  60 */ "cache_statement ::= OPEN_DELIMITER CACHE expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  61 */ "cache_statement ::= OPEN_DELIMITER CACHE expr INTEGER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  62 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  63 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr CLOSE_DELIMITER",
 /*  64 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr WITH expr CLOSE_DELIMITER",
 /*  65 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  66 */ "return_statement ::= OPEN_DELIMITER RETURN expr CLOSE_DELIMITER",
 /*  67 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE FALSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  68 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE TRUE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  69 */ "break_statement ::= OPEN_DELIMITER BREAK CLOSE_DELIMITER",
 /*  70 */ "continue_statement ::= OPEN_DELIMITER CONTINUE CLOSE_DELIMITER",
 /*  71 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  72 */ "expr ::= MINUS expr",
 /*  73 */ "expr ::= PLUS expr",
 /*  74 */ "expr ::= expr MINUS expr",
 /*  75 */ "expr ::= expr PLUS expr",
 /*  76 */ "expr ::= expr TIMES expr",
 /*  77 */ "expr ::= expr TIMES TIMES expr",
 /*  78 */ "expr ::= expr DIVIDE expr",
 /*  79 */ "expr ::= expr DIVIDE DIVIDE expr",
 /*  80 */ "expr ::= expr MOD expr",
 /*  81 */ "expr ::= expr AND expr",
 /*  82 */ "expr ::= expr OR expr",
 /*  83 */ "expr ::= expr CONCAT expr",
 /*  84 */ "expr ::= expr PIPE expr",
 /*  85 */ "expr ::= expr RANGE expr",
 /*  86 */ "expr ::= expr EQUALS expr",
 /*  87 */ "expr ::= expr NOTEQUALS DEFINED",
 /*  88 */ "expr ::= expr IS DEFINED",
 /*  89 */ "expr ::= expr NOTEQUALS EMPTY",
 /*  90 */ "expr ::= expr IS EMPTY",
 /*  91 */ "expr ::= expr NOTEQUALS EVEN",
 /*  92 */ "expr ::= expr IS EVEN",
 /*  93 */ "expr ::= expr NOTEQUALS ODD",
 /*  94 */ "expr ::= expr IS ODD",
 /*  95 */ "expr ::= expr NOTEQUALS NUMERIC",
 /*  96 */ "expr ::= expr IS NUMERIC",
 /*  97 */ "expr ::= expr NOTEQUALS SCALAR",
 /*  98 */ "expr ::= expr IS SCALAR",
 /*  99 */ "expr ::= expr NOTEQUALS ITERABLE",
 /* 100 */ "expr ::= expr IS ITERABLE",
 /* 101 */ "expr ::= expr IS expr",
 /* 102 */ "expr ::= expr NOTEQUALS expr",
 /* 103 */ "expr ::= expr IDENTICAL expr",
 /* 104 */ "expr ::= expr NOTIDENTICAL expr",
 /* 105 */ "expr ::= expr LESS expr",
 /* 106 */ "expr ::= expr GREATER expr",
 /* 107 */ "expr ::= expr GREATEREQUAL expr",
 /* 108 */ "expr ::= expr LESSEQUAL expr",
 /* 109 */ "expr ::= expr DOT expr",
 /* 110 */ "expr ::= expr IN expr",
 /* 111 */ "expr ::= expr NOT IN expr",
 /* 112 */ "expr ::= NOT expr",
 /* 113 */ "expr ::= expr INCR",
 /* 114 */ "expr ::= expr DECR",
 /* 115 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 116 */ "expr ::= SBRACKET_OPEN SBRACKET_CLOSE",
 /* 117 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /* 118 */ "expr ::= CBRACKET_OPEN CBRACKET_CLOSE",
 /* 119 */ "expr ::= CBRACKET_OPEN array_list CBRACKET_CLOSE",
 /* 120 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /* 121 */ "expr ::= expr QUESTION expr COLON expr",
 /* 122 */ "expr ::= expr SBRACKET_OPEN COLON slice_offset SBRACKET_CLOSE",
 /* 123 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON SBRACKET_CLOSE",
 /* 124 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON slice_offset SBRACKET_CLOSE",
 /* 125 */ "slice_offset ::= INTEGER",
 /* 126 */ "slice_offset ::= IDENTIFIER",
 /* 127 */ "array_list ::= array_list COMMA array_item",
 /* 128 */ "array_list ::= array_item",
 /* 129 */ "array_item ::= STRING COLON expr",
 /* 130 */ "array_item ::= expr",
 /* 131 */ "expr ::= function_call",
 /* 132 */ "function_call ::= expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 133 */ "function_call ::= expr PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 134 */ "argument_list ::= argument_list COMMA argument_item",
 /* 135 */ "argument_list ::= argument_item",
 /* 136 */ "argument_item ::= expr",
 /* 137 */ "argument_item ::= STRING COLON expr",
 /* 138 */ "expr ::= IDENTIFIER",
 /* 139 */ "expr ::= INTEGER",
 /* 140 */ "expr ::= STRING",
 /* 141 */ "expr ::= DOUBLE",
 /* 142 */ "expr ::= NULL",
 /* 143 */ "expr ::= FALSE",
 /* 144 */ "expr ::= TRUE",
};
#endif /* NDEBUG */

/*
** This function returns the symbolic name associated with a token
** value.
*/
const char *phvolt_TokenName(int tokenType){
#ifndef NDEBUG
  if( tokenType>0 && tokenType<(sizeof(vvTokenName)/sizeof(vvTokenName[0])) ){
    return vvTokenName[tokenType];
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
  vvParser *pParser;
  pParser = (vvParser*)(*mallocProc)( (size_t)sizeof(vvParser) );
  if( pParser ){
    pParser->vvidx = -1;
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "vvmajor" is the symbol code, and "vvpminor" is a pointer to
** the value.
*/
static void vv_destructor(VVCODETYPE vvmajor, VVMINORTYPE *vvpminor){
  switch( vvmajor ){
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
// 702 "parser.lemon"
{
	if ((vvpminor->vv0)) {
		if ((vvpminor->vv0)->free_flag) {
			efree((vvpminor->vv0)->token);
		}
		efree((vvpminor->vv0));
	}
}
// 1654 "parser.c"
      break;
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
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
// 719 "parser.lemon"
{ zval_ptr_dtor(&(vvpminor->vv92)); }
// 1690 "parser.c"
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
static int vv_pop_parser_stack(vvParser *pParser){
  VVCODETYPE vvmajor;
  vvStackEntry *vvtos = &pParser->vvstack[pParser->vvidx];

  if( pParser->vvidx<0 ) return 0;
#ifndef NDEBUG
  if( vvTraceFILE && pParser->vvidx>=0 ){
    fprintf(vvTraceFILE,"%sPopping %s\n",
      vvTracePrompt,
      vvTokenName[vvtos->major]);
  }
#endif
  vvmajor = vvtos->major;
  vv_destructor( vvmajor, &vvtos->minor);
  pParser->vvidx--;
  return vvmajor;
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
  vvParser *pParser = (vvParser*)p;
  if( pParser==0 ) return;
  while( pParser->vvidx>=0 ) vv_pop_parser_stack(pParser);
  (*freeProc)((void*)pParser);
}

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is VVNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return VV_NO_ACTION.
*/
static int vv_find_shift_action(
  vvParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->vvstack[pParser->vvidx].stateno;
 
  /* if( pParser->vvidx<0 ) return VV_NO_ACTION;  */
  i = vv_shift_ofst[stateno];
  if( i==VV_SHIFT_USE_DFLT ){
    return vv_default[stateno];
  }
  if( iLookAhead==VVNOCODE ){
    return VV_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=VV_SZ_ACTTAB || vv_lookahead[i]!=iLookAhead ){
#ifdef VVFALLBACK
    int iFallback;            /* Fallback token */
    if( iLookAhead<sizeof(vvFallback)/sizeof(vvFallback[0])
           && (iFallback = vvFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
      if( vvTraceFILE ){
        fprintf(vvTraceFILE, "%sFALLBACK %s => %s\n",
           vvTracePrompt, vvTokenName[iLookAhead], vvTokenName[iFallback]);
      }
#endif
      return vv_find_shift_action(pParser, iFallback);
    }
#endif
    return vv_default[stateno];
  }else{
    return vv_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is VVNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return VV_NO_ACTION.
*/
static int vv_find_reduce_action(
  vvParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->vvstack[pParser->vvidx].stateno;
 
  i = vv_reduce_ofst[stateno];
  if( i==VV_REDUCE_USE_DFLT ){
    return vv_default[stateno];
  }
  if( iLookAhead==VVNOCODE ){
    return VV_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=VV_SZ_ACTTAB || vv_lookahead[i]!=iLookAhead ){
    return vv_default[stateno];
  }else{
    return vv_action[i];
  }
}

/*
** Perform a shift action.
*/
static void vv_shift(
  vvParser *vvpParser,          /* The parser to be shifted */
  int vvNewState,               /* The new state to shift in */
  int vvMajor,                  /* The major token to shift in */
  VVMINORTYPE *vvpMinor         /* Pointer ot the minor token to shift in */
){
  vvStackEntry *vvtos;
  vvpParser->vvidx++;
  if( vvpParser->vvidx>=VVSTACKDEPTH ){
     phvolt_ARG_FETCH;
     vvpParser->vvidx--;
#ifndef NDEBUG
     if( vvTraceFILE ){
       fprintf(vvTraceFILE,"%sStack Overflow!\n",vvTracePrompt);
     }
#endif
     while( vvpParser->vvidx>=0 ) vv_pop_parser_stack(vvpParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     phvolt_ARG_STORE; /* Suppress warning about unused %extra_argument var */
     return;
  }
  vvtos = &vvpParser->vvstack[vvpParser->vvidx];
  vvtos->stateno = vvNewState;
  vvtos->major = vvMajor;
  vvtos->minor = *vvpMinor;
#ifndef NDEBUG
  if( vvTraceFILE && vvpParser->vvidx>0 ){
    int i;
    fprintf(vvTraceFILE,"%sShift %d\n",vvTracePrompt,vvNewState);
    fprintf(vvTraceFILE,"%sStack:",vvTracePrompt);
    for(i=1; i<=vvpParser->vvidx; i++)
      fprintf(vvTraceFILE," %s",vvTokenName[vvpParser->vvstack[i].major]);
    fprintf(vvTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static struct {
  VVCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} vvRuleInfo[] = {
  { 84, 1 },
  { 85, 1 },
  { 86, 2 },
  { 86, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 89, 8 },
  { 89, 7 },
  { 89, 12 },
  { 89, 11 },
  { 89, 10 },
  { 90, 4 },
  { 91, 3 },
  { 92, 10 },
  { 92, 12 },
  { 92, 12 },
  { 92, 14 },
  { 93, 4 },
  { 108, 3 },
  { 108, 1 },
  { 109, 3 },
  { 109, 3 },
  { 109, 3 },
  { 109, 3 },
  { 109, 3 },
  { 104, 10 },
  { 104, 11 },
  { 110, 3 },
  { 110, 1 },
  { 111, 1 },
  { 111, 3 },
  { 112, 1 },
  { 112, 1 },
  { 112, 1 },
  { 112, 1 },
  { 112, 1 },
  { 112, 1 },
  { 106, 11 },
  { 106, 9 },
  { 105, 2 },
  { 94, 3 },
  { 95, 8 },
  { 95, 7 },
  { 96, 8 },
  { 96, 9 },
  { 97, 4 },
  { 98, 4 },
  { 98, 6 },
  { 99, 4 },
  { 100, 4 },
  { 101, 8 },
  { 101, 8 },
  { 102, 3 },
  { 103, 3 },
  { 88, 1 },
  { 107, 2 },
  { 107, 2 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 4 },
  { 107, 3 },
  { 107, 4 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 4 },
  { 107, 2 },
  { 107, 2 },
  { 107, 2 },
  { 107, 3 },
  { 107, 2 },
  { 107, 3 },
  { 107, 2 },
  { 107, 3 },
  { 107, 4 },
  { 107, 5 },
  { 107, 5 },
  { 107, 5 },
  { 107, 6 },
  { 115, 1 },
  { 115, 1 },
  { 114, 3 },
  { 114, 1 },
  { 116, 3 },
  { 116, 1 },
  { 107, 1 },
  { 117, 4 },
  { 117, 3 },
  { 113, 3 },
  { 113, 1 },
  { 118, 1 },
  { 118, 3 },
  { 107, 1 },
  { 107, 1 },
  { 107, 1 },
  { 107, 1 },
  { 107, 1 },
  { 107, 1 },
  { 107, 1 },
};

static void vv_accept(vvParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void vv_reduce(
  vvParser *vvpParser,         /* The parser */
  int vvruleno                 /* Number of the rule by which to reduce */
){
  int vvgoto;                     /* The next state */
  int vvact;                      /* The next action */
  VVMINORTYPE vvgotominor;        /* The LHS of the rule reduced */
  vvStackEntry *vvmsp;            /* The top of the parser's stack */
  int vvsize;                     /* Amount to pop the stack */
  phvolt_ARG_FETCH;
  vvmsp = &vvpParser->vvstack[vvpParser->vvidx];
#ifndef NDEBUG
  if( vvTraceFILE && vvruleno>=0 
        && vvruleno<sizeof(vvRuleName)/sizeof(vvRuleName[0]) ){
    fprintf(vvTraceFILE, "%sReduce [%s].\n", vvTracePrompt,
      vvRuleName[vvruleno]);
  }
#endif /* NDEBUG */

  switch( vvruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  // <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  // <lineno> <thisfile>
  **     break;
  */
      case 0:
// 711 "parser.lemon"
{
	status->ret = vvmsp[0].minor.vv92;
}
// 2052 "parser.c"
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
      case 22:
      case 131:
// 715 "parser.lemon"
{
	vvgotominor.vv92 = vvmsp[0].minor.vv92;
}
// 2079 "parser.c"
        break;
      case 2:
// 721 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_zval_list(vvmsp[-1].minor.vv92, vvmsp[0].minor.vv92);
}
// 2086 "parser.c"
        break;
      case 3:
      case 36:
      case 45:
      case 128:
      case 135:
// 725 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_zval_list(NULL, vvmsp[0].minor.vv92);
}
// 2097 "parser.c"
        break;
      case 23:
// 809 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_if_statement(vvmsp[-5].minor.vv92, vvmsp[-3].minor.vv92, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(31,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(33,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2110 "parser.c"
        break;
      case 24:
// 813 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_if_statement(vvmsp[-4].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-6].minor);
  vv_destructor(31,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-3].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(33,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2123 "parser.c"
        break;
      case 25:
// 817 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_if_statement(vvmsp[-9].minor.vv92, vvmsp[-7].minor.vv92, vvmsp[-3].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-11].minor);
  vv_destructor(31,&vvmsp[-10].minor);
  vv_destructor(32,&vvmsp[-8].minor);
  vv_destructor(1,&vvmsp[-6].minor);
  vv_destructor(34,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(33,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2139 "parser.c"
        break;
      case 26:
// 821 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_if_statement(vvmsp[-8].minor.vv92, vvmsp[-6].minor.vv92, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-10].minor);
  vv_destructor(31,&vvmsp[-9].minor);
  vv_destructor(32,&vvmsp[-7].minor);
  vv_destructor(1,&vvmsp[-5].minor);
  vv_destructor(34,&vvmsp[-4].minor);
  vv_destructor(32,&vvmsp[-3].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(33,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2155 "parser.c"
        break;
      case 27:
// 825 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_if_statement(vvmsp[-7].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-9].minor);
  vv_destructor(31,&vvmsp[-8].minor);
  vv_destructor(32,&vvmsp[-6].minor);
  vv_destructor(1,&vvmsp[-5].minor);
  vv_destructor(34,&vvmsp[-4].minor);
  vv_destructor(32,&vvmsp[-3].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(33,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2171 "parser.c"
        break;
      case 28:
// 831 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_elseif_statement(vvmsp[-1].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(35,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2181 "parser.c"
        break;
      case 29:
// 837 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_elsefor_statement(status->scanner_state);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(36,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2191 "parser.c"
        break;
      case 30:
// 843 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_for_statement(vvmsp[-7].minor.vv0, NULL, vvmsp[-5].minor.vv92, NULL, vvmsp[-3].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-9].minor);
  vv_destructor(37,&vvmsp[-8].minor);
  vv_destructor(3,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(39,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2205 "parser.c"
        break;
      case 31:
// 847 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_for_statement(vvmsp[-9].minor.vv0, NULL, vvmsp[-7].minor.vv92, vvmsp[-5].minor.vv92, vvmsp[-3].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-11].minor);
  vv_destructor(37,&vvmsp[-10].minor);
  vv_destructor(3,&vvmsp[-8].minor);
  vv_destructor(31,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(39,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2220 "parser.c"
        break;
      case 32:
// 851 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_for_statement(vvmsp[-7].minor.vv0, vvmsp[-9].minor.vv0, vvmsp[-5].minor.vv92, NULL, vvmsp[-3].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-11].minor);
  vv_destructor(37,&vvmsp[-10].minor);
  vv_destructor(2,&vvmsp[-8].minor);
  vv_destructor(3,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(39,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2235 "parser.c"
        break;
      case 33:
// 855 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_for_statement(vvmsp[-9].minor.vv0, vvmsp[-11].minor.vv0, vvmsp[-7].minor.vv92, vvmsp[-5].minor.vv92, vvmsp[-3].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-13].minor);
  vv_destructor(37,&vvmsp[-12].minor);
  vv_destructor(2,&vvmsp[-10].minor);
  vv_destructor(3,&vvmsp[-8].minor);
  vv_destructor(31,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(39,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2251 "parser.c"
        break;
      case 34:
// 861 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_set_statement(vvmsp[-1].minor.vv92);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(40,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2261 "parser.c"
        break;
      case 35:
      case 44:
      case 127:
      case 134:
// 867 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_zval_list(vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92);
  vv_destructor(2,&vvmsp[-1].minor);
}
// 2272 "parser.c"
        break;
      case 37:
// 877 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv0, PHVOLT_T_ASSIGN, vvmsp[0].minor.vv92, status->scanner_state);
  vv_destructor(41,&vvmsp[-1].minor);
}
// 2280 "parser.c"
        break;
      case 38:
// 881 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv0, PHVOLT_T_ADD_ASSIGN, vvmsp[0].minor.vv92, status->scanner_state);
  vv_destructor(42,&vvmsp[-1].minor);
}
// 2288 "parser.c"
        break;
      case 39:
// 885 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv0, PHVOLT_T_SUB_ASSIGN, vvmsp[0].minor.vv92, status->scanner_state);
  vv_destructor(43,&vvmsp[-1].minor);
}
// 2296 "parser.c"
        break;
      case 40:
// 889 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv0, PHVOLT_T_MUL_ASSIGN, vvmsp[0].minor.vv92, status->scanner_state);
  vv_destructor(44,&vvmsp[-1].minor);
}
// 2304 "parser.c"
        break;
      case 41:
// 893 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv0, PHVOLT_T_DIV_ASSIGN, vvmsp[0].minor.vv92, status->scanner_state);
  vv_destructor(45,&vvmsp[-1].minor);
}
// 2312 "parser.c"
        break;
      case 42:
// 899 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_macro_statement(vvmsp[-7].minor.vv0, NULL, vvmsp[-3].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-9].minor);
  vv_destructor(46,&vvmsp[-8].minor);
  vv_destructor(29,&vvmsp[-6].minor);
  vv_destructor(47,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(48,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2327 "parser.c"
        break;
      case 43:
// 903 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_macro_statement(vvmsp[-8].minor.vv0, vvmsp[-6].minor.vv92, vvmsp[-3].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-10].minor);
  vv_destructor(46,&vvmsp[-9].minor);
  vv_destructor(29,&vvmsp[-7].minor);
  vv_destructor(47,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(48,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2342 "parser.c"
        break;
      case 46:
// 919 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_macro_parameter(vvmsp[0].minor.vv0, NULL, status->scanner_state);
}
// 2349 "parser.c"
        break;
      case 47:
// 923 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_macro_parameter(vvmsp[-2].minor.vv0, vvmsp[0].minor.vv92, status->scanner_state);
  vv_destructor(41,&vvmsp[-1].minor);
}
// 2357 "parser.c"
        break;
      case 48:
      case 125:
      case 139:
// 927 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, vvmsp[0].minor.vv0, status->scanner_state);
}
// 2366 "parser.c"
        break;
      case 49:
      case 140:
// 931 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_literal_zval(PHVOLT_T_STRING, vvmsp[0].minor.vv0, status->scanner_state);
}
// 2374 "parser.c"
        break;
      case 50:
      case 141:
// 935 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, vvmsp[0].minor.vv0, status->scanner_state);
}
// 2382 "parser.c"
        break;
      case 51:
      case 142:
// 939 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  vv_destructor(52,&vvmsp[0].minor);
}
// 2391 "parser.c"
        break;
      case 52:
      case 143:
// 943 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  vv_destructor(53,&vvmsp[0].minor);
}
// 2400 "parser.c"
        break;
      case 53:
      case 144:
// 947 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  vv_destructor(54,&vvmsp[0].minor);
}
// 2409 "parser.c"
        break;
      case 54:
// 953 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_macro_call_statement(vvmsp[-8].minor.vv92, vvmsp[-6].minor.vv92, vvmsp[-3].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-10].minor);
  vv_destructor(55,&vvmsp[-9].minor);
  vv_destructor(29,&vvmsp[-7].minor);
  vv_destructor(47,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(56,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2424 "parser.c"
        break;
      case 55:
// 957 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_macro_call_statement(vvmsp[-6].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-8].minor);
  vv_destructor(55,&vvmsp[-7].minor);
  vv_destructor(29,&vvmsp[-5].minor);
  vv_destructor(47,&vvmsp[-4].minor);
  vv_destructor(32,&vvmsp[-3].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(56,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2439 "parser.c"
        break;
      case 56:
// 963 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_empty_statement(status->scanner_state);
  vv_destructor(1,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2448 "parser.c"
        break;
      case 57:
// 969 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_echo_statement(vvmsp[-1].minor.vv92, status->scanner_state);
  vv_destructor(57,&vvmsp[-2].minor);
  vv_destructor(58,&vvmsp[0].minor);
}
// 2457 "parser.c"
        break;
      case 58:
// 975 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_block_statement(vvmsp[-5].minor.vv0, vvmsp[-3].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(59,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(60,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2470 "parser.c"
        break;
      case 59:
// 979 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_block_statement(vvmsp[-4].minor.vv0, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-6].minor);
  vv_destructor(59,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-3].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(60,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2483 "parser.c"
        break;
      case 60:
// 985 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_cache_statement(vvmsp[-5].minor.vv92, NULL, vvmsp[-3].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(61,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(62,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2496 "parser.c"
        break;
      case 61:
// 989 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_cache_statement(vvmsp[-6].minor.vv92, vvmsp[-5].minor.vv0, vvmsp[-3].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-8].minor);
  vv_destructor(61,&vvmsp[-7].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(62,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2509 "parser.c"
        break;
      case 62:
// 995 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_extends_statement(vvmsp[-1].minor.vv0, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(63,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2519 "parser.c"
        break;
      case 63:
// 1001 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_include_statement(vvmsp[-1].minor.vv92, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(64,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2529 "parser.c"
        break;
      case 64:
// 1005 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_include_statement(vvmsp[-3].minor.vv92, vvmsp[-1].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-5].minor);
  vv_destructor(64,&vvmsp[-4].minor);
  vv_destructor(65,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2540 "parser.c"
        break;
      case 65:
// 1011 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_do_statement(vvmsp[-1].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(66,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2550 "parser.c"
        break;
      case 66:
// 1017 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_return_statement(vvmsp[-1].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(67,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2560 "parser.c"
        break;
      case 67:
// 1023 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_autoescape_statement(0, vvmsp[-3].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(68,&vvmsp[-6].minor);
  vv_destructor(53,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(69,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2574 "parser.c"
        break;
      case 68:
// 1027 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_autoescape_statement(1, vvmsp[-3].minor.vv92, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(68,&vvmsp[-6].minor);
  vv_destructor(54,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(69,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2588 "parser.c"
        break;
      case 69:
// 1033 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_break_statement(status->scanner_state);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(70,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2598 "parser.c"
        break;
      case 70:
// 1039 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_continue_statement(status->scanner_state);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(71,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2608 "parser.c"
        break;
      case 71:
// 1045 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, vvmsp[0].minor.vv0, status->scanner_state);
}
// 2615 "parser.c"
        break;
      case 72:
// 1051 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(22,&vvmsp[-1].minor);
}
// 2623 "parser.c"
        break;
      case 73:
// 1055 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_PLUS, NULL, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(21,&vvmsp[-1].minor);
}
// 2631 "parser.c"
        break;
      case 74:
// 1059 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_SUB, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(22,&vvmsp[-1].minor);
}
// 2639 "parser.c"
        break;
      case 75:
// 1063 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_ADD, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(21,&vvmsp[-1].minor);
}
// 2647 "parser.c"
        break;
      case 76:
// 1067 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_MUL, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(19,&vvmsp[-1].minor);
}
// 2655 "parser.c"
        break;
      case 77:
// 1071 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_POW, vvmsp[-3].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(19,&vvmsp[-2].minor);
  vv_destructor(19,&vvmsp[-1].minor);
}
// 2664 "parser.c"
        break;
      case 78:
// 1075 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_DIV, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(18,&vvmsp[-1].minor);
}
// 2672 "parser.c"
        break;
      case 79:
// 1079 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_MOD, vvmsp[-3].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(18,&vvmsp[-2].minor);
  vv_destructor(18,&vvmsp[-1].minor);
}
// 2681 "parser.c"
        break;
      case 80:
// 1083 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_MOD, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(20,&vvmsp[-1].minor);
}
// 2689 "parser.c"
        break;
      case 81:
// 1087 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_AND, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(7,&vvmsp[-1].minor);
}
// 2697 "parser.c"
        break;
      case 82:
// 1091 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_OR, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(8,&vvmsp[-1].minor);
}
// 2705 "parser.c"
        break;
      case 83:
// 1095 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_CONCAT, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(23,&vvmsp[-1].minor);
}
// 2713 "parser.c"
        break;
      case 84:
// 1099 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_PIPE, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(25,&vvmsp[-1].minor);
}
// 2721 "parser.c"
        break;
      case 85:
// 1103 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_RANGE, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(6,&vvmsp[-1].minor);
}
// 2729 "parser.c"
        break;
      case 86:
// 1107 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_EQUALS, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(10,&vvmsp[-1].minor);
}
// 2737 "parser.c"
        break;
      case 87:
// 1111 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, vvmsp[-2].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(73,&vvmsp[0].minor);
}
// 2746 "parser.c"
        break;
      case 88:
// 1115 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_ISSET, vvmsp[-2].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(73,&vvmsp[0].minor);
}
// 2755 "parser.c"
        break;
      case 89:
// 1119 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_NOT_ISEMPTY, vvmsp[-2].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(74,&vvmsp[0].minor);
}
// 2764 "parser.c"
        break;
      case 90:
// 1123 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_ISEMPTY, vvmsp[-2].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(74,&vvmsp[0].minor);
}
// 2773 "parser.c"
        break;
      case 91:
// 1127 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_NOT_ISEVEN, vvmsp[-2].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(75,&vvmsp[0].minor);
}
// 2782 "parser.c"
        break;
      case 92:
// 1131 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_ISEVEN, vvmsp[-2].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(75,&vvmsp[0].minor);
}
// 2791 "parser.c"
        break;
      case 93:
// 1135 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_NOT_ISODD, vvmsp[-2].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(76,&vvmsp[0].minor);
}
// 2800 "parser.c"
        break;
      case 94:
// 1139 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_ISODD, vvmsp[-2].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(76,&vvmsp[0].minor);
}
// 2809 "parser.c"
        break;
      case 95:
// 1143 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_NOT_ISNUMERIC, vvmsp[-2].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(77,&vvmsp[0].minor);
}
// 2818 "parser.c"
        break;
      case 96:
// 1147 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_ISNUMERIC, vvmsp[-2].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(77,&vvmsp[0].minor);
}
// 2827 "parser.c"
        break;
      case 97:
// 1151 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_NOT_ISSCALAR, vvmsp[-2].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(78,&vvmsp[0].minor);
}
// 2836 "parser.c"
        break;
      case 98:
// 1155 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_ISSCALAR, vvmsp[-2].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(78,&vvmsp[0].minor);
}
// 2845 "parser.c"
        break;
      case 99:
// 1159 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_NOT_ISITERABLE, vvmsp[-2].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(79,&vvmsp[0].minor);
}
// 2854 "parser.c"
        break;
      case 100:
// 1163 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_ISITERABLE, vvmsp[-2].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(79,&vvmsp[0].minor);
}
// 2863 "parser.c"
        break;
      case 101:
// 1167 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_IS, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
}
// 2871 "parser.c"
        break;
      case 102:
// 1171 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
}
// 2879 "parser.c"
        break;
      case 103:
// 1175 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(16,&vvmsp[-1].minor);
}
// 2887 "parser.c"
        break;
      case 104:
// 1179 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(17,&vvmsp[-1].minor);
}
// 2895 "parser.c"
        break;
      case 105:
// 1183 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_LESS, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(12,&vvmsp[-1].minor);
}
// 2903 "parser.c"
        break;
      case 106:
// 1187 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_GREATER, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(13,&vvmsp[-1].minor);
}
// 2911 "parser.c"
        break;
      case 107:
// 1191 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(14,&vvmsp[-1].minor);
}
// 2919 "parser.c"
        break;
      case 108:
// 1195 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(15,&vvmsp[-1].minor);
}
// 2927 "parser.c"
        break;
      case 109:
// 1199 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_DOT, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(30,&vvmsp[-1].minor);
}
// 2935 "parser.c"
        break;
      case 110:
// 1203 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_IN, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(3,&vvmsp[-1].minor);
}
// 2943 "parser.c"
        break;
      case 111:
// 1207 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_NOT_IN, vvmsp[-3].minor.vv92, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(26,&vvmsp[-2].minor);
  vv_destructor(3,&vvmsp[-1].minor);
}
// 2952 "parser.c"
        break;
      case 112:
// 1211 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, vvmsp[0].minor.vv92, NULL, status->scanner_state);
  vv_destructor(26,&vvmsp[-1].minor);
}
// 2960 "parser.c"
        break;
      case 113:
// 1215 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_INCR, vvmsp[-1].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(27,&vvmsp[0].minor);
}
// 2968 "parser.c"
        break;
      case 114:
// 1219 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_DECR, vvmsp[-1].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(28,&vvmsp[0].minor);
}
// 2976 "parser.c"
        break;
      case 115:
// 1223 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, vvmsp[-1].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(29,&vvmsp[-2].minor);
  vv_destructor(47,&vvmsp[0].minor);
}
// 2985 "parser.c"
        break;
      case 116:
// 1227 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  vv_destructor(24,&vvmsp[-1].minor);
  vv_destructor(80,&vvmsp[0].minor);
}
// 2994 "parser.c"
        break;
      case 117:
// 1231 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_ARRAY, vvmsp[-1].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(24,&vvmsp[-2].minor);
  vv_destructor(80,&vvmsp[0].minor);
}
// 3003 "parser.c"
        break;
      case 118:
// 1235 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  vv_destructor(81,&vvmsp[-1].minor);
  vv_destructor(82,&vvmsp[0].minor);
}
// 3012 "parser.c"
        break;
      case 119:
// 1239 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_ARRAY, vvmsp[-1].minor.vv92, NULL, NULL, status->scanner_state);
  vv_destructor(81,&vvmsp[-2].minor);
  vv_destructor(82,&vvmsp[0].minor);
}
// 3021 "parser.c"
        break;
      case 120:
// 1243 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, vvmsp[-3].minor.vv92, vvmsp[-1].minor.vv92, NULL, status->scanner_state);
  vv_destructor(24,&vvmsp[-2].minor);
  vv_destructor(80,&vvmsp[0].minor);
}
// 3030 "parser.c"
        break;
      case 121:
// 1247 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_expr(PHVOLT_T_TERNARY, vvmsp[-2].minor.vv92, vvmsp[0].minor.vv92, vvmsp[-4].minor.vv92, status->scanner_state);
  vv_destructor(4,&vvmsp[-3].minor);
  vv_destructor(5,&vvmsp[-1].minor);
}
// 3039 "parser.c"
        break;
      case 122:
// 1251 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_slice(vvmsp[-4].minor.vv92, NULL, vvmsp[-1].minor.vv92, status->scanner_state);
  vv_destructor(24,&vvmsp[-3].minor);
  vv_destructor(5,&vvmsp[-2].minor);
  vv_destructor(80,&vvmsp[0].minor);
}
// 3049 "parser.c"
        break;
      case 123:
// 1255 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_slice(vvmsp[-4].minor.vv92, vvmsp[-2].minor.vv92, NULL, status->scanner_state);
  vv_destructor(24,&vvmsp[-3].minor);
  vv_destructor(5,&vvmsp[-1].minor);
  vv_destructor(80,&vvmsp[0].minor);
}
// 3059 "parser.c"
        break;
      case 124:
// 1259 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_slice(vvmsp[-5].minor.vv92, vvmsp[-3].minor.vv92, vvmsp[-1].minor.vv92, status->scanner_state);
  vv_destructor(24,&vvmsp[-4].minor);
  vv_destructor(5,&vvmsp[-2].minor);
  vv_destructor(80,&vvmsp[0].minor);
}
// 3069 "parser.c"
        break;
      case 126:
      case 138:
// 1269 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, vvmsp[0].minor.vv0, status->scanner_state);
}
// 3077 "parser.c"
        break;
      case 129:
      case 137:
// 1285 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_named_item(vvmsp[-2].minor.vv0, vvmsp[0].minor.vv92, status->scanner_state);
  vv_destructor(5,&vvmsp[-1].minor);
}
// 3086 "parser.c"
        break;
      case 130:
      case 136:
// 1289 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_named_item(NULL, vvmsp[0].minor.vv92, status->scanner_state);
}
// 3094 "parser.c"
        break;
      case 132:
// 1299 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_func_call(vvmsp[-3].minor.vv92, vvmsp[-1].minor.vv92, status->scanner_state);
  vv_destructor(29,&vvmsp[-2].minor);
  vv_destructor(47,&vvmsp[0].minor);
}
// 3103 "parser.c"
        break;
      case 133:
// 1303 "parser.lemon"
{
	vvgotominor.vv92 = phvolt_ret_func_call(vvmsp[-2].minor.vv92, NULL, status->scanner_state);
  vv_destructor(29,&vvmsp[-1].minor);
  vv_destructor(47,&vvmsp[0].minor);
}
// 3112 "parser.c"
        break;
  };
  vvgoto = vvRuleInfo[vvruleno].lhs;
  vvsize = vvRuleInfo[vvruleno].nrhs;
  vvpParser->vvidx -= vvsize;
  vvact = vv_find_reduce_action(vvpParser,vvgoto);
  if( vvact < VVNSTATE ){
    vv_shift(vvpParser,vvact,vvgoto,&vvgotominor);
  }else if( vvact == VVNSTATE + VVNRULE + 1 ){
    vv_accept(vvpParser);
  }
}

/*
** The following code executes when the parse fails
*/
static void vv_parse_failed(
  vvParser *vvpParser           /* The parser */
){
  phvolt_ARG_FETCH;
#ifndef NDEBUG
  if( vvTraceFILE ){
    fprintf(vvTraceFILE,"%sFail!\n",vvTracePrompt);
  }
#endif
  while( vvpParser->vvidx>=0 ) vv_pop_parser_stack(vvpParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  phvolt_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void vv_syntax_error(
  vvParser *vvpParser,           /* The parser */
  int vvmajor,                   /* The major type of the error token */
  VVMINORTYPE vvminor            /* The minor type of the error token */
){
  phvolt_ARG_FETCH;
#define TOKEN (vvminor.vv0)
// 604 "parser.lemon"

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

// 3252 "parser.c"
  phvolt_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void vv_accept(
  vvParser *vvpParser           /* The parser */
){
  phvolt_ARG_FETCH;
#ifndef NDEBUG
  if( vvTraceFILE ){
    fprintf(vvTraceFILE,"%sAccept!\n",vvTracePrompt);
  }
#endif
  while( vvpParser->vvidx>=0 ) vv_pop_parser_stack(vvpParser);
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
  void *vvp,                   /* The parser */
  int vvmajor,                 /* The major token code number */
  phvolt_TOKENTYPE vvminor       /* The value for the token */
  phvolt_ARG_PDECL               /* Optional %extra_argument parameter */
){
  VVMINORTYPE vvminorunion;
  int vvact;            /* The parser action. */
  int vvendofinput;     /* True if we are at the end of input */
  int vverrorhit = 0;   /* True if vvmajor has invoked an error */
  vvParser *vvpParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  vvpParser = (vvParser*)vvp;
  if( vvpParser->vvidx<0 ){
    if( vvmajor==0 ) return;
    vvpParser->vvidx = 0;
    vvpParser->vverrcnt = -1;
    vvpParser->vvstack[0].stateno = 0;
    vvpParser->vvstack[0].major = 0;
  }
  vvminorunion.vv0 = vvminor;
  vvendofinput = (vvmajor==0);
  phvolt_ARG_STORE;

#ifndef NDEBUG
  if( vvTraceFILE ){
    fprintf(vvTraceFILE,"%sInput %s\n",vvTracePrompt,vvTokenName[vvmajor]);
  }
#endif

  do{
    vvact = vv_find_shift_action(vvpParser,vvmajor);
    if( vvact<VVNSTATE ){
      vv_shift(vvpParser,vvact,vvmajor,&vvminorunion);
      vvpParser->vverrcnt--;
      if( vvendofinput && vvpParser->vvidx>=0 ){
        vvmajor = 0;
      }else{
        vvmajor = VVNOCODE;
      }
    }else if( vvact < VVNSTATE + VVNRULE ){
      vv_reduce(vvpParser,vvact-VVNSTATE);
    }else if( vvact == VV_ERROR_ACTION ){
      int vvmx;
#ifndef NDEBUG
      if( vvTraceFILE ){
        fprintf(vvTraceFILE,"%sSyntax Error!\n",vvTracePrompt);
      }
#endif
#ifdef VVERRORSYMBOL
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
      if( vvpParser->vverrcnt<0 ){
        vv_syntax_error(vvpParser,vvmajor,vvminorunion);
      }
      vvmx = vvpParser->vvstack[vvpParser->vvidx].major;
      if( vvmx==VVERRORSYMBOL || vverrorhit ){
#ifndef NDEBUG
        if( vvTraceFILE ){
          fprintf(vvTraceFILE,"%sDiscard input token %s\n",
             vvTracePrompt,vvTokenName[vvmajor]);
        }
#endif
        vv_destructor(vvmajor,&vvminorunion);
        vvmajor = VVNOCODE;
      }else{
         while(
          vvpParser->vvidx >= 0 &&
          vvmx != VVERRORSYMBOL &&
          (vvact = vv_find_shift_action(vvpParser,VVERRORSYMBOL)) >= VVNSTATE
        ){
          vv_pop_parser_stack(vvpParser);
        }
        if( vvpParser->vvidx < 0 || vvmajor==0 ){
          vv_destructor(vvmajor,&vvminorunion);
          vv_parse_failed(vvpParser);
          vvmajor = VVNOCODE;
        }else if( vvmx!=VVERRORSYMBOL ){
          VVMINORTYPE u2;
          u2.VVERRSYMDT = 0;
          vv_shift(vvpParser,vvact,VVERRORSYMBOL,&u2);
        }
      }
      vvpParser->vverrcnt = 3;
      vverrorhit = 1;
#else  /* VVERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( vvpParser->vverrcnt<=0 ){
        vv_syntax_error(vvpParser,vvmajor,vvminorunion);
      }
      vvpParser->vverrcnt = 3;
      vv_destructor(vvmajor,&vvminorunion);
      if( vvendofinput ){
        vv_parse_failed(vvpParser);
      }
      vvmajor = VVNOCODE;
#endif
    }else{
      vv_accept(vvpParser);
      vvmajor = VVNOCODE;
    }
  }while( vvmajor!=VVNOCODE && vvpParser->vvidx>=0 );
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

const phvolt_token_names phvolt_tokens[] =
{
  { SL("INTEGER"),        PHVOLT_T_INTEGER },
  { SL("DOUBLE"),         PHVOLT_T_DOUBLE },
  { SL("STRING"),         PHVOLT_T_STRING },
  { SL("IDENTIFIER"),     PHVOLT_T_IDENTIFIER },
  { SL("MINUS"),          PHVOLT_T_MINUS },
  { SL("+"),              PHVOLT_T_ADD },
  { SL("-"),              PHVOLT_T_SUB },
  { SL("*"),              PHVOLT_T_MUL },
  { SL("/"),              PHVOLT_T_DIV },
  { SL("%%"),             PHVOLT_T_MOD },
  { SL("!"),              PHVOLT_T_NOT },
  { SL("~"),              PHVOLT_T_CONCAT },
  { SL("AND"),            PHVOLT_T_AND },
  { SL("OR"),             PHVOLT_T_OR },
  { SL("DOT"),            PHVOLT_T_DOT },
  { SL("COMMA"),          PHVOLT_T_COMMA },
  { SL("EQUALS"),         PHVOLT_T_EQUALS },
  { SL("NOT EQUALS"),     PHVOLT_T_NOTEQUALS },
  { SL("IDENTICAL"),      PHVOLT_T_IDENTICAL },
  { SL("NOT IDENTICAL"),  PHVOLT_T_NOTIDENTICAL },
  { SL("NOT"),            PHVOLT_T_NOT },
  { SL("RANGE"),          PHVOLT_T_RANGE },
  { SL("COLON"),          PHVOLT_T_COLON },
  { SL("QUESTION MARK"),  PHVOLT_T_QUESTION },
  { SL("<"),              PHVOLT_T_LESS },
  { SL("<="),             PHVOLT_T_LESSEQUAL },
  { SL(">"),              PHVOLT_T_GREATER },
  { SL(">="),             PHVOLT_T_GREATEREQUAL },
  { SL("("),              PHVOLT_T_PARENTHESES_OPEN },
  { SL(")"),              PHVOLT_T_PARENTHESES_CLOSE },
  { SL("["),              PHVOLT_T_SBRACKET_OPEN },
  { SL("]"),              PHVOLT_T_SBRACKET_CLOSE },
  { SL("{"),              PHVOLT_T_CBRACKET_OPEN },
  { SL("}"),              PHVOLT_T_CBRACKET_CLOSE },
  { SL("{%"),             PHVOLT_T_OPEN_DELIMITER },
  { SL("%}"),             PHVOLT_T_CLOSE_DELIMITER },
  { SL("{{"),             PHVOLT_T_OPEN_EDELIMITER },
  { SL("}}"),             PHVOLT_T_CLOSE_EDELIMITER },
  { SL("IF"),             PHVOLT_T_IF },
  { SL("ELSE"),           PHVOLT_T_ELSE },
  { SL("ELSEIF"),         PHVOLT_T_ELSEIF },
  { SL("ELSEFOR"),        PHVOLT_T_ELSEFOR },
  { SL("ENDIF"),          PHVOLT_T_ENDIF },
  { SL("FOR"),            PHVOLT_T_FOR },
  { SL("IN"),             PHVOLT_T_IN },
  { SL("ENDFOR"),         PHVOLT_T_ENDFOR },
  { SL("SET"),            PHVOLT_T_SET },
  { SL("ASSIGN"),         PHVOLT_T_ASSIGN },
  { SL("+="),             PHVOLT_T_ADD_ASSIGN },
  { SL("-="),             PHVOLT_T_SUB_ASSIGN },
  { SL("*="),             PHVOLT_T_MUL_ASSIGN },
  { SL("/="),             PHVOLT_T_DIV_ASSIGN },
  { SL("++"),             PHVOLT_T_INCR },
  { SL("--"),             PHVOLT_T_DECR },
  { SL("BLOCK"),          PHVOLT_T_BLOCK },
  { SL("ENDBLOCK"),       PHVOLT_T_ENDBLOCK },
  { SL("CACHE"),          PHVOLT_T_CACHE },
  { SL("ENDCACHE"),       PHVOLT_T_ENDCACHE },
  { SL("EXTENDS"),        PHVOLT_T_EXTENDS },
  { SL("IS"),             PHVOLT_T_IS },
  { SL("DEFINED"),        PHVOLT_T_DEFINED },
  { SL("EMPTY"),          PHVOLT_T_EMPTY },
  { SL("EVEN"),           PHVOLT_T_EVEN },
  { SL("ODD"),            PHVOLT_T_ODD },
  { SL("NUMERIC"),        PHVOLT_T_NUMERIC },
  { SL("SCALAR"),         PHVOLT_T_SCALAR },
  { SL("ITERABLE"),       PHVOLT_T_ITERABLE },
  { SL("INCLUDE"),        PHVOLT_T_INCLUDE },
  { SL("DO"),             PHVOLT_T_DO },
  { SL("WHITESPACE"),     PHVOLT_T_IGNORE },
  { SL("AUTOESCAPE"),     PHVOLT_T_AUTOESCAPE },
  { SL("ENDAUTOESCAPE"),  PHVOLT_T_ENDAUTOESCAPE },
  { SL("CONTINUE"),       PHVOLT_T_CONTINUE },
  { SL("BREAK"),          PHVOLT_T_BREAK },
  { SL("WITH"),           PHVOLT_T_WITH },
  { SL("RETURN"),         PHVOLT_T_RETURN },
  { SL("MACRO"),          PHVOLT_T_MACRO },
  { SL("ENDMACRO"),       PHVOLT_T_ENDMACRO },
  { SL("CALL"),           PHVOLT_T_CALL },
  { SL("WITH"),           PHVOLT_T_WITH },
  { NULL, 0, 0 }
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

	token->value = NULL;
	token->len = 0;
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

	MAKE_STD_ZVAL(*error_msg);
	if (state->start) {
		error = emalloc(sizeof(char) * 72 + state->start_length +  Z_STRLEN_P(state->active_file));
		if (state->start_length > 16) {
			length = 72 + Z_STRLEN_P(state->active_file);
			error_part = estrndup(state->start, 16);
			snprintf(error, length, "Scanning error before '%s...' in %s on line %d", error_part, Z_STRVAL_P(state->active_file), state->active_line);
			error[length - 1] = '\0';
			efree(error_part);
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
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "View code must be a string");
		return FAILURE;
	}

	if (phvolt_internal_parse_view(&result, view_code, template_path, &error_msg TSRMLS_CC) == FAILURE) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, Z_STRVAL_P(error_msg));
		zval_ptr_dtor(&error_msg);
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
		MAKE_STD_ZVAL(*error_msg);
		ZVAL_STRING(*error_msg, "View code cannot be null", 1);
		return FAILURE;
	}

	if (!Z_STRLEN_P(view_code)) {
		array_init(*result);
		return SUCCESS;
	}

	/** Start the reentrant parser */
	phvolt_parser = phvolt_Alloc(phvolt_wrapper_alloc);
	if (unlikely(!phvolt_parser)) {
		MAKE_STD_ZVAL(*error_msg);
		ZVAL_STRING(*error_msg, "Memory allocation error", 1);
		return FAILURE;
	}

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

	while (0 <= (scanner_status = phvolt_get_token(state, &token))) {

		state->active_token = token.opcode;

		state->start_length = (Z_STRVAL_P(view_code) + Z_STRLEN_P(view_code) - state->start);

		switch (token.opcode) {

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
						if (!phvolt_is_blank_string(&token)) {
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

			case PHVOLT_T_INCR:
				phvolt_(phvolt_parser, PHVOLT_INCR, NULL, parser_status);
				break;
			case PHVOLT_T_DECR:
				phvolt_(phvolt_parser, PHVOLT_DECR, NULL, parser_status);
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

			case PHVOLT_T_EMPTY:
				phvolt_(phvolt_parser, PHVOLT_EMPTY, NULL, parser_status);
				break;

			case PHVOLT_T_EVEN:
				phvolt_(phvolt_parser, PHVOLT_EVEN, NULL, parser_status);
				break;

			case PHVOLT_T_ODD:
				phvolt_(phvolt_parser, PHVOLT_ODD, NULL, parser_status);
				break;

			case PHVOLT_T_NUMERIC:
				phvolt_(phvolt_parser, PHVOLT_NUMERIC, NULL, parser_status);
				break;

			case PHVOLT_T_SCALAR:
				phvolt_(phvolt_parser, PHVOLT_SCALAR, NULL, parser_status);
				break;

			case PHVOLT_T_ITERABLE:
				phvolt_(phvolt_parser, PHVOLT_ITERABLE, NULL, parser_status);
				break;

			case PHVOLT_T_DO:
				phvolt_(phvolt_parser, PHVOLT_DO, NULL, parser_status);
				break;
			case PHVOLT_T_RETURN:
				phvolt_(phvolt_parser, PHVOLT_RETURN, NULL, parser_status);
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
					MAKE_STD_ZVAL(*error_msg);
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
				MAKE_STD_ZVAL(*error_msg);
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
