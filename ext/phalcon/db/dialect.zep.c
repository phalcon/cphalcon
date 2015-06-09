
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


/**
 * Phalcon\Db\Dialect
 *
 * This is the base class to each database dialect. This implements
 * common methods to transform intermediate code into its RDBMS related syntax
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Dialect, phalcon, db_dialect, phalcon_db_dialect_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_db_dialect_ce, SL("_escapeChar"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_db_dialect_ce, SL("_customFunctions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_dialect_ce TSRMLS_CC, 1, phalcon_db_dialectinterface_ce);
	return SUCCESS;

}

/**
 * Registers custom SQL functions
 */
PHP_METHOD(Phalcon_Db_Dialect, registerCustomFunction) {

	zval *name_param = NULL, *customFunction;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &customFunction);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("_customFunctions"), name, customFunction TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns registered functions
 */
PHP_METHOD(Phalcon_Db_Dialect, getCustomFunctions) {


	RETURN_MEMBER(this_ptr, "_customFunctions");

}

/**
 * Escape identifiers
 */
PHP_METHOD(Phalcon_Db_Dialect, escape) {

	HashTable *_7;
	HashPosition _6;
	zval *_5 = NULL;
	zend_bool _2, _9;
	zval *str_param = NULL, *escapeChar_param = NULL, *parts = NULL, *key = NULL, *part = NULL, *newParts = NULL, *_0, *_3, *_4, **_8, *_10 = NULL;
	zval *str = NULL, *escapeChar = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &escapeChar_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	if (!(ZEPHIR_GLOBAL(db).escape_identifiers)) {
		RETURN_CTOR(str);
	}
	if (ZEPHIR_IS_STRING(escapeChar, "")) {
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("_escapeChar"), PH_NOISY_CC);
		zephir_get_strval(_1, _0);
		ZEPHIR_CPY_WRT(escapeChar, _1);
	}
	if (!(zephir_memnstr_str(str, SL("."), "phalcon/db/dialect.zep", 68))) {
		_2 = !ZEPHIR_IS_STRING(escapeChar, "");
		if (_2) {
			_2 = !ZEPHIR_IS_STRING(str, "*");
		}
		if (_2) {
			ZEPHIR_CONCAT_VVV(return_value, escapeChar, str, escapeChar);
			RETURN_MM();
		}
		RETURN_CTOR(str);
	}
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_trim(_4, str, escapeChar, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_fast_explode_str(_3, SL("."), _4, LONG_MAX TSRMLS_CC);
	zephir_get_arrval(_5, _3);
	ZEPHIR_CPY_WRT(parts, _5);
	ZEPHIR_CPY_WRT(newParts, parts);
	zephir_is_iterable(parts, &_7, &_6, 0, 0, "phalcon/db/dialect.zep", 89);
	for (
	  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zephir_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HMKEY(key, _7, _6);
		ZEPHIR_GET_HVALUE(part, _8);
		_2 = ZEPHIR_IS_STRING(escapeChar, "");
		if (!(_2)) {
			_2 = ZEPHIR_IS_STRING(part, "");
		}
		_9 = _2;
		if (!(_9)) {
			_9 = ZEPHIR_IS_STRING(part, "*");
		}
		if (_9) {
			continue;
		}
		ZEPHIR_INIT_LNVAR(_10);
		ZEPHIR_CONCAT_VVV(_10, escapeChar, part, escapeChar);
		zephir_array_update_zval(&newParts, key, &_10, PH_COPY | PH_SEPARATE);
	}
	zephir_fast_join_str(return_value, SL("."), newParts TSRMLS_CC);
	RETURN_MM();

}

/**
 * Generates the SQL for LIMIT clause
 *
 * <code>
 *    $sql = $dialect->limit('SELECT * FROM robots', 10);
 *    echo $sql; // SELECT * FROM robots LIMIT 10
 *
 *    $sql = $dialect->limit('SELECT * FROM robots', [10, 50]);
 *    echo $sql; // SELECT * FROM robots LIMIT 10 OFFSET 50
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect, limit) {

	zend_bool _2;
	zval *sqlQuery_param = NULL, *number, *_0, *_1, *_3, *_4, *_5;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sqlQuery_param, &number);

	if (unlikely(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(sqlQuery);
		ZVAL_EMPTY_STRING(sqlQuery);
	}


	if (Z_TYPE_P(number) == IS_ARRAY) {
		zephir_array_fetch_long(&_0, number, 0, PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 107 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SV(_1, " LIMIT ", _0);
		zephir_concat_self(&sqlQuery, _1 TSRMLS_CC);
		_2 = zephir_array_isset_long(number, 1);
		if (_2) {
			zephir_array_fetch_long(&_3, number, 1, PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 109 TSRMLS_CC);
			_2 = (zephir_fast_strlen_ev(_3)) ? 1 : 0;
		}
		if (_2) {
			zephir_array_fetch_long(&_4, number, 1, PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 110 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_5);
			ZEPHIR_CONCAT_SV(_5, " OFFSET ", _4);
			zephir_concat_self(&sqlQuery, _5 TSRMLS_CC);
		}
		RETURN_CTOR(sqlQuery);
	}
	ZEPHIR_CONCAT_VSV(return_value, sqlQuery, " LIMIT ", number);
	RETURN_MM();

}

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 *<code>
 * $sql = $dialect->forUpdate('SELECT * FROM robots');
 * echo $sql; // SELECT * FROM robots FOR UPDATE
 *</code>
 */
