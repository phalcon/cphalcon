
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include <ext/standard/php_smart_string.h>
#include <zend_smart_str.h>

#include "parser.php7.h"
#include "scanner.h"
#include "volt.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

#define phvolt_add_assoc_stringl(var, index, str, len, copy) add_assoc_stringl(var, index, str, len);

static void phvolt_ret_literal_zval(zval *ret, int type, phvolt_parser_token *T, phvolt_scanner_state *state)
{
	array_init(ret);
	add_assoc_long(ret, "type", type);
	if (T) {
		phvolt_add_assoc_stringl(ret, "value", T->token, T->token_len, 0);
		efree(T->token);
		efree(T);
	}

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_if_statement(zval *ret, zval *expr, zval *true_statements, zval *false_statements, phvolt_scanner_state *state)
{
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_IF);
	add_assoc_zval(ret, "expr", expr);

	if (true_statements) {
		add_assoc_zval(ret, "true_statements", true_statements);
	}
	if (false_statements) {
		add_assoc_zval(ret, "false_statements", false_statements);
	}

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_elseif_statement(zval *ret, zval *expr, phvolt_scanner_state *state)
{
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_ELSEIF);
	add_assoc_zval(ret, "expr", expr);

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_elsefor_statement(zval *ret, phvolt_scanner_state *state)
{
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_ELSEFOR);

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_switch_statement(zval *ret, zval *expr, zval *case_clauses, phvolt_scanner_state *state)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_SWITCH);
	add_assoc_zval(ret, "expr", expr);

	if (case_clauses) {
		add_assoc_zval(ret, "case_clauses", case_clauses);
	}

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_case_clause(zval *ret, zval *expr, phvolt_scanner_state *state)
{
	array_init(ret);

	if (expr) {
		add_assoc_long(ret, "type", PHVOLT_T_CASE);
		add_assoc_zval(ret, "expr", expr);
	} else {
		add_assoc_long(ret, "type", PHVOLT_T_DEFAULT);
	}

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_for_statement(zval *ret, phvolt_parser_token *variable, phvolt_parser_token *key, zval *expr, zval *if_expr, zval *block_statements, phvolt_scanner_state *state)
{
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_FOR);

	phvolt_add_assoc_stringl(ret, "variable", variable->token, variable->token_len, 0);
	efree(variable->token);
	efree(variable);

	if (key) {
		phvolt_add_assoc_stringl(ret, "key", key->token, key->token_len, 0);
		efree(key->token);
		efree(key);
	}

	add_assoc_zval(ret, "expr", expr);
	if (if_expr) {
		add_assoc_zval(ret, "if_expr", if_expr);
	}

	add_assoc_zval(ret, "block_statements", block_statements);

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_cache_statement(zval *ret, zval *expr, zval *lifetime, zval *block_statements, phvolt_scanner_state *state)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_CACHE);
	add_assoc_zval(ret, "expr", expr);

	if (lifetime) {
		add_assoc_zval(ret, "lifetime", lifetime);
	}
	add_assoc_zval(ret, "block_statements", block_statements);

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_raw_statement(zval *ret, zval *statement, phvolt_scanner_state *state)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_RAW);
	add_assoc_zval(ret, "content", statement);

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_set_statement(zval *ret, zval *assignments)
{
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_SET);

	add_assoc_zval(ret, "assignments", assignments);
}

