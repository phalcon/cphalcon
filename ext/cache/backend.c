
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"

/**
 * Phalcon\Cache\Backend
 *
 * This class implements common functionality for backend adapters. A backend cache adapter may extend this class
 */


/**
 * Phalcon\Cache\Backend initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Backend){

	PHALCON_REGISTER_CLASS(Phalcon\\Cache, Backend, cache_backend, phalcon_cache_backend_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_cache_backend_ce, SL("_frontend"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cache_backend_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cache_backend_ce, SL("_lastKey"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_cache_backend_ce, SL("_fresh"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_cache_backend_ce, SL("_started"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

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

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &frontend, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
	}
	
	if (Z_TYPE_P(frontend) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Frontend must be an Object");
		return;
	}
	
	/** 
	 * A common option is the prefix
	 */
	if (phalcon_array_isset_string(options, SS("prefix"))) {
		PHALCON_OBS_VAR(prefix);
		phalcon_array_fetch_string(&prefix, options, SL("prefix"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_frontend"), frontend TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_options"), options TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Starts a cache. The $keyname allows to identify the created fragment
 *
 * @param int|string $keyName
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend, start){

	zval *key_name, *lifetime = NULL, *existing_cache, *fresh = NULL;
	zval *frontend;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &key_name, &lifetime) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!lifetime) {
		PHALCON_INIT_NVAR(lifetime);
	}
	
	/** 
	 * Get the cache content verifying if it was expired
	 */
	PHALCON_INIT_VAR(existing_cache);
	PHALCON_CALL_METHOD_PARAMS_2(existing_cache, this_ptr, "get", key_name, lifetime);
	if (Z_TYPE_P(existing_cache) == IS_NULL) {
		PHALCON_INIT_VAR(fresh);
		ZVAL_BOOL(fresh, 1);
	
		PHALCON_OBS_VAR(frontend);
		phalcon_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_NORETURN(frontend, "start");
	} else {
		PHALCON_INIT_NVAR(fresh);
		ZVAL_BOOL(fresh, 0);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_fresh"), fresh TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_started"), 1 TSRMLS_CC);
	
	RETURN_CCTOR(existing_cache);
}

/**
 * Stops the frontend without store any cached content
 *
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend, stop){

	zval *stop_buffer = NULL, *frontend;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &stop_buffer) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!stop_buffer) {
		PHALCON_INIT_NVAR(stop_buffer);
		ZVAL_BOOL(stop_buffer, 1);
	}
	
	PHALCON_OBS_VAR(frontend);
	phalcon_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (PHALCON_IS_TRUE(stop_buffer)) {
		PHALCON_CALL_METHOD_NORETURN(frontend, "stop");
	}
	
	phalcon_update_property_bool(this_ptr, SL("_started"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &last_key) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_lastKey"), last_key TSRMLS_CC);
	
}

/**
 * Gets the last key stored by the cache
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Backend, getLastKey){


	RETURN_MEMBER(this_ptr, "_lastKey");
}

