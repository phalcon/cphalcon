/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
/* #line 42 "parser.y" */


#include "php_phalcon.h"
#include "mvc/view/engine/volt/parser.h"
#include "mvc/view/engine/volt/scanner.h"
#include "mvc/view/engine/volt/volt.h"
#include "mvc/view/exception.h"

#include <ext/standard/php_smart_str.h>

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

static zval *phvolt_ret_set_statement(zval *assignments)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, "type", PHVOLT_T_SET);

	add_assoc_zval(ret, "assignments", assignments);

	return ret;
}

static zval *phvolt_ret_set_assignment(phvolt_parser_token *variable, int operator, zval *expr, phvolt_scanner_state *state)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 5);

	add_assoc_stringl(ret, "variable", variable->token, variable->token_len, 0);
	efree(variable);

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


/* #line 565 "parser.c" */
#include "parser.h"
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
#if INTERFACE
#define PHVOLT_OPEN_DELIMITER                  1
#define PHVOLT_COMMA                           2
#define PHVOLT_IN                              3
#define PHVOLT_QUESTION                        4
#define PHVOLT_COLON                           5
#define PHVOLT_RANGE                           6
#define PHVOLT_AND                             7
#define PHVOLT_OR                              8
#define PHVOLT_IS                              9
#define PHVOLT_EQUALS                         10
#define PHVOLT_NOTEQUALS                      11
#define PHVOLT_LESS                           12
#define PHVOLT_GREATER                        13
#define PHVOLT_GREATEREQUAL                   14
#define PHVOLT_LESSEQUAL                      15
#define PHVOLT_IDENTICAL                      16
#define PHVOLT_NOTIDENTICAL                   17
#define PHVOLT_DIVIDE                         18
#define PHVOLT_TIMES                          19
#define PHVOLT_MOD                            20
#define PHVOLT_PLUS                           21
#define PHVOLT_MINUS                          22
#define PHVOLT_CONCAT                         23
#define PHVOLT_SBRACKET_OPEN                  24
#define PHVOLT_PIPE                           25
#define PHVOLT_NOT                            26
#define PHVOLT_INCR                           27
#define PHVOLT_DECR                           28
#define PHVOLT_PARENTHESES_OPEN               29
#define PHVOLT_DOT                            30
#define PHVOLT_IF                             31
#define PHVOLT_CLOSE_DELIMITER                32
#define PHVOLT_ENDIF                          33
#define PHVOLT_ELSE                           34
#define PHVOLT_ELSEIF                         35
#define PHVOLT_ELSEFOR                        36
#define PHVOLT_FOR                            37
#define PHVOLT_IDENTIFIER                     38
#define PHVOLT_ENDFOR                         39
#define PHVOLT_SET                            40
#define PHVOLT_ASSIGN                         41
#define PHVOLT_ADD_ASSIGN                     42
#define PHVOLT_SUB_ASSIGN                     43
#define PHVOLT_MUL_ASSIGN                     44
#define PHVOLT_DIV_ASSIGN                     45
#define PHVOLT_MACRO                          46
#define PHVOLT_PARENTHESES_CLOSE              47
#define PHVOLT_ENDMACRO                       48
#define PHVOLT_INTEGER                        49
#define PHVOLT_STRING                         50
#define PHVOLT_DOUBLE                         51
#define PHVOLT_NULL                           52
#define PHVOLT_FALSE                          53
#define PHVOLT_TRUE                           54
#define PHVOLT_CALL                           55
#define PHVOLT_ENDCALL                        56
#define PHVOLT_OPEN_EDELIMITER                57
#define PHVOLT_CLOSE_EDELIMITER               58
#define PHVOLT_BLOCK                          59
#define PHVOLT_ENDBLOCK                       60
#define PHVOLT_CACHE                          61
#define PHVOLT_ENDCACHE                       62
#define PHVOLT_EXTENDS                        63
#define PHVOLT_INCLUDE                        64
#define PHVOLT_WITH                           65
#define PHVOLT_DO                             66
#define PHVOLT_RETURN                         67
#define PHVOLT_AUTOESCAPE                     68
#define PHVOLT_ENDAUTOESCAPE                  69
#define PHVOLT_BREAK                          70
#define PHVOLT_CONTINUE                       71
#define PHVOLT_RAW_FRAGMENT                   72
#define PHVOLT_DEFINED                        73
#define PHVOLT_SBRACKET_CLOSE                 74
#define PHVOLT_CBRACKET_OPEN                  75
#define PHVOLT_CBRACKET_CLOSE                 76
#endif
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
#define KKNOCODE 114
#define KKACTIONTYPE unsigned short int
#if INTERFACE
#define phvolt_KTOKENTYPE phvolt_parser_token*
#endif
typedef union {
  phvolt_KTOKENTYPE kk0;
  zval* kk132;
  int kk227;
} KKMINORTYPE;
#define KKSTACKDEPTH 100
#if INTERFACE
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = kkpParser->status
#define phvolt_ARG_STORE kkpParser->status = status
#endif
#define KKNSTATE 322
#define KKNRULE 133
#define KKERRORSYMBOL 77
#define KKERRSYMDT kk227
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
 /*     0 */    82,   92,   23,   60,   52,   54,   64,   62,   66,   72,
 /*    10 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*    20 */    56,   89,   58,   84,   87,   88,   96,   80,  288,  162,
 /*    30 */    82,   92,  128,   60,   52,   54,   64,   62,   66,   72,
 /*    40 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*    50 */    56,   89,   58,   84,   87,   88,   96,   80,  244,  213,
 /*    60 */    48,   46,   50,   43,   40,   56,   89,   58,   84,   87,
 /*    70 */    88,   96,   80,  247,  295,  160,  255,  127,  168,  183,
 /*    80 */    82,   92,  170,   60,   52,   54,   64,   62,   66,   72,
 /*    90 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   100 */    56,   89,   58,   84,   87,   88,   96,   80,  322,  223,
 /*   110 */    82,   92,  169,   60,   52,   54,   64,   62,   66,   72,
 /*   120 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   130 */    56,   89,   58,   84,   87,   88,   96,   80,  304,  299,
 /*   140 */    82,   92,  224,   60,   52,   54,   64,   62,   66,   72,
 /*   150 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   160 */    56,   89,   58,   84,   87,   88,   96,   80,   30,   26,
 /*   170 */    82,   92,   32,   60,   52,   54,   64,   62,   66,   72,
 /*   180 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   190 */    56,   89,   58,   84,   87,   88,   96,   80,  108,   39,
 /*   200 */    82,   92,  108,   60,   52,   54,   64,   62,   66,   72,
 /*   210 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   220 */    56,   89,   58,   84,   87,   88,   96,   80,   82,   92,
 /*   230 */    94,   60,   52,   54,   64,   62,   66,   72,   74,   76,
 /*   240 */    78,   68,   70,   48,   46,   50,   43,   40,   56,   89,
 /*   250 */    58,   84,   87,   88,   96,   80,   43,   40,   56,   89,
 /*   260 */    58,   84,   87,   88,   96,   80,   84,   87,   88,   96,
 /*   270 */    80,   91,  112,  128,  107,   82,   92,  276,   60,   52,
 /*   280 */    54,   64,   62,   66,   72,   74,   76,   78,   68,   70,
 /*   290 */    48,   46,   50,   43,   40,   56,   89,   58,   84,   87,
 /*   300 */    88,   96,   80,   89,   58,   84,   87,   88,   96,   80,
 /*   310 */   281,  282,  283,  284,  285,  286,  269,  287,  197,  102,
 /*   320 */   234,  249,  270,   82,   92,   36,   60,   52,   54,   64,
 /*   330 */    62,   66,   72,   74,   76,   78,   68,   70,   48,   46,
 /*   340 */    50,   43,   40,   56,   89,   58,   84,   87,   88,   96,
 /*   350 */    80,   85,  226,   82,   92,  136,   60,   52,   54,   64,
 /*   360 */    62,   66,   72,   74,   76,   78,   68,   70,   48,   46,
 /*   370 */    50,   43,   40,   56,   89,   58,   84,   87,   88,   96,
 /*   380 */    80,  115,  229,   82,   92,  137,   60,   52,   54,   64,
 /*   390 */    62,   66,   72,   74,   76,   78,   68,   70,   48,   46,
 /*   400 */    50,   43,   40,   56,   89,   58,   84,   87,   88,   96,
 /*   410 */    80,  131,  232,   82,   92,  435,   60,   52,   54,   64,
 /*   420 */    62,   66,   72,   74,   76,   78,   68,   70,   48,   46,
 /*   430 */    50,   43,   40,   56,   89,   58,   84,   87,   88,   96,
 /*   440 */    80,   92,  436,   60,   52,   54,   64,   62,   66,   72,
 /*   450 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   460 */    56,   89,   58,   84,   87,   88,   96,   80,  246,  141,
 /*   470 */   143,  144,   82,   92,  157,   60,   52,   54,   64,   62,
 /*   480 */    66,   72,   74,   76,   78,   68,   70,   48,   46,   50,
 /*   490 */    43,   40,   56,   89,   58,   84,   87,   88,   96,   80,
 /*   500 */   435,  290,   82,   92,  159,   60,   52,   54,   64,   62,
 /*   510 */    66,   72,   74,   76,   78,   68,   70,   48,   46,   50,
 /*   520 */    43,   40,   56,   89,   58,   84,   87,   88,   96,   80,
 /*   530 */   436,  306,   82,   92,  166,   60,   52,   54,   64,   62,
 /*   540 */    66,   72,   74,   76,   78,   68,   70,   48,   46,   50,
 /*   550 */    43,   40,   56,   89,   58,   84,   87,   88,   96,   80,
 /*   560 */    82,   92,  172,   60,   52,   54,   64,   62,   66,   72,
 /*   570 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   580 */    56,   89,   58,   84,   87,   88,  195,   80,   60,   52,
 /*   590 */    54,   64,   62,   66,   72,   74,   76,   78,   68,   70,
 /*   600 */    48,   46,   50,   43,   40,   56,   89,   58,   84,   87,
 /*   610 */    88,   96,   80,   52,   54,   64,   62,   66,   72,   74,
 /*   620 */    76,   78,   68,   70,   48,   46,   50,   43,   40,   56,
 /*   630 */    89,   58,   84,   87,   88,   96,   80,  456,    1,    2,
 /*   640 */   248,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   650 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   660 */    64,   62,   66,   72,   74,   76,   78,   68,   70,   48,
 /*   670 */    46,   50,   43,   40,   56,   89,   58,   84,   87,   88,
 /*   680 */    96,   80,   27,  248,    4,    5,    6,    7,    8,    9,
 /*   690 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   700 */    20,   21,   22,   33,  248,    4,    5,    6,    7,    8,
 /*   710 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   720 */    19,   20,   21,   22,  163,  248,    4,    5,    6,    7,
 /*   730 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   740 */    18,   19,   20,   21,   22,  189,  248,    4,    5,    6,
 /*   750 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   760 */    17,   18,   19,   20,   21,   22,  199,  248,    4,    5,
 /*   770 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   780 */    16,   17,   18,   19,   20,   21,   22,  207,  248,    4,
 /*   790 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   800 */    15,   16,   17,   18,   19,   20,   21,   22,  214,  248,
 /*   810 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   820 */    14,   15,   16,   17,   18,   19,   20,   21,   22,  236,
 /*   830 */   248,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   840 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   850 */   251,  248,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   860 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   870 */    22,  257,  248,    4,    5,    6,    7,    8,    9,   10,
 /*   880 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   890 */    21,   22,  272,  248,    4,    5,    6,    7,    8,    9,
 /*   900 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   910 */    20,   21,   22,  291,  248,    4,    5,    6,    7,    8,
 /*   920 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   930 */    19,   20,   21,   22,  300,  248,    4,    5,    6,    7,
 /*   940 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   950 */    18,   19,   20,   21,   22,  307,  248,    4,    5,    6,
 /*   960 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   970 */    17,   18,   19,   20,   21,   22,    3,    4,    5,    6,
 /*   980 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   990 */    17,   18,   19,   20,   21,   22,   24,  203,   29,   31,
 /*  1000 */    37,  156,  158,  323,   23,  167,  171,  185,   25,   90,
 /*  1010 */   139,  184,  173,  175,  177,  179,  181,  140,  117,  117,
 /*  1020 */   193,  138,  186,  188,  204,  278,  211,  192,  218,  221,
 /*  1030 */   198,  227,  230,  233,  187,  240,  242,   24,  203,  315,
 /*  1040 */   317,   37,  156,  158,   97,  314,  167,   38,  202,  104,
 /*  1050 */   126,   28,  184,  104,  117,  134,  106,  117,  113,  117,
 /*  1060 */   244,  193,  125,  117,  205,  204,  266,  211,  206,  218,
 /*  1070 */   221,  219,  227,  230,  233,  247,  240,  242,   24,  203,
 /*  1080 */    35,  104,   37,  156,  158,  155,   97,  167,  111,   97,
 /*  1090 */   113,  117,  196,  184,  139,  117,  117,  134,  210,  117,
 /*  1100 */   129,  244,  193,  217,  220,  138,  204,  244,  211,  235,
 /*  1110 */   218,  221,  311,  227,  230,  233,  247,  240,  242,   24,
 /*  1120 */   203,   42,  247,   37,  156,  158,  154,  165,  167,  239,
 /*  1130 */   142,  117,  241,  243,  184,   45,  117,  250,   47,  267,
 /*  1140 */    49,  254,  256,  193,  260,  117,  263,  204,  117,  211,
 /*  1150 */   117,  218,  221,   34,  227,  230,  233,  164,  240,  242,
 /*  1160 */    24,  203,   51,   53,   37,  156,  158,  265,  244,  167,
 /*  1170 */   268,   55,  117,  117,  271,  184,   57,  191,  275,  190,
 /*  1180 */   279,  117,  280,  247,  193,  278,  117,  277,  204,  297,
 /*  1190 */   211,  294,  218,  221,   59,  227,  230,  233,  200,  240,
 /*  1200 */   242,   24,  203,  296,  117,   37,  156,  158,   61,  244,
 /*  1210 */   167,  303,  310,  244,  313,  316,  184,   63,  117,  318,
 /*  1220 */   319,  320,   65,  321,  247,  193,  201,  117,  247,  204,
 /*  1230 */   261,  211,  117,  218,  221,  244,  227,  230,  233,  208,
 /*  1240 */   240,  242,   24,  203,  248,   67,   37,  156,  158,   69,
 /*  1250 */   247,  167,   71,  248,  244,  117,  215,  184,   73,  117,
 /*  1260 */   248,  248,  117,   75,  248,  248,  193,  248,  117,  247,
 /*  1270 */   204,  209,  211,  117,  218,  221,  237,  227,  230,  233,
 /*  1280 */   252,  240,  242,   24,  203,  248,  244,   37,  156,  158,
 /*  1290 */    77,  248,  167,  248,   79,  244,   81,  258,  184,   83,
 /*  1300 */   117,  247,  248,  248,  117,  248,  117,  193,  248,  117,
 /*  1310 */   247,  204,  244,  211,  216,  218,  221,  273,  227,  230,
 /*  1320 */   233,  292,  240,  242,   24,  203,  248,  247,   37,  156,
 /*  1330 */   158,   86,  244,  167,   93,   95,  244,  248,  301,  184,
 /*  1340 */    99,  117,  248,  248,  117,  117,  248,  247,  193,  248,
 /*  1350 */   117,  247,  204,  244,  211,  248,  218,  221,  308,  227,
 /*  1360 */   230,  233,  238,  240,  242,   24,  203,  248,  247,   37,
 /*  1370 */   156,  158,  101,  244,  167,  116,  248,  244,  248,  248,
 /*  1380 */   184,  132,  117,  248,  248,  117,  151,  248,  247,  193,
 /*  1390 */   248,  117,  247,  204,  244,  211,  117,  218,  221,  248,
 /*  1400 */   227,  230,  233,  253,  240,  242,   24,  203,  153,  247,
 /*  1410 */    37,  156,  158,  161,  244,  167,  174,  248,  117,  248,
 /*  1420 */   248,  184,  176,  117,  248,  178,  117,  248,  248,  247,
 /*  1430 */   193,  248,  117,  248,  204,  117,  211,  259,  218,  221,
 /*  1440 */   180,  227,  230,  233,  248,  240,  242,   24,  203,  182,
 /*  1450 */   117,   37,  156,  158,  194,  212,  167,  248,  248,  117,
 /*  1460 */   222,  248,  184,  225,  117,  117,  248,  248,  228,  248,
 /*  1470 */   117,  193,  248,  117,  248,  204,  262,  211,  117,  218,
 /*  1480 */   221,  248,  227,  230,  233,  248,  240,  242,   24,  203,
 /*  1490 */   231,  245,   37,  156,  158,  248,  289,  167,  298,  305,
 /*  1500 */   117,  117,  248,  184,  248,  274,  117,  248,  117,  117,
 /*  1510 */   248,  248,  193,  248,  248,  248,  204,  248,  211,  248,
 /*  1520 */   218,  221,  248,  227,  230,  233,  248,  240,  242,   24,
 /*  1530 */   203,  248,  248,   37,  156,  158,  248,  293,  167,  248,
 /*  1540 */   248,  248,  248,  248,  184,  248,  248,  248,  248,  248,
 /*  1550 */   248,  248,  248,  193,  248,  248,  248,  204,  248,  211,
 /*  1560 */   248,  218,  221,  248,  227,  230,  233,  248,  240,  242,
 /*  1570 */    24,  203,  248,  248,   37,  156,  158,  248,  302,  167,
 /*  1580 */   248,  248,  248,  248,  248,  184,  248,  248,  248,  248,
 /*  1590 */   248,  248,  248,  248,  193,  248,  248,  248,  204,  248,
 /*  1600 */   211,  248,  218,  221,  248,  227,  230,  233,  248,  240,
 /*  1610 */   242,   24,  203,  248,  248,   37,  156,  158,  248,  309,
 /*  1620 */   167,  248,  248,  248,  248,  248,  184,  248,  248,  248,
 /*  1630 */   248,  248,  248,  248,  248,  193,  248,  248,  248,  204,
 /*  1640 */   248,  211,  248,  218,  221,  248,  227,  230,  233,  248,
 /*  1650 */   240,  242,   24,  203,  312,  248,   37,  156,  158,  248,
 /*  1660 */   248,  167,  248,  248,  248,  248,  248,  184,  248,  248,
 /*  1670 */   248,  248,  248,  248,  248,  248,  193,  248,  248,  248,
 /*  1680 */   204,  248,  211,  248,  218,  221,  248,  227,  230,  233,
 /*  1690 */   248,  240,  242,   24,  203,  248,  248,   37,  156,  158,
 /*  1700 */   248,  248,  167,  248,  248,  248,  248,  248,  184,  248,
 /*  1710 */   248,  248,  248,  248,  248,  248,  248,  193,  248,  248,
 /*  1720 */   248,  204,  248,  211,  248,  218,  221,  248,  227,  230,
 /*  1730 */   233,  248,  240,  242,  248,  248,  248,  152,  248,   44,
 /*  1740 */    41,  248,  103,  248,   98,  248,  248,  100,  248,  248,
 /*  1750 */   248,  248,  248,  248,  248,  248,  118,  248,  248,  248,
 /*  1760 */   248,  248,  248,  248,  248,  248,  248,  119,  120,  121,
 /*  1770 */   122,  123,  124,  248,  248,  150,  248,  248,   44,   41,
 /*  1780 */   248,  103,  248,   98,  248,  248,  100,  248,  248,  248,
 /*  1790 */   248,  248,  248,  109,  248,  118,  248,   44,   41,  248,
 /*  1800 */   103,  248,  147,  248,  248,  100,  119,  120,  121,  122,
 /*  1810 */   123,  124,  248,  248,  118,  248,  248,  135,  248,  248,
 /*  1820 */   248,  248,  248,  248,  248,  119,  120,  121,  122,  123,
 /*  1830 */   124,  248,  109,   44,   41,  248,  103,  248,   98,  248,
 /*  1840 */   248,  100,  248,  248,  248,  248,  248,  248,  248,  149,
 /*  1850 */   146,  109,   44,   41,  248,  103,  248,   98,  248,  248,
 /*  1860 */   100,  145,  120,  121,  122,  123,  124,  248,  248,  118,
 /*  1870 */   248,   44,   41,  248,  103,  248,   98,  248,  133,  100,
 /*  1880 */   119,  130,  121,  122,  123,  124,  248,  109,  118,  248,
 /*  1890 */   248,  248,  248,  248,  248,  248,  248,  248,  248,  119,
 /*  1900 */   114,  121,  122,  123,  124,  248,  109,  248,  248,   44,
 /*  1910 */    41,  248,  103,  248,   98,  248,  248,  100,  248,  248,
 /*  1920 */   248,  248,  248,  248,  105,  109,  118,  248,   44,   41,
 /*  1930 */   248,  103,  248,   98,  248,  248,  100,  119,  114,  121,
 /*  1940 */   122,  123,  124,  248,  248,  118,  248,  248,  248,  248,
 /*  1950 */   248,  248,  248,  248,  248,  248,  119,  120,  121,  122,
 /*  1960 */   123,  124,  248,  109,  110,  248,  248,   44,   41,  248,
 /*  1970 */   103,  248,   98,  248,  248,  100,  248,  248,  248,  248,
 /*  1980 */   148,  248,  109,  248,  118,  248,   44,   41,  248,  103,
 /*  1990 */   248,   98,  248,  264,  100,  119,  130,  121,  122,  123,
 /*  2000 */   124,  248,  248,  118,  248,  248,  248,  248,  248,  248,
 /*  2010 */   248,  248,  248,  248,  119,  120,  121,  122,  123,  124,
 /*  2020 */   248,  109,   44,   41,  248,  103,  248,   98,  248,  248,
 /*  2030 */   100,  248,  248,  248,  248,  248,  248,  248,  248,  118,
 /*  2040 */   109,   44,   41,  248,  103,  248,   98,  248,  248,  100,
 /*  2050 */   119,  114,  121,  122,  123,  124,  248,  248,  118,  248,
 /*  2060 */   248,  248,  248,  248,  248,  248,  248,  248,  248,  119,
 /*  2070 */   130,  121,  122,  123,  124,  248,  109,  248,  248,  248,
 /*  2080 */   248,  248,  248,  248,  248,  248,  248,  248,  248,  248,
 /*  2090 */   248,  248,  248,  248,  248,  109,
};
static KKCODETYPE kk_lookahead[] = {
 /*     0 */     3,    4,    1,    6,    7,    8,    9,   10,   11,   12,
 /*    10 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    20 */    23,   24,   25,   26,   27,   28,   29,   30,   31,   32,
 /*    30 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*    40 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    50 */    23,   24,   25,   26,   27,   28,   29,   30,   57,   32,
 /*    60 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*    70 */    28,   29,   30,   72,    2,    3,   49,   47,  102,  103,
 /*    80 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*    90 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   100 */    23,   24,   25,   26,   27,   28,   29,   30,    0,   32,
 /*   110 */     3,    4,   32,    6,    7,    8,    9,   10,   11,   12,
 /*   120 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   130 */    23,   24,   25,   26,   27,   28,   29,   30,   31,   32,
 /*   140 */     3,    4,   65,    6,    7,    8,    9,   10,   11,   12,
 /*   150 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   160 */    23,   24,   25,   26,   27,   28,   29,   30,   32,   32,
 /*   170 */     3,    4,   32,    6,    7,    8,    9,   10,   11,   12,
 /*   180 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   190 */    23,   24,   25,   26,   27,   28,   29,   30,    2,   32,
 /*   200 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*   210 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   220 */    23,   24,   25,   26,   27,   28,   29,   30,    3,    4,
 /*   230 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   240 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   250 */    25,   26,   27,   28,   29,   30,   21,   22,   23,   24,
 /*   260 */    25,   26,   27,   28,   29,   30,   26,   27,   28,   29,
 /*   270 */    30,   74,   76,    2,   74,    3,    4,    2,    6,    7,
 /*   280 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   290 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   300 */    28,   29,   30,   24,   25,   26,   27,   28,   29,   30,
 /*   310 */    49,   50,   51,   52,   53,   54,  104,  105,   47,   47,
 /*   320 */    53,   54,   47,    3,    4,   32,    6,    7,    8,    9,
 /*   330 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   340 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   350 */    30,    3,   32,    3,    4,  109,    6,    7,    8,    9,
 /*   360 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   370 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   380 */    30,    5,   32,    3,    4,   74,    6,    7,    8,    9,
 /*   390 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   400 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   410 */    30,    5,   32,    3,    4,   74,    6,    7,    8,    9,
 /*   420 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   430 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   440 */    30,    4,   74,    6,    7,    8,    9,   10,   11,   12,
 /*   450 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   460 */    23,   24,   25,   26,   27,   28,   29,   30,   58,    5,
 /*   470 */   109,   74,    3,    4,   32,    6,    7,    8,    9,   10,
 /*   480 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   490 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
 /*   500 */     5,   32,    3,    4,   38,    6,    7,    8,    9,   10,
 /*   510 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   520 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
 /*   530 */     5,   32,    3,    4,   32,    6,    7,    8,    9,   10,
 /*   540 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   550 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
 /*   560 */     3,    4,   38,    6,    7,    8,    9,   10,   11,   12,
 /*   570 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   580 */    23,   24,   25,   26,   27,   28,   29,   30,    6,    7,
 /*   590 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   600 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   610 */    28,   29,   30,    7,    8,    9,   10,   11,   12,   13,
 /*   620 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   630 */    24,   25,   26,   27,   28,   29,   30,   78,   79,   80,
 /*   640 */    81,   82,   83,   84,   85,   86,   87,   88,   89,   90,
 /*   650 */    91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
 /*   660 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   670 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   680 */    29,   30,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   690 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   700 */    98,   99,  100,   80,   81,   82,   83,   84,   85,   86,
 /*   710 */    87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
 /*   720 */    97,   98,   99,  100,   80,   81,   82,   83,   84,   85,
 /*   730 */    86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
 /*   740 */    96,   97,   98,   99,  100,   80,   81,   82,   83,   84,
 /*   750 */    85,   86,   87,   88,   89,   90,   91,   92,   93,   94,
 /*   760 */    95,   96,   97,   98,   99,  100,   80,   81,   82,   83,
 /*   770 */    84,   85,   86,   87,   88,   89,   90,   91,   92,   93,
 /*   780 */    94,   95,   96,   97,   98,   99,  100,   80,   81,   82,
 /*   790 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   800 */    93,   94,   95,   96,   97,   98,   99,  100,   80,   81,
 /*   810 */    82,   83,   84,   85,   86,   87,   88,   89,   90,   91,
 /*   820 */    92,   93,   94,   95,   96,   97,   98,   99,  100,   80,
 /*   830 */    81,   82,   83,   84,   85,   86,   87,   88,   89,   90,
 /*   840 */    91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
 /*   850 */    80,   81,   82,   83,   84,   85,   86,   87,   88,   89,
 /*   860 */    90,   91,   92,   93,   94,   95,   96,   97,   98,   99,
 /*   870 */   100,   80,   81,   82,   83,   84,   85,   86,   87,   88,
 /*   880 */    89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
 /*   890 */    99,  100,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   900 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   910 */    98,   99,  100,   80,   81,   82,   83,   84,   85,   86,
 /*   920 */    87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
 /*   930 */    97,   98,   99,  100,   80,   81,   82,   83,   84,   85,
 /*   940 */    86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
 /*   950 */    96,   97,   98,   99,  100,   80,   81,   82,   83,   84,
 /*   960 */    85,   86,   87,   88,   89,   90,   91,   92,   93,   94,
 /*   970 */    95,   96,   97,   98,   99,  100,   81,   82,   83,   84,
 /*   980 */    85,   86,   87,   88,   89,   90,   91,   92,   93,   94,
 /*   990 */    95,   96,   97,   98,   99,  100,   31,   32,   33,   34,
 /*  1000 */    35,   36,   37,    0,    1,   40,  103,   38,  101,  101,
 /*  1010 */    38,   46,   41,   42,   43,   44,   45,  109,  111,  111,
 /*  1020 */    55,   49,   29,   32,   59,   38,   61,   32,   63,   64,
 /*  1030 */    32,   66,   67,   68,   47,   70,   71,   31,   32,   33,
 /*  1040 */    34,   35,   36,   37,  101,    1,   40,  101,   32,  101,
 /*  1050 */   107,    1,   46,  101,  111,  112,  108,  111,  110,  111,
 /*  1060 */    57,   55,  110,  111,   38,   59,    1,   61,   32,   63,
 /*  1070 */    64,   50,   66,   67,   68,   72,   70,   71,   31,   32,
 /*  1080 */    33,  101,   35,   36,   37,  101,  101,   40,  108,  101,
 /*  1090 */   110,  111,  107,   46,   38,  111,  111,  112,   32,  111,
 /*  1100 */   112,   57,   55,   32,   32,   49,   59,   57,   61,   32,
 /*  1110 */    63,   64,    1,   66,   67,   68,   72,   70,   71,   31,
 /*  1120 */    32,  101,   72,   35,   36,   37,  101,   39,   40,   32,
 /*  1130 */    74,  111,   32,   32,   46,  101,  111,   32,  101,   56,
 /*  1140 */   101,   32,   32,   55,   32,  111,   32,   59,  111,   61,
 /*  1150 */   111,   63,   64,    1,   66,   67,   68,    1,   70,   71,
 /*  1160 */    31,   32,  101,  101,   35,   36,   37,   32,   57,   40,
 /*  1170 */    32,  101,  111,  111,   32,   46,  101,   48,   32,    1,
 /*  1180 */    41,  111,  106,   72,   55,   38,  111,  105,   59,    3,
 /*  1190 */    61,   32,   63,   64,  101,   66,   67,   68,    1,   70,
 /*  1200 */    71,   31,   32,   38,  111,   35,   36,   37,  101,   57,
 /*  1210 */    40,   32,   32,   57,   32,   32,   46,  101,  111,   32,
 /*  1220 */     1,   33,  101,   32,   72,   55,   56,  111,   72,   59,
 /*  1230 */     1,   61,  111,   63,   64,   57,   66,   67,   68,    1,
 /*  1240 */    70,   71,   31,   32,  113,  101,   35,   36,   37,  101,
 /*  1250 */    72,   40,  101,  113,   57,  111,    1,   46,  101,  111,
 /*  1260 */   113,  113,  111,  101,  113,  113,   55,  113,  111,   72,
 /*  1270 */    59,   60,   61,  111,   63,   64,    1,   66,   67,   68,
 /*  1280 */     1,   70,   71,   31,   32,  113,   57,   35,   36,   37,
 /*  1290 */   101,  113,   40,  113,  101,   57,  101,    1,   46,  101,
 /*  1300 */   111,   72,  113,  113,  111,  113,  111,   55,  113,  111,
 /*  1310 */    72,   59,   57,   61,   62,   63,   64,    1,   66,   67,
 /*  1320 */    68,    1,   70,   71,   31,   32,  113,   72,   35,   36,
 /*  1330 */    37,  101,   57,   40,  101,  101,   57,  113,    1,   46,
 /*  1340 */   101,  111,  113,  113,  111,  111,  113,   72,   55,  113,
 /*  1350 */   111,   72,   59,   57,   61,  113,   63,   64,    1,   66,
 /*  1360 */    67,   68,   69,   70,   71,   31,   32,  113,   72,   35,
 /*  1370 */    36,   37,  101,   57,   40,  101,  113,   57,  113,  113,
 /*  1380 */    46,  101,  111,  113,  113,  111,  101,  113,   72,   55,
 /*  1390 */   113,  111,   72,   59,   57,   61,  111,   63,   64,  113,
 /*  1400 */    66,   67,   68,   69,   70,   71,   31,   32,  101,   72,
 /*  1410 */    35,   36,   37,  101,   57,   40,  101,  113,  111,  113,
 /*  1420 */   113,   46,  101,  111,  113,  101,  111,  113,  113,   72,
 /*  1430 */    55,  113,  111,  113,   59,  111,   61,   62,   63,   64,
 /*  1440 */   101,   66,   67,   68,  113,   70,   71,   31,   32,  101,
 /*  1450 */   111,   35,   36,   37,  101,  101,   40,  113,  113,  111,
 /*  1460 */   101,  113,   46,  101,  111,  111,  113,  113,  101,  113,
 /*  1470 */   111,   55,  113,  111,  113,   59,   60,   61,  111,   63,
 /*  1480 */    64,  113,   66,   67,   68,  113,   70,   71,   31,   32,
 /*  1490 */   101,  101,   35,   36,   37,  113,  101,   40,  101,  101,
 /*  1500 */   111,  111,  113,   46,  113,   48,  111,  113,  111,  111,
 /*  1510 */   113,  113,   55,  113,  113,  113,   59,  113,   61,  113,
 /*  1520 */    63,   64,  113,   66,   67,   68,  113,   70,   71,   31,
 /*  1530 */    32,  113,  113,   35,   36,   37,  113,   39,   40,  113,
 /*  1540 */   113,  113,  113,  113,   46,  113,  113,  113,  113,  113,
 /*  1550 */   113,  113,  113,   55,  113,  113,  113,   59,  113,   61,
 /*  1560 */   113,   63,   64,  113,   66,   67,   68,  113,   70,   71,
 /*  1570 */    31,   32,  113,  113,   35,   36,   37,  113,   39,   40,
 /*  1580 */   113,  113,  113,  113,  113,   46,  113,  113,  113,  113,
 /*  1590 */   113,  113,  113,  113,   55,  113,  113,  113,   59,  113,
 /*  1600 */    61,  113,   63,   64,  113,   66,   67,   68,  113,   70,
 /*  1610 */    71,   31,   32,  113,  113,   35,   36,   37,  113,   39,
 /*  1620 */    40,  113,  113,  113,  113,  113,   46,  113,  113,  113,
 /*  1630 */   113,  113,  113,  113,  113,   55,  113,  113,  113,   59,
 /*  1640 */   113,   61,  113,   63,   64,  113,   66,   67,   68,  113,
 /*  1650 */    70,   71,   31,   32,   33,  113,   35,   36,   37,  113,
 /*  1660 */   113,   40,  113,  113,  113,  113,  113,   46,  113,  113,
 /*  1670 */   113,  113,  113,  113,  113,  113,   55,  113,  113,  113,
 /*  1680 */    59,  113,   61,  113,   63,   64,  113,   66,   67,   68,
 /*  1690 */   113,   70,   71,   31,   32,  113,  113,   35,   36,   37,
 /*  1700 */   113,  113,   40,  113,  113,  113,  113,  113,   46,  113,
 /*  1710 */   113,  113,  113,  113,  113,  113,  113,   55,  113,  113,
 /*  1720 */   113,   59,  113,   61,  113,   63,   64,  113,   66,   67,
 /*  1730 */    68,  113,   70,   71,  113,  113,  113,   19,  113,   21,
 /*  1740 */    22,  113,   24,  113,   26,  113,  113,   29,  113,  113,
 /*  1750 */   113,  113,  113,  113,  113,  113,   38,  113,  113,  113,
 /*  1760 */   113,  113,  113,  113,  113,  113,  113,   49,   50,   51,
 /*  1770 */    52,   53,   54,  113,  113,   18,  113,  113,   21,   22,
 /*  1780 */   113,   24,  113,   26,  113,  113,   29,  113,  113,  113,
 /*  1790 */   113,  113,  113,   75,  113,   38,  113,   21,   22,  113,
 /*  1800 */    24,  113,   26,  113,  113,   29,   49,   50,   51,   52,
 /*  1810 */    53,   54,  113,  113,   38,  113,  113,    5,  113,  113,
 /*  1820 */   113,  113,  113,  113,  113,   49,   50,   51,   52,   53,
 /*  1830 */    54,  113,   75,   21,   22,  113,   24,  113,   26,  113,
 /*  1840 */   113,   29,  113,  113,  113,  113,  113,  113,  113,   73,
 /*  1850 */    38,   75,   21,   22,  113,   24,  113,   26,  113,  113,
 /*  1860 */    29,   49,   50,   51,   52,   53,   54,  113,  113,   38,
 /*  1870 */   113,   21,   22,  113,   24,  113,   26,  113,   47,   29,
 /*  1880 */    49,   50,   51,   52,   53,   54,  113,   75,   38,  113,
 /*  1890 */   113,  113,  113,  113,  113,  113,  113,  113,  113,   49,
 /*  1900 */    50,   51,   52,   53,   54,  113,   75,  113,  113,   21,
 /*  1910 */    22,  113,   24,  113,   26,  113,  113,   29,  113,  113,
 /*  1920 */   113,  113,  113,  113,   74,   75,   38,  113,   21,   22,
 /*  1930 */   113,   24,  113,   26,  113,  113,   29,   49,   50,   51,
 /*  1940 */    52,   53,   54,  113,  113,   38,  113,  113,  113,  113,
 /*  1950 */   113,  113,  113,  113,  113,  113,   49,   50,   51,   52,
 /*  1960 */    53,   54,  113,   75,   76,  113,  113,   21,   22,  113,
 /*  1970 */    24,  113,   26,  113,  113,   29,  113,  113,  113,  113,
 /*  1980 */    73,  113,   75,  113,   38,  113,   21,   22,  113,   24,
 /*  1990 */   113,   26,  113,   47,   29,   49,   50,   51,   52,   53,
 /*  2000 */    54,  113,  113,   38,  113,  113,  113,  113,  113,  113,
 /*  2010 */   113,  113,  113,  113,   49,   50,   51,   52,   53,   54,
 /*  2020 */   113,   75,   21,   22,  113,   24,  113,   26,  113,  113,
 /*  2030 */    29,  113,  113,  113,  113,  113,  113,  113,  113,   38,
 /*  2040 */    75,   21,   22,  113,   24,  113,   26,  113,  113,   29,
 /*  2050 */    49,   50,   51,   52,   53,   54,  113,  113,   38,  113,
 /*  2060 */   113,  113,  113,  113,  113,  113,  113,  113,  113,   49,
 /*  2070 */    50,   51,   52,   53,   54,  113,   75,  113,  113,  113,
 /*  2080 */   113,  113,  113,  113,  113,  113,  113,  113,  113,  113,
 /*  2090 */   113,  113,  113,  113,  113,   75,
};
#define KK_SHIFT_USE_DFLT (-4)
static short kk_shift_ofst[] = {
 /*     0 */     1,  108, 1003,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    20 */    -4,   -4,   -4, 1662, 1965,  137, 1044, 1050,  965,  136,
 /*    30 */    -4,  140, 1111, 1152, 1047,  293,   -4, 1965,  167,   -4,
 /*    40 */  1965, 1965,  279, 1965, 1965,  279, 1718,  235, 1757,  235,
 /*    50 */  1965,  235, 1965,  651, 1965,  651, 1965,  279, 1965,  240,
 /*    60 */  1965,  606, 1965,   42, 1776,   42, 1965,   42, 1965,   42,
 /*    70 */  1965,   42, 1965,   42, 1965,   42, 1965,   42, 1965,   42,
 /*    80 */  1965,   -4, 1965,  437,  348, 1965,  240,   -4,   -4, 1812,
 /*    90 */   197,   -4, 1965,  225, 1965,  582, 1831,  529, 1965,  240,
 /*   100 */  1965,  272,   -4, 1850,  529,   -4,  200,   -4, 2001, 1888,
 /*   110 */    -4,  196,   -4,   -4,  376, 1965,  529,   -4,   -4,   -4,
 /*   120 */    -4,   -4,   -4,   -4,   -4,   -4,   30,   -4, 2020,   -4,
 /*   130 */   406, 1965,  529,   -4,   -4,  972,  311,   -4,  341,  368,
 /*   140 */   464, 1056,   -4,  397,   -4,  495,  525, 1907,   -4,   -4,
 /*   150 */  1965,  235, 1965,  235,  279,  279,  442,   -4,  466,   72,
 /*   160 */  1965,   -3,    1, 1156, 1088,  502,   -4,  524,   80,   -4,
 /*   170 */   524,   -4,  971, 1965,  529, 1965,  529, 1965,  529, 1965,
 /*   180 */   529, 1965,  529,   -4,  969,  993,  987,  991,    1, 1178,
 /*   190 */  1129,  995,   -4, 1965,  557, 1946,  271,  998,    1, 1197,
 /*   200 */  1170, 1016,   -4,   -4, 1026, 1036, 1229, 1238, 1211, 1066,
 /*   210 */    -4, 1965,   27,    1, 1255, 1252, 1071,   -4, 1021, 1072,
 /*   220 */    -4, 1965,   77,   -4, 1965,  320,   -4, 1965,  350,   -4,
 /*   230 */  1965,  380,   -4,  267, 1077,    1, 1275, 1293, 1097,   -4,
 /*   240 */  1100,   -4, 1101,   -4, 1965,  410,   -4,   -4,   -4, 1105,
 /*   250 */     1, 1279, 1334, 1109,   -4, 1110,    1, 1296, 1375, 1112,
 /*   260 */    -4, 1416, 1114,   -4, 1135, 1065, 1083, 1138,   -4,  275,
 /*   270 */  1142,    1, 1316, 1457, 1146,   -4, 1147,   -4, 1139,  261,
 /*   280 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4, 1965,  469,
 /*   290 */     1, 1320, 1498, 1159,   -4, 1165, 1186, 1965,  107,    1,
 /*   300 */  1337, 1539, 1179,   -4, 1965,  499,    1, 1357, 1580, 1180,
 /*   310 */    -4, 1621, 1182,   -4, 1006, 1183,   -4, 1187, 1219, 1188,
 /*   320 */  1191,   -4,
};
#define KK_REDUCE_USE_DFLT (-25)
static short kk_reduce_ofst[] = {
 /*     0 */   559,  -25,  895,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
 /*    10 */   -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
 /*    20 */   -25,  -25,  -25,  -25,  907,  -25,  602,  895,  -25,  -25,
 /*    30 */   -25,  -25,  623,  895,  -25,  -25,  -25,  946,  -25,  -25,
 /*    40 */   984, 1020,  -25, 1025, 1034,  -25, 1037,  -25, 1039,  -25,
 /*    50 */  1061,  -25, 1062,  -25, 1070,  -25, 1075,  -25, 1093,  -25,
 /*    60 */  1107,  -25, 1116,  -25, 1121,  -25, 1144,  -25, 1148,  -25,
 /*    70 */  1151,  -25, 1157,  -25, 1162,  -25, 1189,  -25, 1193,  -25,
 /*    80 */  1195,  -25, 1198,  -25,  -25, 1230,  -25,  -25,  -25,  908,
 /*    90 */   -25,  -25, 1233,  -25, 1234,  -25,  943,  -25, 1239,  -25,
 /*   100 */  1271,  -25,  -25,  948,  -25,  -25,  -25,  -25,  952,  980,
 /*   110 */   -25,  -25,  -25,  -25,  -25, 1274,  -25,  -25,  -25,  -25,
 /*   120 */   -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  988,  -25,
 /*   130 */   -25, 1280,  -25,  -25,  -25,  246,  -25,  -25,  -25,  -25,
 /*   140 */   -25,  361,  -25,  -25,  -25,  -25,  -25, 1239,  -25,  -25,
 /*   150 */  1285,  -25, 1307,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
 /*   160 */  1312,  -25,  644,  895,  -25,  -25,  -25,  -24,  -25,  -25,
 /*   170 */   903,  -25,  -25, 1315,  -25, 1321,  -25, 1324,  -25, 1339,
 /*   180 */   -25, 1348,  -25,  -25,  -25,  -25,  212,  -25,  665,  895,
 /*   190 */   -25,  -25,  -25, 1353,  -25,  985,  -25,  -25,  686,  895,
 /*   200 */   -25,  -25,  -25,  -25,  -25,  -25,  707,  895,  -25,  -25,
 /*   210 */   -25, 1354,  -25,  728,  895,  -25,  -25,  -25,  -25,  -25,
 /*   220 */   -25, 1359,  -25,  -25, 1362,  -25,  -25, 1367,  -25,  -25,
 /*   230 */  1389,  -25,  -25,  -25,  -25,  749,  895,  -25,  -25,  -25,
 /*   240 */   -25,  -25,  -25,  -25, 1390,  -25,  -25,  -25,  -25,  -25,
 /*   250 */   770,  895,  -25,  -25,  -25,  -25,  791,  895,  -25,  -25,
 /*   260 */   -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
 /*   270 */   -25,  812,  895,  -25,  -25,  -25, 1082,  -25,  -25, 1076,
 /*   280 */   -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25, 1395,  -25,
 /*   290 */   833,  895,  -25,  -25,  -25,  -25,  -25, 1397,  -25,  854,
 /*   300 */   895,  -25,  -25,  -25, 1398,  -25,  875,  895,  -25,  -25,
 /*   310 */   -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
 /*   320 */   -25,  -25,
};
static KKACTIONTYPE kk_default[] = {
 /*     0 */   455,  455,  455,  324,  326,  327,  328,  329,  330,  331,
 /*    10 */   332,  333,  334,  335,  336,  337,  338,  339,  340,  341,
 /*    20 */   342,  343,  344,  455,  455,  455,  455,  455,  455,  455,
 /*    30 */   345,  455,  455,  455,  455,  455,  347,  455,  455,  350,
 /*    40 */   455,  455,  394,  455,  455,  395,  455,  398,  455,  400,
 /*    50 */   455,  402,  455,  403,  455,  404,  455,  405,  455,  406,
 /*    60 */   455,  407,  455,  408,  455,  411,  455,  412,  455,  413,
 /*    70 */   455,  414,  455,  415,  455,  416,  455,  417,  455,  418,
 /*    80 */   455,  419,  455,  420,  455,  455,  421,  423,  424,  455,
 /*    90 */   455,  430,  455,  455,  455,  431,  455,  446,  455,  422,
 /*   100 */   455,  455,  425,  455,  440,  426,  455,  427,  455,  455,
 /*   110 */   428,  455,  429,  438,  450,  455,  439,  441,  448,  449,
 /*   120 */   450,  451,  452,  453,  454,  437,  455,  442,  455,  444,
 /*   130 */   450,  455,  447,  443,  445,  455,  455,  432,  455,  455,
 /*   140 */   455,  455,  433,  455,  434,  449,  448,  455,  409,  410,
 /*   150 */   455,  401,  455,  399,  397,  396,  455,  351,  455,  455,
 /*   160 */   455,  455,  455,  455,  455,  455,  352,  455,  455,  356,
 /*   170 */   455,  357,  455,  455,  359,  455,  360,  455,  361,  455,
 /*   180 */   362,  455,  363,  358,  455,  455,  455,  455,  455,  455,
 /*   190 */   455,  455,  364,  455,  455,  455,  455,  442,  455,  455,
 /*   200 */   455,  455,  376,  378,  455,  455,  455,  455,  455,  455,
 /*   210 */   380,  455,  455,  455,  455,  455,  455,  382,  455,  455,
 /*   220 */   384,  455,  455,  385,  455,  455,  386,  455,  455,  387,
 /*   230 */   455,  455,  388,  455,  455,  455,  455,  455,  455,  389,
 /*   240 */   455,  391,  455,  392,  455,  455,  379,  393,  325,  455,
 /*   250 */   455,  455,  455,  455,  390,  455,  455,  455,  455,  455,
 /*   260 */   383,  455,  455,  381,  443,  455,  455,  455,  377,  455,
 /*   270 */   455,  455,  455,  455,  455,  365,  455,  366,  368,  455,
 /*   280 */   369,  370,  371,  372,  373,  374,  375,  367,  455,  455,
 /*   290 */   455,  455,  455,  455,  353,  455,  455,  455,  455,  455,
 /*   300 */   455,  455,  455,  354,  455,  455,  455,  455,  455,  455,
 /*   310 */   355,  455,  455,  348,  455,  455,  346,  455,  455,  455,
 /*   320 */   455,  349,
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
  "MUL_ASSIGN",    "DIV_ASSIGN",    "MACRO",         "PARENTHESES_CLOSE",
  "ENDMACRO",      "INTEGER",       "STRING",        "DOUBLE",      
  "NULL",          "FALSE",         "TRUE",          "CALL",        
  "ENDCALL",       "OPEN_EDELIMITER",  "CLOSE_EDELIMITER",  "BLOCK",       
  "ENDBLOCK",      "CACHE",         "ENDCACHE",      "EXTENDS",     
  "INCLUDE",       "WITH",          "DO",            "RETURN",      
  "AUTOESCAPE",    "ENDAUTOESCAPE",  "BREAK",         "CONTINUE",    
  "RAW_FRAGMENT",  "DEFINED",       "SBRACKET_CLOSE",  "CBRACKET_OPEN",
  "CBRACKET_CLOSE",  "error",         "program",       "volt_language",
  "statement_list",  "statement",     "raw_fragment",  "if_statement",
  "elseif_statement",  "elsefor_statement",  "for_statement",  "set_statement",
  "echo_statement",  "block_statement",  "cache_statement",  "extends_statement",
  "include_statement",  "do_statement",  "return_statement",  "autoescape_statement",
  "break_statement",  "continue_statement",  "macro_statement",  "empty_statement",
  "macro_call_statement",  "expr",          "set_assignments",  "set_assignment",
  "macro_parameters",  "macro_parameter",  "macro_parameter_default",  "argument_list",
  "array_list",    "slice_offset",  "array_item",    "function_call",
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
 /*  37 */ "set_assignment ::= IDENTIFIER ASSIGN expr",
 /*  38 */ "set_assignment ::= IDENTIFIER ADD_ASSIGN expr",
 /*  39 */ "set_assignment ::= IDENTIFIER SUB_ASSIGN expr",
 /*  40 */ "set_assignment ::= IDENTIFIER MUL_ASSIGN expr",
 /*  41 */ "set_assignment ::= IDENTIFIER DIV_ASSIGN expr",
 /*  42 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  43 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN macro_parameters PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  44 */ "macro_parameters ::= macro_parameters COMMA macro_parameter",
 /*  45 */ "macro_parameters ::= macro_parameter",
 /*  46 */ "macro_parameter ::= IDENTIFIER",
 /*  47 */ "macro_parameter ::= IDENTIFIER ASSIGN macro_parameter_default",
 /*  48 */ "macro_parameter_default ::= INTEGER",
 /*  49 */ "macro_parameter_default ::= STRING",
 /*  50 */ "macro_parameter_default ::= DOUBLE",
 /*  51 */ "macro_parameter_default ::= NULL",
 /*  52 */ "macro_parameter_default ::= FALSE",
 /*  53 */ "macro_parameter_default ::= TRUE",
 /*  54 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  55 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  56 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  57 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  58 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  59 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  60 */ "cache_statement ::= OPEN_DELIMITER CACHE expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  61 */ "cache_statement ::= OPEN_DELIMITER CACHE expr INTEGER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  62 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  63 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr CLOSE_DELIMITER",
 /*  64 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr WITH expr CLOSE_DELIMITER",
 /*  65 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  66 */ "return_statement ::= OPEN_DELIMITER RETURN expr CLOSE_DELIMITER",
 /*  67 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE FALSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  68 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE TRUE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  69 */ "break_statement ::= OPEN_DELIMITER BREAK CLOSE_DELIMITER",
 /*  70 */ "continue_statement ::= OPEN_DELIMITER CONTINUE CLOSE_DELIMITER",
 /*  71 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  72 */ "expr ::= MINUS expr",
 /*  73 */ "expr ::= PLUS expr",
 /*  74 */ "expr ::= expr MINUS expr",
 /*  75 */ "expr ::= expr PLUS expr",
 /*  76 */ "expr ::= expr TIMES expr",
 /*  77 */ "expr ::= expr TIMES TIMES expr",
 /*  78 */ "expr ::= expr DIVIDE expr",
 /*  79 */ "expr ::= expr DIVIDE DIVIDE expr",
 /*  80 */ "expr ::= expr MOD expr",
 /*  81 */ "expr ::= expr AND expr",
 /*  82 */ "expr ::= expr OR expr",
 /*  83 */ "expr ::= expr CONCAT expr",
 /*  84 */ "expr ::= expr PIPE expr",
 /*  85 */ "expr ::= expr RANGE expr",
 /*  86 */ "expr ::= expr EQUALS expr",
 /*  87 */ "expr ::= expr IS NOT DEFINED",
 /*  88 */ "expr ::= expr IS DEFINED",
 /*  89 */ "expr ::= expr IS expr",
 /*  90 */ "expr ::= expr NOTEQUALS expr",
 /*  91 */ "expr ::= expr IDENTICAL expr",
 /*  92 */ "expr ::= expr NOTIDENTICAL expr",
 /*  93 */ "expr ::= expr LESS expr",
 /*  94 */ "expr ::= expr GREATER expr",
 /*  95 */ "expr ::= expr GREATEREQUAL expr",
 /*  96 */ "expr ::= expr LESSEQUAL expr",
 /*  97 */ "expr ::= expr DOT expr",
 /*  98 */ "expr ::= expr IN expr",
 /*  99 */ "expr ::= expr NOT IN expr",
 /* 100 */ "expr ::= NOT expr",
 /* 101 */ "expr ::= expr INCR",
 /* 102 */ "expr ::= expr DECR",
 /* 103 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 104 */ "expr ::= SBRACKET_OPEN SBRACKET_CLOSE",
 /* 105 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /* 106 */ "expr ::= CBRACKET_OPEN CBRACKET_CLOSE",
 /* 107 */ "expr ::= CBRACKET_OPEN array_list CBRACKET_CLOSE",
 /* 108 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /* 109 */ "expr ::= expr QUESTION expr COLON expr",
 /* 110 */ "expr ::= expr SBRACKET_OPEN COLON slice_offset SBRACKET_CLOSE",
 /* 111 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON SBRACKET_CLOSE",
 /* 112 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON slice_offset SBRACKET_CLOSE",
 /* 113 */ "slice_offset ::= INTEGER",
 /* 114 */ "slice_offset ::= IDENTIFIER",
 /* 115 */ "array_list ::= array_list COMMA array_item",
 /* 116 */ "array_list ::= array_item",
 /* 117 */ "array_item ::= STRING COLON expr",
 /* 118 */ "array_item ::= expr",
 /* 119 */ "expr ::= function_call",
 /* 120 */ "function_call ::= expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 121 */ "function_call ::= expr PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 122 */ "argument_list ::= argument_list COMMA argument_item",
 /* 123 */ "argument_list ::= argument_item",
 /* 124 */ "argument_item ::= expr",
 /* 125 */ "argument_item ::= STRING COLON expr",
 /* 126 */ "expr ::= IDENTIFIER",
 /* 127 */ "expr ::= INTEGER",
 /* 128 */ "expr ::= STRING",
 /* 129 */ "expr ::= DOUBLE",
 /* 130 */ "expr ::= NULL",
 /* 131 */ "expr ::= FALSE",
 /* 132 */ "expr ::= TRUE",
};
#endif /* NDEBUG */

