
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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
 * $app->handle("/say/welcome/Phalcon");
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

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_responseHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
	zval *dependencyInjector = NULL, dependencyInjector_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		dependencyInjector = &dependencyInjector_sub;
		dependencyInjector = &__$null;
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
	zval *dependencyInjector, dependencyInjector_sub, _0, _1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dependencyInjector);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "application");
	ZEPHIR_CALL_METHOD(&_0, dependencyInjector, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "application");
		ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "set", NULL, 0, &_2$$3, this_ptr);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);
	ZEPHIR_MM_RESTORE();

}

/**
 * Maps a route to a handler without any HTTP method constraint
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, map) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "add", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_handlers"), &_0, handler);
	RETURN_CCTOR(&route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addget", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_handlers"), &_0, handler);
	RETURN_CCTOR(&route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, post) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addpost", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_handlers"), &_0, handler);
	RETURN_CCTOR(&route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 *
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, put) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addput", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_handlers"), &_0, handler);
	RETURN_CCTOR(&route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH
 *
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, patch) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addpatch", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_handlers"), &_0, handler);
	RETURN_CCTOR(&route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, head) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addhead", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_handlers"), &_0, handler);
	RETURN_CCTOR(&route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "adddelete", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_handlers"), &_0, handler);
	RETURN_CCTOR(&route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, options) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addoptions", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_handlers"), &_0, handler);
	RETURN_CCTOR(&route);

}

/**
 * Mounts a collection of handlers
 */
PHP_METHOD(Phalcon_Mvc_Micro, mount) {

	zend_bool _4$$8, _5$$8, _7$$16, _8$$16;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, mainHandler, handlers, lazyHandler, prefix, methods, pattern, subHandler, realHandler, prefixedPattern, route, handler, name, _0$$5, *_1$$5, _2$$5, _6$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&mainHandler);
	ZVAL_UNDEF(&handlers);
	ZVAL_UNDEF(&lazyHandler);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&subHandler);
	ZVAL_UNDEF(&realHandler);
	ZVAL_UNDEF(&prefixedPattern);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_6$$16);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection);



	ZEPHIR_CALL_METHOD(&mainHandler, collection, "gethandler", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&mainHandler)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Collection requires a main handler", "phalcon/mvc/micro.zep", 358);
		return;
	}
	ZEPHIR_CALL_METHOD(&handlers, collection, "gethandlers", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&handlers TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "There are no handlers to mount", "phalcon/mvc/micro.zep", 363);
		return;
	}
	if (Z_TYPE_P(&handlers) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0$$5, collection, "islazy", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_0$$5)) {
			ZEPHIR_INIT_VAR(&lazyHandler);
			object_init_ex(&lazyHandler, phalcon_mvc_micro_lazyloader_ce);
			ZEPHIR_CALL_METHOD(NULL, &lazyHandler, "__construct", NULL, 306, &mainHandler);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&lazyHandler, &mainHandler);
		}
		ZEPHIR_CALL_METHOD(&prefix, collection, "getprefix", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&handlers, 0, "phalcon/mvc/micro.zep", 421);
		if (Z_TYPE_P(&handlers) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handlers), _1$$5)
			{
				ZEPHIR_INIT_NVAR(&handler);
				ZVAL_COPY(&handler, _1$$5);
				if (Z_TYPE_P(&handler) != IS_ARRAY) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "One of the registered handlers is invalid", "phalcon/mvc/micro.zep", 385);
					return;
				}
				ZEPHIR_OBS_NVAR(&methods);
				zephir_array_fetch_long(&methods, &handler, 0, PH_NOISY, "phalcon/mvc/micro.zep", 388 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&pattern);
				zephir_array_fetch_long(&pattern, &handler, 1, PH_NOISY, "phalcon/mvc/micro.zep", 389 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&subHandler);
				zephir_array_fetch_long(&subHandler, &handler, 2, PH_NOISY, "phalcon/mvc/micro.zep", 390 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&name);
				zephir_array_fetch_long(&name, &handler, 3, PH_NOISY, "phalcon/mvc/micro.zep", 391 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&realHandler);
				zephir_create_array(&realHandler, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(&realHandler, &lazyHandler);
				zephir_array_fast_append(&realHandler, &subHandler);
				if (!(ZEPHIR_IS_EMPTY(&prefix))) {
					if (ZEPHIR_IS_STRING(&pattern, "/")) {
						ZEPHIR_CPY_WRT(&prefixedPattern, &prefix);
					} else {
						ZEPHIR_INIT_NVAR(&prefixedPattern);
						ZEPHIR_CONCAT_VV(&prefixedPattern, &prefix, &pattern);
					}
				} else {
					ZEPHIR_CPY_WRT(&prefixedPattern, &pattern);
				}
				ZEPHIR_CALL_METHOD(&route, this_ptr, "map", &_3, 0, &prefixedPattern, &realHandler);
				zephir_check_call_status();
				_4$$8 = Z_TYPE_P(&methods) == IS_STRING;
				if (_4$$8) {
					_4$$8 = !ZEPHIR_IS_STRING(&methods, "");
				}
				_5$$8 = _4$$8;
				if (!(_5$$8)) {
					_5$$8 = Z_TYPE_P(&methods) == IS_ARRAY;
				}
				if (_5$$8) {
					ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&name) == IS_STRING) {
					ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &name);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &handlers, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$5, &handlers, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&handler, &handlers, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&handler) != IS_ARRAY) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "One of the registered handlers is invalid", "phalcon/mvc/micro.zep", 385);
						return;
					}
					ZEPHIR_OBS_NVAR(&methods);
					zephir_array_fetch_long(&methods, &handler, 0, PH_NOISY, "phalcon/mvc/micro.zep", 388 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&pattern);
					zephir_array_fetch_long(&pattern, &handler, 1, PH_NOISY, "phalcon/mvc/micro.zep", 389 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&subHandler);
					zephir_array_fetch_long(&subHandler, &handler, 2, PH_NOISY, "phalcon/mvc/micro.zep", 390 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&name);
					zephir_array_fetch_long(&name, &handler, 3, PH_NOISY, "phalcon/mvc/micro.zep", 391 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_6$$16);
					zephir_create_array(&_6$$16, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_6$$16, &lazyHandler);
					zephir_array_fast_append(&_6$$16, &subHandler);
					ZEPHIR_CPY_WRT(&realHandler, &_6$$16);
					if (!(ZEPHIR_IS_EMPTY(&prefix))) {
						if (ZEPHIR_IS_STRING(&pattern, "/")) {
							ZEPHIR_CPY_WRT(&prefixedPattern, &prefix);
						} else {
							ZEPHIR_INIT_NVAR(&prefixedPattern);
							ZEPHIR_CONCAT_VV(&prefixedPattern, &prefix, &pattern);
						}
					} else {
						ZEPHIR_CPY_WRT(&prefixedPattern, &pattern);
					}
					ZEPHIR_CALL_METHOD(&route, this_ptr, "map", &_3, 0, &prefixedPattern, &realHandler);
					zephir_check_call_status();
					_7$$16 = Z_TYPE_P(&methods) == IS_STRING;
					if (_7$$16) {
						_7$$16 = !ZEPHIR_IS_STRING(&methods, "");
					}
					_8$$16 = _7$$16;
					if (!(_8$$16)) {
						_8$$16 = Z_TYPE_P(&methods) == IS_ARRAY;
					}
					if (_8$$16) {
						ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
						zephir_check_call_status();
					}
					if (Z_TYPE_P(&name) == IS_STRING) {
						ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &name);
						zephir_check_call_status();
					}
				ZEPHIR_CALL_METHOD(NULL, &handlers, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&handler);
	}
	RETURN_THIS();

}

