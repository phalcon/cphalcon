
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include <ext/standard/php_smart_str.h>

#include "parser.php5.h"
#include "scanner.h"
#include "volt.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

#define PHVOLT_DEFINE_INIT_ZVAL(var) zval *var; MAKE_STD_ZVAL(var);
#define phvolt_add_assoc_stringl(var, index, str, len, copy) add_assoc_stringl(var, index, str, len, copy);
#define PHVOLT_ADDREF_P(var) Z_ADDREF_P(var)

static zval *phvolt_ret_literal_zval(int type, phvolt_parser_token *T, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 5);
	add_assoc_long(ret, "type", type);
	if (T) {
		phvolt_add_assoc_stringl(ret, "value", T->token, T->token_len, 0);
		//efree(T->token);
		efree(T);
	}

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_if_statement(zval *expr, zval *true_statements, zval *false_statements, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 7);
	add_assoc_long(ret, "type", PHVOLT_T_IF);
	add_assoc_zval(ret, "expr", expr);

	if (true_statements) {
		add_assoc_zval(ret, "true_statements", true_statements);
	}
	if (false_statements) {
		add_assoc_zval(ret, "false_statements", false_statements);
	}

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_elseif_statement(zval *expr, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 5);
	add_assoc_long(ret, "type", PHVOLT_T_ELSEIF);
	add_assoc_zval(ret, "expr", expr);

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_elsefor_statement(phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 4);
	add_assoc_long(ret, "type", PHVOLT_T_ELSEFOR);

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_switch_statement(zval *expr, zval *case_clauses, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 6);

	add_assoc_long(ret, "type", PHVOLT_T_SWITCH);
	add_assoc_zval(ret, "expr", expr);

	if (case_clauses) {
		add_assoc_zval(ret, "case_clauses", case_clauses);
	}

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_case_clause(zval *expr, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 5);

	if (expr) {
		add_assoc_long(ret, "type", PHVOLT_T_CASE);
		add_assoc_zval(ret, "expr", expr);
	} else {
		add_assoc_long(ret, "type", PHVOLT_T_DEFAULT);
	}

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_for_statement(phvolt_parser_token *variable, phvolt_parser_token *key, zval *expr, zval *if_expr, zval *block_statements, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 9);
	add_assoc_long(ret, "type", PHVOLT_T_FOR);

	phvolt_add_assoc_stringl(ret, "variable", variable->token, variable->token_len, 0);
	//efree(variable->token);
	efree(variable);

	if (key) {
		phvolt_add_assoc_stringl(ret, "key", key->token, key->token_len, 0);
		//efree(key->token);
		efree(key);
	}

	add_assoc_zval(ret, "expr", expr);
	if (if_expr) {
		add_assoc_zval(ret, "if_expr", if_expr);
	}

	add_assoc_zval(ret, "block_statements", block_statements);

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_cache_statement(zval *expr, zval *lifetime, zval *block_statements, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_CACHE);
	add_assoc_zval(ret, "expr", expr);

	if (lifetime) {
		add_assoc_zval(ret, "lifetime", lifetime);
	}
	add_assoc_zval(ret, "block_statements", block_statements);

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_raw_statement(zval *statement, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_RAW);
	add_assoc_zval(ret, "content", statement);

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_set_statement(zval *assignments)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 3);
	add_assoc_long(ret, "type", PHVOLT_T_SET);

	add_assoc_zval(ret, "assignments", assignments);

	return ret;
}