/*
** This function returns the symbolic name associated with a token
** value.
*/
const char *phvolt_TokenName(int tokenType){
#ifndef NDEBUG
  if( tokenType>0 && (size_t)tokenType<(sizeof(kkTokenName)/sizeof(kkTokenName[0])) ){
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
/* #line 697 "parser.y" */
{
	if ((kkpminor->kk0)) {
		if ((kkpminor->kk0)->free_flag) {
			efree((kkpminor->kk0)->token);
		}
		efree((kkpminor->kk0));
	}
}
/* #line 1692 "parser.c" */
      break;
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
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
/* #line 714 "parser.y" */
{ zval_ptr_dtor(&(kkpminor->kk132)); }
/* #line 1728 "parser.c" */
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
  if( i<0 || i>=(int)KK_SZ_ACTTAB || kk_lookahead[i]!=iLookAhead ){
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
  if( i<0 || i>=(int)KK_SZ_ACTTAB || kk_lookahead[i]!=iLookAhead ){
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
  { 78, 1 },
  { 79, 1 },
  { 80, 2 },
  { 80, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 83, 8 },
  { 83, 7 },
  { 83, 12 },
  { 83, 11 },
  { 83, 10 },
  { 84, 4 },
  { 85, 3 },
  { 86, 10 },
  { 86, 12 },
  { 86, 12 },
  { 86, 14 },
  { 87, 4 },
  { 102, 3 },
  { 102, 1 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 98, 10 },
  { 98, 11 },
  { 104, 3 },
  { 104, 1 },
  { 105, 1 },
  { 105, 3 },
  { 106, 1 },
  { 106, 1 },
  { 106, 1 },
  { 106, 1 },
  { 106, 1 },
  { 106, 1 },
  { 100, 11 },
  { 100, 9 },
  { 99, 2 },
  { 88, 3 },
  { 89, 8 },
  { 89, 7 },
  { 90, 8 },
  { 90, 9 },
  { 91, 4 },
  { 92, 4 },
  { 92, 6 },
  { 93, 4 },
  { 94, 4 },
  { 95, 8 },
  { 95, 8 },
  { 96, 3 },
  { 97, 3 },
  { 82, 1 },
  { 101, 2 },
  { 101, 2 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 4 },
  { 101, 3 },
  { 101, 4 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 4 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 3 },
  { 101, 4 },
  { 101, 2 },
  { 101, 2 },
  { 101, 2 },
  { 101, 3 },
  { 101, 2 },
  { 101, 3 },
  { 101, 2 },
  { 101, 3 },
  { 101, 4 },
  { 101, 5 },
  { 101, 5 },
  { 101, 5 },
  { 101, 6 },
  { 109, 1 },
  { 109, 1 },
  { 108, 3 },
  { 108, 1 },
  { 110, 3 },
  { 110, 1 },
  { 101, 1 },
  { 111, 4 },
  { 111, 3 },
  { 107, 3 },
  { 107, 1 },
  { 112, 1 },
  { 112, 3 },
  { 101, 1 },
  { 101, 1 },
  { 101, 1 },
  { 101, 1 },
  { 101, 1 },
  { 101, 1 },
  { 101, 1 },
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
        && kkruleno<(int)(sizeof(kkRuleName)/sizeof(kkRuleName[0])) ){
    fprintf(kkTraceFILE, "%sReduce [%s].\n", kkTracePrompt,
      kkRuleName[kkruleno]);
  }
#endif /* NDEBUG */

  switch( kkruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0:
/* #line 706 "parser.y" */
{
	status->ret = kkmsp[0].minor.kk132;
}
/* #line 2078 "parser.c" */
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
      case 119:
/* #line 710 "parser.y" */
{
	kkgotominor.kk132 = kkmsp[0].minor.kk132;
}
/* #line 2105 "parser.c" */
        break;
      case 2:
/* #line 716 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_zval_list(kkmsp[-1].minor.kk132, kkmsp[0].minor.kk132);
}
/* #line 2112 "parser.c" */
        break;
      case 3:
      case 36:
      case 45:
      case 116:
      case 123:
/* #line 720 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_zval_list(NULL, kkmsp[0].minor.kk132);
}
/* #line 2123 "parser.c" */
        break;
      case 23:
/* #line 804 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_if_statement(kkmsp[-5].minor.kk132, kkmsp[-3].minor.kk132, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(31,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2136 "parser.c" */
        break;
      case 24:
/* #line 808 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_if_statement(kkmsp[-4].minor.kk132, NULL, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(31,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2149 "parser.c" */
        break;
      case 25:
/* #line 812 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_if_statement(kkmsp[-9].minor.kk132, kkmsp[-7].minor.kk132, kkmsp[-3].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(31,&kkmsp[-10].minor);
  kk_destructor(32,&kkmsp[-8].minor);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(34,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2165 "parser.c" */
        break;
      case 26:
/* #line 816 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_if_statement(kkmsp[-8].minor.kk132, kkmsp[-6].minor.kk132, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(31,&kkmsp[-9].minor);
  kk_destructor(32,&kkmsp[-7].minor);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(34,&kkmsp[-4].minor);
  kk_destructor(32,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2181 "parser.c" */
        break;
      case 27:
/* #line 820 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_if_statement(kkmsp[-7].minor.kk132, NULL, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(31,&kkmsp[-8].minor);
  kk_destructor(32,&kkmsp[-6].minor);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(34,&kkmsp[-4].minor);
  kk_destructor(32,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2197 "parser.c" */
        break;
      case 28:
/* #line 826 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_elseif_statement(kkmsp[-1].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(35,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2207 "parser.c" */
        break;
      case 29:
/* #line 832 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_elsefor_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(36,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2217 "parser.c" */
        break;
      case 30:
/* #line 838 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-5].minor.kk132, NULL, kkmsp[-3].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(37,&kkmsp[-8].minor);
  kk_destructor(3,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2231 "parser.c" */
        break;
      case 31:
/* #line 842 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, NULL, kkmsp[-7].minor.kk132, kkmsp[-5].minor.kk132, kkmsp[-3].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(37,&kkmsp[-10].minor);
  kk_destructor(3,&kkmsp[-8].minor);
  kk_destructor(31,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2246 "parser.c" */
        break;
      case 32:
/* #line 846 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, kkmsp[-9].minor.kk0, kkmsp[-5].minor.kk132, NULL, kkmsp[-3].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(37,&kkmsp[-10].minor);
  kk_destructor(2,&kkmsp[-8].minor);
  kk_destructor(3,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2261 "parser.c" */
        break;
      case 33:
/* #line 850 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, kkmsp[-11].minor.kk0, kkmsp[-7].minor.kk132, kkmsp[-5].minor.kk132, kkmsp[-3].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-13].minor);
  kk_destructor(37,&kkmsp[-12].minor);
  kk_destructor(2,&kkmsp[-10].minor);
  kk_destructor(3,&kkmsp[-8].minor);
  kk_destructor(31,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2277 "parser.c" */
        break;
      case 34:
/* #line 856 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_set_statement(kkmsp[-1].minor.kk132);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(40,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2287 "parser.c" */
        break;
      case 35:
      case 44:
      case 115:
      case 122:
/* #line 862 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_zval_list(kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132);
  kk_destructor(2,&kkmsp[-1].minor);
}
/* #line 2298 "parser.c" */
        break;
      case 37:
/* #line 872 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_ASSIGN, kkmsp[0].minor.kk132, status->scanner_state);
  kk_destructor(41,&kkmsp[-1].minor);
}
/* #line 2306 "parser.c" */
        break;
      case 38:
/* #line 876 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_ADD_ASSIGN, kkmsp[0].minor.kk132, status->scanner_state);
  kk_destructor(42,&kkmsp[-1].minor);
}
/* #line 2314 "parser.c" */
        break;
      case 39:
/* #line 880 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_SUB_ASSIGN, kkmsp[0].minor.kk132, status->scanner_state);
  kk_destructor(43,&kkmsp[-1].minor);
}
/* #line 2322 "parser.c" */
        break;
      case 40:
/* #line 884 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_MUL_ASSIGN, kkmsp[0].minor.kk132, status->scanner_state);
  kk_destructor(44,&kkmsp[-1].minor);
}
/* #line 2330 "parser.c" */
        break;
      case 41:
/* #line 888 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_DIV_ASSIGN, kkmsp[0].minor.kk132, status->scanner_state);
  kk_destructor(45,&kkmsp[-1].minor);
}
/* #line 2338 "parser.c" */
        break;
      case 42:
/* #line 894 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_macro_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-3].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(46,&kkmsp[-8].minor);
  kk_destructor(29,&kkmsp[-6].minor);
  kk_destructor(47,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(48,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2353 "parser.c" */
        break;
      case 43:
/* #line 898 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_macro_statement(kkmsp[-8].minor.kk0, kkmsp[-6].minor.kk132, kkmsp[-3].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(46,&kkmsp[-9].minor);
  kk_destructor(29,&kkmsp[-7].minor);
  kk_destructor(47,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(48,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2368 "parser.c" */
        break;
      case 46:
/* #line 914 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_macro_parameter(kkmsp[0].minor.kk0, NULL, status->scanner_state);
}
/* #line 2375 "parser.c" */
        break;
      case 47:
/* #line 918 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_macro_parameter(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk132, status->scanner_state);
  kk_destructor(41,&kkmsp[-1].minor);
}
/* #line 2383 "parser.c" */
        break;
      case 48:
      case 113:
      case 127:
/* #line 922 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, kkmsp[0].minor.kk0, status->scanner_state);
}
/* #line 2392 "parser.c" */
        break;
      case 49:
      case 128:
/* #line 926 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_literal_zval(PHVOLT_T_STRING, kkmsp[0].minor.kk0, status->scanner_state);
}
/* #line 2400 "parser.c" */
        break;
      case 50:
      case 129:
/* #line 930 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, kkmsp[0].minor.kk0, status->scanner_state);
}
/* #line 2408 "parser.c" */
        break;
      case 51:
      case 130:
/* #line 934 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  kk_destructor(52,&kkmsp[0].minor);
}
/* #line 2417 "parser.c" */
        break;
      case 52:
      case 131:
/* #line 938 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  kk_destructor(53,&kkmsp[0].minor);
}
/* #line 2426 "parser.c" */
        break;
      case 53:
      case 132:
/* #line 942 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  kk_destructor(54,&kkmsp[0].minor);
}
/* #line 2435 "parser.c" */
        break;
      case 54:
/* #line 948 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_macro_call_statement(kkmsp[-8].minor.kk132, kkmsp[-6].minor.kk132, kkmsp[-3].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(55,&kkmsp[-9].minor);
  kk_destructor(29,&kkmsp[-7].minor);
  kk_destructor(47,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(56,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2450 "parser.c" */
        break;
      case 55:
/* #line 952 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_macro_call_statement(kkmsp[-6].minor.kk132, NULL, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(55,&kkmsp[-7].minor);
  kk_destructor(29,&kkmsp[-5].minor);
  kk_destructor(47,&kkmsp[-4].minor);
  kk_destructor(32,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(56,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2465 "parser.c" */
        break;
      case 56:
/* #line 958 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_empty_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2474 "parser.c" */
        break;
      case 57:
/* #line 964 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_echo_statement(kkmsp[-1].minor.kk132, status->scanner_state);
  kk_destructor(57,&kkmsp[-2].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
/* #line 2483 "parser.c" */
        break;
      case 58:
/* #line 970 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_block_statement(kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(59,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(60,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2496 "parser.c" */
        break;
      case 59:
/* #line 974 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_block_statement(kkmsp[-4].minor.kk0, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(59,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(60,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2509 "parser.c" */
        break;
      case 60:
/* #line 980 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_cache_statement(kkmsp[-5].minor.kk132, NULL, kkmsp[-3].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(61,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(62,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2522 "parser.c" */
        break;
      case 61:
/* #line 984 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_cache_statement(kkmsp[-6].minor.kk132, kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(61,&kkmsp[-7].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(62,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2535 "parser.c" */
        break;
      case 62:
/* #line 990 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_extends_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(63,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2545 "parser.c" */
        break;
      case 63:
/* #line 996 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_include_statement(kkmsp[-1].minor.kk132, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(64,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2555 "parser.c" */
        break;
      case 64:
/* #line 1000 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_include_statement(kkmsp[-3].minor.kk132, kkmsp[-1].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(64,&kkmsp[-4].minor);
  kk_destructor(65,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2566 "parser.c" */
        break;
      case 65:
/* #line 1006 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_do_statement(kkmsp[-1].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(66,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2576 "parser.c" */
        break;
      case 66:
/* #line 1012 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_return_statement(kkmsp[-1].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(67,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2586 "parser.c" */
        break;
      case 67:
/* #line 1018 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_autoescape_statement(0, kkmsp[-3].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(68,&kkmsp[-6].minor);
  kk_destructor(53,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(69,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2600 "parser.c" */
        break;
      case 68:
/* #line 1022 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_autoescape_statement(1, kkmsp[-3].minor.kk132, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(68,&kkmsp[-6].minor);
  kk_destructor(54,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(69,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2614 "parser.c" */
        break;
      case 69:
/* #line 1028 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_break_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(70,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2624 "parser.c" */
        break;
      case 70:
/* #line 1034 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_continue_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(71,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2634 "parser.c" */
        break;
      case 71:
/* #line 1040 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, kkmsp[0].minor.kk0, status->scanner_state);
}
/* #line 2641 "parser.c" */
        break;
      case 72:
/* #line 1046 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
/* #line 2649 "parser.c" */
        break;
      case 73:
/* #line 1050 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_PLUS, NULL, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
/* #line 2657 "parser.c" */
        break;
      case 74:
/* #line 1054 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_SUB, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
/* #line 2665 "parser.c" */
        break;
      case 75:
/* #line 1058 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_ADD, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
/* #line 2673 "parser.c" */
        break;
      case 76:
/* #line 1062 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_MUL, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(19,&kkmsp[-1].minor);
}
/* #line 2681 "parser.c" */
        break;
      case 77:
/* #line 1066 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_POW, kkmsp[-3].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(19,&kkmsp[-2].minor);
  kk_destructor(19,&kkmsp[-1].minor);
}
/* #line 2690 "parser.c" */
        break;
      case 78:
/* #line 1070 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_DIV, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(18,&kkmsp[-1].minor);
}
/* #line 2698 "parser.c" */
        break;
      case 79:
/* #line 1074 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-3].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(18,&kkmsp[-2].minor);
  kk_destructor(18,&kkmsp[-1].minor);
}
/* #line 2707 "parser.c" */
        break;
      case 80:
/* #line 1078 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
/* #line 2715 "parser.c" */
        break;
      case 81:
/* #line 1082 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_AND, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
}
/* #line 2723 "parser.c" */
        break;
      case 82:
/* #line 1086 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_OR, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(8,&kkmsp[-1].minor);
}
/* #line 2731 "parser.c" */
        break;
      case 83:
/* #line 1090 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_CONCAT, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
}
/* #line 2739 "parser.c" */
        break;
      case 84:
/* #line 1094 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_PIPE, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(25,&kkmsp[-1].minor);
}
/* #line 2747 "parser.c" */
        break;
      case 85:
/* #line 1098 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_RANGE, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-1].minor);
}
/* #line 2755 "parser.c" */
        break;
      case 86:
/* #line 1102 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_EQUALS, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
}
/* #line 2763 "parser.c" */
        break;
      case 87:
/* #line 1106 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, kkmsp[-3].minor.kk132, NULL, NULL, status->scanner_state);
  kk_destructor(9,&kkmsp[-2].minor);
  kk_destructor(26,&kkmsp[-1].minor);
  kk_destructor(73,&kkmsp[0].minor);
}
/* #line 2773 "parser.c" */
        break;
      case 88:
/* #line 1110 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_ISSET, kkmsp[-2].minor.kk132, NULL, NULL, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
  kk_destructor(73,&kkmsp[0].minor);
}
/* #line 2782 "parser.c" */
        break;
      case 89:
/* #line 1114 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_IS, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
}
/* #line 2790 "parser.c" */
        break;
      case 90:
/* #line 1118 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(11,&kkmsp[-1].minor);
}
/* #line 2798 "parser.c" */
        break;
      case 91:
/* #line 1122 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(16,&kkmsp[-1].minor);
}
/* #line 2806 "parser.c" */
        break;
      case 92:
/* #line 1126 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(17,&kkmsp[-1].minor);
}
/* #line 2814 "parser.c" */
        break;
      case 93:
/* #line 1130 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_LESS, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(12,&kkmsp[-1].minor);
}
/* #line 2822 "parser.c" */
        break;
      case 94:
/* #line 1134 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_GREATER, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(13,&kkmsp[-1].minor);
}
/* #line 2830 "parser.c" */
        break;
      case 95:
/* #line 1138 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(14,&kkmsp[-1].minor);
}
/* #line 2838 "parser.c" */
        break;
      case 96:
/* #line 1142 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(15,&kkmsp[-1].minor);
}
/* #line 2846 "parser.c" */
        break;
      case 97:
/* #line 1146 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_DOT, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(30,&kkmsp[-1].minor);
}
/* #line 2854 "parser.c" */
        break;
      case 98:
/* #line 1150 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_IN, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(3,&kkmsp[-1].minor);
}
/* #line 2862 "parser.c" */
        break;
      case 99:
/* #line 1154 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_NOT_IN, kkmsp[-3].minor.kk132, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(3,&kkmsp[-1].minor);
}
/* #line 2871 "parser.c" */
        break;
      case 100:
/* #line 1158 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, kkmsp[0].minor.kk132, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-1].minor);
}
/* #line 2879 "parser.c" */
        break;
      case 101:
/* #line 1162 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_INCR, kkmsp[-1].minor.kk132, NULL, NULL, status->scanner_state);
  kk_destructor(27,&kkmsp[0].minor);
}
/* #line 2887 "parser.c" */
        break;
      case 102:
/* #line 1166 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_DECR, kkmsp[-1].minor.kk132, NULL, NULL, status->scanner_state);
  kk_destructor(28,&kkmsp[0].minor);
}
/* #line 2895 "parser.c" */
        break;
      case 103:
/* #line 1170 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, kkmsp[-1].minor.kk132, NULL, NULL, status->scanner_state);
  kk_destructor(29,&kkmsp[-2].minor);
  kk_destructor(47,&kkmsp[0].minor);
}
/* #line 2904 "parser.c" */
        break;
      case 104:
/* #line 1174 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-1].minor);
  kk_destructor(74,&kkmsp[0].minor);
}
/* #line 2913 "parser.c" */
        break;
      case 105:
/* #line 1178 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk132, NULL, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-2].minor);
  kk_destructor(74,&kkmsp[0].minor);
}
/* #line 2922 "parser.c" */
        break;
      case 106:
/* #line 1182 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  kk_destructor(75,&kkmsp[-1].minor);
  kk_destructor(76,&kkmsp[0].minor);
}
/* #line 2931 "parser.c" */
        break;
      case 107:
/* #line 1186 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk132, NULL, NULL, status->scanner_state);
  kk_destructor(75,&kkmsp[-2].minor);
  kk_destructor(76,&kkmsp[0].minor);
}
/* #line 2940 "parser.c" */
        break;
      case 108:
/* #line 1190 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, kkmsp[-3].minor.kk132, kkmsp[-1].minor.kk132, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-2].minor);
  kk_destructor(74,&kkmsp[0].minor);
}
/* #line 2949 "parser.c" */
        break;
      case 109:
/* #line 1194 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_expr(PHVOLT_T_TERNARY, kkmsp[-2].minor.kk132, kkmsp[0].minor.kk132, kkmsp[-4].minor.kk132, status->scanner_state);
  kk_destructor(4,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-1].minor);
}
/* #line 2958 "parser.c" */
        break;
      case 110:
/* #line 1198 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_slice(kkmsp[-4].minor.kk132, NULL, kkmsp[-1].minor.kk132, status->scanner_state);
  kk_destructor(24,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-2].minor);
  kk_destructor(74,&kkmsp[0].minor);
}
/* #line 2968 "parser.c" */
        break;
      case 111:
/* #line 1202 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_slice(kkmsp[-4].minor.kk132, kkmsp[-2].minor.kk132, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-1].minor);
  kk_destructor(74,&kkmsp[0].minor);
}
/* #line 2978 "parser.c" */
        break;
      case 112:
/* #line 1206 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_slice(kkmsp[-5].minor.kk132, kkmsp[-3].minor.kk132, kkmsp[-1].minor.kk132, status->scanner_state);
  kk_destructor(24,&kkmsp[-4].minor);
  kk_destructor(5,&kkmsp[-2].minor);
  kk_destructor(74,&kkmsp[0].minor);
}
/* #line 2988 "parser.c" */
        break;
      case 114:
      case 126:
/* #line 1216 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, kkmsp[0].minor.kk0, status->scanner_state);
}
/* #line 2996 "parser.c" */
        break;
      case 117:
      case 125:
/* #line 1232 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_named_item(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk132, status->scanner_state);
  kk_destructor(5,&kkmsp[-1].minor);
}
/* #line 3005 "parser.c" */
        break;
      case 118:
      case 124:
/* #line 1236 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_named_item(NULL, kkmsp[0].minor.kk132, status->scanner_state);
}
/* #line 3013 "parser.c" */
        break;
      case 120:
/* #line 1246 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_func_call(kkmsp[-3].minor.kk132, kkmsp[-1].minor.kk132, status->scanner_state);
  kk_destructor(29,&kkmsp[-2].minor);
  kk_destructor(47,&kkmsp[0].minor);
}
/* #line 3022 "parser.c" */
        break;
      case 121:
/* #line 1250 "parser.y" */
{
	kkgotominor.kk132 = phvolt_ret_func_call(kkmsp[-2].minor.kk132, NULL, status->scanner_state);
  kk_destructor(29,&kkmsp[-1].minor);
  kk_destructor(47,&kkmsp[0].minor);
}
/* #line 3031 "parser.c" */
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
/* #line 599 "parser.y" */

	{

		smart_str error_str = {0};

		char *token_name = NULL;
		const phvolt_token_names *tokens = phvolt_tokens;
		int token_len = 0;
		uint active_token = status->scanner_state->active_token;

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

/* #line 3171 "parser.c" */
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
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "View code must be a string");
		return FAILURE;
	}

	if (phvolt_internal_parse_view(&result, view_code, template_path, &error_msg TSRMLS_CC) == FAILURE) {
		if (likely(error_msg != NULL)) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, Z_STRVAL_P(error_msg));
			zval_ptr_dtor(&error_msg);
		}
		else {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "Error parsing the view");
		}

		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Checks whether the token has only blank characters
 */
int phvolt_is_blank_string(phvolt_scanner_token *token){

	char *marker = token->value;
	int i;

	for (i = 0; i < token->len; i++) {
		char ch = *marker;
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
