
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
 * Connects to a Redis server (ext-redis) and builds a RedisContext. The
 * connection (connect/pconnect, auth, database select) is delegated to
 * Phalcon\Storage\Adapter\Redis so the queue reuses the framework's hardened
 * connection handling instead of re-implementing it.
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
 *
 * @phpstan-import-type queue_redis_options from QueueTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Redis_RedisConnectionFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter\\Redis, RedisConnectionFactory, phalcon, queue_adapter_redis_redisconnectionfactory, phalcon_queue_adapter_redis_redisconnectionfactory_method_entry, 0);

	/**
	 * @phpstan-param queue_redis_options $options
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_queue_adapter_redis_redisconnectionfactory_ce, SL("options"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_queue_adapter_redis_redisconnectionfactory_ce, 1, phalcon_contracts_queue_connectionfactory_ce);
	return SUCCESS;
}

/**
 * @phpstan-param queue_redis_options $options
 */
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisConnectionFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1277, &options);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisConnectionFactory, createContext)
{
	zval _4;
	zval options, adapter, redis, prefix, pollInterval, e, _0, _1, _2, _3, _5, _6$$4, _7$$4, _8$$4, _9$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&pollInterval);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1277, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	if (zephir_array_isset_value_string(&options, SL("prefix"))) {
		zephir_memory_observe(&prefix);
		zephir_array_fetch_string(&prefix, &options, SL("prefix"), PH_NOISY, "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 69);
	} else {
		ZEPHIR_INIT_NVAR(&prefix);
		ZVAL_STRING(&prefix, "phalcon_queue:");
	}
	if (zephir_array_isset_value_string(&options, SL("pollInterval"))) {
		zephir_memory_observe(&_1);
		zephir_array_fetch_string(&_1, &options, SL("pollInterval"), PH_NOISY, "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 70);
		ZEPHIR_INIT_VAR(&pollInterval);
		ZVAL_LONG(&pollInterval, zephir_get_intval(&_1));
	} else {
		ZEPHIR_INIT_NVAR(&pollInterval);
		ZVAL_LONG(&pollInterval, 200);
	}
	ZEPHIR_INIT_VAR(&adapter);
	object_init_ex(&adapter, phalcon_storage_adapter_redis_ce);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_storage_serializerfactory_ce);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	add_assoc_stringl_ex(&_4, SL("prefix"), SL(""));
	add_assoc_stringl_ex(&_4, SL("defaultSerializer"), SL("none"));
	zephir_fast_array_merge(&_3, &options, &_4);
	ZEPHIR_CALL_METHOD(NULL, &adapter, "__construct", NULL, 0, &_2, &_3);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&redis, &adapter, "getadapter", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_OBJ(&_5, EG(exception));
		Z_ADDREF_P(&_5);
		if (zephir_instance_of_ev(&_5, phalcon_storage_exception_ce)) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_5);
			ZEPHIR_INIT_VAR(&_6$$4);
			object_init_ex(&_6$$4, phalcon_queue_exceptions_exception_ce);
			ZEPHIR_CALL_METHOD(&_7$$4, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8$$4, &e, "getcode", NULL, 0);
			zephir_check_call_status();
			ZVAL_LONG(&_9$$4, zephir_get_intval(&_8$$4));
			ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", NULL, 9, &_7$$4, &_9$$4, &e);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$4, "phalcon/Queue/Adapter/Redis/RedisConnectionFactory.zep", 97);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	object_init_ex(return_value, phalcon_queue_adapter_redis_rediscontext_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &redis, &prefix, &pollInterval);
	zephir_check_call_status();
	RETURN_MM();
}

