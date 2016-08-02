
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
#include "Zend/zend_closures.h"


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
	zval *dependencyInjector, *_0 = NULL, *_1, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dependencyInjector);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "application", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, dependencyInjector, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "application", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "set", NULL, 0, _2$$3, this_ptr);
		zephir_check_temp_parameter(_2$$3);
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
 * @return \Phalcon\Mvc\Router\RouteInterface
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
 * @return \Phalcon\Mvc\Router\RouteInterface
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
 * @return \Phalcon\Mvc\Router\RouteInterface
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
 * @return \Phalcon\Mvc\Router\RouteInterface
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
 * @return \Phalcon\Mvc\Router\RouteInterface
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
 * @return \Phalcon\Mvc\Router\RouteInterface
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
 * @return \Phalcon\Mvc\Router\RouteInterface
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
 * @return \Phalcon\Mvc\Router\RouteInterface
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

	zend_bool _5$$8, _6$$8;
	HashTable *_2$$5;
	HashPosition _1$$5;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *collection, *mainHandler = NULL, *handlers = NULL, *lazyHandler = NULL, *prefix = NULL, *methods = NULL, *pattern = NULL, *subHandler = NULL, *realHandler = NULL, *prefixedPattern = NULL, *route = NULL, *handler = NULL, *name = NULL, *_0$$5 = NULL, **_3$$5;

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
		ZEPHIR_CALL_METHOD(&_0$$5, collection, "islazy", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_0$$5)) {
			ZEPHIR_INIT_VAR(lazyHandler);
			object_init_ex(lazyHandler, phalcon_mvc_micro_lazyloader_ce);
			ZEPHIR_CALL_METHOD(NULL, lazyHandler, "__construct", NULL, 307, mainHandler);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(lazyHandler, mainHandler);
		}
		ZEPHIR_CALL_METHOD(&prefix, collection, "getprefix", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(handlers, &_2$$5, &_1$$5, 0, 0, "phalcon/mvc/micro.zep", 437);
		for (
		  ; zephir_hash_get_current_data_ex(_2$$5, (void**) &_3$$5, &_1$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2$$5, &_1$$5)
		) {
			ZEPHIR_GET_HVALUE(handler, _3$$5);
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
			_5$$8 = Z_TYPE_P(methods) == IS_STRING;
			if (_5$$8) {
				_5$$8 = !ZEPHIR_IS_STRING(methods, "");
			}
			_6$$8 = _5$$8;
			if (!(_6$$8)) {
				_6$$8 = Z_TYPE_P(methods) == IS_ARRAY;
			}
			if (_6$$8) {
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
 * @return \Phalcon\Mvc\Micro
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
 * @return \Phalcon\Mvc\Micro
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

	zval *router = NULL, *_0$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(router);
	zephir_read_property_this(&router, this_ptr, SL("_router"), PH_NOISY_CC);
	if (Z_TYPE_P(router) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "router", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&router, this_ptr, "getsharedservice", NULL, 0, _0$$3);
		zephir_check_temp_parameter(_0$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, router, "clear", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0$$3);
		ZVAL_BOOL(_0$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, router, "removeextraslashes", NULL, 0, _0$$3);
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
 * @return \Phalcon\Di\ServiceInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, setService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared;
	zval *serviceName_param = NULL, *definition, *shared_param = NULL, *dependencyInjector = NULL, *_0;
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
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "__construct", NULL, 180);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	if (shared) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "set", NULL, 308, serviceName, definition, _0);
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
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "__construct", NULL, 180);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "has", NULL, 309, serviceName);
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
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "__construct", NULL, 180);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "get", NULL, 310, serviceName);
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
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "__construct", NULL, 180);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "getshared", NULL, 311, serviceName);
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

	zval *_41$$43;
	zend_class_entry *_20$$20;
	HashTable *_11$$12, *_23$$22, *_34$$33;
	HashPosition _10$$12, _22$$22, _33$$33;
	zend_bool _18$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, *dependencyInjector = NULL, *eventsManager = NULL, *status = NULL, *router = NULL, *matchedRoute = NULL, *handler = NULL, *beforeHandlers = NULL, *params = NULL, *returnedValue = NULL, *e = NULL, *errorHandler = NULL, *afterHandlers = NULL, *notFoundHandler = NULL, *finishHandlers = NULL, *finish = NULL, *before = NULL, *after = NULL, *response = NULL, *_0$$5 = NULL, *_1$$5, *_2$$4 = NULL, *_3$$4, *_4$$7, *_5$$7 = NULL, *_6$$8, *_7$$8, *_8$$9 = NULL, *_9$$9, **_12$$12, *_13$$15, *_14$$17 = NULL, *_15$$17 = NULL, *_16$$13 = NULL, *_17$$13, *_19$$20 = NULL, *_21$$21, **_24$$22, *_25$$25, *_26$$27 = NULL, *_27$$27 = NULL, *_28$$29 = NULL, *_29$$29, *_30$$31, *_31$$31, *_32$$32, **_35$$33, *_36$$36, *_37$$38 = NULL, *_38$$38 = NULL, *_39$$34, *_40$$42, *_42$$51 = NULL, *_43$$51;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "A dependency injection container is required to access required micro services", "phalcon/mvc/micro.zep", 587);
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(returnedValue);
		ZVAL_NULL(returnedValue);
		ZEPHIR_OBS_VAR(eventsManager);
		zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_1$$5);
			ZVAL_STRING(_1$$5, "micro:beforeHandleRoute", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_0$$5, eventsManager, "fire", NULL, 0, _1$$5, this_ptr);
			zephir_check_temp_parameter(_1$$5);
			zephir_check_call_status_or_jump(try_end_1);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_0$$5)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_STRING(_3$$4, "router", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2$$4, dependencyInjector, "getshared", NULL, 0, _3$$4);
		zephir_check_temp_parameter(_3$$4);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(router, _2$$4);
		ZEPHIR_CALL_METHOD(NULL, router, "handle", NULL, 0, uri);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&matchedRoute, router, "getmatchedroute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (Z_TYPE_P(matchedRoute) == IS_OBJECT) {
			ZEPHIR_OBS_VAR(handler);
			_4$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_handlers"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_5$$7, matchedRoute, "getrouteid", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (!(zephir_array_isset_fetch(&handler, _4$$7, _5$$7, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_6$$8);
				object_init_ex(_6$$8, phalcon_mvc_micro_exception_ce);
				ZEPHIR_INIT_VAR(_7$$8);
				ZVAL_STRING(_7$$8, "Matched route doesn't have an associated handler", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _6$$8, "__construct", NULL, 9, _7$$8);
				zephir_check_temp_parameter(_7$$8);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(_6$$8, "phalcon/mvc/micro.zep", 621 TSRMLS_CC);
				goto try_end_1;

			}
			zephir_update_property_this(this_ptr, SL("_activeHandler"), handler TSRMLS_CC);
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(_9$$9);
				ZVAL_STRING(_9$$9, "micro:beforeExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_8$$9, eventsManager, "fire", NULL, 0, _9$$9, this_ptr);
				zephir_check_temp_parameter(_9$$9);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_8$$9)) {
					RETURN_MM_BOOL(0);
				} else {
					ZEPHIR_OBS_NVAR(handler);
					zephir_read_property_this(&handler, this_ptr, SL("_activeHandler"), PH_NOISY_CC);
				}
			}
			ZEPHIR_OBS_VAR(beforeHandlers);
			zephir_read_property_this(&beforeHandlers, this_ptr, SL("_beforeHandlers"), PH_NOISY_CC);
			if (Z_TYPE_P(beforeHandlers) == IS_ARRAY) {
				if (0) {
					zephir_update_property_this(this_ptr, SL("_stopped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
				} else {
					zephir_update_property_this(this_ptr, SL("_stopped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				}
				zephir_is_iterable(beforeHandlers, &_11$$12, &_10$$12, 0, 0, "phalcon/mvc/micro.zep", 688);
				for (
				  ; zephir_hash_get_current_data_ex(_11$$12, (void**) &_12$$12, &_10$$12) == SUCCESS
				  ; zephir_hash_move_forward_ex(_11$$12, &_10$$12)
				) {
					ZEPHIR_GET_HVALUE(before, _12$$12);
					if (Z_TYPE_P(before) == IS_OBJECT) {
						if (zephir_instance_of_ev(before, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
							ZEPHIR_CALL_METHOD(&status, before, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
							_13$$15 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
							if (zephir_is_true(_13$$15)) {
								break;
							}
							continue;
						}
					}
					if (!(zephir_is_callable(before TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(_14$$17);
						object_init_ex(_14$$17, phalcon_mvc_micro_exception_ce);
						ZEPHIR_INIT_NVAR(_15$$17);
						ZVAL_STRING(_15$$17, "'before' handler is not callable", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, _14$$17, "__construct", NULL, 9, _15$$17);
						zephir_check_temp_parameter(_15$$17);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(_14$$17, "phalcon/mvc/micro.zep", 671 TSRMLS_CC);
						goto try_end_1;

					}
					ZEPHIR_INIT_NVAR(_16$$13);
					ZEPHIR_CALL_USER_FUNC(_16$$13, before);
					zephir_check_call_status_or_jump(try_end_1);
					if (ZEPHIR_IS_FALSE_IDENTICAL(_16$$13)) {
						RETURN_MM_BOOL(0);
					}
					_17$$13 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
					if (zephir_is_true(_17$$13)) {
						RETURN_CCTOR(status);
					}
				}
			}
			ZEPHIR_CALL_METHOD(&params, router, "getparams", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			_18$$7 = Z_TYPE_P(handler) == IS_OBJECT;
			if (_18$$7) {
				_18$$7 = zephir_instance_of_ev(handler, zend_ce_closure TSRMLS_CC);
			}
			if (_18$$7) {
					_20$$20 = zend_fetch_class(SL("Closure"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				ZEPHIR_CALL_CE_STATIC(&_19$$20, _20$$20, "bind", NULL, 0, handler, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(handler, _19$$20);
			}
			ZEPHIR_INIT_NVAR(returnedValue);
			ZEPHIR_CALL_USER_FUNC_ARRAY(returnedValue, handler, params);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_update_property_this(this_ptr, SL("_returnedValue"), returnedValue TSRMLS_CC);
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(_21$$21);
				ZVAL_STRING(_21$$21, "micro:afterExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _21$$21, this_ptr);
				zephir_check_temp_parameter(_21$$21);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_OBS_VAR(afterHandlers);
			zephir_read_property_this(&afterHandlers, this_ptr, SL("_afterHandlers"), PH_NOISY_CC);
			if (Z_TYPE_P(afterHandlers) == IS_ARRAY) {
				if (0) {
					zephir_update_property_this(this_ptr, SL("_stopped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
				} else {
					zephir_update_property_this(this_ptr, SL("_stopped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				}
				zephir_is_iterable(afterHandlers, &_23$$22, &_22$$22, 0, 0, "phalcon/mvc/micro.zep", 751);
				for (
				  ; zephir_hash_get_current_data_ex(_23$$22, (void**) &_24$$22, &_22$$22) == SUCCESS
				  ; zephir_hash_move_forward_ex(_23$$22, &_22$$22)
				) {
					ZEPHIR_GET_HVALUE(after, _24$$22);
					if (Z_TYPE_P(after) == IS_OBJECT) {
						if (zephir_instance_of_ev(after, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
							ZEPHIR_CALL_METHOD(&status, after, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
							_25$$25 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
							if (zephir_is_true(_25$$25)) {
								break;
							}
							continue;
						}
					}
					if (!(zephir_is_callable(after TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(_26$$27);
						object_init_ex(_26$$27, phalcon_mvc_micro_exception_ce);
						ZEPHIR_INIT_NVAR(_27$$27);
						ZVAL_STRING(_27$$27, "One of the 'after' handlers is not callable", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, _26$$27, "__construct", NULL, 9, _27$$27);
						zephir_check_temp_parameter(_27$$27);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(_26$$27, "phalcon/mvc/micro.zep", 746 TSRMLS_CC);
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
				ZEPHIR_INIT_VAR(_29$$29);
				ZVAL_STRING(_29$$29, "micro:beforeNotFound", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_28$$29, eventsManager, "fire", NULL, 0, _29$$29, this_ptr);
				zephir_check_temp_parameter(_29$$29);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_28$$29)) {
					RETURN_MM_BOOL(0);
				}
			}
			ZEPHIR_OBS_VAR(notFoundHandler);
			zephir_read_property_this(&notFoundHandler, this_ptr, SL("_notFoundHandler"), PH_NOISY_CC);
			if (!(zephir_is_callable(notFoundHandler TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_30$$31);
				object_init_ex(_30$$31, phalcon_mvc_micro_exception_ce);
				ZEPHIR_INIT_VAR(_31$$31);
				ZVAL_STRING(_31$$31, "Not-Found handler is not callable or is not defined", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _30$$31, "__construct", NULL, 9, _31$$31);
				zephir_check_temp_parameter(_31$$31);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(_30$$31, "phalcon/mvc/micro.zep", 770 TSRMLS_CC);
				goto try_end_1;

			}
			ZEPHIR_INIT_NVAR(returnedValue);
			ZEPHIR_CALL_USER_FUNC(returnedValue, notFoundHandler);
			zephir_check_call_status_or_jump(try_end_1);
		}
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_32$$32);
			ZVAL_STRING(_32$$32, "micro:afterHandleRoute", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _32$$32, this_ptr, returnedValue);
			zephir_check_temp_parameter(_32$$32);
			zephir_check_call_status_or_jump(try_end_1);
		}
		ZEPHIR_OBS_VAR(finishHandlers);
		zephir_read_property_this(&finishHandlers, this_ptr, SL("_finishHandlers"), PH_NOISY_CC);
		if (Z_TYPE_P(finishHandlers) == IS_ARRAY) {
			if (0) {
				zephir_update_property_this(this_ptr, SL("_stopped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_this(this_ptr, SL("_stopped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
			ZEPHIR_INIT_NVAR(params);
			ZVAL_NULL(params);
			zephir_is_iterable(finishHandlers, &_34$$33, &_33$$33, 0, 0, "phalcon/mvc/micro.zep", 841);
			for (
			  ; zephir_hash_get_current_data_ex(_34$$33, (void**) &_35$$33, &_33$$33) == SUCCESS
			  ; zephir_hash_move_forward_ex(_34$$33, &_33$$33)
			) {
				ZEPHIR_GET_HVALUE(finish, _35$$33);
				if (Z_TYPE_P(finish) == IS_OBJECT) {
					if (zephir_instance_of_ev(finish, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
						ZEPHIR_CALL_METHOD(&status, finish, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
						_36$$36 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
						if (zephir_is_true(_36$$36)) {
							break;
						}
						continue;
					}
				}
				if (!(zephir_is_callable(finish TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_37$$38);
					object_init_ex(_37$$38, phalcon_mvc_micro_exception_ce);
					ZEPHIR_INIT_NVAR(_38$$38);
					ZVAL_STRING(_38$$38, "One of the 'finish' handlers is not callable", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, _37$$38, "__construct", NULL, 9, _38$$38);
					zephir_check_temp_parameter(_38$$38);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_throw_exception_debug(_37$$38, "phalcon/mvc/micro.zep", 822 TSRMLS_CC);
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
				_39$$34 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
				if (zephir_is_true(_39$$34)) {
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
				ZEPHIR_INIT_VAR(_40$$42);
				ZVAL_STRING(_40$$42, "micro:beforeException", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&returnedValue, eventsManager, "fire", NULL, 0, _40$$42, this_ptr, e);
				zephir_check_temp_parameter(_40$$42);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_VAR(errorHandler);
			zephir_read_property_this(&errorHandler, this_ptr, SL("_errorHandler"), PH_NOISY_CC);
			if (zephir_is_true(errorHandler)) {
				if (!(zephir_is_callable(errorHandler TSRMLS_CC))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Error handler is not callable", "phalcon/mvc/micro.zep", 860);
					return;
				}
				ZEPHIR_INIT_VAR(_41$$43);
				zephir_create_array(_41$$43, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(_41$$43, e);
				ZEPHIR_INIT_NVAR(returnedValue);
				ZEPHIR_CALL_USER_FUNC_ARRAY(returnedValue, errorHandler, _41$$43);
				zephir_check_call_status();
				if (Z_TYPE_P(returnedValue) == IS_OBJECT) {
					if (!(zephir_instance_of_ev(returnedValue, phalcon_http_responseinterface_ce TSRMLS_CC))) {
						zephir_throw_exception_debug(e, "phalcon/mvc/micro.zep", 869 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					if (!ZEPHIR_IS_FALSE_IDENTICAL(returnedValue)) {
						zephir_throw_exception_debug(e, "phalcon/mvc/micro.zep", 873 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				if (!ZEPHIR_IS_FALSE_IDENTICAL(returnedValue)) {
					zephir_throw_exception_debug(e, "phalcon/mvc/micro.zep", 879 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (Z_TYPE_P(returnedValue) == IS_STRING) {
		ZEPHIR_INIT_VAR(_43$$51);
		ZVAL_STRING(_43$$51, "response", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_42$$51, dependencyInjector, "getshared", NULL, 0, _43$$51);
		zephir_check_temp_parameter(_43$$51);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(response, _42$$51);
		ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, 0, returnedValue);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, response, "send", NULL, 0);
		zephir_check_call_status();
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

	

	if (1) {
		zephir_update_property_this(this_ptr, SL("_stopped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_stopped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}

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
 * @return \Phalcon\Mvc\Micro
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
 * @return \Phalcon\Mvc\Micro
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
 * @return \Phalcon\Mvc\Micro
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

