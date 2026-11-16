
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
#include "kernel/string.h"
#include "Zend/zend_closures.h"
#include "kernel/concat.h"
#include "kernel/variables.h"
#include "kernel/require.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
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
 *
 * @phpstan-import-type mvc_router_defaults from MvcTypes
 * @phpstan-import-type mvc_router_http_methods from MvcTypes
 * @phpstan-import-type mvc_router_config_group from MvcTypes
 * @phpstan-import-type mvc_router_config_route from MvcTypes
 * @phpstan-import-type mvc_router_dump from MvcTypes
 * @phpstan-import-type mvc_router_dumped_route from MvcTypes
 * @phpstan-import-type mvc_router_hostname_buckets from MvcTypes
 * @phpstan-import-type mvc_router_index_buckets from MvcTypes
 * @phpstan-import-type mvc_router_matches from MvcTypes
 * @phpstan-import-type mvc_router_method_buckets from MvcTypes
 * @phpstan-import-type mvc_router_params from MvcTypes
 * @phpstan-import-type mvc_router_paths from MvcTypes
 * @phpstan-import-type mvc_router_regex_chunks from MvcTypes
 * @phpstan-import-type mvc_router_regex_disabled from MvcTypes
 * @phpstan-import-type mvc_router_regex_mark_map from MvcTypes
 * @phpstan-import-type mvc_router_route_meta from MvcTypes
 * @phpstan-import-type mvc_router_shadow_buckets from MvcTypes
 * @phpstan-import-type mvc_router_static_buckets from MvcTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Router, phalcon, mvc_router, phalcon_di_abstractinjectionaware_ce, phalcon_mvc_router_method_entry, 0);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("action"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * Pre-merged per-method candidate buckets in attach order. For each HTTP
	 * method seen on any registered route, the bucket contains the
	 * method-specific routes followed by the "*" (no-constraint) routes.
	 * The "*" key itself holds only the no-constraint routes - used when the
	 * request method has no specific bucket.
	 *
	 * Built in rebuildMethodIndex(); consumed by handle() in reverse.
	 *
	 * @phpstan-var mvc_router_method_buckets
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("candidatesByMethod"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Combined PCRE pattern per method bucket (chunked list of strings).
	 * Each chunk uses (?|...) branch reset and (*:N) mark labels. Built
	 * only when the bucket has no hostname routes and all patterns are
	 * the standard `#^...$#u` shape.
	 *
	 * @phpstan-var mvc_router_regex_chunks
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("combinedRegexByMethod"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Boolean per method bucket: true when the combined regex cannot be
	 * built (hostname route present, exotic pattern shape, etc.).
	 *
	 * @phpstan-var mvc_router_regex_disabled
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("combinedRegexDisabled"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Map from MARK label back to the route index in
	 * candidatesByMethod[method]. One per chunk.
	 *
	 *   combinedRegexMarkMap[method][chunkIdx][markLabel] = routeIdx
	 *
	 * @phpstan-var mvc_router_regex_mark_map
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("combinedRegexMarkMap"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("controller"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("defaultAction"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("defaultController"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("defaultModule"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("defaultNamespace"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * @phpstan-var mvc_router_params
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("defaultParams"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("eventsManager"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Events\\ManagerInterface"));
	}

	/**
	 * Per-method buckets of routes with hostname constraints, grouped by
	 * raw hostname string. Routes are referenced by their index into
	 * candidatesByMethod[method]. Built in rebuildMethodIndex().
	 *
	 * Shape: hostnameByMethod[method][hostname] = list of route indices.
	 *
	 * @phpstan-var mvc_router_hostname_buckets
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("hostnameByMethod"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Per-method indices of routes without a hostname constraint, in
	 * attach order.
	 *
	 * Shape: hostnameLessByMethod[method] = list of route indices into
	 * candidatesByMethod[method].
	 * @phpstan-var mvc_router_index_buckets
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("hostnameLessByMethod"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var array<array-key, int|string>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("keyRouteIds"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var array<string, int|string>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("keyRouteNames"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("matchedRoute"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Mvc\\Router\\RouteInterface"));
	}

	/**
	 * @phpstan-var mvc_router_matches
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("matches"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var mvc_router_method_buckets
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("methodRoutes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("methodRoutesDirty"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("module"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("namespaceName"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * @var array|string|null
	 *
	 * @phpstan-var mvc_router_paths|string|null
	 */
	zend_declare_property_null(phalcon_mvc_router_ce, SL("notFoundPaths"), ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var mvc_router_params
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("params"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Lazy-write cache target set by useCache(). When non-null, handle()
	 * writes buildDispatcherDump() to this cache after a successful
	 * rebuild on cache miss, then clears the property to skip subsequent
	 * writes.
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("pendingCache"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Cache\\Adapter\\AdapterInterface"));
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("pendingCacheKey"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("removeExtraSlashes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

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
	 * @phpstan-var array<string, mvc_router_route_meta>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("routeMeta"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var list<RouteInterface>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("routes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Static-route hash, populated by rebuildMethodIndex(). For each method
	 * bucket (including "*"), maps URI => list of routes whose compiled
	 * pattern is a literal string equal to that URI.
	 *
	 * @phpstan-var mvc_router_static_buckets
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("staticByMethod"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Shadow-detection map. If staticShadowedByMethod[method][uri] is set,
	 * the static URI in that bucket is shadowed by a later-attached regex
	 * route - the fast path MUST NOT be used; fall through to the dynamic
	 * loop so the regex wins (reverse-iteration semantics).
	 *
	 * @phpstan-var mvc_router_shadow_buckets
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("staticShadowedByMethod"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_router_ce, SL("uriSource"), 0, ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_router_ce, SL("wasMatched"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[0], &_2$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "attach", &_zephir_call_cache[1], &_0$$3);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[2], &_4$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "attach", &_zephir_call_cache[3], &_2$$3);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "__construct", &_zephir_call_cache[0], &pattern_zv, paths, httpMethods);
	zephir_check_call_status();
	ZVAL_LONG(&_0, position);
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "attach", &_zephir_call_cache[1], &route, &_0);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "add", &_zephir_call_cache[0], &pattern_zv, paths, &_0, &_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "add", &_zephir_call_cache[0], &pattern_zv, paths, &_0, &_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "add", &_zephir_call_cache[0], &pattern_zv, paths, &_0, &_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "add", &_zephir_call_cache[0], &pattern_zv, paths, &_0, &_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "add", &_zephir_call_cache[0], &pattern_zv, paths, &_0, &_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "add", &_zephir_call_cache[0], &pattern_zv, paths, &_0, &_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "add", &_zephir_call_cache[0], &pattern_zv, paths, &_0, &_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "add", &_zephir_call_cache[0], &pattern_zv, paths, &_0, &_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "add", &_zephir_call_cache[0], &pattern_zv, paths, &_0, &_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "add", &_zephir_call_cache[0], &pattern_zv, paths, &_0, &_1);
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
 *
 * @phpstan-return static
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("methodRoutesDirty", 17, 1);
	}

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
	if (position == 1) { goto zephir_switch_0_clause_0; }
	if (position == 0) { goto zephir_switch_0_clause_1; }
	goto zephir_switch_0_clause_2;
	zephir_switch_0_clause_0: ;
		zephir_update_property_array_append(this_ptr, SL("routes"), route);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_1: ;
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 1, 0);
		zephir_array_fast_append(&_1$$4, route);
		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_fast_array_merge(&_0$$4, &_1$$4, &_2$$4);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 289, &_0$$4);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_2: ;
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_router_exceptions_invalidrouteposition_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$5, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Router.zep", 649);
		ZEPHIR_MM_RESTORE();
		return;
	zephir_switch_0_end: ;

	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 290, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 290, &__$false);
	}
	RETURN_THIS();
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
 *
 * @phpstan-return mvc_router_dump
 */
PHP_METHOD(Phalcon_Mvc_Router, buildDispatcherDump)
{
	zval _26$$4, _49$$11;
	zend_bool _30, _68, _94, _137, _9$$4, _22$$6, _32$$11, _45$$13, _64$$18, _75$$21, _90$$24, _101$$27, _126$$30, _122$$31, _133$$34, _154$$37, _150$$38, _161$$41;
	zend_string *_6, *_57, *_83, *_109, *_17$$6, *_40$$13, *_115$$30, *_143$$37;
	zend_ulong _5, _56, _82, _108, _16$$6, _39$$13, _114$$30, _142$$37;
	zval route, cb, converters, convName, converter, dumpedRoutes, routeToIdx, scalarIdx, scalarSubKey, scalarVal, methodRoutesScalar, candidatesScalar, staticScalar, innerKey, innerVal, mostInnerVal, mostInnerArr, _0, _1, *_2, _3, *_4, _29, _52, *_53, _54, *_55, _67, _78, *_79, _80, *_81, _93, _104, *_105, _106, *_107, _136, _164, _7$$4, _27$$4, _28$$4, _10$$5, _11$$5, _12$$5, *_13$$6, _14$$6, *_15$$6, _21$$6, _18$$8, _19$$8, _20$$8, _23$$10, _24$$10, _25$$10, _31$$11, _50$$11, _51$$11, _33$$12, _34$$12, _35$$12, *_36$$13, _37$$13, *_38$$13, _44$$13, _41$$15, _42$$15, _43$$15, _46$$17, _47$$17, _48$$17, *_58$$18, _59$$18, *_60$$18, _63$$18, _61$$19, _62$$19, _65$$20, _66$$20, *_69$$21, _70$$21, *_71$$21, _74$$21, _72$$22, _73$$22, _76$$23, _77$$23, *_84$$24, _85$$24, *_86$$24, _89$$24, _87$$25, _88$$25, _91$$26, _92$$26, *_95$$27, _96$$27, *_97$$27, _100$$27, _98$$28, _99$$28, _102$$29, _103$$29, _110$$30, *_111$$30, _112$$30, *_113$$30, _125$$30, *_116$$31, _117$$31, *_118$$31, _121$$31, _119$$32, _120$$32, _123$$33, _124$$33, *_127$$34, _128$$34, *_129$$34, _132$$34, _130$$35, _131$$35, _134$$36, _135$$36, _138$$37, *_139$$37, _140$$37, *_141$$37, _153$$37, *_144$$38, _145$$38, *_146$$38, _149$$38, _147$$39, _148$$39, _151$$40, _152$$40, *_155$$41, _156$$41, *_157$$41, _160$$41, _158$$42, _159$$42, _162$$43, _163$$43;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&_54);
	ZVAL_UNDEF(&_67);
	ZVAL_UNDEF(&_78);
	ZVAL_UNDEF(&_80);
	ZVAL_UNDEF(&_93);
	ZVAL_UNDEF(&_104);
	ZVAL_UNDEF(&_106);
	ZVAL_UNDEF(&_136);
	ZVAL_UNDEF(&_164);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_27$$4);
	ZVAL_UNDEF(&_28$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_31$$11);
	ZVAL_UNDEF(&_50$$11);
	ZVAL_UNDEF(&_51$$11);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_34$$12);
	ZVAL_UNDEF(&_35$$12);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_44$$13);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_42$$15);
	ZVAL_UNDEF(&_43$$15);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_48$$17);
	ZVAL_UNDEF(&_59$$18);
	ZVAL_UNDEF(&_63$$18);
	ZVAL_UNDEF(&_61$$19);
	ZVAL_UNDEF(&_62$$19);
	ZVAL_UNDEF(&_65$$20);
	ZVAL_UNDEF(&_66$$20);
	ZVAL_UNDEF(&_70$$21);
	ZVAL_UNDEF(&_74$$21);
	ZVAL_UNDEF(&_72$$22);
	ZVAL_UNDEF(&_73$$22);
	ZVAL_UNDEF(&_76$$23);
	ZVAL_UNDEF(&_77$$23);
	ZVAL_UNDEF(&_85$$24);
	ZVAL_UNDEF(&_89$$24);
	ZVAL_UNDEF(&_87$$25);
	ZVAL_UNDEF(&_88$$25);
	ZVAL_UNDEF(&_91$$26);
	ZVAL_UNDEF(&_92$$26);
	ZVAL_UNDEF(&_96$$27);
	ZVAL_UNDEF(&_100$$27);
	ZVAL_UNDEF(&_98$$28);
	ZVAL_UNDEF(&_99$$28);
	ZVAL_UNDEF(&_102$$29);
	ZVAL_UNDEF(&_103$$29);
	ZVAL_UNDEF(&_110$$30);
	ZVAL_UNDEF(&_112$$30);
	ZVAL_UNDEF(&_125$$30);
	ZVAL_UNDEF(&_117$$31);
	ZVAL_UNDEF(&_121$$31);
	ZVAL_UNDEF(&_119$$32);
	ZVAL_UNDEF(&_120$$32);
	ZVAL_UNDEF(&_123$$33);
	ZVAL_UNDEF(&_124$$33);
	ZVAL_UNDEF(&_128$$34);
	ZVAL_UNDEF(&_132$$34);
	ZVAL_UNDEF(&_130$$35);
	ZVAL_UNDEF(&_131$$35);
	ZVAL_UNDEF(&_134$$36);
	ZVAL_UNDEF(&_135$$36);
	ZVAL_UNDEF(&_138$$37);
	ZVAL_UNDEF(&_140$$37);
	ZVAL_UNDEF(&_153$$37);
	ZVAL_UNDEF(&_145$$38);
	ZVAL_UNDEF(&_149$$38);
	ZVAL_UNDEF(&_147$$39);
	ZVAL_UNDEF(&_148$$39);
	ZVAL_UNDEF(&_151$$40);
	ZVAL_UNDEF(&_152$$40);
	ZVAL_UNDEF(&_156$$41);
	ZVAL_UNDEF(&_160$$41);
	ZVAL_UNDEF(&_158$$42);
	ZVAL_UNDEF(&_159$$42);
	ZVAL_UNDEF(&_162$$43);
	ZVAL_UNDEF(&_163$$43);
	ZVAL_UNDEF(&_26$$4);
	ZVAL_UNDEF(&_49$$11);
	ZEND_TLS zephir_method_cache _zephir_call_cache[101];
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 290, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "rebuildMethodIndex", &_zephir_call_cache[0]);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&dumpedRoutes);
	array_init(&dumpedRoutes);
	ZEPHIR_INIT_VAR(&routeToIdx);
	array_init(&routeToIdx);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 289, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_1) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, &_1);
		_2 = &_3;
	} else {
		_2 = &_1;
	}
	zephir_is_iterable(_2, 0, "phalcon/Mvc/Router.zep", 721);
	if (Z_TYPE_P(_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_2), _5, _6, _4)
		{
			ZEPHIR_INIT_NVAR(&scalarIdx);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&scalarIdx, _6);
			} else {
				ZVAL_LONG(&scalarIdx, _5);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _4);
			ZEPHIR_CALL_FUNCTION(&_7$$4, "spl_object_id", &_8, 30, &route);
			zephir_check_call_status();
			zephir_array_update_zval(&routeToIdx, &_7$$4, &scalarIdx, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&cb, &route, "getBeforeMatch", &_zephir_call_cache[1]);
			zephir_check_call_status();
			_9$$4 = Z_TYPE_P(&cb) != IS_NULL;
			if (_9$$4) {
				_9$$4 = zephir_is_instance_of(&cb, SL("Closure"));
			}
			if (_9$$4) {
				ZEPHIR_INIT_NVAR(&_10$$5);
				object_init_ex(&_10$$5, phalcon_mvc_router_exception_ce);
				ZEPHIR_CALL_METHOD_CACHED(&_11$$5, &route, "getRouteId", &_zephir_call_cache[2]);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZEPHIR_CONCAT_SVS(&_12$$5, "Cannot cache router: route id '", &_11$$5, "' has a Closure beforeMatch - only string/array callables are cacheable");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_10$$5, "__construct", &_zephir_call_cache[3], &_12$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_10$$5, "phalcon/Mvc/Router.zep", 692);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&converters, &route, "getConverters", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (Z_TYPE_P(&converters) == IS_ARRAY) {
				if (Z_TYPE_P(&converters) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_14$$6);
					zephir_string_to_char_array(&_14$$6, &converters);
					_13$$6 = &_14$$6;
				} else {
					_13$$6 = &converters;
				}
				zephir_is_iterable(_13$$6, 0, "phalcon/Mvc/Router.zep", 706);
				if (Z_TYPE_P(_13$$6) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_13$$6), _16$$6, _17$$6, _15$$6)
					{
						ZEPHIR_INIT_NVAR(&convName);
						if (_17$$6 != NULL) { 
							ZVAL_STR_COPY(&convName, _17$$6);
						} else {
							ZVAL_LONG(&convName, _16$$6);
						}
						ZEPHIR_INIT_NVAR(&converter);
						ZVAL_COPY(&converter, _15$$6);
						if (zephir_is_instance_of(&converter, SL("Closure"))) {
							ZEPHIR_INIT_NVAR(&_18$$8);
							object_init_ex(&_18$$8, phalcon_mvc_router_exception_ce);
							ZEPHIR_CALL_METHOD_CACHED(&_19$$8, &route, "getRouteId", &_zephir_call_cache[5]);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_20$$8);
							ZEPHIR_CONCAT_SVSVS(&_20$$8, "Cannot cache router: route id '", &_19$$8, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_18$$8, "__construct", &_zephir_call_cache[6], &_20$$8);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_18$$8, "phalcon/Mvc/Router.zep", 703);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _13$$6, "rewind", &_zephir_call_cache[7]);
					zephir_check_call_status();
					_22$$6 = 1;
					while (1) {
						if (_22$$6) {
							_22$$6 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _13$$6, "next", &_zephir_call_cache[8]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_21$$6, _13$$6, "valid", &_zephir_call_cache[9]);
						zephir_check_call_status();
						if (!zend_is_true(&_21$$6)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&convName, _13$$6, "key", &_zephir_call_cache[10]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&converter, _13$$6, "current", &_zephir_call_cache[11]);
						zephir_check_call_status();
							if (zephir_is_instance_of(&converter, SL("Closure"))) {
								ZEPHIR_INIT_NVAR(&_23$$10);
								object_init_ex(&_23$$10, phalcon_mvc_router_exception_ce);
								ZEPHIR_CALL_METHOD_CACHED(&_24$$10, &route, "getRouteId", &_zephir_call_cache[12]);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_25$$10);
								ZEPHIR_CONCAT_SVSVS(&_25$$10, "Cannot cache router: route id '", &_24$$10, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_23$$10, "__construct", &_zephir_call_cache[13], &_25$$10);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_23$$10, "phalcon/Mvc/Router.zep", 703);
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&converter);
				ZEPHIR_INIT_NVAR(&convName);
			}
			ZEPHIR_INIT_NVAR(&_26$$4);
			zephir_create_array(&_26$$4, 9, 0);
			ZEPHIR_INIT_NVAR(&_27$$4);
			zephir_get_class(&_27$$4, &route, 0);
			zephir_array_update_string(&_26$$4, SL("class"), &_27$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD_CACHED(&_28$$4, &route, "getPattern", &_zephir_call_cache[14]);
			zephir_check_call_status();
			zephir_array_update_string(&_26$$4, SL("pattern"), &_28$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD_CACHED(&_28$$4, &route, "getPaths", &_zephir_call_cache[15]);
			zephir_check_call_status();
			zephir_array_update_string(&_26$$4, SL("paths"), &_28$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD_CACHED(&_28$$4, &route, "getHttpMethods", &_zephir_call_cache[16]);
			zephir_check_call_status();
			zephir_array_update_string(&_26$$4, SL("methods"), &_28$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD_CACHED(&_28$$4, &route, "getHostname", &_zephir_call_cache[17]);
			zephir_check_call_status();
			zephir_array_update_string(&_26$$4, SL("hostname"), &_28$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD_CACHED(&_28$$4, &route, "getName", &_zephir_call_cache[18]);
			zephir_check_call_status();
			zephir_array_update_string(&_26$$4, SL("name"), &_28$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD_CACHED(&_28$$4, &route, "getRouteId", &_zephir_call_cache[19]);
			zephir_check_call_status();
			zephir_array_update_string(&_26$$4, SL("id"), &_28$$4, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_26$$4, SL("beforeMatch"), &cb, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_26$$4, SL("converters"), &converters, PH_COPY | PH_SEPARATE);
			zephir_array_append(&dumpedRoutes, &_26$$4, PH_SEPARATE, "phalcon/Mvc/Router.zep", 718);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _2, "rewind", &_zephir_call_cache[20]);
		zephir_check_call_status();
		_30 = 1;
		while (1) {
			if (_30) {
				_30 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _2, "next", &_zephir_call_cache[21]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_29, _2, "valid", &_zephir_call_cache[22]);
			zephir_check_call_status();
			if (!zend_is_true(&_29)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&scalarIdx, _2, "key", &_zephir_call_cache[23]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&route, _2, "current", &_zephir_call_cache[24]);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_31$$11, "spl_object_id", &_8, 30, &route);
				zephir_check_call_status();
				zephir_array_update_zval(&routeToIdx, &_31$$11, &scalarIdx, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&cb, &route, "getBeforeMatch", &_zephir_call_cache[25]);
				zephir_check_call_status();
				_32$$11 = Z_TYPE_P(&cb) != IS_NULL;
				if (_32$$11) {
					_32$$11 = zephir_is_instance_of(&cb, SL("Closure"));
				}
				if (_32$$11) {
					ZEPHIR_INIT_NVAR(&_33$$12);
					object_init_ex(&_33$$12, phalcon_mvc_router_exception_ce);
					ZEPHIR_CALL_METHOD_CACHED(&_34$$12, &route, "getRouteId", &_zephir_call_cache[26]);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_35$$12);
					ZEPHIR_CONCAT_SVS(&_35$$12, "Cannot cache router: route id '", &_34$$12, "' has a Closure beforeMatch - only string/array callables are cacheable");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_33$$12, "__construct", &_zephir_call_cache[27], &_35$$12);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_33$$12, "phalcon/Mvc/Router.zep", 692);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&converters, &route, "getConverters", &_zephir_call_cache[28]);
				zephir_check_call_status();
				if (Z_TYPE_P(&converters) == IS_ARRAY) {
					if (Z_TYPE_P(&converters) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_37$$13);
						zephir_string_to_char_array(&_37$$13, &converters);
						_36$$13 = &_37$$13;
					} else {
						_36$$13 = &converters;
					}
					zephir_is_iterable(_36$$13, 0, "phalcon/Mvc/Router.zep", 706);
					if (Z_TYPE_P(_36$$13) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_36$$13), _39$$13, _40$$13, _38$$13)
						{
							ZEPHIR_INIT_NVAR(&convName);
							if (_40$$13 != NULL) { 
								ZVAL_STR_COPY(&convName, _40$$13);
							} else {
								ZVAL_LONG(&convName, _39$$13);
							}
							ZEPHIR_INIT_NVAR(&converter);
							ZVAL_COPY(&converter, _38$$13);
							if (zephir_is_instance_of(&converter, SL("Closure"))) {
								ZEPHIR_INIT_NVAR(&_41$$15);
								object_init_ex(&_41$$15, phalcon_mvc_router_exception_ce);
								ZEPHIR_CALL_METHOD_CACHED(&_42$$15, &route, "getRouteId", &_zephir_call_cache[29]);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_43$$15);
								ZEPHIR_CONCAT_SVSVS(&_43$$15, "Cannot cache router: route id '", &_42$$15, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_41$$15, "__construct", &_zephir_call_cache[30], &_43$$15);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_41$$15, "phalcon/Mvc/Router.zep", 703);
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _36$$13, "rewind", &_zephir_call_cache[31]);
						zephir_check_call_status();
						_45$$13 = 1;
						while (1) {
							if (_45$$13) {
								_45$$13 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _36$$13, "next", &_zephir_call_cache[32]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_44$$13, _36$$13, "valid", &_zephir_call_cache[33]);
							zephir_check_call_status();
							if (!zend_is_true(&_44$$13)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&convName, _36$$13, "key", &_zephir_call_cache[34]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&converter, _36$$13, "current", &_zephir_call_cache[35]);
							zephir_check_call_status();
								if (zephir_is_instance_of(&converter, SL("Closure"))) {
									ZEPHIR_INIT_NVAR(&_46$$17);
									object_init_ex(&_46$$17, phalcon_mvc_router_exception_ce);
									ZEPHIR_CALL_METHOD_CACHED(&_47$$17, &route, "getRouteId", &_zephir_call_cache[36]);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_48$$17);
									ZEPHIR_CONCAT_SVSVS(&_48$$17, "Cannot cache router: route id '", &_47$$17, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, &_46$$17, "__construct", &_zephir_call_cache[37], &_48$$17);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_46$$17, "phalcon/Mvc/Router.zep", 703);
									ZEPHIR_MM_RESTORE();
									return;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&converter);
					ZEPHIR_INIT_NVAR(&convName);
				}
				ZEPHIR_INIT_NVAR(&_49$$11);
				zephir_create_array(&_49$$11, 9, 0);
				ZEPHIR_INIT_NVAR(&_50$$11);
				zephir_get_class(&_50$$11, &route, 0);
				zephir_array_update_string(&_49$$11, SL("class"), &_50$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_51$$11, &route, "getPattern", &_zephir_call_cache[38]);
				zephir_check_call_status();
				zephir_array_update_string(&_49$$11, SL("pattern"), &_51$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_51$$11, &route, "getPaths", &_zephir_call_cache[39]);
				zephir_check_call_status();
				zephir_array_update_string(&_49$$11, SL("paths"), &_51$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_51$$11, &route, "getHttpMethods", &_zephir_call_cache[40]);
				zephir_check_call_status();
				zephir_array_update_string(&_49$$11, SL("methods"), &_51$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_51$$11, &route, "getHostname", &_zephir_call_cache[41]);
				zephir_check_call_status();
				zephir_array_update_string(&_49$$11, SL("hostname"), &_51$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_51$$11, &route, "getName", &_zephir_call_cache[42]);
				zephir_check_call_status();
				zephir_array_update_string(&_49$$11, SL("name"), &_51$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_51$$11, &route, "getRouteId", &_zephir_call_cache[43]);
				zephir_check_call_status();
				zephir_array_update_string(&_49$$11, SL("id"), &_51$$11, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_49$$11, SL("beforeMatch"), &cb, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_49$$11, SL("converters"), &converters, PH_COPY | PH_SEPARATE);
				zephir_array_append(&dumpedRoutes, &_49$$11, PH_SEPARATE, "phalcon/Mvc/Router.zep", 718);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&scalarIdx);
	ZEPHIR_INIT_VAR(&methodRoutesScalar);
	array_init(&methodRoutesScalar);
	zephir_read_property_cached(&_52, this_ptr, _zephir_prop_2, 291, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_52) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_54);
		zephir_string_to_char_array(&_54, &_52);
		_53 = &_54;
	} else {
		_53 = &_52;
	}
	zephir_is_iterable(_53, 0, "phalcon/Mvc/Router.zep", 730);
	if (Z_TYPE_P(_53) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_53), _56, _57, _55)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_57 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _57);
			} else {
				ZVAL_LONG(&innerKey, _56);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _55);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_59$$18);
				zephir_string_to_char_array(&_59$$18, &innerVal);
				_58$$18 = &_59$$18;
			} else {
				_58$$18 = &innerVal;
			}
			zephir_is_iterable(_58$$18, 0, "phalcon/Mvc/Router.zep", 727);
			if (Z_TYPE_P(_58$$18) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_58$$18), _60$$18)
				{
					ZEPHIR_INIT_NVAR(&scalarVal);
					ZVAL_COPY(&scalarVal, _60$$18);
					ZEPHIR_CALL_FUNCTION(&_62$$19, "spl_object_id", &_8, 30, &scalarVal);
					zephir_check_call_status();
					zephir_array_fetch(&_61$$19, &routeToIdx, &_62$$19, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 725);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&mostInnerArr, &_61$$19, PH_SEPARATE, "phalcon/Mvc/Router.zep", 725);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _58$$18, "rewind", &_zephir_call_cache[44]);
				zephir_check_call_status();
				_64$$18 = 1;
				while (1) {
					if (_64$$18) {
						_64$$18 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _58$$18, "next", &_zephir_call_cache[45]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_63$$18, _58$$18, "valid", &_zephir_call_cache[46]);
					zephir_check_call_status();
					if (!zend_is_true(&_63$$18)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&scalarVal, _58$$18, "current", &_zephir_call_cache[47]);
					zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_66$$20, "spl_object_id", &_8, 30, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_65$$20, &routeToIdx, &_66$$20, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 725);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_65$$20, PH_SEPARATE, "phalcon/Mvc/Router.zep", 725);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&scalarVal);
			zephir_array_update_zval(&methodRoutesScalar, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _53, "rewind", &_zephir_call_cache[48]);
		zephir_check_call_status();
		_68 = 1;
		while (1) {
			if (_68) {
				_68 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _53, "next", &_zephir_call_cache[49]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_67, _53, "valid", &_zephir_call_cache[50]);
			zephir_check_call_status();
			if (!zend_is_true(&_67)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&innerKey, _53, "key", &_zephir_call_cache[51]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&innerVal, _53, "current", &_zephir_call_cache[52]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_70$$21);
					zephir_string_to_char_array(&_70$$21, &innerVal);
					_69$$21 = &_70$$21;
				} else {
					_69$$21 = &innerVal;
				}
				zephir_is_iterable(_69$$21, 0, "phalcon/Mvc/Router.zep", 727);
				if (Z_TYPE_P(_69$$21) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_69$$21), _71$$21)
					{
						ZEPHIR_INIT_NVAR(&scalarVal);
						ZVAL_COPY(&scalarVal, _71$$21);
						ZEPHIR_CALL_FUNCTION(&_73$$22, "spl_object_id", &_8, 30, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_72$$22, &routeToIdx, &_73$$22, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 725);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_72$$22, PH_SEPARATE, "phalcon/Mvc/Router.zep", 725);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _69$$21, "rewind", &_zephir_call_cache[53]);
					zephir_check_call_status();
					_75$$21 = 1;
					while (1) {
						if (_75$$21) {
							_75$$21 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _69$$21, "next", &_zephir_call_cache[54]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_74$$21, _69$$21, "valid", &_zephir_call_cache[55]);
						zephir_check_call_status();
						if (!zend_is_true(&_74$$21)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&scalarVal, _69$$21, "current", &_zephir_call_cache[56]);
						zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&_77$$23, "spl_object_id", &_8, 30, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_76$$23, &routeToIdx, &_77$$23, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 725);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&mostInnerArr, &_76$$23, PH_SEPARATE, "phalcon/Mvc/Router.zep", 725);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&scalarVal);
				zephir_array_update_zval(&methodRoutesScalar, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	ZEPHIR_INIT_VAR(&candidatesScalar);
	array_init(&candidatesScalar);
	zephir_read_property_cached(&_78, this_ptr, _zephir_prop_3, 292, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_78) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_80);
		zephir_string_to_char_array(&_80, &_78);
		_79 = &_80;
	} else {
		_79 = &_78;
	}
	zephir_is_iterable(_79, 0, "phalcon/Mvc/Router.zep", 739);
	if (Z_TYPE_P(_79) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_79), _82, _83, _81)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_83 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _83);
			} else {
				ZVAL_LONG(&innerKey, _82);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _81);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_85$$24);
				zephir_string_to_char_array(&_85$$24, &innerVal);
				_84$$24 = &_85$$24;
			} else {
				_84$$24 = &innerVal;
			}
			zephir_is_iterable(_84$$24, 0, "phalcon/Mvc/Router.zep", 736);
			if (Z_TYPE_P(_84$$24) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_84$$24), _86$$24)
				{
					ZEPHIR_INIT_NVAR(&scalarVal);
					ZVAL_COPY(&scalarVal, _86$$24);
					ZEPHIR_CALL_FUNCTION(&_88$$25, "spl_object_id", &_8, 30, &scalarVal);
					zephir_check_call_status();
					zephir_array_fetch(&_87$$25, &routeToIdx, &_88$$25, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 734);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&mostInnerArr, &_87$$25, PH_SEPARATE, "phalcon/Mvc/Router.zep", 734);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _84$$24, "rewind", &_zephir_call_cache[57]);
				zephir_check_call_status();
				_90$$24 = 1;
				while (1) {
					if (_90$$24) {
						_90$$24 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _84$$24, "next", &_zephir_call_cache[58]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_89$$24, _84$$24, "valid", &_zephir_call_cache[59]);
					zephir_check_call_status();
					if (!zend_is_true(&_89$$24)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&scalarVal, _84$$24, "current", &_zephir_call_cache[60]);
					zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_92$$26, "spl_object_id", &_8, 30, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_91$$26, &routeToIdx, &_92$$26, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 734);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_91$$26, PH_SEPARATE, "phalcon/Mvc/Router.zep", 734);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&scalarVal);
			zephir_array_update_zval(&candidatesScalar, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _79, "rewind", &_zephir_call_cache[61]);
		zephir_check_call_status();
		_94 = 1;
		while (1) {
			if (_94) {
				_94 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _79, "next", &_zephir_call_cache[62]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_93, _79, "valid", &_zephir_call_cache[63]);
			zephir_check_call_status();
			if (!zend_is_true(&_93)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&innerKey, _79, "key", &_zephir_call_cache[64]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&innerVal, _79, "current", &_zephir_call_cache[65]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_96$$27);
					zephir_string_to_char_array(&_96$$27, &innerVal);
					_95$$27 = &_96$$27;
				} else {
					_95$$27 = &innerVal;
				}
				zephir_is_iterable(_95$$27, 0, "phalcon/Mvc/Router.zep", 736);
				if (Z_TYPE_P(_95$$27) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_95$$27), _97$$27)
					{
						ZEPHIR_INIT_NVAR(&scalarVal);
						ZVAL_COPY(&scalarVal, _97$$27);
						ZEPHIR_CALL_FUNCTION(&_99$$28, "spl_object_id", &_8, 30, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_98$$28, &routeToIdx, &_99$$28, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 734);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_98$$28, PH_SEPARATE, "phalcon/Mvc/Router.zep", 734);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _95$$27, "rewind", &_zephir_call_cache[66]);
					zephir_check_call_status();
					_101$$27 = 1;
					while (1) {
						if (_101$$27) {
							_101$$27 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _95$$27, "next", &_zephir_call_cache[67]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_100$$27, _95$$27, "valid", &_zephir_call_cache[68]);
						zephir_check_call_status();
						if (!zend_is_true(&_100$$27)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&scalarVal, _95$$27, "current", &_zephir_call_cache[69]);
						zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&_103$$29, "spl_object_id", &_8, 30, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_102$$29, &routeToIdx, &_103$$29, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 734);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&mostInnerArr, &_102$$29, PH_SEPARATE, "phalcon/Mvc/Router.zep", 734);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&scalarVal);
				zephir_array_update_zval(&candidatesScalar, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	ZEPHIR_INIT_VAR(&staticScalar);
	array_init(&staticScalar);
	zephir_read_property_cached(&_104, this_ptr, _zephir_prop_4, 293, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_104) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_106);
		zephir_string_to_char_array(&_106, &_104);
		_105 = &_106;
	} else {
		_105 = &_104;
	}
	zephir_is_iterable(_105, 0, "phalcon/Mvc/Router.zep", 751);
	if (Z_TYPE_P(_105) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_105), _108, _109, _107)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_109 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _109);
			} else {
				ZVAL_LONG(&innerKey, _108);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _107);
			ZEPHIR_INIT_NVAR(&_110$$30);
			array_init(&_110$$30);
			zephir_array_update_zval(&staticScalar, &innerKey, &_110$$30, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_112$$30);
				zephir_string_to_char_array(&_112$$30, &innerVal);
				_111$$30 = &_112$$30;
			} else {
				_111$$30 = &innerVal;
			}
			zephir_is_iterable(_111$$30, 0, "phalcon/Mvc/Router.zep", 749);
			if (Z_TYPE_P(_111$$30) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_111$$30), _114$$30, _115$$30, _113$$30)
				{
					ZEPHIR_INIT_NVAR(&scalarSubKey);
					if (_115$$30 != NULL) { 
						ZVAL_STR_COPY(&scalarSubKey, _115$$30);
					} else {
						ZVAL_LONG(&scalarSubKey, _114$$30);
					}
					ZEPHIR_INIT_NVAR(&mostInnerVal);
					ZVAL_COPY(&mostInnerVal, _113$$30);
					ZEPHIR_INIT_NVAR(&mostInnerArr);
					array_init(&mostInnerArr);
					if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_117$$31);
						zephir_string_to_char_array(&_117$$31, &mostInnerVal);
						_116$$31 = &_117$$31;
					} else {
						_116$$31 = &mostInnerVal;
					}
					zephir_is_iterable(_116$$31, 0, "phalcon/Mvc/Router.zep", 747);
					if (Z_TYPE_P(_116$$31) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_116$$31), _118$$31)
						{
							ZEPHIR_INIT_NVAR(&scalarVal);
							ZVAL_COPY(&scalarVal, _118$$31);
							ZEPHIR_CALL_FUNCTION(&_120$$32, "spl_object_id", &_8, 30, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_119$$32, &routeToIdx, &_120$$32, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&mostInnerArr, &_119$$32, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _116$$31, "rewind", &_zephir_call_cache[70]);
						zephir_check_call_status();
						_122$$31 = 1;
						while (1) {
							if (_122$$31) {
								_122$$31 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _116$$31, "next", &_zephir_call_cache[71]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_121$$31, _116$$31, "valid", &_zephir_call_cache[72]);
							zephir_check_call_status();
							if (!zend_is_true(&_121$$31)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&scalarVal, _116$$31, "current", &_zephir_call_cache[73]);
							zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&_124$$33, "spl_object_id", &_8, 30, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_123$$33, &routeToIdx, &_124$$33, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&mostInnerArr, &_123$$33, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&scalarVal);
					zephir_array_update_multi(&staticScalar, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _111$$30, "rewind", &_zephir_call_cache[74]);
				zephir_check_call_status();
				_126$$30 = 1;
				while (1) {
					if (_126$$30) {
						_126$$30 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _111$$30, "next", &_zephir_call_cache[75]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_125$$30, _111$$30, "valid", &_zephir_call_cache[76]);
					zephir_check_call_status();
					if (!zend_is_true(&_125$$30)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&scalarSubKey, _111$$30, "key", &_zephir_call_cache[77]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&mostInnerVal, _111$$30, "current", &_zephir_call_cache[78]);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_128$$34);
							zephir_string_to_char_array(&_128$$34, &mostInnerVal);
							_127$$34 = &_128$$34;
						} else {
							_127$$34 = &mostInnerVal;
						}
						zephir_is_iterable(_127$$34, 0, "phalcon/Mvc/Router.zep", 747);
						if (Z_TYPE_P(_127$$34) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_127$$34), _129$$34)
							{
								ZEPHIR_INIT_NVAR(&scalarVal);
								ZVAL_COPY(&scalarVal, _129$$34);
								ZEPHIR_CALL_FUNCTION(&_131$$35, "spl_object_id", &_8, 30, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_130$$35, &routeToIdx, &_131$$35, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&mostInnerArr, &_130$$35, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _127$$34, "rewind", &_zephir_call_cache[79]);
							zephir_check_call_status();
							_133$$34 = 1;
							while (1) {
								if (_133$$34) {
									_133$$34 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _127$$34, "next", &_zephir_call_cache[80]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_132$$34, _127$$34, "valid", &_zephir_call_cache[81]);
								zephir_check_call_status();
								if (!zend_is_true(&_132$$34)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&scalarVal, _127$$34, "current", &_zephir_call_cache[82]);
								zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_135$$36, "spl_object_id", &_8, 30, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_134$$36, &routeToIdx, &_135$$36, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&mostInnerArr, &_134$$36, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
							}
						}
						ZEPHIR_INIT_NVAR(&scalarVal);
						zephir_array_update_multi(&staticScalar, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&mostInnerVal);
			ZEPHIR_INIT_NVAR(&scalarSubKey);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _105, "rewind", &_zephir_call_cache[83]);
		zephir_check_call_status();
		_137 = 1;
		while (1) {
			if (_137) {
				_137 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _105, "next", &_zephir_call_cache[84]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_136, _105, "valid", &_zephir_call_cache[85]);
			zephir_check_call_status();
			if (!zend_is_true(&_136)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&innerKey, _105, "key", &_zephir_call_cache[86]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&innerVal, _105, "current", &_zephir_call_cache[87]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_138$$37);
				array_init(&_138$$37);
				zephir_array_update_zval(&staticScalar, &innerKey, &_138$$37, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_140$$37);
					zephir_string_to_char_array(&_140$$37, &innerVal);
					_139$$37 = &_140$$37;
				} else {
					_139$$37 = &innerVal;
				}
				zephir_is_iterable(_139$$37, 0, "phalcon/Mvc/Router.zep", 749);
				if (Z_TYPE_P(_139$$37) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_139$$37), _142$$37, _143$$37, _141$$37)
					{
						ZEPHIR_INIT_NVAR(&scalarSubKey);
						if (_143$$37 != NULL) { 
							ZVAL_STR_COPY(&scalarSubKey, _143$$37);
						} else {
							ZVAL_LONG(&scalarSubKey, _142$$37);
						}
						ZEPHIR_INIT_NVAR(&mostInnerVal);
						ZVAL_COPY(&mostInnerVal, _141$$37);
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_145$$38);
							zephir_string_to_char_array(&_145$$38, &mostInnerVal);
							_144$$38 = &_145$$38;
						} else {
							_144$$38 = &mostInnerVal;
						}
						zephir_is_iterable(_144$$38, 0, "phalcon/Mvc/Router.zep", 747);
						if (Z_TYPE_P(_144$$38) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_144$$38), _146$$38)
							{
								ZEPHIR_INIT_NVAR(&scalarVal);
								ZVAL_COPY(&scalarVal, _146$$38);
								ZEPHIR_CALL_FUNCTION(&_148$$39, "spl_object_id", &_8, 30, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_147$$39, &routeToIdx, &_148$$39, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&mostInnerArr, &_147$$39, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _144$$38, "rewind", &_zephir_call_cache[88]);
							zephir_check_call_status();
							_150$$38 = 1;
							while (1) {
								if (_150$$38) {
									_150$$38 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _144$$38, "next", &_zephir_call_cache[89]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_149$$38, _144$$38, "valid", &_zephir_call_cache[90]);
								zephir_check_call_status();
								if (!zend_is_true(&_149$$38)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&scalarVal, _144$$38, "current", &_zephir_call_cache[91]);
								zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_152$$40, "spl_object_id", &_8, 30, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_151$$40, &routeToIdx, &_152$$40, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&mostInnerArr, &_151$$40, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
							}
						}
						ZEPHIR_INIT_NVAR(&scalarVal);
						zephir_array_update_multi(&staticScalar, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _139$$37, "rewind", &_zephir_call_cache[92]);
					zephir_check_call_status();
					_154$$37 = 1;
					while (1) {
						if (_154$$37) {
							_154$$37 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _139$$37, "next", &_zephir_call_cache[93]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_153$$37, _139$$37, "valid", &_zephir_call_cache[94]);
						zephir_check_call_status();
						if (!zend_is_true(&_153$$37)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&scalarSubKey, _139$$37, "key", &_zephir_call_cache[95]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&mostInnerVal, _139$$37, "current", &_zephir_call_cache[96]);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&mostInnerArr);
							array_init(&mostInnerArr);
							if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_156$$41);
								zephir_string_to_char_array(&_156$$41, &mostInnerVal);
								_155$$41 = &_156$$41;
							} else {
								_155$$41 = &mostInnerVal;
							}
							zephir_is_iterable(_155$$41, 0, "phalcon/Mvc/Router.zep", 747);
							if (Z_TYPE_P(_155$$41) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_155$$41), _157$$41)
								{
									ZEPHIR_INIT_NVAR(&scalarVal);
									ZVAL_COPY(&scalarVal, _157$$41);
									ZEPHIR_CALL_FUNCTION(&_159$$42, "spl_object_id", &_8, 30, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_158$$42, &routeToIdx, &_159$$42, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&mostInnerArr, &_158$$42, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _155$$41, "rewind", &_zephir_call_cache[97]);
								zephir_check_call_status();
								_161$$41 = 1;
								while (1) {
									if (_161$$41) {
										_161$$41 = 0;
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _155$$41, "next", &_zephir_call_cache[98]);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD_CACHED(&_160$$41, _155$$41, "valid", &_zephir_call_cache[99]);
									zephir_check_call_status();
									if (!zend_is_true(&_160$$41)) {
										break;
									}
									ZEPHIR_CALL_METHOD_CACHED(&scalarVal, _155$$41, "current", &_zephir_call_cache[100]);
									zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_163$$43, "spl_object_id", &_8, 30, &scalarVal);
										zephir_check_call_status();
										zephir_array_fetch(&_162$$43, &routeToIdx, &_163$$43, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&mostInnerArr, &_162$$43, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
								}
							}
							ZEPHIR_INIT_NVAR(&scalarVal);
							zephir_array_update_multi(&staticScalar, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
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
	zephir_memory_observe(&_164);
	zephir_read_property_cached(&_164, this_ptr, _zephir_prop_5, 294, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(return_value, SL("staticShadowedByMethod"), &_164, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_164);
	zephir_read_property_cached(&_164, this_ptr, _zephir_prop_6, 295, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(return_value, SL("hostnameByMethod"), &_164, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_164);
	zephir_read_property_cached(&_164, this_ptr, _zephir_prop_7, 296, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(return_value, SL("hostnameLessByMethod"), &_164, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_164);
	zephir_read_property_cached(&_164, this_ptr, _zephir_prop_8, 297, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(return_value, SL("combinedRegexByMethod"), &_164, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_164);
	zephir_read_property_cached(&_164, this_ptr, _zephir_prop_9, 298, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(return_value, SL("combinedRegexDisabled"), &_164, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_164);
	zephir_read_property_cached(&_164, this_ptr, _zephir_prop_10, 299, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(return_value, SL("combinedRegexMarkMap"), &_164, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_164);
	zephir_read_property_cached(&_164, this_ptr, _zephir_prop_11, 300, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(return_value, SL("routeMeta"), &_164, PH_COPY | PH_SEPARATE);
	RETURN_MM();
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 289, &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 291, &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 292, &_2);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 300, &_3);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 293, &_4);
	ZEPHIR_INIT_VAR(&_5);
	array_init(&_5);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 294, &_5);
	ZEPHIR_INIT_VAR(&_6);
	array_init(&_6);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 295, &_6);
	ZEPHIR_INIT_VAR(&_7);
	array_init(&_7);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 296, &_7);
	ZEPHIR_INIT_VAR(&_8);
	array_init(&_8);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 297, &_8);
	ZEPHIR_INIT_VAR(&_9);
	array_init(&_9);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 298, &_9);
	ZEPHIR_INIT_VAR(&_10);
	array_init(&_10);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 299, &_10);
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 290, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 290, &__$false);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	ZEPHIR_CALL_METHOD_CACHED(&dump, this_ptr, "buildDispatcherDump", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_var_export_ex(&_0, &dump);
	ZEPHIR_INIT_VAR(&php);
	ZEPHIR_CONCAT_SVS(&php, "<?php\nreturn ", &_0, ";\n");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_1, "getmypid", NULL, 78);
	zephir_check_call_status();
	zephir_cast_to_string(&_2, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSV(&_3, &path_zv, ".tmp.", &_2);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&tmpPath, &_3);
	ZEPHIR_CALL_METHOD_CACHED(&_4, this_ptr, "phpFilePutContents", &_zephir_call_cache[1], &tmpPath, &php);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SV(&_6$$3, "Failed to write router cache temp file: ", &tmpPath);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$3, "__construct", &_zephir_call_cache[2], &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "phalcon/Mvc/Router.zep", 802);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_7, "rename", NULL, 79, &tmpPath, &path_zv);
	zephir_check_call_status();
	if (!(zephir_is_true(&_7))) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "phpUnlink", &_zephir_call_cache[3], &tmpPath);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$4);
		object_init_ex(&_8$$4, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZEPHIR_CONCAT_SV(&_9$$4, "Failed to commit router cache: ", &path_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_8$$4, "__construct", &_zephir_call_cache[4], &_9$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$4, "phalcon/Mvc/Router.zep", 807);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
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
 *
 * @phpstan-return array<string, mixed>
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 301, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(return_value, SL("namespace"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 302, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(return_value, SL("module"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 303, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(return_value, SL("controller"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 304, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(return_value, SL("action"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 305, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(return_value, SL("params"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Mvc_Router, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * @phpstan-return array<array-key, int|string>
 */
PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteIds)
{

	RETURN_MEMBER_TYPED(getThis(), "keyRouteIds", IS_ARRAY);
}

/**
 * @phpstan-return array<string, int|string>
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
 *
 * @phpstan-return mvc_router_matches
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatches)
{

	RETURN_MEMBER_TYPED(getThis(), "matches", IS_ARRAY);
}

/**
 * Returns the routes indexed by HTTP method.
 * Routes with no HTTP constraint are stored under the "*" key.
 *
 * @phpstan-return mvc_router_method_buckets
 */
PHP_METHOD(Phalcon_Mvc_Router, getMethodRoutes)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("methodRoutesDirty", 17, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 290, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "rebuildMethodIndex", &_zephir_call_cache[0]);
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
 *
 * @phpstan-return mvc_router_params
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
	zend_bool _1$$3, _2$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _GET, _SERVER, url, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("uriSource", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_GET, SL("_GET"));

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 306, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 0)) {
		zephir_memory_observe(&url);
		_1$$3 = zephir_array_isset_string_fetch(&url, &_GET, SL("_url"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_1$$3) {
			if (!(ZEPHIR_IS_EMPTY(&url))) {
				ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "extractRealUri", &_zephir_call_cache[0], &url);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
	} else {
		ZEPHIR_OBS_NVAR(&url);
		_2$$6 = zephir_array_isset_string_fetch(&url, &_SERVER, SL("REQUEST_URI"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_2$$6) {
			if (!(ZEPHIR_IS_EMPTY(&url))) {
				ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "extractRealUri", &_zephir_call_cache[1], &url);
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
	zend_string *_9;
	zend_ulong _8;
	zend_bool _1, _12, _10$$4, _13$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routeId, routeId_sub, localRouteId, route, key, _0, _4, *_5, _6, *_7, _11, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeId_sub);
	ZVAL_UNDEF(&localRouteId);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 307, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_fetch(&key, &_0, routeId, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_1, 289, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_3$$3);
		zephir_array_fetch(&_3$$3, &_2$$3, &key, PH_NOISY, "phalcon/Mvc/Router.zep", 969);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&_3$$3);
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 289, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_4) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_6);
		zephir_string_to_char_array(&_6, &_4);
		_5 = &_6;
	} else {
		_5 = &_4;
	}
	zephir_is_iterable(_5, 0, "phalcon/Mvc/Router.zep", 981);
	if (Z_TYPE_P(_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_5), _8, _9, _7)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&key, _9);
			} else {
				ZVAL_LONG(&key, _8);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _7);
			ZEPHIR_CALL_METHOD_CACHED(&localRouteId, &route, "getRouteId", &_zephir_call_cache[0]);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("keyRouteIds"), &localRouteId, &key);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_10$$4 = ZEPHIR_IS_EQUAL(&localRouteId, routeId);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_10$$4) {
				RETURN_CCTOR(&route);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_11, _5, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, _5, "key", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&route, _5, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&localRouteId, &route, "getRouteId", &_zephir_call_cache[6]);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("keyRouteIds"), &localRouteId, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_13$$6 = ZEPHIR_IS_EQUAL(&localRouteId, routeId);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_13$$6) {
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
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName)
{
	zend_ulong _8;
	zend_bool _1, _12, _10$$5, _13$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, route, routeName, key, _0, _4, *_5, _6, *_7, _11, _2$$3, _3$$3;
	zend_string *name = NULL, *_9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 308, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_fetch(&key, &_0, &name_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_1, 289, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_3$$3);
		zephir_array_fetch(&_3$$3, &_2$$3, &key, PH_NOISY, "phalcon/Mvc/Router.zep", 992);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&_3$$3);
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 289, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_4) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_6);
		zephir_string_to_char_array(&_6, &_4);
		_5 = &_6;
	} else {
		_5 = &_4;
	}
	zephir_is_iterable(_5, 0, "phalcon/Mvc/Router.zep", 1007);
	if (Z_TYPE_P(_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_5), _8, _9, _7)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&key, _9);
			} else {
				ZVAL_LONG(&key, _8);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _7);
			ZEPHIR_CALL_METHOD_CACHED(&routeName, &route, "getName", &_zephir_call_cache[0]);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&routeName))) {
				zephir_update_property_array(this_ptr, SL("keyRouteNames"), &routeName, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_10$$5 = ZEPHIR_IS_EQUAL(&routeName, &name_zv);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_10$$5) {
					RETURN_CCTOR(&route);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_11, _5, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, _5, "key", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&route, _5, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&routeName, &route, "getName", &_zephir_call_cache[6]);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&routeName))) {
					zephir_update_property_array(this_ptr, SL("keyRouteNames"), &routeName, &key);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_13$$8 = ZEPHIR_IS_EQUAL(&routeName, &name_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_13$$8) {
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
	zend_ulong _66$$39, _79$$40, _114$$62, _140$$84, _155$$103, _190$$140;
	zend_bool _1, _10, _14, _15, _17, _19, _20, _22, _55, _56, _58, _59, _61, _12$$11, _25$$15, _26$$15, _29$$15, _31$$15, _32$$15, _35$$15, _36$$15, _39$$15, _50$$18, _46$$24, _52$$34, _102$$39, _70$$40, _91$$40, _82$$46, _83$$46, _84$$49, _85$$49, _87$$51, _88$$51, _93$$54, _94$$54, _95$$57, _96$$57, _98$$59, _99$$59, _105$$62, _126$$62, _117$$68, _118$$68, _119$$71, _120$$71, _122$$73, _123$$73, _128$$76, _129$$76, _130$$79, _131$$79, _133$$81, _134$$81, _176$$84, _142$$85, _146$$91, _148$$95, _166$$103, _158$$104, _159$$104, _160$$108, _162$$110, _163$$110, _168$$113, _169$$113, _170$$117, _172$$119, _173$$119, _177$$122, _181$$128, _183$$132, _201$$140, _193$$141, _194$$141, _195$$145, _197$$147, _198$$147, _203$$150, _204$$150, _205$$154, _207$$156, _208$$156, _216$$163, _217$$163, _218$$163, _219$$163, _220$$163;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, __$true, __$false, __$null, action, beforeMatch, candidateMethod, candidateRoutes, container, controller, converter, converters, currentHostName, eventsManager, handledUri, hostname, matched, matches, matchPosition, module, notFoundPaths, params, paramsStr, part, parts, paths, pattern, position, realUri, regexHostName, request, requestMethod, route, routeFound, routeId, routeIdx, routeMeta, staticBeforeMatch, staticBucket, staticBucketMethod, staticHostname, staticHostRegex, staticMatched, staticRoute, strParams, vetoedRoutes, vnamespace, _0, _3, _4, _7, _8, _9, _13, _16, _18, _21, combinedChunks, combinedMarkMaps, combinedChunkIdx, combinedChunk, combinedMatchesLocal, combinedMarkLabel, combinedRouteIdx, combinedRoute, combinedRouteMeta, combinedBeforeMatch, combinedPaths, combinedConverters, combinedPart, combinedPosition, combinedMatchPosition, combinedConverter, _57, _60, _211, _212, _213, _214, _215, _224, _2$$5, _5$$8, _6$$9, _11$$11, _23$$15, _24$$15, _27$$15, _28$$15, _30$$15, _33$$15, _34$$15, _37$$15, _38$$15, _40$$18, _41$$18, *_42$$18, _43$$18, *_44$$18, _49$$18, _45$$23, _47$$27, _48$$28, _51$$33, _53$$37, _54$$38, _62$$39, *_63$$39, _64$$39, *_65$$39, _101$$39, _68$$40, _69$$40, _71$$40, _72$$40, *_76$$40, _77$$40, *_78$$40, _90$$40, _73$$44, _74$$43, _75$$45, _81$$47, _86$$50, _89$$52, _92$$55, _97$$58, _100$$60, _103$$62, _104$$62, _106$$62, _107$$62, *_111$$62, _112$$62, *_113$$62, _125$$62, _108$$66, _109$$65, _110$$67, _116$$69, _121$$72, _124$$74, _127$$77, _132$$80, _135$$82, _136$$84, *_137$$84, _138$$84, *_139$$84, _175$$84, _143$$85, _144$$85, _145$$90, _147$$93, _149$$97, _150$$99, _151$$101, *_152$$103, _153$$103, *_154$$103, _165$$103, _157$$105, _161$$109, _164$$111, _167$$114, _171$$118, _174$$120, _178$$122, _179$$122, _180$$127, _182$$130, _184$$134, _185$$136, _186$$138, *_187$$140, _188$$140, *_189$$140, _200$$140, _192$$142, _196$$146, _199$$148, _202$$151, _206$$155, _209$$157, _210$$161, _221$$169, _222$$171, _223$$173, _225$$174, _226$$174, _227$$174, _228$$174;
	zend_string *uri = NULL, *_67$$39, *_80$$40, *_115$$62, *_141$$84, *_156$$103, *_191$$140;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&candidateMethod);
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
	ZVAL_UNDEF(&routeId);
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
	ZVAL_UNDEF(&vetoedRoutes);
	ZVAL_UNDEF(&vnamespace);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_21);
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
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_60);
	ZVAL_UNDEF(&_211);
	ZVAL_UNDEF(&_212);
	ZVAL_UNDEF(&_213);
	ZVAL_UNDEF(&_214);
	ZVAL_UNDEF(&_215);
	ZVAL_UNDEF(&_224);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_34$$15);
	ZVAL_UNDEF(&_37$$15);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_40$$18);
	ZVAL_UNDEF(&_41$$18);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_49$$18);
	ZVAL_UNDEF(&_45$$23);
	ZVAL_UNDEF(&_47$$27);
	ZVAL_UNDEF(&_48$$28);
	ZVAL_UNDEF(&_51$$33);
	ZVAL_UNDEF(&_53$$37);
	ZVAL_UNDEF(&_54$$38);
	ZVAL_UNDEF(&_62$$39);
	ZVAL_UNDEF(&_64$$39);
	ZVAL_UNDEF(&_101$$39);
	ZVAL_UNDEF(&_68$$40);
	ZVAL_UNDEF(&_69$$40);
	ZVAL_UNDEF(&_71$$40);
	ZVAL_UNDEF(&_72$$40);
	ZVAL_UNDEF(&_77$$40);
	ZVAL_UNDEF(&_90$$40);
	ZVAL_UNDEF(&_73$$44);
	ZVAL_UNDEF(&_74$$43);
	ZVAL_UNDEF(&_75$$45);
	ZVAL_UNDEF(&_81$$47);
	ZVAL_UNDEF(&_86$$50);
	ZVAL_UNDEF(&_89$$52);
	ZVAL_UNDEF(&_92$$55);
	ZVAL_UNDEF(&_97$$58);
	ZVAL_UNDEF(&_100$$60);
	ZVAL_UNDEF(&_103$$62);
	ZVAL_UNDEF(&_104$$62);
	ZVAL_UNDEF(&_106$$62);
	ZVAL_UNDEF(&_107$$62);
	ZVAL_UNDEF(&_112$$62);
	ZVAL_UNDEF(&_125$$62);
	ZVAL_UNDEF(&_108$$66);
	ZVAL_UNDEF(&_109$$65);
	ZVAL_UNDEF(&_110$$67);
	ZVAL_UNDEF(&_116$$69);
	ZVAL_UNDEF(&_121$$72);
	ZVAL_UNDEF(&_124$$74);
	ZVAL_UNDEF(&_127$$77);
	ZVAL_UNDEF(&_132$$80);
	ZVAL_UNDEF(&_135$$82);
	ZVAL_UNDEF(&_136$$84);
	ZVAL_UNDEF(&_138$$84);
	ZVAL_UNDEF(&_175$$84);
	ZVAL_UNDEF(&_143$$85);
	ZVAL_UNDEF(&_144$$85);
	ZVAL_UNDEF(&_145$$90);
	ZVAL_UNDEF(&_147$$93);
	ZVAL_UNDEF(&_149$$97);
	ZVAL_UNDEF(&_150$$99);
	ZVAL_UNDEF(&_151$$101);
	ZVAL_UNDEF(&_153$$103);
	ZVAL_UNDEF(&_165$$103);
	ZVAL_UNDEF(&_157$$105);
	ZVAL_UNDEF(&_161$$109);
	ZVAL_UNDEF(&_164$$111);
	ZVAL_UNDEF(&_167$$114);
	ZVAL_UNDEF(&_171$$118);
	ZVAL_UNDEF(&_174$$120);
	ZVAL_UNDEF(&_178$$122);
	ZVAL_UNDEF(&_179$$122);
	ZVAL_UNDEF(&_180$$127);
	ZVAL_UNDEF(&_182$$130);
	ZVAL_UNDEF(&_184$$134);
	ZVAL_UNDEF(&_185$$136);
	ZVAL_UNDEF(&_186$$138);
	ZVAL_UNDEF(&_188$$140);
	ZVAL_UNDEF(&_200$$140);
	ZVAL_UNDEF(&_192$$142);
	ZVAL_UNDEF(&_196$$146);
	ZVAL_UNDEF(&_199$$148);
	ZVAL_UNDEF(&_202$$151);
	ZVAL_UNDEF(&_206$$155);
	ZVAL_UNDEF(&_209$$157);
	ZVAL_UNDEF(&_210$$161);
	ZVAL_UNDEF(&_221$$169);
	ZVAL_UNDEF(&_222$$171);
	ZVAL_UNDEF(&_223$$173);
	ZVAL_UNDEF(&_225$$174);
	ZVAL_UNDEF(&_226$$174);
	ZVAL_UNDEF(&_227$$174);
	ZVAL_UNDEF(&_228$$174);
	ZEND_TLS zephir_method_cache _zephir_call_cache[95];
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
		_zephir_prop_1 = zend_string_init("matches", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("wasMatched", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("matchedRoute", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("methodRoutesDirty", 17, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("candidatesByMethod", 18, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("hostnameByMethod", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("staticByMethod", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("staticShadowedByMethod", 22, 1);
	}
	if (UNEXPECTED(!_zephir_prop_11)) {
		_zephir_prop_11 = zend_string_init("combinedRegexDisabled", 21, 1);
	}
	if (UNEXPECTED(!_zephir_prop_12)) {
		_zephir_prop_12 = zend_string_init("combinedRegexByMethod", 21, 1);
	}
	if (UNEXPECTED(!_zephir_prop_13)) {
		_zephir_prop_13 = zend_string_init("combinedRegexMarkMap", 20, 1);
	}
	if (UNEXPECTED(!_zephir_prop_14)) {
		_zephir_prop_14 = zend_string_init("routeMeta", 9, 1);
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
		ZEPHIR_CALL_METHOD_CACHED(&realUri, this_ptr, "getRewriteUri", &_zephir_call_cache[0]);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(&realUri, this_ptr, "extractRealUri", &_zephir_call_cache[1], &uri_zv);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 309, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	ZEPHIR_INIT_VAR(&vetoedRoutes);
	array_init(&vetoedRoutes);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 310, &_3);
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 311, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 311, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 312, &__$null);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_4, 313, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&eventsManager, &_4);
	if (Z_TYPE_P(&eventsManager) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_5$$8);
		ZVAL_STRING(&_5$$8, "router:beforeCheckRoutes");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[2], &_5$$8, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_5, 314, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&container, &_4);
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_6$$9);
		object_init_ex(&_6$$9, phalcon_mvc_router_exceptions_requestserviceunavailable_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$9, "__construct", &_zephir_call_cache[3]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$9, "phalcon/Mvc/Router.zep", 1085);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "request");
	ZEPHIR_CALL_METHOD_CACHED(&_7, &container, "get", &_zephir_call_cache[4], &_8);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&request, &_7);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_6, 290, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&_4)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "rebuildMethodIndex", &_zephir_call_cache[5]);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_CACHED(&requestMethod, &request, "getMethod", &_zephir_call_cache[6]);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&candidateMethod, &requestMethod);
	ZEPHIR_INIT_VAR(&candidateRoutes);
	array_init(&candidateRoutes);
	ZEPHIR_OBS_NVAR(&candidateRoutes);
	zephir_read_property_cached(&_9, this_ptr, _zephir_prop_7, 292, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_10 = zephir_array_isset_fetch(&candidateRoutes, &_9, &requestMethod, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_10)) {
		ZEPHIR_INIT_NVAR(&candidateMethod);
		ZVAL_STRING(&candidateMethod, "*");
		ZEPHIR_OBS_NVAR(&candidateRoutes);
		zephir_read_property_cached(&_11$$11, this_ptr, _zephir_prop_7, 292, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_12$$11 = zephir_array_isset_string_fetch(&candidateRoutes, &_11$$11, SL("*"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_12$$11;
	}
	if (Z_TYPE_P(&candidateRoutes) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&candidateRoutes);
		array_init(&candidateRoutes);
	}
	zephir_read_property_cached(&_13, this_ptr, _zephir_prop_8, 295, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_14 = zephir_array_isset_value(&_13, &requestMethod);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_15 = _14;
	if (_15) {
		zephir_read_property_cached(&_16, this_ptr, _zephir_prop_8, 295, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_17 = zephir_isempty_dim(&_16, &requestMethod);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_15 = !(_17);
	}
	if (_15) {
		ZEPHIR_CALL_METHOD_CACHED(&currentHostName, &request, "getHttpHost", &_zephir_call_cache[7]);
		zephir_check_call_status();
	} else {
		zephir_read_property_cached(&_18, this_ptr, _zephir_prop_8, 295, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_19 = zephir_array_isset_value_string(&_18, SL("*"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_20 = _19;
		if (_20) {
			zephir_read_property_cached(&_21, this_ptr, _zephir_prop_8, 295, PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_22 = zephir_isempty_dim_string(&_21, SL("*"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_20 = !(_22);
		}
		if (_20) {
			ZEPHIR_CALL_METHOD_CACHED(&currentHostName, &request, "getHttpHost", &_zephir_call_cache[8]);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_NULL) {
		ZEPHIR_INIT_VAR(&staticBucketMethod);
		ZVAL_NULL(&staticBucketMethod);
		zephir_read_property_cached(&_23$$15, this_ptr, _zephir_prop_9, 293, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_24$$15);
		zephir_array_fetch(&_24$$15, &_23$$15, &requestMethod, 0, "phalcon/Mvc/Router.zep", 1140);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_25$$15 = zephir_array_isset_value(&_24$$15, &handledUri);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_26$$15 = _25$$15;
		if (_26$$15) {
			zephir_read_property_cached(&_27$$15, this_ptr, _zephir_prop_10, 294, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&_28$$15);
			zephir_array_fetch(&_28$$15, &_27$$15, &requestMethod, 0, "phalcon/Mvc/Router.zep", 1141);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_29$$15 = zephir_array_isset_value(&_28$$15, &handledUri);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_26$$15 = !(_29$$15);
		}
		if (_26$$15) {
			ZEPHIR_CPY_WRT(&staticBucketMethod, &requestMethod);
		} else {
			zephir_read_property_cached(&_30$$15, this_ptr, _zephir_prop_7, 292, PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_31$$15 = zephir_array_isset_value(&_30$$15, &requestMethod);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_32$$15 = !(_31$$15);
			if (_32$$15) {
				zephir_read_property_cached(&_33$$15, this_ptr, _zephir_prop_9, 293, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_memory_observe(&_34$$15);
				zephir_array_fetch_string(&_34$$15, &_33$$15, SL("*"), 0, "phalcon/Mvc/Router.zep", 1144);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_35$$15 = zephir_array_isset_value(&_34$$15, &handledUri);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_32$$15 = _35$$15;
			}
			_36$$15 = _32$$15;
			if (_36$$15) {
				zephir_read_property_cached(&_37$$15, this_ptr, _zephir_prop_10, 294, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_memory_observe(&_38$$15);
				zephir_array_fetch_string(&_38$$15, &_37$$15, SL("*"), 0, "phalcon/Mvc/Router.zep", 1145);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_39$$15 = zephir_array_isset_value(&_38$$15, &handledUri);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_36$$15 = !(_39$$15);
			}
			if (_36$$15) {
				ZEPHIR_INIT_NVAR(&staticBucketMethod);
				ZVAL_STRING(&staticBucketMethod, "*");
			}
		}
		if (Z_TYPE_P(&staticBucketMethod) != IS_NULL) {
			zephir_read_property_cached(&_40$$18, this_ptr, _zephir_prop_9, 293, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&_41$$18);
			zephir_array_fetch(&_41$$18, &_40$$18, &staticBucketMethod, PH_NOISY, "phalcon/Mvc/Router.zep", 1155);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&staticBucket);
			zephir_array_fetch(&staticBucket, &_41$$18, &handledUri, PH_NOISY, "phalcon/Mvc/Router.zep", 1155);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&staticBucket) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_43$$18);
				zephir_string_to_char_array(&_43$$18, &staticBucket);
				_42$$18 = &_43$$18;
			} else {
				_42$$18 = &staticBucket;
			}
			zephir_is_iterable(_42$$18, 0, "phalcon/Mvc/Router.zep", 1209);
			if (Z_TYPE_P(_42$$18) == IS_ARRAY) {
				ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(_42$$18), _44$$18)
				{
					ZEPHIR_INIT_NVAR(&staticRoute);
					ZVAL_COPY(&staticRoute, _44$$18);
					ZEPHIR_CALL_METHOD_CACHED(&staticHostname, &staticRoute, "getHostName", &_zephir_call_cache[9]);
					zephir_check_call_status();
					if (Z_TYPE_P(&staticHostname) != IS_NULL) {
						if (Z_TYPE_P(&currentHostName) == IS_NULL) {
							ZEPHIR_CALL_METHOD_CACHED(&currentHostName, &request, "getHttpHost", &_zephir_call_cache[10]);
							zephir_check_call_status();
						}
						if (!(zephir_is_true(&currentHostName))) {
							continue;
						}
						ZEPHIR_CALL_METHOD_CACHED(&staticHostRegex, &staticRoute, "getCompiledHostName", &_zephir_call_cache[11]);
						zephir_check_call_status();
						if (Z_TYPE_P(&staticHostRegex) != IS_NULL) {
							ZEPHIR_INIT_NVAR(&_45$$23);
							ZEPHIR_INIT_NVAR(&staticMatched);
							zephir_preg_match(&staticMatched, &staticHostRegex, &currentHostName, &_45$$23, 0, 0 , 0 );
						} else {
							_46$$24 = ZEPHIR_IS_EQUAL(&currentHostName, &staticHostname);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&staticMatched);
							ZVAL_BOOL(&staticMatched, _46$$24);
						}
						if (!(zephir_is_true(&staticMatched))) {
							continue;
						}
					}
					ZEPHIR_CALL_METHOD_CACHED(&staticBeforeMatch, &staticRoute, "getBeforeMatch", &_zephir_call_cache[12]);
					zephir_check_call_status();
					if (Z_TYPE_P(&staticBeforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&staticBeforeMatch)))) {
							ZEPHIR_INIT_NVAR(&_47$$27);
							object_init_ex(&_47$$27, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_47$$27, "__construct", &_zephir_call_cache[13]);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_47$$27, "phalcon/Mvc/Router.zep", 1186);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &staticBeforeMatch, NULL, 0, &handledUri, &staticRoute, this_ptr);
						zephir_check_call_status();
						if (!(zephir_is_true(&routeFound))) {
							ZEPHIR_CALL_METHOD_CACHED(&_48$$28, &staticRoute, "getRouteId", &_zephir_call_cache[14]);
							zephir_check_call_status();
							zephir_array_update_zval(&vetoedRoutes, &_48$$28, &__$true, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					}
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, 1);
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					ZEPHIR_CALL_METHOD_CACHED(&parts, &staticRoute, "getPaths", &_zephir_call_cache[15]);
					zephir_check_call_status();
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 312, &staticRoute);
					break;
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _42$$18, "rewind", &_zephir_call_cache[16]);
				zephir_check_call_status();
				_50$$18 = 1;
				while (1) {
					if (_50$$18) {
						_50$$18 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _42$$18, "next", &_zephir_call_cache[17]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_49$$18, _42$$18, "valid", &_zephir_call_cache[18]);
					zephir_check_call_status();
					if (!zend_is_true(&_49$$18)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&staticRoute, _42$$18, "current", &_zephir_call_cache[19]);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&staticHostname, &staticRoute, "getHostName", &_zephir_call_cache[20]);
						zephir_check_call_status();
						if (Z_TYPE_P(&staticHostname) != IS_NULL) {
							if (Z_TYPE_P(&currentHostName) == IS_NULL) {
								ZEPHIR_CALL_METHOD_CACHED(&currentHostName, &request, "getHttpHost", &_zephir_call_cache[21]);
								zephir_check_call_status();
							}
							if (!(zephir_is_true(&currentHostName))) {
								continue;
							}
							ZEPHIR_CALL_METHOD_CACHED(&staticHostRegex, &staticRoute, "getCompiledHostName", &_zephir_call_cache[22]);
							zephir_check_call_status();
							if (Z_TYPE_P(&staticHostRegex) != IS_NULL) {
								ZEPHIR_INIT_NVAR(&_51$$33);
								ZEPHIR_INIT_NVAR(&staticMatched);
								zephir_preg_match(&staticMatched, &staticHostRegex, &currentHostName, &_51$$33, 0, 0 , 0 );
							} else {
								_52$$34 = ZEPHIR_IS_EQUAL(&currentHostName, &staticHostname);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&staticMatched);
								ZVAL_BOOL(&staticMatched, _52$$34);
							}
							if (!(zephir_is_true(&staticMatched))) {
								continue;
							}
						}
						ZEPHIR_CALL_METHOD_CACHED(&staticBeforeMatch, &staticRoute, "getBeforeMatch", &_zephir_call_cache[23]);
						zephir_check_call_status();
						if (Z_TYPE_P(&staticBeforeMatch) != IS_NULL) {
							if (UNEXPECTED(!(zephir_is_callable(&staticBeforeMatch)))) {
								ZEPHIR_INIT_NVAR(&_53$$37);
								object_init_ex(&_53$$37, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_53$$37, "__construct", &_zephir_call_cache[24]);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_53$$37, "phalcon/Mvc/Router.zep", 1186);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &staticBeforeMatch, NULL, 0, &handledUri, &staticRoute, this_ptr);
							zephir_check_call_status();
							if (!(zephir_is_true(&routeFound))) {
								ZEPHIR_CALL_METHOD_CACHED(&_54$$38, &staticRoute, "getRouteId", &_zephir_call_cache[25]);
								zephir_check_call_status();
								zephir_array_update_zval(&vetoedRoutes, &_54$$38, &__$true, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								continue;
							}
						}
						ZEPHIR_INIT_NVAR(&routeFound);
						ZVAL_BOOL(&routeFound, 1);
						ZEPHIR_INIT_NVAR(&matches);
						ZVAL_NULL(&matches);
						ZEPHIR_CALL_METHOD_CACHED(&parts, &staticRoute, "getPaths", &_zephir_call_cache[26]);
						zephir_check_call_status();
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 312, &staticRoute);
						break;
				}
			}
			ZEPHIR_INIT_NVAR(&staticRoute);
		}
	}
	_55 = !zephir_is_true(&routeFound);
	if (_55) {
		_55 = Z_TYPE_P(&eventsManager) == IS_NULL;
	}
	_56 = _55;
	if (_56) {
		zephir_read_property_cached(&_57, this_ptr, _zephir_prop_11, 298, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_58 = zephir_array_isset_value(&_57, &candidateMethod);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_56 = !(_58);
	}
	_59 = _56;
	if (_59) {
		zephir_memory_observe(&combinedChunks);
		zephir_read_property_cached(&_60, this_ptr, _zephir_prop_12, 297, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_61 = zephir_array_isset_fetch(&combinedChunks, &_60, &candidateMethod, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_59 = _61;
	}
	if (_59) {
		zephir_read_property_cached(&_62$$39, this_ptr, _zephir_prop_13, 299, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&combinedMarkMaps);
		zephir_array_fetch(&combinedMarkMaps, &_62$$39, &candidateMethod, PH_NOISY, "phalcon/Mvc/Router.zep", 1229);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&combinedChunks) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_64$$39);
			zephir_string_to_char_array(&_64$$39, &combinedChunks);
			_63$$39 = &_64$$39;
		} else {
			_63$$39 = &combinedChunks;
		}
		zephir_is_iterable(_63$$39, 0, "phalcon/Mvc/Router.zep", 1307);
		if (Z_TYPE_P(_63$$39) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_63$$39), _66$$39, _67$$39, _65$$39)
			{
				ZEPHIR_INIT_NVAR(&combinedChunkIdx);
				if (_67$$39 != NULL) { 
					ZVAL_STR_COPY(&combinedChunkIdx, _67$$39);
				} else {
					ZVAL_LONG(&combinedChunkIdx, _66$$39);
				}
				ZEPHIR_INIT_NVAR(&combinedChunk);
				ZVAL_COPY(&combinedChunk, _65$$39);
				ZEPHIR_INIT_NVAR(&combinedMatchesLocal);
				array_init(&combinedMatchesLocal);
				ZEPHIR_INIT_NVAR(&_68$$40);
				zephir_preg_match(&_68$$40, &combinedChunk, &handledUri, &combinedMatchesLocal, 0, 0 , 0 );
				if (!(zephir_is_true(&_68$$40))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&combinedMarkLabel);
				zephir_array_fetch_string(&combinedMarkLabel, &combinedMatchesLocal, SL("MARK"), PH_NOISY, "phalcon/Mvc/Router.zep", 1238);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_unset_string(&combinedMatchesLocal, SL("MARK"), PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&combinedRouteIdx);
				ZEPHIR_OBS_NVAR(&_69$$40);
				zephir_array_fetch(&_69$$40, &combinedMarkMaps, &combinedChunkIdx, 0, "phalcon/Mvc/Router.zep", 1246);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_70$$40 = zephir_array_isset_fetch(&combinedRouteIdx, &_69$$40, &combinedMarkLabel, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_70$$40)) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&combinedRoute);
				zephir_array_fetch(&combinedRoute, &candidateRoutes, &combinedRouteIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1250);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property_cached(&_71$$40, this_ptr, _zephir_prop_14, 300, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&combinedRouteMeta);
				ZEPHIR_CALL_METHOD_CACHED(&_72$$40, &combinedRoute, "getRouteId", &_zephir_call_cache[27]);
				zephir_check_call_status();
				zephir_array_fetch(&combinedRouteMeta, &_71$$40, &_72$$40, PH_NOISY, "phalcon/Mvc/Router.zep", 1251);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&combinedBeforeMatch);
				zephir_array_fetch_string(&combinedBeforeMatch, &combinedRouteMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1253);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&combinedBeforeMatch) != IS_NULL) {
					if (UNEXPECTED(!(zephir_is_callable(&combinedBeforeMatch)))) {
						ZEPHIR_INIT_NVAR(&_73$$44);
						object_init_ex(&_73$$44, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_73$$44, "__construct", &_zephir_call_cache[28]);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_73$$44, "phalcon/Mvc/Router.zep", 1257);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_ZVAL_FUNCTION(&_74$$43, &combinedBeforeMatch, NULL, 0, &handledUri, &combinedRoute, this_ptr);
					zephir_check_call_status();
					if (!(zephir_is_true(&_74$$43))) {
						ZEPHIR_CALL_METHOD_CACHED(&_75$$45, &combinedRoute, "getRouteId", &_zephir_call_cache[29]);
						zephir_check_call_status();
						zephir_array_update_zval(&vetoedRoutes, &_75$$45, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						break;
					}
				}
				ZEPHIR_CALL_METHOD_CACHED(&combinedPaths, &combinedRoute, "getPaths", &_zephir_call_cache[30]);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&parts, &combinedPaths);
				ZEPHIR_CPY_WRT(&matches, &combinedMatchesLocal);
				ZEPHIR_CALL_METHOD_CACHED(&combinedConverters, &combinedRoute, "getConverters", &_zephir_call_cache[31]);
				zephir_check_call_status();
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 310, &combinedMatchesLocal);
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 312, &combinedRoute);
				ZEPHIR_INIT_NVAR(&routeFound);
				ZVAL_BOOL(&routeFound, 1);
				if (Z_TYPE_P(&combinedPaths) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_77$$40);
					zephir_string_to_char_array(&_77$$40, &combinedPaths);
					_76$$40 = &_77$$40;
				} else {
					_76$$40 = &combinedPaths;
				}
				zephir_is_iterable(_76$$40, 0, "phalcon/Mvc/Router.zep", 1305);
				if (Z_TYPE_P(_76$$40) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_76$$40), _79$$40, _80$$40, _78$$40)
					{
						ZEPHIR_INIT_NVAR(&combinedPart);
						if (_80$$40 != NULL) { 
							ZVAL_STR_COPY(&combinedPart, _80$$40);
						} else {
							ZVAL_LONG(&combinedPart, _79$$40);
						}
						ZEPHIR_INIT_NVAR(&combinedPosition);
						ZVAL_COPY(&combinedPosition, _78$$40);
						if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
							ZEPHIR_INIT_NVAR(&_81$$47);
							object_init_ex(&_81$$47, phalcon_mvc_router_exceptions_wrongpathskey_ce);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_81$$47, "__construct", &_zephir_call_cache[32], &combinedPart);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_81$$47, "phalcon/Mvc/Router.zep", 1282);
							ZEPHIR_MM_RESTORE();
							return;
						}
						_82$$46 = Z_TYPE_P(&combinedPosition) != IS_STRING;
						if (_82$$46) {
							_82$$46 = Z_TYPE_P(&combinedPosition) != IS_LONG;
						}
						if (_82$$46) {
							continue;
						}
						ZEPHIR_OBS_NVAR(&combinedMatchPosition);
						_83$$46 = zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_83$$46) {
							_84$$49 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
							if (_84$$49) {
								ZEPHIR_OBS_NVAR(&combinedConverter);
								_85$$49 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								_84$$49 = _85$$49;
							}
							if (_84$$49) {
								ZEPHIR_CALL_ZVAL_FUNCTION(&_86$$50, &combinedConverter, NULL, 0, &combinedMatchPosition);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, &combinedPart, &_86$$50, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								continue;
							}
							zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							_87$$51 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
							if (_87$$51) {
								ZEPHIR_OBS_NVAR(&combinedConverter);
								_88$$51 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								_87$$51 = _88$$51;
							}
							if (_87$$51) {
								ZEPHIR_CALL_ZVAL_FUNCTION(&_89$$52, &combinedConverter, NULL, 0, &combinedPosition);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, &combinedPart, &_89$$52, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else if (Z_TYPE_P(&combinedPosition) == IS_LONG) {
								zephir_array_unset(&parts, &combinedPart, PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _76$$40, "rewind", &_zephir_call_cache[33]);
					zephir_check_call_status();
					_91$$40 = 1;
					while (1) {
						if (_91$$40) {
							_91$$40 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _76$$40, "next", &_zephir_call_cache[34]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_90$$40, _76$$40, "valid", &_zephir_call_cache[35]);
						zephir_check_call_status();
						if (!zend_is_true(&_90$$40)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&combinedPart, _76$$40, "key", &_zephir_call_cache[36]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&combinedPosition, _76$$40, "current", &_zephir_call_cache[37]);
						zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
								ZEPHIR_INIT_NVAR(&_92$$55);
								object_init_ex(&_92$$55, phalcon_mvc_router_exceptions_wrongpathskey_ce);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_92$$55, "__construct", &_zephir_call_cache[38], &combinedPart);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_92$$55, "phalcon/Mvc/Router.zep", 1282);
								ZEPHIR_MM_RESTORE();
								return;
							}
							_93$$54 = Z_TYPE_P(&combinedPosition) != IS_STRING;
							if (_93$$54) {
								_93$$54 = Z_TYPE_P(&combinedPosition) != IS_LONG;
							}
							if (_93$$54) {
								continue;
							}
							ZEPHIR_OBS_NVAR(&combinedMatchPosition);
							_94$$54 = zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_94$$54) {
								_95$$57 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_95$$57) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_96$$57 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_95$$57 = _96$$57;
								}
								if (_95$$57) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_97$$58, &combinedConverter, NULL, 0, &combinedMatchPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_97$$58, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									continue;
								}
								zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								_98$$59 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_98$$59) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_99$$59 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_98$$59 = _99$$59;
								}
								if (_98$$59) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_100$$60, &combinedConverter, NULL, 0, &combinedPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_100$$60, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else if (Z_TYPE_P(&combinedPosition) == IS_LONG) {
									zephir_array_unset(&parts, &combinedPart, PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							}
					}
				}
				ZEPHIR_INIT_NVAR(&combinedPosition);
				ZEPHIR_INIT_NVAR(&combinedPart);
				break;
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _63$$39, "rewind", &_zephir_call_cache[39]);
			zephir_check_call_status();
			_102$$39 = 1;
			while (1) {
				if (_102$$39) {
					_102$$39 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _63$$39, "next", &_zephir_call_cache[40]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_101$$39, _63$$39, "valid", &_zephir_call_cache[41]);
				zephir_check_call_status();
				if (!zend_is_true(&_101$$39)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&combinedChunkIdx, _63$$39, "key", &_zephir_call_cache[42]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&combinedChunk, _63$$39, "current", &_zephir_call_cache[43]);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&combinedMatchesLocal);
					array_init(&combinedMatchesLocal);
					ZEPHIR_INIT_NVAR(&_103$$62);
					zephir_preg_match(&_103$$62, &combinedChunk, &handledUri, &combinedMatchesLocal, 0, 0 , 0 );
					if (!(zephir_is_true(&_103$$62))) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&combinedMarkLabel);
					zephir_array_fetch_string(&combinedMarkLabel, &combinedMatchesLocal, SL("MARK"), PH_NOISY, "phalcon/Mvc/Router.zep", 1238);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset_string(&combinedMatchesLocal, SL("MARK"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&combinedRouteIdx);
					ZEPHIR_OBS_NVAR(&_104$$62);
					zephir_array_fetch(&_104$$62, &combinedMarkMaps, &combinedChunkIdx, 0, "phalcon/Mvc/Router.zep", 1246);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_105$$62 = zephir_array_isset_fetch(&combinedRouteIdx, &_104$$62, &combinedMarkLabel, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_105$$62)) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&combinedRoute);
					zephir_array_fetch(&combinedRoute, &candidateRoutes, &combinedRouteIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1250);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property_cached(&_106$$62, this_ptr, _zephir_prop_14, 300, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&combinedRouteMeta);
					ZEPHIR_CALL_METHOD_CACHED(&_107$$62, &combinedRoute, "getRouteId", &_zephir_call_cache[44]);
					zephir_check_call_status();
					zephir_array_fetch(&combinedRouteMeta, &_106$$62, &_107$$62, PH_NOISY, "phalcon/Mvc/Router.zep", 1251);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&combinedBeforeMatch);
					zephir_array_fetch_string(&combinedBeforeMatch, &combinedRouteMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1253);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&combinedBeforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&combinedBeforeMatch)))) {
							ZEPHIR_INIT_NVAR(&_108$$66);
							object_init_ex(&_108$$66, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_108$$66, "__construct", &_zephir_call_cache[45]);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_108$$66, "phalcon/Mvc/Router.zep", 1257);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_ZVAL_FUNCTION(&_109$$65, &combinedBeforeMatch, NULL, 0, &handledUri, &combinedRoute, this_ptr);
						zephir_check_call_status();
						if (!(zephir_is_true(&_109$$65))) {
							ZEPHIR_CALL_METHOD_CACHED(&_110$$67, &combinedRoute, "getRouteId", &_zephir_call_cache[46]);
							zephir_check_call_status();
							zephir_array_update_zval(&vetoedRoutes, &_110$$67, &__$true, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							break;
						}
					}
					ZEPHIR_CALL_METHOD_CACHED(&combinedPaths, &combinedRoute, "getPaths", &_zephir_call_cache[47]);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&parts, &combinedPaths);
					ZEPHIR_CPY_WRT(&matches, &combinedMatchesLocal);
					ZEPHIR_CALL_METHOD_CACHED(&combinedConverters, &combinedRoute, "getConverters", &_zephir_call_cache[48]);
					zephir_check_call_status();
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 310, &combinedMatchesLocal);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 312, &combinedRoute);
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, 1);
					if (Z_TYPE_P(&combinedPaths) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_112$$62);
						zephir_string_to_char_array(&_112$$62, &combinedPaths);
						_111$$62 = &_112$$62;
					} else {
						_111$$62 = &combinedPaths;
					}
					zephir_is_iterable(_111$$62, 0, "phalcon/Mvc/Router.zep", 1305);
					if (Z_TYPE_P(_111$$62) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_111$$62), _114$$62, _115$$62, _113$$62)
						{
							ZEPHIR_INIT_NVAR(&combinedPart);
							if (_115$$62 != NULL) { 
								ZVAL_STR_COPY(&combinedPart, _115$$62);
							} else {
								ZVAL_LONG(&combinedPart, _114$$62);
							}
							ZEPHIR_INIT_NVAR(&combinedPosition);
							ZVAL_COPY(&combinedPosition, _113$$62);
							if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
								ZEPHIR_INIT_NVAR(&_116$$69);
								object_init_ex(&_116$$69, phalcon_mvc_router_exceptions_wrongpathskey_ce);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_116$$69, "__construct", &_zephir_call_cache[49], &combinedPart);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_116$$69, "phalcon/Mvc/Router.zep", 1282);
								ZEPHIR_MM_RESTORE();
								return;
							}
							_117$$68 = Z_TYPE_P(&combinedPosition) != IS_STRING;
							if (_117$$68) {
								_117$$68 = Z_TYPE_P(&combinedPosition) != IS_LONG;
							}
							if (_117$$68) {
								continue;
							}
							ZEPHIR_OBS_NVAR(&combinedMatchPosition);
							_118$$68 = zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_118$$68) {
								_119$$71 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_119$$71) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_120$$71 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_119$$71 = _120$$71;
								}
								if (_119$$71) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_121$$72, &combinedConverter, NULL, 0, &combinedMatchPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_121$$72, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									continue;
								}
								zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								_122$$73 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_122$$73) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_123$$73 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_122$$73 = _123$$73;
								}
								if (_122$$73) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_124$$74, &combinedConverter, NULL, 0, &combinedPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_124$$74, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else if (Z_TYPE_P(&combinedPosition) == IS_LONG) {
									zephir_array_unset(&parts, &combinedPart, PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _111$$62, "rewind", &_zephir_call_cache[50]);
						zephir_check_call_status();
						_126$$62 = 1;
						while (1) {
							if (_126$$62) {
								_126$$62 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _111$$62, "next", &_zephir_call_cache[51]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_125$$62, _111$$62, "valid", &_zephir_call_cache[52]);
							zephir_check_call_status();
							if (!zend_is_true(&_125$$62)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&combinedPart, _111$$62, "key", &_zephir_call_cache[53]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&combinedPosition, _111$$62, "current", &_zephir_call_cache[54]);
							zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
									ZEPHIR_INIT_NVAR(&_127$$77);
									object_init_ex(&_127$$77, phalcon_mvc_router_exceptions_wrongpathskey_ce);
									ZEPHIR_CALL_METHOD_CACHED(NULL, &_127$$77, "__construct", &_zephir_call_cache[55], &combinedPart);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_127$$77, "phalcon/Mvc/Router.zep", 1282);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_128$$76 = Z_TYPE_P(&combinedPosition) != IS_STRING;
								if (_128$$76) {
									_128$$76 = Z_TYPE_P(&combinedPosition) != IS_LONG;
								}
								if (_128$$76) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&combinedMatchPosition);
								_129$$76 = zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_129$$76) {
									_130$$79 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
									if (_130$$79) {
										ZEPHIR_OBS_NVAR(&combinedConverter);
										_131$$79 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										_130$$79 = _131$$79;
									}
									if (_130$$79) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_132$$80, &combinedConverter, NULL, 0, &combinedMatchPosition);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &combinedPart, &_132$$80, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										continue;
									}
									zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									_133$$81 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
									if (_133$$81) {
										ZEPHIR_OBS_NVAR(&combinedConverter);
										_134$$81 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										_133$$81 = _134$$81;
									}
									if (_133$$81) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_135$$82, &combinedConverter, NULL, 0, &combinedPosition);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &combinedPart, &_135$$82, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} else if (Z_TYPE_P(&combinedPosition) == IS_LONG) {
										zephir_array_unset(&parts, &combinedPart, PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
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
		ZEPHIR_CALL_FUNCTION(&_136$$84, "array_reverse", NULL, 80, &candidateRoutes, &__$true);
		zephir_check_call_status();
		if (Z_TYPE_P(&_136$$84) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_138$$84);
			zephir_string_to_char_array(&_138$$84, &_136$$84);
			_137$$84 = &_138$$84;
		} else {
			_137$$84 = &_136$$84;
		}
		zephir_is_iterable(_137$$84, 0, "phalcon/Mvc/Router.zep", 1477);
		if (Z_TYPE_P(_137$$84) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_137$$84), _140$$84, _141$$84, _139$$84)
			{
				ZEPHIR_INIT_NVAR(&routeIdx);
				if (_141$$84 != NULL) { 
					ZVAL_STR_COPY(&routeIdx, _141$$84);
				} else {
					ZVAL_LONG(&routeIdx, _140$$84);
				}
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _139$$84);
				ZEPHIR_CALL_METHOD_CACHED(&routeId, &route, "getRouteId", &_zephir_call_cache[56]);
				zephir_check_call_status();
				_142$$85 = zephir_array_isset_value(&vetoedRoutes, &routeId);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_142$$85) {
					continue;
				}
				zephir_read_property_cached(&_143$$85, this_ptr, _zephir_prop_14, 300, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_144$$85);
				zephir_array_fetch(&_144$$85, &_143$$85, &routeId, PH_NOISY, "phalcon/Mvc/Router.zep", 1325);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&routeMeta, &_144$$85);
				ZEPHIR_INIT_NVAR(&params);
				array_init(&params);
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				ZEPHIR_OBS_NVAR(&hostname);
				zephir_array_fetch_string(&hostname, &routeMeta, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1332);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&hostname) != IS_NULL) {
					if (Z_TYPE_P(&currentHostName) == IS_NULL) {
						ZEPHIR_CALL_METHOD_CACHED(&currentHostName, &request, "getHttpHost", &_zephir_call_cache[57]);
						zephir_check_call_status();
					}
					if (!(zephir_is_true(&currentHostName))) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&regexHostName);
					zephir_array_fetch_string(&regexHostName, &routeMeta, SL("hostRegex"), PH_NOISY, "phalcon/Mvc/Router.zep", 1352);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&regexHostName) != IS_NULL) {
						ZEPHIR_INIT_NVAR(&_145$$90);
						ZEPHIR_INIT_NVAR(&matched);
						zephir_preg_match(&matched, &regexHostName, &currentHostName, &_145$$90, 0, 0 , 0 );
					} else {
						_146$$91 = ZEPHIR_IS_EQUAL(&currentHostName, &hostname);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&matched);
						ZVAL_BOOL(&matched, _146$$91);
					}
					if (!(zephir_is_true(&matched))) {
						continue;
					}
				}
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_147$$93);
					ZVAL_STRING(&_147$$93, "router:beforeCheckRoute");
					ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[58], &_147$$93, this_ptr, &route);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&pattern);
				zephir_array_fetch_string(&pattern, &routeMeta, SL("pattern"), PH_NOISY, "phalcon/Mvc/Router.zep", 1372);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_144$$85);
				zephir_array_fetch_string(&_144$$85, &routeMeta, SL("isRegex"), PH_NOISY, "phalcon/Mvc/Router.zep", 1374);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&_144$$85)) {
					ZEPHIR_INIT_NVAR(&routeFound);
					zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
				} else {
					_148$$95 = ZEPHIR_IS_EQUAL(&pattern, &handledUri);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, _148$$95);
				}
				if (zephir_is_true(&routeFound)) {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_149$$97);
						ZVAL_STRING(&_149$$97, "router:matchedRoute");
						ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[59], &_149$$97, this_ptr, &route);
						zephir_check_call_status();
					}
					ZEPHIR_OBS_NVAR(&beforeMatch);
					zephir_array_fetch_string(&beforeMatch, &routeMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1388);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
							ZEPHIR_INIT_NVAR(&_150$$99);
							object_init_ex(&_150$$99, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_150$$99, "__construct", &_zephir_call_cache[60]);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_150$$99, "phalcon/Mvc/Router.zep", 1394);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &beforeMatch, NULL, 0, &handledUri, &route, this_ptr);
						zephir_check_call_status();
					}
				} else {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_151$$101);
						ZVAL_STRING(&_151$$101, "router:notMatchedRoute");
						ZEPHIR_CALL_METHOD_CACHED(&routeFound, &eventsManager, "fire", &_zephir_call_cache[61], &_151$$101, this_ptr, &route);
						zephir_check_call_status();
					}
				}
				if (zephir_is_true(&routeFound)) {
					ZEPHIR_CALL_METHOD_CACHED(&paths, &route, "getPaths", &_zephir_call_cache[62]);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&parts, &paths);
					if (Z_TYPE_P(&matches) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD_CACHED(&converters, &route, "getConverters", &_zephir_call_cache[63]);
						zephir_check_call_status();
						if (Z_TYPE_P(&paths) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_153$$103);
							zephir_string_to_char_array(&_153$$103, &paths);
							_152$$103 = &_153$$103;
						} else {
							_152$$103 = &paths;
						}
						zephir_is_iterable(_152$$103, 0, "phalcon/Mvc/Router.zep", 1469);
						if (Z_TYPE_P(_152$$103) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_152$$103), _155$$103, _156$$103, _154$$103)
							{
								ZEPHIR_INIT_NVAR(&part);
								if (_156$$103 != NULL) { 
									ZVAL_STR_COPY(&part, _156$$103);
								} else {
									ZVAL_LONG(&part, _155$$103);
								}
								ZEPHIR_INIT_NVAR(&position);
								ZVAL_COPY(&position, _154$$103);
								if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
									ZEPHIR_INIT_NVAR(&_157$$105);
									object_init_ex(&_157$$105, phalcon_mvc_router_exceptions_wrongpathskey_ce);
									ZEPHIR_CALL_METHOD_CACHED(NULL, &_157$$105, "__construct", &_zephir_call_cache[64], &part);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_157$$105, "phalcon/Mvc/Router.zep", 1427);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_158$$104 = Z_TYPE_P(&position) != IS_STRING;
								if (_158$$104) {
									_158$$104 = Z_TYPE_P(&position) != IS_LONG;
								}
								if (_158$$104) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&matchPosition);
								_159$$104 = zephir_array_isset_fetch(&matchPosition, &matches, &position, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_159$$104) {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										_160$$108 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (_160$$108) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_161$$109, &converter, NULL, 0, &matchPosition);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_161$$109, PH_COPY | PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											continue;
										}
									}
									zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									_162$$110 = Z_TYPE_P(&converters) == IS_ARRAY;
									if (_162$$110) {
										ZEPHIR_OBS_NVAR(&converter);
										_163$$110 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										_162$$110 = _163$$110;
									}
									if (_162$$110) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_164$$111, &converter, NULL, 0, &position);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_164$$111, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} else if (Z_TYPE_P(&position) == IS_LONG) {
										zephir_array_unset(&parts, &part, PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _152$$103, "rewind", &_zephir_call_cache[65]);
							zephir_check_call_status();
							_166$$103 = 1;
							while (1) {
								if (_166$$103) {
									_166$$103 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _152$$103, "next", &_zephir_call_cache[66]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_165$$103, _152$$103, "valid", &_zephir_call_cache[67]);
								zephir_check_call_status();
								if (!zend_is_true(&_165$$103)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&part, _152$$103, "key", &_zephir_call_cache[68]);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&position, _152$$103, "current", &_zephir_call_cache[69]);
								zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
										ZEPHIR_INIT_NVAR(&_167$$114);
										object_init_ex(&_167$$114, phalcon_mvc_router_exceptions_wrongpathskey_ce);
										ZEPHIR_CALL_METHOD_CACHED(NULL, &_167$$114, "__construct", &_zephir_call_cache[70], &part);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_167$$114, "phalcon/Mvc/Router.zep", 1427);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_168$$113 = Z_TYPE_P(&position) != IS_STRING;
									if (_168$$113) {
										_168$$113 = Z_TYPE_P(&position) != IS_LONG;
									}
									if (_168$$113) {
										continue;
									}
									ZEPHIR_OBS_NVAR(&matchPosition);
									_169$$113 = zephir_array_isset_fetch(&matchPosition, &matches, &position, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_169$$113) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											_170$$117 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											if (_170$$117) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_171$$118, &converter, NULL, 0, &matchPosition);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_171$$118, PH_COPY | PH_SEPARATE);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												continue;
											}
										}
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} else {
										_172$$119 = Z_TYPE_P(&converters) == IS_ARRAY;
										if (_172$$119) {
											ZEPHIR_OBS_NVAR(&converter);
											_173$$119 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											_172$$119 = _173$$119;
										}
										if (_172$$119) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_174$$120, &converter, NULL, 0, &position);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_174$$120, PH_COPY | PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										} else if (Z_TYPE_P(&position) == IS_LONG) {
											zephir_array_unset(&parts, &part, PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									}
							}
						}
						ZEPHIR_INIT_NVAR(&position);
						ZEPHIR_INIT_NVAR(&part);
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 310, &matches);
					}
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 312, &route);
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _137$$84, "rewind", &_zephir_call_cache[71]);
			zephir_check_call_status();
			_176$$84 = 1;
			while (1) {
				if (_176$$84) {
					_176$$84 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _137$$84, "next", &_zephir_call_cache[72]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_175$$84, _137$$84, "valid", &_zephir_call_cache[73]);
				zephir_check_call_status();
				if (!zend_is_true(&_175$$84)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&routeIdx, _137$$84, "key", &_zephir_call_cache[74]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&route, _137$$84, "current", &_zephir_call_cache[75]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&routeId, &route, "getRouteId", &_zephir_call_cache[76]);
					zephir_check_call_status();
					_177$$122 = zephir_array_isset_value(&vetoedRoutes, &routeId);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_177$$122) {
						continue;
					}
					zephir_read_property_cached(&_178$$122, this_ptr, _zephir_prop_14, 300, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_179$$122);
					zephir_array_fetch(&_179$$122, &_178$$122, &routeId, PH_NOISY, "phalcon/Mvc/Router.zep", 1325);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&routeMeta, &_179$$122);
					ZEPHIR_INIT_NVAR(&params);
					array_init(&params);
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					ZEPHIR_OBS_NVAR(&hostname);
					zephir_array_fetch_string(&hostname, &routeMeta, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1332);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&hostname) != IS_NULL) {
						if (Z_TYPE_P(&currentHostName) == IS_NULL) {
							ZEPHIR_CALL_METHOD_CACHED(&currentHostName, &request, "getHttpHost", &_zephir_call_cache[77]);
							zephir_check_call_status();
						}
						if (!(zephir_is_true(&currentHostName))) {
							continue;
						}
						ZEPHIR_OBS_NVAR(&regexHostName);
						zephir_array_fetch_string(&regexHostName, &routeMeta, SL("hostRegex"), PH_NOISY, "phalcon/Mvc/Router.zep", 1352);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (Z_TYPE_P(&regexHostName) != IS_NULL) {
							ZEPHIR_INIT_NVAR(&_180$$127);
							ZEPHIR_INIT_NVAR(&matched);
							zephir_preg_match(&matched, &regexHostName, &currentHostName, &_180$$127, 0, 0 , 0 );
						} else {
							_181$$128 = ZEPHIR_IS_EQUAL(&currentHostName, &hostname);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&matched);
							ZVAL_BOOL(&matched, _181$$128);
						}
						if (!(zephir_is_true(&matched))) {
							continue;
						}
					}
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_182$$130);
						ZVAL_STRING(&_182$$130, "router:beforeCheckRoute");
						ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[78], &_182$$130, this_ptr, &route);
						zephir_check_call_status();
					}
					ZEPHIR_OBS_NVAR(&pattern);
					zephir_array_fetch_string(&pattern, &routeMeta, SL("pattern"), PH_NOISY, "phalcon/Mvc/Router.zep", 1372);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_179$$122);
					zephir_array_fetch_string(&_179$$122, &routeMeta, SL("isRegex"), PH_NOISY, "phalcon/Mvc/Router.zep", 1374);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_is_true(&_179$$122)) {
						ZEPHIR_INIT_NVAR(&routeFound);
						zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
					} else {
						_183$$132 = ZEPHIR_IS_EQUAL(&pattern, &handledUri);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&routeFound);
						ZVAL_BOOL(&routeFound, _183$$132);
					}
					if (zephir_is_true(&routeFound)) {
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_184$$134);
							ZVAL_STRING(&_184$$134, "router:matchedRoute");
							ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[79], &_184$$134, this_ptr, &route);
							zephir_check_call_status();
						}
						ZEPHIR_OBS_NVAR(&beforeMatch);
						zephir_array_fetch_string(&beforeMatch, &routeMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1388);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
							if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
								ZEPHIR_INIT_NVAR(&_185$$136);
								object_init_ex(&_185$$136, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_185$$136, "__construct", &_zephir_call_cache[80]);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_185$$136, "phalcon/Mvc/Router.zep", 1394);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &beforeMatch, NULL, 0, &handledUri, &route, this_ptr);
							zephir_check_call_status();
						}
					} else {
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_186$$138);
							ZVAL_STRING(&_186$$138, "router:notMatchedRoute");
							ZEPHIR_CALL_METHOD_CACHED(&routeFound, &eventsManager, "fire", &_zephir_call_cache[81], &_186$$138, this_ptr, &route);
							zephir_check_call_status();
						}
					}
					if (zephir_is_true(&routeFound)) {
						ZEPHIR_CALL_METHOD_CACHED(&paths, &route, "getPaths", &_zephir_call_cache[82]);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&parts, &paths);
						if (Z_TYPE_P(&matches) == IS_ARRAY) {
							ZEPHIR_CALL_METHOD_CACHED(&converters, &route, "getConverters", &_zephir_call_cache[83]);
							zephir_check_call_status();
							if (Z_TYPE_P(&paths) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_188$$140);
								zephir_string_to_char_array(&_188$$140, &paths);
								_187$$140 = &_188$$140;
							} else {
								_187$$140 = &paths;
							}
							zephir_is_iterable(_187$$140, 0, "phalcon/Mvc/Router.zep", 1469);
							if (Z_TYPE_P(_187$$140) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_187$$140), _190$$140, _191$$140, _189$$140)
								{
									ZEPHIR_INIT_NVAR(&part);
									if (_191$$140 != NULL) { 
										ZVAL_STR_COPY(&part, _191$$140);
									} else {
										ZVAL_LONG(&part, _190$$140);
									}
									ZEPHIR_INIT_NVAR(&position);
									ZVAL_COPY(&position, _189$$140);
									if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
										ZEPHIR_INIT_NVAR(&_192$$142);
										object_init_ex(&_192$$142, phalcon_mvc_router_exceptions_wrongpathskey_ce);
										ZEPHIR_CALL_METHOD_CACHED(NULL, &_192$$142, "__construct", &_zephir_call_cache[84], &part);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_192$$142, "phalcon/Mvc/Router.zep", 1427);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_193$$141 = Z_TYPE_P(&position) != IS_STRING;
									if (_193$$141) {
										_193$$141 = Z_TYPE_P(&position) != IS_LONG;
									}
									if (_193$$141) {
										continue;
									}
									ZEPHIR_OBS_NVAR(&matchPosition);
									_194$$141 = zephir_array_isset_fetch(&matchPosition, &matches, &position, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_194$$141) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											_195$$145 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											if (_195$$145) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_196$$146, &converter, NULL, 0, &matchPosition);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_196$$146, PH_COPY | PH_SEPARATE);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												continue;
											}
										}
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} else {
										_197$$147 = Z_TYPE_P(&converters) == IS_ARRAY;
										if (_197$$147) {
											ZEPHIR_OBS_NVAR(&converter);
											_198$$147 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											_197$$147 = _198$$147;
										}
										if (_197$$147) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_199$$148, &converter, NULL, 0, &position);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_199$$148, PH_COPY | PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										} else if (Z_TYPE_P(&position) == IS_LONG) {
											zephir_array_unset(&parts, &part, PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _187$$140, "rewind", &_zephir_call_cache[85]);
								zephir_check_call_status();
								_201$$140 = 1;
								while (1) {
									if (_201$$140) {
										_201$$140 = 0;
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _187$$140, "next", &_zephir_call_cache[86]);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD_CACHED(&_200$$140, _187$$140, "valid", &_zephir_call_cache[87]);
									zephir_check_call_status();
									if (!zend_is_true(&_200$$140)) {
										break;
									}
									ZEPHIR_CALL_METHOD_CACHED(&part, _187$$140, "key", &_zephir_call_cache[88]);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD_CACHED(&position, _187$$140, "current", &_zephir_call_cache[89]);
									zephir_check_call_status();
										if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
											ZEPHIR_INIT_NVAR(&_202$$151);
											object_init_ex(&_202$$151, phalcon_mvc_router_exceptions_wrongpathskey_ce);
											ZEPHIR_CALL_METHOD_CACHED(NULL, &_202$$151, "__construct", &_zephir_call_cache[90], &part);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_202$$151, "phalcon/Mvc/Router.zep", 1427);
											ZEPHIR_MM_RESTORE();
											return;
										}
										_203$$150 = Z_TYPE_P(&position) != IS_STRING;
										if (_203$$150) {
											_203$$150 = Z_TYPE_P(&position) != IS_LONG;
										}
										if (_203$$150) {
											continue;
										}
										ZEPHIR_OBS_NVAR(&matchPosition);
										_204$$150 = zephir_array_isset_fetch(&matchPosition, &matches, &position, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (_204$$150) {
											if (Z_TYPE_P(&converters) == IS_ARRAY) {
												ZEPHIR_OBS_NVAR(&converter);
												_205$$154 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												if (_205$$154) {
													ZEPHIR_CALL_ZVAL_FUNCTION(&_206$$155, &converter, NULL, 0, &matchPosition);
													zephir_check_call_status();
													zephir_array_update_zval(&parts, &part, &_206$$155, PH_COPY | PH_SEPARATE);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													continue;
												}
											}
											zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										} else {
											_207$$156 = Z_TYPE_P(&converters) == IS_ARRAY;
											if (_207$$156) {
												ZEPHIR_OBS_NVAR(&converter);
												_208$$156 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												_207$$156 = _208$$156;
											}
											if (_207$$156) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_209$$157, &converter, NULL, 0, &position);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_209$$157, PH_COPY | PH_SEPARATE);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											} else if (Z_TYPE_P(&position) == IS_LONG) {
												zephir_array_unset(&parts, &part, PH_SEPARATE);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											}
										}
								}
							}
							ZEPHIR_INIT_NVAR(&position);
							ZEPHIR_INIT_NVAR(&part);
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 310, &matches);
						}
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 312, &route);
						break;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&route);
		ZEPHIR_INIT_NVAR(&routeIdx);
	}
	if (zephir_is_true(&routeFound)) {
		if (1) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 311, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 311, &__$false);
		}
	} else {
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 311, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 311, &__$false);
		}
	}
	if (!(zephir_is_true(&routeFound))) {
		zephir_read_property_cached(&_210$$161, this_ptr, _zephir_prop_15, 315, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&notFoundPaths, &_210$$161);
		if (Z_TYPE_P(&notFoundPaths) != IS_NULL) {
			ZEPHIR_CALL_CE_STATIC_CACHED(&parts, phalcon_mvc_router_route_ce, "getRoutePaths", &_zephir_call_cache[91], &notFoundPaths);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&routeFound);
			ZVAL_BOOL(&routeFound, 1);
		}
	}
	zephir_read_property_cached(&_211, this_ptr, _zephir_prop_16, 301, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_17, 316, &_211);
	zephir_read_property_cached(&_212, this_ptr, _zephir_prop_18, 302, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_19, 317, &_212);
	zephir_read_property_cached(&_213, this_ptr, _zephir_prop_20, 303, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_21, 318, &_213);
	zephir_read_property_cached(&_214, this_ptr, _zephir_prop_22, 304, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_23, 319, &_214);
	zephir_read_property_cached(&_215, this_ptr, _zephir_prop_24, 305, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_25, 320, &_215);
	if (zephir_is_true(&routeFound)) {
		zephir_memory_observe(&vnamespace);
		_216$$163 = zephir_array_isset_string_fetch(&vnamespace, &parts, SL("namespace"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_216$$163) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_17, 316, &vnamespace);
			zephir_array_unset_string(&parts, SL("namespace"), PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_memory_observe(&module);
		_217$$163 = zephir_array_isset_string_fetch(&module, &parts, SL("module"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_217$$163) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_19, 317, &module);
			zephir_array_unset_string(&parts, SL("module"), PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_memory_observe(&controller);
		_218$$163 = zephir_array_isset_string_fetch(&controller, &parts, SL("controller"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_218$$163) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_21, 318, &controller);
			zephir_array_unset_string(&parts, SL("controller"), PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_memory_observe(&action);
		_219$$163 = zephir_array_isset_string_fetch(&action, &parts, SL("action"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_219$$163) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_23, 319, &action);
			zephir_array_unset_string(&parts, SL("action"), PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_memory_observe(&paramsStr);
		_220$$163 = zephir_array_isset_string_fetch(&paramsStr, &parts, SL("params"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_220$$163) {
			if (Z_TYPE_P(&paramsStr) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_221$$169);
				ZVAL_STRING(&_221$$169, "/");
				ZEPHIR_INIT_VAR(&strParams);
				zephir_fast_trim(&strParams, &paramsStr, &_221$$169, ZEPHIR_TRIM_BOTH);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&strParams, "")) {
					ZEPHIR_INIT_NVAR(&params);
					zephir_fast_explode_str(&params, SL("/"), &strParams, NULL);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			zephir_array_unset_string(&parts, SL("params"), PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (!(ZEPHIR_IS_EMPTY(&params))) {
			ZEPHIR_INIT_VAR(&_222$$171);
			zephir_fast_array_merge(&_222$$171, &params, &parts);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_25, 320, &_222$$171);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_25, 320, &parts);
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_223$$173);
		ZVAL_STRING(&_223$$173, "router:afterCheckRoutes");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[92], &_223$$173, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_224, this_ptr, _zephir_prop_26, 321, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_224) != IS_NULL) {
		zephir_read_property_cached(&_225$$174, this_ptr, _zephir_prop_26, 321, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_226$$174, this_ptr, _zephir_prop_27, 322, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_227$$174, this_ptr, "buildDispatcherDump", &_zephir_call_cache[93]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_225$$174, "set", &_zephir_call_cache[94], &_226$$174, &_227$$174);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_26, 321, &__$null);
		ZEPHIR_INIT_VAR(&_228$$174);
		ZEPHIR_INIT_NVAR(&_228$$174);
		ZVAL_STRING(&_228$$174, "");
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_27, 322, &_228$$174);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "phpFileExists", &_zephir_call_cache[0], &path_zv);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Router cache not found: ", &path_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[1], &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Router.zep", 1598);
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$4, "__construct", &_zephir_call_cache[2], &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Mvc/Router.zep", 1606);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "loadDispatcherFromArray", &_zephir_call_cache[3], &dump);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Inverse of buildDispatcherDump(). Reconstructs every Route from the
 * scalar `routes` entries (preserving subclass and routeId), restores
 * every index, and marks the indexes clean so handle() skips rebuild.
 *
 * @throws \Phalcon\Mvc\Router\Exception
 *
 * @phpstan-param array<string, mixed> $dump
 */
