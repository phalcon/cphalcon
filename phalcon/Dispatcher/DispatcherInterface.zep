
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Dispatcher;

/**
 * Interface for Phalcon\Dispatcher\AbstractDispatcher
 */
interface DispatcherInterface
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
     */
    public function getParam(var param, filters = null) -> var;

    /**
     * Gets action params
     */
    public function getParams() -> array;

    /**
     * Returns value returned by the latest dispatched action
     */
    public function getReturnedValue() -> var;

    /**
     * Check if a param exists
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
    public function setModuleName(string moduleName) -> void;

    /**
     * Sets the namespace which the controller belongs to
     */
    public function setNamespaceName(string namespaceName) -> void;

    /**
     * Set a param by its name or numeric index
     *
     * @param  mixed value
     */
    public function setParam(var param, value) -> void;

    /**
     * Sets action params to be dispatched
     */
    public function setParams(array params) -> void;
}
