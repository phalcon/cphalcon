
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "Zend/zend_closures.h"
#include "kernel/concat.h"
#include "kernel/variables.h"
#include "kernel/require.h"
#include "kernel/string.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Additional enhancements inspired by FastRoute and Symfony
 *
 * @link    https://github.com/nikic/FastRoute
 * @license https://github.com/nikic/FastRoute/blob/master/LICENSE
 * @link    https://github.com/symfony/routing
 * @license https://github.com/symfony/routing/blob/8.1/LICENSE
 * @link    https://github.com/Jurigag/fast-micro-router-phalcon
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
	 * Pre-merged per-method candidate buckets in attach order. For each HTTP
	 * method seen on any registered route, the bucket contains the
	 * method-specific routes followed by the "*" (no-constraint) routes.
	 * The "*" key itself holds only the no-constraint routes - used when the
	 * request method has no specific bucket.
	 *
	 * Built in rebuildMethodIndex(); consumed by handle() in reverse.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("candidatesByMethod"), ZEND_ACC_PROTECTED);
	/**
	 * Single-source per-route metadata cache. One entry per route, keyed
	 * by the route's intrinsic id. Replaces the previous per-method-bucket
	 * replication of metadata arrays. Built once in rebuildMethodIndex().
	 *
	 * Shape: routeMeta[routeId] = [
	 *     "pattern":     string,        // compiled pattern
	 *     "isRegex":     bool,
	 *     "hostname":    string|null,
	 *     "hostRegex":   string|null,
	 *     "beforeMatch": callable|null
	 *   ]
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("routeMeta"), ZEND_ACC_PROTECTED);
	/**
	 * Combined PCRE pattern per method bucket (chunked list of strings).
	 * Each chunk uses (?|...) branch reset and (*:N) mark labels. Built
	 * only when the bucket meets gating: no hostname routes; standard
	 * pattern shape.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("combinedRegexByMethod"), ZEND_ACC_PROTECTED);
	/**
	 * Boolean per method bucket: true when the combined regex cannot be
	 * built (hostname route present, exotic pattern shape, etc.).
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("combinedRegexDisabled"), ZEND_ACC_PROTECTED);
	/**
	 * Map from MARK label back to the route index in
	 * candidatesByMethod[method]. One per chunk.
	 *
	 *   combinedRegexMarkMap[method][chunkIdx][markLabel] = routeIdx
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("combinedRegexMarkMap"), ZEND_ACC_PROTECTED);
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
	 * Per-method buckets of routes with hostname constraints, grouped by
	 * raw hostname string. Routes are referenced by their index into
	 * candidatesByMethod[method]. Built in rebuildMethodIndex().
	 *
	 * Shape: hostnameByMethod[method][hostname] = list of route indices.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("hostnameByMethod"), ZEND_ACC_PROTECTED);
	/**
	 * Per-method indices of routes without a hostname constraint, in
	 * attach order.
	 *
	 * Shape: hostnameLessByMethod[method] = list of route indices into
	 * candidatesByMethod[method].
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("hostnameLessByMethod"), ZEND_ACC_PROTECTED);
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
	 * Lazy-write cache target set by useCache(). When non-null, handle()
	 * writes buildDispatcherDump() to this cache after a successful
	 * rebuild on cache miss, then clears the property to skip subsequent
	 * writes.
	 *
	 * @var CacheAdapterInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("pendingCache"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_router_ce, SL("pendingCacheKey"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_router_ce, SL("removeExtraSlashes"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("routes"), ZEND_ACC_PROTECTED);
	/**
	 * Static-route hash, populated by rebuildMethodIndex(). For each method
	 * bucket (including "*"), maps URI => list of routes whose compiled
	 * pattern is a literal string equal to that URI.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("staticByMethod"), ZEND_ACC_PROTECTED);
	/**
	 * Shadow-detection map. If staticShadowedByMethod[method][uri] is set,
	 * the static URI in that bucket is shadowed by a later-attached regex
	 * route - the fast path MUST NOT be used; fall through to the dynamic
	 * loop so the regex wins (reverse-iteration semantics).
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("staticShadowedByMethod"), ZEND_ACC_PROTECTED);
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
	 * Number of alternatives per combined-regex chunk. Empirically derived
	 * (FastRoute uses ~10) - keeps each chunk below PCRE's optimizer cliff.
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("REGEX_CHUNK_SIZE"), 10);

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
		}
	if (defaultRoutes) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0);
		add_assoc_long_ex(&_1$$3, SL("controller"), 1);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "#^/([\\w0-9\\_\\-]+)[/]{0,1}$#u");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 264, &_2$$3, &_1$$3);
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
		ZVAL_STRING(&_4$$3, "#^/([\\w0-9\\_\\-]+)/([\\w0-9\\.\\_]+)(/.*)?$#u");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 264, &_4$$3, &_3$$3);
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
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 264, &pattern_zv, paths, httpMethods);
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
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Router, attach)
{
	zval _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *route, route_sub, *position_param = NULL, __$true, __$false, _0$$4, _2$$4, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_1$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("methodRoutesDirty", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(route, zephir_get_internal_ce(SL("phalcon\\mvc\\router\\routeinterface")))
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
	if (position == 1) { goto zephir_switch_0_clause_0; }
	if (position == 0) { goto zephir_switch_0_clause_1; }
	goto zephir_switch_0_clause_2;
	zephir_switch_0_clause_0: ;
		zephir_update_property_array_append(this_ptr, SL("routes"), route);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_1: ;
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 1, 0);
		zephir_array_fast_append(&_1$$4, route);
		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$4, &_1$$4, &_2$$4);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 282, &_0$$4);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_2: ;
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_router_exceptions_invalidrouteposition_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 265);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Router.zep", 672);
		ZEPHIR_MM_RESTORE();
		return;
	zephir_switch_0_end: ;

	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 283, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 283, &__$false);
	}
	RETURN_THIS();
}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, clear)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	static zend_string *_zephir_prop_11 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("methodRoutes", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("candidatesByMethod", 18, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("routeMeta", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("staticByMethod", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("staticShadowedByMethod", 22, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("hostnameByMethod", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("hostnameLessByMethod", 20, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("combinedRegexByMethod", 21, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("combinedRegexDisabled", 21, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("combinedRegexMarkMap", 20, 1);
	}
	if (UNEXPECTED(!_zephir_prop_11)) {
		_zephir_prop_11 = zend_string_init("methodRoutesDirty", 17, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 282, &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 284, &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 285, &_2);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 286, &_3);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 287, &_4);
	ZEPHIR_INIT_VAR(&_5);
	array_init(&_5);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 288, &_5);
	ZEPHIR_INIT_VAR(&_6);
	array_init(&_6);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 289, &_6);
	ZEPHIR_INIT_VAR(&_7);
	array_init(&_7);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 290, &_7);
	ZEPHIR_INIT_VAR(&_8);
	array_init(&_8);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 291, &_8);
	ZEPHIR_INIT_VAR(&_9);
	array_init(&_9);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 292, &_9);
	ZEPHIR_INIT_VAR(&_10);
	array_init(&_10);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 293, &_10);
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 283, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 283, &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Produces a pure-data array describing every piece of state needed
 * to reconstruct this router. The returned array is var_export-able
 * (no objects, no closures). Used by dumpDispatcher() and by
 * Phalcon\Cache integration via useCache().
 *
 * Throws when a route has a Closure beforeMatch or converter - those
 * cannot be cached.
 *
 * @throws \Phalcon\Mvc\Router\Exception
 */
