
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
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
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("methodRoutes"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_router_ce, SL("methodRoutesDirty"), 1, ZEND_ACC_PROTECTED);
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
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_router_ce, SL("uriSource"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_router_ce, SL("wasMatched"), 0, ZEND_ACC_PROTECTED);
	phalcon_mvc_router_ce->create_object = zephir_init_properties_Phalcon_Mvc_Router;
	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("POSITION_FIRST"), 0);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("POSITION_LAST"), 1);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("URI_SOURCE_GET_URL"), 0);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("URI_SOURCE_SERVER_REQUEST_URI"), 1);

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
	zval _1$$3, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultRoutes_param = NULL, _0$$3, _2$$3, _4$$3;
	zend_bool defaultRoutes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
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
	if (defaultRoutes) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0);
		add_assoc_long_ex(&_1$$3, SL("controller"), 1);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "#^/([\\w0-9\\_\\-]+)[/]{0,1}$#u");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 124, &_2$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0);
		add_assoc_long_ex(&_3$$3, SL("controller"), 1);
		add_assoc_long_ex(&_3$$3, SL("action"), 2);
		add_assoc_long_ex(&_3$$3, SL("params"), 3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "#^/([\\w0-9\\_\\-]+)/([\\w0-9\\.\\_]+)(/.*)*$#u");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 124, &_4$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, &_2$$3);
		zephir_check_call_status();
	}
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
 * @param string            $pattern
 * @param array|string|null $paths = [
 *                                 'module => '',
 *                                 'controller' => '',
 *                                 'action' => '',
 *                                 'namespace' => ''
 *                                 ]
 * @param array|string|null $httpMethods
 * @param int               $position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, *paths = NULL, paths_sub, *httpMethods = NULL, httpMethods_sub, *position_param = NULL, __$null, route, _0;
	zend_string *pattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
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
	if (ZEND_NUM_ARGS() > 1) {
		paths = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		httpMethods = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		position_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
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
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 124, &pattern_zv, paths, httpMethods);
	zephir_check_call_status();
	ZVAL_LONG(&_0, position);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, &route, &_0);
	zephir_check_call_status();
	RETURN_CCTOR(&route);
}

/**
 * Adds a route to the router that only match if the HTTP method is CONNECT
 *
 * @param string            $pattern
 * @param array|string|null $paths  = [
 *                                  'module => '',
 *                                  'controller' => '',
 *                                  'action' => '',
 *                                  'namespace' => ''
 *                                  ]
 * @param int               $position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addConnect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zend_string *pattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
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
	if (ZEND_NUM_ARGS() > 1) {
		paths = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string            $pattern
 * @param array|string|null $paths  = [
 *                                  'module => '',
 *                                  'controller' => '',
 *                                  'action' => '',
 *                                  'namespace' => ''
 *                                  ]
 * @param int               $position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addDelete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zend_string *pattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
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
	if (ZEND_NUM_ARGS() > 1) {
		paths = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string            $pattern
 * @param array|string|null $paths  = [
 *                                  'module => '',
 *                                  'controller' => '',
 *                                  'action' => '',
 *                                  'namespace' => ''
 *                                  ]
 * @param int               $position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zend_string *pattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
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
	if (ZEND_NUM_ARGS() > 1) {
		paths = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string            $pattern
 * @param array|string|null $paths  = [
 *                                  'module => '',
 *                                  'controller' => '',
 *                                  'action' => '',
 *                                  'namespace' => ''
 *                                  ]
 * @param int               $position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addHead)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zend_string *pattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
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
	if (ZEND_NUM_ARGS() > 1) {
		paths = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string            $pattern
 * @param array|string|null $paths  = [
 *                                  'module => '',
 *                                  'controller' => '',
 *                                  'action' => '',
 *                                  'namespace' => ''
 *                                  ]
 * @param int               $position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zend_string *pattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
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
	if (ZEND_NUM_ARGS() > 1) {
		paths = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 *
 * @param string            $pattern
 * @param array|string|null $paths  = [
 *                                  'module => '',
 *                                  'controller' => '',
 *                                  'action' => '',
 *                                  'namespace' => ''
 *                                  ]
 * @param int               $position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addPatch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zend_string *pattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
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
	if (ZEND_NUM_ARGS() > 1) {
		paths = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string            $pattern
 * @param array|string|null $paths  = [
 *                                  'module => '',
 *                                  'controller' => '',
 *                                  'action' => '',
 *                                  'namespace' => ''
 *                                  ]
 * @param int               $position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addPost)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zend_string *pattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
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
	if (ZEND_NUM_ARGS() > 1) {
		paths = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is PURGE
 * (Squid and Varnish support)
 *
 * @param string            $pattern
 * @param array|string|null $paths  = [
 *                                  'module => '',
 *                                  'controller' => '',
 *                                  'action' => '',
 *                                  'namespace' => ''
 *                                  ]
 * @param int               $position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addPurge)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zend_string *pattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
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
	if (ZEND_NUM_ARGS() > 1) {
		paths = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string            $pattern
 * @param array|string|null $paths  = [
 *                                  'module => '',
 *                                  'controller' => '',
 *                                  'action' => '',
 *                                  'namespace' => ''
 *                                  ]
 * @param int               $position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addPut)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zend_string *pattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
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
	if (ZEND_NUM_ARGS() > 1) {
		paths = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, paths, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is TRACE
 *
 * @param string            $pattern
 * @param array|string|null $paths  = [
 *                                  'module => '',
 *                                  'controller' => '',
 *                                  'action' => '',
 *                                  'namespace' => ''
 *                                  ]
 * @param int               $position
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, addTrace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, *paths = NULL, paths_sub, *position_param = NULL, __$null, _0, _1;
	zend_string *pattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
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
	if (ZEND_NUM_ARGS() > 1) {
		paths = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, paths, &_0, &_1);
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
 * @param RouteInterface $route
 * @param int            $position
 *
 * @return RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, attach)
{
	zval _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position;
	zval *route, route_sub, *position_param = NULL, __$true, __$false, _0$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Invalid route position", "phalcon/Mvc/Router.zep", 526);
		return;
	} while(0);

	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutesDirty"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutesDirty"), &__$false);
	}
	RETURN_THIS();
}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, clear)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("routes"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutes"), &_1);
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutesDirty"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutesDirty"), &__$false);
	}
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

	RETURN_MEMBER_TYPED(getThis(), "action", IS_STRING);
}

/**
 * Returns the processed controller name
 */
PHP_METHOD(Phalcon_Mvc_Router, getControllerName)
{

	RETURN_MEMBER_TYPED(getThis(), "controller", IS_STRING);
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

	RETURN_MEMBER_TYPED(getThis(), "keyRouteNames", IS_ARRAY);
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteIds)
{

	RETURN_MEMBER_TYPED(getThis(), "keyRouteIds", IS_ARRAY);
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

	RETURN_MEMBER_TYPED(getThis(), "matches", IS_ARRAY);
}

