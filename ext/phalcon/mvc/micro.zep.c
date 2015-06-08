
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Micro, phalcon, mvc_micro, phalcon_di_injectable_ce, phalcon_mvc_micro_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_handlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_router"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_stopped"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_notFoundHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_errorHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_activeHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_beforeHandlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_afterHandlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_finishHandlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_returnedValue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_micro_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Micro constructor
 */
PHP_METHOD(Phalcon_Mvc_Micro, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dependencyInjector = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		dependencyInjector = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		if (zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, dependencyInjector);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Micro, setDI) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dependencyInjector, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dependencyInjector);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "application", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, dependencyInjector, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "application", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "set", NULL, 0, _1, this_ptr);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, router, "add", NULL, 0, routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_handlers"), _0, handler TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, router, "addget", NULL, 0, routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_handlers"), _0, handler TSRMLS_CC);
	RETURN_CCTOR(route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, post) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, router, "addpost", NULL, 0, routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_handlers"), _0, handler TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, router, "addput", NULL, 0, routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_handlers"), _0, handler TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, router, "addpatch", NULL, 0, routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_handlers"), _0, handler TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, router, "addhead", NULL, 0, routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, route, "getrouteid", NULL, 0);
	zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, router, "adddelete", NULL, 0, routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, route, "getrouteid", NULL, 0);
	zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, router, "addoptions", NULL, 0, routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_handlers"), _0, handler TSRMLS_CC);
	RETURN_CCTOR(route);

}

/**
 * Mounts a collection of handlers
 */
