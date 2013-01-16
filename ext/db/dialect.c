
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/file.h"

/**
 * Phalcon\Db\Dialect
 *
 * This is the base class to each database dialect. This implements
 * common methods to transform intermediate code into its RDBM related syntax
 */


/**
 * Phalcon\Db\Dialect initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Dialect){

	PHALCON_REGISTER_CLASS(Phalcon\\Db, Dialect, db_dialect, phalcon_db_dialect_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_db_dialect_ce, SL("_escapeChar"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Generates the SQL for LIMIT clause
 *
 *<code>
 * $sql = $dialect->limit('SELECT * FROM robots', 10);
 * echo $sql; // SELECT * FROM robots LIMIT 10
 *</code>
 *
 * @param string $sqlQuery
 * @param int $number
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, limit){

	zval *sql_query, *number, *is_numeric, *limit, *sql_limit;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &sql_query, &number) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(is_numeric);
	PHALCON_CALL_FUNC_PARAMS_1(is_numeric, "is_numeric", number);
	if (PHALCON_IS_TRUE(is_numeric)) {
		PHALCON_INIT_VAR(limit);
		PHALCON_CALL_FUNC_PARAMS_1(limit, "intval", number);
	
		PHALCON_INIT_VAR(sql_limit);
		PHALCON_CONCAT_VSV(sql_limit, sql_query, " LIMIT ", limit);
		RETURN_CTOR(sql_limit);
	}
	
	
	RETURN_CCTOR(sql_query);
}

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 *<code>
 * $sql = $dialect->forUpdate('SELECT * FROM robots');
 * echo $sql; // SELECT * FROM robots FOR UPDATE
 *</code>
 *
 * @param string $sqlQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, forUpdate){

	zval *sql_query, *sql;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_query) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_VS(sql, sql_query, " FOR UPDATE");
	RETURN_CTOR(sql);
}

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 *<code>
 * $sql = $dialect->sharedLock('SELECT * FROM robots');
 * echo $sql; // SELECT * FROM robots LOCK IN SHARE MODE
 *</code>
 *
 * @param string $sqlQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, sharedLock){

	zval *sql_query, *sql;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_query) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_VS(sql, sql_query, " LOCK IN SHARE MODE");
	RETURN_CTOR(sql);
}

/**
 * Gets a list of columns with escaped identifiers
 *
 *<code>
 * echo $dialect->getColumnList(array('column1', 'column'));
 *</code>
 *
 * @param array $columnList
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getColumnList){

	zval *column_list, *str_list, *escape_char, *column = NULL;
	zval *column_quoted = NULL, *joined_list;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &column_list) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(str_list);
	array_init(str_list);
	
	PHALCON_OBS_VAR(escape_char);
	phalcon_read_property(&escape_char, this_ptr, SL("_escapeChar"), PH_NOISY_CC);
	
	if (!phalcon_is_iterable(column_list, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(column);
	
		PHALCON_INIT_NVAR(column_quoted);
		PHALCON_CONCAT_VVV(column_quoted, escape_char, column, escape_char);
		phalcon_array_append(&str_list, column_quoted, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_INIT_VAR(joined_list);
	phalcon_fast_join_str(joined_list, SL(", "), str_list TSRMLS_CC);
	
	RETURN_CTOR(joined_list);
}

/**
 * Transforms an intermediate representation for a expression into a database system valid expression
 *
 * @param array $expression
 * @param string $escapeChar
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpression){

	zval *expression, *escape_char = NULL, *type, *name = NULL, *escaped_name = NULL;
	zval *domain, *escaped_domain = NULL, *value = NULL, *operator = NULL;
	zval *left = NULL, *expression_left = NULL, *right = NULL, *expression_right = NULL;
	zval *binary_expr, *unary_expr = NULL, *expression_group;
	zval *sql_arguments, *arguments, *argument = NULL, *argument_expression = NULL;
	zval *arguments_joined, *function_expression = NULL;
	zval *sql_items, *items, *item = NULL, *item_expression = NULL;
	zval *list_expression, *group_expression;
	zval *exception_message;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &expression, &escape_char) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!escape_char) {
		PHALCON_INIT_VAR(escape_char);
	} else {
		PHALCON_SEPARATE_PARAM(escape_char);
	}
	
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		if (Z_TYPE_P(escape_char) == IS_NULL) {
			PHALCON_OBS_NVAR(escape_char);
			phalcon_read_property(&escape_char, this_ptr, SL("_escapeChar"), PH_NOISY_CC);
		}
	}
	if (Z_TYPE_P(expression) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid SQL expression");
		return;
	}
	
	if (!phalcon_array_isset_string(expression, SS("type"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid SQL expression");
		return;
	}
	
	PHALCON_OBS_VAR(type);
	phalcon_array_fetch_string(&type, expression, SL("type"), PH_NOISY_CC);
	
	/** 
	 * Resolve qualified expressions
	 */
	if (PHALCON_COMPARE_STRING(type, "qualified")) {
	
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, expression, SL("name"), PH_NOISY_CC);
		if (PHALCON_GLOBAL(db).escape_identifiers) {
			PHALCON_INIT_VAR(escaped_name);
			PHALCON_CONCAT_VVV(escaped_name, escape_char, name, escape_char);
		} else {
			PHALCON_CPY_WRT(escaped_name, name);
		}
	
		/** 
		 * A domain could be a table/schema
		 */
		if (phalcon_array_isset_string(expression, SS("domain"))) {
	
			PHALCON_OBS_VAR(domain);
			phalcon_array_fetch_string(&domain, expression, SL("domain"), PH_NOISY_CC);
			if (PHALCON_GLOBAL(db).escape_identifiers) {
				PHALCON_INIT_VAR(escaped_domain);
				PHALCON_CONCAT_VVVSV(escaped_domain, escape_char, domain, escape_char, ".", escaped_name);
			} else {
				PHALCON_INIT_NVAR(escaped_domain);
				PHALCON_CONCAT_VSV(escaped_domain, domain, ".", escaped_name);
			}
	
	
			RETURN_CTOR(escaped_domain);
		}
	
	
		RETURN_CCTOR(escaped_name);
	}
	
	/** 
	 * Resolve literal expressions
	 */
	if (PHALCON_COMPARE_STRING(type, "literal")) {
		PHALCON_OBS_VAR(value);
		phalcon_array_fetch_string(&value, expression, SL("value"), PH_NOISY_CC);
		RETURN_CCTOR(value);
	}
	
	/** 
	 * Resolve binary operations expressions
	 */
	if (PHALCON_COMPARE_STRING(type, "binary-op")) {
		PHALCON_OBS_VAR(operator);
		phalcon_array_fetch_string(&operator, expression, SL("op"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(left);
		phalcon_array_fetch_string(&left, expression, SL("left"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(expression_left);
		PHALCON_CALL_METHOD_PARAMS_2(expression_left, this_ptr, "getsqlexpression", left, escape_char);
	
		PHALCON_OBS_VAR(right);
		phalcon_array_fetch_string(&right, expression, SL("right"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(expression_right);
		PHALCON_CALL_METHOD_PARAMS_2(expression_right, this_ptr, "getsqlexpression", right, escape_char);
	
		PHALCON_INIT_VAR(binary_expr);
		PHALCON_CONCAT_VSVSV(binary_expr, expression_left, " ", operator, " ", expression_right);
		RETURN_CTOR(binary_expr);
	}
	
	/** 
	 * Resolve unary operations expressions
	 */
	if (PHALCON_COMPARE_STRING(type, "unary-op")) {
	
		PHALCON_OBS_NVAR(operator);
		phalcon_array_fetch_string(&operator, expression, SL("op"), PH_NOISY_CC);
	
		/** 
		 * Some unary operators uses the left operand...
		 */
		if (phalcon_array_isset_string(expression, SS("left"))) {
			PHALCON_OBS_NVAR(left);
			phalcon_array_fetch_string(&left, expression, SL("left"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(expression_left);
			PHALCON_CALL_METHOD_PARAMS_2(expression_left, this_ptr, "getsqlexpression", left, escape_char);
	
			PHALCON_INIT_VAR(unary_expr);
			PHALCON_CONCAT_VV(unary_expr, expression_left, operator);
			RETURN_CTOR(unary_expr);
		}
	
		/** 
		 * ...Others uses the right operand
		 */
		if (phalcon_array_isset_string(expression, SS("right"))) {
			PHALCON_OBS_NVAR(right);
			phalcon_array_fetch_string(&right, expression, SL("right"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(expression_right);
			PHALCON_CALL_METHOD_PARAMS_2(expression_right, this_ptr, "getsqlexpression", right, escape_char);
	
			PHALCON_INIT_NVAR(unary_expr);
			PHALCON_CONCAT_VV(unary_expr, operator, expression_right);
			RETURN_CTOR(unary_expr);
		}
	}
	
	/** 
	 * Resolve placeholder
	 */
	if (PHALCON_COMPARE_STRING(type, "placeholder")) {
		PHALCON_OBS_NVAR(value);
		phalcon_array_fetch_string(&value, expression, SL("value"), PH_NOISY_CC);
		RETURN_CCTOR(value);
	}
	
	/** 
	 * Resolve parentheses
	 */
	if (PHALCON_COMPARE_STRING(type, "parentheses")) {
		PHALCON_OBS_NVAR(left);
		phalcon_array_fetch_string(&left, expression, SL("left"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(expression_left);
		PHALCON_CALL_METHOD_PARAMS_2(expression_left, this_ptr, "getsqlexpression", left, escape_char);
	
		PHALCON_INIT_VAR(expression_group);
		PHALCON_CONCAT_SVS(expression_group, "(", expression_left, ")");
		RETURN_CTOR(expression_group);
	}
	
	/** 
	 * Resolve function calls
	 */
	if (PHALCON_COMPARE_STRING(type, "functionCall")) {
	
		PHALCON_OBS_NVAR(name);
		phalcon_array_fetch_string(&name, expression, SL("name"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(sql_arguments);
		array_init(sql_arguments);
		if (phalcon_array_isset_string(expression, SS("arguments"))) {
	
			PHALCON_OBS_VAR(arguments);
			phalcon_array_fetch_string(&arguments, expression, SL("arguments"), PH_NOISY_CC);
	
			if (!phalcon_is_iterable(arguments, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(argument);
	
				PHALCON_INIT_NVAR(argument_expression);
				PHALCON_CALL_METHOD_PARAMS_2(argument_expression, this_ptr, "getsqlexpression", argument, escape_char);
				phalcon_array_append(&sql_arguments, argument_expression, PH_SEPARATE TSRMLS_CC);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			PHALCON_INIT_VAR(arguments_joined);
			phalcon_fast_join_str(arguments_joined, SL(", "), sql_arguments TSRMLS_CC);
	
			PHALCON_INIT_VAR(function_expression);
			PHALCON_CONCAT_VSVS(function_expression, name, "(", arguments_joined, ")");
		} else {
			PHALCON_INIT_NVAR(function_expression);
			PHALCON_CONCAT_VS(function_expression, name, "()");
		}
	
	
		RETURN_CTOR(function_expression);
	}
	
	/** 
	 * Resolve lists
	 */
	if (PHALCON_COMPARE_STRING(type, "list")) {
	
		PHALCON_INIT_VAR(sql_items);
		array_init(sql_items);
	
		PHALCON_OBS_VAR(items);
		phalcon_array_fetch_long(&items, expression, 0, PH_NOISY_CC);
	
		if (!phalcon_is_iterable(items, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(item);
	
			PHALCON_INIT_NVAR(item_expression);
			PHALCON_CALL_METHOD_PARAMS_2(item_expression, this_ptr, "getsqlexpression", item, escape_char);
			phalcon_array_append(&sql_items, item_expression, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
		PHALCON_INIT_VAR(list_expression);
		phalcon_fast_join_str(list_expression, SL(", "), sql_items TSRMLS_CC);
	
		PHALCON_INIT_VAR(group_expression);
		PHALCON_CONCAT_SVS(group_expression, "(", list_expression, ")");
	
		RETURN_CTOR(group_expression);
	}
	
	/** 
	 * Resolve *
	 */
	if (PHALCON_COMPARE_STRING(type, "all")) {
		PHALCON_MM_RESTORE();
		RETURN_STRING("*", 1);
	}
	
	/** 
	 * Expression type wasn't found
	 */
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SVS(exception_message, "Invalid SQL expression type '", type, "'");
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_db_exception_ce, exception_message);
	return;
}

/**
 * Transform an intermediate representation for a schema/table into a database system valid expression
 *
 * @param array $table
 * @param string $escapeChar
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlTable){

	zval *table, *escape_char = NULL, *table_name, *sql_table = NULL;
	zval *schema_name, *sql_schema = NULL, *alias_name;
	zval *sql_table_alias = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &escape_char) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!escape_char) {
		PHALCON_INIT_VAR(escape_char);
	} else {
		PHALCON_SEPARATE_PARAM(escape_char);
	}
	
	if (Z_TYPE_P(escape_char) == IS_NULL) {
		PHALCON_OBS_NVAR(escape_char);
		phalcon_read_property(&escape_char, this_ptr, SL("_escapeChar"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(table) == IS_ARRAY) { 
	
		/** 
		 * The index '0' is the table name
		 */
		PHALCON_OBS_VAR(table_name);
		phalcon_array_fetch_long(&table_name, table, 0, PH_NOISY_CC);
		if (PHALCON_GLOBAL(db).escape_identifiers) {
			PHALCON_INIT_VAR(sql_table);
			PHALCON_CONCAT_VVV(sql_table, escape_char, table_name, escape_char);
		} else {
			PHALCON_CPY_WRT(sql_table, table_name);
		}
	
		/** 
		 * The index '1' is the schema name
		 */
		PHALCON_OBS_VAR(schema_name);
		phalcon_array_fetch_long(&schema_name, table, 1, PH_NOISY_CC);
		if (Z_TYPE_P(schema_name) != IS_NULL) {
			if (PHALCON_GLOBAL(db).escape_identifiers) {
				PHALCON_INIT_VAR(sql_schema);
				PHALCON_CONCAT_VVVSV(sql_schema, escape_char, schema_name, escape_char, ".", sql_table);
			} else {
				PHALCON_INIT_NVAR(sql_schema);
				PHALCON_CONCAT_VSV(sql_schema, schema_name, ".", sql_table);
			}
		} else {
			PHALCON_CPY_WRT(sql_schema, sql_table);
		}
	
		/** 
		 * The index '2' is the table alias
		 */
		if (phalcon_array_isset_long(table, 2)) {
	
			PHALCON_OBS_VAR(alias_name);
			phalcon_array_fetch_long(&alias_name, table, 2, PH_NOISY_CC);
			if (PHALCON_GLOBAL(db).escape_identifiers) {
				PHALCON_INIT_VAR(sql_table_alias);
				PHALCON_CONCAT_VSVVV(sql_table_alias, sql_schema, " AS ", escape_char, alias_name, escape_char);
			} else {
				PHALCON_INIT_NVAR(sql_table_alias);
				PHALCON_CONCAT_VSV(sql_table_alias, sql_schema, " AS ", alias_name);
			}
		} else {
			PHALCON_CPY_WRT(sql_table_alias, sql_schema);
		}
	
	
		RETURN_CCTOR(sql_table_alias);
	}
	
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		PHALCON_INIT_NVAR(sql_table);
		PHALCON_CONCAT_VVV(sql_table, escape_char, table, escape_char);
		RETURN_CCTOR(sql_table);
	}
	
	
	RETURN_CCTOR(table);
}

/**
 * Builds a SELECT statement
 *
 * @param array $definition
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, select){

	zval *definition, *escape_char = NULL, *columns, *selected_columns;
	zval *column = NULL, *column_item = NULL, *column_sql = NULL, *columns_sql = NULL;
	zval *column_domain = NULL, *column_domain_sql = NULL, *column_alias = NULL;
	zval *column_alias_sql = NULL, *tables, *selected_tables;
	zval *table = NULL, *sql_table = NULL, *tables_sql = NULL, *sql, *joins;
	zval *join = NULL, *type = NULL, *sql_join = NULL, *join_conditions_array = NULL;
	zval *join_expressions = NULL, *join_condition = NULL, *join_expression = NULL;
	zval *join_conditions = NULL, *where_conditions;
	zval *where_expression, *group_items, *group_fields;
	zval *group_field = NULL, *group_expression = NULL, *group_sql;
	zval *group_clause, *having_conditions, *having_expression;
	zval *order_fields, *order_items, *order_item = NULL;
	zval *order_expression = NULL, *order_sql_item = NULL, *sql_order_type = NULL;
	zval *order_sql_item_type = NULL, *order_sql, *limit_value;
	zval *number, *offset;
	HashTable *ah0, *ah1, *ah2, *ah3, *ah4, *ah5;
	HashPosition hp0, hp1, hp2, hp3, hp4, hp5;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &definition) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(definition) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid SELECT definition");
		return;
	}
	if (!phalcon_array_isset_string(definition, SS("tables"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'tables' is required in the definition array");
		return;
	}
	
	if (!phalcon_array_isset_string(definition, SS("columns"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array");
		return;
	}
	
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		PHALCON_OBS_VAR(escape_char);
		phalcon_read_property(&escape_char, this_ptr, SL("_escapeChar"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(escape_char);
	}
	
	PHALCON_OBS_VAR(columns);
	phalcon_array_fetch_string(&columns, definition, SL("columns"), PH_NOISY_CC);
	if (Z_TYPE_P(columns) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(selected_columns);
		array_init(selected_columns);
	
		if (!phalcon_is_iterable(columns, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(column);
	
			/** 
			 * Escape column name
			 */
			PHALCON_OBS_NVAR(column_item);
			phalcon_array_fetch_long(&column_item, column, 0, PH_NOISY_CC);
			if (Z_TYPE_P(column_item) == IS_ARRAY) { 
				PHALCON_INIT_NVAR(column_sql);
				PHALCON_CALL_METHOD_PARAMS_2(column_sql, this_ptr, "getsqlexpression", column_item, escape_char);
			} else {
				if (PHALCON_COMPARE_STRING(column_item, "*")) {
					PHALCON_CPY_WRT(column_sql, column_item);
				} else {
					if (PHALCON_GLOBAL(db).escape_identifiers) {
						PHALCON_INIT_NVAR(column_sql);
						PHALCON_CONCAT_VVV(column_sql, escape_char, column_item, escape_char);
					} else {
						PHALCON_CPY_WRT(columns_sql, column_item);
					}
				}
			}
	
			/** 
			 * Escape column domain
			 */
			PHALCON_OBS_NVAR(column_domain);
			phalcon_array_fetch_long(&column_domain, column, 1, PH_NOISY_CC);
			if (zend_is_true(column_domain)) {
				if (PHALCON_GLOBAL(db).escape_identifiers) {
					PHALCON_INIT_NVAR(column_domain_sql);
					PHALCON_CONCAT_VVVSV(column_domain_sql, escape_char, column_domain, escape_char, ".", column_sql);
				} else {
					PHALCON_INIT_NVAR(column_domain_sql);
					PHALCON_CONCAT_VSV(column_domain_sql, column_domain, ".", column_sql);
				}
			} else {
				PHALCON_CPY_WRT(column_domain_sql, column_sql);
			}
	
			/** 
			 * Escape column alias
			 */
			if (phalcon_array_isset_long(column, 2)) {
	
				PHALCON_OBS_NVAR(column_alias);
				phalcon_array_fetch_long(&column_alias, column, 2, PH_NOISY_CC);
				if (zend_is_true(column_alias)) {
					if (PHALCON_GLOBAL(db).escape_identifiers) {
						PHALCON_INIT_NVAR(column_alias_sql);
						PHALCON_CONCAT_VSVVV(column_alias_sql, column_domain_sql, " AS ", escape_char, column_alias, escape_char);
					} else {
						PHALCON_INIT_NVAR(column_alias_sql);
						PHALCON_CONCAT_VSV(column_alias_sql, column_domain_sql, " AS ", column_alias);
					}
				} else {
					PHALCON_CPY_WRT(column_alias_sql, column_domain_sql);
				}
			} else {
				PHALCON_CPY_WRT(column_alias_sql, column_domain_sql);
			}
	
			phalcon_array_append(&selected_columns, column_alias_sql, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		PHALCON_INIT_VAR(columns_sql);
		phalcon_fast_join_str(columns_sql, SL(", "), selected_columns TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(columns_sql, columns);
	}
	
	/** 
	 * Check and escape tables
	 */
	PHALCON_OBS_VAR(tables);
	phalcon_array_fetch_string(&tables, definition, SL("tables"), PH_NOISY_CC);
	if (Z_TYPE_P(tables) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(selected_tables);
		array_init(selected_tables);
	
		if (!phalcon_is_iterable(tables, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(table);
	
			PHALCON_INIT_NVAR(sql_table);
			PHALCON_CALL_METHOD_PARAMS_2(sql_table, this_ptr, "getsqltable", table, escape_char);
			phalcon_array_append(&selected_tables, sql_table, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
		PHALCON_INIT_VAR(tables_sql);
		phalcon_fast_join_str(tables_sql, SL(", "), selected_tables TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(tables_sql, tables);
	}
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVSV(sql, "SELECT ", columns_sql, " FROM ", tables_sql);
	
	/** 
	 * Check for joins
	 */
	if (phalcon_array_isset_string(definition, SS("joins"))) {
	
		PHALCON_OBS_VAR(joins);
		phalcon_array_fetch_string(&joins, definition, SL("joins"), PH_NOISY_CC);
	
		if (!phalcon_is_iterable(joins, &ah2, &hp2, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(join);
	
			PHALCON_OBS_NVAR(type);
			phalcon_array_fetch_string(&type, join, SL("type"), PH_NOISY_CC);
	
			PHALCON_OBS_NVAR(table);
			phalcon_array_fetch_string(&table, join, SL("source"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(sql_table);
			PHALCON_CALL_METHOD_PARAMS_2(sql_table, this_ptr, "getsqltable", table, escape_char);
			phalcon_array_append(&selected_tables, sql_table, PH_SEPARATE TSRMLS_CC);
	
			PHALCON_INIT_NVAR(sql_join);
			PHALCON_CONCAT_SVSV(sql_join, " ", type, " JOIN ", sql_table);
	
			/** 
			 * Check if the join has conditions
			 */
			if (phalcon_array_isset_string(join, SS("conditions"))) {
	
				PHALCON_OBS_NVAR(join_conditions_array);
				phalcon_array_fetch_string(&join_conditions_array, join, SL("conditions"), PH_NOISY_CC);
				if (phalcon_fast_count_ev(join_conditions_array TSRMLS_CC)) {
	
					PHALCON_INIT_NVAR(join_expressions);
					array_init(join_expressions);
	
					if (!phalcon_is_iterable(join_conditions_array, &ah3, &hp3, 0, 0 TSRMLS_CC)) {
						return;
					}
	
					while (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) == SUCCESS) {
	
						PHALCON_GET_FOREACH_VALUE(join_condition);
	
						PHALCON_INIT_NVAR(join_expression);
						PHALCON_CALL_METHOD_PARAMS_2(join_expression, this_ptr, "getsqlexpression", join_condition, escape_char);
						phalcon_array_append(&join_expressions, join_expression, PH_SEPARATE TSRMLS_CC);
	
						zend_hash_move_forward_ex(ah3, &hp3);
					}
	
					PHALCON_INIT_NVAR(join_conditions);
					phalcon_fast_join_str(join_conditions, SL(" AND "), join_expressions TSRMLS_CC);
					PHALCON_SCONCAT_SV(sql_join, " ON ", join_conditions);
				}
			}
	
			phalcon_concat_self(&sql, sql_join TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah2, &hp2);
		}
	
	}
	
	/** 
	 * Check for a WHERE clause
	 */
	if (phalcon_array_isset_string(definition, SS("where"))) {
		PHALCON_OBS_VAR(where_conditions);
		phalcon_array_fetch_string(&where_conditions, definition, SL("where"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(where_expression);
		PHALCON_CALL_METHOD_PARAMS_2(where_expression, this_ptr, "getsqlexpression", where_conditions, escape_char);
		PHALCON_SCONCAT_SV(sql, " WHERE ", where_expression);
	}
	
	/** 
	 * Check for a GROUP clause
	 */
	if (phalcon_array_isset_string(definition, SS("group"))) {
	
		PHALCON_INIT_VAR(group_items);
		array_init(group_items);
	
		PHALCON_OBS_VAR(group_fields);
		phalcon_array_fetch_string(&group_fields, definition, SL("group"), PH_NOISY_CC);
	
		if (!phalcon_is_iterable(group_fields, &ah4, &hp4, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah4, (void**) &hd, &hp4) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(group_field);
	
			PHALCON_INIT_NVAR(group_expression);
			PHALCON_CALL_METHOD_PARAMS_2(group_expression, this_ptr, "getsqlexpression", group_field, escape_char);
			phalcon_array_append(&group_items, group_expression, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah4, &hp4);
		}
	
		PHALCON_INIT_VAR(group_sql);
		phalcon_fast_join_str(group_sql, SL(", "), group_items TSRMLS_CC);
	
		PHALCON_INIT_VAR(group_clause);
		PHALCON_CONCAT_SV(group_clause, " GROUP BY ", group_sql);
		phalcon_concat_self(&sql, group_clause TSRMLS_CC);
	
		/** 
		 * Check for a HAVING clause
		 */
		if (phalcon_array_isset_string(definition, SS("having"))) {
			PHALCON_OBS_VAR(having_conditions);
			phalcon_array_fetch_string(&having_conditions, definition, SL("having"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(having_expression);
			PHALCON_CALL_METHOD_PARAMS_2(having_expression, this_ptr, "getsqlexpression", having_conditions, escape_char);
			PHALCON_SCONCAT_SV(sql, " HAVING ", having_expression);
		}
	}
	
	/** 
	 * Check for a ORDER clause
	 */
	if (phalcon_array_isset_string(definition, SS("order"))) {
	
		PHALCON_OBS_VAR(order_fields);
		phalcon_array_fetch_string(&order_fields, definition, SL("order"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(order_items);
		array_init(order_items);
	
		if (!phalcon_is_iterable(order_fields, &ah5, &hp5, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah5, (void**) &hd, &hp5) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(order_item);
	
			PHALCON_OBS_NVAR(order_expression);
			phalcon_array_fetch_long(&order_expression, order_item, 0, PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(order_sql_item);
			PHALCON_CALL_METHOD_PARAMS_2(order_sql_item, this_ptr, "getsqlexpression", order_expression, escape_char);
	
			/** 
			 * In the numeric 1 position could be a ASC/DESC clause
			 */
			if (phalcon_array_isset_long(order_item, 1)) {
				PHALCON_OBS_NVAR(sql_order_type);
				phalcon_array_fetch_long(&sql_order_type, order_item, 1, PH_NOISY_CC);
	
				PHALCON_INIT_NVAR(order_sql_item_type);
				PHALCON_CONCAT_VSV(order_sql_item_type, order_sql_item, " ", sql_order_type);
			} else {
				PHALCON_CPY_WRT(order_sql_item_type, order_sql_item);
			}
	
			phalcon_array_append(&order_items, order_sql_item_type, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah5, &hp5);
		}
	
		PHALCON_INIT_VAR(order_sql);
		phalcon_fast_join_str(order_sql, SL(", "), order_items TSRMLS_CC);
		PHALCON_SCONCAT_SV(sql, " ORDER BY ", order_sql);
	}
	
	/** 
	 * Check for a LIMIT condition
	 */
	if (phalcon_array_isset_string(definition, SS("limit"))) {
	
		PHALCON_OBS_VAR(limit_value);
		phalcon_array_fetch_string(&limit_value, definition, SL("limit"), PH_NOISY_CC);
		if (Z_TYPE_P(limit_value) == IS_ARRAY) { 
	
			PHALCON_OBS_VAR(number);
			phalcon_array_fetch_string(&number, limit_value, SL("number"), PH_NOISY_CC);
	
			/** 
			 * Check for a OFFSET condition
			 */
			if (phalcon_array_isset_string(limit_value, SS("offset"))) {
				PHALCON_OBS_VAR(offset);
				phalcon_array_fetch_string(&offset, limit_value, SL("offset"), PH_NOISY_CC);
				PHALCON_SCONCAT_SVSV(sql, " LIMIT ", number, " OFFSET ", offset);
			} else {
				PHALCON_SCONCAT_SV(sql, " LIMIT ", number);
			}
		} else {
			PHALCON_SCONCAT_SV(sql, " LIMIT ", limit_value);
		}
	}
	
	
	RETURN_CTOR(sql);
}

