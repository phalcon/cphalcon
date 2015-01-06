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

#include "cache/frontend/json.h"
#include "cache/frontend/data.h"
#include "cache/frontendinterface.h"

#include "kernel/main.h"
#include "kernel/string.h"
#include "kernel/string.h"

/**
 * Phalcon\Cache\Frontend\Json
 *
 * Allows to cache data converting/deconverting them to JSON.
 *
 * This adapters uses the json_encode/json_decode PHP's functions
 *
 * As the data is encoded in JSON other systems accessing the same backend could
 * process them
 *
 *<code>
 *
 * // Cache the data for 2 days
 * $frontCache = new Phalcon\Cache\Frontend\Json(array(
 *    "lifetime" => 172800
 * ));
 *
 * //Create the Cache setting memcached connection options
 * $cache = new Phalcon\Cache\Backend\Memcache($frontCache, array(
 *		'host' => 'localhost',
 *		'port' => 11211,
 *  	'persistent' => false
 * ));
 *
 * //Cache arbitrary data
 * $cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 * //Get data
 * $data = $cache->get('my-data');
 *</code>
 */
zend_class_entry *phalcon_cache_frontend_json_ce;

PHP_METHOD(Phalcon_Cache_Frontend_Json, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_Json, afterRetrieve);

static const zend_function_entry phalcon_cache_frontend_json_method_entry[] = {
	PHP_ME(Phalcon_Cache_Frontend_Json, beforeStore, arginfo_phalcon_cache_frontendinterface_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Json, afterRetrieve, arginfo_phalcon_cache_frontendinterface_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Cache\Frontend\Json initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Json){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Frontend, Json, cache_frontend_json, phalcon_cache_frontend_data_ce, phalcon_cache_frontend_json_method_entry, 0);

	zend_class_implements(phalcon_cache_frontend_json_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);

	return SUCCESS;
}

/**
 * Serializes data before storing it
 *
 * @param mixed $data
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, beforeStore){

	zval *data;

	phalcon_fetch_params(0, 1, 0, &data);
	RETURN_ON_FAILURE(phalcon_json_encode(return_value, data, 0 TSRMLS_CC));
}

/**
 * Unserializes data after retrieving it
 *
 * @param mixed $data
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, afterRetrieve){

	zval *data;

	phalcon_fetch_params(0, 1, 0, &data);
	RETURN_ON_FAILURE(phalcon_json_decode(return_value, data, 0 TSRMLS_CC));
}