PHP_METHOD(Phalcon_Mvc_Router, buildDispatcherDump)
{
	zval _25$$4, _48$$11;
	zend_bool _29, _63, _83, _116, _7$$4, _20$$6, _31$$11, _43$$13, _59$$18, _68$$21, _79$$24, _88$$27, _107$$30, _103$$31, _112$$34, _129$$37, _125$$38, _134$$41;
	zend_string *_4, *_54, *_74, *_94, *_14$$6, *_37$$13, *_98$$30, *_120$$37;
	zend_ulong _3, _53, _73, _93, _13$$6, _36$$13, _97$$30, _119$$37;
	zval route, cb, converters, convName, converter, dumpedRoutes, routeToIdx, scalarIdx, scalarSubKey, scalarVal, methodRoutesScalar, candidatesScalar, staticScalar, innerKey, innerVal, mostInnerVal, mostInnerArr, _0, _1, *_2, _28, _51, *_52, _62, _71, *_72, _82, _91, *_92, _115, _137, _5$$4, _26$$4, _27$$4, _8$$5, _9$$5, _10$$5, *_12$$6, _19$$6, _15$$8, _16$$8, _18$$8, _21$$10, _22$$10, _24$$10, _30$$11, _49$$11, _50$$11, _32$$12, _33$$12, _34$$12, *_35$$13, _42$$13, _38$$15, _39$$15, _41$$15, _44$$17, _45$$17, _47$$17, *_55$$18, _58$$18, _56$$19, _57$$19, _60$$20, _61$$20, *_64$$21, _67$$21, _65$$22, _66$$22, _69$$23, _70$$23, *_75$$24, _78$$24, _76$$25, _77$$25, _80$$26, _81$$26, *_84$$27, _87$$27, _85$$28, _86$$28, _89$$29, _90$$29, _95$$30, *_96$$30, _106$$30, *_99$$31, _102$$31, _100$$32, _101$$32, _104$$33, _105$$33, *_108$$34, _111$$34, _109$$35, _110$$35, _113$$36, _114$$36, _117$$37, *_118$$37, _128$$37, *_121$$38, _124$$38, _122$$39, _123$$39, _126$$40, _127$$40, *_130$$41, _133$$41, _131$$42, _132$$42, _135$$43, _136$$43;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_11 = NULL, *_17 = NULL, *_23 = NULL, *_40 = NULL, *_46 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&cb);
	ZVAL_UNDEF(&converters);
	ZVAL_UNDEF(&convName);
	ZVAL_UNDEF(&converter);
	ZVAL_UNDEF(&dumpedRoutes);
	ZVAL_UNDEF(&routeToIdx);
	ZVAL_UNDEF(&scalarIdx);
	ZVAL_UNDEF(&scalarSubKey);
	ZVAL_UNDEF(&scalarVal);
	ZVAL_UNDEF(&methodRoutesScalar);
	ZVAL_UNDEF(&candidatesScalar);
	ZVAL_UNDEF(&staticScalar);
	ZVAL_UNDEF(&innerKey);
	ZVAL_UNDEF(&innerVal);
	ZVAL_UNDEF(&mostInnerVal);
	ZVAL_UNDEF(&mostInnerArr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_51);
	ZVAL_UNDEF(&_62);
	ZVAL_UNDEF(&_71);
	ZVAL_UNDEF(&_82);
	ZVAL_UNDEF(&_91);
	ZVAL_UNDEF(&_115);
	ZVAL_UNDEF(&_137);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_26$$4);
	ZVAL_UNDEF(&_27$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_49$$11);
	ZVAL_UNDEF(&_50$$11);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_34$$12);
	ZVAL_UNDEF(&_42$$13);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_39$$15);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_45$$17);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_58$$18);
	ZVAL_UNDEF(&_56$$19);
	ZVAL_UNDEF(&_57$$19);
	ZVAL_UNDEF(&_60$$20);
	ZVAL_UNDEF(&_61$$20);
	ZVAL_UNDEF(&_67$$21);
	ZVAL_UNDEF(&_65$$22);
	ZVAL_UNDEF(&_66$$22);
	ZVAL_UNDEF(&_69$$23);
	ZVAL_UNDEF(&_70$$23);
	ZVAL_UNDEF(&_78$$24);
	ZVAL_UNDEF(&_76$$25);
	ZVAL_UNDEF(&_77$$25);
	ZVAL_UNDEF(&_80$$26);
	ZVAL_UNDEF(&_81$$26);
	ZVAL_UNDEF(&_87$$27);
	ZVAL_UNDEF(&_85$$28);
	ZVAL_UNDEF(&_86$$28);
	ZVAL_UNDEF(&_89$$29);
	ZVAL_UNDEF(&_90$$29);
	ZVAL_UNDEF(&_95$$30);
	ZVAL_UNDEF(&_106$$30);
	ZVAL_UNDEF(&_102$$31);
	ZVAL_UNDEF(&_100$$32);
	ZVAL_UNDEF(&_101$$32);
	ZVAL_UNDEF(&_104$$33);
	ZVAL_UNDEF(&_105$$33);
	ZVAL_UNDEF(&_111$$34);
	ZVAL_UNDEF(&_109$$35);
	ZVAL_UNDEF(&_110$$35);
	ZVAL_UNDEF(&_113$$36);
	ZVAL_UNDEF(&_114$$36);
	ZVAL_UNDEF(&_117$$37);
	ZVAL_UNDEF(&_128$$37);
	ZVAL_UNDEF(&_124$$38);
	ZVAL_UNDEF(&_122$$39);
	ZVAL_UNDEF(&_123$$39);
	ZVAL_UNDEF(&_126$$40);
	ZVAL_UNDEF(&_127$$40);
	ZVAL_UNDEF(&_133$$41);
	ZVAL_UNDEF(&_131$$42);
	ZVAL_UNDEF(&_132$$42);
	ZVAL_UNDEF(&_135$$43);
	ZVAL_UNDEF(&_136$$43);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_48$$11);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	static zend_string *_zephir_prop_11 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("methodRoutesDirty", 17, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("routes", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("methodRoutes", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("candidatesByMethod", 18, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("staticByMethod", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("staticShadowedByMethod", 22, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("hostnameByMethod", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("hostnameLessByMethod", 20, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("combinedRegexByMethod", 21, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("combinedRegexDisabled", 21, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("combinedRegexMarkMap", 20, 1);
	}
	if (UNEXPECTED(!_zephir_prop_11)) {
		_zephir_prop_11 = zend_string_init("routeMeta", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 283, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rebuildmethodindex", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&dumpedRoutes);
	array_init(&dumpedRoutes);
	ZEPHIR_INIT_VAR(&routeToIdx);
	array_init(&routeToIdx);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 282, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_1, 0, "phalcon/Mvc/Router.zep", 761);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1), _3, _4, _2)
		{
			ZEPHIR_INIT_NVAR(&scalarIdx);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&scalarIdx, _4);
			} else {
				ZVAL_LONG(&scalarIdx, _3);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _2);
			ZEPHIR_CALL_FUNCTION(&_5$$4, "spl_object_id", &_6, 53, &route);
			zephir_check_call_status();
			zephir_array_update_zval(&routeToIdx, &_5$$4, &scalarIdx, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&cb, &route, "getbeforematch", NULL, 0);
			zephir_check_call_status();
			_7$$4 = Z_TYPE_P(&cb) != IS_NULL;
			if (_7$$4) {
				_7$$4 = zephir_is_instance_of(&cb, SL("Closure"));
			}
			if (_7$$4) {
				ZEPHIR_INIT_NVAR(&_8$$5);
				object_init_ex(&_8$$5, phalcon_mvc_router_exception_ce);
				ZEPHIR_CALL_METHOD(&_9$$5, &route, "getrouteid", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZEPHIR_CONCAT_SVS(&_10$$5, "Cannot cache router: route id '", &_9$$5, "' has a Closure beforeMatch - only string/array callables are cacheable");
				ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", &_11, 9, &_10$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_8$$5, "phalcon/Mvc/Router.zep", 732);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&converters, &route, "getconverters", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&converters) == IS_ARRAY) {
				zephir_is_iterable(&converters, 0, "phalcon/Mvc/Router.zep", 746);
				if (Z_TYPE_P(&converters) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&converters), _13$$6, _14$$6, _12$$6)
					{
						ZEPHIR_INIT_NVAR(&convName);
						if (_14$$6 != NULL) { 
							ZVAL_STR_COPY(&convName, _14$$6);
						} else {
							ZVAL_LONG(&convName, _13$$6);
						}
						ZEPHIR_INIT_NVAR(&converter);
						ZVAL_COPY(&converter, _12$$6);
						if (zephir_is_instance_of(&converter, SL("Closure"))) {
							ZEPHIR_INIT_NVAR(&_15$$8);
							object_init_ex(&_15$$8, phalcon_mvc_router_exception_ce);
							ZEPHIR_CALL_METHOD(&_16$$8, &route, "getrouteid", &_17, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_18$$8);
							ZEPHIR_CONCAT_SVSVS(&_18$$8, "Cannot cache router: route id '", &_16$$8, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
							ZEPHIR_CALL_METHOD(NULL, &_15$$8, "__construct", &_11, 9, &_18$$8);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_15$$8, "phalcon/Mvc/Router.zep", 743);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &converters, "rewind", NULL, 0);
					zephir_check_call_status();
					_20$$6 = 1;
					while (1) {
						if (_20$$6) {
							_20$$6 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &converters, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_19$$6, &converters, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_19$$6)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&convName, &converters, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&converter, &converters, "current", NULL, 0);
						zephir_check_call_status();
							if (zephir_is_instance_of(&converter, SL("Closure"))) {
								ZEPHIR_INIT_NVAR(&_21$$10);
								object_init_ex(&_21$$10, phalcon_mvc_router_exception_ce);
								ZEPHIR_CALL_METHOD(&_22$$10, &route, "getrouteid", &_23, 0);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_24$$10);
								ZEPHIR_CONCAT_SVSVS(&_24$$10, "Cannot cache router: route id '", &_22$$10, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
								ZEPHIR_CALL_METHOD(NULL, &_21$$10, "__construct", &_11, 9, &_24$$10);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_21$$10, "phalcon/Mvc/Router.zep", 743);
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&converter);
				ZEPHIR_INIT_NVAR(&convName);
			}
			ZEPHIR_INIT_NVAR(&_25$$4);
			zephir_create_array(&_25$$4, 9, 0);
			ZEPHIR_INIT_NVAR(&_26$$4);
			zephir_get_class(&_26$$4, &route, 0);
			zephir_array_update_string(&_25$$4, SL("class"), &_26$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_27$$4, &route, "getpattern", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_25$$4, SL("pattern"), &_27$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_27$$4, &route, "getpaths", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_25$$4, SL("paths"), &_27$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_27$$4, &route, "gethttpmethods", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_25$$4, SL("methods"), &_27$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_27$$4, &route, "gethostname", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_25$$4, SL("hostname"), &_27$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_27$$4, &route, "getname", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_25$$4, SL("name"), &_27$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_27$$4, &route, "getrouteid", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_25$$4, SL("id"), &_27$$4, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_25$$4, SL("beforeMatch"), &cb, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_25$$4, SL("converters"), &converters, PH_COPY | PH_SEPARATE);
			zephir_array_append(&dumpedRoutes, &_25$$4, PH_SEPARATE, "phalcon/Mvc/Router.zep", 758);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		_29 = 1;
		while (1) {
			if (_29) {
				_29 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_28, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_28)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&scalarIdx, &_1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_30$$11, "spl_object_id", &_6, 53, &route);
				zephir_check_call_status();
				zephir_array_update_zval(&routeToIdx, &_30$$11, &scalarIdx, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&cb, &route, "getbeforematch", NULL, 0);
				zephir_check_call_status();
				_31$$11 = Z_TYPE_P(&cb) != IS_NULL;
				if (_31$$11) {
					_31$$11 = zephir_is_instance_of(&cb, SL("Closure"));
				}
				if (_31$$11) {
					ZEPHIR_INIT_NVAR(&_32$$12);
					object_init_ex(&_32$$12, phalcon_mvc_router_exception_ce);
					ZEPHIR_CALL_METHOD(&_33$$12, &route, "getrouteid", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_34$$12);
					ZEPHIR_CONCAT_SVS(&_34$$12, "Cannot cache router: route id '", &_33$$12, "' has a Closure beforeMatch - only string/array callables are cacheable");
					ZEPHIR_CALL_METHOD(NULL, &_32$$12, "__construct", &_11, 9, &_34$$12);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_32$$12, "phalcon/Mvc/Router.zep", 732);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&converters, &route, "getconverters", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&converters) == IS_ARRAY) {
					zephir_is_iterable(&converters, 0, "phalcon/Mvc/Router.zep", 746);
					if (Z_TYPE_P(&converters) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&converters), _36$$13, _37$$13, _35$$13)
						{
							ZEPHIR_INIT_NVAR(&convName);
							if (_37$$13 != NULL) { 
								ZVAL_STR_COPY(&convName, _37$$13);
							} else {
								ZVAL_LONG(&convName, _36$$13);
							}
							ZEPHIR_INIT_NVAR(&converter);
							ZVAL_COPY(&converter, _35$$13);
							if (zephir_is_instance_of(&converter, SL("Closure"))) {
								ZEPHIR_INIT_NVAR(&_38$$15);
								object_init_ex(&_38$$15, phalcon_mvc_router_exception_ce);
								ZEPHIR_CALL_METHOD(&_39$$15, &route, "getrouteid", &_40, 0);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_41$$15);
								ZEPHIR_CONCAT_SVSVS(&_41$$15, "Cannot cache router: route id '", &_39$$15, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
								ZEPHIR_CALL_METHOD(NULL, &_38$$15, "__construct", &_11, 9, &_41$$15);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_38$$15, "phalcon/Mvc/Router.zep", 743);
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &converters, "rewind", NULL, 0);
						zephir_check_call_status();
						_43$$13 = 1;
						while (1) {
							if (_43$$13) {
								_43$$13 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &converters, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_42$$13, &converters, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_42$$13)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&convName, &converters, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&converter, &converters, "current", NULL, 0);
							zephir_check_call_status();
								if (zephir_is_instance_of(&converter, SL("Closure"))) {
									ZEPHIR_INIT_NVAR(&_44$$17);
									object_init_ex(&_44$$17, phalcon_mvc_router_exception_ce);
									ZEPHIR_CALL_METHOD(&_45$$17, &route, "getrouteid", &_46, 0);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_47$$17);
									ZEPHIR_CONCAT_SVSVS(&_47$$17, "Cannot cache router: route id '", &_45$$17, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
									ZEPHIR_CALL_METHOD(NULL, &_44$$17, "__construct", &_11, 9, &_47$$17);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_44$$17, "phalcon/Mvc/Router.zep", 743);
									ZEPHIR_MM_RESTORE();
									return;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&converter);
					ZEPHIR_INIT_NVAR(&convName);
				}
				ZEPHIR_INIT_NVAR(&_48$$11);
				zephir_create_array(&_48$$11, 9, 0);
				ZEPHIR_INIT_NVAR(&_49$$11);
				zephir_get_class(&_49$$11, &route, 0);
				zephir_array_update_string(&_48$$11, SL("class"), &_49$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_50$$11, &route, "getpattern", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_48$$11, SL("pattern"), &_50$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_50$$11, &route, "getpaths", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_48$$11, SL("paths"), &_50$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_50$$11, &route, "gethttpmethods", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_48$$11, SL("methods"), &_50$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_50$$11, &route, "gethostname", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_48$$11, SL("hostname"), &_50$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_50$$11, &route, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_48$$11, SL("name"), &_50$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_50$$11, &route, "getrouteid", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_48$$11, SL("id"), &_50$$11, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_48$$11, SL("beforeMatch"), &cb, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_48$$11, SL("converters"), &converters, PH_COPY | PH_SEPARATE);
				zephir_array_append(&dumpedRoutes, &_48$$11, PH_SEPARATE, "phalcon/Mvc/Router.zep", 758);
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&scalarIdx);
	ZEPHIR_INIT_VAR(&methodRoutesScalar);
	array_init(&methodRoutesScalar);
	zephir_read_property_cached(&_51, this_ptr, _zephir_prop_2, 284, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_51, 0, "phalcon/Mvc/Router.zep", 770);
	if (Z_TYPE_P(&_51) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_51), _53, _54, _52)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_54 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _54);
			} else {
				ZVAL_LONG(&innerKey, _53);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _52);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 767);
			if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _55$$18)
				{
					ZEPHIR_INIT_NVAR(&scalarVal);
					ZVAL_COPY(&scalarVal, _55$$18);
					ZEPHIR_CALL_FUNCTION(&_57$$19, "spl_object_id", &_6, 53, &scalarVal);
					zephir_check_call_status();
					zephir_array_fetch(&_56$$19, &routeToIdx, &_57$$19, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 765);
					zephir_array_append(&mostInnerArr, &_56$$19, PH_SEPARATE, "phalcon/Mvc/Router.zep", 765);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
				zephir_check_call_status();
				_59$$18 = 1;
				while (1) {
					if (_59$$18) {
						_59$$18 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_58$$18, &innerVal, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_58$$18)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarVal, &innerVal, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_61$$20, "spl_object_id", &_6, 53, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_60$$20, &routeToIdx, &_61$$20, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 765);
						zephir_array_append(&mostInnerArr, &_60$$20, PH_SEPARATE, "phalcon/Mvc/Router.zep", 765);
				}
			}
			ZEPHIR_INIT_NVAR(&scalarVal);
			zephir_array_update_zval(&methodRoutesScalar, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_51, "rewind", NULL, 0);
		zephir_check_call_status();
		_63 = 1;
		while (1) {
			if (_63) {
				_63 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_51, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_62, &_51, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_62)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, &_51, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, &_51, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 767);
				if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _64$$21)
					{
						ZEPHIR_INIT_NVAR(&scalarVal);
						ZVAL_COPY(&scalarVal, _64$$21);
						ZEPHIR_CALL_FUNCTION(&_66$$22, "spl_object_id", &_6, 53, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_65$$22, &routeToIdx, &_66$$22, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 765);
						zephir_array_append(&mostInnerArr, &_65$$22, PH_SEPARATE, "phalcon/Mvc/Router.zep", 765);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
					zephir_check_call_status();
					_68$$21 = 1;
					while (1) {
						if (_68$$21) {
							_68$$21 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_67$$21, &innerVal, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_67$$21)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarVal, &innerVal, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&_70$$23, "spl_object_id", &_6, 53, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_69$$23, &routeToIdx, &_70$$23, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 765);
							zephir_array_append(&mostInnerArr, &_69$$23, PH_SEPARATE, "phalcon/Mvc/Router.zep", 765);
					}
				}
				ZEPHIR_INIT_NVAR(&scalarVal);
				zephir_array_update_zval(&methodRoutesScalar, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	ZEPHIR_INIT_VAR(&candidatesScalar);
	array_init(&candidatesScalar);
	zephir_read_property_cached(&_71, this_ptr, _zephir_prop_3, 285, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_71, 0, "phalcon/Mvc/Router.zep", 779);
	if (Z_TYPE_P(&_71) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_71), _73, _74, _72)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_74 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _74);
			} else {
				ZVAL_LONG(&innerKey, _73);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _72);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 776);
			if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _75$$24)
				{
					ZEPHIR_INIT_NVAR(&scalarVal);
					ZVAL_COPY(&scalarVal, _75$$24);
					ZEPHIR_CALL_FUNCTION(&_77$$25, "spl_object_id", &_6, 53, &scalarVal);
					zephir_check_call_status();
					zephir_array_fetch(&_76$$25, &routeToIdx, &_77$$25, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 774);
					zephir_array_append(&mostInnerArr, &_76$$25, PH_SEPARATE, "phalcon/Mvc/Router.zep", 774);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
				zephir_check_call_status();
				_79$$24 = 1;
				while (1) {
					if (_79$$24) {
						_79$$24 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_78$$24, &innerVal, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_78$$24)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarVal, &innerVal, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_81$$26, "spl_object_id", &_6, 53, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_80$$26, &routeToIdx, &_81$$26, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 774);
						zephir_array_append(&mostInnerArr, &_80$$26, PH_SEPARATE, "phalcon/Mvc/Router.zep", 774);
				}
			}
			ZEPHIR_INIT_NVAR(&scalarVal);
			zephir_array_update_zval(&candidatesScalar, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_71, "rewind", NULL, 0);
		zephir_check_call_status();
		_83 = 1;
		while (1) {
			if (_83) {
				_83 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_71, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_82, &_71, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_82)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, &_71, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, &_71, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 776);
				if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _84$$27)
					{
						ZEPHIR_INIT_NVAR(&scalarVal);
						ZVAL_COPY(&scalarVal, _84$$27);
						ZEPHIR_CALL_FUNCTION(&_86$$28, "spl_object_id", &_6, 53, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_85$$28, &routeToIdx, &_86$$28, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 774);
						zephir_array_append(&mostInnerArr, &_85$$28, PH_SEPARATE, "phalcon/Mvc/Router.zep", 774);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
					zephir_check_call_status();
					_88$$27 = 1;
					while (1) {
						if (_88$$27) {
							_88$$27 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_87$$27, &innerVal, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_87$$27)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarVal, &innerVal, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&_90$$29, "spl_object_id", &_6, 53, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_89$$29, &routeToIdx, &_90$$29, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 774);
							zephir_array_append(&mostInnerArr, &_89$$29, PH_SEPARATE, "phalcon/Mvc/Router.zep", 774);
					}
				}
				ZEPHIR_INIT_NVAR(&scalarVal);
				zephir_array_update_zval(&candidatesScalar, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	ZEPHIR_INIT_VAR(&staticScalar);
	array_init(&staticScalar);
	zephir_read_property_cached(&_91, this_ptr, _zephir_prop_4, 287, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_91, 0, "phalcon/Mvc/Router.zep", 791);
	if (Z_TYPE_P(&_91) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_91), _93, _94, _92)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_94 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _94);
			} else {
				ZVAL_LONG(&innerKey, _93);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _92);
			ZEPHIR_INIT_NVAR(&_95$$30);
			array_init(&_95$$30);
			zephir_array_update_zval(&staticScalar, &innerKey, &_95$$30, PH_COPY | PH_SEPARATE);
			zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 789);
			if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&innerVal), _97$$30, _98$$30, _96$$30)
				{
					ZEPHIR_INIT_NVAR(&scalarSubKey);
					if (_98$$30 != NULL) { 
						ZVAL_STR_COPY(&scalarSubKey, _98$$30);
					} else {
						ZVAL_LONG(&scalarSubKey, _97$$30);
					}
					ZEPHIR_INIT_NVAR(&mostInnerVal);
					ZVAL_COPY(&mostInnerVal, _96$$30);
					ZEPHIR_INIT_NVAR(&mostInnerArr);
					array_init(&mostInnerArr);
					zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 787);
					if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _99$$31)
						{
							ZEPHIR_INIT_NVAR(&scalarVal);
							ZVAL_COPY(&scalarVal, _99$$31);
							ZEPHIR_CALL_FUNCTION(&_101$$32, "spl_object_id", &_6, 53, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_100$$32, &routeToIdx, &_101$$32, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 785);
							zephir_array_append(&mostInnerArr, &_100$$32, PH_SEPARATE, "phalcon/Mvc/Router.zep", 785);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
						zephir_check_call_status();
						_103$$31 = 1;
						while (1) {
							if (_103$$31) {
								_103$$31 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_102$$31, &mostInnerVal, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_102$$31)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&scalarVal, &mostInnerVal, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&_105$$33, "spl_object_id", &_6, 53, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_104$$33, &routeToIdx, &_105$$33, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 785);
								zephir_array_append(&mostInnerArr, &_104$$33, PH_SEPARATE, "phalcon/Mvc/Router.zep", 785);
						}
					}
					ZEPHIR_INIT_NVAR(&scalarVal);
					zephir_array_update_multi(&staticScalar, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
				zephir_check_call_status();
				_107$$30 = 1;
				while (1) {
					if (_107$$30) {
						_107$$30 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_106$$30, &innerVal, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_106$$30)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarSubKey, &innerVal, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&mostInnerVal, &innerVal, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 787);
						if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _108$$34)
							{
								ZEPHIR_INIT_NVAR(&scalarVal);
								ZVAL_COPY(&scalarVal, _108$$34);
								ZEPHIR_CALL_FUNCTION(&_110$$35, "spl_object_id", &_6, 53, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_109$$35, &routeToIdx, &_110$$35, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 785);
								zephir_array_append(&mostInnerArr, &_109$$35, PH_SEPARATE, "phalcon/Mvc/Router.zep", 785);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
							zephir_check_call_status();
							_112$$34 = 1;
							while (1) {
								if (_112$$34) {
									_112$$34 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_111$$34, &mostInnerVal, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_111$$34)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarVal, &mostInnerVal, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_114$$36, "spl_object_id", &_6, 53, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_113$$36, &routeToIdx, &_114$$36, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 785);
									zephir_array_append(&mostInnerArr, &_113$$36, PH_SEPARATE, "phalcon/Mvc/Router.zep", 785);
							}
						}
						ZEPHIR_INIT_NVAR(&scalarVal);
						zephir_array_update_multi(&staticScalar, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
				}
			}
			ZEPHIR_INIT_NVAR(&mostInnerVal);
			ZEPHIR_INIT_NVAR(&scalarSubKey);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_91, "rewind", NULL, 0);
		zephir_check_call_status();
		_116 = 1;
		while (1) {
			if (_116) {
				_116 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_91, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_115, &_91, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_115)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, &_91, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, &_91, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_117$$37);
				array_init(&_117$$37);
				zephir_array_update_zval(&staticScalar, &innerKey, &_117$$37, PH_COPY | PH_SEPARATE);
				zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 789);
				if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&innerVal), _119$$37, _120$$37, _118$$37)
					{
						ZEPHIR_INIT_NVAR(&scalarSubKey);
						if (_120$$37 != NULL) { 
							ZVAL_STR_COPY(&scalarSubKey, _120$$37);
						} else {
							ZVAL_LONG(&scalarSubKey, _119$$37);
						}
						ZEPHIR_INIT_NVAR(&mostInnerVal);
						ZVAL_COPY(&mostInnerVal, _118$$37);
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 787);
						if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _121$$38)
							{
								ZEPHIR_INIT_NVAR(&scalarVal);
								ZVAL_COPY(&scalarVal, _121$$38);
								ZEPHIR_CALL_FUNCTION(&_123$$39, "spl_object_id", &_6, 53, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_122$$39, &routeToIdx, &_123$$39, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 785);
								zephir_array_append(&mostInnerArr, &_122$$39, PH_SEPARATE, "phalcon/Mvc/Router.zep", 785);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
							zephir_check_call_status();
							_125$$38 = 1;
							while (1) {
								if (_125$$38) {
									_125$$38 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_124$$38, &mostInnerVal, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_124$$38)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarVal, &mostInnerVal, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_127$$40, "spl_object_id", &_6, 53, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_126$$40, &routeToIdx, &_127$$40, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 785);
									zephir_array_append(&mostInnerArr, &_126$$40, PH_SEPARATE, "phalcon/Mvc/Router.zep", 785);
							}
						}
						ZEPHIR_INIT_NVAR(&scalarVal);
						zephir_array_update_multi(&staticScalar, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
					zephir_check_call_status();
					_129$$37 = 1;
					while (1) {
						if (_129$$37) {
							_129$$37 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_128$$37, &innerVal, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_128$$37)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarSubKey, &innerVal, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&mostInnerVal, &innerVal, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&mostInnerArr);
							array_init(&mostInnerArr);
							zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 787);
							if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _130$$41)
								{
									ZEPHIR_INIT_NVAR(&scalarVal);
									ZVAL_COPY(&scalarVal, _130$$41);
									ZEPHIR_CALL_FUNCTION(&_132$$42, "spl_object_id", &_6, 53, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_131$$42, &routeToIdx, &_132$$42, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 785);
									zephir_array_append(&mostInnerArr, &_131$$42, PH_SEPARATE, "phalcon/Mvc/Router.zep", 785);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
								zephir_check_call_status();
								_134$$41 = 1;
								while (1) {
									if (_134$$41) {
										_134$$41 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_133$$41, &mostInnerVal, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_133$$41)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&scalarVal, &mostInnerVal, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_136$$43, "spl_object_id", &_6, 53, &scalarVal);
										zephir_check_call_status();
										zephir_array_fetch(&_135$$43, &routeToIdx, &_136$$43, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 785);
										zephir_array_append(&mostInnerArr, &_135$$43, PH_SEPARATE, "phalcon/Mvc/Router.zep", 785);
								}
							}
							ZEPHIR_INIT_NVAR(&scalarVal);
							zephir_array_update_multi(&staticScalar, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
					}
				}
				ZEPHIR_INIT_NVAR(&mostInnerVal);
				ZEPHIR_INIT_NVAR(&scalarSubKey);
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	zephir_create_array(return_value, 12, 0);
	add_assoc_long_ex(return_value, SL("version"), 1);
	zephir_array_update_string(return_value, SL("routes"), &dumpedRoutes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("methodRoutes"), &methodRoutesScalar, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("candidatesByMethod"), &candidatesScalar, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("staticByMethod"), &staticScalar, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_137);
	zephir_read_property_cached(&_137, this_ptr, _zephir_prop_5, 288, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("staticShadowedByMethod"), &_137, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_137);
	zephir_read_property_cached(&_137, this_ptr, _zephir_prop_6, 289, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("hostnameByMethod"), &_137, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_137);
	zephir_read_property_cached(&_137, this_ptr, _zephir_prop_7, 290, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("hostnameLessByMethod"), &_137, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_137);
	zephir_read_property_cached(&_137, this_ptr, _zephir_prop_8, 291, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("combinedRegexByMethod"), &_137, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_137);
	zephir_read_property_cached(&_137, this_ptr, _zephir_prop_9, 292, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("combinedRegexDisabled"), &_137, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_137);
	zephir_read_property_cached(&_137, this_ptr, _zephir_prop_10, 293, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("combinedRegexMarkMap"), &_137, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_137);
	zephir_read_property_cached(&_137, this_ptr, _zephir_prop_11, 286, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("routeMeta"), &_137, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Inverse of buildDispatcherDump(). Reconstructs every Route from the
 * scalar `routes` entries (preserving subclass and routeId), restores
 * every index, and marks the indexes clean so handle() skips rebuild.
 *
 * @throws \Phalcon\Mvc\Router\Exception
 */
PHP_METHOD(Phalcon_Mvc_Router, loadDispatcherFromArray)
{
	zend_class_entry *_7$$6, *_26$$13;
	zval _3$$4;
	zend_string *_45, *_65, *_85, *_18$$10, *_37$$17, *_89$$32, *_111$$39;
	zend_ulong _44, _64, _84, _17$$10, _36$$17, _88$$32, _110$$39;
	zend_bool _24, _54, _74, _107, _21$$10, _40$$17, _50$$20, _59$$23, _70$$26, _79$$29, _98$$32, _94$$33, _103$$36, _120$$39, _116$$40, _125$$43;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_19 = NULL, *_22 = NULL, *_38 = NULL, *_41 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, dumpVersion = 0;
	zval *dump_param = NULL, __$true, __$false, routeData, route, routeClass, beforeMatch, converters, convName, converter, rebuiltRoutes, methodRoutesRehydrated, candidatesRehydrated, staticRehydrated, innerKey, innerVal, scalarIdx, scalarSubKey, mostInnerVal, mostInnerArr, _0, _4, *_5, _23, _42, *_43, _53, _62, *_63, _73, _82, *_83, _106, _128, _129, _130, _131, _132, _133, _134, _135, _136, _1$$4, _2$$4, _6$$6, _8$$6, _9$$6, _10$$6, _11$$6, _13$$6, _15$$6, _12$$7, _14$$8, *_16$$10, _20$$10, _25$$13, _27$$13, _28$$13, _29$$13, _30$$13, _32$$13, _34$$13, _31$$14, _33$$15, *_35$$17, _39$$17, *_46$$20, _49$$20, _47$$21, _48$$21, _51$$22, _52$$22, *_55$$23, _58$$23, _56$$24, _57$$24, _60$$25, _61$$25, *_66$$26, _69$$26, _67$$27, _68$$27, _71$$28, _72$$28, *_75$$29, _78$$29, _76$$30, _77$$30, _80$$31, _81$$31, _86$$32, *_87$$32, _97$$32, *_90$$33, _93$$33, _91$$34, _92$$34, _95$$35, _96$$35, *_99$$36, _102$$36, _100$$37, _101$$37, _104$$38, _105$$38, _108$$39, *_109$$39, _119$$39, *_112$$40, _115$$40, _113$$41, _114$$41, _117$$42, _118$$42, *_121$$43, _124$$43, _122$$44, _123$$44, _126$$45, _127$$45;
	zval dump;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dump);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&routeData);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routeClass);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&converters);
	ZVAL_UNDEF(&convName);
	ZVAL_UNDEF(&converter);
	ZVAL_UNDEF(&rebuiltRoutes);
	ZVAL_UNDEF(&methodRoutesRehydrated);
	ZVAL_UNDEF(&candidatesRehydrated);
	ZVAL_UNDEF(&staticRehydrated);
	ZVAL_UNDEF(&innerKey);
	ZVAL_UNDEF(&innerVal);
	ZVAL_UNDEF(&scalarIdx);
	ZVAL_UNDEF(&scalarSubKey);
	ZVAL_UNDEF(&mostInnerVal);
	ZVAL_UNDEF(&mostInnerArr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_53);
	ZVAL_UNDEF(&_62);
	ZVAL_UNDEF(&_73);
	ZVAL_UNDEF(&_82);
	ZVAL_UNDEF(&_106);
	ZVAL_UNDEF(&_128);
	ZVAL_UNDEF(&_129);
	ZVAL_UNDEF(&_130);
	ZVAL_UNDEF(&_131);
	ZVAL_UNDEF(&_132);
	ZVAL_UNDEF(&_133);
	ZVAL_UNDEF(&_134);
	ZVAL_UNDEF(&_135);
	ZVAL_UNDEF(&_136);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_28$$13);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_47$$21);
	ZVAL_UNDEF(&_48$$21);
	ZVAL_UNDEF(&_51$$22);
	ZVAL_UNDEF(&_52$$22);
	ZVAL_UNDEF(&_58$$23);
	ZVAL_UNDEF(&_56$$24);
	ZVAL_UNDEF(&_57$$24);
	ZVAL_UNDEF(&_60$$25);
	ZVAL_UNDEF(&_61$$25);
	ZVAL_UNDEF(&_69$$26);
	ZVAL_UNDEF(&_67$$27);
	ZVAL_UNDEF(&_68$$27);
	ZVAL_UNDEF(&_71$$28);
	ZVAL_UNDEF(&_72$$28);
	ZVAL_UNDEF(&_78$$29);
	ZVAL_UNDEF(&_76$$30);
	ZVAL_UNDEF(&_77$$30);
	ZVAL_UNDEF(&_80$$31);
	ZVAL_UNDEF(&_81$$31);
	ZVAL_UNDEF(&_86$$32);
	ZVAL_UNDEF(&_97$$32);
	ZVAL_UNDEF(&_93$$33);
	ZVAL_UNDEF(&_91$$34);
	ZVAL_UNDEF(&_92$$34);
	ZVAL_UNDEF(&_95$$35);
	ZVAL_UNDEF(&_96$$35);
	ZVAL_UNDEF(&_102$$36);
	ZVAL_UNDEF(&_100$$37);
	ZVAL_UNDEF(&_101$$37);
	ZVAL_UNDEF(&_104$$38);
	ZVAL_UNDEF(&_105$$38);
	ZVAL_UNDEF(&_108$$39);
	ZVAL_UNDEF(&_119$$39);
	ZVAL_UNDEF(&_115$$40);
	ZVAL_UNDEF(&_113$$41);
	ZVAL_UNDEF(&_114$$41);
	ZVAL_UNDEF(&_117$$42);
	ZVAL_UNDEF(&_118$$42);
	ZVAL_UNDEF(&_124$$43);
	ZVAL_UNDEF(&_122$$44);
	ZVAL_UNDEF(&_123$$44);
	ZVAL_UNDEF(&_126$$45);
	ZVAL_UNDEF(&_127$$45);
	ZVAL_UNDEF(&_3$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	static zend_string *_zephir_prop_11 = NULL;
	static zend_string *_zephir_prop_12 = NULL;
	static zend_string *_zephir_prop_13 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("methodRoutes", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("candidatesByMethod", 18, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("staticByMethod", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("staticShadowedByMethod", 22, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("hostnameByMethod", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("hostnameLessByMethod", 20, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("combinedRegexByMethod", 21, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("combinedRegexDisabled", 21, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("combinedRegexMarkMap", 20, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("routeMeta", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_11)) {
		_zephir_prop_11 = zend_string_init("keyRouteIds", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_12)) {
		_zephir_prop_12 = zend_string_init("keyRouteNames", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_13)) {
		_zephir_prop_13 = zend_string_init("methodRoutesDirty", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(dump, dump_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &dump_param);
	zephir_get_arrval(&dump, dump_param);
	if (!(zephir_array_isset_value_string(&dump, SL("version")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Router cache is missing 'version' field", "phalcon/Mvc/Router.zep", 823);
		return;
	}
	zephir_memory_observe(&_0);
	zephir_array_fetch_string(&_0, &dump, SL("version"), PH_NOISY, "phalcon/Mvc/Router.zep", 826);
	dumpVersion = zephir_get_intval(&_0);
	if (dumpVersion != 1) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_LONG(&_2$$4, dumpVersion);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_SVS(&_3$$4, "Router cache version ", &_2$$4, " is not supported (this build supports version 1)");
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 9, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Router.zep", 831);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_array_isset_value_string(&dump, SL("routes")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Router cache is missing 'routes' field", "phalcon/Mvc/Router.zep", 835);
		return;
	}
	ZEPHIR_INIT_VAR(&rebuiltRoutes);
	array_init(&rebuiltRoutes);
	zephir_array_fetch_string(&_4, &dump, SL("routes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 840);
	zephir_is_iterable(&_4, 0, "phalcon/Mvc/Router.zep", 869);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
		{
			ZEPHIR_INIT_NVAR(&routeData);
			ZVAL_COPY(&routeData, _5);
			ZEPHIR_OBS_NVAR(&routeClass);
			zephir_array_fetch_string(&routeClass, &routeData, SL("class"), PH_NOISY, "phalcon/Mvc/Router.zep", 841);
			ZEPHIR_INIT_NVAR(&route);
			zephir_fetch_safe_class(&_6$$6, &routeClass);
			_7$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_6$$6), Z_STRLEN_P(&_6$$6), ZEND_FETCH_CLASS_AUTO);
			if(!_7$$6) {
				RETURN_MM_NULL();
			}
			object_init_ex(&route, _7$$6);
			ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&route);
			zephir_check_call_status();
			if (zephir_has_constructor(&route)) {
				zephir_array_fetch_string(&_8$$6, &routeData, SL("pattern"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 842);
				zephir_array_fetch_string(&_9$$6, &routeData, SL("paths"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 842);
				zephir_array_fetch_string(&_10$$6, &routeData, SL("methods"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 842);
				ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 0, &_8$$6, &_9$$6, &_10$$6);
				zephir_check_call_status();
			}

			zephir_array_fetch_string(&_11$$6, &routeData, SL("hostname"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 844);
			if (Z_TYPE_P(&_11$$6) != IS_NULL) {
				zephir_array_fetch_string(&_12$$7, &routeData, SL("hostname"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 845);
				ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &_12$$7);
				zephir_check_call_status();
			}
			zephir_array_fetch_string(&_13$$6, &routeData, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 848);
			if (Z_TYPE_P(&_13$$6) != IS_NULL) {
				zephir_array_fetch_string(&_14$$8, &routeData, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 849);
				ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &_14$$8);
				zephir_check_call_status();
			}
			zephir_array_fetch_string(&_15$$6, &routeData, SL("id"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 852);
			ZEPHIR_CALL_METHOD(NULL, &route, "setrouteid", NULL, 0, &_15$$6);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&beforeMatch);
			zephir_array_fetch_string(&beforeMatch, &routeData, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 854);
			if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&converters);
			zephir_array_fetch_string(&converters, &routeData, SL("converters"), PH_NOISY, "phalcon/Mvc/Router.zep", 859);
			if (Z_TYPE_P(&converters) == IS_ARRAY) {
				zephir_is_iterable(&converters, 0, "phalcon/Mvc/Router.zep", 864);
				if (Z_TYPE_P(&converters) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&converters), _17$$10, _18$$10, _16$$10)
					{
						ZEPHIR_INIT_NVAR(&convName);
						if (_18$$10 != NULL) { 
							ZVAL_STR_COPY(&convName, _18$$10);
						} else {
							ZVAL_LONG(&convName, _17$$10);
						}
						ZEPHIR_INIT_NVAR(&converter);
						ZVAL_COPY(&converter, _16$$10);
						ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_19, 0, &convName, &converter);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &converters, "rewind", NULL, 0);
					zephir_check_call_status();
					_21$$10 = 1;
					while (1) {
						if (_21$$10) {
							_21$$10 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &converters, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_20$$10, &converters, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_20$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&convName, &converters, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&converter, &converters, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_22, 0, &convName, &converter);
							zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&converter);
				ZEPHIR_INIT_NVAR(&convName);
			}
			zephir_array_append(&rebuiltRoutes, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 866);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		_24 = 1;
		while (1) {
			if (_24) {
				_24 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_23, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&routeData, &_4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&routeClass);
				zephir_array_fetch_string(&routeClass, &routeData, SL("class"), PH_NOISY, "phalcon/Mvc/Router.zep", 841);
				ZEPHIR_INIT_NVAR(&route);
				zephir_fetch_safe_class(&_25$$13, &routeClass);
				_26$$13 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_25$$13), Z_STRLEN_P(&_25$$13), ZEND_FETCH_CLASS_AUTO);
				if(!_26$$13) {
					RETURN_MM_NULL();
				}
				object_init_ex(&route, _26$$13);
				ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&route);
				zephir_check_call_status();
				if (zephir_has_constructor(&route)) {
					zephir_array_fetch_string(&_27$$13, &routeData, SL("pattern"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 842);
					zephir_array_fetch_string(&_28$$13, &routeData, SL("paths"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 842);
					zephir_array_fetch_string(&_29$$13, &routeData, SL("methods"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 842);
					ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 0, &_27$$13, &_28$$13, &_29$$13);
					zephir_check_call_status();
				}

				zephir_array_fetch_string(&_30$$13, &routeData, SL("hostname"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 844);
				if (Z_TYPE_P(&_30$$13) != IS_NULL) {
					zephir_array_fetch_string(&_31$$14, &routeData, SL("hostname"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 845);
					ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &_31$$14);
					zephir_check_call_status();
				}
				zephir_array_fetch_string(&_32$$13, &routeData, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 848);
				if (Z_TYPE_P(&_32$$13) != IS_NULL) {
					zephir_array_fetch_string(&_33$$15, &routeData, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 849);
					ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &_33$$15);
					zephir_check_call_status();
				}
				zephir_array_fetch_string(&_34$$13, &routeData, SL("id"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 852);
				ZEPHIR_CALL_METHOD(NULL, &route, "setrouteid", NULL, 0, &_34$$13);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&beforeMatch);
				zephir_array_fetch_string(&beforeMatch, &routeData, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 854);
				if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&converters);
				zephir_array_fetch_string(&converters, &routeData, SL("converters"), PH_NOISY, "phalcon/Mvc/Router.zep", 859);
				if (Z_TYPE_P(&converters) == IS_ARRAY) {
					zephir_is_iterable(&converters, 0, "phalcon/Mvc/Router.zep", 864);
					if (Z_TYPE_P(&converters) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&converters), _36$$17, _37$$17, _35$$17)
						{
							ZEPHIR_INIT_NVAR(&convName);
							if (_37$$17 != NULL) { 
								ZVAL_STR_COPY(&convName, _37$$17);
							} else {
								ZVAL_LONG(&convName, _36$$17);
							}
							ZEPHIR_INIT_NVAR(&converter);
							ZVAL_COPY(&converter, _35$$17);
							ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_38, 0, &convName, &converter);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &converters, "rewind", NULL, 0);
						zephir_check_call_status();
						_40$$17 = 1;
						while (1) {
							if (_40$$17) {
								_40$$17 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &converters, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_39$$17, &converters, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_39$$17)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&convName, &converters, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&converter, &converters, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_41, 0, &convName, &converter);
								zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&converter);
					ZEPHIR_INIT_NVAR(&convName);
				}
				zephir_array_append(&rebuiltRoutes, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 866);
		}
	}
	ZEPHIR_INIT_NVAR(&routeData);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 282, &rebuiltRoutes);
	ZEPHIR_INIT_VAR(&methodRoutesRehydrated);
	array_init(&methodRoutesRehydrated);
	zephir_array_fetch_string(&_42, &dump, SL("methodRoutes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 872);
	zephir_is_iterable(&_42, 0, "phalcon/Mvc/Router.zep", 880);
	if (Z_TYPE_P(&_42) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_42), _44, _45, _43)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_45 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _45);
			} else {
				ZVAL_LONG(&innerKey, _44);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _43);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 877);
			if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _46$$20)
				{
					ZEPHIR_INIT_NVAR(&scalarIdx);
					ZVAL_COPY(&scalarIdx, _46$$20);
					zephir_read_property_cached(&_47$$21, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_48$$21, &_47$$21, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 875);
					zephir_array_append(&mostInnerArr, &_48$$21, PH_SEPARATE, "phalcon/Mvc/Router.zep", 875);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
				zephir_check_call_status();
				_50$$20 = 1;
				while (1) {
					if (_50$$20) {
						_50$$20 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_49$$20, &innerVal, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_49$$20)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarIdx, &innerVal, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property_cached(&_51$$22, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_52$$22, &_51$$22, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 875);
						zephir_array_append(&mostInnerArr, &_52$$22, PH_SEPARATE, "phalcon/Mvc/Router.zep", 875);
				}
			}
			ZEPHIR_INIT_NVAR(&scalarIdx);
			zephir_array_update_zval(&methodRoutesRehydrated, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_42, "rewind", NULL, 0);
		zephir_check_call_status();
		_54 = 1;
		while (1) {
			if (_54) {
				_54 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_42, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_53, &_42, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_53)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, &_42, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, &_42, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 877);
				if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _55$$23)
					{
						ZEPHIR_INIT_NVAR(&scalarIdx);
						ZVAL_COPY(&scalarIdx, _55$$23);
						zephir_read_property_cached(&_56$$24, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_57$$24, &_56$$24, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 875);
						zephir_array_append(&mostInnerArr, &_57$$24, PH_SEPARATE, "phalcon/Mvc/Router.zep", 875);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
					zephir_check_call_status();
					_59$$23 = 1;
					while (1) {
						if (_59$$23) {
							_59$$23 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_58$$23, &innerVal, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_58$$23)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarIdx, &innerVal, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property_cached(&_60$$25, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch(&_61$$25, &_60$$25, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 875);
							zephir_array_append(&mostInnerArr, &_61$$25, PH_SEPARATE, "phalcon/Mvc/Router.zep", 875);
					}
				}
				ZEPHIR_INIT_NVAR(&scalarIdx);
				zephir_array_update_zval(&methodRoutesRehydrated, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	ZEPHIR_INIT_VAR(&candidatesRehydrated);
	array_init(&candidatesRehydrated);
	zephir_array_fetch_string(&_62, &dump, SL("candidatesByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 881);
	zephir_is_iterable(&_62, 0, "phalcon/Mvc/Router.zep", 889);
	if (Z_TYPE_P(&_62) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_62), _64, _65, _63)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_65 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _65);
			} else {
				ZVAL_LONG(&innerKey, _64);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _63);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 886);
			if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _66$$26)
				{
					ZEPHIR_INIT_NVAR(&scalarIdx);
					ZVAL_COPY(&scalarIdx, _66$$26);
					zephir_read_property_cached(&_67$$27, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_68$$27, &_67$$27, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 884);
					zephir_array_append(&mostInnerArr, &_68$$27, PH_SEPARATE, "phalcon/Mvc/Router.zep", 884);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
				zephir_check_call_status();
				_70$$26 = 1;
				while (1) {
					if (_70$$26) {
						_70$$26 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_69$$26, &innerVal, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_69$$26)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarIdx, &innerVal, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property_cached(&_71$$28, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_72$$28, &_71$$28, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 884);
						zephir_array_append(&mostInnerArr, &_72$$28, PH_SEPARATE, "phalcon/Mvc/Router.zep", 884);
				}
			}
			ZEPHIR_INIT_NVAR(&scalarIdx);
			zephir_array_update_zval(&candidatesRehydrated, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_62, "rewind", NULL, 0);
		zephir_check_call_status();
		_74 = 1;
		while (1) {
			if (_74) {
				_74 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_62, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_73, &_62, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_73)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, &_62, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, &_62, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 886);
				if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _75$$29)
					{
						ZEPHIR_INIT_NVAR(&scalarIdx);
						ZVAL_COPY(&scalarIdx, _75$$29);
						zephir_read_property_cached(&_76$$30, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_77$$30, &_76$$30, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 884);
						zephir_array_append(&mostInnerArr, &_77$$30, PH_SEPARATE, "phalcon/Mvc/Router.zep", 884);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
					zephir_check_call_status();
					_79$$29 = 1;
					while (1) {
						if (_79$$29) {
							_79$$29 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_78$$29, &innerVal, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_78$$29)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarIdx, &innerVal, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property_cached(&_80$$31, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch(&_81$$31, &_80$$31, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 884);
							zephir_array_append(&mostInnerArr, &_81$$31, PH_SEPARATE, "phalcon/Mvc/Router.zep", 884);
					}
				}
				ZEPHIR_INIT_NVAR(&scalarIdx);
				zephir_array_update_zval(&candidatesRehydrated, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	ZEPHIR_INIT_VAR(&staticRehydrated);
	array_init(&staticRehydrated);
	zephir_array_fetch_string(&_82, &dump, SL("staticByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 890);
	zephir_is_iterable(&_82, 0, "phalcon/Mvc/Router.zep", 901);
	if (Z_TYPE_P(&_82) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_82), _84, _85, _83)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_85 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _85);
			} else {
				ZVAL_LONG(&innerKey, _84);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _83);
			ZEPHIR_INIT_NVAR(&_86$$32);
			array_init(&_86$$32);
			zephir_array_update_zval(&staticRehydrated, &innerKey, &_86$$32, PH_COPY | PH_SEPARATE);
			zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 899);
			if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&innerVal), _88$$32, _89$$32, _87$$32)
				{
					ZEPHIR_INIT_NVAR(&scalarSubKey);
					if (_89$$32 != NULL) { 
						ZVAL_STR_COPY(&scalarSubKey, _89$$32);
					} else {
						ZVAL_LONG(&scalarSubKey, _88$$32);
					}
					ZEPHIR_INIT_NVAR(&mostInnerVal);
					ZVAL_COPY(&mostInnerVal, _87$$32);
					ZEPHIR_INIT_NVAR(&mostInnerArr);
					array_init(&mostInnerArr);
					zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 897);
					if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _90$$33)
						{
							ZEPHIR_INIT_NVAR(&scalarIdx);
							ZVAL_COPY(&scalarIdx, _90$$33);
							zephir_read_property_cached(&_91$$34, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch(&_92$$34, &_91$$34, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 895);
							zephir_array_append(&mostInnerArr, &_92$$34, PH_SEPARATE, "phalcon/Mvc/Router.zep", 895);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
						zephir_check_call_status();
						_94$$33 = 1;
						while (1) {
							if (_94$$33) {
								_94$$33 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_93$$33, &mostInnerVal, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_93$$33)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&scalarIdx, &mostInnerVal, "current", NULL, 0);
							zephir_check_call_status();
								zephir_read_property_cached(&_95$$35, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch(&_96$$35, &_95$$35, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 895);
								zephir_array_append(&mostInnerArr, &_96$$35, PH_SEPARATE, "phalcon/Mvc/Router.zep", 895);
						}
					}
					ZEPHIR_INIT_NVAR(&scalarIdx);
					zephir_array_update_multi(&staticRehydrated, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
				zephir_check_call_status();
				_98$$32 = 1;
				while (1) {
					if (_98$$32) {
						_98$$32 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_97$$32, &innerVal, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_97$$32)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarSubKey, &innerVal, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&mostInnerVal, &innerVal, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 897);
						if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _99$$36)
							{
								ZEPHIR_INIT_NVAR(&scalarIdx);
								ZVAL_COPY(&scalarIdx, _99$$36);
								zephir_read_property_cached(&_100$$37, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch(&_101$$37, &_100$$37, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 895);
								zephir_array_append(&mostInnerArr, &_101$$37, PH_SEPARATE, "phalcon/Mvc/Router.zep", 895);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
							zephir_check_call_status();
							_103$$36 = 1;
							while (1) {
								if (_103$$36) {
									_103$$36 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_102$$36, &mostInnerVal, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_102$$36)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarIdx, &mostInnerVal, "current", NULL, 0);
								zephir_check_call_status();
									zephir_read_property_cached(&_104$$38, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch(&_105$$38, &_104$$38, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 895);
									zephir_array_append(&mostInnerArr, &_105$$38, PH_SEPARATE, "phalcon/Mvc/Router.zep", 895);
							}
						}
						ZEPHIR_INIT_NVAR(&scalarIdx);
						zephir_array_update_multi(&staticRehydrated, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
				}
			}
			ZEPHIR_INIT_NVAR(&mostInnerVal);
			ZEPHIR_INIT_NVAR(&scalarSubKey);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_82, "rewind", NULL, 0);
		zephir_check_call_status();
		_107 = 1;
		while (1) {
			if (_107) {
				_107 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_82, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_106, &_82, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_106)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, &_82, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, &_82, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_108$$39);
				array_init(&_108$$39);
				zephir_array_update_zval(&staticRehydrated, &innerKey, &_108$$39, PH_COPY | PH_SEPARATE);
				zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 899);
				if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&innerVal), _110$$39, _111$$39, _109$$39)
					{
						ZEPHIR_INIT_NVAR(&scalarSubKey);
						if (_111$$39 != NULL) { 
							ZVAL_STR_COPY(&scalarSubKey, _111$$39);
						} else {
							ZVAL_LONG(&scalarSubKey, _110$$39);
						}
						ZEPHIR_INIT_NVAR(&mostInnerVal);
						ZVAL_COPY(&mostInnerVal, _109$$39);
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 897);
						if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _112$$40)
							{
								ZEPHIR_INIT_NVAR(&scalarIdx);
								ZVAL_COPY(&scalarIdx, _112$$40);
								zephir_read_property_cached(&_113$$41, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch(&_114$$41, &_113$$41, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 895);
								zephir_array_append(&mostInnerArr, &_114$$41, PH_SEPARATE, "phalcon/Mvc/Router.zep", 895);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
							zephir_check_call_status();
							_116$$40 = 1;
							while (1) {
								if (_116$$40) {
									_116$$40 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_115$$40, &mostInnerVal, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_115$$40)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarIdx, &mostInnerVal, "current", NULL, 0);
								zephir_check_call_status();
									zephir_read_property_cached(&_117$$42, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch(&_118$$42, &_117$$42, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 895);
									zephir_array_append(&mostInnerArr, &_118$$42, PH_SEPARATE, "phalcon/Mvc/Router.zep", 895);
							}
						}
						ZEPHIR_INIT_NVAR(&scalarIdx);
						zephir_array_update_multi(&staticRehydrated, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
					zephir_check_call_status();
					_120$$39 = 1;
					while (1) {
						if (_120$$39) {
							_120$$39 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_119$$39, &innerVal, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_119$$39)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarSubKey, &innerVal, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&mostInnerVal, &innerVal, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&mostInnerArr);
							array_init(&mostInnerArr);
							zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 897);
							if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _121$$43)
								{
									ZEPHIR_INIT_NVAR(&scalarIdx);
									ZVAL_COPY(&scalarIdx, _121$$43);
									zephir_read_property_cached(&_122$$44, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch(&_123$$44, &_122$$44, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 895);
									zephir_array_append(&mostInnerArr, &_123$$44, PH_SEPARATE, "phalcon/Mvc/Router.zep", 895);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
								zephir_check_call_status();
								_125$$43 = 1;
								while (1) {
									if (_125$$43) {
										_125$$43 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_124$$43, &mostInnerVal, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_124$$43)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&scalarIdx, &mostInnerVal, "current", NULL, 0);
									zephir_check_call_status();
										zephir_read_property_cached(&_126$$45, this_ptr, _zephir_prop_0, 282, PH_NOISY_CC | PH_READONLY);
										zephir_array_fetch(&_127$$45, &_126$$45, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 895);
										zephir_array_append(&mostInnerArr, &_127$$45, PH_SEPARATE, "phalcon/Mvc/Router.zep", 895);
								}
							}
							ZEPHIR_INIT_NVAR(&scalarIdx);
							zephir_array_update_multi(&staticRehydrated, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
					}
				}
				ZEPHIR_INIT_NVAR(&mostInnerVal);
				ZEPHIR_INIT_NVAR(&scalarSubKey);
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 284, &methodRoutesRehydrated);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 285, &candidatesRehydrated);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 287, &staticRehydrated);
	zephir_array_fetch_string(&_128, &dump, SL("staticShadowedByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 904);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 288, &_128);
	zephir_array_fetch_string(&_129, &dump, SL("hostnameByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 905);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 289, &_129);
	zephir_array_fetch_string(&_130, &dump, SL("hostnameLessByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 906);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 290, &_130);
	zephir_array_fetch_string(&_131, &dump, SL("combinedRegexByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 907);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 291, &_131);
	zephir_array_fetch_string(&_132, &dump, SL("combinedRegexDisabled"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 908);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 292, &_132);
	zephir_array_fetch_string(&_133, &dump, SL("combinedRegexMarkMap"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 909);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 293, &_133);
	zephir_array_fetch_string(&_134, &dump, SL("routeMeta"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 910);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 286, &_134);
	ZEPHIR_INIT_VAR(&_135);
	array_init(&_135);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 294, &_135);
	ZEPHIR_INIT_VAR(&_136);
	array_init(&_136);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_12, 295, &_136);
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_13, 283, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_13, 283, &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * File-shaped helper around buildDispatcherDump(). Writes the dump as
 * a `<?php return [...];` file, atomically (temp + rename) so concurrent
 * dumps don't corrupt the result.
 *
 * @throws \Phalcon\Mvc\Router\Exception
 */
PHP_METHOD(Phalcon_Mvc_Router, dumpDispatcher)
{
	zval _2, _3, _9$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval path_zv, dump, php, tmpPath, _0, _1, _4, _7, _5$$3, _6$$3, _8$$4;
	zend_string *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&dump);
	ZVAL_UNDEF(&php);
	ZVAL_UNDEF(&tmpPath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	ZEPHIR_CALL_METHOD(&dump, this_ptr, "builddispatcherdump", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_var_export_ex(&_0, &dump);
	ZEPHIR_INIT_VAR(&php);
	ZEPHIR_CONCAT_SVS(&php, "<?php\nreturn ", &_0, ";\n");
	ZEPHIR_CALL_FUNCTION(&_1, "getmypid", NULL, 266);
	zephir_check_call_status();
	zephir_cast_to_string(&_2, &_1);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSV(&_3, &path_zv, ".tmp.", &_2);
	ZEPHIR_CPY_WRT(&tmpPath, &_3);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "phpfileputcontents", NULL, 0, &tmpPath, &php);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SV(&_6$$3, "Failed to write router cache temp file: ", &tmpPath);
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 9, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "phalcon/Mvc/Router.zep", 932);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_7, "rename", NULL, 267, &tmpPath, &path_zv);
	zephir_check_call_status();
	if (!(zephir_is_true(&_7))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "phpunlink", NULL, 0, &tmpPath);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$4);
		object_init_ex(&_8$$4, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZEPHIR_CONCAT_SV(&_9$$4, "Failed to commit router cache: ", &path_zv);
		ZEPHIR_CALL_METHOD(NULL, &_8$$4, "__construct", NULL, 9, &_9$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$4, "phalcon/Mvc/Router.zep", 937);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * File-shaped helper around loadDispatcherFromArray(). Includes the
 * file (opcache-friendly) and forwards the return value.
 *
 * @throws \Phalcon\Mvc\Router\Exception
 */
PHP_METHOD(Phalcon_Mvc_Router, loadDispatcher)
{
	zval _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval path_zv, dump, _0, _3, _1$$3, _4$$4, _5$$4, _6$$4;
	zend_string *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&dump);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpfileexists", NULL, 0, &path_zv);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Router cache not found: ", &path_zv);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 9, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Router.zep", 952);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_3);
	if (zephir_require_zval_ret(&_3, &path_zv) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(&dump, &_3);
	if (Z_TYPE_P(&dump) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		zephir_gettype(&_5$$4, &dump);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZEPHIR_CONCAT_SVSV(&_6$$4, "Router cache is corrupt or invalid (expected array, got ", &_5$$4, "): ", &path_zv);
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 9, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Mvc/Router.zep", 960);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loaddispatcherfromarray", NULL, 0, &dump);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Cache-instance convenience wrapper. On cache hit, restores the
 * dispatcher immediately. On miss, defers cache population until the
 * next handle() completes - at which point buildDispatcherDump() is
 * written to the cache key.
 *
 * @throws \Phalcon\Mvc\Router\Exception
 */
PHP_METHOD(Phalcon_Mvc_Router, useCache)
{
	zval _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *key = NULL;
	zval *cache, cache_sub, key_zv, stored, _0, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache_sub);
	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&stored);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("pendingCache", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("pendingCacheKey", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(cache, zephir_get_internal_ce(SL("phalcon\\cache\\adapter\\adapterinterface")))
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	cache = ZEND_CALL_ARG(execute_data, 1);
	if (!key) {
		key = zend_string_init(ZEND_STRL("phalcon.router.dispatcher"), 0);
		zephir_memory_observe(&key_zv);
		ZVAL_STR(&key_zv, key);
	} else {
		zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	}
	ZEPHIR_CALL_METHOD(&_0, cache, "has", NULL, 0, &key_zv);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&stored, cache, "get", NULL, 0, &key_zv);
		zephir_check_call_status();
		if (Z_TYPE_P(&stored) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_mvc_router_exception_ce);
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_CONCAT_SVS(&_2$$4, "Router cache value at key '", &key_zv, "' is not an array");
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 9, &_2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Router.zep", 984);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loaddispatcherfromarray", NULL, 0, &stored);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 296, cache);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 297, &key_zv);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultNamespace", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("defaultModule", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("defaultController", 17, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("defaultAction", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("defaultParams", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_create_array(return_value, 5, 0);
	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 298, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("namespace"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 299, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("module"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 300, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("controller"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 301, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("action"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 302, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("params"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteIds)
{

	RETURN_MEMBER_TYPED(getThis(), "keyRouteIds", IS_ARRAY);
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteNames)
{

	RETURN_MEMBER_TYPED(getThis(), "keyRouteNames", IS_ARRAY);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("methodRoutesDirty", 17, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 283, PH_NOISY_CC | PH_READONLY);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("uriSource", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_GET, SL("_GET"));

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 303, PH_NOISY_CC | PH_READONLY);
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

/**
 * Returns a route object by its id
 *
 * @param mixed $routeId
 *
 * @return RouteInterface|bool
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteById)
{
	zend_bool _8;
	zend_string *_6;
	zend_ulong _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routeId, routeId_sub, localRouteId, route, key, _0, _3, *_4, _7, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeId_sub);
	ZVAL_UNDEF(&localRouteId);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("keyRouteIds", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("routes", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(routeId)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &routeId);
	zephir_memory_observe(&key);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 294, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&key, &_0, routeId, 0)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 282, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1147);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 282, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/Mvc/Router.zep", 1159);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
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
			ZEPHIR_CALL_METHOD(&localRouteId, &route, "getrouteid", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("keyRouteIds"), &localRouteId, &key);
			if (ZEPHIR_IS_EQUAL(&localRouteId, routeId)) {
				RETURN_CCTOR(&route);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, &_3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&localRouteId, &route, "getrouteid", NULL, 0);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("keyRouteIds"), &localRouteId, &key);
				if (ZEPHIR_IS_EQUAL(&localRouteId, routeId)) {
					RETURN_CCTOR(&route);
				}
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
	zend_bool _8;
	zend_ulong _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, route, routeName, key, _0, _3, *_4, _7, _1$$3, _2$$3;
	zend_string *name = NULL, *_6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("keyRouteNames", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("routes", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&key);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 295, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&key, &_0, &name_zv, 0)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 282, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1174);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 282, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/Mvc/Router.zep", 1189);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
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
				zephir_update_property_array(this_ptr, SL("keyRouteNames"), &routeName, &key);
				if (ZEPHIR_IS_EQUAL(&routeName, &name_zv)) {
					RETURN_CCTOR(&route);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
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
	zend_ulong _47$$39, _56$$40, _82$$62, _100$$84, _115$$102, _144$$138;
	zend_bool _1, _11, _15, _40, _41, _43, _20$$15, _25$$15, _36$$18, _74$$39, _66$$40, _60$$46, _61$$49, _63$$51, _68$$54, _69$$57, _71$$59, _91$$62, _85$$68, _86$$71, _88$$73, _93$$76, _94$$79, _96$$81, _130$$84, _123$$102, _118$$103, _120$$109, _125$$112, _127$$118, _152$$138, _147$$139, _149$$145, _154$$148, _156$$154;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_31 = NULL, *_34 = NULL, *_37 = NULL, *_59 = NULL, *_105 = NULL, *_108 = NULL, *_110 = NULL, *_113 = NULL, *_134 = NULL, *_137 = NULL, *_139 = NULL, *_142 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, __$true, __$false, __$null, action, beforeMatch, candidateRoutes, container, controller, converter, converters, currentHostName, eventsManager, handledUri, hostname, matched, matches, matchPosition, module, notFoundPaths, params, paramsStr, part, parts, paths, pattern, position, realUri, regexHostName, request, requestMethod, route, routeFound, routeIdx, routeMeta, staticBeforeMatch, staticBucket, staticBucketMethod, staticHostname, staticHostRegex, staticMatched, staticRoute, strParams, vnamespace, _0, _3, _6, _7, _8, _10, _12, _13, _14, _16, _17, combinedChunks, combinedMarkMaps, combinedChunkIdx, combinedChunk, combinedMatchesLocal, combinedMarkLabel, combinedRouteIdx, combinedRoute, combinedRouteMeta, combinedBeforeMatch, combinedPaths, combinedConverters, combinedPart, combinedPosition, combinedMatchPosition, combinedConverter, _42, _44, _159, _160, _161, _162, _163, _167, _2$$5, _4$$8, _5$$9, _9$$11, _18$$15, _19$$15, _21$$15, _22$$15, _23$$15, _24$$15, _26$$15, _27$$15, _28$$18, _29$$18, *_30$$18, _35$$18, _32$$23, _33$$27, _38$$33, _39$$37, _45$$39, *_46$$39, _73$$39, _49$$40, _50$$40, _51$$40, _52$$40, *_55$$40, _65$$40, _53$$44, _54$$43, _58$$47, _62$$50, _64$$52, _67$$55, _70$$58, _72$$60, _75$$62, _76$$62, _77$$62, _78$$62, *_81$$62, _90$$62, _79$$66, _80$$65, _84$$69, _87$$72, _89$$74, _92$$77, _95$$80, _97$$82, _98$$84, *_99$$84, _129$$84, _102$$85, _103$$85, _104$$85, _106$$89, _107$$92, _109$$96, _111$$98, _112$$100, *_114$$102, _122$$102, _117$$104, _119$$108, _121$$110, _124$$113, _126$$117, _128$$119, _131$$121, _132$$121, _133$$121, _135$$125, _136$$128, _138$$132, _140$$134, _141$$136, *_143$$138, _151$$138, _146$$140, _148$$144, _150$$146, _153$$149, _155$$153, _157$$155, _158$$159, _164$$167, _165$$169, _166$$171, _168$$172, _169$$172, _170$$172, _171$$172;
	zend_string *uri = NULL, *_48$$39, *_57$$40, *_83$$62, *_101$$84, *_116$$102, *_145$$138;
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
	ZVAL_UNDEF(&routeIdx);
	ZVAL_UNDEF(&routeMeta);
	ZVAL_UNDEF(&staticBeforeMatch);
	ZVAL_UNDEF(&staticBucket);
	ZVAL_UNDEF(&staticBucketMethod);
	ZVAL_UNDEF(&staticHostname);
	ZVAL_UNDEF(&staticHostRegex);
	ZVAL_UNDEF(&staticMatched);
	ZVAL_UNDEF(&staticRoute);
	ZVAL_UNDEF(&strParams);
	ZVAL_UNDEF(&vnamespace);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&combinedChunks);
	ZVAL_UNDEF(&combinedMarkMaps);
	ZVAL_UNDEF(&combinedChunkIdx);
	ZVAL_UNDEF(&combinedChunk);
	ZVAL_UNDEF(&combinedMatchesLocal);
	ZVAL_UNDEF(&combinedMarkLabel);
	ZVAL_UNDEF(&combinedRouteIdx);
	ZVAL_UNDEF(&combinedRoute);
	ZVAL_UNDEF(&combinedRouteMeta);
	ZVAL_UNDEF(&combinedBeforeMatch);
	ZVAL_UNDEF(&combinedPaths);
	ZVAL_UNDEF(&combinedConverters);
	ZVAL_UNDEF(&combinedPart);
	ZVAL_UNDEF(&combinedPosition);
	ZVAL_UNDEF(&combinedMatchPosition);
	ZVAL_UNDEF(&combinedConverter);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_44);
	ZVAL_UNDEF(&_159);
	ZVAL_UNDEF(&_160);
	ZVAL_UNDEF(&_161);
	ZVAL_UNDEF(&_162);
	ZVAL_UNDEF(&_163);
	ZVAL_UNDEF(&_167);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_35$$18);
	ZVAL_UNDEF(&_32$$23);
	ZVAL_UNDEF(&_33$$27);
	ZVAL_UNDEF(&_38$$33);
	ZVAL_UNDEF(&_39$$37);
	ZVAL_UNDEF(&_45$$39);
	ZVAL_UNDEF(&_73$$39);
	ZVAL_UNDEF(&_49$$40);
	ZVAL_UNDEF(&_50$$40);
	ZVAL_UNDEF(&_51$$40);
	ZVAL_UNDEF(&_52$$40);
	ZVAL_UNDEF(&_65$$40);
	ZVAL_UNDEF(&_53$$44);
	ZVAL_UNDEF(&_54$$43);
	ZVAL_UNDEF(&_58$$47);
	ZVAL_UNDEF(&_62$$50);
	ZVAL_UNDEF(&_64$$52);
	ZVAL_UNDEF(&_67$$55);
	ZVAL_UNDEF(&_70$$58);
	ZVAL_UNDEF(&_72$$60);
	ZVAL_UNDEF(&_75$$62);
	ZVAL_UNDEF(&_76$$62);
	ZVAL_UNDEF(&_77$$62);
	ZVAL_UNDEF(&_78$$62);
	ZVAL_UNDEF(&_90$$62);
	ZVAL_UNDEF(&_79$$66);
	ZVAL_UNDEF(&_80$$65);
	ZVAL_UNDEF(&_84$$69);
	ZVAL_UNDEF(&_87$$72);
	ZVAL_UNDEF(&_89$$74);
	ZVAL_UNDEF(&_92$$77);
	ZVAL_UNDEF(&_95$$80);
	ZVAL_UNDEF(&_97$$82);
	ZVAL_UNDEF(&_98$$84);
	ZVAL_UNDEF(&_129$$84);
	ZVAL_UNDEF(&_102$$85);
	ZVAL_UNDEF(&_103$$85);
	ZVAL_UNDEF(&_104$$85);
	ZVAL_UNDEF(&_106$$89);
	ZVAL_UNDEF(&_107$$92);
	ZVAL_UNDEF(&_109$$96);
	ZVAL_UNDEF(&_111$$98);
	ZVAL_UNDEF(&_112$$100);
	ZVAL_UNDEF(&_122$$102);
	ZVAL_UNDEF(&_117$$104);
	ZVAL_UNDEF(&_119$$108);
	ZVAL_UNDEF(&_121$$110);
	ZVAL_UNDEF(&_124$$113);
	ZVAL_UNDEF(&_126$$117);
	ZVAL_UNDEF(&_128$$119);
	ZVAL_UNDEF(&_131$$121);
	ZVAL_UNDEF(&_132$$121);
	ZVAL_UNDEF(&_133$$121);
	ZVAL_UNDEF(&_135$$125);
	ZVAL_UNDEF(&_136$$128);
	ZVAL_UNDEF(&_138$$132);
	ZVAL_UNDEF(&_140$$134);
	ZVAL_UNDEF(&_141$$136);
	ZVAL_UNDEF(&_151$$138);
	ZVAL_UNDEF(&_146$$140);
	ZVAL_UNDEF(&_148$$144);
	ZVAL_UNDEF(&_150$$146);
	ZVAL_UNDEF(&_153$$149);
	ZVAL_UNDEF(&_155$$153);
	ZVAL_UNDEF(&_157$$155);
	ZVAL_UNDEF(&_158$$159);
	ZVAL_UNDEF(&_164$$167);
	ZVAL_UNDEF(&_165$$169);
	ZVAL_UNDEF(&_166$$171);
	ZVAL_UNDEF(&_168$$172);
	ZVAL_UNDEF(&_169$$172);
	ZVAL_UNDEF(&_170$$172);
	ZVAL_UNDEF(&_171$$172);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	static zend_string *_zephir_prop_11 = NULL;
	static zend_string *_zephir_prop_12 = NULL;
	static zend_string *_zephir_prop_13 = NULL;
	static zend_string *_zephir_prop_14 = NULL;
	static zend_string *_zephir_prop_15 = NULL;
	static zend_string *_zephir_prop_16 = NULL;
	static zend_string *_zephir_prop_17 = NULL;
	static zend_string *_zephir_prop_18 = NULL;
	static zend_string *_zephir_prop_19 = NULL;
	static zend_string *_zephir_prop_20 = NULL;
	static zend_string *_zephir_prop_21 = NULL;
	static zend_string *_zephir_prop_22 = NULL;
	static zend_string *_zephir_prop_23 = NULL;
	static zend_string *_zephir_prop_24 = NULL;
	static zend_string *_zephir_prop_25 = NULL;
	static zend_string *_zephir_prop_26 = NULL;
	static zend_string *_zephir_prop_27 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("removeExtraSlashes", 18, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("wasMatched", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("matchedRoute", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("methodRoutesDirty", 17, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("candidatesByMethod", 18, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("hostnameByMethod", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("staticByMethod", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("staticShadowedByMethod", 22, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("combinedRegexDisabled", 21, 1);
	}
	if (UNEXPECTED(!_zephir_prop_11)) {
		_zephir_prop_11 = zend_string_init("combinedRegexByMethod", 21, 1);
	}
	if (UNEXPECTED(!_zephir_prop_12)) {
		_zephir_prop_12 = zend_string_init("combinedRegexMarkMap", 20, 1);
	}
	if (UNEXPECTED(!_zephir_prop_13)) {
		_zephir_prop_13 = zend_string_init("routeMeta", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_14)) {
		_zephir_prop_14 = zend_string_init("matches", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_15)) {
		_zephir_prop_15 = zend_string_init("notFoundPaths", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_16)) {
		_zephir_prop_16 = zend_string_init("defaultNamespace", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_17)) {
		_zephir_prop_17 = zend_string_init("namespaceName", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_18)) {
		_zephir_prop_18 = zend_string_init("defaultModule", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_19)) {
		_zephir_prop_19 = zend_string_init("module", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_20)) {
		_zephir_prop_20 = zend_string_init("defaultController", 17, 1);
	}
	if (UNEXPECTED(!_zephir_prop_21)) {
		_zephir_prop_21 = zend_string_init("controller", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_22)) {
		_zephir_prop_22 = zend_string_init("defaultAction", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_23)) {
		_zephir_prop_23 = zend_string_init("action", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_24)) {
		_zephir_prop_24 = zend_string_init("defaultParams", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_25)) {
		_zephir_prop_25 = zend_string_init("params", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_26)) {
		_zephir_prop_26 = zend_string_init("pendingCache", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_27)) {
		_zephir_prop_27 = zend_string_init("pendingCacheKey", 15, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 304, PH_NOISY_CC | PH_READONLY);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 305, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 305, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 306, &__$null);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_3, 307, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_3);
	if (Z_TYPE_P(&eventsManager) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_4$$8);
		ZVAL_STRING(&_4$$8, "router:beforeCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_4$$8, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_4, 308, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_3);
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_5$$9);
		object_init_ex(&_5$$9, phalcon_mvc_router_exceptions_requestserviceunavailable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$9, "__construct", NULL, 268);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$9, "phalcon/Mvc/Router.zep", 1265);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "request");
	ZEPHIR_CALL_METHOD(&_6, &container, "get", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&request, &_6);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_5, 283, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_3)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rebuildmethodindex", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&requestMethod, &request, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&candidateRoutes);
	array_init(&candidateRoutes);
	ZEPHIR_OBS_NVAR(&candidateRoutes);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_6, 285, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&candidateRoutes, &_8, &requestMethod, 0))) {
		ZEPHIR_OBS_NVAR(&candidateRoutes);
		zephir_read_property_cached(&_9$$11, this_ptr, _zephir_prop_6, 285, PH_NOISY_CC | PH_READONLY);
		zephir_array_isset_string_fetch(&candidateRoutes, &_9$$11, SL("*"), 0);
	}
	if (Z_TYPE_P(&candidateRoutes) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&candidateRoutes);
		array_init(&candidateRoutes);
	}
	zephir_read_property_cached(&_10, this_ptr, _zephir_prop_7, 289, PH_NOISY_CC | PH_READONLY);
	_11 = zephir_array_isset_value(&_10, &requestMethod);
	if (_11) {
		zephir_read_property_cached(&_12, this_ptr, _zephir_prop_7, 289, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_13, &_12, &requestMethod, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1297);
		_11 = !(ZEPHIR_IS_EMPTY(&_13));
	}
	if (_11) {
		ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", NULL, 0);
		zephir_check_call_status();
	} else {
		zephir_read_property_cached(&_14, this_ptr, _zephir_prop_7, 289, PH_NOISY_CC | PH_READONLY);
		_15 = zephir_array_isset_value_string(&_14, SL("*"));
		if (_15) {
			zephir_read_property_cached(&_16, this_ptr, _zephir_prop_7, 289, PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_17, &_16, SL("*"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1300);
			_15 = !(ZEPHIR_IS_EMPTY(&_17));
		}
		if (_15) {
			ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", NULL, 0);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_NULL) {
		ZEPHIR_INIT_VAR(&staticBucketMethod);
		ZVAL_NULL(&staticBucketMethod);
		zephir_read_property_cached(&_18$$15, this_ptr, _zephir_prop_8, 287, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_19$$15, &_18$$15, &requestMethod, PH_READONLY, "phalcon/Mvc/Router.zep", 1313);
		_20$$15 = zephir_array_isset_value(&_19$$15, &handledUri);
		if (_20$$15) {
			zephir_read_property_cached(&_21$$15, this_ptr, _zephir_prop_9, 288, PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_22$$15, &_21$$15, &requestMethod, PH_READONLY, "phalcon/Mvc/Router.zep", 1314);
			_20$$15 = !(zephir_array_isset_value(&_22$$15, &handledUri));
		}
		if (_20$$15) {
			ZEPHIR_CPY_WRT(&staticBucketMethod, &requestMethod);
		} else {
			zephir_read_property_cached(&_23$$15, this_ptr, _zephir_prop_8, 287, PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_24$$15, &_23$$15, SL("*"), PH_READONLY, "phalcon/Mvc/Router.zep", 1316);
			_25$$15 = zephir_array_isset_value(&_24$$15, &handledUri);
			if (_25$$15) {
				zephir_read_property_cached(&_26$$15, this_ptr, _zephir_prop_9, 288, PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch_string(&_27$$15, &_26$$15, SL("*"), PH_READONLY, "phalcon/Mvc/Router.zep", 1317);
				_25$$15 = !(zephir_array_isset_value(&_27$$15, &handledUri));
			}
			if (_25$$15) {
				ZEPHIR_INIT_NVAR(&staticBucketMethod);
				ZVAL_STRING(&staticBucketMethod, "*");
			}
		}
		if (Z_TYPE_P(&staticBucketMethod) != IS_NULL) {
			zephir_read_property_cached(&_28$$18, this_ptr, _zephir_prop_8, 287, PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_29$$18, &_28$$18, &staticBucketMethod, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1322);
			zephir_memory_observe(&staticBucket);
			zephir_array_fetch(&staticBucket, &_29$$18, &handledUri, PH_NOISY, "phalcon/Mvc/Router.zep", 1322);
			zephir_is_iterable(&staticBucket, 0, "phalcon/Mvc/Router.zep", 1370);
			if (Z_TYPE_P(&staticBucket) == IS_ARRAY) {
				ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(&staticBucket), _30$$18)
				{
					ZEPHIR_INIT_NVAR(&staticRoute);
					ZVAL_COPY(&staticRoute, _30$$18);
					ZEPHIR_CALL_METHOD(&staticHostname, &staticRoute, "gethostname", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&staticHostname) != IS_NULL) {
						if (Z_TYPE_P(&currentHostName) == IS_NULL) {
							ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", &_31, 0);
							zephir_check_call_status();
						}
						if (!(zephir_is_true(&currentHostName))) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&staticHostRegex, &staticRoute, "getcompiledhostname", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&staticHostRegex) != IS_NULL) {
							ZEPHIR_INIT_NVAR(&_32$$23);
							ZEPHIR_INIT_NVAR(&staticMatched);
							zephir_preg_match(&staticMatched, &staticHostRegex, &currentHostName, &_32$$23, 0, 0 , 0 );
						} else {
							ZEPHIR_INIT_NVAR(&staticMatched);
							ZVAL_BOOL(&staticMatched, ZEPHIR_IS_EQUAL(&currentHostName, &staticHostname));
						}
						if (!(zephir_is_true(&staticMatched))) {
							continue;
						}
					}
					ZEPHIR_CALL_METHOD(&staticBeforeMatch, &staticRoute, "getbeforematch", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&staticBeforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&staticBeforeMatch)))) {
							ZEPHIR_INIT_NVAR(&_33$$27);
							object_init_ex(&_33$$27, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD(NULL, &_33$$27, "__construct", &_34, 269);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_33$$27, "phalcon/Mvc/Router.zep", 1353);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &staticBeforeMatch, NULL, 0, &handledUri, &staticRoute, this_ptr);
						zephir_check_call_status();
						if (!(zephir_is_true(&routeFound))) {
							continue;
						}
					}
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, 1);
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					ZEPHIR_CALL_METHOD(&parts, &staticRoute, "getpaths", NULL, 0);
					zephir_check_call_status();
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 306, &staticRoute);
					break;
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &staticBucket, "rewind", NULL, 0);
				zephir_check_call_status();
				_36$$18 = 1;
				while (1) {
					if (_36$$18) {
						_36$$18 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &staticBucket, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_35$$18, &staticBucket, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_35$$18)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&staticRoute, &staticBucket, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&staticHostname, &staticRoute, "gethostname", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&staticHostname) != IS_NULL) {
							if (Z_TYPE_P(&currentHostName) == IS_NULL) {
								ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", &_37, 0);
								zephir_check_call_status();
							}
							if (!(zephir_is_true(&currentHostName))) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&staticHostRegex, &staticRoute, "getcompiledhostname", NULL, 0);
							zephir_check_call_status();
							if (Z_TYPE_P(&staticHostRegex) != IS_NULL) {
								ZEPHIR_INIT_NVAR(&_38$$33);
								ZEPHIR_INIT_NVAR(&staticMatched);
								zephir_preg_match(&staticMatched, &staticHostRegex, &currentHostName, &_38$$33, 0, 0 , 0 );
							} else {
								ZEPHIR_INIT_NVAR(&staticMatched);
								ZVAL_BOOL(&staticMatched, ZEPHIR_IS_EQUAL(&currentHostName, &staticHostname));
							}
							if (!(zephir_is_true(&staticMatched))) {
								continue;
							}
						}
						ZEPHIR_CALL_METHOD(&staticBeforeMatch, &staticRoute, "getbeforematch", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&staticBeforeMatch) != IS_NULL) {
							if (UNEXPECTED(!(zephir_is_callable(&staticBeforeMatch)))) {
								ZEPHIR_INIT_NVAR(&_39$$37);
								object_init_ex(&_39$$37, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
								ZEPHIR_CALL_METHOD(NULL, &_39$$37, "__construct", &_34, 269);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_39$$37, "phalcon/Mvc/Router.zep", 1353);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &staticBeforeMatch, NULL, 0, &handledUri, &staticRoute, this_ptr);
							zephir_check_call_status();
							if (!(zephir_is_true(&routeFound))) {
								continue;
							}
						}
						ZEPHIR_INIT_NVAR(&routeFound);
						ZVAL_BOOL(&routeFound, 1);
						ZEPHIR_INIT_NVAR(&matches);
						ZVAL_NULL(&matches);
						ZEPHIR_CALL_METHOD(&parts, &staticRoute, "getpaths", NULL, 0);
						zephir_check_call_status();
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 306, &staticRoute);
						break;
				}
			}
			ZEPHIR_INIT_NVAR(&staticRoute);
		}
	}
	_40 = !zephir_is_true(&routeFound);
	if (_40) {
		_40 = Z_TYPE_P(&eventsManager) == IS_NULL;
	}
	_41 = _40;
	if (_41) {
		zephir_read_property_cached(&_42, this_ptr, _zephir_prop_10, 292, PH_NOISY_CC | PH_READONLY);
		_41 = !(zephir_array_isset_value(&_42, &requestMethod));
	}
	_43 = _41;
	if (_43) {
		zephir_memory_observe(&combinedChunks);
		zephir_read_property_cached(&_44, this_ptr, _zephir_prop_11, 291, PH_NOISY_CC | PH_READONLY);
		_43 = zephir_array_isset_fetch(&combinedChunks, &_44, &requestMethod, 0);
	}
	if (_43) {
		zephir_read_property_cached(&_45$$39, this_ptr, _zephir_prop_12, 293, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&combinedMarkMaps);
		zephir_array_fetch(&combinedMarkMaps, &_45$$39, &requestMethod, PH_NOISY, "phalcon/Mvc/Router.zep", 1389);
		zephir_is_iterable(&combinedChunks, 0, "phalcon/Mvc/Router.zep", 1454);
		if (Z_TYPE_P(&combinedChunks) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&combinedChunks), _47$$39, _48$$39, _46$$39)
			{
				ZEPHIR_INIT_NVAR(&combinedChunkIdx);
				if (_48$$39 != NULL) { 
					ZVAL_STR_COPY(&combinedChunkIdx, _48$$39);
				} else {
					ZVAL_LONG(&combinedChunkIdx, _47$$39);
				}
				ZEPHIR_INIT_NVAR(&combinedChunk);
				ZVAL_COPY(&combinedChunk, _46$$39);
				ZEPHIR_INIT_NVAR(&combinedMatchesLocal);
				array_init(&combinedMatchesLocal);
				ZEPHIR_INIT_NVAR(&_49$$40);
				zephir_preg_match(&_49$$40, &combinedChunk, &handledUri, &combinedMatchesLocal, 0, 0 , 0 );
				if (!(zephir_is_true(&_49$$40))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&combinedMarkLabel);
				zephir_array_fetch_string(&combinedMarkLabel, &combinedMatchesLocal, SL("MARK"), PH_NOISY, "phalcon/Mvc/Router.zep", 1398);
				ZEPHIR_OBS_NVAR(&combinedRouteIdx);
				zephir_array_fetch(&_50$$40, &combinedMarkMaps, &combinedChunkIdx, PH_READONLY, "phalcon/Mvc/Router.zep", 1400);
				if (!(zephir_array_isset_fetch(&combinedRouteIdx, &_50$$40, &combinedMarkLabel, 0))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&combinedRoute);
				zephir_array_fetch(&combinedRoute, &candidateRoutes, &combinedRouteIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1404);
				zephir_read_property_cached(&_51$$40, this_ptr, _zephir_prop_13, 286, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&combinedRouteMeta);
				ZEPHIR_CALL_METHOD(&_52$$40, &combinedRoute, "getrouteid", NULL, 0);
				zephir_check_call_status();
				zephir_array_fetch(&combinedRouteMeta, &_51$$40, &_52$$40, PH_NOISY, "phalcon/Mvc/Router.zep", 1405);
				ZEPHIR_OBS_NVAR(&combinedBeforeMatch);
				zephir_array_fetch_string(&combinedBeforeMatch, &combinedRouteMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1407);
				if (Z_TYPE_P(&combinedBeforeMatch) != IS_NULL) {
					if (UNEXPECTED(!(zephir_is_callable(&combinedBeforeMatch)))) {
						ZEPHIR_INIT_NVAR(&_53$$44);
						object_init_ex(&_53$$44, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
						ZEPHIR_CALL_METHOD(NULL, &_53$$44, "__construct", &_34, 269);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_53$$44, "phalcon/Mvc/Router.zep", 1411);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_ZVAL_FUNCTION(&_54$$43, &combinedBeforeMatch, NULL, 0, &handledUri, &combinedRoute, this_ptr);
					zephir_check_call_status();
					if (!(zephir_is_true(&_54$$43))) {
						continue;
					}
				}
				ZEPHIR_CALL_METHOD(&combinedPaths, &combinedRoute, "getpaths", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&parts, &combinedPaths);
				ZEPHIR_CPY_WRT(&matches, &combinedMatchesLocal);
				ZEPHIR_CALL_METHOD(&combinedConverters, &combinedRoute, "getconverters", NULL, 0);
				zephir_check_call_status();
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_14, 309, &combinedMatchesLocal);
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 306, &combinedRoute);
				ZEPHIR_INIT_NVAR(&routeFound);
				ZVAL_BOOL(&routeFound, 1);
				zephir_is_iterable(&combinedPaths, 0, "phalcon/Mvc/Router.zep", 1452);
				if (Z_TYPE_P(&combinedPaths) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&combinedPaths), _56$$40, _57$$40, _55$$40)
					{
						ZEPHIR_INIT_NVAR(&combinedPart);
						if (_57$$40 != NULL) { 
							ZVAL_STR_COPY(&combinedPart, _57$$40);
						} else {
							ZVAL_LONG(&combinedPart, _56$$40);
						}
						ZEPHIR_INIT_NVAR(&combinedPosition);
						ZVAL_COPY(&combinedPosition, _55$$40);
						if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
							ZEPHIR_INIT_NVAR(&_58$$47);
							object_init_ex(&_58$$47, phalcon_mvc_router_exceptions_wrongpathskey_ce);
							ZEPHIR_CALL_METHOD(NULL, &_58$$47, "__construct", &_59, 270, &combinedPart);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_58$$47, "phalcon/Mvc/Router.zep", 1429);
							ZEPHIR_MM_RESTORE();
							return;
						}
						_60$$46 = Z_TYPE_P(&combinedPosition) != IS_STRING;
						if (_60$$46) {
							_60$$46 = Z_TYPE_P(&combinedPosition) != IS_LONG;
						}
						if (_60$$46) {
							continue;
						}
						ZEPHIR_OBS_NVAR(&combinedMatchPosition);
						if (zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0)) {
							_61$$49 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
							if (_61$$49) {
								ZEPHIR_OBS_NVAR(&combinedConverter);
								_61$$49 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
							}
							if (_61$$49) {
								ZEPHIR_CALL_ZVAL_FUNCTION(&_62$$50, &combinedConverter, NULL, 0, &combinedMatchPosition);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, &combinedPart, &_62$$50, PH_COPY | PH_SEPARATE);
								continue;
							}
							zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
						} else {
							_63$$51 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
							if (_63$$51) {
								ZEPHIR_OBS_NVAR(&combinedConverter);
								_63$$51 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
							}
							if (_63$$51) {
								ZEPHIR_CALL_ZVAL_FUNCTION(&_64$$52, &combinedConverter, NULL, 0, &combinedPosition);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, &combinedPart, &_64$$52, PH_COPY | PH_SEPARATE);
							} else if (Z_TYPE_P(&combinedPosition) == IS_LONG) {
								zephir_array_unset(&parts, &combinedPart, PH_SEPARATE);
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &combinedPaths, "rewind", NULL, 0);
					zephir_check_call_status();
					_66$$40 = 1;
					while (1) {
						if (_66$$40) {
							_66$$40 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &combinedPaths, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_65$$40, &combinedPaths, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_65$$40)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&combinedPart, &combinedPaths, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&combinedPosition, &combinedPaths, "current", NULL, 0);
						zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
								ZEPHIR_INIT_NVAR(&_67$$55);
								object_init_ex(&_67$$55, phalcon_mvc_router_exceptions_wrongpathskey_ce);
								ZEPHIR_CALL_METHOD(NULL, &_67$$55, "__construct", &_59, 270, &combinedPart);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_67$$55, "phalcon/Mvc/Router.zep", 1429);
								ZEPHIR_MM_RESTORE();
								return;
							}
							_68$$54 = Z_TYPE_P(&combinedPosition) != IS_STRING;
							if (_68$$54) {
								_68$$54 = Z_TYPE_P(&combinedPosition) != IS_LONG;
							}
							if (_68$$54) {
								continue;
							}
							ZEPHIR_OBS_NVAR(&combinedMatchPosition);
							if (zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0)) {
								_69$$57 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_69$$57) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_69$$57 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								}
								if (_69$$57) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_70$$58, &combinedConverter, NULL, 0, &combinedMatchPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_70$$58, PH_COPY | PH_SEPARATE);
									continue;
								}
								zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
							} else {
								_71$$59 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_71$$59) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_71$$59 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								}
								if (_71$$59) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_72$$60, &combinedConverter, NULL, 0, &combinedPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_72$$60, PH_COPY | PH_SEPARATE);
								} else if (Z_TYPE_P(&combinedPosition) == IS_LONG) {
									zephir_array_unset(&parts, &combinedPart, PH_SEPARATE);
								}
							}
					}
				}
				ZEPHIR_INIT_NVAR(&combinedPosition);
				ZEPHIR_INIT_NVAR(&combinedPart);
				break;
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &combinedChunks, "rewind", NULL, 0);
			zephir_check_call_status();
			_74$$39 = 1;
			while (1) {
				if (_74$$39) {
					_74$$39 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &combinedChunks, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_73$$39, &combinedChunks, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_73$$39)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&combinedChunkIdx, &combinedChunks, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&combinedChunk, &combinedChunks, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&combinedMatchesLocal);
					array_init(&combinedMatchesLocal);
					ZEPHIR_INIT_NVAR(&_75$$62);
					zephir_preg_match(&_75$$62, &combinedChunk, &handledUri, &combinedMatchesLocal, 0, 0 , 0 );
					if (!(zephir_is_true(&_75$$62))) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&combinedMarkLabel);
					zephir_array_fetch_string(&combinedMarkLabel, &combinedMatchesLocal, SL("MARK"), PH_NOISY, "phalcon/Mvc/Router.zep", 1398);
					ZEPHIR_OBS_NVAR(&combinedRouteIdx);
					zephir_array_fetch(&_76$$62, &combinedMarkMaps, &combinedChunkIdx, PH_READONLY, "phalcon/Mvc/Router.zep", 1400);
					if (!(zephir_array_isset_fetch(&combinedRouteIdx, &_76$$62, &combinedMarkLabel, 0))) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&combinedRoute);
					zephir_array_fetch(&combinedRoute, &candidateRoutes, &combinedRouteIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1404);
					zephir_read_property_cached(&_77$$62, this_ptr, _zephir_prop_13, 286, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&combinedRouteMeta);
					ZEPHIR_CALL_METHOD(&_78$$62, &combinedRoute, "getrouteid", NULL, 0);
					zephir_check_call_status();
					zephir_array_fetch(&combinedRouteMeta, &_77$$62, &_78$$62, PH_NOISY, "phalcon/Mvc/Router.zep", 1405);
					ZEPHIR_OBS_NVAR(&combinedBeforeMatch);
					zephir_array_fetch_string(&combinedBeforeMatch, &combinedRouteMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1407);
					if (Z_TYPE_P(&combinedBeforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&combinedBeforeMatch)))) {
							ZEPHIR_INIT_NVAR(&_79$$66);
							object_init_ex(&_79$$66, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD(NULL, &_79$$66, "__construct", &_34, 269);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_79$$66, "phalcon/Mvc/Router.zep", 1411);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_ZVAL_FUNCTION(&_80$$65, &combinedBeforeMatch, NULL, 0, &handledUri, &combinedRoute, this_ptr);
						zephir_check_call_status();
						if (!(zephir_is_true(&_80$$65))) {
							continue;
						}
					}
					ZEPHIR_CALL_METHOD(&combinedPaths, &combinedRoute, "getpaths", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&parts, &combinedPaths);
					ZEPHIR_CPY_WRT(&matches, &combinedMatchesLocal);
					ZEPHIR_CALL_METHOD(&combinedConverters, &combinedRoute, "getconverters", NULL, 0);
					zephir_check_call_status();
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_14, 309, &combinedMatchesLocal);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 306, &combinedRoute);
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, 1);
					zephir_is_iterable(&combinedPaths, 0, "phalcon/Mvc/Router.zep", 1452);
					if (Z_TYPE_P(&combinedPaths) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&combinedPaths), _82$$62, _83$$62, _81$$62)
						{
							ZEPHIR_INIT_NVAR(&combinedPart);
							if (_83$$62 != NULL) { 
								ZVAL_STR_COPY(&combinedPart, _83$$62);
							} else {
								ZVAL_LONG(&combinedPart, _82$$62);
							}
							ZEPHIR_INIT_NVAR(&combinedPosition);
							ZVAL_COPY(&combinedPosition, _81$$62);
							if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
								ZEPHIR_INIT_NVAR(&_84$$69);
								object_init_ex(&_84$$69, phalcon_mvc_router_exceptions_wrongpathskey_ce);
								ZEPHIR_CALL_METHOD(NULL, &_84$$69, "__construct", &_59, 270, &combinedPart);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_84$$69, "phalcon/Mvc/Router.zep", 1429);
								ZEPHIR_MM_RESTORE();
								return;
							}
							_85$$68 = Z_TYPE_P(&combinedPosition) != IS_STRING;
							if (_85$$68) {
								_85$$68 = Z_TYPE_P(&combinedPosition) != IS_LONG;
							}
							if (_85$$68) {
								continue;
							}
							ZEPHIR_OBS_NVAR(&combinedMatchPosition);
							if (zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0)) {
								_86$$71 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_86$$71) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_86$$71 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								}
								if (_86$$71) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_87$$72, &combinedConverter, NULL, 0, &combinedMatchPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_87$$72, PH_COPY | PH_SEPARATE);
									continue;
								}
								zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
							} else {
								_88$$73 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_88$$73) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_88$$73 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								}
								if (_88$$73) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_89$$74, &combinedConverter, NULL, 0, &combinedPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_89$$74, PH_COPY | PH_SEPARATE);
								} else if (Z_TYPE_P(&combinedPosition) == IS_LONG) {
									zephir_array_unset(&parts, &combinedPart, PH_SEPARATE);
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &combinedPaths, "rewind", NULL, 0);
						zephir_check_call_status();
						_91$$62 = 1;
						while (1) {
							if (_91$$62) {
								_91$$62 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &combinedPaths, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_90$$62, &combinedPaths, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_90$$62)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&combinedPart, &combinedPaths, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&combinedPosition, &combinedPaths, "current", NULL, 0);
							zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
									ZEPHIR_INIT_NVAR(&_92$$77);
									object_init_ex(&_92$$77, phalcon_mvc_router_exceptions_wrongpathskey_ce);
									ZEPHIR_CALL_METHOD(NULL, &_92$$77, "__construct", &_59, 270, &combinedPart);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_92$$77, "phalcon/Mvc/Router.zep", 1429);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_93$$76 = Z_TYPE_P(&combinedPosition) != IS_STRING;
								if (_93$$76) {
									_93$$76 = Z_TYPE_P(&combinedPosition) != IS_LONG;
								}
								if (_93$$76) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&combinedMatchPosition);
								if (zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0)) {
									_94$$79 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
									if (_94$$79) {
										ZEPHIR_OBS_NVAR(&combinedConverter);
										_94$$79 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
									}
									if (_94$$79) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_95$$80, &combinedConverter, NULL, 0, &combinedMatchPosition);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &combinedPart, &_95$$80, PH_COPY | PH_SEPARATE);
										continue;
									}
									zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
								} else {
									_96$$81 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
									if (_96$$81) {
										ZEPHIR_OBS_NVAR(&combinedConverter);
										_96$$81 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
									}
									if (_96$$81) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_97$$82, &combinedConverter, NULL, 0, &combinedPosition);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &combinedPart, &_97$$82, PH_COPY | PH_SEPARATE);
									} else if (Z_TYPE_P(&combinedPosition) == IS_LONG) {
										zephir_array_unset(&parts, &combinedPart, PH_SEPARATE);
									}
								}
						}
					}
					ZEPHIR_INIT_NVAR(&combinedPosition);
					ZEPHIR_INIT_NVAR(&combinedPart);
					break;
			}
		}
		ZEPHIR_INIT_NVAR(&combinedChunk);
		ZEPHIR_INIT_NVAR(&combinedChunkIdx);
	}
	if (!(zephir_is_true(&routeFound))) {
		ZEPHIR_CALL_FUNCTION(&_98$$84, "array_reverse", NULL, 271, &candidateRoutes, &__$true);
		zephir_check_call_status();
		zephir_is_iterable(&_98$$84, 0, "phalcon/Mvc/Router.zep", 1614);
		if (Z_TYPE_P(&_98$$84) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_98$$84), _100$$84, _101$$84, _99$$84)
			{
				ZEPHIR_INIT_NVAR(&routeIdx);
				if (_101$$84 != NULL) { 
					ZVAL_STR_COPY(&routeIdx, _101$$84);
				} else {
					ZVAL_LONG(&routeIdx, _100$$84);
				}
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _99$$84);
				zephir_read_property_cached(&_102$$85, this_ptr, _zephir_prop_13, 286, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_104$$85, &route, "getrouteid", NULL, 0);
				zephir_check_call_status();
				zephir_array_fetch(&_103$$85, &_102$$85, &_104$$85, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1462);
				ZEPHIR_CPY_WRT(&routeMeta, &_103$$85);
				ZEPHIR_INIT_NVAR(&params);
				array_init(&params);
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				ZEPHIR_OBS_NVAR(&hostname);
				zephir_array_fetch_string(&hostname, &routeMeta, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1469);
				if (Z_TYPE_P(&hostname) != IS_NULL) {
					if (Z_TYPE_P(&currentHostName) == IS_NULL) {
						ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", &_105, 0);
						zephir_check_call_status();
					}
					if (!(zephir_is_true(&currentHostName))) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&regexHostName);
					zephir_array_fetch_string(&regexHostName, &routeMeta, SL("hostRegex"), PH_NOISY, "phalcon/Mvc/Router.zep", 1489);
					if (Z_TYPE_P(&regexHostName) != IS_NULL) {
						ZEPHIR_INIT_NVAR(&_106$$89);
						ZEPHIR_INIT_NVAR(&matched);
						zephir_preg_match(&matched, &regexHostName, &currentHostName, &_106$$89, 0, 0 , 0 );
					} else {
						ZEPHIR_INIT_NVAR(&matched);
						ZVAL_BOOL(&matched, ZEPHIR_IS_EQUAL(&currentHostName, &hostname));
					}
					if (!(zephir_is_true(&matched))) {
						continue;
					}
				}
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_107$$92);
					ZVAL_STRING(&_107$$92, "router:beforeCheckRoute");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_108, 0, &_107$$92, this_ptr, &route);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&pattern);
				zephir_array_fetch_string(&pattern, &routeMeta, SL("pattern"), PH_NOISY, "phalcon/Mvc/Router.zep", 1509);
				zephir_array_fetch_string(&_103$$85, &routeMeta, SL("isRegex"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1511);
				if (zephir_is_true(&_103$$85)) {
					ZEPHIR_INIT_NVAR(&routeFound);
					zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
				} else {
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, &handledUri));
				}
				if (zephir_is_true(&routeFound)) {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_109$$96);
						ZVAL_STRING(&_109$$96, "router:matchedRoute");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_110, 0, &_109$$96, this_ptr, &route);
						zephir_check_call_status();
					}
					ZEPHIR_OBS_NVAR(&beforeMatch);
					zephir_array_fetch_string(&beforeMatch, &routeMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1525);
					if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
							ZEPHIR_INIT_NVAR(&_111$$98);
							object_init_ex(&_111$$98, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD(NULL, &_111$$98, "__construct", &_34, 269);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_111$$98, "phalcon/Mvc/Router.zep", 1531);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &beforeMatch, NULL, 0, &handledUri, &route, this_ptr);
						zephir_check_call_status();
					}
				} else {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_112$$100);
						ZVAL_STRING(&_112$$100, "router:notMatchedRoute");
						ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_113, 0, &_112$$100, this_ptr, &route);
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
						zephir_is_iterable(&paths, 0, "phalcon/Mvc/Router.zep", 1606);
						if (Z_TYPE_P(&paths) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _115$$102, _116$$102, _114$$102)
							{
								ZEPHIR_INIT_NVAR(&part);
								if (_116$$102 != NULL) { 
									ZVAL_STR_COPY(&part, _116$$102);
								} else {
									ZVAL_LONG(&part, _115$$102);
								}
								ZEPHIR_INIT_NVAR(&position);
								ZVAL_COPY(&position, _114$$102);
								if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
									ZEPHIR_INIT_NVAR(&_117$$104);
									object_init_ex(&_117$$104, phalcon_mvc_router_exceptions_wrongpathskey_ce);
									ZEPHIR_CALL_METHOD(NULL, &_117$$104, "__construct", &_59, 270, &part);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_117$$104, "phalcon/Mvc/Router.zep", 1564);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_118$$103 = Z_TYPE_P(&position) != IS_STRING;
								if (_118$$103) {
									_118$$103 = Z_TYPE_P(&position) != IS_LONG;
								}
								if (_118$$103) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&matchPosition);
								if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_119$$108, &converter, NULL, 0, &matchPosition);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_119$$108, PH_COPY | PH_SEPARATE);
											continue;
										}
									}
									zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
								} else {
									_120$$109 = Z_TYPE_P(&converters) == IS_ARRAY;
									if (_120$$109) {
										ZEPHIR_OBS_NVAR(&converter);
										_120$$109 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
									}
									if (_120$$109) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_121$$110, &converter, NULL, 0, &position);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_121$$110, PH_COPY | PH_SEPARATE);
									} else if (Z_TYPE_P(&position) == IS_LONG) {
										zephir_array_unset(&parts, &part, PH_SEPARATE);
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
							zephir_check_call_status();
							_123$$102 = 1;
							while (1) {
								if (_123$$102) {
									_123$$102 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &paths, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_122$$102, &paths, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_122$$102)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&part, &paths, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&position, &paths, "current", NULL, 0);
								zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
										ZEPHIR_INIT_NVAR(&_124$$113);
										object_init_ex(&_124$$113, phalcon_mvc_router_exceptions_wrongpathskey_ce);
										ZEPHIR_CALL_METHOD(NULL, &_124$$113, "__construct", &_59, 270, &part);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_124$$113, "phalcon/Mvc/Router.zep", 1564);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_125$$112 = Z_TYPE_P(&position) != IS_STRING;
									if (_125$$112) {
										_125$$112 = Z_TYPE_P(&position) != IS_LONG;
									}
									if (_125$$112) {
										continue;
									}
									ZEPHIR_OBS_NVAR(&matchPosition);
									if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_126$$117, &converter, NULL, 0, &matchPosition);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_126$$117, PH_COPY | PH_SEPARATE);
												continue;
											}
										}
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
									} else {
										_127$$118 = Z_TYPE_P(&converters) == IS_ARRAY;
										if (_127$$118) {
											ZEPHIR_OBS_NVAR(&converter);
											_127$$118 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										}
										if (_127$$118) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_128$$119, &converter, NULL, 0, &position);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_128$$119, PH_COPY | PH_SEPARATE);
										} else if (Z_TYPE_P(&position) == IS_LONG) {
											zephir_array_unset(&parts, &part, PH_SEPARATE);
										}
									}
							}
						}
						ZEPHIR_INIT_NVAR(&position);
						ZEPHIR_INIT_NVAR(&part);
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_14, 309, &matches);
					}
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 306, &route);
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_98$$84, "rewind", NULL, 0);
			zephir_check_call_status();
			_130$$84 = 1;
			while (1) {
				if (_130$$84) {
					_130$$84 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_98$$84, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_129$$84, &_98$$84, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_129$$84)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&routeIdx, &_98$$84, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&route, &_98$$84, "current", NULL, 0);
				zephir_check_call_status();
					zephir_read_property_cached(&_131$$121, this_ptr, _zephir_prop_13, 286, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_133$$121, &route, "getrouteid", NULL, 0);
					zephir_check_call_status();
					zephir_array_fetch(&_132$$121, &_131$$121, &_133$$121, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1462);
					ZEPHIR_CPY_WRT(&routeMeta, &_132$$121);
					ZEPHIR_INIT_NVAR(&params);
					array_init(&params);
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					ZEPHIR_OBS_NVAR(&hostname);
					zephir_array_fetch_string(&hostname, &routeMeta, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1469);
					if (Z_TYPE_P(&hostname) != IS_NULL) {
						if (Z_TYPE_P(&currentHostName) == IS_NULL) {
							ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", &_134, 0);
							zephir_check_call_status();
						}
						if (!(zephir_is_true(&currentHostName))) {
							continue;
						}
						ZEPHIR_OBS_NVAR(&regexHostName);
						zephir_array_fetch_string(&regexHostName, &routeMeta, SL("hostRegex"), PH_NOISY, "phalcon/Mvc/Router.zep", 1489);
						if (Z_TYPE_P(&regexHostName) != IS_NULL) {
							ZEPHIR_INIT_NVAR(&_135$$125);
							ZEPHIR_INIT_NVAR(&matched);
							zephir_preg_match(&matched, &regexHostName, &currentHostName, &_135$$125, 0, 0 , 0 );
						} else {
							ZEPHIR_INIT_NVAR(&matched);
							ZVAL_BOOL(&matched, ZEPHIR_IS_EQUAL(&currentHostName, &hostname));
						}
						if (!(zephir_is_true(&matched))) {
							continue;
						}
					}
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_136$$128);
						ZVAL_STRING(&_136$$128, "router:beforeCheckRoute");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_137, 0, &_136$$128, this_ptr, &route);
						zephir_check_call_status();
					}
					ZEPHIR_OBS_NVAR(&pattern);
					zephir_array_fetch_string(&pattern, &routeMeta, SL("pattern"), PH_NOISY, "phalcon/Mvc/Router.zep", 1509);
					zephir_array_fetch_string(&_132$$121, &routeMeta, SL("isRegex"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1511);
					if (zephir_is_true(&_132$$121)) {
						ZEPHIR_INIT_NVAR(&routeFound);
						zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
					} else {
						ZEPHIR_INIT_NVAR(&routeFound);
						ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, &handledUri));
					}
					if (zephir_is_true(&routeFound)) {
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_138$$132);
							ZVAL_STRING(&_138$$132, "router:matchedRoute");
							ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_139, 0, &_138$$132, this_ptr, &route);
							zephir_check_call_status();
						}
						ZEPHIR_OBS_NVAR(&beforeMatch);
						zephir_array_fetch_string(&beforeMatch, &routeMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1525);
						if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
							if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
								ZEPHIR_INIT_NVAR(&_140$$134);
								object_init_ex(&_140$$134, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
								ZEPHIR_CALL_METHOD(NULL, &_140$$134, "__construct", &_34, 269);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_140$$134, "phalcon/Mvc/Router.zep", 1531);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &beforeMatch, NULL, 0, &handledUri, &route, this_ptr);
							zephir_check_call_status();
						}
					} else {
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_141$$136);
							ZVAL_STRING(&_141$$136, "router:notMatchedRoute");
							ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_142, 0, &_141$$136, this_ptr, &route);
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
							zephir_is_iterable(&paths, 0, "phalcon/Mvc/Router.zep", 1606);
							if (Z_TYPE_P(&paths) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _144$$138, _145$$138, _143$$138)
								{
									ZEPHIR_INIT_NVAR(&part);
									if (_145$$138 != NULL) { 
										ZVAL_STR_COPY(&part, _145$$138);
									} else {
										ZVAL_LONG(&part, _144$$138);
									}
									ZEPHIR_INIT_NVAR(&position);
									ZVAL_COPY(&position, _143$$138);
									if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
										ZEPHIR_INIT_NVAR(&_146$$140);
										object_init_ex(&_146$$140, phalcon_mvc_router_exceptions_wrongpathskey_ce);
										ZEPHIR_CALL_METHOD(NULL, &_146$$140, "__construct", &_59, 270, &part);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_146$$140, "phalcon/Mvc/Router.zep", 1564);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_147$$139 = Z_TYPE_P(&position) != IS_STRING;
									if (_147$$139) {
										_147$$139 = Z_TYPE_P(&position) != IS_LONG;
									}
									if (_147$$139) {
										continue;
									}
									ZEPHIR_OBS_NVAR(&matchPosition);
									if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_148$$144, &converter, NULL, 0, &matchPosition);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_148$$144, PH_COPY | PH_SEPARATE);
												continue;
											}
										}
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
									} else {
										_149$$145 = Z_TYPE_P(&converters) == IS_ARRAY;
										if (_149$$145) {
											ZEPHIR_OBS_NVAR(&converter);
											_149$$145 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										}
										if (_149$$145) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_150$$146, &converter, NULL, 0, &position);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_150$$146, PH_COPY | PH_SEPARATE);
										} else if (Z_TYPE_P(&position) == IS_LONG) {
											zephir_array_unset(&parts, &part, PH_SEPARATE);
										}
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
								zephir_check_call_status();
								_152$$138 = 1;
								while (1) {
									if (_152$$138) {
										_152$$138 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, &paths, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_151$$138, &paths, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_151$$138)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&part, &paths, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&position, &paths, "current", NULL, 0);
									zephir_check_call_status();
										if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
											ZEPHIR_INIT_NVAR(&_153$$149);
											object_init_ex(&_153$$149, phalcon_mvc_router_exceptions_wrongpathskey_ce);
											ZEPHIR_CALL_METHOD(NULL, &_153$$149, "__construct", &_59, 270, &part);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_153$$149, "phalcon/Mvc/Router.zep", 1564);
											ZEPHIR_MM_RESTORE();
											return;
										}
										_154$$148 = Z_TYPE_P(&position) != IS_STRING;
										if (_154$$148) {
											_154$$148 = Z_TYPE_P(&position) != IS_LONG;
										}
										if (_154$$148) {
											continue;
										}
										ZEPHIR_OBS_NVAR(&matchPosition);
										if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
											if (Z_TYPE_P(&converters) == IS_ARRAY) {
												ZEPHIR_OBS_NVAR(&converter);
												if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
													ZEPHIR_CALL_ZVAL_FUNCTION(&_155$$153, &converter, NULL, 0, &matchPosition);
													zephir_check_call_status();
													zephir_array_update_zval(&parts, &part, &_155$$153, PH_COPY | PH_SEPARATE);
													continue;
												}
											}
											zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
										} else {
											_156$$154 = Z_TYPE_P(&converters) == IS_ARRAY;
											if (_156$$154) {
												ZEPHIR_OBS_NVAR(&converter);
												_156$$154 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
											}
											if (_156$$154) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_157$$155, &converter, NULL, 0, &position);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_157$$155, PH_COPY | PH_SEPARATE);
											} else if (Z_TYPE_P(&position) == IS_LONG) {
												zephir_array_unset(&parts, &part, PH_SEPARATE);
											}
										}
								}
							}
							ZEPHIR_INIT_NVAR(&position);
							ZEPHIR_INIT_NVAR(&part);
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_14, 309, &matches);
						}
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 306, &route);
						break;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&route);
		ZEPHIR_INIT_NVAR(&routeIdx);
	}
	if (zephir_is_true(&routeFound)) {
		if (1) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 305, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 305, &__$false);
		}
	} else {
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 305, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 305, &__$false);
		}
	}
	if (!(zephir_is_true(&routeFound))) {
		zephir_read_property_cached(&_158$$159, this_ptr, _zephir_prop_15, 310, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&notFoundPaths, &_158$$159);
		if (Z_TYPE_P(&notFoundPaths) != IS_NULL) {
			ZEPHIR_CALL_CE_STATIC(&parts, phalcon_mvc_router_route_ce, "getroutepaths", NULL, 0, &notFoundPaths);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&routeFound);
			ZVAL_BOOL(&routeFound, 1);
		}
	}
	zephir_read_property_cached(&_159, this_ptr, _zephir_prop_16, 298, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_17, 311, &_159);
	zephir_read_property_cached(&_160, this_ptr, _zephir_prop_18, 299, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_19, 312, &_160);
	zephir_read_property_cached(&_161, this_ptr, _zephir_prop_20, 300, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_21, 313, &_161);
	zephir_read_property_cached(&_162, this_ptr, _zephir_prop_22, 301, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_23, 314, &_162);
	zephir_read_property_cached(&_163, this_ptr, _zephir_prop_24, 302, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_25, 315, &_163);
	if (zephir_is_true(&routeFound)) {
		zephir_memory_observe(&vnamespace);
		if (zephir_array_isset_string_fetch(&vnamespace, &parts, SL("namespace"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_17, 311, &vnamespace);
			zephir_array_unset_string(&parts, SL("namespace"), PH_SEPARATE);
		}
		zephir_memory_observe(&module);
		if (zephir_array_isset_string_fetch(&module, &parts, SL("module"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_19, 312, &module);
			zephir_array_unset_string(&parts, SL("module"), PH_SEPARATE);
		}
		zephir_memory_observe(&controller);
		if (zephir_array_isset_string_fetch(&controller, &parts, SL("controller"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_21, 313, &controller);
			zephir_array_unset_string(&parts, SL("controller"), PH_SEPARATE);
		}
		zephir_memory_observe(&action);
		if (zephir_array_isset_string_fetch(&action, &parts, SL("action"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_23, 314, &action);
			zephir_array_unset_string(&parts, SL("action"), PH_SEPARATE);
		}
		zephir_memory_observe(&paramsStr);
		if (zephir_array_isset_string_fetch(&paramsStr, &parts, SL("params"), 0)) {
			if (Z_TYPE_P(&paramsStr) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_164$$167);
				ZVAL_STRING(&_164$$167, "/");
				ZEPHIR_INIT_VAR(&strParams);
				zephir_fast_trim(&strParams, &paramsStr, &_164$$167, ZEPHIR_TRIM_BOTH);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&strParams, "")) {
					ZEPHIR_INIT_NVAR(&params);
					zephir_fast_explode_str(&params, SL("/"), &strParams, LONG_MAX);
				}
			}
			zephir_array_unset_string(&parts, SL("params"), PH_SEPARATE);
		}
		if (!(ZEPHIR_IS_EMPTY(&params))) {
			ZEPHIR_INIT_VAR(&_165$$169);
			zephir_fast_array_merge(&_165$$169, &params, &parts);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_25, 315, &_165$$169);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_25, 315, &parts);
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_166$$171);
		ZVAL_STRING(&_166$$171, "router:afterCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_166$$171, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_167, this_ptr, _zephir_prop_26, 296, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_167) != IS_NULL) {
		zephir_read_property_cached(&_168$$172, this_ptr, _zephir_prop_26, 296, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_169$$172, this_ptr, _zephir_prop_27, 297, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_170$$172, this_ptr, "builddispatcherdump", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_168$$172, "set", NULL, 0, &_169$$172, &_170$$172);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_26, 296, &__$null);
		ZEPHIR_INIT_VAR(&_171$$172);
		ZEPHIR_INIT_NVAR(&_171$$172);
		ZVAL_STRING(&_171$$172, "");
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_27, 297, &_171$$172);
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
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Router, loadFromConfig)
{
	zend_bool _7$$9, _11$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, routes, routeData, defaults, notFoundPaths, removeExtra, groups, groupData, _0$$4, _1$$3, _2$$5, _3$$6, *_4$$9, _6$$9, *_8$$13, _10$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&routeData);
	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&notFoundPaths);
	ZVAL_UNDEF(&removeExtra);
	ZVAL_UNDEF(&groups);
	ZVAL_UNDEF(&groupData);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_10$$13);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_SEPARATE_PARAM(config);
	if (Z_TYPE_P(config) == IS_OBJECT) {
		if (!(zephir_instance_of_ev(config, phalcon_config_configinterface_ce))) {
			ZEPHIR_INIT_VAR(&_0$$4);
			object_init_ex(&_0$$4, phalcon_mvc_router_exceptions_invalidconfigsource_ce);
			ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 272);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/Router.zep", 1751);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_1$$3, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_1$$3);
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, phalcon_mvc_router_exceptions_invalidconfigsource_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 272);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Router.zep", 1757);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_array_isset_value_string(config, SL("removeExtraSlashes"))) {
		zephir_memory_observe(&removeExtra);
		zephir_array_fetch_string(&removeExtra, config, SL("removeExtraSlashes"), PH_NOISY, "phalcon/Mvc/Router.zep", 1761);
		ZVAL_BOOL(&_3$$6, zephir_get_boolval(&removeExtra));
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "removeextraslashes", NULL, 0, &_3$$6);
		zephir_check_call_status();
	}
	if (zephir_array_isset_value_string(config, SL("defaults"))) {
		zephir_memory_observe(&defaults);
		zephir_array_fetch_string(&defaults, config, SL("defaults"), PH_NOISY, "phalcon/Mvc/Router.zep", 1766);
		if (Z_TYPE_P(&defaults) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_configkeymustbearray_ce, "defaults", "phalcon/Mvc/Router.zep", 1768);
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaults", NULL, 0, &defaults);
		zephir_check_call_status();
	}
	zephir_memory_observe(&routes);
	if (zephir_array_isset_string_fetch(&routes, config, SL("routes"), 0)) {
		if (Z_TYPE_P(&routes) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_configkeymustbearray_ce, "routes", "phalcon/Mvc/Router.zep", 1775);
			return;
		}
		zephir_is_iterable(&routes, 0, "phalcon/Mvc/Router.zep", 1780);
		if (Z_TYPE_P(&routes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&routes), _4$$9)
			{
				ZEPHIR_INIT_NVAR(&routeData);
				ZVAL_COPY(&routeData, _4$$9);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addroutefromconfig", &_5, 0, &routeData);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &routes, "rewind", NULL, 0);
			zephir_check_call_status();
			_7$$9 = 1;
			while (1) {
				if (_7$$9) {
					_7$$9 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &routes, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_6$$9, &routes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&routeData, &routes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "addroutefromconfig", &_5, 0, &routeData);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&routeData);
	}
	zephir_memory_observe(&groups);
	if (zephir_array_isset_string_fetch(&groups, config, SL("groups"), 0)) {
		if (Z_TYPE_P(&groups) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_configkeymustbearray_ce, "groups", "phalcon/Mvc/Router.zep", 1784);
			return;
		}
		zephir_is_iterable(&groups, 0, "phalcon/Mvc/Router.zep", 1789);
		if (Z_TYPE_P(&groups) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groups), _8$$13)
			{
				ZEPHIR_INIT_NVAR(&groupData);
				ZVAL_COPY(&groupData, _8$$13);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "mountgroupfromconfig", &_9, 0, &groupData);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &groups, "rewind", NULL, 0);
			zephir_check_call_status();
			_11$$13 = 1;
			while (1) {
				if (_11$$13) {
					_11$$13 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &groups, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_10$$13, &groups, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$13)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&groupData, &groups, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "mountgroupfromconfig", &_9, 0, &groupData);
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
 * Mounts a group of routes in the router
 *
 * @param GroupInterface group
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Router, mount)
{
	zend_bool _12, _5$$5, _8$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group, group_sub, groupRoutes, beforeMatch, hostname, route, eventsManager, _0, *_9, _11, _1$$3, _2$$4, *_3$$5, _4$$5, *_6$$8, _7$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&groupRoutes);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&hostname);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$8);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(group, zephir_get_internal_ce(SL("phalcon\\mvc\\router\\groupinterface")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &group);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 307, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "router:beforeMount");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_1$$3, this_ptr, group);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&groupRoutes, group, "getroutes", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&groupRoutes))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_router_exceptions_emptygroupofroutes_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 273);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Router.zep", 1818);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&beforeMatch, group, "getbeforematch", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
		zephir_is_iterable(&groupRoutes, 0, "phalcon/Mvc/Router.zep", 1830);
		if (Z_TYPE_P(&groupRoutes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groupRoutes), _3$$5)
			{
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _3$$5);
				ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "rewind", NULL, 0);
			zephir_check_call_status();
			_5$$5 = 1;
			while (1) {
				if (_5$$5) {
					_5$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_4$$5, &groupRoutes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&route, &groupRoutes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&route);
	}
	ZEPHIR_CALL_METHOD(&hostname, group, "gethostname", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&hostname) != IS_NULL) {
		zephir_is_iterable(&groupRoutes, 0, "phalcon/Mvc/Router.zep", 1839);
		if (Z_TYPE_P(&groupRoutes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groupRoutes), _6$$8)
			{
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _6$$8);
				ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &hostname);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "rewind", NULL, 0);
			zephir_check_call_status();
			_8$$8 = 1;
			while (1) {
				if (_8$$8) {
					_8$$8 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_7$$8, &groupRoutes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$8)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&route, &groupRoutes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &hostname);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&route);
	}
	zephir_is_iterable(&groupRoutes, 0, "phalcon/Mvc/Router.zep", 1845);
	if (Z_TYPE_P(&groupRoutes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groupRoutes), _9)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _9);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", &_10, 0, &route);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, &groupRoutes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &groupRoutes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", &_10, 0, &route);
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
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Router, notFound)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *paths, paths_sub, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&_1$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("notFoundPaths", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(paths)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &paths);
	_0 = Z_TYPE_P(paths) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(paths) != IS_STRING;
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_router_exceptions_invalidnotfoundpaths_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 274);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Router.zep", 1859);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 310, paths);
	RETURN_THIS();
}

/**
 * Set whether router must remove the extra slashes in the handled routes
 *
 * @param bool remove
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes)
{
	zval *remove_param = NULL, __$true, __$false;
	zend_bool remove;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("removeExtraSlashes", 18, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(remove)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &remove_param);
	if (remove) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 304, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 304, &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the default action name
 *
 * @param string actionName
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction)
{
	zval actionName_zv;
	zend_string *actionName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultAction", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&actionName_zv, actionName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 301, &actionName_zv);
	RETURN_THISW();
}

/**
 * Sets the default controller name
 *
 * @param string controllerName
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultController)
{
	zval controllerName_zv;
	zend_string *controllerName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultController", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(controllerName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&controllerName_zv, controllerName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 300, &controllerName_zv);
	RETURN_THISW();
}

/**
 * Sets the name of the default module
 *
 * @param string moduleName
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule)
{
	zval moduleName_zv;
	zend_string *moduleName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultModule", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(moduleName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&moduleName_zv, moduleName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 299, &moduleName_zv);
	RETURN_THISW();
}

/**
 * Sets the name of the default namespace
 *
 * @parma string namespaceName
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace)
{
	zval namespaceName_zv;
	zend_string *namespaceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultNamespace", 16, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(namespaceName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&namespaceName_zv, namespaceName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 298, &namespaceName_zv);
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
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaults)
{
	zval _0$$3, _1$$4, _2$$5, _3$$6;
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
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultNamespace", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("defaultModule", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("defaultController", 17, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("defaultAction", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("defaultParams", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(defaults, defaults_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &defaults_param);
	zephir_get_arrval(&defaults, defaults_param);
	zephir_memory_observe(&namespaceName);
	if (zephir_array_isset_string_fetch(&namespaceName, &defaults, SL("namespace"), 0)) {
		zephir_cast_to_string(&_0$$3, &namespaceName);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 298, &_0$$3);
	}
	zephir_memory_observe(&module);
	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 0)) {
		zephir_cast_to_string(&_1$$4, &module);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 299, &_1$$4);
	}
	zephir_memory_observe(&controller);
	if (zephir_array_isset_string_fetch(&controller, &defaults, SL("controller"), 0)) {
		zephir_cast_to_string(&_2$$5, &controller);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 300, &_2$$5);
	}
	zephir_memory_observe(&action);
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 0)) {
		zephir_cast_to_string(&_3$$6, &action);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 301, &_3$$6);
	}
	zephir_memory_observe(&params);
	if (zephir_array_isset_string_fetch(&params, &defaults, SL("params"), 0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 302, &params);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, zephir_get_internal_ce(SL("phalcon\\events\\managerinterface")))
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 307, eventsManager);
}

/**
 * @param array $routeIds
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Router, setKeyRouteIds)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *routeIds_param = NULL;
	zval routeIds;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeIds);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("keyRouteIds", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(routeIds, routeIds_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &routeIds_param);
	zephir_get_arrval(&routeIds, routeIds_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 294, &routeIds);
	RETURN_THIS();
}

/**
 * @param array $routeNames
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Router, setKeyRouteNames)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *routeNames_param = NULL;
	zval routeNames;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeNames);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("keyRouteNames", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(routeNames, routeNames_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &routeNames_param);
	zephir_get_arrval(&routeNames, routeNames_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 295, &routeNames);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("uriSource", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(uriSource)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &uriSource_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, uriSource);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 303, &_0);
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

/**
 * Adds a single route from a config array entry. Used by loadFromConfig.
 *
 * @param array routeData
 *
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_Router, addRouteFromConfig)
{
	zval _3$$5, _7$$8, _9$$9;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routeData_param = NULL, method, methodClass, pattern, paths, route, _1, _2$$5, _4$$6, _5$$7, _6$$8, _8$$9;
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
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$9);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(routeData, routeData_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &routeData_param);
	zephir_get_arrval(&routeData, routeData_param);
	zephir_memory_observe(&pattern);
	if (!(zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missingrouteconfigkey_ce, "pattern", "phalcon/Mvc/Router.zep", 2061);
		return;
	}
	zephir_memory_observe(&paths);
	if (!(zephir_array_isset_string_fetch(&paths, &routeData, SL("paths"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missingrouteconfigkey_ce, "paths", "phalcon/Mvc/Router.zep", 2065);
		return;
	}
	ZEPHIR_INIT_VAR(&method);
	ZVAL_STRING(&method, "");
	_0 = zephir_array_isset_value_string(&routeData, SL("method"));
	if (_0) {
		zephir_array_fetch_string(&_1, &routeData, SL("method"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2069);
		_0 = Z_TYPE_P(&_1) != IS_NULL;
	}
	if (_0) {
		zephir_memory_observe(&_2$$5);
		zephir_array_fetch_string(&_2$$5, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2070);
		zephir_cast_to_string(&_3$$5, &_2$$5);
		ZEPHIR_INIT_NVAR(&method);
		zephir_fast_strtolower(&method, &_3$$5);
	}
	if (ZEPHIR_IS_STRING(&method, "")) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_STRING(&method, "connect")) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_STRING(&method, "delete")) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_STRING(&method, "get")) { goto zephir_switch_0_clause_3; }
	if (ZEPHIR_IS_STRING(&method, "head")) { goto zephir_switch_0_clause_4; }
	if (ZEPHIR_IS_STRING(&method, "options")) { goto zephir_switch_0_clause_5; }
	if (ZEPHIR_IS_STRING(&method, "patch")) { goto zephir_switch_0_clause_6; }
	if (ZEPHIR_IS_STRING(&method, "post")) { goto zephir_switch_0_clause_7; }
	if (ZEPHIR_IS_STRING(&method, "purge")) { goto zephir_switch_0_clause_8; }
	if (ZEPHIR_IS_STRING(&method, "put")) { goto zephir_switch_0_clause_9; }
	if (ZEPHIR_IS_STRING(&method, "trace")) { goto zephir_switch_0_clause_10; }
	goto zephir_switch_0_clause_11;
	zephir_switch_0_clause_0: ;
	zephir_switch_0_clause_1: ;
	zephir_switch_0_clause_2: ;
	zephir_switch_0_clause_3: ;
	zephir_switch_0_clause_4: ;
	zephir_switch_0_clause_5: ;
	zephir_switch_0_clause_6: ;
	zephir_switch_0_clause_7: ;
	zephir_switch_0_clause_8: ;
	zephir_switch_0_clause_9: ;
	zephir_switch_0_clause_10: ;
		ZEPHIR_INIT_VAR(&_4$$6);
		zephir_ucfirst(&_4$$6, &method);
		ZEPHIR_INIT_VAR(&methodClass);
		ZEPHIR_CONCAT_SV(&methodClass, "add", &_4$$6);
		ZEPHIR_CALL_METHOD_ZVAL(&route, this_ptr, &methodClass, NULL, 0, &pattern, &paths);
		zephir_check_call_status();
		goto zephir_switch_0_end;
	zephir_switch_0_clause_11: ;
		ZEPHIR_INIT_VAR(&_5$$7);
		object_init_ex(&_5$$7, phalcon_mvc_router_exceptions_unknownhttpmethod_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", NULL, 275, &method);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$7, "phalcon/Mvc/Router.zep", 2089);
		ZEPHIR_MM_RESTORE();
		return;
	zephir_switch_0_end: ;

	if (zephir_array_isset_value_string(&routeData, SL("name"))) {
		zephir_memory_observe(&_6$$8);
		zephir_array_fetch_string(&_6$$8, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 2093);
		zephir_cast_to_string(&_7$$8, &_6$$8);
		ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &_7$$8);
		zephir_check_call_status();
	}
	if (zephir_array_isset_value_string(&routeData, SL("hostname"))) {
		zephir_memory_observe(&_8$$9);
		zephir_array_fetch_string(&_8$$9, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 2096);
		zephir_cast_to_string(&_9$$9, &_8$$9);
		ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &_9$$9);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
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
	zephir_array_fetch_long(&realUri, &urlParts, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2105);
	RETURN_CTOR(&realUri);
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
	zval _1$$4, _3$$5, _9$$11, _14$$14, _20$$18, _24$$21;
	zend_bool _16, _6$$8, _17$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *groupData_param = NULL, group, paths, routes, routeData, method, methodClass, pattern, routePaths, route, *_5, _15, _0$$4, _2$$5, _4$$7, _7$$8, _8$$11, _10$$12, _11$$13, _13$$14, _18$$15, _19$$18, _21$$19, _22$$20, _23$$21;
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
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$20);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_20$$18);
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
	if (zephir_array_isset_value_string(&groupData, SL("paths"))) {
		ZEPHIR_OBS_NVAR(&paths);
		zephir_array_fetch_string(&paths, &groupData, SL("paths"), PH_NOISY, "phalcon/Mvc/Router.zep", 2123);
	}
	ZEPHIR_INIT_VAR(&group);
	object_init_ex(&group, phalcon_mvc_router_group_ce);
	ZEPHIR_CALL_METHOD(NULL, &group, "__construct", NULL, 276, &paths);
	zephir_check_call_status();
	if (zephir_array_isset_value_string(&groupData, SL("prefix"))) {
		zephir_memory_observe(&_0$$4);
		zephir_array_fetch_string(&_0$$4, &groupData, SL("prefix"), PH_NOISY, "phalcon/Mvc/Router.zep", 2129);
		zephir_cast_to_string(&_1$$4, &_0$$4);
		ZEPHIR_CALL_METHOD(NULL, &group, "setprefix", NULL, 277, &_1$$4);
		zephir_check_call_status();
	}
	if (zephir_array_isset_value_string(&groupData, SL("hostname"))) {
		zephir_memory_observe(&_2$$5);
		zephir_array_fetch_string(&_2$$5, &groupData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 2133);
		zephir_cast_to_string(&_3$$5, &_2$$5);
		ZEPHIR_CALL_METHOD(NULL, &group, "sethostname", NULL, 278, &_3$$5);
		zephir_check_call_status();
	}
	zephir_memory_observe(&routes);
	if (!(zephir_array_isset_string_fetch(&routes, &groupData, SL("routes"), 0))) {
		ZEPHIR_INIT_NVAR(&routes);
		array_init(&routes);
	}
	if (Z_TYPE_P(&routes) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_4$$7);
		object_init_ex(&_4$$7, phalcon_mvc_router_exceptions_grouproutesmustbearray_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", NULL, 279);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$7, "phalcon/Mvc/Router.zep", 2141);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_is_iterable(&routes, 0, "phalcon/Mvc/Router.zep", 2181);
	if (Z_TYPE_P(&routes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&routes), _5)
		{
			ZEPHIR_INIT_NVAR(&routeData);
			ZVAL_COPY(&routeData, _5);
			ZEPHIR_OBS_NVAR(&pattern);
			if (!(zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "pattern", "phalcon/Mvc/Router.zep", 2146);
				return;
			}
			ZEPHIR_OBS_NVAR(&routePaths);
			if (!(zephir_array_isset_string_fetch(&routePaths, &routeData, SL("paths"), 0))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "paths", "phalcon/Mvc/Router.zep", 2149);
				return;
			}
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_STRING(&method, "");
			_6$$8 = zephir_array_isset_value_string(&routeData, SL("method"));
			if (_6$$8) {
				zephir_array_fetch_string(&_7$$8, &routeData, SL("method"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2153);
				_6$$8 = Z_TYPE_P(&_7$$8) != IS_NULL;
			}
			if (_6$$8) {
				ZEPHIR_OBS_NVAR(&_8$$11);
				zephir_array_fetch_string(&_8$$11, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2154);
				zephir_cast_to_string(&_9$$11, &_8$$11);
				ZEPHIR_INIT_NVAR(&method);
				zephir_fast_strtolower(&method, &_9$$11);
			}
			if (ZEPHIR_IS_STRING(&method, "")) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_STRING(&method, "connect")) { goto zephir_switch_0_clause_1; }
			if (ZEPHIR_IS_STRING(&method, "delete")) { goto zephir_switch_0_clause_2; }
			if (ZEPHIR_IS_STRING(&method, "get")) { goto zephir_switch_0_clause_3; }
			if (ZEPHIR_IS_STRING(&method, "head")) { goto zephir_switch_0_clause_4; }
			if (ZEPHIR_IS_STRING(&method, "options")) { goto zephir_switch_0_clause_5; }
			if (ZEPHIR_IS_STRING(&method, "patch")) { goto zephir_switch_0_clause_6; }
			if (ZEPHIR_IS_STRING(&method, "post")) { goto zephir_switch_0_clause_7; }
			if (ZEPHIR_IS_STRING(&method, "purge")) { goto zephir_switch_0_clause_8; }
			if (ZEPHIR_IS_STRING(&method, "put")) { goto zephir_switch_0_clause_9; }
			if (ZEPHIR_IS_STRING(&method, "trace")) { goto zephir_switch_0_clause_10; }
			goto zephir_switch_0_clause_11;
			zephir_switch_0_clause_0: ;
			zephir_switch_0_clause_1: ;
			zephir_switch_0_clause_2: ;
			zephir_switch_0_clause_3: ;
			zephir_switch_0_clause_4: ;
			zephir_switch_0_clause_5: ;
			zephir_switch_0_clause_6: ;
			zephir_switch_0_clause_7: ;
			zephir_switch_0_clause_8: ;
			zephir_switch_0_clause_9: ;
			zephir_switch_0_clause_10: ;
				ZEPHIR_INIT_NVAR(&_10$$12);
				zephir_ucfirst(&_10$$12, &method);
				ZEPHIR_INIT_NVAR(&methodClass);
				ZEPHIR_CONCAT_SV(&methodClass, "add", &_10$$12);
				ZEPHIR_CALL_METHOD_ZVAL(&route, &group, &methodClass, NULL, 0, &pattern, &routePaths);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_11: ;
				ZEPHIR_INIT_NVAR(&_11$$13);
				object_init_ex(&_11$$13, phalcon_mvc_router_exceptions_unknownhttpmethod_ce);
				ZEPHIR_CALL_METHOD(NULL, &_11$$13, "__construct", &_12, 275, &method);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$13, "phalcon/Mvc/Router.zep", 2173);
				ZEPHIR_MM_RESTORE();
				return;
			zephir_switch_0_end: ;

			if (zephir_array_isset_value_string(&routeData, SL("name"))) {
				ZEPHIR_OBS_NVAR(&_13$$14);
				zephir_array_fetch_string(&_13$$14, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 2177);
				zephir_cast_to_string(&_14$$14, &_13$$14);
				ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &_14$$14);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &routes, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &routes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, &routes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&routeData, &routes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&pattern);
				if (!(zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "pattern", "phalcon/Mvc/Router.zep", 2146);
					return;
				}
				ZEPHIR_OBS_NVAR(&routePaths);
				if (!(zephir_array_isset_string_fetch(&routePaths, &routeData, SL("paths"), 0))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "paths", "phalcon/Mvc/Router.zep", 2149);
					return;
				}
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_STRING(&method, "");
				_17$$15 = zephir_array_isset_value_string(&routeData, SL("method"));
				if (_17$$15) {
					zephir_array_fetch_string(&_18$$15, &routeData, SL("method"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2153);
					_17$$15 = Z_TYPE_P(&_18$$15) != IS_NULL;
				}
				if (_17$$15) {
					ZEPHIR_OBS_NVAR(&_19$$18);
					zephir_array_fetch_string(&_19$$18, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2154);
					zephir_cast_to_string(&_20$$18, &_19$$18);
					ZEPHIR_INIT_NVAR(&method);
					zephir_fast_strtolower(&method, &_20$$18);
				}
				if (ZEPHIR_IS_STRING(&method, "")) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_STRING(&method, "connect")) { goto zephir_switch_1_clause_1; }
				if (ZEPHIR_IS_STRING(&method, "delete")) { goto zephir_switch_1_clause_2; }
				if (ZEPHIR_IS_STRING(&method, "get")) { goto zephir_switch_1_clause_3; }
				if (ZEPHIR_IS_STRING(&method, "head")) { goto zephir_switch_1_clause_4; }
				if (ZEPHIR_IS_STRING(&method, "options")) { goto zephir_switch_1_clause_5; }
				if (ZEPHIR_IS_STRING(&method, "patch")) { goto zephir_switch_1_clause_6; }
				if (ZEPHIR_IS_STRING(&method, "post")) { goto zephir_switch_1_clause_7; }
				if (ZEPHIR_IS_STRING(&method, "purge")) { goto zephir_switch_1_clause_8; }
				if (ZEPHIR_IS_STRING(&method, "put")) { goto zephir_switch_1_clause_9; }
				if (ZEPHIR_IS_STRING(&method, "trace")) { goto zephir_switch_1_clause_10; }
				goto zephir_switch_1_clause_11;
				zephir_switch_1_clause_0: ;
				zephir_switch_1_clause_1: ;
				zephir_switch_1_clause_2: ;
				zephir_switch_1_clause_3: ;
				zephir_switch_1_clause_4: ;
				zephir_switch_1_clause_5: ;
				zephir_switch_1_clause_6: ;
				zephir_switch_1_clause_7: ;
				zephir_switch_1_clause_8: ;
				zephir_switch_1_clause_9: ;
				zephir_switch_1_clause_10: ;
					ZEPHIR_INIT_NVAR(&_21$$19);
					zephir_ucfirst(&_21$$19, &method);
					ZEPHIR_INIT_NVAR(&methodClass);
					ZEPHIR_CONCAT_SV(&methodClass, "add", &_21$$19);
					ZEPHIR_CALL_METHOD_ZVAL(&route, &group, &methodClass, NULL, 0, &pattern, &routePaths);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_clause_11: ;
					ZEPHIR_INIT_NVAR(&_22$$20);
					object_init_ex(&_22$$20, phalcon_mvc_router_exceptions_unknownhttpmethod_ce);
					ZEPHIR_CALL_METHOD(NULL, &_22$$20, "__construct", &_12, 275, &method);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_22$$20, "phalcon/Mvc/Router.zep", 2173);
					ZEPHIR_MM_RESTORE();
					return;
				zephir_switch_1_end: ;

				if (zephir_array_isset_value_string(&routeData, SL("name"))) {
					ZEPHIR_OBS_NVAR(&_23$$21);
					zephir_array_fetch_string(&_23$$21, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 2177);
					zephir_cast_to_string(&_24$$21, &_23$$21);
					ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &_24$$21);
					zephir_check_call_status();
				}
		}
	}
	ZEPHIR_INIT_NVAR(&routeData);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mount", NULL, 0, &group);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Rebuilds the HTTP-method index from the current routes array.
 * Routes with no HTTP method constraint are filed under "*".
 */
PHP_METHOD(Phalcon_Mvc_Router, rebuildMethodIndex)
{
	zval _149$$98, _155$$101, _179$$111, _185$$114;
	zval _37$$40, _42$$42;
	zend_string *_19, *_48, *_118, *_141, *_57$$49, *_73$$58, *_90$$68, *_106$$77, *_123$$82, *_132$$89, *_145$$96, *_175$$109;
	zend_ulong _18, _47, _117, _140, _56$$49, _72$$58, _89$$68, _105$$77, _122$$82, _131$$89, _144$$96, _174$$109;
	zend_bool isRegex = 0, _11, _27, _41, _81, _127, _171, _9$$6, _14$$12, _25$$16, _33$$28, _65$$44, _61$$49, _77$$58, _98$$63, _94$$68, _110$$77, _125$$82, _134$$89, _151$$96, _165$$106, _181$$109, _193$$119;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_158 = NULL, *_161 = NULL;
	zval __$true, __$false, route, methods, method, methodSpecific, starRoutes, candidates, candidateRoute, candidatePattern, bucketRoute, bucketPattern, staticUri, staticBucket, staticRoutesList, _0, _1, _2, _3, _4, _5, *_6, _10, _15, _16, *_17, _26, _34, _35, *_36, _40, _45, *_46, _80, bucketIdx, bucketHostname, _113, _114, _115, *_116, _126, combinedAlternatives, combinedMark, combinedBody, combinedBodyMatch, combinedShape, hostnameBucketRef, _135, _136, _137, _138, *_139, _170, *_7$$6, _8$$6, *_12$$12, _13$$12, _20$$17, _21$$16, _22$$16, *_23$$16, _24$$16, _28$$29, _29$$28, _30$$28, *_31$$28, _32$$28, _38$$40, _39$$40, _43$$42, _44$$42, *_49$$44, _64$$44, _50$$46, _51$$46, _52$$47, _53$$47, _54$$48, *_55$$49, _60$$49, _58$$50, _59$$50, _62$$52, _63$$52, _66$$55, _67$$55, _68$$56, _69$$56, _70$$57, *_71$$58, _76$$58, _74$$59, _75$$59, _78$$61, _79$$61, *_82$$63, _97$$63, _83$$65, _84$$65, _85$$66, _86$$66, _87$$67, *_88$$68, _93$$68, _91$$69, _92$$69, _95$$71, _96$$71, _99$$74, _100$$74, _101$$75, _102$$75, _103$$76, *_104$$77, _109$$77, _107$$78, _108$$78, _111$$80, _112$$80, _119$$82, _120$$82, *_121$$82, _124$$82, _128$$89, _129$$89, *_130$$89, _133$$89, _142$$96, *_143$$96, _150$$96, _156$$96, chunkedPatterns$$96, chunkedMarkMaps$$96, chunkOffset$$96, chunkSlice$$96, chunkSliceMap$$96, chunkMarkSubset$$96, reversedMarkIds$$96, chunkMarkId$$96, _157$$96, _159$$96, _146$$98, _147$$98, _148$$98, _152$$101, _153$$101, _154$$101, _160$$106, *_162$$106, _164$$106, _167$$106, _168$$106, _169$$106, _163$$107, _166$$108, _172$$109, *_173$$109, _180$$109, _186$$109, chunkedPatterns$$109, chunkedMarkMaps$$109, chunkOffset$$109, chunkSlice$$109, chunkSliceMap$$109, chunkMarkSubset$$109, reversedMarkIds$$109, chunkMarkId$$109, _187$$109, _188$$109, _176$$111, _177$$111, _178$$111, _182$$114, _183$$114, _184$$114, _189$$119, *_190$$119, _192$$119, _195$$119, _196$$119, _197$$119, _191$$120, _194$$121;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&methodSpecific);
	ZVAL_UNDEF(&starRoutes);
	ZVAL_UNDEF(&candidates);
	ZVAL_UNDEF(&candidateRoute);
	ZVAL_UNDEF(&candidatePattern);
	ZVAL_UNDEF(&bucketRoute);
	ZVAL_UNDEF(&bucketPattern);
	ZVAL_UNDEF(&staticUri);
	ZVAL_UNDEF(&staticBucket);
	ZVAL_UNDEF(&staticRoutesList);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_80);
	ZVAL_UNDEF(&bucketIdx);
	ZVAL_UNDEF(&bucketHostname);
	ZVAL_UNDEF(&_113);
	ZVAL_UNDEF(&_114);
	ZVAL_UNDEF(&_115);
	ZVAL_UNDEF(&_126);
	ZVAL_UNDEF(&combinedAlternatives);
	ZVAL_UNDEF(&combinedMark);
	ZVAL_UNDEF(&combinedBody);
	ZVAL_UNDEF(&combinedBodyMatch);
	ZVAL_UNDEF(&combinedShape);
	ZVAL_UNDEF(&hostnameBucketRef);
	ZVAL_UNDEF(&_135);
	ZVAL_UNDEF(&_136);
	ZVAL_UNDEF(&_137);
	ZVAL_UNDEF(&_138);
	ZVAL_UNDEF(&_170);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_28$$29);
	ZVAL_UNDEF(&_29$$28);
	ZVAL_UNDEF(&_30$$28);
	ZVAL_UNDEF(&_32$$28);
	ZVAL_UNDEF(&_38$$40);
	ZVAL_UNDEF(&_39$$40);
	ZVAL_UNDEF(&_43$$42);
	ZVAL_UNDEF(&_44$$42);
	ZVAL_UNDEF(&_64$$44);
	ZVAL_UNDEF(&_50$$46);
	ZVAL_UNDEF(&_51$$46);
	ZVAL_UNDEF(&_52$$47);
	ZVAL_UNDEF(&_53$$47);
	ZVAL_UNDEF(&_54$$48);
	ZVAL_UNDEF(&_60$$49);
	ZVAL_UNDEF(&_58$$50);
	ZVAL_UNDEF(&_59$$50);
	ZVAL_UNDEF(&_62$$52);
	ZVAL_UNDEF(&_63$$52);
	ZVAL_UNDEF(&_66$$55);
	ZVAL_UNDEF(&_67$$55);
	ZVAL_UNDEF(&_68$$56);
	ZVAL_UNDEF(&_69$$56);
	ZVAL_UNDEF(&_70$$57);
	ZVAL_UNDEF(&_76$$58);
	ZVAL_UNDEF(&_74$$59);
	ZVAL_UNDEF(&_75$$59);
	ZVAL_UNDEF(&_78$$61);
	ZVAL_UNDEF(&_79$$61);
	ZVAL_UNDEF(&_97$$63);
	ZVAL_UNDEF(&_83$$65);
	ZVAL_UNDEF(&_84$$65);
	ZVAL_UNDEF(&_85$$66);
	ZVAL_UNDEF(&_86$$66);
	ZVAL_UNDEF(&_87$$67);
	ZVAL_UNDEF(&_93$$68);
	ZVAL_UNDEF(&_91$$69);
	ZVAL_UNDEF(&_92$$69);
	ZVAL_UNDEF(&_95$$71);
	ZVAL_UNDEF(&_96$$71);
	ZVAL_UNDEF(&_99$$74);
	ZVAL_UNDEF(&_100$$74);
	ZVAL_UNDEF(&_101$$75);
	ZVAL_UNDEF(&_102$$75);
	ZVAL_UNDEF(&_103$$76);
	ZVAL_UNDEF(&_109$$77);
	ZVAL_UNDEF(&_107$$78);
	ZVAL_UNDEF(&_108$$78);
	ZVAL_UNDEF(&_111$$80);
	ZVAL_UNDEF(&_112$$80);
	ZVAL_UNDEF(&_119$$82);
	ZVAL_UNDEF(&_120$$82);
	ZVAL_UNDEF(&_124$$82);
	ZVAL_UNDEF(&_128$$89);
	ZVAL_UNDEF(&_129$$89);
	ZVAL_UNDEF(&_133$$89);
	ZVAL_UNDEF(&_142$$96);
	ZVAL_UNDEF(&_150$$96);
	ZVAL_UNDEF(&_156$$96);
	ZVAL_UNDEF(&chunkedPatterns$$96);
	ZVAL_UNDEF(&chunkedMarkMaps$$96);
	ZVAL_UNDEF(&chunkOffset$$96);
	ZVAL_UNDEF(&chunkSlice$$96);
	ZVAL_UNDEF(&chunkSliceMap$$96);
	ZVAL_UNDEF(&chunkMarkSubset$$96);
	ZVAL_UNDEF(&reversedMarkIds$$96);
	ZVAL_UNDEF(&chunkMarkId$$96);
	ZVAL_UNDEF(&_157$$96);
	ZVAL_UNDEF(&_159$$96);
	ZVAL_UNDEF(&_146$$98);
	ZVAL_UNDEF(&_147$$98);
	ZVAL_UNDEF(&_148$$98);
	ZVAL_UNDEF(&_152$$101);
	ZVAL_UNDEF(&_153$$101);
	ZVAL_UNDEF(&_154$$101);
	ZVAL_UNDEF(&_160$$106);
	ZVAL_UNDEF(&_164$$106);
	ZVAL_UNDEF(&_167$$106);
	ZVAL_UNDEF(&_168$$106);
	ZVAL_UNDEF(&_169$$106);
	ZVAL_UNDEF(&_163$$107);
	ZVAL_UNDEF(&_166$$108);
	ZVAL_UNDEF(&_172$$109);
	ZVAL_UNDEF(&_180$$109);
	ZVAL_UNDEF(&_186$$109);
	ZVAL_UNDEF(&chunkedPatterns$$109);
	ZVAL_UNDEF(&chunkedMarkMaps$$109);
	ZVAL_UNDEF(&chunkOffset$$109);
	ZVAL_UNDEF(&chunkSlice$$109);
	ZVAL_UNDEF(&chunkSliceMap$$109);
	ZVAL_UNDEF(&chunkMarkSubset$$109);
	ZVAL_UNDEF(&reversedMarkIds$$109);
	ZVAL_UNDEF(&chunkMarkId$$109);
	ZVAL_UNDEF(&_187$$109);
	ZVAL_UNDEF(&_188$$109);
	ZVAL_UNDEF(&_176$$111);
	ZVAL_UNDEF(&_177$$111);
	ZVAL_UNDEF(&_178$$111);
	ZVAL_UNDEF(&_182$$114);
	ZVAL_UNDEF(&_183$$114);
	ZVAL_UNDEF(&_184$$114);
	ZVAL_UNDEF(&_189$$119);
	ZVAL_UNDEF(&_192$$119);
	ZVAL_UNDEF(&_195$$119);
	ZVAL_UNDEF(&_196$$119);
	ZVAL_UNDEF(&_197$$119);
	ZVAL_UNDEF(&_191$$120);
	ZVAL_UNDEF(&_194$$121);
	ZVAL_UNDEF(&_37$$40);
	ZVAL_UNDEF(&_42$$42);
	ZVAL_UNDEF(&_149$$98);
	ZVAL_UNDEF(&_155$$101);
	ZVAL_UNDEF(&_179$$111);
	ZVAL_UNDEF(&_185$$114);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	static zend_string *_zephir_prop_11 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("methodRoutes", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("candidatesByMethod", 18, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("routeMeta", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("staticByMethod", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("staticShadowedByMethod", 22, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("routes", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("hostnameByMethod", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("hostnameLessByMethod", 20, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("combinedRegexByMethod", 21, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("combinedRegexMarkMap", 20, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("combinedRegexDisabled", 21, 1);
	}
	if (UNEXPECTED(!_zephir_prop_11)) {
		_zephir_prop_11 = zend_string_init("methodRoutesDirty", 17, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 284, &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 285, &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 286, &_2);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 287, &_3);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 288, &_4);
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_5, 282, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_5, 0, "phalcon/Mvc/Router.zep", 2215);
	if (Z_TYPE_P(&_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5), _6)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _6);
			ZEPHIR_CALL_METHOD(&methods, &route, "gethttpmethods", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&methods) == IS_NULL) {
				zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("sa"), 3, SL("*"));
			} else if (Z_TYPE_P(&methods) == IS_STRING) {
				zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("za"), 2, &methods);
			} else {
				zephir_is_iterable(&methods, 0, "phalcon/Mvc/Router.zep", 2212);
				if (Z_TYPE_P(&methods) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _7$$6)
					{
						ZEPHIR_INIT_NVAR(&method);
						ZVAL_COPY(&method, _7$$6);
						zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("za"), 2, &method);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
					zephir_check_call_status();
					_9$$6 = 1;
					while (1) {
						if (_9$$6) {
							_9$$6 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_8$$6, &methods, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_8$$6)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&method, &methods, "current", NULL, 0);
						zephir_check_call_status();
							zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("za"), 2, &method);
					}
				}
				ZEPHIR_INIT_NVAR(&method);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_5, "rewind", NULL, 0);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_5, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_10, &_5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &_5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&methods, &route, "gethttpmethods", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&methods) == IS_NULL) {
					zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("sa"), 3, SL("*"));
				} else if (Z_TYPE_P(&methods) == IS_STRING) {
					zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("za"), 2, &methods);
				} else {
					zephir_is_iterable(&methods, 0, "phalcon/Mvc/Router.zep", 2212);
					if (Z_TYPE_P(&methods) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _12$$12)
						{
							ZEPHIR_INIT_NVAR(&method);
							ZVAL_COPY(&method, _12$$12);
							zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("za"), 2, &method);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
						zephir_check_call_status();
						_14$$12 = 1;
						while (1) {
							if (_14$$12) {
								_14$$12 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_13$$12, &methods, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_13$$12)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&method, &methods, "current", NULL, 0);
							zephir_check_call_status();
								zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("za"), 2, &method);
						}
					}
					ZEPHIR_INIT_NVAR(&method);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	zephir_memory_observe(&starRoutes);
	zephir_read_property_cached(&_15, this_ptr, _zephir_prop_0, 284, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&starRoutes, &_15, SL("*"), 0))) {
		ZEPHIR_INIT_NVAR(&starRoutes);
		array_init(&starRoutes);
	}
	zephir_read_property_cached(&_16, this_ptr, _zephir_prop_0, 284, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_16, 0, "phalcon/Mvc/Router.zep", 2255);
	if (Z_TYPE_P(&_16) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_16), _18, _19, _17)
		{
			ZEPHIR_INIT_NVAR(&method);
			if (_19 != NULL) { 
				ZVAL_STR_COPY(&method, _19);
			} else {
				ZVAL_LONG(&method, _18);
			}
			ZEPHIR_INIT_NVAR(&methodSpecific);
			ZVAL_COPY(&methodSpecific, _17);
			if (ZEPHIR_IS_STRING(&method, "*")) {
				ZEPHIR_INIT_NVAR(&_20$$17);
				ZVAL_STRING(&_20$$17, "*");
				zephir_update_property_array(this_ptr, SL("candidatesByMethod"), &_20$$17, &starRoutes);
				continue;
			}
			ZEPHIR_INIT_NVAR(&_21$$16);
			array_init(&_21$$16);
			zephir_update_property_array(this_ptr, SL("candidatesByMethod"), &method, &_21$$16);
			zephir_read_property_cached(&_22$$16, this_ptr, _zephir_prop_5, 282, PH_NOISY_CC | PH_READONLY);
			zephir_is_iterable(&_22$$16, 0, "phalcon/Mvc/Router.zep", 2248);
			if (Z_TYPE_P(&_22$$16) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_22$$16), _23$$16)
				{
					ZEPHIR_INIT_NVAR(&route);
					ZVAL_COPY(&route, _23$$16);
					ZEPHIR_CALL_METHOD(&methods, &route, "gethttpmethods", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&methods) == IS_NULL) {
						zephir_update_property_array_multi(this_ptr, SL("candidatesByMethod"), &route, SL("za"), 2, &method);
					} else if (Z_TYPE_P(&methods) == IS_STRING) {
						if (ZEPHIR_IS_IDENTICAL(&methods, &method)) {
							zephir_update_property_array_multi(this_ptr, SL("candidatesByMethod"), &route, SL("za"), 2, &method);
						}
					} else if (zephir_fast_in_array(&method, &methods)) {
						zephir_update_property_array_multi(this_ptr, SL("candidatesByMethod"), &route, SL("za"), 2, &method);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_22$$16, "rewind", NULL, 0);
				zephir_check_call_status();
				_25$$16 = 1;
				while (1) {
					if (_25$$16) {
						_25$$16 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &_22$$16, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_24$$16, &_22$$16, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_24$$16)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&route, &_22$$16, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&methods, &route, "gethttpmethods", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&methods) == IS_NULL) {
							zephir_update_property_array_multi(this_ptr, SL("candidatesByMethod"), &route, SL("za"), 2, &method);
						} else if (Z_TYPE_P(&methods) == IS_STRING) {
							if (ZEPHIR_IS_IDENTICAL(&methods, &method)) {
								zephir_update_property_array_multi(this_ptr, SL("candidatesByMethod"), &route, SL("za"), 2, &method);
							}
						} else if (zephir_fast_in_array(&method, &methods)) {
							zephir_update_property_array_multi(this_ptr, SL("candidatesByMethod"), &route, SL("za"), 2, &method);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&route);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_16, "rewind", NULL, 0);
		zephir_check_call_status();
		_27 = 1;
		while (1) {
			if (_27) {
				_27 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_16, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_26, &_16, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_26)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, &_16, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&methodSpecific, &_16, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_STRING(&method, "*")) {
					ZEPHIR_INIT_NVAR(&_28$$29);
					ZVAL_STRING(&_28$$29, "*");
					zephir_update_property_array(this_ptr, SL("candidatesByMethod"), &_28$$29, &starRoutes);
					continue;
				}
				ZEPHIR_INIT_NVAR(&_29$$28);
				array_init(&_29$$28);
				zephir_update_property_array(this_ptr, SL("candidatesByMethod"), &method, &_29$$28);
				zephir_read_property_cached(&_30$$28, this_ptr, _zephir_prop_5, 282, PH_NOISY_CC | PH_READONLY);
				zephir_is_iterable(&_30$$28, 0, "phalcon/Mvc/Router.zep", 2248);
				if (Z_TYPE_P(&_30$$28) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_30$$28), _31$$28)
					{
						ZEPHIR_INIT_NVAR(&route);
						ZVAL_COPY(&route, _31$$28);
						ZEPHIR_CALL_METHOD(&methods, &route, "gethttpmethods", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&methods) == IS_NULL) {
							zephir_update_property_array_multi(this_ptr, SL("candidatesByMethod"), &route, SL("za"), 2, &method);
						} else if (Z_TYPE_P(&methods) == IS_STRING) {
							if (ZEPHIR_IS_IDENTICAL(&methods, &method)) {
								zephir_update_property_array_multi(this_ptr, SL("candidatesByMethod"), &route, SL("za"), 2, &method);
							}
						} else if (zephir_fast_in_array(&method, &methods)) {
							zephir_update_property_array_multi(this_ptr, SL("candidatesByMethod"), &route, SL("za"), 2, &method);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_30$$28, "rewind", NULL, 0);
					zephir_check_call_status();
					_33$$28 = 1;
					while (1) {
						if (_33$$28) {
							_33$$28 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_30$$28, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_32$$28, &_30$$28, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_32$$28)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&route, &_30$$28, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&methods, &route, "gethttpmethods", NULL, 0);
							zephir_check_call_status();
							if (Z_TYPE_P(&methods) == IS_NULL) {
								zephir_update_property_array_multi(this_ptr, SL("candidatesByMethod"), &route, SL("za"), 2, &method);
							} else if (Z_TYPE_P(&methods) == IS_STRING) {
								if (ZEPHIR_IS_IDENTICAL(&methods, &method)) {
									zephir_update_property_array_multi(this_ptr, SL("candidatesByMethod"), &route, SL("za"), 2, &method);
								}
							} else if (zephir_fast_in_array(&method, &methods)) {
								zephir_update_property_array_multi(this_ptr, SL("candidatesByMethod"), &route, SL("za"), 2, &method);
							}
					}
				}
				ZEPHIR_INIT_NVAR(&route);
		}
	}
	ZEPHIR_INIT_NVAR(&methodSpecific);
	ZEPHIR_INIT_NVAR(&method);
	ZEPHIR_INIT_VAR(&_34);
	array_init(&_34);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 286, &_34);
	zephir_read_property_cached(&_35, this_ptr, _zephir_prop_5, 282, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_35, 0, "phalcon/Mvc/Router.zep", 2281);
	if (Z_TYPE_P(&_35) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_35), _36)
		{
			ZEPHIR_INIT_NVAR(&candidateRoute);
			ZVAL_COPY(&candidateRoute, _36);
			ZEPHIR_CALL_METHOD(&candidatePattern, &candidateRoute, "getcompiledpattern", NULL, 0);
			zephir_check_call_status();
			isRegex = 0;
			if (zephir_memnstr_str(&candidatePattern, SL("^"), "phalcon/Mvc/Router.zep", 2261)) {
				isRegex = 1;
			}
			ZEPHIR_INIT_NVAR(&_37$$40);
			zephir_create_array(&_37$$40, 5, 0);
			zephir_array_update_string(&_37$$40, SL("pattern"), &candidatePattern, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_38$$40);
			ZVAL_BOOL(&_38$$40, isRegex);
			zephir_array_update_string(&_37$$40, SL("isRegex"), &_38$$40, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_39$$40, &candidateRoute, "gethostname", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_37$$40, SL("hostname"), &_39$$40, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_39$$40, &candidateRoute, "getcompiledhostname", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_37$$40, SL("hostRegex"), &_39$$40, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_39$$40, &candidateRoute, "getbeforematch", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_37$$40, SL("beforeMatch"), &_39$$40, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_39$$40, &candidateRoute, "getrouteid", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("routeMeta"), &_39$$40, &_37$$40);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_35, "rewind", NULL, 0);
		zephir_check_call_status();
		_41 = 1;
		while (1) {
			if (_41) {
				_41 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_35, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_40, &_35, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_40)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&candidateRoute, &_35, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&candidatePattern, &candidateRoute, "getcompiledpattern", NULL, 0);
				zephir_check_call_status();
				isRegex = 0;
				if (zephir_memnstr_str(&candidatePattern, SL("^"), "phalcon/Mvc/Router.zep", 2261)) {
					isRegex = 1;
				}
				ZEPHIR_INIT_NVAR(&_42$$42);
				zephir_create_array(&_42$$42, 5, 0);
				zephir_array_update_string(&_42$$42, SL("pattern"), &candidatePattern, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_43$$42);
				ZVAL_BOOL(&_43$$42, isRegex);
				zephir_array_update_string(&_42$$42, SL("isRegex"), &_43$$42, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_44$$42, &candidateRoute, "gethostname", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_42$$42, SL("hostname"), &_44$$42, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_44$$42, &candidateRoute, "getcompiledhostname", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_42$$42, SL("hostRegex"), &_44$$42, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_44$$42, &candidateRoute, "getbeforematch", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_42$$42, SL("beforeMatch"), &_44$$42, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_44$$42, &candidateRoute, "getrouteid", NULL, 0);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("routeMeta"), &_44$$42, &_42$$42);
		}
	}
	ZEPHIR_INIT_NVAR(&candidateRoute);
	zephir_read_property_cached(&_45, this_ptr, _zephir_prop_1, 285, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_45, 0, "phalcon/Mvc/Router.zep", 2313);
	if (Z_TYPE_P(&_45) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_45), _47, _48, _46)
		{
			ZEPHIR_INIT_NVAR(&method);
			if (_48 != NULL) { 
				ZVAL_STR_COPY(&method, _48);
			} else {
				ZVAL_LONG(&method, _47);
			}
			ZEPHIR_INIT_NVAR(&candidates);
			ZVAL_COPY(&candidates, _46);
			zephir_is_iterable(&candidates, 0, "phalcon/Mvc/Router.zep", 2306);
			if (Z_TYPE_P(&candidates) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&candidates), _49$$44)
				{
					ZEPHIR_INIT_NVAR(&bucketRoute);
					ZVAL_COPY(&bucketRoute, _49$$44);
					ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2285))) {
						zephir_update_property_array_multi(this_ptr, SL("staticByMethod"), &bucketRoute, SL("zza"), 3, &method, &bucketPattern);
						zephir_read_property_cached(&_50$$46, this_ptr, _zephir_prop_4, 288, PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_51$$46, &_50$$46, &method, PH_READONLY, "phalcon/Mvc/Router.zep", 2293);
						if (zephir_array_isset_value(&_51$$46, &bucketPattern)) {
							zephir_read_property_cached(&_52$$47, this_ptr, _zephir_prop_4, 288, PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch(&_53$$47, &_52$$47, &method, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2294);
							zephir_array_unset(&_53$$47, &bucketPattern, PH_SEPARATE);
						}
					} else {
						ZEPHIR_OBS_NVAR(&staticBucket);
						zephir_read_property_cached(&_54$$48, this_ptr, _zephir_prop_3, 287, PH_NOISY_CC | PH_READONLY);
						if (zephir_array_isset_fetch(&staticBucket, &_54$$48, &method, 0)) {
							zephir_is_iterable(&staticBucket, 0, "phalcon/Mvc/Router.zep", 2303);
							if (Z_TYPE_P(&staticBucket) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&staticBucket), _56$$49, _57$$49, _55$$49)
								{
									ZEPHIR_INIT_NVAR(&staticUri);
									if (_57$$49 != NULL) { 
										ZVAL_STR_COPY(&staticUri, _57$$49);
									} else {
										ZVAL_LONG(&staticUri, _56$$49);
									}
									ZEPHIR_INIT_NVAR(&staticRoutesList);
									ZVAL_COPY(&staticRoutesList, _55$$49);
									ZEPHIR_INIT_NVAR(&_58$$50);
									ZEPHIR_INIT_NVAR(&_59$$50);
									zephir_preg_match(&_59$$50, &bucketPattern, &staticUri, &_58$$50, 0, 0 , 0 );
									if (zephir_is_true(&_59$$50)) {
										zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &staticBucket, "rewind", NULL, 0);
								zephir_check_call_status();
								_61$$49 = 1;
								while (1) {
									if (_61$$49) {
										_61$$49 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, &staticBucket, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_60$$49, &staticBucket, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_60$$49)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&staticUri, &staticBucket, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&staticRoutesList, &staticBucket, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_62$$52);
										ZEPHIR_INIT_NVAR(&_63$$52);
										zephir_preg_match(&_63$$52, &bucketPattern, &staticUri, &_62$$52, 0, 0 , 0 );
										if (zephir_is_true(&_63$$52)) {
											zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
										}
								}
							}
							ZEPHIR_INIT_NVAR(&staticRoutesList);
							ZEPHIR_INIT_NVAR(&staticUri);
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &candidates, "rewind", NULL, 0);
				zephir_check_call_status();
				_65$$44 = 1;
				while (1) {
					if (_65$$44) {
						_65$$44 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &candidates, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_64$$44, &candidates, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_64$$44)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&bucketRoute, &candidates, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2285))) {
							zephir_update_property_array_multi(this_ptr, SL("staticByMethod"), &bucketRoute, SL("zza"), 3, &method, &bucketPattern);
							zephir_read_property_cached(&_66$$55, this_ptr, _zephir_prop_4, 288, PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch(&_67$$55, &_66$$55, &method, PH_READONLY, "phalcon/Mvc/Router.zep", 2293);
							if (zephir_array_isset_value(&_67$$55, &bucketPattern)) {
								zephir_read_property_cached(&_68$$56, this_ptr, _zephir_prop_4, 288, PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch(&_69$$56, &_68$$56, &method, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2294);
								zephir_array_unset(&_69$$56, &bucketPattern, PH_SEPARATE);
							}
						} else {
							ZEPHIR_OBS_NVAR(&staticBucket);
							zephir_read_property_cached(&_70$$57, this_ptr, _zephir_prop_3, 287, PH_NOISY_CC | PH_READONLY);
							if (zephir_array_isset_fetch(&staticBucket, &_70$$57, &method, 0)) {
								zephir_is_iterable(&staticBucket, 0, "phalcon/Mvc/Router.zep", 2303);
								if (Z_TYPE_P(&staticBucket) == IS_ARRAY) {
									ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&staticBucket), _72$$58, _73$$58, _71$$58)
									{
										ZEPHIR_INIT_NVAR(&staticUri);
										if (_73$$58 != NULL) { 
											ZVAL_STR_COPY(&staticUri, _73$$58);
										} else {
											ZVAL_LONG(&staticUri, _72$$58);
										}
										ZEPHIR_INIT_NVAR(&staticRoutesList);
										ZVAL_COPY(&staticRoutesList, _71$$58);
										ZEPHIR_INIT_NVAR(&_74$$59);
										ZEPHIR_INIT_NVAR(&_75$$59);
										zephir_preg_match(&_75$$59, &bucketPattern, &staticUri, &_74$$59, 0, 0 , 0 );
										if (zephir_is_true(&_75$$59)) {
											zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
										}
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &staticBucket, "rewind", NULL, 0);
									zephir_check_call_status();
									_77$$58 = 1;
									while (1) {
										if (_77$$58) {
											_77$$58 = 0;
										} else {
											ZEPHIR_CALL_METHOD(NULL, &staticBucket, "next", NULL, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(&_76$$58, &staticBucket, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_76$$58)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&staticUri, &staticBucket, "key", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_CALL_METHOD(&staticRoutesList, &staticBucket, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_78$$61);
											ZEPHIR_INIT_NVAR(&_79$$61);
											zephir_preg_match(&_79$$61, &bucketPattern, &staticUri, &_78$$61, 0, 0 , 0 );
											if (zephir_is_true(&_79$$61)) {
												zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
											}
									}
								}
								ZEPHIR_INIT_NVAR(&staticRoutesList);
								ZEPHIR_INIT_NVAR(&staticUri);
							}
						}
				}
			}
			ZEPHIR_INIT_NVAR(&bucketRoute);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_45, "rewind", NULL, 0);
		zephir_check_call_status();
		_81 = 1;
		while (1) {
			if (_81) {
				_81 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_45, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_80, &_45, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_80)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, &_45, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&candidates, &_45, "current", NULL, 0);
			zephir_check_call_status();
				zephir_is_iterable(&candidates, 0, "phalcon/Mvc/Router.zep", 2306);
				if (Z_TYPE_P(&candidates) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&candidates), _82$$63)
					{
						ZEPHIR_INIT_NVAR(&bucketRoute);
						ZVAL_COPY(&bucketRoute, _82$$63);
						ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2285))) {
							zephir_update_property_array_multi(this_ptr, SL("staticByMethod"), &bucketRoute, SL("zza"), 3, &method, &bucketPattern);
							zephir_read_property_cached(&_83$$65, this_ptr, _zephir_prop_4, 288, PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch(&_84$$65, &_83$$65, &method, PH_READONLY, "phalcon/Mvc/Router.zep", 2293);
							if (zephir_array_isset_value(&_84$$65, &bucketPattern)) {
								zephir_read_property_cached(&_85$$66, this_ptr, _zephir_prop_4, 288, PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch(&_86$$66, &_85$$66, &method, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2294);
								zephir_array_unset(&_86$$66, &bucketPattern, PH_SEPARATE);
							}
						} else {
							ZEPHIR_OBS_NVAR(&staticBucket);
							zephir_read_property_cached(&_87$$67, this_ptr, _zephir_prop_3, 287, PH_NOISY_CC | PH_READONLY);
							if (zephir_array_isset_fetch(&staticBucket, &_87$$67, &method, 0)) {
								zephir_is_iterable(&staticBucket, 0, "phalcon/Mvc/Router.zep", 2303);
								if (Z_TYPE_P(&staticBucket) == IS_ARRAY) {
									ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&staticBucket), _89$$68, _90$$68, _88$$68)
									{
										ZEPHIR_INIT_NVAR(&staticUri);
										if (_90$$68 != NULL) { 
											ZVAL_STR_COPY(&staticUri, _90$$68);
										} else {
											ZVAL_LONG(&staticUri, _89$$68);
										}
										ZEPHIR_INIT_NVAR(&staticRoutesList);
										ZVAL_COPY(&staticRoutesList, _88$$68);
										ZEPHIR_INIT_NVAR(&_91$$69);
										ZEPHIR_INIT_NVAR(&_92$$69);
										zephir_preg_match(&_92$$69, &bucketPattern, &staticUri, &_91$$69, 0, 0 , 0 );
										if (zephir_is_true(&_92$$69)) {
											zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
										}
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &staticBucket, "rewind", NULL, 0);
									zephir_check_call_status();
									_94$$68 = 1;
									while (1) {
										if (_94$$68) {
											_94$$68 = 0;
										} else {
											ZEPHIR_CALL_METHOD(NULL, &staticBucket, "next", NULL, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(&_93$$68, &staticBucket, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_93$$68)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&staticUri, &staticBucket, "key", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_CALL_METHOD(&staticRoutesList, &staticBucket, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_95$$71);
											ZEPHIR_INIT_NVAR(&_96$$71);
											zephir_preg_match(&_96$$71, &bucketPattern, &staticUri, &_95$$71, 0, 0 , 0 );
											if (zephir_is_true(&_96$$71)) {
												zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
											}
									}
								}
								ZEPHIR_INIT_NVAR(&staticRoutesList);
								ZEPHIR_INIT_NVAR(&staticUri);
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &candidates, "rewind", NULL, 0);
					zephir_check_call_status();
					_98$$63 = 1;
					while (1) {
						if (_98$$63) {
							_98$$63 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &candidates, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_97$$63, &candidates, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_97$$63)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&bucketRoute, &candidates, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
							zephir_check_call_status();
							if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2285))) {
								zephir_update_property_array_multi(this_ptr, SL("staticByMethod"), &bucketRoute, SL("zza"), 3, &method, &bucketPattern);
								zephir_read_property_cached(&_99$$74, this_ptr, _zephir_prop_4, 288, PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch(&_100$$74, &_99$$74, &method, PH_READONLY, "phalcon/Mvc/Router.zep", 2293);
								if (zephir_array_isset_value(&_100$$74, &bucketPattern)) {
									zephir_read_property_cached(&_101$$75, this_ptr, _zephir_prop_4, 288, PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch(&_102$$75, &_101$$75, &method, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2294);
									zephir_array_unset(&_102$$75, &bucketPattern, PH_SEPARATE);
								}
							} else {
								ZEPHIR_OBS_NVAR(&staticBucket);
								zephir_read_property_cached(&_103$$76, this_ptr, _zephir_prop_3, 287, PH_NOISY_CC | PH_READONLY);
								if (zephir_array_isset_fetch(&staticBucket, &_103$$76, &method, 0)) {
									zephir_is_iterable(&staticBucket, 0, "phalcon/Mvc/Router.zep", 2303);
									if (Z_TYPE_P(&staticBucket) == IS_ARRAY) {
										ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&staticBucket), _105$$77, _106$$77, _104$$77)
										{
											ZEPHIR_INIT_NVAR(&staticUri);
											if (_106$$77 != NULL) { 
												ZVAL_STR_COPY(&staticUri, _106$$77);
											} else {
												ZVAL_LONG(&staticUri, _105$$77);
											}
											ZEPHIR_INIT_NVAR(&staticRoutesList);
											ZVAL_COPY(&staticRoutesList, _104$$77);
											ZEPHIR_INIT_NVAR(&_107$$78);
											ZEPHIR_INIT_NVAR(&_108$$78);
											zephir_preg_match(&_108$$78, &bucketPattern, &staticUri, &_107$$78, 0, 0 , 0 );
											if (zephir_is_true(&_108$$78)) {
												zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
											}
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &staticBucket, "rewind", NULL, 0);
										zephir_check_call_status();
										_110$$77 = 1;
										while (1) {
											if (_110$$77) {
												_110$$77 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, &staticBucket, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_109$$77, &staticBucket, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_109$$77)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&staticUri, &staticBucket, "key", NULL, 0);
											zephir_check_call_status();
											ZEPHIR_CALL_METHOD(&staticRoutesList, &staticBucket, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_111$$80);
												ZEPHIR_INIT_NVAR(&_112$$80);
												zephir_preg_match(&_112$$80, &bucketPattern, &staticUri, &_111$$80, 0, 0 , 0 );
												if (zephir_is_true(&_112$$80)) {
													zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
												}
										}
									}
									ZEPHIR_INIT_NVAR(&staticRoutesList);
									ZEPHIR_INIT_NVAR(&staticUri);
								}
							}
					}
				}
				ZEPHIR_INIT_NVAR(&bucketRoute);
		}
	}
	ZEPHIR_INIT_NVAR(&candidates);
	ZEPHIR_INIT_NVAR(&method);
	ZEPHIR_INIT_VAR(&_113);
	array_init(&_113);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 289, &_113);
	ZEPHIR_INIT_VAR(&_114);
	array_init(&_114);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 290, &_114);
	zephir_read_property_cached(&_115, this_ptr, _zephir_prop_1, 285, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_115, 0, "phalcon/Mvc/Router.zep", 2340);
	if (Z_TYPE_P(&_115) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_115), _117, _118, _116)
		{
			ZEPHIR_INIT_NVAR(&method);
			if (_118 != NULL) { 
				ZVAL_STR_COPY(&method, _118);
			} else {
				ZVAL_LONG(&method, _117);
			}
			ZEPHIR_INIT_NVAR(&candidates);
			ZVAL_COPY(&candidates, _116);
			ZEPHIR_INIT_NVAR(&_119$$82);
			array_init(&_119$$82);
			zephir_update_property_array(this_ptr, SL("hostnameByMethod"), &method, &_119$$82);
			ZEPHIR_INIT_NVAR(&_120$$82);
			array_init(&_120$$82);
			zephir_update_property_array(this_ptr, SL("hostnameLessByMethod"), &method, &_120$$82);
			zephir_is_iterable(&candidates, 0, "phalcon/Mvc/Router.zep", 2331);
			if (Z_TYPE_P(&candidates) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&candidates), _122$$82, _123$$82, _121$$82)
				{
					ZEPHIR_INIT_NVAR(&bucketIdx);
					if (_123$$82 != NULL) { 
						ZVAL_STR_COPY(&bucketIdx, _123$$82);
					} else {
						ZVAL_LONG(&bucketIdx, _122$$82);
					}
					ZEPHIR_INIT_NVAR(&bucketRoute);
					ZVAL_COPY(&bucketRoute, _121$$82);
					ZEPHIR_CALL_METHOD(&bucketHostname, &bucketRoute, "gethostname", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&bucketHostname) == IS_NULL) {
						zephir_update_property_array_multi(this_ptr, SL("hostnameLessByMethod"), &bucketIdx, SL("za"), 2, &method);
					} else {
						zephir_update_property_array_multi(this_ptr, SL("hostnameByMethod"), &bucketIdx, SL("zza"), 3, &method, &bucketHostname);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &candidates, "rewind", NULL, 0);
				zephir_check_call_status();
				_125$$82 = 1;
				while (1) {
					if (_125$$82) {
						_125$$82 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &candidates, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_124$$82, &candidates, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_124$$82)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&bucketIdx, &candidates, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&bucketRoute, &candidates, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&bucketHostname, &bucketRoute, "gethostname", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&bucketHostname) == IS_NULL) {
							zephir_update_property_array_multi(this_ptr, SL("hostnameLessByMethod"), &bucketIdx, SL("za"), 2, &method);
						} else {
							zephir_update_property_array_multi(this_ptr, SL("hostnameByMethod"), &bucketIdx, SL("zza"), 3, &method, &bucketHostname);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&bucketRoute);
			ZEPHIR_INIT_NVAR(&bucketIdx);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_115, "rewind", NULL, 0);
		zephir_check_call_status();
		_127 = 1;
		while (1) {
			if (_127) {
				_127 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_115, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_126, &_115, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_126)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, &_115, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&candidates, &_115, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_128$$89);
				array_init(&_128$$89);
				zephir_update_property_array(this_ptr, SL("hostnameByMethod"), &method, &_128$$89);
				ZEPHIR_INIT_NVAR(&_129$$89);
				array_init(&_129$$89);
				zephir_update_property_array(this_ptr, SL("hostnameLessByMethod"), &method, &_129$$89);
				zephir_is_iterable(&candidates, 0, "phalcon/Mvc/Router.zep", 2331);
				if (Z_TYPE_P(&candidates) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&candidates), _131$$89, _132$$89, _130$$89)
					{
						ZEPHIR_INIT_NVAR(&bucketIdx);
						if (_132$$89 != NULL) { 
							ZVAL_STR_COPY(&bucketIdx, _132$$89);
						} else {
							ZVAL_LONG(&bucketIdx, _131$$89);
						}
						ZEPHIR_INIT_NVAR(&bucketRoute);
						ZVAL_COPY(&bucketRoute, _130$$89);
						ZEPHIR_CALL_METHOD(&bucketHostname, &bucketRoute, "gethostname", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&bucketHostname) == IS_NULL) {
							zephir_update_property_array_multi(this_ptr, SL("hostnameLessByMethod"), &bucketIdx, SL("za"), 2, &method);
						} else {
							zephir_update_property_array_multi(this_ptr, SL("hostnameByMethod"), &bucketIdx, SL("zza"), 3, &method, &bucketHostname);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &candidates, "rewind", NULL, 0);
					zephir_check_call_status();
					_134$$89 = 1;
					while (1) {
						if (_134$$89) {
							_134$$89 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &candidates, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_133$$89, &candidates, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_133$$89)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&bucketIdx, &candidates, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&bucketRoute, &candidates, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&bucketHostname, &bucketRoute, "gethostname", NULL, 0);
							zephir_check_call_status();
							if (Z_TYPE_P(&bucketHostname) == IS_NULL) {
								zephir_update_property_array_multi(this_ptr, SL("hostnameLessByMethod"), &bucketIdx, SL("za"), 2, &method);
							} else {
								zephir_update_property_array_multi(this_ptr, SL("hostnameByMethod"), &bucketIdx, SL("zza"), 3, &method, &bucketHostname);
							}
					}
				}
				ZEPHIR_INIT_NVAR(&bucketRoute);
				ZEPHIR_INIT_NVAR(&bucketIdx);
		}
	}
	ZEPHIR_INIT_NVAR(&candidates);
	ZEPHIR_INIT_NVAR(&method);
	ZEPHIR_INIT_VAR(&_135);
	array_init(&_135);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 291, &_135);
	ZEPHIR_INIT_VAR(&_136);
	array_init(&_136);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 293, &_136);
	ZEPHIR_INIT_VAR(&_137);
	array_init(&_137);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 292, &_137);
	zephir_read_property_cached(&_138, this_ptr, _zephir_prop_1, 285, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_138, 0, "phalcon/Mvc/Router.zep", 2422);
	if (Z_TYPE_P(&_138) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_138), _140, _141, _139)
		{
			ZEPHIR_INIT_NVAR(&method);
			if (_141 != NULL) { 
				ZVAL_STR_COPY(&method, _141);
			} else {
				ZVAL_LONG(&method, _140);
			}
			ZEPHIR_INIT_NVAR(&candidates);
			ZVAL_COPY(&candidates, _139);
			zephir_read_property_cached(&_142$$96, this_ptr, _zephir_prop_6, 289, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&hostnameBucketRef);
			zephir_array_fetch(&hostnameBucketRef, &_142$$96, &method, PH_NOISY, "phalcon/Mvc/Router.zep", 2348);
			if (!(ZEPHIR_IS_EMPTY(&hostnameBucketRef))) {
				zephir_update_property_array(this_ptr, SL("combinedRegexDisabled"), &method, &__$true);
				continue;
			}
			ZEPHIR_INIT_NVAR(&combinedAlternatives);
			array_init(&combinedAlternatives);
			ZEPHIR_INIT_NVAR(&combinedMark);
			array_init(&combinedMark);
			zephir_is_iterable(&candidates, 0, "phalcon/Mvc/Router.zep", 2379);
			if (Z_TYPE_P(&candidates) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&candidates), _144$$96, _145$$96, _143$$96)
				{
					ZEPHIR_INIT_NVAR(&bucketIdx);
					if (_145$$96 != NULL) { 
						ZVAL_STR_COPY(&bucketIdx, _145$$96);
					} else {
						ZVAL_LONG(&bucketIdx, _144$$96);
					}
					ZEPHIR_INIT_NVAR(&bucketRoute);
					ZVAL_COPY(&bucketRoute, _143$$96);
					ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2361))) {
						continue;
					}
					ZEPHIR_INIT_NVAR(&combinedBodyMatch);
					array_init(&combinedBodyMatch);
					ZEPHIR_INIT_NVAR(&_146$$98);
					ZVAL_STRING(&_146$$98, "/^#\\^(.+)\\$#u$/");
					ZEPHIR_INIT_NVAR(&_147$$98);
					ZVAL_STRING(&_147$$98, "/^#\\^(.+)\\$#u$/");
					ZEPHIR_INIT_NVAR(&combinedShape);
					zephir_preg_match(&combinedShape, &_147$$98, &bucketPattern, &combinedBodyMatch, 0, 0 , 0 );
					if (!(zephir_is_true(&combinedShape))) {
						zephir_update_property_array(this_ptr, SL("combinedRegexDisabled"), &method, &__$true);
						ZEPHIR_INIT_NVAR(&combinedAlternatives);
						array_init(&combinedAlternatives);
						break;
					}
					ZEPHIR_OBS_NVAR(&combinedBody);
					zephir_array_fetch_long(&combinedBody, &combinedBodyMatch, 1, PH_NOISY, "phalcon/Mvc/Router.zep", 2374);
					ZEPHIR_INIT_NVAR(&_148$$98);
					ZEPHIR_CONCAT_VSVS(&_148$$98, &combinedBody, "(*:", &bucketIdx, ")");
					zephir_array_append(&combinedAlternatives, &_148$$98, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2375);
					zephir_cast_to_string(&_149$$98, &bucketIdx);
					zephir_array_update_zval(&combinedMark, &_149$$98, &bucketIdx, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &candidates, "rewind", NULL, 0);
				zephir_check_call_status();
				_151$$96 = 1;
				while (1) {
					if (_151$$96) {
						_151$$96 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &candidates, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_150$$96, &candidates, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_150$$96)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&bucketIdx, &candidates, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&bucketRoute, &candidates, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2361))) {
							continue;
						}
						ZEPHIR_INIT_NVAR(&combinedBodyMatch);
						array_init(&combinedBodyMatch);
						ZEPHIR_INIT_NVAR(&_152$$101);
						ZVAL_STRING(&_152$$101, "/^#\\^(.+)\\$#u$/");
						ZEPHIR_INIT_NVAR(&_153$$101);
						ZVAL_STRING(&_153$$101, "/^#\\^(.+)\\$#u$/");
						ZEPHIR_INIT_NVAR(&combinedShape);
						zephir_preg_match(&combinedShape, &_153$$101, &bucketPattern, &combinedBodyMatch, 0, 0 , 0 );
						if (!(zephir_is_true(&combinedShape))) {
							zephir_update_property_array(this_ptr, SL("combinedRegexDisabled"), &method, &__$true);
							ZEPHIR_INIT_NVAR(&combinedAlternatives);
							array_init(&combinedAlternatives);
							break;
						}
						ZEPHIR_OBS_NVAR(&combinedBody);
						zephir_array_fetch_long(&combinedBody, &combinedBodyMatch, 1, PH_NOISY, "phalcon/Mvc/Router.zep", 2374);
						ZEPHIR_INIT_NVAR(&_154$$101);
						ZEPHIR_CONCAT_VSVS(&_154$$101, &combinedBody, "(*:", &bucketIdx, ")");
						zephir_array_append(&combinedAlternatives, &_154$$101, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2375);
						zephir_cast_to_string(&_155$$101, &bucketIdx);
						zephir_array_update_zval(&combinedMark, &_155$$101, &bucketIdx, PH_COPY | PH_SEPARATE);
				}
			}
			ZEPHIR_INIT_NVAR(&bucketRoute);
			ZEPHIR_INIT_NVAR(&bucketIdx);
			zephir_read_property_cached(&_156$$96, this_ptr, _zephir_prop_10, 292, PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset_value(&_156$$96, &method)) {
				continue;
			}
			if (ZEPHIR_IS_EMPTY(&combinedAlternatives)) {
				continue;
			}
			ZEPHIR_CALL_FUNCTION(&_157$$96, "array_reverse", &_158, 271, &combinedAlternatives);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&combinedAlternatives, &_157$$96);
			ZEPHIR_INIT_NVAR(&_159$$96);
			zephir_array_keys(&_159$$96, &combinedMark);
			ZEPHIR_CALL_FUNCTION(&reversedMarkIds$$96, "array_reverse", &_158, 271, &_159$$96);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&reversedMarkIds$$96, &reversedMarkIds$$96);
			ZEPHIR_INIT_NVAR(&chunkedPatterns$$96);
			array_init(&chunkedPatterns$$96);
			ZEPHIR_CPY_WRT(&chunkedPatterns$$96, &chunkedPatterns$$96);
			ZEPHIR_INIT_NVAR(&chunkedMarkMaps$$96);
			array_init(&chunkedMarkMaps$$96);
			ZEPHIR_CPY_WRT(&chunkedMarkMaps$$96, &chunkedMarkMaps$$96);
			ZEPHIR_INIT_NVAR(&chunkOffset$$96);
			ZVAL_LONG(&chunkOffset$$96, 0);
			while (1) {
				if (!(ZEPHIR_LT_LONG(&chunkOffset$$96, zephir_fast_count_int(&combinedAlternatives)))) {
					break;
				}
				ZVAL_LONG(&_160$$106, 10);
				ZEPHIR_CALL_FUNCTION(&chunkSlice$$96, "array_slice", &_161, 280, &combinedAlternatives, &chunkOffset$$96, &_160$$106);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&chunkSlice$$96, &chunkSlice$$96);
				ZVAL_LONG(&_160$$106, 10);
				ZEPHIR_CALL_FUNCTION(&chunkMarkSubset$$96, "array_slice", &_161, 280, &reversedMarkIds$$96, &chunkOffset$$96, &_160$$106);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&chunkMarkSubset$$96, &chunkMarkSubset$$96);
				ZEPHIR_INIT_NVAR(&chunkSliceMap$$96);
				array_init(&chunkSliceMap$$96);
				ZEPHIR_CPY_WRT(&chunkSliceMap$$96, &chunkSliceMap$$96);
				zephir_is_iterable(&chunkMarkSubset$$96, 0, "phalcon/Mvc/Router.zep", 2413);
				if (Z_TYPE_P(&chunkMarkSubset$$96) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&chunkMarkSubset$$96), _162$$106)
					{
						ZEPHIR_INIT_NVAR(&chunkMarkId$$96);
						ZVAL_COPY(&chunkMarkId$$96, _162$$106);
						zephir_array_fetch(&_163$$107, &combinedMark, &chunkMarkId$$96, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2410);
						zephir_array_update_zval(&chunkSliceMap$$96, &chunkMarkId$$96, &_163$$107, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &chunkMarkSubset$$96, "rewind", NULL, 0);
					zephir_check_call_status();
					_165$$106 = 1;
					while (1) {
						if (_165$$106) {
							_165$$106 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &chunkMarkSubset$$96, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_164$$106, &chunkMarkSubset$$96, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_164$$106)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&chunkMarkId$$96, &chunkMarkSubset$$96, "current", NULL, 0);
						zephir_check_call_status();
							zephir_array_fetch(&_166$$108, &combinedMark, &chunkMarkId$$96, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2410);
							zephir_array_update_zval(&chunkSliceMap$$96, &chunkMarkId$$96, &_166$$108, PH_COPY | PH_SEPARATE);
					}
				}
				ZEPHIR_INIT_NVAR(&chunkMarkId$$96);
				ZEPHIR_INIT_NVAR(&_167$$106);
				zephir_fast_join_str(&_167$$106, SL("|"), &chunkSlice$$96);
				ZEPHIR_INIT_NVAR(&_168$$106);
				ZEPHIR_CONCAT_SVS(&_168$$106, "#^(?|", &_167$$106, ")$#u");
				zephir_array_append(&chunkedPatterns$$96, &_168$$106, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2413);
				zephir_array_append(&chunkedMarkMaps$$96, &chunkSliceMap$$96, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2414);
				ZEPHIR_INIT_NVAR(&_169$$106);
				ZVAL_LONG(&_169$$106, 10);
				ZEPHIR_ADD_ASSIGN(&chunkOffset$$96, &_169$$106);
			}
			zephir_update_property_array(this_ptr, SL("combinedRegexByMethod"), &method, &chunkedPatterns$$96);
			zephir_update_property_array(this_ptr, SL("combinedRegexMarkMap"), &method, &chunkedMarkMaps$$96);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_138, "rewind", NULL, 0);
		zephir_check_call_status();
		_171 = 1;
		while (1) {
			if (_171) {
				_171 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_138, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_170, &_138, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_170)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, &_138, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&candidates, &_138, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property_cached(&_172$$109, this_ptr, _zephir_prop_6, 289, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&hostnameBucketRef);
				zephir_array_fetch(&hostnameBucketRef, &_172$$109, &method, PH_NOISY, "phalcon/Mvc/Router.zep", 2348);
				if (!(ZEPHIR_IS_EMPTY(&hostnameBucketRef))) {
					zephir_update_property_array(this_ptr, SL("combinedRegexDisabled"), &method, &__$true);
					continue;
				}
				ZEPHIR_INIT_NVAR(&combinedAlternatives);
				array_init(&combinedAlternatives);
				ZEPHIR_INIT_NVAR(&combinedMark);
				array_init(&combinedMark);
				zephir_is_iterable(&candidates, 0, "phalcon/Mvc/Router.zep", 2379);
				if (Z_TYPE_P(&candidates) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&candidates), _174$$109, _175$$109, _173$$109)
					{
						ZEPHIR_INIT_NVAR(&bucketIdx);
						if (_175$$109 != NULL) { 
							ZVAL_STR_COPY(&bucketIdx, _175$$109);
						} else {
							ZVAL_LONG(&bucketIdx, _174$$109);
						}
						ZEPHIR_INIT_NVAR(&bucketRoute);
						ZVAL_COPY(&bucketRoute, _173$$109);
						ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2361))) {
							continue;
						}
						ZEPHIR_INIT_NVAR(&combinedBodyMatch);
						array_init(&combinedBodyMatch);
						ZEPHIR_INIT_NVAR(&_176$$111);
						ZVAL_STRING(&_176$$111, "/^#\\^(.+)\\$#u$/");
						ZEPHIR_INIT_NVAR(&_177$$111);
						ZVAL_STRING(&_177$$111, "/^#\\^(.+)\\$#u$/");
						ZEPHIR_INIT_NVAR(&combinedShape);
						zephir_preg_match(&combinedShape, &_177$$111, &bucketPattern, &combinedBodyMatch, 0, 0 , 0 );
						if (!(zephir_is_true(&combinedShape))) {
							zephir_update_property_array(this_ptr, SL("combinedRegexDisabled"), &method, &__$true);
							ZEPHIR_INIT_NVAR(&combinedAlternatives);
							array_init(&combinedAlternatives);
							break;
						}
						ZEPHIR_OBS_NVAR(&combinedBody);
						zephir_array_fetch_long(&combinedBody, &combinedBodyMatch, 1, PH_NOISY, "phalcon/Mvc/Router.zep", 2374);
						ZEPHIR_INIT_NVAR(&_178$$111);
						ZEPHIR_CONCAT_VSVS(&_178$$111, &combinedBody, "(*:", &bucketIdx, ")");
						zephir_array_append(&combinedAlternatives, &_178$$111, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2375);
						zephir_cast_to_string(&_179$$111, &bucketIdx);
						zephir_array_update_zval(&combinedMark, &_179$$111, &bucketIdx, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &candidates, "rewind", NULL, 0);
					zephir_check_call_status();
					_181$$109 = 1;
					while (1) {
						if (_181$$109) {
							_181$$109 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &candidates, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_180$$109, &candidates, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_180$$109)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&bucketIdx, &candidates, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&bucketRoute, &candidates, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
							zephir_check_call_status();
							if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2361))) {
								continue;
							}
							ZEPHIR_INIT_NVAR(&combinedBodyMatch);
							array_init(&combinedBodyMatch);
							ZEPHIR_INIT_NVAR(&_182$$114);
							ZVAL_STRING(&_182$$114, "/^#\\^(.+)\\$#u$/");
							ZEPHIR_INIT_NVAR(&_183$$114);
							ZVAL_STRING(&_183$$114, "/^#\\^(.+)\\$#u$/");
							ZEPHIR_INIT_NVAR(&combinedShape);
							zephir_preg_match(&combinedShape, &_183$$114, &bucketPattern, &combinedBodyMatch, 0, 0 , 0 );
							if (!(zephir_is_true(&combinedShape))) {
								zephir_update_property_array(this_ptr, SL("combinedRegexDisabled"), &method, &__$true);
								ZEPHIR_INIT_NVAR(&combinedAlternatives);
								array_init(&combinedAlternatives);
								break;
							}
							ZEPHIR_OBS_NVAR(&combinedBody);
							zephir_array_fetch_long(&combinedBody, &combinedBodyMatch, 1, PH_NOISY, "phalcon/Mvc/Router.zep", 2374);
							ZEPHIR_INIT_NVAR(&_184$$114);
							ZEPHIR_CONCAT_VSVS(&_184$$114, &combinedBody, "(*:", &bucketIdx, ")");
							zephir_array_append(&combinedAlternatives, &_184$$114, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2375);
							zephir_cast_to_string(&_185$$114, &bucketIdx);
							zephir_array_update_zval(&combinedMark, &_185$$114, &bucketIdx, PH_COPY | PH_SEPARATE);
					}
				}
				ZEPHIR_INIT_NVAR(&bucketRoute);
				ZEPHIR_INIT_NVAR(&bucketIdx);
				zephir_read_property_cached(&_186$$109, this_ptr, _zephir_prop_10, 292, PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset_value(&_186$$109, &method)) {
					continue;
				}
				if (ZEPHIR_IS_EMPTY(&combinedAlternatives)) {
					continue;
				}
				ZEPHIR_CALL_FUNCTION(&_187$$109, "array_reverse", &_158, 271, &combinedAlternatives);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&combinedAlternatives, &_187$$109);
				ZEPHIR_INIT_NVAR(&_188$$109);
				zephir_array_keys(&_188$$109, &combinedMark);
				ZEPHIR_CALL_FUNCTION(&reversedMarkIds$$109, "array_reverse", &_158, 271, &_188$$109);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&reversedMarkIds$$109, &reversedMarkIds$$109);
				ZEPHIR_INIT_NVAR(&chunkedPatterns$$109);
				array_init(&chunkedPatterns$$109);
				ZEPHIR_CPY_WRT(&chunkedPatterns$$109, &chunkedPatterns$$109);
				ZEPHIR_INIT_NVAR(&chunkedMarkMaps$$109);
				array_init(&chunkedMarkMaps$$109);
				ZEPHIR_CPY_WRT(&chunkedMarkMaps$$109, &chunkedMarkMaps$$109);
				ZEPHIR_INIT_NVAR(&chunkOffset$$109);
				ZVAL_LONG(&chunkOffset$$109, 0);
				while (1) {
					if (!(ZEPHIR_LT_LONG(&chunkOffset$$109, zephir_fast_count_int(&combinedAlternatives)))) {
						break;
					}
					ZVAL_LONG(&_189$$119, 10);
					ZEPHIR_CALL_FUNCTION(&chunkSlice$$109, "array_slice", &_161, 280, &combinedAlternatives, &chunkOffset$$109, &_189$$119);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&chunkSlice$$109, &chunkSlice$$109);
					ZVAL_LONG(&_189$$119, 10);
					ZEPHIR_CALL_FUNCTION(&chunkMarkSubset$$109, "array_slice", &_161, 280, &reversedMarkIds$$109, &chunkOffset$$109, &_189$$119);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&chunkMarkSubset$$109, &chunkMarkSubset$$109);
					ZEPHIR_INIT_NVAR(&chunkSliceMap$$109);
					array_init(&chunkSliceMap$$109);
					ZEPHIR_CPY_WRT(&chunkSliceMap$$109, &chunkSliceMap$$109);
					zephir_is_iterable(&chunkMarkSubset$$109, 0, "phalcon/Mvc/Router.zep", 2413);
					if (Z_TYPE_P(&chunkMarkSubset$$109) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&chunkMarkSubset$$109), _190$$119)
						{
							ZEPHIR_INIT_NVAR(&chunkMarkId$$109);
							ZVAL_COPY(&chunkMarkId$$109, _190$$119);
							zephir_array_fetch(&_191$$120, &combinedMark, &chunkMarkId$$109, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2410);
							zephir_array_update_zval(&chunkSliceMap$$109, &chunkMarkId$$109, &_191$$120, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &chunkMarkSubset$$109, "rewind", NULL, 0);
						zephir_check_call_status();
						_193$$119 = 1;
						while (1) {
							if (_193$$119) {
								_193$$119 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &chunkMarkSubset$$109, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_192$$119, &chunkMarkSubset$$109, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_192$$119)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&chunkMarkId$$109, &chunkMarkSubset$$109, "current", NULL, 0);
							zephir_check_call_status();
								zephir_array_fetch(&_194$$121, &combinedMark, &chunkMarkId$$109, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2410);
								zephir_array_update_zval(&chunkSliceMap$$109, &chunkMarkId$$109, &_194$$121, PH_COPY | PH_SEPARATE);
						}
					}
					ZEPHIR_INIT_NVAR(&chunkMarkId$$109);
					ZEPHIR_INIT_NVAR(&_195$$119);
					zephir_fast_join_str(&_195$$119, SL("|"), &chunkSlice$$109);
					ZEPHIR_INIT_NVAR(&_196$$119);
					ZEPHIR_CONCAT_SVS(&_196$$119, "#^(?|", &_195$$119, ")$#u");
					zephir_array_append(&chunkedPatterns$$109, &_196$$119, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2413);
					zephir_array_append(&chunkedMarkMaps$$109, &chunkSliceMap$$109, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2414);
					ZEPHIR_INIT_NVAR(&_197$$119);
					ZVAL_LONG(&_197$$119, 10);
					ZEPHIR_ADD_ASSIGN(&chunkOffset$$109, &_197$$119);
				}
				zephir_update_property_array(this_ptr, SL("combinedRegexByMethod"), &method, &chunkedPatterns$$109);
				zephir_update_property_array(this_ptr, SL("combinedRegexMarkMap"), &method, &chunkedMarkMaps$$109);
		}
	}
	ZEPHIR_INIT_NVAR(&candidates);
	ZEPHIR_INIT_NVAR(&method);
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 283, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 283, &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Closes an open file pointer
 *
 * @link https://php.net/manual/en/function.fclose.php
 *
 * @param resource $handle
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Router, phpFclose)
{
	zval *handle, handle_sub;

	ZVAL_UNDEF(&handle_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle);
	RETURN_BOOL(zephir_fclose(handle));
}

