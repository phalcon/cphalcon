
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
	public function setActionSuffix(string actionSuffix);

	/**
	 * Sets the default namespace
	 */
	public function setDefaultNamespace(string defaultNamespace);

	/**
	 * Sets the default action name
	 */
	public function setDefaultAction(string actionName);

	/**
	 * Sets the namespace which the controller belongs to
	 */
	public function setNamespaceName(string namespaceName);

	/**
	 * Sets the module name which the application belongs to
	 */
	public function setModuleName(string moduleName);

	/**
	 * Sets the action name to be dispatched
	 */
	public function setActionName(string actionName);

	/**
	 * Gets last dispatched action name
	 */
	public function getActionName() -> string;

	/**
	 * Sets action params to be dispatched
	 *
	 * @param array params
	 */
	public function setParams(params);

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
	public function setParam(param, value);

	/**
	 * Gets a param by its name or numeric index
	 *
	 * @param  mixed param
	 * @param  string|array filters
	 * @return mixed
	 */
	public function getParam(param, filters = null);

	/**
	 * Checks if the dispatch loop is finished or has more pendent controllers/tasks to dispatch
	 */
	public function isFinished() -> boolean;

	/**
	 * Returns value returned by the lastest dispatched action
	 *
	 * @return mixed
	 */
	public function getReturnedValue();

	/**
	 * Dispatches a handle action taking into account the routing parameters
	 *
	 * @return object
	 */
	public function dispatch();

	/**
	 * Forwards the execution flow to another controller/action
	 *
	 * @param array forward
	 */
	public function forward(forward);
}
