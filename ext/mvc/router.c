
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/hash.h"

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
 *  $router->add(
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


/**
 * Phalcon\Mvc\Router initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Router){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, Router, mvc_router, phalcon_mvc_router_method_entry, 0);

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
	zend_declare_property_bool(phalcon_mvc_router_ce, SL("_isExactControllerName"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_router_ce, SL("URI_SOURCE_GET_URL"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_router_ce, SL("URI_SOURCE_SERVER_REQUEST_URI"), 1 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_router_ce TSRMLS_CC, 2, phalcon_mvc_routerinterface_ce, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Router constructor
 *
 * @param boolean $defaultRoutes
 */
PHP_METHOD(Phalcon_Mvc_Router, __construct){

	zval *default_routes = NULL, *routes, *paths = NULL, *action_pattern;
	zval *route = NULL, *params_pattern, *params;

	PHALCON_MM_GROW();

	phalcon_update_property_empty_array(phalcon_mvc_router_ce, this_ptr, SL("_defaultParams") TSRMLS_CC);

	phalcon_fetch_params(1, 0, 1, &default_routes);

	if (!default_routes) {
		PHALCON_INIT_VAR(default_routes);
		ZVAL_TRUE(default_routes);
	}

	PHALCON_INIT_VAR(routes);
	array_init(routes);
	if (PHALCON_IS_TRUE(default_routes)) {

		/**
		 * Two routes are added by default to match /:controller/:action and
		 * /:controller/:action/:params
		 */
		PHALCON_INIT_VAR(paths);
		array_init_size(paths, 1);
		add_assoc_long_ex(paths, ISS(controller), 1);

		PHALCON_INIT_VAR(action_pattern);
		ZVAL_STRING(action_pattern, "#^/([a-zA-Z0-9_-]++)/?+$#", 1);

		PHALCON_INIT_VAR(route);
		object_init_ex(route, phalcon_mvc_router_route_ce);
		phalcon_call_method_p2_noret(route, "__construct", action_pattern, paths);

		phalcon_array_append(&routes, route, 0);

		PHALCON_INIT_NVAR(paths);
		array_init_size(paths, 3);
		add_assoc_long_ex(paths, ISS(controller), 1);
		add_assoc_long_ex(paths, ISS(action), 2);
		add_assoc_long_ex(paths, ISS(params), 3);

		PHALCON_INIT_VAR(params_pattern);
		ZVAL_STRING(params_pattern, "#^/([a-zA-Z0-9_-]++)/([a-zA-Z0-9\\._]++)(/.*+)?+$#", 1);

		PHALCON_INIT_NVAR(route);
		object_init_ex(route, phalcon_mvc_router_route_ce);
		phalcon_call_method_p2_noret(route, "__construct", params_pattern, paths);

		phalcon_array_append(&routes, route, 0);
	}

	PHALCON_INIT_VAR(params);
	array_init(params);
	phalcon_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_routes"), routes TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Router, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);

	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Get rewrite info. This info is read from $_GET['_url']. This returns '/' if the rewrite information cannot be read
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getRewriteUri){

	zval *uri_source, *_GET, *url = NULL, *_SERVER, *url_parts;
	zval *real_uri;

	PHALCON_MM_GROW();

	/**
	 * The developer can change the URI source
	 */
	PHALCON_OBS_VAR(uri_source);
	phalcon_read_property_this(&uri_source, this_ptr, SL("_uriSource"), PH_NOISY_CC);

	/**
	 * By default we use $_GET['url'] to obtain the rewrite information
	 */
	if (!zend_is_true(uri_source)) {
		phalcon_get_global(&_GET, SS("_GET") TSRMLS_CC);
		if (phalcon_array_isset_string(_GET, SS("_url"))) {

			PHALCON_OBS_VAR(url);
			phalcon_array_fetch_string(&url, _GET, SL("_url"), PH_NOISY);
			if (PHALCON_IS_NOT_EMPTY(url)) {
				RETURN_CCTOR(url);
			}
		}
	} else {
		/**
		 * Otherwise use the standard $_SERVER['REQUEST_URI']
		 */
		phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		if (phalcon_array_isset_string(_SERVER, SS("REQUEST_URI"))) {

			PHALCON_OBS_NVAR(url);
			phalcon_array_fetch_string(&url, _SERVER, SL("REQUEST_URI"), PH_NOISY);

			PHALCON_INIT_VAR(url_parts);
			phalcon_fast_explode_str(url_parts, SL("?"), url);

			PHALCON_OBS_VAR(real_uri);
			phalcon_array_fetch_long(&real_uri, url_parts, 0, PH_NOISY);
			if (PHALCON_IS_NOT_EMPTY(real_uri)) {
				RETURN_CCTOR(real_uri);
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
 * @param string $uriSource
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setUriSource){

	zval *uri_source;

	phalcon_fetch_params(0, 1, 0, &uri_source);

	phalcon_update_property_this(this_ptr, SL("_uriSource"), uri_source TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Set whether router must remove the extra slashes in the handled routes
 *
 * @param boolean $remove
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes){

	zval *remove;

	phalcon_fetch_params(0, 1, 0, &remove);

	phalcon_update_property_this(this_ptr, SL("_removeExtraSlashes"), remove TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Sets the name of the default namespace
 *
 * @param string $namespaceName
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace){

	zval *namespace_name;

	phalcon_fetch_params(0, 1, 0, &namespace_name);

	phalcon_update_property_this(this_ptr, SL("_defaultNamespace"), namespace_name TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the name of the default namespace
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaultNamespace){

	RETURN_MEMBER(this_ptr, "_defaultNamespace");
}

/**
 * Sets the name of the default module
 *
 * @param string $moduleName
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule){

	zval *module_name;

	phalcon_fetch_params(0, 1, 0, &module_name);

	phalcon_update_property_this(this_ptr, SL("_defaultModule"), module_name TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the name of the default module
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaultModule){

	RETURN_MEMBER(this_ptr, "_defaultModule");
}

/**
 * Sets the default controller name
 *
 * @param string $controllerName
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultController){

	zval *controller_name;

	phalcon_fetch_params(0, 1, 0, &controller_name);

	phalcon_update_property_this(this_ptr, SL("_defaultController"), controller_name TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the default controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaultController){

	RETURN_MEMBER(this_ptr, "_defaultController");
}

/**
 * Sets the default action name
 *
 * @param string $actionName
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction){

	zval *action_name;

	phalcon_fetch_params(0, 1, 0, &action_name);

	phalcon_update_property_this(this_ptr, SL("_defaultAction"), action_name TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the default action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaultAction){

	RETURN_MEMBER(this_ptr, "_defaultAction");
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
 * @param array $defaults
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaults){

	zval *defaults, *namespace_name, *module_name;
	zval *controller_name, *action_name, *params;

	phalcon_fetch_params(0, 1, 0, &defaults);

	if (Z_TYPE_P(defaults) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_router_exception_ce, "Defaults must be an array");
		return;
	}

	/**
	 * Set a default namespace
	 */
	if (phalcon_array_isset_string_fetch(&namespace_name, defaults, SS("namespace"))) {
		phalcon_update_property_this(this_ptr, SL("_defaultNamespace"), namespace_name TSRMLS_CC);
	}

	/**
	 * Set a default module
	 */
	if (phalcon_array_isset_string_fetch(&module_name, defaults, SS("module"))) {
		phalcon_update_property_this(this_ptr, SL("_defaultModule"), module_name TSRMLS_CC);
	}

	/**
	 * Set a default controller
	 */
	if (phalcon_array_isset_string_fetch(&controller_name, defaults, SS("controller"))) {
		phalcon_update_property_this(this_ptr, SL("_defaultController"), controller_name TSRMLS_CC);
	}

	/**
	 * Set a default action
	 */
	if (phalcon_array_isset_string_fetch(&action_name, defaults, SS("action"))) {
		phalcon_update_property_this(this_ptr, SL("_defaultAction"), action_name TSRMLS_CC);
	}

	/**
	 * Set default parameters
	 */
	if (phalcon_array_isset_string_fetch(&params, defaults, SS("params"))) {
		phalcon_update_property_this(this_ptr, SL("_defaultParams"), params TSRMLS_CC);
	}

	RETURN_THISW();
}

/**
 * Returns an array of default paths
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaults){

	zval *namespace_name, *module_name;
	zval *controller_name, *action_name, *params;

	namespace_name = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
	module_name = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	controller_name = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultController"), PH_NOISY_CC);
	action_name  = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY_CC);
	params = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultParams"), PH_NOISY_CC);

	array_init_size(return_value, 5);

	phalcon_array_update_string(&return_value, ISL(namespace), &namespace_name, PH_COPY);
	phalcon_array_update_string(&return_value, ISL(module), &module_name, PH_COPY);
	phalcon_array_update_string(&return_value, ISL(controller), &controller_name, PH_COPY);
	phalcon_array_update_string(&return_value, ISL(action), &action_name, PH_COPY);
	phalcon_array_update_string(&return_value, ISL(params), &params, PH_COPY);
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
 * @param string $uri
 */
PHP_METHOD(Phalcon_Mvc_Router, handle){

	zval *uri = NULL, *real_uri = NULL;
	zval *handled_uri = NULL, *request = NULL, *current_host_name = NULL;
	zval *route_found = NULL, *parts = NULL, *params = NULL, *matches, *routes;
	zval *route = NULL, *methods = NULL;
	zval *service, *match_method = NULL, *hostname = NULL, *regex_host_name = NULL;
	zval *matched = NULL, *pattern = NULL, *before_match = NULL, *before_match_params = NULL;
	zval *paths = NULL, *converters = NULL, *position = NULL, *part = NULL;
	zval *parameters = NULL, *converted_part = NULL;
	zval *namespace, *module, *controller;
	zval *action, *params_str, *str_params;
	zval *params_merge = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	zval *dependency_injector, *tmp;
	zval *match_position = NULL, *converter = NULL;
	zval *exact = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &uri);

	if (!uri || !zend_is_true(uri)) {
		/**
		 * If 'uri' isn't passed as parameter it reads $_GET['_url']
		 */
		PHALCON_INIT_VAR(real_uri);
		phalcon_call_method(real_uri, this_ptr, "getrewriteuri");
	} else {
		real_uri = uri;
	}

	/**
	 * Remove extra slashes in the route
	 */
	tmp = phalcon_fetch_property_this(this_ptr, SL("_removeExtraSlashes"), PH_NOISY_CC);
	if (tmp && zend_is_true(tmp)) {
		PHALCON_INIT_VAR(handled_uri);
		phalcon_remove_extra_slashes(handled_uri, real_uri);
	} else {
		handled_uri = real_uri;
	}

	PHALCON_INIT_VAR(current_host_name);

	PHALCON_INIT_VAR(route_found);
	ZVAL_FALSE(route_found);

	PHALCON_INIT_VAR(parts);
	array_init(parts);

	PHALCON_INIT_VAR(params);
	array_init(params);

	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "request", 1);

	PHALCON_INIT_VAR(matches);
	phalcon_update_property_bool(this_ptr, SL("_wasMatched"), 0 TSRMLS_CC);
	phalcon_update_property_null(this_ptr, SL("_matchedRoute") TSRMLS_CC);

	/**
	 * Routes are traversed in reversed order
	 */
	PHALCON_OBS_VAR(routes);
	phalcon_read_property_this(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);

	phalcon_is_iterable(routes, &ah0, &hp0, 0, 1);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HVALUE(route);

		/**
		 * Look for HTTP method constraints
		 */
		PHALCON_INIT_NVAR(methods);
		phalcon_call_method(methods, route, "gethttpmethods");
		if (Z_TYPE_P(methods) != IS_NULL) {

			/**
			 * Retrieve the request service from the container
			 */
			if (!request) {
				dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service");
					return;
				}

				PHALCON_INIT_NVAR(request);
				phalcon_call_method_p1(request, dependency_injector, "getshared", service);
				PHALCON_VERIFY_INTERFACE(request, phalcon_http_requestinterface_ce);
			}

			/**
			 * Check if the current method is allowed by the route
			 */
			PHALCON_INIT_NVAR(match_method);
			phalcon_call_method_p1(match_method, request, "ismethod", methods);
			if (PHALCON_IS_FALSE(match_method)) {
				zend_hash_move_backwards_ex(ah0, &hp0);
				continue;
			}
		}

		/**
		 * Look for hostname constraints
		 */
		PHALCON_INIT_NVAR(hostname);
		phalcon_call_method(hostname, route, "gethostname");
		if (Z_TYPE_P(hostname) != IS_NULL) {

			/**
			 * Retrieve the request service from the container
			 */
			if (!request) {
				dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service");
					return;
				}

				PHALCON_INIT_NVAR(request);
				phalcon_call_method_p1(request, dependency_injector, "getshared", service);
				PHALCON_VERIFY_INTERFACE(request, phalcon_http_requestinterface_ce);
			}

			/**
			 * Check if the current hostname is the same as the route
			 */
			if (Z_TYPE_P(current_host_name) == IS_NULL) {
				PHALCON_INIT_NVAR(current_host_name);
				phalcon_call_method(current_host_name, request, "gethttphost");
			}

			/**
			 * No HTTP_HOST, maybe in CLI mode?
			 */
			if (Z_TYPE_P(current_host_name) == IS_NULL) {
				zend_hash_move_backwards_ex(ah0, &hp0);
				continue;
			}

			/**
			 * Check if the hostname restriction is the same as the current in the route
			 */
			PHALCON_INIT_NVAR(matched);
			if (phalcon_memnstr_str(hostname, SL("("))) {
				if (!phalcon_memnstr_str(hostname, SL("#"))) {
					PHALCON_INIT_NVAR(regex_host_name);
					PHALCON_CONCAT_SVS(regex_host_name, "#^", hostname, "$#");
				} else {
					PHALCON_CPY_WRT(regex_host_name, hostname);
				}

				phalcon_preg_match(matched, NULL, regex_host_name, current_host_name, NULL TSRMLS_CC);
			} else {
				is_equal_function(matched, current_host_name, hostname TSRMLS_CC);
			}

			if (!zend_is_true(matched)) {
				zend_hash_move_backwards_ex(ah0, &hp0);
				continue;
			}
		}

		/**
		 * If the route has parentheses use preg_match
		 */
		PHALCON_INIT_NVAR(pattern);
		phalcon_call_method(pattern, route, "getcompiledpattern");

		PHALCON_INIT_NVAR(route_found);
		if (Z_TYPE_P(pattern) == IS_STRING && Z_STRLEN_P(pattern) > 3 && Z_STRVAL_P(pattern)[1] == '^') {
			phalcon_preg_match(route_found, NULL, pattern, handled_uri, matches TSRMLS_CC);
		} else {
			is_equal_function(route_found, pattern, handled_uri TSRMLS_CC);
		}

		/**
		 * Check for beforeMatch conditions
		 */
		if (zend_is_true(route_found)) {

			PHALCON_INIT_NVAR(before_match);
			phalcon_call_method(before_match, route, "getbeforematch");
			if (Z_TYPE_P(before_match) != IS_NULL) {

				/**
				 * Check first if the callback is callable
				 */
				if (!phalcon_is_callable(before_match TSRMLS_CC)) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "Before-Match callback is not callable in matched route");
					return;
				}

				/**
				 * Before-Match parameters
				 */
				PHALCON_INIT_NVAR(before_match_params);
				array_init_size(before_match_params, 3);
				phalcon_array_append(&before_match_params, handled_uri, 0);
				phalcon_array_append(&before_match_params, route, 0);
				phalcon_array_append(&before_match_params, this_ptr, 0);

				/**
				 * Call the function in the PHP userland
				 */
				PHALCON_INIT_NVAR(route_found);
				PHALCON_CALL_USER_FUNC_ARRAY(route_found, before_match, params);
			}
		}

		if (zend_is_true(route_found)) {

			/**
			 * Start from the default paths
			 */
			PHALCON_INIT_NVAR(paths);
			phalcon_call_method(paths, route, "getpaths");
			PHALCON_CPY_WRT(parts, paths);

			/**
			 * Check if the matches has variables
			 */
			if (Z_TYPE_P(matches) == IS_ARRAY) {

				/**
				 * Get the route converters if any
				 */
				PHALCON_INIT_NVAR(converters);
				phalcon_call_method(converters, route, "getconverters");

				phalcon_is_iterable(paths, &ah1, &hp1, 0, 0);

				while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {

					PHALCON_GET_HKEY(part, ah1, hp1);
					PHALCON_GET_HVALUE(position);

					if (Z_TYPE_P(part) != IS_STRING || Z_STRVAL_P(part)[0] != '\0') {
						if (phalcon_array_isset_fetch(&match_position, matches, position)) {
							/**
							 * Check if the part has a converter
							 */
							if (phalcon_array_isset_fetch(&converter, converters, part)) {
								PHALCON_INIT_NVAR(parameters);
								array_init_size(parameters, 1);
								phalcon_array_append(&parameters, match_position, 0);

								PHALCON_INIT_NVAR(converted_part);
								PHALCON_CALL_USER_FUNC_ARRAY(converted_part, converter, parameters);
								phalcon_array_update_zval(&parts, part, &converted_part, PH_COPY);
								zend_hash_move_forward_ex(ah1, &hp1);
								continue;
							}

							/**
							 * Update the parts if there is no converter
							 */
							phalcon_array_update_zval(&parts, part, &match_position, PH_COPY);
						} else {
							/**
							 * Apply the converters anyway
							 */
							if (phalcon_array_isset_fetch(&converter, converters, part)) {
								PHALCON_INIT_NVAR(parameters);
								array_init_size(parameters, 1);
								phalcon_array_append(&parameters, position, 0);

								PHALCON_INIT_NVAR(converted_part);
								PHALCON_CALL_USER_FUNC_ARRAY(converted_part, converter, parameters);
								phalcon_array_update_zval(&parts, part, &converted_part, PH_COPY);
							}
						}
					}

					zend_hash_move_forward_ex(ah1, &hp1);
				}

				/**
				 * Update the matches generated by preg_match
				 */
				phalcon_update_property_this(this_ptr, SL("_matches"), matches TSRMLS_CC);
			}

			phalcon_update_property_this(this_ptr, SL("_matchedRoute"), route TSRMLS_CC);
			break;
		}

		zend_hash_move_backwards_ex(ah0, &hp0);
	}

	/**
	 * Update the wasMatched property indicating if the route was matched
	 */
	phalcon_update_property_bool(this_ptr, SL("_wasMatched"), zend_is_true(route_found) TSRMLS_CC);

	/**
	 * The route wasn't found, try to use the not-found paths
	 */
	if (!zend_is_true(route_found)) {

		tmp = phalcon_fetch_property_this(this_ptr, SL("_notFoundPaths"), PH_NOISY_CC);
		if (tmp && Z_TYPE_P(tmp) != IS_NULL) {
			PHALCON_CPY_WRT(parts, tmp);

			PHALCON_INIT_NVAR(route_found);
			ZVAL_TRUE(route_found);
		}
	}

	if (zend_is_true(route_found)) {

		/**
		 * Check for a namespace
		 */
		if (phalcon_array_isset_string(parts, SS("namespace"))) {

			PHALCON_OBS_VAR(namespace);
			phalcon_array_fetch_string(&namespace, parts, SL("namespace"), PH_NOISY);
			if (!phalcon_is_numeric(namespace)) {
				phalcon_update_property_this(this_ptr, SL("_namespace"), namespace TSRMLS_CC);
			}

			phalcon_array_unset_string(&parts, SS("namespace"), PH_SEPARATE);
		} else {
			tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
			phalcon_update_property_this(this_ptr, SL("_namespace"), tmp TSRMLS_CC);
		}

		/**
		 * Check for a module
		 */
		if (phalcon_array_isset_string(parts, SS("module"))) {

			PHALCON_OBS_VAR(module);
			phalcon_array_fetch_string(&module, parts, SL("module"), PH_NOISY);
			if (!phalcon_is_numeric(module)) {
				phalcon_update_property_this(this_ptr, SL("_module"), module TSRMLS_CC);
			}

			phalcon_array_unset_string(&parts, SS("module"), PH_SEPARATE);
		} else {
			tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultModule"), PH_NOISY_CC);
			phalcon_update_property_this(this_ptr, SL("_module"), tmp TSRMLS_CC);
		}

		if (phalcon_array_isset_string_fetch(&exact, parts, SS("\0exact"))) {
			phalcon_update_property_this(this_ptr, SL("_isExactControllerName"), exact TSRMLS_CC);
			phalcon_array_unset_string(&parts, SS("\0exact"), PH_SEPARATE);
		}
		else {
			PHALCON_INIT_VAR(exact);
			ZVAL_FALSE(exact);
			phalcon_update_property_this(this_ptr, SL("_isExactControllerName"), exact TSRMLS_CC);
		}

		/**
		 * Check for a controller
		 */
		if (phalcon_array_isset_string(parts, SS("controller"))) {

			PHALCON_OBS_VAR(controller);
			phalcon_array_fetch_string(&controller, parts, SL("controller"), PH_NOISY);
			if (!phalcon_is_numeric(controller)) {
				phalcon_update_property_this(this_ptr, SL("_controller"), controller TSRMLS_CC);
			}

			phalcon_array_unset_string(&parts, SS("controller"), PH_SEPARATE);
		} else {
			tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultController"), PH_NOISY_CC);
			phalcon_update_property_this(this_ptr, SL("_controller"), tmp TSRMLS_CC);
		}

		/**
		 * Check for an action
		 */
		if (phalcon_array_isset_string(parts, SS("action"))) {

			PHALCON_OBS_VAR(action);
			phalcon_array_fetch_string(&action, parts, SL("action"), PH_NOISY);
			if (!phalcon_is_numeric(action)) {
				phalcon_update_property_this(this_ptr, SL("_action"), action TSRMLS_CC);
			}

			phalcon_array_unset_string(&parts, SS("action"), PH_SEPARATE);
		} else {
			tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			phalcon_update_property_this(this_ptr, SL("_action"), tmp TSRMLS_CC);
		}

		/**
		 * Check for parameters
		 */
		if (phalcon_array_isset_string(parts, SS("params"))) {

			PHALCON_OBS_VAR(params_str);
			phalcon_array_fetch_string(&params_str, parts, SL("params"), PH_NOISY);

			PHALCON_INIT_VAR(str_params);
			phalcon_substr(str_params, params_str, 1, 0);
			if (zend_is_true(str_params)) {
				zval slash;
				ZVAL_STRINGL(&slash, "/", 1, 0);

				PHALCON_INIT_NVAR(params);
				phalcon_fast_explode(params, &slash, str_params);
			}

			phalcon_array_unset_string(&parts, SS("params"), PH_SEPARATE);
		}

		if (zend_hash_num_elements(Z_ARRVAL_P(params))) {
			PHALCON_INIT_VAR(params_merge);
			phalcon_fast_array_merge(params_merge, &params, &parts TSRMLS_CC);
		} else {
			params_merge = parts;
		}

		phalcon_update_property_this(this_ptr, SL("_params"), params_merge TSRMLS_CC);
	} else {
		/**
		 * Use default values if the route hasn't matched
		 */
		tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
		phalcon_update_property_this(this_ptr, SL("_namespace"), tmp TSRMLS_CC);

		tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultModule"), PH_NOISY_CC);
		phalcon_update_property_this(this_ptr, SL("_module"), tmp TSRMLS_CC);

		tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultController"), PH_NOISY_CC);
		phalcon_update_property_this(this_ptr, SL("_controller"), tmp TSRMLS_CC);

		tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY_CC);
		phalcon_update_property_this(this_ptr, SL("_action"), tmp TSRMLS_CC);

		tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultParams"), PH_NOISY_CC);
		phalcon_update_property_this(this_ptr, SL("_params"), tmp TSRMLS_CC);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Adds a route to the router without any HTTP constraint
 *
 *<code>
 * $router->add('/about', 'About::index');
 *</code>
 *
 * @param string $pattern
 * @param string/array $paths
 * @param string $httpMethods
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, add){

	zval *pattern, *paths = NULL, *http_methods = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &pattern, &paths, &http_methods);

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}

	if (!http_methods) {
		PHALCON_INIT_VAR(http_methods);
	}

	/**
	 * Every route is internally stored as a Phalcon\Mvc\Router\Route
	 */
	object_init_ex(return_value, phalcon_mvc_router_route_ce);
	phalcon_call_method_p3_noret(return_value, "__construct", pattern, paths, http_methods);

	phalcon_update_property_array_append(this_ptr, SL("_routes"), return_value TSRMLS_CC);
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addGet){

	zval *pattern, *paths = NULL, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}

	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "GET", 1);
	phalcon_call_method_p3(return_value, this_ptr, "add", pattern, paths, method);
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addPost){

	zval *pattern, *paths = NULL, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}

	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "POST", 1);
	phalcon_call_method_p3(return_value, this_ptr, "add", pattern, paths, method);
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addPut){

	zval *pattern, *paths = NULL, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}

	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "PUT", 1);
	phalcon_call_method_p3(return_value, this_ptr, "add", pattern, paths, method);
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addPatch){

	zval *pattern, *paths = NULL, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}

	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "PATCH", 1);
	phalcon_call_method_p3(return_value, this_ptr, "add", pattern, paths, method);
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addDelete){

	zval *pattern, *paths = NULL, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}

	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "DELETE", 1);
	phalcon_call_method_p3(return_value, this_ptr, "add", pattern, paths, method);
	RETURN_MM();
}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addOptions){

	zval *pattern, *paths = NULL, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}

	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "OPTIONS", 1);
	phalcon_call_method_p3(return_value, this_ptr, "add", pattern, paths, method);
	RETURN_MM();
}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addHead){

	zval *pattern, *paths = NULL, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}

	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "HEAD", 1);
	phalcon_call_method_p3(return_value, this_ptr, "add", pattern, paths, method);
	RETURN_MM();
}