PHP_METHOD(Phalcon_Mvc_Router, loadDispatcherFromArray)
{
	zend_class_entry *_11$$6, *_30$$13;
	zval _4$$4;
	zend_string *_51, *_77, *_103, *_24$$10, *_43$$17, *_109$$32, *_137$$39;
	zend_ulong _50, _76, _102, _23$$10, _42$$17, _108$$32, _136$$39;
	zend_bool _0, _5, _28, _62, _88, _131, _26$$10, _45$$17, _58$$20, _69$$23, _84$$26, _95$$29, _120$$32, _116$$33, _127$$36, _148$$39, _144$$40, _155$$43;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, dumpVersion = 0;
	zval *dump_param = NULL, __$true, __$false, routeData, route, routeClass, beforeMatch, converters, convName, converter, rebuiltRoutes, methodRoutesRehydrated, candidatesRehydrated, staticRehydrated, innerKey, innerVal, scalarIdx, scalarSubKey, mostInnerVal, mostInnerArr, _1, _6, *_7, _8, *_9, _27, _46, *_47, _48, *_49, _61, _72, *_73, _74, *_75, _87, _98, *_99, _100, *_101, _130, _158, _159, _160, _161, _162, _163, _164, _165, _166, _2$$4, _3$$4, _10$$6, _12$$6, _13$$6, _14$$6, _15$$6, _17$$6, _19$$6, _16$$7, _18$$8, *_20$$10, _21$$10, *_22$$10, _25$$10, _29$$13, _31$$13, _32$$13, _33$$13, _34$$13, _36$$13, _38$$13, _35$$14, _37$$15, *_39$$17, _40$$17, *_41$$17, _44$$17, *_52$$20, _53$$20, *_54$$20, _57$$20, _55$$21, _56$$21, _59$$22, _60$$22, *_63$$23, _64$$23, *_65$$23, _68$$23, _66$$24, _67$$24, _70$$25, _71$$25, *_78$$26, _79$$26, *_80$$26, _83$$26, _81$$27, _82$$27, _85$$28, _86$$28, *_89$$29, _90$$29, *_91$$29, _94$$29, _92$$30, _93$$30, _96$$31, _97$$31, _104$$32, *_105$$32, _106$$32, *_107$$32, _119$$32, *_110$$33, _111$$33, *_112$$33, _115$$33, _113$$34, _114$$34, _117$$35, _118$$35, *_121$$36, _122$$36, *_123$$36, _126$$36, _124$$37, _125$$37, _128$$38, _129$$38, _132$$39, *_133$$39, _134$$39, *_135$$39, _147$$39, *_138$$40, _139$$40, *_140$$40, _143$$40, _141$$41, _142$$41, _145$$42, _146$$42, *_149$$43, _150$$43, *_151$$43, _154$$43, _152$$44, _153$$44, _156$$45, _157$$45;
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_61);
	ZVAL_UNDEF(&_72);
	ZVAL_UNDEF(&_74);
	ZVAL_UNDEF(&_87);
	ZVAL_UNDEF(&_98);
	ZVAL_UNDEF(&_100);
	ZVAL_UNDEF(&_130);
	ZVAL_UNDEF(&_158);
	ZVAL_UNDEF(&_159);
	ZVAL_UNDEF(&_160);
	ZVAL_UNDEF(&_161);
	ZVAL_UNDEF(&_162);
	ZVAL_UNDEF(&_163);
	ZVAL_UNDEF(&_164);
	ZVAL_UNDEF(&_165);
	ZVAL_UNDEF(&_166);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_38$$13);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_37$$15);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_53$$20);
	ZVAL_UNDEF(&_57$$20);
	ZVAL_UNDEF(&_55$$21);
	ZVAL_UNDEF(&_56$$21);
	ZVAL_UNDEF(&_59$$22);
	ZVAL_UNDEF(&_60$$22);
	ZVAL_UNDEF(&_64$$23);
	ZVAL_UNDEF(&_68$$23);
	ZVAL_UNDEF(&_66$$24);
	ZVAL_UNDEF(&_67$$24);
	ZVAL_UNDEF(&_70$$25);
	ZVAL_UNDEF(&_71$$25);
	ZVAL_UNDEF(&_79$$26);
	ZVAL_UNDEF(&_83$$26);
	ZVAL_UNDEF(&_81$$27);
	ZVAL_UNDEF(&_82$$27);
	ZVAL_UNDEF(&_85$$28);
	ZVAL_UNDEF(&_86$$28);
	ZVAL_UNDEF(&_90$$29);
	ZVAL_UNDEF(&_94$$29);
	ZVAL_UNDEF(&_92$$30);
	ZVAL_UNDEF(&_93$$30);
	ZVAL_UNDEF(&_96$$31);
	ZVAL_UNDEF(&_97$$31);
	ZVAL_UNDEF(&_104$$32);
	ZVAL_UNDEF(&_106$$32);
	ZVAL_UNDEF(&_119$$32);
	ZVAL_UNDEF(&_111$$33);
	ZVAL_UNDEF(&_115$$33);
	ZVAL_UNDEF(&_113$$34);
	ZVAL_UNDEF(&_114$$34);
	ZVAL_UNDEF(&_117$$35);
	ZVAL_UNDEF(&_118$$35);
	ZVAL_UNDEF(&_122$$36);
	ZVAL_UNDEF(&_126$$36);
	ZVAL_UNDEF(&_124$$37);
	ZVAL_UNDEF(&_125$$37);
	ZVAL_UNDEF(&_128$$38);
	ZVAL_UNDEF(&_129$$38);
	ZVAL_UNDEF(&_132$$39);
	ZVAL_UNDEF(&_134$$39);
	ZVAL_UNDEF(&_147$$39);
	ZVAL_UNDEF(&_139$$40);
	ZVAL_UNDEF(&_143$$40);
	ZVAL_UNDEF(&_141$$41);
	ZVAL_UNDEF(&_142$$41);
	ZVAL_UNDEF(&_145$$42);
	ZVAL_UNDEF(&_146$$42);
	ZVAL_UNDEF(&_150$$43);
	ZVAL_UNDEF(&_154$$43);
	ZVAL_UNDEF(&_152$$44);
	ZVAL_UNDEF(&_153$$44);
	ZVAL_UNDEF(&_156$$45);
	ZVAL_UNDEF(&_157$$45);
	ZVAL_UNDEF(&_4$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[86];
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
	_0 = zephir_array_isset_value_string(&dump, SL("version"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Router cache is missing 'version' field", "phalcon/Mvc/Router.zep", 1630);
		return;
	}
	zephir_memory_observe(&_1);
	zephir_array_fetch_string(&_1, &dump, SL("version"), PH_NOISY, "phalcon/Mvc/Router.zep", 1633);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	dumpVersion = zephir_get_intval(&_1);
	if (dumpVersion != 1) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_LONG(&_3$$4, dumpVersion);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CONCAT_SVS(&_4$$4, "Router cache version ", &_3$$4, " is not supported (this build supports version 1)");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$4, "__construct", &_zephir_call_cache[0], &_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Router.zep", 1638);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = zephir_array_isset_value_string(&dump, SL("routes"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_5)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Router cache is missing 'routes' field", "phalcon/Mvc/Router.zep", 1642);
		return;
	}
	ZEPHIR_INIT_VAR(&rebuiltRoutes);
	array_init(&rebuiltRoutes);
	zephir_array_fetch_string(&_6, &dump, SL("routes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1647);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_6) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_8);
		zephir_string_to_char_array(&_8, &_6);
		_7 = &_8;
	} else {
		_7 = &_6;
	}
	zephir_is_iterable(_7, 0, "phalcon/Mvc/Router.zep", 1676);
	if (Z_TYPE_P(_7) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_7), _9)
		{
			ZEPHIR_INIT_NVAR(&routeData);
			ZVAL_COPY(&routeData, _9);
			ZEPHIR_OBS_NVAR(&routeClass);
			zephir_array_fetch_string(&routeClass, &routeData, SL("class"), PH_NOISY, "phalcon/Mvc/Router.zep", 1648);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&route);
			zephir_fetch_safe_class(&_10$$6, &routeClass);
			_11$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_10$$6), Z_STRLEN_P(&_10$$6), ZEND_FETCH_CLASS_AUTO);
			if(!_11$$6) {
				RETURN_MM_NULL();
			}
			object_init_ex(&route, _11$$6);
			ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&route);
			zephir_check_call_status();
			if (zephir_has_constructor(&route)) {
				ZEPHIR_OBS_NVAR(&_12$$6);
				zephir_array_fetch_string(&_12$$6, &routeData, SL("pattern"), PH_NOISY, "phalcon/Mvc/Router.zep", 1649);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_13$$6);
				zephir_array_fetch_string(&_13$$6, &routeData, SL("paths"), PH_NOISY, "phalcon/Mvc/Router.zep", 1649);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_14$$6);
				zephir_array_fetch_string(&_14$$6, &routeData, SL("methods"), PH_NOISY, "phalcon/Mvc/Router.zep", 1649);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "__construct", &_zephir_call_cache[1], &_12$$6, &_13$$6, &_14$$6);
				zephir_check_call_status();
			}

			ZEPHIR_OBS_NVAR(&_15$$6);
			zephir_array_fetch_string(&_15$$6, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1651);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&_15$$6) != IS_NULL) {
				ZEPHIR_OBS_NVAR(&_16$$7);
				zephir_array_fetch_string(&_16$$7, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1652);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "setHostname", &_zephir_call_cache[2], &_16$$7);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&_17$$6);
			zephir_array_fetch_string(&_17$$6, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 1655);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&_17$$6) != IS_NULL) {
				ZEPHIR_OBS_NVAR(&_18$$8);
				zephir_array_fetch_string(&_18$$8, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 1656);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "setName", &_zephir_call_cache[3], &_18$$8);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&_19$$6);
			zephir_array_fetch_string(&_19$$6, &routeData, SL("id"), PH_NOISY, "phalcon/Mvc/Router.zep", 1659);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "setRouteId", &_zephir_call_cache[4], &_19$$6);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&beforeMatch);
			zephir_array_fetch_string(&beforeMatch, &routeData, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1661);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "beforeMatch", &_zephir_call_cache[5], &beforeMatch);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&converters);
			zephir_array_fetch_string(&converters, &routeData, SL("converters"), PH_NOISY, "phalcon/Mvc/Router.zep", 1666);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&converters) == IS_ARRAY) {
				if (Z_TYPE_P(&converters) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_21$$10);
					zephir_string_to_char_array(&_21$$10, &converters);
					_20$$10 = &_21$$10;
				} else {
					_20$$10 = &converters;
				}
				zephir_is_iterable(_20$$10, 0, "phalcon/Mvc/Router.zep", 1671);
				if (Z_TYPE_P(_20$$10) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_20$$10), _23$$10, _24$$10, _22$$10)
					{
						ZEPHIR_INIT_NVAR(&convName);
						if (_24$$10 != NULL) { 
							ZVAL_STR_COPY(&convName, _24$$10);
						} else {
							ZVAL_LONG(&convName, _23$$10);
						}
						ZEPHIR_INIT_NVAR(&converter);
						ZVAL_COPY(&converter, _22$$10);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "convert", &_zephir_call_cache[6], &convName, &converter);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _20$$10, "rewind", &_zephir_call_cache[7]);
					zephir_check_call_status();
					_26$$10 = 1;
					while (1) {
						if (_26$$10) {
							_26$$10 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _20$$10, "next", &_zephir_call_cache[8]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_25$$10, _20$$10, "valid", &_zephir_call_cache[9]);
						zephir_check_call_status();
						if (!zend_is_true(&_25$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&convName, _20$$10, "key", &_zephir_call_cache[10]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&converter, _20$$10, "current", &_zephir_call_cache[11]);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "convert", &_zephir_call_cache[12], &convName, &converter);
							zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&converter);
				ZEPHIR_INIT_NVAR(&convName);
			}
			zephir_array_append(&rebuiltRoutes, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1673);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _7, "rewind", &_zephir_call_cache[13]);
		zephir_check_call_status();
		_28 = 1;
		while (1) {
			if (_28) {
				_28 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _7, "next", &_zephir_call_cache[14]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_27, _7, "valid", &_zephir_call_cache[15]);
			zephir_check_call_status();
			if (!zend_is_true(&_27)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&routeData, _7, "current", &_zephir_call_cache[16]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&routeClass);
				zephir_array_fetch_string(&routeClass, &routeData, SL("class"), PH_NOISY, "phalcon/Mvc/Router.zep", 1648);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&route);
				zephir_fetch_safe_class(&_29$$13, &routeClass);
				_30$$13 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_29$$13), Z_STRLEN_P(&_29$$13), ZEND_FETCH_CLASS_AUTO);
				if(!_30$$13) {
					RETURN_MM_NULL();
				}
				object_init_ex(&route, _30$$13);
				ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&route);
				zephir_check_call_status();
				if (zephir_has_constructor(&route)) {
					ZEPHIR_OBS_NVAR(&_31$$13);
					zephir_array_fetch_string(&_31$$13, &routeData, SL("pattern"), PH_NOISY, "phalcon/Mvc/Router.zep", 1649);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_32$$13);
					zephir_array_fetch_string(&_32$$13, &routeData, SL("paths"), PH_NOISY, "phalcon/Mvc/Router.zep", 1649);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_33$$13);
					zephir_array_fetch_string(&_33$$13, &routeData, SL("methods"), PH_NOISY, "phalcon/Mvc/Router.zep", 1649);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "__construct", &_zephir_call_cache[17], &_31$$13, &_32$$13, &_33$$13);
					zephir_check_call_status();
				}

				ZEPHIR_OBS_NVAR(&_34$$13);
				zephir_array_fetch_string(&_34$$13, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1651);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&_34$$13) != IS_NULL) {
					ZEPHIR_OBS_NVAR(&_35$$14);
					zephir_array_fetch_string(&_35$$14, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1652);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "setHostname", &_zephir_call_cache[18], &_35$$14);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&_36$$13);
				zephir_array_fetch_string(&_36$$13, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 1655);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&_36$$13) != IS_NULL) {
					ZEPHIR_OBS_NVAR(&_37$$15);
					zephir_array_fetch_string(&_37$$15, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 1656);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "setName", &_zephir_call_cache[19], &_37$$15);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&_38$$13);
				zephir_array_fetch_string(&_38$$13, &routeData, SL("id"), PH_NOISY, "phalcon/Mvc/Router.zep", 1659);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "setRouteId", &_zephir_call_cache[20], &_38$$13);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&beforeMatch);
				zephir_array_fetch_string(&beforeMatch, &routeData, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1661);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "beforeMatch", &_zephir_call_cache[21], &beforeMatch);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&converters);
				zephir_array_fetch_string(&converters, &routeData, SL("converters"), PH_NOISY, "phalcon/Mvc/Router.zep", 1666);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&converters) == IS_ARRAY) {
					if (Z_TYPE_P(&converters) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_40$$17);
						zephir_string_to_char_array(&_40$$17, &converters);
						_39$$17 = &_40$$17;
					} else {
						_39$$17 = &converters;
					}
					zephir_is_iterable(_39$$17, 0, "phalcon/Mvc/Router.zep", 1671);
					if (Z_TYPE_P(_39$$17) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_39$$17), _42$$17, _43$$17, _41$$17)
						{
							ZEPHIR_INIT_NVAR(&convName);
							if (_43$$17 != NULL) { 
								ZVAL_STR_COPY(&convName, _43$$17);
							} else {
								ZVAL_LONG(&convName, _42$$17);
							}
							ZEPHIR_INIT_NVAR(&converter);
							ZVAL_COPY(&converter, _41$$17);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "convert", &_zephir_call_cache[22], &convName, &converter);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _39$$17, "rewind", &_zephir_call_cache[23]);
						zephir_check_call_status();
						_45$$17 = 1;
						while (1) {
							if (_45$$17) {
								_45$$17 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _39$$17, "next", &_zephir_call_cache[24]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_44$$17, _39$$17, "valid", &_zephir_call_cache[25]);
							zephir_check_call_status();
							if (!zend_is_true(&_44$$17)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&convName, _39$$17, "key", &_zephir_call_cache[26]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&converter, _39$$17, "current", &_zephir_call_cache[27]);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "convert", &_zephir_call_cache[28], &convName, &converter);
								zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&converter);
					ZEPHIR_INIT_NVAR(&convName);
				}
				zephir_array_append(&rebuiltRoutes, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1673);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&routeData);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 289, &rebuiltRoutes);
	ZEPHIR_INIT_VAR(&methodRoutesRehydrated);
	array_init(&methodRoutesRehydrated);
	zephir_array_fetch_string(&_46, &dump, SL("methodRoutes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1679);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_46) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_48);
		zephir_string_to_char_array(&_48, &_46);
		_47 = &_48;
	} else {
		_47 = &_46;
	}
	zephir_is_iterable(_47, 0, "phalcon/Mvc/Router.zep", 1687);
	if (Z_TYPE_P(_47) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_47), _50, _51, _49)
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
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_53$$20);
				zephir_string_to_char_array(&_53$$20, &innerVal);
				_52$$20 = &_53$$20;
			} else {
				_52$$20 = &innerVal;
			}
			zephir_is_iterable(_52$$20, 0, "phalcon/Mvc/Router.zep", 1684);
			if (Z_TYPE_P(_52$$20) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_52$$20), _54$$20)
				{
					ZEPHIR_INIT_NVAR(&scalarIdx);
					ZVAL_COPY(&scalarIdx, _54$$20);
					zephir_read_property_cached(&_55$$21, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_56$$21);
					zephir_array_fetch(&_56$$21, &_55$$21, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1682);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&mostInnerArr, &_56$$21, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1682);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _52$$20, "rewind", &_zephir_call_cache[29]);
				zephir_check_call_status();
				_58$$20 = 1;
				while (1) {
					if (_58$$20) {
						_58$$20 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _52$$20, "next", &_zephir_call_cache[30]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_57$$20, _52$$20, "valid", &_zephir_call_cache[31]);
					zephir_check_call_status();
					if (!zend_is_true(&_57$$20)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&scalarIdx, _52$$20, "current", &_zephir_call_cache[32]);
					zephir_check_call_status();
						zephir_read_property_cached(&_59$$22, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&_60$$22);
						zephir_array_fetch(&_60$$22, &_59$$22, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1682);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_60$$22, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1682);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&scalarIdx);
			zephir_array_update_zval(&methodRoutesRehydrated, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _47, "rewind", &_zephir_call_cache[33]);
		zephir_check_call_status();
		_62 = 1;
		while (1) {
			if (_62) {
				_62 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _47, "next", &_zephir_call_cache[34]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_61, _47, "valid", &_zephir_call_cache[35]);
			zephir_check_call_status();
			if (!zend_is_true(&_61)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&innerKey, _47, "key", &_zephir_call_cache[36]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&innerVal, _47, "current", &_zephir_call_cache[37]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_64$$23);
					zephir_string_to_char_array(&_64$$23, &innerVal);
					_63$$23 = &_64$$23;
				} else {
					_63$$23 = &innerVal;
				}
				zephir_is_iterable(_63$$23, 0, "phalcon/Mvc/Router.zep", 1684);
				if (Z_TYPE_P(_63$$23) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_63$$23), _65$$23)
					{
						ZEPHIR_INIT_NVAR(&scalarIdx);
						ZVAL_COPY(&scalarIdx, _65$$23);
						zephir_read_property_cached(&_66$$24, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&_67$$24);
						zephir_array_fetch(&_67$$24, &_66$$24, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1682);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_67$$24, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1682);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _63$$23, "rewind", &_zephir_call_cache[38]);
					zephir_check_call_status();
					_69$$23 = 1;
					while (1) {
						if (_69$$23) {
							_69$$23 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _63$$23, "next", &_zephir_call_cache[39]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_68$$23, _63$$23, "valid", &_zephir_call_cache[40]);
						zephir_check_call_status();
						if (!zend_is_true(&_68$$23)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&scalarIdx, _63$$23, "current", &_zephir_call_cache[41]);
						zephir_check_call_status();
							zephir_read_property_cached(&_70$$25, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_71$$25);
							zephir_array_fetch(&_71$$25, &_70$$25, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1682);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&mostInnerArr, &_71$$25, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1682);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&scalarIdx);
				zephir_array_update_zval(&methodRoutesRehydrated, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	ZEPHIR_INIT_VAR(&candidatesRehydrated);
	array_init(&candidatesRehydrated);
	zephir_array_fetch_string(&_72, &dump, SL("candidatesByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1688);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_72) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_74);
		zephir_string_to_char_array(&_74, &_72);
		_73 = &_74;
	} else {
		_73 = &_72;
	}
	zephir_is_iterable(_73, 0, "phalcon/Mvc/Router.zep", 1696);
	if (Z_TYPE_P(_73) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_73), _76, _77, _75)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_77 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _77);
			} else {
				ZVAL_LONG(&innerKey, _76);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _75);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_79$$26);
				zephir_string_to_char_array(&_79$$26, &innerVal);
				_78$$26 = &_79$$26;
			} else {
				_78$$26 = &innerVal;
			}
			zephir_is_iterable(_78$$26, 0, "phalcon/Mvc/Router.zep", 1693);
			if (Z_TYPE_P(_78$$26) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_78$$26), _80$$26)
				{
					ZEPHIR_INIT_NVAR(&scalarIdx);
					ZVAL_COPY(&scalarIdx, _80$$26);
					zephir_read_property_cached(&_81$$27, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_82$$27);
					zephir_array_fetch(&_82$$27, &_81$$27, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1691);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&mostInnerArr, &_82$$27, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1691);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _78$$26, "rewind", &_zephir_call_cache[42]);
				zephir_check_call_status();
				_84$$26 = 1;
				while (1) {
					if (_84$$26) {
						_84$$26 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _78$$26, "next", &_zephir_call_cache[43]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_83$$26, _78$$26, "valid", &_zephir_call_cache[44]);
					zephir_check_call_status();
					if (!zend_is_true(&_83$$26)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&scalarIdx, _78$$26, "current", &_zephir_call_cache[45]);
					zephir_check_call_status();
						zephir_read_property_cached(&_85$$28, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&_86$$28);
						zephir_array_fetch(&_86$$28, &_85$$28, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1691);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_86$$28, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1691);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&scalarIdx);
			zephir_array_update_zval(&candidatesRehydrated, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _73, "rewind", &_zephir_call_cache[46]);
		zephir_check_call_status();
		_88 = 1;
		while (1) {
			if (_88) {
				_88 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _73, "next", &_zephir_call_cache[47]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_87, _73, "valid", &_zephir_call_cache[48]);
			zephir_check_call_status();
			if (!zend_is_true(&_87)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&innerKey, _73, "key", &_zephir_call_cache[49]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&innerVal, _73, "current", &_zephir_call_cache[50]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_90$$29);
					zephir_string_to_char_array(&_90$$29, &innerVal);
					_89$$29 = &_90$$29;
				} else {
					_89$$29 = &innerVal;
				}
				zephir_is_iterable(_89$$29, 0, "phalcon/Mvc/Router.zep", 1693);
				if (Z_TYPE_P(_89$$29) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_89$$29), _91$$29)
					{
						ZEPHIR_INIT_NVAR(&scalarIdx);
						ZVAL_COPY(&scalarIdx, _91$$29);
						zephir_read_property_cached(&_92$$30, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&_93$$30);
						zephir_array_fetch(&_93$$30, &_92$$30, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1691);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_93$$30, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1691);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _89$$29, "rewind", &_zephir_call_cache[51]);
					zephir_check_call_status();
					_95$$29 = 1;
					while (1) {
						if (_95$$29) {
							_95$$29 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _89$$29, "next", &_zephir_call_cache[52]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_94$$29, _89$$29, "valid", &_zephir_call_cache[53]);
						zephir_check_call_status();
						if (!zend_is_true(&_94$$29)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&scalarIdx, _89$$29, "current", &_zephir_call_cache[54]);
						zephir_check_call_status();
							zephir_read_property_cached(&_96$$31, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_97$$31);
							zephir_array_fetch(&_97$$31, &_96$$31, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1691);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&mostInnerArr, &_97$$31, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1691);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&scalarIdx);
				zephir_array_update_zval(&candidatesRehydrated, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	ZEPHIR_INIT_VAR(&staticRehydrated);
	array_init(&staticRehydrated);
	zephir_array_fetch_string(&_98, &dump, SL("staticByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1697);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_98) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_100);
		zephir_string_to_char_array(&_100, &_98);
		_99 = &_100;
	} else {
		_99 = &_98;
	}
	zephir_is_iterable(_99, 0, "phalcon/Mvc/Router.zep", 1708);
	if (Z_TYPE_P(_99) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_99), _102, _103, _101)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_103 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _103);
			} else {
				ZVAL_LONG(&innerKey, _102);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _101);
			ZEPHIR_INIT_NVAR(&_104$$32);
			array_init(&_104$$32);
			zephir_array_update_zval(&staticRehydrated, &innerKey, &_104$$32, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_106$$32);
				zephir_string_to_char_array(&_106$$32, &innerVal);
				_105$$32 = &_106$$32;
			} else {
				_105$$32 = &innerVal;
			}
			zephir_is_iterable(_105$$32, 0, "phalcon/Mvc/Router.zep", 1706);
			if (Z_TYPE_P(_105$$32) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_105$$32), _108$$32, _109$$32, _107$$32)
				{
					ZEPHIR_INIT_NVAR(&scalarSubKey);
					if (_109$$32 != NULL) { 
						ZVAL_STR_COPY(&scalarSubKey, _109$$32);
					} else {
						ZVAL_LONG(&scalarSubKey, _108$$32);
					}
					ZEPHIR_INIT_NVAR(&mostInnerVal);
					ZVAL_COPY(&mostInnerVal, _107$$32);
					ZEPHIR_INIT_NVAR(&mostInnerArr);
					array_init(&mostInnerArr);
					if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_111$$33);
						zephir_string_to_char_array(&_111$$33, &mostInnerVal);
						_110$$33 = &_111$$33;
					} else {
						_110$$33 = &mostInnerVal;
					}
					zephir_is_iterable(_110$$33, 0, "phalcon/Mvc/Router.zep", 1704);
					if (Z_TYPE_P(_110$$33) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_110$$33), _112$$33)
						{
							ZEPHIR_INIT_NVAR(&scalarIdx);
							ZVAL_COPY(&scalarIdx, _112$$33);
							zephir_read_property_cached(&_113$$34, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_114$$34);
							zephir_array_fetch(&_114$$34, &_113$$34, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&mostInnerArr, &_114$$34, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _110$$33, "rewind", &_zephir_call_cache[55]);
						zephir_check_call_status();
						_116$$33 = 1;
						while (1) {
							if (_116$$33) {
								_116$$33 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _110$$33, "next", &_zephir_call_cache[56]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_115$$33, _110$$33, "valid", &_zephir_call_cache[57]);
							zephir_check_call_status();
							if (!zend_is_true(&_115$$33)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&scalarIdx, _110$$33, "current", &_zephir_call_cache[58]);
							zephir_check_call_status();
								zephir_read_property_cached(&_117$$35, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_118$$35);
								zephir_array_fetch(&_118$$35, &_117$$35, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&mostInnerArr, &_118$$35, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&scalarIdx);
					zephir_array_update_multi(&staticRehydrated, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _105$$32, "rewind", &_zephir_call_cache[59]);
				zephir_check_call_status();
				_120$$32 = 1;
				while (1) {
					if (_120$$32) {
						_120$$32 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _105$$32, "next", &_zephir_call_cache[60]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_119$$32, _105$$32, "valid", &_zephir_call_cache[61]);
					zephir_check_call_status();
					if (!zend_is_true(&_119$$32)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&scalarSubKey, _105$$32, "key", &_zephir_call_cache[62]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&mostInnerVal, _105$$32, "current", &_zephir_call_cache[63]);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_122$$36);
							zephir_string_to_char_array(&_122$$36, &mostInnerVal);
							_121$$36 = &_122$$36;
						} else {
							_121$$36 = &mostInnerVal;
						}
						zephir_is_iterable(_121$$36, 0, "phalcon/Mvc/Router.zep", 1704);
						if (Z_TYPE_P(_121$$36) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_121$$36), _123$$36)
							{
								ZEPHIR_INIT_NVAR(&scalarIdx);
								ZVAL_COPY(&scalarIdx, _123$$36);
								zephir_read_property_cached(&_124$$37, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_125$$37);
								zephir_array_fetch(&_125$$37, &_124$$37, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&mostInnerArr, &_125$$37, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _121$$36, "rewind", &_zephir_call_cache[64]);
							zephir_check_call_status();
							_127$$36 = 1;
							while (1) {
								if (_127$$36) {
									_127$$36 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _121$$36, "next", &_zephir_call_cache[65]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_126$$36, _121$$36, "valid", &_zephir_call_cache[66]);
								zephir_check_call_status();
								if (!zend_is_true(&_126$$36)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&scalarIdx, _121$$36, "current", &_zephir_call_cache[67]);
								zephir_check_call_status();
									zephir_read_property_cached(&_128$$38, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&_129$$38);
									zephir_array_fetch(&_129$$38, &_128$$38, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&mostInnerArr, &_129$$38, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
							}
						}
						ZEPHIR_INIT_NVAR(&scalarIdx);
						zephir_array_update_multi(&staticRehydrated, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&mostInnerVal);
			ZEPHIR_INIT_NVAR(&scalarSubKey);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _99, "rewind", &_zephir_call_cache[68]);
		zephir_check_call_status();
		_131 = 1;
		while (1) {
			if (_131) {
				_131 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _99, "next", &_zephir_call_cache[69]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_130, _99, "valid", &_zephir_call_cache[70]);
			zephir_check_call_status();
			if (!zend_is_true(&_130)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&innerKey, _99, "key", &_zephir_call_cache[71]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&innerVal, _99, "current", &_zephir_call_cache[72]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_132$$39);
				array_init(&_132$$39);
				zephir_array_update_zval(&staticRehydrated, &innerKey, &_132$$39, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_134$$39);
					zephir_string_to_char_array(&_134$$39, &innerVal);
					_133$$39 = &_134$$39;
				} else {
					_133$$39 = &innerVal;
				}
				zephir_is_iterable(_133$$39, 0, "phalcon/Mvc/Router.zep", 1706);
				if (Z_TYPE_P(_133$$39) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_133$$39), _136$$39, _137$$39, _135$$39)
					{
						ZEPHIR_INIT_NVAR(&scalarSubKey);
						if (_137$$39 != NULL) { 
							ZVAL_STR_COPY(&scalarSubKey, _137$$39);
						} else {
							ZVAL_LONG(&scalarSubKey, _136$$39);
						}
						ZEPHIR_INIT_NVAR(&mostInnerVal);
						ZVAL_COPY(&mostInnerVal, _135$$39);
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_139$$40);
							zephir_string_to_char_array(&_139$$40, &mostInnerVal);
							_138$$40 = &_139$$40;
						} else {
							_138$$40 = &mostInnerVal;
						}
						zephir_is_iterable(_138$$40, 0, "phalcon/Mvc/Router.zep", 1704);
						if (Z_TYPE_P(_138$$40) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_138$$40), _140$$40)
							{
								ZEPHIR_INIT_NVAR(&scalarIdx);
								ZVAL_COPY(&scalarIdx, _140$$40);
								zephir_read_property_cached(&_141$$41, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_142$$41);
								zephir_array_fetch(&_142$$41, &_141$$41, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&mostInnerArr, &_142$$41, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _138$$40, "rewind", &_zephir_call_cache[73]);
							zephir_check_call_status();
							_144$$40 = 1;
							while (1) {
								if (_144$$40) {
									_144$$40 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _138$$40, "next", &_zephir_call_cache[74]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_143$$40, _138$$40, "valid", &_zephir_call_cache[75]);
								zephir_check_call_status();
								if (!zend_is_true(&_143$$40)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&scalarIdx, _138$$40, "current", &_zephir_call_cache[76]);
								zephir_check_call_status();
									zephir_read_property_cached(&_145$$42, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&_146$$42);
									zephir_array_fetch(&_146$$42, &_145$$42, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&mostInnerArr, &_146$$42, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
							}
						}
						ZEPHIR_INIT_NVAR(&scalarIdx);
						zephir_array_update_multi(&staticRehydrated, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _133$$39, "rewind", &_zephir_call_cache[77]);
					zephir_check_call_status();
					_148$$39 = 1;
					while (1) {
						if (_148$$39) {
							_148$$39 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _133$$39, "next", &_zephir_call_cache[78]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_147$$39, _133$$39, "valid", &_zephir_call_cache[79]);
						zephir_check_call_status();
						if (!zend_is_true(&_147$$39)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&scalarSubKey, _133$$39, "key", &_zephir_call_cache[80]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&mostInnerVal, _133$$39, "current", &_zephir_call_cache[81]);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&mostInnerArr);
							array_init(&mostInnerArr);
							if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_150$$43);
								zephir_string_to_char_array(&_150$$43, &mostInnerVal);
								_149$$43 = &_150$$43;
							} else {
								_149$$43 = &mostInnerVal;
							}
							zephir_is_iterable(_149$$43, 0, "phalcon/Mvc/Router.zep", 1704);
							if (Z_TYPE_P(_149$$43) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_149$$43), _151$$43)
								{
									ZEPHIR_INIT_NVAR(&scalarIdx);
									ZVAL_COPY(&scalarIdx, _151$$43);
									zephir_read_property_cached(&_152$$44, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&_153$$44);
									zephir_array_fetch(&_153$$44, &_152$$44, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&mostInnerArr, &_153$$44, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _149$$43, "rewind", &_zephir_call_cache[82]);
								zephir_check_call_status();
								_155$$43 = 1;
								while (1) {
									if (_155$$43) {
										_155$$43 = 0;
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _149$$43, "next", &_zephir_call_cache[83]);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD_CACHED(&_154$$43, _149$$43, "valid", &_zephir_call_cache[84]);
									zephir_check_call_status();
									if (!zend_is_true(&_154$$43)) {
										break;
									}
									ZEPHIR_CALL_METHOD_CACHED(&scalarIdx, _149$$43, "current", &_zephir_call_cache[85]);
									zephir_check_call_status();
										zephir_read_property_cached(&_156$$45, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_OBS_NVAR(&_157$$45);
										zephir_array_fetch(&_157$$45, &_156$$45, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&mostInnerArr, &_157$$45, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
								}
							}
							ZEPHIR_INIT_NVAR(&scalarIdx);
							zephir_array_update_multi(&staticRehydrated, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&mostInnerVal);
				ZEPHIR_INIT_NVAR(&scalarSubKey);
		}
	}
	ZEPHIR_INIT_NVAR(&innerVal);
	ZEPHIR_INIT_NVAR(&innerKey);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 291, &methodRoutesRehydrated);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 292, &candidatesRehydrated);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 293, &staticRehydrated);
	zephir_array_fetch_string(&_158, &dump, SL("staticShadowedByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1711);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 294, &_158);
	zephir_array_fetch_string(&_159, &dump, SL("hostnameByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1712);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 295, &_159);
	zephir_array_fetch_string(&_160, &dump, SL("hostnameLessByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1713);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 296, &_160);
	zephir_array_fetch_string(&_161, &dump, SL("combinedRegexByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1714);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 297, &_161);
	zephir_array_fetch_string(&_162, &dump, SL("combinedRegexDisabled"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1715);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 298, &_162);
	zephir_array_fetch_string(&_163, &dump, SL("combinedRegexMarkMap"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1716);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 299, &_163);
	zephir_array_fetch_string(&_164, &dump, SL("routeMeta"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1717);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 300, &_164);
	ZEPHIR_INIT_VAR(&_165);
	array_init(&_165);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 307, &_165);
	ZEPHIR_INIT_VAR(&_166);
	array_init(&_166);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_12, 308, &_166);
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_13, 290, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_13, 290, &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Loads routes from an array or Phalcon\Config\Config instance.
 *
 * ```php
 * $router->loadFromConfig(
 *     [
 *         'routes' => [
 *             [
 *                 'method'  => 'get',
 *                 'pattern' => '/users',
 *                 'paths'   => 'Users::index',
 *             ],
 *         ],
 *     ]
 * );
 * ```
 *
 * @param array|ConfigInterface config
 *
 * @return static
 *
 * @phpstan-return static
 */
PHP_METHOD(Phalcon_Mvc_Router, loadFromConfig)
{
	zend_bool _3, _5, _6, _12, _18, _11$$9, _17$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, routes, routeData, defaults, notFoundPaths, removeExtra, groups, groupData, _0$$4, _1$$3, _2$$5, _4$$6, *_7$$9, _8$$9, *_9$$9, _10$$9, *_13$$13, _14$$13, *_15$$13, _16$$13;
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
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_16$$13);
	ZEND_TLS zephir_method_cache _zephir_call_cache[18];
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$4, "__construct", &_zephir_call_cache[0]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/Router.zep", 1752);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, config, "toArray", &_zephir_call_cache[1]);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_1$$3);
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, phalcon_mvc_router_exceptions_invalidconfigsource_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$5, "__construct", &_zephir_call_cache[2]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Router.zep", 1758);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_array_isset_value_string(config, SL("removeExtraSlashes"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		zephir_memory_observe(&removeExtra);
		zephir_array_fetch_string(&removeExtra, config, SL("removeExtraSlashes"), PH_NOISY, "phalcon/Mvc/Router.zep", 1762);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_BOOL(&_4$$6, zephir_get_boolval(&removeExtra));
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "removeExtraSlashes", &_zephir_call_cache[3], &_4$$6);
		zephir_check_call_status();
	}
	_5 = zephir_array_isset_value_string(config, SL("defaults"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		zephir_memory_observe(&defaults);
		zephir_array_fetch_string(&defaults, config, SL("defaults"), PH_NOISY, "phalcon/Mvc/Router.zep", 1767);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&defaults) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_configkeymustbearray_ce, "defaults", "phalcon/Mvc/Router.zep", 1769);
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "setDefaults", &_zephir_call_cache[4], &defaults);
		zephir_check_call_status();
	}
	zephir_memory_observe(&routes);
	_6 = zephir_array_isset_string_fetch(&routes, config, SL("routes"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_6) {
		if (Z_TYPE_P(&routes) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_configkeymustbearray_ce, "routes", "phalcon/Mvc/Router.zep", 1776);
			return;
		}
		if (Z_TYPE_P(&routes) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_8$$9);
			zephir_string_to_char_array(&_8$$9, &routes);
			_7$$9 = &_8$$9;
		} else {
			_7$$9 = &routes;
		}
		zephir_is_iterable(_7$$9, 0, "phalcon/Mvc/Router.zep", 1781);
		if (Z_TYPE_P(_7$$9) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_7$$9), _9$$9)
			{
				ZEPHIR_INIT_NVAR(&routeData);
				ZVAL_COPY(&routeData, _9$$9);
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addRouteFromConfig", &_zephir_call_cache[5], &routeData);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _7$$9, "rewind", &_zephir_call_cache[6]);
			zephir_check_call_status();
			_11$$9 = 1;
			while (1) {
				if (_11$$9) {
					_11$$9 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _7$$9, "next", &_zephir_call_cache[7]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_10$$9, _7$$9, "valid", &_zephir_call_cache[8]);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&routeData, _7$$9, "current", &_zephir_call_cache[9]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addRouteFromConfig", &_zephir_call_cache[10], &routeData);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&routeData);
	}
	zephir_memory_observe(&groups);
	_12 = zephir_array_isset_string_fetch(&groups, config, SL("groups"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_12) {
		if (Z_TYPE_P(&groups) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_configkeymustbearray_ce, "groups", "phalcon/Mvc/Router.zep", 1785);
			return;
		}
		if (Z_TYPE_P(&groups) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_14$$13);
			zephir_string_to_char_array(&_14$$13, &groups);
			_13$$13 = &_14$$13;
		} else {
			_13$$13 = &groups;
		}
		zephir_is_iterable(_13$$13, 0, "phalcon/Mvc/Router.zep", 1790);
		if (Z_TYPE_P(_13$$13) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_13$$13), _15$$13)
			{
				ZEPHIR_INIT_NVAR(&groupData);
				ZVAL_COPY(&groupData, _15$$13);
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "mountGroupFromConfig", &_zephir_call_cache[11], &groupData);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _13$$13, "rewind", &_zephir_call_cache[12]);
			zephir_check_call_status();
			_17$$13 = 1;
			while (1) {
				if (_17$$13) {
					_17$$13 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _13$$13, "next", &_zephir_call_cache[13]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_16$$13, _13$$13, "valid", &_zephir_call_cache[14]);
				zephir_check_call_status();
				if (!zend_is_true(&_16$$13)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&groupData, _13$$13, "current", &_zephir_call_cache[15]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "mountGroupFromConfig", &_zephir_call_cache[16], &groupData);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&groupData);
	}
	zephir_memory_observe(&notFoundPaths);
	_18 = zephir_array_isset_string_fetch(&notFoundPaths, config, SL("notFound"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_18) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "notFound", &_zephir_call_cache[17], &notFoundPaths);
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
 *
 * @phpstan-return static
 */
