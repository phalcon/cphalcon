
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
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This is the base class to each database dialect. This implements
 * common methods to transform intermediate code into its RDBMS related syntax
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Dialect, phalcon, db_dialect, phalcon_db_dialect_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_dialect_ce, SL("escapeChar"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_dialect_ce, SL("customFunctions"), ZEND_ACC_PROTECTED);
	/**
	 * Dialect-specific operators that a concrete dialect must opt into
	 * via supportedOperators; using one elsewhere throws.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_dialect_ce, SL("guardedOperators"), ZEND_ACC_PROTECTED);
	/**
	 * Subset of guardedOperators that this dialect emits. Overridden per
	 * dialect.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_dialect_ce, SL("supportedOperators"), ZEND_ACC_PROTECTED);
	phalcon_db_dialect_ce->create_object = zephir_init_properties_Phalcon_Db_Dialect;

	zend_class_implements(phalcon_db_dialect_ce, 1, phalcon_db_dialectinterface_ce);
	return SUCCESS;
}

/**
 * Generate SQL to create a new savepoint
 */
PHP_METHOD(Phalcon_Db_Dialect, createSavepoint)
{
	zval name_zv;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	ZEPHIR_CONCAT_SV(return_value, "SAVEPOINT ", &name_zv);
	return;
}

/**
 * Escape identifiers
 */
PHP_METHOD(Phalcon_Db_Dialect, escape)
{
	zend_bool _4$$5, _12$$7, _13$$7;
	zend_ulong _10;
	zval _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar, _3$$4, _6$$6, _15$$7;
	zval str_zv, *escapeChar_param = NULL, parts, key, part, newParts, _0, _1, _7, *_9, _2$$4, _5$$6, _14$$7, _16$$7;
	zend_string *str = NULL, *_11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str_zv);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&newParts);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&escapeChar);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_8);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(str)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(escapeChar_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		escapeChar_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&str_zv);
	ZVAL_STR_COPY(&str_zv, str);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "db.escape_identifiers");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_support_settings_ce, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_STR(zend_string_copy(str));
	}
	if (ZEPHIR_IS_EMPTY(&escapeChar)) {
		zephir_memory_observe(&_2$$4);
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("escapeChar"), PH_NOISY_CC);
		zephir_cast_to_string(&_3$$4, &_2$$4);
		ZEPHIR_CPY_WRT(&escapeChar, &_3$$4);
	}
	if (!(zephir_memnstr_str(&str_zv, SL("."), "phalcon/Db/Dialect.zep", 82))) {
		_4$$5 = !ZEPHIR_IS_STRING(&escapeChar, "");
		if (_4$$5) {
			_4$$5 = !ZEPHIR_IS_STRING(&str_zv, "*");
		}
		if (_4$$5) {
			ZEPHIR_INIT_VAR(&_5$$6);
			ZEPHIR_INIT_VAR(&_6$$6);
			ZEPHIR_CONCAT_VV(&_6$$6, &escapeChar, &escapeChar);
			zephir_fast_str_replace(&_5$$6, &escapeChar, &_6$$6, &str_zv);
			ZEPHIR_CONCAT_VVV(return_value, &escapeChar, &_5$$6, &escapeChar);
			RETURN_MM();
		}
		RETURN_MM_STR(zend_string_copy(str));
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_trim(&_7, &str_zv, &escapeChar, ZEPHIR_TRIM_BOTH);
	zephir_fast_explode_str(&_1, SL("."), &_7, LONG_MAX);
	zephir_get_arrval(&_8, &_1);
	ZEPHIR_CPY_WRT(&parts, &_8);
	ZEPHIR_CPY_WRT(&newParts, &parts);
	zephir_is_iterable(&parts, 0, "phalcon/Db/Dialect.zep", 102);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parts), _10, _11, _9)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_11 != NULL) { 
			ZVAL_STR_COPY(&key, _11);
		} else {
			ZVAL_LONG(&key, _10);
		}
		ZEPHIR_INIT_NVAR(&part);
		ZVAL_COPY(&part, _9);
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
		ZEPHIR_INIT_NVAR(&_15$$7);
		ZEPHIR_CONCAT_VV(&_15$$7, &escapeChar, &escapeChar);
		zephir_fast_str_replace(&_14$$7, &escapeChar, &_15$$7, &part);
		ZEPHIR_INIT_NVAR(&_16$$7);
		ZEPHIR_CONCAT_VVV(&_16$$7, &escapeChar, &_14$$7, &escapeChar);
		zephir_array_update_zval(&newParts, &key, &_16$$7, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&part);
	ZEPHIR_INIT_NVAR(&key);
	zephir_fast_join_str(return_value, SL("."), &newParts);
	RETURN_MM();
}

/**
 * Escape Schema
 */
PHP_METHOD(Phalcon_Db_Dialect, escapeSchema)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escapeChar, _3$$4;
	zval str_zv, *escapeChar_param = NULL, _0, _1, _2$$4;
	zend_string *str = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&escapeChar);
	ZVAL_UNDEF(&_3$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(str)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(escapeChar_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		escapeChar_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&str_zv);
	ZVAL_STR_COPY(&str_zv, str);
	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(&escapeChar);
	} else {
		zephir_get_strval(&escapeChar, escapeChar_param);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "db.escape_identifiers");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_support_settings_ce, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_STR(zend_string_copy(str));
	}
	if (ZEPHIR_IS_STRING(&escapeChar, "")) {
		zephir_memory_observe(&_2$$4);
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("escapeChar"), PH_NOISY_CC);
		zephir_cast_to_string(&_3$$4, &_2$$4);
		ZEPHIR_CPY_WRT(&escapeChar, &_3$$4);
	}
	ZEPHIR_INIT_NVAR(&_1);
	zephir_fast_trim(&_1, &str_zv, &escapeChar, ZEPHIR_TRIM_BOTH);
	ZEPHIR_CONCAT_VVV(return_value, &escapeChar, &_1, &escapeChar);
	RETURN_MM();
}

/**
 * Returns a SQL modified with a FOR UPDATE clause. The optional `modifier`
 * appends a row-lock disposition keyword.
 *
 *```php
 * $sql = $dialect->forUpdate("SELECT * FROM robots");
 * echo $sql; // SELECT * FROM robots FOR UPDATE
 *
 * $sql = $dialect->forUpdate(
 *     "SELECT * FROM robots",
 *     Dialect::LOCK_NOWAIT
 * );
 * echo $sql; // SELECT * FROM robots FOR UPDATE NOWAIT
 *
 * $sql = $dialect->forUpdate(
 *     "SELECT * FROM robots",
 *     Dialect::LOCK_SKIP_LOCKED
 * );
 * echo $sql; // SELECT * FROM robots FOR UPDATE SKIP LOCKED
 *```
 */
PHP_METHOD(Phalcon_Db_Dialect, forUpdate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval sqlQuery_zv, modifier_zv;
	zend_string *sqlQuery = NULL, *modifier = NULL;

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&modifier_zv);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(sqlQuery)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(modifier)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
	if (!modifier) {
		modifier = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&modifier_zv);
		ZVAL_STR(&modifier_zv, modifier);
	} else {
		zephir_memory_observe(&modifier_zv);
	ZVAL_STR_COPY(&modifier_zv, modifier);
	}
	if (!ZEPHIR_IS_STRING_IDENTICAL(&modifier_zv, "")) {
		ZEPHIR_CONCAT_VSV(return_value, &sqlQuery_zv, " FOR UPDATE ", &modifier_zv);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_VS(return_value, &sqlQuery_zv, " FOR UPDATE");
	RETURN_MM();
}

/**
 * Gets a list of columns with escaped identifiers
 *
 * ```php
 * echo $dialect->getColumnList(
 *     [
 *         "column1",
 *         "column",
 *     ]
 * );
 * ```
 */
PHP_METHOD(Phalcon_Db_Dialect, getColumnList)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *columnList_param = NULL, escapeChar_zv, *bindCounts_param = NULL, column, *_0, _3, _1$$3, _5$$4;
	zval columnList, bindCounts, columns;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnList);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(columnList, columnList_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	columnList_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&columnList, columnList_param);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	zephir_is_iterable(&columnList, 0, "phalcon/Db/Dialect.zep", 174);
	if (Z_TYPE_P(&columnList) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columnList), _0)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _0);
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getsqlcolumn", &_2, 87, &column, &escapeChar_zv, &bindCounts);
			zephir_check_call_status();
			zephir_array_append(&columns, &_1$$3, PH_SEPARATE, "phalcon/Db/Dialect.zep", 171);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columnList, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &columnList, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &columnList, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &columnList, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getsqlcolumn", &_2, 87, &column, &escapeChar_zv, &bindCounts);
				zephir_check_call_status();
				zephir_array_append(&columns, &_5$$4, PH_SEPARATE, "phalcon/Db/Dialect.zep", 171);
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	zephir_fast_join_str(return_value, SL(", "), &columns);
	RETURN_MM();
}

/**
 * Returns registered functions
 */
PHP_METHOD(Phalcon_Db_Dialect, getCustomFunctions)
{

	RETURN_MEMBER_TYPED(getThis(), "customFunctions", IS_ARRAY);
}

