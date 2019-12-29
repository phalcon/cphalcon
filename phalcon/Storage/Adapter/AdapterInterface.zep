
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
     * Stores data in the adapter
     */
    public function set(string! key, var value, var ttl = null) -> bool;
}
