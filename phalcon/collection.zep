
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

/**
 * Phalcon\Collection
 *
 * Phalcon\Collection is a supercharged object oriented array. It implements
 * ArrayAccess, Countable, IteratorAggregate, JsonSerializable, Serializable
 *
 * It can be used in any part of the application that needs collection of data
 * Such implementatins are for instance accessing globals `$_GET`, `$_POST` etc.
 */
class Collection implements \ArrayAccess, \Countable, \IteratorAggregate, \JsonSerializable, \Serializable
{
	/**
	 * @var array
	 */
	protected data = [];

	/**
	 * @var array
	 */
	protected lowerKeys = [];



	public function __construct(array! data = []) -> void
	{
		this->init(data);
	}

	/**
	 * Magic getter to get an element from the collection
	 */
	public function __get(string! element) -> var
	{
		return this->get(element);
	}

	/**
	 * Magic isset to check whether an element exists or not
	 */
	public function __isset(string! element) -> bool
	{
		return this->has(element);
	}

	/**
	 * Magic setter to assign values to an element
	 */
	public function __set(string! element, var value) -> void
	{
		this->set(element, value);
	}

	/**
	 * Magic unset to remove an element from the collection
	 */
	public function __unset(string! element) -> void
	{
		this->remove(element);
	}

	/**
	 * Clears the internal collection
	 */
	public function clear() -> void
	{
		let this->data = [];
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
	 */
	public function get(string! element, var defaultValue = null, bool insensitive = true) -> var
	{
		var value;

		if likely insensitive {
			let element = strtolower(element);
		}

		if likely fetch value, this->lowerKeys[element] {
			return this->data[value];
		}

		return defaultValue;
	}

	/**
	 * Returns the iterator of the class
	 */
	public function getIterator() -> <Traversable>
	{
		return new \ArrayIterator(this);
	}

	/**
	 * Get the element from the collection
	 */
	public function has(string! element, bool insensitive = true) -> bool
	{
		if likely insensitive {
			let element = strtolower(element);
		}

		return isset this->lowerKeys[element];
	}

	/**
	 * Initialize internal array
	 */
	public function init(array! data = []) -> void
	{
		var key, value;

		for key, value in data {
			this->set(key, value);
		}
	}

	/**
	 * Specify data which should be serialized to JSON
	 *
	 * @link https://php.net/manual/en/jsonserializable.jsonserialize.php
	 */
	public function jsonSerialize () -> array
	{
		return this->data;
	}

	/**
	 * Whether a offset exists
	 *
	 * @link https://php.net/manual/en/arrayaccess.offsetexists.php
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
	 */
	public function offsetGet(var element) -> var
	{
		let element = (string) element;

		return this->get(element);
	}

	/**
	 * Offset to set
	 *
	 * @link https://php.net/manual/en/arrayaccess.offsetset.php
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
	 */
	public function offsetUnset(var element) -> void
	{
		let element = (string) element;

		this->remove(element);
	}

	/**
	 * Delete the element from the collection
	 */
	public function remove(string! element, bool insensitive = true) -> void
	{
		var data, lowerKeys, value;


		let data      = this->data,
			lowerKeys = this->lowerKeys;

		if this->has(element) {
			if likely insensitive {
				let element = strtolower(element);
			}

			let value = lowerKeys[element];

			unset lowerKeys[element];
			unset data[value];
		}

		let this->data      = data,
			this->lowerKeys = lowerKeys;
	}

    /**
     * String representation of object
     *
     * @link https://php.net/manual/en/serializable.serialize.php
     */
    public function serialize() -> string
    {
		return serialize(this->data);
    }

	/**
	 * Set an element in the collection
	 */
	public function set(string! element, var value) -> void
	{
		var key;

		let key = strtolower(element);

		let this->data[element]  = value,
			this->lowerKeys[key] = element;
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
	 * JSON_HEX_TAG, JSON_HEX_APOS, JSON_HEX_AMP, JSON_HEX_QUOT, JSON_UNESCAPED_SLASHES
	 *
	 * @see https://www.ietf.org/rfc/rfc4627.txt
	 */
	public function toJson(int options = 74) -> string
	{
		return json_encode(this->data, options);
	}

    /**
     * Constructs the object
     *
     * @link https://php.net/manual/en/serializable.unserialize.php
     */
    public function unserialize(var serialized) -> void
    {
		var data;

		let serialized = (string) serialized,
			data       = unserialize(serialized);

		this->init(data);
    }
}
