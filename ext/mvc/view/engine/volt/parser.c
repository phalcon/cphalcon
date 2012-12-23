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

				if (zend_hash_get_current_data_ex(list, (void**)&item, &pos) == FAILURE) {
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


// 353 "parser.c"
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
#define KKNOCODE 79
#define KKACTIONTYPE unsigned short int
#define phvolt_KTOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_KTOKENTYPE kk0;
  zval* kk72;
  int kk157;
} KKMINORTYPE;
#define KKSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = kkpParser->status
#define phvolt_ARG_STORE kkpParser->status = status
#define KKNSTATE 186
#define KKNRULE 77
#define KKERRORSYMBOL 56
#define KKERRSYMDT kk157
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
 /*     0 */    86,   62,   54,   56,   66,   64,   68,   74,   76,   78,
 /*    10 */    80,   70,   72,   60,   50,   48,   52,   46,   43,   58,
 /*    20 */    17,   84,   82,  103,  163,   33,  186,   86,   62,   54,
 /*    30 */    56,   66,   64,   68,   74,   76,   78,   80,   70,   72,
 /*    40 */    60,   50,   48,   52,   46,   43,   58,   32,   84,   82,
 /*    50 */   103,  179,  174,   30,   86,   62,   54,   56,   66,   64,
 /*    60 */    68,   74,   76,   78,   80,   70,   72,   60,   50,   48,
 /*    70 */    52,   46,   43,   58,  170,   84,   82,   22,   95,   18,
 /*    80 */    99,  103,   86,   62,   54,   56,   66,   64,   68,   74,
 /*    90 */    76,   78,   80,   70,   72,   60,   50,   48,   52,   46,
 /*   100 */    43,   58,   24,   84,   82,   31,   41,   42,   28,  103,
 /*   110 */    86,   62,   54,   56,   66,   64,   68,   74,   76,   78,
 /*   120 */    80,   70,   72,   60,   50,   48,   52,   46,   43,   58,
 /*   130 */   124,   84,   82,  103,   86,   62,   54,   56,   66,   64,
 /*   140 */    68,   74,   76,   78,   80,   70,   72,   60,   50,   48,
 /*   150 */    52,   46,   43,   58,   85,   84,   82,  103,   88,  115,
 /*   160 */    37,   86,   62,   54,   56,   66,   64,   68,   74,   76,
 /*   170 */    78,   80,   70,   72,   60,   50,   48,   52,   46,   43,
 /*   180 */    58,   93,   84,   82,   45,   47,  148,  103,  103,   86,
 /*   190 */    62,   54,   56,   66,   64,   68,   74,   76,   78,   80,
 /*   200 */    70,   72,   60,   50,   48,   52,   46,   43,   58,   39,
 /*   210 */    84,   82,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   220 */    11,   12,   13,   14,  151,   84,   82,   86,   62,   54,
 /*   230 */    56,   66,   64,   68,   74,   76,   78,   80,   70,   72,
 /*   240 */    60,   50,   48,   52,   46,   43,   58,   49,   84,   82,
 /*   250 */   103,   51,  165,   40,  103,   86,   62,   54,   56,   66,
 /*   260 */    64,   68,   74,   76,   78,   80,   70,   72,   60,   50,
 /*   270 */    48,   52,   46,   43,   58,   53,   84,   82,  103,   55,
 /*   280 */   181,  101,  103,   86,   62,   54,   56,   66,   64,   68,
 /*   290 */    74,   76,   78,   80,   70,   72,   60,   50,   48,   52,
 /*   300 */    46,   43,   58,  117,   84,   82,   54,   56,   66,   64,
 /*   310 */    68,   74,   76,   78,   80,   70,   72,   60,   50,   48,
 /*   320 */    52,   46,   43,   58,  127,   84,   82,   66,   64,   68,
 /*   330 */    74,   76,   78,   80,   70,   72,   60,   50,   48,   52,
 /*   340 */    46,   43,   58,  134,   84,   82,  264,    1,    2,  153,
 /*   350 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   360 */    14,  128,   19,  153,    4,    5,    6,    7,    8,    9,
 /*   370 */    10,   11,   12,   13,   14,   25,  153,    4,    5,    6,
 /*   380 */     7,    8,    9,   10,   11,   12,   13,   14,   34,  153,
 /*   390 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   400 */    14,  129,  153,    4,    5,    6,    7,    8,    9,   10,
 /*   410 */    11,   12,   13,   14,  136,  153,    4,    5,    6,    7,
 /*   420 */     8,    9,   10,   11,   12,   13,   14,  156,  153,    4,
 /*   430 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   440 */   166,  153,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   450 */    12,   13,   14,  175,  153,    4,    5,    6,    7,    8,
 /*   460 */     9,   10,   11,   12,   13,   14,  182,  153,    4,    5,
 /*   470 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   94,
 /*   480 */    95,   96,  111,  103,   16,  125,   21,   23,   29,   46,
 /*   490 */    43,   58,   38,   84,   82,  132,  126,   44,  133,  121,
 /*   500 */    91,  140,   85,  143,  146,  103,  112,  120,  104,   50,
 /*   510 */    48,   52,   46,   43,   58,   15,   84,   82,  139,  105,
 /*   520 */   141,  106,   94,   20,   57,  123,  149,  103,   94,  107,
 /*   530 */   108,  109,  110,   26,  149,   59,   35,  152,  103,  160,
 /*   540 */    44,  187,   89,   91,  149,  152,   44,  149,   89,   91,
 /*   550 */   149,  104,  135,   61,  142,  152,  103,  104,  152,  144,
 /*   560 */   130,  152,  105,   98,  116,   94,   15,  154,  105,  119,
 /*   570 */   106,  149,  107,  108,  109,  110,  171,  149,  107,  108,
 /*   580 */   109,  110,  152,   44,   63,   89,   91,  103,  152,   65,
 /*   590 */    67,  137,  103,  103,  104,   60,   50,   48,   52,   46,
 /*   600 */    43,   58,  149,   84,   82,  105,  145,  106,   94,  157,
 /*   610 */   155,  122,   97,  152,   94,  107,  108,  109,  110,  159,
 /*   620 */   149,   69,  167,  162,  103,  176,   44,  183,   89,   91,
 /*   630 */   169,  152,   44,  149,   89,   91,  149,  104,  149,   71,
 /*   640 */   172,  178,  103,  104,  152,  185,  157,  152,  105,  152,
 /*   650 */   100,  157,  114,  157,  105,  157,  116,  157,  107,  108,
 /*   660 */   109,  110,  157,  157,  107,  108,  109,  110,  157,  157,
 /*   670 */    16,  125,   27,   73,   29,  157,  103,   75,   38,  157,
 /*   680 */   103,  157,  126,  157,  133,  102,  157,  140,  103,  143,
 /*   690 */   146,   16,  125,   77,   79,   29,  103,  103,   36,   38,
 /*   700 */   113,   81,  157,  126,  103,  133,   83,  157,  140,  103,
 /*   710 */   143,  146,  157,  157,   16,  125,  157,   87,   29,  157,
 /*   720 */   103,   90,   38,  157,  103,  157,  126,  131,  133,   92,
 /*   730 */   157,  140,  103,  143,  146,   16,  125,  157,  118,   29,
 /*   740 */   157,  103,  157,   38,  157,  147,  157,  126,  103,  133,
 /*   750 */   138,  157,  140,  150,  143,  146,  103,  164,   16,  125,
 /*   760 */   103,  173,   29,  157,  103,  180,   38,  157,  103,  157,
 /*   770 */   126,  157,  133,  158,  157,  140,  157,  143,  146,   16,
 /*   780 */   125,  157,  157,   29,  157,  157,  157,   38,  157,  157,
 /*   790 */   157,  126,  161,  133,  157,  157,  140,  157,  143,  146,
 /*   800 */    16,  125,  157,  157,   29,  157,  157,  168,   38,  157,
 /*   810 */   157,  157,  126,  157,  133,  157,  157,  140,  157,  143,
 /*   820 */   146,  157,  157,   16,  125,  157,  157,   29,  157,  157,
 /*   830 */   177,   38,  157,  157,  157,  126,  157,  133,  157,  157,
 /*   840 */   140,  157,  143,  146,   16,  125,  157,  157,   29,  157,
 /*   850 */   157,  184,   38,  157,  157,  157,  126,  157,  133,  157,
 /*   860 */   157,  140,  157,  143,  146,  157,  157,   16,  125,  157,
 /*   870 */   157,   29,  157,  157,  157,   38,  157,  157,  157,  126,
 /*   880 */   157,  133,  157,  157,  140,  157,  143,  146,
};
static KKCODETYPE kk_lookahead[] = {
 /*     0 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*    10 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*    20 */    72,   23,   24,   75,   26,   27,    0,    2,    3,    4,
 /*    30 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*    40 */    15,   16,   17,   18,   19,   20,   21,   72,   23,   24,
 /*    50 */    75,   26,   27,   31,    2,    3,    4,    5,    6,    7,
 /*    60 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    70 */    18,   19,   20,   21,    1,   23,   24,   27,   72,   27,
 /*    80 */    74,   75,    2,    3,    4,    5,    6,    7,    8,    9,
 /*    90 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   100 */    20,   21,   27,   23,   24,   32,   72,   27,   27,   75,
 /*   110 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   120 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   130 */    72,   23,   24,   75,    2,    3,    4,    5,    6,    7,
 /*   140 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   150 */    18,   19,   20,   21,   72,   23,   24,   75,   50,   77,
 /*   160 */    27,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   170 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   180 */    21,   49,   23,   24,   72,   72,   27,   75,   75,    2,
 /*   190 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   200 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   31,
 /*   210 */    23,   24,   60,   61,   62,   63,   64,   65,   66,   67,
 /*   220 */    68,   69,   70,   71,   37,   23,   24,    2,    3,    4,
 /*   230 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   240 */    15,   16,   17,   18,   19,   20,   21,   72,   23,   24,
 /*   250 */    75,   72,   27,   35,   75,    2,    3,    4,    5,    6,
 /*   260 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   270 */    17,   18,   19,   20,   21,   72,   23,   24,   75,   72,
 /*   280 */    27,   51,   75,    2,    3,    4,    5,    6,    7,    8,
 /*   290 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   300 */    19,   20,   21,   51,   23,   24,    4,    5,    6,    7,
 /*   310 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   320 */    18,   19,   20,   21,   31,   23,   24,    6,    7,    8,
 /*   330 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   340 */    19,   20,   21,   31,   23,   24,   57,   58,   59,   60,
 /*   350 */    61,   62,   63,   64,   65,   66,   67,   68,   69,   70,
 /*   360 */    71,   27,   59,   60,   61,   62,   63,   64,   65,   66,
 /*   370 */    67,   68,   69,   70,   71,   59,   60,   61,   62,   63,
 /*   380 */    64,   65,   66,   67,   68,   69,   70,   71,   59,   60,
 /*   390 */    61,   62,   63,   64,   65,   66,   67,   68,   69,   70,
 /*   400 */    71,   59,   60,   61,   62,   63,   64,   65,   66,   67,
 /*   410 */    68,   69,   70,   71,   59,   60,   61,   62,   63,   64,
 /*   420 */    65,   66,   67,   68,   69,   70,   71,   59,   60,   61,
 /*   430 */    62,   63,   64,   65,   66,   67,   68,   69,   70,   71,
 /*   440 */    59,   60,   61,   62,   63,   64,   65,   66,   67,   68,
 /*   450 */    69,   70,   71,   59,   60,   61,   62,   63,   64,   65,
 /*   460 */    66,   67,   68,   69,   70,   71,   59,   60,   61,   62,
 /*   470 */    63,   64,   65,   66,   67,   68,   69,   70,   71,    2,
 /*   480 */    72,   73,   74,   75,   26,   27,   28,   29,   30,   19,
 /*   490 */    20,   21,   34,   23,   24,   27,   38,   20,   40,   22,
 /*   500 */    23,   43,   72,   45,   46,   75,   76,   77,   31,   16,
 /*   510 */    17,   18,   19,   20,   21,   25,   23,   24,   27,   42,
 /*   520 */    44,   44,    2,   25,   72,   48,   36,   75,    2,   52,
 /*   530 */    53,   54,   55,   25,   36,   72,   25,   47,   75,   25,
 /*   540 */    20,    0,   22,   23,   36,   47,   20,   36,   22,   23,
 /*   550 */    36,   31,   27,   72,   27,   47,   75,   31,   47,   44,
 /*   560 */    25,   47,   42,    1,   44,    2,   25,   42,   42,   49,
 /*   570 */    44,   36,   52,   53,   54,   55,   31,   36,   52,   53,
 /*   580 */    54,   55,   47,   20,   72,   22,   23,   75,   47,   72,
 /*   590 */    72,   25,   75,   75,   31,   15,   16,   17,   18,   19,
 /*   600 */    20,   21,   36,   23,   24,   42,   27,   44,    2,   25,
 /*   610 */    27,   48,   50,   47,    2,   52,   53,   54,   55,   27,
 /*   620 */    36,   72,   25,   27,   75,   25,   20,   25,   22,   23,
 /*   630 */    27,   47,   20,   36,   22,   23,   36,   31,   36,   72,
 /*   640 */    32,   27,   75,   31,   47,   27,   78,   47,   42,   47,
 /*   650 */    44,   78,    1,   78,   42,   78,   44,   78,   52,   53,
 /*   660 */    54,   55,   78,   78,   52,   53,   54,   55,   78,   78,
 /*   670 */    26,   27,   28,   72,   30,   78,   75,   72,   34,   78,
 /*   680 */    75,   78,   38,   78,   40,   72,   78,   43,   75,   45,
 /*   690 */    46,   26,   27,   72,   72,   30,   75,   75,   33,   34,
 /*   700 */    49,   72,   78,   38,   75,   40,   72,   78,   43,   75,
 /*   710 */    45,   46,   78,   78,   26,   27,   78,   72,   30,   78,
 /*   720 */    75,   72,   34,   78,   75,   78,   38,   39,   40,   72,
 /*   730 */    78,   43,   75,   45,   46,   26,   27,   78,   72,   30,
 /*   740 */    78,   75,   78,   34,   78,   72,   78,   38,   75,   40,
 /*   750 */    41,   78,   43,   72,   45,   46,   75,   72,   26,   27,
 /*   760 */    75,   72,   30,   78,   75,   72,   34,   78,   75,   78,
 /*   770 */    38,   78,   40,   41,   78,   43,   78,   45,   46,   26,
 /*   780 */    27,   78,   78,   30,   78,   78,   78,   34,   78,   78,
 /*   790 */    78,   38,   39,   40,   78,   78,   43,   78,   45,   46,
 /*   800 */    26,   27,   78,   78,   30,   78,   78,   33,   34,   78,
 /*   810 */    78,   78,   38,   78,   40,   78,   78,   43,   78,   45,
 /*   820 */    46,   78,   78,   26,   27,   78,   78,   30,   78,   78,
 /*   830 */    33,   34,   78,   78,   78,   38,   78,   40,   78,   78,
 /*   840 */    43,   78,   45,   46,   26,   27,   78,   78,   30,   78,
 /*   850 */    78,   33,   34,   78,   78,   78,   38,   78,   40,   78,
 /*   860 */    78,   43,   78,   45,   46,   78,   78,   26,   27,   78,
 /*   870 */    78,   30,   78,   78,   78,   34,   78,   78,   78,   38,
 /*   880 */    78,   40,   78,   78,   43,   78,   45,   46,
};
#define KK_SHIFT_USE_DFLT (-3)
static short kk_shift_ofst[] = {
 /*     0 */   490,   26,  541,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
 /*    10 */    -3,   -3,   -3,   -3,   -3,  841,  526,   52,  490,  498,
 /*    20 */   458,   50,   -3,   75,  490,  508,  644,   81,   -3,   22,
 /*    30 */    73,  526,   -2,  490,  511,  665,  133,   -3,  178,  218,
 /*    40 */   526,   80,   -3,  526,  526,  202,  526,  202,  526,  470,
 /*    50 */   526,  470,  526,  470,  526,  321,  526,  321,  526,  202,
 /*    60 */   526,  493,  526,  302,  526,  580,  477,  580,  526,  580,
 /*    70 */   526,  580,  526,  580,  526,  580,  526,  580,  526,  580,
 /*    80 */   526,  580,  526,   -3,  520,  281,  526,  108,   -3,  526,
 /*    90 */   202,  526,  132,   -3,  606,  281,  562,   -3,  606,   -3,
 /*   100 */   230,  526,  281,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
 /*   110 */    -3,   -3,  651,   -3,  612,   -3,  252,  526,  281,   -3,
 /*   120 */    -3,  563,   -3,   -3,  202,   -3,  293,  334,  514,  535,
 /*   130 */   688,  468,   -3,  312,  525,  490,  566,  709,  491,   -3,
 /*   140 */   476,  527,   -3,  515,  579,   -3,  526,  159,   -3,  526,
 /*   150 */   187,   -3,   -3,   -3,  583,  490,  584,  732,  592,   -3,
 /*   160 */   753,  596,   -3,  526,  225,  490,  597,  774,  603,   -3,
 /*   170 */   545,  608,  526,   25,  490,  600,  797,  614,   -3,  526,
 /*   180 */   253,  490,  602,  818,  618,   -3,
};
#define KK_REDUCE_USE_DFLT (-53)
static short kk_reduce_ofst[] = {
 /*     0 */   289,  -53,  152,  -53,  -53,  -53,  -53,  -53,  -53,  -53,
 /*    10 */   -53,  -53,  -53,  -53,  -53,  -53,  -52,  -53,  303,  152,
 /*    20 */   -53,  -53,  -53,  -53,  316,  152,  -53,  -53,  -53,  -53,
 /*    30 */   -53,  -25,  -53,  329,  152,  -53,  -53,  -53,  -53,  -53,
 /*    40 */    34,  -53,  -53,   58,  112,  -53,  113,  -53,  175,  -53,
 /*    50 */   179,  -53,  203,  -53,  207,  -53,  452,  -53,  463,  -53,
 /*    60 */   481,  -53,  512,  -53,  517,  -53,  518,  -53,  549,  -53,
 /*    70 */   567,  -53,  601,  -53,  605,  -53,  621,  -53,  622,  -53,
 /*    80 */   629,  -53,  634,  -53,  430,  -53,  645,  -53,  -53,  649,
 /*    90 */   -53,  657,  -53,  -53,  408,  -53,  -53,  -53,    6,  -53,
 /*   100 */   -53,  613,  -53,  -53,  -53,  -53,  -53,  -53,  -53,  -53,
 /*   110 */   -53,  -53,  -53,  -53,   82,  -53,  -53,  666,  -53,  -53,
 /*   120 */   -53,  649,  -53,  -53,  -53,  -53,  -53,  -53,  342,  152,
 /*   130 */   -53,  -53,  -53,  -53,  -53,  355,  152,  -53,  -53,  -53,
 /*   140 */   -53,  -53,  -53,  -53,  -53,  -53,  673,  -53,  -53,  681,
 /*   150 */   -53,  -53,  -53,  -53,  -53,  368,  152,  -53,  -53,  -53,
 /*   160 */   -53,  -53,  -53,  685,  -53,  381,  152,  -53,  -53,  -53,
 /*   170 */   -53,  -53,  689,  -53,  394,  152,  -53,  -53,  -53,  693,
 /*   180 */   -53,  407,  152,  -53,  -53,  -53,
};
static KKACTIONTYPE kk_default[] = {
 /*     0 */   263,  263,  263,  188,  190,  191,  192,  193,  194,  195,
 /*    10 */   196,  197,  198,  199,  200,  263,  263,  263,  263,  263,
 /*    20 */   263,  263,  201,  263,  263,  263,  263,  263,  202,  263,
 /*    30 */   263,  263,  263,  263,  263,  263,  263,  203,  263,  263,
 /*    40 */   263,  263,  207,  263,  263,  218,  263,  220,  263,  221,
 /*    50 */   263,  222,  263,  223,  263,  224,  263,  225,  263,  226,
 /*    60 */   263,  227,  263,  228,  263,  229,  263,  232,  263,  233,
 /*    70 */   263,  234,  263,  235,  263,  236,  263,  237,  263,  238,
 /*    80 */   263,  239,  263,  240,  263,  253,  263,  263,  256,  263,
 /*    90 */   241,  263,  263,  242,  263,  247,  263,  243,  263,  244,
 /*   100 */   258,  263,  246,  248,  255,  257,  258,  259,  260,  261,
 /*   110 */   262,  245,  263,  249,  263,  251,  258,  263,  254,  250,
 /*   120 */   252,  263,  230,  231,  219,  208,  263,  263,  263,  263,
 /*   130 */   263,  263,  210,  263,  263,  263,  263,  263,  263,  212,
 /*   140 */   263,  263,  214,  263,  263,  215,  263,  263,  216,  263,
 /*   150 */   263,  209,  217,  189,  263,  263,  263,  263,  263,  213,
 /*   160 */   263,  263,  211,  263,  263,  263,  263,  263,  263,  204,
 /*   170 */   263,  263,  263,  263,  263,  263,  263,  263,  205,  263,
 /*   180 */   263,  263,  263,  263,  263,  206,
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
  "STRING",        "INCLUDE",       "DO",            "RAW_FRAGMENT",
  "DEFINED",       "BRACKET_CLOSE",  "SBRACKET_CLOSE",  "DOUBLECOLON", 
  "DOUBLE",        "NULL",          "FALSE",         "TRUE",        
  "error",         "program",       "volt_language",  "statement_list",
  "statement",     "raw_fragment",  "if_statement",  "for_statement",
  "set_statement",  "echo_statement",  "block_statement",  "cache_statement",
  "extends_statement",  "include_statement",  "do_statement",  "empty_statement",
  "expr",          "array_list",    "array_item",    "function_call",
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
 /*  14 */ "statement ::= empty_statement",
 /*  15 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  16 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  17 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  18 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  19 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  20 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  21 */ "set_statement ::= OPEN_DELIMITER SET IDENTIFIER ASSIGN expr CLOSE_DELIMITER",
 /*  22 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  23 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  24 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  25 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  26 */ "cache_statement ::= OPEN_DELIMITER CACHE IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  27 */ "cache_statement ::= OPEN_DELIMITER CACHE IDENTIFIER INTEGER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  28 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  29 */ "include_statement ::= OPEN_DELIMITER INCLUDE STRING CLOSE_DELIMITER",
 /*  30 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  31 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  32 */ "expr ::= MINUS expr",
 /*  33 */ "expr ::= expr MINUS expr",
 /*  34 */ "expr ::= expr PLUS expr",
 /*  35 */ "expr ::= expr TIMES expr",
 /*  36 */ "expr ::= expr DIVIDE expr",
 /*  37 */ "expr ::= expr MOD expr",
 /*  38 */ "expr ::= expr AND expr",
 /*  39 */ "expr ::= expr OR expr",
 /*  40 */ "expr ::= expr CONCAT expr",
 /*  41 */ "expr ::= expr PIPE expr",
 /*  42 */ "expr ::= expr RANGE expr",
 /*  43 */ "expr ::= expr EQUALS expr",
 /*  44 */ "expr ::= expr IS NOT DEFINED",
 /*  45 */ "expr ::= expr IS DEFINED",
 /*  46 */ "expr ::= expr IS expr",
 /*  47 */ "expr ::= expr NOTEQUALS expr",
 /*  48 */ "expr ::= expr IDENTICAL expr",
 /*  49 */ "expr ::= expr NOTIDENTICAL expr",
 /*  50 */ "expr ::= expr LESS expr",
 /*  51 */ "expr ::= expr GREATER expr",
 /*  52 */ "expr ::= expr GREATEREQUAL expr",
 /*  53 */ "expr ::= expr LESSEQUAL expr",
 /*  54 */ "expr ::= expr DOT expr",
 /*  55 */ "expr ::= NOT expr",
 /*  56 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /*  57 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /*  58 */ "array_list ::= array_list COMMA array_item",
 /*  59 */ "array_list ::= array_item",
 /*  60 */ "array_item ::= STRING DOUBLECOLON expr",
 /*  61 */ "array_item ::= expr",
 /*  62 */ "expr ::= function_call",
 /*  63 */ "function_call ::= expr BRACKET_OPEN argument_list BRACKET_CLOSE",
 /*  64 */ "function_call ::= expr BRACKET_OPEN BRACKET_CLOSE",
 /*  65 */ "argument_list ::= argument_list COMMA argument_item",
 /*  66 */ "argument_list ::= argument_item",
 /*  67 */ "argument_item ::= expr",
 /*  68 */ "argument_item ::= STRING DOUBLECOLON expr",
 /*  69 */ "expr ::= IDENTIFIER",
 /*  70 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /*  71 */ "expr ::= INTEGER",
 /*  72 */ "expr ::= STRING",
 /*  73 */ "expr ::= DOUBLE",
 /*  74 */ "expr ::= NULL",
 /*  75 */ "expr ::= FALSE",
 /*  76 */ "expr ::= TRUE",
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
// 429 "parser.lemon"
{
	if ((kkpminor->kk0)) {
		if ((kkpminor->kk0)->free_flag) {
			efree((kkpminor->kk0)->token);
		}
		efree((kkpminor->kk0));
	}
}
// 1027 "parser.c"
      break;
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
    case 75:
    case 76:
    case 77:
// 446 "parser.lemon"
{ zval_ptr_dtor(&(kkpminor->kk72)); }
// 1049 "parser.c"
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
  { 57, 1 },
  { 58, 1 },
  { 59, 2 },
  { 59, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 62, 8 },
  { 62, 12 },
  { 63, 10 },
  { 63, 12 },
  { 63, 12 },
  { 63, 14 },
  { 64, 6 },
  { 71, 2 },
  { 65, 3 },
  { 66, 8 },
  { 66, 7 },
  { 67, 8 },
  { 67, 9 },
  { 68, 4 },
  { 69, 4 },
  { 70, 4 },
  { 61, 1 },
  { 72, 2 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 4 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 2 },
  { 72, 3 },
  { 72, 3 },
  { 73, 3 },
  { 73, 1 },
  { 74, 3 },
  { 74, 1 },
  { 72, 1 },
  { 75, 4 },
  { 75, 3 },
  { 76, 3 },
  { 76, 1 },
  { 77, 1 },
  { 77, 3 },
  { 72, 1 },
  { 72, 4 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
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
// 438 "parser.lemon"
{
	status->ret = kkmsp[0].minor.kk72;
}
// 1343 "parser.c"
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
      case 62:
// 442 "parser.lemon"
{
	kkgotominor.kk72 = kkmsp[0].minor.kk72;
}
// 1362 "parser.c"
        break;
      case 2:
// 448 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_zval_list(kkmsp[-1].minor.kk72, kkmsp[0].minor.kk72);
}
// 1369 "parser.c"
        break;
      case 3:
      case 59:
      case 66:
// 452 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_zval_list(NULL, kkmsp[0].minor.kk72);
}
// 1378 "parser.c"
        break;
      case 15:
// 504 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_if_statement(kkmsp[-5].minor.kk72, kkmsp[-3].minor.kk72, NULL, status->scanner_state);
  kk_destructor(25,&kkmsp[-7].minor);
  kk_destructor(26,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(28,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1391 "parser.c"
        break;
      case 16:
// 508 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_if_statement(kkmsp[-9].minor.kk72, kkmsp[-7].minor.kk72, kkmsp[-3].minor.kk72, status->scanner_state);
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
// 1407 "parser.c"
        break;
      case 17:
// 514 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-5].minor.kk72, NULL, kkmsp[-3].minor.kk72, status->scanner_state);
  kk_destructor(25,&kkmsp[-9].minor);
  kk_destructor(30,&kkmsp[-8].minor);
  kk_destructor(32,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1421 "parser.c"
        break;
      case 18:
// 518 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, NULL, kkmsp[-7].minor.kk72, kkmsp[-5].minor.kk72, kkmsp[-3].minor.kk72, status->scanner_state);
  kk_destructor(25,&kkmsp[-11].minor);
  kk_destructor(30,&kkmsp[-10].minor);
  kk_destructor(32,&kkmsp[-8].minor);
  kk_destructor(26,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1436 "parser.c"
        break;
      case 19:
// 522 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, kkmsp[-9].minor.kk0, kkmsp[-5].minor.kk72, NULL, kkmsp[-3].minor.kk72, status->scanner_state);
  kk_destructor(25,&kkmsp[-11].minor);
  kk_destructor(30,&kkmsp[-10].minor);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(32,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1451 "parser.c"
        break;
      case 20:
// 526 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, kkmsp[-11].minor.kk0, kkmsp[-7].minor.kk72, kkmsp[-5].minor.kk72, kkmsp[-3].minor.kk72, status->scanner_state);
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
// 1467 "parser.c"
        break;
      case 21:
// 532 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_set_statement(kkmsp[-3].minor.kk0, kkmsp[-1].minor.kk72, status->scanner_state);
  kk_destructor(25,&kkmsp[-5].minor);
  kk_destructor(34,&kkmsp[-4].minor);
  kk_destructor(35,&kkmsp[-2].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1478 "parser.c"
        break;
      case 22:
// 538 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_empty_statement(status->scanner_state);
  kk_destructor(25,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1487 "parser.c"
        break;
      case 23:
// 544 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_echo_statement(kkmsp[-1].minor.kk72, status->scanner_state);
  kk_destructor(36,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[0].minor);
}
// 1496 "parser.c"
        break;
      case 24:
// 550 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_block_statement(kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk72, status->scanner_state);
  kk_destructor(25,&kkmsp[-7].minor);
  kk_destructor(38,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1509 "parser.c"
        break;
      case 25:
// 554 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_block_statement(kkmsp[-4].minor.kk0, NULL, status->scanner_state);
  kk_destructor(25,&kkmsp[-6].minor);
  kk_destructor(38,&kkmsp[-5].minor);
  kk_destructor(27,&kkmsp[-3].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1522 "parser.c"
        break;
      case 26:
// 560 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_cache_statement(kkmsp[-5].minor.kk0, NULL, kkmsp[-3].minor.kk72, status->scanner_state);
  kk_destructor(25,&kkmsp[-7].minor);
  kk_destructor(40,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1535 "parser.c"
        break;
      case 27:
// 564 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_cache_statement(kkmsp[-6].minor.kk0, kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk72, status->scanner_state);
  kk_destructor(25,&kkmsp[-8].minor);
  kk_destructor(40,&kkmsp[-7].minor);
  kk_destructor(27,&kkmsp[-4].minor);
  kk_destructor(25,&kkmsp[-2].minor);
  kk_destructor(41,&kkmsp[-1].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1548 "parser.c"
        break;
      case 28:
// 570 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_extends_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(25,&kkmsp[-3].minor);
  kk_destructor(43,&kkmsp[-2].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1558 "parser.c"
        break;
      case 29:
// 576 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_include_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(25,&kkmsp[-3].minor);
  kk_destructor(45,&kkmsp[-2].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1568 "parser.c"
        break;
      case 30:
// 582 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_do_statement(kkmsp[-1].minor.kk72, status->scanner_state);
  kk_destructor(25,&kkmsp[-3].minor);
  kk_destructor(46,&kkmsp[-2].minor);
  kk_destructor(27,&kkmsp[0].minor);
}
// 1578 "parser.c"
        break;
      case 31:
// 588 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, kkmsp[0].minor.kk0, status->scanner_state);
}
// 1585 "parser.c"
        break;
      case 32:
// 594 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 1593 "parser.c"
        break;
      case 33:
// 598 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_SUB, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 1601 "parser.c"
        break;
      case 34:
// 602 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_ADD, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 1609 "parser.c"
        break;
      case 35:
// 606 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_MUL, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(17,&kkmsp[-1].minor);
}
// 1617 "parser.c"
        break;
      case 36:
// 610 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_DIV, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(16,&kkmsp[-1].minor);
}
// 1625 "parser.c"
        break;
      case 37:
// 614 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(18,&kkmsp[-1].minor);
}
// 1633 "parser.c"
        break;
      case 38:
// 618 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_AND, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(4,&kkmsp[-1].minor);
}
// 1641 "parser.c"
        break;
      case 39:
// 622 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_OR, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 1649 "parser.c"
        break;
      case 40:
// 626 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_CONCAT, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
// 1657 "parser.c"
        break;
      case 41:
// 630 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_PIPE, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(15,&kkmsp[-1].minor);
}
// 1665 "parser.c"
        break;
      case 42:
// 634 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_RANGE, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(3,&kkmsp[-1].minor);
}
// 1673 "parser.c"
        break;
      case 43:
// 638 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_EQUALS, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
}
// 1681 "parser.c"
        break;
      case 44:
// 642 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, kkmsp[-3].minor.kk72, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-2].minor);
  kk_destructor(22,&kkmsp[-1].minor);
  kk_destructor(48,&kkmsp[0].minor);
}
// 1691 "parser.c"
        break;
      case 45:
// 646 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_ISSET, kkmsp[-2].minor.kk72, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-1].minor);
  kk_destructor(48,&kkmsp[0].minor);
}
// 1700 "parser.c"
        break;
      case 46:
// 650 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_IS, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(6,&kkmsp[-1].minor);
}
// 1708 "parser.c"
        break;
      case 47:
// 654 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(8,&kkmsp[-1].minor);
}
// 1716 "parser.c"
        break;
      case 48:
// 658 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(13,&kkmsp[-1].minor);
}
// 1724 "parser.c"
        break;
      case 49:
// 662 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(14,&kkmsp[-1].minor);
}
// 1732 "parser.c"
        break;
      case 50:
// 666 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_LESS, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
}
// 1740 "parser.c"
        break;
      case 51:
// 670 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_GREATER, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
}
// 1748 "parser.c"
        break;
      case 52:
// 674 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(11,&kkmsp[-1].minor);
}
// 1756 "parser.c"
        break;
      case 53:
// 678 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(12,&kkmsp[-1].minor);
}
// 1764 "parser.c"
        break;
      case 54:
// 682 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_DOT, kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(24,&kkmsp[-1].minor);
}
// 1772 "parser.c"
        break;
      case 55:
// 686 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 1780 "parser.c"
        break;
      case 56:
// 690 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, kkmsp[-1].minor.kk72, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(49,&kkmsp[0].minor);
}
// 1789 "parser.c"
        break;
      case 57:
// 694 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk72, NULL, status->scanner_state);
  kk_destructor(2,&kkmsp[-2].minor);
  kk_destructor(50,&kkmsp[0].minor);
}
// 1798 "parser.c"
        break;
      case 58:
      case 65:
// 700 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_zval_list(kkmsp[-2].minor.kk72, kkmsp[0].minor.kk72);
  kk_destructor(1,&kkmsp[-1].minor);
}
// 1807 "parser.c"
        break;
      case 60:
      case 68:
// 708 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_named_item(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk72, status->scanner_state);
  kk_destructor(51,&kkmsp[-1].minor);
}
// 1816 "parser.c"
        break;
      case 61:
      case 67:
// 712 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_named_item(NULL, kkmsp[0].minor.kk72, status->scanner_state);
}
// 1824 "parser.c"
        break;
      case 63:
// 722 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_func_call(kkmsp[-3].minor.kk72, kkmsp[-1].minor.kk72, status->scanner_state);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(49,&kkmsp[0].minor);
}
// 1833 "parser.c"
        break;
      case 64:
// 726 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_func_call(kkmsp[-2].minor.kk72, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
  kk_destructor(49,&kkmsp[0].minor);
}
// 1842 "parser.c"
        break;
      case 69:
// 750 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 1849 "parser.c"
        break;
      case 70:
// 754 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, kkmsp[-3].minor.kk72, kkmsp[-1].minor.kk72, status->scanner_state);
  kk_destructor(2,&kkmsp[-2].minor);
  kk_destructor(50,&kkmsp[0].minor);
}
// 1858 "parser.c"
        break;
      case 71:
// 758 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, kkmsp[0].minor.kk0, status->scanner_state);
}
// 1865 "parser.c"
        break;
      case 72:
// 762 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_literal_zval(PHVOLT_T_STRING, kkmsp[0].minor.kk0, status->scanner_state);
}
// 1872 "parser.c"
        break;
      case 73:
// 766 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, kkmsp[0].minor.kk0, status->scanner_state);
}
// 1879 "parser.c"
        break;
      case 74:
// 770 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  kk_destructor(53,&kkmsp[0].minor);
}
// 1887 "parser.c"
        break;
      case 75:
// 774 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  kk_destructor(54,&kkmsp[0].minor);
}
// 1895 "parser.c"
        break;
      case 76:
// 778 "parser.lemon"
{
	kkgotominor.kk72 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  kk_destructor(55,&kkmsp[0].minor);
}
// 1903 "parser.c"
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
// 383 "parser.lemon"

	if (status->scanner_state->start) {
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

// 1991 "parser.c"
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
		error = emalloc(sizeof(char) * 64 + strlen(state->start) +  Z_STRLEN_P(state->active_file));
		if (strlen(state->start) > 16) {
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