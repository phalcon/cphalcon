
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Session\Adapter\Memcache
 *
 * This adapter store sessions in memcache
 *
 *<code>
 * $session = new \Phalcon\Session\Adapter\Memcache(array(
 *    'uniqueId' => 'my-private-app'
 *    'host' => '127.0.0.1',
 *    'port' => 11211,
 *    'persistent' => TRUE,
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
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Memcache) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, Memcache, phalcon, session_adapter_memcache, phalcon_session_adapter_ce, phalcon_session_adapter_memcache_method_entry, 0);

	zend_declare_property_null(phalcon_session_adapter_memcache_ce, SL("_memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_session_adapter_memcache_ce, SL("_lifetime"), 8600, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_session_adapter_memcache_ce TSRMLS_CC, 1, phalcon_session_adapterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Session_Adapter_Memcache, getMemcache) {


	RETURN_MEMBER(this_ptr, "_memcache");

}

PHP_METHOD(Phalcon_Session_Adapter_Memcache, getLifetime) {


	RETURN_MEMBER(this_ptr, "_lifetime");

}

/**
 * Phalcon\Session\Adapter\Memcache constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, __construct) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_2, *_6, *_8, *_9, *_10, *_11, *_12;
	zval *options = NULL, *lifetime, *_0 = NULL, *_1, *_3, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(options);
		array_init(options);
	}
	if (!(zephir_array_isset_string(options, SS("host")))) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "127.0.0.1", 1);
		zephir_array_update_string(&options, SL("host"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("port")))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 11211);
		zephir_array_update_string(&options, SL("port"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("persistent")))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 0);
		zephir_array_update_string(&options, SL("persistent"), &_0, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, options, SS("lifetime"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_lifetime"), lifetime TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_0);
	object_init_ex(_0, phalcon_cache_backend_memcache_ce);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_cache_frontend_data_ce);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_this(&_3, this_ptr, SL("_lifetime"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("lifetime"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_4, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_5, _1, options);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_memcache"), _0 TSRMLS_CC);
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
	ZEPHIR_CALL_FUNCTION(NULL, "session_set_save_handler", NULL, _6, _8, _9, _10, _11, _12);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_session_adapter_memcache_ce, this_ptr, "__construct", &_13, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Session_Adapter_Memcache, open) {


	RETURN_BOOL(1);

}

PHP_METHOD(Phalcon_Session_Adapter_Memcache, close) {


	RETURN_BOOL(1);

}

/**
 * {@inheritdoc}
 *
 * @param string sessionId
 * @return mixed
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, read) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
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
PHP_METHOD(Phalcon_Session_Adapter_Memcache, write) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, *data, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId, &data);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
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
PHP_METHOD(Phalcon_Session_Adapter_Memcache, destroy) {

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
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "delete", NULL, session_id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, gc) {


	RETURN_BOOL(1);

}

