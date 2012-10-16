/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 37 "parser.lemon"


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "parser.h"
#include "scanner.h"
#include "compiler.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

static zval *phvolt_ret_literal_zval(int type, phvolt_parser_token *T)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", type);
	if (T) {
		add_assoc_stringl(ret, "value", T->token, T->token_len, 1);
		efree(T->token);
		efree(T);
	}

	return ret;
}

static zval *phvolt_ret_if_statement(zval *expr, zval *true_statements, zval *false_statements)
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

	return ret;
}

static zval *phvolt_ret_for_statement(zval *qualified_name, zval *expr, zval *block_statements)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_FOR);
	add_assoc_zval(ret, "qualified", qualified_name);
	add_assoc_zval(ret, "expr", expr);
	add_assoc_zval(ret, "block_statements", block_statements);

	return ret;
}

static zval *phvolt_ret_set_statement(zval *qualified_name, zval *expr)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_SET);
	add_assoc_zval(ret, "qualified", qualified_name);
	add_assoc_zval(ret, "expr", expr);

	return ret;
}

static zval *phvolt_ret_echo_statement(zval *expr)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_ECHO);
	add_assoc_zval(ret, "expr", expr);

	return ret;
}

static zval *phvolt_ret_block_statement(phvolt_parser_token *name, zval *block_statements)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_BLOCK);

	add_assoc_stringl(ret, "name", name->token, name->token_len, 1);
	efree(name->token);
	efree(name);

	if (block_statements) {
		add_assoc_zval(ret, "block_statements", block_statements);
	}

	return ret;
}

static zval *phvolt_ret_extends_statement(phvolt_parser_token *P)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_EXTENDS);

	add_assoc_stringl(ret, "path", P->token, P->token_len, 1);
	efree(P->token);
	efree(P);

	return ret;
}

static zval *phvolt_ret_include_statement(phvolt_parser_token *P)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_INCLUDE);

	add_assoc_stringl(ret, "path", P->token, P->token_len, 1);
	efree(P->token);
	efree(P);

	return ret;
}

static zval *phvolt_ret_empty_statement()
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_EMPTY);

	return ret;
}

static zval *phvolt_ret_qualified_name(zval *A, phvolt_parser_token *B)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_QUALIFIED);
	if (A != NULL) {
		add_assoc_zval(ret, "qualified", A);
	}

	add_assoc_stringl(ret, "name", B->token, B->token_len, 1);
	efree(B->token);
	efree(B);

	return ret;
}

static zval *phvolt_ret_zval_list(zval *list_left, zval *right_list)
{

	zval *ret;
	HashPosition pos;
	HashTable *list;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

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

	add_next_index_zval(ret, right_list);

	return ret;
}

static zval *phvolt_ret_named_item(phvolt_parser_token *name, zval *expr)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_zval(ret, "expr", expr);
	if (name != NULL) {
		add_assoc_stringl(ret, "name", name->token, name->token_len, 1);
		efree(name->token);
		efree(name);
	}

	return ret;
}

static zval *phvolt_ret_expr(int type, zval *left, zval *right)
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

	return ret;
}

static zval *phvolt_ret_func_call(phvolt_parser_token *name, zval *arguments)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_FCALL);
	add_assoc_stringl(ret, "name", name->token, name->token_len, 1);
	efree(name->token);
	efree(name);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	return ret;
}


