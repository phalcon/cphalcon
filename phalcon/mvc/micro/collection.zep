
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
 * Phalcon\Mvc\Micro\Collection
 *
 * Groups Micro-Mvc handlers as controllers
 *
 *<code>
 *
 * $app = new Phalcon\Mvc\Micro();
 *
 * $collection = new Phalcon\Mvc\Micro\Collection();
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
class Collection implements Phalcon\Mvc\Micro\CollectionInterface
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
	 */
	protected function _addMap(string! method, routePattern, handler)
	{
		let this->_handlers[] = [method, routePattern, handler];
	}

	/**
	 * Sets a prefix for all routes added to the collection
	 *
	 * @param string prefix
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function setPrefix(string! prefix) -> <Phalcon\Mvc\Micro\Collection>
	{
		let this->_prefix = prefix;
		return this;
	}

	/**
	 * Returns the collection prefix if any
	 *
	 * @return string
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
	public function setHandler(var handler, boolean lazy=false) -> <Phalcon\Mvc\Micro\Collection>
	{
		let this->_handler = handler, this->_lazy = lazy;
		return this;
	}

	/**
	 * Sets if the main handler must be lazy loaded
	 *
	 * @param boolean lazy
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function setLazy(lazy) -> <Phalcon\Mvc\Micro\Collection>
	{
		let this->_lazy = lazy;
		return this;
	}

	/**
	 * Returns if the main handler must be lazy loaded
	 *
	 * @return boolean
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
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function map(string! routePattern, var handler) -> <Phalcon\Mvc\Micro\Collection>
	{
		return this->_addMap(null, routePattern, handler);
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is GET
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function get(string! routePattern, handler) -> <Phalcon\Mvc\Micro\Collection>
	{
		this->_addMap("GET", routePattern, handler);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is POST
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function post(string! routePattern, handler) -> <Phalcon\Mvc\Micro\Collection>
	{
		this->_addMap("POST", routePattern, handler);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is PUT
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function put(string! routePattern, var handler) -> <Phalcon\Mvc\Micro\Collection>
	{
		this->_addMap("PUT", routePattern, handler);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is PATCH
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function patch(string! routePattern, var handler) -> <Phalcon\Mvc\Micro\Collection>
	{
		this->_addMap("PATCH", routePattern, handler);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is HEAD
	 *
	 * @param  string routePattern
	 * @param  callable handler
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function head(string! routePattern, var handler) -> <Phalcon\Mvc\Micro\Collection>
	{
		this->_addMap("HEAD", routePattern, handler);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is DELETE
	 *
	 * @param string   routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function delete(string! routePattern, var handler) -> <Phalcon\Mvc\Micro\Collection>
	{
		this->_addMap("DELETE", routePattern, handler);
		return this;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Micro\Collection
	 */
	public function options(string! routePattern, handler) -> <Phalcon\Mvc\Micro\Collection>
	{
		this->_addMap("OPTIONS", routePattern, handler);
		return this;
	}

}