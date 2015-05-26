
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

use Phalcon\DiInterface;
use Phalcon\Mvc\Micro\Exception;
use Phalcon\Mvc\Router\RouteInterface;
use Phalcon\Mvc\Micro\MiddlewareInterface;
use Phalcon\Mvc\Micro\Collection;
use Phalcon\Mvc\Micro\CollectionInterface;
use Phalcon\Mvc\Micro\LazyLoader;
use Phalcon\Http\ResponseInterface;
use Phalcon\Di\ServiceInterface;
use Phalcon\Di\FactoryDefault;
use Phalcon\Di\Injectable;

/**
 * Phalcon\Mvc\Micro
 *
 * With Phalcon you can create "Micro-Framework like" applications. By doing this, you only need to
 * write a minimal amount of code to create a PHP application. Micro applications are suitable
 * to small applications, APIs and prototypes in a practical way.
 *
 *<code>
 *
 * $app = new \Phalcon\Mvc\Micro();
 *
 * $app->get('/say/welcome/{name}', function ($name) {
 *    echo "<h1>Welcome $name!</h1>";
 * });
 *
 * $app->handle();
 *
 *</code>
 */
class Micro extends Injectable implements \ArrayAccess
{

	protected _dependencyInjector;

	protected _handlers;

	protected _router;

	protected _stopped;

	protected _notFoundHandler;

	protected _errorHandler;

	protected _activeHandler;

	protected _beforeHandlers;

	protected _afterHandlers;

	protected _finishHandlers;

	protected _returnedValue;

	/**
	 * Phalcon\Mvc\Micro constructor
	 */
	public function __construct(<DiInterface> dependencyInjector = null)
	{
		if typeof dependencyInjector == "object" {
			if dependencyInjector instanceof DiInterface {
				this->setDi(dependencyInjector);
			}
		}
	}

