
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

/**
 * Memory adapter
 *
 * @property array $data
 * @property array $options
 */
class Memory extends AbstractAdapter
{
    /**
     * @var array
     */
    protected data = [];

    /**
     * Memory constructor.
     *
     * @param SerializerFactory $factory
     * @param array             $options
     *
     * @throws SupportException
     */
    public function __construct(<SerializerFactory> factory, array! options = [])
    {
        parent::__construct(factory, options);

        this->initSerializer();
    }

    /**
     * Flushes/clears the cache
     */
    public function clear() -> bool
    {
        let this->data = [];

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
        var current, prefixedKey, result;

        let prefixedKey = this->getPrefixedKey(key);

        if unlikely !fetch current, this->data[prefixedKey] {
            return false;
        }

        let result = (int) current - value,
            this->data[prefixedKey] = result;

        return result;
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
        var exists, prefixedKey;

        let prefixedKey = this->getPrefixedKey(key),
            exists      = isset(this->data[prefixedKey]);

        unset(this->data[prefixedKey]);

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
    public function get(string key, defaultValue = null)
    {
        var content, prefixedKey;

        let prefixedKey = this->getPrefixedKey(key),
            content     = this->data[prefixedKey];

        return this->getUnserializedData(content, defaultValue);
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
        return this->getFilteredKeys(array_keys(this->data), prefix);
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

        return isset(this->data[prefixedKey]);
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
        var current, prefixedKey, result;

        let prefixedKey = this->getPrefixedKey(key);

        if unlikely !fetch current, this->data[prefixedKey] {
            return false;
        }

        let result = (int) current + value,
            this->data[prefixedKey] = result;

        return result;
    }

    /**
     * Stores data in the adapter
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
        var content, prefixedKey;

        if (typeof ttl === "integer" && ttl < 1) {
            return this->delete(key);
        }

        let content     = this->getSerializedData(value),
            prefixedKey = this->getPrefixedKey(key);

        let this->data[prefixedKey] = content;

        return true;
    }

    /**
     * Stores data in the adapter forever. The key needs to manually deleted
     * from the adapter.
     *
     * @param string $key
     * @param mixed  $value
     *
     * @return bool
     */
    public function setForever(string! key, var value) -> bool
    {
        return this->set(key, value);
    }
}
