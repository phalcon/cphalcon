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

static zval *phvolt_ret_raw_statement(zval *statement, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_RAW);
	add_assoc_zval(ret, "content", statement);

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

static zval *phvolt_ret_extends_statement(zval *path, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	add_assoc_long(ret, "type", PHVOLT_T_EXTENDS);
	add_assoc_zval(ret, "path", path);	

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


// 584 "parser.c"
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
#define VVNOCODE 125
#define VVACTIONTYPE unsigned short int
#define phvolt_TOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_TOKENTYPE vv0;
  zval* vv40;
  int vv249;
} VVMINORTYPE;
#define VVSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = vvpParser->status
#define phvolt_ARG_STORE vvpParser->status = status
#define VVNSTATE 348
#define VVNRULE 152
#define VVERRORSYMBOL 85
#define VVERRSYMDT vv249
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
 /*     0 */    83,   93,  109,   61,   53,   55,   67,   63,   65,   73,
 /*    10 */    75,   77,   79,   69,   71,   49,   47,   51,   44,   41,
 /*    20 */    57,   90,   59,   85,   88,   89,   97,   81,   86,  231,
 /*    30 */    85,   88,   89,   97,   81,  286,   44,   41,   57,   90,
 /*    40 */    59,   85,   88,   89,   97,   81,  108,  285,  180,  201,
 /*    50 */   184,   83,   93,  182,   61,   53,   55,   67,   63,   65,
 /*    60 */    73,   75,   77,   79,   69,   71,   49,   47,   51,   44,
 /*    70 */    41,   57,   90,   59,   85,   88,   89,   97,   81,  223,
 /*    80 */   251,   83,   93,  181,   61,   53,   55,   67,   63,   65,
 /*    90 */    73,   75,   77,   79,   69,   71,   49,   47,   51,   44,
 /*   100 */    41,   57,   90,   59,   85,   88,   89,   97,   81,  314,
 /*   110 */   174,  321,  172,   37,   83,   93,  252,   61,   53,   55,
 /*   120 */    67,   63,   65,   73,   75,   77,   79,   69,   71,   49,
 /*   130 */    47,   51,   44,   41,   57,   90,   59,   85,   88,   89,
 /*   140 */    97,   81,  330,  325,   83,   93,  228,   61,   53,   55,
 /*   150 */    67,   63,   65,   73,   75,   77,   79,   69,   71,   49,
 /*   160 */    47,   51,   44,   41,   57,   90,   59,   85,   88,   89,
 /*   170 */    97,   81,  279,  260,   83,   93,   95,   61,   53,   55,
 /*   180 */    67,   63,   65,   73,   75,   77,   79,   69,   71,   49,
 /*   190 */    47,   51,   44,   41,   57,   90,   59,   85,   88,   89,
 /*   200 */    97,   81,   83,   93,  302,   61,   53,   55,   67,   63,
 /*   210 */    65,   73,   75,   77,   79,   69,   71,   49,   47,   51,
 /*   220 */    44,   41,   57,   90,   59,   85,   88,   89,   97,   81,
 /*   230 */    49,   47,   51,   44,   41,   57,   90,   59,   85,   88,
 /*   240 */    89,   97,   81,  304,  295,  313,  199,  103,  109,  346,
 /*   250 */   296,   83,   93,  205,   61,   53,   55,   67,   63,   65,
 /*   260 */    73,   75,   77,   79,   69,   71,   49,   47,   51,   44,
 /*   270 */    41,   57,   90,   59,   85,   88,   89,   97,   81,  129,
 /*   280 */   316,   83,   93,  145,   61,   53,   55,   67,   63,   65,
 /*   290 */    73,   75,   77,   79,   69,   71,   49,   47,   51,   44,
 /*   300 */    41,   57,   90,   59,   85,   88,   89,   97,   81,   90,
 /*   310 */    59,   85,   88,   89,   97,   81,  307,  308,  309,  310,
 /*   320 */   311,  312,  183,  184,   92,  215,  262,  273,   83,   93,
 /*   330 */   113,   61,   53,   55,   67,   63,   65,   73,   75,   77,
 /*   340 */    79,   69,   71,   49,   47,   51,   44,   41,   57,   90,
 /*   350 */    59,   85,   88,   89,   97,   81,  140,  140,  224,  271,
 /*   360 */   284,   56,   91,  235,  143,  102,  216,  344,  139,  139,
 /*   370 */   414,  197,  141,  118,  118,   83,   93,  118,   61,   53,
 /*   380 */    55,   67,   63,   65,   73,   75,   77,   79,   69,   71,
 /*   390 */    49,   47,   51,   44,   41,   57,   90,   59,   85,   88,
 /*   400 */    89,   97,   81,  171,   40,   83,   93,  415,   61,   53,
 /*   410 */    55,   67,   63,   65,   73,   75,   77,   79,   69,   71,
 /*   420 */    49,   47,   51,   44,   41,   57,   90,   59,   85,   88,
 /*   430 */    89,   97,   81,  237,   27,   83,   93,  481,   61,   53,
 /*   440 */    55,   67,   63,   65,   73,   75,   77,   79,   69,   71,
 /*   450 */    49,   47,   51,   44,   41,   57,   90,   59,   85,   88,
 /*   460 */    89,   97,   81,   83,   93,  320,   61,   53,   55,   67,
 /*   470 */    63,   65,   73,   75,   77,   79,   69,   71,   49,   47,
 /*   480 */    51,   44,   41,   57,   90,   59,   85,   88,   89,   97,
 /*   490 */    81,  240,  332,   83,   93,  289,   61,   53,   55,   67,
 /*   500 */    63,   65,   73,   75,   77,   79,   69,   71,   49,   47,
 /*   510 */    51,   44,   41,   57,   90,   59,   85,   88,   89,   97,
 /*   520 */    81,  200,  248,   83,   93,  169,   61,   53,   55,   67,
 /*   530 */    63,   65,   73,   75,   77,   79,   69,   71,   49,   47,
 /*   540 */    51,   44,   41,   57,   90,   59,   85,   88,   89,   97,
 /*   550 */    81,  291,  254,   83,   93,  280,   61,   53,   55,   67,
 /*   560 */    63,   65,   73,   75,   77,   79,   69,   71,   49,   47,
 /*   570 */    51,   44,   41,   57,   90,   59,   85,   88,   89,   97,
 /*   580 */    81,  339,  257,   83,   93,  292,   61,   53,   55,   67,
 /*   590 */    63,   65,   73,   75,   77,   79,   69,   71,   49,   47,
 /*   600 */    51,   44,   41,   57,   90,   59,   85,   88,   89,  213,
 /*   610 */    81,   83,   93,  293,   61,   53,   55,   67,   63,   65,
 /*   620 */    73,   75,   77,   79,   69,   71,   49,   47,   51,   44,
 /*   630 */    41,   57,   90,   59,   85,   88,   89,   97,   81,   93,
 /*   640 */   322,   61,   53,   55,   67,   63,   65,   73,   75,   77,
 /*   650 */    79,   69,   71,   49,   47,   51,   44,   41,   57,   90,
 /*   660 */    59,   85,   88,   89,   97,   81,   61,   53,   55,   67,
 /*   670 */    63,   65,   73,   75,   77,   79,   69,   71,   49,   47,
 /*   680 */    51,   44,   41,   57,   90,   59,   85,   88,   89,   97,
 /*   690 */    81,   53,   55,   67,   63,   65,   73,   75,   77,   79,
 /*   700 */    69,   71,   49,   47,   51,   44,   41,   57,   90,   59,
 /*   710 */    85,   88,   89,   97,   81,  501,    1,    2,  272,    4,
 /*   720 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   730 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   28,
 /*   740 */   272,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   750 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   760 */    23,  207,  272,    4,    5,    6,    7,    8,    9,   10,
 /*   770 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   780 */    21,   22,   23,   67,   63,   65,   73,   75,   77,   79,
 /*   790 */    69,   71,   49,   47,   51,   44,   41,   57,   90,   59,
 /*   800 */    85,   88,   89,   97,   81,  232,  272,    4,    5,    6,
 /*   810 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   820 */    17,   18,   19,   20,   21,   22,   23,  264,  272,    4,
 /*   830 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   840 */    15,   16,   17,   18,   19,   20,   21,   22,   23,  217,
 /*   850 */   272,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   860 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   870 */    23,  281,  272,    4,    5,    6,    7,    8,    9,   10,
 /*   880 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   890 */    21,   22,   23,  275,  272,    4,    5,    6,    7,    8,
 /*   900 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   910 */    19,   20,   21,   22,   23,  333,  272,    4,    5,    6,
 /*   920 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   930 */    17,   18,   19,   20,   21,   22,   23,  175,  272,    4,
 /*   940 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   950 */    15,   16,   17,   18,   19,   20,   21,   22,   23,  298,
 /*   960 */   272,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   970 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   980 */    23,  317,  272,    4,    5,    6,    7,    8,    9,   10,
 /*   990 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*  1000 */    21,   22,   23,  326,  272,    4,    5,    6,    7,    8,
 /*  1010 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*  1020 */    19,   20,   21,   22,   23,   34,  272,    4,    5,    6,
 /*  1030 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*  1040 */    17,   18,   19,   20,   21,   22,   23,  225,  272,    4,
 /*  1050 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*  1060 */    15,   16,   17,   18,   19,   20,   21,   22,   23,    3,
 /*  1070 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*  1080 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*  1090 */   241,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*  1100 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*  1110 */    23,   25,  221,  341,  343,   38,  168,  170,   98,  294,
 /*  1120 */   179,  349,   24,  105,  480,  127,   98,  202,  242,   24,
 /*  1130 */   118,  135,  107,  214,  114,  118,  211,  340,  118,  135,
 /*  1140 */   222,  263,  229,   26,  236,  105,  246,  249,  167,  255,
 /*  1150 */   258,  261,  196,  268,  270,  118,  126,  118,   45,   42,
 /*  1160 */   118,  104,   70,   99,  118,   29,  101,  243,   45,   42,
 /*  1170 */   117,  104,  105,   99,  118,  119,  101,  323,  297,  238,
 /*  1180 */   336,  112,  118,  114,  118,  119,  238,  120,  121,  122,
 /*  1190 */   123,  124,  125,   98,  238,  239,  245,  120,  121,  122,
 /*  1200 */   123,  124,  125,  245,  337,  118,  130,  118,  176,   68,
 /*  1210 */   345,  245,  129,  155,  156,  157,  158,  159,  160,  161,
 /*  1220 */   110,  118,  238,  148,  149,  150,  151,  152,  153,  154,
 /*  1230 */   110,   25,  221,   30,   32,   38,  168,  170,  244,  245,
 /*  1240 */   179,   58,  173,  247,  348,   54,  203,  202,  204,  301,
 /*  1250 */   481,  304,  342,  118,  118,  118,  211,  118,  128,   31,
 /*  1260 */   222,  238,  229,   35,  236,  238,  246,  249,  208,  255,
 /*  1270 */   258,  261,  218,  268,  270,   33,  303,  250,  245,   25,
 /*  1280 */   221,  195,  245,   38,  168,  170,  206,  198,  179,  118,
 /*  1290 */   287,  137,  305,   72,   39,  202,  144,  306,  185,  187,
 /*  1300 */   189,  191,  193,  116,  211,  118,  118,  138,  222,  227,
 /*  1310 */   229,  226,  236,  178,  246,  249,  233,  255,  258,  261,
 /*  1320 */   238,  268,  270,  347,  220,  238,  274,   25,  221,  238,
 /*  1330 */   132,   38,  168,  170,  210,  265,  179,  245,  276,  253,
 /*  1340 */   267,  212,  245,  202,  142,  256,  245,  238,  282,  480,
 /*  1350 */   329,  118,  211,  118,  278,  269,  222,  118,  229,  234,
 /*  1360 */   236,  278,  246,  249,  245,  255,  258,  261,  238,  268,
 /*  1370 */   270,  278,  278,  238,  278,   25,  221,   36,  278,   38,
 /*  1380 */   168,  170,  278,  299,  179,  245,  318,  278,  278,   64,
 /*  1390 */   245,  202,  238,  278,  327,  238,  334,  278,  278,  278,
 /*  1400 */   211,  118,  278,  278,  222,  238,  229,  278,  236,  245,
 /*  1410 */   246,  249,  245,  255,  258,  261,  278,  268,  270,  278,
 /*  1420 */   278,  163,  245,   25,  221,  278,  315,   38,  168,  170,
 /*  1430 */   259,  335,  179,  118,  278,  278,  278,  278,  118,  202,
 /*  1440 */   238,  278,  118,  238,  278,  278,  278,  278,  211,  278,
 /*  1450 */   278,  238,  222,  238,  229,  278,  236,  245,  246,  249,
 /*  1460 */   245,  255,  258,  261,  278,  268,  270,   76,  245,   66,
 /*  1470 */   245,   25,  221,   62,  324,   38,  168,  170,  165,  118,
 /*  1480 */   179,  118,  278,  278,  278,  118,  118,  202,  278,  278,
 /*  1490 */   118,   52,  278,  278,  278,  278,  211,  219,  278,  278,
 /*  1500 */   222,  278,  229,  118,  236,  278,  246,  249,  278,  255,
 /*  1510 */   258,  261,  278,  268,  270,  186,  278,  133,  278,   25,
 /*  1520 */   221,   50,  331,   38,  168,  170,  188,  118,  179,  118,
 /*  1530 */   278,  278,  278,  118,  118,  202,  278,   60,  118,  278,
 /*  1540 */   278,   87,  278,  278,  211,  278,  278,  278,  222,  118,
 /*  1550 */   229,  283,  236,  118,  246,  249,  278,  255,  258,  261,
 /*  1560 */   278,  268,  270,   48,  278,  190,  278,   25,  221,   46,
 /*  1570 */   192,   38,  168,  170,  166,  118,  179,  118,   94,   84,
 /*  1580 */   278,  118,  118,  202,  278,   96,  118,  230,  278,   74,
 /*  1590 */   118,  118,  211,  278,  278,  278,  222,  118,  229,  118,
 /*  1600 */   236,  118,  246,  249,  278,  255,  258,  261,  277,  268,
 /*  1610 */   270,   82,  278,   80,  194,   25,  221,  338,  100,   38,
 /*  1620 */   168,  170,   78,  118,  179,  118,  118,  278,  278,  278,
 /*  1630 */   118,  202,  278,   43,  118,  278,  278,  278,  278,  278,
 /*  1640 */   211,  278,  278,  278,  222,  118,  229,  278,  236,  278,
 /*  1650 */   246,  249,  278,  255,  258,  261,  278,  268,  270,  278,
 /*  1660 */   278,  278,  278,   25,  221,  278,  278,   38,  168,  170,
 /*  1670 */   278,  278,  179,  278,  278,  278,  278,  278,  278,  202,
 /*  1680 */   278,  209,  278,  278,  278,  278,  278,  278,  211,  278,
 /*  1690 */   278,  278,  222,  278,  229,  278,  236,  278,  246,  249,
 /*  1700 */   278,  255,  258,  261,  278,  268,  270,  278,  278,  278,
 /*  1710 */   278,   25,  221,  278,  278,   38,  168,  170,  278,  278,
 /*  1720 */   179,  278,  278,  278,  278,  278,  278,  202,  278,  278,
 /*  1730 */   278,  278,  278,  278,  278,  278,  211,  278,  278,  278,
 /*  1740 */   222,  288,  229,  278,  236,  278,  246,  249,  278,  255,
 /*  1750 */   258,  261,  278,  268,  270,  278,  278,  278,  278,   25,
 /*  1760 */   221,  278,  278,   38,  168,  170,  278,  278,  179,  278,
 /*  1770 */   278,  278,  278,  278,  278,  202,  278,  278,  278,  278,
 /*  1780 */   278,  278,  278,  278,  211,  278,  278,  278,  222,  278,
 /*  1790 */   229,  278,  236,  278,  246,  249,  278,  255,  258,  261,
 /*  1800 */   266,  268,  270,  278,  278,  278,  278,   25,  221,  278,
 /*  1810 */   278,   38,  168,  170,  278,  328,  179,  278,  278,  278,
 /*  1820 */   278,  278,  278,  202,  278,  278,  278,  278,  278,  278,
 /*  1830 */   278,  278,  211,  278,  278,  278,  222,  278,  229,  278,
 /*  1840 */   236,  278,  246,  249,  278,  255,  258,  261,  278,  268,
 /*  1850 */   270,  278,  278,  278,  278,   25,  221,  278,  278,   38,
 /*  1860 */   168,  170,  278,  278,  179,  278,  278,  278,  278,  278,
 /*  1870 */   278,  202,  278,  300,  278,  278,  278,  278,  278,  278,
 /*  1880 */   211,  278,  278,  278,  222,  278,  229,  278,  236,  278,
 /*  1890 */   246,  249,  278,  255,  258,  261,  278,  268,  270,  278,
 /*  1900 */   278,  278,  278,   25,  221,  278,  278,   38,  168,  170,
 /*  1910 */   278,  177,  179,  278,  278,  278,  278,  278,  278,  202,
 /*  1920 */   278,  278,  278,  278,  278,  278,  278,  278,  211,  278,
 /*  1930 */   278,  278,  222,  278,  229,  278,  236,  278,  246,  249,
 /*  1940 */   278,  255,  258,  261,  278,  268,  270,  278,  278,  278,
 /*  1950 */   278,   25,  221,  278,  278,   38,  168,  170,  278,  319,
 /*  1960 */   179,  278,  278,  278,  278,  278,  278,  202,  278,  278,
 /*  1970 */   278,  278,  278,  278,  278,  278,  211,  278,  278,  278,
 /*  1980 */   222,  278,  229,  278,  236,  278,  246,  249,  278,  255,
 /*  1990 */   258,  261,  278,  268,  270,  278,  278,  278,  278,   25,
 /*  2000 */   221,  278,  278,   38,  168,  170,  278,  278,  179,  278,
 /*  2010 */   278,  278,  278,  278,  278,  202,  278,  278,  278,  278,
 /*  2020 */   278,  278,  278,  278,  211,  278,  278,  278,  222,  278,
 /*  2030 */   229,  278,  236,  278,  246,  249,  278,  255,  258,  261,
 /*  2040 */   278,  268,  270,  278,  164,  278,   45,   42,  278,  104,
 /*  2050 */   136,   99,  278,  162,  101,  278,   45,   42,  278,  104,
 /*  2060 */   278,   99,  278,  119,  101,  278,   45,   42,  278,  104,
 /*  2070 */   278,   99,  278,  119,  101,  120,  121,  122,  123,  124,
 /*  2080 */   125,  278,  278,  147,  278,  120,  121,  122,  123,  124,
 /*  2090 */   125,  278,  278,  278,  278,  146,  121,  122,  123,  124,
 /*  2100 */   125,  278,   45,   42,  278,  104,  278,   99,  110,  278,
 /*  2110 */   101,  278,   45,   42,  278,  104,  278,   99,  110,  119,
 /*  2120 */   101,  278,  278,  278,  278,  278,  278,  106,  110,  119,
 /*  2130 */   278,  120,  115,  122,  123,  124,  125,  278,  278,  134,
 /*  2140 */   278,  120,  131,  122,  123,  124,  125,  278,  278,   45,
 /*  2150 */    42,  278,  104,  278,   99,   45,   42,  101,  104,  278,
 /*  2160 */    99,  278,  278,  101,  110,  278,  119,  278,  278,  278,
 /*  2170 */   278,  278,  119,  278,  110,  278,  290,  278,  120,  131,
 /*  2180 */   122,  123,  124,  125,  120,  115,  122,  123,  124,  125,
 /*  2190 */   278,  278,  278,  278,  278,  278,   45,   42,  278,  104,
 /*  2200 */   278,   99,   45,   42,  101,  104,  278,   99,  278,  278,
 /*  2210 */   101,  110,  278,  119,  278,  278,  278,  110,  111,  119,
 /*  2220 */   278,  278,  278,  278,  278,  120,  121,  122,  123,  124,
 /*  2230 */   125,  120,  115,  122,  123,  124,  125,  278,  278,   45,
 /*  2240 */    42,  278,  104,  278,   99,  278,  278,  101,  278,  278,
 /*  2250 */   278,  278,  278,  278,  278,  278,  119,  278,  110,  278,
 /*  2260 */   278,  278,  278,  278,  110,  278,  278,  278,  120,  131,
 /*  2270 */   122,  123,  124,  125,  278,  278,  278,  278,  278,  278,
 /*  2280 */   278,  278,  278,  278,  278,  278,  278,  278,  278,  278,
 /*  2290 */   278,  278,  278,  278,  278,  278,  278,  278,  278,  278,
 /*  2300 */   278,  110,
};
static VVCODETYPE vv_lookahead[] = {
 /*     0 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*    10 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    20 */    23,   24,   25,   26,   27,   28,   29,   30,    3,   32,
 /*    30 */    26,   27,   28,   29,   30,   38,   21,   22,   23,   24,
 /*    40 */    25,   26,   27,   28,   29,   30,   46,   50,  111,  112,
 /*    50 */   113,    3,    4,    2,    6,    7,    8,    9,   10,   11,
 /*    60 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*    70 */    22,   23,   24,   25,   26,   27,   28,   29,   30,   38,
 /*    80 */    32,    3,    4,   32,    6,    7,    8,    9,   10,   11,
 /*    90 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   100 */    22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
 /*   110 */    32,    2,    3,   32,    3,    4,   68,    6,    7,    8,
 /*   120 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   130 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   140 */    29,   30,   31,   32,    3,    4,   32,    6,    7,    8,
 /*   150 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   160 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   170 */    29,   30,  118,   32,    3,    4,    5,    6,    7,    8,
 /*   180 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   190 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   200 */    29,   30,    3,    4,    2,    6,    7,    8,    9,   10,
 /*   210 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   220 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
 /*   230 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   240 */    28,   29,   30,   38,  114,  115,   38,   48,    2,   33,
 /*   250 */    48,    3,    4,   48,    6,    7,    8,    9,   10,   11,
 /*   260 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   270 */    22,   23,   24,   25,   26,   27,   28,   29,   30,    2,
 /*   280 */    32,    3,    4,   46,    6,    7,    8,    9,   10,   11,
 /*   290 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   300 */    22,   23,   24,   25,   26,   27,   28,   29,   30,   24,
 /*   310 */    25,   26,   27,   28,   29,   30,   50,   51,   52,   53,
 /*   320 */    54,   55,  112,  113,   46,   48,   54,   55,    3,    4,
 /*   330 */    84,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   340 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   350 */    25,   26,   27,   28,   29,   30,   38,   38,   32,   32,
 /*   360 */    32,  110,  110,   32,   46,  110,   32,   32,   50,   50,
 /*   370 */    32,   46,  120,  122,  122,    3,    4,  122,    6,    7,
 /*   380 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   390 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   400 */    28,   29,   30,   38,   32,    3,    4,   32,    6,    7,
 /*   410 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   420 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   430 */    28,   29,   30,   32,   32,    3,    4,   46,    6,    7,
 /*   440 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   450 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   460 */    28,   29,   30,    3,    4,   32,    6,    7,    8,    9,
 /*   470 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   480 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   490 */    30,   59,   32,    3,    4,   32,    6,    7,    8,    9,
 /*   500 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   510 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   520 */    30,  113,   32,    3,    4,   32,    6,    7,    8,    9,
 /*   530 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   540 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   550 */    30,   32,   32,    3,    4,   32,    6,    7,    8,    9,
 /*   560 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   570 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   580 */    30,   32,   32,    3,    4,    1,    6,    7,    8,    9,
 /*   590 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   600 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   610 */    30,    3,    4,   57,    6,    7,    8,    9,   10,   11,
 /*   620 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   630 */    22,   23,   24,   25,   26,   27,   28,   29,   30,    4,
 /*   640 */    38,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   650 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   660 */    25,   26,   27,   28,   29,   30,    6,    7,    8,    9,
 /*   670 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   680 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   690 */    30,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   700 */    16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
 /*   710 */    26,   27,   28,   29,   30,   86,   87,   88,   89,   90,
 /*   720 */    91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
 /*   730 */   101,  102,  103,  104,  105,  106,  107,  108,  109,   88,
 /*   740 */    89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
 /*   750 */    99,  100,  101,  102,  103,  104,  105,  106,  107,  108,
 /*   760 */   109,   88,   89,   90,   91,   92,   93,   94,   95,   96,
 /*   770 */    97,   98,   99,  100,  101,  102,  103,  104,  105,  106,
 /*   780 */   107,  108,  109,    9,   10,   11,   12,   13,   14,   15,
 /*   790 */    16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
 /*   800 */    26,   27,   28,   29,   30,   88,   89,   90,   91,   92,
 /*   810 */    93,   94,   95,   96,   97,   98,   99,  100,  101,  102,
 /*   820 */   103,  104,  105,  106,  107,  108,  109,   88,   89,   90,
 /*   830 */    91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
 /*   840 */   101,  102,  103,  104,  105,  106,  107,  108,  109,   88,
 /*   850 */    89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
 /*   860 */    99,  100,  101,  102,  103,  104,  105,  106,  107,  108,
 /*   870 */   109,   88,   89,   90,   91,   92,   93,   94,   95,   96,
 /*   880 */    97,   98,   99,  100,  101,  102,  103,  104,  105,  106,
 /*   890 */   107,  108,  109,   88,   89,   90,   91,   92,   93,   94,
 /*   900 */    95,   96,   97,   98,   99,  100,  101,  102,  103,  104,
 /*   910 */   105,  106,  107,  108,  109,   88,   89,   90,   91,   92,
 /*   920 */    93,   94,   95,   96,   97,   98,   99,  100,  101,  102,
 /*   930 */   103,  104,  105,  106,  107,  108,  109,   88,   89,   90,
 /*   940 */    91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
 /*   950 */   101,  102,  103,  104,  105,  106,  107,  108,  109,   88,
 /*   960 */    89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
 /*   970 */    99,  100,  101,  102,  103,  104,  105,  106,  107,  108,
 /*   980 */   109,   88,   89,   90,   91,   92,   93,   94,   95,   96,
 /*   990 */    97,   98,   99,  100,  101,  102,  103,  104,  105,  106,
 /*  1000 */   107,  108,  109,   88,   89,   90,   91,   92,   93,   94,
 /*  1010 */    95,   96,   97,   98,   99,  100,  101,  102,  103,  104,
 /*  1020 */   105,  106,  107,  108,  109,   88,   89,   90,   91,   92,
 /*  1030 */    93,   94,   95,   96,   97,   98,   99,  100,  101,  102,
 /*  1040 */   103,  104,  105,  106,  107,  108,  109,   88,   89,   90,
 /*  1050 */    91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
 /*  1060 */   101,  102,  103,  104,  105,  106,  107,  108,  109,   89,
 /*  1070 */    90,   91,   92,   93,   94,   95,   96,   97,   98,   99,
 /*  1080 */   100,  101,  102,  103,  104,  105,  106,  107,  108,  109,
 /*  1090 */    89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
 /*  1100 */    99,  100,  101,  102,  103,  104,  105,  106,  107,  108,
 /*  1110 */   109,   31,   32,   33,   34,   35,   36,   37,  110,   32,
 /*  1120 */    40,    0,    1,  110,    5,  117,  110,   47,    1,    1,
 /*  1130 */   122,  123,  119,  117,  121,  122,   56,    1,  122,  123,
 /*  1140 */    60,   32,   62,  110,   64,  110,   66,   67,  110,   69,
 /*  1150 */    70,   71,  110,   73,   74,  122,  121,  122,   21,   22,
 /*  1160 */   122,   24,  110,   26,  122,    1,   29,   65,   21,   22,
 /*  1170 */   110,   24,  110,   26,  122,   38,   29,    3,   32,   58,
 /*  1180 */    32,  119,  122,  121,  122,   38,   58,   50,   51,   52,
 /*  1190 */    53,   54,   55,  110,   58,  110,   75,   50,   51,   52,
 /*  1200 */    53,   54,   55,   75,    1,  122,  123,  122,    1,  110,
 /*  1210 */     1,   75,    2,   76,   77,   78,   79,   80,   81,   82,
 /*  1220 */    83,  122,   58,   76,   77,   78,   79,   80,   81,   82,
 /*  1230 */    83,   31,   32,   33,   34,   35,   36,   37,   32,   75,
 /*  1240 */    40,  110,  110,  110,    0,  110,   38,   47,   29,   32,
 /*  1250 */     5,   38,   32,  122,  122,  122,   56,  122,   48,   32,
 /*  1260 */    60,   58,   62,    1,   64,   58,   66,   67,    1,   69,
 /*  1270 */    70,   71,    1,   73,   74,   32,  115,  110,   75,   31,
 /*  1280 */    32,   24,   75,   35,   36,   37,   32,   30,   40,  122,
 /*  1290 */     1,  120,   41,  110,  110,   47,  120,  116,   41,   42,
 /*  1300 */    43,   44,   45,    5,   56,  122,  122,   46,   60,   61,
 /*  1310 */    62,    1,   64,   32,   66,   67,    1,   69,   70,   71,
 /*  1320 */    58,   73,   74,   32,   32,   58,   32,   31,   32,   58,
 /*  1330 */     5,   35,   36,   37,   32,    1,   40,   75,    1,  110,
 /*  1340 */    32,  110,   75,   47,    5,  110,   75,   58,    1,   46,
 /*  1350 */    32,  122,   56,  122,   32,   32,   60,  122,   62,   63,
 /*  1360 */    64,  124,   66,   67,   75,   69,   70,   71,   58,   73,
 /*  1370 */    74,  124,  124,   58,  124,   31,   32,   33,  124,   35,
 /*  1380 */    36,   37,  124,    1,   40,   75,    1,  124,  124,  110,
 /*  1390 */    75,   47,   58,  124,    1,   58,    1,  124,  124,  124,
 /*  1400 */    56,  122,  124,  124,   60,   58,   62,  124,   64,   75,
 /*  1410 */    66,   67,   75,   69,   70,   71,  124,   73,   74,  124,
 /*  1420 */   124,  110,   75,   31,   32,  124,  110,   35,   36,   37,
 /*  1430 */   110,   39,   40,  122,  124,  124,  124,  124,  122,   47,
 /*  1440 */    58,  124,  122,   58,  124,  124,  124,  124,   56,  124,
 /*  1450 */   124,   58,   60,   58,   62,  124,   64,   75,   66,   67,
 /*  1460 */    75,   69,   70,   71,  124,   73,   74,  110,   75,  110,
 /*  1470 */    75,   31,   32,  110,  110,   35,   36,   37,  110,  122,
 /*  1480 */    40,  122,  124,  124,  124,  122,  122,   47,  124,  124,
 /*  1490 */   122,  110,  124,  124,  124,  124,   56,   57,  124,  124,
 /*  1500 */    60,  124,   62,  122,   64,  124,   66,   67,  124,   69,
 /*  1510 */    70,   71,  124,   73,   74,  110,  124,  110,  124,   31,
 /*  1520 */    32,  110,  110,   35,   36,   37,  110,  122,   40,  122,
 /*  1530 */   124,  124,  124,  122,  122,   47,  124,  110,  122,  124,
 /*  1540 */   124,  110,  124,  124,   56,  124,  124,  124,   60,  122,
 /*  1550 */    62,   63,   64,  122,   66,   67,  124,   69,   70,   71,
 /*  1560 */   124,   73,   74,  110,  124,  110,  124,   31,   32,  110,
 /*  1570 */   110,   35,   36,   37,  110,  122,   40,  122,  110,  110,
 /*  1580 */   124,  122,  122,   47,  124,  110,  122,  110,  124,  110,
 /*  1590 */   122,  122,   56,  124,  124,  124,   60,  122,   62,  122,
 /*  1600 */    64,  122,   66,   67,  124,   69,   70,   71,   72,   73,
 /*  1610 */    74,  110,  124,  110,  110,   31,   32,   33,  110,   35,
 /*  1620 */    36,   37,  110,  122,   40,  122,  122,  124,  124,  124,
 /*  1630 */   122,   47,  124,  110,  122,  124,  124,  124,  124,  124,
 /*  1640 */    56,  124,  124,  124,   60,  122,   62,  124,   64,  124,
 /*  1650 */    66,   67,  124,   69,   70,   71,  124,   73,   74,  124,
 /*  1660 */   124,  124,  124,   31,   32,  124,  124,   35,   36,   37,
 /*  1670 */   124,  124,   40,  124,  124,  124,  124,  124,  124,   47,
 /*  1680 */   124,   49,  124,  124,  124,  124,  124,  124,   56,  124,
 /*  1690 */   124,  124,   60,  124,   62,  124,   64,  124,   66,   67,
 /*  1700 */   124,   69,   70,   71,  124,   73,   74,  124,  124,  124,
 /*  1710 */   124,   31,   32,  124,  124,   35,   36,   37,  124,  124,
 /*  1720 */    40,  124,  124,  124,  124,  124,  124,   47,  124,  124,
 /*  1730 */   124,  124,  124,  124,  124,  124,   56,  124,  124,  124,
 /*  1740 */    60,   61,   62,  124,   64,  124,   66,   67,  124,   69,
 /*  1750 */    70,   71,  124,   73,   74,  124,  124,  124,  124,   31,
 /*  1760 */    32,  124,  124,   35,   36,   37,  124,  124,   40,  124,
 /*  1770 */   124,  124,  124,  124,  124,   47,  124,  124,  124,  124,
 /*  1780 */   124,  124,  124,  124,   56,  124,  124,  124,   60,  124,
 /*  1790 */    62,  124,   64,  124,   66,   67,  124,   69,   70,   71,
 /*  1800 */    72,   73,   74,  124,  124,  124,  124,   31,   32,  124,
 /*  1810 */   124,   35,   36,   37,  124,   39,   40,  124,  124,  124,
 /*  1820 */   124,  124,  124,   47,  124,  124,  124,  124,  124,  124,
 /*  1830 */   124,  124,   56,  124,  124,  124,   60,  124,   62,  124,
 /*  1840 */    64,  124,   66,   67,  124,   69,   70,   71,  124,   73,
 /*  1850 */    74,  124,  124,  124,  124,   31,   32,  124,  124,   35,
 /*  1860 */    36,   37,  124,  124,   40,  124,  124,  124,  124,  124,
 /*  1870 */   124,   47,  124,   49,  124,  124,  124,  124,  124,  124,
 /*  1880 */    56,  124,  124,  124,   60,  124,   62,  124,   64,  124,
 /*  1890 */    66,   67,  124,   69,   70,   71,  124,   73,   74,  124,
 /*  1900 */   124,  124,  124,   31,   32,  124,  124,   35,   36,   37,
 /*  1910 */   124,   39,   40,  124,  124,  124,  124,  124,  124,   47,
 /*  1920 */   124,  124,  124,  124,  124,  124,  124,  124,   56,  124,
 /*  1930 */   124,  124,   60,  124,   62,  124,   64,  124,   66,   67,
 /*  1940 */   124,   69,   70,   71,  124,   73,   74,  124,  124,  124,
 /*  1950 */   124,   31,   32,  124,  124,   35,   36,   37,  124,   39,
 /*  1960 */    40,  124,  124,  124,  124,  124,  124,   47,  124,  124,
 /*  1970 */   124,  124,  124,  124,  124,  124,   56,  124,  124,  124,
 /*  1980 */    60,  124,   62,  124,   64,  124,   66,   67,  124,   69,
 /*  1990 */    70,   71,  124,   73,   74,  124,  124,  124,  124,   31,
 /*  2000 */    32,  124,  124,   35,   36,   37,  124,  124,   40,  124,
 /*  2010 */   124,  124,  124,  124,  124,   47,  124,  124,  124,  124,
 /*  2020 */   124,  124,  124,  124,   56,  124,  124,  124,   60,  124,
 /*  2030 */    62,  124,   64,  124,   66,   67,  124,   69,   70,   71,
 /*  2040 */   124,   73,   74,  124,   19,  124,   21,   22,  124,   24,
 /*  2050 */     5,   26,  124,   18,   29,  124,   21,   22,  124,   24,
 /*  2060 */   124,   26,  124,   38,   29,  124,   21,   22,  124,   24,
 /*  2070 */   124,   26,  124,   38,   29,   50,   51,   52,   53,   54,
 /*  2080 */    55,  124,  124,   38,  124,   50,   51,   52,   53,   54,
 /*  2090 */    55,  124,  124,  124,  124,   50,   51,   52,   53,   54,
 /*  2100 */    55,  124,   21,   22,  124,   24,  124,   26,   83,  124,
 /*  2110 */    29,  124,   21,   22,  124,   24,  124,   26,   83,   38,
 /*  2120 */    29,  124,  124,  124,  124,  124,  124,   46,   83,   38,
 /*  2130 */   124,   50,   51,   52,   53,   54,   55,  124,  124,   48,
 /*  2140 */   124,   50,   51,   52,   53,   54,   55,  124,  124,   21,
 /*  2150 */    22,  124,   24,  124,   26,   21,   22,   29,   24,  124,
 /*  2160 */    26,  124,  124,   29,   83,  124,   38,  124,  124,  124,
 /*  2170 */   124,  124,   38,  124,   83,  124,   48,  124,   50,   51,
 /*  2180 */    52,   53,   54,   55,   50,   51,   52,   53,   54,   55,
 /*  2190 */   124,  124,  124,  124,  124,  124,   21,   22,  124,   24,
 /*  2200 */   124,   26,   21,   22,   29,   24,  124,   26,  124,  124,
 /*  2210 */    29,   83,  124,   38,  124,  124,  124,   83,   84,   38,
 /*  2220 */   124,  124,  124,  124,  124,   50,   51,   52,   53,   54,
 /*  2230 */    55,   50,   51,   52,   53,   54,   55,  124,  124,   21,
 /*  2240 */    22,  124,   24,  124,   26,  124,  124,   29,  124,  124,
 /*  2250 */   124,  124,  124,  124,  124,  124,   38,  124,   83,  124,
 /*  2260 */   124,  124,  124,  124,   83,  124,  124,  124,   50,   51,
 /*  2270 */    52,   53,   54,   55,  124,  124,  124,  124,  124,  124,
 /*  2280 */   124,  124,  124,  124,  124,  124,  124,  124,  124,  124,
 /*  2290 */   124,  124,  124,  124,  124,  124,  124,  124,  124,  124,
 /*  2300 */   124,   83,
};
#define VV_SHIFT_USE_DFLT (-4)
static short vv_shift_ofst[] = {
 /*     0 */  1128, 1244, 1121,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    20 */    -4,   -4,   -4,   -4, 1968, 2175,  402, 1136, 1164, 1200,
 /*    30 */  1227,   -4, 1243, 1203, 1262, 1344,   81,   -4, 2175,  372,
 /*    40 */    -4, 2175, 2175,  285, 2175, 2175,  285, 2025,   15, 2035,
 /*    50 */    15, 2175,   15, 2175,  774, 2175,  774, 2175,  285, 2175,
 /*    60 */     4, 2175,  684, 2175,  212, 1137,  212, 1147,  212, 2175,
 /*    70 */   212, 2175,  212, 2175,  212, 2175,  212, 2175,  212, 2175,
 /*    80 */   212, 2175,   -4, 2175,  635,   25, 2175,    4,   -4,   -4,
 /*    90 */  2045,  278,   -4, 2175,  171, 2175,  660, 2091,  608, 2175,
 /*   100 */     4, 2175,  199,   -4, 2081,  608,   -4,    0,   -4, 2181,
 /*   110 */  2134,   -4,  246,   -4,   -4, 1298, 2175,  608,   -4,   -4,
 /*   120 */    -4,   -4,   -4,   -4,   -4,   -4,   -4, 1210,   -4, 2218,
 /*   130 */    -4, 1325, 2175,  608,   -4,   -4,  319, 1261,   -4, 1303,
 /*   140 */   391, 1339,  318,   -4,  237,   -4, 1119, 1245,   -4,   -4,
 /*   150 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*   160 */    -4,   -4, 2175,   15, 2175,   15,  285,  285,  493,   -4,
 /*   170 */   365,  109, 2175,   78, 1128, 1207, 1872, 1281,   -4,  208,
 /*   180 */    51,   -4,  208,   -4, 1257, 2175,  608, 2175,  608, 2175,
 /*   190 */   608, 2175,  608, 2175,  608, 2175,  325,   -4,  208,   -4,
 /*   200 */    -4,   -4, 1208, 1219,  205, 1254, 1128, 1267, 1632, 1302,
 /*   210 */    -4, 2175,  580, 2128,  277,  334, 1128, 1271, 1440, 1292,
 /*   220 */    -4,   -4,   41,  326, 1289, 1310, 1248,  114,   -4, 2175,
 /*   230 */    -3, 1128, 1315, 1296,  331,   -4,  401, 1128, 2175,  432,
 /*   240 */    -4, 1127, 1102, 1206,   -4,   -4, 2175,  490,   -4, 2175,
 /*   250 */    48,   -4, 2175,  520,   -4, 2175,  550,   -4, 2175,  141,
 /*   260 */    -4,  272, 1109, 1128, 1334, 1728, 1308,   -4, 1323,   -4,
 /*   270 */   327,   -4,   -4, 1294, 1128, 1337, 1536, 1322,   -4,  523,
 /*   280 */  1128, 1347, 1488,  328,   -4,  338,  375, 1680,  463,   -4,
 /*   290 */   519,  584,  556, 1087,   -4,  202, 1146, 1128, 1382, 1824,
 /*   300 */  1217,   -4, 1213,   -4, 1251,  266,   -4,   -4,   -4,   -4,
 /*   310 */    -4,   -4,   -4,   -4, 2175,  248, 1128, 1385, 1920,  433,
 /*   320 */    -4,  602, 1174, 2175,  111, 1128, 1393, 1776, 1318,   -4,
 /*   330 */  2175,  460, 1128, 1395, 1392, 1148,   -4, 1584,  549,   -4,
 /*   340 */  1080, 1220,   -4,  335, 1209,  216, 1291,   -4,
};
#define VV_REDUCE_USE_DFLT (-64)
static short vv_reduce_ofst[] = {
 /*     0 */   629,  -64,  980,  -64,  -64,  -64,  -64,  -64,  -64,  -64,
 /*    10 */   -64,  -64,  -64,  -64,  -64,  -64,  -64,  -64,  -64,  -64,
 /*    20 */   -64,  -64,  -64,  -64,  -64, 1033,  -64,  651,  980,  -64,
 /*    30 */   -64,  -64,  -64,  937,  980,  -64,  -64,  -64, 1184,  -64,
 /*    40 */   -64, 1038, 1523,  -64, 1464, 1459,  -64, 1453,  -64, 1411,
 /*    50 */   -64, 1381,  -64, 1135,  -64,  251,  -64, 1131,  -64, 1427,
 /*    60 */   -64, 1363,  -64, 1279,  -64, 1359,  -64, 1099,  -64, 1052,
 /*    70 */   -64, 1183,  -64, 1479,  -64, 1357,  -64, 1512,  -64, 1503,
 /*    80 */   -64, 1501,  -64, 1469,  -64,  -64, 1431,  -64,  -64,  -64,
 /*    90 */   252,  -64,  -64, 1468,  -64, 1475,  -64, 1008,  -64, 1508,
 /*   100 */   -64,  255,  -64,  -64, 1013,  -64,  -64,  -64,  -64, 1035,
 /*   110 */  1062,  -64,  -64,  -64,  -64,  -64, 1060,  -64,  -64,  -64,
 /*   120 */   -64,  -64,  -64,  -64,  -64,  -64,  -64,  -64,  -64, 1083,
 /*   130 */   -64,  -64, 1407,  -64,  -64,  -64, 1171,  -64,  -64,  -64,
 /*   140 */   -64,  -64, 1176,  -64,  -64,  -64,  -64,  -64,  -64,  -64,
 /*   150 */   -64,  -64,  -64,  -64,  -64,  -64,  -64,  -64,  -64,  -64,
 /*   160 */   -64,  -64, 1311,  -64, 1368,  -64,  -64,  -64,  -64,  -64,
 /*   170 */   -64,  -64, 1132,  -64,  849,  980,  -64,  -64,  -64,  -63,
 /*   180 */   -64,  -64,  210,  -64,  -64, 1405,  -64, 1416,  -64, 1455,
 /*   190 */   -64, 1460,  -64, 1504,  -64, 1042,  -64,  -64,  408,  -64,
 /*   200 */   -64,  -64,  -64,  -64,  130,  -64,  673,  980,  -64,  -64,
 /*   210 */   -64, 1231,  -64, 1016,  -64,  -64,  761,  980,  -64,  -64,
 /*   220 */   -64,  -64,  -64,  -64,  959,  980,  -64,  -64,  -64, 1477,
 /*   230 */    54,  717,  980,  -64,  -64,  -64,  -64, 1001, 1085,  -64,
 /*   240 */   -64,  -64,  -64,  -64,  -64,  -64, 1133,  -64,  -64, 1167,
 /*   250 */   -64,  -64, 1229,  -64,  -64, 1235,  -64,  -64, 1320,  -64,
 /*   260 */   -64,  -64,  -64,  739,  980,  -64,  -64,  -64,  -64,  -64,
 /*   270 */   -64,  -64,  -64,  -64,  805,  980,  -64,  -64,  -64,  -64,
 /*   280 */   783,  980,  -64,  -64,  -64,  -64,  -64,  -64,  -64,  -64,
 /*   290 */   -64,  -64,  -64,  -64,  -64,  -64,  -64,  871,  980,  -64,
 /*   300 */   -64,  -64, 1161,  -64,  -64, 1181,  -64,  -64,  -64,  -64,
 /*   310 */   -64,  -64,  -64,  -64, 1316,  -64,  893,  980,  -64,  -64,
 /*   320 */   -64,  -64,  -64, 1364,  -64,  915,  980,  -64,  -64,  -64,
 /*   330 */  1412,  -64,  827,  980,  -64,  -64,  -64,  -64,  -64,  -64,
 /*   340 */   -64,  -64,  -64,  -64,  -64,  -64,  -64,  -64,
};
static VVACTIONTYPE vv_default[] = {
 /*     0 */   500,  500,  500,  350,  352,  353,  354,  355,  356,  357,
 /*    10 */   358,  359,  360,  361,  362,  363,  364,  365,  366,  367,
 /*    20 */   368,  369,  370,  371,  500,  500,  500,  500,  500,  500,
 /*    30 */   500,  372,  500,  500,  500,  500,  500,  374,  500,  500,
 /*    40 */   377,  500,  500,  427,  500,  500,  428,  500,  431,  500,
 /*    50 */   433,  500,  435,  500,  436,  500,  437,  500,  438,  500,
 /*    60 */   439,  500,  440,  500,  441,  500,  457,  500,  456,  500,
 /*    70 */   458,  500,  459,  500,  460,  500,  461,  500,  462,  500,
 /*    80 */   463,  500,  464,  500,  465,  500,  500,  466,  468,  469,
 /*    90 */   500,  500,  475,  500,  500,  500,  476,  500,  491,  500,
 /*   100 */   467,  500,  500,  470,  500,  485,  471,  500,  472,  500,
 /*   110 */   500,  473,  500,  474,  483,  495,  500,  484,  486,  493,
 /*   120 */   494,  495,  496,  497,  498,  499,  482,  500,  487,  500,
 /*   130 */   489,  495,  500,  492,  488,  490,  500,  500,  477,  500,
 /*   140 */   500,  500,  500,  478,  500,  479,  494,  493,  443,  445,
 /*   150 */   447,  449,  451,  453,  455,  442,  444,  446,  448,  450,
 /*   160 */   452,  454,  500,  434,  500,  432,  430,  429,  500,  378,
 /*   170 */   500,  500,  500,  500,  500,  500,  500,  500,  379,  500,
 /*   180 */   500,  383,  500,  384,  500,  500,  386,  500,  387,  500,
 /*   190 */   388,  500,  389,  500,  390,  500,  500,  392,  500,  391,
 /*   200 */   393,  385,  500,  500,  500,  500,  500,  500,  500,  500,
 /*   210 */   394,  500,  500,  500,  500,  487,  500,  500,  500,  500,
 /*   220 */   406,  408,  500,  500,  500,  500,  500,  500,  410,  500,
 /*   230 */   500,  500,  500,  500,  500,  412,  500,  500,  500,  500,
 /*   240 */   409,  500,  500,  500,  416,  426,  500,  500,  417,  500,
 /*   250 */   500,  418,  500,  500,  419,  500,  500,  420,  500,  500,
 /*   260 */   421,  500,  500,  500,  500,  500,  500,  422,  500,  424,
 /*   270 */   500,  425,  351,  500,  500,  500,  500,  500,  423,  500,
 /*   280 */   500,  500,  500,  500,  413,  500,  500,  500,  500,  411,
 /*   290 */   488,  500,  500,  500,  407,  500,  500,  500,  500,  500,
 /*   300 */   500,  395,  500,  396,  398,  500,  399,  400,  401,  402,
 /*   310 */   403,  404,  405,  397,  500,  500,  500,  500,  500,  500,
 /*   320 */   380,  500,  500,  500,  500,  500,  500,  500,  500,  381,
 /*   330 */   500,  500,  500,  500,  500,  500,  382,  500,  500,  375,
 /*   340 */   500,  500,  373,  500,  500,  500,  500,  376,
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
  "RAW",           "ENDRAW",        "EXTENDS",       "INCLUDE",     
  "WITH",          "DO",            "RETURN",        "AUTOESCAPE",  
  "ENDAUTOESCAPE",  "BREAK",         "CONTINUE",      "RAW_FRAGMENT",
  "DEFINED",       "EMPTY",         "EVEN",          "ODD",         
  "NUMERIC",       "SCALAR",        "ITERABLE",      "CBRACKET_OPEN",
  "CBRACKET_CLOSE",  "error",         "program",       "volt_language",
  "statement_list",  "statement",     "raw_fragment",  "if_statement",
  "elseif_statement",  "elsefor_statement",  "for_statement",  "set_statement",
  "echo_statement",  "block_statement",  "cache_statement",  "extends_statement",
  "include_statement",  "do_statement",  "return_statement",  "autoescape_statement",
  "raw_statement",  "break_statement",  "continue_statement",  "macro_statement",
  "empty_statement",  "macro_call_statement",  "expr",          "set_assignments",
  "set_assignment",  "assignable_expr",  "macro_parameters",  "macro_parameter",
  "macro_parameter_default",  "argument_list",  "cache_lifetime",  "array_list",  
  "slice_offset",  "array_item",    "function_call",  "argument_item",
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
 /*  18 */ "statement ::= raw_statement",
 /*  19 */ "statement ::= break_statement",
 /*  20 */ "statement ::= continue_statement",
 /*  21 */ "statement ::= macro_statement",
 /*  22 */ "statement ::= empty_statement",
 /*  23 */ "statement ::= macro_call_statement",
 /*  24 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  25 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  26 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  27 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  28 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER OPEN_DELIMITER ELSE CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  29 */ "elseif_statement ::= OPEN_DELIMITER ELSEIF expr CLOSE_DELIMITER",
 /*  30 */ "elsefor_statement ::= OPEN_DELIMITER ELSEFOR CLOSE_DELIMITER",
 /*  31 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  32 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  33 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  34 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  35 */ "set_statement ::= OPEN_DELIMITER SET set_assignments CLOSE_DELIMITER",
 /*  36 */ "set_assignments ::= set_assignments COMMA set_assignment",
 /*  37 */ "set_assignments ::= set_assignment",
 /*  38 */ "set_assignment ::= assignable_expr ASSIGN expr",
 /*  39 */ "set_assignment ::= assignable_expr ADD_ASSIGN expr",
 /*  40 */ "set_assignment ::= assignable_expr SUB_ASSIGN expr",
 /*  41 */ "set_assignment ::= assignable_expr MUL_ASSIGN expr",
 /*  42 */ "set_assignment ::= assignable_expr DIV_ASSIGN expr",
 /*  43 */ "assignable_expr ::= IDENTIFIER",
 /*  44 */ "assignable_expr ::= assignable_expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /*  45 */ "assignable_expr ::= assignable_expr DOT assignable_expr",
 /*  46 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  47 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN macro_parameters PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  48 */ "macro_parameters ::= macro_parameters COMMA macro_parameter",
 /*  49 */ "macro_parameters ::= macro_parameter",
 /*  50 */ "macro_parameter ::= IDENTIFIER",
 /*  51 */ "macro_parameter ::= IDENTIFIER ASSIGN macro_parameter_default",
 /*  52 */ "macro_parameter_default ::= INTEGER",
 /*  53 */ "macro_parameter_default ::= STRING",
 /*  54 */ "macro_parameter_default ::= DOUBLE",
 /*  55 */ "macro_parameter_default ::= NULL",
 /*  56 */ "macro_parameter_default ::= FALSE",
 /*  57 */ "macro_parameter_default ::= TRUE",
 /*  58 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  59 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  60 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  61 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  62 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  63 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  64 */ "cache_statement ::= OPEN_DELIMITER CACHE expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  65 */ "cache_statement ::= OPEN_DELIMITER CACHE expr cache_lifetime CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  66 */ "cache_lifetime ::= INTEGER",
 /*  67 */ "cache_lifetime ::= IDENTIFIER",
 /*  68 */ "raw_statement ::= OPEN_DELIMITER RAW CLOSE_DELIMITER statement OPEN_DELIMITER ENDRAW CLOSE_DELIMITER",
 /*  69 */ "extends_statement ::= OPEN_DELIMITER EXTENDS expr CLOSE_DELIMITER",
 /*  70 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr CLOSE_DELIMITER",
 /*  71 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr WITH expr CLOSE_DELIMITER",
 /*  72 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  73 */ "return_statement ::= OPEN_DELIMITER RETURN expr CLOSE_DELIMITER",
 /*  74 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE FALSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  75 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE TRUE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  76 */ "break_statement ::= OPEN_DELIMITER BREAK CLOSE_DELIMITER",
 /*  77 */ "continue_statement ::= OPEN_DELIMITER CONTINUE CLOSE_DELIMITER",
 /*  78 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  79 */ "expr ::= MINUS expr",
 /*  80 */ "expr ::= PLUS expr",
 /*  81 */ "expr ::= expr MINUS expr",
 /*  82 */ "expr ::= expr PLUS expr",
 /*  83 */ "expr ::= expr TIMES expr",
 /*  84 */ "expr ::= expr TIMES TIMES expr",
 /*  85 */ "expr ::= expr DIVIDE expr",
 /*  86 */ "expr ::= expr DIVIDE DIVIDE expr",
 /*  87 */ "expr ::= expr MOD expr",
 /*  88 */ "expr ::= expr AND expr",
 /*  89 */ "expr ::= expr OR expr",
 /*  90 */ "expr ::= expr CONCAT expr",
 /*  91 */ "expr ::= expr PIPE expr",
 /*  92 */ "expr ::= expr RANGE expr",
 /*  93 */ "expr ::= expr EQUALS expr",
 /*  94 */ "expr ::= expr NOTEQUALS DEFINED",
 /*  95 */ "expr ::= expr IS DEFINED",
 /*  96 */ "expr ::= expr NOTEQUALS EMPTY",
 /*  97 */ "expr ::= expr IS EMPTY",
 /*  98 */ "expr ::= expr NOTEQUALS EVEN",
 /*  99 */ "expr ::= expr IS EVEN",
 /* 100 */ "expr ::= expr NOTEQUALS ODD",
 /* 101 */ "expr ::= expr IS ODD",
 /* 102 */ "expr ::= expr NOTEQUALS NUMERIC",
 /* 103 */ "expr ::= expr IS NUMERIC",
 /* 104 */ "expr ::= expr NOTEQUALS SCALAR",
 /* 105 */ "expr ::= expr IS SCALAR",
 /* 106 */ "expr ::= expr NOTEQUALS ITERABLE",
 /* 107 */ "expr ::= expr IS ITERABLE",
 /* 108 */ "expr ::= expr IS expr",
 /* 109 */ "expr ::= expr NOTEQUALS expr",
 /* 110 */ "expr ::= expr IDENTICAL expr",
 /* 111 */ "expr ::= expr NOTIDENTICAL expr",
 /* 112 */ "expr ::= expr LESS expr",
 /* 113 */ "expr ::= expr GREATER expr",
 /* 114 */ "expr ::= expr GREATEREQUAL expr",
 /* 115 */ "expr ::= expr LESSEQUAL expr",
 /* 116 */ "expr ::= expr DOT expr",
 /* 117 */ "expr ::= expr IN expr",
 /* 118 */ "expr ::= expr NOT IN expr",
 /* 119 */ "expr ::= NOT expr",
 /* 120 */ "expr ::= expr INCR",
 /* 121 */ "expr ::= expr DECR",
 /* 122 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 123 */ "expr ::= SBRACKET_OPEN SBRACKET_CLOSE",
 /* 124 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /* 125 */ "expr ::= CBRACKET_OPEN CBRACKET_CLOSE",
 /* 126 */ "expr ::= CBRACKET_OPEN array_list CBRACKET_CLOSE",
 /* 127 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /* 128 */ "expr ::= expr QUESTION expr COLON expr",
 /* 129 */ "expr ::= expr SBRACKET_OPEN COLON slice_offset SBRACKET_CLOSE",
 /* 130 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON SBRACKET_CLOSE",
 /* 131 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON slice_offset SBRACKET_CLOSE",
 /* 132 */ "slice_offset ::= INTEGER",
 /* 133 */ "slice_offset ::= IDENTIFIER",
 /* 134 */ "array_list ::= array_list COMMA array_item",
 /* 135 */ "array_list ::= array_item",
 /* 136 */ "array_item ::= STRING COLON expr",
 /* 137 */ "array_item ::= expr",
 /* 138 */ "expr ::= function_call",
 /* 139 */ "function_call ::= expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 140 */ "function_call ::= expr PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 141 */ "argument_list ::= argument_list COMMA argument_item",
 /* 142 */ "argument_list ::= argument_item",
 /* 143 */ "argument_item ::= expr",
 /* 144 */ "argument_item ::= STRING COLON expr",
 /* 145 */ "expr ::= IDENTIFIER",
 /* 146 */ "expr ::= INTEGER",
 /* 147 */ "expr ::= STRING",
 /* 148 */ "expr ::= DOUBLE",
 /* 149 */ "expr ::= NULL",
 /* 150 */ "expr ::= FALSE",
 /* 151 */ "expr ::= TRUE",
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
    case 83:
    case 84:
// 716 "parser.lemon"
{
	if ((vvpminor->vv0)) {
		if ((vvpminor->vv0)->free_flag) {
			efree((vvpminor->vv0)->token);
		}
		efree((vvpminor->vv0));
	}
}
// 1705 "parser.c"
      break;
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
    case 112:
    case 114:
    case 115:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 122:
    case 123:
// 733 "parser.lemon"
{ zval_ptr_dtor(&(vvpminor->vv40)); }
// 1743 "parser.c"
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
  { 86, 1 },
  { 87, 1 },
  { 88, 2 },
  { 88, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 89, 1 },
  { 91, 8 },
  { 91, 7 },
  { 91, 12 },
  { 91, 11 },
  { 91, 10 },
  { 92, 4 },
  { 93, 3 },
  { 94, 10 },
  { 94, 12 },
  { 94, 12 },
  { 94, 14 },
  { 95, 4 },
  { 111, 3 },
  { 111, 1 },
  { 112, 3 },
  { 112, 3 },
  { 112, 3 },
  { 112, 3 },
  { 112, 3 },
  { 113, 1 },
  { 113, 4 },
  { 113, 3 },
  { 107, 10 },
  { 107, 11 },
  { 114, 3 },
  { 114, 1 },
  { 115, 1 },
  { 115, 3 },
  { 116, 1 },
  { 116, 1 },
  { 116, 1 },
  { 116, 1 },
  { 116, 1 },
  { 116, 1 },
  { 109, 11 },
  { 109, 9 },
  { 108, 2 },
  { 96, 3 },
  { 97, 8 },
  { 97, 7 },
  { 98, 8 },
  { 98, 9 },
  { 118, 1 },
  { 118, 1 },
  { 104, 7 },
  { 99, 4 },
  { 100, 4 },
  { 100, 6 },
  { 101, 4 },
  { 102, 4 },
  { 103, 8 },
  { 103, 8 },
  { 105, 3 },
  { 106, 3 },
  { 90, 1 },
  { 110, 2 },
  { 110, 2 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 4 },
  { 110, 3 },
  { 110, 4 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 3 },
  { 110, 4 },
  { 110, 2 },
  { 110, 2 },
  { 110, 2 },
  { 110, 3 },
  { 110, 2 },
  { 110, 3 },
  { 110, 2 },
  { 110, 3 },
  { 110, 4 },
  { 110, 5 },
  { 110, 5 },
  { 110, 5 },
  { 110, 6 },
  { 120, 1 },
  { 120, 1 },
  { 119, 3 },
  { 119, 1 },
  { 121, 3 },
  { 121, 1 },
  { 110, 1 },
  { 122, 4 },
  { 122, 3 },
  { 117, 3 },
  { 117, 1 },
  { 123, 1 },
  { 123, 3 },
  { 110, 1 },
  { 110, 1 },
  { 110, 1 },
  { 110, 1 },
  { 110, 1 },
  { 110, 1 },
  { 110, 1 },
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
// 725 "parser.lemon"
{
	status->ret = vvmsp[0].minor.vv40;
}
// 2112 "parser.c"
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
      case 23:
      case 138:
// 729 "parser.lemon"
{
	vvgotominor.vv40 = vvmsp[0].minor.vv40;
}
// 2140 "parser.c"
        break;
      case 2:
// 735 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_zval_list(vvmsp[-1].minor.vv40, vvmsp[0].minor.vv40);
}
// 2147 "parser.c"
        break;
      case 3:
      case 37:
      case 49:
      case 135:
      case 142:
// 739 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_zval_list(NULL, vvmsp[0].minor.vv40);
}
// 2158 "parser.c"
        break;
      case 24:
// 827 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_if_statement(vvmsp[-5].minor.vv40, vvmsp[-3].minor.vv40, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(31,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(33,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2171 "parser.c"
        break;
      case 25:
// 831 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_if_statement(vvmsp[-4].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-6].minor);
  vv_destructor(31,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-3].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(33,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2184 "parser.c"
        break;
      case 26:
// 835 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_if_statement(vvmsp[-9].minor.vv40, vvmsp[-7].minor.vv40, vvmsp[-3].minor.vv40, status->scanner_state);
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
// 2200 "parser.c"
        break;
      case 27:
// 839 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_if_statement(vvmsp[-8].minor.vv40, vvmsp[-6].minor.vv40, NULL, status->scanner_state);
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
// 2216 "parser.c"
        break;
      case 28:
// 843 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_if_statement(vvmsp[-7].minor.vv40, NULL, NULL, status->scanner_state);
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
// 2232 "parser.c"
        break;
      case 29:
// 849 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_elseif_statement(vvmsp[-1].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(35,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2242 "parser.c"
        break;
      case 30:
// 855 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_elsefor_statement(status->scanner_state);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(36,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2252 "parser.c"
        break;
      case 31:
// 861 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_for_statement(vvmsp[-7].minor.vv0, NULL, vvmsp[-5].minor.vv40, NULL, vvmsp[-3].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-9].minor);
  vv_destructor(37,&vvmsp[-8].minor);
  vv_destructor(3,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(39,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2266 "parser.c"
        break;
      case 32:
// 865 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_for_statement(vvmsp[-9].minor.vv0, NULL, vvmsp[-7].minor.vv40, vvmsp[-5].minor.vv40, vvmsp[-3].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-11].minor);
  vv_destructor(37,&vvmsp[-10].minor);
  vv_destructor(3,&vvmsp[-8].minor);
  vv_destructor(31,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(39,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2281 "parser.c"
        break;
      case 33:
// 869 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_for_statement(vvmsp[-7].minor.vv0, vvmsp[-9].minor.vv0, vvmsp[-5].minor.vv40, NULL, vvmsp[-3].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-11].minor);
  vv_destructor(37,&vvmsp[-10].minor);
  vv_destructor(2,&vvmsp[-8].minor);
  vv_destructor(3,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(39,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2296 "parser.c"
        break;
      case 34:
// 873 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_for_statement(vvmsp[-9].minor.vv0, vvmsp[-11].minor.vv0, vvmsp[-7].minor.vv40, vvmsp[-5].minor.vv40, vvmsp[-3].minor.vv40, status->scanner_state);
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
// 2312 "parser.c"
        break;
      case 35:
// 879 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_set_statement(vvmsp[-1].minor.vv40);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(40,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2322 "parser.c"
        break;
      case 36:
      case 48:
      case 134:
      case 141:
// 885 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_zval_list(vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40);
  vv_destructor(2,&vvmsp[-1].minor);
}
// 2333 "parser.c"
        break;
      case 38:
// 895 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv40, PHVOLT_T_ASSIGN, vvmsp[0].minor.vv40, status->scanner_state);
  vv_destructor(41,&vvmsp[-1].minor);
}
// 2341 "parser.c"
        break;
      case 39:
// 899 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv40, PHVOLT_T_ADD_ASSIGN, vvmsp[0].minor.vv40, status->scanner_state);
  vv_destructor(42,&vvmsp[-1].minor);
}
// 2349 "parser.c"
        break;
      case 40:
// 903 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv40, PHVOLT_T_SUB_ASSIGN, vvmsp[0].minor.vv40, status->scanner_state);
  vv_destructor(43,&vvmsp[-1].minor);
}
// 2357 "parser.c"
        break;
      case 41:
// 907 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv40, PHVOLT_T_MUL_ASSIGN, vvmsp[0].minor.vv40, status->scanner_state);
  vv_destructor(44,&vvmsp[-1].minor);
}
// 2365 "parser.c"
        break;
      case 42:
// 911 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_set_assignment(vvmsp[-2].minor.vv40, PHVOLT_T_DIV_ASSIGN, vvmsp[0].minor.vv40, status->scanner_state);
  vv_destructor(45,&vvmsp[-1].minor);
}
// 2373 "parser.c"
        break;
      case 43:
      case 67:
      case 133:
      case 145:
// 915 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, vvmsp[0].minor.vv0, status->scanner_state);
}
// 2383 "parser.c"
        break;
      case 44:
      case 127:
// 919 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, vvmsp[-3].minor.vv40, vvmsp[-1].minor.vv40, NULL, status->scanner_state);
  vv_destructor(24,&vvmsp[-2].minor);
  vv_destructor(46,&vvmsp[0].minor);
}
// 2393 "parser.c"
        break;
      case 45:
      case 116:
// 923 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_DOT, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(30,&vvmsp[-1].minor);
}
// 2402 "parser.c"
        break;
      case 46:
// 929 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_macro_statement(vvmsp[-7].minor.vv0, NULL, vvmsp[-3].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-9].minor);
  vv_destructor(47,&vvmsp[-8].minor);
  vv_destructor(29,&vvmsp[-6].minor);
  vv_destructor(48,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(49,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2417 "parser.c"
        break;
      case 47:
// 933 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_macro_statement(vvmsp[-8].minor.vv0, vvmsp[-6].minor.vv40, vvmsp[-3].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-10].minor);
  vv_destructor(47,&vvmsp[-9].minor);
  vv_destructor(29,&vvmsp[-7].minor);
  vv_destructor(48,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(49,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2432 "parser.c"
        break;
      case 50:
// 949 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_macro_parameter(vvmsp[0].minor.vv0, NULL, status->scanner_state);
}
// 2439 "parser.c"
        break;
      case 51:
// 953 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_macro_parameter(vvmsp[-2].minor.vv0, vvmsp[0].minor.vv40, status->scanner_state);
  vv_destructor(41,&vvmsp[-1].minor);
}
// 2447 "parser.c"
        break;
      case 52:
      case 66:
      case 132:
      case 146:
// 957 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, vvmsp[0].minor.vv0, status->scanner_state);
}
// 2457 "parser.c"
        break;
      case 53:
      case 147:
// 961 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_literal_zval(PHVOLT_T_STRING, vvmsp[0].minor.vv0, status->scanner_state);
}
// 2465 "parser.c"
        break;
      case 54:
      case 148:
// 965 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, vvmsp[0].minor.vv0, status->scanner_state);
}
// 2473 "parser.c"
        break;
      case 55:
      case 149:
// 969 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  vv_destructor(53,&vvmsp[0].minor);
}
// 2482 "parser.c"
        break;
      case 56:
      case 150:
// 973 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  vv_destructor(54,&vvmsp[0].minor);
}
// 2491 "parser.c"
        break;
      case 57:
      case 151:
// 977 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  vv_destructor(55,&vvmsp[0].minor);
}
// 2500 "parser.c"
        break;
      case 58:
// 983 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_macro_call_statement(vvmsp[-8].minor.vv40, vvmsp[-6].minor.vv40, vvmsp[-3].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-10].minor);
  vv_destructor(56,&vvmsp[-9].minor);
  vv_destructor(29,&vvmsp[-7].minor);
  vv_destructor(48,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(57,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2515 "parser.c"
        break;
      case 59:
// 987 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_macro_call_statement(vvmsp[-6].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-8].minor);
  vv_destructor(56,&vvmsp[-7].minor);
  vv_destructor(29,&vvmsp[-5].minor);
  vv_destructor(48,&vvmsp[-4].minor);
  vv_destructor(32,&vvmsp[-3].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(57,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2530 "parser.c"
        break;
      case 60:
// 993 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_empty_statement(status->scanner_state);
  vv_destructor(1,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2539 "parser.c"
        break;
      case 61:
// 999 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_echo_statement(vvmsp[-1].minor.vv40, status->scanner_state);
  vv_destructor(58,&vvmsp[-2].minor);
  vv_destructor(59,&vvmsp[0].minor);
}
// 2548 "parser.c"
        break;
      case 62:
// 1005 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_block_statement(vvmsp[-5].minor.vv0, vvmsp[-3].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(60,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(61,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2561 "parser.c"
        break;
      case 63:
// 1009 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_block_statement(vvmsp[-4].minor.vv0, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-6].minor);
  vv_destructor(60,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-3].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(61,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2574 "parser.c"
        break;
      case 64:
// 1015 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_cache_statement(vvmsp[-5].minor.vv40, NULL, vvmsp[-3].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(62,&vvmsp[-6].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(63,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2587 "parser.c"
        break;
      case 65:
// 1019 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_cache_statement(vvmsp[-6].minor.vv40, vvmsp[-5].minor.vv40, vvmsp[-3].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-8].minor);
  vv_destructor(62,&vvmsp[-7].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(63,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2600 "parser.c"
        break;
      case 68:
// 1035 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_raw_statement(vvmsp[-3].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-6].minor);
  vv_destructor(64,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(65,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2613 "parser.c"
        break;
      case 69:
// 1041 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_extends_statement(vvmsp[-1].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(66,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2623 "parser.c"
        break;
      case 70:
// 1047 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_include_statement(vvmsp[-1].minor.vv40, NULL, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(67,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2633 "parser.c"
        break;
      case 71:
// 1051 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_include_statement(vvmsp[-3].minor.vv40, vvmsp[-1].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-5].minor);
  vv_destructor(67,&vvmsp[-4].minor);
  vv_destructor(68,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2644 "parser.c"
        break;
      case 72:
// 1057 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_do_statement(vvmsp[-1].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(69,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2654 "parser.c"
        break;
      case 73:
// 1063 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_return_statement(vvmsp[-1].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-3].minor);
  vv_destructor(70,&vvmsp[-2].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2664 "parser.c"
        break;
      case 74:
// 1069 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_autoescape_statement(0, vvmsp[-3].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(71,&vvmsp[-6].minor);
  vv_destructor(54,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(72,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2678 "parser.c"
        break;
      case 75:
// 1073 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_autoescape_statement(1, vvmsp[-3].minor.vv40, status->scanner_state);
  vv_destructor(1,&vvmsp[-7].minor);
  vv_destructor(71,&vvmsp[-6].minor);
  vv_destructor(55,&vvmsp[-5].minor);
  vv_destructor(32,&vvmsp[-4].minor);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(72,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2692 "parser.c"
        break;
      case 76:
// 1079 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_break_statement(status->scanner_state);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(73,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2702 "parser.c"
        break;
      case 77:
// 1085 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_continue_statement(status->scanner_state);
  vv_destructor(1,&vvmsp[-2].minor);
  vv_destructor(74,&vvmsp[-1].minor);
  vv_destructor(32,&vvmsp[0].minor);
}
// 2712 "parser.c"
        break;
      case 78:
// 1091 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, vvmsp[0].minor.vv0, status->scanner_state);
}
// 2719 "parser.c"
        break;
      case 79:
// 1097 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(22,&vvmsp[-1].minor);
}
// 2727 "parser.c"
        break;
      case 80:
// 1101 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_PLUS, NULL, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(21,&vvmsp[-1].minor);
}
// 2735 "parser.c"
        break;
      case 81:
// 1105 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_SUB, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(22,&vvmsp[-1].minor);
}
// 2743 "parser.c"
        break;
      case 82:
// 1109 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_ADD, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(21,&vvmsp[-1].minor);
}
// 2751 "parser.c"
        break;
      case 83:
// 1113 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_MUL, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(19,&vvmsp[-1].minor);
}
// 2759 "parser.c"
        break;
      case 84:
// 1117 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_POW, vvmsp[-3].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(19,&vvmsp[-2].minor);
  vv_destructor(19,&vvmsp[-1].minor);
}
// 2768 "parser.c"
        break;
      case 85:
// 1121 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_DIV, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(18,&vvmsp[-1].minor);
}
// 2776 "parser.c"
        break;
      case 86:
// 1125 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_MOD, vvmsp[-3].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(18,&vvmsp[-2].minor);
  vv_destructor(18,&vvmsp[-1].minor);
}
// 2785 "parser.c"
        break;
      case 87:
// 1129 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_MOD, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(20,&vvmsp[-1].minor);
}
// 2793 "parser.c"
        break;
      case 88:
// 1133 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_AND, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(7,&vvmsp[-1].minor);
}
// 2801 "parser.c"
        break;
      case 89:
// 1137 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_OR, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(8,&vvmsp[-1].minor);
}
// 2809 "parser.c"
        break;
      case 90:
// 1141 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_CONCAT, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(23,&vvmsp[-1].minor);
}
// 2817 "parser.c"
        break;
      case 91:
// 1145 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_PIPE, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(25,&vvmsp[-1].minor);
}
// 2825 "parser.c"
        break;
      case 92:
// 1149 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_RANGE, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(6,&vvmsp[-1].minor);
}
// 2833 "parser.c"
        break;
      case 93:
// 1153 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_EQUALS, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(10,&vvmsp[-1].minor);
}
// 2841 "parser.c"
        break;
      case 94:
// 1157 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, vvmsp[-2].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(76,&vvmsp[0].minor);
}
// 2850 "parser.c"
        break;
      case 95:
// 1161 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_ISSET, vvmsp[-2].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(76,&vvmsp[0].minor);
}
// 2859 "parser.c"
        break;
      case 96:
// 1165 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_NOT_ISEMPTY, vvmsp[-2].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(77,&vvmsp[0].minor);
}
// 2868 "parser.c"
        break;
      case 97:
// 1169 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_ISEMPTY, vvmsp[-2].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(77,&vvmsp[0].minor);
}
// 2877 "parser.c"
        break;
      case 98:
// 1173 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_NOT_ISEVEN, vvmsp[-2].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(78,&vvmsp[0].minor);
}
// 2886 "parser.c"
        break;
      case 99:
// 1177 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_ISEVEN, vvmsp[-2].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(78,&vvmsp[0].minor);
}
// 2895 "parser.c"
        break;
      case 100:
// 1181 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_NOT_ISODD, vvmsp[-2].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(79,&vvmsp[0].minor);
}
// 2904 "parser.c"
        break;
      case 101:
// 1185 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_ISODD, vvmsp[-2].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(79,&vvmsp[0].minor);
}
// 2913 "parser.c"
        break;
      case 102:
// 1189 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_NOT_ISNUMERIC, vvmsp[-2].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(80,&vvmsp[0].minor);
}
// 2922 "parser.c"
        break;
      case 103:
// 1193 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_ISNUMERIC, vvmsp[-2].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(80,&vvmsp[0].minor);
}
// 2931 "parser.c"
        break;
      case 104:
// 1197 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_NOT_ISSCALAR, vvmsp[-2].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(81,&vvmsp[0].minor);
}
// 2940 "parser.c"
        break;
      case 105:
// 1201 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_ISSCALAR, vvmsp[-2].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(81,&vvmsp[0].minor);
}
// 2949 "parser.c"
        break;
      case 106:
// 1205 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_NOT_ISITERABLE, vvmsp[-2].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
  vv_destructor(82,&vvmsp[0].minor);
}
// 2958 "parser.c"
        break;
      case 107:
// 1209 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_ISITERABLE, vvmsp[-2].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
  vv_destructor(82,&vvmsp[0].minor);
}
// 2967 "parser.c"
        break;
      case 108:
// 1213 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_IS, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(9,&vvmsp[-1].minor);
}
// 2975 "parser.c"
        break;
      case 109:
// 1217 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(11,&vvmsp[-1].minor);
}
// 2983 "parser.c"
        break;
      case 110:
// 1221 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(16,&vvmsp[-1].minor);
}
// 2991 "parser.c"
        break;
      case 111:
// 1225 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(17,&vvmsp[-1].minor);
}
// 2999 "parser.c"
        break;
      case 112:
// 1229 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_LESS, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(12,&vvmsp[-1].minor);
}
// 3007 "parser.c"
        break;
      case 113:
// 1233 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_GREATER, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(13,&vvmsp[-1].minor);
}
// 3015 "parser.c"
        break;
      case 114:
// 1237 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(14,&vvmsp[-1].minor);
}
// 3023 "parser.c"
        break;
      case 115:
// 1241 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(15,&vvmsp[-1].minor);
}
// 3031 "parser.c"
        break;
      case 117:
// 1249 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_IN, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(3,&vvmsp[-1].minor);
}
// 3039 "parser.c"
        break;
      case 118:
// 1253 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_NOT_IN, vvmsp[-3].minor.vv40, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(26,&vvmsp[-2].minor);
  vv_destructor(3,&vvmsp[-1].minor);
}
// 3048 "parser.c"
        break;
      case 119:
// 1257 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, vvmsp[0].minor.vv40, NULL, status->scanner_state);
  vv_destructor(26,&vvmsp[-1].minor);
}
// 3056 "parser.c"
        break;
      case 120:
// 1261 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_INCR, vvmsp[-1].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(27,&vvmsp[0].minor);
}
// 3064 "parser.c"
        break;
      case 121:
// 1265 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_DECR, vvmsp[-1].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(28,&vvmsp[0].minor);
}
// 3072 "parser.c"
        break;
      case 122:
// 1269 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, vvmsp[-1].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(29,&vvmsp[-2].minor);
  vv_destructor(48,&vvmsp[0].minor);
}
// 3081 "parser.c"
        break;
      case 123:
// 1273 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  vv_destructor(24,&vvmsp[-1].minor);
  vv_destructor(46,&vvmsp[0].minor);
}
// 3090 "parser.c"
        break;
      case 124:
// 1277 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_ARRAY, vvmsp[-1].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(24,&vvmsp[-2].minor);
  vv_destructor(46,&vvmsp[0].minor);
}
// 3099 "parser.c"
        break;
      case 125:
// 1281 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  vv_destructor(83,&vvmsp[-1].minor);
  vv_destructor(84,&vvmsp[0].minor);
}
// 3108 "parser.c"
        break;
      case 126:
// 1285 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_ARRAY, vvmsp[-1].minor.vv40, NULL, NULL, status->scanner_state);
  vv_destructor(83,&vvmsp[-2].minor);
  vv_destructor(84,&vvmsp[0].minor);
}
// 3117 "parser.c"
        break;
      case 128:
// 1293 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_expr(PHVOLT_T_TERNARY, vvmsp[-2].minor.vv40, vvmsp[0].minor.vv40, vvmsp[-4].minor.vv40, status->scanner_state);
  vv_destructor(4,&vvmsp[-3].minor);
  vv_destructor(5,&vvmsp[-1].minor);
}
// 3126 "parser.c"
        break;
      case 129:
// 1297 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_slice(vvmsp[-4].minor.vv40, NULL, vvmsp[-1].minor.vv40, status->scanner_state);
  vv_destructor(24,&vvmsp[-3].minor);
  vv_destructor(5,&vvmsp[-2].minor);
  vv_destructor(46,&vvmsp[0].minor);
}
// 3136 "parser.c"
        break;
      case 130:
// 1301 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_slice(vvmsp[-4].minor.vv40, vvmsp[-2].minor.vv40, NULL, status->scanner_state);
  vv_destructor(24,&vvmsp[-3].minor);
  vv_destructor(5,&vvmsp[-1].minor);
  vv_destructor(46,&vvmsp[0].minor);
}
// 3146 "parser.c"
        break;
      case 131:
// 1305 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_slice(vvmsp[-5].minor.vv40, vvmsp[-3].minor.vv40, vvmsp[-1].minor.vv40, status->scanner_state);
  vv_destructor(24,&vvmsp[-4].minor);
  vv_destructor(5,&vvmsp[-2].minor);
  vv_destructor(46,&vvmsp[0].minor);
}
// 3156 "parser.c"
        break;
      case 136:
      case 144:
// 1331 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_named_item(vvmsp[-2].minor.vv0, vvmsp[0].minor.vv40, status->scanner_state);
  vv_destructor(5,&vvmsp[-1].minor);
}
// 3165 "parser.c"
        break;
      case 137:
      case 143:
// 1335 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_named_item(NULL, vvmsp[0].minor.vv40, status->scanner_state);
}
// 3173 "parser.c"
        break;
      case 139:
// 1345 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_func_call(vvmsp[-3].minor.vv40, vvmsp[-1].minor.vv40, status->scanner_state);
  vv_destructor(29,&vvmsp[-2].minor);
  vv_destructor(48,&vvmsp[0].minor);
}
// 3182 "parser.c"
        break;
      case 140:
// 1349 "parser.lemon"
{
	vvgotominor.vv40 = phvolt_ret_func_call(vvmsp[-2].minor.vv40, NULL, status->scanner_state);
  vv_destructor(29,&vvmsp[-1].minor);
  vv_destructor(48,&vvmsp[0].minor);
}
// 3191 "parser.c"
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
#define VTOKEN (vvminor.vv0)
// 618 "parser.lemon"

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

// 3331 "parser.c"
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
  | Phalcon Framework													   |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)	   |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled	   |
  | with this package in the file docs/LICENSE.txt.					       |
  |																	       |
  | If you did not receive a copy of the license and are unable to		   |
  | obtain it through the world-wide-web, please send an email			   |
  | to license@phalconphp.com so we can send you a copy immediately.	   |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>					   |
  |		  Eduar Carvajal <eduar@phalconphp.com>						       |
  +------------------------------------------------------------------------+
*/

const phvolt_token_names phvolt_tokens[] =
{
  { SL("INTEGER"),		PHVOLT_T_INTEGER },
  { SL("DOUBLE"),		 PHVOLT_T_DOUBLE },
  { SL("STRING"),		 PHVOLT_T_STRING },
  { SL("IDENTIFIER"),	 PHVOLT_T_IDENTIFIER },
  { SL("MINUS"),		  PHVOLT_T_MINUS },
  { SL("+"),			  PHVOLT_T_ADD },
  { SL("-"),			  PHVOLT_T_SUB },
  { SL("*"),			  PHVOLT_T_MUL },
  { SL("/"),			  PHVOLT_T_DIV },
  { SL("%%"),			 PHVOLT_T_MOD },
  { SL("!"),			  PHVOLT_T_NOT },
  { SL("~"),			  PHVOLT_T_CONCAT },
  { SL("AND"),			PHVOLT_T_AND },
  { SL("OR"),			 PHVOLT_T_OR },
  { SL("DOT"),			PHVOLT_T_DOT },
  { SL("COMMA"),		  PHVOLT_T_COMMA },
  { SL("EQUALS"),		 PHVOLT_T_EQUALS },
  { SL("NOT EQUALS"),	 PHVOLT_T_NOTEQUALS },
  { SL("IDENTICAL"),	  PHVOLT_T_IDENTICAL },
  { SL("NOT IDENTICAL"),  PHVOLT_T_NOTIDENTICAL },
  { SL("NOT"),			PHVOLT_T_NOT },
  { SL("RANGE"),		  PHVOLT_T_RANGE },
  { SL("COLON"),		  PHVOLT_T_COLON },
  { SL("QUESTION MARK"),  PHVOLT_T_QUESTION },
  { SL("<"),			  PHVOLT_T_LESS },
  { SL("<="),			 PHVOLT_T_LESSEQUAL },
  { SL(">"),			  PHVOLT_T_GREATER },
  { SL(">="),			 PHVOLT_T_GREATEREQUAL },
  { SL("("),			  PHVOLT_T_PARENTHESES_OPEN },
  { SL(")"),			  PHVOLT_T_PARENTHESES_CLOSE },
  { SL("["),			  PHVOLT_T_SBRACKET_OPEN },
  { SL("]"),			  PHVOLT_T_SBRACKET_CLOSE },
  { SL("{"),			  PHVOLT_T_CBRACKET_OPEN },
  { SL("}"),			  PHVOLT_T_CBRACKET_CLOSE },
  { SL("{%"),			 PHVOLT_T_OPEN_DELIMITER },
  { SL("%}"),			 PHVOLT_T_CLOSE_DELIMITER },
  { SL("{{"),			 PHVOLT_T_OPEN_EDELIMITER },
  { SL("}}"),			 PHVOLT_T_CLOSE_EDELIMITER },
  { SL("IF"),			 PHVOLT_T_IF },
  { SL("ELSE"),		   PHVOLT_T_ELSE },
  { SL("ELSEIF"),		 PHVOLT_T_ELSEIF },
  { SL("ELSEFOR"),		PHVOLT_T_ELSEFOR },
  { SL("ENDIF"),		  PHVOLT_T_ENDIF },
  { SL("FOR"),			PHVOLT_T_FOR },
  { SL("IN"),			 PHVOLT_T_IN },
  { SL("ENDFOR"),		 PHVOLT_T_ENDFOR },
  { SL("SET"),			PHVOLT_T_SET },
  { SL("ASSIGN"),		 PHVOLT_T_ASSIGN },
  { SL("+="),			 PHVOLT_T_ADD_ASSIGN },
  { SL("-="),			 PHVOLT_T_SUB_ASSIGN },
  { SL("*="),			 PHVOLT_T_MUL_ASSIGN },
  { SL("/="),			 PHVOLT_T_DIV_ASSIGN },
  { SL("++"),			 PHVOLT_T_INCR },
  { SL("--"),			 PHVOLT_T_DECR },
  { SL("BLOCK"),		  PHVOLT_T_BLOCK },
  { SL("ENDBLOCK"),	   PHVOLT_T_ENDBLOCK },
  { SL("CACHE"),		  PHVOLT_T_CACHE },
  { SL("ENDCACHE"),	   PHVOLT_T_ENDCACHE },
  { SL("EXTENDS"),		PHVOLT_T_EXTENDS },
  { SL("IS"),			 PHVOLT_T_IS },
  { SL("DEFINED"),		PHVOLT_T_DEFINED },
  { SL("EMPTY"),		  PHVOLT_T_EMPTY },
  { SL("EVEN"),		   PHVOLT_T_EVEN },
  { SL("ODD"),			PHVOLT_T_ODD },
  { SL("NUMERIC"),		PHVOLT_T_NUMERIC },
  { SL("SCALAR"),		 PHVOLT_T_SCALAR },
  { SL("ITERABLE"),	   PHVOLT_T_ITERABLE },
  { SL("INCLUDE"),		PHVOLT_T_INCLUDE },
  { SL("DO"),			 PHVOLT_T_DO },
  { SL("WHITESPACE"),	 PHVOLT_T_IGNORE },
  { SL("AUTOESCAPE"),	 PHVOLT_T_AUTOESCAPE },
  { SL("ENDAUTOESCAPE"),  PHVOLT_T_ENDAUTOESCAPE },
  { SL("CONTINUE"),	   PHVOLT_T_CONTINUE },
  { SL("BREAK"),		  PHVOLT_T_BREAK },
  { SL("WITH"),		   PHVOLT_T_WITH },
  { SL("RETURN"),		 PHVOLT_T_RETURN },
  { SL("MACRO"),		  PHVOLT_T_MACRO },
  { SL("ENDMACRO"),	   PHVOLT_T_ENDMACRO },
  { SL("CALL"),		   PHVOLT_T_CALL },
  { SL("WITH"),		   PHVOLT_T_WITH },
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
	state->forced_raw_state = 0;

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

			case PHVOLT_T_RAW:
				phvolt_(phvolt_parser, PHVOLT_RAW, NULL, parser_status);
				state->forced_raw_state++;
				break;
			case PHVOLT_T_ENDRAW:
				phvolt_(phvolt_parser, PHVOLT_ENDRAW, NULL, parser_status);
				state->forced_raw_state--;
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
