
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

namespace Phalcon\CLI;

/**
 * Phalcon\CLI\Dispatcher
 *
 * Dispatching is the process of taking the command-line arguments, extracting the module name,
 * task name, action name, and optional parameters contained in it, and then
 * instantiating a task and calling an action on it.
 *
 *<code>
 *
 *	$di = new Phalcon\Di();
 *
 *	$dispatcher = new Phalcon\CLI\Dispatcher();
 *
 *  $dispatcher->setDI(di);
 *
 *	$dispatcher->setTaskName('posts');
 *	$dispatcher->setActionName('index');
 *	$dispatcher->setParams(array());
 *
 *	$handle = dispatcher->dispatch();
 *
 *</code>
 */
class Dispatcher extends Phalcon\Dispatcher
{

	protected _handlerSuffix = "Task";

	protected _defaultHandler = "main";

	protected _defaultAction = "main";

	/**
	 * Sets the default task suffix
	 *
	 * @param string taskSuffix
	 */
	public function setTaskSuffix(taskSuffix)
	{
		let this->_handlerSuffix = taskSuffix;
	}

	/**
	 * Sets the default task name
     *
	 * @param string taskName
	 */
	public function setDefaultTask(taskName)
	{
		let this->_defaultHandler = taskName;
	}

	/**
	 * Sets the task name to be dispatched
	 *
	 * @param string taskName
	 */
	public function setTaskName(taskName)
	{
		let this->_handlerName = taskName;
	}

	/**
	 * Gets last dispatched task name
	 *
	 * @return string
	 */
	public function getTaskName()
	{
		return this->_handlerName;
	}

	/**
	 * Throws an internal exception
	 *
	 * @param string message
	 * @param int exceptionCode
	 */
	protected function _throwDispatchException(message, exceptionCode=0)
	{
		var exception, eventsManager;

		let exception = new Phalcon\CLI\Dispatcher\Exception(message, exceptionCode);

		let eventsManager = <Phalcon\Events\Manager> this->_eventsManager;
		if typeof eventsManager != "object" {
			if eventsManager->fire("dispatch:beforeException", this, exception) === false {
				return false;
			}
		}

		throw exception;
	}

	/**
	 * Returns the lastest dispatched controller
	 *
	 * @return Phalcon\CLI\Task
	 */
	public function getLastTask()
	{
		return this->_lastHandler;
	}

	/**
	 * Returns the active task in the dispatcher
	 *
	 * @return Phalcon\CLI\Task
	 */
	public function getActiveTask()
	{
		return this->_activeHandler;
	}

}