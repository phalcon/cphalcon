
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Adapter;

use APCUIterator;
use Phalcon\Helper\Arr;
use Phalcon\Storage\Adapter\AbstractAdapter;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Storage\Serializer\SerializerInterface;

/**
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
    public function __construct(<SerializerFactory> factory = null, array! options = [])
    {
        /**
         * Lets set some defaults and options here
         */
        let this->prefix  = "ph-apcu-",
            this->options = options;

        parent::__construct(factory, options);

        this->initSerializer();
    }

    /**
     * Flushes/clears the cache
     */
    public function clear() -> bool
    {
        var item, pattern, apc = null;
        bool result;

        let pattern = "/^" . this->prefix . "/",
            apc     = new APCUIterator(pattern),
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
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     */
    public function decrement(string! key, int value = 1) -> int | bool
    {
        return apcu_dec(this->getPrefixedKey(key), value);
    }

    /**
     * Reads data from the adapter
     *
     * @param string $key
     *
     * @return bool
     */
    public function delete(string! key) -> bool
    {
        return apcu_delete(this->getPrefixedKey(key));
    }

    /**
     * Reads data from the adapter
     *
     * @param string $key
     * @param null   $defaultValue
     *
     * @return mixed
     */
    public function get(string! key, var defaultValue = null) -> var
    {
    	var content;

        let content = apcu_fetch(this->getPrefixedKey(key));

        return this->getUnserializedData(content, defaultValue);
    }

    /**
     * Returns the already connected adapter or connects to the Memcached
     * server(s)
     *
     * @return mixed
     */
    public function getAdapter() -> var
    {
        return this->adapter;
    }

    /**
     * Stores data in the adapter
     *
     * @return array
     */
    public function getKeys() -> array
    {
        var item, pattern, apc = null;
        array results;

        let pattern = "/^" . this->prefix . "/",
            apc     = new APCUIterator(pattern),
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
     *
     * @param string $key
     *
     * @return bool
     */
    public function has(string! key) -> bool
    {
        return apcu_exists(this->getPrefixedKey(key));
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
        return apcu_inc(this->getPrefixedKey(key), value);
    }

    /**
     * Stores data in the adapter
     *
     * @param string $key
     * @param mixed  $value
     * @param null   $ttl
     *
     * @return bool
     * @throws \Exception
     */
    public function set(string! key, var value, var ttl = null) -> bool
    {
        return apcu_store(
            this->getPrefixedKey(key),
            this->getSerializedData(value),
            this->getTtl(ttl)
        );
    }
}
