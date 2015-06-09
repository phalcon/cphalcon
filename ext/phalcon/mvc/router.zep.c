
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
#include "kernel/hash.h"
#include "kernel/concat.h"


/**
 * Phalcon\Mvc\Router
 *
 * <p>Phalcon\Mvc\Router is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request</p>
 *
 *<code>
 *
 *	$router = new Router();
 *
 *	$router->add(
 *		"/documentation/{chapter}/{name}.{type:[a-z]+}",
 *		array(
 *			"controller" => "documentation",
 *			"action"     => "show"
 *		)
 *	);
 *
 *	$router->handle();
 *
 *	echo $router->getControllerName();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, Router, phalcon, mvc_router, phalcon_mvc_router_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_uriSource"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_namespace"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_controller"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_routes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_matchedRoute"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_matches"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_router_ce, SL("_wasMatched"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultNamespace"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultController"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultAction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_removeExtraSlashes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_notFoundPaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_router_ce, SL("URI_SOURCE_GET_URL"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_router_ce, SL("URI_SOURCE_SERVER_REQUEST_URI"), 1 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_router_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_router_ce TSRMLS_CC, 1, phalcon_mvc_routerinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Router constructor
 */
PHP_METHOD(Phalcon_Mvc_Router, __construct) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *routes, *_1, *_4;
	zval *defaultRoutes_param = NULL, *_0 = NULL, *_2 = NULL, *_5;
	zend_bool defaultRoutes;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultRoutes_param);

	if (!defaultRoutes_param) {
		defaultRoutes = 1;
	} else {
	if (unlikely(Z_TYPE_P(defaultRoutes_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'defaultRoutes' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	defaultRoutes = Z_BVAL_P(defaultRoutes_param);
	}
	ZEPHIR_INIT_VAR(routes);
	array_init(routes);


	if (defaultRoutes) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(_1);
		zephir_create_array(_1, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(_1, SS("controller"), 1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "#^/([a-zA-Z0-9\\_\\-]+)[/]{0,1}$#", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_3, 354, _2, _1);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_append(&routes, _0, PH_SEPARATE, "phalcon/mvc/router.zep", 111);
		ZEPHIR_INIT_NVAR(_2);
		object_init_ex(_2, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(_4);
		zephir_create_array(_4, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(_4, SS("controller"), 1);
		add_assoc_long_ex(_4, SS("action"), 2);
		add_assoc_long_ex(_4, SS("params"), 3);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "#^/([a-zA-Z0-9\\_\\-]+)/([a-zA-Z0-9\\.\\_]+)(/.*)*$#", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_3, 354, _5, _4);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		zephir_array_append(&routes, _2, PH_SEPARATE, "phalcon/mvc/router.zep", 117);
	}
	ZEPHIR_INIT_NVAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_params"), _0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("_defaultParams"), _2 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_routes"), routes TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Mvc_Router, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Mvc_Router, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Get rewrite info. This info is read from $_GET['_url']. This returns '/' if the rewrite information cannot be read
 */
PHP_METHOD(Phalcon_Mvc_Router, getRewriteUri) {

	zval *url = NULL, *urlParts, *realUri, *_0, *_GET, *_SERVER;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_uriSource"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_OBS_VAR(url);
		if (zephir_array_isset_string_fetch(&url, _GET, SS("_url"), 0 TSRMLS_CC)) {
			if (!(ZEPHIR_IS_EMPTY(url))) {
				RETURN_CCTOR(url);
			}
		}
	} else {
		ZEPHIR_OBS_NVAR(url);
		if (zephir_array_isset_string_fetch(&url, _SERVER, SS("REQUEST_URI"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(urlParts);
			zephir_fast_explode_str(urlParts, SL("?"), url, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&realUri, urlParts, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/router.zep", 163 TSRMLS_CC);
			if (!(ZEPHIR_IS_EMPTY(realUri))) {
				RETURN_CTOR(realUri);
			}
		}
	}
	RETURN_MM_STRING("/", 1);

}

/**
 * Sets the URI source. One of the URI_SOURCE_* constants
 *
 *<code>
 *	$router->setUriSource(Router::URI_SOURCE_SERVER_REQUEST_URI);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, setUriSource) {

	zval *uriSource;

	zephir_fetch_params(0, 1, 0, &uriSource);



	zephir_update_property_this(this_ptr, SL("_uriSource"), uriSource TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Set whether router must remove the extra slashes in the handled routes
 */
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes) {

	zval *remove_param = NULL;
	zend_bool remove;

	zephir_fetch_params(0, 1, 0, &remove_param);

	if (unlikely(Z_TYPE_P(remove_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'remove' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}

	remove = Z_BVAL_P(remove_param);


	zephir_update_property_this(this_ptr, SL("_removeExtraSlashes"), remove ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets the name of the default namespace
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace) {

	zval *namespaceName_param = NULL;
	zval *namespaceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);

	if (unlikely(Z_TYPE_P(namespaceName_param) != IS_STRING && Z_TYPE_P(namespaceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'namespaceName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(namespaceName_param) == IS_STRING)) {
		zephir_get_strval(namespaceName, namespaceName_param);
	} else {
		ZEPHIR_INIT_VAR(namespaceName);
		ZVAL_EMPTY_STRING(namespaceName);
	}


	zephir_update_property_this(this_ptr, SL("_defaultNamespace"), namespaceName TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the name of the default module
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule) {

	zval *moduleName_param = NULL;
	zval *moduleName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	if (unlikely(Z_TYPE_P(moduleName_param) != IS_STRING && Z_TYPE_P(moduleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(moduleName_param) == IS_STRING)) {
		zephir_get_strval(moduleName, moduleName_param);
	} else {
		ZEPHIR_INIT_VAR(moduleName);
		ZVAL_EMPTY_STRING(moduleName);
	}


	zephir_update_property_this(this_ptr, SL("_defaultModule"), moduleName TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the default controller name
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultController) {

	zval *controllerName_param = NULL;
	zval *controllerName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerName_param);

	if (unlikely(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(controllerName);
		ZVAL_EMPTY_STRING(controllerName);
	}


	zephir_update_property_this(this_ptr, SL("_defaultController"), controllerName TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the default action name
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction) {

	zval *actionName_param = NULL;
	zval *actionName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

	if (unlikely(Z_TYPE_P(actionName_param) != IS_STRING && Z_TYPE_P(actionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(actionName_param) == IS_STRING)) {
		zephir_get_strval(actionName, actionName_param);
	} else {
		ZEPHIR_INIT_VAR(actionName);
		ZVAL_EMPTY_STRING(actionName);
	}


	zephir_update_property_this(this_ptr, SL("_defaultAction"), actionName TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets an array of default paths. If a route is missing a path the router will use the defined here
 * This method must not be used to set a 404 route
 *
 *<code>
 * $router->setDefaults(array(
 *		'module' => 'common',
 *		'action' => 'index'
 * ));
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaults) {

	zval *defaults_param = NULL, *namespaceName, *module, *controller, *action, *params;
	zval *defaults = NULL;

	zephir_fetch_params(0, 1, 0, &defaults_param);

	defaults = defaults_param;



	if (zephir_array_isset_string_fetch(&namespaceName, defaults, SS("namespace"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultNamespace"), namespaceName TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&module, defaults, SS("module"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultModule"), module TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&controller, defaults, SS("controller"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultController"), controller TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&action, defaults, SS("action"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultAction"), action TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&params, defaults, SS("params"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultParams"), params TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Returns an array of default parameters
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaults) {

	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 5, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("namespace"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("module"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_defaultController"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("controller"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("action"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_defaultParams"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("params"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Handles routing information received from the rewrite engine
 *
 *<code>
 * //Read the info from the rewrite engine
 * $router->handle();
 *
 * //Manually passing an URL
 * $router->handle('/posts/edit/1');
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, handle) {

	zephir_fcall_cache_entry *_17 = NULL;
	zval *_11 = NULL, *_16 = NULL;
	HashTable *_5, *_13;
	HashPosition _4, _12;
	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *realUri = NULL, *request = NULL, *currentHostName = NULL, *routeFound = NULL, *parts = NULL, *params = NULL, *matches, *notFoundPaths, *vnamespace, *module, *controller, *action, *paramsStr, *strParams, *route = NULL, *methods = NULL, *dependencyInjector = NULL, *hostname = NULL, *regexHostName = NULL, *matched = NULL, *pattern = NULL, *handledUri = NULL, *beforeMatch = NULL, *paths = NULL, *converters = NULL, *part = NULL, *position = NULL, *matchPosition = NULL, *converter = NULL, *_0, _2 = zval_used_for_init, *_3, **_6, *_7, *_8 = NULL, *_9 = NULL, *_10 = NULL, **_14, *_15 = NULL, *_18, *_19, *_20, *_21;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	} else {
		zephir_get_strval(uri, uri_param);
	}


	if (!(uri && Z_STRLEN_P(uri))) {
		ZEPHIR_CALL_METHOD(&realUri, this_ptr, "getrewriteuri", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(realUri, uri);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_removeExtraSlashes"), PH_NOISY_CC);
	_1 = zephir_is_true(_0);
	if (_1) {
		_1 = !ZEPHIR_IS_STRING(realUri, "/");
	}
	if (_1) {
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "/", 0);
		ZEPHIR_INIT_VAR(handledUri);
		zephir_fast_trim(handledUri, realUri, &_2, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(handledUri, realUri);
	}
	ZEPHIR_INIT_VAR(request);
	ZVAL_NULL(request);
	ZEPHIR_INIT_VAR(currentHostName);
	ZVAL_NULL(currentHostName);
	ZEPHIR_INIT_VAR(routeFound);
	ZVAL_BOOL(routeFound, 0);
	ZEPHIR_INIT_VAR(parts);
	array_init(parts);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);
	zephir_update_property_this(this_ptr, SL("_wasMatched"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_matchedRoute"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 1, "phalcon/mvc/router.zep", 514);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_backwards_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(route, _6);
		ZEPHIR_CALL_METHOD(&methods, route, "gethttpmethods", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(methods) != IS_NULL) {
			if (Z_TYPE_P(request) == IS_NULL) {
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				ZEPHIR_CPY_WRT(dependencyInjector, _7);
				if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service", "phalcon/mvc/router.zep", 352);
					return;
				}
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_STRING(_9, "request", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_8, dependencyInjector, "getshared", NULL, 0, _9);
				zephir_check_temp_parameter(_9);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(request, _8);
			}
			ZEPHIR_CALL_METHOD(&_8, request, "ismethod", NULL, 0, methods);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&hostname, route, "gethostname", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(hostname) != IS_NULL) {
			if (Z_TYPE_P(request) == IS_NULL) {
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				ZEPHIR_CPY_WRT(dependencyInjector, _7);
				if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service", "phalcon/mvc/router.zep", 379);
					return;
				}
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_STRING(_9, "request", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_8, dependencyInjector, "getshared", NULL, 0, _9);
				zephir_check_temp_parameter(_9);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(request, _8);
			}
			if (Z_TYPE_P(currentHostName) != IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&currentHostName, request, "gethttphost", NULL, 0);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(currentHostName) == IS_NULL) {
				continue;
			}
			if (zephir_memnstr_str(hostname, SL("("), "phalcon/mvc/router.zep", 402)) {
				if (!(zephir_memnstr_str(hostname, SL("#"), "phalcon/mvc/router.zep", 403))) {
					ZEPHIR_INIT_NVAR(regexHostName);
					ZEPHIR_CONCAT_SVS(regexHostName, "#^", hostname, "$#");
				} else {
					ZEPHIR_CPY_WRT(regexHostName, hostname);
				}
				ZEPHIR_INIT_NVAR(_10);
				ZEPHIR_INIT_NVAR(matched);
				zephir_preg_match(matched, regexHostName, currentHostName, _10, 0, 0 , 0  TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(matched);
				ZVAL_BOOL(matched, ZEPHIR_IS_EQUAL(currentHostName, hostname));
			}
			if (!(zephir_is_true(matched))) {
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&pattern, route, "getcompiledpattern", NULL, 0);
		zephir_check_call_status();
		if (zephir_memnstr_str(pattern, SL("^"), "phalcon/mvc/router.zep", 424)) {
			ZEPHIR_INIT_NVAR(routeFound);
			zephir_preg_match(routeFound, pattern, handledUri, matches, 0, 0 , 0  TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(routeFound);
			ZVAL_BOOL(routeFound, ZEPHIR_IS_EQUAL(pattern, handledUri));
		}
		if (zephir_is_true(routeFound)) {
			ZEPHIR_CALL_METHOD(&beforeMatch, route, "getbeforematch", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(beforeMatch) != IS_NULL) {
				if (!(zephir_is_callable(beforeMatch TSRMLS_CC))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/mvc/router.zep", 442);
					return;
				}
				ZEPHIR_INIT_NVAR(_11);
				zephir_create_array(_11, 3, 0 TSRMLS_CC);
				zephir_array_fast_append(_11, handledUri);
				zephir_array_fast_append(_11, route);
				zephir_array_fast_append(_11, this_ptr);
				ZEPHIR_INIT_NVAR(routeFound);
				ZEPHIR_CALL_USER_FUNC_ARRAY(routeFound, beforeMatch, _11);
				zephir_check_call_status();
			}
		}
		if (zephir_is_true(routeFound)) {
			ZEPHIR_CALL_METHOD(&paths, route, "getpaths", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(parts, paths);
			if (Z_TYPE_P(matches) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(&converters, route, "getconverters", NULL, 0);
				zephir_check_call_status();
				zephir_is_iterable(paths, &_13, &_12, 0, 0, "phalcon/mvc/router.zep", 503);
				for (
				  ; zephir_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
				  ; zephir_hash_move_forward_ex(_13, &_12)
				) {
					ZEPHIR_GET_HMKEY(part, _13, _12);
					ZEPHIR_GET_HVALUE(position, _14);
					ZEPHIR_OBS_NVAR(matchPosition);
					if (zephir_array_isset_fetch(&matchPosition, matches, position, 0 TSRMLS_CC)) {
						if (Z_TYPE_P(converters) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(converter);
							if (zephir_array_isset_fetch(&converter, converters, part, 0 TSRMLS_CC)) {
								ZEPHIR_INIT_NVAR(_9);
								ZEPHIR_INIT_NVAR(_11);
								zephir_create_array(_11, 1, 0 TSRMLS_CC);
								zephir_array_fast_append(_11, matchPosition);
								ZEPHIR_CALL_USER_FUNC_ARRAY(_9, converter, _11);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, part, &_9, PH_COPY | PH_SEPARATE);
								continue;
							}
						}
						zephir_array_update_zval(&parts, part, &matchPosition, PH_COPY | PH_SEPARATE);
					} else {
						if (Z_TYPE_P(converters) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(converter);
							if (zephir_array_isset_fetch(&converter, converters, part, 0 TSRMLS_CC)) {
								ZEPHIR_INIT_NVAR(_15);
								ZEPHIR_INIT_NVAR(_16);
								zephir_create_array(_16, 1, 0 TSRMLS_CC);
								zephir_array_fast_append(_16, position);
								ZEPHIR_CALL_USER_FUNC_ARRAY(_15, converter, _16);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, part, &_15, PH_COPY | PH_SEPARATE);
							}
						}
					}
				}
				zephir_update_property_this(this_ptr, SL("_matches"), matches TSRMLS_CC);
			}
			zephir_update_property_this(this_ptr, SL("_matchedRoute"), route TSRMLS_CC);
			break;
		}
	}
	if (zephir_is_true(routeFound)) {
		zephir_update_property_this(this_ptr, SL("_wasMatched"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_wasMatched"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (!(zephir_is_true(routeFound))) {
		ZEPHIR_OBS_VAR(notFoundPaths);
		zephir_read_property_this(&notFoundPaths, this_ptr, SL("_notFoundPaths"), PH_NOISY_CC);
		if (Z_TYPE_P(notFoundPaths) != IS_NULL) {
			ZEPHIR_CALL_CE_STATIC(&parts, phalcon_mvc_router_route_ce, "getroutepaths", &_17, 355, notFoundPaths);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(routeFound);
			ZVAL_BOOL(routeFound, 1);
		}
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("_namespace"), _7 TSRMLS_CC);
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("_module"), _18 TSRMLS_CC);
	_19 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultController"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("_controller"), _19 TSRMLS_CC);
	_20 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("_action"), _20 TSRMLS_CC);
	_21 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultParams"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("_params"), _21 TSRMLS_CC);
	if (zephir_is_true(routeFound)) {
		ZEPHIR_OBS_VAR(vnamespace);
		if (zephir_array_isset_string_fetch(&vnamespace, parts, SS("namespace"), 0 TSRMLS_CC)) {
			if (!(zephir_is_numeric(vnamespace))) {
				zephir_update_property_this(this_ptr, SL("_namespace"), vnamespace TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("namespace"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(module);
		if (zephir_array_isset_string_fetch(&module, parts, SS("module"), 0 TSRMLS_CC)) {
			if (!(zephir_is_numeric(module))) {
				zephir_update_property_this(this_ptr, SL("_module"), module TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("module"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(controller);
		if (zephir_array_isset_string_fetch(&controller, parts, SS("controller"), 0 TSRMLS_CC)) {
			if (!(zephir_is_numeric(controller))) {
				zephir_update_property_this(this_ptr, SL("_controller"), controller TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("controller"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(action);
		if (zephir_array_isset_string_fetch(&action, parts, SS("action"), 0 TSRMLS_CC)) {
			if (!(zephir_is_numeric(action))) {
				zephir_update_property_this(this_ptr, SL("_action"), action TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("action"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(paramsStr);
		if (zephir_array_isset_string_fetch(&paramsStr, parts, SS("params"), 0 TSRMLS_CC)) {
			if (Z_TYPE_P(paramsStr) == IS_STRING) {
				ZEPHIR_SINIT_NVAR(_2);
				ZVAL_STRING(&_2, "/", 0);
				ZEPHIR_INIT_VAR(strParams);
				zephir_fast_trim(strParams, paramsStr, &_2, ZEPHIR_TRIM_BOTH TSRMLS_CC);
				if (zephir_is_true(strParams)) {
					ZEPHIR_INIT_NVAR(params);
					zephir_fast_explode_str(params, SL("/"), strParams, LONG_MAX TSRMLS_CC);
				}
			}
			zephir_array_unset_string(&parts, SS("params"), PH_SEPARATE);
		}
		if (zephir_fast_count_int(params TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_9);
			zephir_fast_array_merge(_9, &(params), &(parts) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_params"), _9 TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_params"), parts TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a route to the router without any HTTP constraint
 *
 *<code>
 * $router->add('/about', 'About::index');
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *httpMethods = NULL, *route;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &httpMethods);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!httpMethods) {
		httpMethods = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(route);
	object_init_ex(route, phalcon_mvc_router_route_ce);
	ZEPHIR_CALL_METHOD(NULL, route, "__construct", NULL, 354, pattern, paths, httpMethods);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_routes"), route TSRMLS_CC);
	RETURN_CCTOR(route);

}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 */
PHP_METHOD(Phalcon_Mvc_Router, addGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "GET", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 */
PHP_METHOD(Phalcon_Mvc_Router, addPost) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "POST", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 */
PHP_METHOD(Phalcon_Mvc_Router, addPut) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "PUT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 */
PHP_METHOD(Phalcon_Mvc_Router, addPatch) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "PATCH", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 */
PHP_METHOD(Phalcon_Mvc_Router, addDelete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "DELETE", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 */
PHP_METHOD(Phalcon_Mvc_Router, addOptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "OPTIONS", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 */
PHP_METHOD(Phalcon_Mvc_Router, addHead) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HEAD", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Mounts a group of routes in the router
 */
PHP_METHOD(Phalcon_Mvc_Router, mount) {

	HashTable *_1, *_4;
	HashPosition _0, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *group, *groupRoutes = NULL, *beforeMatch = NULL, *hostname = NULL, *routes, *route = NULL, **_2, **_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);



	ZEPHIR_CALL_METHOD(&groupRoutes, group, "getroutes", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(groupRoutes TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "The group of routes does not contain any routes", "phalcon/mvc/router.zep", 690);
		return;
	}
	ZEPHIR_CALL_METHOD(&beforeMatch, group, "getbeforematch", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(beforeMatch) != IS_NULL) {
		zephir_is_iterable(groupRoutes, &_1, &_0, 0, 0, "phalcon/mvc/router.zep", 702);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(route, _2);
			ZEPHIR_CALL_METHOD(NULL, route, "beforematch", NULL, 0, beforeMatch);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&hostname, group, "gethostname", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(hostname) != IS_NULL) {
		zephir_is_iterable(groupRoutes, &_4, &_3, 0, 0, "phalcon/mvc/router.zep", 711);
		for (
		  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HVALUE(route, _5);
			ZEPHIR_CALL_METHOD(NULL, route, "sethostname", NULL, 0, hostname);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(routes);
	zephir_read_property_this(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	if (Z_TYPE_P(routes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_6);
		zephir_fast_array_merge(_6, &(routes), &(groupRoutes) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_routes"), _6 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_routes"), groupRoutes TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Set a group of paths to be returned when none of the defined routes are matched
 */
PHP_METHOD(Phalcon_Mvc_Router, notFound) {

	zend_bool _0;
	zval *paths;

	zephir_fetch_params(0, 1, 0, &paths);



	_0 = Z_TYPE_P(paths) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(paths) != IS_STRING;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_router_exception_ce, "The not-found paths must be an array or string", "phalcon/mvc/router.zep", 730);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_notFoundPaths"), paths TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, clear) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_routes"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the processed namespace name
 */
PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName) {


	RETURN_MEMBER(this_ptr, "_namespace");

}

/**
 * Returns the processed module name
 */
PHP_METHOD(Phalcon_Mvc_Router, getModuleName) {


	RETURN_MEMBER(this_ptr, "_module");

}

/**
 * Returns the processed controller name
 */
PHP_METHOD(Phalcon_Mvc_Router, getControllerName) {


	RETURN_MEMBER(this_ptr, "_controller");

}

/**
 * Returns the processed action name
 */
PHP_METHOD(Phalcon_Mvc_Router, getActionName) {


	RETURN_MEMBER(this_ptr, "_action");

}

/**
 * Returns the processed parameters
 */
PHP_METHOD(Phalcon_Mvc_Router, getParams) {


	RETURN_MEMBER(this_ptr, "_params");

}

/**
 * Returns the route that matchs the handled URI
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute) {


	RETURN_MEMBER(this_ptr, "_matchedRoute");

}

/**
 * Returns the sub expressions in the regular expression matched
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatches) {


	RETURN_MEMBER(this_ptr, "_matches");

}

/**
 * Checks if the router macthes any of the defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, wasMatched) {


	RETURN_MEMBER(this_ptr, "_wasMatched");

}

/**
 * Returns all the routes defined in the router
 */
PHP_METHOD(Phalcon_Mvc_Router, getRoutes) {


	RETURN_MEMBER(this_ptr, "_routes");

}

/**
 * Returns a route object by its id
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteById) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *id, *route = NULL, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/mvc/router.zep", 829);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(route, _3);
		ZEPHIR_CALL_METHOD(&_4, route, "getrouteid", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(_4, id)) {
			RETURN_CCTOR(route);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns a route object by its name
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *name_param = NULL, *route = NULL, *_0, **_3, *_4 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/mvc/router.zep", 844);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(route, _3);
		ZEPHIR_CALL_METHOD(&_4, route, "getname", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(_4, name)) {
			RETURN_CCTOR(route);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns whether controller name should not be mangled
 */
PHP_METHOD(Phalcon_Mvc_Router, isExactControllerName) {


	RETURN_BOOL(1);

}

