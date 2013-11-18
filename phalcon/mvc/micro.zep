
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

namespace Phalcon\Mvc;

/**
 * Phalcon\Mvc\Micro
 *
 * With Phalcon you can create "Micro-Framework like" applications. By doing this, you only need to
 * write a minimal amount of code to create a PHP application. Micro applications are suitable
 * to small applications, APIs and prototypes in a practical way.
 *
 *<code>
 *
 * $app = new Phalcon\Mvc\Micro();
 *
 * $app->get('/say/welcome/{name}', function ($name) {
 *    echo "<h1>Welcome $name!</h1>";
 * });
 *
 * $app->handle();
 *
 *</code>
 */
class Micro extends Phalcon\Di\Injectable //implements ArrayAccess
{

	protected _dependencyInjector;

	protected _handlers;

	protected _router;

	protected _stopped;

	protected _notFoundHandler;

	protected _activeHandler;

	protected _beforeHandlers;

	protected _afterHandlers;

	protected _finishHandlers;

	protected _returnedValue;

	/**
	* Phalcon\Mvc\Micro constructor
	*
	* @param Phalcon\DiInterface $dependencyInjector
	*/
	public function __construct(<Phalcon\DiInterface> dependencyInjector)
	{
		this->setDi(dependencyInjector);
	}

	/**
	* Sets the DependencyInjector container
	*
	* @param Phalcon\DiInterface $dependencyInjector
	*/
	public function setDI(<Phalcon\DiInterface> dependencyInjector)
	{
		var service, exists;

		let service = "application";
		/** 
        * We automatically set ourselves as application service
        */
        let exists = dependencyInjector->has(service);
        
        if !exists {
        	dependencyInjector->set(service, this);
        }

        let this->_dependencyInjector = dependencyInjector;
	}

	/**
	* add route
	* @param string routePattern
	* @param string handler
	*/
	public function add(routePattern, handler)
	{
		var retVal, router;

		/**
        * We create a router even if there is no one in the DI
        */
        let router = this->getRouter();

        /**
        * Routes are added to the router
        */
        let retVal = [];
        let retVal[] = router->{"method"}(routePattern);
	}

	/**
	* Maps a route to a handler without any HTTP method constraint
	*
	* @param string routePattern
	* @param callable handler
	* @return Phalcon\Mvc\Router\RouteInterface
	*/
	public function map(routePattern, handler) -> <Phalcon\Mvc\Router\RouteInterface>
	{
		var router, route, routeId;
 
		/**
		 * <comment>We create a router even if there is no one in the DI</comment>
		 */
		let router = this->getRouter();
 
		/**
		 * <comment>Routes are added to the router</comment>
		 */
		let route = router->add(routePattern);
 
		/**
		 * <comment>Using the id produced by the router we store the handler</comment>
		 */
		let routeId = route->getRouteId();
		let this->_handlers[routeId] = handler;
 
		/**
		 * <comment>The route is returned, the developer can add more things on it</comment>
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
	public function get(routePattern, handler) -> <Phalcon\Mvc\Router\RouteInterface>
	{
 		var router, route, routeId;
 
		/**
		 * <comment>We create a router even if there is no one in the DI</comment>
		 */
		let router = this->getRouter();
 
		/**
		 * <comment>Routes are added to the router restricting to GET</comment>
		 */
		let route = router->addGet(routePattern);
 
		/**
		 * <comment>Using the id produced by the router we store the handler</comment>
		 */
		let routeId = route->getRouteId();
		let this->_handlers[routeId] = handler;
 
		/**
		 * <comment>The route is returned, the developer can add more things on it</comment>
		 */
		return route;
	}