/**
 * Resolve Column expressions
 *
 * @param array|string column
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlColumn)
{
	zend_bool _5, _3$$4, _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindCounts;
	zend_string *escapeChar = NULL;
	zval *column = NULL, column_sub, escapeChar_zv, *bindCounts_param = NULL, columnExpression, columnAlias, columnField, columnDomain, _6, _0$$3, _1$$6, _2$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&columnExpression);
	ZVAL_UNDEF(&columnAlias);
	ZVAL_UNDEF(&columnField);
	ZVAL_UNDEF(&columnDomain);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&bindCounts);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(column)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	column = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_SEPARATE_PARAM(column);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	if (Z_TYPE_P(column) != IS_ARRAY) {
		ZVAL_NULL(&_0$$3);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparequalified", NULL, 0, column, &_0$$3, &escapeChar_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (!(zephir_array_isset_value_string(column, SL("type")))) {
		zephir_memory_observe(&columnField);
		zephir_array_fetch_long(&columnField, column, 0, PH_NOISY, "phalcon/Db/Dialect.zep", 206);
		if (Z_TYPE_P(&columnField) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&columnExpression);
			zephir_create_array(&columnExpression, 2, 0);
			add_assoc_stringl_ex(&columnExpression, SL("type"), SL("scalar"));
			zephir_array_update_string(&columnExpression, SL("value"), &columnField, PH_COPY | PH_SEPARATE);
		} else if (ZEPHIR_IS_STRING_IDENTICAL(&columnField, "*")) {
			ZEPHIR_INIT_VAR(&_1$$6);
			zephir_create_array(&_1$$6, 1, 0);
			add_assoc_stringl_ex(&_1$$6, SL("type"), SL("all"));
			ZEPHIR_CPY_WRT(&columnExpression, &_1$$6);
		} else {
			ZEPHIR_INIT_VAR(&_2$$7);
			zephir_create_array(&_2$$7, 2, 0);
			add_assoc_stringl_ex(&_2$$7, SL("type"), SL("qualified"));
			zephir_array_update_string(&_2$$7, SL("name"), &columnField, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&columnExpression, &_2$$7);
		}
		zephir_memory_observe(&columnDomain);
		_3$$4 = zephir_array_isset_long_fetch(&columnDomain, column, 1, 0);
		if (_3$$4) {
			_3$$4 = !ZEPHIR_IS_STRING_IDENTICAL(&columnDomain, "");
		}
		if (_3$$4) {
			zephir_array_update_string(&columnExpression, SL("domain"), &columnDomain, PH_COPY | PH_SEPARATE);
		}
		zephir_memory_observe(&columnAlias);
		_4$$4 = zephir_array_isset_long_fetch(&columnAlias, column, 2, 0);
		if (_4$$4) {
			_4$$4 = zephir_is_true(&columnAlias);
		}
		if (_4$$4) {
			zephir_array_update_string(&columnExpression, SL("sqlAlias"), &columnAlias, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_CPY_WRT(&columnExpression, column);
	}
	ZEPHIR_CALL_METHOD(column, this_ptr, "getsqlexpression", NULL, 0, &columnExpression, &escapeChar_zv, &bindCounts);
	zephir_check_call_status();
	ZEPHIR_OBS_NVAR(&columnAlias);
	_5 = zephir_array_isset_string_fetch(&columnAlias, &columnExpression, SL("sqlAlias"), 0);
	if (!(_5)) {
		ZEPHIR_OBS_NVAR(&columnAlias);
		_5 = zephir_array_isset_string_fetch(&columnAlias, &columnExpression, SL("alias"), 0);
	}
	if (_5) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparecolumnalias", NULL, 0, column, &columnAlias, &escapeChar_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_NULL(&_6);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparecolumnalias", NULL, 0, column, &_6, &escapeChar_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Transforms an intermediate representation for an expression into a database system valid expression
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpression)
{
	zend_bool _2$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, _3$$9;
	zend_string *escapeChar = NULL;
	zval *expression_param = NULL, escapeChar_zv, *bindCounts_param = NULL, type, times, postTimes, rawValue, value, nestedDefinition, _11, _0$$3, _1$$7, _4$$9, _5$$11, _6$$11, _7$$8, _8$$14, _9$$14, _10$$18;
	zval expression, bindCounts, placeholders;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&times);
	ZVAL_UNDEF(&postTimes);
	ZVAL_UNDEF(&rawValue);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&nestedDefinition);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_10$$18);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(expression, expression_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	zephir_memory_observe(&type);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&type, &expression, SL("type"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_db_exceptions_invalidsqlexpression_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 88);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Db/Dialect.zep", 270);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (ZEPHIR_IS_STRING(&type, "scalar")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionscalar", NULL, 89, &expression, &escapeChar_zv, &bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "object")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionobject", NULL, 90, &expression, &escapeChar_zv, &bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "qualified")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionqualified", NULL, 91, &expression, &escapeChar_zv);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "literal")) {
			zephir_array_fetch_string(&_1$$7, &expression, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 304);
			RETURN_CTOR(&_1$$7);
		}
		if (ZEPHIR_IS_STRING(&type, "placeholder")) {
			zephir_memory_observe(&times);
			if (zephir_array_isset_string_fetch(&times, &expression, SL("times"), 0)) {
				ZEPHIR_INIT_VAR(&placeholders);
				array_init(&placeholders);
				zephir_memory_observe(&rawValue);
				zephir_array_fetch_string(&rawValue, &expression, SL("rawValue"), PH_NOISY, "phalcon/Db/Dialect.zep", 310);
				zephir_memory_observe(&value);
				zephir_array_fetch_string(&value, &expression, SL("value"), PH_NOISY, "phalcon/Db/Dialect.zep", 311);
				zephir_memory_observe(&postTimes);
				if (zephir_array_isset_fetch(&postTimes, &bindCounts, &rawValue, 0)) {
					ZEPHIR_CPY_WRT(&times, &postTimes);
				}
				ZEPHIR_CPY_WRT(&_4$$9, &times);
				_3$$9 = 1;
				_2$$9 = 0;
				if (ZEPHIR_GE_LONG(&_4$$9, _3$$9)) {
					while (1) {
						if (_2$$9) {
							_3$$9++;
							if (!(ZEPHIR_GE_LONG(&_4$$9, _3$$9))) {
								break;
							}
						} else {
							_2$$9 = 1;
						}
						i = _3$$9;
						ZEPHIR_INIT_NVAR(&_5$$11);
						ZVAL_LONG(&_5$$11, ((i - 1)));
						ZEPHIR_INIT_NVAR(&_6$$11);
						ZEPHIR_CONCAT_VV(&_6$$11, &value, &_5$$11);
						zephir_array_append(&placeholders, &_6$$11, PH_SEPARATE, "phalcon/Db/Dialect.zep", 318);
					}
				}
				zephir_fast_join_str(return_value, SL(", "), &placeholders);
				RETURN_MM();
			}
			zephir_array_fetch_string(&_7$$8, &expression, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 324);
			RETURN_CTOR(&_7$$8);
		}
		if (ZEPHIR_IS_STRING(&type, "binary-op")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionbinaryoperations", NULL, 92, &expression, &escapeChar_zv, &bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "unary-op")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionunaryoperations", NULL, 93, &expression, &escapeChar_zv, &bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "parentheses")) {
			zephir_array_fetch_string(&_9$$14, &expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 350);
			ZEPHIR_CALL_METHOD(&_8$$14, this_ptr, "getsqlexpression", NULL, 94, &_9$$14, &escapeChar_zv, &bindCounts);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVS(return_value, "(", &_8$$14, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "functionCall")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionfunctioncall", NULL, 95, &expression, &escapeChar_zv, &bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "list")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionlist", NULL, 96, &expression, &escapeChar_zv, &bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "all")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionall", NULL, 97, &expression, &escapeChar_zv);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "select")) {
			zephir_memory_observe(&nestedDefinition);
			zephir_array_fetch_string(&nestedDefinition, &expression, SL("value"), PH_NOISY, "phalcon/Db/Dialect.zep", 389);
			if (zephir_fast_count_int(&bindCounts)) {
				zephir_array_update_string(&nestedDefinition, SL("bindCounts"), &bindCounts, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_CALL_METHOD(&_10$$18, this_ptr, "select", NULL, 0, &nestedDefinition);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVS(return_value, "(", &_10$$18, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "cast")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressioncastvalue", NULL, 98, &expression, &escapeChar_zv, &bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "convert")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressionconvertvalue", NULL, 99, &expression, &escapeChar_zv, &bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "case")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpressioncase", NULL, 100, &expression, &escapeChar_zv, &bindCounts);
			zephir_check_call_status();
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_INIT_VAR(&_11);
	object_init_ex(&_11, phalcon_db_exceptions_invalidsqlexpressiontype_ce);
	ZEPHIR_CALL_METHOD(NULL, &_11, "__construct", NULL, 101, &type);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_11, "phalcon/Db/Dialect.zep", 426);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Transform an intermediate representation of a schema/table into a
 * database system valid expression
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlTable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *table, table_sub, escapeChar_zv, tableName, schemaName, aliasName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&aliasName);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	table = ZEND_CALL_ARG(execute_data, 1);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (Z_TYPE_P(table) == IS_ARRAY) {
		zephir_memory_observe(&tableName);
		zephir_array_fetch_long(&tableName, table, 0, PH_NOISY, "phalcon/Db/Dialect.zep", 442);
		zephir_memory_observe(&schemaName);
		zephir_array_isset_long_fetch(&schemaName, table, 1, 0);
		zephir_memory_observe(&aliasName);
		zephir_array_isset_long_fetch(&aliasName, table, 2, 0);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparetable", NULL, 0, &tableName, &schemaName, &aliasName, &escapeChar_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", NULL, 102, table, &escapeChar_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates the SQL for LIMIT clause
 *
 * ```php
 * // SELECT * FROM robots LIMIT 10
 * echo $dialect->limit(
 *     "SELECT * FROM robots",
 *     10
 * );
 *
 * // SELECT * FROM robots LIMIT 10 OFFSET 50
 * echo $dialect->limit(
 *     "SELECT * FROM robots",
 *     [10, 50]
 * );
 * ```
 */
PHP_METHOD(Phalcon_Db_Dialect, limit)
{
	zend_bool _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sqlQuery_param = NULL, *number, number_sub, _0$$3, _1$$3, _3$$3, _4$$4, _5$$4;
	zval sqlQuery;

	ZVAL_UNDEF(&sqlQuery);
	ZVAL_UNDEF(&number_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(sqlQuery_param)
		Z_PARAM_ZVAL(number)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &sqlQuery_param, &number);
	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(&sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlQuery);
	}
	if (Z_TYPE_P(number) == IS_ARRAY) {
		zephir_array_fetch_long(&_0$$3, number, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 485);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SV(&_1$$3, " LIMIT ", &_0$$3);
		zephir_concat_self(&sqlQuery, &_1$$3);
		_2$$3 = zephir_array_isset_value_long(number, 1);
		if (_2$$3) {
			zephir_array_fetch_long(&_3$$3, number, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 487);
			_2$$3 = ((zephir_fast_strlen_ev(&_3$$3)) ? 1 : 0);
		}
		if (_2$$3) {
			zephir_array_fetch_long(&_4$$4, number, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 488);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZEPHIR_CONCAT_SV(&_5$$4, " OFFSET ", &_4$$4);
			zephir_concat_self(&sqlQuery, &_5$$4);
		}
		RETURN_CTOR(&sqlQuery);
	}
	ZEPHIR_CONCAT_VSV(return_value, &sqlQuery, " LIMIT ", number);
	RETURN_MM();
}