PHP_METHOD(Phalcon_Mvc_Router, mount)
{
	zend_bool _17, _7$$5, _12$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group, group_sub, groupRoutes, beforeMatch, hostname, route, eventsManager, _0, *_13, _14, *_15, _16, _1$$3, _2$$4, *_3$$5, _4$$5, *_5$$5, _6$$5, *_8$$8, _9$$8, *_10$$8, _11$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&groupRoutes);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&hostname);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_11$$8);
	ZEND_TLS zephir_method_cache _zephir_call_cache[23];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(group, phalcon_mvc_router_groupinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &group);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 313, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "router:beforeMount");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[0], &_1$$3, this_ptr, group);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_CACHED(&groupRoutes, group, "getRoutes", &_zephir_call_cache[1]);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&groupRoutes))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_router_exceptions_emptygroupofroutes_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$4, "__construct", &_zephir_call_cache[2]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Router.zep", 1821);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&beforeMatch, group, "getBeforeMatch", &_zephir_call_cache[3]);
	zephir_check_call_status();
	if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
		if (Z_TYPE_P(&groupRoutes) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_4$$5);
			zephir_string_to_char_array(&_4$$5, &groupRoutes);
			_3$$5 = &_4$$5;
		} else {
			_3$$5 = &groupRoutes;
		}
		zephir_is_iterable(_3$$5, 0, "phalcon/Mvc/Router.zep", 1833);
		if (Z_TYPE_P(_3$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3$$5), _5$$5)
			{
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _5$$5);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "beforeMatch", &_zephir_call_cache[4], &beforeMatch);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _3$$5, "rewind", &_zephir_call_cache[5]);
			zephir_check_call_status();
			_7$$5 = 1;
			while (1) {
				if (_7$$5) {
					_7$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _3$$5, "next", &_zephir_call_cache[6]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_6$$5, _3$$5, "valid", &_zephir_call_cache[7]);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&route, _3$$5, "current", &_zephir_call_cache[8]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "beforeMatch", &_zephir_call_cache[9], &beforeMatch);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&route);
	}
	ZEPHIR_CALL_METHOD_CACHED(&hostname, group, "getHostName", &_zephir_call_cache[10]);
	zephir_check_call_status();
	if (Z_TYPE_P(&hostname) != IS_NULL) {
		if (Z_TYPE_P(&groupRoutes) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_9$$8);
			zephir_string_to_char_array(&_9$$8, &groupRoutes);
			_8$$8 = &_9$$8;
		} else {
			_8$$8 = &groupRoutes;
		}
		zephir_is_iterable(_8$$8, 0, "phalcon/Mvc/Router.zep", 1842);
		if (Z_TYPE_P(_8$$8) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_8$$8), _10$$8)
			{
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _10$$8);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "setHostName", &_zephir_call_cache[11], &hostname);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _8$$8, "rewind", &_zephir_call_cache[12]);
			zephir_check_call_status();
			_12$$8 = 1;
			while (1) {
				if (_12$$8) {
					_12$$8 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _8$$8, "next", &_zephir_call_cache[13]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_11$$8, _8$$8, "valid", &_zephir_call_cache[14]);
				zephir_check_call_status();
				if (!zend_is_true(&_11$$8)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&route, _8$$8, "current", &_zephir_call_cache[15]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "setHostName", &_zephir_call_cache[16], &hostname);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&route);
	}
	if (Z_TYPE_P(&groupRoutes) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_14);
		zephir_string_to_char_array(&_14, &groupRoutes);
		_13 = &_14;
	} else {
		_13 = &groupRoutes;
	}
	zephir_is_iterable(_13, 0, "phalcon/Mvc/Router.zep", 1848);
	if (Z_TYPE_P(_13) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_13), _15)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _15);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "attach", &_zephir_call_cache[17], &route);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _13, "rewind", &_zephir_call_cache[18]);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _13, "next", &_zephir_call_cache[19]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_16, _13, "valid", &_zephir_call_cache[20]);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&route, _13, "current", &_zephir_call_cache[21]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "attach", &_zephir_call_cache[22], &route);
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
 *
 * @phpstan-return static
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Router.zep", 1864);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 315, paths);
	RETURN_THIS();
}

