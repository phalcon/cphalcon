
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
 |          Rack Lin <racklin@gmail.com>                                  |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Cli;

use Phalcon\DiInterface;
use Phalcon\Cli\Router\Route;
use Phalcon\CLi\Router\Exception;

/**
 * Phalcon\Cli\Router
 *
 * <p>Phalcon\Cli\Router is the standard framework router. Routing is the
 * process of taking a command-line arguments and
 * decomposing it into parameters to determine which module, task, and
 * action of that task should receive the request</p>
 *
 *<code>
 *	$router = new \Phalcon\Cli\Router();
 *	$router->handle(array(
 *		'module' => 'main',
 *		'task' => 'videos',
 *		'action' => 'process'
 *	));
 *	echo $router->getTaskName();
 *</code>
 *
 */
class Router implements \Phalcon\Di\InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _module;

	protected _task;

	protected _action;

	protected _params;

	protected _defaultModule = null;

	protected _defaultTask = null;

	protected _defaultAction = null;

	protected _defaultParams;

	protected _routes;

	protected _matchedRoute;

	protected _matches;

	protected _wasMatched = false;

	/**
	 * Phalcon\Cli\Router constructor
	 */
	public function __construct(boolean defaultRoutes = true)
	{
		var routes;

		let routes = [];
		if defaultRoutes === true {

			// Two routes are added by default to match
			// /:task/:action and /:task/:action/:params

			let routes[] = new Route("#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+)[:delimiter]{0,1}$#", [
				"task": 1
			]);

			let routes[] = new Route("#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+):delimiter([a-zA-Z0-9\\.\\_]+)(:delimiter.*)*$#", [
				"task": 1,
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
	public function setDI(<DiInterface> dependencyInjector)
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
	 * Sets the name of the default module
	 */
	public function setDefaultModule(string moduleName)
	{
		let this->_defaultModule = moduleName;
	}

	/**
	 * Sets the default controller name
	 */
	public function setDefaultTask(string taskName)
	{
		let this->_defaultTask = taskName;
	}

	/**
	 * Sets the default action name
	 */
	public function setDefaultAction(string actionName)
	{
		let this->_defaultAction = actionName;
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
	public function setDefaults(array! defaults) -> <Router>
	{
		var module, task, action, params;

		// Set a default module
		if fetch module, defaults["module"] {
			let this->_defaultModule = module;
		}

		// Set a default task
		if fetch task, defaults["task"] {
			let this->_defaultTask = task;
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
	 * Handles routing information received from command-line arguments
	 *
	 * @param array arguments
	 */
	public function handle(arguments = null)
	{
		var moduleName, taskName, actionName,
			params, route, parts, pattern, routeFound, matches, paths,
			beforeMatch, converters, converter, part, position, matchPosition,
			strParams;

		let routeFound = false,
			parts = [],
			params = [],
			matches = null,
			this->_wasMatched = false,
			this->_matchedRoute = null;

		if typeof arguments != "array" {

			if typeof arguments != "string" && typeof arguments != "null" {
				throw new Exception("Arguments must be an array or string");
			}

			for route in reverse this->_routes {

				/**
				 * If the route has parentheses use preg_match
				 */
				let pattern = route->getCompiledPattern();

				if memstr(pattern, "^") {
					let routeFound = preg_match(pattern, arguments, matches);
				} else {
					let routeFound = pattern == arguments;
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
						let routeFound = call_user_func_array(beforeMatch, [arguments, route, this]);
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

				/**
				 * The route wasn't found, try to use the not-found paths
				 */
				let this->_module = this->_defaultModule,
					this->_task = this->_defaultTask,
					this->_action = this->_defaultAction,
					this->_params = this->_defaultParams;
				return this;
			}
		} else {
			let parts = arguments;
		}

		let moduleName = null,
			taskName = null,
			actionName = null;

		/**
		 * Check for a module
		 */
		if fetch moduleName, parts["module"] {
			unset parts["module"];
		} else {
			let moduleName = this->_defaultModule;
		}

		/**
		 * Check for a task
		 */
		if fetch taskName, parts["task"] {
			unset parts["task"];
		} else {
			let taskName = this->_defaultTask;
		}

		/**
		 * Check for an action
		 */
		if fetch actionName, parts["action"] {
			unset parts["action"];
		} else {
			let actionName = this->_defaultAction;
		}

		/**
		 * Check for an parameters
		 */
		if routeFound {
			if fetch params, parts["params"] {
				if typeof params != "array" {
					let strParams = substr((string)params, 1);
					if strParams {
						let params = explode(Route::getDelimiter(), strParams);
					} else {
						let params = [];
					}
				}
				unset parts["params"];
			}
			if count(params) {
				let params = array_merge(params, parts);
			} else {
				let params = parts;
			}
		} else {
			let params = parts;
		}

		let this->_module = moduleName,
			this->_task = taskName,
			this->_action = actionName,
			this->_params = params;
	}

	/**
	 * Adds a route to the router
	 *
	 *<code>
	 * $router->add('/about', 'About::main');
	 *</code>
	 *
	 * @param string pattern
	 * @param string/array paths
	 * @return Phalcon\Cli\Router\Route
	 */
	public function add(string! pattern, paths = null) -> <Route>
	{
		var route;

		let route = new Route(pattern, paths),
			this->_routes[] = route;
		return route;
	}

	/**
	 * Returns proccesed module name
	 */
	public function getModuleName() -> string
	{
		return this->_module;
	}

	/**
	 * Returns proccesed task name
	 */
	public function getTaskName() -> string
	{
		return this->_task;
	}

	/**
	 * Returns proccesed action name
	 */
	public function getActionName() -> string
	{
		return this->_action;
	}

	/**
	 * Returns proccesed extra params
	 *
	 * @return array
	 */
	public function getParams()
	{
		return this->_params;
	}

	/**
	 * Returns the route that matchs the handled URI
	 */
	public function getMatchedRoute() -> <Route>
	{
		return this->_matchedRoute;
	}

	/**
	 * Returns the sub expressions in the regular expression matched
	 *
	 * @return array
	 */
	public function getMatches()
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
	public function getRoutes() -> <Route[]>
	{
		return this->_routes;
	}

	/**
	 * Returns a route object by its id
	 *
	 * @param int id
	 * @return Phalcon\Cli\Router\Route
	 */
	public function getRouteById(var id) -> <Route> | boolean
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
	public function getRouteByName(string! name) -> <Route> | boolean
	{
		var route;

		for route in this->_routes {
			if route->getName() == name {
				return route;
			}
		}
		return false;
	}
}
