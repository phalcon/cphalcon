
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon;

use Phalcon\Application\Exception;
use Phalcon\DiInterface;
use Phalcon\Di\Injectable;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;

/**
 * Phalcon\Application
 *
 * Base class for Phalcon\Cli\Console and Phalcon\Mvc\Application.
 */
abstract class Application extends Injectable implements EventsAwareInterface
{

	protected _eventsManager;

	protected _dependencyInjector;

	/**
	 * @var string
	 */
	protected _defaultModule;

	/**
	 * @var array
	 */
	protected _modules = [];

	/**
	 * Phalcon\Application
	 */
	public function __construct(<DiInterface> dependencyInjector = null)
	{
		if typeof dependencyInjector == "object" {
			let this->_dependencyInjector = dependencyInjector;
		}
	}

	/**
	 * Sets the events manager
	 */
	public function setEventsManager(<ManagerInterface> eventsManager) -> <Application>
	{
		let this->_eventsManager = eventsManager;

		return this;
	}

	/**
	 * Returns the internal event manager
	 */
	public function getEventsManager() -> <ManagerInterface>
	{
		return this->_eventsManager;
	}

	/**
	 * Register an array of modules present in the application
	 *
	 * <code>
	 * $this->registerModules(
	 *     [
	 *         "frontend" => [
	 *             "className" => "Multiple\\Frontend\\Module",
	 *             "path"      => "../apps/frontend/Module.php",
	 *         ],
	 *         "backend" => [
	 *             "className" => "Multiple\\Backend\\Module",
	 *             "path"      => "../apps/backend/Module.php",
	 *         ],
	 *     ]
	 * );
	 * </code>
	 */
	public function registerModules(array modules, boolean merge = false) -> <Application>
	{
		if merge {
			let this->_modules = array_merge(this->_modules, modules);
		} else {
			let this->_modules = modules;
		}

		return this;
	}

	/**
	 * Return the modules registered in the application
	 */
	public function getModules() -> array
	{
		return this->_modules;
	}

	/**
	 * Gets the module definition registered in the application via module name
	 */
	public function getModule(string! name) -> array | object
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
	 * Handles a request
	 */
	abstract public function handle();
}