/**
 * Registers custom SQL functions
 */
PHP_METHOD(Phalcon_Db_Dialect, registerCustomFunction)
{
	zval name_zv, *customFunction, customFunction_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&customFunction_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(customFunction)
	ZEND_PARSE_PARAMETERS_END();
	customFunction = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("customFunctions"), &name_zv, customFunction);
	RETURN_THISW();
}

/**
 * Generates SQL to create a materialized view. Supported by PostgreSQL
 * (`CREATE MATERIALIZED VIEW name AS <sql>`). Other dialects inherit
 * this throw - MySQL and SQLite have no materialized-view concept.
 */
PHP_METHOD(Phalcon_Db_Dialect, createMaterializedView)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval viewName_zv, *definition_param = NULL, schemaName_zv, _0;
	zend_string *viewName = NULL, *schemaName = NULL;

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&definition);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(viewName)
		ZEPHIR_Z_PARAM_ARRAY(definition, definition_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&viewName_zv);
	ZVAL_STR_COPY(&viewName_zv, viewName);
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_db_exceptions_materializedviewsnotsupported_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 103);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect.zep", 514);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Generates SQL to drop a materialized view. Supported by PostgreSQL.
 */
PHP_METHOD(Phalcon_Db_Dialect, dropMaterializedView)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval viewName_zv, schemaName_zv, *ifExists_param = NULL, _0;
	zend_string *viewName = NULL, *schemaName = NULL;

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(viewName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
		Z_PARAM_BOOL(ifExists)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		ifExists_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&viewName_zv);
	ZVAL_STR_COPY(&viewName_zv, viewName);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_db_exceptions_materializedviewsnotsupported_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 103);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect.zep", 522);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Generates SQL to refresh a materialized view. Supported by
 * PostgreSQL. Pass `concurrent = true` for `REFRESH MATERIALIZED VIEW
 * CONCURRENTLY ...`, which avoids blocking concurrent SELECTs (requires
 * the view to have a unique index).
 */
PHP_METHOD(Phalcon_Db_Dialect, refreshMaterializedView)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool concurrent;
	zval viewName_zv, schemaName_zv, *concurrent_param = NULL, _0;
	zend_string *viewName = NULL, *schemaName = NULL;

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(viewName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
		Z_PARAM_BOOL(concurrent)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		concurrent_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&viewName_zv);
	ZVAL_STR_COPY(&viewName_zv, viewName);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	if (!concurrent_param) {
		concurrent = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_db_exceptions_materializedviewsnotsupported_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 103);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect.zep", 533);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Appends an `ON CONFLICT (col, ...) DO UPDATE SET col = excluded.col`
 * upsert clause to the supplied INSERT statement. The syntax is the
 * SQL standard form recognized by PostgreSQL (9.5+) and SQLite (3.24+).
 * MySQL overrides this method to throw because its `ON DUPLICATE KEY
 * UPDATE` has a different shape (deferred to parser item #23).
 */
PHP_METHOD(Phalcon_Db_Dialect, onConflictUpdate)
{
	zval _4$$5, _7$$5, _12$$6, _14$$6;
	zend_bool _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval conflictColumns, updateColumns, assignments;
	zval sqlQuery_zv, *conflictColumns_param = NULL, *updateColumns_param = NULL, col, *_2, _9, _16, _17, _0$$3, _1$$4, _3$$5, _6$$5, _8$$5, _11$$6, _13$$6, _15$$6;
	zend_string *sqlQuery = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&col);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&conflictColumns);
	ZVAL_UNDEF(&updateColumns);
	ZVAL_UNDEF(&assignments);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$6);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(sqlQuery)
		ZEPHIR_Z_PARAM_ARRAY(conflictColumns, conflictColumns_param)
		ZEPHIR_Z_PARAM_ARRAY(updateColumns, updateColumns_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	conflictColumns_param = ZEND_CALL_ARG(execute_data, 2);
	updateColumns_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
	ZEPHIR_OBS_COPY_OR_DUP(&conflictColumns, conflictColumns_param);
	ZEPHIR_OBS_COPY_OR_DUP(&updateColumns, updateColumns_param);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&conflictColumns))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_db_exceptions_conflicttargetcolumnrequired_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 104);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Db/Dialect.zep", 549);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&updateColumns))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_db_exceptions_conflictupdatecolumnrequired_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 105);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Db/Dialect.zep", 553);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&assignments);
	array_init(&assignments);
	zephir_is_iterable(&updateColumns, 0, "phalcon/Db/Dialect.zep", 562);
	if (Z_TYPE_P(&updateColumns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&updateColumns), _2)
		{
			ZEPHIR_INIT_NVAR(&col);
			ZVAL_COPY(&col, _2);
			zephir_cast_to_string(&_4$$5, &col);
			ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "escape", &_5, 102, &_4$$5);
			zephir_check_call_status();
			zephir_cast_to_string(&_7$$5, &col);
			ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "escape", &_5, 102, &_7$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$5);
			ZEPHIR_CONCAT_VSV(&_8$$5, &_3$$5, " = excluded.", &_6$$5);
			zephir_array_append(&assignments, &_8$$5, PH_SEPARATE, "phalcon/Db/Dialect.zep", 559);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &updateColumns, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &updateColumns, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, &updateColumns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&col, &updateColumns, "current", NULL, 0);
			zephir_check_call_status();
				zephir_cast_to_string(&_12$$6, &col);
				ZEPHIR_CALL_METHOD(&_11$$6, this_ptr, "escape", &_5, 102, &_12$$6);
				zephir_check_call_status();
				zephir_cast_to_string(&_14$$6, &col);
				ZEPHIR_CALL_METHOD(&_13$$6, this_ptr, "escape", &_5, 102, &_14$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$6);
				ZEPHIR_CONCAT_VSV(&_15$$6, &_11$$6, " = excluded.", &_13$$6);
				zephir_array_append(&assignments, &_15$$6, PH_SEPARATE, "phalcon/Db/Dialect.zep", 559);
		}
	}
	ZEPHIR_INIT_NVAR(&col);
	ZEPHIR_CALL_METHOD(&_16, this_ptr, "getcolumnlist", NULL, 106, &conflictColumns);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_17);
	zephir_fast_join_str(&_17, SL(", "), &assignments);
	ZEPHIR_CONCAT_VSVSSV(return_value, &sqlQuery_zv, " ON CONFLICT (", &_16, ")", " DO UPDATE SET ", &_17);
	RETURN_MM();
}

/**
 * Returns a SQL statement extended with a `RETURNING` clause so the
 * INSERT/UPDATE/DELETE returns rows. Supported by PostgreSQL and
 * SQLite 3.35+. Pass `["*"]` for `RETURNING *`, or a list of column
 * names. The base implementation throws - MySQL inherits it because
 * MySQL has no RETURNING construct.
 */
PHP_METHOD(Phalcon_Db_Dialect, returning)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval columns;
	zval sqlQuery_zv, *columns_param = NULL, _0;
	zend_string *sqlQuery = NULL;

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&columns);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(sqlQuery)
		ZEPHIR_Z_PARAM_ARRAY(columns, columns_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	columns_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
	ZEPHIR_OBS_COPY_OR_DUP(&columns, columns_param);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_db_exceptions_returningnotsupported_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 107);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect.zep", 576);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Generate SQL to release a savepoint
 */
PHP_METHOD(Phalcon_Db_Dialect, releaseSavepoint)
{
	zval name_zv;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	ZEPHIR_CONCAT_SV(return_value, "RELEASE SAVEPOINT ", &name_zv);
	return;
}

/**
 * Generate SQL to rollback a savepoint
 */
PHP_METHOD(Phalcon_Db_Dialect, rollbackSavepoint)
{
	zval name_zv;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	ZEPHIR_CONCAT_SV(return_value, "ROLLBACK TO SAVEPOINT ", &name_zv);
	return;
}

/**
 * Builds a SELECT statement
 */
