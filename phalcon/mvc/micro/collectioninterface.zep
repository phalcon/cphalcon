
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
	 */
	public function getHandlers() -> array;

	/**
	 * Sets the main handler
	 */
	public function setHandler(var handler, boolean lazy = false) -> <CollectionInterface>;

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
	 */
	public function getHandler() -> var;

	/**
	 * Maps a route to a handler
	 */
	public function map(string! routePattern, callable handler, string name = null) -> <CollectionInterface>;

	/**
	 * Maps a route to a handler that only matches if the HTTP method is GET
	 */
	public function get(string! routePattern, callable handler, string name = null) -> <CollectionInterface>;

	/**
	 * Maps a route to a handler that only matches if the HTTP method is POST
	 */
	public function post(string! routePattern, callable handler, string name = null) -> <CollectionInterface>;

	/**
	 * Maps a route to a handler that only matches if the HTTP method is PUT
	 */
	public function put(string! routePattern, callable handler, string name = null) -> <CollectionInterface>;

	/**
	 * Maps a route to a handler that only matches if the HTTP method is PATCH
	 */
	public function patch(string! routePattern, callable handler, string name = null) -> <CollectionInterface>;

	/**
	 * Maps a route to a handler that only matches if the HTTP method is HEAD
	 */
	public function head(string! routePattern, callable handler, string name = null) -> <CollectionInterface>;

	/**
	 * Maps a route to a handler that only matches if the HTTP method is DELETE
	 */
	public function delete(string! routePattern, callable handler, string name = null) -> <CollectionInterface>;

	/**
	 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
	 */
	public function options(string! routePattern, callable handler, string name = null) -> <CollectionInterface>;

}
