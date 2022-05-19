
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
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Cache\Cache
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_CacheInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Cache, CacheInterface, phalcon, cache_cacheinterface, phalcon_cache_cacheinterface_method_entry);

	return SUCCESS;
}

/**
 * Wipes clean the entire cache's keys.
 *
 * @return bool True on success and false on failure.
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_CacheInterface, clear);
/**
 * Delete an item from the cache by its unique key.
 *
 * @param string $key The unique cache key of the item to delete.
 *
 * @return bool True if the item was successfully removed. False if there
 *              was an error.
 *
 * @throws InvalidArgumentException MUST be thrown if the $key string is
 *                                  not a legal value.
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_CacheInterface, delete);
/**
 * Deletes multiple cache items in a single operation.
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_CacheInterface, deleteMultiple);
/**
 * Fetches a value from the cache.
 *
 * @param string $key          The unique key of this item in the cache.
 * @param mixed  $defaultValue Default value to return if the key does not exist.
 *
 * @return mixed The value of the item from the cache, or $default in case
 * of cache miss.
 *
 * @throws InvalidArgumentException MUST be thrown if the $key string is
 * not a legal value.
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_CacheInterface, get);
/**
 * Obtains multiple cache items by their unique keys.
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_CacheInterface, getMultiple);
/**
 * Determines whether an item is present in the cache.
 *
 * @param string $key The cache item key.
 *
 * @return bool
 *
 * @throws InvalidArgumentException MUST be thrown if the $key string is
 * not a legal value.
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_CacheInterface, has);
/**
 * Persists data in the cache, uniquely referenced by a key with an optional
 * expiration TTL time.
 *
 * @param string                $key    The key of the item to store.
 * @param mixed                 $value  The value of the item to store.
 *                                      Must be serializable.
 * @param null|int|DateInterval $ttl    Optional. The TTL value of this
 *                                      item. If no value is sent and the
 *                                      driver supports TTL then the library
 *                                      may set a default value for it or
 *                                      let the driver take care of that.
 *
 * @return bool True on success and false on failure.
 *
 * @throws InvalidArgumentException MUST be thrown if the $key string is not
 * a legal value.
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_CacheInterface, set);
/**
 * Persists a set of key => value pairs in the cache, with an optional TTL.
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_CacheInterface, setMultiple);
