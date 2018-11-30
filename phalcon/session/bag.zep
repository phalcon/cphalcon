/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session;

use Phalcon\Di;
use Phalcon\DiInterface;
use Phalcon\Di\InjectionAwareInterface;

/**
 * Phalcon\Session\Bag
 *
 * This component helps to separate session data into "namespaces". Working by this way
 * you can easily create groups of session variables into the application
 *
 * <code>
 * $user = new \Phalcon\Session\Bag("user");
 *
 * $user->name = "Kimbra Johnson";
 * $user->age  = 22;
 * </code>
 */
class Bag implements InjectionAwareInterface, BagInterface, \IteratorAggregate, \ArrayAccess, \Countable
{

	protected _dependencyInjector;

	protected _data;

	protected _initialized = false;

	protected _name = null;

	protected _session;

	/**
	 * Phalcon\Session\Bag constructor
	 */
	public function __construct(string! name)
	{
		let this->_name = name;
	}

	/**
	 * Magic getter to obtain values from the session bag
	 *
	 *<code>
	 * echo $user->name;
	 *</code>
	 */
	public function __get(string! property) -> var
	{
		return this->get(property);
	}

	/**
	 * Magic isset to check whether a property is defined in the bag
	 *
	 *<code>
	 * var_dump(
	 *     isset($user["name"])
	 * );
	 *</code>
	 */
	public function __isset(string! property) -> bool
	{
		return this->has(property);
	}

	/**
	 * Magic setter to assign values to the session bag
	 *
	 *<code>
	 * $user->name = "Kimbra";
	 *</code>
	 */
	public function __set(string! property, var value)
	{
		this->set(property, value);
	}

	/**
	 * Magic unset to remove items using the array syntax
	 *
	 *<code>
	 * unset($user["name"]);
	 *</code>
	 */
	public function __unset(string! property) -> bool
	{
		return this->remove(property);
	}

	/**
	 * Return length of bag
	 *
	 *<code>
	 * echo $user->count();
	 *</code>
	 */
	public final function count() -> int
	{
		if this->_initialized === false {
			this->initialize();
		}
		return count(this->_data);
	}

	/**
	 * Destroys the session bag
	 *
	 *<code>
	 * $user->destroy();
	 *</code>
	 */
	public function destroy()
	{
		if this->_initialized === false {
			this->initialize();
		}
		let this->_data = [];
		this->_session->remove(this->_name);
	}

	/**
	 * Obtains a value from the session bag optionally setting a default value
	 *
	 *<code>
	 * echo $user->get("name", "Kimbra");
	 *</code>
	 */
	public function get(string! property, var defaultValue = null)
	{
		var value;

		/**
		 * Check first if the bag is initialized
		 */
		if this->_initialized === false {
			this->initialize();
		}

		/**
		 * Retrieve the data
		 */
		if fetch value, this->_data[property] {
			return value;
		}

		return defaultValue;
	}

	/**
	 * Returns the DependencyInjector container
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Returns the bag iterator
	 */
	public final function getIterator() -> <\ArrayIterator>
	{
		if this->_initialized === false {
			this->initialize();
		}

		return new \ArrayIterator(this->_data);
	}

	/**
	 * Check whether a property is defined in the internal bag
	 *
	 *<code>
	 * var_dump(
	 *     $user->has("name")
	 * );
	 *</code>
	 */
	public function has(string! property) -> bool
	{
		if this->_initialized === false {
			this->initialize();
		}

		return isset this->_data[property];
	}

	/**
	 * Initializes the session bag. This method must not be called directly, the
	 * class calls it when its internal data is accessed
	 */
	public function initialize()
	{
		var session, dependencyInjector, data;

		let session = this->_session;
		if typeof session != "object" {

			let dependencyInjector = this->_dependencyInjector;
			if typeof dependencyInjector != "object" {
				let dependencyInjector = Di::getDefault();
				if typeof dependencyInjector != "object" {
					throw new Exception("A dependency injection object is required to access the 'session' service");
				}
			}

			let session = dependencyInjector->getShared("session"),
				this->_session = session;
		}

		let data = session->get(this->_name);
		if typeof data != "array" {
			let data = [];
		}

		let this->_data = data;
		let this->_initialized = true;
	}

	public final function offsetExists(var property) -> bool
	{
		return this->has(property);
	}

	public final function offsetGet(var property) -> var
	{
		return this->get(property);
	}

	public final function offsetSet(var property, var value)
	{
		return this->set(property, value);
	}

	public final function offsetUnset(var property)
	{
		return this->remove(property);
	}

	/**
	 * Removes a property from the internal bag
	 *
	 *<code>
	 * $user->remove("name");
	 *</code>
	 */
	public function remove(string! property) -> bool
	{
		if this->_initialized === false {
			this->initialize();
		}

		var data;

		let data = this->_data;
		if isset data[property] {
			unset data[property];
			this->_session->set(this->_name, data);
			let this->_data = data;
			return true;
		}

		return false;
	}

	/**
	 * Sets a value in the session bag
	 *
	 *<code>
	 * $user->set("name", "Kimbra");
	 *</code>
	 */
	public function set(string! property, var value)
	{
		if this->_initialized === false {
			this->initialize();
		}

		let this->_data[property] = value;
		this->_session->set(this->_name, this->_data);
	}

	/**
	 * Sets the DependencyInjector container
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}
}
