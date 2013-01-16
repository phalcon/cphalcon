/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 39 "parser.lemon"


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

static zval *phvolt_ret_cache_statement(phvolt_parser_token *key, phvolt_parser_token *lifetime, zval *block_statements, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_CACHE);
	add_assoc_stringl(ret, "key", key->token, key->token_len, 0);
	efree(key);

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


// 425 "parser.c"
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
#define KKNOCODE 87
#define KKACTIONTYPE unsigned short int
#define phvolt_KTOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_KTOKENTYPE kk0;
  zval* kk128;
  int kk173;
} KKMINORTYPE;
#define KKSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = kkpParser->status
#define phvolt_ARG_STORE kkpParser->status = status
#define KKNSTATE 218
#define KKNRULE 89
#define KKERRORSYMBOL 60
#define KKERRSYMDT kk173
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
 /*    10 */    83,   73,   75,   63,   53,   51,   55,   49,   46,   61,
 /*    20 */    90,   90,   85,   85,  195,   36,   87,   65,   57,   59,
 /*    30 */    69,   67,   71,   77,   79,   81,   83,   73,   75,   63,
 /*    40 */    53,   51,   55,   49,   46,   61,   90,  117,   85,   25,
 /*    50 */   211,  206,   87,   65,   57,   59,   69,   67,   71,   77,
 /*    60 */    79,   81,   83,   73,   75,   63,   53,   51,   55,   49,
 /*    70 */    46,   61,   90,  165,   85,  180,  218,   21,   87,   65,
 /*    80 */    57,   59,   69,   67,   71,   77,   79,   81,   83,   73,
 /*    90 */    75,   63,   53,   51,   55,   49,   46,   61,   90,   27,
 /*   100 */    85,   31,  116,   45,   87,   65,   57,   59,   69,   67,
 /*   110 */    71,   77,   79,   81,   83,   73,   75,   63,   53,   51,
 /*   120 */    55,   49,   46,   61,   90,   33,   85,   87,   65,   57,
 /*   130 */    59,   69,   67,   71,   77,   79,   81,   83,   73,   75,
 /*   140 */    63,   53,   51,   55,   49,   46,   61,   90,   40,   85,
 /*   150 */    49,   46,   61,   90,   42,   85,   85,   43,   89,  308,
 /*   160 */     1,    2,  179,    4,    5,    6,    7,    8,    9,   10,
 /*   170 */    11,   12,   13,   14,   15,   16,   17,  104,   98,   99,
 /*   180 */    96,  114,  106,  125,   87,   65,   57,   59,   69,   67,
 /*   190 */    71,   77,   79,   81,   83,   73,   75,   63,   53,   51,
 /*   200 */    55,   49,   46,   61,   90,  120,   85,  126,  287,  163,
 /*   210 */    87,   65,   57,   59,   69,   67,   71,   77,   79,   81,
 /*   220 */    83,   73,   75,   63,   53,   51,   55,   49,   46,   61,
 /*   230 */    90,  288,   85,   63,   53,   51,   55,   49,   46,   61,
 /*   240 */    90,  202,   85,   20,   88,  177,  129,  106,  106,   87,
 /*   250 */    65,   57,   59,   69,   67,   71,   77,   79,   81,   83,
 /*   260 */    73,   75,   63,   53,   51,   55,   49,   46,   61,   90,
 /*   270 */   130,   85,  132,   34,  197,   87,   65,   57,   59,   69,
 /*   280 */    67,   71,   77,   79,   81,   83,   73,   75,   63,   53,
 /*   290 */    51,   55,   49,   46,   61,   90,  133,   85,  287,  288,
 /*   300 */   213,   87,   65,   57,   59,   69,   67,   71,   77,   79,
 /*   310 */    81,   83,   73,   75,   63,   53,   51,   55,   49,   46,
 /*   320 */    61,   90,  142,   85,   57,   59,   69,   67,   71,   77,
 /*   330 */    79,   81,   83,   73,   75,   63,   53,   51,   55,   49,
 /*   340 */    46,   61,   90,  143,   85,   69,   67,   71,   77,   79,
 /*   350 */    81,   83,   73,   75,   63,   53,   51,   55,   49,   46,
 /*   360 */    61,   90,  147,   85,   22,  179,    4,    5,    6,    7,
 /*   370 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   380 */    28,  179,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   390 */    12,   13,   14,   15,   16,   17,   37,  179,    4,    5,
 /*   400 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   410 */    16,   17,  144,  179,    4,    5,    6,    7,    8,    9,
 /*   420 */    10,   11,   12,   13,   14,   15,   16,   17,  151,  179,
 /*   430 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   440 */    14,   15,   16,   17,  167,  179,    4,    5,    6,    7,
 /*   450 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   460 */   182,  179,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   470 */    12,   13,   14,   15,   16,   17,  188,  179,    4,    5,
 /*   480 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   490 */    16,   17,  198,  179,    4,    5,    6,    7,    8,    9,
 /*   500 */    10,   11,   12,   13,   14,   15,   16,   17,  207,  179,
 /*   510 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   520 */    14,   15,   16,   17,  214,  179,    4,    5,    6,    7,
 /*   530 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   540 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   550 */    13,   14,   15,   16,   17,   19,  140,   24,   26,   32,
 /*   560 */    91,  149,  128,   41,  106,  115,  123,  141,  128,  148,
 /*   570 */   154,  156,  155,  127,  158,  161,  164,   18,   23,  127,
 /*   580 */   171,  173,   19,  140,   30,  219,   32,   29,  175,  175,
 /*   590 */    41,   91,  159,  131,  141,  106,  148,  118,  175,  155,
 /*   600 */    35,  158,  161,  164,  106,  178,  178,  171,  173,   19,
 /*   610 */   140,   18,  157,   32,   38,  178,   39,   41,  101,  160,
 /*   620 */    44,  141,  175,  148,  106,  175,  155,  139,  158,  161,
 /*   630 */   164,  106,  166,  170,  171,  173,   19,  140,  172,  178,
 /*   640 */    32,  192,  178,   98,   41,  203,  102,  106,  141,  146,
 /*   650 */   148,  174,  175,  155,   48,  158,  161,  164,  106,  181,
 /*   660 */   185,  171,  173,   19,  140,  187,   50,   32,  145,  178,
 /*   670 */   106,   41,  150,  191,  100,  141,  194,  148,  153,  175,
 /*   680 */   155,   52,  158,  161,  164,  106,  201,  186,  171,  173,
 /*   690 */    19,  140,  204,   54,   32,  152,  178,  106,   41,  210,
 /*   700 */   217,   56,  141,  177,  148,  106,  175,  155,   58,  158,
 /*   710 */   161,  164,  106,  169,  177,  171,  173,   19,  140,  177,
 /*   720 */    60,   32,  168,  178,  106,   41,   62,  177,   64,  141,
 /*   730 */   106,  148,  106,  175,  155,   66,  158,  161,  164,  106,
 /*   740 */   184,  177,  171,  173,   19,  140,  177,   68,   32,  183,
 /*   750 */   178,  106,   41,  177,  177,  177,  141,  177,  148,  190,
 /*   760 */   175,  155,   70,  158,  161,  164,  106,  189,  177,  171,
 /*   770 */   173,   19,  140,  177,  177,   32,  199,  178,  175,   41,
 /*   780 */   177,  177,   72,  141,  193,  148,  106,  175,  155,   74,
 /*   790 */   158,  161,  164,  106,  177,  178,  171,  173,   19,  140,
 /*   800 */   177,  177,   32,  208,  178,  200,   41,  177,  177,   76,
 /*   810 */   141,  177,  148,  106,  175,  155,   78,  158,  161,  164,
 /*   820 */   106,  177,  177,  171,  173,   19,  140,  177,  177,   32,
 /*   830 */   215,  178,  209,   41,  177,  177,   80,  141,  177,  148,
 /*   840 */   106,  175,  155,   82,  158,  161,  164,  106,  177,  177,
 /*   850 */   171,  173,   19,  140,  177,  177,   32,   84,  178,  216,
 /*   860 */    41,  106,  177,   86,  141,  177,  148,  106,   97,  155,
 /*   870 */    93,  158,  161,  164,  106,  177,  177,  171,  173,   19,
 /*   880 */   140,  177,  177,   32,  177,  177,   47,   41,   94,  136,
 /*   890 */    95,  141,  177,  148,  106,  177,  155,  107,  158,  161,
 /*   900 */   164,  177,  177,  105,  171,  173,  177,  106,  108,  121,
 /*   910 */   109,  124,   97,  106,  112,  177,  113,  162,  177,  177,
 /*   920 */   138,  106,  176,  110,  111,  196,  106,  205,  177,  106,
 /*   930 */    47,  106,   94,   92,   53,   51,   55,   49,   46,   61,
 /*   940 */    90,  135,   85,  212,  177,   97,  177,  106,  177,  177,
 /*   950 */   177,  177,  134,  177,  109,  177,  177,  177,  112,  177,
 /*   960 */   113,  177,  177,   47,  177,   94,   92,  110,  111,  177,
 /*   970 */   177,  177,  177,  177,  107,  177,  177,  177,  177,  177,
 /*   980 */   177,  177,  177,  177,  177,  108,  177,  119,  177,   97,
 /*   990 */   177,  112,  177,  113,  177,  177,  177,  177,  122,  177,
 /*  1000 */   110,  111,  177,  177,  177,  177,  177,   47,  177,   94,
 /*  1010 */    92,  177,  177,  177,  177,  177,  177,  177,  107,  177,
 /*  1020 */   177,  177,   97,  177,  177,  177,  177,  177,  177,  108,
 /*  1030 */   177,  109,  177,  177,  177,  112,  177,  113,  177,  177,
 /*  1040 */    47,  137,   94,   92,  110,  111,  177,  177,  177,  177,
 /*  1050 */   177,  107,  177,  177,  177,   97,  177,  177,  177,  177,
 /*  1060 */   177,  177,  108,  177,  109,  177,  177,  177,  112,  177,
 /*  1070 */   113,  177,  177,   47,  177,   94,   92,  110,  111,  177,
 /*  1080 */   177,  177,  177,  177,  107,  177,  177,  177,   97,  177,
 /*  1090 */   177,  177,  177,  177,  177,  108,  177,  103,  177,  177,
 /*  1100 */   177,  112,  177,  113,  177,  177,   47,  177,   94,   92,
 /*  1110 */   110,  111,  177,  177,  177,  177,  177,  107,  177,  177,
 /*  1120 */   177,  177,  177,  177,  177,  177,  177,  177,  108,  177,
 /*  1130 */   119,  177,  177,  177,  112,  177,  113,  177,  177,  177,
 /*  1140 */   177,  177,  177,  110,  111,
};
static KKCODETYPE kk_lookahead[] = {
 /*     0 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*    10 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    20 */    23,   23,   25,   25,   27,   28,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,   18,   19,   20,   21,   22,   23,    1,   25,   28,
 /*    50 */    27,   28,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    60 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    70 */    21,   22,   23,   49,   25,   51,    0,   28,    3,    4,
 /*    80 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*    90 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   28,
 /*   100 */    25,   28,   56,   28,    3,    4,    5,    6,    7,    8,
 /*   110 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   120 */    19,   20,   21,   22,   23,   32,   25,    3,    4,    5,
 /*   130 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   140 */    16,   17,   18,   19,   20,   21,   22,   23,   28,   25,
 /*   150 */    20,   21,   22,   23,   32,   25,   25,   36,   57,   61,
 /*   160 */    62,   63,   64,   65,   66,   67,   68,   69,   70,   71,
 /*   170 */    72,   73,   74,   75,   76,   77,   78,    2,   79,   80,
 /*   180 */    56,   82,   83,   81,    3,    4,    5,    6,    7,    8,
 /*   190 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   200 */    19,   20,   21,   22,   23,    2,   25,   57,   57,   28,
 /*   210 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   220 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   230 */    23,   57,   25,   16,   17,   18,   19,   20,   21,   22,
 /*   240 */    23,    1,   25,   79,   79,   38,   81,   83,   83,    3,
 /*   250 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   260 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   270 */     2,   25,   81,   33,   28,    3,    4,    5,    6,    7,
 /*   280 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   290 */    18,   19,   20,   21,   22,   23,   57,   25,    2,    2,
 /*   300 */    28,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   310 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   320 */    22,   23,   32,   25,    5,    6,    7,    8,    9,   10,
 /*   330 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   340 */    21,   22,   23,   28,   25,    7,    8,    9,   10,   11,
 /*   350 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   360 */    22,   23,   28,   25,   63,   64,   65,   66,   67,   68,
 /*   370 */    69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
 /*   380 */    63,   64,   65,   66,   67,   68,   69,   70,   71,   72,
 /*   390 */    73,   74,   75,   76,   77,   78,   63,   64,   65,   66,
 /*   400 */    67,   68,   69,   70,   71,   72,   73,   74,   75,   76,
 /*   410 */    77,   78,   63,   64,   65,   66,   67,   68,   69,   70,
 /*   420 */    71,   72,   73,   74,   75,   76,   77,   78,   63,   64,
 /*   430 */    65,   66,   67,   68,   69,   70,   71,   72,   73,   74,
 /*   440 */    75,   76,   77,   78,   63,   64,   65,   66,   67,   68,
 /*   450 */    69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
 /*   460 */    63,   64,   65,   66,   67,   68,   69,   70,   71,   72,
 /*   470 */    73,   74,   75,   76,   77,   78,   63,   64,   65,   66,
 /*   480 */    67,   68,   69,   70,   71,   72,   73,   74,   75,   76,
 /*   490 */    77,   78,   63,   64,   65,   66,   67,   68,   69,   70,
 /*   500 */    71,   72,   73,   74,   75,   76,   77,   78,   63,   64,
 /*   510 */    65,   66,   67,   68,   69,   70,   71,   72,   73,   74,
 /*   520 */    75,   76,   77,   78,   63,   64,   65,   66,   67,   68,
 /*   530 */    69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
 /*   540 */    64,   65,   66,   67,   68,   69,   70,   71,   72,   73,
 /*   550 */    74,   75,   76,   77,   78,   27,   28,   29,   30,   31,
 /*   560 */    79,   32,   32,   35,   83,   84,   85,   39,   32,   41,
 /*   570 */    28,   45,   44,   43,   46,   47,   48,   26,   26,   43,
 /*   580 */    52,   53,   27,   28,   29,    0,   31,   26,   37,   37,
 /*   590 */    35,   79,   45,   57,   39,   83,   41,   85,   37,   44,
 /*   600 */    79,   46,   47,   48,   83,   54,   54,   52,   53,   27,
 /*   610 */    28,   26,   28,   31,   26,   54,   34,   35,    1,   28,
 /*   620 */    79,   39,   37,   41,   83,   37,   44,   79,   46,   47,
 /*   630 */    48,   83,   28,   28,   52,   53,   27,   28,   28,   54,
 /*   640 */    31,   26,   54,   79,   35,   32,   82,   83,   39,   40,
 /*   650 */    41,   28,   37,   44,   79,   46,   47,   48,   83,   28,
 /*   660 */    28,   52,   53,   27,   28,   28,   79,   31,   26,   54,
 /*   670 */    83,   35,   28,   28,   57,   39,   28,   41,   42,   37,
 /*   680 */    44,   79,   46,   47,   48,   83,   28,   43,   52,   53,
 /*   690 */    27,   28,   33,   79,   31,   26,   54,   83,   35,   28,
 /*   700 */    28,   79,   39,   86,   41,   83,   37,   44,   79,   46,
 /*   710 */    47,   48,   83,   50,   86,   52,   53,   27,   28,   86,
 /*   720 */    79,   31,   26,   54,   83,   35,   79,   86,   79,   39,
 /*   730 */    83,   41,   83,   37,   44,   79,   46,   47,   48,   83,
 /*   740 */    50,   86,   52,   53,   27,   28,   86,   79,   31,   26,
 /*   750 */    54,   83,   35,   86,   86,   86,   39,   86,   41,   42,
 /*   760 */    37,   44,   79,   46,   47,   48,   83,   26,   86,   52,
 /*   770 */    53,   27,   28,   86,   86,   31,   26,   54,   37,   35,
 /*   780 */    86,   86,   79,   39,   40,   41,   83,   37,   44,   79,
 /*   790 */    46,   47,   48,   83,   86,   54,   52,   53,   27,   28,
 /*   800 */    86,   86,   31,   26,   54,   34,   35,   86,   86,   79,
 /*   810 */    39,   86,   41,   83,   37,   44,   79,   46,   47,   48,
 /*   820 */    83,   86,   86,   52,   53,   27,   28,   86,   86,   31,
 /*   830 */    26,   54,   34,   35,   86,   86,   79,   39,   86,   41,
 /*   840 */    83,   37,   44,   79,   46,   47,   48,   83,   86,   86,
 /*   850 */    52,   53,   27,   28,   86,   86,   31,   79,   54,   34,
 /*   860 */    35,   83,   86,   79,   39,   86,   41,   83,    3,   44,
 /*   870 */    79,   46,   47,   48,   83,   86,   86,   52,   53,   27,
 /*   880 */    28,   86,   86,   31,   86,   86,   21,   35,   23,   24,
 /*   890 */    79,   39,   86,   41,   83,   86,   44,   32,   46,   47,
 /*   900 */    48,   86,   86,   79,   52,   53,   86,   83,   43,   79,
 /*   910 */    45,    2,    3,   83,   49,   86,   51,   79,   86,   86,
 /*   920 */    55,   83,   79,   58,   59,   79,   83,   79,   86,   83,
 /*   930 */    21,   83,   23,   24,   17,   18,   19,   20,   21,   22,
 /*   940 */    23,   32,   25,   79,   86,    3,   86,   83,   86,   86,
 /*   950 */    86,   86,   43,   86,   45,   86,   86,   86,   49,   86,
 /*   960 */    51,   86,   86,   21,   86,   23,   24,   58,   59,   86,
 /*   970 */    86,   86,   86,   86,   32,   86,   86,   86,   86,   86,
 /*   980 */    86,   86,   86,   86,   86,   43,   86,   45,   86,    3,
 /*   990 */    86,   49,   86,   51,   86,   86,   86,   86,   56,   86,
 /*  1000 */    58,   59,   86,   86,   86,   86,   86,   21,   86,   23,
 /*  1010 */    24,   86,   86,   86,   86,   86,   86,   86,   32,   86,
 /*  1020 */    86,   86,    3,   86,   86,   86,   86,   86,   86,   43,
 /*  1030 */    86,   45,   86,   86,   86,   49,   86,   51,   86,   86,
 /*  1040 */    21,   55,   23,   24,   58,   59,   86,   86,   86,   86,
 /*  1050 */    86,   32,   86,   86,   86,    3,   86,   86,   86,   86,
 /*  1060 */    86,   86,   43,   86,   45,   86,   86,   86,   49,   86,
 /*  1070 */    51,   86,   86,   21,   86,   23,   24,   58,   59,   86,
 /*  1080 */    86,   86,   86,   86,   32,   86,   86,   86,    3,   86,
 /*  1090 */    86,   86,   86,   86,   86,   43,   86,   45,   86,   86,
 /*  1100 */    86,   49,   86,   51,   86,   86,   21,   86,   23,   24,
 /*  1110 */    58,   59,   86,   86,   86,   86,   86,   32,   86,   86,
 /*  1120 */    86,   86,   86,   86,   86,   86,   86,   86,   43,   86,
 /*  1130 */    45,   86,   86,   86,   49,   86,   51,   86,   86,   86,
 /*  1140 */    86,   86,   86,   58,   59,
};
#define KK_SHIFT_USE_DFLT (-4)
static short kk_shift_ofst[] = {
 /*     0 */   551,   76,  585,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,  852, 1019,
 /*    20 */    49,  551,  552,  528,   21,   -4,   71,  551,  561,  555,
 /*    30 */    73,   -4,   93,  240, 1019,   -3,  551,  588,  582,  120,
 /*    40 */    -4,  122,  121, 1019,   75,   -4, 1019, 1019,   -2, 1019,
 /*    50 */    -2, 1019,  130, 1019,  130, 1019,  130, 1019,  338, 1019,
 /*    60 */   338, 1019,   -2, 1019,  917, 1019,  319, 1019,  217,  865,
 /*    70 */   217, 1019,  217, 1019,  217, 1019,  217, 1019,  217, 1019,
 /*    80 */   217, 1019,  217, 1019,  217, 1019,   -4,  909,  101,   -4,
 /*    90 */   942,  298, 1019,  131, 1019,  124,   -4, 1052,  298,  617,
 /*   100 */    -4, 1052,   -4,  175, 1019,  298,   -4,   -4,   -4,   -4,
 /*   110 */    -4,   -4,   -4,   -4,   -4,   46,   -4, 1085,   -4,  203,
 /*   120 */  1019,  298,   -4,   -4,  530,  150,   -4,  151,  174,  268,
 /*   130 */   536,   -4,  239,   -4,  296,  297,  986,   -4,   -4,   -2,
 /*   140 */    -4,  290,  315,  615,  642,  609,  334,   -4,  529,  644,
 /*   150 */   551,  669,  636,  542,   -4,  526,  584,   -4,  547,  591,
 /*   160 */    -4, 1019,  181,   -4,   24,  604,  551,  696,  663,  605,
 /*   170 */    -4,  610,   -4,  623,   -4, 1019,  207,   -4,   -4,   -4,
 /*   180 */   631,  551,  723,  690,  632,   -4,  637,  551,  741,  717,
 /*   190 */   645,   -4,  744,  648,   -4, 1019,  246,  551,  750,  771,
 /*   200 */   658,   -4,  613,  659, 1019,   23,  551,  777,  798,  671,
 /*   210 */    -4, 1019,  272,  551,  804,  825,  672,   -4,
};
#define KK_REDUCE_USE_DFLT (-1)
static short kk_reduce_ofst[] = {
 /*     0 */    98,   -1,  476,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*    10 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  164,
 /*    20 */    -1,  301,  476,   -1,   -1,   -1,   -1,  317,  476,   -1,
 /*    30 */    -1,   -1,   -1,   -1,  521,   -1,  333,  476,   -1,   -1,
 /*    40 */    -1,   -1,   -1,  541,   -1,   -1,  548,  575,   -1,  587,
 /*    50 */    -1,  602,   -1,  614,   -1,  622,   -1,  629,   -1,  641,
 /*    60 */    -1,  647,   -1,  649,   -1,  656,   -1,  668,   -1,  683,
 /*    70 */    -1,  703,   -1,  710,   -1,  730,   -1,  737,   -1,  757,
 /*    80 */    -1,  764,   -1,  778,   -1,  784,   -1,  165,   -1,   -1,
 /*    90 */   481,   -1,  791,   -1,  811,   -1,   -1,   99,   -1,   -1,
 /*   100 */    -1,  564,   -1,   -1,  824,   -1,   -1,   -1,   -1,   -1,
 /*   110 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,  512,   -1,   -1,
 /*   120 */   830,   -1,   -1,   -1,  102,   -1,   -1,   -1,   -1,   -1,
 /*   130 */   191,   -1,   -1,   -1,   -1,   -1,  791,   -1,   -1,   -1,
 /*   140 */    -1,   -1,   -1,  349,  476,   -1,   -1,   -1,   -1,   -1,
 /*   150 */   365,  476,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   160 */    -1,  838,   -1,   -1,   -1,   -1,  381,  476,   -1,   -1,
 /*   170 */    -1,   -1,   -1,   -1,   -1,  843,   -1,   -1,   -1,   -1,
 /*   180 */    -1,  397,  476,   -1,   -1,   -1,   -1,  413,  476,   -1,
 /*   190 */    -1,   -1,   -1,   -1,   -1,  846,   -1,  429,  476,   -1,
 /*   200 */    -1,   -1,   -1,   -1,  848,   -1,  445,  476,   -1,   -1,
 /*   210 */    -1,  864,   -1,  461,  476,   -1,   -1,   -1,
};
static KKACTIONTYPE kk_default[] = {
 /*     0 */   307,  307,  307,  220,  222,  223,  224,  225,  226,  227,
 /*    10 */   228,  229,  230,  231,  232,  233,  234,  235,  307,  307,
 /*    20 */   307,  307,  307,  307,  307,  236,  307,  307,  307,  307,
 /*    30 */   307,  237,  307,  307,  307,  307,  307,  307,  307,  307,
 /*    40 */   238,  307,  307,  307,  307,  242,  307,  307,  257,  307,
 /*    50 */   259,  307,  260,  307,  261,  307,  262,  307,  263,  307,
 /*    60 */   264,  307,  265,  307,  266,  307,  267,  307,  268,  307,
 /*    70 */   271,  307,  272,  307,  273,  307,  274,  307,  275,  307,
 /*    80 */   276,  307,  277,  307,  278,  307,  279,  307,  307,  283,
 /*    90 */   307,  298,  307,  280,  307,  307,  281,  307,  292,  307,
 /*   100 */   282,  307,  289,  302,  307,  291,  293,  300,  301,  302,
 /*   110 */   303,  304,  305,  306,  290,  307,  294,  307,  296,  302,
 /*   120 */   307,  299,  295,  297,  307,  307,  284,  307,  307,  307,
 /*   130 */   307,  285,  307,  286,  301,  300,  307,  269,  270,  258,
 /*   140 */   243,  307,  307,  307,  307,  307,  307,  245,  307,  307,
 /*   150 */   307,  307,  307,  307,  247,  307,  307,  249,  307,  307,
 /*   160 */   250,  307,  307,  251,  307,  307,  307,  307,  307,  307,
 /*   170 */   252,  307,  254,  307,  255,  307,  307,  244,  256,  221,
 /*   180 */   307,  307,  307,  307,  307,  253,  307,  307,  307,  307,
 /*   190 */   307,  248,  307,  307,  246,  307,  307,  307,  307,  307,
 /*   200 */   307,  239,  307,  307,  307,  307,  307,  307,  307,  307,
 /*   210 */   240,  307,  307,  307,  307,  307,  307,  241,
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
  "$",             "COMMA",         "DOUBLECOLON",   "SBRACKET_OPEN",
  "RANGE",         "AND",           "OR",            "IS",          
  "EQUALS",        "NOTEQUALS",     "LESS",          "GREATER",     
  "GREATEREQUAL",  "LESSEQUAL",     "IDENTICAL",     "NOTIDENTICAL",
  "PIPE",          "DIVIDE",        "TIMES",         "MOD",         
  "PLUS",          "MINUS",         "CONCAT",        "BRACKET_OPEN",
  "NOT",           "DOT",           "OPEN_DELIMITER",  "IF",          
  "CLOSE_DELIMITER",  "ENDIF",         "ELSE",          "FOR",         
  "IDENTIFIER",    "IN",            "ENDFOR",        "SET",         
  "ASSIGN",        "OPEN_EDELIMITER",  "CLOSE_EDELIMITER",  "BLOCK",       
  "ENDBLOCK",      "CACHE",         "ENDCACHE",      "INTEGER",     
  "EXTENDS",       "STRING",        "INCLUDE",       "DO",          
  "AUTOESCAPE",    "FALSE",         "ENDAUTOESCAPE",  "TRUE",        
  "BREAK",         "CONTINUE",      "RAW_FRAGMENT",  "DEFINED",     
  "BRACKET_CLOSE",  "SBRACKET_CLOSE",  "DOUBLE",        "NULL",        
  "error",         "program",       "volt_language",  "statement_list",
  "statement",     "raw_fragment",  "if_statement",  "for_statement",
  "set_statement",  "echo_statement",  "block_statement",  "cache_statement",
  "extends_statement",  "include_statement",  "do_statement",  "autoescape_statement",
  "break_statement",  "continue_statement",  "empty_statement",  "expr",        
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
 /*  20 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  21 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  22 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  23 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  24 */ "set_statement ::= OPEN_DELIMITER SET IDENTIFIER ASSIGN expr CLOSE_DELIMITER",
 /*  25 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  26 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  27 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  28 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  29 */ "cache_statement ::= OPEN_DELIMITER CACHE IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  30 */ "cache_statement ::= OPEN_DELIMITER CACHE IDENTIFIER INTEGER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  31 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  32 */ "include_statement ::= OPEN_DELIMITER INCLUDE STRING CLOSE_DELIMITER",
 /*  33 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  34 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE FALSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  35 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE TRUE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  36 */ "break_statement ::= OPEN_DELIMITER BREAK CLOSE_DELIMITER",
 /*  37 */ "continue_statement ::= OPEN_DELIMITER CONTINUE CLOSE_DELIMITER",
 /*  38 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  39 */ "expr ::= MINUS expr",
 /*  40 */ "expr ::= expr MINUS expr",
 /*  41 */ "expr ::= expr PLUS expr",
 /*  42 */ "expr ::= expr TIMES expr",
 /*  43 */ "expr ::= expr DIVIDE expr",
 /*  44 */ "expr ::= expr MOD expr",
 /*  45 */ "expr ::= expr AND expr",
 /*  46 */ "expr ::= expr OR expr",
 /*  47 */ "expr ::= expr CONCAT expr",
 /*  48 */ "expr ::= expr PIPE expr",
 /*  49 */ "expr ::= expr RANGE expr",
 /*  50 */ "expr ::= expr EQUALS expr",
 /*  51 */ "expr ::= expr IS NOT DEFINED",
 /*  52 */ "expr ::= expr IS DEFINED",
 /*  53 */ "expr ::= expr IS expr",
 /*  54 */ "expr ::= expr NOTEQUALS expr",
 /*  55 */ "expr ::= expr IDENTICAL expr",
 /*  56 */ "expr ::= expr NOTIDENTICAL expr",
 /*  57 */ "expr ::= expr LESS expr",
 /*  58 */ "expr ::= expr GREATER expr",
 /*  59 */ "expr ::= expr GREATEREQUAL expr",
 /*  60 */ "expr ::= expr LESSEQUAL expr",
 /*  61 */ "expr ::= expr DOT expr",
 /*  62 */ "expr ::= NOT expr",
 /*  63 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /*  64 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /*  65 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /*  66 */ "expr ::= expr SBRACKET_OPEN DOUBLECOLON slice_offset SBRACKET_CLOSE",
 /*  67 */ "expr ::= expr SBRACKET_OPEN slice_offset DOUBLECOLON SBRACKET_CLOSE",
 /*  68 */ "expr ::= expr SBRACKET_OPEN slice_offset DOUBLECOLON slice_offset SBRACKET_CLOSE",
 /*  69 */ "slice_offset ::= INTEGER",
 /*  70 */ "slice_offset ::= IDENTIFIER",
 /*  71 */ "array_list ::= array_list COMMA array_item",
 /*  72 */ "array_list ::= array_item",
 /*  73 */ "array_item ::= STRING DOUBLECOLON expr",
 /*  74 */ "array_item ::= expr",
 /*  75 */ "expr ::= function_call",
 /*  76 */ "function_call ::= expr BRACKET_OPEN argument_list BRACKET_CLOSE",
 /*  77 */ "function_call ::= expr BRACKET_OPEN BRACKET_CLOSE",
 /*  78 */ "argument_list ::= argument_list COMMA argument_item",
 /*  79 */ "argument_list ::= argument_item",
 /*  80 */ "argument_item ::= expr",
 /*  81 */ "argument_item ::= STRING DOUBLECOLON expr",
 /*  82 */ "expr ::= IDENTIFIER",
 /*  83 */ "expr ::= INTEGER",
 /*  84 */ "expr ::= STRING",
 /*  85 */ "expr ::= DOUBLE",
 /*  86 */ "expr ::= NULL",
 /*  87 */ "expr ::= FALSE",
 /*  88 */ "expr ::= TRUE",
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
// 502 "parser.lemon"
{
	if ((kkpminor->kk0)) {
		if ((kkpminor->kk0)->free_flag) {
			efree((kkpminor->kk0)->token);
		}
		efree((kkpminor->kk0));
	}
}
// 1178 "parser.c"
      break;
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
    case 85:
// 519 "parser.lemon"
{ zval_ptr_dtor(&(kkpminor->kk128)); }
// 1205 "parser.c"
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
  { 61, 1 },
  { 62, 1 },
  { 63, 2 },
  { 63, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 66, 8 },
  { 66, 12 },
  { 67, 10 },
  { 67, 12 },
  { 67, 12 },
  { 67, 14 },
  { 68, 6 },
  { 78, 2 },
  { 69, 3 },
  { 70, 8 },
  { 70, 7 },
  { 71, 8 },
  { 71, 9 },
  { 72, 4 },
  { 73, 4 },
  { 74, 4 },
  { 75, 8 },
  { 75, 8 },
  { 76, 3 },
  { 77, 3 },
  { 65, 1 },
  { 79, 2 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 4 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 3 },
  { 79, 2 },
  { 79, 3 },
  { 79, 3 },
  { 79, 4 },
  { 79, 5 },
  { 79, 5 },
  { 79, 6 },
  { 81, 1 },
  { 81, 1 },
  { 80, 3 },
  { 80, 1 },
  { 82, 3 },
  { 82, 1 },
  { 79, 1 },
  { 83, 4 },
  { 83, 3 },
  { 84, 3 },
  { 84, 1 },
  { 85, 1 },
  { 85, 3 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
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
// 511 "parser.lemon"
{
	status->ret = kkmsp[0].minor.kk128;
}
// 1511 "parser.c"
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
      case 75:
// 515 "parser.lemon"
{
	kkgotominor.kk128 = kkmsp[0].minor.kk128;
}
// 1533 "parser.c"
        break;
      case 2:
// 521 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_zval_list(kkmsp[-1].minor.kk128, kkmsp[0].minor.kk128);
}
// 1540 "parser.c"
        break;
      case 3:
      case 72:
      case 79:
// 525 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_zval_list(NULL, kkmsp[0].minor.kk128);
}
// 1549 "parser.c"
        break;
      case 18:
// 589 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_if_statement(kkmsp[-5].minor.kk128, kkmsp[-3].minor.kk128, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(27,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(29,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1562 "parser.c"
        break;
      case 19:
// 593 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_if_statement(kkmsp[-9].minor.kk128, kkmsp[-7].minor.kk128, kkmsp[-3].minor.kk128, status->scanner_state);
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
// 1578 "parser.c"
        break;
      case 20:
// 599 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-5].minor.kk128, NULL, kkmsp[-3].minor.kk128, status->scanner_state);
  kk_destructor(26,&kkmsp[-9].minor);
  kk_destructor(31,&kkmsp[-8].minor);
  kk_destructor(33,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(34,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1592 "parser.c"
        break;
      case 21:
// 603 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, NULL, kkmsp[-7].minor.kk128, kkmsp[-5].minor.kk128, kkmsp[-3].minor.kk128, status->scanner_state);
  kk_destructor(26,&kkmsp[-11].minor);
  kk_destructor(31,&kkmsp[-10].minor);
  kk_destructor(33,&kkmsp[-8].minor);
  kk_destructor(27,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(34,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1607 "parser.c"
        break;
      case 22:
// 607 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, kkmsp[-9].minor.kk0, kkmsp[-5].minor.kk128, NULL, kkmsp[-3].minor.kk128, status->scanner_state);
  kk_destructor(26,&kkmsp[-11].minor);
  kk_destructor(31,&kkmsp[-10].minor);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(33,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(34,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1622 "parser.c"
        break;
      case 23:
// 611 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, kkmsp[-11].minor.kk0, kkmsp[-7].minor.kk128, kkmsp[-5].minor.kk128, kkmsp[-3].minor.kk128, status->scanner_state);
  kk_destructor(26,&kkmsp[-13].minor);
  kk_destructor(31,&kkmsp[-12].minor);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(33,&kkmsp[-8].minor);
  kk_destructor(27,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(34,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1638 "parser.c"
        break;
      case 24:
// 617 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_set_statement(kkmsp[-3].minor.kk0, kkmsp[-1].minor.kk128, status->scanner_state);
  kk_destructor(26,&kkmsp[-5].minor);
  kk_destructor(35,&kkmsp[-4].minor);
  kk_destructor(36,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1649 "parser.c"
        break;
      case 25:
// 623 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_empty_statement(status->scanner_state);
  kk_destructor(26,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1658 "parser.c"
        break;
      case 26:
// 629 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_echo_statement(kkmsp[-1].minor.kk128, status->scanner_state);
  kk_destructor(37,&kkmsp[-2].minor);
  kk_destructor(38,&kkmsp[0].minor);
}
// 1667 "parser.c"
        break;
      case 27:
// 635 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_block_statement(kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk128, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(39,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(40,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1680 "parser.c"
        break;
      case 28:
// 639 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_block_statement(kkmsp[-4].minor.kk0, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-6].minor);
  kk_destructor(39,&kkmsp[-5].minor);
  kk_destructor(28,&kkmsp[-3].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(40,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1693 "parser.c"
        break;
      case 29:
// 645 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_cache_statement(kkmsp[-5].minor.kk0, NULL, kkmsp[-3].minor.kk128, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(41,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(42,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1706 "parser.c"
        break;
      case 30:
// 649 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_cache_statement(kkmsp[-6].minor.kk0, kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk128, status->scanner_state);
  kk_destructor(26,&kkmsp[-8].minor);
  kk_destructor(41,&kkmsp[-7].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(42,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1719 "parser.c"
        break;
      case 31:
// 655 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_extends_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(26,&kkmsp[-3].minor);
  kk_destructor(44,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1729 "parser.c"
        break;
      case 32:
// 661 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_include_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(26,&kkmsp[-3].minor);
  kk_destructor(46,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1739 "parser.c"
        break;
      case 33:
// 667 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_do_statement(kkmsp[-1].minor.kk128, status->scanner_state);
  kk_destructor(26,&kkmsp[-3].minor);
  kk_destructor(47,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1749 "parser.c"
        break;
      case 34:
// 673 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_autoescape_statement(0, kkmsp[-3].minor.kk128, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(48,&kkmsp[-6].minor);
  kk_destructor(49,&kkmsp[-5].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(50,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1763 "parser.c"
        break;
      case 35:
// 677 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_autoescape_statement(1, kkmsp[-3].minor.kk128, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(48,&kkmsp[-6].minor);
  kk_destructor(51,&kkmsp[-5].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(50,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1777 "parser.c"
        break;
      case 36:
// 683 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_break_statement(status->scanner_state);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(52,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1787 "parser.c"
        break;
      case 37:
// 689 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_continue_statement(status->scanner_state);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(53,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1797 "parser.c"
        break;
      case 38:
// 695 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, kkmsp[0].minor.kk0, status->scanner_state);
}
// 1804 "parser.c"
        break;
      case 39:
// 701 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
// 1812 "parser.c"
        break;
      case 40:
// 705 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_SUB, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
// 1820 "parser.c"
        break;
      case 41:
// 709 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_ADD, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 1828 "parser.c"
        break;
      case 42:
// 713 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_MUL, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(18,&kkmsp[-1].minor);
}
// 1836 "parser.c"
        break;
      case 43:
// 717 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_DIV, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(17,&kkmsp[-1].minor);
}
// 1844 "parser.c"
        break;
      case 44:
// 721 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 1852 "parser.c"
        break;
      case 45:
// 725 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_AND, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 1860 "parser.c"
        break;
      case 46:
// 729 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_OR, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(6,&kkmsp[-1].minor);
}
// 1868 "parser.c"
        break;
      case 47:
// 733 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_CONCAT, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 1876 "parser.c"
        break;
      case 48:
// 737 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_PIPE, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(16,&kkmsp[-1].minor);
}
// 1884 "parser.c"
        break;
      case 49:
// 741 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_RANGE, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(4,&kkmsp[-1].minor);
}
// 1892 "parser.c"
        break;
      case 50:
// 745 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_EQUALS, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(8,&kkmsp[-1].minor);
}
// 1900 "parser.c"
        break;
      case 51:
// 749 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, kkmsp[-3].minor.kk128, NULL, status->scanner_state);
  kk_destructor(7,&kkmsp[-2].minor);
  kk_destructor(24,&kkmsp[-1].minor);
  kk_destructor(55,&kkmsp[0].minor);
}
// 1910 "parser.c"
        break;
      case 52:
// 753 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_ISSET, kkmsp[-2].minor.kk128, NULL, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
  kk_destructor(55,&kkmsp[0].minor);
}
// 1919 "parser.c"
        break;
      case 53:
// 757 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_IS, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
}
// 1927 "parser.c"
        break;
      case 54:
// 761 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
}
// 1935 "parser.c"
        break;
      case 55:
// 765 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(14,&kkmsp[-1].minor);
}
// 1943 "parser.c"
        break;
      case 56:
// 769 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(15,&kkmsp[-1].minor);
}
// 1951 "parser.c"
        break;
      case 57:
// 773 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_LESS, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
}
// 1959 "parser.c"
        break;
      case 58:
// 777 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_GREATER, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(11,&kkmsp[-1].minor);
}
// 1967 "parser.c"
        break;
      case 59:
// 781 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(12,&kkmsp[-1].minor);
}
// 1975 "parser.c"
        break;
      case 60:
// 785 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(13,&kkmsp[-1].minor);
}
// 1983 "parser.c"
        break;
      case 61:
// 789 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_DOT, kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(25,&kkmsp[-1].minor);
}
// 1991 "parser.c"
        break;
      case 62:
// 793 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(24,&kkmsp[-1].minor);
}
// 1999 "parser.c"
        break;
      case 63:
// 797 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, kkmsp[-1].minor.kk128, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(56,&kkmsp[0].minor);
}
// 2008 "parser.c"
        break;
      case 64:
