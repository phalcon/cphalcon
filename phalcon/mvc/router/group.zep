
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * $router = new Phalcon\Mvc\Router();
 *
 * //Create a group with a common module and controller
 * $blog = new Phalcon\Mvc\Router\Group(array(
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
class Group
{

	protected _prefix;

	protected _hostname;

	protected _paths;

	protected _routes;

	protected _beforeMatch;

	/**
	 * Phalcon\Mvc\Router\Group constructor
	 *
	 * @param array paths
	 */
	public function __construct(paths=null)
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
	 *
	 * @param string hostname
	 * @return Phalcon\Mvc\Router\Group
	 */
	public function setHostname(string hostname) -> <Phalcon\Mvc\Router\Group>
	{
		let this->_hostname = hostname;
		return this;
	}

	/**
	 * Returns the hostname restriction
	 *
	 * @return string
	 */
	public function getHostname() -> string
	{
		return this->_hostname;
	}

	/**
	 * Set a common uri prefix for all the routes in this group
	 *
	 * @param string prefix
	 * @return Phalcon\Mvc\Router\Group
	 */
	public function setPrefix(string prefix) -> <Phalcon\Mvc\Router\Group>
	{
		let this->_prefix = prefix;
		return this;
	}

	/**
	 * Returns the common prefix for all the routes
	 *
	 * @return string
	 */
	public function getPrefix() -> string
	{
		return this->_prefix;
	}

	/**
	 * Set a before-match condition for the whole group
	 *
	 * @param callable beforeMatch
	 * @return Phalcon\Mvc\Router\Group
	 */
	public function beforeMatch(beforeMatch) -> <Phalcon\Mvc\Router\Group>
	{
		let this->_beforeMatch = beforeMatch;
		return this;
	}

	/**
	 * Returns the before-match condition if any
	 *
	 * @return string
	 */
	public function getBeforeMatch() -> string
	{
		return this->_beforeMatch;
	}

	/**
	 * Set common paths for all the routes in the group
	 *
	 * @param array paths
	 * @return Phalcon\Mvc\Router\Group
	 */
	public function setPaths(var paths) -> <Phalcon\Mvc\Router\Group>
	{
		let this->_paths = paths;
		return this;
	}

	/**
	 * Returns the common paths defined for this group
	 *
	 * @return array|string
	 */
	public function getPaths()
	{
		return this->_paths;
	}

	/**
	 * Returns the routes added to the group
	 *
	 * @return Phalcon\Mvc\Router\Route[]
	 */
	public function getRoutes()
	{
		return this->_routes;
	}

	/**
	 * Adds a route applying the common attributes
	 *
	 * @param string patten
	 * @param array paths
	 * @param array httpMethods
	 * @return Phalcon\Mvc\Router\Route
	 */
	protected function _addRoute(string! pattern, paths=null, httpMethods=null) -> <Phalcon\Mvc\Router\Route>
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
		let route = new Phalcon\Mvc\Router\Route(this->_prefix . pattern, mergedPaths, httpMethods),
			this->_routes[] = route;
		return route;
	}

	/**
	 * Adds a route to the router on any HTTP method
	 *
	 *<code>
	 * router->add('/about', 'About::index');
	 *</code>
	 *
	 * @param string pattern
	 * @param string/array paths
	 * @param string httpMethods
	 * @return Phalcon\Mvc\Router\Route
	 */
	public function add(string! pattern, paths=null, httpMethods=null) -> <Phalcon\Mvc\Router\Route>
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
	public function addGet(string! pattern, paths=null) -> <Phalcon\Mvc\Router\Route>
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
	public function addPost(string! pattern, paths=null) -> <Phalcon\Mvc\Router\Route>
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
	public function addPut(string! pattern, paths=null) -> <Phalcon\Mvc\Router\Route>
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
	public function addPatch(string! pattern, paths=null) -> <Phalcon\Mvc\Router\Route>
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
	public function addDelete(string! pattern, paths=null) -> <Phalcon\Mvc\Router\Route>
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
	public function addOptions(string! pattern, paths=null) -> <Phalcon\Mvc\Router\Route>
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
	public function addHead(string pattern, paths=null) -> <Phalcon\Mvc\Router\Route>
	{
		return this->_addRoute(pattern, paths, "HEAD");
	}

	/**
	 * Removes all the pre-defined routes
	 */
	public function clear()
	{
		let this->_routes = [];
	}

}
