
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Router
 *
 * Phalcon\Mvc\Router is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the
 * base URL) and decomposing it into parameters to determine which module,
 * controller, and action of that controller should receive the request
 *
 * <code>
 * use Phalcon\Mvc\Router;
 *
 * $router = new Router();
 *
 * $router->add(
 *     "/documentation/{chapter}/{name}\.{type:[a-z]+}",
 *     [
 *         "controller" => "documentation",
 *         "action"     => "show",
 *     ]
 * );
 *
 * $router->handle(
 *     "/documentation/1/examples.html"
 * );
 *
 * echo $router->getControllerName();
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, Router, phalcon, mvc_router, phalcon_mvc_router_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("controller"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("defaultAction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("defaultController"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("defaultNamespace"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("defaultParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("keyRouteNames"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("keyRouteIds"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("matchedRoute"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("matches"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("namespaceName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("notFoundPaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("removeExtraSlashes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("routes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("uriSource"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_router_ce, SL("wasMatched"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_router_ce->create_object = zephir_init_properties_Phalcon_Mvc_Router;
	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("POSITION_FIRST"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("POSITION_LAST"), 1);

	zend_class_implements(phalcon_mvc_router_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_router_ce TSRMLS_CC, 1, phalcon_mvc_routerinterface_ce);
	zend_class_implements(phalcon_mvc_router_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteNames) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "keyRouteNames");

}

PHP_METHOD(Phalcon_Mvc_Router, setKeyRouteNames) {

	zval *keyRouteNames, keyRouteNames_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyRouteNames_sub);

	zephir_fetch_params(0, 1, 0, &keyRouteNames);



	zephir_update_property_zval(this_ptr, SL("keyRouteNames"), keyRouteNames);
	RETURN_THISW();

}

PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteIds) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "keyRouteIds");

}

PHP_METHOD(Phalcon_Mvc_Router, setKeyRouteIds) {

	zval *keyRouteIds, keyRouteIds_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyRouteIds_sub);

	zephir_fetch_params(0, 1, 0, &keyRouteIds);



	zephir_update_property_zval(this_ptr, SL("keyRouteIds"), keyRouteIds);
	RETURN_THISW();

}

/**
 * Phalcon\Mvc\Router constructor
 */
PHP_METHOD(Phalcon_Mvc_Router, __construct) {

	zval routes, _1$$3, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultRoutes_param = NULL, _0$$3, _2$$3, _4$$3;
	zend_bool defaultRoutes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultRoutes_param);

	if (!defaultRoutes_param) {
		defaultRoutes = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(defaultRoutes_param) != IS_TRUE && Z_TYPE_P(defaultRoutes_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'defaultRoutes' must be of the type bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	defaultRoutes = (Z_TYPE_P(defaultRoutes_param) == IS_TRUE);
	}


	ZEPHIR_INIT_VAR(&routes);
	array_init(&routes);
	if (defaultRoutes) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(&_1$$3, SL("controller"), 1);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "#^/([\\w0-9\\_\\-]+)[/]{0,1}$#u");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 84, &_2$$3, &_1$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, &_0$$3, PH_SEPARATE, "phalcon/Mvc/Router.zep", 96);
		ZEPHIR_INIT_NVAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(&_3$$3, SL("controller"), 1);
		add_assoc_long_ex(&_3$$3, SL("action"), 2);
		add_assoc_long_ex(&_3$$3, SL("params"), 3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "#^/([\\w0-9\\_\\-]+)/([\\w0-9\\.\\_]+)(/.*)*$#u");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 84, &_4$$3, &_3$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, &_2$$3, PH_SEPARATE, "phalcon/Mvc/Router.zep", 105);
	}
	zephir_update_property_zval(this_ptr, SL("routes"), &routes);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a route to the router without any HTTP constraint
 *
 *<code>
 * use Phalcon\Mvc\Router;
 *
 * $router->add("/about", "About::index");
 *
 * $router->add(
 *     "/about",
 *     "About::index",
 *     ["GET", "POST"]
 * );
 *
 * $router->add(
 *     "/about",
 *     "About::index",
 *     ["GET", "POST"],
 *     Router::POSITION_FIRST
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, add) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *httpMethods = NULL, httpMethods_sub, *position = NULL, position_sub, __$null, route;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&httpMethods_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&route);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &pattern_param, &paths, &httpMethods, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!httpMethods) {
		httpMethods = &httpMethods_sub;
		httpMethods = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&route);
	object_init_ex(&route, phalcon_mvc_router_route_ce);
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 84, &pattern, paths, httpMethods);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, &route, position);
	zephir_check_call_status();
	RETURN_CCTOR(&route);

}

