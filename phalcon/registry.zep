
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\Collection;

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
final class Registry extends Collection
{
	/**
	 * Constructor 
	 */
	public final function __construct(array! data = null) -> void
	{
		parent::__construct(data);
	}

	/**
	 * Magic getter to get an element from the collection
	 */
	public final function __get(string! element) -> var
	{
		return parent::get(element);
	}

	/**
	 * Magic isset to check whether an element exists or not
	 */
	public final function __isset(string! element) -> bool
	{
		return parent::has(element);
	}

	/**
	 * Magic setter to assign values to an element
	 */
	public final function __set(string! element, var value) -> void
	{
		parent::set(element, value);
	}

	/**
	 * Magic unset to remove an element from the collection
	 */
	public final function __unset(string! element) -> void
	{
		parent::remove(element);
	}

	/**
	 * Clears the internal collection
	 */
	public final function clear() -> void
	{
		parent::clear();
	}

	/**
	 * Count elements of an object
	 *
	 * @link https://php.net/manual/en/countable.count.php
	 */
	public final function count() -> int
	{
		return parent::count();
	}

	/**
	 * Get the element from the collection
	 */
	public final function get(string! element, var defaultValue = null, bool insensitive = true) -> var | bool
	{
		return parent::get(element, defaultValue, insensitive);
	}

	/**
	 * Returns the iterator of the class
	 */
	public final function getIterator() -> <Traversable>
	{
		return parent::getIterator();
	}

	/**
	 * Get the element from the collection
	 */
	public final function has(string! element, bool insensitive = true) -> bool
	{
		return parent::has(element, insensitive);
	}

	/**
	 * Initialize internal array
	 */
	public final function init(array! data = []) -> void
	{
		parent::init(data);
	}

	/**
	 * Specify data which should be serialized to JSON
	 *
	 * @link https://php.net/manual/en/jsonserializable.jsonserialize.php
	 */
	public final function jsonSerialize () -> array
	{
		return parent::jsonSerialize();
	}

	/**
	 * Whether a offset exists
	 *
	 * @link https://php.net/manual/en/arrayaccess.offsetexists.php
	 */
	public final function offsetExists(var element) -> bool
	{
		return parent::has(element);
	}

	/**
	 * Offset to retrieve
	 *
	 * @link https://php.net/manual/en/arrayaccess.offsetget.php
	 */
	public final function offsetGet(var element) -> var
	{
		return parent::get(element);
	}

	/**
	 * Offset to set
	 *
	 * @link https://php.net/manual/en/arrayaccess.offsetset.php
	 */
	public final function offsetSet(var element, var value) -> void
	{
		parent::set(element, value);
	}

	/**
	 * Offset to unset
	 *
	 * @link https://php.net/manual/en/arrayaccess.offsetunset.php
	 */
	public final function offsetUnset(var element) -> void
	{
		parent::remove(element);
	}

	/**
	 * Delete the element from the collection
	 */
	public final function remove(string! element, bool insensitive = true) -> void
	{
		parent::remove(element, insensitive);
	}

    /**
     * String representation of object
     *
     * @link https://php.net/manual/en/serializable.serialize.php
     */
    public final function serialize() -> string
    {
		return parent::serialize();
    }

	/**
	 * Set an element in the collection
	 */
	public final function set(string! element, var value) -> void
	{
		parent::set(element, value);
	}

	/**
	 * Returns the object in an array format
	 */
	public final function toArray() -> array
	{
		return parent::toArray();
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
	public final function toJson(int options = 74) -> string
	{
		return parent::toJson(options);
	}

    /**
     * Constructs the object
     *
     * @link https://php.net/manual/en/serializable.unserialize.php
     */
    public final function unserialize(var serialized) -> void
    {
		parent::unserialize(serialized);
    }
}
