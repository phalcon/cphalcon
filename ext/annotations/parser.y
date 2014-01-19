
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

%token_prefix PHANNOT_
%token_type {phannot_parser_token*}
%default_type {zval*}
%extra_argument {phannot_parser_status *status}
%name phannot_

%left COMMA .

%include {

#include "php_phalcon.h"

#include <ext/standard/php_smart_str.h>

#include "annotations/parser.h"
#include "annotations/scanner.h"
#include "annotations/annot.h"
#include "annotations/exception.h"

#include "kernel/main.h"
#include "kernel/exception.h"

#include "interned-strings.h"

static zval *phannot_ret_literal_zval(int type, phannot_parser_token *T)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, phalcon_interned_type, type);
	if (T) {
		add_assoc_stringl(ret, phalcon_interned_value, T->token, T->token_len, 0);
		efree(T);
	}

	return ret;
}

static zval *phannot_ret_array(zval *items)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, phalcon_interned_type, PHANNOT_T_ARRAY);

	if (items) {
		add_assoc_zval(ret, phalcon_interned_items, items);
	}

	return ret;
}

static zval *phannot_ret_zval_list(zval *list_left, zval *right_list)
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

static zval *phannot_ret_named_item(phannot_parser_token *name, zval *expr)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_zval(ret, phalcon_interned_expr, expr);
	if (name != NULL) {
		add_assoc_stringl(ret, phalcon_interned_name, name->token, name->token_len, 0);
		efree(name);
	}

	return ret;
}

static zval *phannot_ret_annotation(phannot_parser_token *name, zval *arguments, phannot_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 5);

	add_assoc_long(ret, phalcon_interned_type, PHANNOT_T_ANNOTATION);

	if (name) {
		add_assoc_stringl(ret, phalcon_interned_name, name->token, name->token_len, 0);
		efree(name);
	}

	if (arguments) {
		add_assoc_zval(ret, phalcon_interned_arguments, arguments);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, phalcon_interned_file, state->active_file);
	add_assoc_long(ret, phalcon_interned_line, state->active_line);

	return ret;
}

}

%syntax_error {
	if (status->scanner_state->start_length) {
		{

			char *token_name = NULL;
			const phannot_token_names *tokens = phannot_tokens;
			int token_found = 0;
			uint active_token = status->scanner_state->active_token;
			uint near_length = status->scanner_state->start_length;

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

			status->syntax_error_len = 128 + strlen(token_name) + Z_STRLEN_P(status->scanner_state->active_file);
			status->syntax_error = emalloc(sizeof(char) * status->syntax_error_len);

			if (near_length > 0) {
				if (status->token->value) {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s(%s), near to '%s' in %s on line %d", token_name, status->token->value, status->scanner_state->start, Z_STRVAL_P(status->scanner_state->active_file), status->scanner_state->active_line);
				} else {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s, near to '%s' in %s on line %d", token_name, status->scanner_state->start, Z_STRVAL_P(status->scanner_state->active_file), status->scanner_state->active_line);
				}
			} else {
				if (active_token != PHANNOT_T_IGNORE) {
					if (status->token->value) {
						snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s(%s), at the end of docblock in %s on line %d", token_name, status->token->value, Z_STRVAL_P(status->scanner_state->active_file), status->scanner_state->active_line);
					} else {
						snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s, at the end of docblock in %s on line %d", token_name, Z_STRVAL_P(status->scanner_state->active_file), status->scanner_state->active_line);
					}
				} else {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected EOF, at the end of docblock in %s on line %d", Z_STRVAL_P(status->scanner_state->active_file), status->scanner_state->active_line);
				}
				status->syntax_error[status->syntax_error_len-1] = '\0';
			}

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

	status->status = PHANNOT_PARSING_FAILED;
}

%token_destructor {
	if ($$) {
		if ($$->free_flag) {
			efree($$->token);
		}
		efree($$);
	}
}

program ::= annotation_language(Q) . {
	status->ret = Q;
}

%destructor annotation_language { zval_ptr_dtor(&$$); }

annotation_language(R) ::= annotation_list(L) . {
	R = L;
}

%destructor annotation_list { zval_ptr_dtor(&$$); }

annotation_list(R) ::= annotation_list(L) annotation(S) . {
	R = phannot_ret_zval_list(L, S);
}

annotation_list(R) ::= annotation(S) . {
	R = phannot_ret_zval_list(NULL, S);
}


%destructor annotation { zval_ptr_dtor(&$$); }

annotation(R) ::= AT IDENTIFIER(I) PARENTHESES_OPEN argument_list(L) PARENTHESES_CLOSE . {
	R = phannot_ret_annotation(I, L, status->scanner_state);
}

annotation(R) ::= AT IDENTIFIER(I) PARENTHESES_OPEN PARENTHESES_CLOSE . {
	R = phannot_ret_annotation(I, NULL, status->scanner_state);
}

annotation(R) ::= AT IDENTIFIER(I) . {
	R = phannot_ret_annotation(I, NULL, status->scanner_state);
}

%destructor argument_list { zval_ptr_dtor(&$$); }

argument_list(R) ::= argument_list(L) COMMA argument_item(I) . {
	R = phannot_ret_zval_list(L, I);
}

argument_list(R) ::= argument_item(I) . {
	R = phannot_ret_zval_list(NULL, I);
}

%destructor argument_item { zval_ptr_dtor(&$$); }

argument_item(R) ::= expr(E) . {
	R = phannot_ret_named_item(NULL, E);
}

argument_item(R) ::= STRING(S) EQUALS expr(E) . {
	R = phannot_ret_named_item(S, E);
}

argument_item(R) ::= STRING(S) COLON expr(E) . {
	R = phannot_ret_named_item(S, E);
}

argument_item(R) ::= IDENTIFIER(I) EQUALS expr(E) . {
	R = phannot_ret_named_item(I, E);
}

argument_item(R) ::= IDENTIFIER(I) COLON expr(E) . {
	R = phannot_ret_named_item(I, E);
}

%destructor expr { zval_ptr_dtor(&$$); }

expr(R) ::= annotation(S) . {
	R = S;
}

expr(R) ::= array(A) . {
	R = A;
}

expr(R) ::= IDENTIFIER(I) . {
	R = phannot_ret_literal_zval(PHANNOT_T_IDENTIFIER, I);
}

expr(R) ::= INTEGER(I) . {
	R = phannot_ret_literal_zval(PHANNOT_T_INTEGER, I);
}

expr(R) ::= STRING(S) . {
	R = phannot_ret_literal_zval(PHANNOT_T_STRING, S);
}

expr(R) ::= DOUBLE(D) . {
	R = phannot_ret_literal_zval(PHANNOT_T_DOUBLE, D);
}

expr(R) ::= NULL . {
	R = phannot_ret_literal_zval(PHANNOT_T_NULL, NULL);
}

expr(R) ::= FALSE . {
	R = phannot_ret_literal_zval(PHANNOT_T_FALSE, NULL);
}

expr(R) ::= TRUE . {
	R = phannot_ret_literal_zval(PHANNOT_T_TRUE, NULL);
}

array(R) ::= BRACKET_OPEN argument_list(A) BRACKET_CLOSE . {
	R = phannot_ret_array(A);
}

array(R) ::= SBRACKET_OPEN argument_list(A) SBRACKET_CLOSE . {
	R = phannot_ret_array(A);
}
