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

static zval *phvolt_ret_cache_statement(zval *expr, zval *lifetime, zval *block_statements, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_CACHE);
	add_assoc_zval(ret, "expr", expr);

	if (lifetime) {
		add_assoc_zval(ret, "lifetime", lifetime);
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

static zval *phvolt_ret_set_assignment(zval *assignable_expr, int operator, zval *expr, phvolt_scanner_state *state)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 5);

	add_assoc_zval(ret, "variable", assignable_expr);

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


// 568 "parser.c"
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
#define VVNOCODE 122
#define VVACTIONTYPE unsigned short int
#define phvolt_TOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_TOKENTYPE vv0;
  zval* vv112;
  int vv243;
} VVMINORTYPE;
#define VVSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = vvpParser->status
#define phvolt_ARG_STORE vvpParser->status = status
#define VVNSTATE 341
#define VVNRULE 150
#define VVERRORSYMBOL 83
#define VVERRSYMDT vv243
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
 /*     0 */    82,   92,  108,   60,   52,   54,   66,   62,   64,   72,
 /*    10 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*    20 */    56,   89,   58,   84,   87,   88,   96,   80,  115,  230,
 /*    30 */    84,   87,   88,   96,   80,  279,   43,   40,   56,   89,
 /*    40 */    58,   84,   87,   88,   96,   80,  107,  278,  179,  200,
 /*    50 */   183,   82,   92,  181,   60,   52,   54,   66,   62,   64,
 /*    60 */    72,   74,   76,   78,   68,   70,   48,   46,   50,   43,
 /*    70 */    40,   56,   89,   58,   84,   87,   88,   96,   80,   30,
 /*    80 */   240,   82,   92,  180,   60,   52,   54,   66,   62,   64,
 /*    90 */    72,   74,   76,   78,   68,   70,   48,   46,   50,   43,
 /*   100 */    40,   56,   89,   58,   84,   87,   88,   96,   80,  307,
 /*   110 */   173,  205,   82,   92,  241,   60,   52,   54,   66,   62,
 /*   120 */    64,   72,   74,   76,   78,   68,   70,   48,   46,   50,
 /*   130 */    43,   40,   56,   89,   58,   84,   87,   88,   96,   80,
 /*   140 */   323,  318,   82,   92,  234,   60,   52,   54,   66,   62,
 /*   150 */    64,   72,   74,   76,   78,   68,   70,   48,   46,   50,
 /*   160 */    43,   40,   56,   89,   58,   84,   87,   88,   96,   80,
 /*   170 */   406,  246,   82,   92,  332,   60,   52,   54,   66,   62,
 /*   180 */    64,   72,   74,   76,   78,   68,   70,   48,   46,   50,
 /*   190 */    43,   40,   56,   89,   58,   84,   87,   88,   96,   80,
 /*   200 */    85,  249,   82,   92,  407,   60,   52,   54,   66,   62,
 /*   210 */    64,   72,   74,   76,   78,   68,   70,   48,   46,   50,
 /*   220 */    43,   40,   56,   89,   58,   84,   87,   88,   96,   80,
 /*   230 */   128,  243,   82,   92,  219,   60,   52,   54,   66,   62,
 /*   240 */    64,   72,   74,   76,   78,   68,   70,   48,   46,   50,
 /*   250 */    43,   40,   56,   89,   58,   84,   87,   88,   96,   80,
 /*   260 */    48,   46,   50,   43,   40,   56,   89,   58,   84,   87,
 /*   270 */    88,   96,   80,  108,  236,  196,  214,  182,  183,   82,
 /*   280 */    92,  256,   60,   52,   54,   66,   62,   64,   72,   74,
 /*   290 */    76,   78,   68,   70,   48,   46,   50,   43,   40,   56,
 /*   300 */    89,   58,   84,   87,   88,   96,   80,   82,   92,  313,
 /*   310 */    60,   52,   54,   66,   62,   64,   72,   74,   76,   78,
 /*   320 */    68,   70,   48,   46,   50,   43,   40,   56,   89,   58,
 /*   330 */    84,   87,   88,   96,   80,  263,   89,   58,   84,   87,
 /*   340 */    88,   96,   80,  300,  301,  302,  303,  304,  305,  314,
 /*   350 */   171,  282,  102,  112,  288,  306,   82,   92,  315,   60,
 /*   360 */    52,   54,   66,   62,   64,   72,   74,   76,   78,   68,
 /*   370 */    70,   48,   46,   50,   43,   40,   56,   89,   58,   84,
 /*   380 */    87,   88,   96,   80,  472,  309,   82,   92,  258,   60,
 /*   390 */    52,   54,   66,   62,   64,   72,   74,   76,   78,   68,
 /*   400 */    70,   48,   46,   50,   43,   40,   56,   89,   58,   84,
 /*   410 */    87,   88,   96,   80,   97,  316,  139,  128,   97,  284,
 /*   420 */    25,  126,  251,  266,  142,  213,  117,  134,  138,   91,
 /*   430 */   117,  134,  117,   82,   92,   94,   60,   52,   54,   66,
 /*   440 */    62,   64,   72,   74,   76,   78,   68,   70,   48,   46,
 /*   450 */    50,   43,   40,   56,   89,   58,   84,   87,   88,   96,
 /*   460 */    80,   82,   92,  127,   60,   52,   54,   66,   62,   64,
 /*   470 */    72,   74,   76,   78,   68,   70,   48,   46,   50,   43,
 /*   480 */    40,   56,   89,   58,   84,   87,   88,   96,   80,  237,
 /*   490 */   325,   82,   92,  285,   60,   52,   54,   66,   62,   64,
 /*   500 */    72,   74,   76,   78,   68,   70,   48,   46,   50,   43,
 /*   510 */    40,   56,   89,   58,   84,   87,   88,   96,   80,  472,
 /*   520 */    39,   82,   92,  286,   60,   52,   54,   66,   62,   64,
 /*   530 */    72,   74,   76,   78,   68,   70,   48,   46,   50,   43,
 /*   540 */    40,   56,   89,   58,   84,   87,   88,   96,   80,  198,
 /*   550 */    26,   82,   92,  287,   60,   52,   54,   66,   62,   64,
 /*   560 */    72,   74,   76,   78,   68,   70,   48,   46,   50,   43,
 /*   570 */    40,   56,   89,   58,   84,   87,   88,   96,   80,   82,
 /*   580 */    92,  260,   60,   52,   54,   66,   62,   64,   72,   74,
 /*   590 */    76,   78,   68,   70,   48,   46,   50,   43,   40,   56,
 /*   600 */    89,   58,   84,   87,   88,  212,   80,   92,  136,   60,
 /*   610 */    52,   54,   66,   62,   64,   72,   74,   76,   78,   68,
 /*   620 */    70,   48,   46,   50,   43,   40,   56,   89,   58,   84,
 /*   630 */    87,   88,   96,   80,   60,   52,   54,   66,   62,   64,
 /*   640 */    72,   74,   76,   78,   68,   70,   48,   46,   50,   43,
 /*   650 */    40,   56,   89,   58,   84,   87,   88,   96,   80,   52,
 /*   660 */    54,   66,   62,   64,   72,   74,   76,   78,   68,   70,
 /*   670 */    48,   46,   50,   43,   40,   56,   89,   58,   84,   87,
 /*   680 */    88,   96,   80,  492,    1,    2,  265,    4,    5,    6,
 /*   690 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   700 */    17,   18,   19,   20,   21,   22,   66,   62,   64,   72,
 /*   710 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   720 */    56,   89,   58,   84,   87,   88,   96,   80,   27,  265,
 /*   730 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   740 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   33,
 /*   750 */   265,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   760 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   770 */   319,  265,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   780 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   790 */    22,  206,  265,    4,    5,    6,    7,    8,    9,   10,
 /*   800 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   810 */    21,   22,  274,  265,    4,    5,    6,    7,    8,    9,
 /*   820 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   830 */    20,   21,   22,  224,  265,    4,    5,    6,    7,    8,
 /*   840 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   850 */    19,   20,   21,   22,  216,  265,    4,    5,    6,    7,
 /*   860 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   870 */    18,   19,   20,   21,   22,  268,  265,    4,    5,    6,
 /*   880 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   890 */    17,   18,   19,   20,   21,   22,  231,  265,    4,    5,
 /*   900 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   910 */    16,   17,   18,   19,   20,   21,   22,  326,  265,    4,
 /*   920 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   930 */    15,   16,   17,   18,   19,   20,   21,   22,  253,  265,
 /*   940 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   950 */    14,   15,   16,   17,   18,   19,   20,   21,   22,  310,
 /*   960 */   265,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   970 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   980 */   291,  265,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   990 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*  1000 */    22,  174,  265,    4,    5,    6,    7,    8,    9,   10,
 /*  1010 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*  1020 */    21,   22,    3,    4,    5,    6,    7,    8,    9,   10,
 /*  1030 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*  1040 */    21,   22,   44,   41,  222,  103,   90,   98,  295,   97,
 /*  1050 */   100,  340,   44,   41,  104,  103,  140,   98,  117,  118,
 /*  1060 */   100,  117,  129,  111,  322,  113,  117,  337,  104,  118,
 /*  1070 */   290,  119,  120,  121,  122,  123,  124,  106,  104,  113,
 /*  1080 */   117,  119,  120,  121,  122,  123,  124,  144,  223,  125,
 /*  1090 */   117,   38,  166,  209,  289,  154,  155,  156,  157,  158,
 /*  1100 */   159,  160,  109,  117,  117,  147,  148,  149,  150,  151,
 /*  1110 */   152,  153,  109,   24,  220,  334,  336,   37,  167,  169,
 /*  1120 */   342,   23,  178,   42,  327,  165,  329,   36,  168,  201,
 /*  1130 */   294,   45,  199,  141,  267,  117,  227,  117,  210,  194,
 /*  1140 */    47,  297,  221,  117,  228,  197,  235,  238,  320,  244,
 /*  1150 */   247,  250,  117,  257,  259,  217,  184,  186,  188,  190,
 /*  1160 */   192,   24,  220,   29,   31,   37,  167,  169,  298,   23,
 /*  1170 */   178,   49,  175,   51,  297,  296,   53,  201,  261,   55,
 /*  1180 */   232,  261,   34,  117,  204,  117,  210,  338,  117,   32,
 /*  1190 */   221,  117,  228,  264,  235,  238,  264,  244,  247,  250,
 /*  1200 */   299,  257,  259,  330,   57,  261,  471,  254,  170,   24,
 /*  1210 */   220,  311,  261,   37,  167,  169,  117,  312,  178,   59,
 /*  1220 */   264,   61,  137,   63,   65,  201,  261,  264,   28,  261,
 /*  1230 */   333,  117,  207,  117,  210,  117,  117,  261,  221,  261,
 /*  1240 */   228,  264,  235,  238,  264,  244,  247,  250,  471,  257,
 /*  1250 */   259,  292,  264,  271,  264,   67,  225,   24,  220,  269,
 /*  1260 */   261,   37,  167,  169,  261,  328,  178,  117,  261,   69,
 /*  1270 */   202,  215,   71,  201,  272,  264,  203,  273,  177,  264,
 /*  1280 */   143,  117,  210,  264,  117,  261,  221,  261,  228,  261,
 /*  1290 */   235,  238,  280,  244,  247,  250,  339,  257,  259,  275,
 /*  1300 */   264,  341,  264,   73,  264,   24,  220,   35,  261,   37,
 /*  1310 */   167,  169,   75,  261,  178,  117,  261,  273,  252,  335,
 /*  1320 */    77,  201,  273,  264,  117,   79,  131,  277,  264,  273,
 /*  1330 */   210,  264,  117,  273,  221,   81,  228,  117,  235,  238,
 /*  1340 */    83,  244,  247,  250,  273,  257,  259,  117,   86,  261,
 /*  1350 */   273,   93,  117,   24,  220,   95,  261,   37,  167,  169,
 /*  1360 */   117,  273,  178,  117,  264,  273,  273,  117,   99,  201,
 /*  1370 */   273,  264,  273,  101,  273,  273,  116,  273,  210,  273,
 /*  1380 */   117,  273,  221,  281,  228,  117,  235,  238,  117,  244,
 /*  1390 */   247,  250,  132,  257,  259,  273,  139,  162,  273,  164,
 /*  1400 */   172,   24,  220,  185,  117,   37,  167,  169,  138,  117,
 /*  1410 */   178,  117,  117,  187,  273,  117,  189,  201,  273,  191,
 /*  1420 */   273,  193,  273,  273,  195,  117,  210,  273,  117,  273,
 /*  1430 */   221,  117,  228,  117,  235,  238,  117,  244,  247,  250,
 /*  1440 */   270,  257,  259,  273,  211,  229,  273,  239,  242,   24,
 /*  1450 */   220,  245,  273,   37,  167,  169,  117,  117,  178,  117,
 /*  1460 */   117,  248,  273,  117,  262,  201,  273,  308,  273,  273,
 /*  1470 */   273,  273,  317,  117,  210,  273,  117,  273,  221,  117,
 /*  1480 */   228,  276,  235,  238,  117,  244,  247,  250,  324,  257,
 /*  1490 */   259,  273,  273,  273,  273,  273,  273,   24,  220,  273,
 /*  1500 */   117,   37,  167,  169,  273,  273,  178,  273,  273,  273,
 /*  1510 */   273,  273,  273,  201,  273,  273,  273,  273,  273,  273,
 /*  1520 */   273,  273,  210,  273,  273,  273,  221,  273,  228,  233,
 /*  1530 */   235,  238,  273,  244,  247,  250,  273,  257,  259,  273,
 /*  1540 */   273,  273,  273,  273,  273,   24,  220,  273,  273,   37,
 /*  1550 */   167,  169,  273,  321,  178,  273,  273,  273,  273,  273,
 /*  1560 */   273,  201,  273,  273,  273,  273,  273,  273,  273,  273,
 /*  1570 */   210,  273,  273,  273,  221,  273,  228,  273,  235,  238,
 /*  1580 */   273,  244,  247,  250,  273,  257,  259,  273,  273,  273,
 /*  1590 */   273,  273,  273,   24,  220,  273,  273,   37,  167,  169,
 /*  1600 */   273,  273,  178,  273,  273,  273,  273,  273,  273,  201,
 /*  1610 */   273,  273,  273,  273,  273,  273,  273,  273,  210,  218,
 /*  1620 */   273,  273,  221,  273,  228,  273,  235,  238,  273,  244,
 /*  1630 */   247,  250,  273,  257,  259,  273,  273,  273,  273,  273,
 /*  1640 */   273,   24,  220,  273,  273,   37,  167,  169,  273,  273,
 /*  1650 */   178,  273,  273,  273,  273,  273,  273,  201,  273,  293,
 /*  1660 */   273,  273,  273,  273,  273,  273,  210,  273,  273,  273,
 /*  1670 */   221,  273,  228,  273,  235,  238,  273,  244,  247,  250,
 /*  1680 */   273,  257,  259,  273,  273,  273,  273,  273,  273,   24,
 /*  1690 */   220,  331,  273,   37,  167,  169,  273,  273,  178,  273,
 /*  1700 */   273,  273,  273,  273,  273,  201,  273,  273,  273,  273,
 /*  1710 */   273,  273,  273,  273,  210,  273,  273,  273,  221,  273,
 /*  1720 */   228,  273,  235,  238,  273,  244,  247,  250,  273,  257,
 /*  1730 */   259,  273,  273,  273,  273,  273,  273,   24,  220,  273,
 /*  1740 */   273,   37,  167,  169,  273,  273,  178,  273,  273,  273,
 /*  1750 */   273,  273,  273,  201,  273,  273,  273,  273,  273,  273,
 /*  1760 */   273,  273,  210,  273,  273,  273,  221,  226,  228,  273,
 /*  1770 */   235,  238,  273,  244,  247,  250,  273,  257,  259,  273,
 /*  1780 */   273,  273,  273,  273,  273,   24,  220,  273,  273,   37,
 /*  1790 */   167,  169,  273,  273,  178,  273,  273,  273,  273,  273,
 /*  1800 */   273,  201,  273,  208,  273,  273,  273,  273,  273,  273,
 /*  1810 */   210,  273,  273,  273,  221,  273,  228,  273,  235,  238,
 /*  1820 */   273,  244,  247,  250,  273,  257,  259,  273,  273,  273,
 /*  1830 */   273,  273,  273,   24,  220,  273,  273,   37,  167,  169,
 /*  1840 */   273,  273,  178,  273,  273,  273,  273,  273,  273,  201,
 /*  1850 */   273,  273,  273,  273,  273,  273,  273,  273,  210,  273,
 /*  1860 */   273,  273,  221,  273,  228,  273,  235,  238,  273,  244,
 /*  1870 */   247,  250,  255,  257,  259,  273,  273,  273,  273,  273,
 /*  1880 */   273,   24,  220,  273,  273,   37,  167,  169,  273,  176,
 /*  1890 */   178,  273,  273,  273,  273,  273,  273,  201,  273,  273,
 /*  1900 */   273,  273,  273,  273,  273,  273,  210,  273,  273,  273,
 /*  1910 */   221,  273,  228,  273,  235,  238,  273,  244,  247,  250,
 /*  1920 */   273,  257,  259,  273,  273,  273,  273,  273,  273,   24,
 /*  1930 */   220,  273,  273,   37,  167,  169,  273,  273,  178,  273,
 /*  1940 */   273,  273,  273,  273,  273,  201,  273,  273,  273,  273,
 /*  1950 */   273,  273,  273,  273,  210,  273,   44,   41,  221,  103,
 /*  1960 */   228,   98,  235,  238,  100,  244,  247,  250,  273,  257,
 /*  1970 */   259,  273,  273,  118,  273,  273,   44,   41,  273,  103,
 /*  1980 */   273,   98,  273,  283,  100,  119,  130,  121,  122,  123,
 /*  1990 */   124,  273,  161,  118,  273,   44,   41,  273,  103,  273,
 /*  2000 */    98,  273,  273,  100,  273,  119,  114,  121,  122,  123,
 /*  2010 */   124,  273,  118,  273,   44,   41,  109,  103,  273,   98,
 /*  2020 */   273,  273,  100,  273,  119,  120,  121,  122,  123,  124,
 /*  2030 */   273,  118,  273,  135,  273,  273,  109,  110,  273,  105,
 /*  2040 */   273,  273,  273,  119,  114,  121,  122,  123,  124,   44,
 /*  2050 */    41,  273,  103,  273,   98,  109,  273,  100,  273,  273,
 /*  2060 */   273,  273,  273,  273,  273,  163,  146,   44,   41,  273,
 /*  2070 */   103,  273,   98,  273,  109,  100,  273,  273,  145,  120,
 /*  2080 */   121,  122,  123,  124,  118,  273,  273,   44,   41,  273,
 /*  2090 */   103,  273,   98,  273,  273,  100,  119,  120,  121,  122,
 /*  2100 */   123,  124,  273,  273,  118,   44,   41,  273,  103,  109,
 /*  2110 */    98,  273,  273,  100,  133,  273,  119,  130,  121,  122,
 /*  2120 */   123,  124,  118,   44,   41,  273,  103,  109,   98,  273,
 /*  2130 */   273,  100,  273,  273,  119,  120,  121,  122,  123,  124,
 /*  2140 */   118,   44,   41,  273,  103,  273,   98,  109,  273,  100,
 /*  2150 */   273,  273,  119,  114,  121,  122,  123,  124,  118,  273,
 /*  2160 */   273,  273,  273,  273,  273,  109,  273,  273,  273,  273,
 /*  2170 */   119,  130,  121,  122,  123,  124,  273,  273,  273,  273,
 /*  2180 */   273,  273,  273,  109,  273,  273,  273,  273,  273,  273,
 /*  2190 */   273,  273,  273,  273,  273,  273,  273,  273,  273,  273,
 /*  2200 */   273,  109,
};
static VVCODETYPE vv_lookahead[] = {
 /*     0 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*    10 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    20 */    23,   24,   25,   26,   27,   28,   29,   30,    5,   32,
 /*    30 */    26,   27,   28,   29,   30,   38,   21,   22,   23,   24,
 /*    40 */    25,   26,   27,   28,   29,   30,   46,   50,  108,  109,
 /*    50 */   110,    3,    4,    2,    6,    7,    8,    9,   10,   11,
 /*    60 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*    70 */    22,   23,   24,   25,   26,   27,   28,   29,   30,   32,
 /*    80 */    32,    3,    4,   32,    6,    7,    8,    9,   10,   11,
 /*    90 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   100 */    22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
 /*   110 */    32,   32,    3,    4,   66,    6,    7,    8,    9,   10,
 /*   120 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   130 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
 /*   140 */    31,   32,    3,    4,   32,    6,    7,    8,    9,   10,
 /*   150 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   160 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
 /*   170 */    32,   32,    3,    4,   32,    6,    7,    8,    9,   10,
 /*   180 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   190 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
 /*   200 */     3,   32,    3,    4,   32,    6,    7,    8,    9,   10,
 /*   210 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   220 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
 /*   230 */     2,   32,    3,    4,   32,    6,    7,    8,    9,   10,
 /*   240 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   250 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
 /*   260 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   270 */    28,   29,   30,    2,   51,   46,   48,  109,  110,    3,
 /*   280 */     4,   32,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   290 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   300 */    24,   25,   26,   27,   28,   29,   30,    3,    4,   32,
 /*   310 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   320 */    16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
 /*   330 */    26,   27,   28,   29,   30,   59,   24,   25,   26,   27,
 /*   340 */    28,   29,   30,   50,   51,   52,   53,   54,   55,    2,
 /*   350 */     3,   32,   48,   82,  111,  112,    3,    4,   38,    6,
 /*   360 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   370 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   380 */    27,   28,   29,   30,    5,   32,    3,    4,   32,    6,
 /*   390 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   400 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   410 */    27,   28,   29,   30,  107,    3,   38,    2,  107,   32,
 /*   420 */   107,  114,   54,   55,   46,  114,  119,  120,   50,   46,
 /*   430 */   119,  120,  119,    3,    4,    5,    6,    7,    8,    9,
 /*   440 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   450 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   460 */    30,    3,    4,   48,    6,    7,    8,    9,   10,   11,
 /*   470 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   480 */    22,   23,   24,   25,   26,   27,   28,   29,   30,   32,
 /*   490 */    32,    3,    4,    1,    6,    7,    8,    9,   10,   11,
 /*   500 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   510 */    22,   23,   24,   25,   26,   27,   28,   29,   30,   46,
 /*   520 */    32,    3,    4,   57,    6,    7,    8,    9,   10,   11,
 /*   530 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   540 */    22,   23,   24,   25,   26,   27,   28,   29,   30,   38,
 /*   550 */    32,    3,    4,   32,    6,    7,    8,    9,   10,   11,
 /*   560 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   570 */    22,   23,   24,   25,   26,   27,   28,   29,   30,    3,
 /*   580 */     4,   32,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   590 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   600 */    24,   25,   26,   27,   28,   29,   30,    4,  117,    6,
 /*   610 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   620 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   630 */    27,   28,   29,   30,    6,    7,    8,    9,   10,   11,
 /*   640 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   650 */    22,   23,   24,   25,   26,   27,   28,   29,   30,    7,
 /*   660 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   670 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   680 */    28,   29,   30,   84,   85,   86,   87,   88,   89,   90,
 /*   690 */    91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
 /*   700 */   101,  102,  103,  104,  105,  106,    9,   10,   11,   12,
 /*   710 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   720 */    23,   24,   25,   26,   27,   28,   29,   30,   86,   87,
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
 /*   980 */    86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
 /*   990 */    96,   97,   98,   99,  100,  101,  102,  103,  104,  105,
 /*  1000 */   106,   86,   87,   88,   89,   90,   91,   92,   93,   94,
 /*  1010 */    95,   96,   97,   98,   99,  100,  101,  102,  103,  104,
 /*  1020 */   105,  106,   87,   88,   89,   90,   91,   92,   93,   94,
 /*  1030 */    95,   96,   97,   98,   99,  100,  101,  102,  103,  104,
 /*  1040 */   105,  106,   21,   22,   38,   24,  107,   26,    2,  107,
 /*  1050 */    29,   32,   21,   22,  107,   24,  117,   26,  119,   38,
 /*  1060 */    29,  119,  120,  116,   32,  118,  119,   32,  107,   38,
 /*  1070 */    32,   50,   51,   52,   53,   54,   55,  116,  107,  118,
 /*  1080 */   119,   50,   51,   52,   53,   54,   55,   46,   32,  118,
 /*  1090 */   119,  107,  107,   32,   48,   74,   75,   76,   77,   78,
 /*  1100 */    79,   80,   81,  119,  119,   74,   75,   76,   77,   78,
 /*  1110 */    79,   80,   81,   31,   32,   33,   34,   35,   36,   37,
 /*  1120 */     0,    1,   40,  107,    1,  107,   32,   32,   32,   47,
 /*  1130 */    32,  107,  110,    5,   32,  119,   32,  119,   56,   24,
 /*  1140 */   107,   38,   60,  119,   62,   30,   64,   65,    1,   67,
 /*  1150 */    68,   69,  119,   71,   72,    1,   41,   42,   43,   44,
 /*  1160 */    45,   31,   32,   33,   34,   35,   36,   37,   41,    1,
 /*  1170 */    40,  107,    1,  107,   38,  112,  107,   47,   58,  107,
 /*  1180 */     1,   58,    1,  119,   48,  119,   56,    1,  119,   32,
 /*  1190 */    60,  119,   62,   73,   64,   65,   73,   67,   68,   69,
 /*  1200 */   113,   71,   72,    1,  107,   58,   46,    1,   38,   31,
 /*  1210 */    32,    1,   58,   35,   36,   37,  119,   39,   40,  107,
 /*  1220 */    73,  107,   46,  107,  107,   47,   58,   73,    1,   58,
 /*  1230 */     1,  119,    1,  119,   56,  119,  119,   58,   60,   58,
 /*  1240 */    62,   73,   64,   65,   73,   67,   68,   69,    5,   71,
 /*  1250 */    72,    1,   73,   32,   73,  107,    1,   31,   32,    1,
 /*  1260 */    58,   35,   36,   37,   58,   39,   40,  119,   58,  107,
 /*  1270 */    38,   32,  107,   47,  115,   73,   29,   32,   32,   73,
 /*  1280 */   117,  119,   56,   73,  119,   58,   60,   58,   62,   58,
 /*  1290 */    64,   65,    1,   67,   68,   69,   33,   71,   72,    1,
 /*  1300 */    73,    0,   73,  107,   73,   31,   32,   33,   58,   35,
 /*  1310 */    36,   37,  107,   58,   40,  119,   58,  121,   32,   32,
 /*  1320 */   107,   47,  121,   73,  119,  107,    5,   32,   73,  121,
 /*  1330 */    56,   73,  119,  121,   60,  107,   62,  119,   64,   65,
 /*  1340 */   107,   67,   68,   69,  121,   71,   72,  119,  107,   58,
 /*  1350 */   121,  107,  119,   31,   32,  107,   58,   35,   36,   37,
 /*  1360 */   119,  121,   40,  119,   73,  121,  121,  119,  107,   47,
 /*  1370 */   121,   73,  121,  107,  121,  121,  107,  121,   56,  121,
 /*  1380 */   119,  121,   60,   61,   62,  119,   64,   65,  119,   67,
 /*  1390 */    68,   69,  107,   71,   72,  121,   38,  107,  121,  107,
 /*  1400 */   107,   31,   32,  107,  119,   35,   36,   37,   50,  119,
 /*  1410 */    40,  119,  119,  107,  121,  119,  107,   47,  121,  107,
 /*  1420 */   121,  107,  121,  121,  107,  119,   56,  121,  119,  121,
 /*  1430 */    60,  119,   62,  119,   64,   65,  119,   67,   68,   69,
 /*  1440 */    70,   71,   72,  121,  107,  107,  121,  107,  107,   31,
 /*  1450 */    32,  107,  121,   35,   36,   37,  119,  119,   40,  119,
 /*  1460 */   119,  107,  121,  119,  107,   47,  121,  107,  121,  121,
 /*  1470 */   121,  121,  107,  119,   56,  121,  119,  121,   60,  119,
 /*  1480 */    62,   63,   64,   65,  119,   67,   68,   69,  107,   71,
 /*  1490 */    72,  121,  121,  121,  121,  121,  121,   31,   32,  121,
 /*  1500 */   119,   35,   36,   37,  121,  121,   40,  121,  121,  121,
 /*  1510 */   121,  121,  121,   47,  121,  121,  121,  121,  121,  121,
 /*  1520 */   121,  121,   56,  121,  121,  121,   60,  121,   62,   63,
 /*  1530 */    64,   65,  121,   67,   68,   69,  121,   71,   72,  121,
 /*  1540 */   121,  121,  121,  121,  121,   31,   32,  121,  121,   35,
 /*  1550 */    36,   37,  121,   39,   40,  121,  121,  121,  121,  121,
 /*  1560 */   121,   47,  121,  121,  121,  121,  121,  121,  121,  121,
 /*  1570 */    56,  121,  121,  121,   60,  121,   62,  121,   64,   65,
 /*  1580 */   121,   67,   68,   69,  121,   71,   72,  121,  121,  121,
 /*  1590 */   121,  121,  121,   31,   32,  121,  121,   35,   36,   37,
 /*  1600 */   121,  121,   40,  121,  121,  121,  121,  121,  121,   47,
 /*  1610 */   121,  121,  121,  121,  121,  121,  121,  121,   56,   57,
 /*  1620 */   121,  121,   60,  121,   62,  121,   64,   65,  121,   67,
 /*  1630 */    68,   69,  121,   71,   72,  121,  121,  121,  121,  121,
 /*  1640 */   121,   31,   32,  121,  121,   35,   36,   37,  121,  121,
 /*  1650 */    40,  121,  121,  121,  121,  121,  121,   47,  121,   49,
 /*  1660 */   121,  121,  121,  121,  121,  121,   56,  121,  121,  121,
 /*  1670 */    60,  121,   62,  121,   64,   65,  121,   67,   68,   69,
 /*  1680 */   121,   71,   72,  121,  121,  121,  121,  121,  121,   31,
 /*  1690 */    32,   33,  121,   35,   36,   37,  121,  121,   40,  121,
 /*  1700 */   121,  121,  121,  121,  121,   47,  121,  121,  121,  121,
 /*  1710 */   121,  121,  121,  121,   56,  121,  121,  121,   60,  121,
 /*  1720 */    62,  121,   64,   65,  121,   67,   68,   69,  121,   71,
 /*  1730 */    72,  121,  121,  121,  121,  121,  121,   31,   32,  121,
 /*  1740 */   121,   35,   36,   37,  121,  121,   40,  121,  121,  121,
 /*  1750 */   121,  121,  121,   47,  121,  121,  121,  121,  121,  121,
 /*  1760 */   121,  121,   56,  121,  121,  121,   60,   61,   62,  121,
 /*  1770 */    64,   65,  121,   67,   68,   69,  121,   71,   72,  121,
 /*  1780 */   121,  121,  121,  121,  121,   31,   32,  121,  121,   35,
 /*  1790 */    36,   37,  121,  121,   40,  121,  121,  121,  121,  121,
 /*  1800 */   121,   47,  121,   49,  121,  121,  121,  121,  121,  121,
 /*  1810 */    56,  121,  121,  121,   60,  121,   62,  121,   64,   65,
 /*  1820 */   121,   67,   68,   69,  121,   71,   72,  121,  121,  121,
 /*  1830 */   121,  121,  121,   31,   32,  121,  121,   35,   36,   37,
 /*  1840 */   121,  121,   40,  121,  121,  121,  121,  121,  121,   47,
 /*  1850 */   121,  121,  121,  121,  121,  121,  121,  121,   56,  121,
 /*  1860 */   121,  121,   60,  121,   62,  121,   64,   65,  121,   67,
 /*  1870 */    68,   69,   70,   71,   72,  121,  121,  121,  121,  121,
 /*  1880 */   121,   31,   32,  121,  121,   35,   36,   37,  121,   39,
 /*  1890 */    40,  121,  121,  121,  121,  121,  121,   47,  121,  121,
 /*  1900 */   121,  121,  121,  121,  121,  121,   56,  121,  121,  121,
 /*  1910 */    60,  121,   62,  121,   64,   65,  121,   67,   68,   69,
 /*  1920 */   121,   71,   72,  121,  121,  121,  121,  121,  121,   31,
 /*  1930 */    32,  121,  121,   35,   36,   37,  121,  121,   40,  121,
 /*  1940 */   121,  121,  121,  121,  121,   47,  121,  121,  121,  121,
 /*  1950 */   121,  121,  121,  121,   56,  121,   21,   22,   60,   24,
 /*  1960 */    62,   26,   64,   65,   29,   67,   68,   69,  121,   71,
 /*  1970 */    72,  121,  121,   38,  121,  121,   21,   22,  121,   24,
 /*  1980 */   121,   26,  121,   48,   29,   50,   51,   52,   53,   54,
 /*  1990 */    55,  121,   18,   38,  121,   21,   22,  121,   24,  121,
 /*  2000 */    26,  121,  121,   29,  121,   50,   51,   52,   53,   54,
 /*  2010 */    55,  121,   38,  121,   21,   22,   81,   24,  121,   26,
 /*  2020 */   121,  121,   29,  121,   50,   51,   52,   53,   54,   55,
 /*  2030 */   121,   38,  121,    5,  121,  121,   81,   82,  121,   46,
 /*  2040 */   121,  121,  121,   50,   51,   52,   53,   54,   55,   21,
 /*  2050 */    22,  121,   24,  121,   26,   81,  121,   29,  121,  121,
 /*  2060 */   121,  121,  121,  121,  121,   19,   38,   21,   22,  121,
 /*  2070 */    24,  121,   26,  121,   81,   29,  121,  121,   50,   51,
 /*  2080 */    52,   53,   54,   55,   38,  121,  121,   21,   22,  121,
 /*  2090 */    24,  121,   26,  121,  121,   29,   50,   51,   52,   53,
 /*  2100 */    54,   55,  121,  121,   38,   21,   22,  121,   24,   81,
 /*  2110 */    26,  121,  121,   29,   48,  121,   50,   51,   52,   53,
 /*  2120 */    54,   55,   38,   21,   22,  121,   24,   81,   26,  121,
 /*  2130 */   121,   29,  121,  121,   50,   51,   52,   53,   54,   55,
 /*  2140 */    38,   21,   22,  121,   24,  121,   26,   81,  121,   29,
 /*  2150 */   121,  121,   50,   51,   52,   53,   54,   55,   38,  121,
 /*  2160 */   121,  121,  121,  121,  121,   81,  121,  121,  121,  121,
 /*  2170 */    50,   51,   52,   53,   54,   55,  121,  121,  121,  121,
 /*  2180 */   121,  121,  121,   81,  121,  121,  121,  121,  121,  121,
 /*  2190 */   121,  121,  121,  121,  121,  121,  121,  121,  121,  121,
 /*  2200 */   121,   81,
};
#define VV_SHIFT_USE_DFLT (-4)
static short vv_shift_ofst[] = {
 /*     0 */  1168, 1301, 1120,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    20 */    -4,   -4,   -4, 1898, 2084,  518, 1229, 1227, 1130,   47,
 /*    30 */    -4, 1157, 1202, 1181, 1274, 1095,   -4, 2084,  488,   -4,
 /*    40 */  2084, 2084,  312, 2084, 2084,  312, 2046,   15, 1974,   15,
 /*    50 */  2084,   15, 2084,  697, 2084,  697, 2084,  312, 2084,    4,
 /*    60 */  2084,  652, 2084,  242, 1021,  242, 1031,  242, 2084,  242,
 /*    70 */  2084,  242, 2084,  242, 2084,  242, 2084,  242, 2084,  242,
 /*    80 */  2084,   -4, 2084,  603,  197, 2084,    4,   -4,   -4, 2028,
 /*    90 */   383,   -4, 2084,  430, 2084,  628, 2066,  548, 2084,    4,
 /*   100 */  2084,  304,   -4, 1993,  548,   -4,    0,   -4, 2102, 1955,
 /*   110 */    -4,  271,   -4,   -4,   23, 2084,  548,   -4,   -4,   -4,
 /*   120 */    -4,   -4,   -4,   -4,   -4,   -4,  415,   -4, 2120,   -4,
 /*   130 */  1321, 2084,  548,   -4,   -4, 1358, 1176,   -4, 1160,  473,
 /*   140 */  1128,  378,   -4, 1041,   -4, 1243,  379,   -4,   -4,   -4,
 /*   150 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*   160 */    -4, 2084,   15, 2084,   15,  312,  312, 1096,   -4, 1170,
 /*   170 */   347, 2084,   78, 1168, 1171, 1850, 1246,   -4,  511,   51,
 /*   180 */    -4,  511,   -4, 1115, 2084,  548, 2084,  548, 2084,  548,
 /*   190 */  2084,  548, 2084,  548, 2084,  229,   -4,  511,   -4,   -4,
 /*   200 */    -4, 1232, 1247, 1136,   79, 1168, 1231, 1754, 1061,   -4,
 /*   210 */  2084,  576, 1935,  228, 1239, 1168, 1154, 1562,  202,   -4,
 /*   220 */    -4, 1006, 1056, 1291, 1255, 1706, 1104,   -4, 2084,   -3,
 /*   230 */  1168, 1179, 1466,  112,   -4,  223,  457,   -4, 2084,   48,
 /*   240 */    -4, 2084,  199,   -4, 2084,  139,   -4, 2084,  169,   -4,
 /*   250 */   368, 1286, 1168, 1206, 1802,  249,   -4,  356,   -4,  549,
 /*   260 */    -4, 2084,  276,   -4,   -4,   -4, 1102, 1168, 1258, 1370,
 /*   270 */  1221,   -4, 1245, 1168, 1298, 1418, 1295,   -4,  138,  172,
 /*   280 */  1322,  319,   -4,  387,  492,  466,  521,   -4, 1046, 1038,
 /*   290 */  1168, 1250, 1610, 1098,   -4, 1103,   -4, 1127,  293,   -4,
 /*   300 */    -4,   -4,   -4,   -4,   -4,   -4,   -4, 2084,  353, 1168,
 /*   310 */  1210, 1178,  277,   -4,  320,  412, 2084,  109, 1168, 1147,
 /*   320 */  1514, 1032,   -4, 2084,  458, 1168, 1123, 1226, 1094,   -4,
 /*   330 */  1658,  142,   -4, 1082, 1287,   -4, 1035, 1186, 1263, 1019,
 /*   340 */    -4,
};
#define VV_REDUCE_USE_DFLT (-61)
static short vv_reduce_ofst[] = {
 /*     0 */   599,  -61,  935,  -61,  -61,  -61,  -61,  -61,  -61,  -61,
 /*    10 */   -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,
 /*    20 */   -61,  -61,  -61,  -61,  313,  -61,  642,  935,  -61,  -61,
 /*    30 */   -61,  -61,  663,  935,  -61,  -61,  -61,  984,  -61,  -61,
 /*    40 */   985, 1016,  -61, 1018, 1024,  -61, 1033,  -61, 1064,  -61,
 /*    50 */  1066,  -61, 1069,  -61, 1072,  -61, 1097,  -61, 1112,  -61,
 /*    60 */  1114,  -61, 1116,  -61, 1117,  -61, 1148,  -61, 1162,  -61,
 /*    70 */  1165,  -61, 1196,  -61, 1205,  -61, 1213,  -61, 1218,  -61,
 /*    80 */  1228,  -61, 1233,  -61,  -61, 1241,  -61,  -61,  -61,  939,
 /*    90 */   -61,  -61, 1244,  -61, 1248,  -61,  307,  -61, 1261,  -61,
 /*   100 */  1266,  -61,  -61,  961,  -61,  -61,  -61,  -61,  971,  947,
 /*   110 */   -61,  -61,  -61,  -61,  -61, 1269,  -61,  -61,  -61,  -61,
 /*   120 */   -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,  942,  -61,
 /*   130 */   -61, 1285,  -61,  -61,  -61,  491,  -61,  -61,  -61,  -61,
 /*   140 */   -61, 1163,  -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,
 /*   150 */   -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,
 /*   160 */   -61, 1290,  -61, 1292,  -61,  -61,  -61,  -61,  -61,  -61,
 /*   170 */   -61, 1293,  -61,  915,  935,  -61,  -61,  -61,  -60,  -61,
 /*   180 */   -61,  168,  -61,  -61, 1296,  -61, 1306,  -61, 1309,  -61,
 /*   190 */  1312,  -61, 1314,  -61, 1317,  -61,  -61, 1022,  -61,  -61,
 /*   200 */   -61,  -61,  -61,  243,  -61,  705,  935,  -61,  -61,  -61,
 /*   210 */  1337,  -61,  311,  -61,  -61,  768,  935,  -61,  -61,  -61,
 /*   220 */   -61,  -61,  -61,  747,  935,  -61,  -61,  -61, 1338, 1159,
 /*   230 */   810,  935,  -61,  -61,  -61,  -61,  -61,  -61, 1340,  -61,
 /*   240 */   -61, 1341,  -61,  -61, 1344,  -61,  -61, 1354,  -61,  -61,
 /*   250 */   -61,  -61,  852,  935,  -61,  -61,  -61,  -61,  -61,  -61,
 /*   260 */   -61, 1357,  -61,  -61,  -61,  -61,  -61,  789,  935,  -61,
 /*   270 */   -61,  -61,  -61,  726,  935,  -61,  -61,  -61,  -61,  -61,
 /*   280 */   -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,
 /*   290 */   894,  935,  -61,  -61,  -61, 1063,  -61,  -61, 1087,  -61,
 /*   300 */   -61,  -61,  -61,  -61,  -61,  -61,  -61, 1360,  -61,  873,
 /*   310 */   935,  -61,  -61,  -61,  -61,  -61, 1365,  -61,  684,  935,
 /*   320 */   -61,  -61,  -61, 1381,  -61,  831,  935,  -61,  -61,  -61,
 /*   330 */   -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,
 /*   340 */   -61,
};
static VVACTIONTYPE vv_default[] = {
 /*     0 */   491,  491,  491,  343,  345,  346,  347,  348,  349,  350,
 /*    10 */   351,  352,  353,  354,  355,  356,  357,  358,  359,  360,
 /*    20 */   361,  362,  363,  491,  491,  491,  491,  491,  491,  491,
 /*    30 */   364,  491,  491,  491,  491,  491,  366,  491,  491,  369,
 /*    40 */   491,  491,  418,  491,  491,  419,  491,  422,  491,  424,
 /*    50 */   491,  426,  491,  427,  491,  428,  491,  429,  491,  430,
 /*    60 */   491,  431,  491,  432,  491,  448,  491,  447,  491,  449,
 /*    70 */   491,  450,  491,  451,  491,  452,  491,  453,  491,  454,
 /*    80 */   491,  455,  491,  456,  491,  491,  457,  459,  460,  491,
 /*    90 */   491,  466,  491,  491,  491,  467,  491,  482,  491,  458,
 /*   100 */   491,  491,  461,  491,  476,  462,  491,  463,  491,  491,
 /*   110 */   464,  491,  465,  474,  486,  491,  475,  477,  484,  485,
 /*   120 */   486,  487,  488,  489,  490,  473,  491,  478,  491,  480,
 /*   130 */   486,  491,  483,  479,  481,  491,  491,  468,  491,  491,
 /*   140 */   491,  491,  469,  491,  470,  485,  484,  434,  436,  438,
 /*   150 */   440,  442,  444,  446,  433,  435,  437,  439,  441,  443,
 /*   160 */   445,  491,  425,  491,  423,  421,  420,  491,  370,  491,
 /*   170 */   491,  491,  491,  491,  491,  491,  491,  371,  491,  491,
 /*   180 */   375,  491,  376,  491,  491,  378,  491,  379,  491,  380,
 /*   190 */   491,  381,  491,  382,  491,  491,  384,  491,  383,  385,
 /*   200 */   377,  491,  491,  491,  491,  491,  491,  491,  491,  386,
 /*   210 */   491,  491,  491,  491,  478,  491,  491,  491,  491,  398,
 /*   220 */   400,  491,  491,  491,  491,  491,  491,  402,  491,  491,
 /*   230 */   491,  491,  491,  491,  404,  491,  491,  408,  491,  491,
 /*   240 */   409,  491,  491,  410,  491,  491,  411,  491,  491,  412,
 /*   250 */   491,  491,  491,  491,  491,  491,  413,  491,  415,  491,
 /*   260 */   416,  491,  491,  401,  417,  344,  491,  491,  491,  491,
 /*   270 */   491,  414,  491,  491,  491,  491,  491,  405,  491,  491,
 /*   280 */   491,  491,  403,  479,  491,  491,  491,  399,  491,  491,
 /*   290 */   491,  491,  491,  491,  387,  491,  388,  390,  491,  391,
 /*   300 */   392,  393,  394,  395,  396,  397,  389,  491,  491,  491,
 /*   310 */   491,  491,  491,  372,  491,  491,  491,  491,  491,  491,
 /*   320 */   491,  491,  373,  491,  491,  491,  491,  491,  491,  374,
 /*   330 */   491,  491,  367,  491,  491,  365,  491,  491,  491,  491,
 /*   340 */   368,
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
  "MUL_ASSIGN",    "DIV_ASSIGN",    "SBRACKET_CLOSE",  "MACRO",       
  "PARENTHESES_CLOSE",  "ENDMACRO",      "INTEGER",       "STRING",      
  "DOUBLE",        "NULL",          "FALSE",         "TRUE",        
  "CALL",          "ENDCALL",       "OPEN_EDELIMITER",  "CLOSE_EDELIMITER",
  "BLOCK",         "ENDBLOCK",      "CACHE",         "ENDCACHE",    
  "EXTENDS",       "INCLUDE",       "WITH",          "DO",          
  "RETURN",        "AUTOESCAPE",    "ENDAUTOESCAPE",  "BREAK",       
  "CONTINUE",      "RAW_FRAGMENT",  "DEFINED",       "EMPTY",       
  "EVEN",          "ODD",           "NUMERIC",       "SCALAR",      
  "ITERABLE",      "CBRACKET_OPEN",  "CBRACKET_CLOSE",  "error",       
  "program",       "volt_language",  "statement_list",  "statement",   
  "raw_fragment",  "if_statement",  "elseif_statement",  "elsefor_statement",
  "for_statement",  "set_statement",  "echo_statement",  "block_statement",
  "cache_statement",  "extends_statement",  "include_statement",  "do_statement",
  "return_statement",  "autoescape_statement",  "break_statement",  "continue_statement",
  "macro_statement",  "empty_statement",  "macro_call_statement",  "expr",        
  "set_assignments",  "set_assignment",  "assignable_expr",  "macro_parameters",
  "macro_parameter",  "macro_parameter_default",  "argument_list",  "cache_lifetime",
  "array_list",    "slice_offset",  "array_item",    "function_call",
  "argument_item",
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
 /*  37 */ "set_assignment ::= assignable_expr ASSIGN expr",
 /*  38 */ "set_assignment ::= assignable_expr ADD_ASSIGN expr",
 /*  39 */ "set_assignment ::= assignable_expr SUB_ASSIGN expr",
 /*  40 */ "set_assignment ::= assignable_expr MUL_ASSIGN expr",
 /*  41 */ "set_assignment ::= assignable_expr DIV_ASSIGN expr",
 /*  42 */ "assignable_expr ::= IDENTIFIER",
 /*  43 */ "assignable_expr ::= assignable_expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /*  44 */ "assignable_expr ::= assignable_expr DOT assignable_expr",
 /*  45 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  46 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN macro_parameters PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  47 */ "macro_parameters ::= macro_parameters COMMA macro_parameter",
 /*  48 */ "macro_parameters ::= macro_parameter",
 /*  49 */ "macro_parameter ::= IDENTIFIER",
 /*  50 */ "macro_parameter ::= IDENTIFIER ASSIGN macro_parameter_default",
 /*  51 */ "macro_parameter_default ::= INTEGER",
 /*  52 */ "macro_parameter_default ::= STRING",
 /*  53 */ "macro_parameter_default ::= DOUBLE",
 /*  54 */ "macro_parameter_default ::= NULL",
 /*  55 */ "macro_parameter_default ::= FALSE",
 /*  56 */ "macro_parameter_default ::= TRUE",
 /*  57 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  58 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  59 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  60 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  61 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  62 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  63 */ "cache_statement ::= OPEN_DELIMITER CACHE expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  64 */ "cache_statement ::= OPEN_DELIMITER CACHE expr cache_lifetime CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  65 */ "cache_lifetime ::= INTEGER",
 /*  66 */ "cache_lifetime ::= IDENTIFIER",
 /*  67 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  68 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr CLOSE_DELIMITER",
 /*  69 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr WITH expr CLOSE_DELIMITER",
 /*  70 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  71 */ "return_statement ::= OPEN_DELIMITER RETURN expr CLOSE_DELIMITER",
 /*  72 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE FALSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  73 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE TRUE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  74 */ "break_statement ::= OPEN_DELIMITER BREAK CLOSE_DELIMITER",
 /*  75 */ "continue_statement ::= OPEN_DELIMITER CONTINUE CLOSE_DELIMITER",
 /*  76 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  77 */ "expr ::= MINUS expr",
 /*  78 */ "expr ::= PLUS expr",
 /*  79 */ "expr ::= expr MINUS expr",
 /*  80 */ "expr ::= expr PLUS expr",
 /*  81 */ "expr ::= expr TIMES expr",
 /*  82 */ "expr ::= expr TIMES TIMES expr",
 /*  83 */ "expr ::= expr DIVIDE expr",
 /*  84 */ "expr ::= expr DIVIDE DIVIDE expr",
 /*  85 */ "expr ::= expr MOD expr",
 /*  86 */ "expr ::= expr AND expr",
 /*  87 */ "expr ::= expr OR expr",
 /*  88 */ "expr ::= expr CONCAT expr",
 /*  89 */ "expr ::= expr PIPE expr",
 /*  90 */ "expr ::= expr RANGE expr",
 /*  91 */ "expr ::= expr EQUALS expr",
 /*  92 */ "expr ::= expr NOTEQUALS DEFINED",
 /*  93 */ "expr ::= expr IS DEFINED",
 /*  94 */ "expr ::= expr NOTEQUALS EMPTY",
 /*  95 */ "expr ::= expr IS EMPTY",
 /*  96 */ "expr ::= expr NOTEQUALS EVEN",
 /*  97 */ "expr ::= expr IS EVEN",
 /*  98 */ "expr ::= expr NOTEQUALS ODD",
 /*  99 */ "expr ::= expr IS ODD",
 /* 100 */ "expr ::= expr NOTEQUALS NUMERIC",
 /* 101 */ "expr ::= expr IS NUMERIC",
 /* 102 */ "expr ::= expr NOTEQUALS SCALAR",
 /* 103 */ "expr ::= expr IS SCALAR",
 /* 104 */ "expr ::= expr NOTEQUALS ITERABLE",
 /* 105 */ "expr ::= expr IS ITERABLE",
 /* 106 */ "expr ::= expr IS expr",
 /* 107 */ "expr ::= expr NOTEQUALS expr",
 /* 108 */ "expr ::= expr IDENTICAL expr",
 /* 109 */ "expr ::= expr NOTIDENTICAL expr",
 /* 110 */ "expr ::= expr LESS expr",
 /* 111 */ "expr ::= expr GREATER expr",
 /* 112 */ "expr ::= expr GREATEREQUAL expr",
 /* 113 */ "expr ::= expr LESSEQUAL expr",
 /* 114 */ "expr ::= expr DOT expr",
 /* 115 */ "expr ::= expr IN expr",
 /* 116 */ "expr ::= expr NOT IN expr",
 /* 117 */ "expr ::= NOT expr",
 /* 118 */ "expr ::= expr INCR",
 /* 119 */ "expr ::= expr DECR",
 /* 120 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 121 */ "expr ::= SBRACKET_OPEN SBRACKET_CLOSE",
 /* 122 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /* 123 */ "expr ::= CBRACKET_OPEN CBRACKET_CLOSE",
 /* 124 */ "expr ::= CBRACKET_OPEN array_list CBRACKET_CLOSE",
 /* 125 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /* 126 */ "expr ::= expr QUESTION expr COLON expr",
 /* 127 */ "expr ::= expr SBRACKET_OPEN COLON slice_offset SBRACKET_CLOSE",
 /* 128 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON SBRACKET_CLOSE",
 /* 129 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON slice_offset SBRACKET_CLOSE",
 /* 130 */ "slice_offset ::= INTEGER",
 /* 131 */ "slice_offset ::= IDENTIFIER",
 /* 132 */ "array_list ::= array_list COMMA array_item",
 /* 133 */ "array_list ::= array_item",
 /* 134 */ "array_item ::= STRING COLON expr",
 /* 135 */ "array_item ::= expr",
 /* 136 */ "expr ::= function_call",
 /* 137 */ "function_call ::= expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 138 */ "function_call ::= expr PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 139 */ "argument_list ::= argument_list COMMA argument_item",
 /* 140 */ "argument_list ::= argument_item",
 /* 141 */ "argument_item ::= expr",
 /* 142 */ "argument_item ::= STRING COLON expr",
 /* 143 */ "expr ::= IDENTIFIER",
 /* 144 */ "expr ::= INTEGER",
 /* 145 */ "expr ::= STRING",
 /* 146 */ "expr ::= DOUBLE",
 /* 147 */ "expr ::= NULL",
 /* 148 */ "expr ::= FALSE",
 /* 149 */ "expr ::= TRUE",
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
// 700 "parser.lemon"
{
	if ((vvpminor->vv0)) {
		if ((vvpminor->vv0)->free_flag) {
			efree((vvpminor->vv0)->token);
		}
		efree((vvpminor->vv0));
	}
}
// 1665 "parser.c"
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
    case 111:
    case 112:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
// 717 "parser.lemon"
{ zval_ptr_dtor(&(vvpminor->vv112)); }
// 1702 "parser.c"
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
  { 110, 1 },
  { 110, 4 },
  { 110, 3 },
  { 104, 10 },
  { 104, 11 },
  { 111, 3 },
  { 111, 1 },
  { 112, 1 },
  { 112, 3 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 106, 11 },
  { 106, 9 },
  { 105, 2 },
  { 94, 3 },
  { 95, 8 },
  { 95, 7 },
  { 96, 8 },
  { 96, 9 },
  { 115, 1 },
  { 115, 1 },
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
  { 117, 1 },
  { 117, 1 },
  { 116, 3 },
  { 116, 1 },
  { 118, 3 },
  { 118, 1 },
  { 107, 1 },
  { 119, 4 },
  { 119, 3 },
  { 114, 3 },
  { 114, 1 },
  { 120, 1 },
  { 120, 3 },
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
// 709 "parser.lemon"
{
	status->ret = vvmsp[0].minor.vv112;
}
// 2069 "parser.c"
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
      case 136:
// 713 "parser.lemon"
{
	vvgotominor.vv112 = vvmsp[0].minor.vv112;
}
// 2096 "parser.c"
        break;
      case 2:
// 719 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_zval_list(vvmsp[-1].minor.vv112, vvmsp[0].minor.vv112);
}
// 2103 "parser.c"
        break;
      case 3:
      case 36:
      case 48:
      case 133:
      case 140:
// 723 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_zval_list(NULL, vvmsp[0].minor.vv112);
}
// 2114 "parser.c"
        break;
      case 23:
// 807 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_if_statement(vvmsp[-5].minor.vv112, vvmsp[-3].minor.vv112, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(31,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(33,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2127 "parser.c"
        break;
      case 24:
// 811 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_if_statement(vvmsp[-4].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-6].minor);
  vv_destructor(31,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-3].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(33,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2140 "parser.c"
        break;
      case 25:
// 815 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_if_statement(vvmsp[-9].minor.vv112, vvmsp[-7].minor.vv112, vvmsp[-3].minor.vv112, status->scanner_state);
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
// 2156 "parser.c"
        break;
      case 26:
// 819 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_if_statement(vvmsp[-8].minor.vv112, vvmsp[-6].minor.vv112, NULL, status->scanner_state);
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
// 2172 "parser.c"
        break;
      case 27:
// 823 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_if_statement(vvmsp[-7].minor.vv112, NULL, NULL, status->scanner_state);
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
// 2188 "parser.c"
        break;
      case 28:
// 829 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_elseif_statement(vvmsp[-1].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(35,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2198 "parser.c"
        break;
      case 29:
// 835 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_elsefor_statement(status->scanner_state);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(36,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2208 "parser.c"
        break;
      case 30:
// 841 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_for_statement(vvmsp[-7].minor.vv0, NULL, vvmsp[-5].minor.vv112, NULL, vvmsp[-3].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-9].minor);
  vv_destructor(37,&vvmsp[-8].minor);
  vv_destructor(3,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(39,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2222 "parser.c"
        break;
      case 31:
// 845 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_for_statement(vvmsp[-9].minor.vv0, NULL, vvmsp[-7].minor.vv112, vvmsp[-5].minor.vv112, vvmsp[-3].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-11].minor);
  vv_destructor(37,&vvmsp[-10].minor);
  vv_destructor(3,&vvmsp[-8].minor);
  vv_destructor(31,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(39,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2237 "parser.c"
        break;
      case 32:
// 849 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_for_statement(vvmsp[-7].minor.vv0, vvmsp[-9].minor.vv0, vvmsp[-5].minor.vv112, NULL, vvmsp[-3].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-11].minor);
  vv_destructor(37,&vvmsp[-10].minor);
  vv_destructor(2,&vvmsp[-8].minor);
  vv_destructor(3,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(39,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2252 "parser.c"
        break;
      case 33:
// 853 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_for_statement(vvmsp[-9].minor.vv0, vvmsp[-11].minor.vv0, vvmsp[-7].minor.vv112, vvmsp[-5].minor.vv112, vvmsp[-3].minor.vv112, status->scanner_state);
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
// 2268 "parser.c"
        break;
      case 34:
// 859 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_set_statement(vvmsp[-1].minor.vv112);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(40,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2278 "parser.c"
        break;
      case 35:
      case 47:
      case 132:
      case 139:
// 865 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_zval_list(vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112);
  vv_destructor(2,&vvmsp[-1].minor);
}
// 2289 "parser.c"
        break;
      case 37:
// 875 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv112, PHVOLT_T_ASSIGN, vvmsp[0].minor.vv112, status->scanner_state);
  vv_destructor(41,&vvmsp[-1].minor);
}
// 2297 "parser.c"
        break;
      case 38:
// 879 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv112, PHVOLT_T_ADD_ASSIGN, vvmsp[0].minor.vv112, status->scanner_state);
  vv_destructor(42,&vvmsp[-1].minor);
}
// 2305 "parser.c"
        break;
      case 39:
// 883 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv112, PHVOLT_T_SUB_ASSIGN, vvmsp[0].minor.vv112, status->scanner_state);
  vv_destructor(43,&vvmsp[-1].minor);
}
// 2313 "parser.c"
        break;
      case 40:
// 887 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv112, PHVOLT_T_MUL_ASSIGN, vvmsp[0].minor.vv112, status->scanner_state);
  vv_destructor(44,&vvmsp[-1].minor);
}
// 2321 "parser.c"
        break;
      case 41:
// 891 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv112, PHVOLT_T_DIV_ASSIGN, vvmsp[0].minor.vv112, status->scanner_state);
  vv_destructor(45,&vvmsp[-1].minor);
}
// 2329 "parser.c"
        break;
      case 42:
      case 66:
      case 131:
      case 143:
// 895 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, vvmsp[0].minor.vv0, status->scanner_state);
}
// 2339 "parser.c"
        break;
      case 43:
      case 125:
