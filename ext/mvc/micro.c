
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/array.h"

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

PHP_METHOD(Phalcon_Mvc_Micro, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_mvc_micro_ce, this_ptr, SL("_handlers"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Micro, setDI){

	zval *dependency_injector = NULL, *service = NULL, *exists = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "The dependency injector must be an object");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "application", 1);
	
	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_1(exists, dependency_injector, "has", service, PH_NO_CHECK);
	if (!zend_is_true(exists)) {
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(dependency_injector, "set", service, this_ptr, PH_NO_CHECK);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Mvc_Micro, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\Manager $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Micro, setEventsManager){

	zval *events_manager = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &events_manager) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\Manager
 */
PHP_METHOD(Phalcon_Mvc_Micro, getEventsManager){

	zval *events_manager = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
	RETURN_CCTOR(events_manager);
}

/**
 * Maps a route to a handler without any HTTP method constraint
 *
 * @param string $routePattern
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, map){

	zval *route_pattern = NULL, *handler = NULL, *router = NULL, *route = NULL;
	zval *route_id = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "add", route_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_handlers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, route_id, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_handlers"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param string $routePattern
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, get){

	zval *route_pattern = NULL, *handler = NULL, *router = NULL, *route = NULL;
	zval *route_id = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addget", route_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_handlers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, route_id, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_handlers"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param string $routePattern
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, post){

	zval *route_pattern = NULL, *handler = NULL, *router = NULL, *route = NULL;
	zval *route_id = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addpost", route_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_handlers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, route_id, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_handlers"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 *
 * @param string $routePattern
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, put){

	zval *route_pattern = NULL, *handler = NULL, *router = NULL, *route = NULL;
	zval *route_id = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addput", route_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_handlers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, route_id, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_handlers"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 *
 * @param string $routePattern
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, head){

	zval *route_pattern = NULL, *handler = NULL, *router = NULL, *route = NULL;
	zval *route_id = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addhead", route_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_handlers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, route_id, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_handlers"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 *
 * @param string $routePattern
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, delete){

	zval *route_pattern = NULL, *handler = NULL, *router = NULL, *route = NULL;
	zval *route_id = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "adddelete", route_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_handlers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, route_id, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_handlers"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param string $routePattern
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, options){

	zval *route_pattern = NULL, *handler = NULL, *router = NULL, *route = NULL;
	zval *route_id = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addoptions", route_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_handlers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, route_id, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_handlers"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(route);
}

/**
 * Sets a handler that will be called when the router doesn't match any of the defined routes
 *
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, notFound){

	zval *handler = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_notFoundHandler"), handler TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal router used by the application
 *
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Micro, getRouter){

	zval *router = NULL, *service_name = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(router);
	phalcon_read_property(&router, this_ptr, SL("_router"), PH_NOISY_CC);
	if (Z_TYPE_P(router) != IS_OBJECT) {
		PHALCON_INIT_VAR(service_name);
		ZVAL_STRING(service_name, "router", 1);
		
		PHALCON_INIT_VAR(router);
		PHALCON_CALL_METHOD_PARAMS_1(router, this_ptr, "getsharedservice", service_name, PH_NO_CHECK);
		PHALCON_CALL_METHOD_NORETURN(router, "clear", PH_NO_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_router"), router TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(router);
}

/**
 * Obtains a service from the DI
 *
 * @return object
 */
