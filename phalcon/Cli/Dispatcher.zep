
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cli;

use Phalcon\Cli\Dispatcher\Exception;
use Phalcon\Dispatcher\AbstractDispatcher as CliDispatcher;
use Phalcon\Events\ManagerInterface;
use Phalcon\Filter\FilterInterface;

/**
 * Dispatching is the process of taking the command-line arguments, extracting
 * the module name, task name, action name, and optional parameters contained in
 * it, and then instantiating a task and calling an action on it.
 *
 * ```php
 * use Phalcon\Di;
 * use Phalcon\Cli\Dispatcher;
 *
 * $di = new Di();
 *
 * $dispatcher = new Dispatcher();
 *
 * $dispatcher->setDi($di);
 *
 * $dispatcher->setTaskName("posts");
 * $dispatcher->setActionName("index");
 * $dispatcher->setParams([]);
 *
 * $handle = $dispatcher->dispatch();
 * ```
 */
class Dispatcher extends CliDispatcher implements DispatcherInterface
{
    protected defaultHandler = "main";

    /**
     * @var string
     */
    protected defaultAction = "main";

    /**
     * @var string
     */
    protected handlerSuffix = "Task";

    /**
     * @var array
     */
    protected options = [];

    /**
     * Calls the action method.
     */
    public function callActionMethod(handler, string actionMethod, array! params = []) -> var
    {
        var params;

        // This is to make sure that the parameters are zero-indexed and
        // their order isn't overriden by any options when we merge the array.
        let params = array_values(params);
        let params = array_merge(params, this->options);

        return call_user_func_array(
            [handler, actionMethod],
            params
        );
    }

    /**
     * Returns the active task in the dispatcher
     */
    public function getActiveTask() -> <TaskInterface>
    {
        return this->activeHandler;
    }

    /**
     * Returns the latest dispatched controller
     */
    public function getLastTask() -> <TaskInterface>
    {
        return this->lastHandler;
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
            this->{"throwDispatchException"}(
                "A dependency injection container is required to access the 'filter' service",
                Exception::EXCEPTION_NO_DI
            );
        }

        let filter = <FilterInterface> container->getShared("filter");

        return filter->sanitize(optionValue, filters);
    }

    /**
     * Get dispatched options
     */
    public function getOptions() -> array
    {
        return this->options;
    }

    /**
     * Gets last dispatched task name
     */
    public function getTaskName() -> string
    {
        return this->handlerName;
    }

    /**
     * Gets the default task suffix
     */
    public function getTaskSuffix() -> string
    {
        return this->handlerSuffix;
    }

    /**
     * Check if an option exists
     */
    public function hasOption(var option) -> bool
    {
        return isset this->options[option];
    }

    /**
     * Sets the default task name
     */
    public function setDefaultTask(string taskName) -> void
    {
        let this->defaultHandler = taskName;
    }

    /**
     * Set the options to be dispatched
     */
    public function setOptions(array options) -> void
    {
        let this->options = options;
    }

    /**
     * Sets the task name to be dispatched
     */
    public function setTaskName(string taskName) -> void
    {
        let this->handlerName = taskName;
    }

    /**
     * Sets the default task suffix
     */
    public function setTaskSuffix(string taskSuffix) -> void
    {
        let this->handlerSuffix = taskSuffix;
    }

    /**
     * Handles a user exception
     */
    protected function handleException(<\Exception> exception)
    {
        var eventsManager;

        let eventsManager = <ManagerInterface> this->eventsManager;

        if typeof eventsManager == "object" {
            if eventsManager->fire("dispatch:beforeException", this, exception) === false {
                return false;
            }
        }
    }

    /**
     * Throws an internal exception
     */
    protected function throwDispatchException(string message, int exceptionCode = 0)
    {
        var exception;

        let exception = new Exception(message, exceptionCode);

        if this->handleException(exception) === false {
            return false;
        }

        throw exception;
    }
}
