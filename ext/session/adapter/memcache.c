
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

#include "session/adapter/memcache.h"
#include "session/adapter.h"
#include "session/adapterinterface.h"
#include "session/exception.h"
#include "cache/backend/memcache.h"
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
 * Phalcon\Session\Adapter\Memcache
 *
 * This adapter store sessions in memcache
 *
 *<code>
 * $session = new Phalcon\Session\Adapter\Memcache(array(
 *    'host' => '127.0.0.1',
 *    'port' => 11211,
 *    'lifetime' => 3600,
 *    'persistent' => TRUE,
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
zend_class_entry *phalcon_session_adapter_memcache_ce;

PHP_METHOD(Phalcon_Session_Adapter_Memcache, __construct);
PHP_METHOD(Phalcon_Session_Adapter_Memcache, open);
PHP_METHOD(Phalcon_Session_Adapter_Memcache, close);
PHP_METHOD(Phalcon_Session_Adapter_Memcache, read);
PHP_METHOD(Phalcon_Session_Adapter_Memcache, write);
PHP_METHOD(Phalcon_Session_Adapter_Memcache, destroy);
PHP_METHOD(Phalcon_Session_Adapter_Memcache, gc);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_memcache___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_memcache_read, 0, 0, 1)
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_memcache_write, 0, 0, 2)
	ZEND_ARG_INFO(0, sessionId)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_memcache_destroy, 0, 0, 0)
        ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_session_adapter_memcache_method_entry[] = {
	PHP_ME(Phalcon_Session_Adapter_Memcache, __construct, arginfo_phalcon_session_adapter_memcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Adapter_Memcache, open, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Memcache, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Memcache, read, arginfo_phalcon_session_adapter_memcache_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Memcache, write, arginfo_phalcon_session_adapter_memcache_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Memcache, destroy, arginfo_phalcon_session_adapter_memcache_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Memcache, gc, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Session\Adapter\Memcache initializer
 */
PHALCON_INIT_CLASS(Phalcon_Session_Adapter_Memcache){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, Memcache, session_adapter_memcache, phalcon_session_adapter_ce, phalcon_session_adapter_memcache_method_entry, 0);

	zend_declare_property_null(phalcon_session_adapter_memcache_ce, SL("_lifetime"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_adapter_memcache_ce, SL("_prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_adapter_memcache_ce, SL("_memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_session_adapter_memcache_ce TSRMLS_CC, 1, phalcon_session_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Constructor for Phalcon\Session\Adapter\Memcache
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, __construct){

	zval *options;
	zval *host, *port, *lifetime, *persistent, *prefix;
	zval *frontend_data, *memcache, *option;
	zval *callable;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_session_exception_ce, "The options must be an array");
		return;
	}

	if (!phalcon_array_isset_string_fetch(&host, options, SS("host"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_session_exception_ce, "No session host given in options");
		return;
	}

	if (!phalcon_array_isset_string_fetch(&port, options, SS("port"))) {
		PHALCON_INIT_VAR(port);
		ZVAL_LONG(port, 11211);
	}

	if (!phalcon_array_isset_string_fetch(&lifetime, options, SS("lifetime"))) {
		PHALCON_INIT_VAR(lifetime);
		ZVAL_LONG(lifetime, 8600);
	}

	phalcon_update_property_this(this_ptr, SL("_lifetime"), lifetime TSRMLS_CC);

	if (!phalcon_array_isset_string_fetch(&persistent, options, SS("persistent"))) {
		PHALCON_INIT_VAR(persistent);
		ZVAL_FALSE(persistent);
	}

	if (phalcon_array_isset_string_fetch(&prefix, options, SS("prefix"))) {
		phalcon_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	}

	/* create memcache instance */
	PHALCON_INIT_VAR(option);
	array_init_size(option, 1);

	phalcon_array_append(&option, lifetime, 0);

	PHALCON_INIT_VAR(frontend_data);
	object_init_ex(frontend_data, phalcon_cache_frontend_data_ce);

	PHALCON_CALL_METHOD(NULL, frontend_data, "__construct", option);

	PHALCON_INIT_NVAR(option);
	array_init_size(option, 3);

	phalcon_array_append(&option, host, 0);
	phalcon_array_append(&option, port, 0);
	phalcon_array_append(&option, persistent, 0);

	PHALCON_INIT_VAR(memcache);
	object_init_ex(memcache, phalcon_cache_backend_memcache_ce);

	PHALCON_CALL_METHOD(NULL, memcache, "__construct", frontend_data, option);

	phalcon_update_property_this(this_ptr, SL("_memcache"), memcache TSRMLS_CC);

	PHALCON_INIT_VAR(callable);
	array_init_size(callable, 2);

	/* open */
	phalcon_array_append(&callable, this_ptr, PH_SEPARATE);
	phalcon_array_append_string(&callable, SL("open"), 0);

	if (PS(mod_user_names).names[0] != NULL) {
			zval_ptr_dtor(&PS(mod_user_names).names[0]);
	}
	PS(mod_user_names).names[0] = callable;

	/* close */
	phalcon_array_update_long_string(&callable, 1, SL("close"), 0);

	if (PS(mod_user_names).names[1] != NULL) {
			zval_ptr_dtor(&PS(mod_user_names).names[1]);
	}
	PS(mod_user_names).names[1] = callable;

	/* read */
	phalcon_array_update_long_string(&callable, 1, SL("read"), 0);

	if (PS(mod_user_names).names[2] != NULL) {
			zval_ptr_dtor(&PS(mod_user_names).names[2]);
	}
	PS(mod_user_names).names[2] = callable;

	/* write */
	phalcon_array_update_long_string(&callable, 1, SL("write"), 0);

	if (PS(mod_user_names).names[3] != NULL) {
			zval_ptr_dtor(&PS(mod_user_names).names[3]);
	}
	PS(mod_user_names).names[3] = callable;

	/* destroy */
	phalcon_array_update_long_string(&callable, 1, SL("destroy"), 0);

	if (PS(mod_user_names).names[4] != NULL) {
			zval_ptr_dtor(&PS(mod_user_names).names[4]);
	}
	PS(mod_user_names).names[4] = callable;

	/* gc */
	phalcon_array_update_long_string(&callable, 1, SL("gc"), 0);

	if (PS(mod_user_names).names[5] != NULL) {
			zval_ptr_dtor(&PS(mod_user_names).names[5]);
	}
	PS(mod_user_names).names[5] = callable;

	PHALCON_CALL_PARENT(NULL, phalcon_session_adapter_memcache_ce, this_ptr, "__construct", options);
	
	PHALCON_MM_RESTORE();
}

/**
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, open){

	RETURN_TRUE;
}

/**
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, close){

	RETURN_TRUE;
}

/**
 *
 * @param string $sessionId
 * @return mixed
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, read){

	zval *sid;
	zval *lifetime, *prefix, *real_sid, *memcache;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &sid);

	lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY TSRMLS_CC);
	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(real_sid);
	PHALCON_CONCAT_VV(real_sid, prefix, sid)

	PHALCON_RETURN_CALL_METHOD(memcache, "get", real_sid, lifetime);

	RETURN_MM();
}

/**
 *
 * @param string $sessionId
 * @param string $data
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, write){

	zval *sid, *data;
	zval *lifetime, *prefix, *real_sid, *memcache;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &sid, &data);

	lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY TSRMLS_CC);
	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(real_sid);
	PHALCON_CONCAT_VV(real_sid, prefix, sid)

	PHALCON_RETURN_CALL_METHOD(memcache, "save", real_sid, data, lifetime);

	RETURN_MM();
}

/**
 *
 * @param string $session_id optional, session id
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, destroy){

	zval *sid = NULL;
	zval *prefix, *real_sid, *memcache;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &sid);

	if (!sid) {
		PHALCON_INIT_VAR(sid);
		PHALCON_CALL_SELF(&sid, "getid");
	}

	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(real_sid);
	PHALCON_CONCAT_VV(real_sid, prefix, sid)

	PHALCON_RETURN_CALL_METHOD(memcache, "delete", real_sid);

	RETURN_MM();
}

/**
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, gc){

}

