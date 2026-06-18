
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Dispatcher;

use Exception;
use Phalcon\Di\DiInterface;
use Phalcon\Di\AbstractInjectionAware;
use Phalcon\Dispatcher\Exception as PhalconException;
use Phalcon\Dispatcher\Exceptions\ForwardInInitializeForbidden;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Filter\FilterInterface;
use Phalcon\Mvc\Model\Binder;
use Phalcon\Mvc\Model\BinderInterface;
use Phalcon\Support\Collection;

/**
 * This is the base class for Phalcon\Mvc\Dispatcher and Phalcon\Cli\Dispatcher.
 * This class can't be instantiated directly, you can use it to create your own
 * dispatchers.
 *
 * ## Error protocol
 *
 * Subclasses (including third-party ones) MUST implement the two abstract
 * error hooks {@see throwDispatchException()} and {@see handleException()}.
 * The dispatch loop calls them on every error/exception path; a subclass that
 * omits them cannot be loaded.
 *
 * ## Hook channels
 *
 * A single lifecycle point can be intercepted through three independent
 * channels. For any given point they run in this order:
 *
 * 1. **Events-manager listener** — e.g. `dispatch:beforeExecuteRoute`. A
 *    listener returning `false` cancels; calling `forward()` re-enters the
 *    loop; throwing routes through {@see handleException()}.
 * 2. **Duck-typed handler method** — e.g. a `beforeExecuteRoute()` method on
 *    the controller/task itself (presence is cached per class). Same
 *    `false` / `forward()` cancellation semantics as the event.
 * 3. **`dispatch:beforeCallAction` observer** — fired by
 *    {@see callActionMethod()} with a `Phalcon\Support\Collection` carrying
 *    the mutable keys `handler`, `action` and `params`. Listeners may rewrite
 *    those keys to change *what* gets invoked; the substituted callable is
 *    re-validated before the call. `dispatch:afterCallAction` receives the
 *    same Collection plus a `result` key.
 */
abstract class AbstractDispatcher extends AbstractInjectionAware implements DispatcherInterface, EventsAwareInterface
{
    /**
     * @var object|null
     */
    protected activeHandler = null;

    /**
     * @var array
     */
    protected activeMethodMap = [];

    /**
     * @var string
     */
    protected actionName = "";

    /**
     * @var string
     */
    protected actionSuffix = "Action";

    /**
     * @var array
     */
    protected camelCaseMap = [];

    /**
     * @var string
     */
    protected defaultAction = "";

    /**
     * @var string
     */
    protected defaultNamespace = "";

    /**
     * @var string
     */
    protected defaultHandler = "";

    /**
     * @var array
     */
    protected handlerHashes = [];

    /**
     * @var array
     */
    protected handlerHookCache = [];

    /**
     * @var string
     */
    protected handlerName = "";

    /**
     * @var string
     */
    protected handlerSuffix = "";

    /**
     * @var ManagerInterface|null
     */
    protected eventsManager = null;

    /**
     * @var bool
     */
    protected finished = false;

    /**
     * @var bool
     */
    protected forwarded = false;

    /**
     * @var bool
     */
    protected isControllerInitialize = false;

    /**
     * @var mixed|null
     */
    protected lastHandler = null;

    /**
     * @var BinderInterface|null
     */
    protected modelBinder = null;

    /**
     * @var bool
     */
    protected modelBinding = false;

    /**
     * @var string
     */
    protected moduleName = "";

    /**
     * @var string
     */
    protected namespaceName = "";

    /**
     * @var array
     */
    protected params = [];

    /**
     * @var string|null
     */
    protected previousActionName = "";

    /**
     * @var string|null
     */
    protected previousHandlerName = "";

    /**
     * @var string|null
     */
    protected previousNamespaceName = "";

    /**
     * @var string|null
     */
    protected returnedValue = null;

