
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc;

use ArrayAccess;
use Closure;
use Phalcon\Di\DiInterface;
use Phalcon\Di\Injectable;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Micro\Exception;
use Phalcon\Di\ServiceInterface;
use Phalcon\Mvc\Micro\Collection;
use Phalcon\Mvc\Micro\LazyLoader;
use Phalcon\Http\ResponseInterface;
use Phalcon\Mvc\Model\BinderInterface;
use Phalcon\Mvc\Router\RouteInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Mvc\Micro\MiddlewareInterface;
use Phalcon\Mvc\Micro\CollectionInterface;
use Throwable;

/**
 * Phalcon\Mvc\Micro
 *
 * With Phalcon you can create "Micro-Framework like" applications. By doing
 * this, you only need to write a minimal amount of code to create a PHP
 * application. Micro applications are suitable to small applications, APIs and
 * prototypes in a practical way.
 *
 *```php
 * $app = new \Phalcon\Mvc\Micro();
 *
 * $app->get(
 *     "/say/welcome/{name}",
 *     function ($name) {
 *         echo "<h1>Welcome $name!</h1>";
 *     }
 * );
 *
 * $app->handle("/say/welcome/Phalcon");
 *```
 */
class Micro extends Injectable implements ArrayAccess, EventsAwareInterface
{
    /**
     * @var callable|null
     */
    protected activeHandler = null;

    /**
     * @var array
     */
    protected afterBindingHandlers = [];

    /**
     * @var array
     */
    protected afterHandlers = [];

    /**
     * @var array
     */
    protected beforeHandlers = [];

    /**
     * @var DiInterface|null
     */
    protected container = null;

    /**
     * @var callable|null
     */
    protected errorHandler = null;

    /**
     * @var ManagerInterface|null
     */
    protected eventsManager = null;

    /**
     * @var array
     */
    protected finishHandlers = [];

    /**
     * @var array
     */
    protected handlers = [];

    /**
     * @var BinderInterface|null
     */
    protected modelBinder = null;

    /**
     * @var callable|null
     */
    protected notFoundHandler = null;

    /**
     * @var callable|null
     */
    protected responseHandler = null;

    /**
     * @var mixed|null
     */
    protected returnedValue = null;

    /**
     * @var RouterInterface|null
     */
    protected router = null;

    /**
     * @var bool
     */
    protected stopped = false;

    /**
     * Phalcon\Mvc\Micro constructor
     */
    public function __construct(<DiInterface> container = null)
    {
        if container !== null {
            this->setDi(container);
        }
    }

    /**
     * Appends an 'after' middleware to be called after execute the route
     *
     * @param callable handler
     */
    public function after(handler) -> <Micro>
    {
        let this->afterHandlers[] = handler;

        return this;
    }

    /**
     * Appends a afterBinding middleware to be called after model binding
     *
     * @param callable handler
     */
    public function afterBinding(handler) -> <Micro>
    {
        let this->afterBindingHandlers[] = handler;

        return this;
    }

