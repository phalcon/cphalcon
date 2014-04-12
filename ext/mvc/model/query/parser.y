
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

%token_prefix PHQL_
%token_type {phql_parser_token*}
%default_type {zval*}
%extra_argument {phql_parser_status *status}
%name phql_

%right AGAINST .
%left BETWEEN .
%left EQUALS NOTEQUALS LESS GREATER GREATEREQUAL LESSEQUAL .
%left AND OR .
%left LIKE ILIKE .
%left BITWISE_AND BITWISE_OR BITWISE_XOR .
%left DIVIDE TIMES MOD .
%left PLUS MINUS .
%left IS .
%right IN .
%right NOT BITWISE_NOT .
%left COMMA .

%include {

#include "php_phalcon.h"

#include "mvc/model/query/parser.h"
#include "mvc/model/query/scanner.h"
#include "mvc/model/query/phql.h"
#include "mvc/model/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

#include "interned-strings.h"

static zval *phql_ret_literal_zval(int type, phql_parser_token *T)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, phalcon_interned_type, type);
	if (T) {
		add_assoc_stringl(ret, phalcon_interned_value, T->token, T->token_len, 0);
		efree(T);
	}

	return ret;
}

static zval *phql_ret_placeholder_zval(int type, phql_parser_token *T)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, phalcon_interned_type, type);
	add_assoc_stringl(ret, phalcon_interned_value, T->token, T->token_len, 0);
	efree(T);

	return ret;
}

static zval *phql_ret_qualified_name(phql_parser_token *A, phql_parser_token *B, phql_parser_token *C)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, phalcon_interned_type, PHQL_T_QUALIFIED);

	if (A != NULL) {
		add_assoc_stringl(ret, phalcon_interned_ns_alias, A->token, A->token_len, 0);
		efree(A);
	}

	if (B != NULL) {
		add_assoc_stringl(ret, phalcon_interned_domain, B->token, B->token_len, 0);
		efree(B);
	}

	add_assoc_stringl(ret, phalcon_interned_name, C->token, C->token_len, 0);
	efree(C);

	return ret;
}

static zval *phql_ret_raw_qualified_name(phql_parser_token *A, phql_parser_token *B)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, phalcon_interned_type, PHQL_T_RAW_QUALIFIED);
	if (B != NULL) {
		add_assoc_stringl(ret, phalcon_interned_domain, A->token, A->token_len, 0);
		add_assoc_stringl(ret, phalcon_interned_name, B->token, B->token_len, 0);
		efree(B);
	} else {
		add_assoc_stringl(ret, phalcon_interned_name, A->token, A->token_len, 0);
	}
	efree(A);

	return ret;
}

static zval *phql_ret_select_statement(zval *S, zval *W, zval *O, zval *G, zval *H, zval *L)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, phalcon_interned_type, PHQL_T_SELECT);
	add_assoc_zval(ret, phalcon_interned_select, S);

	if (W != NULL) {
		add_assoc_zval(ret, phalcon_interned_where, W);
	}
	if (O != NULL) {
		add_assoc_zval(ret, phalcon_interned_orderBy, O);
	}
	if (G != NULL) {
		add_assoc_zval(ret, phalcon_interned_groupBy, G);
	}
	if (H != NULL) {
		add_assoc_zval(ret, phalcon_interned_having, H);
	}
	if (L != NULL) {
		add_assoc_zval(ret, phalcon_interned_limit, L);
	}

	return ret;
}

static zval *phql_ret_select_clause(zval *distinct, zval *columns, zval *tables, zval *join_list)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	if (distinct) {
		add_assoc_zval(ret, phalcon_interned_distinct, distinct);
	}

	add_assoc_zval(ret, phalcon_interned_columns, columns);
	add_assoc_zval(ret, phalcon_interned_tables, tables);
	if (join_list) {
		add_assoc_zval(ret, phalcon_interned_joins, join_list);
	}

	return ret;
}

static zval *phql_ret_distinct_all(int distinct)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	ZVAL_LONG(ret, distinct);

	return ret;
}

