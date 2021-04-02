
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
 * Class Update
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_Update) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\DataMapper\\Query, Update, phalcon, datamapper_query_update, phalcon_datamapper_query_abstractconditions_ce, phalcon_datamapper_query_update_method_entry, 0);

	return SUCCESS;

}

/**
 * Update constructor.
 *
 * @param Connection $connection
 * @param Bind       $bind
 */
PHP_METHOD(Phalcon_DataMapper_Query_Update, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *connection, connection_sub, *bind, bind_sub, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&bind_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_datamapper_pdo_connection_ce)
		Z_PARAM_OBJECT_OF_CLASS(bind, phalcon_datamapper_query_bind_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &bind);



	ZEPHIR_CALL_PARENT(NULL, phalcon_datamapper_query_update_ce, getThis(), "__construct", &_0, 0, connection, bind);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "FROM");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	zephir_update_property_array(this_ptr, SL("store"), &_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "RETURNING");
	zephir_update_property_array(this_ptr, SL("store"), &_4, &_3);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a column for the `UPDATE` query
 *
 * @param string $column
 *
 * @return this
 */
PHP_METHOD(Phalcon_DataMapper_Query_Update, column) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *column_param = NULL, *value = NULL, value_sub, *type_param = NULL, __$null, _1$$3, _2$$3;
	zval column, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(column)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(value)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &column_param, &value, &type_param);

	zephir_get_strval(&column, column_param);
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
	ZEPHIR_CONCAT_SV(&_0, ":", &column);
	zephir_update_property_array_multi(this_ptr, SL("store"), &_0, SL("sz"), 3, SL("COLUMNS"), &column);
	if (Z_TYPE_P(value) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("bind"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_2$$3, type);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "setvalue", NULL, 0, &column, value, &_2$$3);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Mass sets columns and values for the `UPDATE`
 *
 * @param array $columns
 *
 * @return this
 */
PHP_METHOD(Phalcon_DataMapper_Query_Update, columns) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns_param = NULL, column, value, *_0, _1;
	zval columns;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(columns)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &columns_param);

	zephir_get_arrval(&columns, columns_param);


	zephir_is_iterable(&columns, 0, "phalcon/DataMapper/Query/Update.zep", 76);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columns), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&column);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&column, _3);
			} else {
				ZVAL_LONG(&column, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (Z_TYPE_P(&column) == IS_LONG) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "column", &_4, 0, &value);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "column", &_4, 0, &column, &value);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &columns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &columns, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &columns, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&column) == IS_LONG) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "column", &_4, 0, &value);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "column", &_4, 0, &column, &value);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&column);
	RETURN_THIS();

}

/**
 * Adds table(s) in the query
 *
 * @param string $table
 *
 * @return Update
 */
PHP_METHOD(Phalcon_DataMapper_Query_Update, from) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL, _0;
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
	ZVAL_STRING(&_0, "FROM");
	zephir_update_property_array(this_ptr, SL("store"), &_0, &table);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_Update, getStatement) {

	zval _0, _1, _2, _3, _4, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "buildflags", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_2, &_1, SL("FROM"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Update.zep", 101);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "buildcolumns", NULL, 212);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "WHERE");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "buildcondition", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "buildreturning", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVVVV(return_value, "UPDATE", &_0, " ", &_2, &_3, &_4, &_6);
	RETURN_MM();

}

/**
 * Whether the query has columns or not
 *
 * @return bool
 */
PHP_METHOD(Phalcon_DataMapper_Query_Update, hasColumns) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("COLUMNS"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Update.zep", 113);
	RETURN_BOOL(zephir_fast_count_int(&_1) > 0);

}

/**
 * Adds the `RETURNING` clause
 *
 * @param array $columns
 *
 * @return Update
 */
PHP_METHOD(Phalcon_DataMapper_Query_Update, returning) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *columns_param = NULL, _0, _1, _2, _3;
	zval columns;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(columns)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &columns_param);

	zephir_get_arrval(&columns, columns_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_2, &_1, SL("RETURNING"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Update.zep", 126);
	zephir_fast_array_merge(&_0, &_2, &columns);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "RETURNING");
	zephir_update_property_array(this_ptr, SL("store"), &_3, &_0);
	RETURN_THIS();

}

/**
 * Resets the internal store
 */
PHP_METHOD(Phalcon_DataMapper_Query_Update, reset) {

	zval _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phalcon_datamapper_query_update_ce, getThis(), "reset", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "FROM");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	zephir_update_property_array(this_ptr, SL("store"), &_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "RETURNING");
	zephir_update_property_array(this_ptr, SL("store"), &_4, &_3);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a column = value condition
 *
 * @param string     $column
 * @param mixed|null $value
 *
 * @return Update
 */
PHP_METHOD(Phalcon_DataMapper_Query_Update, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column_param = NULL, *value = NULL, value_sub, __$null, _0;
	zval column;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(column)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &column_param, &value);

	zephir_get_strval(&column, column_param);
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
	zephir_update_property_array_multi(this_ptr, SL("store"), value, SL("sz"), 3, SL("COLUMNS"), &column);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("bind"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "remove", NULL, 0, &column);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Builds the column list
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_Update, buildColumns) {

	zend_string *_5;
	zend_ulong _4;
	zval assignments;
	zval column, value, _0, _1, *_2, _3, _11, _12, _6$$3, _8$$3, _9$$4, _10$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&assignments);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&assignments);
	array_init(&assignments);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("COLUMNS"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Update.zep", 175);
	zephir_is_iterable(&_1, 0, "phalcon/DataMapper/Query/Update.zep", 179);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&column);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&column, _5);
			} else {
				ZVAL_LONG(&column, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "quoteidentifier", &_7, 0, &column);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZEPHIR_CONCAT_VSV(&_8$$3, &_6$$3, " = ", &value);
			zephir_array_append(&assignments, &_8$$3, PH_SEPARATE, "phalcon/DataMapper/Query/Update.zep", 176);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &_1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "quoteidentifier", &_7, 0, &column);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$4);
				ZEPHIR_CONCAT_VSV(&_10$$4, &_9$$4, " = ", &value);
				zephir_array_append(&assignments, &_10$$4, PH_SEPARATE, "phalcon/DataMapper/Query/Update.zep", 176);
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, ",");
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "indent", NULL, 0, &assignments, &_12);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, " SET", &_11);
	RETURN_MM();

}

