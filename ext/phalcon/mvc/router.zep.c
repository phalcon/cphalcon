
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 266, &_2$$3, &_1$$3);
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
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 266, &_4$$3, &_3$$3);
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
		goto zephir_switch_0_end;
	zephir_switch_0_clause_1: ;
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 1, 0);
		zephir_array_fast_append(&_1$$4, route);
		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$4, &_1$$4, &_2$$4);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 287, &_0$$4);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 288, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 288, &__$false);
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
	zval _29$$4, _54$$11;
	zend_bool _33, _73, _99, _142, _9$$4, _24$$6, _35$$11, _49$$13, _69$$18, _80$$21, _95$$24, _106$$27, _131$$30, _127$$31, _138$$34, _159$$37, _155$$38, _166$$41;
	zend_string *_6, *_62, *_88, *_114, *_18$$6, *_43$$13, *_120$$30, *_148$$37;
	zend_ulong _5, _61, _87, _113, _17$$6, _42$$13, _119$$30, _147$$37;
	zval route, cb, converters, convName, converter, dumpedRoutes, routeToIdx, scalarIdx, scalarSubKey, scalarVal, methodRoutesScalar, candidatesScalar, staticScalar, innerKey, innerVal, mostInnerVal, mostInnerArr, _0, _1, *_2, _3, *_4, _32, _57, *_58, _59, *_60, _72, _83, *_84, _85, *_86, _98, _109, *_110, _111, *_112, _141, _169, _7$$4, _30$$4, _31$$4, _10$$5, _11$$5, _12$$5, *_14$$6, _15$$6, *_16$$6, _23$$6, _19$$8, _20$$8, _22$$8, _25$$10, _26$$10, _28$$10, _34$$11, _55$$11, _56$$11, _36$$12, _37$$12, _38$$12, *_39$$13, _40$$13, *_41$$13, _48$$13, _44$$15, _45$$15, _47$$15, _50$$17, _51$$17, _53$$17, *_63$$18, _64$$18, *_65$$18, _68$$18, _66$$19, _67$$19, _70$$20, _71$$20, *_74$$21, _75$$21, *_76$$21, _79$$21, _77$$22, _78$$22, _81$$23, _82$$23, *_89$$24, _90$$24, *_91$$24, _94$$24, _92$$25, _93$$25, _96$$26, _97$$26, *_100$$27, _101$$27, *_102$$27, _105$$27, _103$$28, _104$$28, _107$$29, _108$$29, _115$$30, *_116$$30, _117$$30, *_118$$30, _130$$30, *_121$$31, _122$$31, *_123$$31, _126$$31, _124$$32, _125$$32, _128$$33, _129$$33, *_132$$34, _133$$34, *_134$$34, _137$$34, _135$$35, _136$$35, _139$$36, _140$$36, _143$$37, *_144$$37, _145$$37, *_146$$37, _158$$37, *_149$$38, _150$$38, *_151$$38, _154$$38, _152$$39, _153$$39, _156$$40, _157$$40, *_160$$41, _161$$41, *_162$$41, _165$$41, _163$$42, _164$$42, _167$$43, _168$$43;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_13 = NULL, *_21 = NULL, *_27 = NULL, *_46 = NULL, *_52 = NULL;
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
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_59);
	ZVAL_UNDEF(&_72);
	ZVAL_UNDEF(&_83);
	ZVAL_UNDEF(&_85);
	ZVAL_UNDEF(&_98);
	ZVAL_UNDEF(&_109);
	ZVAL_UNDEF(&_111);
	ZVAL_UNDEF(&_141);
	ZVAL_UNDEF(&_169);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_30$$4);
	ZVAL_UNDEF(&_31$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_34$$11);
	ZVAL_UNDEF(&_55$$11);
	ZVAL_UNDEF(&_56$$11);
	ZVAL_UNDEF(&_36$$12);
	ZVAL_UNDEF(&_37$$12);
	ZVAL_UNDEF(&_38$$12);
	ZVAL_UNDEF(&_40$$13);
	ZVAL_UNDEF(&_48$$13);
	ZVAL_UNDEF(&_44$$15);
	ZVAL_UNDEF(&_45$$15);
	ZVAL_UNDEF(&_47$$15);
	ZVAL_UNDEF(&_50$$17);
	ZVAL_UNDEF(&_51$$17);
	ZVAL_UNDEF(&_53$$17);
	ZVAL_UNDEF(&_64$$18);
	ZVAL_UNDEF(&_68$$18);
	ZVAL_UNDEF(&_66$$19);
	ZVAL_UNDEF(&_67$$19);
	ZVAL_UNDEF(&_70$$20);
	ZVAL_UNDEF(&_71$$20);
	ZVAL_UNDEF(&_75$$21);
	ZVAL_UNDEF(&_79$$21);
	ZVAL_UNDEF(&_77$$22);
	ZVAL_UNDEF(&_78$$22);
	ZVAL_UNDEF(&_81$$23);
	ZVAL_UNDEF(&_82$$23);
	ZVAL_UNDEF(&_90$$24);
	ZVAL_UNDEF(&_94$$24);
	ZVAL_UNDEF(&_92$$25);
	ZVAL_UNDEF(&_93$$25);
	ZVAL_UNDEF(&_96$$26);
	ZVAL_UNDEF(&_97$$26);
	ZVAL_UNDEF(&_101$$27);
	ZVAL_UNDEF(&_105$$27);
	ZVAL_UNDEF(&_103$$28);
	ZVAL_UNDEF(&_104$$28);
	ZVAL_UNDEF(&_107$$29);
	ZVAL_UNDEF(&_108$$29);
	ZVAL_UNDEF(&_115$$30);
	ZVAL_UNDEF(&_117$$30);
	ZVAL_UNDEF(&_130$$30);
	ZVAL_UNDEF(&_122$$31);
	ZVAL_UNDEF(&_126$$31);
	ZVAL_UNDEF(&_124$$32);
	ZVAL_UNDEF(&_125$$32);
	ZVAL_UNDEF(&_128$$33);
	ZVAL_UNDEF(&_129$$33);
	ZVAL_UNDEF(&_133$$34);
	ZVAL_UNDEF(&_137$$34);
	ZVAL_UNDEF(&_135$$35);
	ZVAL_UNDEF(&_136$$35);
	ZVAL_UNDEF(&_139$$36);
	ZVAL_UNDEF(&_140$$36);
	ZVAL_UNDEF(&_143$$37);
	ZVAL_UNDEF(&_145$$37);
	ZVAL_UNDEF(&_158$$37);
	ZVAL_UNDEF(&_150$$38);
	ZVAL_UNDEF(&_154$$38);
	ZVAL_UNDEF(&_152$$39);
	ZVAL_UNDEF(&_153$$39);
	ZVAL_UNDEF(&_156$$40);
	ZVAL_UNDEF(&_157$$40);
	ZVAL_UNDEF(&_161$$41);
	ZVAL_UNDEF(&_165$$41);
	ZVAL_UNDEF(&_163$$42);
	ZVAL_UNDEF(&_164$$42);
	ZVAL_UNDEF(&_167$$43);
	ZVAL_UNDEF(&_168$$43);
	ZVAL_UNDEF(&_29$$4);
	ZVAL_UNDEF(&_54$$11);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 288, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rebuildMethodIndex", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&dumpedRoutes);
	array_init(&dumpedRoutes);
	ZEPHIR_INIT_VAR(&routeToIdx);
	array_init(&routeToIdx);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 287, PH_NOISY_CC | PH_READONLY);
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
			ZEPHIR_CALL_FUNCTION(&_7$$4, "spl_object_id", &_8, 53, &route);
			zephir_check_call_status();
			zephir_array_update_zval(&routeToIdx, &_7$$4, &scalarIdx, PH_COPY | PH_SEPARATE);
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
				ZEPHIR_CALL_METHOD(NULL, &_10$$5, "__construct", &_13, 9, &_12$$5);
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
							ZEPHIR_CALL_METHOD(NULL, &_19$$8, "__construct", &_13, 9, &_22$$8);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_19$$8, "phalcon/Mvc/Router.zep", 703);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _14$$6, "rewind", NULL, 0);
					zephir_check_call_status();
					_24$$6 = 1;
					while (1) {
						if (_24$$6) {
							_24$$6 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _14$$6, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_23$$6, _14$$6, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_23$$6)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&convName, _14$$6, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&converter, _14$$6, "current", NULL, 0);
						zephir_check_call_status();
							if (zephir_is_instance_of(&converter, SL("Closure"))) {
								ZEPHIR_INIT_NVAR(&_25$$10);
								object_init_ex(&_25$$10, phalcon_mvc_router_exception_ce);
								ZEPHIR_CALL_METHOD(&_26$$10, &route, "getRouteId", &_27, 0);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_28$$10);
								ZEPHIR_CONCAT_SVSVS(&_28$$10, "Cannot cache router: route id '", &_26$$10, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
								ZEPHIR_CALL_METHOD(NULL, &_25$$10, "__construct", &_13, 9, &_28$$10);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_25$$10, "phalcon/Mvc/Router.zep", 703);
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&converter);
				ZEPHIR_INIT_NVAR(&convName);
			}
			ZEPHIR_INIT_NVAR(&_29$$4);
			zephir_create_array(&_29$$4, 9, 0);
			ZEPHIR_INIT_NVAR(&_30$$4);
			zephir_get_class(&_30$$4, &route, 0);
			zephir_array_update_string(&_29$$4, SL("class"), &_30$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_31$$4, &route, "getPattern", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_29$$4, SL("pattern"), &_31$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_31$$4, &route, "getPaths", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_29$$4, SL("paths"), &_31$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_31$$4, &route, "getHttpMethods", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_29$$4, SL("methods"), &_31$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_31$$4, &route, "getHostname", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_29$$4, SL("hostname"), &_31$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_31$$4, &route, "getName", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_29$$4, SL("name"), &_31$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_31$$4, &route, "getRouteId", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_29$$4, SL("id"), &_31$$4, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_29$$4, SL("beforeMatch"), &cb, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_29$$4, SL("converters"), &converters, PH_COPY | PH_SEPARATE);
			zephir_array_append(&dumpedRoutes, &_29$$4, PH_SEPARATE, "phalcon/Mvc/Router.zep", 718);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _2, "rewind", NULL, 0);
		zephir_check_call_status();
		_33 = 1;
		while (1) {
			if (_33) {
				_33 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _2, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_32, _2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_32)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&scalarIdx, _2, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, _2, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_34$$11, "spl_object_id", &_8, 53, &route);
				zephir_check_call_status();
				zephir_array_update_zval(&routeToIdx, &_34$$11, &scalarIdx, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&cb, &route, "getBeforeMatch", NULL, 0);
				zephir_check_call_status();
				_35$$11 = Z_TYPE_P(&cb) != IS_NULL;
				if (_35$$11) {
					_35$$11 = zephir_is_instance_of(&cb, SL("Closure"));
				}
				if (_35$$11) {
					ZEPHIR_INIT_NVAR(&_36$$12);
					object_init_ex(&_36$$12, phalcon_mvc_router_exception_ce);
					ZEPHIR_CALL_METHOD(&_37$$12, &route, "getRouteId", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_38$$12);
					ZEPHIR_CONCAT_SVS(&_38$$12, "Cannot cache router: route id '", &_37$$12, "' has a Closure beforeMatch - only string/array callables are cacheable");
					ZEPHIR_CALL_METHOD(NULL, &_36$$12, "__construct", &_13, 9, &_38$$12);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_36$$12, "phalcon/Mvc/Router.zep", 692);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&converters, &route, "getConverters", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&converters) == IS_ARRAY) {
					if (Z_TYPE_P(&converters) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_40$$13);
						zephir_string_to_char_array(&_40$$13, &converters);
						_39$$13 = &_40$$13;
					} else {
						_39$$13 = &converters;
					}
					zephir_is_iterable(_39$$13, 0, "phalcon/Mvc/Router.zep", 706);
					if (Z_TYPE_P(_39$$13) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_39$$13), _42$$13, _43$$13, _41$$13)
						{
							ZEPHIR_INIT_NVAR(&convName);
							if (_43$$13 != NULL) { 
								ZVAL_STR_COPY(&convName, _43$$13);
							} else {
								ZVAL_LONG(&convName, _42$$13);
							}
							ZEPHIR_INIT_NVAR(&converter);
							ZVAL_COPY(&converter, _41$$13);
							if (zephir_is_instance_of(&converter, SL("Closure"))) {
								ZEPHIR_INIT_NVAR(&_44$$15);
								object_init_ex(&_44$$15, phalcon_mvc_router_exception_ce);
								ZEPHIR_CALL_METHOD(&_45$$15, &route, "getRouteId", &_46, 0);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_47$$15);
								ZEPHIR_CONCAT_SVSVS(&_47$$15, "Cannot cache router: route id '", &_45$$15, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
								ZEPHIR_CALL_METHOD(NULL, &_44$$15, "__construct", &_13, 9, &_47$$15);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_44$$15, "phalcon/Mvc/Router.zep", 703);
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _39$$13, "rewind", NULL, 0);
						zephir_check_call_status();
						_49$$13 = 1;
						while (1) {
							if (_49$$13) {
								_49$$13 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _39$$13, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_48$$13, _39$$13, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_48$$13)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&convName, _39$$13, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&converter, _39$$13, "current", NULL, 0);
							zephir_check_call_status();
								if (zephir_is_instance_of(&converter, SL("Closure"))) {
									ZEPHIR_INIT_NVAR(&_50$$17);
									object_init_ex(&_50$$17, phalcon_mvc_router_exception_ce);
									ZEPHIR_CALL_METHOD(&_51$$17, &route, "getRouteId", &_52, 0);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_53$$17);
									ZEPHIR_CONCAT_SVSVS(&_53$$17, "Cannot cache router: route id '", &_51$$17, "' has a Closure converter for '", &convName, "' - only string/array callables are cacheable");
									ZEPHIR_CALL_METHOD(NULL, &_50$$17, "__construct", &_13, 9, &_53$$17);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_50$$17, "phalcon/Mvc/Router.zep", 703);
									ZEPHIR_MM_RESTORE();
									return;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&converter);
					ZEPHIR_INIT_NVAR(&convName);
				}
				ZEPHIR_INIT_NVAR(&_54$$11);
				zephir_create_array(&_54$$11, 9, 0);
				ZEPHIR_INIT_NVAR(&_55$$11);
				zephir_get_class(&_55$$11, &route, 0);
				zephir_array_update_string(&_54$$11, SL("class"), &_55$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_56$$11, &route, "getPattern", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_54$$11, SL("pattern"), &_56$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_56$$11, &route, "getPaths", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_54$$11, SL("paths"), &_56$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_56$$11, &route, "getHttpMethods", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_54$$11, SL("methods"), &_56$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_56$$11, &route, "getHostname", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_54$$11, SL("hostname"), &_56$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_56$$11, &route, "getName", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_54$$11, SL("name"), &_56$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_56$$11, &route, "getRouteId", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_54$$11, SL("id"), &_56$$11, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_54$$11, SL("beforeMatch"), &cb, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_54$$11, SL("converters"), &converters, PH_COPY | PH_SEPARATE);
				zephir_array_append(&dumpedRoutes, &_54$$11, PH_SEPARATE, "phalcon/Mvc/Router.zep", 718);
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&scalarIdx);
	ZEPHIR_INIT_VAR(&methodRoutesScalar);
	array_init(&methodRoutesScalar);
	zephir_read_property_cached(&_57, this_ptr, _zephir_prop_2, 289, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_57) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_59);
		zephir_string_to_char_array(&_59, &_57);
		_58 = &_59;
	} else {
		_58 = &_57;
	}
	zephir_is_iterable(_58, 0, "phalcon/Mvc/Router.zep", 730);
	if (Z_TYPE_P(_58) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_58), _61, _62, _60)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_62 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _62);
			} else {
				ZVAL_LONG(&innerKey, _61);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _60);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_64$$18);
				zephir_string_to_char_array(&_64$$18, &innerVal);
				_63$$18 = &_64$$18;
			} else {
				_63$$18 = &innerVal;
			}
			zephir_is_iterable(_63$$18, 0, "phalcon/Mvc/Router.zep", 727);
			if (Z_TYPE_P(_63$$18) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_63$$18), _65$$18)
				{
					ZEPHIR_INIT_NVAR(&scalarVal);
					ZVAL_COPY(&scalarVal, _65$$18);
					ZEPHIR_CALL_FUNCTION(&_67$$19, "spl_object_id", &_8, 53, &scalarVal);
					zephir_check_call_status();
					zephir_array_fetch(&_66$$19, &routeToIdx, &_67$$19, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 725);
					zephir_array_append(&mostInnerArr, &_66$$19, PH_SEPARATE, "phalcon/Mvc/Router.zep", 725);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _63$$18, "rewind", NULL, 0);
				zephir_check_call_status();
				_69$$18 = 1;
				while (1) {
					if (_69$$18) {
						_69$$18 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _63$$18, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_68$$18, _63$$18, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_68$$18)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarVal, _63$$18, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_71$$20, "spl_object_id", &_8, 53, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_70$$20, &routeToIdx, &_71$$20, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 725);
						zephir_array_append(&mostInnerArr, &_70$$20, PH_SEPARATE, "phalcon/Mvc/Router.zep", 725);
				}
			}
			ZEPHIR_INIT_NVAR(&scalarVal);
			zephir_array_update_zval(&methodRoutesScalar, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _58, "rewind", NULL, 0);
		zephir_check_call_status();
		_73 = 1;
		while (1) {
			if (_73) {
				_73 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _58, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_72, _58, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_72)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, _58, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, _58, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_75$$21);
					zephir_string_to_char_array(&_75$$21, &innerVal);
					_74$$21 = &_75$$21;
				} else {
					_74$$21 = &innerVal;
				}
				zephir_is_iterable(_74$$21, 0, "phalcon/Mvc/Router.zep", 727);
				if (Z_TYPE_P(_74$$21) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_74$$21), _76$$21)
					{
						ZEPHIR_INIT_NVAR(&scalarVal);
						ZVAL_COPY(&scalarVal, _76$$21);
						ZEPHIR_CALL_FUNCTION(&_78$$22, "spl_object_id", &_8, 53, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_77$$22, &routeToIdx, &_78$$22, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 725);
						zephir_array_append(&mostInnerArr, &_77$$22, PH_SEPARATE, "phalcon/Mvc/Router.zep", 725);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _74$$21, "rewind", NULL, 0);
					zephir_check_call_status();
					_80$$21 = 1;
					while (1) {
						if (_80$$21) {
							_80$$21 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _74$$21, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_79$$21, _74$$21, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_79$$21)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarVal, _74$$21, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&_82$$23, "spl_object_id", &_8, 53, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_81$$23, &routeToIdx, &_82$$23, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 725);
							zephir_array_append(&mostInnerArr, &_81$$23, PH_SEPARATE, "phalcon/Mvc/Router.zep", 725);
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
	zephir_read_property_cached(&_83, this_ptr, _zephir_prop_3, 290, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_83) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_85);
		zephir_string_to_char_array(&_85, &_83);
		_84 = &_85;
	} else {
		_84 = &_83;
	}
	zephir_is_iterable(_84, 0, "phalcon/Mvc/Router.zep", 739);
	if (Z_TYPE_P(_84) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_84), _87, _88, _86)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_88 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _88);
			} else {
				ZVAL_LONG(&innerKey, _87);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _86);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_90$$24);
				zephir_string_to_char_array(&_90$$24, &innerVal);
				_89$$24 = &_90$$24;
			} else {
				_89$$24 = &innerVal;
			}
			zephir_is_iterable(_89$$24, 0, "phalcon/Mvc/Router.zep", 736);
			if (Z_TYPE_P(_89$$24) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_89$$24), _91$$24)
				{
					ZEPHIR_INIT_NVAR(&scalarVal);
					ZVAL_COPY(&scalarVal, _91$$24);
					ZEPHIR_CALL_FUNCTION(&_93$$25, "spl_object_id", &_8, 53, &scalarVal);
					zephir_check_call_status();
					zephir_array_fetch(&_92$$25, &routeToIdx, &_93$$25, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 734);
					zephir_array_append(&mostInnerArr, &_92$$25, PH_SEPARATE, "phalcon/Mvc/Router.zep", 734);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _89$$24, "rewind", NULL, 0);
				zephir_check_call_status();
				_95$$24 = 1;
				while (1) {
					if (_95$$24) {
						_95$$24 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _89$$24, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_94$$24, _89$$24, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_94$$24)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarVal, _89$$24, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_97$$26, "spl_object_id", &_8, 53, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_96$$26, &routeToIdx, &_97$$26, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 734);
						zephir_array_append(&mostInnerArr, &_96$$26, PH_SEPARATE, "phalcon/Mvc/Router.zep", 734);
				}
			}
			ZEPHIR_INIT_NVAR(&scalarVal);
			zephir_array_update_zval(&candidatesScalar, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _84, "rewind", NULL, 0);
		zephir_check_call_status();
		_99 = 1;
		while (1) {
			if (_99) {
				_99 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _84, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_98, _84, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_98)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, _84, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, _84, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_101$$27);
					zephir_string_to_char_array(&_101$$27, &innerVal);
					_100$$27 = &_101$$27;
				} else {
					_100$$27 = &innerVal;
				}
				zephir_is_iterable(_100$$27, 0, "phalcon/Mvc/Router.zep", 736);
				if (Z_TYPE_P(_100$$27) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_100$$27), _102$$27)
					{
						ZEPHIR_INIT_NVAR(&scalarVal);
						ZVAL_COPY(&scalarVal, _102$$27);
						ZEPHIR_CALL_FUNCTION(&_104$$28, "spl_object_id", &_8, 53, &scalarVal);
						zephir_check_call_status();
						zephir_array_fetch(&_103$$28, &routeToIdx, &_104$$28, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 734);
						zephir_array_append(&mostInnerArr, &_103$$28, PH_SEPARATE, "phalcon/Mvc/Router.zep", 734);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _100$$27, "rewind", NULL, 0);
					zephir_check_call_status();
					_106$$27 = 1;
					while (1) {
						if (_106$$27) {
							_106$$27 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _100$$27, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_105$$27, _100$$27, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_105$$27)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarVal, _100$$27, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&_108$$29, "spl_object_id", &_8, 53, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_107$$29, &routeToIdx, &_108$$29, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 734);
							zephir_array_append(&mostInnerArr, &_107$$29, PH_SEPARATE, "phalcon/Mvc/Router.zep", 734);
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
	zephir_read_property_cached(&_109, this_ptr, _zephir_prop_4, 291, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_109) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_111);
		zephir_string_to_char_array(&_111, &_109);
		_110 = &_111;
	} else {
		_110 = &_109;
	}
	zephir_is_iterable(_110, 0, "phalcon/Mvc/Router.zep", 751);
	if (Z_TYPE_P(_110) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_110), _113, _114, _112)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_114 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _114);
			} else {
				ZVAL_LONG(&innerKey, _113);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _112);
			ZEPHIR_INIT_NVAR(&_115$$30);
			array_init(&_115$$30);
			zephir_array_update_zval(&staticScalar, &innerKey, &_115$$30, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_117$$30);
				zephir_string_to_char_array(&_117$$30, &innerVal);
				_116$$30 = &_117$$30;
			} else {
				_116$$30 = &innerVal;
			}
			zephir_is_iterable(_116$$30, 0, "phalcon/Mvc/Router.zep", 749);
			if (Z_TYPE_P(_116$$30) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_116$$30), _119$$30, _120$$30, _118$$30)
				{
					ZEPHIR_INIT_NVAR(&scalarSubKey);
					if (_120$$30 != NULL) { 
						ZVAL_STR_COPY(&scalarSubKey, _120$$30);
					} else {
						ZVAL_LONG(&scalarSubKey, _119$$30);
					}
					ZEPHIR_INIT_NVAR(&mostInnerVal);
					ZVAL_COPY(&mostInnerVal, _118$$30);
					ZEPHIR_INIT_NVAR(&mostInnerArr);
					array_init(&mostInnerArr);
					if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_122$$31);
						zephir_string_to_char_array(&_122$$31, &mostInnerVal);
						_121$$31 = &_122$$31;
					} else {
						_121$$31 = &mostInnerVal;
					}
					zephir_is_iterable(_121$$31, 0, "phalcon/Mvc/Router.zep", 747);
					if (Z_TYPE_P(_121$$31) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_121$$31), _123$$31)
						{
							ZEPHIR_INIT_NVAR(&scalarVal);
							ZVAL_COPY(&scalarVal, _123$$31);
							ZEPHIR_CALL_FUNCTION(&_125$$32, "spl_object_id", &_8, 53, &scalarVal);
							zephir_check_call_status();
							zephir_array_fetch(&_124$$32, &routeToIdx, &_125$$32, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
							zephir_array_append(&mostInnerArr, &_124$$32, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _121$$31, "rewind", NULL, 0);
						zephir_check_call_status();
						_127$$31 = 1;
						while (1) {
							if (_127$$31) {
								_127$$31 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _121$$31, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_126$$31, _121$$31, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_126$$31)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&scalarVal, _121$$31, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&_129$$33, "spl_object_id", &_8, 53, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_128$$33, &routeToIdx, &_129$$33, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
								zephir_array_append(&mostInnerArr, &_128$$33, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
						}
					}
					ZEPHIR_INIT_NVAR(&scalarVal);
					zephir_array_update_multi(&staticScalar, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _116$$30, "rewind", NULL, 0);
				zephir_check_call_status();
				_131$$30 = 1;
				while (1) {
					if (_131$$30) {
						_131$$30 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _116$$30, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_130$$30, _116$$30, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_130$$30)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarSubKey, _116$$30, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&mostInnerVal, _116$$30, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_133$$34);
							zephir_string_to_char_array(&_133$$34, &mostInnerVal);
							_132$$34 = &_133$$34;
						} else {
							_132$$34 = &mostInnerVal;
						}
						zephir_is_iterable(_132$$34, 0, "phalcon/Mvc/Router.zep", 747);
						if (Z_TYPE_P(_132$$34) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_132$$34), _134$$34)
							{
								ZEPHIR_INIT_NVAR(&scalarVal);
								ZVAL_COPY(&scalarVal, _134$$34);
								ZEPHIR_CALL_FUNCTION(&_136$$35, "spl_object_id", &_8, 53, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_135$$35, &routeToIdx, &_136$$35, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
								zephir_array_append(&mostInnerArr, &_135$$35, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _132$$34, "rewind", NULL, 0);
							zephir_check_call_status();
							_138$$34 = 1;
							while (1) {
								if (_138$$34) {
									_138$$34 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _132$$34, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_137$$34, _132$$34, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_137$$34)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarVal, _132$$34, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_140$$36, "spl_object_id", &_8, 53, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_139$$36, &routeToIdx, &_140$$36, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
									zephir_array_append(&mostInnerArr, &_139$$36, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
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
		ZEPHIR_CALL_METHOD(NULL, _110, "rewind", NULL, 0);
		zephir_check_call_status();
		_142 = 1;
		while (1) {
			if (_142) {
				_142 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _110, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_141, _110, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_141)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, _110, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, _110, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_143$$37);
				array_init(&_143$$37);
				zephir_array_update_zval(&staticScalar, &innerKey, &_143$$37, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_145$$37);
					zephir_string_to_char_array(&_145$$37, &innerVal);
					_144$$37 = &_145$$37;
				} else {
					_144$$37 = &innerVal;
				}
				zephir_is_iterable(_144$$37, 0, "phalcon/Mvc/Router.zep", 749);
				if (Z_TYPE_P(_144$$37) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_144$$37), _147$$37, _148$$37, _146$$37)
					{
						ZEPHIR_INIT_NVAR(&scalarSubKey);
						if (_148$$37 != NULL) { 
							ZVAL_STR_COPY(&scalarSubKey, _148$$37);
						} else {
							ZVAL_LONG(&scalarSubKey, _147$$37);
						}
						ZEPHIR_INIT_NVAR(&mostInnerVal);
						ZVAL_COPY(&mostInnerVal, _146$$37);
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_150$$38);
							zephir_string_to_char_array(&_150$$38, &mostInnerVal);
							_149$$38 = &_150$$38;
						} else {
							_149$$38 = &mostInnerVal;
						}
						zephir_is_iterable(_149$$38, 0, "phalcon/Mvc/Router.zep", 747);
						if (Z_TYPE_P(_149$$38) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_149$$38), _151$$38)
							{
								ZEPHIR_INIT_NVAR(&scalarVal);
								ZVAL_COPY(&scalarVal, _151$$38);
								ZEPHIR_CALL_FUNCTION(&_153$$39, "spl_object_id", &_8, 53, &scalarVal);
								zephir_check_call_status();
								zephir_array_fetch(&_152$$39, &routeToIdx, &_153$$39, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
								zephir_array_append(&mostInnerArr, &_152$$39, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _149$$38, "rewind", NULL, 0);
							zephir_check_call_status();
							_155$$38 = 1;
							while (1) {
								if (_155$$38) {
									_155$$38 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _149$$38, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_154$$38, _149$$38, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_154$$38)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarVal, _149$$38, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_157$$40, "spl_object_id", &_8, 53, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_156$$40, &routeToIdx, &_157$$40, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
									zephir_array_append(&mostInnerArr, &_156$$40, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
							}
						}
						ZEPHIR_INIT_NVAR(&scalarVal);
						zephir_array_update_multi(&staticScalar, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _144$$37, "rewind", NULL, 0);
					zephir_check_call_status();
					_159$$37 = 1;
					while (1) {
						if (_159$$37) {
							_159$$37 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _144$$37, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_158$$37, _144$$37, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_158$$37)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarSubKey, _144$$37, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&mostInnerVal, _144$$37, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&mostInnerArr);
							array_init(&mostInnerArr);
							if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_161$$41);
								zephir_string_to_char_array(&_161$$41, &mostInnerVal);
								_160$$41 = &_161$$41;
							} else {
								_160$$41 = &mostInnerVal;
							}
							zephir_is_iterable(_160$$41, 0, "phalcon/Mvc/Router.zep", 747);
							if (Z_TYPE_P(_160$$41) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_160$$41), _162$$41)
								{
									ZEPHIR_INIT_NVAR(&scalarVal);
									ZVAL_COPY(&scalarVal, _162$$41);
									ZEPHIR_CALL_FUNCTION(&_164$$42, "spl_object_id", &_8, 53, &scalarVal);
									zephir_check_call_status();
									zephir_array_fetch(&_163$$42, &routeToIdx, &_164$$42, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
									zephir_array_append(&mostInnerArr, &_163$$42, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _160$$41, "rewind", NULL, 0);
								zephir_check_call_status();
								_166$$41 = 1;
								while (1) {
									if (_166$$41) {
										_166$$41 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _160$$41, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_165$$41, _160$$41, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_165$$41)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&scalarVal, _160$$41, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_168$$43, "spl_object_id", &_8, 53, &scalarVal);
										zephir_check_call_status();
										zephir_array_fetch(&_167$$43, &routeToIdx, &_168$$43, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 745);
										zephir_array_append(&mostInnerArr, &_167$$43, PH_SEPARATE, "phalcon/Mvc/Router.zep", 745);
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
	zephir_memory_observe(&_169);
	zephir_read_property_cached(&_169, this_ptr, _zephir_prop_5, 292, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("staticShadowedByMethod"), &_169, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_169);
	zephir_read_property_cached(&_169, this_ptr, _zephir_prop_6, 293, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("hostnameByMethod"), &_169, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_169);
	zephir_read_property_cached(&_169, this_ptr, _zephir_prop_7, 294, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("hostnameLessByMethod"), &_169, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_169);
	zephir_read_property_cached(&_169, this_ptr, _zephir_prop_8, 295, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("combinedRegexByMethod"), &_169, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_169);
	zephir_read_property_cached(&_169, this_ptr, _zephir_prop_9, 296, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("combinedRegexDisabled"), &_169, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_169);
	zephir_read_property_cached(&_169, this_ptr, _zephir_prop_10, 297, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("combinedRegexMarkMap"), &_169, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_169);
	zephir_read_property_cached(&_169, this_ptr, _zephir_prop_11, 298, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("routeMeta"), &_169, PH_COPY | PH_SEPARATE);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 287, &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 289, &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 290, &_2);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 298, &_3);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 291, &_4);
	ZEPHIR_INIT_VAR(&_5);
	array_init(&_5);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 292, &_5);
	ZEPHIR_INIT_VAR(&_6);
	array_init(&_6);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 293, &_6);
	ZEPHIR_INIT_VAR(&_7);
	array_init(&_7);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 294, &_7);
	ZEPHIR_INIT_VAR(&_8);
	array_init(&_8);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 295, &_8);
	ZEPHIR_INIT_VAR(&_9);
	array_init(&_9);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 296, &_9);
	ZEPHIR_INIT_VAR(&_10);
	array_init(&_10);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 297, &_10);
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 288, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 288, &__$false);
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
	ZEPHIR_CALL_FUNCTION(&_1, "getmypid", NULL, 268);
	zephir_check_call_status();
	zephir_cast_to_string(&_2, &_1);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSV(&_3, &path_zv, ".tmp.", &_2);
	ZEPHIR_CPY_WRT(&tmpPath, &_3);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "phpFilePutContents", NULL, 0, &tmpPath, &php);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SV(&_6$$3, "Failed to write router cache temp file: ", &tmpPath);
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 9, &_6$$3);
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
		ZEPHIR_CALL_METHOD(NULL, &_8$$4, "__construct", NULL, 9, &_9$$4);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 299, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("namespace"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 300, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("module"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 301, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("controller"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 302, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("action"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 303, PH_NOISY_CC);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 288, PH_NOISY_CC | PH_READONLY);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 304, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 0)) {
		zephir_memory_observe(&url);
		if (zephir_array_isset_string_fetch(&url, &_GET, SL("_url"), 0)) {
			if (!(ZEPHIR_IS_EMPTY(&url))) {
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "extractRealUri", NULL, 0, &url);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
	} else {
		ZEPHIR_OBS_NVAR(&url);
		if (zephir_array_isset_string_fetch(&url, &_SERVER, SL("REQUEST_URI"), 0)) {
			if (!(ZEPHIR_IS_EMPTY(&url))) {
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "extractRealUri", NULL, 0, &url);
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
	zend_bool _10;
	zend_string *_8;
	zend_ulong _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routeId, routeId_sub, localRouteId, route, key, _0, _3, *_4, _5, *_6, _9, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeId_sub);
	ZVAL_UNDEF(&localRouteId);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 305, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&key, &_0, routeId, 0)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 287, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_2$$3);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY, "phalcon/Mvc/Router.zep", 969);
		RETURN_CCTOR(&_2$$3);
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 287, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_3) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &_3);
		_4 = &_5;
	} else {
		_4 = &_3;
	}
	zephir_is_iterable(_4, 0, "phalcon/Mvc/Router.zep", 981);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4), _7, _8, _6)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&key, _8);
			} else {
				ZVAL_LONG(&key, _7);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _6);
			ZEPHIR_CALL_METHOD(&localRouteId, &route, "getRouteId", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("keyRouteIds"), &localRouteId, &key);
			if (ZEPHIR_IS_EQUAL(&localRouteId, routeId)) {
				RETURN_CCTOR(&route);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, _4, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&localRouteId, &route, "getRouteId", NULL, 0);
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
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName)
{
	zend_bool _10;
	zend_ulong _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, route, routeName, key, _0, _3, *_4, _5, *_6, _9, _1$$3, _2$$3;
	zend_string *name = NULL, *_8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 306, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&key, &_0, &name_zv, 0)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 287, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_2$$3);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY, "phalcon/Mvc/Router.zep", 992);
		RETURN_CCTOR(&_2$$3);
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 287, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_3) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &_3);
		_4 = &_5;
	} else {
		_4 = &_3;
	}
	zephir_is_iterable(_4, 0, "phalcon/Mvc/Router.zep", 1007);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4), _7, _8, _6)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&key, _8);
			} else {
				ZVAL_LONG(&key, _7);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _6);
			ZEPHIR_CALL_METHOD(&routeName, &route, "getName", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&routeName))) {
				zephir_update_property_array(this_ptr, SL("keyRouteNames"), &routeName, &key);
				if (ZEPHIR_IS_EQUAL(&routeName, &name_zv)) {
					RETURN_CCTOR(&route);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, _4, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&routeName, &route, "getName", NULL, 0);
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
	zend_ulong _54$$39, _66$$40, _95$$62, _115$$84, _131$$103, _161$$140;
	zend_bool _1, _12, _15, _45, _46, _48, _19$$15, _23$$15, _26$$15, _40$$18, _84$$39, _76$$40, _70$$46, _71$$49, _73$$51, _78$$54, _79$$57, _81$$59, _104$$62, _98$$68, _99$$71, _101$$73, _106$$76, _107$$79, _109$$81, _146$$84, _139$$103, _134$$104, _136$$110, _141$$113, _143$$119, _169$$140, _164$$141, _166$$147, _171$$150, _173$$156;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_34 = NULL, *_37 = NULL, *_41 = NULL, *_69 = NULL, *_119 = NULL, *_122 = NULL, *_124 = NULL, *_127 = NULL, *_149 = NULL, *_152 = NULL, *_154 = NULL, *_157 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, __$true, __$false, __$null, action, beforeMatch, candidateMethod, candidateRoutes, container, controller, converter, converters, currentHostName, eventsManager, handledUri, hostname, matched, matches, matchPosition, module, notFoundPaths, params, paramsStr, part, parts, paths, pattern, position, realUri, regexHostName, request, requestMethod, route, routeFound, routeId, routeIdx, routeMeta, staticBeforeMatch, staticBucket, staticBucketMethod, staticHostname, staticHostRegex, staticMatched, staticRoute, strParams, vetoedRoutes, vnamespace, _0, _3, _4, _7, _8, _9, _11, _13, _14, _16, combinedChunks, combinedMarkMaps, combinedChunkIdx, combinedChunk, combinedMatchesLocal, combinedMarkLabel, combinedRouteIdx, combinedRoute, combinedRouteMeta, combinedBeforeMatch, combinedPaths, combinedConverters, combinedPart, combinedPosition, combinedMatchPosition, combinedConverter, _47, _49, _176, _177, _178, _179, _180, _184, _2$$5, _5$$8, _6$$9, _10$$11, _17$$15, _18$$15, _20$$15, _21$$15, _22$$15, _24$$15, _25$$15, _27$$15, _28$$15, _29$$18, _30$$18, *_31$$18, _32$$18, *_33$$18, _39$$18, _35$$23, _36$$27, _38$$28, _42$$33, _43$$37, _44$$38, _50$$39, *_51$$39, _52$$39, *_53$$39, _83$$39, _56$$40, _57$$40, _58$$40, _59$$40, *_63$$40, _64$$40, *_65$$40, _75$$40, _60$$44, _61$$43, _62$$45, _68$$47, _72$$50, _74$$52, _77$$55, _80$$58, _82$$60, _85$$62, _86$$62, _87$$62, _88$$62, *_92$$62, _93$$62, *_94$$62, _103$$62, _89$$66, _90$$65, _91$$67, _97$$69, _100$$72, _102$$74, _105$$77, _108$$80, _110$$82, _111$$84, *_112$$84, _113$$84, *_114$$84, _145$$84, _117$$85, _118$$85, _120$$90, _121$$93, _123$$97, _125$$99, _126$$101, *_128$$103, _129$$103, *_130$$103, _138$$103, _133$$105, _135$$109, _137$$111, _140$$114, _142$$118, _144$$120, _147$$122, _148$$122, _150$$127, _151$$130, _153$$134, _155$$136, _156$$138, *_158$$140, _159$$140, *_160$$140, _168$$140, _163$$142, _165$$146, _167$$148, _170$$151, _172$$155, _174$$157, _175$$161, _181$$169, _182$$171, _183$$173, _185$$174, _186$$174, _187$$174, _188$$174;
	zend_string *uri = NULL, *_55$$39, *_67$$40, *_96$$62, *_116$$84, *_132$$103, *_162$$140;
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
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
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
	ZVAL_UNDEF(&_47);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_176);
	ZVAL_UNDEF(&_177);
	ZVAL_UNDEF(&_178);
	ZVAL_UNDEF(&_179);
	ZVAL_UNDEF(&_180);
	ZVAL_UNDEF(&_184);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&_39$$18);
	ZVAL_UNDEF(&_35$$23);
	ZVAL_UNDEF(&_36$$27);
	ZVAL_UNDEF(&_38$$28);
	ZVAL_UNDEF(&_42$$33);
	ZVAL_UNDEF(&_43$$37);
	ZVAL_UNDEF(&_44$$38);
	ZVAL_UNDEF(&_50$$39);
	ZVAL_UNDEF(&_52$$39);
	ZVAL_UNDEF(&_83$$39);
	ZVAL_UNDEF(&_56$$40);
	ZVAL_UNDEF(&_57$$40);
	ZVAL_UNDEF(&_58$$40);
	ZVAL_UNDEF(&_59$$40);
	ZVAL_UNDEF(&_64$$40);
	ZVAL_UNDEF(&_75$$40);
	ZVAL_UNDEF(&_60$$44);
	ZVAL_UNDEF(&_61$$43);
	ZVAL_UNDEF(&_62$$45);
	ZVAL_UNDEF(&_68$$47);
	ZVAL_UNDEF(&_72$$50);
	ZVAL_UNDEF(&_74$$52);
	ZVAL_UNDEF(&_77$$55);
	ZVAL_UNDEF(&_80$$58);
	ZVAL_UNDEF(&_82$$60);
	ZVAL_UNDEF(&_85$$62);
	ZVAL_UNDEF(&_86$$62);
	ZVAL_UNDEF(&_87$$62);
	ZVAL_UNDEF(&_88$$62);
	ZVAL_UNDEF(&_93$$62);
	ZVAL_UNDEF(&_103$$62);
	ZVAL_UNDEF(&_89$$66);
	ZVAL_UNDEF(&_90$$65);
	ZVAL_UNDEF(&_91$$67);
	ZVAL_UNDEF(&_97$$69);
	ZVAL_UNDEF(&_100$$72);
	ZVAL_UNDEF(&_102$$74);
	ZVAL_UNDEF(&_105$$77);
	ZVAL_UNDEF(&_108$$80);
	ZVAL_UNDEF(&_110$$82);
	ZVAL_UNDEF(&_111$$84);
	ZVAL_UNDEF(&_113$$84);
	ZVAL_UNDEF(&_145$$84);
	ZVAL_UNDEF(&_117$$85);
	ZVAL_UNDEF(&_118$$85);
	ZVAL_UNDEF(&_120$$90);
	ZVAL_UNDEF(&_121$$93);
	ZVAL_UNDEF(&_123$$97);
	ZVAL_UNDEF(&_125$$99);
	ZVAL_UNDEF(&_126$$101);
	ZVAL_UNDEF(&_129$$103);
	ZVAL_UNDEF(&_138$$103);
	ZVAL_UNDEF(&_133$$105);
	ZVAL_UNDEF(&_135$$109);
	ZVAL_UNDEF(&_137$$111);
	ZVAL_UNDEF(&_140$$114);
	ZVAL_UNDEF(&_142$$118);
	ZVAL_UNDEF(&_144$$120);
	ZVAL_UNDEF(&_147$$122);
	ZVAL_UNDEF(&_148$$122);
	ZVAL_UNDEF(&_150$$127);
	ZVAL_UNDEF(&_151$$130);
	ZVAL_UNDEF(&_153$$134);
	ZVAL_UNDEF(&_155$$136);
	ZVAL_UNDEF(&_156$$138);
	ZVAL_UNDEF(&_159$$140);
	ZVAL_UNDEF(&_168$$140);
	ZVAL_UNDEF(&_163$$142);
	ZVAL_UNDEF(&_165$$146);
	ZVAL_UNDEF(&_167$$148);
	ZVAL_UNDEF(&_170$$151);
	ZVAL_UNDEF(&_172$$155);
	ZVAL_UNDEF(&_174$$157);
	ZVAL_UNDEF(&_175$$161);
	ZVAL_UNDEF(&_181$$169);
	ZVAL_UNDEF(&_182$$171);
	ZVAL_UNDEF(&_183$$173);
	ZVAL_UNDEF(&_185$$174);
	ZVAL_UNDEF(&_186$$174);
	ZVAL_UNDEF(&_187$$174);
	ZVAL_UNDEF(&_188$$174);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 307, PH_NOISY_CC | PH_READONLY);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 308, &_3);
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 309, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 309, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 310, &__$null);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_4, 311, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_4);
	if (Z_TYPE_P(&eventsManager) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_5$$8);
		ZVAL_STRING(&_5$$8, "router:beforeCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_5$$8, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_5, 312, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_6, 288, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_9, this_ptr, _zephir_prop_7, 290, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&candidateRoutes, &_9, &requestMethod, 0))) {
		ZEPHIR_INIT_NVAR(&candidateMethod);
		ZVAL_STRING(&candidateMethod, "*");
		ZEPHIR_OBS_NVAR(&candidateRoutes);
		zephir_read_property_cached(&_10$$11, this_ptr, _zephir_prop_7, 290, PH_NOISY_CC | PH_READONLY);
		zephir_array_isset_string_fetch(&candidateRoutes, &_10$$11, SL("*"), 0);
	}
	if (Z_TYPE_P(&candidateRoutes) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&candidateRoutes);
		array_init(&candidateRoutes);
	}
	zephir_read_property_cached(&_11, this_ptr, _zephir_prop_8, 293, PH_NOISY_CC | PH_READONLY);
	_12 = zephir_array_isset_value(&_11, &requestMethod);
	if (_12) {
		zephir_read_property_cached(&_13, this_ptr, _zephir_prop_8, 293, PH_NOISY_CC | PH_READONLY);
		_12 = !(zephir_isempty_dim(&_13, &requestMethod));
	}
	if (_12) {
		ZEPHIR_CALL_METHOD(&currentHostName, &request, "getHttpHost", NULL, 0);
		zephir_check_call_status();
	} else {
		zephir_read_property_cached(&_14, this_ptr, _zephir_prop_8, 293, PH_NOISY_CC | PH_READONLY);
		_15 = zephir_array_isset_value_string(&_14, SL("*"));
		if (_15) {
			zephir_read_property_cached(&_16, this_ptr, _zephir_prop_8, 293, PH_NOISY_CC | PH_READONLY);
			_15 = !(zephir_isempty_dim_string(&_16, SL("*")));
		}
		if (_15) {
			ZEPHIR_CALL_METHOD(&currentHostName, &request, "getHttpHost", NULL, 0);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_NULL) {
		ZEPHIR_INIT_VAR(&staticBucketMethod);
		ZVAL_NULL(&staticBucketMethod);
		zephir_read_property_cached(&_17$$15, this_ptr, _zephir_prop_9, 291, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_18$$15);
		zephir_array_fetch(&_18$$15, &_17$$15, &requestMethod, 0, "phalcon/Mvc/Router.zep", 1140);
		_19$$15 = zephir_array_isset_value(&_18$$15, &handledUri);
		if (_19$$15) {
			zephir_read_property_cached(&_20$$15, this_ptr, _zephir_prop_10, 292, PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&_21$$15);
			zephir_array_fetch(&_21$$15, &_20$$15, &requestMethod, 0, "phalcon/Mvc/Router.zep", 1141);
			_19$$15 = !(zephir_array_isset_value(&_21$$15, &handledUri));
		}
		if (_19$$15) {
			ZEPHIR_CPY_WRT(&staticBucketMethod, &requestMethod);
		} else {
			zephir_read_property_cached(&_22$$15, this_ptr, _zephir_prop_7, 290, PH_NOISY_CC | PH_READONLY);
			_23$$15 = !(zephir_array_isset_value(&_22$$15, &requestMethod));
			if (_23$$15) {
				zephir_read_property_cached(&_24$$15, this_ptr, _zephir_prop_9, 291, PH_NOISY_CC | PH_READONLY);
				zephir_memory_observe(&_25$$15);
				zephir_array_fetch_string(&_25$$15, &_24$$15, SL("*"), 0, "phalcon/Mvc/Router.zep", 1144);
				_23$$15 = zephir_array_isset_value(&_25$$15, &handledUri);
			}
			_26$$15 = _23$$15;
			if (_26$$15) {
				zephir_read_property_cached(&_27$$15, this_ptr, _zephir_prop_10, 292, PH_NOISY_CC | PH_READONLY);
				zephir_memory_observe(&_28$$15);
				zephir_array_fetch_string(&_28$$15, &_27$$15, SL("*"), 0, "phalcon/Mvc/Router.zep", 1145);
				_26$$15 = !(zephir_array_isset_value(&_28$$15, &handledUri));
			}
			if (_26$$15) {
				ZEPHIR_INIT_NVAR(&staticBucketMethod);
				ZVAL_STRING(&staticBucketMethod, "*");
			}
		}
		if (Z_TYPE_P(&staticBucketMethod) != IS_NULL) {
			zephir_read_property_cached(&_29$$18, this_ptr, _zephir_prop_9, 291, PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&_30$$18);
			zephir_array_fetch(&_30$$18, &_29$$18, &staticBucketMethod, PH_NOISY, "phalcon/Mvc/Router.zep", 1155);
			zephir_memory_observe(&staticBucket);
			zephir_array_fetch(&staticBucket, &_30$$18, &handledUri, PH_NOISY, "phalcon/Mvc/Router.zep", 1155);
			if (Z_TYPE_P(&staticBucket) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_32$$18);
				zephir_string_to_char_array(&_32$$18, &staticBucket);
				_31$$18 = &_32$$18;
			} else {
				_31$$18 = &staticBucket;
			}
			zephir_is_iterable(_31$$18, 0, "phalcon/Mvc/Router.zep", 1209);
			if (Z_TYPE_P(_31$$18) == IS_ARRAY) {
				ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(_31$$18), _33$$18)
				{
					ZEPHIR_INIT_NVAR(&staticRoute);
					ZVAL_COPY(&staticRoute, _33$$18);
					ZEPHIR_CALL_METHOD(&staticHostname, &staticRoute, "getHostName", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&staticHostname) != IS_NULL) {
						if (Z_TYPE_P(&currentHostName) == IS_NULL) {
							ZEPHIR_CALL_METHOD(&currentHostName, &request, "getHttpHost", &_34, 0);
							zephir_check_call_status();
						}
						if (!(zephir_is_true(&currentHostName))) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&staticHostRegex, &staticRoute, "getCompiledHostName", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&staticHostRegex) != IS_NULL) {
							ZEPHIR_INIT_NVAR(&_35$$23);
							ZEPHIR_INIT_NVAR(&staticMatched);
							zephir_preg_match(&staticMatched, &staticHostRegex, &currentHostName, &_35$$23, 0, 0 , 0 );
						} else {
							ZEPHIR_INIT_NVAR(&staticMatched);
							ZVAL_BOOL(&staticMatched, ZEPHIR_IS_EQUAL(&currentHostName, &staticHostname));
						}
						if (!(zephir_is_true(&staticMatched))) {
							continue;
						}
					}
					ZEPHIR_CALL_METHOD(&staticBeforeMatch, &staticRoute, "getBeforeMatch", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&staticBeforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&staticBeforeMatch)))) {
							ZEPHIR_INIT_NVAR(&_36$$27);
							object_init_ex(&_36$$27, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD(NULL, &_36$$27, "__construct", &_37, 271);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_36$$27, "phalcon/Mvc/Router.zep", 1186);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &staticBeforeMatch, NULL, 0, &handledUri, &staticRoute, this_ptr);
						zephir_check_call_status();
						if (!(zephir_is_true(&routeFound))) {
							ZEPHIR_CALL_METHOD(&_38$$28, &staticRoute, "getRouteId", NULL, 0);
							zephir_check_call_status();
							zephir_array_update_zval(&vetoedRoutes, &_38$$28, &__$true, PH_COPY | PH_SEPARATE);
							continue;
						}
					}
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, 1);
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					ZEPHIR_CALL_METHOD(&parts, &staticRoute, "getPaths", NULL, 0);
					zephir_check_call_status();
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 310, &staticRoute);
					break;
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _31$$18, "rewind", NULL, 0);
				zephir_check_call_status();
				_40$$18 = 1;
				while (1) {
					if (_40$$18) {
						_40$$18 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _31$$18, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_39$$18, _31$$18, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_39$$18)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&staticRoute, _31$$18, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&staticHostname, &staticRoute, "getHostName", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&staticHostname) != IS_NULL) {
							if (Z_TYPE_P(&currentHostName) == IS_NULL) {
								ZEPHIR_CALL_METHOD(&currentHostName, &request, "getHttpHost", &_41, 0);
								zephir_check_call_status();
							}
							if (!(zephir_is_true(&currentHostName))) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&staticHostRegex, &staticRoute, "getCompiledHostName", NULL, 0);
							zephir_check_call_status();
							if (Z_TYPE_P(&staticHostRegex) != IS_NULL) {
								ZEPHIR_INIT_NVAR(&_42$$33);
								ZEPHIR_INIT_NVAR(&staticMatched);
								zephir_preg_match(&staticMatched, &staticHostRegex, &currentHostName, &_42$$33, 0, 0 , 0 );
							} else {
								ZEPHIR_INIT_NVAR(&staticMatched);
								ZVAL_BOOL(&staticMatched, ZEPHIR_IS_EQUAL(&currentHostName, &staticHostname));
							}
							if (!(zephir_is_true(&staticMatched))) {
								continue;
							}
						}
						ZEPHIR_CALL_METHOD(&staticBeforeMatch, &staticRoute, "getBeforeMatch", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&staticBeforeMatch) != IS_NULL) {
							if (UNEXPECTED(!(zephir_is_callable(&staticBeforeMatch)))) {
								ZEPHIR_INIT_NVAR(&_43$$37);
								object_init_ex(&_43$$37, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
								ZEPHIR_CALL_METHOD(NULL, &_43$$37, "__construct", &_37, 271);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_43$$37, "phalcon/Mvc/Router.zep", 1186);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &staticBeforeMatch, NULL, 0, &handledUri, &staticRoute, this_ptr);
							zephir_check_call_status();
							if (!(zephir_is_true(&routeFound))) {
								ZEPHIR_CALL_METHOD(&_44$$38, &staticRoute, "getRouteId", NULL, 0);
								zephir_check_call_status();
								zephir_array_update_zval(&vetoedRoutes, &_44$$38, &__$true, PH_COPY | PH_SEPARATE);
								continue;
							}
						}
						ZEPHIR_INIT_NVAR(&routeFound);
						ZVAL_BOOL(&routeFound, 1);
						ZEPHIR_INIT_NVAR(&matches);
						ZVAL_NULL(&matches);
						ZEPHIR_CALL_METHOD(&parts, &staticRoute, "getPaths", NULL, 0);
						zephir_check_call_status();
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 310, &staticRoute);
						break;
				}
			}
			ZEPHIR_INIT_NVAR(&staticRoute);
		}
	}
	_45 = !zephir_is_true(&routeFound);
	if (_45) {
		_45 = Z_TYPE_P(&eventsManager) == IS_NULL;
	}
	_46 = _45;
	if (_46) {
		zephir_read_property_cached(&_47, this_ptr, _zephir_prop_11, 296, PH_NOISY_CC | PH_READONLY);
		_46 = !(zephir_array_isset_value(&_47, &candidateMethod));
	}
	_48 = _46;
	if (_48) {
		zephir_memory_observe(&combinedChunks);
		zephir_read_property_cached(&_49, this_ptr, _zephir_prop_12, 295, PH_NOISY_CC | PH_READONLY);
		_48 = zephir_array_isset_fetch(&combinedChunks, &_49, &candidateMethod, 0);
	}
	if (_48) {
		zephir_read_property_cached(&_50$$39, this_ptr, _zephir_prop_13, 297, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&combinedMarkMaps);
		zephir_array_fetch(&combinedMarkMaps, &_50$$39, &candidateMethod, PH_NOISY, "phalcon/Mvc/Router.zep", 1229);
		if (Z_TYPE_P(&combinedChunks) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_52$$39);
			zephir_string_to_char_array(&_52$$39, &combinedChunks);
			_51$$39 = &_52$$39;
		} else {
			_51$$39 = &combinedChunks;
		}
		zephir_is_iterable(_51$$39, 0, "phalcon/Mvc/Router.zep", 1307);
		if (Z_TYPE_P(_51$$39) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_51$$39), _54$$39, _55$$39, _53$$39)
			{
				ZEPHIR_INIT_NVAR(&combinedChunkIdx);
				if (_55$$39 != NULL) { 
					ZVAL_STR_COPY(&combinedChunkIdx, _55$$39);
				} else {
					ZVAL_LONG(&combinedChunkIdx, _54$$39);
				}
				ZEPHIR_INIT_NVAR(&combinedChunk);
				ZVAL_COPY(&combinedChunk, _53$$39);
				ZEPHIR_INIT_NVAR(&combinedMatchesLocal);
				array_init(&combinedMatchesLocal);
				ZEPHIR_INIT_NVAR(&_56$$40);
				zephir_preg_match(&_56$$40, &combinedChunk, &handledUri, &combinedMatchesLocal, 0, 0 , 0 );
				if (!(zephir_is_true(&_56$$40))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&combinedMarkLabel);
				zephir_array_fetch_string(&combinedMarkLabel, &combinedMatchesLocal, SL("MARK"), PH_NOISY, "phalcon/Mvc/Router.zep", 1238);
				zephir_array_unset_string(&combinedMatchesLocal, SL("MARK"), PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&combinedRouteIdx);
				ZEPHIR_OBS_NVAR(&_57$$40);
				zephir_array_fetch(&_57$$40, &combinedMarkMaps, &combinedChunkIdx, 0, "phalcon/Mvc/Router.zep", 1246);
				if (!(zephir_array_isset_fetch(&combinedRouteIdx, &_57$$40, &combinedMarkLabel, 0))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&combinedRoute);
				zephir_array_fetch(&combinedRoute, &candidateRoutes, &combinedRouteIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1250);
				zephir_read_property_cached(&_58$$40, this_ptr, _zephir_prop_14, 298, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&combinedRouteMeta);
				ZEPHIR_CALL_METHOD(&_59$$40, &combinedRoute, "getRouteId", NULL, 0);
				zephir_check_call_status();
				zephir_array_fetch(&combinedRouteMeta, &_58$$40, &_59$$40, PH_NOISY, "phalcon/Mvc/Router.zep", 1251);
				ZEPHIR_OBS_NVAR(&combinedBeforeMatch);
				zephir_array_fetch_string(&combinedBeforeMatch, &combinedRouteMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1253);
				if (Z_TYPE_P(&combinedBeforeMatch) != IS_NULL) {
					if (UNEXPECTED(!(zephir_is_callable(&combinedBeforeMatch)))) {
						ZEPHIR_INIT_NVAR(&_60$$44);
						object_init_ex(&_60$$44, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
						ZEPHIR_CALL_METHOD(NULL, &_60$$44, "__construct", &_37, 271);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_60$$44, "phalcon/Mvc/Router.zep", 1257);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_ZVAL_FUNCTION(&_61$$43, &combinedBeforeMatch, NULL, 0, &handledUri, &combinedRoute, this_ptr);
					zephir_check_call_status();
					if (!(zephir_is_true(&_61$$43))) {
						ZEPHIR_CALL_METHOD(&_62$$45, &combinedRoute, "getRouteId", NULL, 0);
						zephir_check_call_status();
						zephir_array_update_zval(&vetoedRoutes, &_62$$45, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
				}
				ZEPHIR_CALL_METHOD(&combinedPaths, &combinedRoute, "getPaths", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&parts, &combinedPaths);
				ZEPHIR_CPY_WRT(&matches, &combinedMatchesLocal);
				ZEPHIR_CALL_METHOD(&combinedConverters, &combinedRoute, "getConverters", NULL, 0);
				zephir_check_call_status();
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 308, &combinedMatchesLocal);
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 310, &combinedRoute);
				ZEPHIR_INIT_NVAR(&routeFound);
				ZVAL_BOOL(&routeFound, 1);
				if (Z_TYPE_P(&combinedPaths) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_64$$40);
					zephir_string_to_char_array(&_64$$40, &combinedPaths);
					_63$$40 = &_64$$40;
				} else {
					_63$$40 = &combinedPaths;
				}
				zephir_is_iterable(_63$$40, 0, "phalcon/Mvc/Router.zep", 1305);
				if (Z_TYPE_P(_63$$40) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_63$$40), _66$$40, _67$$40, _65$$40)
					{
						ZEPHIR_INIT_NVAR(&combinedPart);
						if (_67$$40 != NULL) { 
							ZVAL_STR_COPY(&combinedPart, _67$$40);
						} else {
							ZVAL_LONG(&combinedPart, _66$$40);
						}
						ZEPHIR_INIT_NVAR(&combinedPosition);
						ZVAL_COPY(&combinedPosition, _65$$40);
						if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
							ZEPHIR_INIT_NVAR(&_68$$47);
							object_init_ex(&_68$$47, phalcon_mvc_router_exceptions_wrongpathskey_ce);
							ZEPHIR_CALL_METHOD(NULL, &_68$$47, "__construct", &_69, 272, &combinedPart);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_68$$47, "phalcon/Mvc/Router.zep", 1282);
							ZEPHIR_MM_RESTORE();
							return;
						}
						_70$$46 = Z_TYPE_P(&combinedPosition) != IS_STRING;
						if (_70$$46) {
							_70$$46 = Z_TYPE_P(&combinedPosition) != IS_LONG;
						}
						if (_70$$46) {
							continue;
						}
						ZEPHIR_OBS_NVAR(&combinedMatchPosition);
						if (zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0)) {
							_71$$49 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
							if (_71$$49) {
								ZEPHIR_OBS_NVAR(&combinedConverter);
								_71$$49 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
							}
							if (_71$$49) {
								ZEPHIR_CALL_ZVAL_FUNCTION(&_72$$50, &combinedConverter, NULL, 0, &combinedMatchPosition);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, &combinedPart, &_72$$50, PH_COPY | PH_SEPARATE);
								continue;
							}
							zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
						} else {
							_73$$51 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
							if (_73$$51) {
								ZEPHIR_OBS_NVAR(&combinedConverter);
								_73$$51 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
							}
							if (_73$$51) {
								ZEPHIR_CALL_ZVAL_FUNCTION(&_74$$52, &combinedConverter, NULL, 0, &combinedPosition);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, &combinedPart, &_74$$52, PH_COPY | PH_SEPARATE);
							} else if (Z_TYPE_P(&combinedPosition) == IS_LONG) {
								zephir_array_unset(&parts, &combinedPart, PH_SEPARATE);
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _63$$40, "rewind", NULL, 0);
					zephir_check_call_status();
					_76$$40 = 1;
					while (1) {
						if (_76$$40) {
							_76$$40 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _63$$40, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_75$$40, _63$$40, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_75$$40)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&combinedPart, _63$$40, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&combinedPosition, _63$$40, "current", NULL, 0);
						zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
								ZEPHIR_INIT_NVAR(&_77$$55);
								object_init_ex(&_77$$55, phalcon_mvc_router_exceptions_wrongpathskey_ce);
								ZEPHIR_CALL_METHOD(NULL, &_77$$55, "__construct", &_69, 272, &combinedPart);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_77$$55, "phalcon/Mvc/Router.zep", 1282);
								ZEPHIR_MM_RESTORE();
								return;
							}
							_78$$54 = Z_TYPE_P(&combinedPosition) != IS_STRING;
							if (_78$$54) {
								_78$$54 = Z_TYPE_P(&combinedPosition) != IS_LONG;
							}
							if (_78$$54) {
								continue;
							}
							ZEPHIR_OBS_NVAR(&combinedMatchPosition);
							if (zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0)) {
								_79$$57 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_79$$57) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_79$$57 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								}
								if (_79$$57) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_80$$58, &combinedConverter, NULL, 0, &combinedMatchPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_80$$58, PH_COPY | PH_SEPARATE);
									continue;
								}
								zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
							} else {
								_81$$59 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_81$$59) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_81$$59 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								}
								if (_81$$59) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_82$$60, &combinedConverter, NULL, 0, &combinedPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_82$$60, PH_COPY | PH_SEPARATE);
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
			ZEPHIR_CALL_METHOD(NULL, _51$$39, "rewind", NULL, 0);
			zephir_check_call_status();
			_84$$39 = 1;
			while (1) {
				if (_84$$39) {
					_84$$39 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _51$$39, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_83$$39, _51$$39, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_83$$39)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&combinedChunkIdx, _51$$39, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&combinedChunk, _51$$39, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&combinedMatchesLocal);
					array_init(&combinedMatchesLocal);
					ZEPHIR_INIT_NVAR(&_85$$62);
					zephir_preg_match(&_85$$62, &combinedChunk, &handledUri, &combinedMatchesLocal, 0, 0 , 0 );
					if (!(zephir_is_true(&_85$$62))) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&combinedMarkLabel);
					zephir_array_fetch_string(&combinedMarkLabel, &combinedMatchesLocal, SL("MARK"), PH_NOISY, "phalcon/Mvc/Router.zep", 1238);
					zephir_array_unset_string(&combinedMatchesLocal, SL("MARK"), PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&combinedRouteIdx);
					ZEPHIR_OBS_NVAR(&_86$$62);
					zephir_array_fetch(&_86$$62, &combinedMarkMaps, &combinedChunkIdx, 0, "phalcon/Mvc/Router.zep", 1246);
					if (!(zephir_array_isset_fetch(&combinedRouteIdx, &_86$$62, &combinedMarkLabel, 0))) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&combinedRoute);
					zephir_array_fetch(&combinedRoute, &candidateRoutes, &combinedRouteIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1250);
					zephir_read_property_cached(&_87$$62, this_ptr, _zephir_prop_14, 298, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&combinedRouteMeta);
					ZEPHIR_CALL_METHOD(&_88$$62, &combinedRoute, "getRouteId", NULL, 0);
					zephir_check_call_status();
					zephir_array_fetch(&combinedRouteMeta, &_87$$62, &_88$$62, PH_NOISY, "phalcon/Mvc/Router.zep", 1251);
					ZEPHIR_OBS_NVAR(&combinedBeforeMatch);
					zephir_array_fetch_string(&combinedBeforeMatch, &combinedRouteMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1253);
					if (Z_TYPE_P(&combinedBeforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&combinedBeforeMatch)))) {
							ZEPHIR_INIT_NVAR(&_89$$66);
							object_init_ex(&_89$$66, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD(NULL, &_89$$66, "__construct", &_37, 271);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_89$$66, "phalcon/Mvc/Router.zep", 1257);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_ZVAL_FUNCTION(&_90$$65, &combinedBeforeMatch, NULL, 0, &handledUri, &combinedRoute, this_ptr);
						zephir_check_call_status();
						if (!(zephir_is_true(&_90$$65))) {
							ZEPHIR_CALL_METHOD(&_91$$67, &combinedRoute, "getRouteId", NULL, 0);
							zephir_check_call_status();
							zephir_array_update_zval(&vetoedRoutes, &_91$$67, &__$true, PH_COPY | PH_SEPARATE);
							break;
						}
					}
					ZEPHIR_CALL_METHOD(&combinedPaths, &combinedRoute, "getPaths", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&parts, &combinedPaths);
					ZEPHIR_CPY_WRT(&matches, &combinedMatchesLocal);
					ZEPHIR_CALL_METHOD(&combinedConverters, &combinedRoute, "getConverters", NULL, 0);
					zephir_check_call_status();
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 308, &combinedMatchesLocal);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 310, &combinedRoute);
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, 1);
					if (Z_TYPE_P(&combinedPaths) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_93$$62);
						zephir_string_to_char_array(&_93$$62, &combinedPaths);
						_92$$62 = &_93$$62;
					} else {
						_92$$62 = &combinedPaths;
					}
					zephir_is_iterable(_92$$62, 0, "phalcon/Mvc/Router.zep", 1305);
					if (Z_TYPE_P(_92$$62) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_92$$62), _95$$62, _96$$62, _94$$62)
						{
							ZEPHIR_INIT_NVAR(&combinedPart);
							if (_96$$62 != NULL) { 
								ZVAL_STR_COPY(&combinedPart, _96$$62);
							} else {
								ZVAL_LONG(&combinedPart, _95$$62);
							}
							ZEPHIR_INIT_NVAR(&combinedPosition);
							ZVAL_COPY(&combinedPosition, _94$$62);
							if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
								ZEPHIR_INIT_NVAR(&_97$$69);
								object_init_ex(&_97$$69, phalcon_mvc_router_exceptions_wrongpathskey_ce);
								ZEPHIR_CALL_METHOD(NULL, &_97$$69, "__construct", &_69, 272, &combinedPart);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_97$$69, "phalcon/Mvc/Router.zep", 1282);
								ZEPHIR_MM_RESTORE();
								return;
							}
							_98$$68 = Z_TYPE_P(&combinedPosition) != IS_STRING;
							if (_98$$68) {
								_98$$68 = Z_TYPE_P(&combinedPosition) != IS_LONG;
							}
							if (_98$$68) {
								continue;
							}
							ZEPHIR_OBS_NVAR(&combinedMatchPosition);
							if (zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0)) {
								_99$$71 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_99$$71) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_99$$71 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								}
								if (_99$$71) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_100$$72, &combinedConverter, NULL, 0, &combinedMatchPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_100$$72, PH_COPY | PH_SEPARATE);
									continue;
								}
								zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
							} else {
								_101$$73 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
								if (_101$$73) {
									ZEPHIR_OBS_NVAR(&combinedConverter);
									_101$$73 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
								}
								if (_101$$73) {
									ZEPHIR_CALL_ZVAL_FUNCTION(&_102$$74, &combinedConverter, NULL, 0, &combinedPosition);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &combinedPart, &_102$$74, PH_COPY | PH_SEPARATE);
								} else if (Z_TYPE_P(&combinedPosition) == IS_LONG) {
									zephir_array_unset(&parts, &combinedPart, PH_SEPARATE);
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _92$$62, "rewind", NULL, 0);
						zephir_check_call_status();
						_104$$62 = 1;
						while (1) {
							if (_104$$62) {
								_104$$62 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _92$$62, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_103$$62, _92$$62, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_103$$62)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&combinedPart, _92$$62, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&combinedPosition, _92$$62, "current", NULL, 0);
							zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&combinedPart) != IS_STRING)) {
									ZEPHIR_INIT_NVAR(&_105$$77);
									object_init_ex(&_105$$77, phalcon_mvc_router_exceptions_wrongpathskey_ce);
									ZEPHIR_CALL_METHOD(NULL, &_105$$77, "__construct", &_69, 272, &combinedPart);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_105$$77, "phalcon/Mvc/Router.zep", 1282);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_106$$76 = Z_TYPE_P(&combinedPosition) != IS_STRING;
								if (_106$$76) {
									_106$$76 = Z_TYPE_P(&combinedPosition) != IS_LONG;
								}
								if (_106$$76) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&combinedMatchPosition);
								if (zephir_array_isset_fetch(&combinedMatchPosition, &combinedMatchesLocal, &combinedPosition, 0)) {
									_107$$79 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
									if (_107$$79) {
										ZEPHIR_OBS_NVAR(&combinedConverter);
										_107$$79 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
									}
									if (_107$$79) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_108$$80, &combinedConverter, NULL, 0, &combinedMatchPosition);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &combinedPart, &_108$$80, PH_COPY | PH_SEPARATE);
										continue;
									}
									zephir_array_update_zval(&parts, &combinedPart, &combinedMatchPosition, PH_COPY | PH_SEPARATE);
								} else {
									_109$$81 = Z_TYPE_P(&combinedConverters) == IS_ARRAY;
									if (_109$$81) {
										ZEPHIR_OBS_NVAR(&combinedConverter);
										_109$$81 = zephir_array_isset_fetch(&combinedConverter, &combinedConverters, &combinedPart, 0);
									}
									if (_109$$81) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_110$$82, &combinedConverter, NULL, 0, &combinedPosition);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &combinedPart, &_110$$82, PH_COPY | PH_SEPARATE);
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
		ZEPHIR_CALL_FUNCTION(&_111$$84, "array_reverse", NULL, 273, &candidateRoutes, &__$true);
		zephir_check_call_status();
		if (Z_TYPE_P(&_111$$84) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_113$$84);
			zephir_string_to_char_array(&_113$$84, &_111$$84);
			_112$$84 = &_113$$84;
		} else {
			_112$$84 = &_111$$84;
		}
		zephir_is_iterable(_112$$84, 0, "phalcon/Mvc/Router.zep", 1477);
		if (Z_TYPE_P(_112$$84) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_112$$84), _115$$84, _116$$84, _114$$84)
			{
				ZEPHIR_INIT_NVAR(&routeIdx);
				if (_116$$84 != NULL) { 
					ZVAL_STR_COPY(&routeIdx, _116$$84);
				} else {
					ZVAL_LONG(&routeIdx, _115$$84);
				}
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _114$$84);
				ZEPHIR_CALL_METHOD(&routeId, &route, "getRouteId", NULL, 0);
				zephir_check_call_status();
				if (zephir_array_isset_value(&vetoedRoutes, &routeId)) {
					continue;
				}
				zephir_read_property_cached(&_117$$85, this_ptr, _zephir_prop_14, 298, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&_118$$85);
				zephir_array_fetch(&_118$$85, &_117$$85, &routeId, PH_NOISY, "phalcon/Mvc/Router.zep", 1325);
				ZEPHIR_CPY_WRT(&routeMeta, &_118$$85);
				ZEPHIR_INIT_NVAR(&params);
				array_init(&params);
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				ZEPHIR_OBS_NVAR(&hostname);
				zephir_array_fetch_string(&hostname, &routeMeta, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1332);
				if (Z_TYPE_P(&hostname) != IS_NULL) {
					if (Z_TYPE_P(&currentHostName) == IS_NULL) {
						ZEPHIR_CALL_METHOD(&currentHostName, &request, "getHttpHost", &_119, 0);
						zephir_check_call_status();
					}
					if (!(zephir_is_true(&currentHostName))) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&regexHostName);
					zephir_array_fetch_string(&regexHostName, &routeMeta, SL("hostRegex"), PH_NOISY, "phalcon/Mvc/Router.zep", 1352);
					if (Z_TYPE_P(&regexHostName) != IS_NULL) {
						ZEPHIR_INIT_NVAR(&_120$$90);
						ZEPHIR_INIT_NVAR(&matched);
						zephir_preg_match(&matched, &regexHostName, &currentHostName, &_120$$90, 0, 0 , 0 );
					} else {
						ZEPHIR_INIT_NVAR(&matched);
						ZVAL_BOOL(&matched, ZEPHIR_IS_EQUAL(&currentHostName, &hostname));
					}
					if (!(zephir_is_true(&matched))) {
						continue;
					}
				}
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_121$$93);
					ZVAL_STRING(&_121$$93, "router:beforeCheckRoute");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_122, 0, &_121$$93, this_ptr, &route);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&pattern);
				zephir_array_fetch_string(&pattern, &routeMeta, SL("pattern"), PH_NOISY, "phalcon/Mvc/Router.zep", 1372);
				ZEPHIR_OBS_NVAR(&_118$$85);
				zephir_array_fetch_string(&_118$$85, &routeMeta, SL("isRegex"), PH_NOISY, "phalcon/Mvc/Router.zep", 1374);
				if (zephir_is_true(&_118$$85)) {
					ZEPHIR_INIT_NVAR(&routeFound);
					zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
				} else {
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, &handledUri));
				}
				if (zephir_is_true(&routeFound)) {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_123$$97);
						ZVAL_STRING(&_123$$97, "router:matchedRoute");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_124, 0, &_123$$97, this_ptr, &route);
						zephir_check_call_status();
					}
					ZEPHIR_OBS_NVAR(&beforeMatch);
					zephir_array_fetch_string(&beforeMatch, &routeMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1388);
					if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
							ZEPHIR_INIT_NVAR(&_125$$99);
							object_init_ex(&_125$$99, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD(NULL, &_125$$99, "__construct", &_37, 271);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_125$$99, "phalcon/Mvc/Router.zep", 1394);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &beforeMatch, NULL, 0, &handledUri, &route, this_ptr);
						zephir_check_call_status();
					}
				} else {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_126$$101);
						ZVAL_STRING(&_126$$101, "router:notMatchedRoute");
						ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_127, 0, &_126$$101, this_ptr, &route);
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
							ZEPHIR_INIT_NVAR(&_129$$103);
							zephir_string_to_char_array(&_129$$103, &paths);
							_128$$103 = &_129$$103;
						} else {
							_128$$103 = &paths;
						}
						zephir_is_iterable(_128$$103, 0, "phalcon/Mvc/Router.zep", 1469);
						if (Z_TYPE_P(_128$$103) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_128$$103), _131$$103, _132$$103, _130$$103)
							{
								ZEPHIR_INIT_NVAR(&part);
								if (_132$$103 != NULL) { 
									ZVAL_STR_COPY(&part, _132$$103);
								} else {
									ZVAL_LONG(&part, _131$$103);
								}
								ZEPHIR_INIT_NVAR(&position);
								ZVAL_COPY(&position, _130$$103);
								if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
									ZEPHIR_INIT_NVAR(&_133$$105);
									object_init_ex(&_133$$105, phalcon_mvc_router_exceptions_wrongpathskey_ce);
									ZEPHIR_CALL_METHOD(NULL, &_133$$105, "__construct", &_69, 272, &part);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_133$$105, "phalcon/Mvc/Router.zep", 1427);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_134$$104 = Z_TYPE_P(&position) != IS_STRING;
								if (_134$$104) {
									_134$$104 = Z_TYPE_P(&position) != IS_LONG;
								}
								if (_134$$104) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&matchPosition);
								if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_135$$109, &converter, NULL, 0, &matchPosition);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_135$$109, PH_COPY | PH_SEPARATE);
											continue;
										}
									}
									zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
								} else {
									_136$$110 = Z_TYPE_P(&converters) == IS_ARRAY;
									if (_136$$110) {
										ZEPHIR_OBS_NVAR(&converter);
										_136$$110 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
									}
									if (_136$$110) {
										ZEPHIR_CALL_ZVAL_FUNCTION(&_137$$111, &converter, NULL, 0, &position);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_137$$111, PH_COPY | PH_SEPARATE);
									} else if (Z_TYPE_P(&position) == IS_LONG) {
										zephir_array_unset(&parts, &part, PH_SEPARATE);
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _128$$103, "rewind", NULL, 0);
							zephir_check_call_status();
							_139$$103 = 1;
							while (1) {
								if (_139$$103) {
									_139$$103 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _128$$103, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_138$$103, _128$$103, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_138$$103)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&part, _128$$103, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&position, _128$$103, "current", NULL, 0);
								zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
										ZEPHIR_INIT_NVAR(&_140$$114);
										object_init_ex(&_140$$114, phalcon_mvc_router_exceptions_wrongpathskey_ce);
										ZEPHIR_CALL_METHOD(NULL, &_140$$114, "__construct", &_69, 272, &part);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_140$$114, "phalcon/Mvc/Router.zep", 1427);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_141$$113 = Z_TYPE_P(&position) != IS_STRING;
									if (_141$$113) {
										_141$$113 = Z_TYPE_P(&position) != IS_LONG;
									}
									if (_141$$113) {
										continue;
									}
									ZEPHIR_OBS_NVAR(&matchPosition);
									if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_142$$118, &converter, NULL, 0, &matchPosition);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_142$$118, PH_COPY | PH_SEPARATE);
												continue;
											}
										}
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
									} else {
										_143$$119 = Z_TYPE_P(&converters) == IS_ARRAY;
										if (_143$$119) {
											ZEPHIR_OBS_NVAR(&converter);
											_143$$119 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										}
										if (_143$$119) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_144$$120, &converter, NULL, 0, &position);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_144$$120, PH_COPY | PH_SEPARATE);
										} else if (Z_TYPE_P(&position) == IS_LONG) {
											zephir_array_unset(&parts, &part, PH_SEPARATE);
										}
									}
							}
						}
						ZEPHIR_INIT_NVAR(&position);
						ZEPHIR_INIT_NVAR(&part);
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 308, &matches);
					}
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 310, &route);
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _112$$84, "rewind", NULL, 0);
			zephir_check_call_status();
			_146$$84 = 1;
			while (1) {
				if (_146$$84) {
					_146$$84 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _112$$84, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_145$$84, _112$$84, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_145$$84)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&routeIdx, _112$$84, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&route, _112$$84, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&routeId, &route, "getRouteId", NULL, 0);
					zephir_check_call_status();
					if (zephir_array_isset_value(&vetoedRoutes, &routeId)) {
						continue;
					}
					zephir_read_property_cached(&_147$$122, this_ptr, _zephir_prop_14, 298, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_148$$122);
					zephir_array_fetch(&_148$$122, &_147$$122, &routeId, PH_NOISY, "phalcon/Mvc/Router.zep", 1325);
					ZEPHIR_CPY_WRT(&routeMeta, &_148$$122);
					ZEPHIR_INIT_NVAR(&params);
					array_init(&params);
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					ZEPHIR_OBS_NVAR(&hostname);
					zephir_array_fetch_string(&hostname, &routeMeta, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1332);
					if (Z_TYPE_P(&hostname) != IS_NULL) {
						if (Z_TYPE_P(&currentHostName) == IS_NULL) {
							ZEPHIR_CALL_METHOD(&currentHostName, &request, "getHttpHost", &_149, 0);
							zephir_check_call_status();
						}
						if (!(zephir_is_true(&currentHostName))) {
							continue;
						}
						ZEPHIR_OBS_NVAR(&regexHostName);
						zephir_array_fetch_string(&regexHostName, &routeMeta, SL("hostRegex"), PH_NOISY, "phalcon/Mvc/Router.zep", 1352);
						if (Z_TYPE_P(&regexHostName) != IS_NULL) {
							ZEPHIR_INIT_NVAR(&_150$$127);
							ZEPHIR_INIT_NVAR(&matched);
							zephir_preg_match(&matched, &regexHostName, &currentHostName, &_150$$127, 0, 0 , 0 );
						} else {
							ZEPHIR_INIT_NVAR(&matched);
							ZVAL_BOOL(&matched, ZEPHIR_IS_EQUAL(&currentHostName, &hostname));
						}
						if (!(zephir_is_true(&matched))) {
							continue;
						}
					}
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_151$$130);
						ZVAL_STRING(&_151$$130, "router:beforeCheckRoute");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_152, 0, &_151$$130, this_ptr, &route);
						zephir_check_call_status();
					}
					ZEPHIR_OBS_NVAR(&pattern);
					zephir_array_fetch_string(&pattern, &routeMeta, SL("pattern"), PH_NOISY, "phalcon/Mvc/Router.zep", 1372);
					ZEPHIR_OBS_NVAR(&_148$$122);
					zephir_array_fetch_string(&_148$$122, &routeMeta, SL("isRegex"), PH_NOISY, "phalcon/Mvc/Router.zep", 1374);
					if (zephir_is_true(&_148$$122)) {
						ZEPHIR_INIT_NVAR(&routeFound);
						zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
					} else {
						ZEPHIR_INIT_NVAR(&routeFound);
						ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, &handledUri));
					}
					if (zephir_is_true(&routeFound)) {
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_153$$134);
							ZVAL_STRING(&_153$$134, "router:matchedRoute");
							ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_154, 0, &_153$$134, this_ptr, &route);
							zephir_check_call_status();
						}
						ZEPHIR_OBS_NVAR(&beforeMatch);
						zephir_array_fetch_string(&beforeMatch, &routeMeta, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1388);
						if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
							if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
								ZEPHIR_INIT_NVAR(&_155$$136);
								object_init_ex(&_155$$136, phalcon_mvc_router_exceptions_beforematchnotcallable_ce);
								ZEPHIR_CALL_METHOD(NULL, &_155$$136, "__construct", &_37, 271);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_155$$136, "phalcon/Mvc/Router.zep", 1394);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_ZVAL_FUNCTION(&routeFound, &beforeMatch, NULL, 0, &handledUri, &route, this_ptr);
							zephir_check_call_status();
						}
					} else {
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_156$$138);
							ZVAL_STRING(&_156$$138, "router:notMatchedRoute");
							ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_157, 0, &_156$$138, this_ptr, &route);
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
								ZEPHIR_INIT_NVAR(&_159$$140);
								zephir_string_to_char_array(&_159$$140, &paths);
								_158$$140 = &_159$$140;
							} else {
								_158$$140 = &paths;
							}
							zephir_is_iterable(_158$$140, 0, "phalcon/Mvc/Router.zep", 1469);
							if (Z_TYPE_P(_158$$140) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_158$$140), _161$$140, _162$$140, _160$$140)
								{
									ZEPHIR_INIT_NVAR(&part);
									if (_162$$140 != NULL) { 
										ZVAL_STR_COPY(&part, _162$$140);
									} else {
										ZVAL_LONG(&part, _161$$140);
									}
									ZEPHIR_INIT_NVAR(&position);
									ZVAL_COPY(&position, _160$$140);
									if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
										ZEPHIR_INIT_NVAR(&_163$$142);
										object_init_ex(&_163$$142, phalcon_mvc_router_exceptions_wrongpathskey_ce);
										ZEPHIR_CALL_METHOD(NULL, &_163$$142, "__construct", &_69, 272, &part);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_163$$142, "phalcon/Mvc/Router.zep", 1427);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_164$$141 = Z_TYPE_P(&position) != IS_STRING;
									if (_164$$141) {
										_164$$141 = Z_TYPE_P(&position) != IS_LONG;
									}
									if (_164$$141) {
										continue;
									}
									ZEPHIR_OBS_NVAR(&matchPosition);
									if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_165$$146, &converter, NULL, 0, &matchPosition);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_165$$146, PH_COPY | PH_SEPARATE);
												continue;
											}
										}
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
									} else {
										_166$$147 = Z_TYPE_P(&converters) == IS_ARRAY;
										if (_166$$147) {
											ZEPHIR_OBS_NVAR(&converter);
											_166$$147 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										}
										if (_166$$147) {
											ZEPHIR_CALL_ZVAL_FUNCTION(&_167$$148, &converter, NULL, 0, &position);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_167$$148, PH_COPY | PH_SEPARATE);
										} else if (Z_TYPE_P(&position) == IS_LONG) {
											zephir_array_unset(&parts, &part, PH_SEPARATE);
										}
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _158$$140, "rewind", NULL, 0);
								zephir_check_call_status();
								_169$$140 = 1;
								while (1) {
									if (_169$$140) {
										_169$$140 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _158$$140, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_168$$140, _158$$140, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_168$$140)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&part, _158$$140, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&position, _158$$140, "current", NULL, 0);
									zephir_check_call_status();
										if (UNEXPECTED(Z_TYPE_P(&part) != IS_STRING)) {
											ZEPHIR_INIT_NVAR(&_170$$151);
											object_init_ex(&_170$$151, phalcon_mvc_router_exceptions_wrongpathskey_ce);
											ZEPHIR_CALL_METHOD(NULL, &_170$$151, "__construct", &_69, 272, &part);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_170$$151, "phalcon/Mvc/Router.zep", 1427);
											ZEPHIR_MM_RESTORE();
											return;
										}
										_171$$150 = Z_TYPE_P(&position) != IS_STRING;
										if (_171$$150) {
											_171$$150 = Z_TYPE_P(&position) != IS_LONG;
										}
										if (_171$$150) {
											continue;
										}
										ZEPHIR_OBS_NVAR(&matchPosition);
										if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
											if (Z_TYPE_P(&converters) == IS_ARRAY) {
												ZEPHIR_OBS_NVAR(&converter);
												if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
													ZEPHIR_CALL_ZVAL_FUNCTION(&_172$$155, &converter, NULL, 0, &matchPosition);
													zephir_check_call_status();
													zephir_array_update_zval(&parts, &part, &_172$$155, PH_COPY | PH_SEPARATE);
													continue;
												}
											}
											zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
										} else {
											_173$$156 = Z_TYPE_P(&converters) == IS_ARRAY;
											if (_173$$156) {
												ZEPHIR_OBS_NVAR(&converter);
												_173$$156 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
											}
											if (_173$$156) {
												ZEPHIR_CALL_ZVAL_FUNCTION(&_174$$157, &converter, NULL, 0, &position);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_174$$157, PH_COPY | PH_SEPARATE);
											} else if (Z_TYPE_P(&position) == IS_LONG) {
												zephir_array_unset(&parts, &part, PH_SEPARATE);
											}
										}
								}
							}
							ZEPHIR_INIT_NVAR(&position);
							ZEPHIR_INIT_NVAR(&part);
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 308, &matches);
						}
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 310, &route);
						break;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&route);
		ZEPHIR_INIT_NVAR(&routeIdx);
	}
	if (zephir_is_true(&routeFound)) {
		if (1) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 309, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 309, &__$false);
		}
	} else {
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 309, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 309, &__$false);
		}
	}
	if (!(zephir_is_true(&routeFound))) {
		zephir_read_property_cached(&_175$$161, this_ptr, _zephir_prop_15, 313, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&notFoundPaths, &_175$$161);
		if (Z_TYPE_P(&notFoundPaths) != IS_NULL) {
			ZEPHIR_CALL_CE_STATIC(&parts, phalcon_mvc_router_route_ce, "getRoutePaths", NULL, 0, &notFoundPaths);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&routeFound);
			ZVAL_BOOL(&routeFound, 1);
		}
	}
	zephir_read_property_cached(&_176, this_ptr, _zephir_prop_16, 299, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_17, 314, &_176);
	zephir_read_property_cached(&_177, this_ptr, _zephir_prop_18, 300, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_19, 315, &_177);
	zephir_read_property_cached(&_178, this_ptr, _zephir_prop_20, 301, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_21, 316, &_178);
	zephir_read_property_cached(&_179, this_ptr, _zephir_prop_22, 302, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_23, 317, &_179);
	zephir_read_property_cached(&_180, this_ptr, _zephir_prop_24, 303, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_25, 318, &_180);
	if (zephir_is_true(&routeFound)) {
		zephir_memory_observe(&vnamespace);
		if (zephir_array_isset_string_fetch(&vnamespace, &parts, SL("namespace"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_17, 314, &vnamespace);
			zephir_array_unset_string(&parts, SL("namespace"), PH_SEPARATE);
		}
		zephir_memory_observe(&module);
		if (zephir_array_isset_string_fetch(&module, &parts, SL("module"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_19, 315, &module);
			zephir_array_unset_string(&parts, SL("module"), PH_SEPARATE);
		}
		zephir_memory_observe(&controller);
		if (zephir_array_isset_string_fetch(&controller, &parts, SL("controller"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_21, 316, &controller);
			zephir_array_unset_string(&parts, SL("controller"), PH_SEPARATE);
		}
		zephir_memory_observe(&action);
		if (zephir_array_isset_string_fetch(&action, &parts, SL("action"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_23, 317, &action);
			zephir_array_unset_string(&parts, SL("action"), PH_SEPARATE);
		}
		zephir_memory_observe(&paramsStr);
		if (zephir_array_isset_string_fetch(&paramsStr, &parts, SL("params"), 0)) {
			if (Z_TYPE_P(&paramsStr) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_181$$169);
				ZVAL_STRING(&_181$$169, "/");
				ZEPHIR_INIT_VAR(&strParams);
				zephir_fast_trim(&strParams, &paramsStr, &_181$$169, ZEPHIR_TRIM_BOTH);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&strParams, "")) {
					ZEPHIR_INIT_NVAR(&params);
					zephir_fast_explode_str(&params, SL("/"), &strParams, ZEND_LONG_MAX);
				}
			}
			zephir_array_unset_string(&parts, SL("params"), PH_SEPARATE);
		}
		if (!(ZEPHIR_IS_EMPTY(&params))) {
			ZEPHIR_INIT_VAR(&_182$$171);
			zephir_fast_array_merge(&_182$$171, &params, &parts);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_25, 318, &_182$$171);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_25, 318, &parts);
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_183$$173);
		ZVAL_STRING(&_183$$173, "router:afterCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_183$$173, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_184, this_ptr, _zephir_prop_26, 319, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_184) != IS_NULL) {
		zephir_read_property_cached(&_185$$174, this_ptr, _zephir_prop_26, 319, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_186$$174, this_ptr, _zephir_prop_27, 320, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_187$$174, this_ptr, "buildDispatcherDump", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_185$$174, "set", NULL, 0, &_186$$174, &_187$$174);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_26, 319, &__$null);
		ZEPHIR_INIT_VAR(&_188$$174);
		ZEPHIR_INIT_NVAR(&_188$$174);
		ZVAL_STRING(&_188$$174, "");
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_27, 320, &_188$$174);
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
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 9, &_2$$3);
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
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 9, &_6$$4);
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
	zend_class_entry *_9$$6, *_30$$13;
	zval _3$$4;
	zend_string *_53, *_79, *_105, *_22$$10, *_43$$17, *_111$$32, *_139$$39;
	zend_ulong _52, _78, _104, _21$$10, _42$$17, _110$$32, _138$$39;
	zend_bool _28, _64, _90, _133, _25$$10, _46$$17, _60$$20, _71$$23, _86$$26, _97$$29, _122$$32, _118$$33, _129$$36, _150$$39, _146$$40, _157$$43;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_23 = NULL, *_26 = NULL, *_44 = NULL, *_47 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, dumpVersion = 0;
	zval *dump_param = NULL, __$true, __$false, routeData, route, routeClass, beforeMatch, converters, convName, converter, rebuiltRoutes, methodRoutesRehydrated, candidatesRehydrated, staticRehydrated, innerKey, innerVal, scalarIdx, scalarSubKey, mostInnerVal, mostInnerArr, _0, _4, *_5, _6, *_7, _27, _48, *_49, _50, *_51, _63, _74, *_75, _76, *_77, _89, _100, *_101, _102, *_103, _132, _160, _161, _162, _163, _164, _165, _166, _167, _168, _1$$4, _2$$4, _8$$6, _10$$6, _11$$6, _12$$6, _13$$6, _15$$6, _17$$6, _14$$7, _16$$8, *_18$$10, _19$$10, *_20$$10, _24$$10, _29$$13, _31$$13, _32$$13, _33$$13, _34$$13, _36$$13, _38$$13, _35$$14, _37$$15, *_39$$17, _40$$17, *_41$$17, _45$$17, *_54$$20, _55$$20, *_56$$20, _59$$20, _57$$21, _58$$21, _61$$22, _62$$22, *_65$$23, _66$$23, *_67$$23, _70$$23, _68$$24, _69$$24, _72$$25, _73$$25, *_80$$26, _81$$26, *_82$$26, _85$$26, _83$$27, _84$$27, _87$$28, _88$$28, *_91$$29, _92$$29, *_93$$29, _96$$29, _94$$30, _95$$30, _98$$31, _99$$31, _106$$32, *_107$$32, _108$$32, *_109$$32, _121$$32, *_112$$33, _113$$33, *_114$$33, _117$$33, _115$$34, _116$$34, _119$$35, _120$$35, *_123$$36, _124$$36, *_125$$36, _128$$36, _126$$37, _127$$37, _130$$38, _131$$38, _134$$39, *_135$$39, _136$$39, *_137$$39, _149$$39, *_140$$40, _141$$40, *_142$$40, _145$$40, _143$$41, _144$$41, _147$$42, _148$$42, *_151$$43, _152$$43, *_153$$43, _156$$43, _154$$44, _155$$44, _158$$45, _159$$45;
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_50);
	ZVAL_UNDEF(&_63);
	ZVAL_UNDEF(&_74);
	ZVAL_UNDEF(&_76);
	ZVAL_UNDEF(&_89);
	ZVAL_UNDEF(&_100);
	ZVAL_UNDEF(&_102);
	ZVAL_UNDEF(&_132);
	ZVAL_UNDEF(&_160);
	ZVAL_UNDEF(&_161);
	ZVAL_UNDEF(&_162);
	ZVAL_UNDEF(&_163);
	ZVAL_UNDEF(&_164);
	ZVAL_UNDEF(&_165);
	ZVAL_UNDEF(&_166);
	ZVAL_UNDEF(&_167);
	ZVAL_UNDEF(&_168);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_24$$10);
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
	ZVAL_UNDEF(&_45$$17);
	ZVAL_UNDEF(&_55$$20);
	ZVAL_UNDEF(&_59$$20);
	ZVAL_UNDEF(&_57$$21);
	ZVAL_UNDEF(&_58$$21);
	ZVAL_UNDEF(&_61$$22);
	ZVAL_UNDEF(&_62$$22);
	ZVAL_UNDEF(&_66$$23);
	ZVAL_UNDEF(&_70$$23);
	ZVAL_UNDEF(&_68$$24);
	ZVAL_UNDEF(&_69$$24);
	ZVAL_UNDEF(&_72$$25);
	ZVAL_UNDEF(&_73$$25);
	ZVAL_UNDEF(&_81$$26);
	ZVAL_UNDEF(&_85$$26);
	ZVAL_UNDEF(&_83$$27);
	ZVAL_UNDEF(&_84$$27);
	ZVAL_UNDEF(&_87$$28);
	ZVAL_UNDEF(&_88$$28);
	ZVAL_UNDEF(&_92$$29);
	ZVAL_UNDEF(&_96$$29);
	ZVAL_UNDEF(&_94$$30);
	ZVAL_UNDEF(&_95$$30);
	ZVAL_UNDEF(&_98$$31);
	ZVAL_UNDEF(&_99$$31);
	ZVAL_UNDEF(&_106$$32);
	ZVAL_UNDEF(&_108$$32);
	ZVAL_UNDEF(&_121$$32);
	ZVAL_UNDEF(&_113$$33);
	ZVAL_UNDEF(&_117$$33);
	ZVAL_UNDEF(&_115$$34);
	ZVAL_UNDEF(&_116$$34);
	ZVAL_UNDEF(&_119$$35);
	ZVAL_UNDEF(&_120$$35);
	ZVAL_UNDEF(&_124$$36);
	ZVAL_UNDEF(&_128$$36);
	ZVAL_UNDEF(&_126$$37);
	ZVAL_UNDEF(&_127$$37);
	ZVAL_UNDEF(&_130$$38);
	ZVAL_UNDEF(&_131$$38);
	ZVAL_UNDEF(&_134$$39);
	ZVAL_UNDEF(&_136$$39);
	ZVAL_UNDEF(&_149$$39);
	ZVAL_UNDEF(&_141$$40);
	ZVAL_UNDEF(&_145$$40);
	ZVAL_UNDEF(&_143$$41);
	ZVAL_UNDEF(&_144$$41);
	ZVAL_UNDEF(&_147$$42);
	ZVAL_UNDEF(&_148$$42);
	ZVAL_UNDEF(&_152$$43);
	ZVAL_UNDEF(&_156$$43);
	ZVAL_UNDEF(&_154$$44);
	ZVAL_UNDEF(&_155$$44);
	ZVAL_UNDEF(&_158$$45);
	ZVAL_UNDEF(&_159$$45);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Router cache is missing 'version' field", "phalcon/Mvc/Router.zep", 1630);
		return;
	}
	zephir_memory_observe(&_0);
	zephir_array_fetch_string(&_0, &dump, SL("version"), PH_NOISY, "phalcon/Mvc/Router.zep", 1633);
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
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Router.zep", 1638);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_array_isset_value_string(&dump, SL("routes")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Router cache is missing 'routes' field", "phalcon/Mvc/Router.zep", 1642);
		return;
	}
	ZEPHIR_INIT_VAR(&rebuiltRoutes);
	array_init(&rebuiltRoutes);
	zephir_array_fetch_string(&_4, &dump, SL("routes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1647);
	if (Z_TYPE_P(&_4) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_6);
		zephir_string_to_char_array(&_6, &_4);
		_5 = &_6;
	} else {
		_5 = &_4;
	}
	zephir_is_iterable(_5, 0, "phalcon/Mvc/Router.zep", 1676);
	if (Z_TYPE_P(_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_5), _7)
		{
			ZEPHIR_INIT_NVAR(&routeData);
			ZVAL_COPY(&routeData, _7);
			ZEPHIR_OBS_NVAR(&routeClass);
			zephir_array_fetch_string(&routeClass, &routeData, SL("class"), PH_NOISY, "phalcon/Mvc/Router.zep", 1648);
			ZEPHIR_INIT_NVAR(&route);
			zephir_fetch_safe_class(&_8$$6, &routeClass);
			_9$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_8$$6), Z_STRLEN_P(&_8$$6), ZEND_FETCH_CLASS_AUTO);
			if(!_9$$6) {
				RETURN_MM_NULL();
			}
			object_init_ex(&route, _9$$6);
			ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&route);
			zephir_check_call_status();
			if (zephir_has_constructor(&route)) {
				ZEPHIR_OBS_NVAR(&_10$$6);
				zephir_array_fetch_string(&_10$$6, &routeData, SL("pattern"), PH_NOISY, "phalcon/Mvc/Router.zep", 1649);
				ZEPHIR_OBS_NVAR(&_11$$6);
				zephir_array_fetch_string(&_11$$6, &routeData, SL("paths"), PH_NOISY, "phalcon/Mvc/Router.zep", 1649);
				ZEPHIR_OBS_NVAR(&_12$$6);
				zephir_array_fetch_string(&_12$$6, &routeData, SL("methods"), PH_NOISY, "phalcon/Mvc/Router.zep", 1649);
				ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 0, &_10$$6, &_11$$6, &_12$$6);
				zephir_check_call_status();
			}

			ZEPHIR_OBS_NVAR(&_13$$6);
			zephir_array_fetch_string(&_13$$6, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1651);
			if (Z_TYPE_P(&_13$$6) != IS_NULL) {
				ZEPHIR_OBS_NVAR(&_14$$7);
				zephir_array_fetch_string(&_14$$7, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1652);
				ZEPHIR_CALL_METHOD(NULL, &route, "setHostname", NULL, 0, &_14$$7);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&_15$$6);
			zephir_array_fetch_string(&_15$$6, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 1655);
			if (Z_TYPE_P(&_15$$6) != IS_NULL) {
				ZEPHIR_OBS_NVAR(&_16$$8);
				zephir_array_fetch_string(&_16$$8, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 1656);
				ZEPHIR_CALL_METHOD(NULL, &route, "setName", NULL, 0, &_16$$8);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&_17$$6);
			zephir_array_fetch_string(&_17$$6, &routeData, SL("id"), PH_NOISY, "phalcon/Mvc/Router.zep", 1659);
			ZEPHIR_CALL_METHOD(NULL, &route, "setRouteId", NULL, 0, &_17$$6);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&beforeMatch);
			zephir_array_fetch_string(&beforeMatch, &routeData, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1661);
			if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &route, "beforeMatch", NULL, 0, &beforeMatch);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&converters);
			zephir_array_fetch_string(&converters, &routeData, SL("converters"), PH_NOISY, "phalcon/Mvc/Router.zep", 1666);
			if (Z_TYPE_P(&converters) == IS_ARRAY) {
				if (Z_TYPE_P(&converters) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_19$$10);
					zephir_string_to_char_array(&_19$$10, &converters);
					_18$$10 = &_19$$10;
				} else {
					_18$$10 = &converters;
				}
				zephir_is_iterable(_18$$10, 0, "phalcon/Mvc/Router.zep", 1671);
				if (Z_TYPE_P(_18$$10) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_18$$10), _21$$10, _22$$10, _20$$10)
					{
						ZEPHIR_INIT_NVAR(&convName);
						if (_22$$10 != NULL) { 
							ZVAL_STR_COPY(&convName, _22$$10);
						} else {
							ZVAL_LONG(&convName, _21$$10);
						}
						ZEPHIR_INIT_NVAR(&converter);
						ZVAL_COPY(&converter, _20$$10);
						ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_23, 0, &convName, &converter);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _18$$10, "rewind", NULL, 0);
					zephir_check_call_status();
					_25$$10 = 1;
					while (1) {
						if (_25$$10) {
							_25$$10 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _18$$10, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_24$$10, _18$$10, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_24$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&convName, _18$$10, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&converter, _18$$10, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_26, 0, &convName, &converter);
							zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&converter);
				ZEPHIR_INIT_NVAR(&convName);
			}
			zephir_array_append(&rebuiltRoutes, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1673);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _5, "rewind", NULL, 0);
		zephir_check_call_status();
		_28 = 1;
		while (1) {
			if (_28) {
				_28 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _5, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_27, _5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_27)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&routeData, _5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&routeClass);
				zephir_array_fetch_string(&routeClass, &routeData, SL("class"), PH_NOISY, "phalcon/Mvc/Router.zep", 1648);
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
					ZEPHIR_OBS_NVAR(&_32$$13);
					zephir_array_fetch_string(&_32$$13, &routeData, SL("paths"), PH_NOISY, "phalcon/Mvc/Router.zep", 1649);
					ZEPHIR_OBS_NVAR(&_33$$13);
					zephir_array_fetch_string(&_33$$13, &routeData, SL("methods"), PH_NOISY, "phalcon/Mvc/Router.zep", 1649);
					ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 0, &_31$$13, &_32$$13, &_33$$13);
					zephir_check_call_status();
				}

				ZEPHIR_OBS_NVAR(&_34$$13);
				zephir_array_fetch_string(&_34$$13, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1651);
				if (Z_TYPE_P(&_34$$13) != IS_NULL) {
					ZEPHIR_OBS_NVAR(&_35$$14);
					zephir_array_fetch_string(&_35$$14, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 1652);
					ZEPHIR_CALL_METHOD(NULL, &route, "setHostname", NULL, 0, &_35$$14);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&_36$$13);
				zephir_array_fetch_string(&_36$$13, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 1655);
				if (Z_TYPE_P(&_36$$13) != IS_NULL) {
					ZEPHIR_OBS_NVAR(&_37$$15);
					zephir_array_fetch_string(&_37$$15, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 1656);
					ZEPHIR_CALL_METHOD(NULL, &route, "setName", NULL, 0, &_37$$15);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&_38$$13);
				zephir_array_fetch_string(&_38$$13, &routeData, SL("id"), PH_NOISY, "phalcon/Mvc/Router.zep", 1659);
				ZEPHIR_CALL_METHOD(NULL, &route, "setRouteId", NULL, 0, &_38$$13);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&beforeMatch);
				zephir_array_fetch_string(&beforeMatch, &routeData, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 1661);
				if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &route, "beforeMatch", NULL, 0, &beforeMatch);
					zephir_check_call_status();
				}
				ZEPHIR_OBS_NVAR(&converters);
				zephir_array_fetch_string(&converters, &routeData, SL("converters"), PH_NOISY, "phalcon/Mvc/Router.zep", 1666);
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
							ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_44, 0, &convName, &converter);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _39$$17, "rewind", NULL, 0);
						zephir_check_call_status();
						_46$$17 = 1;
						while (1) {
							if (_46$$17) {
								_46$$17 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _39$$17, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_45$$17, _39$$17, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_45$$17)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&convName, _39$$17, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&converter, _39$$17, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_47, 0, &convName, &converter);
								zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&converter);
					ZEPHIR_INIT_NVAR(&convName);
				}
				zephir_array_append(&rebuiltRoutes, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1673);
		}
	}
	ZEPHIR_INIT_NVAR(&routeData);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 287, &rebuiltRoutes);
	ZEPHIR_INIT_VAR(&methodRoutesRehydrated);
	array_init(&methodRoutesRehydrated);
	zephir_array_fetch_string(&_48, &dump, SL("methodRoutes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1679);
	if (Z_TYPE_P(&_48) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_50);
		zephir_string_to_char_array(&_50, &_48);
		_49 = &_50;
	} else {
		_49 = &_48;
	}
	zephir_is_iterable(_49, 0, "phalcon/Mvc/Router.zep", 1687);
	if (Z_TYPE_P(_49) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_49), _52, _53, _51)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_53 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _53);
			} else {
				ZVAL_LONG(&innerKey, _52);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _51);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_55$$20);
				zephir_string_to_char_array(&_55$$20, &innerVal);
				_54$$20 = &_55$$20;
			} else {
				_54$$20 = &innerVal;
			}
			zephir_is_iterable(_54$$20, 0, "phalcon/Mvc/Router.zep", 1684);
			if (Z_TYPE_P(_54$$20) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_54$$20), _56$$20)
				{
					ZEPHIR_INIT_NVAR(&scalarIdx);
					ZVAL_COPY(&scalarIdx, _56$$20);
					zephir_read_property_cached(&_57$$21, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_58$$21);
					zephir_array_fetch(&_58$$21, &_57$$21, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1682);
					zephir_array_append(&mostInnerArr, &_58$$21, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1682);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _54$$20, "rewind", NULL, 0);
				zephir_check_call_status();
				_60$$20 = 1;
				while (1) {
					if (_60$$20) {
						_60$$20 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _54$$20, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_59$$20, _54$$20, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_59$$20)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarIdx, _54$$20, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property_cached(&_61$$22, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_62$$22);
						zephir_array_fetch(&_62$$22, &_61$$22, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1682);
						zephir_array_append(&mostInnerArr, &_62$$22, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1682);
				}
			}
			ZEPHIR_INIT_NVAR(&scalarIdx);
			zephir_array_update_zval(&methodRoutesRehydrated, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _49, "rewind", NULL, 0);
		zephir_check_call_status();
		_64 = 1;
		while (1) {
			if (_64) {
				_64 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _49, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_63, _49, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_63)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, _49, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, _49, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_66$$23);
					zephir_string_to_char_array(&_66$$23, &innerVal);
					_65$$23 = &_66$$23;
				} else {
					_65$$23 = &innerVal;
				}
				zephir_is_iterable(_65$$23, 0, "phalcon/Mvc/Router.zep", 1684);
				if (Z_TYPE_P(_65$$23) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_65$$23), _67$$23)
					{
						ZEPHIR_INIT_NVAR(&scalarIdx);
						ZVAL_COPY(&scalarIdx, _67$$23);
						zephir_read_property_cached(&_68$$24, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_69$$24);
						zephir_array_fetch(&_69$$24, &_68$$24, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1682);
						zephir_array_append(&mostInnerArr, &_69$$24, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1682);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _65$$23, "rewind", NULL, 0);
					zephir_check_call_status();
					_71$$23 = 1;
					while (1) {
						if (_71$$23) {
							_71$$23 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _65$$23, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_70$$23, _65$$23, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_70$$23)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarIdx, _65$$23, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property_cached(&_72$$25, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_OBS_NVAR(&_73$$25);
							zephir_array_fetch(&_73$$25, &_72$$25, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1682);
							zephir_array_append(&mostInnerArr, &_73$$25, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1682);
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
	zephir_array_fetch_string(&_74, &dump, SL("candidatesByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1688);
	if (Z_TYPE_P(&_74) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_76);
		zephir_string_to_char_array(&_76, &_74);
		_75 = &_76;
	} else {
		_75 = &_74;
	}
	zephir_is_iterable(_75, 0, "phalcon/Mvc/Router.zep", 1696);
	if (Z_TYPE_P(_75) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_75), _78, _79, _77)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_79 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _79);
			} else {
				ZVAL_LONG(&innerKey, _78);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _77);
			ZEPHIR_INIT_NVAR(&mostInnerArr);
			array_init(&mostInnerArr);
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_81$$26);
				zephir_string_to_char_array(&_81$$26, &innerVal);
				_80$$26 = &_81$$26;
			} else {
				_80$$26 = &innerVal;
			}
			zephir_is_iterable(_80$$26, 0, "phalcon/Mvc/Router.zep", 1693);
			if (Z_TYPE_P(_80$$26) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_80$$26), _82$$26)
				{
					ZEPHIR_INIT_NVAR(&scalarIdx);
					ZVAL_COPY(&scalarIdx, _82$$26);
					zephir_read_property_cached(&_83$$27, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_84$$27);
					zephir_array_fetch(&_84$$27, &_83$$27, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1691);
					zephir_array_append(&mostInnerArr, &_84$$27, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1691);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _80$$26, "rewind", NULL, 0);
				zephir_check_call_status();
				_86$$26 = 1;
				while (1) {
					if (_86$$26) {
						_86$$26 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _80$$26, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_85$$26, _80$$26, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_85$$26)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarIdx, _80$$26, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property_cached(&_87$$28, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_88$$28);
						zephir_array_fetch(&_88$$28, &_87$$28, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1691);
						zephir_array_append(&mostInnerArr, &_88$$28, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1691);
				}
			}
			ZEPHIR_INIT_NVAR(&scalarIdx);
			zephir_array_update_zval(&candidatesRehydrated, &innerKey, &mostInnerArr, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _75, "rewind", NULL, 0);
		zephir_check_call_status();
		_90 = 1;
		while (1) {
			if (_90) {
				_90 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _75, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_89, _75, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_89)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, _75, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, _75, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&mostInnerArr);
				array_init(&mostInnerArr);
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_92$$29);
					zephir_string_to_char_array(&_92$$29, &innerVal);
					_91$$29 = &_92$$29;
				} else {
					_91$$29 = &innerVal;
				}
				zephir_is_iterable(_91$$29, 0, "phalcon/Mvc/Router.zep", 1693);
				if (Z_TYPE_P(_91$$29) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_91$$29), _93$$29)
					{
						ZEPHIR_INIT_NVAR(&scalarIdx);
						ZVAL_COPY(&scalarIdx, _93$$29);
						zephir_read_property_cached(&_94$$30, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_95$$30);
						zephir_array_fetch(&_95$$30, &_94$$30, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1691);
						zephir_array_append(&mostInnerArr, &_95$$30, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1691);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _91$$29, "rewind", NULL, 0);
					zephir_check_call_status();
					_97$$29 = 1;
					while (1) {
						if (_97$$29) {
							_97$$29 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _91$$29, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_96$$29, _91$$29, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_96$$29)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarIdx, _91$$29, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property_cached(&_98$$31, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_OBS_NVAR(&_99$$31);
							zephir_array_fetch(&_99$$31, &_98$$31, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1691);
							zephir_array_append(&mostInnerArr, &_99$$31, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1691);
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
	zephir_array_fetch_string(&_100, &dump, SL("staticByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1697);
	if (Z_TYPE_P(&_100) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_102);
		zephir_string_to_char_array(&_102, &_100);
		_101 = &_102;
	} else {
		_101 = &_100;
	}
	zephir_is_iterable(_101, 0, "phalcon/Mvc/Router.zep", 1708);
	if (Z_TYPE_P(_101) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_101), _104, _105, _103)
		{
			ZEPHIR_INIT_NVAR(&innerKey);
			if (_105 != NULL) { 
				ZVAL_STR_COPY(&innerKey, _105);
			} else {
				ZVAL_LONG(&innerKey, _104);
			}
			ZEPHIR_INIT_NVAR(&innerVal);
			ZVAL_COPY(&innerVal, _103);
			ZEPHIR_INIT_NVAR(&_106$$32);
			array_init(&_106$$32);
			zephir_array_update_zval(&staticRehydrated, &innerKey, &_106$$32, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(&innerVal) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_108$$32);
				zephir_string_to_char_array(&_108$$32, &innerVal);
				_107$$32 = &_108$$32;
			} else {
				_107$$32 = &innerVal;
			}
			zephir_is_iterable(_107$$32, 0, "phalcon/Mvc/Router.zep", 1706);
			if (Z_TYPE_P(_107$$32) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_107$$32), _110$$32, _111$$32, _109$$32)
				{
					ZEPHIR_INIT_NVAR(&scalarSubKey);
					if (_111$$32 != NULL) { 
						ZVAL_STR_COPY(&scalarSubKey, _111$$32);
					} else {
						ZVAL_LONG(&scalarSubKey, _110$$32);
					}
					ZEPHIR_INIT_NVAR(&mostInnerVal);
					ZVAL_COPY(&mostInnerVal, _109$$32);
					ZEPHIR_INIT_NVAR(&mostInnerArr);
					array_init(&mostInnerArr);
					if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_113$$33);
						zephir_string_to_char_array(&_113$$33, &mostInnerVal);
						_112$$33 = &_113$$33;
					} else {
						_112$$33 = &mostInnerVal;
					}
					zephir_is_iterable(_112$$33, 0, "phalcon/Mvc/Router.zep", 1704);
					if (Z_TYPE_P(_112$$33) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_112$$33), _114$$33)
						{
							ZEPHIR_INIT_NVAR(&scalarIdx);
							ZVAL_COPY(&scalarIdx, _114$$33);
							zephir_read_property_cached(&_115$$34, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_OBS_NVAR(&_116$$34);
							zephir_array_fetch(&_116$$34, &_115$$34, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
							zephir_array_append(&mostInnerArr, &_116$$34, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _112$$33, "rewind", NULL, 0);
						zephir_check_call_status();
						_118$$33 = 1;
						while (1) {
							if (_118$$33) {
								_118$$33 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _112$$33, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_117$$33, _112$$33, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_117$$33)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&scalarIdx, _112$$33, "current", NULL, 0);
							zephir_check_call_status();
								zephir_read_property_cached(&_119$$35, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_OBS_NVAR(&_120$$35);
								zephir_array_fetch(&_120$$35, &_119$$35, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
								zephir_array_append(&mostInnerArr, &_120$$35, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
						}
					}
					ZEPHIR_INIT_NVAR(&scalarIdx);
					zephir_array_update_multi(&staticRehydrated, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _107$$32, "rewind", NULL, 0);
				zephir_check_call_status();
				_122$$32 = 1;
				while (1) {
					if (_122$$32) {
						_122$$32 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _107$$32, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_121$$32, _107$$32, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_121$$32)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&scalarSubKey, _107$$32, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&mostInnerVal, _107$$32, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_124$$36);
							zephir_string_to_char_array(&_124$$36, &mostInnerVal);
							_123$$36 = &_124$$36;
						} else {
							_123$$36 = &mostInnerVal;
						}
						zephir_is_iterable(_123$$36, 0, "phalcon/Mvc/Router.zep", 1704);
						if (Z_TYPE_P(_123$$36) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_123$$36), _125$$36)
							{
								ZEPHIR_INIT_NVAR(&scalarIdx);
								ZVAL_COPY(&scalarIdx, _125$$36);
								zephir_read_property_cached(&_126$$37, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_OBS_NVAR(&_127$$37);
								zephir_array_fetch(&_127$$37, &_126$$37, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
								zephir_array_append(&mostInnerArr, &_127$$37, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _123$$36, "rewind", NULL, 0);
							zephir_check_call_status();
							_129$$36 = 1;
							while (1) {
								if (_129$$36) {
									_129$$36 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _123$$36, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_128$$36, _123$$36, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_128$$36)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarIdx, _123$$36, "current", NULL, 0);
								zephir_check_call_status();
									zephir_read_property_cached(&_130$$38, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_OBS_NVAR(&_131$$38);
									zephir_array_fetch(&_131$$38, &_130$$38, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
									zephir_array_append(&mostInnerArr, &_131$$38, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
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
		ZEPHIR_CALL_METHOD(NULL, _101, "rewind", NULL, 0);
		zephir_check_call_status();
		_133 = 1;
		while (1) {
			if (_133) {
				_133 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _101, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_132, _101, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_132)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&innerKey, _101, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&innerVal, _101, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_134$$39);
				array_init(&_134$$39);
				zephir_array_update_zval(&staticRehydrated, &innerKey, &_134$$39, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(&innerVal) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_136$$39);
					zephir_string_to_char_array(&_136$$39, &innerVal);
					_135$$39 = &_136$$39;
				} else {
					_135$$39 = &innerVal;
				}
				zephir_is_iterable(_135$$39, 0, "phalcon/Mvc/Router.zep", 1706);
				if (Z_TYPE_P(_135$$39) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_135$$39), _138$$39, _139$$39, _137$$39)
					{
						ZEPHIR_INIT_NVAR(&scalarSubKey);
						if (_139$$39 != NULL) { 
							ZVAL_STR_COPY(&scalarSubKey, _139$$39);
						} else {
							ZVAL_LONG(&scalarSubKey, _138$$39);
						}
						ZEPHIR_INIT_NVAR(&mostInnerVal);
						ZVAL_COPY(&mostInnerVal, _137$$39);
						ZEPHIR_INIT_NVAR(&mostInnerArr);
						array_init(&mostInnerArr);
						if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_141$$40);
							zephir_string_to_char_array(&_141$$40, &mostInnerVal);
							_140$$40 = &_141$$40;
						} else {
							_140$$40 = &mostInnerVal;
						}
						zephir_is_iterable(_140$$40, 0, "phalcon/Mvc/Router.zep", 1704);
						if (Z_TYPE_P(_140$$40) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_140$$40), _142$$40)
							{
								ZEPHIR_INIT_NVAR(&scalarIdx);
								ZVAL_COPY(&scalarIdx, _142$$40);
								zephir_read_property_cached(&_143$$41, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_OBS_NVAR(&_144$$41);
								zephir_array_fetch(&_144$$41, &_143$$41, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
								zephir_array_append(&mostInnerArr, &_144$$41, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _140$$40, "rewind", NULL, 0);
							zephir_check_call_status();
							_146$$40 = 1;
							while (1) {
								if (_146$$40) {
									_146$$40 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _140$$40, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_145$$40, _140$$40, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_145$$40)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&scalarIdx, _140$$40, "current", NULL, 0);
								zephir_check_call_status();
									zephir_read_property_cached(&_147$$42, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_OBS_NVAR(&_148$$42);
									zephir_array_fetch(&_148$$42, &_147$$42, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
									zephir_array_append(&mostInnerArr, &_148$$42, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
							}
						}
						ZEPHIR_INIT_NVAR(&scalarIdx);
						zephir_array_update_multi(&staticRehydrated, &mostInnerArr, SL("zz"), 2, &innerKey, &scalarSubKey);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _135$$39, "rewind", NULL, 0);
					zephir_check_call_status();
					_150$$39 = 1;
					while (1) {
						if (_150$$39) {
							_150$$39 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _135$$39, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_149$$39, _135$$39, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_149$$39)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&scalarSubKey, _135$$39, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&mostInnerVal, _135$$39, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&mostInnerArr);
							array_init(&mostInnerArr);
							if (Z_TYPE_P(&mostInnerVal) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_152$$43);
								zephir_string_to_char_array(&_152$$43, &mostInnerVal);
								_151$$43 = &_152$$43;
							} else {
								_151$$43 = &mostInnerVal;
							}
							zephir_is_iterable(_151$$43, 0, "phalcon/Mvc/Router.zep", 1704);
							if (Z_TYPE_P(_151$$43) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_151$$43), _153$$43)
								{
									ZEPHIR_INIT_NVAR(&scalarIdx);
									ZVAL_COPY(&scalarIdx, _153$$43);
									zephir_read_property_cached(&_154$$44, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_OBS_NVAR(&_155$$44);
									zephir_array_fetch(&_155$$44, &_154$$44, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
									zephir_array_append(&mostInnerArr, &_155$$44, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _151$$43, "rewind", NULL, 0);
								zephir_check_call_status();
								_157$$43 = 1;
								while (1) {
									if (_157$$43) {
										_157$$43 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _151$$43, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_156$$43, _151$$43, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_156$$43)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&scalarIdx, _151$$43, "current", NULL, 0);
									zephir_check_call_status();
										zephir_read_property_cached(&_158$$45, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
										ZEPHIR_OBS_NVAR(&_159$$45);
										zephir_array_fetch(&_159$$45, &_158$$45, &scalarIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 1702);
										zephir_array_append(&mostInnerArr, &_159$$45, PH_SEPARATE, "phalcon/Mvc/Router.zep", 1702);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 289, &methodRoutesRehydrated);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 290, &candidatesRehydrated);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 291, &staticRehydrated);
	zephir_array_fetch_string(&_160, &dump, SL("staticShadowedByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1711);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 292, &_160);
	zephir_array_fetch_string(&_161, &dump, SL("hostnameByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1712);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 293, &_161);
	zephir_array_fetch_string(&_162, &dump, SL("hostnameLessByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1713);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 294, &_162);
	zephir_array_fetch_string(&_163, &dump, SL("combinedRegexByMethod"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1714);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 295, &_163);
	zephir_array_fetch_string(&_164, &dump, SL("combinedRegexDisabled"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1715);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 296, &_164);
	zephir_array_fetch_string(&_165, &dump, SL("combinedRegexMarkMap"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1716);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 297, &_165);
	zephir_array_fetch_string(&_166, &dump, SL("routeMeta"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 1717);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 298, &_166);
	ZEPHIR_INIT_VAR(&_167);
	array_init(&_167);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 305, &_167);
	ZEPHIR_INIT_VAR(&_168);
	array_init(&_168);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_12, 306, &_168);
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_13, 288, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_13, 288, &__$false);
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
	zend_bool _9$$9, _15$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, routes, routeData, defaults, notFoundPaths, removeExtra, groups, groupData, _0$$4, _1$$3, _2$$5, _3$$6, *_4$$9, _5$$9, *_6$$9, _8$$9, *_10$$13, _11$$13, *_12$$13, _14$$13;
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
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_14$$13);
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
			ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 274);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/Router.zep", 1752);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_1$$3, config, "toArray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_1$$3);
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, phalcon_mvc_router_exceptions_invalidconfigsource_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 274);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Router.zep", 1758);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_array_isset_value_string(config, SL("removeExtraSlashes"))) {
		zephir_memory_observe(&removeExtra);
		zephir_array_fetch_string(&removeExtra, config, SL("removeExtraSlashes"), PH_NOISY, "phalcon/Mvc/Router.zep", 1762);
		ZVAL_BOOL(&_3$$6, zephir_get_boolval(&removeExtra));
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "removeExtraSlashes", NULL, 0, &_3$$6);
		zephir_check_call_status();
	}
	if (zephir_array_isset_value_string(config, SL("defaults"))) {
		zephir_memory_observe(&defaults);
		zephir_array_fetch_string(&defaults, config, SL("defaults"), PH_NOISY, "phalcon/Mvc/Router.zep", 1767);
		if (Z_TYPE_P(&defaults) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_configkeymustbearray_ce, "defaults", "phalcon/Mvc/Router.zep", 1769);
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setDefaults", NULL, 0, &defaults);
		zephir_check_call_status();
	}
	zephir_memory_observe(&routes);
	if (zephir_array_isset_string_fetch(&routes, config, SL("routes"), 0)) {
		if (Z_TYPE_P(&routes) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_configkeymustbearray_ce, "routes", "phalcon/Mvc/Router.zep", 1776);
			return;
		}
		if (Z_TYPE_P(&routes) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_5$$9);
			zephir_string_to_char_array(&_5$$9, &routes);
			_4$$9 = &_5$$9;
		} else {
			_4$$9 = &routes;
		}
		zephir_is_iterable(_4$$9, 0, "phalcon/Mvc/Router.zep", 1781);
		if (Z_TYPE_P(_4$$9) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4$$9), _6$$9)
			{
				ZEPHIR_INIT_NVAR(&routeData);
				ZVAL_COPY(&routeData, _6$$9);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addRouteFromConfig", &_7, 0, &routeData);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _4$$9, "rewind", NULL, 0);
			zephir_check_call_status();
			_9$$9 = 1;
			while (1) {
				if (_9$$9) {
					_9$$9 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _4$$9, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_8$$9, _4$$9, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&routeData, _4$$9, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "addRouteFromConfig", &_7, 0, &routeData);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&routeData);
	}
	zephir_memory_observe(&groups);
	if (zephir_array_isset_string_fetch(&groups, config, SL("groups"), 0)) {
		if (Z_TYPE_P(&groups) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_configkeymustbearray_ce, "groups", "phalcon/Mvc/Router.zep", 1785);
			return;
		}
		if (Z_TYPE_P(&groups) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_11$$13);
			zephir_string_to_char_array(&_11$$13, &groups);
			_10$$13 = &_11$$13;
		} else {
			_10$$13 = &groups;
		}
		zephir_is_iterable(_10$$13, 0, "phalcon/Mvc/Router.zep", 1790);
		if (Z_TYPE_P(_10$$13) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_10$$13), _12$$13)
			{
				ZEPHIR_INIT_NVAR(&groupData);
				ZVAL_COPY(&groupData, _12$$13);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "mountGroupFromConfig", &_13, 0, &groupData);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _10$$13, "rewind", NULL, 0);
			zephir_check_call_status();
			_15$$13 = 1;
			while (1) {
				if (_15$$13) {
					_15$$13 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _10$$13, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_14$$13, _10$$13, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$13)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&groupData, _10$$13, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "mountGroupFromConfig", &_13, 0, &groupData);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&groupData);
	}
	zephir_memory_observe(&notFoundPaths);
	if (zephir_array_isset_string_fetch(&notFoundPaths, config, SL("notFound"), 0)) {
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 311, PH_NOISY_CC | PH_READONLY);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 313, paths);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 307, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 307, &__$false);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 302, &actionName_zv);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 301, &controllerName_zv);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 300, &moduleName_zv);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 299, &namespaceName_zv);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 299, &_0$$3);
	}
	zephir_memory_observe(&module);
	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 0)) {
		zephir_cast_to_string(&_1$$4, &module);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 300, &_1$$4);
	}
	zephir_memory_observe(&controller);
	if (zephir_array_isset_string_fetch(&controller, &defaults, SL("controller"), 0)) {
		zephir_cast_to_string(&_2$$5, &controller);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 301, &_2$$5);
	}
	zephir_memory_observe(&action);
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 0)) {
		zephir_cast_to_string(&_3$$6, &action);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 302, &_3$$6);
	}
	zephir_memory_observe(&params);
	if (zephir_array_isset_string_fetch(&params, &defaults, SL("params"), 0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 303, &params);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 311, eventsManager);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 305, &routeIds);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 306, &routeNames);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 304, &_0);
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
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 9, &_2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Router.zep", 2081);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadDispatcherFromArray", NULL, 0, &stored);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 319, cache);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 320, &key_zv);
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
	zval _3$$5, _7$$8, _9$$9;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routeData_param = NULL, methodClass, pattern, paths, method, route, _1, _2$$5, _4$$6, _5$$7, _6$$8, _8$$9;
	zval routeData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeData);
	ZVAL_UNDEF(&methodClass);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&method);
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
	ZEPHIR_INIT_VAR(&method);
	ZVAL_STRING(&method, "");
	ZEPHIR_INIT_VAR(&route);
	ZVAL_NULL(&route);
	zephir_memory_observe(&pattern);
	if (!(zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missingrouteconfigkey_ce, "pattern", "phalcon/Mvc/Router.zep", 2116);
		return;
	}
	zephir_memory_observe(&paths);
	if (!(zephir_array_isset_string_fetch(&paths, &routeData, SL("paths"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missingrouteconfigkey_ce, "paths", "phalcon/Mvc/Router.zep", 2120);
		return;
	}
	_0 = zephir_array_isset_value_string(&routeData, SL("method"));
	if (_0) {
		zephir_array_fetch_string(&_1, &routeData, SL("method"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2123);
		_0 = Z_TYPE_P(&_1) != IS_NULL;
	}
	if (_0) {
		zephir_memory_observe(&_2$$5);
		zephir_array_fetch_string(&_2$$5, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2124);
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
		ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", NULL, 277, &method);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$7, "phalcon/Mvc/Router.zep", 2143);
		ZEPHIR_MM_RESTORE();
		return;
	zephir_switch_0_end: ;

	if (zephir_array_isset_value_string(&routeData, SL("name"))) {
		zephir_memory_observe(&_6$$8);
		zephir_array_fetch_string(&_6$$8, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 2147);
		zephir_cast_to_string(&_7$$8, &_6$$8);
		ZEPHIR_CALL_METHOD(NULL, &route, "setName", NULL, 0, &_7$$8);
		zephir_check_call_status();
	}
	if (zephir_array_isset_value_string(&routeData, SL("hostname"))) {
		zephir_memory_observe(&_8$$9);
		zephir_array_fetch_string(&_8$$9, &routeData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 2150);
		zephir_cast_to_string(&_9$$9, &_8$$9);
		ZEPHIR_CALL_METHOD(NULL, &route, "setHostname", NULL, 0, &_9$$9);
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
	zephir_memory_observe(&realUri);
	zephir_array_fetch_long(&realUri, &urlParts, 0, PH_NOISY, "phalcon/Mvc/Router.zep", 2159);
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
	zval _1$$4, _3$$5, _11$$11, _16$$14, _22$$18, _26$$21;
	zend_bool _18, _8$$8, _19$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *groupData_param = NULL, group, paths, routes, routeData, method, methodClass, pattern, routePaths, route, *_5, _6, *_7, _17, _0$$4, _2$$5, _4$$7, _9$$8, _10$$11, _12$$12, _13$$13, _15$$14, _20$$15, _21$$18, _23$$19, _24$$20, _25$$21;
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_23$$19);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_25$$21);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_26$$21);
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
	if (zephir_array_isset_value_string(&groupData, SL("paths"))) {
		ZEPHIR_OBS_NVAR(&paths);
		zephir_array_fetch_string(&paths, &groupData, SL("paths"), PH_NOISY, "phalcon/Mvc/Router.zep", 2180);
	}
	ZEPHIR_INIT_VAR(&group);
	object_init_ex(&group, phalcon_mvc_router_group_ce);
	ZEPHIR_CALL_METHOD(NULL, &group, "__construct", NULL, 278, &paths);
	zephir_check_call_status();
	if (zephir_array_isset_value_string(&groupData, SL("prefix"))) {
		zephir_memory_observe(&_0$$4);
		zephir_array_fetch_string(&_0$$4, &groupData, SL("prefix"), PH_NOISY, "phalcon/Mvc/Router.zep", 2186);
		zephir_cast_to_string(&_1$$4, &_0$$4);
		ZEPHIR_CALL_METHOD(NULL, &group, "setPrefix", NULL, 279, &_1$$4);
		zephir_check_call_status();
	}
	if (zephir_array_isset_value_string(&groupData, SL("hostname"))) {
		zephir_memory_observe(&_2$$5);
		zephir_array_fetch_string(&_2$$5, &groupData, SL("hostname"), PH_NOISY, "phalcon/Mvc/Router.zep", 2190);
		zephir_cast_to_string(&_3$$5, &_2$$5);
		ZEPHIR_CALL_METHOD(NULL, &group, "setHostname", NULL, 280, &_3$$5);
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
		ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", NULL, 281);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$7, "phalcon/Mvc/Router.zep", 2198);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&routes) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_6);
		zephir_string_to_char_array(&_6, &routes);
		_5 = &_6;
	} else {
		_5 = &routes;
	}
	zephir_is_iterable(_5, 0, "phalcon/Mvc/Router.zep", 2238);
	if (Z_TYPE_P(_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_5), _7)
		{
			ZEPHIR_INIT_NVAR(&routeData);
			ZVAL_COPY(&routeData, _7);
			ZEPHIR_OBS_NVAR(&pattern);
			if (!(zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "pattern", "phalcon/Mvc/Router.zep", 2203);
				return;
			}
			ZEPHIR_OBS_NVAR(&routePaths);
			if (!(zephir_array_isset_string_fetch(&routePaths, &routeData, SL("paths"), 0))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "paths", "phalcon/Mvc/Router.zep", 2206);
				return;
			}
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_STRING(&method, "");
			_8$$8 = zephir_array_isset_value_string(&routeData, SL("method"));
			if (_8$$8) {
				ZEPHIR_OBS_NVAR(&_9$$8);
				zephir_array_fetch_string(&_9$$8, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2210);
				_8$$8 = Z_TYPE_P(&_9$$8) != IS_NULL;
			}
			if (_8$$8) {
				ZEPHIR_OBS_NVAR(&_10$$11);
				zephir_array_fetch_string(&_10$$11, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2211);
				zephir_cast_to_string(&_11$$11, &_10$$11);
				ZEPHIR_INIT_NVAR(&method);
				zephir_fast_strtolower(&method, &_11$$11);
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
				ZEPHIR_INIT_NVAR(&_12$$12);
				zephir_ucfirst(&_12$$12, &method);
				ZEPHIR_INIT_NVAR(&methodClass);
				ZEPHIR_CONCAT_SV(&methodClass, "add", &_12$$12);
				ZEPHIR_CALL_METHOD_ZVAL(&route, &group, &methodClass, NULL, 0, &pattern, &routePaths);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_11: ;
				ZEPHIR_INIT_NVAR(&_13$$13);
				object_init_ex(&_13$$13, phalcon_mvc_router_exceptions_unknownhttpmethod_ce);
				ZEPHIR_CALL_METHOD(NULL, &_13$$13, "__construct", &_14, 277, &method);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_13$$13, "phalcon/Mvc/Router.zep", 2230);
				ZEPHIR_MM_RESTORE();
				return;
			zephir_switch_0_end: ;

			if (zephir_array_isset_value_string(&routeData, SL("name"))) {
				ZEPHIR_OBS_NVAR(&_15$$14);
				zephir_array_fetch_string(&_15$$14, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 2234);
				zephir_cast_to_string(&_16$$14, &_15$$14);
				ZEPHIR_CALL_METHOD(NULL, &route, "setName", NULL, 0, &_16$$14);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _5, "rewind", NULL, 0);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _5, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_17, _5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&routeData, _5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&pattern);
				if (!(zephir_array_isset_string_fetch(&pattern, &routeData, SL("pattern"), 0))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "pattern", "phalcon/Mvc/Router.zep", 2203);
					return;
				}
				ZEPHIR_OBS_NVAR(&routePaths);
				if (!(zephir_array_isset_string_fetch(&routePaths, &routeData, SL("paths"), 0))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exceptions_missinggrouproutekey_ce, "paths", "phalcon/Mvc/Router.zep", 2206);
					return;
				}
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_STRING(&method, "");
				_19$$15 = zephir_array_isset_value_string(&routeData, SL("method"));
				if (_19$$15) {
					ZEPHIR_OBS_NVAR(&_20$$15);
					zephir_array_fetch_string(&_20$$15, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2210);
					_19$$15 = Z_TYPE_P(&_20$$15) != IS_NULL;
				}
				if (_19$$15) {
					ZEPHIR_OBS_NVAR(&_21$$18);
					zephir_array_fetch_string(&_21$$18, &routeData, SL("method"), PH_NOISY, "phalcon/Mvc/Router.zep", 2211);
					zephir_cast_to_string(&_22$$18, &_21$$18);
					ZEPHIR_INIT_NVAR(&method);
					zephir_fast_strtolower(&method, &_22$$18);
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
					ZEPHIR_INIT_NVAR(&_23$$19);
					zephir_ucfirst(&_23$$19, &method);
					ZEPHIR_INIT_NVAR(&methodClass);
					ZEPHIR_CONCAT_SV(&methodClass, "add", &_23$$19);
					ZEPHIR_CALL_METHOD_ZVAL(&route, &group, &methodClass, NULL, 0, &pattern, &routePaths);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_clause_11: ;
					ZEPHIR_INIT_NVAR(&_24$$20);
					object_init_ex(&_24$$20, phalcon_mvc_router_exceptions_unknownhttpmethod_ce);
					ZEPHIR_CALL_METHOD(NULL, &_24$$20, "__construct", &_14, 277, &method);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_24$$20, "phalcon/Mvc/Router.zep", 2230);
					ZEPHIR_MM_RESTORE();
					return;
				zephir_switch_1_end: ;

				if (zephir_array_isset_value_string(&routeData, SL("name"))) {
					ZEPHIR_OBS_NVAR(&_25$$21);
					zephir_array_fetch_string(&_25$$21, &routeData, SL("name"), PH_NOISY, "phalcon/Mvc/Router.zep", 2234);
					zephir_cast_to_string(&_26$$21, &_25$$21);
					ZEPHIR_CALL_METHOD(NULL, &route, "setName", NULL, 0, &_26$$21);
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
	zval _123$$66, _139$$71;
	zval _6$$3, _16$$13;
	zend_string *_5, *_28, *_41, *_89, *_103, *_34$$24, *_46$$38, *_58$$43, *_78$$52, *_96$$57, *_108$$64;
	zend_ulong _4, _27, _40, _88, _102, _33$$24, _45$$38, _57$$43, _77$$52, _95$$57, _107$$64;
	zend_bool isRegex = 0, _15, _13$$10, _23$$20, _36$$24, _66$$38, _48$$40, _50$$40, _62$$43, _68$$49, _70$$49, _82$$52, _98$$57, _125$$64, _109$$66, _112$$66, _113$$66, _114$$66, _119$$66, _126$$71, _129$$71, _130$$71, _131$$71, _136$$71, _150$$78;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_121 = NULL, *_141 = NULL, *_144 = NULL;
	zval __$true, __$false, route, methods, method, methodSpecific, starRoutes, candidates, candidatePattern, bucketRoute, bucketPattern, staticUri, staticBucket, staticRoutesList, shadowBucket, bucket, methodRoutes, candidatesByMethod, routeMeta, staticByMethod, staticShadowedByMethod, hostnameByMethod, hostnameLessByMethod, combinedRegexByMethod, combinedRegexMarkMap, combinedRegexDisabled, routePatterns, routeHosts, candidateHost, routeData, routeMethods, routeIndex, starPositions, positions, positionsByMethod, bucketIdx, _0, *_1, _2, *_3, _14, *_24, _25, *_26, *_37, _38, *_39, bucketHostname, *_85, _86, *_87, combinedAlternatives, combinedMark, combinedBody, hostnameBucketRef, *_99, _100, *_101, _7$$3, _8$$3, *_9$$10, _10$$10, *_11$$10, _12$$10, _17$$13, _18$$13, *_19$$20, _20$$20, *_21$$20, _22$$20, _29$$24, *_30$$24, _31$$24, *_32$$24, _35$$24, *_42$$38, _43$$38, *_44$$38, _65$$38, _47$$40, _49$$40, _51$$40, _52$$40, _53$$40, *_54$$43, _55$$43, *_56$$43, _61$$43, _59$$44, _60$$44, _63$$46, _64$$46, _67$$49, _69$$49, _71$$49, _72$$49, _73$$49, *_74$$52, _75$$52, *_76$$52, _81$$52, _79$$53, _80$$53, _83$$55, _84$$55, _90$$57, _91$$57, *_92$$57, _93$$57, *_94$$57, _97$$57, *_104$$64, _105$$64, *_106$$64, _124$$64, chunkedPatterns$$64, chunkedMarkMaps$$64, chunkOffset$$64, chunkSlice$$64, chunkSliceMap$$64, chunkMarkSubset$$64, reversedMarkIds$$64, chunkMarkId$$64, chunkPattern$$64, _140$$64, _142$$64, _110$$66, _111$$66, _115$$66, _116$$66, _117$$66, _118$$66, _120$$66, _122$$66, _127$$71, _128$$71, _132$$71, _133$$71, _134$$71, _135$$71, _137$$71, _138$$71, _143$$78, *_145$$78, _146$$78, *_147$$78, _149$$78, _152$$78, _153$$78, _154$$78, _155$$78, _156$$78, _157$$78, _148$$79, _151$$80;
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
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&bucketHostname);
	ZVAL_UNDEF(&_86);
	ZVAL_UNDEF(&combinedAlternatives);
	ZVAL_UNDEF(&combinedMark);
	ZVAL_UNDEF(&combinedBody);
	ZVAL_UNDEF(&hostnameBucketRef);
	ZVAL_UNDEF(&_100);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_20$$20);
	ZVAL_UNDEF(&_22$$20);
	ZVAL_UNDEF(&_29$$24);
	ZVAL_UNDEF(&_31$$24);
	ZVAL_UNDEF(&_35$$24);
	ZVAL_UNDEF(&_43$$38);
	ZVAL_UNDEF(&_65$$38);
	ZVAL_UNDEF(&_47$$40);
	ZVAL_UNDEF(&_49$$40);
	ZVAL_UNDEF(&_51$$40);
	ZVAL_UNDEF(&_52$$40);
	ZVAL_UNDEF(&_53$$40);
	ZVAL_UNDEF(&_55$$43);
	ZVAL_UNDEF(&_61$$43);
	ZVAL_UNDEF(&_59$$44);
	ZVAL_UNDEF(&_60$$44);
	ZVAL_UNDEF(&_63$$46);
	ZVAL_UNDEF(&_64$$46);
	ZVAL_UNDEF(&_67$$49);
	ZVAL_UNDEF(&_69$$49);
	ZVAL_UNDEF(&_71$$49);
	ZVAL_UNDEF(&_72$$49);
	ZVAL_UNDEF(&_73$$49);
	ZVAL_UNDEF(&_75$$52);
	ZVAL_UNDEF(&_81$$52);
	ZVAL_UNDEF(&_79$$53);
	ZVAL_UNDEF(&_80$$53);
	ZVAL_UNDEF(&_83$$55);
	ZVAL_UNDEF(&_84$$55);
	ZVAL_UNDEF(&_90$$57);
	ZVAL_UNDEF(&_91$$57);
	ZVAL_UNDEF(&_93$$57);
	ZVAL_UNDEF(&_97$$57);
	ZVAL_UNDEF(&_105$$64);
	ZVAL_UNDEF(&_124$$64);
	ZVAL_UNDEF(&chunkedPatterns$$64);
	ZVAL_UNDEF(&chunkedMarkMaps$$64);
	ZVAL_UNDEF(&chunkOffset$$64);
	ZVAL_UNDEF(&chunkSlice$$64);
	ZVAL_UNDEF(&chunkSliceMap$$64);
	ZVAL_UNDEF(&chunkMarkSubset$$64);
	ZVAL_UNDEF(&reversedMarkIds$$64);
	ZVAL_UNDEF(&chunkMarkId$$64);
	ZVAL_UNDEF(&chunkPattern$$64);
	ZVAL_UNDEF(&_140$$64);
	ZVAL_UNDEF(&_142$$64);
	ZVAL_UNDEF(&_110$$66);
	ZVAL_UNDEF(&_111$$66);
	ZVAL_UNDEF(&_115$$66);
	ZVAL_UNDEF(&_116$$66);
	ZVAL_UNDEF(&_117$$66);
	ZVAL_UNDEF(&_118$$66);
	ZVAL_UNDEF(&_120$$66);
	ZVAL_UNDEF(&_122$$66);
	ZVAL_UNDEF(&_127$$71);
	ZVAL_UNDEF(&_128$$71);
	ZVAL_UNDEF(&_132$$71);
	ZVAL_UNDEF(&_133$$71);
	ZVAL_UNDEF(&_134$$71);
	ZVAL_UNDEF(&_135$$71);
	ZVAL_UNDEF(&_137$$71);
	ZVAL_UNDEF(&_138$$71);
	ZVAL_UNDEF(&_143$$78);
	ZVAL_UNDEF(&_146$$78);
	ZVAL_UNDEF(&_149$$78);
	ZVAL_UNDEF(&_152$$78);
	ZVAL_UNDEF(&_153$$78);
	ZVAL_UNDEF(&_154$$78);
	ZVAL_UNDEF(&_155$$78);
	ZVAL_UNDEF(&_156$$78);
	ZVAL_UNDEF(&_157$$78);
	ZVAL_UNDEF(&_148$$79);
	ZVAL_UNDEF(&_151$$80);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_123$$66);
	ZVAL_UNDEF(&_139$$71);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
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
			ZEPHIR_OBS_NVAR(&candidatePattern);
			zephir_array_fetch_long(&candidatePattern, &routeData, 1, PH_NOISY, "phalcon/Mvc/Router.zep", 2284);
			ZEPHIR_OBS_NVAR(&candidateHost);
			zephir_array_fetch_long(&candidateHost, &routeData, 2, PH_NOISY, "phalcon/Mvc/Router.zep", 2285);
			isRegex = 0;
			if (zephir_memnstr_str(&candidatePattern, SL("^"), "phalcon/Mvc/Router.zep", 2288)) {
				isRegex = 1;
			}
			ZEPHIR_INIT_NVAR(&_6$$3);
			zephir_create_array(&_6$$3, 5, 0);
			zephir_array_update_string(&_6$$3, SL("pattern"), &candidatePattern, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZVAL_BOOL(&_7$$3, isRegex);
			zephir_array_update_string(&_6$$3, SL("isRegex"), &_7$$3, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_6$$3, SL("hostname"), &candidateHost, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_8$$3);
			zephir_array_fetch_long(&_8$$3, &routeData, 3, PH_NOISY, "phalcon/Mvc/Router.zep", 2296);
			zephir_array_update_string(&_6$$3, SL("hostRegex"), &_8$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_8$$3);
			zephir_array_fetch_long(&_8$$3, &routeData, 4, PH_NOISY, "phalcon/Mvc/Router.zep", 2298);
			zephir_array_update_string(&_6$$3, SL("beforeMatch"), &_8$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_8$$3);
			zephir_array_fetch_long(&_8$$3, &routeData, 5, PH_NOISY, "phalcon/Mvc/Router.zep", 2292);
			zephir_array_update_zval(&routeMeta, &_8$$3, &_6$$3, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&routePatterns, &routeIndex, &candidatePattern, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&routeHosts, &routeIndex, &candidateHost, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(&methods) == IS_NULL) {
				if (Z_TYPE_P(&starPositions) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&starPositions);
					array_init(&starPositions);
				}
				zephir_array_update_multi(&methodRoutes, &route, SL("sa"), 3, SL("*"));
				zephir_array_append(&starPositions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2309);
			} else {
				if (Z_TYPE_P(&routeMethods) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&routeMethods);
					array_init(&routeMethods);
				}
				zephir_array_update_zval(&routeMethods, &routeIndex, &methods, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(&methods) == IS_STRING) {
					zephir_array_update_multi(&methodRoutes, &route, SL("za"), 2, &methods);
				} else {
					if (Z_TYPE_P(&methods) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_10$$10);
						zephir_string_to_char_array(&_10$$10, &methods);
						_9$$10 = &_10$$10;
					} else {
						_9$$10 = &methods;
					}
					zephir_is_iterable(_9$$10, 0, "phalcon/Mvc/Router.zep", 2327);
					if (Z_TYPE_P(_9$$10) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9$$10), _11$$10)
						{
							ZEPHIR_INIT_NVAR(&method);
							ZVAL_COPY(&method, _11$$10);
							zephir_array_update_multi(&methodRoutes, &route, SL("za"), 2, &method);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _9$$10, "rewind", NULL, 0);
						zephir_check_call_status();
						_13$$10 = 1;
						while (1) {
							if (_13$$10) {
								_13$$10 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _9$$10, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_12$$10, _9$$10, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_12$$10)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&method, _9$$10, "current", NULL, 0);
							zephir_check_call_status();
								zephir_array_update_multi(&methodRoutes, &route, SL("za"), 2, &method);
						}
					}
					ZEPHIR_INIT_NVAR(&method);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_15 = 1;
		while (1) {
			if (_15) {
				_15 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_14, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
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
				ZEPHIR_OBS_NVAR(&candidatePattern);
				zephir_array_fetch_long(&candidatePattern, &routeData, 1, PH_NOISY, "phalcon/Mvc/Router.zep", 2284);
				ZEPHIR_OBS_NVAR(&candidateHost);
				zephir_array_fetch_long(&candidateHost, &routeData, 2, PH_NOISY, "phalcon/Mvc/Router.zep", 2285);
				isRegex = 0;
				if (zephir_memnstr_str(&candidatePattern, SL("^"), "phalcon/Mvc/Router.zep", 2288)) {
					isRegex = 1;
				}
				ZEPHIR_INIT_NVAR(&_16$$13);
				zephir_create_array(&_16$$13, 5, 0);
				zephir_array_update_string(&_16$$13, SL("pattern"), &candidatePattern, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_17$$13);
				ZVAL_BOOL(&_17$$13, isRegex);
				zephir_array_update_string(&_16$$13, SL("isRegex"), &_17$$13, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_16$$13, SL("hostname"), &candidateHost, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_18$$13);
				zephir_array_fetch_long(&_18$$13, &routeData, 3, PH_NOISY, "phalcon/Mvc/Router.zep", 2296);
				zephir_array_update_string(&_16$$13, SL("hostRegex"), &_18$$13, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_18$$13);
				zephir_array_fetch_long(&_18$$13, &routeData, 4, PH_NOISY, "phalcon/Mvc/Router.zep", 2298);
				zephir_array_update_string(&_16$$13, SL("beforeMatch"), &_18$$13, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_18$$13);
				zephir_array_fetch_long(&_18$$13, &routeData, 5, PH_NOISY, "phalcon/Mvc/Router.zep", 2292);
				zephir_array_update_zval(&routeMeta, &_18$$13, &_16$$13, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&routePatterns, &routeIndex, &candidatePattern, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&routeHosts, &routeIndex, &candidateHost, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(&methods) == IS_NULL) {
					if (Z_TYPE_P(&starPositions) == IS_NULL) {
						ZEPHIR_INIT_NVAR(&starPositions);
						array_init(&starPositions);
					}
					zephir_array_update_multi(&methodRoutes, &route, SL("sa"), 3, SL("*"));
					zephir_array_append(&starPositions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2309);
				} else {
					if (Z_TYPE_P(&routeMethods) == IS_NULL) {
						ZEPHIR_INIT_NVAR(&routeMethods);
						array_init(&routeMethods);
					}
					zephir_array_update_zval(&routeMethods, &routeIndex, &methods, PH_COPY | PH_SEPARATE);
					if (Z_TYPE_P(&methods) == IS_STRING) {
						zephir_array_update_multi(&methodRoutes, &route, SL("za"), 2, &methods);
					} else {
						if (Z_TYPE_P(&methods) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_20$$20);
							zephir_string_to_char_array(&_20$$20, &methods);
							_19$$20 = &_20$$20;
						} else {
							_19$$20 = &methods;
						}
						zephir_is_iterable(_19$$20, 0, "phalcon/Mvc/Router.zep", 2327);
						if (Z_TYPE_P(_19$$20) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_19$$20), _21$$20)
							{
								ZEPHIR_INIT_NVAR(&method);
								ZVAL_COPY(&method, _21$$20);
								zephir_array_update_multi(&methodRoutes, &route, SL("za"), 2, &method);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _19$$20, "rewind", NULL, 0);
							zephir_check_call_status();
							_23$$20 = 1;
							while (1) {
								if (_23$$20) {
									_23$$20 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _19$$20, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_22$$20, _19$$20, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_22$$20)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&method, _19$$20, "current", NULL, 0);
								zephir_check_call_status();
									zephir_array_update_multi(&methodRoutes, &route, SL("za"), 2, &method);
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
	if (!(zephir_array_isset_string_fetch(&starRoutes, &methodRoutes, SL("*"), 0))) {
		ZEPHIR_INIT_NVAR(&starRoutes);
		array_init(&starRoutes);
	}
	if (Z_TYPE_P(&methodRoutes) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_25);
		zephir_string_to_char_array(&_25, &methodRoutes);
		_24 = &_25;
	} else {
		_24 = &methodRoutes;
	}
	zephir_is_iterable(_24, 0, "phalcon/Mvc/Router.zep", 2383);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_24), _27, _28, _26)
	{
		ZEPHIR_INIT_NVAR(&method);
		if (_28 != NULL) { 
			ZVAL_STR_COPY(&method, _28);
		} else {
			ZVAL_LONG(&method, _27);
		}
		ZEPHIR_INIT_NVAR(&methodSpecific);
		ZVAL_COPY(&methodSpecific, _26);
		if (ZEPHIR_IS_STRING(&method, "*")) {
			zephir_array_update_string(&candidatesByMethod, SL("*"), &starRoutes, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&positionsByMethod, SL("*"), &starPositions, PH_COPY | PH_SEPARATE);
			continue;
		}
		ZEPHIR_INIT_NVAR(&bucket);
		array_init(&bucket);
		ZEPHIR_INIT_NVAR(&positions);
		array_init(&positions);
		zephir_read_property_cached(&_29$$24, this_ptr, _zephir_prop_0, 287, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_29$$24) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_31$$24);
			zephir_string_to_char_array(&_31$$24, &_29$$24);
			_30$$24 = &_31$$24;
		} else {
			_30$$24 = &_29$$24;
		}
		zephir_is_iterable(_30$$24, 0, "phalcon/Mvc/Router.zep", 2372);
		if (Z_TYPE_P(_30$$24) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_30$$24), _33$$24, _34$$24, _32$$24)
			{
				ZEPHIR_INIT_NVAR(&routeIndex);
				if (_34$$24 != NULL) { 
					ZVAL_STR_COPY(&routeIndex, _34$$24);
				} else {
					ZVAL_LONG(&routeIndex, _33$$24);
				}
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _32$$24);
				ZEPHIR_OBS_NVAR(&methods);
				if (!(zephir_array_isset_fetch(&methods, &routeMethods, &routeIndex, 0))) {
					ZEPHIR_INIT_NVAR(&methods);
					ZVAL_NULL(&methods);
				}
				if (Z_TYPE_P(&methods) == IS_NULL) {
					zephir_array_append(&bucket, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2359);
					zephir_array_append(&positions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2360);
				} else if (Z_TYPE_P(&methods) == IS_STRING) {
					if (ZEPHIR_IS_IDENTICAL(&methods, &method)) {
						zephir_array_append(&bucket, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2363);
						zephir_array_append(&positions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2364);
					}
				} else if (zephir_fast_in_array(&method, &methods)) {
					zephir_array_append(&bucket, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2367);
					zephir_array_append(&positions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2368);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _30$$24, "rewind", NULL, 0);
			zephir_check_call_status();
			_36$$24 = 1;
			while (1) {
				if (_36$$24) {
					_36$$24 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _30$$24, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_35$$24, _30$$24, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_35$$24)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&routeIndex, _30$$24, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&route, _30$$24, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&methods);
					if (!(zephir_array_isset_fetch(&methods, &routeMethods, &routeIndex, 0))) {
						ZEPHIR_INIT_NVAR(&methods);
						ZVAL_NULL(&methods);
					}
					if (Z_TYPE_P(&methods) == IS_NULL) {
						zephir_array_append(&bucket, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2359);
						zephir_array_append(&positions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2360);
					} else if (Z_TYPE_P(&methods) == IS_STRING) {
						if (ZEPHIR_IS_IDENTICAL(&methods, &method)) {
							zephir_array_append(&bucket, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2363);
							zephir_array_append(&positions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2364);
						}
					} else if (zephir_fast_in_array(&method, &methods)) {
						zephir_array_append(&bucket, &route, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2367);
						zephir_array_append(&positions, &routeIndex, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2368);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&route);
		ZEPHIR_INIT_NVAR(&routeIndex);
		zephir_array_update_zval(&candidatesByMethod, &method, &bucket, PH_COPY | PH_SEPARATE);
		zephir_array_update_zval(&positionsByMethod, &method, &positions, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&methodSpecific);
	ZEPHIR_INIT_NVAR(&method);
	if (Z_TYPE_P(&candidatesByMethod) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_38);
		zephir_string_to_char_array(&_38, &candidatesByMethod);
		_37 = &_38;
	} else {
		_37 = &candidatesByMethod;
	}
	zephir_is_iterable(_37, 0, "phalcon/Mvc/Router.zep", 2431);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_37), _40, _41, _39)
	{
		ZEPHIR_INIT_NVAR(&method);
		if (_41 != NULL) { 
			ZVAL_STR_COPY(&method, _41);
		} else {
			ZVAL_LONG(&method, _40);
		}
		ZEPHIR_INIT_NVAR(&candidates);
		ZVAL_COPY(&candidates, _39);
		ZEPHIR_OBS_NVAR(&positions);
		zephir_array_fetch(&positions, &positionsByMethod, &method, PH_NOISY, "phalcon/Mvc/Router.zep", 2384);
		if (Z_TYPE_P(&candidates) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_43$$38);
			zephir_string_to_char_array(&_43$$38, &candidates);
			_42$$38 = &_43$$38;
		} else {
			_42$$38 = &candidates;
		}
		zephir_is_iterable(_42$$38, 0, "phalcon/Mvc/Router.zep", 2424);
		if (Z_TYPE_P(_42$$38) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_42$$38), _45$$38, _46$$38, _44$$38)
			{
				ZEPHIR_INIT_NVAR(&bucketIdx);
				if (_46$$38 != NULL) { 
					ZVAL_STR_COPY(&bucketIdx, _46$$38);
				} else {
					ZVAL_LONG(&bucketIdx, _45$$38);
				}
				ZEPHIR_INIT_NVAR(&bucketRoute);
				ZVAL_COPY(&bucketRoute, _44$$38);
				ZEPHIR_OBS_NVAR(&routeIndex);
				zephir_array_fetch(&routeIndex, &positions, &bucketIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 2387);
				ZEPHIR_OBS_NVAR(&bucketPattern);
				zephir_array_fetch(&bucketPattern, &routePatterns, &routeIndex, PH_NOISY, "phalcon/Mvc/Router.zep", 2388);
				if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2390))) {
					zephir_array_update_multi(&staticByMethod, &bucketRoute, SL("zza"), 3, &method, &bucketPattern);
					zephir_array_fetch(&_47$$40, &staticShadowedByMethod, &method, PH_READONLY, "phalcon/Mvc/Router.zep", 2401);
					_48$$40 = zephir_array_isset_value(&_47$$40, &bucketPattern);
					if (_48$$40) {
						zephir_array_fetch(&_49$$40, &routeHosts, &routeIndex, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2402);
						_48$$40 = Z_TYPE_P(&_49$$40) == IS_NULL;
					}
					_50$$40 = _48$$40;
					if (_50$$40) {
						ZEPHIR_CALL_METHOD(&_52$$40, &bucketRoute, "getRouteId", NULL, 0);
						zephir_check_call_status();
						zephir_array_fetch(&_51$$40, &routeMeta, &_52$$40, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2403);
						ZEPHIR_OBS_NVAR(&_53$$40);
						zephir_array_fetch_string(&_53$$40, &_51$$40, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 2403);
						_50$$40 = Z_TYPE_P(&_53$$40) == IS_NULL;
					}
					if (_50$$40) {
						ZEPHIR_OBS_NVAR(&shadowBucket);
						zephir_array_fetch(&shadowBucket, &staticShadowedByMethod, &method, PH_NOISY, "phalcon/Mvc/Router.zep", 2408);
						zephir_array_unset(&shadowBucket, &bucketPattern, PH_SEPARATE);
						zephir_array_update_zval(&staticShadowedByMethod, &method, &shadowBucket, PH_COPY | PH_SEPARATE);
					}
				} else {
					ZEPHIR_OBS_NVAR(&staticBucket);
					if (zephir_array_isset_fetch(&staticBucket, &staticByMethod, &method, 0)) {
						if (Z_TYPE_P(&staticBucket) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_55$$43);
							zephir_string_to_char_array(&_55$$43, &staticBucket);
							_54$$43 = &_55$$43;
						} else {
							_54$$43 = &staticBucket;
						}
						zephir_is_iterable(_54$$43, 0, "phalcon/Mvc/Router.zep", 2421);
						if (Z_TYPE_P(_54$$43) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_54$$43), _57$$43, _58$$43, _56$$43)
							{
								ZEPHIR_INIT_NVAR(&staticUri);
								if (_58$$43 != NULL) { 
									ZVAL_STR_COPY(&staticUri, _58$$43);
								} else {
									ZVAL_LONG(&staticUri, _57$$43);
								}
								ZEPHIR_INIT_NVAR(&staticRoutesList);
								ZVAL_COPY(&staticRoutesList, _56$$43);
								ZEPHIR_INIT_NVAR(&_59$$44);
								ZEPHIR_INIT_NVAR(&_60$$44);
								zephir_preg_match(&_60$$44, &bucketPattern, &staticUri, &_59$$44, 0, 0 , 0 );
								if (zephir_is_true(&_60$$44)) {
									zephir_array_update_multi(&staticShadowedByMethod, &__$true, SL("zz"), 2, &method, &staticUri);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _54$$43, "rewind", NULL, 0);
							zephir_check_call_status();
							_62$$43 = 1;
							while (1) {
								if (_62$$43) {
									_62$$43 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _54$$43, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_61$$43, _54$$43, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_61$$43)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&staticUri, _54$$43, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&staticRoutesList, _54$$43, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_63$$46);
									ZEPHIR_INIT_NVAR(&_64$$46);
									zephir_preg_match(&_64$$46, &bucketPattern, &staticUri, &_63$$46, 0, 0 , 0 );
									if (zephir_is_true(&_64$$46)) {
										zephir_array_update_multi(&staticShadowedByMethod, &__$true, SL("zz"), 2, &method, &staticUri);
									}
							}
						}
						ZEPHIR_INIT_NVAR(&staticRoutesList);
						ZEPHIR_INIT_NVAR(&staticUri);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _42$$38, "rewind", NULL, 0);
			zephir_check_call_status();
			_66$$38 = 1;
			while (1) {
				if (_66$$38) {
					_66$$38 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _42$$38, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_65$$38, _42$$38, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_65$$38)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&bucketIdx, _42$$38, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&bucketRoute, _42$$38, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&routeIndex);
					zephir_array_fetch(&routeIndex, &positions, &bucketIdx, PH_NOISY, "phalcon/Mvc/Router.zep", 2387);
					ZEPHIR_OBS_NVAR(&bucketPattern);
					zephir_array_fetch(&bucketPattern, &routePatterns, &routeIndex, PH_NOISY, "phalcon/Mvc/Router.zep", 2388);
					if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2390))) {
						zephir_array_update_multi(&staticByMethod, &bucketRoute, SL("zza"), 3, &method, &bucketPattern);
						zephir_array_fetch(&_67$$49, &staticShadowedByMethod, &method, PH_READONLY, "phalcon/Mvc/Router.zep", 2401);
						_68$$49 = zephir_array_isset_value(&_67$$49, &bucketPattern);
						if (_68$$49) {
							zephir_array_fetch(&_69$$49, &routeHosts, &routeIndex, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2402);
							_68$$49 = Z_TYPE_P(&_69$$49) == IS_NULL;
						}
						_70$$49 = _68$$49;
						if (_70$$49) {
							ZEPHIR_CALL_METHOD(&_72$$49, &bucketRoute, "getRouteId", NULL, 0);
							zephir_check_call_status();
							zephir_array_fetch(&_71$$49, &routeMeta, &_72$$49, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router.zep", 2403);
							ZEPHIR_OBS_NVAR(&_73$$49);
							zephir_array_fetch_string(&_73$$49, &_71$$49, SL("beforeMatch"), PH_NOISY, "phalcon/Mvc/Router.zep", 2403);
							_70$$49 = Z_TYPE_P(&_73$$49) == IS_NULL;
						}
						if (_70$$49) {
							ZEPHIR_OBS_NVAR(&shadowBucket);
							zephir_array_fetch(&shadowBucket, &staticShadowedByMethod, &method, PH_NOISY, "phalcon/Mvc/Router.zep", 2408);
							zephir_array_unset(&shadowBucket, &bucketPattern, PH_SEPARATE);
							zephir_array_update_zval(&staticShadowedByMethod, &method, &shadowBucket, PH_COPY | PH_SEPARATE);
						}
					} else {
						ZEPHIR_OBS_NVAR(&staticBucket);
						if (zephir_array_isset_fetch(&staticBucket, &staticByMethod, &method, 0)) {
							if (Z_TYPE_P(&staticBucket) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_75$$52);
								zephir_string_to_char_array(&_75$$52, &staticBucket);
								_74$$52 = &_75$$52;
							} else {
								_74$$52 = &staticBucket;
							}
							zephir_is_iterable(_74$$52, 0, "phalcon/Mvc/Router.zep", 2421);
							if (Z_TYPE_P(_74$$52) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_74$$52), _77$$52, _78$$52, _76$$52)
								{
									ZEPHIR_INIT_NVAR(&staticUri);
									if (_78$$52 != NULL) { 
										ZVAL_STR_COPY(&staticUri, _78$$52);
									} else {
										ZVAL_LONG(&staticUri, _77$$52);
									}
									ZEPHIR_INIT_NVAR(&staticRoutesList);
									ZVAL_COPY(&staticRoutesList, _76$$52);
									ZEPHIR_INIT_NVAR(&_79$$53);
									ZEPHIR_INIT_NVAR(&_80$$53);
									zephir_preg_match(&_80$$53, &bucketPattern, &staticUri, &_79$$53, 0, 0 , 0 );
									if (zephir_is_true(&_80$$53)) {
										zephir_array_update_multi(&staticShadowedByMethod, &__$true, SL("zz"), 2, &method, &staticUri);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _74$$52, "rewind", NULL, 0);
								zephir_check_call_status();
								_82$$52 = 1;
								while (1) {
									if (_82$$52) {
										_82$$52 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _74$$52, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_81$$52, _74$$52, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_81$$52)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&staticUri, _74$$52, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&staticRoutesList, _74$$52, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_83$$55);
										ZEPHIR_INIT_NVAR(&_84$$55);
										zephir_preg_match(&_84$$55, &bucketPattern, &staticUri, &_83$$55, 0, 0 , 0 );
										if (zephir_is_true(&_84$$55)) {
											zephir_array_update_multi(&staticShadowedByMethod, &__$true, SL("zz"), 2, &method, &staticUri);
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
		ZEPHIR_INIT_VAR(&_86);
		zephir_string_to_char_array(&_86, &positionsByMethod);
		_85 = &_86;
	} else {
		_85 = &positionsByMethod;
	}
	zephir_is_iterable(_85, 0, "phalcon/Mvc/Router.zep", 2458);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_85), _88, _89, _87)
	{
		ZEPHIR_INIT_NVAR(&method);
		if (_89 != NULL) { 
			ZVAL_STR_COPY(&method, _89);
		} else {
			ZVAL_LONG(&method, _88);
		}
		ZEPHIR_INIT_NVAR(&positions);
		ZVAL_COPY(&positions, _87);
		ZEPHIR_INIT_NVAR(&_90$$57);
		array_init(&_90$$57);
		zephir_array_update_zval(&hostnameByMethod, &method, &_90$$57, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_91$$57);
		array_init(&_91$$57);
		zephir_array_update_zval(&hostnameLessByMethod, &method, &_91$$57, PH_COPY | PH_SEPARATE);
		if (Z_TYPE_P(&positions) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_93$$57);
			zephir_string_to_char_array(&_93$$57, &positions);
			_92$$57 = &_93$$57;
		} else {
			_92$$57 = &positions;
		}
		zephir_is_iterable(_92$$57, 0, "phalcon/Mvc/Router.zep", 2449);
		if (Z_TYPE_P(_92$$57) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_92$$57), _95$$57, _96$$57, _94$$57)
			{
				ZEPHIR_INIT_NVAR(&bucketIdx);
				if (_96$$57 != NULL) { 
					ZVAL_STR_COPY(&bucketIdx, _96$$57);
				} else {
					ZVAL_LONG(&bucketIdx, _95$$57);
				}
				ZEPHIR_INIT_NVAR(&routeIndex);
				ZVAL_COPY(&routeIndex, _94$$57);
				ZEPHIR_OBS_NVAR(&bucketHostname);
				zephir_array_fetch(&bucketHostname, &routeHosts, &routeIndex, PH_NOISY, "phalcon/Mvc/Router.zep", 2441);
				if (Z_TYPE_P(&bucketHostname) == IS_NULL) {
					zephir_array_update_multi(&hostnameLessByMethod, &bucketIdx, SL("za"), 2, &method);
				} else {
					zephir_array_update_multi(&hostnameByMethod, &bucketIdx, SL("zza"), 3, &method, &bucketHostname);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _92$$57, "rewind", NULL, 0);
			zephir_check_call_status();
			_98$$57 = 1;
			while (1) {
				if (_98$$57) {
					_98$$57 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _92$$57, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_97$$57, _92$$57, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_97$$57)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&bucketIdx, _92$$57, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&routeIndex, _92$$57, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&bucketHostname);
					zephir_array_fetch(&bucketHostname, &routeHosts, &routeIndex, PH_NOISY, "phalcon/Mvc/Router.zep", 2441);
					if (Z_TYPE_P(&bucketHostname) == IS_NULL) {
						zephir_array_update_multi(&hostnameLessByMethod, &bucketIdx, SL("za"), 2, &method);
					} else {
						zephir_array_update_multi(&hostnameByMethod, &bucketIdx, SL("zza"), 3, &method, &bucketHostname);
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
		ZEPHIR_INIT_VAR(&_100);
		zephir_string_to_char_array(&_100, &positionsByMethod);
		_99 = &_100;
	} else {
		_99 = &positionsByMethod;
	}
	zephir_is_iterable(_99, 0, "phalcon/Mvc/Router.zep", 2589);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_99), _102, _103, _101)
	{
		ZEPHIR_INIT_NVAR(&method);
		if (_103 != NULL) { 
			ZVAL_STR_COPY(&method, _103);
		} else {
			ZVAL_LONG(&method, _102);
		}
		ZEPHIR_INIT_NVAR(&positions);
		ZVAL_COPY(&positions, _101);
		ZEPHIR_OBS_NVAR(&hostnameBucketRef);
		zephir_array_fetch(&hostnameBucketRef, &hostnameByMethod, &method, PH_NOISY, "phalcon/Mvc/Router.zep", 2466);
		if (!(ZEPHIR_IS_EMPTY(&hostnameBucketRef))) {
			zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
			continue;
		}
		ZEPHIR_INIT_NVAR(&combinedAlternatives);
		array_init(&combinedAlternatives);
		ZEPHIR_INIT_NVAR(&combinedMark);
		array_init(&combinedMark);
		if (Z_TYPE_P(&positions) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_105$$64);
			zephir_string_to_char_array(&_105$$64, &positions);
			_104$$64 = &_105$$64;
		} else {
			_104$$64 = &positions;
		}
		zephir_is_iterable(_104$$64, 0, "phalcon/Mvc/Router.zep", 2526);
		if (Z_TYPE_P(_104$$64) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_104$$64), _107$$64, _108$$64, _106$$64)
			{
				ZEPHIR_INIT_NVAR(&bucketIdx);
				if (_108$$64 != NULL) { 
					ZVAL_STR_COPY(&bucketIdx, _108$$64);
				} else {
					ZVAL_LONG(&bucketIdx, _107$$64);
				}
				ZEPHIR_INIT_NVAR(&routeIndex);
				ZVAL_COPY(&routeIndex, _106$$64);
				ZEPHIR_OBS_NVAR(&bucketPattern);
				zephir_array_fetch(&bucketPattern, &routePatterns, &routeIndex, PH_NOISY, "phalcon/Mvc/Router.zep", 2477);
				if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2479))) {
					continue;
				}
				_109$$66 = !(zephir_start_with_str(&bucketPattern, SL("#^")));
				if (!(_109$$66)) {
					_109$$66 = !(zephir_end_with_str(&bucketPattern, SL("$#u")));
				}
				if (_109$$66) {
					zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&combinedAlternatives);
					array_init(&combinedAlternatives);
					break;
				}
				ZVAL_LONG(&_110$$66, 2);
				ZVAL_LONG(&_111$$66, -3);
				ZEPHIR_INIT_NVAR(&combinedBody);
				zephir_substr(&combinedBody, &bucketPattern, 2 , -3 , 0);
				_112$$66 = ZEPHIR_IS_STRING_IDENTICAL(&combinedBody, "");
				if (!(_112$$66)) {
					_112$$66 = zephir_memnstr_str(&combinedBody, SL("\n"), "phalcon/Mvc/Router.zep", 2505);
				}
				_113$$66 = _112$$66;
				if (!(_113$$66)) {
					_114$$66 = zephir_memnstr_str(&combinedBody, SL("(?"), "phalcon/Mvc/Router.zep", 2505);
					if (_114$$66) {
						ZEPHIR_INIT_NVAR(&_115$$66);
						ZEPHIR_INIT_NVAR(&_116$$66);
						ZVAL_STRING(&_116$$66, "/\\(\\?(?:P?<[^=!]|')/");
						ZEPHIR_INIT_NVAR(&_117$$66);
						ZEPHIR_INIT_NVAR(&_118$$66);
						ZVAL_STRING(&_118$$66, "/\\(\\?(?:P?<[^=!]|')/");
						zephir_preg_match(&_117$$66, &_118$$66, &combinedBody, &_115$$66, 0, 0 , 0 );
						_114$$66 = zephir_is_true(&_117$$66);
					}
					_113$$66 = _114$$66;
				}
				if (_113$$66) {
					zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&combinedAlternatives);
					array_init(&combinedAlternatives);
					break;
				}
				_119$$66 = zephir_memnstr_str(&combinedBody, SL("|"), "phalcon/Mvc/Router.zep", 2516);
				if (_119$$66) {
					ZEPHIR_CALL_METHOD(&_120$$66, this_ptr, "hasTopLevelAlternation", &_121, 282, &combinedBody);
					zephir_check_call_status();
					_119$$66 = zephir_is_true(&_120$$66);
				}
				if (_119$$66) {
					zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&combinedAlternatives);
					array_init(&combinedAlternatives);
					break;
				}
				ZEPHIR_INIT_NVAR(&_122$$66);
				ZEPHIR_CONCAT_VSVS(&_122$$66, &combinedBody, "(*:", &bucketIdx, ")");
				zephir_array_append(&combinedAlternatives, &_122$$66, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2522);
				zephir_cast_to_string(&_123$$66, &bucketIdx);
				zephir_array_update_zval(&combinedMark, &_123$$66, &bucketIdx, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _104$$64, "rewind", NULL, 0);
			zephir_check_call_status();
			_125$$64 = 1;
			while (1) {
				if (_125$$64) {
					_125$$64 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _104$$64, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_124$$64, _104$$64, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_124$$64)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&bucketIdx, _104$$64, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&routeIndex, _104$$64, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&bucketPattern);
					zephir_array_fetch(&bucketPattern, &routePatterns, &routeIndex, PH_NOISY, "phalcon/Mvc/Router.zep", 2477);
					if (!(zephir_memnstr_str(&bucketPattern, SL("^"), "phalcon/Mvc/Router.zep", 2479))) {
						continue;
					}
					_126$$71 = !(zephir_start_with_str(&bucketPattern, SL("#^")));
					if (!(_126$$71)) {
						_126$$71 = !(zephir_end_with_str(&bucketPattern, SL("$#u")));
					}
					if (_126$$71) {
						zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&combinedAlternatives);
						array_init(&combinedAlternatives);
						break;
					}
					ZVAL_LONG(&_127$$71, 2);
					ZVAL_LONG(&_128$$71, -3);
					ZEPHIR_INIT_NVAR(&combinedBody);
					zephir_substr(&combinedBody, &bucketPattern, 2 , -3 , 0);
					_129$$71 = ZEPHIR_IS_STRING_IDENTICAL(&combinedBody, "");
					if (!(_129$$71)) {
						_129$$71 = zephir_memnstr_str(&combinedBody, SL("\n"), "phalcon/Mvc/Router.zep", 2505);
					}
					_130$$71 = _129$$71;
					if (!(_130$$71)) {
						_131$$71 = zephir_memnstr_str(&combinedBody, SL("(?"), "phalcon/Mvc/Router.zep", 2505);
						if (_131$$71) {
							ZEPHIR_INIT_NVAR(&_132$$71);
							ZEPHIR_INIT_NVAR(&_133$$71);
							ZVAL_STRING(&_133$$71, "/\\(\\?(?:P?<[^=!]|')/");
							ZEPHIR_INIT_NVAR(&_134$$71);
							ZEPHIR_INIT_NVAR(&_135$$71);
							ZVAL_STRING(&_135$$71, "/\\(\\?(?:P?<[^=!]|')/");
							zephir_preg_match(&_134$$71, &_135$$71, &combinedBody, &_132$$71, 0, 0 , 0 );
							_131$$71 = zephir_is_true(&_134$$71);
						}
						_130$$71 = _131$$71;
					}
					if (_130$$71) {
						zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&combinedAlternatives);
						array_init(&combinedAlternatives);
						break;
					}
					_136$$71 = zephir_memnstr_str(&combinedBody, SL("|"), "phalcon/Mvc/Router.zep", 2516);
					if (_136$$71) {
						ZEPHIR_CALL_METHOD(&_137$$71, this_ptr, "hasTopLevelAlternation", &_121, 282, &combinedBody);
						zephir_check_call_status();
						_136$$71 = zephir_is_true(&_137$$71);
					}
					if (_136$$71) {
						zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&combinedAlternatives);
						array_init(&combinedAlternatives);
						break;
					}
					ZEPHIR_INIT_NVAR(&_138$$71);
					ZEPHIR_CONCAT_VSVS(&_138$$71, &combinedBody, "(*:", &bucketIdx, ")");
					zephir_array_append(&combinedAlternatives, &_138$$71, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2522);
					zephir_cast_to_string(&_139$$71, &bucketIdx);
					zephir_array_update_zval(&combinedMark, &_139$$71, &bucketIdx, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_NVAR(&routeIndex);
		ZEPHIR_INIT_NVAR(&bucketIdx);
		if (zephir_array_isset_value(&combinedRegexDisabled, &method)) {
			continue;
		}
		if (ZEPHIR_IS_EMPTY(&combinedAlternatives)) {
			continue;
		}
		ZEPHIR_CALL_FUNCTION(&_140$$64, "array_reverse", &_141, 273, &combinedAlternatives);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&combinedAlternatives, &_140$$64);
		ZEPHIR_INIT_NVAR(&_142$$64);
		zephir_array_keys(&_142$$64, &combinedMark);
		ZEPHIR_CALL_FUNCTION(&reversedMarkIds$$64, "array_reverse", &_141, 273, &_142$$64);
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
			ZVAL_LONG(&_143$$78, 10);
			ZEPHIR_CALL_FUNCTION(&chunkSlice$$64, "array_slice", &_144, 283, &combinedAlternatives, &chunkOffset$$64, &_143$$78);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&chunkSlice$$64, &chunkSlice$$64);
			ZVAL_LONG(&_143$$78, 10);
			ZEPHIR_CALL_FUNCTION(&chunkMarkSubset$$64, "array_slice", &_144, 283, &reversedMarkIds$$64, &chunkOffset$$64, &_143$$78);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&chunkMarkSubset$$64, &chunkMarkSubset$$64);
			ZEPHIR_INIT_NVAR(&chunkSliceMap$$64);
			array_init(&chunkSliceMap$$64);
			ZEPHIR_CPY_WRT(&chunkSliceMap$$64, &chunkSliceMap$$64);
			if (Z_TYPE_P(&chunkMarkSubset$$64) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_146$$78);
				zephir_string_to_char_array(&_146$$78, &chunkMarkSubset$$64);
				_145$$78 = &_146$$78;
			} else {
				_145$$78 = &chunkMarkSubset$$64;
			}
			zephir_is_iterable(_145$$78, 0, "phalcon/Mvc/Router.zep", 2561);
			if (Z_TYPE_P(_145$$78) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_145$$78), _147$$78)
				{
					ZEPHIR_INIT_NVAR(&chunkMarkId$$64);
					ZVAL_COPY(&chunkMarkId$$64, _147$$78);
					ZEPHIR_OBS_NVAR(&_148$$79);
					zephir_array_fetch(&_148$$79, &combinedMark, &chunkMarkId$$64, PH_NOISY, "phalcon/Mvc/Router.zep", 2558);
					zephir_array_update_zval(&chunkSliceMap$$64, &chunkMarkId$$64, &_148$$79, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _145$$78, "rewind", NULL, 0);
				zephir_check_call_status();
				_150$$78 = 1;
				while (1) {
					if (_150$$78) {
						_150$$78 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _145$$78, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_149$$78, _145$$78, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_149$$78)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&chunkMarkId$$64, _145$$78, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&_151$$80);
						zephir_array_fetch(&_151$$80, &combinedMark, &chunkMarkId$$64, PH_NOISY, "phalcon/Mvc/Router.zep", 2558);
						zephir_array_update_zval(&chunkSliceMap$$64, &chunkMarkId$$64, &_151$$80, PH_COPY | PH_SEPARATE);
				}
			}
			ZEPHIR_INIT_NVAR(&chunkMarkId$$64);
			ZEPHIR_INIT_NVAR(&_152$$78);
			zephir_fast_join_str(&_152$$78, SL("|"), &chunkSlice$$64);
			ZEPHIR_INIT_NVAR(&chunkPattern$$64);
			ZEPHIR_CONCAT_SVS(&chunkPattern$$64, "#^(?|", &_152$$78, ")$#u");
			ZEPHIR_CPY_WRT(&chunkPattern$$64, &chunkPattern$$64);
			ZEPHIR_INIT_NVAR(&_153$$78);
			ZEPHIR_INIT_NVAR(&_154$$78);
			ZVAL_STRING(&_154$$78, "");
			ZEPHIR_INIT_NVAR(&_155$$78);
			ZEPHIR_INIT_NVAR(&_156$$78);
			ZVAL_STRING(&_156$$78, "");
			zephir_preg_match(&_155$$78, &chunkPattern$$64, &_156$$78, &_153$$78, 0, 0 , 0 );
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_155$$78)) {
				zephir_array_update_zval(&combinedRegexDisabled, &method, &__$true, PH_COPY | PH_SEPARATE);
				break;
			}
			zephir_array_append(&chunkedPatterns$$64, &chunkPattern$$64, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2576);
			zephir_array_append(&chunkedMarkMaps$$64, &chunkSliceMap$$64, PH_SEPARATE, "phalcon/Mvc/Router.zep", 2577);
			ZEPHIR_INIT_NVAR(&_157$$78);
			ZVAL_LONG(&_157$$78, 10);
			ZEPHIR_ADD_ASSIGN(&chunkOffset$$64, &_157$$78);
		}
		if (zephir_array_isset_value(&combinedRegexDisabled, &method)) {
			continue;
		}
		zephir_array_update_zval(&combinedRegexByMethod, &method, &chunkedPatterns$$64, PH_COPY | PH_SEPARATE);
		zephir_array_update_zval(&combinedRegexMarkMap, &method, &chunkedMarkMaps$$64, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&positions);
	ZEPHIR_INIT_NVAR(&method);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 289, &methodRoutes);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 290, &candidatesByMethod);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 298, &routeMeta);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 291, &staticByMethod);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 292, &staticShadowedByMethod);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 293, &hostnameByMethod);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 294, &hostnameLessByMethod);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 295, &combinedRegexByMethod);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 297, &combinedRegexMarkMap);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 296, &combinedRegexDisabled);
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 288, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 288, &__$false);
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
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 162, stream, &_0, &separator_zv, enclosure, escape);
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
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 163, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_2, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 163, &filename_zv, &_2, context, &_3, &_4);
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
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 164, &filename_zv, data, &_0, context);
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
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 165, &filename_zv, &mode_zv, &_0, context);
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
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 166, handle, &data_zv, &_0);
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
	ZEPHIR_RETURN_CALL_FUNCTION("is_dir", NULL, 167, &filename_zv);
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
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 168, &filename_zv);
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
	ZEPHIR_RETURN_CALL_FUNCTION("mkdir", NULL, 169, &directory_zv, &_0, &_1, context);
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
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 170, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

