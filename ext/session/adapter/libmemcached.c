
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "session/adapter/libmemcached.h"
#include "session/adapter.h"
#include "session/adapterinterface.h"
#include "session/exception.h"
#include "cache/backend/libmemcached.h"
#include "cache/frontend/data.h"

#ifdef PHALCON_USE_PHP_SESSION
#include <ext/session/php_session.h>
#endif

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/object.h"

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
zend_class_entry *phalcon_session_adapter_libmemcached_ce;

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, __construct);
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, open);
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, close);
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, read);
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, write);
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, destroy);
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, gc);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_libmemcached___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_libmemcached_read, 0, 0, 1)
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_libmemcached_write, 0, 0, 2)
	ZEND_ARG_INFO(0, sessionId)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_libmemcached_destroy, 0, 0, 0)
        ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_session_adapter_libmemcached_method_entry[] = {
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, __construct, arginfo_phalcon_session_adapter_libmemcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, open, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, read, arginfo_phalcon_session_adapter_libmemcached_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, write, arginfo_phalcon_session_adapter_libmemcached_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, destroy, arginfo_phalcon_session_adapter_libmemcached_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, gc, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Session\Adapter\Libmemcached initializer
 */
PHALCON_INIT_CLASS(Phalcon_Session_Adapter_Libmemcached){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, Libmemcached, session_adapter_libmemcached, phalcon_session_adapter_ce, phalcon_session_adapter_libmemcached_method_entry, 0);

	zend_declare_property_null(phalcon_session_adapter_libmemcached_ce, SL("_lifetime"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_adapter_libmemcached_ce, SL("_libmemcached"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_session_adapter_libmemcached_ce TSRMLS_CC, 1, phalcon_session_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Constructor for Phalcon\Session\Adapter\Libmemcached
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, __construct){

	zval *options;
	zval *servers, *client, *lifetime, *prefix;
	zval *frontend_data, *libmemcached, *option;
	zval *callable_open , *callable_close , *callable_read , *callable_write , *callable_destroy , *callable_gc;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_session_exception_ce, "The options must be an array");
		return;
	}

	if (!phalcon_array_isset_string_fetch(&servers, options, SS("servers"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_session_exception_ce, "No servers given in options");
		return;
	}

	if (!phalcon_array_isset_string_fetch(&client, options, SS("client"))) {
		client = NULL;
	}

	if (!phalcon_array_isset_string_fetch(&lifetime, options, SS("lifetime"))) {
		PHALCON_INIT_VAR(lifetime);
		ZVAL_LONG(lifetime, 8600);
	}

	phalcon_update_property_this(this_ptr, SL("_lifetime"), lifetime TSRMLS_CC);

	if (!phalcon_array_isset_string_fetch(&prefix, options, SS("prefix"))) {
		PHALCON_INIT_VAR(prefix);
                ZVAL_EMPTY_STRING(prefix);
	}

	/* create libmemcached instance */
	PHALCON_INIT_VAR(option);
	array_init_size(option, 1);

	phalcon_array_update_string(&option, SL("lifetime"), lifetime, PH_COPY);

	PHALCON_INIT_VAR(frontend_data);
	object_init_ex(frontend_data, phalcon_cache_frontend_data_ce);

	PHALCON_CALL_METHOD(NULL, frontend_data, "__construct", option);

	PHALCON_INIT_NVAR(option);
	array_init(option);

	phalcon_array_update_string(&option, SL("servers"), servers, PH_COPY);
	if (client) {
		phalcon_array_update_string(&option, SL("client"), client, PH_COPY);
	}
	phalcon_array_update_string(&option, SL("prefix"), prefix, PH_COPY);

	PHALCON_INIT_VAR(libmemcached);
	object_init_ex(libmemcached, phalcon_cache_backend_libmemcached_ce);

	PHALCON_CALL_METHOD(NULL, libmemcached, "__construct", frontend_data, option);

	phalcon_update_property_this(this_ptr, SL("_libmemcached"), libmemcached TSRMLS_CC);

	/* open callback */
	PHALCON_INIT_VAR(callable_open);
	array_init_size(callable_open, 2);
	phalcon_array_append(&callable_open, this_ptr, 0);
	phalcon_array_append_string(&callable_open, SL("open"), 0);

	/* close callback */
	PHALCON_INIT_VAR(callable_close);
	array_init_size(callable_close, 2);
	phalcon_array_append(&callable_close, this_ptr, 0);
	phalcon_array_append_string(&callable_close, SL("close"), 0);

	/* read callback */
	PHALCON_INIT_VAR(callable_read);
	array_init_size(callable_read, 2);
	phalcon_array_append(&callable_read, this_ptr, 0);
	phalcon_array_append_string(&callable_read, SL("read"), 0);

	/* write callback */
	PHALCON_INIT_VAR(callable_write);
	array_init_size(callable_write, 2);
	phalcon_array_append(&callable_write, this_ptr, 0);
	phalcon_array_append_string(&callable_write, SL("write"), 0);

	/* destroy callback */
	PHALCON_INIT_VAR(callable_destroy);
	array_init_size(callable_destroy, 2);
	phalcon_array_append(&callable_destroy, this_ptr, 0);
	phalcon_array_append_string(&callable_destroy, SL("destroy"), 0);

	/* gc callback */
	PHALCON_INIT_VAR(callable_gc);
	array_init_size(callable_gc, 2);
	phalcon_array_append(&callable_gc, this_ptr, 0);
	phalcon_array_append_string(&callable_gc, SL("gc"), 0);

	PHALCON_CALL_FUNCTION(NULL, "session_set_save_handler", callable_open, callable_close, callable_read, callable_write, callable_destroy, callable_gc);

	PHALCON_CALL_PARENT(NULL, phalcon_session_adapter_libmemcached_ce, this_ptr, "__construct", options);
	
	PHALCON_MM_RESTORE();
}

/**
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, open){

	RETURN_TRUE;
}

/**
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, close){

	RETURN_TRUE;
}

/**
 *
 * @param string $sessionId
 * @return mixed
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, read){

	zval *sid;
	zval *lifetime, *libmemcached;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &sid);

	lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY TSRMLS_CC);
	libmemcached = phalcon_fetch_nproperty_this(this_ptr, SL("_libmemcached"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(libmemcached) == IS_OBJECT) {
		PHALCON_RETURN_CALL_METHOD(libmemcached, "get", sid, lifetime);

		RETURN_MM();
	} else {
		RETURN_MM_FALSE;
	}
}

/**
 *
 * @param string $sessionId
 * @param string $data
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, write){

	zval *sid, *data;
	zval *lifetime, *libmemcached;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &sid, &data);

	lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY TSRMLS_CC);
	libmemcached = phalcon_fetch_nproperty_this(this_ptr, SL("_libmemcached"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(libmemcached) == IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, libmemcached, "save", sid, data, lifetime);	
	}

	PHALCON_MM_RESTORE();
}

/**
 *
 * @param string $session_id optional, session id
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, destroy){

	zval *sid = NULL;
	zval *libmemcached;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &sid);

	if (!sid) {
		PHALCON_INIT_VAR(sid);
		PHALCON_CALL_SELF(&sid, "getid");
	}

	libmemcached = phalcon_fetch_nproperty_this(this_ptr, SL("_libmemcached"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(libmemcached) == IS_OBJECT) {
		PHALCON_RETURN_CALL_METHOD(libmemcached, "delete", sid);

		RETURN_MM();
	} else {
		RETURN_MM_FALSE;
	}
}

/**
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, gc){

	RETURN_TRUE;
}

