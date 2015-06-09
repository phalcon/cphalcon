
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

use Phalcon\Di\Injectable;
use Phalcon\Mvc\ViewInterface;
use Phalcon\Mvc\Application\Exception;
use Phalcon\Mvc\ModuleDefinitionInterface;
use Phalcon\Mvc\RouterInterface;
use Phalcon\DiInterface;
use Phalcon\Http\ResponseInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Mvc\DispatcherInterface;

/**
 * Phalcon\Mvc\Application
 *
 * This component encapsulates all the complex operations behind instantiating every component
 * needed and integrating it with the rest to allow the MVC pattern to operate as desired.
 *
 *<code>
 *
 * class Application extends \Phalcon\Mvc\Application
 * {
 *
 *		/**
 *		 * Register the services here to make them general or register
 *		 * in the ModuleDefinition to make them module-specific
 *		 *\/
 *		protected function _registerServices()
 *		{
 *
 *		}
 *
 *		/**
 *		 * This method registers all the modules in the application
 *		 *\/
 *		public function main()
 *		{
 *			$this->registerModules(array(
 *				'frontend' => array(
 *					'className' => 'Multiple\Frontend\Module',
 *					'path' => '../apps/frontend/Module.php'
 *				),
 *				'backend' => array(
 *					'className' => 'Multiple\Backend\Module',
 *					'path' => '../apps/backend/Module.php'
 *				)
 *			));
 *		}
 *	}
 *
 *	$application = new Application();
 *	$application->main();
 *
 *</code>
 */
class Application extends Injectable
{

	protected _defaultModule;

	protected _modules;

	protected _implicitView = true;

	/**
	 * Phalcon\Mvc\Application
	 */
	public function __construct(<DiInterface> dependencyInjector = null)
	{
		if typeof dependencyInjector == "object" {
			let this->_dependencyInjector = dependencyInjector;
		}
	}

	/**
	 * By default. The view is implicitly buffering all the output
	 * You can full disable the view component using this method
	 */
	public function useImplicitView(boolean implicitView) -> <Application>
	{
		let this->_implicitView = implicitView;
		return this;
	}

	/**
	 * Register an array of modules present in the application
	 *
	 *<code>
	 *	$this->registerModules(array(
	 *		'frontend' => array(
	 *			'className' => 'Multiple\Frontend\Module',
	 *			'path' => '../apps/frontend/Module.php'
	 *		),
	 *		'backend' => array(
	 *			'className' => 'Multiple\Backend\Module',
	 *			'path' => '../apps/backend/Module.php'
	 *		)
	 *	));
	 *</code>
	 */
	public function registerModules(array modules, boolean merge = false) -> <Application>
	{
		var registeredModules;

		if merge === false {
			let this->_modules = modules;
		} else {
			let registeredModules = this->_modules;
			if typeof registeredModules == "array" {
				let this->_modules = array_merge(registeredModules, modules);
			} else {
				let this->_modules = modules;
			}
		}

		return this;
	}

	/**
	 * Return the modules registered in the application
	 *
	 * @return array
	 */
	public function getModules()
	{
		return this->_modules;
	}

	/**
	 * Gets the module definition registered in the application via module name
	 *
	 * @param string name
	 * @return array|object
	 */
	public function getModule(string! name)
	{
		var module;

		if !fetch module, this->_modules[name] {
			throw new Exception("Module '" . name . "' isn't registered in the application container");
		}

		return module;
	}

	/**
	 * Sets the module name to be used if the router doesn't return a valid module
	 */
	public function setDefaultModule(string! defaultModule) -> <Application>
	{
		let this->_defaultModule = defaultModule;
		return this;
	}

	/**
	 * Returns the default module name
	 */
	public function getDefaultModule() -> string
	{
		return this->_defaultModule;
	}

	/**
	 * Handles a MVC request
	 *
	 * @param string uri
	 * @return Phalcon\Http\ResponseInterface|boolean
	 */
	public function handle(uri = null) -> <ResponseInterface> | boolean
	{
		var dependencyInjector, eventsManager, router, dispatcher, response, view,
			module, moduleObject, moduleName, className, path,
			implicitView, returnedResponse, controller, possibleResponse,
			renderStatus;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injection object is required to access internal services");
		}

		let eventsManager = <ManagerInterface> this->_eventsManager;

		/**
		 * Call boot event, this allow the developer to perform initialization actions
		 */
		if typeof eventsManager == "object" {
			if eventsManager->fire("application:boot", this) === false {
				return false;
			}
		}

		let router = <RouterInterface> dependencyInjector->getShared("router");

		/**
		 * Handle the URI pattern (if any)
		 */
		router->handle(uri);

		/**
		 * If the router doesn't return a valid module we use the default module
		 */
		let moduleName = router->getModuleName();
		if !moduleName {
			let moduleName = this->_defaultModule;
		}

		let moduleObject = null;

