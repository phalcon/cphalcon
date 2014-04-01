
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

#include "db/dialect.h"
#include "db/dialectinterface.h"
#include "db/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"

/**
 * Phalcon\Db\Dialect
 *
 * This is the base class to each database dialect. This implements
 * common methods to transform intermediate code into its RDBM related syntax
 */
zend_class_entry *phalcon_db_dialect_ce;

PHP_METHOD(Phalcon_Db_Dialect, limit);
PHP_METHOD(Phalcon_Db_Dialect, forUpdate);
PHP_METHOD(Phalcon_Db_Dialect, sharedLock);
PHP_METHOD(Phalcon_Db_Dialect, getColumnList);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpression);
PHP_METHOD(Phalcon_Db_Dialect, getSqlTable);
PHP_METHOD(Phalcon_Db_Dialect, select);
PHP_METHOD(Phalcon_Db_Dialect, supportsSavepoints);
PHP_METHOD(Phalcon_Db_Dialect, supportsReleaseSavepoints);
PHP_METHOD(Phalcon_Db_Dialect, createSavepoint);
PHP_METHOD(Phalcon_Db_Dialect, releaseSavepoint);
PHP_METHOD(Phalcon_Db_Dialect, rollbackSavepoint);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpression, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqltable, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_db_dialect_method_entry[] = {
	PHP_ME(Phalcon_Db_Dialect, limit, arginfo_phalcon_db_dialectinterface_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, forUpdate, arginfo_phalcon_db_dialectinterface_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, sharedLock, arginfo_phalcon_db_dialectinterface_sharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, getColumnList, arginfo_phalcon_db_dialectinterface_getcolumnlist, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpression, arginfo_phalcon_db_dialect_getsqlexpression, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, getSqlTable, arginfo_phalcon_db_dialect_getsqltable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, select, arginfo_phalcon_db_dialectinterface_select, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, supportsSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, supportsReleaseSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, createSavepoint, arginfo_phalcon_db_dialectinterface_createsavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, releaseSavepoint, arginfo_phalcon_db_dialectinterface_releasesavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, rollbackSavepoint, arginfo_phalcon_db_dialectinterface_rollbacksavepoint, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Db\Dialect initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Dialect){

	PHALCON_REGISTER_CLASS(Phalcon\\Db, Dialect, db_dialect, phalcon_db_dialect_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_db_dialect_ce, SL("_escapeChar"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_dialect_ce TSRMLS_CC, 1, phalcon_db_dialectinterface_ce);

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

	zval *sql_query, *number, *limit;

	phalcon_fetch_params(1, 2, 0, &sql_query, &number);
	
	if (phalcon_is_numeric(number)) {
		PHALCON_MM_GROW();
		PHALCON_INIT_VAR(limit);
		ZVAL_LONG(limit, phalcon_get_intval(number));
		PHALCON_CONCAT_VSV(return_value, sql_query, " LIMIT ", limit);
		RETURN_MM();
	}
	
	RETURN_ZVAL(sql_query, 1, 0);
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

	zval *sql_query;

	phalcon_fetch_params(0, 1, 0, &sql_query);
	
	PHALCON_CONCAT_VS(return_value, sql_query, " FOR UPDATE");
	return;
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

	zval *sql_query;

	phalcon_fetch_params(0, 1, 0, &sql_query);
	
	PHALCON_CONCAT_VS(return_value, sql_query, " LOCK IN SHARE MODE");
	return;
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
	zval *column_quoted = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &column_list);
	
	PHALCON_INIT_VAR(str_list);
	array_init(str_list);
	
	PHALCON_OBS_VAR(escape_char);
	phalcon_read_property_this(&escape_char, this_ptr, SL("_escapeChar"), PH_NOISY TSRMLS_CC);
	
	phalcon_is_iterable(column_list, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(column);
	
		PHALCON_INIT_NVAR(column_quoted);
		PHALCON_CONCAT_VVV(column_quoted, escape_char, column, escape_char);
		phalcon_array_append(&str_list, column_quoted, PH_SEPARATE);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	phalcon_fast_join_str(return_value, SL(", "), str_list TSRMLS_CC);
	RETURN_MM();
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
	zval *expression_group, *sql_arguments, *arguments;
	zval *argument = NULL, *argument_expression = NULL, *arguments_joined;
	zval *sql_items, *items, *item = NULL, *item_expression = NULL;
	zval *list_expression, *exception_message;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &expression, &escape_char);
	
	if (!escape_char) {
		PHALCON_INIT_VAR(escape_char);
	} else {
		PHALCON_SEPARATE_PARAM(escape_char);
	}
	
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		if (Z_TYPE_P(escape_char) == IS_NULL) {
			PHALCON_OBS_NVAR(escape_char);
			phalcon_read_property_this(&escape_char, this_ptr, SL("_escapeChar"), PH_NOISY TSRMLS_CC);
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
	phalcon_array_fetch_string(&type, expression, SL("type"), PH_NOISY);
	
	/** 
	 * Resolve qualified expressions
	 */
	if (PHALCON_IS_STRING(type, "qualified")) {
	
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, expression, SL("name"), PH_NOISY);
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
			phalcon_array_fetch_string(&domain, expression, SL("domain"), PH_NOISY);
			if (PHALCON_GLOBAL(db).escape_identifiers) {
				PHALCON_INIT_VAR(escaped_domain);
				PHALCON_CONCAT_VVVSV(escaped_domain, escape_char, domain, escape_char, ".", escaped_name);
			} else {
				PHALCON_INIT_NVAR(escaped_domain);
				PHALCON_CONCAT_VSV(escaped_domain, domain, ".", escaped_name);
			}
	
			RETURN_CTOR(escaped_domain);
		}
	
		RETURN_CTOR(escaped_name);
	}
	
	/** 
	 * Resolve literal expressions
	 */
	if (PHALCON_IS_STRING(type, "literal")) {
		PHALCON_OBS_VAR(value);
		phalcon_array_fetch_string(&value, expression, SL("value"), PH_NOISY);
		RETURN_CTOR(value);
	}
	
	/** 
	 * Resolve binary operations expressions
	 */
	if (PHALCON_IS_STRING(type, "binary-op")) {
		PHALCON_OBS_VAR(operator);
		phalcon_array_fetch_string(&operator, expression, SL("op"), PH_NOISY);
	
		PHALCON_OBS_VAR(left);
		phalcon_array_fetch_string(&left, expression, SL("left"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&expression_left, this_ptr, "getsqlexpression", left, escape_char);
	
		PHALCON_OBS_VAR(right);
		phalcon_array_fetch_string(&right, expression, SL("right"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&expression_right, this_ptr, "getsqlexpression", right, escape_char);
		PHALCON_CONCAT_VSVSV(return_value, expression_left, " ", operator, " ", expression_right);
		RETURN_MM();
	}
	
	/** 
	 * Resolve unary operations expressions
	 */
	if (PHALCON_IS_STRING(type, "unary-op")) {
	
		PHALCON_OBS_NVAR(operator);
		phalcon_array_fetch_string(&operator, expression, SL("op"), PH_NOISY);
	
		/** 
		 * Some unary operators uses the left operand...
		 */
		if (phalcon_array_isset_string(expression, SS("left"))) {
			PHALCON_OBS_NVAR(left);
			phalcon_array_fetch_string(&left, expression, SL("left"), PH_NOISY);
	
			PHALCON_CALL_METHOD(&expression_left, this_ptr, "getsqlexpression", left, escape_char);
			PHALCON_CONCAT_VV(return_value, expression_left, operator);
			RETURN_MM();
		}
	
		/** 
		 * ...Others uses the right operand
		 */
		if (phalcon_array_isset_string(expression, SS("right"))) {
			PHALCON_OBS_NVAR(right);
			phalcon_array_fetch_string(&right, expression, SL("right"), PH_NOISY);
	
			PHALCON_CALL_METHOD(&expression_right, this_ptr, "getsqlexpression", right, escape_char);
			PHALCON_CONCAT_VV(return_value, operator, expression_right);
			RETURN_MM();
		}
	}
	
	/** 
	 * Resolve placeholder
	 */
	if (PHALCON_IS_STRING(type, "placeholder")) {
		PHALCON_OBS_NVAR(value);
		phalcon_array_fetch_string(&value, expression, SL("value"), PH_NOISY);
		RETURN_CTOR(value);
	}
	
	/** 
	 * Resolve parentheses
	 */
	if (PHALCON_IS_STRING(type, "parentheses")) {
		PHALCON_OBS_NVAR(left);
		phalcon_array_fetch_string(&left, expression, SL("left"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&expression_left, this_ptr, "getsqlexpression", left, escape_char);
	
		PHALCON_INIT_VAR(expression_group);
		PHALCON_CONCAT_SVS(expression_group, "(", expression_left, ")");
		RETURN_CTOR(expression_group);
	}
	
	/** 
	 * Resolve function calls
	 */
	if (PHALCON_IS_STRING(type, "functionCall")) {
	
		PHALCON_OBS_NVAR(name);
		phalcon_array_fetch_string(&name, expression, SL("name"), PH_NOISY);
	
		PHALCON_INIT_VAR(sql_arguments);
		array_init(sql_arguments);
		if (phalcon_array_isset_string(expression, SS("arguments"))) {
	
			PHALCON_OBS_VAR(arguments);
			phalcon_array_fetch_string(&arguments, expression, SL("arguments"), PH_NOISY);
	
			phalcon_is_iterable(arguments, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HVALUE(argument);
	
				PHALCON_CALL_METHOD(&argument_expression, this_ptr, "getsqlexpression", argument, escape_char);
				phalcon_array_append(&sql_arguments, argument_expression, PH_SEPARATE);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			PHALCON_INIT_VAR(arguments_joined);
			phalcon_fast_join_str(arguments_joined, SL(", "), sql_arguments TSRMLS_CC);
			if (phalcon_array_isset_string(expression, SS("distinct"))) {
				PHALCON_CONCAT_VSVS(return_value, name, "(DISTINCT ", arguments_joined, ")");
			}
			else {
				PHALCON_CONCAT_VSVS(return_value, name, "(", arguments_joined, ")");
			}
	
			RETURN_MM();
		} else {
			PHALCON_CONCAT_VS(return_value, name, "()");
			RETURN_MM();
		}
	}
	
	/** 
	 * Resolve lists
	 */
	if (PHALCON_IS_STRING(type, "list")) {
	
		PHALCON_INIT_VAR(sql_items);
		array_init(sql_items);
	
		PHALCON_OBS_VAR(items);
		phalcon_array_fetch_long(&items, expression, 0, PH_NOISY);
	
		phalcon_is_iterable(items, &ah1, &hp1, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_HVALUE(item);
	
			PHALCON_CALL_METHOD(&item_expression, this_ptr, "getsqlexpression", item, escape_char);
			phalcon_array_append(&sql_items, item_expression, PH_SEPARATE);
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
		PHALCON_INIT_VAR(list_expression);
		phalcon_fast_join_str(list_expression, SL(", "), sql_items TSRMLS_CC);
		PHALCON_CONCAT_SVS(return_value, "(", list_expression, ")");
	
		RETURN_MM();
	}
	
	/** 
	 * Resolve *
	 */
	if (PHALCON_IS_STRING(type, "all")) {
		RETURN_MM_STRING("*", 1);
	}
	
	/** 
	 * Resolve CAST of values 
	 */
	if (PHALCON_IS_STRING(type, "cast")) {
		PHALCON_OBS_NVAR(left);
		phalcon_array_fetch_string(&left, expression, SL("left"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&expression_left, this_ptr, "getsqlexpression", left, escape_char);
	
		PHALCON_OBS_NVAR(right);
		phalcon_array_fetch_string(&right, expression, SL("right"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&expression_right, this_ptr, "getsqlexpression", right, escape_char);
		PHALCON_CONCAT_SVSVS(return_value, "CAST(", expression_left, " AS ", expression_right, ")");
		RETURN_MM();
	}
	
	/** 
	 * Resolve CONVERT of values encodings
	 */
	if (PHALCON_IS_STRING(type, "convert")) {
		PHALCON_OBS_NVAR(left);
		phalcon_array_fetch_string(&left, expression, SL("left"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&expression_left, this_ptr, "getsqlexpression", left, escape_char);
	
		PHALCON_OBS_NVAR(right);
		phalcon_array_fetch_string(&right, expression, SL("right"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&expression_right, this_ptr, "getsqlexpression", right, escape_char);
		PHALCON_CONCAT_SVSVS(return_value, "CONVERT(", expression_left, " USING ", expression_right, ")");
		RETURN_MM();
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

	phalcon_fetch_params(1, 1, 1, &table, &escape_char);
	
	if (!escape_char) {
		PHALCON_INIT_VAR(escape_char);
	} else {
		PHALCON_SEPARATE_PARAM(escape_char);
	}
	
	if (Z_TYPE_P(escape_char) == IS_NULL) {
		PHALCON_OBS_NVAR(escape_char);
		phalcon_read_property_this(&escape_char, this_ptr, SL("_escapeChar"), PH_NOISY TSRMLS_CC);
	}
	if (Z_TYPE_P(table) == IS_ARRAY) { 
	
		/** 
		 * The index '0' is the table name
		 */
		PHALCON_OBS_VAR(table_name);
		phalcon_array_fetch_long(&table_name, table, 0, PH_NOISY);
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
		phalcon_array_fetch_long(&schema_name, table, 1, PH_NOISY);
		if (PHALCON_IS_NOT_EMPTY(schema_name)) {
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
			phalcon_array_fetch_long(&alias_name, table, 2, PH_NOISY);
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
	
		RETURN_CTOR(sql_table_alias);
	}
	
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		PHALCON_CONCAT_VVV(return_value, escape_char, table, escape_char);
		RETURN_MM();
	}
	
	RETURN_CTOR(table);
}

/**
 * Builds a SELECT statement
 *
 * @param array $definition
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, select){

	zval *definition, *escape_char = NULL, *columns, *selected_columns, *distinct;
	zval *column = NULL, *column_sql = NULL;
	zval *column_domain_sql = NULL, *column_alias_sql = NULL;
	zval *columns_sql = NULL, *tables, *selected_tables;
	zval *table = NULL, *sql_table = NULL, *tables_sql = NULL, *sql, *joins;
	zval *join = NULL, *type = NULL, *sql_join = NULL, *join_conditions_array = NULL;
	zval *join_expressions = NULL, *join_condition = NULL, *join_expression = NULL;
	zval *join_conditions = NULL, *where_conditions;
	zval *where_expression = NULL, *group_items, *group_fields;
	zval *group_field = NULL, *group_expression = NULL, *group_sql;
	zval *group_clause, *having_conditions, *having_expression = NULL;
	zval *order_fields, *order_items, *order_item = NULL;
	zval *order_expression = NULL, *order_sql_item = NULL, *sql_order_type = NULL;
	zval *order_sql_item_type = NULL, *order_sql, *tmp1 = NULL, *tmp2 = NULL;
	zval *limit_value;
	zval *number, *offset;
	HashTable *ah0, *ah1, *ah2, *ah3, *ah4, *ah5;
	HashPosition hp0, hp1, hp2, hp3, hp4, hp5;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &definition);

	if (Z_TYPE_P(definition) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid SELECT definition");
		return;
	}
	if (!phalcon_array_isset_string(definition, SS("tables"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'tables' is required in the definition array");
		return;
	}
	
	if (!phalcon_array_isset_string_fetch(&columns, definition, SS("columns"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array");
		return;
	}
	
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		PHALCON_OBS_VAR(escape_char);
		phalcon_read_property_this(&escape_char, this_ptr, SL("_escapeChar"), PH_NOISY TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(escape_char);
	}
	
	if (Z_TYPE_P(columns) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(selected_columns);
		array_init(selected_columns);
	
		phalcon_is_iterable(columns, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			zval *column_item, *column_alias, *column_domain;
	
			PHALCON_GET_HVALUE(column);
	
			/** 
			 * Escape column name
			 */
			if (
				    phalcon_array_isset_long_fetch(&column_item, column, 0)
				 || phalcon_array_isset_string_fetch(&column_item, column, SS("column"))
			) {
				if (Z_TYPE_P(column_item) == IS_ARRAY) {
					PHALCON_CALL_METHOD(&column_sql, this_ptr, "getsqlexpression", column_item, escape_char);
				} else if (PHALCON_IS_STRING(column_item, "*")) {
					PHALCON_CPY_WRT(column_sql, column_item);
				} else if (PHALCON_GLOBAL(db).escape_identifiers) {
					PHALCON_INIT_NVAR(column_sql);
					PHALCON_CONCAT_VVV(column_sql, escape_char, column_item, escape_char);
				} else {
					PHALCON_CPY_WRT(column_sql, column_item);
				}
			}
			else {
				PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid SELECT definition");
				return;
			}
	
			/** 
			 * Escape column domain
			 */
			if (phalcon_array_isset_long_fetch(&column_domain, column, 1)) {
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
			} else {
				PHALCON_CPY_WRT(column_domain_sql, column_sql);
			}
	
			/** 
			 * Escape column alias
			 */
			if (phalcon_array_isset_long_fetch(&column_alias, column, 2)) {
	
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
	
			phalcon_array_append(&selected_columns, column_alias_sql, PH_SEPARATE);
	
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
	phalcon_array_fetch_string(&tables, definition, SL("tables"), PH_NOISY);
	if (Z_TYPE_P(tables) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(selected_tables);
		array_init(selected_tables);
	
		phalcon_is_iterable(tables, &ah1, &hp1, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_HVALUE(table);
	
			PHALCON_CALL_METHOD(&sql_table, this_ptr, "getsqltable", table, escape_char);
			phalcon_array_append(&selected_tables, sql_table, PH_SEPARATE);
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
		PHALCON_INIT_VAR(tables_sql);
		phalcon_fast_join_str(tables_sql, SL(", "), selected_tables TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(tables_sql, tables);
	}

	PHALCON_INIT_VAR(sql);
	if (phalcon_array_isset_string_fetch(&distinct, definition, SS("distinct"))) {
		assert(Z_TYPE_P(distinct) == IS_LONG);
		if (Z_LVAL_P(distinct) == 0) {
			ZVAL_STRING(sql, "SELECT ALL ", 1);
		}
		else if (Z_LVAL_P(distinct) == 1) {
			ZVAL_STRING(sql, "SELECT DISTINCT ", 1);
		}
		else {
			ZVAL_STRING(sql, "SELECT ", 1);
		}
	}
	else {
		ZVAL_STRING(sql, "SELECT ", 1);
	}
	
	PHALCON_SCONCAT_VSV(sql, columns_sql, " FROM ", tables_sql);
	
	/** 
	 * Check for joins
	 */
	if (phalcon_array_isset_string(definition, SS("joins"))) {
	
		PHALCON_OBS_VAR(joins);
		phalcon_array_fetch_string(&joins, definition, SL("joins"), PH_NOISY);
	
		phalcon_is_iterable(joins, &ah2, &hp2, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
			PHALCON_GET_HVALUE(join);
	
			PHALCON_OBS_NVAR(type);
			phalcon_array_fetch_string(&type, join, SL("type"), PH_NOISY);
	
			PHALCON_OBS_NVAR(table);
			phalcon_array_fetch_string(&table, join, SL("source"), PH_NOISY);
	
			PHALCON_CALL_METHOD(&sql_table, this_ptr, "getsqltable", table, escape_char);
			phalcon_array_append(&selected_tables, sql_table, PH_SEPARATE);
	
			PHALCON_INIT_NVAR(sql_join);
			PHALCON_CONCAT_SVSV(sql_join, " ", type, " JOIN ", sql_table);
	
			/** 
			 * Check if the join has conditions
			 */
			if (phalcon_array_isset_string(join, SS("conditions"))) {
	
				PHALCON_OBS_NVAR(join_conditions_array);
				phalcon_array_fetch_string(&join_conditions_array, join, SL("conditions"), PH_NOISY);
				if (phalcon_fast_count_ev(join_conditions_array TSRMLS_CC)) {
	
					PHALCON_INIT_NVAR(join_expressions);
					array_init(join_expressions);
	
					phalcon_is_iterable(join_conditions_array, &ah3, &hp3, 0, 0);
	
					while (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) == SUCCESS) {
	
						PHALCON_GET_HVALUE(join_condition);
	
						PHALCON_CALL_METHOD(&join_expression, this_ptr, "getsqlexpression", join_condition, escape_char);
						phalcon_array_append(&join_expressions, join_expression, PH_SEPARATE);
	
						zend_hash_move_forward_ex(ah3, &hp3);
					}
	
					PHALCON_INIT_NVAR(join_conditions);
					phalcon_fast_join_str(join_conditions, SL(" AND "), join_expressions TSRMLS_CC);
					PHALCON_SCONCAT_SVS(sql_join, " ON ", join_conditions, " ");
				}
			}
	
			phalcon_concat_self(&sql, sql_join TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah2, &hp2);
		}
	
	}
	
	/* Check for a WHERE clause */
	if (phalcon_array_isset_string_fetch(&where_conditions, definition, SS("where"))) {
	
		if (Z_TYPE_P(where_conditions) == IS_ARRAY) { 
			PHALCON_CALL_METHOD(&where_expression, this_ptr, "getsqlexpression", where_conditions, escape_char);
			PHALCON_SCONCAT_SV(sql, " WHERE ", where_expression);
		} else {
			PHALCON_SCONCAT_SV(sql, " WHERE ", where_conditions);
		}
	}
	
	/* Check for a GROUP clause */
	if (phalcon_array_isset_string_fetch(&group_fields, definition, SS("group"))) {
	
		PHALCON_INIT_VAR(group_items);
		array_init(group_items);
	
		phalcon_is_iterable(group_fields, &ah4, &hp4, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah4, (void**) &hd, &hp4) == SUCCESS) {
	
			PHALCON_GET_HVALUE(group_field);
	
			PHALCON_CALL_METHOD(&group_expression, this_ptr, "getsqlexpression", group_field, escape_char);
			phalcon_array_append(&group_items, group_expression, PH_SEPARATE);
	
			zend_hash_move_forward_ex(ah4, &hp4);
		}
	
		PHALCON_INIT_VAR(group_sql);
		phalcon_fast_join_str(group_sql, SL(", "), group_items TSRMLS_CC);
	
		PHALCON_INIT_VAR(group_clause);
		PHALCON_CONCAT_SV(group_clause, " GROUP BY ", group_sql);
		phalcon_concat_self(&sql, group_clause TSRMLS_CC);
	}

	/* Check for a HAVING clause */
	if (phalcon_array_isset_string_fetch(&having_conditions, definition, SS("having"))) {
		PHALCON_CALL_METHOD(&having_expression, this_ptr, "getsqlexpression", having_conditions, escape_char);
		PHALCON_SCONCAT_SV(sql, " HAVING ", having_expression);
	}
	
	/* Check for a ORDER clause */
	if (phalcon_array_isset_string_fetch(&order_fields, definition, SS("order"))) {
		PHALCON_INIT_VAR(order_items);
		array_init(order_items);
	
		phalcon_is_iterable(order_fields, &ah5, &hp5, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah5, (void**) &hd, &hp5) == SUCCESS) {
	
			PHALCON_GET_HVALUE(order_item);
	
			PHALCON_OBS_NVAR(order_expression);
			phalcon_array_fetch_long(&order_expression, order_item, 0, PH_NOISY);
	
			PHALCON_CALL_METHOD(&order_sql_item, this_ptr, "getsqlexpression", order_expression, escape_char);
	
			/** 
			 * In the numeric 1 position could be a ASC/DESC clause
			 */
			if (phalcon_array_isset_long(order_item, 1)) {
				PHALCON_OBS_NVAR(sql_order_type);
				phalcon_array_fetch_long(&sql_order_type, order_item, 1, PH_NOISY);
	
				PHALCON_INIT_NVAR(order_sql_item_type);
				PHALCON_CONCAT_VSV(order_sql_item_type, order_sql_item, " ", sql_order_type);
			} else {
				PHALCON_CPY_WRT(order_sql_item_type, order_sql_item);
			}
	
			phalcon_array_append(&order_items, order_sql_item_type, PH_SEPARATE);
	
			zend_hash_move_forward_ex(ah5, &hp5);
		}
	
		PHALCON_INIT_VAR(order_sql);
		phalcon_fast_join_str(order_sql, SL(", "), order_items TSRMLS_CC);
		PHALCON_SCONCAT_SV(sql, " ORDER BY ", order_sql);
	}
	
	/** 
	 * Check for a LIMIT condition
	 */
	if (phalcon_array_isset_string_fetch(&limit_value, definition, SS("limit"))) {
		if (likely(Z_TYPE_P(limit_value) == IS_ARRAY)) {
			if (likely(phalcon_array_isset_string_fetch(&number, limit_value, SS("number")))) {
				PHALCON_OBS_NVAR(tmp1);
				phalcon_array_fetch_string(&tmp1, number, SL("value"), PH_NOISY);

				/**
				 * Check for a OFFSET condition
				 */
				if (phalcon_array_isset_string_fetch(&offset, limit_value, SS("offset"))) {
					PHALCON_OBS_NVAR(tmp2);
					phalcon_array_fetch_string(&tmp2, offset, SL("value"), PH_NOISY);
					PHALCON_SCONCAT_SVSV(sql, " LIMIT ", tmp1, " OFFSET ", tmp2);
				} else {
					PHALCON_SCONCAT_SV(sql, " LIMIT ", tmp1);
				}
			}
		} else {
			PHALCON_SCONCAT_SV(sql, " LIMIT ", limit_value);
		}
	}
	
	RETURN_CTOR(sql);
}

/**
 * Checks whether the platform supports savepoints
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Dialect, supportsSavepoints){


	RETURN_TRUE;
}

/**
 * Checks whether the platform supports releasing savepoints.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Dialect, supportsReleaseSavepoints)
{
	PHALCON_RETURN_CALL_METHODW(this_ptr, "supportssavepoints");
}

/**
 * Generate SQL to create a new savepoint
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, createSavepoint){

	zval *name;

	phalcon_fetch_params(0, 1, 0, &name);
	
	PHALCON_CONCAT_SV(return_value, "SAVEPOINT ", name);
	return;
}

/**
 * Generate SQL to release a savepoint
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, releaseSavepoint){

	zval *name;

	phalcon_fetch_params(0, 1, 0, &name);
	
	PHALCON_CONCAT_SV(return_value, "RELEASE SAVEPOINT ", name);
	return;
}

/**
 * Generate SQL to rollback a savepoint
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, rollbackSavepoint){

	zval *name;

	phalcon_fetch_params(0, 1, 0, &name);
	
	PHALCON_CONCAT_SV(return_value, "ROLLBACK TO SAVEPOINT ", name);
	return;
}
