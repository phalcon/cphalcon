
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Cache\Backend\Memory
 *
 * Stores content in memory. Data is lost when the request is finished
 *
 *<code>
 *	//Cache data
 *	$frontCache = new Phalcon\Cache\Frontend\Data();
 *
 *  $cache = new Phalcon\Cache\Backend\Memory($frontCache);
 *
 *	//Cache arbitrary data
 *	$cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 *	//Get data
 *	$data = $cache->get('my-data');
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Memory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Memory, phalcon, cache_backend_memory, phalcon_cache_backend_ce, phalcon_cache_backend_memory_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_memory_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_memory_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);

	return SUCCESS;

}

/**
 * Returns a cached content
 *
 * @param 	string keyName
 * @param   long lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, get) {

	zval *keyName, *lifetime = NULL, *lastKey, *cachedContent, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(lastKey);
	if ((Z_TYPE_P(keyName) == IS_NULL)) {
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_VV(lastKey, _0, keyName);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&cachedContent, _0, lastKey, 1 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	if ((Z_TYPE_P(cachedContent) == IS_NULL)) {
		RETURN_MM_NULL();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	zephir_call_method_p1(return_value, _0, "afterretrieve", cachedContent);
	RETURN_MM();

}

/**
 * Stores cached content into the backend and stops the frontend
 *
 * @param string keyName
 * @param string content
 * @param long lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, save) {

	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer = NULL, *lastKey, *frontend, *cachedContent = NULL, *preparedContent, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!content) {
		content = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}
	if (!stopBuffer) {
		stopBuffer = ZEPHIR_GLOBAL(global_true);
	}


	ZEPHIR_INIT_VAR(lastKey);
	if ((Z_TYPE_P(keyName) == IS_NULL)) {
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_VV(lastKey, _0, keyName);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	frontend = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	if ((Z_TYPE_P(content) == IS_NULL)) {
		ZEPHIR_INIT_VAR(cachedContent);
		zephir_call_method(cachedContent, frontend, "getcontent");
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	ZEPHIR_INIT_VAR(preparedContent);
	zephir_call_method_p1(preparedContent, frontend, "beforestore", cachedContent);
	zephir_update_property_array(this_ptr, SL("_data"), lastKey, preparedContent TSRMLS_CC);
	if (ZEPHIR_IS_TRUE(stopBuffer)) {
		zephir_call_method_noret(frontend, "stop");
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, frontend, "isbuffering");
	if (ZEPHIR_IS_TRUE(_1)) {
		zend_print_zval(cachedContent, 0);
	}
	zephir_update_property_this(this_ptr, SL("_started"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Deletes a value from the cache by its key
 *
 * @param string keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, delete) {

	zval *keyName, *key, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(key);
	ZEPHIR_CONCAT_VV(key, _0, keyName);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	if (zephir_array_isset(_1, key)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Query the existing cached keys
 *
 * @param string|int prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, queryKeys) {

	zval *prefix = NULL;

	zephir_fetch_params(0, 0, 1, &prefix);

	if (!prefix) {
		prefix = ZEPHIR_GLOBAL(global_null);
	}



}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param  string|int keyName
 * @param  long lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, exists) {

	zval *keyName = NULL, *lifetime = NULL, *lastKey, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(lastKey);
	if ((Z_TYPE_P(keyName) == IS_NULL)) {
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_VV(lastKey, _0, keyName);
	}
	if (zephir_is_true(lastKey)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
		if (zephir_array_isset(_0, lastKey)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

