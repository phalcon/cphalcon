
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/main.h"
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
 * Class Select
 *
 * @property string $asAlias
 * @property bool   $forUpdate
 *
 * @method int    fetchAffected()
 * @method array  fetchAll()
 * @method array  fetchAssoc()
 * @method array  fetchColumn(int $column = 0)
 * @method array  fetchGroup(int $flags = PDO::FETCH_ASSOC)
 * @method object fetchObject(string $class = 'stdClass', array $arguments = [])
 * @method array  fetchObjects(string $class = 'stdClass', array $arguments = [])
 * @method array  fetchOne()
 * @method array  fetchPairs()
 * @method mixed  fetchValue()
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_Select)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\DataMapper\\Query, Select, phalcon, datamapper_query_select, phalcon_datamapper_query_abstractconditions_ce, phalcon_datamapper_query_select_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_datamapper_query_select_ce, SL("asAlias"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_datamapper_query_select_ce, SL("forUpdate"), 0, ZEND_ACC_PROTECTED);
	zephir_declare_class_constant_string(phalcon_datamapper_query_select_ce, SL("JOIN_INNER"), "INNER");

	zephir_declare_class_constant_string(phalcon_datamapper_query_select_ce, SL("JOIN_LEFT"), "LEFT");

	zephir_declare_class_constant_string(phalcon_datamapper_query_select_ce, SL("JOIN_NATURAL"), "NATURAL");

	zephir_declare_class_constant_string(phalcon_datamapper_query_select_ce, SL("JOIN_RIGHT"), "RIGHT");

	return SUCCESS;
}

