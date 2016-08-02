
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
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/array.h"
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
 * Escape Schema
 */
PHP_METHOD(Phalcon_Db_Dialect, escapeSchema) {

	zval *str_param = NULL, *escapeChar_param = NULL, *_0$$4, *_2;
	zval *str = NULL, *escapeChar = NULL, *_1$$4 = NULL;

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
		ZEPHIR_OBS_VAR(_0$$4);
		zephir_read_property_this(&_0$$4, this_ptr, SL("_escapeChar"), PH_NOISY_CC);
		zephir_get_strval(_1$$4, _0$$4);
		ZEPHIR_CPY_WRT(escapeChar, _1$$4);
	}
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_trim(_2, str, escapeChar, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CONCAT_VVV(return_value, escapeChar, _2, escapeChar);
	RETURN_MM();

}

/**
 * Escape identifiers
 */
PHP_METHOD(Phalcon_Db_Dialect, escape) {

	zend_bool _2$$5, _9$$7, _10$$7;
	HashTable *_7;
	HashPosition _6;
	zval *_5 = NULL;
	zval *str_param = NULL, *escapeChar_param = NULL, *parts = NULL, *key = NULL, *part = NULL, *newParts = NULL, *_3, *_4, **_8, *_0$$4, *_11$$7 = NULL;
	zval *str = NULL, *escapeChar = NULL, *_1$$4 = NULL;

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
		ZEPHIR_OBS_VAR(_0$$4);
		zephir_read_property_this(&_0$$4, this_ptr, SL("_escapeChar"), PH_NOISY_CC);
		zephir_get_strval(_1$$4, _0$$4);
		ZEPHIR_CPY_WRT(escapeChar, _1$$4);
	}
	if (!(zephir_memnstr_str(str, SL("."), "phalcon/db/dialect.zep", 84))) {
		_2$$5 = !ZEPHIR_IS_STRING(escapeChar, "");
		if (_2$$5) {
			_2$$5 = !ZEPHIR_IS_STRING(str, "*");
		}
		if (_2$$5) {
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
	zephir_is_iterable(parts, &_7, &_6, 0, 0, "phalcon/db/dialect.zep", 105);
	for (
	  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zephir_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HMKEY(key, _7, _6);
		ZEPHIR_GET_HVALUE(part, _8);
		_9$$7 = ZEPHIR_IS_STRING(escapeChar, "");
		if (!(_9$$7)) {
			_9$$7 = ZEPHIR_IS_STRING(part, "");
		}
		_10$$7 = _9$$7;
		if (!(_10$$7)) {
			_10$$7 = ZEPHIR_IS_STRING(part, "*");
		}
		if (_10$$7) {
			continue;
		}
		ZEPHIR_INIT_LNVAR(_11$$7);
		ZEPHIR_CONCAT_VVV(_11$$7, escapeChar, part, escapeChar);
		zephir_array_update_zval(&newParts, key, &_11$$7, PH_COPY | PH_SEPARATE);
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

	zend_bool _2$$3;
	zval *sqlQuery_param = NULL, *number, *_0$$3, *_1$$3, *_3$$3, *_4$$4, *_5$$4;
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
		zephir_array_fetch_long(&_0$$3, number, 0, PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 123 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SV(_1$$3, " LIMIT ", _0$$3);
		zephir_concat_self(&sqlQuery, _1$$3 TSRMLS_CC);
		_2$$3 = zephir_array_isset_long(number, 1);
		if (_2$$3) {
			zephir_array_fetch_long(&_3$$3, number, 1, PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 125 TSRMLS_CC);
			_2$$3 = (zephir_fast_strlen_ev(_3$$3)) ? 1 : 0;
		}
		if (_2$$3) {
			zephir_array_fetch_long(&_4$$4, number, 1, PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 126 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_5$$4);
			ZEPHIR_CONCAT_SV(_5$$4, " OFFSET ", _4$$4);
			zephir_concat_self(&sqlQuery, _5$$4 TSRMLS_CC);
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

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *columnList_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, *columns = NULL, *column = NULL, **_2, *_3$$3 = NULL;
	zval *columnList = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &columnList_param, &escapeChar_param, &bindCounts);

	columnList = columnList_param;
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(columns);
	array_init(columns);
	zephir_is_iterable(columnList, &_1, &_0, 0, 0, "phalcon/db/dialect.zep", 177);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(column, _2);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "getsqlcolumn", &_4, 40, column, escapeChar, bindCounts);
		zephir_check_call_status();
		zephir_array_append(&columns, _3$$3, PH_SEPARATE, "phalcon/db/dialect.zep", 174);
	}
	zephir_fast_join_str(return_value, SL(", "), columns TSRMLS_CC);
	RETURN_MM();

}

/**
 * Resolve Column expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlColumn) {

	zend_bool _3, _1$$4, _2$$4;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *column = NULL, *escapeChar_param = NULL, *bindCounts = NULL, *columnExpression = NULL, *columnAlias = NULL, *columnField = NULL, *columnDomain = NULL, *_5, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &column, &escapeChar_param, &bindCounts);

	ZEPHIR_SEPARATE_PARAM(column);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(column) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_NULL(_0$$3);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparequalified", NULL, 0, column, _0$$3, escapeChar);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (!(zephir_array_isset_string(column, SS("type")))) {
		ZEPHIR_OBS_VAR(columnField);
		zephir_array_fetch_long(&columnField, column, 0, PH_NOISY, "phalcon/db/dialect.zep", 196 TSRMLS_CC);
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
		_1$$4 = zephir_array_isset_long_fetch(&columnDomain, column, 1, 0 TSRMLS_CC);
		if (_1$$4) {
			_1$$4 = !ZEPHIR_IS_STRING(columnDomain, "");
		}
		if (_1$$4) {
			zephir_array_update_string(&columnExpression, SL("domain"), &columnDomain, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(columnAlias);
		_2$$4 = zephir_array_isset_long_fetch(&columnAlias, column, 2, 0 TSRMLS_CC);
		if (_2$$4) {
			_2$$4 = zephir_is_true(columnAlias);
		}
		if (_2$$4) {
			zephir_array_update_string(&columnExpression, SL("sqlAlias"), &columnAlias, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_CPY_WRT(columnExpression, column);
	}
	ZEPHIR_CALL_METHOD(&column, this_ptr, "getsqlexpression", NULL, 0, columnExpression, escapeChar, bindCounts);
	zephir_check_call_status();
	ZEPHIR_OBS_NVAR(columnAlias);
	_3 = zephir_array_isset_string_fetch(&columnAlias, columnExpression, SS("sqlAlias"), 0 TSRMLS_CC);
	if (!(_3)) {
		ZEPHIR_OBS_NVAR(columnAlias);
		_3 = zephir_array_isset_string_fetch(&columnAlias, columnExpression, SS("alias"), 0 TSRMLS_CC);
	}
	if (_3) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparecolumnalias", &_4, 0, column, columnAlias, escapeChar);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_5);
	ZVAL_NULL(_5);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparecolumnalias", &_4, 0, column, _5, escapeChar);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Transforms an intermediate representation for a expression into a database system valid expression
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpression) {

	zend_bool _1$$9;
	int ZEPHIR_LAST_CALL_STATUS, i = 0, _2$$9;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, *type = NULL, *times = NULL, *postTimes = NULL, *placeholders = NULL, *rawValue = NULL, *value = NULL, *_11, *_12, *_0$$7, *_3$$9 = NULL, _4$$11 = zval_used_for_init, *_5$$11 = NULL, *_6$$8, *_7$$14 = NULL, *_8$$14, *_9$$18 = NULL, *_10$$18;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	expression = expression_param;
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(type);
	if (!(zephir_array_isset_string_fetch(&type, expression, SS("type"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL expression", "phalcon/db/dialect.zep", 257);
		return;
	}
	do {
		if (ZEPHIR_IS_STRING(type, "scalar")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionscalar", NULL, 41, expression, escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "object")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionobject", NULL, 42, expression, escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "qualified")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionqualified", NULL, 43, expression, escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "literal")) {
			zephir_array_fetch_string(&_0$$7, expression, SL("value"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 284 TSRMLS_CC);
			RETURN_CTOR(_0$$7);
		}
		if (ZEPHIR_IS_STRING(type, "placeholder")) {
			ZEPHIR_OBS_VAR(times);
			if (zephir_array_isset_string_fetch(&times, expression, SS("times"), 0 TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(placeholders);
				array_init(placeholders);
				ZEPHIR_OBS_VAR(rawValue);
				zephir_array_fetch_string(&rawValue, expression, SL("rawValue"), PH_NOISY, "phalcon/db/dialect.zep", 290 TSRMLS_CC);
				ZEPHIR_OBS_VAR(value);
				zephir_array_fetch_string(&value, expression, SL("value"), PH_NOISY, "phalcon/db/dialect.zep", 291 TSRMLS_CC);
				ZEPHIR_OBS_VAR(postTimes);
				if (zephir_array_isset_fetch(&postTimes, bindCounts, rawValue, 0 TSRMLS_CC)) {
					ZEPHIR_CPY_WRT(times, postTimes);
				}
				ZEPHIR_CPY_WRT(_3$$9, times);
				_2$$9 = 1;
				_1$$9 = 0;
				if (ZEPHIR_GE_LONG(_3$$9, _2$$9)) {
					while (1) {
						if (_1$$9) {
							_2$$9++;
							if (!(ZEPHIR_GE_LONG(_3$$9, _2$$9))) {
								break;
							}
						} else {
							_1$$9 = 1;
						}
						i = _2$$9;
						ZEPHIR_SINIT_NVAR(_4$$11);
						ZVAL_LONG(&_4$$11, ((i - 1)));
						ZEPHIR_INIT_LNVAR(_5$$11);
						ZEPHIR_CONCAT_VV(_5$$11, value, &_4$$11);
						zephir_array_append(&placeholders, _5$$11, PH_SEPARATE, "phalcon/db/dialect.zep", 298);
					}
				}
				zephir_fast_join_str(return_value, SL(", "), placeholders TSRMLS_CC);
				RETURN_MM();
			}
			zephir_array_fetch_string(&_6$$8, expression, SL("value"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 303 TSRMLS_CC);
			RETURN_CTOR(_6$$8);
		}
		if (ZEPHIR_IS_STRING(type, "binary-op")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionbinaryoperations", NULL, 44, expression, escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "unary-op")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionunaryoperations", NULL, 45, expression, escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "parentheses")) {
			zephir_array_fetch_string(&_8$$14, expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 321 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_7$$14, this_ptr, "getsqlexpression", NULL, 46, _8$$14, escapeChar, bindCounts);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVS(return_value, "(", _7$$14, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "functionCall")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionfunctioncall", NULL, 47, expression, escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "list")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionlist", NULL, 48, expression, escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "all")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionall", NULL, 49, expression, escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "select")) {
			zephir_array_fetch_string(&_10$$18, expression, SL("value"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 345 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_9$$18, this_ptr, "select", NULL, 0, _10$$18);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVS(return_value, "(", _9$$18, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "cast")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressioncastvalue", NULL, 50, expression, escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "convert")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionconvertvalue", NULL, 51, expression, escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "case")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressioncase", NULL, 52, expression, escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_INIT_VAR(_11);
	object_init_ex(_11, phalcon_db_exception_ce);
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_CONCAT_SVS(_12, "Invalid SQL expression type '", type, "'");
	ZEPHIR_CALL_METHOD(NULL, _11, "__construct", NULL, 9, _12);
	zephir_check_call_status();
	zephir_throw_exception_debug(_11, "phalcon/db/dialect.zep", 366 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Transform an intermediate representation of a schema/table into a database system valid expression
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlTable) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *table, *escapeChar_param = NULL, *tableName = NULL, *schemaName = NULL, *aliasName = NULL;

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
		zephir_array_fetch_long(&tableName, table, 0, PH_NOISY, "phalcon/db/dialect.zep", 381 TSRMLS_CC);
		ZEPHIR_OBS_VAR(schemaName);
		zephir_array_isset_long_fetch(&schemaName, table, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(aliasName);
		zephir_array_isset_long_fetch(&aliasName, table, 2, 0 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparetable", NULL, 0, tableName, schemaName, aliasName, escapeChar);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", NULL, 53, table, escapeChar);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a SELECT statement
 */
PHP_METHOD(Phalcon_Db_Dialect, select) {

	zend_bool _4, _8, _11, _14, _17, _20, _22;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *definition_param = NULL, *tables = NULL, *columns = NULL, *sql = NULL, *distinct = NULL, *joins = NULL, *where = NULL, *escapeChar = NULL, *groupBy = NULL, *having = NULL, *orderBy = NULL, *limit = NULL, *forUpdate = NULL, *bindCounts = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, *_5$$9 = NULL, *_6$$9, *_7$$9, *_9$$10 = NULL, *_10$$10, *_12$$11 = NULL, *_13$$11, *_15$$12 = NULL, *_16$$12, *_18$$13 = NULL, *_19$$13;
	zval *definition = NULL, *_21$$14;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition_param);

	definition = definition_param;


	ZEPHIR_OBS_VAR(tables);
	if (!(zephir_array_isset_string_fetch(&tables, definition, SS("tables"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'tables' is required in the definition array", "phalcon/db/dialect.zep", 408);
		return;
	}
	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array", "phalcon/db/dialect.zep", 412);
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
	ZEPHIR_OBS_VAR(bindCounts);
	zephir_array_isset_string_fetch(&bindCounts, definition, SS("bindCounts"), 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(escapeChar);
	zephir_read_property_this(&escapeChar, this_ptr, SL("_escapeChar"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcolumnlist", NULL, 54, columns, escapeChar, bindCounts);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, " ", _0);
	zephir_concat_self(&sql, _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getsqlexpressionfrom", NULL, 55, tables, escapeChar);
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
		zephir_array_fetch_string(&_6$$9, definition, SL("joins"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 445 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_5$$9, this_ptr, "getsqlexpressionjoins", NULL, 56, _6$$9, escapeChar, bindCounts);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7$$9);
		ZEPHIR_CONCAT_SV(_7$$9, " ", _5$$9);
		zephir_concat_self(&sql, _7$$9 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(where);
	_8 = zephir_array_isset_string_fetch(&where, definition, SS("where"), 0 TSRMLS_CC);
	if (_8) {
		_8 = zephir_is_true(where);
	}
	if (_8) {
		ZEPHIR_CALL_METHOD(&_9$$10, this_ptr, "getsqlexpressionwhere", NULL, 57, where, escapeChar, bindCounts);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_10$$10);
		ZEPHIR_CONCAT_SV(_10$$10, " ", _9$$10);
		zephir_concat_self(&sql, _10$$10 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(groupBy);
	_11 = zephir_array_isset_string_fetch(&groupBy, definition, SS("group"), 0 TSRMLS_CC);
	if (_11) {
		_11 = zephir_is_true(groupBy);
	}
	if (_11) {
		ZEPHIR_CALL_METHOD(&_12$$11, this_ptr, "getsqlexpressiongroupby", NULL, 58, groupBy, escapeChar);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_13$$11);
		ZEPHIR_CONCAT_SV(_13$$11, " ", _12$$11);
		zephir_concat_self(&sql, _13$$11 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(having);
	_14 = zephir_array_isset_string_fetch(&having, definition, SS("having"), 0 TSRMLS_CC);
	if (_14) {
		_14 = zephir_is_true(having);
	}
	if (_14) {
		ZEPHIR_CALL_METHOD(&_15$$12, this_ptr, "getsqlexpressionhaving", NULL, 59, having, escapeChar, bindCounts);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_16$$12);
		ZEPHIR_CONCAT_SV(_16$$12, " ", _15$$12);
		zephir_concat_self(&sql, _16$$12 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(orderBy);
	_17 = zephir_array_isset_string_fetch(&orderBy, definition, SS("order"), 0 TSRMLS_CC);
	if (_17) {
		_17 = zephir_is_true(orderBy);
	}
	if (_17) {
		ZEPHIR_CALL_METHOD(&_18$$13, this_ptr, "getsqlexpressionorderby", NULL, 60, orderBy, escapeChar, bindCounts);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_19$$13);
		ZEPHIR_CONCAT_SV(_19$$13, " ", _18$$13);
		zephir_concat_self(&sql, _19$$13 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(limit);
	_20 = zephir_array_isset_string_fetch(&limit, definition, SS("limit"), 0 TSRMLS_CC);
	if (_20) {
		_20 = zephir_is_true(limit);
	}
	if (_20) {
		ZEPHIR_INIT_VAR(_21$$14);
		zephir_create_array(_21$$14, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_21$$14, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_21$$14, SL("value"), &limit, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&sql, this_ptr, "getsqlexpressionlimit", NULL, 61, _21$$14, escapeChar, bindCounts);
		zephir_check_call_status();
	}
	_22 = zephir_array_isset_string_fetch(&forUpdate, definition, SS("forUpdate"), 1 TSRMLS_CC);
	if (_22) {
		_22 = zephir_is_true(forUpdate);
	}
	if (_22) {
		zephir_concat_self_str(&sql, SL(" FOR UPDATE") TSRMLS_CC);
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
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, *value = NULL, *_0$$3;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	expression = expression_param;
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_array_isset_string(expression, SS("column"))) {
		zephir_array_fetch_string(&_0$$3, expression, SL("column"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 541 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlcolumn", NULL, 40, _0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(value);
	if (!(zephir_array_isset_string_fetch(&value, expression, SS("value"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL expression", "phalcon/db/dialect.zep", 545);
		return;
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpression", NULL, 0, value, escapeChar, bindCounts);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(value);

}

/**
 * Resolve object expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionObject) {

	zend_bool _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, *domain = NULL, *objectExpression = NULL;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	expression = expression_param;
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpression", NULL, 0, objectExpression, escapeChar, bindCounts);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Resolve qualified expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionQualified) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *column = NULL, *domain = NULL;
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
	zephir_array_fetch_string(&column, expression, SL("name"), PH_NOISY, "phalcon/db/dialect.zep", 579 TSRMLS_CC);
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
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, *left = NULL, *right = NULL, *_0, *_2, *_3;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	expression = expression_param;
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	zephir_array_fetch_string(&_0, expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 598 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", &_1, 0, _0, escapeChar, bindCounts);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, expression, SL("right"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 599 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", &_1, 46, _2, escapeChar, bindCounts);
	zephir_check_call_status();
	zephir_array_fetch_string(&_3, expression, SL("op"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 601 TSRMLS_CC);
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
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, *left = NULL, *right = NULL, *_0$$3 = NULL, *_2$$3, *_3$$4, *_4$$4 = NULL;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	expression = expression_param;
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(left);
	if (zephir_array_isset_string_fetch(&left, expression, SS("left"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getsqlexpression", &_1, 0, left, escapeChar, bindCounts);
		zephir_check_call_status();
		zephir_array_fetch_string(&_2$$3, expression, SL("op"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 615 TSRMLS_CC);
		ZEPHIR_CONCAT_VSV(return_value, _0$$3, " ", _2$$3);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(right);
	if (zephir_array_isset_string_fetch(&right, expression, SS("right"), 0 TSRMLS_CC)) {
		zephir_array_fetch_string(&_3$$4, expression, SL("op"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 622 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "getsqlexpression", &_1, 46, right, escapeChar, bindCounts);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSV(return_value, _3$$4, " ", _4$$4);
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-unary expression", "phalcon/db/dialect.zep", 625);
	return;

}

/**
 * Resolve function calls
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionFunctionCall) {

	zend_bool _1, _3$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts, *name = NULL, *customFunction = NULL, *arguments = NULL, *_0, *_4$$4;
	zval *expression = NULL, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expression_param, &escapeChar_param, &bindCounts);

	expression = expression_param;
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	ZEPHIR_OBS_VAR(name);
	zephir_array_fetch_string(&name, expression, SL("name"), PH_NOISY, "phalcon/db/dialect.zep", 635 TSRMLS_CC);
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
		ZEPHIR_INIT_VAR(_2$$4);
		zephir_create_array(_2$$4, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_2$$4, SS("type"), SL("list"), 1);
		zephir_array_update_string(&_2$$4, SL("parentheses"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_2$$4, SL("value"), &arguments, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&arguments, this_ptr, "getsqlexpression", NULL, 0, _2$$4, escapeChar, bindCounts);
		zephir_check_call_status();
		_3$$4 = zephir_array_isset_string(expression, SS("distinct"));
		if (_3$$4) {
			zephir_array_fetch_string(&_4$$4, expression, SL("distinct"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 649 TSRMLS_CC);
			_3$$4 = zephir_is_true(_4$$4);
		}
		if (_3$$4) {
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

	HashTable *_3$$4;
	HashPosition _2$$4;
	zend_bool _0, _1, _7$$4;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, *items = NULL, *item = NULL, *values = NULL, *separator = NULL, **_4$$4, *_8$$4, *_9$$4, *_5$$5 = NULL;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	expression = expression_param;
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(items);
	array_init(items);
	ZEPHIR_INIT_VAR(separator);
	ZVAL_STRING(separator, ", ", 1);
	if (zephir_array_isset_string(expression, SS("separator"))) {
		ZEPHIR_OBS_NVAR(separator);
		zephir_array_fetch_string(&separator, expression, SL("separator"), PH_NOISY, "phalcon/db/dialect.zep", 670 TSRMLS_CC);
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
		zephir_is_iterable(values, &_3$$4, &_2$$4, 0, 0, "phalcon/db/dialect.zep", 679);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$4, (void**) &_4$$4, &_2$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$4, &_2$$4)
		) {
			ZEPHIR_GET_HVALUE(item, _4$$4);
			ZEPHIR_CALL_METHOD(&_5$$5, this_ptr, "getsqlexpression", &_6, 0, item, escapeChar, bindCounts);
			zephir_check_call_status();
			zephir_array_append(&items, _5$$5, PH_SEPARATE, "phalcon/db/dialect.zep", 676);
		}
		_7$$4 = zephir_array_isset_string(expression, SS("parentheses"));
		if (_7$$4) {
			zephir_array_fetch_string(&_8$$4, expression, SL("parentheses"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 679 TSRMLS_CC);
			_7$$4 = ZEPHIR_IS_FALSE_IDENTICAL(_8$$4);
		}
		if (_7$$4) {
			zephir_fast_join(return_value, separator, items TSRMLS_CC);
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(_9$$4);
		zephir_fast_join(_9$$4, separator, items TSRMLS_CC);
		ZEPHIR_CONCAT_SVS(return_value, "(", _9$$4, ")");
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-list expression", "phalcon/db/dialect.zep", 686);
	return;

}

/**
 * Resolve *
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression_param = NULL, *escapeChar_param = NULL, *domain = NULL, *_0;
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
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, *left = NULL, *right = NULL, *_0, *_2;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	expression = expression_param;
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	zephir_array_fetch_string(&_0, expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 708 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", &_1, 0, _0, escapeChar, bindCounts);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, expression, SL("right"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 709 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", &_1, 46, _2, escapeChar, bindCounts);
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
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, *left = NULL, *right = NULL, *_0, *_2;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	expression = expression_param;
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	zephir_array_fetch_string(&_0, expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 721 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", &_1, 0, _0, escapeChar, bindCounts);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, expression, SL("right"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 722 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", &_1, 46, _2, escapeChar, bindCounts);
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
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, *sql = NULL, *whenClause = NULL, *_0 = NULL, *_1, *_3, **_6, *_7$$3, *_8$$4 = NULL, *_9$$4, *_10$$4 = NULL, *_11$$4, *_12$$4 = NULL, *_13$$5 = NULL, *_14$$5, *_15$$5 = NULL;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	expression = expression_param;
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	zephir_array_fetch_string(&_1, expression, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 734 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsqlexpression", &_2, 0, _1, escapeChar, bindCounts);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SV(sql, "CASE ", _0);
	zephir_array_fetch_string(&_3, expression, SL("when-clauses"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 736 TSRMLS_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "phalcon/db/dialect.zep", 747);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(whenClause, _6);
		zephir_array_fetch_string(&_7$$3, whenClause, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 737 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_7$$3, "when")) {
			zephir_array_fetch_string(&_9$$4, whenClause, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 739 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "getsqlexpression", &_2, 46, _9$$4, escapeChar, bindCounts);
			zephir_check_call_status();
			zephir_array_fetch_string(&_11$$4, whenClause, SL("then"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 741 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10$$4, this_ptr, "getsqlexpression", &_2, 46, _11$$4, escapeChar, bindCounts);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_12$$4);
			ZEPHIR_CONCAT_SVSV(_12$$4, " WHEN ", _8$$4, " THEN ", _10$$4);
			zephir_concat_self(&sql, _12$$4 TSRMLS_CC);
		} else {
			zephir_array_fetch_string(&_14$$5, whenClause, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 743 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_13$$5, this_ptr, "getsqlexpression", &_2, 46, _14$$5, escapeChar, bindCounts);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_15$$5);
			ZEPHIR_CONCAT_SV(_15$$5, " ELSE ", _13$$5);
			zephir_concat_self(&sql, _15$$5 TSRMLS_CC);
		}
	}
	ZEPHIR_CONCAT_VS(return_value, sql, " END");
	RETURN_MM();

}

/**
 * Resolve a FROM clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionFrom) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression, *escapeChar_param = NULL, *table = NULL, *tables = NULL, **_2$$3, *_5$$3, *_3$$4 = NULL;

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
		zephir_is_iterable(expression, &_1$$3, &_0$$3, 0, 0, "phalcon/db/dialect.zep", 765);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(table, _2$$3);
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "getsqltable", &_4, 62, table, escapeChar);
			zephir_check_call_status();
			zephir_array_append(&tables, _3$$4, PH_SEPARATE, "phalcon/db/dialect.zep", 762);
		}
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_fast_join_str(_5$$3, SL(", "), tables TSRMLS_CC);
		ZEPHIR_CPY_WRT(tables, _5$$3);
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

	zend_bool _3$$3, _10$$3;
	HashTable *_1, *_6$$6;
	HashPosition _0, _5$$6;
	zephir_fcall_cache_entry *_4 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression, *escapeChar_param = NULL, *bindCounts = NULL, *condition = NULL, *join = NULL, *sql = NULL, *joinCondition = NULL, *joinTable = NULL, *joinType = NULL, *joinConditionsArray = NULL, **_2, *_11$$3, *_13$$3 = NULL, **_7$$6, *_9$$6 = NULL, *_8$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression, &escapeChar_param, &bindCounts);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "", 1);
	ZEPHIR_INIT_VAR(joinType);
	ZVAL_STRING(joinType, "", 1);
	zephir_is_iterable(expression, &_1, &_0, 0, 0, "phalcon/db/dialect.zep", 813);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(join, _2);
		ZEPHIR_OBS_NVAR(joinConditionsArray);
		_3$$3 = zephir_array_isset_string_fetch(&joinConditionsArray, join, SS("conditions"), 0 TSRMLS_CC);
		if (_3$$3) {
			_3$$3 = !(ZEPHIR_IS_EMPTY(joinConditionsArray));
		}
		if (_3$$3) {
			if (!(zephir_array_isset_long(joinConditionsArray, 0))) {
				ZEPHIR_CALL_METHOD(&joinCondition, this_ptr, "getsqlexpression", &_4, 0, joinConditionsArray, escapeChar, bindCounts);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(joinCondition);
				array_init(joinCondition);
				zephir_is_iterable(joinConditionsArray, &_6$$6, &_5$$6, 0, 0, "phalcon/db/dialect.zep", 798);
				for (
				  ; zephir_hash_get_current_data_ex(_6$$6, (void**) &_7$$6, &_5$$6) == SUCCESS
				  ; zephir_hash_move_forward_ex(_6$$6, &_5$$6)
				) {
					ZEPHIR_GET_HVALUE(condition, _7$$6);
					ZEPHIR_CALL_METHOD(&_8$$7, this_ptr, "getsqlexpression", &_4, 46, condition, escapeChar, bindCounts);
					zephir_check_call_status();
					zephir_array_append(&joinCondition, _8$$7, PH_SEPARATE, "phalcon/db/dialect.zep", 795);
				}
				ZEPHIR_INIT_NVAR(_9$$6);
				zephir_fast_join_str(_9$$6, SL(" AND "), joinCondition TSRMLS_CC);
				ZEPHIR_CPY_WRT(joinCondition, _9$$6);
			}
		} else {
			ZEPHIR_INIT_NVAR(joinCondition);
			ZVAL_LONG(joinCondition, 1);
		}
		ZEPHIR_OBS_NVAR(joinType);
		_10$$3 = zephir_array_isset_string_fetch(&joinType, join, SS("type"), 0 TSRMLS_CC);
		if (_10$$3) {
			_10$$3 = zephir_is_true(joinType);
		}
		if (_10$$3) {
			zephir_concat_self_str(&joinType, SL(" ") TSRMLS_CC);
		}
		zephir_array_fetch_string(&_11$$3, join, SL("source"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 808 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&joinTable, this_ptr, "getsqltable", &_12, 62, _11$$3, escapeChar);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_13$$3);
		ZEPHIR_CONCAT_SVSVSV(_13$$3, " ", joinType, "JOIN ", joinTable, " ON ", joinCondition);
		zephir_concat_self(&sql, _13$$3 TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Resolve a WHERE clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionWhere) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression, *escapeChar_param = NULL, *bindCounts = NULL, *whereSql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression, &escapeChar_param, &bindCounts);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&whereSql, this_ptr, "getsqlexpression", NULL, 0, expression, escapeChar, bindCounts);
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

	HashTable *_1$$3;
	HashPosition _0$$3;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression, *escapeChar_param = NULL, *bindCounts = NULL, *field = NULL, *fields = NULL, **_2$$3, *_5$$3, *_3$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression, &escapeChar_param, &bindCounts);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
		zephir_is_iterable(expression, &_1$$3, &_0$$3, 0, 0, "phalcon/db/dialect.zep", 851);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(field, _2$$3);
			if (unlikely(Z_TYPE_P(field) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-GROUP-BY expression", "phalcon/db/dialect.zep", 845);
				return;
			}
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "getsqlexpression", &_4, 0, field, escapeChar, bindCounts);
			zephir_check_call_status();
			zephir_array_append(&fields, _3$$4, PH_SEPARATE, "phalcon/db/dialect.zep", 848);
		}
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_fast_join_str(_5$$3, SL(", "), fields TSRMLS_CC);
		ZEPHIR_CPY_WRT(fields, _5$$3);
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
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, *_0 = NULL;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	expression = expression_param;
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsqlexpression", NULL, 0, expression, escapeChar, bindCounts);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, "HAVING ", _0);
	RETURN_MM();

}

/**
 * Resolve a ORDER BY clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionOrderBy) {

	zend_bool _5$$4;
	HashTable *_1$$3;
	HashPosition _0$$3;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression, *escapeChar_param = NULL, *bindCounts = NULL, *field = NULL, *fields = NULL, *type = NULL, *fieldSql = NULL, **_2$$3, *_7$$3, *_3$$4, *_6$$6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression, &escapeChar_param, &bindCounts);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(fieldSql);
	ZVAL_NULL(fieldSql);
	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
		zephir_is_iterable(expression, &_1$$3, &_0$$3, 0, 0, "phalcon/db/dialect.zep", 897);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(field, _2$$3);
			if (unlikely(Z_TYPE_P(field) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-ORDER-BY expression", "phalcon/db/dialect.zep", 882);
				return;
			}
			zephir_array_fetch_long(&_3$$4, field, 0, PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 885 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&fieldSql, this_ptr, "getsqlexpression", &_4, 0, _3$$4, escapeChar, bindCounts);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(type);
			_5$$4 = zephir_array_isset_long_fetch(&type, field, 1, 0 TSRMLS_CC);
			if (_5$$4) {
				_5$$4 = !ZEPHIR_IS_STRING(type, "");
			}
			if (_5$$4) {
				ZEPHIR_INIT_LNVAR(_6$$6);
				ZEPHIR_CONCAT_SV(_6$$6, " ", type);
				zephir_concat_self(&fieldSql, _6$$6 TSRMLS_CC);
			}
			zephir_array_append(&fields, fieldSql, PH_SEPARATE, "phalcon/db/dialect.zep", 894);
		}
		ZEPHIR_INIT_VAR(_7$$3);
		zephir_fast_join_str(_7$$3, SL(", "), fields TSRMLS_CC);
		ZEPHIR_CPY_WRT(fields, _7$$3);
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

	zend_bool _3$$4;
	zval *_5;
	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL;
	zval *expression, *escapeChar_param = NULL, *bindCounts = NULL, *sql = NULL, *value = NULL, *limit = NULL, *offset = NULL, *_0$$4, *_1$$5, *_4$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression, &escapeChar_param, &bindCounts);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "", 1);
	ZEPHIR_INIT_VAR(offset);
	ZVAL_NULL(offset);
	ZEPHIR_OBS_VAR(value);
	zephir_array_fetch_string(&value, expression, SL("value"), PH_NOISY, "phalcon/db/dialect.zep", 912 TSRMLS_CC);
	if (zephir_array_isset_string(expression, SS("sql"))) {
		ZEPHIR_OBS_NVAR(sql);
		zephir_array_fetch_string(&sql, expression, SL("sql"), PH_NOISY, "phalcon/db/dialect.zep", 915 TSRMLS_CC);
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(_0$$4);
		zephir_array_fetch_string(&_0$$4, value, SL("number"), PH_NOISY, "phalcon/db/dialect.zep", 920 TSRMLS_CC);
		if (Z_TYPE_P(_0$$4) == IS_ARRAY) {
			zephir_array_fetch_string(&_1$$5, value, SL("number"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 921 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&limit, this_ptr, "getsqlexpression", &_2, 0, _1$$5, escapeChar, bindCounts);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(limit);
			zephir_array_fetch_string(&limit, value, SL("number"), PH_NOISY, "phalcon/db/dialect.zep", 923 TSRMLS_CC);
		}
		ZEPHIR_OBS_NVAR(offset);
		_3$$4 = zephir_array_isset_string_fetch(&offset, value, SS("offset"), 0 TSRMLS_CC);
		if (_3$$4) {
			_3$$4 = Z_TYPE_P(offset) == IS_ARRAY;
		}
		if (_3$$4) {
			ZEPHIR_CALL_METHOD(&_4$$7, this_ptr, "getsqlexpression", &_2, 46, offset, escapeChar, bindCounts);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(offset, _4$$7);
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
	zval *qualified_param = NULL, *alias_param = NULL, *escapeChar_param = NULL, *_0$$3 = NULL;
	zval *qualified = NULL, *alias = NULL, *escapeChar = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &qualified_param, &alias_param, &escapeChar_param);

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
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	if (!ZEPHIR_IS_STRING(alias, "")) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "escape", NULL, 53, alias, escapeChar);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSV(return_value, qualified, " AS ", _0$$3);
		RETURN_MM();
	}
	RETURN_CTOR(qualified);

}

/**
 * Prepares table for this RDBMS
 */
PHP_METHOD(Phalcon_Db_Dialect, prepareTable) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *alias_param = NULL, *escapeChar_param = NULL, *_0 = NULL, *_2$$3 = NULL, *_3$$3, *_4$$4 = NULL, *_5$$4;
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "escape", &_1, 53, table, escapeChar);
	zephir_check_call_status();
	zephir_get_strval(table, _0);
	if (!ZEPHIR_IS_STRING(schema, "")) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "escapeschema", NULL, 63, schema, escapeChar);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_VSV(_3$$3, _2$$3, ".", table);
		zephir_get_strval(table, _3$$3);
	}
	if (!ZEPHIR_IS_STRING(alias, "")) {
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "escape", &_1, 53, alias, escapeChar);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5$$4);
		ZEPHIR_CONCAT_VSV(_5$$4, table, " AS ", _4$$4);
		zephir_get_strval(table, _5$$4);
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
	zval *column = NULL, *domain = NULL, *escapeChar = NULL, *_0$$3;

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
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_CONCAT_VSV(_0$$3, domain, ".", column);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", &_1, 53, _0$$3, escapeChar);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", &_1, 53, column, escapeChar);
	zephir_check_call_status();
	RETURN_MM();

}

