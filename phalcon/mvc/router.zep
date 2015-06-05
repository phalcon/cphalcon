
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc;

use Phalcon\Di\InjectionAwareInterface;
use Phalcon\DiInterface;
use Phalcon\Mvc\Router\Route;
use Phalcon\Mvc\Router\RouteInterface;
use Phalcon\Mvc\Router\Exception;
use Phalcon\Http\RequestInterface;
use Phalcon\Mvc\Router\GroupInterface;

/**
 * Phalcon\Mvc\Router
 *
 * <p>Phalcon\Mvc\Router is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request</p>
 *
 *<code>
 *
 *	$router = new Router();
 *
 *	$router->add(
 *		"/documentation/{chapter}/{name}.{type:[a-z]+}",
 *		array(
 *			"controller" => "documentation",
 *			"action"     => "show"
 *		)
 *	);
 *
 *	$router->handle();
 *
 *	echo $router->getControllerName();
 *</code>
 */
class Router implements InjectionAwareInterface, RouterInterface
{
	protected _dependencyInjector;

	protected _uriSource;

	protected _namespace = null;

	protected _module = null;

	protected _controller = null;

	protected _action = null;

	protected _params;

	protected _routes;

	protected _matchedRoute;

	protected _matches;

	protected _wasMatched = false;

	protected _defaultNamespace;

	protected _defaultModule;

	protected _defaultController;

	protected _defaultAction;

	protected _defaultParams;

	protected _removeExtraSlashes;

	protected _notFoundPaths;

	const URI_SOURCE_GET_URL = 0;

	const URI_SOURCE_SERVER_REQUEST_URI = 1;

	/**
	 * Phalcon\Mvc\Router constructor
	 */
	public function __construct(boolean! defaultRoutes = true)
	{
		array routes = [];

		if defaultRoutes {

			// Two routes are added by default to match /:controller/:action and
			// /:controller/:action/:params

			let routes[] = new Route("#^/([a-zA-Z0-9\\_\\-]+)[/]{0,1}$#", [
				"controller": 1
			]);

			let routes[] = new Route("#^/([a-zA-Z0-9\\_\\-]+)/([a-zA-Z0-9\\.\\_]+)(/.*)*$#", [
				"controller": 1,
				"action": 2,
				"params": 3
			]);
		}

		let this->_params = [],
			this->_defaultParams = [],
			this->_routes = routes;
	}

	/**
	 * Sets the dependency injector
	 */
	public function setDI(<DiInterface> dependencyInjector) -> void
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Get rewrite info. This info is read from $_GET['_url']. This returns '/' if the rewrite information cannot be read
	 */
	public function getRewriteUri() -> string
	{
		var url, urlParts, realUri;

		/**
		 * By default we use $_GET['url'] to obtain the rewrite information
		 */
		if !this->_uriSource {
			if fetch url, _GET["_url"] {
				if !empty url {
					return url;
				}
			}
		} else {
			/**
			 * Otherwise use the standard $_SERVER['REQUEST_URI']
			 */
			if fetch url, _SERVER["REQUEST_URI"] {
				let urlParts = explode("?", url),
					realUri = urlParts[0];
				if !empty realUri {
					return realUri;
				}
			}
		}
		return "/";
	}

	/**
	 * Sets the URI source. One of the URI_SOURCE_* constants
	 *
	 *<code>
	 *	$router->setUriSource(Router::URI_SOURCE_SERVER_REQUEST_URI);
	 *</code>
	 */
	public function setUriSource(var uriSource) -> <RouterInterface>
	{
		let this->_uriSource = uriSource;
		return this;
	}

	/**
	 * Set whether router must remove the extra slashes in the handled routes
	 */
	public function removeExtraSlashes(boolean! remove) -> <RouterInterface>
	{
		let this->_removeExtraSlashes = remove;
		return this;
	}

	/**
	 * Sets the name of the default namespace
	 */
	public function setDefaultNamespace(string! namespaceName) -> <RouterInterface>
	{
		let this->_defaultNamespace = namespaceName;
		return this;
	}

	/**
	 * Sets the name of the default module
	 */
	public function setDefaultModule(string! moduleName) -> <RouterInterface>
	{
		let this->_defaultModule = moduleName;
		return this;
	}

