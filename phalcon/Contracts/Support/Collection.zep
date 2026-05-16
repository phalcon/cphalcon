
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Support;

use ArrayAccess;
use IteratorAggregate;
use Phalcon\Support\Collection\CollectionInterface;

/**
 * Canonical contract for Phalcon\Support\Collection.
 *
 * @phpstan-template T
 *
 * @extends ArrayAccess<int|string, mixed>
 * @extends IteratorAggregate<int|string, mixed>
 */
interface Collection extends ArrayAccess, IteratorAggregate
{
    /**
     * @param string $element
     *
     * @return mixed
     */
    public function __get(string element) -> mixed;

    /**
     * @param string $element
     *
     * @return bool
     */
    public function __isset(string element) -> bool;

    /**
     * @param string $element
     * @param mixed  $value
     */
    public function __set(string element, mixed value) -> void;

    /**
     * @param string $element
     */
    public function __unset(string element) -> void;

    /**
     * Clears the internal collection.
     */
    public function clear() -> void;

    /**
     * Returns the values from a single property/method extracted from every
     * item in the collection, keyed by the original collection key.
     *
     * @param string $propertyOrMethod
     *
     * @return array<int|string, mixed>
     */
    public function column(string propertyOrMethod) -> array;

    /**
     * Invokes the callback for every item in the collection.
     *
     * @phpstan-param callable(T, array-key): mixed $callback
     *
     * @param callable $callback
     *
     * @return static
     */
    public function each(callable callback) -> <Collection>;

    /**
     * Returns a new collection of items for which the callback returns true.
     *
     * @phpstan-param  callable(T, array-key): bool $callback
     * @phpstan-return static<T>
     *
     * @param callable $callback
     *
     * @return static
     */
    public function filter(callable callback) -> <CollectionInterface>;

    /**
     * Returns the first value in the collection or null when empty.
     *
     * @phpstan-return T|null
     *
     * @return mixed
     */
    public function first() -> mixed;

    /**
     * Returns an element from the collection.
     *
     * @param string      $element
     * @param mixed       $defaultValue
     * @param string|null $cast
     *
     * @return mixed
     */
    public function get(
        string element,
        mixed defaultValue = null,
        string cast = null
    ) -> mixed;

    /**
     * Returns the keys (insensitive or not) of the collection.
     *
     * @deprecated Use {@see self::keys()} instead. Will be removed in a future major release.
     *
     * @param bool $insensitive
     *
     * @return array<int|string, mixed>
     */
    public function getKeys(bool insensitive = true) -> array;

    /**
     * Returns the configured runtime type guard, or null when not set.
     *
     * @return string|null
     */
    public function getType() -> string | null;

    /**
     * Returns the values of the internal array.
     *
     * @deprecated Use {@see self::values()} instead. Will be removed in a future major release.
     *
     * @return array<int|string, mixed>
     */
    public function getValues() -> array;

    /**
     * Checks whether an element exists in the collection.
     *
     * @param string $element
     *
     * @return bool
     */
    public function has(string element) -> bool;

    /**
     * Initializes the internal array.
     *
     * @param array<int|string, mixed> $data
     */
    public function init(array data = []) -> void;

    /**
     * Returns true when the collection has no entries.
     *
     * @return bool
     */
    public function isEmpty() -> bool;

    /**
     * Returns the keys (insensitive or not) of the collection.
     *
     * @param bool $insensitive
     *
     * @return array<int|string, mixed>
     */
    public function keys(bool insensitive = true) -> array;

    /**
     * Returns the last value in the collection or null when empty.
     *
     * @phpstan-return T|null
     *
     * @return mixed
     */
    public function last() -> mixed;

    /**
     * Returns a new collection with the callback applied to every value.
     *
     * @phpstan-param callable(T, array-key): mixed $callback
     *
     * @param callable $callback
     *
     * @return static
     */
    public function map(callable callback) -> <CollectionInterface>;

    /**
     * Reduces the collection to a single value using the callback.
     *
     * @phpstan-param callable(mixed, T, array-key): mixed $callback
     *
     * @param callable $callback
     * @param mixed    $initial
     *
     * @return mixed
     */
    public function reduce(callable callback, mixed initial = null) -> mixed;

    /**
     * Removes the element from the collection.
     *
     * @param string $element
     */
    public function remove(string element) -> void;

    /**
     * Replaces the collection data with a new array, clearing first.
     *
     * @param array<int|string, mixed> $data
     */
    public function replace(array data) -> void;

    /**
     * Stores an element in the collection.
     *
     * @phpstan-param T $value
     *
     * @param string $element
     * @param mixed  $value
     */
    public function set(string element, mixed value) -> void;

    /**
     * Returns a new collection sorted by value, preserving keys.
     *
     * @phpstan-return static<T>
     *
     * @param callable|null $callback
     * @param int           $order
     *
     * @return static
     */
    public function sort(callable callback = null, int order = 4) -> <CollectionInterface>;

    /**
     * Returns the collection as an array.
     *
     * @phpstan-return array<array-key, T>
     *
     * @return array<int|string, mixed>
     */
    public function toArray() -> array;

    /**
     * Returns the collection serialized as a JSON string.
     *
     * @param int $options
     *
     * @return string
     */
    public function toJson(int options = 4194383) -> string;

    /**
     * Returns the values of the internal array.
     *
     * @return array<int|string, mixed>
     */
    public function values() -> array;

    /**
     * Returns a new collection containing only the items whose
     * `propertyOrMethod` strictly equals `$value`.
     *
     * @phpstan-return static<T>
     *
     * @param string $propertyOrMethod
     * @param mixed  $value
     *
     * @return static
     */
    public function where(string propertyOrMethod, mixed value) -> <CollectionInterface>;
}
