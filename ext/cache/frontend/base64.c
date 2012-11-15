
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

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Cache\Frontend\Base64
 *
 * Allows to cache data converting/deconverting them to base64.
 *
 * This adapters uses the base64_encode/base64_decode PHP's functions
 *
 *<code>
 *
 * // Cache the files for 2 days using a Base64 frontend
 * $frontCache = new Phalcon\Cache\Frontend\Base64(array(
 *    "lifetime" => 172800
 * ));
 *
 * //Create a MongoDB cache
 * $cache = new Phalcon\Cache\Backend\Mongo($frontCache, array(
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
 *     $cache->save($cacheKey, file_put_contents('tmp-dir/some-image.jpg'));
 * }
 *
 * header('Content-Type: image/jpeg');
 * echo $image;
 *</code>
 */


/**
 * Phalcon\Cache\Frontend\Base64 initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Base64){

	PHALCON_REGISTER_CLASS(Phalcon\\Cache\\Frontend, Base64, cache_frontend_base64, phalcon_cache_frontend_base64_method_entry, 0);

	zend_declare_property_null(phalcon_cache_frontend_base64_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_frontend_base64_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Cache\Frontend\Base64 constructor
 *
 * @param array $frontendOptions
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, __construct){

	zval *frontend_options = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &frontend_options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!frontend_options) {
		PHALCON_INIT_NVAR(frontend_options);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_frontendOptions"), frontend_options TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the cache lifetime
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, getLifetime){

	zval *options, *lifetime;
	int eval_int;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_frontendOptions"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_string(options, SS("lifetime"));
		if (eval_int) {
			PHALCON_INIT_VAR(lifetime);
			phalcon_array_fetch_string(&lifetime, options, SL("lifetime"), PH_NOISY_CC);
	
			RETURN_CCTOR(lifetime);
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_LONG(1);
}

/**
 * Check whether if frontend is buffering output
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, isBuffering){


	RETURN_FALSE;
}

/**
 * Starts output frontend. Actually, does nothing
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, start){


	
}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, getContent){


	RETURN_NULL();
}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, stop){


	
}

/**
 * Serializes data before storing it
 *
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, beforeStore){

	zval *data, *serialized;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(serialized);
	PHALCON_CALL_FUNC_PARAMS_1(serialized, "base64_encode", data);
	
	RETURN_CCTOR(serialized);
}

/**
 * Unserializes data after retrieving it
 *
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Cache_Frontend_Base64, afterRetrieve){

	zval *data, *unserialized;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(unserialized);
	PHALCON_CALL_FUNC_PARAMS_1(unserialized, "base64_decode", data);
	
	RETURN_CCTOR(unserialized);
}

