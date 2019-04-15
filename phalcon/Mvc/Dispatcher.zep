
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc;

use Phalcon\Mvc\DispatcherInterface;
use Phalcon\Mvc\Dispatcher\Exception;
use Phalcon\Events\ManagerInterface;
use Phalcon\Http\ResponseInterface;
use Phalcon\Mvc\ControllerInterface;
use Phalcon\Dispatcher as BaseDispatcher;

/**
 * Phalcon\Mvc\Dispatcher
 *
 * Dispatching is the process of taking the request object, extracting the
 * module name, controller name, action name, and optional parameters contained
 * in it, and then instantiating a controller and calling an action of that
 * controller.
 *
 *<code>
 * $di = new \Phalcon\Di();
 *
 * $dispatcher = new \Phalcon\Mvc\Dispatcher();
 *
 * $dispatcher->setDI($di);
 *
 * $dispatcher->setControllerName("posts");
 * $dispatcher->setActionName("index");
 * $dispatcher->setParams([]);
 *
 * $controller = $dispatcher->dispatch();
 *</code>
 */
class Dispatcher extends BaseDispatcher implements DispatcherInterface
{

    protected defaultAction = "index";

    protected defaultHandler = "index";

    protected handlerSuffix = "Controller";

    /**
     * Forwards the execution flow to another controller/action.
     *
     * <code>
     * use Phalcon\Events\Event;
     * use Phalcon\Mvc\Dispatcher;
     * use App\Backend\Bootstrap as Backend;
     * use App\Frontend\Bootstrap as Frontend;
     *
     * // Registering modules
     * $modules = [
     *     "frontend" => [
     *         "className" => Frontend::class,
     *         "path"      => __DIR__ . "/app/Modules/Frontend/Bootstrap.php",
     *         "metadata"  => [
     *             "controllersNamespace" => "App\Frontend\Controllers",
     *         ],
     *     ],
     *     "backend" => [
     *         "className" => Backend::class,
     *         "path"      => __DIR__ . "/app/Modules/Backend/Bootstrap.php",
     *         "metadata"  => [
     *             "controllersNamespace" => "App\Backend\Controllers",
     *         ],
     *     ],
     * ];
     *
     * $application->registerModules($modules);
     *
     * // Setting beforeForward listener
     * $eventsManager  = $di->getShared("eventsManager");
     *
     * $eventsManager->attach(
     *     "dispatch:beforeForward",
     *     function(Event $event, Dispatcher $dispatcher, array $forward) use ($modules) {
     *         $metadata = $modules[$forward["module"]]["metadata"];
     *
     *         $dispatcher->setModuleName($forward["module"]);
     *         $dispatcher->setNamespaceName($metadata["controllersNamespace"]);
     *     }
     * );
     *
     * // Forward
     * $this->dispatcher->forward(
     *     [
     *         "module"     => "backend",
     *         "controller" => "posts",
     *         "action"     => "index",
     *     ]
     * );
     * </code>
     *
     * @param array forward
     */
    public function forward(var forward)
    {
        var eventsManager;

        let eventsManager = <ManagerInterface> this->eventsManager;
        if typeof eventsManager == "object" {
            eventsManager->fire("dispatch:beforeForward", this, forward);
        }

        parent::forward(forward);
    }

    /**
     * Returns the active controller in the dispatcher
     */
    public function getActiveController() -> <ControllerInterface>
    {
        return this->activeHandler;
    }

    /**
     * Possible controller class name that will be located to dispatch the
     * request
     */
    public function getControllerClass() -> string
    {
        return this->getHandlerClass();
    }

    /**
     * Gets last dispatched controller name
     */
    public function getControllerName() -> string
    {
        return this->handlerName;
    }

    /**
     * Returns the latest dispatched controller
     */
    public function getLastController() -> <ControllerInterface>
    {
        return this->lastHandler;
    }

    /**
     * Gets previous dispatched action name
     */
    public function getPreviousActionName() -> string
    {
        return this->previousActionName;
    }

    /**
     * Gets previous dispatched controller name
     */
    public function getPreviousControllerName() -> string
    {
        return this->previousHandlerName;
    }

    /**
     * Gets previous dispatched namespace name
     */
    public function getPreviousNamespaceName() -> string
    {
        return this->previousNamespaceName;
    }

    /**
     * Sets the controller name to be dispatched
     */
    public function setControllerName(string! controllerName)
    {
        let this->handlerName = controllerName;
    }

    /**
     * Sets the default controller suffix
     */
    public function setControllerSuffix(string! controllerSuffix)
    {
        let this->handlerSuffix = controllerSuffix;
    }

    /**
     * Sets the default controller name
     */
    public function setDefaultController(string! controllerName)
    {
        let this->defaultHandler = controllerName;
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
    protected function throwDispatchException(string! message, int exceptionCode = 0)
    {
        var container, response, exception;

        let container = this->container;
        if typeof container != "object" {
            throw new Exception(
                Exception::containerServiceNotFound("the 'response' service"),
                BaseDispatcher::EXCEPTION_NO_DI
            );
        }

        let response = <ResponseInterface> container->getShared("response");

        /**
         * Dispatcher exceptions automatically sends a 404 status
         */
        response->setStatusCode(404, "Not Found");

        /**
         * Create the real exception
         */
        let exception = new Exception(message, exceptionCode);

        if this->handleException(exception) === false {
            return false;
        }

        /**
         * Throw the exception if it wasn't handled
         */
        throw exception;
    }
}