// 899 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, vvmsp[-3].minor.vv112, vvmsp[-1].minor.vv112, NULL, status->scanner_state);
  vv_destructor(24,&vvmsp[-2].minor);
  vv_destructor(46,&vvmsp[0].minor);
}
// 2349 "parser.c"
        break;
      case 44:
      case 114:
// 903 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_DOT, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(30,&vvmsp[-1].minor);
}
// 2358 "parser.c"
        break;
      case 45:
// 909 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_macro_statement(vvmsp[-7].minor.vv0, NULL, vvmsp[-3].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-9].minor);
  vv_destructor(47,&vvmsp[-8].minor);
  vv_destructor(29,&vvmsp[-6].minor);
  vv_destructor(48,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(49,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2373 "parser.c"
        break;
      case 46:
// 913 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_macro_statement(vvmsp[-8].minor.vv0, vvmsp[-6].minor.vv112, vvmsp[-3].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-10].minor);
  vv_destructor(47,&vvmsp[-9].minor);
  vv_destructor(29,&vvmsp[-7].minor);
  vv_destructor(48,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(49,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2388 "parser.c"
        break;
      case 49:
// 929 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_macro_parameter(vvmsp[0].minor.vv0, NULL, status->scanner_state);
}
// 2395 "parser.c"
        break;
      case 50:
// 933 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_macro_parameter(vvmsp[-2].minor.vv0, vvmsp[0].minor.vv112, status->scanner_state);
  vv_destructor(41,&vvmsp[-1].minor);
}
// 2403 "parser.c"
        break;
      case 51:
      case 65:
      case 130:
      case 144:
// 937 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, vvmsp[0].minor.vv0, status->scanner_state);
}
// 2413 "parser.c"
        break;
      case 52:
      case 145:
// 941 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_literal_zval(PHVOLT_T_STRING, vvmsp[0].minor.vv0, status->scanner_state);
}
// 2421 "parser.c"
        break;
      case 53:
      case 146:
// 945 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, vvmsp[0].minor.vv0, status->scanner_state);
}
// 2429 "parser.c"
        break;
      case 54:
      case 147:
// 949 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  vv_destructor(53,&vvmsp[0].minor);
}
// 2438 "parser.c"
        break;
      case 55:
      case 148:
// 953 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  vv_destructor(54,&vvmsp[0].minor);
}
// 2447 "parser.c"
        break;
      case 56:
      case 149:
// 957 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  vv_destructor(55,&vvmsp[0].minor);
}
// 2456 "parser.c"
        break;
      case 57:
// 963 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_macro_call_statement(vvmsp[-8].minor.vv112, vvmsp[-6].minor.vv112, vvmsp[-3].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-10].minor);
  vv_destructor(56,&vvmsp[-9].minor);
  vv_destructor(29,&vvmsp[-7].minor);
  vv_destructor(48,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(57,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2471 "parser.c"
        break;
      case 58:
// 967 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_macro_call_statement(vvmsp[-6].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-8].minor);
  vv_destructor(56,&vvmsp[-7].minor);
  vv_destructor(29,&vvmsp[-5].minor);
  vv_destructor(48,&vvmsp[-4].minor);
  vv_destructor(32,&vvmsp[-3].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(57,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2486 "parser.c"
        break;
      case 59:
// 973 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_empty_statement(status->scanner_state);
  vv_destructor(1,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2495 "parser.c"
        break;
      case 60:
// 979 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_echo_statement(vvmsp[-1].minor.vv112, status->scanner_state);
  vv_destructor(58,&vvmsp[-2].minor);
  vv_destructor(59,&vvmsp[0].minor);
}
// 2504 "parser.c"
        break;
      case 61:
// 985 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_block_statement(vvmsp[-5].minor.vv0, vvmsp[-3].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(60,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(61,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2517 "parser.c"
        break;
      case 62:
// 989 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_block_statement(vvmsp[-4].minor.vv0, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-6].minor);
  vv_destructor(60,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-3].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(61,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2530 "parser.c"
        break;
      case 63:
// 995 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_cache_statement(vvmsp[-5].minor.vv112, NULL, vvmsp[-3].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(62,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(63,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2543 "parser.c"
        break;
      case 64:
// 999 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_cache_statement(vvmsp[-6].minor.vv112, vvmsp[-5].minor.vv112, vvmsp[-3].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-8].minor);
  vv_destructor(62,&vvmsp[-7].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(63,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2556 "parser.c"
        break;
      case 67:
// 1015 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_extends_statement(vvmsp[-1].minor.vv0, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(64,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2566 "parser.c"
        break;
      case 68:
// 1021 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_include_statement(vvmsp[-1].minor.vv112, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(65,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2576 "parser.c"
        break;
      case 69:
// 1025 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_include_statement(vvmsp[-3].minor.vv112, vvmsp[-1].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-5].minor);
  vv_destructor(65,&vvmsp[-4].minor);
  vv_destructor(66,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2587 "parser.c"
        break;
      case 70:
// 1031 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_do_statement(vvmsp[-1].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(67,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2597 "parser.c"
        break;
      case 71:
// 1037 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_return_statement(vvmsp[-1].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(68,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2607 "parser.c"
        break;
      case 72:
// 1043 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_autoescape_statement(0, vvmsp[-3].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(69,&vvmsp[-6].minor);
  vv_destructor(54,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(70,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2621 "parser.c"
        break;
      case 73:
// 1047 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_autoescape_statement(1, vvmsp[-3].minor.vv112, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(69,&vvmsp[-6].minor);
  vv_destructor(55,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(70,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2635 "parser.c"
        break;
      case 74:
// 1053 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_break_statement(status->scanner_state);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(71,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2645 "parser.c"
        break;
      case 75:
// 1059 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_continue_statement(status->scanner_state);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(72,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2655 "parser.c"
        break;
      case 76:
// 1065 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, vvmsp[0].minor.vv0, status->scanner_state);
}
// 2662 "parser.c"
        break;
      case 77:
// 1071 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(22,&vvmsp[-1].minor);
}
// 2670 "parser.c"
        break;
      case 78:
// 1075 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_PLUS, NULL, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(21,&vvmsp[-1].minor);
}
// 2678 "parser.c"
        break;
      case 79:
// 1079 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_SUB, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(22,&vvmsp[-1].minor);
}
// 2686 "parser.c"
        break;
      case 80:
// 1083 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_ADD, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(21,&vvmsp[-1].minor);
}
// 2694 "parser.c"
        break;
      case 81:
// 1087 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_MUL, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(19,&vvmsp[-1].minor);
}
// 2702 "parser.c"
        break;
      case 82:
// 1091 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_POW, vvmsp[-3].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(19,&vvmsp[-2].minor);
  vv_destructor(19,&vvmsp[-1].minor);
}
// 2711 "parser.c"
        break;
      case 83:
// 1095 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_DIV, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(18,&vvmsp[-1].minor);
}
// 2719 "parser.c"
        break;
      case 84:
// 1099 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_MOD, vvmsp[-3].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(18,&vvmsp[-2].minor);
  vv_destructor(18,&vvmsp[-1].minor);
}
// 2728 "parser.c"
        break;
      case 85:
// 1103 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_MOD, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(20,&vvmsp[-1].minor);
}
// 2736 "parser.c"
        break;
      case 86:
// 1107 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_AND, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(7,&vvmsp[-1].minor);
}
// 2744 "parser.c"
        break;
      case 87:
// 1111 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_OR, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(8,&vvmsp[-1].minor);
}
// 2752 "parser.c"
        break;
      case 88:
// 1115 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_CONCAT, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(23,&vvmsp[-1].minor);
}
// 2760 "parser.c"
        break;
      case 89:
// 1119 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_PIPE, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(25,&vvmsp[-1].minor);
}
// 2768 "parser.c"
        break;
      case 90:
// 1123 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_RANGE, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(6,&vvmsp[-1].minor);
}
// 2776 "parser.c"
        break;
      case 91:
// 1127 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_EQUALS, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(10,&vvmsp[-1].minor);
}
// 2784 "parser.c"
        break;
      case 92:
// 1131 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, vvmsp[-2].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(74,&vvmsp[0].minor);
}
// 2793 "parser.c"
        break;
      case 93:
// 1135 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_ISSET, vvmsp[-2].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(74,&vvmsp[0].minor);
}
// 2802 "parser.c"
        break;
      case 94:
// 1139 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_NOT_ISEMPTY, vvmsp[-2].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(75,&vvmsp[0].minor);
}
// 2811 "parser.c"
        break;
      case 95:
// 1143 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_ISEMPTY, vvmsp[-2].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(75,&vvmsp[0].minor);
}
// 2820 "parser.c"
        break;
      case 96:
// 1147 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_NOT_ISEVEN, vvmsp[-2].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(76,&vvmsp[0].minor);
}
// 2829 "parser.c"
        break;
      case 97:
// 1151 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_ISEVEN, vvmsp[-2].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(76,&vvmsp[0].minor);
}
// 2838 "parser.c"
        break;
      case 98:
// 1155 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_NOT_ISODD, vvmsp[-2].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(77,&vvmsp[0].minor);
}
// 2847 "parser.c"
        break;
      case 99:
// 1159 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_ISODD, vvmsp[-2].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(77,&vvmsp[0].minor);
}
// 2856 "parser.c"
        break;
      case 100:
// 1163 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_NOT_ISNUMERIC, vvmsp[-2].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(78,&vvmsp[0].minor);
}
// 2865 "parser.c"
        break;
      case 101:
// 1167 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_ISNUMERIC, vvmsp[-2].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(78,&vvmsp[0].minor);
}
// 2874 "parser.c"
        break;
      case 102:
// 1171 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_NOT_ISSCALAR, vvmsp[-2].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(79,&vvmsp[0].minor);
}
// 2883 "parser.c"
        break;
      case 103:
// 1175 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_ISSCALAR, vvmsp[-2].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(79,&vvmsp[0].minor);
}
// 2892 "parser.c"
        break;
      case 104:
// 1179 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_NOT_ISITERABLE, vvmsp[-2].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(80,&vvmsp[0].minor);
}
// 2901 "parser.c"
        break;
      case 105:
