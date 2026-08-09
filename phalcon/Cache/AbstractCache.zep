
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
use Phalcon\Cache\Adapter\Redis;
use Phalcon\Cache\Exception\InvalidArgumentException;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Events\Traits\EventsAwareTrait;
use Throwable;
use Traversable;

/**
 * This component offers caching capabilities for your application.
 *
 * Event layering: cache operations can emit `cache:*` events from two layers.
 * This facade fires `cache:before*`/`cache:after*` around each operation, and
 * the underlying `Storage` adapter (whose `eventType` is `"cache"`) also fires
 * `cache:before*`/`cache:after*` for the same operation. If an events manager
 * is wired into both the facade and the adapter, a single call emits the event
 * twice (once from each object). Wire the manager into one layer only; the
 * facade is the supported source for cache-level events (it also emits the
 * multi-key `cache:*Multiple` events).
 */
abstract class AbstractCache implements CacheInterface, EventsAwareInterface
{
    use EventsAwareTrait;

    protected <AdapterInterface> adapter;

    /**
     * Constructor.
     *
     * @param AdapterInterface $adapter The cache adapter
     */
    public function __construct(<AdapterInterface> adapter)
    {
        let this->adapter = adapter;
    }

    /**
     * Fetches a value from the cache.
     */
    abstract public function get(string key, var defaultValue = null) -> mixed;

    /**
     * Returns the current adapter
     */
    public function getAdapter() -> <AdapterInterface>
    {
        return this->adapter;
    }

    /**
     * Persists data in the cache, uniquely referenced by a key with an
     * optional expiration TTL time.
     */
    abstract public function set(
        string key,
        var value,
        var ttl = null
    ) -> bool;

    /**
     * Checks the key. If it contains invalid characters an exception is thrown
     */
    protected function checkKey(string key) -> void
    {
        var exceptionClass;

        if (key === "" || preg_match("/[^A-Za-z0-9-_.]/", key)) {
            let exceptionClass = this->getExceptionClass();

            throw new {exceptionClass}("The key contains invalid characters");
        }
    }

    /**
     * Checks the key. If it contains invalid characters an exception is thrown
     */
    protected function checkKeys(var keys) -> void
    {
        var exceptionClass;

        if (!(typeof keys === "array" || keys instanceof Traversable)) {
            let exceptionClass = this->getExceptionClass();

            throw new {exceptionClass}(
                "The keys need to be an array or instance of Traversable"
            );
        }
    }

    /**
     * Wipes clean the entire cache's keys.
     */
    protected function doClear() -> bool
    {
        return this->adapter->clear();
    }

    /**
     * Delete an item from the cache by its unique key.
     */
    protected function doDelete(string key) -> bool
    {
        var result;

        this->checkKey(key);

        this->fireManagerEvent("cache:beforeDelete", key);

        let result = this->adapter->delete(key);

        this->fireManagerEvent("cache:afterDelete", key);

        return result;
    }

    /**
     * Deletes multiple cache items in a single operation.
     */
    protected function doDeleteMultiple(var keys) -> bool
    {
        var key, keysArray, result;

        this->checkKeys(keys);

        this->fireManagerEvent("cache:beforeDeleteMultiple", keys);

        let keysArray = [];
        for key in keys {
            this->checkKey(key);
            let keysArray[] = key;
        }

        let result = this->adapter->deleteMultiple(keysArray);

        this->fireManagerEvent("cache:afterDeleteMultiple", keys);

        return result;
    }

    /**
     * Fetches a value from the cache.
     */
    protected function doGet(string key, var defaultValue = null) -> var
    {
        var result;

        this->checkKey(key);

        this->fireManagerEvent("cache:beforeGet", key);

        let result = this->adapter->get(key, defaultValue);

        this->fireManagerEvent("cache:afterGet", key);

        return result;
    }

    /**
     * Obtains multiple cache items by their unique keys.
     */
    protected function doGetMultiple(var keys, var defaultValue = null) -> array
    {
        var adapterClass, element, keysArray, results, serializer;

        this->checkKeys(keys);

        this->fireManagerEvent("cache:beforeGetMultiple", keys);

        let results = [];
        let adapterClass = this->adapter;
        if (adapterClass instanceof Redis) {
            /**
             * Validate every key and collect them into an array (this also
             * handles Traversable inputs), so `mget()` and `array_combine()`
             * below receive arrays instead of throwing a TypeError.
             *
             * NOTE: incoming keys are not routed through the adapter's key
             * policy here - `getKeyWithoutPrefix()` is protected on the
             * Storage adapter, so an already-prefixed key is prefixed again by
             * the phpredis `OPT_PREFIX` and misses. Resolving that needs the
             * batch-capability redesign noted in the modularity review.
             */
            let keysArray = [];
            for element in keys {
                this->checkKey(element);
                let keysArray[] = element;
            }

            let serializer = this->adapter->getSerializer();
            let results    = this->adapter->getAdapter()->mget(keysArray);
            let results    = array_map(
                function (element) use (serializer, defaultValue) {
                    if (false === element) {
                        return defaultValue;
                    }

                    serializer->unserialize(element);

                    if (
                        true === method_exists(serializer, "isSuccess") &&
                        true !== serializer->isSuccess()
                    ) {
                        return defaultValue;
                    }

                    return serializer->getData();
                },
                results
            );

            let results = array_combine(keysArray, results);
        } else {
            for element in keys {
                let results[element] = this->get(element, defaultValue);
            }
        }

        this->fireManagerEvent("cache:afterGetMultiple", keys);

        return results;
    }

    /**
     * Determines whether an item is present in the cache.
     */
    protected function doHas(string key) -> bool
    {
        var result;

        this->checkKey(key);

        this->fireManagerEvent("cache:beforeHas", key);

        let result = this->adapter->has(key);

        this->fireManagerEvent("cache:afterHas", key);

        return result;
    }

    /**
     * Persists data in the cache, uniquely referenced by a key with an optional
     * expiration TTL time.
     */
    protected function doSet(string key, var value, var ttl = null) -> bool
    {
        var result;

        this->checkKey(key);

        this->fireManagerEvent("cache:beforeSet", key);

        let result = this->adapter->set(key, value, ttl);

        this->fireManagerEvent("cache:afterSet", key);

        return result;
    }

    /**
     * Persists a set of key => value pairs in the cache, with an optional TTL.
     */
    protected function doSetMultiple(values, var ttl = null) -> bool
    {
        var key, keys, result, value;

        this->checkKeys(values);

        let keys = array_keys(values);
        for key in keys {
            this->checkKey(key);
        }

        this->fireManagerEvent("cache:beforeSetMultiple", keys);

        let result = true;
        for key, value in values {
            if (true !== this->set(key, value, ttl)) {
                let result = false;
            }
        }

        this->fireManagerEvent("cache:afterSetMultiple", keys);

        return result;
    }

    /**
     * Returns the exception class that will be used for exceptions thrown
     *
     * @return class-string<Throwable>
     */
    abstract protected function getExceptionClass() -> string;
}
