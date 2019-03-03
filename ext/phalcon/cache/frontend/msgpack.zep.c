
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
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
 * Phalcon\Cache\Frontend\Msgpack
 *
 * Allows to cache native PHP data in a serialized form using msgpack extension
 * This adapter uses a Msgpack frontend to store the cached content and requires msgpack extension.
 *
 * @link https://github.com/msgpack/msgpack-php
 *
 *<code>
 * use Phalcon\Cache\Backend\File;
 * use Phalcon\Cache\Frontend\Msgpack;
 *
 * // Cache the files for 2 days using Msgpack frontend
 * $frontCache = new Msgpack(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * // Create the component that will cache "Msgpack" to a "File" backend
 * // Set the cache file directory - important to keep the "/" at the end of
 * // of the value for the folder
 * $cache = new File(
 *     $frontCache,
 *     [
 *         "cacheDir" => "../app/cache/",
 *     ]
 * );
 *
 * $cacheKey = "robots_order_id.cache";
 *
 * // Try to get cached records
 * $robots = $cache->get($cacheKey);
 *
 * if ($robots === null) {
 *     // $robots is null due to cache expiration or data do not exist
 *     // Make the database call and populate the variable
 *     $robots = Robots::find(
 *         [
 *             "order" => "id",
 *         ]
 *     );
 *
 *     // Store it in the cache
 *     $cache->save($cacheKey, $robots);
 * }
 *
 * // Use $robots
 * foreach ($robots as $robot) {
 *     echo $robot->name, "\n";
 * }
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Msgpack) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Frontend, Msgpack, phalcon, cache_frontend_msgpack, phalcon_cache_frontend_data_ce, phalcon_cache_frontend_msgpack_method_entry, 0);

	zend_class_implements(phalcon_cache_frontend_msgpack_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cache\Frontend\Msgpack constructor
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, __construct) {

	zval *frontendOptions_param = NULL, lifetime;
	zval frontendOptions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&frontendOptions);
	ZVAL_UNDEF(&lifetime);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &frontendOptions_param);

	if (!frontendOptions_param) {
		ZEPHIR_INIT_VAR(&frontendOptions);
		array_init(&frontendOptions);
	} else {
		zephir_get_arrval(&frontendOptions, frontendOptions_param);
	}


	ZEPHIR_OBS_VAR(&lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, &frontendOptions, SL("lifetime"), 0)) {
		if (Z_TYPE_P(&lifetime) != IS_LONG) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Option 'lifetime' must be an integer", "phalcon/cache/frontend/msgpack.zep", 80);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, SL("_frontendOptions"), &frontendOptions);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the cache lifetime
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, getLifetime) {

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
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, isBuffering) {

	zval *this_ptr = getThis();


	RETURN_BOOL(0);

}

/**
 * Starts output frontend. Actually, does nothing
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, start) {

	zval *this_ptr = getThis();



}

/**
 * Returns output cached content
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, getContent) {

	zval *this_ptr = getThis();


	RETURN_NULL();

}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, stop) {

	zval *this_ptr = getThis();



}

/**
 * Serializes data before storing them
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, beforeStore) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_RETURN_CALL_FUNCTION("msgpack_pack", NULL, 112, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes data after retrieval
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, afterRetrieve) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (zephir_is_numeric(data)) {
		RETVAL_ZVAL(data, 1, 0);
		RETURN_MM();
	}
	if (ZEPHIR_IS_EMPTY(data)) {
		RETVAL_ZVAL(data, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("msgpack_unpack", NULL, 113, data);
	zephir_check_call_status();
	RETURN_MM();

}

