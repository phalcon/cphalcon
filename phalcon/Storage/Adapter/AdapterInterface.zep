
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Adapter;

use Phalcon\Storage\Serializer\SerializerInterface;

/**
 * Interface for Phalcon\Logger adapters
 */
interface AdapterInterface
{
    /**
     * Flushes/clears the cache
     */
    public function clear() -> bool;

    /**
     * Decrements a stored number
     */
    public function decrement(string! key, int value = 1) -> int | bool;

    /**
     * Deletes data from the adapter
     */
    public function delete(string! key) -> bool;

    /**
     * Reads data from the adapter
     *
     * @param string key
     * @param mixed|null defaultValue
     *
     * @return mixed
     */
    public function get(string! key, var defaultValue = null) -> var;

    /**
     * Returns the already connected adapter or connects to the backend
     * server(s)
     */
    public function getAdapter() -> var;

    /**
     * Returns all the keys stored
     */
    public function getKeys(string! prefix = "") -> array;

    /**
     * Returns the prefix for the keys
     */
    public function getPrefix() -> string;

    /**
     * Checks if an element exists in the cache
     */
    public function has(string! key) -> bool;

    /**
     * Increments a stored number
     */
    public function increment(string! key, int value = 1) -> int | bool;

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
     */
    public function set(string! key, var value, var ttl = null) -> bool;

    /**
     * Stores data in the adapter forever. The key needs to manually deleted
     * from the adapter.
     *
     * @param string $key
     * @param mixed  $value
     *
     * @return bool
     */
    public function setForever(string key, value) -> bool;
}
