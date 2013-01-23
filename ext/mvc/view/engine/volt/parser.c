/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 38 "parser.lemon"


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

static zval *phvolt_ret_if_statement(zval *expr, zval *true_statements, zval *false_statements, zval *elseif_expr, phvolt_scanner_state *state)
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

	if (elseif_expr) {
		add_assoc_zval(ret, "elseif_expr", elseif_expr);
	}

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

static zval *phvolt_ret_expr(int type, zval *left, zval *right, phvolt_scanner_state *state)
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


// 429 "parser.c"
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
#define KKNOCODE 88
#define KKACTIONTYPE unsigned short int
#define phvolt_KTOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_KTOKENTYPE kk0;
  zval* kk150;
  int kk175;
} KKMINORTYPE;
#define KKSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = kkpParser->status
#define phvolt_ARG_STORE kkpParser->status = status
#define KKNSTATE 225
#define KKNRULE 90
#define KKERRORSYMBOL 61
#define KKERRSYMDT kk175
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
 /*     0 */    87,   65,   57,   59,   69,   67,   71,   77,   79,   81,
 /*    10 */    83,   73,   75,   53,   51,   55,   49,   46,   61,   63,
 /*    20 */    90,   90,   85,   85,  195,   36,   87,   65,   57,   59,
 /*    30 */    69,   67,   71,   77,   79,   81,   83,   73,   75,   53,
 /*    40 */    51,   55,   49,   46,   61,   63,   90,  225,   85,   25,
 /*    50 */    27,  150,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    60 */    11,   12,   13,   14,   15,   16,   17,  186,  165,   31,
 /*    70 */   180,   87,   65,   57,   59,   69,   67,   71,   77,   79,
 /*    80 */    81,   83,   73,   75,   53,   51,   55,   49,   46,   61,
 /*    90 */    63,   90,   33,   85,   40,  211,  206,   87,   65,   57,
 /*   100 */    59,   69,   67,   71,   77,   79,   81,   83,   73,   75,
 /*   110 */    53,   51,   55,   49,   46,   61,   63,   90,   42,   85,
 /*   120 */    43,   85,   21,   87,   65,   57,   59,   69,   67,   71,
 /*   130 */    77,   79,   81,   83,   73,   75,   53,   51,   55,   49,
 /*   140 */    46,   61,   63,   90,  104,   85,  125,  120,   45,   87,
 /*   150 */    65,   57,   59,   69,   67,   71,   77,   79,   81,   83,
 /*   160 */    73,   75,   53,   51,   55,   49,   46,   61,   63,   90,
 /*   170 */   126,   85,   87,   65,   57,   59,   69,   67,   71,   77,
 /*   180 */    79,   81,   83,   73,   75,   53,   51,   55,   49,   46,
 /*   190 */    61,   63,   90,  295,   85,   49,   46,   61,   63,   90,
 /*   200 */   130,   85,  295,  132,   89,  316,    1,    2,  179,    4,
 /*   210 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   220 */    15,   16,   17,  296,   98,   99,   96,  114,  106,  133,
 /*   230 */    87,   65,   57,   59,   69,   67,   71,   77,   79,   81,
 /*   240 */    83,   73,   75,   53,   51,   55,   49,   46,   61,   63,
 /*   250 */    90,  296,   85,  142,  143,  163,   87,   65,   57,   59,
 /*   260 */    69,   67,   71,   77,   79,   81,   83,   73,   75,   53,
 /*   270 */    51,   55,   49,   46,   61,   63,   90,  156,   85,   53,
 /*   280 */    51,   55,   49,   46,   61,   63,   90,   98,   85,   91,
 /*   290 */   102,  106,  177,  106,  115,  123,   87,   65,   57,   59,
 /*   300 */    69,   67,   71,   77,   79,   81,   83,   73,   75,   53,
 /*   310 */    51,   55,   49,   46,   61,   63,   90,  147,   85,  154,
 /*   320 */   157,  197,   87,   65,   57,   59,   69,   67,   71,   77,
 /*   330 */    79,   81,   83,   73,   75,   53,   51,   55,   49,   46,
 /*   340 */    61,   63,   90,  159,   85,  160,  166,  213,   87,   65,
 /*   350 */    57,   59,   69,   67,   71,   77,   79,   81,   83,   73,
 /*   360 */    75,   53,   51,   55,   49,   46,   61,   63,   90,  170,
 /*   370 */    85,  172,  174,  220,   87,   65,   57,   59,   69,   67,
 /*   380 */    71,   77,   79,   81,   83,   73,   75,   53,   51,   55,
 /*   390 */    49,   46,   61,   63,   90,  181,   85,   57,   59,   69,
 /*   400 */    67,   71,   77,   79,   81,   83,   73,   75,   53,   51,
 /*   410 */    55,   49,   46,   61,   63,   90,  185,   85,   69,   67,
 /*   420 */    71,   77,   79,   81,   83,   73,   75,   53,   51,   55,
 /*   430 */    49,   46,   61,   63,   90,  187,   85,  191,   22,  179,
 /*   440 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   450 */    14,   15,   16,   17,   28,  179,    4,    5,    6,    7,
 /*   460 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   470 */    37,  179,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   480 */    12,   13,   14,   15,   16,   17,  144,  179,    4,    5,
 /*   490 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   500 */    16,   17,  194,  151,  179,    4,    5,    6,    7,    8,
 /*   510 */     9,   10,   11,   12,   13,   14,   15,   16,   17,  167,
 /*   520 */   179,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   530 */    13,   14,   15,   16,   17,  182,  179,    4,    5,    6,
 /*   540 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   550 */    17,  188,  179,    4,    5,    6,    7,    8,    9,   10,
 /*   560 */    11,   12,   13,   14,   15,   16,   17,  201,  198,  179,
 /*   570 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   580 */    14,   15,   16,   17,  207,  179,    4,    5,    6,    7,
 /*   590 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   600 */   214,  179,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   610 */    12,   13,   14,   15,   16,   17,  221,  179,    4,    5,
 /*   620 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   630 */    16,   17,   19,  140,   24,   26,  218,   32,  101,   63,
 /*   640 */    90,   41,   85,  204,   88,  141,  129,  148,  106,  203,
 /*   650 */   155,   18,  158,  161,  164,   19,  140,   30,  171,  173,
 /*   660 */    32,   91,   20,  175,   41,  106,  106,  118,  141,  210,
 /*   670 */   148,  226,  217,  155,  224,  158,  161,  164,   19,  140,
 /*   680 */   178,  171,  173,   32,   35,  202,   39,   41,  106,  179,
 /*   690 */    44,  141,  128,  148,  106,  100,  155,   18,  158,  161,
 /*   700 */   164,   19,  140,  127,  171,  173,   32,  139,  179,  175,
 /*   710 */    41,  106,  179,  179,  141,  146,  148,  131,   34,  155,
 /*   720 */    23,  158,  161,  164,   19,  140,  178,  171,  173,   32,
 /*   730 */   117,  179,  175,   41,   48,  179,  179,  141,  106,  148,
 /*   740 */   153,   29,  155,   38,  158,  161,  164,   19,  140,  178,
 /*   750 */   171,  173,   32,  175,  192,  175,   41,   50,  179,   52,
 /*   760 */   141,  106,  148,  106,  179,  155,  175,  158,  161,  164,
 /*   770 */   178,  169,  178,  171,  173,   19,  140,  145,  179,  179,
 /*   780 */    32,   54,  152,  178,   41,  106,  116,   56,  141,  175,
 /*   790 */   148,  106,  179,  155,  175,  158,  161,  164,  179,  184,
 /*   800 */   179,  171,  173,   19,  140,   58,  178,  179,   32,  106,
 /*   810 */   168,  178,   41,   60,  179,  128,  141,  106,  148,  190,
 /*   820 */   179,  155,  175,  158,  161,  164,  127,   19,  140,  171,
 /*   830 */   173,  179,   32,   62,  179,  179,   41,  106,  183,  178,
 /*   840 */   141,  193,  148,  179,  179,  155,  179,  158,  161,  164,
 /*   850 */   175,   19,  140,  171,  173,  179,   32,   64,   66,  200,
 /*   860 */    41,  106,  106,  179,  141,  179,  148,  178,  179,  155,
 /*   870 */    68,  158,  161,  164,  106,   19,  140,  171,  173,  179,
 /*   880 */    32,  179,  179,  209,   41,   70,  189,   72,  141,  106,
 /*   890 */   148,  106,  179,  155,  199,  158,  161,  164,  175,   19,
 /*   900 */   140,  171,  173,  179,   32,   74,  175,  216,   41,  106,
 /*   910 */   208,  179,  141,  179,  148,  178,  179,  155,  179,  158,
 /*   920 */   161,  164,  175,  178,  179,  171,  173,   19,  140,  223,
 /*   930 */   179,   76,   32,   78,  215,  106,   41,  106,  179,  178,
 /*   940 */   141,  179,  148,  179,  179,  155,  175,  158,  161,  164,
 /*   950 */   222,  179,  179,  171,  173,   19,  140,   80,  179,  179,
 /*   960 */    32,  106,  175,  178,   41,   82,  179,   84,  141,  106,
 /*   970 */   148,  106,   97,  155,   86,  158,  161,  164,  106,  178,
 /*   980 */   179,  171,  173,   93,  179,  179,   95,  106,  179,   47,
 /*   990 */   106,  105,   94,  136,  179,  106,  124,   97,  179,  179,
 /*  1000 */   121,  149,  107,  162,  106,  106,  176,  106,  179,  179,
 /*  1010 */   106,  179,  196,  108,   47,  109,  106,   94,   92,  112,
 /*  1020 */   205,  113,   97,  179,  106,  138,  212,  135,  110,  111,
 /*  1030 */   106,  219,  179,  179,  179,  106,  179,  179,  134,   47,
 /*  1040 */   109,  179,   94,   92,  112,  179,  113,   97,  179,  179,
 /*  1050 */   179,  179,  107,  110,  111,  179,  179,  179,  179,  179,
 /*  1060 */   179,  179,  179,  108,   47,  119,  179,   94,   92,  112,
 /*  1070 */   179,  113,   97,  179,  179,  179,  122,  107,  110,  111,
 /*  1080 */   179,  179,  179,  179,  179,  179,  179,  179,  108,   47,
 /*  1090 */   109,  179,   94,   92,  112,  179,  113,   97,  179,  179,
 /*  1100 */   137,  179,  107,  110,  111,  179,  179,  179,  179,  179,
 /*  1110 */   179,  179,  179,  108,   47,  109,  179,   94,   92,  112,
 /*  1120 */   179,  113,   97,  179,  179,  179,  179,  107,  110,  111,
 /*  1130 */   179,  179,  179,  179,  179,  179,  179,  179,  108,   47,
 /*  1140 */   103,  179,   94,   92,  112,  179,  113,  179,  179,  179,
 /*  1150 */   179,  179,  107,  110,  111,  179,  179,  179,  179,  179,
 /*  1160 */   179,  179,  179,  108,  179,  119,  179,  179,  179,  112,
 /*  1170 */   179,  113,  179,  179,  179,  179,  179,  179,  110,  111,
};
static KKCODETYPE kk_lookahead[] = {
 /*     0 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*    10 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    20 */    23,   23,   25,   25,   27,   28,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,   18,   19,   20,   21,   22,   23,    0,   25,   28,
 /*    50 */    28,   28,   65,   66,   67,   68,   69,   70,   71,   72,
 /*    60 */    73,   74,   75,   76,   77,   78,   79,   44,   50,   28,
 /*    70 */    52,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*    80 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*    90 */    22,   23,   33,   25,   28,   27,   28,    3,    4,    5,
 /*   100 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   110 */    16,   17,   18,   19,   20,   21,   22,   23,   33,   25,
 /*   120 */    37,   25,   28,    3,    4,    5,    6,    7,    8,    9,
 /*   130 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   140 */    20,   21,   22,   23,    2,   25,   82,    2,   28,    3,
 /*   150 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   160 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   170 */    58,   25,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   180 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   190 */    21,   22,   23,   58,   25,   19,   20,   21,   22,   23,
 /*   200 */     2,   25,    2,   82,   58,   62,   63,   64,   65,   66,
 /*   210 */    67,   68,   69,   70,   71,   72,   73,   74,   75,   76,
 /*   220 */    77,   78,   79,   58,   80,   81,   57,   83,   84,   58,
 /*   230 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   240 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   250 */    23,    2,   25,   33,   28,   28,    3,    4,    5,    6,
 /*   260 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   270 */    17,   18,   19,   20,   21,   22,   23,   46,   25,   16,
 /*   280 */    17,   18,   19,   20,   21,   22,   23,   80,   25,   80,
 /*   290 */    83,   84,   39,   84,   85,   86,    3,    4,    5,    6,
 /*   300 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   310 */    17,   18,   19,   20,   21,   22,   23,   28,   25,   28,
 /*   320 */    28,   28,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   330 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   340 */    21,   22,   23,   46,   25,   28,   28,   28,    3,    4,
 /*   350 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   360 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   28,
 /*   370 */    25,   28,   28,   28,    3,    4,    5,    6,    7,    8,
 /*   380 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   390 */    19,   20,   21,   22,   23,   28,   25,    5,    6,    7,
 /*   400 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   410 */    18,   19,   20,   21,   22,   23,   28,   25,    7,    8,
 /*   420 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   430 */    19,   20,   21,   22,   23,   28,   25,   28,   64,   65,
 /*   440 */    66,   67,   68,   69,   70,   71,   72,   73,   74,   75,
 /*   450 */    76,   77,   78,   79,   64,   65,   66,   67,   68,   69,
 /*   460 */    70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
 /*   470 */    64,   65,   66,   67,   68,   69,   70,   71,   72,   73,
 /*   480 */    74,   75,   76,   77,   78,   79,   64,   65,   66,   67,
 /*   490 */    68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
 /*   500 */    78,   79,   28,   64,   65,   66,   67,   68,   69,   70,
 /*   510 */    71,   72,   73,   74,   75,   76,   77,   78,   79,   64,
 /*   520 */    65,   66,   67,   68,   69,   70,   71,   72,   73,   74,
 /*   530 */    75,   76,   77,   78,   79,   64,   65,   66,   67,   68,
 /*   540 */    69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
 /*   550 */    79,   64,   65,   66,   67,   68,   69,   70,   71,   72,
 /*   560 */    73,   74,   75,   76,   77,   78,   79,   28,   64,   65,
 /*   570 */    66,   67,   68,   69,   70,   71,   72,   73,   74,   75,
 /*   580 */    76,   77,   78,   79,   64,   65,   66,   67,   68,   69,
 /*   590 */    70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
 /*   600 */    64,   65,   66,   67,   68,   69,   70,   71,   72,   73,
 /*   610 */    74,   75,   76,   77,   78,   79,   64,   65,   66,   67,
 /*   620 */    68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
 /*   630 */    78,   79,   27,   28,   29,   30,   31,   32,    1,   22,
 /*   640 */    23,   36,   25,   34,   80,   40,   82,   42,   84,   33,
 /*   650 */    45,   26,   47,   48,   49,   27,   28,   29,   53,   54,
 /*   660 */    32,   80,   80,   38,   36,   84,   84,   86,   40,   28,
 /*   670 */    42,    0,   28,   45,   28,   47,   48,   49,   27,   28,
 /*   680 */    55,   53,   54,   32,   80,    1,   35,   36,   84,   87,
 /*   690 */    80,   40,   33,   42,   84,   58,   45,   26,   47,   48,
 /*   700 */    49,   27,   28,   44,   53,   54,   32,   80,   87,   38,
 /*   710 */    36,   84,   87,   87,   40,   41,   42,   58,   34,   45,
 /*   720 */    26,   47,   48,   49,   27,   28,   55,   53,   54,   32,
 /*   730 */     1,   87,   38,   36,   80,   87,   87,   40,   84,   42,
 /*   740 */    43,   26,   45,   26,   47,   48,   49,   27,   28,   55,
 /*   750 */    53,   54,   32,   38,   26,   38,   36,   80,   87,   80,
 /*   760 */    40,   84,   42,   84,   87,   45,   38,   47,   48,   49,
 /*   770 */    55,   51,   55,   53,   54,   27,   28,   26,   87,   87,
 /*   780 */    32,   80,   26,   55,   36,   84,   57,   80,   40,   38,
 /*   790 */    42,   84,   87,   45,   38,   47,   48,   49,   87,   51,
 /*   800 */    87,   53,   54,   27,   28,   80,   55,   87,   32,   84,
 /*   810 */    26,   55,   36,   80,   87,   33,   40,   84,   42,   43,
 /*   820 */    87,   45,   38,   47,   48,   49,   44,   27,   28,   53,
 /*   830 */    54,   87,   32,   80,   87,   87,   36,   84,   26,   55,
 /*   840 */    40,   41,   42,   87,   87,   45,   87,   47,   48,   49,
 /*   850 */    38,   27,   28,   53,   54,   87,   32,   80,   80,   35,
 /*   860 */    36,   84,   84,   87,   40,   87,   42,   55,   87,   45,
 /*   870 */    80,   47,   48,   49,   84,   27,   28,   53,   54,   87,
 /*   880 */    32,   87,   87,   35,   36,   80,   26,   80,   40,   84,
 /*   890 */    42,   84,   87,   45,   26,   47,   48,   49,   38,   27,
 /*   900 */    28,   53,   54,   87,   32,   80,   38,   35,   36,   84,
 /*   910 */    26,   87,   40,   87,   42,   55,   87,   45,   87,   47,
 /*   920 */    48,   49,   38,   55,   87,   53,   54,   27,   28,   29,
 /*   930 */    87,   80,   32,   80,   26,   84,   36,   84,   87,   55,
 /*   940 */    40,   87,   42,   87,   87,   45,   38,   47,   48,   49,
 /*   950 */    26,   87,   87,   53,   54,   27,   28,   80,   87,   87,
 /*   960 */    32,   84,   38,   55,   36,   80,   87,   80,   40,   84,
 /*   970 */    42,   84,    3,   45,   80,   47,   48,   49,   84,   55,
 /*   980 */    87,   53,   54,   80,   87,   87,   80,   84,   87,   20,
 /*   990 */    84,   80,   23,   24,   87,   84,    2,    3,   87,   87,
 /*  1000 */    80,   80,   33,   80,   84,   84,   80,   84,   87,   87,
 /*  1010 */    84,   87,   80,   44,   20,   46,   84,   23,   24,   50,
 /*  1020 */    80,   52,    3,   87,   84,   56,   80,   33,   59,   60,
 /*  1030 */    84,   80,   87,   87,   87,   84,   87,   87,   44,   20,
 /*  1040 */    46,   87,   23,   24,   50,   87,   52,    3,   87,   87,
 /*  1050 */    87,   87,   33,   59,   60,   87,   87,   87,   87,   87,
 /*  1060 */    87,   87,   87,   44,   20,   46,   87,   23,   24,   50,
 /*  1070 */    87,   52,    3,   87,   87,   87,   57,   33,   59,   60,
 /*  1080 */    87,   87,   87,   87,   87,   87,   87,   87,   44,   20,
 /*  1090 */    46,   87,   23,   24,   50,   87,   52,    3,   87,   87,
 /*  1100 */    56,   87,   33,   59,   60,   87,   87,   87,   87,   87,
 /*  1110 */    87,   87,   87,   44,   20,   46,   87,   23,   24,   50,
 /*  1120 */    87,   52,    3,   87,   87,   87,   87,   33,   59,   60,
 /*  1130 */    87,   87,   87,   87,   87,   87,   87,   87,   44,   20,
 /*  1140 */    46,   87,   23,   24,   50,   87,   52,   87,   87,   87,
 /*  1150 */    87,   87,   33,   59,   60,   87,   87,   87,   87,   87,
 /*  1160 */    87,   87,   87,   44,   87,   46,   87,   87,   87,   50,
 /*  1170 */    87,   52,   87,   87,   87,   87,   87,   87,   59,   60,
};
#define KK_SHIFT_USE_DFLT (-4)
static short kk_shift_ofst[] = {
 /*     0 */   625,   47,  671,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,  928, 1069,
 /*    20 */    94,  625,  694,  605,   21,   -4,   22,  625,  715,  628,
 /*    30 */    41,   -4,   59,  684, 1069,   -3,  625,  717,  651,   66,
 /*    40 */    -4,   85,   83, 1069,  120,   -4, 1069, 1069,  617, 1069,
 /*    50 */   617, 1069,  176, 1069,  176, 1069,  176, 1069,  411, 1069,
 /*    60 */   411, 1069,  617, 1069,   -2, 1069,  392, 1069,  263,  969,
 /*    70 */   263, 1069,  263, 1069,  263, 1069,  263, 1069,  263, 1069,
 /*    80 */   263, 1069,  263, 1069,  263, 1069,   -4,  994,  146,   -4,
 /*    90 */  1019,  371, 1069,   96, 1069,  169,   -4, 1094,  371,  637,
 /*   100 */    -4, 1094,   -4,  142, 1069,  371,   -4,   -4,   -4,   -4,
 /*   110 */    -4,   -4,   -4,   -4,   -4,  729,   -4, 1119,   -4,  145,
 /*   120 */  1069,  371,   -4,   -4,  782,  112,   -4,  135,  165,  198,
 /*   130 */   659,   -4,  171,   -4,  200,  249, 1044,   -4,   -4,  617,
 /*   140 */    -4,  220,  226,  728,  751,  674,  289,   -4, 1069,   23,
 /*   150 */   625,  756,  697,  291,   -4,  231,  292,   -4,  297,  317,
 /*   160 */    -4, 1069,  227,   -4,   18,  318,  625,  784,  720,  341,
 /*   170 */    -4,  343,   -4,  344,   -4, 1069,  253,   -4,   -4,   -4,
 /*   180 */   367,  625,  812,  748,  388,   -4,  407,  625,  860,  776,
 /*   190 */   409,   -4,  800,  474,   -4, 1069,  293,  625,  868,  824,
 /*   200 */   539,   -4,  616,  609, 1069,   68,  625,  884,  848,  641,
 /*   210 */    -4, 1069,  319,  625,  908,  872,  644,   -4, 1069,  345,
 /*   220 */   625,  924,  900,  646,   -4,
};
#define KK_REDUCE_USE_DFLT (-14)
static short kk_reduce_ofst[] = {
 /*     0 */   143,  -14,  -13,  -14,  -14,  -14,  -14,  -14,  -14,  -14,
 /*    10 */   -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  582,
 /*    20 */   -14,  374,  -13,  -14,  -14,  -14,  -14,  390,  -13,  -14,
 /*    30 */   -14,  -14,  -14,  -14,  604,  -14,  406,  -13,  -14,  -14,
 /*    40 */   -14,  -14,  -14,  610,  -14,  -14,  627,  654,  -14,  677,
 /*    50 */   -14,  679,  -14,  701,  -14,  707,  -14,  725,  -14,  733,
 /*    60 */   -14,  753,  -14,  777,  -14,  778,  -14,  790,  -14,  805,
 /*    70 */   -14,  807,  -14,  825,  -14,  851,  -14,  853,  -14,  877,
 /*    80 */   -14,  885,  -14,  887,  -14,  894,  -14,  564,  -14,  -14,
 /*    90 */   209,  -14,  903,  -14,  906,  -14,  -14,  144,  -14,  -14,
 /*   100 */   -14,  207,  -14,  -14,  911,  -14,  -14,  -14,  -14,  -14,
 /*   110 */   -14,  -14,  -14,  -14,  -14,  -14,  -14,  581,  -14,  -14,
 /*   120 */   920,  -14,  -14,  -14,   64,  -14,  -14,  -14,  -14,  -14,
 /*   130 */   121,  -14,  -14,  -14,  -14,  -14,  903,  -14,  -14,  -14,
 /*   140 */   -14,  -14,  -14,  422,  -13,  -14,  -14,  -14,  921,  -14,
 /*   150 */   439,  -13,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,
 /*   160 */   -14,  923,  -14,  -14,  -14,  -14,  455,  -13,  -14,  -14,
 /*   170 */   -14,  -14,  -14,  -14,  -14,  926,  -14,  -14,  -14,  -14,
 /*   180 */   -14,  471,  -13,  -14,  -14,  -14,  -14,  487,  -13,  -14,
 /*   190 */   -14,  -14,  -14,  -14,  -14,  932,  -14,  504,  -13,  -14,
 /*   200 */   -14,  -14,  -14,  -14,  940,  -14,  520,  -13,  -14,  -14,
 /*   210 */   -14,  946,  -14,  536,  -13,  -14,  -14,  -14,  951,  -14,
 /*   220 */   552,  -13,  -14,  -14,  -14,
};
static KKACTIONTYPE kk_default[] = {
 /*     0 */   315,  315,  315,  227,  229,  230,  231,  232,  233,  234,
 /*    10 */   235,  236,  237,  238,  239,  240,  241,  242,  315,  315,
 /*    20 */   315,  315,  315,  315,  315,  243,  315,  315,  315,  315,
 /*    30 */   315,  244,  315,  315,  315,  315,  315,  315,  315,  315,
 /*    40 */   246,  315,  315,  315,  315,  250,  315,  315,  265,  315,
 /*    50 */   267,  315,  268,  315,  269,  315,  270,  315,  271,  315,
 /*    60 */   272,  315,  273,  315,  274,  315,  275,  315,  276,  315,
 /*    70 */   279,  315,  280,  315,  281,  315,  282,  315,  283,  315,
 /*    80 */   284,  315,  285,  315,  286,  315,  287,  315,  315,  291,
 /*    90 */   315,  306,  315,  288,  315,  315,  289,  315,  300,  315,
 /*   100 */   290,  315,  297,  310,  315,  299,  301,  308,  309,  310,
 /*   110 */   311,  312,  313,  314,  298,  315,  302,  315,  304,  310,
 /*   120 */   315,  307,  303,  305,  315,  315,  292,  315,  315,  315,
 /*   130 */   315,  293,  315,  294,  309,  308,  315,  277,  278,  266,
 /*   140 */   251,  315,  315,  315,  315,  315,  315,  253,  315,  315,
 /*   150 */   315,  315,  315,  315,  255,  315,  315,  257,  315,  315,
 /*   160 */   258,  315,  315,  259,  315,  315,  315,  315,  315,  315,
 /*   170 */   260,  315,  262,  315,  263,  315,  315,  252,  264,  228,
 /*   180 */   315,  315,  315,  315,  315,  261,  315,  315,  315,  315,
 /*   190 */   315,  256,  315,  315,  254,  315,  315,  315,  315,  315,
 /*   200 */   315,  247,  315,  315,  315,  315,  315,  315,  315,  315,
 /*   210 */   248,  315,  315,  315,  315,  315,  315,  249,  315,  315,
 /*   220 */   315,  315,  315,  315,  245,
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
  "$",             "COMMA",         "COLON",         "SBRACKET_OPEN",
  "RANGE",         "AND",           "OR",            "IS",          
  "EQUALS",        "NOTEQUALS",     "LESS",          "GREATER",     
  "GREATEREQUAL",  "LESSEQUAL",     "IDENTICAL",     "NOTIDENTICAL",
  "DIVIDE",        "TIMES",         "MOD",           "PLUS",        
  "MINUS",         "CONCAT",        "PIPE",          "BRACKET_OPEN",
  "NOT",           "DOT",           "OPEN_DELIMITER",  "IF",          
  "CLOSE_DELIMITER",  "ENDIF",         "ELSE",          "ELSEIF",      
  "FOR",           "IDENTIFIER",    "IN",            "ENDFOR",      
  "SET",           "ASSIGN",        "OPEN_EDELIMITER",  "CLOSE_EDELIMITER",
  "BLOCK",         "ENDBLOCK",      "CACHE",         "ENDCACHE",    
  "INTEGER",       "EXTENDS",       "STRING",        "INCLUDE",     
  "DO",            "AUTOESCAPE",    "FALSE",         "ENDAUTOESCAPE",
  "TRUE",          "BREAK",         "CONTINUE",      "RAW_FRAGMENT",
  "DEFINED",       "BRACKET_CLOSE",  "SBRACKET_CLOSE",  "DOUBLE",      
  "NULL",          "error",         "program",       "volt_language",
  "statement_list",  "statement",     "raw_fragment",  "if_statement",
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
 /*   6 */ "statement ::= for_statement",
 /*   7 */ "statement ::= set_statement",
 /*   8 */ "statement ::= echo_statement",
 /*   9 */ "statement ::= block_statement",
 /*  10 */ "statement ::= cache_statement",
 /*  11 */ "statement ::= extends_statement",
 /*  12 */ "statement ::= include_statement",
 /*  13 */ "statement ::= do_statement",
 /*  14 */ "statement ::= autoescape_statement",
 /*  15 */ "statement ::= break_statement",
 /*  16 */ "statement ::= continue_statement",
 /*  17 */ "statement ::= empty_statement",
 /*  18 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  19 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  20 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSEIF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  21 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  22 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  23 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  24 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  25 */ "set_statement ::= OPEN_DELIMITER SET IDENTIFIER ASSIGN expr CLOSE_DELIMITER",
 /*  26 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  27 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  28 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  29 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  30 */ "cache_statement ::= OPEN_DELIMITER CACHE expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  31 */ "cache_statement ::= OPEN_DELIMITER CACHE expr INTEGER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  32 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  33 */ "include_statement ::= OPEN_DELIMITER INCLUDE STRING CLOSE_DELIMITER",
 /*  34 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  35 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE FALSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  36 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE TRUE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  37 */ "break_statement ::= OPEN_DELIMITER BREAK CLOSE_DELIMITER",
 /*  38 */ "continue_statement ::= OPEN_DELIMITER CONTINUE CLOSE_DELIMITER",
 /*  39 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  40 */ "expr ::= MINUS expr",
 /*  41 */ "expr ::= expr MINUS expr",
 /*  42 */ "expr ::= expr PLUS expr",
 /*  43 */ "expr ::= expr TIMES expr",
 /*  44 */ "expr ::= expr DIVIDE expr",
 /*  45 */ "expr ::= expr MOD expr",
 /*  46 */ "expr ::= expr AND expr",
 /*  47 */ "expr ::= expr OR expr",
 /*  48 */ "expr ::= expr CONCAT expr",
 /*  49 */ "expr ::= expr PIPE expr",
 /*  50 */ "expr ::= expr RANGE expr",
 /*  51 */ "expr ::= expr EQUALS expr",
 /*  52 */ "expr ::= expr IS NOT DEFINED",
 /*  53 */ "expr ::= expr IS DEFINED",
 /*  54 */ "expr ::= expr IS expr",
 /*  55 */ "expr ::= expr NOTEQUALS expr",
 /*  56 */ "expr ::= expr IDENTICAL expr",
 /*  57 */ "expr ::= expr NOTIDENTICAL expr",
 /*  58 */ "expr ::= expr LESS expr",
 /*  59 */ "expr ::= expr GREATER expr",
 /*  60 */ "expr ::= expr GREATEREQUAL expr",
 /*  61 */ "expr ::= expr LESSEQUAL expr",
 /*  62 */ "expr ::= expr DOT expr",
 /*  63 */ "expr ::= NOT expr",
 /*  64 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /*  65 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /*  66 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /*  67 */ "expr ::= expr SBRACKET_OPEN COLON slice_offset SBRACKET_CLOSE",
 /*  68 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON SBRACKET_CLOSE",
 /*  69 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON slice_offset SBRACKET_CLOSE",
 /*  70 */ "slice_offset ::= INTEGER",
 /*  71 */ "slice_offset ::= IDENTIFIER",
 /*  72 */ "array_list ::= array_list COMMA array_item",
 /*  73 */ "array_list ::= array_item",
 /*  74 */ "array_item ::= STRING COLON expr",
 /*  75 */ "array_item ::= expr",
 /*  76 */ "expr ::= function_call",
 /*  77 */ "function_call ::= expr BRACKET_OPEN argument_list BRACKET_CLOSE",
 /*  78 */ "function_call ::= expr BRACKET_OPEN BRACKET_CLOSE",
 /*  79 */ "argument_list ::= argument_list COMMA argument_item",
 /*  80 */ "argument_list ::= argument_item",
 /*  81 */ "argument_item ::= expr",
 /*  82 */ "argument_item ::= STRING COLON expr",
 /*  83 */ "expr ::= IDENTIFIER",
 /*  84 */ "expr ::= INTEGER",
 /*  85 */ "expr ::= STRING",
 /*  86 */ "expr ::= DOUBLE",
 /*  87 */ "expr ::= NULL",
 /*  88 */ "expr ::= FALSE",
 /*  89 */ "expr ::= TRUE",
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
// 505 "parser.lemon"
{
	if ((kkpminor->kk0)) {
		if ((kkpminor->kk0)->free_flag) {
			efree((kkpminor->kk0)->token);
		}
		efree((kkpminor->kk0));
	}
}
// 1193 "parser.c"
      break;
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
    case 85:
    case 86:
// 522 "parser.lemon"
{ zval_ptr_dtor(&(kkpminor->kk150)); }
// 1220 "parser.c"
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
  { 62, 1 },
  { 63, 1 },
  { 64, 2 },
  { 64, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 67, 8 },
  { 67, 12 },
  { 67, 13 },
  { 68, 10 },
  { 68, 12 },
  { 68, 12 },
  { 68, 14 },
  { 69, 6 },
  { 79, 2 },
  { 70, 3 },
  { 71, 8 },
  { 71, 7 },
  { 72, 8 },
  { 72, 9 },
  { 73, 4 },
  { 74, 4 },
  { 75, 4 },
  { 76, 8 },
  { 76, 8 },
  { 77, 3 },
  { 78, 3 },
  { 66, 1 },
  { 80, 2 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 4 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 3 },
  { 80, 2 },
  { 80, 3 },
  { 80, 3 },
  { 80, 4 },
  { 80, 5 },
  { 80, 5 },
  { 80, 6 },
  { 82, 1 },
  { 82, 1 },
  { 81, 3 },
  { 81, 1 },
  { 83, 3 },
  { 83, 1 },
  { 80, 1 },
  { 84, 4 },
  { 84, 3 },
  { 85, 3 },
  { 85, 1 },
  { 86, 1 },
  { 86, 3 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
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
// 514 "parser.lemon"
{
	status->ret = kkmsp[0].minor.kk150;
}
// 1527 "parser.c"
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
      case 76:
// 518 "parser.lemon"
{
	kkgotominor.kk150 = kkmsp[0].minor.kk150;
}
// 1549 "parser.c"
        break;
      case 2:
// 524 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_zval_list(kkmsp[-1].minor.kk150, kkmsp[0].minor.kk150);
}
// 1556 "parser.c"
        break;
      case 3:
      case 73:
      case 80:
// 528 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_zval_list(NULL, kkmsp[0].minor.kk150);
}
// 1565 "parser.c"
        break;
      case 18:
// 592 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_if_statement(kkmsp[-5].minor.kk150, kkmsp[-3].minor.kk150, NULL, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(27,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(29,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1578 "parser.c"
        break;
      case 19:
// 596 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_if_statement(kkmsp[-9].minor.kk150, kkmsp[-7].minor.kk150, kkmsp[-3].minor.kk150, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-11].minor);
  kk_destructor(27,&kkmsp[-10].minor);
  kk_destructor(28,&kkmsp[-8].minor);
  kk_destructor(26,&kkmsp[-6].minor);
  kk_destructor(30,&kkmsp[-5].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(29,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1594 "parser.c"
        break;
      case 20:
// 600 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_if_statement(kkmsp[-10].minor.kk150, kkmsp[-8].minor.kk150, kkmsp[-3].minor.kk150, kkmsp[-5].minor.kk150, status->scanner_state);
  kk_destructor(26,&kkmsp[-12].minor);
  kk_destructor(27,&kkmsp[-11].minor);
  kk_destructor(28,&kkmsp[-9].minor);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(31,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(29,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1610 "parser.c"
        break;
      case 21:
// 606 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-5].minor.kk150, NULL, kkmsp[-3].minor.kk150, status->scanner_state);
  kk_destructor(26,&kkmsp[-9].minor);
  kk_destructor(32,&kkmsp[-8].minor);
  kk_destructor(34,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(35,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1624 "parser.c"
        break;
      case 22:
// 610 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, NULL, kkmsp[-7].minor.kk150, kkmsp[-5].minor.kk150, kkmsp[-3].minor.kk150, status->scanner_state);
  kk_destructor(26,&kkmsp[-11].minor);
  kk_destructor(32,&kkmsp[-10].minor);
  kk_destructor(34,&kkmsp[-8].minor);
  kk_destructor(27,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(35,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1639 "parser.c"
        break;
      case 23:
// 614 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, kkmsp[-9].minor.kk0, kkmsp[-5].minor.kk150, NULL, kkmsp[-3].minor.kk150, status->scanner_state);
  kk_destructor(26,&kkmsp[-11].minor);
  kk_destructor(32,&kkmsp[-10].minor);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(34,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(35,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1654 "parser.c"
        break;
      case 24:
// 618 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, kkmsp[-11].minor.kk0, kkmsp[-7].minor.kk150, kkmsp[-5].minor.kk150, kkmsp[-3].minor.kk150, status->scanner_state);
  kk_destructor(26,&kkmsp[-13].minor);
  kk_destructor(32,&kkmsp[-12].minor);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(34,&kkmsp[-8].minor);
  kk_destructor(27,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(35,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1670 "parser.c"
        break;
      case 25:
// 624 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_set_statement(kkmsp[-3].minor.kk0, kkmsp[-1].minor.kk150, status->scanner_state);
  kk_destructor(26,&kkmsp[-5].minor);
  kk_destructor(36,&kkmsp[-4].minor);
  kk_destructor(37,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1681 "parser.c"
        break;
      case 26:
// 630 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_empty_statement(status->scanner_state);
  kk_destructor(26,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1690 "parser.c"
        break;
      case 27:
// 636 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_echo_statement(kkmsp[-1].minor.kk150, status->scanner_state);
  kk_destructor(38,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[0].minor);
}
// 1699 "parser.c"
        break;
      case 28:
// 642 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_block_statement(kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk150, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(40,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1712 "parser.c"
        break;
      case 29:
// 646 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_block_statement(kkmsp[-4].minor.kk0, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-6].minor);
  kk_destructor(40,&kkmsp[-5].minor);
  kk_destructor(28,&kkmsp[-3].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1725 "parser.c"
        break;
      case 30:
// 652 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_cache_statement(kkmsp[-5].minor.kk150, NULL, kkmsp[-3].minor.kk150, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(42,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(43,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1738 "parser.c"
        break;
      case 31:
// 656 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_cache_statement(kkmsp[-6].minor.kk150, kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk150, status->scanner_state);
  kk_destructor(26,&kkmsp[-8].minor);
  kk_destructor(42,&kkmsp[-7].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(43,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1751 "parser.c"
        break;
      case 32:
// 662 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_extends_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(26,&kkmsp[-3].minor);
  kk_destructor(45,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1761 "parser.c"
        break;
      case 33:
// 668 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_include_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(26,&kkmsp[-3].minor);
  kk_destructor(47,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1771 "parser.c"
        break;
      case 34:
// 674 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_do_statement(kkmsp[-1].minor.kk150, status->scanner_state);
  kk_destructor(26,&kkmsp[-3].minor);
  kk_destructor(48,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1781 "parser.c"
        break;
      case 35:
// 680 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_autoescape_statement(0, kkmsp[-3].minor.kk150, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(49,&kkmsp[-6].minor);
  kk_destructor(50,&kkmsp[-5].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(51,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1795 "parser.c"
        break;
      case 36:
// 684 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_autoescape_statement(1, kkmsp[-3].minor.kk150, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(49,&kkmsp[-6].minor);
  kk_destructor(52,&kkmsp[-5].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(51,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1809 "parser.c"
        break;
      case 37:
// 690 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_break_statement(status->scanner_state);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(53,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1819 "parser.c"
        break;
      case 38:
// 696 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_continue_statement(status->scanner_state);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(54,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1829 "parser.c"
        break;
      case 39:
// 702 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, kkmsp[0].minor.kk0, status->scanner_state);
}
// 1836 "parser.c"
        break;
      case 40:
// 708 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 1844 "parser.c"
        break;
      case 41:
// 712 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_SUB, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 1852 "parser.c"
        break;
      case 42:
// 716 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_ADD, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 1860 "parser.c"
        break;
      case 43:
// 720 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_MUL, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(17,&kkmsp[-1].minor);
}
// 1868 "parser.c"
        break;
      case 44:
// 724 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_DIV, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(16,&kkmsp[-1].minor);
}
// 1876 "parser.c"
        break;
      case 45:
// 728 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(18,&kkmsp[-1].minor);
}
// 1884 "parser.c"
        break;
      case 46:
// 732 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_AND, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 1892 "parser.c"
        break;
      case 47:
// 736 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_OR, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(6,&kkmsp[-1].minor);
}
// 1900 "parser.c"
        break;
      case 48:
// 740 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_CONCAT, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
// 1908 "parser.c"
        break;
      case 49:
// 744 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_PIPE, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 1916 "parser.c"
        break;
      case 50:
// 748 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_RANGE, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(4,&kkmsp[-1].minor);
}
// 1924 "parser.c"
        break;
      case 51:
// 752 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_EQUALS, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(8,&kkmsp[-1].minor);
}
// 1932 "parser.c"
        break;
      case 52:
// 756 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, kkmsp[-3].minor.kk150, NULL, status->scanner_state);
  kk_destructor(7,&kkmsp[-2].minor);
  kk_destructor(24,&kkmsp[-1].minor);
  kk_destructor(56,&kkmsp[0].minor);
}
// 1942 "parser.c"
        break;
      case 53:
// 760 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_ISSET, kkmsp[-2].minor.kk150, NULL, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
  kk_destructor(56,&kkmsp[0].minor);
}
// 1951 "parser.c"
        break;
      case 54:
// 764 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_IS, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
}
// 1959 "parser.c"
        break;
      case 55:
// 768 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
}
// 1967 "parser.c"
        break;
      case 56:
// 772 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(14,&kkmsp[-1].minor);
}
// 1975 "parser.c"
        break;
      case 57:
// 776 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(15,&kkmsp[-1].minor);
}
// 1983 "parser.c"
        break;
      case 58:
// 780 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_LESS, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
}
// 1991 "parser.c"
        break;
      case 59:
// 784 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_GREATER, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(11,&kkmsp[-1].minor);
}
// 1999 "parser.c"
        break;
      case 60:
// 788 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(12,&kkmsp[-1].minor);
}
// 2007 "parser.c"
        break;
      case 61:
// 792 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(13,&kkmsp[-1].minor);
}
// 2015 "parser.c"
        break;
      case 62:
// 796 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_DOT, kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(25,&kkmsp[-1].minor);
}
// 2023 "parser.c"
        break;
      case 63:
// 800 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(24,&kkmsp[-1].minor);
}
// 2031 "parser.c"
        break;
      case 64:
// 804 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, kkmsp[-1].minor.kk150, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(57,&kkmsp[0].minor);
}
// 2040 "parser.c"
        break;
      case 65:
// 808 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk150, NULL, status->scanner_state);
  kk_destructor(3,&kkmsp[-2].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
// 2049 "parser.c"
        break;
      case 66:
// 812 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, kkmsp[-3].minor.kk150, kkmsp[-1].minor.kk150, status->scanner_state);
  kk_destructor(3,&kkmsp[-2].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
// 2058 "parser.c"
        break;
      case 67:
// 816 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_slice(kkmsp[-4].minor.kk150, NULL, kkmsp[-1].minor.kk150, status->scanner_state);
  kk_destructor(3,&kkmsp[-3].minor);
  kk_destructor(2,&kkmsp[-2].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
// 2068 "parser.c"
        break;
      case 68:
// 820 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_slice(kkmsp[-4].minor.kk150, kkmsp[-2].minor.kk150, NULL, status->scanner_state);
  kk_destructor(3,&kkmsp[-3].minor);
  kk_destructor(2,&kkmsp[-1].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
// 2078 "parser.c"
        break;
      case 69:
// 824 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_slice(kkmsp[-5].minor.kk150, kkmsp[-3].minor.kk150, kkmsp[-1].minor.kk150, status->scanner_state);
  kk_destructor(3,&kkmsp[-4].minor);
  kk_destructor(2,&kkmsp[-2].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
// 2088 "parser.c"
        break;
      case 70:
      case 84:
// 830 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2096 "parser.c"
        break;
      case 71:
      case 83:
// 834 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2104 "parser.c"
        break;
      case 72:
      case 79:
// 840 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_zval_list(kkmsp[-2].minor.kk150, kkmsp[0].minor.kk150);
  kk_destructor(1,&kkmsp[-1].minor);
}
// 2113 "parser.c"
        break;
      case 74:
      case 82:
// 850 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_named_item(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk150, status->scanner_state);
  kk_destructor(2,&kkmsp[-1].minor);
}
// 2122 "parser.c"
        break;
      case 75:
      case 81:
// 854 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_named_item(NULL, kkmsp[0].minor.kk150, status->scanner_state);
}
// 2130 "parser.c"
        break;
      case 77:
// 864 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_func_call(kkmsp[-3].minor.kk150, kkmsp[-1].minor.kk150, status->scanner_state);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(57,&kkmsp[0].minor);
}
// 2139 "parser.c"
        break;
      case 78:
// 868 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_func_call(kkmsp[-2].minor.kk150, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
  kk_destructor(57,&kkmsp[0].minor);
}
// 2148 "parser.c"
        break;
      case 85:
// 900 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_literal_zval(PHVOLT_T_STRING, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2155 "parser.c"
        break;
      case 86:
// 904 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2162 "parser.c"
        break;
      case 87:
// 908 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  kk_destructor(60,&kkmsp[0].minor);
}
// 2170 "parser.c"
        break;
      case 88:
// 912 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  kk_destructor(50,&kkmsp[0].minor);
}
// 2178 "parser.c"
        break;
      case 89:
// 916 "parser.lemon"
{
	kkgotominor.kk150 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  kk_destructor(52,&kkmsp[0].minor);
}
// 2186 "parser.c"
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
// 459 "parser.lemon"

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

// 2274 "parser.c"
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
  { PHVOLT_T_LESS,          	"<" },
  { PHVOLT_T_LESSEQUAL,     	"<=" },
  { PHVOLT_T_GREATER,       	">" },
  { PHVOLT_T_GREATEREQUAL,  	">=" },
  { PHVOLT_T_BRACKET_OPEN,  	"(" },
  { PHVOLT_T_BRACKET_CLOSE, 	")" },
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
				if (state->extends_mode == 1 && state->block_level == 0){
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
					state->block_level++;
				}
				phvolt_(phvolt_parser, PHVOLT_IF, NULL, parser_status);
				break;
			case PHVOLT_T_ELSE:
				phvolt_(phvolt_parser, PHVOLT_ELSE, NULL, parser_status);
				break;
			case PHVOLT_T_ELSEIF:
				phvolt_(phvolt_parser, PHVOLT_ELSEIF, NULL, parser_status);
				break;
			case PHVOLT_T_ENDIF:
				state->block_level--;
				phvolt_(phvolt_parser, PHVOLT_ENDIF, NULL, parser_status);
				break;

			case PHVOLT_T_FOR:
				if (state->extends_mode == 1 && state->block_level == 0){
					phvolt_create_error_msg(parser_status, "Child templates only may contain blocks");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				} else {
					state->block_level++;
				}
				phvolt_(phvolt_parser, PHVOLT_FOR, NULL, parser_status);
				break;
			case PHVOLT_T_IN:
				phvolt_(phvolt_parser, PHVOLT_IN, NULL, parser_status);
				break;
			case PHVOLT_T_ENDFOR:
				state->block_level--;
				phvolt_(phvolt_parser, PHVOLT_ENDFOR, NULL, parser_status);
				break;

			case PHVOLT_T_RAW_FRAGMENT:
				if (state->extends_mode == 1 && state->block_level == 0){
					if(!phvolt_is_blank_string(&token)){
						phvolt_create_error_msg(parser_status, "Child templates only may contain blocks");
						parser_status->status = PHVOLT_PARSING_FAILED;
					}
					efree(token.value);
					break;
				} else {
					if(!phvolt_is_blank_string(&token)){
						state->statement_position++;
					}
				}
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_RAW_FRAGMENT, PHVOLT_RAW_FRAGMENT, &token, parser_status);
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
				if(state->block_level > 0){
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