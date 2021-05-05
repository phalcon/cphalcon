
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Query
 * @license https://github.com/atlasphp/Atlas.Qyert/blob/1.x/LICENSE.md
 */
/**
 * Class AbstractConditions
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_AbstractConditions)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\DataMapper\\Query, AbstractConditions, phalcon, datamapper_query_abstractconditions, phalcon_datamapper_query_abstractquery_ce, phalcon_datamapper_query_abstractconditions_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;
}

/**
 * Sets the `LIMIT` clause
 *
 * @param int $limit
 *
 * @return AbstractConditions
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, limit)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *limit_param = NULL, _0, _1;
	zend_long limit;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(limit)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &limit_param);
	limit = zephir_get_intval(limit_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "LIMIT");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, limit);
	zephir_update_property_array(this_ptr, SL("store"), &_0, &_1);
	RETURN_THIS();
}

/**
 * Sets the `OFFSET` clause
 *
 * @param int $offset
 *
 * @return AbstractConditions
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, offset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *offset_param = NULL, _0, _1;
	zend_long offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(offset)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);
	offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "OFFSET");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, offset);
	zephir_update_property_array(this_ptr, SL("store"), &_0, &_1);
	RETURN_THIS();
}

/**
 * Sets a `AND` for a `WHERE` condition
 *
 * @param string     $condition
 * @param mixed|null $value
 * @param int        $type
 *
 * @return AbstractConditions
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, andWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *condition_param = NULL, *value = NULL, value_sub, *type_param = NULL, __$null, _0;
	zval condition;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(condition)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(value)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &condition_param, &value, &type_param);
	zephir_get_strval(&condition, condition_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}
	if (!type_param) {
		type = -1;
	} else {
		type = zephir_get_intval(type_param);
	}


	ZVAL_LONG(&_0, type);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", NULL, 0, &condition, value, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Concatenates to the most recent `WHERE` clause
 *
 * @param string     $condition
 * @param mixed|null $value
 * @param int        $type
 *
 * @return AbstractConditions
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, appendWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *condition_param = NULL, *value = NULL, value_sub, *type_param = NULL, __$null, _0, _1;
	zval condition;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(condition)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(value)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &condition_param, &value, &type_param);
	zephir_get_strval(&condition, condition_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}
	if (!type_param) {
		type = -1;
	} else {
		type = zephir_get_intval(type_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "WHERE");
	ZVAL_LONG(&_1, type);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendcondition", NULL, 0, &_0, &condition, value, &_1);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sets the `ORDER BY`
 *
 * @param array|string $orderBy
 *
 * @return AbstractConditions
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, orderBy)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *orderBy, orderBy_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&orderBy_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(orderBy)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &orderBy);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "ORDER");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processvalue", NULL, 0, &_0, orderBy);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sets a `OR` for a `WHERE` condition
 *
 * @param string     $condition
 * @param mixed|null $value
 * @param int        $type
 *
 * @return AbstractConditions
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, orWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *condition_param = NULL, *value = NULL, value_sub, *type_param = NULL, __$null, _0, _1, _2;
	zval condition;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(condition)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(value)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &condition_param, &value, &type_param);
	zephir_get_strval(&condition, condition_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}
	if (!type_param) {
		type = -1;
	} else {
		type = zephir_get_intval(type_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "WHERE");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "OR ");
	ZVAL_LONG(&_2, type);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addcondition", NULL, 0, &_0, &_1, &condition, value, &_2);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sets a `WHERE` condition
 *
 * @param string     $condition
 * @param mixed|null $value
 * @param int        $type
 *
 * @return AbstractConditions
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, where)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *condition_param = NULL, *value = NULL, value_sub, *type_param = NULL, __$null, _0, _1, _2;
	zval condition;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(condition)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(value)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &condition_param, &value, &type_param);
	zephir_get_strval(&condition, condition_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}
	if (!type_param) {
		type = -1;
	} else {
		type = zephir_get_intval(type_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "WHERE");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "AND ");
	ZVAL_LONG(&_2, type);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addcondition", NULL, 0, &_0, &_1, &condition, value, &_2);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * @param array $columnsValues
 *
 * @return AbstractConditions
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, whereEquals)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columnsValues_param = NULL, key, value, *_0, _1, _5$$5, _6$$6, _7$$7, _8$$10, _9$$11, _10$$12;
	zval columnsValues;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnsValues);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$12);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(columnsValues)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &columnsValues_param);
	zephir_get_arrval(&columnsValues, columnsValues_param);


	zephir_is_iterable(&columnsValues, 0, "phalcon/DataMapper/Query/AbstractConditions.zep", 164);
	if (Z_TYPE_P(&columnsValues) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columnsValues), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (zephir_is_numeric(&key)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", &_4, 0, &value);
				zephir_check_call_status();
			} else if (Z_TYPE_P(&value) == IS_NULL) {
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZEPHIR_CONCAT_VS(&_5$$5, &key, " IS NULL");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", &_4, 0, &_5$$5);
				zephir_check_call_status();
			} else if (Z_TYPE_P(&value) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_6$$6);
				ZEPHIR_CONCAT_VS(&_6$$6, &key, " IN ");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", &_4, 0, &_6$$6, &value);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&_7$$7);
				ZEPHIR_CONCAT_VS(&_7$$7, &key, " = ");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", &_4, 0, &_7$$7, &value);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columnsValues, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &columnsValues, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &columnsValues, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &columnsValues, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_is_numeric(&key)) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", &_4, 0, &value);
					zephir_check_call_status();
				} else if (Z_TYPE_P(&value) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&_8$$10);
					ZEPHIR_CONCAT_VS(&_8$$10, &key, " IS NULL");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", &_4, 0, &_8$$10);
					zephir_check_call_status();
				} else if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_9$$11);
					ZEPHIR_CONCAT_VS(&_9$$11, &key, " IN ");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", &_4, 0, &_9$$11, &value);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_10$$12);
					ZEPHIR_CONCAT_VS(&_10$$12, &key, " = ");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", &_4, 0, &_10$$12, &value);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &columnsValues, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();
}

/**
 * Appends a conditional
 *
 * @param string     $store
 * @param string     $andor
 * @param string     $condition
 * @param mixed|null $value
 * @param int        $type
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, addCondition)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *store_param = NULL, *andor_param = NULL, *condition_param = NULL, *value = NULL, value_sub, *type_param = NULL, __$null, _0$$3, _1$$3, _2, _3;
	zval store, andor, condition, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&store);
	ZVAL_UNDEF(&andor);
	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_STR(store)
		Z_PARAM_STR(andor)
		Z_PARAM_STR(condition)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(value)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &store_param, &andor_param, &condition_param, &value, &type_param);
	zephir_get_strval(&store, store_param);
	zephir_get_strval(&andor, andor_param);
	zephir_get_strval(&condition, condition_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}
	if (!type_param) {
		type = -1;
	} else {
		type = zephir_get_intval(type_param);
	}


	if (!(ZEPHIR_IS_EMPTY(value))) {
		ZVAL_LONG(&_1$$3, type);
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "bindinline", NULL, 0, value, &_1$$3);
		zephir_check_call_status();
		zephir_concat_self(&condition, &_0$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &store, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 187);
	if (ZEPHIR_IS_EMPTY(&_3)) {
		ZEPHIR_INIT_NVAR(&andor);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &andor, &condition);
	zephir_update_property_array_multi(this_ptr, SL("store"), &_4, SL("za"), 2, &store);
	ZEPHIR_MM_RESTORE();
}

/**
 * Builds a `BY` list
 *
 * @param string $type
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, buildBy)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, _0, _1, _2, _3, _4, _5;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);
	zephir_get_strval(&type, type_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, &type, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 203);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		RETURN_MM_STRING("");
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &type, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 208);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, ",");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "indent", NULL, 0, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSV(return_value, " ", &type, " BY", &_2);
	RETURN_MM();
}

/**
 * Builds the conditional string
 *
 * @param string $type
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, buildCondition)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, _0, _1, _2, _3, _4;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);
	zephir_get_strval(&type, type_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, &type, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 220);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		RETURN_MM_STRING("");
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &type, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 225);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "indent", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVV(return_value, " ", &type, &_2);
	RETURN_MM();
}

/**
 * Builds the early `LIMIT` clause - MS SQLServer
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, buildLimitEarly)
{
	zend_bool _3, _6;
	zval _0, _1, _2, _4, _5, _7, _8, _9$$3, _10$$3, _11$$3;
	zval limit;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&limit);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getdrivername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "sqlsrv");
	_3 = ZEPHIR_IS_IDENTICAL(&_2, &_1);
	if (_3) {
		zephir_read_property(&_4, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_5, &_4, SL("LIMIT"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 239);
		_3 = ZEPHIR_GT_LONG(&_5, 0);
	}
	_6 = _3;
	if (_6) {
		zephir_read_property(&_7, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_8, &_7, SL("OFFSET"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 241);
		_6 = ZEPHIR_IS_LONG_IDENTICAL(&_8, 0);
	}
	if (_6) {
		zephir_read_property(&_9$$3, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_10$$3, &_9$$3, SL("LIMIT"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 242);
		ZEPHIR_INIT_VAR(&_11$$3);
		ZEPHIR_CONCAT_SV(&_11$$3, " TOP ", &_10$$3);
		zephir_get_strval(&limit, &_11$$3);
	}
	RETURN_CTOR(&limit);
}

/**
 * Builds the `LIMIT` clause
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, buildLimit)
{
	zval method, suffix, _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&suffix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&suffix, &_0, "getdrivername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "sqlsrv");
	if (!ZEPHIR_IS_IDENTICAL(&_1, &suffix)) {
		ZEPHIR_INIT_NVAR(&suffix);
		ZVAL_STRING(&suffix, "common");
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_ucfirst(&_2, &suffix);
	ZEPHIR_INIT_VAR(&method);
	ZEPHIR_CONCAT_SV(&method, "buildLimit", &_2);
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds the `LIMIT` clause for all drivers
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, buildLimitCommon)
{
	zval _0, _1, _5, _6, _10, _2$$3, _3$$3, _4$$3, _7$$4, _8$$4, _9$$4, _11$$5, _12$$5;
	zval limit;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&limit);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("LIMIT"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 278);
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_1, 0)) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3$$3, &_2$$3, SL("LIMIT"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 279);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SV(&_4$$3, "LIMIT ", &_3$$3);
		zephir_concat_self(&limit, &_4$$3);
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_6, &_5, SL("OFFSET"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 282);
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_6, 0)) {
		zephir_read_property(&_7$$4, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_8$$4, &_7$$4, SL("OFFSET"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 283);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZEPHIR_CONCAT_SV(&_9$$4, " OFFSET ", &_8$$4);
		zephir_concat_self(&limit, &_9$$4);
	}
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "");
	if (!ZEPHIR_IS_IDENTICAL(&_10, &limit)) {
		ZEPHIR_INIT_VAR(&_11$$5);
		zephir_fast_trim(&_11$$5, &limit, NULL , ZEPHIR_TRIM_LEFT);
		ZEPHIR_INIT_VAR(&_12$$5);
		ZEPHIR_CONCAT_SV(&_12$$5, " ", &_11$$5);
		zephir_get_strval(&limit, &_12$$5);
	}
	RETURN_CTOR(&limit);
}

/**
 * Builds the `LIMIT` clause for MSSQLServer
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, buildLimitSqlsrv)
{
	zend_bool _2;
	zval _0, _1, _3, _4, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3;
	zval limit;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&limit);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("LIMIT"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 302);
	_2 = ZEPHIR_GT_LONG(&_1, 0);
	if (_2) {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_4, &_3, SL("OFFSET"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 302);
		_2 = ZEPHIR_GT_LONG(&_4, 0);
	}
	if (_2) {
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_6$$3, &_5$$3, SL("OFFSET"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 303);
		zephir_read_property(&_7$$3, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_8$$3, &_7$$3, SL("LIMIT"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 304);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZEPHIR_CONCAT_SVSSVS(&_9$$3, " OFFSET ", &_6$$3, " ROWS", " FETCH NEXT ", &_8$$3, " ROWS ONLY");
		zephir_get_strval(&limit, &_9$$3);
	}
	RETURN_CTOR(&limit);
}

/**
 * Concatenates a conditional
 *
 * @param string $store
 * @param string $condition
 * @param mixed  $value
 * @param int    $type
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, appendCondition)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *store_param = NULL, *condition_param = NULL, *value = NULL, value_sub, *type_param = NULL, __$null, key, _2, _3, _6, _7, _8, _9, _10, _11, _0$$3, _1$$3, _4$$4;
	zval store, condition;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&store);
	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(store)
		Z_PARAM_STR(condition)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(value)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &store_param, &condition_param, &value, &type_param);
	zephir_get_strval(&store, store_param);
	zephir_get_strval(&condition, condition_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}
	if (!type_param) {
		type = -1;
	} else {
		type = zephir_get_intval(type_param);
	}


	if (!(ZEPHIR_IS_EMPTY(value))) {
		ZVAL_LONG(&_1$$3, type);
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "bindinline", NULL, 0, value, &_1$$3);
		zephir_check_call_status();
		zephir_concat_self(&condition, &_0$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &store, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 330);
	if (ZEPHIR_IS_EMPTY(&_3)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "");
		zephir_update_property_array_multi(this_ptr, SL("store"), &_4$$4, SL("za"), 2, &store);
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_7, &_6, &store, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 334);
	ZEPHIR_CALL_CE_STATIC(&key, phalcon_helper_arr_ce, "lastkey", &_5, 49, &_7);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_9, &_8, &store, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 336);
	zephir_array_fetch(&_10, &_9, &key, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 336);
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_CONCAT_VV(&_11, &_10, &condition);
	zephir_update_property_array_multi(this_ptr, SL("store"), &_11, SL("zz"), 2, &store, &key);
	ZEPHIR_MM_RESTORE();
}

/**
 * Processes a value (array or string) and merges it with the store
 *
 * @param string       $store
 * @param array|string $data
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, processValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *store_param = NULL, *data = NULL, data_sub, _0$$3, _1$$4, _2$$4, _3$$4;
	zval store;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&store);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(store)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &store_param, &data);
	zephir_get_strval(&store, store_param);
	ZEPHIR_SEPARATE_PARAM(data);


	if (Z_TYPE_P(data) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		zephir_array_fast_append(&_0$$3, data);
		ZEPHIR_CPY_WRT(data, &_0$$3);
	}
	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$4, &_2$$4, &store, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractConditions.zep", 353);
		zephir_fast_array_merge(&_1$$4, &_3$$4, data);
		zephir_update_property_array(this_ptr, SL("store"), &store, &_1$$4);
	}
	ZEPHIR_MM_RESTORE();
}

