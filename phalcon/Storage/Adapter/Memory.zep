
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Adapter;

use Phalcon\Collection;
use Phalcon\Helper\Arr;
use Phalcon\Storage\Adapter\AbstractAdapter;
use Phalcon\Storage\Exception;
use Phalcon\Storage\Serializer\SerializerInterface;

/**
 * Phalcon\Storage\Adapter\Memory
 *
 * Memory adapter
 */
class Memory extends AbstractAdapter
{
    /**
     * @var Collection
     */
    protected data = [];

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
        let this->prefix  = "ph-memo-",
            this->options = options,
            this->data    = new Collection();

        parent::__construct(options);

        let className = "Phalcon\\Storage\\Serializer\\" . this->defaultSerializer;
        let this->serializer = new {className}();
    }

    /**
     * Flushes/clears the cache
     */
    public function clear() -> bool
    {
        this->data->clear();

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
        var current, newValue, prefixedKey, result;

        let prefixedKey = this->getPrefixedKey(key),
            result      = this->data->has(prefixedKey);

        if result {
            let current  = this->data->get(prefixedKey),
                newValue = (int) current - value,
                result   = newValue;

            this->data->set(prefixedKey, newValue);
        }

        return result;
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
        var exists, prefixedKey;

        let prefixedKey = this->getPrefixedKey(key),
            exists      = this->data->has(prefixedKey);

        this->data->remove(prefixedKey);

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
    public function get(string! key, var defaultValue = null) -> var
    {
        var content, prefixedKey;

        let prefixedKey = this->getPrefixedKey(key),
            content     = this->data->get(prefixedKey);

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
        return array_keys(this->data->toArray());
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
        var prefixedKey;

        let prefixedKey = this->getPrefixedKey(key);

        return this->data->has(prefixedKey);
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
        var current, newValue, prefixedKey, result;

        let prefixedKey = this->getPrefixedKey(key),
            result      = this->data->has(prefixedKey);

        if result {
            let current  = this->data->get(prefixedKey),
                newValue = (int) current + value,
                result   = newValue;

            this->data->set(prefixedKey, newValue);
        }

        return result;
    }

    /**
     * Stores data in the adapter
     *
     * @param string $key
     * @param mixed  $value
     * @param null   $ttl
     *
     * @return bool
     */
    public function set(string! key, var value, var ttl = null) -> bool
    {
        var content, lifetime, prefixedKey;

        let content     = this->getSerializedData(value),
            lifetime    = this->getTtl(ttl),
            prefixedKey = this->getPrefixedKey(key);

        this->data->set(prefixedKey, content);

        return true;
    }
}