/**
 * Adds a route to the router that only match if the HTTP method is CONNECT
 */
PHP_METHOD(Phalcon_Mvc_Router, addConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "CONNECT");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 */
PHP_METHOD(Phalcon_Mvc_Router, addDelete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DELETE");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 */
PHP_METHOD(Phalcon_Mvc_Router, addGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GET");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 */
PHP_METHOD(Phalcon_Mvc_Router, addHead) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HEAD");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 */
PHP_METHOD(Phalcon_Mvc_Router, addOptions) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "OPTIONS");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 */
PHP_METHOD(Phalcon_Mvc_Router, addPatch) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PATCH");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 */
PHP_METHOD(Phalcon_Mvc_Router, addPost) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "POST");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PURGE
 * (Squid and Varnish support)
 */
PHP_METHOD(Phalcon_Mvc_Router, addPurge) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PURGE");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 */
PHP_METHOD(Phalcon_Mvc_Router, addPut) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PUT");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is TRACE
 */
PHP_METHOD(Phalcon_Mvc_Router, addTrace) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "TRACE");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Attach Route object to the routes stack.
 *
 * <code>
 * use Phalcon\Mvc\Router;
 * use Phalcon\Mvc\Router\Route;
 *
 * class CustomRoute extends Route {
 *      // ...
 * }
 *
 * $router = new Router();
 *
 * $router->attach(
 *     new CustomRoute("/about", "About::index", ["GET", "HEAD"]),
 *     Router::POSITION_FIRST
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Router, attach) {

	zval _1$$4;
	zval *route, route_sub, *position = NULL, position_sub, _0$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &route, &position);

	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	do {
		if (ZEPHIR_IS_LONG(position, 1)) {
			zephir_update_property_array_append(this_ptr, SL("routes"), route TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(position, 0)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZEPHIR_INIT_VAR(&_1$$4);
			zephir_create_array(&_1$$4, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_1$$4, route);
			zephir_read_property(&_2$$4, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
			zephir_fast_array_merge(&_0$$4, &_1$$4, &_2$$4 TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("routes"), &_0$$4);
			break;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Invalid route position", "phalcon/Mvc/Router.zep", 257);
		return;
	} while(0);

	RETURN_THIS();

}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, clear) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("routes"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Mvc_Router, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Mvc_Router, getEventsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "eventsManager");

}

/**
 * Returns the processed action name
 */
PHP_METHOD(Phalcon_Mvc_Router, getActionName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "action");

}

/**
 * Returns the processed controller name
 */
PHP_METHOD(Phalcon_Mvc_Router, getControllerName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "controller");

}

/**
 * Returns the route that matches the handled URI
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "matchedRoute");

}

/**
 * Returns the sub expressions in the regular expression matched
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatches) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "matches");

}

/**
 * Returns the processed module name
 */
PHP_METHOD(Phalcon_Mvc_Router, getModuleName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "module");

}

/**
 * Returns the processed namespace name
 */
PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "namespaceName");

}

/**
 * Returns the processed parameters
 */
PHP_METHOD(Phalcon_Mvc_Router, getParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "params");

}

