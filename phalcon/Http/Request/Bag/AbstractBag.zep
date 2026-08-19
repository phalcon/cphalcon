
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Request\Bag;

use ArrayAccess;
use ArrayIterator;
use Countable;
use IteratorAggregate;
use Phalcon\Contracts\Http\HttpTypes;
use Phalcon\Http\Request\Exceptions\NullKeyException;
use Traversable;

/**
 * Shared base for the HTTP request bags. A bag is a string- or integer-keyed
 * value store backed by a raw array, exposing `get/has/set/remove/all` plus
 * typed readers for cast-with-default access.
 *
 * Two protected hooks (`normalizeKey`, `normalizeItems`) let subclasses
 * change key handling without restating the surface.
 *
 * The ArrayAccess append form (`$bag[] = $value`) is rejected with a
 * NullKeyException: the append form supplies no explicit key, so the write
 * could never be addressed by the caller.
 *
 * @phpstan-import-type http_bag_items from HttpTypes
 *
 * @implements ArrayAccess<int|string, mixed>
 * @implements IteratorAggregate<int|string, mixed>
 */
abstract class AbstractBag implements ArrayAccess, Countable, IteratorAggregate
{
    /**
     * @phpstan-var http_bag_items
     */
    protected array items = [];

    /**
     * AbstractBag constructor.
     *
     * @phpstan-param http_bag_items $items
     */
    public function __construct(array items = [])
    {
        let this->items = this->normalizeItems(items);
    }

    /**
     * Returns all the elements of the bag
     *
     * @phpstan-return http_bag_items
     */
    public function all() -> array
    {
        return this->items;
    }

    /**
     * Returns the number of elements in the bag
     */
    public function count() -> int
    {
        return count(this->items);
    }

    /**
     * Returns an element of the bag, or the default value if it is not set
     *
     * @param int|string $key
     */
    public function get(var key, var defaultValue = null) -> mixed
    {
        var value;

        let key = this->normalizeKey(key);

        if fetch value, this->items[key] {
            if null !== value {
                return value;
            }
        }

        return defaultValue;
    }

    /**
     * Returns an element of the bag as an array. The default value is
     * returned if the element is not set or is not an array
     *
     * @param int|string $key
     *
     * @phpstan-param  http_bag_items $defaultValue
     * @phpstan-return http_bag_items
     */
    public function getArray(var key, array defaultValue = []) -> array
    {
        var value;

        let key = this->normalizeKey(key);

        if fetch value, this->items[key] {
            if typeof value === "array" {
                return value;
            }
        }

        return defaultValue;
    }

    /**
     * Returns an element of the bag cast to bool, or the default value if
     * it is not set
     *
     * @param int|string $key
     */
    public function getBool(var key, bool defaultValue = false) -> bool
    {
        var value;

        let key = this->normalizeKey(key);

        if fetch value, this->items[key] {
            if null !== value {
                return (bool) value;
            }
        }

        return defaultValue;
    }

    /**
     * Returns an element of the bag cast to float, or the default value if
     * it is not set
     *
     * @param int|string $key
     */
    public function getFloat(var key, float defaultValue = 0.0) -> float
    {
        var value;

        let key = this->normalizeKey(key);

        if fetch value, this->items[key] {
            if null !== value {
                return (double) value;
            }
        }

        return defaultValue;
    }

    /**
     * Returns an element of the bag cast to int, or the default value if
     * it is not set
     *
     * @param int|string $key
     */
    public function getInt(var key, int defaultValue = 0) -> int
    {
        var value;

        let key = this->normalizeKey(key);

        if fetch value, this->items[key] {
            if null !== value {
                return (int) value;
            }
        }

        return defaultValue;
    }

    /**
     * Returns the iterator of the bag
     *
     * @return Traversable<int|string, mixed>
     */
    public function getIterator() -> <Traversable>
    {
        return new ArrayIterator(this->items);
    }

    /**
     * Returns an element of the bag cast to string, or the default value if
     * it is not set
     *
     * @param int|string $key
     */
    public function getString(var key, string defaultValue = "") -> string
    {
        var value;

        let key = this->normalizeKey(key);

        if fetch value, this->items[key] {
            if null !== value {
                return (string) value;
            }
        }

        return defaultValue;
    }

    /**
     * Checks whether an element exists in the bag
     *
     * @param int|string $key
     */
    public function has(var key) -> bool
    {
        return array_key_exists(this->normalizeKey(key), this->items);
    }

    /**
     * Whether an offset exists
     */
    public function offsetExists(mixed offset) -> bool
    {
        return this->has((string) offset);
    }

    /**
     * Offset to retrieve
     */
    public function offsetGet(mixed offset) -> mixed
    {
        return this->get((string) offset);
    }

    /**
     * Offset to set
     * @throws NullKeyException When the offset is null (append form)
     */
    public function offsetSet(mixed offset, mixed value) -> void
    {
        if null === offset {
            throw new NullKeyException();
        }

        this->set((string) offset, value);
    }

    /**
     * Offset to unset
     */
    public function offsetUnset(mixed offset) -> void
    {
        this->remove((string) offset);
    }

    /**
     * Removes an element from the bag
     *
     * @param int|string $key
     */
    public function remove(var key) -> void
    {
        let key = this->normalizeKey(key);

        unset(this->items[key]);
    }

    /**
     * Sets an element in the bag
     *
     * @param int|string $key
     */
    public function set(var key, mixed value) -> void
    {
        let key = this->normalizeKey(key);

        let this->items[key] = value;
    }

    /**
     * Normalizes the items at construction time. Identity in the base;
     * subclasses can override it to normalize keys
     *
     * @phpstan-param  http_bag_items $items
     * @phpstan-return http_bag_items
     */
    protected function normalizeItems(array items) -> array
    {
        return items;
    }

    /**
     * Normalizes a key for lookups and writes. Identity in the base;
     * subclasses can override it to change key handling
     */
    protected function normalizeKey(var key) -> string
    {
        if typeof key === "int" || typeof key === "string" {
            return key;
        }
        
        return (string) key;
    }
}