	/**
	 * Sets the DependencyInjector container
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		/**
		 * We automatically set ourselves as application service
		 */
		if !dependencyInjector->has("application") {
			dependencyInjector->set("application", this);
		}

		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Maps a route to a handler without any HTTP method constraint
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function map(string! routePattern, handler) -> <RouteInterface>
	{
		var router, route;

		/**
		 * We create a router even if there is no one in the DI
		 */
		let router = this->getRouter();

		/**
		 * Routes are added to the router
		 */
		let route = router->add(routePattern);

		/**
		 * Using the id produced by the router we store the handler
		 */
		let this->_handlers[route->getRouteId()] = handler;

		/**
		 * The route is returned, the developer can add more things on it
		 */
		return route;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is GET
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function get(string! routePattern, handler) -> <RouteInterface>
	{
		var router, route;

		/**
		 * We create a router even if there is no one in the DI
		 */
		let router = this->getRouter();

		/**
		 * Routes are added to the router restricting to GET
		 */
		let route = router->addGet(routePattern);

		/**
		 * Using the id produced by the router we store the handler
		 */
		let this->_handlers[route->getRouteId()] = handler;

		/**
		 * The route is returned, the developer can add more things on it
		 */
		return route;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is POST
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function post(string! routePattern, handler) -> <RouteInterface>
	{
		var router, route;

		/**
		 * We create a router even if there is no one in the DI
		 */
		let router = this->getRouter();

		/**
		 * Routes are added to the router restricting to POST
		 */
		let route = router->addPost(routePattern);

		/**
		 * Using the id produced by the router we store the handler
		 */
		let this->_handlers[route->getRouteId()] = handler;

		/**
		 * The route is returned, the developer can add more things on it
		 */
		return route;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is PUT
	 *
	 * @param string $routePattern
	 * @param callable $handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function put(string! routePattern, handler) -> <RouteInterface>
	{
		var router, route;

		/**
		 * We create a router even if there is no one in the DI
		 */
		let router = this->getRouter();

		/**
		 * Routes are added to the router restricting to PUT
		 */
		let route = router->addPut(routePattern);

		/**
		 * Using the id produced by the router we store the handler
		 */
		let this->_handlers[route->getRouteId()] = handler;

		/**
		 * The route is returned, the developer can add more things on it
		 */
		return route;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is PATCH
	 *
	 * @param string $routePattern
	 * @param callable $handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function patch(string! routePattern, handler) -> <RouteInterface>
	{
		var router, route;

		/**
		 * We create a router even if there is no one in the DI
		 */
		let router = this->getRouter();

		/**
		 * Routes are added to the router restricting to PATCH
		 */
		let route = router->addPatch(routePattern);

		/**
		 * Using the id produced by the router we store the handler
		 */
		let this->_handlers[route->getRouteId()] = handler;

		/**
		 * The route is returned, the developer can add more things on it
		 */
		return route;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is HEAD
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function head(string! routePattern, handler) -> <RouteInterface>
	{
		var router, route;

		/**
		 * We create a router even if there is no one in the DI
		 */
		let router = this->getRouter();

		/**
		 * Routes are added to the router restricting to HEAD
		 */
		let route = router->addHead(routePattern);

		/**
		 * Using the id produced by the router we store the handler
		 */
		let this->_handlers[route->getRouteId()] = handler;

		/**
		 * The route is returned, the developer can add more things on it
		 */
		return route;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is DELETE
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function delete(string! routePattern, handler) -> <RouteInterface>
	{
		var router, route;

		/**
		 * We create a router even if there is no one in the DI
		 */
		let router = this->getRouter();

		/**
		 * Routes are added to the router restricting to DELETE
		 */
		let route = router->addDelete(routePattern);

		/**
		 * Using the id produced by the router we store the handler
		 */
		let this->_handlers[route->getRouteId()] = handler;

		/**
		 * The route is returned, the developer can add more things on it
		 */
		return route;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
	 *
	 * @param string routePattern
	 * @param callable handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function options(string! routePattern, handler) -> <RouteInterface>
	{
		var router, route;

		/**
		 * We create a router even if there is no one in the DI
		 */
		let router = this->getRouter();

		/**
		 * Routes are added to the router restricting to OPTIONS
		 */
		let route = router->addOptions(routePattern);

		/**
		 * Using the id produced by the router we store the handler
		 */
		let this->_handlers[route->getRouteId()] = handler;

		/**
		 * The route is returned, the developer can add more things on it
		 */
		return route;
	}

	/**
	 * Mounts a collection of handlers
	 */
	public function mount(<CollectionInterface> collection) -> <Micro>
	{
		var mainHandler, handlers, lazyHandler, prefix, methods, pattern,
			subHandler, realHandler, prefixedPattern, route, handler, name;

		/**
		 * Get the main handler
		 */
		let mainHandler = collection->getHandler();
		if empty mainHandler {
			throw new Exception("Collection requires a main handler");
		}

		let handlers = collection->getHandlers();
		if !count(handlers) {
			throw new Exception("There are no handlers to mount");
		}

		if typeof handlers == "array" {

			/**
			 * Check if handler is lazy
			 */
			if collection->isLazy() {
				let lazyHandler = new LazyLoader(mainHandler);
			} else {
				let lazyHandler = mainHandler;
			}

			/**
			 * Get the main prefix for the collection
			 */
			let prefix = collection->getPrefix();

			for handler in handlers {

				if typeof handler != "array" {
					throw new Exception("One of the registered handlers is invalid");
				}

				let methods    = handler[0];
				let pattern    = handler[1];
				let subHandler = handler[2];
				let name       = handler[3];

				/**
				 * Create a real handler
				 */
				let realHandler = [lazyHandler, subHandler];

				if !empty prefix {
					if pattern == "/" {
						let prefixedPattern = prefix;
					} else {
						let prefixedPattern = prefix . pattern;
					}
				} else {
					let prefixedPattern = pattern;
				}

				/**
				 * Map the route manually
				 */
				let route = this->map(prefixedPattern, realHandler);

				if (typeof methods == "string" && methods != "") || typeof methods == "array" {
					route->via(methods);
				}

				if typeof name == "string" {
					route->setName(name);
				}
			}
		}

		return this;
	}

	/**
	 * Sets a handler that will be called when the router doesn't match any of the defined routes
	 *
	 * @param callable handler
	 * @return Phalcon\Mvc\Micro
	 */
	public function notFound(var handler) -> <Micro>
	{
		let this->_notFoundHandler = handler;
		return this;
	}

	/**
	 * Sets a handler that will be called when an exception is thrown handling the route
	 *
	 * @param callable handler
	 * @return Phalcon\Mvc\Micro
	 */
	public function error(var handler) -> <Micro>
	{
		let this->_errorHandler = handler;
		return this;
	}

	/**
	 * Returns the internal router used by the application
	 */
	public function getRouter() -> <RouterInterface>
	{
		var router;

		let router = this->_router;
		if typeof router != "object" {

			let router = this->getSharedService("router");

			/**
			 * Clear the set routes if any
			 */
			router->clear();

			/**
			 * Automatically remove extra slashes
			 */
			router->removeExtraSlashes(true);

			/**
			 * Update the internal router
			 */
			let this->_router = router;
		}

		return router;
	}

	/**
	 * Sets a service from the DI
	 *
	 * @param string  serviceName
	 * @param mixed   definition
	 * @param boolean shared
	 * @return Phalcon\DI\ServiceInterface
	 */
	public function setService(string! serviceName, var definition, boolean shared = false) -> <ServiceInterface>
	{
		var dependencyInjector;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			let dependencyInjector = new FactoryDefault();
			let this->_dependencyInjector = dependencyInjector;
		}

		return dependencyInjector->set(serviceName, definition, shared);
	}

	/**
	 * Checks if a service is registered in the DI
	 */
	public function hasService(string! serviceName) -> boolean
	{
		var dependencyInjector;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			let dependencyInjector = new FactoryDefault();
			let this->_dependencyInjector = dependencyInjector;
		}

		return dependencyInjector->has(serviceName);
	}

	/**
	 * Obtains a service from the DI
	 *
	 * @param string serviceName
	 * @return object
	 */
	public function getService(string! serviceName)
	{
		var dependencyInjector;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			let dependencyInjector = new FactoryDefault();
			let this->_dependencyInjector = dependencyInjector;
		}

		return dependencyInjector->get(serviceName);
	}

	/**
	 * Obtains a shared service from the DI
	 *
	 * @param string serviceName
	 * @return mixed
	 */
	public function getSharedService(serviceName)
	{
		var dependencyInjector;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			let dependencyInjector = new FactoryDefault();
			let this->_dependencyInjector = dependencyInjector;
		}

		return dependencyInjector->getShared(serviceName);
	}

	/**
	 * Handle the whole request
	 *
	 * @param string uri
	 * @return mixed
	 */
	public function handle(var uri = null)
	{
		var dependencyInjector, eventsManager, status = null, router, matchedRoute,
			handler, beforeHandlers, params, returnedValue, e, errorHandler,
			afterHandlers, notFoundHandler, finishHandlers, finish, before, after;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injection container is required to access required micro services");
		}

		try {

			let returnedValue = null;

			/**
			 * Calling beforeHandle routing
			 */
			let eventsManager = this->_eventsManager;
			if typeof eventsManager == "object" {
				if eventsManager->fire("micro:beforeHandleRoute", this) === false {
					return false;
				}
			}

			/**
			 * Handling routing information
			 */
			let router = dependencyInjector->getShared("router");

			/**
			 * Handle the URI as normal
			 */
			router->handle(uri);

			/**
			 * Check if one route was matched
			 */
			let matchedRoute = router->getMatchedRoute();
			if typeof matchedRoute == "object" {

				if !fetch handler, this->_handlers[matchedRoute->getRouteId()] {
					throw new Exception("Matched route doesn't have an associated handler");
				}

				/**
				 * Updating active handler
				 */
				let this->_activeHandler = handler;

				/**
				 * Calling beforeExecuteRoute event
				 */
				if typeof eventsManager == "object" {
					if eventsManager->fire("micro:beforeExecuteRoute", this) === false {
						return false;
					} else {
						let handler = this->_activeHandler;
					}
				}

				let beforeHandlers = this->_beforeHandlers;
				if typeof beforeHandlers == "array" {

					let this->_stopped = false;

					/**
					 * Calls the before handlers
					 */
					for before in beforeHandlers {

						if typeof before == "object" {
							if before instanceof MiddlewareInterface {

								/**
								 * Call the middleware
								 */
								let status = before->call(this);

								/**
								 * Reload the status
								 * break the execution if the middleware was stopped
								 */
								if this->_stopped {
									break;
								}

								continue;
							}
						}

						if !is_callable(before) {
							throw new Exception("'before' handler is not callable");
						}

						/**
						 * Call the before handler, if it returns false exit
						 */
						if call_user_func(before) === false {
							return false;
						}

						/**
						 * Reload the 'stopped' status
						 */
						if this->_stopped {
							return status;
						}
					}
				}

				/**
				 * Calling the Handler in the PHP userland
				 */
				let params = router->getParams();
				let returnedValue = call_user_func_array(handler, params);

				/**
				 * Update the returned value
				 */
				let this->_returnedValue = returnedValue;

				/**
				 * Calling afterExecuteRoute event
				 */
				if typeof eventsManager == "object" {
					eventsManager->fire("micro:afterExecuteRoute", this);
				}

				let afterHandlers = this->_afterHandlers;
				if typeof afterHandlers == "array" {

					let this->_stopped = false;

					/**
					 * Calls the after handlers
					 */
					for after in afterHandlers {

						if typeof after == "object" {
							if after instanceof MiddlewareInterface {

								/**
								 * Call the middleware
								 */
								let status = after->call(this);

								/**
								 * break the execution if the middleware was stopped
								 */
								if this->_stopped {
									break;
								}

								continue;
							}
						}

						if !is_callable(after) {
							throw new Exception("One of the 'after' handlers is not callable");
						}

						let status = call_user_func(after);
					}
				}

			} else {

				/**
				 * Calling beforeNotFound event
				 */
				let eventsManager = this->_eventsManager;
				if typeof eventsManager == "object" {
					if eventsManager->fire("micro:beforeNotFound", this) === false {
						return false;
					}
				}

				/**
				 * Check if a notfoundhandler is defined and it's callable
				 */
				let notFoundHandler = this->_notFoundHandler;
				if !is_callable(notFoundHandler) {
					throw new Exception("Not-Found handler is not callable or is not defined");
				}

				/**
				 * Call the Not-Found handler
				 */
				let returnedValue = call_user_func(notFoundHandler);
			}

			/**
			 * Calling afterHandleRoute event
			 */
			if typeof eventsManager == "object" {
				eventsManager->fire("micro:afterHandleRoute", this, returnedValue);
			}

			let finishHandlers = this->_finishHandlers;
			if typeof finishHandlers == "array" {

				let this->_stopped = false;

				let params = null;

				/**
				 * Calls the finish handlers
				 */
				for finish in finishHandlers {

					/**
					 * Try to execute middleware as plugins
					 */
					if typeof finish == "object" {

						if finish instanceof MiddlewareInterface {

							/**
							 * Call the middleware
							 */
							let status = finish->call(this);

							/**
							 * break the execution if the middleware was stopped
							 */
							if this->_stopped {
								break;
							}

							continue;
						}
					}

					if !is_callable(finish) {
						throw new Exception("One of the 'finish' handlers is not callable");
					}

					if params === null {
						let params = [this];
					}

					/**
					 * Call the 'finish' middleware
					 */
					let status = call_user_func_array(finish, params);

					/**
					 * break the execution if the middleware was stopped
					 */
					if this->_stopped {
						break;
					}
				}
			}

		} catch \Exception, e {

			/**
			 * Calling beforeNotFound event
			 */
			let eventsManager = this->_eventsManager;
			if typeof eventsManager == "object" {
				let returnedValue = eventsManager->fire("micro:beforeException", this, e);
			}

			/**
			 * Check if an errorhandler is defined and it's callable
			 */
			let errorHandler = this->_errorHandler;
			if errorHandler {

				if !is_callable(errorHandler) {
					throw new Exception("Error handler is not callable");
				}

				/**
				 * Call the Error handler
				 */
				let returnedValue = call_user_func_array(errorHandler, [e]);
				if typeof returnedValue == "object" {
					if !(returnedValue instanceof ResponseInterface) {
						throw e;
					}
				} else {
					if returnedValue !== false {
						throw e;
					}
				}

			} else {
				if returnedValue !== false {
					throw e;
				}
			}
		}

		/**
		 * Check if the returned object is already a response
		 */
		if typeof returnedValue == "object" {
			if returnedValue instanceof ResponseInterface {
				/**
				 * Automatically send the response
				 */
				returnedValue->send();
			}
		}

		return returnedValue;
	}

	/**
	 * Stops the middleware execution avoiding than other middlewares be executed
	 */
	public function stop()
	{
		let this->_stopped = true;
	}

	/**
	 * Sets externally the handler that must be called by the matched route
	 *
	 * @param callable activeHandler
	 */
	public function setActiveHandler(activeHandler)
	{
		let this->_activeHandler = activeHandler;
	}

	/**
	 * Return the handler that will be called for the matched route
	 *
	 * @return callable
	 */
	public function getActiveHandler()
	{
		return this->_activeHandler;
	}

	/**
	 * Returns the value returned by the executed handler
	 *
	 * @return mixed
	 */
	public function getReturnedValue()
	{
		return this->_returnedValue;
	}

	/**
	 * Check if a service is registered in the internal services container using the array syntax
	 *
	 * @param string alias
	 * @return boolean
	 */
	public function offsetExists(alias) -> boolean
	{
		return this->hasService(alias);
	}

	/**
	 * Allows to register a shared service in the internal services container using the array syntax
	 *
	 *<code>
	 *	$app['request'] = new \Phalcon\Http\Request();
	 *</code>
	 *
	 * @param string alias
	 * @param mixed definition
	 */
	public function offsetSet(alias, definition)
	{
		this->setService(alias, definition);
	}

	/**
	 * Allows to obtain a shared service in the internal services container using the array syntax
	 *
	 *<code>
	 *	var_dump($di['request']);
	 *</code>
	 *
	 * @param string alias
	 * @return mixed
	 */
	public function offsetGet(alias)
	{
		return this->getService(alias);
	}

	/**
	 * Removes a service from the internal services container using the array syntax
	 *
	 * @param string alias
	 */
	public function offsetUnset(alias)
	{
		return alias;
	}

	/**
	 * Appends a before middleware to be called before execute the route
	 *
	 * @param callable handler
	 * @return Phalcon\Mvc\Micro
	 */
	public function before(handler) -> <Micro>
	{
		let this->_beforeHandlers[] = handler;
		return this;
	}

	/**
	 * Appends an 'after' middleware to be called after execute the route
	 *
	 * @param callable handler
	 * @return Phalcon\Mvc\Micro
	 */
	public function after(handler) -> <Micro>
	{
		let this->_afterHandlers[] = handler;
		return this;
	}

	/**
	 * Appends a 'finish' middleware to be called when the request is finished
	 *
	 * @param callable handler
	 * @return Phalcon\Mvc\Micro
	 */
	public function finish(handler) -> <Micro>
	{
		let this->_finishHandlers[] = handler;
		return this;
	}

	/**
	 * Returns the internal handlers attached to the application
	 *
	 * @return array
	 */
	public function getHandlers()
	{
		return this->_handlers;
	}
}
