
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
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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

	zval *name_param = NULL, *customFunction, customFunction_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&customFunction_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &customFunction);

	zephir_get_strval(&name, name_param);


	zephir_update_property_array(this_ptr, SL("_customFunctions"), &name, customFunction);
	RETURN_THIS();

}

/**
 * Returns registered functions
 */
PHP_METHOD(Phalcon_Db_Dialect, getCustomFunctions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_customFunctions");

}

/**
 * Escape Schema
 */
PHP_METHOD(Phalcon_Db_Dialect, escapeSchema) {

	zval *str_param = NULL, *escapeChar_param = NULL, _0$$4, _2;
	zval str, escapeChar, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&escapeChar);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &escapeChar_param);

	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(&str, str_param);
	} else {
		ZEPHIR_INIT_VAR(&str);
		ZVAL_EMPTY_STRING(&str);
	}
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}


	if (!(ZEPHIR_GLOBAL(db).escape_identifiers)) {
		RETURN_CTOR(&str);
	}
	if (ZEPHIR_IS_STRING(&escapeChar, "")) {
		ZEPHIR_OBS_VAR(&_0$$4);
		zephir_read_property(&_0$$4, this_ptr, SL("_escapeChar"), PH_NOISY_CC);
		zephir_get_strval(&_1$$4, &_0$$4);
		ZEPHIR_CPY_WRT(&escapeChar, &_1$$4);
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_trim(&_2, &str, &escapeChar, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CONCAT_VVV(return_value, &escapeChar, &_2, &escapeChar);
	RETURN_MM();

}

/**
 * Escape identifiers
 */
PHP_METHOD(Phalcon_Db_Dialect, escape) {

	zend_bool _2$$5, _12$$7, _13$$7, _17$$9, _18$$9;
	zend_string *_11;
	zend_ulong _10;
	zval _7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *escapeChar_param = NULL, parts, key, part, newParts, _5, _6, *_8, _9, _0$$4, _3$$6, _14$$7, _16$$7, _19$$9, _21$$9;
	zval str, escapeChar, _1$$4, _4$$6, _15$$7, _20$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&escapeChar);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&newParts);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &escapeChar_param);

	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(&str, str_param);
	} else {
		ZEPHIR_INIT_VAR(&str);
		ZVAL_EMPTY_STRING(&str);
	}
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}


	if (!(ZEPHIR_GLOBAL(db).escape_identifiers)) {
		RETURN_CTOR(&str);
	}
	if (ZEPHIR_IS_STRING(&escapeChar, "")) {
		ZEPHIR_OBS_VAR(&_0$$4);
		zephir_read_property(&_0$$4, this_ptr, SL("_escapeChar"), PH_NOISY_CC);
		zephir_get_strval(&_1$$4, &_0$$4);
		ZEPHIR_CPY_WRT(&escapeChar, &_1$$4);
	}
	if (!(zephir_memnstr_str(&str, SL("."), "phalcon/db/dialect.zep", 74))) {
		_2$$5 = !ZEPHIR_IS_STRING(&escapeChar, "");
		if (_2$$5) {
			_2$$5 = !ZEPHIR_IS_STRING(&str, "*");
		}
		if (_2$$5) {
			ZEPHIR_INIT_VAR(&_3$$6);
			ZEPHIR_INIT_VAR(&_4$$6);
			ZEPHIR_CONCAT_VV(&_4$$6, &escapeChar, &escapeChar);
			zephir_fast_str_replace(&_3$$6, &escapeChar, &_4$$6, &str TSRMLS_CC);
			ZEPHIR_CONCAT_VVV(return_value, &escapeChar, &_3$$6, &escapeChar);
			RETURN_MM();
		}
		RETURN_CTOR(&str);
	}
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_trim(&_6, &str, &escapeChar, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_fast_explode_str(&_5, SL("."), &_6, LONG_MAX TSRMLS_CC);
	zephir_get_arrval(&_7, &_5);
	ZEPHIR_CPY_WRT(&parts, &_7);
	ZEPHIR_CPY_WRT(&newParts, &parts);
	zephir_is_iterable(&parts, 0, "phalcon/db/dialect.zep", 95);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parts), _10, _11, _8)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_11 != NULL) { 
				ZVAL_STR_COPY(&key, _11);
			} else {
				ZVAL_LONG(&key, _10);
			}
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _8);
			_12$$7 = ZEPHIR_IS_STRING(&escapeChar, "");
			if (!(_12$$7)) {
				_12$$7 = ZEPHIR_IS_STRING(&part, "");
			}
			_13$$7 = _12$$7;
			if (!(_13$$7)) {
				_13$$7 = ZEPHIR_IS_STRING(&part, "*");
			}
			if (_13$$7) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_14$$7);
			ZEPHIR_INIT_LNVAR(_15$$7);
			ZEPHIR_CONCAT_VV(&_15$$7, &escapeChar, &escapeChar);
			zephir_fast_str_replace(&_14$$7, &escapeChar, &_15$$7, &part TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_16$$7);
			ZEPHIR_CONCAT_VVV(&_16$$7, &escapeChar, &_14$$7, &escapeChar);
			zephir_array_update_zval(&newParts, &key, &_16$$7, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_9, &parts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &parts, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&part, &parts, "current", NULL, 0);
			zephir_check_call_status();
				_17$$9 = ZEPHIR_IS_STRING(&escapeChar, "");
				if (!(_17$$9)) {
					_17$$9 = ZEPHIR_IS_STRING(&part, "");
				}
				_18$$9 = _17$$9;
				if (!(_18$$9)) {
					_18$$9 = ZEPHIR_IS_STRING(&part, "*");
				}
				if (_18$$9) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_19$$9);
				ZEPHIR_INIT_LNVAR(_20$$9);
				ZEPHIR_CONCAT_VV(&_20$$9, &escapeChar, &escapeChar);
				zephir_fast_str_replace(&_19$$9, &escapeChar, &_20$$9, &part TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_21$$9);
				ZEPHIR_CONCAT_VVV(&_21$$9, &escapeChar, &_19$$9, &escapeChar);
				zephir_array_update_zval(&newParts, &key, &_21$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	ZEPHIR_INIT_NVAR(&key);
	zephir_fast_join_str(return_value, SL("."), &newParts TSRMLS_CC);
	RETURN_MM();

}

/**
 * Generates the SQL for LIMIT clause
 *
 * <code>
 * $sql = $dialect->limit("SELECT * FROM robots", 10);
 * echo $sql; // SELECT * FROM robots LIMIT 10
 *
 * $sql = $dialect->limit("SELECT * FROM robots", [10, 50]);
 * echo $sql; // SELECT * FROM robots LIMIT 10 OFFSET 50
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect, limit) {

	zend_bool _2$$3;
	zval *sqlQuery_param = NULL, *number, number_sub, _0$$3, _1$$3, _3$$3, _4$$4, _5$$4;
	zval sqlQuery;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery);
	ZVAL_UNDEF(&number_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sqlQuery_param, &number);

	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(&sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlQuery);
		ZVAL_EMPTY_STRING(&sqlQuery);
	}


	if (Z_TYPE_P(number) == IS_ARRAY) {
		zephir_array_fetch_long(&_0$$3, number, 0, PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 113 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SV(&_1$$3, " LIMIT ", &_0$$3);
		zephir_concat_self(&sqlQuery, &_1$$3 TSRMLS_CC);
		_2$$3 = zephir_array_isset_long(number, 1);
		if (_2$$3) {
			zephir_array_fetch_long(&_3$$3, number, 1, PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 115 TSRMLS_CC);
			_2$$3 = ((zephir_fast_strlen_ev(&_3$$3)) ? 1 : 0);
		}
		if (_2$$3) {
			zephir_array_fetch_long(&_4$$4, number, 1, PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 116 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZEPHIR_CONCAT_SV(&_5$$4, " OFFSET ", &_4$$4);
			zephir_concat_self(&sqlQuery, &_5$$4 TSRMLS_CC);
		}
		RETURN_CTOR(&sqlQuery);
	}
	ZEPHIR_CONCAT_VSV(return_value, &sqlQuery, " LIMIT ", number);
	RETURN_MM();

}

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 *<code>
 * $sql = $dialect->forUpdate("SELECT * FROM robots");
 * echo $sql; // SELECT * FROM robots FOR UPDATE
 *</code>
 */