/**
 * Set whether router must remove the extra slashes in the handled routes
 *
 * @param bool remove
 *
 * @return static
 *
 * @phpstan-return static
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 309, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 309, &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the default action name
 *
 * @param string actionName
 *
 * @return static
 *
 * @phpstan-return static
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 304, &actionName_zv);
	RETURN_THISW();
}

/**
 * Sets the default controller name
 *
 * @param string controllerName
 *
 * @return static
 *
 * @phpstan-return static
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 303, &controllerName_zv);
	RETURN_THISW();
}

/**
 * Sets the name of the default module
 *
 * @param string moduleName
 *
 * @return static
 *
 * @phpstan-return static
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 302, &moduleName_zv);
	RETURN_THISW();
}

/**
 * Sets the name of the default namespace
 *
 * @parma string namespaceName
 *
 * @return static
 *
 * @phpstan-return static
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 301, &namespaceName_zv);
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
 *
 * @phpstan-param mvc_router_defaults $defaults
 * @phpstan-return static
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaults)
{
	zval _1$$3, _3$$4, _5$$5, _7$$6;
	zend_bool _0, _2, _4, _6, _8;
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
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
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
	_0 = zephir_array_isset_string_fetch(&namespaceName, &defaults, SL("namespace"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		zephir_cast_to_string(&_1$$3, &namespaceName);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 301, &_1$$3);
	}
	zephir_memory_observe(&module);
	_2 = zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		zephir_cast_to_string(&_3$$4, &module);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 302, &_3$$4);
	}
	zephir_memory_observe(&controller);
	_4 = zephir_array_isset_string_fetch(&controller, &defaults, SL("controller"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_4) {
		zephir_cast_to_string(&_5$$5, &controller);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 303, &_5$$5);
	}
	zephir_memory_observe(&action);
	_6 = zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_6) {
		zephir_cast_to_string(&_7$$6, &action);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 304, &_7$$6);
	}
	zephir_memory_observe(&params);
	_8 = zephir_array_isset_string_fetch(&params, &defaults, SL("params"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_8) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 305, &params);
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
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 313, eventsManager);
}

/**
 * @param array $routeIds
 *
 * @return static
 *
 * @phpstan-param array<array-key, int|string> $routeIds
 * @phpstan-return static
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 307, &routeIds);
	RETURN_THIS();
}

/**
 * @param array $routeNames
 *
 * @return static
 *
 * @phpstan-param array<string, int|string> $routeNames
 * @phpstan-return static
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 308, &routeNames);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 306, &_0);
	RETURN_THISW();
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("pendingCache", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("pendingCacheKey", 15, 1);
	}

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
	ZEPHIR_CALL_METHOD_CACHED(&_0, cache, "has", &_zephir_call_cache[0], &key_zv);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD_CACHED(&stored, cache, "get", &_zephir_call_cache[1], &key_zv);
		zephir_check_call_status();
		if (Z_TYPE_P(&stored) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_mvc_router_exception_ce);
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_CONCAT_SVS(&_2$$4, "Router cache value at key '", &key_zv, "' is not an array");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$4, "__construct", &_zephir_call_cache[2], &_2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Router.zep", 2081);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "loadDispatcherFromArray", &_zephir_call_cache[3], &stored);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 321, cache);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 322, &key_zv);
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks if the router matches any of the defined routes
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
 *
 * @phpstan-param array<string, mixed> $routeData
 */