    public function callActionMethod(handler, string actionMethod, array! params = [])
    {
        var result, observer, altHandler, altAction, altParams;

        let altHandler = handler;
        let altAction = actionMethod;
        let altParams = params;

        if this->eventsManager !== null && this->eventsManager instanceof ManagerInterface {
            let observer = new Collection([
                "handler": handler,
                "action": actionMethod,
                "params": params
            ]);

            this->eventsManager->fire(
                "dispatch:beforeCallAction",
                this,
                observer
            );

            let altHandler = observer->get("handler");
            let altAction = observer->get("action");
            let altParams = observer->get("params", [], "array");

            /**
             * The `dispatch:beforeCallAction` observer may replace the handler
             * and/or the action (see the hook-channel notes on this class). The
             * loop's own `is_callable()` check ran against the *original* pair,
             * so re-validate the (possibly mutated) callable here. A substituted,
             * non-existent target then fails through the dispatcher's own
             * EXCEPTION_ACTION_NOT_FOUND channel instead of producing a raw
             * call_user_func_array() fatal.
             */
            if unlikely !is_callable([altHandler, altAction]) {
                this->throwDispatchException(
                    "Action '" . this->actionName . "' was not found on handler '" . this->handlerName . "'",
                    PhalconException::EXCEPTION_ACTION_NOT_FOUND
                );

                return false;
            }
        }

        let result = call_user_func_array(
            [
                altHandler,
                altAction
            ],
            array_values(altParams)
        );

        if this->eventsManager !== null && this->eventsManager instanceof ManagerInterface {
            let observer["result"] = result;

            this->eventsManager->fire(
                "dispatch:afterCallAction",
                this,
                observer
            );
        }

        return result;
    }