// 268 "parser.c"
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
#define KKNOCODE 74
#define KKACTIONTYPE unsigned char
#define phvolt_KTOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_KTOKENTYPE kk0;
  zval* kk92;
  int kk147;
} KKMINORTYPE;
#define KKSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = kkpParser->status
#define phvolt_ARG_STORE kkpParser->status = status
#define KKNSTATE 145
#define KKNRULE 69
#define KKERRORSYMBOL 52
#define KKERRSYMDT kk147
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
 /*     0 */    78,   60,   62,   64,   70,   72,   74,   76,   66,   68,
 /*    10 */    52,   54,   58,   48,   46,   50,   44,   41,   56,  145,
 /*    20 */    20,   87,  106,   16,   91,   95,   78,   60,   62,   64,
 /*    30 */    70,   72,   74,   76,   66,   68,   52,   54,   58,   48,
 /*    40 */    46,   50,   44,   41,   56,   22,   15,  106,   26,   31,
 /*    50 */    95,  122,   78,   60,   62,   64,   70,   72,   74,   76,
 /*    60 */    66,   68,   52,   54,   58,   48,   46,   50,   44,   41,
 /*    70 */    56,   28,   30,  106,   35,   40,   95,   37,   78,   60,
 /*    80 */    62,   64,   70,   72,   74,   76,   66,   68,   52,   54,
 /*    90 */    58,   48,   46,   50,   44,   41,   56,   78,   60,   62,
 /*   100 */    64,   70,   72,   74,   76,   66,   68,   52,   54,   58,
 /*   110 */    48,   46,   50,   44,   41,   56,   44,   41,   56,   93,
 /*   120 */    97,   80,  215,    1,    2,  141,    4,    5,    6,    7,
 /*   130 */     8,    9,   10,   11,   12,  104,   39,  106,  107,   85,
 /*   140 */    95,  108,   78,   60,   62,   64,   70,   72,   74,   76,
 /*   150 */    66,   68,   52,   54,   58,   48,   46,   50,   44,   41,
 /*   160 */    56,   17,  141,    4,    5,    6,    7,    8,    9,   10,
 /*   170 */    11,   12,  125,  126,  139,  130,  132,   78,   60,   62,
 /*   180 */    64,   70,   72,   74,   76,   66,   68,   52,   54,   58,
 /*   190 */    48,   46,   50,   44,   41,   56,   62,   64,   70,   72,
 /*   200 */    74,   76,   66,   68,   52,   54,   58,   48,   46,   50,
 /*   210 */    44,   41,   56,   86,   23,  141,    4,    5,    6,    7,
 /*   220 */     8,    9,   10,   11,   12,  133,  135,  121,  106,  136,
 /*   230 */    42,   95,  118,   32,  141,    4,    5,    6,    7,    8,
 /*   240 */     9,   10,   11,   12,  144,   98,  106,   96,  101,   95,
 /*   250 */   110,  102,  144,  120,   83,  144,   86,  144,  109,  111,
 /*   260 */   112,  113,  114,    3,    4,    5,    6,    7,    8,    9,
 /*   270 */    10,   11,   12,   42,  144,   81,  127,  141,    4,    5,
 /*   280 */     6,    7,    8,    9,   10,   11,   12,  107,   43,  106,
 /*   290 */    96,  100,   95,  103,   29,  144,   86,   83,  115,  146,
 /*   300 */   144,  109,  111,  112,  113,  114,  144,   14,  123,   19,
 /*   310 */    21,   27,  144,   42,   36,   81,   45,  106,  124,  144,
 /*   320 */    95,  131,   13,  134,   48,   46,   50,   44,   41,   56,
 /*   330 */    96,   90,  137,  110,   47,  106,  119,   83,   95,   86,
 /*   340 */   140,  109,  111,  112,  113,  114,   52,   54,   58,   48,
 /*   350 */    46,   50,   44,   41,   56,  144,   42,  144,   81,   58,
 /*   360 */    48,   46,   50,   44,   41,   56,  144,   14,  123,   25,
 /*   370 */   144,   27,   13,   96,   36,   89,  110,  144,  124,   86,
 /*   380 */    83,  131,  137,  134,  109,  111,  112,  113,  114,  144,
 /*   390 */   140,   49,  106,   14,  123,   95,   42,   27,   81,   34,
 /*   400 */    36,   51,  106,  144,  124,   95,  144,  131,  144,  134,
 /*   410 */    53,  106,  144,   96,   95,  144,   92,   98,  106,   86,
 /*   420 */    83,   95,   99,  116,  109,  111,  112,  113,  114,   87,
 /*   430 */   106,   88,  117,   95,  144,  144,   42,   18,   81,   55,
 /*   440 */   106,   24,  144,   95,   33,   57,  106,  137,  144,   95,
 /*   450 */   144,  137,  144,   96,  137,  140,  103,   59,  106,  140,
 /*   460 */    83,   95,  140,  144,  109,  111,  112,  113,  114,   61,
 /*   470 */   106,   63,  106,   95,  107,   95,   65,  106,   14,  123,
 /*   480 */    95,  144,   27,  144,   38,   36,   67,  106,  144,  124,
 /*   490 */    95,  129,  131,  144,  134,   69,  106,   71,  106,   95,
 /*   500 */   144,   95,  144,   14,  123,   73,  106,   27,  144,   95,
 /*   510 */    36,   75,  106,  144,  124,   95,  143,  131,  144,  134,
 /*   520 */   142,   77,  106,   79,  106,   95,  144,   95,   14,  123,
 /*   530 */   137,  128,   27,   82,  106,   36,  144,   95,  140,  124,
 /*   540 */   144,  137,  131,  144,  134,  144,   84,  106,  144,  140,
 /*   550 */    95,  144,   94,  106,  105,  106,   95,  144,   95,  138,
 /*   560 */   106,  144,  144,   95,
};
static KKCODETYPE kk_lookahead[] = {
 /*     0 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*    10 */    12,   13,   14,   15,   16,   17,   18,   19,   20,    0,
 /*    20 */    25,   66,   67,   25,   69,   70,    2,    3,    4,    5,
 /*    30 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*    40 */    16,   17,   18,   19,   20,   25,   66,   67,   25,   25,
 /*    50 */    70,   36,    2,    3,    4,    5,    6,    7,    8,    9,
 /*    60 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*    70 */    20,   67,   66,   67,   25,   25,   70,   67,    2,    3,
 /*    80 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    90 */    14,   15,   16,   17,   18,   19,   20,    2,    3,    4,
 /*   100 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   110 */    15,   16,   17,   18,   19,   20,   18,   19,   20,   46,
 /*   120 */    43,   45,   53,   54,   55,   56,   57,   58,   59,   60,
 /*   130 */    61,   62,   63,   64,   65,   46,   66,   67,   22,   44,
 /*   140 */    70,   36,    2,    3,    4,    5,    6,    7,    8,    9,
 /*   150 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   160 */    20,   55,   56,   57,   58,   59,   60,   61,   62,   63,
 /*   170 */    64,   65,   36,   25,   34,   25,   39,    2,    3,    4,
 /*   180 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   190 */    15,   16,   17,   18,   19,   20,    4,    5,    6,    7,
 /*   200 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   210 */    18,   19,   20,    2,   55,   56,   57,   58,   59,   60,
 /*   220 */    61,   62,   63,   64,   65,   25,   39,   66,   67,   25,
 /*   230 */    19,   70,   21,   55,   56,   57,   58,   59,   60,   61,
 /*   240 */    62,   63,   64,   65,   25,   66,   67,   36,    1,   70,
 /*   250 */    39,   72,   73,   42,   43,   73,    2,   73,   47,   48,
 /*   260 */    49,   50,   51,   56,   57,   58,   59,   60,   61,   62,
 /*   270 */    63,   64,   65,   19,   73,   21,   55,   56,   57,   58,
 /*   280 */    59,   60,   61,   62,   63,   64,   65,   22,   66,   67,
 /*   290 */    36,   44,   70,   39,   29,   73,    2,   43,   44,    0,
 /*   300 */    73,   47,   48,   49,   50,   51,   73,   24,   25,   26,
 /*   310 */    27,   28,   73,   19,   31,   21,   66,   67,   35,   73,
 /*   320 */    70,   38,   23,   40,   15,   16,   17,   18,   19,   20,
 /*   330 */    36,    1,   33,   39,   66,   67,   42,   43,   70,    2,
 /*   340 */    41,   47,   48,   49,   50,   51,   12,   13,   14,   15,
 /*   350 */    16,   17,   18,   19,   20,   73,   19,   73,   21,   14,
 /*   360 */    15,   16,   17,   18,   19,   20,   73,   24,   25,   26,
 /*   370 */    73,   28,   23,   36,   31,   45,   39,   73,   35,    2,
 /*   380 */    43,   38,   33,   40,   47,   48,   49,   50,   51,   73,
 /*   390 */    41,   66,   67,   24,   25,   70,   19,   28,   21,   30,
 /*   400 */    31,   66,   67,   73,   35,   70,   73,   38,   73,   40,
 /*   410 */    66,   67,   73,   36,   70,   73,   39,   66,   67,    2,
 /*   420 */    43,   70,   71,   72,   47,   48,   49,   50,   51,   66,
 /*   430 */    67,   68,   69,   70,   73,   73,   19,   23,   21,   66,
 /*   440 */    67,   23,   73,   70,   23,   66,   67,   33,   73,   70,
 /*   450 */    73,   33,   73,   36,   33,   41,   39,   66,   67,   41,
 /*   460 */    43,   70,   41,   73,   47,   48,   49,   50,   51,   66,
 /*   470 */    67,   66,   67,   70,   22,   70,   66,   67,   24,   25,
 /*   480 */    70,   73,   28,   73,   32,   31,   66,   67,   73,   35,
 /*   490 */    70,   37,   38,   73,   40,   66,   67,   66,   67,   70,
 /*   500 */    73,   70,   73,   24,   25,   66,   67,   28,   73,   70,
 /*   510 */    31,   66,   67,   73,   35,   70,   37,   38,   73,   40,
 /*   520 */    23,   66,   67,   66,   67,   70,   73,   70,   24,   25,
 /*   530 */    33,   23,   28,   66,   67,   31,   73,   70,   41,   35,
 /*   540 */    73,   33,   38,   73,   40,   73,   66,   67,   73,   41,
 /*   550 */    70,   73,   66,   67,   66,   67,   70,   73,   70,   66,
 /*   560 */    67,   73,   73,   70,
};
#define KK_SHIFT_USE_DFLT (-6)
static short kk_shift_ofst[] = {
 /*     0 */   349,   19,  299,   -6,   -6,   -6,   -6,   -6,   -6,   -6,
 /*    10 */    -6,   -6,   -6,  504,  337,   -2,  349,  414,  283,   -5,
 /*    20 */    -6,   20,  349,  418,  343,   23,   -6,   15,  265,  337,
 /*    30 */    24,  349,  421,  369,   49,   -6,   15,  452,  337,   50,
 /*    40 */    -6,  337,  337,   -6,  337,   -6,  337,   98,  337,   98,
 /*    50 */   337,   98,  337,  345,  337,  345,  337,   -6,  337,  309,
 /*    60 */   337,  192,  211,  334,  337,  334,  337,  334,  337,  334,
 /*    70 */   337,  334,  337,  334,  337,  334,  337,  334,  337,   76,
 /*    80 */    -6,  337,   -6,  337,   95,   -6,  377,  175,  330,   -6,
 /*    90 */   377,   -6,   73,  337,  175,   -6,   77,  254,  175,  247,
 /*   100 */    -6,  417,   -6,   89,  337,  175,  116,  105,   -6,   -6,
 /*   110 */    -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,  294,   -6,
 /*   120 */    -6,   -6,   -6,   -6,  136,  148,  497,  508,  454,  150,
 /*   130 */    -6,  137,  200,   -6,  187,  204,   -6,  337,  140,   -6,
 /*   140 */    -6,   -6,  479,  219,   -6,
};
#define KK_REDUCE_USE_DFLT (-46)
static short kk_reduce_ofst[] = {
 /*     0 */    69,  -46,  207,  -46,  -46,  -46,  -46,  -46,  -46,  -46,
 /*    10 */   -46,  -46,  -46,  -46,  -20,  -46,  106,  207,  -46,  -46,
 /*    20 */   -46,  -46,  159,  207,  -46,  -46,  -46,    4,  -46,    6,
 /*    30 */   -46,  178,  207,  -46,  -46,  -46,   10,  -46,   70,  -46,
 /*    40 */   -46,  161,  222,  -46,  250,  -46,  268,  -46,  325,  -46,
 /*    50 */   335,  -46,  344,  -46,  373,  -46,  379,  -46,  391,  -46,
 /*    60 */   403,  -46,  405,  -46,  410,  -46,  420,  -46,  429,  -46,
 /*    70 */   431,  -46,  439,  -46,  445,  -46,  455,  -46,  457,  -46,
 /*    80 */   -46,  467,  -46,  480,  -46,  -46,  363,  -46,  -46,  -46,
 /*    90 */   -45,  -46,  -46,  486,  -46,  -46,  -46,  351,  -46,  -46,
 /*   100 */   -46,  179,  -46,  -46,  488,  -46,  -46,  -46,  -46,  -46,
 /*   110 */   -46,  -46,  -46,  -46,  -46,  -46,  -46,  -46,  467,  -46,
 /*   120 */   -46,  -46,  -46,  -46,  -46,  -46,  221,  207,  -46,  -46,
 /*   130 */   -46,  -46,  -46,  -46,  -46,  -46,  -46,  493,  -46,  -46,
 /*   140 */   -46,  -46,  -46,  -46,  -46,
};
static KKACTIONTYPE kk_default[] = {
 /*     0 */   214,  214,  214,  147,  149,  150,  151,  152,  153,  154,
 /*    10 */   155,  156,  157,  214,  214,  214,  214,  214,  214,  214,
 /*    20 */   158,  214,  214,  214,  214,  214,  159,  214,  214,  214,
 /*    30 */   214,  214,  214,  214,  214,  160,  214,  214,  214,  214,
 /*    40 */   161,  214,  214,  169,  214,  171,  214,  172,  214,  173,
 /*    50 */   214,  174,  214,  175,  214,  176,  214,  177,  214,  178,
 /*    60 */   214,  179,  214,  180,  214,  183,  214,  184,  214,  185,
 /*    70 */   214,  186,  214,  187,  214,  188,  214,  189,  214,  214,
 /*    80 */   205,  214,  190,  214,  214,  191,  214,  196,  214,  192,
 /*    90 */   214,  193,  207,  214,  195,  197,  213,  214,  202,  214,
 /*   100 */   198,  214,  200,  207,  214,  203,  204,  214,  212,  206,
 /*   110 */   207,  208,  209,  210,  211,  199,  201,  194,  214,  181,
 /*   120 */   182,  170,  213,  162,  214,  214,  214,  214,  214,  214,
 /*   130 */   164,  214,  214,  166,  214,  214,  167,  214,  214,  163,
 /*   140 */   168,  148,  214,  214,  165,
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
  "EQUALS",        "NOTEQUALS",     "LESS",          "GREATER",     
  "GREATEREQUAL",  "LESSEQUAL",     "IDENTICAL",     "NOTIDENTICAL",
  "AND",           "OR",            "PIPE",          "DIVIDE",      
  "TIMES",         "MOD",           "PLUS",          "MINUS",       
  "CONCAT",        "NOT",           "DOT",           "OPEN_DELIMITER",
  "IF",            "CLOSE_DELIMITER",  "ENDIF",         "ELSE",        
  "FOR",           "IN",            "ENDFOR",        "SET",         
  "ASSIGN",        "OPEN_EDELIMITER",  "CLOSE_EDELIMITER",  "BLOCK",       
  "IDENTIFIER",    "ENDBLOCK",      "EXTENDS",       "STRING",      
  "INCLUDE",       "RAW_FRAGMENT",  "DEFINED",       "BRACKET_OPEN",
  "BRACKET_CLOSE",  "SBRACKET_CLOSE",  "DOUBLECOLON",   "INTEGER",     
  "DOUBLE",        "NULL",          "FALSE",         "TRUE",        
  "error",         "program",       "volt_language",  "statement_list",
  "statement",     "raw_fragment",  "if_statement",  "for_statement",
  "set_statement",  "echo_statement",  "block_statement",  "extends_statement",
  "include_statement",  "empty_statement",  "expr",          "qualified_name",
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
 /*  10 */ "statement ::= extends_statement",
 /*  11 */ "statement ::= include_statement",
 /*  12 */ "statement ::= empty_statement",
 /*  13 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  14 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  15 */ "for_statement ::= OPEN_DELIMITER FOR qualified_name IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  16 */ "set_statement ::= OPEN_DELIMITER SET qualified_name ASSIGN expr CLOSE_DELIMITER",
 /*  17 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  18 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  19 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  20 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  21 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  22 */ "include_statement ::= OPEN_DELIMITER INCLUDE STRING CLOSE_DELIMITER",
 /*  23 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  24 */ "expr ::= MINUS expr",
 /*  25 */ "expr ::= expr MINUS expr",
 /*  26 */ "expr ::= expr PLUS expr",
 /*  27 */ "expr ::= expr TIMES expr",
 /*  28 */ "expr ::= expr DIVIDE expr",
 /*  29 */ "expr ::= expr MOD expr",
 /*  30 */ "expr ::= expr AND expr",
 /*  31 */ "expr ::= expr OR expr",
 /*  32 */ "expr ::= expr CONCAT expr",
 /*  33 */ "expr ::= expr PIPE expr",
 /*  34 */ "expr ::= expr RANGE expr",
 /*  35 */ "expr ::= expr EQUALS expr",
 /*  36 */ "expr ::= expr EQUALS NOT DEFINED",
 /*  37 */ "expr ::= expr EQUALS DEFINED",
 /*  38 */ "expr ::= expr NOTEQUALS expr",
 /*  39 */ "expr ::= expr IDENTICAL expr",
 /*  40 */ "expr ::= expr NOTIDENTICAL expr",
 /*  41 */ "expr ::= expr LESS expr",
 /*  42 */ "expr ::= expr GREATER expr",
 /*  43 */ "expr ::= expr GREATEREQUAL expr",
 /*  44 */ "expr ::= expr LESSEQUAL expr",
 /*  45 */ "expr ::= NOT expr",
 /*  46 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /*  47 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /*  48 */ "array_list ::= array_list COMMA array_item",
 /*  49 */ "array_list ::= array_item",
 /*  50 */ "array_item ::= STRING DOUBLECOLON expr",
 /*  51 */ "array_item ::= expr",
 /*  52 */ "expr ::= function_call",
 /*  53 */ "function_call ::= IDENTIFIER BRACKET_OPEN argument_list BRACKET_CLOSE",
 /*  54 */ "function_call ::= IDENTIFIER BRACKET_OPEN BRACKET_CLOSE",
 /*  55 */ "argument_list ::= argument_list COMMA argument_item",
 /*  56 */ "argument_list ::= argument_item",
 /*  57 */ "argument_item ::= expr",
 /*  58 */ "argument_item ::= STRING DOUBLECOLON expr",
 /*  59 */ "expr ::= qualified_name",
 /*  60 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /*  61 */ "expr ::= INTEGER",
 /*  62 */ "expr ::= STRING",
 /*  63 */ "expr ::= DOUBLE",
 /*  64 */ "expr ::= NULL",
 /*  65 */ "expr ::= FALSE",
 /*  66 */ "expr ::= TRUE",
 /*  67 */ "qualified_name ::= qualified_name DOT IDENTIFIER",
 /*  68 */ "qualified_name ::= IDENTIFIER",
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
// 342 "parser.lemon"
{
	if ((kkpminor->kk0)) {
		efree((kkpminor->kk0)->token);
		efree((kkpminor->kk0));
	}
}
// 851 "parser.c"
      break;
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
    case 70:
    case 71:
    case 72:
// 357 "parser.lemon"
{ zval_ptr_dtor(&(kkpminor->kk92)); }
// 872 "parser.c"
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
  { 53, 1 },
  { 54, 1 },
  { 55, 2 },
  { 55, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 58, 8 },
  { 58, 12 },
  { 59, 10 },
  { 60, 6 },
  { 65, 2 },
  { 61, 3 },
  { 62, 8 },
  { 62, 7 },
  { 63, 4 },
  { 64, 4 },
  { 57, 1 },
  { 66, 2 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 4 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 2 },
  { 66, 3 },
  { 66, 3 },
  { 68, 3 },
  { 68, 1 },
  { 69, 3 },
  { 69, 1 },
  { 66, 1 },
  { 70, 4 },
  { 70, 3 },
  { 71, 3 },
  { 71, 1 },
  { 72, 1 },
  { 72, 3 },
  { 66, 1 },
  { 66, 4 },
  { 66, 1 },
  { 66, 1 },
  { 66, 1 },
  { 66, 1 },
  { 66, 1 },
  { 66, 1 },
  { 67, 3 },
  { 67, 1 },
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
// 349 "parser.lemon"
{
	status->ret = kkmsp[0].minor.kk92;
}
// 1158 "parser.c"
        break;
      case 1:
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
      case 49:
      case 52:
      case 56:
      case 59:
// 353 "parser.lemon"
{
	kkgotominor.kk92 = kkmsp[0].minor.kk92;
}
// 1179 "parser.c"
        break;
      case 2:
// 359 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_zval_list(kkmsp[-1].minor.kk92, kkmsp[0].minor.kk92);
}
// 1186 "parser.c"
        break;
      case 13:
// 407 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_if_statement(kkmsp[-5].minor.kk92, kkmsp[-3].minor.kk92, NULL);
  kk_destructor(23,&kkmsp[-7].minor);
  kk_destructor(24,&kkmsp[-6].minor);
  kk_destructor(25,&kkmsp[-4].minor);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(26,&kkmsp[-1].minor);
  kk_destructor(25,&kkmsp[0].minor);
}
// 1199 "parser.c"
        break;
      case 14:
// 411 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_if_statement(kkmsp[-9].minor.kk92, kkmsp[-7].minor.kk92, kkmsp[-3].minor.kk92);
  kk_destructor(23,&kkmsp[-11].minor);
  kk_destructor(24,&kkmsp[-10].minor);
  kk_destructor(25,&kkmsp[-8].minor);
  kk_destructor(23,&kkmsp[-6].minor);
  kk_destructor(27,&kkmsp[-5].minor);
  kk_destructor(25,&kkmsp[-4].minor);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(26,&kkmsp[-1].minor);
  kk_destructor(25,&kkmsp[0].minor);
}
// 1215 "parser.c"
        break;
      case 15:
// 417 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_for_statement(kkmsp[-7].minor.kk92, kkmsp[-5].minor.kk92, kkmsp[-3].minor.kk92);
  kk_destructor(23,&kkmsp[-9].minor);
  kk_destructor(28,&kkmsp[-8].minor);
  kk_destructor(29,&kkmsp[-6].minor);
  kk_destructor(25,&kkmsp[-4].minor);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(30,&kkmsp[-1].minor);
  kk_destructor(25,&kkmsp[0].minor);
}
// 1229 "parser.c"
        break;
      case 16:
