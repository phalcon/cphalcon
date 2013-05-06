
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
  |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/array.h"
#include "kernel/concat.h"

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


/**
 * Phalcon\Mvc\Micro initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Micro){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc, Micro, mvc_micro, "phalcon\\di\\injectable", phalcon_mvc_micro_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_handlers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_router"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_stopped"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_notFoundHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_activeHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_beforeHandlers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_afterHandlers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_finishHandlers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_returnedValue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_micro_ce TSRMLS_CC, 1, zend_ce_arrayaccess);

	return SUCCESS;
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Micro, setDI){

	zval *dependency_injector, *service, *exists;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &dependency_injector);
	
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "The dependency injector must be an object");
		return;
	}
	
	/** 
	 * We automatically set ourselves as application service
	 */
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "application", 1);
	
	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_1(exists, dependency_injector, "has", service);
	if (!zend_is_true(exists)) {
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(dependency_injector, "set", service, this_ptr);
	}
	
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Maps a route to a handler without any HTTP method constraint
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, map){

	zval *route_pattern, *handler, *router, *route;
	zval *route_id;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	/** 
	 * We create a router even if there is no one in the DI
	 */
	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter");
	
	/** 
	 * Routes are added to the router
	 */
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "add", route_pattern);
	
	/** 
	 * Using the id produced by the router we store the handler
	 */
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid");
	phalcon_update_property_array(this_ptr, SL("_handlers"), route_id, handler TSRMLS_CC);
	
	/** 
	 * The route is returned, the developer can add more things on it
	 */
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, get){

	zval *route_pattern, *handler, *router, *route;
	zval *route_id;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	/** 
	 * We create a router even if there is no one in the DI
	 */
	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter");
	
	/** 
	 * Routes are added to the router restricting to GET
	 */
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addget", route_pattern);
	
	/** 
	 * Using the id produced by the router we store the handler
	 */
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid");
	phalcon_update_property_array(this_ptr, SL("_handlers"), route_id, handler TSRMLS_CC);
	
	/** 
	 * The route is returned, the developer can add more things on it
	 */
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, post){

	zval *route_pattern, *handler, *router, *route;
	zval *route_id;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	/** 
	 * We create a router even if there is no one in the DI
	 */
	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter");
	
	/** 
	 * Routes are added to the router restricting to POST
	 */
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addpost", route_pattern);
	
	/** 
	 * Using the id produced by the router we store the handler
	 */
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid");
	phalcon_update_property_array(this_ptr, SL("_handlers"), route_id, handler TSRMLS_CC);
	
	/** 
	 * The route is returned, the developer can add more things on it
	 */
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, put){

	zval *route_pattern, *handler, *router, *route;
	zval *route_id;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	/** 
	 * We create a router even if there is no one in the DI
	 */
	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter");
	
	/** 
	 * Routes are added to the router restricting to PUT
	 */
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addput", route_pattern);
	
	/** 
	 * Using the id produced by the router we store the handler
	 */
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid");
	phalcon_update_property_array(this_ptr, SL("_handlers"), route_id, handler TSRMLS_CC);
	
	/** 
	 * The route is returned, the developer can add more things on it
	 */
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, patch){

	zval *route_pattern, *handler, *router, *route;
	zval *route_id;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	/** 
	 * We create a router even if there is no one in the DI
	 */
	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter");
	
	/** 
	 * Routes are added to the router restricting to PATCH
	 */
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addpatch", route_pattern);
	
	/** 
	 * Using the id produced by the router we store the handler
	 */
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid");
	phalcon_update_property_array(this_ptr, SL("_handlers"), route_id, handler TSRMLS_CC);
	
	/** 
	 * The route is returned, the developer can add more things on it
	 */
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, head){

	zval *route_pattern, *handler, *router, *route;
	zval *route_id;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	/** 
	 * We create a router even if there is no one in the DI
	 */
	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter");
	
	/** 
	 * Routes are added to the router restricting to HEAD
	 */
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addhead", route_pattern);
	
	/** 
	 * Using the id produced by the router we store the handler
	 */
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid");
	phalcon_update_property_array(this_ptr, SL("_handlers"), route_id, handler TSRMLS_CC);
	
	/** 
	 * The route is returned, the developer can add more things on it
	 */
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, delete){

	zval *route_pattern, *handler, *router, *route;
	zval *route_id;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	/** 
	 * We create a router even if there is no one in the DI
	 */
	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter");
	
	/** 
	 * Routes are added to the router restricting to DELETE
	 */
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "adddelete", route_pattern);
	
	/** 
	 * Using the id produced by the router we store the handler
	 */
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid");
	phalcon_update_property_array(this_ptr, SL("_handlers"), route_id, handler TSRMLS_CC);
	
	/** 
	 * The route is returned, the developer can add more things on it
	 */
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, options){

	zval *route_pattern, *handler, *router, *route;
	zval *route_id;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	/** 
	 * We create a router even if there is no one in the DI
	 */
	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter");
	
	/** 
	 * Routes are added to the router restricting to OPTIONS
	 */
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addoptions", route_pattern);
	
	/** 
	 * Using the id produced by the router we store the handler
	 */
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid");
	phalcon_update_property_array(this_ptr, SL("_handlers"), route_id, handler TSRMLS_CC);
	
	/** 
	 * The route is returned, the developer can add more things on it
	 */
	RETURN_CCTOR(route);
}