static zval *phql_ret_distinct(void)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	ZVAL_TRUE(ret);

	return ret;
}

static zval *phql_ret_order_item(zval *column, int sort){

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_zval(ret, phalcon_interned_column, column);
	if (sort != 0 ) {
		add_assoc_long(ret, phalcon_interned_sort, sort);
	}

	return ret;
}

static zval *phql_ret_limit_clause(zval *L, zval *O)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);

	add_assoc_zval(ret, phalcon_interned_number, L);

	if (O != NULL) {
		add_assoc_zval(ret, phalcon_interned_offset, O);
	}

	return ret;
}

static zval *phql_ret_insert_statement(zval *Q, zval *F, zval *V)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	add_assoc_long(ret, phalcon_interned_type, PHQL_T_INSERT);
	add_assoc_zval(ret, phalcon_interned_qualifiedName, Q);
	if (F != NULL) {
		add_assoc_zval(ret, phalcon_interned_fields, F);
	}
	add_assoc_zval(ret, phalcon_interned_values, V);

	return ret;
}

static zval *phql_ret_update_statement(zval *U, zval *W, zval *L)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, phalcon_interned_type, PHQL_T_UPDATE);
	add_assoc_zval(ret, phalcon_interned_update, U);
	if (W != NULL) {
		add_assoc_zval(ret, phalcon_interned_where, W);
	}
	if (L != NULL) {
		add_assoc_zval(ret, phalcon_interned_limit, L);
	}

	return ret;
}

static zval *phql_ret_update_clause(zval *tables, zval *values)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_zval(ret, phalcon_interned_tables, tables);
	add_assoc_zval(ret, phalcon_interned_values, values);

	return ret;
}

static zval *phql_ret_update_item(zval *column, zval *expr)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_zval(ret, phalcon_interned_column, column);
	add_assoc_zval(ret, phalcon_interned_expr, expr);

	return ret;
}

static zval *phql_ret_delete_statement(zval *D, zval *W, zval *L)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, phalcon_interned_type, PHQL_T_DELETE);
	add_assoc_zval(ret, phalcon_interned_delete, D);
	if (W != NULL) {
		add_assoc_zval(ret, phalcon_interned_where, W);
	}
	if (L != NULL) {
		add_assoc_zval(ret, phalcon_interned_limit, L);
	}

	return ret;
}

static zval *phql_ret_delete_clause(zval *tables)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 1);
	add_assoc_zval(ret, phalcon_interned_tables, tables);

	return ret;
}

static zval *phql_ret_zval_list(zval *list_left, zval *right_list)
{
	zval *ret;
	HashTable *list;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	list = Z_ARRVAL_P(list_left);
	if (zend_hash_index_exists(list, 0)) {
		HashPosition pos;
		zval **item;

		for (
			zend_hash_internal_pointer_reset_ex(list, &pos);
			zend_hash_get_current_data_ex(list, (void**)&item, &pos) != FAILURE;
			zend_hash_move_forward_ex(list, &pos)
		) {
			Z_ADDREF_PP(item);
			add_next_index_zval(ret, *item);
		}

		zval_ptr_dtor(&list_left);
	} else {
		add_next_index_zval(ret, list_left);
	}

	if (right_list) {
		add_next_index_zval(ret, right_list);
	}

	return ret;
}

static zval *phql_ret_column_item(int type, zval *column, phql_parser_token *identifier_column, phql_parser_token *alias)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);
	add_assoc_long(ret, phalcon_interned_type, type);
	if (column) {
		add_assoc_zval(ret, phalcon_interned_column, column);
	}
	if (identifier_column) {
		add_assoc_stringl(ret, phalcon_interned_column, identifier_column->token, identifier_column->token_len, 0);
		efree(identifier_column);
	}
	if (alias) {
		add_assoc_stringl(ret, phalcon_interned_alias, alias->token, alias->token_len, 0);
		efree(alias);
	}

	return ret;
}

