
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
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Cache\Frontend\Base64
 *
 * Allows to cache data converting/deconverting them to base64.
 *
 * This adapter uses the base64_encode/base64_decode PHP's functions
 *
 *<code>
 *<?php
 *
 * // Cache the files for 2 days using a Base64 frontend
 * $frontCache = new \Phalcon\Cache\Frontend\Base64(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * //Create a MongoDB cache
 * $cache = new \Phalcon\Cache\Backend\Mongo(
 *     $frontCache,
 *     [
 *         "server"     => "mongodb://localhost",
 *         "db"         => "caches",
 *         "collection" => "images",
 *     ]
 * );
 *
 * $cacheKey = "some-image.jpg.cache";
 *
 * // Try to get cached image
 * $image = $cache->get($cacheKey);
 *
 * if ($image === null) {
 *     // Store the image in the cache
 *     $cache->save(
 *         $cacheKey,
 *         file_get_contents("tmp-dir/some-image.jpg")
 *     );
 * }
 *
 * header("Content-Type: image/jpeg");
 *
 * echo $image;
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Base64) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cache\\Frontend, Base64, phalcon, cache_frontend_base64, phalcon_cache_frontend_base64_method_entry, 0);

	zend_declare_property_null(phalcon_cache_frontend_base64_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_frontend_base64_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cache\Frontend\Base64 constructor
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, __construct) {

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
PHP_METHOD(Phalcon_Cache_Frontend_Base64, getLifetime) {

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
PHP_METHOD(Phalcon_Cache_Frontend_Base64, isBuffering) {

	zval *this_ptr = getThis();


	RETURN_BOOL(0);

}

/**
 * Starts output frontend. Actually, does nothing in this adapter
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, start) {

	zval *this_ptr = getThis();



}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, getContent) {

	zval *this_ptr = getThis();


	RETURN_NULL();

}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, stop) {

	zval *this_ptr = getThis();



}

/**
 * Serializes data before storing them
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, beforeStore) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 108, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes data after retrieval
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, afterRetrieve) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_RETURN_CALL_FUNCTION("base64_decode", NULL, 109, data);
	zephir_check_call_status();
	RETURN_MM();

}

