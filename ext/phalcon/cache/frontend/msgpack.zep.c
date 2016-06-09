
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
#include "kernel/fcall.h"


/**
 * Phalcon\Cache\Frontend\Msgpack
 *
 * Allows to cache native PHP data in a serialized form using msgpack extension
 *
 *<code>
 *
 *	// Cache the files for 2 days using Msgpack frontend
 *	$frontCache = new \Phalcon\Cache\Frontend\Msgpack(array(
 *		"lifetime" => 172800
 *	));
 *
 *	// Create the component that will cache "Msgpack" to a "File" backend
 *	// Set the cache file directory - important to keep the "/" at the end of
 *	// of the value for the folder
 *	$cache = new \Phalcon\Cache\Backend\File($frontCache, array(
 *		"cacheDir" => "../app/cache/"
 *	));
 *
 *	// Try to get cached records
 *	$cacheKey  = 'robots_order_id.cache';
 *	$robots    = $cache->get($cacheKey);
 *	if ($robots === null) {
 *
 *		// $robots is null due to cache expiration or data do not exist
 *		// Make the database call and populate the variable
 *		$robots = Robots::find(array("order" => "id"));
 *
 *		// Store it in the cache
 *		$cache->save($cacheKey, $robots);
 *	}
 *
 *	// Use $robots :)
 *	foreach ($robots as $robot) {
 *		echo $robot->name, "\n";
 *	}
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Msgpack) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Frontend, Msgpack, phalcon, cache_frontend_msgpack, phalcon_cache_frontend_data_ce, phalcon_cache_frontend_msgpack_method_entry, 0);

	zend_class_implements(phalcon_cache_frontend_msgpack_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cache\Frontend\Msgpack constructor
 *
 * @param array frontendOptions
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, __construct) {

	zval *frontendOptions = NULL, frontendOptions_sub, __$null, lifetime;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&frontendOptions_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lifetime);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &frontendOptions);

	if (!frontendOptions) {
		frontendOptions = &frontendOptions_sub;
		frontendOptions = &__$null;
	}


	ZEPHIR_OBS_VAR(&lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, frontendOptions, SL("lifetime"), 0)) {
		if (Z_TYPE_P(&lifetime) != IS_LONG) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "lifetime option should be a integer.", "phalcon/cache/frontend/msgpack.zep", 77);
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the cache lifetime
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, getLifetime) {

	zval options, lifetime;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&lifetime);


	zephir_read_property(&options, this_ptr, SL("_frontendOptions"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&lifetime, &options, SL("lifetime"), 1)) {
			RETURN_CTORW(lifetime);
		}
	}
	RETURN_LONG(1);

}

/**
 * Check whether if frontend is buffering output
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, isBuffering) {

	ZEPHIR_INIT_THIS();


	RETURN_BOOL(0);

}

/**
 * Starts output frontend. Actually, does nothing
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, start) {

	ZEPHIR_INIT_THIS();



}

/**
 * Returns output cached content
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, getContent) {

	ZEPHIR_INIT_THIS();


	RETURN_NULL();

}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, stop) {

	ZEPHIR_INIT_THIS();



}

/**
 * Serializes data before storing them
 *
 * @param mixed data
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, beforeStore) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_RETURN_CALL_FUNCTION("msgpack_pack", NULL, 126, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes data after retrieval
 *
 * @param mixed data
 */
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, afterRetrieve) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_RETURN_CALL_FUNCTION("msgpack_unpack", NULL, 127, data);
	zephir_check_call_status();
	RETURN_MM();

}