    /**
     * Process the results of the router by calling into the appropriate
     * controller action(s) including any routing data or injected parameters.
     *
     * @return mixed Returns the dispatched handler class (the Controller for Mvc dispatching or a Task
     *               for CLI dispatching) or <tt>false</tt> if an exception occurred and the operation was
     *               stopped by returning <tt>false</tt> in the exception handler.
     *
     * @throws \Exception if any uncaught or unhandled exception occurs during the dispatcher process.
     */
    public function dispatch() -> var | bool
    {
        bool hasService, hasEventsManager;
        int numberDispatches;
        var value, handler, container, namespaceName, handlerName, actionName,
            eventsManager, handlerClass, status, actionMethod,
            modelBinder, bindCacheKey, isNewHandler, handlerHash, hookCache, e;

        let container = <DiInterface> this->container;

        if container === null {
            this->throwDispatchException(
                "A dependency injection container is required to access related dispatching services",
                PhalconException::EXCEPTION_NO_DI
            );

            return false;
        }

        let eventsManager = <ManagerInterface> this->eventsManager;
        let hasEventsManager = typeof eventsManager == "object";
        let this->finished = true;

        if hasEventsManager {
            try {
                // Calling beforeDispatchLoop event
                // Note: Allow user to forward in the beforeDispatchLoop.
                if eventsManager->fire("dispatch:beforeDispatchLoop", this) === false && this->finished !== false {
                    return false;
                }
            } catch Exception, e {
                // Exception occurred in beforeDispatchLoop.

                /**
                 * The user can optionally forward now in the
                 * `dispatch:beforeException` event or return <tt>false</tt> to
                 * handle the exception and prevent it from bubbling. In the
                 * event the user does forward but does or does not return
                 * false, we assume the forward takes precedence. The returning
                 * false intuitively makes more sense when inside the dispatch
                 * loop and technically we are not here. Therefore, returning
                 * false only impacts whether non-forwarded exceptions are
                 * silently handled or bubbled up the stack. Note that this
                 * behavior is slightly different than other subsequent events
                 * handled inside the dispatch loop.
                 */

                let status = this->handleException(e);

                if this->finished !== false {
                    // No forwarding
                    if status === false {
                        return false;
                    }

                    // Otherwise, bubble Exception
                    throw e;
                }

                // Otherwise, user forwarded, continue
            }
        }

        let value = null,
            handler = null,
            numberDispatches = 0,
            this->finished = false;

        while !this->finished {
            let numberDispatches++;

            // Throw an exception after 256 consecutive forwards
            if unlikely numberDispatches == 256 {
                this->throwDispatchException(
                    "Dispatcher has detected a cyclic routing causing stability problems",
                    PhalconException::EXCEPTION_CYCLIC_ROUTING
                );

                break;
            }

            let this->finished = true;

            this->resolveEmptyProperties();

            if hasEventsManager {
                try {
                    // Calling "dispatch:beforeDispatch" event
                    if eventsManager->fire("dispatch:beforeDispatch", this) === false || this->finished === false {
                        continue;
                    }
                } catch Exception, e {
                    if this->handleException(e) === false || this->finished === false {
                        continue;
                    }

                    throw e;
                }
            }

            let handlerClass = this->getHandlerClass();

            /**
             * Handlers are retrieved as shared instances from the Service
             * Container
             */
            let hasService = (bool) container->has(handlerClass);
            if !hasService {
                /**
                 * DI does not have a service with that name, try to load it
                 * using an autoloader
                 */
                let hasService = class_exists(handlerClass);
            }

            // If the service can be loaded we throw an exception
            if !hasService {
                let status = this->throwDispatchException(
                    handlerClass . " handler class cannot be loaded",
                    PhalconException::EXCEPTION_HANDLER_NOT_FOUND
                );

                if status === false && this->finished === false {
                    continue;
                }

                break;
            }

            let handler = container->getShared(handlerClass);

            // Handlers must be only objects
            if unlikely typeof handler !== "object" {
                let status = this->throwDispatchException(
                    "Invalid handler returned from the services container",
                    PhalconException::EXCEPTION_INVALID_HANDLER
                );

                if status === false && this->finished === false {
                    continue;
                }

                break;
            }

            // Check if the handler is new (hasn't been initialized).
            let handlerHash = spl_object_hash(handler);

            let isNewHandler = !(isset this->handlerHashes[handlerHash]);

            if isNewHandler {
                let this->handlerHashes[handlerHash] = true;
            }

            let this->activeHandler = handler;

            if !isset this->handlerHookCache[handlerClass] {
                let this->handlerHookCache[handlerClass] = [
                    method_exists(handler, "beforeExecuteRoute"),
                    method_exists(handler, "initialize"),
                    method_exists(handler, "afterBinding"),
                    method_exists(handler, "afterExecuteRoute")
                ];
            }

            let hookCache = this->handlerHookCache[handlerClass];

            let namespaceName = this->namespaceName;
            let handlerName = this->handlerName;
            let actionName = this->actionName;

            /**
             * Check if the params is an array
             */
            if unlikely typeof this->params !== "array" {
                /**
                 * An invalid parameter variable was passed throw an exception
                 */
                let status = this->throwDispatchException(
                    "Action parameters must be an Array",
                    PhalconException::EXCEPTION_INVALID_PARAMS
                );

                if status === false && this->finished === false {
                    continue;
                }

                break;
            }

            // Check if the method exists in the handler
            let actionMethod = this->getActiveMethod();

            if unlikely !is_callable([handler, actionMethod]) {
                if hasEventsManager {
                    if eventsManager->fire("dispatch:beforeNotFoundAction", this) === false {
                        continue;
                    }

                    if this->finished === false {
                        continue;
                    }
                }

                /**
                 * Try to throw an exception when an action isn't defined on the
                 * object
                 */
                let status = this->throwDispatchException(
                    "Action '" . actionName . "' was not found on handler '" . handlerName . "'",
                    PhalconException::EXCEPTION_ACTION_NOT_FOUND
                );

                if status === false && this->finished === false {
                    continue;
                }

                break;
            }

            /**
             * In order to ensure that the `initialize()` gets called we'll
             * destroy the current handlerClass from the DI container in the
             * event that an error occurs and we continue out of this block.
             * This is necessary because there is a disjoin between retrieval of
             * the instance and the execution of the `initialize()` event. From
             * a coding perspective, it would have made more sense to probably
             * put the `initialize()` prior to the beforeExecuteRoute which
             * would have solved this. However, for posterity, and to remain
             * consistency, we'll ensure the default and documented behavior
             * works correctly.
             */
            if hasEventsManager {
                try {
                    // Calling "dispatch:beforeExecuteRoute" event
                    if eventsManager->fire("dispatch:beforeExecuteRoute", this) === false || this->finished === false {
                        container->remove(handlerClass);
                        continue;
                    }
                } catch Exception, e {
                    if this->handleException(e) === false || this->finished === false {
                        container->remove(handlerClass);

                        continue;
                    }

                    throw e;
                }
            }

            if hookCache[0] {
                try {
                    // Calling "beforeExecuteRoute" as direct method
                    if handler->beforeExecuteRoute(this) === false || this->finished === false {
                        container->remove(handlerClass);

                        continue;
                    }
                } catch Exception, e {
                    if this->handleException(e) === false || this->finished === false {
                        container->remove(handlerClass);

                        continue;
                    }

                    throw e;
                }
            }

            /**
             * Call the "initialize" method just once per request
             *
             * Note: The `dispatch:afterInitialize` event is called regardless
             *       of the presence of an `initialize()` method. The naming is
             *       poor; however, the intent is for a more global "constructor
             *       is ready to go" or similarly "__onConstruct()" methodology.
             *
             * Note (historical): the `initialize()` call and the
             * `dispatch:afterInitialize` event ideally would run *before* the
             * `beforeExecuteRoute` event/method blocks. This was a bug in the
             * original design that could not be changed due to widespread
             * implementation. The reordering was once slated for 4.0 but never
             * shipped; it remains deferred to a future major version, where the
             * BC break is acceptable and the container-eviction workaround below
             * can be removed along with it.
             *
             * @see https://github.com/phalcon/cphalcon/pull/13112
             */
            if isNewHandler {
                if hookCache[1] {
                    try {
                        let this->isControllerInitialize = true;

                        handler->initialize();
                    } catch Exception, e {
                        let this->isControllerInitialize = false;

                        /**
                         * If this is a dispatch exception (e.g. From
                         * forwarding) ensure we don't handle this twice. In
                         * order to ensure this does not happen all other
                         * exceptions thrown outside this method in this class
                         * should not call "throwDispatchException" but instead
                         * throw a normal Exception.
                         */
                        if this->handleException(e) === false || this->finished === false {
                            continue;
                        }

                        throw e;
                    }
                }

                let this->isControllerInitialize = false;

                /**
                 * Refresh in case initialize() attached an events manager to
                 * the dispatcher when none existed at dispatch() entry.
                 */
                if !hasEventsManager && this->eventsManager !== null && this->eventsManager instanceof ManagerInterface {
                    let eventsManager    = <ManagerInterface> this->eventsManager;
                    let hasEventsManager = true;
                }

                /**
                 * Calling "dispatch:afterInitialize" event
                 */
                if eventsManager {
                    try {
                        if eventsManager->fire("dispatch:afterInitialize", this) === false || this->finished === false {
                            continue;
                        }
                    } catch Exception, e {
                        if this->handleException(e) === false || this->finished === false {
                            continue;
                        }

                        throw e;
                    }
                }
            }

            if this->modelBinding {
                let modelBinder = this->modelBinder;
                let bindCacheKey = "_PHMB_" . handlerClass . "_" . actionMethod;

                let this->params = modelBinder->bindToHandler(
                    handler,
                    this->params,
                    bindCacheKey,
                    actionMethod
                );
            }

            /**
             * Calling afterBinding
             *
             * Note: Unlike every other lifecycle hook, the `afterBinding` event
             * and method blocks deliberately have no try/catch. Exceptions
             * raised here are intended to bypass `handleException()` (and the
             * `dispatch:beforeException` channel) and bubble straight up: at
             * this point binding has already mutated the parameters and the
             * action is about to run, so swallowing/forwarding from a binding
             * listener is intentionally not supported. The only honored signals
             * are returning `false` (cancel) and `forward()` (`finished` flips
             * to `false`). This asymmetry is by design, not an oversight.
             */
            if hasEventsManager {
                if eventsManager->fire("dispatch:afterBinding", this) === false {
                    continue;
                }

                /**
                 * Check if the user made a forward in the listener
                 */
                if this->finished === false {
                    continue;
                }
            }

            /**
             * Calling afterBinding as callback and event
             */
            if hookCache[2] {
                if handler->afterBinding(this) === false {
                    continue;
                }

                /**
                 * Check if the user made a forward in the listener
                 */
                if this->finished === false {
                    continue;
                }
            }

            /**
             * Save the current handler
             */
            let this->lastHandler = handler;

            try {
                /**
                 * We update the latest value produced by the latest handler
                 */
                let this->returnedValue = this->callActionMethod(
                    handler,
                    actionMethod,
                    this->params
                );

                if this->finished === false {
                    continue;
                }
            } catch Exception, e {
                if this->handleException(e) === false || this->finished === false {
                    continue;
                }

                throw e;
            }

            /**
             * Calling "dispatch:afterExecuteRoute" event
             */
            if hasEventsManager {
                try {
                    if eventsManager->fire("dispatch:afterExecuteRoute", this, value) === false || this->finished === false {
                        continue;
                    }
                } catch Exception, e {
                    if this->handleException(e) === false || this->finished === false {
                        continue;
                    }

                    throw e;
                }
            }

            /**
             * Calling "afterExecuteRoute" as direct method
             */
            if hookCache[3] {
                try {
                    if handler->afterExecuteRoute(this, value) === false || this->finished === false {
                        continue;
                    }
                } catch Exception, e {
                    if this->handleException(e) === false || this->finished === false {
                        continue;
                    }

                    throw e;
                }
            }

            // Calling "dispatch:afterDispatch" event
            if hasEventsManager {
                try {
                    eventsManager->fire("dispatch:afterDispatch", this, value);
                } catch Exception, e {
                    /**
                     * Still check for finished here as we want to prioritize
                     * `forwarding()` calls
                     */
                    if this->handleException(e) === false || this->finished === false {
                        continue;
                    }

                    throw e;
                }
            }
        }

        if hasEventsManager {
            try {
                // Calling "dispatch:afterDispatchLoop" event
                // Note: We don't worry about forwarding in after dispatch loop.
                eventsManager->fire("dispatch:afterDispatchLoop", this);
            } catch Exception, e {
                // Exception occurred in afterDispatchLoop.
                if this->handleException(e) === false {
                    return false;
                }

                // Otherwise, bubble Exception
                throw e;
            }
        }

        return handler;
    }