		/**
		 * Process the module definition
		 */
		if moduleName {

			if typeof eventsManager == "object" {
				if eventsManager->fire("application:beforeStartModule", this, moduleName) === false {
					return false;
				}
			}

			/**
			 * Gets the module definition
			 */
			let module = this->getModule(moduleName);

			/**
			 * A module definition must ne an array or an object
			 */
			if typeof module != "array" && typeof module != "object" {
				throw new Exception("Invalid module definition");
			}

			/**
			 * An array module definition contains a path to a module definition class
			 */
			if typeof module == "array" {

				/**
				 * Class name used to load the module definition
				 */
				if !fetch className, module["className"] {
					let className = "Module";
				}

				/**
				 * If developer specify a path try to include the file
				 */
				if fetch path, module["path"] {
					if !class_exists(className, false) {
						if file_exists(path) {
							require path;
						} else {
							throw new Exception("Module definition path '" . path . "' doesn't exist");
						}
					}
				}

				let moduleObject = <ModuleDefinitionInterface> dependencyInjector->get(className);

				/**
				 * 'registerAutoloaders' and 'registerServices' are automatically called
				 */
				moduleObject->registerAutoloaders(dependencyInjector);
				moduleObject->registerServices(dependencyInjector);

			} else {

				/**
				 * A module definition object, can be a Closure instance
				 */
				if module instanceof \Closure {
					let moduleObject = call_user_func_array(module, [dependencyInjector]);
				} else {
					throw new Exception("Invalid module definition");
				}
			}

			/**
			 * Calling afterStartModule event
			 */
			if typeof eventsManager == "object" {
				eventsManager->fire("application:afterStartModule", this, moduleObject);
			}

		}

		/**
		 * Check whether use implicit views or not
		 */
		let implicitView = this->_implicitView;

		if implicitView === true {
			let view = <ViewInterface> dependencyInjector->getShared("view");
		}

		/**
		 * We get the parameters from the router and assign them to the dispatcher
		 * Assign the values passed from the router
		 */
		let dispatcher = <DispatcherInterface> dependencyInjector->getShared("dispatcher");
		dispatcher->setModuleName(router->getModuleName());
		dispatcher->setNamespaceName(router->getNamespaceName());
		dispatcher->setControllerName(router->getControllerName());
		dispatcher->setActionName(router->getActionName());
		dispatcher->setParams(router->getParams());

		/**
		 * Start the view component (start output buffering)
		 */
		if implicitView === true {
			view->start();
		}

		/**
		 * Calling beforeHandleRequest
		 */
		if typeof eventsManager == "object" {
			if eventsManager->fire("application:beforeHandleRequest", this, dispatcher) === false {
				return false;
			}
		}

		/**
		 * The dispatcher must return an object
		 */
		let controller = dispatcher->dispatch();

		/**
		 * Get the latest value returned by an action
		 */
		let possibleResponse = dispatcher->getReturnedValue();

		if typeof possibleResponse == "boolean" && possibleResponse == false {
			let response = <ResponseInterface> dependencyInjector->getShared("response");
		} else {
			if typeof possibleResponse == "object" {

				/**
				 * Check if the returned object is already a response
				 */
				let returnedResponse = possibleResponse instanceof ResponseInterface;
			} else {
				let returnedResponse = false;
			}

			/**
			 * Calling afterHandleRequest
			 */
			if typeof eventsManager == "object" {
				eventsManager->fire("application:afterHandleRequest", this, controller);
			}

			/**
			 * If the dispatcher returns an object we try to render the view in auto-rendering mode
			 */
			if returnedResponse === false {
				if implicitView === true {
					if typeof controller == "object" {

						let renderStatus = true;

						/**
						 * This allows to make a custom view render
						 */
						if typeof eventsManager == "object" {
							let renderStatus = eventsManager->fire("application:viewRender", this, view);
						}

						/**
						 * Check if the view process has been treated by the developer
						 */
						if renderStatus !== false {

							/**
							 * Automatic render based on the latest controller executed
							 */
							view->render(
								dispatcher->getControllerName(),
								dispatcher->getActionName(),
								dispatcher->getParams()
							);
						}
					}
				}
			}

			/**
			 * Finish the view component (stop output buffering)
			 */
			if implicitView === true {
				view->finish();
			}

			if returnedResponse === false {

				let response = <ResponseInterface> dependencyInjector->getShared("response");
				if implicitView === true {

					/**
					 * The content returned by the view is passed to the response service
					 */
					response->setContent(view->getContent());
				}

			} else {

				/**
				 * We don't need to create a response because there is one already created
				 */
				let response = possibleResponse;
			}
		}

		/**
		 * Calling beforeSendResponse
		 */
		if typeof eventsManager == "object" {
			eventsManager->fire("application:beforeSendResponse", this, response);
		}

		/**
		 * Headers and Cookies are automatically send
		 */
		response->sendHeaders();
		response->sendCookies();

		/**
		 * Return the response
		 */
		return response;
	}
}
