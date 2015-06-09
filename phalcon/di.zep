
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
 |          Nikolaos Dimopoulos <nikos@niden.net>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon;

use Phalcon\DiInterface;
use Phalcon\Di\Service;
use Phalcon\Di\ServiceInterface;
use Phalcon\Di\Exception;
use Phalcon\Events\ManagerInterface;
use Phalcon\Di\InjectionAwareInterface;

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
 * $di = new \Phalcon\Di();
 *
 * //Using a string definition
 * $di->set("request", "Phalcon\Http\Request", true);
 *
 * //Using an anonymous function
 * $di->set("request", function(){
 *	  return new \Phalcon\Http\Request();
 * }, true);
 *
 * $request = $di->getRequest();
 *</code>
 */
class Di implements DiInterface
{

	/**
	 * List of registered services
	 */
	protected _services;

	/**
	 * List of shared instances
	 */
	protected _sharedInstances;

	/**
	 * To know if the latest resolved instance was shared or not
	 */
	protected _freshInstance = false;

	/**
	 * Events Manager
	 *
	 * @var \Phalcon\Events\ManagerInterface
	 */
	protected _eventsManager;

	/**
	 * Latest DI build
	 */
	protected static _default;

	/**
	 * Phalcon\Di constructor
	 */
	public function __construct()
	{
		var di;
		let di = self::_default;
		if !di {
			let self::_default = this;
		}
	}

	/**
	 * Sets the internal event manager
	 */
	public function setInternalEventsManager(<ManagerInterface> eventsManager)
	{
		let this->_eventsManager = eventsManager;
	}

	/**
	 * Returns the internal event manager
	 */
	public function getInternalEventsManager() -> <ManagerInterface>
	{
		return this->_eventsManager;
	}

	/**
	 * Registers a service in the services container
	 */
	public function set(string! name, var definition, boolean shared = false) -> <ServiceInterface>
	{
		var service;
		let service = new Service(name, definition, shared),
			this->_services[name] = service;
		return service;
	}

	/**
	 * Registers an "always shared" service in the services container
	 */
	public function setShared(string! name, var definition) -> <ServiceInterface>
	{
		var service;
		let service = new Service(name, definition, true),
			this->_services[name] = service;
		return service;
	}

	/**
	 * Removes a service in the services container
	 */
	public function remove(string! name)
	{
		unset this->_services[name];
	}

	/**
	 * Attempts to register a service in the services container
	 * Only is successful if a service hasn"t been registered previously
	 * with the same name
	 */
	public function attempt(string! name, definition, boolean shared = false) -> <ServiceInterface> | boolean
	{
		var service;

		if !isset this->_services[name] {
			let service = new Service(name, definition, shared),
				this->_services[name] = service;
			return service;
		}

		return false;
	}

	/**
	 * Sets a service using a raw Phalcon\Di\Service definition
	 */
	public function setRaw(string! name, <ServiceInterface> rawDefinition) -> <ServiceInterface>
	{
		let this->_services[name] = rawDefinition;
		return rawDefinition;
	}

	/**
	 * Returns a service definition without resolving
	 */
	public function getRaw(string! name)
	{
		var service;

		if fetch service, this->_services[name] {
			return service->getDefinition();
		}

		throw new Exception("Service '" . name . "' wasn't found in the dependency injection container");
	}

	/**
	 * Returns a Phalcon\Di\Service instance
	 */
	public function getService(string! name) -> <ServiceInterface>
	{
		var service;

		if fetch service, this->_services[name] {
			return service;
		}

		throw new Exception("Service '" . name . "' wasn't found in the dependency injection container");
	}

	/**
	 * Resolves the service based on its configuration
	 */
	public function get(string! name, parameters = null)
	{
		var service, instance, reflection, eventsManager;

		let eventsManager = <ManagerInterface> this->_eventsManager;

		if typeof eventsManager == "object" {
			eventsManager->fire("di:beforeServiceResolve", this, ["name": name, "parameters": parameters]);
		}

		if fetch service, this->_services[name] {
			/**
			 * The service is registered in the DI
			 */
			let instance = service->resolve(parameters, this);
		} else {
			/**
			 * The DI also acts as builder for any class even if it isn't defined in the DI
			 */
			if !class_exists(name) {
				throw new Exception("Service '" . name . "' wasn't found in the dependency injection container");
			}

			if typeof parameters == "array" {
				if count(parameters) {
					if is_php_version("5.6") {
						let reflection = new \ReflectionClass(name),
							instance = reflection->newInstanceArgs(parameters);
					} else {
						let instance = create_instance_params(name, parameters);
					}
				} else {
					if is_php_version("5.6") {
						let reflection = new \ReflectionClass(name),
							instance = reflection->newInstance();
					} else {
						let instance = create_instance(name);
					}
				}
			} else {
				if is_php_version("5.6") {
					let reflection = new \ReflectionClass(name),
						instance = reflection->newInstance();
				} else {
					let instance = create_instance(name);
				}
			}
		}

		/**
		 * Pass the DI itself if the instance implements \Phalcon\Di\InjectionAwareInterface
		 */
		if typeof instance == "object" {
			if instance instanceof InjectionAwareInterface {
				instance->setDI(this);
			}
		}

		if typeof eventsManager == "object" {
			eventsManager->fire(
				"di:afterServiceResolve",
				this,
				[
					"name": name,
					"parameters": parameters,
					"instance": instance
				]
			);
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
	public function getShared(string! name, parameters = null)
	{
		var instance;

		/**
		 * This method provides a first level to shared instances allowing to use non-shared services as shared
		 */
		if fetch instance, this->_sharedInstances[name] {
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
	 */
	public function has(string! name) -> boolean
	{
		return isset this->_services[name];
	}

	/**
	 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
	 */
	public function wasFreshInstance() -> boolean
	{
		return this->_freshInstance;
	}

	/**
	 * Return the services registered in the DI
	 */
	public function getServices() -> <Service[]>
	{
		return this->_services;
	}

	/**
	 * Check if a service is registered using the array syntax
	 */
	public function offsetExists(string! name) -> boolean
	{
		return this->has(name);
	}

	/**
	 * Allows to register a shared service using the array syntax
	 *
	 *<code>
	 *	$di["request"] = new \Phalcon\Http\Request();
	 *</code>
	 *
	 * @param string name
	 * @param mixed definition
	 * @return boolean
	 */
	public function offsetSet(string! name, var definition) -> boolean
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
	public function __call(string! method, arguments = null)
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
		throw new Exception("Call to undefined method or service '" . method . "'");
	}

	/**
	 * Set a default dependency injection container to be obtained into static methods
	 */
	public static function setDefault(<DiInterface> dependencyInjector)
	{
		let self::_default = dependencyInjector;
	}

	/**
	 * Return the lastest DI created
	 */
	public static function getDefault() -> <DiInterface>
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
