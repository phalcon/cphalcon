
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Di;

use Phalcon\DiInterface;
use Phalcon\Di\Exception;
use Phalcon\Di\ServiceInterface;
use Phalcon\Di\Service\Builder;

/**
 * Phalcon\Di\Service
 *
 * Represents individually a service in the services container
 *
 *<code>
 * $service = new \Phalcon\Di\Service('request', 'Phalcon\Http\Request');
 * $request = service->resolve();
 *<code>
 *
 */
class Service implements ServiceInterface
{

	protected _name;

	protected _definition;

	protected _shared = false;

	protected _resolved = false;

	protected _sharedInstance;

	/**
	 * Phalcon\Di\Service
	 *
	 * @param string name
	 * @param mixed definition
	 * @param boolean shared
	 */
	public final function __construct(string! name, definition, boolean shared = false)
	{
		let this->_name = name,
			this->_definition = definition,
			this->_shared = shared;
	}

	/**
	 * Returns the service's name
	 */
	public function getName() -> string
	{
		return this->_name;
	}

	/**
	 * Sets if the service is shared or not
	 */
	public function setShared(boolean shared) -> void
	{
		let this->_shared = shared;
	}

	/**
	 * Check whether the service is shared or not
	 */
	public function isShared() -> boolean
	{
		return this->_shared;
	}

	/**
	 * Sets/Resets the shared instance related to the service
	 *
	 * @param mixed sharedInstance
	 */
	public function setSharedInstance(sharedInstance) -> void
	{
		let this->_sharedInstance = sharedInstance;
	}

	/**
	 * Set the service definition
	 *
	 * @param mixed definition
	 */
	public function setDefinition(definition) -> void
	{
		let this->_definition = definition;
	}

	/**
	 * Returns the service definition
	 *
	 * @return mixed
	 */
	public function getDefinition()
	{
		return this->_definition;
	}

	/**
	 * Resolves the service
	 *
	 * @param array parameters
	 * @param Phalcon\DiInterface dependencyInjector
	 * @return mixed
	 */
	public function resolve(parameters = null, <DiInterface> dependencyInjector = null)
	{
		boolean found;
		var shared, definition, sharedInstance, instance, builder, reflection;

		let shared = this->_shared;

		/**
		 * Check if the service is shared
		 */
		if shared {
			let sharedInstance = this->_sharedInstance;
			if sharedInstance !== null {
				return sharedInstance;
			}
		}

		let found = true,
			instance = null;

		let definition = this->_definition;
		if typeof definition == "string" {

			/**
			 * String definitions can be class names without implicit parameters
			 */
			if class_exists(definition) {
				if typeof parameters == "array" {
					if count(parameters) {
						if is_php_version("5.6") {
							let reflection = new \ReflectionClass(definition),
								instance = reflection->newInstanceArgs(parameters);
						} else {
							let instance = create_instance_params(definition, parameters);
						}
					} else {
						if is_php_version("5.6") {
							let reflection = new \ReflectionClass(definition),
								instance = reflection->newInstance();
						} else {
							let instance = create_instance(definition);
						}
					}
				} else {
					if is_php_version("5.6") {
						let reflection = new \ReflectionClass(definition),
							instance = reflection->newInstance();
					} else {
						let instance = create_instance(definition);
					}
				}
			} else {
				let found = false;
			}
		} else {

			/**
			 * Object definitions can be a Closure or an already resolved instance
			 */
			if typeof definition == "object" {
				if definition instanceof \Closure {
					if typeof parameters == "array" {
						let instance = call_user_func_array(definition, parameters);
					} else {
						let instance = call_user_func(definition);
					}
				} else {
					let instance = definition;
				}
			} else {
				/**
				 * Array definitions require a 'className' parameter
				 */
				if typeof definition == "array" {
					let builder = new Builder(),
						instance = builder->build(dependencyInjector, definition, parameters);
				} else {
					let found = false;
				}
			}
		}

		/**
		 * If the service can't be built, we must throw an exception
		 */
		if found === false  {
			throw new Exception("Service '" . this->_name . "' cannot be resolved");
		}

		/**
		 * Update the shared instance if the service is shared
		 */
		if shared {
			let this->_sharedInstance = instance;
		}

		let this->_resolved = true;

		return instance;
	}

	/**
	 * Changes a parameter in the definition without resolve the service
	 */
	public function setParameter(int position, array! parameter) -> <Service>
	{
		var definition, arguments;

		let definition = this->_definition;
		if typeof definition != "array" {
			throw new Exception("Definition must be an array to update its parameters");
		}

		/**
		 * Update the parameter
		 */
		if fetch arguments, definition["arguments"] {
			let arguments[position] = parameter;
		} else {
			let arguments = [position: parameter];
		}

		/**
		 * Re-update the arguments
		 */
		let definition["arguments"] = arguments;

		/**
		 * Re-update the definition
		 */
		let this->_definition = definition;

		return this;
	}

	/**
	 * Returns a parameter in a specific position
	 *
	 * @param int position
	 * @return array
	 */
	public function getParameter(int position)
	{
		var definition, arguments, parameter;

		let definition = this->_definition;
		if typeof definition != "array" {
			throw new Exception("Definition must be an array to obtain its parameters");
		}

		/**
		 * Update the parameter
		 */
		if fetch arguments, definition["arguments"] {
			if fetch parameter, arguments[position] {
				return parameter;
			}
		}

		return null;
	}

	/**
	 * Returns true if the service was resolved
	 */
	public function isResolved() -> boolean
	{
		return this->_resolved;
	}

	/**
	 * Restore the internal state of a service
	 */
	public static function __set_state(array! attributes) -> <Service>
	{
		var name, definition, shared;

		if !fetch name, attributes["_name"] {
			throw new Exception("The attribute '_name' is required");
		}

		if !fetch definition, attributes["_definition"] {
			throw new Exception("The attribute '_definition' is required");
		}

		if !fetch shared, attributes["_shared"] {
			throw new Exception("The attribute '_shared' is required");
		}

		return new self(name, definition, shared);
	}
}
