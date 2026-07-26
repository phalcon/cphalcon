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
use Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as SupportException;
use Phalcon\Traits\Php\ApcuTrait;

/**
 * Apcu adapter
 *
 * Capabilities:
 * - Counters: native atomic (apcu_inc()/apcu_dec()).
 * - getKeys(): APCUIterator regex scan over the shared APCu store.
 * - Serializers: Phalcon-side only; no backend-native serializer.
 *
 * @property array $options
 */
class Apcu extends AbstractAdapter
{
    use ApcuTrait;

    /**
     * @var string
     */
    protected prefix = "ph-apcu-";

    /**
     * Apcu constructor.
     *
     * @param SerializerFactory $factory
     * @param array             $options
     *
     * @throws SupportException
     */
    public function __construct(<SerializerFactory> factory,  array options = [])
    {
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
            apc     = this->phpApcuIterator(pattern),
            result  = true;

        if typeof apc !== "object" {
            return false;
        }

        for item in iterator(apc) {
            if (true !== this->phpApcuDelete(item["key"])) {
                let result = false;
            }
        }

        return result;
    }

    /**
     * Stores data in the adapter
     *
     * @param string $prefix
     *
     * @return array
     */
    public function getKeys( string prefix = "") -> array
    {
        var item, pattern, apc = null;
        array results;

        let pattern = "/^" . this->prefix . prefix . "/",
            apc     = this->phpApcuIterator(pattern),
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
     * Stores data in the adapter forever. The key needs to manually deleted
     * from the adapter.
     *
     * @param string $key
     * @param mixed  $value
     *
     * @return bool
     */
    public function setForever( string key, var value) -> bool
    {
        var result;

        let result = this->phpApcuStore(
            this->getPrefixedKey(key),
            this->getSerializedData(value)
        );

        return is_bool(result) ? result : false;
    }

    /**
     * Decrements a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     */
    protected function doDecrement( string key, int value = 1) -> int | bool
    {
        return this->phpApcuDec(this->getPrefixedKey(key), value);
    }

    /**
     * Deletes data from the adapter
     *
     * @param string $key
     *
     * @return bool
     */
    protected function doDelete( string key) -> bool
    {
        return (bool) this->phpApcuDelete(this->getPrefixedKey(key));
    }

    /**
     * Deletes multiple keys from APCu in a single call
     *
     * @param array $keys
     * @return bool
     */
    protected function doDeleteMultiple(array keys) -> bool
    {
        var prefixedKeys = [], key, result;

        for key in keys {
            let prefixedKeys[] = this->getPrefixedKey(key);
        }

        let result = this->phpApcuDelete(prefixedKeys);

        // apcu_delete with array returns array of keys that could NOT be deleted
        return typeof result === "array" && empty result;
    }

    /**
     * @param string $key
     *
     * @return mixed
     */
    protected function doGetData(string key)
    {
        return this->phpApcuFetch(this->getPrefixedKey(key));
    }

    /**
     * Checks if an element exists in the cache
     *
     * @param string $key
     *
     * @return bool
     */
    protected function doHas( string key) -> bool
    {
        var result;

        let result = this->phpApcuExists(this->getPrefixedKey(key));

        return typeof result === "bool" ? result : false;
    }

    /**
     * Increments a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     */
    protected function doIncrement( string key, int value = 1) -> int | bool
    {
        return this->phpApcuInc(this->getPrefixedKey(key), value);
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
     * @throws Exception
     */
    protected function doSet( string key, var value, var ttl = null) -> bool
    {
        var result;

        if (typeof ttl === "integer" && ttl < 1) {
            return this->delete(key);
        }

        let result = this->phpApcuStore(
            this->getPrefixedKey(key),
            this->getSerializedData(value),
            this->getTtl(ttl)
        );

        return typeof result === "bool" ? result : false;
    }
}