PHP_METHOD(Phalcon_Db_Dialect, forUpdate) {

	zval *sqlQuery_param = NULL;
	zval sqlQuery;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(&sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlQuery);
		ZVAL_EMPTY_STRING(&sqlQuery);
	}


	ZEPHIR_CONCAT_VS(return_value, &sqlQuery, " FOR UPDATE");
	RETURN_MM();

}

/**
 * Gets a list of columns with escaped identifiers
 *
 * <code>
 * echo $dialect->getColumnList(
 *     [
 *         "column1",
 *         "column",
 *     ]
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect, getColumnList) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *columnList_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, columns, column, *_0, _1, _2$$3, _4$$4;
	zval columnList;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnList);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &columnList_param, &escapeChar_param, &bindCounts);

	ZEPHIR_OBS_COPY_OR_DUP(&columnList, columnList_param);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	zephir_is_iterable(&columnList, 0, "phalcon/db/dialect.zep", 159);
	if (Z_TYPE_P(&columnList) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columnList), _0)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _0);
			ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getsqlcolumn", &_3, 24, &column, &escapeChar, bindCounts);
			zephir_check_call_status();
			zephir_array_append(&columns, &_2$$3, PH_SEPARATE, "phalcon/db/dialect.zep", 156);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columnList, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &columnList, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &columnList, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "getsqlcolumn", &_3, 24, &column, &escapeChar, bindCounts);
				zephir_check_call_status();
				zephir_array_append(&columns, &_4$$4, PH_SEPARATE, "phalcon/db/dialect.zep", 156);
			ZEPHIR_CALL_METHOD(NULL, &columnList, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	zephir_fast_join_str(return_value, SL(", "), &columns TSRMLS_CC);
	RETURN_MM();

}

/**
 * Resolve Column expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlColumn) {

	zend_bool _5, _3$$4, _4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *column = NULL, column_sub, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, columnExpression, columnAlias, columnField, columnDomain, _6, _0$$3, _1$$6, _2$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&columnExpression);
	ZVAL_UNDEF(&columnAlias);
	ZVAL_UNDEF(&columnField);
	ZVAL_UNDEF(&columnDomain);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &column, &escapeChar_param, &bindCounts);

	ZEPHIR_SEPARATE_PARAM(column);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	if (Z_TYPE_P(column) != IS_ARRAY) {
		ZVAL_NULL(&_0$$3);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparequalified", NULL, 0, column, &_0$$3, &escapeChar);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (!(zephir_array_isset_string(column, SL("type")))) {
		ZEPHIR_OBS_VAR(&columnField);
		zephir_array_fetch_long(&columnField, column, 0, PH_NOISY, "phalcon/db/dialect.zep", 178 TSRMLS_CC);
		if (Z_TYPE_P(&columnField) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&columnExpression);
			zephir_create_array(&columnExpression, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&columnExpression, SL("type"), SL("scalar"));
			zephir_array_update_string(&columnExpression, SL("value"), &columnField, PH_COPY | PH_SEPARATE);
		} else if (ZEPHIR_IS_STRING(&columnField, "*")) {
			ZEPHIR_INIT_VAR(&_1$$6);
			zephir_create_array(&_1$$6, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$6, SL("type"), SL("all"));
			ZEPHIR_CPY_WRT(&columnExpression, &_1$$6);
		} else {
			ZEPHIR_INIT_VAR(&_2$$7);
			zephir_create_array(&_2$$7, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_2$$7, SL("type"), SL("qualified"));
			zephir_array_update_string(&_2$$7, SL("name"), &columnField, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&columnExpression, &_2$$7);
		}
		ZEPHIR_OBS_VAR(&columnDomain);
		_3$$4 = zephir_array_isset_long_fetch(&columnDomain, column, 1, 0 TSRMLS_CC);
		if (_3$$4) {
			_3$$4 = !ZEPHIR_IS_STRING(&columnDomain, "");
		}
		if (_3$$4) {
			zephir_array_update_string(&columnExpression, SL("domain"), &columnDomain, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&columnAlias);
		_4$$4 = zephir_array_isset_long_fetch(&columnAlias, column, 2, 0 TSRMLS_CC);
		if (_4$$4) {
			_4$$4 = zephir_is_true(&columnAlias);
		}
		if (_4$$4) {
			zephir_array_update_string(&columnExpression, SL("sqlAlias"), &columnAlias, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_CPY_WRT(&columnExpression, column);
	}
	ZEPHIR_CALL_METHOD(column, this_ptr, "getsqlexpression", NULL, 0, &columnExpression, &escapeChar, bindCounts);
	zephir_check_call_status();
	ZEPHIR_OBS_NVAR(&columnAlias);
	_5 = zephir_array_isset_string_fetch(&columnAlias, &columnExpression, SL("sqlAlias"), 0);
	if (!(_5)) {
		ZEPHIR_OBS_NVAR(&columnAlias);
		_5 = zephir_array_isset_string_fetch(&columnAlias, &columnExpression, SL("alias"), 0);
	}
	if (_5) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparecolumnalias", NULL, 0, column, &columnAlias, &escapeChar);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_NULL(&_6);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparecolumnalias", NULL, 0, column, &_6, &escapeChar);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Transforms an intermediate representation for an expression into a database system valid expression
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpression) {

	zend_bool _1$$9;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, _2$$9;
	zval escapeChar;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, type, times, postTimes, placeholders, rawValue, value, _11, _12, _0$$7, _3$$9, _4$$11, _5$$11, _6$$8, _7$$14, _8$$14, _9$$18, _10$$18;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&times);
	ZVAL_UNDEF(&postTimes);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&rawValue);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_0$$7);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_9$$18);
	ZVAL_UNDEF(&_10$$18);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	ZEPHIR_OBS_VAR(&type);
	if (!(zephir_array_isset_string_fetch(&type, &expression, SL("type"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL expression", "phalcon/db/dialect.zep", 239);
		return;
	}
	do {
		if (ZEPHIR_IS_STRING(&type, "scalar")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionscalar", NULL, 25, &expression, &escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "object")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionobject", NULL, 26, &expression, &escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "qualified")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionqualified", NULL, 27, &expression, &escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "literal")) {
			zephir_array_fetch_string(&_0$$7, &expression, SL("value"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 266 TSRMLS_CC);
			RETURN_CTOR(&_0$$7);
		}
		if (ZEPHIR_IS_STRING(&type, "placeholder")) {
			ZEPHIR_OBS_VAR(&times);
			if (zephir_array_isset_string_fetch(&times, &expression, SL("times"), 0)) {
				ZEPHIR_INIT_VAR(&placeholders);
				array_init(&placeholders);
				ZEPHIR_OBS_VAR(&rawValue);
				zephir_array_fetch_string(&rawValue, &expression, SL("rawValue"), PH_NOISY, "phalcon/db/dialect.zep", 272 TSRMLS_CC);
				ZEPHIR_OBS_VAR(&value);
				zephir_array_fetch_string(&value, &expression, SL("value"), PH_NOISY, "phalcon/db/dialect.zep", 273 TSRMLS_CC);
				ZEPHIR_OBS_VAR(&postTimes);
				if (zephir_array_isset_fetch(&postTimes, bindCounts, &rawValue, 0 TSRMLS_CC)) {
					ZEPHIR_CPY_WRT(&times, &postTimes);
				}
				ZEPHIR_CPY_WRT(&_3$$9, &times);
				_2$$9 = 1;
				_1$$9 = 0;
				if (ZEPHIR_GE_LONG(&_3$$9, _2$$9)) {
					while (1) {
						if (_1$$9) {
							_2$$9++;
							if (!(ZEPHIR_GE_LONG(&_3$$9, _2$$9))) {
								break;
							}
						} else {
							_1$$9 = 1;
						}
						i = _2$$9;
						ZEPHIR_SINIT_NVAR(_4$$11);
						ZVAL_LONG(&_4$$11, ((i - 1)));
						ZEPHIR_INIT_LNVAR(_5$$11);
						ZEPHIR_CONCAT_VV(&_5$$11, &value, &_4$$11);
						zephir_array_append(&placeholders, &_5$$11, PH_SEPARATE, "phalcon/db/dialect.zep", 280);
					}
				}
				zephir_fast_join_str(return_value, SL(", "), &placeholders TSRMLS_CC);
				RETURN_MM();
			}
			zephir_array_fetch_string(&_6$$8, &expression, SL("value"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 285 TSRMLS_CC);
			RETURN_CTOR(&_6$$8);
		}
		if (ZEPHIR_IS_STRING(&type, "binary-op")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionbinaryoperations", NULL, 28, &expression, &escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "unary-op")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionunaryoperations", NULL, 29, &expression, &escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "parentheses")) {
			zephir_array_fetch_string(&_8$$14, &expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 303 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_7$$14, this_ptr, "getsqlexpression", NULL, 30, &_8$$14, &escapeChar, bindCounts);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVS(return_value, "(", &_7$$14, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "functionCall")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionfunctioncall", NULL, 31, &expression, &escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "list")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionlist", NULL, 32, &expression, &escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "all")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionall", NULL, 33, &expression, &escapeChar);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "select")) {
			zephir_array_fetch_string(&_10$$18, &expression, SL("value"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 327 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_9$$18, this_ptr, "select", NULL, 0, &_10$$18);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVS(return_value, "(", &_9$$18, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "cast")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressioncastvalue", NULL, 34, &expression, &escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "convert")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionconvertvalue", NULL, 35, &expression, &escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "case")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressioncase", NULL, 36, &expression, &escapeChar, bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_INIT_VAR(&_11);
	object_init_ex(&_11, phalcon_db_exception_ce);
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_SVS(&_12, "Invalid SQL expression type '", &type, "'");
	ZEPHIR_CALL_METHOD(NULL, &_11, "__construct", NULL, 4, &_12);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_11, "phalcon/db/dialect.zep", 348 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Transform an intermediate representation of a schema/table into a database system valid expression
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlTable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *table, table_sub, *escapeChar_param = NULL, tableName, schemaName, aliasName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&aliasName);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &escapeChar_param);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}


	if (Z_TYPE_P(table) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&tableName);
		zephir_array_fetch_long(&tableName, table, 0, PH_NOISY, "phalcon/db/dialect.zep", 363 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&schemaName);
		zephir_array_isset_long_fetch(&schemaName, table, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&aliasName);
		zephir_array_isset_long_fetch(&aliasName, table, 2, 0 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparetable", NULL, 0, &tableName, &schemaName, &aliasName, &escapeChar);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", NULL, 37, table, &escapeChar);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a SELECT statement
 */