/**
 * Returns the routes indexed by HTTP method.
 * Routes with no HTTP constraint are stored under the "*" key.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getMethodRoutes)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("methodRoutesDirty"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rebuildmethodindex", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "methodRoutes", IS_ARRAY);
}

/**
 * Returns the processed module name
 */
PHP_METHOD(Phalcon_Mvc_Router, getModuleName)
{

	RETURN_MEMBER_TYPED(getThis(), "module", IS_STRING);
}

/**
 * Returns the processed namespace name
 */
PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName)
{

	RETURN_MEMBER_TYPED(getThis(), "namespaceName", IS_STRING);
}

/**
 * Returns the processed parameters
 */
PHP_METHOD(Phalcon_Mvc_Router, getParams)
{

	RETURN_MEMBER_TYPED(getThis(), "params", IS_ARRAY);
}

/**
 * Get rewrite info. This info is read from $_GET["_url"].
 * This returns '/' if the rewrite information cannot be read
 */
PHP_METHOD(Phalcon_Mvc_Router, getRewriteUri)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _GET, _SERVER, url, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_GET, SL("_GET"));

	zephir_read_property(&_0, this_ptr, ZEND_STRL("uriSource"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 0)) {
		zephir_memory_observe(&url);
		if (zephir_array_isset_string_fetch(&url, &_GET, SL("_url"), 0)) {
			if (!(ZEPHIR_IS_EMPTY(&url))) {
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "extractrealuri", NULL, 0, &url);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
	} else {
		ZEPHIR_OBS_NVAR(&url);
		if (zephir_array_isset_string_fetch(&url, &_SERVER, SL("REQUEST_URI"), 0)) {
			if (!(ZEPHIR_IS_EMPTY(&url))) {
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "extractrealuri", NULL, 0, &url);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
	}
	RETURN_MM_STRING("/");
}

PHP_METHOD(Phalcon_Mvc_Router, extractRealUri)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval uri_zv, urlParts, realUri;
	zend_string *uri = NULL;

	ZVAL_UNDEF(&uri_zv);
	ZVAL_UNDEF(&urlParts);
	ZVAL_UNDEF(&realUri);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	ZEPHIR_INIT_VAR(&urlParts);
	zephir_fast_explode_str(&urlParts, SL("?"), &uri_zv, 2 );
	zephir_array_fetch_long(&realUri, &urlParts, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 689);
	RETURN_CTOR(&realUri);
}

