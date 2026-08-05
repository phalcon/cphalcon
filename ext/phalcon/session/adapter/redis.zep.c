
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Session\Adapter\Redis
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Redis)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, Redis, phalcon, session_adapter_redis, phalcon_session_adapter_abstractadapter_ce, phalcon_session_adapter_redis_method_entry, 0);

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_session_adapter_redis_ce, SL("lockAcquired"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * Lock time-to-live in seconds. The lock is not refreshed during the
	 * request: a request that runs longer than this expiry loses its lock
	 * silently and a concurrent request may then acquire it (the token-guarded
	 * release still avoids deleting the newer lock). Raise this above the
	 * longest expected request to retain the lock for the whole request.
	 */
	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 30);
		zephir_declare_typed_property(phalcon_session_adapter_redis_ce, SL("lockExpiry"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_session_adapter_redis_ce, SL("lockingEnabled"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_session_adapter_redis_ce, SL("lockKey"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 100);
		zephir_declare_typed_property(phalcon_session_adapter_redis_ce, SL("lockRetries"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_session_adapter_redis_ce, SL("lockToken"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 50000);
		zephir_declare_typed_property(phalcon_session_adapter_redis_ce, SL("lockWaitTime"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_session_adapter_redis_ce, SL("prefix"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Constructor
 *
 * @param AdapterFactory $factory
 * @param array          $options = [
 *                                'prefix'         => 'sess-reds-',
 *                                'stripPrefix'    => false,
 *                                'host'           => '127.0.0.1',
 *                                'port'           => 6379,
 *                                'index'          => 0,
 *                                'persistent'     => false,
 *                                'auth'           => '',
 *                                'socket'         => '',
 *                                'lockingEnabled' => false,
 *                                'lockExpiry'     => 30,
 *                                'lockRetries'    => 100,
 *                                'lockWaitTime'   => 50000,
 * ]
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Session_Adapter_Redis, __construct)
{
	zval _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *factory, factory_sub, *options_param = NULL, __$true, __$false, _0, _1, _2, _3, _4, _5, _6, _7, _8, _10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_9);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("lockExpiry", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("lockingEnabled", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("lockRetries", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("lockWaitTime", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("prefix", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("adapter", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(factory, phalcon_storage_adapterfactory_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &factory, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "prefix");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "sess-reds-");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarrval", NULL, 0, &options, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("prefix"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "stripPrefix");
	ZVAL_BOOL(&_4, 0);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getarrval", NULL, 0, &options, &_1, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("stripPrefix"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "lockExpiry");
	ZVAL_LONG(&_4, 30);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getarrval", NULL, 0, &options, &_1, &_4);
	zephir_check_call_status();
	ZVAL_UNDEF(&_4);
	ZVAL_LONG(&_4, zephir_get_intval(&_5));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1306, &_4);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "lockingEnabled");
	ZVAL_BOOL(&_4, 0);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getarrval", NULL, 0, &options, &_1, &_4);
	zephir_check_call_status();
	if (zephir_get_boolval(&_6)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1307, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1307, &__$false);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "lockRetries");
	ZVAL_LONG(&_4, 100);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getarrval", NULL, 0, &options, &_1, &_4);
	zephir_check_call_status();
	ZVAL_UNDEF(&_4);
	ZVAL_LONG(&_4, zephir_get_intval(&_6));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1308, &_4);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "lockWaitTime");
	ZVAL_LONG(&_4, 50000);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getarrval", NULL, 0, &options, &_1, &_4);
	zephir_check_call_status();
	ZVAL_UNDEF(&_4);
	ZVAL_LONG(&_4, zephir_get_intval(&_7));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1309, &_4);
	zephir_memory_observe(&_8);
	zephir_array_fetch_string(&_8, &options, SL("prefix"), PH_NOISY, "phalcon/Session/Adapter/Redis.zep", 72);
	zephir_cast_to_string(&_9, &_8);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1310, &_9);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "redis");
	ZEPHIR_CALL_METHOD(&_10, factory, "newinstance", NULL, 0, &_1, &options);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1311, &_10);
	ZEPHIR_MM_RESTORE();
}

/**
 * Close - releases the session lock if one is held
 */
PHP_METHOD(Phalcon_Session_Adapter_Redis, close)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "releaselock", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);
}

/**
 * Destroy
 */
PHP_METHOD(Phalcon_Session_Adapter_Redis, destroy)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval id_zv, result;
	zend_string *id = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_zv);
	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&id_zv);
	ZVAL_STR_COPY(&id_zv, id);
	ZEPHIR_CALL_PARENT(&result, phalcon_session_adapter_redis_ce, getThis(), "destroy", NULL, 0, &id_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "releaselock", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&result);
}

