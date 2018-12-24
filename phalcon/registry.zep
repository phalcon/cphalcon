
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
 * Phalcon\Registry
 *
 * A registry is a container for storing objects and values in the application space.
 * By storing the value in a registry, the same object is always available throughout
 * your application.
 *
 *<code>
 * $registry = new \Phalcon\Registry();
 *
 * // Set value
 * $registry->something = "something";
 * // or
 * $registry["something"] = "something";
 *
 * // Get value
 * $value = $registry->something;
 * // or
 * $value = $registry["something"];
 *
 * // Check if the key exists
 * $exists = isset($registry->something);
 * // or
 * $exists = isset($registry["something"]);
 *
 * // Unset
 * unset($registry->something);
 * // or
 * unset($registry["something"]);
 *</code>
 *
 * In addition to ArrayAccess, Phalcon\Registry also implements Countable
 * (count($registry) will return the number of elements in the registry),
 * Serializable and Iterator (you can iterate over the registry
 * using a foreach loop) interfaces. For PHP 5.4 and higher, JsonSerializable
 * interface is implemented.
 *
 * Phalcon\Registry is very fast (it is typically faster than any userspace
 * implementation of the registry); however, this comes at a price:
 * Phalcon\Registry is a final class and cannot be inherited from.
 *
 * Though Phalcon\Registry exposes methods like __get(), offsetGet(), count() etc,
 * it is not recommended to invoke them manually (these methods exist mainly to
 * match the interfaces the registry implements): $registry->__get("property")
 * is several times slower than $registry->property.
 *
 * Internally all the magic methods (and interfaces except JsonSerializable)
 * are implemented using object handlers or similar techniques: this allows
 * to bypass relatively slow method calls.
 */
final class Registry implements \ArrayAccess, \Countable, \Iterator
{
	protected _data;

	/**
	 * Registry constructor
	 */
	public final function __construct()
	{
		let this->_data = [];
	}

	/**
	 * Checks if the element is present in the registry
	 */
	public final function offsetExists(var offset) -> bool
	{
		return isset this->_data[offset];
	}

	/**
	 * Returns an index in the registry
	 */
	public final function offsetGet(var offset) -> var
	{
		return this->_data[offset];
	}

	/**
	 * Sets an element in the registry
	 */
	public final function offsetSet(var offset, var value) -> void
	{
		let this->_data[offset] = value;
	}

	/**
	 * Unsets an element in the registry
	 */
	public final function offsetUnset(var offset) -> void
	{
		unset this->_data[offset];
	}

	/**
	 * Checks how many elements are in the register
	 */
	public final function count() -> int
	{
		return count(this->_data);
	}

	/**
	 * Moves cursor to next row in the registry
	 */
	public final function next() -> void
	{
		next(this->_data);
	}

	/**
	 * Gets pointer number of active row in the registry
	 */
	public final function key() -> int
	{
		return key(this->_data);
	}

	/**
	 * Rewinds the registry cursor to its beginning
	 */
	public final function rewind() -> void
	{
		reset(this->_data);
	}

	/**
	 * Checks if the iterator is valid
	 */
	public function valid() -> bool
	{
		return key(this->_data) !== null;
	}

	/**
	 * Obtains the current value in the internal iterator
	 */
	public function current()
	{
		return current(this->_data);
	}

	/**
	 * Sets an element in the registry
	 */
	public final function __set(string! key, var value) -> void
	{
		this->offsetSet(key, value);
	}

	/**
	 * Returns an index in the registry
	 */
	public final function __get(string! key) -> var
	{
		return this->offsetGet(key);
	}

	public final function __isset(string! key) -> bool
	{
		return this->offsetExists(key);
	}

	public final function __unset(string! key) -> void
	{
		this->offsetUnset(key);
	}
}
