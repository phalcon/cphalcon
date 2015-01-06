
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "cache/frontend/data.h"
#include "cache/frontendinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/variables.h"

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
zend_class_entry *phalcon_cache_frontend_data_ce;

PHP_METHOD(Phalcon_Cache_Frontend_Data, __construct);
PHP_METHOD(Phalcon_Cache_Frontend_Data, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_Data, isBuffering);
PHP_METHOD(Phalcon_Cache_Frontend_Data, start);
PHP_METHOD(Phalcon_Cache_Frontend_Data, getContent);
PHP_METHOD(Phalcon_Cache_Frontend_Data, stop);
PHP_METHOD(Phalcon_Cache_Frontend_Data, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_Data, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_data___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_cache_frontend_data_method_entry[] = {
	PHP_ME(Phalcon_Cache_Frontend_Data, __construct, arginfo_phalcon_cache_frontend_data___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Frontend_Data, getLifetime, arginfo_phalcon_cache_frontendinterface_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, isBuffering, arginfo_phalcon_cache_frontendinterface_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, start, arginfo_phalcon_cache_frontendinterface_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, getContent, arginfo_phalcon_cache_frontendinterface_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, stop, arginfo_phalcon_cache_frontendinterface_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, beforeStore, arginfo_phalcon_cache_frontendinterface_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, afterRetrieve, arginfo_phalcon_cache_frontendinterface_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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

	phalcon_fetch_params(0, 0, 1, &frontend_options);
	
	if (frontend_options) {
		phalcon_update_property_this(this_ptr, SL("_frontendOptions"), frontend_options TSRMLS_CC);
	}
}

/**
 * Returns cache lifetime
 *
 * @return int
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, getLifetime){

	zval *options, *lifetime;

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_frontendOptions"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_string_fetch(&lifetime, options, SS("lifetime"))) {
		RETURN_ZVAL(lifetime, 1, 0);
	}
	else {
		RETURN_LONG(1);
	}
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
 * Serializes data before storing them
 *
 * @param mixed $data
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, beforeStore){

	zval *data;

	phalcon_fetch_params(0, 1, 0, &data);
	phalcon_serialize(return_value, &data TSRMLS_CC);
}

/**
 * Unserializes data after retrieval
 *
 * @param mixed $data
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, afterRetrieve){

	zval *data;

	phalcon_fetch_params(0, 1, 0, &data);
	phalcon_unserialize(return_value, data TSRMLS_CC);
}
