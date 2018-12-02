
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
 * $app = new \Phalcon\Mvc\Micro();
 *
 * $app->get(
 *     "/say/welcome/{name}",
 *     function ($name) {
 *         echo "<h1>Welcome $name!</h1>";
 *     }
 * );
 *
 * $app->handle();
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

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_modelBinder"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_afterBindingHandlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_micro_ce->create_object = zephir_init_properties_Phalcon_Mvc_Micro;

	zend_class_implements(phalcon_mvc_micro_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Micro constructor
 */
PHP_METHOD(Phalcon_Mvc_Micro, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
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
	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *router = NULL, *route = NULL, *_0 = NULL;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, *mainHandler = NULL, *handlers = NULL, *lazyHandler = NULL, *prefix = NULL, *methods = NULL, *pattern = NULL, *subHandler = NULL, *realHandler = NULL, *prefixedPattern = NULL, *route = NULL, *handler = NULL, *name = NULL, *_0$$5 = NULL, **_3$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection);



	ZEPHIR_CALL_METHOD(&mainHandler, collection, "gethandler", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(mainHandler)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Collection requires a main handler", "phalcon/mvc/micro.zep", 378);
		return;
	}
	ZEPHIR_CALL_METHOD(&handlers, collection, "gethandlers", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(handlers TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "There are no handlers to mount", "phalcon/mvc/micro.zep", 383);
		return;
	}
	if (Z_TYPE_P(handlers) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0$$5, collection, "islazy", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_0$$5)) {
			ZEPHIR_INIT_VAR(lazyHandler);
			object_init_ex(lazyHandler, phalcon_mvc_micro_lazyloader_ce);
			ZEPHIR_CALL_METHOD(NULL, lazyHandler, "__construct", NULL, 325, mainHandler);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(lazyHandler, mainHandler);
		}
		ZEPHIR_CALL_METHOD(&prefix, collection, "getprefix", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(handlers, &_2$$5, &_1$$5, 0, 0, "phalcon/mvc/micro.zep", 441);
		for (
		  ; zend_hash_get_current_data_ex(_2$$5, (void**) &_3$$5, &_1$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_2$$5, &_1$$5)
		) {
			ZEPHIR_GET_HVALUE(handler, _3$$5);
			if (Z_TYPE_P(handler) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "One of the registered handlers is invalid", "phalcon/mvc/micro.zep", 405);
				return;
			}
			ZEPHIR_OBS_NVAR(methods);
			zephir_array_fetch_long(&methods, handler, 0, PH_NOISY, "phalcon/mvc/micro.zep", 408 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(pattern);
			zephir_array_fetch_long(&pattern, handler, 1, PH_NOISY, "phalcon/mvc/micro.zep", 409 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(subHandler);
			zephir_array_fetch_long(&subHandler, handler, 2, PH_NOISY, "phalcon/mvc/micro.zep", 410 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(name);
			zephir_array_fetch_long(&name, handler, 3, PH_NOISY, "phalcon/mvc/micro.zep", 411 TSRMLS_CC);
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



	zephir_update_property_this(getThis(), SL("_notFoundHandler"), handler TSRMLS_CC);
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



	zephir_update_property_this(getThis(), SL("_errorHandler"), handler TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the internal router used by the application
 */
PHP_METHOD(Phalcon_Mvc_Micro, getRouter) {

	zval *router = NULL, *_0$$3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

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
		zephir_update_property_this(getThis(), SL("_router"), router TSRMLS_CC);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared;
	zval *serviceName_param = NULL, *definition, *shared_param = NULL, *dependencyInjector = NULL, *_0;
	zval *serviceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &serviceName_param, &definition, &shared_param);

	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
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
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "__construct", NULL, 197);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	if (shared) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "set", NULL, 326, serviceName, definition, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks if a service is registered in the DI
 */
PHP_METHOD(Phalcon_Mvc_Micro, hasService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, *dependencyInjector = NULL;
	zval *serviceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName_param);

	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
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
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "__construct", NULL, 197);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "has", NULL, 327, serviceName);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, *dependencyInjector = NULL;
	zval *serviceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName_param);

	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
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
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "__construct", NULL, 197);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "get", NULL, 328, serviceName);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName, *dependencyInjector = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName);



	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(dependencyInjector);
		object_init_ex(dependencyInjector, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "__construct", NULL, 197);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "getshared", NULL, 329, serviceName);
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

	zval *_60$$60;
	zend_class_entry *_20$$20;
	HashTable *_11$$12, *_30$$30, *_40$$38, *_52$$50;
	HashPosition _10$$12, _29$$30, _39$$38, _51$$50;
	zend_bool _18$$7, _26$$7, _23$$24, _32$$31;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, *dependencyInjector = NULL, *eventsManager = NULL, *status = NULL, *router = NULL, *matchedRoute = NULL, *handler = NULL, *beforeHandlers = NULL, *params = NULL, *returnedValue = NULL, *e = NULL, *errorHandler = NULL, *afterHandlers = NULL, *notFoundHandler = NULL, *finishHandlers = NULL, *finish = NULL, *before = NULL, *after = NULL, *response = NULL, *modelBinder = NULL, *bindCacheKey = NULL, *routeName = NULL, *realHandler = NULL, *methodName = NULL, *lazyReturned = NULL, *afterBindingHandlers = NULL, *afterBinding = NULL, *_58, *_0$$5 = NULL, *_1$$5, *_2$$4 = NULL, *_3$$4, *_4$$7, *_5$$7 = NULL, *_6$$8, *_7$$8, *_8$$9 = NULL, *_9$$9, **_12$$12, *_17$$12, *_13$$15, *_14$$17 = NULL, *_15$$17 = NULL, *_16$$13, *_19$$20 = NULL, *_21$$23 = NULL, *_22$$21 = NULL, *_24$$25, *_25$$25 = NULL, *_27$$28 = NULL, *_28$$28, **_31$$30, *_37$$30, *_36$$31, *_33$$32, *_34$$34 = NULL, *_35$$34 = NULL, *_38$$37, **_41$$38, *_42$$41, *_43$$43 = NULL, *_44$$43 = NULL, *_45$$39, *_46$$46 = NULL, *_47$$46, *_48$$48, *_49$$48, *_50$$49, **_53$$50, *_54$$53, *_55$$55 = NULL, *_56$$55 = NULL, *_57$$51, *_59$$59, *_61$$68 = NULL, *_62$$68, *_63$$71 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(status);
	ZVAL_NULL(status);
	ZEPHIR_INIT_VAR(realHandler);
	ZVAL_NULL(realHandler);
	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "A dependency injection container is required to access required micro services", "phalcon/mvc/micro.zep", 592);
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
				zephir_throw_exception_debug(_6$$8, "phalcon/mvc/micro.zep", 626 TSRMLS_CC);
				goto try_end_1;

			}
			zephir_update_property_this(getThis(), SL("_activeHandler"), handler TSRMLS_CC);
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
					zephir_update_property_this(getThis(), SL("_stopped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
				} else {
					zephir_update_property_this(getThis(), SL("_stopped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				}
				zephir_is_iterable(beforeHandlers, &_11$$12, &_10$$12, 0, 0, "phalcon/mvc/micro.zep", 694);
				for (
				  ; zend_hash_get_current_data_ex(_11$$12, (void**) &_12$$12, &_10$$12) == SUCCESS
				  ; zend_hash_move_forward_ex(_11$$12, &_10$$12)
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
						zephir_throw_exception_debug(_14$$17, "phalcon/mvc/micro.zep", 676 TSRMLS_CC);
						goto try_end_1;

					}
					ZEPHIR_INIT_NVAR(status);
					ZEPHIR_CALL_USER_FUNC(status, before);
					zephir_check_call_status_or_jump(try_end_1);
					_16$$13 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
					if (zephir_is_true(_16$$13)) {
						break;
					}
				}
				_17$$12 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
				if (zephir_is_true(_17$$12)) {
					RETURN_CCTOR(status);
				}
			}
			ZEPHIR_CALL_METHOD(&params, router, "getparams", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_OBS_VAR(modelBinder);
			zephir_read_property_this(&modelBinder, this_ptr, SL("_modelBinder"), PH_NOISY_CC);
			_18$$7 = Z_TYPE_P(handler) == IS_OBJECT;
			if (_18$$7) {
				_18$$7 = zephir_instance_of_ev(handler, zend_ce_closure TSRMLS_CC);
			}
			if (_18$$7) {
					_20$$20 = zend_fetch_class(SL("Closure"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				ZEPHIR_CALL_CE_STATIC(&_19$$20, _20$$20, "bind", NULL, 0, handler, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(handler, _19$$20);
				if (Z_TYPE_P(modelBinder) != IS_NULL) {
					ZEPHIR_CALL_METHOD(&routeName, matchedRoute, "getname", NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_INIT_VAR(bindCacheKey);
					if (Z_TYPE_P(routeName) != IS_NULL) {
						ZEPHIR_CONCAT_SV(bindCacheKey, "_PHMB_", routeName);
					} else {
						ZEPHIR_CALL_METHOD(&_21$$23, matchedRoute, "getpattern", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						ZEPHIR_CONCAT_SV(bindCacheKey, "_PHMB_", _21$$23);
					}
					ZEPHIR_CALL_METHOD(&_22$$21, modelBinder, "bindtohandler", NULL, 0, handler, params, bindCacheKey);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(params, _22$$21);
				}
			}
			if (Z_TYPE_P(handler) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(realHandler);
				zephir_array_fetch_long(&realHandler, handler, 0, PH_NOISY, "phalcon/mvc/micro.zep", 725 TSRMLS_CC);
				_23$$24 = zephir_instance_of_ev(realHandler, phalcon_mvc_controller_ce TSRMLS_CC);
				if (_23$$24) {
					_23$$24 = Z_TYPE_P(modelBinder) != IS_NULL;
				}
				if (_23$$24) {
					ZEPHIR_OBS_VAR(methodName);
					zephir_array_fetch_long(&methodName, handler, 1, PH_NOISY, "phalcon/mvc/micro.zep", 728 TSRMLS_CC);
					ZEPHIR_INIT_VAR(_24$$25);
					zephir_get_class(_24$$25, realHandler, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(bindCacheKey);
					ZEPHIR_CONCAT_SVSV(bindCacheKey, "_PHMB_", _24$$25, "_", methodName);
					ZEPHIR_CALL_METHOD(&_25$$25, modelBinder, "bindtohandler", NULL, 0, realHandler, params, bindCacheKey, methodName);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(params, _25$$25);
				}
			}
			_26$$7 = Z_TYPE_P(realHandler) != IS_NULL;
			if (_26$$7) {
				_26$$7 = zephir_instance_of_ev(realHandler, phalcon_mvc_micro_lazyloader_ce TSRMLS_CC);
			}
			if (_26$$7) {
				ZEPHIR_OBS_NVAR(methodName);
				zephir_array_fetch_long(&methodName, handler, 1, PH_NOISY, "phalcon/mvc/micro.zep", 738 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&lazyReturned, realHandler, "callmethod", NULL, 0, methodName, params, modelBinder);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(returnedValue, lazyReturned);
			} else {
				ZEPHIR_INIT_NVAR(returnedValue);
				ZEPHIR_CALL_USER_FUNC_ARRAY(returnedValue, handler, params);
				zephir_check_call_status_or_jump(try_end_1);
			}
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(_28$$28);
				ZVAL_STRING(_28$$28, "micro:afterBinding", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_27$$28, eventsManager, "fire", NULL, 0, _28$$28, this_ptr);
				zephir_check_temp_parameter(_28$$28);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_27$$28)) {
					RETURN_MM_BOOL(0);
				}
			}
			ZEPHIR_OBS_VAR(afterBindingHandlers);
			zephir_read_property_this(&afterBindingHandlers, this_ptr, SL("_afterBindingHandlers"), PH_NOISY_CC);
			if (Z_TYPE_P(afterBindingHandlers) == IS_ARRAY) {
				if (0) {
					zephir_update_property_this(getThis(), SL("_stopped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
				} else {
					zephir_update_property_this(getThis(), SL("_stopped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				}
				zephir_is_iterable(afterBindingHandlers, &_30$$30, &_29$$30, 0, 0, "phalcon/mvc/micro.zep", 803);
				for (
				  ; zend_hash_get_current_data_ex(_30$$30, (void**) &_31$$30, &_29$$30) == SUCCESS
				  ; zend_hash_move_forward_ex(_30$$30, &_29$$30)
				) {
					ZEPHIR_GET_HVALUE(afterBinding, _31$$30);
					_32$$31 = Z_TYPE_P(afterBinding) == IS_OBJECT;
					if (_32$$31) {
						_32$$31 = zephir_instance_of_ev(afterBinding, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC);
					}
					if (_32$$31) {
						ZEPHIR_CALL_METHOD(&status, afterBinding, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
						_33$$32 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
						if (zephir_is_true(_33$$32)) {
							break;
						}
						continue;
					}
					if (!(zephir_is_callable(afterBinding TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(_34$$34);
						object_init_ex(_34$$34, phalcon_mvc_micro_exception_ce);
						ZEPHIR_INIT_NVAR(_35$$34);
						ZVAL_STRING(_35$$34, "'afterBinding' handler is not callable", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, _34$$34, "__construct", NULL, 9, _35$$34);
						zephir_check_temp_parameter(_35$$34);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(_34$$34, "phalcon/mvc/micro.zep", 785 TSRMLS_CC);
						goto try_end_1;

					}
					ZEPHIR_INIT_NVAR(status);
					ZEPHIR_CALL_USER_FUNC(status, afterBinding);
					zephir_check_call_status_or_jump(try_end_1);
					_36$$31 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
					if (zephir_is_true(_36$$31)) {
						break;
					}
				}
				_37$$30 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
				if (zephir_is_true(_37$$30)) {
					RETURN_CCTOR(status);
				}
			}
			zephir_update_property_this(getThis(), SL("_returnedValue"), returnedValue TSRMLS_CC);
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(_38$$37);
				ZVAL_STRING(_38$$37, "micro:afterExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _38$$37, this_ptr);
				zephir_check_temp_parameter(_38$$37);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_OBS_VAR(afterHandlers);
			zephir_read_property_this(&afterHandlers, this_ptr, SL("_afterHandlers"), PH_NOISY_CC);
			if (Z_TYPE_P(afterHandlers) == IS_ARRAY) {
				if (0) {
					zephir_update_property_this(getThis(), SL("_stopped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
				} else {
					zephir_update_property_this(getThis(), SL("_stopped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				}
				zephir_is_iterable(afterHandlers, &_40$$38, &_39$$38, 0, 0, "phalcon/mvc/micro.zep", 862);
				for (
				  ; zend_hash_get_current_data_ex(_40$$38, (void**) &_41$$38, &_39$$38) == SUCCESS
				  ; zend_hash_move_forward_ex(_40$$38, &_39$$38)
				) {
					ZEPHIR_GET_HVALUE(after, _41$$38);
					if (Z_TYPE_P(after) == IS_OBJECT) {
						if (zephir_instance_of_ev(after, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
							ZEPHIR_CALL_METHOD(&status, after, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
							_42$$41 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
							if (zephir_is_true(_42$$41)) {
								break;
							}
							continue;
						}
					}
					if (!(zephir_is_callable(after TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(_43$$43);
						object_init_ex(_43$$43, phalcon_mvc_micro_exception_ce);
						ZEPHIR_INIT_NVAR(_44$$43);
						ZVAL_STRING(_44$$43, "One of the 'after' handlers is not callable", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, _43$$43, "__construct", NULL, 9, _44$$43);
						zephir_check_temp_parameter(_44$$43);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(_43$$43, "phalcon/mvc/micro.zep", 850 TSRMLS_CC);
						goto try_end_1;

					}
					ZEPHIR_INIT_NVAR(status);
					ZEPHIR_CALL_USER_FUNC(status, after);
					zephir_check_call_status_or_jump(try_end_1);
					_45$$39 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
					if (zephir_is_true(_45$$39)) {
						break;
					}
				}
			}
		} else {
			ZEPHIR_OBS_NVAR(eventsManager);
			zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(_47$$46);
				ZVAL_STRING(_47$$46, "micro:beforeNotFound", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_46$$46, eventsManager, "fire", NULL, 0, _47$$46, this_ptr);
				zephir_check_temp_parameter(_47$$46);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_46$$46)) {
					RETURN_MM_BOOL(0);
				}
			}
			ZEPHIR_OBS_VAR(notFoundHandler);
			zephir_read_property_this(&notFoundHandler, this_ptr, SL("_notFoundHandler"), PH_NOISY_CC);
			if (!(zephir_is_callable(notFoundHandler TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_48$$48);
				object_init_ex(_48$$48, phalcon_mvc_micro_exception_ce);
				ZEPHIR_INIT_VAR(_49$$48);
				ZVAL_STRING(_49$$48, "Not-Found handler is not callable or is not defined", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _48$$48, "__construct", NULL, 9, _49$$48);
				zephir_check_temp_parameter(_49$$48);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(_48$$48, "phalcon/mvc/micro.zep", 881 TSRMLS_CC);
				goto try_end_1;

			}
			ZEPHIR_INIT_NVAR(returnedValue);
			ZEPHIR_CALL_USER_FUNC(returnedValue, notFoundHandler);
			zephir_check_call_status_or_jump(try_end_1);
		}
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_50$$49);
			ZVAL_STRING(_50$$49, "micro:afterHandleRoute", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _50$$49, this_ptr, returnedValue);
			zephir_check_temp_parameter(_50$$49);
			zephir_check_call_status_or_jump(try_end_1);
		}
		ZEPHIR_OBS_VAR(finishHandlers);
		zephir_read_property_this(&finishHandlers, this_ptr, SL("_finishHandlers"), PH_NOISY_CC);
		if (Z_TYPE_P(finishHandlers) == IS_ARRAY) {
			if (0) {
				zephir_update_property_this(getThis(), SL("_stopped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_this(getThis(), SL("_stopped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
			ZEPHIR_INIT_NVAR(params);
			ZVAL_NULL(params);
			zephir_is_iterable(finishHandlers, &_52$$50, &_51$$50, 0, 0, "phalcon/mvc/micro.zep", 952);
			for (
			  ; zend_hash_get_current_data_ex(_52$$50, (void**) &_53$$50, &_51$$50) == SUCCESS
			  ; zend_hash_move_forward_ex(_52$$50, &_51$$50)
			) {
				ZEPHIR_GET_HVALUE(finish, _53$$50);
				if (Z_TYPE_P(finish) == IS_OBJECT) {
					if (zephir_instance_of_ev(finish, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
						ZEPHIR_CALL_METHOD(&status, finish, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
						_54$$53 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
						if (zephir_is_true(_54$$53)) {
							break;
						}
						continue;
					}
				}
				if (!(zephir_is_callable(finish TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_55$$55);
					object_init_ex(_55$$55, phalcon_mvc_micro_exception_ce);
					ZEPHIR_INIT_NVAR(_56$$55);
					ZVAL_STRING(_56$$55, "One of the 'finish' handlers is not callable", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, _55$$55, "__construct", NULL, 9, _56$$55);
					zephir_check_temp_parameter(_56$$55);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_throw_exception_debug(_55$$55, "phalcon/mvc/micro.zep", 933 TSRMLS_CC);
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
				_57$$51 = zephir_fetch_nproperty_this(this_ptr, SL("_stopped"), PH_NOISY_CC);
				if (zephir_is_true(_57$$51)) {
					break;
				}
			}
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(_58);
		ZEPHIR_CPY_WRT(_58, EG(exception));
		if (zephir_instance_of_ev(_58, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(e, _58);
			ZEPHIR_OBS_NVAR(eventsManager);
			zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(_59$$59);
				ZVAL_STRING(_59$$59, "micro:beforeException", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&returnedValue, eventsManager, "fire", NULL, 0, _59$$59, this_ptr, e);
				zephir_check_temp_parameter(_59$$59);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_VAR(errorHandler);
			zephir_read_property_this(&errorHandler, this_ptr, SL("_errorHandler"), PH_NOISY_CC);
			if (zephir_is_true(errorHandler)) {
				if (!(zephir_is_callable(errorHandler TSRMLS_CC))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Error handler is not callable", "phalcon/mvc/micro.zep", 971);
					return;
				}
				ZEPHIR_INIT_VAR(_60$$60);
				zephir_create_array(_60$$60, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(_60$$60, e);
				ZEPHIR_INIT_NVAR(returnedValue);
				ZEPHIR_CALL_USER_FUNC_ARRAY(returnedValue, errorHandler, _60$$60);
				zephir_check_call_status();
				if (Z_TYPE_P(returnedValue) == IS_OBJECT) {
					if (!(zephir_instance_of_ev(returnedValue, phalcon_http_responseinterface_ce TSRMLS_CC))) {
						zephir_throw_exception_debug(e, "phalcon/mvc/micro.zep", 980 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					if (!ZEPHIR_IS_FALSE_IDENTICAL(returnedValue)) {
						zephir_throw_exception_debug(e, "phalcon/mvc/micro.zep", 984 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				if (!ZEPHIR_IS_FALSE_IDENTICAL(returnedValue)) {
					zephir_throw_exception_debug(e, "phalcon/mvc/micro.zep", 990 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (Z_TYPE_P(returnedValue) == IS_STRING) {
		ZEPHIR_INIT_VAR(_62$$68);
		ZVAL_STRING(_62$$68, "response", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_61$$68, dependencyInjector, "getshared", NULL, 0, _62$$68);
		zephir_check_temp_parameter(_62$$68);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(response, _61$$68);
		ZEPHIR_CALL_METHOD(&_61$$68, response, "issent", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_61$$68))) {
			ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, 0, returnedValue);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, response, "send", NULL, 0);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(returnedValue) == IS_OBJECT) {
		if (zephir_instance_of_ev(returnedValue, phalcon_http_responseinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_63$$71, returnedValue, "issent", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(_63$$71))) {
				ZEPHIR_CALL_METHOD(NULL, returnedValue, "send", NULL, 0);
				zephir_check_call_status();
			}
		}
	}
	RETURN_CCTOR(returnedValue);

}

/**
 * Stops the middleware execution avoiding than other middlewares be executed
 */
PHP_METHOD(Phalcon_Mvc_Micro, stop) {

	

	if (1) {
		zephir_update_property_this(getThis(), SL("_stopped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_stopped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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



	zephir_update_property_this(getThis(), SL("_activeHandler"), activeHandler TSRMLS_CC);

}

/**
 * Return the handler that will be called for the matched route
 *
 * @return callable
 */
PHP_METHOD(Phalcon_Mvc_Micro, getActiveHandler) {

	

	RETURN_MEMBER(getThis(), "_activeHandler");

}

/**
 * Returns the value returned by the executed handler
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, getReturnedValue) {

	

	RETURN_MEMBER(getThis(), "_returnedValue");

}

/**
 * Check if a service is registered in the internal services container using the array syntax
 *
 * @param string alias
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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
 *	$app["request"] = new \Phalcon\Http\Request();
 *</code>
 *
 * @param string alias
 * @param mixed definition
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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
 * var_dump(
 *     $app["request"]
 * );
 *</code>
 *
 * @param string alias
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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
 * Appends a afterBinding middleware to be called after model binding
 *
 * @param callable handler
 * @return \Phalcon\Mvc\Micro
 */
PHP_METHOD(Phalcon_Mvc_Micro, afterBinding) {

	zval *handler;

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_array_append(this_ptr, SL("_afterBindingHandlers"), handler TSRMLS_CC);
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
 */
PHP_METHOD(Phalcon_Mvc_Micro, getHandlers) {

	

	RETURN_MEMBER(getThis(), "_handlers");

}

/**
 * Gets model binder
 */
PHP_METHOD(Phalcon_Mvc_Micro, getModelBinder) {

	

	RETURN_MEMBER(getThis(), "_modelBinder");

}

/**
 * Sets model binder
 *
 * <code>
 * $micro = new Micro($di);
 * $micro->setModelBinder(new Binder(), 'cache');
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Micro, setModelBinder) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelBinder, *cache = NULL, *dependencyInjector = NULL, *_0$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modelBinder, &cache);

	if (!cache) {
		ZEPHIR_CPY_WRT(cache, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(cache);
	}


	if (Z_TYPE_P(cache) == IS_STRING) {
		ZEPHIR_OBS_VAR(dependencyInjector);
		zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0$$3, dependencyInjector, "get", NULL, 0, cache);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(cache, _0$$3);
	}
	if (Z_TYPE_P(cache) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, modelBinder, "setcache", NULL, 0, cache);
		zephir_check_call_status();
	}
	zephir_update_property_this(getThis(), SL("_modelBinder"), modelBinder TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns bound models from binder instance
 */
PHP_METHOD(Phalcon_Mvc_Micro, getBoundModels) {

	zval *modelBinder = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(modelBinder);
	zephir_read_property_this(&modelBinder, this_ptr, SL("_modelBinder"), PH_NOISY_CC);
	if (Z_TYPE_P(modelBinder) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(modelBinder, "getboundmodels", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

zend_object_value zephir_init_properties_Phalcon_Mvc_Micro(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_handlers"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_handlers"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

