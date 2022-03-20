
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
        var current, newValue, prefixedKey, result;

        let prefixedKey = this->getPrefixedKey(key),
            result      = array_key_exists(prefixedKey, this->data);

        if likely true === result {
            let current  = this->data[prefixedKey],
                newValue = (int) current - value,
                result   = newValue;

            let this->data[prefixedKey] = newValue;
        }

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
            exists      = array_key_exists(prefixedKey, this->data);

        unset(this->data[prefixedKey]);

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

        return array_key_exists(prefixedKey, this->data);
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
            result      = array_key_exists(prefixedKey, this->data);

        if likely true === result {
            let current  = this->data[prefixedKey],
                newValue = (int) current + value,
                result   = newValue;

            let this->data[prefixedKey] = newValue;
        }

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

    /**
     * @param string $key
     *
     * @return mixed
     */
    protected function doGet(string key)
    {
        return this->data[this->getPrefixedKey(key)];
    }
}
