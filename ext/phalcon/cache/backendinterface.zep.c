
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Cache\BackendInterface
 *
 * Interface for Phalcon\Cache\Backend adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_BackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Cache, BackendInterface, phalcon, cache_backendinterface, phalcon_cache_backendinterface_method_entry);

	return SUCCESS;

}

/**
 * Starts a cache. The keyname allows to identify the created fragment
 *
 * @param int|string keyName
 * @param   int lifetime
 * @return  mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_BackendInterface, start);

/**
 * Stops the frontend without store any cached content
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_BackendInterface, stop);

/**
 * Returns front-end instance adapter related to the back-end
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_BackendInterface, getFrontend);

/**
 * Returns the backend options
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_BackendInterface, getOptions);

/**
 * Checks whether the last cache is fresh or cached
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_BackendInterface, isFresh);

/**
 * Checks whether the cache has starting buffering or not
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_BackendInterface, isStarted);

/**
 * Sets the last key used in the cache
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_BackendInterface, setLastKey);

/**
 * Gets the last key stored by the cache
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_BackendInterface, getLastKey);

/**
 * Returns a cached content
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_BackendInterface, get);

/**
 * Stores cached content into the file backend and stops the frontend
 *
 * @param int|string keyName
 * @param string content
 * @param int lifetime
 * @return bool true on success/false otherwise
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_BackendInterface, save);

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_BackendInterface, delete);

/**
 * Query the existing cached keys
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_BackendInterface, queryKeys);

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param  string keyName
 * @param  int lifetime
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_BackendInterface, exists);

