
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Micro, phalcon, mvc_micro, phalcon_di_injectable_ce, phalcon_mvc_micro_method_entry, 0);

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

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Micro constructor
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Micro, __construct) {

	zval *dependencyInjector;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dependencyInjector);



	zephir_call_method_p1_noret(this_ptr, "setdi", dependencyInjector);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Micro, setDI) {

	zval *dependencyInjector, *service, *exists;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dependencyInjector);



	ZEPHIR_INIT_VAR(service);
	ZVAL_STRING(service, "application", 1);
	ZEPHIR_INIT_VAR(exists);
	zephir_call_method_p1(exists, dependencyInjector, "has", service);
	if (!(zephir_is_true(exists))) {
		zephir_call_method_p2_noret(dependencyInjector, "set", service, this_ptr);
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * add route
 * @param string routePattern
 * @param string handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, add) {

	zval *routePattern, *handler, *retVal, *router, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern, &handler);



	ZEPHIR_INIT_VAR(router);
	zephir_call_method(router, this_ptr, "getrouter");
	ZEPHIR_INIT_VAR(retVal);
	array_init(retVal);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, router, "method", routePattern);
	zephir_array_append(&retVal, _0, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * Maps a route to a handler without any HTTP method constraint
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, map) {

	zval *routePattern, *handler, *router, *route, *routeId;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern, &handler);



	ZEPHIR_INIT_VAR(router);
	zephir_call_method(router, this_ptr, "getrouter");
	ZEPHIR_INIT_VAR(route);
	zephir_call_method_p1(route, router, "add", routePattern);
	ZEPHIR_INIT_VAR(routeId);
	zephir_call_method(routeId, route, "getrouteid");
	zephir_update_property_array(this_ptr, SL("_handlers"), routeId, handler TSRMLS_CC);
	RETURN_CCTOR(route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, get) {

	zval *routePattern, *handler, *router, *route, *routeId;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern, &handler);



	ZEPHIR_INIT_VAR(router);
	zephir_call_method(router, this_ptr, "getrouter");
	ZEPHIR_INIT_VAR(route);
	zephir_call_method_p1(route, router, "addget", routePattern);
	ZEPHIR_INIT_VAR(routeId);
	zephir_call_method(routeId, route, "getrouteid");
	zephir_update_property_array(this_ptr, SL("_handlers"), routeId, handler TSRMLS_CC);
	RETURN_CCTOR(route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, post) {

	zval *routePattern, *handler, *router, *route, *routeId;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern, &handler);



	ZEPHIR_INIT_VAR(router);
	zephir_call_method(router, this_ptr, "getrouter");
	ZEPHIR_INIT_VAR(route);
	zephir_call_method_p1(route, router, "addpost", routePattern);
	ZEPHIR_INIT_VAR(routeId);
	zephir_call_method(routeId, route, "getrouteid");
	zephir_update_property_array(this_ptr, SL("_handlers"), routeId, handler TSRMLS_CC);
	RETURN_CCTOR(route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, put) {

	zval *routePattern, *handler, *router, *route, *routeId;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern, &handler);



	ZEPHIR_INIT_VAR(router);
	zephir_call_method(router, this_ptr, "getrouter");
	ZEPHIR_INIT_VAR(route);
	zephir_call_method_p1(route, router, "addput", routePattern);
	ZEPHIR_INIT_VAR(routeId);
	zephir_call_method(routeId, route, "getrouteid");
	zephir_update_property_array(this_ptr, SL("_handlers"), routeId, handler TSRMLS_CC);
	RETURN_CCTOR(route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, patch) {

	zval *routePattern, *handler, *router, *route, *routeId;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern, &handler);



	ZEPHIR_INIT_VAR(router);
	zephir_call_method(router, this_ptr, "getrouter");
	ZEPHIR_INIT_VAR(route);
	zephir_call_method_p1(route, router, "addpatch", routePattern);
	ZEPHIR_INIT_VAR(routeId);
	zephir_call_method(routeId, route, "getrouteid");
	zephir_update_property_array(this_ptr, SL("_handlers"), routeId, handler TSRMLS_CC);
	RETURN_CCTOR(route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, head) {

	zval *routePattern_param = NULL, *handler, *router, *route, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

		if (Z_TYPE_P(routePattern_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		routePattern = routePattern_param;



	ZEPHIR_INIT_VAR(router);
	zephir_call_method(router, this_ptr, "getrouter");
	ZEPHIR_INIT_VAR(route);
	zephir_call_method_p1(route, router, "addhead", routePattern);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, route, "getrouteid");
	zephir_update_property_array(this_ptr, SL("_handlers"), _0, handler TSRMLS_CC);
	RETURN_CCTOR(route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, delete) {

	zval *routePattern, *handler, *router, *route, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern, &handler);



	ZEPHIR_INIT_VAR(router);
	zephir_call_method(router, this_ptr, "getrouter");
	ZEPHIR_INIT_VAR(route);
	zephir_call_method_p1(route, router, "adddelete", routePattern);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, route, "getrouteid");
	zephir_update_property_array(this_ptr, SL("_handlers"), _0, handler TSRMLS_CC);
	RETURN_CCTOR(route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, options) {

	zval *routePattern_param = NULL, *handler, *router, *route, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

		if (Z_TYPE_P(routePattern_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		routePattern = routePattern_param;



	ZEPHIR_INIT_VAR(router);
	zephir_call_method(router, this_ptr, "getrouter");
	ZEPHIR_INIT_VAR(route);
	zephir_call_method_p1(route, router, "addoptions", routePattern);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, route, "getrouteid");
	zephir_update_property_array(this_ptr, SL("_handlers"), _0, handler TSRMLS_CC);
	RETURN_CCTOR(route);

}

/**
 * Mounts a collection of handlers
 *
 * @param Phalcon\Mvc\Micro\Collection collection
 * @return Phalcon\Mvc\Micro
 */
PHP_METHOD(Phalcon_Mvc_Micro, mount) {

	zend_function *_3 = NULL, *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *collection, *mainHandler, *handlers, *lazy, *lazyHandler = NULL, *prefix, *methods, *pattern, *subHandler, *realHandler = NULL, *prefixedPattern = NULL, *route = NULL, *handler = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection);



	if ((Z_TYPE_P(collection) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "The collection is not valid");
		return;
	}
	ZEPHIR_INIT_VAR(mainHandler);
	zephir_call_method(mainHandler, collection, "gethandler");
	if (!((0 == 0))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "The collection requires a main handler");
		return;
	}
	ZEPHIR_INIT_VAR(handlers);
	zephir_call_method(handlers, collection, "gethandlers");
	if (!(zephir_fast_count_int(handlers TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "There are no handlers to mount");
		return;
	}
	if ((Z_TYPE_P(handlers) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(lazy);
		zephir_call_method(lazy, collection, "islazy");
		if (zephir_is_true(lazy)) {
			ZEPHIR_INIT_VAR(lazyHandler);
			object_init_ex(lazyHandler, phalcon_mvc_micro_exception_ce);
			zephir_call_method_p1_noret(lazyHandler, "__construct", mainHandler);
		} else {
			ZEPHIR_CPY_WRT(lazyHandler, mainHandler);
		}
		ZEPHIR_INIT_VAR(prefix);
		zephir_call_method(prefix, collection, "getprefix");
		zephir_is_iterable(handlers, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(handler, _2);
			if ((Z_TYPE_P(handler) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "One of the registered handlers is invalid");
				return;
			}
			zephir_array_fetch_long(&methods, handler, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_long(&pattern, handler, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_long(&subHandler, handler, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(realHandler);
			array_init(realHandler);
			zephir_array_fast_append(realHandler, lazyHandler);
			zephir_array_fast_append(realHandler, subHandler);
			if (!((0 == 0))) {
				if (ZEPHIR_IS_LONG(pattern, '/')) {
					ZEPHIR_CPY_WRT(prefixedPattern, prefix);
				} else {
					ZEPHIR_INIT_NVAR(prefixedPattern);
					ZEPHIR_CONCAT_VV(prefixedPattern, prefix, pattern);
				}
			} else {
				ZEPHIR_CPY_WRT(prefixedPattern, pattern);
			}
			ZEPHIR_INIT_NVAR(route);
			zephir_call_method_p2_cache(route, this_ptr, "map", &_3, prefixedPattern, realHandler);
			if (zephir_is_true(methods)) {
				zephir_call_method_p1_cache_noret(route, "via", &_4, methods);
			}
		}
	}
	RETURN_THIS();

}

/**
 * Sets a handler that will be called when the router doesn't match any of the defined routes
 *
 * @param callable handler
 * @return Phalcon\Mvc\Micro
 */
PHP_METHOD(Phalcon_Mvc_Micro, notFound) {

	zval *handler;

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_this(this_ptr, SL("_notFoundHandler"), handler TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the internal router used by the application
 *
 * @return Phalcon\Mvc\RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, getRouter) {

	zval *router, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(router);
	zephir_read_property_this(&router, this_ptr, SL("_router"), PH_NOISY_CC);
	if ((Z_TYPE_P(router) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "router", 1);
		ZEPHIR_INIT_BNVAR(router);
		zephir_call_method_p1(router, this_ptr, "getsharedservice", _0);
		zephir_call_method_noret(router, "clear");
		zephir_call_method_p1_noret(router, "removeextraslashes", ZEPHIR_GLOBAL(global_true));
		zephir_update_property_this(this_ptr, SL("_router"), router TSRMLS_CC);
	}
	RETURN_CCTOR(router);

}

/**
 * Sets a service from the DI
 *
 * @param string  serviceName
 * @param mixed   definition
 * @param boolean shared
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, setService) {

	zval *serviceName, *definition, *shared = NULL, *dependencyInjector;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &serviceName, &definition, &shared);

	if (!shared) {
		shared = ZEPHIR_GLOBAL(global_false);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_INIT_BNVAR(dependencyInjector);
		object_init_ex(dependencyInjector, phalcon_di_factorydefault_ce);
		zephir_call_method_noret(dependencyInjector, "__construct");
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	zephir_call_method_p3(return_value, dependencyInjector, "set", serviceName, definition, shared);
	RETURN_MM();

}

/**
 * Checks if a service is registered in the DI
 *
 * @param string serviceName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Micro, hasService) {

	zval *serviceName, *dependencyInjector;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName);



	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_INIT_BNVAR(dependencyInjector);
		object_init_ex(dependencyInjector, phalcon_di_factorydefault_ce);
		zephir_call_method_noret(dependencyInjector, "__construct");
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	zephir_call_method_p1(return_value, dependencyInjector, "has", serviceName);
	RETURN_MM();

}

/**
 * Obtains a service from the DI
 *
 * @param string serviceName
 * @return object
 */
PHP_METHOD(Phalcon_Mvc_Micro, getService) {

	zval *serviceName, *dependencyInjector;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName);



	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_INIT_BNVAR(dependencyInjector);
		object_init_ex(dependencyInjector, phalcon_di_factorydefault_ce);
		zephir_call_method_noret(dependencyInjector, "__construct");
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	zephir_call_method_p1(return_value, dependencyInjector, "get", serviceName);
	RETURN_MM();

}

/**
 * Obtains a shared service from the DI
 *
 * @param string serviceName
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, getSharedService) {

	zval *serviceName, *dependencyInjector;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName);



	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_INIT_BNVAR(dependencyInjector);
		object_init_ex(dependencyInjector, phalcon_di_factorydefault_ce);
		zephir_call_method_noret(dependencyInjector, "__construct");
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	zephir_call_method_p1(return_value, dependencyInjector, "getshared", serviceName);
	RETURN_MM();

}

/**
 * Handle the whole request
 *
 * @param string uri
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, handle) {

	zend_function *_9 = NULL, *_15 = NULL, *_20 = NULL;
	HashTable *_7, *_13, *_18;
	HashPosition _6, _12, _17;
	zval *uri = NULL, *dependencyInjector, *eventsManager = NULL, *status = NULL, *router, *matchedRoute, *handler = NULL, *beforeHandlers, *params = NULL, *returnedValue, *afterHandlers, *notFoundHandler, *finishHandlers, *finish = NULL, *before = NULL, *after = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, **_8, *_10, *_11 = NULL, **_14, *_16, **_19;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "is_object", dependencyInjector);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "A dependency injection container is required to access related dispatching services");
		return;
	}
	ZEPHIR_OBS_VAR(eventsManager);
	zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "is_object", eventsManager);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "micro:beforeHandleRoute", 1);
		zephir_call_method_p2(_2, eventsManager, "fire", _3, this_ptr);
		if (ZEPHIR_IS_FALSE(_2)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "router", 1);
	ZEPHIR_INIT_VAR(router);
	zephir_call_method_p1(router, dependencyInjector, "getshared", _2);
	zephir_call_method_p1_noret(router, "handle", uri);
	ZEPHIR_INIT_VAR(matchedRoute);
	zephir_call_method(matchedRoute, router, "getmatchedroute");
	ZEPHIR_INIT_VAR(returnedValue);
	if ((Z_TYPE_P(matchedRoute) == IS_OBJECT)) {
		ZEPHIR_OBS_VAR(handler);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_handlers"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_method(_2, matchedRoute, "getrouteid");
		if (!(zephir_array_isset_fetch(&handler, _4, _2, 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "Matched route doesn't have an associate handler");
			return;
		}
		zephir_update_property_this(this_ptr, SL("_activeHandler"), handler TSRMLS_CC);
		if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
			ZEPHIR_INIT_NVAR(_3);
			ZEPHIR_INIT_VAR(_5);
			ZVAL_STRING(_5, "micro:beforeExecuteRoute", 1);
			zephir_call_method_p2(_3, eventsManager, "fire", _5, this_ptr);
			if (ZEPHIR_IS_FALSE(_3)) {
				RETURN_MM_BOOL(0);
			} else {
				ZEPHIR_OBS_NVAR(handler);
				zephir_read_property_this(&handler, this_ptr, SL("_activeHandler"), PH_NOISY_CC);
			}
		}
		beforeHandlers = zephir_fetch_nproperty_this(this_ptr, SL("_beforeHandlers"), PH_NOISY_CC);
		if ((Z_TYPE_P(beforeHandlers) == IS_ARRAY)) {
			zephir_update_property_this(this_ptr, SL("_stopped"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			zephir_is_iterable(beforeHandlers, &_7, &_6, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
				; zend_hash_move_forward_ex(_7, &_6)
			) {
				ZEPHIR_GET_HVALUE(before, _8);
				if ((Z_TYPE_P(before) == IS_OBJECT)) {
					if (zephir_is_instance_of(before, SL("Phalcon\\Mvc\\Micro\\MiddlewareInterface") TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(status);
						zephir_call_method_p1_cache(status, before, "call", &_9, this_ptr);
						_10 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
						if (zephir_is_true(_10)) {
							break;
						}
						continue;
					}
				}
				if (!(zephir_is_callable(before TSRMLS_CC))) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "The before handler is not callable");
					return;
				}
				ZEPHIR_INIT_NVAR(_5);
				zephir_call_func_p1(_5, "call_user_func", before);
				if (ZEPHIR_IS_FALSE(_5)) {
					RETURN_MM_BOOL(0);
				}
				_10 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
				if (zephir_is_true(_10)) {
					RETURN_CCTOR(status);
				}
			}
		}
		ZEPHIR_INIT_VAR(params);
		zephir_call_method(params, router, "getparams");
		zephir_call_func_p2(returnedValue, "call_user_func_array", handler, params);
		zephir_update_property_this(this_ptr, SL("_returnedValue"), returnedValue TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_func_p1(_5, "is_object", eventsManager);
		if (zephir_is_true(_5)) {
			ZEPHIR_INIT_VAR(_11);
			ZVAL_STRING(_11, "micro:afterExecuteRoute", 1);
			zephir_call_method_p2_noret(eventsManager, "fire", _11, this_ptr);
		}
		afterHandlers = zephir_fetch_nproperty_this(this_ptr, SL("_afterHandlers"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_func_p1(_5, "is_array", afterHandlers);
		if (zephir_is_true(_5)) {
			zephir_update_property_this(this_ptr, SL("_stopped"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			zephir_is_iterable(afterHandlers, &_13, &_12, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
				; zend_hash_move_forward_ex(_13, &_12)
			) {
				ZEPHIR_GET_HVALUE(after, _14);
				ZEPHIR_INIT_NVAR(_11);
				zephir_call_func_p1(_11, "is_object", after);
				if (zephir_is_true(_11)) {
					if (zephir_is_instance_of(after, SL("Phalcon\\Mvc\\Micro\\MiddlewareInterface") TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(status);
						zephir_call_method_p1_cache(status, after, "call", &_15, this_ptr);
						_16 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
						if (zephir_is_true(_16)) {
							break;
						}
						continue;
					}
				}
				if (!(zephir_is_callable(after TSRMLS_CC))) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "One of the 'after' handlers is not callable");
					return;
				}
				ZEPHIR_INIT_NVAR(status);
				zephir_call_func_p1(status, "call_user_func", after);
			}
		}
	} else {
		ZEPHIR_OBS_NVAR(eventsManager);
		zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_func_p1(_2, "is_object", eventsManager);
		if (zephir_is_true(_2)) {
			ZEPHIR_INIT_NVAR(_3);
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "micro:beforeNotFound", 1);
			zephir_call_method_p2(_3, eventsManager, "fire", _5, this_ptr);
			if (ZEPHIR_IS_FALSE(_3)) {
				RETURN_MM_BOOL(0);
			}
		}
		notFoundHandler = zephir_fetch_nproperty_this(this_ptr, SL("_notFoundHandler"), PH_NOISY_CC);
		if (!(zephir_is_callable(notFoundHandler TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "The Not-Found handler is not callable or is not defined");
			return;
		}
		zephir_call_func_p1(returnedValue, "call_user_func", notFoundHandler);
		zephir_update_property_this(this_ptr, SL("_returnedValue"), returnedValue TSRMLS_CC);
		RETURN_CCTOR(returnedValue);
	}
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_func_p1(_2, "is_object", eventsManager);
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "micro:afterHandleRoute", 1);
		zephir_call_method_p2_noret(eventsManager, "fire", _3, this_ptr);
	}
	finishHandlers = zephir_fetch_nproperty_this(this_ptr, SL("_finishHandlers"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_func_p1(_2, "is_array", finishHandlers);
	if (zephir_is_true(_2)) {
		zephir_update_property_this(this_ptr, SL("_stopped"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		ZEPHIR_INIT_NVAR(params);
		ZVAL_NULL(params);
		zephir_is_iterable(finishHandlers, &_18, &_17, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_18, (void**) &_19, &_17) == SUCCESS
			; zend_hash_move_forward_ex(_18, &_17)
		) {
			ZEPHIR_GET_HVALUE(finish, _19);
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_func_p1(_3, "is_object", finish);
			if (zephir_is_true(_3)) {
				if (zephir_is_instance_of(finish, SL("Phalcon\\Mvc\\Micro\\MiddlewareInterface") TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(status);
					zephir_call_method_p1_cache(status, finish, "call", &_20, this_ptr);
					_4 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
					if (zephir_is_true(_4)) {
						break;
					}
					continue;
				}
			}
			if (!(zephir_is_callable(finish TSRMLS_CC))) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "One of finish handlers is not callable");
				return;
			}
			if ((Z_TYPE_P(params) == IS_NULL)) {
				ZEPHIR_INIT_NVAR(params);
				array_init(params);
				zephir_array_fast_append(params, this_ptr);
			}
			ZEPHIR_INIT_NVAR(status);
			zephir_call_func_p2(status, "call_user_func_array", finish, params);
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
			if (zephir_is_true(_10)) {
				break;
			}
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_func_p1(_2, "is_object", returnedValue);
	if (zephir_is_true(_2)) {
		if (zephir_is_instance_of(returnedValue, SL("Phalcon\\Http\\ResponseInterface") TSRMLS_CC)) {
			zephir_call_method_noret(returnedValue, "send");
		}
	}
	RETURN_CCTOR(returnedValue);

}

/**
 * Stops the middleware execution avoiding than other middlewares be executed
 */
PHP_METHOD(Phalcon_Mvc_Micro, stop) {


	zephir_update_property_this(this_ptr, SL("_stopped"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

/**
 * Sets externally the handler that must be called by the matched route
 *
 * @param callable activeHandler
 */
PHP_METHOD(Phalcon_Mvc_Micro, setActiveHandler) {

	zval *activeHandler;

	zephir_fetch_params(0, 1, 0, &activeHandler);



	zephir_update_property_this(this_ptr, SL("_activeHandler"), activeHandler TSRMLS_CC);

}

/**
 * Return the handler that will be called for the matched route
 *
 * @return callable
 */
PHP_METHOD(Phalcon_Mvc_Micro, getActiveHandler) {


	RETURN_MEMBER(this_ptr, "_activeHandler");

}

/**
 * Returns the value returned by the executed handler
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, getReturnedValue) {


	RETURN_MEMBER(this_ptr, "_returnedValue");

}

/**
 * Check if a service is registered in the internal services container using the array syntax
 *
 * @param string alias
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetExists) {

	zval *alias;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias);



	zephir_call_method_p1(return_value, this_ptr, "hasservice", alias);
	RETURN_MM();

}

/**
 * Allows to register a shared service in the internal services container using the array syntax
 *
 *<code>
 *	$app['request'] = new Phalcon\Http\Request();
 *</code>
 *
 * @param string alias
 * @param mixed definition
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetSet) {

	zval *alias, *definition;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &alias, &definition);



	zephir_call_method_p2_noret(this_ptr, "setservice", alias, definition);
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Phalcon_Mvc_Micro, offsetGet) {

	zval *alias;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias);



	zephir_call_method_p1(return_value, this_ptr, "getservice", alias);
	RETURN_MM();

}

/**
 * Removes a service from the internal services container using the array syntax
 *
 * @param string alias
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetUnset) {

	zval *alias;

	zephir_fetch_params(0, 1, 0, &alias);



	RETURN_CCTORW(alias);

}

/**
 * Appends a before middleware to be called before execute the route
 *
 * @param callable handler
 * @return Phalcon\Mvc\Micro
 */
PHP_METHOD(Phalcon_Mvc_Micro, before) {

	zval *handler;

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_array_append(this_ptr, SL("_beforeHandlers"), handler TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Appends an 'after' middleware to be called after execute the route
 *
 * @param callable handler
 * @return Phalcon\Mvc\Micro
 */
PHP_METHOD(Phalcon_Mvc_Micro, after) {

	zval *handler;

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_array_append(this_ptr, SL("_afterHandlers"), handler TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Appends a 'finish' middleware to be called when the request is finished
 *
 * @param callable handler
 * @return Phalcon\Mvc\Micro
 */
PHP_METHOD(Phalcon_Mvc_Micro, finish) {

	zval *handler;

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_array_append(this_ptr, SL("_finishHandlers"), handler TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the internal handlers attached to the application
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Micro, getHandlers) {


	RETURN_MEMBER(this_ptr, "_handlers");

}

