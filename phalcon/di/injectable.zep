
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

use Phalcon\Di;
use Phalcon\DiInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Di\Exception;
use Phalcon\Session\BagInterface;

/**
 * Phalcon\Di\Injectable
 *
 * This class allows to access services in the services container by just only accessing a public property
 * with the same name of a registered service
 *
 * @property \Phalcon\Mvc\Dispatcher|\Phalcon\Mvc\DispatcherInterface $dispatcher;
 * @property \Phalcon\Mvc\Router|\Phalcon\Mvc\RouterInterface $router
 * @property \Phalcon\Mvc\Url|\Phalcon\Mvc\UrlInterface $url
 * @property \Phalcon\Http\Request|\Phalcon\HTTP\RequestInterface $request
 * @property \Phalcon\Http\Response|\Phalcon\HTTP\ResponseInterface $response
 * @property \Phalcon\Http\Response\Cookies|\Phalcon\Http\Response\CookiesInterface $cookies
 * @property \Phalcon\Filter|\Phalcon\FilterInterface $filter
 * @property \Phalcon\Flash\Direct $flash
 * @property \Phalcon\Flash\Session $flashSession
 * @property \Phalcon\Session\Adapter\Files|\Phalcon\Session\Adapter|\Phalcon\Session\AdapterInterface $session
 * @property \Phalcon\Events\Manager $eventsManager
 * @property \Phalcon\Db\AdapterInterface $db
 * @property \Phalcon\Security $security
 * @property \Phalcon\Crypt $crypt
 * @property \Phalcon\Tag $tag
 * @property \Phalcon\Escaper|\Phalcon\EscaperInterface $escaper
 * @property \Phalcon\Annotations\Adapter\Memory|\Phalcon\Annotations\Adapter $annotations
 * @property \Phalcon\Mvc\Model\Manager|\Phalcon\Mvc\Model\ManagerInterface $modelsManager
 * @property \Phalcon\Mvc\Model\MetaData\Memory|\Phalcon\Mvc\Model\MetadataInterface $modelsMetadata
 * @property \Phalcon\Mvc\Model\Transaction\Manager $transactionManager
 * @property \Phalcon\Assets\Manager $assets
 * @property \Phalcon\DI|\Phalcon\DiInterface $di
 * @property \Phalcon\Session\Bag $persistent
 * @property \Phalcon\Mvc\View|\Phalcon\Mvc\ViewInterface $view
 */
abstract class Injectable implements InjectionAwareInterface, EventsAwareInterface
{

	/**
	 * Dependency Injector
	 *
	 * @var \Phalcon\DiInterface
	 */
	protected _dependencyInjector;

	/**
	 * Events Manager
	 *
	 * @var \Phalcon\Events\ManagerInterface
	 */
	protected _eventsManager;

	/**
	 * Sets the dependency injector
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 */
	public function getDI() -> <DiInterface>
	{
		var dependencyInjector;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			let dependencyInjector = Di::getDefault();
		}
		return dependencyInjector;
	}

	/**
	 * Sets the event manager
	 */
	public function setEventsManager(<ManagerInterface> eventsManager)
	{
		let this->_eventsManager = eventsManager;
	}

	/**
	 * Returns the internal event manager
	 */
	public function getEventsManager() -> <ManagerInterface>
	{
		return this->_eventsManager;
	}

	/**
	 * Magic method __get
	 */
	public function __get(string! propertyName)
	{
		var dependencyInjector, service, persistent;

		let dependencyInjector = <DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			let dependencyInjector = \Phalcon\Di::getDefault();
			if typeof dependencyInjector != "object" {
				throw new Exception("A dependency injection object is required to access the application services");
			}
		}

		/**
		 * Fallback to the PHP userland if the cache is not available
		 */
		if dependencyInjector->has(propertyName) {
			let service = dependencyInjector->getShared(propertyName);
			let this->{propertyName} = service;
			return service;
		}

		if propertyName == "di" {
			let this->{"di"} = dependencyInjector;
			return dependencyInjector;
		}

		/**
		 * Accessing the persistent property will create a session bag on any class
		 */
		if propertyName == "persistent" {
			let persistent = <BagInterface> dependencyInjector->get("sessionBag", [get_class(this)]),
				this->{"persistent"} = persistent;
			return persistent;
		}

		/**
		 * A notice is shown if the property is not defined and isn't a valid service
		 */
		trigger_error("Access to undefined property " . propertyName);
		return null;
	}
}
