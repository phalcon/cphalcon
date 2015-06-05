
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

use Phalcon\Mvc\Router\RouteInterface;
use Phalcon\Mvc\Router\GroupInterface;

/**
 * Phalcon\Mvc\RouterInterface
 *
 * Interface for Phalcon\Mvc\Router
 */
interface RouterInterface
{

	/**
	 * Sets the name of the default module
	 */
	public function setDefaultModule(string! moduleName) -> void;

	/**
	 * Sets the default controller name
	 */
	public function setDefaultController(string! controllerName) -> void;

	/**
	 * Sets the default action name
	 */
	public function setDefaultAction(string! actionName) -> void;

	/**
	 * Sets an array of default paths
	 */
	public function setDefaults(array! defaults) -> void;

	/**
	 * Handles routing information received from the rewrite engine
	 */
	public function handle(string uri = null) -> void;

	/**
	 * Adds a route to the router on any HTTP method
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
	public function addPatch(string! pattern, paths = null) -> <RouteInterface>;

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
	 * Mounts a group of routes in the router
	 */
	public function mount(<GroupInterface> group) -> <RouterInterface>;

	/**
	 * Removes all the defined routes
	 */
	public function clear() -> void;

	/**
	 * Returns processed module name
	 */
	public function getModuleName() -> string;

	/**
	 * Returns processed namespace name
	 */
	public function getNamespaceName() -> string;

	/**
	 * Returns processed controller name
	 */
	public function getControllerName() -> string;

	/**
	 * Returns processed action name
	 */
	public function getActionName() -> string;

	/**
	 * Returns processed extra params
	 */
	public function getParams() -> array;

	/**
	 * Returns the route that matchs the handled URI
	 */
	public function getMatchedRoute() -> <RouteInterface>;

	/**
	 * Return the sub expressions in the regular expression matched
	 */
	public function getMatches() -> array;

	/**
	 * Check if the router macthes any of the defined routes
	 */
	public function wasMatched() -> boolean;

	/**
	 * Return all the routes defined in the router
	 */
	public function getRoutes() -> <RouteInterface[]>;

	/**
	 * Returns a route object by its id
	 */
	public function getRouteById(var id) -> <RouteInterface>;

	/**
	 * Returns a route object by its name
	 */
	public function getRouteByName(string! name) -> <RouteInterface>;
}