/**
 * Proxied methods to the connection
 *
 * @param string $method
 * @param array  $params
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, __call)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, proxied, _0$$3, _3$$3;
	zval *method_param = NULL, *params_param = NULL, __$true, _5, _1$$3, _2$$3, _4$$3;
	zval method, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_6);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&proxied);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		Z_PARAM_ARRAY(params)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &params_param);
	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&params, params_param);


	ZEPHIR_INIT_VAR(&proxied);
	zephir_create_array(&proxied, 10, 0);
	zephir_array_update_string(&proxied, SL("fetchAffected"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&proxied, SL("fetchAll"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&proxied, SL("fetchAssoc"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&proxied, SL("fetchCol"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&proxied, SL("fetchGroup"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&proxied, SL("fetchObject"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&proxied, SL("fetchObjects"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&proxied, SL("fetchOne"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&proxied, SL("fetchPairs"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&proxied, SL("fetchValue"), &__$true, PH_COPY | PH_SEPARATE);
	if (EXPECTED(zephir_array_isset(&proxied, &method))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 2, 0);
		ZEPHIR_OBS_VAR(&_1$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC);
		zephir_array_fast_append(&_0$$3, &_1$$3);
		zephir_array_fast_append(&_0$$3, &method);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 2, 0);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "getstatement", NULL, 0);
		zephir_check_call_status();
		zephir_array_fast_append(&_3$$3, &_4$$3);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "getbindvalues", NULL, 0);
		zephir_check_call_status();
		zephir_array_fast_append(&_3$$3, &_4$$3);
		zephir_fast_array_merge(&_2$$3, &_3$$3, &params);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0$$3, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_5);
	object_init_ex(&_5, spl_ce_BadMethodCallException);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVS(&_6, "Unknown method: [", &method, "]");
	ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 100, &_6);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_5, "phalcon/DataMapper/Query/Select.zep", 97);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Sets a `AND` for a `HAVING` condition
 *
 * @param string     $condition
 * @param mixed|null $value
 * @param int        $type
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, andHaving)
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
		Z_PARAM_ZVAL_OR_NULL(value)
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "having", NULL, 0, &condition, value, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * The `AS` statement for the query - useful in sub-queries
 *
 * @param string $asAlias
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, asAlias)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *asAlias_param = NULL;
	zval asAlias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asAlias);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(asAlias)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &asAlias_param);
	zephir_get_strval(&asAlias, asAlias_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("asAlias"), &asAlias);
	RETURN_THIS();
}

/**
 * Concatenates to the most recent `HAVING` clause
 *
 * @param string     $condition
 * @param mixed|null $value
 * @param int        $type
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, appendHaving)
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
		Z_PARAM_ZVAL_OR_NULL(value)
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
	ZVAL_STRING(&_0, "HAVING");
	ZVAL_LONG(&_1, type);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendcondition", NULL, 0, &_0, &condition, value, &_1);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Concatenates to the most recent `JOIN` clause
 *
 * @param string     $condition
 * @param mixed|null $value
 * @param int        $type
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, appendJoin)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *condition_param = NULL, *value = NULL, value_sub, *type_param = NULL, __$null, end, key, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _0$$3, _1$$3, _2$$3;
	zval condition;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(condition)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(value)
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


	if (!(ZEPHIR_IS_EMPTY(value))) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("bind"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_2$$3, type);
		ZEPHIR_CALL_METHOD(&_1$$3, &_0$$3, "bindinline", NULL, 0, value, &_2$$3);
		zephir_check_call_status();
		zephir_concat_self(&condition, &_1$$3);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_4, &_3, SL("FROM"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Select.zep", 172);
	ZEPHIR_CALL_FUNCTION(&end, "array_key_last", NULL, 48, &_4);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_6, &_5, SL("FROM"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Select.zep", 173);
	zephir_array_fetch(&_7, &_6, &end, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Select.zep", 173);
	ZEPHIR_CALL_FUNCTION(&key, "array_key_last", NULL, 48, &_7);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_9, &_8, SL("FROM"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Select.zep", 175);
	zephir_array_fetch(&_10, &_9, &end, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Select.zep", 175);
	zephir_array_fetch(&_11, &_10, &key, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Select.zep", 175);
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_VV(&_12, &_11, &condition);
	zephir_update_property_array_multi(this_ptr, SL("store"), &_12, SL("szz"), 4, SL("FROM"), &end, &key);
	RETURN_THIS();
}

/**
 * The columns to select from. If a key is set in an array element, the
 * key will be used as the alias
 *
 * @param string ...$column
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, columns)
{
	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_2, &_1, SL("COLUMNS"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Select.zep", 191);
	ZEPHIR_INIT_VAR(&_3);
	zephir_get_args(&_3);
	zephir_fast_array_merge(&_0, &_2, &_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "COLUMNS");
	zephir_update_property_array(this_ptr, SL("store"), &_4, &_0);
	RETURN_THIS();
}

/**
 * @param bool $enable
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, distinct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *enable_param = NULL, _0, _1;
	zend_bool enable;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(enable)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &enable_param);
	if (!enable_param) {
		enable = 1;
	} else {
		enable = zephir_get_boolval(enable_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DISTINCT");
	if (enable) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setflag", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds table(s) in the query
 *
 * @param string $table
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, from)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL;
	zval table;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(table)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &table_param);
	zephir_get_strval(&table, table_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	zephir_array_fast_append(&_0, &table);
	zephir_update_property_array_multi(this_ptr, SL("store"), &_0, SL("sa"), 3, SL("FROM"));
	RETURN_THIS();
}

/**
 * Enable the `FOR UPDATE` for the query
 *
 * @param bool $enable
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, forUpdate)
{
	zval *enable_param = NULL, __$true, __$false;
	zend_bool enable;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(enable)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(0, 1, &enable_param);
	if (!enable_param) {
		enable = 1;
	} else {
		enable = zephir_get_boolval(enable_param);
	}


	if (enable) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("forUpdate"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("forUpdate"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Returns the compiled SQL statement
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, getStatement)
{
	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_2, &_1, SL("UNION"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Select.zep", 245);
	zephir_fast_join_str(&_0, SL(""), &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcurrentstatement", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &_3);
	RETURN_MM();
}

/**
 * Sets the `GROUP BY`
 *
 * @param array|string $groupBy
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, groupBy)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *groupBy, groupBy_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&groupBy_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(groupBy)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &groupBy);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GROUP");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processvalue", NULL, 0, &_0, groupBy);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Whether the query has columns or not
 *
 * @return bool
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, hasColumns)
{
	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("COLUMNS"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Select.zep", 269);
	RETURN_BOOL(zephir_fast_count_int(&_1) > 0);
}

/**
 * Sets a `HAVING` condition
 *
 * @param string     $condition
 * @param mixed|null $value
 * @param int        $type
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, having)
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
		Z_PARAM_ZVAL_OR_NULL(value)
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
	ZVAL_STRING(&_0, "HAVING");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "AND ");
	ZVAL_LONG(&_2, type);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addcondition", NULL, 0, &_0, &_1, &condition, value, &_2);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sets a 'JOIN' condition
 *
 * @param string     $join
 * @param string     $table
 * @param string     $condition
 * @param mixed|null $value
 * @param int        $type
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, join)
{
	zend_bool _5, _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *join_param = NULL, *table_param = NULL, *condition_param = NULL, *value = NULL, value_sub, *type_param = NULL, __$null, key, _0, _1, _2, _3, _4, _6, _7, _8, _9, _11, _12, _13, _14, _19, _20, _16$$5, _17$$5, _18$$5;
	zval join, table, condition, _21, _15$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_STR(join)
		Z_PARAM_STR(table)
		Z_PARAM_STR(condition)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(value)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &join_param, &table_param, &condition_param, &value, &type_param);
	zephir_get_strval(&join, join_param);
	zephir_get_strval(&table, table_param);
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
	zephir_fast_trim(&_0, &join, NULL , ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_NVAR(&join);
	zephir_fast_strtoupper(&join, &_0);
	ZVAL_LONG(&_1, -4);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &join, -4 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_2, "JOIN")) {
		zephir_concat_self_str(&join, " JOIN", sizeof(" JOIN") - 1);
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_trim(&_3, &condition, NULL , ZEPHIR_TRIM_LEFT);
	zephir_get_strval(&condition, &_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "");
	_5 = !ZEPHIR_IS_IDENTICAL(&_4, &condition);
	if (_5) {
		ZEPHIR_INIT_VAR(&_6);
		ZVAL_LONG(&_7, 0);
		ZVAL_LONG(&_8, 3);
		ZEPHIR_INIT_VAR(&_9);
		zephir_substr(&_9, &condition, 0 , 3 , 0);
		zephir_fast_strtoupper(&_6, &_9);
		_5 = !ZEPHIR_IS_STRING_IDENTICAL(&_6, "ON ");
	}
	_10 = _5;
	if (_10) {
		ZEPHIR_INIT_VAR(&_11);
		ZVAL_LONG(&_12, 0);
		ZVAL_LONG(&_13, 6);
		ZEPHIR_INIT_VAR(&_14);
		zephir_substr(&_14, &condition, 0 , 6 , 0);
		zephir_fast_strtoupper(&_11, &_14);
		_10 = !ZEPHIR_IS_STRING_IDENTICAL(&_11, "USING ");
	}
	if (_10) {
		ZEPHIR_INIT_VAR(&_15$$4);
		ZEPHIR_CONCAT_SV(&_15$$4, "ON ", &condition);
		ZEPHIR_CPY_WRT(&condition, &_15$$4);
	}
	if (!(ZEPHIR_IS_EMPTY(value))) {
		zephir_read_property(&_16$$5, this_ptr, ZEND_STRL("bind"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_18$$5, type);
		ZEPHIR_CALL_METHOD(&_17$$5, &_16$$5, "bindinline", NULL, 0, value, &_18$$5);
		zephir_check_call_status();
		zephir_concat_self(&condition, &_17$$5);
	}
	zephir_read_property(&_19, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_20, &_19, SL("FROM"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Select.zep", 330);
	ZEPHIR_CALL_FUNCTION(&key, "array_key_last", NULL, 48, &_20);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_21);
	ZEPHIR_CONCAT_VSVSV(&_21, &join, " ", &table, " ", &condition);
	zephir_update_property_array_multi(this_ptr, SL("store"), &_21, SL("sza"), 4, SL("FROM"), &key);
	RETURN_THIS();
}

/**
 * Sets a `OR` for a `HAVING` condition
 *
 * @param string     $condition
 * @param mixed|null $value
 * @param int        $type
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, orHaving)
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
		Z_PARAM_ZVAL_OR_NULL(value)
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
	ZVAL_STRING(&_0, "HAVING");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "OR ");
	ZVAL_LONG(&_2, type);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addcondition", NULL, 0, &_0, &_1, &condition, value, &_2);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Resets the internal collections
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, reset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phalcon_datamapper_query_select_ce, getThis(), "reset", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "");
	zephir_update_property_zval(this_ptr, ZEND_STRL("asAlias"), &_1);
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("forUpdate"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("forUpdate"), &__$false);
	}
	RETURN_THIS();
}

/**
 * Start a sub-select
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, subSelect)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_datamapper_query_select_ce);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("bind"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 224, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Start a `UNION`
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, union)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, " UNION ");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcurrentstatement", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_array_multi(this_ptr, SL("store"), &_0, SL("sa"), 3, SL("UNION"));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "reset", NULL, 0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Start a `UNION ALL`
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, unionAll)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, " UNION ALL ");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcurrentstatement", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_array_multi(this_ptr, SL("store"), &_0, SL("sa"), 3, SL("UNION"));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "reset", NULL, 0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Statement builder
 *
 * @param string $suffix
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, getCurrentStatement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *suffix_param = NULL, statement, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13$$4, _14$$4;
	zval suffix, forUpdate;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&suffix);
	ZVAL_UNDEF(&forUpdate);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(suffix)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &suffix_param);
	if (!suffix_param) {
		ZEPHIR_INIT_VAR(&suffix);
		ZVAL_STRING(&suffix, "");
	} else {
		zephir_get_strval(&suffix, suffix_param);
	}


	ZEPHIR_INIT_VAR(&forUpdate);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("forUpdate"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_NVAR(&forUpdate);
		ZVAL_STRING(&forUpdate, " FOR UPDATE");
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildflags", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "buildlimitearly", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "buildcolumns", NULL, 225);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "buildfrom", NULL, 226);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "WHERE");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "buildcondition", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "GROUP");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "buildby", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "HAVING");
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "buildcondition", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "ORDER");
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "buildby", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "buildlimit", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&statement);
	ZEPHIR_CONCAT_SVVVVVVVVVV(&statement, "SELECT", &_1, &_2, &_3, &_4, &_5, &_7, &_8, &_9, &_10, &forUpdate);
	zephir_read_property(&_11, this_ptr, ZEND_STRL("asAlias"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "");
	if (UNEXPECTED(!ZEPHIR_IS_IDENTICAL(&_12, &_11))) {
		zephir_read_property(&_13$$4, this_ptr, ZEND_STRL("asAlias"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_14$$4);
		ZEPHIR_CONCAT_SVSV(&_14$$4, "(", &statement, ") AS ", &_13$$4);
		ZEPHIR_CPY_WRT(&statement, &_14$$4);
	}
	ZEPHIR_CONCAT_VV(return_value, &statement, &suffix);
	RETURN_MM();
}

/**
 * Builds the columns list
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, buildColumns)
{
	zval columns, _0, _3, _1$$3, _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hascolumns", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&columns);
		zephir_create_array(&columns, 1, 0);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "*");
		zephir_array_fast_append(&columns, &_1$$3);
	} else {
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&columns);
		zephir_array_fetch_string(&columns, &_2$$4, SL("COLUMNS"), PH_NOISY, "phalcon/DataMapper/Query/Select.zep", 456);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, ",");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "indent", NULL, 0, &columns, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds the from list
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_Select, buildFrom)
{
	zval from;
	zval table, _0, _1, _2, _3, *_4, _5, _14, _15, _6$$4, _8$$4, _10$$4, _11$$5, _12$$5, _13$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&from);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&from);
	array_init(&from);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("FROM"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Select.zep", 472);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		RETURN_MM_STRING("");
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_3, &_2, SL("FROM"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Select.zep", 476);
	zephir_is_iterable(&_3, 0, "phalcon/DataMapper/Query/Select.zep", 480);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
		{
			ZEPHIR_INIT_NVAR(&table);
			ZVAL_COPY(&table, _4);
			ZEPHIR_MAKE_REF(&table);
			ZEPHIR_CALL_FUNCTION(&_6$$4, "array_shift", &_7, 22, &table);
			ZEPHIR_UNREF(&table);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "indent", &_9, 0, &table);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZEPHIR_CONCAT_VV(&_10$$4, &_6$$4, &_8$$4);
			zephir_array_append(&from, &_10$$4, PH_SEPARATE, "phalcon/DataMapper/Query/Select.zep", 477);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&table, &_3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_MAKE_REF(&table);
				ZEPHIR_CALL_FUNCTION(&_11$$5, "array_shift", &_7, 22, &table);
				ZEPHIR_UNREF(&table);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "indent", &_9, 0, &table);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZEPHIR_CONCAT_VV(&_13$$5, &_11$$5, &_12$$5);
				zephir_array_append(&from, &_13$$5, PH_SEPARATE, "phalcon/DataMapper/Query/Select.zep", 477);
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&table);
	ZEPHIR_INIT_VAR(&_15);
	ZVAL_STRING(&_15, ",");
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "indent", &_9, 0, &from, &_15);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, " FROM", &_14);
	RETURN_MM();
}

