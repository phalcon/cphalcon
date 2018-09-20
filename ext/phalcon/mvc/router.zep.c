
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
 * Phalcon\Mvc\Router
 *
 * Phalcon\Mvc\Router is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request
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
 * $router->handle();
 *
 * echo $router->getControllerName();
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, Router, phalcon, mvc_router, phalcon_mvc_router_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_keyRouteNames"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_keyRouteIds"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_router_ce->create_object = zephir_init_properties_Phalcon_Mvc_Router;
	zend_declare_class_constant_long(phalcon_mvc_router_ce, SL("URI_SOURCE_GET_URL"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_router_ce, SL("URI_SOURCE_SERVER_REQUEST_URI"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_router_ce, SL("POSITION_FIRST"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_router_ce, SL("POSITION_LAST"), 1 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_router_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_router_ce TSRMLS_CC, 1, phalcon_mvc_routerinterface_ce);
	zend_class_implements(phalcon_mvc_router_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteNames) {

	

	RETURN_MEMBER(getThis(), "_keyRouteNames");

}

PHP_METHOD(Phalcon_Mvc_Router, setKeyRouteNames) {

	zval *keyRouteNames;

	zephir_fetch_params(0, 1, 0, &keyRouteNames);



	zephir_update_property_this(getThis(), SL("_keyRouteNames"), keyRouteNames TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteIds) {

	

	RETURN_MEMBER(getThis(), "_keyRouteIds");

}

PHP_METHOD(Phalcon_Mvc_Router, setKeyRouteIds) {

	zval *keyRouteIds;

	zephir_fetch_params(0, 1, 0, &keyRouteIds);



	zephir_update_property_this(getThis(), SL("_keyRouteIds"), keyRouteIds TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Phalcon\Mvc\Router constructor
 */
PHP_METHOD(Phalcon_Mvc_Router, __construct) {

	zval *routes, *_1$$3, *_3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultRoutes_param = NULL, *_0$$3, *_2$$3 = NULL, *_4$$3;
	zend_bool defaultRoutes;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultRoutes_param);

	if (!defaultRoutes_param) {
		defaultRoutes = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(defaultRoutes_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'defaultRoutes' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	defaultRoutes = Z_BVAL_P(defaultRoutes_param);
	}


	ZEPHIR_INIT_VAR(routes);
	array_init(routes);
	if (defaultRoutes) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(_1$$3, SS("controller"), 1);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "#^/([\\w0-9\\_\\-]+)[/]{0,1}$#u", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 82, _2$$3, _1$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, _0$$3, PH_SEPARATE, "phalcon/mvc/router.zep", 124);
		ZEPHIR_INIT_NVAR(_2$$3);
		object_init_ex(_2$$3, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_create_array(_3$$3, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(_3$$3, SS("controller"), 1);
		add_assoc_long_ex(_3$$3, SS("action"), 2);
		add_assoc_long_ex(_3$$3, SS("params"), 3);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "#^/([\\w0-9\\_\\-]+)/([\\w0-9\\.\\_]+)(/.*)*$#u", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 82, _4$$3, _3$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, _2$$3, PH_SEPARATE, "phalcon/mvc/router.zep", 130);
	}
	zephir_update_property_this(getThis(), SL("_routes"), routes TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Mvc_Router, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Mvc_Router, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Mvc_Router, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(getThis(), SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Mvc_Router, getEventsManager) {

	

	RETURN_MEMBER(getThis(), "_eventsManager");

}

/**
 * Get rewrite info. This info is read from $_GET["_url"]. This returns '/' if the rewrite information cannot be read
 */
PHP_METHOD(Phalcon_Mvc_Router, getRewriteUri) {

	zval *_GET, *_SERVER, *url = NULL, *urlParts = NULL, *realUri = NULL, *_0;

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
			zephir_array_fetch_long(&realUri, urlParts, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/router.zep", 190 TSRMLS_CC);
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
 * <code>
 * $router->setUriSource(
 *     Router::URI_SOURCE_SERVER_REQUEST_URI
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Router, setUriSource) {

	zval *uriSource;

	zephir_fetch_params(0, 1, 0, &uriSource);



	zephir_update_property_this(getThis(), SL("_uriSource"), uriSource TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Set whether router must remove the extra slashes in the handled routes
 */
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes) {

	zval *remove_param = NULL;
	zend_bool remove;

	zephir_fetch_params(0, 1, 0, &remove_param);

	if (UNEXPECTED(Z_TYPE_P(remove_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'remove' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	remove = Z_BVAL_P(remove_param);


	if (remove) {
		zephir_update_property_this(getThis(), SL("_removeExtraSlashes"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_removeExtraSlashes"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
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

	if (UNEXPECTED(Z_TYPE_P(namespaceName_param) != IS_STRING && Z_TYPE_P(namespaceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'namespaceName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(namespaceName_param) == IS_STRING)) {
		zephir_get_strval(namespaceName, namespaceName_param);
	} else {
		ZEPHIR_INIT_VAR(namespaceName);
		ZVAL_EMPTY_STRING(namespaceName);
	}


	zephir_update_property_this(getThis(), SL("_defaultNamespace"), namespaceName TSRMLS_CC);
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

	if (UNEXPECTED(Z_TYPE_P(moduleName_param) != IS_STRING && Z_TYPE_P(moduleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleName_param) == IS_STRING)) {
		zephir_get_strval(moduleName, moduleName_param);
	} else {
		ZEPHIR_INIT_VAR(moduleName);
		ZVAL_EMPTY_STRING(moduleName);
	}


	zephir_update_property_this(getThis(), SL("_defaultModule"), moduleName TSRMLS_CC);
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

	if (UNEXPECTED(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(controllerName);
		ZVAL_EMPTY_STRING(controllerName);
	}


	zephir_update_property_this(getThis(), SL("_defaultController"), controllerName TSRMLS_CC);
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

	if (UNEXPECTED(Z_TYPE_P(actionName_param) != IS_STRING && Z_TYPE_P(actionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(actionName_param) == IS_STRING)) {
		zephir_get_strval(actionName, actionName_param);
	} else {
		ZEPHIR_INIT_VAR(actionName);
		ZVAL_EMPTY_STRING(actionName);
	}


	zephir_update_property_this(getThis(), SL("_defaultAction"), actionName TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets an array of default paths. If a route is missing a path the router will use the defined here
 * This method must not be used to set a 404 route
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

	zval *defaults_param = NULL, *namespaceName = NULL, *module = NULL, *controller = NULL, *action = NULL, *params = NULL;
	zval *defaults = NULL;

	zephir_fetch_params(0, 1, 0, &defaults_param);

	defaults = defaults_param;


	if (zephir_array_isset_string_fetch(&namespaceName, defaults, SS("namespace"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_defaultNamespace"), namespaceName TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&module, defaults, SS("module"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_defaultModule"), module TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&controller, defaults, SS("controller"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_defaultController"), controller TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&action, defaults, SS("action"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_defaultAction"), action TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&params, defaults, SS("params"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_defaultParams"), params TSRMLS_CC);
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
 * // Read the info from the rewrite engine
 * $router->handle();
 *
 * // Manually passing an URL
 * $router->handle("/posts/edit/1");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, handle) {

	zval *_21$$29 = NULL, *_32$$40 = NULL, *_34$$43 = NULL;
	HashTable *_6, *_25$$34;
	HashPosition _5, _24$$34;
	zend_bool _1, _30$$35;
	zephir_fcall_cache_entry *_18 = NULL, *_20 = NULL, *_23 = NULL, *_29 = NULL, *_35 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *realUri = NULL, *request = NULL, *currentHostName = NULL, *routeFound = NULL, *parts = NULL, *params = NULL, *matches = NULL, *notFoundPaths = NULL, *vnamespace = NULL, *module = NULL, *controller = NULL, *action = NULL, *paramsStr = NULL, *strParams = NULL, *route = NULL, *methods = NULL, *dependencyInjector = NULL, *hostname = NULL, *regexHostName = NULL, *matched = NULL, *pattern = NULL, *handledUri = NULL, *beforeMatch = NULL, *paths = NULL, *converters = NULL, *part = NULL, *position = NULL, *matchPosition = NULL, *converter = NULL, *eventsManager = NULL, *_0, *_4, **_7, *_36, *_37, *_38, *_39, *_40, _2$$5, *_3$$7, *_8$$10, *_9$$10 = NULL, *_10$$10 = NULL, *_11$$9 = NULL, *_12$$9 = NULL, *_13$$14, *_14$$14 = NULL, *_15$$14 = NULL, *_16$$18 = NULL, *_17$$24 = NULL, *_19$$28 = NULL, *_22$$32 = NULL, **_26$$34, *_27$$36 = NULL, *_28$$36 = NULL, *_31$$40 = NULL, *_33$$43 = NULL, _41$$60, *_42$$62, *_43$$64;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	} else {
		zephir_get_strval(uri, uri_param);
	}


	if (!(!(!uri) && Z_STRLEN_P(uri))) {
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
		ZEPHIR_SINIT_VAR(_2$$5);
		ZVAL_STRING(&_2$$5, "/", 0);
		ZEPHIR_INIT_VAR(handledUri);
		zephir_fast_trim(handledUri, realUri, &_2$$5, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
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
	if (0) {
		zephir_update_property_this(getThis(), SL("_wasMatched"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_wasMatched"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	zephir_update_property_this(getThis(), SL("_matchedRoute"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_OBS_VAR(eventsManager);
	zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_3$$7);
		ZVAL_STRING(_3$$7, "router:beforeCheckRoutes", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _3$$7, this_ptr);
		zephir_check_temp_parameter(_3$$7);
		zephir_check_call_status();
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_4, &_6, &_5, 0, 1, "phalcon/mvc/router.zep", 586);
	for (
	  ; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zend_hash_move_backwards_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(route, _7);
		ZEPHIR_INIT_NVAR(params);
		array_init(params);
		ZEPHIR_INIT_NVAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_CALL_METHOD(&methods, route, "gethttpmethods", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(methods) != IS_NULL) {
			if (Z_TYPE_P(request) == IS_NULL) {
				_8$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				ZEPHIR_CPY_WRT(dependencyInjector, _8$$10);
				if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service", "phalcon/mvc/router.zep", 391);
					return;
				}
				ZEPHIR_INIT_NVAR(_10$$10);
				ZVAL_STRING(_10$$10, "request", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_9$$10, dependencyInjector, "getshared", NULL, 0, _10$$10);
				zephir_check_temp_parameter(_10$$10);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(request, _9$$10);
			}
			ZEPHIR_INIT_NVAR(_12$$9);
			ZVAL_BOOL(_12$$9, 1);
			ZEPHIR_CALL_METHOD(&_11$$9, request, "ismethod", NULL, 0, methods, _12$$9);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_11$$9)) {
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&hostname, route, "gethostname", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(hostname) != IS_NULL) {
			if (Z_TYPE_P(request) == IS_NULL) {
				_13$$14 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				ZEPHIR_CPY_WRT(dependencyInjector, _13$$14);
				if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service", "phalcon/mvc/router.zep", 418);
					return;
				}
				ZEPHIR_INIT_NVAR(_15$$14);
				ZVAL_STRING(_15$$14, "request", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_14$$14, dependencyInjector, "getshared", NULL, 0, _15$$14);
				zephir_check_temp_parameter(_15$$14);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(request, _14$$14);
			}
			if (Z_TYPE_P(currentHostName) == IS_NULL) {
				ZEPHIR_CALL_METHOD(&currentHostName, request, "gethttphost", NULL, 0);
				zephir_check_call_status();
			}
			if (!(zephir_is_true(currentHostName))) {
				continue;
			}
			if (zephir_memnstr_str(hostname, SL("("), "phalcon/mvc/router.zep", 441)) {
				if (!(zephir_memnstr_str(hostname, SL("#"), "phalcon/mvc/router.zep", 442))) {
					ZEPHIR_INIT_NVAR(regexHostName);
					ZEPHIR_CONCAT_SV(regexHostName, "#^", hostname);
					if (!(zephir_memnstr_str(hostname, SL(":"), "phalcon/mvc/router.zep", 444))) {
						zephir_concat_self_str(&regexHostName, SL("(:[[:digit:]]+)?") TSRMLS_CC);
					}
					zephir_concat_self_str(&regexHostName, SL("$#i") TSRMLS_CC);
				} else {
					ZEPHIR_CPY_WRT(regexHostName, hostname);
				}
				ZEPHIR_INIT_NVAR(_16$$18);
				ZEPHIR_INIT_NVAR(matched);
				zephir_preg_match(matched, regexHostName, currentHostName, _16$$18, 0, 0 , 0  TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(matched);
				ZVAL_BOOL(matched, ZEPHIR_IS_EQUAL(currentHostName, hostname));
			}
			if (!(zephir_is_true(matched))) {
				continue;
			}
		}
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_17$$24);
			ZVAL_STRING(_17$$24, "router:beforeCheckRoute", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_18, 0, _17$$24, this_ptr, route);
			zephir_check_temp_parameter(_17$$24);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&pattern, route, "getcompiledpattern", NULL, 0);
		zephir_check_call_status();
		if (zephir_memnstr_str(pattern, SL("^"), "phalcon/mvc/router.zep", 470)) {
			ZEPHIR_INIT_NVAR(routeFound);
			zephir_preg_match(routeFound, pattern, handledUri, matches, 0, 0 , 0  TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(routeFound);
			ZVAL_BOOL(routeFound, ZEPHIR_IS_EQUAL(pattern, handledUri));
		}
		if (zephir_is_true(routeFound)) {
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_19$$28);
				ZVAL_STRING(_19$$28, "router:matchedRoute", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_20, 0, _19$$28, this_ptr, route);
				zephir_check_temp_parameter(_19$$28);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&beforeMatch, route, "getbeforematch", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(beforeMatch) != IS_NULL) {
				if (!(zephir_is_callable(beforeMatch TSRMLS_CC))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/mvc/router.zep", 492);
					return;
				}
				ZEPHIR_INIT_NVAR(_21$$29);
				zephir_create_array(_21$$29, 3, 0 TSRMLS_CC);
				zephir_array_fast_append(_21$$29, handledUri);
				zephir_array_fast_append(_21$$29, route);
				zephir_array_fast_append(_21$$29, this_ptr);
				ZEPHIR_INIT_NVAR(routeFound);
				ZEPHIR_CALL_USER_FUNC_ARRAY(routeFound, beforeMatch, _21$$29);
				zephir_check_call_status();
			}
		} else {
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_22$$32);
				ZVAL_STRING(_22$$32, "router:notMatchedRoute", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&routeFound, eventsManager, "fire", &_23, 0, _22$$32, this_ptr, route);
				zephir_check_temp_parameter(_22$$32);
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
				zephir_is_iterable(paths, &_25$$34, &_24$$34, 0, 0, "phalcon/mvc/router.zep", 575);
				for (
				  ; zend_hash_get_current_data_ex(_25$$34, (void**) &_26$$34, &_24$$34) == SUCCESS
				  ; zend_hash_move_forward_ex(_25$$34, &_24$$34)
				) {
					ZEPHIR_GET_HMKEY(part, _25$$34, _24$$34);
					ZEPHIR_GET_HVALUE(position, _26$$34);
					if (Z_TYPE_P(part) != IS_STRING) {
						ZEPHIR_INIT_NVAR(_27$$36);
						object_init_ex(_27$$36, phalcon_mvc_router_exception_ce);
						ZEPHIR_INIT_LNVAR(_28$$36);
						ZEPHIR_CONCAT_SV(_28$$36, "Wrong key in paths: ", part);
						ZEPHIR_CALL_METHOD(NULL, _27$$36, "__construct", &_29, 9, _28$$36);
						zephir_check_call_status();
						zephir_throw_exception_debug(_27$$36, "phalcon/mvc/router.zep", 528 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					_30$$35 = Z_TYPE_P(position) != IS_STRING;
					if (_30$$35) {
						_30$$35 = Z_TYPE_P(position) != IS_LONG;
					}
					if (_30$$35) {
						continue;
					}
					ZEPHIR_OBS_NVAR(matchPosition);
					if (zephir_array_isset_fetch(&matchPosition, matches, position, 0 TSRMLS_CC)) {
						if (Z_TYPE_P(converters) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(converter);
							if (zephir_array_isset_fetch(&converter, converters, part, 0 TSRMLS_CC)) {
								ZEPHIR_INIT_NVAR(_31$$40);
								ZEPHIR_INIT_NVAR(_32$$40);
								zephir_create_array(_32$$40, 1, 0 TSRMLS_CC);
								zephir_array_fast_append(_32$$40, matchPosition);
								ZEPHIR_CALL_USER_FUNC_ARRAY(_31$$40, converter, _32$$40);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, part, &_31$$40, PH_COPY | PH_SEPARATE);
								continue;
							}
						}
						zephir_array_update_zval(&parts, part, &matchPosition, PH_COPY | PH_SEPARATE);
					} else {
						if (Z_TYPE_P(converters) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(converter);
							if (zephir_array_isset_fetch(&converter, converters, part, 0 TSRMLS_CC)) {
								ZEPHIR_INIT_NVAR(_33$$43);
								ZEPHIR_INIT_NVAR(_34$$43);
								zephir_create_array(_34$$43, 1, 0 TSRMLS_CC);
								zephir_array_fast_append(_34$$43, position);
								ZEPHIR_CALL_USER_FUNC_ARRAY(_33$$43, converter, _34$$43);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, part, &_33$$43, PH_COPY | PH_SEPARATE);
							}
						} else {
							if (Z_TYPE_P(position) == IS_LONG) {
								zephir_array_unset(&parts, part, PH_SEPARATE);
							}
						}
					}
				}
				zephir_update_property_this(getThis(), SL("_matches"), matches TSRMLS_CC);
			}
			zephir_update_property_this(getThis(), SL("_matchedRoute"), route TSRMLS_CC);
			break;
		}
	}
	if (zephir_is_true(routeFound)) {
		if (1) {
			zephir_update_property_this(getThis(), SL("_wasMatched"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_wasMatched"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	} else {
		if (0) {
			zephir_update_property_this(getThis(), SL("_wasMatched"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_wasMatched"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	if (!(zephir_is_true(routeFound))) {
		ZEPHIR_OBS_VAR(notFoundPaths);
		zephir_read_property_this(&notFoundPaths, this_ptr, SL("_notFoundPaths"), PH_NOISY_CC);
		if (Z_TYPE_P(notFoundPaths) != IS_NULL) {
			ZEPHIR_CALL_CE_STATIC(&parts, phalcon_mvc_router_route_ce, "getroutepaths", &_35, 83, notFoundPaths);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(routeFound);
			ZVAL_BOOL(routeFound, 1);
		}
	}
	_36 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
	zephir_update_property_this(getThis(), SL("_namespace"), _36 TSRMLS_CC);
	_37 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	zephir_update_property_this(getThis(), SL("_module"), _37 TSRMLS_CC);
	_38 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultController"), PH_NOISY_CC);
	zephir_update_property_this(getThis(), SL("_controller"), _38 TSRMLS_CC);
	_39 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY_CC);
	zephir_update_property_this(getThis(), SL("_action"), _39 TSRMLS_CC);
	_40 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultParams"), PH_NOISY_CC);
	zephir_update_property_this(getThis(), SL("_params"), _40 TSRMLS_CC);
	if (zephir_is_true(routeFound)) {
		ZEPHIR_OBS_VAR(vnamespace);
		if (zephir_array_isset_string_fetch(&vnamespace, parts, SS("namespace"), 0 TSRMLS_CC)) {
			if (!(zephir_is_numeric(vnamespace))) {
				zephir_update_property_this(getThis(), SL("_namespace"), vnamespace TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("namespace"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(module);
		if (zephir_array_isset_string_fetch(&module, parts, SS("module"), 0 TSRMLS_CC)) {
			if (!(zephir_is_numeric(module))) {
				zephir_update_property_this(getThis(), SL("_module"), module TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("module"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(controller);
		if (zephir_array_isset_string_fetch(&controller, parts, SS("controller"), 0 TSRMLS_CC)) {
			if (!(zephir_is_numeric(controller))) {
				zephir_update_property_this(getThis(), SL("_controller"), controller TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("controller"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(action);
		if (zephir_array_isset_string_fetch(&action, parts, SS("action"), 0 TSRMLS_CC)) {
			if (!(zephir_is_numeric(action))) {
				zephir_update_property_this(getThis(), SL("_action"), action TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("action"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(paramsStr);
		if (zephir_array_isset_string_fetch(&paramsStr, parts, SS("params"), 0 TSRMLS_CC)) {
			if (Z_TYPE_P(paramsStr) == IS_STRING) {
				ZEPHIR_SINIT_VAR(_41$$60);
				ZVAL_STRING(&_41$$60, "/", 0);
				ZEPHIR_INIT_VAR(strParams);
				zephir_fast_trim(strParams, paramsStr, &_41$$60, ZEPHIR_TRIM_BOTH TSRMLS_CC);
				if (!ZEPHIR_IS_STRING_IDENTICAL(strParams, "")) {
					ZEPHIR_INIT_NVAR(params);
					zephir_fast_explode_str(params, SL("/"), strParams, LONG_MAX TSRMLS_CC);
				}
			}
			zephir_array_unset_string(&parts, SS("params"), PH_SEPARATE);
		}
		if (zephir_fast_count_int(params TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_42$$62);
			zephir_fast_array_merge(_42$$62, &(params), &(parts) TSRMLS_CC);
			zephir_update_property_this(getThis(), SL("_params"), _42$$62 TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_params"), parts TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_43$$64);
		ZVAL_STRING(_43$$64, "router:afterCheckRoutes", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _43$$64, this_ptr);
		zephir_check_temp_parameter(_43$$64);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

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
 *
 * @todo Add to the interface for 4.0.0
 */
PHP_METHOD(Phalcon_Mvc_Router, attach) {

	zval *_1$$4;
	zval *route, *position = NULL, *_0$$4, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &route, &position);

	if (!position) {
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	do {
		if (ZEPHIR_IS_LONG(position, 1)) {
			zephir_update_property_array_append(this_ptr, SL("_routes"), route TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(position, 0)) {
			ZEPHIR_INIT_VAR(_0$$4);
			ZEPHIR_INIT_VAR(_1$$4);
			zephir_create_array(_1$$4, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_1$$4, route);
			_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
			zephir_fast_array_merge(_0$$4, &(_1$$4), &(_2$$4) TSRMLS_CC);
			zephir_update_property_this(getThis(), SL("_routes"), _0$$4 TSRMLS_CC);
			break;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Invalid route position", "phalcon/mvc/router.zep", 711);
		return;
	} while(0);

	RETURN_THIS();

}

/**
 * Adds a route to the router without any HTTP constraint
 *
 *<code>
 * use Phalcon\Mvc\Router;
 *
 * $router->add("/about", "About::index");
 * $router->add("/about", "About::index", ["GET", "POST"]);
 * $router->add("/about", "About::index", ["GET", "POST"], Router::POSITION_FIRST);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, add) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *httpMethods = NULL, *position = NULL, *route = NULL;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &pattern_param, &paths, &httpMethods, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
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
	if (!position) {
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(route);
	object_init_ex(route, phalcon_mvc_router_route_ce);
	ZEPHIR_CALL_METHOD(NULL, route, "__construct", NULL, 82, pattern, paths, httpMethods);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, route, position);
	zephir_check_call_status();
	RETURN_CCTOR(route);

}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 */
PHP_METHOD(Phalcon_Mvc_Router, addGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *position = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!position) {
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "GET", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0, position);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 */
PHP_METHOD(Phalcon_Mvc_Router, addPost) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *position = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!position) {
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "POST", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0, position);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 */
PHP_METHOD(Phalcon_Mvc_Router, addPut) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *position = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!position) {
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "PUT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0, position);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 */
PHP_METHOD(Phalcon_Mvc_Router, addPatch) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *position = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!position) {
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "PATCH", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0, position);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 */
PHP_METHOD(Phalcon_Mvc_Router, addDelete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *position = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!position) {
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "DELETE", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0, position);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 */
PHP_METHOD(Phalcon_Mvc_Router, addOptions) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *position = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!position) {
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "OPTIONS", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0, position);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 */
PHP_METHOD(Phalcon_Mvc_Router, addHead) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *position = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!position) {
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HEAD", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0, position);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PURGE (Squid and Varnish support)
 */
PHP_METHOD(Phalcon_Mvc_Router, addPurge) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *position = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!position) {
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "PURGE", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0, position);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is TRACE
 */
PHP_METHOD(Phalcon_Mvc_Router, addTrace) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *position = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!position) {
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "TRACE", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0, position);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is CONNECT
 */
PHP_METHOD(Phalcon_Mvc_Router, addConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *position = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!position) {
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "CONNECT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, pattern, paths, _0, position);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Mounts a group of routes in the router
 */
PHP_METHOD(Phalcon_Mvc_Router, mount) {

	HashTable *_2$$5, *_5$$7;
	HashPosition _1$$5, _4$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group, *groupRoutes = NULL, *beforeMatch = NULL, *hostname = NULL, *routes = NULL, *route = NULL, *eventsManager = NULL, *_0$$3, **_3$$5, **_6$$7, *_7$$9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);



	ZEPHIR_OBS_VAR(eventsManager);
	zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "router:beforeMount", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _0$$3, this_ptr, group);
		zephir_check_temp_parameter(_0$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&groupRoutes, group, "getroutes", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(groupRoutes TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "The group of routes does not contain any routes", "phalcon/mvc/router.zep", 837);
		return;
	}
	ZEPHIR_CALL_METHOD(&beforeMatch, group, "getbeforematch", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(beforeMatch) != IS_NULL) {
		zephir_is_iterable(groupRoutes, &_2$$5, &_1$$5, 0, 0, "phalcon/mvc/router.zep", 849);
		for (
		  ; zend_hash_get_current_data_ex(_2$$5, (void**) &_3$$5, &_1$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_2$$5, &_1$$5)
		) {
			ZEPHIR_GET_HVALUE(route, _3$$5);
			ZEPHIR_CALL_METHOD(NULL, route, "beforematch", NULL, 0, beforeMatch);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&hostname, group, "gethostname", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(hostname) != IS_NULL) {
		zephir_is_iterable(groupRoutes, &_5$$7, &_4$$7, 0, 0, "phalcon/mvc/router.zep", 858);
		for (
		  ; zend_hash_get_current_data_ex(_5$$7, (void**) &_6$$7, &_4$$7) == SUCCESS
		  ; zend_hash_move_forward_ex(_5$$7, &_4$$7)
		) {
			ZEPHIR_GET_HVALUE(route, _6$$7);
			ZEPHIR_CALL_METHOD(NULL, route, "sethostname", NULL, 0, hostname);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(routes);
	zephir_read_property_this(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	if (Z_TYPE_P(routes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_7$$9);
		zephir_fast_array_merge(_7$$9, &(routes), &(groupRoutes) TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_routes"), _7$$9 TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_routes"), groupRoutes TSRMLS_CC);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_router_exception_ce, "The not-found paths must be an array or string", "phalcon/mvc/router.zep", 877);
		return;
	}
	zephir_update_property_this(getThis(), SL("_notFoundPaths"), paths TSRMLS_CC);
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
	zephir_update_property_this(getThis(), SL("_routes"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the processed namespace name
 */
PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName) {

	

	RETURN_MEMBER(getThis(), "_namespace");

}

/**
 * Returns the processed module name
 */
PHP_METHOD(Phalcon_Mvc_Router, getModuleName) {

	

	RETURN_MEMBER(getThis(), "_module");

}

/**
 * Returns the processed controller name
 */
PHP_METHOD(Phalcon_Mvc_Router, getControllerName) {

	

	RETURN_MEMBER(getThis(), "_controller");

}

/**
 * Returns the processed action name
 */
PHP_METHOD(Phalcon_Mvc_Router, getActionName) {

	

	RETURN_MEMBER(getThis(), "_action");

}

/**
 * Returns the processed parameters
 */
PHP_METHOD(Phalcon_Mvc_Router, getParams) {

	

	RETURN_MEMBER(getThis(), "_params");

}

/**
 * Returns the route that matches the handled URI
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute) {

	

	RETURN_MEMBER(getThis(), "_matchedRoute");

}

/**
 * Returns the sub expressions in the regular expression matched
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatches) {

	

	RETURN_MEMBER(getThis(), "_matches");

}

/**
 * Checks if the router matches any of the defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, wasMatched) {

	

	RETURN_MEMBER(getThis(), "_wasMatched");

}

/**
 * Returns all the routes defined in the router
 */
PHP_METHOD(Phalcon_Mvc_Router, getRoutes) {

	

	RETURN_MEMBER(getThis(), "_routes");

}

/**
 * Returns a route object by its id
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteById) {

	HashTable *_5;
	HashPosition _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, *route = NULL, *routeId = NULL, *key = NULL, *_0, *_3, **_6, *_1$$3, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	ZEPHIR_OBS_VAR(key);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_keyRouteIds"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&key, _0, id, 0 TSRMLS_CC)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
		zephir_array_fetch(&_2$$3, _1$$3, key, PH_NOISY | PH_READONLY, "phalcon/mvc/router.zep", 971 TSRMLS_CC);
		RETURN_CTOR(_2$$3);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "phalcon/mvc/router.zep", 982);
	for (
	  ; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(key, _5, _4);
		ZEPHIR_GET_HVALUE(route, _6);
		ZEPHIR_CALL_METHOD(&routeId, route, "getrouteid", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("_keyRouteIds"), routeId, key TSRMLS_CC);
		if (ZEPHIR_IS_EQUAL(routeId, id)) {
			RETURN_CCTOR(route);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns a route object by its name
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName) {

	HashTable *_5;
	HashPosition _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *route = NULL, *routeName = NULL, *key = NULL, *_0, *_3, **_6, *_1$$3, *_2$$3;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_OBS_VAR(key);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_keyRouteNames"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&key, _0, name, 0 TSRMLS_CC)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
		zephir_array_fetch(&_2$$3, _1$$3, key, PH_NOISY | PH_READONLY, "phalcon/mvc/router.zep", 993 TSRMLS_CC);
		RETURN_CTOR(_2$$3);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "phalcon/mvc/router.zep", 1006);
	for (
	  ; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(key, _5, _4);
		ZEPHIR_GET_HVALUE(route, _6);
		ZEPHIR_CALL_METHOD(&routeName, route, "getname", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(routeName))) {
			zephir_update_property_array(this_ptr, SL("_keyRouteNames"), routeName, key TSRMLS_CC);
			if (ZEPHIR_IS_EQUAL(routeName, name)) {
				RETURN_CCTOR(route);
			}
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

zend_object_value zephir_init_properties_Phalcon_Mvc_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_6, *_1$$3, *_3$$4, *_5$$5, *_7$$6;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_keyRouteIds"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_keyRouteIds"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_keyRouteNames"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("_keyRouteNames"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultParams"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(getThis(), SL("_defaultParams"), _5$$5 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(_7$$6);
			array_init(_7$$6);
			zephir_update_property_this(getThis(), SL("_params"), _7$$6 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