// 801 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk128, NULL, status->scanner_state);
  kk_destructor(3,&kkmsp[-2].minor);
  kk_destructor(57,&kkmsp[0].minor);
}
// 2017 "parser.c"
        break;
      case 65:
// 805 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, kkmsp[-3].minor.kk128, kkmsp[-1].minor.kk128, status->scanner_state);
  kk_destructor(3,&kkmsp[-2].minor);
  kk_destructor(57,&kkmsp[0].minor);
}
// 2026 "parser.c"
        break;
      case 66:
// 809 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_slice(kkmsp[-4].minor.kk128, NULL, kkmsp[-1].minor.kk128, status->scanner_state);
  kk_destructor(3,&kkmsp[-3].minor);
  kk_destructor(2,&kkmsp[-2].minor);
  kk_destructor(57,&kkmsp[0].minor);
}
// 2036 "parser.c"
        break;
      case 67:
// 813 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_slice(kkmsp[-4].minor.kk128, kkmsp[-2].minor.kk128, NULL, status->scanner_state);
  kk_destructor(3,&kkmsp[-3].minor);
  kk_destructor(2,&kkmsp[-1].minor);
  kk_destructor(57,&kkmsp[0].minor);
}
// 2046 "parser.c"
        break;
      case 68:
// 817 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_slice(kkmsp[-5].minor.kk128, kkmsp[-3].minor.kk128, kkmsp[-1].minor.kk128, status->scanner_state);
  kk_destructor(3,&kkmsp[-4].minor);
  kk_destructor(2,&kkmsp[-2].minor);
  kk_destructor(57,&kkmsp[0].minor);
}
// 2056 "parser.c"
        break;
      case 69:
      case 83:
// 823 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2064 "parser.c"
        break;
      case 70:
      case 82:
// 827 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2072 "parser.c"
        break;
      case 71:
      case 78:
// 833 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_zval_list(kkmsp[-2].minor.kk128, kkmsp[0].minor.kk128);
  kk_destructor(1,&kkmsp[-1].minor);
}
// 2081 "parser.c"
        break;
      case 73:
      case 81:
// 843 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_named_item(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk128, status->scanner_state);
  kk_destructor(2,&kkmsp[-1].minor);
}
// 2090 "parser.c"
        break;
      case 74:
      case 80:
// 847 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_named_item(NULL, kkmsp[0].minor.kk128, status->scanner_state);
}
// 2098 "parser.c"
        break;
      case 76:
// 857 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_func_call(kkmsp[-3].minor.kk128, kkmsp[-1].minor.kk128, status->scanner_state);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(56,&kkmsp[0].minor);
}
// 2107 "parser.c"
        break;
      case 77:
// 861 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_func_call(kkmsp[-2].minor.kk128, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
  kk_destructor(56,&kkmsp[0].minor);
}
// 2116 "parser.c"
        break;
      case 84:
// 893 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_literal_zval(PHVOLT_T_STRING, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2123 "parser.c"
        break;
      case 85:
// 897 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2130 "parser.c"
        break;
      case 86:
// 901 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  kk_destructor(59,&kkmsp[0].minor);
}
// 2138 "parser.c"
        break;
      case 87:
// 905 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  kk_destructor(49,&kkmsp[0].minor);
}
// 2146 "parser.c"
        break;
      case 88:
// 909 "parser.lemon"
{
	kkgotominor.kk128 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  kk_destructor(51,&kkmsp[0].minor);
}
// 2154 "parser.c"
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
// 456 "parser.lemon"

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

// 2242 "parser.c"
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
  { PHVOLT_T_DOUBLECOLON,       "DOUBLECOLON" },
  { PHVOLT_T_LESS,          	"<" },
  { PHVOLT_T_LESSEQUAL,     	"<=" },
  { PHVOLT_T_GREATER,       	">" },
  { PHVOLT_T_GREATEREQUAL,  	">=" },
  { PHVOLT_T_BRACKET_OPEN,  	"(" },
  { PHVOLT_T_BRACKET_CLOSE, 	")" },
  { PHVOLT_T_OPEN_DELIMITER, 	"{%" },
  { PHVOLT_T_CLOSE_DELIMITER, 	"%}" },
  { PHVOLT_T_OPEN_EDELIMITER, 	"{{" },
  { PHVOLT_T_CLOSE_EDELIMITER, 	"}}" },
  { PHVOLT_T_IF,           		"IF" },
  { PHVOLT_T_ELSE,           	"ELSE" },
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