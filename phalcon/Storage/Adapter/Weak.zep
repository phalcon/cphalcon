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

    /**
     * Decrements a stored number — not supported for WeakReference
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     */
    protected function doDecrement(string! key, int value = 1) -> int | bool
    {
        return false;
    }

    /**
     * Deletes data from the adapter
     *
     * @param string $key
     *
     * @return bool
     */
    protected function doDelete(string! key) -> bool
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
     *
     * @param string     $key
     * @param mixed|null $defaultValue
     *
     * @return mixed
     */
    protected function doGet(string! key, var defaultValue = null) -> var
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

        let wr    = this->weakList[key];
        let value = wr->get();
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
     *
     * @param string $key
     *
     * @return bool
     */
    protected function doHas(string! key) -> bool
    {
        return isset this->weakList[key];
    }

    /**
     * Increments a stored number — not supported for WeakReference
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     */
    protected function doIncrement(string! key, int value = 1) -> int | bool
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
     * @param string                $key
     * @param mixed                 $value
     * @param DateInterval|int|null $ttl
     *
     * @return bool
     * @throws BaseException
     */
    protected function doSet(string! key, var value, var ttl = null) -> bool
    {
        if typeof value !== "object" {
            return false;
        }

        if false === isset this->weakList[key] {
            let this->weakList[key] = \WeakReference::create(value);
        }

        return true;
    }
}