/**
 * Returns a route object by its id
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteById) {

	zend_string *_6;
	zend_ulong _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, route, routeId, key, _0, _3, *_4, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routeId);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	ZEPHIR_OBS_VAR(&key);
	zephir_read_property(&_0, this_ptr, SL("keyRouteIds"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&key, &_0, id, 0 TSRMLS_CC)) {
		zephir_read_property(&_1$$3, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 351 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/Mvc/Router.zep", 363);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&key, _6);
		} else {
			ZVAL_LONG(&key, _5);
		}
		ZEPHIR_INIT_NVAR(&route);
		ZVAL_COPY(&route, _4);
		ZEPHIR_CALL_METHOD(&routeId, &route, "getrouteid", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("keyRouteIds"), &routeId, &key TSRMLS_CC);
		if (ZEPHIR_IS_EQUAL(&routeId, id)) {
			RETURN_CCTOR(&route);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_MM_BOOL(0);

}

/**
 * Returns a route object by its name
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName) {

	zend_string *_6;
	zend_ulong _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, route, routeName, key, _0, _3, *_4, _1$$3, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_OBS_VAR(&key);
	zephir_read_property(&_0, this_ptr, SL("keyRouteNames"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&key, &_0, &name, 0 TSRMLS_CC)) {
		zephir_read_property(&_1$$3, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 374 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/Mvc/Router.zep", 389);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&key, _6);
		} else {
			ZVAL_LONG(&key, _5);
		}
		ZEPHIR_INIT_NVAR(&route);
		ZVAL_COPY(&route, _4);
		ZEPHIR_CALL_METHOD(&routeName, &route, "getname", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&routeName))) {
			zephir_update_property_array(this_ptr, SL("keyRouteNames"), &routeName, &key TSRMLS_CC);
			if (ZEPHIR_IS_EQUAL(&routeName, &name)) {
				RETURN_CCTOR(&route);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_MM_BOOL(0);

}

/**
 * Returns all the routes defined in the router
 */
PHP_METHOD(Phalcon_Mvc_Router, getRoutes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "routes");

}

