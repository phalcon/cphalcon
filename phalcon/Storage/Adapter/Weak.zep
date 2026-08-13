/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Adapter;


use Exception as BaseException;
use Phalcon\Contracts\Storage\StorageTypes;
use Phalcon\Storage\SerializerFactory;
use WeakReference;

/**
 * Weak Adapter
 *
 * Capabilities:
 * - Stores objects only, as WeakReferences; entries vanish when the referenced
 *   object is garbage-collected.
 * - TTL is ignored; no serializer is used (none/no-op).
 * - Counters unsupported: increment()/decrement() return false.
 * - setForever() is equivalent to set(); getKeys() reads the in-memory list.
 *
 * @phpstan-import-type storage_adapter_options from StorageTypes
 * @phpstan-import-type storage_keys from StorageTypes
 * @phpstan-import-type storage_weak_list from StorageTypes
 */
class Weak extends AbstractAdapter
{
    /**
     *
     *
     * @var string|null
     */
    protected fetching = null;

    /**
     * @var array<string, WeakReference<object>>
     *
     * @phpstan-var storage_weak_list
     */
    protected array weakList = [];

    /**
     * Constructor, there are no options
     *
     * @phpstan-param storage_adapter_options $options
     */
    public function __construct(<SerializerFactory> factory, array options = [])
    {
        let this->defaultSerializer = "none",
            this->lifetime           = this->getArrVal(options, "lifetime", 3600),
            this->prefix             = "",
            this->options            = options;
    }

    /**
     * Flushes/clears the cache
     */
    public function clear() -> bool
    {
        let this->weakList = [];
        return true;
    }

    /**
     * Stores data in the adapter
     *
     * @phpstan-return storage_keys
     */
    public function getKeys(string prefix = "") -> array
    {
        var keys, key;
        array results;
        let keys = array_keys(this->weakList);
        if unlikely "" !== prefix {
            let results = [];
            for key in keys {
                if starts_with(key, prefix) {
                    let results[] = key;
                }
            }
            return results;
        }
        return keys;
    }

    /**
     * Will never set a serializer, WeakReference cannot be serialized
     */
    public function setDefaultSerializer(string serializer) -> void
    {
    }

    /**
     * For compatiblity only, there is no Forever with WeakReference.
     */
    public function setForever(string key, var data) -> bool
    {
        return this->set(key, data);
    }

    /**
     * Decrements a stored number - not supported for WeakReference
     */
    protected function doDecrement( string key, int value = 1) -> false | int
    {
        return false;
    }

    /**
     * Deletes data from the adapter
     */
    protected function doDelete( string key) -> bool
    {
        var exists;

        if key === this->fetching {
            return false;
        }

        let exists = isset this->weakList[key];
        unset(this->weakList[key]);

        return exists;
    }

    /**
     * Reads data from the adapter
     */
    protected function doGet(string key, var defaultValue = null) -> var
    {
        var value, wr;

        /**
         * while getting a key, garbage collection might be triggered,
         * this will stop unsetting the key, will not stop however the model
         * gets destroyed by GC,
         * this is for the destruct that is in the model
         * not do destroy the key before getting it.
         */
        let this->fetching = key;
        if false === isset this->weakList[key] {
            let this->fetching = null;

            return defaultValue;
        }

        let wr             = this->weakList[key];
        let value          = wr->get();
        let this->fetching = null;

        /**
         * value could be null, object could be destroyed while fetching
         */
        if null === value {
            this->delete(key);
        }

        return value;
    }

    /**
     * Checks if an element exists in the cache
     */
    protected function doHas( string key) -> bool
    {
        return isset this->weakList[key];
    }

    /**
     * Increments a stored number - not supported for WeakReference
     */
    protected function doIncrement( string key, int value = 1) -> false | int
    {
        return false;
    }

    /**
     * Stores data in the adapter. If the TTL is `null` (default) or not defined
     * then the default TTL will be used, as set in this adapter. If the TTL
     * is `0` or a negative number, a `delete()` will be issued, since this
     * item has expired. If you need to set this key forever, you should use
     * the `setForever()` method.
     *
     * @throws BaseException
     */
    protected function doSet( string key, var value, var ttl = null) -> bool
    {
        if typeof value !== "object" {
            return false;
        }

        if false === isset this->weakList[key] {
            let this->weakList[key] = WeakReference::create(value);
        }

        return true;
    }
}
