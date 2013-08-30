
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

/**
 * Phalcon\DI
 *
 * Phalcon\DI is a component that implements Dependency Injection/Service Location
 * of services and it's itself a container for them.
 *
 * Since Phalcon is highly decoupled, Phalcon\DI is essential to integrate the different
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
 * $di = new Phalcon\DI();
 *
 * //Using a string definition
 * $di->set('request', 'Phalcon\Http\Request', true);
 *
 * //Using an anonymous function
 * $di->set('request', function(){
 *	  return new Phalcon\Http\Request();
 * }, true);
 *
 * $request = $di->getRequest();
 *
 *</code>
 */
class DI implements Phalcon\DiInterface
{

	protected _services;

	protected _sharedInstances;

	protected _freshInstance = false;

	protected static _default;

	/**
	 * Phalcon\DI constructor
	 *
	 */
	public function __construct()
	{
		let defaultDi = self::_default;
		if !defaultDi {
			self::_default = this;
		}
	}

	/**
	 * Registers a service in the services container
	 *
	 * @param string name
	 * @param mixed definition
	 * @param boolean shared
	 * @return Phalcon\DI\ServiceInterface
	 */
	public function set(name, definition, shared=false)
	{
		if typeof name != "string" {
			throw new Phalcon\DI\Exception("The service name must be a string");
		}
		let service = new Phalcon\DI\Service(name, definition, shared),
			this->_services[name] = service;
		return service;
	}

	/**
	 * Registers an "always shared" service in the services container
	 *
	 * @param string name
	 * @param mixed definition
	 * @return Phalcon\DI\ServiceInterface
	 */
	public function setShared(name, definition)
	{
		if typeof name != "string" {
			throw new Phalcon\DI\Exception("The service name must be a string");
		}
		let service = new Phalcon\DI\Service(name, definition, true),
			this->_services[name] = service;
		return service;
	}

	/**
	 * Removes a service in the services container
	 *
	 * @param string name
	 */
	public function remove(name)
	{
		if typeof name != "string" {
			throw new Phalcon\DI\Exception("The service name must be a string");
		}
		unset this->_services[name];
	}

	/**
	 * Attempts to register a service in the services container
	 * Only is successful if a service hasn't been registered previously
	 * with the same name
	 *
	 * @param string name
	 * @param mixed definition
	 * @param boolean shared
	 * @return Phalcon\DI\ServiceInterface
	 */
	public function attempt(name, definition, shared=false)
	{

		if typeof name != "string" {
			throw new Phalcon\DI\Exception("The service name must be a string");
		}

		let services = this->_services;
		if !isset services[name] {
			let service = new Phalcon\DI\Service(name, definition, shared),
				this->_services[name] = service;
			return service;
		}

		return null;
	}

	/**
	 * Sets a service using a raw Phalcon\DI\Service definition
	 *
	 * @param string name
	 * @param Phalcon\DI\ServiceInterface rawDefinition
	 * @return Phalcon\DI\ServiceInterface
	 */
	public function setRaw(name, <Phalcon\DI\ServiceInterface> rawDefinition)
	{

		if typeof name != "string" {
			throw new Phalcon\DI\Exception("The service name must be a string");
		}

		if typeof rawDefinition != "object" {
			throw new Phalcon\DI\Exception("The service definition must be an object");
		}

		let this->_services[name] = rawDefinition;
		return rawDefinition;
	}

	/**
	 * Returns a service definition without resolving
	 *
	 * @param string name
	 * @return mixed
	 */
	public function getRaw(name)
	{

		if typeof name != "string" {
			throw new Phalcon\DI\Exception("The service name must be a string");
		}

		let services = this->_services;
		if isset services[name] {
			let service = services[name],
				return service->getDefinition();
		}

		throw new Phalcon_DI_Exception("Service '" . name . "' wasn't found in the dependency injection container");
	}

	/**
	 * Returns a Phalcon\DI\Service instance
	 *
	 * @param string name
	 * @return Phalcon\DI\ServiceInterface
	 */
	public function getService(name)
	{

		if typeof name != "string" {
			throw new Phalcon\DI\Exception("The service name must be a string");
		}

		let services = this->_services;
		if fetch setvice, services[name] {
			return service;
		}

		throw new Phalcon\DI\Exception("Service '" . name . "' wasn't found in the dependency injection container");
	}