    /**
     * Appends a before middleware to be called before execute the route
     *
     * @param callable handler
     */
    public function before(handler) -> <Micro>
    {
        let this->beforeHandlers[] = handler;

        return this;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is DELETE
     *
     * @param callable handler
     */
    public function delete(string! routePattern, handler) -> <RouteInterface>
    {
        var router, route;

        /**
         * We create a router even if there is no one in the DI
         */
        let router = this->getRouter();

        /**
         * Routes are added to the router restricting to DELETE
         */
        let route = router->addDelete(routePattern);

        /**
         * Using the id produced by the router we store the handler
         */
        let this->handlers[route->getRouteId()] = handler;

        /**
         * The route is returned, the developer can add more things on it
         */
        return route;
    }

    /**
     * Sets a handler that will be called when an exception is thrown handling
     * the route
     *
     * @param callable handler
     */
    public function error(var handler) -> <Micro>
    {
        let this->errorHandler = handler;

        return this;
    }

    /**
     * Appends a 'finish' middleware to be called when the request is finished
     *
     * @param callable handler
     */
    public function finish(handler) -> <Micro>
    {
        let this->finishHandlers[] = handler;

        return this;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is GET
     *
     * @param callable handler
     */
    public function get(string! routePattern, handler) -> <RouteInterface>
    {
        var router, route;

        /**
         * We create a router even if there is no one in the DI
         */
        let router = this->getRouter();

        /**
         * Routes are added to the router restricting to GET
         */
        let route = router->addGet(routePattern);

        /**
         * Using the id produced by the router we store the handler
         */
        let this->handlers[route->getRouteId()] = handler;

        /**
         * The route is returned, the developer can add more things on it
         */
        return route;
    }

    /**
     * Return the handler that will be called for the matched route
     *
     * @return callable
     */
    public function getActiveHandler()
    {
        return this->activeHandler;
    }

    /**
     * Returns bound models from binder instance
     */
    public function getBoundModels() -> array
    {
        var modelBinder;

        let modelBinder = this->modelBinder;

        if modelBinder == null {
            return [];
        }

        return modelBinder->getBoundModels();
    }

    /**
     * Returns the internal event manager
     */
    public function getEventsManager() -> <ManagerInterface> | null
    {
        return this->eventsManager;
    }

    /**
     * Sets the events manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }

    /**
     * Returns the internal handlers attached to the application
     */
    public function getHandlers() -> array
    {
        return this->handlers;
    }

    /**
     * Gets model binder
     */
    public function getModelBinder() -> <BinderInterface>|null
    {
        return this->modelBinder;
    }

    /**
     * Returns the value returned by the executed handler
     *
     * @return mixed
     */
    public function getReturnedValue()
    {
        return this->returnedValue;
    }

    /**
     * Returns the internal router used by the application
     */
    public function getRouter() -> <RouterInterface>
    {
        var router;

        let router = this->router;

        if typeof router != "object" {
            let router = this->getSharedService("router");

            /**
             * Clear the set routes if any
             */
            router->clear();

            /**
             * Automatically remove extra slashes
             */
            router->removeExtraSlashes(true);

            /**
             * Update the internal router
             */
            let this->router = router;
        }

        return router;
    }

    /**
     * Obtains a service from the DI
     *
     * @return object
     */
    public function getService(string! serviceName)
    {
        var container;

        let container = this->container;

        if typeof container != "object" {
            let container = new FactoryDefault();

            let this->container = container;
        }

        return container->get(serviceName);
    }

    /**
     * Obtains a shared service from the DI
     *
     * @return mixed
     */
    public function getSharedService(string! serviceName)
    {
        var container;

        let container = this->container;

        if typeof container != "object" {
            let container = new FactoryDefault();

            let this->container = container;
        }

        return container->getShared(serviceName);
    }

    /**
     * Handle the whole request
     *
     * @param string uri
     * @return mixed
     */
    public function handle(string! uri)
    {
        var container, eventsManager, status = null, router, matchedRoute,
            handler, beforeHandlers, params, returnedValue, e, errorHandler,
            afterHandlers, notFoundHandler, finishHandlers, finish, before,
            after, response, modelBinder, routeName, realHandler = null,
            methodName, lazyReturned, afterBindingHandlers, afterBinding;
        string bindCacheKey;

        let container = this->container;

        if unlikely typeof container != "object" {
            throw new Exception(
                "A dependency injection container is required to access micro services"
            );
        }

        try {
            let returnedValue = null;

            /**
             * Calling beforeHandle routing
             */
            let eventsManager = this->eventsManager;

            if typeof eventsManager == "object" {
                if eventsManager->fire("micro:beforeHandleRoute", this) === false {
                    return false;
                }
            }

            /**
             * Handling routing information
             */
            let router = <RouterInterface> container->getShared("router");

            /**
             * Handle the URI as normal
             */
            router->handle(uri);

            /**
             * Check if one route was matched
             */
            let matchedRoute = router->getMatchedRoute();

            if typeof matchedRoute == "object" {
                if unlikely !fetch handler, this->handlers[matchedRoute->getRouteId()] {
                    throw new Exception(
                        "Matched route doesn't have an associated handler"
                    );
                }

                /**
                 * Updating active handler
                 */
                let this->activeHandler = handler;

                /**
                 * Calling beforeExecuteRoute event
                 */
                if typeof eventsManager == "object" {
                    if eventsManager->fire("micro:beforeExecuteRoute", this) === false {
                        return false;
                    }

                    let handler = this->activeHandler;
                }

                let beforeHandlers = this->beforeHandlers;

                let this->stopped = false;

                /**
                 * Calls the before handlers
                 */
                for before in beforeHandlers {
                    if typeof before == "object" && before instanceof MiddlewareInterface {
                        /**
                         * Call the middleware
                         */
                        let status = before->call(this);
                    } else {
                        if unlikely !is_callable(before) {
                            throw new Exception(
                                "'before' handler is not callable"
                            );
                        }

                        /**
                         * Call the before handler
                         */
                        let status = call_user_func(before);
                    }

                    /**
                     * Return the status if the middleware was stopped
                     */
                    if this->stopped {
                        return status;
                    }
                }

                let params = router->getParams();

                let modelBinder = this->modelBinder;

                /**
                 * Bound the app to the handler
                 */
                if typeof handler == "object" && handler instanceof Closure {
                    let handler = Closure::bind(handler, this);

                    if modelBinder != null {
                        let routeName = matchedRoute->getName();

                        if routeName != null {
                            let bindCacheKey = "_PHMB_" . routeName;
                        } else {
                            let bindCacheKey = "_PHMB_" . matchedRoute->getPattern();
                        }

                        let params = modelBinder->bindToHandler(
                            handler,
                            params,
                            bindCacheKey
                        );
                    }
                }

                /**
                 * Calling the Handler in the PHP userland
                 */
                if typeof handler == "array" {
                    let realHandler = handler[0];

                    if realHandler instanceof Controller && modelBinder != null {
                        let methodName = handler[1];
                        let bindCacheKey = "_PHMB_" . get_class(realHandler) . "_" . methodName;

                        let params = modelBinder->bindToHandler(
                            realHandler,
                            params,
                            bindCacheKey,
                            methodName
                        );
                    }
                }

                /**
                 * Instead of double call_user_func_array when lazy loading we
                 * will just call method
                 */
                if realHandler != null && realHandler instanceof LazyLoader {
                    let methodName = handler[1];

                    let lazyReturned = realHandler->callMethod(
                        methodName,
                        params,
                        modelBinder
                    );
                } else {
                    let lazyReturned = call_user_func_array(handler, params);
                }

                /**
                 * There is seg fault if we try set directly value of method
                 * to returnedValue
                 */
                let returnedValue = lazyReturned;

                /**
                 * Calling afterBinding event
                 */
                if typeof eventsManager == "object" {
                    if eventsManager->fire("micro:afterBinding", this) === false {
                        return false;
                    }
                }

                let afterBindingHandlers = this->afterBindingHandlers;

                let this->stopped = false;

                /**
                 * Calls the after binding handlers
                 */
                for afterBinding in afterBindingHandlers {
                    if typeof afterBinding == "object" && afterBinding instanceof MiddlewareInterface {
                        /**
                         * Call the middleware
                         */
                        let status = afterBinding->call(this);
                    } else {
                        if unlikely !is_callable(afterBinding) {
                            throw new Exception(
                                "'afterBinding' handler is not callable"
                            );
                        }

                        /**
                         * Call the afterBinding handler
                         */
                        let status = call_user_func(afterBinding);
                    }

                    /**
                     * Return the status if the middleware was stopped
                     */
                    if this->stopped {
                        return status;
                    }
                }

                /**
                 * Update the returned value
                 */
                let this->returnedValue = returnedValue;

                /**
                 * Calling afterExecuteRoute event
                 */
                if typeof eventsManager == "object" {
                    eventsManager->fire("micro:afterExecuteRoute", this);
                }

                let afterHandlers = this->afterHandlers;

                let this->stopped = false;

                /**
                 * Calls the after handlers
                 */
                for after in afterHandlers {
                    if typeof after == "object" && after instanceof MiddlewareInterface {
                        /**
                         * Call the middleware
                         */
                        let status = after->call(this);
                    } else {
                        if unlikely !is_callable(after) {
                            throw new Exception(
                                "One of the 'after' handlers is not callable"
                            );
                        }

                        let status = call_user_func(after);
                    }

                    /**
                     * break the execution if the middleware was stopped
                     */
                    if this->stopped {
                        break;
                    }
                }
            } else {
                /**
                 * Calling beforeNotFound event
                 */
                let eventsManager = this->eventsManager;

                if typeof eventsManager == "object" {
                    if eventsManager->fire("micro:beforeNotFound", this) === false {
                        return false;
                    }
                }

                /**
                 * Check if a notfoundhandler is defined and it's callable
                 */
                let notFoundHandler = this->notFoundHandler;

                if unlikely !is_callable(notFoundHandler) {
                    throw new Exception(
                        "Not-Found handler is not callable or is not defined"
                    );
                }

                /**
                 * Call the Not-Found handler
                 */
                let returnedValue = call_user_func(notFoundHandler);
            }

            /**
             * Calling afterHandleRoute event
             */
            if typeof eventsManager == "object" {
                eventsManager->fire("micro:afterHandleRoute", this, returnedValue);
            }

            let finishHandlers = this->finishHandlers;

            let this->stopped = false;

            /**
             * Calls the finish handlers
             */
            for finish in finishHandlers {
                /**
                 * Try to execute middleware as plugins
                 */
                if typeof finish == "object" && finish instanceof MiddlewareInterface {
                    /**
                     * Call the middleware
                     */
                    let status = finish->call(this);
                } else {
                    if unlikely !is_callable(finish) {
                        throw new Exception(
                            "One of the 'finish' handlers is not callable"
                        );
                    }

                    /**
                     * Call the 'finish' middleware
                     */
                    let status = call_user_func_array(
                        finish,
                        [this]
                    );
                }

                /**
                 * break the execution if the middleware was stopped
                 */
                if this->stopped {
                    break;
                }
            }
        } catch Throwable, e {
            /**
             * Calling beforeNotFound event
             */
            let eventsManager = this->eventsManager;

            if typeof eventsManager == "object" {
                let returnedValue = eventsManager->fire(
                    "micro:beforeException",
                    this,
                    e
                );
            }

            /**
             * Check if an errorhandler is defined and it's callable
             */
            let errorHandler = this->errorHandler;

            if errorHandler {
                if unlikely !is_callable(errorHandler) {
                    throw new Exception("Error handler is not callable");
                }

                /**
                 * Call the Error handler
                 */
                let returnedValue = call_user_func_array(
                    errorHandler,
                    [e]
                );

                if typeof returnedValue == "object" {
                    if !(returnedValue instanceof ResponseInterface) {
                        throw e;
                    }
                } else {
                    if returnedValue !== false {
                        throw e;
                    }
                }
            } else {
                if returnedValue !== false {
                    throw e;
                }
            }
        }

        /**
         * Check if a response handler is defined, else use default response
         * handler
         */
        if this->responseHandler {
            if unlikely !is_callable(this->responseHandler) {
                throw new Exception(
                    "Response handler is not callable or is not defined"
                );
            }

            let returnedValue = call_user_func(this->responseHandler);
        } else {
            /**
             * Check if the returned value is a string and take it as response
             * body
             */
            if typeof returnedValue == "string" {
                let response = <ResponseInterface> container->getShared("response");

                if !response->isSent() {
                    response->setContent(returnedValue);
                    response->send();
                }
            }

            /**
             * Check if the returned object is already a response
             */
            if typeof returnedValue == "object" && returnedValue instanceof ResponseInterface {
                if !returnedValue->isSent() {
                    returnedValue->send();
                }
            }
        }

        return returnedValue;
    }

    /**
     * Checks if a service is registered in the DI
     */
    public function hasService(string! serviceName) -> bool
    {
        var container;

        let container = this->container;

        if typeof container != "object" {
            let container = new FactoryDefault();

            let this->container = container;
        }

        return container->has(serviceName);
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is HEAD
     *
     * @param callable handler
     */
    public function head(string! routePattern, handler) -> <RouteInterface>
    {
        var router, route;

        /**
         * We create a router even if there is no one in the DI
         */
        let router = this->getRouter();

        /**
         * Routes are added to the router restricting to HEAD
         */
        let route = router->addHead(routePattern);

        /**
         * Using the id produced by the router we store the handler
         */
        let this->handlers[route->getRouteId()] = handler;

        /**
         * The route is returned, the developer can add more things on it
         */
        return route;
    }

    /**
     * Maps a route to a handler without any HTTP method constraint
     *
     * @param callable handler
     */
    public function map(string! routePattern, handler) -> <RouteInterface>
    {
        var router, route;

        /**
         * We create a router even if there is no one in the DI
         */
        let router = this->getRouter();

        /**
         * Routes are added to the router
         */
        let route = router->add(routePattern);

        /**
         * Using the id produced by the router we store the handler
         */
        let this->handlers[route->getRouteId()] = handler;

        /**
         * The route is returned, the developer can add more things on it
         */
        return route;
    }

    /**
     * Mounts a collection of handlers
     */
    public function mount(<CollectionInterface> collection) -> <Micro>
    {
        var mainHandler, handlers, lazyHandler, prefix, methods, pattern,
            subHandler, realHandler, prefixedPattern, route, handler, name;

        /**
         * Get the main handler
         */
        let mainHandler = collection->getHandler();

        if unlikely empty mainHandler {
            throw new Exception("Collection requires a main handler");
        }

        let handlers = collection->getHandlers();

        if unlikely !count(handlers) {
            throw new Exception("There are no handlers to mount");
        }

        /**
         * Check if handler is lazy
         */
        if collection->isLazy() {
            let lazyHandler = new LazyLoader(mainHandler);
        } else {
            let lazyHandler = mainHandler;
        }

        /**
         * Get the main prefix for the collection
         */
        let prefix = collection->getPrefix();

        for handler in handlers {
            if unlikely typeof handler != "array" {
                throw new Exception(
                    "One of the registered handlers is invalid"
                );
            }

            let methods    = handler[0];
            let pattern    = handler[1];
            let subHandler = handler[2];
            let name       = handler[3];

            /**
             * Create a real handler
             */
            let realHandler = [lazyHandler, subHandler];

            if !empty prefix {
                if pattern == "/" {
                    let prefixedPattern = prefix;
                } else {
                    let prefixedPattern = prefix . pattern;
                }
            } else {
                let prefixedPattern = pattern;
            }

            /**
             * Map the route manually
             */
            let route = this->map(prefixedPattern, realHandler);

            if (typeof methods == "string" && methods != "") || typeof methods == "array" {
                route->via(methods);
            }

            if typeof name == "string" {
                route->setName(name);
            }
        }

        return this;
    }

    /**
     * Sets a handler that will be called when the router doesn't match any of
     * the defined routes
     *
     * @param callable handler
     */
    public function notFound(var handler) -> <Micro>
    {
        let this->notFoundHandler = handler;

        return this;
    }

    /**
     * Check if a service is registered in the internal services container using
     * the array syntax
     */
    public function offsetExists(var alias) -> bool
    {
        return this->hasService(alias);
    }

    /**
     * Allows to obtain a shared service in the internal services container
     * using the array syntax
     *
     *```php
     * var_dump(
     *     $app["request"]
     * );
     *```
     */
    public function offsetGet(var alias) -> var
    {
        return this->getService(alias);
    }

    /**
     * Allows to register a shared service in the internal services container
     * using the array syntax
     *
     *```php
     *    $app["request"] = new \Phalcon\Http\Request();
     *```
     */
    public function offsetSet(var alias, var definition) -> void
    {
        this->setService(alias, definition);
    }

    /**
     * Removes a service from the internal services container using the array
     * syntax
     */
    public function offsetUnset(var alias) -> void
    {
        var container;

        let container = this->container;

        if typeof container != "object" {
            let container = new FactoryDefault();

            let this->container = container;
        }

        container->remove(alias);
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is OPTIONS
     *
     * @param callable handler
     */
    public function options(string! routePattern, handler) -> <RouteInterface>
    {
        var router, route;

        /**
         * We create a router even if there is no one in the DI
         */
        let router = this->getRouter();

        /**
         * Routes are added to the router restricting to OPTIONS
         */
        let route = router->addOptions(routePattern);

        /**
         * Using the id produced by the router we store the handler
         */
        let this->handlers[route->getRouteId()] = handler;

        /**
         * The route is returned, the developer can add more things on it
         */
        return route;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is PATCH
     *
     * @param callable $handler
     */
    public function patch(string! routePattern, handler) -> <RouteInterface>
    {
        var router, route;

        /**
         * We create a router even if there is no one in the DI
         */
        let router = this->getRouter();

        /**
         * Routes are added to the router restricting to PATCH
         */
        let route = router->addPatch(routePattern);

        /**
         * Using the id produced by the router we store the handler
         */
        let this->handlers[route->getRouteId()] = handler;

        /**
         * The route is returned, the developer can add more things on it
         */
        return route;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is POST
     *
     * @param callable handler
     */
    public function post(string! routePattern, handler) -> <RouteInterface>
    {
        var router, route;

        /**
         * We create a router even if there is no one in the DI
         */
        let router = this->getRouter();

        /**
         * Routes are added to the router restricting to POST
         */
        let route = router->addPost(routePattern);

        /**
         * Using the id produced by the router we store the handler
         */
        let this->handlers[route->getRouteId()] = handler;

        /**
         * The route is returned, the developer can add more things on it
         */
        return route;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is PUT
     *
     * @param callable $handler
     */
    public function put(string! routePattern, handler) -> <RouteInterface>
    {
        var router, route;

        /**
         * We create a router even if there is no one in the DI
         */
        let router = this->getRouter();

        /**
         * Routes are added to the router restricting to PUT
         */
        let route = router->addPut(routePattern);

        /**
         * Using the id produced by the router we store the handler
         */
        let this->handlers[route->getRouteId()] = handler;

        /**
         * The route is returned, the developer can add more things on it
         */
        return route;
    }

    /**
     * Sets externally the handler that must be called by the matched route
     *
     * @param callable activeHandler
     */
    public function setActiveHandler(activeHandler)
    {
        let this->activeHandler = activeHandler;
    }

    /**
     * Sets the DependencyInjector container
     */
    public function setDI(<DiInterface> container) -> void
    {
        /**
         * We automatically set ourselves as application service
         */
        if !container->has("application") {
            container->set("application", this);
        }

        let this->container = container;
    }

    /**
     * Sets model binder
     *
     * ```php
     * $micro = new Micro($di);
     *
     * $micro->setModelBinder(
     *     new Binder(),
     *     'cache'
     * );
     * ```
     */
    public function setModelBinder(<BinderInterface> modelBinder, var cache = null) -> <Micro>
    {
        if typeof cache == "string" {
            let cache = this->getService(cache);
        }

        if cache != null {
            modelBinder->setCache(cache);
        }

        let this->modelBinder = modelBinder;

        return this;
    }

    /**
     * Appends a custom 'response' handler to be called instead of the default
     * response handler
     *
     * @param callable handler
     */
    public function setResponseHandler(handler) -> <Micro>
    {
        let this->responseHandler = handler;

        return this;
    }

    /**
     * Sets a service from the DI
     */
    public function setService(string! serviceName, var definition, bool shared = false) -> <ServiceInterface>
    {
        var container;

        let container = this->container;

        if typeof container != "object" {
            let container = new FactoryDefault();

            let this->container = container;
        }

        return container->set(serviceName, definition, shared);
    }

    /**
     * Stops the middleware execution avoiding than other middlewares be
     * executed
     */
    public function stop()
    {
        let this->stopped = true;
    }
}
