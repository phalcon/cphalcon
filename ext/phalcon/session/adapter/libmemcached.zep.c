
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


/**
 * Phalcon\Session\Adapter\Libmemcached
 *
 * This adapter store sessions in libmemcached
 *
 *<code>
 * use Phalcon\Session\Adapter\Libmemcached;
 *
 * $session = new Libmemcached([
 *     'servers' => [
 *         ['host' => 'localhost', 'port' => 11211, 'weight' => 1],
 *     ],
 *     'client' => [
 *         \Memcached::OPT_HASH       => \Memcached::HASH_MD5,
 *         \Memcached::OPT_PREFIX_KEY => 'prefix.',
 *     ],
 *    'lifetime' => 3600,
 *    'prefix'   => 'my_'
 * ]);
 *
 * $session->start();
 *
 * $session->set('var', 'some-value');
 *
 * echo $session->get('var');
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Libmemcached) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, Libmemcached, phalcon, session_adapter_libmemcached, phalcon_session_adapter_ce, phalcon_session_adapter_libmemcached_method_entry, 0);

	zend_declare_property_null(phalcon_session_adapter_libmemcached_ce, SL("_libmemcached"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_session_adapter_libmemcached_ce, SL("_lifetime"), 8600, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, getLibmemcached) {

	

	RETURN_MEMBER(this_ptr, "_libmemcached");

}

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, getLifetime) {

	

	RETURN_MEMBER(this_ptr, "_lifetime");

}

/**
 * Phalcon\Session\Adapter\Libmemcached constructor
 *
 * @throws \Phalcon\Session\Exception
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, __construct) {

	zephir_fcall_cache_entry *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, *servers = NULL, *client = NULL, *lifetime = NULL, *prefix = NULL, *statsKey = NULL, *persistentId = NULL, *_0 = NULL, *_1 = NULL, *_2, *_4, *_7 = NULL;
	zval *options = NULL, *_3, *_5, *_6, *_8, *_9, *_10, *_11, *_12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	ZEPHIR_OBS_VAR(servers);
	if (!(zephir_array_isset_string_fetch(&servers, options, SS("servers"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_session_exception_ce, "No servers given in options", "phalcon/session/adapter/libmemcached.zep", 70);
		return;
	}
	ZEPHIR_OBS_VAR(client);
	if (!(zephir_array_isset_string_fetch(&client, options, SS("client"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(client);
		ZVAL_NULL(client);
	}
	ZEPHIR_OBS_VAR(lifetime);
	if (!(zephir_array_isset_string_fetch(&lifetime, options, SS("lifetime"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(lifetime);
		ZVAL_LONG(lifetime, 8600);
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2592000);
	ZEPHIR_CALL_FUNCTION(&_1, "min", NULL, 426, lifetime, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_lifetime"), _1 TSRMLS_CC);
	ZEPHIR_OBS_VAR(prefix);
	if (!(zephir_array_isset_string_fetch(&prefix, options, SS("prefix"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(prefix);
		ZVAL_NULL(prefix);
	}
	ZEPHIR_OBS_VAR(statsKey);
	if (!(zephir_array_isset_string_fetch(&statsKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(statsKey);
		ZVAL_STRING(statsKey, "", 1);
	}
	ZEPHIR_OBS_VAR(persistentId);
	if (!(zephir_array_isset_string_fetch(&persistentId, options, SS("persistent_id"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(persistentId);
		ZVAL_STRING(persistentId, "phalcon-session", 1);
	}
	ZEPHIR_INIT_NVAR(_0);
	object_init_ex(_0, phalcon_cache_backend_libmemcached_ce);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, phalcon_cache_frontend_data_ce);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_this(&_4, this_ptr, SL("_lifetime"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("lifetime"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 327, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 5, 0 TSRMLS_CC);
	zephir_array_update_string(&_5, SL("servers"), &servers, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("client"), &client, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("prefix"), &prefix, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("statsKey"), &statsKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("persistent_id"), &persistentId, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 328, _2, _5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_libmemcached"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_6, this_ptr);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "open", 1);
	zephir_array_fast_append(_6, _7);
	ZEPHIR_INIT_VAR(_8);
	zephir_create_array(_8, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_8, this_ptr);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "close", 1);
	zephir_array_fast_append(_8, _7);
	ZEPHIR_INIT_VAR(_9);
	zephir_create_array(_9, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_9, this_ptr);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "read", 1);
	zephir_array_fast_append(_9, _7);
	ZEPHIR_INIT_VAR(_10);
	zephir_create_array(_10, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_10, this_ptr);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "write", 1);
	zephir_array_fast_append(_10, _7);
	ZEPHIR_INIT_VAR(_11);
	zephir_create_array(_11, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_11, this_ptr);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "destroy", 1);
	zephir_array_fast_append(_11, _7);
	ZEPHIR_INIT_VAR(_12);
	zephir_create_array(_12, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_12, this_ptr);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "gc", 1);
	zephir_array_fast_append(_12, _7);
	ZEPHIR_CALL_FUNCTION(NULL, "session_set_save_handler", NULL, 427, _6, _8, _9, _10, _11, _12);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_session_adapter_libmemcached_ce, this_ptr, "__construct", &_13, 428, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, open) {

	

	RETURN_BOOL(1);

}

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, close) {

	

	RETURN_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, read) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, *_0, *_1;
	zval *sessionId = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId_param);

	zephir_get_strval(sessionId, sessionId_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_libmemcached"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, sessionId, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, write) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, *data_param = NULL, *_0, *_1;
	zval *sessionId = NULL, *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId_param, &data_param);

	zephir_get_strval(sessionId, sessionId_param);
	zephir_get_strval(data, data_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_libmemcached"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "save", NULL, 0, sessionId, data, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, destroy) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, *_SESSION, *id = NULL, *key = NULL, *_0 = NULL, **_3, *_4;
	zval *sessionId = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_fetch_params(1, 0, 1, &sessionId_param);

	if (!sessionId_param) {
		ZEPHIR_INIT_VAR(sessionId);
		ZVAL_EMPTY_STRING(sessionId);
	} else {
		zephir_get_strval(sessionId, sessionId_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(sessionId, "")) {
		ZEPHIR_CALL_METHOD(&id, this_ptr, "getid", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(id, sessionId);
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_is_iterable(_SESSION, &_2, &_1, 1, 0, "phalcon/session/adapter/libmemcached.zep", 161);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(_0, _3);
		zephir_array_unset(&_SESSION, key, PH_SEPARATE);
	}
	zend_hash_destroy(_2);
	FREE_HASHTABLE(_2);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_libmemcached"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_4, "delete", NULL, 0, id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, gc) {

	

	RETURN_BOOL(1);

}

