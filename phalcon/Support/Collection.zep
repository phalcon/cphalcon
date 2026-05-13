
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support;

use ArrayAccess;
use ArrayIterator;
use Countable;
use IteratorAggregate;
use InvalidArgumentException; // @todo this will also be removed when traits are available
use JsonSerializable;
use Phalcon\Support\Collection\CollectionInterface;
use Phalcon\Support\Helper\Json\Encode;
use Phalcon\Contracts\Support\Collection as CollectionContract;
use Traversable;

/**
 * `Phalcon\Support\Collection` is a supercharged object-oriented array. It implements:
 * - [ArrayAccess](https://www.php.net/manual/en/class.arrayaccess.php)
 * - [Countable](https://www.php.net/manual/en/class.countable.php)
 * - [IteratorAggregate](https://www.php.net/manual/en/class.iteratoraggregate.php)
 * - [JsonSerializable](https://www.php.net/manual/en/class.jsonserializable.php)
 *
 * It can be used in any part of the application that needs collection of data
 * Such implementations are for instance accessing globals `$_GET`, `$_POST`
 * etc.
 *
 * @phpstan-template T
 *
 * @property array       $data
 * @property bool        $insensitive
 * @property array       $lowerKeys
 * @property bool        $strictNull
 * @property string|null $type
 */