    /**
     * Forwards the execution flow to another controller/action.
     *
     * ```php
     * $this->dispatcher->forward(
     *     [
     *         "controller" => "posts",
     *         "action"     => "index",
     *     ]
     * );
     * ```
     *
     * @throws PhalconException
     */
    public function forward(array forward) -> void
    {
        var namespaceName, controllerName, params, actionName, taskName;

        if unlikely this->isControllerInitialize === true {
            /**
             * Note: Important that we do not throw a "throwDispatchException"
             * call here. This is important because it would allow the
             * application to break out of the defined logic inside the
             * dispatcher which handles all dispatch exceptions.
             */
            throw new ForwardInInitializeForbidden();
        }

        /**
         * Save current values as previous to ensure calls to getPrevious
         * methods don't return null.
         */
        let this->previousNamespaceName = this->namespaceName,
            this->previousHandlerName = this->handlerName,
            this->previousActionName = this->actionName;

        // Check if we need to forward to another namespace
        if fetch namespaceName, forward["namespace"] {
            let this->namespaceName = namespaceName;
        }

        // Check if we need to forward to another controller.
        if fetch controllerName, forward["controller"] {
            let this->handlerName = controllerName;
        } elseif fetch taskName, forward["task"] {
            let this->handlerName = taskName;
        }

        // Check if we need to forward to another action
        if fetch actionName, forward["action"] {
            let this->actionName = actionName;
        }

        // Check if we need to forward changing the current parameters
        if fetch params, forward["params"] {
            let this->params = params;
        }

        let this->finished = false,
            this->forwarded = true;
    }