	/**
	* Maps a route to a handler that only matches if the HTTP method is POST
	*
	* @param string $routePattern
	* @param callable $handler
	* @return Phalcon\Mvc\Router\RouteInterface
	*/
	public function post(routePattern, handler) -> <Phalcon\Mvc\Router\RouteInterface>
	{
 		var router, route, routeId;
 
		/**
		 * <comment>We create a router even if there is no one in the DI</comment>
		 */
		let router = this->getRouter();
 
		/**
		 * <comment>Routes are added to the router restricting to POST</comment>
		 */
		let route = router->addPost(routePattern);
 
		/**
		 * <comment>Using the id produced by the router we store the handler</comment>
		 */
		let routeId = route->getRouteId();
		let this->_handlers[routeId] = handler;
 
		/**
		 * <comment>The route is returned, the developer can add more things on it</comment>
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
	public function put(routePattern, handler) -> <Phalcon\Mvc\Router\RouteInterface>
	{
		var router, route, routeId;
 
		/**
		 * <comment>We create a router even if there is no one in the DI</comment>
		 */
		let router = this->getRouter();
 
		/**
		 * <comment>Routes are added to the router restricting to PUT</comment>
		 */
		let route = router->addPut(routePattern);
 
		/**
		 * <comment>Using the id produced by the router we store the handler</comment>
		 */
		let routeId = route->getRouteId();
		let this->_handlers[routeId] = handler;
 
		/**
		 * <comment>The route is returned, the developer can add more things on it</comment>
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
	public function patch(routePattern, handler) -> <Phalcon\Mvc\Router\RouteInterface>
	{
		var router, route, routeId;
 
		/**
		 * <comment>We create a router even if there is no one in the DI</comment>
		 */
		let router = this->getRouter();
 
		/**
		 * <comment>Routes are added to the router restricting to PATCH</comment>
		 */
		let route = router->addPatch(routePattern);
 
		/**
		 * <comment>Using the id produced by the router we store the handler</comment>
		 */
		let routeId = route->getRouteId();
		let this->_handlers[routeId] = handler;
 
		/**
		 * <comment>The route is returned, the developer can add more things on it</comment>
		 */
		return route;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is HEAD
	 *
	 * @param string $routePattern
	 * @param callable $handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function head(routePattern, handler) -> <Phalcon\Mvc\Router\RouteInterface>
	{
 		var router, route, routeId;
 
		/**
		 * <comment>We create a router even if there is no one in the DI</comment>
		 */
		let router = this->getRouter();
 
		/**
		 * <comment>Routes are added to the router restricting to HEAD</comment>
		 */
		let route = router->addHead(routePattern);
 
		/**
		 * <comment>Using the id produced by the router we store the handler</comment>
		 */
		let routeId = route->getRouteId();
		let this->_handlers[routeId] = handler;
 
		/**
		 * <comment>The route is returned, the developer can add more things on it</comment>
		 */
		return route;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is DELETE
	 *
	 * @param string $routePattern
	 * @param callable $handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function delete(routePattern, handler) -> <Phalcon\Mvc\Router\RouteInterface>
	{
		var router, route, routeId;
 
		/**
		 * <comment>We create a router even if there is no one in the DI</comment>
		 */
		let router = this->getRouter();
 
		/**
		 * <comment>Routes are added to the router restricting to DELETE</comment>
		 */
		let route = router->addDelete(routePattern);
 
		/**
		 * <comment>Using the id produced by the router we store the handler</comment>
		 */
		let routeId = route->getRouteId();
		let this->_handlers[routeId] = handler;
 
		/**
		 * <comment>The route is returned, the developer can add more things on it</comment>
		 */
		return route;
	}

	/**
	 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
	 *
	 * @param string $routePattern
	 * @param callable $handler
	 * @return Phalcon\Mvc\Router\RouteInterface
	 */
	public function options(routePattern, handler) -> <Phalcon\Mvc\Router\RouteInterface>
	{
 		var router, route, routeId;
 
		/**
		 * <comment>We create a router even if there is no one in the DI</comment>
		 */
		let router = this->getRouter();
 
		/**
		 * <comment>Routes are added to the router restricting to OPTIONS</comment>
		 */
		let route = router->addOptions(routePattern);
 
		/**
		 * <comment>Using the id produced by the router we store the handler</comment>
		 */
		let routeId = route->getRouteId();
		let this->_handlers[routeId] = handler;
 
		/**
		 * <comment>The route is returned, the developer can add more things on it</comment>
		 */
		return route;
	}

	/**
	 * Mounts a collection of handlers
	 *
	 * @param Phalcon\Mvc\Collection $collection
	 * @return Phalcon\Mvc\Micro
	 */
	public function mount(<Phalcon\Mvc\Collection> collection) -> <Phalcon\Mvc\Micro>
	{
 		var mainHandler, handlers, lazy, lazyHandler, prefix, methods, pattern,
 			subHandler, realHandler, prefixedPattern, route;
 
		if !is_object(collection) {
			throw new Phalcon\Mvc\Micro\Exception("The collection is not valid");
		}
 
		/**
		 * <comment>Get the main handler</comment>
		 */
		let mainHandler = collection->getHandler();
		if is_empty(mainHandler) {
			throw new Phalcon\Mvc\Micro\Exception("The collection requires a main handler");
		}
 
		let handlers = collection->getHandlers();
		if !count(handlers) {
			throw new Phalcon\Mvc\Micro\Exception("There are no handlers to mount");
		}
 
		if is_array(handlers) {
 
			/**
			 * <comment>Check if handler is lazy</comment>
			 */
			let lazy = collection->isLazy();
 
			if lazy {
				let lazyHandler = new Phalcon\Mvc\Micro\Exception($mainHandler);
			} else {
				let lazyHandler = mainHandler;
			}
 
			/**
			 * <comment>Get the main prefix for the collection</comment>
			 */
			let prefix = collection->getPrefix();
 
			for handler in handlers 
			{
 
				if !is_array(handler) {
					throw new Phalcon\Mvc\Micro\Exception("One of the registered handlers is invalid");
				}
 
				let methods = handler[0];
				let pattern = handler[1];
				let subHandler = handler[2];
 
				/**
				 * <comment>Create a real handler</comment>
				 */
				let realHandler = array(lazyHandler, subHandler);
 
				if !is_empty(prefix) {
					if pattern == '/' {
						let prefixedPattern = prefix;
					} else {
						let prefixedPattern = prefix.pattern;
					}
				} else {
					let prefixedPattern = pattern;
				}
 
				/**
				 * <comment>Map the route manually</comment>
				 */
				let route = this->map(prefixedPattern, realHandler);
 
				if methods {
					route->via(methods);
				}
			}
		}
 
		return this;
	}

	/**
	 * Sets a handler that will be called when the router doesn't match any of the defined routes
	 *
	 * @param callable $handler
	 * @return Phalcon\Mvc\Micro
	 */
	public function notFound(handler) -> <Phalcon\Mvc\Micro>
	{
		let this->_notFoundHandler = handler;
		return this;
	}

	/**
	 * Returns the internal router used by the application
	 *
     * @return Phalcon\Mvc\RouterInterface
	 */
	public function getRouter() -> <Phalcon\Mvc\RouterInterface>
	{
 		var router, serviceName, remove;

		let router = this->_router;
		if !is_object(router) {
 
			let serviceName = 'router';
			let router = this->getSharedService(serviceName);
 
			/**
			 * <comment>Clear the set routes if any</comment>
			 */
			router->clear();
 
			let remove = true;
 
			/**
			 * <comment>Automatically remove extra slashes</comment>
			 */
			router->removeExtraSlashes(remove);
 
			/**
			 * <comment>Update the internal router</comment>
			 */
			let this->_router = router;
		}
 
		return router;
	}

	/**
	 * Sets a service from the DI
	 *
	 * @param string $serviceName
	 * @param mixed $definition
	 * @param boolean $shared
	 * @return Phalcon\DI\ServiceInterface
	 */
	public function setService(serviceName, definition, shared=false) -> <Phalcon\DI\ServiceInterface>
	{
 		var dependencyInjector;

		let dependencyInjector = this->_dependencyInjector;
		if !is_object(dependencyInjector) {
			let dependencyInjector = new Phalcon\DI\FactoryDefault();
			let this->_dependencyInjector = dependencyInjector;
		}
 
		return dependencyInjector->set(serviceName, definition, shared);
	}

	/**
	 * Checks if a service is registered in the DI
	 *
	 * @param string $serviceName
	 * @return boolean
	 */
	public function hasService(serviceName) -> boolean
	{
 		var dependencyInjector;

		let dependencyInjector = this->_dependencyInjector;
		if !is_object(dependencyInjector) {
			let dependencyInjector = new Phalcon\DI\FactoryDefault();
			let this->_dependencyInjector = dependencyInjector;
		}
 
		return dependencyInjector->has(serviceName);
	}

	/**
	 * Obtains a service from the DI
	 *
	 * @param string $serviceName
	 * @return object
	 */
	public function getService(serviceName)
	{
 		var dependencyInjector;
 		
		let dependencyInjector = this->_dependencyInjector;
		if !is_object(dependencyInjector) {
			let dependencyInjector = new Phalcon\DI\FactoryDefault();
			let this->_dependencyInjector = dependencyInjector;
		}
 
		return dependencyInjector->get(serviceName);
	}

	/**
	 * Obtains a shared service from the DI
	 *
	 * @param string $serviceName
	 * @return mixed
	 */
	public function getSharedService(serviceName)
	{
 		var dependencyInjector;
 		
		let dependencyInjector = this->_dependencyInjector;
		if !is_object(dependencyInjector) {
			let dependencyInjector = new Phalcon\DI\FactoryDefault();
			let this->_dependencyInjector = dependencyInjector;
		}
 
		return dependencyInjector->getShared(serviceName);
	}

	/**
	 * Handle the whole request
	 *
	 * @param string $uri
	 * @return mixed
	 */
	public function handle(uri=null)
	{
 		var dependencyInjector, eventsManager, eventName, status, service, router, matchedRoute,
 			handlers, routeId, handler, beforeHandlers, isMiddleware, stopped, params, returnedValue,
 			afterHandlers, notFoundHandler, finishHandlers;
 		
		let dependencyInjector = this->_dependencyInjector;
		if !is_object(dependencyInjector) {
			throw new Phalcon\Mvc\Micro\Exception("A dependency injection container is required to access related dispatching services");
		}
 
		/**
		 * <comment>Calling beforeHandle routing</comment>
		 */
		let eventsManager = this->_eventsManager;
		if is_object(eventsManager) {
			let eventName = 'micro:beforeHandleRoute';
			let status = eventsManager->fire(eventName, this);
			if status===false {
				return false;
			}
		}
 
		/**
		 * <comment>Handling routing information</comment>
		 */
		let service = 'router';
		let router = dependencyInjector->getShared(service);
 
		/**
		 * <comment>Handle the URI as normal</comment>
		 */
		router->handle(uri);
 
		/**
		 * <comment>Check if one route was matched</comment>
		 */
		let matchedRoute = router->getMatchedRoute();
		if is_object(matchedRoute) {
 
			let handlers = this->_handlers;
 
			let routeId = matchedRoute->getRouteId();
			if !isset(handlers[routeId]) {
				throw new Phalcon\Mvc\Micro\Exception("Matched route doesn't have an associate handler");
			}
 
			/**
			 * <comment>Updating active handler</comment>
			 */
			let handler = handlers[routeId];
 
			let this->_activeHandler = handler;
 
			/**
			 * <comment>Calling beforeExecuteRoute event</comment>
			 */
			if is_object(eventsManager) {
				let eventName = 'micro:beforeExecuteRoute';
				let status = eventsManager->fire(eventName, this);
				if status===false {
					return false;
				} else {
					let handler = this->_activeHandler;
				}
			}
 
			let beforeHandlers = this->_beforeHandlers;
			if is_array(beforeHandlers) {
 
				let this->_stopped = false;
 
				/**
				 * <comment>Calls the before handlers</comment>
				 */
				for before in beforeHandlers 
				{
 
					if is_object(before) {
						let isMiddleware = before instanceof Phalcon\Mvc\Micro\MiddlewareInterface;
						if isMiddleware===true {
 
							/**
							 * <comment>Call the middleware</comment>
							 */
							let status = before->call(this);
 
							/**
							 * <comment>Reload the status</comment>
							 */
							let stopped = this->_stopped;
 
							/**
							 * <comment>break the execution if the middleware was stopped</comment>
							 */
							if stopped {
								break;
							}
 
							continue;
						}
					}
 
					if !is_callable(before) {
						throw new Phalcon\Mvc\Micro\Exception("The before handler is not callable");
					}
 
					/**
					 * <comment>Call the before handler, if it returns false exit</comment>
					 */
					let status = call_user_func(before);
					if status===false {
						return false;
					}
 
					/**
					 * <comment>Reload the 'stopped' status</comment>
					 */
					let stopped = this->_stopped;
 
					if stopped {
						return status;
					}
				}
			}
 
			/**
			 * <comment>Calling the Handler in the PHP userland</comment>
			 */
			let params = router->getParams();
			let returnedValue = call_user_func_array(handler, params);
 
			/**
			 * <comment>Update the returned value</comment>
			 */
			let this->_returnedValue = returnedValue;
 
			/**
			 * <comment>Calling afterExecuteRoute event</comment>
			 */
			if is_object(eventsManager) {
				let eventName = 'micro:afterExecuteRoute';
				eventsManager->fire(eventName, this);
			}
 
			let afterHandlers = this->_afterHandlers;
			if is_array(afterHandlers) {
 
				let this->_stopped = false;
 
				/**
				 * <comment>Calls the after handlers</comment>
				 */
				for after in afterHandlers 
				{
 
					if is_object(after) {
						let isMiddleware = after instanceof Phalcon\Mvc\Micro\MiddlewareInterface;
						if isMiddleware===true {
 
							/**
							 * <comment>Call the middleware</comment>
							 */
							let status = after->call(this);
 
							/**
							 * <comment>Reload the status</comment>
							 */
							let stopped = this->_stopped;
 
							/**
							 * <comment>break the execution if the middleware was stopped</comment>
							 */
							if stopped {
								break;
							}
 
							continue;
						}
					}
 
					if !is_callable(after) {
						throw new Phalcon\Mvc\Micro\Exception("One of the 'after' handlers is not callable");
					}
 
					let status = call_user_func(after);
				}
			}
 
		} else {
 
			/**
			 * <comment>Calling beforeNotFound event</comment>
			 */
			let eventsManager = this->_eventsManager;
			if is_object(eventsManager) {
				let eventName = 'micro:beforeNotFound';
				let status = eventsManager->fire(eventName, this);
				if $status===false {
					return false;
				}
			}
 
			/**
			 * <comment>Check if a notfoundhandler is defined and it's callable</comment>
			 */
			let notFoundHandler = this->_notFoundHandler;
			if !is_callable(notFoundHandler) {
				throw new Phalcon\Mvc\Micro\Exception("The Not-Found handler is not callable or is not defined");
			}
 
			/**
			 * <comment>Call the Not-Found handler</comment>
			 */
			let returnedValue = call_user_func(notFoundHandler);
 
			/**
			 * <comment>Update the returned value</comment>
			 */
			let this->_returnedValue = returnedValue;
 
			return returnedValue;
		}
 
		/**
		 * <comment>Calling afterHandleRoute event</comment>
		 */
		if is_object(eventsManager) {
			let eventName = 'micro:afterHandleRoute';
			eventsManager->fire(eventName, this);
		}
 
		let finishHandlers = this->_finishHandlers;
		if is_array(finishHandlers) {
 
			let this->_stopped = false;
 
			let params = null;
 
			/**
			 * <comment>Calls the finish handlers</comment>
			 */
			for finish in finishHandlers 
			{
 
				/**
				 * <comment>Try to execute middleware as plugins</comment>
				 */
				if is_object(finish) {
					let isMiddleware = finish instanceof Phalcon\Mvc\Micro\MiddlewareInterface;
					if isMiddleware===true {
 
						/**
						 * <comment>Call the middleware</comment>
						 */
						let status = finish->call(this);
 
						/**
						 * <comment>Reload the status</comment>
						 */
						let stopped = this->_stopped;
 
						/**
						 * <comment>break the execution if the middleware was stopped</comment>
						 */
						if stopped {
							break;
						}
 
						continue;
					}
				}
 
				if !is_callable(finish) {
					throw new Phalcon\Mvc\Micro\Exception("One of finish handlers is not callable");
				}
 
				if params===null {
					let params = array(this);
				}
 
				/**
				 * <comment>Call the 'finish' middleware</comment>
				 */
				let status = call_user_func_array(finish, params);
 
				/**
				 * <comment>Reload the status</comment>
				 */
				let stopped = this->_stopped;
 
				/**
				 * <comment>break the execution if the middleware was stopped</comment>
				 */
				if stopped {
					break;
				}
			}
		}
 
		/**
		 * <comment>Check if the returned object is already a response</comment>
		 */
		if is_object(returnedValue) {
			let returnedResponse = returnedValue instanceof Phalcon\Http\ResponseInterface;
			if returnedResponse===true {
				/**
				 * <comment>Automatically send the responses</comment>
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
	 * @param callable $activeHandler
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
	 * @param string $alias
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
	 *	$app['request'] = new Phalcon\Http\Request();
	 *</code>
	 *
	 * @param string $alias
	 * @param mixed $definition
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
	 * @param string $alias
	 * @return mixed
	 */
	public function offsetGet(alias)
	{
		return this->getService(alias);
	}

	/**
	 * Removes a service from the internal services container using the array syntax
	 *
	 * @param string $alias
	 */
	public function offsetUnset(alias)
	{
		return alias;
	}

	/**
	 * Appends a before middleware to be called before execute the route
	 *
	 * @param callable $handler
	 * @return Phalcon\Mvc\Micro
	 */
	public function before(handler) -> <Phalcon\Mvc\Micro>
	{
		let this->_beforeHandlers[] = handler;
		return this;
	}

	/**
	 * Appends an 'after' middleware to be called after execute the route
	 *
	 * @param callable $handler
	 * @return Phalcon\Mvc\Micro
	 */
	public function after(handler) -> <Phalcon\Mvc\Micro>
	{
		let this->_afterHandlers[] = handler;
		return this;
	}

	/**
	 * Appends a 'finish' middleware to be called when the request is finished
	 *
	 * @param callable $handler
	 * @return Phalcon\Mvc\Micro
	 */
	public function finish(handler) -> <Phalcon\Mvc\Micro>
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