PHP_METHOD(Phalcon_Mvc_Router, rebuildMethodIndex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, route, methods, method, _0, _1, *_2, _3, *_4$$6, _5$$6, *_6$$12, _7$$12;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$12);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutes"), &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_1, 0, "phalcon/Mvc/Router.zep", 714);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _2);
			ZEPHIR_CALL_METHOD(&methods, &route, "gethttpmethods", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&methods) == IS_NULL) {
				zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("sa"), 3, SL("*"));
			} else if (Z_TYPE_P(&methods) == IS_STRING) {
				zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("za"), 2, &methods);
			} else {
				zephir_is_iterable(&methods, 0, "phalcon/Mvc/Router.zep", 711);
				if (Z_TYPE_P(&methods) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _4$$6)
					{
						ZEPHIR_INIT_NVAR(&method);
						ZVAL_COPY(&method, _4$$6);
						zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("za"), 2, &method);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_5$$6, &methods, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_5$$6)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&method, &methods, "current", NULL, 0);
						zephir_check_call_status();
							zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("za"), 2, &method);
						ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&method);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&methods, &route, "gethttpmethods", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&methods) == IS_NULL) {
					zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("sa"), 3, SL("*"));
				} else if (Z_TYPE_P(&methods) == IS_STRING) {
					zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("za"), 2, &methods);
				} else {
					zephir_is_iterable(&methods, 0, "phalcon/Mvc/Router.zep", 711);
					if (Z_TYPE_P(&methods) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _6$$12)
						{
							ZEPHIR_INIT_NVAR(&method);
							ZVAL_COPY(&method, _6$$12);
							zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("za"), 2, &method);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_7$$12, &methods, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_7$$12)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&method, &methods, "current", NULL, 0);
							zephir_check_call_status();
								zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("za"), 2, &method);
							ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&method);
				}
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutesDirty"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutesDirty"), &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns a route object by its id
 *
 * @param mixed id
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
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 729);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/Mvc/Router.zep", 741);
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
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, route, routeName, key, _0, _3, *_4, _5, _1$$3, _2$$3;
	zend_string *name = NULL, *_7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
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
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&key);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("keyRouteNames"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&key, &_0, &name_zv, 0)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 756);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/Mvc/Router.zep", 771);
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
				if (ZEPHIR_IS_EQUAL(&routeName, &name_zv)) {
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
					if (ZEPHIR_IS_EQUAL(&routeName, &name_zv)) {
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

	RETURN_MEMBER_TYPED(getThis(), "routes", IS_ARRAY);
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
	zend_ulong _23$$33, _53$$72;
	zval _18$$28, _30$$39, _33$$41, _38$$48, _41$$50, _48$$67, _59$$78, _62$$80, _67$$87, _70$$89;
	zend_bool _1, _28$$34, _31$$40, _36$$43, _39$$49, _57$$73, _60$$79, _65$$82, _68$$88;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL, *_15 = NULL, *_17 = NULL, *_20 = NULL, *_27 = NULL, *_42 = NULL, *_45 = NULL, *_47 = NULL, *_50 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, __$true, __$false, __$null, action, beforeMatch, candidateRoutes, container, controller, converter, converters, currentHostName, eventsManager, handledUri, hostname, matched, matches, matchPosition, methodCandidates, module, notFoundPaths, params, paramsStr, part, parts, paths, pattern, position, realUri, regexHostName, request, requestMethod, route, routeFound, strParams, vnamespace, _0, _3, _5, _6, _7, _8, *_10, _11, _72, _73, _74, _75, _76, _2$$5, _4$$8, _9$$12, _13$$17, _14$$23, _16$$27, _19$$31, *_21$$33, _22$$33, _25$$35, _26$$35, _29$$39, _32$$41, _34$$44, _35$$44, _37$$48, _40$$50, _43$$56, _44$$62, _46$$66, _49$$70, *_51$$72, _52$$72, _55$$74, _56$$74, _58$$78, _61$$80, _63$$83, _64$$83, _66$$87, _69$$89, _71$$93, _77$$101, _78$$103, _79$$105;
	zend_string *uri = NULL, *_24$$33, *_54$$72;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&candidateRoutes);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&converter);
	ZVAL_UNDEF(&converters);
	ZVAL_UNDEF(&currentHostName);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&handledUri);
	ZVAL_UNDEF(&hostname);
	ZVAL_UNDEF(&matched);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&matchPosition);
	ZVAL_UNDEF(&methodCandidates);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&notFoundPaths);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&paramsStr);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&realUri);
	ZVAL_UNDEF(&regexHostName);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&requestMethod);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routeFound);
	ZVAL_UNDEF(&strParams);
	ZVAL_UNDEF(&vnamespace);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_72);
	ZVAL_UNDEF(&_73);
	ZVAL_UNDEF(&_74);
	ZVAL_UNDEF(&_75);
	ZVAL_UNDEF(&_76);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_13$$17);
	ZVAL_UNDEF(&_14$$23);
	ZVAL_UNDEF(&_16$$27);
	ZVAL_UNDEF(&_19$$31);
	ZVAL_UNDEF(&_22$$33);
	ZVAL_UNDEF(&_25$$35);
	ZVAL_UNDEF(&_26$$35);
	ZVAL_UNDEF(&_29$$39);
	ZVAL_UNDEF(&_32$$41);
	ZVAL_UNDEF(&_34$$44);
	ZVAL_UNDEF(&_35$$44);
	ZVAL_UNDEF(&_37$$48);
	ZVAL_UNDEF(&_40$$50);
	ZVAL_UNDEF(&_43$$56);
	ZVAL_UNDEF(&_44$$62);
	ZVAL_UNDEF(&_46$$66);
	ZVAL_UNDEF(&_49$$70);
	ZVAL_UNDEF(&_52$$72);
	ZVAL_UNDEF(&_55$$74);
	ZVAL_UNDEF(&_56$$74);
	ZVAL_UNDEF(&_58$$78);
	ZVAL_UNDEF(&_61$$80);
	ZVAL_UNDEF(&_63$$83);
	ZVAL_UNDEF(&_64$$83);
	ZVAL_UNDEF(&_66$$87);
	ZVAL_UNDEF(&_69$$89);
	ZVAL_UNDEF(&_71$$93);
	ZVAL_UNDEF(&_77$$101);
	ZVAL_UNDEF(&_78$$103);
	ZVAL_UNDEF(&_79$$105);
	ZVAL_UNDEF(&_18$$28);
	ZVAL_UNDEF(&_30$$39);
	ZVAL_UNDEF(&_33$$41);
	ZVAL_UNDEF(&_38$$48);
	ZVAL_UNDEF(&_41$$50);
	ZVAL_UNDEF(&_48$$67);
	ZVAL_UNDEF(&_59$$78);
	ZVAL_UNDEF(&_62$$80);
	ZVAL_UNDEF(&_67$$87);
	ZVAL_UNDEF(&_70$$89);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	if (!(!(ZEPHIR_IS_EMPTY(&uri_zv)))) {
		ZEPHIR_CALL_METHOD(&realUri, this_ptr, "getrewriteuri", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&realUri, this_ptr, "extractrealuri", NULL, 0, &uri_zv);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("removeExtraSlashes"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		_1 = !ZEPHIR_IS_STRING_IDENTICAL(&realUri, "/");
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "/");
		ZEPHIR_INIT_VAR(&handledUri);
		zephir_fast_trim(&handledUri, &realUri, &_2$$5, ZEPHIR_TRIM_RIGHT);
	} else {
		ZEPHIR_CPY_WRT(&handledUri, &realUri);
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
	zephir_read_property(&_3, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_3);
	if (Z_TYPE_P(&eventsManager) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_4$$8);
		ZVAL_STRING(&_4$$8, "router:beforeCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_4$$8, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_3);
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service", "phalcon/Mvc/Router.zep", 847);
		return;
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "request");
	ZEPHIR_CALL_METHOD(&_5, &container, "get", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&request, &_5);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("methodRoutesDirty"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_3)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rebuildmethodindex", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&requestMethod, &request, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&methodCandidates);
	array_init(&methodCandidates);
	ZEPHIR_INIT_VAR(&candidateRoutes);
	array_init(&candidateRoutes);
	ZEPHIR_OBS_NVAR(&methodCandidates);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("methodRoutes"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&methodCandidates, &_7, &requestMethod, 0)) {
		ZEPHIR_CPY_WRT(&candidateRoutes, &methodCandidates);
	}
	ZEPHIR_OBS_NVAR(&methodCandidates);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("methodRoutes"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&methodCandidates, &_8, SL("*"), 0)) {
		ZEPHIR_INIT_VAR(&_9$$12);
		zephir_fast_array_merge(&_9$$12, &candidateRoutes, &methodCandidates);
		ZEPHIR_CPY_WRT(&candidateRoutes, &_9$$12);
	}
	zephir_is_iterable(&candidateRoutes, 0, "phalcon/Mvc/Router.zep", 1057);
	if (Z_TYPE_P(&candidateRoutes) == IS_ARRAY) {
		ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(&candidateRoutes), _10)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _10);
			ZEPHIR_INIT_NVAR(&params);
			array_init(&params);
			ZEPHIR_INIT_NVAR(&matches);
			ZVAL_NULL(&matches);
			ZEPHIR_CALL_METHOD(&hostname, &route, "gethostname", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&hostname) != IS_NULL) {
				if (Z_TYPE_P(&currentHostName) == IS_NULL) {
					ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", &_12, 0);
					zephir_check_call_status();
				}
				if (!(zephir_is_true(&currentHostName))) {
					continue;
				}
				if (zephir_memnstr_str(&hostname, SL("("), "phalcon/Mvc/Router.zep", 903)) {
					if (!(zephir_memnstr_str(&hostname, SL("#"), "phalcon/Mvc/Router.zep", 904))) {
						ZEPHIR_INIT_NVAR(&regexHostName);
						ZEPHIR_CONCAT_SV(&regexHostName, "#^", &hostname);
						if (!(zephir_memnstr_str(&hostname, SL(":"), "phalcon/Mvc/Router.zep", 907))) {
							zephir_concat_self_str(&regexHostName, SL("(:[[:digit:]]+)?"));
						}
						zephir_concat_self_str(&regexHostName, SL("$#i"));
					} else {
						ZEPHIR_CPY_WRT(&regexHostName, &hostname);
					}
					ZEPHIR_INIT_NVAR(&_13$$17);
					ZEPHIR_INIT_NVAR(&matched);
					zephir_preg_match(&matched, &regexHostName, &currentHostName, &_13$$17, 0, 0 , 0 );
				} else {
					ZEPHIR_INIT_NVAR(&matched);
					ZVAL_BOOL(&matched, ZEPHIR_IS_EQUAL(&currentHostName, &hostname));
				}
				if (!(zephir_is_true(&matched))) {
					continue;
				}
			}
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_14$$23);
				ZVAL_STRING(&_14$$23, "router:beforeCheckRoute");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_15, 0, &_14$$23, this_ptr, &route);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&pattern, &route, "getcompiledpattern", NULL, 0);
			zephir_check_call_status();
			if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/Mvc/Router.zep", 935)) {
				ZEPHIR_INIT_NVAR(&routeFound);
				zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
			} else {
				ZEPHIR_INIT_NVAR(&routeFound);
				ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, &handledUri));
			}
			if (zephir_is_true(&routeFound)) {
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_16$$27);
					ZVAL_STRING(&_16$$27, "router:matchedRoute");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_17, 0, &_16$$27, this_ptr, &route);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getbeforematch", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
					if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/Mvc/Router.zep", 957);
						return;
					}
					ZEPHIR_INIT_NVAR(&_18$$28);
					zephir_create_array(&_18$$28, 3, 0);
					zephir_array_fast_append(&_18$$28, &handledUri);
					zephir_array_fast_append(&_18$$28, &route);
					zephir_array_fast_append(&_18$$28, this_ptr);
					ZEPHIR_INIT_NVAR(&routeFound);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_18$$28);
					zephir_check_call_status();
				}
			} else {
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_19$$31);
					ZVAL_STRING(&_19$$31, "router:notMatchedRoute");
					ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_20, 0, &_19$$31, this_ptr, &route);
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
					zephir_is_iterable(&paths, 0, "phalcon/Mvc/Router.zep", 1045);
					if (Z_TYPE_P(&paths) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _23$$33, _24$$33, _21$$33)
						{
							ZEPHIR_INIT_NVAR(&part);
							if (_24$$33 != NULL) { 
								ZVAL_STR_COPY(&part, _24$$33);
							} else {
								ZVAL_LONG(&part, _23$$33);
							}
							ZEPHIR_INIT_NVAR(&position);
							ZVAL_COPY(&position, _21$$33);
							if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
								ZEPHIR_INIT_NVAR(&_25$$35);
								object_init_ex(&_25$$35, phalcon_mvc_router_exception_ce);
								ZEPHIR_INIT_NVAR(&_26$$35);
								ZEPHIR_CONCAT_SV(&_26$$35, "Wrong key in paths: ", &part);
								ZEPHIR_CALL_METHOD(NULL, &_25$$35, "__construct", &_27, 49, &_26$$35);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_25$$35, "phalcon/Mvc/Router.zep", 997);
								ZEPHIR_MM_RESTORE();
								return;
							}
							_28$$34 = Z_TYPE_P(&position) != IS_STRING;
							if (_28$$34) {
								_28$$34 = Z_TYPE_P(&position) != IS_LONG;
							}
							if (_28$$34) {
								continue;
							}
							ZEPHIR_OBS_NVAR(&matchPosition);
							if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
								if (Z_TYPE_P(&converters) == IS_ARRAY) {
									ZEPHIR_OBS_NVAR(&converter);
									if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
										ZEPHIR_INIT_NVAR(&_29$$39);
										ZEPHIR_INIT_NVAR(&_30$$39);
										zephir_create_array(&_30$$39, 1, 0);
										zephir_array_fast_append(&_30$$39, &matchPosition);
										ZEPHIR_CALL_USER_FUNC_ARRAY(&_29$$39, &converter, &_30$$39);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_29$$39, PH_COPY | PH_SEPARATE);
										continue;
									}
								}
								zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
							} else {
								_31$$40 = Z_TYPE_P(&converters) == IS_ARRAY;
								if (_31$$40) {
									ZEPHIR_OBS_NVAR(&converter);
									_31$$40 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
								}
								if (_31$$40) {
									ZEPHIR_INIT_NVAR(&_32$$41);
									ZEPHIR_INIT_NVAR(&_33$$41);
									zephir_create_array(&_33$$41, 1, 0);
									zephir_array_fast_append(&_33$$41, &position);
									ZEPHIR_CALL_USER_FUNC_ARRAY(&_32$$41, &converter, &_33$$41);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &part, &_32$$41, PH_COPY | PH_SEPARATE);
								} else if (Z_TYPE_P(&position) == IS_LONG) {
									zephir_array_unset(&parts, &part, PH_SEPARATE);
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_22$$33, &paths, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_22$$33)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&part, &paths, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&position, &paths, "current", NULL, 0);
							zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
									ZEPHIR_INIT_NVAR(&_34$$44);
									object_init_ex(&_34$$44, phalcon_mvc_router_exception_ce);
									ZEPHIR_INIT_NVAR(&_35$$44);
									ZEPHIR_CONCAT_SV(&_35$$44, "Wrong key in paths: ", &part);
									ZEPHIR_CALL_METHOD(NULL, &_34$$44, "__construct", &_27, 49, &_35$$44);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_34$$44, "phalcon/Mvc/Router.zep", 997);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_36$$43 = Z_TYPE_P(&position) != IS_STRING;
								if (_36$$43) {
									_36$$43 = Z_TYPE_P(&position) != IS_LONG;
								}
								if (_36$$43) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&matchPosition);
								if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_37$$48);
											ZEPHIR_INIT_NVAR(&_38$$48);
											zephir_create_array(&_38$$48, 1, 0);
											zephir_array_fast_append(&_38$$48, &matchPosition);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_37$$48, &converter, &_38$$48);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_37$$48, PH_COPY | PH_SEPARATE);
											continue;
										}
									}
									zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
								} else {
									_39$$49 = Z_TYPE_P(&converters) == IS_ARRAY;
									if (_39$$49) {
										ZEPHIR_OBS_NVAR(&converter);
										_39$$49 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
									}
									if (_39$$49) {
										ZEPHIR_INIT_NVAR(&_40$$50);
										ZEPHIR_INIT_NVAR(&_41$$50);
										zephir_create_array(&_41$$50, 1, 0);
										zephir_array_fast_append(&_41$$50, &position);
										ZEPHIR_CALL_USER_FUNC_ARRAY(&_40$$50, &converter, &_41$$50);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_40$$50, PH_COPY | PH_SEPARATE);
									} else if (Z_TYPE_P(&position) == IS_LONG) {
										zephir_array_unset(&parts, &part, PH_SEPARATE);
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
		ZEPHIR_CALL_METHOD(NULL, &candidateRoutes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_11, &candidateRoutes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &candidateRoutes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&params);
				array_init(&params);
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				ZEPHIR_CALL_METHOD(&hostname, &route, "gethostname", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&hostname) != IS_NULL) {
					if (Z_TYPE_P(&currentHostName) == IS_NULL) {
						ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", &_42, 0);
						zephir_check_call_status();
					}
					if (!(zephir_is_true(&currentHostName))) {
						continue;
					}
					if (zephir_memnstr_str(&hostname, SL("("), "phalcon/Mvc/Router.zep", 903)) {
						if (!(zephir_memnstr_str(&hostname, SL("#"), "phalcon/Mvc/Router.zep", 904))) {
							ZEPHIR_INIT_NVAR(&regexHostName);
							ZEPHIR_CONCAT_SV(&regexHostName, "#^", &hostname);
							if (!(zephir_memnstr_str(&hostname, SL(":"), "phalcon/Mvc/Router.zep", 907))) {
								zephir_concat_self_str(&regexHostName, SL("(:[[:digit:]]+)?"));
							}
							zephir_concat_self_str(&regexHostName, SL("$#i"));
						} else {
							ZEPHIR_CPY_WRT(&regexHostName, &hostname);
						}
						ZEPHIR_INIT_NVAR(&_43$$56);
						ZEPHIR_INIT_NVAR(&matched);
						zephir_preg_match(&matched, &regexHostName, &currentHostName, &_43$$56, 0, 0 , 0 );
					} else {
						ZEPHIR_INIT_NVAR(&matched);
						ZVAL_BOOL(&matched, ZEPHIR_IS_EQUAL(&currentHostName, &hostname));
					}
					if (!(zephir_is_true(&matched))) {
						continue;
					}
				}
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_44$$62);
					ZVAL_STRING(&_44$$62, "router:beforeCheckRoute");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_45, 0, &_44$$62, this_ptr, &route);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&pattern, &route, "getcompiledpattern", NULL, 0);
				zephir_check_call_status();
				if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/Mvc/Router.zep", 935)) {
					ZEPHIR_INIT_NVAR(&routeFound);
					zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
				} else {
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, &handledUri));
				}
				if (zephir_is_true(&routeFound)) {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_46$$66);
						ZVAL_STRING(&_46$$66, "router:matchedRoute");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_47, 0, &_46$$66, this_ptr, &route);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getbeforematch", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/Mvc/Router.zep", 957);
							return;
						}
						ZEPHIR_INIT_NVAR(&_48$$67);
						zephir_create_array(&_48$$67, 3, 0);
						zephir_array_fast_append(&_48$$67, &handledUri);
						zephir_array_fast_append(&_48$$67, &route);
						zephir_array_fast_append(&_48$$67, this_ptr);
						ZEPHIR_INIT_NVAR(&routeFound);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_48$$67);
						zephir_check_call_status();
					}
				} else {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_49$$70);
						ZVAL_STRING(&_49$$70, "router:notMatchedRoute");
						ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_50, 0, &_49$$70, this_ptr, &route);
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
						zephir_is_iterable(&paths, 0, "phalcon/Mvc/Router.zep", 1045);
						if (Z_TYPE_P(&paths) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _53$$72, _54$$72, _51$$72)
							{
								ZEPHIR_INIT_NVAR(&part);
								if (_54$$72 != NULL) { 
									ZVAL_STR_COPY(&part, _54$$72);
								} else {
									ZVAL_LONG(&part, _53$$72);
								}
								ZEPHIR_INIT_NVAR(&position);
								ZVAL_COPY(&position, _51$$72);
								if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
									ZEPHIR_INIT_NVAR(&_55$$74);
									object_init_ex(&_55$$74, phalcon_mvc_router_exception_ce);
									ZEPHIR_INIT_NVAR(&_56$$74);
									ZEPHIR_CONCAT_SV(&_56$$74, "Wrong key in paths: ", &part);
									ZEPHIR_CALL_METHOD(NULL, &_55$$74, "__construct", &_27, 49, &_56$$74);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_55$$74, "phalcon/Mvc/Router.zep", 997);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_57$$73 = Z_TYPE_P(&position) != IS_STRING;
								if (_57$$73) {
									_57$$73 = Z_TYPE_P(&position) != IS_LONG;
								}
								if (_57$$73) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&matchPosition);
								if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_58$$78);
											ZEPHIR_INIT_NVAR(&_59$$78);
											zephir_create_array(&_59$$78, 1, 0);
											zephir_array_fast_append(&_59$$78, &matchPosition);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_58$$78, &converter, &_59$$78);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_58$$78, PH_COPY | PH_SEPARATE);
											continue;
										}
									}
									zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
								} else {
									_60$$79 = Z_TYPE_P(&converters) == IS_ARRAY;
									if (_60$$79) {
										ZEPHIR_OBS_NVAR(&converter);
										_60$$79 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
									}
									if (_60$$79) {
										ZEPHIR_INIT_NVAR(&_61$$80);
										ZEPHIR_INIT_NVAR(&_62$$80);
										zephir_create_array(&_62$$80, 1, 0);
										zephir_array_fast_append(&_62$$80, &position);
										ZEPHIR_CALL_USER_FUNC_ARRAY(&_61$$80, &converter, &_62$$80);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_61$$80, PH_COPY | PH_SEPARATE);
									} else if (Z_TYPE_P(&position) == IS_LONG) {
										zephir_array_unset(&parts, &part, PH_SEPARATE);
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_52$$72, &paths, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_52$$72)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&part, &paths, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&position, &paths, "current", NULL, 0);
								zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
										ZEPHIR_INIT_NVAR(&_63$$83);
										object_init_ex(&_63$$83, phalcon_mvc_router_exception_ce);
										ZEPHIR_INIT_NVAR(&_64$$83);
										ZEPHIR_CONCAT_SV(&_64$$83, "Wrong key in paths: ", &part);
										ZEPHIR_CALL_METHOD(NULL, &_63$$83, "__construct", &_27, 49, &_64$$83);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_63$$83, "phalcon/Mvc/Router.zep", 997);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_65$$82 = Z_TYPE_P(&position) != IS_STRING;
									if (_65$$82) {
										_65$$82 = Z_TYPE_P(&position) != IS_LONG;
									}
									if (_65$$82) {
										continue;
									}
									ZEPHIR_OBS_NVAR(&matchPosition);
									if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_INIT_NVAR(&_66$$87);
												ZEPHIR_INIT_NVAR(&_67$$87);
												zephir_create_array(&_67$$87, 1, 0);
												zephir_array_fast_append(&_67$$87, &matchPosition);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_66$$87, &converter, &_67$$87);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_66$$87, PH_COPY | PH_SEPARATE);
												continue;
											}
										}
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
									} else {
										_68$$88 = Z_TYPE_P(&converters) == IS_ARRAY;
										if (_68$$88) {
											ZEPHIR_OBS_NVAR(&converter);
											_68$$88 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										}
										if (_68$$88) {
											ZEPHIR_INIT_NVAR(&_69$$89);
											ZEPHIR_INIT_NVAR(&_70$$89);
											zephir_create_array(&_70$$89, 1, 0);
											zephir_array_fast_append(&_70$$89, &position);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_69$$89, &converter, &_70$$89);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_69$$89, PH_COPY | PH_SEPARATE);
										} else if (Z_TYPE_P(&position) == IS_LONG) {
											zephir_array_unset(&parts, &part, PH_SEPARATE);
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
			ZEPHIR_CALL_METHOD(NULL, &candidateRoutes, "next", NULL, 0);
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
		zephir_read_property(&_71$$93, this_ptr, ZEND_STRL("notFoundPaths"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&notFoundPaths, &_71$$93);
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
				ZEPHIR_INIT_VAR(&_77$$101);
				ZVAL_STRING(&_77$$101, "/");
				ZEPHIR_INIT_VAR(&strParams);
				zephir_fast_trim(&strParams, &paramsStr, &_77$$101, ZEPHIR_TRIM_BOTH);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&strParams, "")) {
					ZEPHIR_INIT_NVAR(&params);
					zephir_fast_explode_str(&params, SL("/"), &strParams, LONG_MAX);
				}
			}
			zephir_array_unset_string(&parts, SL("params"), PH_SEPARATE);
		}
		if (zephir_fast_count_int(&params)) {
			ZEPHIR_INIT_VAR(&_78$$103);
			zephir_fast_array_merge(&_78$$103, &params, &parts);
			zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &_78$$103);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &parts);
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_79$$105);
		ZVAL_STRING(&_79$$105, "router:afterCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_79$$105, this_ptr);
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
 * Loads routes from an array or Phalcon\Config\Config instance.
 *
 *```php
 * $router->loadFromConfig(
 *      [
 *          'routes' => [
 *              [
 *                  'method'  => 'get',
 *                  'pattern' => '/users',
 *                  'paths'   => 'Users::index',
 *              ],
 *          ],
 *      ]
 *  );
 *```
 *
 * @param array|ConfigInterface config
 *
 * @return RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, loadFromConfig)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, routes, routeData, defaults, notFoundPaths, removeExtra, groups, groupData, _0$$3, _1$$6, *_2$$9, _3$$9, *_5$$13, _6$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&routeData);
	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&notFoundPaths);
	ZVAL_UNDEF(&removeExtra);
	ZVAL_UNDEF(&groups);
	ZVAL_UNDEF(&groupData);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_6$$13);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_SEPARATE_PARAM(config);
	if (Z_TYPE_P(config) == IS_OBJECT) {
		if (!(zephir_instance_of_ev(config, phalcon_config_configinterface_ce))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "loadFromConfig requires an array or Phalcon\\Config\\ConfigInterface instance", "phalcon/Mvc/Router.zep", 1185);
			return;
		}
		ZEPHIR_CALL_METHOD(&_0$$3, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_0$$3);
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "loadFromConfig requires an array or Phalcon\\Config\\ConfigInterface instance", "phalcon/Mvc/Router.zep", 1193);
		return;
	}
	if (zephir_array_isset_string(config, SL("removeExtraSlashes"))) {
		zephir_memory_observe(&removeExtra);
		zephir_array_fetch_string(&removeExtra, config, SL("removeExtraSlashes"), PH_NOISY, "phalcon/Mvc/Router.zep", 1197);
		ZVAL_BOOL(&_1$$6, zephir_get_boolval(&removeExtra));
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "removeextraslashes", NULL, 0, &_1$$6);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(config, SL("defaults"))) {
		zephir_memory_observe(&defaults);
		zephir_array_fetch_string(&defaults, config, SL("defaults"), PH_NOISY, "phalcon/Mvc/Router.zep", 1202);
		if (Z_TYPE_P(&defaults) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "'defaults' must be an array", "phalcon/Mvc/Router.zep", 1204);
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaults", NULL, 0, &defaults);
		zephir_check_call_status();
	}
	zephir_memory_observe(&routes);
	if (zephir_array_isset_string_fetch(&routes, config, SL("routes"), 0)) {
		if (Z_TYPE_P(&routes) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "'routes' must be an array", "phalcon/Mvc/Router.zep", 1211);
			return;
		}
		zephir_is_iterable(&routes, 0, "phalcon/Mvc/Router.zep", 1216);
		if (Z_TYPE_P(&routes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&routes), _2$$9)
			{
				ZEPHIR_INIT_NVAR(&routeData);
				ZVAL_COPY(&routeData, _2$$9);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addroutefromconfig", &_4, 0, &routeData);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &routes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$9, &routes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&routeData, &routes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "addroutefromconfig", &_4, 0, &routeData);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &routes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&routeData);
	}
	zephir_memory_observe(&groups);
	if (zephir_array_isset_string_fetch(&groups, config, SL("groups"), 0)) {
		if (Z_TYPE_P(&groups) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "'groups' must be an array", "phalcon/Mvc/Router.zep", 1220);
			return;
		}
		zephir_is_iterable(&groups, 0, "phalcon/Mvc/Router.zep", 1225);
		if (Z_TYPE_P(&groups) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groups), _5$$13)
			{
				ZEPHIR_INIT_NVAR(&groupData);
				ZVAL_COPY(&groupData, _5$$13);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "mountgroupfromconfig", &_7, 0, &groupData);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &groups, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$13, &groups, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$13)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&groupData, &groups, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "mountgroupfromconfig", &_7, 0, &groupData);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &groups, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&groupData);
	}
	zephir_memory_observe(&notFoundPaths);
	if (zephir_array_isset_string_fetch(&notFoundPaths, config, SL("notFound"), 0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "notfound", NULL, 0, &notFoundPaths);
		zephir_check_call_status();
	}
	RETURN_THIS();
}