	/**
	 * Sets the default controller name
	 */
	public function setDefaultController(string! controllerName) -> <RouterInterface>
	{
		let this->_defaultController = controllerName;
		return this;
	}

	/**
	 * Sets the default action name
	 */
	public function setDefaultAction(string! actionName) -> <RouterInterface>
	{
		let this->_defaultAction = actionName;
		return this;
	}

	/**
	 * Sets an array of default paths. If a route is missing a path the router will use the defined here
	 * This method must not be used to set a 404 route
	 *
	 *<code>
	 * $router->setDefaults(array(
	 *		'module' => 'common',
	 *		'action' => 'index'
	 * ));
	 *</code>
	 */
	public function setDefaults(array! defaults) -> <RouterInterface>
	{
		var namespaceName, module, controller, action, params;

		// Set a default namespace
		if fetch namespaceName, defaults["namespace"] {
			let this->_defaultNamespace = namespaceName;
		}

		// Set a default module
		if fetch module, defaults["module"] {
			let this->_defaultModule = module;
		}

		// Set a default controller
		if fetch controller, defaults["controller"] {
			let this->_defaultController = controller;
		}

		// Set a default action
		if fetch action, defaults["action"] {
			let this->_defaultAction = action;
		}

		// Set default parameters
		if fetch params, defaults["params"] {
			let this->_defaultParams = params;
		}

		return this;
	}

	/**
	 * Returns an array of default parameters
	 */
	public function getDefaults() -> array
	{
		return [
			"namespace": this->_defaultNamespace,
			"module": this->_defaultModule,
			"controller": this->_defaultController,
			"action": this->_defaultAction,
			"params": this->_defaultParams
		];
	}