static zval *phql_ret_assoc_name(zval *qualified_name, phql_parser_token *alias)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_zval(ret, phalcon_interned_qualifiedName, qualified_name);
	if (alias) {
		add_assoc_stringl(ret, phalcon_interned_alias, alias->token, alias->token_len, 0);
		efree(alias);
	}

	return ret;
}

static zval *phql_ret_join_type(int type)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	ZVAL_LONG(ret, type);

	return ret;
}

static zval *phql_ret_join_item(zval *type, zval *qualified, zval *alias, zval *conditions)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);
	add_assoc_zval(ret, phalcon_interned_type, type);

	if (qualified) {
		add_assoc_zval(ret, phalcon_interned_qualified, qualified);
	}

	if (alias) {
		add_assoc_zval(ret, phalcon_interned_alias, alias);
	}

	if (conditions) {
		add_assoc_zval(ret, phalcon_interned_conditions, conditions);
	}

	return ret;
}

static zval *phql_ret_expr(int type, zval *left, zval *right)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, phalcon_interned_type, type);
	if (left) {
		add_assoc_zval(ret, phalcon_interned_left, left);
	}
	if (right) {
		add_assoc_zval(ret, phalcon_interned_right, right);
	}

	return ret;
}

static zval *phql_ret_func_call(phql_parser_token *name, zval *arguments, zval *distinct)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);
	add_assoc_long(ret, phalcon_interned_type, PHQL_T_FCALL);
	add_assoc_stringl(ret, phalcon_interned_name, name->token, name->token_len, 0);
	efree(name);

	if (arguments) {
		add_assoc_zval(ret, phalcon_interned_arguments, arguments);
	}
	
	if (distinct) {
		add_assoc_zval(ret, phalcon_interned_distinct, distinct);
	}

	return ret;
}

}