PHP_METHOD(Phalcon_Db_Dialect, forUpdate) {

	zval *sqlQuery_param = NULL;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (unlikely(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(sqlQuery);
		ZVAL_EMPTY_STRING(sqlQuery);
	}


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
 */
PHP_METHOD(Phalcon_Db_Dialect, sharedLock) {

	zval *sqlQuery_param = NULL;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (unlikely(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(sqlQuery);
		ZVAL_EMPTY_STRING(sqlQuery);
	}


	ZEPHIR_CONCAT_VS(return_value, sqlQuery, " LOCK IN SHARE MODE");
	RETURN_MM();

}

/**
 * Gets a list of columns with escaped identifiers
 *
 * <code>
 *    echo $dialect->getColumnList(array('column1', 'column'));
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect, getColumnList) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *columnList_param = NULL, *columns, *column = NULL, **_2, *_3 = NULL;
	zval *columnList = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &columnList_param);

	columnList = columnList_param;



	ZEPHIR_INIT_VAR(columns);
	array_init(columns);
	zephir_is_iterable(columnList, &_1, &_0, 0, 0, "phalcon/db/dialect.zep", 161);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(column, _2);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "getsqlcolumn", &_4, 86, column);
		zephir_check_call_status();
		zephir_array_append(&columns, _3, PH_SEPARATE, "phalcon/db/dialect.zep", 158);
	}
	zephir_fast_join_str(return_value, SL(", "), columns TSRMLS_CC);
	RETURN_MM();

}

/**
 * Resolve Column expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlColumn) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_bool _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *column = NULL, *columnExpression = NULL, *columnAlias = NULL, *columnField, *columnDomain;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);

	ZEPHIR_SEPARATE_PARAM(column);


	if (Z_TYPE_P(column) != IS_ARRAY) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparequalified", NULL, 0, column);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (!(zephir_array_isset_string(column, SS("type")))) {
		ZEPHIR_OBS_VAR(columnField);
		zephir_array_fetch_long(&columnField, column, 0, PH_NOISY, "phalcon/db/dialect.zep", 180 TSRMLS_CC);
		if (Z_TYPE_P(columnField) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(columnExpression);
			zephir_create_array(columnExpression, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(columnExpression, SS("type"), SL("scalar"), 1);
			zephir_array_update_string(&columnExpression, SL("value"), &columnField, PH_COPY | PH_SEPARATE);
		} else if (ZEPHIR_IS_STRING(columnField, "*")) {
			ZEPHIR_INIT_NVAR(columnExpression);
			zephir_create_array(columnExpression, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(columnExpression, SS("type"), SL("all"), 1);
		} else {
			ZEPHIR_INIT_NVAR(columnExpression);
			zephir_create_array(columnExpression, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(columnExpression, SS("type"), SL("qualified"), 1);
			zephir_array_update_string(&columnExpression, SL("name"), &columnField, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(columnDomain);
		_0 = zephir_array_isset_long_fetch(&columnDomain, column, 1, 0 TSRMLS_CC);
		if (_0) {
			_0 = !ZEPHIR_IS_STRING(columnDomain, "");
		}
		if (_0) {
			zephir_array_update_string(&columnExpression, SL("domain"), &columnDomain, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(columnAlias);
		_1 = zephir_array_isset_long_fetch(&columnAlias, column, 2, 0 TSRMLS_CC);
		if (_1) {
			_1 = zephir_is_true(columnAlias);
		}
		if (_1) {
			zephir_array_update_string(&columnExpression, SL("sqlAlias"), &columnAlias, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_CPY_WRT(columnExpression, column);
	}
	ZEPHIR_CALL_METHOD(&column, this_ptr, "getsqlexpression", NULL, 0, columnExpression);
	zephir_check_call_status();
	ZEPHIR_OBS_NVAR(columnAlias);
	_0 = zephir_array_isset_string_fetch(&columnAlias, columnExpression, SS("sqlAlias"), 0 TSRMLS_CC);
	if (!(_0)) {
		ZEPHIR_OBS_NVAR(columnAlias);
		_0 = zephir_array_isset_string_fetch(&columnAlias, columnExpression, SS("alias"), 0 TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparecolumnalias", &_2, 0, column, columnAlias);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparecolumnalias", &_2, 0, column);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Transforms an intermediate representation for a expression into a database system valid expression
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpression) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *type, *_0, *_1 = NULL, *_2, *_3;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression_param, &escapeChar_param);

	expression = expression_param;

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	ZEPHIR_OBS_VAR(type);
	if (!(zephir_array_isset_string_fetch(&type, expression, SS("type"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL expression", "phalcon/db/dialect.zep", 240);
		return;
	}
	do {
		if (ZEPHIR_IS_STRING(type, "scalar")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionscalar", NULL, 87, expression, escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "object")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionobject", NULL, 88, expression, escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "qualified")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionqualified", NULL, 89, expression, escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "literal") || ZEPHIR_IS_STRING(type, "placeholder")) {
			zephir_array_fetch_string(&_0, expression, SL("value"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 268 TSRMLS_CC);
			RETURN_CTOR(_0);
		}
		if (ZEPHIR_IS_STRING(type, "binary-op")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionbinaryoperations", NULL, 90, expression, escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "unary-op")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionunaryoperations", NULL, 91, expression, escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "parentheses")) {
			zephir_array_fetch_string(&_0, expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 286 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_1, this_ptr, "getsqlexpression", NULL, 92, _0, escapeChar);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVS(return_value, "(", _1, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "functionCall")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionfunctioncall", NULL, 93, expression, escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "list")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionlist", NULL, 94, expression, escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "all")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionall", NULL, 95, expression, escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "select")) {
			zephir_array_fetch_string(&_0, expression, SL("value"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 310 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_1, this_ptr, "select", NULL, 0, _0);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVS(return_value, "(", _1, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "cast")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressioncastvalue", NULL, 96, expression, escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "convert")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionconvertvalue", NULL, 97, expression, escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "case")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressioncase", NULL, 98, expression, escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, phalcon_db_exception_ce);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "Invalid SQL expression type '", type, "'");
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 2, _3);
	zephir_check_call_status();
	zephir_throw_exception_debug(_2, "phalcon/db/dialect.zep", 331 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Transform an intermediate representation of a schema/table into a database system valid expression
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlTable) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *table, *escapeChar_param = NULL, *tableName, *schemaName, *aliasName;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &escapeChar_param);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	if (Z_TYPE_P(table) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(tableName);
		zephir_array_fetch_long(&tableName, table, 0, PH_NOISY, "phalcon/db/dialect.zep", 346 TSRMLS_CC);
		ZEPHIR_OBS_VAR(schemaName);
		zephir_array_isset_long_fetch(&schemaName, table, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(aliasName);
		zephir_array_isset_long_fetch(&aliasName, table, 2, 0 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparetable", NULL, 0, tableName, schemaName, aliasName, escapeChar);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", NULL, 99, table, escapeChar);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a SELECT statement
 */
PHP_METHOD(Phalcon_Db_Dialect, select) {

	zend_bool _4, _8, _9, _10, _11, _12;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *definition_param = NULL, *tables, *columns, *sql = NULL, *distinct, *joins, *where, *groupBy, *having, *orderBy, *limit, *_0 = NULL, *_1, *_2 = NULL, *_3, *_5 = NULL, *_6, *_7 = NULL;
	zval *definition = NULL, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition_param);

	definition = definition_param;



	ZEPHIR_OBS_VAR(tables);
	if (!(zephir_array_isset_string_fetch(&tables, definition, SS("tables"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'tables' is required in the definition array", "phalcon/db/dialect.zep", 373);
		return;
	}
	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array", "phalcon/db/dialect.zep", 377);
		return;
	}
	ZEPHIR_OBS_VAR(distinct);
	if (zephir_array_isset_string_fetch(&distinct, definition, SS("distinct"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(sql);
		if (zephir_is_true(distinct)) {
			ZVAL_STRING(sql, "SELECT DISTINCT", 1);
		} else {
			ZVAL_STRING(sql, "SELECT ALL", 1);
		}
	} else {
		ZEPHIR_INIT_NVAR(sql);
		ZVAL_STRING(sql, "SELECT", 1);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcolumnlist", NULL, 100, columns);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, " ", _0);
	zephir_concat_self(&sql, _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getsqlexpressionfrom", NULL, 101, tables);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, " ", _2);
	zephir_concat_self(&sql, _3 TSRMLS_CC);
	ZEPHIR_OBS_VAR(joins);
	_4 = zephir_array_isset_string_fetch(&joins, definition, SS("joins"), 0 TSRMLS_CC);
	if (_4) {
		_4 = zephir_is_true(joins);
	}
	if (_4) {
		zephir_array_fetch_string(&_6, definition, SL("joins"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 406 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "getsqlexpressionjoins", NULL, 102, _6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SV(_7, " ", _5);
		zephir_concat_self(&sql, _7 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(where);
	_8 = zephir_array_isset_string_fetch(&where, definition, SS("where"), 0 TSRMLS_CC);
	if (_8) {
		_8 = zephir_is_true(where);
	}
	if (_8) {
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "getsqlexpressionwhere", NULL, 103, where);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_SV(_7, " ", _5);
		zephir_concat_self(&sql, _7 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(groupBy);
	_9 = zephir_array_isset_string_fetch(&groupBy, definition, SS("group"), 0 TSRMLS_CC);
	if (_9) {
		_9 = zephir_is_true(groupBy);
	}
	if (_9) {
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "getsqlexpressiongroupby", NULL, 104, groupBy);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_SV(_7, " ", _5);
		zephir_concat_self(&sql, _7 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(having);
	_10 = zephir_array_isset_string_fetch(&having, definition, SS("having"), 0 TSRMLS_CC);
	if (_10) {
		_10 = zephir_is_true(having);
	}
	if (_10) {
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "getsqlexpressionhaving", NULL, 105, having);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_SV(_7, " ", _5);
		zephir_concat_self(&sql, _7 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(orderBy);
	_11 = zephir_array_isset_string_fetch(&orderBy, definition, SS("order"), 0 TSRMLS_CC);
	if (_11) {
		_11 = zephir_is_true(orderBy);
	}
	if (_11) {
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "getsqlexpressionorderby", NULL, 106, orderBy);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_SV(_7, " ", _5);
		zephir_concat_self(&sql, _7 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(limit);
	_12 = zephir_array_isset_string_fetch(&limit, definition, SS("limit"), 0 TSRMLS_CC);
	if (_12) {
		_12 = zephir_is_true(limit);
	}
	if (_12) {
		ZEPHIR_INIT_VAR(_13);
		zephir_create_array(_13, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_13, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13, SL("value"), &limit, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&sql, this_ptr, "getsqlexpressionlimit", NULL, 107, _13);
		zephir_check_call_status();
	}
	RETURN_CCTOR(sql);

}

/**
 * Checks whether the platform supports savepoints
 */
PHP_METHOD(Phalcon_Db_Dialect, supportsSavepoints) {


	RETURN_BOOL(1);

}

/**
 * Checks whether the platform supports releasing savepoints.
 */
PHP_METHOD(Phalcon_Db_Dialect, supportsReleaseSavepoints) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "supportssavepoints", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generate SQL to create a new savepoint
 */
PHP_METHOD(Phalcon_Db_Dialect, createSavepoint) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CONCAT_SV(return_value, "SAVEPOINT ", name);
	RETURN_MM();

}

/**
 * Generate SQL to release a savepoint
 */
PHP_METHOD(Phalcon_Db_Dialect, releaseSavepoint) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CONCAT_SV(return_value, "RELEASE SAVEPOINT ", name);
	RETURN_MM();

}

/**
 * Generate SQL to rollback a savepoint
 */
PHP_METHOD(Phalcon_Db_Dialect, rollbackSavepoint) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CONCAT_SV(return_value, "ROLLBACK TO SAVEPOINT ", name);
	RETURN_MM();

}

/**
 * Resolve Column expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionScalar) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *value, *_0;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression_param, &escapeChar_param);

	expression = expression_param;

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	if (zephir_array_isset_string(expression, SS("column"))) {
		zephir_array_fetch_string(&_0, expression, SL("column"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 495 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlcolumn", NULL, 86, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(value);
	if (!(zephir_array_isset_string_fetch(&value, expression, SS("value"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL expression", "phalcon/db/dialect.zep", 499);
		return;
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpression", NULL, 0, value, escapeChar);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(value);

}

/**
 * Resolve object expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionObject) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _1;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *domain = NULL, *objectExpression;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression_param, &escapeChar_param);

	expression = expression_param;

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	ZEPHIR_INIT_VAR(domain);
	ZVAL_NULL(domain);


	ZEPHIR_INIT_VAR(objectExpression);
	zephir_create_array(objectExpression, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(objectExpression, SS("type"), SL("all"), 1);
	ZEPHIR_OBS_NVAR(domain);
	_0 = zephir_array_isset_string_fetch(&domain, expression, SS("column"), 0 TSRMLS_CC);
	if (!(_0)) {
		ZEPHIR_OBS_NVAR(domain);
		_0 = zephir_array_isset_string_fetch(&domain, expression, SS("domain"), 0 TSRMLS_CC);
	}
	_1 = _0;
	if (_1) {
		_1 = !ZEPHIR_IS_STRING(domain, "");
	}
	if (_1) {
		zephir_array_update_string(&objectExpression, SL("domain"), &domain, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpression", NULL, 0, objectExpression, escapeChar);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Resolve qualified expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionQualified) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *column, *domain = NULL;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression_param, &escapeChar_param);

	expression = expression_param;

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	ZEPHIR_OBS_VAR(column);
	zephir_array_fetch_string(&column, expression, SL("name"), PH_NOISY, "phalcon/db/dialect.zep", 533 TSRMLS_CC);
	ZEPHIR_OBS_VAR(domain);
	if (!(zephir_array_isset_string_fetch(&domain, expression, SS("domain"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(domain);
		ZVAL_NULL(domain);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparequalified", NULL, 0, column, domain, escapeChar);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Resolve binary operations expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionBinaryOperations) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *left = NULL, *right = NULL, *_0, *_2, *_3;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression_param, &escapeChar_param);

	expression = expression_param;

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	zephir_array_fetch_string(&_0, expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 552 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", &_1, 0, _0, escapeChar);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, expression, SL("right"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 553 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", &_1, 92, _2, escapeChar);
	zephir_check_call_status();
	zephir_array_fetch_string(&_3, expression, SL("op"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 555 TSRMLS_CC);
	ZEPHIR_CONCAT_VSVSV(return_value, left, " ", _3, " ", right);
	RETURN_MM();

}

/**
 * Resolve unary operations expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionUnaryOperations) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *left, *right, *_0 = NULL, *_2;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression_param, &escapeChar_param);

	expression = expression_param;

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	ZEPHIR_OBS_VAR(left);
	if (zephir_array_isset_string_fetch(&left, expression, SS("left"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsqlexpression", &_1, 0, left, escapeChar);
		zephir_check_call_status();
		zephir_array_fetch_string(&_2, expression, SL("op"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 569 TSRMLS_CC);
		ZEPHIR_CONCAT_VSV(return_value, _0, " ", _2);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(right);
	if (zephir_array_isset_string_fetch(&right, expression, SS("right"), 0 TSRMLS_CC)) {
		zephir_array_fetch_string(&_2, expression, SL("op"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 576 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsqlexpression", &_1, 92, right, escapeChar);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSV(return_value, _2, " ", _0);
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-unary expression", "phalcon/db/dialect.zep", 579);
	return;

}

/**
 * Resolve function calls
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionFunctionCall) {

	zend_bool _1, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *name, *customFunction, *arguments = NULL, *_0, *_4;
	zval *expression = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression_param, &escapeChar_param);

	expression = expression_param;

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	ZEPHIR_OBS_VAR(name);
	zephir_array_fetch_string(&name, expression, SL("name"), PH_NOISY, "phalcon/db/dialect.zep", 589 TSRMLS_CC);
	ZEPHIR_OBS_VAR(customFunction);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_customFunctions"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&customFunction, _0, name, 0 TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(customFunction, NULL, 0, this_ptr, expression, escapeChar);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(arguments);
	_1 = zephir_array_isset_string_fetch(&arguments, expression, SS("arguments"), 0 TSRMLS_CC);
	if (_1) {
		_1 = Z_TYPE_P(arguments) == IS_ARRAY;
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_2);
		zephir_create_array(_2, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_2, SS("type"), SL("list"), 1);
		zephir_array_update_string(&_2, SL("parentheses"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_2, SL("value"), &arguments, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&arguments, this_ptr, "getsqlexpression", NULL, 0, _2, escapeChar);
		zephir_check_call_status();
		_3 = zephir_array_isset_string(expression, SS("distinct"));
		if (_3) {
			zephir_array_fetch_string(&_4, expression, SL("distinct"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 603 TSRMLS_CC);
			_3 = zephir_is_true(_4);
		}
		if (_3) {
			ZEPHIR_CONCAT_VSVS(return_value, name, "(DISTINCT ", arguments, ")");
			RETURN_MM();
		}
		ZEPHIR_CONCAT_VSVS(return_value, name, "(", arguments, ")");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_VS(return_value, name, "()");
	RETURN_MM();

}

/**
 * Resolve Lists
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionList) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_3;
	HashPosition _2;
	zend_bool _0, _1, _7;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *items, *item = NULL, *values = NULL, *separator = NULL, **_4, *_5 = NULL, *_8, *_9;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression_param, &escapeChar_param);

	expression = expression_param;

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	ZEPHIR_INIT_VAR(items);
	array_init(items);
	ZEPHIR_INIT_VAR(separator);
	ZVAL_STRING(separator, ", ", 1);
	if (zephir_array_isset_string(expression, SS("separator"))) {
		ZEPHIR_OBS_NVAR(separator);
		zephir_array_fetch_string(&separator, expression, SL("separator"), PH_NOISY, "phalcon/db/dialect.zep", 624 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(values);
	_0 = zephir_array_isset_long_fetch(&values, expression, 0, 0 TSRMLS_CC);
	if (!(_0)) {
		ZEPHIR_OBS_NVAR(values);
		_0 = zephir_array_isset_string_fetch(&values, expression, SS("value"), 0 TSRMLS_CC);
	}
	_1 = _0;
	if (_1) {
		_1 = Z_TYPE_P(values) == IS_ARRAY;
	}
	if (_1) {
		zephir_is_iterable(values, &_3, &_2, 0, 0, "phalcon/db/dialect.zep", 633);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(item, _4);
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "getsqlexpression", &_6, 0, item, escapeChar);
			zephir_check_call_status();
			zephir_array_append(&items, _5, PH_SEPARATE, "phalcon/db/dialect.zep", 630);
		}
		_7 = zephir_array_isset_string(expression, SS("parentheses"));
		if (_7) {
			zephir_array_fetch_string(&_8, expression, SL("parentheses"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 633 TSRMLS_CC);
			_7 = ZEPHIR_IS_FALSE_IDENTICAL(_8);
		}
		if (_7) {
			zephir_fast_join(return_value, separator, items TSRMLS_CC);
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(_9);
		zephir_fast_join(_9, separator, items TSRMLS_CC);
		ZEPHIR_CONCAT_SVS(return_value, "(", _9, ")");
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-list expression", "phalcon/db/dialect.zep", 640);
	return;

}

/**
 * Resolve *
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *domain, *_0;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression_param, &escapeChar_param);

	expression = expression_param;

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	ZEPHIR_OBS_VAR(domain);
	zephir_array_isset_string_fetch(&domain, expression, SS("domain"), 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "*", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparequalified", NULL, 0, _0, domain, escapeChar);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Resolve CAST of values
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionCastValue) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *left = NULL, *right = NULL, *_0, *_2;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression_param, &escapeChar_param);

	expression = expression_param;

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	zephir_array_fetch_string(&_0, expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 662 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", &_1, 0, _0, escapeChar);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, expression, SL("right"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 663 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", &_1, 92, _2, escapeChar);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "CAST(", left, " AS ", right, ")");
	RETURN_MM();

}

/**
 * Resolve CONVERT of values encodings
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionConvertValue) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *left = NULL, *right = NULL, *_0, *_2;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression_param, &escapeChar_param);

	expression = expression_param;

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	zephir_array_fetch_string(&_0, expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 675 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", &_1, 0, _0, escapeChar);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, expression, SL("right"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 676 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", &_1, 92, _2, escapeChar);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "CONVERT(", left, " USING ", right, ")");
	RETURN_MM();

}

/**
 * Resolve CASE expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionCase) {

	HashTable *_5;
	HashPosition _4;
	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *sql, *whenClause = NULL, *_0 = NULL, *_1, *_3, **_6, *_7, *_8 = NULL, *_9, *_10 = NULL, *_11, *_12 = NULL;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression_param, &escapeChar_param);

	expression = expression_param;

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	zephir_array_fetch_string(&_1, expression, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 688 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsqlexpression", &_2, 0, _1, escapeChar);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SV(sql, "CASE ", _0);
	zephir_array_fetch_string(&_3, expression, SL("when-clauses"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 690 TSRMLS_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "phalcon/db/dialect.zep", 701);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(whenClause, _6);
		zephir_array_fetch_string(&_7, whenClause, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 691 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_7, "when")) {
			zephir_array_fetch_string(&_9, whenClause, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 693 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_8, this_ptr, "getsqlexpression", &_2, 92, _9, escapeChar);
			zephir_check_call_status();
			zephir_array_fetch_string(&_11, whenClause, SL("then"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 695 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10, this_ptr, "getsqlexpression", &_2, 92, _11, escapeChar);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_12);
			ZEPHIR_CONCAT_SVSV(_12, " WHEN ", _8, " THEN ", _10);
			zephir_concat_self(&sql, _12 TSRMLS_CC);
		} else {
			zephir_array_fetch_string(&_9, whenClause, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 697 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_8, this_ptr, "getsqlexpression", &_2, 92, _9, escapeChar);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_12);
			ZEPHIR_CONCAT_SV(_12, " ELSE ", _8);
			zephir_concat_self(&sql, _12 TSRMLS_CC);
		}
	}
	ZEPHIR_CONCAT_VS(return_value, sql, " END");
	RETURN_MM();

}

/**
 * Resolve a FROM clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionFrom) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *escapeChar = NULL;
	zval *expression, *escapeChar_param = NULL, *table = NULL, *tables = NULL, **_2, *_3 = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression, &escapeChar_param);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(tables);
		array_init(tables);
		zephir_is_iterable(expression, &_1, &_0, 0, 0, "phalcon/db/dialect.zep", 719);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(table, _2);
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "getsqltable", &_4, 108, table, escapeChar);
			zephir_check_call_status();
			zephir_array_append(&tables, _3, PH_SEPARATE, "phalcon/db/dialect.zep", 716);
		}
		ZEPHIR_INIT_VAR(_5);
		zephir_fast_join_str(_5, SL(", "), tables TSRMLS_CC);
		ZEPHIR_CPY_WRT(tables, _5);
	} else {
		ZEPHIR_CPY_WRT(tables, expression);
	}
	ZEPHIR_CONCAT_SV(return_value, "FROM ", tables);
	RETURN_MM();

}

/**
 * Resolve a JOINs clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionJoins) {

	zephir_fcall_cache_entry *_4 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _3, _10;
	HashTable *_1, *_6;
	HashPosition _0, _5;
	zval *escapeChar = NULL;
	zval *expression, *escapeChar_param = NULL, *join = NULL, *sql, *joinCondition = NULL, *joinTable = NULL, *joinType = NULL, *joinConditionsArray = NULL, **_2, *condition = NULL, **_7, *_8 = NULL, *_9 = NULL, *_11, *_13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression, &escapeChar_param);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "", 1);
	ZEPHIR_INIT_VAR(joinType);
	ZVAL_STRING(joinType, "", 1);


	zephir_is_iterable(expression, &_1, &_0, 0, 0, "phalcon/db/dialect.zep", 768);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(join, _2);
		ZEPHIR_OBS_NVAR(joinConditionsArray);
		_3 = zephir_array_isset_string_fetch(&joinConditionsArray, join, SS("conditions"), 0 TSRMLS_CC);
		if (_3) {
			_3 = !(ZEPHIR_IS_EMPTY(joinConditionsArray));
		}
		if (_3) {
			if (!(zephir_array_isset_long(joinConditionsArray, 0))) {
				ZEPHIR_CALL_METHOD(&joinCondition, this_ptr, "getsqlexpression", &_4, 0, joinConditionsArray, escapeChar);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(joinCondition);
				array_init(joinCondition);
				zephir_is_iterable(joinConditionsArray, &_6, &_5, 0, 0, "phalcon/db/dialect.zep", 753);
				for (
				  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
				  ; zephir_hash_move_forward_ex(_6, &_5)
				) {
					ZEPHIR_GET_HVALUE(condition, _7);
					ZEPHIR_CALL_METHOD(&_8, this_ptr, "getsqlexpression", &_4, 92, condition, escapeChar);
					zephir_check_call_status();
					zephir_array_append(&joinCondition, _8, PH_SEPARATE, "phalcon/db/dialect.zep", 750);
				}
				ZEPHIR_INIT_NVAR(_9);
				zephir_fast_join_str(_9, SL(" AND "), joinCondition TSRMLS_CC);
				ZEPHIR_CPY_WRT(joinCondition, _9);
			}
		} else {
			ZEPHIR_INIT_NVAR(joinCondition);
			ZVAL_LONG(joinCondition, 1);
		}
		ZEPHIR_OBS_NVAR(joinType);
		_10 = zephir_array_isset_string_fetch(&joinType, join, SS("type"), 0 TSRMLS_CC);
		if (_10) {
			_10 = zephir_is_true(joinType);
		}
		if (_10) {
			zephir_concat_self_str(&joinType, SL(" ") TSRMLS_CC);
		}
		zephir_array_fetch_string(&_11, join, SL("source"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 763 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&joinTable, this_ptr, "getsqltable", &_12, 108, _11, escapeChar);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_13);
		ZEPHIR_CONCAT_SVSVSV(_13, " ", joinType, "JOIN ", joinTable, " ON ", joinCondition);
		zephir_concat_self(&sql, _13 TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Resolve a WHERE clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionWhere) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression, *escapeChar_param = NULL, *whereSql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression, &escapeChar_param);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&whereSql, this_ptr, "getsqlexpression", NULL, 0, expression, escapeChar);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(whereSql, expression);
	}
	ZEPHIR_CONCAT_SV(return_value, "WHERE ", whereSql);
	RETURN_MM();

}

/**
 * Resolve a GROUP BY clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionGroupBy) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *escapeChar = NULL;
	zval *expression, *escapeChar_param = NULL, *filed = NULL, *fields = NULL, **_2, *_3 = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression, &escapeChar_param);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
		zephir_is_iterable(expression, &_1, &_0, 0, 0, "phalcon/db/dialect.zep", 806);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(filed, _2);
			if (unlikely(Z_TYPE_P(filed) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-GROUP-BY expression", "phalcon/db/dialect.zep", 800);
				return;
			} else {
				ZEPHIR_CALL_METHOD(&_3, this_ptr, "getsqlexpression", &_4, 0, filed, escapeChar);
				zephir_check_call_status();
				zephir_array_append(&fields, _3, PH_SEPARATE, "phalcon/db/dialect.zep", 802);
			}
		}
		ZEPHIR_INIT_VAR(_5);
		zephir_fast_join_str(_5, SL(", "), fields TSRMLS_CC);
		ZEPHIR_CPY_WRT(fields, _5);
	} else {
		ZEPHIR_CPY_WRT(fields, expression);
	}
	ZEPHIR_CONCAT_SV(return_value, "GROUP BY ", fields);
	RETURN_MM();

}

/**
 * Resolve a HAVING clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionHaving) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression, *escapeChar_param = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression, &escapeChar_param);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsqlexpression", NULL, 0, expression, escapeChar);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SV(return_value, "HAVING ", _0);
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-HAVING expression", "phalcon/db/dialect.zep", 824);
	return;

}

/**
 * Resolve a ORDER BY clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionOrderBy) {

	zend_bool _5;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *escapeChar = NULL;
	zval *expression, *escapeChar_param = NULL, *filed = NULL, *fields = NULL, *type = NULL, *fieldSql = NULL, **_2, *_3, *_6 = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression, &escapeChar_param);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	ZEPHIR_INIT_VAR(fieldSql);
	ZVAL_NULL(fieldSql);


	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
		zephir_is_iterable(expression, &_1, &_0, 0, 0, "phalcon/db/dialect.zep", 856);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(filed, _2);
			if (unlikely(Z_TYPE_P(filed) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-ORDER-BY expression", "phalcon/db/dialect.zep", 841);
				return;
			} else {
				zephir_array_fetch_long(&_3, filed, 0, PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 843 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&fieldSql, this_ptr, "getsqlexpression", &_4, 0, _3, escapeChar);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(type);
			_5 = zephir_array_isset_long_fetch(&type, filed, 1, 0 TSRMLS_CC);
			if (_5) {
				_5 = !ZEPHIR_IS_STRING(type, "");
			}
			if (_5) {
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SV(_6, " ", type);
				zephir_concat_self(&fieldSql, _6 TSRMLS_CC);
			}
			zephir_array_append(&fields, fieldSql, PH_SEPARATE, "phalcon/db/dialect.zep", 853);
		}
		ZEPHIR_INIT_VAR(_7);
		zephir_fast_join_str(_7, SL(", "), fields TSRMLS_CC);
		ZEPHIR_CPY_WRT(fields, _7);
	} else {
		ZEPHIR_CPY_WRT(fields, expression);
	}
	ZEPHIR_CONCAT_SV(return_value, "ORDER BY ", fields);
	RETURN_MM();

}

/**
 * Resolve a LIMIT clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionLimit) {

	zval *_5;
	zend_bool _3;
	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression, *escapeChar_param = NULL, *sql = NULL, *value, *limit = NULL, *offset = NULL, *_0, *_1, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression, &escapeChar_param);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "", 1);
	ZEPHIR_INIT_VAR(offset);
	ZVAL_NULL(offset);


	ZEPHIR_OBS_VAR(value);
	zephir_array_fetch_string(&value, expression, SL("value"), PH_NOISY, "phalcon/db/dialect.zep", 871 TSRMLS_CC);
	if (zephir_array_isset_string(expression, SS("sql"))) {
		ZEPHIR_OBS_NVAR(sql);
		zephir_array_fetch_string(&sql, expression, SL("sql"), PH_NOISY, "phalcon/db/dialect.zep", 874 TSRMLS_CC);
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(_0);
		zephir_array_fetch_string(&_0, value, SL("number"), PH_NOISY, "phalcon/db/dialect.zep", 879 TSRMLS_CC);
		if (Z_TYPE_P(_0) == IS_ARRAY) {
			zephir_array_fetch_string(&_1, value, SL("number"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 880 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&limit, this_ptr, "getsqlexpression", &_2, 0, _1);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(limit);
			zephir_array_fetch_string(&limit, value, SL("number"), PH_NOISY, "phalcon/db/dialect.zep", 882 TSRMLS_CC);
		}
		ZEPHIR_OBS_NVAR(offset);
		_3 = zephir_array_isset_string_fetch(&offset, value, SS("offset"), 0 TSRMLS_CC);
		if (_3) {
			_3 = Z_TYPE_P(offset) == IS_ARRAY;
		}
		if (_3) {
			ZEPHIR_CALL_METHOD(&_4, this_ptr, "getsqlexpression", &_2, 92, offset);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(offset, _4);
		}
	} else {
		ZEPHIR_CPY_WRT(limit, value);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_5, limit);
	zephir_array_fast_append(_5, offset);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "limit", NULL, 0, sql, _5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prepares column for this RDBMS
 */
PHP_METHOD(Phalcon_Db_Dialect, prepareColumnAlias) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *qualified_param = NULL, *alias_param = NULL, *_0 = NULL;
	zval *qualified = NULL, *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &qualified_param, &alias_param);

	if (unlikely(Z_TYPE_P(qualified_param) != IS_STRING && Z_TYPE_P(qualified_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'qualified' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(qualified_param) == IS_STRING)) {
		zephir_get_strval(qualified, qualified_param);
	} else {
		ZEPHIR_INIT_VAR(qualified);
		ZVAL_EMPTY_STRING(qualified);
	}
	if (!alias_param) {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	} else {
		zephir_get_strval(alias, alias_param);
	}


	if (!ZEPHIR_IS_STRING(alias, "")) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "escape", NULL, 99, alias);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSV(return_value, qualified, " AS ", _0);
		RETURN_MM();
	} else {
		RETURN_CTOR(qualified);
	}

}

/**
 * Prepares table for this RDBMS
 */
PHP_METHOD(Phalcon_Db_Dialect, prepareTable) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *alias_param = NULL, *escapeChar_param = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL;
	zval *table = NULL, *schema = NULL, *alias = NULL, *escapeChar = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &table_param, &schema_param, &alias_param, &escapeChar_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
		zephir_get_strval(schema, schema_param);
	}
	if (!alias_param) {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	} else {
		zephir_get_strval(alias, alias_param);
	}
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "escape", &_1, 99, table, escapeChar);
	zephir_check_call_status();
	zephir_get_strval(table, _0);
	if (!ZEPHIR_IS_STRING(schema, "")) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "escape", &_1, 99, schema, escapeChar);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_VSV(_3, _2, ".", table);
		zephir_get_strval(table, _3);
	}
	if (!ZEPHIR_IS_STRING(alias, "")) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "escape", &_1, 99, alias, escapeChar);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_VSV(_3, table, " AS ", _2);
		zephir_get_strval(table, _3);
	}
	RETURN_CTOR(table);

}

/**
 * Prepares qualified for this RDBMS
 */
PHP_METHOD(Phalcon_Db_Dialect, prepareQualified) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *column_param = NULL, *domain_param = NULL, *escapeChar_param = NULL;
	zval *column = NULL, *domain = NULL, *escapeChar = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &column_param, &domain_param, &escapeChar_param);

	if (unlikely(Z_TYPE_P(column_param) != IS_STRING && Z_TYPE_P(column_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'column' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(column_param) == IS_STRING)) {
		zephir_get_strval(column, column_param);
	} else {
		ZEPHIR_INIT_VAR(column);
		ZVAL_EMPTY_STRING(column);
	}
	if (!domain_param) {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_EMPTY_STRING(domain);
	} else {
		zephir_get_strval(domain, domain_param);
	}
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	if (!ZEPHIR_IS_STRING(domain, "")) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VSV(_0, domain, ".", column);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", &_1, 99, _0, escapeChar);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", &_1, 99, column, escapeChar);
	zephir_check_call_status();
	RETURN_MM();

}