PHP_METHOD(Phalcon_Db_Dialect, select)
{
	zend_bool _2, _5, _7, _9, _11, _13, _15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *definition_param = NULL, tables, columns, sql, distinct, joins, where, escapeChar, groupBy, having, orderBy, limit, forUpdate, bindCounts, _0, _1, _3$$10, _4$$10, _6$$11, _8$$12, _10$$13, _12$$14;
	zval definition, parts, _14$$15;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_14$$15);
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
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_12$$14);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(definition, definition_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &definition_param);
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	zephir_memory_observe(&tables);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&tables, &definition, SL("tables"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_missingdefinitionkey_ce, "tables", "phalcon/Db/Dialect.zep", 605);
		return;
	}
	zephir_memory_observe(&columns);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_missingdefinitionkey_ce, "columns", "phalcon/Db/Dialect.zep", 609);
		return;
	}
	zephir_memory_observe(&distinct);
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
	zephir_memory_observe(&bindCounts);
	zephir_array_isset_string_fetch(&bindCounts, &definition, SL("bindCounts"), 0);
	if (Z_TYPE_P(&bindCounts) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&bindCounts);
		array_init(&bindCounts);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("escapeChar"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&escapeChar, &_0);
	ZEPHIR_INIT_VAR(&parts);
	zephir_create_array(&parts, 3, 0);
	zephir_array_fast_append(&parts, &sql);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcolumnlist", NULL, 106, &columns, &escapeChar, &bindCounts);
	zephir_check_call_status();
	zephir_array_fast_append(&parts, &_1);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getsqlexpressionfrom", NULL, 108, &tables, &escapeChar);
	zephir_check_call_status();
	zephir_array_fast_append(&parts, &_1);
	zephir_memory_observe(&joins);
	_2 = zephir_array_isset_string_fetch(&joins, &definition, SL("joins"), 0);
	if (_2) {
		_2 = zephir_is_true(&joins);
	}
	if (_2) {
		zephir_array_fetch_string(&_4$$10, &definition, SL("joins"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 642);
		ZEPHIR_CALL_METHOD(&_3$$10, this_ptr, "getsqlexpressionjoins", NULL, 109, &_4$$10, &escapeChar, &bindCounts);
		zephir_check_call_status();
		zephir_array_append(&parts, &_3$$10, PH_SEPARATE, "phalcon/Db/Dialect.zep", 642);
	}
	zephir_memory_observe(&where);
	_5 = zephir_array_isset_string_fetch(&where, &definition, SL("where"), 0);
	if (_5) {
		_5 = zephir_is_true(&where);
	}
	if (_5) {
		ZEPHIR_CALL_METHOD(&_6$$11, this_ptr, "getsqlexpressionwhere", NULL, 110, &where, &escapeChar, &bindCounts);
		zephir_check_call_status();
		zephir_array_append(&parts, &_6$$11, PH_SEPARATE, "phalcon/Db/Dialect.zep", 646);
	}
	zephir_memory_observe(&groupBy);
	_7 = zephir_array_isset_string_fetch(&groupBy, &definition, SL("group"), 0);
	if (_7) {
		_7 = zephir_is_true(&groupBy);
	}
	if (_7) {
		ZEPHIR_CALL_METHOD(&_8$$12, this_ptr, "getsqlexpressiongroupby", NULL, 111, &groupBy, &escapeChar);
		zephir_check_call_status();
		zephir_array_append(&parts, &_8$$12, PH_SEPARATE, "phalcon/Db/Dialect.zep", 650);
	}
	zephir_memory_observe(&having);
	_9 = zephir_array_isset_string_fetch(&having, &definition, SL("having"), 0);
	if (_9) {
		_9 = zephir_is_true(&having);
	}
	if (_9) {
		ZEPHIR_CALL_METHOD(&_10$$13, this_ptr, "getsqlexpressionhaving", NULL, 112, &having, &escapeChar, &bindCounts);
		zephir_check_call_status();
		zephir_array_append(&parts, &_10$$13, PH_SEPARATE, "phalcon/Db/Dialect.zep", 654);
	}
	zephir_memory_observe(&orderBy);
	_11 = zephir_array_isset_string_fetch(&orderBy, &definition, SL("order"), 0);
	if (_11) {
		_11 = zephir_is_true(&orderBy);
	}
	if (_11) {
		ZEPHIR_CALL_METHOD(&_12$$14, this_ptr, "getsqlexpressionorderby", NULL, 113, &orderBy, &escapeChar, &bindCounts);
		zephir_check_call_status();
		zephir_array_append(&parts, &_12$$14, PH_SEPARATE, "phalcon/Db/Dialect.zep", 658);
	}
	ZEPHIR_INIT_NVAR(&sql);
	zephir_fast_join_str(&sql, SL(" "), &parts);
	zephir_memory_observe(&limit);
	_13 = zephir_array_isset_string_fetch(&limit, &definition, SL("limit"), 0);
	if (_13) {
		_13 = zephir_is_true(&limit);
	}
	if (_13) {
		ZEPHIR_INIT_VAR(&_14$$15);
		zephir_create_array(&_14$$15, 2, 0);
		zephir_array_update_string(&_14$$15, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_14$$15, SL("value"), &limit, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&sql, this_ptr, "getsqlexpressionlimit", NULL, 114, &_14$$15, &escapeChar, &bindCounts);
		zephir_check_call_status();
	}
	_15 = zephir_array_isset_string_fetch(&forUpdate, &definition, SL("forUpdate"), 1);
	if (_15) {
		_15 = zephir_is_true(&forUpdate);
	}
	if (_15) {
		zephir_concat_self_str(&sql, SL(" FOR UPDATE"));
	}
	RETURN_CCTOR(&sql);
}

/**
 * Checks whether the platform supports savepoints
 */
PHP_METHOD(Phalcon_Db_Dialect, supportsSavepoints)
{

	RETURN_BOOL(1);
}

/**
 * Checks whether the platform supports releasing savepoints.
 */
PHP_METHOD(Phalcon_Db_Dialect, supportsReleaseSavepoints)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "supportssavepoints", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks whether the platform supports the full `ALTER TABLE` matrix:
 * modifying existing columns and adding or dropping foreign keys, primary
 * keys, and check constraints. SQLite returns false - those operations
 * throw a dedicated `Sqlite*NotSupported` exception there (basic
 * `ADD COLUMN` remains available).
 */
PHP_METHOD(Phalcon_Db_Dialect, supportsAlterTable)
{

	RETURN_BOOL(1);
}

/**
 * Checks whether the platform supports materialized views. Only PostgreSQL
 * returns true; `createMaterializedView()` throws on the other dialects.
 */
PHP_METHOD(Phalcon_Db_Dialect, supportsMaterializedViews)
{

	RETURN_BOOL(0);
}

/**
 * Checks whether the platform supports the `ON CONFLICT (...) DO UPDATE`
 * upsert clause. MySQL returns false; `onConflictUpdate()` throws there.
 */
PHP_METHOD(Phalcon_Db_Dialect, supportsOnConflictUpdate)
{

	RETURN_BOOL(1);
}

/**
 * Checks whether the platform supports the `RETURNING` clause. MySQL
 * returns false; `returning()` throws there.
 */
PHP_METHOD(Phalcon_Db_Dialect, supportsReturning)
{

	RETURN_BOOL(0);
}

/**
 * Returns the size of the column enclosed in parentheses
 */
PHP_METHOD(Phalcon_Db_Dialect, getColumnSize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, _0;

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &column);
	ZEPHIR_CALL_METHOD(&_0, column, "getsize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "(", &_0, ")");
	RETURN_MM();
}

/**
 * Returns the column size and scale enclosed in parentheses
 */
PHP_METHOD(Phalcon_Db_Dialect, getColumnSizeAndScale)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, _0, _1;

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &column);
	ZEPHIR_CALL_METHOD(&_0, column, "getsize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, column, "getscale", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "(", &_0, ",", &_1, ")");
	RETURN_MM();
}

/**
 * Checks the column type and if not string it returns the type reference
 */
PHP_METHOD(Phalcon_Db_Dialect, checkColumnType)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, _0;

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Phalcon_Db_Dialect, checkColumnTypeSql)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, _0;

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &column);
	ZEPHIR_CALL_METHOD(&_0, column, "gettype", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) != IS_STRING) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_RETURN_CALL_METHOD(column, "gettype", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a CHECK constraint clause from a `CheckInterface`, using the
 * provided escape character for the constraint name (so each dialect
 * gets its native quoting). Returns the clause body - the dialect's
 * `createTable()` / `addCheck()` is expected to prefix `ADD` or place
 * the result on its own line as appropriate.
 */
PHP_METHOD(Phalcon_Db_Dialect, getCheckClause)
{
	zval clause;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *check, check_sub, escapeChar_zv, name, _1, _2, _0$$3;

	ZVAL_UNDEF(&check_sub);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&clause);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(check, phalcon_db_checkinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(escapeChar)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	check = ZEND_CALL_ARG(execute_data, 1);
	if (!escapeChar) {
		escapeChar = zend_string_init(ZEND_STRL("`"), 0);
		zephir_memory_observe(&escapeChar_zv);
		ZVAL_STR(&escapeChar_zv, escapeChar);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	ZEPHIR_CALL_METHOD(&name, check, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&clause);
	ZVAL_STRING(&clause, "");
	if (!ZEPHIR_IS_STRING_IDENTICAL(&name, "")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVVVS(&_0$$3, "CONSTRAINT ", &escapeChar_zv, &name, &escapeChar_zv, " ");
		zephir_get_strval(&clause, &_0$$3);
	}
	ZEPHIR_CALL_METHOD(&_1, check, "getexpression", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "CHECK (", &_1, ")");
	zephir_concat_self(&clause, &_2);
	RETURN_CTOR(&clause);
}

/**
 * Builds the per-index parenthesized column list, honoring per-column
 * sort directions when the index declares any. Returns the bare
 * comma-separated `getColumnList()` output when no directions are set,
 * preserving the legacy rendering exactly. When directions are set,
 * each column is followed by ` ASC` or ` DESC`; trailing positions
 * absent from the directions array default to `ASC`.
 */
PHP_METHOD(Phalcon_Db_Dialect, getIndexColumnList)
{
	zval _10$$14, _15$$24;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0;
	zend_bool wrapExpressions, hasExpression = 0, _3, _5, _12, _1$$3, _4$$5, _7$$8, _13$$18;
	zval *index, index_sub, *wrapExpressions_param = NULL, columns, directions, parts, column, direction, upper, rendered, *_0, _2, *_6, _11, _8$$10, _14$$20;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&directions);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&direction);
	ZVAL_UNDEF(&upper);
	ZVAL_UNDEF(&rendered);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_14$$20);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_15$$24);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(index, phalcon_db_indexinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(wrapExpressions)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &index, &wrapExpressions_param);
	if (!wrapExpressions_param) {
		wrapExpressions = 1;
	} else {
		}
	ZEPHIR_CALL_METHOD(&columns, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&directions, index, "getdirections", NULL, 0);
	zephir_check_call_status();
	hasExpression = 0;
	zephir_is_iterable(&columns, 0, "phalcon/Db/Dialect.zep", 835);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _0)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _0);
			_1$$3 = Z_TYPE_P(&column) == IS_OBJECT;
			if (_1$$3) {
				_1$$3 = zephir_instance_of_ev(&column, phalcon_db_rawvalue_ce);
			}
			if (_1$$3) {
				hasExpression = 1;
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
		zephir_check_call_status();
		_3 = 1;
		while (1) {
			if (_3) {
				_3 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_2, &columns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &columns, "current", NULL, 0);
			zephir_check_call_status();
				_4$$5 = Z_TYPE_P(&column) == IS_OBJECT;
				if (_4$$5) {
					_4$$5 = zephir_instance_of_ev(&column, phalcon_db_rawvalue_ce);
				}
				if (_4$$5) {
					hasExpression = 1;
					break;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	_5 = !hasExpression;
	if (_5) {
		_5 = ZEPHIR_IS_EMPTY(&directions);
	}
	if (_5) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcolumnlist", NULL, 106, &columns);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	i = 0;
	zephir_is_iterable(&columns, 0, "phalcon/Db/Dialect.zep", 871);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _6)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _6);
			_7$$8 = Z_TYPE_P(&column) == IS_OBJECT;
			if (_7$$8) {
				_7$$8 = zephir_instance_of_ev(&column, phalcon_db_rawvalue_ce);
			}
			if (_7$$8) {
				if (wrapExpressions) {
					ZEPHIR_CALL_METHOD(&_8$$10, &column, "getvalue", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&rendered);
					ZEPHIR_CONCAT_SVS(&rendered, "(", &_8$$10, ")");
				} else {
					ZEPHIR_CALL_METHOD(&rendered, &column, "getvalue", NULL, 0);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_CALL_METHOD(&rendered, this_ptr, "escape", &_9, 102, &column);
				zephir_check_call_status();
			}
			if (!(ZEPHIR_IS_EMPTY(&directions))) {
				ZEPHIR_OBS_NVAR(&direction);
				if (zephir_array_isset_long_fetch(&direction, &directions, i, 0)) {
					zephir_cast_to_string(&_10$$14, &direction);
					ZEPHIR_INIT_NVAR(&upper);
					zephir_fast_strtoupper(&upper, &_10$$14);
					if (ZEPHIR_IS_STRING(&upper, "DESC")) {
						zephir_concat_self_str(&rendered, SL(" DESC"));
					} else {
						zephir_concat_self_str(&rendered, SL(" ASC"));
					}
				} else {
					zephir_concat_self_str(&rendered, SL(" ASC"));
				}
			}
			zephir_array_append(&parts, &rendered, PH_SEPARATE, "phalcon/Db/Dialect.zep", 867);
			i = (i + 1);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, &columns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &columns, "current", NULL, 0);
			zephir_check_call_status();
				_13$$18 = Z_TYPE_P(&column) == IS_OBJECT;
				if (_13$$18) {
					_13$$18 = zephir_instance_of_ev(&column, phalcon_db_rawvalue_ce);
				}
				if (_13$$18) {
					if (wrapExpressions) {
						ZEPHIR_CALL_METHOD(&_14$$20, &column, "getvalue", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&rendered);
						ZEPHIR_CONCAT_SVS(&rendered, "(", &_14$$20, ")");
					} else {
						ZEPHIR_CALL_METHOD(&rendered, &column, "getvalue", NULL, 0);
						zephir_check_call_status();
					}
				} else {
					ZEPHIR_CALL_METHOD(&rendered, this_ptr, "escape", &_9, 102, &column);
					zephir_check_call_status();
				}
				if (!(ZEPHIR_IS_EMPTY(&directions))) {
					ZEPHIR_OBS_NVAR(&direction);
					if (zephir_array_isset_long_fetch(&direction, &directions, i, 0)) {
						zephir_cast_to_string(&_15$$24, &direction);
						ZEPHIR_INIT_NVAR(&upper);
						zephir_fast_strtoupper(&upper, &_15$$24);
						if (ZEPHIR_IS_STRING(&upper, "DESC")) {
							zephir_concat_self_str(&rendered, SL(" DESC"));
						} else {
							zephir_concat_self_str(&rendered, SL(" ASC"));
						}
					} else {
						zephir_concat_self_str(&rendered, SL(" ASC"));
					}
				}
				zephir_array_append(&parts, &rendered, PH_SEPARATE, "phalcon/Db/Dialect.zep", 867);
				i = (i + 1);
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	zephir_fast_join_str(return_value, SL(", "), &parts);
	RETURN_MM();
}

