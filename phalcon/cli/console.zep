
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Cli;

/**
 * Phalcon\Cli\Console
 *
 * This component allows to create CLI applications using Phalcon
 */
class Console implements \Phalcon\Di\InjectionAwareInterface, \Phalcon\Events\EventsAwareInterface
{

	protected _dependencyInjector;

	protected _eventsManager;

	protected _modules;

	protected _moduleObject;

	protected _arguments;

	protected _options;

	/**
	 * Phalcon\Cli\Console constructor
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function __construct(<\Phalcon\DiInterface> dependencyInjector=null)
	{
		if typeof dependencyInjector == "object" {
			let this->_dependencyInjector = dependencyInjector;
		}

		let this->_arguments = [],
			this->_options = [];
	}

	/**
	 * Sets the DependencyInjector container
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<\Phalcon\DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <\Phalcon\DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets the events manager
	 *
	 * @param Phalcon\Events\ManagerInterface eventsManager
	 */
	public function setEventsManager(<\Phalcon\Events\ManagerInterface> eventsManager)
	{
		let this->_eventsManager = eventsManager;
	}

	/**
	 * Returns the internal event manager
	 *
	 * @return Phalcon\Events\ManagerInterface
	 */
	public function getEventsManager() -> <\Phalcon\Events\ManagerInterface>
	{
		return this->_eventsManager;
	}

	/**
	 * Register an array of modules present in the console
	 *
	 *<code>
	 *	$application->registerModules(array(
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
	 *
	 * @param array modules
	 */
	public function registerModules(modules)
	{
		if typeof modules != "array" {
			throw new \Phalcon\Cli\Console\Exception("Modules must be an Array");
		}
		let this->_modules = modules;
	}

	/**
	 * Merge modules with the existing ones
	 *
	 *<code>
	 *	application->addModules(array(
	 *		'admin' => array(
	 *			'className' => 'Multiple\Admin\Module',
	 *			'path' => '../apps/admin/Module.php'
	 *		)
	 *	));
	 *</code>
	 *
	 * @param array modules
	 */
	public function addModules(modules)
	{
		if typeof modules != "array" {
			throw new \Phalcon\Cli\Console\Exception("Modules must be an Array");
		}
		let this->_modules = array_merge(modules, this->_modules);
	}

	/**
	 * Return the modules registered in the console
	 *
	 * @return array
	 */
	public function getModules()
	{
		return this->_modules;
	}

	/**
	 * Handle the whole command-line tasks
	 *
	 * @param array arguments
	 * @return mixed
	 */
	public function handle(arguments=null)
	{
		var dependencyInjector, router, eventsManager,
			moduleName, modules, module, path, className,
			moduleObject, dispatcher, task;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new \Phalcon\Cli\Console\Exception("A dependency injection object is required to access internal services");
		}

		let eventsManager = <\Phalcon\Events\Manager> this->_eventsManager;

		let router = <\Phalcon\Cli\Router> dependencyInjector->getShared("router");

		if !arguments && this->_arguments {
			router->handle(this->_arguments);
		} else {
			router->handle(arguments);
		}

		let moduleName = router->getModuleName();
		if moduleName {

			if typeof eventsManager == "object" {
				if eventsManager->fire("console:beforeStartModule", this, moduleName) === false {
					return false;
				}
			}

			let modules = this->_modules;
			if !isset modules[moduleName] {
				throw new \Phalcon\Cli\Console\Exception("Module '" . moduleName . "' isn't registered in the console container");
			}

			let module = modules[moduleName];
			if typeof module != "array" {
				throw new \Phalcon\Cli\Console\Exception("Invalid module definition path");
			}

			if fetch path, module["path"] {
				if !file_exists(path) {
					throw new \Phalcon\Cli\Console\Exception("Module definition path '" . path . "' doesn't exist");
				}
				require path;
			}

			if !fetch className, module["className"] {
				let className = "Module";
			}

			let moduleObject = dependencyInjector->get(className);

			moduleObject->registerAutoloaders();
			moduleObject->registerServices(dependencyInjector);

			if typeof eventsManager == "object" {
				let this->_moduleObject = moduleObject;
				if eventsManager->fire("console:afterStartModule", this, moduleObject) === false {
					return false;
				}
			}

		}

		let dispatcher = <\Phalcon\Cli\Dispatcher> dependencyInjector->getShared("dispatcher");

		dispatcher->setTaskName(router->getTaskName());
		dispatcher->setActionName(router->getActionName());
		dispatcher->setParams(router->getParams());
		dispatcher->setOptions(this->_options);

		if typeof eventsManager == "object" {
			if eventsManager->fire("console:beforeHandleTask", this, dispatcher) === false {
				return false;
			}
		}

		let task = dispatcher->dispatch();

		if typeof eventsManager == "object" {
			eventsManager->fire("console:afterHandleTask", this, task);
		}

		return task;
	}

	public function setArgument(arguments=null, boolean! str=true, boolean! shift=true) -> <Console>
	{
		var arg, pos, args, opts, handleArgs;

		let args = [],
			opts = [],
			handleArgs = [];

		if typeof arguments != "array" {
			throw new \Phalcon\Cli\Console\Exception("Arguments must be an array");
		}

		if shift {
			array_shift(arguments);
		}

		for arg in arguments {
			if strncmp(arg, "--", 2) == 0 {
				let pos = strpos(arg, "=");
				if pos {
					let opts[trim(substr(arg, 2, pos - 2))] = trim(substr(arg, pos + 1));
				} else {
					let opts[trim(substr(arg, 2))] = true;
				}
			} else {
				if strncmp(arg, "-", 1) == 0 {
					let opts[substr(arg, 1)] = true;
				} else {
					let args[] = arg;
				}
			}
		}

		if str {
			let this->_arguments = implode(\Phalcon\Cli\Router\Route::getDelimiter(), args);
		} else {
			if count(args) {
				let handleArgs["task"] = array_shift(args);
			}
			if count(args) {
				let handleArgs["action"] = array_shift(args);
			}
			if count(args) {
				let handleArgs = array_merge(handleArgs, args);
			}
			let this->_arguments = handleArgs;
		}

		let this->_options = opts;

		return this;
	}

}
