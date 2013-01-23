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


// 441 "parser.c"
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
#define KKNOCODE 89
#define KKACTIONTYPE unsigned short int
#define phvolt_KTOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_KTOKENTYPE kk0;
  zval* kk24;
  int kk177;
} KKMINORTYPE;
#define KKSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = kkpParser->status
#define phvolt_ARG_STORE kkpParser->status = status
#define KKNSTATE 222
#define KKNRULE 91
#define KKERRORSYMBOL 61
#define KKERRSYMDT kk177
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
 /*     0 */    77,   55,   47,   49,   59,   57,   61,   67,   69,   71,
 /*    10 */    73,   63,   65,   43,   41,   45,   39,   36,   51,   53,
 /*    20 */    80,   80,   75,   75,  199,  134,   77,   55,   47,   49,
 /*    30 */    59,   57,   61,   67,   69,   71,   73,   63,   65,   43,
 /*    40 */    41,   45,   39,   36,   51,   53,   80,  222,   75,  118,
 /*    50 */    26,  154,   43,   41,   45,   39,   36,   51,   53,   80,
 /*    60 */   117,   75,   39,   36,   51,   53,   80,  190,   75,   28,
 /*    70 */    75,   77,   55,   47,   49,   59,   57,   61,   67,   69,
 /*    80 */    71,   73,   63,   65,   43,   41,   45,   39,   36,   51,
 /*    90 */    53,   80,  169,   75,  184,  215,  210,   77,   55,   47,
 /*   100 */    49,   59,   57,   61,   67,   69,   71,   73,   63,   65,
 /*   110 */    43,   41,   45,   39,   36,   51,   53,   80,   32,   75,
 /*   120 */    94,  110,   22,   77,   55,   47,   49,   59,   57,   61,
 /*   130 */    67,   69,   71,   73,   63,   65,   43,   41,   45,   39,
 /*   140 */    36,   51,   53,   80,  115,   75,  116,  293,   35,   77,
 /*   150 */    55,   47,   49,   59,   57,   61,   67,   69,   71,   73,
 /*   160 */    63,   65,   43,   41,   45,   39,   36,   51,   53,   80,
 /*   170 */   120,   75,   77,   55,   47,   49,   59,   57,   61,   67,
 /*   180 */    69,   71,   73,   63,   65,   43,   41,   45,   39,   36,
 /*   190 */    51,   53,   80,   81,   75,  107,   91,   96,  105,  113,
 /*   200 */    53,   80,  293,   75,   79,  314,    1,    2,  183,    4,
 /*   210 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   220 */    15,   16,   17,   18,  294,   78,   86,  119,  122,   96,
 /*   230 */    77,   55,   47,   49,   59,   57,   61,   67,   69,   71,
 /*   240 */    73,   63,   65,   43,   41,   45,   39,   36,   51,   53,
 /*   250 */    80,  106,   75,   90,  123,  143,   77,   55,   47,   49,
 /*   260 */    59,   57,   61,   67,   69,   71,   73,   63,   65,   43,
 /*   270 */    41,   45,   39,   36,   51,   53,   80,  294,   75,  131,
 /*   280 */   138,  167,   77,   55,   47,   49,   59,   57,   61,   67,
 /*   290 */    69,   71,   73,   63,   65,   43,   41,   45,   39,   36,
 /*   300 */    51,   53,   80,  140,   75,   88,   89,   88,  104,   96,
 /*   310 */    92,   96,   21,   81,  141,  146,   96,   96,  181,  108,
 /*   320 */   147,  151,   77,   55,   47,   49,   59,   57,   61,   67,
 /*   330 */    69,   71,   73,   63,   65,   43,   41,   45,   39,   36,
 /*   340 */    51,   53,   80,  158,   75,  160,  161,  201,   77,   55,
 /*   350 */    47,   49,   59,   57,   61,   67,   69,   71,   73,   63,
 /*   360 */    65,   43,   41,   45,   39,   36,   51,   53,   80,  163,
 /*   370 */    75,  164,  170,  217,   77,   55,   47,   49,   59,   57,
 /*   380 */    61,   67,   69,   71,   73,   63,   65,   43,   41,   45,
 /*   390 */    39,   36,   51,   53,   80,  174,   75,   47,   49,   59,
 /*   400 */    57,   61,   67,   69,   71,   73,   63,   65,   43,   41,
 /*   410 */    45,   39,   36,   51,   53,   80,  176,   75,   59,   57,
 /*   420 */    61,   67,   69,   71,   73,   63,   65,   43,   41,   45,
 /*   430 */    39,   36,   51,   53,   80,  178,   75,  185,   23,  183,
 /*   440 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   450 */    14,   15,   16,   17,   18,   29,  183,    4,    5,    6,
 /*   460 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   470 */    17,   18,  135,  183,    4,    5,    6,    7,    8,    9,
 /*   480 */    10,   11,   12,   13,   14,   15,   16,   17,   18,  148,
 /*   490 */   183,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   500 */    13,   14,   15,   16,   17,   18,  155,  183,    4,    5,
 /*   510 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   520 */    16,   17,   18,  171,  183,    4,    5,    6,    7,    8,
 /*   530 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   540 */   186,  183,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   550 */    12,   13,   14,   15,   16,   17,   18,  192,  183,    4,
 /*   560 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   570 */    15,   16,   17,   18,  202,  183,    4,    5,    6,    7,
 /*   580 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   590 */    18,  211,  183,    4,    5,    6,    7,    8,    9,   10,
 /*   600 */    11,   12,   13,   14,   15,   16,   17,   18,  218,  183,
 /*   610 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   620 */    14,   15,   16,   17,   18,    3,    4,    5,    6,    7,
 /*   630 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   640 */    18,   20,  144,   25,   27,   33,  130,   34,   19,  129,
 /*   650 */   139,   96,   24,   96,  145,  189,  152,  191,  195,  159,
 /*   660 */   179,  162,  165,  168,  179,  198,  205,  175,  177,   20,
 /*   670 */   144,   31,   38,   33,  130,   40,   96,  182,  139,   96,
 /*   680 */   207,  182,  145,  208,  152,  214,  221,  159,  118,  162,
 /*   690 */   165,  168,  181,  181,  181,  175,  177,   20,  144,  117,
 /*   700 */   181,   33,  130,  181,   30,  137,  139,  181,  136,  181,
 /*   710 */   145,  181,  152,  121,  181,  159,  179,  162,  165,  168,
 /*   720 */   179,  181,  181,  175,  177,   20,  144,   42,  181,   33,
 /*   730 */   130,   96,  196,  182,  139,  181,  181,  182,  145,  150,
 /*   740 */   152,  181,  181,  159,  179,  162,  165,  168,  181,  181,
 /*   750 */   181,  175,  177,   20,  144,   44,  181,   33,  130,   96,
 /*   760 */   149,  182,  139,  181,  156,  181,  145,  181,  152,  157,
 /*   770 */   181,  159,  179,  162,  165,  168,  179,  181,  181,  175,
 /*   780 */   177,   20,  144,   46,  181,   33,  130,   96,  172,  182,
 /*   790 */   139,  181,  181,  182,  145,  181,  152,  181,  181,  159,
 /*   800 */   179,  162,  165,  168,  181,  173,  181,  175,  177,   20,
 /*   810 */   144,   48,  181,   33,  130,   96,  187,  182,  139,  181,
 /*   820 */   193,   50,  145,  181,  152,   96,  181,  159,  179,  162,
 /*   830 */   165,  168,  179,  188,  181,  175,  177,   20,  144,   52,
 /*   840 */   181,   33,  130,   96,  203,  182,  139,  181,  181,  182,
 /*   850 */   145,  181,  152,  194,  181,  159,  179,  162,  165,  168,
 /*   860 */   181,   20,  144,  175,  177,   33,  130,   54,  212,  206,
 /*   870 */   139,   96,  219,  182,  145,  197,  152,  181,  181,  159,
 /*   880 */   179,  162,  165,  168,  179,   20,  144,  175,  177,   33,
 /*   890 */   130,  181,   56,  204,  139,   58,   96,  182,  145,   96,
 /*   900 */   152,  182,  132,  159,   60,  162,  165,  168,   96,   20,
 /*   910 */   144,  175,  177,   33,  130,  181,  181,  213,  139,   62,
 /*   920 */   181,   64,  145,   96,  152,   96,  181,  159,   66,  162,
 /*   930 */   165,  168,   96,   20,  144,  175,  177,   33,  130,  181,
 /*   940 */    68,  220,  139,  223,   96,   70,  145,  181,  152,   96,
 /*   950 */   181,  159,   72,  162,  165,  168,   96,   20,  144,  175,
 /*   960 */   177,   33,  130,  181,   74,   87,  139,   76,   96,   19,
 /*   970 */   145,   96,  152,  181,  181,  159,   83,  162,  165,  168,
 /*   980 */    96,  179,   37,  175,  177,   84,  126,  181,   85,  114,
 /*   990 */    87,  181,   96,   95,  181,   97,  111,   96,  182,  133,
 /*  1000 */    96,  142,  181,   96,  181,   96,   98,   37,   99,  153,
 /*  1010 */    84,   82,  102,   96,  103,   87,  181,  181,  128,  166,
 /*  1020 */   125,  100,  101,   96,  181,  180,  200,  181,  181,   96,
 /*  1030 */    96,  124,   37,   99,  209,   84,   82,  102,   96,  103,
 /*  1040 */    87,  181,  181,  181,  216,   97,  100,  101,   96,  181,
 /*  1050 */   181,  181,  181,  181,  181,  181,   98,   37,  109,  181,
 /*  1060 */    84,   82,  102,  181,  103,   87,  181,  181,  181,  112,
 /*  1070 */    97,  100,  101,  181,  181,  181,  181,  181,  181,  181,
 /*  1080 */   181,   98,   37,   99,  181,   84,   82,  102,  181,  103,
 /*  1090 */    87,  181,  181,  127,  181,   97,  100,  101,  181,  181,
 /*  1100 */   181,  181,  181,  181,  181,  181,   98,   37,   99,  181,
 /*  1110 */    84,   82,  102,  181,  103,   87,  181,  181,  181,  181,
 /*  1120 */    97,  100,  101,  181,  181,  181,  181,  181,  181,  181,
 /*  1130 */   181,   98,   37,   93,  181,   84,   82,  102,  181,  103,
 /*  1140 */   181,  181,  181,  181,  181,   97,  100,  101,  181,  181,
 /*  1150 */   181,  181,  181,  181,  181,  181,   98,  181,  109,  181,
 /*  1160 */   181,  181,  102,  181,  103,  181,  181,  181,  181,  181,
 /*  1170 */   181,  100,  101,
};
static KKCODETYPE kk_lookahead[] = {
 /*     0 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*    10 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    20 */    23,   23,   25,   25,   27,   28,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,   18,   19,   20,   21,   22,   23,    0,   25,   33,
 /*    50 */    28,   28,   16,   17,   18,   19,   20,   21,   22,   23,
 /*    60 */    44,   25,   19,   20,   21,   22,   23,   44,   25,   28,
 /*    70 */    25,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*    80 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*    90 */    22,   23,   50,   25,   52,   27,   28,    3,    4,    5,
 /*   100 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   110 */    16,   17,   18,   19,   20,   21,   22,   23,   28,   25,
 /*   120 */     2,    2,   28,    3,    4,    5,    6,    7,    8,    9,
 /*   130 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   140 */    20,   21,   22,   23,   83,   25,   58,   58,   28,    3,
 /*   150 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   160 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   170 */     2,   25,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   180 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   190 */    21,   22,   23,   81,   25,    1,    1,   85,   86,   87,
 /*   200 */    22,   23,    2,   25,   58,   62,   63,   64,   65,   66,
 /*   210 */    67,   68,   69,   70,   71,   72,   73,   74,   75,   76,
 /*   220 */    77,   78,   79,   80,   58,   81,   57,   83,   83,   85,
 /*   230 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   240 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   250 */    23,   57,   25,   58,   58,   28,    3,    4,    5,    6,
 /*   260 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   270 */    17,   18,   19,   20,   21,   22,   23,    2,   25,   33,
 /*   280 */    28,   28,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   290 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   300 */    21,   22,   23,   33,   25,   81,   82,   81,   84,   85,
 /*   310 */    84,   85,   81,   81,   37,   33,   85,   85,   39,   87,
 /*   320 */    28,   28,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   330 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   340 */    21,   22,   23,   28,   25,   46,   28,   28,    3,    4,
 /*   350 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   360 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   46,
 /*   370 */    25,   28,   28,   28,    3,    4,    5,    6,    7,    8,
 /*   380 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   390 */    19,   20,   21,   22,   23,   28,   25,    5,    6,    7,
 /*   400 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   410 */    18,   19,   20,   21,   22,   23,   28,   25,    7,    8,
 /*   420 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   430 */    19,   20,   21,   22,   23,   28,   25,   28,   64,   65,
 /*   440 */    66,   67,   68,   69,   70,   71,   72,   73,   74,   75,
 /*   450 */    76,   77,   78,   79,   80,   64,   65,   66,   67,   68,
 /*   460 */    69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
 /*   470 */    79,   80,   64,   65,   66,   67,   68,   69,   70,   71,
 /*   480 */    72,   73,   74,   75,   76,   77,   78,   79,   80,   64,
 /*   490 */    65,   66,   67,   68,   69,   70,   71,   72,   73,   74,
 /*   500 */    75,   76,   77,   78,   79,   80,   64,   65,   66,   67,
 /*   510 */    68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
 /*   520 */    78,   79,   80,   64,   65,   66,   67,   68,   69,   70,
 /*   530 */    71,   72,   73,   74,   75,   76,   77,   78,   79,   80,
 /*   540 */    64,   65,   66,   67,   68,   69,   70,   71,   72,   73,
 /*   550 */    74,   75,   76,   77,   78,   79,   80,   64,   65,   66,
 /*   560 */    67,   68,   69,   70,   71,   72,   73,   74,   75,   76,
 /*   570 */    77,   78,   79,   80,   64,   65,   66,   67,   68,   69,
 /*   580 */    70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
 /*   590 */    80,   64,   65,   66,   67,   68,   69,   70,   71,   72,
 /*   600 */    73,   74,   75,   76,   77,   78,   79,   80,   64,   65,
 /*   610 */    66,   67,   68,   69,   70,   71,   72,   73,   74,   75,
 /*   620 */    76,   77,   78,   79,   80,   65,   66,   67,   68,   69,
 /*   630 */    70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
 /*   640 */    80,   27,   28,   29,   30,   31,   32,   81,   26,   81,
 /*   650 */    36,   85,   26,   85,   40,   28,   42,   28,   28,   45,
 /*   660 */    38,   47,   48,   49,   38,   28,   28,   53,   54,   27,
 /*   670 */    28,   29,   81,   31,   32,   81,   85,   55,   36,   85,
 /*   680 */    33,   55,   40,   34,   42,   28,   28,   45,   33,   47,
 /*   690 */    48,   49,   88,   88,   88,   53,   54,   27,   28,   44,
 /*   700 */    88,   31,   32,   88,   26,   35,   36,   88,   26,   88,
 /*   710 */    40,   88,   42,   58,   88,   45,   38,   47,   48,   49,
 /*   720 */    38,   88,   88,   53,   54,   27,   28,   81,   88,   31,
 /*   730 */    32,   85,   26,   55,   36,   88,   88,   55,   40,   41,
 /*   740 */    42,   88,   88,   45,   38,   47,   48,   49,   88,   88,
 /*   750 */    88,   53,   54,   27,   28,   81,   88,   31,   32,   85,
 /*   760 */    26,   55,   36,   88,   26,   88,   40,   88,   42,   43,
 /*   770 */    88,   45,   38,   47,   48,   49,   38,   88,   88,   53,
 /*   780 */    54,   27,   28,   81,   88,   31,   32,   85,   26,   55,
 /*   790 */    36,   88,   88,   55,   40,   88,   42,   88,   88,   45,
 /*   800 */    38,   47,   48,   49,   88,   51,   88,   53,   54,   27,
 /*   810 */    28,   81,   88,   31,   32,   85,   26,   55,   36,   88,
 /*   820 */    26,   81,   40,   88,   42,   85,   88,   45,   38,   47,
 /*   830 */    48,   49,   38,   51,   88,   53,   54,   27,   28,   81,
 /*   840 */    88,   31,   32,   85,   26,   55,   36,   88,   88,   55,
 /*   850 */    40,   88,   42,   43,   88,   45,   38,   47,   48,   49,
 /*   860 */    88,   27,   28,   53,   54,   31,   32,   81,   26,    1,
 /*   870 */    36,   85,   26,   55,   40,   41,   42,   88,   88,   45,
 /*   880 */    38,   47,   48,   49,   38,   27,   28,   53,   54,   31,
 /*   890 */    32,   88,   81,   35,   36,   81,   85,   55,   40,   85,
 /*   900 */    42,   55,   34,   45,   81,   47,   48,   49,   85,   27,
 /*   910 */    28,   53,   54,   31,   32,   88,   88,   35,   36,   81,
 /*   920 */    88,   81,   40,   85,   42,   85,   88,   45,   81,   47,
 /*   930 */    48,   49,   85,   27,   28,   53,   54,   31,   32,   88,
 /*   940 */    81,   35,   36,    0,   85,   81,   40,   88,   42,   85,
 /*   950 */    88,   45,   81,   47,   48,   49,   85,   27,   28,   53,
 /*   960 */    54,   31,   32,   88,   81,    3,   36,   81,   85,   26,
 /*   970 */    40,   85,   42,   88,   88,   45,   81,   47,   48,   49,
 /*   980 */    85,   38,   20,   53,   54,   23,   24,   88,   81,    2,
 /*   990 */     3,   88,   85,   81,   88,   33,   81,   85,   55,   81,
 /*  1000 */    85,   81,   88,   85,   88,   85,   44,   20,   46,   81,
 /*  1010 */    23,   24,   50,   85,   52,    3,   88,   88,   56,   81,
 /*  1020 */    33,   59,   60,   85,   88,   81,   81,   88,   88,   85,
 /*  1030 */    85,   44,   20,   46,   81,   23,   24,   50,   85,   52,
 /*  1040 */     3,   88,   88,   88,   81,   33,   59,   60,   85,   88,
 /*  1050 */    88,   88,   88,   88,   88,   88,   44,   20,   46,   88,
 /*  1060 */    23,   24,   50,   88,   52,    3,   88,   88,   88,   57,
 /*  1070 */    33,   59,   60,   88,   88,   88,   88,   88,   88,   88,
 /*  1080 */    88,   44,   20,   46,   88,   23,   24,   50,   88,   52,
 /*  1090 */     3,   88,   88,   56,   88,   33,   59,   60,   88,   88,
 /*  1100 */    88,   88,   88,   88,   88,   88,   44,   20,   46,   88,
 /*  1110 */    23,   24,   50,   88,   52,    3,   88,   88,   88,   88,
 /*  1120 */    33,   59,   60,   88,   88,   88,   88,   88,   88,   88,
 /*  1130 */    88,   44,   20,   46,   88,   23,   24,   50,   88,   52,
 /*  1140 */    88,   88,   88,   88,   88,   33,   59,   60,   88,   88,
 /*  1150 */    88,   88,   88,   88,   88,   88,   44,   88,   46,   88,
 /*  1160 */    88,   88,   50,   88,   52,   88,   88,   88,   88,   88,
 /*  1170 */    88,   59,   60,
};
#define KK_SHIFT_USE_DFLT (-4)
static short kk_shift_ofst[] = {
 /*     0 */   622,   47,  943,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,  930,
 /*    20 */  1062,   94,  622,  626,  614,   22,   -4,   41,  622,  678,
 /*    30 */   642,   90,   -4, 1062,  120,   -4, 1062, 1062,  178, 1062,
 /*    40 */   178, 1062,   43, 1062,   43, 1062,   43, 1062,  411, 1062,
 /*    50 */   411, 1062,  178, 1062,   -2, 1062,  392, 1062,   36,  962,
 /*    60 */    36, 1062,   36, 1062,   36, 1062,   36, 1062,   36, 1062,
 /*    70 */    36, 1062,   36, 1062,   36, 1062,   -4,  987,  146,   -4,
 /*    80 */  1012,  371, 1062,   45, 1062,  169,   -4, 1087,  371,  195,
 /*    90 */    -4, 1087,   -4,  118, 1062,  371,   -4,   -4,   -4,   -4,
 /*   100 */    -4,   -4,   -4,   -4,   -4,  194,   -4, 1112,   -4,  119,
 /*   110 */  1062,  371,   -4,   -4,   16,   88,   -4,   89,  166,  168,
 /*   120 */   655,   -4,  196,   -4,  200,  275, 1037,   -4,   -4,  178,
 /*   130 */   246,  868, 1062,   -3,  622,  682,  670,  252,   -4,  270,
 /*   140 */   277, 1062,  227,   -4,   -4,  282,  292,  706,  734,  698,
 /*   150 */   293,   -4, 1062,   23,  622,  738,  726,  315,   -4,  299,
 /*   160 */   318,   -4,  323,  343,   -4, 1062,  253,   -4,   42,  344,
 /*   170 */   622,  762,  754,  367,   -4,  388,   -4,  407,   -4, 1062,
 /*   180 */   279,   -4,   -4,   -4,  409,  622,  790,  782,  627,   -4,
 /*   190 */   629,  622,  794,  810,  630,   -4,  834,  637,   -4, 1062,
 /*   200 */   319,  622,  818,  858,  638,   -4,  647,  649, 1062,   68,
 /*   210 */   622,  842,  882,  657,   -4, 1062,  345,  622,  846,  906,
 /*   220 */   658,   -4,
};
#define KK_REDUCE_USE_DFLT (-1)
static short kk_reduce_ofst[] = {
 /*     0 */   143,   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*    10 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*    20 */   231,   -1,  374,  560,   -1,   -1,   -1,   -1,  391,  560,
 /*    30 */    -1,   -1,   -1,  566,   -1,   -1,  568,  591,   -1,  594,
 /*    40 */    -1,  646,   -1,  674,   -1,  702,   -1,  730,   -1,  740,
 /*    50 */    -1,  758,   -1,  786,   -1,  811,   -1,  814,   -1,  823,
 /*    60 */    -1,  838,   -1,  840,   -1,  847,   -1,  859,   -1,  864,
 /*    70 */    -1,  871,   -1,  883,   -1,  886,   -1,  144,   -1,   -1,
 /*    80 */   112,   -1,  895,   -1,  907,   -1,   -1,  224,   -1,   -1,
 /*    90 */    -1,  226,   -1,   -1,  912,   -1,   -1,   -1,   -1,   -1,
 /*   100 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,  232,   -1,   -1,
 /*   110 */   915,   -1,   -1,   -1,   61,   -1,   -1,   -1,   -1,   -1,
 /*   120 */   145,   -1,   -1,   -1,   -1,   -1,  895,   -1,   -1,   -1,
 /*   130 */    -1,   -1,  918,   -1,  408,  560,   -1,   -1,   -1,   -1,
 /*   140 */    -1,  920,   -1,   -1,   -1,   -1,   -1,  425,  560,   -1,
 /*   150 */    -1,   -1,  928,   -1,  442,  560,   -1,   -1,   -1,   -1,
 /*   160 */    -1,   -1,   -1,   -1,   -1,  938,   -1,   -1,   -1,   -1,
 /*   170 */   459,  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  944,
 /*   180 */    -1,   -1,   -1,   -1,   -1,  476,  560,   -1,   -1,   -1,
 /*   190 */    -1,  493,  560,   -1,   -1,   -1,   -1,   -1,   -1,  945,
 /*   200 */    -1,  510,  560,   -1,   -1,   -1,   -1,   -1,  953,   -1,
 /*   210 */   527,  560,   -1,   -1,   -1,  963,   -1,  544,  560,   -1,
 /*   220 */    -1,   -1,
};
static KKACTIONTYPE kk_default[] = {
 /*     0 */   313,  313,  313,  224,  226,  227,  228,  229,  230,  231,
 /*    10 */   232,  233,  234,  235,  236,  237,  238,  239,  240,  313,
 /*    20 */   313,  313,  313,  313,  313,  313,  241,  313,  313,  313,
 /*    30 */   313,  313,  242,  313,  313,  243,  313,  313,  263,  313,
 /*    40 */   265,  313,  266,  313,  267,  313,  268,  313,  269,  313,
 /*    50 */   270,  313,  271,  313,  272,  313,  273,  313,  274,  313,
 /*    60 */   277,  313,  278,  313,  279,  313,  280,  313,  281,  313,
 /*    70 */   282,  313,  283,  313,  284,  313,  285,  313,  313,  289,
 /*    80 */   313,  304,  313,  286,  313,  313,  287,  313,  298,  313,
 /*    90 */   288,  313,  295,  308,  313,  297,  299,  306,  307,  308,
 /*   100 */   309,  310,  311,  312,  296,  313,  300,  313,  302,  308,
 /*   110 */   313,  305,  301,  303,  313,  313,  290,  313,  313,  313,
 /*   120 */   313,  291,  313,  292,  307,  306,  313,  275,  276,  264,
 /*   130 */   313,  313,  313,  313,  313,  313,  313,  313,  244,  313,
 /*   140 */   313,  313,  313,  248,  249,  313,  313,  313,  313,  313,
 /*   150 */   313,  251,  313,  313,  313,  313,  313,  313,  253,  313,
 /*   160 */   313,  255,  313,  313,  256,  313,  313,  257,  313,  313,
 /*   170 */   313,  313,  313,  313,  258,  313,  260,  313,  261,  313,
 /*   180 */   313,  250,  262,  225,  313,  313,  313,  313,  313,  259,
 /*   190 */   313,  313,  313,  313,  313,  254,  313,  313,  252,  313,
 /*   200 */   313,  313,  313,  313,  313,  245,  313,  313,  313,  313,
 /*   210 */   313,  313,  313,  313,  246,  313,  313,  313,  313,  313,
 /*   220 */   313,  247,
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
  "elseif_statement",  "for_statement",  "set_statement",  "echo_statement",
  "block_statement",  "cache_statement",  "extends_statement",  "include_statement",
  "do_statement",  "autoescape_statement",  "break_statement",  "continue_statement",
  "empty_statement",  "expr",          "array_list",    "slice_offset",
  "array_item",    "function_call",  "argument_list",  "argument_item",
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
 /*   7 */ "statement ::= for_statement",
 /*   8 */ "statement ::= set_statement",
 /*   9 */ "statement ::= echo_statement",
 /*  10 */ "statement ::= block_statement",
 /*  11 */ "statement ::= cache_statement",
 /*  12 */ "statement ::= extends_statement",
 /*  13 */ "statement ::= include_statement",
 /*  14 */ "statement ::= do_statement",
 /*  15 */ "statement ::= autoescape_statement",
 /*  16 */ "statement ::= break_statement",
 /*  17 */ "statement ::= continue_statement",
 /*  18 */ "statement ::= empty_statement",
 /*  19 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  20 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  21 */ "elseif_statement ::= OPEN_DELIMITER ELSEIF expr CLOSE_DELIMITER",
 /*  22 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  23 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  24 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  25 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  26 */ "set_statement ::= OPEN_DELIMITER SET IDENTIFIER ASSIGN expr CLOSE_DELIMITER",
 /*  27 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  28 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  29 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  30 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  31 */ "cache_statement ::= OPEN_DELIMITER CACHE expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  32 */ "cache_statement ::= OPEN_DELIMITER CACHE expr INTEGER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  33 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  34 */ "include_statement ::= OPEN_DELIMITER INCLUDE STRING CLOSE_DELIMITER",
 /*  35 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  36 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE FALSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  37 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE TRUE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  38 */ "break_statement ::= OPEN_DELIMITER BREAK CLOSE_DELIMITER",
 /*  39 */ "continue_statement ::= OPEN_DELIMITER CONTINUE CLOSE_DELIMITER",
 /*  40 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  41 */ "expr ::= MINUS expr",
 /*  42 */ "expr ::= expr MINUS expr",
 /*  43 */ "expr ::= expr PLUS expr",
 /*  44 */ "expr ::= expr TIMES expr",
 /*  45 */ "expr ::= expr DIVIDE expr",
 /*  46 */ "expr ::= expr MOD expr",
 /*  47 */ "expr ::= expr AND expr",
 /*  48 */ "expr ::= expr OR expr",
 /*  49 */ "expr ::= expr CONCAT expr",
 /*  50 */ "expr ::= expr PIPE expr",
 /*  51 */ "expr ::= expr RANGE expr",
 /*  52 */ "expr ::= expr EQUALS expr",
 /*  53 */ "expr ::= expr IS NOT DEFINED",
 /*  54 */ "expr ::= expr IS DEFINED",
 /*  55 */ "expr ::= expr IS expr",
 /*  56 */ "expr ::= expr NOTEQUALS expr",
 /*  57 */ "expr ::= expr IDENTICAL expr",
 /*  58 */ "expr ::= expr NOTIDENTICAL expr",
 /*  59 */ "expr ::= expr LESS expr",
 /*  60 */ "expr ::= expr GREATER expr",
 /*  61 */ "expr ::= expr GREATEREQUAL expr",
 /*  62 */ "expr ::= expr LESSEQUAL expr",
 /*  63 */ "expr ::= expr DOT expr",
 /*  64 */ "expr ::= NOT expr",
 /*  65 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /*  66 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /*  67 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /*  68 */ "expr ::= expr SBRACKET_OPEN COLON slice_offset SBRACKET_CLOSE",
 /*  69 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON SBRACKET_CLOSE",
 /*  70 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON slice_offset SBRACKET_CLOSE",
 /*  71 */ "slice_offset ::= INTEGER",
 /*  72 */ "slice_offset ::= IDENTIFIER",
 /*  73 */ "array_list ::= array_list COMMA array_item",
 /*  74 */ "array_list ::= array_item",
 /*  75 */ "array_item ::= STRING COLON expr",
 /*  76 */ "array_item ::= expr",
 /*  77 */ "expr ::= function_call",
 /*  78 */ "function_call ::= expr BRACKET_OPEN argument_list BRACKET_CLOSE",
 /*  79 */ "function_call ::= expr BRACKET_OPEN BRACKET_CLOSE",
 /*  80 */ "argument_list ::= argument_list COMMA argument_item",
 /*  81 */ "argument_list ::= argument_item",
 /*  82 */ "argument_item ::= expr",
 /*  83 */ "argument_item ::= STRING COLON expr",
 /*  84 */ "expr ::= IDENTIFIER",
 /*  85 */ "expr ::= INTEGER",
 /*  86 */ "expr ::= STRING",
 /*  87 */ "expr ::= DOUBLE",
 /*  88 */ "expr ::= NULL",
 /*  89 */ "expr ::= FALSE",
 /*  90 */ "expr ::= TRUE",
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
// 517 "parser.lemon"
{
	if ((kkpminor->kk0)) {
		if ((kkpminor->kk0)->free_flag) {
			efree((kkpminor->kk0)->token);
		}
		efree((kkpminor->kk0));
	}
}
// 1206 "parser.c"
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
    case 87:
// 534 "parser.lemon"
{ zval_ptr_dtor(&(kkpminor->kk24)); }
// 1234 "parser.c"
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
  { 65, 1 },
  { 67, 8 },
  { 67, 12 },
  { 68, 4 },
  { 69, 10 },
  { 69, 12 },
  { 69, 12 },
  { 69, 14 },
  { 70, 6 },
  { 80, 2 },
  { 71, 3 },
  { 72, 8 },
  { 72, 7 },
  { 73, 8 },
  { 73, 9 },
  { 74, 4 },
  { 75, 4 },
  { 76, 4 },
  { 77, 8 },
  { 77, 8 },
  { 78, 3 },
  { 79, 3 },
  { 66, 1 },
  { 81, 2 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 4 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 2 },
  { 81, 3 },
  { 81, 3 },
  { 81, 4 },
  { 81, 5 },
  { 81, 5 },
  { 81, 6 },
  { 83, 1 },
  { 83, 1 },
  { 82, 3 },
  { 82, 1 },
  { 84, 3 },
  { 84, 1 },
  { 81, 1 },
  { 85, 4 },
  { 85, 3 },
  { 86, 3 },
  { 86, 1 },
  { 87, 1 },
  { 87, 3 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
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
// 526 "parser.lemon"
{
	status->ret = kkmsp[0].minor.kk24;
}
// 1542 "parser.c"
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
      case 77:
// 530 "parser.lemon"
{
	kkgotominor.kk24 = kkmsp[0].minor.kk24;
}
// 1565 "parser.c"
        break;
      case 2:
// 536 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_zval_list(kkmsp[-1].minor.kk24, kkmsp[0].minor.kk24);
}
// 1572 "parser.c"
        break;
      case 3:
      case 74:
      case 81:
// 540 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_zval_list(NULL, kkmsp[0].minor.kk24);
}
// 1581 "parser.c"
        break;
      case 19:
// 608 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_if_statement(kkmsp[-5].minor.kk24, kkmsp[-3].minor.kk24, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(27,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(29,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1594 "parser.c"
        break;
      case 20:
// 612 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_if_statement(kkmsp[-9].minor.kk24, kkmsp[-7].minor.kk24, kkmsp[-3].minor.kk24, status->scanner_state);
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
// 1610 "parser.c"
        break;
      case 21:
// 618 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_elseif_statement(kkmsp[-1].minor.kk24, status->scanner_state);
  kk_destructor(26,&kkmsp[-3].minor);
  kk_destructor(31,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1620 "parser.c"
        break;
      case 22:
// 624 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-5].minor.kk24, NULL, kkmsp[-3].minor.kk24, status->scanner_state);
  kk_destructor(26,&kkmsp[-9].minor);
  kk_destructor(32,&kkmsp[-8].minor);
  kk_destructor(34,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(35,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1634 "parser.c"
        break;
      case 23:
// 628 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, NULL, kkmsp[-7].minor.kk24, kkmsp[-5].minor.kk24, kkmsp[-3].minor.kk24, status->scanner_state);
  kk_destructor(26,&kkmsp[-11].minor);
  kk_destructor(32,&kkmsp[-10].minor);
  kk_destructor(34,&kkmsp[-8].minor);
  kk_destructor(27,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(35,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1649 "parser.c"
        break;
      case 24:
// 632 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, kkmsp[-9].minor.kk0, kkmsp[-5].minor.kk24, NULL, kkmsp[-3].minor.kk24, status->scanner_state);
  kk_destructor(26,&kkmsp[-11].minor);
  kk_destructor(32,&kkmsp[-10].minor);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(34,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(35,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1664 "parser.c"
        break;
      case 25:
// 636 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, kkmsp[-11].minor.kk0, kkmsp[-7].minor.kk24, kkmsp[-5].minor.kk24, kkmsp[-3].minor.kk24, status->scanner_state);
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
// 1680 "parser.c"
        break;
      case 26:
// 642 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_set_statement(kkmsp[-3].minor.kk0, kkmsp[-1].minor.kk24, status->scanner_state);
  kk_destructor(26,&kkmsp[-5].minor);
  kk_destructor(36,&kkmsp[-4].minor);
  kk_destructor(37,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1691 "parser.c"
        break;
      case 27:
// 648 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_empty_statement(status->scanner_state);
  kk_destructor(26,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1700 "parser.c"
        break;
      case 28:
// 654 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_echo_statement(kkmsp[-1].minor.kk24, status->scanner_state);
  kk_destructor(38,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[0].minor);
}
// 1709 "parser.c"
        break;
      case 29:
// 660 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_block_statement(kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk24, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(40,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1722 "parser.c"
        break;
      case 30:
// 664 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_block_statement(kkmsp[-4].minor.kk0, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-6].minor);
  kk_destructor(40,&kkmsp[-5].minor);
  kk_destructor(28,&kkmsp[-3].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1735 "parser.c"
        break;
      case 31:
// 670 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_cache_statement(kkmsp[-5].minor.kk24, NULL, kkmsp[-3].minor.kk24, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(42,&kkmsp[-6].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(43,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1748 "parser.c"
        break;
      case 32:
// 674 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_cache_statement(kkmsp[-6].minor.kk24, kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk24, status->scanner_state);
  kk_destructor(26,&kkmsp[-8].minor);
  kk_destructor(42,&kkmsp[-7].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(43,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1761 "parser.c"
        break;
      case 33:
// 680 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_extends_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(26,&kkmsp[-3].minor);
  kk_destructor(45,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1771 "parser.c"
        break;
      case 34:
// 686 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_include_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(26,&kkmsp[-3].minor);
  kk_destructor(47,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1781 "parser.c"
        break;
      case 35:
// 692 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_do_statement(kkmsp[-1].minor.kk24, status->scanner_state);
  kk_destructor(26,&kkmsp[-3].minor);
  kk_destructor(48,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1791 "parser.c"
        break;
      case 36:
// 698 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_autoescape_statement(0, kkmsp[-3].minor.kk24, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(49,&kkmsp[-6].minor);
  kk_destructor(50,&kkmsp[-5].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(51,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1805 "parser.c"
        break;
      case 37:
// 702 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_autoescape_statement(1, kkmsp[-3].minor.kk24, status->scanner_state);
  kk_destructor(26,&kkmsp[-7].minor);
  kk_destructor(49,&kkmsp[-6].minor);
  kk_destructor(52,&kkmsp[-5].minor);
  kk_destructor(28,&kkmsp[-4].minor);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(51,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1819 "parser.c"
        break;
      case 38:
// 708 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_break_statement(status->scanner_state);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(53,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1829 "parser.c"
        break;
      case 39:
// 714 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_continue_statement(status->scanner_state);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(54,&kkmsp[-1].minor);
  kk_destructor(28,&kkmsp[0].minor);
}
// 1839 "parser.c"
        break;
      case 40:
// 720 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, kkmsp[0].minor.kk0, status->scanner_state);
}
// 1846 "parser.c"
        break;
      case 41:
// 726 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 1854 "parser.c"
        break;
      case 42:
// 730 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_SUB, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 1862 "parser.c"
        break;
      case 43:
// 734 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_ADD, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 1870 "parser.c"
        break;
      case 44:
// 738 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_MUL, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(17,&kkmsp[-1].minor);
}
// 1878 "parser.c"
        break;
      case 45:
// 742 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_DIV, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(16,&kkmsp[-1].minor);
}
// 1886 "parser.c"
        break;
      case 46:
// 746 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(18,&kkmsp[-1].minor);
}
// 1894 "parser.c"
        break;
      case 47:
// 750 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_AND, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 1902 "parser.c"
        break;
      case 48:
// 754 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_OR, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(6,&kkmsp[-1].minor);
}
// 1910 "parser.c"
        break;
      case 49:
// 758 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_CONCAT, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
// 1918 "parser.c"
        break;
      case 50:
// 762 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_PIPE, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 1926 "parser.c"
        break;
      case 51:
// 766 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_RANGE, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(4,&kkmsp[-1].minor);
}
// 1934 "parser.c"
        break;
      case 52:
// 770 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_EQUALS, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(8,&kkmsp[-1].minor);
}
// 1942 "parser.c"
        break;
      case 53:
// 774 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, kkmsp[-3].minor.kk24, NULL, status->scanner_state);
  kk_destructor(7,&kkmsp[-2].minor);
  kk_destructor(24,&kkmsp[-1].minor);
  kk_destructor(56,&kkmsp[0].minor);
}
// 1952 "parser.c"
        break;
      case 54:
// 778 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_ISSET, kkmsp[-2].minor.kk24, NULL, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
  kk_destructor(56,&kkmsp[0].minor);
}
// 1961 "parser.c"
        break;
      case 55:
// 782 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_IS, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
}
// 1969 "parser.c"
        break;
      case 56:
// 786 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
}
// 1977 "parser.c"
        break;
      case 57:
// 790 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(14,&kkmsp[-1].minor);
}
// 1985 "parser.c"
        break;
      case 58:
// 794 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(15,&kkmsp[-1].minor);
}
// 1993 "parser.c"
        break;
      case 59:
// 798 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_LESS, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
}
// 2001 "parser.c"
        break;
      case 60:
// 802 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_GREATER, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(11,&kkmsp[-1].minor);
}
// 2009 "parser.c"
        break;
      case 61:
// 806 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(12,&kkmsp[-1].minor);
}
// 2017 "parser.c"
        break;
      case 62:
// 810 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(13,&kkmsp[-1].minor);
}
// 2025 "parser.c"
        break;
      case 63:
// 814 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_DOT, kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(25,&kkmsp[-1].minor);
}
// 2033 "parser.c"
        break;
      case 64:
// 818 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(24,&kkmsp[-1].minor);
}
// 2041 "parser.c"
        break;
      case 65:
// 822 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, kkmsp[-1].minor.kk24, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(57,&kkmsp[0].minor);
}
// 2050 "parser.c"
        break;
      case 66:
// 826 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk24, NULL, status->scanner_state);
  kk_destructor(3,&kkmsp[-2].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
// 2059 "parser.c"
        break;
      case 67:
// 830 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, kkmsp[-3].minor.kk24, kkmsp[-1].minor.kk24, status->scanner_state);
  kk_destructor(3,&kkmsp[-2].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
// 2068 "parser.c"
        break;
      case 68:
// 834 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_slice(kkmsp[-4].minor.kk24, NULL, kkmsp[-1].minor.kk24, status->scanner_state);
  kk_destructor(3,&kkmsp[-3].minor);
  kk_destructor(2,&kkmsp[-2].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
// 2078 "parser.c"
        break;
      case 69:
// 838 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_slice(kkmsp[-4].minor.kk24, kkmsp[-2].minor.kk24, NULL, status->scanner_state);
  kk_destructor(3,&kkmsp[-3].minor);
  kk_destructor(2,&kkmsp[-1].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
// 2088 "parser.c"
        break;
      case 70:
// 842 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_slice(kkmsp[-5].minor.kk24, kkmsp[-3].minor.kk24, kkmsp[-1].minor.kk24, status->scanner_state);
  kk_destructor(3,&kkmsp[-4].minor);
  kk_destructor(2,&kkmsp[-2].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
// 2098 "parser.c"
        break;
      case 71:
      case 85:
// 848 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2106 "parser.c"
        break;
      case 72:
      case 84:
// 852 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2114 "parser.c"
        break;
      case 73:
      case 80:
// 858 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_zval_list(kkmsp[-2].minor.kk24, kkmsp[0].minor.kk24);
  kk_destructor(1,&kkmsp[-1].minor);
}
// 2123 "parser.c"
        break;
      case 75:
      case 83:
// 868 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_named_item(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk24, status->scanner_state);
  kk_destructor(2,&kkmsp[-1].minor);
}
// 2132 "parser.c"
        break;
      case 76:
      case 82:
// 872 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_named_item(NULL, kkmsp[0].minor.kk24, status->scanner_state);
}
// 2140 "parser.c"
        break;
      case 78:
// 882 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_func_call(kkmsp[-3].minor.kk24, kkmsp[-1].minor.kk24, status->scanner_state);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(57,&kkmsp[0].minor);
}
// 2149 "parser.c"
        break;
      case 79:
// 886 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_func_call(kkmsp[-2].minor.kk24, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
  kk_destructor(57,&kkmsp[0].minor);
}
// 2158 "parser.c"
        break;
      case 86:
// 918 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_literal_zval(PHVOLT_T_STRING, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2165 "parser.c"
        break;
      case 87:
// 922 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2172 "parser.c"
        break;
      case 88:
// 926 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  kk_destructor(60,&kkmsp[0].minor);
}
// 2180 "parser.c"
        break;
      case 89:
// 930 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  kk_destructor(50,&kkmsp[0].minor);
}
// 2188 "parser.c"
        break;
      case 90:
// 934 "parser.lemon"
{
	kkgotominor.kk24 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  kk_destructor(52,&kkmsp[0].minor);
}
// 2196 "parser.c"
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
// 471 "parser.lemon"

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

// 2284 "parser.c"
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