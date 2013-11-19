
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
 * Phalcon\Cache\Frontend\Data
 *
 * Allows to cache native PHP data in a serialized form
 *
 *<code>
 *<?php
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
ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Data) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cache\\Frontend, Data, phalcon, cache_frontend_data, phalcon_cache_frontend_data_method_entry, 0);

	zend_declare_property_null(phalcon_cache_frontend_data_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_frontend_data_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);

	return SUCCESS;

}

/**
 * Phalcon\Cache\Frontend\Data constructor
 *
 * @param array frontendOptions
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, __construct) {

	zval *frontendOptions = NULL;

	zephir_fetch_params(0, 0, 1, &frontendOptions);

	if (!frontendOptions || Z_TYPE_P(frontendOptions) == IS_NULL) {
		frontendOptions = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_frontendOptions"), frontendOptions TSRMLS_CC);

}

/**
 * Returns the cache lifetime
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, getLifetime) {

	zval *options, *lifetime;


	options = zephir_fetch_nproperty_this(this_ptr, SL("_frontendOptions"), PH_NOISY_CC);
	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		if (zephir_array_isset_string_fetch(&lifetime, options, SS("lifetime"), 1 TSRMLS_CC)) {
			RETURN_CTORW(lifetime);
		}
	}
	RETURN_LONG(1);

}

/**
 * Check whether if frontend is buffering output
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, isBuffering) {


	RETURN_BOOL(0);

}

/**
 * Starts output frontend. Actually, does nothing
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, start) {



}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, getContent) {


	RETURN_NULL();

}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, stop) {



}

/**
 * Serializes data before storing them
 *
 * @param mixed data
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, beforeStore) {

	zval *data;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	zephir_call_func_p1(return_value, "serialize", data);
	RETURN_MM();

}

/**
 * Unserializes data after retrieval
 *
 * @param mixed data
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Frontend_Data, afterRetrieve) {

	zval *data;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	zephir_call_func_p1(return_value, "unserialize", data);
	RETURN_MM();

}

