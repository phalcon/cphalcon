
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
 |          Rack Lin <racklin@gmail.com>                                  |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Cli;

use Phalcon\DiInterface;
use Phalcon\Cli\Router\Route;
use Phalcon\Events\ManagerInterface;
use Phalcon\Cli\Console\Exception;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;

/**
 * Phalcon\Cli\Console
 *
 * This component allows to create CLI applications using Phalcon
 */
class Console implements InjectionAwareInterface, EventsAwareInterface
{

	protected _dependencyInjector;

	protected _eventsManager;

	protected _modules;

	protected _moduleObject;

	protected _arguments;

	protected _options;

	/**
	 * Phalcon\Cli\Console constructor
	 */
	public function __construct(<DiInterface> dependencyInjector = null)
	{
		if typeof dependencyInjector == "object" {
			let this->_dependencyInjector = dependencyInjector;
		}

		let this->_arguments = [],
			this->_options = [];
	}

	/**
	 * Sets the DependencyInjector container
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
	 */
	public function registerModules(array! modules)
	{
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
	 */
	public function addModules(array! modules)
	{
		let this->_modules = array_merge(modules, this->_modules);
	}

	/**
	 * Return the modules registered in the console
	 */
	public function getModules() -> array
	{
		return this->_modules;
	}

	/**
	 * Handle the whole command-line tasks
	 */
	public function handle(array arguments = null)
	{
		var dependencyInjector, router, eventsManager,
			moduleName, modules, module, path, className,
			moduleObject, dispatcher, task;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injection object is required to access internal services");
		}

		let eventsManager = <ManagerInterface> this->_eventsManager;

		let router = <Router> dependencyInjector->getShared("router");

		if !count(arguments) && this->_arguments {
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
				throw new Exception("Module '" . moduleName . "' isn't registered in the console container");
			}

			let module = modules[moduleName];
			if typeof module != "array" {
				throw new Exception("Invalid module definition path");
			}

			if fetch path, module["path"] {
				if !file_exists(path) {
					throw new Exception("Module definition path '" . path . "' doesn't exist");
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

	/**
	 * Set an specific argument
	 */
	public function setArgument(array! arguments = null, boolean! str = true, boolean! shift = true) -> <Console>
	{
		var arg, pos, args, opts, handleArgs;

		let args = [],
			opts = [],
			handleArgs = [];

		if shift && count(arguments) {
			array_shift(arguments);
		}

		for arg in arguments {
			if typeof arg == "string" {
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
			} else {
				let args[] = arg;
			}
		}

		if str {
			let this->_arguments = implode(Route::getDelimiter(), args);
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