PHP_METHOD(Phalcon_Mvc_Router, addRouteFromConfig)
{
	zval _6$$5, _11$$8, _14$$9;
	zend_bool _0, _1, _2, _3, _9, _12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routeData_param = NULL, methodClass, pattern, paths, method, route, _4, _5$$5, _7$$6, _8$$7, _10$$8, _13$$9;
	zval routeData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeData);
	ZVAL_UNDEF(&methodClass);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_14$$9);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(routeData, routeData_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &routeData_param);
	zephir_get_arrval(&routeData, routeData_param);
	ZEPHIR_INIT_VAR(&method);
	ZVAL_STRING(&method, "");
	ZEPHIR_INIT_VAR(&route);
	ZVAL_NULL(&route);
	zephir_memory_observe(&pattern);
	_0 = zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missingrouteconfigkey_ce, "pattern", "phalcon/Mvc/Router.zep", 2116);
		return;
	}
	zephir_memory_observe(&paths);
	_1 = zephir_array_isset_string_fetch(&paths, &routeData, SL("paths"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missingrouteconfigkey_ce, "paths", "phalcon/Mvc/Router.zep", 2120);
		return;
	}
	_2 = zephir_array_isset_value_string(&routeData, SL("method"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = _2;
	if (_3) {
		zephir_array_fetch_string(&_4, &routeData, SL("method"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2123);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_3 = Z_TYPE_P(&_4) != IS_NULL;
	}
	if (_3) {
		zephir_memory_observe(&_5$$5);
		zephir_array_fetch_string(&_5$$5, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2124);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_cast_to_string(&_6$$5, &_5$$5);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&method);
		zephir_fast_strtolower(&method, &_6$$5);
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
		ZEPHIR_INIT_VAR(&_7$$6);
		zephir_ucfirst(&_7$$6, &method);
		ZEPHIR_INIT_VAR(&methodClass);
		ZEPHIR_CONCAT_SV(&methodClass, "add", &_7$$6);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_ZVAL(&route, this_ptr, &methodClass, NULL, 0, &pattern, &paths);
		zephir_check_call_status();
		goto zephir_switch_0_end;
	zephir_switch_0_clause_11: ;
		ZEPHIR_INIT_VAR(&_8$$7);
		object_init_ex(&_8$$7, phalcon_mvc_router_exceptions_unknownhttpmethod_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_8$$7, "__construct", &_zephir_call_cache[0], &method);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$7, "phalcon/Mvc/Router.zep", 2143);
		ZEPHIR_MM_RESTORE();
		return;
	zephir_switch_0_end: ;

	_9 = zephir_array_isset_value_string(&routeData, SL("name"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_9) {
		zephir_memory_observe(&_10$$8);
		zephir_array_fetch_string(&_10$$8, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 2147);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_cast_to_string(&_11$$8, &_10$$8);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "setName", &_zephir_call_cache[1], &_11$$8);
		zephir_check_call_status();
	}
	_12 = zephir_array_isset_value_string(&routeData, SL("hostname"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_12) {
		zephir_memory_observe(&_13$$9);
		zephir_array_fetch_string(&_13$$9, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 2150);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_cast_to_string(&_14$$9, &_13$$9);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "setHostname", &_zephir_call_cache[2], &_14$$9);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Router, extractRealUri)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval uri_zv, urlParts, realUri, _0;
	zend_string *uri = NULL;

	ZVAL_UNDEF(&uri_zv);
	ZVAL_UNDEF(&urlParts);
	ZVAL_UNDEF(&realUri);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_INIT_VAR(&urlParts);
	zephir_fast_explode_str(&urlParts, SL("?"), &uri_zv, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&realUri);
	zephir_array_fetch_long(&realUri, &urlParts, 0, PH_NOISY, "phalcon/Mvc/Router.zep", 2159);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&realUri);
}

