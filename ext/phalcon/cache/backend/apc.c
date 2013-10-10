
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
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
 * Phalcon\Cache\Backend\Apc
 *
 * Allows to cache output fragments, PHP data and raw data using an APC backend
 *
 *<code>
 *	//Cache data for 2 days
 *	$frontCache = new Phalcon\Cache\Frontend\Data(array(
 *		'lifetime' => 172800
 *	));
 *
 *  $cache = new Phalcon\Cache\Backend\Apc($frontCache, array(
 *      'prefix' => 'app-data'
 *  ));
 *
 *	//Cache arbitrary data
 *	$cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 *	//Get data
 *	$data = $cache->get('my-data');
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Apc) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Apc, phalcon, cache_backend_apc, phalcon_cache_backend_ce, phalcon_cache_backend_apc_method_entry, 0);

	zend_class_implements(phalcon_cache_backend_apc_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);

	return SUCCESS;

}

/**
 * Returns a cached content
 *
 * @param 	string|long keyName
 * @param   long lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, get) {

	zval *keyName, *lifetime = NULL, *frontend, *prefixedKey, *cachedContent, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		ZEPHIR_CPY_WRT(lifetime, ZEPHIR_GLOBAL(global_null));
	}


	frontend = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_SVV(prefixedKey, "_PHCA", _0, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_INIT_VAR(cachedContent);
	zephir_call_func_p1(cachedContent, "apc_fetch", prefixedKey);
	if (ZEPHIR_IS_FALSE(cachedContent)) {
		RETURN_MM_NULL();
	}
	zephir_call_method_p1(return_value, frontend, "afterretrieve", cachedContent);
	RETURN_MM();

}

/**
 * Stores cached content into the APC backend and stops the frontend
 *
 * @param string|long keyName
 * @param string content
 * @param long lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, save) {

	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer = NULL, *lastKey, *frontend, *cachedContent = NULL, *preparedContent, *ttl = NULL, *isBuffering, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer);

	if (!keyName) {
		ZEPHIR_CPY_WRT(keyName, ZEPHIR_GLOBAL(global_null));
	}
	if (!content) {
		ZEPHIR_CPY_WRT(content, ZEPHIR_GLOBAL(global_null));
	}
	if (!lifetime) {
		ZEPHIR_CPY_WRT(lifetime, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(lifetime);
	if (!stopBuffer) {
		ZEPHIR_CPY_WRT(stopBuffer, ZEPHIR_GLOBAL(global_true));
	}


	ZEPHIR_INIT_VAR(lastKey);
	if ((Z_TYPE_P(keyName) == IS_NULL)) {
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCA", _0, keyName);
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
	if ((Z_TYPE_P(lifetime) == IS_NULL)) {
		ZEPHIR_OBS_NVAR(lifetime);
		zephir_read_property_this(&lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if ((Z_TYPE_P(lifetime) == IS_NULL)) {
			ZEPHIR_INIT_VAR(ttl);
			zephir_call_method(ttl, frontend, "getlifetime");
		} else {
			ZEPHIR_CPY_WRT(ttl, lifetime);
		}
	} else {
		ZEPHIR_CPY_WRT(ttl, lifetime);
	}
	zephir_call_func_p3_noret("apc_store", lastKey, preparedContent, ttl);
	ZEPHIR_INIT_VAR(isBuffering);
	zephir_call_method(isBuffering, frontend, "isbuffering");
	if (ZEPHIR_IS_TRUE(stopBuffer)) {
		zephir_call_method_noret(frontend, "stop");
	}
	if (ZEPHIR_IS_TRUE(isBuffering)) {
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
PHP_METHOD(Phalcon_Cache_Backend_Apc, delete) {

	zval *keyName, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVV(_1, "_PHCA", _0, keyName);
	zephir_call_func_p1(return_value, "apc_delete", _1);
	RETURN_MM();

}

/**
 * Query the existing cached keys
 *
 * @param string prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, queryKeys) {

	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		ZEPHIR_CPY_WRT(prefix, ZEPHIR_GLOBAL(global_null));
	}



}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param  string|long keyName
 * @param  long lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, exists) {

	zval *keyName = NULL, *lifetime = NULL, *lastKey, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName) {
		ZEPHIR_CPY_WRT(keyName, ZEPHIR_GLOBAL(global_null));
	}
	if (!lifetime) {
		ZEPHIR_CPY_WRT(lifetime, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(lastKey);
	if ((Z_TYPE_P(keyName) == IS_NULL)) {
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCA", _0, keyName);
	}
	if (zephir_is_true(lastKey)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func_p1(_1, "apc_exists", lastKey);
		if (!ZEPHIR_IS_FALSE(_1)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

