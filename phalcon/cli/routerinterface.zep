
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Cli;

use Phalcon\Cli\Router\RouteInterface;

/**
 * Phalcon\Cli\RouterInterface
 *
 * Interface for Phalcon\Cli\Router
 */
interface RouterInterface
{

	/**
	 * Sets the name of the default module
	 */
	public function setDefaultModule(string! moduleName) -> void;

	/**
	 * Sets the default task name
	 */
	public function setDefaultTask(string! taskName) -> void;

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
	 *
	 * @param array arguments
	 */
	public function handle(arguments = null) -> void;

	/**
	 * Adds a route to the router on any HTTP method
	 */
	public function add(string! pattern, var paths = null) -> <RouteInterface>;

	/**
	 * Returns processed module name
	 */
	public function getModuleName() -> string;

	/**
	 * Returns processed task name
	 */
	public function getTaskName() -> string;

	/**
	 * Returns processed action name
	 */
	public function getActionName() -> string;

	/**
	 * Returns processed extra params
	 */
	public function getParams() -> array;

	/**
	 * Returns the route that matches the handled URI
	 */
	public function getMatchedRoute() -> <RouteInterface>;

	/**
	 * Return the sub expressions in the regular expression matched
	 */
	public function getMatches() -> array;

	/**
	 * Check if the router matches any of the defined routes
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
