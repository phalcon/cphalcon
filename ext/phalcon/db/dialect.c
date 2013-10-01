
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"


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
/**
 * Phalcon\Db\Dialect
 *
 * This is the base class to each database dialect. This implements
 * common methods to transform intermediate code into its RDBM related syntax
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Dialect, phalcon, db_dialect, phalcon_db_dialect_method_entry, 0);

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
 * @param string sqlQuery
 * @param int number
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, limit) {

	int number;
	zval *sqlQuery_param = NULL, *number_param = NULL, _0, *_1;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sqlQuery_param, &number_param);

		zephir_get_strval(sqlQuery, sqlQuery_param);
		number = zephir_get_intval(number_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, number);
	if (zephir_is_numeric(&_0)) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, sqlQuery, " LIMIT ");
		concat_function(return_value, _1, number TSRMLS_CC);
		RETURN_MM();
	}
	RETURN_CTOR(sqlQuery);

}

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 *<code>
 * $sql = $dialect->forUpdate('SELECT * FROM robots');
 * echo $sql; // SELECT * FROM robots FOR UPDATE
 *</code>
 *
 * @param	string sqlQuery
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect, forUpdate) {

	zval *sqlQuery_param = NULL;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

		zephir_get_strval(sqlQuery, sqlQuery_param);


	ZEPHIR_CONCAT_VS(return_value, sqlQuery, " FOR UPDATE");
	RETURN_MM();

}

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 *<code>
 * $sql = $dialect->sharedLock('SELECT * FROM robots');
 * echo $sql; // SELECT * FROM robots LOCK IN SHARE MODE
 *</code>
 *
 * @param	string sqlQuery
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect, sharedLock) {

	zval *sqlQuery_param = NULL;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

		zephir_get_strval(sqlQuery, sqlQuery_param);


	ZEPHIR_CONCAT_VS(return_value, sqlQuery, " LOCK IN SHARE MODE");
	RETURN_MM();

}

/**
 * Gets a list of columns with escaped identifiers
 *
 *<code>
 * echo $dialect->getColumnList(array('column1', 'column'));
 *</code>
 *
 * @param	array columnList
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect, getColumnList) {

	HashTable *_1;
	HashPosition _0;
	zval *columnList, *strList, *escapeChar, *column = NULL, **_2, *_3 = NULL, *_4 = NULL, _5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &columnList);



	ZEPHIR_INIT_VAR(strList);
	array_init(strList);
	ZEPHIR_OBS_VAR(escapeChar);
	escapeChar = zephir_fetch_nproperty_this(this_ptr, SL("_escapeChar"), PH_NOISY_CC);
	zephir_is_iterable(columnList, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(column, _2);
		ZEPHIR_INIT_LNVAR(_3);
		concat_function(_3, escapeChar, column TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_4);
		concat_function(_4, _3, escapeChar TSRMLS_CC);
		zephir_array_append(&strList, _4, PH_SEPARATE);
	}
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, ", ", 0);
	zephir_call_func_p2(return_value, "join", &_5, strList);
	RETURN_MM();

}

/**
 * Transforms an intermediate representation for a expression into a database system valid expression
 *
 * @param array expression
 * @param string escapeChar
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpression) {

	zend_function *_14 = NULL, *_19 = NULL;
	HashTable *_12, *_17;
	HashPosition _11, _16;
	zval *escapeChar = NULL, *_3 = NULL;
	zval *expression, *escapeChar_param = NULL, *type, *domain, *operator, *left = NULL, *right = NULL, *name = NULL, *sqlItems, *escapedName = NULL, *sqlArguments, *arguments, *argument = NULL, *items, *item = NULL, *_0, *_1, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9, *_10, **_13, _15 = zval_used_for_init, **_18, *_20 = NULL, *_21 = NULL, *_22 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression, &escapeChar_param);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "db.escape_identifiers", 1);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "globals_get", _0);
	if (zephir_is_true(_1)) {
		if (ZEPHIR_IS_STRING(escapeChar, "")) {
			ZEPHIR_OBS_VAR(_2);
			zephir_read_property_this(&_2, this_ptr, SL("_escapeChar"), PH_NOISY_CC);
			zephir_get_strval(_3, _2);
			ZEPHIR_CPY_WRT(escapeChar, _3);
		}
	}
	if ((Z_TYPE_P(expression) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid SQL expression");
		return;
	}
	ZEPHIR_OBS_VAR(type);
	if (!(zephir_array_isset_string_fetch(&type, expression, SS("type") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid SQL expression");
		return;
	}
	if (ZEPHIR_IS_STRING(type, "qualified")) {
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_string(&name, expression, SL("name"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "db.escape_identifiers", 1);
		ZEPHIR_INIT_VAR(_4);
		zephir_call_func_p1(_4, "globals_get", _0);
		if (zephir_is_true(_4)) {
			ZEPHIR_INIT_VAR(_5);
			concat_function(_5, escapeChar, name TSRMLS_CC);
			ZEPHIR_INIT_VAR(escapedName);
			concat_function(escapedName, _5, escapeChar TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(escapedName, name);
		}
		ZEPHIR_OBS_VAR(domain);
		if (zephir_array_isset_string_fetch(&domain, expression, SS("domain") TSRMLS_CC)) {
			ZEPHIR_INIT_BNVAR(_0);
			ZVAL_STRING(_0, "db.escape_identifiers", 1);
			ZEPHIR_INIT_VAR(_6);
			zephir_call_func_p1(_6, "globals_get", _0);
			if (zephir_is_true(_6)) {
				ZEPHIR_INIT_LNVAR(_5);
				concat_function(_5, escapeChar, domain TSRMLS_CC);
				ZEPHIR_INIT_VAR(_7);
				concat_function(_7, _5, escapeChar TSRMLS_CC);
				ZEPHIR_INIT_VAR(_8);
				ZEPHIR_CONCAT_VS(_8, _7, ".");
				concat_function(return_value, _8, escapedName TSRMLS_CC);
				RETURN_MM();
			} else {
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_VS(_7, domain, ".");
				concat_function(return_value, _7, escapedName TSRMLS_CC);
				RETURN_MM();
			}
		}
		RETURN_CCTOR(escapedName);
	}
	if (ZEPHIR_IS_STRING(type, "literal")) {
		zephir_array_fetch_string(&return_value, expression, SL("value"), PH_NOISY TSRMLS_CC);
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(type, "binary-op")) {
		zephir_array_fetch_string(&_9, expression, SL("left"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(left);
		zephir_call_method_p2(left, this_ptr, "getsqlexpression", _9, escapeChar);
		zephir_array_fetch_string(&_10, expression, SL("right"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(right);
		zephir_call_method_p2(right, this_ptr, "getsqlexpression", _10, escapeChar);
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_VS(_5, left, " ");
		ZEPHIR_OBS_NVAR(_2);
		zephir_array_fetch_string(&_2, expression, SL("op"), PH_NOISY TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_7);
		concat_function(_7, _5, _2 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_8);
		ZEPHIR_CONCAT_VS(_8, _7, " ");
		concat_function(return_value, _8, right TSRMLS_CC);
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(type, "unary-op")) {
		zephir_array_fetch_string(&operator, expression, SL("op"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(left);
		if (zephir_array_isset_string_fetch(&left, expression, SS("left") TSRMLS_CC)) {
			ZEPHIR_INIT_BNVAR(_0);
			zephir_call_method_p2(_0, this_ptr, "getsqlexpression", left, escapeChar);
			concat_function(return_value, _0, operator TSRMLS_CC);
			RETURN_MM();
		}
		ZEPHIR_OBS_NVAR(right);
		if (zephir_array_isset_string_fetch(&right, expression, SS("right") TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_4);
			zephir_call_method_p2(_4, this_ptr, "getsqlexpression", right, escapeChar);
			concat_function(return_value, _4, operator TSRMLS_CC);
			RETURN_MM();
		}
	}
	if (ZEPHIR_IS_STRING(type, "placeholder")) {
		zephir_array_fetch_string(&return_value, expression, SL("value"), PH_NOISY TSRMLS_CC);
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(type, "parentheses")) {
		ZEPHIR_INIT_NVAR(_4);
		zephir_array_fetch_string(&_9, expression, SL("left"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_call_method_p2(_4, this_ptr, "getsqlexpression", _9, escapeChar);
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_SV(_5, "(", _4);
		ZEPHIR_CONCAT_VS(return_value, _5, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(type, "functionCall")) {
		ZEPHIR_OBS_NVAR(name);
		zephir_array_fetch_string(&name, expression, SL("name"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(sqlArguments);
		array_init(sqlArguments);
		ZEPHIR_OBS_VAR(arguments);
		if (zephir_array_isset_string_fetch(&arguments, expression, SS("arguments") TSRMLS_CC)) {
			zephir_is_iterable(arguments, &_12, &_11, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
				; zend_hash_move_forward_ex(_12, &_11)
			) {
				ZEPHIR_GET_HVALUE(argument, _13);
				ZEPHIR_INIT_NVAR(_4);
				zephir_call_method_p2_cache(_4, this_ptr, "getsqlexpression", &_14, argument, escapeChar);
				zephir_array_append(&sqlArguments, _4, PH_SEPARATE);
			}
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_CONCAT_VS(_7, name, "(");
			ZEPHIR_SINIT_VAR(_15);
			ZVAL_STRING(&_15, ", ", 0);
			ZEPHIR_INIT_NVAR(_6);
			zephir_call_func_p2(_6, "join", &_15, sqlArguments);
			ZEPHIR_INIT_LNVAR(_8);
			concat_function(_8, _7, _6 TSRMLS_CC);
			ZEPHIR_CONCAT_VS(return_value, _8, ")");
			RETURN_MM();
		} else {
			ZEPHIR_CONCAT_VS(return_value, name, "()");
			RETURN_MM();
		}
	}
	if (ZEPHIR_IS_STRING(type, "list")) {
		ZEPHIR_INIT_VAR(sqlItems);
		array_init(sqlItems);
		zephir_array_fetch_long(&items, expression, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_is_iterable(items, &_17, &_16, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
			; zend_hash_move_forward_ex(_17, &_16)
		) {
			ZEPHIR_GET_HVALUE(item, _18);
			ZEPHIR_INIT_NVAR(_4);
			zephir_call_method_p2_cache(_4, this_ptr, "getsqlexpression", &_19, item, escapeChar);
			zephir_array_append(&sqlItems, _4, PH_SEPARATE);
		}
		ZEPHIR_SINIT_NVAR(_15);
		ZVAL_STRING(&_15, ", ", 0);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_func_p2(_6, "join", &_15, sqlItems);
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_SV(_5, "(", _6);
		ZEPHIR_CONCAT_VS(return_value, _5, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(type, "all")) {
		RETURN_MM_STRING("*", 1);
	}
	if (ZEPHIR_IS_STRING(type, "cast")) {
		zephir_array_fetch_string(&_9, expression, SL("left"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(left);
		zephir_call_method_p2(left, this_ptr, "getsqlexpression", _9, escapeChar);
		zephir_array_fetch_string(&_10, expression, SL("right"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(right);
		zephir_call_method_p2(right, this_ptr, "getsqlexpression", _10, escapeChar);
		ZEPHIR_INIT_VAR(_20);
		ZEPHIR_CONCAT_SV(_20, "CAST(", left);
		ZEPHIR_INIT_VAR(_21);
		ZEPHIR_CONCAT_VS(_21, _20, " AS ");
		ZEPHIR_INIT_VAR(_22);
		concat_function(_22, _21, right TSRMLS_CC);
		ZEPHIR_CONCAT_VS(return_value, _22, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(type, "convert")) {
		zephir_array_fetch_string(&_9, expression, SL("left"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(left);
		zephir_call_method_p2(left, this_ptr, "getsqlexpression", _9, escapeChar);
		zephir_array_fetch_string(&_10, expression, SL("right"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(right);
		zephir_call_method_p2(right, this_ptr, "getsqlexpression", _10, escapeChar);
		ZEPHIR_INIT_LNVAR(_20);
		ZEPHIR_CONCAT_SV(_20, "CONVERT(", left);
		ZEPHIR_INIT_LNVAR(_21);
		ZEPHIR_CONCAT_VS(_21, _20, " USING ");
		ZEPHIR_INIT_LNVAR(_22);
		concat_function(_22, _21, right TSRMLS_CC);
		ZEPHIR_CONCAT_VS(return_value, _22, ")");
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_4);
	object_init_ex(_4, phalcon_db_exception_ce);
	ZEPHIR_INIT_LNVAR(_20);
	ZEPHIR_CONCAT_SV(_20, "Invalid SQL expression type '", type);
	ZEPHIR_INIT_LNVAR(_21);
	ZEPHIR_CONCAT_VS(_21, _20, "'");
	zephir_call_method_p1_noret(_4, "__construct", _21);
	zephir_throw_exception(_4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Transform an intermediate representation for a schema/table into a database system valid expression
 *
 * @param array table
 * @param string escapeChar
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlTable) {

	zval *escapeChar = NULL, *_1 = NULL;
	zval *table, *escapeChar_param = NULL, *sqlTable = NULL, *sqlSchema = NULL, *aliasName, *sqlTableAlias = NULL, *schemaName, *tableName, *_0, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &escapeChar_param);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	if (ZEPHIR_IS_STRING(escapeChar, "")) {
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("_escapeChar"), PH_NOISY_CC);
		zephir_get_strval(_1, _0);
		ZEPHIR_CPY_WRT(escapeChar, _1);
	}
	if ((Z_TYPE_P(table) == IS_ARRAY)) {
		zephir_array_fetch_long(&tableName, table, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "db.escape_identifiers", 1);
		ZEPHIR_INIT_VAR(_3);
		zephir_call_func_p1(_3, "globals_get", _2);
		if (zephir_is_true(_3)) {
			ZEPHIR_INIT_VAR(_4);
			concat_function(_4, escapeChar, tableName TSRMLS_CC);
			ZEPHIR_INIT_VAR(sqlTable);
			concat_function(sqlTable, _4, escapeChar TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(sqlTable, tableName);
		}
		zephir_array_fetch_long(&schemaName, table, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		if ((Z_TYPE_P(schemaName) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(sqlSchema);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "db.escape_identifiers", 1);
			ZEPHIR_INIT_VAR(_5);
			zephir_call_func_p1(_5, "globals_get", _2);
			if (zephir_is_true(_5)) {
				ZEPHIR_INIT_LNVAR(_4);
				concat_function(_4, escapeChar, schemaName TSRMLS_CC);
				ZEPHIR_INIT_VAR(_6);
				concat_function(_6, _4, escapeChar TSRMLS_CC);
				ZEPHIR_INIT_VAR(_7);
				ZEPHIR_CONCAT_VS(_7, _6, ".");
				concat_function(sqlSchema, _7, sqlTable TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_VS(_6, schemaName, ".");
				concat_function(sqlSchema, _6, sqlTable TSRMLS_CC);
			}
		} else {
			ZEPHIR_CPY_WRT(sqlSchema, sqlTable);
		}
		ZEPHIR_OBS_VAR(aliasName);
		if (zephir_array_isset_long_fetch(&aliasName, table, 2 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(sqlTableAlias);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "db.escape_identifiers", 1);
			ZEPHIR_INIT_NVAR(_5);
			zephir_call_func_p1(_5, "globals_get", _2);
			if (zephir_is_true(_5)) {
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_VS(_4, sqlSchema, " AS ");
				ZEPHIR_INIT_LNVAR(_6);
				concat_function(_6, _4, escapeChar TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_7);
				concat_function(_7, _6, aliasName TSRMLS_CC);
				concat_function(sqlTableAlias, _7, escapeChar TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_VS(_6, sqlSchema, " AS ");
				concat_function(sqlTableAlias, _6, aliasName TSRMLS_CC);
			}
		} else {
			ZEPHIR_CPY_WRT(sqlTableAlias, sqlSchema);
		}
		RETURN_CCTOR(sqlTableAlias);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "db.escape_identifiers", 1);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p1(_3, "globals_get", _2);
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_LNVAR(_4);
		concat_function(_4, escapeChar, table TSRMLS_CC);
		concat_function(return_value, _4, escapeChar TSRMLS_CC);
		RETURN_MM();
	}
	RETURN_CCTOR(table);

}

/**
 * Builds a SELECT statement
 *
 * @param array definition
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, select) {

	zend_function *_5 = NULL, *_14 = NULL, *_19 = NULL, *_25 = NULL, *_30 = NULL, *_37 = NULL;
	HashTable *_3, *_12, *_16, *_23, *_28, *_35;
	HashPosition _2, _11, _15, _22, _27, _34;
	zval *definition, *tables, *columns = NULL, *escapeChar, *columnItem, *column = NULL, *selectedColumns, *columnSql = NULL, *columnDomainSql = NULL, *columnAlias = NULL, *selectedTables, *sqlJoin = NULL, *joinExpressions = NULL, *joinCondition = NULL, *joinConditionsArray = NULL, *tablesSql = NULL, *columnDomain = NULL, *columnAliasSql = NULL, *columnsSql = NULL, *table = NULL, *sql, *joins, *join = NULL, *sqlTable = NULL, *whereConditions, *groupFields, *groupField = NULL, *groupItems, *havingConditions, *orderFields, *orderItem = NULL, *orderItems, *orderSqlItem = NULL, *sqlOrderType = NULL, *orderSqlItemType = NULL, *limitValue, *number, *offset, *_0 = NULL, *_1, **_4, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, _10 = zval_used_for_init, **_13, **_17, *_18, *_20 = NULL, *_21 = NULL, **_24, *_26 = NULL, **_29, *_31 = NULL, *_32, *_33 = NULL, **_36, *_38 = NULL, *_39;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition);



	if ((Z_TYPE_P(definition) == IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid SELECT definition");
		return;
	}
	ZEPHIR_OBS_VAR(tables);
	if (!(zephir_array_isset_string_fetch(&tables, definition, SS("tables") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'tables' is required in the definition array");
		return;
	}
	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array");
		return;
	}
	ZEPHIR_INIT_VAR(escapeChar);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "db.escape_identifiers", 1);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "globals_get", _0);
	if (zephir_is_true(_1)) {
		zephir_read_property_this(&escapeChar, this_ptr, SL("_escapeChar"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_BNVAR(escapeChar);
		ZVAL_NULL(escapeChar);
	}
	ZEPHIR_OBS_NVAR(columns);
	zephir_array_fetch_string(&columns, definition, SL("columns"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if ((Z_TYPE_P(columns) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(selectedColumns);
		array_init(selectedColumns);
		zephir_is_iterable(columns, &_3, &_2, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
			; zend_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(column, _4);
			zephir_array_fetch_long(&columnItem, column, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
			if ((Z_TYPE_P(columnItem) == IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(columnSql);
				zephir_call_method_p2_cache(columnSql, this_ptr, "getsqlexpression", &_5, columnItem, escapeChar);
			} else {
				if (ZEPHIR_IS_STRING(columnItem, "*")) {
					ZEPHIR_CPY_WRT(columnSql, columnItem);
				} else {
					ZEPHIR_INIT_NVAR(_0);
					ZVAL_STRING(_0, "db.escape_identifiers", 1);
					ZEPHIR_INIT_NVAR(_6);
					zephir_call_func_p1(_6, "globals_get", _0);
					if (zephir_is_true(_6)) {
						ZEPHIR_INIT_LNVAR(_7);
						concat_function(_7, escapeChar, columnItem TSRMLS_CC);
						ZEPHIR_INIT_NVAR(columnSql);
						concat_function(columnSql, _7, escapeChar TSRMLS_CC);
					} else {
						ZEPHIR_CPY_WRT(columnSql, columnItem);
					}
				}
			}
			ZEPHIR_OBS_NVAR(columnDomain);
			if (zephir_array_isset_long_fetch(&columnDomain, column, 1 TSRMLS_CC)) {
				if (zephir_is_true(columnDomain)) {
					ZEPHIR_INIT_NVAR(columnDomainSql);
					ZEPHIR_INIT_NVAR(_0);
					ZVAL_STRING(_0, "db.escape_identifiers", 1);
					ZEPHIR_INIT_NVAR(_6);
					zephir_call_func_p1(_6, "globals_get", _0);
					if (zephir_is_true(_6)) {
						ZEPHIR_INIT_LNVAR(_7);
						concat_function(_7, escapeChar, columnDomain TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_8);
						concat_function(_8, _7, escapeChar TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_9);
						ZEPHIR_CONCAT_VS(_9, _8, ".");
						concat_function(columnDomainSql, _9, columnSql TSRMLS_CC);
					} else {
						ZEPHIR_INIT_LNVAR(_7);
						ZEPHIR_CONCAT_VS(_7, columnDomain, ".");
						concat_function(columnDomainSql, _7, columnSql TSRMLS_CC);
					}
				} else {
					ZEPHIR_CPY_WRT(columnDomainSql, columnSql);
				}
			} else {
				ZEPHIR_CPY_WRT(columnDomainSql, columnSql);
			}
			ZEPHIR_OBS_NVAR(columnAlias);
			if (zephir_array_isset_long_fetch(&columnAlias, column, 2 TSRMLS_CC)) {
				if (zephir_is_true(columnAlias)) {
					ZEPHIR_INIT_NVAR(columnAliasSql);
					ZEPHIR_INIT_NVAR(_0);
					ZVAL_STRING(_0, "db.escape_identifiers", 1);
					ZEPHIR_INIT_NVAR(_6);
					zephir_call_func_p1(_6, "globals_get", _0);
					if (zephir_is_true(_6)) {
						ZEPHIR_INIT_LNVAR(_7);
						ZEPHIR_CONCAT_VS(_7, columnDomainSql, " AS ");
						ZEPHIR_INIT_LNVAR(_8);
						concat_function(_8, _7, escapeChar TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_9);
						concat_function(_9, _8, columnAlias TSRMLS_CC);
						concat_function(columnAliasSql, _9, escapeChar TSRMLS_CC);
					} else {
						ZEPHIR_INIT_LNVAR(_7);
						ZEPHIR_CONCAT_VS(_7, columnDomainSql, " AS ");
						concat_function(columnAliasSql, _7, columnAlias TSRMLS_CC);
					}
				} else {
					ZEPHIR_CPY_WRT(columnAliasSql, columnDomainSql);
				}
			} else {
				ZEPHIR_CPY_WRT(columnAliasSql, columnDomainSql);
			}
			zephir_array_append(&selectedColumns, columnAliasSql, PH_SEPARATE);
		}
		ZEPHIR_SINIT_VAR(_10);
		ZVAL_STRING(&_10, ", ", 0);
		ZEPHIR_INIT_VAR(columnsSql);
		zephir_call_func_p2(columnsSql, "join", &_10, selectedColumns);
	} else {
		ZEPHIR_CPY_WRT(columnsSql, columns);
	}
	if ((Z_TYPE_P(tables) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(selectedTables);
		array_init(selectedTables);
		zephir_is_iterable(tables, &_12, &_11, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
			; zend_hash_move_forward_ex(_12, &_11)
		) {
			ZEPHIR_GET_HVALUE(table, _13);
			ZEPHIR_INIT_NVAR(_0);
			zephir_call_method_p2_cache(_0, this_ptr, "getsqltable", &_14, table, escapeChar);
			zephir_array_append(&selectedTables, _0, PH_SEPARATE);
		}
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_STRING(&_10, ", ", 0);
		ZEPHIR_INIT_VAR(tablesSql);
		zephir_call_func_p2(tablesSql, "join", &_10, selectedTables);
	} else {
		ZEPHIR_CPY_WRT(tablesSql, tables);
	}
	ZEPHIR_INIT_LNVAR(_7);
	ZEPHIR_CONCAT_SV(_7, "SELECT ", columnsSql);
	ZEPHIR_INIT_LNVAR(_8);
	ZEPHIR_CONCAT_VS(_8, _7, " FROM ");
	ZEPHIR_INIT_VAR(sql);
	concat_function(sql, _8, tablesSql TSRMLS_CC);
	ZEPHIR_OBS_VAR(joins);
	if (zephir_array_isset_string_fetch(&joins, definition, SS("joins") TSRMLS_CC)) {
		zephir_is_iterable(joins, &_16, &_15, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_16, (void**) &_17, &_15) == SUCCESS
			; zend_hash_move_forward_ex(_16, &_15)
		) {
			ZEPHIR_GET_HVALUE(join, _17);
			zephir_array_fetch_string(&_18, join, SL("source"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(sqlTable);
			zephir_call_method_p2_cache(sqlTable, this_ptr, "getsqltable", &_19, _18, escapeChar);
			zephir_array_append(&selectedTables, sqlTable, PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_20);
			zephir_array_fetch_string(&_20, join, SL("type"), PH_NOISY TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_SV(_9, " ", _20);
			ZEPHIR_INIT_LNVAR(_21);
			ZEPHIR_CONCAT_VS(_21, _9, " JOIN ");
			ZEPHIR_INIT_NVAR(sqlJoin);
			concat_function(sqlJoin, _21, sqlTable TSRMLS_CC);
			ZEPHIR_OBS_NVAR(joinConditionsArray);
			if (zephir_array_isset_string_fetch(&joinConditionsArray, join, SS("conditions") TSRMLS_CC)) {
				if (zephir_fast_count_int(joinConditionsArray TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(joinExpressions);
					array_init(joinExpressions);
					zephir_is_iterable(joinConditionsArray, &_23, &_22, 0, 0);
					for (
						; zend_hash_get_current_data_ex(_23, (void**) &_24, &_22) == SUCCESS
						; zend_hash_move_forward_ex(_23, &_22)
					) {
						ZEPHIR_GET_HVALUE(joinCondition, _24);
						ZEPHIR_INIT_NVAR(_6);
						zephir_call_method_p2_cache(_6, this_ptr, "getsqlexpression", &_25, joinCondition, escapeChar);
						zephir_array_append(&joinExpressions, _6, PH_SEPARATE);
					}
					ZEPHIR_SINIT_NVAR(_10);
					ZVAL_STRING(&_10, " AND ", 0);
					ZEPHIR_INIT_NVAR(_26);
					zephir_call_func_p2(_26, "join", &_10, joinExpressions);
					ZEPHIR_INIT_LNVAR(_7);
					ZEPHIR_CONCAT_SV(_7, " ON ", _26);
					ZEPHIR_INIT_LNVAR(_8);
					ZEPHIR_CONCAT_VS(_8, _7, " ");
					zephir_concat_self(&sqlJoin, _8 TSRMLS_CC);
				}
			}
			zephir_concat_self(&sql, sqlJoin TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(whereConditions);
	if (zephir_array_isset_string_fetch(&whereConditions, definition, SS("where") TSRMLS_CC)) {
		if ((Z_TYPE_P(whereConditions) == IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_6);
			zephir_call_method_p2(_6, this_ptr, "getsqlexpression", whereConditions, escapeChar);
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_SV(_9, " WHERE ", _6);
			zephir_concat_self(&sql, _9 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_LNVAR(_21);
			ZEPHIR_CONCAT_SV(_21, " WHERE ", whereConditions);
			zephir_concat_self(&sql, _21 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(groupFields);
	if (zephir_array_isset_string_fetch(&groupFields, definition, SS("group") TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(groupItems);
		array_init(groupItems);
		zephir_is_iterable(groupFields, &_28, &_27, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_28, (void**) &_29, &_27) == SUCCESS
			; zend_hash_move_forward_ex(_28, &_27)
		) {
			ZEPHIR_GET_HVALUE(groupField, _29);
			ZEPHIR_INIT_NVAR(_26);
			zephir_call_method_p2_cache(_26, this_ptr, "getsqlexpression", &_30, groupField, escapeChar);
			zephir_array_append(&groupItems, _26, PH_SEPARATE);
		}
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_STRING(&_10, ", ", 0);
		ZEPHIR_INIT_VAR(_31);
		zephir_call_func_p2(_31, "join", &_10, groupItems);
		ZEPHIR_INIT_LNVAR(_21);
		ZEPHIR_CONCAT_SV(_21, " GROUP BY ", _31);
		zephir_concat_self(&sql, _21 TSRMLS_CC);
		ZEPHIR_OBS_VAR(havingConditions);
		if (zephir_array_isset_string_fetch(&havingConditions, definition, SS("having") TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_32);
			zephir_call_method_p2(_32, this_ptr, "getsqlexpression", havingConditions, escapeChar);
			ZEPHIR_INIT_VAR(_33);
			ZEPHIR_CONCAT_SV(_33, " HAVING ", _32);
			zephir_concat_self(&sql, _33 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(orderFields);
	if (zephir_array_isset_string_fetch(&orderFields, definition, SS("order") TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(orderItems);
		array_init(orderItems);
		zephir_is_iterable(orderFields, &_35, &_34, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_35, (void**) &_36, &_34) == SUCCESS
			; zend_hash_move_forward_ex(_35, &_34)
		) {
			ZEPHIR_GET_HVALUE(orderItem, _36);
			zephir_array_fetch_long(&_18, orderItem, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(orderSqlItem);
			zephir_call_method_p2_cache(orderSqlItem, this_ptr, "getsqlexpression", &_37, _18, escapeChar);
			ZEPHIR_OBS_NVAR(sqlOrderType);
			if (zephir_array_isset_long_fetch(&sqlOrderType, orderItem, 1 TSRMLS_CC)) {
				ZEPHIR_INIT_LNVAR(_21);
				ZEPHIR_CONCAT_VS(_21, orderSqlItem, " ");
				ZEPHIR_INIT_NVAR(orderSqlItemType);
				concat_function(orderSqlItemType, _21, sqlOrderType TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(orderSqlItemType, orderSqlItem);
			}
			zephir_array_append(&orderItems, orderSqlItemType, PH_SEPARATE);
		}
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_STRING(&_10, ", ", 0);
		ZEPHIR_INIT_NVAR(_31);
		zephir_call_func_p2(_31, "join", &_10, orderItems);
		ZEPHIR_INIT_LNVAR(_21);
		ZEPHIR_CONCAT_SV(_21, " ORDER BY ", _31);
		zephir_concat_self(&sql, _21 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(limitValue);
	if (zephir_array_isset_string_fetch(&limitValue, definition, SS("limit") TSRMLS_CC)) {
		if ((Z_TYPE_P(limitValue) == IS_ARRAY)) {
			zephir_array_fetch_string(&number, limitValue, SL("number"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_OBS_VAR(offset);
			if (zephir_array_isset_string_fetch(&offset, limitValue, SS("offset") TSRMLS_CC)) {
				ZEPHIR_INIT_LNVAR(_33);
				ZEPHIR_CONCAT_SV(_33, " LIMIT ", number);
				ZEPHIR_INIT_VAR(_38);
				ZEPHIR_CONCAT_VS(_38, _33, " OFFSET ");
				ZEPHIR_INIT_VAR(_39);
				concat_function(_39, _38, offset TSRMLS_CC);
				zephir_concat_self(&sql, _39 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_38);
				ZEPHIR_CONCAT_SV(_38, " LIMIT ", number);
				zephir_concat_self(&sql, _38 TSRMLS_CC);
			}
		} else {
			ZEPHIR_INIT_LNVAR(_21);
			ZEPHIR_CONCAT_SV(_21, " LIMIT ", limitValue);
			zephir_concat_self(&sql, _21 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(sql);

}

/**
 * Checks whether the platform supports savepoints
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Dialect, supportsSavepoints) {


	RETURN_BOOL(1);

}

/**
 * Checks whether the platform supports releasing savepoints.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Dialect, supportsReleaseSavepoints) {

	ZEPHIR_MM_GROW();

	zephir_call_method(return_value, this_ptr, "supportssavepoints");
	RETURN_MM();

}

/**
 * Generate SQL to create a new savepoint
 *
 * @param string name
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, createSavepoint) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		zephir_get_strval(name, name_param);


	ZEPHIR_CONCAT_SV(return_value, "SAVEPOINT ", name);
	RETURN_MM();

}

/**
 * Generate SQL to release a savepoint
 *
 * @param string name
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, releaseSavepoint) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		zephir_get_strval(name, name_param);


	ZEPHIR_CONCAT_SV(return_value, "RELEASE SAVEPOINT ", name);
	RETURN_MM();

}

/**
 * Generate SQL to rollback a savepoint
 *
 * @param string name
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, rollbackSavepoint) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		zephir_get_strval(name, name_param);


	ZEPHIR_CONCAT_SV(return_value, "ROLLBACK TO SAVEPOINT ", name);
	RETURN_MM();

}

