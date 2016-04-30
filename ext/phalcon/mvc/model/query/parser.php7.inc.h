
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "parser.php7.h"
#include "scanner.h"
#include "phql.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

#define phql_add_assoc_stringl(var, index, str, len, copy) add_assoc_stringl(var, index, str, len);

static void phql_ret_literal_zval(zval *ret, int type, phql_parser_token *T)
{
	array_init(ret);
	add_assoc_long(ret, "type", type);
	if (T) {
		phql_add_assoc_stringl(ret, "value", T->token, T->token_len, 0);
		efree(T->token);
		efree(T);
	}
}

static void phql_ret_placeholder_zval(zval *ret, int type, phql_parser_token *T)
{
	array_init(ret);
	add_assoc_long(ret, "type", type);
	phql_add_assoc_stringl(ret, "value", T->token, T->token_len, 0);
	efree(T->token);
	efree(T);
}

static void phql_ret_qualified_name(zval *ret, phql_parser_token *A, phql_parser_token *B, phql_parser_token *C)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHQL_T_QUALIFIED);

	if (A) {
		phql_add_assoc_stringl(ret, "ns-alias", A->token, A->token_len, 0);
		efree(A->token);
		efree(A);
	}

	if (B) {
		phql_add_assoc_stringl(ret, "domain", B->token, B->token_len, 0);
		efree(B->token);
		efree(B);
	}

	phql_add_assoc_stringl(ret, "name", C->token, C->token_len, 0);
	efree(C->token);
	efree(C);
}

static void phql_ret_raw_qualified_name(zval *ret, phql_parser_token *A, phql_parser_token *B)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHQL_T_RAW_QUALIFIED);
	if (B) {
		phql_add_assoc_stringl(ret, "domain", A->token, A->token_len, 0);
		phql_add_assoc_stringl(ret, "name", B->token, B->token_len, 0);
		efree(B->token);
		efree(B);
	} else {
		phql_add_assoc_stringl(ret, "name", A->token, A->token_len, 0);
	}

	efree(A->token);
	efree(A);
}

static void phql_ret_select_statement(zval *ret, zval *S, zval *W, zval *O, zval *G, zval *H, zval *L, zval *F)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHQL_T_SELECT);
	add_assoc_zval(ret, "select", S);

	if (W && Z_TYPE_P(W) != IS_UNDEF) {
		add_assoc_zval(ret, "where", W);
	}
	if (O && Z_TYPE_P(O) != IS_UNDEF) {
		add_assoc_zval(ret, "orderBy", O);
	}
	if (G && Z_TYPE_P(G) != IS_UNDEF) {
		add_assoc_zval(ret, "groupBy", G);
	}
	if (H && Z_TYPE_P(H) != IS_UNDEF) {
		add_assoc_zval(ret, "having", H);
	}
	if (L && Z_TYPE_P(L) != IS_UNDEF) {
		add_assoc_zval(ret, "limit", L);
	}
	if (F && Z_TYPE_P(F) != IS_UNDEF) {
		add_assoc_zval(ret, "forUpdate", F);
	}
}

static void phql_ret_select_clause(zval *ret, zval *distinct, zval *columns, zval *tables, zval *join_list)
{
	array_init(ret);

	if (distinct && Z_TYPE_P(distinct) != IS_UNDEF) {
		add_assoc_zval(ret, "distinct", distinct);
	}

	add_assoc_zval(ret, "columns", columns);
	add_assoc_zval(ret, "tables", tables);

	if (join_list && Z_TYPE_P(join_list) != IS_UNDEF) {
		add_assoc_zval(ret, "joins", join_list);
	}
}

static void phql_ret_distinct_all(zval *ret, int distinct)
{
	ZVAL_LONG(ret, distinct);
}

static void phql_ret_distinct(zval *ret)
{
	ZVAL_TRUE(ret);
}

static void phql_ret_order_item(zval *ret, zval *column, int sort){

	array_init(ret);
	add_assoc_zval(ret, "column", column);
	if (sort) {
		add_assoc_long(ret, "sort", sort);
	}
}

static void phql_ret_limit_clause(zval *ret, zval *L, zval *O)
{
	array_init(ret);

	add_assoc_zval(ret, "number", L);

	if (O && Z_TYPE_P(O) != IS_UNDEF) {
		add_assoc_zval(ret, "offset", O);
	}
}

static void phql_ret_for_update_clause(zval *ret)
{
	ZVAL_BOOL(ret, 1);
}

static void phql_ret_insert_statement(zval *ret, zval *Q, zval *F, zval *V)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHQL_T_INSERT);
	add_assoc_zval(ret, "qualifiedName", Q);
	if (F && Z_TYPE_P(F) != IS_UNDEF) {
		add_assoc_zval(ret, "fields", F);
	}
	add_assoc_zval(ret, "values", V);
}

