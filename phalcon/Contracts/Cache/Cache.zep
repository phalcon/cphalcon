
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Cache;

use DateInterval;
use Phalcon\Cache\Exception\InvalidArgumentException;

/**
 * Canonical contract for Phalcon\Cache\Cache.
 */
interface Cache
{
    /**
     * Wipes clean the entire cache's keys.
     *
     * @return bool True on success and false on failure.
     */
    public function clear() -> bool;

    /**
     * Delete an item from the cache by its unique key.
     *
     * @param string $key The unique cache key of the item to delete.
     *
     * @return bool True if the item was successfully removed. False if there
     *              was an error.
     *
     * @throws InvalidArgumentException MUST be thrown if the $key string is
     *                                  not a legal value.
     */
    public function delete(string key) -> bool;

    /**
     * Deletes multiple cache items in a single operation.
     *
     * @phpstan-param iterable<array-key, string> $keys
     */
    public function deleteMultiple(var keys) -> bool;

    /**
     * Fetches a value from the cache.
     */
    public function get(string key, var defaultValue = null);

    /**
     * Obtains multiple cache items by their unique keys.
     *
     * @phpstan-param iterable<array-key, string> $keys
     */
    public function getMultiple(var keys, var defaultValue = null);

    /**
     * Determines whether an item is present in the cache.
     */
    public function has(string key) -> bool;

    /**
     * Persists data in the cache, uniquely referenced by a key with an optional
     * expiration TTL time.
     */
    public function set(string key, var value, var ttl = null) -> bool;

    /**
     * Persists a set of key => value pairs in the cache, with an optional TTL.
     *
     * @phpstan-param iterable<string, mixed> $values
     */
    public function setMultiple(var values, var ttl = null) -> bool;
}