// 423 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_set_statement(kkmsp[-3].minor.kk92, kkmsp[-1].minor.kk92);
  kk_destructor(23,&kkmsp[-5].minor);
  kk_destructor(31,&kkmsp[-4].minor);
  kk_destructor(32,&kkmsp[-2].minor);
  kk_destructor(25,&kkmsp[0].minor);
}
// 1240 "parser.c"
        break;
      case 17:
// 429 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_empty_statement();
  kk_destructor(23,&kkmsp[-1].minor);
  kk_destructor(25,&kkmsp[0].minor);
}
// 1249 "parser.c"
        break;
      case 18:
// 435 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_echo_statement(kkmsp[-1].minor.kk92);
  kk_destructor(33,&kkmsp[-2].minor);
  kk_destructor(34,&kkmsp[0].minor);
}
// 1258 "parser.c"
        break;
      case 19:
// 441 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_block_statement(kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk92);
  kk_destructor(23,&kkmsp[-7].minor);
  kk_destructor(35,&kkmsp[-6].minor);
  kk_destructor(25,&kkmsp[-4].minor);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(25,&kkmsp[0].minor);
}
// 1271 "parser.c"
        break;
      case 20:
// 445 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_block_statement(kkmsp[-4].minor.kk0, NULL);
  kk_destructor(23,&kkmsp[-6].minor);
  kk_destructor(35,&kkmsp[-5].minor);
  kk_destructor(25,&kkmsp[-3].minor);
  kk_destructor(23,&kkmsp[-2].minor);
  kk_destructor(37,&kkmsp[-1].minor);
  kk_destructor(25,&kkmsp[0].minor);
}
// 1284 "parser.c"
        break;
      case 21:
// 451 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_extends_statement(kkmsp[-1].minor.kk0);
  kk_destructor(23,&kkmsp[-3].minor);
  kk_destructor(38,&kkmsp[-2].minor);
  kk_destructor(25,&kkmsp[0].minor);
}
// 1294 "parser.c"
        break;
      case 22:
// 457 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_include_statement(kkmsp[-1].minor.kk0);
  kk_destructor(23,&kkmsp[-3].minor);
  kk_destructor(40,&kkmsp[-2].minor);
  kk_destructor(25,&kkmsp[0].minor);
}
// 1304 "parser.c"
        break;
      case 23:
// 463 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, kkmsp[0].minor.kk0);
}
// 1311 "parser.c"
        break;
      case 24:
// 469 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, kkmsp[0].minor.kk92);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 1319 "parser.c"
        break;
      case 25:
// 473 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_SUB, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(19,&kkmsp[-1].minor);
}
// 1327 "parser.c"
        break;
      case 26:
// 477 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_ADD, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(18,&kkmsp[-1].minor);
}
// 1335 "parser.c"
        break;
      case 27:
// 481 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_MUL, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(16,&kkmsp[-1].minor);
}
// 1343 "parser.c"
        break;
      case 28:
// 485 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_DIV, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(15,&kkmsp[-1].minor);
}
// 1351 "parser.c"
        break;
      case 29:
// 489 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(17,&kkmsp[-1].minor);
}
// 1359 "parser.c"
        break;
      case 30:
// 493 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_AND, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(12,&kkmsp[-1].minor);
}
// 1367 "parser.c"
        break;
      case 31:
// 497 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_OR, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(13,&kkmsp[-1].minor);
}
// 1375 "parser.c"
        break;
      case 32:
// 501 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_CONCAT, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(20,&kkmsp[-1].minor);
}
// 1383 "parser.c"
        break;
      case 33:
// 505 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_PIPE, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(14,&kkmsp[-1].minor);
}
// 1391 "parser.c"
        break;
      case 34:
// 509 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_RANGE, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(3,&kkmsp[-1].minor);
}
// 1399 "parser.c"
        break;
      case 35:
// 513 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_EQUALS, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(4,&kkmsp[-1].minor);
}
// 1407 "parser.c"
        break;
      case 36:
// 517 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, kkmsp[-3].minor.kk92, NULL);
  kk_destructor(4,&kkmsp[-2].minor);
  kk_destructor(21,&kkmsp[-1].minor);
  kk_destructor(42,&kkmsp[0].minor);
}
// 1417 "parser.c"
        break;
      case 37:
// 521 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_ISSET, kkmsp[-2].minor.kk92, NULL);
  kk_destructor(4,&kkmsp[-1].minor);
  kk_destructor(42,&kkmsp[0].minor);
}
// 1426 "parser.c"
        break;
      case 38:
// 525 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(5,&kkmsp[-1].minor);
}
// 1434 "parser.c"
        break;
      case 39:
// 529 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(10,&kkmsp[-1].minor);
}
// 1442 "parser.c"
        break;
      case 40:
// 533 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(11,&kkmsp[-1].minor);
}
// 1450 "parser.c"
        break;
      case 41:
// 537 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_LESS, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(6,&kkmsp[-1].minor);
}
// 1458 "parser.c"
        break;
      case 42:
// 541 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_GREATER, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(7,&kkmsp[-1].minor);
}
// 1466 "parser.c"
        break;
      case 43:
// 545 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(8,&kkmsp[-1].minor);
}
// 1474 "parser.c"
        break;
      case 44:
// 549 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(9,&kkmsp[-1].minor);
}
// 1482 "parser.c"
        break;
      case 45:
// 553 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, kkmsp[0].minor.kk92);
  kk_destructor(21,&kkmsp[-1].minor);
}
// 1490 "parser.c"
        break;
      case 46:
// 557 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, kkmsp[-1].minor.kk92, NULL);
  kk_destructor(43,&kkmsp[-2].minor);
  kk_destructor(44,&kkmsp[0].minor);
}
// 1499 "parser.c"
        break;
      case 47:
// 561 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk92, NULL);
  kk_destructor(2,&kkmsp[-2].minor);
  kk_destructor(45,&kkmsp[0].minor);
}
// 1508 "parser.c"
        break;
      case 48:
      case 55:
// 567 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_zval_list(kkmsp[-2].minor.kk92, kkmsp[0].minor.kk92);
  kk_destructor(1,&kkmsp[-1].minor);
}
// 1517 "parser.c"
        break;
      case 50:
      case 58:
// 575 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_named_item(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk92);
  kk_destructor(46,&kkmsp[-1].minor);
}
// 1526 "parser.c"
        break;
      case 51:
      case 57:
// 579 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_named_item(NULL, kkmsp[0].minor.kk92);
}
// 1534 "parser.c"
        break;
      case 53:
// 589 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_func_call(kkmsp[-3].minor.kk0, kkmsp[-1].minor.kk92);
  kk_destructor(43,&kkmsp[-2].minor);
  kk_destructor(44,&kkmsp[0].minor);
}
// 1543 "parser.c"
        break;
      case 54:
// 593 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_func_call(kkmsp[-2].minor.kk0, NULL);
  kk_destructor(43,&kkmsp[-1].minor);
  kk_destructor(44,&kkmsp[0].minor);
}
// 1552 "parser.c"
        break;
      case 60:
// 621 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, kkmsp[-3].minor.kk92, kkmsp[-1].minor.kk92);
  kk_destructor(2,&kkmsp[-2].minor);
  kk_destructor(45,&kkmsp[0].minor);
}
// 1561 "parser.c"
        break;
      case 61:
// 625 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, kkmsp[0].minor.kk0);
}
// 1568 "parser.c"
        break;
      case 62:
// 629 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_STRING, kkmsp[0].minor.kk0);
}
// 1575 "parser.c"
        break;
      case 63:
// 633 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, kkmsp[0].minor.kk0);
}
// 1582 "parser.c"
        break;
      case 64:
// 637 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL);
  kk_destructor(49,&kkmsp[0].minor);
}
// 1590 "parser.c"
        break;
      case 65:
// 641 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL);
  kk_destructor(50,&kkmsp[0].minor);
}
// 1598 "parser.c"
        break;
      case 66:
// 645 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL);
  kk_destructor(51,&kkmsp[0].minor);
}
// 1606 "parser.c"
        break;
      case 67:
// 651 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_qualified_name(kkmsp[-2].minor.kk92, kkmsp[0].minor.kk0);
  kk_destructor(22,&kkmsp[-1].minor);
}
// 1614 "parser.c"
        break;
      case 68:
// 655 "parser.lemon"
{
	kkgotominor.kk92 = phvolt_ret_qualified_name(NULL, kkmsp[0].minor.kk0);
}
// 1621 "parser.c"
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
// 297 "parser.lemon"

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

			status->syntax_error_len = 64 + strlen(token_name);
			status->syntax_error = emalloc(sizeof(char)*status->syntax_error_len);
			sprintf(status->syntax_error, "Syntax error, unexpected token %s on line %d", token_name, status->scanner_state->active_line);

			if (!token_found) {
				if (token_name) {
					efree(token_name);
				}
			}
		}
	} else {
		status->syntax_error_len = strlen("Syntax error, unexpected EOF");
		status->syntax_error = estrndup("Syntax error, unexpected EOF", status->syntax_error_len);
	}

	status->status = PHVOLT_PARSING_FAILED;

// 1708 "parser.c"
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
  { PHVOLT_T_EXTENDS,			"EXTENDS" },
  { PHVOLT_T_IS,				"IS" },
  { PHVOLT_T_DEFINED,			"DEFINED" },
  { PHVOLT_T_INCLUDE,			"INCLUDE" },
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
	phvolt_(phvolt_parser, parsercode, pToken, parser_status);
}

/**
 * Creates an error message
 */
static void phvolt_create_error_msg(phvolt_parser_status *parser_status, char *message){
	char *str = emalloc(sizeof(char) * 128);
	sprintf(str, "%s on line %d", message, parser_status->scanner_state->active_line);
	parser_status->syntax_error = estrndup(str, strlen(str));
	efree(str);
}

