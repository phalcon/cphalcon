
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	public function setHandler(var handler, bool lazy = false) -> <CollectionInterface>;

	/**
	 * Sets if the main handler must be lazy loaded
	 */
	public function setLazy(bool! lazy) -> <CollectionInterface>;

	/**
	 * Returns if the main handler must be lazy loaded
	 */
	public function isLazy() -> bool;

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
