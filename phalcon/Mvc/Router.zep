
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc;

use Phalcon\Di\DiInterface;
use Phalcon\Di\AbstractInjectionAware;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Http\RequestInterface;
use Phalcon\Mvc\Router\Exception;
use Phalcon\Mvc\Router\GroupInterface;
use Phalcon\Mvc\Router\Route;
use Phalcon\Mvc\Router\RouteInterface;

/**
 * Phalcon\Mvc\Router
 *
 * Phalcon\Mvc\Router is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the
 * base URL) and decomposing it into parameters to determine which module,
 * controller, and action of that controller should receive the request
 *
 * ```php
 * use Phalcon\Mvc\Router;
 *
 * $router = new Router();
 *
 * $router->add(
 *     "/documentation/{chapter}/{name}\.{type:[a-z]+}",
 *     [
 *         "controller" => "documentation",
 *         "action"     => "show",
 *     ]
 * );
 *
 * $router->handle(
 *     "/documentation/1/examples.html"
 * );
 *
 * echo $router->getControllerName();
 * ```
 */
class Router extends AbstractInjectionAware implements RouterInterface, EventsAwareInterface
{
    const POSITION_FIRST = 0;
    const POSITION_LAST = 1;

    protected action = null;
    protected controller = null;
    protected defaultAction;
    protected defaultController;
    protected defaultModule;
    protected defaultNamespace;
    protected defaultParams = [];
    protected eventsManager;
    protected keyRouteNames = [] { get, set };
    protected keyRouteIds = [] { get, set };
    protected matchedRoute;
    protected matches;
    protected module = null;
    protected namespaceName = null;
    protected notFoundPaths;
    protected params = [];
    protected removeExtraSlashes;
    protected routes;
    protected wasMatched = false;

    /**
     * Phalcon\Mvc\Router constructor
     */
    public function __construct(bool! defaultRoutes = true)
    {
        array routes = [];

        if defaultRoutes {
            /**
             * Two routes are added by default to match /:controller/:action and
             * /:controller/:action/:params
             */

            let routes[] = new Route(
                "#^/([\\w0-9\\_\\-]+)[/]{0,1}$#u",
                [
                    "controller": 1
                ]
            );

            let routes[] = new Route(
                "#^/([\\w0-9\\_\\-]+)/([\\w0-9\\.\\_]+)(/.*)*$#u",
                [
                    "controller": 1,
                    "action":     2,
                    "params":     3
                ]
            );
        }

        let this->routes = routes;
    }

    /**
     * Adds a route to the router without any HTTP constraint
     *
     *```php
     * use Phalcon\Mvc\Router;
     *
     * $router->add("/about", "About::index");
     *
     * $router->add(
     *     "/about",
     *     "About::index",
     *     ["GET", "POST"]
     * );
     *
     * $router->add(
     *     "/about",
     *     "About::index",
     *     ["GET", "POST"],
     *     Router::POSITION_FIRST
     * );
     *```
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function add(string! pattern, var paths = null, var httpMethods = null, var position = Router::POSITION_LAST) -> <RouteInterface>
    {
        var route;

        /**
         * Every route is internally stored as a Phalcon\Mvc\Router\Route
         */
        let route = new Route(pattern, paths, httpMethods);

        this->attach(route, position);

