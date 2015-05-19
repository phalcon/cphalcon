
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

namespace Phalcon\Mvc\Router;

/**
 * Phalcon\Mvc\Router\Group
 *
 * Helper class to create a group of routes with common attributes
 *
 *<code>
 * $router = new \Phalcon\Mvc\Router();
 *
 * //Create a group with a common module and controller
 * $blog = new Group(array(
 * 	'module' => 'blog',
 * 	'controller' => 'index'
 * ));
 *
 * //All the routes start with /blog
 * $blog->setPrefix('/blog');
 *
 * //Add a route to the group
 * $blog->add('/save', array(
 * 	'action' => 'save'
 * ));
 *
 * //Add another route to the group
 * $blog->add('/edit/{id}', array(
 * 	'action' => 'edit'
 * ));
 *
 * //This route maps to a controller different than the default
 * $blog->add('/blog', array(
 * 	'controller' => 'about',
 * 	'action' => 'index'
 * ));
 *
 * //Add the group to the router
 * $router->mount($blog);
 *</code>
 *
 */
class Group implements GroupInterface
{

	protected _prefix;

	protected _hostname;

	protected _paths;

	protected _routes;

	protected _beforeMatch;

	/**
	 * Phalcon\Mvc\Router\Group constructor
	 */
	public function __construct(var paths = null)
	{
		if typeof paths == "array" {
			let this->_paths = paths;
		} else {
			if typeof paths == "string" {
				let this->_paths = paths;
			}
		}

		if method_exists(this, "initialize") {
			this->{"initialize"}(paths);
		}
	}

	/**
	 * Set a hostname restriction for all the routes in the group
	 */
	public function setHostname(string hostname) -> <GroupInterface>
	{
		let this->_hostname = hostname;
		return this;
	}

	/**
	 * Returns the hostname restriction
	 */
	public function getHostname() -> string
	{
		return this->_hostname;
	}

	/**
	 * Set a common uri prefix for all the routes in this group
	 */
	public function setPrefix(string prefix) -> <GroupInterface>
	{
		let this->_prefix = prefix;
		return this;
	}

	/**
	 * Returns the common prefix for all the routes
	 */
	public function getPrefix() -> string
	{
		return this->_prefix;
	}

	/**
	 * Sets a callback that is called if the route is matched.
	 * The developer can implement any arbitrary conditions here
	 * If the callback returns false the route is treated as not matched
	 */
	 public function beforeMatch(callable beforeMatch) -> <GroupInterface>
	{
		let this->_beforeMatch = beforeMatch;
		return this;
	}

	/**
	 * Returns the 'before match' callback if any
	 */
	public function getBeforeMatch() -> callable
	{
		return this->_beforeMatch;
	}

	/**
	 * Set common paths for all the routes in the group
	 */
	public function setPaths(var paths) -> <GroupInterface>
	{
		let this->_paths = paths;
		return this;
	}

	/**
	 * Returns the common paths defined for this group
	 */
	public function getPaths() -> array | string
	{
		return this->_paths;
	}

	/**
	 * Returns the routes added to the group
	 */
	public function getRoutes() -> <RouteInterface[]>
	{
		return this->_routes;
	}

	/**
	 * Adds a route to the router on any HTTP method
	 *
	 *<code>
	 * router->add('/about', 'About::index');
	 *</code>
	 */
	public function add(string! pattern, var paths = null, var httpMethods = null) -> <RouteInterface>
	{
		return this->_addRoute(pattern, paths, httpMethods);
	}

	/**
	 * Adds a route to the router that only match if the HTTP method is GET
	 *
	 * @param string pattern
	 * @param string/array paths
	 * @return Phalcon\Mvc\Router\Route
	 */
	public function addGet(string! pattern, var paths = null) -> <RouteInterface>
	{
		return this->_addRoute(pattern, paths, "GET");
	}

	/**
	 * Adds a route to the router that only match if the HTTP method is POST
	 *
	 * @param string pattern
	 * @param string/array paths
	 * @return Phalcon\Mvc\Router\Route
	 */
	public function addPost(string! pattern, var paths = null) -> <RouteInterface>
	{
		return this->_addRoute(pattern, paths, "POST");
	}

	/**
	 * Adds a route to the router that only match if the HTTP method is PUT
	 *
	 * @param string pattern
	 * @param string/array paths
	 * @return Phalcon\Mvc\Router\Route
	 */
	public function addPut(string! pattern, var paths = null) -> <RouteInterface>
	{
		return this->_addRoute(pattern, paths, "PUT");
	}

	/**
	 * Adds a route to the router that only match if the HTTP method is PATCH
	 *
	 * @param string pattern
	 * @param string/array paths
	 * @return Phalcon\Mvc\Router\Route
	 */
	public function addPatch(string! pattern, var paths = null) -> <RouteInterface>
	{
		return this->_addRoute(pattern, paths, "PATCH");
	}

	/**
	 * Adds a route to the router that only match if the HTTP method is DELETE
	 *
	 * @param string pattern
	 * @param string/array paths
	 * @return Phalcon\Mvc\Router\Route
	 */
	public function addDelete(string! pattern, var paths = null) -> <RouteInterface>
	{
		return this->_addRoute(pattern, paths, "DELETE");
	}

	/**
	 * Add a route to the router that only match if the HTTP method is OPTIONS
	 *
	 * @param string pattern
	 * @param string/array paths
	 * @return Phalcon\Mvc\Router\Route
	 */
	public function addOptions(string! pattern, var paths = null) -> <RouteInterface>
	{
		return this->_addRoute(pattern, paths, "OPTIONS");
	}

	/**
	 * Adds a route to the router that only match if the HTTP method is HEAD
	 *
	 * @param string pattern
	 * @param string/array paths
	 * @return Phalcon\Mvc\Router\Route
	 */
	public function addHead(string! pattern, var paths = null) -> <RouteInterface>
	{
		return this->_addRoute(pattern, paths, "HEAD");
	}

	/**
	 * Removes all the pre-defined routes
	 */
	public function clear() -> void
	{
		let this->_routes = [];
	}

	/**
	 * Adds a route applying the common attributes
	 */
	protected function _addRoute(string! pattern, var paths = null, var httpMethods = null) -> <RouteInterface>
	{
		var mergedPaths, route, defaultPaths;

		/**
		 * Check if the paths need to be merged with current paths
		 */
		let defaultPaths = this->_paths;
		if typeof defaultPaths == "array" {
			if typeof paths == "array" {
				/**
				 * Merge the paths with the default paths
				 */
				let mergedPaths = array_merge(defaultPaths, paths);
			} else {
				let mergedPaths = defaultPaths;
			}
		} else {
			let mergedPaths = paths;
		}

		/**
		 * Every route is internally stored as a Phalcon\Mvc\Router\Route
		 */
		let route = new Route(this->_prefix . pattern, mergedPaths, httpMethods),
			this->_routes[] = route;
		route->setGroup(this);
		return route;
	}
}
