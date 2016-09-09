
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon;

/**
 * Phalcon\DispatcherInterface
 *
 * Interface for Phalcon\Dispatcher
 */
interface DispatcherInterface
{

	/**
	 * Sets the default action suffix
	 */
	public function setActionSuffix(string actionSuffix) -> void;

	/**
	 * Gets the default action suffix
	 */
	public function getActionSuffix() -> string;

	/**
	 * Sets the default namespace
	 */
	public function setDefaultNamespace(string defaultNamespace) -> void;

	/**
	 * Sets the default action name
	 */
	public function setDefaultAction(string actionName) -> void;

	/**
	 * Sets the namespace which the controller belongs to
	 */
	public function setNamespaceName(string namespaceName) -> void;

	/**
	 * Sets the module name which the application belongs to
	 */
	public function setModuleName(string moduleName) -> void;

	/**
	 * Sets the action name to be dispatched
	 */
	public function setActionName(string actionName) -> void;

	/**
	 * Gets last dispatched action name
	 */
	public function getActionName() -> string;

	/**
	 * Sets action params to be dispatched
	 */
	public function setParams(array params) -> void;

	/**
	 * Gets action params
	 */
	public function getParams() -> array;

	/**
	 * Set a param by its name or numeric index
	 *
	 * @param  mixed param
	 * @param  mixed value
	 */
	public function setParam(param, value) -> void;

	/**
	 * Gets a param by its name or numeric index
	 *
	 * @param  mixed param
	 * @param  string|array filters
	 * @return mixed
	 */
	public function getParam(param, filters = null);

	/**
	 * Check if a param exists
	 *
	 * @param  mixed param
	 * @return boolean
	 */
	public function hasParam(param) -> boolean;

	/**
	 * Checks if the dispatch loop is finished or has more pendent controllers/tasks to dispatch
	 */
	public function isFinished() -> boolean;

	/**
	 * Returns value returned by the latest dispatched action
	 *
	 * @return mixed
	 */
	public function getReturnedValue();

	/**
	 * Dispatches a handle action taking into account the routing parameters
	 *
	 * @return object|false  Returns the dispatched handler class (the Controller for Mvc dispatching or a Task 
	 *                       for Cli dispatching) or <tt>false</tt> if an exception occurred and the operation was 
	 *                       stopped by returning <tt>false</tt> in the exception handler.
	 */
	public function dispatch();

	/**
	 * Forwards the execution flow to another controller/action
	 */
	public function forward(array forward) -> void;
}