class Collection implements
    CollectionInterface,
    Countable,
    JsonSerializable
{
    /**
     * @var array
     */
    protected data = [];

    /**
     * @var bool
     */
    protected insensitive = true;

    /**
     * @var array
     */
    protected lowerKeys = [];

    /**
     * @var bool
     */
    protected strictNull = false;

    /**
     * @var string|null
     */
    protected type = null;

    /**
     * Collection constructor.
     *
     * @phpstan-param array<int|string, mixed> $data
     */
    public function __construct(
        array data = [],
        bool insensitive = true,
        bool strictNull = false,
        string type = null
    ) {
        let this->insensitive = insensitive;
        let this->strictNull  = strictNull;
        let this->type        = type;
        this->init(data);
    }

    /**
     * Magic getter to get an element from the collection
     *
     * @param string $element
     *
     * @return mixed|null
     */
    public function __get(string! element) -> mixed
    {
        return this->get(element);
    }

    /**
     * Magic isset to check whether an element exists or not
     *
     * @param string $element
     *
     * @return bool
     */
    public function __isset(string element) -> bool
    {
        return this->has(element);
    }

    /**
     * Returns the state of the collection for serialization, including
     * configuration flags so the round-trip restores full state.
     *
     * @return array
     */
    public function __serialize() -> array
    {
        return [
            "data"        : this->data,
            "insensitive" : this->insensitive,
            "strictNull"  : this->strictNull,
            "type"        : this->type
        ];
    }

    /**
     * Magic setter to assign values to an element
     *
     * @param string $element
     * @param mixed  $value
     */
    public function __set(string element, mixed value) -> void
    {
        this->set(element, value);
    }

    /**
     * Restores the collection state. Accepts both the structured format
     * emitted by __serialize() and the legacy flat-array format for BC
     * with previously serialized data.
     *
     * @param array $data
     *
     * @return void
     */
    public function __unserialize(array data) -> void
    {
        if (isset(data["data"]) && typeof data["data"] === "array") {
            let this->insensitive = (bool) (isset(data["insensitive"]) ? data["insensitive"] : true);
            let this->strictNull  = (bool) (isset(data["strictNull"]) ? data["strictNull"] : false);
            let this->type        = isset(data["type"]) ? data["type"] : null;

            this->init(data["data"]);

            return;
        }

        this->init(data);
    }

    /**
     * Magic unset to remove an element from the collection
     *
     * @param string $element
     */
    public function __unset(string element) -> void
    {
        this->remove(element);
    }

    /**
     * Clears the internal collection
     */
    public function clear() -> void
    {
        let this->data      = [];
        let this->lowerKeys = [];
    }

    /**
     * Returns the values from a single property/method extracted from every
     * item in the collection, keyed by the original collection key.
     *
     * @param string $propertyOrMethod
     *
     * @return array<int|string, mixed>
     */
    public function column(string propertyOrMethod) -> array
    {
        var key, result, value;

        let result = [];

        for key, value in this->data {
            let result[key] = this->extractValue(value, propertyOrMethod);
        }

        return result;
    }

    /**
     * Count elements of an object
     *
     * @return int
     */
    public function count() -> int
    {
        return count(this->data);
    }

    /**
     * Invokes the callback for every item in the collection. Returns the
     * collection itself to allow chaining.
     *
     * @phpstan-param callable(T, array-key) -> mixed $callback
     *
     * @param callable $callback
     *
     * @return static
     */
    public function each(callable callback) -> <CollectionContract>
    {
        var key, value;

        for key, value in this->data {
            {callback}(value, key);
        }

        return this;
    }

    /**
     * Returns a new collection of items for which the callback returns true.
     * Keys are preserved.
     *
     * @phpstan-param  callable(T, array-key) -> bool $callback
     * @phpstan-return static<T>
     *
     * @param callable $callback
     *
     * @return static
     */
    public function filter(callable callback) -> <CollectionContract>
    {
        var key, result, value;

        let result = [];

        for key, value in this->data {
            if ({callback}(value, key)) {
                let result[key] = value;
            }
        }

        return this->cloneEmpty(result);
    }

    /**
     * Returns the first value in the collection, or null if empty.
     *
     * @phpstan-return T|null
     *
     * @return mixed
     */
    public function first() -> mixed
    {
        var key;

        if (empty(this->data)) {
            return null;
        }

        let key = array_key_first(this->data);

        return this->data[key];
    }

    /**
     * Get the element from the collection
     *
     * @phpstan-return T|mixed
     *
     * @param string      $element
     * @param mixed|null  $defaultValue
     * @param string|null $cast
     *
     * @return mixed
     */
    public function get(
        string element,
        var defaultValue = null,
        string cast = null
    ) -> mixed {
        var key, value;

        let element = this->processKey(element);

        /**
         * If the key is not set, return the default value
         */
        if unlikely true !== isset(this->lowerKeys[element]) {
            return defaultValue;
        }

        let key   = this->lowerKeys[element];
        let value = this->data[key];

        /**
         * If the key is set and is `null` then return the default
         * value also. This aligns with 3.x behavior
         */
        if unlikely (null === value && false === this->strictNull) {
            return defaultValue;
        }

        if unlikely cast {
            settype(value, cast);
        }

        return value;
    }

    /**
     * Returns the iterator of the class
     */
    public function getIterator() -> <Traversable>
    {
        return new ArrayIterator(this->data);
    }

    /**
     * Returns the keys (insensitive or not) of the collection.
     *
     * @deprecated Use {@see self::keys()} instead. Will be removed in a future major release.
     *
     * @param bool $insensitive Case-insensitive keys (default: true)
     *
     * @return array<int|string, mixed>
     */
    public function getKeys(bool insensitive = true) -> array
    {
        return this->keys(insensitive);
    }

    /**
     * Returns the configured runtime type guard, or null if none.
     *
     * @return string|null
     */
    public function getType() -> string | null
    {
        return this->type;
    }

    /**
     * Returns the values of the internal array.
     *
     * @deprecated Use {@see self::values()} instead. Will be removed in a future major release.
     *
     * @return array<int|string, mixed>
     */
    public function getValues() -> array
    {
        return this->values();
    }

    /**
     * Get the element from the collection
     *
     * @param string $element Name of the element
     *
     * @return bool
     */
    public function has(string element) -> bool
    {
        let element = this->processKey(element);

        return isset(this->lowerKeys[element]);
    }

    /**
     * Initialize internal array
     *
     * @phpstan-param array<int|string, mixed> $data
     */
    public function init(array data = []) -> void
    {
        var key, value;

        for key, value in data {
            this->setData(key, value);
        }
    }

    /**
     * Return if the collection is empty
     *
     * @return bool
     */
    public function isEmpty() -> bool
    {
        return empty(this->data);
    }

    /**
     * Specify data which should be serialized to JSON
     *
     * @link https://php.net/manual/en/jsonserializable.jsonserialize.php
     *
     * @return array<int|string, mixed>
     */
    public function jsonSerialize() -> array
    {
        return array_map(
            function (value) {
                return this->checkSerializable(value);
            },
            this->data
        );
    }

    /**
     * Returns the keys (insensitive or not) of the collection.
     *
     * @param bool $insensitive Case-insensitive keys (default: true)
     *
     * @return array<int|string, mixed>
     */
    public function keys(bool insensitive = true) -> array
    {
        if (insensitive) {
            return array_keys(this->lowerKeys);
        }

        return array_keys(this->data);
    }

    /**
     * Returns the last value in the collection, or null if empty.
     *
     * @phpstan-return T|null
     *
     * @return mixed
     */
    public function last() -> mixed
    {
        var key;

        if (empty(this->data)) {
            return null;
        }

        let key = array_key_last(this->data);

        return this->data[key];
    }

    /**
     * Returns a new collection with the callback applied to every value.
     * Keys are preserved.
     *
     * @phpstan-param  callable(T, array-key) -> mixed $callback
     * @phpstan-return static<mixed>
     *
     * @param callable $callback
     *
     * @return static
     */
    public function map(callable callback) -> <CollectionContract>
    {
        var key, result, value;

        let result = [];

        for key, value in this->data {
            let result[key] = {callback}(value, key);
        }

        return this->cloneEmpty(result);
    }

    /**
     * Whether a offset exists
     *
     * @link https://php.net/manual/en/arrayaccess.offsetexists.php
     *
     * @param mixed $element
     *
     * @return bool
     */
    public function offsetExists(mixed element) -> bool
    {
        let element = (string)element;

        return this->has(element);
    }

    /**
     * Offset to retrieve
     *
     * @link https://php.net/manual/en/arrayaccess.offsetget.php
     *
     * @param mixed $element
     *
     * @return mixed
     */
    public function offsetGet(mixed element) -> mixed
    {
        let element = (string)element;

        return this->get(element);
    }

    /**
     * Offset to set
     *
     * @link https://php.net/manual/en/arrayaccess.offsetset.php
     *
     * @param mixed $element
     * @param mixed $value
     */
    public function offsetSet(mixed element, mixed value) -> void
    {
        let element = (string)element;

        this->set(element, value);
    }

    /**
     * Offset to unset
     *
     * @link https://php.net/manual/en/arrayaccess.offsetunset.php
     *
     * @param mixed $element
     */
    public function offsetUnset(mixed element) -> void
    {
        let element = (string)element;

        this->remove(element);
    }
    /**
     * Reduces the collection to a single value using the callback. The
     * callback receives `($accumulator, $value, $key)`.
     *
     * @phpstan-param callable(mixed, T, array-key) -> mixed $callback
     *
     * @param callable $callback
     * @param mixed    $initial
     *
     * @return mixed
     */
    public function reduce(callable callback, var initial = null) -> mixed
    {
        var accumulator, key, value;

        let accumulator = initial;

        for key, value in this->data {
            let accumulator = {callback}(accumulator, value, key);
        }

        return accumulator;
    }

    /**
     * Delete the element from the collection
     *
     * @param string $element Name of the element
     */
    public function remove(string element) -> void
    {
        var value;

        if (this->has(element)) {
            let element = this->processKey(element);

            let value = this->lowerKeys[element];

            unset(this->lowerKeys[element]);
            unset(this->data[value]);
        }
    }

    /**
     * Replaces the collection data with a new array, clearing existing data first
     *
     * @phpstan-param array<int|string, mixed> $data
     */
    public function replace(array data) -> void
    {
        this->clear();
        this->init(data);
    }

    /**
     * BC - delegate to __serialize()
     *
     * @return string|null
     */
    public function serialize() -> string | null
    {
        return serialize(this->__serialize());
    }

    /**
     * Set an element in the collection
     *
     * @param string $element Name of the element
     * @param mixed  $value   Value to store for the element
     */
    public function set(string element, mixed value) -> void
    {
        this->setData(element, value);
    }

    /**
     * Returns a new collection sorted by value. Keys are preserved. When a
     * callback is supplied, `uasort` is used. Without a callback, the
     * comparison direction is controlled by the `$order` argument
     * (`SORT_ASC` or `SORT_DESC`).
     *
     * @phpstan-return static<T>
     *
     * @param callable|null $callback
     * @param int           $order
     *
     * @return static
     */
    public function sort(var callback = null, int order = 4) -> <CollectionContract>
    {
        var result;

        /**
         * @todo check the type for callable
         */
        let result = this->data;

        if (null !== callback) {
            uasort(result, callback);
        } elseif (order === 3) {
            arsort(result);
        } else {
            asort(result);
        }

        return this->cloneEmpty(result);
    }

    /**
     * Returns the object in an array format
     *
     * @phpstan-return array<array-key, T>
     *
     * @return array<int|string, mixed>
     */
    public function toArray() -> array
    {
        return this->data;
    }

    /**
     * Returns the object in a JSON format
     *
     * The following options are used if none specified for json_encode
     *
     * JSON_HEX_TAG, JSON_HEX_APOS, JSON_HEX_AMP, JSON_HEX_QUOT,
     * JSON_UNESCAPED_SLASHES, JSON_THROW_ON_ERROR
     *
     * @see https://www.ietf.org/rfc/rfc4627.txt
     *
     * @param int $options `
     *
     * @return string
     */
    public function toJson(int options = 4194383) -> string
    {
        var result;

        let result = (new Encode())->__invoke(this->jsonSerialize(), options);

        if (false === result) {
            let result = "";
        }

        return result;
    }

    /**
     * BC - delegate to __unserialize()
     *
     * @param string $data
     *
     * @return void
     */
    public function unserialize(string data) -> void
    {
        this->__unserialize(unserialize(data));
    }

    /**
     * Returns the values of the internal array.
     *
     * @return array<int|string, mixed>
     */
    public function values() -> array
    {
        return array_values(this->data);
    }

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
    public function where(string propertyOrMethod, mixed value) -> <CollectionContract>
    {
        var key, result, item;

        let result = [];

        for key, item in this->data {
            if (this->extractValue(item, propertyOrMethod) === value) {
                let result[key] = item;
            }
        }

        return this->cloneEmpty(result);
    }

    /**
     * Builds a new collection of the same concrete class, carrying over the
     * configuration (insensitivity, strict-null, type) of the current one.
     *
     * @param array<int|string, mixed> $data
     *
     * @return static
     */
    protected function cloneEmpty(array data = []) -> <CollectionContract>
    {
        var className;

        let className = get_called_class();

        return new {className}(data, this->insensitive, this->strictNull, this->type);
    }

    /**
     * Extracts a single value from an item. For arrays returns the keyed
     * entry; for objects, prefers a callable method, then a readable
     * property. Returns null when nothing matches.
     *
     * @param mixed  $item
     * @param string $propertyOrMethod
     *
     * @return mixed
     */
    protected function extractValue(var item, string propertyOrMethod) -> mixed
    {
        if (typeof item === "array") {
            return isset(item[propertyOrMethod]) ? item[propertyOrMethod] : null;
        }

        if (typeof item === "object") {
            if (method_exists(item, propertyOrMethod)) {
                return item->{propertyOrMethod}();
            }

            if (property_exists(item, propertyOrMethod)) {
                return item->{propertyOrMethod};
            }
        }

        return null;
    }

    /**
     * Checks if we need insensitive keys and if so, converts the element to
     * lowercase
     */
    protected function processKey(string element) -> string
    {
        if (true === this->insensitive) {
            return mb_strtolower(element);
        }

        return element;
    }

    /**
     * Internal method to set data
     *
     * @phpstan-param T $value
     *
     * @param string $element Name of the element
     * @param mixed  $value   Value to store for the element
     */
    protected function setData(string element, mixed value) -> void
    {
        var key;

        this->validateType(value);

        let key                  = this->processKey(element);
        let this->data[element]  = value;
        let this->lowerKeys[key] = element;
    }

    /**
     * Validates the value against the configured `$type` guard. When `$type`
     * is null this is a no-op. Scalar tokens (`int`, `string`, `bool`,
     * `float`, `array`, `object`) map to their `is_*` checks; anything else
     * is treated as a class/interface name and tested with `instanceof`.
     *
     * @param mixed $value
     *
     * @throws InvalidArgumentException
     */
    protected function validateType(var value) -> void
    {
        var ok;

        if (null === this->type) {
            return;
        }

        switch this->type {
            case "int":
                let ok = is_int(value);
                break;
            case "string":
                let ok = is_string(value);
                break;
            case "bool":
                let ok = is_bool(value);
                break;
            case "float":
                let ok = is_float(value);
                break;
            case "array":
                let ok = is_array(value);
                break;
            case "object":
                let ok = is_object(value);
                break;
            default:
                let ok = (value instanceof this->type);
        }

        if (!ok) {
            throw new InvalidArgumentException(
                "Value must be of type '" . this->type
                . "', '" . get_debug_type(value) . "' given"
            );
        }
    }

    /**
     * @param mixed $value
     */
    private function checkSerializable(var value) -> mixed
    {
        if (
            typeof value === "object" &&
            true === method_exists(value, "jsonSerialize")
        ) {
            return value->jsonSerialize();
        }

        return value;
    }
}
