
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Adapter;


use DateInterval;
use Exception as BaseException;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as SupportException;
use Phalcon\Storage\Serializer\SerializerInterface;

/**
* Weak Adapter
*/
class Weak extends AbstractAdapter
{

    /**
     *
     *
     * @var int|null
     */
    protected fetching = null;

    /**
     * @var array
     */

    protected weakList = [];

    /**
     * @var array
     */
    protected options = [];

    /**
     * Constructor, there are no options
     *
     * @param array options = []
     * @throws SupportException
     */
    public function __construct(<SerializerFactory> factory, array! options = [])
    {
        let this->defaultSerializer = "none",
            this->prefix                 = "",
            this->options                = options;
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
     * Decrements a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     */
    public function decrement(string! key, int value = 1) -> int | bool
    {
        this->fire(this->eventType . ":beforeDecrement", key);
        this->fire(this->eventType . ":afterDecrement", key);

        return false;
    }

    /**
     * Deletes data from the adapter
     *
     * @param string $key
     *
     * @return bool
     */
    public function delete(string! key) -> bool
    {
        var exists;

        this->fire(this->eventType . ":beforeDelete", key);

        if key === this->fetching {
            this->fire(this->eventType . ":afterDelete", key);

            return false;
        }
        let exists = isset this->weakList[key];
        unset(this->weakList[key]);

        this->fire(this->eventType . ":afterDelete", key);

        return exists;
    }

    /**
     * Stores data in the adapter
     *
     * @param string $prefix
     *
     * @return array
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
     * Increments a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     */
    public function increment(string! key, int value = 1) -> int | bool
    {
        this->fire(this->eventType . ":beforeIncrement", key);
        this->fire(this->eventType . ":afterIncrement", key);

        return false;
    }

    /**
    * Reads data from the adapter
    *
    * @param string key
    * @param mixed|null   defaultValue
    *
    * @return mixed
    */
    public function get(string! key, var defaultValue = null) -> var
    {
        var value, wr;

        this->fire(this->eventType . ":beforeGet", key);

        /**
         * while getting a key, garbage collection might be triggered,
         * this will stop unsetting the key, will not stop however the model gets destroid by GC,
         * this is for the destruct that is in the model
         * not do destroy the key before getting it.
         */
        let this->fetching = key;
        if false === isset this->weakList[key] {
            let this->fetching = null;

            this->fire(this->eventType . ":afterGet", key);

            return defaultValue;
        }
        let wr = this->weakList[key];
        let value = wr->get();
        let this->fetching = null;
        /**
         * value could be null, object could be destroid while fetching
         */
        if null === value {
            this->delete(key);
        }

        this->fire(this->eventType . ":afterGet", key);

        return value;
    }

    /**
    * Checks if an element exists in the cache
    *
    * @param string key
    *
    * @return bool
    */
    public function has(string! key) -> bool
    {
        var result;

        this->fire(this->eventType . ":beforeHas", key);

        let result = isset this->weakList[key];

        this->fire(this->eventType . ":afterHas", key);

        return result;
    }

    /**
     * Stores data in the adapter. If the TTL is `null` (default) or not defined
     * then the default TTL will be used, as set in this adapter. If the TTL
     * is `0` or a negative number, a `delete()` will be issued, since this
     * item has expired. If you need to set this key forever, you should use
     * the `setForever()` method.
     *
     * @param string                $key
     * @param mixed                 $value
     * @param DateInterval|int|null $ttl
     *
     * @return bool
     * @throws BaseException
     */
    public function set(string! key, var value, var ttl = null) -> bool
    {
        this->fire(this->eventType . ":beforeSet", key);

        if typeof value !== "object" {
            this->fire(this->eventType . ":afterSet", key);

            return false;
        }
        if false === isset this->weakList[key] {
            let this->weakList[key] = \WeakReference::create(value);
        }

        this->fire(this->eventType . ":afterSet", key);

        return true;
    }

    /**
     * For compatiblity only, there is no Forever with WeakReference.
     *
     * @param string $key
     * @param mixed  $value
     *
     * @return bool
     */
    public function setForever(string key, value) -> bool
    {
        return this->set(key, value);
    }

    /**
     * will never set a serializer, WeakReference cannot be serialized
     * @param string $serializer
     */
    public function setDefaultSerializer(string serializer) -> void
    {
    }
}
