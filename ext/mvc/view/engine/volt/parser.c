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


// 401 "parser.c"
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
#define KKNOCODE 86
#define KKACTIONTYPE unsigned short int
#define phvolt_KTOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_KTOKENTYPE kk0;
  zval* kk58;
  int kk171;
} KKMINORTYPE;
#define KKSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = kkpParser->status
#define phvolt_ARG_STORE kkpParser->status = status
#define KKNSTATE 206
#define KKNRULE 84
#define KKERRORSYMBOL 60
#define KKERRSYMDT kk171
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
 /*     0 */    89,   65,   57,   59,   69,   67,   71,   77,   79,   81,
 /*    10 */    83,   73,   75,   63,   53,   51,   55,   49,   46,   61,
 /*    20 */    20,   87,   85,  106,  183,   36,  206,   89,   65,   57,
 /*    30 */    59,   69,   67,   71,   77,   79,   81,   83,   73,   75,
 /*    40 */    63,   53,   51,   55,   49,   46,   61,   35,   87,   85,
 /*    50 */   106,  199,  194,   33,   89,   65,   57,   59,   69,   67,
 /*    60 */    71,   77,   79,   81,   83,   73,   75,   63,   53,   51,
 /*    70 */    55,   49,   46,   61,  190,   87,   85,   25,   98,   21,
 /*    80 */   102,  106,   89,   65,   57,   59,   69,   67,   71,   77,
 /*    90 */    79,   81,   83,   73,   75,   63,   53,   51,   55,   49,
 /*   100 */    46,   61,   27,   87,   85,   34,   31,   45,   87,   85,
 /*   110 */    89,   65,   57,   59,   69,   67,   71,   77,   79,   81,
 /*   120 */    83,   73,   75,   63,   53,   51,   55,   49,   46,   61,
 /*   130 */    44,   87,   85,  106,   89,   65,   57,   59,   69,   67,
 /*   140 */    71,   77,   79,   81,   83,   73,   75,   63,   53,   51,
 /*   150 */    55,   49,   46,   61,   40,   87,   85,   63,   53,   51,
 /*   160 */    55,   49,   46,   61,   91,   87,   85,   89,   65,   57,
 /*   170 */    59,   69,   67,   71,   77,   79,   81,   83,   73,   75,
 /*   180 */    63,   53,   51,   55,   49,   46,   61,   96,   87,   85,
 /*   190 */   127,   48,  151,  106,  106,   89,   65,   57,   59,   69,
 /*   200 */    67,   71,   77,   79,   81,   83,   73,   75,   63,   53,
 /*   210 */    51,   55,   49,   46,   61,   42,   87,   85,   53,   51,
 /*   220 */    55,   49,   46,   61,   43,   87,   85,   49,   46,   61,
 /*   230 */   165,   87,   85,   89,   65,   57,   59,   69,   67,   71,
 /*   240 */    77,   79,   81,   83,   73,   75,   63,   53,   51,   55,
 /*   250 */    49,   46,   61,   50,   87,   85,  106,   52,  185,  130,
 /*   260 */   106,   89,   65,   57,   59,   69,   67,   71,   77,   79,
 /*   270 */    81,   83,   73,   75,   63,   53,   51,   55,   49,   46,
 /*   280 */    61,  104,   87,   85,   54,   56,  201,  106,  106,   89,
 /*   290 */    65,   57,   59,   69,   67,   71,   77,   79,   81,   83,
 /*   300 */    73,   75,   63,   53,   51,   55,   49,   46,   61,  120,
 /*   310 */    87,   85,   57,   59,   69,   67,   71,   77,   79,   81,
 /*   320 */    83,   73,   75,   63,   53,   51,   55,   49,   46,   61,
 /*   330 */   131,   87,   85,  291,    1,    2,  167,    4,    5,    6,
 /*   340 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   350 */    17,   69,   67,   71,   77,   79,   81,   83,   73,   75,
 /*   360 */    63,   53,   51,   55,   49,   46,   61,  135,   87,   85,
 /*   370 */    22,  167,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   380 */    12,   13,   14,   15,   16,   17,   28,  167,    4,    5,
 /*   390 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   400 */    16,   17,   37,  167,    4,    5,    6,    7,    8,    9,
 /*   410 */    10,   11,   12,   13,   14,   15,   16,   17,  132,  167,
 /*   420 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   430 */    14,   15,   16,   17,  139,  167,    4,    5,    6,    7,
 /*   440 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   450 */   155,  167,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   460 */    12,   13,   14,   15,   16,   17,  170,  167,    4,    5,
 /*   470 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   480 */    16,   17,  176,  167,    4,    5,    6,    7,    8,    9,
 /*   490 */    10,   11,   12,   13,   14,   15,   16,   17,  186,  167,
 /*   500 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   510 */    14,   15,   16,   17,  195,  167,    4,    5,    6,    7,
 /*   520 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   530 */   202,  167,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   540 */    12,   13,   14,   15,   16,   17,    3,    4,    5,    6,
 /*   550 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   560 */    17,   19,  128,   24,   26,   32,   18,   88,  137,   41,
 /*   570 */   106,  115,  123,  129,  142,  136,   58,  163,  143,  106,
 /*   580 */   146,  149,  152,  117,   23,  145,  159,  161,   19,  128,
 /*   590 */    30,  138,   32,   29,  166,  163,   41,  101,   88,  144,
 /*   600 */   129,  106,  136,  118,  163,  143,  174,  146,  149,  152,
 /*   610 */   147,  148,  166,  159,  161,   19,  128,  154,  158,   32,
 /*   620 */    38,  166,   39,   41,  153,   60,  168,  129,  106,  136,
 /*   630 */    62,  163,  143,  106,  146,  149,  152,  116,  180,  160,
 /*   640 */   159,  161,   19,  128,  162,  169,   32,  133,  166,  163,
 /*   650 */    41,  173,  100,  175,  129,  134,  136,   64,  163,  143,
 /*   660 */   106,  146,  149,  152,  179,  182,  166,  159,  161,   19,
 /*   670 */   128,  189,  191,   32,  140,  166,   66,   41,  192,  106,
 /*   680 */   198,  129,  205,  136,  141,  163,  143,  171,  146,  149,
 /*   690 */   152,  171,  156,  171,  159,  161,   19,  128,  171,  171,
 /*   700 */    32,  171,  166,  163,   41,  171,  164,  171,  129,  106,
 /*   710 */   136,   68,  163,  143,  106,  146,  149,  152,  171,  157,
 /*   720 */   166,  159,  161,   19,  128,  171,  171,   32,  177,  166,
 /*   730 */    70,   41,  171,  106,  171,  129,  207,  136,   72,  163,
 /*   740 */   143,  106,  146,  149,  152,  171,  172,  171,  159,  161,
 /*   750 */    19,  128,  171,  171,   32,  187,  166,   74,   41,  171,
 /*   760 */   106,   18,  129,  171,  136,  178,  163,  143,  171,  146,
 /*   770 */   149,  152,  163,   19,  128,  159,  161,   32,  171,  171,
 /*   780 */   171,   41,  171,  166,  196,  129,  181,  136,   76,  166,
 /*   790 */   143,  106,  146,  149,  152,  163,   19,  128,  159,  161,
 /*   800 */    32,  171,   78,  188,   41,  106,  171,  203,  129,  171,
 /*   810 */   136,   80,  166,  143,  106,  146,  149,  152,  163,   19,
 /*   820 */   128,  159,  161,   32,  171,  171,  197,   41,  171,   82,
 /*   830 */   171,  129,  106,  136,   84,  166,  143,  106,  146,  149,
 /*   840 */   152,  171,   19,  128,  159,  161,   32,  171,  171,  204,
 /*   850 */    41,  171,   86,  171,  129,  106,  136,   90,  171,  143,
 /*   860 */   106,  146,  149,  152,  171,   19,  128,  159,  161,   32,
 /*   870 */   171,   93,  171,   41,  106,   95,   97,  129,  106,  136,
 /*   880 */   105,  171,  143,  106,  146,  149,  152,  171,  171,  171,
 /*   890 */   159,  161,  121,  171,   47,  106,  124,   94,  171,   98,
 /*   900 */    99,  114,  106,  150,  171,  107,  106,  184,  171,  193,
 /*   910 */   106,  200,  106,  171,  106,  171,  108,  171,  109,   97,
 /*   920 */   171,  171,  112,  171,  113,  171,  171,  171,  126,  171,
 /*   930 */   171,   97,  110,  111,  171,  171,  171,   47,  171,   92,
 /*   940 */    94,  171,  171,  171,  171,  171,  171,  171,  107,   47,
 /*   950 */   171,   92,   94,  171,  171,  171,  171,  171,  171,  108,
 /*   960 */   107,  119,  171,  171,   97,  112,  171,  113,  171,  171,
 /*   970 */   171,  108,  122,  109,  171,  110,  111,  112,  171,  113,
 /*   980 */   171,  171,   47,  125,   92,   94,  171,  110,  111,  171,
 /*   990 */   171,  171,  171,  107,  171,  171,   97,  171,  171,  171,
 /*  1000 */   171,  171,  171,  171,  108,  171,  109,  171,  171,  171,
 /*  1010 */   112,  171,  113,  171,   47,  171,   92,   94,  171,   97,
 /*  1020 */   110,  111,  171,  171,  171,  107,  171,  171,  171,  171,
 /*  1030 */   171,  171,  171,  171,  171,  171,  108,   47,  103,   92,
 /*  1040 */    94,  171,  112,  171,  113,  171,  171,  171,  107,  171,
 /*  1050 */   171,  171,  110,  111,  171,  171,  171,  171,  171,  108,
 /*  1060 */   171,  119,  171,  171,  171,  112,  171,  113,  171,  171,
 /*  1070 */   171,  171,  171,  171,  171,  110,  111,
};
static KKCODETYPE kk_lookahead[] = {
 /*     0 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*    10 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*    20 */    79,   23,   24,   82,   26,   27,    0,    2,    3,    4,
 /*    30 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*    40 */    15,   16,   17,   18,   19,   20,   21,   79,   23,   24,
 /*    50 */    82,   26,   27,   31,    2,    3,    4,    5,    6,    7,
 /*    60 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    70 */    18,   19,   20,   21,    1,   23,   24,   27,   79,   27,
 /*    80 */    81,   82,    2,    3,    4,    5,    6,    7,    8,    9,
 /*    90 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   100 */    20,   21,   27,   23,   24,   32,   27,   27,   23,   24,
 /*   110 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   120 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   130 */    79,   23,   24,   82,    2,    3,    4,    5,    6,    7,
 /*   140 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   150 */    18,   19,   20,   21,   27,   23,   24,   15,   16,   17,
 /*   160 */    18,   19,   20,   21,   56,   23,   24,    2,    3,    4,
 /*   170 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   180 */    15,   16,   17,   18,   19,   20,   21,   55,   23,   24,
 /*   190 */    79,   79,   27,   82,   82,    2,    3,    4,    5,    6,
 /*   200 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   210 */    17,   18,   19,   20,   21,   31,   23,   24,   16,   17,
 /*   220 */    18,   19,   20,   21,   35,   23,   24,   19,   20,   21,
 /*   230 */    37,   23,   24,    2,    3,    4,    5,    6,    7,    8,
 /*   240 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   250 */    19,   20,   21,   79,   23,   24,   82,   79,   27,   31,
 /*   260 */    82,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   270 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   280 */    21,   57,   23,   24,   79,   79,   27,   82,   82,    2,
 /*   290 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   300 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   57,
 /*   310 */    23,   24,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   320 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   330 */    27,   23,   24,   61,   62,   63,   64,   65,   66,   67,
 /*   340 */    68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
 /*   350 */    78,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   360 */    15,   16,   17,   18,   19,   20,   21,   27,   23,   24,
 /*   370 */    63,   64,   65,   66,   67,   68,   69,   70,   71,   72,
 /*   380 */    73,   74,   75,   76,   77,   78,   63,   64,   65,   66,
 /*   390 */    67,   68,   69,   70,   71,   72,   73,   74,   75,   76,
 /*   400 */    77,   78,   63,   64,   65,   66,   67,   68,   69,   70,
 /*   410 */    71,   72,   73,   74,   75,   76,   77,   78,   63,   64,
 /*   420 */    65,   66,   67,   68,   69,   70,   71,   72,   73,   74,
 /*   430 */    75,   76,   77,   78,   63,   64,   65,   66,   67,   68,
 /*   440 */    69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
 /*   450 */    63,   64,   65,   66,   67,   68,   69,   70,   71,   72,
 /*   460 */    73,   74,   75,   76,   77,   78,   63,   64,   65,   66,
 /*   470 */    67,   68,   69,   70,   71,   72,   73,   74,   75,   76,
 /*   480 */    77,   78,   63,   64,   65,   66,   67,   68,   69,   70,
 /*   490 */    71,   72,   73,   74,   75,   76,   77,   78,   63,   64,
 /*   500 */    65,   66,   67,   68,   69,   70,   71,   72,   73,   74,
 /*   510 */    75,   76,   77,   78,   63,   64,   65,   66,   67,   68,
 /*   520 */    69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
 /*   530 */    63,   64,   65,   66,   67,   68,   69,   70,   71,   72,
 /*   540 */    73,   74,   75,   76,   77,   78,   64,   65,   66,   67,
 /*   550 */    68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
 /*   560 */    78,   26,   27,   28,   29,   30,   25,   79,   31,   34,
 /*   570 */    82,   83,   84,   38,   27,   40,   79,   36,   43,   82,
 /*   580 */    45,   46,   47,    1,   25,   27,   51,   52,   26,   27,
 /*   590 */    28,   27,   30,   25,   53,   36,   34,    1,   79,   44,
 /*   600 */    38,   82,   40,   84,   36,   43,   42,   45,   46,   47,
 /*   610 */    44,   27,   53,   51,   52,   26,   27,   27,   27,   30,
 /*   620 */    25,   53,   33,   34,   48,   79,   50,   38,   82,   40,
 /*   630 */    79,   36,   43,   82,   45,   46,   47,   55,   25,   27,
 /*   640 */    51,   52,   26,   27,   27,   27,   30,   25,   53,   36,
 /*   650 */    34,   27,   56,   27,   38,   39,   40,   79,   36,   43,
 /*   660 */    82,   45,   46,   47,   27,   27,   53,   51,   52,   26,
 /*   670 */    27,   27,   31,   30,   25,   53,   79,   34,   32,   82,
 /*   680 */    27,   38,   27,   40,   41,   36,   43,   85,   45,   46,
 /*   690 */    47,   85,   25,   85,   51,   52,   26,   27,   85,   85,
 /*   700 */    30,   25,   53,   36,   34,   85,   79,   85,   38,   82,
 /*   710 */    40,   79,   36,   43,   82,   45,   46,   47,   85,   49,
 /*   720 */    53,   51,   52,   26,   27,   85,   85,   30,   25,   53,
 /*   730 */    79,   34,   85,   82,   85,   38,    0,   40,   79,   36,
 /*   740 */    43,   82,   45,   46,   47,   85,   49,   85,   51,   52,
 /*   750 */    26,   27,   85,   85,   30,   25,   53,   79,   34,   85,
 /*   760 */    82,   25,   38,   85,   40,   41,   36,   43,   85,   45,
 /*   770 */    46,   47,   36,   26,   27,   51,   52,   30,   85,   85,
 /*   780 */    85,   34,   85,   53,   25,   38,   39,   40,   79,   53,
 /*   790 */    43,   82,   45,   46,   47,   36,   26,   27,   51,   52,
 /*   800 */    30,   85,   79,   33,   34,   82,   85,   25,   38,   85,
 /*   810 */    40,   79,   53,   43,   82,   45,   46,   47,   36,   26,
 /*   820 */    27,   51,   52,   30,   85,   85,   33,   34,   85,   79,
 /*   830 */    85,   38,   82,   40,   79,   53,   43,   82,   45,   46,
 /*   840 */    47,   85,   26,   27,   51,   52,   30,   85,   85,   33,
 /*   850 */    34,   85,   79,   85,   38,   82,   40,   79,   85,   43,
 /*   860 */    82,   45,   46,   47,   85,   26,   27,   51,   52,   30,
 /*   870 */    85,   79,   85,   34,   82,   79,    2,   38,   82,   40,
 /*   880 */    79,   85,   43,   82,   45,   46,   47,   85,   85,   85,
 /*   890 */    51,   52,   79,   85,   20,   82,   22,   23,   85,   79,
 /*   900 */    80,   81,   82,   79,   85,   31,   82,   79,   85,   79,
 /*   910 */    82,   79,   82,   85,   82,   85,   42,   85,   44,    2,
 /*   920 */    85,   85,   48,   85,   50,   85,   85,   85,   54,   85,
 /*   930 */    85,    2,   58,   59,   85,   85,   85,   20,   85,   22,
 /*   940 */    23,   85,   85,   85,   85,   85,   85,   85,   31,   20,
 /*   950 */    85,   22,   23,   85,   85,   85,   85,   85,   85,   42,
 /*   960 */    31,   44,   85,   85,    2,   48,   85,   50,   85,   85,
 /*   970 */    85,   42,   55,   44,   85,   58,   59,   48,   85,   50,
 /*   980 */    85,   85,   20,   54,   22,   23,   85,   58,   59,   85,
 /*   990 */    85,   85,   85,   31,   85,   85,    2,   85,   85,   85,
 /*  1000 */    85,   85,   85,   85,   42,   85,   44,   85,   85,   85,
 /*  1010 */    48,   85,   50,   85,   20,   85,   22,   23,   85,    2,
 /*  1020 */    58,   59,   85,   85,   85,   31,   85,   85,   85,   85,
 /*  1030 */    85,   85,   85,   85,   85,   85,   42,   20,   44,   22,
 /*  1040 */    23,   85,   48,   85,   50,   85,   85,   85,   31,   85,
 /*  1050 */    85,   85,   58,   59,   85,   85,   85,   85,   85,   42,
 /*  1060 */    85,   44,   85,   85,   85,   48,   85,   50,   85,   85,
 /*  1070 */    85,   85,   85,   85,   85,   58,   59,
};
#define KK_SHIFT_USE_DFLT (-3)
static short kk_shift_ofst[] = {
 /*     0 */   541,   26,  736,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
 /*    10 */    -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,  839,  962,
 /*    20 */    52,  541,  559,  535,   50,   -3,   75,  541,  568,  562,
 /*    30 */    79,   -3,   22,   73,  962,   -2,  541,  595,  589,  127,
 /*    40 */    -3,  184,  189,  962,   80,   -3,  962,  962,   85,  962,
 /*    50 */    85,  962,  208,  962,  208,  962,  208,  962,  345,  962,
 /*    60 */   345,  962,   85,  962,  202,  962,  308,  962,  142,  874,
 /*    70 */   142,  962,  142,  962,  142,  962,  142,  962,  142,  962,
 /*    80 */   142,  962,  142,  962,  142,  962,   -3,  917,  287,  962,
 /*    90 */   108,   -3,  962,   85,  962,  132,   -3,  994,  287,  596,
 /*   100 */    -3,  994,   -3,  224,  962,  287,   -3,   -3,   -3,   -3,
 /*   110 */    -3,   -3,   -3,   -3,   -3,  582,   -3, 1017,   -3,  252,
 /*   120 */   962,  287,   -3,   -3,  929,   -3,   -3,   85,   -3,  228,
 /*   130 */   303,  613,  622,  616,  340,   -3,  537,  564,  541,  649,
 /*   140 */   643,  547,   -3,  555,  558,   -3,  566,  584,   -3,  962,
 /*   150 */   165,   -3,  576,  590,  541,  667,  670,  591,   -3,  612,
 /*   160 */    -3,  617,   -3,  962,  193,   -3,   -3,   -3,  618,  541,
 /*   170 */   676,  697,  624,   -3,  626,  541,  703,  724,  637,   -3,
 /*   180 */   747,  638,   -3,  962,  231,  541,  730,  770,  644,   -3,
 /*   190 */   641,  646,  962,   25,  541,  759,  793,  653,   -3,  962,
 /*   200 */   259,  541,  782,  816,  655,   -3,
};
#define KK_REDUCE_USE_DFLT (-60)
static short kk_reduce_ofst[] = {
 /*     0 */   272,  -60,  482,  -60,  -60,  -60,  -60,  -60,  -60,  -60,
 /*    10 */   -60,  -60,  -60,  -60,  -60,  -60,  -60,  -60,  -60,  -59,
 /*    20 */   -60,  307,  482,  -60,  -60,  -60,  -60,  323,  482,  -60,
 /*    30 */   -60,  -60,  -60,  -60,  -32,  -60,  339,  482,  -60,  -60,
 /*    40 */   -60,  -60,  -60,   51,  -60,  -60,  111,  112,  -60,  174,
 /*    50 */   -60,  178,  -60,  205,  -60,  206,  -60,  497,  -60,  546,
 /*    60 */   -60,  551,  -60,  578,  -60,  597,  -60,  632,  -60,  651,
 /*    70 */   -60,  659,  -60,  678,  -60,  709,  -60,  723,  -60,  732,
 /*    80 */   -60,  750,  -60,  755,  -60,  773,  -60,  488,  -60,  778,
 /*    90 */   -60,  -60,  792,  -60,  796,  -60,  -60,  820,  -60,  -60,
 /*   100 */   -60,   -1,  -60,  -60,  801,  -60,  -60,  -60,  -60,  -60,
 /*   110 */   -60,  -60,  -60,  -60,  -60,  -60,  -60,  519,  -60,  -60,
 /*   120 */   813,  -60,  -60,  -60,  792,  -60,  -60,  -60,  -60,  -60,
 /*   130 */   -60,  355,  482,  -60,  -60,  -60,  -60,  -60,  371,  482,
 /*   140 */   -60,  -60,  -60,  -60,  -60,  -60,  -60,  -60,  -60,  824,
 /*   150 */   -60,  -60,  -60,  -60,  387,  482,  -60,  -60,  -60,  -60,
 /*   160 */   -60,  -60,  -60,  627,  -60,  -60,  -60,  -60,  -60,  403,
 /*   170 */   482,  -60,  -60,  -60,  -60,  419,  482,  -60,  -60,  -60,
 /*   180 */   -60,  -60,  -60,  828,  -60,  435,  482,  -60,  -60,  -60,
 /*   190 */   -60,  -60,  830,  -60,  451,  482,  -60,  -60,  -60,  832,
 /*   200 */   -60,  467,  482,  -60,  -60,  -60,
};
static KKACTIONTYPE kk_default[] = {
 /*     0 */   290,  290,  290,  208,  210,  211,  212,  213,  214,  215,
 /*    10 */   216,  217,  218,  219,  220,  221,  222,  223,  290,  290,
 /*    20 */   290,  290,  290,  290,  290,  224,  290,  290,  290,  290,
 /*    30 */   290,  225,  290,  290,  290,  290,  290,  290,  290,  290,
 /*    40 */   226,  290,  290,  290,  290,  230,  290,  290,  245,  290,
 /*    50 */   247,  290,  248,  290,  249,  290,  250,  290,  251,  290,
 /*    60 */   252,  290,  253,  290,  254,  290,  255,  290,  256,  290,
 /*    70 */   259,  290,  260,  290,  261,  290,  262,  290,  263,  290,
 /*    80 */   264,  290,  265,  290,  266,  290,  267,  290,  280,  290,
 /*    90 */   290,  283,  290,  268,  290,  290,  269,  290,  274,  290,
 /*   100 */   270,  290,  271,  285,  290,  273,  275,  282,  284,  285,
 /*   110 */   286,  287,  288,  289,  272,  290,  276,  290,  278,  285,
 /*   120 */   290,  281,  277,  279,  290,  257,  258,  246,  231,  290,
 /*   130 */   290,  290,  290,  290,  290,  233,  290,  290,  290,  290,
 /*   140 */   290,  290,  235,  290,  290,  237,  290,  290,  238,  290,
 /*   150 */   290,  239,  290,  290,  290,  290,  290,  290,  240,  290,
 /*   160 */   242,  290,  243,  290,  290,  232,  244,  209,  290,  290,
 /*   170 */   290,  290,  290,  241,  290,  290,  290,  290,  290,  236,
 /*   180 */   290,  290,  234,  290,  290,  290,  290,  290,  290,  227,
 /*   190 */   290,  290,  290,  290,  290,  290,  290,  290,  228,  290,
 /*   200 */   290,  290,  290,  290,  290,  229,
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
  "$",             "COMMA",         "SBRACKET_OPEN",  "RANGE",       
  "AND",           "OR",            "IS",            "EQUALS",      
  "NOTEQUALS",     "LESS",          "GREATER",       "GREATEREQUAL",
  "LESSEQUAL",     "IDENTICAL",     "NOTIDENTICAL",  "PIPE",        
  "DIVIDE",        "TIMES",         "MOD",           "PLUS",        
  "MINUS",         "CONCAT",        "NOT",           "BRACKET_OPEN",
  "DOT",           "OPEN_DELIMITER",  "IF",            "CLOSE_DELIMITER",
  "ENDIF",         "ELSE",          "FOR",           "IDENTIFIER",  
  "IN",            "ENDFOR",        "SET",           "ASSIGN",      
  "OPEN_EDELIMITER",  "CLOSE_EDELIMITER",  "BLOCK",         "ENDBLOCK",    
  "CACHE",         "ENDCACHE",      "INTEGER",       "EXTENDS",     
  "STRING",        "INCLUDE",       "DO",            "AUTOESCAPE",  
  "FALSE",         "ENDAUTOESCAPE",  "TRUE",          "BREAK",       
  "CONTINUE",      "RAW_FRAGMENT",  "DEFINED",       "BRACKET_CLOSE",
  "SBRACKET_CLOSE",  "DOUBLECOLON",   "DOUBLE",        "NULL",        
  "error",         "program",       "volt_language",  "statement_list",
  "statement",     "raw_fragment",  "if_statement",  "for_statement",
  "set_statement",  "echo_statement",  "block_statement",  "cache_statement",
  "extends_statement",  "include_statement",  "do_statement",  "autoescape_statement",
  "break_statement",  "continue_statement",  "empty_statement",  "expr",        
  "array_list",    "array_item",    "function_call",  "argument_list",
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
 /*  65 */ "array_list ::= array_list COMMA array_item",
 /*  66 */ "array_list ::= array_item",
 /*  67 */ "array_item ::= STRING DOUBLECOLON expr",
 /*  68 */ "array_item ::= expr",
 /*  69 */ "expr ::= function_call",
 /*  70 */ "function_call ::= expr BRACKET_OPEN argument_list BRACKET_CLOSE",
 /*  71 */ "function_call ::= expr BRACKET_OPEN BRACKET_CLOSE",
 /*  72 */ "argument_list ::= argument_list COMMA argument_item",
 /*  73 */ "argument_list ::= argument_item",
 /*  74 */ "argument_item ::= expr",
 /*  75 */ "argument_item ::= STRING DOUBLECOLON expr",
 /*  76 */ "expr ::= IDENTIFIER",
 /*  77 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /*  78 */ "expr ::= INTEGER",
 /*  79 */ "expr ::= STRING",
 /*  80 */ "expr ::= DOUBLE",
 /*  81 */ "expr ::= NULL",
 /*  82 */ "expr ::= FALSE",
 /*  83 */ "expr ::= TRUE",
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
// 477 "parser.lemon"
{
	if ((kkpminor->kk0)) {
		if ((kkpminor->kk0)->free_flag) {
			efree((kkpminor->kk0)->token);
		}
		efree((kkpminor->kk0));
	}
}
// 1132 "parser.c"
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
    case 82:
    case 83:
    case 84:
// 494 "parser.lemon"
{ zval_ptr_dtor(&(kkpminor->kk58)); }
// 1157 "parser.c"
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
  { 80, 3 },
  { 80, 1 },
  { 81, 3 },
  { 81, 1 },
  { 79, 1 },
  { 82, 4 },
  { 82, 3 },
  { 83, 3 },
  { 83, 1 },
  { 84, 1 },
  { 84, 3 },
  { 79, 1 },
  { 79, 4 },
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
// 486 "parser.lemon"
{
	status->ret = kkmsp[0].minor.kk58;
}
// 1458 "parser.c"
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
      case 69:
// 490 "parser.lemon"
{
	kkgotominor.kk58 = kkmsp[0].minor.kk58;
}
// 1480 "parser.c"
        break;
      case 2:
// 496 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_zval_list(kkmsp[-1].minor.kk58, kkmsp[0].minor.kk58);
}
// 1487 "parser.c"
        break;
      case 3:
      case 66:
      case 73:
// 500 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_zval_list(NULL, kkmsp[0].minor.kk58);
}
// 1496 "parser.c"
        break;
      case 18:
// 564 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_if_statement(kkmsp[-5].minor.kk58, kkmsp[-3].minor.kk58, NULL, status->scanner_state);
  kk_destructor(25,&kkmsp[-7].minor);
  kk_destructor(26,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1509 "parser.c"
        break;
      case 19:
// 568 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_if_statement(kkmsp[-9].minor.kk58, kkmsp[-7].minor.kk58, kkmsp[-3].minor.kk58, status->scanner_state);
  kk_destructor(25,&kkmsp[-11].minor);
  kk_destructor(26,&kkmsp[-10].minor);
  kk_destructor(27,&kkmsp[-8].minor);
  kk_destructor(25,&kkmsp[-6].minor);
  kk_destructor(29,&kkmsp[-5].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1525 "parser.c"
        break;
      case 20:
// 574 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-5].minor.kk58, NULL, kkmsp[-3].minor.kk58, status->scanner_state);
  kk_destructor(25,&kkmsp[-9].minor);
  kk_destructor(30,&kkmsp[-8].minor);
  kk_destructor(32,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1539 "parser.c"
        break;
      case 21:
// 578 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, NULL, kkmsp[-7].minor.kk58, kkmsp[-5].minor.kk58, kkmsp[-3].minor.kk58, status->scanner_state);
  kk_destructor(25,&kkmsp[-11].minor);
  kk_destructor(30,&kkmsp[-10].minor);
  kk_destructor(32,&kkmsp[-8].minor);
  kk_destructor(26,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1554 "parser.c"
        break;
      case 22:
// 582 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, kkmsp[-9].minor.kk0, kkmsp[-5].minor.kk58, NULL, kkmsp[-3].minor.kk58, status->scanner_state);
  kk_destructor(25,&kkmsp[-11].minor);
  kk_destructor(30,&kkmsp[-10].minor);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(32,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1569 "parser.c"
        break;
      case 23:
// 586 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, kkmsp[-11].minor.kk0, kkmsp[-7].minor.kk58, kkmsp[-5].minor.kk58, kkmsp[-3].minor.kk58, status->scanner_state);
  kk_destructor(25,&kkmsp[-13].minor);
  kk_destructor(30,&kkmsp[-12].minor);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(32,&kkmsp[-8].minor);
  kk_destructor(26,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1585 "parser.c"
        break;
      case 24:
// 592 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_set_statement(kkmsp[-3].minor.kk0, kkmsp[-1].minor.kk58, status->scanner_state);
  kk_destructor(25,&kkmsp[-5].minor);
  kk_destructor(34,&kkmsp[-4].minor);
  kk_destructor(35,&kkmsp[-2].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1596 "parser.c"
        break;
      case 25:
// 598 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_empty_statement(status->scanner_state);
  kk_destructor(25,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1605 "parser.c"
        break;
      case 26:
// 604 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_echo_statement(kkmsp[-1].minor.kk58, status->scanner_state);
  kk_destructor(36,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[0].minor);
}
// 1614 "parser.c"
        break;
      case 27:
// 610 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_block_statement(kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk58, status->scanner_state);
  kk_destructor(25,&kkmsp[-7].minor);
  kk_destructor(38,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1627 "parser.c"
        break;
      case 28:
// 614 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_block_statement(kkmsp[-4].minor.kk0, NULL, status->scanner_state);
  kk_destructor(25,&kkmsp[-6].minor);
  kk_destructor(38,&kkmsp[-5].minor);
  kk_destructor(27,&kkmsp[-3].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1640 "parser.c"
        break;
      case 29:
// 620 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_cache_statement(kkmsp[-5].minor.kk0, NULL, kkmsp[-3].minor.kk58, status->scanner_state);
  kk_destructor(25,&kkmsp[-7].minor);
  kk_destructor(40,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1653 "parser.c"
        break;
      case 30:
// 624 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_cache_statement(kkmsp[-6].minor.kk0, kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk58, status->scanner_state);
  kk_destructor(25,&kkmsp[-8].minor);
  kk_destructor(40,&kkmsp[-7].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1666 "parser.c"
        break;
      case 31:
// 630 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_extends_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(25,&kkmsp[-3].minor);
  kk_destructor(43,&kkmsp[-2].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1676 "parser.c"
        break;
      case 32:
// 636 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_include_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(25,&kkmsp[-3].minor);
  kk_destructor(45,&kkmsp[-2].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1686 "parser.c"
        break;
      case 33:
// 642 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_do_statement(kkmsp[-1].minor.kk58, status->scanner_state);
  kk_destructor(25,&kkmsp[-3].minor);
  kk_destructor(46,&kkmsp[-2].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1696 "parser.c"
        break;
      case 34:
// 648 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_autoescape_statement(0, kkmsp[-3].minor.kk58, status->scanner_state);
  kk_destructor(25,&kkmsp[-7].minor);
  kk_destructor(47,&kkmsp[-6].minor);
  kk_destructor(48,&kkmsp[-5].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(49,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1710 "parser.c"
        break;
      case 35:
// 652 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_autoescape_statement(1, kkmsp[-3].minor.kk58, status->scanner_state);
  kk_destructor(25,&kkmsp[-7].minor);
  kk_destructor(47,&kkmsp[-6].minor);
  kk_destructor(50,&kkmsp[-5].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(49,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1724 "parser.c"
        break;
      case 36:
// 658 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_break_statement(status->scanner_state);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(51,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1734 "parser.c"
        break;
      case 37:
// 664 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_continue_statement(status->scanner_state);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(52,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1744 "parser.c"
        break;
      case 38:
// 670 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, kkmsp[0].minor.kk0, status->scanner_state);
}
// 1751 "parser.c"
        break;
      case 39:
// 676 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 1759 "parser.c"
        break;
      case 40:
// 680 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_SUB, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 1767 "parser.c"
        break;
      case 41:
// 684 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_ADD, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 1775 "parser.c"
        break;
      case 42:
// 688 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_MUL, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(17,&kkmsp[-1].minor);
}
// 1783 "parser.c"
        break;
      case 43:
// 692 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_DIV, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(16,&kkmsp[-1].minor);
}
// 1791 "parser.c"
        break;
      case 44:
// 696 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(18,&kkmsp[-1].minor);
}
// 1799 "parser.c"
        break;
      case 45:
// 700 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_AND, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(4,&kkmsp[-1].minor);
}
// 1807 "parser.c"
        break;
      case 46:
// 704 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_OR, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 1815 "parser.c"
        break;
      case 47:
// 708 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_CONCAT, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
// 1823 "parser.c"
        break;
      case 48:
// 712 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_PIPE, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(15,&kkmsp[-1].minor);
}
// 1831 "parser.c"
        break;
      case 49:
// 716 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_RANGE, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(3,&kkmsp[-1].minor);
}
// 1839 "parser.c"
        break;
      case 50:
// 720 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_EQUALS, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
}
// 1847 "parser.c"
        break;
      case 51:
// 724 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, kkmsp[-3].minor.kk58, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-2].minor);
  kk_destructor(22,&kkmsp[-1].minor);
  kk_destructor(54,&kkmsp[0].minor);
}
// 1857 "parser.c"
        break;
      case 52:
// 728 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_ISSET, kkmsp[-2].minor.kk58, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-1].minor);
  kk_destructor(54,&kkmsp[0].minor);
}
// 1866 "parser.c"
        break;
      case 53:
// 732 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_IS, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(6,&kkmsp[-1].minor);
}
// 1874 "parser.c"
        break;
      case 54:
// 736 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(8,&kkmsp[-1].minor);
}
// 1882 "parser.c"
        break;
      case 55:
// 740 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(13,&kkmsp[-1].minor);
}
// 1890 "parser.c"
        break;
      case 56:
// 744 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(14,&kkmsp[-1].minor);
}
// 1898 "parser.c"
        break;
      case 57:
// 748 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_LESS, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
}
// 1906 "parser.c"
        break;
      case 58:
// 752 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_GREATER, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
}
// 1914 "parser.c"
        break;
      case 59:
// 756 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(11,&kkmsp[-1].minor);
}
// 1922 "parser.c"
        break;
      case 60:
// 760 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(12,&kkmsp[-1].minor);
}
// 1930 "parser.c"
        break;
      case 61:
