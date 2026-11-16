
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Query
 * @license https://github.com/atlasphp/Atlas.Query/blob/1.x/LICENSE.md
 */
/**
 * Insert Query
 *
 * @phpstan-import-type datamapper_clauses from DataMapperTypes
 * @phpstan-import-type datamapper_column_values from DataMapperTypes
 * @phpstan-import-type datamapper_write_store from DataMapperTypes
 *
 * @property datamapper_write_store $store
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_Insert)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\DataMapper\\Query, Insert, phalcon, datamapper_query_insert, phalcon_datamapper_query_abstractquery_ce, phalcon_datamapper_query_insert_method_entry, 0);

	return SUCCESS;
}

/**
 * Insert constructor.
 */
PHP_METHOD(Phalcon_DataMapper_Query_Insert, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, *bind, bind_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&bind_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_datamapper_pdo_connection_ce)
		Z_PARAM_OBJECT_OF_CLASS(bind, phalcon_datamapper_query_bind_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &connection, &bind);
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_datamapper_query_insert_ce, getThis(), "__construct", &_zephir_call_cache[0], connection, bind);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "FROM");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	zephir_update_property_array(this_ptr, SL("store"), &_0, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "RETURNING");
	zephir_update_property_array(this_ptr, SL("store"), &_3, &_2);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets a column for the `INSERT` query
 */
PHP_METHOD(Phalcon_DataMapper_Query_Insert, column)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval column_zv, *value = NULL, value_sub, *type_param = NULL, __$null, _1$$3, _2$$3;
	zend_string *column = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("bind", 4, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(column)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(value)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		value = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		type_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&column_zv);
	ZVAL_STR_COPY(&column_zv, column);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}
	if (!type_param) {
		type = -1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, ":", &column_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array_multi(this_ptr, SL("store"), &_0, SL("sz"), 3, SL("COLUMNS"), &column_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(value) != IS_NULL) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 599, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_2$$3, type);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "setValue", &_zephir_call_cache[0], &column_zv, value, &_2$$3);
		zephir_check_call_status();
	}
	RETURN_THIS();
}

/**
 * Mass sets columns and values for the `INSERT`
 *
 * @phpstan-param datamapper_column_values $columns
 */
PHP_METHOD(Phalcon_DataMapper_Query_Insert, columns)
{
	zend_bool _4;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns_param = NULL, column, value, *_0, _3;
	zval columns;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(columns, columns_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &columns_param);
	zephir_get_arrval(&columns, columns_param);
	zephir_is_iterable(&columns, 0, "phalcon/DataMapper/Query/Insert.zep", 74);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columns), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&column);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&column, _2);
			} else {
				ZVAL_LONG(&column, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (Z_TYPE_P(&column) == IS_LONG) {
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "column", &_zephir_call_cache[0], &value);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "column", &_zephir_call_cache[1], &column, &value);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &columns, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &columns, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_3, &columns, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&column, &columns, "key", &_zephir_call_cache[5]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &columns, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				if (Z_TYPE_P(&column) == IS_LONG) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "column", &_zephir_call_cache[7], &value);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "column", &_zephir_call_cache[8], &column, &value);
					zephir_check_call_status();
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&column);
	RETURN_THIS();
}

/**
 * Returns the id of the last inserted record
 */
