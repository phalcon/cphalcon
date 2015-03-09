
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Session;

use Phalcon\DiInterface;
use Phalcon\Di\InjectionAwareInterface;

/**
 * Phalcon\Session\Bag
 *
 * This component helps to separate session data into "namespaces". Working by this way
 * you can easily create groups of session variables into the application
 *
 *<code>
 *	$user = new \Phalcon\Session\Bag('user');
 *	$user->name = "Kimbra Johnson";
 *	$user->age = 22;
 *</code>
 */
class Bag implements InjectionAwareInterface, BagInterface
{

	protected _dependencyInjector;

	protected _name = null;

	protected _data;

	protected _initalized = false;

	protected _session;

	/**
	 * Phalcon\Session\Bag constructor
	 *
	 * @param string name
	 */
	public function __construct(string! name)
	{
		let this->_name = name;
	}

	/**
	 * Sets the DependencyInjector container
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the DependencyInjector container
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Initializes the session bag. This method must not be called directly, the class calls it when its internal data is accesed
	 */
	public function initialize()
	{
		var session, dependencyInjector, data;

		let session = this->_session;
		if typeof session != "object" {

			let dependencyInjector = this->_dependencyInjector;
			if typeof dependencyInjector != "object" {
				let dependencyInjector = \Phalcon\DI::getDefault();
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
		let this->_initalized = true;
	}

	/**
	 * Destroyes the session bag
	 *
	 *<code>
	 * $user->destroy();
	 *</code>
	 */
	public function destroy()
	{
		if this->_initalized === false {
			this->initialize();
		}
		this->_session->remove(this->_name);
	}

	/**
	 * Sets a value in the session bag
	 *
	 *<code>
	 * $user->set('name', 'Kimbra');
	 *</code>
	 *
	 * @param string property
	 * @param string value
	 */
	public function set(string! property, value)
	{
		if this->_initalized === false {
			this->initialize();
		}
		let this->_data[property] = value;
		this->_session->set(this->_name, this->_data);
	}

	/**
	 * Magic setter to assign values to the session bag
	 *
	 *<code>
	 * $user->name = "Kimbra";
	 *</code>
	 *
	 * @param string property
	 * @param string value
	 */
	public function __set(string! property, value)
	{
		this->set(property, value);
	}

	/**
	 * Obtains a value from the session bag optionally setting a default value
	 *
	 *<code>
	 * echo $user->get('name', 'Kimbra');
	 *</code>
	 *
	 * @param string property
	 * @param string defaultValue
	 * @return mixed
	 */
	public function get(string! property, defaultValue = null)
	{
		var value;

		/**
		 * Check first if the bag is initialized
		 */
		if this->_initalized === false {
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
	 * Magic getter to obtain values from the session bag
	 *
	 *<code>
	 * echo $user->name;
	 *</code>
	 *
	 * @param string property
	 * @return mixed
	 */
	public function __get(string! property)
	{
		return this->get(property);
	}

	/**
	 * Check whether a property is defined in the internal bag
	 *
	 *<code>
	 * var_dump($user->has('name'));
	 *</code>
	 *
	 * @param string property
	 * @return boolean
	 */
	public function has(string! property) -> boolean
	{
		if this->_initalized === false {
			this->initialize();
		}

		return isset this->_data[property];
	}

	/**
	 * Magic isset to check whether a property is defined in the bag
	 *
	 *<code>
	 * var_dump(isset($user['name']));
	 *</code>
	 *
	 * @param string property
	 * @return boolean
	 */
	public function __isset(string! property) -> boolean
	{
		return this->has(property);
	}

	/**
	 * Removes a property from the internal bag
	 *
	 *<code>
	 * $user->remove('name');
	 *</code>
	 *
	 * @param string property
	 * @return boolean
	 */
	public function remove(string! property) -> boolean
	{
		if isset this->_data[property] {
			unset this->_data[property];
			this->_session->set(this->_name, this->_data);
			return true;
		}
		return false;
	}

	/**
	 * Magic unset to remove items using the array syntax
	 *
	 *<code>
	 * unset($user['name']);
	 *</code>
	 *
	 * @param string property
	 * @return boolean
	 */
	public function __unset(string! property) -> boolean
	{
		return this->remove(property);
	}

}