// 764 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_DOT, kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(24,&kkmsp[-1].minor);
}
// 1938 "parser.c"
        break;
      case 62:
// 768 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 1946 "parser.c"
        break;
      case 63:
// 772 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, kkmsp[-1].minor.kk58, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(55,&kkmsp[0].minor);
}
// 1955 "parser.c"
        break;
      case 64:
// 776 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk58, NULL, status->scanner_state);
  kk_destructor(2,&kkmsp[-2].minor);
  kk_destructor(56,&kkmsp[0].minor);
}
// 1964 "parser.c"
        break;
      case 65:
      case 72:
// 782 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_zval_list(kkmsp[-2].minor.kk58, kkmsp[0].minor.kk58);
  kk_destructor(1,&kkmsp[-1].minor);
}
// 1973 "parser.c"
        break;
      case 67:
      case 75:
// 790 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_named_item(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk58, status->scanner_state);
  kk_destructor(57,&kkmsp[-1].minor);
}
// 1982 "parser.c"
        break;
      case 68:
      case 74:
// 794 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_named_item(NULL, kkmsp[0].minor.kk58, status->scanner_state);
}
// 1990 "parser.c"
        break;
      case 70:
// 804 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_func_call(kkmsp[-3].minor.kk58, kkmsp[-1].minor.kk58, status->scanner_state);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(55,&kkmsp[0].minor);
}
// 1999 "parser.c"
        break;
      case 71:
// 808 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_func_call(kkmsp[-2].minor.kk58, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
  kk_destructor(55,&kkmsp[0].minor);
}
// 2008 "parser.c"
        break;
      case 76:
// 832 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2015 "parser.c"
        break;
      case 77:
// 836 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, kkmsp[-3].minor.kk58, kkmsp[-1].minor.kk58, status->scanner_state);
  kk_destructor(2,&kkmsp[-2].minor);
  kk_destructor(56,&kkmsp[0].minor);
}
// 2024 "parser.c"
        break;
      case 78:
// 840 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2031 "parser.c"
        break;
      case 79:
// 844 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_literal_zval(PHVOLT_T_STRING, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2038 "parser.c"
        break;
      case 80:
// 848 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, kkmsp[0].minor.kk0, status->scanner_state);
}
// 2045 "parser.c"
        break;
      case 81:
// 852 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  kk_destructor(59,&kkmsp[0].minor);
}
// 2053 "parser.c"
        break;
      case 82:
// 856 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  kk_destructor(48,&kkmsp[0].minor);
}
// 2061 "parser.c"
        break;
      case 83:
// 860 "parser.lemon"
{
	kkgotominor.kk58 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  kk_destructor(50,&kkmsp[0].minor);
}
// 2069 "parser.c"
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
// 431 "parser.lemon"

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

// 2157 "parser.c"
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