/**
 * Builds a Group from a config entry and mounts it. Used by loadFromConfig.
 *
 * @param array groupData
 *
 * @return void
 *
 * @phpstan-param array<string, mixed> $groupData
 */
PHP_METHOD(Phalcon_Mvc_Router, mountGroupFromConfig)
{
	zval _3$$4, _6$$5, _18$$11, _23$$14, _32$$18, _37$$21;
	zend_bool _0, _1, _4, _7, _25, _12$$8, _13$$8, _14$$8, _15$$8, _21$$8, _26$$15, _27$$15, _28$$15, _29$$15, _35$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *groupData_param = NULL, group, paths, routes, routeData, method, methodClass, pattern, routePaths, route, *_9, _10, *_11, _24, _2$$4, _5$$5, _8$$7, _16$$8, _17$$11, _19$$12, _20$$13, _22$$14, _30$$15, _31$$18, _33$$19, _34$$20, _36$$21;
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
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_31$$18);
	ZVAL_UNDEF(&_33$$19);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&_37$$21);
	ZEND_TLS zephir_method_cache _zephir_call_cache[13];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(groupData, groupData_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &groupData_param);
	zephir_get_arrval(&groupData, groupData_param);
	ZEPHIR_INIT_VAR(&route);
	ZVAL_NULL(&route);
	ZEPHIR_INIT_VAR(&paths);
	ZVAL_NULL(&paths);
	_0 = zephir_array_isset_value_string(&groupData, SL("paths"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		ZEPHIR_OBS_NVAR(&paths);
		zephir_array_fetch_string(&paths, &groupData, SL("paths"), PH_NOISY, "phalcon/Mvc/Router.zep", 2180);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&group);
	object_init_ex(&group, phalcon_mvc_router_group_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &group, "__construct", &_zephir_call_cache[0], &paths);
	zephir_check_call_status();
	_1 = zephir_array_isset_value_string(&groupData, SL("prefix"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_memory_observe(&_2$$4);
		zephir_array_fetch_string(&_2$$4, &groupData, SL("prefix"), PH_NOISY, "phalcon/Mvc/Router.zep", 2186);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_cast_to_string(&_3$$4, &_2$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &group, "setPrefix", &_zephir_call_cache[1], &_3$$4);
		zephir_check_call_status();
	}
	_4 = zephir_array_isset_value_string(&groupData, SL("hostname"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_4) {
		zephir_memory_observe(&_5$$5);
		zephir_array_fetch_string(&_5$$5, &groupData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 2190);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_cast_to_string(&_6$$5, &_5$$5);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &group, "setHostname", &_zephir_call_cache[2], &_6$$5);
		zephir_check_call_status();
	}
	zephir_memory_observe(&routes);
	_7 = zephir_array_isset_string_fetch(&routes, &groupData, SL("routes"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_7)) {
		ZEPHIR_INIT_NVAR(&routes);
		array_init(&routes);
	}
	if (Z_TYPE_P(&routes) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_8$$7);
		object_init_ex(&_8$$7, phalcon_mvc_router_exceptions_grouproutesmustbearray_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_8$$7, "__construct", &_zephir_call_cache[3]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$7, "phalcon/Mvc/Router.zep", 2198);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&routes) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_10);
		zephir_string_to_char_array(&_10, &routes);
		_9 = &_10;
	} else {
		_9 = &routes;
	}
	zephir_is_iterable(_9, 0, "phalcon/Mvc/Router.zep", 2238);
	if (Z_TYPE_P(_9) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9), _11)
		{
			ZEPHIR_INIT_NVAR(&routeData);
			ZVAL_COPY(&routeData, _11);
			ZEPHIR_OBS_NVAR(&pattern);
			_12$$8 = zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_12$$8)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "pattern", "phalcon/Mvc/Router.zep", 2203);
				return;
			}
			ZEPHIR_OBS_NVAR(&routePaths);
			_13$$8 = zephir_array_isset_string_fetch(&routePaths, &routeData, SL("paths"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_13$$8)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "paths", "phalcon/Mvc/Router.zep", 2206);
				return;
			}
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_STRING(&method, "");
			_14$$8 = zephir_array_isset_value_string(&routeData, SL("method"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_15$$8 = _14$$8;
			if (_15$$8) {
				ZEPHIR_OBS_NVAR(&_16$$8);
				zephir_array_fetch_string(&_16$$8, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2210);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_15$$8 = Z_TYPE_P(&_16$$8) != IS_NULL;
			}
			if (_15$$8) {
				ZEPHIR_OBS_NVAR(&_17$$11);
				zephir_array_fetch_string(&_17$$11, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2211);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_18$$11, &_17$$11);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&method);
				zephir_fast_strtolower(&method, &_18$$11);
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
				ZEPHIR_INIT_NVAR(&_19$$12);
				zephir_ucfirst(&_19$$12, &method);
				ZEPHIR_INIT_NVAR(&methodClass);
				ZEPHIR_CONCAT_SV(&methodClass, "add", &_19$$12);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_ZVAL(&route, &group, &methodClass, NULL, 0, &pattern, &routePaths);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_11: ;
				ZEPHIR_INIT_NVAR(&_20$$13);
				object_init_ex(&_20$$13, phalcon_mvc_router_exceptions_unknownhttpmethod_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_20$$13, "__construct", &_zephir_call_cache[4], &method);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_20$$13, "phalcon/Mvc/Router.zep", 2230);
				ZEPHIR_MM_RESTORE();
				return;
			zephir_switch_0_end: ;

			_21$$8 = zephir_array_isset_value_string(&routeData, SL("name"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_21$$8) {
				ZEPHIR_OBS_NVAR(&_22$$14);
				zephir_array_fetch_string(&_22$$14, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 2234);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_23$$14, &_22$$14);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "setName", &_zephir_call_cache[5], &_23$$14);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _9, "rewind", &_zephir_call_cache[6]);
		zephir_check_call_status();
		_25 = 1;
		while (1) {
			if (_25) {
				_25 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _9, "next", &_zephir_call_cache[7]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_24, _9, "valid", &_zephir_call_cache[8]);
			zephir_check_call_status();
			if (!zend_is_true(&_24)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&routeData, _9, "current", &_zephir_call_cache[9]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&pattern);
				_26$$15 = zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_26$$15)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "pattern", "phalcon/Mvc/Router.zep", 2203);
					return;
				}
				ZEPHIR_OBS_NVAR(&routePaths);
				_27$$15 = zephir_array_isset_string_fetch(&routePaths, &routeData, SL("paths"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_27$$15)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "paths", "phalcon/Mvc/Router.zep", 2206);
					return;
				}
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_STRING(&method, "");
				_28$$15 = zephir_array_isset_value_string(&routeData, SL("method"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_29$$15 = _28$$15;
				if (_29$$15) {
					ZEPHIR_OBS_NVAR(&_30$$15);
					zephir_array_fetch_string(&_30$$15, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2210);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_29$$15 = Z_TYPE_P(&_30$$15) != IS_NULL;
				}
				if (_29$$15) {
					ZEPHIR_OBS_NVAR(&_31$$18);
					zephir_array_fetch_string(&_31$$18, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2211);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_cast_to_string(&_32$$18, &_31$$18);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&method);
					zephir_fast_strtolower(&method, &_32$$18);
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
					ZEPHIR_INIT_NVAR(&_33$$19);
					zephir_ucfirst(&_33$$19, &method);
					ZEPHIR_INIT_NVAR(&methodClass);
					ZEPHIR_CONCAT_SV(&methodClass, "add", &_33$$19);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_ZVAL(&route, &group, &methodClass, NULL, 0, &pattern, &routePaths);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_clause_11: ;
					ZEPHIR_INIT_NVAR(&_34$$20);
					object_init_ex(&_34$$20, phalcon_mvc_router_exceptions_unknownhttpmethod_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_34$$20, "__construct", &_zephir_call_cache[10], &method);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_34$$20, "phalcon/Mvc/Router.zep", 2230);
					ZEPHIR_MM_RESTORE();
					return;
				zephir_switch_1_end: ;

				_35$$15 = zephir_array_isset_value_string(&routeData, SL("name"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_35$$15) {
					ZEPHIR_OBS_NVAR(&_36$$21);
					zephir_array_fetch_string(&_36$$21, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 2234);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_cast_to_string(&_37$$21, &_36$$21);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "setName", &_zephir_call_cache[11], &_37$$21);
					zephir_check_call_status();
				}
		}
	}
	ZEPHIR_INIT_NVAR(&routeData);
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "mount", &_zephir_call_cache[12], &group);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Rebuilds the HTTP-method index from the current routes array.
 * Routes with no HTTP method constraint are filed under "*".
 */
