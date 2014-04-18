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

static zval *phvolt_ret_require_statement(zval *path, zval *params, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	add_assoc_long(ret, "type", PHVOLT_T_REQUIRE);

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


/* #line 586 "parser.c" */
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
#define PHVOLT_REQUIRE                        66
#define PHVOLT_DO                             67
#define PHVOLT_RETURN                         68
#define PHVOLT_AUTOESCAPE                     69
#define PHVOLT_ENDAUTOESCAPE                  70
#define PHVOLT_BREAK                          71
#define PHVOLT_CONTINUE                       72
#define PHVOLT_RAW_FRAGMENT                   73
#define PHVOLT_DEFINED                        74
#define PHVOLT_SBRACKET_CLOSE                 75
#define PHVOLT_CBRACKET_OPEN                  76
#define PHVOLT_CBRACKET_CLOSE                 77
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
#define KKNOCODE 116
#define KKACTIONTYPE unsigned short int
#if INTERFACE
#define phvolt_KTOKENTYPE phvolt_parser_token*
#endif
typedef union {
  phvolt_KTOKENTYPE kk0;
  zval* kk158;
  int kk231;
} KKMINORTYPE;
#define KKSTACKDEPTH 100
#if INTERFACE
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = kkpParser->status
#define phvolt_ARG_STORE kkpParser->status = status
#endif
#define KKNSTATE 329
#define KKNRULE 136
#define KKERRORSYMBOL 78
#define KKERRSYMDT kk231
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
 /*     0 */    83,   93,   24,   61,   53,   55,   65,   63,   67,   73,
 /*    10 */    75,   77,   79,   69,   71,   49,   47,   51,   44,   41,
 /*    20 */    57,   90,   59,   85,   88,   89,   97,   81,  295,  163,
 /*    30 */    83,   93,  129,   61,   53,   55,   65,   63,   67,   73,
 /*    40 */    75,   77,   79,   69,   71,   49,   47,   51,   44,   41,
 /*    50 */    57,   90,   59,   85,   88,   89,   97,   81,  251,  214,
 /*    60 */    49,   47,   51,   44,   41,   57,   90,   59,   85,   88,
 /*    70 */    89,   97,   81,  329,  254,   31,  262,  128,  169,  184,
 /*    80 */    83,   93,  171,   61,   53,   55,   65,   63,   67,   73,
 /*    90 */    75,   77,   79,   69,   71,   49,   47,   51,   44,   41,
 /*   100 */    57,   90,   59,   85,   88,   89,   97,   81,   33,  224,
 /*   110 */    83,   93,  170,   61,   53,   55,   65,   63,   67,   73,
 /*   120 */    75,   77,   79,   69,   71,   49,   47,   51,   44,   41,
 /*   130 */    57,   90,   59,   85,   88,   89,   97,   81,   37,  230,
 /*   140 */    83,   93,  225,   61,   53,   55,   65,   63,   67,   73,
 /*   150 */    75,   77,   79,   69,   71,   49,   47,   51,   44,   41,
 /*   160 */    57,   90,   59,   85,   88,   89,   97,   81,  311,  306,
 /*   170 */    83,   93,  231,   61,   53,   55,   65,   63,   67,   73,
 /*   180 */    75,   77,   79,   69,   71,   49,   47,   51,   44,   41,
 /*   190 */    57,   90,   59,   85,   88,   89,   97,   81,   86,   27,
 /*   200 */    83,   93,  137,   61,   53,   55,   65,   63,   67,   73,
 /*   210 */    75,   77,   79,   69,   71,   49,   47,   51,   44,   41,
 /*   220 */    57,   90,   59,   85,   88,   89,   97,   81,  109,   40,
 /*   230 */    83,   93,  109,   61,   53,   55,   65,   63,   67,   73,
 /*   240 */    75,   77,   79,   69,   71,   49,   47,   51,   44,   41,
 /*   250 */    57,   90,   59,   85,   88,   89,   97,   81,   83,   93,
 /*   260 */    95,   61,   53,   55,   65,   63,   67,   73,   75,   77,
 /*   270 */    79,   69,   71,   49,   47,   51,   44,   41,   57,   90,
 /*   280 */    59,   85,   88,   89,   97,   81,   44,   41,   57,   90,
 /*   290 */    59,   85,   88,   89,   97,   81,  288,  289,  290,  291,
 /*   300 */   292,  293,   92,  113,  129,  108,   83,   93,  283,   61,
 /*   310 */    53,   55,   65,   63,   67,   73,   75,   77,   79,   69,
 /*   320 */    71,   49,   47,   51,   44,   41,   57,   90,   59,   85,
 /*   330 */    88,   89,   97,   81,   90,   59,   85,   88,   89,   97,
 /*   340 */    81,   85,   88,   89,   97,   81,   26,  302,  161,  198,
 /*   350 */   103,  276,  294,  277,   83,   93,  118,   61,   53,   55,
 /*   360 */    65,   63,   67,   73,   75,   77,   79,   69,   71,   49,
 /*   370 */    47,   51,   44,   41,   57,   90,   59,   85,   88,   89,
 /*   380 */    97,   81,  116,  227,   83,   93,  138,   61,   53,   55,
 /*   390 */    65,   63,   67,   73,   75,   77,   79,   69,   71,   49,
 /*   400 */    47,   51,   44,   41,   57,   90,   59,   85,   88,   89,
 /*   410 */    97,   81,  132,  233,   83,   93,  445,   61,   53,   55,
 /*   420 */    65,   63,   67,   73,   75,   77,   79,   69,   71,   49,
 /*   430 */    47,   51,   44,   41,   57,   90,   59,   85,   88,   89,
 /*   440 */    97,   81,  446,  236,   83,   93,  144,   61,   53,   55,
 /*   450 */    65,   63,   67,   73,   75,   77,   79,   69,   71,   49,
 /*   460 */    47,   51,   44,   41,   57,   90,   59,   85,   88,   89,
 /*   470 */    97,   81,  142,  239,   83,   93,  145,   61,   53,   55,
 /*   480 */    65,   63,   67,   73,   75,   77,   79,   69,   71,   49,
 /*   490 */    47,   51,   44,   41,   57,   90,   59,   85,   88,   89,
 /*   500 */    97,   81,   93,  160,   61,   53,   55,   65,   63,   67,
 /*   510 */    73,   75,   77,   79,   69,   71,   49,   47,   51,   44,
 /*   520 */    41,   57,   90,   59,   85,   88,   89,   97,   81,  253,
 /*   530 */   445,  241,  256,   83,   93,  158,   61,   53,   55,   65,
 /*   540 */    63,   67,   73,   75,   77,   79,   69,   71,   49,   47,
 /*   550 */    51,   44,   41,   57,   90,   59,   85,   88,   89,   97,
 /*   560 */    81,  446,  297,   83,   93,  167,   61,   53,   55,   65,
 /*   570 */    63,   67,   73,   75,   77,   79,   69,   71,   49,   47,
 /*   580 */    51,   44,   41,   57,   90,   59,   85,   88,   89,   97,
 /*   590 */    81,  173,  313,   83,   93,  172,   61,   53,   55,   65,
 /*   600 */    63,   67,   73,   75,   77,   79,   69,   71,   49,   47,
 /*   610 */    51,   44,   41,   57,   90,   59,   85,   88,   89,   97,
 /*   620 */    81,   83,   93,  186,   61,   53,   55,   65,   63,   67,
 /*   630 */    73,   75,   77,   79,   69,   71,   49,   47,   51,   44,
 /*   640 */    41,   57,   90,   59,   85,   88,   89,  196,   81,   61,
 /*   650 */    53,   55,   65,   63,   67,   73,   75,   77,   79,   69,
 /*   660 */    71,   49,   47,   51,   44,   41,   57,   90,   59,   85,
 /*   670 */    88,   89,   97,   81,  466,    1,    2,  255,    4,    5,
 /*   680 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   690 */    16,   17,   18,   19,   20,   21,   22,   23,   53,   55,
 /*   700 */    65,   63,   67,   73,   75,   77,   79,   69,   71,   49,
 /*   710 */    47,   51,   44,   41,   57,   90,   59,   85,   88,   89,
 /*   720 */    97,   81,   28,  255,    4,    5,    6,    7,    8,    9,
 /*   730 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   740 */    20,   21,   22,   23,   34,  255,    4,    5,    6,    7,
 /*   750 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   760 */    18,   19,   20,   21,   22,   23,   65,   63,   67,   73,
 /*   770 */    75,   77,   79,   69,   71,   49,   47,   51,   44,   41,
 /*   780 */    57,   90,   59,   85,   88,   89,   97,   81,  164,  255,
 /*   790 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   800 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   810 */   190,  255,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   820 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   830 */    22,   23,  200,  255,    4,    5,    6,    7,    8,    9,
 /*   840 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   850 */    20,   21,   22,   23,  208,  255,    4,    5,    6,    7,
 /*   860 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   870 */    18,   19,   20,   21,   22,   23,  215,  255,    4,    5,
 /*   880 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   890 */    16,   17,   18,   19,   20,   21,   22,   23,  243,  255,
 /*   900 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   910 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   920 */   258,  255,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   930 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   940 */    22,   23,  264,  255,    4,    5,    6,    7,    8,    9,
 /*   950 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   960 */    20,   21,   22,   23,  279,  255,    4,    5,    6,    7,
 /*   970 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   980 */    18,   19,   20,   21,   22,   23,  298,  255,    4,    5,
 /*   990 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*  1000 */    16,   17,   18,   19,   20,   21,   22,   23,  307,  255,
 /*  1010 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*  1020 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*  1030 */   314,  255,    4,    5,    6,    7,    8,    9,   10,   11,
 /*  1040 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*  1050 */    22,   23,    3,    4,    5,    6,    7,    8,    9,   10,
 /*  1060 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*  1070 */    21,   22,   23,   25,  204,   30,   32,   38,  157,  159,
 /*  1080 */   187,  206,  168,  273,  189,   39,   91,  140,  185,  174,
 /*  1090 */   176,  178,  180,  182,  141,  118,  118,  194,  139,  193,
 /*  1100 */   199,  205,  156,  212,  203,  219,  222,  321,  228,  234,
 /*  1110 */   237,  240,  118,  247,  249,  207,  220,  211,   43,  218,
 /*  1120 */    25,  204,  322,  324,   38,  157,  159,   98,  118,  168,
 /*  1130 */   221,  242,  105,  127,   29,  185,  105,  118,  135,  107,
 /*  1140 */   318,  114,  118,  112,  194,  114,  118,  246,  205,  155,
 /*  1150 */   212,  248,  219,  222,   35,  228,  234,  237,  240,  118,
 /*  1160 */   247,  249,  285,  251,   98,  165,  250,   25,  204,   36,
 /*  1170 */   197,   38,  157,  159,  118,  135,  168,  105,   98,  254,
 /*  1180 */   257,  261,  185,   46,  263,  285,  126,  118,  118,  130,
 /*  1190 */   251,  194,  191,  118,  188,  205,  251,  212,  274,  219,
 /*  1200 */   222,  201,  228,  234,  237,  240,  254,  247,  249,  284,
 /*  1210 */   251,  267,  254,  270,   25,  204,  140,  272,   38,  157,
 /*  1220 */   159,  251,  166,  168,   48,   50,  254,  139,  268,  185,
 /*  1230 */    52,   54,  303,   56,  118,  118,  275,  254,  194,  209,
 /*  1240 */   118,  118,  205,  118,  212,  278,  219,  222,  251,  228,
 /*  1250 */   234,  237,  240,  143,  247,  249,  304,  251,   58,  216,
 /*  1260 */   282,   25,  204,  244,  254,   38,  157,  159,  118,   60,
 /*  1270 */   168,   62,   64,  254,  301,  286,  185,   66,  192,  118,
 /*  1280 */    68,  118,  118,  287,  251,  194,  259,  118,  310,  205,
 /*  1290 */   118,  212,  317,  219,  222,  251,  228,  234,  237,  240,
 /*  1300 */   254,  247,  249,  320,  323,  326,   70,  325,   25,  204,
 /*  1310 */   265,  254,   38,  157,  159,  251,  118,  168,   72,  251,
 /*  1320 */    74,  327,  328,  185,   76,  253,  253,   78,  118,   80,
 /*  1330 */   118,  254,  194,  202,  118,  254,  205,  118,  212,  118,
 /*  1340 */   219,  222,  251,  228,  234,  237,  240,  253,  247,  249,
 /*  1350 */   253,  253,   82,   84,  253,   25,  204,  280,  254,   38,
 /*  1360 */   157,  159,  118,  118,  168,  253,  251,   87,   94,  253,
 /*  1370 */   185,   96,  253,  253,  253,  253,  100,  118,  118,  194,
 /*  1380 */   253,  118,  254,  205,  210,  212,  118,  219,  222,  299,
 /*  1390 */   228,  234,  237,  240,  253,  247,  249,  253,  253,  102,
 /*  1400 */   117,  253,   25,  204,  308,  133,   38,  157,  159,  118,
 /*  1410 */   118,  168,  253,  251,  152,  118,  253,  185,  154,  253,
 /*  1420 */   253,  162,  253,  253,  118,  253,  194,  253,  118,  254,
 /*  1430 */   205,  118,  212,  217,  219,  222,  315,  228,  234,  237,
 /*  1440 */   240,  175,  247,  249,  253,  251,  177,  179,  253,   25,
 /*  1450 */   204,  118,  181,   38,  157,  159,  118,  118,  168,  253,
 /*  1460 */   251,  254,  118,  253,  185,  183,  253,  253,  195,  253,
 /*  1470 */   213,  253,  253,  194,  253,  118,  254,  205,  118,  212,
 /*  1480 */   118,  219,  222,  223,  228,  234,  237,  240,  245,  247,
 /*  1490 */   249,  253,  251,  118,  226,  253,   25,  204,  253,  229,
 /*  1500 */    38,  157,  159,  232,  118,  168,  253,  235,  254,  118,
 /*  1510 */   253,  185,  238,  118,  253,  252,  253,  118,  253,  253,
 /*  1520 */   194,  253,  118,  253,  205,  118,  212,  253,  219,  222,
 /*  1530 */   296,  228,  234,  237,  240,  260,  247,  249,  253,  253,
 /*  1540 */   118,  305,  253,   25,  204,  312,  253,   38,  157,  159,
 /*  1550 */   253,  118,  168,  253,  253,  118,  253,  253,  185,  253,
 /*  1560 */   253,  253,  253,  253,  253,  253,  253,  194,  253,  253,
 /*  1570 */   253,  205,  253,  212,  266,  219,  222,  253,  228,  234,
 /*  1580 */   237,  240,  253,  247,  249,  253,  253,  253,  253,  253,
 /*  1590 */    25,  204,  253,  253,   38,  157,  159,  253,  253,  168,
 /*  1600 */   253,  253,  253,  253,  253,  185,  253,  253,  253,  253,
 /*  1610 */   253,  253,  253,  253,  194,  253,  253,  253,  205,  269,
 /*  1620 */   212,  253,  219,  222,  253,  228,  234,  237,  240,  253,
 /*  1630 */   247,  249,  253,  253,  253,  253,  253,   25,  204,  253,
 /*  1640 */   253,   38,  157,  159,  253,  253,  168,  253,  253,  253,
 /*  1650 */   253,  253,  185,  253,  281,  253,  253,  253,  253,  253,
 /*  1660 */   253,  194,  253,  253,  253,  205,  253,  212,  253,  219,
 /*  1670 */   222,  253,  228,  234,  237,  240,  253,  247,  249,  253,
 /*  1680 */   253,  253,  253,  253,   25,  204,  253,  253,   38,  157,
 /*  1690 */   159,  253,  300,  168,  253,  253,  253,  253,  253,  185,
 /*  1700 */   253,  253,  253,  253,  253,  253,  253,  253,  194,  253,
 /*  1710 */   253,  253,  205,  253,  212,  253,  219,  222,  253,  228,
 /*  1720 */   234,  237,  240,  253,  247,  249,  253,  253,  253,  253,
 /*  1730 */   253,   25,  204,  253,  253,   38,  157,  159,  253,  309,
 /*  1740 */   168,  253,  253,  253,  253,  253,  185,  253,  253,  253,
 /*  1750 */   253,  253,  253,  253,  253,  194,  253,  253,  253,  205,
 /*  1760 */   253,  212,  253,  219,  222,  253,  228,  234,  237,  240,
 /*  1770 */   253,  247,  249,  253,  253,  253,  253,  253,   25,  204,
 /*  1780 */   253,  253,   38,  157,  159,  253,  316,  168,  253,  253,
 /*  1790 */   253,  253,  253,  185,  253,  253,  253,  253,  253,  253,
 /*  1800 */   253,  253,  194,  253,  253,  253,  205,  253,  212,  253,
 /*  1810 */   219,  222,  253,  228,  234,  237,  240,  253,  247,  249,
 /*  1820 */   253,  253,  253,  253,  253,   25,  204,  319,  253,   38,
 /*  1830 */   157,  159,  253,  253,  168,  253,  253,  253,  253,  253,
 /*  1840 */   185,  253,  253,  253,  253,  253,  253,  253,  253,  194,
 /*  1850 */   253,  253,  253,  205,  253,  212,  253,  219,  222,  253,
 /*  1860 */   228,  234,  237,  240,  253,  247,  249,  330,   24,  253,
 /*  1870 */   253,  253,   25,  204,  253,  253,   38,  157,  159,  253,
 /*  1880 */   253,  168,  253,  253,  253,  253,  253,  185,  253,  253,
 /*  1890 */   253,  253,  253,  253,  253,  253,  194,  253,  253,  253,
 /*  1900 */   205,  253,  212,  253,  219,  222,  253,  228,  234,  237,
 /*  1910 */   240,  253,  247,  249,  253,  253,  153,  253,   45,   42,
 /*  1920 */   253,  104,  253,   99,  251,  253,  101,  253,  253,  253,
 /*  1930 */   253,  253,  253,  253,  253,  119,  253,  253,  253,  253,
 /*  1940 */   254,  253,  253,  253,  253,  253,  120,  121,  122,  123,
 /*  1950 */   124,  125,  253,  253,  151,  253,  253,   45,   42,  253,
 /*  1960 */   104,  253,   99,  253,  253,  101,  253,  253,  253,  253,
 /*  1970 */   253,  253,  253,  110,  119,  253,   45,   42,  253,  104,
 /*  1980 */   253,  148,  253,  253,  101,  120,  121,  122,  123,  124,
 /*  1990 */   125,  253,  253,  119,  136,  253,  253,  253,  253,  253,
 /*  2000 */   253,  253,  253,  253,  120,  121,  122,  123,  124,  125,
 /*  2010 */    45,   42,  110,  104,  253,   99,  253,  253,  101,  253,
 /*  2020 */   253,  253,  253,  253,  253,  253,  253,  147,  253,  150,
 /*  2030 */   253,  110,  253,  253,  253,  253,  253,  253,  146,  121,
 /*  2040 */   122,  123,  124,  125,  253,  253,  253,  253,  253,   45,
 /*  2050 */    42,  253,  104,  253,   99,  253,  253,  101,  253,  253,
 /*  2060 */   253,  253,  253,  253,  253,  110,  119,  253,  253,  253,
 /*  2070 */   253,  253,  253,  253,  253,  134,  253,  120,  131,  122,
 /*  2080 */   123,  124,  125,  253,  253,  253,  253,  253,   45,   42,
 /*  2090 */   253,  104,  253,   99,  253,  253,  101,  253,  253,  253,
 /*  2100 */   253,  253,  253,  253,  110,  119,  253,  253,  253,  253,
 /*  2110 */   253,  253,  253,  253,  253,  253,  120,  115,  122,  123,
 /*  2120 */   124,  125,  253,  253,  253,  253,  253,   45,   42,  253,
 /*  2130 */   104,  253,   99,  253,  253,  101,  253,  253,  253,  253,
 /*  2140 */   253,  253,  106,  110,  119,  253,  253,  253,  253,  253,
 /*  2150 */   253,  253,  253,  253,  253,  120,  115,  122,  123,  124,
 /*  2160 */   125,  253,  253,  253,   45,   42,  253,  104,  253,   99,
 /*  2170 */   253,  253,  101,  253,  253,  253,  253,  253,  253,  253,
 /*  2180 */   253,  119,  110,  111,  253,  253,  253,  253,  253,  253,
 /*  2190 */   253,  253,  120,  121,  122,  123,  124,  125,  253,  253,
 /*  2200 */   253,  253,  253,   45,   42,  253,  104,  253,   99,  253,
 /*  2210 */   253,  101,  253,  253,  253,  253,  253,  149,  253,  110,
 /*  2220 */   119,  253,  253,  253,  253,  253,  253,  253,  253,  271,
 /*  2230 */   253,  120,  131,  122,  123,  124,  125,  253,  253,   45,
 /*  2240 */    42,  253,  104,  253,   99,  253,  253,  101,  253,  253,
 /*  2250 */   253,  253,  253,  253,  253,  253,  119,  253,  110,  253,
 /*  2260 */   253,  253,  253,  253,  253,  253,  253,  120,  121,  122,
 /*  2270 */   123,  124,  125,  253,  253,  253,  253,  253,   45,   42,
 /*  2280 */   253,  104,  253,   99,  253,  253,  101,  253,  253,  253,
 /*  2290 */   253,  253,  253,  253,  110,  119,  253,  253,  253,  253,
 /*  2300 */   253,  253,  253,  253,  253,  253,  120,  115,  122,  123,
 /*  2310 */   124,  125,  253,  253,  253,  253,  253,   45,   42,  253,
 /*  2320 */   104,  253,   99,  253,  253,  101,  253,  253,  253,  253,
 /*  2330 */   253,  253,  253,  110,  119,  253,  253,  253,  253,  253,
 /*  2340 */   253,  253,  253,  253,  253,  120,  131,  122,  123,  124,
 /*  2350 */   125,  253,  253,  253,  253,  253,  253,  253,  253,  253,
 /*  2360 */   253,  253,  253,  253,  253,  253,  253,  253,  253,  253,
 /*  2370 */   253,  253,  110,
};
static KKCODETYPE kk_lookahead[] = {
 /*     0 */     3,    4,    1,    6,    7,    8,    9,   10,   11,   12,
 /*    10 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    20 */    23,   24,   25,   26,   27,   28,   29,   30,   31,   32,
 /*    30 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*    40 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    50 */    23,   24,   25,   26,   27,   28,   29,   30,   57,   32,
 /*    60 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*    70 */    28,   29,   30,    0,   73,   32,   49,   47,  104,  105,
 /*    80 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*    90 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   100 */    23,   24,   25,   26,   27,   28,   29,   30,   32,   32,
 /*   110 */     3,    4,   32,    6,    7,    8,    9,   10,   11,   12,
 /*   120 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   130 */    23,   24,   25,   26,   27,   28,   29,   30,   32,   32,
 /*   140 */     3,    4,   65,    6,    7,    8,    9,   10,   11,   12,
 /*   150 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   160 */    23,   24,   25,   26,   27,   28,   29,   30,   31,   32,
 /*   170 */     3,    4,   65,    6,    7,    8,    9,   10,   11,   12,
 /*   180 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   190 */    23,   24,   25,   26,   27,   28,   29,   30,    3,   32,
 /*   200 */     3,    4,  111,    6,    7,    8,    9,   10,   11,   12,
 /*   210 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   220 */    23,   24,   25,   26,   27,   28,   29,   30,    2,   32,
 /*   230 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*   240 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   250 */    23,   24,   25,   26,   27,   28,   29,   30,    3,    4,
 /*   260 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   270 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   280 */    25,   26,   27,   28,   29,   30,   21,   22,   23,   24,
 /*   290 */    25,   26,   27,   28,   29,   30,   49,   50,   51,   52,
 /*   300 */    53,   54,   75,   77,    2,   75,    3,    4,    2,    6,
 /*   310 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   320 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   330 */    27,   28,   29,   30,   24,   25,   26,   27,   28,   29,
 /*   340 */    30,   26,   27,   28,   29,   30,  103,    2,    3,   47,
 /*   350 */    47,  106,  107,   47,    3,    4,  113,    6,    7,    8,
 /*   360 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   370 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   380 */    29,   30,    5,   32,    3,    4,   75,    6,    7,    8,
 /*   390 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   400 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   410 */    29,   30,    5,   32,    3,    4,   75,    6,    7,    8,
 /*   420 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   430 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   440 */    29,   30,   75,   32,    3,    4,  111,    6,    7,    8,
 /*   450 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   460 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   470 */    29,   30,    5,   32,    3,    4,   75,    6,    7,    8,
 /*   480 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   490 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   500 */    29,   30,    4,   38,    6,    7,    8,    9,   10,   11,
 /*   510 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   520 */    22,   23,   24,   25,   26,   27,   28,   29,   30,   58,
 /*   530 */     5,   53,   54,    3,    4,   32,    6,    7,    8,    9,
 /*   540 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   550 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   560 */    30,    5,   32,    3,    4,   32,    6,    7,    8,    9,
 /*   570 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   580 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   590 */    30,   38,   32,    3,    4,  105,    6,    7,    8,    9,
 /*   600 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   610 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   620 */    30,    3,    4,   38,    6,    7,    8,    9,   10,   11,
 /*   630 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   640 */    22,   23,   24,   25,   26,   27,   28,   29,   30,    6,
 /*   650 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   660 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   670 */    27,   28,   29,   30,   79,   80,   81,   82,   83,   84,
 /*   680 */    85,   86,   87,   88,   89,   90,   91,   92,   93,   94,
 /*   690 */    95,   96,   97,   98,   99,  100,  101,  102,    7,    8,
 /*   700 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   710 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   720 */    29,   30,   81,   82,   83,   84,   85,   86,   87,   88,
 /*   730 */    89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
 /*   740 */    99,  100,  101,  102,   81,   82,   83,   84,   85,   86,
 /*   750 */    87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
 /*   760 */    97,   98,   99,  100,  101,  102,    9,   10,   11,   12,
 /*   770 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   780 */    23,   24,   25,   26,   27,   28,   29,   30,   81,   82,
 /*   790 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   800 */    93,   94,   95,   96,   97,   98,   99,  100,  101,  102,
 /*   810 */    81,   82,   83,   84,   85,   86,   87,   88,   89,   90,
 /*   820 */    91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
 /*   830 */   101,  102,   81,   82,   83,   84,   85,   86,   87,   88,
 /*   840 */    89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
 /*   850 */    99,  100,  101,  102,   81,   82,   83,   84,   85,   86,
 /*   860 */    87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
 /*   870 */    97,   98,   99,  100,  101,  102,   81,   82,   83,   84,
 /*   880 */    85,   86,   87,   88,   89,   90,   91,   92,   93,   94,
 /*   890 */    95,   96,   97,   98,   99,  100,  101,  102,   81,   82,
 /*   900 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*   910 */    93,   94,   95,   96,   97,   98,   99,  100,  101,  102,
 /*   920 */    81,   82,   83,   84,   85,   86,   87,   88,   89,   90,
 /*   930 */    91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
 /*   940 */   101,  102,   81,   82,   83,   84,   85,   86,   87,   88,
 /*   950 */    89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
 /*   960 */    99,  100,  101,  102,   81,   82,   83,   84,   85,   86,
 /*   970 */    87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
 /*   980 */    97,   98,   99,  100,  101,  102,   81,   82,   83,   84,
 /*   990 */    85,   86,   87,   88,   89,   90,   91,   92,   93,   94,
 /*  1000 */    95,   96,   97,   98,   99,  100,  101,  102,   81,   82,
 /*  1010 */    83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
 /*  1020 */    93,   94,   95,   96,   97,   98,   99,  100,  101,  102,
 /*  1030 */    81,   82,   83,   84,   85,   86,   87,   88,   89,   90,
 /*  1040 */    91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
 /*  1050 */   101,  102,   82,   83,   84,   85,   86,   87,   88,   89,
 /*  1060 */    90,   91,   92,   93,   94,   95,   96,   97,   98,   99,
 /*  1070 */   100,  101,  102,   31,   32,   33,   34,   35,   36,   37,
 /*  1080 */    29,   38,   40,    1,   32,  103,  103,   38,   46,   41,
 /*  1090 */    42,   43,   44,   45,  111,  113,  113,   55,   49,   32,
 /*  1100 */    32,   59,  103,   61,   32,   63,   64,    1,   66,   67,
 /*  1110 */    68,   69,  113,   71,   72,   32,   50,   32,  103,   32,
 /*  1120 */    31,   32,   33,   34,   35,   36,   37,  103,  113,   40,
 /*  1130 */    32,   32,  103,  109,    1,   46,  103,  113,  114,  110,
 /*  1140 */     1,  112,  113,  110,   55,  112,  113,   32,   59,  103,
 /*  1150 */    61,   32,   63,   64,    1,   66,   67,   68,   69,  113,
 /*  1160 */    71,   72,   38,   57,  103,    1,   32,   31,   32,   33,
 /*  1170 */   109,   35,   36,   37,  113,  114,   40,  103,  103,   73,
 /*  1180 */    32,   32,   46,  103,   32,   38,  112,  113,  113,  114,
 /*  1190 */    57,   55,    1,  113,   47,   59,   57,   61,   56,   63,
 /*  1200 */    64,    1,   66,   67,   68,   69,   73,   71,   72,  107,
 /*  1210 */    57,   32,   73,   32,   31,   32,   38,   32,   35,   36,
 /*  1220 */    37,   57,   39,   40,  103,  103,   73,   49,    1,   46,
 /*  1230 */   103,  103,   38,  103,  113,  113,   32,   73,   55,    1,
 /*  1240 */   113,  113,   59,  113,   61,   32,   63,   64,   57,   66,
 /*  1250 */    67,   68,   69,   75,   71,   72,    3,   57,  103,    1,
 /*  1260 */    32,   31,   32,    1,   73,   35,   36,   37,  113,  103,
 /*  1270 */    40,  103,  103,   73,   32,   41,   46,  103,   48,  113,
 /*  1280 */   103,  113,  113,  108,   57,   55,    1,  113,   32,   59,
 /*  1290 */   113,   61,   32,   63,   64,   57,   66,   67,   68,   69,
 /*  1300 */    73,   71,   72,   32,   32,    1,  103,   32,   31,   32,
 /*  1310 */     1,   73,   35,   36,   37,   57,  113,   40,  103,   57,
 /*  1320 */   103,   33,   32,   46,  103,  115,  115,  103,  113,  103,
 /*  1330 */   113,   73,   55,   56,  113,   73,   59,  113,   61,  113,
 /*  1340 */    63,   64,   57,   66,   67,   68,   69,  115,   71,   72,
 /*  1350 */   115,  115,  103,  103,  115,   31,   32,    1,   73,   35,
 /*  1360 */    36,   37,  113,  113,   40,  115,   57,  103,  103,  115,
 /*  1370 */    46,  103,  115,  115,  115,  115,  103,  113,  113,   55,
 /*  1380 */   115,  113,   73,   59,   60,   61,  113,   63,   64,    1,
 /*  1390 */    66,   67,   68,   69,  115,   71,   72,  115,  115,  103,
 /*  1400 */   103,  115,   31,   32,    1,  103,   35,   36,   37,  113,
 /*  1410 */   113,   40,  115,   57,  103,  113,  115,   46,  103,  115,
 /*  1420 */   115,  103,  115,  115,  113,  115,   55,  115,  113,   73,
 /*  1430 */    59,  113,   61,   62,   63,   64,    1,   66,   67,   68,
 /*  1440 */    69,  103,   71,   72,  115,   57,  103,  103,  115,   31,
 /*  1450 */    32,  113,  103,   35,   36,   37,  113,  113,   40,  115,
 /*  1460 */    57,   73,  113,  115,   46,  103,  115,  115,  103,  115,
 /*  1470 */   103,  115,  115,   55,  115,  113,   73,   59,  113,   61,
 /*  1480 */   113,   63,   64,  103,   66,   67,   68,   69,   70,   71,
 /*  1490 */    72,  115,   57,  113,  103,  115,   31,   32,  115,  103,
 /*  1500 */    35,   36,   37,  103,  113,   40,  115,  103,   73,  113,
 /*  1510 */   115,   46,  103,  113,  115,  103,  115,  113,  115,  115,
 /*  1520 */    55,  115,  113,  115,   59,  113,   61,  115,   63,   64,
 /*  1530 */   103,   66,   67,   68,   69,   70,   71,   72,  115,  115,
 /*  1540 */   113,  103,  115,   31,   32,  103,  115,   35,   36,   37,
 /*  1550 */   115,  113,   40,  115,  115,  113,  115,  115,   46,  115,
 /*  1560 */   115,  115,  115,  115,  115,  115,  115,   55,  115,  115,
 /*  1570 */   115,   59,  115,   61,   62,   63,   64,  115,   66,   67,
 /*  1580 */    68,   69,  115,   71,   72,  115,  115,  115,  115,  115,
 /*  1590 */    31,   32,  115,  115,   35,   36,   37,  115,  115,   40,
 /*  1600 */   115,  115,  115,  115,  115,   46,  115,  115,  115,  115,
 /*  1610 */   115,  115,  115,  115,   55,  115,  115,  115,   59,   60,
 /*  1620 */    61,  115,   63,   64,  115,   66,   67,   68,   69,  115,
 /*  1630 */    71,   72,  115,  115,  115,  115,  115,   31,   32,  115,
 /*  1640 */   115,   35,   36,   37,  115,  115,   40,  115,  115,  115,
 /*  1650 */   115,  115,   46,  115,   48,  115,  115,  115,  115,  115,
 /*  1660 */   115,   55,  115,  115,  115,   59,  115,   61,  115,   63,
 /*  1670 */    64,  115,   66,   67,   68,   69,  115,   71,   72,  115,
 /*  1680 */   115,  115,  115,  115,   31,   32,  115,  115,   35,   36,
 /*  1690 */    37,  115,   39,   40,  115,  115,  115,  115,  115,   46,
 /*  1700 */   115,  115,  115,  115,  115,  115,  115,  115,   55,  115,
 /*  1710 */   115,  115,   59,  115,   61,  115,   63,   64,  115,   66,
 /*  1720 */    67,   68,   69,  115,   71,   72,  115,  115,  115,  115,
 /*  1730 */   115,   31,   32,  115,  115,   35,   36,   37,  115,   39,
 /*  1740 */    40,  115,  115,  115,  115,  115,   46,  115,  115,  115,
 /*  1750 */   115,  115,  115,  115,  115,   55,  115,  115,  115,   59,
 /*  1760 */   115,   61,  115,   63,   64,  115,   66,   67,   68,   69,
 /*  1770 */   115,   71,   72,  115,  115,  115,  115,  115,   31,   32,
 /*  1780 */   115,  115,   35,   36,   37,  115,   39,   40,  115,  115,
 /*  1790 */   115,  115,  115,   46,  115,  115,  115,  115,  115,  115,
 /*  1800 */   115,  115,   55,  115,  115,  115,   59,  115,   61,  115,
 /*  1810 */    63,   64,  115,   66,   67,   68,   69,  115,   71,   72,
 /*  1820 */   115,  115,  115,  115,  115,   31,   32,   33,  115,   35,
 /*  1830 */    36,   37,  115,  115,   40,  115,  115,  115,  115,  115,
 /*  1840 */    46,  115,  115,  115,  115,  115,  115,  115,  115,   55,
 /*  1850 */   115,  115,  115,   59,  115,   61,  115,   63,   64,  115,
 /*  1860 */    66,   67,   68,   69,  115,   71,   72,    0,    1,  115,
 /*  1870 */   115,  115,   31,   32,  115,  115,   35,   36,   37,  115,
 /*  1880 */   115,   40,  115,  115,  115,  115,  115,   46,  115,  115,
 /*  1890 */   115,  115,  115,  115,  115,  115,   55,  115,  115,  115,
 /*  1900 */    59,  115,   61,  115,   63,   64,  115,   66,   67,   68,
 /*  1910 */    69,  115,   71,   72,  115,  115,   19,  115,   21,   22,
 /*  1920 */   115,   24,  115,   26,   57,  115,   29,  115,  115,  115,
 /*  1930 */   115,  115,  115,  115,  115,   38,  115,  115,  115,  115,
 /*  1940 */    73,  115,  115,  115,  115,  115,   49,   50,   51,   52,
 /*  1950 */    53,   54,  115,  115,   18,  115,  115,   21,   22,  115,
 /*  1960 */    24,  115,   26,  115,  115,   29,  115,  115,  115,  115,
 /*  1970 */   115,  115,  115,   76,   38,  115,   21,   22,  115,   24,
 /*  1980 */   115,   26,  115,  115,   29,   49,   50,   51,   52,   53,
 /*  1990 */    54,  115,  115,   38,    5,  115,  115,  115,  115,  115,
 /*  2000 */   115,  115,  115,  115,   49,   50,   51,   52,   53,   54,
 /*  2010 */    21,   22,   76,   24,  115,   26,  115,  115,   29,  115,
 /*  2020 */   115,  115,  115,  115,  115,  115,  115,   38,  115,   74,
 /*  2030 */   115,   76,  115,  115,  115,  115,  115,  115,   49,   50,
 /*  2040 */    51,   52,   53,   54,  115,  115,  115,  115,  115,   21,
 /*  2050 */    22,  115,   24,  115,   26,  115,  115,   29,  115,  115,
 /*  2060 */   115,  115,  115,  115,  115,   76,   38,  115,  115,  115,
 /*  2070 */   115,  115,  115,  115,  115,   47,  115,   49,   50,   51,
 /*  2080 */    52,   53,   54,  115,  115,  115,  115,  115,   21,   22,
 /*  2090 */   115,   24,  115,   26,  115,  115,   29,  115,  115,  115,
 /*  2100 */   115,  115,  115,  115,   76,   38,  115,  115,  115,  115,
 /*  2110 */   115,  115,  115,  115,  115,  115,   49,   50,   51,   52,
 /*  2120 */    53,   54,  115,  115,  115,  115,  115,   21,   22,  115,
 /*  2130 */    24,  115,   26,  115,  115,   29,  115,  115,  115,  115,
 /*  2140 */   115,  115,   75,   76,   38,  115,  115,  115,  115,  115,
 /*  2150 */   115,  115,  115,  115,  115,   49,   50,   51,   52,   53,
 /*  2160 */    54,  115,  115,  115,   21,   22,  115,   24,  115,   26,
 /*  2170 */   115,  115,   29,  115,  115,  115,  115,  115,  115,  115,
 /*  2180 */   115,   38,   76,   77,  115,  115,  115,  115,  115,  115,
 /*  2190 */   115,  115,   49,   50,   51,   52,   53,   54,  115,  115,
 /*  2200 */   115,  115,  115,   21,   22,  115,   24,  115,   26,  115,
 /*  2210 */   115,   29,  115,  115,  115,  115,  115,   74,  115,   76,
 /*  2220 */    38,  115,  115,  115,  115,  115,  115,  115,  115,   47,
 /*  2230 */   115,   49,   50,   51,   52,   53,   54,  115,  115,   21,
 /*  2240 */    22,  115,   24,  115,   26,  115,  115,   29,  115,  115,
 /*  2250 */   115,  115,  115,  115,  115,  115,   38,  115,   76,  115,
 /*  2260 */   115,  115,  115,  115,  115,  115,  115,   49,   50,   51,
 /*  2270 */    52,   53,   54,  115,  115,  115,  115,  115,   21,   22,
 /*  2280 */   115,   24,  115,   26,  115,  115,   29,  115,  115,  115,
 /*  2290 */   115,  115,  115,  115,   76,   38,  115,  115,  115,  115,
 /*  2300 */   115,  115,  115,  115,  115,  115,   49,   50,   51,   52,
 /*  2310 */    53,   54,  115,  115,  115,  115,  115,   21,   22,  115,
 /*  2320 */    24,  115,   26,  115,  115,   29,  115,  115,  115,  115,
 /*  2330 */   115,  115,  115,   76,   38,  115,  115,  115,  115,  115,
 /*  2340 */   115,  115,  115,  115,  115,   49,   50,   51,   52,   53,
 /*  2350 */    54,  115,  115,  115,  115,  115,  115,  115,  115,  115,
 /*  2360 */   115,  115,  115,  115,  115,  115,  115,  115,  115,  115,
 /*  2370 */   115,  115,   76,
};
#define KK_SHIFT_USE_DFLT (-4)
static short kk_shift_ofst[] = {
 /*     0 */     1,   73, 1867,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    20 */    -4,   -4,   -4,   -4, 1841, 2218,  167, 1106, 1133, 1042,
 /*    30 */    43,   -4,   76, 1139, 1153, 1136,  106,   -4, 2218,  197,
 /*    40 */    -4, 2218, 2218,  310, 2218, 2218,  310, 1897,  265, 1936,
 /*    50 */   265, 2218,  265, 2218,  757, 2218,  757, 2218,  310, 2218,
 /*    60 */   315, 2218,  691, 2218,   42, 1955,   42, 2218,   42, 2218,
 /*    70 */    42, 2218,   42, 2218,   42, 2218,   42, 2218,   42, 2218,
 /*    80 */    42, 2218,   -4, 2218,  498,  195, 2218,  315,   -4,   -4,
 /*    90 */  1989,  227,   -4, 2218,  255, 2218,  643, 2028,  590, 2218,
 /*   100 */   315, 2218,  303,   -4, 2067,  590,   -4,  230,   -4, 2257,
 /*   110 */  2106,   -4,  226,   -4,   -4,  377, 2218,  590,   -4,   -4,
 /*   120 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   30,   -4, 2296,
 /*   130 */    -4,  407, 2218,  590,   -4,   -4, 1049,  311,   -4,  341,
 /*   140 */   367,  467, 1178,   -4,  401,   -4,  525,  556, 2143,   -4,
 /*   150 */    -4, 2218,  265, 2218,  265,  310,  310,  503,   -4,  465,
 /*   160 */   345, 2218,   -3,    1, 1164, 1183,  533,   -4,  553,   80,
 /*   170 */    -4,  553,   -4, 1048, 2218,  590, 2218,  590, 2218,  590,
 /*   180 */  2218,  590, 2218,  590,   -4,  585, 1051, 1147, 1052,    1,
 /*   190 */  1191, 1230, 1067,   -4, 2218,  618, 2182,  302, 1068,    1,
 /*   200 */  1200, 1277, 1072,   -4,   -4, 1043, 1083, 1227, 1238, 1324,
 /*   210 */  1085,   -4, 2218,   27,    1, 1258, 1371, 1087,   -4, 1066,
 /*   220 */  1098,   -4, 2218,   77,   -4, 2218,  351,   -4, 2218,  107,
 /*   230 */    -4, 2218,  381,   -4, 2218,  411,   -4, 2218,  441,   -4,
 /*   240 */   478, 1099,    1, 1262, 1418, 1115,   -4, 1119,   -4, 1134,
 /*   250 */    -4, 2218,  471,   -4,   -4,   -4, 1148,    1, 1285, 1465,
 /*   260 */  1149,   -4, 1152,    1, 1309, 1512, 1179,   -4, 1559, 1181,
 /*   270 */    -4, 1185, 1082, 1142, 1204,   -4,  306, 1213,    1, 1356,
 /*   280 */  1606, 1228,   -4, 1124,   -4, 1234,  247,   -4,   -4,   -4,
 /*   290 */    -4,   -4,   -4,   -4,   -4, 2218,  530,    1, 1388, 1653,
 /*   300 */  1242,   -4, 1194, 1253, 2218,  137,    1, 1403, 1700, 1256,
 /*   310 */    -4, 2218,  560,    1, 1435, 1747, 1260,   -4, 1794, 1271,
 /*   320 */    -4, 1089, 1272,   -4, 1275, 1304, 1288, 1290,   -4,
};
#define KK_REDUCE_USE_DFLT (-27)
static short kk_reduce_ofst[] = {
 /*     0 */   595,  -27,  970,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
 /*    10 */   -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
 /*    20 */   -27,  -27,  -27,  -27,  -27,  243,  -27,  641,  970,  -27,
 /*    30 */   -27,  -27,  -27,  663,  970,  -27,  -27,  -27,  982,  -27,
 /*    40 */   -27,  999, 1015,  -27, 1046, 1080,  -27, 1121,  -27, 1122,
 /*    50 */   -27, 1127,  -27, 1128,  -27, 1130,  -27, 1155,  -27, 1166,
 /*    60 */   -27, 1168,  -27, 1169,  -27, 1174,  -27, 1177,  -27, 1203,
 /*    70 */   -27, 1215,  -27, 1217,  -27, 1221,  -27, 1224,  -27, 1226,
 /*    80 */   -27, 1249,  -27, 1250,  -27,  -27, 1264,  -27,  -27,  -27,
 /*    90 */   983,  -27,  -27, 1265,  -27, 1268,  -27, 1024,  -27, 1273,
 /*   100 */   -27, 1296,  -27,  -27, 1029,  -27,  -27,  -27,  -27, 1074,
 /*   110 */  1033,  -27,  -27,  -27,  -27,  -27, 1297,  -27,  -27,  -27,
 /*   120 */   -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27, 1075,
 /*   130 */   -27,  -27, 1302,  -27,  -27,  -27,   91,  -27,  -27,  -27,
 /*   140 */   -27,  -27,  335,  -27,  -27,  -27,  -27,  -27, 1273,  -27,
 /*   150 */   -27, 1311,  -27, 1315,  -27,  -27,  -27,  -27,  -27,  -27,
 /*   160 */   -27, 1318,  -27,  707,  970,  -27,  -27,  -27,  -26,  -27,
 /*   170 */   -27,  490,  -27,  -27, 1338,  -27, 1343,  -27, 1344,  -27,
 /*   180 */  1349,  -27, 1362,  -27,  -27,  -27,  -27,  245,  -27,  729,
 /*   190 */   970,  -27,  -27,  -27, 1365,  -27, 1061,  -27,  -27,  751,
 /*   200 */   970,  -27,  -27,  -27,  -27,  -27,  -27,  773,  970,  -27,
 /*   210 */   -27,  -27, 1367,  -27,  795,  970,  -27,  -27,  -27,  -27,
 /*   220 */   -27,  -27, 1380,  -27,  -27, 1391,  -27,  -27, 1396,  -27,
 /*   230 */   -27, 1400,  -27,  -27, 1404,  -27,  -27, 1409,  -27,  -27,
 /*   240 */   -27,  -27,  817,  970,  -27,  -27,  -27,  -27,  -27,  -27,
 /*   250 */   -27, 1412,  -27,  -27,  -27,  -27,  -27,  839,  970,  -27,
 /*   260 */   -27,  -27,  -27,  861,  970,  -27,  -27,  -27,  -27,  -27,
 /*   270 */   -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  883,  970,
 /*   280 */   -27,  -27,  -27, 1102,  -27,  -27, 1175,  -27,  -27,  -27,
 /*   290 */   -27,  -27,  -27,  -27,  -27, 1427,  -27,  905,  970,  -27,
 /*   300 */   -27,  -27,  -27,  -27, 1438,  -27,  927,  970,  -27,  -27,
 /*   310 */   -27, 1442,  -27,  949,  970,  -27,  -27,  -27,  -27,  -27,
 /*   320 */   -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
};
static KKACTIONTYPE kk_default[] = {
 /*     0 */   465,  465,  465,  331,  333,  334,  335,  336,  337,  338,
 /*    10 */   339,  340,  341,  342,  343,  344,  345,  346,  347,  348,
 /*    20 */   349,  350,  351,  352,  465,  465,  465,  465,  465,  465,
 /*    30 */   465,  353,  465,  465,  465,  465,  465,  355,  465,  465,
 /*    40 */   358,  465,  465,  404,  465,  465,  405,  465,  408,  465,
 /*    50 */   410,  465,  412,  465,  413,  465,  414,  465,  415,  465,
 /*    60 */   416,  465,  417,  465,  418,  465,  421,  465,  422,  465,
 /*    70 */   423,  465,  424,  465,  425,  465,  426,  465,  427,  465,
 /*    80 */   428,  465,  429,  465,  430,  465,  465,  431,  433,  434,
 /*    90 */   465,  465,  440,  465,  465,  465,  441,  465,  456,  465,
 /*   100 */   432,  465,  465,  435,  465,  450,  436,  465,  437,  465,
 /*   110 */   465,  438,  465,  439,  448,  460,  465,  449,  451,  458,
 /*   120 */   459,  460,  461,  462,  463,  464,  447,  465,  452,  465,
 /*   130 */   454,  460,  465,  457,  453,  455,  465,  465,  442,  465,
 /*   140 */   465,  465,  465,  443,  465,  444,  459,  458,  465,  419,
 /*   150 */   420,  465,  411,  465,  409,  407,  406,  465,  359,  465,
 /*   160 */   465,  465,  465,  465,  465,  465,  465,  360,  465,  465,
 /*   170 */   364,  465,  365,  465,  465,  367,  465,  368,  465,  369,
 /*   180 */   465,  370,  465,  371,  366,  465,  465,  465,  465,  465,
 /*   190 */   465,  465,  465,  372,  465,  465,  465,  465,  452,  465,
 /*   200 */   465,  465,  465,  384,  386,  465,  465,  465,  465,  465,
 /*   210 */   465,  388,  465,  465,  465,  465,  465,  465,  390,  465,
 /*   220 */   465,  392,  465,  465,  393,  465,  465,  394,  465,  465,
 /*   230 */   395,  465,  465,  396,  465,  465,  397,  465,  465,  398,
 /*   240 */   465,  465,  465,  465,  465,  465,  399,  465,  401,  465,
 /*   250 */   402,  465,  465,  387,  403,  332,  465,  465,  465,  465,
 /*   260 */   465,  400,  465,  465,  465,  465,  465,  391,  465,  465,
 /*   270 */   389,  453,  465,  465,  465,  385,  465,  465,  465,  465,
 /*   280 */   465,  465,  373,  465,  374,  376,  465,  377,  378,  379,
 /*   290 */   380,  381,  382,  383,  375,  465,  465,  465,  465,  465,
 /*   300 */   465,  361,  465,  465,  465,  465,  465,  465,  465,  465,
 /*   310 */   362,  465,  465,  465,  465,  465,  465,  363,  465,  465,
 /*   320 */   356,  465,  465,  354,  465,  465,  465,  465,  357,
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
  "INCLUDE",       "WITH",          "REQUIRE",       "DO",          
  "RETURN",        "AUTOESCAPE",    "ENDAUTOESCAPE",  "BREAK",       
  "CONTINUE",      "RAW_FRAGMENT",  "DEFINED",       "SBRACKET_CLOSE",
  "CBRACKET_OPEN",  "CBRACKET_CLOSE",  "error",         "program",     
  "volt_language",  "statement_list",  "statement",     "raw_fragment",
  "if_statement",  "elseif_statement",  "elsefor_statement",  "for_statement",
  "set_statement",  "echo_statement",  "block_statement",  "cache_statement",
  "extends_statement",  "include_statement",  "require_statement",  "do_statement",
  "return_statement",  "autoescape_statement",  "break_statement",  "continue_statement",
  "macro_statement",  "empty_statement",  "macro_call_statement",  "expr",        
  "set_assignments",  "set_assignment",  "macro_parameters",  "macro_parameter",
  "macro_parameter_default",  "argument_list",  "array_list",    "slice_offset",
  "array_item",    "function_call",  "argument_item",
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
 /*  15 */ "statement ::= require_statement",
 /*  16 */ "statement ::= do_statement",
 /*  17 */ "statement ::= return_statement",
 /*  18 */ "statement ::= autoescape_statement",
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
 /*  38 */ "set_assignment ::= IDENTIFIER ASSIGN expr",
 /*  39 */ "set_assignment ::= IDENTIFIER ADD_ASSIGN expr",
 /*  40 */ "set_assignment ::= IDENTIFIER SUB_ASSIGN expr",
 /*  41 */ "set_assignment ::= IDENTIFIER MUL_ASSIGN expr",
 /*  42 */ "set_assignment ::= IDENTIFIER DIV_ASSIGN expr",
 /*  43 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  44 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN macro_parameters PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  45 */ "macro_parameters ::= macro_parameters COMMA macro_parameter",
 /*  46 */ "macro_parameters ::= macro_parameter",
 /*  47 */ "macro_parameter ::= IDENTIFIER",
 /*  48 */ "macro_parameter ::= IDENTIFIER ASSIGN macro_parameter_default",
 /*  49 */ "macro_parameter_default ::= INTEGER",
 /*  50 */ "macro_parameter_default ::= STRING",
 /*  51 */ "macro_parameter_default ::= DOUBLE",
 /*  52 */ "macro_parameter_default ::= NULL",
 /*  53 */ "macro_parameter_default ::= FALSE",
 /*  54 */ "macro_parameter_default ::= TRUE",
 /*  55 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  56 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  57 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  58 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  59 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  60 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  61 */ "cache_statement ::= OPEN_DELIMITER CACHE expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  62 */ "cache_statement ::= OPEN_DELIMITER CACHE expr INTEGER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  63 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  64 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr CLOSE_DELIMITER",
 /*  65 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr WITH expr CLOSE_DELIMITER",
 /*  66 */ "require_statement ::= OPEN_DELIMITER REQUIRE expr CLOSE_DELIMITER",
 /*  67 */ "require_statement ::= OPEN_DELIMITER REQUIRE expr WITH expr CLOSE_DELIMITER",
 /*  68 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  69 */ "return_statement ::= OPEN_DELIMITER RETURN expr CLOSE_DELIMITER",
 /*  70 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE FALSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  71 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE TRUE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  72 */ "break_statement ::= OPEN_DELIMITER BREAK CLOSE_DELIMITER",
 /*  73 */ "continue_statement ::= OPEN_DELIMITER CONTINUE CLOSE_DELIMITER",
 /*  74 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  75 */ "expr ::= MINUS expr",
 /*  76 */ "expr ::= PLUS expr",
 /*  77 */ "expr ::= expr MINUS expr",
 /*  78 */ "expr ::= expr PLUS expr",
 /*  79 */ "expr ::= expr TIMES expr",
 /*  80 */ "expr ::= expr TIMES TIMES expr",
 /*  81 */ "expr ::= expr DIVIDE expr",
 /*  82 */ "expr ::= expr DIVIDE DIVIDE expr",
 /*  83 */ "expr ::= expr MOD expr",
 /*  84 */ "expr ::= expr AND expr",
 /*  85 */ "expr ::= expr OR expr",
 /*  86 */ "expr ::= expr CONCAT expr",
 /*  87 */ "expr ::= expr PIPE expr",
 /*  88 */ "expr ::= expr RANGE expr",
 /*  89 */ "expr ::= expr EQUALS expr",
 /*  90 */ "expr ::= expr IS NOT DEFINED",
 /*  91 */ "expr ::= expr IS DEFINED",
 /*  92 */ "expr ::= expr IS expr",
 /*  93 */ "expr ::= expr NOTEQUALS expr",
 /*  94 */ "expr ::= expr IDENTICAL expr",
 /*  95 */ "expr ::= expr NOTIDENTICAL expr",
 /*  96 */ "expr ::= expr LESS expr",
 /*  97 */ "expr ::= expr GREATER expr",
 /*  98 */ "expr ::= expr GREATEREQUAL expr",
 /*  99 */ "expr ::= expr LESSEQUAL expr",
 /* 100 */ "expr ::= expr DOT expr",
 /* 101 */ "expr ::= expr IN expr",
 /* 102 */ "expr ::= expr NOT IN expr",
 /* 103 */ "expr ::= NOT expr",
 /* 104 */ "expr ::= expr INCR",
 /* 105 */ "expr ::= expr DECR",
 /* 106 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 107 */ "expr ::= SBRACKET_OPEN SBRACKET_CLOSE",
 /* 108 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /* 109 */ "expr ::= CBRACKET_OPEN CBRACKET_CLOSE",
 /* 110 */ "expr ::= CBRACKET_OPEN array_list CBRACKET_CLOSE",
 /* 111 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /* 112 */ "expr ::= expr QUESTION expr COLON expr",
 /* 113 */ "expr ::= expr SBRACKET_OPEN COLON slice_offset SBRACKET_CLOSE",
 /* 114 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON SBRACKET_CLOSE",
 /* 115 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON slice_offset SBRACKET_CLOSE",
 /* 116 */ "slice_offset ::= INTEGER",
 /* 117 */ "slice_offset ::= IDENTIFIER",
 /* 118 */ "array_list ::= array_list COMMA array_item",
 /* 119 */ "array_list ::= array_item",
 /* 120 */ "array_item ::= STRING COLON expr",
 /* 121 */ "array_item ::= expr",
 /* 122 */ "expr ::= function_call",
 /* 123 */ "function_call ::= expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 124 */ "function_call ::= expr PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 125 */ "argument_list ::= argument_list COMMA argument_item",
 /* 126 */ "argument_list ::= argument_item",
 /* 127 */ "argument_item ::= expr",
 /* 128 */ "argument_item ::= STRING COLON expr",
 /* 129 */ "expr ::= IDENTIFIER",
 /* 130 */ "expr ::= INTEGER",
 /* 131 */ "expr ::= STRING",
 /* 132 */ "expr ::= DOUBLE",
 /* 133 */ "expr ::= NULL",
 /* 134 */ "expr ::= FALSE",
 /* 135 */ "expr ::= TRUE",
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
    case 77:
/* #line 718 "parser.y" */
{
	if ((kkpminor->kk0)) {
		if ((kkpminor->kk0)->free_flag) {
			efree((kkpminor->kk0)->token);
		}
		efree((kkpminor->kk0));
	}
}
/* #line 1774 "parser.c" */
      break;
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
    case 106:
    case 107:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
/* #line 735 "parser.y" */
{ zval_ptr_dtor(&(kkpminor->kk158)); }
/* #line 1811 "parser.c" */
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
  { 79, 1 },
  { 80, 1 },
  { 81, 2 },
  { 81, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 82, 1 },
  { 84, 8 },
  { 84, 7 },
  { 84, 12 },
  { 84, 11 },
  { 84, 10 },
  { 85, 4 },
  { 86, 3 },
  { 87, 10 },
  { 87, 12 },
  { 87, 12 },
  { 87, 14 },
  { 88, 4 },
  { 104, 3 },
  { 104, 1 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 100, 10 },
  { 100, 11 },
  { 106, 3 },
  { 106, 1 },
  { 107, 1 },
  { 107, 3 },
  { 108, 1 },
  { 108, 1 },
  { 108, 1 },
  { 108, 1 },
  { 108, 1 },
  { 108, 1 },
  { 102, 11 },
  { 102, 9 },
  { 101, 2 },
  { 89, 3 },
  { 90, 8 },
  { 90, 7 },
  { 91, 8 },
  { 91, 9 },
  { 92, 4 },
  { 93, 4 },
  { 93, 6 },
  { 94, 4 },
  { 94, 6 },
  { 95, 4 },
  { 96, 4 },
  { 97, 8 },
  { 97, 8 },
  { 98, 3 },
  { 99, 3 },
  { 83, 1 },
  { 103, 2 },
  { 103, 2 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 4 },
  { 103, 3 },
  { 103, 4 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 4 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 3 },
  { 103, 4 },
  { 103, 2 },
  { 103, 2 },
  { 103, 2 },
  { 103, 3 },
  { 103, 2 },
  { 103, 3 },
  { 103, 2 },
  { 103, 3 },
  { 103, 4 },
  { 103, 5 },
  { 103, 5 },
  { 103, 5 },
  { 103, 6 },
  { 111, 1 },
  { 111, 1 },
  { 110, 3 },
  { 110, 1 },
  { 112, 3 },
  { 112, 1 },
  { 103, 1 },
  { 113, 4 },
  { 113, 3 },
  { 109, 3 },
  { 109, 1 },
  { 114, 1 },
  { 114, 3 },
  { 103, 1 },
  { 103, 1 },
  { 103, 1 },
  { 103, 1 },
  { 103, 1 },
  { 103, 1 },
  { 103, 1 },
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
/* #line 727 "parser.y" */
{
	status->ret = kkmsp[0].minor.kk158;
}
/* #line 2164 "parser.c" */
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
      case 122:
/* #line 731 "parser.y" */
{
	kkgotominor.kk158 = kkmsp[0].minor.kk158;
}
/* #line 2192 "parser.c" */
        break;
      case 2:
/* #line 737 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_zval_list(kkmsp[-1].minor.kk158, kkmsp[0].minor.kk158);
}
/* #line 2199 "parser.c" */
        break;
      case 3:
      case 37:
      case 46:
      case 119:
      case 126:
/* #line 741 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_zval_list(NULL, kkmsp[0].minor.kk158);
}
/* #line 2210 "parser.c" */
        break;
      case 24:
/* #line 829 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_if_statement(kkmsp[-5].minor.kk158, kkmsp[-3].minor.kk158, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(31,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2223 "parser.c" */
        break;
      case 25:
/* #line 833 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_if_statement(kkmsp[-4].minor.kk158, NULL, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(31,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(33,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2236 "parser.c" */
        break;
      case 26:
/* #line 837 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_if_statement(kkmsp[-9].minor.kk158, kkmsp[-7].minor.kk158, kkmsp[-3].minor.kk158, status->scanner_state);
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
/* #line 2252 "parser.c" */
        break;
      case 27:
/* #line 841 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_if_statement(kkmsp[-8].minor.kk158, kkmsp[-6].minor.kk158, NULL, status->scanner_state);
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
/* #line 2268 "parser.c" */
        break;
      case 28:
/* #line 845 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_if_statement(kkmsp[-7].minor.kk158, NULL, NULL, status->scanner_state);
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
/* #line 2284 "parser.c" */
        break;
      case 29:
/* #line 851 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_elseif_statement(kkmsp[-1].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(35,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2294 "parser.c" */
        break;
      case 30:
/* #line 857 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_elsefor_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(36,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2304 "parser.c" */
        break;
      case 31:
/* #line 863 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-5].minor.kk158, NULL, kkmsp[-3].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(37,&kkmsp[-8].minor);
  kk_destructor(3,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2318 "parser.c" */
        break;
      case 32:
/* #line 867 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, NULL, kkmsp[-7].minor.kk158, kkmsp[-5].minor.kk158, kkmsp[-3].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(37,&kkmsp[-10].minor);
  kk_destructor(3,&kkmsp[-8].minor);
  kk_destructor(31,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2333 "parser.c" */
        break;
      case 33:
/* #line 871 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_for_statement(kkmsp[-7].minor.kk0, kkmsp[-9].minor.kk0, kkmsp[-5].minor.kk158, NULL, kkmsp[-3].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-11].minor);
  kk_destructor(37,&kkmsp[-10].minor);
  kk_destructor(2,&kkmsp[-8].minor);
  kk_destructor(3,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(39,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2348 "parser.c" */
        break;
      case 34:
/* #line 875 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_for_statement(kkmsp[-9].minor.kk0, kkmsp[-11].minor.kk0, kkmsp[-7].minor.kk158, kkmsp[-5].minor.kk158, kkmsp[-3].minor.kk158, status->scanner_state);
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
/* #line 2364 "parser.c" */
        break;
      case 35:
/* #line 881 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_set_statement(kkmsp[-1].minor.kk158);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(40,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2374 "parser.c" */
        break;
      case 36:
      case 45:
      case 118:
      case 125:
/* #line 887 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_zval_list(kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158);
  kk_destructor(2,&kkmsp[-1].minor);
}
/* #line 2385 "parser.c" */
        break;
      case 38:
/* #line 897 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_ASSIGN, kkmsp[0].minor.kk158, status->scanner_state);
  kk_destructor(41,&kkmsp[-1].minor);
}
/* #line 2393 "parser.c" */
        break;
      case 39:
/* #line 901 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_ADD_ASSIGN, kkmsp[0].minor.kk158, status->scanner_state);
  kk_destructor(42,&kkmsp[-1].minor);
}
/* #line 2401 "parser.c" */
        break;
      case 40:
/* #line 905 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_SUB_ASSIGN, kkmsp[0].minor.kk158, status->scanner_state);
  kk_destructor(43,&kkmsp[-1].minor);
}
/* #line 2409 "parser.c" */
        break;
      case 41:
/* #line 909 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_MUL_ASSIGN, kkmsp[0].minor.kk158, status->scanner_state);
  kk_destructor(44,&kkmsp[-1].minor);
}
/* #line 2417 "parser.c" */
        break;
      case 42:
/* #line 913 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_set_assignment(kkmsp[-2].minor.kk0, PHVOLT_T_DIV_ASSIGN, kkmsp[0].minor.kk158, status->scanner_state);
  kk_destructor(45,&kkmsp[-1].minor);
}
/* #line 2425 "parser.c" */
        break;
      case 43:
/* #line 919 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_macro_statement(kkmsp[-7].minor.kk0, NULL, kkmsp[-3].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-9].minor);
  kk_destructor(46,&kkmsp[-8].minor);
  kk_destructor(29,&kkmsp[-6].minor);
  kk_destructor(47,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(48,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2440 "parser.c" */
        break;
      case 44:
/* #line 923 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_macro_statement(kkmsp[-8].minor.kk0, kkmsp[-6].minor.kk158, kkmsp[-3].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(46,&kkmsp[-9].minor);
  kk_destructor(29,&kkmsp[-7].minor);
  kk_destructor(47,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(48,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2455 "parser.c" */
        break;
      case 47:
/* #line 939 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_macro_parameter(kkmsp[0].minor.kk0, NULL, status->scanner_state);
}
/* #line 2462 "parser.c" */
        break;
      case 48:
/* #line 943 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_macro_parameter(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk158, status->scanner_state);
  kk_destructor(41,&kkmsp[-1].minor);
}
/* #line 2470 "parser.c" */
        break;
      case 49:
      case 116:
      case 130:
/* #line 947 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, kkmsp[0].minor.kk0, status->scanner_state);
}
/* #line 2479 "parser.c" */
        break;
      case 50:
      case 131:
/* #line 951 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_literal_zval(PHVOLT_T_STRING, kkmsp[0].minor.kk0, status->scanner_state);
}
/* #line 2487 "parser.c" */
        break;
      case 51:
      case 132:
/* #line 955 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, kkmsp[0].minor.kk0, status->scanner_state);
}
/* #line 2495 "parser.c" */
        break;
      case 52:
      case 133:
/* #line 959 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  kk_destructor(52,&kkmsp[0].minor);
}
/* #line 2504 "parser.c" */
        break;
      case 53:
      case 134:
/* #line 963 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  kk_destructor(53,&kkmsp[0].minor);
}
/* #line 2513 "parser.c" */
        break;
      case 54:
      case 135:
/* #line 967 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  kk_destructor(54,&kkmsp[0].minor);
}
/* #line 2522 "parser.c" */
        break;
      case 55:
/* #line 973 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_macro_call_statement(kkmsp[-8].minor.kk158, kkmsp[-6].minor.kk158, kkmsp[-3].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-10].minor);
  kk_destructor(55,&kkmsp[-9].minor);
  kk_destructor(29,&kkmsp[-7].minor);
  kk_destructor(47,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(56,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2537 "parser.c" */
        break;
      case 56:
/* #line 977 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_macro_call_statement(kkmsp[-6].minor.kk158, NULL, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(55,&kkmsp[-7].minor);
  kk_destructor(29,&kkmsp[-5].minor);
  kk_destructor(47,&kkmsp[-4].minor);
  kk_destructor(32,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(56,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2552 "parser.c" */
        break;
      case 57:
/* #line 983 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_empty_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2561 "parser.c" */
        break;
      case 58:
/* #line 989 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_echo_statement(kkmsp[-1].minor.kk158, status->scanner_state);
  kk_destructor(57,&kkmsp[-2].minor);
  kk_destructor(58,&kkmsp[0].minor);
}
/* #line 2570 "parser.c" */
        break;
      case 59:
/* #line 995 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_block_statement(kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(59,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(60,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2583 "parser.c" */
        break;
      case 60:
/* #line 999 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_block_statement(kkmsp[-4].minor.kk0, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-6].minor);
  kk_destructor(59,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-3].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(60,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2596 "parser.c" */
        break;
      case 61:
/* #line 1005 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_cache_statement(kkmsp[-5].minor.kk158, NULL, kkmsp[-3].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(61,&kkmsp[-6].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(62,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2609 "parser.c" */
        break;
      case 62:
/* #line 1009 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_cache_statement(kkmsp[-6].minor.kk158, kkmsp[-5].minor.kk0, kkmsp[-3].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-8].minor);
  kk_destructor(61,&kkmsp[-7].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(62,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2622 "parser.c" */
        break;
      case 63:
/* #line 1015 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_extends_statement(kkmsp[-1].minor.kk0, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(63,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2632 "parser.c" */
        break;
      case 64:
/* #line 1021 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_include_statement(kkmsp[-1].minor.kk158, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(64,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2642 "parser.c" */
        break;
      case 65:
/* #line 1025 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_include_statement(kkmsp[-3].minor.kk158, kkmsp[-1].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(64,&kkmsp[-4].minor);
  kk_destructor(65,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2653 "parser.c" */
        break;
      case 66:
/* #line 1031 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_require_statement(kkmsp[-1].minor.kk158, NULL, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(66,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2663 "parser.c" */
        break;
      case 67:
/* #line 1035 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_require_statement(kkmsp[-3].minor.kk158, kkmsp[-1].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-5].minor);
  kk_destructor(66,&kkmsp[-4].minor);
  kk_destructor(65,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2674 "parser.c" */
        break;
      case 68:
/* #line 1041 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_do_statement(kkmsp[-1].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(67,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2684 "parser.c" */
        break;
      case 69:
/* #line 1047 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_return_statement(kkmsp[-1].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-3].minor);
  kk_destructor(68,&kkmsp[-2].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2694 "parser.c" */
        break;
      case 70:
/* #line 1053 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_autoescape_statement(0, kkmsp[-3].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(69,&kkmsp[-6].minor);
  kk_destructor(53,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(70,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2708 "parser.c" */
        break;
      case 71:
/* #line 1057 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_autoescape_statement(1, kkmsp[-3].minor.kk158, status->scanner_state);
  kk_destructor(1,&kkmsp[-7].minor);
  kk_destructor(69,&kkmsp[-6].minor);
  kk_destructor(54,&kkmsp[-5].minor);
  kk_destructor(32,&kkmsp[-4].minor);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(70,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2722 "parser.c" */
        break;
      case 72:
/* #line 1063 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_break_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(71,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2732 "parser.c" */
        break;
      case 73:
/* #line 1069 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_continue_statement(status->scanner_state);
  kk_destructor(1,&kkmsp[-2].minor);
  kk_destructor(72,&kkmsp[-1].minor);
  kk_destructor(32,&kkmsp[0].minor);
}
/* #line 2742 "parser.c" */
        break;
      case 74:
/* #line 1075 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, kkmsp[0].minor.kk0, status->scanner_state);
}
/* #line 2749 "parser.c" */
        break;
      case 75:
/* #line 1081 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
/* #line 2757 "parser.c" */
        break;
      case 76:
/* #line 1085 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_PLUS, NULL, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
/* #line 2765 "parser.c" */
        break;
      case 77:
/* #line 1089 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_SUB, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(22,&kkmsp[-1].minor);
}
/* #line 2773 "parser.c" */
        break;
      case 78:
/* #line 1093 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_ADD, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(21,&kkmsp[-1].minor);
}
/* #line 2781 "parser.c" */
        break;
      case 79:
/* #line 1097 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_MUL, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(19,&kkmsp[-1].minor);
}
/* #line 2789 "parser.c" */
        break;
      case 80:
/* #line 1101 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_POW, kkmsp[-3].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(19,&kkmsp[-2].minor);
  kk_destructor(19,&kkmsp[-1].minor);
}
/* #line 2798 "parser.c" */
        break;
      case 81:
/* #line 1105 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_DIV, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(18,&kkmsp[-1].minor);
}
/* #line 2806 "parser.c" */
        break;
      case 82:
/* #line 1109 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-3].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(18,&kkmsp[-2].minor);
  kk_destructor(18,&kkmsp[-1].minor);
}
/* #line 2815 "parser.c" */
        break;
      case 83:
/* #line 1113 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_MOD, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(20,&kkmsp[-1].minor);
}
/* #line 2823 "parser.c" */
        break;
      case 84:
/* #line 1117 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_AND, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(7,&kkmsp[-1].minor);
}
/* #line 2831 "parser.c" */
        break;
      case 85:
/* #line 1121 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_OR, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(8,&kkmsp[-1].minor);
}
/* #line 2839 "parser.c" */
        break;
      case 86:
/* #line 1125 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_CONCAT, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(23,&kkmsp[-1].minor);
}
/* #line 2847 "parser.c" */
        break;
      case 87:
/* #line 1129 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_PIPE, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(25,&kkmsp[-1].minor);
}
/* #line 2855 "parser.c" */
        break;
      case 88:
/* #line 1133 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_RANGE, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(6,&kkmsp[-1].minor);
}
/* #line 2863 "parser.c" */
        break;
      case 89:
/* #line 1137 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_EQUALS, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(10,&kkmsp[-1].minor);
}
/* #line 2871 "parser.c" */
        break;
      case 90:
/* #line 1141 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, kkmsp[-3].minor.kk158, NULL, NULL, status->scanner_state);
  kk_destructor(9,&kkmsp[-2].minor);
  kk_destructor(26,&kkmsp[-1].minor);
  kk_destructor(74,&kkmsp[0].minor);
}
/* #line 2881 "parser.c" */
        break;
      case 91:
/* #line 1145 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_ISSET, kkmsp[-2].minor.kk158, NULL, NULL, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
  kk_destructor(74,&kkmsp[0].minor);
}
/* #line 2890 "parser.c" */
        break;
      case 92:
/* #line 1149 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_IS, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(9,&kkmsp[-1].minor);
}
/* #line 2898 "parser.c" */
        break;
      case 93:
/* #line 1153 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(11,&kkmsp[-1].minor);
}
/* #line 2906 "parser.c" */
        break;
      case 94:
/* #line 1157 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(16,&kkmsp[-1].minor);
}
/* #line 2914 "parser.c" */
        break;
      case 95:
/* #line 1161 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(17,&kkmsp[-1].minor);
}
/* #line 2922 "parser.c" */
        break;
      case 96:
/* #line 1165 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_LESS, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(12,&kkmsp[-1].minor);
}
/* #line 2930 "parser.c" */
        break;
      case 97:
/* #line 1169 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_GREATER, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(13,&kkmsp[-1].minor);
}
/* #line 2938 "parser.c" */
        break;
      case 98:
/* #line 1173 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(14,&kkmsp[-1].minor);
}
/* #line 2946 "parser.c" */
        break;
      case 99:
/* #line 1177 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(15,&kkmsp[-1].minor);
}
/* #line 2954 "parser.c" */
        break;
      case 100:
/* #line 1181 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_DOT, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(30,&kkmsp[-1].minor);
}
/* #line 2962 "parser.c" */
        break;
      case 101:
/* #line 1185 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_IN, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(3,&kkmsp[-1].minor);
}
/* #line 2970 "parser.c" */
        break;
      case 102:
/* #line 1189 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_NOT_IN, kkmsp[-3].minor.kk158, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-2].minor);
  kk_destructor(3,&kkmsp[-1].minor);
}
/* #line 2979 "parser.c" */
        break;
      case 103:
/* #line 1193 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, kkmsp[0].minor.kk158, NULL, status->scanner_state);
  kk_destructor(26,&kkmsp[-1].minor);
}
/* #line 2987 "parser.c" */
        break;
      case 104:
/* #line 1197 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_INCR, kkmsp[-1].minor.kk158, NULL, NULL, status->scanner_state);
  kk_destructor(27,&kkmsp[0].minor);
}
/* #line 2995 "parser.c" */
        break;
      case 105:
/* #line 1201 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_DECR, kkmsp[-1].minor.kk158, NULL, NULL, status->scanner_state);
  kk_destructor(28,&kkmsp[0].minor);
}
/* #line 3003 "parser.c" */
        break;
      case 106:
/* #line 1205 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, kkmsp[-1].minor.kk158, NULL, NULL, status->scanner_state);
  kk_destructor(29,&kkmsp[-2].minor);
  kk_destructor(47,&kkmsp[0].minor);
}
/* #line 3012 "parser.c" */
        break;
      case 107:
/* #line 1209 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-1].minor);
  kk_destructor(75,&kkmsp[0].minor);
}
/* #line 3021 "parser.c" */
        break;
      case 108:
/* #line 1213 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk158, NULL, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-2].minor);
  kk_destructor(75,&kkmsp[0].minor);
}
/* #line 3030 "parser.c" */
        break;
      case 109:
/* #line 1217 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  kk_destructor(76,&kkmsp[-1].minor);
  kk_destructor(77,&kkmsp[0].minor);
}
/* #line 3039 "parser.c" */
        break;
      case 110:
/* #line 1221 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_ARRAY, kkmsp[-1].minor.kk158, NULL, NULL, status->scanner_state);
  kk_destructor(76,&kkmsp[-2].minor);
  kk_destructor(77,&kkmsp[0].minor);
}
/* #line 3048 "parser.c" */
        break;
      case 111:
/* #line 1225 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, kkmsp[-3].minor.kk158, kkmsp[-1].minor.kk158, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-2].minor);
  kk_destructor(75,&kkmsp[0].minor);
}
/* #line 3057 "parser.c" */
        break;
      case 112:
/* #line 1229 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_expr(PHVOLT_T_TERNARY, kkmsp[-2].minor.kk158, kkmsp[0].minor.kk158, kkmsp[-4].minor.kk158, status->scanner_state);
  kk_destructor(4,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-1].minor);
}
/* #line 3066 "parser.c" */
        break;
      case 113:
/* #line 1233 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_slice(kkmsp[-4].minor.kk158, NULL, kkmsp[-1].minor.kk158, status->scanner_state);
  kk_destructor(24,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-2].minor);
  kk_destructor(75,&kkmsp[0].minor);
}
/* #line 3076 "parser.c" */
        break;
      case 114:
/* #line 1237 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_slice(kkmsp[-4].minor.kk158, kkmsp[-2].minor.kk158, NULL, status->scanner_state);
  kk_destructor(24,&kkmsp[-3].minor);
  kk_destructor(5,&kkmsp[-1].minor);
  kk_destructor(75,&kkmsp[0].minor);
}
/* #line 3086 "parser.c" */
        break;
      case 115:
/* #line 1241 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_slice(kkmsp[-5].minor.kk158, kkmsp[-3].minor.kk158, kkmsp[-1].minor.kk158, status->scanner_state);
  kk_destructor(24,&kkmsp[-4].minor);
  kk_destructor(5,&kkmsp[-2].minor);
  kk_destructor(75,&kkmsp[0].minor);
}
/* #line 3096 "parser.c" */
        break;
      case 117:
      case 129:
/* #line 1251 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, kkmsp[0].minor.kk0, status->scanner_state);
}
/* #line 3104 "parser.c" */
        break;
      case 120:
      case 128:
/* #line 1267 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_named_item(kkmsp[-2].minor.kk0, kkmsp[0].minor.kk158, status->scanner_state);
  kk_destructor(5,&kkmsp[-1].minor);
}
/* #line 3113 "parser.c" */
        break;
      case 121:
      case 127:
/* #line 1271 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_named_item(NULL, kkmsp[0].minor.kk158, status->scanner_state);
}
/* #line 3121 "parser.c" */
        break;
      case 123:
/* #line 1281 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_func_call(kkmsp[-3].minor.kk158, kkmsp[-1].minor.kk158, status->scanner_state);
  kk_destructor(29,&kkmsp[-2].minor);
  kk_destructor(47,&kkmsp[0].minor);
}
/* #line 3130 "parser.c" */
        break;
      case 124:
/* #line 1285 "parser.y" */
{
	kkgotominor.kk158 = phvolt_ret_func_call(kkmsp[-2].minor.kk158, NULL, status->scanner_state);
  kk_destructor(29,&kkmsp[-1].minor);
  kk_destructor(47,&kkmsp[0].minor);
}
/* #line 3139 "parser.c" */
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
/* #line 620 "parser.y" */

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

/* #line 3279 "parser.c" */
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
  { SL("REQUIRE"),        PHVOLT_T_REQUIRE },
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

			case PHVOLT_T_REQUIRE:
				phvolt_(phvolt_parser, PHVOLT_REQUIRE, NULL, parser_status);
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