    /**
     * Gets the latest dispatched action name
     */
    public function getActionName() -> string
    {
        return this->actionName;
    }

    /**
     * Gets the default action suffix
     */
    public function getActionSuffix() -> string
    {
        return this->actionSuffix;
    }

    /**
     * Returns the current method to be/executed in the dispatcher
     */
    public function getActiveMethod() -> string
    {
        var activeMethodName;

        if !fetch activeMethodName, this->activeMethodMap[this->actionName] {
            let activeMethodName = lcfirst(
                this->toCamelCase(
                    this->actionName
                )
            );

            let this->activeMethodMap[this->actionName] = activeMethodName;
        }

        return activeMethodName . this->actionSuffix;
    }

    /**
     * Returns bound models from binder instance
     *
     * ```php
     * class UserController extends Controller
     * {
     *     public function showAction(User $user)
     *     {
     *         // return array with $user
     *         $boundModels = $this->dispatcher->getBoundModels();
     *     }
     * }
     * ```
     */
    public function getBoundModels() -> array
    {
        if this->modelBinder === null {
            return [];
        }

        return this->modelBinder->getBoundModels();
    }

    /**
     * Returns the default namespace
     */
    public function getDefaultNamespace() -> string
    {
        return this->defaultNamespace;
    }

    /**
     * Returns the internal event manager
     */
    public function getEventsManager() -> <ManagerInterface> | null
    {
        return this->eventsManager;
    }

    /**
     * Gets the default handler suffix
     */
    public function getHandlerSuffix() -> string
    {
        return this->handlerSuffix;
    }

