
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
#include "Zend/zend_closures.h"
#include "kernel/concat.h"
#include "kernel/variables.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/string.h"


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
	 * The "*" key itself holds only the no-constraint routes — used when the
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
	 * route — the fast path MUST NOT be used; fall through to the dynamic
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
	 * (FastRoute uses ~10) — keeps each chunk below PCRE's optimizer cliff.
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 182, &_2$$3, &_1$$3);
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
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 182, &_4$$3, &_3$$3);
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
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 182, &pattern_zv, paths, httpMethods);
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
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_router_exceptions_invalidrouteposition_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 183);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Router.zep", 669);
		ZEPHIR_MM_RESTORE();
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("routes"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutes"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("candidatesByMethod"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval(this_ptr, ZEND_STRL("routeMeta"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	zephir_update_property_zval(this_ptr, ZEND_STRL("staticByMethod"), &_4);
	ZEPHIR_INIT_VAR(&_5);
	array_init(&_5);
	zephir_update_property_zval(this_ptr, ZEND_STRL("staticShadowedByMethod"), &_5);
	ZEPHIR_INIT_VAR(&_6);
	array_init(&_6);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hostnameByMethod"), &_6);
	ZEPHIR_INIT_VAR(&_7);
	array_init(&_7);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hostnameLessByMethod"), &_7);
	ZEPHIR_INIT_VAR(&_8);
	array_init(&_8);
	zephir_update_property_zval(this_ptr, ZEND_STRL("combinedRegexByMethod"), &_8);
	ZEPHIR_INIT_VAR(&_9);
	array_init(&_9);
	zephir_update_property_zval(this_ptr, ZEND_STRL("combinedRegexDisabled"), &_9);
	ZEPHIR_INIT_VAR(&_10);
	array_init(&_10);
	zephir_update_property_zval(this_ptr, ZEND_STRL("combinedRegexMarkMap"), &_10);
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutesDirty"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutesDirty"), &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Produces a pure-data array describing every piece of state needed
 * to reconstruct this router. The returned array is var_export-able
 * (no objects, no closures). Used by dumpDispatcher() and by
 * Phalcon\Cache integration via useCache().
 *
 * Throws when a route has a Closure beforeMatch or converter — those
 * cannot be cached.
 *
 * @throws \Phalcon\Mvc\Router\Exception
 */