	/**
	 * Handles routing information received from the rewrite engine
	 *
	 *<code>
	 * //Read the info from the rewrite engine
	 * $router->handle();
	 *
	 * //Manually passing an URL
	 * $router->handle('/posts/edit/1');
	 *</code>
	 */
	public function handle(string uri = null)
	{
		var realUri, request, currentHostName, routeFound, parts,
			params, matches, notFoundPaths,
			vnamespace, module,  controller, action, paramsStr, strParams,
			route, methods, dependencyInjector,
			hostname, regexHostName, matched, pattern, handledUri, beforeMatch,
			paths, converters, part, position, matchPosition, converter;

		if !uri {
			/**
			 * If 'uri' isn't passed as parameter it reads _GET['_url']
			 */
			let realUri = this->getRewriteUri();
		} else {
			let realUri = uri;
		}

		/**
		 * Remove extra slashes in the route
		 */
		if this->_removeExtraSlashes && realUri != "/" {
			let handledUri = rtrim(realUri, "/");
		} else {
			let handledUri = realUri;
		}

		let request = null,
			currentHostName = null,
			routeFound = false,
			parts = [],
			params = [],
			matches = null,
			this->_wasMatched = false,
			this->_matchedRoute = null;

		/**
		 * Routes are traversed in reversed order
		 */
		for route in reverse this->_routes {

			/**
			 * Look for HTTP method constraints
			 */
			let methods = route->getHttpMethods();
			if methods !== null {

				/**
				 * Retrieve the request service from the container
				 */
				if request === null {

					let dependencyInjector = <\Phalcon\DiInterface> this->_dependencyInjector;
					if typeof dependencyInjector != "object" {
						throw new Exception("A dependency injection container is required to access the 'request' service");
					}

					let request = <RequestInterface> dependencyInjector->getShared("request");
				}

				/**
				 * Check if the current method is allowed by the route
				 */
				if request->isMethod(methods) === false {
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

					let dependencyInjector = <DiInterface> this->_dependencyInjector;
					if typeof dependencyInjector != "object" {
						throw new Exception("A dependency injection container is required to access the 'request' service");
					}

					let request = <RequestInterface> dependencyInjector->getShared("request");
				}

				/**
				 * Check if the current hostname is the same as the route
				 */
				if typeof currentHostName != "object" {
					let currentHostName = request->getHttpHost();
				}

				/**
				 * No HTTP_HOST, maybe in CLI mode?
				 */
				if typeof currentHostName == "null" {
					continue;
				}

				/**
				 * Check if the hostname restriction is the same as the current in the route
				 */
				if memstr(hostname, "(") {
					if !memstr(hostname, "#") {
						let regexHostName = "#^" . hostname . "$#";
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

				let beforeMatch = route->getBeforeMatch();
				if beforeMatch !== null {

					/**
					 * Check first if the callback is callable
					 */
					if !is_callable(beforeMatch) {
						throw new Exception("Before-Match callback is not callable in matched route");
					}

					/**
					 * Check first if the callback is callable
					 */
					let routeFound = call_user_func_array(beforeMatch, [handledUri, route, this]);
				}
			}

			if routeFound {

				/**
				 * Start from the default paths
				 */
				let paths = route->getPaths(), parts = paths;

				/**
				 * Check if the matches has variables
				 */
				if typeof matches == "array" {

					/**
					 * Get the route converters if any
					 */
					let converters = route->getConverters();

					for part, position in paths {

						if fetch matchPosition, matches[position] {

							/**
							 * Check if the part has a converter
							 */
							if typeof converters == "array" {
								if fetch converter, converters[part] {
									let parts[part] = call_user_func_array(converter, [matchPosition]);
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
									let parts[part] = call_user_func_array(converter, [position]);
								}
							}
						}
					}

					/**
					 * Update the matches generated by preg_match
					 */
					let this->_matches = matches;
				}

				let this->_matchedRoute = route;
				break;
			}
		}

		/**
		 * Update the wasMatched property indicating if the route was matched
		 */
		if routeFound {
			let this->_wasMatched = true;
		} else {
			let this->_wasMatched = false;
		}

		/**
		 * The route wasn't found, try to use the not-found paths
		 */
		if !routeFound {
			let notFoundPaths = this->_notFoundPaths;
			if notFoundPaths !== null {
				let parts = Route::getRoutePaths(notFoundPaths),
					routeFound = true;
			}
		}

		/**
		 * Use default values before we overwrite them if the route is matched
		 */
		let this->_namespace = this->_defaultNamespace,
			this->_module = this->_defaultModule,
			this->_controller = this->_defaultController,
			this->_action = this->_defaultAction,
			this->_params = this->_defaultParams;

		if routeFound {

			/**
			 * Check for a namespace
			 */
			if fetch vnamespace, parts["namespace"] {
				if !is_numeric(vnamespace) {
					let this->_namespace = vnamespace;
				}
				unset parts["namespace"];
			}

			/**
			 * Check for a module
			 */
			if fetch module, parts["module"] {
				if !is_numeric(module) {
					let this->_module = module;
				}
				unset parts["module"];
			}

			/**
			 * Check for a controller
			 */
			if fetch controller, parts["controller"] {
				if !is_numeric(controller) {
					let this->_controller = controller;
				}
				unset parts["controller"];
			}

			/**
			 * Check for an action
			 */
			if fetch action, parts["action"] {
				if !is_numeric(action) {
					let this->_action = action;
				}
				unset parts["action"];
			}

			/**
			 * Check for parameters
			 */
			if fetch paramsStr, parts["params"] {
				if typeof paramsStr == "string" {
					let strParams = trim(paramsStr, "/");

					if strParams {
						let params = explode("/", strParams);
					}
				}

				unset parts["params"];
			}

			if count(params) {
				let this->_params = array_merge(params, parts);
			} else {
				let this->_params = parts;
			}

		}
	}

	/**
	 * Adds a route to the router without any HTTP constraint
	 *
	 *<code>
	 * $router->add('/about', 'About::index');
	 *</code>
	 */
	public function add(string! pattern, var paths = null, var httpMethods = null) -> <RouteInterface>
	{
		var route;

		/**
		 * Every route is internally stored as a Phalcon\Mvc\Router\Route
		 */
		let route = new Route(pattern, paths, httpMethods),
			this->_routes[] = route;
		return route;
	}

	/**
	 * Adds a route to the router that only match if the HTTP method is GET
	 */
	public function addGet(string! pattern, var paths = null) -> <RouteInterface>
	{
		return this->add(pattern, paths, "GET");
	}

	/**
	 * Adds a route to the router that only match if the HTTP method is POST
	 */
	public function addPost(string! pattern, var paths = null) -> <RouteInterface>
	{
		return this->add(pattern, paths, "POST");
	}

	/**
	 * Adds a route to the router that only match if the HTTP method is PUT
	 */
	public function addPut(string! pattern, var paths = null) -> <RouteInterface>
	{
		return this->add(pattern, paths, "PUT");
	}

	/**
	 * Adds a route to the router that only match if the HTTP method is PATCH
	 */
	public function addPatch(string! pattern, var paths = null) -> <RouteInterface>
	{
		return this->add(pattern, paths, "PATCH");
	}

	/**
	 * Adds a route to the router that only match if the HTTP method is DELETE
	 */
	public function addDelete(string! pattern, var paths = null) -> <RouteInterface>
	{
		return this->add(pattern, paths, "DELETE");
	}

	/**
	 * Add a route to the router that only match if the HTTP method is OPTIONS
	 */
	public function addOptions(string! pattern, var paths = null) -> <RouteInterface>
	{
		return this->add(pattern, paths, "OPTIONS");
	}

	/**
	 * Adds a route to the router that only match if the HTTP method is HEAD
	 */
	public function addHead(string! pattern, var paths = null) -> <RouteInterface>
	{
		return this->add(pattern, paths, "HEAD");
	}

	/**
	 * Mounts a group of routes in the router
	 */
	public function mount(<GroupInterface> group) -> <RouterInterface>
	{
		var groupRoutes, beforeMatch, hostname, routes, route;

		let groupRoutes = group->getRoutes();
		if !count(groupRoutes) {
			throw new Exception("The group of routes does not contain any routes");
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

		let routes = this->_routes;

		if typeof routes == "array" {
			let this->_routes = array_merge(routes, groupRoutes);
		} else {
			let this->_routes = groupRoutes;
		}

		return this;
	}

	/**
	 * Set a group of paths to be returned when none of the defined routes are matched
	 */
	public function notFound(var paths) -> <RouterInterface>
	{
		if typeof paths != "array" && typeof paths != "string" {
			throw new Exception("The not-found paths must be an array or string");
		}
		let this->_notFoundPaths = paths;
		return this;
	}

	/**
	 * Removes all the pre-defined routes
	 */
	public function clear() -> void
	{
		let this->_routes = [];
	}

	/**
	 * Returns the processed namespace name
	 */
	public function getNamespaceName() -> string
	{
		return this->_namespace;
	}

	/**
	 * Returns the processed module name
	 */
	public function getModuleName() -> string
	{
		return this->_module;
	}

	/**
	 * Returns the processed controller name
	 */
	public function getControllerName() -> string
	{
		return this->_controller;
	}

	/**
	 * Returns the processed action name
	 */
	public function getActionName() -> string
	{
		return this->_action;
	}

	/**
	 * Returns the processed parameters
	 */
	public function getParams() -> array
	{
		return this->_params;
	}

	/**
	 * Returns the route that matchs the handled URI
	 */
	public function getMatchedRoute() -> <RouteInterface>
	{
		return this->_matchedRoute;
	}

	/**
	 * Returns the sub expressions in the regular expression matched
	 */
	public function getMatches() -> array
	{
		return this->_matches;
	}

	/**
	 * Checks if the router macthes any of the defined routes
	 */
	public function wasMatched() -> boolean
	{
		return this->_wasMatched;
	}

	/**
	 * Returns all the routes defined in the router
	 */
	public function getRoutes() -> <RouteInterface[]>
	{
		return this->_routes;
	}

	/**
	 * Returns a route object by its id
	 */
	public function getRouteById(var id) -> <RouteInterface> | boolean
	{
		var route;

		for route in this->_routes {
			if route->getRouteId() == id {
				return route;
			}
		}

		return false;
	}

	/**
	 * Returns a route object by its name
	 */
	public function getRouteByName(string! name) -> <RouteInterface> | boolean
	{
		var route;

		for route in this->_routes {
			if route->getName() == name {
				return route;
			}
		}
		return false;
	}

	/**
	 * Returns whether controller name should not be mangled
	 */
	public function isExactControllerName() -> boolean
	{
		return true;
	}
}