static void phvolt_ret_set_assignment(zval *ret, zval *assignable_expr, int operator, zval *expr, phvolt_scanner_state *state)
{

	array_init(ret);

	add_assoc_zval(ret, "variable", assignable_expr);
	add_assoc_long(ret, "op", operator);
	add_assoc_zval(ret, "expr", expr);

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_echo_statement(zval *ret, zval *expr, phvolt_scanner_state *state)
{
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_ECHO);
	add_assoc_zval(ret, "expr", expr);

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_block_statement(zval *ret, phvolt_parser_token *name, zval *block_statements, phvolt_scanner_state *state)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_BLOCK);

	phvolt_add_assoc_stringl(ret, "name", name->token, name->token_len, 0);
	efree(name->token);
	efree(name);

	if (block_statements) {
		add_assoc_zval(ret, "block_statements", block_statements);
	}

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_macro_statement(zval *ret, phvolt_parser_token *macro_name, zval *parameters, zval *block_statements, phvolt_scanner_state *state)
{
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_MACRO);

	phvolt_add_assoc_stringl(ret, "name", macro_name->token, macro_name->token_len, 0);
	efree(macro_name->token);
	efree(macro_name);

	if (parameters) {
		add_assoc_zval(ret, "parameters", parameters);
	}

	if (block_statements) {
		add_assoc_zval(ret, "block_statements", block_statements);
	}

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_macro_parameter(zval *ret, phvolt_parser_token *variable, zval *default_value, phvolt_scanner_state *state)
{
	array_init(ret);

	phvolt_add_assoc_stringl(ret, "variable", variable->token, variable->token_len, 0);
	efree(variable->token);
	efree(variable);

	if (default_value) {
		add_assoc_zval(ret, "default", default_value);
	}

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_extends_statement(zval *ret, zval *path, phvolt_scanner_state *state)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_EXTENDS);
	add_assoc_zval(ret, "path", path);

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_include_statement(zval *ret, zval *path, zval *params, phvolt_scanner_state *state)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_INCLUDE);

	add_assoc_zval(ret, "path", path);
	if (params) {
		add_assoc_zval(ret, "params", params);
	}

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_do_statement(zval *ret, zval *expr, phvolt_scanner_state *state)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_DO);
	add_assoc_zval(ret, "expr", expr);

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_return_statement(zval *ret, zval *expr, phvolt_scanner_state *state)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_RETURN);
	add_assoc_zval(ret, "expr", expr);

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_autoescape_statement(zval *ret, int enable, zval *block_statements, phvolt_scanner_state *state)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_AUTOESCAPE);
	add_assoc_long(ret, "enable", enable);
	add_assoc_zval(ret, "block_statements", block_statements);

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_empty_statement(zval *ret, phvolt_scanner_state *state)
{
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_EMPTY_STATEMENT);

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_break_statement(zval *ret, phvolt_scanner_state *state)
{
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_BREAK);

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_continue_statement(zval *ret, phvolt_scanner_state *state)
{
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_CONTINUE);

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_zval_list(zval *ret, zval *list_left, zval *right_list)
{
	HashTable *list;

	array_init(ret);

	if (list_left) {

		list = Z_ARRVAL_P(list_left);
		if (zend_hash_index_exists(list, 0)) {
			{
				zval *item;
				ZEND_HASH_FOREACH_VAL(list, item) {

					Z_TRY_ADDREF_P(item);
					add_next_index_zval(ret, item);

				} ZEND_HASH_FOREACH_END();
			}
			zval_dtor(list_left);
		} else {
			add_next_index_zval(ret, list_left);
		}
	}

	add_next_index_zval(ret, right_list);
}

static void phvolt_ret_named_item(zval *ret, phvolt_parser_token *name, zval *expr, phvolt_scanner_state *state)
{
	array_init(ret);
	add_assoc_zval(ret, "expr", expr);
	if (name != NULL) {
		phvolt_add_assoc_stringl(ret, "name", name->token, name->token_len, 0);
		efree(name->token);
		efree(name);
	}

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_expr(zval *ret, int type, zval *left, zval *right, zval *ternary, phvolt_scanner_state *state)
{
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

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_slice(zval *ret, zval *left, zval *start, zval *end, phvolt_scanner_state *state)
{
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_SLICE);
	add_assoc_zval(ret, "left", left);

	if (start != NULL) {
		add_assoc_zval(ret, "start", start);
	}

	if (end != NULL) {
		add_assoc_zval(ret, "end", end);
	}

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_func_call(zval *ret, zval *expr, zval *arguments, phvolt_scanner_state *state)
{

	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_FCALL);
	add_assoc_zval(ret, "name", expr);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}

static void phvolt_ret_macro_call_statement(zval *ret, zval *expr, zval *arguments, zval *caller, phvolt_scanner_state *state)
{

	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_CALL);
	add_assoc_zval(ret, "name", expr);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	if (caller) {
		add_assoc_zval(ret, "caller", caller);
	}

	Z_TRY_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}
