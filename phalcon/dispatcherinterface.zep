
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	 * Gets the default action suffix
	 */
	public function getActionSuffix() -> string;

	/**
	 * Gets the default handler suffix
	 */
	public function getHandlerSuffix() -> string;

	/**
	 * Sets the default namespace
	 */
	public function setDefaultNamespace(string defaultNamespace);

	/**
	 * Sets the default suffix for the handler
	 */
	public function setHandlerSuffix(string handlerSuffix);

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
	 * @param  mixed value
	 */
	public function setParam(var param, value);

	/**
	 * Gets a param by its name or numeric index
	 *
	 * @param  string|array filters
	 * @return mixed
	 */
	public function getParam(var param, filters = null);

	/**
	 * Check if a param exists
	 */
	public function hasParam(var param) -> bool;

	/**
	 * Checks if the dispatch loop is finished or has more pendent controllers/tasks to dispatch
	 */
	public function isFinished() -> bool;

	/**
	 * Returns value returned by the latest dispatched action
	 */
	public function getReturnedValue() -> var;

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