/**
 * Mounts a collection of handlers
 *
 * @param Phalcon\Mvc\Collection $collection
 * @return Phalcon\Mvc\Micro
 */
PHP_METHOD(Phalcon_Mvc_Micro, mount){

	zval *collection, *main_handler, *handlers, *lazy;
	zval *lazy_handler = NULL, *prefix, *handler = NULL, *methods = NULL;
	zval *pattern = NULL, *sub_handler = NULL, *real_handler = NULL, *prefixed_pattern = NULL;
	zval *route = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &collection);
	
	if (Z_TYPE_P(collection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "The collection is not valid");
		return;
	}
	
	/** 
	 * Get the main handler
	 */
	PHALCON_INIT_VAR(main_handler);
	PHALCON_CALL_METHOD(main_handler, collection, "gethandler");
	if (PHALCON_IS_EMPTY(main_handler)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "The collection requires a main handler");
		return;
	}
	
	PHALCON_INIT_VAR(handlers);
	PHALCON_CALL_METHOD(handlers, collection, "gethandlers");
	if (!phalcon_fast_count_ev(handlers TSRMLS_CC)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "There are no handlers to mount");
		return;
	}
	
	if (Z_TYPE_P(handlers) == IS_ARRAY) { 
	
		/** 
		 * Check if handler is lazy
		 */
		PHALCON_INIT_VAR(lazy);
		PHALCON_CALL_METHOD(lazy, collection, "islazy");
		if (zend_is_true(lazy)) {
			PHALCON_INIT_VAR(lazy_handler);
			object_init_ex(lazy_handler, phalcon_mvc_micro_lazyloader_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(lazy_handler, "__construct", main_handler);
	
		} else {
			PHALCON_CPY_WRT(lazy_handler, main_handler);
		}
	
		/** 
		 * Get the main prefix for the collection
		 */
		PHALCON_INIT_VAR(prefix);
		PHALCON_CALL_METHOD(prefix, collection, "getprefix");
	
		if (!phalcon_is_iterable(handlers, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(handler);
	
			if (Z_TYPE_P(handler) != IS_ARRAY) { 
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "One of the registered handlers is invalid");
				return;
			}
	
			PHALCON_OBS_NVAR(methods);
			phalcon_array_fetch_long(&methods, handler, 0, PH_NOISY_CC);
	
			PHALCON_OBS_NVAR(pattern);
			phalcon_array_fetch_long(&pattern, handler, 1, PH_NOISY_CC);
	
			PHALCON_OBS_NVAR(sub_handler);
			phalcon_array_fetch_long(&sub_handler, handler, 2, PH_NOISY_CC);
	
			/** 
			 * Create a real handler
			 */
			PHALCON_INIT_NVAR(real_handler);
			array_init_size(real_handler, 2);
			phalcon_array_append(&real_handler, lazy_handler, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&real_handler, sub_handler, PH_SEPARATE TSRMLS_CC);
			if (PHALCON_IS_NOT_EMPTY(prefix)) {
				if (PHALCON_IS_STRING(pattern, "/")) {
					PHALCON_CPY_WRT(prefixed_pattern, prefix);
				} else {
					PHALCON_INIT_NVAR(prefixed_pattern);
					PHALCON_CONCAT_VV(prefixed_pattern, prefix, pattern);
				}
			} else {
				PHALCON_CPY_WRT(prefixed_pattern, pattern);
			}
	
			/** 
			 * Map the route manually
			 */
			PHALCON_INIT_NVAR(route);
			PHALCON_CALL_METHOD_PARAMS_2(route, this_ptr, "map", prefixed_pattern, real_handler);
			if (zend_is_true(methods)) {
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(route, "via", methods);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	
	RETURN_THIS();
}

/**
 * Sets a handler that will be called when the router doesn't match any of the defined routes
 *
 * @param callable $handler
 * @return Phalcon\Mvc\Micro
 */
PHP_METHOD(Phalcon_Mvc_Micro, notFound){

	zval *handler;

	phalcon_fetch_params(0, 1, 0, &handler);
	
	phalcon_update_property_this(this_ptr, SL("_notFoundHandler"), handler TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the internal router used by the application
 *
 * @return Phalcon\Mvc\RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, getRouter){

	zval *router = NULL, *service_name, *remove;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(router);
	phalcon_read_property_this(&router, this_ptr, SL("_router"), PH_NOISY_CC);
	if (Z_TYPE_P(router) != IS_OBJECT) {
		PHALCON_INIT_VAR(service_name);
		ZVAL_STRING(service_name, "router", 1);
	
		PHALCON_INIT_NVAR(router);
		PHALCON_CALL_METHOD_PARAMS_1(router, this_ptr, "getsharedservice", service_name);
	
		/** 
		 * Clear the set routes if any
		 */
		PHALCON_CALL_METHOD_NORETURN(router, "clear");
	
		PHALCON_INIT_VAR(remove);
		ZVAL_BOOL(remove, 1);
	
		/** 
		 * Automatically remove extra slashes
		 */
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(router, "removeextraslashes", remove);
	
		/** 
		 * Update the internal router
		 */
		phalcon_update_property_this(this_ptr, SL("_router"), router TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(router);
}

/**
 * Sets a service from the DI
 *
 * @param string $serviceName
 * @param mixed $definition
 * @param boolean $shared
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, setService){

	zval *service_name, *definition, *shared = NULL, *dependency_injector = NULL;
	zval *service;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &service_name, &definition, &shared);
	
	if (!shared) {
		PHALCON_INIT_VAR(shared);
		ZVAL_BOOL(shared, 0);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_NVAR(dependency_injector);
		object_init_ex(dependency_injector, phalcon_di_factorydefault_ce);
		PHALCON_CALL_METHOD_NORETURN(dependency_injector, "__construct");
	
		phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(service);
	PHALCON_CALL_METHOD_PARAMS_3(service, dependency_injector, "set", service_name, definition, shared);
	
	RETURN_CCTOR(service);
}

/**
 * Checks if a service is registered in the DI
 *
 * @param string $serviceName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Micro, hasService){

	zval *service_name, *dependency_injector = NULL;
	zval *exists;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &service_name);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_NVAR(dependency_injector);
		object_init_ex(dependency_injector, phalcon_di_factorydefault_ce);
		PHALCON_CALL_METHOD_NORETURN(dependency_injector, "__construct");
	
		phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_1(exists, dependency_injector, "has", service_name);
	
	RETURN_CCTOR(exists);
}

/**
 * Obtains a service from the DI
 *
 * @param string $serviceName
 * @return object
 */
PHP_METHOD(Phalcon_Mvc_Micro, getService){

	zval *service_name, *dependency_injector = NULL;
	zval *service;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &service_name);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_NVAR(dependency_injector);
		object_init_ex(dependency_injector, phalcon_di_factorydefault_ce);
		PHALCON_CALL_METHOD_NORETURN(dependency_injector, "__construct");
	
		phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(service);
	PHALCON_CALL_METHOD_PARAMS_1(service, dependency_injector, "get", service_name);
	
	RETURN_CCTOR(service);
}

/**
 * Obtains a shared service from the DI
 *
 * @param string $serviceName
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, getSharedService){

	zval *service_name, *dependency_injector = NULL;
	zval *service;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &service_name);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_NVAR(dependency_injector);
		object_init_ex(dependency_injector, phalcon_di_factorydefault_ce);
		PHALCON_CALL_METHOD_NORETURN(dependency_injector, "__construct");
	
		phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(service);
	PHALCON_CALL_METHOD_PARAMS_1(service, dependency_injector, "getshared", service_name);
	
	RETURN_CCTOR(service);
}

/**
 * Handle the whole request
 *
 * @param string $uri
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, handle){

	zval *uri = NULL, *dependency_injector, *events_manager = NULL;
	zval *event_name = NULL, *status = NULL, *service, *router, *matched_route;
	zval *handlers, *route_id, *handler = NULL, *before_handlers;
	zval *before = NULL, *is_middleware = NULL, *stopped = NULL, *params = NULL;
	zval *returned_value = NULL, *after_handlers, *after = NULL;
	zval *not_found_handler, *finish_handlers;
	zval *finish = NULL;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &uri);
	
	if (!uri) {
		PHALCON_INIT_VAR(uri);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "A dependency injection container is required to access related dispatching services");
		return;
	}
	
	/** 
	 * Calling beforeHandle routing
	 */
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "micro:beforeHandleRoute", 1);
	
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Handling routing information
	 */
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "router", 1);
	
	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD_PARAMS_1(router, dependency_injector, "getshared", service);
	
	/** 
	 * Handle the URI as normal
	 */
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(router, "handle", uri);
	
	/** 
	 * Check if one route was matched
	 */
	PHALCON_INIT_VAR(matched_route);
	PHALCON_CALL_METHOD(matched_route, router, "getmatchedroute");
	if (Z_TYPE_P(matched_route) == IS_OBJECT) {
	
		PHALCON_OBS_VAR(handlers);
		phalcon_read_property_this(&handlers, this_ptr, SL("_handlers"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(route_id);
		PHALCON_CALL_METHOD(route_id, matched_route, "getrouteid");
		if (!phalcon_array_isset(handlers, route_id)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "Matched route doesn't have an associate handler");
			return;
		}
	
		/** 
		 * Updating active handler
		 */
		PHALCON_OBS_VAR(handler);
		phalcon_array_fetch(&handler, handlers, route_id, PH_NOISY_CC);
		phalcon_update_property_this(this_ptr, SL("_activeHandler"), handler TSRMLS_CC);
	
		/** 
		 * Calling beforeExecuteRoute event
		 */
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "micro:beforeExecuteRoute", 1);
	
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr);
			if (PHALCON_IS_FALSE(status)) {
				RETURN_MM_FALSE;
			} else {
				PHALCON_OBS_NVAR(handler);
				phalcon_read_property_this(&handler, this_ptr, SL("_activeHandler"), PH_NOISY_CC);
			}
		}
	
		PHALCON_OBS_VAR(before_handlers);
		phalcon_read_property_this(&before_handlers, this_ptr, SL("_beforeHandlers"), PH_NOISY_CC);
		if (Z_TYPE_P(before_handlers) == IS_ARRAY) { 
			phalcon_update_property_bool(this_ptr, SL("_stopped"), 0 TSRMLS_CC);
	
			/** 
			 * Calls the before handlers
			 */
	
			if (!phalcon_is_iterable(before_handlers, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(before);
	
				if (Z_TYPE_P(before) == IS_OBJECT) {
	
					PHALCON_INIT_NVAR(is_middleware);
					phalcon_instance_of(is_middleware, before, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC);
					if (PHALCON_IS_TRUE(is_middleware)) {
	
						/** 
						 * Call the middleware
						 */
						PHALCON_INIT_NVAR(status);
						PHALCON_CALL_METHOD_PARAMS_1(status, before, "call", this_ptr);
	
						/** 
						 * Reload the status
						 */
						PHALCON_OBS_NVAR(stopped);
						phalcon_read_property_this(&stopped, this_ptr, SL("_stopped"), PH_NOISY_CC);
	
						/** 
						 * break the execution if the middleware was stopped
						 */
						if (zend_is_true(stopped)) {
							break;
						}
	
						zend_hash_move_forward_ex(ah0, &hp0);
						continue;
					}
				}
				if (!phalcon_is_callable(before TSRMLS_CC)) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "The before handler is not callable");
					return;
				}
	
				/** 
				 * Call the before handler, if it returns false exit
				 */
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_USER_FUNC(status, before);
				if (PHALCON_IS_FALSE(status)) {
					RETURN_MM_FALSE;
				}
	
				/** 
				 * Reload the 'stopped' status
				 */
				PHALCON_OBS_NVAR(stopped);
				phalcon_read_property_this(&stopped, this_ptr, SL("_stopped"), PH_NOISY_CC);
				if (zend_is_true(stopped)) {
					RETURN_CCTOR(status);
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	
		/** 
		 * Calling the Handler in the PHP userland
		 */
		PHALCON_INIT_VAR(params);
		PHALCON_CALL_METHOD(params, router, "getparams");
	
		PHALCON_INIT_VAR(returned_value);
		PHALCON_CALL_USER_FUNC_ARRAY(returned_value, handler, params);
	
		/** 
		 * Update the returned value
		 */
		phalcon_update_property_this(this_ptr, SL("_returnedValue"), returned_value TSRMLS_CC);
	
		/** 
		 * Calling afterExecuteRoute event
		 */
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "micro:afterExecuteRoute", 1);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr);
		}
	
		PHALCON_OBS_VAR(after_handlers);
		phalcon_read_property_this(&after_handlers, this_ptr, SL("_afterHandlers"), PH_NOISY_CC);
		if (Z_TYPE_P(after_handlers) == IS_ARRAY) { 
			phalcon_update_property_bool(this_ptr, SL("_stopped"), 0 TSRMLS_CC);
	
			/** 
			 * Calls the after handlers
			 */
	
			if (!phalcon_is_iterable(after_handlers, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(after);
	
				if (Z_TYPE_P(after) == IS_OBJECT) {
	
					PHALCON_INIT_NVAR(is_middleware);
					phalcon_instance_of(is_middleware, after, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC);
					if (PHALCON_IS_TRUE(is_middleware)) {
	
						/** 
						 * Call the middleware
						 */
						PHALCON_INIT_NVAR(status);
						PHALCON_CALL_METHOD_PARAMS_1(status, after, "call", this_ptr);
	
						/** 
						 * Reload the status
						 */
						PHALCON_OBS_NVAR(stopped);
						phalcon_read_property_this(&stopped, this_ptr, SL("_stopped"), PH_NOISY_CC);
	
						/** 
						 * break the execution if the middleware was stopped
						 */
						if (zend_is_true(stopped)) {
							break;
						}
	
						zend_hash_move_forward_ex(ah1, &hp1);
						continue;
					}
				}
				if (!phalcon_is_callable(after TSRMLS_CC)) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "One of the 'after' handlers is not callable");
					return;
				}
	
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_USER_FUNC(status, after);
	
				zend_hash_move_forward_ex(ah1, &hp1);
			}
	
		}
	} else {
		/** 
		 * Calling beforeNotFound event
		 */
		PHALCON_OBS_NVAR(events_manager);
		phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "micro:beforeNotFound", 1);
	
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr);
			if (PHALCON_IS_FALSE(status)) {
				RETURN_MM_FALSE;
			}
		}
	
		/** 
		 * Check if a notfoundhandler is defined and it's callable
		 */
		PHALCON_OBS_VAR(not_found_handler);
		phalcon_read_property_this(&not_found_handler, this_ptr, SL("_notFoundHandler"), PH_NOISY_CC);
		if (!phalcon_is_callable(not_found_handler TSRMLS_CC)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "The Not-Found handler is not callable or is not defined");
			return;
		}
	
		/** 
		 * Call the Not-Found handler
		 */
		PHALCON_INIT_NVAR(returned_value);
		PHALCON_CALL_USER_FUNC(returned_value, not_found_handler);
	
		/** 
		 * Update the returned value
		 */
		phalcon_update_property_this(this_ptr, SL("_returnedValue"), returned_value TSRMLS_CC);
	
		RETURN_CCTOR(returned_value);
	}
	
	/** 
	 * Calling afterHandleRoute event
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "micro:afterHandleRoute", 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr);
	}
	
	PHALCON_OBS_VAR(finish_handlers);
	phalcon_read_property_this(&finish_handlers, this_ptr, SL("_finishHandlers"), PH_NOISY_CC);
	if (Z_TYPE_P(finish_handlers) == IS_ARRAY) { 
		phalcon_update_property_bool(this_ptr, SL("_stopped"), 0 TSRMLS_CC);
	
		PHALCON_INIT_NVAR(params);
	
		/** 
		 * Calls the finish handlers
		 */
	
		if (!phalcon_is_iterable(finish_handlers, &ah2, &hp2, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(finish);
	
			/** 
			 * Try to execute middleware as plugins
			 */
			if (Z_TYPE_P(finish) == IS_OBJECT) {
	
				PHALCON_INIT_NVAR(is_middleware);
				phalcon_instance_of(is_middleware, finish, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC);
				if (PHALCON_IS_TRUE(is_middleware)) {
	
					/** 
					 * Call the middleware
					 */
					PHALCON_INIT_NVAR(status);
					PHALCON_CALL_METHOD_PARAMS_1(status, finish, "call", this_ptr);
	
					/** 
					 * Reload the status
					 */
					PHALCON_OBS_NVAR(stopped);
					phalcon_read_property_this(&stopped, this_ptr, SL("_stopped"), PH_NOISY_CC);
	
					/** 
					 * break the execution if the middleware was stopped
					 */
					if (zend_is_true(stopped)) {
						break;
					}
	
					zend_hash_move_forward_ex(ah2, &hp2);
					continue;
				}
			}
			if (!phalcon_is_callable(finish TSRMLS_CC)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "One of finish handlers is not callable");
				return;
			}
	
			if (Z_TYPE_P(params) == IS_NULL) {
				PHALCON_INIT_NVAR(params);
				array_init_size(params, 1);
				phalcon_array_append(&params, this_ptr, PH_SEPARATE TSRMLS_CC);
			}
	
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_USER_FUNC_ARRAY(status, finish, params);
	
			/** 
			 * Reload the status
			 */
			PHALCON_OBS_NVAR(stopped);
			phalcon_read_property_this(&stopped, this_ptr, SL("_stopped"), PH_NOISY_CC);
	
			/** 
			 * break the execution if the middleware was stopped
			 */
			if (zend_is_true(stopped)) {
				break;
			}
	
			zend_hash_move_forward_ex(ah2, &hp2);
		}
	
	}
	
	
	RETURN_CCTOR(returned_value);
}

