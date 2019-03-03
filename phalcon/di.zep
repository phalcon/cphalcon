
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\Config;
use Phalcon\Di\Service;
use Phalcon\DiInterface;
use Phalcon\Di\Exception;
use Phalcon\Di\Exception\ServiceResolutionException;
use Phalcon\Config\Adapter\Php;
use Phalcon\Config\Adapter\Yaml;
use Phalcon\Di\ServiceInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Di\ServiceProviderInterface;

/**
 * Phalcon\Di
 *
 * Phalcon\Di is a component that implements Dependency Injection/Service Location
 * of services and it's itself a container for them.
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
 * use Phalcon\Di;
 * use Phalcon\Http\Request;
 *
 * $di = new Di();
 *
 * // Using a string definition
 * $di->set("request", Request::class, true);
 *
 * // Using an anonymous function
 * $di->setShared(
 *     "request",
 *     function () {
 *         return new Request();
 *     }
 * );
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
	public function set(string! name, var definition, bool shared = false) -> <ServiceInterface>
	{
		var service;
		let service = new Service(definition, shared),
			this->_services[name] = service;
		return service;
	}

	/**
	 * Registers an "always shared" service in the services container
	 */
	public function setShared(string! name, var definition) -> <ServiceInterface>
	{
		return this->set(name, definition, true);
	}

	/**
	 * Removes a service in the services container
	 * It also removes any shared instance created for the service
	 */
	public function remove(string! name)
	{
		unset this->_services[name];
		unset this->_sharedInstances[name];
	}

	/**
	 * Attempts to register a service in the services container
	 * Only is successful if a service hasn't been registered previously
	 * with the same name
	 */
	public function attempt(string! name, definition, bool shared = false) -> <ServiceInterface> | bool
	{
		var service;

		if !isset this->_services[name] {
			let service = new Service(definition, shared),
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
	public function getRaw(string! name) -> var
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
	public function get(string! name, parameters = null) -> var
	{
		var service, eventsManager, isShared, instance = null;

		// If the service is shared and it already has a cached instance then
		// immediately return it without triggering events.
		if fetch service, this->_services[name] {
			let isShared = service->isShared();
			if isShared && isset this->_sharedInstances[name] {
				return this->_sharedInstances[name];
			}
		}

		let eventsManager = <ManagerInterface> this->_eventsManager;

		// Allows for custom creation of instances through the "di:beforeServiceResolve" event.
		if typeof eventsManager == "object" {
			let instance = eventsManager->fire(
				"di:beforeServiceResolve",
				this,
				[
					"name": name,
					"parameters": parameters
				]
			);
		}

		if typeof instance != "object" {
			if service !== null {

				// The service is registered in the DI.
				try {
					let instance = service->resolve(parameters, this);
				} catch ServiceResolutionException {
					throw new Exception("Service '" . name . "' cannot be resolved");
				}

				// If the service is shared then we'll cache the instance.
				if isShared {
					let this->_sharedInstances[name] = instance;
				}
			} else {

				// The DI also acts as builder for any class even if it isn't defined in the DI
				if !class_exists(name) {
					throw new Exception("Service '" . name . "' wasn't found in the dependency injection container");
				}

				if typeof parameters == "array" && count(parameters) {
					let instance = create_instance_params(name, parameters);
				} else {
					let instance = create_instance(name);
				}
			}
		}

		// Pass the DI to the instance if it implements \Phalcon\Di\InjectionAwareInterface
		if typeof instance == "object" {
			if instance instanceof InjectionAwareInterface {
				instance->setDI(this);
			}
		}

		// Allows for post creation instance configuration through the "di:afterServiceResolve" event.
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
	 * Resolves a service, the resolved service is stored in the DI, subsequent
	 * requests for this service will return the same instance
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public function getShared(string! name, parameters = null) -> var
	{
		var instance;

		// Attempt to use the instance from the shared instances cache.
		if !fetch instance, this->_sharedInstances[name] {
			// Resolve the instance normally
			let instance = this->get(name, parameters);

			// Store the instance in the shared instances cache.
			let this->_sharedInstances[name] = instance;
		}

		return instance;
	}

	/**
	 * Check whether the DI contains a service by a name
	 */
	public function has(string! name) -> bool
	{
		return isset this->_services[name];
	}

	/**
	 * Return the services registered in the DI
	 */
	public function getServices() -> <ServiceInterface[]>
	{
		return this->_services;
	}

	/**
	 * Check if a service is registered using the array syntax
	 */
	public function offsetExists(var name) -> bool
	{
		return this->has(name);
	}

	/**
	 * Allows to register a shared service using the array syntax
	 *
	 *<code>
	 * $di["request"] = new \Phalcon\Http\Request();
	 *</code>
	 */
	public function offsetSet(var name, var definition) -> void
	{
		this->setShared(name, definition);
	}

	/**
	 * Allows to obtain a shared service using the array syntax
	 *
	 *<code>
	 * var_dump($di["request"]);
	 *</code>
	 */
	public function offsetGet(var name) -> var
	{
		return this->getShared(name);
	}

	/**
	 * Removes a service from the services container using the array syntax
	 */
	public function offsetUnset(var name) -> void
	{
		this->remove(name);
	}

	/**
	 * Magic method to get or set services using setters/getters
	 */
	public function __call(string! method, array arguments = []) -> var | null
	{
		var instance, possibleService, services, definition;

		/**
		 * If the magic method starts with "get" we try to get a service with that name
		 */
		if starts_with(method, "get") {
			let services = this->_services,
				possibleService = lcfirst(substr(method, 3));

			if isset services[possibleService] {
				let instance = this->get(possibleService, arguments);

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
	 * Registers a service provider.
	 *
	 * <code>
	 * use Phalcon\DiInterface;
	 * use Phalcon\Di\ServiceProviderInterface;
	 *
	 * class SomeServiceProvider implements ServiceProviderInterface
	 * {
	 *     public function register(DiInterface $di)
	 *     {
	 *         $di->setShared('service', function () {
	 *             // ...
	 *         });
	 *     }
	 * }
	 * </code>
	 */
	public function register(<ServiceProviderInterface> provider) -> void
	{
		provider->register(this);
	}

	/**
	 * Set a default dependency injection container to be obtained into static methods
	 */
	public static function setDefault(<DiInterface> dependencyInjector) -> void
	{
		let self::_default = dependencyInjector;
	}

	/**
	 * Return the latest DI created
	 */
	public static function getDefault() -> <DiInterface> | null
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

	/**
	 * Loads services from a yaml file.
	 *
	 * <code>
	 * $di->loadFromYaml(
	 *     "path/services.yaml",
	 *     [
	 *         "!approot" => function ($value) {
	 *             return dirname(__DIR__) . $value;
	 *         }
	 *     ]
	 * );
	 * </code>
	 *
	 * And the services can be specified in the file as:
	 *
	 * <code>
	 * myComponent:
	 *     className: \Acme\Components\MyComponent
	 *     shared: true
	 *
	 * group:
	 *     className: \Acme\Group
	 *     arguments:
	 *         - type: service
	 *           name: myComponent
	 *
	 * user:
	 *    className: \Acme\User
	 * </code>
	 *
	 * @link https://docs.phalconphp.com/en/latest/reference/di.html
	 */
	public function loadFromYaml(string! filePath, array! callbacks = null) -> void
	{
		var services;

		let services = new Yaml(filePath, callbacks);

		this->loadFromConfig(services);
	}

	/**
	 * Loads services from a php config file.
	 *
	 * <code>
	 * $di->loadFromPhp("path/services.php");
	 * </code>
	 *
	 * And the services can be specified in the file as:
	 *
	 * <code>
	 * return [
	 *      'myComponent' => [
	 *          'className' => '\Acme\Components\MyComponent',
	 *          'shared' => true,
	 *      ],
	 *      'group' => [
	 *          'className' => '\Acme\Group',
	 *          'arguments' => [
	 *              [
	 *                  'type' => 'service',
	 *                  'service' => 'myComponent',
	 *              ],
	 *          ],
	 *      ],
	 *      'user' => [
	 *          'className' => '\Acme\User',
	 *      ],
	 * ];
	 * </code>
	 *
	 * @link https://docs.phalconphp.com/en/latest/reference/di.html
	 */
	public function loadFromPhp(string! filePath) -> void
	{
		var services;

		let services = new Php(filePath);

		this->loadFromConfig(services);
	}

	/**
	 * Loads services from a Config object.
	 */
	protected function loadFromConfig(<Config> config) -> void
	{
		var services, name, service;

		let services = config->toArray();

		for name, service in services {
			this->set(name, service, isset service["shared"] && service["shared"]);
		}
	}
}
