
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"


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
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_Delete) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\DataMapper\\Query, Delete, phalcon, datamapper_query_delete, phalcon_datamapper_query_abstractconditions_ce, phalcon_datamapper_query_delete_method_entry, 0);

	return SUCCESS;

}

/**
 * Delete constructor.
 *
 * @param Connection $connection
 * @param Bind       $bind
 */
PHP_METHOD(Phalcon_DataMapper_Query_Delete, __construct) {

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



	ZEPHIR_CALL_PARENT(NULL, phalcon_datamapper_query_delete_ce, getThis(), "__construct", &_0, 0, connection, bind);
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
 * Adds table(s) in the query
 *
 * @param string $table
 *
 * @return AbstractConditions
 */
PHP_METHOD(Phalcon_DataMapper_Query_Delete, from) {

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
 * Adds the `RETURNING` clause
 *
 * @param array $columns
 *
 * @return Delete
 */
PHP_METHOD(Phalcon_DataMapper_Query_Delete, returning) {

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
	zephir_array_fetch_string(&_2, &_1, SL("RETURNING"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Delete.zep", 60);
	zephir_fast_array_merge(&_0, &_2, &columns);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "RETURNING");
	zephir_update_property_array(this_ptr, SL("store"), &_3, &_0);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_Delete, getStatement) {

	zval _0, _1, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "buildflags", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_2, &_1, SL("FROM"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/Delete.zep", 75);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "WHERE");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "buildcondition", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "buildreturning", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVVV(return_value, "DELETE", &_0, " FROM ", &_2, &_3, &_5);
	RETURN_MM();

}

/**
 * Resets the internal store
 */
PHP_METHOD(Phalcon_DataMapper_Query_Delete, reset) {

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

	ZEPHIR_CALL_PARENT(NULL, phalcon_datamapper_query_delete_ce, getThis(), "reset", &_0, 0);
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