static zval *phvolt_ret_set_assignment(zval *assignable_expr, int operator, zval *expr, phvolt_scanner_state *state)
{

	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 5);

	add_assoc_zval(ret, "variable", assignable_expr);
	add_assoc_long(ret, "op", operator);
	add_assoc_zval(ret, "expr", expr);

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_echo_statement(zval *expr, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 4);
	add_assoc_long(ret, "type", PHVOLT_T_ECHO);
	add_assoc_zval(ret, "expr", expr);

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_block_statement(phvolt_parser_token *name, zval *block_statements, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 6);

	add_assoc_long(ret, "type", PHVOLT_T_BLOCK);

	phvolt_add_assoc_stringl(ret, "name", name->token, name->token_len, 0);
	//efree(name->token);
	efree(name);

	if (block_statements) {
		add_assoc_zval(ret, "block_statements", block_statements);
	}

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_macro_statement(phvolt_parser_token *macro_name, zval *parameters, zval *block_statements, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_MACRO);

	phvolt_add_assoc_stringl(ret, "name", macro_name->token, macro_name->token_len, 0);
	//efree(macro_name->token);
	efree(macro_name);

	if (parameters) {
		add_assoc_zval(ret, "parameters", parameters);
	}

	if (block_statements) {
		add_assoc_zval(ret, "block_statements", block_statements);
	}

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_macro_parameter(phvolt_parser_token *variable, zval *default_value, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 5);

	phvolt_add_assoc_stringl(ret, "variable", variable->token, variable->token_len, 0);
	//efree(variable->token);
	efree(variable);

	if (default_value) {
		add_assoc_zval(ret, "default", default_value);
	}

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_extends_statement(zval *path, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 4);

	add_assoc_long(ret, "type", PHVOLT_T_EXTENDS);
	add_assoc_zval(ret, "path", path);

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_include_statement(zval *path, zval *params, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 5);

	add_assoc_long(ret, "type", PHVOLT_T_INCLUDE);

	add_assoc_zval(ret, "path", path);
	if (params) {
		add_assoc_zval(ret, "params", params);
	}

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_do_statement(zval *expr, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 5);

	add_assoc_long(ret, "type", PHVOLT_T_DO);
	add_assoc_zval(ret, "expr", expr);

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_return_statement(zval *expr, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 4);

	add_assoc_long(ret, "type", PHVOLT_T_RETURN);
	add_assoc_zval(ret, "expr", expr);

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_autoescape_statement(int enable, zval *block_statements, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 5);

	add_assoc_long(ret, "type", PHVOLT_T_AUTOESCAPE);
	add_assoc_long(ret, "enable", enable);
	add_assoc_zval(ret, "block_statements", block_statements);

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_empty_statement(phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 3);
	add_assoc_long(ret, "type", PHVOLT_T_EMPTY_STATEMENT);

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_break_statement(phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 3);
	add_assoc_long(ret, "type", PHVOLT_T_BREAK);

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_continue_statement(phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init_size(ret, 3);
	add_assoc_long(ret, "type", PHVOLT_T_CONTINUE);

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_zval_list(zval *list_left, zval *right_list)
{
	HashTable *list;

	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init(ret);

	if (list_left) {

		list = Z_ARRVAL_P(list_left);
		if (zend_hash_index_exists(list, 0)) {
			{
				HashPosition pos;
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
			}
		} else {
			add_next_index_zval(ret, list_left);
		}
	}

	add_next_index_zval(ret, right_list);

	return ret;
}

static zval *phvolt_ret_named_item(phvolt_parser_token *name, zval *expr, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init(ret);
	add_assoc_zval(ret, "expr", expr);
	if (name != NULL) {
		phvolt_add_assoc_stringl(ret, "name", name->token, name->token_len, 0);
		//efree(name->token);
		efree(name);
	}

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_expr(int type, zval *left, zval *right, zval *ternary, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

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

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_slice(zval *left, zval *start, zval *end, phvolt_scanner_state *state)
{
	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_SLICE);
	add_assoc_zval(ret, "left", left);

	if (start != NULL) {
		add_assoc_zval(ret, "start", start);
	}

	if (end != NULL) {
		add_assoc_zval(ret, "end", end);
	}

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_func_call(zval *expr, zval *arguments, phvolt_scanner_state *state)
{

	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_FCALL);
	add_assoc_zval(ret, "name", expr);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_macro_call_statement(zval *expr, zval *arguments, zval *caller, phvolt_scanner_state *state)
{

	PHVOLT_DEFINE_INIT_ZVAL(ret);

	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_CALL);
	add_assoc_zval(ret, "name", expr);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	if (caller) {
		add_assoc_zval(ret, "caller", caller);
	}

	PHVOLT_ADDREF_P(state->active_file);

	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}