/**
 * Builds the `GENERATED ALWAYS AS (<expr>) VIRTUAL|STORED` clause for a
 * generated/computed column. Returns an empty string when the column is
 * not generated. When `forceStored` is `true` the clause is always emitted
 * as `STORED` regardless of the column's `isGenerationStored()` flag -
 * PostgreSQL uses this since it only supports stored generated columns.
 */
PHP_METHOD(Phalcon_Db_Dialect, getGeneratedClause)
{
	zval storage;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool forceStored, _1;
	zval *column, column_sub, *forceStored_param = NULL, expression, _0, _2;

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&storage);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(forceStored)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &column, &forceStored_param);
	if (!forceStored_param) {
		forceStored = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&_0, column, "isgenerated", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_CALL_METHOD(&expression, column, "getgenerationexpression", NULL, 0);
	zephir_check_call_status();
	_1 = forceStored;
	if (!(_1)) {
		ZEPHIR_CALL_METHOD(&_2, column, "isgenerationstored", NULL, 0);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&storage);
		ZVAL_STRING(&storage, "STORED");
	} else {
		ZEPHIR_INIT_NVAR(&storage);
		ZVAL_STRING(&storage, "VIRTUAL");
	}
	ZEPHIR_CONCAT_SVSV(return_value, " GENERATED ALWAYS AS (", &expression, ") ", &storage);
	RETURN_MM();
}

