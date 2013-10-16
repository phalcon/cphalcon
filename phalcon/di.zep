
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
 |          Nikolaos Dimopoulos <nikos@niden.net>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon;

/**
 * Phalcon\Di
 *
 * Phalcon\Di is a component that implements Dependency Injection/Service Location
 * of services and it"s itself a container for them.
 *
 * Since Phalcon is highly decoupled, Phalcon\Di is essential to integrate the different
 * components of the framework. The developer can also use this component to inject dependencies
 * and manage global instances of the different classes used in the application.
 *
 * Basically, this component implements the `Inversion of Control` pattern. Applying this,
 * the objects do not receive their dependencies using setters or constructors, but requesting
 * a service dependency injector. This reduces the overall complexity, since there is only one
 * way to get the required dependencies within a component.
 *
 * Additionally, this pattern increases testability in the code, thus making it less prone to errors.
 *
 *<code>
 * $di = new Phalcon\Di();
 *
 * //Using a string definition
 * $di->set("request", "Phalcon\Http\Request", true);
 *
 * //Using an anonymous function
 * $di->set("request", function(){
 *	  return new Phalcon\Http\Request();
 * }, true);
 *
 * $request = $di->getRequest();
 *
 *</code>
 */
class Di implements Phalcon\DiInterface
{

	protected _services;

	protected _sharedInstances;

	protected _freshInstance = false;

	protected static _default;

	/**
	 * Phalcon\Di constructor
	 *
	 */
	public function __construct()
	{
		var defaultDi;

		let defaultDi = self::_default;
		if !defaultDi {
			let self::_default = this;
		}
	}

	/**
	 * Registers a service in the services container
	 *
	 * @param string name
	 * @param mixed definition
	 * @param boolean shared
	 * @return Phalcon\Di\ServiceInterface
	 */
	public function set(string! name, definition, shared=false) -> <Phalcon\Di\ServiceInterface>
	{
		var service;
		let service = new Phalcon\Di\Service(name, definition, shared),
			this->_services[name] = service;
		return service;
	}

	/**
	 * Registers an "always shared" service in the services container
	 *
	 * @param string name
	 * @param mixed definition
	 * @return Phalcon\Di\ServiceInterface
	 */
	public function setShared(string! name, definition) -> <Phalcon\Di\ServiceInterface>
	{
		var service;
		let service = new Phalcon\Di\Service(name, definition, true),
			this->_services[name] = service;
		return service;
	}

	/**
	 * Removes a service in the services container
	 *
	 * @param string name
	 */
	public function remove(string! name)
	{
		//unset this->_services[name];
	}

	/**
	 * Attempts to register a service in the services container
	 * Only is successful if a service hasn"t been registered previously
	 * with the same name
	 *
	 * @param string name
	 * @param mixed definition
	 * @param boolean shared
	 * @return Phalcon\Di\ServiceInterface|false
	 */
	public function attempt(string! name, definition, boolean shared=false) -> <Phalcon\Di\ServiceInterface> | boolean
	{
		var services, service;

		let services = this->_services;
		if !isset services[name] {
			let service = new Phalcon\Di\Service(name, definition, shared),
				this->_services[name] = service;
			return service;
		}

		return false;
	}

	/**
	 * Sets a service using a raw Phalcon\Di\Service definition
	 *
	 * @param string name
	 * @param Phalcon\Di\ServiceInterface rawDefinition
	 * @return Phalcon\Di\ServiceInterface
	 */
	public function setRaw(string! name, <Phalcon\Di\ServiceInterface> rawDefinition) -> <Phalcon\Di\ServiceInterface>
	{
		let this->_services[name] = rawDefinition;
		return rawDefinition;
	}

	/**
	 * Returns a service definition without resolving
	 *
	 * @param string name
	 * @return mixed
	 */
	public function getRaw(string! name)
	{
		var services, service;

		let services = this->_services;
		if fetch service, services[name] {
			return service->getDefinition();
		}

		throw new Phalcon\Di\Exception("Service '" . name . "' wasn't found in the dependency injection container");
	}

	/**
	 * Returns a Phalcon\Di\Service instance
	 *
	 * @param string name
	 * @return Phalcon\Di\ServiceInterface
	 */
	public function getService(string! name) -> <Phalcon\Di\ServiceInterface>
	{
		var services, service;

		let services = this->_services;
		if fetch service, services[name] {
			return service;
		}

		throw new Phalcon\Di\Exception("Service '" . name . "' wasn't found in the dependency injection container");
	}

