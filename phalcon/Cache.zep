
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\Cache\Adapter\AdapterInterface;
use Phalcon\Cache\Exception\Exception;
use Phalcon\Cache\Exception\InvalidArgumentException;
use Psr\SimpleCache\CacheInterface;
use Traversable;

/**
 * This component offers caching capabilities for your application.
 * Phalcon\Cache implements PSR-16.
 */
class Cache implements CacheInterface
{
    /**
     * The adapter
     *
     * @var AdapterInterface
     */
    protected adapter { get };

    /**
     * Constructor.
     *
     * @param AdapterInterface  adapter The cache adapter
     */
    public function __construct(<AdapterInterface> adapter)
    {
        let this->adapter = adapter;
    }

    /**
     * Wipes clean the entire cache's keys.
     *
     * @return bool True on success and false on failure.
     */
    public function clear() -> bool
    {
        return this->adapter->clear();
    }

    /**
     * Delete an item from the cache by its unique key.
     *
     * @param string $key The unique cache key of the item to delete.
     *
     * @return bool True if the item was successfully removed. False if there was an error.
     *
     * @throws InvalidArgumentException MUST be thrown if the $key string is not a legal value.
     */
    public function delete(var key) -> bool
    {
        this->checkKey(key);

        return this->adapter->delete(key);
    }

    /**
     * Deletes multiple cache items in a single operation.
     *
     * @param iterable $keys A list of string-based keys to be deleted.
     *
     * @return bool True if the items were successfully removed. False if there was an error.
     *
     * @throws InvalidArgumentException MUST be thrown if $keys is neither an array nor a Traversable, or if any of the $keys are not a legal value.
     */
    public function deleteMultiple(var keys) -> bool
    {
        var key, result;

        this->checkKeys(keys);

        let result = true;

        for key in keys {
            if !this->adapter->delete(key) {
                let result = false;
            }
        }

        return result;
    }

    /**
     * Fetches a value from the cache.
     *
     * @param string $key          The unique key of this item in the cache.
     * @param mixed  $defaultValue Default value to return if the key does not exist.
     *
     * @return mixed The value of the item from the cache, or $default in case of cache miss.
     *
     * @throws InvalidArgumentException MUST be thrown if the $key string is not a legal value.
     */
    public function get(var key, var defaultValue = null) -> var
    {
        this->checkKey(key);

        return this->adapter->get(key, defaultValue);
    }

    /**
     * Obtains multiple cache items by their unique keys.
     *
     * @param iterable $keys         A list of keys that can obtained in a single operation.
     * @param mixed    $defaultValue Default value to return for keys that do not exist.
     *
     * @return iterable A list of key => value pairs. Cache keys that do not exist or are stale will have $default as value.
     *
     * @throws InvalidArgumentException MUST be thrown if $keys is neither an array nor a Traversable, or if any of the $keys are not a legal value.
     */
    public function getMultiple(var keys, var defaultValue = null) -> var
    {
        var element;
        array results;

        this->checkKeys(keys);

        let results = [];
        for element in keys {
            let results[element] = this->get(element, defaultValue);
        }

        return results;
    }

    /**
     * Determines whether an item is present in the cache.
     *
     * @param string $key The cache item key.
     *
     * @return bool
     *
     * @throws InvalidArgumentException MUST be thrown if the $key string is not a legal value.
     */
    public function has(var key) -> bool
    {
        this->checkKey(key);

        return this->adapter->has(key);
    }

    /**
     * Persists data in the cache, uniquely referenced by a key with an optional expiration TTL time.
     *
     * @param string                 $key   The key of the item to store.
     * @param mixed                  $value The value of the item to store. Must be serializable.
     * @param null|int|\DateInterval $ttl   Optional. The TTL value of this item. If no value is sent and
     *                                      the driver supports TTL then the library may set a default value
     *                                      for it or let the driver take care of that.
     *
     * @return bool True on success and false on failure.
     *
     * @throws InvalidArgumentException MUST be thrown if the $key string is not a legal value.
     */
    public function set(var key, var value, var ttl = null) -> bool
    {
        this->checkKey(key);

        return this->adapter->set(key, value, ttl);
    }

    /**
     * Persists a set of key => value pairs in the cache, with an optional TTL.
     *
     * @param iterable               $values A list of key => value pairs for a multiple-set operation.
     * @param null|int|\DateInterval $ttl    Optional. The TTL value of this item. If no value is sent and
     *                                       the driver supports TTL then the library may set a default value
     *                                       for it or let the driver take care of that.
     *
     * @return bool True on success and false on failure.
     *
     * @throws InvalidArgumentException MUST be thrown if $values is neither an array nor a Traversable, or if any of the $values are not a legal value.
     */
    public function setMultiple(var values, var ttl = null) -> bool
    {
        var key, value;
        bool result;

        this->checkKeys(values);

        let result = true;
        for key, value in values {
            if !this->set(key, value, ttl) {
                let result = false;
            }
        }

        return result;
    }

    /**
     * Checks the key. If it contains invalid characters an exception is thrown
     */
    protected function checkKey(var key) -> void
    {
        let key = (string) key;

        if preg_match("/[^A-Za-z0-9-_.]/", key) {
            throw new InvalidArgumentException(
                "The key contains invalid characters"
            );
        }
    }

    /**
     * Checks the key. If it contains invalid characters an exception is thrown
     */
    protected function checkKeys(var keys) -> void
    {
        if !(typeof keys === "array" || keys instanceof Traversable) {
            throw new InvalidArgumentException(
                "The keys need to be an array or instance of Traversable"
            );
        }
    }
}