// 1183 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_ISITERABLE, vvmsp[-2].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(80,&vvmsp[0].minor);
}
// 2910 "parser.c"
        break;
      case 106:
// 1187 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_IS, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
}
// 2918 "parser.c"
        break;
      case 107:
// 1191 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
}
// 2926 "parser.c"
        break;
      case 108:
// 1195 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(16,&vvmsp[-1].minor);
}
// 2934 "parser.c"
        break;
      case 109:
// 1199 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(17,&vvmsp[-1].minor);
}
// 2942 "parser.c"
        break;
      case 110:
// 1203 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_LESS, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(12,&vvmsp[-1].minor);
}
// 2950 "parser.c"
        break;
      case 111:
// 1207 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_GREATER, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(13,&vvmsp[-1].minor);
}
// 2958 "parser.c"
        break;
      case 112:
// 1211 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(14,&vvmsp[-1].minor);
}
// 2966 "parser.c"
        break;
      case 113:
// 1215 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(15,&vvmsp[-1].minor);
}
// 2974 "parser.c"
        break;
      case 115:
// 1223 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_IN, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(3,&vvmsp[-1].minor);
}
// 2982 "parser.c"
        break;
      case 116:
// 1227 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_NOT_IN, vvmsp[-3].minor.vv112, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(26,&vvmsp[-2].minor);
  vv_destructor(3,&vvmsp[-1].minor);
}
// 2991 "parser.c"
        break;
      case 117:
// 1231 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, vvmsp[0].minor.vv112, NULL, status->scanner_state);
  vv_destructor(26,&vvmsp[-1].minor);
}
// 2999 "parser.c"
        break;
      case 118:
// 1235 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_INCR, vvmsp[-1].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(27,&vvmsp[0].minor);
}
// 3007 "parser.c"
        break;
      case 119:
// 1239 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_DECR, vvmsp[-1].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(28,&vvmsp[0].minor);
}
// 3015 "parser.c"
        break;
      case 120:
// 1243 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, vvmsp[-1].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(29,&vvmsp[-2].minor);
  vv_destructor(48,&vvmsp[0].minor);
}
// 3024 "parser.c"
        break;
      case 121:
// 1247 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  vv_destructor(24,&vvmsp[-1].minor);
  vv_destructor(46,&vvmsp[0].minor);
}
// 3033 "parser.c"
        break;
      case 122:
// 1251 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_ARRAY, vvmsp[-1].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(24,&vvmsp[-2].minor);
  vv_destructor(46,&vvmsp[0].minor);
}
// 3042 "parser.c"
        break;
      case 123:
// 1255 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  vv_destructor(81,&vvmsp[-1].minor);
  vv_destructor(82,&vvmsp[0].minor);
}
// 3051 "parser.c"
        break;
      case 124:
// 1259 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_ARRAY, vvmsp[-1].minor.vv112, NULL, NULL, status->scanner_state);
  vv_destructor(81,&vvmsp[-2].minor);
  vv_destructor(82,&vvmsp[0].minor);
}
// 3060 "parser.c"
        break;
      case 126:
// 1267 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_expr(PHVOLT_T_TERNARY, vvmsp[-2].minor.vv112, vvmsp[0].minor.vv112, vvmsp[-4].minor.vv112, status->scanner_state);
  vv_destructor(4,&vvmsp[-3].minor);
  vv_destructor(5,&vvmsp[-1].minor);
}
// 3069 "parser.c"
        break;
      case 127:
// 1271 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_slice(vvmsp[-4].minor.vv112, NULL, vvmsp[-1].minor.vv112, status->scanner_state);
  vv_destructor(24,&vvmsp[-3].minor);
  vv_destructor(5,&vvmsp[-2].minor);
  vv_destructor(46,&vvmsp[0].minor);
}
// 3079 "parser.c"
        break;
      case 128:
// 1275 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_slice(vvmsp[-4].minor.vv112, vvmsp[-2].minor.vv112, NULL, status->scanner_state);
  vv_destructor(24,&vvmsp[-3].minor);
  vv_destructor(5,&vvmsp[-1].minor);
  vv_destructor(46,&vvmsp[0].minor);
}
// 3089 "parser.c"
        break;
      case 129:
// 1279 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_slice(vvmsp[-5].minor.vv112, vvmsp[-3].minor.vv112, vvmsp[-1].minor.vv112, status->scanner_state);
  vv_destructor(24,&vvmsp[-4].minor);
  vv_destructor(5,&vvmsp[-2].minor);
  vv_destructor(46,&vvmsp[0].minor);
}
// 3099 "parser.c"
        break;
      case 134:
      case 142:
// 1305 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_named_item(vvmsp[-2].minor.vv0, vvmsp[0].minor.vv112, status->scanner_state);
  vv_destructor(5,&vvmsp[-1].minor);
}
// 3108 "parser.c"
        break;
      case 135:
      case 141:
// 1309 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_named_item(NULL, vvmsp[0].minor.vv112, status->scanner_state);
}
// 3116 "parser.c"
        break;
      case 137:
// 1319 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_func_call(vvmsp[-3].minor.vv112, vvmsp[-1].minor.vv112, status->scanner_state);
  vv_destructor(29,&vvmsp[-2].minor);
  vv_destructor(48,&vvmsp[0].minor);
}
// 3125 "parser.c"
        break;
      case 138:
// 1323 "parser.lemon"
{
	vvgotominor.vv112 = phvolt_ret_func_call(vvmsp[-2].minor.vv112, NULL, status->scanner_state);
  vv_destructor(29,&vvmsp[-1].minor);
  vv_destructor(48,&vvmsp[0].minor);
}
// 3134 "parser.c"
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
// 602 "parser.lemon"

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

// 3274 "parser.c"
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
