
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

/**
 * Phalcon\Di\Service
 *
 * Represents individually a service in the services container
 *
 *<code>
 * $service = new Phalcon\Di\Service('request', 'Phalcon\Http\Request');
 * $request = service->resolve();
 *<code>
 *
 */
class Service implements Phalcon\Di\ServiceInterface
{

	protected _name;

	protected _definition;

	protected _shared;

	protected _sharedInstance;

	/**
	 * Phalcon\Di\Service
	 *
	 * @param string name
	 * @param mixed definition
	 * @param boolean shared
	 */
	public function __construct(string name, definition, boolean shared=false)
	{
		let this->_name = name,
			this->_definition = definition,
			this->_shared = shared;
	}

	/**
	 * Returns the service's name
	 *
	 * @param string
	 */
	public function getName()
	{
		return this->_name;
	}

	/**
	 * Sets if the service is shared or not
	 *
	 * @param boolean shared
	 */
	public function setShared(shared)
	{
		let this->_shared = shared;
	}

	/**
	 * Check whether the service is shared or not
	 *
	 * @return boolean
	 */
	public function isShared()
	{
		return this->_shared;
	}

	/**
	 * Sets/Resets the shared instance related to the service
	 *
	 * @param mixed sharedInstance
	 */
	public function setSharedInstance(sharedInstance)
	{
		let this->_sharedInstance = sharedInstance;
	}

	/**
	 * Set the service definition
	 *
	 * @param mixed definition
	 */
	public function setDefinition(definition)
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
	public function resolve(parameters=null, <Phalcon\DiInterface> dependencyInjector=null)
	{

		boolean found;
		var shared, definition, sharedInstance, instance, builder;

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
						let instance = create_instance_params(definition, parameters);
					} else {
						let instance = create_instance(definition);
					}
				} else {
					let instance = create_instance(definition);
				}
			} else {
				let found = false;
			}
		} else {

			/**
			 * Object definitions can be a Closure or an already resolved instance
			 */
			if typeof definition == "object" {
				if definition instanceof "Closure" {
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
					let builder = new Phalcon\Di\Service\Builder(),
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
			throw new Phalcon\Di\Exception("Service '" . this->_name . "' cannot be resolved");
		}

		/**
		 * Update the shared instance if the service is shared
		 */
		if shared {
			let this->_sharedInstance = instance;
		}

		return instance;
	}

	/**
	 * Changes a parameter in the definition without resolve the service
	 *
	 * @param long position
	 * @param array parameter
	 * @return Phalcon\Di\Service
	 */
	public function setParameter(int position, parameter)
	{
		var definition, arguments;

		let definition = this->_definition;
		if typeof definition != "array" {
			throw new Phalcon\Di\Exception("Definition must be an array to update its parameters");
		}

		if typeof parameter != "array" {
			throw new Phalcon\Di\Exception("The parameter must be an array");
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
			throw new Phalcon\Di\Exception("Definition must be an array to obtain its parameters");
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
	 * Restore the internal state of a service
	 *
	 * @param array attributes
	 * @return Phalcon\Di\Service
	 */
	public static function __set_state(attributes)
	{
		var name, definition, shared;

		if !fetch name, attributes["_name"] {
			throw new Phalcon\Di\Exception("The attribute '_name' is required");
		}

		if !fetch definition, attributes["_definition"] {
			throw new Phalcon\Di\Exception("The attribute '_name' is required");
		}

		if !fetch shared, attributes["_shared"] {
			throw new Phalcon\Di\Exception("The attribute '_shared' is required");
		}

		return new self(name, definition, shared);
	}

}