%syntax_error {
	if (status->scanner_state->start_length) {
		{

			char *token_name = NULL;
			int token_found = 0;
			unsigned int token_length;
			const phql_token_names *tokens = phql_tokens;
			uint active_token = status->scanner_state->active_token;
			uint near_length = status->scanner_state->start_length;

			if (active_token) {

				do {
					if (tokens->code == active_token) {
						token_name = tokens->name;
						token_length = tokens->length;
						token_found = 1;
						break;
					}
					++tokens;
				} while (tokens[0].code != 0);

			}

			if (!token_name) {
				token_length = strlen("UNKNOWN");
				token_name = estrndup("UNKNOWN", token_length);
				token_found = 0;
			}

			status->syntax_error_len = 96 + status->token->len + token_length + near_length + status->phql_length;;
			status->syntax_error = emalloc(sizeof(char) * status->syntax_error_len);

			if (near_length > 0) {
				if (status->token->value) {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s(%s), near to '%s', when parsing: %s (%d)", token_name, status->token->value, status->scanner_state->start, status->phql, status->phql_length);
				} else {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s, near to '%s', when parsing: %s (%d)", token_name, status->scanner_state->start, status->phql, status->phql_length);
				}
			} else {
				if (active_token != PHQL_T_IGNORE) {
					if (status->token->value) {
						snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s(%s), at the end of query, when parsing: %s (%d)", token_name, status->token->value, status->phql, status->phql_length);
					} else {
						snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s, at the end of query, when parsing: %s (%d)", token_name, status->phql, status->phql_length);
					}
				} else {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected EOF, at the end of query");
				}
				status->syntax_error[status->syntax_error_len - 1] = '\0';
			}

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

	status->status = PHQL_PARSING_FAILED;
}

%token_destructor {
	if ($$) {
		if ($$->free_flag) {
			efree($$->token);
		}
		efree($$);
	}
}

program ::= query_language(Q) . {
	status->ret = Q;
}

%destructor query_language { zval_ptr_dtor(&$$); }

query_language(R) ::= select_statement(S) . {
	R = S;
}

query_language(R) ::= insert_statement(I) . {
	R = I;
}

query_language(R) ::= update_statement(U) . {
	R = U;
}

query_language(R) ::= delete_statement(D) . {
	R = D;
}

%destructor select_statement { zval_ptr_dtor(&$$); }

select_statement(R) ::= select_clause(S) where_clause(W) group_clause(G) having_clause(H) order_clause(O) select_limit_clause(L) . {
	R = phql_ret_select_statement(S, W, O, G, H, L);
}

%destructor select_clause { zval_ptr_dtor(&$$); }

select_clause(R) ::= SELECT distinct_all(D) column_list(C) FROM associated_name_list(A) join_list_or_null(J) . {
	R = phql_ret_select_clause(D, C, A, J);
}

%destructor distinct_all { phalcon_safe_zval_ptr_dtor($$); }

distinct_all(R) ::= DISTINCT . {
	R = phql_ret_distinct_all(1);
}

distinct_all(R) ::= ALL . {
	R = phql_ret_distinct_all(0);
}

distinct_all(R) ::= . {
	R = NULL;
}

%destructor column_list { zval_ptr_dtor(&$$); }

column_list(R) ::= column_list(L) COMMA column_item(C) . {
	R = phql_ret_zval_list(L, C);
}

column_list(R) ::= column_item(I) . {
	R = phql_ret_zval_list(I, NULL);
}

%destructor column_item { zval_ptr_dtor(&$$); }

column_item(R) ::= TIMES . {
	R = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
}

column_item(R) ::= IDENTIFIER(I) DOT TIMES . {
	R = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, I, NULL);
}

column_item(R) ::= expr(E) AS IDENTIFIER(I) . {
	R = phql_ret_column_item(PHQL_T_EXPR, E, NULL, I);
}

column_item(R) ::= expr(E) IDENTIFIER(I) . {
	R = phql_ret_column_item(PHQL_T_EXPR, E, NULL, I);
}

column_item(R) ::= expr(E) . {
	R = phql_ret_column_item(PHQL_T_EXPR, E, NULL, NULL);
}

%destructor associated_name_list { zval_ptr_dtor(&$$); }

associated_name_list(R) ::= associated_name_list(L) COMMA associated_name(A) . {
	R = phql_ret_zval_list(L, A);
}

associated_name_list(R) ::= associated_name(L) . {
	R = L;
}

join_list_or_null(R) ::= join_list(L) . {
	R = L;
}

join_list_or_null(R) ::= . {
	R = NULL;
}

%destructor join_list { zval_ptr_dtor(&$$); }

join_list(R) ::= join_list(L) join_item(I) . {
	R = phql_ret_zval_list(L, I);
}

join_list(R) ::= join_item(I) . {
	R = I;
}

%destructor join_item { zval_ptr_dtor(&$$); }

join_item(R) ::= join_clause(C) . {
	R = C;
}

%destructor join_clause { zval_ptr_dtor(&$$); }

/** Join + conditions + alias */
join_clause(R) ::= join_type(T) aliased_or_qualified_name(Q) join_associated_name(A) join_conditions(C) . {
	R = phql_ret_join_item(T, Q, A, C);
}

%destructor join_associated_name { phalcon_safe_zval_ptr_dtor($$); }

join_associated_name(R) ::= AS IDENTIFIER(I) . {
	R = phql_ret_qualified_name(NULL, NULL, I);
}

join_associated_name(R) ::= IDENTIFIER(I) . {
	R = phql_ret_qualified_name(NULL, NULL, I);
}

join_associated_name(R) ::= . {
	R = NULL;
}

%destructor join_type { zval_ptr_dtor(&$$); }

join_type(R) ::= INNER JOIN . {
	R = phql_ret_join_type(PHQL_T_INNERJOIN);
}

join_type(R) ::= CROSS JOIN . {
	R = phql_ret_join_type(PHQL_T_CROSSJOIN);
}

join_type(R) ::= LEFT OUTER JOIN . {
	R = phql_ret_join_type(PHQL_T_LEFTJOIN);
}

join_type(R) ::= LEFT JOIN . {
	R = phql_ret_join_type(PHQL_T_LEFTJOIN);
}

join_type(R) ::= RIGHT OUTER JOIN . {
	R = phql_ret_join_type(PHQL_T_RIGHTJOIN);
}

join_type(R) ::= RIGHT JOIN . {
	R = phql_ret_join_type(PHQL_T_RIGHTJOIN);
}

join_type(R) ::= FULL OUTER JOIN . {
	R = phql_ret_join_type(PHQL_T_FULLJOIN);
}

join_type(R) ::= FULL JOIN . {
	R = phql_ret_join_type(PHQL_T_FULLJOIN);
}

join_type(R) ::= JOIN . {
	R = phql_ret_join_type(PHQL_T_INNERJOIN);
}

%destructor join_conditions { phalcon_safe_zval_ptr_dtor($$); }

join_conditions(R) ::= ON expr(E) . {
	R = E;
}

join_conditions(R) ::= . {
	R = NULL;
}

%destructor insert_statement { zval_ptr_dtor(&$$); }

/* Insert */
insert_statement(R) ::= INSERT INTO aliased_or_qualified_name(Q) VALUES PARENTHESES_OPEN values_list(V) PARENTHESES_CLOSE . {
	R = phql_ret_insert_statement(Q, NULL, V);
}

insert_statement(R) ::= INSERT INTO aliased_or_qualified_name(Q) PARENTHESES_OPEN field_list(F) PARENTHESES_CLOSE VALUES PARENTHESES_OPEN values_list(V) PARENTHESES_CLOSE . {
	R = phql_ret_insert_statement(Q, F, V);
}

%destructor value_list { zval_ptr_dtor(&$$); }

values_list(R) ::= values_list(L) COMMA value_item(I) . {
	R = phql_ret_zval_list(L, I);
}

values_list(R) ::= value_item(I) . {
	R = phql_ret_zval_list(I, NULL);
}

value_item(R) ::= expr(E) . {
	R = E;
}

%destructor field_list { zval_ptr_dtor(&$$); }

field_list(R) ::= field_list(L) COMMA field_item(I) . {
	R = phql_ret_zval_list(L, I);
}

field_list(R) ::= field_item(I) . {
	R = phql_ret_zval_list(I, NULL);
}

%destructor field_item { zval_ptr_dtor(&$$); }

field_item(R) ::= IDENTIFIER(I) . {
	R = phql_ret_qualified_name(NULL, NULL, I);
}

/* Update */

%destructor update_statement { zval_ptr_dtor(&$$); }

update_statement(R) ::= update_clause(U) where_clause(W) limit_clause(L) . {
	R = phql_ret_update_statement(U, W, L);
}

%destructor update_clause { zval_ptr_dtor(&$$); }

update_clause(R) ::= UPDATE associated_name(A) SET update_item_list(U) . {
	R = phql_ret_update_clause(A, U);
}

%destructor update_item_list { zval_ptr_dtor(&$$); }

update_item_list(R) ::= update_item_list(L) COMMA update_item(I) . {
	R = phql_ret_zval_list(L, I);
}

update_item_list(R) ::= update_item(I) . {
	R = I;
}

%destructor update_item { zval_ptr_dtor(&$$); }

update_item(R) ::= qualified_name(Q) EQUALS new_value(N) . {
	R = phql_ret_update_item(Q, N);
}

new_value(R) ::= expr(E) . {
	R = E;
}

/* Delete */

%destructor delete_statement { zval_ptr_dtor(&$$); }

delete_statement(R) ::= delete_clause(D) where_clause(W) limit_clause(L) . {
	R = phql_ret_delete_statement(D, W, L);
}

%destructor delete_clause { zval_ptr_dtor(&$$); }

delete_clause(R) ::= DELETE FROM associated_name(A) . {
	R = phql_ret_delete_clause(A);
}

%destructor associated_name { zval_ptr_dtor(&$$); }

associated_name(R) ::= aliased_or_qualified_name(Q) AS IDENTIFIER(I) . {
	R = phql_ret_assoc_name(Q, I);
}

associated_name(R) ::= aliased_or_qualified_name(Q) IDENTIFIER(I) . {
	R = phql_ret_assoc_name(Q, I);
}

associated_name(R) ::= aliased_or_qualified_name(Q) . {
	R = phql_ret_assoc_name(Q, NULL);
}

%destructor aliased_or_qualified_name { zval_ptr_dtor(&$$); }

aliased_or_qualified_name(R) ::= qualified_name(Q) . {
	R = Q;
}

%destructor where_clause { phalcon_safe_zval_ptr_dtor($$); }

where_clause(R) ::= WHERE expr(E) . {
	R = E;
}

where_clause(R) ::= . {
	R = NULL;
}

%destructor order_clause { phalcon_safe_zval_ptr_dtor($$); } 

order_clause(R) ::= ORDER BY order_list(O) . {
	R = O;
}

order_clause(R) ::= . {
	R = NULL;
}

%destructor order_list { zval_ptr_dtor(&$$); }

order_list(R) ::= order_list(L) COMMA order_item(I) . {
	R = phql_ret_zval_list(L, I);
}

order_list(R) ::= order_item(I) . {
	R = I;
}

%destructor order_item { zval_ptr_dtor(&$$); }

order_item(R) ::= expr(O) . {
	R = phql_ret_order_item(O, 0);
}

order_item(R) ::= expr(O) ASC . {
	R = phql_ret_order_item(O, PHQL_T_ASC);
}

order_item(R) ::= expr(O) DESC . {
	R = phql_ret_order_item(O, PHQL_T_DESC);
}

%destructor group_clause { phalcon_safe_zval_ptr_dtor($$); }

group_clause(R) ::= GROUP BY group_list(G) . {
	R = G;
}

group_clause(R) ::= . {
	R = NULL;
}

%destructor group_list { zval_ptr_dtor(&$$); }

group_list(R) ::= group_list(L) COMMA group_item(I) . {
	R = phql_ret_zval_list(L, I);
}

group_list(R) ::= group_item(I) . {
	R = I;
}

%destructor group_item { zval_ptr_dtor(&$$); }

group_item(R) ::= expr(E) . {
	R = E;
}

%destructor having_clause { phalcon_safe_zval_ptr_dtor($$); }

having_clause(R) ::= HAVING expr(E) . {
	R = E;
}

having_clause(R) ::= . {
	R = NULL;
}

%destructor select_limit_clause { phalcon_safe_zval_ptr_dtor($$); }

select_limit_clause(R) ::= LIMIT integer_or_placeholder(I) . {
	R = phql_ret_limit_clause(I, NULL);
}

select_limit_clause(R) ::= LIMIT integer_or_placeholder(O) COMMA integer_or_placeholder(I). {
	R = phql_ret_limit_clause(I, O);
}

select_limit_clause(R) ::= LIMIT integer_or_placeholder(I) OFFSET integer_or_placeholder(O). {
	R = phql_ret_limit_clause(I, O);
}

select_limit_clause(R) ::= . {
	R = NULL;
}

%destructor limit_clause { phalcon_safe_zval_ptr_dtor($$); }

limit_clause(R) ::= LIMIT integer_or_placeholder(I) . {
	R = phql_ret_limit_clause(I, NULL);
}

limit_clause(R) ::= . {
	R = NULL;
}

integer_or_placeholder(R) ::= INTEGER(I) . {
	R = phql_ret_literal_zval(PHQL_T_INTEGER, I);
}

integer_or_placeholder(R) ::= NPLACEHOLDER(P) . {
	R = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, P);
}

