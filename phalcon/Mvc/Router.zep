
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc;

use Phalcon\Config\ConfigInterface;
use Phalcon\Di\AbstractInjectionAware;
use Phalcon\Di\DiInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Http\RequestInterface;
use Phalcon\Mvc\Router\Exception;
use Phalcon\Mvc\Router\Exceptions\BeforeMatchNotCallable;
use Phalcon\Mvc\Router\Exceptions\ConfigKeyMustBeArray;
use Phalcon\Mvc\Router\Exceptions\EmptyGroupOfRoutes;
use Phalcon\Mvc\Router\Exceptions\GroupRoutesMustBeArray;
use Phalcon\Mvc\Router\Exceptions\InvalidConfigSource;
use Phalcon\Mvc\Router\Exceptions\InvalidNotFoundPaths;
use Phalcon\Mvc\Router\Exceptions\InvalidRoutePosition;
use Phalcon\Mvc\Router\Exceptions\MissingGroupRouteKey;
use Phalcon\Mvc\Router\Exceptions\MissingRouteConfigKey;
use Phalcon\Mvc\Router\Exceptions\RequestServiceUnavailable;
use Phalcon\Mvc\Router\Exceptions\UnknownHttpMethod;
use Phalcon\Mvc\Router\Exceptions\WrongPathsKey;
use Phalcon\Mvc\Router\Group;
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
    /**
     * @var int
     */
    const POSITION_FIRST = 0;
    /**
     * @var int
     */
    const POSITION_LAST = 1;

    /**
     * @var int
     */
    const URI_SOURCE_GET_URL = 0;
    /**
     * @var int
     */
    const URI_SOURCE_SERVER_REQUEST_URI = 1;

    /**
     * @var string
     */
    protected action = "";

    /**
     * @var string
     */
    protected controller = "";

    /**
     * @var string
     */
    protected defaultAction = "";

    /**
     * @var string
     */
    protected defaultController = "";

    /**
     * @var string
     */
    protected defaultModule = "";

    /**
     * @var string
     */
    protected defaultNamespace = "";

    /**
     * @var array
     */
    protected defaultParams = [];

    /**
     * @var ManagerInterface|null
     */
    protected eventsManager;

    /**
     * @var array
     */
    protected keyRouteNames = [];

    /**
     * @var array
     */
    protected keyRouteIds = [];

    /**
     * @var RouteInterface|null
     */
    protected matchedRoute = null;

    /**
     * @var array
     */
    protected matches = [];

    /**
     * @var array
     */
    protected methodRoutes = [];

    /**
     * @var bool
     */
    protected methodRoutesDirty = true;

    /**
     * @var string
     */
    protected module = "";

    /**
     * @var string
     */
    protected namespaceName = "";

    /**
     * @var array|string|null
     */
    protected notFoundPaths = null;

    /**
     * @var array
     */
    protected params = [];

    /**
     * @var bool
     */
    protected removeExtraSlashes = false;

    /**
     * @var array
     */
    protected routes = [];

    /**
    * @var int
     */
    protected uriSource = self::URI_SOURCE_GET_URL;

    /**
     * @var bool
     */
    protected wasMatched = false;

    /**
     * Phalcon\Mvc\Router constructor
     *
     * @param bool defaultRoutes
     */
    public function __construct(bool! defaultRoutes = true)
    {
        if defaultRoutes {
            /**
             * Two routes are added by default to match /:controller/:action and
             * /:controller/:action/:params
             */
            this->attach(
                new Route(
                    "#^/([\\w0-9\\_\\-]+)[/]{0,1}$#u",
                    [
                        "controller": 1
                    ]
                )
            );

            this->attach(
                new Route(
                    "#^/([\\w0-9\\_\\-]+)/([\\w0-9\\.\\_]+)(/.*)*$#u",
                    [
                        "controller": 1,
                        "action":     2,
                        "params":     3
                    ]
                )
            );
        }
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
     * @param string            $pattern
     * @param array|string|null $paths = [
     *                                 'module => '',
     *                                 'controller' => '',
     *                                 'action' => '',
     *                                 'namespace' => ''
     *                                 ]
     * @param array|string|null $httpMethods
     * @param int               $position
     *
     * @return RouteInterface
     */
    public function add(
        string! pattern,
        var paths = null,
        var httpMethods = null,
        int position = Router::POSITION_LAST
    ) -> <RouteInterface> {
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
     * @param string            $pattern
     * @param array|string|null $paths  = [
     *                                  'module => '',
     *                                  'controller' => '',
     *                                  'action' => '',
     *                                  'namespace' => ''
     *                                  ]
     * @param int               $position
     *
     * @return RouteInterface
     */
    public function addConnect(
        string! pattern,
        var paths = null,
        int position = Router::POSITION_LAST
    ) -> <RouteInterface> {
        return this->add(pattern, paths, "CONNECT", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is DELETE
     *
     * @param string            $pattern
     * @param array|string|null $paths  = [
     *                                  'module => '',
     *                                  'controller' => '',
     *                                  'action' => '',
     *                                  'namespace' => ''
     *                                  ]
     * @param int               $position
     *
     * @return RouteInterface
     */
    public function addDelete(
        string! pattern,
        var paths = null,
        int position = Router::POSITION_LAST
    ) -> <RouteInterface> {
        return this->add(pattern, paths, "DELETE", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is GET
     *
     * @param string            $pattern
     * @param array|string|null $paths  = [
     *                                  'module => '',
     *                                  'controller' => '',
     *                                  'action' => '',
     *                                  'namespace' => ''
     *                                  ]
     * @param int               $position
     *
     * @return RouteInterface
     */
    public function addGet(
        string! pattern,
        var paths = null,
        int position = Router::POSITION_LAST
    ) -> <RouteInterface> {
        return this->add(pattern, paths, "GET", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is HEAD
     *
     * @param string            $pattern
     * @param array|string|null $paths  = [
     *                                  'module => '',
     *                                  'controller' => '',
     *                                  'action' => '',
     *                                  'namespace' => ''
     *                                  ]
     * @param int               $position
     *
     * @return RouteInterface
     */
    public function addHead(
        string! pattern,
        var paths = null,
        int position = Router::POSITION_LAST
    ) -> <RouteInterface> {
        return this->add(pattern, paths, "HEAD", position);
    }

    /**
     * Add a route to the router that only match if the HTTP method is OPTIONS
     *
     * @param string            $pattern
     * @param array|string|null $paths  = [
     *                                  'module => '',
     *                                  'controller' => '',
     *                                  'action' => '',
     *                                  'namespace' => ''
     *                                  ]
     * @param int               $position
     *
     * @return RouteInterface
     */
    public function addOptions(
        string! pattern,
        var paths = null,
        int position = Router::POSITION_LAST
    ) -> <RouteInterface> {
        return this->add(pattern, paths, "OPTIONS", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is PATCH
     *
     * @param string            $pattern
     * @param array|string|null $paths  = [
     *                                  'module => '',
     *                                  'controller' => '',
     *                                  'action' => '',
     *                                  'namespace' => ''
     *                                  ]
     * @param int               $position
     *
     * @return RouteInterface
     */
    public function addPatch(
        string! pattern,
        var paths = null,
        int position = Router::POSITION_LAST
    ) -> <RouteInterface> {
        return this->add(pattern, paths, "PATCH", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is POST
     *
     * @param string            $pattern
     * @param array|string|null $paths  = [
     *                                  'module => '',
     *                                  'controller' => '',
     *                                  'action' => '',
     *                                  'namespace' => ''
     *                                  ]
     * @param int               $position
     *
     * @return RouteInterface
     */
    public function addPost(
        string! pattern,
        var paths = null,
        int position = Router::POSITION_LAST
    ) -> <RouteInterface> {
        return this->add(pattern, paths, "POST", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is PURGE
     * (Squid and Varnish support)
     *
     * @param string            $pattern
     * @param array|string|null $paths  = [
     *                                  'module => '',
     *                                  'controller' => '',
     *                                  'action' => '',
     *                                  'namespace' => ''
     *                                  ]
     * @param int               $position
     *
     * @return RouteInterface
     */
    public function addPurge(
        string! pattern,
        var paths = null,
        int position = Router::POSITION_LAST
    ) -> <RouteInterface> {
        return this->add(pattern, paths, "PURGE", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is PUT
     *
     * @param string            $pattern
     * @param array|string|null $paths  = [
     *                                  'module => '',
     *                                  'controller' => '',
     *                                  'action' => '',
     *                                  'namespace' => ''
     *                                  ]
     * @param int               $position
     *
     * @return RouteInterface
     */
    public function addPut(
        string! pattern,
        var paths = null,
        int position = Router::POSITION_LAST
    ) -> <RouteInterface> {
        return this->add(pattern, paths, "PUT", position);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is TRACE
     *
     * @param string            $pattern
     * @param array|string|null $paths  = [
     *                                  'module => '',
     *                                  'controller' => '',
     *                                  'action' => '',
     *                                  'namespace' => ''
     *                                  ]
     * @param int               $position
     *
     * @return RouteInterface
     */
    public function addTrace(
        string! pattern,
        var paths = null,
        int position = Router::POSITION_LAST
    ) -> <RouteInterface> {
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
     *
     * @param RouteInterface $route
     * @param int            $position
     *
     * @return RouterInterface
     */
    public function attach(
        <RouteInterface> route,
        int position = Router::POSITION_LAST
    ) -> <static> {
        switch position {
            case self::POSITION_LAST:
                let this->routes[] = route;
                break;
            case self::POSITION_FIRST:
                let this->routes = array_merge([route], this->routes);
                break;
            default:
                throw new InvalidRoutePosition();
        }

        let this->methodRoutesDirty = true;

        return this;
    }

    /**
     * Removes all the pre-defined routes
     */
    public function clear() -> void
    {
        let this->routes            = [],
            this->methodRoutes      = [],
            this->methodRoutesDirty = true;
    }

    /**
     * Returns the internal event manager
     */
    public function getEventsManager() -> <ManagerInterface> | null
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
     * @return array
     */
    public function getKeyRouteNames() -> array
    {
        return this->keyRouteNames;
    }

    /**
     * @return array
     */
    public function getKeyRouteIds() -> array
    {
        return this->keyRouteIds;
    }

    /**
     * Returns the route that matches the handled URI
     */
    public function getMatchedRoute() -> <RouteInterface> | null
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
     * Returns the routes indexed by HTTP method.
     * Routes with no HTTP constraint are stored under the "*" key.
     *
     * @return array
     */
    public function getMethodRoutes() -> array
    {
        if this->methodRoutesDirty {
            this->rebuildMethodIndex();
        }

        return this->methodRoutes;
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
     * Get rewrite info. This info is read from $_GET["_url"].
     * This returns '/' if the rewrite information cannot be read
     */
    public function getRewriteUri() -> string
    {
        var url;

        /**
         * By default we use $_GET["url"] to obtain the rewrite information
         */
        if (self::URI_SOURCE_GET_URL === this->uriSource) {
            if fetch url, _GET["_url"] {
                if !empty url {
                    return this->extractRealUri(url);
                }
            }
        } else {
            /**
             * Otherwise use the standard $_SERVER["REQUEST_URI"]
             */
            if fetch url, _SERVER["REQUEST_URI"] {
                if !empty url {
                    return this->extractRealUri(url);
                }
            }
        }

        return "/";
    }

    protected function extractRealUri(string! uri) -> string
    {
        var urlParts, realUri;

        let urlParts = explode("?", uri, 2),
            realUri  = urlParts[0];

        return realUri;
    }

    protected function rebuildMethodIndex() -> void
    {
        var route, methods, method;

        let this->methodRoutes = [];

        for route in this->routes {
            let methods = route->getHttpMethods();

            if methods === null {
                let this->methodRoutes["*"][] = route;
            } elseif typeof methods == "string" {
                let this->methodRoutes[methods][] = route;
            } else {
                for method in methods {
                    let this->methodRoutes[method][] = route;
                }
            }
        }

        let this->methodRoutesDirty = false;
    }

    /**
     * Returns a route object by its id
     *
     * @param mixed id
     *
     * @return RouteInterface|bool
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
     *
     * @param string name
     *
     * @return RouteInterface|bool
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
     *
     * @return array
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
     *
     * @param string uri
     *
     * @return void
     */
    public function handle(string! uri) -> void
    {
        var action, beforeMatch, candidateRoutes, container, controller,
            converter, converters, currentHostName, eventsManager, handledUri,
            hostname, matched, matches, matchPosition, methodCandidates,
            module, notFoundPaths, params, paramsStr, part, parts, paths,
            pattern, position, realUri, regexHostName, request, requestMethod,
            route, routeFound, strParams, vnamespace;

        if !uri {
            /**
             * If 'uri' isn't passed as parameter it reads _GET["_url"]
             */
            let realUri = this->getRewriteUri();
        } else {
            let realUri = this->extractRealUri(uri);
        }

        /**
         * Remove extra slashes in the route
         */
        if this->removeExtraSlashes && realUri !== "/" {
            let handledUri = rtrim(realUri, "/");
        } else {
            let handledUri = realUri;
        }

        if empty handledUri {
            let handledUri = "/";
        }

        let currentHostName = null,
            routeFound = false,
            parts = [],
            params = [],
            matches = null,
            this->wasMatched = false,
            this->matchedRoute = null;

        let eventsManager = this->eventsManager;
        if eventsManager !== null {
            eventsManager->fire("router:beforeCheckRoutes", this);
        }

        /**
         * Retrieve the request service from the container
         */
        let container = <DiInterface> this->container;
        if container === null {
            throw new RequestServiceUnavailable();
        }

        let request = <RequestInterface> container->get("request");

        /**
         * Build a candidate list of routes that match the request method.
         * Routes with no HTTP constraint are stored under "*" and are always
         * included. This avoids iterating the full route array per request.
         */
        if this->methodRoutesDirty {
            this->rebuildMethodIndex();
        }

        let requestMethod    = request->getMethod(),
            methodCandidates = [],
            candidateRoutes  = [];

        if fetch methodCandidates, this->methodRoutes[requestMethod] {
            let candidateRoutes = methodCandidates;
        }

        if fetch methodCandidates, this->methodRoutes["*"] {
            let candidateRoutes = array_merge(candidateRoutes, methodCandidates);
        }

        /**
         * Routes are traversed in reversed order
         */
        for route in reverse candidateRoutes {
            let params  = [],
                matches = null;

            /**
             * Look for hostname constraints
             */
            let hostname = route->getHostName();
            if hostname !== null {
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

            if typeof eventsManager === "object" {
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
                if typeof eventsManager === "object" {
                    eventsManager->fire("router:matchedRoute", this, route);
                }

                let beforeMatch = route->getBeforeMatch();
                if beforeMatch !== null {
                    /**
                     * Check first if the callback is callable
                     */
                    if unlikely !is_callable(beforeMatch) {
                        throw new BeforeMatchNotCallable();
                    }

                    /**
                     * Check first if the callback is callable
                     */
                    let routeFound = {beforeMatch}(handledUri, route, this);
                }

            } else {
                if typeof eventsManager === "object" {
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
                if typeof matches === "array" {
                    /**
                     * Get the route converters if any
                     */
                    let converters = route->getConverters();

                    for part, position in paths {
                        if unlikely typeof part !== "string" {
                            throw new WrongPathsKey(part);
                        }

                        if typeof position !== "string" && typeof position !== "integer" {
                            continue;
                        }

                        if fetch matchPosition, matches[position] {
                            /**
                             * Check if the part has a converter
                             */
                            if typeof converters === "array" {
                                if fetch converter, converters[part] {
                                    let parts[part] = {converter}(matchPosition);

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
                            if typeof converters === "array" && fetch converter, converters[part] {
                                let parts[part] = {converter}(position);
                            } elseif typeof position === "integer" {
                                /**
                                 * Remove the path if the parameter was not
                                 * matched
                                 */
                                unset parts[part];
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
                let this->namespaceName = vnamespace;

                unset parts["namespace"];
            }

            /**
             * Check for a module
             */
            if fetch module, parts["module"] {
                let this->module = module;

                unset parts["module"];
            }

            /**
             * Check for a controller
             */
            if fetch controller, parts["controller"] {
                let this->controller = controller;

                unset parts["controller"];
            }

            /**
             * Check for an action
             */
            if fetch action, parts["action"] {
                let this->action = action;

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

        if typeof eventsManager === "object" {
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
     * Loads routes from an array or Phalcon\Config\Config instance.
     *
     *```php
     * $router->loadFromConfig(
     *      [
     *          'routes' => [
     *              [
     *                  'method'  => 'get',
     *                  'pattern' => '/users',
     *                  'paths'   => 'Users::index',
     *              ],
     *          ],
     *      ]
     *  );
     *```
     *
     * @param array|ConfigInterface config
     *
     * @return RouterInterface
     */
    public function loadFromConfig(var config) -> <static>
    {
        var routes, routeData, defaults, notFoundPaths, removeExtra, groups, groupData;

        if typeof config === "object" {
            if !(config instanceof ConfigInterface) {
                throw new InvalidConfigSource();
            }
            let config = config->toArray();
        }

        if typeof config !== "array" {
            throw new InvalidConfigSource();
        }

        if isset config["removeExtraSlashes"] {
            let removeExtra = config["removeExtraSlashes"];
            this->removeExtraSlashes((bool) removeExtra);
        }

        if isset config["defaults"] {
            let defaults = config["defaults"];
            if typeof defaults !== "array" {
                throw new ConfigKeyMustBeArray("defaults");
            }
            this->setDefaults(defaults);
        }

        if fetch routes, config["routes"] {
            if typeof routes !== "array" {
                throw new ConfigKeyMustBeArray("routes");
            }
            for routeData in routes {
                this->addRouteFromConfig(routeData);
            }
        }

        if fetch groups, config["groups"] {
            if typeof groups !== "array" {
                throw new ConfigKeyMustBeArray("groups");
            }
            for groupData in groups {
                this->mountGroupFromConfig(groupData);
            }
        }

        if fetch notFoundPaths, config["notFound"] {
            this->notFound(notFoundPaths);
        }

        return this;
    }

    /**
     * Adds a single route from a config array entry. Used by loadFromConfig.
     *
     * @param array routeData
     *
     * @return void
     */
    protected function addRouteFromConfig(array routeData) -> void
    {
        var method, methodClass, pattern, paths, route;

        if !fetch pattern, routeData["pattern"] {
            throw new MissingRouteConfigKey("pattern");
        }

        if !fetch paths, routeData["paths"] {
            throw new MissingRouteConfigKey("paths");
        }

        let method = "";
        if isset routeData["method"] && routeData["method"] !== null {
            let method = strtolower((string) routeData["method"]);
        }

        switch method {
            case "":
            case "connect":
            case "delete":
            case "get":
            case "head":
            case "options":
            case "patch":
            case "post":
            case "purge":
            case "put":
            case "trace":
                let methodClass = "add" . ucfirst(method);
                let route = this->{methodClass}(pattern, paths);
                break;
            default:
                throw new UnknownHttpMethod(method);
        }

        if isset routeData["name"] {
            route->setName((string) routeData["name"]);
        }
        if isset routeData["hostname"] {
            route->setHostname((string) routeData["hostname"]);
        }
    }

    /**
     * Builds a Group from a config entry and mounts it. Used by loadFromConfig.
     *
     * @param array groupData
     *
     * @return void
     */
    protected function mountGroupFromConfig(array groupData) -> void
    {
        var group, paths, routes, routeData, method, methodClass, pattern, routePaths, route;

        let paths = null;
        if isset groupData["paths"] {
            let paths = groupData["paths"];
        }

        let group = new Group(paths);

        if isset groupData["prefix"] {
            group->setPrefix((string) groupData["prefix"]);
        }

        if isset groupData["hostname"] {
            group->setHostname((string) groupData["hostname"]);
        }

        if !fetch routes, groupData["routes"] {
            let routes = [];
        }

        if typeof routes !== "array" {
            throw new GroupRoutesMustBeArray();
        }

        for routeData in routes {
            if !fetch pattern, routeData["pattern"] {
                throw new MissingGroupRouteKey("pattern");
            }
            if !fetch routePaths, routeData["paths"] {
                throw new MissingGroupRouteKey("paths");
            }

            let method = "";
            if isset routeData["method"] && routeData["method"] !== null {
                let method = strtolower((string) routeData["method"]);
            }

            switch method {
                case "":
                case "connect":
                case "delete":
                case "get":
                case "head":
                case "options":
                case "patch":
                case "post":
                case "purge":
                case "put":
                case "trace":
                    let methodClass = "add" . ucfirst(method);
                    let route = group->{methodClass}(pattern, routePaths);
                    break;
                default:
                    throw new UnknownHttpMethod(method);
            }

            if isset routeData["name"] {
                route->setName((string) routeData["name"]);
            }
        }

        this->mount(group);
    }

    /**
     * Mounts a group of routes in the router
     *
     * @param GroupInterface group
     *
     * @return RouterInterface
     */
    public function mount(<GroupInterface> group) -> <static>
    {
        var groupRoutes, beforeMatch, hostname, route, eventsManager;

        let eventsManager = this->eventsManager;

        if typeof eventsManager == "object" {
            eventsManager->fire("router:beforeMount", this, group);
        }

        let groupRoutes = group->getRoutes();

        if unlikely !count(groupRoutes) {
            throw new EmptyGroupOfRoutes();
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

        for route in groupRoutes {
            this->attach(route);
        }

        return this;
    }

    /**
     * Set a group of paths to be returned when none of the defined routes are
     * matched
     *
     * @param array|string|null paths
     *
     * @return RouterInterface
     */
    public function notFound(var paths) -> <static>
    {
        if unlikely (typeof paths !== "array" && typeof paths !== "string") {
            throw new InvalidNotFoundPaths();
        }

        let this->notFoundPaths = paths;

        return this;
    }

    /**
     * Set whether router must remove the extra slashes in the handled routes
     *
     * @param bool remove
     *
     * @return RouterInterface
     */
    public function removeExtraSlashes(bool! remove) -> <static>
    {
        let this->removeExtraSlashes = remove;

        return this;
    }

    /**
     * Sets the default action name
     *
     * @param string actionName
     *
     * @return RouterInterface
     */
    public function setDefaultAction(string! actionName) -> <static>
    {
        let this->defaultAction = actionName;

        return this;
    }

    /**
     * Sets the default controller name
     *
     * @param string controllerName
     *
     * @return RouterInterface
     */
    public function setDefaultController(string! controllerName) -> <static>
    {
        let this->defaultController = controllerName;

        return this;
    }

    /**
     * Sets the name of the default module
     *
     * @param string moduleName
     *
     * @return RouterInterface
     */
    public function setDefaultModule(string! moduleName) -> <static>
    {
        let this->defaultModule = moduleName;

        return this;
    }

    /**
     * Sets the name of the default namespace
     *
     * @parma string namespaceName
     *
     * @return RouterInterface
     */
    public function setDefaultNamespace(string! namespaceName) -> <static>
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
     *
     * @param array defaults
     *
     * @return RouterInterface
     */
    public function setDefaults(array! defaults) -> <static>
    {
        var namespaceName, module, controller, action, params;

        // Set a default namespace
        if fetch namespaceName, defaults["namespace"] {
            let this->defaultNamespace = (string)namespaceName;
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
     * Sets the events manager
     *
     * @param ManagerInterface eventsManager
     *
     * @return void
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }

    /**
     * @param array $routeNames
     *
     * @return Router
     */
    public function setKeyRouteNames(array routeNames) -> <static>
    {
        let this->keyRouteNames = routeNames;

        return this;
    }

    /**
     * @param array $routeIds
     *
     * @return Router
     */
    public function setKeyRouteIds(array routeIds) -> <static>
    {
        let this->keyRouteIds = routeIds;

        return this;
    }

    /**
     * Sets the URI source. One of the URI_SOURCE_* constants
     *
     * ```php
     * $router->setUriSource(
     *     Router::URI_SOURCE_SERVER_REQUEST_URI
     * );
     * ```
     */
    public function setUriSource(int uriSource) -> <static>
    {
        let this->uriSource = uriSource;

        return this;
    }

    /**
     * Checks if the router matches any of the defined routes
     *
     * @return bool
     */
    public function wasMatched() -> bool
    {
        return this->wasMatched;
    }
}
