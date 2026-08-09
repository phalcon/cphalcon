
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cache;

use DateInterval;
use Phalcon\Cache\Adapter\AdapterInterface;
use Phalcon\Cache\Exception\InvalidArgumentException;
use Throwable;

/**
 * This component offers caching capabilities for your application.
 */
class Cache extends AbstractCache
{
    /**
     * Wipes clean the entire cache's keys.
     *
     * @return bool True on success and false on failure.
     */
    public function clear() -> bool
    {
        return this->doClear();
    }

    /**
     * Delete an item from the cache by its unique key.
     *
     * @param string $key The unique cache key of the item to delete.
     *
     * @return bool True if the item was successfully removed. False if there
     *              was an error.
     *
     * @throws InvalidArgumentException
     */
    public function delete(string key) -> bool
    {
        return this->doDelete(key);
    }

    /**
     * Deletes multiple cache items in a single operation.
     */
    public function deleteMultiple(var keys) -> bool
    {
        return this->doDeleteMultiple(keys);
    }

    /**
     * Fetches a value from the cache.
     */
    public function get(string key, var defaultValue = null) -> mixed
    {
        return this->doGet(key, defaultValue);
    }

    /**
     * Obtains multiple cache items by their unique keys.
     */
    public function getMultiple(var keys, var defaultValue = null)
    {
        return this->doGetMultiple(keys, defaultValue);
    }

    /**
     * Determines whether an item is present in the cache.
     */
    public function has(string key) -> bool
    {
        return this->doHas(key);
    }

    /**
     * Persists data in the cache, uniquely referenced by a key with an optional
     * expiration TTL time.
     */
    public function set(string key, var value, var ttl = null) -> bool
    {
        return this->doSet(key, value, ttl);
    }

    /**
     * Persists a set of key => value pairs in the cache, with an optional TTL.
     */
    public function setMultiple(var values, var ttl = null) -> bool
    {
        return this->doSetMultiple(values, ttl);
    }

    /**
     * Returns the exception class that will be used for exceptions thrown
     * 
     * @return class-string<Throwable>
     */
    protected function getExceptionClass() -> string
    {
        return InvalidArgumentException::class;
    }
}
