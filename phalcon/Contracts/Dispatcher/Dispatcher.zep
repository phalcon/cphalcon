
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Dispatcher;

/**
 * Canonical contract for Phalcon\Dispatcher\AbstractDispatcher.
 *
 * Note: The deprecated `getParam()`/`getParams()`/`hasParam()`/`setParam()`/
 * `setParams()` spellings are still declared for backwards compatibility and
 * are scheduled to be removed in the next major version in favor of their
 * `*Parameter` counterparts.
 */
interface Dispatcher
{
    /**
     * Dispatches a handle action taking into account the routing parameters
     *
     * @return mixed
     */
    public function dispatch()  -> var | bool;

    /**
     * Forwards the execution flow to another controller/action
     */
    public function forward(array forward) -> void;

    /**
     * Gets last dispatched action name
     */
    public function getActionName() -> string;

    /**
     * Gets the default action suffix
     */
    public function getActionSuffix() -> string;

    /**
     * Gets the default handler suffix
     */
    public function getHandlerSuffix() -> string;

    /**
     * Gets a param by its name or numeric index
     *
     * @param  string|array filters
     *
     * @deprecated Use getParameter() instead
     *
     * Note: This signature omits the `defaultValue` argument the implementation
     * accepts; the two will be aligned in the next major version.
     */
    public function getParam(var param, filters = null) -> var;

    /**
     * Gets a param by its name or numeric index
     *
     * @param  string|array filters
     */
    public function getParameter(var param, filters = null) -> var;

    /**
     * Gets action params
     *
     * @deprecated Use getParameters() instead
     */
    public function getParams() -> array;

    /**
     * Gets action params
     */
    public function getParameters() -> array;

    /**
     * Returns value returned by the latest dispatched action
     */
    public function getReturnedValue() -> var;

    /**
     * Check if a param exists
     *
     * @deprecated Use hasParameter() instead
     */
    public function hasParam(var param) -> bool;

    /**
     * Checks if the dispatch loop is finished or has more pendent
     * controllers/tasks to dispatch
     */
    public function isFinished() -> bool;

    /**
     * Sets the action name to be dispatched
     */
    public function setActionName(string actionName) -> void;

    /**
     * Sets the default action suffix
     */
    public function setActionSuffix(string actionSuffix) -> void;

    /**
     * Sets the default action name
     */
    public function setDefaultAction(string actionName) -> void;

    /**
     * Sets the default namespace
     */
    public function setDefaultNamespace(string defaultNamespace) -> void;

    /**
     * Sets the default suffix for the handler
     */
    public function setHandlerSuffix(string handlerSuffix) -> void;

    /**
     * Sets the module name which the application belongs to
     */
    public function setModuleName(string moduleName = null) -> void;

    /**
     * Sets the namespace which the controller belongs to
     */
    public function setNamespaceName(string namespaceName) -> void;

    /**
     * Set a param by its name or numeric index
     *
     * @param  mixed value
     *
     * @deprecated Use setParameter() instead
     */
    public function setParam(var param, value) -> void;

    /**
     * Sets action params to be dispatched
     *
     * @deprecated Use setParameters() instead
     */
    public function setParams(array params) -> void;
}
