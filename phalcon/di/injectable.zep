
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

namespace Phalcon\DI;

/**
 * Phalcon\DI\Injectable
 *
 * This class allows to access services in the services container by just only accessing a public property
 * with the same name of a registered service
 */
abstract class Injectable implements Phalcon\DI\InjectionAwareInterface, Phalcon\Events\EventsAwareInterface
{

	/**
	 * Dependency Injector
	 *
	 * @var Phalcon\DiInteface
	 */
	protected _dependencyInjector;

	/**
	 * Events Manager
	 *
	 * @var Phalcon\Events\ManagerInterface
	 */
	protected _eventsManager;

	/**
	 * Sets the dependency injector
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<Phalcon\DiInterface> dependencyInjector)
	{
		if typeof dependencyInjector != "object" {
			throw new Phalcon\DI\Exception("Dependency Injector is invalid");
		}
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI()
	{
		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			let dependencyInjector = Phalcon\DI::getDefault();
		}
		return dependencyInjector;
	}

	/**
	 * Sets the event manager
	 *
	 * @param Phalcon\Events\ManagerInterface $eventsManager
	 */
	public function setEventsManager(<Phalcon\Events\ManagerInterface> eventsManager)
	{
		let this->_eventsManager = eventsManager;
	}

	/**
	 * Returns the internal event manager
	 *
	 * @return Phalcon\Events\ManagerInterface
	 */
	public function getEventsManager()
	{
		return this->_eventsManager;
	}

	/**
	 * Magic method __get
	 *
	 * @param string propertyName
	 */
	public function __get(propertyName)
	{

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			let dependencyInjector = Phalcon\DI::getDefault();
			if typeof dependencyInjector != "object" {
				throw new Phalcon\DI\Exception("A dependency injection object is required to access the application services");
			}
		}

		/**
		 * Fallback to the PHP userland if the cache is not available
		 */
		let hasService = dependencyInjector->has(propertyName);
		if hasService {
			let service = dependencyInjector->getShared(propertyName);
			let this->{propertyName} = service;
			return service;
		}

		if propertyName == "di" {
			let this->{"di"} = dependencyInjector;
			return dependencyInjector;
		}

		/**
		 * Accessing the persistent property will create a session bag in any class
		 */
		if propertyName == "persistent" {
			let persistent = dependencyInjector->get("sessionBag", [get_class(this)]),
				this->persistent = persistent;
			return persistent;
		}

		/**
		 * A notice is shown if the property is not defined and isn't a valid service
		 */
		trigger_error("Access to undefined property " . propertyName);
		return null;
	}

}
