
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

#include "cache/backend.h"
#include "cache/backendinterface.h"
#include "cache/frontendinterface.h"
#include "cache/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"

/**
 * Phalcon\Cache\Backend
 *
 * This class implements common functionality for backend adapters. A backend cache adapter may extend this class
 */
zend_class_entry *phalcon_cache_backend_ce;

PHP_METHOD(Phalcon_Cache_Backend, __construct);
PHP_METHOD(Phalcon_Cache_Backend, start);
PHP_METHOD(Phalcon_Cache_Backend, stop);
PHP_METHOD(Phalcon_Cache_Backend, getFrontend);
PHP_METHOD(Phalcon_Cache_Backend, getOptions);
PHP_METHOD(Phalcon_Cache_Backend, isFresh);
PHP_METHOD(Phalcon_Cache_Backend, isStarted);
PHP_METHOD(Phalcon_Cache_Backend, setLastKey);
PHP_METHOD(Phalcon_Cache_Backend, getLastKey);
PHP_METHOD(Phalcon_Cache_Backend, getLifetime);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_cache_backend_method_entry[] = {
	PHP_ME(Phalcon_Cache_Backend, __construct, arginfo_phalcon_cache_backend___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend, start, arginfo_phalcon_cache_backendinterface_start, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, stop, arginfo_phalcon_cache_backendinterface_stop, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, getFrontend, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, isFresh, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, isStarted, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, setLastKey, arginfo_phalcon_cache_backendinterface_setlastkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, getLastKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, getLifetime, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Cache\Backend initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Backend){

	PHALCON_REGISTER_CLASS(Phalcon\\Cache, Backend, cache_backend, phalcon_cache_backend_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_cache_backend_ce, SL("_frontend"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cache_backend_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cache_backend_ce, SL("_lastKey"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_ce, SL("_lastLifetime"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_cache_backend_ce, SL("_fresh"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_cache_backend_ce, SL("_started"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Cache\Backend constructor
 *
 * @param Phalcon\Cache\FrontendInterface $frontend
 * @param array $options
 */
PHP_METHOD(Phalcon_Cache_Backend, __construct){

	zval *frontend, *options = NULL, *prefix;

	phalcon_fetch_params(0, 1, 1, &frontend, &options);
	
	PHALCON_VERIFY_INTERFACE_EX(frontend, phalcon_cache_frontendinterface_ce, phalcon_cache_exception_ce, 0);

	if (options) {
		/**
		 * A common option is the prefix
		 */
		if (phalcon_array_isset_string_fetch(&prefix, options, SS("prefix"))) {
			phalcon_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
		}

		phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}

	phalcon_update_property_this(this_ptr, SL("_frontend"), frontend TSRMLS_CC);
}

/**
 * Starts a cache. The $keyname allows to identify the created fragment
 *
 * @param int|string $keyName
 * @param   long $lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend, start){

	zval *key_name, *lifetime = NULL, *fresh = NULL;
	zval *frontend;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	if (!lifetime) {
		lifetime = PHALCON_GLOBAL(z_null);
	}
	
	/** 
	 * Get the cache content verifying if it was expired
	 */
	PHALCON_RETURN_CALL_METHOD(this_ptr, "get", key_name, lifetime);
	if (return_value_ptr) {
		return_value = *return_value_ptr;
	}

	if (Z_TYPE_P(return_value) == IS_NULL) {
		fresh = PHALCON_GLOBAL(z_true);
	
		frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD(NULL, frontend, "start");
	} else {
		fresh = PHALCON_GLOBAL(z_false);
	}
	
	phalcon_update_property_this(this_ptr, SL("_fresh"), fresh TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_started"), PHALCON_GLOBAL(z_true) TSRMLS_CC);
	
	/** 
	 * Update the last lifetime to be used in save()
	 */
	if (Z_TYPE_P(lifetime) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_lastLifetime"), lifetime TSRMLS_CC);
	}

	RETURN_MM();
}

/**
 * Stops the frontend without store any cached content
 *
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend, stop){

	zval *stop_buffer = NULL, *frontend;

	phalcon_fetch_params(0, 0, 1, &stop_buffer);
	
	if (!stop_buffer || PHALCON_IS_TRUE(stop_buffer)) {
		PHALCON_MM_GROW();
		frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD(NULL, frontend, "stop");
		PHALCON_MM_RESTORE();
	}

	phalcon_update_property_bool(this_ptr, SL("_started"), 0 TSRMLS_CC);
}

/**
 * Returns front-end instance adapter related to the back-end
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend, getFrontend){


	RETURN_MEMBER(this_ptr, "_frontend");
}

/**
 * Returns the backend options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend, getOptions){


	RETURN_MEMBER(this_ptr, "_options");
}

/**
 * Checks whether the last cache is fresh or cached
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend, isFresh){


	RETURN_MEMBER(this_ptr, "_fresh");
}

/**
 * Checks whether the cache has starting buffering or not
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend, isStarted){


	RETURN_MEMBER(this_ptr, "_started");
}

/**
 * Sets the last key used in the cache
 *
 * @param string $lastKey
 */
PHP_METHOD(Phalcon_Cache_Backend, setLastKey){

	zval *last_key;

	phalcon_fetch_params(0, 1, 0, &last_key);
	
	phalcon_update_property_this(this_ptr, SL("_lastKey"), last_key TSRMLS_CC);
	
}

/**
 * Gets the last key stored by the cache
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Backend, getLastKey){


	RETURN_MEMBER(this_ptr, "_lastKey");
}

/**
 * Gets the last lifetime set
 *
 * @return int
 */
PHP_METHOD(Phalcon_Cache_Backend, getLifetime){


	RETURN_MEMBER(this_ptr, "_lastLifetime");
}