/**
 * Sets a handler that will be called when the router doesn't match any of the defined routes
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, notFound) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_zval(this_ptr, SL("_notFoundHandler"), handler);
	RETURN_THISW();

}

/**
 * Sets a handler that will be called when an exception is thrown handling the route
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, error) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_zval(this_ptr, SL("_errorHandler"), handler);
	RETURN_THISW();

}

/**
 * Returns the internal router used by the application
 */
PHP_METHOD(Phalcon_Mvc_Micro, getRouter) {

	zval router, _0$$3, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&router);
	zephir_read_property(&router, this_ptr, SL("_router"), PH_NOISY_CC);
	if (Z_TYPE_P(&router) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "router");
		ZEPHIR_CALL_METHOD(&router, this_ptr, "getsharedservice", NULL, 0, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &router, "clear", NULL, 0);
		zephir_check_call_status();
		ZVAL_BOOL(&_1$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &router, "removeextraslashes", NULL, 0, &_1$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_router"), &router);
	}
	RETURN_CCTOR(&router);

}

/**
 * Sets a service from the DI
 */
PHP_METHOD(Phalcon_Mvc_Micro, setService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared;
	zval *serviceName_param = NULL, *definition, definition_sub, *shared_param = NULL, dependencyInjector, _0;
	zval serviceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &serviceName_param, &definition, &shared_param);

	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(&serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(&serviceName);
		ZVAL_EMPTY_STRING(&serviceName);
	}
	if (!shared_param) {
		shared = 0;
	} else {
		shared = zephir_get_boolval(shared_param);
	}


	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&dependencyInjector);
		object_init_ex(&dependencyInjector, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "__construct", NULL, 307);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), &dependencyInjector);
	}
	if (shared) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(&dependencyInjector, "set", NULL, 308, &serviceName, definition, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks if a service is registered in the DI
 */
PHP_METHOD(Phalcon_Mvc_Micro, hasService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, dependencyInjector;
	zval serviceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&dependencyInjector);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName_param);

	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(&serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(&serviceName);
		ZVAL_EMPTY_STRING(&serviceName);
	}


	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&dependencyInjector);
		object_init_ex(&dependencyInjector, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "__construct", NULL, 307);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), &dependencyInjector);
	}
	ZEPHIR_RETURN_CALL_METHOD(&dependencyInjector, "has", NULL, 309, &serviceName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Obtains a service from the DI
 *
 * @return object
 */
PHP_METHOD(Phalcon_Mvc_Micro, getService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, dependencyInjector;
	zval serviceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&dependencyInjector);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName_param);

	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(&serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(&serviceName);
		ZVAL_EMPTY_STRING(&serviceName);
	}


	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&dependencyInjector);
		object_init_ex(&dependencyInjector, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "__construct", NULL, 307);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), &dependencyInjector);
	}
	ZEPHIR_RETURN_CALL_METHOD(&dependencyInjector, "get", NULL, 310, &serviceName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Obtains a shared service from the DI
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, getSharedService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, dependencyInjector;
	zval serviceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&dependencyInjector);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName_param);

	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(&serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(&serviceName);
		ZVAL_EMPTY_STRING(&serviceName);
	}


	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&dependencyInjector);
		object_init_ex(&dependencyInjector, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "__construct", NULL, 307);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), &dependencyInjector);
	}
	ZEPHIR_RETURN_CALL_METHOD(&dependencyInjector, "getshared", NULL, 311, &serviceName);
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

	zval _75$$84;
	zend_class_entry *_23$$26;
	zend_bool _21$$7, _29$$7, _26$$30, _34$$37, _39$$42;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, __$true, __$false, dependencyInjector, eventsManager, status, router, matchedRoute, handler, beforeHandlers, params, returnedValue, e, errorHandler, afterHandlers, notFoundHandler, finishHandlers, finish, before, after, response, modelBinder, bindCacheKey, routeName, realHandler, methodName, lazyReturned, afterBindingHandlers, afterBinding, _73, _76, _0$$5, _1$$5, _2$$4, _3$$4, _4$$7, _5$$7, _6$$8, _7$$8, _8$$9, _9$$9, *_10$$12, _11$$12, _20$$12, _12$$15, _13$$17, _14$$17, _15$$13, _16$$21, _17$$23, _18$$23, _19$$19, _22$$26, _24$$29, _25$$27, _27$$31, _28$$31, _30$$34, _31$$34, *_32$$36, _33$$36, _44$$36, _38$$37, _35$$38, _36$$40, _37$$40, _43$$42, _40$$43, _41$$45, _42$$45, _45$$48, *_46$$49, _47$$49, _48$$52, _49$$54, _50$$54, _51$$50, _52$$58, _53$$60, _54$$60, _55$$56, _56$$63, _57$$63, _58$$65, _59$$65, _60$$66, *_61$$67, _62$$67, _63$$70, _64$$72, _65$$72, _66$$73, _67$$68, _68$$77, _69$$79, _70$$79, _71$$80, _72$$75, _74$$83, _77$$92, _78$$92, _79$$95, _80$$95, _81$$98;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&matchedRoute);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&beforeHandlers);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&returnedValue);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&errorHandler);
	ZVAL_UNDEF(&afterHandlers);
	ZVAL_UNDEF(&notFoundHandler);
	ZVAL_UNDEF(&finishHandlers);
	ZVAL_UNDEF(&finish);
	ZVAL_UNDEF(&before);
	ZVAL_UNDEF(&after);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&modelBinder);
	ZVAL_UNDEF(&bindCacheKey);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&realHandler);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&lazyReturned);
	ZVAL_UNDEF(&afterBindingHandlers);
	ZVAL_UNDEF(&afterBinding);
	ZVAL_UNDEF(&_73);
	ZVAL_UNDEF(&_76);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$17);
	ZVAL_UNDEF(&_14$$17);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$21);
	ZVAL_UNDEF(&_17$$23);
	ZVAL_UNDEF(&_18$$23);
	ZVAL_UNDEF(&_19$$19);
	ZVAL_UNDEF(&_22$$26);
	ZVAL_UNDEF(&_24$$29);
	ZVAL_UNDEF(&_25$$27);
	ZVAL_UNDEF(&_27$$31);
	ZVAL_UNDEF(&_28$$31);
	ZVAL_UNDEF(&_30$$34);
	ZVAL_UNDEF(&_31$$34);
	ZVAL_UNDEF(&_33$$36);
	ZVAL_UNDEF(&_44$$36);
	ZVAL_UNDEF(&_38$$37);
	ZVAL_UNDEF(&_35$$38);
	ZVAL_UNDEF(&_36$$40);
	ZVAL_UNDEF(&_37$$40);
	ZVAL_UNDEF(&_43$$42);
	ZVAL_UNDEF(&_40$$43);
	ZVAL_UNDEF(&_41$$45);
	ZVAL_UNDEF(&_42$$45);
	ZVAL_UNDEF(&_45$$48);
	ZVAL_UNDEF(&_47$$49);
	ZVAL_UNDEF(&_48$$52);
	ZVAL_UNDEF(&_49$$54);
	ZVAL_UNDEF(&_50$$54);
	ZVAL_UNDEF(&_51$$50);
	ZVAL_UNDEF(&_52$$58);
	ZVAL_UNDEF(&_53$$60);
	ZVAL_UNDEF(&_54$$60);
	ZVAL_UNDEF(&_55$$56);
	ZVAL_UNDEF(&_56$$63);
	ZVAL_UNDEF(&_57$$63);
	ZVAL_UNDEF(&_58$$65);
	ZVAL_UNDEF(&_59$$65);
	ZVAL_UNDEF(&_60$$66);
	ZVAL_UNDEF(&_62$$67);
	ZVAL_UNDEF(&_63$$70);
	ZVAL_UNDEF(&_64$$72);
	ZVAL_UNDEF(&_65$$72);
	ZVAL_UNDEF(&_66$$73);
	ZVAL_UNDEF(&_67$$68);
	ZVAL_UNDEF(&_68$$77);
	ZVAL_UNDEF(&_69$$79);
	ZVAL_UNDEF(&_70$$79);
	ZVAL_UNDEF(&_71$$80);
	ZVAL_UNDEF(&_72$$75);
	ZVAL_UNDEF(&_74$$83);
	ZVAL_UNDEF(&_77$$92);
	ZVAL_UNDEF(&_78$$92);
	ZVAL_UNDEF(&_79$$95);
	ZVAL_UNDEF(&_80$$95);
	ZVAL_UNDEF(&_81$$98);
	ZVAL_UNDEF(&_75$$84);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_EMPTY_STRING(&uri);
	}


	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	ZEPHIR_INIT_VAR(&realHandler);
	ZVAL_NULL(&realHandler);
	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "A dependency injection container is required to access required micro services", "phalcon/mvc/micro.zep", 563);
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&returnedValue);
		ZVAL_NULL(&returnedValue);
		ZEPHIR_OBS_VAR(&eventsManager);
		zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_1$$5);
			ZVAL_STRING(&_1$$5, "micro:beforeHandleRoute");
			ZEPHIR_CALL_METHOD(&_0$$5, &eventsManager, "fire", NULL, 0, &_1$$5, this_ptr);
			zephir_check_call_status_or_jump(try_end_1);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$5)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "router");
		ZEPHIR_CALL_METHOD(&_2$$4, &dependencyInjector, "getshared", NULL, 0, &_3$$4);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(&router, &_2$$4);
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &uri);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&matchedRoute, &router, "getmatchedroute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (Z_TYPE_P(&matchedRoute) == IS_OBJECT) {
			ZEPHIR_OBS_VAR(&handler);
			zephir_read_property(&_4$$7, this_ptr, SL("_handlers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_5$$7, &matchedRoute, "getrouteid", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (!(zephir_array_isset_fetch(&handler, &_4$$7, &_5$$7, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(&_6$$8);
				object_init_ex(&_6$$8, phalcon_mvc_micro_exception_ce);
				ZEPHIR_INIT_VAR(&_7$$8);
				ZVAL_STRING(&_7$$8, "Matched route doesn't have an associated handler");
				ZEPHIR_CALL_METHOD(NULL, &_6$$8, "__construct", NULL, 4, &_7$$8);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_6$$8, "phalcon/mvc/micro.zep", 597 TSRMLS_CC);
				goto try_end_1;

			}
			zephir_update_property_zval(this_ptr, SL("_activeHandler"), &handler);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_9$$9);
				ZVAL_STRING(&_9$$9, "micro:beforeExecuteRoute");
				ZEPHIR_CALL_METHOD(&_8$$9, &eventsManager, "fire", NULL, 0, &_9$$9, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_8$$9)) {
					RETURN_MM_BOOL(0);
				} else {
					ZEPHIR_OBS_NVAR(&handler);
					zephir_read_property(&handler, this_ptr, SL("_activeHandler"), PH_NOISY_CC);
				}
			}
			ZEPHIR_OBS_VAR(&beforeHandlers);
			zephir_read_property(&beforeHandlers, this_ptr, SL("_beforeHandlers"), PH_NOISY_CC);
			if (Z_TYPE_P(&beforeHandlers) == IS_ARRAY) {
				if (0) {
					zephir_update_property_zval(this_ptr, SL("_stopped"), &__$true);
				} else {
					zephir_update_property_zval(this_ptr, SL("_stopped"), &__$false);
				}
				zephir_is_iterable(&beforeHandlers, 0, "phalcon/mvc/micro.zep", 665);
				if (Z_TYPE_P(&beforeHandlers) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&beforeHandlers), _10$$12)
					{
						ZEPHIR_INIT_NVAR(&before);
						ZVAL_COPY(&before, _10$$12);
						if (Z_TYPE_P(&before) == IS_OBJECT) {
							if (zephir_instance_of_ev(&before, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
								ZEPHIR_CALL_METHOD(&status, &before, "call", NULL, 0, this_ptr);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_read_property(&_12$$15, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
								if (zephir_is_true(&_12$$15)) {
									break;
								}
								continue;
							}
						}
						if (!(zephir_is_callable(&before TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_13$$17);
							object_init_ex(&_13$$17, phalcon_mvc_micro_exception_ce);
							ZEPHIR_INIT_NVAR(&_14$$17);
							ZVAL_STRING(&_14$$17, "'before' handler is not callable");
							ZEPHIR_CALL_METHOD(NULL, &_13$$17, "__construct", NULL, 4, &_14$$17);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_13$$17, "phalcon/mvc/micro.zep", 647 TSRMLS_CC);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &before);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_read_property(&_15$$13, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_15$$13)) {
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &beforeHandlers, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_11$$12, &beforeHandlers, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_11$$12)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&before, &beforeHandlers, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&before) == IS_OBJECT) {
								if (zephir_instance_of_ev(&before, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
									ZEPHIR_CALL_METHOD(&status, &before, "call", NULL, 0, this_ptr);
									zephir_check_call_status_or_jump(try_end_1);
									zephir_read_property(&_16$$21, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
									if (zephir_is_true(&_16$$21)) {
										break;
									}
									continue;
								}
							}
							if (!(zephir_is_callable(&before TSRMLS_CC))) {
								ZEPHIR_INIT_NVAR(&_17$$23);
								object_init_ex(&_17$$23, phalcon_mvc_micro_exception_ce);
								ZEPHIR_INIT_NVAR(&_18$$23);
								ZVAL_STRING(&_18$$23, "'before' handler is not callable");
								ZEPHIR_CALL_METHOD(NULL, &_17$$23, "__construct", NULL, 4, &_18$$23);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_17$$23, "phalcon/mvc/micro.zep", 647 TSRMLS_CC);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &before);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_read_property(&_19$$19, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_19$$19)) {
								break;
							}
						ZEPHIR_CALL_METHOD(NULL, &beforeHandlers, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&before);
				zephir_read_property(&_20$$12, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_20$$12)) {
					RETURN_CCTOR(&status);
				}
			}
			ZEPHIR_CALL_METHOD(&params, &router, "getparams", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_OBS_VAR(&modelBinder);
			zephir_read_property(&modelBinder, this_ptr, SL("_modelBinder"), PH_NOISY_CC);
			_21$$7 = Z_TYPE_P(&handler) == IS_OBJECT;
			if (_21$$7) {
				_21$$7 = zephir_instance_of_ev(&handler, zend_ce_closure TSRMLS_CC);
			}
			if (_21$$7) {
				_23$$26 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
				ZEPHIR_CALL_CE_STATIC(&_22$$26, _23$$26, "bind", NULL, 0, &handler, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(&handler, &_22$$26);
				if (Z_TYPE_P(&modelBinder) != IS_NULL) {
					ZEPHIR_CALL_METHOD(&routeName, &matchedRoute, "getname", NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_INIT_VAR(&bindCacheKey);
					if (Z_TYPE_P(&routeName) != IS_NULL) {
						ZEPHIR_CONCAT_SV(&bindCacheKey, "_PHMB_", &routeName);
					} else {
						ZEPHIR_CALL_METHOD(&_24$$29, &matchedRoute, "getpattern", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						ZEPHIR_CONCAT_SV(&bindCacheKey, "_PHMB_", &_24$$29);
					}
					ZEPHIR_CALL_METHOD(&_25$$27, &modelBinder, "bindtohandler", NULL, 0, &handler, &params, &bindCacheKey);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(&params, &_25$$27);
				}
			}
			if (Z_TYPE_P(&handler) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&realHandler);
				zephir_array_fetch_long(&realHandler, &handler, 0, PH_NOISY, "phalcon/mvc/micro.zep", 696 TSRMLS_CC);
				_26$$30 = zephir_instance_of_ev(&realHandler, phalcon_mvc_controller_ce TSRMLS_CC);
				if (_26$$30) {
					_26$$30 = Z_TYPE_P(&modelBinder) != IS_NULL;
				}
				if (_26$$30) {
					ZEPHIR_OBS_VAR(&methodName);
					zephir_array_fetch_long(&methodName, &handler, 1, PH_NOISY, "phalcon/mvc/micro.zep", 699 TSRMLS_CC);
					ZEPHIR_INIT_VAR(&_27$$31);
					zephir_get_class(&_27$$31, &realHandler, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&bindCacheKey);
					ZEPHIR_CONCAT_SVSV(&bindCacheKey, "_PHMB_", &_27$$31, "_", &methodName);
					ZEPHIR_CALL_METHOD(&_28$$31, &modelBinder, "bindtohandler", NULL, 0, &realHandler, &params, &bindCacheKey, &methodName);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(&params, &_28$$31);
				}
			}
			_29$$7 = Z_TYPE_P(&realHandler) != IS_NULL;
			if (_29$$7) {
				_29$$7 = zephir_instance_of_ev(&realHandler, phalcon_mvc_micro_lazyloader_ce TSRMLS_CC);
			}
			if (_29$$7) {
				ZEPHIR_OBS_NVAR(&methodName);
				zephir_array_fetch_long(&methodName, &handler, 1, PH_NOISY, "phalcon/mvc/micro.zep", 709 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&lazyReturned, &realHandler, "callmethod", NULL, 0, &methodName, &params, &modelBinder);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(&returnedValue, &lazyReturned);
			} else {
				ZEPHIR_INIT_NVAR(&returnedValue);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&returnedValue, &handler, &params);
				zephir_check_call_status_or_jump(try_end_1);
			}
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_31$$34);
				ZVAL_STRING(&_31$$34, "micro:afterBinding");
				ZEPHIR_CALL_METHOD(&_30$$34, &eventsManager, "fire", NULL, 0, &_31$$34, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_30$$34)) {
					RETURN_MM_BOOL(0);
				}
			}
			ZEPHIR_OBS_VAR(&afterBindingHandlers);
			zephir_read_property(&afterBindingHandlers, this_ptr, SL("_afterBindingHandlers"), PH_NOISY_CC);
			if (Z_TYPE_P(&afterBindingHandlers) == IS_ARRAY) {
				if (0) {
					zephir_update_property_zval(this_ptr, SL("_stopped"), &__$true);
				} else {
					zephir_update_property_zval(this_ptr, SL("_stopped"), &__$false);
				}
				zephir_is_iterable(&afterBindingHandlers, 0, "phalcon/mvc/micro.zep", 774);
				if (Z_TYPE_P(&afterBindingHandlers) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&afterBindingHandlers), _32$$36)
					{
						ZEPHIR_INIT_NVAR(&afterBinding);
						ZVAL_COPY(&afterBinding, _32$$36);
						_34$$37 = Z_TYPE_P(&afterBinding) == IS_OBJECT;
						if (_34$$37) {
							_34$$37 = zephir_instance_of_ev(&afterBinding, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC);
						}
						if (_34$$37) {
							ZEPHIR_CALL_METHOD(&status, &afterBinding, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_read_property(&_35$$38, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_35$$38)) {
								break;
							}
							continue;
						}
						if (!(zephir_is_callable(&afterBinding TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_36$$40);
							object_init_ex(&_36$$40, phalcon_mvc_micro_exception_ce);
							ZEPHIR_INIT_NVAR(&_37$$40);
							ZVAL_STRING(&_37$$40, "'afterBinding' handler is not callable");
							ZEPHIR_CALL_METHOD(NULL, &_36$$40, "__construct", NULL, 4, &_37$$40);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_36$$40, "phalcon/mvc/micro.zep", 756 TSRMLS_CC);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &afterBinding);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_read_property(&_38$$37, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_38$$37)) {
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &afterBindingHandlers, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_33$$36, &afterBindingHandlers, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_33$$36)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&afterBinding, &afterBindingHandlers, "current", NULL, 0);
						zephir_check_call_status();
							_39$$42 = Z_TYPE_P(&afterBinding) == IS_OBJECT;
							if (_39$$42) {
								_39$$42 = zephir_instance_of_ev(&afterBinding, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC);
							}
							if (_39$$42) {
								ZEPHIR_CALL_METHOD(&status, &afterBinding, "call", NULL, 0, this_ptr);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_read_property(&_40$$43, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
								if (zephir_is_true(&_40$$43)) {
									break;
								}
								continue;
							}
							if (!(zephir_is_callable(&afterBinding TSRMLS_CC))) {
								ZEPHIR_INIT_NVAR(&_41$$45);
								object_init_ex(&_41$$45, phalcon_mvc_micro_exception_ce);
								ZEPHIR_INIT_NVAR(&_42$$45);
								ZVAL_STRING(&_42$$45, "'afterBinding' handler is not callable");
								ZEPHIR_CALL_METHOD(NULL, &_41$$45, "__construct", NULL, 4, &_42$$45);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_41$$45, "phalcon/mvc/micro.zep", 756 TSRMLS_CC);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &afterBinding);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_read_property(&_43$$42, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_43$$42)) {
								break;
							}
						ZEPHIR_CALL_METHOD(NULL, &afterBindingHandlers, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&afterBinding);
				zephir_read_property(&_44$$36, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_44$$36)) {
					RETURN_CCTOR(&status);
				}
			}
			zephir_update_property_zval(this_ptr, SL("_returnedValue"), &returnedValue);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_45$$48);
				ZVAL_STRING(&_45$$48, "micro:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_45$$48, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_OBS_VAR(&afterHandlers);
			zephir_read_property(&afterHandlers, this_ptr, SL("_afterHandlers"), PH_NOISY_CC);
			if (Z_TYPE_P(&afterHandlers) == IS_ARRAY) {
				if (0) {
					zephir_update_property_zval(this_ptr, SL("_stopped"), &__$true);
				} else {
					zephir_update_property_zval(this_ptr, SL("_stopped"), &__$false);
				}
				zephir_is_iterable(&afterHandlers, 0, "phalcon/mvc/micro.zep", 833);
				if (Z_TYPE_P(&afterHandlers) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&afterHandlers), _46$$49)
					{
						ZEPHIR_INIT_NVAR(&after);
						ZVAL_COPY(&after, _46$$49);
						if (Z_TYPE_P(&after) == IS_OBJECT) {
							if (zephir_instance_of_ev(&after, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
								ZEPHIR_CALL_METHOD(&status, &after, "call", NULL, 0, this_ptr);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_read_property(&_48$$52, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
								if (zephir_is_true(&_48$$52)) {
									break;
								}
								continue;
							}
						}
						if (!(zephir_is_callable(&after TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_49$$54);
							object_init_ex(&_49$$54, phalcon_mvc_micro_exception_ce);
							ZEPHIR_INIT_NVAR(&_50$$54);
							ZVAL_STRING(&_50$$54, "One of the 'after' handlers is not callable");
							ZEPHIR_CALL_METHOD(NULL, &_49$$54, "__construct", NULL, 4, &_50$$54);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_49$$54, "phalcon/mvc/micro.zep", 821 TSRMLS_CC);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &after);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_read_property(&_51$$50, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_51$$50)) {
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &afterHandlers, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_47$$49, &afterHandlers, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_47$$49)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&after, &afterHandlers, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&after) == IS_OBJECT) {
								if (zephir_instance_of_ev(&after, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
									ZEPHIR_CALL_METHOD(&status, &after, "call", NULL, 0, this_ptr);
									zephir_check_call_status_or_jump(try_end_1);
									zephir_read_property(&_52$$58, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
									if (zephir_is_true(&_52$$58)) {
										break;
									}
									continue;
								}
							}
							if (!(zephir_is_callable(&after TSRMLS_CC))) {
								ZEPHIR_INIT_NVAR(&_53$$60);
								object_init_ex(&_53$$60, phalcon_mvc_micro_exception_ce);
								ZEPHIR_INIT_NVAR(&_54$$60);
								ZVAL_STRING(&_54$$60, "One of the 'after' handlers is not callable");
								ZEPHIR_CALL_METHOD(NULL, &_53$$60, "__construct", NULL, 4, &_54$$60);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_53$$60, "phalcon/mvc/micro.zep", 821 TSRMLS_CC);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &after);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_read_property(&_55$$56, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_55$$56)) {
								break;
							}
						ZEPHIR_CALL_METHOD(NULL, &afterHandlers, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&after);
			}
		} else {
			ZEPHIR_OBS_NVAR(&eventsManager);
			zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_57$$63);
				ZVAL_STRING(&_57$$63, "micro:beforeNotFound");
				ZEPHIR_CALL_METHOD(&_56$$63, &eventsManager, "fire", NULL, 0, &_57$$63, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_56$$63)) {
					RETURN_MM_BOOL(0);
				}
			}
			ZEPHIR_OBS_VAR(&notFoundHandler);
			zephir_read_property(&notFoundHandler, this_ptr, SL("_notFoundHandler"), PH_NOISY_CC);
			if (!(zephir_is_callable(&notFoundHandler TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(&_58$$65);
				object_init_ex(&_58$$65, phalcon_mvc_micro_exception_ce);
				ZEPHIR_INIT_VAR(&_59$$65);
				ZVAL_STRING(&_59$$65, "Not-Found handler is not callable or is not defined");
				ZEPHIR_CALL_METHOD(NULL, &_58$$65, "__construct", NULL, 4, &_59$$65);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_58$$65, "phalcon/mvc/micro.zep", 852 TSRMLS_CC);
				goto try_end_1;

			}
			ZEPHIR_INIT_NVAR(&returnedValue);
			ZEPHIR_CALL_USER_FUNC(&returnedValue, &notFoundHandler);
			zephir_check_call_status_or_jump(try_end_1);
		}
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_60$$66);
			ZVAL_STRING(&_60$$66, "micro:afterHandleRoute");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_60$$66, this_ptr, &returnedValue);
			zephir_check_call_status_or_jump(try_end_1);
		}
		ZEPHIR_OBS_VAR(&finishHandlers);
		zephir_read_property(&finishHandlers, this_ptr, SL("_finishHandlers"), PH_NOISY_CC);
		if (Z_TYPE_P(&finishHandlers) == IS_ARRAY) {
			if (0) {
				zephir_update_property_zval(this_ptr, SL("_stopped"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("_stopped"), &__$false);
			}
			ZEPHIR_INIT_NVAR(&params);
			ZVAL_NULL(&params);
			zephir_is_iterable(&finishHandlers, 0, "phalcon/mvc/micro.zep", 923);
			if (Z_TYPE_P(&finishHandlers) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&finishHandlers), _61$$67)
				{
					ZEPHIR_INIT_NVAR(&finish);
					ZVAL_COPY(&finish, _61$$67);
					if (Z_TYPE_P(&finish) == IS_OBJECT) {
						if (zephir_instance_of_ev(&finish, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
							ZEPHIR_CALL_METHOD(&status, &finish, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_read_property(&_63$$70, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_63$$70)) {
								break;
							}
							continue;
						}
					}
					if (!(zephir_is_callable(&finish TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(&_64$$72);
						object_init_ex(&_64$$72, phalcon_mvc_micro_exception_ce);
						ZEPHIR_INIT_NVAR(&_65$$72);
						ZVAL_STRING(&_65$$72, "One of the 'finish' handlers is not callable");
						ZEPHIR_CALL_METHOD(NULL, &_64$$72, "__construct", NULL, 4, &_65$$72);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(&_64$$72, "phalcon/mvc/micro.zep", 904 TSRMLS_CC);
						goto try_end_1;

					}
					if (Z_TYPE_P(&params) == IS_NULL) {
						ZEPHIR_INIT_NVAR(&_66$$73);
						zephir_create_array(&_66$$73, 1, 0 TSRMLS_CC);
						zephir_array_fast_append(&_66$$73, this_ptr);
						ZEPHIR_CPY_WRT(&params, &_66$$73);
					}
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &finish, &params);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_read_property(&_67$$68, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_67$$68)) {
						break;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &finishHandlers, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_62$$67, &finishHandlers, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_62$$67)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&finish, &finishHandlers, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&finish) == IS_OBJECT) {
							if (zephir_instance_of_ev(&finish, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
								ZEPHIR_CALL_METHOD(&status, &finish, "call", NULL, 0, this_ptr);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_read_property(&_68$$77, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
								if (zephir_is_true(&_68$$77)) {
									break;
								}
								continue;
							}
						}
						if (!(zephir_is_callable(&finish TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_69$$79);
							object_init_ex(&_69$$79, phalcon_mvc_micro_exception_ce);
							ZEPHIR_INIT_NVAR(&_70$$79);
							ZVAL_STRING(&_70$$79, "One of the 'finish' handlers is not callable");
							ZEPHIR_CALL_METHOD(NULL, &_69$$79, "__construct", NULL, 4, &_70$$79);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_69$$79, "phalcon/mvc/micro.zep", 904 TSRMLS_CC);
							goto try_end_1;

						}
						if (Z_TYPE_P(&params) == IS_NULL) {
							ZEPHIR_INIT_NVAR(&_71$$80);
							zephir_create_array(&_71$$80, 1, 0 TSRMLS_CC);
							zephir_array_fast_append(&_71$$80, this_ptr);
							ZEPHIR_CPY_WRT(&params, &_71$$80);
						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &finish, &params);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_read_property(&_72$$75, this_ptr, SL("_stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_72$$75)) {
							break;
						}
					ZEPHIR_CALL_METHOD(NULL, &finishHandlers, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&finish);
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_73);
		ZVAL_OBJ(&_73, EG(exception));
		Z_ADDREF_P(&_73);
		if (zephir_is_instance_of(&_73, SL("Throwable") TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_73);
			ZEPHIR_OBS_NVAR(&eventsManager);
			zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_74$$83);
				ZVAL_STRING(&_74$$83, "micro:beforeException");
				ZEPHIR_CALL_METHOD(&returnedValue, &eventsManager, "fire", NULL, 0, &_74$$83, this_ptr, &e);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_VAR(&errorHandler);
			zephir_read_property(&errorHandler, this_ptr, SL("_errorHandler"), PH_NOISY_CC);
			if (zephir_is_true(&errorHandler)) {
				if (!(zephir_is_callable(&errorHandler TSRMLS_CC))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Error handler is not callable", "phalcon/mvc/micro.zep", 942);
					return;
				}
				ZEPHIR_INIT_VAR(&_75$$84);
				zephir_create_array(&_75$$84, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(&_75$$84, &e);
				ZEPHIR_INIT_NVAR(&returnedValue);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&returnedValue, &errorHandler, &_75$$84);
				zephir_check_call_status();
				if (Z_TYPE_P(&returnedValue) == IS_OBJECT) {
					if (!(zephir_instance_of_ev(&returnedValue, phalcon_http_responseinterface_ce TSRMLS_CC))) {
						zephir_throw_exception_debug(&e, "phalcon/mvc/micro.zep", 951 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&returnedValue)) {
						zephir_throw_exception_debug(&e, "phalcon/mvc/micro.zep", 955 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&returnedValue)) {
					zephir_throw_exception_debug(&e, "phalcon/mvc/micro.zep", 961 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	zephir_read_property(&_76, this_ptr, SL("_responseHandler"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_76)) {
		zephir_read_property(&_77$$92, this_ptr, SL("_responseHandler"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_is_callable(&_77$$92 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Response handler is not callable or is not defined", "phalcon/mvc/micro.zep", 973);
			return;
		}
		zephir_read_property(&_78$$92, this_ptr, SL("_responseHandler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&returnedValue);
		ZEPHIR_CALL_USER_FUNC(&returnedValue, &_78$$92);
		zephir_check_call_status();
	} else {
		if (Z_TYPE_P(&returnedValue) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_80$$95);
			ZVAL_STRING(&_80$$95, "response");
			ZEPHIR_CALL_METHOD(&_79$$95, &dependencyInjector, "getshared", NULL, 0, &_80$$95);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&response, &_79$$95);
			ZEPHIR_CALL_METHOD(&_79$$95, &response, "issent", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_79$$95))) {
				ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &returnedValue);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "send", NULL, 0);
				zephir_check_call_status();
			}
		}
		if (Z_TYPE_P(&returnedValue) == IS_OBJECT) {
			if (zephir_instance_of_ev(&returnedValue, phalcon_http_responseinterface_ce TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&_81$$98, &returnedValue, "issent", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_81$$98))) {
					ZEPHIR_CALL_METHOD(NULL, &returnedValue, "send", NULL, 0);
					zephir_check_call_status();
				}
			}
		}
	}
	RETURN_CCTOR(&returnedValue);

}

/**
 * Stops the middleware execution avoiding than other middlewares be executed
 */
PHP_METHOD(Phalcon_Mvc_Micro, stop) {

	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);


	if (1) {
		zephir_update_property_zval(this_ptr, SL("_stopped"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_stopped"), &__$false);
	}

}

/**
 * Sets externally the handler that must be called by the matched route
 *
 * @param callable activeHandler
 */
PHP_METHOD(Phalcon_Mvc_Micro, setActiveHandler) {

	zval *activeHandler, activeHandler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&activeHandler_sub);

	zephir_fetch_params(0, 1, 0, &activeHandler);



	zephir_update_property_zval(this_ptr, SL("_activeHandler"), activeHandler);

}

/**
 * Return the handler that will be called for the matched route
 *
 * @return callable
 */
PHP_METHOD(Phalcon_Mvc_Micro, getActiveHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_activeHandler");

}

/**
 * Returns the value returned by the executed handler
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, getReturnedValue) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_returnedValue");

}

/**
 * Check if a service is registered in the internal services container using the array syntax
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);

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
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub, *definition, definition_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);
	ZVAL_UNDEF(&definition_sub);

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
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getservice", NULL, 0, alias);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Removes a service from the internal services container using the array syntax
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetUnset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub, dependencyInjector;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);
	ZVAL_UNDEF(&dependencyInjector);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias);



	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&dependencyInjector);
		object_init_ex(&dependencyInjector, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "__construct", NULL, 307);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), &dependencyInjector);
	}
	ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "remove", NULL, 312, alias);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Appends a before middleware to be called before execute the route
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, before) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_array_append(this_ptr, SL("_beforeHandlers"), handler);
	RETURN_THISW();

}

/**
 * Appends a afterBinding middleware to be called after model binding
 *
 * @param callable handler
 * @return \Phalcon\Mvc\Micro
 */
PHP_METHOD(Phalcon_Mvc_Micro, afterBinding) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_array_append(this_ptr, SL("_afterBindingHandlers"), handler);
	RETURN_THISW();

}

/**
 * Appends an 'after' middleware to be called after execute the route
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, after) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_array_append(this_ptr, SL("_afterHandlers"), handler);
	RETURN_THISW();

}

/**
 * Appends a 'finish' middleware to be called when the request is finished
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, finish) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_array_append(this_ptr, SL("_finishHandlers"), handler);
	RETURN_THISW();

}

/**
 * Returns the internal handlers attached to the application
 */
PHP_METHOD(Phalcon_Mvc_Micro, getHandlers) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_handlers");

}