        return route;
    }

    /**
     * Adds a route to the router that only match if the HTTP method is CONNECT
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addConnect(string! pattern, var paths = null, var position = Router::POSITION_LAST) -> <RouteInterface>
    {
        return this->add(pattern, paths, "CONNECT", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is DELETE
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addDelete(string! pattern, var paths = null, var position = Router::POSITION_LAST) -> <RouteInterface>
    {
        return this->add(pattern, paths, "DELETE", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is GET
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addGet(string! pattern, var paths = null, var position = Router::POSITION_LAST) -> <RouteInterface>
    {
        return this->add(pattern, paths, "GET", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is HEAD
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addHead(string! pattern, var paths = null, var position = Router::POSITION_LAST) -> <RouteInterface>
    {
        return this->add(pattern, paths, "HEAD", position);
    }

    /**
     * Add a route to the router that only match if the HTTP method is OPTIONS
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addOptions(string! pattern, var paths = null, var position = Router::POSITION_LAST) -> <RouteInterface>
    {
        return this->add(pattern, paths, "OPTIONS", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is PATCH
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addPatch(string! pattern, var paths = null, var position = Router::POSITION_LAST) -> <RouteInterface>
    {
        return this->add(pattern, paths, "PATCH", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is POST
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addPost(string! pattern, var paths = null, var position = Router::POSITION_LAST) -> <RouteInterface>
    {
        return this->add(pattern, paths, "POST", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is PURGE
     * (Squid and Varnish support)
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addPurge(string! pattern, var paths = null, var position = Router::POSITION_LAST) -> <RouteInterface>
    {
        return this->add(pattern, paths, "PURGE", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is PUT
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addPut(string! pattern, var paths = null, var position = Router::POSITION_LAST) -> <RouteInterface>
    {
        return this->add(pattern, paths, "PUT", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is TRACE
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addTrace(string! pattern, var paths = null, var position = Router::POSITION_LAST) -> <RouteInterface>
    {
        return this->add(pattern, paths, "TRACE", position);
    }

    /**
     * Attach Route object to the routes stack.
     *
     * ```php
     * use Phalcon\Mvc\Router;
     * use Phalcon\Mvc\Router\Route;
     *
     * class CustomRoute extends Route {
     *      // ...
     * }
     *
     * $router = new Router();
     *
     * $router->attach(
     *     new CustomRoute("/about", "About::index", ["GET", "HEAD"]),
     *     Router::POSITION_FIRST
     * );
     * ```
     */
    public function attach(<RouteInterface> route, var position = Router::POSITION_LAST) -> <RouterInterface>
    {
        switch position {
            case self::POSITION_LAST:
                let this->routes[] = route;
                break;
            case self::POSITION_FIRST:
                let this->routes = array_merge([route], this->routes);
                break;
            default:
                throw new Exception("Invalid route position");
        }

        return this;
    }

    /**
     * Removes all the pre-defined routes
     */
    public function clear() -> void
    {
        let this->routes = [];
    }

    /**
     * Returns the internal event manager
     */
    public function getEventsManager() -> <ManagerInterface>
    {
        return this->eventsManager;
    }

    /**
     * Returns the processed action name
     */
    public function getActionName() -> string
    {
        return this->action;
    }

    /**
     * Returns the processed controller name
     */
    public function getControllerName() -> string
    {
        return this->controller;
    }

    /**
     * Returns the route that matches the handled URI
     */
    public function getMatchedRoute() -> <RouteInterface>
    {
        return this->matchedRoute;
    }

    /**
     * Returns the sub expressions in the regular expression matched
     */
    public function getMatches() -> array
    {
        return this->matches;
    }

    /**
     * Returns the processed module name
     */
    public function getModuleName() -> string
    {
        return this->module;
    }

    /**
     * Returns the processed namespace name
     */
    public function getNamespaceName() -> string
    {
        return this->namespaceName;
    }

    /**
     * Returns the processed parameters
     */
    public function getParams() -> array
    {
        return this->params;
    }

    /**
     * Returns a route object by its id
     */
    public function getRouteById(var id) -> <RouteInterface> | bool
    {
        var route, routeId, key;

        if fetch key, this->keyRouteIds[id] {
            return this->routes[key];
        }

        for key, route in this->routes {
            let routeId = route->getRouteId();
            let this->keyRouteIds[routeId] = key;

            if routeId == id {
                return route;
            }
        }

        return false;
    }

    /**
     * Returns a route object by its name
     */
    public function getRouteByName(string! name) -> <RouteInterface> | bool
    {
        var route, routeName, key;

        if fetch key, this->keyRouteNames[name] {
            return this->routes[key];
        }

        for key, route in this->routes {
            let routeName = route->getName();

            if !empty routeName {
                let this->keyRouteNames[routeName] = key;

                if routeName == name {
                    return route;
                }
            }
        }

        return false;
    }

    /**
     * Returns all the routes defined in the router
     */
    public function getRoutes() -> <RouteInterface[]>
    {
        return this->routes;
    }

    /**
     * Handles routing information received from the rewrite engine
     *
     *```php
     * // Passing a URL
     * $router->handle("/posts/edit/1");
     *```
     */
    public function handle(string! uri) -> void
    {
        var request, currentHostName, routeFound, parts, params, matches,
            notFoundPaths, vnamespace, module,  controller, action, paramsStr,
            strParams, route, methods, container, hostname, regexHostName,
            matched, pattern, handledUri, beforeMatch, paths, converters, part,
            position, matchPosition, converter, eventsManager;

        let uri = parse_url(uri, PHP_URL_PATH);

        /**
         * Remove extra slashes in the route
         */
        if this->removeExtraSlashes && uri != "/" {
            let handledUri = rtrim(uri, "/");
        } else {
            let handledUri = uri;
        }

        if empty handledUri {
            let handledUri = "/";
        }

        let request = null,
            currentHostName = null,
            routeFound = false,
            parts = [],
            params = [],
            matches = null,
            this->wasMatched = false,
            this->matchedRoute = null;

        let eventsManager = this->eventsManager;

        if typeof eventsManager == "object" {
            eventsManager->fire("router:beforeCheckRoutes", this);
        }

        /**
         * Routes are traversed in reversed order
         */
        for route in reverse this->routes {
            let params = [],
                matches = null;

            /**
             * Look for HTTP method constraints
             */
            let methods = route->getHttpMethods();

            if methods !== null {
                /**
                 * Retrieve the request service from the container
                 */
                if request === null {
                    let container = <DiInterface> this->container;

                    if unlikely typeof container != "object" {
                        throw new Exception(
                            Exception::containerServiceNotFound(
                                "the 'request' service"
                            )
                        );
                    }

                    let request = <RequestInterface> container->getShared("request");
                }

                /**
                 * Check if the current method is allowed by the route
                 */
                if request->isMethod(methods, true) === false {
                    continue;
                }
            }

            /**
             * Look for hostname constraints
             */
            let hostname = route->getHostName();

            if hostname !== null {
                /**
                 * Retrieve the request service from the container
                 */
                if request === null {
                    let container = <DiInterface> this->container;

                    if unlikely typeof container != "object" {
                        throw new Exception(
                            Exception::containerServiceNotFound(
                                "the 'request' service"
                            )
                        );
                    }

                    let request = <RequestInterface> container->getShared("request");
                }

                /**
                 * Check if the current hostname is the same as the route
                 */
                if currentHostName === null {
                    let currentHostName = request->getHttpHost();
                }

                /**
                 * No HTTP_HOST, maybe in CLI mode?
                 */
                if !currentHostName {
                    continue;
                }

                /**
                 * Check if the hostname restriction is the same as the current
                 * in the route
                 */
                if memstr(hostname, "(") {
                    if !memstr(hostname, "#") {
                        let regexHostName = "#^" . hostname;

                        if !memstr(hostname, ":") {
                            let regexHostName .= "(:[[:digit:]]+)?";
                        }

                        let regexHostName .= "$#i";
                    } else {
                        let regexHostName = hostname;
                    }

                    let matched = preg_match(regexHostName, currentHostName);
                } else {
                    let matched = currentHostName == hostname;
                }

                if !matched {
                    continue;
                }
            }

            if typeof eventsManager == "object" {
                eventsManager->fire("router:beforeCheckRoute", this, route);
            }

            /**
             * If the route has parentheses use preg_match
             */
            let pattern = route->getCompiledPattern();

            if memstr(pattern, "^") {
                let routeFound = preg_match(pattern, handledUri, matches);
            } else {
                let routeFound = pattern == handledUri;
            }

            /**
             * Check for beforeMatch conditions
             */
            if routeFound {
                if typeof eventsManager == "object" {
                    eventsManager->fire("router:matchedRoute", this, route);
                }

                let beforeMatch = route->getBeforeMatch();

                if beforeMatch !== null {
                    /**
                     * Check first if the callback is callable
                     */
                    if unlikely !is_callable(beforeMatch) {
                        throw new Exception(
                            "Before-Match callback is not callable in matched route"
                        );
                    }

                    /**
                     * Check first if the callback is callable
                     */
                    let routeFound = call_user_func_array(
                        beforeMatch,
                        [
                            handledUri,
                            route,
                            this
                        ]
                    );
                }

            } else {
                if typeof eventsManager == "object" {
                    let routeFound = eventsManager->fire("router:notMatchedRoute", this, route);
                }
            }

            if routeFound {
                /**
                 * Start from the default paths
                 */
                let paths = route->getPaths(),
                    parts = paths;

                /**
                 * Check if the matches has variables
                 */
                if typeof matches == "array" {
                    /**
                     * Get the route converters if any
                     */
                    let converters = route->getConverters();

                    for part, position in paths {
                        if unlikely typeof part != "string" {
                            throw new Exception("Wrong key in paths: " . part);
                        }

                        if typeof position != "string" && typeof position != "integer" {
                            continue;
                        }

                        if fetch matchPosition, matches[position] {
                            /**
                             * Check if the part has a converter
                             */
                            if typeof converters == "array" {
                                if fetch converter, converters[part] {
                                    let parts[part] = call_user_func_array(
                                        converter,
                                        [matchPosition]
                                    );

                                    continue;
                                }
                            }

                            /**
                             * Update the parts if there is no converter
                             */
                            let parts[part] = matchPosition;
                        } else {
                            /**
                             * Apply the converters anyway
                             */
                            if typeof converters == "array" {
                                if fetch converter, converters[part] {
                                    let parts[part] = call_user_func_array(
                                        converter,
                                        [position]
                                    );
                                }
                            } else {
                                /**
                                 * Remove the path if the parameter was not
                                 * matched
                                 */
                                if typeof position == "integer" {
                                    unset parts[part];
                                }
                            }
                        }
                    }

                    /**
                     * Update the matches generated by preg_match
                     */
                    let this->matches = matches;
                }

                let this->matchedRoute = route;

                break;
            }
        }

        /**
         * Update the wasMatched property indicating if the route was matched
         */
        if routeFound {
            let this->wasMatched = true;
        } else {
            let this->wasMatched = false;
        }

        /**
         * The route wasn't found, try to use the not-found paths
         */
        if !routeFound {
            let notFoundPaths = this->notFoundPaths;

            if notFoundPaths !== null {
                let parts = Route::getRoutePaths(notFoundPaths),
                    routeFound = true;
            }
        }

        /**
         * Use default values before we overwrite them if the route is matched
         */
        let this->namespaceName = this->defaultNamespace,
            this->module = this->defaultModule,
            this->controller = this->defaultController,
            this->action = this->defaultAction,
            this->params = this->defaultParams;

        if routeFound {
            /**
             * Check for a namespace
             */
            if fetch vnamespace, parts["namespace"] {
                if !is_numeric(vnamespace) {
                    let this->namespaceName = vnamespace;
                }

                unset parts["namespace"];
            }

            /**
             * Check for a module
             */
            if fetch module, parts["module"] {
                if !is_numeric(module) {
                    let this->module = module;
                }

                unset parts["module"];
            }

            /**
             * Check for a controller
             */
            if fetch controller, parts["controller"] {
                if !is_numeric(controller) {
                    let this->controller = controller;
                }

                unset parts["controller"];
            }

            /**
             * Check for an action
             */
            if fetch action, parts["action"] {
                if !is_numeric(action) {
                    let this->action = action;
                }

                unset parts["action"];
            }

            /**
             * Check for parameters
             */
            if fetch paramsStr, parts["params"] {
                if typeof paramsStr == "string" {
                    let strParams = trim(paramsStr, "/");

                    if strParams !== "" {
                        let params = explode("/", strParams);
                    }
                }

                unset parts["params"];
            }

            if count(params) {
                let this->params = array_merge(params, parts);
            } else {
                let this->params = parts;
            }
        }

        if typeof eventsManager == "object" {
            eventsManager->fire("router:afterCheckRoutes", this);
        }
    }

    /**
     * Returns whether controller name should not be mangled
     */
    public function isExactControllerName() -> bool
    {
        return true;
    }

    /**
     * Mounts a group of routes in the router
     */
    public function mount(<GroupInterface> group) -> <RouterInterface>
    {
        var groupRoutes, beforeMatch, hostname, routes, route, eventsManager;

        let eventsManager = this->eventsManager;

        if typeof eventsManager == "object" {
            eventsManager->fire("router:beforeMount", this, group);
        }

        let groupRoutes = group->getRoutes();

        if unlikely !count(groupRoutes) {
            throw new Exception(
                "The group of routes does not contain any routes"
            );
        }

        /**
         * Get the before-match condition
         */
        let beforeMatch = group->getBeforeMatch();

        if beforeMatch !== null {
            for route in groupRoutes {
                route->beforeMatch(beforeMatch);
            }
        }

        // Get the hostname restriction
        let hostname = group->getHostName();

        if hostname !== null {
            for route in groupRoutes {
                route->setHostName(hostname);
            }
        }

        let routes = this->routes;

        let this->routes = array_merge(routes, groupRoutes);

        return this;
    }

    /**
     * Set a group of paths to be returned when none of the defined routes are
     * matched
     */
    public function notFound(var paths) -> <RouterInterface>
    {
        if unlikely (typeof paths != "array" && typeof paths != "string") {
            throw new Exception(
                "The not-found paths must be an array or string"
            );
        }

        let this->notFoundPaths = paths;

        return this;
    }

    /**
     * Set whether router must remove the extra slashes in the handled routes
     */
    public function removeExtraSlashes(bool! remove) -> <RouterInterface>
    {
        let this->removeExtraSlashes = remove;

        return this;
    }

    /**
     * Sets the default action name
     */
    public function setDefaultAction(string! actionName) -> <RouterInterface>
    {
        let this->defaultAction = actionName;

        return this;
    }

    /**
     * Sets the default controller name
     */
    public function setDefaultController(string! controllerName) -> <RouterInterface>
    {
        let this->defaultController = controllerName;

        return this;
    }

    /**
     * Sets the name of the default module
     */
    public function setDefaultModule(string! moduleName) -> <RouterInterface>
    {
        let this->defaultModule = moduleName;

        return this;
    }

    /**
     * Sets the name of the default namespace
     */
    public function setDefaultNamespace(string! namespaceName) -> <RouterInterface>
    {
        let this->defaultNamespace = namespaceName;

        return this;
    }

    /**
     * Sets an array of default paths. If a route is missing a path the router
     * will use the defined here. This method must not be used to set a 404
     * route
     *
     *```php
     * $router->setDefaults(
     *     [
     *         "module" => "common",
     *         "action" => "index",
     *     ]
     * );
     *```
     */
    public function setDefaults(array! defaults) -> <RouterInterface>
    {
        var namespaceName, module, controller, action, params;

        // Set a default namespace
        if fetch namespaceName, defaults["namespace"] {
            let this->defaultNamespace = namespaceName;
        }

        // Set a default module
        if fetch module, defaults["module"] {
            let this->defaultModule = module;
        }

        // Set a default controller
        if fetch controller, defaults["controller"] {
            let this->defaultController = controller;
        }

        // Set a default action
        if fetch action, defaults["action"] {
            let this->defaultAction = action;
        }

        // Set default parameters
        if fetch params, defaults["params"] {
            let this->defaultParams = params;
        }

        return this;
    }

    /**
     * Returns an array of default parameters
     */
    public function getDefaults() -> array
    {
        return [
            "namespace":  this->defaultNamespace,
            "module":     this->defaultModule,
            "controller": this->defaultController,
            "action":     this->defaultAction,
            "params":     this->defaultParams
        ];
    }

    /**
     * Sets the events manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }

    /**
     * Checks if the router matches any of the defined routes
     */
    public function wasMatched() -> bool
    {
        return this->wasMatched;
    }
}
