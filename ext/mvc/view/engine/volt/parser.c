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


// 511 "parser.c"
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
#define KKNOCODE 99
#define KKACTIONTYPE unsigned short int
#define phvolt_KTOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_KTOKENTYPE kk0;
  zval* kk92;
  int kk197;
} KKMINORTYPE;
#define KKSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = kkpParser->status
#define phvolt_ARG_STORE kkpParser->status = status
#define KKNSTATE 284
#define KKNRULE 117
#define KKERRORSYMBOL 66
#define KKERRSYMDT kk197
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
 /*     0 */    80,   88,  284,   85,   58,   50,   52,   62,   60,   64,
 /*    10 */    70,   72,   74,   76,   66,   68,   46,   44,   48,   41,
 /*    20 */    38,   54,   56,   82,   92,   78,  250,  154,   80,   88,
 /*    30 */    28,   85,   58,   50,   52,   62,   60,   64,   70,   72,
 /*    40 */    74,   76,   66,   68,   46,   44,   48,   41,   38,   54,
 /*    50 */    56,   82,   92,   78,   30,  183,   46,   44,   48,   41,
 /*    60 */    38,   54,   56,   82,   92,   78,  104,   23,  222,   82,
 /*    70 */    92,   78,   80,   88,  109,   85,   58,   50,   52,   62,
 /*    80 */    60,   64,   70,   72,   74,   76,   66,   68,   46,   44,
 /*    90 */    48,   41,   38,   54,   56,   82,   92,   78,   34,  193,
 /*   100 */    80,   88,   83,   85,   58,   50,   52,   62,   60,   64,
 /*   110 */    70,   72,   74,   76,   66,   68,   46,   44,   48,   41,
 /*   120 */    38,   54,   56,   82,   92,   78,  194,   24,  107,  103,
 /*   130 */    80,   88,  128,   85,   58,   50,   52,   62,   60,   64,
 /*   140 */    70,   72,   74,   76,   66,   68,   46,   44,   48,   41,
 /*   150 */    38,   54,   56,   82,   92,   78,  266,  261,   80,   88,
 /*   160 */   129,   85,   58,   50,   52,   62,   60,   64,   70,   72,
 /*   170 */    74,   76,   66,   68,   46,   44,   48,   41,   38,   54,
 /*   180 */    56,   82,   92,   78,  123,   37,   80,   88,  149,   85,
 /*   190 */    58,   50,   52,   62,   60,   64,   70,   72,   74,   76,
 /*   200 */    66,   68,   46,   44,   48,   41,   38,   54,   56,   82,
 /*   210 */    92,   78,   80,   88,   90,   85,   58,   50,   52,   62,
 /*   220 */    60,   64,   70,   72,   74,   76,   66,   68,   46,   44,
 /*   230 */    48,   41,   38,   54,   56,   82,   92,   78,   41,   38,
 /*   240 */    54,   56,   82,   92,   78,  257,  152,   36,   87,  231,
 /*   250 */   249,  381,   80,   88,  109,   85,   58,   50,   52,   62,
 /*   260 */    60,   64,   70,   72,   74,   76,   66,   68,   46,   44,
 /*   270 */    48,   41,   38,   54,   56,   82,   92,   78,  243,  244,
 /*   280 */   245,  246,  247,  248,   56,   82,   92,   78,  382,  147,
 /*   290 */    98,  201,  216,  133,   80,   88,  109,   85,   58,   50,
 /*   300 */    52,   62,   60,   64,   70,   72,   74,   76,   66,   68,
 /*   310 */    46,   44,   48,   41,   38,   54,   56,   82,   92,   78,
 /*   320 */   135,  163,   80,   88,  158,   85,   58,   50,   52,   62,
 /*   330 */    60,   64,   70,   72,   74,   76,   66,   68,   46,   44,
 /*   340 */    48,   41,   38,   54,   56,   82,   92,   78,  136,  196,
 /*   350 */    80,   88,  151,   85,   58,   50,   52,   62,   60,   64,
 /*   360 */    70,   72,   74,   76,   66,   68,   46,   44,   48,   41,
 /*   370 */    38,   54,   56,   82,   92,   78,  381,  199,   80,   88,
 /*   380 */   160,   85,   58,   50,   52,   62,   60,   64,   70,   72,
 /*   390 */    74,   76,   66,   68,   46,   44,   48,   41,   38,   54,
 /*   400 */    56,   82,   92,   78,  402,    1,    2,  215,    4,    5,
 /*   410 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   420 */    16,   17,   18,   19,   20,  213,  240,  382,  161,   80,
 /*   430 */    88,  167,   85,   58,   50,   52,   62,   60,   64,   70,
 /*   440 */    72,   74,   76,   66,   68,   46,   44,   48,   41,   38,
 /*   450 */    54,   56,   82,   92,   78,  165,  252,   80,   88,  166,
 /*   460 */    85,   58,   50,   52,   62,   60,   64,   70,   72,   74,
 /*   470 */    76,   66,   68,   46,   44,   48,   41,   38,   54,   56,
 /*   480 */    82,   92,   78,  168,  268,   80,   88,  172,   85,   58,
 /*   490 */    50,   52,   62,   60,   64,   70,   72,   74,   76,   66,
 /*   500 */    68,   46,   44,   48,   41,   38,   54,   56,   82,   92,
 /*   510 */    78,   88,  175,   85,   58,   50,   52,   62,   60,   64,
 /*   520 */    70,   72,   74,   76,   66,   68,   46,   44,   48,   41,
 /*   530 */    38,   54,   56,   82,   92,   78,   85,   58,   50,   52,
 /*   540 */    62,   60,   64,   70,   72,   74,   76,   66,   68,   46,
 /*   550 */    44,   48,   41,   38,   54,   56,   82,   92,   78,   50,
 /*   560 */    52,   62,   60,   64,   70,   72,   74,   76,   66,   68,
 /*   570 */    46,   44,   48,   41,   38,   54,   56,   82,   92,   78,
 /*   580 */    25,  215,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   590 */    12,   13,   14,   15,   16,   17,   18,   19,   20,  189,
 /*   600 */    31,  215,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   610 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   62,
 /*   620 */    60,   64,   70,   72,   74,   76,   66,   68,   46,   44,
 /*   630 */    48,   41,   38,   54,   56,   82,   92,   78,  155,  215,
 /*   640 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   650 */    14,   15,   16,   17,   18,   19,   20,  169,  215,    4,
 /*   660 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   670 */    15,   16,   17,   18,   19,   20,  177,  215,    4,    5,
 /*   680 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   690 */    16,   17,   18,   19,   20,  184,  215,    4,    5,    6,
 /*   700 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   710 */    17,   18,   19,   20,  203,  215,    4,    5,    6,    7,
 /*   720 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   730 */    18,   19,   20,  218,  215,    4,    5,    6,    7,    8,
 /*   740 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   750 */    19,   20,  224,  215,    4,    5,    6,    7,    8,    9,
 /*   760 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   770 */    20,  234,  215,    4,    5,    6,    7,    8,    9,   10,
 /*   780 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   790 */   253,  215,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   800 */    12,   13,   14,   15,   16,   17,   18,   19,   20,  262,
 /*   810 */   215,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   820 */    13,   14,   15,   16,   17,   18,   19,   20,  269,  215,
 /*   830 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   840 */    14,   15,   16,   17,   18,   19,   20,    3,    4,    5,
 /*   850 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   860 */    16,   17,   18,   19,   20,   22,  173,   27,   29,   35,
 /*   870 */   148,  150,  176,  180,  159,  187,  164,   22,  173,  277,
 /*   880 */   279,   35,  148,  150,  190,  120,  159,  174,  164,  181,
 /*   890 */   202,  188,  191,   93,  197,  200,  206,  207,  209,  174,
 /*   900 */   109,  181,  121,  188,  191,  240,  197,  200,  239,  207,
 /*   910 */   209,   22,  173,   33,   86,   35,  148,  150,   93,  132,
 /*   920 */   159,  109,  164,  100,  119,  109,  118,  126,  208,  105,
 /*   930 */   109,  210,   40,  174,  217,  181,  241,  188,  191,  109,
 /*   940 */   197,  200,  238,  207,  209,   22,  173,  285,   21,   35,
 /*   950 */   148,  150,  221,  157,  159,  100,  164,  131,  146,  102,
 /*   960 */   223,  117,  109,   43,  130,  109,   45,  174,  242,  181,
 /*   970 */   109,  188,  191,  109,  197,  200,  227,  207,  209,   22,
 /*   980 */   173,  232,   21,   35,  148,  150,  134,   47,  159,  230,
 /*   990 */   164,   49,  171,   51,  109,   53,  211,  258,  109,  256,
 /*  1000 */   109,  174,  109,  181,  233,  188,  191,  237,  197,  200,
 /*  1010 */   214,  207,  209,   22,  173,  259,  276,   35,  148,  150,
 /*  1020 */   265,   55,  159,  272,  164,  131,   57,   59,  109,  275,
 /*  1030 */   211,  251,  130,  109,  109,  174,  179,  181,  109,  188,
 /*  1040 */   191,  282,  197,  200,  214,  207,  209,   22,  173,  278,
 /*  1050 */    61,   35,  148,  150,   63,   65,  159,  109,  164,   67,
 /*  1060 */    69,  109,  109,   71,  211,  281,  109,  109,   73,  174,
 /*  1070 */   109,  181,  186,  188,  191,  109,  197,  200,  214,  207,
 /*  1080 */   209,   22,  173,  280,   75,   35,  148,  150,  283,   77,
 /*  1090 */   159,  109,  164,  217,   79,   81,  109,   84,  217,   89,
 /*  1100 */   217,  109,  109,  174,  109,  181,  109,  188,  191,  217,
 /*  1110 */   197,  200,  205,  207,  209,   22,  173,  217,   26,   35,
 /*  1120 */   148,  150,   91,   95,  159,   97,  164,  260,  108,  109,
 /*  1130 */   109,  124,  109,  143,  109,  109,  145,  174,  109,  181,
 /*  1140 */   109,  188,  191,  109,  197,  200,  220,  207,  209,   22,
 /*  1150 */   173,  217,  273,   35,  148,  150,  153,  162,  159,  217,
 /*  1160 */   164,  182,  192,  109,  109,  195,  211,  217,  109,  109,
 /*  1170 */   198,  174,  109,  181,  226,  188,  191,  109,  197,  200,
 /*  1180 */   214,  207,  209,   22,  173,  217,   32,   35,  148,  150,
 /*  1190 */   212,  267,  159,  217,  164,  217,  217,  109,  109,  217,
 /*  1200 */   211,  217,  217,  217,  217,  174,  229,  181,  217,  188,
 /*  1210 */   191,  217,  197,  200,  214,  207,  209,   22,  173,  217,
 /*  1220 */   156,   35,  148,  150,  217,  217,  159,  217,  164,  217,
 /*  1230 */   236,  217,  217,  217,  211,  217,  217,  217,  217,  174,
 /*  1240 */   217,  181,  217,  188,  191,  217,  197,  200,  214,  207,
 /*  1250 */   209,   22,  173,  217,  170,   35,  148,  150,  217,  255,
 /*  1260 */   159,  217,  164,  217,  217,  217,  217,  217,  211,  217,
 /*  1270 */   217,  217,  217,  174,  217,  181,  217,  188,  191,  217,
 /*  1280 */   197,  200,  214,  207,  209,   22,  173,  217,  228,   35,
 /*  1290 */   148,  150,  217,  264,  159,  217,  164,  217,  217,  217,
 /*  1300 */   217,  217,  211,  217,  217,  217,  217,  174,  217,  181,
 /*  1310 */   217,  188,  191,  217,  197,  200,  214,  207,  209,   22,
 /*  1320 */   173,  217,  178,   35,  148,  150,  217,  271,  159,  217,
 /*  1330 */   164,  217,  217,  217,  217,  217,  211,  217,  217,  217,
 /*  1340 */   217,  174,  217,  181,  217,  188,  191,  217,  197,  200,
 /*  1350 */   214,  207,  209,   22,  173,  274,  217,   35,  148,  150,
 /*  1360 */   185,  217,  159,  217,  164,  217,  217,  217,  217,  217,
 /*  1370 */   211,  217,  217,  217,  217,  174,  217,  181,  217,  188,
 /*  1380 */   191,  204,  197,  200,  214,  207,  209,   22,  173,  217,
 /*  1390 */   217,   35,  148,  150,  217,  217,  159,  217,  164,  217,
 /*  1400 */   217,  217,  217,  217,  217,  217,  217,  217,  211,  174,
 /*  1410 */   217,  181,  217,  188,  191,  217,  197,  200,   99,  207,
 /*  1420 */   209,  219,  214,  217,   99,  217,  217,  217,  217,  211,
 /*  1430 */   217,  217,  144,  217,   42,   39,  217,  142,   94,   96,
 /*  1440 */    42,   39,  217,  214,   94,   96,  217,  217,  110,  217,
 /*  1450 */   217,   99,  217,  217,  110,  111,  112,  113,  114,  115,
 /*  1460 */   116,  111,  112,  113,  114,  115,  116,   42,   39,  211,
 /*  1470 */   217,  139,   96,  217,  217,  217,  217,  127,   99,  225,
 /*  1480 */   217,  110,  217,  214,  217,  217,  217,  217,  111,  112,
 /*  1490 */   113,  114,  115,  116,   42,   39,  217,  217,   94,   96,
 /*  1500 */   217,  217,  217,  217,  217,   99,  217,  217,  138,  141,
 /*  1510 */   217,  217,  217,  217,  217,  137,  112,  113,  114,  115,
 /*  1520 */   116,   42,   39,  217,  217,   94,   96,  211,  217,  217,
 /*  1530 */   217,  217,   99,  217,  217,  110,  217,  217,  217,  217,
 /*  1540 */   125,  214,  111,  122,  113,  114,  115,  116,   42,   39,
 /*  1550 */   217,  217,   94,   96,  217,  217,  217,  217,  217,   99,
 /*  1560 */   217,  217,  110,  217,  217,  217,  217,  217,  217,  111,
 /*  1570 */   106,  113,  114,  115,  116,   42,   39,  217,  217,   94,
 /*  1580 */    96,  217,  217,  217,  217,  217,   99,  217,  217,  110,
 /*  1590 */   217,  101,  217,  217,  217,  217,  111,  112,  113,  114,
 /*  1600 */   115,  116,   42,   39,  217,  217,   94,   96,  217,  217,
 /*  1610 */   217,  217,  217,   99,  217,  217,  110,  140,  217,  217,
 /*  1620 */   217,  217,  217,  111,  112,  113,  114,  115,  116,   42,
 /*  1630 */    39,  217,  217,   94,   96,  217,  235,  217,  254,  217,
 /*  1640 */    99,  217,  263,  110,  270,  217,  217,  217,  217,  217,
 /*  1650 */   111,  106,  113,  114,  115,  116,   42,   39,  217,  217,
 /*  1660 */    94,   96,  217,  217,  217,  217,  217,  217,  217,  217,
 /*  1670 */   110,  217,  217,  217,  217,  217,  217,  111,  122,  113,
 /*  1680 */   114,  115,  116,  217,  211,  217,  211,  217,  217,  217,
 /*  1690 */   211,  217,  211,  217,  217,  217,  217,  217,  214,  217,
 /*  1700 */   214,  217,  217,  217,  214,  217,  214,
};
static KKCODETYPE kk_lookahead[] = {
 /*     0 */     3,    4,    0,    6,    7,    8,    9,   10,   11,   12,
 /*    10 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    20 */    23,   24,   25,   26,   27,   28,   29,   30,    3,    4,
 /*    30 */    30,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*    40 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*    50 */    25,   26,   27,   28,   30,   30,   19,   20,   21,   22,
 /*    60 */    23,   24,   25,   26,   27,   28,    2,   88,   43,   26,
 /*    70 */    27,   28,    3,    4,   95,    6,    7,    8,    9,   10,
 /*    80 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    90 */    21,   22,   23,   24,   25,   26,   27,   28,   30,   30,
 /*   100 */     3,    4,    3,    6,    7,    8,    9,   10,   11,   12,
 /*   110 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   120 */    23,   24,   25,   26,   27,   28,   57,   30,    5,   65,
 /*   130 */     3,    4,   93,    6,    7,    8,    9,   10,   11,   12,
 /*   140 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   150 */    23,   24,   25,   26,   27,   28,   29,   30,    3,    4,
 /*   160 */    65,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   170 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   180 */    25,   26,   27,   28,    5,   30,    3,    4,   30,    6,
 /*   190 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   200 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   210 */    27,   28,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   220 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   230 */    21,   22,   23,   24,   25,   26,   27,   28,   22,   23,
 /*   240 */    24,   25,   26,   27,   28,    2,    3,   88,   65,   89,
 /*   250 */    90,   65,    3,    4,   95,    6,    7,    8,    9,   10,
 /*   260 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   270 */    21,   22,   23,   24,   25,   26,   27,   28,   43,   44,
 /*   280 */    45,   46,   47,   48,   25,   26,   27,   28,   65,   88,
 /*   290 */    41,   47,   48,    5,    3,    4,   95,    6,    7,    8,
 /*   300 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   310 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   320 */    93,   30,    3,    4,   30,    6,    7,    8,    9,   10,
 /*   330 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   340 */    21,   22,   23,   24,   25,   26,   27,   28,   65,   30,
 /*   350 */     3,    4,   36,    6,    7,    8,    9,   10,   11,   12,
 /*   360 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   370 */    23,   24,   25,   26,   27,   28,    5,   30,    3,    4,
 /*   380 */    36,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   390 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   400 */    25,   26,   27,   28,   67,   68,   69,   70,   71,   72,
 /*   410 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   420 */    83,   84,   85,   86,   87,   50,   36,    5,   39,    3,
 /*   430 */     4,   41,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   440 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   450 */    24,   25,   26,   27,   28,   36,   30,    3,    4,   27,
 /*   460 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   470 */    16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
 /*   480 */    26,   27,   28,   30,   30,    3,    4,   30,    6,    7,
 /*   490 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   500 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   510 */    28,    4,   36,    6,    7,    8,    9,   10,   11,   12,
 /*   520 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   530 */    23,   24,   25,   26,   27,   28,    6,    7,    8,    9,
 /*   540 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   550 */    20,   21,   22,   23,   24,   25,   26,   27,   28,    8,
 /*   560 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   570 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   580 */    69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
 /*   590 */    79,   80,   81,   82,   83,   84,   85,   86,   87,   44,
 /*   600 */    69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
 /*   610 */    79,   80,   81,   82,   83,   84,   85,   86,   87,   10,
 /*   620 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   630 */    21,   22,   23,   24,   25,   26,   27,   28,   69,   70,
 /*   640 */    71,   72,   73,   74,   75,   76,   77,   78,   79,   80,
 /*   650 */    81,   82,   83,   84,   85,   86,   87,   69,   70,   71,
 /*   660 */    72,   73,   74,   75,   76,   77,   78,   79,   80,   81,
 /*   670 */    82,   83,   84,   85,   86,   87,   69,   70,   71,   72,
 /*   680 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   690 */    83,   84,   85,   86,   87,   69,   70,   71,   72,   73,
 /*   700 */    74,   75,   76,   77,   78,   79,   80,   81,   82,   83,
 /*   710 */    84,   85,   86,   87,   69,   70,   71,   72,   73,   74,
 /*   720 */    75,   76,   77,   78,   79,   80,   81,   82,   83,   84,
 /*   730 */    85,   86,   87,   69,   70,   71,   72,   73,   74,   75,
 /*   740 */    76,   77,   78,   79,   80,   81,   82,   83,   84,   85,
 /*   750 */    86,   87,   69,   70,   71,   72,   73,   74,   75,   76,
 /*   760 */    77,   78,   79,   80,   81,   82,   83,   84,   85,   86,
 /*   770 */    87,   69,   70,   71,   72,   73,   74,   75,   76,   77,
 /*   780 */    78,   79,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   790 */    69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
 /*   800 */    79,   80,   81,   82,   83,   84,   85,   86,   87,   69,
 /*   810 */    70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
 /*   820 */    80,   81,   82,   83,   84,   85,   86,   87,   69,   70,
 /*   830 */    71,   72,   73,   74,   75,   76,   77,   78,   79,   80,
 /*   840 */    81,   82,   83,   84,   85,   86,   87,   70,   71,   72,
 /*   850 */    73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
 /*   860 */    83,   84,   85,   86,   87,   29,   30,   31,   32,   33,
 /*   870 */    34,   35,   30,   30,   38,   30,   40,   29,   30,   31,
 /*   880 */    32,   33,   34,   35,   30,    2,   38,   51,   40,   53,
 /*   890 */    30,   55,   56,   88,   58,   59,   30,   61,   62,   51,
 /*   900 */    95,   53,   97,   55,   56,   36,   58,   59,   90,   61,
 /*   910 */    62,   29,   30,   31,   88,   33,   34,   35,   88,   93,
 /*   920 */    38,   95,   40,   88,   41,   95,   96,   97,   30,   94,
 /*   930 */    95,   30,   88,   51,   30,   53,   39,   55,   56,   95,
 /*   940 */    58,   59,    2,   61,   62,   29,   30,    0,    1,   33,
 /*   950 */    34,   35,   30,   37,   38,   88,   40,   36,   88,   92,
 /*   960 */    30,   94,   95,   88,   43,   95,   88,   51,   91,   53,
 /*   970 */    95,   55,   56,   95,   58,   59,   30,   61,   62,   29,
 /*   980 */    30,   41,    1,   33,   34,   35,   65,   88,   38,   30,
 /*   990 */    40,   88,   42,   88,   95,   88,   49,   36,   95,   30,
 /*  1000 */    95,   51,   95,   53,   30,   55,   56,   30,   58,   59,
 /*  1010 */    63,   61,   62,   29,   30,    3,    1,   33,   34,   35,
 /*  1020 */    30,   88,   38,   30,   40,   36,   88,   88,   95,   30,
 /*  1030 */    49,   88,   43,   95,   95,   51,   52,   53,   95,   55,
 /*  1040 */    56,   31,   58,   59,   63,   61,   62,   29,   30,   30,
 /*  1050 */    88,   33,   34,   35,   88,   88,   38,   95,   40,   88,
 /*  1060 */    88,   95,   95,   88,   49,    1,   95,   95,   88,   51,
 /*  1070 */    95,   53,   54,   55,   56,   95,   58,   59,   63,   61,
 /*  1080 */    62,   29,   30,   30,   88,   33,   34,   35,   30,   88,
 /*  1090 */    38,   95,   40,   98,   88,   88,   95,   88,   98,   88,
 /*  1100 */    98,   95,   95,   51,   95,   53,   95,   55,   56,   98,
 /*  1110 */    58,   59,   60,   61,   62,   29,   30,   98,    1,   33,
 /*  1120 */    34,   35,   88,   88,   38,   88,   40,   88,   88,   95,
 /*  1130 */    95,   88,   95,   88,   95,   95,   88,   51,   95,   53,
 /*  1140 */    95,   55,   56,   95,   58,   59,   60,   61,   62,   29,
 /*  1150 */    30,   98,    1,   33,   34,   35,   88,   88,   38,   98,
 /*  1160 */    40,   88,   88,   95,   95,   88,   49,   98,   95,   95,
 /*  1170 */    88,   51,   95,   53,   54,   55,   56,   95,   58,   59,
 /*  1180 */    63,   61,   62,   29,   30,   98,    1,   33,   34,   35,
 /*  1190 */    88,   88,   38,   98,   40,   98,   98,   95,   95,   98,
 /*  1200 */    49,   98,   98,   98,   98,   51,   52,   53,   98,   55,
 /*  1210 */    56,   98,   58,   59,   63,   61,   62,   29,   30,   98,
 /*  1220 */     1,   33,   34,   35,   98,   98,   38,   98,   40,   98,
 /*  1230 */    42,   98,   98,   98,   49,   98,   98,   98,   98,   51,
 /*  1240 */    98,   53,   98,   55,   56,   98,   58,   59,   63,   61,
 /*  1250 */    62,   29,   30,   98,    1,   33,   34,   35,   98,   37,
 /*  1260 */    38,   98,   40,   98,   98,   98,   98,   98,   49,   98,
 /*  1270 */    98,   98,   98,   51,   98,   53,   98,   55,   56,   98,
 /*  1280 */    58,   59,   63,   61,   62,   29,   30,   98,    1,   33,
 /*  1290 */    34,   35,   98,   37,   38,   98,   40,   98,   98,   98,
 /*  1300 */    98,   98,   49,   98,   98,   98,   98,   51,   98,   53,
 /*  1310 */    98,   55,   56,   98,   58,   59,   63,   61,   62,   29,
 /*  1320 */    30,   98,    1,   33,   34,   35,   98,   37,   38,   98,
 /*  1330 */    40,   98,   98,   98,   98,   98,   49,   98,   98,   98,
 /*  1340 */    98,   51,   98,   53,   98,   55,   56,   98,   58,   59,
 /*  1350 */    63,   61,   62,   29,   30,   31,   98,   33,   34,   35,
 /*  1360 */     1,   98,   38,   98,   40,   98,   98,   98,   98,   98,
 /*  1370 */    49,   98,   98,   98,   98,   51,   98,   53,   98,   55,
 /*  1380 */    56,    1,   58,   59,   63,   61,   62,   29,   30,   98,
 /*  1390 */    98,   33,   34,   35,   98,   98,   38,   98,   40,   98,
 /*  1400 */    98,   98,   98,   98,   98,   98,   98,   98,   49,   51,
 /*  1410 */    98,   53,   98,   55,   56,   98,   58,   59,    6,   61,
 /*  1420 */    62,    1,   63,   98,    6,   98,   98,   98,   98,   49,
 /*  1430 */    98,   98,   20,   98,   22,   23,   98,   19,   26,   27,
 /*  1440 */    22,   23,   98,   63,   26,   27,   98,   98,   36,   98,
 /*  1450 */    98,    6,   98,   98,   36,   43,   44,   45,   46,   47,
 /*  1460 */    48,   43,   44,   45,   46,   47,   48,   22,   23,   49,
 /*  1470 */    98,   26,   27,   98,   98,   98,   98,    5,    6,    1,
 /*  1480 */    98,   36,   98,   63,   98,   98,   98,   98,   43,   44,
 /*  1490 */    45,   46,   47,   48,   22,   23,   98,   98,   26,   27,
 /*  1500 */    98,   98,   98,   98,   98,    6,   98,   98,   36,   64,
 /*  1510 */    98,   98,   98,   98,   98,   43,   44,   45,   46,   47,
 /*  1520 */    48,   22,   23,   98,   98,   26,   27,   49,   98,   98,
 /*  1530 */    98,   98,    6,   98,   98,   36,   98,   98,   98,   98,
 /*  1540 */    41,   63,   43,   44,   45,   46,   47,   48,   22,   23,
 /*  1550 */    98,   98,   26,   27,   98,   98,   98,   98,   98,    6,
 /*  1560 */    98,   98,   36,   98,   98,   98,   98,   98,   98,   43,
 /*  1570 */    44,   45,   46,   47,   48,   22,   23,   98,   98,   26,
 /*  1580 */    27,   98,   98,   98,   98,   98,    6,   98,   98,   36,
 /*  1590 */    98,   65,   98,   98,   98,   98,   43,   44,   45,   46,
 /*  1600 */    47,   48,   22,   23,   98,   98,   26,   27,   98,   98,
 /*  1610 */    98,   98,   98,    6,   98,   98,   36,   64,   98,   98,
 /*  1620 */    98,   98,   98,   43,   44,   45,   46,   47,   48,   22,
 /*  1630 */    23,   98,   98,   26,   27,   98,    1,   98,    1,   98,
 /*  1640 */     6,   98,    1,   36,    1,   98,   98,   98,   98,   98,
 /*  1650 */    43,   44,   45,   46,   47,   48,   22,   23,   98,   98,
 /*  1660 */    26,   27,   98,   98,   98,   98,   98,   98,   98,   98,
 /*  1670 */    36,   98,   98,   98,   98,   98,   98,   43,   44,   45,
 /*  1680 */    46,   47,   48,   98,   49,   98,   49,   98,   98,   98,
 /*  1690 */    49,   98,   49,   98,   98,   98,   98,   98,   63,   98,
 /*  1700 */    63,   98,   98,   98,   63,   98,   63,
};
#define KK_SHIFT_USE_DFLT (-4)
static short kk_shift_ofst[] = {
 /*     0 */   981,    2,  947,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    20 */    -4, 1358, 1580,   97, 1015, 1117,  836,    0,   -4,   24,
 /*    30 */  1151, 1185,  882,   68,   -4, 1580,  155,   -4, 1580, 1580,
 /*    40 */   259, 1580, 1580,  259, 1412,  216, 1418,  216, 1580,  216,
 /*    50 */  1580,  609, 1580,  609, 1580,  259, 1580,   43, 1580,  551,
 /*    60 */  1580,   37, 1445,   37, 1580,   37, 1580,   37, 1580,   37,
 /*    70 */  1580,   37, 1580,   37, 1580,   37, 1580,   37, 1580,   -4,
 /*    80 */  1580,  507,   99, 1580,   43, 1472,  183,   -4, 1580,  209,
 /*    90 */  1580,  530, 1499,  482, 1580,   43, 1580,  249,   -4, 1526,
 /*   100 */   482,   -4,   64,   -4, 1607,   -4,  123, 1580,  482,   -4,
 /*   110 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,  883,   -4,
 /*   120 */  1634,   -4,  179, 1580,  482,   -4,   -4,  989,   95,   -4,
 /*   130 */   186,  223,  288,  921,   -4,  283,   -4,  371,  422, 1553,
 /*   140 */    -4,   -4, 1580,  216, 1580,  216,  259,  259,  158,   -4,
 /*   150 */   316,  243, 1580,   -3,  981, 1219,  916,  294,   -4,  344,
 /*   160 */   389, 1580,  291,   -4,  419,  432,  390,  453,  981, 1253,
 /*   170 */   950,  457,   -4,   -4,  476,  842, 1287, 1321,  984,  843,
 /*   180 */    -4, 1580,   25,  981, 1359, 1018,  845,   -4,  555,  854,
 /*   190 */    -4, 1580,   69,   -4, 1580,  319,   -4, 1580,  347,   -4,
 /*   200 */   244,  860,  981, 1380, 1052,  866,   -4,  898,   -4,  901,
 /*   210 */    -4, 1580,  375,   -4,   -4,   -4,  904,  981, 1420, 1086,
 /*   220 */   922,   -4,  930,  981, 1478, 1120,  946,   -4, 1154,  959,
 /*   230 */    -4,  940,  974,  981, 1635, 1188,  977,   -4,  869,   -4,
 /*   240 */   897,  235,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*   250 */  1580,  426,  981, 1637, 1222,  969,   -4,  961, 1012, 1580,
 /*   260 */   127,  981, 1641, 1256,  990,   -4, 1580,  454,  981, 1643,
 /*   270 */  1290,  993,   -4, 1324,  999,   -4,  848, 1019,   -4, 1053,
 /*   280 */  1064, 1010, 1058,   -4,
};
#define KK_REDUCE_USE_DFLT (-22)
static short kk_reduce_ofst[] = {
 /*     0 */   337,  -22,  777,  -22,  -22,  -22,  -22,  -22,  -22,  -22,
 /*    10 */   -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,
 /*    20 */   -22,  -22,  -21,  -22,  511,  777,  -22,  -22,  -22,  -22,
 /*    30 */   531,  777,  -22,  -22,  -22,  159,  -22,  -22,  201,  844,
 /*    40 */   -22,  870,  875,  -22,  878,  -22,  899,  -22,  903,  -22,
 /*    50 */   905,  -22,  907,  -22,  933,  -22,  938,  -22,  939,  -22,
 /*    60 */   962,  -22,  966,  -22,  967,  -22,  971,  -22,  972,  -22,
 /*    70 */   975,  -22,  980,  -22,  996,  -22, 1001,  -22, 1006,  -22,
 /*    80 */  1007,  -22,  -22, 1009,  -22,  826,  -22,  -22, 1011,  -22,
 /*    90 */  1034,  -22,  830,  -22, 1035,  -22, 1037,  -22,  -22,  867,
 /*   100 */   -22,  -22,  -22,  -22,  835,  -22,  -22, 1040,  -22,  -22,
 /*   110 */   -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,
 /*   120 */   805,  -22,  -22, 1043,  -22,  -22,  -22,   39,  -22,  -22,
 /*   130 */   -22,  -22,  -22,  227,  -22,  -22,  -22,  -22,  -22, 1035,
 /*   140 */   -22,  -22, 1045,  -22, 1048,  -22,  -22,  -22,  -22,  -22,
 /*   150 */   -22,  -22, 1068,  -22,  569,  777,  -22,  -22,  -22,  -22,
 /*   160 */   -22, 1069,  -22,  -22,  -22,  -22,  160,  -22,  588,  777,
 /*   170 */   -22,  -22,  -22,  -22,  -22,  -22,  607,  777,  -22,  -22,
 /*   180 */   -22, 1073,  -22,  626,  777,  -22,  -22,  -22,  -22,  -22,
 /*   190 */   -22, 1074,  -22,  -22, 1077,  -22,  -22, 1082,  -22,  -22,
 /*   200 */   -22,  -22,  645,  777,  -22,  -22,  -22,  -22,  -22,  -22,
 /*   210 */   -22, 1102,  -22,  -22,  -22,  -22,  -22,  664,  777,  -22,
 /*   220 */   -22,  -22,  -22,  683,  777,  -22,  -22,  -22,  -22,  -22,
 /*   230 */   -22,  -22,  -22,  702,  777,  -22,  -22,  -22,  818,  -22,
 /*   240 */   -22,  877,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,
 /*   250 */   943,  -22,  721,  777,  -22,  -22,  -22,  -22,  -22, 1039,
 /*   260 */   -22,  740,  777,  -22,  -22,  -22, 1103,  -22,  759,  777,
 /*   270 */   -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,
 /*   280 */   -22,  -22,  -22,  -22,
};
static KKACTIONTYPE kk_default[] = {
 /*     0 */   401,  401,  401,  286,  288,  289,  290,  291,  292,  293,
 /*    10 */   294,  295,  296,  297,  298,  299,  300,  301,  302,  303,
 /*    20 */   304,  401,  401,  401,  401,  401,  401,  401,  305,  401,
 /*    30 */   401,  401,  401,  401,  307,  401,  401,  310,  401,  401,
 /*    40 */   344,  401,  401,  345,  401,  348,  401,  350,  401,  352,
 /*    50 */   401,  353,  401,  354,  401,  355,  401,  356,  401,  357,
 /*    60 */   401,  358,  401,  361,  401,  362,  401,  363,  401,  364,
 /*    70 */   401,  365,  401,  366,  401,  367,  401,  368,  401,  369,
 /*    80 */   401,  370,  401,  401,  371,  401,  401,  376,  401,  401,
 /*    90 */   401,  377,  401,  392,  401,  372,  401,  401,  373,  401,
 /*   100 */   386,  374,  401,  375,  401,  383,  396,  401,  385,  387,
 /*   110 */   394,  395,  396,  397,  398,  399,  400,  384,  401,  388,
 /*   120 */   401,  390,  396,  401,  393,  389,  391,  401,  401,  378,
 /*   130 */   401,  401,  401,  401,  379,  401,  380,  395,  394,  401,
 /*   140 */   359,  360,  401,  351,  401,  349,  347,  346,  401,  311,
 /*   150 */   401,  401,  401,  401,  401,  401,  401,  401,  312,  401,
 /*   160 */   401,  401,  401,  316,  401,  401,  401,  401,  401,  401,
 /*   170 */   401,  401,  317,  329,  401,  401,  401,  401,  401,  401,
 /*   180 */   331,  401,  401,  401,  401,  401,  401,  333,  401,  401,
 /*   190 */   335,  401,  401,  336,  401,  401,  337,  401,  401,  338,
 /*   200 */   401,  401,  401,  401,  401,  401,  339,  401,  341,  401,
 /*   210 */   342,  401,  401,  330,  343,  287,  401,  401,  401,  401,
 /*   220 */   401,  340,  401,  401,  401,  401,  401,  334,  401,  401,
 /*   230 */   332,  401,  401,  401,  401,  401,  401,  318,  401,  319,
 /*   240 */   321,  401,  322,  323,  324,  325,  326,  327,  328,  320,
 /*   250 */   401,  401,  401,  401,  401,  401,  313,  401,  401,  401,
 /*   260 */   401,  401,  401,  401,  401,  314,  401,  401,  401,  401,
 /*   270 */   401,  401,  315,  401,  401,  308,  401,  401,  306,  401,
 /*   280 */   401,  401,  401,  309,
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
  "INCLUDE",       "WITH",          "DO",            "AUTOESCAPE",  
  "ENDAUTOESCAPE",  "BREAK",         "CONTINUE",      "RAW_FRAGMENT",
  "DEFINED",       "SBRACKET_CLOSE",  "error",         "program",     
  "volt_language",  "statement_list",  "statement",     "raw_fragment",
  "if_statement",  "elseif_statement",  "elsefor_statement",  "for_statement",
  "set_statement",  "echo_statement",  "block_statement",  "cache_statement",
  "extends_statement",  "include_statement",  "do_statement",  "autoescape_statement",
  "break_statement",  "continue_statement",  "macro_statement",  "empty_statement",
  "expr",          "macro_parameters",  "macro_parameter",  "macro_parameter_default",
  "array_list",    "slice_offset",  "array_item",    "function_call",
  "argument_list",  "argument_item",
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
 /*  22 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  23 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  24 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  25 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER OPEN_DELIMITER ELSE CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  26 */ "elseif_statement ::= OPEN_DELIMITER ELSEIF expr CLOSE_DELIMITER",
 /*  27 */ "elsefor_statement ::= OPEN_DELIMITER ELSEFOR CLOSE_DELIMITER",
 /*  28 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  29 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  30 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  31 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  32 */ "set_statement ::= OPEN_DELIMITER SET IDENTIFIER ASSIGN expr CLOSE_DELIMITER",
 /*  33 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  34 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN macro_parameters PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  35 */ "macro_parameters ::= macro_parameters COMMA macro_parameter",
 /*  36 */ "macro_parameters ::= macro_parameter",
 /*  37 */ "macro_parameter ::= IDENTIFIER",
 /*  38 */ "macro_parameter ::= IDENTIFIER ASSIGN macro_parameter_default",
 /*  39 */ "macro_parameter_default ::= INTEGER",
 /*  40 */ "macro_parameter_default ::= STRING",
 /*  41 */ "macro_parameter_default ::= DOUBLE",
 /*  42 */ "macro_parameter_default ::= NULL",
 /*  43 */ "macro_parameter_default ::= FALSE",
 /*  44 */ "macro_parameter_default ::= TRUE",
 /*  45 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  46 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  47 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  48 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  49 */ "cache_statement ::= OPEN_DELIMITER CACHE expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  50 */ "cache_statement ::= OPEN_DELIMITER CACHE expr INTEGER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  51 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  52 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr CLOSE_DELIMITER",
 /*  53 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr WITH expr CLOSE_DELIMITER",
 /*  54 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  55 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE FALSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  56 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE TRUE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  57 */ "break_statement ::= OPEN_DELIMITER BREAK CLOSE_DELIMITER",
 /*  58 */ "continue_statement ::= OPEN_DELIMITER CONTINUE CLOSE_DELIMITER",
 /*  59 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  60 */ "expr ::= MINUS expr",
 /*  61 */ "expr ::= PLUS expr",
 /*  62 */ "expr ::= expr MINUS expr",
 /*  63 */ "expr ::= expr PLUS expr",
 /*  64 */ "expr ::= expr TIMES expr",
 /*  65 */ "expr ::= expr TIMES TIMES expr",
 /*  66 */ "expr ::= expr DIVIDE expr",
 /*  67 */ "expr ::= expr DIVIDE DIVIDE expr",
 /*  68 */ "expr ::= expr MOD expr",
 /*  69 */ "expr ::= expr AND expr",
 /*  70 */ "expr ::= expr OR expr",
 /*  71 */ "expr ::= expr CONCAT expr",
 /*  72 */ "expr ::= expr PIPE expr",
 /*  73 */ "expr ::= expr RANGE expr",
 /*  74 */ "expr ::= expr EQUALS expr",
 /*  75 */ "expr ::= expr IS NOT DEFINED",
 /*  76 */ "expr ::= expr IS DEFINED",
 /*  77 */ "expr ::= expr IS expr",
 /*  78 */ "expr ::= expr NOTEQUALS expr",
 /*  79 */ "expr ::= expr IDENTICAL expr",
 /*  80 */ "expr ::= expr NOTIDENTICAL expr",
 /*  81 */ "expr ::= expr LESS expr",
 /*  82 */ "expr ::= expr GREATER expr",
 /*  83 */ "expr ::= expr GREATEREQUAL expr",
 /*  84 */ "expr ::= expr LESSEQUAL expr",
 /*  85 */ "expr ::= expr DOT expr",
 /*  86 */ "expr ::= expr IN expr",
 /*  87 */ "expr ::= expr NOT IN expr",
 /*  88 */ "expr ::= NOT expr",
 /*  89 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /*  90 */ "expr ::= SBRACKET_OPEN SBRACKET_CLOSE",
 /*  91 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /*  92 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /*  93 */ "expr ::= expr QUESTION expr COLON expr",
 /*  94 */ "expr ::= expr SBRACKET_OPEN COLON slice_offset SBRACKET_CLOSE",
 /*  95 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON SBRACKET_CLOSE",
 /*  96 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON slice_offset SBRACKET_CLOSE",
 /*  97 */ "slice_offset ::= INTEGER",
 /*  98 */ "slice_offset ::= IDENTIFIER",
 /*  99 */ "array_list ::= array_list COMMA array_item",
 /* 100 */ "array_list ::= array_item",
 /* 101 */ "array_item ::= STRING COLON expr",
 /* 102 */ "array_item ::= expr",
 /* 103 */ "expr ::= function_call",
 /* 104 */ "function_call ::= expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 105 */ "function_call ::= expr PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 106 */ "argument_list ::= argument_list COMMA argument_item",
 /* 107 */ "argument_list ::= argument_item",
 /* 108 */ "argument_item ::= expr",
 /* 109 */ "argument_item ::= STRING COLON expr",
 /* 110 */ "expr ::= IDENTIFIER",
 /* 111 */ "expr ::= INTEGER",
 /* 112 */ "expr ::= STRING",
 /* 113 */ "expr ::= DOUBLE",
 /* 114 */ "expr ::= NULL",
 /* 115 */ "expr ::= FALSE",
 /* 116 */ "expr ::= TRUE",
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
// 592 "parser.lemon"
{
	if ((kkpminor->kk0)) {
		if ((kkpminor->kk0)->free_flag) {
			efree((kkpminor->kk0)->token);
		}
		efree((kkpminor->kk0));
	}
}
// 1434 "parser.c"
      break;
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
    case 92:
    case 93:
    case 94:
    case 95:
    case 96:
    case 97:
// 609 "parser.lemon"
{ zval_ptr_dtor(&(kkpminor->kk92)); }
// 1466 "parser.c"
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
  { 67, 1 },
  { 68, 1 },
  { 69, 2 },
  { 69, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 72, 8 },
  { 72, 7 },
  { 72, 12 },
  { 72, 11 },
  { 72, 10 },
  { 73, 4 },
  { 74, 3 },
  { 75, 10 },
  { 75, 12 },
  { 75, 12 },
  { 75, 14 },
  { 76, 6 },
  { 86, 10 },
  { 86, 11 },
  { 89, 3 },
  { 89, 1 },
  { 90, 1 },
  { 90, 3 },
  { 91, 1 },
  { 91, 1 },
  { 91, 1 },
  { 91, 1 },
  { 91, 1 },
  { 91, 1 },
  { 87, 2 },
  { 77, 3 },
  { 78, 8 },
  { 78, 7 },
  { 79, 8 },
  { 79, 9 },
  { 80, 4 },
  { 81, 4 },
  { 81, 6 },
  { 82, 4 },
  { 83, 8 },
  { 83, 8 },
  { 84, 3 },
  { 85, 3 },
  { 71, 1 },
  { 88, 2 },
  { 88, 2 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 4 },
  { 88, 3 },
  { 88, 4 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 4 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 4 },
  { 88, 2 },
  { 88, 3 },
  { 88, 2 },
  { 88, 3 },
  { 88, 4 },
  { 88, 5 },
  { 88, 5 },
  { 88, 5 },
  { 88, 6 },
  { 93, 1 },
  { 93, 1 },
  { 92, 3 },
  { 92, 1 },
  { 94, 3 },
  { 94, 1 },
  { 88, 1 },
  { 95, 4 },
  { 95, 3 },
  { 96, 3 },
  { 96, 1 },
  { 97, 1 },
  { 97, 3 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
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
// 601 "parser.lemon"
{
	status->ret = kkmsp[0].minor.kk92;
}
// 1800 "parser.c"
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
      case 103:
// 605 "parser.lemon"
{
	kkgotominor.kk92 = kkmsp[0].minor.kk92;
}
// 1825 "parser.c"
        break;
      case 2:
// 611 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_zval_list(kkmsp[-1].minor.kk92, kkmsp[0].minor.kk92);
}
// 1832 "parser.c"
        break;
      case 3:
      case 36:
      case 100:
      case 107:
// 615 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_zval_list(NULL, kkmsp[0].minor.kk92);
}
// 1842 "parser.c"
        break;
      case 21:
// 691 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_if_statement(kkmsp[-5].minor.kk92, kkmsp[-3].minor.kk92, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(29,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(31,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1855 "parser.c"
        break;
      case 22:
// 695 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_if_statement(kkmsp[-4].minor.kk92, NULL, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(29,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(31,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1868 "parser.c"
        break;
      case 23:
// 699 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_if_statement(kkmsp[-9].minor.kk92, kkmsp[-7].minor.kk92, kkmsp[-3].minor.kk92, status->scanner_state);
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
// 1884 "parser.c"
        break;
      case 24:
// 703 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_if_statement(kkmsp[-8].minor.kk92, kkmsp[-6].minor.kk92, NULL, status->scanner_state);
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
// 1900 "parser.c"
        break;
      case 25:
// 707 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_if_statement(kkmsp[-7].minor.kk92, NULL, NULL, status->scanner_state);
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
// 1916 "parser.c"
        break;
      case 26:
// 713 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_elseif_statement(kkmsp[-1].minor.kk92, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(33,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1926 "parser.c"
        break;
      case 27:
// 719 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_elsefor_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(34,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1936 "parser.c"
        break;
      case 28:
// 725 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-5].minor.kk92, NULL, kkmsp[-3].minor.kk92, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(35,&kkmsp[-8].minor);
  kk_destructor(3,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1950 "parser.c"
        break;
      case 29:
// 729 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, NULL, kkmsp[-7].minor.kk92, kkmsp[-5].minor.kk92, kkmsp[-3].minor.kk92, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(35,&kkmsp[-10].minor);
  kk_destructor(3,&kkmsp[-8].minor);
  kk_destructor(29,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1965 "parser.c"
        break;
      case 30:
// 733 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, kkmsp[-9].minor.kk0, kkmsp[-5].minor.kk92, NULL, kkmsp[-3].minor.kk92, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(35,&kkmsp[-10].minor);
  kk_destructor(2,&kkmsp[-8].minor);
  kk_destructor(3,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 1980 "parser.c"
        break;
      case 31:
// 737 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, kkmsp[-11].minor.kk0, kkmsp[-7].minor.kk92, kkmsp[-5].minor.kk92, kkmsp[-3].minor.kk92, status->scanner_state);
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
// 1996 "parser.c"
        break;
      case 32:
// 743 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_set_statement(kkmsp[-3].minor.kk0, kkmsp[-1].minor.kk92, status->scanner_state);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(38,&kkmsp[-4].minor);
  kk_destructor(39,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2007 "parser.c"
        break;
      case 33:
// 749 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_macro_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-3].minor.kk92, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(40,&kkmsp[-8].minor);
  kk_destructor(27,&kkmsp[-6].minor);
  kk_destructor(41,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(42,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2022 "parser.c"
        break;
      case 34:
// 753 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_macro_statement(kkmsp[-8].minor.kk0, kkmsp[-6].minor.kk92, kkmsp[-3].minor.kk92, status->scanner_state);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(40,&kkmsp[-9].minor);
  kk_destructor(27,&kkmsp[-7].minor);
  kk_destructor(41,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(42,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2037 "parser.c"
        break;
      case 35:
      case 99:
      case 106:
// 759 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_zval_list(kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(2,&kkmsp[-1].minor);
}
// 2047 "parser.c"
        break;
      case 37:
// 769 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_macro_parameter(kkmsp[0].minor.kk0, NULL, status->scanner_state);
}
// 2054 "parser.c"
        break;
      case 38:
// 773 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_macro_parameter(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk92, status->scanner_state);
  kk_destructor(39,&kkmsp[-1].minor);
}
// 2062 "parser.c"
        break;
      case 39:
      case 97:
      case 111:
// 777 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2071 "parser.c"
        break;
      case 40:
      case 112:
// 781 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_STRING, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2079 "parser.c"
        break;
      case 41:
      case 113:
// 785 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2087 "parser.c"
        break;
      case 42:
      case 114:
// 789 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  kk_destructor(46,&kkmsp[0].minor);
}
// 2096 "parser.c"
        break;
      case 43:
      case 115:
// 793 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  kk_destructor(47,&kkmsp[0].minor);
}
// 2105 "parser.c"
        break;
      case 44:
      case 116:
// 797 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  kk_destructor(48,&kkmsp[0].minor);
}
// 2114 "parser.c"
        break;
      case 45:
// 803 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_empty_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2123 "parser.c"
        break;
      case 46:
// 809 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_echo_statement(kkmsp[-1].minor.kk92, status->scanner_state);
  kk_destructor(49,&kkmsp[-2].minor);
  kk_destructor(50,&kkmsp[0].minor);
}
// 2132 "parser.c"
        break;
      case 47:
// 815 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_block_statement(kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk92, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(51,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(52,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2145 "parser.c"
        break;
      case 48:
// 819 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_block_statement(kkmsp[-4].minor.kk0, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(51,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(52,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2158 "parser.c"
        break;
      case 49:
// 825 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_cache_statement(kkmsp[-5].minor.kk92, NULL, kkmsp[-3].minor.kk92, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(53,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(54,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2171 "parser.c"
        break;
      case 50:
// 829 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_cache_statement(kkmsp[-6].minor.kk92, kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk92, status->scanner_state);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(53,&kkmsp[-7].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(54,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2184 "parser.c"
        break;
      case 51:
// 835 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_extends_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(55,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2194 "parser.c"
        break;
      case 52:
// 841 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_include_statement(kkmsp[-1].minor.kk92, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(56,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2204 "parser.c"
        break;
      case 53:
// 845 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_include_statement(kkmsp[-3].minor.kk92, kkmsp[-1].minor.kk92, status->scanner_state);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(56,&kkmsp[-4].minor);
  kk_destructor(57,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2215 "parser.c"
        break;
      case 54:
// 851 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_do_statement(kkmsp[-1].minor.kk92, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(58,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2225 "parser.c"
        break;
      case 55:
// 857 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_autoescape_statement(0, kkmsp[-3].minor.kk92, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(59,&kkmsp[-6].minor);
  kk_destructor(47,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(60,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2239 "parser.c"
        break;
      case 56:
// 861 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_autoescape_statement(1, kkmsp[-3].minor.kk92, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(59,&kkmsp[-6].minor);
  kk_destructor(48,&kkmsp[-5].minor);
  kk_destructor(30,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(60,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2253 "parser.c"
        break;
      case 57:
// 867 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_break_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(61,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2263 "parser.c"
        break;
      case 58:
// 873 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_continue_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(62,&kkmsp[-1].minor);
  kk_destructor(30,&kkmsp[0].minor);
}
// 2273 "parser.c"
        break;
      case 59:
// 879 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2280 "parser.c"
        break;
      case 60:
// 885 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
}
// 2288 "parser.c"
        break;
      case 61:
// 889 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_PLUS, NULL, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 2296 "parser.c"
        break;
      case 62:
// 893 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_SUB, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
}
// 2304 "parser.c"
        break;
      case 63:
// 897 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_ADD, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 2312 "parser.c"
        break;
      case 64:
// 901 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_MUL, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 2320 "parser.c"
        break;
      case 65:
// 905 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_POW, kkmsp[-3].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(20,&kkmsp[-2].minor);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 2329 "parser.c"
        break;
      case 66:
// 909 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_DIV, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 2337 "parser.c"
        break;
      case 67:
// 913 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-3].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(19,&kkmsp[-2].minor);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 2346 "parser.c"
        break;
      case 68:
// 917 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
// 2354 "parser.c"
        break;
      case 69:
// 921 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_AND, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(8,&kkmsp[-1].minor);
}
// 2362 "parser.c"
        break;
      case 70:
// 925 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_OR, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
}
// 2370 "parser.c"
        break;
      case 71:
// 929 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_CONCAT, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-1].minor);
}
// 2378 "parser.c"
        break;
      case 72:
// 933 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_PIPE, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(25,&kkmsp[-1].minor);
}
// 2386 "parser.c"
        break;
      case 73:
// 937 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_RANGE, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
}
// 2394 "parser.c"
        break;
      case 74:
// 941 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_EQUALS, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(11,&kkmsp[-1].minor);
}
// 2402 "parser.c"
        break;
      case 75:
// 945 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, kkmsp[-3].minor.kk92, NULL, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-2].minor);
  kk_destructor(26,&kkmsp[-1].minor);
  kk_destructor(64,&kkmsp[0].minor);
}
// 2412 "parser.c"
        break;
      case 76:
// 949 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_ISSET, kkmsp[-2].minor.kk92, NULL, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
  kk_destructor(64,&kkmsp[0].minor);
}
// 2421 "parser.c"
        break;
      case 77:
// 953 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_IS, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
}
// 2429 "parser.c"
        break;
      case 78:
// 957 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(12,&kkmsp[-1].minor);
}
// 2437 "parser.c"
        break;
      case 79:
// 961 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(17,&kkmsp[-1].minor);
}
// 2445 "parser.c"
        break;
      case 80:
// 965 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(18,&kkmsp[-1].minor);
}
// 2453 "parser.c"
        break;
      case 81:
// 969 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_LESS, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(13,&kkmsp[-1].minor);
}
// 2461 "parser.c"
        break;
      case 82:
// 973 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_GREATER, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(14,&kkmsp[-1].minor);
}
// 2469 "parser.c"
        break;
      case 83:
// 977 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(15,&kkmsp[-1].minor);
}
// 2477 "parser.c"
        break;
      case 84:
// 981 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(16,&kkmsp[-1].minor);
}
// 2485 "parser.c"
        break;
      case 85:
// 985 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_DOT, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(28,&kkmsp[-1].minor);
}
// 2493 "parser.c"
        break;
      case 86:
// 989 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_IN, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(3,&kkmsp[-1].minor);
}
// 2501 "parser.c"
        break;
      case 87:
// 993 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_NOT_IN, kkmsp[-3].minor.kk92, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(3,&kkmsp[-1].minor);
}
// 2510 "parser.c"
        break;
      case 88:
// 997 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, kkmsp[0].minor.kk92, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-1].minor);
}
// 2518 "parser.c"
        break;
      case 89:
// 1001 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, kkmsp[-1].minor.kk92, NULL, NULL, status->scanner_state);
  kk_destructor(27,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[0].minor);
}
// 2527 "parser.c"
        break;
      case 90:
// 1005 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-1].minor);
  kk_destructor(65,&kkmsp[0].minor);
}
// 2536 "parser.c"
        break;
      case 91:
// 1009 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk92, NULL, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-2].minor);
  kk_destructor(65,&kkmsp[0].minor);
}
// 2545 "parser.c"
        break;
      case 92:
// 1013 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, kkmsp[-3].minor.kk92, kkmsp[-1].minor.kk92, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-2].minor);
  kk_destructor(65,&kkmsp[0].minor);
}
// 2554 "parser.c"
        break;
      case 93:
// 1017 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_TERNARY, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92, kkmsp[-4].minor.kk92, status->scanner_state);
  kk_destructor(4,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 2563 "parser.c"
        break;
      case 94:
// 1021 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_slice(kkmsp[-4].minor.kk92, NULL, kkmsp[-1].minor.kk92, status->scanner_state);
  kk_destructor(6,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-2].minor);
  kk_destructor(65,&kkmsp[0].minor);
}
// 2573 "parser.c"
        break;
      case 95:
// 1025 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_slice(kkmsp[-4].minor.kk92, kkmsp[-2].minor.kk92, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-1].minor);
  kk_destructor(65,&kkmsp[0].minor);
}
// 2583 "parser.c"
        break;
      case 96:
// 1029 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_slice(kkmsp[-5].minor.kk92, kkmsp[-3].minor.kk92, kkmsp[-1].minor.kk92, status->scanner_state);
  kk_destructor(6,&kkmsp[-4].minor);
  kk_destructor(5,&kkmsp[-2].minor);
  kk_destructor(65,&kkmsp[0].minor);
}
// 2593 "parser.c"
        break;
      case 98:
      case 110:
// 1039 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2601 "parser.c"
        break;
      case 101:
      case 109:
// 1055 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_named_item(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk92, status->scanner_state);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 2610 "parser.c"
        break;
      case 102:
      case 108:
// 1059 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_named_item(NULL, kkmsp[0].minor.kk92, status->scanner_state);
}
// 2618 "parser.c"
        break;
      case 104:
// 1069 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_func_call(kkmsp[-3].minor.kk92, kkmsp[-1].minor.kk92, status->scanner_state);
  kk_destructor(27,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[0].minor);
}
// 2627 "parser.c"
        break;
      case 105:
// 1073 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_func_call(kkmsp[-2].minor.kk92, NULL, status->scanner_state);
  kk_destructor(27,&kkmsp[-1].minor);
  kk_destructor(41,&kkmsp[0].minor);
}
// 2636 "parser.c"
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
// 544 "parser.lemon"

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

// 2726 "parser.c"
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