/**
 * Handles routing information received from the rewrite engine
 *
 *<code>
 * // Passing a URL
 * $router->handle("/posts/edit/1");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, handle) {

	zend_string *_32$$32;
	zend_ulong _31$$32;
	zval _27$$27, _37$$38, _39$$41;
	zend_bool _1, _35$$33;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL, *_24 = NULL, *_26 = NULL, *_29 = NULL, *_41 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, __$true, __$false, __$null, request, currentHostName, routeFound, parts, params, matches, notFoundPaths, vnamespace, module, controller, action, paramsStr, strParams, route, methods, container, hostname, regexHostName, matched, pattern, handledUri, beforeMatch, paths, converters, part, position, matchPosition, converter, eventsManager, _0, _3, *_5, _42, _43, _44, _45, _46, _2$$3, _4$$5, _6$$8, _12$$8, _13$$8, _7$$9, _8$$9, _10$$9, _14$$7, _15$$7, _16$$12, _20$$12, _21$$12, _17$$13, _18$$13, _19$$13, _22$$16, _23$$22, _25$$26, _28$$30, *_30$$32, _33$$34, _34$$34, _36$$38, _38$$41, _40$$46, _47$$58, _48$$60, _49$$62;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&currentHostName);
	ZVAL_UNDEF(&routeFound);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&notFoundPaths);
	ZVAL_UNDEF(&vnamespace);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&paramsStr);
	ZVAL_UNDEF(&strParams);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&hostname);
	ZVAL_UNDEF(&regexHostName);
	ZVAL_UNDEF(&matched);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&handledUri);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&converters);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&matchPosition);
	ZVAL_UNDEF(&converter);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_44);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$22);
	ZVAL_UNDEF(&_25$$26);
	ZVAL_UNDEF(&_28$$30);
	ZVAL_UNDEF(&_33$$34);
	ZVAL_UNDEF(&_34$$34);
	ZVAL_UNDEF(&_36$$38);
	ZVAL_UNDEF(&_38$$41);
	ZVAL_UNDEF(&_40$$46);
	ZVAL_UNDEF(&_47$$58);
	ZVAL_UNDEF(&_48$$60);
	ZVAL_UNDEF(&_49$$62);
	ZVAL_UNDEF(&_27$$27);
	ZVAL_UNDEF(&_37$$38);
	ZVAL_UNDEF(&_39$$41);

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


	zephir_read_property(&_0, this_ptr, SL("removeExtraSlashes"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		_1 = !ZEPHIR_IS_STRING(&uri, "/");
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "/");
		ZEPHIR_INIT_VAR(&handledUri);
		zephir_fast_trim(&handledUri, &uri, &_2$$3, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&handledUri, &uri);
	}
	ZEPHIR_INIT_VAR(&request);
	ZVAL_NULL(&request);
	ZEPHIR_INIT_VAR(&currentHostName);
	ZVAL_NULL(&currentHostName);
	ZEPHIR_INIT_VAR(&routeFound);
	ZVAL_BOOL(&routeFound, 0);
	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("wasMatched"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("wasMatched"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("matchedRoute"), &__$null);
	zephir_read_property(&_3, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_3);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "router:beforeCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_4$$5, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property(&_3, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/Mvc/Router.zep", 678);
	ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(&_3), _5)
	{
		ZEPHIR_INIT_NVAR(&route);
		ZVAL_COPY(&route, _5);
		ZEPHIR_INIT_NVAR(&params);
		array_init(&params);
		ZEPHIR_INIT_NVAR(&matches);
		ZVAL_NULL(&matches);
		ZEPHIR_CALL_METHOD(&methods, &route, "gethttpmethods", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&methods) != IS_NULL) {
			if (Z_TYPE_P(&request) == IS_NULL) {
				zephir_read_property(&_6$$8, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&container, &_6$$8);
				if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
					ZEPHIR_INIT_NVAR(&_7$$9);
					object_init_ex(&_7$$9, phalcon_mvc_router_exception_ce);
					ZEPHIR_INIT_NVAR(&_10$$9);
					ZVAL_STRING(&_10$$9, "the 'request' service");
					ZEPHIR_CALL_CE_STATIC(&_8$$9, phalcon_mvc_router_exception_ce, "containerservicenotfound", &_9, 0, &_10$$9);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_7$$9, "__construct", &_11, 1, &_8$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_7$$9, "phalcon/Mvc/Router.zep", 464 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_13$$8);
				ZVAL_STRING(&_13$$8, "request");
				ZEPHIR_CALL_METHOD(&_12$$8, &container, "getshared", NULL, 0, &_13$$8);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&request, &_12$$8);
			}
			ZVAL_BOOL(&_15$$7, 1);
			ZEPHIR_CALL_METHOD(&_14$$7, &request, "ismethod", NULL, 0, &methods, &_15$$7);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_14$$7)) {
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&hostname, &route, "gethostname", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&hostname) != IS_NULL) {
			if (Z_TYPE_P(&request) == IS_NULL) {
				zephir_read_property(&_16$$12, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&container, &_16$$12);
				if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
					ZEPHIR_INIT_NVAR(&_17$$13);
					object_init_ex(&_17$$13, phalcon_mvc_router_exception_ce);
					ZEPHIR_INIT_NVAR(&_19$$13);
					ZVAL_STRING(&_19$$13, "the 'request' service");
					ZEPHIR_CALL_CE_STATIC(&_18$$13, phalcon_mvc_router_exception_ce, "containerservicenotfound", &_9, 0, &_19$$13);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_17$$13, "__construct", &_11, 1, &_18$$13);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_17$$13, "phalcon/Mvc/Router.zep", 495 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_21$$12);
				ZVAL_STRING(&_21$$12, "request");
				ZEPHIR_CALL_METHOD(&_20$$12, &container, "getshared", NULL, 0, &_21$$12);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&request, &_20$$12);
			}
			if (Z_TYPE_P(&currentHostName) == IS_NULL) {
				ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", NULL, 0);
				zephir_check_call_status();
			}
			if (!(zephir_is_true(&currentHostName))) {
				continue;
			}
			if (zephir_memnstr_str(&hostname, SL("("), "phalcon/Mvc/Router.zep", 519)) {
				if (!(zephir_memnstr_str(&hostname, SL("#"), "phalcon/Mvc/Router.zep", 520))) {
					ZEPHIR_INIT_NVAR(&regexHostName);
					ZEPHIR_CONCAT_SV(&regexHostName, "#^", &hostname);
					if (!(zephir_memnstr_str(&hostname, SL(":"), "phalcon/Mvc/Router.zep", 523))) {
						zephir_concat_self_str(&regexHostName, SL("(:[[:digit:]]+)?") TSRMLS_CC);
					}
					zephir_concat_self_str(&regexHostName, SL("$#i") TSRMLS_CC);
				} else {
					ZEPHIR_CPY_WRT(&regexHostName, &hostname);
				}
				ZEPHIR_INIT_NVAR(&_22$$16);
				ZEPHIR_INIT_NVAR(&matched);
				zephir_preg_match(&matched, &regexHostName, &currentHostName, &_22$$16, 0, 0 , 0  TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(&matched);
				ZVAL_BOOL(&matched, ZEPHIR_IS_EQUAL(&currentHostName, &hostname));
			}
			if (!(zephir_is_true(&matched))) {
				continue;
			}
		}
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_23$$22);
			ZVAL_STRING(&_23$$22, "router:beforeCheckRoute");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_24, 0, &_23$$22, this_ptr, &route);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&pattern, &route, "getcompiledpattern", NULL, 0);
		zephir_check_call_status();
		if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/Mvc/Router.zep", 551)) {
			ZEPHIR_INIT_NVAR(&routeFound);
			zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0  TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&routeFound);
			ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, &handledUri));
		}
		if (zephir_is_true(&routeFound)) {
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_25$$26);
				ZVAL_STRING(&_25$$26, "router:matchedRoute");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_26, 0, &_25$$26, this_ptr, &route);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getbeforematch", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
				if (UNEXPECTED(!(zephir_is_callable(&beforeMatch TSRMLS_CC)))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/Mvc/Router.zep", 574);
					return;
				}
				ZEPHIR_INIT_NVAR(&_27$$27);
				zephir_create_array(&_27$$27, 3, 0 TSRMLS_CC);
				zephir_array_fast_append(&_27$$27, &handledUri);
				zephir_array_fast_append(&_27$$27, &route);
				zephir_array_fast_append(&_27$$27, this_ptr);
				ZEPHIR_INIT_NVAR(&routeFound);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_27$$27);
				zephir_check_call_status();
			}
		} else {
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_28$$30);
				ZVAL_STRING(&_28$$30, "router:notMatchedRoute");
				ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_29, 0, &_28$$30, this_ptr, &route);
				zephir_check_call_status();
			}
		}
		if (zephir_is_true(&routeFound)) {
			ZEPHIR_CALL_METHOD(&paths, &route, "getpaths", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&parts, &paths);
			if (Z_TYPE_P(&matches) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(&converters, &route, "getconverters", NULL, 0);
				zephir_check_call_status();
				zephir_is_iterable(&paths, 0, "phalcon/Mvc/Router.zep", 666);
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _31$$32, _32$$32, _30$$32)
				{
					ZEPHIR_INIT_NVAR(&part);
					if (_32$$32 != NULL) { 
						ZVAL_STR_COPY(&part, _32$$32);
					} else {
						ZVAL_LONG(&part, _31$$32);
					}
					ZEPHIR_INIT_NVAR(&position);
					ZVAL_COPY(&position, _30$$32);
					if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
						ZEPHIR_INIT_NVAR(&_33$$34);
						object_init_ex(&_33$$34, phalcon_mvc_router_exception_ce);
						ZEPHIR_INIT_LNVAR(_34$$34);
						ZEPHIR_CONCAT_SV(&_34$$34, "Wrong key in paths: ", &part);
						ZEPHIR_CALL_METHOD(NULL, &_33$$34, "__construct", &_11, 1, &_34$$34);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_33$$34, "phalcon/Mvc/Router.zep", 614 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					_35$$33 = Z_TYPE_P(&position) != IS_STRING;
					if (_35$$33) {
						_35$$33 = Z_TYPE_P(&position) != IS_LONG;
					}
					if (_35$$33) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&matchPosition);
					if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0 TSRMLS_CC)) {
						if (Z_TYPE_P(&converters) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&converter);
							if (zephir_array_isset_fetch(&converter, &converters, &part, 0 TSRMLS_CC)) {
								ZEPHIR_INIT_NVAR(&_36$$38);
								ZEPHIR_INIT_NVAR(&_37$$38);
								zephir_create_array(&_37$$38, 1, 0 TSRMLS_CC);
								zephir_array_fast_append(&_37$$38, &matchPosition);
								ZEPHIR_CALL_USER_FUNC_ARRAY(&_36$$38, &converter, &_37$$38);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, &part, &_36$$38, PH_COPY | PH_SEPARATE);
								continue;
							}
						}
						zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
					} else {
						if (Z_TYPE_P(&converters) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&converter);
							if (zephir_array_isset_fetch(&converter, &converters, &part, 0 TSRMLS_CC)) {
								ZEPHIR_INIT_NVAR(&_38$$41);
								ZEPHIR_INIT_NVAR(&_39$$41);
								zephir_create_array(&_39$$41, 1, 0 TSRMLS_CC);
								zephir_array_fast_append(&_39$$41, &position);
								ZEPHIR_CALL_USER_FUNC_ARRAY(&_38$$41, &converter, &_39$$41);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, &part, &_38$$41, PH_COPY | PH_SEPARATE);
							}
						} else {
							if (Z_TYPE_P(&position) == IS_LONG) {
								zephir_array_unset(&parts, &part, PH_SEPARATE);
							}
						}
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&position);
				ZEPHIR_INIT_NVAR(&part);
				zephir_update_property_zval(this_ptr, SL("matches"), &matches);
			}
			zephir_update_property_zval(this_ptr, SL("matchedRoute"), &route);
			break;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&route);
	if (zephir_is_true(&routeFound)) {
		if (1) {
			zephir_update_property_zval(this_ptr, SL("wasMatched"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("wasMatched"), &__$false);
		}
	} else {
		if (0) {
			zephir_update_property_zval(this_ptr, SL("wasMatched"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("wasMatched"), &__$false);
		}
	}
	if (!(zephir_is_true(&routeFound))) {
		zephir_read_property(&_40$$46, this_ptr, SL("notFoundPaths"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&notFoundPaths, &_40$$46);
		if (Z_TYPE_P(&notFoundPaths) != IS_NULL) {
			ZEPHIR_CALL_CE_STATIC(&parts, phalcon_mvc_router_route_ce, "getroutepaths", &_41, 0, &notFoundPaths);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&routeFound);
			ZVAL_BOOL(&routeFound, 1);
		}
	}
	zephir_read_property(&_42, this_ptr, SL("defaultNamespace"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("namespaceName"), &_42);
	zephir_read_property(&_43, this_ptr, SL("defaultModule"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("module"), &_43);
	zephir_read_property(&_44, this_ptr, SL("defaultController"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("controller"), &_44);
	zephir_read_property(&_45, this_ptr, SL("defaultAction"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("action"), &_45);
	zephir_read_property(&_46, this_ptr, SL("defaultParams"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("params"), &_46);
	if (zephir_is_true(&routeFound)) {
		ZEPHIR_OBS_VAR(&vnamespace);
		if (zephir_array_isset_string_fetch(&vnamespace, &parts, SL("namespace"), 0)) {
			if (!(zephir_is_numeric(&vnamespace))) {
				zephir_update_property_zval(this_ptr, SL("namespaceName"), &vnamespace);
			}
			zephir_array_unset_string(&parts, SL("namespace"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&module);
		if (zephir_array_isset_string_fetch(&module, &parts, SL("module"), 0)) {
			if (!(zephir_is_numeric(&module))) {
				zephir_update_property_zval(this_ptr, SL("module"), &module);
			}
			zephir_array_unset_string(&parts, SL("module"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&controller);
		if (zephir_array_isset_string_fetch(&controller, &parts, SL("controller"), 0)) {
			if (!(zephir_is_numeric(&controller))) {
				zephir_update_property_zval(this_ptr, SL("controller"), &controller);
			}
			zephir_array_unset_string(&parts, SL("controller"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&action);
		if (zephir_array_isset_string_fetch(&action, &parts, SL("action"), 0)) {
			if (!(zephir_is_numeric(&action))) {
				zephir_update_property_zval(this_ptr, SL("action"), &action);
			}
			zephir_array_unset_string(&parts, SL("action"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&paramsStr);
		if (zephir_array_isset_string_fetch(&paramsStr, &parts, SL("params"), 0)) {
			if (Z_TYPE_P(&paramsStr) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_47$$58);
				ZVAL_STRING(&_47$$58, "/");
				ZEPHIR_INIT_VAR(&strParams);
				zephir_fast_trim(&strParams, &paramsStr, &_47$$58, ZEPHIR_TRIM_BOTH TSRMLS_CC);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&strParams, "")) {
					ZEPHIR_INIT_NVAR(&params);
					zephir_fast_explode_str(&params, SL("/"), &strParams, LONG_MAX TSRMLS_CC);
				}
			}
			zephir_array_unset_string(&parts, SL("params"), PH_SEPARATE);
		}
		if (zephir_fast_count_int(&params TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_48$$60);
			zephir_fast_array_merge(&_48$$60, &params, &parts TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("params"), &_48$$60);
		} else {
			zephir_update_property_zval(this_ptr, SL("params"), &parts);
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_49$$62);
		ZVAL_STRING(&_49$$62, "router:afterCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_49$$62, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns whether controller name should not be mangled
 */
