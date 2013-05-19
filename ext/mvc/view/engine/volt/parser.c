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


// 507 "parser.c"
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
#define KKNOCODE 98
#define KKACTIONTYPE unsigned short int
#define phvolt_KTOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_KTOKENTYPE kk0;
  zval* kk66;
  int kk195;
} KKMINORTYPE;
#define KKSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = kkpParser->status
#define phvolt_ARG_STORE kkpParser->status = status
#define KKNSTATE 270
#define KKNRULE 113
#define KKERRORSYMBOL 65
#define KKERRSYMDT kk195
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
 /*     0 */    80,   88,  270,   85,   58,   50,   52,   62,   60,   64,
 /*    10 */    70,   72,   74,   76,   66,   68,   46,   44,   48,   41,
 /*    20 */    38,   54,   56,   82,   92,   78,  247,  154,   80,   88,
 /*    30 */    28,   85,   58,   50,   52,   62,   60,   64,   70,   72,
 /*    40 */    74,   76,   66,   68,   46,   44,   48,   41,   38,   54,
 /*    50 */    56,   82,   92,   78,   30,  183,   46,   44,   48,   41,
 /*    60 */    38,   54,   56,   82,   92,   78,   34,   23,  219,   82,
 /*    70 */    92,   78,   80,   88,  109,   85,   58,   50,   52,   62,
 /*    80 */    60,   64,   70,   72,   74,   76,   66,   68,   46,   44,
 /*    90 */    48,   41,   38,   54,   56,   82,   92,   78,  263,  258,
 /*   100 */    80,   88,   83,   85,   58,   50,   52,   62,   60,   64,
 /*   110 */    70,   72,   74,   76,   66,   68,   46,   44,   48,   41,
 /*   120 */    38,   54,   56,   82,   92,   78,  107,   24,   80,   88,
 /*   130 */   128,   85,   58,   50,   52,   62,   60,   64,   70,   72,
 /*   140 */    74,   76,   66,   68,   46,   44,   48,   41,   38,   54,
 /*   150 */    56,   82,   92,   78,  123,   37,   80,   88,  104,   85,
 /*   160 */    58,   50,   52,   62,   60,   64,   70,   72,   74,   76,
 /*   170 */    66,   68,   46,   44,   48,   41,   38,   54,   56,   82,
 /*   180 */    92,   78,   80,   88,   90,   85,   58,   50,   52,   62,
 /*   190 */    60,   64,   70,   72,   74,   76,   66,   68,   46,   44,
 /*   200 */    48,   41,   38,   54,   56,   82,   92,   78,   41,   38,
 /*   210 */    54,   56,   82,   92,   78,  129,   36,   87,  228,  246,
 /*   220 */   103,   80,   88,  109,   85,   58,   50,   52,   62,   60,
 /*   230 */    64,   70,   72,   74,   76,   66,   68,   46,   44,   48,
 /*   240 */    41,   38,   54,   56,   82,   92,   78,  240,  241,  242,
 /*   250 */   243,  244,  245,   56,   82,   92,   78,  363,  147,   98,
 /*   260 */   364,  254,  152,   80,   88,  109,   85,   58,   50,   52,
 /*   270 */    62,   60,   64,   70,   72,   74,   76,   66,   68,   46,
 /*   280 */    44,   48,   41,   38,   54,   56,   82,   92,   78,  133,
 /*   290 */   163,   80,   88,  135,   85,   58,   50,   52,   62,   60,
 /*   300 */    64,   70,   72,   74,   76,   66,   68,   46,   44,   48,
 /*   310 */    41,   38,   54,   56,   82,   92,   78,  136,  196,   80,
 /*   320 */    88,  149,   85,   58,   50,   52,   62,   60,   64,   70,
 /*   330 */    72,   74,   76,   66,   68,   46,   44,   48,   41,   38,
 /*   340 */    54,   56,   82,   92,   78,  384,    1,    2,  212,    4,
 /*   350 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   360 */    15,   16,   17,   18,   19,   20,  210,  237,  198,  213,
 /*   370 */    80,   88,  167,   85,   58,   50,   52,   62,   60,   64,
 /*   380 */    70,   72,   74,   76,   66,   68,   46,   44,   48,   41,
 /*   390 */    38,   54,   56,   82,   92,   78,  363,  249,   80,   88,
 /*   400 */   151,   85,   58,   50,   52,   62,   60,   64,   70,   72,
 /*   410 */    74,   76,   66,   68,   46,   44,   48,   41,   38,   54,
 /*   420 */    56,   82,   92,   78,  364,  265,   80,   88,  158,   85,
 /*   430 */    58,   50,   52,   62,   60,   64,   70,   72,   74,   76,
 /*   440 */    66,   68,   46,   44,   48,   41,   38,   54,   56,   82,
 /*   450 */    92,   78,   88,  160,   85,   58,   50,   52,   62,   60,
 /*   460 */    64,   70,   72,   74,   76,   66,   68,   46,   44,   48,
 /*   470 */    41,   38,   54,   56,   82,   92,   78,   85,   58,   50,
 /*   480 */    52,   62,   60,   64,   70,   72,   74,   76,   66,   68,
 /*   490 */    46,   44,   48,   41,   38,   54,   56,   82,   92,   78,
 /*   500 */    50,   52,   62,   60,   64,   70,   72,   74,   76,   66,
 /*   510 */    68,   46,   44,   48,   41,   38,   54,   56,   82,   92,
 /*   520 */    78,   25,  212,    4,    5,    6,    7,    8,    9,   10,
 /*   530 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   540 */    31,  212,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   550 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   62,
 /*   560 */    60,   64,   70,   72,   74,   76,   66,   68,   46,   44,
 /*   570 */    48,   41,   38,   54,   56,   82,   92,   78,  155,  212,
 /*   580 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   590 */    14,   15,   16,   17,   18,   19,   20,  169,  212,    4,
 /*   600 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   610 */    15,   16,   17,   18,   19,   20,  177,  212,    4,    5,
 /*   620 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   630 */    16,   17,   18,   19,   20,  184,  212,    4,    5,    6,
 /*   640 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   650 */    17,   18,   19,   20,  200,  212,    4,    5,    6,    7,
 /*   660 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   670 */    18,   19,   20,  215,  212,    4,    5,    6,    7,    8,
 /*   680 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   690 */    19,   20,  221,  212,    4,    5,    6,    7,    8,    9,
 /*   700 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   710 */    20,  231,  212,    4,    5,    6,    7,    8,    9,   10,
 /*   720 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   730 */   250,  212,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   740 */    12,   13,   14,   15,   16,   17,   18,   19,   20,  259,
 /*   750 */   212,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   760 */    13,   14,   15,   16,   17,   18,   19,   20,  266,  212,
 /*   770 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   780 */    14,   15,   16,   17,   18,   19,   20,    3,    4,    5,
 /*   790 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   800 */    16,   17,   18,   19,   20,   22,  173,   27,   29,   35,
 /*   810 */   148,  150,  161,   40,  159,  165,  164,   22,  173,   33,
 /*   820 */   109,   35,  148,  150,  166,  168,  159,  174,  164,  181,
 /*   830 */   172,  188,  191,  194,  197,   86,  204,  206,   21,  174,
 /*   840 */   132,  181,  109,  188,  191,  194,  197,  100,  204,  206,
 /*   850 */   175,   22,  173,  105,  109,   35,  148,  150,  176,  157,
 /*   860 */   159,   26,  164,   22,  173,  271,   21,   35,  148,  150,
 /*   870 */   180,  187,  159,  174,  164,  181,  171,  188,  191,  194,
 /*   880 */   197,  146,  204,  206,  190,  174,  208,  181,  109,  188,
 /*   890 */   191,  194,  197,   32,  204,  206,  193,   22,  173,  211,
 /*   900 */   156,   35,  148,  150,   93,  189,  159,  192,  164,  208,
 /*   910 */   131,  109,  118,  126,  208,  199,  237,  130,  203,  174,
 /*   920 */   179,  181,  211,  188,  191,  194,  197,  211,  204,  206,
 /*   930 */   205,   22,  173,  207,  214,   35,  148,  150,  134,  100,
 /*   940 */   159,  208,  164,  102,   43,  117,  109,  120,  208,  218,
 /*   950 */   170,  109,  238,  174,  211,  181,  186,  188,  191,  194,
 /*   960 */   197,  211,  204,  206,  220,   22,  173,  224,   93,   35,
 /*   970 */   148,  150,  227,   45,  159,  109,  164,  121,   47,  235,
 /*   980 */   109,   49,  230,   51,  236,  109,  119,  174,  109,  181,
 /*   990 */   109,  188,  191,  194,  197,  202,  204,  206,  208,   22,
 /*  1000 */   173,  234,  225,   35,  148,  150,  239,   53,  159,   55,
 /*  1010 */   164,  211,   57,   59,  109,   61,  109,   63,  229,  109,
 /*  1020 */   109,  174,  109,  181,  109,  188,  191,  194,  197,  217,
 /*  1030 */   204,  206,  253,   22,  173,  255,  178,   35,  148,  150,
 /*  1040 */   256,   65,  159,  262,  164,  269,   67,   69,  109,   71,
 /*  1050 */   208,  212,  185,  109,  109,  174,  109,  181,  223,  188,
 /*  1060 */   191,  194,  197,  211,  204,  206,  212,   22,  173,  212,
 /*  1070 */   201,   35,  148,  150,  212,   73,  159,  212,  164,  212,
 /*  1080 */    75,   77,  109,  212,  208,   79,  216,  109,  109,  174,
 /*  1090 */   226,  181,  109,  188,  191,  194,  197,  211,  204,  206,
 /*  1100 */   208,   22,  173,  212,  222,   35,  148,  150,   81,   84,
 /*  1110 */   159,  212,  164,  211,  233,  109,  109,   89,  208,   91,
 /*  1120 */   232,  212,  212,  174,  109,  181,  109,  188,  191,  194,
 /*  1130 */   197,  211,  204,  206,  208,   22,  173,  212,  251,   35,
 /*  1140 */   148,  150,   95,  252,  159,  212,  164,  211,   97,  109,
 /*  1150 */   212,  108,  208,  124,  260,  109,  212,  174,  109,  181,
 /*  1160 */   109,  188,  191,  194,  197,  211,  204,  206,  208,   22,
 /*  1170 */   173,  212,  267,   35,  148,  150,  212,  261,  159,  212,
 /*  1180 */   164,  211,  143,  131,  212,  145,  208,  153,  212,  109,
 /*  1190 */   130,  174,  109,  181,  109,  188,  191,  194,  197,  211,
 /*  1200 */   204,  206,  208,   22,  173,  212,  212,   35,  148,  150,
 /*  1210 */   212,  268,  159,  212,  164,  211,  162,  182,  212,  195,
 /*  1220 */   208,  209,  212,  109,  109,  174,  109,  181,  109,  188,
 /*  1230 */   191,  194,  197,  211,  204,  206,  212,   22,  173,  212,
 /*  1240 */   212,   35,  148,  150,  212,  248,  159,  257,  164,  264,
 /*  1250 */   212,  212,  109,  212,  109,  212,  109,  212,  212,  174,
 /*  1260 */   212,  181,  212,  188,  191,  194,  197,  212,  204,  206,
 /*  1270 */    99,  212,  212,  212,  212,  212,   99,  212,  212,  212,
 /*  1280 */   212,  212,  212,  212,  144,  212,   42,   39,  212,  142,
 /*  1290 */    94,   96,   42,   39,  212,  212,   94,   96,  212,  212,
 /*  1300 */   110,  212,  212,   99,  212,  212,  110,  111,  112,  113,
 /*  1310 */   114,  115,  116,  111,  112,  113,  114,  115,  116,   42,
 /*  1320 */    39,  212,  212,  139,   96,  212,  212,  212,  212,  212,
 /*  1330 */   127,   99,  212,  110,  212,  212,  212,  212,  212,  212,
 /*  1340 */   111,  112,  113,  114,  115,  116,  212,   42,   39,  212,
 /*  1350 */   212,   94,   96,  212,  212,  212,  212,  212,   99,  212,
 /*  1360 */   141,  138,  212,  212,  212,  212,  212,  212,  137,  112,
 /*  1370 */   113,  114,  115,  116,   42,   39,  212,  212,   94,   96,
 /*  1380 */   212,  212,  212,  212,  212,   99,  212,  212,  110,  212,
 /*  1390 */   212,  212,  212,  125,  212,  111,  122,  113,  114,  115,
 /*  1400 */   116,   42,   39,  212,  212,   94,   96,  212,  212,  212,
 /*  1410 */   212,  212,   99,  212,  212,  110,  212,  212,  212,  212,
 /*  1420 */   212,  212,  111,  106,  113,  114,  115,  116,   42,   39,
 /*  1430 */   212,  212,   94,   96,  212,  212,  212,  212,  212,  212,
 /*  1440 */    99,  212,  110,  101,  212,  212,  212,  212,  212,  111,
 /*  1450 */   112,  113,  114,  115,  116,  212,   42,   39,  212,  212,
 /*  1460 */    94,   96,  212,  212,  212,  212,  212,   99,  212,  140,
 /*  1470 */   110,  212,  212,  212,  212,  212,  212,  111,  112,  113,
 /*  1480 */   114,  115,  116,   42,   39,  212,  212,   94,   96,  212,
 /*  1490 */   212,  212,  212,  212,   99,  212,  212,  110,  212,  212,
 /*  1500 */   212,  212,  212,  212,  111,  106,  113,  114,  115,  116,
 /*  1510 */    42,   39,  212,  212,   94,   96,  212,  212,  212,  212,
 /*  1520 */   212,  212,  212,  212,  110,  212,  212,  212,  212,  212,
 /*  1530 */   212,  111,  122,  113,  114,  115,  116,
};
static KKCODETYPE kk_lookahead[] = {
 /*     0 */     3,    4,    0,    6,    7,    8,    9,   10,   11,   12,
 /*    10 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    20 */    23,   24,   25,   26,   27,   28,   29,   30,    3,    4,
 /*    30 */    30,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*    40 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*    50 */    25,   26,   27,   28,   30,   30,   19,   20,   21,   22,
 /*    60 */    23,   24,   25,   26,   27,   28,   30,   87,   43,   26,
 /*    70 */    27,   28,    3,    4,   94,    6,    7,    8,    9,   10,
 /*    80 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    90 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
 /*   100 */     3,    4,    3,    6,    7,    8,    9,   10,   11,   12,
 /*   110 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   120 */    23,   24,   25,   26,   27,   28,    5,   30,    3,    4,
 /*   130 */    92,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   140 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   150 */    25,   26,   27,   28,    5,   30,    3,    4,    2,    6,
 /*   160 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   170 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   180 */    27,   28,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   190 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   200 */    21,   22,   23,   24,   25,   26,   27,   28,   22,   23,
 /*   210 */    24,   25,   26,   27,   28,   64,   87,   64,   88,   89,
 /*   220 */    64,    3,    4,   94,    6,    7,    8,    9,   10,   11,
 /*   230 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   240 */    22,   23,   24,   25,   26,   27,   28,   43,   44,   45,
 /*   250 */    46,   47,   48,   25,   26,   27,   28,   64,   87,   41,
 /*   260 */    64,    2,    3,    3,    4,   94,    6,    7,    8,    9,
 /*   270 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   280 */    20,   21,   22,   23,   24,   25,   26,   27,   28,    5,
 /*   290 */    30,    3,    4,   92,    6,    7,    8,    9,   10,   11,
 /*   300 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   310 */    22,   23,   24,   25,   26,   27,   28,   64,   30,    3,
 /*   320 */     4,   30,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   330 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   340 */    24,   25,   26,   27,   28,   66,   67,   68,   69,   70,
 /*   350 */    71,   72,   73,   74,   75,   76,   77,   78,   79,   80,
 /*   360 */    81,   82,   83,   84,   85,   86,   50,   36,   47,   48,
 /*   370 */     3,    4,   41,    6,    7,    8,    9,   10,   11,   12,
 /*   380 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   390 */    23,   24,   25,   26,   27,   28,    5,   30,    3,    4,
 /*   400 */    36,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   410 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   420 */    25,   26,   27,   28,    5,   30,    3,    4,   30,    6,
 /*   430 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   440 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   450 */    27,   28,    4,   36,    6,    7,    8,    9,   10,   11,
 /*   460 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   470 */    22,   23,   24,   25,   26,   27,   28,    6,    7,    8,
 /*   480 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   490 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   500 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   510 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   520 */    28,   68,   69,   70,   71,   72,   73,   74,   75,   76,
 /*   530 */    77,   78,   79,   80,   81,   82,   83,   84,   85,   86,
 /*   540 */    68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
 /*   550 */    78,   79,   80,   81,   82,   83,   84,   85,   86,   10,
 /*   560 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   570 */    21,   22,   23,   24,   25,   26,   27,   28,   68,   69,
 /*   580 */    70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
 /*   590 */    80,   81,   82,   83,   84,   85,   86,   68,   69,   70,
 /*   600 */    71,   72,   73,   74,   75,   76,   77,   78,   79,   80,
 /*   610 */    81,   82,   83,   84,   85,   86,   68,   69,   70,   71,
 /*   620 */    72,   73,   74,   75,   76,   77,   78,   79,   80,   81,
 /*   630 */    82,   83,   84,   85,   86,   68,   69,   70,   71,   72,
 /*   640 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   650 */    83,   84,   85,   86,   68,   69,   70,   71,   72,   73,
 /*   660 */    74,   75,   76,   77,   78,   79,   80,   81,   82,   83,
 /*   670 */    84,   85,   86,   68,   69,   70,   71,   72,   73,   74,
 /*   680 */    75,   76,   77,   78,   79,   80,   81,   82,   83,   84,
 /*   690 */    85,   86,   68,   69,   70,   71,   72,   73,   74,   75,
 /*   700 */    76,   77,   78,   79,   80,   81,   82,   83,   84,   85,
 /*   710 */    86,   68,   69,   70,   71,   72,   73,   74,   75,   76,
 /*   720 */    77,   78,   79,   80,   81,   82,   83,   84,   85,   86,
 /*   730 */    68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
 /*   740 */    78,   79,   80,   81,   82,   83,   84,   85,   86,   68,
 /*   750 */    69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
 /*   760 */    79,   80,   81,   82,   83,   84,   85,   86,   68,   69,
 /*   770 */    70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
 /*   780 */    80,   81,   82,   83,   84,   85,   86,   69,   70,   71,
 /*   790 */    72,   73,   74,   75,   76,   77,   78,   79,   80,   81,
 /*   800 */    82,   83,   84,   85,   86,   29,   30,   31,   32,   33,
 /*   810 */    34,   35,   39,   87,   38,   36,   40,   29,   30,   31,
 /*   820 */    94,   33,   34,   35,   27,   30,   38,   51,   40,   53,
 /*   830 */    30,   55,   56,   57,   58,   87,   60,   61,    1,   51,
 /*   840 */    92,   53,   94,   55,   56,   57,   58,   87,   60,   61,
 /*   850 */    36,   29,   30,   93,   94,   33,   34,   35,   30,   37,
 /*   860 */    38,    1,   40,   29,   30,    0,    1,   33,   34,   35,
 /*   870 */    30,   30,   38,   51,   40,   53,   42,   55,   56,   57,
 /*   880 */    58,   87,   60,   61,   30,   51,   49,   53,   94,   55,
 /*   890 */    56,   57,   58,    1,   60,   61,   30,   29,   30,   62,
 /*   900 */     1,   33,   34,   35,   87,   44,   38,   44,   40,   49,
 /*   910 */    36,   94,   95,   96,   49,   30,   36,   43,   30,   51,
 /*   920 */    52,   53,   62,   55,   56,   57,   58,   62,   60,   61,
 /*   930 */    30,   29,   30,   30,   30,   33,   34,   35,   64,   87,
 /*   940 */    38,   49,   40,   91,   87,   93,   94,    2,   49,   30,
 /*   950 */     1,   94,   39,   51,   62,   53,   54,   55,   56,   57,
 /*   960 */    58,   62,   60,   61,   30,   29,   30,   30,   87,   33,
 /*   970 */    34,   35,   30,   87,   38,   94,   40,   96,   87,    2,
 /*   980 */    94,   87,   30,   87,   89,   94,   41,   51,   94,   53,
 /*   990 */    94,   55,   56,   57,   58,   59,   60,   61,   49,   29,
 /*  1000 */    30,   30,    1,   33,   34,   35,   90,   87,   38,   87,
 /*  1010 */    40,   62,   87,   87,   94,   87,   94,   87,   41,   94,
 /*  1020 */    94,   51,   94,   53,   94,   55,   56,   57,   58,   59,
 /*  1030 */    60,   61,   30,   29,   30,   36,    1,   33,   34,   35,
 /*  1040 */     3,   87,   38,   30,   40,   30,   87,   87,   94,   87,
 /*  1050 */    49,   97,    1,   94,   94,   51,   94,   53,   54,   55,
 /*  1060 */    56,   57,   58,   62,   60,   61,   97,   29,   30,   97,
 /*  1070 */     1,   33,   34,   35,   97,   87,   38,   97,   40,   97,
 /*  1080 */    87,   87,   94,   97,   49,   87,    1,   94,   94,   51,
 /*  1090 */    52,   53,   94,   55,   56,   57,   58,   62,   60,   61,
 /*  1100 */    49,   29,   30,   97,    1,   33,   34,   35,   87,   87,
 /*  1110 */    38,   97,   40,   62,   42,   94,   94,   87,   49,   87,
 /*  1120 */     1,   97,   97,   51,   94,   53,   94,   55,   56,   57,
 /*  1130 */    58,   62,   60,   61,   49,   29,   30,   97,    1,   33,
 /*  1140 */    34,   35,   87,   37,   38,   97,   40,   62,   87,   94,
 /*  1150 */    97,   87,   49,   87,    1,   94,   97,   51,   94,   53,
 /*  1160 */    94,   55,   56,   57,   58,   62,   60,   61,   49,   29,
 /*  1170 */    30,   97,    1,   33,   34,   35,   97,   37,   38,   97,
 /*  1180 */    40,   62,   87,   36,   97,   87,   49,   87,   97,   94,
 /*  1190 */    43,   51,   94,   53,   94,   55,   56,   57,   58,   62,
 /*  1200 */    60,   61,   49,   29,   30,   97,   97,   33,   34,   35,
 /*  1210 */    97,   37,   38,   97,   40,   62,   87,   87,   97,   87,
 /*  1220 */    49,   87,   97,   94,   94,   51,   94,   53,   94,   55,
 /*  1230 */    56,   57,   58,   62,   60,   61,   97,   29,   30,   97,
 /*  1240 */    97,   33,   34,   35,   97,   87,   38,   87,   40,   87,
 /*  1250 */    97,   97,   94,   97,   94,   97,   94,   97,   97,   51,
 /*  1260 */    97,   53,   97,   55,   56,   57,   58,   97,   60,   61,
 /*  1270 */     6,   97,   97,   97,   97,   97,    6,   97,   97,   97,
 /*  1280 */    97,   97,   97,   97,   20,   97,   22,   23,   97,   19,
 /*  1290 */    26,   27,   22,   23,   97,   97,   26,   27,   97,   97,
 /*  1300 */    36,   97,   97,    6,   97,   97,   36,   43,   44,   45,
 /*  1310 */    46,   47,   48,   43,   44,   45,   46,   47,   48,   22,
 /*  1320 */    23,   97,   97,   26,   27,   97,   97,   97,   97,   97,
 /*  1330 */     5,    6,   97,   36,   97,   97,   97,   97,   97,   97,
 /*  1340 */    43,   44,   45,   46,   47,   48,   97,   22,   23,   97,
 /*  1350 */    97,   26,   27,   97,   97,   97,   97,   97,    6,   97,
 /*  1360 */    63,   36,   97,   97,   97,   97,   97,   97,   43,   44,
 /*  1370 */    45,   46,   47,   48,   22,   23,   97,   97,   26,   27,
 /*  1380 */    97,   97,   97,   97,   97,    6,   97,   97,   36,   97,
 /*  1390 */    97,   97,   97,   41,   97,   43,   44,   45,   46,   47,
 /*  1400 */    48,   22,   23,   97,   97,   26,   27,   97,   97,   97,
 /*  1410 */    97,   97,    6,   97,   97,   36,   97,   97,   97,   97,
 /*  1420 */    97,   97,   43,   44,   45,   46,   47,   48,   22,   23,
 /*  1430 */    97,   97,   26,   27,   97,   97,   97,   97,   97,   97,
 /*  1440 */     6,   97,   36,   64,   97,   97,   97,   97,   97,   43,
 /*  1450 */    44,   45,   46,   47,   48,   97,   22,   23,   97,   97,
 /*  1460 */    26,   27,   97,   97,   97,   97,   97,    6,   97,   63,
 /*  1470 */    36,   97,   97,   97,   97,   97,   97,   43,   44,   45,
 /*  1480 */    46,   47,   48,   22,   23,   97,   97,   26,   27,   97,
 /*  1490 */    97,   97,   97,   97,    6,   97,   97,   36,   97,   97,
 /*  1500 */    97,   97,   97,   97,   43,   44,   45,   46,   47,   48,
 /*  1510 */    22,   23,   97,   97,   26,   27,   97,   97,   97,   97,
 /*  1520 */    97,   97,   97,   97,   36,   97,   97,   97,   97,   97,
 /*  1530 */    97,   43,   44,   45,   46,   47,   48,
};
#define KK_SHIFT_USE_DFLT (-4)
static short kk_shift_ofst[] = {
 /*     0 */   837,    2,  865,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    20 */    -4, 1208, 1434,   97,  837,  860,  776,    0,   -4,   24,
 /*    30 */   837,  892,  788,   36,   -4, 1434,  125,   -4, 1434, 1434,
 /*    40 */   228, 1434, 1434,  228, 1264,  186, 1270,  186, 1434,  186,
 /*    50 */  1434,  549, 1434,  549, 1434,  228, 1434,   43, 1434,  492,
 /*    60 */  1434,   37, 1297,   37, 1434,   37, 1434,   37, 1434,   37,
 /*    70 */  1434,   37, 1434,   37, 1434,   37, 1434,   37, 1434,   -4,
 /*    80 */  1434,  448,   99, 1434,   43, 1325,  153,   -4, 1434,  179,
 /*    90 */  1434,  471, 1352,  423, 1434,   43, 1434,  218,   -4, 1379,
 /*   100 */   423,   -4,  156,   -4, 1461,   -4,  121, 1434,  423,   -4,
 /*   110 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,  945,   -4,
 /*   120 */  1488,   -4,  149, 1434,  423,   -4,   -4, 1147,  151,   -4,
 /*   130 */   193,  196,  284,  874,   -4,  253,   -4,  391,  419, 1406,
 /*   140 */    -4,   -4, 1434,  186, 1434,  186,  228,  228,  291,   -4,
 /*   150 */   364,  259, 1434,   -3,  837,  899,  822,  398,   -4,  417,
 /*   160 */   773, 1434,  260,   -4,  779,  797,  331,  795,  837,  949,
 /*   170 */   834,  800,   -4,   -4,  814,  828, 1001, 1035,  868,  840,
 /*   180 */    -4, 1434,   25,  837, 1051,  902,  841,   -4,  861,  854,
 /*   190 */    -4,  863,  866,   -4, 1434,  288,   -4,  321,  885,  837,
 /*   200 */  1069,  936,  888,   -4,  900,   -4,  903,   -4, 1434,  316,
 /*   210 */    -4,   -4,   -4,  904,  837, 1085,  970,  919,   -4,  934,
 /*   220 */   837, 1103, 1004,  937,   -4, 1038,  942,   -4,  977,  952,
 /*   230 */   837, 1119, 1072,  971,   -4,  880,   -4,  913,  204,   -4,
 /*   240 */    -4,   -4,   -4,   -4,   -4,   -4,   -4, 1434,  367,  837,
 /*   250 */  1137, 1106, 1002,   -4,  999, 1037, 1434,   69,  837, 1153,
 /*   260 */  1140, 1013,   -4, 1434,  395,  837, 1171, 1174, 1015,   -4,
};
#define KK_REDUCE_USE_DFLT (-21)
static short kk_reduce_ofst[] = {
 /*     0 */   279,  -21,  718,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
 /*    10 */   -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
 /*    20 */   -21,  -21,  -20,  -21,  453,  718,  -21,  -21,  -21,  -21,
 /*    30 */   472,  718,  -21,  -21,  -21,  129,  -21,  -21,  171,  726,
 /*    40 */   -21,  794,  857,  -21,  886,  -21,  891,  -21,  894,  -21,
 /*    50 */   896,  -21,  920,  -21,  922,  -21,  925,  -21,  926,  -21,
 /*    60 */   928,  -21,  930,  -21,  954,  -21,  959,  -21,  960,  -21,
 /*    70 */   962,  -21,  988,  -21,  993,  -21,  994,  -21,  998,  -21,
 /*    80 */  1021,  -21,  -21, 1022,  -21,  748,  -21,  -21, 1030,  -21,
 /*    90 */  1032,  -21,  817,  -21, 1055,  -21, 1061,  -21,  -21,  852,
 /*   100 */   -21,  -21,  -21,  -21,  760,  -21,  -21, 1064,  -21,  -21,
 /*   110 */   -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
 /*   120 */   881,  -21,  -21, 1066,  -21,  -21,  -21,   38,  -21,  -21,
 /*   130 */   -21,  -21,  -21,  201,  -21,  -21,  -21,  -21,  -21, 1055,
 /*   140 */   -21,  -21, 1095,  -21, 1098,  -21,  -21,  -21,  -21,  -21,
 /*   150 */   -21,  -21, 1100,  -21,  510,  718,  -21,  -21,  -21,  -21,
 /*   160 */   -21, 1129,  -21,  -21,  -21,  -21,  130,  -21,  529,  718,
 /*   170 */   -21,  -21,  -21,  -21,  -21,  -21,  548,  718,  -21,  -21,
 /*   180 */   -21, 1130,  -21,  567,  718,  -21,  -21,  -21,  -21,  -21,
 /*   190 */   -21,  -21,  -21,  -21, 1132,  -21,  -21,  -21,  -21,  586,
 /*   200 */   718,  -21,  -21,  -21,  -21,  -21,  -21,  -21, 1134,  -21,
 /*   210 */   -21,  -21,  -21,  -21,  605,  718,  -21,  -21,  -21,  -21,
 /*   220 */   624,  718,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
 /*   230 */   643,  718,  -21,  -21,  -21,  895,  -21,  -21,  916,  -21,
 /*   240 */   -21,  -21,  -21,  -21,  -21,  -21,  -21, 1158,  -21,  662,
 /*   250 */   718,  -21,  -21,  -21,  -21,  -21, 1160,  -21,  681,  718,
 /*   260 */   -21,  -21,  -21, 1162,  -21,  700,  718,  -21,  -21,  -21,
};
static KKACTIONTYPE kk_default[] = {
 /*     0 */   383,  383,  383,  272,  274,  275,  276,  277,  278,  279,
 /*    10 */   280,  281,  282,  283,  284,  285,  286,  287,  288,  289,
 /*    20 */   290,  383,  383,  383,  383,  383,  383,  383,  291,  383,
 /*    30 */   383,  383,  383,  383,  292,  383,  383,  293,  383,  383,
 /*    40 */   326,  383,  383,  327,  383,  330,  383,  332,  383,  334,
 /*    50 */   383,  335,  383,  336,  383,  337,  383,  338,  383,  339,
 /*    60 */   383,  340,  383,  343,  383,  344,  383,  345,  383,  346,
 /*    70 */   383,  347,  383,  348,  383,  349,  383,  350,  383,  351,
 /*    80 */   383,  352,  383,  383,  353,  383,  383,  358,  383,  383,
 /*    90 */   383,  359,  383,  374,  383,  354,  383,  383,  355,  383,
 /*   100 */   368,  356,  383,  357,  383,  365,  378,  383,  367,  369,
 /*   110 */   376,  377,  378,  379,  380,  381,  382,  366,  383,  370,
 /*   120 */   383,  372,  378,  383,  375,  371,  373,  383,  383,  360,
 /*   130 */   383,  383,  383,  383,  361,  383,  362,  377,  376,  383,
 /*   140 */   341,  342,  383,  333,  383,  331,  329,  328,  383,  294,
 /*   150 */   383,  383,  383,  383,  383,  383,  383,  383,  295,  383,
 /*   160 */   383,  383,  383,  299,  383,  383,  383,  383,  383,  383,
 /*   170 */   383,  383,  300,  312,  383,  383,  383,  383,  383,  383,
 /*   180 */   314,  383,  383,  383,  383,  383,  383,  316,  383,  383,
 /*   190 */   318,  383,  383,  319,  383,  383,  320,  383,  383,  383,
 /*   200 */   383,  383,  383,  321,  383,  323,  383,  324,  383,  383,
 /*   210 */   313,  325,  273,  383,  383,  383,  383,  383,  322,  383,
 /*   220 */   383,  383,  383,  383,  317,  383,  383,  315,  383,  383,
 /*   230 */   383,  383,  383,  383,  301,  383,  302,  304,  383,  305,
 /*   240 */   306,  307,  308,  309,  310,  311,  303,  383,  383,  383,
 /*   250 */   383,  383,  383,  296,  383,  383,  383,  383,  383,  383,
 /*   260 */   383,  383,  297,  383,  383,  383,  383,  383,  383,  298,
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
  "TRUE",          "OPEN_EDELIMITER",  "CLOSE_EDELIMITER",  "BLOCK",       
  "ENDBLOCK",      "CACHE",         "ENDCACHE",      "EXTENDS",     
  "INCLUDE",       "DO",            "AUTOESCAPE",    "ENDAUTOESCAPE",
  "BREAK",         "CONTINUE",      "RAW_FRAGMENT",  "DEFINED",     
  "SBRACKET_CLOSE",  "error",         "program",       "volt_language",
  "statement_list",  "statement",     "raw_fragment",  "if_statement",
  "elseif_statement",  "elsefor_statement",  "for_statement",  "set_statement",
  "echo_statement",  "block_statement",  "cache_statement",  "extends_statement",
  "include_statement",  "do_statement",  "autoescape_statement",  "break_statement",
  "continue_statement",  "macro_statement",  "empty_statement",  "expr",        
  "macro_parameters",  "macro_parameter",  "macro_parameter_default",  "array_list",  
  "slice_offset",  "array_item",    "function_call",  "argument_list",
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
 /*  21 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  22 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  23 */ "elseif_statement ::= OPEN_DELIMITER ELSEIF expr CLOSE_DELIMITER",
 /*  24 */ "elsefor_statement ::= OPEN_DELIMITER ELSEFOR CLOSE_DELIMITER",
 /*  25 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  26 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  27 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  28 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  29 */ "set_statement ::= OPEN_DELIMITER SET IDENTIFIER ASSIGN expr CLOSE_DELIMITER",
 /*  30 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  31 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN macro_parameters PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  32 */ "macro_parameters ::= macro_parameters COMMA macro_parameter",
 /*  33 */ "macro_parameters ::= macro_parameter",
 /*  34 */ "macro_parameter ::= IDENTIFIER",
 /*  35 */ "macro_parameter ::= IDENTIFIER ASSIGN macro_parameter_default",
 /*  36 */ "macro_parameter_default ::= INTEGER",
 /*  37 */ "macro_parameter_default ::= STRING",
 /*  38 */ "macro_parameter_default ::= DOUBLE",
 /*  39 */ "macro_parameter_default ::= NULL",
 /*  40 */ "macro_parameter_default ::= FALSE",
 /*  41 */ "macro_parameter_default ::= TRUE",
 /*  42 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  43 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  44 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  45 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  46 */ "cache_statement ::= OPEN_DELIMITER CACHE expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  47 */ "cache_statement ::= OPEN_DELIMITER CACHE expr INTEGER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  48 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  49 */ "include_statement ::= OPEN_DELIMITER INCLUDE STRING CLOSE_DELIMITER",
 /*  50 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  51 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE FALSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  52 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE TRUE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  53 */ "break_statement ::= OPEN_DELIMITER BREAK CLOSE_DELIMITER",
 /*  54 */ "continue_statement ::= OPEN_DELIMITER CONTINUE CLOSE_DELIMITER",
 /*  55 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  56 */ "expr ::= MINUS expr",
 /*  57 */ "expr ::= PLUS expr",
 /*  58 */ "expr ::= expr MINUS expr",
 /*  59 */ "expr ::= expr PLUS expr",
 /*  60 */ "expr ::= expr TIMES expr",
 /*  61 */ "expr ::= expr TIMES TIMES expr",
 /*  62 */ "expr ::= expr DIVIDE expr",
 /*  63 */ "expr ::= expr DIVIDE DIVIDE expr",
 /*  64 */ "expr ::= expr MOD expr",
 /*  65 */ "expr ::= expr AND expr",
 /*  66 */ "expr ::= expr OR expr",
 /*  67 */ "expr ::= expr CONCAT expr",
 /*  68 */ "expr ::= expr PIPE expr",
 /*  69 */ "expr ::= expr RANGE expr",
 /*  70 */ "expr ::= expr EQUALS expr",
 /*  71 */ "expr ::= expr IS NOT DEFINED",
 /*  72 */ "expr ::= expr IS DEFINED",
 /*  73 */ "expr ::= expr IS expr",
 /*  74 */ "expr ::= expr NOTEQUALS expr",
 /*  75 */ "expr ::= expr IDENTICAL expr",
 /*  76 */ "expr ::= expr NOTIDENTICAL expr",
 /*  77 */ "expr ::= expr LESS expr",
 /*  78 */ "expr ::= expr GREATER expr",
 /*  79 */ "expr ::= expr GREATEREQUAL expr",
 /*  80 */ "expr ::= expr LESSEQUAL expr",
 /*  81 */ "expr ::= expr DOT expr",
 /*  82 */ "expr ::= expr IN expr",
 /*  83 */ "expr ::= expr NOT IN expr",
 /*  84 */ "expr ::= NOT expr",
 /*  85 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /*  86 */ "expr ::= SBRACKET_OPEN SBRACKET_CLOSE",
 /*  87 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /*  88 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /*  89 */ "expr ::= expr QUESTION expr COLON expr",
 /*  90 */ "expr ::= expr SBRACKET_OPEN COLON slice_offset SBRACKET_CLOSE",
 /*  91 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON SBRACKET_CLOSE",
 /*  92 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON slice_offset SBRACKET_CLOSE",
 /*  93 */ "slice_offset ::= INTEGER",
 /*  94 */ "slice_offset ::= IDENTIFIER",
 /*  95 */ "array_list ::= array_list COMMA array_item",
 /*  96 */ "array_list ::= array_item",
 /*  97 */ "array_item ::= STRING COLON expr",
 /*  98 */ "array_item ::= expr",
 /*  99 */ "expr ::= function_call",
 /* 100 */ "function_call ::= expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 101 */ "function_call ::= expr PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 102 */ "argument_list ::= argument_list COMMA argument_item",
 /* 103 */ "argument_list ::= argument_item",
 /* 104 */ "argument_item ::= expr",
 /* 105 */ "argument_item ::= STRING COLON expr",
 /* 106 */ "expr ::= IDENTIFIER",
 /* 107 */ "expr ::= INTEGER",
 /* 108 */ "expr ::= STRING",
 /* 109 */ "expr ::= DOUBLE",
 /* 110 */ "expr ::= NULL",
 /* 111 */ "expr ::= FALSE",
 /* 112 */ "expr ::= TRUE",
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
// 588 "parser.lemon"
{
	if ((kkpminor->kk0)) {
		if ((kkpminor->kk0)->free_flag) {
			efree((kkpminor->kk0)->token);
		}
		efree((kkpminor->kk0));
	}
}
// 1385 "parser.c"
      break;
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
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
    case 96:
// 605 "parser.lemon"
{ zval_ptr_dtor(&(kkpminor->kk66)); }
// 1417 "parser.c"
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
  { 66, 1 },
  { 67, 1 },
  { 68, 2 },
  { 68, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 71, 8 },
  { 71, 12 },
  { 72, 4 },
  { 73, 3 },
  { 74, 10 },
  { 74, 12 },
  { 74, 12 },
  { 74, 14 },
  { 75, 6 },
  { 85, 10 },
  { 85, 11 },
  { 88, 3 },
  { 88, 1 },
  { 89, 1 },
  { 89, 3 },
  { 90, 1 },
  { 90, 1 },
  { 90, 1 },
  { 90, 1 },
  { 90, 1 },
  { 90, 1 },
  { 86, 2 },
  { 76, 3 },
  { 77, 8 },
  { 77, 7 },
  { 78, 8 },
  { 78, 9 },
  { 79, 4 },
  { 80, 4 },
  { 81, 4 },
  { 82, 8 },
  { 82, 8 },
  { 83, 3 },
  { 84, 3 },
  { 70, 1 },
  { 87, 2 },
  { 87, 2 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 4 },
  { 87, 3 },
  { 87, 4 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 4 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 4 },
  { 87, 2 },
  { 87, 3 },
  { 87, 2 },
  { 87, 3 },
  { 87, 4 },
  { 87, 5 },
  { 87, 5 },
  { 87, 5 },
  { 87, 6 },
  { 92, 1 },
  { 92, 1 },
  { 91, 3 },
  { 91, 1 },
  { 93, 3 },
  { 93, 1 },
  { 87, 1 },
  { 94, 4 },
  { 94, 3 },
  { 95, 3 },
  { 95, 1 },
  { 96, 1 },
  { 96, 3 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
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
// 597 "parser.lemon"
{
	status->ret = kkmsp[0].minor.kk66;
}
// 1747 "parser.c"
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
      case 99:
// 601 "parser.lemon"
{
	kkgotominor.kk66 = kkmsp[0].minor.kk66;
}
// 1772 "parser.c"
        break;
      case 2:
// 607 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_zval_list(kkmsp[-1].minor.kk66, kkmsp[0].minor.kk66);
}
// 1779 "parser.c"
        break;
      case 3:
      case 33:
      case 96:
      case 103:
// 611 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_zval_list(NULL, kkmsp[0].minor.kk66);
}
// 1789 "parser.c"
        break;
      case 21:
// 687 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_if_statement(kkmsp[-5].minor.kk66, kkmsp[-3].minor.kk66, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(29,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(31,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1802 "parser.c"
        break;
      case 22:
// 691 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_if_statement(kkmsp[-9].minor.kk66, kkmsp[-7].minor.kk66, kkmsp[-3].minor.kk66, status->scanner_state);
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
// 1818 "parser.c"
        break;
      case 23:
// 697 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_elseif_statement(kkmsp[-1].minor.kk66, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(33,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1828 "parser.c"
        break;
      case 24:
// 703 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_elsefor_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(34,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1838 "parser.c"
        break;
      case 25:
// 709 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-5].minor.kk66, NULL, kkmsp[-3].minor.kk66, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(35,&kkmsp[-8].minor);
  kk_destructor(3,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1852 "parser.c"
        break;
      case 26:
// 713 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, NULL, kkmsp[-7].minor.kk66, kkmsp[-5].minor.kk66, kkmsp[-3].minor.kk66, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(35,&kkmsp[-10].minor);
  kk_destructor(3,&kkmsp[-8].minor);
  kk_destructor(29,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1867 "parser.c"
        break;
      case 27:
// 717 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, kkmsp[-9].minor.kk0, kkmsp[-5].minor.kk66, NULL, kkmsp[-3].minor.kk66, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(35,&kkmsp[-10].minor);
  kk_destructor(2,&kkmsp[-8].minor);
  kk_destructor(3,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1882 "parser.c"
        break;
      case 28:
// 721 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, kkmsp[-11].minor.kk0, kkmsp[-7].minor.kk66, kkmsp[-5].minor.kk66, kkmsp[-3].minor.kk66, status->scanner_state);
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
// 1898 "parser.c"
        break;
      case 29:
// 727 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_set_statement(kkmsp[-3].minor.kk0, kkmsp[-1].minor.kk66, status->scanner_state);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(38,&kkmsp[-4].minor);
  kk_destructor(39,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1909 "parser.c"
        break;
      case 30:
// 733 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_macro_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-3].minor.kk66, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(40,&kkmsp[-8].minor);
  kk_destructor(27,&kkmsp[-6].minor);
  kk_destructor(41,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(42,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1924 "parser.c"
        break;
      case 31:
// 737 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_macro_statement(kkmsp[-8].minor.kk0, kkmsp[-6].minor.kk66, kkmsp[-3].minor.kk66, status->scanner_state);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(40,&kkmsp[-9].minor);
  kk_destructor(27,&kkmsp[-7].minor);
  kk_destructor(41,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(42,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1939 "parser.c"
        break;
      case 32:
      case 95:
      case 102:
// 743 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_zval_list(kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66);
  kk_destructor(2,&kkmsp[-1].minor);
}
// 1949 "parser.c"
        break;
      case 34:
// 753 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_macro_parameter(kkmsp[0].minor.kk0, NULL, status->scanner_state);
}
// 1956 "parser.c"
        break;
      case 35:
// 757 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_macro_parameter(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk66, status->scanner_state);
  kk_destructor(39,&kkmsp[-1].minor);
}
// 1964 "parser.c"
        break;
      case 36:
      case 93:
      case 107:
// 761 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 1973 "parser.c"
        break;
      case 37:
      case 108:
// 765 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_literal_zval(PHVOLT_T_STRING, kkmsp[0].minor.kk0, status->scanner_state);
}
// 1981 "parser.c"
        break;
      case 38:
      case 109:
// 769 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, kkmsp[0].minor.kk0, status->scanner_state);
}
// 1989 "parser.c"
        break;
      case 39:
      case 110:
// 773 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  kk_destructor(46,&kkmsp[0].minor);
}
// 1998 "parser.c"
        break;
      case 40:
      case 111:
// 777 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  kk_destructor(47,&kkmsp[0].minor);
}
// 2007 "parser.c"
        break;
      case 41:
      case 112:
// 781 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  kk_destructor(48,&kkmsp[0].minor);
}
// 2016 "parser.c"
        break;
      case 42:
// 787 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_empty_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2025 "parser.c"
        break;
      case 43:
// 793 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_echo_statement(kkmsp[-1].minor.kk66, status->scanner_state);
  kk_destructor(49,&kkmsp[-2].minor);
  kk_destructor(50,&kkmsp[0].minor);
}
// 2034 "parser.c"
        break;
      case 44:
// 799 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_block_statement(kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk66, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(51,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(52,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2047 "parser.c"
        break;
      case 45:
// 803 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_block_statement(kkmsp[-4].minor.kk0, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(51,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(52,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2060 "parser.c"
        break;
      case 46:
// 809 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_cache_statement(kkmsp[-5].minor.kk66, NULL, kkmsp[-3].minor.kk66, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(53,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(54,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2073 "parser.c"
        break;
      case 47:
// 813 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_cache_statement(kkmsp[-6].minor.kk66, kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk66, status->scanner_state);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(53,&kkmsp[-7].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(54,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2086 "parser.c"
        break;
      case 48:
// 819 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_extends_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(55,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2096 "parser.c"
        break;
      case 49:
// 825 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_include_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(56,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2106 "parser.c"
        break;
      case 50:
// 831 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_do_statement(kkmsp[-1].minor.kk66, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(57,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2116 "parser.c"
        break;
      case 51:
// 837 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_autoescape_statement(0, kkmsp[-3].minor.kk66, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(58,&kkmsp[-6].minor);
  kk_destructor(47,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(59,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2130 "parser.c"
        break;
      case 52:
// 841 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_autoescape_statement(1, kkmsp[-3].minor.kk66, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(58,&kkmsp[-6].minor);
  kk_destructor(48,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(59,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2144 "parser.c"
        break;
      case 53:
// 847 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_break_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(60,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2154 "parser.c"
        break;
      case 54:
// 853 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_continue_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(61,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2164 "parser.c"
        break;
      case 55:
// 859 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2171 "parser.c"
        break;
      case 56:
// 865 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
}
// 2179 "parser.c"
        break;
      case 57:
// 869 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_PLUS, NULL, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 2187 "parser.c"
        break;
      case 58:
// 873 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_SUB, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
}
// 2195 "parser.c"
        break;
      case 59:
// 877 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_ADD, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 2203 "parser.c"
        break;
      case 60:
// 881 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_MUL, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 2211 "parser.c"
        break;
      case 61:
// 885 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_POW, kkmsp[-3].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(20,&kkmsp[-2].minor);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 2220 "parser.c"
        break;
      case 62:
// 889 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_DIV, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 2228 "parser.c"
        break;
      case 63:
// 893 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-3].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(19,&kkmsp[-2].minor);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 2237 "parser.c"
        break;
      case 64:
// 897 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
// 2245 "parser.c"
        break;
      case 65:
// 901 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_AND, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(8,&kkmsp[-1].minor);
}
// 2253 "parser.c"
        break;
      case 66:
// 905 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_OR, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
}
// 2261 "parser.c"
        break;
      case 67:
// 909 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_CONCAT, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-1].minor);
}
// 2269 "parser.c"
        break;
      case 68:
// 913 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_PIPE, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(25,&kkmsp[-1].minor);
}
// 2277 "parser.c"
        break;
      case 69:
// 917 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_RANGE, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
}
// 2285 "parser.c"
        break;
      case 70:
// 921 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_EQUALS, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(11,&kkmsp[-1].minor);
}
// 2293 "parser.c"
        break;
      case 71:
// 925 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, kkmsp[-3].minor.kk66, NULL, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-2].minor);
  kk_destructor(26,&kkmsp[-1].minor);
  kk_destructor(63,&kkmsp[0].minor);
}
// 2303 "parser.c"
        break;
      case 72:
// 929 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_ISSET, kkmsp[-2].minor.kk66, NULL, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
  kk_destructor(63,&kkmsp[0].minor);
}
// 2312 "parser.c"
        break;
      case 73:
// 933 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_IS, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
}
// 2320 "parser.c"
        break;
      case 74:
// 937 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(12,&kkmsp[-1].minor);
}
// 2328 "parser.c"
        break;
      case 75:
// 941 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(17,&kkmsp[-1].minor);
}
// 2336 "parser.c"
        break;
      case 76:
// 945 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(18,&kkmsp[-1].minor);
}
// 2344 "parser.c"
        break;
      case 77:
// 949 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_LESS, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(13,&kkmsp[-1].minor);
}
// 2352 "parser.c"
        break;
      case 78:
// 953 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_GREATER, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(14,&kkmsp[-1].minor);
}
// 2360 "parser.c"
        break;
      case 79:
// 957 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(15,&kkmsp[-1].minor);
}
// 2368 "parser.c"
        break;
      case 80:
// 961 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(16,&kkmsp[-1].minor);
}
// 2376 "parser.c"
        break;
      case 81:
// 965 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_DOT, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(28,&kkmsp[-1].minor);
}
// 2384 "parser.c"
        break;
      case 82:
// 969 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_IN, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(3,&kkmsp[-1].minor);
}
// 2392 "parser.c"
        break;
      case 83:
// 973 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_NOT_IN, kkmsp[-3].minor.kk66, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(3,&kkmsp[-1].minor);
}
// 2401 "parser.c"
        break;
      case 84:
// 977 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, kkmsp[0].minor.kk66, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-1].minor);
}
// 2409 "parser.c"
        break;
      case 85:
// 981 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, kkmsp[-1].minor.kk66, NULL, NULL, status->scanner_state);
  kk_destructor(27,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[0].minor);
}
// 2418 "parser.c"
        break;
      case 86:
// 985 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-1].minor);
  kk_destructor(64,&kkmsp[0].minor);
}
// 2427 "parser.c"
        break;
      case 87:
// 989 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk66, NULL, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-2].minor);
  kk_destructor(64,&kkmsp[0].minor);
}
// 2436 "parser.c"
        break;
      case 88:
// 993 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, kkmsp[-3].minor.kk66, kkmsp[-1].minor.kk66, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-2].minor);
  kk_destructor(64,&kkmsp[0].minor);
}
// 2445 "parser.c"
        break;
      case 89:
// 997 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_expr(PHVOLT_T_TERNARY, kkmsp[-2].minor.kk66, kkmsp[0].minor.kk66, kkmsp[-4].minor.kk66, status->scanner_state);
  kk_destructor(4,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 2454 "parser.c"
        break;
      case 90:
// 1001 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_slice(kkmsp[-4].minor.kk66, NULL, kkmsp[-1].minor.kk66, status->scanner_state);
  kk_destructor(6,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-2].minor);
  kk_destructor(64,&kkmsp[0].minor);
}
// 2464 "parser.c"
        break;
      case 91:
// 1005 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_slice(kkmsp[-4].minor.kk66, kkmsp[-2].minor.kk66, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-1].minor);
  kk_destructor(64,&kkmsp[0].minor);
}
// 2474 "parser.c"
        break;
      case 92:
// 1009 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_slice(kkmsp[-5].minor.kk66, kkmsp[-3].minor.kk66, kkmsp[-1].minor.kk66, status->scanner_state);
  kk_destructor(6,&kkmsp[-4].minor);
  kk_destructor(5,&kkmsp[-2].minor);
  kk_destructor(64,&kkmsp[0].minor);
}
// 2484 "parser.c"
        break;
      case 94:
      case 106:
// 1019 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2492 "parser.c"
        break;
      case 97:
      case 105:
// 1035 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_named_item(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk66, status->scanner_state);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 2501 "parser.c"
        break;
      case 98:
      case 104:
// 1039 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_named_item(NULL, kkmsp[0].minor.kk66, status->scanner_state);
}
// 2509 "parser.c"
        break;
      case 100:
// 1049 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_func_call(kkmsp[-3].minor.kk66, kkmsp[-1].minor.kk66, status->scanner_state);
  kk_destructor(27,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[0].minor);
}
// 2518 "parser.c"
        break;
      case 101:
// 1053 "parser.lemon"
{
	kkgotominor.kk66 = phvolt_ret_func_call(kkmsp[-2].minor.kk66, NULL, status->scanner_state);
  kk_destructor(27,&kkmsp[-1].minor);
  kk_destructor(41,&kkmsp[0].minor);
}
// 2527 "parser.c"
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
// 540 "parser.lemon"

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

// 2617 "parser.c"
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
				phvolt_(phvolt_parser, PHVOLT_MACRO, NULL, parser_status);
				break;
			case PHVOLT_T_ENDMACRO:
				phvolt_(phvolt_parser, PHVOLT_ENDMACRO, NULL, parser_status);
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