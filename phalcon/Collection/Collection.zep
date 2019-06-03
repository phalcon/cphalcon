
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Collection;

use ArrayAccess;
use ArrayIterator;
use Countable;
use IteratorAggregate;
use JsonSerializable;
use Serializable;
use Traversable;

/**
 * Phalcon\Collection\Collection
 *
 * Phalcon\Collection\Collection is a supercharged object oriented array. It
 * implements ArrayAccess, Countable, IteratorAggregate, JsonSerializable,
 * Serializable
 *
 * It can be used in any part of the application that needs collection of data
 * Such implementations are for instance accessing globals `$_GET`, `$_POST`
 * etc.
 */
class Collection implements
    ArrayAccess,
    Countable,
    IteratorAggregate,
    JsonSerializable,
    Serializable
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
     * Collection constructor.
     *
     * @param array $data
     * @param bool  $insensitive
     */
    public function __construct(array data = [], bool insensitive = true)
    {
        let this->insensitive = insensitive;
        this->init(data);
    }

    /**
     * Magic getter to get an element from the collection
     *
     * @param string $element
     *
     * @return mixed
     */
    public function __get(string element) -> var
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
     * Magic setter to assign values to an element
     *
     * @param string $element
     * @param mixed  $value
     */
    public function __set(string element, value) -> void
    {
        this->set(element, value);
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
        let this->data      = [],
            this->lowerKeys = [];
    }

    /**
     * Count elements of an object
     *
     * @link https://php.net/manual/en/countable.count.php
     */
    public function count() -> int
    {
        return count(this->data);
    }

    /**
     * Get the element from the collection
     *
     * @param string     $element
     * @param mixed|null $defaultValue
     *
     * @return mixed
     */
    public function get(string element, defaultValue = null) -> var
    {
        var key;

        if likely this->insensitive {
            let element = element->lower();
        }

        if likely isset this->lowerKeys[element] {
            let key = this->lowerKeys[element];

            return this->data[key];
        }

        return defaultValue;
    }

    /**
     * Returns the iterator of the class
     */
    public function getIterator() -> <Traversable>
    {
        return new ArrayIterator(this->data);
    }

    /**
     * Get the element from the collection
     *
     * @param string $element
     *
     * @return bool
     */
    public function has(string element) -> bool
    {
        if likely this->insensitive {
            let element = element->lower();
        }

        return isset this->lowerKeys[element];
    }

    /**
     * Initialize internal array
     *
     * @param array $data
     */
    public function init(array data = []) -> void
    {
        var key, value;

        for key, value in data {
            this->setData(key, value);
        }
    }

    /**
     * Specify data which should be serialized to JSON
     *
     * @link https://php.net/manual/en/jsonserializable.jsonserialize.php
     */
    public function jsonSerialize() -> array
    {
        return this->data;
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
    public function offsetExists(var element) -> bool
    {
        let element = (string) element;

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
    public function offsetGet(var element)
    {
        let element = (string) element;

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
    public function offsetSet(var element, var value) -> void
    {
        let element = (string) element;

        this->set(element, value);
    }

    /**
     * Offset to unset
     *
     * @link https://php.net/manual/en/arrayaccess.offsetunset.php
     *
     * @param mixed $element
     */
    public function offsetUnset(var element) -> void
    {
        let element = (string) element;

        this->remove(element);
    }

    /**
     * Delete the element from the collection
     *
     * @param string $element
     */
    public function remove(string element) -> void
    {
        var key;
        array lowerKeys, data;

        if likely this->has(element) {
            if likely this->insensitive {
                let element = element->lower();
            }

            let data      = this->data,
                lowerKeys = this->lowerKeys,
                key       = lowerKeys[element];

            unset lowerKeys[element];
            unset data[key];

            let this->data      = data,
                this->lowerKeys = lowerKeys;
        }
    }

    /**
     * Set an element in the collection
     *
     * @param string $element
     * @param        $value
     */
    public function set(string element, var value) -> void
    {
        this->setData(element, value);
    }

    /**
     * String representation of object
     *
     * @link https://php.net/manual/en/serializable.serialize.php
     */
    public function serialize() -> string
    {
        return serialize(this->toArray());
    }

    /**
     * Returns the object in an array format
     */
    public function toArray() -> array
    {
        return this->data;
    }

    /**
     * Returns the object in a JSON format
     *
     * The default string uses the following options for json_encode
     *
     * JSON_HEX_TAG, JSON_HEX_APOS, JSON_HEX_AMP, JSON_HEX_QUOT,
     * JSON_UNESCAPED_SLASHES
     *
     * @see https://www.ietf.org/rfc/rfc4627.txt
     *
     * @param int $options
     *
     * @return string
     */
    public function toJson(int options = 79) -> string
    {
        return json_encode(this->toArray(), options);
    }

    /**
     * Constructs the object
     *
     * @link https://php.net/manual/en/serializable.unserialize.php
     *
     * @param string $serialized
     */
    public function unserialize(var serialized) -> void
    {
        var data;

        let serialized = (string) serialized,
            data       = unserialize(serialized);

        this->init(data);
    }

    /**
     * Internal method to set data
     *
     * @param string $element
     * @param mixed  $value
     */
    protected function setData(string element, var value) -> void
    {
        var key;

        let key = (true === this->insensitive) ? element->lower() : element;

        let this->data[element]  = value,
            this->lowerKeys[key] = element;
    }
}