PHP_METHOD(Phalcon_Db_Dialect, select) {

	zend_bool _4, _8, _11, _14, _17, _20, _22;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *definition_param = NULL, tables, columns, sql, distinct, joins, where, escapeChar, groupBy, having, orderBy, limit, forUpdate, bindCounts, _0, _1, _2, _3, _5$$9, _6$$9, _7$$9, _9$$10, _10$$10, _12$$11, _13$$11, _15$$12, _16$$12, _18$$13, _19$$13;
	zval definition, _21$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&distinct);
	ZVAL_UNDEF(&joins);
	ZVAL_UNDEF(&where);
	ZVAL_UNDEF(&escapeChar);
	ZVAL_UNDEF(&groupBy);
	ZVAL_UNDEF(&having);
	ZVAL_UNDEF(&orderBy);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&forUpdate);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition_param);

	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);


	ZEPHIR_OBS_VAR(&tables);
	if (!(zephir_array_isset_string_fetch(&tables, &definition, SL("tables"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'tables' is required in the definition array", "phalcon/db/dialect.zep", 390);
		return;
	}
	ZEPHIR_OBS_VAR(&columns);
	if (!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array", "phalcon/db/dialect.zep", 394);
		return;
	}
	ZEPHIR_OBS_VAR(&distinct);
	if (zephir_array_isset_string_fetch(&distinct, &definition, SL("distinct"), 0)) {
		ZEPHIR_INIT_VAR(&sql);
		if (zephir_is_true(&distinct)) {
			ZVAL_STRING(&sql, "SELECT DISTINCT");
		} else {
			ZVAL_STRING(&sql, "SELECT ALL");
		}
	} else {
		ZEPHIR_INIT_NVAR(&sql);
		ZVAL_STRING(&sql, "SELECT");
	}
	ZEPHIR_OBS_VAR(&bindCounts);
	zephir_array_isset_string_fetch(&bindCounts, &definition, SL("bindCounts"), 0);
	ZEPHIR_OBS_VAR(&escapeChar);
	zephir_read_property(&escapeChar, this_ptr, SL("_escapeChar"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcolumnlist", NULL, 38, &columns, &escapeChar, &bindCounts);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, " ", &_0);
	zephir_concat_self(&sql, &_1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getsqlexpressionfrom", NULL, 39, &tables, &escapeChar);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, " ", &_2);
	zephir_concat_self(&sql, &_3 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&joins);
	_4 = zephir_array_isset_string_fetch(&joins, &definition, SL("joins"), 0);
	if (_4) {
		_4 = zephir_is_true(&joins);
	}
	if (_4) {
		zephir_array_fetch_string(&_6$$9, &definition, SL("joins"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 427 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_5$$9, this_ptr, "getsqlexpressionjoins", NULL, 40, &_6$$9, &escapeChar, &bindCounts);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_7$$9);
		ZEPHIR_CONCAT_SV(&_7$$9, " ", &_5$$9);
		zephir_concat_self(&sql, &_7$$9 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&where);
	_8 = zephir_array_isset_string_fetch(&where, &definition, SL("where"), 0);
	if (_8) {
		_8 = zephir_is_true(&where);
	}
	if (_8) {
		ZEPHIR_CALL_METHOD(&_9$$10, this_ptr, "getsqlexpressionwhere", NULL, 41, &where, &escapeChar, &bindCounts);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$10);
		ZEPHIR_CONCAT_SV(&_10$$10, " ", &_9$$10);
		zephir_concat_self(&sql, &_10$$10 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&groupBy);
	_11 = zephir_array_isset_string_fetch(&groupBy, &definition, SL("group"), 0);
	if (_11) {
		_11 = zephir_is_true(&groupBy);
	}
	if (_11) {
		ZEPHIR_CALL_METHOD(&_12$$11, this_ptr, "getsqlexpressiongroupby", NULL, 42, &groupBy, &escapeChar);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13$$11);
		ZEPHIR_CONCAT_SV(&_13$$11, " ", &_12$$11);
		zephir_concat_self(&sql, &_13$$11 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&having);
	_14 = zephir_array_isset_string_fetch(&having, &definition, SL("having"), 0);
	if (_14) {
		_14 = zephir_is_true(&having);
	}
	if (_14) {
		ZEPHIR_CALL_METHOD(&_15$$12, this_ptr, "getsqlexpressionhaving", NULL, 43, &having, &escapeChar, &bindCounts);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_16$$12);
		ZEPHIR_CONCAT_SV(&_16$$12, " ", &_15$$12);
		zephir_concat_self(&sql, &_16$$12 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&orderBy);
	_17 = zephir_array_isset_string_fetch(&orderBy, &definition, SL("order"), 0);
	if (_17) {
		_17 = zephir_is_true(&orderBy);
	}
	if (_17) {
		ZEPHIR_CALL_METHOD(&_18$$13, this_ptr, "getsqlexpressionorderby", NULL, 44, &orderBy, &escapeChar, &bindCounts);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_19$$13);
		ZEPHIR_CONCAT_SV(&_19$$13, " ", &_18$$13);
		zephir_concat_self(&sql, &_19$$13 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&limit);
	_20 = zephir_array_isset_string_fetch(&limit, &definition, SL("limit"), 0);
	if (_20) {
		_20 = zephir_is_true(&limit);
	}
	if (_20) {
		ZEPHIR_INIT_VAR(&_21$$14);
		zephir_create_array(&_21$$14, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_21$$14, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_21$$14, SL("value"), &limit, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&sql, this_ptr, "getsqlexpressionlimit", NULL, 45, &_21$$14, &escapeChar, &bindCounts);
		zephir_check_call_status();
	}
	_22 = zephir_array_isset_string_fetch(&forUpdate, &definition, SL("forUpdate"), 1);
	if (_22) {
		_22 = zephir_is_true(&forUpdate);
	}
	if (_22) {
		zephir_concat_self_str(&sql, SL(" FOR UPDATE") TSRMLS_CC);
	}
	RETURN_CCTOR(&sql);

}

/**
 * Checks whether the platform supports savepoints
 */
PHP_METHOD(Phalcon_Db_Dialect, supportsSavepoints) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * Checks whether the platform supports releasing savepoints.
 */
PHP_METHOD(Phalcon_Db_Dialect, supportsReleaseSavepoints) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


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
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_CONCAT_SV(return_value, "SAVEPOINT ", &name);
	RETURN_MM();

}

/**
 * Generate SQL to release a savepoint
 */
PHP_METHOD(Phalcon_Db_Dialect, releaseSavepoint) {

	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_CONCAT_SV(return_value, "RELEASE SAVEPOINT ", &name);
	RETURN_MM();

}

/**
 * Generate SQL to rollback a savepoint
 */
PHP_METHOD(Phalcon_Db_Dialect, rollbackSavepoint) {

	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_CONCAT_SV(return_value, "ROLLBACK TO SAVEPOINT ", &name);
	RETURN_MM();

}

/**
 * Checks the column type and if not string it returns the type reference
 */
PHP_METHOD(Phalcon_Db_Dialect, checkColumnType) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_CALL_METHOD(&_0, column, "gettype", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_RETURN_CALL_METHOD(column, "gettypereference", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(column, "gettype", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks the column type and returns the updated SQL statement
 */
PHP_METHOD(Phalcon_Db_Dialect, checkColumnTypeSql) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_CALL_METHOD(&_0, column, "gettype", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_RETURN_CALL_METHOD(column, "gettype", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_STRING("");

}

/**
 * Returns the size of the column enclosed in parentheses
 */
PHP_METHOD(Phalcon_Db_Dialect, getColumnSize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_CALL_METHOD(&_0, column, "getsize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "(", &_0, ")");
	RETURN_MM();

}

/**
 * Returns the column size and scale enclosed in parentheses
 */
PHP_METHOD(Phalcon_Db_Dialect, getColumnSizeAndScale) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_CALL_METHOD(&_0, column, "getsize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, column, "getscale", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "(", &_0, ",", &_1, ")");
	RETURN_MM();

}

/**
 * Resolve Column expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionScalar) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, value, _0$$3;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	if (zephir_array_isset_string(&expression, SL("column"))) {
		zephir_array_fetch_string(&_0$$3, &expression, SL("column"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 563 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlcolumn", NULL, 24, &_0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&value);
	if (!(zephir_array_isset_string_fetch(&value, &expression, SL("value"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL expression", "phalcon/db/dialect.zep", 567);
		return;
	}
	if (Z_TYPE_P(&value) == IS_ARRAY) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpression", NULL, 0, &value, &escapeChar, bindCounts);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&value);

}

/**
 * Resolve object expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionObject) {

	zend_bool _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, domain, objectExpression;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&objectExpression);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	ZEPHIR_INIT_VAR(&domain);
	ZVAL_NULL(&domain);
	ZEPHIR_INIT_VAR(&objectExpression);
	zephir_create_array(&objectExpression, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&objectExpression, SL("type"), SL("all"));
	ZEPHIR_OBS_NVAR(&domain);
	_0 = zephir_array_isset_string_fetch(&domain, &expression, SL("column"), 0);
	if (!(_0)) {
		ZEPHIR_OBS_NVAR(&domain);
		_0 = zephir_array_isset_string_fetch(&domain, &expression, SL("domain"), 0);
	}
	_1 = _0;
	if (_1) {
		_1 = !ZEPHIR_IS_STRING(&domain, "");
	}
	if (_1) {
		zephir_array_update_string(&objectExpression, SL("domain"), &domain, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpression", NULL, 0, &objectExpression, &escapeChar, bindCounts);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Resolve qualified expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionQualified) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression_param = NULL, *escapeChar_param = NULL, column, domain;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression_param, &escapeChar_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}


	ZEPHIR_OBS_VAR(&column);
	zephir_array_fetch_string(&column, &expression, SL("name"), PH_NOISY, "phalcon/db/dialect.zep", 601 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&domain);
	if (!(zephir_array_isset_string_fetch(&domain, &expression, SL("domain"), 0))) {
		ZEPHIR_INIT_NVAR(&domain);
		ZVAL_NULL(&domain);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparequalified", NULL, 0, &column, &domain, &escapeChar);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Resolve binary operations expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionBinaryOperations) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, left, right, _0, _1, _2;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	zephir_array_fetch_string(&_0, &expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 620 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", NULL, 0, &_0, &escapeChar, bindCounts);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, &expression, SL("right"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 621 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", NULL, 30, &_1, &escapeChar, bindCounts);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, &expression, SL("op"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 623 TSRMLS_CC);
	ZEPHIR_CONCAT_VSVSV(return_value, &left, " ", &_2, " ", &right);
	RETURN_MM();

}

/**
 * Resolve unary operations expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionUnaryOperations) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, left, right, _0$$3, _1$$3, _2$$4, _3$$4;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	ZEPHIR_OBS_VAR(&left);
	if (zephir_array_isset_string_fetch(&left, &expression, SL("left"), 0)) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getsqlexpression", NULL, 0, &left, &escapeChar, bindCounts);
		zephir_check_call_status();
		zephir_array_fetch_string(&_1$$3, &expression, SL("op"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 637 TSRMLS_CC);
		ZEPHIR_CONCAT_VSV(return_value, &_0$$3, " ", &_1$$3);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&right);
	if (zephir_array_isset_string_fetch(&right, &expression, SL("right"), 0)) {
		zephir_array_fetch_string(&_2$$4, &expression, SL("op"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 644 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "getsqlexpression", NULL, 30, &right, &escapeChar, bindCounts);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSV(return_value, &_2$$4, " ", &_3$$4);
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-unary expression", "phalcon/db/dialect.zep", 647);
	return;

}

/**
 * Resolve function calls
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionFunctionCall) {

	zend_bool _1, _3$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts, bindCounts_sub, __$false, name, customFunction, arguments, _0, _4$$4;
	zval expression, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&customFunction);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expression_param, &escapeChar_param, &bindCounts);

	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}


	ZEPHIR_OBS_VAR(&name);
	zephir_array_fetch_string(&name, &expression, SL("name"), PH_NOISY, "phalcon/db/dialect.zep", 657 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&customFunction);
	zephir_read_property(&_0, this_ptr, SL("_customFunctions"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&customFunction, &_0, &name, 0 TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(&customFunction, NULL, 0, this_ptr, &expression, &escapeChar);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&arguments);
	_1 = zephir_array_isset_string_fetch(&arguments, &expression, SL("arguments"), 0);
	if (_1) {
		_1 = Z_TYPE_P(&arguments) == IS_ARRAY;
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_2$$4, SL("type"), SL("list"));
		zephir_array_update_string(&_2$$4, SL("parentheses"), &__$false, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_2$$4, SL("value"), &arguments, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&arguments, this_ptr, "getsqlexpression", NULL, 0, &_2$$4, &escapeChar, bindCounts);
		zephir_check_call_status();
		_3$$4 = zephir_array_isset_string(&expression, SL("distinct"));
		if (_3$$4) {
			zephir_array_fetch_string(&_4$$4, &expression, SL("distinct"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 671 TSRMLS_CC);
			_3$$4 = zephir_is_true(&_4$$4);
		}
		if (_3$$4) {
			ZEPHIR_CONCAT_VSVS(return_value, &name, "(DISTINCT ", &arguments, ")");
			RETURN_MM();
		}
		ZEPHIR_CONCAT_VSVS(return_value, &name, "(", &arguments, ")");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_VS(return_value, &name, "()");
	RETURN_MM();

}

/**
 * Resolve Lists
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionList) {

	zend_bool _0, _1, _7$$4;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, items, item, values, separator, *_2$$4, _3$$4, _8$$4, _9$$4, _4$$5, _6$$6;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	ZEPHIR_INIT_VAR(&items);
	array_init(&items);
	ZEPHIR_INIT_VAR(&separator);
	ZVAL_STRING(&separator, ", ");
	if (zephir_array_isset_string(&expression, SL("separator"))) {
		ZEPHIR_OBS_NVAR(&separator);
		zephir_array_fetch_string(&separator, &expression, SL("separator"), PH_NOISY, "phalcon/db/dialect.zep", 692 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&values);
	_0 = zephir_array_isset_long_fetch(&values, &expression, 0, 0 TSRMLS_CC);
	if (!(_0)) {
		ZEPHIR_OBS_NVAR(&values);
		_0 = zephir_array_isset_string_fetch(&values, &expression, SL("value"), 0);
	}
	_1 = _0;
	if (_1) {
		_1 = Z_TYPE_P(&values) == IS_ARRAY;
	}
	if (_1) {
		zephir_is_iterable(&values, 0, "phalcon/db/dialect.zep", 701);
		if (Z_TYPE_P(&values) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _2$$4)
			{
				ZEPHIR_INIT_NVAR(&item);
				ZVAL_COPY(&item, _2$$4);
				ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "getsqlexpression", &_5, 0, &item, &escapeChar, bindCounts);
				zephir_check_call_status();
				zephir_array_append(&items, &_4$$5, PH_SEPARATE, "phalcon/db/dialect.zep", 698);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$4, &values, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&item, &values, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_6$$6, this_ptr, "getsqlexpression", &_5, 30, &item, &escapeChar, bindCounts);
					zephir_check_call_status();
					zephir_array_append(&items, &_6$$6, PH_SEPARATE, "phalcon/db/dialect.zep", 698);
				ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&item);
		_7$$4 = zephir_array_isset_string(&expression, SL("parentheses"));
		if (_7$$4) {
			zephir_array_fetch_string(&_8$$4, &expression, SL("parentheses"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 701 TSRMLS_CC);
			_7$$4 = ZEPHIR_IS_FALSE_IDENTICAL(&_8$$4);
		}
		if (_7$$4) {
			zephir_fast_join(return_value, &separator, &items TSRMLS_CC);
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_9$$4);
		zephir_fast_join(&_9$$4, &separator, &items TSRMLS_CC);
		ZEPHIR_CONCAT_SVS(return_value, "(", &_9$$4, ")");
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-list expression", "phalcon/db/dialect.zep", 708);
	return;

}

/**
 * Resolve *
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionAll) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression_param = NULL, *escapeChar_param = NULL, domain, _0;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression_param, &escapeChar_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}


	ZEPHIR_OBS_VAR(&domain);
	zephir_array_isset_string_fetch(&domain, &expression, SL("domain"), 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "*");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparequalified", NULL, 0, &_0, &domain, &escapeChar);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Resolve CAST of values
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionCastValue) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, left, right, _0, _1;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	zephir_array_fetch_string(&_0, &expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 730 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", NULL, 0, &_0, &escapeChar, bindCounts);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, &expression, SL("right"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 731 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", NULL, 30, &_1, &escapeChar, bindCounts);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "CAST(", &left, " AS ", &right, ")");
	RETURN_MM();

}

/**
 * Resolve CONVERT of values encodings
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionConvertValue) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, left, right, _0, _1;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	zephir_array_fetch_string(&_0, &expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 743 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", NULL, 0, &_0, &escapeChar, bindCounts);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, &expression, SL("right"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 744 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", NULL, 30, &_1, &escapeChar, bindCounts);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "CONVERT(", &left, " USING ", &right, ")");
	RETURN_MM();

}

/**
 * Resolve CASE expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionCase) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, sql, whenClause, _0, _1, _2, *_3, _4, _5$$3, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4, _11$$5, _12$$5, _13$$5, _14$$6, _15$$7, _16$$7, _17$$7, _18$$7, _19$$7, _20$$8, _21$$8, _22$$8;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&whenClause);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	zephir_array_fetch_string(&_1, &expression, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 756 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsqlexpression", NULL, 0, &_1, &escapeChar, bindCounts);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SV(&sql, "CASE ", &_0);
	zephir_array_fetch_string(&_2, &expression, SL("when-clauses"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 758 TSRMLS_CC);
	zephir_is_iterable(&_2, 0, "phalcon/db/dialect.zep", 769);
	if (Z_TYPE_P(&_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2), _3)
		{
			ZEPHIR_INIT_NVAR(&whenClause);
			ZVAL_COPY(&whenClause, _3);
			zephir_array_fetch_string(&_5$$3, &whenClause, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 759 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(&_5$$3, "when")) {
				zephir_array_fetch_string(&_7$$4, &whenClause, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 761 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "getsqlexpression", NULL, 30, &_7$$4, &escapeChar, bindCounts);
				zephir_check_call_status();
				zephir_array_fetch_string(&_9$$4, &whenClause, SL("then"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 763 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "getsqlexpression", NULL, 30, &_9$$4, &escapeChar, bindCounts);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_10$$4);
				ZEPHIR_CONCAT_SVSV(&_10$$4, " WHEN ", &_6$$4, " THEN ", &_8$$4);
				zephir_concat_self(&sql, &_10$$4 TSRMLS_CC);
			} else {
				zephir_array_fetch_string(&_12$$5, &whenClause, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 765 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "getsqlexpression", NULL, 30, &_12$$5, &escapeChar, bindCounts);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_13$$5);
				ZEPHIR_CONCAT_SV(&_13$$5, " ELSE ", &_11$$5);
				zephir_concat_self(&sql, &_13$$5 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_2, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &_2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&whenClause, &_2, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_14$$6, &whenClause, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 759 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(&_14$$6, "when")) {
					zephir_array_fetch_string(&_16$$7, &whenClause, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 761 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_15$$7, this_ptr, "getsqlexpression", NULL, 30, &_16$$7, &escapeChar, bindCounts);
					zephir_check_call_status();
					zephir_array_fetch_string(&_18$$7, &whenClause, SL("then"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 763 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_17$$7, this_ptr, "getsqlexpression", NULL, 30, &_18$$7, &escapeChar, bindCounts);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_19$$7);
					ZEPHIR_CONCAT_SVSV(&_19$$7, " WHEN ", &_15$$7, " THEN ", &_17$$7);
					zephir_concat_self(&sql, &_19$$7 TSRMLS_CC);
				} else {
					zephir_array_fetch_string(&_21$$8, &whenClause, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 765 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_20$$8, this_ptr, "getsqlexpression", NULL, 30, &_21$$8, &escapeChar, bindCounts);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_22$$8);
					ZEPHIR_CONCAT_SV(&_22$$8, " ELSE ", &_20$$8);
					zephir_concat_self(&sql, &_22$$8 TSRMLS_CC);
				}
			ZEPHIR_CALL_METHOD(NULL, &_2, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&whenClause);
	ZEPHIR_CONCAT_VS(return_value, &sql, " END");
	RETURN_MM();

}

/**
 * Resolve a FROM clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionFrom) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression, expression_sub, *escapeChar_param = NULL, table, tables, *_0$$3, _1$$3, _5$$3, _2$$4, _4$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression, &escapeChar_param);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}


	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&tables);
		array_init(&tables);
		zephir_is_iterable(expression, 0, "phalcon/db/dialect.zep", 787);
		if (Z_TYPE_P(expression) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(expression), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&table);
				ZVAL_COPY(&table, _0$$3);
				ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getsqltable", &_3, 46, &table, &escapeChar);
				zephir_check_call_status();
				zephir_array_append(&tables, &_2$$4, PH_SEPARATE, "phalcon/db/dialect.zep", 784);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, expression, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, expression, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&table, expression, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "getsqltable", &_3, 46, &table, &escapeChar);
					zephir_check_call_status();
					zephir_array_append(&tables, &_4$$5, PH_SEPARATE, "phalcon/db/dialect.zep", 784);
				ZEPHIR_CALL_METHOD(NULL, expression, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&table);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_fast_join_str(&_5$$3, SL(", "), &tables TSRMLS_CC);
		ZEPHIR_CPY_WRT(&tables, &_5$$3);
	} else {
		ZEPHIR_CPY_WRT(&tables, expression);
	}
	ZEPHIR_CONCAT_SV(return_value, "FROM ", &tables);
	RETURN_MM();

}

/**
 * Resolve a JOINs clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionJoins) {

	zend_bool _2$$3, _9$$3, _13$$11, _19$$11;
	zephir_fcall_cache_entry *_3 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression, expression_sub, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, condition, join, sql, joinCondition, joinTable, joinType, joinConditionsArray, *_0, _1, _10$$3, _12$$3, *_4$$6, _5$$6, _8$$6, _6$$7, _7$$8, _20$$11, _21$$11, *_14$$14, _15$$14, _18$$14, _16$$15, _17$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&joinCondition);
	ZVAL_UNDEF(&joinTable);
	ZVAL_UNDEF(&joinType);
	ZVAL_UNDEF(&joinConditionsArray);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression, &escapeChar_param, &bindCounts);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "");
	ZEPHIR_INIT_VAR(&joinType);
	ZVAL_STRING(&joinType, "");
	zephir_is_iterable(expression, 0, "phalcon/db/dialect.zep", 835);
	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(expression), _0)
		{
			ZEPHIR_INIT_NVAR(&join);
			ZVAL_COPY(&join, _0);
			ZEPHIR_OBS_NVAR(&joinConditionsArray);
			_2$$3 = zephir_array_isset_string_fetch(&joinConditionsArray, &join, SL("conditions"), 0);
			if (_2$$3) {
				_2$$3 = !(ZEPHIR_IS_EMPTY(&joinConditionsArray));
			}
			if (_2$$3) {
				if (!(zephir_array_isset_long(&joinConditionsArray, 0))) {
					ZEPHIR_CALL_METHOD(&joinCondition, this_ptr, "getsqlexpression", &_3, 0, &joinConditionsArray, &escapeChar, bindCounts);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&joinCondition);
					array_init(&joinCondition);
					zephir_is_iterable(&joinConditionsArray, 0, "phalcon/db/dialect.zep", 820);
					if (Z_TYPE_P(&joinConditionsArray) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&joinConditionsArray), _4$$6)
						{
							ZEPHIR_INIT_NVAR(&condition);
							ZVAL_COPY(&condition, _4$$6);
							ZEPHIR_CALL_METHOD(&_6$$7, this_ptr, "getsqlexpression", &_3, 30, &condition, &escapeChar, bindCounts);
							zephir_check_call_status();
							zephir_array_append(&joinCondition, &_6$$7, PH_SEPARATE, "phalcon/db/dialect.zep", 817);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &joinConditionsArray, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_5$$6, &joinConditionsArray, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_5$$6)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&condition, &joinConditionsArray, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_7$$8, this_ptr, "getsqlexpression", &_3, 30, &condition, &escapeChar, bindCounts);
								zephir_check_call_status();
								zephir_array_append(&joinCondition, &_7$$8, PH_SEPARATE, "phalcon/db/dialect.zep", 817);
							ZEPHIR_CALL_METHOD(NULL, &joinConditionsArray, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&condition);
					ZEPHIR_INIT_NVAR(&_8$$6);
					zephir_fast_join_str(&_8$$6, SL(" AND "), &joinCondition TSRMLS_CC);
					ZEPHIR_CPY_WRT(&joinCondition, &_8$$6);
				}
			} else {
				ZEPHIR_INIT_NVAR(&joinCondition);
				ZVAL_LONG(&joinCondition, 1);
			}
			ZEPHIR_OBS_NVAR(&joinType);
			_9$$3 = zephir_array_isset_string_fetch(&joinType, &join, SL("type"), 0);
			if (_9$$3) {
				_9$$3 = zephir_is_true(&joinType);
			}
			if (_9$$3) {
				zephir_concat_self_str(&joinType, SL(" ") TSRMLS_CC);
			}
			zephir_array_fetch_string(&_10$$3, &join, SL("source"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 830 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&joinTable, this_ptr, "getsqltable", &_11, 46, &_10$$3, &escapeChar);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_12$$3);
			ZEPHIR_CONCAT_SVSVSV(&_12$$3, " ", &joinType, "JOIN ", &joinTable, " ON ", &joinCondition);
			zephir_concat_self(&sql, &_12$$3 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, expression, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, expression, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&join, expression, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&joinConditionsArray);
				_13$$11 = zephir_array_isset_string_fetch(&joinConditionsArray, &join, SL("conditions"), 0);
				if (_13$$11) {
					_13$$11 = !(ZEPHIR_IS_EMPTY(&joinConditionsArray));
				}
				if (_13$$11) {
					if (!(zephir_array_isset_long(&joinConditionsArray, 0))) {
						ZEPHIR_CALL_METHOD(&joinCondition, this_ptr, "getsqlexpression", &_3, 30, &joinConditionsArray, &escapeChar, bindCounts);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&joinCondition);
						array_init(&joinCondition);
						zephir_is_iterable(&joinConditionsArray, 0, "phalcon/db/dialect.zep", 820);
						if (Z_TYPE_P(&joinConditionsArray) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&joinConditionsArray), _14$$14)
							{
								ZEPHIR_INIT_NVAR(&condition);
								ZVAL_COPY(&condition, _14$$14);
								ZEPHIR_CALL_METHOD(&_16$$15, this_ptr, "getsqlexpression", &_3, 30, &condition, &escapeChar, bindCounts);
								zephir_check_call_status();
								zephir_array_append(&joinCondition, &_16$$15, PH_SEPARATE, "phalcon/db/dialect.zep", 817);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &joinConditionsArray, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_15$$14, &joinConditionsArray, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_15$$14)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&condition, &joinConditionsArray, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&_17$$16, this_ptr, "getsqlexpression", &_3, 30, &condition, &escapeChar, bindCounts);
									zephir_check_call_status();
									zephir_array_append(&joinCondition, &_17$$16, PH_SEPARATE, "phalcon/db/dialect.zep", 817);
								ZEPHIR_CALL_METHOD(NULL, &joinConditionsArray, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&condition);
						ZEPHIR_INIT_NVAR(&_18$$14);
						zephir_fast_join_str(&_18$$14, SL(" AND "), &joinCondition TSRMLS_CC);
						ZEPHIR_CPY_WRT(&joinCondition, &_18$$14);
					}
				} else {
					ZEPHIR_INIT_NVAR(&joinCondition);
					ZVAL_LONG(&joinCondition, 1);
				}
				ZEPHIR_OBS_NVAR(&joinType);
				_19$$11 = zephir_array_isset_string_fetch(&joinType, &join, SL("type"), 0);
				if (_19$$11) {
					_19$$11 = zephir_is_true(&joinType);
				}
				if (_19$$11) {
					zephir_concat_self_str(&joinType, SL(" ") TSRMLS_CC);
				}
				zephir_array_fetch_string(&_20$$11, &join, SL("source"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 830 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&joinTable, this_ptr, "getsqltable", &_11, 46, &_20$$11, &escapeChar);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_21$$11);
				ZEPHIR_CONCAT_SVSVSV(&_21$$11, " ", &joinType, "JOIN ", &joinTable, " ON ", &joinCondition);
				zephir_concat_self(&sql, &_21$$11 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, expression, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&join);
	RETURN_CCTOR(&sql);

}

/**
 * Resolve a WHERE clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression, expression_sub, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, whereSql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&whereSql);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression, &escapeChar_param, &bindCounts);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&whereSql, this_ptr, "getsqlexpression", NULL, 0, expression, &escapeChar, bindCounts);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&whereSql, expression);
	}
	ZEPHIR_CONCAT_SV(return_value, "WHERE ", &whereSql);
	RETURN_MM();

}

/**
 * Resolve a GROUP BY clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionGroupBy) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression, expression_sub, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, field, fields, *_0$$3, _1$$3, _5$$3, _2$$4, _4$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression, &escapeChar_param, &bindCounts);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
		zephir_is_iterable(expression, 0, "phalcon/db/dialect.zep", 873);
		if (Z_TYPE_P(expression) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(expression), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _0$$3);
				if (UNEXPECTED(Z_TYPE_P(&field) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-GROUP-BY expression", "phalcon/db/dialect.zep", 867);
					return;
				}
				ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getsqlexpression", &_3, 0, &field, &escapeChar, bindCounts);
				zephir_check_call_status();
				zephir_array_append(&fields, &_2$$4, PH_SEPARATE, "phalcon/db/dialect.zep", 870);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, expression, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, expression, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, expression, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&field) != IS_ARRAY)) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-GROUP-BY expression", "phalcon/db/dialect.zep", 867);
						return;
					}
					ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "getsqlexpression", &_3, 30, &field, &escapeChar, bindCounts);
					zephir_check_call_status();
					zephir_array_append(&fields, &_4$$6, PH_SEPARATE, "phalcon/db/dialect.zep", 870);
				ZEPHIR_CALL_METHOD(NULL, expression, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_fast_join_str(&_5$$3, SL(", "), &fields TSRMLS_CC);
		ZEPHIR_CPY_WRT(&fields, &_5$$3);
	} else {
		ZEPHIR_CPY_WRT(&fields, expression);
	}
	ZEPHIR_CONCAT_SV(return_value, "GROUP BY ", &fields);
	RETURN_MM();

}

/**
 * Resolve a HAVING clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionHaving) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression_param = NULL, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, _0;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression_param, &escapeChar_param, &bindCounts);

	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsqlexpression", NULL, 0, &expression, &escapeChar, bindCounts);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, "HAVING ", &_0);
	RETURN_MM();

}

/**
 * Resolve an ORDER BY clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionOrderBy) {

	zend_bool _4$$4, _7$$7;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression, expression_sub, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, field, fields, type, fieldSql, *_0$$3, _1$$3, _9$$3, _2$$4, _5$$6, _6$$7, _8$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&fieldSql);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&escapeChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression, &escapeChar_param, &bindCounts);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	ZEPHIR_INIT_VAR(&fieldSql);
	ZVAL_NULL(&fieldSql);
	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
		zephir_is_iterable(expression, 0, "phalcon/db/dialect.zep", 919);
		if (Z_TYPE_P(expression) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(expression), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _0$$3);
				if (UNEXPECTED(Z_TYPE_P(&field) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-ORDER-BY expression", "phalcon/db/dialect.zep", 904);
					return;
				}
				zephir_array_fetch_long(&_2$$4, &field, 0, PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 907 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&fieldSql, this_ptr, "getsqlexpression", &_3, 0, &_2$$4, &escapeChar, bindCounts);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&type);
				_4$$4 = zephir_array_isset_long_fetch(&type, &field, 1, 0 TSRMLS_CC);
				if (_4$$4) {
					_4$$4 = !ZEPHIR_IS_STRING(&type, "");
				}
				if (_4$$4) {
					ZEPHIR_INIT_LNVAR(_5$$6);
					ZEPHIR_CONCAT_SV(&_5$$6, " ", &type);
					zephir_concat_self(&fieldSql, &_5$$6 TSRMLS_CC);
				}
				zephir_array_append(&fields, &fieldSql, PH_SEPARATE, "phalcon/db/dialect.zep", 916);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, expression, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, expression, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, expression, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&field) != IS_ARRAY)) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid SQL-ORDER-BY expression", "phalcon/db/dialect.zep", 904);
						return;
					}
					zephir_array_fetch_long(&_6$$7, &field, 0, PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 907 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&fieldSql, this_ptr, "getsqlexpression", &_3, 30, &_6$$7, &escapeChar, bindCounts);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&type);
					_7$$7 = zephir_array_isset_long_fetch(&type, &field, 1, 0 TSRMLS_CC);
					if (_7$$7) {
						_7$$7 = !ZEPHIR_IS_STRING(&type, "");
					}
					if (_7$$7) {
						ZEPHIR_INIT_LNVAR(_8$$9);
						ZEPHIR_CONCAT_SV(&_8$$9, " ", &type);
						zephir_concat_self(&fieldSql, &_8$$9 TSRMLS_CC);
					}
					zephir_array_append(&fields, &fieldSql, PH_SEPARATE, "phalcon/db/dialect.zep", 916);
				ZEPHIR_CALL_METHOD(NULL, expression, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_fast_join_str(&_9$$3, SL(", "), &fields TSRMLS_CC);
		ZEPHIR_CPY_WRT(&fields, &_9$$3);
	} else {
		ZEPHIR_CPY_WRT(&fields, expression);
	}
	ZEPHIR_CONCAT_SV(return_value, "ORDER BY ", &fields);
	RETURN_MM();

}

/**
 * Resolve a LIMIT clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionLimit) {

	zend_bool _2$$4;
	zval _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar;
	zval *expression, expression_sub, *escapeChar_param = NULL, *bindCounts = NULL, bindCounts_sub, __$null, sql, value, limit, offset, _0$$4, _1$$5, _3$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&bindCounts_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&escapeChar);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &expression, &escapeChar_param, &bindCounts);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	if (!bindCounts) {
		bindCounts = &bindCounts_sub;
		bindCounts = &__$null;
	}


	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "");
	ZEPHIR_INIT_VAR(&offset);
	ZVAL_NULL(&offset);
	ZEPHIR_OBS_VAR(&value);
	zephir_array_fetch_string(&value, expression, SL("value"), PH_NOISY, "phalcon/db/dialect.zep", 934 TSRMLS_CC);
	if (zephir_array_isset_string(expression, SL("sql"))) {
		ZEPHIR_OBS_NVAR(&sql);
		zephir_array_fetch_string(&sql, expression, SL("sql"), PH_NOISY, "phalcon/db/dialect.zep", 937 TSRMLS_CC);
	}
	if (Z_TYPE_P(&value) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&_0$$4);
		zephir_array_fetch_string(&_0$$4, &value, SL("number"), PH_NOISY, "phalcon/db/dialect.zep", 942 TSRMLS_CC);
		if (Z_TYPE_P(&_0$$4) == IS_ARRAY) {
			zephir_array_fetch_string(&_1$$5, &value, SL("number"), PH_NOISY | PH_READONLY, "phalcon/db/dialect.zep", 943 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&limit, this_ptr, "getsqlexpression", NULL, 0, &_1$$5, &escapeChar, bindCounts);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(&limit);
			zephir_array_fetch_string(&limit, &value, SL("number"), PH_NOISY, "phalcon/db/dialect.zep", 945 TSRMLS_CC);
		}
		ZEPHIR_OBS_NVAR(&offset);
		_2$$4 = zephir_array_isset_string_fetch(&offset, &value, SL("offset"), 0);
		if (_2$$4) {
			_2$$4 = Z_TYPE_P(&offset) == IS_ARRAY;
		}
		if (_2$$4) {
			ZEPHIR_CALL_METHOD(&_3$$7, this_ptr, "getsqlexpression", NULL, 30, &offset, &escapeChar, bindCounts);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&offset, &_3$$7);
		}
	} else {
		ZEPHIR_CPY_WRT(&limit, &value);
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_4, &limit);
	zephir_array_fast_append(&_4, &offset);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "limit", NULL, 0, &sql, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prepares column for this RDBMS
 */
PHP_METHOD(Phalcon_Db_Dialect, prepareColumnAlias) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *qualified_param = NULL, *alias_param = NULL, *escapeChar_param = NULL, _0$$3;
	zval qualified, alias, escapeChar;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&qualified);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&escapeChar);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &qualified_param, &alias_param, &escapeChar_param);

	if (UNEXPECTED(Z_TYPE_P(qualified_param) != IS_STRING && Z_TYPE_P(qualified_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'qualified' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(qualified_param) == IS_STRING)) {
		zephir_get_strval(&qualified, qualified_param);
	} else {
		ZEPHIR_INIT_VAR(&qualified);
		ZVAL_EMPTY_STRING(&qualified);
	}
	if (!alias_param) {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_STRING(&alias, "");
	} else {
		zephir_get_strval(&alias, alias_param);
	}
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}


	if (!ZEPHIR_IS_STRING(&alias, "")) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "escape", NULL, 37, &alias, &escapeChar);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSV(return_value, &qualified, " AS ", &_0$$3);
		RETURN_MM();
	}
	RETURN_CTOR(&qualified);

}

/**
 * Prepares table for this RDBMS
 */
PHP_METHOD(Phalcon_Db_Dialect, prepareTable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *alias_param = NULL, *escapeChar_param = NULL, _0, _1$$3, _2$$3, _3$$4, _4$$4;
	zval table, schema, alias, escapeChar;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&escapeChar);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &table_param, &schema_param, &alias_param, &escapeChar_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}
	if (!alias_param) {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_STRING(&alias, "");
	} else {
		zephir_get_strval(&alias, alias_param);
	}
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "escape", NULL, 37, &table, &escapeChar);
	zephir_check_call_status();
	zephir_get_strval(&table, &_0);
	if (!ZEPHIR_IS_STRING(&schema, "")) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "escapeschema", NULL, 47, &schema, &escapeChar);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VSV(&_2$$3, &_1$$3, ".", &table);
		zephir_get_strval(&table, &_2$$3);
	}
	if (!ZEPHIR_IS_STRING(&alias, "")) {
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "escape", NULL, 37, &alias, &escapeChar);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CONCAT_VSV(&_4$$4, &table, " AS ", &_3$$4);
		zephir_get_strval(&table, &_4$$4);
	}
	RETURN_CTOR(&table);

}

/**
 * Prepares qualified for this RDBMS
 */
PHP_METHOD(Phalcon_Db_Dialect, prepareQualified) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column_param = NULL, *domain_param = NULL, *escapeChar_param = NULL;
	zval column, domain, escapeChar, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&escapeChar);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &column_param, &domain_param, &escapeChar_param);

	if (UNEXPECTED(Z_TYPE_P(column_param) != IS_STRING && Z_TYPE_P(column_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'column' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(column_param) == IS_STRING)) {
		zephir_get_strval(&column, column_param);
	} else {
		ZEPHIR_INIT_VAR(&column);
		ZVAL_EMPTY_STRING(&column);
	}
	if (!domain_param) {
		ZEPHIR_INIT_VAR(&domain);
		ZVAL_STRING(&domain, "");
	} else {
		zephir_get_strval(&domain, domain_param);
	}
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
		ZVAL_STRING(&escapeChar, "");
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}


	if (!ZEPHIR_IS_STRING(&domain, "")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_VSV(&_0$$3, &domain, ".", &column);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", NULL, 37, &_0$$3, &escapeChar);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", NULL, 37, &column, &escapeChar);
	zephir_check_call_status();
	RETURN_MM();

}

