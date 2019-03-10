
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
 * Countable, ArrayAccess, Serializable and JsonSerializable.
 *
 * It can be used in any part of the application that needs collection of data
 * Such implementatins are for instance accessing globals `$_GET`, `$_POST` etc.
 */
class Collection implements \ArrayAccess, \Countable, \Serializable, \JsonSerializable
{
	/**
	 * @var array
	 */
	private data = [];

	public function __construct(array! data = null) -> void
	{
		if typeof data === "array" {
			this->init(data);
		}
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
	public function get(var key) -> var | bool
	{
		var value;
		array data;

		let data = this->data;

		if fetch value, data[key] {
			return value;
		}

		return false;
	}

	public function delete(var key) -> void
	{
		array data;

		let data = this->data;

		unset(data[key]);

		this->init(data);
	}

	public function set(var key, var value) -> void
	{
		array data;

		let data      = this->data,
			data[key] = value;

		this->init(data);
	}

	/**
	 * Initialize internal array
	 */
	public function init(array! data = [])
	{
		let this->data = data;
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
	public function offsetExists(var offset) -> bool
	{
		return isset(this->data[offset]);
	}

	/**
	 * Offset to retrieve
	 *
	 * @link https://php.net/manual/en/arrayaccess.offsetget.php
	 */
	public function offsetGet(var key) -> var
	{
		return this->get(key);
	}

	/**
	 * Offset to set
	 *
	 * @link https://php.net/manual/en/arrayaccess.offsetset.php
	 */
	public function offsetSet(var key, var value) -> void
	{
		this->set(key, value);
	}

	/**
	 * Offset to unset
	 *
	 * @link https://php.net/manual/en/arrayaccess.offsetunset.php
	 */
	public function offsetUnset(var key) -> void
	{
		this->delete(key);
	}

    /**
     * String representation of object
     *
     * @link https://php.net/manual/en/serializable.serialize.php
     */
    public function serialize() -> string
    {
		array data;

		let data = this->data;

		return serialize(data);
    }

    /**
     * Constructs the object
     *
     * @link https://php.net/manual/en/serializable.unserialize.php
     */
    public function unserialize(var serialized) -> void
    {
		var data;

		let data = unserialize(serialized);

		this->init(data);
    }
}