/**
 * Gets line from file pointer and parse for CSV fields
 *
 * @param resource $stream
 * @param int      $length
 * @param string   $separator
 * @param string   $enclosure
 * @param string   $escape
 *
 * @return array<array-key, mixed>|false
 *
 * @link https://php.net/manual/en/function.fgetcsv.php
 */
PHP_METHOD(Phalcon_Mvc_Router, phpFgetCsv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *separator = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *length_param = NULL, separator_zv, *enclosure = NULL, enclosure_sub, *escape = NULL, escape_sub, __$null, _0;

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&enclosure_sub);
	ZVAL_UNDEF(&escape_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_ZVAL(stream)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(length)
		Z_PARAM_STR(separator)
		Z_PARAM_ZVAL_OR_NULL(enclosure)
		Z_PARAM_ZVAL_OR_NULL(escape)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	stream = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 1) {
		length_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 3) {
		enclosure = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		escape = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (!separator) {
		separator = zend_string_init(ZEND_STRL(","), 0);
		zephir_memory_observe(&separator_zv);
		ZVAL_STR(&separator_zv, separator);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	if (!enclosure) {
		enclosure = &enclosure_sub;
		ZEPHIR_CPY_WRT(enclosure, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(enclosure);
	}
	if (!escape) {
		escape = &escape_sub;
		ZEPHIR_CPY_WRT(escape, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(escape);
	}
	if (Z_TYPE_P(enclosure) == IS_NULL) {
		ZEPHIR_INIT_NVAR(enclosure);
		ZVAL_STRING(enclosure, "\"");
	}
	if (Z_TYPE_P(escape) == IS_NULL) {
		ZEPHIR_INIT_NVAR(escape);
		ZVAL_STRING(escape, "\\");
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 161, stream, &_0, &separator_zv, enclosure, escape);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.file-exists.php
 */
PHP_METHOD(Phalcon_Mvc_Router, phpFileExists)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	RETURN_BOOL((zephir_file_exists(&filename_zv) == SUCCESS));
}

/**
 * @param string        $filename
 * @param bool          $useIncludePath
 * @param resource|null $context
 * @param int           $offset
 * @param int|null      $length
 *
 * @return false|string
 *
 * @link https://php.net/manual/en/function.file-get-contents.php
 */
PHP_METHOD(Phalcon_Mvc_Router, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offset, length, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _2, _3, _4;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		context = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		offset_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		length_param = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!offset_param) {
		offset = 0;
	} else {
		}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 162, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_2, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 162, &filename_zv, &_2, context, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string   $filename
 * @param mixed    $data
 * @param int      $flags
 * @param resource $context
 *
 * @return false|int
 *
 * @link https://php.net/manual/en/function.file-put-contents.php
 */
PHP_METHOD(Phalcon_Mvc_Router, phpFilePutContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *data, data_sub, *flags_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		flags_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!flags_param) {
		flags = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 163, &filename_zv, data, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param string        $mode
 * @param bool          $useIncludePath
 * @param resource|null $context
 *
 * @return resource|false
 *
 * @link https://php.net/manual/en/function.fopen.php
 */
PHP_METHOD(Phalcon_Mvc_Router, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, mode_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL, *mode = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&mode_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	zephir_memory_observe(&mode_zv);
	ZVAL_STR_COPY(&mode_zv, mode);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_BOOL(&_0, (useIncludePath ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 164, &filename_zv, &mode_zv, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Binary-safe file write
 *
 * @link https://php.net/manual/en/function.fwrite.php
 *
 * @param resource $handle
 * @param string   $data
 * @param int|null $length
 *
 * @return false|int
 */
PHP_METHOD(Phalcon_Mvc_Router, phpFwrite)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zend_string *data = NULL;
	zval *handle, handle_sub, data_zv, *length_param = NULL, _0;

	ZVAL_UNDEF(&handle_sub);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(handle)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handle = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		length_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 165, handle, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is writable
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-writable.php
 */
PHP_METHOD(Phalcon_Mvc_Router, phpIsWritable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 166, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.unlink.php
 */
PHP_METHOD(Phalcon_Mvc_Router, phpUnlink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *context = NULL, context_sub, __$null;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 167, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Mvc_Router(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _12, _14, _16, _18, _20, _22, _24, _26, _28, _30, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9, _15$$10, _17$$11, _19$$12, _21$$13, _23$$14, _25$$15, _27$$16, _29$$17, _31$$18;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_29$$17);
	ZVAL_UNDEF(&_31$$18);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("staticShadowedByMethod"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("staticShadowedByMethod"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("staticByMethod"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("staticByMethod"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("routes"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("params"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("methodRoutes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("methodRoutes"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("matches"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("matches"), &_11$$8);
		}
		zephir_read_property_ex(&_12, this_ptr, ZEND_STRL("keyRouteIds"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("keyRouteIds"), &_13$$9);
		}
		zephir_read_property_ex(&_14, this_ptr, ZEND_STRL("keyRouteNames"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_14) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_15$$10);
			array_init(&_15$$10);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("keyRouteNames"), &_15$$10);
		}
		zephir_read_property_ex(&_16, this_ptr, ZEND_STRL("hostnameLessByMethod"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_16) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_17$$11);
			array_init(&_17$$11);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("hostnameLessByMethod"), &_17$$11);
		}
		zephir_read_property_ex(&_18, this_ptr, ZEND_STRL("hostnameByMethod"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_18) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_19$$12);
			array_init(&_19$$12);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("hostnameByMethod"), &_19$$12);
		}
		zephir_read_property_ex(&_20, this_ptr, ZEND_STRL("defaultParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_20) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_21$$13);
			array_init(&_21$$13);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("defaultParams"), &_21$$13);
		}
		zephir_read_property_ex(&_22, this_ptr, ZEND_STRL("combinedRegexMarkMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_22) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_23$$14);
			array_init(&_23$$14);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("combinedRegexMarkMap"), &_23$$14);
		}
		zephir_read_property_ex(&_24, this_ptr, ZEND_STRL("combinedRegexDisabled"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_24) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_25$$15);
			array_init(&_25$$15);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("combinedRegexDisabled"), &_25$$15);
		}
		zephir_read_property_ex(&_26, this_ptr, ZEND_STRL("combinedRegexByMethod"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_26) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_27$$16);
			array_init(&_27$$16);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("combinedRegexByMethod"), &_27$$16);
		}
		zephir_read_property_ex(&_28, this_ptr, ZEND_STRL("routeMeta"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_28) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_29$$17);
			array_init(&_29$$17);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("routeMeta"), &_29$$17);
		}
		zephir_read_property_ex(&_30, this_ptr, ZEND_STRL("candidatesByMethod"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_30) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_31$$18);
			array_init(&_31$$18);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("candidatesByMethod"), &_31$$18);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

