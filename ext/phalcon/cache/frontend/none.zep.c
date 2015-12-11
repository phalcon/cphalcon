
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
#include "kernel/memory.h"


/**
 * Phalcon\Cache\Frontend\None
 *
 * Discards any kind of frontend data input. This frontend does not have expiration time or any other options
 *
 *<code>
 *<?php
 *
 *	//Create a None Cache
 *	$frontCache = new \Phalcon\Cache\Frontend\None();
 *
 *	// Create the component that will cache "Data" to a "Memcached" backend
 *	// Memcached connection settings
 *	$cache = new \Phalcon\Cache\Backend\Memcache($frontCache, array(
 *		"host" => "localhost",
 *		"port" => "11211"
 *	));
 *
 *	// This Frontend always return the data as it's returned by the backend
 *	$cacheKey = 'robots_order_id.cache';
 *	$robots    = $cache->get($cacheKey);
 *	if ($robots === null) {
 *
 *		// This cache doesn't perform any expiration checking, so the data is always expired
 *		// Make the database call and populate the variable
 *		$robots = Robots::find(array("order" => "id"));
 *
 *		$cache->save($cacheKey, $robots);
 *	}
 *
 *	// Use $robots :)
 *	foreach ($robots as $robot) {
 *		echo $robot->name, "\n";
 *	}
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_None) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cache\\Frontend, None, phalcon, cache_frontend_none, phalcon_cache_frontend_none_method_entry, 0);

	zend_class_implements(phalcon_cache_frontend_none_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);
	return SUCCESS;

}

/**
 * Returns cache lifetime, always one second expiring content
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, getLifetime) {


	RETURN_LONG(1);

}

/**
 * Check whether if frontend is buffering output, always false
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, isBuffering) {


	RETURN_BOOL(0);

}

/**
 * Starts output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, start) {



}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, getContent) {



}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, stop) {



}

/**
 * Prepare data to be stored
 *
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, beforeStore) {

	zval *data;

	zephir_fetch_params(0, 1, 0, &data);



	RETVAL_ZVAL(data, 1, 0);
	return;

}

/**
 * Prepares data to be retrieved to user
 *
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, afterRetrieve) {

	zval *data;

	zephir_fetch_params(0, 1, 0, &data);



	RETVAL_ZVAL(data, 1, 0);
	return;

}

