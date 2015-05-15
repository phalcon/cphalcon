
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
 * Phalcon\Mvc\Micro\Collection
 *
 * Groups Micro-Mvc handlers as controllers
 *
 *<code>
 *
 * $app = new \Phalcon\Mvc\Micro();
 *
 * $collection = new Collection();
 *
 * $collection->setHandler(new PostsController());
 *
 * $collection->get('/posts/edit/{id}', 'edit');
 *
 * $app->mount($collection);
 *
 *</code>
 *
 */
class Collection implements CollectionInterface
{

	protected _prefix;

	protected _lazy;

	protected _handler;

	protected _handlers;

	/**
	 * Internal function to add a handler to the group
	 *
	 * @param string|array method
	 * @param string routePattern
	 * @param mixed handler
	 * @param string name
	 */
	protected function _addMap(string! method, var routePattern, var handler, var name)
	{
		let this->_handlers[] = [method, routePattern, handler, name];
	}

	/**
	 * Sets a prefix for all routes added to the collection
	 */
	public function setPrefix(string! prefix) -> <Collection>
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
	 *
	 * @return array
	 */
	public function getHandlers()
	{
		return this->_handlers;
	}

	/**
	 * Sets the main handler
	 *
	 * @param mixed handler
	 * @param boolean lazy
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function setHandler(var handler, boolean lazy = false) -> <Collection>
	{
		let this->_handler = handler, this->_lazy = lazy;
		return this;
	}

	/**
	 * Sets if the main handler must be lazy loaded
	 */
	public function setLazy(boolean! lazy) -> <Collection>
	{
		let this->_lazy = lazy;
		return this;
	}

	/**
	 * Returns if the main handler must be lazy loaded
	 */
	public function isLazy() -> boolean
	{
		return this->_lazy;
	}

	/**
	 * Returns the main handler
	 *
	 * @return mixed
	 */
	public function getHandler()
	{
		return this->_handler;
	}

	/**
	 * Maps a route to a handler
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function map(string! routePattern, var handler, var name = null) -> <Collection>
	{
		this->_addMap(null, routePattern, handler, name);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is GET
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function get(string! routePattern, handler, var name = null) -> <Collection>
	{
		this->_addMap("GET", routePattern, handler, name);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is POST
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function post(string! routePattern, handler, var name = null) -> <Collection>
	{
		this->_addMap("POST", routePattern, handler, name);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is PUT
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function put(string! routePattern, var handler, var name = null) -> <Collection>
	{
		this->_addMap("PUT", routePattern, handler, name);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is PATCH
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function patch(string! routePattern, var handler, var name = null) -> <Collection>
	{
		this->_addMap("PATCH", routePattern, handler, name);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is HEAD
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function head(string! routePattern, var handler, var name = null) -> <Collection>
	{
		this->_addMap("HEAD", routePattern, handler, name);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is DELETE
	 *
	 * @param  string   routePattern
	 * @param  callable handler
	 * @param  string name
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function delete(string! routePattern, var handler, var name = null) -> <Collection>
	{
		this->_addMap("DELETE", routePattern, handler, name);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function options(string! routePattern, handler, var name = null) -> <Collection>
	{
		this->_addMap("OPTIONS", routePattern, handler, name);
		return this;
	}
}