/**
 * Resolve *
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionAll)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *expression_param = NULL, escapeChar_zv, domain, _0;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(expression, expression_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression_param = ZEND_CALL_ARG(execute_data, 1);
	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	zephir_memory_observe(&domain);
	zephir_array_isset_string_fetch(&domain, &expression, SL("domain"), 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "*");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparequalified", NULL, 0, &_0, &domain, &escapeChar_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolve binary operations expressions
 *
 * @param array expression
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionBinaryOperations)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *expression_param = NULL, escapeChar_zv, *bindCounts_param = NULL, left, right, operator, _0, _2, _4, _5, _3$$3;
	zval expression, bindCounts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(expression, expression_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	zephir_memory_observe(&operator);
	zephir_array_fetch_string(&operator, &expression, SL("op"), PH_NOISY, "phalcon/Db/Dialect.zep", 926);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("guardedOperators"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_fast_in_array(&operator, &_0);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("supportedOperators"), PH_NOISY_CC | PH_READONLY);
		_1 = !(zephir_fast_in_array(&operator, &_2));
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_db_exceptions_unsupportedoperator_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 115, &operator);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Db/Dialect.zep", 929);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_4, &expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 933);
	ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", NULL, 0, &_4, &escapeChar_zv, &bindCounts);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, &expression, SL("right"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 939);
	ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", NULL, 94, &_5, &escapeChar_zv, &bindCounts);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVSV(return_value, &left, " ", &operator, " ", &right);
	RETURN_MM();
}

/**
 * Resolve CASE expressions
 *
 * @param array expression
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionCase)
{
	zend_bool _15;
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *expression_param = NULL, escapeChar_zv, *bindCounts_param = NULL, whenClause, _0, _1, _2, _3, *_4, _14, _5$$3, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4, _11$$5, _12$$5, _13$$5, _16$$6, _17$$7, _18$$7, _19$$7, _20$$7, _21$$7, _22$$8, _23$$8, _24$$8;
	zval expression, bindCounts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&whenClause);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&sql);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(expression, expression_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	zephir_array_fetch_string(&_1, &expression, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 961);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsqlexpression", NULL, 0, &_1, &escapeChar_zv, &bindCounts);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "CASE ", &_0);
	zephir_get_strval(&sql, &_2);
	zephir_array_fetch_string(&_3, &expression, SL("when-clauses"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 963);
	zephir_is_iterable(&_3, 0, "phalcon/Db/Dialect.zep", 974);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
		{
			ZEPHIR_INIT_NVAR(&whenClause);
			ZVAL_COPY(&whenClause, _4);
			zephir_array_fetch_string(&_5$$3, &whenClause, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 964);
			if (ZEPHIR_IS_STRING(&_5$$3, "when")) {
				zephir_array_fetch_string(&_7$$4, &whenClause, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 966);
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "getsqlexpression", NULL, 94, &_7$$4, &escapeChar_zv, &bindCounts);
				zephir_check_call_status();
				zephir_array_fetch_string(&_9$$4, &whenClause, SL("then"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 968);
				ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "getsqlexpression", NULL, 94, &_9$$4, &escapeChar_zv, &bindCounts);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$4);
				ZEPHIR_CONCAT_SVSV(&_10$$4, " WHEN ", &_6$$4, " THEN ", &_8$$4);
				zephir_concat_self(&sql, &_10$$4);
			} else {
				zephir_array_fetch_string(&_12$$5, &whenClause, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 970);
				ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "getsqlexpression", NULL, 94, &_12$$5, &escapeChar_zv, &bindCounts);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZEPHIR_CONCAT_SV(&_13$$5, " ELSE ", &_11$$5);
				zephir_concat_self(&sql, &_13$$5);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		_15 = 1;
		while (1) {
			if (_15) {
				_15 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_14, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&whenClause, &_3, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_16$$6, &whenClause, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 964);
				if (ZEPHIR_IS_STRING(&_16$$6, "when")) {
					zephir_array_fetch_string(&_18$$7, &whenClause, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 966);
					ZEPHIR_CALL_METHOD(&_17$$7, this_ptr, "getsqlexpression", NULL, 94, &_18$$7, &escapeChar_zv, &bindCounts);
					zephir_check_call_status();
					zephir_array_fetch_string(&_20$$7, &whenClause, SL("then"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 968);
					ZEPHIR_CALL_METHOD(&_19$$7, this_ptr, "getsqlexpression", NULL, 94, &_20$$7, &escapeChar_zv, &bindCounts);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_21$$7);
					ZEPHIR_CONCAT_SVSV(&_21$$7, " WHEN ", &_17$$7, " THEN ", &_19$$7);
					zephir_concat_self(&sql, &_21$$7);
				} else {
					zephir_array_fetch_string(&_23$$8, &whenClause, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 970);
					ZEPHIR_CALL_METHOD(&_22$$8, this_ptr, "getsqlexpression", NULL, 94, &_23$$8, &escapeChar_zv, &bindCounts);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_24$$8);
					ZEPHIR_CONCAT_SV(&_24$$8, " ELSE ", &_22$$8);
					zephir_concat_self(&sql, &_24$$8);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&whenClause);
	ZEPHIR_CONCAT_VS(return_value, &sql, " END");
	RETURN_MM();
}

/**
 * Resolve CAST of values
 *
 * @param array expression
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionCastValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *expression_param = NULL, escapeChar_zv, *bindCounts_param = NULL, left, right, _0, _1;
	zval expression, bindCounts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(expression, expression_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	zephir_array_fetch_string(&_0, &expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 991);
	ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", NULL, 0, &_0, &escapeChar_zv, &bindCounts);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, &expression, SL("right"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 997);
	ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", NULL, 94, &_1, &escapeChar_zv, &bindCounts);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "CAST(", &left, " AS ", &right, ")");
	RETURN_MM();
}

/**
 * Resolve CONVERT of values encodings
 *
 * @param array expression
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionConvertValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *expression_param = NULL, escapeChar_zv, *bindCounts_param = NULL, left, right, _0, _1;
	zval expression, bindCounts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(expression, expression_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	zephir_array_fetch_string(&_0, &expression, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 1019);
	ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", NULL, 0, &_0, &escapeChar_zv, &bindCounts);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, &expression, SL("right"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 1025);
	ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", NULL, 94, &_1, &escapeChar_zv, &bindCounts);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "CONVERT(", &left, " USING ", &right, ")");
	RETURN_MM();
}

/**
 * Resolve a FROM clause
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionFrom)
{
	zend_bool _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *expression, expression_sub, escapeChar_zv, table, tables, *_0$$3, _3$$3, _6$$3, _1$$4, _5$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_5$$5);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(expression)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression = ZEND_CALL_ARG(execute_data, 1);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&tables);
		array_init(&tables);
		zephir_is_iterable(expression, 0, "phalcon/Db/Dialect.zep", 1047);
		if (Z_TYPE_P(expression) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(expression), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&table);
				ZVAL_COPY(&table, _0$$3);
				ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getsqltable", &_2, 116, &table, &escapeChar_zv);
				zephir_check_call_status();
				zephir_array_append(&tables, &_1$$4, PH_SEPARATE, "phalcon/Db/Dialect.zep", 1044);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, expression, "rewind", NULL, 0);
			zephir_check_call_status();
			_4$$3 = 1;
			while (1) {
				if (_4$$3) {
					_4$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, expression, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_3$$3, expression, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&table, expression, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_5$$5, this_ptr, "getsqltable", &_2, 116, &table, &escapeChar_zv);
					zephir_check_call_status();
					zephir_array_append(&tables, &_5$$5, PH_SEPARATE, "phalcon/Db/Dialect.zep", 1044);
			}
		}
		ZEPHIR_INIT_NVAR(&table);
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_fast_join_str(&_6$$3, SL(", "), &tables);
		ZEPHIR_CPY_WRT(&tables, &_6$$3);
	} else {
		ZEPHIR_CPY_WRT(&tables, expression);
	}
	ZEPHIR_CONCAT_SV(return_value, "FROM ", &tables);
	RETURN_MM();
}

/**
 * Resolve function calls
 *
 * @param array expression
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionFunctionCall)
{
	zend_bool _1, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *expression_param = NULL, escapeChar_zv, *bindCounts_param = NULL, __$false, name, customFunction, arguments, _0, _4$$4;
	zval expression, bindCounts, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&customFunction);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(expression, expression_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	zephir_memory_observe(&name);
	zephir_array_fetch_string(&name, &expression, SL("name"), PH_NOISY, "phalcon/Db/Dialect.zep", 1068);
	zephir_memory_observe(&customFunction);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("customFunctions"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&customFunction, &_0, &name, 0)) {
		ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(&customFunction, NULL, 0, this_ptr, &expression, &escapeChar_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_memory_observe(&arguments);
	_1 = zephir_array_isset_string_fetch(&arguments, &expression, SL("arguments"), 0);
	if (_1) {
		_1 = Z_TYPE_P(&arguments) == IS_ARRAY;
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 3, 0);
		add_assoc_stringl_ex(&_2$$4, SL("type"), SL("list"));
		zephir_array_update_string(&_2$$4, SL("parentheses"), &__$false, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_2$$4, SL("value"), &arguments, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&arguments, this_ptr, "getsqlexpression", NULL, 0, &_2$$4, &escapeChar_zv, &bindCounts);
		zephir_check_call_status();
		_3$$4 = zephir_array_isset_value_string(&expression, SL("distinct"));
		if (_3$$4) {
			zephir_array_fetch_string(&_4$$4, &expression, SL("distinct"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 1085);
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
 * Resolve a GROUP BY clause
 *
 * @param array|string expression
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionGroupBy)
{
	zend_bool _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindCounts;
	zend_string *escapeChar = NULL;
	zval *expression, expression_sub, escapeChar_zv, *bindCounts_param = NULL, field, fields, *_0$$3, _5$$3, _9$$3, _1$$5, _3$$4, _7$$7, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&bindCounts);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(expression)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
		zephir_is_iterable(expression, 0, "phalcon/Db/Dialect.zep", 1123);
		if (Z_TYPE_P(expression) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(expression), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _0$$3);
				if (UNEXPECTED(Z_TYPE_P(&field) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_1$$5);
					object_init_ex(&_1$$5, phalcon_db_exceptions_invalidgroupbyexpression_ce);
					ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", &_2, 117);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_1$$5, "phalcon/Db/Dialect.zep", 1113);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "getsqlexpression", &_4, 0, &field, &escapeChar_zv, &bindCounts);
				zephir_check_call_status();
				zephir_array_append(&fields, &_3$$4, PH_SEPARATE, "phalcon/Db/Dialect.zep", 1120);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, expression, "rewind", NULL, 0);
			zephir_check_call_status();
			_6$$3 = 1;
			while (1) {
				if (_6$$3) {
					_6$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, expression, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_5$$3, expression, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, expression, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&field) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_7$$7);
						object_init_ex(&_7$$7, phalcon_db_exceptions_invalidgroupbyexpression_ce);
						ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", &_2, 117);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_7$$7, "phalcon/Db/Dialect.zep", 1113);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_8$$6, this_ptr, "getsqlexpression", &_4, 94, &field, &escapeChar_zv, &bindCounts);
					zephir_check_call_status();
					zephir_array_append(&fields, &_8$$6, PH_SEPARATE, "phalcon/Db/Dialect.zep", 1120);
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_fast_join_str(&_9$$3, SL(", "), &fields);
		ZEPHIR_CPY_WRT(&fields, &_9$$3);
	} else {
		ZEPHIR_CPY_WRT(&fields, expression);
	}
	ZEPHIR_CONCAT_SV(return_value, "GROUP BY ", &fields);
	RETURN_MM();
}

/**
 * Resolve a HAVING clause
 *
 * @param array expression
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionHaving)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *expression_param = NULL, escapeChar_zv, *bindCounts_param = NULL, _0;
	zval expression, bindCounts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(expression, expression_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsqlexpression", NULL, 0, &expression, &escapeChar_zv, &bindCounts);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, "HAVING ", &_0);
	RETURN_MM();
}

/**
 * Resolve a JOINs clause
 *
 * @param array|string expression
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionJoins)
{
	zend_bool _14, _1$$3, _9$$3, _6$$6, _15$$11, _22$$11, _19$$14;
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindCounts;
	zend_string *escapeChar = NULL;
	zval *expression, expression_sub, escapeChar_zv, *bindCounts_param = NULL, condition, join, joinCondition, joinTable, joinType, joinConditionsArray, *_0, _13, _10$$3, _12$$3, *_3$$6, _5$$6, _8$$6, _4$$7, _7$$8, _23$$11, _24$$11, *_16$$14, _18$$14, _21$$14, _17$$15, _20$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&joinCondition);
	ZVAL_UNDEF(&joinTable);
	ZVAL_UNDEF(&joinType);
	ZVAL_UNDEF(&joinConditionsArray);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&sql);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(expression)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	ZEPHIR_INIT_VAR(&joinType);
	ZVAL_STRING(&joinType, "");
	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "");
	zephir_is_iterable(expression, 0, "phalcon/Db/Dialect.zep", 1197);
	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(expression), _0)
		{
			ZEPHIR_INIT_NVAR(&join);
			ZVAL_COPY(&join, _0);
			ZEPHIR_OBS_NVAR(&joinConditionsArray);
			_1$$3 = zephir_array_isset_string_fetch(&joinConditionsArray, &join, SL("conditions"), 0);
			if (_1$$3) {
				_1$$3 = !(ZEPHIR_IS_EMPTY(&joinConditionsArray));
			}
			if (_1$$3) {
				if (!(zephir_array_isset_value_long(&joinConditionsArray, 0))) {
					ZEPHIR_CALL_METHOD(&joinCondition, this_ptr, "getsqlexpression", &_2, 0, &joinConditionsArray, &escapeChar_zv, &bindCounts);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&joinCondition);
					array_init(&joinCondition);
					zephir_is_iterable(&joinConditionsArray, 0, "phalcon/Db/Dialect.zep", 1182);
					if (Z_TYPE_P(&joinConditionsArray) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&joinConditionsArray), _3$$6)
						{
							ZEPHIR_INIT_NVAR(&condition);
							ZVAL_COPY(&condition, _3$$6);
							ZEPHIR_CALL_METHOD(&_4$$7, this_ptr, "getsqlexpression", &_2, 94, &condition, &escapeChar_zv, &bindCounts);
							zephir_check_call_status();
							zephir_array_append(&joinCondition, &_4$$7, PH_SEPARATE, "phalcon/Db/Dialect.zep", 1179);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &joinConditionsArray, "rewind", NULL, 0);
						zephir_check_call_status();
						_6$$6 = 1;
						while (1) {
							if (_6$$6) {
								_6$$6 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &joinConditionsArray, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_5$$6, &joinConditionsArray, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_5$$6)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&condition, &joinConditionsArray, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_7$$8, this_ptr, "getsqlexpression", &_2, 94, &condition, &escapeChar_zv, &bindCounts);
								zephir_check_call_status();
								zephir_array_append(&joinCondition, &_7$$8, PH_SEPARATE, "phalcon/Db/Dialect.zep", 1179);
						}
					}
					ZEPHIR_INIT_NVAR(&condition);
					ZEPHIR_INIT_NVAR(&_8$$6);
					zephir_fast_join_str(&_8$$6, SL(" AND "), &joinCondition);
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
				zephir_concat_self_str(&joinType, SL(" "));
			}
			zephir_array_fetch_string(&_10$$3, &join, SL("source"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 1192);
			ZEPHIR_CALL_METHOD(&joinTable, this_ptr, "getsqltable", &_11, 116, &_10$$3, &escapeChar_zv);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_12$$3);
			ZEPHIR_CONCAT_SVSVSV(&_12$$3, " ", &joinType, "JOIN ", &joinTable, " ON ", &joinCondition);
			zephir_concat_self(&sql, &_12$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, expression, "rewind", NULL, 0);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, expression, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_13, expression, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&join, expression, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&joinConditionsArray);
				_15$$11 = zephir_array_isset_string_fetch(&joinConditionsArray, &join, SL("conditions"), 0);
				if (_15$$11) {
					_15$$11 = !(ZEPHIR_IS_EMPTY(&joinConditionsArray));
				}
				if (_15$$11) {
					if (!(zephir_array_isset_value_long(&joinConditionsArray, 0))) {
						ZEPHIR_CALL_METHOD(&joinCondition, this_ptr, "getsqlexpression", &_2, 94, &joinConditionsArray, &escapeChar_zv, &bindCounts);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&joinCondition);
						array_init(&joinCondition);
						zephir_is_iterable(&joinConditionsArray, 0, "phalcon/Db/Dialect.zep", 1182);
						if (Z_TYPE_P(&joinConditionsArray) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&joinConditionsArray), _16$$14)
							{
								ZEPHIR_INIT_NVAR(&condition);
								ZVAL_COPY(&condition, _16$$14);
								ZEPHIR_CALL_METHOD(&_17$$15, this_ptr, "getsqlexpression", &_2, 94, &condition, &escapeChar_zv, &bindCounts);
								zephir_check_call_status();
								zephir_array_append(&joinCondition, &_17$$15, PH_SEPARATE, "phalcon/Db/Dialect.zep", 1179);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &joinConditionsArray, "rewind", NULL, 0);
							zephir_check_call_status();
							_19$$14 = 1;
							while (1) {
								if (_19$$14) {
									_19$$14 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &joinConditionsArray, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_18$$14, &joinConditionsArray, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_18$$14)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&condition, &joinConditionsArray, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&_20$$16, this_ptr, "getsqlexpression", &_2, 94, &condition, &escapeChar_zv, &bindCounts);
									zephir_check_call_status();
									zephir_array_append(&joinCondition, &_20$$16, PH_SEPARATE, "phalcon/Db/Dialect.zep", 1179);
							}
						}
						ZEPHIR_INIT_NVAR(&condition);
						ZEPHIR_INIT_NVAR(&_21$$14);
						zephir_fast_join_str(&_21$$14, SL(" AND "), &joinCondition);
						ZEPHIR_CPY_WRT(&joinCondition, &_21$$14);
					}
				} else {
					ZEPHIR_INIT_NVAR(&joinCondition);
					ZVAL_LONG(&joinCondition, 1);
				}
				ZEPHIR_OBS_NVAR(&joinType);
				_22$$11 = zephir_array_isset_string_fetch(&joinType, &join, SL("type"), 0);
				if (_22$$11) {
					_22$$11 = zephir_is_true(&joinType);
				}
				if (_22$$11) {
					zephir_concat_self_str(&joinType, SL(" "));
				}
				zephir_array_fetch_string(&_23$$11, &join, SL("source"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 1192);
				ZEPHIR_CALL_METHOD(&joinTable, this_ptr, "getsqltable", &_11, 116, &_23$$11, &escapeChar_zv);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_24$$11);
				ZEPHIR_CONCAT_SVSVSV(&_24$$11, " ", &joinType, "JOIN ", &joinTable, " ON ", &joinCondition);
				zephir_concat_self(&sql, &_24$$11);
		}
	}
	ZEPHIR_INIT_NVAR(&join);
	RETURN_CTOR(&sql);
}

/**
 * Resolve a LIMIT clause
 *
 * @param array|string expression
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionLimit)
{
	zend_bool _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindCounts, _4;
	zend_string *escapeChar = NULL;
	zval *expression, expression_sub, escapeChar_zv, *bindCounts_param = NULL, sql, value, limit, offset, _0$$4, _1$$5, _3$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&_4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(expression)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "");
	ZEPHIR_INIT_VAR(&offset);
	ZVAL_NULL(&offset);
	zephir_memory_observe(&value);
	zephir_array_fetch_string(&value, expression, SL("value"), PH_NOISY, "phalcon/Db/Dialect.zep", 1213);
	if (zephir_array_isset_value_string(expression, SL("sql"))) {
		ZEPHIR_OBS_NVAR(&sql);
		zephir_array_fetch_string(&sql, expression, SL("sql"), PH_NOISY, "phalcon/Db/Dialect.zep", 1216);
	}
	if (Z_TYPE_P(&value) == IS_ARRAY) {
		zephir_memory_observe(&_0$$4);
		zephir_array_fetch_string(&_0$$4, &value, SL("number"), PH_NOISY, "phalcon/Db/Dialect.zep", 1220);
		if (Z_TYPE_P(&_0$$4) == IS_ARRAY) {
			zephir_array_fetch_string(&_1$$5, &value, SL("number"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 1222);
			ZEPHIR_CALL_METHOD(&limit, this_ptr, "getsqlexpression", NULL, 0, &_1$$5, &escapeChar_zv, &bindCounts);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(&limit);
			zephir_array_fetch_string(&limit, &value, SL("number"), PH_NOISY, "phalcon/Db/Dialect.zep", 1227);
		}
		ZEPHIR_OBS_NVAR(&offset);
		_2$$4 = zephir_array_isset_string_fetch(&offset, &value, SL("offset"), 0);
		if (_2$$4) {
			_2$$4 = Z_TYPE_P(&offset) == IS_ARRAY;
		}
		if (_2$$4) {
			ZEPHIR_CALL_METHOD(&_3$$7, this_ptr, "getsqlexpression", NULL, 94, &offset, &escapeChar_zv, &bindCounts);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&offset, &_3$$7);
		}
	} else {
		ZEPHIR_CPY_WRT(&limit, &value);
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	zephir_array_fast_append(&_4, &limit);
	zephir_array_fast_append(&_4, &offset);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "limit", NULL, 0, &sql, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolve Lists
 *
 * @param array expression
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionList)
{
	zend_bool _0, _1, _6$$4, _8$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *expression_param = NULL, escapeChar_zv, *bindCounts_param = NULL, item, values, separator, _11, *_2$$4, _5$$4, _9$$4, _10$$4, _3$$5, _7$$6;
	zval expression, bindCounts, items;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_7$$6);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(expression, expression_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	ZEPHIR_INIT_VAR(&items);
	array_init(&items);
	ZEPHIR_INIT_VAR(&separator);
	ZVAL_STRING(&separator, ", ");
	if (zephir_array_isset_value_string(&expression, SL("separator"))) {
		ZEPHIR_OBS_NVAR(&separator);
		zephir_array_fetch_string(&separator, &expression, SL("separator"), PH_NOISY, "phalcon/Db/Dialect.zep", 1266);
	}
	zephir_memory_observe(&values);
	_0 = zephir_array_isset_long_fetch(&values, &expression, 0, 0);
	if (!(_0)) {
		ZEPHIR_OBS_NVAR(&values);
		_0 = zephir_array_isset_string_fetch(&values, &expression, SL("value"), 0);
	}
	_1 = _0;
	if (_1) {
		_1 = Z_TYPE_P(&values) == IS_ARRAY;
	}
	if (_1) {
		zephir_is_iterable(&values, 0, "phalcon/Db/Dialect.zep", 1275);
		if (Z_TYPE_P(&values) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _2$$4)
			{
				ZEPHIR_INIT_NVAR(&item);
				ZVAL_COPY(&item, _2$$4);
				ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "getsqlexpression", &_4, 0, &item, &escapeChar_zv, &bindCounts);
				zephir_check_call_status();
				zephir_array_append(&items, &_3$$5, PH_SEPARATE, "phalcon/Db/Dialect.zep", 1272);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
			zephir_check_call_status();
			_6$$4 = 1;
			while (1) {
				if (_6$$4) {
					_6$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_5$$4, &values, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&item, &values, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_7$$6, this_ptr, "getsqlexpression", &_4, 94, &item, &escapeChar_zv, &bindCounts);
					zephir_check_call_status();
					zephir_array_append(&items, &_7$$6, PH_SEPARATE, "phalcon/Db/Dialect.zep", 1272);
			}
		}
		ZEPHIR_INIT_NVAR(&item);
		_8$$4 = zephir_array_isset_value_string(&expression, SL("parentheses"));
		if (_8$$4) {
			zephir_array_fetch_string(&_9$$4, &expression, SL("parentheses"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 1275);
			_8$$4 = ZEPHIR_IS_FALSE_IDENTICAL(&_9$$4);
		}
		if (_8$$4) {
			zephir_fast_join(return_value, &separator, &items);
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_10$$4);
		zephir_fast_join(&_10$$4, &separator, &items);
		ZEPHIR_CONCAT_SVS(return_value, "(", &_10$$4, ")");
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_11);
	object_init_ex(&_11, phalcon_db_exceptions_invalidlistexpression_ce);
	ZEPHIR_CALL_METHOD(NULL, &_11, "__construct", NULL, 118);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_11, "phalcon/Db/Dialect.zep", 1282);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Resolve object expressions
 *
 * @param array expression
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionObject)
{
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *expression_param = NULL, escapeChar_zv, *bindCounts_param = NULL, domain, objectExpression;
	zval expression, bindCounts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&objectExpression);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(expression, expression_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	ZEPHIR_INIT_VAR(&domain);
	ZVAL_NULL(&domain);
	ZEPHIR_INIT_VAR(&objectExpression);
	zephir_create_array(&objectExpression, 1, 0);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpression", NULL, 0, &objectExpression, &escapeChar_zv, &bindCounts);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolve an ORDER BY clause
 *
 * @param array|string expression
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionOrderBy)
{
	zend_bool _8$$3, _5$$4, _11$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindCounts;
	zend_string *escapeChar = NULL;
	zval *expression, expression_sub, escapeChar_zv, *bindCounts_param = NULL, field, fields, type, fieldSql, *_0$$3, _7$$3, _13$$3, _1$$5, _3$$4, _6$$6, _9$$8, _10$$7, _12$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&fieldSql);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&bindCounts);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(expression)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	ZEPHIR_INIT_VAR(&fieldSql);
	ZVAL_NULL(&fieldSql);
	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
		zephir_is_iterable(expression, 0, "phalcon/Db/Dialect.zep", 1347);
		if (Z_TYPE_P(expression) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(expression), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _0$$3);
				if (UNEXPECTED(Z_TYPE_P(&field) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_1$$5);
					object_init_ex(&_1$$5, phalcon_db_exceptions_invalidorderbyexpression_ce);
					ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", &_2, 119);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_1$$5, "phalcon/Db/Dialect.zep", 1328);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch_long(&_3$$4, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 1332);
				ZEPHIR_CALL_METHOD(&fieldSql, this_ptr, "getsqlexpression", &_4, 0, &_3$$4, &escapeChar_zv, &bindCounts);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&type);
				_5$$4 = zephir_array_isset_long_fetch(&type, &field, 1, 0);
				if (_5$$4) {
					_5$$4 = !ZEPHIR_IS_STRING(&type, "");
				}
				if (_5$$4) {
					ZEPHIR_INIT_NVAR(&_6$$6);
					ZEPHIR_CONCAT_SV(&_6$$6, " ", &type);
					zephir_concat_self(&fieldSql, &_6$$6);
				}
				zephir_array_append(&fields, &fieldSql, PH_SEPARATE, "phalcon/Db/Dialect.zep", 1344);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, expression, "rewind", NULL, 0);
			zephir_check_call_status();
			_8$$3 = 1;
			while (1) {
				if (_8$$3) {
					_8$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, expression, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_7$$3, expression, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, expression, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&field) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_9$$8);
						object_init_ex(&_9$$8, phalcon_db_exceptions_invalidorderbyexpression_ce);
						ZEPHIR_CALL_METHOD(NULL, &_9$$8, "__construct", &_2, 119);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_9$$8, "phalcon/Db/Dialect.zep", 1328);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch_long(&_10$$7, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 1332);
					ZEPHIR_CALL_METHOD(&fieldSql, this_ptr, "getsqlexpression", &_4, 94, &_10$$7, &escapeChar_zv, &bindCounts);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&type);
					_11$$7 = zephir_array_isset_long_fetch(&type, &field, 1, 0);
					if (_11$$7) {
						_11$$7 = !ZEPHIR_IS_STRING(&type, "");
					}
					if (_11$$7) {
						ZEPHIR_INIT_NVAR(&_12$$9);
						ZEPHIR_CONCAT_SV(&_12$$9, " ", &type);
						zephir_concat_self(&fieldSql, &_12$$9);
					}
					zephir_array_append(&fields, &fieldSql, PH_SEPARATE, "phalcon/Db/Dialect.zep", 1344);
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		ZEPHIR_INIT_VAR(&_13$$3);
		zephir_fast_join_str(&_13$$3, SL(", "), &fields);
		ZEPHIR_CPY_WRT(&fields, &_13$$3);
	} else {
		ZEPHIR_CPY_WRT(&fields, expression);
	}
	ZEPHIR_CONCAT_SV(return_value, "ORDER BY ", &fields);
	RETURN_MM();
}

/**
 * Resolve qualified expressions
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionQualified)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *expression_param = NULL, escapeChar_zv, column, domain;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&domain);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(expression, expression_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression_param = ZEND_CALL_ARG(execute_data, 1);
	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	zephir_memory_observe(&column);
	zephir_array_fetch_string(&column, &expression, SL("name"), PH_NOISY, "phalcon/Db/Dialect.zep", 1362);
	zephir_memory_observe(&domain);
	if (!(zephir_array_isset_string_fetch(&domain, &expression, SL("domain"), 0))) {
		ZEPHIR_INIT_NVAR(&domain);
		ZVAL_NULL(&domain);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "preparequalified", NULL, 0, &column, &domain, &escapeChar_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolve Column expressions
 *
 * @param array expression
 * @param string|null escapeChar
 * @param array bindCounts
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionScalar)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *expression_param = NULL, escapeChar_zv, *bindCounts_param = NULL, value, _0$$3, _1$$4;
	zval expression, bindCounts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(expression, expression_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	if (zephir_array_isset_value_string(&expression, SL("column"))) {
		zephir_array_fetch_string(&_0$$3, &expression, SL("column"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 1386);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlcolumn", NULL, 87, &_0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_memory_observe(&value);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&value, &expression, SL("value"), 0)))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_db_exceptions_invalidsqlexpression_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 88);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Db/Dialect.zep", 1390);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&value) == IS_ARRAY) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsqlexpression", NULL, 0, &value, &escapeChar_zv, &bindCounts);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&value);
}

/**
 * Resolve unary operations expressions
 *
 * @param array expression
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionUnaryOperations)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *escapeChar = NULL;
	zval *expression_param = NULL, escapeChar_zv, *bindCounts_param = NULL, left, right, _4, _0$$3, _1$$3, _2$$4, _3$$4;
	zval expression, bindCounts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(expression, expression_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&expression, expression_param);
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	zephir_memory_observe(&left);
	if (zephir_array_isset_string_fetch(&left, &expression, SL("left"), 0)) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getsqlexpression", NULL, 0, &left, &escapeChar_zv, &bindCounts);
		zephir_check_call_status();
		zephir_array_fetch_string(&_1$$3, &expression, SL("op"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 1417);
		ZEPHIR_CONCAT_VSV(return_value, &_0$$3, " ", &_1$$3);
		RETURN_MM();
	}
	zephir_memory_observe(&right);
	if (zephir_array_isset_string_fetch(&right, &expression, SL("right"), 0)) {
		zephir_array_fetch_string(&_2$$4, &expression, SL("op"), PH_NOISY | PH_READONLY, "phalcon/Db/Dialect.zep", 1424);
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "getsqlexpression", NULL, 94, &right, &escapeChar_zv, &bindCounts);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSV(return_value, &_2$$4, " ", &_3$$4);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, phalcon_db_exceptions_invalidunaryexpression_ce);
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 120);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_4, "phalcon/Db/Dialect.zep", 1427);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Resolve a WHERE clause
 *
 * @param array|string expression
 * @param string|null escapeChar
 * @param array bindCounts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindCounts;
	zend_string *escapeChar = NULL;
	zval *expression, expression_sub, escapeChar_zv, *bindCounts_param = NULL, whereSql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&whereSql);
	ZVAL_UNDEF(&bindCounts);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(expression)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(escapeChar)
		ZEPHIR_Z_PARAM_ARRAY(bindCounts, bindCounts_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expression = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		bindCounts_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!bindCounts_param) {
		ZEPHIR_INIT_VAR(&bindCounts);
		array_init(&bindCounts);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindCounts, bindCounts_param);
	}
	if (Z_TYPE_P(expression) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&whereSql, this_ptr, "getsqlexpression", NULL, 0, expression, &escapeChar_zv, &bindCounts);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&whereSql, expression);
	}
	ZEPHIR_CONCAT_SV(return_value, "WHERE ", &whereSql);
	RETURN_MM();
}

/**
 * Prepares column for this RDBMS
 */