    /**
     * Gets model binder
     */
    public function getModelBinder() -> <BinderInterface> | null
    {
        return this->modelBinder;
    }

    /**
     * Gets the module where the controller class is
     */
    public function getModuleName() -> string | null
    {
        return this->moduleName;
    }

    /**
     * Gets a namespace to be prepended to the current handler name
     */
    public function getNamespaceName() -> string
    {
        return this->namespaceName;
    }

    /**
     * Gets a param by its name or numeric index
     *
     * @param  mixed param
     * @param  string|array filters
     * @param  mixed defaultValue
     * @return mixed
     *
     * @deprecated Use getParameter() instead
     *
     * Note: The interface declares `getParam(param, filters = null)` without the
     * `defaultValue` argument, so code typed against `DispatcherInterface`
     * cannot use the default-value feature. This signature drift is intentional
     * for now; the interface and implementation will be aligned in the next
     * major version.
     */
    public function getParam(var param, filters = null, defaultValue = null) -> var
    {
        return this->getParameter(param, filters, defaultValue);
    }

    /**
     * Gets a param by its name or numeric index
     *
     * @param  mixed param
     * @param  string|array filters
     * @param  mixed defaultValue
     * @return mixed
     */
    public function getParameter(var param, var filters = null, var defaultValue = null) -> var
    {
        var params, filter, paramValue;

        let params = this->params;

        if !fetch paramValue, params[param] {
            return defaultValue;
        }

        if filters === null {
            return paramValue;
        }

        if this->container === null {
            this->throwDispatchException(
                "A dependency injection container is required to access the 'filter' service",
                PhalconException::EXCEPTION_NO_DI
            );
        }

        let filter = <FilterInterface> this->container->getShared("filter");

        return filter->sanitize(paramValue, filters);
    }

    /**
     * Gets action params
     *
     * @deprecated Use getParameters() instead
     */
    public function getParams() -> array
    {
        return this->getParameters();
    }

    /**
     * Gets action params
     */
    public function getParameters() -> array
    {
        return this->params;
    }

    /**
     * Gets previous dispatched action name
     */
    public function getPreviousActionName() -> string
    {
        return this->previousActionName;
    }

    /**
     * Gets previous dispatched handler name
     */
    public function getPreviousHandlerName() -> string
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
     * Check if a param exists
     *
     * @deprecated Use hasParameter() instead
     */
    public function hasParam(var param) -> bool
    {
        return this->hasParameter(param);
    }

    /**
     * Check if a param exists
     */
    public function hasParameter(var param) -> bool
    {
        return isset this->params[param];
    }

    /**
     * Checks if the dispatch loop is finished or has more pendent
     * controllers/tasks to dispatch
     */
    public function isFinished() -> bool
    {
        return this->finished;
    }

    /**
     * Sets the action name to be dispatched
     */
    public function setActionName(string actionName) -> void
    {
        let this->actionName = actionName;
    }


    /**
     * Sets the default action name
     */
    public function setDefaultAction(string actionName) -> void
    {
        let this->defaultAction = actionName;
    }

    /**
     * Sets the default namespace
     */
    public function setDefaultNamespace(string defaultNamespace) -> void
    {
        let this->defaultNamespace = defaultNamespace;
    }

    /**
     * Possible class name that will be located to dispatch the request
     */
    public function getHandlerClass() -> string
    {
        var handlerSuffix, handlerName, namespaceName, camelizedClass,
            handlerClass;

        this->resolveEmptyProperties();

        let handlerSuffix = this->handlerSuffix,
            handlerName = this->handlerName,
            namespaceName = this->namespaceName;

        // We don't camelize the classes if they are in namespaces
        if !memstr(handlerName, "\\") {
            let camelizedClass = this->toCamelCase(handlerName);
        } else {
            let camelizedClass = handlerName;
        }

        // Create the complete controller class name prepending the namespace
        if namespaceName {
            if !ends_with(namespaceName, "\\") {
                let namespaceName .= "\\";
            }

            let handlerClass = namespaceName . camelizedClass . handlerSuffix;
        } else {
            let handlerClass = camelizedClass . handlerSuffix;
        }

        return handlerClass;
    }

    /**
     * Set a param by its name or numeric index
     *
     * @deprecated Use setParameter() instead
     */
    public function setParam(var param, var value) -> void
    {
        this->setParameter(param, value);
    }

