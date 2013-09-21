
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
 |          Rack Lin <racklin@gmail.com>                                  |
 +------------------------------------------------------------------------+
 */

namespace Phalcon;

/**
 * Phalcon\Dispatcher
 *
 * This is the base class for Phalcon\Mvc\Dispatcher and Phalcon\CLI\Dispatcher.
 * This class can't be instantiated directly, you can use it to create your own dispatchers
 */
abstract class Dispatcher implements Phalcon\DispatcherInterface, Phalcon\Di\InjectionAwareInterface, Phalcon\Events\EventsAwareInterface
{

	protected _dependencyInjector;

	protected _eventsManager;

	protected _activeHandler;

	protected _finished;

	protected _forwarded = false;

	protected _moduleName = null;

	protected _namespaceName = null;

	protected _handlerName = null;

	protected _actionName = null;

	protected _params;

	protected _returnedValue = null;

	protected _lastHandler = null;

	protected _defaultNamespace = null;

	protected _defaultHandler = null;

	protected _defaultAction = "";

	protected _handlerSuffix = "";

	protected _actionSuffix = "Action";

	const EXCEPTION_NO_DI = 0;

	const EXCEPTION_CYCLIC_ROUTING = 1;

	const EXCEPTION_HANDLER_NOT_FOUND = 2;

	const EXCEPTION_INVALID_HANDLER = 3;

	const EXCEPTION_INVALID_PARAMS = 4;

	const EXCEPTION_ACTION_NOT_FOUND = 5;

	/**
	 * Phalcon\Dispatcher constructor
	 *
	 */
	public function __construct()
	{
		let this->_params = [];
	}

	/**
	 * Sets the dependency injector
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<Phalcon\DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI()
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets the events manager
	 *
	 * @param Phalcon\Events\ManagerInterface eventsManager
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
	 * Sets the default action suffix
	 *
	 * @param string actionSuffix
	 */
	public function setActionSuffix(var actionSuffix)
	{
		let this->_actionSuffix = actionSuffix;
	}

	/**
	 * Sets the module where the controller is (only informative)
	 *
	 * @param string moduleName
	 */
	public function setModuleName(var moduleName)
	{
		let this->_moduleName = moduleName;
	}

	/**
	 * Gets the module where the controller class is
	 *
	 * @return string
	 */
	public function getModuleName()
	{
		return this->_moduleName;
	}

	/**
	 * Sets the namespace where the controller class is
	 *
	 * @param string namespaceName
	 */
	public function setNamespaceName(namespaceName)
	{
		let this->_namespaceName = namespaceName;
	}

	/**
	 * Gets a namespace to be prepended to the current handler name
	 *
	 * @return string
	 */
	public function getNamespaceName()
	{
		return this->_namespaceName;
	}

	/**
	 * Sets the default namespace
	 *
	 * @param string namespaceName
	 */
	public function setDefaultNamespace(namespaceName)
	{
		let this->_defaultNamespace = namespaceName;
	}

	/**
	 * Returns the default namespace
	 *
	 * @return string
	 */
	public function getDefaultNamespace()
	{
		return this->_defaultNamespace;
	}

	/**
	 * Sets the default action name
	 *
	 * @param string actionName
	 */
	public function setDefaultAction(actionName)
	{
		let this->_defaultAction = actionName;
	}

	/**
	 * Sets the action name to be dispatched
	 *
	 * @param string actionName
	 */
	public function setActionName(var actionName)
	{
		let this->_actionName = actionName;
	}

	/**
	 * Gets the lastest dispatched action name
	 *
	 * @return string
	 */
	public function getActionName()
	{
		return this->_actionName;
	}

	/**
	 * Sets action params to be dispatched
	 *
	 * @param array params
	 */
	public function setParams(var params)
	{
		if typeof params != "array" {
			this->{"_throwDispatchException"}("Parameters must be an Array");
			return null;
		}
		let this->_params = params;
	}

	/**
	 * Gets action params
	 *
	 * @return array
	 */
	public function getParams()
	{
		return this->_params;
	}

	/**
	 * Set a param by its name or numeric index
	 *
	 * @param  mixed param
	 * @param  mixed value
	 */
	public function setParam(var param, var value)
	{
		let this->_params[param] = value;
	}

	/**
	 * Gets a param by its name or numeric index
	 *
	 * @param  mixed param
	 * @param  string|array filters
	 * @param  mixed defaultValue
	 * @return mixed
	 */
	public function getParam(param, filters=null, defaultValue=null)
	{
		var params, filter, paramValue, dependencyInjector;

		let params = this->_params;
		if  isset params[param] {
			let paramValue = params[param];
			if filters !== null {
				let dependencyInjector = this->_dependencyInjector;
				if typeof dependencyInjector != "object" {
					this->{"_throwDispatchException"}("A dependency injection object is required to access the 'filter' service", self::EXCEPTION_NO_DI);
				}
				let filter = dependencyInjector->getShared("filter");
				return filter->sanitize(paramValue, filters);
			} else {
				return paramValue;
			}
		}
		return defaultValue;
	}

