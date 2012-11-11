
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

/**
 * Phalcon\Cache\Frontend\None
 *
 * Discards any kind of frontend data input. This frontend does not have expiration time or any other options
 *
 *<code>
 * 
 * //Create a None Cache
 * $frontCache = new Phalcon\Cache\Frontend\None();
 *
 * // Create the component that will cache "Data" to a "Memcached" backend
 * // Memcached connection settings
 * $cache = new Phalcon\Cache\Backend\Memcached($frontCache, array(
 *     "host" => "localhost",
 *     "port" => "11211"
 * ));
 *
 * // This Frontend always return the data as it's returned by the backend
 * $cacheKey = 'robots_order_id.cache';
 * $robots    = $cache->get($cacheKey);
 * if ($robots === null) {
 *
 *     // This cache doesn't perform any expiration checking, so the data is always expired
 *     // Make the database call and populate the variable
 *     $robots = Robots::find(array("order" => "id"));
 *
 *     $cache->save($cacheKey, $robots);
 * }
 *
 * // Use $robots :)
 * foreach ($robots as $robot) {
 *    echo $robot->name, "\n";
 * }
 *</code>
 *
 */


/**
 * Phalcon\Cache\Frontend\None initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_None){

	PHALCON_REGISTER_CLASS(Phalcon\\Cache\\Frontend, None, cache_frontend_none, phalcon_cache_frontend_none_method_entry, 0);

	zend_class_implements(phalcon_cache_frontend_none_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Cache\Frontend\None constructor
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, __construct){

	zval *frontend_options = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &frontend_options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!frontend_options) {
		PHALCON_INIT_NVAR(frontend_options);
	}
	
	
	PHALCON_MM_RESTORE();
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
 * Check whether if frontend is buffering output, always false
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, isBuffering){


	RETURN_FALSE;
}

/**
 * Starts output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, start){


	
}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, getContent){


	
}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, stop){


	
}

/**
 * Prepare data to be stored
 *
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, beforeStore){

	zval *data;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		RETURN_NULL();
	}

	
	RETURN_CCTORW(data);
}

/**
 * Prepares data to be retrieved to user
 *
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, afterRetrieve){

	zval *data;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		RETURN_NULL();
	}

	
	RETURN_CCTORW(data);
}

