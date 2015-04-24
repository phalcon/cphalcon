
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

use Phalcon\Cli\Task;
use Phalcon\Events\ManagerInterface;
use Phalcon\Cli\Dispatcher\Exception;

/**
 * Phalcon\Cli\Dispatcher
 *
 * Dispatching is the process of taking the command-line arguments, extracting the module name,
 * task name, action name, and optional parameters contained in it, and then
 * instantiating a task and calling an action on it.
 *
 *<code>
 *
 *	$di = new \Phalcon\Di();
 *
 *	$dispatcher = new \Phalcon\Cli\Dispatcher();
 *
 *  $dispatcher->setDi(di);
 *
 *	$dispatcher->setTaskName('posts');
 *	$dispatcher->setActionName('index');
 *	$dispatcher->setParams(array());
 *
 *	$handle = dispatcher->dispatch();
 *
 *</code>
 */
class Dispatcher extends \Phalcon\Dispatcher
{

	protected _handlerSuffix = "Task";

	protected _defaultHandler = "main";

	protected _defaultAction = "main";

	protected _options;

	/**
	 * Phalcon\Cli\Dispatcher constructor
	 */
	public function __construct()
	{
		let this->_options = [];

		parent::__construct();
	}

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
	 * Returns the lastest dispatched controller
	 */
	public function getLastTask() -> <Task>
	{
		return this->_lastHandler;
	}

	/**
	 * Returns the active task in the dispatcher
	 */
	public function getActiveTask() -> <Task>
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
}