PHP_METHOD(Phalcon_Mvc_Router, isExactControllerName) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * Mounts a group of routes in the router
 */
PHP_METHOD(Phalcon_Mvc_Router, mount) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group, group_sub, groupRoutes, beforeMatch, hostname, routes, route, eventsManager, _0, _4, _1$$3, *_2$$5, *_3$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&groupRoutes);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&hostname);
	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);



	zephir_read_property(&_0, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "router:beforeMount");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_1$$3, this_ptr, group);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&groupRoutes, group, "getroutes", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!(zephir_fast_count_int(&groupRoutes TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "The group of routes does not contain any routes", "phalcon/Mvc/Router.zep", 803);
		return;
	}
	ZEPHIR_CALL_METHOD(&beforeMatch, group, "getbeforematch", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
		zephir_is_iterable(&groupRoutes, 0, "phalcon/Mvc/Router.zep", 815);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groupRoutes), _2$$5)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _2$$5);
			ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&route);
	}
	ZEPHIR_CALL_METHOD(&hostname, group, "gethostname", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&hostname) != IS_NULL) {
		zephir_is_iterable(&groupRoutes, 0, "phalcon/Mvc/Router.zep", 824);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groupRoutes), _3$$7)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _3$$7);
			ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &hostname);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&route);
	}
	zephir_read_property(&_0, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&routes, &_0);
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_array_merge(&_4, &routes, &groupRoutes TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("routes"), &_4);
	RETURN_THIS();

}

