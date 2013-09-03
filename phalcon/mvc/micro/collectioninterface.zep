
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
	 *
	 * @param string prefix
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function setPrefix(prefix);

	/**
	 * Returns the collection prefix if any
	 *
	 * @return string
	 */
	public function getPrefix();

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
	public function setHandler(handler, lazy=false);

	/**
	 * Sets if the main handler must be lazy loaded
	 *
	 * @param boolean lazy
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function setLazy(lazy);

	/**
	 * Returns if the main handler must be lazy loaded
	 *
	 * @return boolean
	 */
	public function isLazy();

	/**
	 * Returns the main handler
	 *
	 * @return mixed
	 */
	public function getHandler();

	/**
	 * Maps a route to a handler
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function map(routePattern, handler);

	/**
	 * Maps a route to a handler that only matches if the HTTP method is GET
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function get(routePattern, handler);

	/**
	 * Maps a route to a handler that only matches if the HTTP method is POST
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function post(routePattern, handler);

	/**
	 * Maps a route to a handler that only matches if the HTTP method is PUT
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function put(routePattern, handler);

	/**
	 * Maps a route to a handler that only matches if the HTTP method is PATCH
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function patch(routePattern, handler);

	/**
	 * Maps a route to a handler that only matches if the HTTP method is HEAD
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function head(routePattern, handler);

	/**
	 * Maps a route to a handler that only matches if the HTTP method is DELETE
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function delete(routePattern, handler);

	/**
	 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function options(routePattern, handler);

}