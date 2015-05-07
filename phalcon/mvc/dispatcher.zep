
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

namespace Phalcon\Mvc;

use Phalcon\Mvc\DispatcherInterface;
use Phalcon\Mvc\Dispatcher\Exception;
use Phalcon\Events\ManagerInterface;
use Phalcon\Http\ResponseInterface;
use Phalcon\Mvc\ControllerInterface;

/**
 * Phalcon\Mvc\Dispatcher
 *
 * Dispatching is the process of taking the request object, extracting the module name,
 * controller name, action name, and optional parameters contained in it, and then
 * instantiating a controller and calling an action of that controller.
 *
 *<code>
 *
 *	$di = new \Phalcon\Di();
 *
 *	$dispatcher = new \Phalcon\Mvc\Dispatcher();
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
class Dispatcher extends \Phalcon\Dispatcher implements DispatcherInterface
{

	protected _handlerSuffix = "Controller";

	protected _defaultHandler = "index";

	protected _defaultAction = "index";

	/**
	 * Sets the default controller suffix
	 */
	public function setControllerSuffix(string! controllerSuffix)
	{
		let this->_handlerSuffix = controllerSuffix;
	}

	/**
	 * Sets the default controller name
	 */
	public function setDefaultController(string! controllerName)
	{
		let this->_defaultHandler = controllerName;
	}

	/**
	 * Sets the controller name to be dispatched
	 */
	public function setControllerName(string! controllerName)
	{
		let this->_handlerName = controllerName;
	}

	/**
	 * Gets last dispatched controller name
	 */
	public function getControllerName() -> string
	{
		return this->_handlerName;
	}

	/**
	 * Gets previous dispatched controller name
	 */
	public function getPreviousControllerName() -> string
	{
		return this->_previousHandlerName;
	}

	/**
	 * Gets previous dispatched action name
	 */
	public function getPreviousActionName() -> string
	{
		return this->_previousActionName;
	}

	/**
	 * Throws an internal exception
	 */
	protected function _throwDispatchException(string! message, int exceptionCode = 0)
	{
		var dependencyInjector, response, exception;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception(
				"A dependency injection container is required to access the 'response' service",
				\Phalcon\Dispatcher::EXCEPTION_NO_DI
			);
		}

		let response = <ResponseInterface> dependencyInjector->getShared("response");

		/**
		 * Dispatcher exceptions automatically sends a 404 status
		 */
		response->setStatusCode(404, "Not Found");

		/**
		 * Create the real exception
		 */
		let exception = new Exception(message, exceptionCode);

		if this->_handleException(exception) === false {
			return false;
		}

		/**
		 * Throw the exception if it wasn't handled
		 */
		throw exception;
	}

	/**
	 * Handles a user exception
	 */
	protected function _handleException(<\Exception> exception)
	{
		var eventsManager;
		let eventsManager = <ManagerInterface> this->_eventsManager;
		if typeof eventsManager == "object" {
			if eventsManager->fire("dispatch:beforeException", this, exception) === false {
				return false;
			}
		}
	}

	/**
	 * Possible controller class name that will be located to dispatch the request
	 */
	public function getControllerClass() -> string
	{
		return this->getHandlerClass();
	}

	/**
	 * Returns the lastest dispatched controller
	 */
	public function getLastController() -> <ControllerInterface>
	{
		return this->_lastHandler;
	}

	/**
	 * Returns the active controller in the dispatcher
	 */
	public function getActiveController() -> <ControllerInterface>
	{
		return this->_activeHandler;
	}
}