integer_or_placeholder(R) ::= SPLACEHOLDER(P) . {
	R = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, P);
}

%destructor expr { zval_ptr_dtor(&$$); }

expr(R) ::= MINUS expr(E) . {
	R = phql_ret_expr(PHQL_T_MINUS, NULL, E);
}

expr(R) ::= expr(O1) MINUS expr(O2) . {
	R = phql_ret_expr(PHQL_T_SUB, O1, O2);
}

expr(R) ::= expr(O1) PLUS expr(O2) . {
	R = phql_ret_expr(PHQL_T_ADD, O1, O2);
}

expr(R) ::= expr(O1) TIMES expr(O2) . {
	R = phql_ret_expr(PHQL_T_MUL, O1, O2);
}

expr(R) ::= expr(O1) DIVIDE expr(O2) . {
	R = phql_ret_expr(PHQL_T_DIV, O1, O2);
}

expr(R) ::= expr(O1) MOD expr(O2) . {
	R = phql_ret_expr(PHQL_T_MOD, O1, O2);
}

expr(R) ::= expr(O1) AND expr(O2) . {
	R = phql_ret_expr(PHQL_T_AND, O1, O2);
}

expr(R) ::= expr(O1) OR expr(O2) . {
	R = phql_ret_expr(PHQL_T_OR, O1, O2);
}

