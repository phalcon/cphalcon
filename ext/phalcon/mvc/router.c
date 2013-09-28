
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/hash.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
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
 *	$router = new Phalcon\Mvc\Router();
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
 *
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

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Router constructor
 *
 * @param boolean defaultRoutes
 */
PHP_METHOD(Phalcon_Mvc_Router, __construct) {

	zval *defaultRoutes_param = NULL, *routes, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4;
	zend_bool defaultRoutes;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultRoutes_param);

	if (!defaultRoutes_param) {
		defaultRoutes = 1;
	} else {
		defaultRoutes = zephir_get_boolval(defaultRoutes_param);
	}


	ZEPHIR_INIT_VAR(routes);
	array_init(routes);
	if ((defaultRoutes == 1)) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(_1);
		array_init(_1);
		add_assoc_long_ex(_1, SS("controller"), 1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "#^/([a-zA-Z0-9\\_\\-]+)[/]{0,1}$#", 1);
		zephir_call_method_p2_noret(_0, "__construct", _2, _1);
		zephir_array_append(&routes, _0, PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_2);
		object_init_ex(_2, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(_3);
		array_init(_3);
		add_assoc_long_ex(_3, SS("controller"), 1);
		add_assoc_long_ex(_3, SS("action"), 2);
		add_assoc_long_ex(_3, SS("params"), 3);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "#^/([a-zA-Z0-9\\_\\-]+)/([a-zA-Z0-9\\.\\_]+)(/.*)*$#", 1);
		zephir_call_method_p2_noret(_2, "__construct", _4, _3);
		zephir_array_append(&routes, _2, PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_params"), _0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_defaultParams"), _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_routes"), routes TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Router, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Get rewrite info. This info is read from $_GET['_url']. This returns '/' if the rewrite information cannot be read
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getRewriteUri) {

	zval *url = NULL, *urlParts, *realUri, *_0, *_GET, *_SERVER, _1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_uriSource"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_OBS_VAR(url);
		zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
		if (zephir_array_isset_string_fetch(&url, _GET, SS("_url") TSRMLS_CC)) {
			if (!(zephir_is_true(url))) {
				RETURN_CCTOR(url);
			}
		}
	} else {
		ZEPHIR_OBS_NVAR(url);
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		if (zephir_array_isset_string_fetch(&url, _SERVER, SS("REQUEST_URI") TSRMLS_CC)) {
			ZEPHIR_SINIT_VAR(_1);
			ZVAL_STRING(&_1, "?", 0);
			ZEPHIR_INIT_VAR(urlParts);
			zephir_call_func_p2(urlParts, "explode", &_1, url);
			ZEPHIR_OBS_VAR(realUri);
			zephir_array_fetch_long(&realUri, urlParts, 0, PH_NOISY TSRMLS_CC);
			if (!(zephir_is_true(realUri))) {
				RETURN_CCTOR(realUri);
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
 *
 * @param string uriSource
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setUriSource) {

	zval *uriSource;

	zephir_fetch_params(0, 1, 0, &uriSource);



	zephir_update_property_this(this_ptr, SL("_uriSource"), uriSource TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Set whether router must remove the extra slashes in the handled routes
 *
 * @param boolean remove
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes) {

	zval *remove;

	zephir_fetch_params(0, 1, 0, &remove);



	zephir_update_property_this(this_ptr, SL("_removeExtraSlashes"), remove TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets the name of the default namespace
 *
 * @param string namespaceName
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace) {

	zval *namespaceName;

	zephir_fetch_params(0, 1, 0, &namespaceName);



	zephir_update_property_this(this_ptr, SL("_defaultNamespace"), namespaceName TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets the name of the default module
 *
 * @param string moduleName
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule) {

	zval *moduleName_param = NULL;
	zval *moduleName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

		zephir_get_strval(moduleName, moduleName_param);


	zephir_update_property_this(this_ptr, SL("_defaultModule"), moduleName TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the default controller name
 *
 * @param string controllerName
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultController) {

	zval *controllerName_param = NULL;
	zval *controllerName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerName_param);

		zephir_get_strval(controllerName, controllerName_param);


	zephir_update_property_this(this_ptr, SL("_defaultController"), controllerName TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the default action name
 *
 * @param string actionName
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction) {

	zval *actionName_param = NULL;
	zval *actionName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

		zephir_get_strval(actionName, actionName_param);


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
 *
 * @param array defaults
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaults) {

	zval *defaults, *namespaceName, *module, *controller, *action, *params;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaults);



	if ((Z_TYPE_P(defaults) == IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "Defaults must be an array");
		return;
	}
	ZEPHIR_OBS_VAR(namespaceName);
	if (zephir_array_isset_string_fetch(&namespaceName, defaults, SS("namespace") TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultNamespace"), namespaceName TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(module);
	if (zephir_array_isset_string_fetch(&module, defaults, SS("module") TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultModule"), module TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(controller);
	if (zephir_array_isset_string_fetch(&controller, defaults, SS("controller") TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultController"), controller TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(action);
	if (zephir_array_isset_string_fetch(&action, defaults, SS("action") TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultAction"), action TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(params);
	if (zephir_array_isset_string_fetch(&params, defaults, SS("params") TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultParams"), params TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * x
 */
PHP_METHOD(Phalcon_Mvc_Router, doRemoveExtraSlashes) {

	zval *route;

	zephir_fetch_params(0, 1, 0, &route);



	RETURN_CCTORW(route);

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
 *
 * @param string uri
 */
PHP_METHOD(Phalcon_Mvc_Router, handle) {

	zend_function *_5 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_18 = NULL;
	HashTable *_3, *_20;
	HashPosition _2, _19;
	zval *uri = NULL, *realUri = NULL, *request = NULL, *currentHostName = NULL, *routeFound = NULL, *parts = NULL, *params, *matches, *notFoundPaths, *vnamespace, *module, *controller, *action, *paramsStr, *strParams, *route = NULL, *methods = NULL, *dependencyInjector = NULL, *hostname = NULL, *regexHostName = NULL, *matched = NULL, *pattern = NULL, *handledUri = NULL, *beforeMatch = NULL, *paths = NULL, *converters = NULL, *part = NULL, *position = NULL, *matchPosition = NULL, *converter = NULL, *_0, *_1, **_4, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_14 = NULL, **_21, _22 = zval_used_for_init, *_23, *_24, *_25, *_26;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		ZEPHIR_CPY_WRT(uri, ZEPHIR_GLOBAL(global_null));
	}


	if (!(zephir_is_true(uri))) {
		ZEPHIR_INIT_VAR(realUri);
		zephir_call_method(realUri, this_ptr, "getrewriteuri");
	} else {
		ZEPHIR_CPY_WRT(realUri, uri);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_removeExtraSlashes"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(handledUri);
		zephir_call_method_p1(handledUri, this_ptr, "doremoveextraslashes", realUri);
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
	zephir_update_property_this(this_ptr, SL("_wasMatched"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_matchedRoute"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_1, &_3, &_2, 0, 1);
	for (
		; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		; zend_hash_move_backwards_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(route, _4);
		ZEPHIR_INIT_NVAR(methods);
		zephir_call_method_cache(methods, route, "gethttpmethods", &_5);
		if ((Z_TYPE_P(methods) != IS_NULL)) {
			if ((Z_TYPE_P(request) == IS_NULL)) {
				ZEPHIR_OBS_NVAR(_6);
				zephir_read_property_this(&_6, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				ZEPHIR_CPY_WRT(dependencyInjector, _6);
				if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service");
					return;
				}
				ZEPHIR_INIT_NVAR(_7);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_STRING(_8, "request", 1);
				zephir_call_method_p1_cache(_7, dependencyInjector, "getshared", &_9, _8);
				ZEPHIR_CPY_WRT(request, _7);
			}
			ZEPHIR_INIT_NVAR(_7);
			zephir_call_method_p1_cache(_7, request, "ismethod", &_10, methods);
			if (ZEPHIR_IS_FALSE(_7)) {
				continue;
			}
		}
		ZEPHIR_INIT_NVAR(hostname);
		zephir_call_method_cache(hostname, route, "gethostname", &_11);
		if ((Z_TYPE_P(hostname) != IS_NULL)) {
			if ((Z_TYPE_P(request) == IS_NULL)) {
				ZEPHIR_OBS_NVAR(_6);
				zephir_read_property_this(&_6, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				ZEPHIR_CPY_WRT(dependencyInjector, _6);
				if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service");
					return;
				}
				ZEPHIR_INIT_NVAR(_7);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_STRING(_8, "request", 1);
				zephir_call_method_p1_cache(_7, dependencyInjector, "getshared", &_12, _8);
				ZEPHIR_CPY_WRT(request, _7);
			}
			if ((Z_TYPE_P(currentHostName) != IS_OBJECT)) {
				ZEPHIR_INIT_NVAR(currentHostName);
				zephir_call_method_cache(currentHostName, request, "gethttphost", &_13);
			}
			if ((Z_TYPE_P(currentHostName) != IS_NULL)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(matched);
			if (zephir_memnstr_str(hostname, SL("("), "phalcon/mvc/router.zep", 426)) {
				if (zephir_memnstr_str(hostname, SL("#"), "phalcon/mvc/router.zep", 427)) {
					ZEPHIR_INIT_LNVAR(_14);
					ZEPHIR_CONCAT_SV(_14, "#^", hostname);
					ZEPHIR_INIT_NVAR(regexHostName);
					ZEPHIR_CONCAT_VS(regexHostName, _14, "$#");
				} else {
					ZEPHIR_CPY_WRT(regexHostName, hostname);
				}
				zephir_call_func_p2(matched, "preg_match", regexHostName, currentHostName);
			} else {
				ZVAL_BOOL(matched, ZEPHIR_IS_EQUAL(currentHostName, hostname));
			}
			if (!(zephir_is_true(matched))) {
				continue;
			}
		}
		ZEPHIR_INIT_NVAR(pattern);
		zephir_call_method_cache(pattern, route, "getcompiledpattern", &_15);
		ZEPHIR_INIT_NVAR(routeFound);
		if (zephir_memnstr_str(pattern, SL("^"), "phalcon/mvc/router.zep", 447)) {
			Z_SET_ISREF_P(matches);
			zephir_call_func_p3(routeFound, "preg_match", pattern, handledUri, matches);
		} else {
			ZVAL_BOOL(routeFound, ZEPHIR_IS_EQUAL(pattern, handledUri));
		}
		if (zephir_is_true(routeFound)) {
			ZEPHIR_INIT_NVAR(beforeMatch);
			zephir_call_method_cache(beforeMatch, route, "getbeforematch", &_16);
			if ((Z_TYPE_P(beforeMatch) != IS_NULL)) {
				if (zephir_is_callable(beforeMatch TSRMLS_CC)) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "Before-Match callback is not callable in matched route");
					return;
				}
				ZEPHIR_INIT_NVAR(routeFound);
				zephir_call_func_p3(routeFound, "beforematch", handledUri, route, this_ptr);
			}
		}
		if (zephir_is_true(routeFound)) {
			ZEPHIR_INIT_NVAR(paths);
			zephir_call_method_cache(paths, route, "getpaths", &_17);
			ZEPHIR_CPY_WRT(parts, paths);
			if ((Z_TYPE_P(matches) == IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(converters);
				zephir_call_method_cache(converters, route, "getconverters", &_18);
				zephir_is_iterable(paths, &_20, &_19, 0, 0);
				for (
					; zend_hash_get_current_data_ex(_20, (void**) &_21, &_19) == SUCCESS
					; zend_hash_move_forward_ex(_20, &_19)
				) {
					ZEPHIR_GET_HMKEY(part, _20, _19);
					ZEPHIR_GET_HVALUE(position, _21);
					ZEPHIR_OBS_NVAR(matchPosition);
					if (zephir_array_isset_fetch(&matchPosition, matches, position TSRMLS_CC)) {
						if ((Z_TYPE_P(converters) == IS_ARRAY)) {
							ZEPHIR_OBS_NVAR(converter);
							if (zephir_array_isset_fetch(&converter, converters, part TSRMLS_CC)) {
								ZEPHIR_INIT_NVAR(_7);
								zephir_call_func_p1(_7, "converter", matchPosition);
								zephir_array_update_zval(&parts, part, &_7, PH_COPY | PH_SEPARATE);
								continue;
							}
						}
						zephir_array_update_zval(&parts, part, &matchPosition, PH_COPY | PH_SEPARATE);
					} else {
						if ((Z_TYPE_P(converters) == IS_ARRAY)) {
							ZEPHIR_OBS_NVAR(converter);
							if (zephir_array_isset_fetch(&converter, converters, part TSRMLS_CC)) {
								ZEPHIR_INIT_NVAR(_8);
								zephir_call_func_p1(_8, "converter", matchPosition);
								zephir_array_update_zval(&parts, part, &_8, PH_COPY | PH_SEPARATE);
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
		zephir_update_property_this(this_ptr, SL("_wasMatched"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_wasMatched"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (!(zephir_is_true(routeFound))) {
		ZEPHIR_OBS_VAR(notFoundPaths);
		zephir_read_property_this(&notFoundPaths, this_ptr, SL("_notFoundPaths"), PH_NOISY_CC);
		if ((Z_TYPE_P(notFoundPaths) != IS_NULL)) {
			ZEPHIR_CPY_WRT(parts, notFoundPaths);
			ZEPHIR_INIT_BNVAR(routeFound);
			ZVAL_BOOL(routeFound, 1);
		}
	}
	if (zephir_is_true(routeFound)) {
		ZEPHIR_OBS_VAR(vnamespace);
		if (zephir_array_isset_string_fetch(&vnamespace, parts, SS("namespace") TSRMLS_CC)) {
			if (!(zephir_is_numeric(vnamespace))) {
				zephir_update_property_this(this_ptr, SL("_namespace"), vnamespace TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("namespace"), PH_SEPARATE);
		} else {
			ZEPHIR_OBS_NVAR(_6);
			zephir_read_property_this(&_6, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_namespace"), _6 TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(module);
		if (zephir_array_isset_string_fetch(&module, parts, SS("module") TSRMLS_CC)) {
			if (!(zephir_is_numeric(module))) {
				zephir_update_property_this(this_ptr, SL("_module"), module TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("module"), PH_SEPARATE);
		} else {
			ZEPHIR_OBS_NVAR(_6);
			zephir_read_property_this(&_6, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_module"), _6 TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(controller);
		if (zephir_array_isset_string_fetch(&controller, parts, SS("controller") TSRMLS_CC)) {
			if (!(zephir_is_numeric(controller))) {
				zephir_update_property_this(this_ptr, SL("_controller"), controller TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("controller"), PH_SEPARATE);
		} else {
			ZEPHIR_OBS_NVAR(_6);
			zephir_read_property_this(&_6, this_ptr, SL("_defaultController"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_controller"), _6 TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(action);
		if (zephir_array_isset_string_fetch(&action, parts, SS("action") TSRMLS_CC)) {
			if (!(zephir_is_numeric(action))) {
				zephir_update_property_this(this_ptr, SL("_action"), action TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("action"), PH_SEPARATE);
		} else {
			ZEPHIR_OBS_NVAR(_6);
			zephir_read_property_this(&_6, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_action"), _6 TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(paramsStr);
		if (zephir_array_isset_string_fetch(&paramsStr, parts, SS("params") TSRMLS_CC)) {
			ZEPHIR_SINIT_VAR(_22);
			ZVAL_LONG(&_22, 1);
			ZEPHIR_INIT_VAR(strParams);
			zephir_call_func_p2(strParams, "substr", paramsStr, &_22);
			if (zephir_is_true(strParams)) {
				ZEPHIR_SINIT_NVAR(_22);
				ZVAL_STRING(&_22, "/", 0);
				ZEPHIR_INIT_BNVAR(params);
				zephir_call_func_p2(params, "explode", &_22, strParams);
			}
			zephir_array_unset_string(&parts, SS("params"), PH_SEPARATE);
		}
		if (zephir_fast_count_int(params TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_7);
			zephir_fast_array_merge(_7, &(params), &(parts) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_params"), _7 TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_params"), parts TSRMLS_CC);
		}
	} else {
		ZEPHIR_OBS_NVAR(_6);
		zephir_read_property_this(&_6, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_namespace"), _6 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_23);
		zephir_read_property_this(&_23, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_module"), _23 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_24);
		zephir_read_property_this(&_24, this_ptr, SL("_defaultController"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_controller"), _24 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_25);
		zephir_read_property_this(&_25, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_action"), _25 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_26);
		zephir_read_property_this(&_26, this_ptr, SL("_defaultParams"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_params"), _26 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a route to the router without any HTTP constraint
 *
 *<code>
 * $router->add('/about', 'About::index');
 *</code>
 *
 * @param string pattern
 * @param string/array paths
 * @param string httpMethods
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, add) {

	zval *pattern_param = NULL, *paths = NULL, *httpMethods = NULL, *route;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &httpMethods);

		zephir_get_strval(pattern, pattern_param);
	if (!paths) {
		ZEPHIR_CPY_WRT(paths, ZEPHIR_GLOBAL(global_null));
	}
	if (!httpMethods) {
		ZEPHIR_CPY_WRT(httpMethods, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(route);
	object_init_ex(route, phalcon_mvc_router_route_ce);
	zephir_call_method_p3_noret(route, "__construct", pattern, paths, httpMethods);
	zephir_update_property_array_append(this_ptr, SL("_routes"), route TSRMLS_CC);
	RETURN_CCTOR(route);

}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addGet) {

	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

		zephir_get_strval(pattern, pattern_param);
	if (!paths) {
		ZEPHIR_CPY_WRT(paths, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "GET", 1);
	zephir_call_method_p3(return_value, this_ptr, "add", pattern, paths, _0);
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addPost) {

	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

		zephir_get_strval(pattern, pattern_param);
	if (!paths) {
		ZEPHIR_CPY_WRT(paths, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "POST", 1);
	zephir_call_method_p3(return_value, this_ptr, "add", pattern, paths, _0);
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addPut) {

	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

		zephir_get_strval(pattern, pattern_param);
	if (!paths) {
		ZEPHIR_CPY_WRT(paths, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "PUT", 1);
	zephir_call_method_p3(return_value, this_ptr, "add", pattern, paths, _0);
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addPatch) {

	zval *pattern, *paths = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		ZEPHIR_CPY_WRT(paths, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "PATCH", 1);
	zephir_call_method_p3(return_value, this_ptr, "add", pattern, paths, _0);
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addDelete) {

	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

		zephir_get_strval(pattern, pattern_param);
	if (!paths) {
		ZEPHIR_CPY_WRT(paths, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "DELETE", 1);
	zephir_call_method_p3(return_value, this_ptr, "add", pattern, paths, _0);
	RETURN_MM();

}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addOptions) {

	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

		zephir_get_strval(pattern, pattern_param);
	if (!paths) {
		ZEPHIR_CPY_WRT(paths, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "OPTIONS", 1);
	zephir_call_method_p3(return_value, this_ptr, "add", pattern, paths, _0);
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addHead) {

	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

		zephir_get_strval(pattern, pattern_param);
	if (!paths) {
		ZEPHIR_CPY_WRT(paths, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HEAD", 1);
	zephir_call_method_p3(return_value, this_ptr, "add", pattern, paths, _0);
	RETURN_MM();

}

/**
 * Mounts a group of routes in the router
 *
 * @param Phalcon\Mvc\Router\Group route
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, mount) {

	zend_function *_3 = NULL, *_7 = NULL;
	HashTable *_1, *_5;
	HashPosition _0, _4;
	zval *group, *groupRoutes, *beforeMatch, *hostname, *routes, *route = NULL, **_2, **_6, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);



	if ((Z_TYPE_P(group) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "The group of routes is not valid");
		return;
	}
	ZEPHIR_INIT_VAR(groupRoutes);
	zephir_call_method(groupRoutes, group, "getroutes");
	if (!(zephir_fast_count_int(groupRoutes TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "The group of routes does not contain any routes");
		return;
	}
	ZEPHIR_INIT_VAR(beforeMatch);
	zephir_call_method(beforeMatch, group, "getbeforematch");
	if ((Z_TYPE_P(beforeMatch) != IS_NULL)) {
		zephir_is_iterable(groupRoutes, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(route, _2);
			zephir_call_method_p1_cache_noret(route, "beforematch", &_3, beforeMatch);
		}
	}
	ZEPHIR_INIT_VAR(hostname);
	zephir_call_method(hostname, group, "gethostname");
	if ((Z_TYPE_P(hostname) != IS_NULL)) {
		zephir_is_iterable(groupRoutes, &_5, &_4, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
			; zend_hash_move_forward_ex(_5, &_4)
		) {
			ZEPHIR_GET_HVALUE(route, _6);
			zephir_call_method_p1_cache_noret(route, "sethostname", &_7, hostname);
		}
	}
	ZEPHIR_OBS_VAR(routes);
	zephir_read_property_this(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	if ((Z_TYPE_P(routes) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_8);
		zephir_fast_array_merge(_8, &(routes), &(groupRoutes) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_routes"), _8 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_routes"), groupRoutes TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Set a group of paths to be returned when none of the defined routes are matched
 *
 * @param array paths
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, notFound) {

	zval *paths;

	zephir_fetch_params(0, 1, 0, &paths);



	if ((Z_TYPE_P(paths) != IS_ARRAY)) {
		if ((Z_TYPE_P(paths) != IS_STRING)) {
			ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_router_exception_ce, "The not-found paths must be an array or string");
			return;
		}
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
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName) {


	RETURN_MEMBER(this_ptr, "_namespace");

}

/**
 * Returns the processed module name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getModuleName) {


	RETURN_MEMBER(this_ptr, "_module");

}

/**
 * Returns the processed controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getControllerName) {


	RETURN_MEMBER(this_ptr, "_controller");

}

/**
 * Returns the processed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getActionName) {


	RETURN_MEMBER(this_ptr, "_action");

}

/**
 * Returns the processed parameters
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getParams) {


	RETURN_MEMBER(this_ptr, "_params");

}

/**
 * Returns the route that matchs the handled URI
 *
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute) {


	RETURN_MEMBER(this_ptr, "_matchedRoute");

}

/**
 * Returns the sub expressions in the regular expression matched
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatches) {


	RETURN_MEMBER(this_ptr, "_matches");

}

/**
 * Checks if the router macthes any of the defined routes
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Router, wasMatched) {


	RETURN_MEMBER(this_ptr, "_wasMatched");

}

/**
 * Returns all the routes defined in the router
 *
 * @return Phalcon\Mvc\Router\Route[]
 */
PHP_METHOD(Phalcon_Mvc_Router, getRoutes) {


	RETURN_MEMBER(this_ptr, "_routes");

}

/**
 * Returns a route object by its id
 *
 * @param string id
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteById) {

	zend_function *_5 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *id, *route = NULL, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(route, _3);
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_method_cache(_4, route, "getrouteid", &_5);
		if (ZEPHIR_IS_EQUAL(_4, id)) {
			RETURN_CCTOR(route);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Returns a route object by its name
 *
 * @param string name
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName) {

	zend_function *_5 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *name, *route = NULL, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(route, _3);
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_method_cache(_4, route, "getname", &_5);
		if (ZEPHIR_IS_EQUAL(_4, name)) {
			RETURN_CCTOR(route);
		}
	}
	RETURN_MM_NULL();

}