PHP_METHOD(Phalcon_Mvc_Router, rebuildMethodIndex)
{
	zval _133$$66, _149$$71;
	zval _7$$3, _18$$13;
	zend_string *_5, *_31, *_48, *_100, *_114, *_37$$24, *_53$$38, *_67$$43, *_89$$52, *_107$$57, *_119$$64;
	zend_ulong _4, _30, _47, _99, _113, _36$$24, _52$$38, _66$$43, _88$$52, _106$$57, _118$$64;
	zend_bool isRegex = 0, _16, _26, _14$$10, _25$$20, _41$$24, _38$$26, _39$$26, _42$$32, _43$$32, _75$$38, _55$$40, _56$$40, _58$$40, _62$$42, _71$$43, _77$$49, _78$$49, _80$$49, _84$$51, _93$$52, _109$$57, _135$$64, _150$$64, _170$$64, _120$$66, _123$$66, _124$$66, _125$$66, _130$$66, _136$$71, _139$$71, _140$$71, _141$$71, _146$$71, _161$$78;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_152 = NULL, *_155 = NULL;
	zval __$true, __$false, route, methods, method, methodSpecific, starRoutes, candidates, candidatePattern, bucketRoute, bucketPattern, staticUri, staticBucket, staticRoutesList, shadowBucket, bucket, methodRoutes, candidatesByMethod, routeMeta, staticByMethod, staticShadowedByMethod, hostnameByMethod, hostnameLessByMethod, combinedRegexByMethod, combinedRegexMarkMap, combinedRegexDisabled, routePatterns, routeHosts, candidateHost, routeData, routeMethods, routeIndex, starPositions, positions, positionsByMethod, bucketIdx, _0, *_1, _2, *_3, _15, *_27, _28, *_29, *_44, _45, *_46, bucketHostname, *_96, _97, *_98, combinedAlternatives, combinedMark, combinedBody, hostnameBucketRef, *_110, _111, *_112, _6$$3, _8$$3, _9$$3, *_10$$10, _11$$10, *_12$$10, _13$$10, _17$$13, _19$$13, _20$$13, *_21$$20, _22$$20, *_23$$20, _24$$20, _32$$24, *_33$$24, _34$$24, *_35$$24, _40$$24, *_49$$38, _50$$38, *_51$$38, _74$$38, _54$$40, _57$$40, _59$$40, _60$$40, _61$$40, *_63$$43, _64$$43, *_65$$43, _70$$43, _68$$44, _69$$44, _72$$46, _73$$46, _76$$49, _79$$49, _81$$49, _82$$49, _83$$49, *_85$$52, _86$$52, *_87$$52, _92$$52, _90$$53, _91$$53, _94$$55, _95$$55, _101$$57, _102$$57, *_103$$57, _104$$57, *_105$$57, _108$$57, *_115$$64, _116$$64, *_117$$64, _134$$64, chunkedPatterns$$64, chunkedMarkMaps$$64, chunkOffset$$64, chunkSlice$$64, chunkSliceMap$$64, chunkMarkSubset$$64, reversedMarkIds$$64, chunkMarkId$$64, chunkPattern$$64, _151$$64, _153$$64, _121$$66, _122$$66, _126$$66, _127$$66, _128$$66, _129$$66, _131$$66, _132$$66, _137$$71, _138$$71, _142$$71, _143$$71, _144$$71, _145$$71, _147$$71, _148$$71, _154$$78, *_156$$78, _157$$78, *_158$$78, _160$$78, _163$$78, _164$$78, _165$$78, _166$$78, _167$$78, _168$$78, _169$$78, _159$$79, _162$$80;
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
	ZVAL_UNDEF(&candidatePattern);
	ZVAL_UNDEF(&bucketRoute);
	ZVAL_UNDEF(&bucketPattern);
	ZVAL_UNDEF(&staticUri);
	ZVAL_UNDEF(&staticBucket);
	ZVAL_UNDEF(&staticRoutesList);
	ZVAL_UNDEF(&shadowBucket);
	ZVAL_UNDEF(&bucket);
	ZVAL_UNDEF(&methodRoutes);
	ZVAL_UNDEF(&candidatesByMethod);
	ZVAL_UNDEF(&routeMeta);
	ZVAL_UNDEF(&staticByMethod);
	ZVAL_UNDEF(&staticShadowedByMethod);
	ZVAL_UNDEF(&hostnameByMethod);
	ZVAL_UNDEF(&hostnameLessByMethod);
	ZVAL_UNDEF(&combinedRegexByMethod);
	ZVAL_UNDEF(&combinedRegexMarkMap);
	ZVAL_UNDEF(&combinedRegexDisabled);
	ZVAL_UNDEF(&routePatterns);
	ZVAL_UNDEF(&routeHosts);
	ZVAL_UNDEF(&candidateHost);
	ZVAL_UNDEF(&routeData);
	ZVAL_UNDEF(&routeMethods);
	ZVAL_UNDEF(&routeIndex);
	ZVAL_UNDEF(&starPositions);
	ZVAL_UNDEF(&positions);
	ZVAL_UNDEF(&positionsByMethod);
	ZVAL_UNDEF(&bucketIdx);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&bucketHostname);
	ZVAL_UNDEF(&_97);
	ZVAL_UNDEF(&combinedAlternatives);
	ZVAL_UNDEF(&combinedMark);
	ZVAL_UNDEF(&combinedBody);
	ZVAL_UNDEF(&hostnameBucketRef);
	ZVAL_UNDEF(&_111);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_22$$20);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_32$$24);
	ZVAL_UNDEF(&_34$$24);
	ZVAL_UNDEF(&_40$$24);
	ZVAL_UNDEF(&_50$$38);
	ZVAL_UNDEF(&_74$$38);
	ZVAL_UNDEF(&_54$$40);
	ZVAL_UNDEF(&_57$$40);
	ZVAL_UNDEF(&_59$$40);
	ZVAL_UNDEF(&_60$$40);
	ZVAL_UNDEF(&_61$$40);
	ZVAL_UNDEF(&_64$$43);
	ZVAL_UNDEF(&_70$$43);
	ZVAL_UNDEF(&_68$$44);
	ZVAL_UNDEF(&_69$$44);
	ZVAL_UNDEF(&_72$$46);
	ZVAL_UNDEF(&_73$$46);
	ZVAL_UNDEF(&_76$$49);
	ZVAL_UNDEF(&_79$$49);
	ZVAL_UNDEF(&_81$$49);
	ZVAL_UNDEF(&_82$$49);
	ZVAL_UNDEF(&_83$$49);
	ZVAL_UNDEF(&_86$$52);
	ZVAL_UNDEF(&_92$$52);
	ZVAL_UNDEF(&_90$$53);
	ZVAL_UNDEF(&_91$$53);
	ZVAL_UNDEF(&_94$$55);
	ZVAL_UNDEF(&_95$$55);
	ZVAL_UNDEF(&_101$$57);
	ZVAL_UNDEF(&_102$$57);
	ZVAL_UNDEF(&_104$$57);
	ZVAL_UNDEF(&_108$$57);
	ZVAL_UNDEF(&_116$$64);
	ZVAL_UNDEF(&_134$$64);
	ZVAL_UNDEF(&chunkedPatterns$$64);
	ZVAL_UNDEF(&chunkedMarkMaps$$64);
	ZVAL_UNDEF(&chunkOffset$$64);
	ZVAL_UNDEF(&chunkSlice$$64);
	ZVAL_UNDEF(&chunkSliceMap$$64);
	ZVAL_UNDEF(&chunkMarkSubset$$64);
	ZVAL_UNDEF(&reversedMarkIds$$64);
	ZVAL_UNDEF(&chunkMarkId$$64);
	ZVAL_UNDEF(&chunkPattern$$64);
	ZVAL_UNDEF(&_151$$64);
	ZVAL_UNDEF(&_153$$64);
	ZVAL_UNDEF(&_121$$66);
	ZVAL_UNDEF(&_122$$66);
	ZVAL_UNDEF(&_126$$66);
	ZVAL_UNDEF(&_127$$66);
	ZVAL_UNDEF(&_128$$66);
	ZVAL_UNDEF(&_129$$66);
	ZVAL_UNDEF(&_131$$66);
	ZVAL_UNDEF(&_132$$66);
	ZVAL_UNDEF(&_137$$71);
	ZVAL_UNDEF(&_138$$71);
	ZVAL_UNDEF(&_142$$71);
	ZVAL_UNDEF(&_143$$71);
	ZVAL_UNDEF(&_144$$71);
	ZVAL_UNDEF(&_145$$71);
	ZVAL_UNDEF(&_147$$71);
	ZVAL_UNDEF(&_148$$71);
	ZVAL_UNDEF(&_154$$78);
	ZVAL_UNDEF(&_157$$78);
	ZVAL_UNDEF(&_160$$78);
	ZVAL_UNDEF(&_163$$78);
	ZVAL_UNDEF(&_164$$78);
	ZVAL_UNDEF(&_165$$78);
	ZVAL_UNDEF(&_166$$78);
	ZVAL_UNDEF(&_167$$78);
	ZVAL_UNDEF(&_168$$78);
	ZVAL_UNDEF(&_169$$78);
	ZVAL_UNDEF(&_159$$79);
	ZVAL_UNDEF(&_162$$80);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_133$$66);
	ZVAL_UNDEF(&_149$$71);
	ZEND_TLS zephir_method_cache _zephir_call_cache[53];
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

	ZEPHIR_INIT_VAR(&methodRoutes);
	array_init(&methodRoutes);
	ZEPHIR_INIT_VAR(&candidatesByMethod);
	array_init(&candidatesByMethod);
	ZEPHIR_INIT_VAR(&positionsByMethod);
	array_init(&positionsByMethod);
	ZEPHIR_INIT_VAR(&staticByMethod);
	array_init(&staticByMethod);
	ZEPHIR_INIT_VAR(&staticShadowedByMethod);
	array_init(&staticShadowedByMethod);
	ZEPHIR_INIT_VAR(&routeMethods);
	ZVAL_NULL(&routeMethods);
	ZEPHIR_INIT_VAR(&starPositions);
	ZVAL_NULL(&starPositions);
	ZEPHIR_INIT_VAR(&routeMeta);
	array_init(&routeMeta);
	ZEPHIR_INIT_VAR(&routePatterns);
	array_init(&routePatterns);
	ZEPHIR_INIT_VAR(&routeHosts);
	array_init(&routeHosts);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Router.zep", 2331);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&routeIndex);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&routeIndex, _5);
			} else {
				ZVAL_LONG(&routeIndex, _4);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _3);
			ZEPHIR_CALL_METHOD_CACHED(&routeData, &route, "getIndexData", &_zephir_call_cache[0]);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&methods);
			zephir_array_fetch_long(&methods, &routeData, 0, PH_NOISY, "phalcon/Mvc/Router.zep", 2283);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&candidatePattern);
			zephir_array_fetch_long(&candidatePattern, &routeData, 1, PH_NOISY, "phalcon/Mvc/Router.zep", 2284);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&candidateHost);
			zephir_array_fetch_long(&candidateHost, &routeData, 2, PH_NOISY, "phalcon/Mvc/Router.zep", 2285);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			isRegex = 0;
			if (zephir_memnstr_str(&candidatePattern, SL("^"), "phalcon/Mvc/Router.zep", 2288)) {
				isRegex = 1;
			}
			ZEPHIR_OBS_NVAR(&_6$$3);
			zephir_array_fetch_long(&_6$$3, &routeData, 5, PH_NOISY, "phalcon/Mvc/Router.zep", 2292);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_7$$3);
			zephir_create_array(&_7$$3, 5, 0);
			zephir_array_update_string(&_7$$3, SL("pattern"), &candidatePattern, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_BOOL(&_8$$3, isRegex);
			zephir_array_update_string(&_7$$3, SL("isRegex"), &_8$$3, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_7$$3, SL("hostname"), &candidateHost, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_9$$3);
			zephir_array_fetch_long(&_9$$3, &routeData, 3, PH_NOISY, "phalcon/Mvc/Router.zep", 2296);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&_7$$3, SL("hostRegex"), &_9$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_9$$3);
			zephir_array_fetch_long(&_9$$3, &routeData, 4, PH_NOISY, "phalcon/Mvc/Router.zep", 2298);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&_7$$3, SL("beforeMatch"), &_9$$3, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&routeMeta, &_6$$3, &_7$$3, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&routePatterns, &routeIndex, &candidatePattern, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&routeHosts, &routeIndex, &candidateHost, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&methods) == IS_NULL) {
				if (Z_TYPE_P(&starPositions) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&starPositions);
					array_init(&starPositions);
				}
				zephir_array_update_multi(&methodRoutes, &route, SL("sa"), 3, SL("*"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&starPositions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2309);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				if (Z_TYPE_P(&routeMethods) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&routeMethods);
					array_init(&routeMethods);
				}
				zephir_array_update_zval(&routeMethods, &routeIndex, &methods, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&methods) == IS_STRING) {
					zephir_array_update_multi(&methodRoutes, &route, SL("za"), 2, &methods);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					if (Z_TYPE_P(&methods) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_11$$10);
						zephir_string_to_char_array(&_11$$10, &methods);
						_10$$10 = &_11$$10;
					} else {
						_10$$10 = &methods;
					}
					zephir_is_iterable(_10$$10, 0, "phalcon/Mvc/Router.zep", 2327);
					if (Z_TYPE_P(_10$$10) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_10$$10), _12$$10)
						{
							ZEPHIR_INIT_NVAR(&method);
							ZVAL_COPY(&method, _12$$10);
							zephir_array_update_multi(&methodRoutes, &route, SL("za"), 2, &method);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _10$$10, "rewind", &_zephir_call_cache[1]);
						zephir_check_call_status();
						_14$$10 = 1;
						while (1) {
							if (_14$$10) {
								_14$$10 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _10$$10, "next", &_zephir_call_cache[2]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_13$$10, _10$$10, "valid", &_zephir_call_cache[3]);
							zephir_check_call_status();
							if (!zend_is_true(&_13$$10)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&method, _10$$10, "current", &_zephir_call_cache[4]);
							zephir_check_call_status();
								zephir_array_update_multi(&methodRoutes, &route, SL("za"), 2, &method);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&method);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[5]);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[6]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_15, _1, "valid", &_zephir_call_cache[7]);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&routeIndex, _1, "key", &_zephir_call_cache[8]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&route, _1, "current", &_zephir_call_cache[9]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&routeData, &route, "getIndexData", &_zephir_call_cache[10]);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&methods);
				zephir_array_fetch_long(&methods, &routeData, 0, PH_NOISY, "phalcon/Mvc/Router.zep", 2283);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&candidatePattern);
				zephir_array_fetch_long(&candidatePattern, &routeData, 1, PH_NOISY, "phalcon/Mvc/Router.zep", 2284);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&candidateHost);
				zephir_array_fetch_long(&candidateHost, &routeData, 2, PH_NOISY, "phalcon/Mvc/Router.zep", 2285);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				isRegex = 0;
				if (zephir_memnstr_str(&candidatePattern, SL("^"), "phalcon/Mvc/Router.zep", 2288)) {
					isRegex = 1;
				}
				ZEPHIR_OBS_NVAR(&_17$$13);
				zephir_array_fetch_long(&_17$$13, &routeData, 5, PH_NOISY, "phalcon/Mvc/Router.zep", 2292);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_18$$13);
				zephir_create_array(&_18$$13, 5, 0);
				zephir_array_update_string(&_18$$13, SL("pattern"), &candidatePattern, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_19$$13);
				ZVAL_BOOL(&_19$$13, isRegex);
				zephir_array_update_string(&_18$$13, SL("isRegex"), &_19$$13, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_18$$13, SL("hostname"), &candidateHost, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_20$$13);
				zephir_array_fetch_long(&_20$$13, &routeData, 3, PH_NOISY, "phalcon/Mvc/Router.zep", 2296);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&_18$$13, SL("hostRegex"), &_20$$13, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_20$$13);
				zephir_array_fetch_long(&_20$$13, &routeData, 4, PH_NOISY, "phalcon/Mvc/Router.zep", 2298);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&_18$$13, SL("beforeMatch"), &_20$$13, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&routeMeta, &_17$$13, &_18$$13, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&routePatterns, &routeIndex, &candidatePattern, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&routeHosts, &routeIndex, &candidateHost, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&methods) == IS_NULL) {
					if (Z_TYPE_P(&starPositions) == IS_NULL) {
						ZEPHIR_INIT_NVAR(&starPositions);
						array_init(&starPositions);
					}
					zephir_array_update_multi(&methodRoutes, &route, SL("sa"), 3, SL("*"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&starPositions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2309);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					if (Z_TYPE_P(&routeMethods) == IS_NULL) {
						ZEPHIR_INIT_NVAR(&routeMethods);
						array_init(&routeMethods);
					}
					zephir_array_update_zval(&routeMethods, &routeIndex, &methods, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&methods) == IS_STRING) {
						zephir_array_update_multi(&methodRoutes, &route, SL("za"), 2, &methods);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						if (Z_TYPE_P(&methods) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_22$$20);
							zephir_string_to_char_array(&_22$$20, &methods);
							_21$$20 = &_22$$20;
						} else {
							_21$$20 = &methods;
						}
						zephir_is_iterable(_21$$20, 0, "phalcon/Mvc/Router.zep", 2327);
						if (Z_TYPE_P(_21$$20) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_21$$20), _23$$20)
							{
								ZEPHIR_INIT_NVAR(&method);
								ZVAL_COPY(&method, _23$$20);
								zephir_array_update_multi(&methodRoutes, &route, SL("za"), 2, &method);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _21$$20, "rewind", &_zephir_call_cache[11]);
							zephir_check_call_status();
							_25$$20 = 1;
							while (1) {
								if (_25$$20) {
									_25$$20 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _21$$20, "next", &_zephir_call_cache[12]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_24$$20, _21$$20, "valid", &_zephir_call_cache[13]);
								zephir_check_call_status();
								if (!zend_is_true(&_24$$20)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&method, _21$$20, "current", &_zephir_call_cache[14]);
								zephir_check_call_status();
									zephir_array_update_multi(&methodRoutes, &route, SL("za"), 2, &method);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
							}
						}
						ZEPHIR_INIT_NVAR(&method);
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&routeIndex);
	zephir_memory_observe(&starRoutes);
	_26 = zephir_array_isset_string_fetch(&starRoutes, &methodRoutes, SL("*"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_26)) {
		ZEPHIR_INIT_NVAR(&starRoutes);
		array_init(&starRoutes);
	}
	if (Z_TYPE_P(&methodRoutes) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_28);
		zephir_string_to_char_array(&_28, &methodRoutes);
		_27 = &_28;
	} else {
		_27 = &methodRoutes;
	}
	zephir_is_iterable(_27, 0, "phalcon/Mvc/Router.zep", 2383);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_27), _30, _31, _29)
	{
		ZEPHIR_INIT_NVAR(&method);
		if (_31 != NULL) { 
			ZVAL_STR_COPY(&method, _31);
		} else {
			ZVAL_LONG(&method, _30);
		}
		ZEPHIR_INIT_NVAR(&methodSpecific);
		ZVAL_COPY(&methodSpecific, _29);
		if (ZEPHIR_IS_STRING(&method, "*")) {
			zephir_array_update_string(&candidatesByMethod, SL("*"), &starRoutes, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&positionsByMethod, SL("*"), &starPositions, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			continue;
		}
		ZEPHIR_INIT_NVAR(&bucket);
		array_init(&bucket);
		ZEPHIR_INIT_NVAR(&positions);
		array_init(&positions);
		zephir_read_property_cached(&_32$$24, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&_32$$24) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_34$$24);
			zephir_string_to_char_array(&_34$$24, &_32$$24);
			_33$$24 = &_34$$24;
		} else {
			_33$$24 = &_32$$24;
		}
		zephir_is_iterable(_33$$24, 0, "phalcon/Mvc/Router.zep", 2372);
		if (Z_TYPE_P(_33$$24) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_33$$24), _36$$24, _37$$24, _35$$24)
			{
				ZEPHIR_INIT_NVAR(&routeIndex);
				if (_37$$24 != NULL) { 
					ZVAL_STR_COPY(&routeIndex, _37$$24);
				} else {
					ZVAL_LONG(&routeIndex, _36$$24);
				}
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _35$$24);
				ZEPHIR_OBS_NVAR(&methods);
				_38$$26 = zephir_array_isset_fetch(&methods, &routeMethods, &routeIndex, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_38$$26)) {
					ZEPHIR_INIT_NVAR(&methods);
					ZVAL_NULL(&methods);
				}
				if (Z_TYPE_P(&methods) == IS_NULL) {
					zephir_array_append(&bucket, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2359);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&positions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2360);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (Z_TYPE_P(&methods) == IS_STRING) {
					if (ZEPHIR_IS_IDENTICAL(&methods, &method)) {
						zephir_array_append(&bucket, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2363);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&positions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2364);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					_39$$26 = zephir_fast_in_array(&method, &methods);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_39$$26) {
						zephir_array_append(&bucket, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2367);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&positions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2368);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _33$$24, "rewind", &_zephir_call_cache[15]);
			zephir_check_call_status();
			_41$$24 = 1;
			while (1) {
				if (_41$$24) {
					_41$$24 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _33$$24, "next", &_zephir_call_cache[16]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_40$$24, _33$$24, "valid", &_zephir_call_cache[17]);
				zephir_check_call_status();
				if (!zend_is_true(&_40$$24)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&routeIndex, _33$$24, "key", &_zephir_call_cache[18]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&route, _33$$24, "current", &_zephir_call_cache[19]);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&methods);
					_42$$32 = zephir_array_isset_fetch(&methods, &routeMethods, &routeIndex, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_42$$32)) {
						ZEPHIR_INIT_NVAR(&methods);
						ZVAL_NULL(&methods);
					}
					if (Z_TYPE_P(&methods) == IS_NULL) {
						zephir_array_append(&bucket, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2359);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&positions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2360);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else if (Z_TYPE_P(&methods) == IS_STRING) {
						if (ZEPHIR_IS_IDENTICAL(&methods, &method)) {
							zephir_array_append(&bucket, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2363);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&positions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2364);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						_43$$32 = zephir_fast_in_array(&method, &methods);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_43$$32) {
							zephir_array_append(&bucket, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2367);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&positions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2368);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&route);
		ZEPHIR_INIT_NVAR(&routeIndex);
		zephir_array_update_zval(&candidatesByMethod, &method, &bucket, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&positionsByMethod, &method, &positions, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&methodSpecific);
	ZEPHIR_INIT_NVAR(&method);
	if (Z_TYPE_P(&candidatesByMethod) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_45);
		zephir_string_to_char_array(&_45, &candidatesByMethod);
		_44 = &_45;
	} else {
		_44 = &candidatesByMethod;
	}
	zephir_is_iterable(_44, 0, "phalcon/Mvc/Router.zep", 2431);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_44), _47, _48, _46)
	{
		ZEPHIR_INIT_NVAR(&method);
		if (_48 != NULL) { 
			ZVAL_STR_COPY(&method, _48);
		} else {
			ZVAL_LONG(&method, _47);
		}
		ZEPHIR_INIT_NVAR(&candidates);
		ZVAL_COPY(&candidates, _46);
		ZEPHIR_OBS_NVAR(&positions);
		zephir_array_fetch(&positions, &positionsByMethod, &method, PH_NOISY, "phalcon/Mvc/Router.zep", 2384);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&candidates) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_50$$38);
			zephir_string_to_char_array(&_50$$38, &candidates);
			_49$$38 = &_50$$38;
		} else {
			_49$$38 = &candidates;
		}
		zephir_is_iterable(_49$$38, 0, "phalcon/Mvc/Router.zep", 2424);
		if (Z_TYPE_P(_49$$38) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_49$$38), _52$$38, _53$$38, _51$$38)
			{
				ZEPHIR_INIT_NVAR(&bucketIdx);
				if (_53$$38 != NULL) { 
					ZVAL_STR_COPY(&bucketIdx, _53$$38);
				} else {
					ZVAL_LONG(&bucketIdx, _52$$38);
				}
				ZEPHIR_INIT_NVAR(&bucketRoute);
				ZVAL_COPY(&bucketRoute, _51$$38);
				ZEPHIR_OBS_NVAR(&routeIndex);
				zephir_array_fetch(&routeIndex, &positions, &bucketIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 2387);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&bucketPattern);
				zephir_array_fetch(&bucketPattern, &routePatterns, &routeIndex, PH_NOISY, "phalcon/Mvc/Router.zep", 2388);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2390))) {
					zephir_array_update_multi(&staticByMethod, &bucketRoute, SL("zza"), 3, &method, &bucketPattern);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_54$$40, &staticShadowedByMethod, &method, PH_READONLY, "phalcon/Mvc/Router.zep", 2401);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_55$$40 = zephir_array_isset_value(&_54$$40, &bucketPattern);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_56$$40 = _55$$40;
					if (_56$$40) {
						zephir_array_fetch(&_57$$40, &routeHosts, &routeIndex, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2402);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_56$$40 = Z_TYPE_P(&_57$$40) == IS_NULL;
					}
					_58$$40 = _56$$40;
					if (_58$$40) {
						ZEPHIR_CALL_METHOD_CACHED(&_60$$40, &bucketRoute, "getRouteId", &_zephir_call_cache[20]);
						zephir_check_call_status();
						zephir_array_fetch(&_59$$40, &routeMeta, &_60$$40, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2403);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&_61$$40);
						zephir_array_fetch_string(&_61$$40, &_59$$40, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 2403);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_58$$40 = Z_TYPE_P(&_61$$40) == IS_NULL;
					}
					if (_58$$40) {
						ZEPHIR_OBS_NVAR(&shadowBucket);
						zephir_array_fetch(&shadowBucket, &staticShadowedByMethod, &method, PH_NOISY, "phalcon/Mvc/Router.zep", 2408);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_unset(&shadowBucket, &bucketPattern, PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&staticShadowedByMethod, &method, &shadowBucket, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_OBS_NVAR(&staticBucket);
					_62$$42 = zephir_array_isset_fetch(&staticBucket, &staticByMethod, &method, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_62$$42) {
						if (Z_TYPE_P(&staticBucket) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_64$$43);
							zephir_string_to_char_array(&_64$$43, &staticBucket);
							_63$$43 = &_64$$43;
						} else {
							_63$$43 = &staticBucket;
						}
						zephir_is_iterable(_63$$43, 0, "phalcon/Mvc/Router.zep", 2421);
						if (Z_TYPE_P(_63$$43) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_63$$43), _66$$43, _67$$43, _65$$43)
							{
								ZEPHIR_INIT_NVAR(&staticUri);
								if (_67$$43 != NULL) { 
									ZVAL_STR_COPY(&staticUri, _67$$43);
								} else {
									ZVAL_LONG(&staticUri, _66$$43);
								}
								ZEPHIR_INIT_NVAR(&staticRoutesList);
								ZVAL_COPY(&staticRoutesList, _65$$43);
								ZEPHIR_INIT_NVAR(&_68$$44);
								ZEPHIR_INIT_NVAR(&_69$$44);
								zephir_preg_match(&_69$$44, &bucketPattern, &staticUri, &_68$$44, 0, 0 , 0 );
								if (zephir_is_true(&_69$$44)) {
									zephir_array_update_multi(&staticShadowedByMethod, &__$true, SL("zz"), 2, &method, &staticUri);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _63$$43, "rewind", &_zephir_call_cache[21]);
							zephir_check_call_status();
							_71$$43 = 1;
							while (1) {
								if (_71$$43) {
									_71$$43 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _63$$43, "next", &_zephir_call_cache[22]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_70$$43, _63$$43, "valid", &_zephir_call_cache[23]);
								zephir_check_call_status();
								if (!zend_is_true(&_70$$43)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&staticUri, _63$$43, "key", &_zephir_call_cache[24]);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&staticRoutesList, _63$$43, "current", &_zephir_call_cache[25]);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_72$$46);
									ZEPHIR_INIT_NVAR(&_73$$46);
									zephir_preg_match(&_73$$46, &bucketPattern, &staticUri, &_72$$46, 0, 0 , 0 );
									if (zephir_is_true(&_73$$46)) {
										zephir_array_update_multi(&staticShadowedByMethod, &__$true, SL("zz"), 2, &method, &staticUri);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
							}
						}
						ZEPHIR_INIT_NVAR(&staticRoutesList);
						ZEPHIR_INIT_NVAR(&staticUri);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _49$$38, "rewind", &_zephir_call_cache[26]);
			zephir_check_call_status();
			_75$$38 = 1;
			while (1) {
				if (_75$$38) {
					_75$$38 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _49$$38, "next", &_zephir_call_cache[27]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_74$$38, _49$$38, "valid", &_zephir_call_cache[28]);
				zephir_check_call_status();
				if (!zend_is_true(&_74$$38)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&bucketIdx, _49$$38, "key", &_zephir_call_cache[29]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&bucketRoute, _49$$38, "current", &_zephir_call_cache[30]);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&routeIndex);
					zephir_array_fetch(&routeIndex, &positions, &bucketIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 2387);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&bucketPattern);
					zephir_array_fetch(&bucketPattern, &routePatterns, &routeIndex, PH_NOISY, "phalcon/Mvc/Router.zep", 2388);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2390))) {
						zephir_array_update_multi(&staticByMethod, &bucketRoute, SL("zza"), 3, &method, &bucketPattern);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_fetch(&_76$$49, &staticShadowedByMethod, &method, PH_READONLY, "phalcon/Mvc/Router.zep", 2401);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_77$$49 = zephir_array_isset_value(&_76$$49, &bucketPattern);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_78$$49 = _77$$49;
						if (_78$$49) {
							zephir_array_fetch(&_79$$49, &routeHosts, &routeIndex, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2402);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_78$$49 = Z_TYPE_P(&_79$$49) == IS_NULL;
						}
						_80$$49 = _78$$49;
						if (_80$$49) {
							ZEPHIR_CALL_METHOD_CACHED(&_82$$49, &bucketRoute, "getRouteId", &_zephir_call_cache[31]);
							zephir_check_call_status();
							zephir_array_fetch(&_81$$49, &routeMeta, &_82$$49, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2403);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_83$$49);
							zephir_array_fetch_string(&_83$$49, &_81$$49, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 2403);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_80$$49 = Z_TYPE_P(&_83$$49) == IS_NULL;
						}
						if (_80$$49) {
							ZEPHIR_OBS_NVAR(&shadowBucket);
							zephir_array_fetch(&shadowBucket, &staticShadowedByMethod, &method, PH_NOISY, "phalcon/Mvc/Router.zep", 2408);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_unset(&shadowBucket, &bucketPattern, PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&staticShadowedByMethod, &method, &shadowBucket, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_OBS_NVAR(&staticBucket);
						_84$$51 = zephir_array_isset_fetch(&staticBucket, &staticByMethod, &method, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_84$$51) {
							if (Z_TYPE_P(&staticBucket) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_86$$52);
								zephir_string_to_char_array(&_86$$52, &staticBucket);
								_85$$52 = &_86$$52;
							} else {
								_85$$52 = &staticBucket;
							}
							zephir_is_iterable(_85$$52, 0, "phalcon/Mvc/Router.zep", 2421);
							if (Z_TYPE_P(_85$$52) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_85$$52), _88$$52, _89$$52, _87$$52)
								{
									ZEPHIR_INIT_NVAR(&staticUri);
									if (_89$$52 != NULL) { 
										ZVAL_STR_COPY(&staticUri, _89$$52);
									} else {
										ZVAL_LONG(&staticUri, _88$$52);
									}
									ZEPHIR_INIT_NVAR(&staticRoutesList);
									ZVAL_COPY(&staticRoutesList, _87$$52);
									ZEPHIR_INIT_NVAR(&_90$$53);
									ZEPHIR_INIT_NVAR(&_91$$53);
									zephir_preg_match(&_91$$53, &bucketPattern, &staticUri, &_90$$53, 0, 0 , 0 );
									if (zephir_is_true(&_91$$53)) {
										zephir_array_update_multi(&staticShadowedByMethod, &__$true, SL("zz"), 2, &method, &staticUri);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _85$$52, "rewind", &_zephir_call_cache[32]);
								zephir_check_call_status();
								_93$$52 = 1;
								while (1) {
									if (_93$$52) {
										_93$$52 = 0;
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _85$$52, "next", &_zephir_call_cache[33]);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD_CACHED(&_92$$52, _85$$52, "valid", &_zephir_call_cache[34]);
									zephir_check_call_status();
									if (!zend_is_true(&_92$$52)) {
										break;
									}
									ZEPHIR_CALL_METHOD_CACHED(&staticUri, _85$$52, "key", &_zephir_call_cache[35]);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD_CACHED(&staticRoutesList, _85$$52, "current", &_zephir_call_cache[36]);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_94$$55);
										ZEPHIR_INIT_NVAR(&_95$$55);
										zephir_preg_match(&_95$$55, &bucketPattern, &staticUri, &_94$$55, 0, 0 , 0 );
										if (zephir_is_true(&_95$$55)) {
											zephir_array_update_multi(&staticShadowedByMethod, &__$true, SL("zz"), 2, &method, &staticUri);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
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
		ZEPHIR_INIT_NVAR(&bucketIdx);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&candidates);
	ZEPHIR_INIT_NVAR(&method);
	ZEPHIR_INIT_VAR(&hostnameByMethod);
	array_init(&hostnameByMethod);
	ZEPHIR_INIT_VAR(&hostnameLessByMethod);
	array_init(&hostnameLessByMethod);
	if (Z_TYPE_P(&positionsByMethod) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_97);
		zephir_string_to_char_array(&_97, &positionsByMethod);
		_96 = &_97;
	} else {
		_96 = &positionsByMethod;
	}
	zephir_is_iterable(_96, 0, "phalcon/Mvc/Router.zep", 2458);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_96), _99, _100, _98)
	{
		ZEPHIR_INIT_NVAR(&method);
		if (_100 != NULL) { 
			ZVAL_STR_COPY(&method, _100);
		} else {
			ZVAL_LONG(&method, _99);
		}
		ZEPHIR_INIT_NVAR(&positions);
		ZVAL_COPY(&positions, _98);
		ZEPHIR_INIT_NVAR(&_101$$57);
		array_init(&_101$$57);
		zephir_array_update_zval(&hostnameByMethod, &method, &_101$$57, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&_102$$57);
		array_init(&_102$$57);
		zephir_array_update_zval(&hostnameLessByMethod, &method, &_102$$57, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&positions) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_104$$57);
			zephir_string_to_char_array(&_104$$57, &positions);
			_103$$57 = &_104$$57;
		} else {
			_103$$57 = &positions;
		}
		zephir_is_iterable(_103$$57, 0, "phalcon/Mvc/Router.zep", 2449);
		if (Z_TYPE_P(_103$$57) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_103$$57), _106$$57, _107$$57, _105$$57)
			{
				ZEPHIR_INIT_NVAR(&bucketIdx);
				if (_107$$57 != NULL) { 
					ZVAL_STR_COPY(&bucketIdx, _107$$57);
				} else {
					ZVAL_LONG(&bucketIdx, _106$$57);
				}
				ZEPHIR_INIT_NVAR(&routeIndex);
				ZVAL_COPY(&routeIndex, _105$$57);
				ZEPHIR_OBS_NVAR(&bucketHostname);
				zephir_array_fetch(&bucketHostname, &routeHosts, &routeIndex, PH_NOISY, "phalcon/Mvc/Router.zep", 2441);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&bucketHostname) == IS_NULL) {
					zephir_array_update_multi(&hostnameLessByMethod, &bucketIdx, SL("za"), 2, &method);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_array_update_multi(&hostnameByMethod, &bucketIdx, SL("zza"), 3, &method, &bucketHostname);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _103$$57, "rewind", &_zephir_call_cache[37]);
			zephir_check_call_status();
			_109$$57 = 1;
			while (1) {
				if (_109$$57) {
					_109$$57 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _103$$57, "next", &_zephir_call_cache[38]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_108$$57, _103$$57, "valid", &_zephir_call_cache[39]);
				zephir_check_call_status();
				if (!zend_is_true(&_108$$57)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&bucketIdx, _103$$57, "key", &_zephir_call_cache[40]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&routeIndex, _103$$57, "current", &_zephir_call_cache[41]);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&bucketHostname);
					zephir_array_fetch(&bucketHostname, &routeHosts, &routeIndex, PH_NOISY, "phalcon/Mvc/Router.zep", 2441);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&bucketHostname) == IS_NULL) {
						zephir_array_update_multi(&hostnameLessByMethod, &bucketIdx, SL("za"), 2, &method);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						zephir_array_update_multi(&hostnameByMethod, &bucketIdx, SL("zza"), 3, &method, &bucketHostname);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&routeIndex);
		ZEPHIR_INIT_NVAR(&bucketIdx);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&positions);
	ZEPHIR_INIT_NVAR(&method);
	ZEPHIR_INIT_VAR(&combinedRegexByMethod);
	array_init(&combinedRegexByMethod);
	ZEPHIR_INIT_VAR(&combinedRegexMarkMap);
	array_init(&combinedRegexMarkMap);
	ZEPHIR_INIT_VAR(&combinedRegexDisabled);
	array_init(&combinedRegexDisabled);
	if (Z_TYPE_P(&positionsByMethod) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_111);
		zephir_string_to_char_array(&_111, &positionsByMethod);
		_110 = &_111;
	} else {
		_110 = &positionsByMethod;
	}
	zephir_is_iterable(_110, 0, "phalcon/Mvc/Router.zep", 2589);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_110), _113, _114, _112)
	{
		ZEPHIR_INIT_NVAR(&method);
		if (_114 != NULL) { 
			ZVAL_STR_COPY(&method, _114);
		} else {
			ZVAL_LONG(&method, _113);
		}
		ZEPHIR_INIT_NVAR(&positions);
		ZVAL_COPY(&positions, _112);
		ZEPHIR_OBS_NVAR(&hostnameBucketRef);
		zephir_array_fetch(&hostnameBucketRef, &hostnameByMethod, &method, PH_NOISY, "phalcon/Mvc/Router.zep", 2466);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(ZEPHIR_IS_EMPTY(&hostnameBucketRef))) {
			zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			continue;
		}
		ZEPHIR_INIT_NVAR(&combinedAlternatives);
		array_init(&combinedAlternatives);
		ZEPHIR_INIT_NVAR(&combinedMark);
		array_init(&combinedMark);
		if (Z_TYPE_P(&positions) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_116$$64);
			zephir_string_to_char_array(&_116$$64, &positions);
			_115$$64 = &_116$$64;
		} else {
			_115$$64 = &positions;
		}
		zephir_is_iterable(_115$$64, 0, "phalcon/Mvc/Router.zep", 2526);
		if (Z_TYPE_P(_115$$64) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_115$$64), _118$$64, _119$$64, _117$$64)
			{
				ZEPHIR_INIT_NVAR(&bucketIdx);
				if (_119$$64 != NULL) { 
					ZVAL_STR_COPY(&bucketIdx, _119$$64);
				} else {
					ZVAL_LONG(&bucketIdx, _118$$64);
				}
				ZEPHIR_INIT_NVAR(&routeIndex);
				ZVAL_COPY(&routeIndex, _117$$64);
				ZEPHIR_OBS_NVAR(&bucketPattern);
				zephir_array_fetch(&bucketPattern, &routePatterns, &routeIndex, PH_NOISY, "phalcon/Mvc/Router.zep", 2477);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2479))) {
					continue;
				}
				_120$$66 = !(zephir_start_with_str(&bucketPattern, SL("#^")));
				if (!(_120$$66)) {
					_120$$66 = !(zephir_end_with_str(&bucketPattern, SL("$#u")));
				}
				if (_120$$66) {
					zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&combinedAlternatives);
					array_init(&combinedAlternatives);
					break;
				}
				ZVAL_LONG(&_121$$66, 2);
				ZVAL_LONG(&_122$$66, -3);
				ZEPHIR_INIT_NVAR(&combinedBody);
				zephir_substr(&combinedBody, &bucketPattern, 2 , -3 , 0);
				_123$$66 = ZEPHIR_IS_STRING_IDENTICAL(&combinedBody, "");
				if (!(_123$$66)) {
					_123$$66 = zephir_memnstr_str(&combinedBody, SL("\n"), "phalcon/Mvc/Router.zep", 2505);
				}
				_124$$66 = _123$$66;
				if (!(_124$$66)) {
					_125$$66 = zephir_memnstr_str(&combinedBody, SL("(?"), "phalcon/Mvc/Router.zep", 2505);
					if (_125$$66) {
						ZEPHIR_INIT_NVAR(&_126$$66);
						ZEPHIR_INIT_NVAR(&_127$$66);
						ZVAL_STRING(&_127$$66, "/\\(\\?(?:P?<[^=!]|')/");
						ZEPHIR_INIT_NVAR(&_128$$66);
						ZEPHIR_INIT_NVAR(&_129$$66);
						ZVAL_STRING(&_129$$66, "/\\(\\?(?:P?<[^=!]|')/");
						zephir_preg_match(&_128$$66, &_129$$66, &combinedBody, &_126$$66, 0, 0 , 0 );
						_125$$66 = zephir_is_true(&_128$$66);
					}
					_124$$66 = _125$$66;
				}
				if (_124$$66) {
					zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&combinedAlternatives);
					array_init(&combinedAlternatives);
					break;
				}
				_130$$66 = zephir_memnstr_str(&combinedBody, SL("|"), "phalcon/Mvc/Router.zep", 2516);
				if (_130$$66) {
					ZEPHIR_CALL_METHOD_CACHED(&_131$$66, this_ptr, "hasTopLevelAlternation", &_zephir_call_cache[42], &combinedBody);
					zephir_check_call_status();
					_130$$66 = zephir_is_true(&_131$$66);
				}
				if (_130$$66) {
					zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&combinedAlternatives);
					array_init(&combinedAlternatives);
					break;
				}
				ZEPHIR_INIT_NVAR(&_132$$66);
				ZEPHIR_CONCAT_VSVS(&_132$$66, &combinedBody, "(*:", &bucketIdx, ")");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&combinedAlternatives, &_132$$66, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2522);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_133$$66, &bucketIdx);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&combinedMark, &_133$$66, &bucketIdx, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _115$$64, "rewind", &_zephir_call_cache[43]);
			zephir_check_call_status();
			_135$$64 = 1;
			while (1) {
				if (_135$$64) {
					_135$$64 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _115$$64, "next", &_zephir_call_cache[44]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_134$$64, _115$$64, "valid", &_zephir_call_cache[45]);
				zephir_check_call_status();
				if (!zend_is_true(&_134$$64)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&bucketIdx, _115$$64, "key", &_zephir_call_cache[46]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&routeIndex, _115$$64, "current", &_zephir_call_cache[47]);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&bucketPattern);
					zephir_array_fetch(&bucketPattern, &routePatterns, &routeIndex, PH_NOISY, "phalcon/Mvc/Router.zep", 2477);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2479))) {
						continue;
					}
					_136$$71 = !(zephir_start_with_str(&bucketPattern, SL("#^")));
					if (!(_136$$71)) {
						_136$$71 = !(zephir_end_with_str(&bucketPattern, SL("$#u")));
					}
					if (_136$$71) {
						zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&combinedAlternatives);
						array_init(&combinedAlternatives);
						break;
					}
					ZVAL_LONG(&_137$$71, 2);
					ZVAL_LONG(&_138$$71, -3);
					ZEPHIR_INIT_NVAR(&combinedBody);
					zephir_substr(&combinedBody, &bucketPattern, 2 , -3 , 0);
					_139$$71 = ZEPHIR_IS_STRING_IDENTICAL(&combinedBody, "");
					if (!(_139$$71)) {
						_139$$71 = zephir_memnstr_str(&combinedBody, SL("\n"), "phalcon/Mvc/Router.zep", 2505);
					}
					_140$$71 = _139$$71;
					if (!(_140$$71)) {
						_141$$71 = zephir_memnstr_str(&combinedBody, SL("(?"), "phalcon/Mvc/Router.zep", 2505);
						if (_141$$71) {
							ZEPHIR_INIT_NVAR(&_142$$71);
							ZEPHIR_INIT_NVAR(&_143$$71);
							ZVAL_STRING(&_143$$71, "/\\(\\?(?:P?<[^=!]|')/");
							ZEPHIR_INIT_NVAR(&_144$$71);
							ZEPHIR_INIT_NVAR(&_145$$71);
							ZVAL_STRING(&_145$$71, "/\\(\\?(?:P?<[^=!]|')/");
							zephir_preg_match(&_144$$71, &_145$$71, &combinedBody, &_142$$71, 0, 0 , 0 );
							_141$$71 = zephir_is_true(&_144$$71);
						}
						_140$$71 = _141$$71;
					}
					if (_140$$71) {
						zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&combinedAlternatives);
						array_init(&combinedAlternatives);
						break;
					}
					_146$$71 = zephir_memnstr_str(&combinedBody, SL("|"), "phalcon/Mvc/Router.zep", 2516);
					if (_146$$71) {
						ZEPHIR_CALL_METHOD_CACHED(&_147$$71, this_ptr, "hasTopLevelAlternation", &_zephir_call_cache[48], &combinedBody);
						zephir_check_call_status();
						_146$$71 = zephir_is_true(&_147$$71);
					}
					if (_146$$71) {
						zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&combinedAlternatives);
						array_init(&combinedAlternatives);
						break;
					}
					ZEPHIR_INIT_NVAR(&_148$$71);
					ZEPHIR_CONCAT_VSVS(&_148$$71, &combinedBody, "(*:", &bucketIdx, ")");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&combinedAlternatives, &_148$$71, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2522);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_cast_to_string(&_149$$71, &bucketIdx);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&combinedMark, &_149$$71, &bucketIdx, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&routeIndex);
		ZEPHIR_INIT_NVAR(&bucketIdx);
		_150$$64 = zephir_array_isset_value(&combinedRegexDisabled, &method);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_150$$64) {
			continue;
		}
		if (ZEPHIR_IS_EMPTY(&combinedAlternatives)) {
			continue;
		}
		ZEPHIR_CALL_FUNCTION(&_151$$64, "array_reverse", &_152, 80, &combinedAlternatives);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&combinedAlternatives, &_151$$64);
		ZEPHIR_INIT_NVAR(&_153$$64);
		zephir_array_keys(&_153$$64, &combinedMark);
		ZEPHIR_CALL_FUNCTION(&reversedMarkIds$$64, "array_reverse", &_152, 80, &_153$$64);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&reversedMarkIds$$64, &reversedMarkIds$$64);
		ZEPHIR_INIT_NVAR(&chunkedPatterns$$64);
		array_init(&chunkedPatterns$$64);
		ZEPHIR_CPY_WRT(&chunkedPatterns$$64, &chunkedPatterns$$64);
		ZEPHIR_INIT_NVAR(&chunkedMarkMaps$$64);
		array_init(&chunkedMarkMaps$$64);
		ZEPHIR_CPY_WRT(&chunkedMarkMaps$$64, &chunkedMarkMaps$$64);
		ZEPHIR_INIT_NVAR(&chunkOffset$$64);
		ZVAL_LONG(&chunkOffset$$64, 0);
		while (1) {
			if (!(ZEPHIR_LT_LONG(&chunkOffset$$64, zephir_fast_count_int(&combinedAlternatives)))) {
				break;
			}
			ZVAL_LONG(&_154$$78, 10);
			ZEPHIR_CALL_FUNCTION(&chunkSlice$$64, "array_slice", &_155, 81, &combinedAlternatives, &chunkOffset$$64, &_154$$78);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&chunkSlice$$64, &chunkSlice$$64);
			ZVAL_LONG(&_154$$78, 10);
			ZEPHIR_CALL_FUNCTION(&chunkMarkSubset$$64, "array_slice", &_155, 81, &reversedMarkIds$$64, &chunkOffset$$64, &_154$$78);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&chunkMarkSubset$$64, &chunkMarkSubset$$64);
			ZEPHIR_INIT_NVAR(&chunkSliceMap$$64);
			array_init(&chunkSliceMap$$64);
			ZEPHIR_CPY_WRT(&chunkSliceMap$$64, &chunkSliceMap$$64);
			if (Z_TYPE_P(&chunkMarkSubset$$64) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_157$$78);
				zephir_string_to_char_array(&_157$$78, &chunkMarkSubset$$64);
				_156$$78 = &_157$$78;
			} else {
				_156$$78 = &chunkMarkSubset$$64;
			}
			zephir_is_iterable(_156$$78, 0, "phalcon/Mvc/Router.zep", 2561);
			if (Z_TYPE_P(_156$$78) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_156$$78), _158$$78)
				{
					ZEPHIR_INIT_NVAR(&chunkMarkId$$64);
					ZVAL_COPY(&chunkMarkId$$64, _158$$78);
					ZEPHIR_OBS_NVAR(&_159$$79);
					zephir_array_fetch(&_159$$79, &combinedMark, &chunkMarkId$$64, PH_NOISY, "phalcon/Mvc/Router.zep", 2558);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&chunkSliceMap$$64, &chunkMarkId$$64, &_159$$79, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _156$$78, "rewind", &_zephir_call_cache[49]);
				zephir_check_call_status();
				_161$$78 = 1;
				while (1) {
					if (_161$$78) {
						_161$$78 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _156$$78, "next", &_zephir_call_cache[50]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_160$$78, _156$$78, "valid", &_zephir_call_cache[51]);
					zephir_check_call_status();
					if (!zend_is_true(&_160$$78)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&chunkMarkId$$64, _156$$78, "current", &_zephir_call_cache[52]);
					zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&_162$$80);
						zephir_array_fetch(&_162$$80, &combinedMark, &chunkMarkId$$64, PH_NOISY, "phalcon/Mvc/Router.zep", 2558);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&chunkSliceMap$$64, &chunkMarkId$$64, &_162$$80, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&chunkMarkId$$64);
			ZEPHIR_INIT_NVAR(&_163$$78);
			zephir_fast_join_str(&_163$$78, SL("|"), &chunkSlice$$64);
			ZEPHIR_INIT_NVAR(&chunkPattern$$64);
			ZEPHIR_CONCAT_SVS(&chunkPattern$$64, "#^(?|", &_163$$78, ")$#u");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&chunkPattern$$64, &chunkPattern$$64);
			ZEPHIR_INIT_NVAR(&_164$$78);
			ZEPHIR_INIT_NVAR(&_165$$78);
			ZVAL_STRING(&_165$$78, "");
			ZEPHIR_INIT_NVAR(&_166$$78);
			ZEPHIR_INIT_NVAR(&_167$$78);
			ZVAL_STRING(&_167$$78, "");
			zephir_preg_match(&_166$$78, &chunkPattern$$64, &_167$$78, &_164$$78, 0, 0 , 0 );
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_166$$78)) {
				zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				break;
			}
			zephir_array_append(&chunkedPatterns$$64, &chunkPattern$$64, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2576);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&chunkedMarkMaps$$64, &chunkSliceMap$$64, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2577);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_168$$78);
			ZVAL_LONG(&_168$$78, 10);
			ZEPHIR_INIT_NVAR(&_169$$78);
			zephir_add_function(&_169$$78, &chunkOffset$$64, &_168$$78);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&chunkOffset$$64, &_169$$78);
		}
		_170$$64 = zephir_array_isset_value(&combinedRegexDisabled, &method);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_170$$64) {
			continue;
		}
		zephir_array_update_zval(&combinedRegexByMethod, &method, &chunkedPatterns$$64, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&combinedRegexMarkMap, &method, &chunkedMarkMaps$$64, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&positions);
	ZEPHIR_INIT_NVAR(&method);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 291, &methodRoutes);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 292, &candidatesByMethod);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 300, &routeMeta);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 293, &staticByMethod);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 294, &staticShadowedByMethod);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 295, &hostnameByMethod);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 296, &hostnameLessByMethod);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 297, &combinedRegexByMethod);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 299, &combinedRegexMarkMap);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 298, &combinedRegexDisabled);
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 290, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 290, &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks if a regular expression body has a "|" outside a group. The
 * check skips escaped characters and character classes.
 */