expr(R) ::= expr(O1) BITWISE_AND expr(O2) . {
	R = phql_ret_expr(PHQL_T_BITWISE_AND, O1, O2);
}

expr(R) ::= expr(O1) BITWISE_OR expr(O2) . {
	R = phql_ret_expr(PHQL_T_BITWISE_OR, O1, O2);
}

expr(R) ::= expr(O1) BITWISE_XOR expr(O2) . {
	R = phql_ret_expr(PHQL_T_BITWISE_XOR, O1, O2);
}

expr(R) ::= expr(O1) EQUALS expr(O2) . {
	R = phql_ret_expr(PHQL_T_EQUALS, O1, O2);
}

expr(R) ::= expr(O1) NOTEQUALS expr(O2) . {
	R = phql_ret_expr(PHQL_T_NOTEQUALS, O1, O2);
}

expr(R) ::= expr(O1) LESS expr(O2) . {
	R = phql_ret_expr(PHQL_T_LESS, O1, O2);
}

expr(R) ::= expr(O1) GREATER expr(O2) . {
	R = phql_ret_expr(PHQL_T_GREATER, O1, O2);
}

expr(R) ::= expr(O1) GREATEREQUAL expr(O2) . {
	R = phql_ret_expr(PHQL_T_GREATEREQUAL, O1, O2);
}