PHP_METHOD(Phalcon_DataMapper_Query_Insert, getLastInsertId)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("connection", 10, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 600, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "lastInsertId", &_zephir_call_cache[0], &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_DataMapper_Query_Insert, getStatement)
{
	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("store", 5, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "buildFlags", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 601, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_2);
	zephir_array_fetch_string(&_2, &_1, SL("FROM"), PH_NOISY, "phalcon/DataMapper/Query/Insert.zep", 90);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "buildColumns", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_4, this_ptr, "buildReturning", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVVV(return_value, "INSERT", &_0, " INTO ", &_2, &_3, &_4);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Adds table(s) in the query
 */
PHP_METHOD(Phalcon_DataMapper_Query_Insert, into)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval table_zv, _0;
	zend_string *table = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(table)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "FROM");
	zephir_update_property_array(this_ptr, SL("store"), &_0, &table_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Resets the internal store
 */
PHP_METHOD(Phalcon_DataMapper_Query_Insert, reset)
{
	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_datamapper_query_insert_ce, getThis(), "reset", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "FROM");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	zephir_update_property_array(this_ptr, SL("store"), &_0, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "RETURNING");
	zephir_update_property_array(this_ptr, SL("store"), &_3, &_2);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds the `RETURNING` clause
 *
 * @phpstan-param datamapper_clauses $columns
 */
PHP_METHOD(Phalcon_DataMapper_Query_Insert, returning)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *columns_param = NULL, _0, _1, _2, _3;
	zval columns;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("store", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(columns, columns_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &columns_param);
	zephir_get_arrval(&columns, columns_param);
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 601, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_2);
	zephir_array_fetch_string(&_2, &_1, SL("RETURNING"), PH_NOISY, "phalcon/DataMapper/Query/Insert.zep", 123);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_fast_array_merge(&_0, &_2, &columns);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "RETURNING");
	zephir_update_property_array(this_ptr, SL("store"), &_3, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Sets a column = value condition
 *
 * @phpstan-param string|null $value
 */
PHP_METHOD(Phalcon_DataMapper_Query_Insert, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval column_zv, *value = NULL, value_sub, __$null, _0;
	zend_string *column = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("bind", 4, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(column)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		value = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&column_zv);
	ZVAL_STR_COPY(&column_zv, column);
	if (!value) {
		value = &value_sub;
		ZEPHIR_CPY_WRT(value, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}
	if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_STRING(value, "NULL");
	}
	zephir_update_property_array_multi(this_ptr, SL("store"), value, SL("sz"), 3, SL("COLUMNS"), &column_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 599, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "remove", &_zephir_call_cache[0], &column_zv);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Builds the column list
 */
PHP_METHOD(Phalcon_DataMapper_Query_Insert, buildColumns)
{
	zend_bool _10;
	zend_string *_7;
	zend_ulong _6;
	zval columns;
	zval column, _0, _1, *_2, _3, _4, *_5, _9, _12, _13, _14, _15, _16, _17, _18, _19, _8$$3, _11$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&columns);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("store", 5, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 601, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_1);
	zephir_array_fetch_string(&_1, &_0, SL("COLUMNS"), PH_NOISY, "phalcon/DataMapper/Query/Insert.zep", 156);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_1) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, &_1);
		_2 = &_3;
	} else {
		_2 = &_1;
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_is_iterable(_2, 0, "phalcon/DataMapper/Query/Insert.zep", 160);
	if (Z_TYPE_P(_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_2), _6, _7, _5)
		{
			ZEPHIR_INIT_NVAR(&column);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&column, _7);
			} else {
				ZVAL_LONG(&column, _6);
			}
			ZEPHIR_INIT_NVAR(&_4);
			ZVAL_COPY(&_4, _5);
			ZEPHIR_CALL_METHOD_CACHED(&_8$$3, this_ptr, "quoteIdentifier", &_zephir_call_cache[0], &column);
			zephir_check_call_status();
			zephir_array_append(&columns, &_8$$3, PH_SEPARATE, "phalcon/DataMapper/Query/Insert.zep", 157);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _2, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _2, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_9, _2, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&column, _2, "key", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&_4, _2, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_11$$4, this_ptr, "quoteIdentifier", &_zephir_call_cache[6], &column);
				zephir_check_call_status();
				zephir_array_append(&columns, &_11$$4, PH_SEPARATE, "phalcon/DataMapper/Query/Insert.zep", 157);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&_4);
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, ",");
	ZEPHIR_CALL_METHOD_CACHED(&_13, this_ptr, "indent", &_zephir_call_cache[7], &columns, &_14);
	zephir_check_call_status();
	zephir_fast_trim(&_12, &_13, NULL , ZEPHIR_TRIM_LEFT);
	ZEPHIR_INIT_NVAR(&_14);
	zephir_read_property_cached(&_16, this_ptr, _zephir_prop_0, 601, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_17);
	zephir_array_fetch_string(&_17, &_16, SL("COLUMNS"), PH_NOISY, "phalcon/DataMapper/Query/Insert.zep", 163);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_18, "array_values", NULL, 18, &_17);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_19);
	ZVAL_STRING(&_19, ",");
	ZEPHIR_CALL_METHOD_CACHED(&_15, this_ptr, "indent", &_zephir_call_cache[8], &_18, &_19);
	zephir_check_call_status();
	zephir_fast_trim(&_14, &_15, NULL , ZEPHIR_TRIM_LEFT);
	ZEPHIR_CONCAT_SVSVS(return_value, " (", &_12, ") VALUES (", &_14, ")");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

