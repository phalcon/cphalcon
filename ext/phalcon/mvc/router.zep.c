
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
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
 * ```php
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
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Router, phalcon, mvc_router, phalcon_di_abstractinjectionaware_ce, phalcon_mvc_router_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_router_ce, SL("action"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_router_ce, SL("controller"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_router_ce, SL("defaultAction"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_router_ce, SL("defaultController"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_router_ce, SL("defaultModule"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_router_ce, SL("defaultNamespace"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("defaultParams"), ZEND_ACC_PROTECTED);
	/**
	 * @var ManagerInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("keyRouteNames"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("keyRouteIds"), ZEND_ACC_PROTECTED);
	/**
	 * @var RouteInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("matchedRoute"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("matches"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_router_ce, SL("module"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_router_ce, SL("namespaceName"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var array|string|null
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("notFoundPaths"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("params"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_router_ce, SL("removeExtraSlashes"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("routes"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_router_ce, SL("wasMatched"), 0, ZEND_ACC_PROTECTED);
	phalcon_mvc_router_ce->create_object = zephir_init_properties_Phalcon_Mvc_Router;
	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("POSITION_FIRST"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("POSITION_LAST"), 1);

	zend_class_implements(phalcon_mvc_router_ce, 1, phalcon_mvc_routerinterface_ce);
	zend_class_implements(phalcon_mvc_router_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Router constructor
 *
 * @param bool defaultRoutes
 */
PHP_METHOD(Phalcon_Mvc_Router, __construct)
{
	zval routes, _1$$3, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(defaultRoutes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &defaultRoutes_param);
	if (!defaultRoutes_param) {
		defaultRoutes = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(defaultRoutes_param) != IS_TRUE && Z_TYPE_P(defaultRoutes_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'defaultRoutes' must be of the type bool"));
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
		zephir_create_array(&_1$$3, 1, 0);
		add_assoc_long_ex(&_1$$3, SL("controller"), 1);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "#^/([\\w0-9\\_\\-]+)[/]{0,1}$#u");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 101, &_2$$3, &_1$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, &_0$$3, PH_SEPARATE, "phalcon/Mvc/Router.zep", 170);
		ZEPHIR_INIT_NVAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0);
		add_assoc_long_ex(&_3$$3, SL("controller"), 1);
		add_assoc_long_ex(&_3$$3, SL("action"), 2);
		add_assoc_long_ex(&_3$$3, SL("params"), 3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "#^/([\\w0-9\\_\\-]+)/([\\w0-9\\.\\_]+)(/.*)*$#u");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 101, &_4$$3, &_3$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, &_2$$3, PH_SEPARATE, "phalcon/Mvc/Router.zep", 179);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("routes"), &routes);
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds a route to the router without any HTTP constraint
 *
 *```php
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
 *```
 *
 * @param string pattern
 * @param string|array|null paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 * @param string|array|null httpMethods
 * @param int position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *httpMethods = NULL, httpMethods_sub, *position_param = NULL, __$null, route, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&httpMethods_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
		Z_PARAM_ZVAL_OR_NULL(httpMethods)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 3, &pattern_param, &paths, &httpMethods, &position_param);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!httpMethods) {
		httpMethods = &httpMethods_sub;
		httpMethods = &__$null;
	}
	if (!position_param) {
		position = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&route);
	object_init_ex(&route, phalcon_mvc_router_route_ce);
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 101, &pattern, paths, httpMethods);
	zephir_check_call_status();
	ZVAL_LONG(&_0, position);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, &route, &_0);
	zephir_check_call_status();
	RETURN_CCTOR(&route);
}

/**
 * Adds a route to the router that only match if the HTTP method is CONNECT
 *
 * @param string pattern
 * @param string|array|null paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 * @param int position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addConnect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position_param);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position_param) {
		position = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "CONNECT");
	ZVAL_LONG(&_1, position);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string param
 * @param string|array|null paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 * @param int position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addDelete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position_param);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position_param) {
		position = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DELETE");
	ZVAL_LONG(&_1, position);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string param
 * @param string|array|null paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 * @param int position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position_param);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position_param) {
		position = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GET");
	ZVAL_LONG(&_1, position);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string pattern
 * @param string|array|null paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 * @param int position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addHead)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position_param);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position_param) {
		position = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HEAD");
	ZVAL_LONG(&_1, position);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string pattern
 * @param string|array|null paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 * @param int position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position_param);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position_param) {
		position = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "OPTIONS");
	ZVAL_LONG(&_1, position);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 *
 * @param string pattern
 * @param string|array|null paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 * @param int position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addPatch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position_param);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position_param) {
		position = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PATCH");
	ZVAL_LONG(&_1, position);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string pattern
 * @param string|array|null paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 * @param int position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addPost)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position_param);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position_param) {
		position = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "POST");
	ZVAL_LONG(&_1, position);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is PURGE
 * (Squid and Varnish support)
 *
 * @param string pattern
 * @param string|array|null paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 * @param int position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addPurge)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position_param);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position_param) {
		position = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PURGE");
	ZVAL_LONG(&_1, position);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string pattern
 * @param string|array paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 * @param int position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addPut)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position_param);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position_param) {
		position = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PUT");
	ZVAL_LONG(&_1, position);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is TRACE
 *
 * @param string pattern
 * @param string|array|null paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 * @param int position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addTrace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position_param);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position_param) {
		position = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "TRACE");
	ZVAL_LONG(&_1, position);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Attach Route object to the routes stack.
 *
 * ```php
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
 * ```
 *
 * @param RouteInterface route
 * @param int position
 *
 * @return RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, attach)
{
	zval _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position;
	zval *route, route_sub, *position_param = NULL, _0$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_1$$4);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(route, phalcon_mvc_router_routeinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &route, &position_param);
	if (!position_param) {
		position = 1;
	} else {
		}
	do {
		if (position == 1) {
			zephir_update_property_array_append(this_ptr, SL("routes"), route);
			break;
		}
		if (position == 0) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZEPHIR_INIT_VAR(&_1$$4);
			zephir_create_array(&_1$$4, 1, 0);
			zephir_array_fast_append(&_1$$4, route);
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
			zephir_fast_array_merge(&_0$$4, &_1$$4, &_2$$4);
			zephir_update_property_zval(this_ptr, ZEND_STRL("routes"), &_0$$4);
			break;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Invalid route position", "phalcon/Mvc/Router.zep", 494);
		return;
	} while(0);

	RETURN_THIS();
}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, clear)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("routes"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Mvc_Router, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Returns the processed action name
 */
PHP_METHOD(Phalcon_Mvc_Router, getActionName)
{

	RETURN_MEMBER(getThis(), "action");
}

/**
 * Returns the processed controller name
 */
PHP_METHOD(Phalcon_Mvc_Router, getControllerName)
{

	RETURN_MEMBER(getThis(), "controller");
}

/**
 * Returns an array of default parameters
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaults)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_create_array(return_value, 5, 0);
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultNamespace"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("namespace"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("module"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultController"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("controller"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultAction"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("action"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultParams"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("params"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteNames)
{

	RETURN_MEMBER(getThis(), "keyRouteNames");
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteIds)
{

	RETURN_MEMBER(getThis(), "keyRouteIds");
}

/**
 * Returns the route that matches the handled URI
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute)
{

	RETURN_MEMBER(getThis(), "matchedRoute");
}

/**
 * Returns the sub expressions in the regular expression matched
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatches)
{

	RETURN_MEMBER(getThis(), "matches");
}

/**
 * Returns the processed module name
 */
PHP_METHOD(Phalcon_Mvc_Router, getModuleName)
{

	RETURN_MEMBER(getThis(), "module");
}

/**
 * Returns the processed namespace name
 */
PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName)
{

	RETURN_MEMBER(getThis(), "namespaceName");
}

/**
 * Returns the processed parameters
 */
PHP_METHOD(Phalcon_Mvc_Router, getParams)
{

	RETURN_MEMBER(getThis(), "params");
}

/**
 * Returns a route object by its id
 *
 * @param mixed $id
 *
 * @return RouteInterface|bool
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteById)
{
	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, route, routeId, key, _0, _3, *_4, _5, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routeId);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &id);
	zephir_memory_observe(&key);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("keyRouteIds"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&key, &_0, id, 0)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 614);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/Mvc/Router.zep", 626);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&key, _7);
			} else {
				ZVAL_LONG(&key, _6);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _4);
			ZEPHIR_CALL_METHOD(&routeId, &route, "getrouteid", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("keyRouteIds"), &routeId, &key);
			if (ZEPHIR_IS_EQUAL(&routeId, id)) {
				RETURN_CCTOR(&route);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, &_3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&routeId, &route, "getrouteid", NULL, 0);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("keyRouteIds"), &routeId, &key);
				if (ZEPHIR_IS_EQUAL(&routeId, id)) {
					RETURN_CCTOR(&route);
				}
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_MM_BOOL(0);
}

/**
 * Returns a route object by its name
 *
 * @param string name
 *
 * @return RouteInterface|bool
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName)
{
	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, route, routeName, key, _0, _3, *_4, _5, _1$$3, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	zephir_memory_observe(&key);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("keyRouteNames"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&key, &_0, &name, 0)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 641);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/Mvc/Router.zep", 656);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&key, _7);
			} else {
				ZVAL_LONG(&key, _6);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _4);
			ZEPHIR_CALL_METHOD(&routeName, &route, "getname", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&routeName))) {
				zephir_update_property_array(this_ptr, SL("keyRouteNames"), &routeName, &key);
				if (ZEPHIR_IS_EQUAL(&routeName, &name)) {
					RETURN_CCTOR(&route);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, &_3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&routeName, &route, "getname", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&routeName))) {
					zephir_update_property_array(this_ptr, SL("keyRouteNames"), &routeName, &key);
					if (ZEPHIR_IS_EQUAL(&routeName, &name)) {
						RETURN_CCTOR(&route);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_MM_BOOL(0);
}

/**
 * Returns all the routes defined in the router
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getRoutes)
{

	RETURN_MEMBER(getThis(), "routes");
}

/**
 * Handles routing information received from the rewrite engine
 *
 *```php
 * // Passing a URL
 * $router->handle("/posts/edit/1");
 *```
 *
 * @param string uri
 *
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_Router, handle)
{
	zend_string *_25$$30, *_56$$75;
	zend_ulong _24$$30, _55$$75;
	zval _19$$25, _31$$36, _33$$39, _38$$47, _40$$50, _50$$70, _61$$81, _63$$84, _68$$92, _70$$95;
	zend_bool _2, _29$$31, _36$$42, _59$$76, _66$$87;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL, *_13 = NULL, *_16 = NULL, *_18 = NULL, *_21 = NULL, *_28 = NULL, *_43 = NULL, *_44 = NULL, *_47 = NULL, *_49 = NULL, *_52 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, __$true, __$false, __$null, request, currentHostName, routeFound, parts, params, matches, notFoundPaths, vnamespace, module, controller, action, paramsStr, strParams, route, methods, container, hostname, regexHostName, matched, pattern, handledUri, beforeMatch, paths, converters, part, position, matchPosition, converter, eventsManager, _0, _1, _4, _6, _7, *_8, _9, _72, _73, _74, _75, _76, _3$$3, _5$$6, _10$$9, _11$$9, _14$$14, _15$$20, _17$$24, _20$$28, *_22$$30, _23$$30, _26$$32, _27$$32, _30$$36, _32$$39, _34$$43, _35$$43, _37$$47, _39$$50, _41$$54, _42$$54, _45$$59, _46$$65, _48$$69, _51$$73, *_53$$75, _54$$75, _57$$77, _58$$77, _60$$81, _62$$84, _64$$88, _65$$88, _67$$92, _69$$95, _71$$100, _77$$108, _78$$110, _79$$112;
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_72);
	ZVAL_UNDEF(&_73);
	ZVAL_UNDEF(&_74);
	ZVAL_UNDEF(&_75);
	ZVAL_UNDEF(&_76);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$20);
	ZVAL_UNDEF(&_17$$24);
	ZVAL_UNDEF(&_20$$28);
	ZVAL_UNDEF(&_23$$30);
	ZVAL_UNDEF(&_26$$32);
	ZVAL_UNDEF(&_27$$32);
	ZVAL_UNDEF(&_30$$36);
	ZVAL_UNDEF(&_32$$39);
	ZVAL_UNDEF(&_34$$43);
	ZVAL_UNDEF(&_35$$43);
	ZVAL_UNDEF(&_37$$47);
	ZVAL_UNDEF(&_39$$50);
	ZVAL_UNDEF(&_41$$54);
	ZVAL_UNDEF(&_42$$54);
	ZVAL_UNDEF(&_45$$59);
	ZVAL_UNDEF(&_46$$65);
	ZVAL_UNDEF(&_48$$69);
	ZVAL_UNDEF(&_51$$73);
	ZVAL_UNDEF(&_54$$75);
	ZVAL_UNDEF(&_57$$77);
	ZVAL_UNDEF(&_58$$77);
	ZVAL_UNDEF(&_60$$81);
	ZVAL_UNDEF(&_62$$84);
	ZVAL_UNDEF(&_64$$88);
	ZVAL_UNDEF(&_65$$88);
	ZVAL_UNDEF(&_67$$92);
	ZVAL_UNDEF(&_69$$95);
	ZVAL_UNDEF(&_71$$100);
	ZVAL_UNDEF(&_77$$108);
	ZVAL_UNDEF(&_78$$110);
	ZVAL_UNDEF(&_79$$112);
	ZVAL_UNDEF(&_19$$25);
	ZVAL_UNDEF(&_31$$36);
	ZVAL_UNDEF(&_33$$39);
	ZVAL_UNDEF(&_38$$47);
	ZVAL_UNDEF(&_40$$50);
	ZVAL_UNDEF(&_50$$70);
	ZVAL_UNDEF(&_61$$81);
	ZVAL_UNDEF(&_63$$84);
	ZVAL_UNDEF(&_68$$92);
	ZVAL_UNDEF(&_70$$95);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &uri_param);
	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
	}
	ZVAL_LONG(&_0, 5);
	ZEPHIR_CALL_FUNCTION(&_1, "parse_url", NULL, 102, &uri, &_0);
	zephir_check_call_status();
	zephir_get_strval(&uri, &_1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("removeExtraSlashes"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_is_true(&_0);
	if (_2) {
		_2 = !ZEPHIR_IS_STRING_IDENTICAL(&uri, "/");
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "/");
		ZEPHIR_INIT_VAR(&handledUri);
		zephir_fast_trim(&handledUri, &uri, &_3$$3, ZEPHIR_TRIM_RIGHT);
	} else {
		ZEPHIR_CPY_WRT(&handledUri, &uri);
	}
	if (ZEPHIR_IS_EMPTY(&handledUri)) {
		ZEPHIR_INIT_NVAR(&handledUri);
		ZVAL_STRING(&handledUri, "/");
	}
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("wasMatched"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("wasMatched"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("matchedRoute"), &__$null);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_4);
	if (Z_TYPE_P(&eventsManager) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_5$$6);
		ZVAL_STRING(&_5$$6, "router:beforeCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_5$$6, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_4);
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service", "phalcon/Mvc/Router.zep", 724);
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "request");
	ZEPHIR_CALL_METHOD(&_6, &container, "get", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&request, &_6);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "phalcon/Mvc/Router.zep", 930);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(&_4), _8)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _8);
			ZEPHIR_INIT_NVAR(&params);
			array_init(&params);
			ZEPHIR_INIT_NVAR(&matches);
			ZVAL_NULL(&matches);
			ZEPHIR_CALL_METHOD(&methods, &route, "gethttpmethods", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&methods) != IS_NULL) {
				ZVAL_BOOL(&_11$$9, 1);
				ZEPHIR_CALL_METHOD(&_10$$9, &request, "ismethod", &_12, 0, &methods, &_11$$9);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_10$$9)) {
					continue;
				}
			}
			ZEPHIR_CALL_METHOD(&hostname, &route, "gethostname", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&hostname) != IS_NULL) {
				if (Z_TYPE_P(&currentHostName) == IS_NULL) {
					ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", &_13, 0);
					zephir_check_call_status();
				}
				if (!(zephir_is_true(&currentHostName))) {
					continue;
				}
				if (zephir_memnstr_str(&hostname, SL("("), "phalcon/Mvc/Router.zep", 772)) {
					if (!(zephir_memnstr_str(&hostname, SL("#"), "phalcon/Mvc/Router.zep", 773))) {
						ZEPHIR_INIT_NVAR(&regexHostName);
						ZEPHIR_CONCAT_SV(&regexHostName, "#^", &hostname);
						if (!(zephir_memnstr_str(&hostname, SL(":"), "phalcon/Mvc/Router.zep", 776))) {
							zephir_concat_self_str(&regexHostName, SL("(:[[:digit:]]+)?"));
						}
						zephir_concat_self_str(&regexHostName, SL("$#i"));
					} else {
						ZEPHIR_CPY_WRT(&regexHostName, &hostname);
					}
					ZEPHIR_INIT_NVAR(&_14$$14);
					ZEPHIR_INIT_NVAR(&matched);
					zephir_preg_match(&matched, &regexHostName, &currentHostName, &_14$$14, 0, 0 , 0 );
				} else {
					ZEPHIR_INIT_NVAR(&matched);
					ZVAL_BOOL(&matched, ZEPHIR_IS_EQUAL(&currentHostName, &hostname));
				}
				if (!(zephir_is_true(&matched))) {
					continue;
				}
			}
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_15$$20);
				ZVAL_STRING(&_15$$20, "router:beforeCheckRoute");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_16, 0, &_15$$20, this_ptr, &route);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&pattern, &route, "getcompiledpattern", NULL, 0);
			zephir_check_call_status();
			if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/Mvc/Router.zep", 804)) {
				ZEPHIR_INIT_NVAR(&routeFound);
				zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
			} else {
				ZEPHIR_INIT_NVAR(&routeFound);
				ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, &handledUri));
			}
			if (zephir_is_true(&routeFound)) {
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_17$$24);
					ZVAL_STRING(&_17$$24, "router:matchedRoute");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_18, 0, &_17$$24, this_ptr, &route);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getbeforematch", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
					if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/Mvc/Router.zep", 826);
						return;
					}
					ZEPHIR_INIT_NVAR(&_19$$25);
					zephir_create_array(&_19$$25, 3, 0);
					zephir_array_fast_append(&_19$$25, &handledUri);
					zephir_array_fast_append(&_19$$25, &route);
					zephir_array_fast_append(&_19$$25, this_ptr);
					ZEPHIR_INIT_NVAR(&routeFound);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_19$$25);
					zephir_check_call_status();
				}
			} else {
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_20$$28);
					ZVAL_STRING(&_20$$28, "router:notMatchedRoute");
					ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_21, 0, &_20$$28, this_ptr, &route);
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
					zephir_is_iterable(&paths, 0, "phalcon/Mvc/Router.zep", 918);
					if (Z_TYPE_P(&paths) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _24$$30, _25$$30, _22$$30)
						{
							ZEPHIR_INIT_NVAR(&part);
							if (_25$$30 != NULL) { 
								ZVAL_STR_COPY(&part, _25$$30);
							} else {
								ZVAL_LONG(&part, _24$$30);
							}
							ZEPHIR_INIT_NVAR(&position);
							ZVAL_COPY(&position, _22$$30);
							if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
								ZEPHIR_INIT_NVAR(&_26$$32);
								object_init_ex(&_26$$32, phalcon_mvc_router_exception_ce);
								ZEPHIR_INIT_NVAR(&_27$$32);
								ZEPHIR_CONCAT_SV(&_27$$32, "Wrong key in paths: ", &part);
								ZEPHIR_CALL_METHOD(NULL, &_26$$32, "__construct", &_28, 33, &_27$$32);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_26$$32, "phalcon/Mvc/Router.zep", 866);
								ZEPHIR_MM_RESTORE();
								return;
							}
							_29$$31 = Z_TYPE_P(&position) != IS_STRING;
							if (_29$$31) {
								_29$$31 = Z_TYPE_P(&position) != IS_LONG;
							}
							if (_29$$31) {
								continue;
							}
							ZEPHIR_OBS_NVAR(&matchPosition);
							if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
								if (Z_TYPE_P(&converters) == IS_ARRAY) {
									ZEPHIR_OBS_NVAR(&converter);
									if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
										ZEPHIR_INIT_NVAR(&_30$$36);
										ZEPHIR_INIT_NVAR(&_31$$36);
										zephir_create_array(&_31$$36, 1, 0);
										zephir_array_fast_append(&_31$$36, &matchPosition);
										ZEPHIR_CALL_USER_FUNC_ARRAY(&_30$$36, &converter, &_31$$36);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_30$$36, PH_COPY | PH_SEPARATE);
										continue;
									}
								}
								zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
							} else {
								if (Z_TYPE_P(&converters) == IS_ARRAY) {
									ZEPHIR_OBS_NVAR(&converter);
									if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
										ZEPHIR_INIT_NVAR(&_32$$39);
										ZEPHIR_INIT_NVAR(&_33$$39);
										zephir_create_array(&_33$$39, 1, 0);
										zephir_array_fast_append(&_33$$39, &position);
										ZEPHIR_CALL_USER_FUNC_ARRAY(&_32$$39, &converter, &_33$$39);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_32$$39, PH_COPY | PH_SEPARATE);
									}
								} else {
									if (Z_TYPE_P(&position) == IS_LONG) {
										zephir_array_unset(&parts, &part, PH_SEPARATE);
									}
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_23$$30, &paths, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_23$$30)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&part, &paths, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&position, &paths, "current", NULL, 0);
							zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
									ZEPHIR_INIT_NVAR(&_34$$43);
									object_init_ex(&_34$$43, phalcon_mvc_router_exception_ce);
									ZEPHIR_INIT_NVAR(&_35$$43);
									ZEPHIR_CONCAT_SV(&_35$$43, "Wrong key in paths: ", &part);
									ZEPHIR_CALL_METHOD(NULL, &_34$$43, "__construct", &_28, 33, &_35$$43);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_34$$43, "phalcon/Mvc/Router.zep", 866);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_36$$42 = Z_TYPE_P(&position) != IS_STRING;
								if (_36$$42) {
									_36$$42 = Z_TYPE_P(&position) != IS_LONG;
								}
								if (_36$$42) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&matchPosition);
								if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_37$$47);
											ZEPHIR_INIT_NVAR(&_38$$47);
											zephir_create_array(&_38$$47, 1, 0);
											zephir_array_fast_append(&_38$$47, &matchPosition);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_37$$47, &converter, &_38$$47);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_37$$47, PH_COPY | PH_SEPARATE);
											continue;
										}
									}
									zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
								} else {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_39$$50);
											ZEPHIR_INIT_NVAR(&_40$$50);
											zephir_create_array(&_40$$50, 1, 0);
											zephir_array_fast_append(&_40$$50, &position);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_39$$50, &converter, &_40$$50);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_39$$50, PH_COPY | PH_SEPARATE);
										}
									} else {
										if (Z_TYPE_P(&position) == IS_LONG) {
											zephir_array_unset(&parts, &part, PH_SEPARATE);
										}
									}
								}
							ZEPHIR_CALL_METHOD(NULL, &paths, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&position);
					ZEPHIR_INIT_NVAR(&part);
					zephir_update_property_zval(this_ptr, ZEND_STRL("matches"), &matches);
				}
				zephir_update_property_zval(this_ptr, ZEND_STRL("matchedRoute"), &route);
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_9, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &_4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&params);
				array_init(&params);
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				ZEPHIR_CALL_METHOD(&methods, &route, "gethttpmethods", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&methods) != IS_NULL) {
					ZVAL_BOOL(&_42$$54, 1);
					ZEPHIR_CALL_METHOD(&_41$$54, &request, "ismethod", &_43, 0, &methods, &_42$$54);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_41$$54)) {
						continue;
					}
				}
				ZEPHIR_CALL_METHOD(&hostname, &route, "gethostname", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&hostname) != IS_NULL) {
					if (Z_TYPE_P(&currentHostName) == IS_NULL) {
						ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", &_44, 0);
						zephir_check_call_status();
					}
					if (!(zephir_is_true(&currentHostName))) {
						continue;
					}
					if (zephir_memnstr_str(&hostname, SL("("), "phalcon/Mvc/Router.zep", 772)) {
						if (!(zephir_memnstr_str(&hostname, SL("#"), "phalcon/Mvc/Router.zep", 773))) {
							ZEPHIR_INIT_NVAR(&regexHostName);
							ZEPHIR_CONCAT_SV(&regexHostName, "#^", &hostname);
							if (!(zephir_memnstr_str(&hostname, SL(":"), "phalcon/Mvc/Router.zep", 776))) {
								zephir_concat_self_str(&regexHostName, SL("(:[[:digit:]]+)?"));
							}
							zephir_concat_self_str(&regexHostName, SL("$#i"));
						} else {
							ZEPHIR_CPY_WRT(&regexHostName, &hostname);
						}
						ZEPHIR_INIT_NVAR(&_45$$59);
						ZEPHIR_INIT_NVAR(&matched);
						zephir_preg_match(&matched, &regexHostName, &currentHostName, &_45$$59, 0, 0 , 0 );
					} else {
						ZEPHIR_INIT_NVAR(&matched);
						ZVAL_BOOL(&matched, ZEPHIR_IS_EQUAL(&currentHostName, &hostname));
					}
					if (!(zephir_is_true(&matched))) {
						continue;
					}
				}
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_46$$65);
					ZVAL_STRING(&_46$$65, "router:beforeCheckRoute");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_47, 0, &_46$$65, this_ptr, &route);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&pattern, &route, "getcompiledpattern", NULL, 0);
				zephir_check_call_status();
				if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/Mvc/Router.zep", 804)) {
					ZEPHIR_INIT_NVAR(&routeFound);
					zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
				} else {
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, &handledUri));
				}
				if (zephir_is_true(&routeFound)) {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_48$$69);
						ZVAL_STRING(&_48$$69, "router:matchedRoute");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_49, 0, &_48$$69, this_ptr, &route);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getbeforematch", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/Mvc/Router.zep", 826);
							return;
						}
						ZEPHIR_INIT_NVAR(&_50$$70);
						zephir_create_array(&_50$$70, 3, 0);
						zephir_array_fast_append(&_50$$70, &handledUri);
						zephir_array_fast_append(&_50$$70, &route);
						zephir_array_fast_append(&_50$$70, this_ptr);
						ZEPHIR_INIT_NVAR(&routeFound);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_50$$70);
						zephir_check_call_status();
					}
				} else {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_51$$73);
						ZVAL_STRING(&_51$$73, "router:notMatchedRoute");
						ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_52, 0, &_51$$73, this_ptr, &route);
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
						zephir_is_iterable(&paths, 0, "phalcon/Mvc/Router.zep", 918);
						if (Z_TYPE_P(&paths) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _55$$75, _56$$75, _53$$75)
							{
								ZEPHIR_INIT_NVAR(&part);
								if (_56$$75 != NULL) { 
									ZVAL_STR_COPY(&part, _56$$75);
								} else {
									ZVAL_LONG(&part, _55$$75);
								}
								ZEPHIR_INIT_NVAR(&position);
								ZVAL_COPY(&position, _53$$75);
								if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
									ZEPHIR_INIT_NVAR(&_57$$77);
									object_init_ex(&_57$$77, phalcon_mvc_router_exception_ce);
									ZEPHIR_INIT_NVAR(&_58$$77);
									ZEPHIR_CONCAT_SV(&_58$$77, "Wrong key in paths: ", &part);
									ZEPHIR_CALL_METHOD(NULL, &_57$$77, "__construct", &_28, 33, &_58$$77);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_57$$77, "phalcon/Mvc/Router.zep", 866);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_59$$76 = Z_TYPE_P(&position) != IS_STRING;
								if (_59$$76) {
									_59$$76 = Z_TYPE_P(&position) != IS_LONG;
								}
								if (_59$$76) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&matchPosition);
								if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_60$$81);
											ZEPHIR_INIT_NVAR(&_61$$81);
											zephir_create_array(&_61$$81, 1, 0);
											zephir_array_fast_append(&_61$$81, &matchPosition);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_60$$81, &converter, &_61$$81);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_60$$81, PH_COPY | PH_SEPARATE);
											continue;
										}
									}
									zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
								} else {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_62$$84);
											ZEPHIR_INIT_NVAR(&_63$$84);
											zephir_create_array(&_63$$84, 1, 0);
											zephir_array_fast_append(&_63$$84, &position);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_62$$84, &converter, &_63$$84);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_62$$84, PH_COPY | PH_SEPARATE);
										}
									} else {
										if (Z_TYPE_P(&position) == IS_LONG) {
											zephir_array_unset(&parts, &part, PH_SEPARATE);
										}
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_54$$75, &paths, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_54$$75)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&part, &paths, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&position, &paths, "current", NULL, 0);
								zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
										ZEPHIR_INIT_NVAR(&_64$$88);
										object_init_ex(&_64$$88, phalcon_mvc_router_exception_ce);
										ZEPHIR_INIT_NVAR(&_65$$88);
										ZEPHIR_CONCAT_SV(&_65$$88, "Wrong key in paths: ", &part);
										ZEPHIR_CALL_METHOD(NULL, &_64$$88, "__construct", &_28, 33, &_65$$88);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_64$$88, "phalcon/Mvc/Router.zep", 866);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_66$$87 = Z_TYPE_P(&position) != IS_STRING;
									if (_66$$87) {
										_66$$87 = Z_TYPE_P(&position) != IS_LONG;
									}
									if (_66$$87) {
										continue;
									}
									ZEPHIR_OBS_NVAR(&matchPosition);
									if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_INIT_NVAR(&_67$$92);
												ZEPHIR_INIT_NVAR(&_68$$92);
												zephir_create_array(&_68$$92, 1, 0);
												zephir_array_fast_append(&_68$$92, &matchPosition);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_67$$92, &converter, &_68$$92);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_67$$92, PH_COPY | PH_SEPARATE);
												continue;
											}
										}
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
									} else {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_INIT_NVAR(&_69$$95);
												ZEPHIR_INIT_NVAR(&_70$$95);
												zephir_create_array(&_70$$95, 1, 0);
												zephir_array_fast_append(&_70$$95, &position);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_69$$95, &converter, &_70$$95);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_69$$95, PH_COPY | PH_SEPARATE);
											}
										} else {
											if (Z_TYPE_P(&position) == IS_LONG) {
												zephir_array_unset(&parts, &part, PH_SEPARATE);
											}
										}
									}
								ZEPHIR_CALL_METHOD(NULL, &paths, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&position);
						ZEPHIR_INIT_NVAR(&part);
						zephir_update_property_zval(this_ptr, ZEND_STRL("matches"), &matches);
					}
					zephir_update_property_zval(this_ptr, ZEND_STRL("matchedRoute"), &route);
					break;
				}
			ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	if (zephir_is_true(&routeFound)) {
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("wasMatched"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("wasMatched"), &__$false);
		}
	} else {
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("wasMatched"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("wasMatched"), &__$false);
		}
	}
	if (!(zephir_is_true(&routeFound))) {
		zephir_read_property(&_71$$100, this_ptr, ZEND_STRL("notFoundPaths"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&notFoundPaths, &_71$$100);
		if (Z_TYPE_P(&notFoundPaths) != IS_NULL) {
			ZEPHIR_CALL_CE_STATIC(&parts, phalcon_mvc_router_route_ce, "getroutepaths", NULL, 0, &notFoundPaths);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&routeFound);
			ZVAL_BOOL(&routeFound, 1);
		}
	}
	zephir_read_property(&_72, this_ptr, ZEND_STRL("defaultNamespace"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("namespaceName"), &_72);
	zephir_read_property(&_73, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("module"), &_73);
	zephir_read_property(&_74, this_ptr, ZEND_STRL("defaultController"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("controller"), &_74);
	zephir_read_property(&_75, this_ptr, ZEND_STRL("defaultAction"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("action"), &_75);
	zephir_read_property(&_76, this_ptr, ZEND_STRL("defaultParams"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &_76);
	if (zephir_is_true(&routeFound)) {
		zephir_memory_observe(&vnamespace);
		if (zephir_array_isset_string_fetch(&vnamespace, &parts, SL("namespace"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("namespaceName"), &vnamespace);
			zephir_array_unset_string(&parts, SL("namespace"), PH_SEPARATE);
		}
		zephir_memory_observe(&module);
		if (zephir_array_isset_string_fetch(&module, &parts, SL("module"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("module"), &module);
			zephir_array_unset_string(&parts, SL("module"), PH_SEPARATE);
		}
		zephir_memory_observe(&controller);
		if (zephir_array_isset_string_fetch(&controller, &parts, SL("controller"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("controller"), &controller);
			zephir_array_unset_string(&parts, SL("controller"), PH_SEPARATE);
		}
		zephir_memory_observe(&action);
		if (zephir_array_isset_string_fetch(&action, &parts, SL("action"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("action"), &action);
			zephir_array_unset_string(&parts, SL("action"), PH_SEPARATE);
		}
		zephir_memory_observe(&paramsStr);
		if (zephir_array_isset_string_fetch(&paramsStr, &parts, SL("params"), 0)) {
			if (Z_TYPE_P(&paramsStr) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_77$$108);
				ZVAL_STRING(&_77$$108, "/");
				ZEPHIR_INIT_VAR(&strParams);
				zephir_fast_trim(&strParams, &paramsStr, &_77$$108, ZEPHIR_TRIM_BOTH);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&strParams, "")) {
					ZEPHIR_INIT_NVAR(&params);
					zephir_fast_explode_str(&params, SL("/"), &strParams, LONG_MAX);
				}
			}
			zephir_array_unset_string(&parts, SL("params"), PH_SEPARATE);
		}
		if (zephir_fast_count_int(&params)) {
			ZEPHIR_INIT_VAR(&_78$$110);
			zephir_fast_array_merge(&_78$$110, &params, &parts);
			zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &_78$$110);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &parts);
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_79$$112);
		ZVAL_STRING(&_79$$112, "router:afterCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_79$$112, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns whether controller name should not be mangled
 */
PHP_METHOD(Phalcon_Mvc_Router, isExactControllerName)
{

	RETURN_BOOL(1);
}

/**
 * Mounts a group of routes in the router
 *
 * @param GroupInterface group
 *
 * @return RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, mount)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group, group_sub, groupRoutes, beforeMatch, hostname, routes, route, eventsManager, _0, _6, _1$$3, *_2$$5, _3$$5, *_4$$8, _5$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&groupRoutes);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&hostname);
	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$8);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(group, phalcon_mvc_router_groupinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &group);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "router:beforeMount");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_1$$3, this_ptr, group);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&groupRoutes, group, "getroutes", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!(zephir_fast_count_int(&groupRoutes)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "The group of routes does not contain any routes", "phalcon/Mvc/Router.zep", 1051);
		return;
	}
	ZEPHIR_CALL_METHOD(&beforeMatch, group, "getbeforematch", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
		zephir_is_iterable(&groupRoutes, 0, "phalcon/Mvc/Router.zep", 1063);
		if (Z_TYPE_P(&groupRoutes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groupRoutes), _2$$5)
			{
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _2$$5);
				ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$5, &groupRoutes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&route, &groupRoutes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&route);
	}
	ZEPHIR_CALL_METHOD(&hostname, group, "gethostname", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&hostname) != IS_NULL) {
		zephir_is_iterable(&groupRoutes, 0, "phalcon/Mvc/Router.zep", 1072);
		if (Z_TYPE_P(&groupRoutes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groupRoutes), _4$$8)
			{
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _4$$8);
				ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &hostname);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$8, &groupRoutes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$8)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&route, &groupRoutes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &hostname);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&route);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&routes, &_0);
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_array_merge(&_6, &routes, &groupRoutes);
	zephir_update_property_zval(this_ptr, ZEND_STRL("routes"), &_6);
	RETURN_THIS();
}

/**
 * Set a group of paths to be returned when none of the defined routes are
 * matched
 *
 * @param array|string|null paths
 *
 * @return RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, notFound)
{
	zend_bool _0;
	zval *paths, paths_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&paths_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(paths)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &paths);
	_0 = Z_TYPE_P(paths) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(paths) != IS_STRING;
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_router_exception_ce, "The not-found paths must be an array or string", "phalcon/Mvc/Router.zep", 1094);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("notFoundPaths"), paths);
	RETURN_THISW();
}

/**
 * Set whether router must remove the extra slashes in the handled routes
 *
 * @param bool remove
 *
 * @return RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes)
{
	zval *remove_param = NULL, __$true, __$false;
	zend_bool remove;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(remove)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &remove_param);
	if (UNEXPECTED(Z_TYPE_P(remove_param) != IS_TRUE && Z_TYPE_P(remove_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'remove' must be of the type bool"));
		RETURN_NULL();
	}
	remove = (Z_TYPE_P(remove_param) == IS_TRUE);
	if (remove) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("removeExtraSlashes"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("removeExtraSlashes"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the default action name
 *
 * @param string actionName
 *
 * @return RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *actionName_param = NULL;
	zval actionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &actionName_param);
	if (UNEXPECTED(Z_TYPE_P(actionName_param) != IS_STRING && Z_TYPE_P(actionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(actionName_param) == IS_STRING)) {
		zephir_get_strval(&actionName, actionName_param);
	} else {
		ZEPHIR_INIT_VAR(&actionName);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultAction"), &actionName);
	RETURN_THIS();
}

/**
 * Sets the default controller name
 *
 * @param string controllerName
 *
 * @return RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultController)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *controllerName_param = NULL;
	zval controllerName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(controllerName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &controllerName_param);
	if (UNEXPECTED(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(&controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerName);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultController"), &controllerName);
	RETURN_THIS();
}

/**
 * Sets the name of the default module
 *
 * @param string moduleName
 *
 * @return RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *moduleName_param = NULL;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(moduleName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &moduleName_param);
	if (UNEXPECTED(Z_TYPE_P(moduleName_param) != IS_STRING && Z_TYPE_P(moduleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleName_param) == IS_STRING)) {
		zephir_get_strval(&moduleName, moduleName_param);
	} else {
		ZEPHIR_INIT_VAR(&moduleName);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultModule"), &moduleName);
	RETURN_THIS();
}

/**
 * Sets the name of the default namespace
 *
 * @parma string namespaceName
 *
 * @return RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *namespaceName_param = NULL;
	zval namespaceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(namespaceName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &namespaceName_param);
	if (UNEXPECTED(Z_TYPE_P(namespaceName_param) != IS_STRING && Z_TYPE_P(namespaceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'namespaceName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(namespaceName_param) == IS_STRING)) {
		zephir_get_strval(&namespaceName, namespaceName_param);
	} else {
		ZEPHIR_INIT_VAR(&namespaceName);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultNamespace"), &namespaceName);
	RETURN_THIS();
}

/**
 * Sets an array of default paths. If a route is missing a path the router
 * will use the defined here. This method must not be used to set a 404
 * route
 *
 *```php
 * $router->setDefaults(
 *     [
 *         "module" => "common",
 *         "action" => "index",
 *     ]
 * );
 *```
 *
 * @param array defaults
 *
 * @return RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaults)
{
	zval _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *defaults_param = NULL, namespaceName, module, controller, action, params;
	zval defaults;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(defaults)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &defaults_param);
	ZEPHIR_OBS_COPY_OR_DUP(&defaults, defaults_param);
	zephir_memory_observe(&namespaceName);
	if (zephir_array_isset_string_fetch(&namespaceName, &defaults, SL("namespace"), 0)) {
		zephir_cast_to_string(&_0$$3, &namespaceName);
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultNamespace"), &_0$$3);
	}
	zephir_memory_observe(&module);
	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultModule"), &module);
	}
	zephir_memory_observe(&controller);
	if (zephir_array_isset_string_fetch(&controller, &defaults, SL("controller"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultController"), &controller);
	}
	zephir_memory_observe(&action);
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultAction"), &action);
	}
	zephir_memory_observe(&params);
	if (zephir_array_isset_string_fetch(&params, &defaults, SL("params"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultParams"), &params);
	}
	RETURN_THIS();
}

/**
 * Sets the events manager
 *
 * @param ManagerInterface eventsManager
 *
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_Router, setEventsManager)
{
	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);
	zephir_update_property_zval(this_ptr, ZEND_STRL("eventsManager"), eventsManager);
}

/**
 * @param array $routeNames
 *
 * @return Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setKeyRouteNames)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *routeNames_param = NULL;
	zval routeNames;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeNames);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(routeNames)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &routeNames_param);
	zephir_get_arrval(&routeNames, routeNames_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("keyRouteNames"), &routeNames);
	RETURN_THIS();
}

/**
 * @param array $routeIds
 *
 * @return Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setKeyRouteIds)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *routeIds_param = NULL;
	zval routeIds;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeIds);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(routeIds)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &routeIds_param);
	zephir_get_arrval(&routeIds, routeIds_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("keyRouteIds"), &routeIds);
	RETURN_THIS();
}

/**
 * Checks if the router matches any of the defined routes
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Router, wasMatched)
{

	RETURN_MEMBER(getThis(), "wasMatched");
}

zend_object *zephir_init_properties_Phalcon_Mvc_Router(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("routes"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("params"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("matches"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("matches"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("keyRouteIds"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("keyRouteIds"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("keyRouteNames"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("keyRouteNames"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("defaultParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("defaultParams"), &_11$$8);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

