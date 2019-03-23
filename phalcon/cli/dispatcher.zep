
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cli;

use Phalcon\FilterInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Cli\Dispatcher\Exception;
use Phalcon\Dispatcher as CliDispatcher;
use Phalcon\Service\LocatorInterface;

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

    protected handlerSuffix = "Task";

    protected defaultHandler = "main";

    protected defaultAction = "main";

    protected options = [];

    /**
     * Sets the default task suffix
     */
    public function setTaskSuffix(string taskSuffix)
    {
        let this->handlerSuffix = taskSuffix;
    }

    /**
     * Sets the default task name
     */
    public function setDefaultTask(string taskName)
    {
        let this->defaultHandler = taskName;
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
     * Gets the default task suffix
     */
    public function getTaskSuffix() -> string
    {
        return this->handlerSuffix;
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
        let this->options = options;
    }

    /**
     * Get dispatched options
     */
    public function getOptions() -> array
    {
        return this->options;
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
        var options, filter, optionValue, container;

        let options = this->options;
        if !fetch optionValue, options[option] {
            return defaultValue;
        }

        if filters === null {
            return optionValue;
        }

        let container = this->container;
        if typeof container != "object" {
            this->{"_throwDispatchException"}(
                "A dependency injection object is required to access the 'filter' service",
                CliDispatcher::EXCEPTION_NO_DI
            );
        }
        let filter = <LocatorInterface> container->getShared("filter");
//        let filter = <FilterInterface> container->getShared("filter");

        return filter->sanitize(optionValue, filters);
    }

    /**
     * Check if an option exists
     */
    public function hasOption(var option) -> bool
    {
        return isset this->options[option];
    }

    /**
     * Calls the action method.
     */
    public function callActionMethod(handler, string actionMethod, array! params = []) -> var
    {
        var params;

        // This is to make sure that the paramters are zero-indexed and
        // their order isn't overriden by any options when we merge the array.
        let params = array_values(params);
        let params = array_merge(params, this->options);

        return call_user_func_array([handler, actionMethod], params);
    }
}
