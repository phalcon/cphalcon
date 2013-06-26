
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
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
#include "kernel/variables.h"

/**
 * Phalcon\Cache\Frontend\Igbinary
 *
 * Allows to cache native PHP data in a serialized form using igbinary extension
 *
 *<code>
 *
 *	// Cache the files for 2 days using Igbinary frontend
 *	$frontCache = new Phalcon\Cache\Frontend\Igbinary(array(
 *		"lifetime" => 172800
 *	));
 *
 *	// Create the component that will cache "Igbinary" to a "File" backend
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


/**
 * Phalcon\Cache\Frontend\Igbinary initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Igbinary){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Frontend, Igbinary, cache_frontend_igbinary, "phalcon\\cache\\frontend\\data", phalcon_cache_frontend_igbinary_method_entry, 0);

	zend_declare_property_null(phalcon_cache_frontend_igbinary_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_frontend_igbinary_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);

	return SUCCESS;
}

/**
 * Serializes data before storing them
 *
 * @param mixed $data
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, beforeStore){

	zval *data, *serialized;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);

	PHALCON_INIT_VAR(serialized);
	phalcon_call_func_p1(serialized, "igbinary_serialize", data);
	RETURN_CCTOR(serialized);
}

/**
 * Unserializes data after retrieval
 *
 * @param string $data
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, afterRetrieve){

	zval *data, *unserialized;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);

	PHALCON_INIT_VAR(unserialized);
	phalcon_call_func_p1(unserialized, "igbinary_unserialize", data);
	RETURN_CCTOR(unserialized);
}