PHP_METHOD(Phalcon_Db_Dialect, prepareColumnAlias)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval qualified_zv, alias_zv, escapeChar_zv, _0$$3;
	zend_string *qualified = NULL, *alias = NULL, *escapeChar = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&qualified_zv);
	ZVAL_UNDEF(&alias_zv);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&_0$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(qualified)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(alias)
		Z_PARAM_STR_OR_NULL(escapeChar)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&qualified_zv);
	ZVAL_STR_COPY(&qualified_zv, qualified);
	if (!alias) {
		ZEPHIR_INIT_VAR(&alias_zv);
	} else {
		zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	}
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!ZEPHIR_IS_STRING(&alias_zv, "")) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "escape", NULL, 102, &alias_zv, &escapeChar_zv);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSV(return_value, &qualified_zv, " AS ", &_0$$3);
		RETURN_MM();
	}
	RETURN_MM_STR(zend_string_copy(qualified));
}

/**
 * Prepares table for this RDBMS
 */
PHP_METHOD(Phalcon_Db_Dialect, prepareTable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *schema = NULL, *alias = NULL, *escapeChar = NULL;
	zval *table_param = NULL, schema_zv, alias_zv, escapeChar_zv, _0, _1$$3, _2$$3, _3$$4, _4$$4;
	zval table;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_UNDEF(&alias_zv);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_ZVAL(table_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
		Z_PARAM_STR_OR_NULL(alias)
		Z_PARAM_STR_OR_NULL(escapeChar)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	table_param = ZEND_CALL_ARG(execute_data, 1);
	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
	}
	if (!schema) {
		ZEPHIR_INIT_VAR(&schema_zv);
	} else {
		zephir_memory_observe(&schema_zv);
	ZVAL_STR_COPY(&schema_zv, schema);
	}
	if (!alias) {
		ZEPHIR_INIT_VAR(&alias_zv);
	} else {
		zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	}
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "escape", NULL, 102, &table, &escapeChar_zv);
	zephir_check_call_status();
	zephir_get_strval(&table, &_0);
	if (!ZEPHIR_IS_STRING(&schema_zv, "")) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "escapeschema", NULL, 121, &schema_zv, &escapeChar_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VSV(&_2$$3, &_1$$3, ".", &table);
		zephir_get_strval(&table, &_2$$3);
	}
	if (!ZEPHIR_IS_STRING(&alias_zv, "")) {
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "escape", NULL, 102, &alias_zv, &escapeChar_zv);
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
PHP_METHOD(Phalcon_Db_Dialect, prepareQualified)
{
	zval _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval column_zv, domain_zv, escapeChar_zv;
	zend_string *column = NULL, *domain = NULL, *escapeChar = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_zv);
	ZVAL_UNDEF(&domain_zv);
	ZVAL_UNDEF(&escapeChar_zv);
	ZVAL_UNDEF(&_0$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(column)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(domain)
		Z_PARAM_STR_OR_NULL(escapeChar)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&column_zv);
	ZVAL_STR_COPY(&column_zv, column);
	if (!domain) {
		ZEPHIR_INIT_VAR(&domain_zv);
	} else {
		zephir_memory_observe(&domain_zv);
	ZVAL_STR_COPY(&domain_zv, domain);
	}
	if (!escapeChar) {
		ZEPHIR_INIT_VAR(&escapeChar_zv);
	} else {
		zephir_memory_observe(&escapeChar_zv);
	ZVAL_STR_COPY(&escapeChar_zv, escapeChar);
	}
	if (!ZEPHIR_IS_STRING(&domain_zv, "")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_VSV(&_0$$3, &domain_zv, ".", &column_zv);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", NULL, 102, &_0$$3, &escapeChar_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", NULL, 102, &column_zv, &escapeChar_zv);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Db_Dialect(zend_class_entry *class_type)
{
		zval _3$$4;
	zval _0, _2, _5, _1$$3, _4$$4, _6$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("supportedOperators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("supportedOperators"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("guardedOperators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 9, 0);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "@@");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "@>");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "<@");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "&&");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "||");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "->");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "->>");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "#>");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "#>>");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("guardedOperators"), &_3$$4);
		}
		zephir_read_property_ex(&_5, this_ptr, ZEND_STRL("customFunctions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_5) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_6$$5);
			array_init(&_6$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("customFunctions"), &_6$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

