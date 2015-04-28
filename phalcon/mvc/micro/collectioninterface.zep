
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

namespace Phalcon\Mvc\Micro;

/**
 * Phalcon\Mvc\Micro\CollectionInterface
 *
 * Interface for Phalcon\Mvc\Micro\Collection
 */
interface CollectionInterface
{

	/**
	 * Sets a prefix for all routes added to the collection
	 */
	public function setPrefix(string! prefix) -> <CollectionInterface>;

	/**
	 * Returns the collection prefix if any
	 */
	public function getPrefix() -> string;

	/**
	 * Returns the registered handlers
	 *
	 * @return array
	 */
	public function getHandlers();

	/**
	 * Sets the main handler
	 *
	 * @param mixed handler
	 * @param boolean lazy
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function setHandler(handler, boolean lazy = false);

	/**
	 * Sets if the main handler must be lazy loaded
	 */
	public function setLazy(boolean! lazy) -> <CollectionInterface>;

	/**
	 * Returns if the main handler must be lazy loaded
	 */
	public function isLazy() -> boolean;

	/**
	 * Returns the main handler
	 *
	 * @return mixed
	 */
	public function getHandler();

	/**
	 * Maps a route to a handler
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function map(string! routePattern, handler, name = null);

	/**
	 * Maps a route to a handler that only matches if the HTTP method is GET
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function get(string! routePattern, handler, name = null);

	/**
	 * Maps a route to a handler that only matches if the HTTP method is POST
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function post(string! routePattern, handler, name = null);

	/**
	 * Maps a route to a handler that only matches if the HTTP method is PUT
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function put(string! routePattern, handler, name = null);

	/**
	 * Maps a route to a handler that only matches if the HTTP method is PATCH
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function patch(string! routePattern, handler, name = null);

	/**
	 * Maps a route to a handler that only matches if the HTTP method is HEAD
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function head(string! routePattern, handler, name = null);

	/**
	 * Maps a route to a handler that only matches if the HTTP method is DELETE
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function delete(string! routePattern, handler, name = null);

	/**
	 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function options(string! routePattern, handler, name = null);

}