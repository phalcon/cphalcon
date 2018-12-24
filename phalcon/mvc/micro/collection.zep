
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
 * Phalcon\Mvc\Micro\Collection
 *
 * Groups Micro-Mvc handlers as controllers
 *
 *<code>
 * $app = new \Phalcon\Mvc\Micro();
 *
 * $collection = new Collection();
 *
 * $collection->setHandler(
 *     new PostsController()
 * );
 *
 * $collection->get("/posts/edit/{id}", "edit");
 *
 * $app->mount($collection);
 *</code>
 */
class Collection implements CollectionInterface
{

	protected _prefix;

	protected _lazy;

	protected _handler;

	protected _handlers;

	/**
	 * Internal function to add a handler to the group.
	 *
	 * @param string|array method
	 * @param callable|string handler
	 */
	protected function _addMap(var method, string! routePattern, var handler, string name)
	{
		let this->_handlers[] = [method, routePattern, handler, name];
	}

	/**
	 * Sets a prefix for all routes added to the collection
	 */
	public function setPrefix(string! prefix) -> <CollectionInterface>
	{
		let this->_prefix = prefix;
		return this;
	}

	/**
	 * Returns the collection prefix if any
	 */
	public function getPrefix() -> string
	{
		return this->_prefix;
	}

	/**
	 * Returns the registered handlers
	 */
	public function getHandlers() -> array
	{
		return this->_handlers;
	}

	/**
	 * Sets the main handler.
	 *
	 * @param callable|string handler
	 */
	public function setHandler(var handler, bool lazy = false) -> <CollectionInterface>
	{
		let this->_handler = handler, this->_lazy = lazy;
		return this;
	}

	/**
	 * Sets if the main handler must be lazy loaded
	 */
	public function setLazy(bool! lazy) -> <CollectionInterface>
	{
		let this->_lazy = lazy;
		return this;
	}

	/**
	 * Returns if the main handler must be lazy loaded
	 */
	public function isLazy() -> bool
	{
		return this->_lazy;
	}

	/**
	 * Returns the main handler
	 */
	public function getHandler() -> var
	{
		return this->_handler;
	}

	/**
	 * Maps a route to a handler.
	 *
	 * @param callable|string handler
	 */
	public function map(string! routePattern, var handler, string name = null) -> <CollectionInterface>
	{
		this->_addMap(null, routePattern, handler, name);
		return this;
	}

	/**
	 * Maps a route to a handler via methods.
	 *
	 * <code>
	 * $collection->mapVia("/test", "indexAction", ["POST", "GET"], "test");
	 * </code>
	 *
	 * @param callable handler
	 * @param string|array method
	 */
	public function mapVia(string! routePattern, var handler, var method, string name = null) -> <CollectionInterface>
	{
		this->_addMap(method, routePattern, handler, name);

		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is GET.
	 *
	 * @param callable|string handler
	 */
	public function get(string! routePattern, var handler, string name = null) -> <CollectionInterface>
	{
		this->_addMap("GET", routePattern, handler, name);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is POST.
	 *
	 * @param callable|string handler
	 */
	public function post(string! routePattern, var handler, string name = null) -> <CollectionInterface>
	{
		this->_addMap("POST", routePattern, handler, name);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is PUT.
	 *
	 * @param callable|string handler
	 */
	public function put(string! routePattern, var handler, string name = null) -> <CollectionInterface>
	{
		this->_addMap("PUT", routePattern, handler, name);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is PATCH.
	 *
	 * @param callable|string handler
	 */
	public function patch(string! routePattern, var handler, string name = null) -> <CollectionInterface>
	{
		this->_addMap("PATCH", routePattern, handler, name);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is HEAD.
	 *
	 * @param callable|string handler
	 */
	public function head(string! routePattern, var handler, string name = null) -> <CollectionInterface>
	{
		this->_addMap("HEAD", routePattern, handler, name);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is DELETE.
	 *
	 * @param callable|string handler
	 */
	public function delete(string! routePattern, var handler, string name = null) -> <CollectionInterface>
	{
		this->_addMap("DELETE", routePattern, handler, name);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is OPTIONS.
	 *
	 * @param callable|string handler
	 */
	public function options(string! routePattern, var handler, string name = null) -> <CollectionInterface>
	{
		this->_addMap("OPTIONS", routePattern, handler, name);
		return this;
	}
}