expr(R) ::= expr(O1) LESSEQUAL expr(O2) . {
	R = phql_ret_expr(PHQL_T_LESSEQUAL, O1, O2);
}

expr(R) ::= expr(O1) LIKE expr(O2) . {
	R = phql_ret_expr(PHQL_T_LIKE, O1, O2);
}

expr(R) ::= expr(O1) NOT LIKE expr(O2) . {
	R = phql_ret_expr(PHQL_T_NLIKE, O1, O2);
}

expr(R) ::= expr(O1) ILIKE expr(O2) . {
	R = phql_ret_expr(PHQL_T_ILIKE, O1, O2);
}

expr(R) ::= expr(O1) NOT ILIKE expr(O2) . {
	R = phql_ret_expr(PHQL_T_NILIKE, O1, O2);
}

expr(R) ::= expr(E) IN PARENTHESES_OPEN argument_list(L) PARENTHESES_CLOSE . {
	R = phql_ret_expr(PHQL_T_IN, E, L);
}

expr(R) ::= expr(E) NOT IN PARENTHESES_OPEN argument_list(L) PARENTHESES_CLOSE . {
	R = phql_ret_expr(PHQL_T_NOTIN, E, L);
}

expr(R) ::= expr(O1) AGAINST expr(O2) . {
	R = phql_ret_expr(PHQL_T_AGAINST, O1, O2);
}

expr(R) ::= CAST PARENTHESES_OPEN expr(E) AS IDENTIFIER(I) PARENTHESES_CLOSE . {
	R = phql_ret_expr(PHQL_T_CAST, E, phql_ret_raw_qualified_name(I, NULL));
}

