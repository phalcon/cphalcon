
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

/**
 * Phalcon\Cache\Frontend\None
 *
 * Discards any kind of frontend data input. This frontend does not have expiration time or any other options
 *
 *<code>
 *
 *	//Create a None Cache
 *	$frontCache = new Phalcon\Cache\Frontend\None();
 *
 *	// Create the component that will cache "Data" to a "Memcached" backend
 *	// Memcached connection settings
 *	$cache = new Phalcon\Cache\Backend\Memcache($frontCache, array(
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


/**
 * Phalcon\Cache\Frontend\None initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_None){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Frontend, None, cache_frontend_none, "phalcon\\cache\\frontend\\data", phalcon_cache_frontend_none_method_entry, 0);

	zend_class_implements(phalcon_cache_frontend_none_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);

	return SUCCESS;
}

/**
 * Returns cache lifetime, always one second expiring content
 *
 * @return int
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, getLifetime){


	RETURN_LONG(1);
}

/**
 * Prepare data to be stored
 *
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, beforeStore){

	if (return_value_ptr) {
		zval_ptr_dtor(return_value_ptr);
		phalcon_fetch_params(0, 1, 0, return_value_ptr);
		Z_ADDREF_PP(return_value_ptr);
	}
	else {
		zval *data;
		phalcon_fetch_params(0, 1, 0, &data);
		RETURN_CCTORW(data);
	}
}

/**
 * Prepares data to be retrieved to user
 *
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, afterRetrieve){

	if (return_value_ptr) {
		zval_ptr_dtor(return_value_ptr);
		phalcon_fetch_params(0, 1, 0, return_value_ptr);
		Z_ADDREF_PP(return_value_ptr);
	}
	else {
		zval *data;
		phalcon_fetch_params(0, 1, 0, &data);
		RETURN_CCTORW(data);
	}
}

