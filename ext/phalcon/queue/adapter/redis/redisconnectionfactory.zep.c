
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
 */
/**
 * Connects to a Redis server (ext-redis) and builds a RedisContext.
 *
 * Options:
 *   - host:         server host (default 127.0.0.1).
 *   - port:         server port (default 6379).
 *   - timeout:      connection timeout in seconds (default 0).
 *   - persistent:   use a persistent connection (default false).
 *   - persistentId: identifier for the persistent connection.
 *   - auth:         password, or [user, password] for ACL auth.
 *   - index:        database index to SELECT (default 0).
 *   - prefix:       key prefix for every queue (default "phalcon_queue:").
 *   - pollInterval: milliseconds between subscription poll passes (default 200).
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Redis_RedisConnectionFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter\\Redis, RedisConnectionFactory, phalcon, queue_adapter_redis_redisconnectionfactory, phalcon_queue_adapter_redis_redisconnectionfactory_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_queue_adapter_redis_redisconnectionfactory_ce, SL("options"), ZEND_ACC_PROTECTED);
	phalcon_queue_adapter_redis_redisconnectionfactory_ce->create_object = zephir_init_properties_Phalcon_Queue_Adapter_Redis_RedisConnectionFactory;

	zend_class_implements(phalcon_queue_adapter_redis_redisconnectionfactory_ce, 1, phalcon_contracts_queue_connectionfactory_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisConnectionFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisConnectionFactory, createContext)
{
	zend_bool _8, _10;
	zval options, redis, host, port, timeout, persistent, persistentId, auth, index, prefix, pollInterval, parameter, result, _0, _1, _2, _3, _4, _9, _11, _5$$5, _6$$5, _7$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&timeout);
	ZVAL_UNDEF(&persistent);
	ZVAL_UNDEF(&persistentId);
	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&pollInterval);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	if (zephir_array_isset_value_string(&options, SL("host"))) {
		zephir_memory_observe(&host);
		zephir_array_fetch_string(&host, &options, SL("host"), PH_NOISY, "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 58);
	} else {
		ZEPHIR_INIT_NVAR(&host);
		ZVAL_STRING(&host, "127.0.0.1");
	}
	if (zephir_array_isset_value_string(&options, SL("port"))) {
		zephir_memory_observe(&_1);
		zephir_array_fetch_string(&_1, &options, SL("port"), PH_NOISY, "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 59);
		ZEPHIR_INIT_VAR(&port);
		ZVAL_LONG(&port, zephir_get_intval(&_1));
	} else {
		ZEPHIR_INIT_NVAR(&port);
		ZVAL_LONG(&port, 6379);
	}
	if (zephir_array_isset_value_string(&options, SL("timeout"))) {
		zephir_memory_observe(&_2);
		zephir_array_fetch_string(&_2, &options, SL("timeout"), PH_NOISY, "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 60);
		ZEPHIR_INIT_VAR(&timeout);
		ZVAL_DOUBLE(&timeout, zephir_get_doubleval(&_2));
	} else {
		ZEPHIR_INIT_NVAR(&timeout);
		ZVAL_DOUBLE(&timeout, 0.0);
	}
	if (zephir_array_isset_value_string(&options, SL("persistent"))) {
		zephir_memory_observe(&_3);
		zephir_array_fetch_string(&_3, &options, SL("persistent"), PH_NOISY, "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 61);
		ZEPHIR_INIT_VAR(&persistent);
		ZVAL_BOOL(&persistent, zephir_get_boolval(&_3));
	} else {
		ZEPHIR_INIT_NVAR(&persistent);
		ZVAL_BOOL(&persistent, 0);
	}
	if (zephir_array_isset_value_string(&options, SL("persistentId"))) {
		zephir_memory_observe(&persistentId);
		zephir_array_fetch_string(&persistentId, &options, SL("persistentId"), PH_NOISY, "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 62);
	} else {
		ZEPHIR_INIT_NVAR(&persistentId);
		ZVAL_STRING(&persistentId, "");
	}
	if (zephir_array_isset_value_string(&options, SL("auth"))) {
		zephir_memory_observe(&auth);
		zephir_array_fetch_string(&auth, &options, SL("auth"), PH_NOISY, "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 63);
	} else {
		ZEPHIR_INIT_NVAR(&auth);
		ZVAL_STRING(&auth, "");
	}
	if (zephir_array_isset_value_string(&options, SL("index"))) {
		ZEPHIR_OBS_NVAR(&_3);
		zephir_array_fetch_string(&_3, &options, SL("index"), PH_NOISY, "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 64);
		ZEPHIR_INIT_VAR(&index);
		ZVAL_LONG(&index, zephir_get_intval(&_3));
	} else {
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_LONG(&index, 0);
	}
	if (zephir_array_isset_value_string(&options, SL("prefix"))) {
		zephir_memory_observe(&prefix);
		zephir_array_fetch_string(&prefix, &options, SL("prefix"), PH_NOISY, "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 65);
	} else {
		ZEPHIR_INIT_NVAR(&prefix);
		ZVAL_STRING(&prefix, "phalcon_queue:");
	}
	if (zephir_array_isset_value_string(&options, SL("pollInterval"))) {
		zephir_memory_observe(&_4);
		zephir_array_fetch_string(&_4, &options, SL("pollInterval"), PH_NOISY, "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 66);
		ZEPHIR_INIT_VAR(&pollInterval);
		ZVAL_LONG(&pollInterval, zephir_get_intval(&_4));
	} else {
		ZEPHIR_INIT_NVAR(&pollInterval);
		ZVAL_LONG(&pollInterval, 200);
	}
	ZEPHIR_INIT_VAR(&redis);
	object_init_ex(&redis, zephir_get_internal_ce(SL("redis")));
	ZEPHIR_CALL_METHOD(NULL, &redis, "__construct", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&persistent)) {
		if (!(ZEPHIR_IS_EMPTY(&persistentId))) {
			ZEPHIR_CPY_WRT(&parameter, &persistentId);
		} else {
			ZEPHIR_INIT_NVAR(&parameter);
			ZEPHIR_CONCAT_SV(&parameter, "persistentId", &index);
		}
		ZEPHIR_CALL_METHOD(&result, &redis, "pconnect", NULL, 0, &host, &port, &timeout, &parameter);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&result, &redis, "connect", NULL, 0, &host, &port, &timeout);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(&result))) {
		ZEPHIR_INIT_VAR(&_5$$5);
		object_init_ex(&_5$$5, phalcon_queue_exceptions_exception_ce);
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "Could not connect to the Redis server [%s:%s]");
		ZEPHIR_CALL_FUNCTION(&_7$$5, "sprintf", NULL, 137, &_6$$5, &host, &port);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", NULL, 8, &_7$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$5, "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 80);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_8 = !(ZEPHIR_IS_EMPTY(&auth));
	if (_8) {
		ZEPHIR_CALL_METHOD(&_9, &redis, "auth", NULL, 0, &auth);
		zephir_check_call_status();
		_8 = !ZEPHIR_IS_TRUE_IDENTICAL(&_9);
	}
	if (_8) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_exception_ce, "Failed to authenticate with the Redis server", "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 84);
		return;
	}
	_10 = ZEPHIR_GT_LONG(&index, 0);
	if (_10) {
		ZEPHIR_CALL_METHOD(&_11, &redis, "select", NULL, 0, &index);
		zephir_check_call_status();
		_10 = !ZEPHIR_IS_TRUE_IDENTICAL(&_11);
	}
	if (_10) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_exception_ce, "Failed to select the Redis database index", "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 88);
		return;
	}
	object_init_ex(return_value, phalcon_queue_adapter_redis_rediscontext_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &redis, &prefix, &pollInterval);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Queue_Adapter_Redis_RedisConnectionFactory(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