/**
 * Read
 */
PHP_METHOD(Phalcon_Session_Adapter_Redis, read)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval id_zv, _0, _2, _3$$3, _4$$3, _5$$3;
	zend_string *id = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("lockingEnabled", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("lockKey", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&id_zv);
	ZVAL_STR_COPY(&id_zv, id);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1307, PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_IS_TRUE_IDENTICAL(&_0);
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "acquirelock", NULL, 0, &id_zv);
		zephir_check_call_status();
		_1 = !ZEPHIR_IS_TRUE_IDENTICAL(&_2);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_session_adapter_exceptions_adapterruntimeerror_ce);
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_1, 1312, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_SV(&_5$$3, "Could not acquire the session lock with key: ", &_4$$3);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 8, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Session/Adapter/Redis.zep", 108);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_PARENT(phalcon_session_adapter_redis_ce, getThis(), "read", NULL, 0, &id_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tries to acquire the session lock, pausing `lockWaitTime` microseconds
 * between attempts, up to `lockRetries` times
 */
PHP_METHOD(Phalcon_Session_Adapter_Redis, acquireLock)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, attempt = 0;
	zval id_zv, __$true, __$false, client, lockKey, result, token, _0, _1, _3, _4, _5, _6, _7$$4, _8$$4, _9$$4, _10$$4, _11$$4, _13$$4;
	zend_string *id = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&client);
	ZVAL_UNDEF(&lockKey);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_13$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("prefix", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("lockAcquired", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("lockKey", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("adapter", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("lockRetries", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("lockExpiry", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("lockToken", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("lockWaitTime", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&id_zv);
	ZVAL_STR_COPY(&id_zv, id);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1310, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&lockKey);
	ZEPHIR_CONCAT_VVS(&lockKey, &_0, &id_zv, "-lock");
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1313, PH_NOISY_CC | PH_READONLY);
	_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	if (_2) {
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 1312, PH_NOISY_CC | PH_READONLY);
		_2 = ZEPHIR_IS_IDENTICAL(&lockKey, &_3);
	}
	if (_2) {
		RETURN_MM_BOOL(1);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1312, &lockKey);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_3, 1311, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&client, &_4, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 16);
	ZEPHIR_CALL_FUNCTION(&_6, "random_bytes", NULL, 319, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&token, "bin2hex", NULL, 320, &_6);
	zephir_check_call_status();
	attempt = 0;
	while (1) {
		zephir_read_property_cached(&_5, this_ptr, _zephir_prop_4, 1308, PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_GT_LONG(&_5, attempt))) {
			break;
		}
		zephir_read_property_cached(&_7$$4, this_ptr, _zephir_prop_2, 1312, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_8$$4, this_ptr, _zephir_prop_5, 1306, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "SET");
		ZEPHIR_INIT_NVAR(&_10$$4);
		ZVAL_STRING(&_10$$4, "NX");
		ZEPHIR_INIT_NVAR(&_11$$4);
		ZVAL_STRING(&_11$$4, "EX");
		ZEPHIR_CALL_METHOD(&result, &client, "rawcommand", &_12, 0, &_9$$4, &_7$$4, &token, &_10$$4, &_11$$4, &_8$$4);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
			if (1) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1313, &__$true);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1313, &__$false);
			}
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1314, &token);
			RETURN_MM_BOOL(1);
		}
		zephir_read_property_cached(&_13$$4, this_ptr, _zephir_prop_7, 1309, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_14, 73, &_13$$4);
		zephir_check_call_status();
		attempt++;
	}
	RETURN_MM_BOOL(0);
}

/**
 * Releases the session lock - only when this instance still owns it
 */
PHP_METHOD(Phalcon_Session_Adapter_Redis, releaseLock)
{
	zval script;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, client, _0, _1, _2, _3, _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&client);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&script);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("lockAcquired", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("adapter", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("lockKey", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("lockToken", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1313, PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&script);
	ZVAL_STRING(&script, "if redis.call('get', KEYS[1]) == ARGV[1] then return redis.call('del', KEYS[1]) else return 0 end");
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1311, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&client, &_1, "getadapter", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_2, 1312, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_3, 1314, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "EVAL");
	ZVAL_LONG(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &client, "rawcommand", NULL, 0, &_4, &script, &_5, &_2, &_3);
	zephir_check_call_status();
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1313, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1313, &__$false);
	}
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "");
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1314, &_4);
	ZEPHIR_MM_RESTORE();
}

