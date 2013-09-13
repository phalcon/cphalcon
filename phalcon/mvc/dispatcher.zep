
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

namespace Phalcon\Mvc;

/**
 * Phalcon\Mvc\Dispatcher
 *
 * Dispatching is the process of taking the request object, extracting the module name,
 * controller name, action name, and optional parameters contained in it, and then
 * instantiating a controller and calling an action of that controller.
 *
 *<code>
 *
 *	$di = new Phalcon\Di();
 *
 *	$dispatcher = new Phalcon\Mvc\Dispatcher();
 *
 *  $dispatcher->setDI($di);
 *
 *	$dispatcher->setControllerName('posts');
 *	$dispatcher->setActionName('index');
 *	$dispatcher->setParams(array());
 *
 *	$controller = $dispatcher->dispatch();
 *
 *</code>
 */
class Dispatcher extends Phalcon\Dispatcher implements Phalcon\Mvc\DispatcherInterface
{

	protected _handlerSuffix = "Controller";

	protected _defaultHandler = "index";

	protected _defaultAction = "index";

	/**
	 * Sets the default controller suffix
	 *
	 * @param string controllerSuffix
	 */
	public function setControllerSuffix(controllerSuffix)
	{
		let this->_handlerSuffix = controllerSuffix;
	}

	/**
	 * Sets the default controller name
     *
	 * @param string controllerName
	 */
	public function setDefaultController(controllerName)
	{
		let this->_defaultHandler = controllerName;
	}

	/**
	 * Sets the controller name to be dispatched
	 *
	 * @param string controllerName
	 */
	public function setControllerName(controllerName)
	{
		let this->_handlerName = controllerName;
	}

	/**
	 * Gets last dispatched controller name
	 *
	 * @return string
	 */
	public function getControllerName()
	{
		return this->_handlerName;
	}

	/**
	 * Throws an internal exception
	 *
	 * @param string message
	 * @param int exceptionCode
	 */
	protected function _throwDispatchException(message, exceptionCode=0)
	{
		var eventsManager, dependencyInjector, response, exception;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Phalcon\Mvc\Dispatcher\Exception(
				"A dependency injection container is required to access the 'response' service",
				Phalcon\Dispatcher::EXCEPTION_NO_DI
			);
		}

		let response = dependencyInjector->getShared("response");

		/**
		 * Dispatcher exceptions automatically sends 404 status
		 */
		response->setStatusCode(404, "Not Found");

		/**
		 * Create the real exception
		 */
		let exception = new Phalcon\Mvc\Dispatcher\Exception(message, exceptionCode);

		let eventsManager = this->_eventsManager;
		if typeof eventsManager == "object" {
			if eventsManager->fire("dispatch:beforeException", this, exception) === false {
				return false;
			}
		}

		/**
		 * Throw the exception if it wasn't handled
		 */
		throw exception;
	}

	/**
	 * Handles a user exception
	 *
	 * @param \Exception exception
	 */
	protected function _handleException(exception)
	{
		var eventsManager;
		let eventsManager = this->_eventsManager;
		if typeof eventsManager == "object" {
			if eventsManager->fire("dispatch:beforeException", this, exception) === false {
				return false;
			}
		}

	}

	/**
	 * Possible controller class name that will be located to dispatch the request
	 *
	 * @return string
	 */
	public function getControllerClass()
	{
		return this->{"getHandlerName"}();
	}

	/**
	 * Returns the lastest dispatched controller
	 *
	 * @return Phalcon\Mvc\ControllerInterface
	 */
	public function getLastController()
	{
		return this->_lastHandler;
	}

	/**
	 * Returns the active controller in the dispatcher
	 *
	 * @return Phalcon\Mvc\ControllerInterface
	 */
	public function getActiveController()
	{
		return this->_activeHandler;
	}

}