PHP_METHOD(Phalcon_Mvc_Router, hasTopLevelAlternation)
{
	zend_long _0;
	zend_long classLength, depth;
	zend_bool classNegated, escaped, inClass, _1$$7, _2$$7, _3$$7, _4$$3;
	char ch = 0;
	zval body_zv;
	zend_string *body = NULL;

	ZVAL_UNDEF(&body_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(body)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&body_zv, body);
	classNegated = 0;
	escaped = 0;
	inClass = 0;
	classLength = 0;
	depth = 0;
	for (_0 = 0; _0 < Z_STRLEN_P(&body_zv); _0++) {
		ch = ZEPHIR_STRING_OFFSET(&body_zv, _0);
		if (escaped) {
			escaped = 0;
			if (inClass) {
				classLength++;
			}
			continue;
		}
		if (ch == '\\') {
			escaped = 1;
			continue;
		}
		if (inClass) {
			_1$$7 = ch == '^';
			if (_1$$7) {
				_1$$7 = classLength == 0;
			}
			_2$$7 = _1$$7;
			if (_2$$7) {
				_2$$7 = !classNegated;
			}
			if (_2$$7) {
				classNegated = 1;
			} else {
				_3$$7 = ch == ']';
				if (_3$$7) {
					_3$$7 = classLength > 0;
				}
				if (_3$$7) {
					inClass = 0;
				} else {
					classLength++;
				}
			}
			continue;
		}
		if (ch == '[') {
			inClass = 1;
			classLength = 0;
			classNegated = 0;
		} else if (ch == '(') {
			depth++;
		} else if (ch == ')') {
			depth--;
		} else {
			_4$$3 = ch == '|';
			if (_4$$3) {
				_4$$3 = depth == 0;
			}
			if (_4$$3) {
				RETURN_BOOL(1);
			}
		}
	}
	RETURN_BOOL(0);
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
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 44, stream, &_0, &separator_zv, enclosure, escape);
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
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long offset, length, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _3, _4, _5;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
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
	if (0 == (length != 0)) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 45, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_3, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_4, offset);
	ZVAL_LONG(&_5, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 45, &filename_zv, &_3, context, &_4, &_5);
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
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 46, &filename_zv, data, &_0, context);
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
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 47, &filename_zv, &mode_zv, &_0, context);
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
	zephir_fcall_cache_entry *_1 = NULL;
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
	if (0 == (length != 0)) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", &_1, 48, handle, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is a directory
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-dir.php
 */
PHP_METHOD(Phalcon_Mvc_Router, phpIsDir)
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
	ZEPHIR_RETURN_CALL_FUNCTION("is_dir", NULL, 49, &filename_zv);
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
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 50, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Makes a directory
 *
 * @param string        $directory
 * @param int           $permissions
 * @param bool          $recursive
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.mkdir.php
 */
PHP_METHOD(Phalcon_Mvc_Router, phpMkdir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool recursive;
	zend_long permissions, ZEPHIR_LAST_CALL_STATUS;
	zval directory_zv, *permissions_param = NULL, *recursive_param = NULL, *context = NULL, context_sub, __$null, _0, _1;
	zend_string *directory = NULL;

	ZVAL_UNDEF(&directory_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(directory)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(permissions)
		Z_PARAM_BOOL(recursive)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		permissions_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		recursive_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&directory_zv);
	ZVAL_STR_COPY(&directory_zv, directory);
	if (!permissions_param) {
		permissions = 0777;
	} else {
		}
	if (!recursive_param) {
		recursive = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, permissions);
	ZVAL_BOOL(&_1, (recursive ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("mkdir", NULL, 51, &directory_zv, &_0, &_1, context);
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
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 52, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

