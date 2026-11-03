
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
	zval _1$$3, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultRoutes_param = NULL, _0$$3, _2$$3, _6$$3;
	zend_bool defaultRoutes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$3);
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", &_3, 266, &_2$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", &_4, 0, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 3, 0);
		add_assoc_long_ex(&_5$$3, SL("controller"), 1);
		add_assoc_long_ex(&_5$$3, SL("action"), 2);
		add_assoc_long_ex(&_5$$3, SL("params"), 3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "#^/([\\w0-9\\_\\-]+)/([\\w0-9\\.\\_]+)(/.*)?$#u");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", &_7, 266, &_6$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", &_4, 0, &_2$$3);
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
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 266, &pattern_zv, paths, httpMethods);
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
		zephir_fast_array_merge(&_0$$4, &_1$$4, &_2$$4);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 289, &_0$$4);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_2: ;
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_router_exceptions_invalidrouteposition_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 267);
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
	zval _31$$4, _59$$11;
	zend_bool _35, _78, _104, _147, _9$$4, _25$$6, _37$$11, _53$$13, _74$$18, _85$$21, _100$$24, _111$$27, _136$$30, _132$$31, _143$$34, _164$$37, _160$$38, _171$$41;
	zend_string *_6, *_67, *_93, *_119, *_18$$6, *_46$$13, *_125$$30, *_153$$37;
	zend_ulong _5, _66, _92, _118, _17$$6, _45$$13, _124$$30, _152$$37;
	zval route, cb, converters, convName, converter, dumpedRoutes, routeToIdx, scalarIdx, scalarSubKey, scalarVal, methodRoutesScalar, candidatesScalar, staticScalar, innerKey, innerVal, mostInnerVal, mostInnerArr, _0, _1, *_2, _3, *_4, _34, _62, *_63, _64, *_65, _77, _88, *_89, _90, *_91, _103, _114, *_115, _116, *_117, _146, _174, _7$$4, _32$$4, _33$$4, _10$$5, _11$$5, _12$$5, *_14$$6, _15$$6, *_16$$6, _24$$6, _19$$8, _20$$8, _22$$8, _26$$10, _27$$10, _29$$10, _36$$11, _60$$11, _61$$11, _38$$12, _39$$12, _40$$12, *_42$$13, _43$$13, *_44$$13, _52$$13, _47$$15, _48$$15, _50$$15, _54$$17, _55$$17, _57$$17, *_68$$18, _69$$18, *_70$$18, _73$$18, _71$$19, _72$$19, _75$$20, _76$$20, *_79$$21, _80$$21, *_81$$21, _84$$21, _82$$22, _83$$22, _86$$23, _87$$23, *_94$$24, _95$$24, *_96$$24, _99$$24, _97$$25, _98$$25, _101$$26, _102$$26, *_105$$27, _106$$27, *_107$$27, _110$$27, _108$$28, _109$$28, _112$$29, _113$$29, _120$$30, *_121$$30, _122$$30, *_123$$30, _135$$30, *_126$$31, _127$$31, *_128$$31, _131$$31, _129$$32, _130$$32, _133$$33, _134$$33, *_137$$34, _138$$34, *_139$$34, _142$$34, _140$$35, _141$$35, _144$$36, _145$$36, _148$$37, *_149$$37, _150$$37, *_151$$37, _163$$37, *_154$$38, _155$$38, *_156$$38, _159$$38, _157$$39, _158$$39, _161$$40, _162$$40, *_165$$41, _166$$41, *_167$$41, _170$$41, _168$$42, _169$$42, _172$$43, _173$$43;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_13 = NULL, *_21 = NULL, *_23 = NULL, *_28 = NULL, *_30 = NULL, *_41 = NULL, *_49 = NULL, *_51 = NULL, *_56 = NULL, *_58 = NULL;
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
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_62);
	ZVAL_UNDEF(&_64);
	ZVAL_UNDEF(&_77);
	ZVAL_UNDEF(&_88);
	ZVAL_UNDEF(&_90);
	ZVAL_UNDEF(&_103);
	ZVAL_UNDEF(&_114);
	ZVAL_UNDEF(&_116);
	ZVAL_UNDEF(&_146);
	ZVAL_UNDEF(&_174);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_32$$4);
	ZVAL_UNDEF(&_33$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_36$$11);
	ZVAL_UNDEF(&_60$$11);
	ZVAL_UNDEF(&_61$$11);
	ZVAL_UNDEF(&_38$$12);
	ZVAL_UNDEF(&_39$$12);
	ZVAL_UNDEF(&_40$$12);
	ZVAL_UNDEF(&_43$$13);
	ZVAL_UNDEF(&_52$$13);
	ZVAL_UNDEF(&_47$$15);
	ZVAL_UNDEF(&_48$$15);
	ZVAL_UNDEF(&_50$$15);
	ZVAL_UNDEF(&_54$$17);
	ZVAL_UNDEF(&_55$$17);
	ZVAL_UNDEF(&_57$$17);
	ZVAL_UNDEF(&_69$$18);
	ZVAL_UNDEF(&_73$$18);
	ZVAL_UNDEF(&_71$$19);
	ZVAL_UNDEF(&_72$$19);
	ZVAL_UNDEF(&_75$$20);
	ZVAL_UNDEF(&_76$$20);
	ZVAL_UNDEF(&_80$$21);
	ZVAL_UNDEF(&_84$$21);
	ZVAL_UNDEF(&_82$$22);
	ZVAL_UNDEF(&_83$$22);
	ZVAL_UNDEF(&_86$$23);
	ZVAL_UNDEF(&_87$$23);
	ZVAL_UNDEF(&_95$$24);
	ZVAL_UNDEF(&_99$$24);
	ZVAL_UNDEF(&_97$$25);
	ZVAL_UNDEF(&_98$$25);
	ZVAL_UNDEF(&_101$$26);
	ZVAL_UNDEF(&_102$$26);
	ZVAL_UNDEF(&_106$$27);
	ZVAL_UNDEF(&_110$$27);
	ZVAL_UNDEF(&_108$$28);
	ZVAL_UNDEF(&_109$$28);
	ZVAL_UNDEF(&_112$$29);
	ZVAL_UNDEF(&_113$$29);
	ZVAL_UNDEF(&_120$$30);
	ZVAL_UNDEF(&_122$$30);
	ZVAL_UNDEF(&_135$$30);
	ZVAL_UNDEF(&_127$$31);
	ZVAL_UNDEF(&_131$$31);
	ZVAL_UNDEF(&_129$$32);
	ZVAL_UNDEF(&_130$$32);
	ZVAL_UNDEF(&_133$$33);
	ZVAL_UNDEF(&_134$$33);
	ZVAL_UNDEF(&_138$$34);
	ZVAL_UNDEF(&_142$$34);
	ZVAL_UNDEF(&_140$$35);
	ZVAL_UNDEF(&_141$$35);
	ZVAL_UNDEF(&_144$$36);
	ZVAL_UNDEF(&_145$$36);
	ZVAL_UNDEF(&_148$$37);
	ZVAL_UNDEF(&_150$$37);
	ZVAL_UNDEF(&_163$$37);
	ZVAL_UNDEF(&_155$$38);
	ZVAL_UNDEF(&_159$$38);
	ZVAL_UNDEF(&_157$$39);
	ZVAL_UNDEF(&_158$$39);
	ZVAL_UNDEF(&_161$$40);
	ZVAL_UNDEF(&_162$$40);
	ZVAL_UNDEF(&_166$$41);
	ZVAL_UNDEF(&_170$$41);
	ZVAL_UNDEF(&_168$$42);
	ZVAL_UNDEF(&_169$$42);
	ZVAL_UNDEF(&_172$$43);
	ZVAL_UNDEF(&_173$$43);
	ZVAL_UNDEF(&_31$$4);
	ZVAL_UNDEF(&_59$$11);
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
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rebuildMethodIndex", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&dumpedRoutes);
	array_init(&dumpedRoutes);
	ZEPHIR_INIT_VAR(&routeToIdx);
	array_init(&routeToIdx);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 289, PH_NOISY_CC | PH_READONLY);
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
			ZEPHIR_CALL_FUNCTION(&_7$$4, "spl_object_id", &_8, 51, &route);
			zephir_check_call_status();
			zephir_array_update_zval(&routeToIdx, &_7$$4, &scalarIdx, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&cb, &route, "getBeforeMatch", NULL, 0);
			zephir_check_call_status();
			_9$$4 = Z_TYPE_P(&cb) != IS_NULL;
			if (_9$$4) {
				_9$$4 = zephir_is_instance_of(&cb, SL("Closure"));
			}
			if (_9$$4) {
				ZEPHIR_INIT_NVAR(&_10$$5);
				object_init_ex(&_10$$5, phalcon_mvc_router_exception_ce);
				ZEPHIR_CALL_METHOD(&_11$$5, &route, "getRouteId", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZEPHIR_CONCAT_SVS(&_12$$5, "Cannot cache router: route id '", &_11$$5, "' has a Closure beforeMatch - only string/array callables are cacheable");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(NULL, &_10$$5, "__construct", &_13, 7, &_12$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_10$$5, "phalcon/Mvc/Router.zep", 692);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&converters, &route, "getConverters", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&converters) == IS_ARRAY) {
				if (Z_TYPE_P(&converters) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_15$$6);
					zephir_string_to_char_array(&_15$$6, &converters);
					_14$$6 = &_15$$6;
				} else {
					_14$$6 = &converters;
				}
				zephir_is_iterable(_14$$6, 0, "phalcon/Mvc/Router.zep", 706);
				if (Z_TYPE_P(_14$$6) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_14$$6), _17$$6, _18$$6, _16$$6)
					{
						ZEPHIR_INIT_NVAR(&convName);
						if (_18$$6 != NULL) { 
							ZVAL_STR_COPY(&convName, _18$$6);
						} else {
							ZVAL_LONG(&convName, _17$$6);
						}
						ZEPHIR_INIT_NVAR(&converter);
						ZVAL_COPY(&converter, _16$$6);
						if (zephir_is_instance_of(&converter, SL("Closure"))) {
							ZEPHIR_INIT_NVAR(&_19$$8);
							object_init_ex(&_19$$8, phalcon_mvc_router_exception_ce);
							ZEPHIR_CALL_METHOD(&_20$$8, &route, "getRouteId", &_21, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_22$$8);
							ZEPHIR_CONCAT_SVSVS(&_22$$8, "Cannot cache router: route id '", &_20$$8, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD(NULL, &_19$$8, "__construct", &_23, 7, &_22$$8);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_19$$8, "phalcon/Mvc/Router.zep", 703);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _14$$6, "rewind", NULL, 0);
					zephir_check_call_status();
					_25$$6 = 1;
					while (1) {
						if (_25$$6) {
							_25$$6 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _14$$6, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_24$$6, _14$$6, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_24$$6)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&convName, _14$$6, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&converter, _14$$6, "current", NULL, 0);
						zephir_check_call_status();
							if (zephir_is_instance_of(&converter, SL("Closure"))) {
								ZEPHIR_INIT_NVAR(&_26$$10);
								object_init_ex(&_26$$10, phalcon_mvc_router_exception_ce);
								ZEPHIR_CALL_METHOD(&_27$$10, &route, "getRouteId", &_28, 0);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_29$$10);
								ZEPHIR_CONCAT_SVSVS(&_29$$10, "Cannot cache router: route id '", &_27$$10, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD(NULL, &_26$$10, "__construct", &_30, 7, &_29$$10);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_26$$10, "phalcon/Mvc/Router.zep", 703);
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&converter);
				ZEPHIR_INIT_NVAR(&convName);
			}
			ZEPHIR_INIT_NVAR(&_31$$4);
			zephir_create_array(&_31$$4, 9, 0);
			ZEPHIR_INIT_NVAR(&_32$$4);
			zephir_get_class(&_32$$4, &route, 0);
			zephir_array_update_string(&_31$$4, SL("class"), &_32$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_33$$4, &route, "getPattern", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_31$$4, SL("pattern"), &_33$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_33$$4, &route, "getPaths", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_31$$4, SL("paths"), &_33$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_33$$4, &route, "getHttpMethods", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_31$$4, SL("methods"), &_33$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_33$$4, &route, "getHostname", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_31$$4, SL("hostname"), &_33$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_33$$4, &route, "getName", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_31$$4, SL("name"), &_33$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_33$$4, &route, "getRouteId", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_31$$4, SL("id"), &_33$$4, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_31$$4, SL("beforeMatch"), &cb, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_31$$4, SL("converters"), &converters, PH_COPY | PH_SEPARATE);
			zephir_array_append(&dumpedRoutes, &_31$$4, PH_SEPARATE, "phalcon/Mvc/Router.zep", 718);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _2, "rewind", NULL, 0);
		zephir_check_call_status();
		_35 = 1;
		while (1) {
			if (_35) {
				_35 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _2, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_34, _2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_34)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&scalarIdx, _2, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, _2, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_36$$11, "spl_object_id", &_8, 51, &route);
				zephir_check_call_status();
				zephir_array_update_zval(&routeToIdx, &_36$$11, &scalarIdx, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&cb, &route, "getBeforeMatch", NULL, 0);
				zephir_check_call_status();
				_37$$11 = Z_TYPE_P(&cb) != IS_NULL;
				if (_37$$11) {
					_37$$11 = zephir_is_instance_of(&cb, SL("Closure"));
				}
				if (_37$$11) {
					ZEPHIR_INIT_NVAR(&_38$$12);
					object_init_ex(&_38$$12, phalcon_mvc_router_exception_ce);
					ZEPHIR_CALL_METHOD(&_39$$12, &route, "getRouteId", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_40$$12);
					ZEPHIR_CONCAT_SVS(&_40$$12, "Cannot cache router: route id '", &_39$$12, "' has a Closure beforeMatch - only string/array callables are cacheable");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(NULL, &_38$$12, "__construct", &_41, 7, &_40$$12);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_38$$12, "phalcon/Mvc/Router.zep", 692);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&converters, &route, "getConverters", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&converters) == IS_ARRAY) {
					if (Z_TYPE_P(&converters) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_43$$13);
						zephir_string_to_char_array(&_43$$13, &converters);
						_42$$13 = &_43$$13;
					} else {
						_42$$13 = &converters;
					}
					zephir_is_iterable(_42$$13, 0, "phalcon/Mvc/Router.zep", 706);
					if (Z_TYPE_P(_42$$13) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_42$$13), _45$$13, _46$$13, _44$$13)
						{
							ZEPHIR_INIT_NVAR(&convName);
							if (_46$$13 != NULL) { 
								ZVAL_STR_COPY(&convName, _46$$13);
							} else {
								ZVAL_LONG(&convName, _45$$13);
							}
							ZEPHIR_INIT_NVAR(&converter);
							ZVAL_COPY(&converter, _44$$13);
							if (zephir_is_instance_of(&converter, SL("Closure"))) {
								ZEPHIR_INIT_NVAR(&_47$$15);
								object_init_ex(&_47$$15, phalcon_mvc_router_exception_ce);
								ZEPHIR_CALL_METHOD(&_48$$15, &route, "getRouteId", &_49, 0);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_50$$15);
								ZEPHIR_CONCAT_SVSVS(&_50$$15, "Cannot cache router: route id '", &_48$$15, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD(NULL, &_47$$15, "__construct", &_51, 7, &_50$$15);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_47$$15, "phalcon/Mvc/Router.zep", 703);
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _42$$13, "rewind", NULL, 0);
						zephir_check_call_status();
						_53$$13 = 1;
						while (1) {
							if (_53$$13) {
								_53$$13 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _42$$13, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_52$$13, _42$$13, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_52$$13)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&convName, _42$$13, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&converter, _42$$13, "current", NULL, 0);
							zephir_check_call_status();
								if (zephir_is_instance_of(&converter, SL("Closure"))) {
									ZEPHIR_INIT_NVAR(&_54$$17);
									object_init_ex(&_54$$17, phalcon_mvc_router_exception_ce);
									ZEPHIR_CALL_METHOD(&_55$$17, &route, "getRouteId", &_56, 0);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_57$$17);
									ZEPHIR_CONCAT_SVSVS(&_57$$17, "Cannot cache router: route id '", &_55$$17, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD(NULL, &_54$$17, "__construct", &_58, 7, &_57$$17);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_54$$17, "phalcon/Mvc/Router.zep", 703);
									ZEPHIR_MM_RESTORE();
									return;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&converter);
					ZEPHIR_INIT_NVAR(&convName);
				}
				ZEPHIR_INIT_NVAR(&_59$$11);
				zephir_create_array(&_59$$11, 9, 0);
				ZEPHIR_INIT_NVAR(&_60$$11);
				zephir_get_class(&_60$$11, &route, 0);
				zephir_array_update_string(&_59$$11, SL("class"), &_60$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_61$$11, &route, "getPattern", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_59$$11, SL("pattern"), &_61$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_61$$11, &route, "getPaths", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_59$$11, SL("paths"), &_61$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_61$$11, &route, "getHttpMethods", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_59$$11, SL("methods"), &_61$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_61$$11, &route, "getHostname", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_59$$11, SL("hostname"), &_61$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_61$$11, &route, "getName", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_59$$11, SL("name"), &_61$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_61$$11, &route, "getRouteId", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_59$$11, SL("id"), &_61$$11, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_59$$11, SL("beforeMatch"), &cb, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_59$$11, SL("converters"), &converters, PH_COPY | PH_SEPARATE);
				zephir_array_append(&dumpedRoutes, &_59$$11, PH_SEPARATE, "phalcon/Mvc/Router.zep", 718);
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
	zephir_read_property_cached(&_62, this_ptr, _zephir_prop_2, 291, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_62) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_64);
		zephir_string_to_char_array(&_64, &_62);
		_63 = &_64;
	} else {
		_63 = &_62;
	}
	zephir_is_iterable(_63, 0, "phalcon/Mvc/Router.zep", 730);
	if (Z_TYPE_P(_63) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_63), _66, _67, _65)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_67 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _67);
			} else {
				ZVAL_LONG(&innerKey, _66);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _65);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_69$$18);
				zephir_string_to_char_array(&_69$$18, &innerVal);
				_68$$18 = &_69$$18;
			} else {
				_68$$18 = &innerVal;
			}
			zephir_is_iterable(_68$$18, 0, "phalcon/Mvc/Router.zep", 727);
			if (Z_TYPE_P(_68$$18) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_68$$18), _70$$18)
				{
					ZEPHIR_INIT_NVAR(&scalarVal);
					ZVAL_COPY(&scalarVal, _70$$18);
					ZEPHIR_CALL_FUNCTION(&_72$$19, "spl_object_id", &_8, 51, &scalarVal);
					zephir_check_call_status();
					zephir_array_fetch(&_71$$19, &routeToIdx, &_72$$19, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 725);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&mostInnerArr, &_71$$19, PH_SEPARATE, "phalcon/Mvc/Router.zep", 725);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _68$$18, "rewind", NULL, 0);
				zephir_check_call_status();
				_74$$18 = 1;
				while (1) {
					if (_74$$18) {
						_74$$18 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _68$$18, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_73$$18, _68$$18, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_73$$18)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarVal, _68$$18, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_76$$20, "spl_object_id", &_8, 51, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_75$$20, &routeToIdx, &_76$$20, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 725);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_75$$20, PH_SEPARATE, "phalcon/Mvc/Router.zep", 725);
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
		ZEPHIR_CALL_METHOD(NULL, _63, "rewind", NULL, 0);
		zephir_check_call_status();
		_78 = 1;
		while (1) {
			if (_78) {
				_78 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _63, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_77, _63, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_77)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, _63, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, _63, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_80$$21);
					zephir_string_to_char_array(&_80$$21, &innerVal);
					_79$$21 = &_80$$21;
				} else {
					_79$$21 = &innerVal;
				}
				zephir_is_iterable(_79$$21, 0, "phalcon/Mvc/Router.zep", 727);
				if (Z_TYPE_P(_79$$21) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_79$$21), _81$$21)
					{
						ZEPHIR_INIT_NVAR(&scalarVal);
						ZVAL_COPY(&scalarVal, _81$$21);
						ZEPHIR_CALL_FUNCTION(&_83$$22, "spl_object_id", &_8, 51, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_82$$22, &routeToIdx, &_83$$22, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 725);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_82$$22, PH_SEPARATE, "phalcon/Mvc/Router.zep", 725);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _79$$21, "rewind", NULL, 0);
					zephir_check_call_status();
					_85$$21 = 1;
					while (1) {
						if (_85$$21) {
							_85$$21 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _79$$21, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_84$$21, _79$$21, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_84$$21)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarVal, _79$$21, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&_87$$23, "spl_object_id", &_8, 51, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_86$$23, &routeToIdx, &_87$$23, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 725);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&mostInnerArr, &_86$$23, PH_SEPARATE, "phalcon/Mvc/Router.zep", 725);
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
	zephir_read_property_cached(&_88, this_ptr, _zephir_prop_3, 292, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_88) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_90);
		zephir_string_to_char_array(&_90, &_88);
		_89 = &_90;
	} else {
		_89 = &_88;
	}
	zephir_is_iterable(_89, 0, "phalcon/Mvc/Router.zep", 739);
	if (Z_TYPE_P(_89) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_89), _92, _93, _91)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_93 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _93);
			} else {
				ZVAL_LONG(&innerKey, _92);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _91);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_95$$24);
				zephir_string_to_char_array(&_95$$24, &innerVal);
				_94$$24 = &_95$$24;
			} else {
				_94$$24 = &innerVal;
			}
			zephir_is_iterable(_94$$24, 0, "phalcon/Mvc/Router.zep", 736);
			if (Z_TYPE_P(_94$$24) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_94$$24), _96$$24)
				{
					ZEPHIR_INIT_NVAR(&scalarVal);
					ZVAL_COPY(&scalarVal, _96$$24);
					ZEPHIR_CALL_FUNCTION(&_98$$25, "spl_object_id", &_8, 51, &scalarVal);
					zephir_check_call_status();
					zephir_array_fetch(&_97$$25, &routeToIdx, &_98$$25, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 734);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&mostInnerArr, &_97$$25, PH_SEPARATE, "phalcon/Mvc/Router.zep", 734);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _94$$24, "rewind", NULL, 0);
				zephir_check_call_status();
				_100$$24 = 1;
				while (1) {
					if (_100$$24) {
						_100$$24 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _94$$24, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_99$$24, _94$$24, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_99$$24)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarVal, _94$$24, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_102$$26, "spl_object_id", &_8, 51, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_101$$26, &routeToIdx, &_102$$26, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 734);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_101$$26, PH_SEPARATE, "phalcon/Mvc/Router.zep", 734);
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
		ZEPHIR_CALL_METHOD(NULL, _89, "rewind", NULL, 0);
		zephir_check_call_status();
		_104 = 1;
		while (1) {
			if (_104) {
				_104 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _89, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_103, _89, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_103)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, _89, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, _89, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_106$$27);
					zephir_string_to_char_array(&_106$$27, &innerVal);
					_105$$27 = &_106$$27;
				} else {
					_105$$27 = &innerVal;
				}
				zephir_is_iterable(_105$$27, 0, "phalcon/Mvc/Router.zep", 736);
				if (Z_TYPE_P(_105$$27) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_105$$27), _107$$27)
					{
						ZEPHIR_INIT_NVAR(&scalarVal);
						ZVAL_COPY(&scalarVal, _107$$27);
						ZEPHIR_CALL_FUNCTION(&_109$$28, "spl_object_id", &_8, 51, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_108$$28, &routeToIdx, &_109$$28, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 734);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_108$$28, PH_SEPARATE, "phalcon/Mvc/Router.zep", 734);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _105$$27, "rewind", NULL, 0);
					zephir_check_call_status();
					_111$$27 = 1;
					while (1) {
						if (_111$$27) {
							_111$$27 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _105$$27, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_110$$27, _105$$27, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_110$$27)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarVal, _105$$27, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&_113$$29, "spl_object_id", &_8, 51, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_112$$29, &routeToIdx, &_113$$29, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 734);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&mostInnerArr, &_112$$29, PH_SEPARATE, "phalcon/Mvc/Router.zep", 734);
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
	zephir_read_property_cached(&_114, this_ptr, _zephir_prop_4, 293, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_114) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_116);
		zephir_string_to_char_array(&_116, &_114);
		_115 = &_116;
	} else {
		_115 = &_114;
	}
	zephir_is_iterable(_115, 0, "phalcon/Mvc/Router.zep", 751);
	if (Z_TYPE_P(_115) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_115), _118, _119, _117)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_119 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _119);
			} else {
				ZVAL_LONG(&innerKey, _118);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _117);
			ZEPHIR_INIT_NVAR(&_120$$30);
			array_init(&_120$$30);
			zephir_array_update_zval(&staticScalar, &innerKey, &_120$$30, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_122$$30);
				zephir_string_to_char_array(&_122$$30, &innerVal);
				_121$$30 = &_122$$30;
			} else {
				_121$$30 = &innerVal;
			}
			zephir_is_iterable(_121$$30, 0, "phalcon/Mvc/Router.zep", 749);
			if (Z_TYPE_P(_121$$30) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_121$$30), _124$$30, _125$$30, _123$$30)
				{
					ZEPHIR_INIT_NVAR(&scalarSubKey);
					if (_125$$30 != NULL) { 
						ZVAL_STR_COPY(&scalarSubKey, _125$$30);
					} else {
						ZVAL_LONG(&scalarSubKey, _124$$30);
					}
					ZEPHIR_INIT_NVAR(&mostInnerVal);
					ZVAL_COPY(&mostInnerVal, _123$$30);
					ZEPHIR_INIT_NVAR(&mostInnerArr);
					array_init(&mostInnerArr);
					if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_127$$31);
						zephir_string_to_char_array(&_127$$31, &mostInnerVal);
						_126$$31 = &_127$$31;
					} else {
						_126$$31 = &mostInnerVal;
					}
					zephir_is_iterable(_126$$31, 0, "phalcon/Mvc/Router.zep", 747);
					if (Z_TYPE_P(_126$$31) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_126$$31), _128$$31)
						{
							ZEPHIR_INIT_NVAR(&scalarVal);
							ZVAL_COPY(&scalarVal, _128$$31);
							ZEPHIR_CALL_FUNCTION(&_130$$32, "spl_object_id", &_8, 51, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_129$$32, &routeToIdx, &_130$$32, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&mostInnerArr, &_129$$32, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _126$$31, "rewind", NULL, 0);
						zephir_check_call_status();
						_132$$31 = 1;
						while (1) {
							if (_132$$31) {
								_132$$31 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _126$$31, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_131$$31, _126$$31, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_131$$31)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&scalarVal, _126$$31, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&_134$$33, "spl_object_id", &_8, 51, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_133$$33, &routeToIdx, &_134$$33, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&mostInnerArr, &_133$$33, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
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
				ZEPHIR_CALL_METHOD(NULL, _121$$30, "rewind", NULL, 0);
				zephir_check_call_status();
				_136$$30 = 1;
				while (1) {
					if (_136$$30) {
						_136$$30 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _121$$30, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_135$$30, _121$$30, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_135$$30)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarSubKey, _121$$30, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&mostInnerVal, _121$$30, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_138$$34);
							zephir_string_to_char_array(&_138$$34, &mostInnerVal);
							_137$$34 = &_138$$34;
						} else {
							_137$$34 = &mostInnerVal;
						}
						zephir_is_iterable(_137$$34, 0, "phalcon/Mvc/Router.zep", 747);
						if (Z_TYPE_P(_137$$34) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_137$$34), _139$$34)
							{
								ZEPHIR_INIT_NVAR(&scalarVal);
								ZVAL_COPY(&scalarVal, _139$$34);
								ZEPHIR_CALL_FUNCTION(&_141$$35, "spl_object_id", &_8, 51, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_140$$35, &routeToIdx, &_141$$35, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&mostInnerArr, &_140$$35, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _137$$34, "rewind", NULL, 0);
							zephir_check_call_status();
							_143$$34 = 1;
							while (1) {
								if (_143$$34) {
									_143$$34 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _137$$34, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_142$$34, _137$$34, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_142$$34)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarVal, _137$$34, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_145$$36, "spl_object_id", &_8, 51, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_144$$36, &routeToIdx, &_145$$36, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&mostInnerArr, &_144$$36, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
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
		ZEPHIR_CALL_METHOD(NULL, _115, "rewind", NULL, 0);
		zephir_check_call_status();
		_147 = 1;
		while (1) {
			if (_147) {
				_147 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _115, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_146, _115, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_146)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, _115, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, _115, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_148$$37);
				array_init(&_148$$37);
				zephir_array_update_zval(&staticScalar, &innerKey, &_148$$37, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_150$$37);
					zephir_string_to_char_array(&_150$$37, &innerVal);
					_149$$37 = &_150$$37;
				} else {
					_149$$37 = &innerVal;
				}
				zephir_is_iterable(_149$$37, 0, "phalcon/Mvc/Router.zep", 749);
				if (Z_TYPE_P(_149$$37) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_149$$37), _152$$37, _153$$37, _151$$37)
					{
						ZEPHIR_INIT_NVAR(&scalarSubKey);
						if (_153$$37 != NULL) { 
							ZVAL_STR_COPY(&scalarSubKey, _153$$37);
						} else {
							ZVAL_LONG(&scalarSubKey, _152$$37);
						}
						ZEPHIR_INIT_NVAR(&mostInnerVal);
						ZVAL_COPY(&mostInnerVal, _151$$37);
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_155$$38);
							zephir_string_to_char_array(&_155$$38, &mostInnerVal);
							_154$$38 = &_155$$38;
						} else {
							_154$$38 = &mostInnerVal;
						}
						zephir_is_iterable(_154$$38, 0, "phalcon/Mvc/Router.zep", 747);
						if (Z_TYPE_P(_154$$38) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_154$$38), _156$$38)
							{
								ZEPHIR_INIT_NVAR(&scalarVal);
								ZVAL_COPY(&scalarVal, _156$$38);
								ZEPHIR_CALL_FUNCTION(&_158$$39, "spl_object_id", &_8, 51, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_157$$39, &routeToIdx, &_158$$39, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&mostInnerArr, &_157$$39, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _154$$38, "rewind", NULL, 0);
							zephir_check_call_status();
							_160$$38 = 1;
							while (1) {
								if (_160$$38) {
									_160$$38 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _154$$38, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_159$$38, _154$$38, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_159$$38)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarVal, _154$$38, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_162$$40, "spl_object_id", &_8, 51, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_161$$40, &routeToIdx, &_162$$40, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&mostInnerArr, &_161$$40, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
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
					ZEPHIR_CALL_METHOD(NULL, _149$$37, "rewind", NULL, 0);
					zephir_check_call_status();
					_164$$37 = 1;
					while (1) {
						if (_164$$37) {
							_164$$37 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _149$$37, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_163$$37, _149$$37, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_163$$37)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarSubKey, _149$$37, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&mostInnerVal, _149$$37, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&mostInnerArr);
							array_init(&mostInnerArr);
							if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_166$$41);
								zephir_string_to_char_array(&_166$$41, &mostInnerVal);
								_165$$41 = &_166$$41;
							} else {
								_165$$41 = &mostInnerVal;
							}
							zephir_is_iterable(_165$$41, 0, "phalcon/Mvc/Router.zep", 747);
							if (Z_TYPE_P(_165$$41) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_165$$41), _167$$41)
								{
									ZEPHIR_INIT_NVAR(&scalarVal);
									ZVAL_COPY(&scalarVal, _167$$41);
									ZEPHIR_CALL_FUNCTION(&_169$$42, "spl_object_id", &_8, 51, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_168$$42, &routeToIdx, &_169$$42, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&mostInnerArr, &_168$$42, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _165$$41, "rewind", NULL, 0);
								zephir_check_call_status();
								_171$$41 = 1;
								while (1) {
									if (_171$$41) {
										_171$$41 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _165$$41, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_170$$41, _165$$41, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_170$$41)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&scalarVal, _165$$41, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_173$$43, "spl_object_id", &_8, 51, &scalarVal);
										zephir_check_call_status();
										zephir_array_fetch(&_172$$43, &routeToIdx, &_173$$43, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&mostInnerArr, &_172$$43, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
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
	zephir_memory_observe(&_174);
	zephir_read_property_cached(&_174, this_ptr, _zephir_prop_5, 294, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("staticShadowedByMethod"), &_174, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_174);
	zephir_read_property_cached(&_174, this_ptr, _zephir_prop_6, 295, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("hostnameByMethod"), &_174, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_174);
	zephir_read_property_cached(&_174, this_ptr, _zephir_prop_7, 296, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("hostnameLessByMethod"), &_174, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_174);
	zephir_read_property_cached(&_174, this_ptr, _zephir_prop_8, 297, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("combinedRegexByMethod"), &_174, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_174);
	zephir_read_property_cached(&_174, this_ptr, _zephir_prop_9, 298, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("combinedRegexDisabled"), &_174, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_174);
	zephir_read_property_cached(&_174, this_ptr, _zephir_prop_10, 299, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("combinedRegexMarkMap"), &_174, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_174);
	zephir_read_property_cached(&_174, this_ptr, _zephir_prop_11, 300, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("routeMeta"), &_174, PH_COPY | PH_SEPARATE);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	ZEPHIR_CALL_METHOD(&dump, this_ptr, "buildDispatcherDump", NULL, 0);
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
	ZEPHIR_CALL_FUNCTION(&_1, "getmypid", NULL, 268);
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
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "phpFilePutContents", NULL, 0, &tmpPath, &php);
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
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 7, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "phalcon/Mvc/Router.zep", 802);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_7, "rename", NULL, 269, &tmpPath, &path_zv);
	zephir_check_call_status();
	if (!(zephir_is_true(&_7))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "phpUnlink", NULL, 0, &tmpPath);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$4);
		object_init_ex(&_8$$4, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZEPHIR_CONCAT_SV(&_9$$4, "Failed to commit router cache: ", &path_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, &_8$$4, "__construct", NULL, 7, &_9$$4);
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
	zephir_array_update_string(return_value, SL("namespace"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 302, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("module"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 303, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("controller"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 304, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("action"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 305, PH_NOISY_CC);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("methodRoutesDirty", 17, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 290, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rebuildMethodIndex", NULL, 0);
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
	zend_bool _1$$3, _3$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 306, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 0)) {
		zephir_memory_observe(&url);
		_1$$3 = zephir_array_isset_string_fetch(&url, &_GET, SL("_url"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_1$$3) {
			if (!(ZEPHIR_IS_EMPTY(&url))) {
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "extractRealUri", &_2, 0, &url);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
	} else {
		ZEPHIR_OBS_NVAR(&url);
		_3$$6 = zephir_array_isset_string_fetch(&url, &_SERVER, SL("REQUEST_URI"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_3$$6) {
			if (!(ZEPHIR_IS_EMPTY(&url))) {
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "extractRealUri", &_2, 0, &url);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 307, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_fetch(&key, &_0, routeId, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_1, 289, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_3$$3);
		zephir_array_fetch(&_3$$3, &_2$$3, &key, PH_NOISY, "phalcon/Mvc/Router.zep", 969);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&_3$$3);
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 289, PH_NOISY_CC | PH_READONLY);
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
			ZEPHIR_CALL_METHOD(&localRouteId, &route, "getRouteId", NULL, 0);
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
		ZEPHIR_CALL_METHOD(NULL, _5, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _5, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, _5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, _5, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, _5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&localRouteId, &route, "getRouteId", NULL, 0);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 308, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_fetch(&key, &_0, &name_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_1, 289, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_3$$3);
		zephir_array_fetch(&_3$$3, &_2$$3, &key, PH_NOISY, "phalcon/Mvc/Router.zep", 992);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&_3$$3);
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 289, PH_NOISY_CC | PH_READONLY);
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
			ZEPHIR_CALL_METHOD(&routeName, &route, "getName", NULL, 0);
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
		ZEPHIR_CALL_METHOD(NULL, _5, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _5, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, _5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, _5, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, _5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&routeName, &route, "getName", NULL, 0);
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
	zend_ulong _70$$39, _84$$40, _122$$62, _150$$84, _170$$103, _212$$140;
	zend_bool _1, _10, _14, _15, _17, _19, _20, _22, _59, _60, _62, _63, _65, _12$$11, _25$$15, _26$$15, _29$$15, _31$$15, _32$$15, _35$$15, _36$$15, _39$$15, _52$$18, _47$$24, _55$$34, _109$$39, _74$$40, _97$$40, _88$$46, _89$$46, _90$$49, _91$$49, _93$$51, _94$$51, _100$$54, _101$$54, _102$$57, _103$$57, _105$$59, _106$$59, _112$$62, _135$$62, _126$$68, _127$$68, _128$$71, _129$$71, _131$$73, _132$$73, _138$$76, _139$$76, _140$$79, _141$$79, _143$$81, _144$$81, _193$$84, _152$$85, _157$$91, _160$$95, _182$$103, _174$$104, _175$$104, _176$$108, _178$$110, _179$$110, _185$$113, _186$$113, _187$$117, _189$$119, _190$$119, _194$$122, _199$$128, _202$$132, _224$$140, _216$$141, _217$$141, _218$$145, _220$$147, _221$$147, _227$$150, _228$$150, _229$$154, _231$$156, _232$$156, _240$$163, _241$$163, _242$$163, _243$$163, _244$$163;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_45 = NULL, *_49 = NULL, *_53 = NULL, *_57 = NULL, *_78 = NULL, *_87 = NULL, *_99 = NULL, *_116 = NULL, *_125 = NULL, *_137 = NULL, *_155 = NULL, *_159 = NULL, *_162 = NULL, *_164 = NULL, *_166 = NULL, *_173 = NULL, *_184 = NULL, *_197 = NULL, *_201 = NULL, *_204 = NULL, *_206 = NULL, *_208 = NULL, *_215 = NULL, *_226 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, __$true, __$false, __$null, action, beforeMatch, candidateMethod, candidateRoutes, container, controller, converter, converters, currentHostName, eventsManager, handledUri, hostname, matched, matches, matchPosition, module, notFoundPaths, params, paramsStr, part, parts, paths, pattern, position, realUri, regexHostName, request, requestMethod, route, routeFound, routeId, routeIdx, routeMeta, staticBeforeMatch, staticBucket, staticBucketMethod, staticHostname, staticHostRegex, staticMatched, staticRoute, strParams, vetoedRoutes, vnamespace, _0, _3, _4, _7, _8, _9, _13, _16, _18, _21, combinedChunks, combinedMarkMaps, combinedChunkIdx, combinedChunk, combinedMatchesLocal, combinedMarkLabel, combinedRouteIdx, combinedRoute, combinedRouteMeta, combinedBeforeMatch, combinedPaths, combinedConverters, combinedPart, combinedPosition, combinedMatchPosition, combinedConverter, _61, _64, _235, _236, _237, _238, _239, _248, _2$$5, _5$$8, _6$$9, _11$$11, _23$$15, _24$$15, _27$$15, _28$$15, _30$$15, _33$$15, _34$$15, _37$$15, _38$$15, _40$$18, _41$$18, *_42$$18, _43$$18, *_44$$18, _51$$18, _46$$23, _48$$27, _50$$28, _54$$33, _56$$37, _58$$38, _66$$39, *_67$$39, _68$$39, *_69$$39, _108$$39, _72$$40, _73$$40, _75$$40, _76$$40, *_81$$40, _82$$40, *_83$$40, _96$$40, _77$$44, _79$$43, _80$$45, _86$$47, _92$$50, _95$$52, _98$$55, _104$$58, _107$$60, _110$$62, _111$$62, _113$$62, _114$$62, *_119$$62, _120$$62, *_121$$62, _134$$62, _115$$66, _117$$65, _118$$67, _124$$69, _130$$72, _133$$74, _136$$77, _142$$80, _145$$82, _146$$84, *_147$$84, _148$$84, *_149$$84, _192$$84, _153$$85, _154$$85, _156$$90, _158$$93, _161$$97, _163$$99, _165$$101, *_167$$103, _168$$103, *_169$$103, _181$$103, _172$$105, _177$$109, _180$$111, _183$$114, _188$$118, _191$$120, _195$$122, _196$$122, _198$$127, _200$$130, _203$$134, _205$$136, _207$$138, *_209$$140, _210$$140, *_211$$140, _223$$140, _214$$142, _219$$146, _222$$148, _225$$151, _230$$155, _233$$157, _234$$161, _245$$169, _246$$171, _247$$173, _249$$174, _250$$174, _251$$174, _252$$174;
	zend_string *uri = NULL, *_71$$39, *_85$$40, *_123$$62, *_151$$84, *_171$$103, *_213$$140;
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
	ZVAL_UNDEF(&_61);
	ZVAL_UNDEF(&_64);
	ZVAL_UNDEF(&_235);
	ZVAL_UNDEF(&_236);
	ZVAL_UNDEF(&_237);
	ZVAL_UNDEF(&_238);
	ZVAL_UNDEF(&_239);
	ZVAL_UNDEF(&_248);
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
	ZVAL_UNDEF(&_51$$18);
	ZVAL_UNDEF(&_46$$23);
	ZVAL_UNDEF(&_48$$27);
	ZVAL_UNDEF(&_50$$28);
	ZVAL_UNDEF(&_54$$33);
	ZVAL_UNDEF(&_56$$37);
	ZVAL_UNDEF(&_58$$38);
	ZVAL_UNDEF(&_66$$39);
	ZVAL_UNDEF(&_68$$39);
	ZVAL_UNDEF(&_108$$39);
	ZVAL_UNDEF(&_72$$40);
	ZVAL_UNDEF(&_73$$40);
	ZVAL_UNDEF(&_75$$40);
	ZVAL_UNDEF(&_76$$40);
	ZVAL_UNDEF(&_82$$40);
	ZVAL_UNDEF(&_96$$40);
	ZVAL_UNDEF(&_77$$44);
	ZVAL_UNDEF(&_79$$43);
	ZVAL_UNDEF(&_80$$45);
	ZVAL_UNDEF(&_86$$47);
	ZVAL_UNDEF(&_92$$50);
	ZVAL_UNDEF(&_95$$52);
	ZVAL_UNDEF(&_98$$55);
	ZVAL_UNDEF(&_104$$58);
	ZVAL_UNDEF(&_107$$60);
	ZVAL_UNDEF(&_110$$62);
	ZVAL_UNDEF(&_111$$62);
	ZVAL_UNDEF(&_113$$62);
	ZVAL_UNDEF(&_114$$62);
	ZVAL_UNDEF(&_120$$62);
	ZVAL_UNDEF(&_134$$62);
	ZVAL_UNDEF(&_115$$66);
	ZVAL_UNDEF(&_117$$65);
	ZVAL_UNDEF(&_118$$67);
	ZVAL_UNDEF(&_124$$69);
	ZVAL_UNDEF(&_130$$72);
	ZVAL_UNDEF(&_133$$74);
	ZVAL_UNDEF(&_136$$77);
	ZVAL_UNDEF(&_142$$80);
	ZVAL_UNDEF(&_145$$82);
	ZVAL_UNDEF(&_146$$84);
	ZVAL_UNDEF(&_148$$84);
	ZVAL_UNDEF(&_192$$84);
	ZVAL_UNDEF(&_153$$85);
	ZVAL_UNDEF(&_154$$85);
	ZVAL_UNDEF(&_156$$90);
	ZVAL_UNDEF(&_158$$93);
	ZVAL_UNDEF(&_161$$97);
	ZVAL_UNDEF(&_163$$99);
	ZVAL_UNDEF(&_165$$101);
	ZVAL_UNDEF(&_168$$103);
	ZVAL_UNDEF(&_181$$103);
	ZVAL_UNDEF(&_172$$105);
	ZVAL_UNDEF(&_177$$109);
	ZVAL_UNDEF(&_180$$111);
	ZVAL_UNDEF(&_183$$114);
	ZVAL_UNDEF(&_188$$118);
	ZVAL_UNDEF(&_191$$120);
	ZVAL_UNDEF(&_195$$122);
	ZVAL_UNDEF(&_196$$122);
	ZVAL_UNDEF(&_198$$127);
	ZVAL_UNDEF(&_200$$130);
	ZVAL_UNDEF(&_203$$134);
	ZVAL_UNDEF(&_205$$136);
	ZVAL_UNDEF(&_207$$138);
	ZVAL_UNDEF(&_210$$140);
	ZVAL_UNDEF(&_223$$140);
	ZVAL_UNDEF(&_214$$142);
	ZVAL_UNDEF(&_219$$146);
	ZVAL_UNDEF(&_222$$148);
	ZVAL_UNDEF(&_225$$151);
	ZVAL_UNDEF(&_230$$155);
	ZVAL_UNDEF(&_233$$157);
	ZVAL_UNDEF(&_234$$161);
	ZVAL_UNDEF(&_245$$169);
	ZVAL_UNDEF(&_246$$171);
	ZVAL_UNDEF(&_247$$173);
	ZVAL_UNDEF(&_249$$174);
	ZVAL_UNDEF(&_250$$174);
	ZVAL_UNDEF(&_251$$174);
	ZVAL_UNDEF(&_252$$174);
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
		ZEPHIR_CALL_METHOD(&realUri, this_ptr, "getRewriteUri", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&realUri, this_ptr, "extractRealUri", NULL, 0, &uri_zv);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 309, PH_NOISY_CC | PH_READONLY);
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
	ZEPHIR_CPY_WRT(&eventsManager, &_4);
	if (Z_TYPE_P(&eventsManager) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_5$$8);
		ZVAL_STRING(&_5$$8, "router:beforeCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_5$$8, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_5, 314, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_4);
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_6$$9);
		object_init_ex(&_6$$9, phalcon_mvc_router_exceptions_requestserviceunavailable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_6$$9, "__construct", NULL, 270);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$9, "phalcon/Mvc/Router.zep", 1085);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "request");
	ZEPHIR_CALL_METHOD(&_7, &container, "get", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&request, &_7);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_6, 290, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_4)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rebuildMethodIndex", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&requestMethod, &request, "getMethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&candidateMethod, &requestMethod);
	ZEPHIR_INIT_VAR(&candidateRoutes);
	array_init(&candidateRoutes);
	ZEPHIR_OBS_NVAR(&candidateRoutes);
	zephir_read_property_cached(&_9, this_ptr, _zephir_prop_7, 292, PH_NOISY_CC | PH_READONLY);
	_10 = zephir_array_isset_fetch(&candidateRoutes, &_9, &requestMethod, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_10)) {
		ZEPHIR_INIT_NVAR(&candidateMethod);
		ZVAL_STRING(&candidateMethod, "*");
		ZEPHIR_OBS_NVAR(&candidateRoutes);
		zephir_read_property_cached(&_11$$11, this_ptr, _zephir_prop_7, 292, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_13, this_ptr, _zephir_prop_8, 295, PH_NOISY_CC | PH_READONLY);
	_14 = zephir_array_isset_value(&_13, &requestMethod);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_15 = _14;
	if (_15) {
		zephir_read_property_cached(&_16, this_ptr, _zephir_prop_8, 295, PH_NOISY_CC | PH_READONLY);
		_17 = zephir_isempty_dim(&_16, &requestMethod);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_15 = !(_17);
	}
	if (_15) {
		ZEPHIR_CALL_METHOD(&currentHostName, &request, "getHttpHost", NULL, 0);
		zephir_check_call_status();
	} else {
		zephir_read_property_cached(&_18, this_ptr, _zephir_prop_8, 295, PH_NOISY_CC | PH_READONLY);
		_19 = zephir_array_isset_value_string(&_18, SL("*"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_20 = _19;
		if (_20) {
			zephir_read_property_cached(&_21, this_ptr, _zephir_prop_8, 295, PH_NOISY_CC | PH_READONLY);
			_22 = zephir_isempty_dim_string(&_21, SL("*"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_20 = !(_22);
		}
		if (_20) {
			ZEPHIR_CALL_METHOD(&currentHostName, &request, "getHttpHost", NULL, 0);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_NULL) {
		ZEPHIR_INIT_VAR(&staticBucketMethod);
		ZVAL_NULL(&staticBucketMethod);
		zephir_read_property_cached(&_23$$15, this_ptr, _zephir_prop_9, 293, PH_NOISY_CC | PH_READONLY);
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
			zephir_read_property_cached(&_30$$15, this_ptr, _zephir_prop_7, 292, PH_NOISY_CC | PH_READONLY);
			_31$$15 = zephir_array_isset_value(&_30$$15, &requestMethod);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_32$$15 = !(_31$$15);
			if (_32$$15) {
				zephir_read_property_cached(&_33$$15, this_ptr, _zephir_prop_9, 293, PH_NOISY_CC | PH_READONLY);
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
					ZEPHIR_CALL_METHOD(&staticHostname, &staticRoute, "getHostName", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&staticHostname) != IS_NULL) {
						if (Z_TYPE_P(&currentHostName) == IS_NULL) {
							ZEPHIR_CALL_METHOD(&currentHostName, &request, "getHttpHost", &_45, 0);
							zephir_check_call_status();
						}
						if (!(zephir_is_true(&currentHostName))) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&staticHostRegex, &staticRoute, "getCompiledHostName", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&staticHostRegex) != IS_NULL) {
							ZEPHIR_INIT_NVAR(&_46$$23);
							ZEPHIR_INIT_NVAR(&staticMatched);
							zephir_preg_match(&staticMatched, &staticHostRegex, &currentHostName, &_46$$23, 0, 0 , 0 );
						} else {
							_47$$24 = ZEPHIR_IS_EQUAL(&currentHostName, &staticHostname);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&staticMatched);
							ZVAL_BOOL(&staticMatched, _47$$24);
						}
						if (!(zephir_is_true(&staticMatched))) {
							continue;
						}
					}
					ZEPHIR_CALL_METHOD(&staticBeforeMatch, &staticRoute, "getBeforeMatch", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&staticBeforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&staticBeforeMatch)))) {
							ZEPHIR_INIT_NVAR(&_48$$27);
							object_init_ex(&_48$$27, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD(NULL, &_48$$27, "__construct", &_49, 271);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_48$$27, "phalcon/Mvc/Router.zep", 1186);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &staticBeforeMatch, NULL, 0, &handledUri, &staticRoute, this_ptr);
						zephir_check_call_status();
						if (!(zephir_is_true(&routeFound))) {
							ZEPHIR_CALL_METHOD(&_50$$28, &staticRoute, "getRouteId", NULL, 0);
							zephir_check_call_status();
							zephir_array_update_zval(&vetoedRoutes, &_50$$28, &__$true, PH_COPY | PH_SEPARATE);
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
					ZEPHIR_CALL_METHOD(&parts, &staticRoute, "getPaths", NULL, 0);
					zephir_check_call_status();
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 312, &staticRoute);
					break;
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _42$$18, "rewind", NULL, 0);
				zephir_check_call_status();
				_52$$18 = 1;
				while (1) {
					if (_52$$18) {
						_52$$18 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _42$$18, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_51$$18, _42$$18, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_51$$18)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&staticRoute, _42$$18, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&staticHostname, &staticRoute, "getHostName", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&staticHostname) != IS_NULL) {
							if (Z_TYPE_P(&currentHostName) == IS_NULL) {
								ZEPHIR_CALL_METHOD(&currentHostName, &request, "getHttpHost", &_53, 0);
								zephir_check_call_status();
							}
							if (!(zephir_is_true(&currentHostName))) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&staticHostRegex, &staticRoute, "getCompiledHostName", NULL, 0);
							zephir_check_call_status();
							if (Z_TYPE_P(&staticHostRegex) != IS_NULL) {
								ZEPHIR_INIT_NVAR(&_54$$33);
								ZEPHIR_INIT_NVAR(&staticMatched);
								zephir_preg_match(&staticMatched, &staticHostRegex, &currentHostName, &_54$$33, 0, 0 , 0 );
							} else {
								_55$$34 = ZEPHIR_IS_EQUAL(&currentHostName, &staticHostname);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&staticMatched);
								ZVAL_BOOL(&staticMatched, _55$$34);
							}
							if (!(zephir_is_true(&staticMatched))) {
								continue;
							}
						}
						ZEPHIR_CALL_METHOD(&staticBeforeMatch, &staticRoute, "getBeforeMatch", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&staticBeforeMatch) != IS_NULL) {
							if (UNEXPECTED(!(zephir_is_callable(&staticBeforeMatch)))) {
								ZEPHIR_INIT_NVAR(&_56$$37);
								object_init_ex(&_56$$37, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
								ZEPHIR_CALL_METHOD(NULL, &_56$$37, "__construct", &_57, 271);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_56$$37, "phalcon/Mvc/Router.zep", 1186);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &staticBeforeMatch, NULL, 0, &handledUri, &staticRoute, this_ptr);
							zephir_check_call_status();
							if (!(zephir_is_true(&routeFound))) {
								ZEPHIR_CALL_METHOD(&_58$$38, &staticRoute, "getRouteId", NULL, 0);
								zephir_check_call_status();
								zephir_array_update_zval(&vetoedRoutes, &_58$$38, &__$true, PH_COPY | PH_SEPARATE);
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
						ZEPHIR_CALL_METHOD(&parts, &staticRoute, "getPaths", NULL, 0);
						zephir_check_call_status();
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 312, &staticRoute);
						break;
				}
			}
			ZEPHIR_INIT_NVAR(&staticRoute);
		}
	}
	_59 = !zephir_is_true(&routeFound);
	if (_59) {
		_59 = Z_TYPE_P(&eventsManager) == IS_NULL;
	}
	_60 = _59;
	if (_60) {
		zephir_read_property_cached(&_61, this_ptr, _zephir_prop_11, 298, PH_NOISY_CC | PH_READONLY);
		_62 = zephir_array_isset_value(&_61, &candidateMethod);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_60 = !(_62);
	}
	_63 = _60;
	if (_63) {
		zephir_memory_observe(&combinedChunks);
		zephir_read_property_cached(&_64, this_ptr, _zephir_prop_12, 297, PH_NOISY_CC | PH_READONLY);
		_65 = zephir_array_isset_fetch(&combinedChunks, &_64, &candidateMethod, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_63 = _65;
	}
	if (_63) {
		zephir_read_property_cached(&_66$$39, this_ptr, _zephir_prop_13, 299, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&combinedMarkMaps);
		zephir_array_fetch(&combinedMarkMaps, &_66$$39, &candidateMethod, PH_NOISY, "phalcon/Mvc/Router.zep", 1229);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&combinedChunks) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_68$$39);
			zephir_string_to_char_array(&_68$$39, &combinedChunks);
			_67$$39 = &_68$$39;
		} else {
			_67$$39 = &combinedChunks;
		}
		zephir_is_iterable(_67$$39, 0, "phalcon/Mvc/Router.zep", 1307);
		if (Z_TYPE_P(_67$$39) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_67$$39), _70$$39, _71$$39, _69$$39)
			{
				ZEPHIR_INIT_NVAR(&combinedChunkIdx);
				if (_71$$39 != NULL) { 
					ZVAL_STR_COPY(&combinedChunkIdx, _71$$39);
				} else {
					ZVAL_LONG(&combinedChunkIdx, _70$$39);
				}
				ZEPHIR_INIT_NVAR(&combinedChunk);
				ZVAL_COPY(&combinedChunk, _69$$39);
				ZEPHIR_INIT_NVAR(&combinedMatchesLocal);
				array_init(&combinedMatchesLocal);
				ZEPHIR_INIT_NVAR(&_72$$40);
				zephir_preg_match(&_72$$40, &combinedChunk, &handledUri, &combinedMatchesLocal, 0, 0 , 0 );
				if (!(zephir_is_true(&_72$$40))) {
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
				ZEPHIR_OBS_NVAR(&_73$$40);
				zephir_array_fetch(&_73$$40, &combinedMarkMaps, &combinedChunkIdx, 0, "phalcon/Mvc/Router.zep", 1246);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_74$$40 = zephir_array_isset_fetch(&combinedRouteIdx, &_73$$40, &combinedMarkLabel, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_74$$40)) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&combinedRoute);
				zephir_array_fetch(&combinedRoute, &candidateRoutes, &combinedRouteIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1250);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property_cached(&_75$$40, this_ptr, _zephir_prop_14, 300, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&combinedRouteMeta);
				ZEPHIR_CALL_METHOD(&_76$$40, &combinedRoute, "getRouteId", NULL, 0);
				zephir_check_call_status();
				zephir_array_fetch(&combinedRouteMeta, &_75$$40, &_76$$40, PH_NOISY, "phalcon/Mvc/Router.zep", 1251);
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
						ZEPHIR_INIT_NVAR(&_77$$44);
						object_init_ex(&_77$$44, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
						ZEPHIR_CALL_METHOD(NULL, &_77$$44, "__construct", &_78, 271);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_77$$44, "phalcon/Mvc/Router.zep", 1257);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_ZVAL_FUNCTION(&_79$$43, &combinedBeforeMatch, NULL, 0, &handledUri, &combinedRoute, this_ptr);
					zephir_check_call_status();
					if (!(zephir_is_true(&_79$$43))) {
						ZEPHIR_CALL_METHOD(&_80$$45, &combinedRoute, "getRouteId", NULL, 0);
						zephir_check_call_status();
						zephir_array_update_zval(&vetoedRoutes, &_80$$45, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						break;
					}
				}
				ZEPHIR_CALL_METHOD(&combinedPaths, &combinedRoute, "getPaths", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&parts, &combinedPaths);
				ZEPHIR_CPY_WRT(&matches, &combinedMatchesLocal);
				ZEPHIR_CALL_METHOD(&combinedConverters, &combinedRoute, "getConverters", NULL, 0);
				zephir_check_call_status();
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 310, &combinedMatchesLocal);
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 312, &combinedRoute);
				ZEPHIR_INIT_NVAR(&routeFound);
				ZVAL_BOOL(&routeFound, 1);
				if (Z_TYPE_P(&combinedPaths) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_82$$40);
					zephir_string_to_char_array(&_82$$40, &combinedPaths);
					_81$$40 = &_82$$40;
				} else {
					_81$$40 = &combinedPaths;
				}
				zephir_is_iterable(_81$$40, 0, "phalcon/Mvc/Router.zep", 1305);
				if (Z_TYPE_P(_81$$40) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_81$$40), _84$$40, _85$$40, _83$$40)
					{
						ZEPHIR_INIT_NVAR(&combinedPart);
						if (_85$$40 != NULL) { 
							ZVAL_STR_COPY(&combinedPart, _85$$40);
						} else {
							ZVAL_LONG(&combinedPart, _84$$40);
						}
						ZEPHIR_INIT_NVAR(&combinedPosition);
						ZVAL_COPY(&combinedPosition, _83$$40);
						if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
							ZEPHIR_INIT_NVAR(&_86$$47);
							object_init_ex(&_86$$47, phalcon_mvc_router_exceptions_wrongpathskey_ce);
							ZEPHIR_CALL_METHOD(NULL, &_86$$47, "__construct", &_87, 272, &combinedPart);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_86$$47, "phalcon/Mvc/Router.zep", 1282);
							ZEPHIR_MM_RESTORE();
							return;
						}
						_88$$46 = Z_TYPE_P(&combinedPosition) != IS_STRING;
						if (_88$$46) {
							_88$$46 = Z_TYPE_P(&combinedPosition) != IS_LONG;
						}
						if (_88$$46) {
							continue;
						}
						ZEPHIR_OBS_NVAR(&combinedMatchPosition);
						_89$$46 = zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_89$$46) {
							_90$$49 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
							if (_90$$49) {
								ZEPHIR_OBS_NVAR(&combinedConverter);
								_91$$49 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								_90$$49 = _91$$49;
							}
							if (_90$$49) {
								ZEPHIR_CALL_ZVAL_FUNCTION(&_92$$50, &combinedConverter, NULL, 0, &combinedMatchPosition);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, &combinedPart, &_92$$50, PH_COPY | PH_SEPARATE);
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
							_93$$51 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
							if (_93$$51) {
								ZEPHIR_OBS_NVAR(&combinedConverter);
								_94$$51 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								_93$$51 = _94$$51;
							}
							if (_93$$51) {
								ZEPHIR_CALL_ZVAL_FUNCTION(&_95$$52, &combinedConverter, NULL, 0, &combinedPosition);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, &combinedPart, &_95$$52, PH_COPY | PH_SEPARATE);
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
					ZEPHIR_CALL_METHOD(NULL, _81$$40, "rewind", NULL, 0);
					zephir_check_call_status();
					_97$$40 = 1;
					while (1) {
						if (_97$$40) {
							_97$$40 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _81$$40, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_96$$40, _81$$40, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_96$$40)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&combinedPart, _81$$40, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&combinedPosition, _81$$40, "current", NULL, 0);
						zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
								ZEPHIR_INIT_NVAR(&_98$$55);
								object_init_ex(&_98$$55, phalcon_mvc_router_exceptions_wrongpathskey_ce);
								ZEPHIR_CALL_METHOD(NULL, &_98$$55, "__construct", &_99, 272, &combinedPart);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_98$$55, "phalcon/Mvc/Router.zep", 1282);
								ZEPHIR_MM_RESTORE();
								return;
							}
							_100$$54 = Z_TYPE_P(&combinedPosition) != IS_STRING;
							if (_100$$54) {
								_100$$54 = Z_TYPE_P(&combinedPosition) != IS_LONG;
							}
							if (_100$$54) {
								continue;
							}
							ZEPHIR_OBS_NVAR(&combinedMatchPosition);
							_101$$54 = zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_101$$54) {
								_102$$57 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_102$$57) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_103$$57 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_102$$57 = _103$$57;
								}
								if (_102$$57) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_104$$58, &combinedConverter, NULL, 0, &combinedMatchPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_104$$58, PH_COPY | PH_SEPARATE);
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
								_105$$59 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_105$$59) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_106$$59 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_105$$59 = _106$$59;
								}
								if (_105$$59) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_107$$60, &combinedConverter, NULL, 0, &combinedPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_107$$60, PH_COPY | PH_SEPARATE);
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
			ZEPHIR_CALL_METHOD(NULL, _67$$39, "rewind", NULL, 0);
			zephir_check_call_status();
			_109$$39 = 1;
			while (1) {
				if (_109$$39) {
					_109$$39 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _67$$39, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_108$$39, _67$$39, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_108$$39)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&combinedChunkIdx, _67$$39, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&combinedChunk, _67$$39, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&combinedMatchesLocal);
					array_init(&combinedMatchesLocal);
					ZEPHIR_INIT_NVAR(&_110$$62);
					zephir_preg_match(&_110$$62, &combinedChunk, &handledUri, &combinedMatchesLocal, 0, 0 , 0 );
					if (!(zephir_is_true(&_110$$62))) {
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
					ZEPHIR_OBS_NVAR(&_111$$62);
					zephir_array_fetch(&_111$$62, &combinedMarkMaps, &combinedChunkIdx, 0, "phalcon/Mvc/Router.zep", 1246);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_112$$62 = zephir_array_isset_fetch(&combinedRouteIdx, &_111$$62, &combinedMarkLabel, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_112$$62)) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&combinedRoute);
					zephir_array_fetch(&combinedRoute, &candidateRoutes, &combinedRouteIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1250);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property_cached(&_113$$62, this_ptr, _zephir_prop_14, 300, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&combinedRouteMeta);
					ZEPHIR_CALL_METHOD(&_114$$62, &combinedRoute, "getRouteId", NULL, 0);
					zephir_check_call_status();
					zephir_array_fetch(&combinedRouteMeta, &_113$$62, &_114$$62, PH_NOISY, "phalcon/Mvc/Router.zep", 1251);
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
							ZEPHIR_INIT_NVAR(&_115$$66);
							object_init_ex(&_115$$66, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD(NULL, &_115$$66, "__construct", &_116, 271);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_115$$66, "phalcon/Mvc/Router.zep", 1257);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_ZVAL_FUNCTION(&_117$$65, &combinedBeforeMatch, NULL, 0, &handledUri, &combinedRoute, this_ptr);
						zephir_check_call_status();
						if (!(zephir_is_true(&_117$$65))) {
							ZEPHIR_CALL_METHOD(&_118$$67, &combinedRoute, "getRouteId", NULL, 0);
							zephir_check_call_status();
							zephir_array_update_zval(&vetoedRoutes, &_118$$67, &__$true, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							break;
						}
					}
					ZEPHIR_CALL_METHOD(&combinedPaths, &combinedRoute, "getPaths", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&parts, &combinedPaths);
					ZEPHIR_CPY_WRT(&matches, &combinedMatchesLocal);
					ZEPHIR_CALL_METHOD(&combinedConverters, &combinedRoute, "getConverters", NULL, 0);
					zephir_check_call_status();
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 310, &combinedMatchesLocal);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 312, &combinedRoute);
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, 1);
					if (Z_TYPE_P(&combinedPaths) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_120$$62);
						zephir_string_to_char_array(&_120$$62, &combinedPaths);
						_119$$62 = &_120$$62;
					} else {
						_119$$62 = &combinedPaths;
					}
					zephir_is_iterable(_119$$62, 0, "phalcon/Mvc/Router.zep", 1305);
					if (Z_TYPE_P(_119$$62) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_119$$62), _122$$62, _123$$62, _121$$62)
						{
							ZEPHIR_INIT_NVAR(&combinedPart);
							if (_123$$62 != NULL) { 
								ZVAL_STR_COPY(&combinedPart, _123$$62);
							} else {
								ZVAL_LONG(&combinedPart, _122$$62);
							}
							ZEPHIR_INIT_NVAR(&combinedPosition);
							ZVAL_COPY(&combinedPosition, _121$$62);
							if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
								ZEPHIR_INIT_NVAR(&_124$$69);
								object_init_ex(&_124$$69, phalcon_mvc_router_exceptions_wrongpathskey_ce);
								ZEPHIR_CALL_METHOD(NULL, &_124$$69, "__construct", &_125, 272, &combinedPart);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_124$$69, "phalcon/Mvc/Router.zep", 1282);
								ZEPHIR_MM_RESTORE();
								return;
							}
							_126$$68 = Z_TYPE_P(&combinedPosition) != IS_STRING;
							if (_126$$68) {
								_126$$68 = Z_TYPE_P(&combinedPosition) != IS_LONG;
							}
							if (_126$$68) {
								continue;
							}
							ZEPHIR_OBS_NVAR(&combinedMatchPosition);
							_127$$68 = zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_127$$68) {
								_128$$71 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_128$$71) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_129$$71 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_128$$71 = _129$$71;
								}
								if (_128$$71) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_130$$72, &combinedConverter, NULL, 0, &combinedMatchPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_130$$72, PH_COPY | PH_SEPARATE);
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
								_131$$73 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_131$$73) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_132$$73 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_131$$73 = _132$$73;
								}
								if (_131$$73) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_133$$74, &combinedConverter, NULL, 0, &combinedPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_133$$74, PH_COPY | PH_SEPARATE);
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
						ZEPHIR_CALL_METHOD(NULL, _119$$62, "rewind", NULL, 0);
						zephir_check_call_status();
						_135$$62 = 1;
						while (1) {
							if (_135$$62) {
								_135$$62 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _119$$62, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_134$$62, _119$$62, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_134$$62)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&combinedPart, _119$$62, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&combinedPosition, _119$$62, "current", NULL, 0);
							zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
									ZEPHIR_INIT_NVAR(&_136$$77);
									object_init_ex(&_136$$77, phalcon_mvc_router_exceptions_wrongpathskey_ce);
									ZEPHIR_CALL_METHOD(NULL, &_136$$77, "__construct", &_137, 272, &combinedPart);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_136$$77, "phalcon/Mvc/Router.zep", 1282);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_138$$76 = Z_TYPE_P(&combinedPosition) != IS_STRING;
								if (_138$$76) {
									_138$$76 = Z_TYPE_P(&combinedPosition) != IS_LONG;
								}
								if (_138$$76) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&combinedMatchPosition);
								_139$$76 = zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_139$$76) {
									_140$$79 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
									if (_140$$79) {
										ZEPHIR_OBS_NVAR(&combinedConverter);
										_141$$79 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										_140$$79 = _141$$79;
									}
									if (_140$$79) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_142$$80, &combinedConverter, NULL, 0, &combinedMatchPosition);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &combinedPart, &_142$$80, PH_COPY | PH_SEPARATE);
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
									_143$$81 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
									if (_143$$81) {
										ZEPHIR_OBS_NVAR(&combinedConverter);
										_144$$81 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										_143$$81 = _144$$81;
									}
									if (_143$$81) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_145$$82, &combinedConverter, NULL, 0, &combinedPosition);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &combinedPart, &_145$$82, PH_COPY | PH_SEPARATE);
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
		ZEPHIR_CALL_FUNCTION(&_146$$84, "array_reverse", NULL, 273, &candidateRoutes, &__$true);
		zephir_check_call_status();
		if (Z_TYPE_P(&_146$$84) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_148$$84);
			zephir_string_to_char_array(&_148$$84, &_146$$84);
			_147$$84 = &_148$$84;
		} else {
			_147$$84 = &_146$$84;
		}
		zephir_is_iterable(_147$$84, 0, "phalcon/Mvc/Router.zep", 1477);
		if (Z_TYPE_P(_147$$84) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_147$$84), _150$$84, _151$$84, _149$$84)
			{
				ZEPHIR_INIT_NVAR(&routeIdx);
				if (_151$$84 != NULL) { 
					ZVAL_STR_COPY(&routeIdx, _151$$84);
				} else {
					ZVAL_LONG(&routeIdx, _150$$84);
				}
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _149$$84);
				ZEPHIR_CALL_METHOD(&routeId, &route, "getRouteId", NULL, 0);
				zephir_check_call_status();
				_152$$85 = zephir_array_isset_value(&vetoedRoutes, &routeId);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_152$$85) {
					continue;
				}
				zephir_read_property_cached(&_153$$85, this_ptr, _zephir_prop_14, 300, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&_154$$85);
				zephir_array_fetch(&_154$$85, &_153$$85, &routeId, PH_NOISY, "phalcon/Mvc/Router.zep", 1325);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&routeMeta, &_154$$85);
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
						ZEPHIR_CALL_METHOD(&currentHostName, &request, "getHttpHost", &_155, 0);
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
						ZEPHIR_INIT_NVAR(&_156$$90);
						ZEPHIR_INIT_NVAR(&matched);
						zephir_preg_match(&matched, &regexHostName, &currentHostName, &_156$$90, 0, 0 , 0 );
					} else {
						_157$$91 = ZEPHIR_IS_EQUAL(&currentHostName, &hostname);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&matched);
						ZVAL_BOOL(&matched, _157$$91);
					}
					if (!(zephir_is_true(&matched))) {
						continue;
					}
				}
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_158$$93);
					ZVAL_STRING(&_158$$93, "router:beforeCheckRoute");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_159, 0, &_158$$93, this_ptr, &route);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&pattern);
				zephir_array_fetch_string(&pattern, &routeMeta, SL("pattern"), PH_NOISY, "phalcon/Mvc/Router.zep", 1372);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_154$$85);
				zephir_array_fetch_string(&_154$$85, &routeMeta, SL("isRegex"), PH_NOISY, "phalcon/Mvc/Router.zep", 1374);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&_154$$85)) {
					ZEPHIR_INIT_NVAR(&routeFound);
					zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
				} else {
					_160$$95 = ZEPHIR_IS_EQUAL(&pattern, &handledUri);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, _160$$95);
				}
				if (zephir_is_true(&routeFound)) {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_161$$97);
						ZVAL_STRING(&_161$$97, "router:matchedRoute");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_162, 0, &_161$$97, this_ptr, &route);
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
							ZEPHIR_INIT_NVAR(&_163$$99);
							object_init_ex(&_163$$99, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD(NULL, &_163$$99, "__construct", &_164, 271);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_163$$99, "phalcon/Mvc/Router.zep", 1394);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &beforeMatch, NULL, 0, &handledUri, &route, this_ptr);
						zephir_check_call_status();
					}
				} else {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_165$$101);
						ZVAL_STRING(&_165$$101, "router:notMatchedRoute");
						ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_166, 0, &_165$$101, this_ptr, &route);
						zephir_check_call_status();
					}
				}
				if (zephir_is_true(&routeFound)) {
					ZEPHIR_CALL_METHOD(&paths, &route, "getPaths", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&parts, &paths);
					if (Z_TYPE_P(&matches) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD(&converters, &route, "getConverters", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&paths) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_168$$103);
							zephir_string_to_char_array(&_168$$103, &paths);
							_167$$103 = &_168$$103;
						} else {
							_167$$103 = &paths;
						}
						zephir_is_iterable(_167$$103, 0, "phalcon/Mvc/Router.zep", 1469);
						if (Z_TYPE_P(_167$$103) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_167$$103), _170$$103, _171$$103, _169$$103)
							{
								ZEPHIR_INIT_NVAR(&part);
								if (_171$$103 != NULL) { 
									ZVAL_STR_COPY(&part, _171$$103);
								} else {
									ZVAL_LONG(&part, _170$$103);
								}
								ZEPHIR_INIT_NVAR(&position);
								ZVAL_COPY(&position, _169$$103);
								if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
									ZEPHIR_INIT_NVAR(&_172$$105);
									object_init_ex(&_172$$105, phalcon_mvc_router_exceptions_wrongpathskey_ce);
									ZEPHIR_CALL_METHOD(NULL, &_172$$105, "__construct", &_173, 272, &part);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_172$$105, "phalcon/Mvc/Router.zep", 1427);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_174$$104 = Z_TYPE_P(&position) != IS_STRING;
								if (_174$$104) {
									_174$$104 = Z_TYPE_P(&position) != IS_LONG;
								}
								if (_174$$104) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&matchPosition);
								_175$$104 = zephir_array_isset_fetch(&matchPosition, &matches, &position, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_175$$104) {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										_176$$108 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (_176$$108) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_177$$109, &converter, NULL, 0, &matchPosition);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_177$$109, PH_COPY | PH_SEPARATE);
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
									_178$$110 = Z_TYPE_P(&converters) == IS_ARRAY;
									if (_178$$110) {
										ZEPHIR_OBS_NVAR(&converter);
										_179$$110 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										_178$$110 = _179$$110;
									}
									if (_178$$110) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_180$$111, &converter, NULL, 0, &position);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_180$$111, PH_COPY | PH_SEPARATE);
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
							ZEPHIR_CALL_METHOD(NULL, _167$$103, "rewind", NULL, 0);
							zephir_check_call_status();
							_182$$103 = 1;
							while (1) {
								if (_182$$103) {
									_182$$103 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _167$$103, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_181$$103, _167$$103, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_181$$103)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&part, _167$$103, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&position, _167$$103, "current", NULL, 0);
								zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
										ZEPHIR_INIT_NVAR(&_183$$114);
										object_init_ex(&_183$$114, phalcon_mvc_router_exceptions_wrongpathskey_ce);
										ZEPHIR_CALL_METHOD(NULL, &_183$$114, "__construct", &_184, 272, &part);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_183$$114, "phalcon/Mvc/Router.zep", 1427);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_185$$113 = Z_TYPE_P(&position) != IS_STRING;
									if (_185$$113) {
										_185$$113 = Z_TYPE_P(&position) != IS_LONG;
									}
									if (_185$$113) {
										continue;
									}
									ZEPHIR_OBS_NVAR(&matchPosition);
									_186$$113 = zephir_array_isset_fetch(&matchPosition, &matches, &position, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_186$$113) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											_187$$117 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											if (_187$$117) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_188$$118, &converter, NULL, 0, &matchPosition);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_188$$118, PH_COPY | PH_SEPARATE);
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
										_189$$119 = Z_TYPE_P(&converters) == IS_ARRAY;
										if (_189$$119) {
											ZEPHIR_OBS_NVAR(&converter);
											_190$$119 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											_189$$119 = _190$$119;
										}
										if (_189$$119) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_191$$120, &converter, NULL, 0, &position);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_191$$120, PH_COPY | PH_SEPARATE);
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
			ZEPHIR_CALL_METHOD(NULL, _147$$84, "rewind", NULL, 0);
			zephir_check_call_status();
			_193$$84 = 1;
			while (1) {
				if (_193$$84) {
					_193$$84 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _147$$84, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_192$$84, _147$$84, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_192$$84)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&routeIdx, _147$$84, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&route, _147$$84, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&routeId, &route, "getRouteId", NULL, 0);
					zephir_check_call_status();
					_194$$122 = zephir_array_isset_value(&vetoedRoutes, &routeId);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_194$$122) {
						continue;
					}
					zephir_read_property_cached(&_195$$122, this_ptr, _zephir_prop_14, 300, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_196$$122);
					zephir_array_fetch(&_196$$122, &_195$$122, &routeId, PH_NOISY, "phalcon/Mvc/Router.zep", 1325);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&routeMeta, &_196$$122);
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
							ZEPHIR_CALL_METHOD(&currentHostName, &request, "getHttpHost", &_197, 0);
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
							ZEPHIR_INIT_NVAR(&_198$$127);
							ZEPHIR_INIT_NVAR(&matched);
							zephir_preg_match(&matched, &regexHostName, &currentHostName, &_198$$127, 0, 0 , 0 );
						} else {
							_199$$128 = ZEPHIR_IS_EQUAL(&currentHostName, &hostname);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&matched);
							ZVAL_BOOL(&matched, _199$$128);
						}
						if (!(zephir_is_true(&matched))) {
							continue;
						}
					}
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_200$$130);
						ZVAL_STRING(&_200$$130, "router:beforeCheckRoute");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_201, 0, &_200$$130, this_ptr, &route);
						zephir_check_call_status();
					}
					ZEPHIR_OBS_NVAR(&pattern);
					zephir_array_fetch_string(&pattern, &routeMeta, SL("pattern"), PH_NOISY, "phalcon/Mvc/Router.zep", 1372);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_196$$122);
					zephir_array_fetch_string(&_196$$122, &routeMeta, SL("isRegex"), PH_NOISY, "phalcon/Mvc/Router.zep", 1374);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_is_true(&_196$$122)) {
						ZEPHIR_INIT_NVAR(&routeFound);
						zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
					} else {
						_202$$132 = ZEPHIR_IS_EQUAL(&pattern, &handledUri);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&routeFound);
						ZVAL_BOOL(&routeFound, _202$$132);
					}
					if (zephir_is_true(&routeFound)) {
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_203$$134);
							ZVAL_STRING(&_203$$134, "router:matchedRoute");
							ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_204, 0, &_203$$134, this_ptr, &route);
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
								ZEPHIR_INIT_NVAR(&_205$$136);
								object_init_ex(&_205$$136, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
								ZEPHIR_CALL_METHOD(NULL, &_205$$136, "__construct", &_206, 271);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_205$$136, "phalcon/Mvc/Router.zep", 1394);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &beforeMatch, NULL, 0, &handledUri, &route, this_ptr);
							zephir_check_call_status();
						}
					} else {
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_207$$138);
							ZVAL_STRING(&_207$$138, "router:notMatchedRoute");
							ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_208, 0, &_207$$138, this_ptr, &route);
							zephir_check_call_status();
						}
					}
					if (zephir_is_true(&routeFound)) {
						ZEPHIR_CALL_METHOD(&paths, &route, "getPaths", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&parts, &paths);
						if (Z_TYPE_P(&matches) == IS_ARRAY) {
							ZEPHIR_CALL_METHOD(&converters, &route, "getConverters", NULL, 0);
							zephir_check_call_status();
							if (Z_TYPE_P(&paths) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_210$$140);
								zephir_string_to_char_array(&_210$$140, &paths);
								_209$$140 = &_210$$140;
							} else {
								_209$$140 = &paths;
							}
							zephir_is_iterable(_209$$140, 0, "phalcon/Mvc/Router.zep", 1469);
							if (Z_TYPE_P(_209$$140) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_209$$140), _212$$140, _213$$140, _211$$140)
								{
									ZEPHIR_INIT_NVAR(&part);
									if (_213$$140 != NULL) { 
										ZVAL_STR_COPY(&part, _213$$140);
									} else {
										ZVAL_LONG(&part, _212$$140);
									}
									ZEPHIR_INIT_NVAR(&position);
									ZVAL_COPY(&position, _211$$140);
									if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
										ZEPHIR_INIT_NVAR(&_214$$142);
										object_init_ex(&_214$$142, phalcon_mvc_router_exceptions_wrongpathskey_ce);
										ZEPHIR_CALL_METHOD(NULL, &_214$$142, "__construct", &_215, 272, &part);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_214$$142, "phalcon/Mvc/Router.zep", 1427);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_216$$141 = Z_TYPE_P(&position) != IS_STRING;
									if (_216$$141) {
										_216$$141 = Z_TYPE_P(&position) != IS_LONG;
									}
									if (_216$$141) {
										continue;
									}
									ZEPHIR_OBS_NVAR(&matchPosition);
									_217$$141 = zephir_array_isset_fetch(&matchPosition, &matches, &position, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_217$$141) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											_218$$145 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											if (_218$$145) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_219$$146, &converter, NULL, 0, &matchPosition);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_219$$146, PH_COPY | PH_SEPARATE);
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
										_220$$147 = Z_TYPE_P(&converters) == IS_ARRAY;
										if (_220$$147) {
											ZEPHIR_OBS_NVAR(&converter);
											_221$$147 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											_220$$147 = _221$$147;
										}
										if (_220$$147) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_222$$148, &converter, NULL, 0, &position);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_222$$148, PH_COPY | PH_SEPARATE);
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
								ZEPHIR_CALL_METHOD(NULL, _209$$140, "rewind", NULL, 0);
								zephir_check_call_status();
								_224$$140 = 1;
								while (1) {
									if (_224$$140) {
										_224$$140 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _209$$140, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_223$$140, _209$$140, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_223$$140)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&part, _209$$140, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&position, _209$$140, "current", NULL, 0);
									zephir_check_call_status();
										if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
											ZEPHIR_INIT_NVAR(&_225$$151);
											object_init_ex(&_225$$151, phalcon_mvc_router_exceptions_wrongpathskey_ce);
											ZEPHIR_CALL_METHOD(NULL, &_225$$151, "__construct", &_226, 272, &part);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_225$$151, "phalcon/Mvc/Router.zep", 1427);
											ZEPHIR_MM_RESTORE();
											return;
										}
										_227$$150 = Z_TYPE_P(&position) != IS_STRING;
										if (_227$$150) {
											_227$$150 = Z_TYPE_P(&position) != IS_LONG;
										}
										if (_227$$150) {
											continue;
										}
										ZEPHIR_OBS_NVAR(&matchPosition);
										_228$$150 = zephir_array_isset_fetch(&matchPosition, &matches, &position, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (_228$$150) {
											if (Z_TYPE_P(&converters) == IS_ARRAY) {
												ZEPHIR_OBS_NVAR(&converter);
												_229$$154 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												if (_229$$154) {
													ZEPHIR_CALL_ZVAL_FUNCTION(&_230$$155, &converter, NULL, 0, &matchPosition);
													zephir_check_call_status();
													zephir_array_update_zval(&parts, &part, &_230$$155, PH_COPY | PH_SEPARATE);
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
											_231$$156 = Z_TYPE_P(&converters) == IS_ARRAY;
											if (_231$$156) {
												ZEPHIR_OBS_NVAR(&converter);
												_232$$156 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												_231$$156 = _232$$156;
											}
											if (_231$$156) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_233$$157, &converter, NULL, 0, &position);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_233$$157, PH_COPY | PH_SEPARATE);
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
		zephir_read_property_cached(&_234$$161, this_ptr, _zephir_prop_15, 315, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&notFoundPaths, &_234$$161);
		if (Z_TYPE_P(&notFoundPaths) != IS_NULL) {
			ZEPHIR_CALL_CE_STATIC(&parts, phalcon_mvc_router_route_ce, "getRoutePaths", NULL, 0, &notFoundPaths);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&routeFound);
			ZVAL_BOOL(&routeFound, 1);
		}
	}
	zephir_read_property_cached(&_235, this_ptr, _zephir_prop_16, 301, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_17, 316, &_235);
	zephir_read_property_cached(&_236, this_ptr, _zephir_prop_18, 302, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_19, 317, &_236);
	zephir_read_property_cached(&_237, this_ptr, _zephir_prop_20, 303, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_21, 318, &_237);
	zephir_read_property_cached(&_238, this_ptr, _zephir_prop_22, 304, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_23, 319, &_238);
	zephir_read_property_cached(&_239, this_ptr, _zephir_prop_24, 305, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_25, 320, &_239);
	if (zephir_is_true(&routeFound)) {
		zephir_memory_observe(&vnamespace);
		_240$$163 = zephir_array_isset_string_fetch(&vnamespace, &parts, SL("namespace"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_240$$163) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_17, 316, &vnamespace);
			zephir_array_unset_string(&parts, SL("namespace"), PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_memory_observe(&module);
		_241$$163 = zephir_array_isset_string_fetch(&module, &parts, SL("module"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_241$$163) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_19, 317, &module);
			zephir_array_unset_string(&parts, SL("module"), PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_memory_observe(&controller);
		_242$$163 = zephir_array_isset_string_fetch(&controller, &parts, SL("controller"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_242$$163) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_21, 318, &controller);
			zephir_array_unset_string(&parts, SL("controller"), PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_memory_observe(&action);
		_243$$163 = zephir_array_isset_string_fetch(&action, &parts, SL("action"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_243$$163) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_23, 319, &action);
			zephir_array_unset_string(&parts, SL("action"), PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_memory_observe(&paramsStr);
		_244$$163 = zephir_array_isset_string_fetch(&paramsStr, &parts, SL("params"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_244$$163) {
			if (Z_TYPE_P(&paramsStr) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_245$$169);
				ZVAL_STRING(&_245$$169, "/");
				ZEPHIR_INIT_VAR(&strParams);
				zephir_fast_trim(&strParams, &paramsStr, &_245$$169, ZEPHIR_TRIM_BOTH);
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
			ZEPHIR_INIT_VAR(&_246$$171);
			zephir_fast_array_merge(&_246$$171, &params, &parts);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_25, 320, &_246$$171);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_25, 320, &parts);
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_247$$173);
		ZVAL_STRING(&_247$$173, "router:afterCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_247$$173, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_248, this_ptr, _zephir_prop_26, 321, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_248) != IS_NULL) {
		zephir_read_property_cached(&_249$$174, this_ptr, _zephir_prop_26, 321, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_250$$174, this_ptr, _zephir_prop_27, 322, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_251$$174, this_ptr, "buildDispatcherDump", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_249$$174, "set", NULL, 0, &_250$$174, &_251$$174);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_26, 321, &__$null);
		ZEPHIR_INIT_VAR(&_252$$174);
		ZEPHIR_INIT_NVAR(&_252$$174);
		ZVAL_STRING(&_252$$174, "");
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_27, 322, &_252$$174);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpFileExists", NULL, 0, &path_zv);
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
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
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
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 7, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Mvc/Router.zep", 1606);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadDispatcherFromArray", NULL, 0, &dump);
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
	zend_class_entry *_11$$6, *_32$$13;
	zval _4$$4;
	zend_string *_55, *_81, *_107, *_24$$10, *_45$$17, *_113$$32, *_141$$39;
	zend_ulong _54, _80, _106, _23$$10, _44$$17, _112$$32, _140$$39;
	zend_bool _0, _5, _30, _66, _92, _135, _27$$10, _48$$17, _62$$20, _73$$23, _88$$26, _99$$29, _124$$32, _120$$33, _131$$36, _152$$39, _148$$40, _159$$43;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_25 = NULL, *_28 = NULL, *_46 = NULL, *_49 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, dumpVersion = 0;
	zval *dump_param = NULL, __$true, __$false, routeData, route, routeClass, beforeMatch, converters, convName, converter, rebuiltRoutes, methodRoutesRehydrated, candidatesRehydrated, staticRehydrated, innerKey, innerVal, scalarIdx, scalarSubKey, mostInnerVal, mostInnerArr, _1, _6, *_7, _8, *_9, _29, _50, *_51, _52, *_53, _65, _76, *_77, _78, *_79, _91, _102, *_103, _104, *_105, _134, _162, _163, _164, _165, _166, _167, _168, _169, _170, _2$$4, _3$$4, _10$$6, _12$$6, _13$$6, _14$$6, _15$$6, _17$$6, _19$$6, _16$$7, _18$$8, *_20$$10, _21$$10, *_22$$10, _26$$10, _31$$13, _33$$13, _34$$13, _35$$13, _36$$13, _38$$13, _40$$13, _37$$14, _39$$15, *_41$$17, _42$$17, *_43$$17, _47$$17, *_56$$20, _57$$20, *_58$$20, _61$$20, _59$$21, _60$$21, _63$$22, _64$$22, *_67$$23, _68$$23, *_69$$23, _72$$23, _70$$24, _71$$24, _74$$25, _75$$25, *_82$$26, _83$$26, *_84$$26, _87$$26, _85$$27, _86$$27, _89$$28, _90$$28, *_93$$29, _94$$29, *_95$$29, _98$$29, _96$$30, _97$$30, _100$$31, _101$$31, _108$$32, *_109$$32, _110$$32, *_111$$32, _123$$32, *_114$$33, _115$$33, *_116$$33, _119$$33, _117$$34, _118$$34, _121$$35, _122$$35, *_125$$36, _126$$36, *_127$$36, _130$$36, _128$$37, _129$$37, _132$$38, _133$$38, _136$$39, *_137$$39, _138$$39, *_139$$39, _151$$39, *_142$$40, _143$$40, *_144$$40, _147$$40, _145$$41, _146$$41, _149$$42, _150$$42, *_153$$43, _154$$43, *_155$$43, _158$$43, _156$$44, _157$$44, _160$$45, _161$$45;
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
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_50);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&_65);
	ZVAL_UNDEF(&_76);
	ZVAL_UNDEF(&_78);
	ZVAL_UNDEF(&_91);
	ZVAL_UNDEF(&_102);
	ZVAL_UNDEF(&_104);
	ZVAL_UNDEF(&_134);
	ZVAL_UNDEF(&_162);
	ZVAL_UNDEF(&_163);
	ZVAL_UNDEF(&_164);
	ZVAL_UNDEF(&_165);
	ZVAL_UNDEF(&_166);
	ZVAL_UNDEF(&_167);
	ZVAL_UNDEF(&_168);
	ZVAL_UNDEF(&_169);
	ZVAL_UNDEF(&_170);
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
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_38$$13);
	ZVAL_UNDEF(&_40$$13);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_39$$15);
	ZVAL_UNDEF(&_42$$17);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_57$$20);
	ZVAL_UNDEF(&_61$$20);
	ZVAL_UNDEF(&_59$$21);
	ZVAL_UNDEF(&_60$$21);
	ZVAL_UNDEF(&_63$$22);
	ZVAL_UNDEF(&_64$$22);
	ZVAL_UNDEF(&_68$$23);
	ZVAL_UNDEF(&_72$$23);
	ZVAL_UNDEF(&_70$$24);
	ZVAL_UNDEF(&_71$$24);
	ZVAL_UNDEF(&_74$$25);
	ZVAL_UNDEF(&_75$$25);
	ZVAL_UNDEF(&_83$$26);
	ZVAL_UNDEF(&_87$$26);
	ZVAL_UNDEF(&_85$$27);
	ZVAL_UNDEF(&_86$$27);
	ZVAL_UNDEF(&_89$$28);
	ZVAL_UNDEF(&_90$$28);
	ZVAL_UNDEF(&_94$$29);
	ZVAL_UNDEF(&_98$$29);
	ZVAL_UNDEF(&_96$$30);
	ZVAL_UNDEF(&_97$$30);
	ZVAL_UNDEF(&_100$$31);
	ZVAL_UNDEF(&_101$$31);
	ZVAL_UNDEF(&_108$$32);
	ZVAL_UNDEF(&_110$$32);
	ZVAL_UNDEF(&_123$$32);
	ZVAL_UNDEF(&_115$$33);
	ZVAL_UNDEF(&_119$$33);
	ZVAL_UNDEF(&_117$$34);
	ZVAL_UNDEF(&_118$$34);
	ZVAL_UNDEF(&_121$$35);
	ZVAL_UNDEF(&_122$$35);
	ZVAL_UNDEF(&_126$$36);
	ZVAL_UNDEF(&_130$$36);
	ZVAL_UNDEF(&_128$$37);
	ZVAL_UNDEF(&_129$$37);
	ZVAL_UNDEF(&_132$$38);
	ZVAL_UNDEF(&_133$$38);
	ZVAL_UNDEF(&_136$$39);
	ZVAL_UNDEF(&_138$$39);
	ZVAL_UNDEF(&_151$$39);
	ZVAL_UNDEF(&_143$$40);
	ZVAL_UNDEF(&_147$$40);
	ZVAL_UNDEF(&_145$$41);
	ZVAL_UNDEF(&_146$$41);
	ZVAL_UNDEF(&_149$$42);
	ZVAL_UNDEF(&_150$$42);
	ZVAL_UNDEF(&_154$$43);
	ZVAL_UNDEF(&_158$$43);
	ZVAL_UNDEF(&_156$$44);
	ZVAL_UNDEF(&_157$$44);
	ZVAL_UNDEF(&_160$$45);
	ZVAL_UNDEF(&_161$$45);
	ZVAL_UNDEF(&_4$$4);
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
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 7, &_4$$4);
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
				ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 0, &_12$$6, &_13$$6, &_14$$6);
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
				ZEPHIR_CALL_METHOD(NULL, &route, "setHostname", NULL, 0, &_16$$7);
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
				ZEPHIR_CALL_METHOD(NULL, &route, "setName", NULL, 0, &_18$$8);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&_19$$6);
			zephir_array_fetch_string(&_19$$6, &routeData, SL("id"), PH_NOISY, "phalcon/Mvc/Router.zep", 1659);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(NULL, &route, "setRouteId", NULL, 0, &_19$$6);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&beforeMatch);
			zephir_array_fetch_string(&beforeMatch, &routeData, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1661);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &route, "beforeMatch", NULL, 0, &beforeMatch);
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
						ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_25, 0, &convName, &converter);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _20$$10, "rewind", NULL, 0);
					zephir_check_call_status();
					_27$$10 = 1;
					while (1) {
						if (_27$$10) {
							_27$$10 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _20$$10, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_26$$10, _20$$10, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_26$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&convName, _20$$10, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&converter, _20$$10, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_28, 0, &convName, &converter);
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
		ZEPHIR_CALL_METHOD(NULL, _7, "rewind", NULL, 0);
		zephir_check_call_status();
		_30 = 1;
		while (1) {
			if (_30) {
				_30 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _7, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_29, _7, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_29)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&routeData, _7, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&routeClass);
				zephir_array_fetch_string(&routeClass, &routeData, SL("class"), PH_NOISY, "phalcon/Mvc/Router.zep", 1648);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&route);
				zephir_fetch_safe_class(&_31$$13, &routeClass);
				_32$$13 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_31$$13), Z_STRLEN_P(&_31$$13), ZEND_FETCH_CLASS_AUTO);
				if(!_32$$13) {
					RETURN_MM_NULL();
				}
				object_init_ex(&route, _32$$13);
				ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&route);
				zephir_check_call_status();
				if (zephir_has_constructor(&route)) {
					ZEPHIR_OBS_NVAR(&_33$$13);
					zephir_array_fetch_string(&_33$$13, &routeData, SL("pattern"), PH_NOISY, "phalcon/Mvc/Router.zep", 1649);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_34$$13);
					zephir_array_fetch_string(&_34$$13, &routeData, SL("paths"), PH_NOISY, "phalcon/Mvc/Router.zep", 1649);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_35$$13);
					zephir_array_fetch_string(&_35$$13, &routeData, SL("methods"), PH_NOISY, "phalcon/Mvc/Router.zep", 1649);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 0, &_33$$13, &_34$$13, &_35$$13);
					zephir_check_call_status();
				}

				ZEPHIR_OBS_NVAR(&_36$$13);
				zephir_array_fetch_string(&_36$$13, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1651);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&_36$$13) != IS_NULL) {
					ZEPHIR_OBS_NVAR(&_37$$14);
					zephir_array_fetch_string(&_37$$14, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1652);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(NULL, &route, "setHostname", NULL, 0, &_37$$14);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&_38$$13);
				zephir_array_fetch_string(&_38$$13, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 1655);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&_38$$13) != IS_NULL) {
					ZEPHIR_OBS_NVAR(&_39$$15);
					zephir_array_fetch_string(&_39$$15, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 1656);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(NULL, &route, "setName", NULL, 0, &_39$$15);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&_40$$13);
				zephir_array_fetch_string(&_40$$13, &routeData, SL("id"), PH_NOISY, "phalcon/Mvc/Router.zep", 1659);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(NULL, &route, "setRouteId", NULL, 0, &_40$$13);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&beforeMatch);
				zephir_array_fetch_string(&beforeMatch, &routeData, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1661);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &route, "beforeMatch", NULL, 0, &beforeMatch);
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
						ZEPHIR_INIT_NVAR(&_42$$17);
						zephir_string_to_char_array(&_42$$17, &converters);
						_41$$17 = &_42$$17;
					} else {
						_41$$17 = &converters;
					}
					zephir_is_iterable(_41$$17, 0, "phalcon/Mvc/Router.zep", 1671);
					if (Z_TYPE_P(_41$$17) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_41$$17), _44$$17, _45$$17, _43$$17)
						{
							ZEPHIR_INIT_NVAR(&convName);
							if (_45$$17 != NULL) { 
								ZVAL_STR_COPY(&convName, _45$$17);
							} else {
								ZVAL_LONG(&convName, _44$$17);
							}
							ZEPHIR_INIT_NVAR(&converter);
							ZVAL_COPY(&converter, _43$$17);
							ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_46, 0, &convName, &converter);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _41$$17, "rewind", NULL, 0);
						zephir_check_call_status();
						_48$$17 = 1;
						while (1) {
							if (_48$$17) {
								_48$$17 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _41$$17, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_47$$17, _41$$17, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_47$$17)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&convName, _41$$17, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&converter, _41$$17, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_49, 0, &convName, &converter);
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
	zephir_array_fetch_string(&_50, &dump, SL("methodRoutes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1679);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_50) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_52);
		zephir_string_to_char_array(&_52, &_50);
		_51 = &_52;
	} else {
		_51 = &_50;
	}
	zephir_is_iterable(_51, 0, "phalcon/Mvc/Router.zep", 1687);
	if (Z_TYPE_P(_51) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_51), _54, _55, _53)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_55 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _55);
			} else {
				ZVAL_LONG(&innerKey, _54);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _53);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_57$$20);
				zephir_string_to_char_array(&_57$$20, &innerVal);
				_56$$20 = &_57$$20;
			} else {
				_56$$20 = &innerVal;
			}
			zephir_is_iterable(_56$$20, 0, "phalcon/Mvc/Router.zep", 1684);
			if (Z_TYPE_P(_56$$20) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_56$$20), _58$$20)
				{
					ZEPHIR_INIT_NVAR(&scalarIdx);
					ZVAL_COPY(&scalarIdx, _58$$20);
					zephir_read_property_cached(&_59$$21, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_60$$21);
					zephir_array_fetch(&_60$$21, &_59$$21, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1682);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&mostInnerArr, &_60$$21, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1682);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _56$$20, "rewind", NULL, 0);
				zephir_check_call_status();
				_62$$20 = 1;
				while (1) {
					if (_62$$20) {
						_62$$20 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _56$$20, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_61$$20, _56$$20, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_61$$20)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarIdx, _56$$20, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property_cached(&_63$$22, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_64$$22);
						zephir_array_fetch(&_64$$22, &_63$$22, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1682);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_64$$22, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1682);
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
		ZEPHIR_CALL_METHOD(NULL, _51, "rewind", NULL, 0);
		zephir_check_call_status();
		_66 = 1;
		while (1) {
			if (_66) {
				_66 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _51, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_65, _51, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_65)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, _51, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, _51, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_68$$23);
					zephir_string_to_char_array(&_68$$23, &innerVal);
					_67$$23 = &_68$$23;
				} else {
					_67$$23 = &innerVal;
				}
				zephir_is_iterable(_67$$23, 0, "phalcon/Mvc/Router.zep", 1684);
				if (Z_TYPE_P(_67$$23) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_67$$23), _69$$23)
					{
						ZEPHIR_INIT_NVAR(&scalarIdx);
						ZVAL_COPY(&scalarIdx, _69$$23);
						zephir_read_property_cached(&_70$$24, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_71$$24);
						zephir_array_fetch(&_71$$24, &_70$$24, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1682);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_71$$24, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1682);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _67$$23, "rewind", NULL, 0);
					zephir_check_call_status();
					_73$$23 = 1;
					while (1) {
						if (_73$$23) {
							_73$$23 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _67$$23, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_72$$23, _67$$23, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_72$$23)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarIdx, _67$$23, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property_cached(&_74$$25, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_OBS_NVAR(&_75$$25);
							zephir_array_fetch(&_75$$25, &_74$$25, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1682);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&mostInnerArr, &_75$$25, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1682);
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
	zephir_array_fetch_string(&_76, &dump, SL("candidatesByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1688);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_76) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_78);
		zephir_string_to_char_array(&_78, &_76);
		_77 = &_78;
	} else {
		_77 = &_76;
	}
	zephir_is_iterable(_77, 0, "phalcon/Mvc/Router.zep", 1696);
	if (Z_TYPE_P(_77) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_77), _80, _81, _79)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_81 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _81);
			} else {
				ZVAL_LONG(&innerKey, _80);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _79);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_83$$26);
				zephir_string_to_char_array(&_83$$26, &innerVal);
				_82$$26 = &_83$$26;
			} else {
				_82$$26 = &innerVal;
			}
			zephir_is_iterable(_82$$26, 0, "phalcon/Mvc/Router.zep", 1693);
			if (Z_TYPE_P(_82$$26) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_82$$26), _84$$26)
				{
					ZEPHIR_INIT_NVAR(&scalarIdx);
					ZVAL_COPY(&scalarIdx, _84$$26);
					zephir_read_property_cached(&_85$$27, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_86$$27);
					zephir_array_fetch(&_86$$27, &_85$$27, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1691);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&mostInnerArr, &_86$$27, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1691);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _82$$26, "rewind", NULL, 0);
				zephir_check_call_status();
				_88$$26 = 1;
				while (1) {
					if (_88$$26) {
						_88$$26 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _82$$26, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_87$$26, _82$$26, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_87$$26)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarIdx, _82$$26, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property_cached(&_89$$28, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_90$$28);
						zephir_array_fetch(&_90$$28, &_89$$28, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1691);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_90$$28, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1691);
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
		ZEPHIR_CALL_METHOD(NULL, _77, "rewind", NULL, 0);
		zephir_check_call_status();
		_92 = 1;
		while (1) {
			if (_92) {
				_92 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _77, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_91, _77, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_91)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, _77, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, _77, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_94$$29);
					zephir_string_to_char_array(&_94$$29, &innerVal);
					_93$$29 = &_94$$29;
				} else {
					_93$$29 = &innerVal;
				}
				zephir_is_iterable(_93$$29, 0, "phalcon/Mvc/Router.zep", 1693);
				if (Z_TYPE_P(_93$$29) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_93$$29), _95$$29)
					{
						ZEPHIR_INIT_NVAR(&scalarIdx);
						ZVAL_COPY(&scalarIdx, _95$$29);
						zephir_read_property_cached(&_96$$30, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_97$$30);
						zephir_array_fetch(&_97$$30, &_96$$30, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1691);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&mostInnerArr, &_97$$30, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1691);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _93$$29, "rewind", NULL, 0);
					zephir_check_call_status();
					_99$$29 = 1;
					while (1) {
						if (_99$$29) {
							_99$$29 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _93$$29, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_98$$29, _93$$29, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_98$$29)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarIdx, _93$$29, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property_cached(&_100$$31, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_OBS_NVAR(&_101$$31);
							zephir_array_fetch(&_101$$31, &_100$$31, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1691);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&mostInnerArr, &_101$$31, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1691);
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
	zephir_array_fetch_string(&_102, &dump, SL("staticByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1697);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_102) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_104);
		zephir_string_to_char_array(&_104, &_102);
		_103 = &_104;
	} else {
		_103 = &_102;
	}
	zephir_is_iterable(_103, 0, "phalcon/Mvc/Router.zep", 1708);
	if (Z_TYPE_P(_103) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_103), _106, _107, _105)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_107 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _107);
			} else {
				ZVAL_LONG(&innerKey, _106);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _105);
			ZEPHIR_INIT_NVAR(&_108$$32);
			array_init(&_108$$32);
			zephir_array_update_zval(&staticRehydrated, &innerKey, &_108$$32, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_110$$32);
				zephir_string_to_char_array(&_110$$32, &innerVal);
				_109$$32 = &_110$$32;
			} else {
				_109$$32 = &innerVal;
			}
			zephir_is_iterable(_109$$32, 0, "phalcon/Mvc/Router.zep", 1706);
			if (Z_TYPE_P(_109$$32) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_109$$32), _112$$32, _113$$32, _111$$32)
				{
					ZEPHIR_INIT_NVAR(&scalarSubKey);
					if (_113$$32 != NULL) { 
						ZVAL_STR_COPY(&scalarSubKey, _113$$32);
					} else {
						ZVAL_LONG(&scalarSubKey, _112$$32);
					}
					ZEPHIR_INIT_NVAR(&mostInnerVal);
					ZVAL_COPY(&mostInnerVal, _111$$32);
					ZEPHIR_INIT_NVAR(&mostInnerArr);
					array_init(&mostInnerArr);
					if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_115$$33);
						zephir_string_to_char_array(&_115$$33, &mostInnerVal);
						_114$$33 = &_115$$33;
					} else {
						_114$$33 = &mostInnerVal;
					}
					zephir_is_iterable(_114$$33, 0, "phalcon/Mvc/Router.zep", 1704);
					if (Z_TYPE_P(_114$$33) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_114$$33), _116$$33)
						{
							ZEPHIR_INIT_NVAR(&scalarIdx);
							ZVAL_COPY(&scalarIdx, _116$$33);
							zephir_read_property_cached(&_117$$34, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_OBS_NVAR(&_118$$34);
							zephir_array_fetch(&_118$$34, &_117$$34, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&mostInnerArr, &_118$$34, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _114$$33, "rewind", NULL, 0);
						zephir_check_call_status();
						_120$$33 = 1;
						while (1) {
							if (_120$$33) {
								_120$$33 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _114$$33, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_119$$33, _114$$33, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_119$$33)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&scalarIdx, _114$$33, "current", NULL, 0);
							zephir_check_call_status();
								zephir_read_property_cached(&_121$$35, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_OBS_NVAR(&_122$$35);
								zephir_array_fetch(&_122$$35, &_121$$35, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&mostInnerArr, &_122$$35, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
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
				ZEPHIR_CALL_METHOD(NULL, _109$$32, "rewind", NULL, 0);
				zephir_check_call_status();
				_124$$32 = 1;
				while (1) {
					if (_124$$32) {
						_124$$32 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _109$$32, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_123$$32, _109$$32, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_123$$32)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarSubKey, _109$$32, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&mostInnerVal, _109$$32, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_126$$36);
							zephir_string_to_char_array(&_126$$36, &mostInnerVal);
							_125$$36 = &_126$$36;
						} else {
							_125$$36 = &mostInnerVal;
						}
						zephir_is_iterable(_125$$36, 0, "phalcon/Mvc/Router.zep", 1704);
						if (Z_TYPE_P(_125$$36) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_125$$36), _127$$36)
							{
								ZEPHIR_INIT_NVAR(&scalarIdx);
								ZVAL_COPY(&scalarIdx, _127$$36);
								zephir_read_property_cached(&_128$$37, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_OBS_NVAR(&_129$$37);
								zephir_array_fetch(&_129$$37, &_128$$37, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&mostInnerArr, &_129$$37, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _125$$36, "rewind", NULL, 0);
							zephir_check_call_status();
							_131$$36 = 1;
							while (1) {
								if (_131$$36) {
									_131$$36 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _125$$36, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_130$$36, _125$$36, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_130$$36)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarIdx, _125$$36, "current", NULL, 0);
								zephir_check_call_status();
									zephir_read_property_cached(&_132$$38, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_OBS_NVAR(&_133$$38);
									zephir_array_fetch(&_133$$38, &_132$$38, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&mostInnerArr, &_133$$38, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
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
		ZEPHIR_CALL_METHOD(NULL, _103, "rewind", NULL, 0);
		zephir_check_call_status();
		_135 = 1;
		while (1) {
			if (_135) {
				_135 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _103, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_134, _103, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_134)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, _103, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, _103, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_136$$39);
				array_init(&_136$$39);
				zephir_array_update_zval(&staticRehydrated, &innerKey, &_136$$39, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_138$$39);
					zephir_string_to_char_array(&_138$$39, &innerVal);
					_137$$39 = &_138$$39;
				} else {
					_137$$39 = &innerVal;
				}
				zephir_is_iterable(_137$$39, 0, "phalcon/Mvc/Router.zep", 1706);
				if (Z_TYPE_P(_137$$39) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_137$$39), _140$$39, _141$$39, _139$$39)
					{
						ZEPHIR_INIT_NVAR(&scalarSubKey);
						if (_141$$39 != NULL) { 
							ZVAL_STR_COPY(&scalarSubKey, _141$$39);
						} else {
							ZVAL_LONG(&scalarSubKey, _140$$39);
						}
						ZEPHIR_INIT_NVAR(&mostInnerVal);
						ZVAL_COPY(&mostInnerVal, _139$$39);
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_143$$40);
							zephir_string_to_char_array(&_143$$40, &mostInnerVal);
							_142$$40 = &_143$$40;
						} else {
							_142$$40 = &mostInnerVal;
						}
						zephir_is_iterable(_142$$40, 0, "phalcon/Mvc/Router.zep", 1704);
						if (Z_TYPE_P(_142$$40) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_142$$40), _144$$40)
							{
								ZEPHIR_INIT_NVAR(&scalarIdx);
								ZVAL_COPY(&scalarIdx, _144$$40);
								zephir_read_property_cached(&_145$$41, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_OBS_NVAR(&_146$$41);
								zephir_array_fetch(&_146$$41, &_145$$41, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&mostInnerArr, &_146$$41, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _142$$40, "rewind", NULL, 0);
							zephir_check_call_status();
							_148$$40 = 1;
							while (1) {
								if (_148$$40) {
									_148$$40 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _142$$40, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_147$$40, _142$$40, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_147$$40)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarIdx, _142$$40, "current", NULL, 0);
								zephir_check_call_status();
									zephir_read_property_cached(&_149$$42, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_OBS_NVAR(&_150$$42);
									zephir_array_fetch(&_150$$42, &_149$$42, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&mostInnerArr, &_150$$42, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
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
					ZEPHIR_CALL_METHOD(NULL, _137$$39, "rewind", NULL, 0);
					zephir_check_call_status();
					_152$$39 = 1;
					while (1) {
						if (_152$$39) {
							_152$$39 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _137$$39, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_151$$39, _137$$39, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_151$$39)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarSubKey, _137$$39, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&mostInnerVal, _137$$39, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&mostInnerArr);
							array_init(&mostInnerArr);
							if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_154$$43);
								zephir_string_to_char_array(&_154$$43, &mostInnerVal);
								_153$$43 = &_154$$43;
							} else {
								_153$$43 = &mostInnerVal;
							}
							zephir_is_iterable(_153$$43, 0, "phalcon/Mvc/Router.zep", 1704);
							if (Z_TYPE_P(_153$$43) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_153$$43), _155$$43)
								{
									ZEPHIR_INIT_NVAR(&scalarIdx);
									ZVAL_COPY(&scalarIdx, _155$$43);
									zephir_read_property_cached(&_156$$44, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_OBS_NVAR(&_157$$44);
									zephir_array_fetch(&_157$$44, &_156$$44, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&mostInnerArr, &_157$$44, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _153$$43, "rewind", NULL, 0);
								zephir_check_call_status();
								_159$$43 = 1;
								while (1) {
									if (_159$$43) {
										_159$$43 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _153$$43, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_158$$43, _153$$43, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_158$$43)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&scalarIdx, _153$$43, "current", NULL, 0);
									zephir_check_call_status();
										zephir_read_property_cached(&_160$$45, this_ptr, _zephir_prop_0, 289, PH_NOISY_CC | PH_READONLY);
										ZEPHIR_OBS_NVAR(&_161$$45);
										zephir_array_fetch(&_161$$45, &_160$$45, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&mostInnerArr, &_161$$45, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
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
	zephir_array_fetch_string(&_162, &dump, SL("staticShadowedByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1711);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 294, &_162);
	zephir_array_fetch_string(&_163, &dump, SL("hostnameByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1712);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 295, &_163);
	zephir_array_fetch_string(&_164, &dump, SL("hostnameLessByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1713);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 296, &_164);
	zephir_array_fetch_string(&_165, &dump, SL("combinedRegexByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1714);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 297, &_165);
	zephir_array_fetch_string(&_166, &dump, SL("combinedRegexDisabled"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1715);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 298, &_166);
	zephir_array_fetch_string(&_167, &dump, SL("combinedRegexMarkMap"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1716);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 299, &_167);
	zephir_array_fetch_string(&_168, &dump, SL("routeMeta"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1717);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 300, &_168);
	ZEPHIR_INIT_VAR(&_169);
	array_init(&_169);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 307, &_169);
	ZEPHIR_INIT_VAR(&_170);
	array_init(&_170);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_12, 308, &_170);
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
	zend_bool _5, _7, _8, _15, _22, _14$$9, _21$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_12 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, routes, routeData, defaults, notFoundPaths, removeExtra, groups, groupData, _0$$4, _2$$3, _3$$5, _6$$6, *_9$$9, _10$$9, *_11$$9, _13$$9, *_16$$13, _17$$13, *_18$$13, _20$$13;
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
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_20$$13);
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
			ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", &_1, 274);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/Router.zep", 1752);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_2$$3, config, "toArray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_2$$3);
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_router_exceptions_invalidconfigsource_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", &_4, 274);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Router.zep", 1758);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = zephir_array_isset_value_string(config, SL("removeExtraSlashes"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		zephir_memory_observe(&removeExtra);
		zephir_array_fetch_string(&removeExtra, config, SL("removeExtraSlashes"), PH_NOISY, "phalcon/Mvc/Router.zep", 1762);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_BOOL(&_6$$6, zephir_get_boolval(&removeExtra));
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "removeExtraSlashes", NULL, 0, &_6$$6);
		zephir_check_call_status();
	}
	_7 = zephir_array_isset_value_string(config, SL("defaults"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_7) {
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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setDefaults", NULL, 0, &defaults);
		zephir_check_call_status();
	}
	zephir_memory_observe(&routes);
	_8 = zephir_array_isset_string_fetch(&routes, config, SL("routes"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_8) {
		if (Z_TYPE_P(&routes) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_configkeymustbearray_ce, "routes", "phalcon/Mvc/Router.zep", 1776);
			return;
		}
		if (Z_TYPE_P(&routes) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_10$$9);
			zephir_string_to_char_array(&_10$$9, &routes);
			_9$$9 = &_10$$9;
		} else {
			_9$$9 = &routes;
		}
		zephir_is_iterable(_9$$9, 0, "phalcon/Mvc/Router.zep", 1781);
		if (Z_TYPE_P(_9$$9) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9$$9), _11$$9)
			{
				ZEPHIR_INIT_NVAR(&routeData);
				ZVAL_COPY(&routeData, _11$$9);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addRouteFromConfig", &_12, 0, &routeData);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _9$$9, "rewind", NULL, 0);
			zephir_check_call_status();
			_14$$9 = 1;
			while (1) {
				if (_14$$9) {
					_14$$9 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _9$$9, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_13$$9, _9$$9, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_13$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&routeData, _9$$9, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "addRouteFromConfig", &_12, 0, &routeData);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&routeData);
	}
	zephir_memory_observe(&groups);
	_15 = zephir_array_isset_string_fetch(&groups, config, SL("groups"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_15) {
		if (Z_TYPE_P(&groups) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_configkeymustbearray_ce, "groups", "phalcon/Mvc/Router.zep", 1785);
			return;
		}
		if (Z_TYPE_P(&groups) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_17$$13);
			zephir_string_to_char_array(&_17$$13, &groups);
			_16$$13 = &_17$$13;
		} else {
			_16$$13 = &groups;
		}
		zephir_is_iterable(_16$$13, 0, "phalcon/Mvc/Router.zep", 1790);
		if (Z_TYPE_P(_16$$13) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_16$$13), _18$$13)
			{
				ZEPHIR_INIT_NVAR(&groupData);
				ZVAL_COPY(&groupData, _18$$13);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "mountGroupFromConfig", &_19, 0, &groupData);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _16$$13, "rewind", NULL, 0);
			zephir_check_call_status();
			_21$$13 = 1;
			while (1) {
				if (_21$$13) {
					_21$$13 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _16$$13, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_20$$13, _16$$13, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_20$$13)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&groupData, _16$$13, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "mountGroupFromConfig", &_19, 0, &groupData);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&groupData);
	}
	zephir_memory_observe(&notFoundPaths);
	_22 = zephir_array_isset_string_fetch(&notFoundPaths, config, SL("notFound"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_22) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "notFound", NULL, 0, &notFoundPaths);
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
	zend_bool _18, _7$$5, _12$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group, group_sub, groupRoutes, beforeMatch, hostname, route, eventsManager, _0, *_13, _14, *_15, _17, _1$$3, _2$$4, *_3$$5, _4$$5, *_5$$5, _6$$5, *_8$$8, _9$$8, *_10$$8, _11$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&groupRoutes);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&hostname);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_11$$8);
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
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "router:beforeMount");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_1$$3, this_ptr, group);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&groupRoutes, group, "getRoutes", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&groupRoutes))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_router_exceptions_emptygroupofroutes_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 275);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Router.zep", 1821);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&beforeMatch, group, "getBeforeMatch", NULL, 0);
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
				ZEPHIR_CALL_METHOD(NULL, &route, "beforeMatch", NULL, 0, &beforeMatch);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _3$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			_7$$5 = 1;
			while (1) {
				if (_7$$5) {
					_7$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _3$$5, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_6$$5, _3$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&route, _3$$5, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &route, "beforeMatch", NULL, 0, &beforeMatch);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&route);
	}
	ZEPHIR_CALL_METHOD(&hostname, group, "getHostName", NULL, 0);
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
				ZEPHIR_CALL_METHOD(NULL, &route, "setHostName", NULL, 0, &hostname);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _8$$8, "rewind", NULL, 0);
			zephir_check_call_status();
			_12$$8 = 1;
			while (1) {
				if (_12$$8) {
					_12$$8 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _8$$8, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_11$$8, _8$$8, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_11$$8)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&route, _8$$8, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &route, "setHostName", NULL, 0, &hostname);
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
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", &_16, 0, &route);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _13, "rewind", NULL, 0);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _13, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_17, _13, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, _13, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", &_16, 0, &route);
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
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 276);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 7, &_2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Router.zep", 2081);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadDispatcherFromArray", NULL, 0, &stored);
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
		ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", NULL, 277, &method);
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
		ZEPHIR_CALL_METHOD(NULL, &route, "setName", NULL, 0, &_11$$8);
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
		ZEPHIR_CALL_METHOD(NULL, &route, "setHostname", NULL, 0, &_14$$9);
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
	zval _3$$4, _6$$5, _18$$11, _24$$14, _33$$18, _39$$21;
	zend_bool _0, _1, _4, _7, _26, _12$$8, _13$$8, _14$$8, _15$$8, _22$$8, _27$$15, _28$$15, _29$$15, _30$$15, _37$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_21 = NULL, *_36 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *groupData_param = NULL, group, paths, routes, routeData, method, methodClass, pattern, routePaths, route, *_9, _10, *_11, _25, _2$$4, _5$$5, _8$$7, _16$$8, _17$$11, _19$$12, _20$$13, _23$$14, _31$$15, _32$$18, _34$$19, _35$$20, _38$$21;
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
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&_34$$19);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_38$$21);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_33$$18);
	ZVAL_UNDEF(&_39$$21);
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
	ZEPHIR_CALL_METHOD(NULL, &group, "__construct", NULL, 278, &paths);
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
		ZEPHIR_CALL_METHOD(NULL, &group, "setPrefix", NULL, 279, &_3$$4);
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
		ZEPHIR_CALL_METHOD(NULL, &group, "setHostname", NULL, 280, &_6$$5);
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
		ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", NULL, 281);
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
				ZEPHIR_CALL_METHOD(NULL, &_20$$13, "__construct", &_21, 277, &method);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_20$$13, "phalcon/Mvc/Router.zep", 2230);
				ZEPHIR_MM_RESTORE();
				return;
			zephir_switch_0_end: ;

			_22$$8 = zephir_array_isset_value_string(&routeData, SL("name"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_22$$8) {
				ZEPHIR_OBS_NVAR(&_23$$14);
				zephir_array_fetch_string(&_23$$14, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 2234);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_24$$14, &_23$$14);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(NULL, &route, "setName", NULL, 0, &_24$$14);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _9, "rewind", NULL, 0);
		zephir_check_call_status();
		_26 = 1;
		while (1) {
			if (_26) {
				_26 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _9, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_25, _9, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_25)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&routeData, _9, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&pattern);
				_27$$15 = zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_27$$15)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "pattern", "phalcon/Mvc/Router.zep", 2203);
					return;
				}
				ZEPHIR_OBS_NVAR(&routePaths);
				_28$$15 = zephir_array_isset_string_fetch(&routePaths, &routeData, SL("paths"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_28$$15)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "paths", "phalcon/Mvc/Router.zep", 2206);
					return;
				}
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_STRING(&method, "");
				_29$$15 = zephir_array_isset_value_string(&routeData, SL("method"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_30$$15 = _29$$15;
				if (_30$$15) {
					ZEPHIR_OBS_NVAR(&_31$$15);
					zephir_array_fetch_string(&_31$$15, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2210);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_30$$15 = Z_TYPE_P(&_31$$15) != IS_NULL;
				}
				if (_30$$15) {
					ZEPHIR_OBS_NVAR(&_32$$18);
					zephir_array_fetch_string(&_32$$18, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2211);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_cast_to_string(&_33$$18, &_32$$18);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&method);
					zephir_fast_strtolower(&method, &_33$$18);
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
					ZEPHIR_INIT_NVAR(&_34$$19);
					zephir_ucfirst(&_34$$19, &method);
					ZEPHIR_INIT_NVAR(&methodClass);
					ZEPHIR_CONCAT_SV(&methodClass, "add", &_34$$19);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_ZVAL(&route, &group, &methodClass, NULL, 0, &pattern, &routePaths);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_clause_11: ;
					ZEPHIR_INIT_NVAR(&_35$$20);
					object_init_ex(&_35$$20, phalcon_mvc_router_exceptions_unknownhttpmethod_ce);
					ZEPHIR_CALL_METHOD(NULL, &_35$$20, "__construct", &_36, 277, &method);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_35$$20, "phalcon/Mvc/Router.zep", 2230);
					ZEPHIR_MM_RESTORE();
					return;
				zephir_switch_1_end: ;

				_37$$15 = zephir_array_isset_value_string(&routeData, SL("name"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_37$$15) {
					ZEPHIR_OBS_NVAR(&_38$$21);
					zephir_array_fetch_string(&_38$$21, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 2234);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_cast_to_string(&_39$$21, &_38$$21);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(NULL, &route, "setName", NULL, 0, &_39$$21);
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
	zval _134$$66, _150$$71;
	zval _7$$3, _18$$13;
	zend_string *_5, *_31, *_48, *_100, *_114, *_37$$24, *_53$$38, *_67$$43, *_89$$52, *_107$$57, *_119$$64;
	zend_ulong _4, _30, _47, _99, _113, _36$$24, _52$$38, _66$$43, _88$$52, _106$$57, _118$$64;
	zend_bool isRegex = 0, _16, _26, _14$$10, _25$$20, _41$$24, _38$$26, _39$$26, _42$$32, _43$$32, _75$$38, _55$$40, _56$$40, _58$$40, _62$$42, _71$$43, _77$$49, _78$$49, _80$$49, _84$$51, _93$$52, _109$$57, _136$$64, _151$$64, _171$$64, _120$$66, _123$$66, _124$$66, _125$$66, _130$$66, _137$$71, _140$$71, _141$$71, _142$$71, _147$$71, _162$$78;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_132 = NULL, *_153 = NULL, *_156 = NULL;
	zval __$true, __$false, route, methods, method, methodSpecific, starRoutes, candidates, candidatePattern, bucketRoute, bucketPattern, staticUri, staticBucket, staticRoutesList, shadowBucket, bucket, methodRoutes, candidatesByMethod, routeMeta, staticByMethod, staticShadowedByMethod, hostnameByMethod, hostnameLessByMethod, combinedRegexByMethod, combinedRegexMarkMap, combinedRegexDisabled, routePatterns, routeHosts, candidateHost, routeData, routeMethods, routeIndex, starPositions, positions, positionsByMethod, bucketIdx, _0, *_1, _2, *_3, _15, *_27, _28, *_29, *_44, _45, *_46, bucketHostname, *_96, _97, *_98, combinedAlternatives, combinedMark, combinedBody, hostnameBucketRef, *_110, _111, *_112, _6$$3, _8$$3, _9$$3, *_10$$10, _11$$10, *_12$$10, _13$$10, _17$$13, _19$$13, _20$$13, *_21$$20, _22$$20, *_23$$20, _24$$20, _32$$24, *_33$$24, _34$$24, *_35$$24, _40$$24, *_49$$38, _50$$38, *_51$$38, _74$$38, _54$$40, _57$$40, _59$$40, _60$$40, _61$$40, *_63$$43, _64$$43, *_65$$43, _70$$43, _68$$44, _69$$44, _72$$46, _73$$46, _76$$49, _79$$49, _81$$49, _82$$49, _83$$49, *_85$$52, _86$$52, *_87$$52, _92$$52, _90$$53, _91$$53, _94$$55, _95$$55, _101$$57, _102$$57, *_103$$57, _104$$57, *_105$$57, _108$$57, *_115$$64, _116$$64, *_117$$64, _135$$64, chunkedPatterns$$64, chunkedMarkMaps$$64, chunkOffset$$64, chunkSlice$$64, chunkSliceMap$$64, chunkMarkSubset$$64, reversedMarkIds$$64, chunkMarkId$$64, chunkPattern$$64, _152$$64, _154$$64, _121$$66, _122$$66, _126$$66, _127$$66, _128$$66, _129$$66, _131$$66, _133$$66, _138$$71, _139$$71, _143$$71, _144$$71, _145$$71, _146$$71, _148$$71, _149$$71, _155$$78, *_157$$78, _158$$78, *_159$$78, _161$$78, _164$$78, _165$$78, _166$$78, _167$$78, _168$$78, _169$$78, _170$$78, _160$$79, _163$$80;
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
	ZVAL_UNDEF(&_135$$64);
	ZVAL_UNDEF(&chunkedPatterns$$64);
	ZVAL_UNDEF(&chunkedMarkMaps$$64);
	ZVAL_UNDEF(&chunkOffset$$64);
	ZVAL_UNDEF(&chunkSlice$$64);
	ZVAL_UNDEF(&chunkSliceMap$$64);
	ZVAL_UNDEF(&chunkMarkSubset$$64);
	ZVAL_UNDEF(&reversedMarkIds$$64);
	ZVAL_UNDEF(&chunkMarkId$$64);
	ZVAL_UNDEF(&chunkPattern$$64);
	ZVAL_UNDEF(&_152$$64);
	ZVAL_UNDEF(&_154$$64);
	ZVAL_UNDEF(&_121$$66);
	ZVAL_UNDEF(&_122$$66);
	ZVAL_UNDEF(&_126$$66);
	ZVAL_UNDEF(&_127$$66);
	ZVAL_UNDEF(&_128$$66);
	ZVAL_UNDEF(&_129$$66);
	ZVAL_UNDEF(&_131$$66);
	ZVAL_UNDEF(&_133$$66);
	ZVAL_UNDEF(&_138$$71);
	ZVAL_UNDEF(&_139$$71);
	ZVAL_UNDEF(&_143$$71);
	ZVAL_UNDEF(&_144$$71);
	ZVAL_UNDEF(&_145$$71);
	ZVAL_UNDEF(&_146$$71);
	ZVAL_UNDEF(&_148$$71);
	ZVAL_UNDEF(&_149$$71);
	ZVAL_UNDEF(&_155$$78);
	ZVAL_UNDEF(&_158$$78);
	ZVAL_UNDEF(&_161$$78);
	ZVAL_UNDEF(&_164$$78);
	ZVAL_UNDEF(&_165$$78);
	ZVAL_UNDEF(&_166$$78);
	ZVAL_UNDEF(&_167$$78);
	ZVAL_UNDEF(&_168$$78);
	ZVAL_UNDEF(&_169$$78);
	ZVAL_UNDEF(&_170$$78);
	ZVAL_UNDEF(&_160$$79);
	ZVAL_UNDEF(&_163$$80);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_134$$66);
	ZVAL_UNDEF(&_150$$71);
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
			ZEPHIR_CALL_METHOD(&routeData, &route, "getIndexData", NULL, 0);
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
						ZEPHIR_CALL_METHOD(NULL, _10$$10, "rewind", NULL, 0);
						zephir_check_call_status();
						_14$$10 = 1;
						while (1) {
							if (_14$$10) {
								_14$$10 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _10$$10, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_13$$10, _10$$10, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_13$$10)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&method, _10$$10, "current", NULL, 0);
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
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&routeIndex, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&routeData, &route, "getIndexData", NULL, 0);
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
							ZEPHIR_CALL_METHOD(NULL, _21$$20, "rewind", NULL, 0);
							zephir_check_call_status();
							_25$$20 = 1;
							while (1) {
								if (_25$$20) {
									_25$$20 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _21$$20, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_24$$20, _21$$20, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_24$$20)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&method, _21$$20, "current", NULL, 0);
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
			ZEPHIR_CALL_METHOD(NULL, _33$$24, "rewind", NULL, 0);
			zephir_check_call_status();
			_41$$24 = 1;
			while (1) {
				if (_41$$24) {
					_41$$24 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _33$$24, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_40$$24, _33$$24, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_40$$24)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&routeIndex, _33$$24, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&route, _33$$24, "current", NULL, 0);
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
						ZEPHIR_CALL_METHOD(&_60$$40, &bucketRoute, "getRouteId", NULL, 0);
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
							ZEPHIR_CALL_METHOD(NULL, _63$$43, "rewind", NULL, 0);
							zephir_check_call_status();
							_71$$43 = 1;
							while (1) {
								if (_71$$43) {
									_71$$43 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _63$$43, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_70$$43, _63$$43, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_70$$43)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&staticUri, _63$$43, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&staticRoutesList, _63$$43, "current", NULL, 0);
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
			ZEPHIR_CALL_METHOD(NULL, _49$$38, "rewind", NULL, 0);
			zephir_check_call_status();
			_75$$38 = 1;
			while (1) {
				if (_75$$38) {
					_75$$38 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _49$$38, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_74$$38, _49$$38, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_74$$38)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&bucketIdx, _49$$38, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&bucketRoute, _49$$38, "current", NULL, 0);
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
							ZEPHIR_CALL_METHOD(&_82$$49, &bucketRoute, "getRouteId", NULL, 0);
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
								ZEPHIR_CALL_METHOD(NULL, _85$$52, "rewind", NULL, 0);
								zephir_check_call_status();
								_93$$52 = 1;
								while (1) {
									if (_93$$52) {
										_93$$52 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _85$$52, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_92$$52, _85$$52, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_92$$52)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&staticUri, _85$$52, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&staticRoutesList, _85$$52, "current", NULL, 0);
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
			ZEPHIR_CALL_METHOD(NULL, _103$$57, "rewind", NULL, 0);
			zephir_check_call_status();
			_109$$57 = 1;
			while (1) {
				if (_109$$57) {
					_109$$57 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _103$$57, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_108$$57, _103$$57, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_108$$57)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&bucketIdx, _103$$57, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&routeIndex, _103$$57, "current", NULL, 0);
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
					ZEPHIR_CALL_METHOD(&_131$$66, this_ptr, "hasTopLevelAlternation", &_132, 282, &combinedBody);
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
				ZEPHIR_INIT_NVAR(&_133$$66);
				ZEPHIR_CONCAT_VSVS(&_133$$66, &combinedBody, "(*:", &bucketIdx, ")");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&combinedAlternatives, &_133$$66, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2522);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_134$$66, &bucketIdx);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&combinedMark, &_134$$66, &bucketIdx, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _115$$64, "rewind", NULL, 0);
			zephir_check_call_status();
			_136$$64 = 1;
			while (1) {
				if (_136$$64) {
					_136$$64 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _115$$64, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_135$$64, _115$$64, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_135$$64)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&bucketIdx, _115$$64, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&routeIndex, _115$$64, "current", NULL, 0);
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
					_137$$71 = !(zephir_start_with_str(&bucketPattern, SL("#^")));
					if (!(_137$$71)) {
						_137$$71 = !(zephir_end_with_str(&bucketPattern, SL("$#u")));
					}
					if (_137$$71) {
						zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&combinedAlternatives);
						array_init(&combinedAlternatives);
						break;
					}
					ZVAL_LONG(&_138$$71, 2);
					ZVAL_LONG(&_139$$71, -3);
					ZEPHIR_INIT_NVAR(&combinedBody);
					zephir_substr(&combinedBody, &bucketPattern, 2 , -3 , 0);
					_140$$71 = ZEPHIR_IS_STRING_IDENTICAL(&combinedBody, "");
					if (!(_140$$71)) {
						_140$$71 = zephir_memnstr_str(&combinedBody, SL("\n"), "phalcon/Mvc/Router.zep", 2505);
					}
					_141$$71 = _140$$71;
					if (!(_141$$71)) {
						_142$$71 = zephir_memnstr_str(&combinedBody, SL("(?"), "phalcon/Mvc/Router.zep", 2505);
						if (_142$$71) {
							ZEPHIR_INIT_NVAR(&_143$$71);
							ZEPHIR_INIT_NVAR(&_144$$71);
							ZVAL_STRING(&_144$$71, "/\\(\\?(?:P?<[^=!]|')/");
							ZEPHIR_INIT_NVAR(&_145$$71);
							ZEPHIR_INIT_NVAR(&_146$$71);
							ZVAL_STRING(&_146$$71, "/\\(\\?(?:P?<[^=!]|')/");
							zephir_preg_match(&_145$$71, &_146$$71, &combinedBody, &_143$$71, 0, 0 , 0 );
							_142$$71 = zephir_is_true(&_145$$71);
						}
						_141$$71 = _142$$71;
					}
					if (_141$$71) {
						zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&combinedAlternatives);
						array_init(&combinedAlternatives);
						break;
					}
					_147$$71 = zephir_memnstr_str(&combinedBody, SL("|"), "phalcon/Mvc/Router.zep", 2516);
					if (_147$$71) {
						ZEPHIR_CALL_METHOD(&_148$$71, this_ptr, "hasTopLevelAlternation", &_132, 282, &combinedBody);
						zephir_check_call_status();
						_147$$71 = zephir_is_true(&_148$$71);
					}
					if (_147$$71) {
						zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&combinedAlternatives);
						array_init(&combinedAlternatives);
						break;
					}
					ZEPHIR_INIT_NVAR(&_149$$71);
					ZEPHIR_CONCAT_VSVS(&_149$$71, &combinedBody, "(*:", &bucketIdx, ")");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&combinedAlternatives, &_149$$71, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2522);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_cast_to_string(&_150$$71, &bucketIdx);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&combinedMark, &_150$$71, &bucketIdx, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&routeIndex);
		ZEPHIR_INIT_NVAR(&bucketIdx);
		_151$$64 = zephir_array_isset_value(&combinedRegexDisabled, &method);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_151$$64) {
			continue;
		}
		if (ZEPHIR_IS_EMPTY(&combinedAlternatives)) {
			continue;
		}
		ZEPHIR_CALL_FUNCTION(&_152$$64, "array_reverse", &_153, 273, &combinedAlternatives);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&combinedAlternatives, &_152$$64);
		ZEPHIR_INIT_NVAR(&_154$$64);
		zephir_array_keys(&_154$$64, &combinedMark);
		ZEPHIR_CALL_FUNCTION(&reversedMarkIds$$64, "array_reverse", &_153, 273, &_154$$64);
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
			ZVAL_LONG(&_155$$78, 10);
			ZEPHIR_CALL_FUNCTION(&chunkSlice$$64, "array_slice", &_156, 283, &combinedAlternatives, &chunkOffset$$64, &_155$$78);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&chunkSlice$$64, &chunkSlice$$64);
			ZVAL_LONG(&_155$$78, 10);
			ZEPHIR_CALL_FUNCTION(&chunkMarkSubset$$64, "array_slice", &_156, 283, &reversedMarkIds$$64, &chunkOffset$$64, &_155$$78);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&chunkMarkSubset$$64, &chunkMarkSubset$$64);
			ZEPHIR_INIT_NVAR(&chunkSliceMap$$64);
			array_init(&chunkSliceMap$$64);
			ZEPHIR_CPY_WRT(&chunkSliceMap$$64, &chunkSliceMap$$64);
			if (Z_TYPE_P(&chunkMarkSubset$$64) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_158$$78);
				zephir_string_to_char_array(&_158$$78, &chunkMarkSubset$$64);
				_157$$78 = &_158$$78;
			} else {
				_157$$78 = &chunkMarkSubset$$64;
			}
			zephir_is_iterable(_157$$78, 0, "phalcon/Mvc/Router.zep", 2561);
			if (Z_TYPE_P(_157$$78) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_157$$78), _159$$78)
				{
					ZEPHIR_INIT_NVAR(&chunkMarkId$$64);
					ZVAL_COPY(&chunkMarkId$$64, _159$$78);
					ZEPHIR_OBS_NVAR(&_160$$79);
					zephir_array_fetch(&_160$$79, &combinedMark, &chunkMarkId$$64, PH_NOISY, "phalcon/Mvc/Router.zep", 2558);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&chunkSliceMap$$64, &chunkMarkId$$64, &_160$$79, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _157$$78, "rewind", NULL, 0);
				zephir_check_call_status();
				_162$$78 = 1;
				while (1) {
					if (_162$$78) {
						_162$$78 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _157$$78, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_161$$78, _157$$78, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_161$$78)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&chunkMarkId$$64, _157$$78, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&_163$$80);
						zephir_array_fetch(&_163$$80, &combinedMark, &chunkMarkId$$64, PH_NOISY, "phalcon/Mvc/Router.zep", 2558);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&chunkSliceMap$$64, &chunkMarkId$$64, &_163$$80, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&chunkMarkId$$64);
			ZEPHIR_INIT_NVAR(&_164$$78);
			zephir_fast_join_str(&_164$$78, SL("|"), &chunkSlice$$64);
			ZEPHIR_INIT_NVAR(&chunkPattern$$64);
			ZEPHIR_CONCAT_SVS(&chunkPattern$$64, "#^(?|", &_164$$78, ")$#u");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&chunkPattern$$64, &chunkPattern$$64);
			ZEPHIR_INIT_NVAR(&_165$$78);
			ZEPHIR_INIT_NVAR(&_166$$78);
			ZVAL_STRING(&_166$$78, "");
			ZEPHIR_INIT_NVAR(&_167$$78);
			ZEPHIR_INIT_NVAR(&_168$$78);
			ZVAL_STRING(&_168$$78, "");
			zephir_preg_match(&_167$$78, &chunkPattern$$64, &_168$$78, &_165$$78, 0, 0 , 0 );
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_167$$78)) {
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
			ZEPHIR_INIT_NVAR(&_169$$78);
			ZVAL_LONG(&_169$$78, 10);
			ZEPHIR_INIT_NVAR(&_170$$78);
			zephir_add_function(&_170$$78, &chunkOffset$$64, &_169$$78);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&chunkOffset$$64, &_170$$78);
		}
		_171$$64 = zephir_array_isset_value(&combinedRegexDisabled, &method);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_171$$64) {
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
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 160, stream, &_0, &separator_zv, enclosure, escape);
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
	if (0 == length) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 161, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_3, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_4, offset);
	ZVAL_LONG(&_5, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 161, &filename_zv, &_3, context, &_4, &_5);
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
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 162, &filename_zv, data, &_0, context);
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
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 163, &filename_zv, &mode_zv, &_0, context);
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
	if (0 == length) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", &_1, 164, handle, &data_zv, &_0);
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
	ZEPHIR_RETURN_CALL_FUNCTION("is_dir", NULL, 165, &filename_zv);
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
	ZEPHIR_RETURN_CALL_FUNCTION("mkdir", NULL, 167, &directory_zv, &_0, &_1, context);
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
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 168, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