PHP_METHOD(Phalcon_Mvc_Router, buildDispatcherDump)
{
	zval _24$$4, _45$$11;
	zend_bool _7$$4, _29$$11;
	zend_string *_4, *_51, *_68, *_85, *_14$$6, *_35$$13, *_89$$30, *_107$$37;
	zend_ulong _3, _50, _67, _84, _13$$6, _34$$13, _88$$30, _106$$37;
	zval route, cb, converters, convName, converter, dumpedRoutes, routeToIdx, scalarIdx, scalarSubKey, scalarVal, methodRoutesScalar, candidatesScalar, staticScalar, innerKey, innerVal, mostInnerVal, mostInnerArr, _0, _1, *_2, _27, _48, *_49, _58, _65, *_66, _75, _82, *_83, _103, _121, _5$$4, _25$$4, _26$$4, _8$$5, _9$$5, _10$$5, *_12$$6, _19$$6, _15$$8, _16$$8, _18$$8, _20$$10, _21$$10, _23$$10, _28$$11, _46$$11, _47$$11, _30$$12, _31$$12, _32$$12, *_33$$13, _40$$13, _36$$15, _37$$15, _39$$15, _41$$17, _42$$17, _44$$17, *_52$$18, _55$$18, _53$$19, _54$$19, _56$$20, _57$$20, *_59$$21, _62$$21, _60$$22, _61$$22, _63$$23, _64$$23, *_69$$24, _72$$24, _70$$25, _71$$25, _73$$26, _74$$26, *_76$$27, _79$$27, _77$$28, _78$$28, _80$$29, _81$$29, _86$$30, *_87$$30, _96$$30, *_90$$31, _93$$31, _91$$32, _92$$32, _94$$33, _95$$33, *_97$$34, _100$$34, _98$$35, _99$$35, _101$$36, _102$$36, _104$$37, *_105$$37, _114$$37, *_108$$38, _111$$38, _109$$39, _110$$39, _112$$40, _113$$40, *_115$$41, _118$$41, _116$$42, _117$$42, _119$$43, _120$$43;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_11 = NULL, *_17 = NULL, *_22 = NULL, *_38 = NULL, *_43 = NULL;
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
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_58);
	ZVAL_UNDEF(&_65);
	ZVAL_UNDEF(&_75);
	ZVAL_UNDEF(&_82);
	ZVAL_UNDEF(&_103);
	ZVAL_UNDEF(&_121);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_26$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_46$$11);
	ZVAL_UNDEF(&_47$$11);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_40$$13);
	ZVAL_UNDEF(&_36$$15);
	ZVAL_UNDEF(&_37$$15);
	ZVAL_UNDEF(&_39$$15);
	ZVAL_UNDEF(&_41$$17);
	ZVAL_UNDEF(&_42$$17);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_55$$18);
	ZVAL_UNDEF(&_53$$19);
	ZVAL_UNDEF(&_54$$19);
	ZVAL_UNDEF(&_56$$20);
	ZVAL_UNDEF(&_57$$20);
	ZVAL_UNDEF(&_62$$21);
	ZVAL_UNDEF(&_60$$22);
	ZVAL_UNDEF(&_61$$22);
	ZVAL_UNDEF(&_63$$23);
	ZVAL_UNDEF(&_64$$23);
	ZVAL_UNDEF(&_72$$24);
	ZVAL_UNDEF(&_70$$25);
	ZVAL_UNDEF(&_71$$25);
	ZVAL_UNDEF(&_73$$26);
	ZVAL_UNDEF(&_74$$26);
	ZVAL_UNDEF(&_79$$27);
	ZVAL_UNDEF(&_77$$28);
	ZVAL_UNDEF(&_78$$28);
	ZVAL_UNDEF(&_80$$29);
	ZVAL_UNDEF(&_81$$29);
	ZVAL_UNDEF(&_86$$30);
	ZVAL_UNDEF(&_96$$30);
	ZVAL_UNDEF(&_93$$31);
	ZVAL_UNDEF(&_91$$32);
	ZVAL_UNDEF(&_92$$32);
	ZVAL_UNDEF(&_94$$33);
	ZVAL_UNDEF(&_95$$33);
	ZVAL_UNDEF(&_100$$34);
	ZVAL_UNDEF(&_98$$35);
	ZVAL_UNDEF(&_99$$35);
	ZVAL_UNDEF(&_101$$36);
	ZVAL_UNDEF(&_102$$36);
	ZVAL_UNDEF(&_104$$37);
	ZVAL_UNDEF(&_114$$37);
	ZVAL_UNDEF(&_111$$38);
	ZVAL_UNDEF(&_109$$39);
	ZVAL_UNDEF(&_110$$39);
	ZVAL_UNDEF(&_112$$40);
	ZVAL_UNDEF(&_113$$40);
	ZVAL_UNDEF(&_118$$41);
	ZVAL_UNDEF(&_116$$42);
	ZVAL_UNDEF(&_117$$42);
	ZVAL_UNDEF(&_119$$43);
	ZVAL_UNDEF(&_120$$43);
	ZVAL_UNDEF(&_24$$4);
	ZVAL_UNDEF(&_45$$11);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("methodRoutesDirty"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rebuildmethodindex", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&dumpedRoutes);
	array_init(&dumpedRoutes);
	ZEPHIR_INIT_VAR(&routeToIdx);
	array_init(&routeToIdx);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_1, 0, "phalcon/Mvc/Router.zep", 758);
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
			ZEPHIR_CALL_FUNCTION(&_5$$4, "spl_object_id", &_6, 184, &route);
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
				ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", &_11, 8, &_10$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_8$$5, "phalcon/Mvc/Router.zep", 729);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&converters, &route, "getconverters", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&converters) == IS_ARRAY) {
				zephir_is_iterable(&converters, 0, "phalcon/Mvc/Router.zep", 743);
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
							ZEPHIR_CALL_METHOD(NULL, &_15$$8, "__construct", &_11, 8, &_18$$8);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_15$$8, "phalcon/Mvc/Router.zep", 740);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &converters, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
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
								ZEPHIR_INIT_NVAR(&_20$$10);
								object_init_ex(&_20$$10, phalcon_mvc_router_exception_ce);
								ZEPHIR_CALL_METHOD(&_21$$10, &route, "getrouteid", &_22, 0);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_23$$10);
								ZEPHIR_CONCAT_SVSVS(&_23$$10, "Cannot cache router: route id '", &_21$$10, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
								ZEPHIR_CALL_METHOD(NULL, &_20$$10, "__construct", &_11, 8, &_23$$10);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_20$$10, "phalcon/Mvc/Router.zep", 740);
								ZEPHIR_MM_RESTORE();
								return;
							}
						ZEPHIR_CALL_METHOD(NULL, &converters, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&converter);
				ZEPHIR_INIT_NVAR(&convName);
			}
			ZEPHIR_INIT_NVAR(&_24$$4);
			zephir_create_array(&_24$$4, 9, 0);
			ZEPHIR_INIT_NVAR(&_25$$4);
			zephir_get_class(&_25$$4, &route, 0);
			zephir_array_update_string(&_24$$4, SL("class"), &_25$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_26$$4, &route, "getpattern", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_24$$4, SL("pattern"), &_26$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_26$$4, &route, "getpaths", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_24$$4, SL("paths"), &_26$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_26$$4, &route, "gethttpmethods", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_24$$4, SL("methods"), &_26$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_26$$4, &route, "gethostname", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_24$$4, SL("hostname"), &_26$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_26$$4, &route, "getname", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_24$$4, SL("name"), &_26$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_26$$4, &route, "getrouteid", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_24$$4, SL("id"), &_26$$4, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_24$$4, SL("beforeMatch"), &cb, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_24$$4, SL("converters"), &converters, PH_COPY | PH_SEPARATE);
			zephir_array_append(&dumpedRoutes, &_24$$4, PH_SEPARATE, "phalcon/Mvc/Router.zep", 755);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_27, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_27)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&scalarIdx, &_1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_28$$11, "spl_object_id", &_6, 184, &route);
				zephir_check_call_status();
				zephir_array_update_zval(&routeToIdx, &_28$$11, &scalarIdx, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&cb, &route, "getbeforematch", NULL, 0);
				zephir_check_call_status();
				_29$$11 = Z_TYPE_P(&cb) != IS_NULL;
				if (_29$$11) {
					_29$$11 = zephir_is_instance_of(&cb, SL("Closure"));
				}
				if (_29$$11) {
					ZEPHIR_INIT_NVAR(&_30$$12);
					object_init_ex(&_30$$12, phalcon_mvc_router_exception_ce);
					ZEPHIR_CALL_METHOD(&_31$$12, &route, "getrouteid", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_32$$12);
					ZEPHIR_CONCAT_SVS(&_32$$12, "Cannot cache router: route id '", &_31$$12, "' has a Closure beforeMatch - only string/array callables are cacheable");
					ZEPHIR_CALL_METHOD(NULL, &_30$$12, "__construct", &_11, 8, &_32$$12);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_30$$12, "phalcon/Mvc/Router.zep", 729);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&converters, &route, "getconverters", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&converters) == IS_ARRAY) {
					zephir_is_iterable(&converters, 0, "phalcon/Mvc/Router.zep", 743);
					if (Z_TYPE_P(&converters) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&converters), _34$$13, _35$$13, _33$$13)
						{
							ZEPHIR_INIT_NVAR(&convName);
							if (_35$$13 != NULL) { 
								ZVAL_STR_COPY(&convName, _35$$13);
							} else {
								ZVAL_LONG(&convName, _34$$13);
							}
							ZEPHIR_INIT_NVAR(&converter);
							ZVAL_COPY(&converter, _33$$13);
							if (zephir_is_instance_of(&converter, SL("Closure"))) {
								ZEPHIR_INIT_NVAR(&_36$$15);
								object_init_ex(&_36$$15, phalcon_mvc_router_exception_ce);
								ZEPHIR_CALL_METHOD(&_37$$15, &route, "getrouteid", &_38, 0);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_39$$15);
								ZEPHIR_CONCAT_SVSVS(&_39$$15, "Cannot cache router: route id '", &_37$$15, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
								ZEPHIR_CALL_METHOD(NULL, &_36$$15, "__construct", &_11, 8, &_39$$15);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_36$$15, "phalcon/Mvc/Router.zep", 740);
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &converters, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_40$$13, &converters, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_40$$13)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&convName, &converters, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&converter, &converters, "current", NULL, 0);
							zephir_check_call_status();
								if (zephir_is_instance_of(&converter, SL("Closure"))) {
									ZEPHIR_INIT_NVAR(&_41$$17);
									object_init_ex(&_41$$17, phalcon_mvc_router_exception_ce);
									ZEPHIR_CALL_METHOD(&_42$$17, &route, "getrouteid", &_43, 0);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_44$$17);
									ZEPHIR_CONCAT_SVSVS(&_44$$17, "Cannot cache router: route id '", &_42$$17, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
									ZEPHIR_CALL_METHOD(NULL, &_41$$17, "__construct", &_11, 8, &_44$$17);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_41$$17, "phalcon/Mvc/Router.zep", 740);
									ZEPHIR_MM_RESTORE();
									return;
								}
							ZEPHIR_CALL_METHOD(NULL, &converters, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&converter);
					ZEPHIR_INIT_NVAR(&convName);
				}
				ZEPHIR_INIT_NVAR(&_45$$11);
				zephir_create_array(&_45$$11, 9, 0);
				ZEPHIR_INIT_NVAR(&_46$$11);
				zephir_get_class(&_46$$11, &route, 0);
				zephir_array_update_string(&_45$$11, SL("class"), &_46$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_47$$11, &route, "getpattern", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_45$$11, SL("pattern"), &_47$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_47$$11, &route, "getpaths", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_45$$11, SL("paths"), &_47$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_47$$11, &route, "gethttpmethods", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_45$$11, SL("methods"), &_47$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_47$$11, &route, "gethostname", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_45$$11, SL("hostname"), &_47$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_47$$11, &route, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_45$$11, SL("name"), &_47$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_47$$11, &route, "getrouteid", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_45$$11, SL("id"), &_47$$11, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_45$$11, SL("beforeMatch"), &cb, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_45$$11, SL("converters"), &converters, PH_COPY | PH_SEPARATE);
				zephir_array_append(&dumpedRoutes, &_45$$11, PH_SEPARATE, "phalcon/Mvc/Router.zep", 755);
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&scalarIdx);
	ZEPHIR_INIT_VAR(&methodRoutesScalar);
	array_init(&methodRoutesScalar);
	zephir_read_property(&_48, this_ptr, ZEND_STRL("methodRoutes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_48, 0, "phalcon/Mvc/Router.zep", 767);
	if (Z_TYPE_P(&_48) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_48), _50, _51, _49)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_51 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _51);
			} else {
				ZVAL_LONG(&innerKey, _50);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _49);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 764);
			if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _52$$18)
				{
					ZEPHIR_INIT_NVAR(&scalarVal);
					ZVAL_COPY(&scalarVal, _52$$18);
					ZEPHIR_CALL_FUNCTION(&_54$$19, "spl_object_id", &_6, 184, &scalarVal);
					zephir_check_call_status();
					zephir_array_fetch(&_53$$19, &routeToIdx, &_54$$19, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 762);
					zephir_array_append(&mostInnerArr, &_53$$19, PH_SEPARATE, "phalcon/Mvc/Router.zep", 762);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_55$$18, &innerVal, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_55$$18)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarVal, &innerVal, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_57$$20, "spl_object_id", &_6, 184, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_56$$20, &routeToIdx, &_57$$20, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 762);
						zephir_array_append(&mostInnerArr, &_56$$20, PH_SEPARATE, "phalcon/Mvc/Router.zep", 762);
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&scalarVal);
			zephir_array_update_zval(&methodRoutesScalar, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_48, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_58, &_48, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_58)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, &_48, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, &_48, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 764);
				if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _59$$21)
					{
						ZEPHIR_INIT_NVAR(&scalarVal);
						ZVAL_COPY(&scalarVal, _59$$21);
						ZEPHIR_CALL_FUNCTION(&_61$$22, "spl_object_id", &_6, 184, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_60$$22, &routeToIdx, &_61$$22, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 762);
						zephir_array_append(&mostInnerArr, &_60$$22, PH_SEPARATE, "phalcon/Mvc/Router.zep", 762);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_62$$21, &innerVal, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_62$$21)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarVal, &innerVal, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&_64$$23, "spl_object_id", &_6, 184, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_63$$23, &routeToIdx, &_64$$23, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 762);
							zephir_array_append(&mostInnerArr, &_63$$23, PH_SEPARATE, "phalcon/Mvc/Router.zep", 762);
						ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&scalarVal);
				zephir_array_update_zval(&methodRoutesScalar, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_48, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	ZEPHIR_INIT_VAR(&candidatesScalar);
	array_init(&candidatesScalar);
	zephir_read_property(&_65, this_ptr, ZEND_STRL("candidatesByMethod"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_65, 0, "phalcon/Mvc/Router.zep", 776);
	if (Z_TYPE_P(&_65) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_65), _67, _68, _66)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_68 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _68);
			} else {
				ZVAL_LONG(&innerKey, _67);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _66);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 773);
			if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _69$$24)
				{
					ZEPHIR_INIT_NVAR(&scalarVal);
					ZVAL_COPY(&scalarVal, _69$$24);
					ZEPHIR_CALL_FUNCTION(&_71$$25, "spl_object_id", &_6, 184, &scalarVal);
					zephir_check_call_status();
					zephir_array_fetch(&_70$$25, &routeToIdx, &_71$$25, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 771);
					zephir_array_append(&mostInnerArr, &_70$$25, PH_SEPARATE, "phalcon/Mvc/Router.zep", 771);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_72$$24, &innerVal, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_72$$24)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarVal, &innerVal, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_74$$26, "spl_object_id", &_6, 184, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_73$$26, &routeToIdx, &_74$$26, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 771);
						zephir_array_append(&mostInnerArr, &_73$$26, PH_SEPARATE, "phalcon/Mvc/Router.zep", 771);
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&scalarVal);
			zephir_array_update_zval(&candidatesScalar, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_65, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_75, &_65, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_75)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, &_65, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, &_65, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 773);
				if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _76$$27)
					{
						ZEPHIR_INIT_NVAR(&scalarVal);
						ZVAL_COPY(&scalarVal, _76$$27);
						ZEPHIR_CALL_FUNCTION(&_78$$28, "spl_object_id", &_6, 184, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_77$$28, &routeToIdx, &_78$$28, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 771);
						zephir_array_append(&mostInnerArr, &_77$$28, PH_SEPARATE, "phalcon/Mvc/Router.zep", 771);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_79$$27, &innerVal, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_79$$27)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarVal, &innerVal, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&_81$$29, "spl_object_id", &_6, 184, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_80$$29, &routeToIdx, &_81$$29, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 771);
							zephir_array_append(&mostInnerArr, &_80$$29, PH_SEPARATE, "phalcon/Mvc/Router.zep", 771);
						ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&scalarVal);
				zephir_array_update_zval(&candidatesScalar, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_65, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	ZEPHIR_INIT_VAR(&staticScalar);
	array_init(&staticScalar);
	zephir_read_property(&_82, this_ptr, ZEND_STRL("staticByMethod"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_82, 0, "phalcon/Mvc/Router.zep", 788);
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
			ZEPHIR_INIT_NVAR(&_86$$30);
			array_init(&_86$$30);
			zephir_array_update_zval(&staticScalar, &innerKey, &_86$$30, PH_COPY | PH_SEPARATE);
			zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 786);
			if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&innerVal), _88$$30, _89$$30, _87$$30)
				{
					ZEPHIR_INIT_NVAR(&scalarSubKey);
					if (_89$$30 != NULL) { 
						ZVAL_STR_COPY(&scalarSubKey, _89$$30);
					} else {
						ZVAL_LONG(&scalarSubKey, _88$$30);
					}
					ZEPHIR_INIT_NVAR(&mostInnerVal);
					ZVAL_COPY(&mostInnerVal, _87$$30);
					ZEPHIR_INIT_NVAR(&mostInnerArr);
					array_init(&mostInnerArr);
					zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 784);
					if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _90$$31)
						{
							ZEPHIR_INIT_NVAR(&scalarVal);
							ZVAL_COPY(&scalarVal, _90$$31);
							ZEPHIR_CALL_FUNCTION(&_92$$32, "spl_object_id", &_6, 184, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_91$$32, &routeToIdx, &_92$$32, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 782);
							zephir_array_append(&mostInnerArr, &_91$$32, PH_SEPARATE, "phalcon/Mvc/Router.zep", 782);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_93$$31, &mostInnerVal, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_93$$31)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&scalarVal, &mostInnerVal, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&_95$$33, "spl_object_id", &_6, 184, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_94$$33, &routeToIdx, &_95$$33, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 782);
								zephir_array_append(&mostInnerArr, &_94$$33, PH_SEPARATE, "phalcon/Mvc/Router.zep", 782);
							ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&scalarVal);
					zephir_array_update_multi(&staticScalar, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_96$$30, &innerVal, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_96$$30)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarSubKey, &innerVal, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&mostInnerVal, &innerVal, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 784);
						if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _97$$34)
							{
								ZEPHIR_INIT_NVAR(&scalarVal);
								ZVAL_COPY(&scalarVal, _97$$34);
								ZEPHIR_CALL_FUNCTION(&_99$$35, "spl_object_id", &_6, 184, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_98$$35, &routeToIdx, &_99$$35, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 782);
								zephir_array_append(&mostInnerArr, &_98$$35, PH_SEPARATE, "phalcon/Mvc/Router.zep", 782);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_100$$34, &mostInnerVal, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_100$$34)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarVal, &mostInnerVal, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_102$$36, "spl_object_id", &_6, 184, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_101$$36, &routeToIdx, &_102$$36, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 782);
									zephir_array_append(&mostInnerArr, &_101$$36, PH_SEPARATE, "phalcon/Mvc/Router.zep", 782);
								ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&scalarVal);
						zephir_array_update_multi(&staticScalar, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&mostInnerVal);
			ZEPHIR_INIT_NVAR(&scalarSubKey);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_82, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_103, &_82, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_103)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, &_82, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, &_82, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_104$$37);
				array_init(&_104$$37);
				zephir_array_update_zval(&staticScalar, &innerKey, &_104$$37, PH_COPY | PH_SEPARATE);
				zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 786);
				if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&innerVal), _106$$37, _107$$37, _105$$37)
					{
						ZEPHIR_INIT_NVAR(&scalarSubKey);
						if (_107$$37 != NULL) { 
							ZVAL_STR_COPY(&scalarSubKey, _107$$37);
						} else {
							ZVAL_LONG(&scalarSubKey, _106$$37);
						}
						ZEPHIR_INIT_NVAR(&mostInnerVal);
						ZVAL_COPY(&mostInnerVal, _105$$37);
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 784);
						if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _108$$38)
							{
								ZEPHIR_INIT_NVAR(&scalarVal);
								ZVAL_COPY(&scalarVal, _108$$38);
								ZEPHIR_CALL_FUNCTION(&_110$$39, "spl_object_id", &_6, 184, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_109$$39, &routeToIdx, &_110$$39, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 782);
								zephir_array_append(&mostInnerArr, &_109$$39, PH_SEPARATE, "phalcon/Mvc/Router.zep", 782);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_111$$38, &mostInnerVal, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_111$$38)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarVal, &mostInnerVal, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_113$$40, "spl_object_id", &_6, 184, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_112$$40, &routeToIdx, &_113$$40, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 782);
									zephir_array_append(&mostInnerArr, &_112$$40, PH_SEPARATE, "phalcon/Mvc/Router.zep", 782);
								ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&scalarVal);
						zephir_array_update_multi(&staticScalar, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_114$$37, &innerVal, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_114$$37)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarSubKey, &innerVal, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&mostInnerVal, &innerVal, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&mostInnerArr);
							array_init(&mostInnerArr);
							zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 784);
							if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _115$$41)
								{
									ZEPHIR_INIT_NVAR(&scalarVal);
									ZVAL_COPY(&scalarVal, _115$$41);
									ZEPHIR_CALL_FUNCTION(&_117$$42, "spl_object_id", &_6, 184, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_116$$42, &routeToIdx, &_117$$42, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 782);
									zephir_array_append(&mostInnerArr, &_116$$42, PH_SEPARATE, "phalcon/Mvc/Router.zep", 782);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_118$$41, &mostInnerVal, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_118$$41)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&scalarVal, &mostInnerVal, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_120$$43, "spl_object_id", &_6, 184, &scalarVal);
										zephir_check_call_status();
										zephir_array_fetch(&_119$$43, &routeToIdx, &_120$$43, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 782);
										zephir_array_append(&mostInnerArr, &_119$$43, PH_SEPARATE, "phalcon/Mvc/Router.zep", 782);
									ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&scalarVal);
							zephir_array_update_multi(&staticScalar, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
						ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&mostInnerVal);
				ZEPHIR_INIT_NVAR(&scalarSubKey);
			ZEPHIR_CALL_METHOD(NULL, &_82, "next", NULL, 0);
			zephir_check_call_status();
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
	zephir_memory_observe(&_121);
	zephir_read_property(&_121, this_ptr, ZEND_STRL("staticShadowedByMethod"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("staticShadowedByMethod"), &_121, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_121);
	zephir_read_property(&_121, this_ptr, ZEND_STRL("hostnameByMethod"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("hostnameByMethod"), &_121, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_121);
	zephir_read_property(&_121, this_ptr, ZEND_STRL("hostnameLessByMethod"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("hostnameLessByMethod"), &_121, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_121);
	zephir_read_property(&_121, this_ptr, ZEND_STRL("combinedRegexByMethod"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("combinedRegexByMethod"), &_121, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_121);
	zephir_read_property(&_121, this_ptr, ZEND_STRL("combinedRegexDisabled"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("combinedRegexDisabled"), &_121, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_121);
	zephir_read_property(&_121, this_ptr, ZEND_STRL("combinedRegexMarkMap"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("combinedRegexMarkMap"), &_121, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_121);
	zephir_read_property(&_121, this_ptr, ZEND_STRL("routeMeta"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("routeMeta"), &_121, PH_COPY | PH_SEPARATE);
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
	zend_class_entry *_7$$6, *_24$$13;
	zval _3$$4;
	zend_string *_42, *_59, *_76, *_18$$10, *_35$$17, *_80$$32, *_98$$39;
	zend_ulong _41, _58, _75, _17$$10, _34$$17, _79$$32, _97$$39;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_19 = NULL, *_21 = NULL, *_36 = NULL, *_38 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, dumpVersion = 0;
	zval *dump_param = NULL, __$true, __$false, routeData, route, routeClass, beforeMatch, converters, convName, converter, rebuiltRoutes, methodRoutesRehydrated, candidatesRehydrated, staticRehydrated, innerKey, innerVal, scalarIdx, scalarSubKey, mostInnerVal, mostInnerArr, _0, _4, *_5, _22, _39, *_40, _49, _56, *_57, _66, _73, *_74, _94, _112, _113, _114, _115, _116, _117, _118, _119, _120, _1$$4, _2$$4, _6$$6, _8$$6, _9$$6, _10$$6, _11$$6, _13$$6, _15$$6, _12$$7, _14$$8, *_16$$10, _20$$10, _23$$13, _25$$13, _26$$13, _27$$13, _28$$13, _30$$13, _32$$13, _29$$14, _31$$15, *_33$$17, _37$$17, *_43$$20, _46$$20, _44$$21, _45$$21, _47$$22, _48$$22, *_50$$23, _53$$23, _51$$24, _52$$24, _54$$25, _55$$25, *_60$$26, _63$$26, _61$$27, _62$$27, _64$$28, _65$$28, *_67$$29, _70$$29, _68$$30, _69$$30, _71$$31, _72$$31, _77$$32, *_78$$32, _87$$32, *_81$$33, _84$$33, _82$$34, _83$$34, _85$$35, _86$$35, *_88$$36, _91$$36, _89$$37, _90$$37, _92$$38, _93$$38, _95$$39, *_96$$39, _105$$39, *_99$$40, _102$$40, _100$$41, _101$$41, _103$$42, _104$$42, *_106$$43, _109$$43, _107$$44, _108$$44, _110$$45, _111$$45;
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
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_56);
	ZVAL_UNDEF(&_66);
	ZVAL_UNDEF(&_73);
	ZVAL_UNDEF(&_94);
	ZVAL_UNDEF(&_112);
	ZVAL_UNDEF(&_113);
	ZVAL_UNDEF(&_114);
	ZVAL_UNDEF(&_115);
	ZVAL_UNDEF(&_116);
	ZVAL_UNDEF(&_117);
	ZVAL_UNDEF(&_118);
	ZVAL_UNDEF(&_119);
	ZVAL_UNDEF(&_120);
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
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_28$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_46$$20);
	ZVAL_UNDEF(&_44$$21);
	ZVAL_UNDEF(&_45$$21);
	ZVAL_UNDEF(&_47$$22);
	ZVAL_UNDEF(&_48$$22);
	ZVAL_UNDEF(&_53$$23);
	ZVAL_UNDEF(&_51$$24);
	ZVAL_UNDEF(&_52$$24);
	ZVAL_UNDEF(&_54$$25);
	ZVAL_UNDEF(&_55$$25);
	ZVAL_UNDEF(&_63$$26);
	ZVAL_UNDEF(&_61$$27);
	ZVAL_UNDEF(&_62$$27);
	ZVAL_UNDEF(&_64$$28);
	ZVAL_UNDEF(&_65$$28);
	ZVAL_UNDEF(&_70$$29);
	ZVAL_UNDEF(&_68$$30);
	ZVAL_UNDEF(&_69$$30);
	ZVAL_UNDEF(&_71$$31);
	ZVAL_UNDEF(&_72$$31);
	ZVAL_UNDEF(&_77$$32);
	ZVAL_UNDEF(&_87$$32);
	ZVAL_UNDEF(&_84$$33);
	ZVAL_UNDEF(&_82$$34);
	ZVAL_UNDEF(&_83$$34);
	ZVAL_UNDEF(&_85$$35);
	ZVAL_UNDEF(&_86$$35);
	ZVAL_UNDEF(&_91$$36);
	ZVAL_UNDEF(&_89$$37);
	ZVAL_UNDEF(&_90$$37);
	ZVAL_UNDEF(&_92$$38);
	ZVAL_UNDEF(&_93$$38);
	ZVAL_UNDEF(&_95$$39);
	ZVAL_UNDEF(&_105$$39);
	ZVAL_UNDEF(&_102$$40);
	ZVAL_UNDEF(&_100$$41);
	ZVAL_UNDEF(&_101$$41);
	ZVAL_UNDEF(&_103$$42);
	ZVAL_UNDEF(&_104$$42);
	ZVAL_UNDEF(&_109$$43);
	ZVAL_UNDEF(&_107$$44);
	ZVAL_UNDEF(&_108$$44);
	ZVAL_UNDEF(&_110$$45);
	ZVAL_UNDEF(&_111$$45);
	ZVAL_UNDEF(&_3$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(dump, dump_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &dump_param);
	zephir_get_arrval(&dump, dump_param);
	if (!(zephir_array_isset_value_string(&dump, SL("version")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Router cache is missing 'version' field", "phalcon/Mvc/Router.zep", 820);
		return;
	}
	zephir_memory_observe(&_0);
	zephir_array_fetch_string(&_0, &dump, SL("version"), PH_NOISY, "phalcon/Mvc/Router.zep", 823);
	dumpVersion = zephir_get_intval(&_0);
	if (dumpVersion != 1) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_LONG(&_2$$4, dumpVersion);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_SVS(&_3$$4, "Router cache version ", &_2$$4, " is not supported (this build supports version 1)");
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 8, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Router.zep", 828);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_array_isset_value_string(&dump, SL("routes")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Router cache is missing 'routes' field", "phalcon/Mvc/Router.zep", 832);
		return;
	}
	ZEPHIR_INIT_VAR(&rebuiltRoutes);
	array_init(&rebuiltRoutes);
	zephir_array_fetch_string(&_4, &dump, SL("routes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 837);
	zephir_is_iterable(&_4, 0, "phalcon/Mvc/Router.zep", 866);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
		{
			ZEPHIR_INIT_NVAR(&routeData);
			ZVAL_COPY(&routeData, _5);
			ZEPHIR_OBS_NVAR(&routeClass);
			zephir_array_fetch_string(&routeClass, &routeData, SL("class"), PH_NOISY, "phalcon/Mvc/Router.zep", 838);
			ZEPHIR_INIT_NVAR(&route);
			zephir_fetch_safe_class(&_6$$6, &routeClass);
			_7$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_6$$6), Z_STRLEN_P(&_6$$6), ZEND_FETCH_CLASS_AUTO);
			if(!_7$$6) {
				RETURN_MM_NULL();
			}
			object_init_ex(&route, _7$$6);
			if (zephir_has_constructor(&route)) {
				zephir_array_fetch_string(&_8$$6, &routeData, SL("pattern"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 839);
				zephir_array_fetch_string(&_9$$6, &routeData, SL("paths"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 839);
				zephir_array_fetch_string(&_10$$6, &routeData, SL("methods"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 839);
				ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 0, &_8$$6, &_9$$6, &_10$$6);
				zephir_check_call_status();
			}

			zephir_array_fetch_string(&_11$$6, &routeData, SL("hostname"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 841);
			if (Z_TYPE_P(&_11$$6) != IS_NULL) {
				zephir_array_fetch_string(&_12$$7, &routeData, SL("hostname"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 842);
				ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &_12$$7);
				zephir_check_call_status();
			}
			zephir_array_fetch_string(&_13$$6, &routeData, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 845);
			if (Z_TYPE_P(&_13$$6) != IS_NULL) {
				zephir_array_fetch_string(&_14$$8, &routeData, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 846);
				ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &_14$$8);
				zephir_check_call_status();
			}
			zephir_array_fetch_string(&_15$$6, &routeData, SL("id"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 849);
			ZEPHIR_CALL_METHOD(NULL, &route, "setrouteid", NULL, 0, &_15$$6);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&beforeMatch);
			zephir_array_fetch_string(&beforeMatch, &routeData, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 851);
			if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&converters);
			zephir_array_fetch_string(&converters, &routeData, SL("converters"), PH_NOISY, "phalcon/Mvc/Router.zep", 856);
			if (Z_TYPE_P(&converters) == IS_ARRAY) {
				zephir_is_iterable(&converters, 0, "phalcon/Mvc/Router.zep", 861);
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
					while (1) {
						ZEPHIR_CALL_METHOD(&_20$$10, &converters, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_20$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&convName, &converters, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&converter, &converters, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_21, 0, &convName, &converter);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &converters, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&converter);
				ZEPHIR_INIT_NVAR(&convName);
			}
			zephir_array_append(&rebuiltRoutes, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 863);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_22, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_22)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&routeData, &_4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&routeClass);
				zephir_array_fetch_string(&routeClass, &routeData, SL("class"), PH_NOISY, "phalcon/Mvc/Router.zep", 838);
				ZEPHIR_INIT_NVAR(&route);
				zephir_fetch_safe_class(&_23$$13, &routeClass);
				_24$$13 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_23$$13), Z_STRLEN_P(&_23$$13), ZEND_FETCH_CLASS_AUTO);
				if(!_24$$13) {
					RETURN_MM_NULL();
				}
				object_init_ex(&route, _24$$13);
				if (zephir_has_constructor(&route)) {
					zephir_array_fetch_string(&_25$$13, &routeData, SL("pattern"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 839);
					zephir_array_fetch_string(&_26$$13, &routeData, SL("paths"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 839);
					zephir_array_fetch_string(&_27$$13, &routeData, SL("methods"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 839);
					ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 0, &_25$$13, &_26$$13, &_27$$13);
					zephir_check_call_status();
				}

				zephir_array_fetch_string(&_28$$13, &routeData, SL("hostname"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 841);
				if (Z_TYPE_P(&_28$$13) != IS_NULL) {
					zephir_array_fetch_string(&_29$$14, &routeData, SL("hostname"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 842);
					ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &_29$$14);
					zephir_check_call_status();
				}
				zephir_array_fetch_string(&_30$$13, &routeData, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 845);
				if (Z_TYPE_P(&_30$$13) != IS_NULL) {
					zephir_array_fetch_string(&_31$$15, &routeData, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 846);
					ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &_31$$15);
					zephir_check_call_status();
				}
				zephir_array_fetch_string(&_32$$13, &routeData, SL("id"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 849);
				ZEPHIR_CALL_METHOD(NULL, &route, "setrouteid", NULL, 0, &_32$$13);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&beforeMatch);
				zephir_array_fetch_string(&beforeMatch, &routeData, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 851);
				if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&converters);
				zephir_array_fetch_string(&converters, &routeData, SL("converters"), PH_NOISY, "phalcon/Mvc/Router.zep", 856);
				if (Z_TYPE_P(&converters) == IS_ARRAY) {
					zephir_is_iterable(&converters, 0, "phalcon/Mvc/Router.zep", 861);
					if (Z_TYPE_P(&converters) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&converters), _34$$17, _35$$17, _33$$17)
						{
							ZEPHIR_INIT_NVAR(&convName);
							if (_35$$17 != NULL) { 
								ZVAL_STR_COPY(&convName, _35$$17);
							} else {
								ZVAL_LONG(&convName, _34$$17);
							}
							ZEPHIR_INIT_NVAR(&converter);
							ZVAL_COPY(&converter, _33$$17);
							ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_36, 0, &convName, &converter);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &converters, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_37$$17, &converters, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_37$$17)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&convName, &converters, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&converter, &converters, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_38, 0, &convName, &converter);
								zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &converters, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&converter);
					ZEPHIR_INIT_NVAR(&convName);
				}
				zephir_array_append(&rebuiltRoutes, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 863);
			ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&routeData);
	zephir_update_property_zval(this_ptr, ZEND_STRL("routes"), &rebuiltRoutes);
	ZEPHIR_INIT_VAR(&methodRoutesRehydrated);
	array_init(&methodRoutesRehydrated);
	zephir_array_fetch_string(&_39, &dump, SL("methodRoutes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 869);
	zephir_is_iterable(&_39, 0, "phalcon/Mvc/Router.zep", 877);
	if (Z_TYPE_P(&_39) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_39), _41, _42, _40)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_42 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _42);
			} else {
				ZVAL_LONG(&innerKey, _41);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _40);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 874);
			if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _43$$20)
				{
					ZEPHIR_INIT_NVAR(&scalarIdx);
					ZVAL_COPY(&scalarIdx, _43$$20);
					zephir_read_property(&_44$$21, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_45$$21, &_44$$21, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 872);
					zephir_array_append(&mostInnerArr, &_45$$21, PH_SEPARATE, "phalcon/Mvc/Router.zep", 872);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_46$$20, &innerVal, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_46$$20)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarIdx, &innerVal, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property(&_47$$22, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_48$$22, &_47$$22, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 872);
						zephir_array_append(&mostInnerArr, &_48$$22, PH_SEPARATE, "phalcon/Mvc/Router.zep", 872);
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&scalarIdx);
			zephir_array_update_zval(&methodRoutesRehydrated, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_39, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_49, &_39, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_49)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, &_39, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, &_39, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 874);
				if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _50$$23)
					{
						ZEPHIR_INIT_NVAR(&scalarIdx);
						ZVAL_COPY(&scalarIdx, _50$$23);
						zephir_read_property(&_51$$24, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_52$$24, &_51$$24, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 872);
						zephir_array_append(&mostInnerArr, &_52$$24, PH_SEPARATE, "phalcon/Mvc/Router.zep", 872);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_53$$23, &innerVal, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_53$$23)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarIdx, &innerVal, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property(&_54$$25, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch(&_55$$25, &_54$$25, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 872);
							zephir_array_append(&mostInnerArr, &_55$$25, PH_SEPARATE, "phalcon/Mvc/Router.zep", 872);
						ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&scalarIdx);
				zephir_array_update_zval(&methodRoutesRehydrated, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_39, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	ZEPHIR_INIT_VAR(&candidatesRehydrated);
	array_init(&candidatesRehydrated);
	zephir_array_fetch_string(&_56, &dump, SL("candidatesByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 878);
	zephir_is_iterable(&_56, 0, "phalcon/Mvc/Router.zep", 886);
	if (Z_TYPE_P(&_56) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_56), _58, _59, _57)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_59 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _59);
			} else {
				ZVAL_LONG(&innerKey, _58);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _57);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 883);
			if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _60$$26)
				{
					ZEPHIR_INIT_NVAR(&scalarIdx);
					ZVAL_COPY(&scalarIdx, _60$$26);
					zephir_read_property(&_61$$27, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_62$$27, &_61$$27, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 881);
					zephir_array_append(&mostInnerArr, &_62$$27, PH_SEPARATE, "phalcon/Mvc/Router.zep", 881);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_63$$26, &innerVal, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_63$$26)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarIdx, &innerVal, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property(&_64$$28, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_65$$28, &_64$$28, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 881);
						zephir_array_append(&mostInnerArr, &_65$$28, PH_SEPARATE, "phalcon/Mvc/Router.zep", 881);
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&scalarIdx);
			zephir_array_update_zval(&candidatesRehydrated, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_56, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_66, &_56, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_66)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, &_56, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, &_56, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 883);
				if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&innerVal), _67$$29)
					{
						ZEPHIR_INIT_NVAR(&scalarIdx);
						ZVAL_COPY(&scalarIdx, _67$$29);
						zephir_read_property(&_68$$30, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_69$$30, &_68$$30, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 881);
						zephir_array_append(&mostInnerArr, &_69$$30, PH_SEPARATE, "phalcon/Mvc/Router.zep", 881);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_70$$29, &innerVal, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_70$$29)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarIdx, &innerVal, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property(&_71$$31, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch(&_72$$31, &_71$$31, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 881);
							zephir_array_append(&mostInnerArr, &_72$$31, PH_SEPARATE, "phalcon/Mvc/Router.zep", 881);
						ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&scalarIdx);
				zephir_array_update_zval(&candidatesRehydrated, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_56, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	ZEPHIR_INIT_VAR(&staticRehydrated);
	array_init(&staticRehydrated);
	zephir_array_fetch_string(&_73, &dump, SL("staticByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 887);
	zephir_is_iterable(&_73, 0, "phalcon/Mvc/Router.zep", 898);
	if (Z_TYPE_P(&_73) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_73), _75, _76, _74)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_76 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _76);
			} else {
				ZVAL_LONG(&innerKey, _75);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _74);
			ZEPHIR_INIT_NVAR(&_77$$32);
			array_init(&_77$$32);
			zephir_array_update_zval(&staticRehydrated, &innerKey, &_77$$32, PH_COPY | PH_SEPARATE);
			zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 896);
			if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&innerVal), _79$$32, _80$$32, _78$$32)
				{
					ZEPHIR_INIT_NVAR(&scalarSubKey);
					if (_80$$32 != NULL) { 
						ZVAL_STR_COPY(&scalarSubKey, _80$$32);
					} else {
						ZVAL_LONG(&scalarSubKey, _79$$32);
					}
					ZEPHIR_INIT_NVAR(&mostInnerVal);
					ZVAL_COPY(&mostInnerVal, _78$$32);
					ZEPHIR_INIT_NVAR(&mostInnerArr);
					array_init(&mostInnerArr);
					zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 894);
					if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _81$$33)
						{
							ZEPHIR_INIT_NVAR(&scalarIdx);
							ZVAL_COPY(&scalarIdx, _81$$33);
							zephir_read_property(&_82$$34, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch(&_83$$34, &_82$$34, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 892);
							zephir_array_append(&mostInnerArr, &_83$$34, PH_SEPARATE, "phalcon/Mvc/Router.zep", 892);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_84$$33, &mostInnerVal, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_84$$33)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&scalarIdx, &mostInnerVal, "current", NULL, 0);
							zephir_check_call_status();
								zephir_read_property(&_85$$35, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch(&_86$$35, &_85$$35, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 892);
								zephir_array_append(&mostInnerArr, &_86$$35, PH_SEPARATE, "phalcon/Mvc/Router.zep", 892);
							ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&scalarIdx);
					zephir_array_update_multi(&staticRehydrated, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_87$$32, &innerVal, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_87$$32)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarSubKey, &innerVal, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&mostInnerVal, &innerVal, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 894);
						if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _88$$36)
							{
								ZEPHIR_INIT_NVAR(&scalarIdx);
								ZVAL_COPY(&scalarIdx, _88$$36);
								zephir_read_property(&_89$$37, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch(&_90$$37, &_89$$37, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 892);
								zephir_array_append(&mostInnerArr, &_90$$37, PH_SEPARATE, "phalcon/Mvc/Router.zep", 892);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_91$$36, &mostInnerVal, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_91$$36)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarIdx, &mostInnerVal, "current", NULL, 0);
								zephir_check_call_status();
									zephir_read_property(&_92$$38, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch(&_93$$38, &_92$$38, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 892);
									zephir_array_append(&mostInnerArr, &_93$$38, PH_SEPARATE, "phalcon/Mvc/Router.zep", 892);
								ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&scalarIdx);
						zephir_array_update_multi(&staticRehydrated, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&mostInnerVal);
			ZEPHIR_INIT_NVAR(&scalarSubKey);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_73, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_94, &_73, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_94)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, &_73, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, &_73, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_95$$39);
				array_init(&_95$$39);
				zephir_array_update_zval(&staticRehydrated, &innerKey, &_95$$39, PH_COPY | PH_SEPARATE);
				zephir_is_iterable(&innerVal, 0, "phalcon/Mvc/Router.zep", 896);
				if (Z_TYPE_P(&innerVal) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&innerVal), _97$$39, _98$$39, _96$$39)
					{
						ZEPHIR_INIT_NVAR(&scalarSubKey);
						if (_98$$39 != NULL) { 
							ZVAL_STR_COPY(&scalarSubKey, _98$$39);
						} else {
							ZVAL_LONG(&scalarSubKey, _97$$39);
						}
						ZEPHIR_INIT_NVAR(&mostInnerVal);
						ZVAL_COPY(&mostInnerVal, _96$$39);
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 894);
						if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _99$$40)
							{
								ZEPHIR_INIT_NVAR(&scalarIdx);
								ZVAL_COPY(&scalarIdx, _99$$40);
								zephir_read_property(&_100$$41, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch(&_101$$41, &_100$$41, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 892);
								zephir_array_append(&mostInnerArr, &_101$$41, PH_SEPARATE, "phalcon/Mvc/Router.zep", 892);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_102$$40, &mostInnerVal, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_102$$40)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarIdx, &mostInnerVal, "current", NULL, 0);
								zephir_check_call_status();
									zephir_read_property(&_103$$42, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch(&_104$$42, &_103$$42, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 892);
									zephir_array_append(&mostInnerArr, &_104$$42, PH_SEPARATE, "phalcon/Mvc/Router.zep", 892);
								ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&scalarIdx);
						zephir_array_update_multi(&staticRehydrated, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &innerVal, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_105$$39, &innerVal, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_105$$39)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarSubKey, &innerVal, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&mostInnerVal, &innerVal, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&mostInnerArr);
							array_init(&mostInnerArr);
							zephir_is_iterable(&mostInnerVal, 0, "phalcon/Mvc/Router.zep", 894);
							if (Z_TYPE_P(&mostInnerVal) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mostInnerVal), _106$$43)
								{
									ZEPHIR_INIT_NVAR(&scalarIdx);
									ZVAL_COPY(&scalarIdx, _106$$43);
									zephir_read_property(&_107$$44, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch(&_108$$44, &_107$$44, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 892);
									zephir_array_append(&mostInnerArr, &_108$$44, PH_SEPARATE, "phalcon/Mvc/Router.zep", 892);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_109$$43, &mostInnerVal, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_109$$43)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&scalarIdx, &mostInnerVal, "current", NULL, 0);
									zephir_check_call_status();
										zephir_read_property(&_110$$45, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
										zephir_array_fetch(&_111$$45, &_110$$45, &scalarIdx, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 892);
										zephir_array_append(&mostInnerArr, &_111$$45, PH_SEPARATE, "phalcon/Mvc/Router.zep", 892);
									ZEPHIR_CALL_METHOD(NULL, &mostInnerVal, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&scalarIdx);
							zephir_array_update_multi(&staticRehydrated, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
						ZEPHIR_CALL_METHOD(NULL, &innerVal, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&mostInnerVal);
				ZEPHIR_INIT_NVAR(&scalarSubKey);
			ZEPHIR_CALL_METHOD(NULL, &_73, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutes"), &methodRoutesRehydrated);
	zephir_update_property_zval(this_ptr, ZEND_STRL("candidatesByMethod"), &candidatesRehydrated);
	zephir_update_property_zval(this_ptr, ZEND_STRL("staticByMethod"), &staticRehydrated);
	zephir_array_fetch_string(&_112, &dump, SL("staticShadowedByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 901);
	zephir_update_property_zval(this_ptr, ZEND_STRL("staticShadowedByMethod"), &_112);
	zephir_array_fetch_string(&_113, &dump, SL("hostnameByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 902);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hostnameByMethod"), &_113);
	zephir_array_fetch_string(&_114, &dump, SL("hostnameLessByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 903);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hostnameLessByMethod"), &_114);
	zephir_array_fetch_string(&_115, &dump, SL("combinedRegexByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 904);
	zephir_update_property_zval(this_ptr, ZEND_STRL("combinedRegexByMethod"), &_115);
	zephir_array_fetch_string(&_116, &dump, SL("combinedRegexDisabled"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 905);
	zephir_update_property_zval(this_ptr, ZEND_STRL("combinedRegexDisabled"), &_116);
	zephir_array_fetch_string(&_117, &dump, SL("combinedRegexMarkMap"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 906);
	zephir_update_property_zval(this_ptr, ZEND_STRL("combinedRegexMarkMap"), &_117);
	zephir_array_fetch_string(&_118, &dump, SL("routeMeta"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 907);
	zephir_update_property_zval(this_ptr, ZEND_STRL("routeMeta"), &_118);
	ZEPHIR_INIT_VAR(&_119);
	array_init(&_119);
	zephir_update_property_zval(this_ptr, ZEND_STRL("keyRouteIds"), &_119);
	ZEPHIR_INIT_VAR(&_120);
	array_init(&_120);
	zephir_update_property_zval(this_ptr, ZEND_STRL("keyRouteNames"), &_120);
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutesDirty"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutesDirty"), &__$false);
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
	ZEPHIR_CALL_FUNCTION(&_1, "getmypid", NULL, 185);
	zephir_check_call_status();
	zephir_cast_to_string(&_2, &_1);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSV(&_3, &path_zv, ".tmp.", &_2);
	ZEPHIR_CPY_WRT(&tmpPath, &_3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_file_put_contents(&_4, &tmpPath, &php);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SV(&_6$$3, "Failed to write router cache temp file: ", &tmpPath);
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 8, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "phalcon/Mvc/Router.zep", 929);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_7, "rename", NULL, 186, &tmpPath, &path_zv);
	zephir_check_call_status();
	if (!(zephir_is_true(&_7))) {
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 187, &tmpPath);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$4);
		object_init_ex(&_8$$4, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZEPHIR_CONCAT_SV(&_9$$4, "Failed to commit router cache: ", &path_zv);
		ZEPHIR_CALL_METHOD(NULL, &_8$$4, "__construct", NULL, 8, &_9$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$4, "phalcon/Mvc/Router.zep", 934);
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
	zval _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval path_zv, dump, _2, _0$$3, _3$$4, _4$$4, _5$$4;
	zend_string *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&dump);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	if (!((zephir_file_exists(&path_zv) == SUCCESS))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SV(&_1$$3, "Router cache not found: ", &path_zv);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 8, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Router.zep", 949);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_2);
	if (zephir_require_zval_ret(&_2, &path_zv) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(&dump, &_2);
	if (Z_TYPE_P(&dump) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$4);
		zephir_gettype(&_4$$4, &dump);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVSV(&_5$$4, "Router cache is corrupt or invalid (expected array, got ", &_4$$4, "): ", &path_zv);
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 8, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "phalcon/Mvc/Router.zep", 957);
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
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(cache, phalcon_cache_adapter_adapterinterface_ce)
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
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 8, &_2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Router.zep", 981);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loaddispatcherfromarray", NULL, 0, &stored);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("pendingCache"), cache);
	zephir_update_property_zval(this_ptr, ZEND_STRL("pendingCacheKey"), &key_zv);
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
	zephir_array_fetch_long(&realUri, &urlParts, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1137);
	RETURN_CTOR(&realUri);
}

PHP_METHOD(Phalcon_Mvc_Router, rebuildMethodIndex)
{
	zval _110$$74, _115$$77, _137$$87, _142$$90;
	zval _25$$20, _29$$22;
	zend_string *_16, *_35, *_82, *_102, *_40$$28, *_50$$36, *_61$$45, *_71$$53, *_87$$58, *_94$$65, *_106$$72, *_133$$85;
	zend_ulong _15, _34, _81, _101, _39$$28, _49$$36, _60$$45, _70$$53, _86$$58, _93$$65, _105$$72, _132$$85;
	zend_bool isRegex = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_118 = NULL, *_121 = NULL;
	zval __$true, __$false, route, methods, method, methodSpecific, starRoutes, candidates, candidateRoute, candidatePattern, bucketRoute, bucketPattern, staticUri, staticBucket, staticRoutesList, _0, _1, _2, _3, _4, _5, *_6, _9, _12, _13, *_14, _19, _22, _23, *_24, _28, _32, *_33, _56, bucketIdx, bucketHostname, _77, _78, _79, *_80, _89, combinedAlternatives, combinedMark, combinedBody, combinedBodyMatch, combinedShape, hostnameBucketRef, _96, _97, _98, _99, *_100, _129, *_7$$6, _8$$6, *_10$$12, _11$$12, _17$$17, _18$$16, _20$$19, _21$$18, _26$$20, _27$$20, _30$$22, _31$$22, *_36$$24, _46$$24, _37$$27, *_38$$28, _43$$28, _41$$29, _42$$29, _44$$31, _45$$31, _47$$35, *_48$$36, _53$$36, _51$$37, _52$$37, _54$$39, _55$$39, *_57$$41, _67$$41, _58$$44, *_59$$45, _64$$45, _62$$46, _63$$46, _65$$48, _66$$48, _68$$52, *_69$$53, _74$$53, _72$$54, _73$$54, _75$$56, _76$$56, _83$$58, _84$$58, *_85$$58, _88$$58, _90$$65, _91$$65, *_92$$65, _95$$65, _103$$72, *_104$$72, _111$$72, _116$$72, chunkedPatterns$$72, chunkedMarkMaps$$72, chunkOffset$$72, chunkSlice$$72, chunkSliceMap$$72, chunkMarkSubset$$72, reversedMarkIds$$72, chunkMarkId$$72, _117$$72, _119$$72, _107$$74, _108$$74, _109$$74, _112$$77, _113$$77, _114$$77, _120$$82, *_122$$82, _124$$82, _126$$82, _127$$82, _128$$82, _123$$83, _125$$84, _130$$85, *_131$$85, _138$$85, _143$$85, chunkedPatterns$$85, chunkedMarkMaps$$85, chunkOffset$$85, chunkSlice$$85, chunkSliceMap$$85, chunkMarkSubset$$85, reversedMarkIds$$85, chunkMarkId$$85, _144$$85, _145$$85, _134$$87, _135$$87, _136$$87, _139$$90, _140$$90, _141$$90, _146$$95, *_147$$95, _149$$95, _151$$95, _152$$95, _153$$95, _148$$96, _150$$97;
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
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_56);
	ZVAL_UNDEF(&bucketIdx);
	ZVAL_UNDEF(&bucketHostname);
	ZVAL_UNDEF(&_77);
	ZVAL_UNDEF(&_78);
	ZVAL_UNDEF(&_79);
	ZVAL_UNDEF(&_89);
	ZVAL_UNDEF(&combinedAlternatives);
	ZVAL_UNDEF(&combinedMark);
	ZVAL_UNDEF(&combinedBody);
	ZVAL_UNDEF(&combinedBodyMatch);
	ZVAL_UNDEF(&combinedShape);
	ZVAL_UNDEF(&hostnameBucketRef);
	ZVAL_UNDEF(&_96);
	ZVAL_UNDEF(&_97);
	ZVAL_UNDEF(&_98);
	ZVAL_UNDEF(&_99);
	ZVAL_UNDEF(&_129);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_26$$20);
	ZVAL_UNDEF(&_27$$20);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_31$$22);
	ZVAL_UNDEF(&_46$$24);
	ZVAL_UNDEF(&_37$$27);
	ZVAL_UNDEF(&_43$$28);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_42$$29);
	ZVAL_UNDEF(&_44$$31);
	ZVAL_UNDEF(&_45$$31);
	ZVAL_UNDEF(&_47$$35);
	ZVAL_UNDEF(&_53$$36);
	ZVAL_UNDEF(&_51$$37);
	ZVAL_UNDEF(&_52$$37);
	ZVAL_UNDEF(&_54$$39);
	ZVAL_UNDEF(&_55$$39);
	ZVAL_UNDEF(&_67$$41);
	ZVAL_UNDEF(&_58$$44);
	ZVAL_UNDEF(&_64$$45);
	ZVAL_UNDEF(&_62$$46);
	ZVAL_UNDEF(&_63$$46);
	ZVAL_UNDEF(&_65$$48);
	ZVAL_UNDEF(&_66$$48);
	ZVAL_UNDEF(&_68$$52);
	ZVAL_UNDEF(&_74$$53);
	ZVAL_UNDEF(&_72$$54);
	ZVAL_UNDEF(&_73$$54);
	ZVAL_UNDEF(&_75$$56);
	ZVAL_UNDEF(&_76$$56);
	ZVAL_UNDEF(&_83$$58);
	ZVAL_UNDEF(&_84$$58);
	ZVAL_UNDEF(&_88$$58);
	ZVAL_UNDEF(&_90$$65);
	ZVAL_UNDEF(&_91$$65);
	ZVAL_UNDEF(&_95$$65);
	ZVAL_UNDEF(&_103$$72);
	ZVAL_UNDEF(&_111$$72);
	ZVAL_UNDEF(&_116$$72);
	ZVAL_UNDEF(&chunkedPatterns$$72);
	ZVAL_UNDEF(&chunkedMarkMaps$$72);
	ZVAL_UNDEF(&chunkOffset$$72);
	ZVAL_UNDEF(&chunkSlice$$72);
	ZVAL_UNDEF(&chunkSliceMap$$72);
	ZVAL_UNDEF(&chunkMarkSubset$$72);
	ZVAL_UNDEF(&reversedMarkIds$$72);
	ZVAL_UNDEF(&chunkMarkId$$72);
	ZVAL_UNDEF(&_117$$72);
	ZVAL_UNDEF(&_119$$72);
	ZVAL_UNDEF(&_107$$74);
	ZVAL_UNDEF(&_108$$74);
	ZVAL_UNDEF(&_109$$74);
	ZVAL_UNDEF(&_112$$77);
	ZVAL_UNDEF(&_113$$77);
	ZVAL_UNDEF(&_114$$77);
	ZVAL_UNDEF(&_120$$82);
	ZVAL_UNDEF(&_124$$82);
	ZVAL_UNDEF(&_126$$82);
	ZVAL_UNDEF(&_127$$82);
	ZVAL_UNDEF(&_128$$82);
	ZVAL_UNDEF(&_123$$83);
	ZVAL_UNDEF(&_125$$84);
	ZVAL_UNDEF(&_130$$85);
	ZVAL_UNDEF(&_138$$85);
	ZVAL_UNDEF(&_143$$85);
	ZVAL_UNDEF(&chunkedPatterns$$85);
	ZVAL_UNDEF(&chunkedMarkMaps$$85);
	ZVAL_UNDEF(&chunkOffset$$85);
	ZVAL_UNDEF(&chunkSlice$$85);
	ZVAL_UNDEF(&chunkSliceMap$$85);
	ZVAL_UNDEF(&chunkMarkSubset$$85);
	ZVAL_UNDEF(&reversedMarkIds$$85);
	ZVAL_UNDEF(&chunkMarkId$$85);
	ZVAL_UNDEF(&_144$$85);
	ZVAL_UNDEF(&_145$$85);
	ZVAL_UNDEF(&_134$$87);
	ZVAL_UNDEF(&_135$$87);
	ZVAL_UNDEF(&_136$$87);
	ZVAL_UNDEF(&_139$$90);
	ZVAL_UNDEF(&_140$$90);
	ZVAL_UNDEF(&_141$$90);
	ZVAL_UNDEF(&_146$$95);
	ZVAL_UNDEF(&_149$$95);
	ZVAL_UNDEF(&_151$$95);
	ZVAL_UNDEF(&_152$$95);
	ZVAL_UNDEF(&_153$$95);
	ZVAL_UNDEF(&_148$$96);
	ZVAL_UNDEF(&_150$$97);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_29$$22);
	ZVAL_UNDEF(&_110$$74);
	ZVAL_UNDEF(&_115$$77);
	ZVAL_UNDEF(&_137$$87);
	ZVAL_UNDEF(&_142$$90);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("methodRoutes"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("candidatesByMethod"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("routeMeta"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval(this_ptr, ZEND_STRL("staticByMethod"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	zephir_update_property_zval(this_ptr, ZEND_STRL("staticShadowedByMethod"), &_4);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_5, 0, "phalcon/Mvc/Router.zep", 1169);
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
				zephir_is_iterable(&methods, 0, "phalcon/Mvc/Router.zep", 1166);
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
					while (1) {
						ZEPHIR_CALL_METHOD(&_8$$6, &methods, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_8$$6)) {
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
		ZEPHIR_CALL_METHOD(NULL, &_5, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_9, &_5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
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
					zephir_is_iterable(&methods, 0, "phalcon/Mvc/Router.zep", 1166);
					if (Z_TYPE_P(&methods) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _10$$12)
						{
							ZEPHIR_INIT_NVAR(&method);
							ZVAL_COPY(&method, _10$$12);
							zephir_update_property_array_multi(this_ptr, SL("methodRoutes"), &route, SL("za"), 2, &method);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_11$$12, &methods, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_11$$12)) {
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
			ZEPHIR_CALL_METHOD(NULL, &_5, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	zephir_memory_observe(&starRoutes);
	zephir_read_property(&_12, this_ptr, ZEND_STRL("methodRoutes"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&starRoutes, &_12, SL("*"), 0))) {
		ZEPHIR_INIT_NVAR(&starRoutes);
		array_init(&starRoutes);
	}
	zephir_read_property(&_13, this_ptr, ZEND_STRL("methodRoutes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_13, 0, "phalcon/Mvc/Router.zep", 1187);
	if (Z_TYPE_P(&_13) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_13), _15, _16, _14)
		{
			ZEPHIR_INIT_NVAR(&method);
			if (_16 != NULL) { 
				ZVAL_STR_COPY(&method, _16);
			} else {
				ZVAL_LONG(&method, _15);
			}
			ZEPHIR_INIT_NVAR(&methodSpecific);
			ZVAL_COPY(&methodSpecific, _14);
			if (ZEPHIR_IS_STRING(&method, "*")) {
				ZEPHIR_INIT_NVAR(&_17$$17);
				ZVAL_STRING(&_17$$17, "*");
				zephir_update_property_array(this_ptr, SL("candidatesByMethod"), &_17$$17, &starRoutes);
				continue;
			}
			ZEPHIR_INIT_NVAR(&_18$$16);
			zephir_fast_array_merge(&_18$$16, &methodSpecific, &starRoutes);
			zephir_update_property_array(this_ptr, SL("candidatesByMethod"), &method, &_18$$16);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_13, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_19, &_13, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_19)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, &_13, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&methodSpecific, &_13, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_STRING(&method, "*")) {
					ZEPHIR_INIT_NVAR(&_20$$19);
					ZVAL_STRING(&_20$$19, "*");
					zephir_update_property_array(this_ptr, SL("candidatesByMethod"), &_20$$19, &starRoutes);
					continue;
				}
				ZEPHIR_INIT_NVAR(&_21$$18);
				zephir_fast_array_merge(&_21$$18, &methodSpecific, &starRoutes);
				zephir_update_property_array(this_ptr, SL("candidatesByMethod"), &method, &_21$$18);
			ZEPHIR_CALL_METHOD(NULL, &_13, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&methodSpecific);
	ZEPHIR_INIT_NVAR(&method);
	ZEPHIR_INIT_VAR(&_22);
	array_init(&_22);
	zephir_update_property_zval(this_ptr, ZEND_STRL("routeMeta"), &_22);
	zephir_read_property(&_23, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_23, 0, "phalcon/Mvc/Router.zep", 1213);
	if (Z_TYPE_P(&_23) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_23), _24)
		{
			ZEPHIR_INIT_NVAR(&candidateRoute);
			ZVAL_COPY(&candidateRoute, _24);
			ZEPHIR_CALL_METHOD(&candidatePattern, &candidateRoute, "getcompiledpattern", NULL, 0);
			zephir_check_call_status();
			isRegex = 0;
			if (zephir_memnstr_str(&candidatePattern, SL("^"), "phalcon/Mvc/Router.zep", 1193)) {
				isRegex = 1;
			}
			ZEPHIR_INIT_NVAR(&_25$$20);
			zephir_create_array(&_25$$20, 5, 0);
			zephir_array_update_string(&_25$$20, SL("pattern"), &candidatePattern, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_26$$20);
			ZVAL_BOOL(&_26$$20, isRegex);
			zephir_array_update_string(&_25$$20, SL("isRegex"), &_26$$20, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_27$$20, &candidateRoute, "gethostname", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_25$$20, SL("hostname"), &_27$$20, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_27$$20, &candidateRoute, "getcompiledhostname", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_25$$20, SL("hostRegex"), &_27$$20, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_27$$20, &candidateRoute, "getbeforematch", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_25$$20, SL("beforeMatch"), &_27$$20, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_27$$20, &candidateRoute, "getrouteid", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("routeMeta"), &_27$$20, &_25$$20);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_23, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_28, &_23, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_28)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&candidateRoute, &_23, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&candidatePattern, &candidateRoute, "getcompiledpattern", NULL, 0);
				zephir_check_call_status();
				isRegex = 0;
				if (zephir_memnstr_str(&candidatePattern, SL("^"), "phalcon/Mvc/Router.zep", 1193)) {
					isRegex = 1;
				}
				ZEPHIR_INIT_NVAR(&_29$$22);
				zephir_create_array(&_29$$22, 5, 0);
				zephir_array_update_string(&_29$$22, SL("pattern"), &candidatePattern, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_30$$22);
				ZVAL_BOOL(&_30$$22, isRegex);
				zephir_array_update_string(&_29$$22, SL("isRegex"), &_30$$22, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_31$$22, &candidateRoute, "gethostname", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_29$$22, SL("hostname"), &_31$$22, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_31$$22, &candidateRoute, "getcompiledhostname", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_29$$22, SL("hostRegex"), &_31$$22, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_31$$22, &candidateRoute, "getbeforematch", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_29$$22, SL("beforeMatch"), &_31$$22, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_31$$22, &candidateRoute, "getrouteid", NULL, 0);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("routeMeta"), &_31$$22, &_29$$22);
			ZEPHIR_CALL_METHOD(NULL, &_23, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&candidateRoute);
	zephir_read_property(&_32, this_ptr, ZEND_STRL("candidatesByMethod"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_32, 0, "phalcon/Mvc/Router.zep", 1236);
	if (Z_TYPE_P(&_32) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_32), _34, _35, _33)
		{
			ZEPHIR_INIT_NVAR(&method);
			if (_35 != NULL) { 
				ZVAL_STR_COPY(&method, _35);
			} else {
				ZVAL_LONG(&method, _34);
			}
			ZEPHIR_INIT_NVAR(&candidates);
			ZVAL_COPY(&candidates, _33);
			zephir_is_iterable(&candidates, 0, "phalcon/Mvc/Router.zep", 1229);
			if (Z_TYPE_P(&candidates) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&candidates), _36$$24)
				{
					ZEPHIR_INIT_NVAR(&bucketRoute);
					ZVAL_COPY(&bucketRoute, _36$$24);
					ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 1217))) {
						zephir_update_property_array_multi(this_ptr, SL("staticByMethod"), &bucketRoute, SL("zza"), 3, &method, &bucketPattern);
					} else {
						ZEPHIR_OBS_NVAR(&staticBucket);
						zephir_read_property(&_37$$27, this_ptr, ZEND_STRL("staticByMethod"), PH_NOISY_CC | PH_READONLY);
						if (zephir_array_isset_fetch(&staticBucket, &_37$$27, &method, 0)) {
							zephir_is_iterable(&staticBucket, 0, "phalcon/Mvc/Router.zep", 1226);
							if (Z_TYPE_P(&staticBucket) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&staticBucket), _39$$28, _40$$28, _38$$28)
								{
									ZEPHIR_INIT_NVAR(&staticUri);
									if (_40$$28 != NULL) { 
										ZVAL_STR_COPY(&staticUri, _40$$28);
									} else {
										ZVAL_LONG(&staticUri, _39$$28);
									}
									ZEPHIR_INIT_NVAR(&staticRoutesList);
									ZVAL_COPY(&staticRoutesList, _38$$28);
									ZEPHIR_INIT_NVAR(&_41$$29);
									ZEPHIR_INIT_NVAR(&_42$$29);
									zephir_preg_match(&_42$$29, &bucketPattern, &staticUri, &_41$$29, 0, 0 , 0 );
									if (zephir_is_true(&_42$$29)) {
										zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &staticBucket, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_43$$28, &staticBucket, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_43$$28)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&staticUri, &staticBucket, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&staticRoutesList, &staticBucket, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_44$$31);
										ZEPHIR_INIT_NVAR(&_45$$31);
										zephir_preg_match(&_45$$31, &bucketPattern, &staticUri, &_44$$31, 0, 0 , 0 );
										if (zephir_is_true(&_45$$31)) {
											zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
										}
									ZEPHIR_CALL_METHOD(NULL, &staticBucket, "next", NULL, 0);
									zephir_check_call_status();
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
				while (1) {
					ZEPHIR_CALL_METHOD(&_46$$24, &candidates, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_46$$24)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&bucketRoute, &candidates, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 1217))) {
							zephir_update_property_array_multi(this_ptr, SL("staticByMethod"), &bucketRoute, SL("zza"), 3, &method, &bucketPattern);
						} else {
							ZEPHIR_OBS_NVAR(&staticBucket);
							zephir_read_property(&_47$$35, this_ptr, ZEND_STRL("staticByMethod"), PH_NOISY_CC | PH_READONLY);
							if (zephir_array_isset_fetch(&staticBucket, &_47$$35, &method, 0)) {
								zephir_is_iterable(&staticBucket, 0, "phalcon/Mvc/Router.zep", 1226);
								if (Z_TYPE_P(&staticBucket) == IS_ARRAY) {
									ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&staticBucket), _49$$36, _50$$36, _48$$36)
									{
										ZEPHIR_INIT_NVAR(&staticUri);
										if (_50$$36 != NULL) { 
											ZVAL_STR_COPY(&staticUri, _50$$36);
										} else {
											ZVAL_LONG(&staticUri, _49$$36);
										}
										ZEPHIR_INIT_NVAR(&staticRoutesList);
										ZVAL_COPY(&staticRoutesList, _48$$36);
										ZEPHIR_INIT_NVAR(&_51$$37);
										ZEPHIR_INIT_NVAR(&_52$$37);
										zephir_preg_match(&_52$$37, &bucketPattern, &staticUri, &_51$$37, 0, 0 , 0 );
										if (zephir_is_true(&_52$$37)) {
											zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
										}
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &staticBucket, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_53$$36, &staticBucket, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_53$$36)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&staticUri, &staticBucket, "key", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_CALL_METHOD(&staticRoutesList, &staticBucket, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_54$$39);
											ZEPHIR_INIT_NVAR(&_55$$39);
											zephir_preg_match(&_55$$39, &bucketPattern, &staticUri, &_54$$39, 0, 0 , 0 );
											if (zephir_is_true(&_55$$39)) {
												zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
											}
										ZEPHIR_CALL_METHOD(NULL, &staticBucket, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&staticRoutesList);
								ZEPHIR_INIT_NVAR(&staticUri);
							}
						}
					ZEPHIR_CALL_METHOD(NULL, &candidates, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&bucketRoute);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_32, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_56, &_32, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_56)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, &_32, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&candidates, &_32, "current", NULL, 0);
			zephir_check_call_status();
				zephir_is_iterable(&candidates, 0, "phalcon/Mvc/Router.zep", 1229);
				if (Z_TYPE_P(&candidates) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&candidates), _57$$41)
					{
						ZEPHIR_INIT_NVAR(&bucketRoute);
						ZVAL_COPY(&bucketRoute, _57$$41);
						ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 1217))) {
							zephir_update_property_array_multi(this_ptr, SL("staticByMethod"), &bucketRoute, SL("zza"), 3, &method, &bucketPattern);
						} else {
							ZEPHIR_OBS_NVAR(&staticBucket);
							zephir_read_property(&_58$$44, this_ptr, ZEND_STRL("staticByMethod"), PH_NOISY_CC | PH_READONLY);
							if (zephir_array_isset_fetch(&staticBucket, &_58$$44, &method, 0)) {
								zephir_is_iterable(&staticBucket, 0, "phalcon/Mvc/Router.zep", 1226);
								if (Z_TYPE_P(&staticBucket) == IS_ARRAY) {
									ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&staticBucket), _60$$45, _61$$45, _59$$45)
									{
										ZEPHIR_INIT_NVAR(&staticUri);
										if (_61$$45 != NULL) { 
											ZVAL_STR_COPY(&staticUri, _61$$45);
										} else {
											ZVAL_LONG(&staticUri, _60$$45);
										}
										ZEPHIR_INIT_NVAR(&staticRoutesList);
										ZVAL_COPY(&staticRoutesList, _59$$45);
										ZEPHIR_INIT_NVAR(&_62$$46);
										ZEPHIR_INIT_NVAR(&_63$$46);
										zephir_preg_match(&_63$$46, &bucketPattern, &staticUri, &_62$$46, 0, 0 , 0 );
										if (zephir_is_true(&_63$$46)) {
											zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
										}
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &staticBucket, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_64$$45, &staticBucket, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_64$$45)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&staticUri, &staticBucket, "key", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_CALL_METHOD(&staticRoutesList, &staticBucket, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_65$$48);
											ZEPHIR_INIT_NVAR(&_66$$48);
											zephir_preg_match(&_66$$48, &bucketPattern, &staticUri, &_65$$48, 0, 0 , 0 );
											if (zephir_is_true(&_66$$48)) {
												zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
											}
										ZEPHIR_CALL_METHOD(NULL, &staticBucket, "next", NULL, 0);
										zephir_check_call_status();
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
					while (1) {
						ZEPHIR_CALL_METHOD(&_67$$41, &candidates, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_67$$41)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&bucketRoute, &candidates, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
							zephir_check_call_status();
							if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 1217))) {
								zephir_update_property_array_multi(this_ptr, SL("staticByMethod"), &bucketRoute, SL("zza"), 3, &method, &bucketPattern);
							} else {
								ZEPHIR_OBS_NVAR(&staticBucket);
								zephir_read_property(&_68$$52, this_ptr, ZEND_STRL("staticByMethod"), PH_NOISY_CC | PH_READONLY);
								if (zephir_array_isset_fetch(&staticBucket, &_68$$52, &method, 0)) {
									zephir_is_iterable(&staticBucket, 0, "phalcon/Mvc/Router.zep", 1226);
									if (Z_TYPE_P(&staticBucket) == IS_ARRAY) {
										ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&staticBucket), _70$$53, _71$$53, _69$$53)
										{
											ZEPHIR_INIT_NVAR(&staticUri);
											if (_71$$53 != NULL) { 
												ZVAL_STR_COPY(&staticUri, _71$$53);
											} else {
												ZVAL_LONG(&staticUri, _70$$53);
											}
											ZEPHIR_INIT_NVAR(&staticRoutesList);
											ZVAL_COPY(&staticRoutesList, _69$$53);
											ZEPHIR_INIT_NVAR(&_72$$54);
											ZEPHIR_INIT_NVAR(&_73$$54);
											zephir_preg_match(&_73$$54, &bucketPattern, &staticUri, &_72$$54, 0, 0 , 0 );
											if (zephir_is_true(&_73$$54)) {
												zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
											}
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &staticBucket, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_74$$53, &staticBucket, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_74$$53)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&staticUri, &staticBucket, "key", NULL, 0);
											zephir_check_call_status();
											ZEPHIR_CALL_METHOD(&staticRoutesList, &staticBucket, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_75$$56);
												ZEPHIR_INIT_NVAR(&_76$$56);
												zephir_preg_match(&_76$$56, &bucketPattern, &staticUri, &_75$$56, 0, 0 , 0 );
												if (zephir_is_true(&_76$$56)) {
													zephir_update_property_array_multi(this_ptr, SL("staticShadowedByMethod"), &__$true, SL("zz"), 2, &method, &staticUri);
												}
											ZEPHIR_CALL_METHOD(NULL, &staticBucket, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&staticRoutesList);
									ZEPHIR_INIT_NVAR(&staticUri);
								}
							}
						ZEPHIR_CALL_METHOD(NULL, &candidates, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&bucketRoute);
			ZEPHIR_CALL_METHOD(NULL, &_32, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&candidates);
	ZEPHIR_INIT_NVAR(&method);
	ZEPHIR_INIT_VAR(&_77);
	array_init(&_77);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hostnameByMethod"), &_77);
	ZEPHIR_INIT_VAR(&_78);
	array_init(&_78);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hostnameLessByMethod"), &_78);
	zephir_read_property(&_79, this_ptr, ZEND_STRL("candidatesByMethod"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_79, 0, "phalcon/Mvc/Router.zep", 1263);
	if (Z_TYPE_P(&_79) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_79), _81, _82, _80)
		{
			ZEPHIR_INIT_NVAR(&method);
			if (_82 != NULL) { 
				ZVAL_STR_COPY(&method, _82);
			} else {
				ZVAL_LONG(&method, _81);
			}
			ZEPHIR_INIT_NVAR(&candidates);
			ZVAL_COPY(&candidates, _80);
			ZEPHIR_INIT_NVAR(&_83$$58);
			array_init(&_83$$58);
			zephir_update_property_array(this_ptr, SL("hostnameByMethod"), &method, &_83$$58);
			ZEPHIR_INIT_NVAR(&_84$$58);
			array_init(&_84$$58);
			zephir_update_property_array(this_ptr, SL("hostnameLessByMethod"), &method, &_84$$58);
			zephir_is_iterable(&candidates, 0, "phalcon/Mvc/Router.zep", 1254);
			if (Z_TYPE_P(&candidates) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&candidates), _86$$58, _87$$58, _85$$58)
				{
					ZEPHIR_INIT_NVAR(&bucketIdx);
					if (_87$$58 != NULL) { 
						ZVAL_STR_COPY(&bucketIdx, _87$$58);
					} else {
						ZVAL_LONG(&bucketIdx, _86$$58);
					}
					ZEPHIR_INIT_NVAR(&bucketRoute);
					ZVAL_COPY(&bucketRoute, _85$$58);
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
				while (1) {
					ZEPHIR_CALL_METHOD(&_88$$58, &candidates, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_88$$58)) {
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
					ZEPHIR_CALL_METHOD(NULL, &candidates, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&bucketRoute);
			ZEPHIR_INIT_NVAR(&bucketIdx);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_79, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_89, &_79, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_89)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, &_79, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&candidates, &_79, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_90$$65);
				array_init(&_90$$65);
				zephir_update_property_array(this_ptr, SL("hostnameByMethod"), &method, &_90$$65);
				ZEPHIR_INIT_NVAR(&_91$$65);
				array_init(&_91$$65);
				zephir_update_property_array(this_ptr, SL("hostnameLessByMethod"), &method, &_91$$65);
				zephir_is_iterable(&candidates, 0, "phalcon/Mvc/Router.zep", 1254);
				if (Z_TYPE_P(&candidates) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&candidates), _93$$65, _94$$65, _92$$65)
					{
						ZEPHIR_INIT_NVAR(&bucketIdx);
						if (_94$$65 != NULL) { 
							ZVAL_STR_COPY(&bucketIdx, _94$$65);
						} else {
							ZVAL_LONG(&bucketIdx, _93$$65);
						}
						ZEPHIR_INIT_NVAR(&bucketRoute);
						ZVAL_COPY(&bucketRoute, _92$$65);
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
					while (1) {
						ZEPHIR_CALL_METHOD(&_95$$65, &candidates, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_95$$65)) {
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
						ZEPHIR_CALL_METHOD(NULL, &candidates, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&bucketRoute);
				ZEPHIR_INIT_NVAR(&bucketIdx);
			ZEPHIR_CALL_METHOD(NULL, &_79, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&candidates);
	ZEPHIR_INIT_NVAR(&method);
	ZEPHIR_INIT_VAR(&_96);
	array_init(&_96);
	zephir_update_property_zval(this_ptr, ZEND_STRL("combinedRegexByMethod"), &_96);
	ZEPHIR_INIT_VAR(&_97);
	array_init(&_97);
	zephir_update_property_zval(this_ptr, ZEND_STRL("combinedRegexMarkMap"), &_97);
	ZEPHIR_INIT_VAR(&_98);
	array_init(&_98);
	zephir_update_property_zval(this_ptr, ZEND_STRL("combinedRegexDisabled"), &_98);
	zephir_read_property(&_99, this_ptr, ZEND_STRL("candidatesByMethod"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_99, 0, "phalcon/Mvc/Router.zep", 1345);
	if (Z_TYPE_P(&_99) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_99), _101, _102, _100)
		{
			ZEPHIR_INIT_NVAR(&method);
			if (_102 != NULL) { 
				ZVAL_STR_COPY(&method, _102);
			} else {
				ZVAL_LONG(&method, _101);
			}
			ZEPHIR_INIT_NVAR(&candidates);
			ZVAL_COPY(&candidates, _100);
			zephir_read_property(&_103$$72, this_ptr, ZEND_STRL("hostnameByMethod"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&hostnameBucketRef);
			zephir_array_fetch(&hostnameBucketRef, &_103$$72, &method, PH_NOISY, "phalcon/Mvc/Router.zep", 1271);
			if (!(ZEPHIR_IS_EMPTY(&hostnameBucketRef))) {
				zephir_update_property_array(this_ptr, SL("combinedRegexDisabled"), &method, &__$true);
				continue;
			}
			ZEPHIR_INIT_NVAR(&combinedAlternatives);
			array_init(&combinedAlternatives);
			ZEPHIR_INIT_NVAR(&combinedMark);
			array_init(&combinedMark);
			zephir_is_iterable(&candidates, 0, "phalcon/Mvc/Router.zep", 1302);
			if (Z_TYPE_P(&candidates) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&candidates), _105$$72, _106$$72, _104$$72)
				{
					ZEPHIR_INIT_NVAR(&bucketIdx);
					if (_106$$72 != NULL) { 
						ZVAL_STR_COPY(&bucketIdx, _106$$72);
					} else {
						ZVAL_LONG(&bucketIdx, _105$$72);
					}
					ZEPHIR_INIT_NVAR(&bucketRoute);
					ZVAL_COPY(&bucketRoute, _104$$72);
					ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 1284))) {
						continue;
					}
					ZEPHIR_INIT_NVAR(&combinedBodyMatch);
					array_init(&combinedBodyMatch);
					ZEPHIR_INIT_NVAR(&_107$$74);
					ZVAL_STRING(&_107$$74, "/^#\\^(.+)\\$#u$/");
					ZEPHIR_INIT_NVAR(&_108$$74);
					ZVAL_STRING(&_108$$74, "/^#\\^(.+)\\$#u$/");
					ZEPHIR_INIT_NVAR(&combinedShape);
					zephir_preg_match(&combinedShape, &_108$$74, &bucketPattern, &combinedBodyMatch, 0, 0 , 0 );
					if (!(zephir_is_true(&combinedShape))) {
						zephir_update_property_array(this_ptr, SL("combinedRegexDisabled"), &method, &__$true);
						ZEPHIR_INIT_NVAR(&combinedAlternatives);
						array_init(&combinedAlternatives);
						break;
					}
					ZEPHIR_OBS_NVAR(&combinedBody);
					zephir_array_fetch_long(&combinedBody, &combinedBodyMatch, 1, PH_NOISY, "phalcon/Mvc/Router.zep", 1297);
					ZEPHIR_INIT_NVAR(&_109$$74);
					ZEPHIR_CONCAT_VSVS(&_109$$74, &combinedBody, "(*:", &bucketIdx, ")");
					zephir_array_append(&combinedAlternatives, &_109$$74, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1298);
					zephir_cast_to_string(&_110$$74, &bucketIdx);
					zephir_array_update_zval(&combinedMark, &_110$$74, &bucketIdx, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &candidates, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_111$$72, &candidates, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_111$$72)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&bucketIdx, &candidates, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&bucketRoute, &candidates, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 1284))) {
							continue;
						}
						ZEPHIR_INIT_NVAR(&combinedBodyMatch);
						array_init(&combinedBodyMatch);
						ZEPHIR_INIT_NVAR(&_112$$77);
						ZVAL_STRING(&_112$$77, "/^#\\^(.+)\\$#u$/");
						ZEPHIR_INIT_NVAR(&_113$$77);
						ZVAL_STRING(&_113$$77, "/^#\\^(.+)\\$#u$/");
						ZEPHIR_INIT_NVAR(&combinedShape);
						zephir_preg_match(&combinedShape, &_113$$77, &bucketPattern, &combinedBodyMatch, 0, 0 , 0 );
						if (!(zephir_is_true(&combinedShape))) {
							zephir_update_property_array(this_ptr, SL("combinedRegexDisabled"), &method, &__$true);
							ZEPHIR_INIT_NVAR(&combinedAlternatives);
							array_init(&combinedAlternatives);
							break;
						}
						ZEPHIR_OBS_NVAR(&combinedBody);
						zephir_array_fetch_long(&combinedBody, &combinedBodyMatch, 1, PH_NOISY, "phalcon/Mvc/Router.zep", 1297);
						ZEPHIR_INIT_NVAR(&_114$$77);
						ZEPHIR_CONCAT_VSVS(&_114$$77, &combinedBody, "(*:", &bucketIdx, ")");
						zephir_array_append(&combinedAlternatives, &_114$$77, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1298);
						zephir_cast_to_string(&_115$$77, &bucketIdx);
						zephir_array_update_zval(&combinedMark, &_115$$77, &bucketIdx, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &candidates, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&bucketRoute);
			ZEPHIR_INIT_NVAR(&bucketIdx);
			zephir_read_property(&_116$$72, this_ptr, ZEND_STRL("combinedRegexDisabled"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset_value(&_116$$72, &method)) {
				continue;
			}
			if (ZEPHIR_IS_EMPTY(&combinedAlternatives)) {
				continue;
			}
			ZEPHIR_CALL_FUNCTION(&_117$$72, "array_reverse", &_118, 188, &combinedAlternatives);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&combinedAlternatives, &_117$$72);
			ZEPHIR_INIT_NVAR(&_119$$72);
			zephir_array_keys(&_119$$72, &combinedMark);
			ZEPHIR_CALL_FUNCTION(&reversedMarkIds$$72, "array_reverse", &_118, 188, &_119$$72);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&reversedMarkIds$$72, &reversedMarkIds$$72);
			ZEPHIR_INIT_NVAR(&chunkedPatterns$$72);
			array_init(&chunkedPatterns$$72);
			ZEPHIR_CPY_WRT(&chunkedPatterns$$72, &chunkedPatterns$$72);
			ZEPHIR_INIT_NVAR(&chunkedMarkMaps$$72);
			array_init(&chunkedMarkMaps$$72);
			ZEPHIR_CPY_WRT(&chunkedMarkMaps$$72, &chunkedMarkMaps$$72);
			ZEPHIR_INIT_NVAR(&chunkOffset$$72);
			ZVAL_LONG(&chunkOffset$$72, 0);
			while (1) {
				if (!(ZEPHIR_LT_LONG(&chunkOffset$$72, zephir_fast_count_int(&combinedAlternatives)))) {
					break;
				}
				ZVAL_LONG(&_120$$82, 10);
				ZEPHIR_CALL_FUNCTION(&chunkSlice$$72, "array_slice", &_121, 189, &combinedAlternatives, &chunkOffset$$72, &_120$$82);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&chunkSlice$$72, &chunkSlice$$72);
				ZVAL_LONG(&_120$$82, 10);
				ZEPHIR_CALL_FUNCTION(&chunkMarkSubset$$72, "array_slice", &_121, 189, &reversedMarkIds$$72, &chunkOffset$$72, &_120$$82);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&chunkMarkSubset$$72, &chunkMarkSubset$$72);
				ZEPHIR_INIT_NVAR(&chunkSliceMap$$72);
				array_init(&chunkSliceMap$$72);
				ZEPHIR_CPY_WRT(&chunkSliceMap$$72, &chunkSliceMap$$72);
				zephir_is_iterable(&chunkMarkSubset$$72, 0, "phalcon/Mvc/Router.zep", 1336);
				if (Z_TYPE_P(&chunkMarkSubset$$72) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&chunkMarkSubset$$72), _122$$82)
					{
						ZEPHIR_INIT_NVAR(&chunkMarkId$$72);
						ZVAL_COPY(&chunkMarkId$$72, _122$$82);
						zephir_array_fetch(&_123$$83, &combinedMark, &chunkMarkId$$72, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1333);
						zephir_array_update_zval(&chunkSliceMap$$72, &chunkMarkId$$72, &_123$$83, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &chunkMarkSubset$$72, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_124$$82, &chunkMarkSubset$$72, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_124$$82)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&chunkMarkId$$72, &chunkMarkSubset$$72, "current", NULL, 0);
						zephir_check_call_status();
							zephir_array_fetch(&_125$$84, &combinedMark, &chunkMarkId$$72, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1333);
							zephir_array_update_zval(&chunkSliceMap$$72, &chunkMarkId$$72, &_125$$84, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &chunkMarkSubset$$72, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&chunkMarkId$$72);
				ZEPHIR_INIT_NVAR(&_126$$82);
				zephir_fast_join_str(&_126$$82, SL("|"), &chunkSlice$$72);
				ZEPHIR_INIT_NVAR(&_127$$82);
				ZEPHIR_CONCAT_SVS(&_127$$82, "#^(?|", &_126$$82, ")$#u");
				zephir_array_append(&chunkedPatterns$$72, &_127$$82, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1336);
				zephir_array_append(&chunkedMarkMaps$$72, &chunkSliceMap$$72, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1337);
				ZEPHIR_INIT_NVAR(&_128$$82);
				ZVAL_LONG(&_128$$82, 10);
				ZEPHIR_ADD_ASSIGN(&chunkOffset$$72, &_128$$82);
			}
			zephir_update_property_array(this_ptr, SL("combinedRegexByMethod"), &method, &chunkedPatterns$$72);
			zephir_update_property_array(this_ptr, SL("combinedRegexMarkMap"), &method, &chunkedMarkMaps$$72);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_99, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_129, &_99, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_129)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, &_99, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&candidates, &_99, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_130$$85, this_ptr, ZEND_STRL("hostnameByMethod"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&hostnameBucketRef);
				zephir_array_fetch(&hostnameBucketRef, &_130$$85, &method, PH_NOISY, "phalcon/Mvc/Router.zep", 1271);
				if (!(ZEPHIR_IS_EMPTY(&hostnameBucketRef))) {
					zephir_update_property_array(this_ptr, SL("combinedRegexDisabled"), &method, &__$true);
					continue;
				}
				ZEPHIR_INIT_NVAR(&combinedAlternatives);
				array_init(&combinedAlternatives);
				ZEPHIR_INIT_NVAR(&combinedMark);
				array_init(&combinedMark);
				zephir_is_iterable(&candidates, 0, "phalcon/Mvc/Router.zep", 1302);
				if (Z_TYPE_P(&candidates) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&candidates), _132$$85, _133$$85, _131$$85)
					{
						ZEPHIR_INIT_NVAR(&bucketIdx);
						if (_133$$85 != NULL) { 
							ZVAL_STR_COPY(&bucketIdx, _133$$85);
						} else {
							ZVAL_LONG(&bucketIdx, _132$$85);
						}
						ZEPHIR_INIT_NVAR(&bucketRoute);
						ZVAL_COPY(&bucketRoute, _131$$85);
						ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 1284))) {
							continue;
						}
						ZEPHIR_INIT_NVAR(&combinedBodyMatch);
						array_init(&combinedBodyMatch);
						ZEPHIR_INIT_NVAR(&_134$$87);
						ZVAL_STRING(&_134$$87, "/^#\\^(.+)\\$#u$/");
						ZEPHIR_INIT_NVAR(&_135$$87);
						ZVAL_STRING(&_135$$87, "/^#\\^(.+)\\$#u$/");
						ZEPHIR_INIT_NVAR(&combinedShape);
						zephir_preg_match(&combinedShape, &_135$$87, &bucketPattern, &combinedBodyMatch, 0, 0 , 0 );
						if (!(zephir_is_true(&combinedShape))) {
							zephir_update_property_array(this_ptr, SL("combinedRegexDisabled"), &method, &__$true);
							ZEPHIR_INIT_NVAR(&combinedAlternatives);
							array_init(&combinedAlternatives);
							break;
						}
						ZEPHIR_OBS_NVAR(&combinedBody);
						zephir_array_fetch_long(&combinedBody, &combinedBodyMatch, 1, PH_NOISY, "phalcon/Mvc/Router.zep", 1297);
						ZEPHIR_INIT_NVAR(&_136$$87);
						ZEPHIR_CONCAT_VSVS(&_136$$87, &combinedBody, "(*:", &bucketIdx, ")");
						zephir_array_append(&combinedAlternatives, &_136$$87, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1298);
						zephir_cast_to_string(&_137$$87, &bucketIdx);
						zephir_array_update_zval(&combinedMark, &_137$$87, &bucketIdx, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &candidates, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_138$$85, &candidates, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_138$$85)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&bucketIdx, &candidates, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&bucketRoute, &candidates, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&bucketPattern, &bucketRoute, "getcompiledpattern", NULL, 0);
							zephir_check_call_status();
							if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 1284))) {
								continue;
							}
							ZEPHIR_INIT_NVAR(&combinedBodyMatch);
							array_init(&combinedBodyMatch);
							ZEPHIR_INIT_NVAR(&_139$$90);
							ZVAL_STRING(&_139$$90, "/^#\\^(.+)\\$#u$/");
							ZEPHIR_INIT_NVAR(&_140$$90);
							ZVAL_STRING(&_140$$90, "/^#\\^(.+)\\$#u$/");
							ZEPHIR_INIT_NVAR(&combinedShape);
							zephir_preg_match(&combinedShape, &_140$$90, &bucketPattern, &combinedBodyMatch, 0, 0 , 0 );
							if (!(zephir_is_true(&combinedShape))) {
								zephir_update_property_array(this_ptr, SL("combinedRegexDisabled"), &method, &__$true);
								ZEPHIR_INIT_NVAR(&combinedAlternatives);
								array_init(&combinedAlternatives);
								break;
							}
							ZEPHIR_OBS_NVAR(&combinedBody);
							zephir_array_fetch_long(&combinedBody, &combinedBodyMatch, 1, PH_NOISY, "phalcon/Mvc/Router.zep", 1297);
							ZEPHIR_INIT_NVAR(&_141$$90);
							ZEPHIR_CONCAT_VSVS(&_141$$90, &combinedBody, "(*:", &bucketIdx, ")");
							zephir_array_append(&combinedAlternatives, &_141$$90, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1298);
							zephir_cast_to_string(&_142$$90, &bucketIdx);
							zephir_array_update_zval(&combinedMark, &_142$$90, &bucketIdx, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &candidates, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&bucketRoute);
				ZEPHIR_INIT_NVAR(&bucketIdx);
				zephir_read_property(&_143$$85, this_ptr, ZEND_STRL("combinedRegexDisabled"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset_value(&_143$$85, &method)) {
					continue;
				}
				if (ZEPHIR_IS_EMPTY(&combinedAlternatives)) {
					continue;
				}
				ZEPHIR_CALL_FUNCTION(&_144$$85, "array_reverse", &_118, 188, &combinedAlternatives);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&combinedAlternatives, &_144$$85);
				ZEPHIR_INIT_NVAR(&_145$$85);
				zephir_array_keys(&_145$$85, &combinedMark);
				ZEPHIR_CALL_FUNCTION(&reversedMarkIds$$85, "array_reverse", &_118, 188, &_145$$85);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&reversedMarkIds$$85, &reversedMarkIds$$85);
				ZEPHIR_INIT_NVAR(&chunkedPatterns$$85);
				array_init(&chunkedPatterns$$85);
				ZEPHIR_CPY_WRT(&chunkedPatterns$$85, &chunkedPatterns$$85);
				ZEPHIR_INIT_NVAR(&chunkedMarkMaps$$85);
				array_init(&chunkedMarkMaps$$85);
				ZEPHIR_CPY_WRT(&chunkedMarkMaps$$85, &chunkedMarkMaps$$85);
				ZEPHIR_INIT_NVAR(&chunkOffset$$85);
				ZVAL_LONG(&chunkOffset$$85, 0);
				while (1) {
					if (!(ZEPHIR_LT_LONG(&chunkOffset$$85, zephir_fast_count_int(&combinedAlternatives)))) {
						break;
					}
					ZVAL_LONG(&_146$$95, 10);
					ZEPHIR_CALL_FUNCTION(&chunkSlice$$85, "array_slice", &_121, 189, &combinedAlternatives, &chunkOffset$$85, &_146$$95);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&chunkSlice$$85, &chunkSlice$$85);
					ZVAL_LONG(&_146$$95, 10);
					ZEPHIR_CALL_FUNCTION(&chunkMarkSubset$$85, "array_slice", &_121, 189, &reversedMarkIds$$85, &chunkOffset$$85, &_146$$95);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&chunkMarkSubset$$85, &chunkMarkSubset$$85);
					ZEPHIR_INIT_NVAR(&chunkSliceMap$$85);
					array_init(&chunkSliceMap$$85);
					ZEPHIR_CPY_WRT(&chunkSliceMap$$85, &chunkSliceMap$$85);
					zephir_is_iterable(&chunkMarkSubset$$85, 0, "phalcon/Mvc/Router.zep", 1336);
					if (Z_TYPE_P(&chunkMarkSubset$$85) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&chunkMarkSubset$$85), _147$$95)
						{
							ZEPHIR_INIT_NVAR(&chunkMarkId$$85);
							ZVAL_COPY(&chunkMarkId$$85, _147$$95);
							zephir_array_fetch(&_148$$96, &combinedMark, &chunkMarkId$$85, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1333);
							zephir_array_update_zval(&chunkSliceMap$$85, &chunkMarkId$$85, &_148$$96, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &chunkMarkSubset$$85, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_149$$95, &chunkMarkSubset$$85, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_149$$95)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&chunkMarkId$$85, &chunkMarkSubset$$85, "current", NULL, 0);
							zephir_check_call_status();
								zephir_array_fetch(&_150$$97, &combinedMark, &chunkMarkId$$85, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1333);
								zephir_array_update_zval(&chunkSliceMap$$85, &chunkMarkId$$85, &_150$$97, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &chunkMarkSubset$$85, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&chunkMarkId$$85);
					ZEPHIR_INIT_NVAR(&_151$$95);
					zephir_fast_join_str(&_151$$95, SL("|"), &chunkSlice$$85);
					ZEPHIR_INIT_NVAR(&_152$$95);
					ZEPHIR_CONCAT_SVS(&_152$$95, "#^(?|", &_151$$95, ")$#u");
					zephir_array_append(&chunkedPatterns$$85, &_152$$95, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1336);
					zephir_array_append(&chunkedMarkMaps$$85, &chunkSliceMap$$85, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1337);
					ZEPHIR_INIT_NVAR(&_153$$95);
					ZVAL_LONG(&_153$$95, 10);
					ZEPHIR_ADD_ASSIGN(&chunkOffset$$85, &_153$$95);
				}
				zephir_update_property_array(this_ptr, SL("combinedRegexByMethod"), &method, &chunkedPatterns$$85);
				zephir_update_property_array(this_ptr, SL("combinedRegexMarkMap"), &method, &chunkedMarkMaps$$85);
			ZEPHIR_CALL_METHOD(NULL, &_99, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&candidates);
	ZEPHIR_INIT_NVAR(&method);
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
	zend_string *_6;
	zend_ulong _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, route, routeId, key, _0, _3, *_4, _7, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routeId);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
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
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1360);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/Mvc/Router.zep", 1372);
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
			ZEPHIR_CALL_METHOD(&_7, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
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
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1387);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/Mvc/Router.zep", 1402);
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
		while (1) {
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
	zend_ulong _46$$39, _55$$40, _79$$62, _96$$84, _111$$102, _138$$138;
	zend_bool _1, _11, _15, _39, _40, _42, _20$$15, _25$$15, _59$$46, _60$$49, _62$$51, _66$$54, _67$$57, _69$$59, _82$$68, _83$$71, _85$$73, _89$$76, _90$$79, _92$$81, _114$$103, _116$$109, _120$$112, _122$$118, _141$$139, _143$$145, _147$$148, _149$$154;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_31 = NULL, *_34 = NULL, *_36 = NULL, *_58 = NULL, *_101 = NULL, *_104 = NULL, *_106 = NULL, *_109 = NULL, *_128 = NULL, *_131 = NULL, *_133 = NULL, *_136 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, __$true, __$false, __$null, action, beforeMatch, candidateRoutes, container, controller, converter, converters, currentHostName, eventsManager, handledUri, hostname, matched, matches, matchPosition, module, notFoundPaths, params, paramsStr, part, parts, paths, pattern, position, realUri, regexHostName, request, requestMethod, route, routeFound, routeIdx, routeMeta, staticBeforeMatch, staticBucket, staticBucketMethod, staticHostname, staticHostRegex, staticMatched, staticRoute, strParams, vnamespace, _0, _3, _6, _7, _8, _10, _12, _13, _14, _16, _17, combinedChunks, combinedMarkMaps, combinedChunkIdx, combinedChunk, combinedMatchesLocal, combinedMarkLabel, combinedRouteIdx, combinedRoute, combinedRouteMeta, combinedBeforeMatch, combinedPaths, combinedConverters, combinedPart, combinedPosition, combinedMatchPosition, combinedConverter, _41, _43, _152, _153, _154, _155, _156, _160, _2$$5, _4$$8, _5$$9, _9$$11, _18$$15, _19$$15, _21$$15, _22$$15, _23$$15, _24$$15, _26$$15, _27$$15, _28$$18, _29$$18, *_30$$18, _35$$18, _32$$23, _33$$27, _37$$33, _38$$37, _44$$39, *_45$$39, _71$$39, _48$$40, _49$$40, _50$$40, _51$$40, *_54$$40, _64$$40, _52$$44, _53$$43, _57$$47, _61$$50, _63$$52, _65$$55, _68$$58, _70$$60, _72$$62, _73$$62, _74$$62, _75$$62, *_78$$62, _87$$62, _76$$66, _77$$65, _81$$69, _84$$72, _86$$74, _88$$77, _91$$80, _93$$82, _94$$84, *_95$$84, _124$$84, _98$$85, _99$$85, _100$$85, _102$$89, _103$$92, _105$$96, _107$$98, _108$$100, *_110$$102, _118$$102, _113$$104, _115$$108, _117$$110, _119$$113, _121$$117, _123$$119, _125$$121, _126$$121, _127$$121, _129$$125, _130$$128, _132$$132, _134$$134, _135$$136, *_137$$138, _145$$138, _140$$140, _142$$144, _144$$146, _146$$149, _148$$153, _150$$155, _151$$159, _157$$167, _158$$169, _159$$171, _161$$172, _162$$172, _163$$172, _164$$172;
	zend_string *uri = NULL, *_47$$39, *_56$$40, *_80$$62, *_97$$84, *_112$$102, *_139$$138;
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
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_152);
	ZVAL_UNDEF(&_153);
	ZVAL_UNDEF(&_154);
	ZVAL_UNDEF(&_155);
	ZVAL_UNDEF(&_156);
	ZVAL_UNDEF(&_160);
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
	ZVAL_UNDEF(&_37$$33);
	ZVAL_UNDEF(&_38$$37);
	ZVAL_UNDEF(&_44$$39);
	ZVAL_UNDEF(&_71$$39);
	ZVAL_UNDEF(&_48$$40);
	ZVAL_UNDEF(&_49$$40);
	ZVAL_UNDEF(&_50$$40);
	ZVAL_UNDEF(&_51$$40);
	ZVAL_UNDEF(&_64$$40);
	ZVAL_UNDEF(&_52$$44);
	ZVAL_UNDEF(&_53$$43);
	ZVAL_UNDEF(&_57$$47);
	ZVAL_UNDEF(&_61$$50);
	ZVAL_UNDEF(&_63$$52);
	ZVAL_UNDEF(&_65$$55);
	ZVAL_UNDEF(&_68$$58);
	ZVAL_UNDEF(&_70$$60);
	ZVAL_UNDEF(&_72$$62);
	ZVAL_UNDEF(&_73$$62);
	ZVAL_UNDEF(&_74$$62);
	ZVAL_UNDEF(&_75$$62);
	ZVAL_UNDEF(&_87$$62);
	ZVAL_UNDEF(&_76$$66);
	ZVAL_UNDEF(&_77$$65);
	ZVAL_UNDEF(&_81$$69);
	ZVAL_UNDEF(&_84$$72);
	ZVAL_UNDEF(&_86$$74);
	ZVAL_UNDEF(&_88$$77);
	ZVAL_UNDEF(&_91$$80);
	ZVAL_UNDEF(&_93$$82);
	ZVAL_UNDEF(&_94$$84);
	ZVAL_UNDEF(&_124$$84);
	ZVAL_UNDEF(&_98$$85);
	ZVAL_UNDEF(&_99$$85);
	ZVAL_UNDEF(&_100$$85);
	ZVAL_UNDEF(&_102$$89);
	ZVAL_UNDEF(&_103$$92);
	ZVAL_UNDEF(&_105$$96);
	ZVAL_UNDEF(&_107$$98);
	ZVAL_UNDEF(&_108$$100);
	ZVAL_UNDEF(&_118$$102);
	ZVAL_UNDEF(&_113$$104);
	ZVAL_UNDEF(&_115$$108);
	ZVAL_UNDEF(&_117$$110);
	ZVAL_UNDEF(&_119$$113);
	ZVAL_UNDEF(&_121$$117);
	ZVAL_UNDEF(&_123$$119);
	ZVAL_UNDEF(&_125$$121);
	ZVAL_UNDEF(&_126$$121);
	ZVAL_UNDEF(&_127$$121);
	ZVAL_UNDEF(&_129$$125);
	ZVAL_UNDEF(&_130$$128);
	ZVAL_UNDEF(&_132$$132);
	ZVAL_UNDEF(&_134$$134);
	ZVAL_UNDEF(&_135$$136);
	ZVAL_UNDEF(&_145$$138);
	ZVAL_UNDEF(&_140$$140);
	ZVAL_UNDEF(&_142$$144);
	ZVAL_UNDEF(&_144$$146);
	ZVAL_UNDEF(&_146$$149);
	ZVAL_UNDEF(&_148$$153);
	ZVAL_UNDEF(&_150$$155);
	ZVAL_UNDEF(&_151$$159);
	ZVAL_UNDEF(&_157$$167);
	ZVAL_UNDEF(&_158$$169);
	ZVAL_UNDEF(&_159$$171);
	ZVAL_UNDEF(&_161$$172);
	ZVAL_UNDEF(&_162$$172);
	ZVAL_UNDEF(&_163$$172);
	ZVAL_UNDEF(&_164$$172);
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
		ZEPHIR_INIT_VAR(&_5$$9);
		object_init_ex(&_5$$9, phalcon_mvc_router_exceptions_requestserviceunavailable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$9, "__construct", NULL, 190);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$9, "phalcon/Mvc/Router.zep", 1478);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "request");
	ZEPHIR_CALL_METHOD(&_6, &container, "get", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&request, &_6);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("methodRoutesDirty"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_3)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rebuildmethodindex", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&requestMethod, &request, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&candidateRoutes);
	array_init(&candidateRoutes);
	ZEPHIR_OBS_NVAR(&candidateRoutes);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("candidatesByMethod"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&candidateRoutes, &_8, &requestMethod, 0))) {
		ZEPHIR_OBS_NVAR(&candidateRoutes);
		zephir_read_property(&_9$$11, this_ptr, ZEND_STRL("candidatesByMethod"), PH_NOISY_CC | PH_READONLY);
		zephir_array_isset_string_fetch(&candidateRoutes, &_9$$11, SL("*"), 0);
	}
	if (Z_TYPE_P(&candidateRoutes) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&candidateRoutes);
		array_init(&candidateRoutes);
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("hostnameByMethod"), PH_NOISY_CC | PH_READONLY);
	_11 = zephir_array_isset_value(&_10, &requestMethod);
	if (_11) {
		zephir_read_property(&_12, this_ptr, ZEND_STRL("hostnameByMethod"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_13, &_12, &requestMethod, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1510);
		_11 = zephir_fast_count_int(&_13) > 0;
	}
	zephir_read_property(&_14, this_ptr, ZEND_STRL("hostnameByMethod"), PH_NOISY_CC | PH_READONLY);
	_15 = zephir_array_isset_value_string(&_14, SL("*"));
	if (_15) {
		zephir_read_property(&_16, this_ptr, ZEND_STRL("hostnameByMethod"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_17, &_16, SL("*"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1513);
		_15 = zephir_fast_count_int(&_17) > 0;
	}
	if (_11) {
		ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", NULL, 0);
		zephir_check_call_status();
	} else if (_15) {
		ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&eventsManager) == IS_NULL) {
		ZEPHIR_INIT_VAR(&staticBucketMethod);
		ZVAL_NULL(&staticBucketMethod);
		zephir_read_property(&_18$$15, this_ptr, ZEND_STRL("staticByMethod"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_19$$15, &_18$$15, &requestMethod, PH_READONLY, "phalcon/Mvc/Router.zep", 1526);
		_20$$15 = zephir_array_isset_value(&_19$$15, &handledUri);
		if (_20$$15) {
			zephir_read_property(&_21$$15, this_ptr, ZEND_STRL("staticShadowedByMethod"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_22$$15, &_21$$15, &requestMethod, PH_READONLY, "phalcon/Mvc/Router.zep", 1527);
			_20$$15 = !(zephir_array_isset_value(&_22$$15, &handledUri));
		}
		zephir_read_property(&_23$$15, this_ptr, ZEND_STRL("staticByMethod"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_24$$15, &_23$$15, SL("*"), PH_READONLY, "phalcon/Mvc/Router.zep", 1529);
		_25$$15 = zephir_array_isset_value(&_24$$15, &handledUri);
		if (_25$$15) {
			zephir_read_property(&_26$$15, this_ptr, ZEND_STRL("staticShadowedByMethod"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_27$$15, &_26$$15, SL("*"), PH_READONLY, "phalcon/Mvc/Router.zep", 1530);
			_25$$15 = !(zephir_array_isset_value(&_27$$15, &handledUri));
		}
		if (_20$$15) {
			ZEPHIR_CPY_WRT(&staticBucketMethod, &requestMethod);
		} else if (_25$$15) {
			ZEPHIR_INIT_NVAR(&staticBucketMethod);
			ZVAL_STRING(&staticBucketMethod, "*");
		}
		if (Z_TYPE_P(&staticBucketMethod) != IS_NULL) {
			zephir_read_property(&_28$$18, this_ptr, ZEND_STRL("staticByMethod"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_29$$18, &_28$$18, &staticBucketMethod, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1535);
			zephir_memory_observe(&staticBucket);
			zephir_array_fetch(&staticBucket, &_29$$18, &handledUri, PH_NOISY, "phalcon/Mvc/Router.zep", 1535);
			zephir_is_iterable(&staticBucket, 0, "phalcon/Mvc/Router.zep", 1583);
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
							ZEPHIR_CALL_METHOD(NULL, &_33$$27, "__construct", &_34, 191);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_33$$27, "phalcon/Mvc/Router.zep", 1566);
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
					zephir_update_property_zval(this_ptr, ZEND_STRL("matchedRoute"), &staticRoute);
					break;
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &staticBucket, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
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
								ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", &_36, 0);
								zephir_check_call_status();
							}
							if (!(zephir_is_true(&currentHostName))) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&staticHostRegex, &staticRoute, "getcompiledhostname", NULL, 0);
							zephir_check_call_status();
							if (Z_TYPE_P(&staticHostRegex) != IS_NULL) {
								ZEPHIR_INIT_NVAR(&_37$$33);
								ZEPHIR_INIT_NVAR(&staticMatched);
								zephir_preg_match(&staticMatched, &staticHostRegex, &currentHostName, &_37$$33, 0, 0 , 0 );
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
								ZEPHIR_INIT_NVAR(&_38$$37);
								object_init_ex(&_38$$37, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
								ZEPHIR_CALL_METHOD(NULL, &_38$$37, "__construct", &_34, 191);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_38$$37, "phalcon/Mvc/Router.zep", 1566);
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
						zephir_update_property_zval(this_ptr, ZEND_STRL("matchedRoute"), &staticRoute);
						break;
					ZEPHIR_CALL_METHOD(NULL, &staticBucket, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&staticRoute);
		}
	}
	_39 = !zephir_is_true(&routeFound);
	if (_39) {
		_39 = Z_TYPE_P(&eventsManager) == IS_NULL;
	}
	_40 = _39;
	if (_40) {
		zephir_read_property(&_41, this_ptr, ZEND_STRL("combinedRegexDisabled"), PH_NOISY_CC | PH_READONLY);
		_40 = !(zephir_array_isset_value(&_41, &requestMethod));
	}
	_42 = _40;
	if (_42) {
		zephir_memory_observe(&combinedChunks);
		zephir_read_property(&_43, this_ptr, ZEND_STRL("combinedRegexByMethod"), PH_NOISY_CC | PH_READONLY);
		_42 = zephir_array_isset_fetch(&combinedChunks, &_43, &requestMethod, 0);
	}
	if (_42) {
		zephir_read_property(&_44$$39, this_ptr, ZEND_STRL("combinedRegexMarkMap"), PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&combinedMarkMaps);
		zephir_array_fetch(&combinedMarkMaps, &_44$$39, &requestMethod, PH_NOISY, "phalcon/Mvc/Router.zep", 1602);
		zephir_is_iterable(&combinedChunks, 0, "phalcon/Mvc/Router.zep", 1667);
		if (Z_TYPE_P(&combinedChunks) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&combinedChunks), _46$$39, _47$$39, _45$$39)
			{
				ZEPHIR_INIT_NVAR(&combinedChunkIdx);
				if (_47$$39 != NULL) { 
					ZVAL_STR_COPY(&combinedChunkIdx, _47$$39);
				} else {
					ZVAL_LONG(&combinedChunkIdx, _46$$39);
				}
				ZEPHIR_INIT_NVAR(&combinedChunk);
				ZVAL_COPY(&combinedChunk, _45$$39);
				ZEPHIR_INIT_NVAR(&combinedMatchesLocal);
				array_init(&combinedMatchesLocal);
				ZEPHIR_INIT_NVAR(&_48$$40);
				zephir_preg_match(&_48$$40, &combinedChunk, &handledUri, &combinedMatchesLocal, 0, 0 , 0 );
				if (!(zephir_is_true(&_48$$40))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&combinedMarkLabel);
				zephir_array_fetch_string(&combinedMarkLabel, &combinedMatchesLocal, SL("MARK"), PH_NOISY, "phalcon/Mvc/Router.zep", 1611);
				ZEPHIR_OBS_NVAR(&combinedRouteIdx);
				zephir_array_fetch(&_49$$40, &combinedMarkMaps, &combinedChunkIdx, PH_READONLY, "phalcon/Mvc/Router.zep", 1613);
				if (!(zephir_array_isset_fetch(&combinedRouteIdx, &_49$$40, &combinedMarkLabel, 0))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&combinedRoute);
				zephir_array_fetch(&combinedRoute, &candidateRoutes, &combinedRouteIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1617);
				zephir_read_property(&_50$$40, this_ptr, ZEND_STRL("routeMeta"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&combinedRouteMeta);
				ZEPHIR_CALL_METHOD(&_51$$40, &combinedRoute, "getrouteid", NULL, 0);
				zephir_check_call_status();
				zephir_array_fetch(&combinedRouteMeta, &_50$$40, &_51$$40, PH_NOISY, "phalcon/Mvc/Router.zep", 1618);
				ZEPHIR_OBS_NVAR(&combinedBeforeMatch);
				zephir_array_fetch_string(&combinedBeforeMatch, &combinedRouteMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1620);
				if (Z_TYPE_P(&combinedBeforeMatch) != IS_NULL) {
					if (UNEXPECTED(!(zephir_is_callable(&combinedBeforeMatch)))) {
						ZEPHIR_INIT_NVAR(&_52$$44);
						object_init_ex(&_52$$44, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
						ZEPHIR_CALL_METHOD(NULL, &_52$$44, "__construct", &_34, 191);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_52$$44, "phalcon/Mvc/Router.zep", 1624);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_ZVAL_FUNCTION(&_53$$43, &combinedBeforeMatch, NULL, 0, &handledUri, &combinedRoute, this_ptr);
					zephir_check_call_status();
					if (!(zephir_is_true(&_53$$43))) {
						continue;
					}
				}
				ZEPHIR_CALL_METHOD(&combinedPaths, &combinedRoute, "getpaths", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&parts, &combinedPaths);
				ZEPHIR_CPY_WRT(&matches, &combinedMatchesLocal);
				ZEPHIR_CALL_METHOD(&combinedConverters, &combinedRoute, "getconverters", NULL, 0);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, ZEND_STRL("matches"), &combinedMatchesLocal);
				zephir_update_property_zval(this_ptr, ZEND_STRL("matchedRoute"), &combinedRoute);
				ZEPHIR_INIT_NVAR(&routeFound);
				ZVAL_BOOL(&routeFound, 1);
				zephir_is_iterable(&combinedPaths, 0, "phalcon/Mvc/Router.zep", 1665);
				if (Z_TYPE_P(&combinedPaths) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&combinedPaths), _55$$40, _56$$40, _54$$40)
					{
						ZEPHIR_INIT_NVAR(&combinedPart);
						if (_56$$40 != NULL) { 
							ZVAL_STR_COPY(&combinedPart, _56$$40);
						} else {
							ZVAL_LONG(&combinedPart, _55$$40);
						}
						ZEPHIR_INIT_NVAR(&combinedPosition);
						ZVAL_COPY(&combinedPosition, _54$$40);
						if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
							ZEPHIR_INIT_NVAR(&_57$$47);
							object_init_ex(&_57$$47, phalcon_mvc_router_exceptions_wrongpathskey_ce);
							ZEPHIR_CALL_METHOD(NULL, &_57$$47, "__construct", &_58, 192, &combinedPart);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_57$$47, "phalcon/Mvc/Router.zep", 1642);
							ZEPHIR_MM_RESTORE();
							return;
						}
						_59$$46 = Z_TYPE_P(&combinedPosition) != IS_STRING;
						if (_59$$46) {
							_59$$46 = Z_TYPE_P(&combinedPosition) != IS_LONG;
						}
						if (_59$$46) {
							continue;
						}
						ZEPHIR_OBS_NVAR(&combinedMatchPosition);
						if (zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0)) {
							_60$$49 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
							if (_60$$49) {
								ZEPHIR_OBS_NVAR(&combinedConverter);
								_60$$49 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
							}
							if (_60$$49) {
								ZEPHIR_CALL_ZVAL_FUNCTION(&_61$$50, &combinedConverter, NULL, 0, &combinedMatchPosition);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, &combinedPart, &_61$$50, PH_COPY | PH_SEPARATE);
								continue;
							}
							zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
						} else {
							_62$$51 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
							if (_62$$51) {
								ZEPHIR_OBS_NVAR(&combinedConverter);
								_62$$51 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
							}
							if (_62$$51) {
								ZEPHIR_CALL_ZVAL_FUNCTION(&_63$$52, &combinedConverter, NULL, 0, &combinedPosition);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, &combinedPart, &_63$$52, PH_COPY | PH_SEPARATE);
							} else if (Z_TYPE_P(&combinedPosition) == IS_LONG) {
								zephir_array_unset(&parts, &combinedPart, PH_SEPARATE);
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &combinedPaths, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_64$$40, &combinedPaths, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_64$$40)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&combinedPart, &combinedPaths, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&combinedPosition, &combinedPaths, "current", NULL, 0);
						zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
								ZEPHIR_INIT_NVAR(&_65$$55);
								object_init_ex(&_65$$55, phalcon_mvc_router_exceptions_wrongpathskey_ce);
								ZEPHIR_CALL_METHOD(NULL, &_65$$55, "__construct", &_58, 192, &combinedPart);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_65$$55, "phalcon/Mvc/Router.zep", 1642);
								ZEPHIR_MM_RESTORE();
								return;
							}
							_66$$54 = Z_TYPE_P(&combinedPosition) != IS_STRING;
							if (_66$$54) {
								_66$$54 = Z_TYPE_P(&combinedPosition) != IS_LONG;
							}
							if (_66$$54) {
								continue;
							}
							ZEPHIR_OBS_NVAR(&combinedMatchPosition);
							if (zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0)) {
								_67$$57 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_67$$57) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_67$$57 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								}
								if (_67$$57) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_68$$58, &combinedConverter, NULL, 0, &combinedMatchPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_68$$58, PH_COPY | PH_SEPARATE);
									continue;
								}
								zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
							} else {
								_69$$59 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_69$$59) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_69$$59 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								}
								if (_69$$59) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_70$$60, &combinedConverter, NULL, 0, &combinedPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_70$$60, PH_COPY | PH_SEPARATE);
								} else if (Z_TYPE_P(&combinedPosition) == IS_LONG) {
									zephir_array_unset(&parts, &combinedPart, PH_SEPARATE);
								}
							}
						ZEPHIR_CALL_METHOD(NULL, &combinedPaths, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&combinedPosition);
				ZEPHIR_INIT_NVAR(&combinedPart);
				break;
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &combinedChunks, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_71$$39, &combinedChunks, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_71$$39)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&combinedChunkIdx, &combinedChunks, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&combinedChunk, &combinedChunks, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&combinedMatchesLocal);
					array_init(&combinedMatchesLocal);
					ZEPHIR_INIT_NVAR(&_72$$62);
					zephir_preg_match(&_72$$62, &combinedChunk, &handledUri, &combinedMatchesLocal, 0, 0 , 0 );
					if (!(zephir_is_true(&_72$$62))) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&combinedMarkLabel);
					zephir_array_fetch_string(&combinedMarkLabel, &combinedMatchesLocal, SL("MARK"), PH_NOISY, "phalcon/Mvc/Router.zep", 1611);
					ZEPHIR_OBS_NVAR(&combinedRouteIdx);
					zephir_array_fetch(&_73$$62, &combinedMarkMaps, &combinedChunkIdx, PH_READONLY, "phalcon/Mvc/Router.zep", 1613);
					if (!(zephir_array_isset_fetch(&combinedRouteIdx, &_73$$62, &combinedMarkLabel, 0))) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&combinedRoute);
					zephir_array_fetch(&combinedRoute, &candidateRoutes, &combinedRouteIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1617);
					zephir_read_property(&_74$$62, this_ptr, ZEND_STRL("routeMeta"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&combinedRouteMeta);
					ZEPHIR_CALL_METHOD(&_75$$62, &combinedRoute, "getrouteid", NULL, 0);
					zephir_check_call_status();
					zephir_array_fetch(&combinedRouteMeta, &_74$$62, &_75$$62, PH_NOISY, "phalcon/Mvc/Router.zep", 1618);
					ZEPHIR_OBS_NVAR(&combinedBeforeMatch);
					zephir_array_fetch_string(&combinedBeforeMatch, &combinedRouteMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1620);
					if (Z_TYPE_P(&combinedBeforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&combinedBeforeMatch)))) {
							ZEPHIR_INIT_NVAR(&_76$$66);
							object_init_ex(&_76$$66, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD(NULL, &_76$$66, "__construct", &_34, 191);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_76$$66, "phalcon/Mvc/Router.zep", 1624);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_ZVAL_FUNCTION(&_77$$65, &combinedBeforeMatch, NULL, 0, &handledUri, &combinedRoute, this_ptr);
						zephir_check_call_status();
						if (!(zephir_is_true(&_77$$65))) {
							continue;
						}
					}
					ZEPHIR_CALL_METHOD(&combinedPaths, &combinedRoute, "getpaths", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&parts, &combinedPaths);
					ZEPHIR_CPY_WRT(&matches, &combinedMatchesLocal);
					ZEPHIR_CALL_METHOD(&combinedConverters, &combinedRoute, "getconverters", NULL, 0);
					zephir_check_call_status();
					zephir_update_property_zval(this_ptr, ZEND_STRL("matches"), &combinedMatchesLocal);
					zephir_update_property_zval(this_ptr, ZEND_STRL("matchedRoute"), &combinedRoute);
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, 1);
					zephir_is_iterable(&combinedPaths, 0, "phalcon/Mvc/Router.zep", 1665);
					if (Z_TYPE_P(&combinedPaths) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&combinedPaths), _79$$62, _80$$62, _78$$62)
						{
							ZEPHIR_INIT_NVAR(&combinedPart);
							if (_80$$62 != NULL) { 
								ZVAL_STR_COPY(&combinedPart, _80$$62);
							} else {
								ZVAL_LONG(&combinedPart, _79$$62);
							}
							ZEPHIR_INIT_NVAR(&combinedPosition);
							ZVAL_COPY(&combinedPosition, _78$$62);
							if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
								ZEPHIR_INIT_NVAR(&_81$$69);
								object_init_ex(&_81$$69, phalcon_mvc_router_exceptions_wrongpathskey_ce);
								ZEPHIR_CALL_METHOD(NULL, &_81$$69, "__construct", &_58, 192, &combinedPart);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_81$$69, "phalcon/Mvc/Router.zep", 1642);
								ZEPHIR_MM_RESTORE();
								return;
							}
							_82$$68 = Z_TYPE_P(&combinedPosition) != IS_STRING;
							if (_82$$68) {
								_82$$68 = Z_TYPE_P(&combinedPosition) != IS_LONG;
							}
							if (_82$$68) {
								continue;
							}
							ZEPHIR_OBS_NVAR(&combinedMatchPosition);
							if (zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0)) {
								_83$$71 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_83$$71) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_83$$71 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								}
								if (_83$$71) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_84$$72, &combinedConverter, NULL, 0, &combinedMatchPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_84$$72, PH_COPY | PH_SEPARATE);
									continue;
								}
								zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
							} else {
								_85$$73 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_85$$73) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_85$$73 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								}
								if (_85$$73) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_86$$74, &combinedConverter, NULL, 0, &combinedPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_86$$74, PH_COPY | PH_SEPARATE);
								} else if (Z_TYPE_P(&combinedPosition) == IS_LONG) {
									zephir_array_unset(&parts, &combinedPart, PH_SEPARATE);
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &combinedPaths, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_87$$62, &combinedPaths, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_87$$62)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&combinedPart, &combinedPaths, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&combinedPosition, &combinedPaths, "current", NULL, 0);
							zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
									ZEPHIR_INIT_NVAR(&_88$$77);
									object_init_ex(&_88$$77, phalcon_mvc_router_exceptions_wrongpathskey_ce);
									ZEPHIR_CALL_METHOD(NULL, &_88$$77, "__construct", &_58, 192, &combinedPart);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_88$$77, "phalcon/Mvc/Router.zep", 1642);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_89$$76 = Z_TYPE_P(&combinedPosition) != IS_STRING;
								if (_89$$76) {
									_89$$76 = Z_TYPE_P(&combinedPosition) != IS_LONG;
								}
								if (_89$$76) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&combinedMatchPosition);
								if (zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0)) {
									_90$$79 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
									if (_90$$79) {
										ZEPHIR_OBS_NVAR(&combinedConverter);
										_90$$79 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
									}
									if (_90$$79) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_91$$80, &combinedConverter, NULL, 0, &combinedMatchPosition);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &combinedPart, &_91$$80, PH_COPY | PH_SEPARATE);
										continue;
									}
									zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
								} else {
									_92$$81 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
									if (_92$$81) {
										ZEPHIR_OBS_NVAR(&combinedConverter);
										_92$$81 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
									}
									if (_92$$81) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_93$$82, &combinedConverter, NULL, 0, &combinedPosition);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &combinedPart, &_93$$82, PH_COPY | PH_SEPARATE);
									} else if (Z_TYPE_P(&combinedPosition) == IS_LONG) {
										zephir_array_unset(&parts, &combinedPart, PH_SEPARATE);
									}
								}
							ZEPHIR_CALL_METHOD(NULL, &combinedPaths, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&combinedPosition);
					ZEPHIR_INIT_NVAR(&combinedPart);
					break;
				ZEPHIR_CALL_METHOD(NULL, &combinedChunks, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&combinedChunk);
		ZEPHIR_INIT_NVAR(&combinedChunkIdx);
	}
	if (!(zephir_is_true(&routeFound))) {
		ZEPHIR_CALL_FUNCTION(&_94$$84, "array_reverse", NULL, 188, &candidateRoutes, &__$true);
		zephir_check_call_status();
		zephir_is_iterable(&_94$$84, 0, "phalcon/Mvc/Router.zep", 1827);
		if (Z_TYPE_P(&_94$$84) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_94$$84), _96$$84, _97$$84, _95$$84)
			{
				ZEPHIR_INIT_NVAR(&routeIdx);
				if (_97$$84 != NULL) { 
					ZVAL_STR_COPY(&routeIdx, _97$$84);
				} else {
					ZVAL_LONG(&routeIdx, _96$$84);
				}
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _95$$84);
				zephir_read_property(&_98$$85, this_ptr, ZEND_STRL("routeMeta"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_100$$85, &route, "getrouteid", NULL, 0);
				zephir_check_call_status();
				zephir_array_fetch(&_99$$85, &_98$$85, &_100$$85, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1675);
				ZEPHIR_CPY_WRT(&routeMeta, &_99$$85);
				ZEPHIR_INIT_NVAR(&params);
				array_init(&params);
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				ZEPHIR_OBS_NVAR(&hostname);
				zephir_array_fetch_string(&hostname, &routeMeta, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1682);
				if (Z_TYPE_P(&hostname) != IS_NULL) {
					if (Z_TYPE_P(&currentHostName) == IS_NULL) {
						ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", &_101, 0);
						zephir_check_call_status();
					}
					if (!(zephir_is_true(&currentHostName))) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&regexHostName);
					zephir_array_fetch_string(&regexHostName, &routeMeta, SL("hostRegex"), PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
					if (Z_TYPE_P(&regexHostName) != IS_NULL) {
						ZEPHIR_INIT_NVAR(&_102$$89);
						ZEPHIR_INIT_NVAR(&matched);
						zephir_preg_match(&matched, &regexHostName, &currentHostName, &_102$$89, 0, 0 , 0 );
					} else {
						ZEPHIR_INIT_NVAR(&matched);
						ZVAL_BOOL(&matched, ZEPHIR_IS_EQUAL(&currentHostName, &hostname));
					}
					if (!(zephir_is_true(&matched))) {
						continue;
					}
				}
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_103$$92);
					ZVAL_STRING(&_103$$92, "router:beforeCheckRoute");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_104, 0, &_103$$92, this_ptr, &route);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&pattern);
				zephir_array_fetch_string(&pattern, &routeMeta, SL("pattern"), PH_NOISY, "phalcon/Mvc/Router.zep", 1722);
				zephir_array_fetch_string(&_99$$85, &routeMeta, SL("isRegex"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1724);
				if (zephir_is_true(&_99$$85)) {
					ZEPHIR_INIT_NVAR(&routeFound);
					zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
				} else {
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, &handledUri));
				}
				if (zephir_is_true(&routeFound)) {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_105$$96);
						ZVAL_STRING(&_105$$96, "router:matchedRoute");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_106, 0, &_105$$96, this_ptr, &route);
						zephir_check_call_status();
					}
					ZEPHIR_OBS_NVAR(&beforeMatch);
					zephir_array_fetch_string(&beforeMatch, &routeMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1738);
					if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
							ZEPHIR_INIT_NVAR(&_107$$98);
							object_init_ex(&_107$$98, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD(NULL, &_107$$98, "__construct", &_34, 191);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_107$$98, "phalcon/Mvc/Router.zep", 1744);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &beforeMatch, NULL, 0, &handledUri, &route, this_ptr);
						zephir_check_call_status();
					}
				} else {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_108$$100);
						ZVAL_STRING(&_108$$100, "router:notMatchedRoute");
						ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_109, 0, &_108$$100, this_ptr, &route);
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
						zephir_is_iterable(&paths, 0, "phalcon/Mvc/Router.zep", 1819);
						if (Z_TYPE_P(&paths) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _111$$102, _112$$102, _110$$102)
							{
								ZEPHIR_INIT_NVAR(&part);
								if (_112$$102 != NULL) { 
									ZVAL_STR_COPY(&part, _112$$102);
								} else {
									ZVAL_LONG(&part, _111$$102);
								}
								ZEPHIR_INIT_NVAR(&position);
								ZVAL_COPY(&position, _110$$102);
								if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
									ZEPHIR_INIT_NVAR(&_113$$104);
									object_init_ex(&_113$$104, phalcon_mvc_router_exceptions_wrongpathskey_ce);
									ZEPHIR_CALL_METHOD(NULL, &_113$$104, "__construct", &_58, 192, &part);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_113$$104, "phalcon/Mvc/Router.zep", 1777);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_114$$103 = Z_TYPE_P(&position) != IS_STRING;
								if (_114$$103) {
									_114$$103 = Z_TYPE_P(&position) != IS_LONG;
								}
								if (_114$$103) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&matchPosition);
								if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_115$$108, &converter, NULL, 0, &matchPosition);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_115$$108, PH_COPY | PH_SEPARATE);
											continue;
										}
									}
									zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
								} else {
									_116$$109 = Z_TYPE_P(&converters) == IS_ARRAY;
									if (_116$$109) {
										ZEPHIR_OBS_NVAR(&converter);
										_116$$109 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
									}
									if (_116$$109) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_117$$110, &converter, NULL, 0, &position);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_117$$110, PH_COPY | PH_SEPARATE);
									} else if (Z_TYPE_P(&position) == IS_LONG) {
										zephir_array_unset(&parts, &part, PH_SEPARATE);
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_118$$102, &paths, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_118$$102)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&part, &paths, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&position, &paths, "current", NULL, 0);
								zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
										ZEPHIR_INIT_NVAR(&_119$$113);
										object_init_ex(&_119$$113, phalcon_mvc_router_exceptions_wrongpathskey_ce);
										ZEPHIR_CALL_METHOD(NULL, &_119$$113, "__construct", &_58, 192, &part);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_119$$113, "phalcon/Mvc/Router.zep", 1777);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_120$$112 = Z_TYPE_P(&position) != IS_STRING;
									if (_120$$112) {
										_120$$112 = Z_TYPE_P(&position) != IS_LONG;
									}
									if (_120$$112) {
										continue;
									}
									ZEPHIR_OBS_NVAR(&matchPosition);
									if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_121$$117, &converter, NULL, 0, &matchPosition);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_121$$117, PH_COPY | PH_SEPARATE);
												continue;
											}
										}
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
									} else {
										_122$$118 = Z_TYPE_P(&converters) == IS_ARRAY;
										if (_122$$118) {
											ZEPHIR_OBS_NVAR(&converter);
											_122$$118 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										}
										if (_122$$118) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_123$$119, &converter, NULL, 0, &position);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_123$$119, PH_COPY | PH_SEPARATE);
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
			ZEPHIR_CALL_METHOD(NULL, &_94$$84, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_124$$84, &_94$$84, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_124$$84)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&routeIdx, &_94$$84, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&route, &_94$$84, "current", NULL, 0);
				zephir_check_call_status();
					zephir_read_property(&_125$$121, this_ptr, ZEND_STRL("routeMeta"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_127$$121, &route, "getrouteid", NULL, 0);
					zephir_check_call_status();
					zephir_array_fetch(&_126$$121, &_125$$121, &_127$$121, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1675);
					ZEPHIR_CPY_WRT(&routeMeta, &_126$$121);
					ZEPHIR_INIT_NVAR(&params);
					array_init(&params);
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					ZEPHIR_OBS_NVAR(&hostname);
					zephir_array_fetch_string(&hostname, &routeMeta, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1682);
					if (Z_TYPE_P(&hostname) != IS_NULL) {
						if (Z_TYPE_P(&currentHostName) == IS_NULL) {
							ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", &_128, 0);
							zephir_check_call_status();
						}
						if (!(zephir_is_true(&currentHostName))) {
							continue;
						}
						ZEPHIR_OBS_NVAR(&regexHostName);
						zephir_array_fetch_string(&regexHostName, &routeMeta, SL("hostRegex"), PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
						if (Z_TYPE_P(&regexHostName) != IS_NULL) {
							ZEPHIR_INIT_NVAR(&_129$$125);
							ZEPHIR_INIT_NVAR(&matched);
							zephir_preg_match(&matched, &regexHostName, &currentHostName, &_129$$125, 0, 0 , 0 );
						} else {
							ZEPHIR_INIT_NVAR(&matched);
							ZVAL_BOOL(&matched, ZEPHIR_IS_EQUAL(&currentHostName, &hostname));
						}
						if (!(zephir_is_true(&matched))) {
							continue;
						}
					}
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_130$$128);
						ZVAL_STRING(&_130$$128, "router:beforeCheckRoute");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_131, 0, &_130$$128, this_ptr, &route);
						zephir_check_call_status();
					}
					ZEPHIR_OBS_NVAR(&pattern);
					zephir_array_fetch_string(&pattern, &routeMeta, SL("pattern"), PH_NOISY, "phalcon/Mvc/Router.zep", 1722);
					zephir_array_fetch_string(&_126$$121, &routeMeta, SL("isRegex"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1724);
					if (zephir_is_true(&_126$$121)) {
						ZEPHIR_INIT_NVAR(&routeFound);
						zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
					} else {
						ZEPHIR_INIT_NVAR(&routeFound);
						ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, &handledUri));
					}
					if (zephir_is_true(&routeFound)) {
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_132$$132);
							ZVAL_STRING(&_132$$132, "router:matchedRoute");
							ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_133, 0, &_132$$132, this_ptr, &route);
							zephir_check_call_status();
						}
						ZEPHIR_OBS_NVAR(&beforeMatch);
						zephir_array_fetch_string(&beforeMatch, &routeMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1738);
						if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
							if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
								ZEPHIR_INIT_NVAR(&_134$$134);
								object_init_ex(&_134$$134, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
								ZEPHIR_CALL_METHOD(NULL, &_134$$134, "__construct", &_34, 191);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_134$$134, "phalcon/Mvc/Router.zep", 1744);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &beforeMatch, NULL, 0, &handledUri, &route, this_ptr);
							zephir_check_call_status();
						}
					} else {
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_135$$136);
							ZVAL_STRING(&_135$$136, "router:notMatchedRoute");
							ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_136, 0, &_135$$136, this_ptr, &route);
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
							zephir_is_iterable(&paths, 0, "phalcon/Mvc/Router.zep", 1819);
							if (Z_TYPE_P(&paths) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _138$$138, _139$$138, _137$$138)
								{
									ZEPHIR_INIT_NVAR(&part);
									if (_139$$138 != NULL) { 
										ZVAL_STR_COPY(&part, _139$$138);
									} else {
										ZVAL_LONG(&part, _138$$138);
									}
									ZEPHIR_INIT_NVAR(&position);
									ZVAL_COPY(&position, _137$$138);
									if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
										ZEPHIR_INIT_NVAR(&_140$$140);
										object_init_ex(&_140$$140, phalcon_mvc_router_exceptions_wrongpathskey_ce);
										ZEPHIR_CALL_METHOD(NULL, &_140$$140, "__construct", &_58, 192, &part);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_140$$140, "phalcon/Mvc/Router.zep", 1777);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_141$$139 = Z_TYPE_P(&position) != IS_STRING;
									if (_141$$139) {
										_141$$139 = Z_TYPE_P(&position) != IS_LONG;
									}
									if (_141$$139) {
										continue;
									}
									ZEPHIR_OBS_NVAR(&matchPosition);
									if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_142$$144, &converter, NULL, 0, &matchPosition);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_142$$144, PH_COPY | PH_SEPARATE);
												continue;
											}
										}
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
									} else {
										_143$$145 = Z_TYPE_P(&converters) == IS_ARRAY;
										if (_143$$145) {
											ZEPHIR_OBS_NVAR(&converter);
											_143$$145 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										}
										if (_143$$145) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_144$$146, &converter, NULL, 0, &position);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_144$$146, PH_COPY | PH_SEPARATE);
										} else if (Z_TYPE_P(&position) == IS_LONG) {
											zephir_array_unset(&parts, &part, PH_SEPARATE);
										}
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_145$$138, &paths, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_145$$138)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&part, &paths, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&position, &paths, "current", NULL, 0);
									zephir_check_call_status();
										if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
											ZEPHIR_INIT_NVAR(&_146$$149);
											object_init_ex(&_146$$149, phalcon_mvc_router_exceptions_wrongpathskey_ce);
											ZEPHIR_CALL_METHOD(NULL, &_146$$149, "__construct", &_58, 192, &part);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_146$$149, "phalcon/Mvc/Router.zep", 1777);
											ZEPHIR_MM_RESTORE();
											return;
										}
										_147$$148 = Z_TYPE_P(&position) != IS_STRING;
										if (_147$$148) {
											_147$$148 = Z_TYPE_P(&position) != IS_LONG;
										}
										if (_147$$148) {
											continue;
										}
										ZEPHIR_OBS_NVAR(&matchPosition);
										if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
											if (Z_TYPE_P(&converters) == IS_ARRAY) {
												ZEPHIR_OBS_NVAR(&converter);
												if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
													ZEPHIR_CALL_ZVAL_FUNCTION(&_148$$153, &converter, NULL, 0, &matchPosition);
													zephir_check_call_status();
													zephir_array_update_zval(&parts, &part, &_148$$153, PH_COPY | PH_SEPARATE);
													continue;
												}
											}
											zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
										} else {
											_149$$154 = Z_TYPE_P(&converters) == IS_ARRAY;
											if (_149$$154) {
												ZEPHIR_OBS_NVAR(&converter);
												_149$$154 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
											}
											if (_149$$154) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_150$$155, &converter, NULL, 0, &position);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_150$$155, PH_COPY | PH_SEPARATE);
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
				ZEPHIR_CALL_METHOD(NULL, &_94$$84, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&route);
		ZEPHIR_INIT_NVAR(&routeIdx);
	}
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
		zephir_read_property(&_151$$159, this_ptr, ZEND_STRL("notFoundPaths"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&notFoundPaths, &_151$$159);
		if (Z_TYPE_P(&notFoundPaths) != IS_NULL) {
			ZEPHIR_CALL_CE_STATIC(&parts, phalcon_mvc_router_route_ce, "getroutepaths", NULL, 0, &notFoundPaths);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&routeFound);
			ZVAL_BOOL(&routeFound, 1);
		}
	}
	zephir_read_property(&_152, this_ptr, ZEND_STRL("defaultNamespace"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("namespaceName"), &_152);
	zephir_read_property(&_153, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("module"), &_153);
	zephir_read_property(&_154, this_ptr, ZEND_STRL("defaultController"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("controller"), &_154);
	zephir_read_property(&_155, this_ptr, ZEND_STRL("defaultAction"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("action"), &_155);
	zephir_read_property(&_156, this_ptr, ZEND_STRL("defaultParams"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &_156);
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
				ZEPHIR_INIT_VAR(&_157$$167);
				ZVAL_STRING(&_157$$167, "/");
				ZEPHIR_INIT_VAR(&strParams);
				zephir_fast_trim(&strParams, &paramsStr, &_157$$167, ZEPHIR_TRIM_BOTH);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&strParams, "")) {
					ZEPHIR_INIT_NVAR(&params);
					zephir_fast_explode_str(&params, SL("/"), &strParams, LONG_MAX);
				}
			}
			zephir_array_unset_string(&parts, SL("params"), PH_SEPARATE);
		}
		if (zephir_fast_count_int(&params)) {
			ZEPHIR_INIT_VAR(&_158$$169);
			zephir_fast_array_merge(&_158$$169, &params, &parts);
			zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &_158$$169);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &parts);
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_159$$171);
		ZVAL_STRING(&_159$$171, "router:afterCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_159$$171, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property(&_160, this_ptr, ZEND_STRL("pendingCache"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_160) != IS_NULL) {
		zephir_read_property(&_161$$172, this_ptr, ZEND_STRL("pendingCache"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_162$$172, this_ptr, ZEND_STRL("pendingCacheKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_163$$172, this_ptr, "builddispatcherdump", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_161$$172, "set", NULL, 0, &_162$$172, &_163$$172);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("pendingCache"), &__$null);
		ZEPHIR_INIT_VAR(&_164$$172);
		ZEPHIR_INIT_NVAR(&_164$$172);
		ZVAL_STRING(&_164$$172, "");
		zephir_update_property_zval(this_ptr, ZEND_STRL("pendingCacheKey"), &_164$$172);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, routes, routeData, defaults, notFoundPaths, removeExtra, groups, groupData, _0$$4, _1$$3, _2$$5, _3$$6, *_4$$9, _6$$9, *_7$$13, _9$$13;
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
	ZVAL_UNDEF(&_9$$13);
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
			ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 193);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/Router.zep", 1964);
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
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 193);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Router.zep", 1970);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_array_isset_value_string(config, SL("removeExtraSlashes"))) {
		zephir_memory_observe(&removeExtra);
		zephir_array_fetch_string(&removeExtra, config, SL("removeExtraSlashes"), PH_NOISY, "phalcon/Mvc/Router.zep", 1974);
		ZVAL_BOOL(&_3$$6, zephir_get_boolval(&removeExtra));
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "removeextraslashes", NULL, 0, &_3$$6);
		zephir_check_call_status();
	}
	if (zephir_array_isset_value_string(config, SL("defaults"))) {
		zephir_memory_observe(&defaults);
		zephir_array_fetch_string(&defaults, config, SL("defaults"), PH_NOISY, "phalcon/Mvc/Router.zep", 1979);
		if (Z_TYPE_P(&defaults) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_configkeymustbearray_ce, "defaults", "phalcon/Mvc/Router.zep", 1981);
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaults", NULL, 0, &defaults);
		zephir_check_call_status();
	}
	zephir_memory_observe(&routes);
	if (zephir_array_isset_string_fetch(&routes, config, SL("routes"), 0)) {
		if (Z_TYPE_P(&routes) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_configkeymustbearray_ce, "routes", "phalcon/Mvc/Router.zep", 1988);
			return;
		}
		zephir_is_iterable(&routes, 0, "phalcon/Mvc/Router.zep", 1993);
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
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$9, &routes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&routeData, &routes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "addroutefromconfig", &_5, 0, &routeData);
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_configkeymustbearray_ce, "groups", "phalcon/Mvc/Router.zep", 1997);
			return;
		}
		zephir_is_iterable(&groups, 0, "phalcon/Mvc/Router.zep", 2002);
		if (Z_TYPE_P(&groups) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groups), _7$$13)
			{
				ZEPHIR_INIT_NVAR(&groupData);
				ZVAL_COPY(&groupData, _7$$13);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "mountgroupfromconfig", &_8, 0, &groupData);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &groups, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_9$$13, &groups, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$13)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&groupData, &groups, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "mountgroupfromconfig", &_8, 0, &groupData);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missingrouteconfigkey_ce, "pattern", "phalcon/Mvc/Router.zep", 2023);
		return;
	}
	zephir_memory_observe(&paths);
	if (!(zephir_array_isset_string_fetch(&paths, &routeData, SL("paths"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missingrouteconfigkey_ce, "paths", "phalcon/Mvc/Router.zep", 2027);
		return;
	}
	ZEPHIR_INIT_VAR(&method);
	ZVAL_STRING(&method, "");
	_0 = zephir_array_isset_value_string(&routeData, SL("method"));
	if (_0) {
		zephir_array_fetch_string(&_1, &routeData, SL("method"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2031);
		_0 = Z_TYPE_P(&_1) != IS_NULL;
	}
	if (_0) {
		zephir_memory_observe(&_2$$5);
		zephir_array_fetch_string(&_2$$5, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2032);
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
		object_init_ex(&_5$$7, phalcon_mvc_router_exceptions_unknownhttpmethod_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", NULL, 194, &method);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$7, "phalcon/Mvc/Router.zep", 2051);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	if (zephir_array_isset_value_string(&routeData, SL("name"))) {
		zephir_memory_observe(&_6$$8);
		zephir_array_fetch_string(&_6$$8, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 2055);
		zephir_cast_to_string(&_7$$8, &_6$$8);
		ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &_7$$8);
		zephir_check_call_status();
	}
	if (zephir_array_isset_value_string(&routeData, SL("hostname"))) {
		zephir_memory_observe(&_8$$9);
		zephir_array_fetch_string(&_8$$9, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 2058);
		zephir_cast_to_string(&_9$$9, &_8$$9);
		ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &_9$$9);
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
	zval _1$$4, _3$$5, _9$$11, _14$$14, _19$$18, _23$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *groupData_param = NULL, group, paths, routes, routeData, method, methodClass, pattern, routePaths, route, *_5, _15, _0$$4, _2$$5, _4$$7, _7$$8, _8$$11, _10$$12, _11$$13, _13$$14, _17$$15, _18$$18, _20$$19, _21$$20, _22$$21;
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
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$20);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_23$$21);
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
		zephir_array_fetch_string(&paths, &groupData, SL("paths"), PH_NOISY, "phalcon/Mvc/Router.zep", 2075);
	}
	ZEPHIR_INIT_VAR(&group);
	object_init_ex(&group, phalcon_mvc_router_group_ce);
	ZEPHIR_CALL_METHOD(NULL, &group, "__construct", NULL, 195, &paths);
	zephir_check_call_status();
	if (zephir_array_isset_value_string(&groupData, SL("prefix"))) {
		zephir_memory_observe(&_0$$4);
		zephir_array_fetch_string(&_0$$4, &groupData, SL("prefix"), PH_NOISY, "phalcon/Mvc/Router.zep", 2081);
		zephir_cast_to_string(&_1$$4, &_0$$4);
		ZEPHIR_CALL_METHOD(NULL, &group, "setprefix", NULL, 196, &_1$$4);
		zephir_check_call_status();
	}
	if (zephir_array_isset_value_string(&groupData, SL("hostname"))) {
		zephir_memory_observe(&_2$$5);
		zephir_array_fetch_string(&_2$$5, &groupData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 2085);
		zephir_cast_to_string(&_3$$5, &_2$$5);
		ZEPHIR_CALL_METHOD(NULL, &group, "sethostname", NULL, 197, &_3$$5);
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
		ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", NULL, 198);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$7, "phalcon/Mvc/Router.zep", 2093);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_is_iterable(&routes, 0, "phalcon/Mvc/Router.zep", 2133);
	if (Z_TYPE_P(&routes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&routes), _5)
		{
			ZEPHIR_INIT_NVAR(&routeData);
			ZVAL_COPY(&routeData, _5);
			ZEPHIR_OBS_NVAR(&pattern);
			if (!(zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "pattern", "phalcon/Mvc/Router.zep", 2098);
				return;
			}
			ZEPHIR_OBS_NVAR(&routePaths);
			if (!(zephir_array_isset_string_fetch(&routePaths, &routeData, SL("paths"), 0))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "paths", "phalcon/Mvc/Router.zep", 2101);
				return;
			}
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_STRING(&method, "");
			_6$$8 = zephir_array_isset_value_string(&routeData, SL("method"));
			if (_6$$8) {
				zephir_array_fetch_string(&_7$$8, &routeData, SL("method"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2105);
				_6$$8 = Z_TYPE_P(&_7$$8) != IS_NULL;
			}
			if (_6$$8) {
				ZEPHIR_OBS_NVAR(&_8$$11);
				zephir_array_fetch_string(&_8$$11, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2106);
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
				object_init_ex(&_11$$13, phalcon_mvc_router_exceptions_unknownhttpmethod_ce);
				ZEPHIR_CALL_METHOD(NULL, &_11$$13, "__construct", &_12, 194, &method);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$13, "phalcon/Mvc/Router.zep", 2125);
				ZEPHIR_MM_RESTORE();
				return;
			} while(0);

			if (zephir_array_isset_value_string(&routeData, SL("name"))) {
				ZEPHIR_OBS_NVAR(&_13$$14);
				zephir_array_fetch_string(&_13$$14, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 2129);
				zephir_cast_to_string(&_14$$14, &_13$$14);
				ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &_14$$14);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &routes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_15, &routes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&routeData, &routes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&pattern);
				if (!(zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "pattern", "phalcon/Mvc/Router.zep", 2098);
					return;
				}
				ZEPHIR_OBS_NVAR(&routePaths);
				if (!(zephir_array_isset_string_fetch(&routePaths, &routeData, SL("paths"), 0))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "paths", "phalcon/Mvc/Router.zep", 2101);
					return;
				}
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_STRING(&method, "");
				_16$$15 = zephir_array_isset_value_string(&routeData, SL("method"));
				if (_16$$15) {
					zephir_array_fetch_string(&_17$$15, &routeData, SL("method"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2105);
					_16$$15 = Z_TYPE_P(&_17$$15) != IS_NULL;
				}
				if (_16$$15) {
					ZEPHIR_OBS_NVAR(&_18$$18);
					zephir_array_fetch_string(&_18$$18, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2106);
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
					object_init_ex(&_21$$20, phalcon_mvc_router_exceptions_unknownhttpmethod_ce);
					ZEPHIR_CALL_METHOD(NULL, &_21$$20, "__construct", &_12, 194, &method);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_21$$20, "phalcon/Mvc/Router.zep", 2125);
					ZEPHIR_MM_RESTORE();
					return;
				} while(0);

				if (zephir_array_isset_value_string(&routeData, SL("name"))) {
					ZEPHIR_OBS_NVAR(&_22$$21);
					zephir_array_fetch_string(&_22$$21, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 2129);
					zephir_cast_to_string(&_23$$21, &_22$$21);
					ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &_23$$21);
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
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Router, mount)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group, group_sub, groupRoutes, beforeMatch, hostname, route, eventsManager, _0, *_7, _9, _1$$3, _2$$4, *_3$$5, _4$$5, *_5$$8, _6$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&groupRoutes);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&hostname);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$8);
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
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_router_exceptions_emptygroupofroutes_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 199);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Router.zep", 2156);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&beforeMatch, group, "getbeforematch", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
		zephir_is_iterable(&groupRoutes, 0, "phalcon/Mvc/Router.zep", 2168);
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
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$5, &groupRoutes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$5)) {
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
		zephir_is_iterable(&groupRoutes, 0, "phalcon/Mvc/Router.zep", 2177);
		if (Z_TYPE_P(&groupRoutes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groupRoutes), _5$$8)
			{
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _5$$8);
				ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &hostname);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$8, &groupRoutes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$8)) {
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
	zephir_is_iterable(&groupRoutes, 0, "phalcon/Mvc/Router.zep", 2183);
	if (Z_TYPE_P(&groupRoutes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groupRoutes), _7)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _7);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", &_8, 0, &route);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_9, &groupRoutes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
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
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 200);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Router.zep", 2197);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("notFoundPaths"), paths);
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
 * @return static
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
 * @return static
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
 * @return static
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
 * @return static
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
 * @return static
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
 * @return static
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
 * @return static
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