/**
 * Set a group of paths to be returned when none of the defined routes are
 * matched
 */
PHP_METHOD(Phalcon_Mvc_Router, notFound) {

	zend_bool _0;
	zval *paths, paths_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&paths_sub);

	zephir_fetch_params(0, 1, 0, &paths);



	_0 = Z_TYPE_P(paths) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(paths) != IS_STRING;
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_router_exception_ce, "The not-found paths must be an array or string", "phalcon/Mvc/Router.zep", 842);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("notFoundPaths"), paths);
	RETURN_THISW();

}

/**
 * Set whether router must remove the extra slashes in the handled routes
 */
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes) {

	zval *remove_param = NULL, __$true, __$false;
	zend_bool remove;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &remove_param);

	if (UNEXPECTED(Z_TYPE_P(remove_param) != IS_TRUE && Z_TYPE_P(remove_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'remove' must be of the type bool") TSRMLS_CC);
		RETURN_NULL();
	}
	remove = (Z_TYPE_P(remove_param) == IS_TRUE);


	if (remove) {
		zephir_update_property_zval(this_ptr, SL("removeExtraSlashes"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("removeExtraSlashes"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets the default action name
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction) {

	zval *actionName_param = NULL;
	zval actionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

	if (UNEXPECTED(Z_TYPE_P(actionName_param) != IS_STRING && Z_TYPE_P(actionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(actionName_param) == IS_STRING)) {
		zephir_get_strval(&actionName, actionName_param);
	} else {
		ZEPHIR_INIT_VAR(&actionName);
		ZVAL_EMPTY_STRING(&actionName);
	}


	zephir_update_property_zval(this_ptr, SL("defaultAction"), &actionName);
	RETURN_THIS();

}

/**
 * Sets the default controller name
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultController) {

	zval *controllerName_param = NULL;
	zval controllerName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerName_param);

	if (UNEXPECTED(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(&controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerName);
		ZVAL_EMPTY_STRING(&controllerName);
	}


	zephir_update_property_zval(this_ptr, SL("defaultController"), &controllerName);
	RETURN_THIS();

}

/**
 * Sets the name of the default module
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule) {

	zval *moduleName_param = NULL;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	if (UNEXPECTED(Z_TYPE_P(moduleName_param) != IS_STRING && Z_TYPE_P(moduleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleName_param) == IS_STRING)) {
		zephir_get_strval(&moduleName, moduleName_param);
	} else {
		ZEPHIR_INIT_VAR(&moduleName);
		ZVAL_EMPTY_STRING(&moduleName);
	}


	zephir_update_property_zval(this_ptr, SL("defaultModule"), &moduleName);
	RETURN_THIS();

}

/**
 * Sets the name of the default namespace
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace) {

	zval *namespaceName_param = NULL;
	zval namespaceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);

	if (UNEXPECTED(Z_TYPE_P(namespaceName_param) != IS_STRING && Z_TYPE_P(namespaceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'namespaceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(namespaceName_param) == IS_STRING)) {
		zephir_get_strval(&namespaceName, namespaceName_param);
	} else {
		ZEPHIR_INIT_VAR(&namespaceName);
		ZVAL_EMPTY_STRING(&namespaceName);
	}


	zephir_update_property_zval(this_ptr, SL("defaultNamespace"), &namespaceName);
	RETURN_THIS();

}

/**
 * Sets an array of default paths. If a route is missing a path the router
 * will use the defined here. This method must not be used to set a 404
 * route
 *
 *<code>
 * $router->setDefaults(
 *     [
 *         "module" => "common",
 *         "action" => "index",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaults) {

	zval *defaults_param = NULL, namespaceName, module, controller, action, params;
	zval defaults;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaults_param);

	ZEPHIR_OBS_COPY_OR_DUP(&defaults, defaults_param);


	if (zephir_array_isset_string_fetch(&namespaceName, &defaults, SL("namespace"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultNamespace"), &namespaceName);
	}
	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultModule"), &module);
	}
	if (zephir_array_isset_string_fetch(&controller, &defaults, SL("controller"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultController"), &controller);
	}
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultAction"), &action);
	}
	if (zephir_array_isset_string_fetch(&params, &defaults, SL("params"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultParams"), &params);
	}
	RETURN_THIS();

}

/**
 * Returns an array of default parameters
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaults) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 5, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("defaultNamespace"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("namespace"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("defaultModule"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("module"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("defaultController"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("controller"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("defaultAction"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("action"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("defaultParams"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("params"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Mvc_Router, setDI) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Mvc_Router, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("eventsManager"), eventsManager);

}

/**
 * Checks if the router matches any of the defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, wasMatched) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "wasMatched");

}

zend_object *zephir_init_properties_Phalcon_Mvc_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("params"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("keyRouteIds"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("keyRouteIds"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("keyRouteNames"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("keyRouteNames"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("defaultParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("defaultParams"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