/**
 * Stops the middleware execution avoiding than other middlewares be executed
 */
PHP_METHOD(Phalcon_Mvc_Micro, stop){


	phalcon_update_property_bool(this_ptr, SL("_stopped"), 1 TSRMLS_CC);
	
}

/**
 * Sets externally the handler that must be called by the matched route
 *
 * @param callable $activeHandler
 */
PHP_METHOD(Phalcon_Mvc_Micro, setActiveHandler){

	zval *active_handler;

	phalcon_fetch_params(0, 1, 0, &active_handler);
	
	phalcon_update_property_this(this_ptr, SL("_activeHandler"), active_handler TSRMLS_CC);
	
}

/**
 * Return the handler that will be called for the matched route
 *
 * @return callable
 */
PHP_METHOD(Phalcon_Mvc_Micro, getActiveHandler){


	RETURN_MEMBER(this_ptr, "_activeHandler");
}

/**
 * Returns the value returned by the executed handler
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, getReturnedValue){


	RETURN_MEMBER(this_ptr, "_returnedValue");
}

/**
 * Check if a service is registered in the internal services container using the array syntax
 *
 * @param string $alias
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetExists){

	zval *alias, *exists;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &alias);
	
	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_1(exists, this_ptr, "hasservice", alias);
	RETURN_CCTOR(exists);
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
PHP_METHOD(Phalcon_Mvc_Micro, offsetSet){

	zval *alias, *definition;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &alias, &definition);
	
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setservice", alias, definition);
	
	PHALCON_MM_RESTORE();
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
PHP_METHOD(Phalcon_Mvc_Micro, offsetGet){

	zval *alias, *service;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &alias);
	
	PHALCON_INIT_VAR(service);
	PHALCON_CALL_METHOD_PARAMS_1(service, this_ptr, "getservice", alias);
	RETURN_CCTOR(service);
}

/**
 * Removes a service from the internal services container using the array syntax
 *
 * @param string $alias
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetUnset){

	zval *alias;

	phalcon_fetch_params(0, 1, 0, &alias);
	
	RETURN_CCTORW(alias);
}

/**
 * Appends a before middleware to be called before execute the route
 *
 * @param callable $handler
 * @return Phalcon\Mvc\Micro
 */
PHP_METHOD(Phalcon_Mvc_Micro, before){

	zval *handler;

	phalcon_fetch_params(0, 1, 0, &handler);
	
	phalcon_update_property_array_append(this_ptr, SL("_beforeHandlers"), handler TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Appends an 'after' middleware to be called after execute the route
 *
 * @param callable $handler
 * @return Phalcon\Mvc\Micro
 */
PHP_METHOD(Phalcon_Mvc_Micro, after){

	zval *handler;

	phalcon_fetch_params(0, 1, 0, &handler);
	
	phalcon_update_property_array_append(this_ptr, SL("_afterHandlers"), handler TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Appends a 'finish' middleware to be called when the request is finished
 *
 * @param callable $handler
 * @return Phalcon\Mvc\Micro
 */
PHP_METHOD(Phalcon_Mvc_Micro, finish){

	zval *handler;

	phalcon_fetch_params(0, 1, 0, &handler);
	
	phalcon_update_property_array_append(this_ptr, SL("_finishHandlers"), handler TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the internal handlers attached to the application
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Micro, getHandlers){


	RETURN_MEMBER(this_ptr, "_handlers");
}

