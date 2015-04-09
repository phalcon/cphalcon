
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/memory.h"
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
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, __construct) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_15 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_3, *_6, *_8, *_10, *_11, *_12, *_13, *_14;
	zval *options = NULL, *servers, *client = NULL, *lifetime, *prefix = NULL, *statsKey = NULL, *_0, *_1, *_2, *_4, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_session_exception_ce, "The options must be an array", "phalcon/session/adapter/libmemcached.zep", 70);
		return;
	}
	if (!(zephir_array_isset_string(options, SS("servers")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_session_exception_ce, "No servers given in options", "phalcon/session/adapter/libmemcached.zep", 74);
		return;
	}
	ZEPHIR_OBS_VAR(servers);
	zephir_array_fetch_string(&servers, options, SL("servers"), PH_NOISY, "phalcon/session/adapter/libmemcached.zep", 77 TSRMLS_CC);
	if (!(zephir_array_isset_string(options, SS("client")))) {
		ZEPHIR_INIT_VAR(client);
		ZVAL_NULL(client);
	} else {
		ZEPHIR_OBS_NVAR(client);
		zephir_array_fetch_string(&client, options, SL("client"), PH_NOISY, "phalcon/session/adapter/libmemcached.zep", 82 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, options, SS("lifetime"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_lifetime"), lifetime TSRMLS_CC);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_LONG(_0, 8600);
		zephir_update_property_this(this_ptr, SL("_lifetime"), _0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(prefix);
	if (!(zephir_array_isset_string_fetch(&prefix, options, SS("prefix"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(prefix);
		ZVAL_NULL(prefix);
	} else {
		ZEPHIR_OBS_NVAR(prefix);
		zephir_array_fetch_string(&prefix, options, SL("prefix"), PH_NOISY, "phalcon/session/adapter/libmemcached.zep", 94 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(statsKey);
	if (!(zephir_array_isset_string_fetch(&statsKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(statsKey);
		ZVAL_NULL(statsKey);
	} else {
		ZEPHIR_OBS_NVAR(statsKey);
		zephir_array_fetch_string(&statsKey, options, SL("statsKey"), PH_NOISY, "phalcon/session/adapter/libmemcached.zep", 100 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_cache_backend_libmemcached_ce);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, phalcon_cache_frontend_data_ce);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_this(&_4, this_ptr, SL("_lifetime"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("lifetime"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_5, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&_6, SL("servers"), &servers, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("client"), &client, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("prefix"), &prefix, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("statsKey"), &statsKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_7, _2, _6);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_libmemcached"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	zephir_create_array(_8, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_8, this_ptr);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_STRING(_9, "open", 1);
	zephir_array_fast_append(_8, _9);
	ZEPHIR_INIT_VAR(_10);
	zephir_create_array(_10, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_10, this_ptr);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "close", 1);
	zephir_array_fast_append(_10, _9);
	ZEPHIR_INIT_VAR(_11);
	zephir_create_array(_11, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_11, this_ptr);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "read", 1);
	zephir_array_fast_append(_11, _9);
	ZEPHIR_INIT_VAR(_12);
	zephir_create_array(_12, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_12, this_ptr);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "write", 1);
	zephir_array_fast_append(_12, _9);
	ZEPHIR_INIT_VAR(_13);
	zephir_create_array(_13, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_13, this_ptr);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "destroy", 1);
	zephir_array_fast_append(_13, _9);
	ZEPHIR_INIT_VAR(_14);
	zephir_create_array(_14, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_14, this_ptr);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "gc", 1);
	zephir_array_fast_append(_14, _9);
	ZEPHIR_CALL_FUNCTION(NULL, "session_set_save_handler", NULL, _8, _10, _11, _12, _13, _14);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_session_adapter_libmemcached_ce, this_ptr, "__construct", &_15, options);
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
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, sessionId, _1);
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
	ZEPHIR_CALL_METHOD(NULL, _0, "save", NULL, sessionId, data, _1);
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
	zval *session_id = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &session_id);

	if (!session_id) {
		ZEPHIR_CPY_WRT(session_id, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(session_id);
	}


	if (Z_TYPE_P(session_id) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&session_id, this_ptr, "getid", NULL);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_libmemcached"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "delete", NULL, session_id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, gc) {


	RETURN_BOOL(1);

}

