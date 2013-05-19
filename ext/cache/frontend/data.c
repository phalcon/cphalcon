
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
 * Phalcon\Cache\Frontend\Data
 *
 * Allows to cache native PHP data in a serialized form
 *
 *<code>
 *
 *	// Cache the files for 2 days using a Data frontend
 *	$frontCache = new Phalcon\Cache\Frontend\Data(array(
 *		"lifetime" => 172800
 *	));
 *
 *	// Create the component that will cache "Data" to a "File" backend
 *	// Set the cache file directory - important to keep the "/" at the end of
 *	// of the value for the folder
 *	$cache = new Phalcon\Cache\Backend\File($frontCache, array(
 *		"cacheDir" => "../app/cache/"
 *	));
 *
 *	// Try to get cached records
 *	$cacheKey = 'robots_order_id.cache';
 *	$robots    = $cache->get($cacheKey);
 *	if ($robots === null) {
 *
 *		// $robots is null due to cache expiration or data does not exist
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


/**
 * Phalcon\Cache\Frontend\Data initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Data){

	PHALCON_REGISTER_CLASS(Phalcon\\Cache\\Frontend, Data, cache_frontend_data, phalcon_cache_frontend_data_method_entry, 0);

	zend_declare_property_null(phalcon_cache_frontend_data_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_frontend_data_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Cache\Frontend\Data constructor
 *
 * @param array $frontendOptions
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, __construct){

	zval *frontend_options = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &frontend_options);
	
	if (!frontend_options) {
		PHALCON_INIT_VAR(frontend_options);
	}
	
	phalcon_update_property_this(this_ptr, SL("_frontendOptions"), frontend_options TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns cache lifetime
 *
 * @return int
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, getLifetime){

	zval *options, *lifetime;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_frontendOptions"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		if (phalcon_array_isset_string(options, SS("lifetime"))) {
			PHALCON_OBS_VAR(lifetime);
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
PHP_METHOD(Phalcon_Cache_Frontend_Data, isBuffering){


	RETURN_FALSE;
}

/**
 * Starts output frontend. Actually, does nothing
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, start){


	
}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, getContent){


	RETURN_NULL();
}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, stop){


	
}

/**
 * Serializes data before storing it
 *
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, beforeStore){

	zval *data, *serialized;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);
	
	PHALCON_INIT_VAR(serialized);
	phalcon_call_func_p1(serialized, "serialize", data);
	RETURN_CCTOR(serialized);
}

/**
 * Unserializes data after retrieving it
 *
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, afterRetrieve){

	zval *data, *unserialized;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);
	
	PHALCON_INIT_VAR(unserialized);
	phalcon_call_func_p1(unserialized, "unserialize", data);
	RETURN_CCTOR(unserialized);
}

