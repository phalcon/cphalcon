
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (https://phalconphp.com)       |
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

use Exception;
use Phalcon\Exception as PhalconException;
use Phalcon\DiInterface;
use Phalcon\DispatcherInterface;
use Phalcon\DispatcherInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\FilterInterface;

/**
 * Phalcon\Dispatcher
 *
 * This is the base class for Phalcon\Mvc\Dispatcher and Phalcon\Cli\Dispatcher.
 * This class can't be instantiated directly, you can use it to create your own dispatchers.
 */
abstract class Dispatcher implements DispatcherInterface, InjectionAwareInterface, EventsAwareInterface
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

	protected _params = [];

	protected _returnedValue = null;

	protected _lastHandler = null;

	protected _defaultNamespace = null;

	protected _defaultHandler = null;

	protected _defaultAction = "";

	protected _handlerSuffix = "";

	protected _actionSuffix = "Action";

	protected _previousNamespaceName = null;

	protected _previousHandlerName = null;

	protected _previousActionName = null;

	protected _modelBinding = false;
	
	protected _isControllerInitialize = false;

	const EXCEPTION_NO_DI = 0;

	const EXCEPTION_CYCLIC_ROUTING = 1;

	const EXCEPTION_HANDLER_NOT_FOUND = 2;

	const EXCEPTION_INVALID_HANDLER = 3;
	
	/// REMOVE START ///////////////////////////////////////////////////////////////////////////////////////////////////
	// @deprecated
	// @todo Remove this constant in 4.0.0 (No longer used/needed) We should also be able to decrement the 
	//       subsequent constant value back to 4 as all documentation references using the constant keys
	//       opposed to actual values. (e.g. "Dispatcher::EXCEPTION_ACTION_NOT_FOUND")
	const EXCEPTION_INVALID_PARAMS = 4;
	/// REMOVE END /////////////////////////////////////////////////////////////////////////////////////////////////////

	const EXCEPTION_ACTION_NOT_FOUND = 5;

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
		return this->_dependencyInjector;
	}

	/**
	 * Sets the events manager
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
	 * Sets the default action suffix
	 */
	public function setActionSuffix(string actionSuffix)
	{
		let this->_actionSuffix = actionSuffix;
	}

	/**
	 * Gets the default action suffix
	 */
	public function getActionSuffix() -> string
	{
		return this->_actionSuffix;
	}

	/**
	 * Sets the module where the controller is (only informative)
	 */
	public function setModuleName(string moduleName)
	{
		let this->_moduleName = moduleName;
	}

	/**
	 * Gets the module where the controller class is
	 */
	public function getModuleName() -> string
	{
		return this->_moduleName;
	}

	/**
	 * Sets the namespace where the controller class is
	 */
	public function setNamespaceName(string namespaceName)
	{
		let this->_namespaceName = namespaceName;
	}

	/**
	 * Gets a namespace to be prepended to the current handler name
	 */
	public function getNamespaceName() -> string
	{
		return this->_namespaceName;
	}

	/**
	 * Sets the default namespace
	 */
	public function setDefaultNamespace(string namespaceName)
	{
		let this->_defaultNamespace = namespaceName;
	}

	/**
	 * Returns the default namespace
	 */
	public function getDefaultNamespace() -> string
	{
		return this->_defaultNamespace;
	}

	/**
	 * Sets the default action name
	 */
	public function setDefaultAction(string actionName)
	{
		let this->_defaultAction = actionName;
	}

	/**
	 * Sets the action name to be dispatched
	 */
	public function setActionName(string actionName)
	{
		let this->_actionName = actionName;
	}

	/**
	 * Gets the latest dispatched action name
	 */
	public function getActionName() -> string
	{
		return this->_actionName;
	}

	/**
	 * Sets action params to be dispatched
	 *
	 * @param array params
	 */
	public function setParams(array params)
	{
		let this->_params = params;
	}

	/**
	 * Gets action params
	 */
	public function getParams() -> array
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
	public function getParam(param, filters = null, defaultValue = null)
	{
		var params, filter, paramValue, dependencyInjector;

		let params = this->_params;
		if !fetch paramValue, params[param] {
			return defaultValue;
		}

		if filters === null {
			return paramValue;
		}

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			this->{"_throwDispatchException"}("A dependency injection object is required to access the 'filter' service", self::EXCEPTION_NO_DI);
		}
		let filter = <FilterInterface> dependencyInjector->getShared("filter");
		return filter->sanitize(paramValue, filters);
	}

	/**
	 * Check if a param exists
	 *
	 * @param  mixed param
	 * @return boolean
	 */
	public function hasParam(param) -> boolean
	{
		return isset this->_params[param];
	}

	/**
	 * Returns the current method to be/executed in the dispatcher
	 */
	public function getActiveMethod() -> string
	{
		return this->_actionName . this->_actionSuffix;
	}

	/**
	 * Checks if the dispatch loop is finished or has more pendent controllers/tasks to dispatch
	 */
	public function isFinished() -> boolean
	{
		return this->_finished;
	}

	/**
	 * Sets the latest returned value by an action manually
	 *
	 * @param mixed value
	 */
	public function setReturnedValue(var value)
	{
		let this->_returnedValue = value;
	}

	/**
	 * Returns value returned by the latest dispatched action
	 *
	 * @return mixed
	 */
	public function getReturnedValue()
	{
		return this->_returnedValue;
	}

	/**
	 * Enable/Disable model binding during dispatch
	 *
	 * @param boolean value
	 */
	public function setModelBinding(boolean value)
	{
		let this->_modelBinding = value;
	}

	/**
	 * Dispatches a handle action taking into account the routing parameters
	 *
	 * @return object|false  Returns the dispatched handler class (the Controller for Mvc dispatching or or a Task 
	 *						 for Cli dispatching) or <tt>false</tt> if an exception occurred and the operation was 
	 *		                 stopped by returning <tt>false</tt> in the exception handler.
	 */
	public function dispatch()
	{
		boolean hasService, hasEventsManager;
		int numberDispatches;
		var value, handler, dependencyInjector, namespaceName, handlerName,
			actionName, params, eventsManager,
			actionSuffix, handlerClass, status, actionMethod, reflectionMethod, methodParams,
			className, paramKey, methodParam, modelName, bindModel,
			wasFresh, e;

		let dependencyInjector = <DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			this->{"_throwDispatchException"}("A dependency injection container is required to access related dispatching services", self::EXCEPTION_NO_DI);
			return false;
		}

		let eventsManager = <ManagerInterface> this->_eventsManager;
		let hasEventsManager = typeof eventsManager == "object";
		
		if hasEventsManager {
			try {
				// Calling beforeDispatchLoop event 
				// Note: Allow user to forward in the beforeDispatchLoop. 
				if eventsManager->fire("dispatch:beforeDispatchLoop", this) === false && this->_finished !== false {
					return false;
				}
			} catch Exception, e {
				// Exception occurred in beforeDispatchLoop. 
				
				// The user can optionally forward now in the `dispatch:beforeException` event or 
				// return <tt>false</tt> to handle the exception and prevent it from bubbling. In
				// the event the user does forward but does or does not return false, we assume the forward
				// takes precedence. The returning false intuitively makes more sense when inside the 
				// dispatch loop and technically we are not here. Therefore, returning false only impacts
				// whether non-forwarded exceptions are silently handled or bubbled up the stack. Note that
				// this behavior is slightly different than other subsequent events handled inside the
				// dispatch loop.

				let status = this->{"_handleException"}(e);
				if this->_finished !== false {
					// No forwarding
					if status === false {
						return false;
					}

					// Otherwise, bubble Exception
					throw e;
				}

				// Otherwise, user forwarded, continue
			}
		}

		let value = null,
			handler = null,
			numberDispatches = 0,
			actionSuffix = this->_actionSuffix,
			this->_finished = false;

		while !this->_finished {
			let numberDispatches++;

			// Throw an exception after 256 consecutive forwards
			if numberDispatches == 256 {
				this->{"_throwDispatchException"}("Dispatcher has detected a cyclic routing causing stability problems", self::EXCEPTION_CYCLIC_ROUTING);
				break;
			}
			
			let this->_finished = true;
			this->_resolveEmptyProperties();
		
			if hasEventsManager {
				try {
					// Calling "dispatch:beforeDispatch" event
					if eventsManager->fire("dispatch:beforeDispatch", this) === false || this->_finished === false {
						continue;
					}
				} catch Exception, e {
					if this->{"_handleException"}(e) === false || this->_finished === false {
						continue;
					}
		
					throw e;
				}
			}

			let handlerClass = this->getHandlerClass();

			// Handlers are retrieved as shared instances from the Service Container
			let hasService = (bool) dependencyInjector->has(handlerClass);
			if !hasService {
				// DI doesn't have a service with that name, try to load it using an autoloader
				let hasService = (bool) class_exists(handlerClass);
			}

			// If the service can be loaded we throw an exception
			if !hasService {
				let status = this->{"_throwDispatchException"}(handlerClass . " handler class cannot be loaded", self::EXCEPTION_HANDLER_NOT_FOUND);
				if status === false && this->_finished === false {
					continue;
				}
				break;
			}
						
			let handler = dependencyInjector->getShared(handlerClass);
			let wasFresh = dependencyInjector->wasFreshInstance();

			// Handlers must be only objects
			if typeof handler !== "object" {
				let status = this->{"_throwDispatchException"}("Invalid handler returned from the services container", self::EXCEPTION_INVALID_HANDLER);
				if status === false && this->_finished === false {
					continue;
				}
				break;
			}

			let this->_activeHandler = handler;
			let namespaceName = this->_namespaceName;
			let handlerName = this->_handlerName;
			let actionName = this->_actionName;

			// Check if the method exists in the handler
			let actionMethod = actionName . actionSuffix;

			if !is_callable([handler, actionMethod]) {
				/// REMOVE START ///////////////////////////////////////////////////////////////////////////////////////
				// Call "dispatch:beforeNotFoundAction" event
				// @deprecated
				// @todo Remove this from 4.0.0 with blog notice (Docs already updated)
				if hasEventsManager {
					if eventsManager->fire("dispatch:beforeNotFoundAction", this) === false {
						continue;
					}

					if this->_finished === false {
						continue;
					}
				}
				/// REMOVE END /////////////////////////////////////////////////////////////////////////////////////////

				// Try to throw an exception when an action isn't defined on the object
				let status = this->{"_throwDispatchException"}("Action '" . actionName . "' was not found on handler '" . handlerName . "'", self::EXCEPTION_ACTION_NOT_FOUND);
				if status === false {
					if this->_finished === false {
						continue;
					}
				}

				break;
			}

			// In order to ensure that the initialize() gets called we'll destroy the current handlerClass
			// from the DI container in the event that an error occurs and we continue out of this block. This
			// is necessary because there is a disjoin between retrieval of the instance and the execution
			// of the initialize() event. From a coding perspective, it would have made more sense to probably
			// put the initialize() prior to the beforeExecuteRoute which would have solved this. However, for
			// posterity, and to remain consistency, we'll ensure the default and documented behavior works correctly.

			if hasEventsManager {
				try {
					// Calling "dispatch:beforeExecuteRoute" event
					if eventsManager->fire("dispatch:beforeExecuteRoute", this) === false || this->_finished === false {
						dependencyInjector->remove(handlerClass);
						continue;
					}
				} catch Exception, e {
					if this->{"_handleException"}(e) === false || this->_finished === false {
						dependencyInjector->remove(handlerClass);
						continue;
					}
		
					throw e;
				}
			}

			if method_exists(handler, "beforeExecuteRoute") {
				try {
					// Calling "beforeExecuteRoute" as direct method
					if handler->beforeExecuteRoute(this) === false || this->_finished === false {
						dependencyInjector->remove(handlerClass);
						continue;
					}
				} catch Exception, e {
					if this->{"_handleException"}(e) === false || this->_finished === false {
						dependencyInjector->remove(handlerClass);
						continue;
					}
		
					throw e;
				}
			}

			// Call the "initialize" method just once per request
			if wasFresh === true && method_exists(handler, "initialize") {
				try {
					let this->_isControllerInitialize = true;
					handler->initialize();

				} catch Exception, e {
					let this->_isControllerInitialize = false;
					
					// If this is a dispatch exception (e.g. From forwarding) ensure we don't handle this twice. In
					// order to ensure this doesn't happen all other exceptions thrown outside this method
					// in this class should not call "_throwDispatchException" but instead throw a normal Exception.

					if this->{"_handleException"}(e) === false || this->_finished === false {
						continue;
					}
		
					throw e;
				}
				
				let this->_isControllerInitialize = false;
				
			    // Calling "dispatch:afterInitialize" event
				if eventsManager {
					try {
						if eventsManager->fire("dispatch:afterInitialize", this) === false || this->_finished === false {
							continue;
						}
					} catch Exception, e {
						if this->{"_handleException"}(e) === false || this->_finished === false {
							continue;
						}
			
						throw e;
					}
				}
			}

			let params = this->_params;
				
			if this->_modelBinding === true {
				// Check if we can bind a model based on what the controller action is expecting
				let reflectionMethod = new \ReflectionMethod(handlerClass, actionMethod);
				let methodParams = reflectionMethod->getParameters();

				for paramKey, methodParam in methodParams {
					if methodParam->getClass() {
						let className = methodParam->getClass()->getName();
						if typeof className === "string" {
							// If we are in a base class and the child implements BindModelInterface we getModelName
							if className === "Phalcon\\Mvc\\Model" {
								if in_array("Phalcon\\Mvc\\Controller\\BindModelInterface", class_implements(handlerClass)) {
									let modelName = call_user_func([handlerClass, "getModelName"]);
									let bindModel = call_user_func_array([modelName, "findFirst"], [params[paramKey]]);
									let params[paramKey] = bindModel;
									break;
								}
							}

							// Check if Model is defined
							if is_subclass_of(className, "Phalcon\\Mvc\\Model") {
								let bindModel = call_user_func_array([className, "findFirst"], [params[paramKey]]);
								let params[paramKey] = bindModel;
								break;
							}
						}
					}
				}
			}

			// Save the current handler
			let this->_lastHandler = handler;

			try {
				let this->_returnedValue = this->callActionMethod(handler, actionMethod, params);
				
				if this->_finished === false {
					continue;
				}
				
			} catch Exception, e {
				if this->{"_handleException"}(e) === false || this->_finished === false {
					continue;
				}
				
				throw e;
			}
			
			// Calling "dispatch:afterExecuteRoute" event
			if hasEventsManager {
				try {
					if eventsManager->fire("dispatch:afterExecuteRoute", this, value) === false || this->_finished === false {
						continue;
					}				
				} catch Exception, e {
					if this->{"_handleException"}(e) === false || this->_finished === false {
						continue;
					}
					
					throw e;
				}
			}

			// Calling "afterExecuteRoute" as direct method
			if method_exists(handler, "afterExecuteRoute") {
				try {
					if handler->afterExecuteRoute(this, value) === false || this->_finished === false {
						continue;
					}				
				} catch Exception, e {
					if this->{"_handleException"}(e) === false || this->_finished === false {
						continue;
					}
					
					throw e;
				}
			}
			
			// Calling "dispatch:afterDispatch" event
			if hasEventsManager {
				try {
					eventsManager->fire("dispatch:afterDispatch", this, value);			
				} catch Exception, e {
				    // Still check for finished here as we want to prioritize forwarding() calls
					if this->{"_handleException"}(e) === false || this->_finished === false {
						continue;
					}
					
					throw e;
				}
			}
		}

		if hasEventsManager {
			try {
				// Calling "dispatch:afterDispatchLoop" event
				// Note: We don't worry about forwarding in after dispatch loop.
				eventsManager->fire("dispatch:afterDispatchLoop", this);
			} catch Exception, e {
				// Exception occurred in afterDispatchLoop. 
				if this->{"_handleException"}(e) === false {
				    return false;
				}
				
				// Otherwise, bubble Exception
				throw e;
			}
		}

		return handler;
	}

	/**
	 * Forwards the execution flow to another controller/action
	 * Dispatchers are unique per module. Forwarding between modules is not allowed
	 *
	 * <code>
	 * 	$this->dispatcher->forward([
	 * 		"controller" => "posts",
	 *		"action" => "index"
	 *  ]);
	 * </code>
	 */
	public function forward(array forward)
	{
		var namespaceName, controllerName, params, actionName, taskName;

		if this->_isControllerInitialize === true {
			throw new PhalconException("Forwarding inside a controller's initialize() method is forbidden");
		}
		
		// Save current values as previous to ensure calls to getPrevious methods don't return <tt>null</tt>.
		let this->_previousNamespaceName = this->_namespaceName,
			this->_previousHandlerName = this->_handlerName,
			this->_previousActionName = this->_actionName;
				
		// Check if we need to forward to another namespace.
		if fetch namespaceName, forward["namespace"] {
			let this->_namespaceName = namespaceName;
		}

		// Check if we need to forward to another controller.
		if fetch controllerName, forward["controller"] {
			let this->_handlerName = controllerName;
		} elseif fetch taskName, forward["task"] {
			let this->_handlerName = taskName;
		}

		// Check if we need to forward to another action
		if fetch actionName, forward["action"] {
			let this->_actionName = actionName;
		}

		// Check if we need to forward changing the current parameters
		if fetch params, forward["params"] {
			let this->_params = params;
		}

		let this->_finished = false,
			this->_forwarded = true;
	}

	/**
	 * Check if the current executed action was forwarded by another one
	 */
	public function wasForwarded() -> boolean
	{
		return this->_forwarded;
	}

	/**
	 * Possible class name that will be located to dispatch the request
	 */
	public function getHandlerClass() -> string
	{
		var handlerSuffix, handlerName, namespaceName,
			camelizedClass, handlerClass;

		this->_resolveEmptyProperties();

		let handlerSuffix = this->_handlerSuffix,
			handlerName = this->_handlerName,
			namespaceName = this->_namespaceName;

		// We don't camelize the classes if they are in namespaces
		if !memstr(handlerName, "\\") {
			let camelizedClass = camelize(handlerName);
		} else {
			let camelizedClass = handlerName;
		}

		// Create the complete controller class name prepending the namespace
		if namespaceName {
			if ends_with(namespaceName, "\\") {
				let handlerClass = namespaceName . camelizedClass . handlerSuffix;
			} else {
				let handlerClass = namespaceName . "\\" . camelizedClass . handlerSuffix;
			}
		} else {
			let handlerClass = camelizedClass . handlerSuffix;
		}

		return handlerClass;
	}

	public function callActionMethod(handler, string actionMethod, array! params = [])
	{
		return call_user_func_array([handler, actionMethod], params);
	}

	/**
	 * Set empty properties to their defaults (where defaults are available)
	 */
	protected function _resolveEmptyProperties() -> void
	{
		// If the current namespace is null we used the set in this->_defaultNamespace
		if !this->_namespaceName {
			let this->_namespaceName = this->_defaultNamespace;
		}

		// If the handler is null we use the set in this->_defaultHandler
		if !this->_handlerName {
			let this->_handlerName = this->_defaultHandler;
		}

		// If the action is null we use the set in this->_defaultAction
		if !this->_actionName {
			let this->_actionName = this->_defaultAction;
		}
	}
}