	/**
	 * Resolves the service based on its configuration
	 *
	 * @param string name
	 * @param array parameters
	 * @return mixed
	 */
	public function get(string! name, parameters=null)
	{
		var services, service, instance;

		let services = this->_services;
		if fetch service, services[name] {
			/**
			 * The service is registered in the DI
			 */
			let instance = service->resolve(parameters, this);
		} else {
			/**
			 * The DI also acts as builder for any class even if it isn't defined in the DI
			 */
			if class_exists(name) {
				if typeof parameters == "string" {
					if count(parameters) {
						let instance = create_instance_params(name, parameters);
					} else {
						let instance = create_instance(name);
					}
				} else {
					let instance = create_instance(name);
				}
			} else {
				throw new Phalcon\Di\Exception("Service '" . name . "' wasn't found in the dependency injection container");
			}
		}

		/**
		 * Pass the DI itself if the instance implements Phalcon\Di\InjectionAwareInterface
		 */
		if typeof instance == "object" {
			if method_exists(instance, "setDI") {
				instance->setDI(this);
			}
		}

		return instance;
	}

	/**
	 * Resolves a service, the resolved service is stored in the DI, subsequent requests for this service will return the same instance
	 *
	 * @param string name
	 * @param array parameters
	 * @return mixed
	 */
	public function getShared(string! name, parameters=null)
	{
		var instance, sharedInstances;

		/**
		 * This method provides a first level to shared instances allowing to use non-shared services as shared
		 */
		let sharedInstances = this->_sharedInstances;
		if fetch instance, sharedInstances[name] {
			let this->_freshInstance = false;
		} else {

			/**
			 * Resolve the instance normally
			 */
			let instance = this->get(name, parameters);

			/**
			 * Save the instance in the first level shared
			 */
			let this->_sharedInstances[name] = instance,
				this->_freshInstance = true;
		}

		return instance;
	}

	/**
	 * Check whether the DI contains a service by a name
	 *
	 * @param string name
	 * @return boolean
	 */
	public function has(string! name) -> boolean
	{
		var services;
		let services = this->_services;
		return isset services[name];
	}

	/**
	 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
	 *
	 * @return boolean
	 */
	public function wasFreshInstance() -> boolean
	{
		return this->_freshInstance;
	}

	/**
	 * Return the services registered in the DI
	 *
	 * @return Phalcon\Di\Service[]
	 */
	public function getServices()
	{
		return this->_services;
	}

	/**
	 * Check if a service is registered using the array syntax
	 *
	 * @param string name
	 * @return boolean
	 */
	public function offsetExists(string! name) -> boolean
	{
		return this->has(name);
	}

	/**
	 * Allows to register a shared service using the array syntax
	 *
	 *<code>
	 *	$di["request"] = new Phalcon\Http\Request();
	 *</code>
	 *
	 * @param string name
	 * @param mixed definition
	 * @return boolean
	 */
	public function offsetSet(string! name, definition) -> boolean
	{
		this->setShared(name, definition);
		return true;
	}

	/**
	 * Allows to obtain a shared service using the array syntax
	 *
	 *<code>
	 *	var_dump($di["request"]);
	 *</code>
	 *
	 * @param string name
	 * @return mixed
	 */
	public function offsetGet(string! name) -> boolean
	{
		return this->getShared(name);
	}

	/**
	 * Removes a service from the services container using the array syntax
	 *
	 * @param string name
	 */
	public function offsetUnset(string! name) -> boolean
	{
		return false;
	}

	/**
	 * Magic method to get or set services using setters/getters
	 *
	 * @param string method
	 * @param array arguments
	 * @return mixed
	 */
	public function __call(string! method, arguments=null)
	{
		var instance, possibleService, services, definition;

		/**
		 * If the magic method starts with "get" we try to get a service with that name
		 */
		if starts_with(method, "get") {
			let services = this->_services,
				possibleService = lcfirst(substr(method, 3));
			if isset services[possibleService] {
				if count(arguments) {
					let instance = this->get(possibleService, arguments);
				} else {
					let instance = this->get(possibleService);
				}
				return instance;
			}
		}

		/**
		 * If the magic method starts with "set" we try to set a service using that name
		 */
		if starts_with(method, "set") {
			if fetch definition, arguments[0] {
				this->set(lcfirst(substr(method, 3)), definition);
				return null;
			}
		}

		/**
		 * The method doesn't start with set/get throw an exception
		 */
		throw new Phalcon\Di\Exception("Call to undefined method or service '" . method . "'");
	}

	/**
	 * Set a default dependency injection container to be obtained into static methods
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public static function setDefault(<Phalcon\DiInterface> dependencyInjector)
	{
		let self::_default = dependencyInjector;
	}

	/**
	 * Return the lastest DI created
	 *
	 * @return Phalcon\DiInterface
	 */
	public static function getDefault() -> <Phalcon\DiInterface>
	{
		return self::_default;
	}

	/**
	 * Resets the internal default DI
	 */
	public static function reset()
	{
		let self::_default = null;
	}

}
