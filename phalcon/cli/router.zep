
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

namespace Phalcon\Cli;

/**
 * Phalcon\Cli\Router
 *
 * <p>Phalcon\Cli\Router is the standard framework router. Routing is the
 * process of taking a command-line arguments and
 * decomposing it into parameters to determine which module, task, and
 * action of that task should receive the request</p>
 *
 *<code>
 *	$router = new Phalcon\Cli\Router();
 *	$router->handle(array(
 *		'module' => 'main',
 *		'task' => 'videos',
 *		'action' => 'process'
 *	));
 *	echo $router->getTaskName();
 *</code>
 *
 */
class Router implements Phalcon\Di\InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _module;

	protected _task;

	protected _action;

	protected _params;

	protected _defaultModule;

	protected _defaultTask;

	protected _defaultAction;

	protected _defaultParams;

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
	public function getDI() -> <Phalcon\DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets the name of the default module
	 *
	 * @param string moduleName
	 */
	public function setDefaultModule(string moduleName)
	{
		let this->_defaultModule = moduleName;
	}

	/**
	 * Sets the default controller name
	 *
	 * @param string taskName
	 */
	public function setDefaultTask(string taskName)
	{
		let this->_defaultTask = taskName;
	}

	/**
	 * Sets the default action name
	 *
	 * @param string actionName
	 */
	public function setDefaultAction(string actionName)
	{
		let this->_defaultAction = actionName;
	}

	/**
	 * Handles routing information received from command-line arguments
	 *
	 * @param array arguments
	 */
	public function handle(arguments=null)
	{
		var moduleName, taskName, actionName;

		if typeof arguments != "array" {
			throw new Phalcon\Cli\Router\Exception("Arguments must be an Array");
		}

		let moduleName = null,
			taskName = null,
			actionName = null;

		/**
		 * Check for a module
		 */
		if fetch moduleName, arguments["module"] {
			unset arguments["module"];
		}

		/**
		 * Check for a task
		 */
		if fetch taskName, arguments["task"] {
			unset arguments["task"];
		}

		/**
		 * Check for an action
		 */
		if fetch actionName, arguments["action"] {
			unset arguments["action"];
		}

		let this->_module = moduleName,
			this->_task = taskName,
			this->_action = actionName,
			this->_params = arguments;
	}

	/**
	 * Returns proccesed module name
	 *
	 * @return string
	 */
	public function getModuleName() -> string
	{
		return this->_module;
	}

	/**
	 * Returns proccesed task name
	 *
	 * @return string
	 */
	public function getTaskName() -> string
	{
		return this->_task;
	}

	/**
	 * Returns proccesed action name
	 *
	 * @return string
	 */
	public function getActionName() -> string
	{
		return this->_action;
	}

	/**
	 * Returns proccesed extra params
	 *
	 * @return array
	 */
	public function getParams()
	{
		return this->_params;
	}

}