PHP_METHOD(Phalcon_Mvc_Micro, getService){

	zval *service_name = NULL, *dependency_injector = NULL;
	zval *service = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &service_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_VAR(dependency_injector);
		object_init_ex(dependency_injector, phalcon_di_factorydefault_ce);
		PHALCON_CALL_METHOD_NORETURN(dependency_injector, "__construct", PH_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(service);
	PHALCON_CALL_METHOD_PARAMS_1(service, dependency_injector, "get", service_name, PH_NO_CHECK);
	
	RETURN_CCTOR(service);
}

/**
 * Obtains a shared service from the DI
 */
PHP_METHOD(Phalcon_Mvc_Micro, getSharedService){

	zval *service_name = NULL, *dependency_injector = NULL;
	zval *service = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &service_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_VAR(dependency_injector);
		object_init_ex(dependency_injector, phalcon_di_factorydefault_ce);
		PHALCON_CALL_METHOD_NORETURN(dependency_injector, "__construct", PH_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(service);
	PHALCON_CALL_METHOD_PARAMS_1(service, dependency_injector, "getshared", service_name, PH_NO_CHECK);
	
	RETURN_CCTOR(service);
}

/**
 * Handle the whole request
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, handle){

	zval *dependency_injector = NULL, *events_manager = NULL;
	zval *event_name = NULL, *status = NULL, *service = NULL, *router = NULL, *matched_route = NULL;
	zval *handlers = NULL, *route_id = NULL, *handler = NULL, *params = NULL, *returned_value = NULL;
	zval *not_found_handler = NULL, *is_callable = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "A dependency injection container is required to access related dispatching services");
		return;
	}
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "micro:beforeHandleRoute", 1);
		
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
		if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "router", 1);
	
	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD_PARAMS_1(router, dependency_injector, "getshared", service, PH_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(router, "handle", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(matched_route);
	PHALCON_CALL_METHOD(matched_route, router, "getmatchedroute", PH_NO_CHECK);
	if (Z_TYPE_P(matched_route) == IS_OBJECT) {
		PHALCON_INIT_VAR(handlers);
		phalcon_read_property(&handlers, this_ptr, SL("_handlers"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(route_id);
		PHALCON_CALL_METHOD(route_id, matched_route, "getrouteid", PH_NO_CHECK);
		eval_int = phalcon_array_isset(handlers, route_id);
		if (!eval_int) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "Matched route doesn't have an associate handler");
			return;
		}
		
		PHALCON_INIT_VAR(handler);
		phalcon_array_fetch(&handler, handlers, route_id, PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_activeHandler"), handler TSRMLS_CC);
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "micro:beforeExecuteRoute", 1);
			
			PHALCON_INIT_VAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
			if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			} else {
				PHALCON_INIT_VAR(handler);
				phalcon_read_property(&handler, this_ptr, SL("_activeHandler"), PH_NOISY_CC);
			}
		}
		
		PHALCON_INIT_VAR(params);
		PHALCON_CALL_METHOD(params, router, "getparams", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(returned_value);
		PHALCON_CALL_FUNC_PARAMS_2(returned_value, "call_user_func_array", handler, params);
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "micro:afterExecuteRoute", 1);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
		}
	} else {
		PHALCON_INIT_VAR(events_manager);
		phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "micro:beforeNotFound", 1);
			
			PHALCON_INIT_VAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
			if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
		
		PHALCON_INIT_VAR(not_found_handler);
		phalcon_read_property(&not_found_handler, this_ptr, SL("_notFoundHandler"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(is_callable);
		PHALCON_CALL_FUNC_PARAMS_1(is_callable, "is_callable", not_found_handler);
		if (Z_TYPE_P(is_callable) == IS_BOOL && !Z_BVAL_P(is_callable)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "The Not-Found handler is not callable or is not defined");
			return;
		}
		
		PHALCON_INIT_VAR(returned_value);
		PHALCON_CALL_FUNC_PARAMS_1(returned_value, "call_user_func", not_found_handler);
		
		RETURN_CCTOR(returned_value);
	}
	
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "micro:afterHandleRoute", 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
	}
	
	
	RETURN_CCTOR(returned_value);
}

/**
 * Sets externally the handler that must be called by the matched route
 *
 * @param callable $activeHandler
 */
PHP_METHOD(Phalcon_Mvc_Micro, setActiveHandler){

	zval *active_handler = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &active_handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_activeHandler"), active_handler TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Return the handler that will be called for the matched route
 *
 * @return callable
 */
PHP_METHOD(Phalcon_Mvc_Micro, getActiveHandler){

	zval *active_handler = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(active_handler);
	phalcon_read_property(&active_handler, this_ptr, SL("_activeHandler"), PH_NOISY_CC);
	
	RETURN_CCTOR(active_handler);
}

/**
 * Returns the value returned by the executed handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, getReturnedValue){

	zval *returned_value = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(returned_value);
	phalcon_read_property(&returned_value, this_ptr, SL("_returnedValue"), PH_NOISY_CC);
	
	RETURN_CCTOR(returned_value);
}