/**
 * Receives the volt code and tokenizes/parses it
 */
int phvolt_parse_view(zval *result, zval *view_code TSRMLS_DC){

	zval *error_msg;

	ZVAL_NULL(result);

	if(phvolt_internal_parse_view(&result, Z_STRVAL_P(view_code), &error_msg TSRMLS_CC) == FAILURE){
		phalcon_throw_exception_string(phalcon_mvc_view_exception_ce, Z_STRVAL_P(error_msg), Z_STRLEN_P(error_msg) TSRMLS_CC);
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Checks if token contains only black characters
 */
int phvolt_is_blank_string(phvolt_scanner_token *token){
	int i;
	char ch, *marker = token->value;
	for (i = 0; i<token->len; i++) {
		ch = *marker;
		if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r') {
			return 0;
		}
		marker++;
	}
	return 1;
}

/**
 * Parses a volt template returning an intermediate array representation
 */
int phvolt_internal_parse_view(zval **result, char *view_code, zval **error_msg TSRMLS_DC) {

	char *error;
	phvolt_scanner_state *state;
	phvolt_scanner_token *token;
	int scanner_status, status = SUCCESS;
	phvolt_parser_status *parser_status = NULL;
	void* phvolt_parser;

	if (!view_code) {
		PHALCON_INIT_VAR(*error_msg);
		ZVAL_STRING(*error_msg, "View code cannot be null", 1);
		return FAILURE;
	}

	phvolt_parser = phvolt_Alloc(phvolt_wrapper_alloc);

	parser_status = emalloc(sizeof(phvolt_parser_status));
	state = emalloc(sizeof(phvolt_scanner_state));
	token = emalloc(sizeof(phvolt_scanner_token));

	parser_status->status = PHVOLT_PARSING_OK;
	parser_status->scanner_state = state;
	parser_status->ret = NULL;

	/** Initialize the scanner state */
	state->active_token = 0;
	state->start = view_code;
	state->mode = PHVOLT_MODE_RAW;
	state->raw_buffer = emalloc(sizeof(char) * PHVOLT_RAW_BUFFER_SIZE);
	state->raw_buffer_size = PHVOLT_RAW_BUFFER_SIZE;
	state->raw_buffer_cursor = 0;
	state->active_line = 1;
	state->statement_position = 0;
	state->extends_mode = 0;
	state->block_level = 0;

	state->end = state->start;

	while(0 <= (scanner_status = phvolt_get_token(state, token))) {

		state->active_token = token->opcode;

		switch(token->opcode){

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
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_INTEGER, PHVOLT_INTEGER, token, parser_status);
				break;
			case PHVOLT_T_DOUBLE:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_DOUBLE, PHVOLT_DOUBLE, token, parser_status);
				break;
			case PHVOLT_T_STRING:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_STRING, PHVOLT_STRING, token, parser_status);
				break;
			case PHVOLT_T_IDENTIFIER:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_IDENTIFIER, PHVOLT_IDENTIFIER, token, parser_status);
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
					if(!phvolt_is_blank_string(token)){
						phvolt_create_error_msg(parser_status, "Child templates only may contain blocks");
						parser_status->status = PHVOLT_PARSING_FAILED;
					} else {
						efree(token->value);
					}
					break;
				}
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_RAW_FRAGMENT, PHVOLT_RAW_FRAGMENT, token, parser_status);
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

			case PHVOLT_T_INCLUDE:
				phvolt_(phvolt_parser, PHVOLT_INCLUDE, NULL, parser_status);
				break;

			case PHVOLT_T_DEFINED:
				phvolt_(phvolt_parser, PHVOLT_DEFINED, NULL, parser_status);
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
				status = FAILURE;
				error = emalloc(sizeof(char) * 32);
				sprintf(error, "scanner: unknown opcode %c", token->opcode);
				PHALCON_INIT_VAR(*error_msg);
				ZVAL_STRING(*error_msg, error, 1);
				efree(error);
				break;
		}

		if (parser_status->status != PHVOLT_PARSING_OK) {
			status = FAILURE;
			break;
		}

		state->end = state->start;
	}

	state->active_token = 0;
	state->start = NULL;
	efree(state->raw_buffer);

	if (status != FAILURE) {
		switch (scanner_status) {
			case PHVOLT_SCANNER_RETCODE_ERR:
			case PHVOLT_SCANNER_RETCODE_IMPOSSIBLE:
				PHALCON_INIT_VAR(*error_msg);
				if (state->start) {
					error = emalloc(sizeof(char) *(48 + strlen(state->start)));
					sprintf(error, "Parsing error near to %s (%d)", state->start, status);
					ZVAL_STRING(*error_msg, error, 1);
					efree(error);
				} else {
					ZVAL_STRING(*error_msg, "Parsing error near to EOF", 1);
				}
				status = FAILURE;
				break;
			default:
				phvolt_(phvolt_parser, 0, NULL, parser_status);
		}
	}

	if (parser_status->status != PHVOLT_PARSING_OK) {
		status = FAILURE;
		PHALCON_INIT_VAR(*error_msg);
		ZVAL_STRING(*error_msg, parser_status->syntax_error, 1);
		efree(parser_status->syntax_error);
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
	efree(token);

	return status;
}