expr(R) ::= CONVERT PARENTHESES_OPEN expr(E) USING IDENTIFIER(I) PARENTHESES_CLOSE . {
	R = phql_ret_expr(PHQL_T_CONVERT, E, phql_ret_raw_qualified_name(I, NULL));
}

%destructor function_call { zval_ptr_dtor(&$$); }

expr(R) ::= function_call(F) . {
	R = F;
}

function_call(R) ::= IDENTIFIER(I) PARENTHESES_OPEN distinct_or_null(D) argument_list_or_null(L) PARENTHESES_CLOSE . {
	R = phql_ret_func_call(I, L, D);
}

%destructor distinct_or_null { phalcon_safe_zval_ptr_dtor($$); }

distinct_or_null(R) ::= DISTINCT . {
	R = phql_ret_distinct();
}

distinct_or_null(R) ::=  . {
	R = NULL;
}

%destructor argument_list_or_null { phalcon_safe_zval_ptr_dtor($$); }

argument_list_or_null(R) ::= argument_list(L) . {
	R = L;
}

argument_list_or_null(R) ::= . {
	R = NULL;
}

%destructor argument_list { zval_ptr_dtor(&$$); }

argument_list(R) ::= argument_list(L) COMMA argument_item(I) . {
	R = phql_ret_zval_list(L, I);
}

argument_list(R) ::= argument_item(I) . {
	R = phql_ret_zval_list(I, NULL);
}

%destructor argument_item { zval_ptr_dtor(&$$); }

argument_item(R) ::= TIMES . {
	R = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
}

argument_item(R) ::= expr(E) . {
	R = E;
}

expr(R) ::= expr(E) IS NULL . {
	R = phql_ret_expr(PHQL_T_ISNULL, E, NULL);
}

expr(R) ::= expr(E) IS NOT NULL . {
	R = phql_ret_expr(PHQL_T_ISNOTNULL, E, NULL);
}

expr(R) ::= expr(E) BETWEEN expr(L) . {
	R = phql_ret_expr(PHQL_T_BETWEEN, E, L);
}

expr(R) ::= NOT expr(E) . {
	R = phql_ret_expr(PHQL_T_NOT, NULL, E);
}

expr(R) ::= BITWISE_NOT expr(E) . {
	R = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, E);
}

expr(R) ::= PARENTHESES_OPEN expr(E) PARENTHESES_CLOSE . {
	R = phql_ret_expr(PHQL_T_ENCLOSED, E, NULL);
}

expr(R) ::= qualified_name(Q) . {
	R = Q;
}

expr(R) ::= INTEGER(I) . {
	R = phql_ret_literal_zval(PHQL_T_INTEGER, I);
}

expr(R) ::= STRING(S) . {
	R = phql_ret_literal_zval(PHQL_T_STRING, S);
}

expr(R) ::= DOUBLE(D) . {
	R = phql_ret_literal_zval(PHQL_T_DOUBLE, D);
}

expr(R) ::= NULL . {
	R = phql_ret_literal_zval(PHQL_T_NULL, NULL);
}

expr(R) ::= TRUE . {
	R = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
}

expr(R) ::= FALSE . {
	R = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
}

expr(R) ::= NPLACEHOLDER(P) . {
	R = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, P);
}

expr(R) ::= SPLACEHOLDER(P) . {
	R = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, P);
}

%destructor qualified_name { zval_ptr_dtor(&$$); }

qualified_name(R) ::= IDENTIFIER(A) COLON IDENTIFIER(B) DOT IDENTIFIER(C) . {
	R = phql_ret_qualified_name(A, B, C);
}

qualified_name(R) ::= IDENTIFIER(A) COLON IDENTIFIER(B) . {
	R = phql_ret_qualified_name(A, NULL, B);
}

qualified_name(R) ::= IDENTIFIER(A) DOT IDENTIFIER(B) . {
	R = phql_ret_qualified_name(NULL, A, B);
}

qualified_name(R) ::= IDENTIFIER(A) . {
	R = phql_ret_qualified_name(NULL, NULL, A);
}
