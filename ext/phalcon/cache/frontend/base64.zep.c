
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
 * $frontCache = new \Phalcon\Cache\Frontend\Base64(array(
 *    "lifetime" => 172800
 * ));
 *
 * //Create a MongoDB cache
 * $cache = new \Phalcon\Cache\Backend\Mongo($frontCache, array(
 *		'server' => "mongodb://localhost",
 *      'db' => 'caches',
 *		'collection' => 'images'
 * ));
 *
 * // Try to get cached image
 * $cacheKey = 'some-image.jpg.cache';
 * $image    = $cache->get($cacheKey);
 * if ($image === null) {
 *
 *     // Store the image in the cache
 *     $cache->save($cacheKey, file_get_contents('tmp-dir/some-image.jpg'));
 * }
 *
 * header('Content-Type: image/jpeg');
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
 *
 * @param array frontendOptions
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, __construct) {

	zval *frontendOptions = NULL;

	zephir_fetch_params(0, 0, 1, &frontendOptions);

	if (!frontendOptions) {
		frontendOptions = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_frontendOptions"), frontendOptions TSRMLS_CC);

}

/**
 * Returns the cache lifetime
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, getLifetime) {

	zval *options, *lifetime;


	options = zephir_fetch_nproperty_this(this_ptr, SL("_frontendOptions"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&lifetime, options, SS("lifetime"), 1 TSRMLS_CC)) {
			RETURN_CTORW(lifetime);
		}
	}
	RETURN_LONG(1);

}

/**
 * Check whether if frontend is buffering output
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, isBuffering) {


	RETURN_BOOL(0);

}

/**
 * Starts output frontend. Actually, does nothing in this adapter
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, start) {



}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, getContent) {


	RETURN_NULL();

}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, stop) {



}

/**
 * Serializes data before storing them
 *
 * @param mixed data
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, beforeStore) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 45, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes data after retrieval
 *
 * @param mixed data
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, afterRetrieve) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_RETURN_CALL_FUNCTION("base64_decode", NULL, 46, data);
	zephir_check_call_status();
	RETURN_MM();

}

