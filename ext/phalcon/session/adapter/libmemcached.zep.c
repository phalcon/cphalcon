
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


/**
 * Phalcon\Session\Adapter\Libmemcached
 *
 * This adapter store sessions in libmemcached
 *
 *<code>
 * $session = new Phalcon\Session\Adapter\Libmemcached(array(
 *     'servers' => array(
 *         array('host' => 'localhost', 'port' => 11211, 'weight' => 1),
 *     ),
 *     'client' => array(
 *         Memcached::OPT_HASH => Memcached::HASH_MD5,
 *         Memcached::OPT_PREFIX_KEY => 'prefix.',
 *     ),
 *    'lifetime' => 3600,
 *    'prefix' => 'my_'
 * ));
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

	zend_class_implements(phalcon_session_adapter_libmemcached_ce TSRMLS_CC, 1, phalcon_session_adapterinterface_ce);
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
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, __construct) {

	zephir_fcall_cache_entry *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, *servers, *client = NULL, *lifetime = NULL, *prefix = NULL, *statsKey = NULL, *_0, *_1, *_3, *_6 = NULL;
	zval *options = NULL, *_2, *_4, *_5, *_7, *_8, *_9, *_10, *_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	ZEPHIR_OBS_VAR(servers);
	if (!(zephir_array_isset_string_fetch(&servers, options, SS("servers"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_session_exception_ce, "No servers given in options", "phalcon/session/adapter/libmemcached.zep", 68);
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
	zephir_update_property_this(this_ptr, SL("_lifetime"), lifetime TSRMLS_CC);
	ZEPHIR_OBS_VAR(prefix);
	if (!(zephir_array_isset_string_fetch(&prefix, options, SS("prefix"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(prefix);
		ZVAL_NULL(prefix);
	}
	ZEPHIR_OBS_VAR(statsKey);
	if (!(zephir_array_isset_string_fetch(&statsKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(statsKey);
		ZVAL_NULL(statsKey);
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_cache_backend_libmemcached_ce);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_cache_frontend_data_ce);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_this(&_3, this_ptr, SL("_lifetime"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("lifetime"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 402, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&_4, SL("servers"), &servers, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("client"), &client, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("prefix"), &prefix, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("statsKey"), &statsKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 403, _1, _4);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_libmemcached"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_5, this_ptr);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "open", 1);
	zephir_array_fast_append(_5, _6);
	ZEPHIR_INIT_VAR(_7);
	zephir_create_array(_7, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_7, this_ptr);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "close", 1);
	zephir_array_fast_append(_7, _6);
	ZEPHIR_INIT_VAR(_8);
	zephir_create_array(_8, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_8, this_ptr);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "read", 1);
	zephir_array_fast_append(_8, _6);
	ZEPHIR_INIT_VAR(_9);
	zephir_create_array(_9, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_9, this_ptr);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "write", 1);
	zephir_array_fast_append(_9, _6);
	ZEPHIR_INIT_VAR(_10);
	zephir_create_array(_10, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_10, this_ptr);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "destroy", 1);
	zephir_array_fast_append(_10, _6);
	ZEPHIR_INIT_VAR(_11);
	zephir_create_array(_11, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_11, this_ptr);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "gc", 1);
	zephir_array_fast_append(_11, _6);
	ZEPHIR_CALL_FUNCTION(NULL, "session_set_save_handler", NULL, 404, _5, _7, _8, _9, _10, _11);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_session_adapter_libmemcached_ce, this_ptr, "__construct", &_12, 405, options);
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
 *
 * @param string sessionId
 * @return mixed
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, read) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_libmemcached"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, sessionId, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 *
 * @param string sessionId
 * @param string data
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, write) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, *data, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId, &data);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_libmemcached"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "save", NULL, 0, sessionId, data, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 *
 * @param  string  sessionId
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, destroy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sessionId);

	if (!sessionId) {
		ZEPHIR_CPY_WRT(sessionId, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(sessionId);
	}


	if (Z_TYPE_P(sessionId) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&sessionId, this_ptr, "getid", NULL, 0);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_libmemcached"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "delete", NULL, 0, sessionId);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, gc) {


	RETURN_BOOL(1);

}

