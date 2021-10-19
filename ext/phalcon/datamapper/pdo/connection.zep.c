
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/pdo/php_pdo_driver.h"


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
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */
/**
 * Provides array quoting, profiling, a new `perform()` method, new `fetch*()`
 * methods
 *
 * @property array             $arguments
 * @property PDO               $pdo
 * @property ProfilerInterface $profiler
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Connection)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\DataMapper\\Pdo, Connection, phalcon, datamapper_pdo_connection, phalcon_datamapper_pdo_connection_abstractconnection_ce, phalcon_datamapper_pdo_connection_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_datamapper_pdo_connection_ce, SL("arguments"), ZEND_ACC_PROTECTED);
	phalcon_datamapper_pdo_connection_ce->create_object = zephir_init_properties_Phalcon_DataMapper_Pdo_Connection;

	return SUCCESS;
}

/**
 * Constructor.
 *
 * This overrides the parent so that it can take connection attributes as a
 * constructor parameter, and set them after connection.
 *
 * @param string            $dsn
 * @param string            $username
 * @param string            $password
 * @param array             $options
 * @param array             $queries
 * @param ProfilerInterface $profiler
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, queries, available, _5;
	zval *dsn_param = NULL, *username_param = NULL, *password_param = NULL, *options_param = NULL, *queries_param = NULL, *profiler = NULL, profiler_sub, __$true, __$null, parts, _0, _1$$3, _2$$3, _3$$3, _4$$4;
	zval dsn, username, password;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dsn);
	ZVAL_UNDEF(&username);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&profiler_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&queries);
	ZVAL_UNDEF(&available);
	ZVAL_UNDEF(&_5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 6)
		Z_PARAM_STR(dsn)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(username)
		Z_PARAM_STR_OR_NULL(password)
		Z_PARAM_ARRAY(options)
		Z_PARAM_ARRAY(queries)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(profiler, phalcon_datamapper_pdo_profiler_profilerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &dsn_param, &username_param, &password_param, &options_param, &queries_param, &profiler);
	zephir_get_strval(&dsn, dsn_param);
	if (!username_param) {
		ZEPHIR_INIT_VAR(&username);
	} else {
		zephir_get_strval(&username, username_param);
	}
	if (!password_param) {
		ZEPHIR_INIT_VAR(&password);
	} else {
		zephir_get_strval(&password, password_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	if (!queries_param) {
		ZEPHIR_INIT_VAR(&queries);
		array_init(&queries);
	} else {
		zephir_get_arrval(&queries, queries_param);
	}
	if (!profiler) {
		profiler = &profiler_sub;
		ZEPHIR_CPY_WRT(profiler, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(profiler);
	}


	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL(":"), &dsn, LONG_MAX);
	ZEPHIR_INIT_VAR(&available);
	zephir_create_array(&available, 4, 0);
	zephir_array_update_string(&available, SL("mysql"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&available, SL("pgsql"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&available, SL("sqlite"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&available, SL("mssql"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_long(&_0, &parts, 0, PH_READONLY, "phalcon/DataMapper/Pdo/Connection.zep", 69);
	if (!(zephir_array_isset(&available, &_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_InvalidArgumentException);
		zephir_array_fetch_long(&_2$$3, &parts, 0, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Pdo/Connection.zep", 71);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, "Driver not supported [", &_2$$3, "]");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 40, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/DataMapper/Pdo/Connection.zep", 72);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_array_isset_long(&options, 3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_LONG(&_4$$4, 2);
		zephir_array_update_long(&options, 3, &_4$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 5, 0);
	zephir_array_fast_append(&_5, &dsn);
	zephir_array_fast_append(&_5, &username);
	zephir_array_fast_append(&_5, &password);
	zephir_array_fast_append(&_5, &options);
	zephir_array_fast_append(&_5, &queries);
	zephir_update_property_zval(this_ptr, ZEND_STRL("arguments"), &_5);
	if (Z_TYPE_P(profiler) == IS_NULL) {
		ZEPHIR_INIT_NVAR(profiler);
		object_init_ex(profiler, phalcon_datamapper_pdo_profiler_profiler_ce);
		ZEPHIR_CALL_METHOD(NULL, profiler, "__construct", NULL, 208);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setprofiler", NULL, 0, profiler);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * The purpose of this method is to hide sensitive data from stack traces.
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection, __debugInfo)
{
	zval _1, _2, _3, _4, _5;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);


	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 1, 0);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 5, 0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_array_fetch_long(&_2, &_1, 0, PH_NOISY, "phalcon/DataMapper/Pdo/Connection.zep", 106);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "****");
	zephir_array_fast_append(&_0, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "****");
	zephir_array_fast_append(&_0, &_3);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_NVAR(&_2);
	zephir_array_fetch_long(&_2, &_4, 3, PH_NOISY, "phalcon/DataMapper/Pdo/Connection.zep", 109);
	zephir_array_fast_append(&_0, &_2);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_NVAR(&_2);
	zephir_array_fetch_long(&_2, &_5, 4, PH_NOISY, "phalcon/DataMapper/Pdo/Connection.zep", 111);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("arguments"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Connects to the database.
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection, connect)
{
	zval dsn, options, password, query, queries, username, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, *_9$$3, _10$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dsn);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&queries);
	ZVAL_UNDEF(&username);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "connect");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "start", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&dsn);
		zephir_array_fetch_long(&dsn, &_3$$3, 0, PH_NOISY, "phalcon/DataMapper/Pdo/Connection.zep", 126);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&username);
		zephir_array_fetch_long(&username, &_4$$3, 1, PH_NOISY, "phalcon/DataMapper/Pdo/Connection.zep", 127);
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&password);
		zephir_array_fetch_long(&password, &_5$$3, 2, PH_NOISY, "phalcon/DataMapper/Pdo/Connection.zep", 128);
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&options);
		zephir_array_fetch_long(&options, &_6$$3, 3, PH_NOISY, "phalcon/DataMapper/Pdo/Connection.zep", 129);
		zephir_read_property(&_7$$3, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&queries);
		zephir_array_fetch_long(&queries, &_7$$3, 4, PH_NOISY, "phalcon/DataMapper/Pdo/Connection.zep", 130);
		ZEPHIR_INIT_NVAR(&_2$$3);
		object_init_ex(&_2$$3, php_pdo_get_dbh_ce());
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0, &dsn, &username, &password, &options);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("pdo"), &_2$$3);
		zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_8$$3, "finish", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&queries, 0, "phalcon/DataMapper/Pdo/Connection.zep", 140);
		if (Z_TYPE_P(&queries) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queries), _9$$3)
			{
				ZEPHIR_INIT_NVAR(&query);
				ZVAL_COPY(&query, _9$$3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "exec", &_11, 0, &query);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &queries, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_10$$3, &queries, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&query, &queries, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "exec", &_11, 0, &query);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &queries, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&query);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Disconnects from the database.
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection, disconnect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "disconnect");
	ZEPHIR_CALL_METHOD(NULL, &_0, "start", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("pdo"), &__$null);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "finish", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Phalcon_DataMapper_Pdo_Connection(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("arguments"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

