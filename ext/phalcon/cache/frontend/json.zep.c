
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Cache\Frontend\Json
 *
 * Allows to cache data converting/deconverting them to JSON.
 *
 * This adapter uses the json_encode/json_decode PHP's functions
 *
 * As the data is encoded in JSON other systems accessing the same backend could
 * process them
 *
 *<code>
 *<?php
 *
 * // Cache the data for 2 days
 * $frontCache = new \Phalcon\Cache\Frontend\Json(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * // Create the Cache setting memcached connection options
 * $cache = new \Phalcon\Cache\Backend\Memcache(
 *     $frontCache,
 *     [
 *         "host"       => "localhost",
 *         "port"       => 11211,
 *         "persistent" => false,
 *     ]
 * );
 *
 * // Cache arbitrary data
 * $cache->save("my-data", [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get("my-data");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Json) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cache\\Frontend, Json, phalcon, cache_frontend_json, phalcon_cache_frontend_json_method_entry, 0);

	zend_declare_property_null(phalcon_cache_frontend_json_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_frontend_json_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cache\Frontend\Base64 constructor
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, __construct) {

	zval *frontendOptions_param = NULL;
	zval frontendOptions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&frontendOptions);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &frontendOptions_param);

	if (!frontendOptions_param) {
		ZEPHIR_INIT_VAR(&frontendOptions);
		array_init(&frontendOptions);
	} else {
		zephir_get_arrval(&frontendOptions, frontendOptions_param);
	}


	zephir_update_property_zval(this_ptr, SL("_frontendOptions"), &frontendOptions);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the cache lifetime
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, getLifetime) {

	zval options, lifetime;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&lifetime);


	zephir_read_property(&options, this_ptr, SL("_frontendOptions"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&lifetime, &options, SL("lifetime"), 1)) {
			RETURN_CTORW(&lifetime);
		}
	}
	RETURN_LONG(1);

}

/**
 * Check whether if frontend is buffering output
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, isBuffering) {

	zval *this_ptr = getThis();


	RETURN_BOOL(0);

}

/**
 * Starts output frontend. Actually, does nothing
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, start) {

	zval *this_ptr = getThis();



}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, getContent) {

	zval *this_ptr = getThis();


	RETURN_NULL();

}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, stop) {

	zval *this_ptr = getThis();



}

/**
 * Serializes data before storing them
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, beforeStore) {

	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);

	zephir_fetch_params(0, 1, 0, &data);



	zephir_json_encode(return_value, data, 0 );
	return;

}

/**
 * Unserializes data after retrieval
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, afterRetrieve) {

	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);

	zephir_fetch_params(0, 1, 0, &data);



	zephir_json_decode(return_value, data, 0 );
	return;

}

