
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
 |          Stanislav Kiryukhin <korsar.zn@gmail.com>                     |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Router;

use Phalcon\Mvc\Router\RouteInterface;

/**
 * Phalcon\Mvc\Router\GroupInterface
 *
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
interface GroupInterface
{

	/**
	 * Set a hostname restriction for all the routes in the group
	 */
	public function setHostname(string hostname) -> <GroupInterface>;

	/**
	 * Returns the hostname restriction
	 */
	public function getHostname() -> string;

	/**
	 * Set a common uri prefix for all the routes in this group
	 */
	public function setPrefix(string prefix) -> <GroupInterface>;

	/**
	 * Returns the common prefix for all the routes
	 */
	public function getPrefix() -> string;

	/**
	 * Sets a callback that is called if the route is matched.
	 * The developer can implement any arbitrary conditions here
	 * If the callback returns false the route is treated as not matched
	 */
	 public function beforeMatch(callable beforeMatch) -> <GroupInterface>;

	/**
	 * Returns the 'before match' callback if any
	 */
	public function getBeforeMatch() -> callable;

	/**
	 * Set common paths for all the routes in the group
	 *
	 * @param array paths
	 * @return Phalcon\Mvc\Router\Group
	 */
	public function setPaths(var paths) -> <GroupInterface>;

	/**
	 * Returns the common paths defined for this group
	 */
	public function getPaths() -> array | string;

	/**
	 * Returns the routes added to the group
	 */
	public function getRoutes() -> <RouteInterface[]>;

	/**
	 * Adds a route to the router on any HTTP method
	 *
	 *<code>
	 * router->add('/about', 'About::index');
	 *</code>
	 */
	public function add(string! pattern, var paths = null, var httpMethods = null) -> <RouteInterface>;

	/**
	 * Adds a route to the router that only match if the HTTP method is GET
	 */
	public function addGet(string! pattern, var paths = null) -> <RouteInterface>;

	/**
	 * Adds a route to the router that only match if the HTTP method is POST
	 */
	public function addPost(string! pattern, var paths = null) -> <RouteInterface>;

	/**
	 * Adds a route to the router that only match if the HTTP method is PUT
	 */
	public function addPut(string! pattern, var paths = null) -> <RouteInterface>;

	/**
	 * Adds a route to the router that only match if the HTTP method is PATCH
	 */
	public function addPatch(string! pattern, var paths = null) -> <RouteInterface>;

	/**
	 * Adds a route to the router that only match if the HTTP method is DELETE
	 */
	public function addDelete(string! pattern, var paths = null) -> <RouteInterface>;

	/**
	 * Add a route to the router that only match if the HTTP method is OPTIONS
	 */
	public function addOptions(string! pattern, var paths = null) -> <RouteInterface>;

	/**
	 * Adds a route to the router that only match if the HTTP method is HEAD
	 */
	public function addHead(string! pattern, var paths = null) -> <RouteInterface>;

	/**
	 * Removes all the pre-defined routes
	 */
	public function clear() -> void;
}