	/**
	 * Resolves the service based on its configuration
	 *
	 * @param string name
	 * @param array parameters
	 * @return mixed
	 */
	public function get(name, parameters=null)
	{

		/**
		 * <comment>A valid service alias is a string</comment>
		 */
		if typeof name != "string" {
			throw new Phalcon\DI\Exception("The service name must be a string");
		}

		let services = this->_services;
		if fetch setvice, services[name] {
			/**
			 * <comment>The service is registered in the DI</comment>
			 */
			let instance = service->resolve(parameters, this);
		} else {
			/**
			 * <comment>The DI also acts as builder for any class even if it isn't defined in the DI</comment>
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
				throw new Phalcon\DI\Exception("Service '" . name . "' wasn't found in the dependency injection container");
			}
		}

		/**
		 * <comment>Pass the DI itself if the instance implements Phalcon\DI\InjectionAwareInterface</comment>
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
	public function getShared(name, parameters=null)
	{

		if typeof name != "string" {
			throw new Phalcon\DI\Exception("The service name must be a string");
		}

		/**
		 * <comment>This method provides a first level to shared instances allowing to use non-shared services as shared</comment>
		 */
		let sharedInstances = this->_sharedInstances;
		if !fetch instance, sharedInstances[name] {
			let this->_freshInstance = false;
		} else {

			/**
			 * <comment>Resolve the instance normally</comment>
			 */
			let instance = this->get(name, parameters);

			/**
			 * <comment>Save the instance in the first level shared</comment>
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
	public function has(name)
	{
		if typeof name != "string" {
			throw new Phalcon\DI\Exception("The service name must be a string");
		}

		let services = this->_services;
		return isset services[name];
	}

	/**
	 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
	 *
	 * @return boolean
	 */
	public function wasFreshInstance()
	{
		return this->_freshInstance;
	}

	/**
	 * Return the services registered in the DI
	 *
	 * @return Phalcon\DI\Service[]
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
	public function offsetExists(name)
	{
		return this->has(name);
	}

	/**
	 * Allows to register a shared service using the array syntax
	 *
	 *<code>
	 *	$di['request'] = new Phalcon\Http\Request();
	 *</code>
	 *
	 * @param string name
	 * @param mixed definition
	 */
	public function offsetSet(name, definition)
	{
		this->setShared(name, definition);
	}

	/**
	 * Allows to obtain a shared service using the array syntax
	 *
	 *<code>
	 *	var_dump($di['request']);
	 *</code>
	 *
	 * @param string name
	 * @return mixed
	 */
	public function offsetGet(name)
	{
		return this->getShared(name);
	}

	/**
	 * Removes a service from the services container using the array syntax
	 *
	 * @param string name
	 */
	public function offsetUnset(name)
	{
		return name;
	}

	/**
	 * Magic method to get or set services using setters/getters
	 *
	 * @param string method
	 * @param array arguments
	 * @return mixed
	 */
	public function __call(method, arguments=null)
	{

		/**
		 * <comment>If the magic method starts with 'get' we try to get a service with that name</comment>
		 */
		if starts_with(method, 'get') {
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
		 * <comment>If the magic method starts with 'set' we try to set a service using that name</comment>
		 */
		if starts_with(method, 'set') {
			if isset arguments[0] {
				this->set(lcfirst(substr(method, 3)), arguments[0]);
				return null;
			}
		}

		/**
		 * <comment>The method doesn't start with set/get throw an exception</comment>
		 */
		throw new Phalcon\DI\Exception("Call to undefined method or service '" . method . "'");
	}

	/**
	 * Set a default dependency injection container to be obtained into static methods
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public + static function setDefault(<Phalcon\DiInterface> dependencyInjector)
	{
		let self::_default = dependencyInjector;
	}

	/**
	 * Return the lastest DI created
	 *
	 * @return Phalcon\DiInterface
	 */
	public + static function getDefault()
	{
		return self::_default;
	}

	/**
	 * Resets the internal default DI
	 */
	public + static function reset()
	{
		let self::_default = null;
	}

}