static void phql_ret_update_statement(zval *ret, zval *U, zval *W, zval *L)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHQL_T_UPDATE);
	add_assoc_zval(ret, "update", U);
	if (W && Z_TYPE_P(W) != IS_UNDEF) {
		add_assoc_zval(ret, "where", W);
	}
	if (L && Z_TYPE_P(L) != IS_UNDEF) {
		add_assoc_zval(ret, "limit", L);
	}
}

static void phql_ret_update_clause(zval *ret, zval *tables, zval *values)
{
	array_init(ret);
	add_assoc_zval(ret, "tables", tables);
	add_assoc_zval(ret, "values", values);
}

static void phql_ret_update_item(zval *ret, zval *column, zval *expr)
{
	array_init(ret);
	add_assoc_zval(ret, "column", column);
	add_assoc_zval(ret, "expr", expr);
}

static void phql_ret_delete_statement(zval *ret, zval *D, zval *W, zval *L)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHQL_T_DELETE);
	add_assoc_zval(ret, "delete", D);

	if (W && Z_TYPE_P(W) != IS_UNDEF) {
		add_assoc_zval(ret, "where", W);
	}
	if (L && Z_TYPE_P(L) != IS_UNDEF) {
		add_assoc_zval(ret, "limit", L);
	}
}

static void phql_ret_delete_clause(zval *ret, zval *tables)
{
	array_init(ret);
	add_assoc_zval(ret, "tables", tables);
}

static void phql_ret_zval_list(zval *ret, zval *list_left, zval *right_list)
{
    HashTable *list;

	array_init(ret);

	if (list_left && Z_TYPE_P(list_left) != IS_UNDEF) {

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

	if (right_list && Z_TYPE_P(right_list) != IS_UNDEF) {
		add_next_index_zval(ret, right_list);
	}
}

static void phql_ret_column_item(zval *ret, int type, zval *column, phql_parser_token *identifier_column, phql_parser_token *alias)
{

	array_init(ret);
	add_assoc_long(ret, "type", type);

	if (column && Z_TYPE_P(column) != IS_UNDEF) {
		add_assoc_zval(ret, "column", column);
	}

	if (identifier_column) {
		phql_add_assoc_stringl(ret, "column", identifier_column->token, identifier_column->token_len, 0);
		efree(identifier_column->token);
		efree(identifier_column);
	}

	if (alias) {
		phql_add_assoc_stringl(ret, "alias", alias->token, alias->token_len, 0);
		efree(alias->token);
		efree(alias);
	}
}

static void phql_ret_assoc_name(zval *ret, zval *qualified_name, phql_parser_token *alias, zval *with)
{

	array_init(ret);
	add_assoc_zval(ret, "qualifiedName", qualified_name);

	if (alias) {
		phql_add_assoc_stringl(ret, "alias", alias->token, alias->token_len, 0);
		efree(alias->token);
		efree(alias);
	}

	if (with && Z_TYPE_P(with) != IS_UNDEF) {
		add_assoc_zval(ret, "with", with);
	}
}

static void phql_ret_join_type(zval *ret, int type)
{
	ZVAL_LONG(ret, type);
}

static void phql_ret_join_item(zval *ret, zval *type, zval *qualified, zval *alias, zval *conditions)
{

	array_init(ret);
	add_assoc_zval(ret, "type", type);

	if (qualified && Z_TYPE_P(qualified) != IS_UNDEF) {
		add_assoc_zval(ret, "qualified", qualified);
	}

	if (alias && Z_TYPE_P(alias) != IS_UNDEF) {
		add_assoc_zval(ret, "alias", alias);
	}

	if (conditions && Z_TYPE_P(conditions) != IS_UNDEF) {
		add_assoc_zval(ret, "conditions", conditions);
	}
}

static void phql_ret_expr(zval *ret, int type, zval *left, zval *right)
{
	array_init(ret);
	add_assoc_long(ret, "type", type);
	if (left && Z_TYPE_P(left) != IS_UNDEF) {
		add_assoc_zval(ret, "left", left);
	}
	if (right && Z_TYPE_P(right) != IS_UNDEF) {
		add_assoc_zval(ret, "right", right);
	}
}

static void phql_ret_func_call(zval *ret, phql_parser_token *name, zval *arguments, zval *distinct)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHQL_T_FCALL);
	phql_add_assoc_stringl(ret, "name", name->token, name->token_len, 0);
	efree(name->token);
	efree(name);

	if (arguments && Z_TYPE_P(arguments) != IS_UNDEF) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	if (distinct && Z_TYPE_P(distinct) != IS_UNDEF) {
		add_assoc_zval(ret, "distinct", distinct);
	}
}