	/**
	 * Returns the current method to be/executed in the dispatcher
	 *
	 * @return string
	 */
	public function getActiveMethod()
	{
		return this->_actionName . this->_actionSuffix;
	}

	/**
	 * Checks if the dispatch loop is finished or has more pendent controllers/tasks to dispatch
	 *
	 * @return boolean
	 */
	public function isFinished()
	{
		return this->_finished;
	}

	/**
	 * Sets the latest returned value by an action manually
	 *
	 * @param mixed value
	 */
	public function setReturnedValue(value)
	{
		let this->_returnedValue = value;
	}

	/**
	 * Returns value returned by the lastest dispatched action
	 *
	 * @return mixed
	 */
	public function getReturnedValue()
	{
		return this->_returnedValue;
	}

	/**
	 * Dispatches a handle action taking into account the routing parameters
	 *
	 * @return object
	 */
	public function dispatch()
	{
		boolean hasService;
		int numberDispatches;
		var value, handler, dependencyInjector, namespaceName, handlerName,
			actionName, camelizedClass, params, eventsManager,
			handlerSuffix, actionSuffix, handlerClass, status, actionMethod;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			this->{"_throwDispatchException"}("A dependency injection container is required to access related dispatching services", self::EXCEPTION_NO_DI);
			return false;
		}

		/**
		 * Calling beforeDispatchLoop
		 */
		let eventsManager = <Phalcon\Events\Manager> this->_eventsManager;
		if typeof eventsManager == "object" {
			if eventsManager->fire("dispatch:beforeDispatchLoop", this) === false {
				return false;
			}
		}

		let value = null,
			handler = null,
			numberDispatches = 0,

			handlerSuffix = this->_handlerSuffix,
			actionSuffix = this->_actionSuffix,

			this->_finished = false;

