
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
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
 |          Rack Lin <racklin@gmail.com>                                  |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Cli;

use Phalcon\FilterInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Cli\Dispatcher\Exception;
use Phalcon\Dispatcher as CliDispatcher;

/**
 * Phalcon\Cli\Dispatcher
 *
 * Dispatching is the process of taking the command-line arguments, extracting the module name,
 * task name, action name, and optional parameters contained in it, and then
 * instantiating a task and calling an action on it.
 *
 * <code>
 * use Phalcon\Di;
 * use Phalcon\Cli\Dispatcher;
 *
 * $di = new Di();
 * $dispatcher = new Dispatcher();
 * $dispatcher->setDi($di);
 *
 * $dispatcher->setTaskName("posts");
 * $dispatcher->setActionName("index");
 * $dispatcher->setParams([]);
 *
 * $handle = $dispatcher->dispatch();
 * </code>
 */
class Dispatcher extends CliDispatcher implements DispatcherInterface
{

	protected _handlerSuffix = "Task";

	protected _defaultHandler = "main";

	protected _defaultAction = "main";

	protected _options = [];

	/**
	 * Sets the default task suffix
	 */
	public function setTaskSuffix(string taskSuffix)
	{
		let this->_handlerSuffix = taskSuffix;
	}

	/**
	 * Sets the default task name
	 */
	public function setDefaultTask(string taskName)
	{
		let this->_defaultHandler = taskName;
	}

	/**
	 * Sets the task name to be dispatched
	 */
	public function setTaskName(string taskName)
	{
		let this->_handlerName = taskName;
	}

	/**
	 * Gets last dispatched task name
	 */
	public function getTaskName() -> string
	{
		return this->_handlerName;
	}

	/**
	 * Throws an internal exception
	 */
	protected function _throwDispatchException(string message, int exceptionCode = 0)
	{
		var exception;

		let exception = new Exception(message, exceptionCode);

		if this->_handleException(exception) === false {
			return false;
		}

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
	 * Returns the latest dispatched controller
	 */
	public function getLastTask() -> <TaskInterface>
	{
		return this->_lastHandler;
	}

	/**
	 * Returns the active task in the dispatcher
	 */
	public function getActiveTask() -> <TaskInterface>
	{
		return this->_activeHandler;
	}

	/**
	 * Set the options to be dispatched
	 */
	public function setOptions(array options)
	{
		let this->_options = options;
	}

	/**
	 * Get dispatched options
	 */
	public function getOptions() -> array
	{
		return this->_options;
	}

	/**
	 * Gets an option by its name or numeric index
	 *
	 * @param  mixed $option
	 * @param  string|array $filters
	 * @param  mixed $defaultValue
	 */
	public function getOption(option, filters = null, defaultValue = null) -> var
	{
		var options, filter, optionValue, dependencyInjector;

		let options = this->_options;
		if !fetch optionValue, options[option] {
			return defaultValue;
		}

		if filters === null {
			return optionValue;
		}

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			this->{"_throwDispatchException"}(
				"A dependency injection object is required to access the 'filter' service",
				CliDispatcher::EXCEPTION_NO_DI
			);
		}
		let filter = <FilterInterface> dependencyInjector->getShared("filter");

		return filter->sanitize(optionValue, filters);
	}

	/**
	 * Check if an option exists
	 */
	public function hasOption(var option) -> boolean
	{
		return isset this->_options[option];
	}

	/**
	 * Calls the action method.
	 */
	public function callActionMethod(handler, string actionMethod, array! params = []) -> var
	{
		var options;

		let options = this->_options;
		
		return call_user_func_array([handler, actionMethod], [params, options]);
	}
}