/**
 * Adds a single route from a config array entry. Used by loadFromConfig.
 *
 * @param array routeData
 *
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_Router, addRouteFromConfig)
{
	zval _3$$5, _8$$8, _10$$9;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routeData_param = NULL, method, methodClass, pattern, paths, route, _1, _2$$5, _4$$6, _5$$7, _6$$7, _7$$8, _9$$9;
	zval routeData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeData);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&methodClass);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$9);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(routeData, routeData_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &routeData_param);
	zephir_get_arrval(&routeData, routeData_param);
	zephir_memory_observe(&pattern);
	if (!(zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Route config entry is missing 'pattern'", "phalcon/Mvc/Router.zep", 1246);
		return;
	}
	zephir_memory_observe(&paths);
	if (!(zephir_array_isset_string_fetch(&paths, &routeData, SL("paths"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Route config entry is missing 'paths'", "phalcon/Mvc/Router.zep", 1250);
		return;
	}
	ZEPHIR_INIT_VAR(&method);
	ZVAL_STRING(&method, "");
	_0 = zephir_array_isset_string(&routeData, SL("method"));
	if (_0) {
		zephir_array_fetch_string(&_1, &routeData, SL("method"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1254);
		_0 = Z_TYPE_P(&_1) != IS_NULL;
	}
	if (_0) {
		zephir_memory_observe(&_2$$5);
		zephir_array_fetch_string(&_2$$5, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 1255);
		zephir_cast_to_string(&_3$$5, &_2$$5);
		ZEPHIR_INIT_NVAR(&method);
		zephir_fast_strtolower(&method, &_3$$5);
	}
	do {
		if (ZEPHIR_IS_STRING(&method, "") || ZEPHIR_IS_STRING(&method, "connect") || ZEPHIR_IS_STRING(&method, "delete") || ZEPHIR_IS_STRING(&method, "get") || ZEPHIR_IS_STRING(&method, "head") || ZEPHIR_IS_STRING(&method, "options") || ZEPHIR_IS_STRING(&method, "patch") || ZEPHIR_IS_STRING(&method, "post") || ZEPHIR_IS_STRING(&method, "purge") || ZEPHIR_IS_STRING(&method, "put") || ZEPHIR_IS_STRING(&method, "trace")) {
			ZEPHIR_INIT_VAR(&_4$$6);
			zephir_ucfirst(&_4$$6, &method);
			ZEPHIR_INIT_VAR(&methodClass);
			ZEPHIR_CONCAT_SV(&methodClass, "add", &_4$$6);
			ZEPHIR_CALL_METHOD_ZVAL(&route, this_ptr, &methodClass, NULL, 0, &pattern, &paths);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_VAR(&_5$$7);
		object_init_ex(&_5$$7, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_6$$7);
		ZEPHIR_CONCAT_SVS(&_6$$7, "Unknown HTTP method '", &method, "' in route config");
		ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", NULL, 49, &_6$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$7, "phalcon/Mvc/Router.zep", 1276);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	if (zephir_array_isset_string(&routeData, SL("name"))) {
		zephir_memory_observe(&_7$$8);
		zephir_array_fetch_string(&_7$$8, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 1280);
		zephir_cast_to_string(&_8$$8, &_7$$8);
		ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &_8$$8);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&routeData, SL("hostname"))) {
		zephir_memory_observe(&_9$$9);
		zephir_array_fetch_string(&_9$$9, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1283);
		zephir_cast_to_string(&_10$$9, &_9$$9);
		ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &_10$$9);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Builds a Group from a config entry and mounts it. Used by loadFromConfig.
 *
 * @param array groupData
 *
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_Router, mountGroupFromConfig)
{
	zend_bool _6$$8, _16$$15;
	zval _1$$4, _3$$5, _9$$11, _15$$14, _19$$18, _24$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *groupData_param = NULL, group, paths, routes, routeData, method, methodClass, pattern, routePaths, route, *_4, _5, _0$$4, _2$$5, _7$$8, _8$$11, _10$$12, _11$$13, _12$$13, _14$$14, _17$$15, _18$$18, _20$$19, _21$$20, _22$$20, _23$$21;
	zval groupData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&groupData);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&routeData);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&methodClass);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&routePaths);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$20);
	ZVAL_UNDEF(&_22$$20);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_24$$21);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(groupData, groupData_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &groupData_param);
	zephir_get_arrval(&groupData, groupData_param);
	ZEPHIR_INIT_VAR(&paths);
	ZVAL_NULL(&paths);
	if (zephir_array_isset_string(&groupData, SL("paths"))) {
		ZEPHIR_OBS_NVAR(&paths);
		zephir_array_fetch_string(&paths, &groupData, SL("paths"), PH_NOISY, "phalcon/Mvc/Router.zep", 1300);
	}
	ZEPHIR_INIT_VAR(&group);
	object_init_ex(&group, phalcon_mvc_router_group_ce);
	ZEPHIR_CALL_METHOD(NULL, &group, "__construct", NULL, 125, &paths);
	zephir_check_call_status();
	if (zephir_array_isset_string(&groupData, SL("prefix"))) {
		zephir_memory_observe(&_0$$4);
		zephir_array_fetch_string(&_0$$4, &groupData, SL("prefix"), PH_NOISY, "phalcon/Mvc/Router.zep", 1306);
		zephir_cast_to_string(&_1$$4, &_0$$4);
		ZEPHIR_CALL_METHOD(NULL, &group, "setprefix", NULL, 126, &_1$$4);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&groupData, SL("hostname"))) {
		zephir_memory_observe(&_2$$5);
		zephir_array_fetch_string(&_2$$5, &groupData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1310);
		zephir_cast_to_string(&_3$$5, &_2$$5);
		ZEPHIR_CALL_METHOD(NULL, &group, "sethostname", NULL, 127, &_3$$5);
		zephir_check_call_status();
	}
	zephir_memory_observe(&routes);
	if (!(zephir_array_isset_string_fetch(&routes, &groupData, SL("routes"), 0))) {
		ZEPHIR_INIT_NVAR(&routes);
		array_init(&routes);
	}
	if (Z_TYPE_P(&routes) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Group 'routes' must be an array", "phalcon/Mvc/Router.zep", 1318);
		return;
	}
	zephir_is_iterable(&routes, 0, "phalcon/Mvc/Router.zep", 1360);
	if (Z_TYPE_P(&routes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&routes), _4)
		{
			ZEPHIR_INIT_NVAR(&routeData);
			ZVAL_COPY(&routeData, _4);
			ZEPHIR_OBS_NVAR(&pattern);
			if (!(zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Group route entry is missing 'pattern'", "phalcon/Mvc/Router.zep", 1323);
				return;
			}
			ZEPHIR_OBS_NVAR(&routePaths);
			if (!(zephir_array_isset_string_fetch(&routePaths, &routeData, SL("paths"), 0))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Group route entry is missing 'paths'", "phalcon/Mvc/Router.zep", 1326);
				return;
			}
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_STRING(&method, "");
			_6$$8 = zephir_array_isset_string(&routeData, SL("method"));
			if (_6$$8) {
				zephir_array_fetch_string(&_7$$8, &routeData, SL("method"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1330);
				_6$$8 = Z_TYPE_P(&_7$$8) != IS_NULL;
			}
			if (_6$$8) {
				ZEPHIR_OBS_NVAR(&_8$$11);
				zephir_array_fetch_string(&_8$$11, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 1331);
				zephir_cast_to_string(&_9$$11, &_8$$11);
				ZEPHIR_INIT_NVAR(&method);
				zephir_fast_strtolower(&method, &_9$$11);
			}
			do {
				if (ZEPHIR_IS_STRING(&method, "") || ZEPHIR_IS_STRING(&method, "connect") || ZEPHIR_IS_STRING(&method, "delete") || ZEPHIR_IS_STRING(&method, "get") || ZEPHIR_IS_STRING(&method, "head") || ZEPHIR_IS_STRING(&method, "options") || ZEPHIR_IS_STRING(&method, "patch") || ZEPHIR_IS_STRING(&method, "post") || ZEPHIR_IS_STRING(&method, "purge") || ZEPHIR_IS_STRING(&method, "put") || ZEPHIR_IS_STRING(&method, "trace")) {
					ZEPHIR_INIT_NVAR(&_10$$12);
					zephir_ucfirst(&_10$$12, &method);
					ZEPHIR_INIT_NVAR(&methodClass);
					ZEPHIR_CONCAT_SV(&methodClass, "add", &_10$$12);
					ZEPHIR_CALL_METHOD_ZVAL(&route, &group, &methodClass, NULL, 0, &pattern, &routePaths);
					zephir_check_call_status();
					break;
				}
				ZEPHIR_INIT_NVAR(&_11$$13);
				object_init_ex(&_11$$13, phalcon_mvc_router_exception_ce);
				ZEPHIR_INIT_NVAR(&_12$$13);
				ZEPHIR_CONCAT_SVS(&_12$$13, "Unknown HTTP method '", &method, "' in group route config");
				ZEPHIR_CALL_METHOD(NULL, &_11$$13, "__construct", &_13, 49, &_12$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$13, "phalcon/Mvc/Router.zep", 1352);
				ZEPHIR_MM_RESTORE();
				return;
			} while(0);

			if (zephir_array_isset_string(&routeData, SL("name"))) {
				ZEPHIR_OBS_NVAR(&_14$$14);
				zephir_array_fetch_string(&_14$$14, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 1356);
				zephir_cast_to_string(&_15$$14, &_14$$14);
				ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &_15$$14);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &routes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &routes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&routeData, &routes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&pattern);
				if (!(zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Group route entry is missing 'pattern'", "phalcon/Mvc/Router.zep", 1323);
					return;
				}
				ZEPHIR_OBS_NVAR(&routePaths);
				if (!(zephir_array_isset_string_fetch(&routePaths, &routeData, SL("paths"), 0))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Group route entry is missing 'paths'", "phalcon/Mvc/Router.zep", 1326);
					return;
				}
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_STRING(&method, "");
				_16$$15 = zephir_array_isset_string(&routeData, SL("method"));
				if (_16$$15) {
					zephir_array_fetch_string(&_17$$15, &routeData, SL("method"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1330);
					_16$$15 = Z_TYPE_P(&_17$$15) != IS_NULL;
				}
				if (_16$$15) {
					ZEPHIR_OBS_NVAR(&_18$$18);
					zephir_array_fetch_string(&_18$$18, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 1331);
					zephir_cast_to_string(&_19$$18, &_18$$18);
					ZEPHIR_INIT_NVAR(&method);
					zephir_fast_strtolower(&method, &_19$$18);
				}
				do {
					if (ZEPHIR_IS_STRING(&method, "") || ZEPHIR_IS_STRING(&method, "connect") || ZEPHIR_IS_STRING(&method, "delete") || ZEPHIR_IS_STRING(&method, "get") || ZEPHIR_IS_STRING(&method, "head") || ZEPHIR_IS_STRING(&method, "options") || ZEPHIR_IS_STRING(&method, "patch") || ZEPHIR_IS_STRING(&method, "post") || ZEPHIR_IS_STRING(&method, "purge") || ZEPHIR_IS_STRING(&method, "put") || ZEPHIR_IS_STRING(&method, "trace")) {
						ZEPHIR_INIT_NVAR(&_20$$19);
						zephir_ucfirst(&_20$$19, &method);
						ZEPHIR_INIT_NVAR(&methodClass);
						ZEPHIR_CONCAT_SV(&methodClass, "add", &_20$$19);
						ZEPHIR_CALL_METHOD_ZVAL(&route, &group, &methodClass, NULL, 0, &pattern, &routePaths);
						zephir_check_call_status();
						break;
					}
					ZEPHIR_INIT_NVAR(&_21$$20);
					object_init_ex(&_21$$20, phalcon_mvc_router_exception_ce);
					ZEPHIR_INIT_NVAR(&_22$$20);
					ZEPHIR_CONCAT_SVS(&_22$$20, "Unknown HTTP method '", &method, "' in group route config");
					ZEPHIR_CALL_METHOD(NULL, &_21$$20, "__construct", &_13, 49, &_22$$20);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_21$$20, "phalcon/Mvc/Router.zep", 1352);
					ZEPHIR_MM_RESTORE();
					return;
				} while(0);

				if (zephir_array_isset_string(&routeData, SL("name"))) {
					ZEPHIR_OBS_NVAR(&_23$$21);
					zephir_array_fetch_string(&_23$$21, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 1356);
					zephir_cast_to_string(&_24$$21, &_23$$21);
					ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &_24$$21);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &routes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&routeData);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mount", NULL, 0, &group);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
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
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group, group_sub, groupRoutes, beforeMatch, hostname, route, eventsManager, _0, *_6, _7, _1$$3, *_2$$5, _3$$5, *_4$$8, _5$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&groupRoutes);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&hostname);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "The group of routes does not contain any routes", "phalcon/Mvc/Router.zep", 1385);
		return;
	}
	ZEPHIR_CALL_METHOD(&beforeMatch, group, "getbeforematch", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
		zephir_is_iterable(&groupRoutes, 0, "phalcon/Mvc/Router.zep", 1397);
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
		zephir_is_iterable(&groupRoutes, 0, "phalcon/Mvc/Router.zep", 1406);
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
	zephir_is_iterable(&groupRoutes, 0, "phalcon/Mvc/Router.zep", 1412);
	if (Z_TYPE_P(&groupRoutes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groupRoutes), _6)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _6);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", &_8, 0, &route);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &groupRoutes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &groupRoutes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", &_8, 0, &route);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_router_exception_ce, "The not-found paths must be an array or string", "phalcon/Mvc/Router.zep", 1428);
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
	zval actionName_zv;
	zend_string *actionName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&actionName_zv, actionName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultAction"), &actionName_zv);
	RETURN_THISW();
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
	zval controllerName_zv;
	zend_string *controllerName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(controllerName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&controllerName_zv, controllerName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultController"), &controllerName_zv);
	RETURN_THISW();
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
	zval moduleName_zv;
	zend_string *moduleName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(moduleName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&moduleName_zv, moduleName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultModule"), &moduleName_zv);
	RETURN_THISW();
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
	zval namespaceName_zv;
	zend_string *namespaceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(namespaceName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&namespaceName_zv, namespaceName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultNamespace"), &namespaceName_zv);
	RETURN_THISW();
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
		ZEPHIR_Z_PARAM_ARRAY(defaults, defaults_param)
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
		ZEPHIR_Z_PARAM_ARRAY(routeNames, routeNames_param)
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
		ZEPHIR_Z_PARAM_ARRAY(routeIds, routeIds_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &routeIds_param);
	zephir_get_arrval(&routeIds, routeIds_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("keyRouteIds"), &routeIds);
	RETURN_THIS();
}

/**
 * Sets the URI source. One of the URI_SOURCE_* constants
 *
 * ```php
 * $router->setUriSource(
 *     Router::URI_SOURCE_SERVER_REQUEST_URI
 * );
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Router, setUriSource)
{
	zval *uriSource_param = NULL, _0;
	zend_long uriSource;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(uriSource)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &uriSource_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, uriSource);
	zephir_update_property_zval(this_ptr, ZEND_STRL("uriSource"), &_0);
	RETURN_THISW();
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
		zval _0, _2, _4, _6, _8, _10, _12, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	

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
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("methodRoutes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("methodRoutes"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("matches"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("matches"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("keyRouteIds"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("keyRouteIds"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("keyRouteNames"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("keyRouteNames"), &_11$$8);
		}
		zephir_read_property_ex(&_12, this_ptr, ZEND_STRL("defaultParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("defaultParams"), &_13$$9);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