    /**
     * Set a param by its name or numeric index
     */
    public function setParameter(var param, var value) -> void
    {
        let this->params[param] = value;
    }

    /**
     * Sets action params to be dispatched
     *
     * @deprecated Use setParameters() instead
     */
    public function setParams(array params) -> void
    {
        this->setParameters(params);
    }

    /**
     * Sets action params to be dispatched
     */
    public function setParameters(array params) -> void
    {
        let this->params = params;
    }

    /**
     * Sets the latest returned value by an action manually
     */
    public function setReturnedValue(var value) -> void
    {
        let this->returnedValue = value;
    }

    /**
     * Sets the default action suffix
     */
    public function setActionSuffix(string actionSuffix) -> void
    {
        let this->actionSuffix = actionSuffix;
    }

    /**
     * Sets the events manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }

    /**
     * Sets the default suffix for the handler
     */
    public function setHandlerSuffix(string handlerSuffix) -> void
    {
        let this->handlerSuffix = handlerSuffix;
    }

    /**
     * Enable model binding during dispatch
     *
     * ```php
     * $di->set(
     *     'dispatcher',
     *     function() {
     *         $dispatcher = new Dispatcher();
     *
     *         $dispatcher->setModelBinder(
     *             new Binder(),
     *             'cache'
     *         );
     *
     *         return $dispatcher;
     *     }
     * );
     * ```
     */
    public function setModelBinder(<BinderInterface> modelBinder, var cache = null) -> <DispatcherInterface>
    {
        var container;

        if typeof cache === "string" {
            let container = this->container;

            let cache = container->get(cache);
        }

        if cache != null {
            modelBinder->setCache(cache);
        }

        let this->modelBinding = true;
        let this->modelBinder = modelBinder;

        return this;
    }

    /**
     * Sets the module where the controller is (only informative)
     */
    public function setModuleName(string moduleName = null) -> void
    {
        let this->moduleName = moduleName;
    }

    /**
     * Sets the namespace where the controller class is
     */
    public function setNamespaceName(string namespaceName) -> void
    {
        let this->namespaceName = namespaceName;
    }

    /**
     * Returns value returned by the latest dispatched action
     */
    public function getReturnedValue() -> var
    {
        return this->returnedValue;
    }

    /**
     * Check if the current executed action was forwarded by another one
     */
    public function wasForwarded() -> bool
    {
        return this->forwarded;
    }

    /**
     * Handles a user exception triggered inside the dispatch loop.
     *
     * Subclasses implement the namespace-specific behavior (typically firing
     * the `dispatch:beforeException` event so listeners may forward or swallow
     * the exception).
     *
     * @param \Exception exception
     *
     * @return mixed Return `false` to signal that the exception was handled
     *               (swallowed) and the current loop iteration should stop.
     *               Any other return value (including null) lets the caller
     *               bubble the exception, unless a forward was requested
     *               (`finished === false`).
     */
    abstract protected function handleException(<\Exception> exception);

    /**
     * Set empty properties to their defaults (where defaults are available)
     */
    protected function resolveEmptyProperties() -> void
    {
        // If the current namespace is null we use the default namespace
        if !this->namespaceName {
            let this->namespaceName = this->defaultNamespace;
        }

        // If the handler is null we use the default handler
        if !this->handlerName {
            let this->handlerName = this->defaultHandler;
        }

        // If the action is null we use the default action
        if !this->actionName {
            let this->actionName = this->defaultAction;
        }
    }

    /**
     * Throws an internal dispatch exception.
     *
     * Subclasses build the namespace-specific exception and route it through
     * {@see handleException()} before throwing it when it was not handled.
     *
     * @param string message
     * @param int    exceptionCode
     *
     * @return mixed Returns `false` when {@see handleException()} swallowed the
     *               exception; otherwise the method throws and does not return.
     */
    abstract protected function throwDispatchException(string message, int exceptionCode = 0);

    protected function toCamelCase(string input) -> string
    {
        var camelCaseInput;

        if !fetch camelCaseInput, this->camelCaseMap[input] {
            let camelCaseInput = join(
                "",
                array_map(
                    "ucfirst",
                    preg_split("/[_-]+/", input)
                )
            );

            let this->camelCaseMap[input] = camelCaseInput;
        }

        return camelCaseInput;
    }
}
