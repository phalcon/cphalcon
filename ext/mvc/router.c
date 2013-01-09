
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/exception.h"
#include "kernel/string.h"

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
	zend_declare_property_bool(phalcon_mvc_router_ce, SL("_removeExtraSlashes"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

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
	zval *route = NULL, *params_pattern;

	PHALCON_MM_GROW();

	phalcon_update_property_empty_array(phalcon_mvc_router_ce, this_ptr, SL("_params") TSRMLS_CC);
	
	phalcon_update_property_empty_array(phalcon_mvc_router_ce, this_ptr, SL("_defaultParams") TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &default_routes) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!default_routes) {
		PHALCON_INIT_VAR(default_routes);
		ZVAL_BOOL(default_routes, 1);
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
		add_assoc_long_ex(paths, SS("controller"), 1);
	
		PHALCON_INIT_VAR(action_pattern);
		ZVAL_STRING(action_pattern, "#^/([a-zA-Z0-9\\_]+)[/]{0,1}$#", 1);
	
		PHALCON_INIT_VAR(route);
		object_init_ex(route, phalcon_mvc_router_route_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(route, "__construct", action_pattern, paths);
	
		phalcon_array_append(&routes, route, PH_SEPARATE TSRMLS_CC);
	
		PHALCON_INIT_NVAR(paths);
		array_init_size(paths, 3);
		add_assoc_long_ex(paths, SS("controller"), 1);
		add_assoc_long_ex(paths, SS("action"), 2);
		add_assoc_long_ex(paths, SS("params"), 3);
	
		PHALCON_INIT_VAR(params_pattern);
		ZVAL_STRING(params_pattern, "#^/([a-zA-Z0-9\\_]+)/([a-zA-Z0-9\\.\\_]+)(/.*)*$#", 1);
	
		PHALCON_INIT_NVAR(route);
		object_init_ex(route, phalcon_mvc_router_route_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(route, "__construct", params_pattern, paths);
	
		phalcon_array_append(&routes, route, PH_SEPARATE TSRMLS_CC);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_routes"), routes TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Router, setDI){

	zval *dependency_injector;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
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
PHP_METHOD(Phalcon_Mvc_Router, _getRewriteUri){

	zval *get = NULL, *url;
	zval *g0 = NULL;

	PHALCON_MM_GROW();

	phalcon_get_global(&g0, SS("_GET") TSRMLS_CC);
	PHALCON_CPY_WRT(get, g0);
	if (phalcon_array_isset_string(get, SS("_url"))) {
	
		PHALCON_OBS_VAR(url);
		phalcon_array_fetch_string(&url, get, SL("_url"), PH_NOISY_CC);
		if (PHALCON_IS_NOT_EMPTY(url)) {
			RETURN_CCTOR(url);
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_STRING("/", 1);
}

/**
 * Set whether router must remove the extra slashes in the handled routes
 *
 * @param boolean $remove
 */
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes){

	zval *remove;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &remove) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_removeExtraSlashes"), remove TSRMLS_CC);
	
}

/**
 * Sets the name of the default namespace
 *
 * @param string $namespaceName
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace){

	zval *namespace_name;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &namespace_name) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultNamespace"), namespace_name TSRMLS_CC);
	
}

/**
 * Sets the name of the default module
 *
 * @param string $moduleName
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule){

	zval *module_name;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &module_name) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultModule"), module_name TSRMLS_CC);
	
}

/**
 * Sets the default controller name
 *
 * @param string $controllerName
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultController){

	zval *controller_name;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &controller_name) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultController"), controller_name TSRMLS_CC);
	
}

/**
 * Sets the default action name
 *
 * @param string $actionName
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction){

	zval *action_name;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &action_name) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultAction"), action_name TSRMLS_CC);
	
}

/**
 * Sets an array of default paths. This defaults apply for all the routes
 *
 *<code>
 * $router->setDefaults(array(
 *		'module' => 'common',
 *		'action' => 'index'
 * ));
 *</code>
 *
 * @param array $defaults
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaults){

	zval *defaults, *namespace_name, *module_name;
	zval *controller_name, *action_name, *params;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &defaults) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(defaults) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "Defaults must be an array");
		return;
	}
	
	/** 
	 * Set a default namespace
	 */
	if (phalcon_array_isset_string(defaults, SS("namespace"))) {
		PHALCON_OBS_VAR(namespace_name);
		phalcon_array_fetch_string(&namespace_name, defaults, SL("namespace"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_defaultNamespace"), namespace_name TSRMLS_CC);
	}
	
	/** 
	 * Set a default module
	 */
	if (phalcon_array_isset_string(defaults, SS("module"))) {
		PHALCON_OBS_VAR(module_name);
		phalcon_array_fetch_string(&module_name, defaults, SL("module"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_defaultModule"), module_name TSRMLS_CC);
	}
	
	/** 
	 * Set a default controller
	 */
	if (phalcon_array_isset_string(defaults, SS("controller"))) {
		PHALCON_OBS_VAR(controller_name);
		phalcon_array_fetch_string(&controller_name, defaults, SL("controller"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_defaultController"), controller_name TSRMLS_CC);
	}
	
	/** 
	 * Set a default action
	 */
	if (phalcon_array_isset_string(defaults, SS("action"))) {
		PHALCON_OBS_VAR(action_name);
		phalcon_array_fetch_string(&action_name, defaults, SL("action"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_defaultAction"), action_name TSRMLS_CC);
	}
	
	/** 
	 * Set default parameters
	 */
	if (phalcon_array_isset_string(defaults, SS("params"))) {
		PHALCON_OBS_VAR(params);
		phalcon_array_fetch_string(&params, defaults, SL("params"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_defaultParams"), params TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Handles routing information received from the rewrite engine
 *
 *<code>
 * $router->handle('/posts/edit/1');
 *</code>
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Mvc_Router, handle){

	zval *uri = NULL, *real_uri = NULL, *remove_extra_slashes;
	zval *handled_uri = NULL, *request = NULL, *route_found = NULL, *parts = NULL;
	zval *params = NULL, *matches, *routes, *route = NULL, *methods = NULL;
	zval *dependency_injector = NULL, *service = NULL, *match_method = NULL;
	zval *pattern = NULL, *paths = NULL, *converters = NULL, *position = NULL, *part = NULL;
	zval *match_position = NULL, *parameters = NULL, *converter = NULL;
	zval *converted_part = NULL, *namespace, *default_namespace;
	zval *module, *default_module = NULL, *controller, *default_controller = NULL;
	zval *action, *default_action = NULL, *params_str, *str_params;
	zval *slash, *params_merge, *default_params;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &uri) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!uri) {
		PHALCON_INIT_VAR(uri);
	}
	
	if (!zend_is_true(uri)) {
		/** 
		 * If 'uri' isn't passed as parameter it reads $_GET['_url']
		 */
		PHALCON_INIT_VAR(real_uri);
		PHALCON_CALL_METHOD(real_uri, this_ptr, "_getrewriteuri");
	} else {
		PHALCON_CPY_WRT(real_uri, uri);
	}
	
	/** 
	 * Remove extra slashes in the route
	 */
	PHALCON_OBS_VAR(remove_extra_slashes);
	phalcon_read_property(&remove_extra_slashes, this_ptr, SL("_removeExtraSlashes"), PH_NOISY_CC);
	if (zend_is_true(remove_extra_slashes)) {
		PHALCON_INIT_VAR(handled_uri);
		phalcon_remove_extra_slashes(handled_uri, real_uri);
	} else {
		PHALCON_CPY_WRT(handled_uri, real_uri);
	}
	
	PHALCON_INIT_VAR(request);
	
	PHALCON_INIT_VAR(route_found);
	ZVAL_BOOL(route_found, 0);
	
	PHALCON_INIT_VAR(parts);
	array_init(parts);
	
	PHALCON_INIT_VAR(params);
	array_init(params);
	
	PHALCON_INIT_VAR(matches);
	phalcon_update_property_bool(this_ptr, SL("_wasMatched"), 0 TSRMLS_CC);
	
	/** 
	 * Routes are traversed in reversed order
	 */
	PHALCON_OBS_VAR(routes);
	phalcon_read_property(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(routes TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(routes);
	zend_hash_internal_pointer_end_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(route);
	
		PHALCON_INIT_NVAR(methods);
		PHALCON_CALL_METHOD(methods, route, "gethttpmethods");
		if (Z_TYPE_P(methods) != IS_NULL) {
	
			/** 
			 * Retrieve the request service from the container
			 */
			if (Z_TYPE_P(request) == IS_NULL) {
	
				PHALCON_OBS_NVAR(dependency_injector);
				phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_dispatcher_exception_ce, "A dependency injection container is required to access the 'request' service");
					return;
				}
	
				PHALCON_INIT_NVAR(service);
				ZVAL_STRING(service, "request", 1);
	
				PHALCON_INIT_NVAR(request);
				PHALCON_CALL_METHOD_PARAMS_1(request, dependency_injector, "getshared", service);
			}
	
			/** 
			 * Check if the current method is allowed by the route
			 */
			PHALCON_INIT_NVAR(match_method);
			PHALCON_CALL_METHOD_PARAMS_1(match_method, request, "ismethod", methods);
			if (PHALCON_IS_FALSE(match_method)) {
				zend_hash_move_backwards_ex(ah0, &hp0);
				continue;
			}
		}
	
		/** 
		 * If the route has parentheses use preg_match
		 */
		PHALCON_INIT_NVAR(pattern);
		PHALCON_CALL_METHOD(pattern, route, "getcompiledpattern");
		if (phalcon_memnstr_str(pattern, SL("(") TSRMLS_CC)) {
			Z_SET_ISREF_P(matches);
			PHALCON_INIT_NVAR(route_found);
			PHALCON_CALL_FUNC_PARAMS_3(route_found, "preg_match", pattern, handled_uri, matches);
			Z_UNSET_ISREF_P(matches);
		} else {
			PHALCON_INIT_NVAR(route_found);
			is_equal_function(route_found, pattern, handled_uri TSRMLS_CC);
		}
	
		if (zend_is_true(route_found)) {
	
			/** 
			 * Start from the default paths
			 */
			PHALCON_INIT_NVAR(paths);
			PHALCON_CALL_METHOD(paths, route, "getpaths");
			PHALCON_CPY_WRT(parts, paths);
	
			/** 
			 * Check if the matches has variables
			 */
			if (Z_TYPE_P(matches) == IS_ARRAY) { 
	
				/** 
				 * Get the route converters if any
				 */
				PHALCON_INIT_NVAR(converters);
				PHALCON_CALL_METHOD(converters, route, "getconverters");
	
				if (!phalcon_valid_foreach(paths TSRMLS_CC)) {
					return;
				}
	
				ah1 = Z_ARRVAL_P(paths);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
				while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
					PHALCON_GET_FOREACH_KEY(part, ah1, hp1);
					PHALCON_GET_FOREACH_VALUE(position);
	
					if (phalcon_array_isset(matches, position)) {
	
						PHALCON_OBS_NVAR(match_position);
						phalcon_array_fetch(&match_position, matches, position, PH_NOISY_CC);
	
						/** 
						 * Check if the part has a converter
						 */
						if (Z_TYPE_P(converters) == IS_ARRAY) { 
							if (phalcon_array_isset(converters, part)) {
								PHALCON_INIT_NVAR(parameters);
								array_init_size(parameters, 1);
								phalcon_array_append(&parameters, match_position, PH_SEPARATE TSRMLS_CC);
	
								PHALCON_OBS_NVAR(converter);
								phalcon_array_fetch(&converter, converters, part, PH_NOISY_CC);
	
								PHALCON_INIT_NVAR(converted_part);
								PHALCON_CALL_USER_FUNC_ARRAY(converted_part, converter, parameters);
								phalcon_array_update_zval(&parts, part, &converted_part, PH_COPY | PH_SEPARATE TSRMLS_CC);
								zend_hash_move_forward_ex(ah1, &hp1);
								continue;
							}
						}
	
						/** 
						 * Update the parts if there is no converter
						 */
						phalcon_array_update_zval(&parts, part, &match_position, PH_COPY | PH_SEPARATE TSRMLS_CC);
					} else {
						/** 
						 * Apply the converters anyway
						 */
						if (Z_TYPE_P(converters) == IS_ARRAY) { 
							if (phalcon_array_isset(converters, part)) {
								PHALCON_INIT_NVAR(parameters);
								array_init_size(parameters, 1);
								phalcon_array_append(&parameters, position, PH_SEPARATE TSRMLS_CC);
	
								PHALCON_OBS_NVAR(converter);
								phalcon_array_fetch(&converter, converters, part, PH_NOISY_CC);
	
								PHALCON_INIT_NVAR(converted_part);
								PHALCON_CALL_USER_FUNC_ARRAY(converted_part, converter, parameters);
								phalcon_array_update_zval(&parts, part, &converted_part, PH_COPY | PH_SEPARATE TSRMLS_CC);
							}
						}
					}
	
					zend_hash_move_forward_ex(ah1, &hp1);
				}
	
				/** 
				 * Update the matches generated by preg_match
				 */
				phalcon_update_property_zval(this_ptr, SL("_matches"), matches TSRMLS_CC);
			}
	
			phalcon_update_property_zval(this_ptr, SL("_matchedRoute"), route TSRMLS_CC);
			break;
		}
	
		zend_hash_move_backwards_ex(ah0, &hp0);
	}
	
	if (zend_is_true(route_found)) {
	
		/** 
		 * Check for a namespace
		 */
		if (phalcon_array_isset_string(parts, SS("namespace"))) {
			PHALCON_OBS_VAR(namespace);
			phalcon_array_fetch_string(&namespace, parts, SL("namespace"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_namespace"), namespace TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SS("namespace"));
		} else {
			PHALCON_OBS_VAR(default_namespace);
			phalcon_read_property(&default_namespace, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_namespace"), default_namespace TSRMLS_CC);
		}
	
		/** 
		 * Check for a module
		 */
		if (phalcon_array_isset_string(parts, SS("module"))) {
			PHALCON_OBS_VAR(module);
			phalcon_array_fetch_string(&module, parts, SL("module"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_module"), module TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SS("module"));
		} else {
			PHALCON_OBS_VAR(default_module);
			phalcon_read_property(&default_module, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_module"), default_module TSRMLS_CC);
		}
	
		/** 
		 * Check for a controller
		 */
		if (phalcon_array_isset_string(parts, SS("controller"))) {
			PHALCON_OBS_VAR(controller);
			phalcon_array_fetch_string(&controller, parts, SL("controller"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_controller"), controller TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SS("controller"));
		} else {
			PHALCON_OBS_VAR(default_controller);
			phalcon_read_property(&default_controller, this_ptr, SL("_defaultController"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_controller"), default_controller TSRMLS_CC);
		}
	
		/** 
		 * Check for an action
		 */
		if (phalcon_array_isset_string(parts, SS("action"))) {
			PHALCON_OBS_VAR(action);
			phalcon_array_fetch_string(&action, parts, SL("action"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_action"), action TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SS("action"));
		} else {
			PHALCON_OBS_VAR(default_action);
			phalcon_read_property(&default_action, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_action"), default_action TSRMLS_CC);
		}
	
		/** 
		 * Check for parameters
		 */
		if (phalcon_array_isset_string(parts, SS("params"))) {
	
			PHALCON_OBS_VAR(params_str);
			phalcon_array_fetch_string(&params_str, parts, SL("params"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(str_params);
			phalcon_substr(str_params, params_str, 1, 0 TSRMLS_CC);
			if (zend_is_true(str_params)) {
				PHALCON_INIT_VAR(slash);
				ZVAL_STRING(slash, "/", 1);
	
				PHALCON_INIT_NVAR(params);
				phalcon_fast_explode(params, slash, str_params TSRMLS_CC);
			}
	
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SS("params"));
		}
	
		PHALCON_INIT_VAR(params_merge);
		PHALCON_CALL_FUNC_PARAMS_2(params_merge, "array_merge", params, parts);
		phalcon_update_property_zval(this_ptr, SL("_params"), params_merge TSRMLS_CC);
		phalcon_update_property_bool(this_ptr, SL("_wasMatched"), 1 TSRMLS_CC);
	} else {
		/** 
		 * Use default values if the route hasn't matched
		 */
		PHALCON_OBS_NVAR(default_module);
		phalcon_read_property(&default_module, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_module"), default_module TSRMLS_CC);
	
		PHALCON_OBS_NVAR(default_controller);
		phalcon_read_property(&default_controller, this_ptr, SL("_defaultController"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_controller"), default_controller TSRMLS_CC);
	
		PHALCON_OBS_NVAR(default_action);
		phalcon_read_property(&default_action, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_action"), default_action TSRMLS_CC);
	
		PHALCON_OBS_VAR(default_params);
		phalcon_read_property(&default_params, this_ptr, SL("_defaultParams"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_params"), default_params TSRMLS_CC);
		phalcon_update_property_bool(this_ptr, SL("_wasMatched"), 0 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Adds a route to the router on any HTTP method
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

	zval *pattern, *paths = NULL, *http_methods = NULL, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &pattern, &paths, &http_methods) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	if (!http_methods) {
		PHALCON_INIT_VAR(http_methods);
	}
	
	/** 
	 * Every route is internally stored as a Phalcon\Mvc\Router\Route
	 */
	PHALCON_INIT_VAR(route);
	object_init_ex(route, phalcon_mvc_router_route_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(route, "__construct", pattern, paths, http_methods);
	
	phalcon_update_property_array_append(this_ptr, SL("_routes"), route TSRMLS_CC);
	RETURN_CTOR(route);
}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addGet){

	zval *pattern, *paths = NULL, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "GET", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, method);
	RETURN_CCTOR(route);
}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addPost){

	zval *pattern, *paths = NULL, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "POST", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, method);
	RETURN_CCTOR(route);
}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addPut){

	zval *pattern, *paths = NULL, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "PUT", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, method);
	RETURN_CCTOR(route);
}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addPatch){

	zval *pattern, *paths = NULL, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "PATCH", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, method);
	RETURN_CCTOR(route);
}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addDelete){

	zval *pattern, *paths = NULL, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "DELETE", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, method);
	RETURN_CCTOR(route);
}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addOptions){

	zval *pattern, *paths = NULL, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "OPTIONS", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, method);
	RETURN_CCTOR(route);
}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addHead){

	zval *pattern, *paths = NULL, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "HEAD", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, method);
	RETURN_CCTOR(route);
}

/**
 * Mounts a group of routes in the router
 *
 * @param Phalcon\Mvc\Router\Group $route
 */
PHP_METHOD(Phalcon_Mvc_Router, mount){

	zval *group, *routes, *group_routes, *new_routes;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &group) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(group) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "The group of routes is not valid");
		return;
	}
	
	PHALCON_OBS_VAR(routes);
	phalcon_read_property(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(group_routes);
	PHALCON_CALL_METHOD(group_routes, group, "getroutes");
	if (Z_TYPE_P(routes) == IS_ARRAY) { 
		PHALCON_INIT_VAR(new_routes);
		PHALCON_CALL_FUNC_PARAMS_2(new_routes, "array_merge", routes, group_routes);
		phalcon_update_property_zval(this_ptr, SL("_routes"), new_routes TSRMLS_CC);
	} else {
		phalcon_update_property_zval(this_ptr, SL("_routes"), group_routes TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, clear){

	zval *empty_routes;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(empty_routes);
	array_init(empty_routes);
	phalcon_update_property_zval(this_ptr, SL("_routes"), empty_routes TSRMLS_CC);
	
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

	zval *id, *routes, *route = NULL, *route_id = NULL, *is_equal = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &id) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(routes);
	phalcon_read_property(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(routes TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(routes);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(route);
	
		PHALCON_INIT_NVAR(route_id);
		PHALCON_CALL_METHOD(route_id, route, "getrouteid");
	
		PHALCON_INIT_NVAR(is_equal);
		is_equal_function(is_equal, route_id, id TSRMLS_CC);
		if (PHALCON_IS_TRUE(is_equal)) {
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

	zval *name, *routes, *route = NULL, *route_name = NULL, *is_equal = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(routes);
	phalcon_read_property(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(routes TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(routes);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(route);
	
		PHALCON_INIT_NVAR(route_name);
		PHALCON_CALL_METHOD(route_name, route, "getname");
	
		PHALCON_INIT_NVAR(is_equal);
		is_equal_function(is_equal, route_name, name TSRMLS_CC);
		if (PHALCON_IS_TRUE(is_equal)) {
			RETURN_CCTOR(route);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_MM_FALSE;
}

