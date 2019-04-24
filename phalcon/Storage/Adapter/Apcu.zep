
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Adapter;

use Phalcon\Helper\Arr;
use Phalcon\Storage\Adapter\AbstractAdapter;
use Phalcon\Storage\Exception;
use Phalcon\Storage\Serializer\SerializerInterface;

/**
 * Phalcon\Storage\Adapter\Apcu
 *
 * Apcu adapter
 */
class Apcu extends AbstractAdapter
{
    /**
     * @var array
     */
    protected options = [];

    /**
     * Constructor
     */
    public function __construct(array! options = [])
    {
        string className;

        /**
         * Lets set some defaults and options here
         */
        let this->prefix  = "ph-apcu-",
            this->options = options;

        parent::__construct(options);

        let className = "Phalcon\\Storage\\Serializer\\" . this->defaultSerializer;
        let this->serializer = new {className}();
    }

    /**
     * Flushes/clears the cache
     */
    public function clear() -> bool
    {
        var item, pattern, apc = null;
        bool result;

        let pattern = "/^" . this->prefix . "/",
            apc     = new \APCUIterator(pattern),
            result  = true;

        if typeof apc !== "object" {
            return false;
        }

        for item in iterator(apc) {
            if !apcu_delete(item["key"]) {
                let result = false;
            }
        }

        return result;
    }

    /**
     * Decrements a stored number
     */
    public function decrement(string! key, int value = 1) -> int | bool
    {
        var prefixedKey;

        let prefixedKey = this->getPrefixedKey(key);

        return apcu_dec(prefixedKey, value);
    }

    /**
     * Reads data from the adapter
     */
    public function delete(string! key) -> bool
    {
        var prefixedKey;

        let prefixedKey = this->getPrefixedKey(key);

        return apcu_delete(prefixedKey);
    }

    /**
     * Reads data from the adapter
     */
    public function get(string! key, var defaultValue = null) -> var
    {
        var content, prefixedKey;

        let prefixedKey = this->getPrefixedKey(key),
            content     = apcu_fetch(prefixedKey);

        return this->getUnserializedData(content, defaultValue);
    }

    /**
     * Returns the already connected adapter or connects to the Memcached
     * server(s)
     */
    public function getAdapter() -> var
    {
        return this->adapter;
    }

    /**
     * Stores data in the adapter
     */
    public function getKeys() -> array
    {
        var item, pattern, apc = null;
        array results;

        let pattern = "/^" . this->prefix . "/",
            apc     = new \APCUIterator(pattern),
            results = [];

        if typeof apc !== "object" {
            return results;
        }

        for item in iterator(apc) {
            let results[] = item["key"];
        }

        return results;
    }

    /**
     * Checks if an element exists in the cache
     */
    public function has(string! key) -> bool
    {
        var prefixedKey;

        let prefixedKey = this->getPrefixedKey(key);

        return apcu_exists(prefixedKey);
    }

    /**
     * Increments a stored number
     */
    public function increment(string! key, int value = 1) -> int | bool
    {
        var prefixedKey;

        let prefixedKey = this->getPrefixedKey(key);

        return apcu_inc(prefixedKey, value);
    }

    /**
     * Stores data in the adapter
     */
    public function set(string! key, var value, var ttl = null) -> bool
    {
        var connection, content, lifetime, prefixedKey;

        let connection  = this->getAdapter(),
            content     = this->getSerializedData(value),
            lifetime    = this->getTtl(ttl),
            prefixedKey = this->getPrefixedKey(key);

        return apcu_store(prefixedKey, content, lifetime);
    }
}