		while !this->_finished {

			let numberDispatches++;

			/**
			 * Throw an exception after 256 consecutive forwards
			 */
			if numberDispatches == 256 {
				this->{"_throwDispatchException"}("Dispatcher has detected a cyclic routing causing stability problems", self::EXCEPTION_CYCLIC_ROUTING);
				break;
			}

			let this->_finished = true;

			/**
			 * If the current namespace is null we used the set in this->_defaultNamespace
			 */
			let namespaceName = this->_namespaceName;
			if !namespaceName {
				let namespaceName = this->_defaultNamespace;
				let this->_namespaceName = namespaceName;
			}

			/**
			 * If the handler is null we use the set in this->_defaultHandler
			 */
			let handlerName = this->_handlerName;
			if !handlerName {
				let handlerName = this->_defaultHandler;
				let this->_handlerName = handlerName;
			}

			/**
			 * If the action is null we use the set in this->_defaultAction
			 */
			let actionName = this->_actionName;
			if !actionName {
				let actionName = this->_defaultAction;
				let this->_actionName = actionName;
			}

			/**
			 * Calling beforeDispatch
			 */
			if typeof eventsManager == "object" {

				if eventsManager->fire("dispatch:beforeDispatch", this) === false {
					continue;
				}

				/**
				 * Check if the user made a forward in the listener
				 */
				if this->_finished === false {
					continue;
				}
			}

			/**
			 * We don't camelize the classes if they are in namespaces
			 */
			if !memstr(handlerName, "\\") {
				let camelizedClass = camelize(handlerName);
			} else {
				let camelizedClass = handlerName;
			}

			/**
			 * Create the complete controller class name prepending the namespace
			 */
			if namespaceName {
				if ends_with(namespaceName, "\\") {
					let handlerClass = namespaceName . camelizedClass . handlerSuffix;
				} else {
					let handlerClass = namespaceName . "\\" . camelizedClass . handlerSuffix;
				}
			} else {
				let handlerClass = camelizedClass . handlerSuffix;
			}

			/**
			 * Handlers are retrieved as shared instances from the Service Container
			 */
			let hasService = (bool) dependencyInjector->has(handlerClass);
			if !hasService {
				/**
				 * DI doesn't have a service with that name, try to load it using an autoloader
				 */
				let hasService = (bool) class_exists(handlerClass);
			}

			/**
			 * If the service can be loaded we throw an exception
			 */
			if !hasService {
				let status = this->{"_throwDispatchException"}(handlerClass . " handler class cannot be loaded", self::EXCEPTION_HANDLER_NOT_FOUND);
				if status === false {

					/**
					 * Check if the user made a forward in the listener
					 */
					if this->_finished === false {
						continue;
					}
				}
				break;
			}

			/**
			 * Handlers must be only objects
			 */
			let handler = dependencyInjector->getShared(handlerClass);
			if typeof handler != "object" {
				let status = this->{"_throwDispatchException"}("Invalid handler returned from the services container", self::EXCEPTION_INVALID_HANDLER);
				if status === false {
					if this->_finished === false {
						continue;
					}
				}
				break;
			}

			let this->_activeHandler = handler;

			/**
			 * Check if the params is an array
			 */
			let params = this->_params;
			if typeof params != "array" {

				/**
				 * An invalid parameter variable was passed throw an exception
				 */
				let status = this->{"_throwDispatchException"}("Action parameters must be an Array", self::EXCEPTION_INVALID_PARAMS);
				if status === false {
					if this->_finished === false {
						continue;
					}
				}
				break;
			}

			/**
		 	 * Check if the method exists in the handler
		 	 */
			let actionMethod = actionName . actionSuffix;
			if !method_exists(handler, actionMethod) {

				/**
				 * Call beforeNotFoundAction
				 */
				if typeof eventsManager == "object" {

					if eventsManager->fire("dispatch:beforeNotFoundAction", this) === false {
						continue;
					}

					if this->_finished === false {
						continue;
					}
				}

				/**
				 * Try to throw an exception when an action isn't defined on the object
				 */
				let status = this->{"_throwDispatchException"}("Action '" . actionName . "' was not found on handler '" . handlerName . "'", self::EXCEPTION_ACTION_NOT_FOUND);
				if status === false {
					if this->_finished === false {
						continue;
					}
				}

				break;
			}

			/**
			 * Calling beforeExecuteRoute
			 */
			if typeof eventsManager == "object" {

				if eventsManager->fire("dispatch:beforeExecuteRoute", this) === false {
					continue;
				}

				/**
				 * Check if the user made a forward in the listener
				 */
				if this->_finished === false {
					continue;
				}
			}

			/**
			 * Calling beforeExecuteRoute as callback and event
			 */
			if method_exists(handler, "beforeExecuteRoute") {

				if handler->beforeExecuteRoute(this) === false {
					continue;
				}

				/**
				 * Check if the user made a forward in the listener
				 */
				if this->_finished === false {
					continue;
				}
			}

			/**
			 * If the object was recently created in the DI we initialize it
			 */
			if dependencyInjector->wasFreshInstance() === true {
				if method_exists(handler, "initialize") {
					handler->initialize();
				}
			}

			/**
			 * We update the latest value produced by the latest handler
			 */
			let this->_returnedValue = call_user_func_array([handler, actionMethod], params),
				this->_lastHandler = handler;

			/**
			  * Calling afterExecuteRoute
			  */
			if typeof eventsManager == "object" {

				if eventsManager->fire("dispatch:afterExecuteRoute", this, value) === false {
					continue;
				}

				if this->_finished === false {
					continue;
				}

				/**
				 * Call afterDispatch
				 */
				eventsManager->fire("dispatch:afterDispatch", this);
			}

			/**
			 * Calling afterExecuteRoute as callback and event
			 */
			if method_exists(handler, "afterExecuteRoute") {

				if handler->afterExecuteRoute(this, value) === false {
					continue;
				}

				if this->_finished === false {
					continue;
				}
			}

		}

		/**
		 * Call afterDispatchLoop
		 */
		if typeof eventsManager == "object" {
			eventsManager->fire("dispatch:afterDispatchLoop", this);
		}

		return handler;
	}

	/**
	 * Forwards the execution flow to another controller/action
	 * Dispatchers are unique per module. Forwarding between modules is not allowed
	 *
	 *<code>
	 *  $this->dispatcher->forward(array("controller" => "posts", "action" => "index"));
	 *</code>
	 *
	 * @param array forward
	 */
	public function forward(var forward)
	{
		var namespaceName, controllerName, params, actionName, taskName;

		if typeof forward != "array" {
			this->{"_throwDispatchException"}("Forward parameter must be an Array");
			return null;
		}

		/**
		 * Check if we need to forward to another namespace
		 */
		if fetch namespaceName, forward["namespace"] {
			let this->_namespaceName = namespaceName;
		}

		/**
		 * Check if we need to forward to another controller
		 */
		if fetch controllerName, forward["controller"] {
			let this->_handlerName = controllerName;
		} else {
			if fetch taskName, forward["task"] {
				let this->_handlerName = taskName;
			}
		}

		/**
		 * Check if we need to forward to another action
		 */
		if fetch actionName, forward["action"] {
			let this->_actionName = actionName;
		}

		/**
		 * Check if we need to forward changing the current parameters
		 */
		if fetch params, forward["params"] {
			let this->_params = params;
		}

		let this->_finished = false,
			this->_forwarded = true;
	}

	/**
	 * Check if the current executed action was forwarded by another one
	 *
	 * @return boolean
	 */
	public function wasForwarded()
	{
		return this->_forwarded;
	}

}