PHP_METHOD(Phalcon_Mvc_Micro, mount) {

	zend_bool _5, _6;
	zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *collection, *mainHandler = NULL, *handlers = NULL, *lazyHandler = NULL, *prefix = NULL, *methods = NULL, *pattern = NULL, *subHandler = NULL, *realHandler = NULL, *prefixedPattern = NULL, *route = NULL, *handler = NULL, *name = NULL, *_0 = NULL, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection);



	ZEPHIR_CALL_METHOD(&mainHandler, collection, "gethandler", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(mainHandler)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Collection requires a main handler", "phalcon/mvc/micro.zep", 374);
		return;
	}
	ZEPHIR_CALL_METHOD(&handlers, collection, "gethandlers", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(handlers TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "There are no handlers to mount", "phalcon/mvc/micro.zep", 379);
		return;
	}
	if (Z_TYPE_P(handlers) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0, collection, "islazy", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_0)) {
			ZEPHIR_INIT_VAR(lazyHandler);
			object_init_ex(lazyHandler, phalcon_mvc_micro_lazyloader_ce);
			ZEPHIR_CALL_METHOD(NULL, lazyHandler, "__construct", NULL, 289, mainHandler);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(lazyHandler, mainHandler);
		}
		ZEPHIR_CALL_METHOD(&prefix, collection, "getprefix", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(handlers, &_2, &_1, 0, 0, "phalcon/mvc/micro.zep", 437);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(handler, _3);
			if (Z_TYPE_P(handler) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "One of the registered handlers is invalid", "phalcon/mvc/micro.zep", 401);
				return;
			}
			ZEPHIR_OBS_NVAR(methods);
			zephir_array_fetch_long(&methods, handler, 0, PH_NOISY, "phalcon/mvc/micro.zep", 404 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(pattern);
			zephir_array_fetch_long(&pattern, handler, 1, PH_NOISY, "phalcon/mvc/micro.zep", 405 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(subHandler);
			zephir_array_fetch_long(&subHandler, handler, 2, PH_NOISY, "phalcon/mvc/micro.zep", 406 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(name);
			zephir_array_fetch_long(&name, handler, 3, PH_NOISY, "phalcon/mvc/micro.zep", 407 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(realHandler);
			zephir_create_array(realHandler, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(realHandler, lazyHandler);
			zephir_array_fast_append(realHandler, subHandler);
			if (!(ZEPHIR_IS_EMPTY(prefix))) {
				if (ZEPHIR_IS_STRING(pattern, "/")) {
					ZEPHIR_CPY_WRT(prefixedPattern, prefix);
				} else {
					ZEPHIR_INIT_NVAR(prefixedPattern);
					ZEPHIR_CONCAT_VV(prefixedPattern, prefix, pattern);
				}
			} else {
				ZEPHIR_CPY_WRT(prefixedPattern, pattern);
			}
			ZEPHIR_CALL_METHOD(&route, this_ptr, "map", &_4, 0, prefixedPattern, realHandler);
			zephir_check_call_status();
			_5 = Z_TYPE_P(methods) == IS_STRING;
			if (_5) {
				_5 = !ZEPHIR_IS_STRING(methods, "");
			}
			_6 = _5;
			if (!(_6)) {
				_6 = Z_TYPE_P(methods) == IS_ARRAY;
			}
			if (_6) {
				ZEPHIR_CALL_METHOD(NULL, route, "via", NULL, 0, methods);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(name) == IS_STRING) {
				ZEPHIR_CALL_METHOD(NULL, route, "setname", NULL, 0, name);
				zephir_check_call_status();
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
 * Sets a handler that will be called when an exception is thrown handling the route
 *
 * @param callable handler
 * @return Phalcon\Mvc\Micro
 */
PHP_METHOD(Phalcon_Mvc_Micro, error) {

	zval *handler;

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_this(this_ptr, SL("_errorHandler"), handler TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the internal router used by the application
 */
PHP_METHOD(Phalcon_Mvc_Micro, getRouter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *router = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(router);
	zephir_read_property_this(&router, this_ptr, SL("_router"), PH_NOISY_CC);
	if (Z_TYPE_P(router) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "router", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&router, this_ptr, "getsharedservice", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, router, "clear", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_BOOL(_0, 1);
		ZEPHIR_CALL_METHOD(NULL, router, "removeextraslashes", NULL, 0, _0);
		zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared;
	zval *serviceName_param = NULL, *definition, *shared_param = NULL, *dependencyInjector = NULL;
	zval *serviceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &serviceName_param, &definition, &shared_param);

	if (unlikely(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(serviceName);
		ZVAL_EMPTY_STRING(serviceName);
	}
	if (!shared_param) {
		shared = 0;
	} else {
		shared = zephir_get_boolval(shared_param);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(dependencyInjector);
		object_init_ex(dependencyInjector, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "__construct", NULL, 146);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "set", NULL, 290, serviceName, definition, (shared ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks if a service is registered in the DI
 */
PHP_METHOD(Phalcon_Mvc_Micro, hasService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, *dependencyInjector = NULL;
	zval *serviceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName_param);

	if (unlikely(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(serviceName);
		ZVAL_EMPTY_STRING(serviceName);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(dependencyInjector);
		object_init_ex(dependencyInjector, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "__construct", NULL, 146);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "has", NULL, 291, serviceName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Obtains a service from the DI
 *
 * @param string serviceName
 * @return object
 */
PHP_METHOD(Phalcon_Mvc_Micro, getService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, *dependencyInjector = NULL;
	zval *serviceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName_param);

	if (unlikely(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(serviceName);
		ZVAL_EMPTY_STRING(serviceName);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(dependencyInjector);
		object_init_ex(dependencyInjector, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "__construct", NULL, 146);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "get", NULL, 292, serviceName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Obtains a shared service from the DI
 *
 * @param string serviceName
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, getSharedService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName, *dependencyInjector = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName);



	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(dependencyInjector);
		object_init_ex(dependencyInjector, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "__construct", NULL, 146);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "getshared", NULL, 293, serviceName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Handle the whole request
 *
 * @param string uri
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, handle) {

	zval *_17;
	HashTable *_6, *_10, *_15;
	HashPosition _5, _9, _14;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, *dependencyInjector, *eventsManager = NULL, *status = NULL, *router = NULL, *matchedRoute = NULL, *handler = NULL, *beforeHandlers, *params = NULL, *returnedValue = NULL, *e = NULL, *errorHandler, *afterHandlers, *notFoundHandler, *finishHandlers, *finish = NULL, *before = NULL, *after = NULL, *_0 = NULL, *_1 = NULL, *_2, *_3 = NULL, *_4 = NULL, **_7, *_8, **_11, *_12, *_13 = NULL, **_16;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(status);
	ZVAL_NULL(status);


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "A dependency injection container is required to access required micro services", "phalcon/mvc/micro.zep", 586);
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(returnedValue);
		ZVAL_NULL(returnedValue);
		ZEPHIR_OBS_VAR(eventsManager);
		zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_1);
			ZVAL_STRING(_1, "micro:beforeHandleRoute", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_0, eventsManager, "fire", NULL, 0, _1, this_ptr);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status_or_jump(try_end_1);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "router", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&router, dependencyInjector, "getshared", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, router, "handle", NULL, 0, uri);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&matchedRoute, router, "getmatchedroute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (Z_TYPE_P(matchedRoute) == IS_OBJECT) {
			ZEPHIR_OBS_VAR(handler);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_handlers"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_0, matchedRoute, "getrouteid", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (!(zephir_array_isset_fetch(&handler, _2, _0, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, phalcon_mvc_micro_exception_ce);
				ZEPHIR_INIT_VAR(_3);
				ZVAL_STRING(_3, "Matched route doesn't have an associated handler", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _3);
				zephir_check_temp_parameter(_3);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(_1, "phalcon/mvc/micro.zep", 620 TSRMLS_CC);
				goto try_end_1;

			}
			zephir_update_property_this(this_ptr, SL("_activeHandler"), handler TSRMLS_CC);
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_STRING(_1, "micro:beforeExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_4, eventsManager, "fire", NULL, 0, _1, this_ptr);
				zephir_check_temp_parameter(_1);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_4)) {
					RETURN_MM_BOOL(0);
				} else {
					ZEPHIR_OBS_NVAR(handler);
					zephir_read_property_this(&handler, this_ptr, SL("_activeHandler"), PH_NOISY_CC);
				}
			}
			ZEPHIR_OBS_VAR(beforeHandlers);
			zephir_read_property_this(&beforeHandlers, this_ptr, SL("_beforeHandlers"), PH_NOISY_CC);
			if (Z_TYPE_P(beforeHandlers) == IS_ARRAY) {
				zephir_update_property_this(this_ptr, SL("_stopped"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				zephir_is_iterable(beforeHandlers, &_6, &_5, 0, 0, "phalcon/mvc/micro.zep", 687);
				for (
				  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
				  ; zephir_hash_move_forward_ex(_6, &_5)
				) {
					ZEPHIR_GET_HVALUE(before, _7);
					if (Z_TYPE_P(before) == IS_OBJECT) {
						if (zephir_instance_of_ev(before, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
							ZEPHIR_CALL_METHOD(&status, before, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
							_8 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
							if (zephir_is_true(_8)) {
								break;
							}
							continue;
						}
					}
					if (!(zephir_is_callable(before TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(_1);
						object_init_ex(_1, phalcon_mvc_micro_exception_ce);
						ZEPHIR_INIT_NVAR(_3);
						ZVAL_STRING(_3, "'before' handler is not callable", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _3);
						zephir_check_temp_parameter(_3);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(_1, "phalcon/mvc/micro.zep", 670 TSRMLS_CC);
						goto try_end_1;

					}
					ZEPHIR_INIT_NVAR(_1);
					ZEPHIR_CALL_USER_FUNC(_1, before);
					zephir_check_call_status_or_jump(try_end_1);
					if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
						RETURN_MM_BOOL(0);
					}
					_8 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
					if (zephir_is_true(_8)) {
						RETURN_CCTOR(status);
					}
				}
			}
			ZEPHIR_CALL_METHOD(&params, router, "getparams", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_INIT_NVAR(returnedValue);
			ZEPHIR_CALL_USER_FUNC_ARRAY(returnedValue, handler, params);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_update_property_this(this_ptr, SL("_returnedValue"), returnedValue TSRMLS_CC);
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_STRING(_3, "micro:afterExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _3, this_ptr);
				zephir_check_temp_parameter(_3);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_OBS_VAR(afterHandlers);
			zephir_read_property_this(&afterHandlers, this_ptr, SL("_afterHandlers"), PH_NOISY_CC);
			if (Z_TYPE_P(afterHandlers) == IS_ARRAY) {
				zephir_update_property_this(this_ptr, SL("_stopped"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				zephir_is_iterable(afterHandlers, &_10, &_9, 0, 0, "phalcon/mvc/micro.zep", 742);
				for (
				  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
				  ; zephir_hash_move_forward_ex(_10, &_9)
				) {
					ZEPHIR_GET_HVALUE(after, _11);
					if (Z_TYPE_P(after) == IS_OBJECT) {
						if (zephir_instance_of_ev(after, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
							ZEPHIR_CALL_METHOD(&status, after, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
							_12 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
							if (zephir_is_true(_12)) {
								break;
							}
							continue;
						}
					}
					if (!(zephir_is_callable(after TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(_3);
						object_init_ex(_3, phalcon_mvc_micro_exception_ce);
						ZEPHIR_INIT_NVAR(_13);
						ZVAL_STRING(_13, "One of the 'after' handlers is not callable", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 2, _13);
						zephir_check_temp_parameter(_13);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(_3, "phalcon/mvc/micro.zep", 737 TSRMLS_CC);
						goto try_end_1;

					}
					ZEPHIR_INIT_NVAR(status);
					ZEPHIR_CALL_USER_FUNC(status, after);
					zephir_check_call_status_or_jump(try_end_1);
				}
			}
		} else {
			ZEPHIR_OBS_NVAR(eventsManager);
			zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_STRING(_1, "micro:beforeNotFound", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_0, eventsManager, "fire", NULL, 0, _1, this_ptr);
				zephir_check_temp_parameter(_1);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
					RETURN_MM_BOOL(0);
				}
			}
			ZEPHIR_OBS_VAR(notFoundHandler);
			zephir_read_property_this(&notFoundHandler, this_ptr, SL("_notFoundHandler"), PH_NOISY_CC);
			if (!(zephir_is_callable(notFoundHandler TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, phalcon_mvc_micro_exception_ce);
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_STRING(_3, "Not-Found handler is not callable or is not defined", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _3);
				zephir_check_temp_parameter(_3);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(_1, "phalcon/mvc/micro.zep", 761 TSRMLS_CC);
				goto try_end_1;

			}
			ZEPHIR_INIT_NVAR(returnedValue);
			ZEPHIR_CALL_USER_FUNC(returnedValue, notFoundHandler);
			zephir_check_call_status_or_jump(try_end_1);
		}
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "micro:afterHandleRoute", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _1, this_ptr, returnedValue);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status_or_jump(try_end_1);
		}
		ZEPHIR_OBS_VAR(finishHandlers);
		zephir_read_property_this(&finishHandlers, this_ptr, SL("_finishHandlers"), PH_NOISY_CC);
		if (Z_TYPE_P(finishHandlers) == IS_ARRAY) {
			zephir_update_property_this(this_ptr, SL("_stopped"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			ZEPHIR_INIT_NVAR(params);
			ZVAL_NULL(params);
			zephir_is_iterable(finishHandlers, &_15, &_14, 0, 0, "phalcon/mvc/micro.zep", 832);
			for (
			  ; zephir_hash_get_current_data_ex(_15, (void**) &_16, &_14) == SUCCESS
			  ; zephir_hash_move_forward_ex(_15, &_14)
			) {
				ZEPHIR_GET_HVALUE(finish, _16);
				if (Z_TYPE_P(finish) == IS_OBJECT) {
					if (zephir_instance_of_ev(finish, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
						ZEPHIR_CALL_METHOD(&status, finish, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
						_2 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
						if (zephir_is_true(_2)) {
							break;
						}
						continue;
					}
				}
				if (!(zephir_is_callable(finish TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_1);
					object_init_ex(_1, phalcon_mvc_micro_exception_ce);
					ZEPHIR_INIT_NVAR(_3);
					ZVAL_STRING(_3, "One of the 'finish' handlers is not callable", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _3);
					zephir_check_temp_parameter(_3);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_throw_exception_debug(_1, "phalcon/mvc/micro.zep", 813 TSRMLS_CC);
					goto try_end_1;

				}
				if (Z_TYPE_P(params) == IS_NULL) {
					ZEPHIR_INIT_NVAR(params);
					zephir_create_array(params, 1, 0 TSRMLS_CC);
					zephir_array_fast_append(params, this_ptr);
				}
				ZEPHIR_INIT_NVAR(status);
				ZEPHIR_CALL_USER_FUNC_ARRAY(status, finish, params);
				zephir_check_call_status_or_jump(try_end_1);
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
				if (zephir_is_true(_8)) {
					break;
				}
			}
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_OBS_NVAR(eventsManager);
			zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_STRING(_1, "micro:beforeException", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&returnedValue, eventsManager, "fire", NULL, 0, _1, this_ptr, e);
				zephir_check_temp_parameter(_1);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_VAR(errorHandler);
			zephir_read_property_this(&errorHandler, this_ptr, SL("_errorHandler"), PH_NOISY_CC);
			if (zephir_is_true(errorHandler)) {
				if (!(zephir_is_callable(errorHandler TSRMLS_CC))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Error handler is not callable", "phalcon/mvc/micro.zep", 851);
					return;
				}
				ZEPHIR_INIT_VAR(_17);
				zephir_create_array(_17, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(_17, e);
				ZEPHIR_INIT_NVAR(returnedValue);
				ZEPHIR_CALL_USER_FUNC_ARRAY(returnedValue, errorHandler, _17);
				zephir_check_call_status();
				if (Z_TYPE_P(returnedValue) == IS_OBJECT) {
					if (!(zephir_instance_of_ev(returnedValue, phalcon_http_responseinterface_ce TSRMLS_CC))) {
						zephir_throw_exception_debug(e, "phalcon/mvc/micro.zep", 860 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					if (!ZEPHIR_IS_FALSE_IDENTICAL(returnedValue)) {
						zephir_throw_exception_debug(e, "phalcon/mvc/micro.zep", 864 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				if (!ZEPHIR_IS_FALSE_IDENTICAL(returnedValue)) {
					zephir_throw_exception_debug(e, "phalcon/mvc/micro.zep", 870 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (Z_TYPE_P(returnedValue) == IS_OBJECT) {
		if (zephir_instance_of_ev(returnedValue, phalcon_http_responseinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, returnedValue, "send", NULL, 0);
			zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hasservice", NULL, 0, alias);
	zephir_check_call_status();
	RETURN_MM();

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
PHP_METHOD(Phalcon_Mvc_Micro, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias, *definition;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &alias, &definition);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setservice", NULL, 0, alias, definition);
	zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getservice", NULL, 0, alias);
	zephir_check_call_status();
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



	RETVAL_ZVAL(alias, 1, 0);
	return;

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