/**
 * Appends a custom 'reponse' handler to be called insted of the default reponse handler
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, setResponseHandler) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_zval(this_ptr, SL("_responseHandler"), handler);
	RETURN_THISW();

}

/**
 * Gets model binder
 */
PHP_METHOD(Phalcon_Mvc_Micro, getModelBinder) {

	zval *this_ptr = getThis();


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
	zval *modelBinder, modelBinder_sub, *cache = NULL, cache_sub, __$null, dependencyInjector, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelBinder_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modelBinder, &cache);

	if (!cache) {
		cache = &cache_sub;
		ZEPHIR_CPY_WRT(cache, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(cache);
	}


	if (Z_TYPE_P(cache) == IS_STRING) {
		ZEPHIR_OBS_VAR(&dependencyInjector);
		zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0$$3, &dependencyInjector, "get", NULL, 0, cache);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(cache, &_0$$3);
	}
	if (Z_TYPE_P(cache) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, modelBinder, "setcache", NULL, 0, cache);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_modelBinder"), modelBinder);
	RETURN_THIS();

}

/**
 * Returns bound models from binder instance
 */
PHP_METHOD(Phalcon_Mvc_Micro, getBoundModels) {

	zval modelBinder;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelBinder);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&modelBinder);
	zephir_read_property(&modelBinder, this_ptr, SL("_modelBinder"), PH_NOISY_CC);
	if (Z_TYPE_P(&modelBinder) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(&modelBinder, "getboundmodels", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_Mvc_Micro(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_handlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_handlers"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