/**
 * Mounts a group of routes in the router
 *
 * @param Phalcon\Mvc\Router\Group $route
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, mount){

	zval *group, *group_routes, *before_match, *route = NULL;
	zval *hostname, *routes, *new_routes;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &group);

	if (Z_TYPE_P(group) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "The group of routes is not valid");
		return;
	}

	PHALCON_INIT_VAR(group_routes);
	phalcon_call_method(group_routes, group, "getroutes");
	if (!phalcon_fast_count_ev(group_routes TSRMLS_CC)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "The group of routes does not contain any routes");
		return;
	}

	/**
	 * Get the before-match condition
	 */
	PHALCON_INIT_VAR(before_match);
	phalcon_call_method(before_match, group, "getbeforematch");
	if (Z_TYPE_P(before_match) != IS_NULL) {

		phalcon_is_iterable(group_routes, &ah0, &hp0, 0, 0);

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

			PHALCON_GET_HVALUE(route);

			phalcon_call_method_p1_noret(route, "beforematch", before_match);

			zend_hash_move_forward_ex(ah0, &hp0);
		}

	}

	/**
	 * Get the hostname restriction
	 */
	PHALCON_INIT_VAR(hostname);
	phalcon_call_method(hostname, group, "gethostname");
	if (Z_TYPE_P(hostname) != IS_NULL) {

		phalcon_is_iterable(group_routes, &ah1, &hp1, 0, 0);

		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {

			PHALCON_GET_HVALUE(route);

			phalcon_call_method_p1_noret(route, "sethostname", hostname);

			zend_hash_move_forward_ex(ah1, &hp1);
		}

	}

	PHALCON_OBS_VAR(routes);
	phalcon_read_property_this(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	if (Z_TYPE_P(routes) == IS_ARRAY) {
		PHALCON_INIT_VAR(new_routes);
		phalcon_fast_array_merge(new_routes, &routes, &group_routes TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_routes"), new_routes TSRMLS_CC);
	} else {
		phalcon_update_property_this(this_ptr, SL("_routes"), group_routes TSRMLS_CC);
	}

	RETURN_THIS();
}

/**
 * Set a group of paths to be returned when none of the defined routes are matched
 *
 * @param array $paths
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, notFound){

	zval *paths;

	phalcon_fetch_params(0, 1, 0, &paths);

	if (Z_TYPE_P(paths) != IS_ARRAY) {
		if (Z_TYPE_P(paths) != IS_STRING) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_router_exception_ce, "The not-found paths must be an array or string");
			return;
		}
	}
	phalcon_update_property_this(this_ptr, SL("_notFoundPaths"), paths TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, clear){

	zval *empty_routes;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(empty_routes);
	array_init(empty_routes);
	phalcon_update_property_this(this_ptr, SL("_routes"), empty_routes TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Returns the processed namespace name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName){


	RETURN_MEMBER(this_ptr, "_namespace");
}

/**
 * Returns the processed module name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getModuleName){


	RETURN_MEMBER(this_ptr, "_module");
}

/**
 * Returns the processed controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getControllerName){


	RETURN_MEMBER(this_ptr, "_controller");
}

/**
 * Returns the processed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getActionName){


	RETURN_MEMBER(this_ptr, "_action");
}

/**
 * Returns the processed parameters
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getParams){


	RETURN_MEMBER(this_ptr, "_params");
}

/**
 * Returns the route that matchs the handled URI
 *
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute){


	RETURN_MEMBER(this_ptr, "_matchedRoute");
}

/**
 * Returns the sub expressions in the regular expression matched
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatches){


	RETURN_MEMBER(this_ptr, "_matches");
}

/**
 * Checks if the router macthes any of the defined routes
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Router, wasMatched){


	RETURN_MEMBER(this_ptr, "_wasMatched");
}

/**
 * Returns all the routes defined in the router
 *
 * @return Phalcon\Mvc\Router\Route[]
 */
PHP_METHOD(Phalcon_Mvc_Router, getRoutes){


	RETURN_MEMBER(this_ptr, "_routes");
}

/**
 * Returns a route object by its id
 *
 * @param string $id
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteById){

	zval *id, *routes, *route = NULL, *route_id = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &id);

	PHALCON_OBS_VAR(routes);
	phalcon_read_property_this(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);

	phalcon_is_iterable(routes, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HVALUE(route);

		PHALCON_INIT_NVAR(route_id);
		phalcon_call_method(route_id, route, "getrouteid");
		if (PHALCON_IS_EQUAL(route_id, id)) {
			RETURN_CCTOR(route);
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	RETURN_MM_FALSE;
}

/**
 * Returns a route object by its name
 *
 * @param string $name
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName){

	zval *name, *routes, *route = NULL, *route_name = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);

	PHALCON_OBS_VAR(routes);
	phalcon_read_property_this(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);

	phalcon_is_iterable(routes, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HVALUE(route);

		PHALCON_INIT_NVAR(route_name);
		phalcon_call_method(route_name, route, "getname");
		if (PHALCON_IS_EQUAL(route_name, name)) {
			RETURN_CCTOR(route);
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	RETURN_MM_FALSE;
}

/**
 * Returns whether controller name should not be mangled
 */
PHP_METHOD(Phalcon_Mvc_Router, isExactControllerName) {
	RETURN_MEMBER(this_ptr, "_isExactControllerName");
}

