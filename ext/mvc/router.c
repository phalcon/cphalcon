
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

#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
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
 *	$router = new Phalcon\Mvc\Router();
 *	$router->handle();
 *	echo $router->getControllerName();
 *</code>
 *
 */


/**
 * Phalcon\Mvc\Router constructor
 *
 * @param boolean $defaultRoutes
 */
PHP_METHOD(Phalcon_Mvc_Router, __construct){

	zval *default_routes = NULL, *routes, *paths = NULL, *action_pattern;
	zval *route = NULL, *params_pattern;
	zval *a0 = NULL, *a1 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_mvc_router_ce, this_ptr, SL("_params"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_mvc_router_ce, this_ptr, SL("_defaultParams"), a1 TSRMLS_CC);
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &default_routes) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!default_routes) {
		PHALCON_INIT_NVAR(default_routes);
		ZVAL_BOOL(default_routes, 1);
	}
	
	PHALCON_INIT_VAR(routes);
	array_init(routes);
	if (PHALCON_IS_TRUE(default_routes)) {
		PHALCON_INIT_VAR(paths);
		array_init(paths);
		add_assoc_long_ex(paths, SS("controller"), 1);
		
		PHALCON_INIT_VAR(action_pattern);
		ZVAL_STRING(action_pattern, "#^/([a-zA-Z0-9\\_]+)[/]{0,1}$#", 1);
		
		PHALCON_INIT_VAR(route);
		object_init_ex(route, phalcon_mvc_router_route_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(route, "__construct", action_pattern, paths, PH_CHECK);
		phalcon_array_append(&routes, route, PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_NVAR(paths);
		array_init(paths);
		add_assoc_long_ex(paths, SS("controller"), 1);
		add_assoc_long_ex(paths, SS("action"), 2);
		add_assoc_long_ex(paths, SS("params"), 3);
		
		PHALCON_INIT_VAR(params_pattern);
		ZVAL_STRING(params_pattern, "#^/([a-zA-Z0-9\\_]+)/([a-zA-Z0-9\\_]+)(/.*)*$#", 1);
		
		PHALCON_INIT_NVAR(route);
		object_init_ex(route, phalcon_mvc_router_route_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(route, "__construct", params_pattern, paths, PH_CHECK);
		phalcon_array_append(&routes, route, PH_SEPARATE TSRMLS_CC);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_routes"), routes TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DI $dependencyInjector
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
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Mvc_Router, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Get rewrite info
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, _getRewriteUri){

	zval *get = NULL, *url;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	phalcon_get_global(&g0, SL("_GET")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(get, g0);
	eval_int = phalcon_array_isset_string(get, SS("_url"));
	if (eval_int) {
		PHALCON_INIT_VAR(url);
		phalcon_array_fetch_string(&url, get, SL("_url"), PH_NOISY_CC);
		
		RETURN_CCTOR(url);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
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
 * Sets an array of default paths
 *
 * @param array $defaults
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaults){

	zval *defaults, *module_name, *controller_name;
	zval *action_name, *params;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &defaults) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(defaults) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "Defaults must be an array");
		return;
	}
	eval_int = phalcon_array_isset_string(defaults, SS("module"));
	if (eval_int) {
		PHALCON_INIT_VAR(module_name);
		phalcon_array_fetch_string(&module_name, defaults, SL("module"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_defaultModule"), module_name TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(defaults, SS("controller"));
	if (eval_int) {
		PHALCON_INIT_VAR(controller_name);
		phalcon_array_fetch_string(&controller_name, defaults, SL("controller"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_defaultController"), controller_name TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(defaults, SS("action"));
	if (eval_int) {
		PHALCON_INIT_VAR(action_name);
		phalcon_array_fetch_string(&action_name, defaults, SL("action"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_defaultAction"), action_name TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(defaults, SS("params"));
	if (eval_int) {
		PHALCON_INIT_VAR(params);
		phalcon_array_fetch_string(&params, defaults, SL("params"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_defaultParams"), params TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Handles routing information received from the rewrite engine
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Mvc_Router, handle){

	zval *uri = NULL, *real_uri = NULL, *request = NULL, *route_found = NULL, *parts = NULL;
	zval *params = NULL, *matches, *routes, *reversed_routes;
	zval *route = NULL, *methods = NULL, *dependency_injector = NULL;
	zval *service = NULL, *match_method = NULL, *pattern = NULL, *paths = NULL;
	zval *position = NULL, *part = NULL, *match_position = NULL, *module;
	zval *default_module = NULL, *controller, *default_controller = NULL;
	zval *action, *default_action = NULL, *params_str, *one;
	zval *str_params, *slash, *params_merge, *default_params;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!uri) {
		PHALCON_INIT_NVAR(uri);
	}
	
	if (!zend_is_true(uri)) {
		/** 
		 * If 'uri' isn't passed as parameter it reads $_GET['_url']
		 */
		PHALCON_INIT_VAR(real_uri);
		PHALCON_CALL_METHOD(real_uri, this_ptr, "_getrewriteuri", PH_NO_CHECK);
	} else {
		PHALCON_CPY_WRT(real_uri, uri);
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
	PHALCON_INIT_VAR(routes);
	phalcon_read_property(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(reversed_routes);
	PHALCON_CALL_FUNC_PARAMS_1(reversed_routes, "array_reverse", routes);
	
	if (!phalcon_valid_foreach(reversed_routes TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(reversed_routes);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(route);
		
		PHALCON_INIT_NVAR(methods);
		PHALCON_CALL_METHOD(methods, route, "gethttpmethods", PH_NO_CHECK);
		if (Z_TYPE_P(methods) != IS_NULL) {
			if (Z_TYPE_P(request) == IS_NULL) {
				PHALCON_INIT_NVAR(dependency_injector);
				phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_dispatcher_exception_ce, "A dependency injection container is required to access the 'request' service");
					return;
				}
				
				PHALCON_INIT_NVAR(service);
				ZVAL_STRING(service, "request", 1);
				
				PHALCON_INIT_NVAR(request);
				PHALCON_CALL_METHOD_PARAMS_1(request, dependency_injector, "getshared", service, PH_NO_CHECK);
			}
			
			PHALCON_INIT_NVAR(match_method);
			PHALCON_CALL_METHOD_PARAMS_1(match_method, request, "ismethod", methods, PH_NO_CHECK);
			if (PHALCON_IS_FALSE(match_method)) {
				zend_hash_move_forward_ex(ah0, &hp0);
				goto ph_cycle_start_0;
			}
		}
		
		/** 
		 * If the route has parentheses use preg_match
		 */
		PHALCON_INIT_NVAR(pattern);
		PHALCON_CALL_METHOD(pattern, route, "getcompiledpattern", PH_NO_CHECK);
		if (phalcon_memnstr_str(pattern, SL("(") TSRMLS_CC)) {
			Z_SET_ISREF_P(matches);
			PHALCON_INIT_NVAR(route_found);
			PHALCON_CALL_FUNC_PARAMS_3(route_found, "preg_match", pattern, real_uri, matches);
			Z_UNSET_ISREF_P(matches);
		} else {
			PHALCON_INIT_NVAR(route_found);
			is_equal_function(route_found, pattern, real_uri TSRMLS_CC);
		}
		
		if (zend_is_true(route_found)) {
			PHALCON_INIT_NVAR(paths);
			PHALCON_CALL_METHOD(paths, route, "getpaths", PH_NO_CHECK);
			PHALCON_CPY_WRT(parts, paths);
			if (Z_TYPE_P(matches) == IS_ARRAY) { 
				
				if (!phalcon_valid_foreach(paths TSRMLS_CC)) {
					return;
				}
				
				ah1 = Z_ARRVAL_P(paths);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				
				ph_cycle_start_1:
				
					if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
						goto ph_cycle_end_1;
					}
					
					PHALCON_GET_FOREACH_KEY(part, ah1, hp1);
					PHALCON_GET_FOREACH_VALUE(position);
					
					eval_int = phalcon_array_isset(matches, position);
					if (eval_int) {
						PHALCON_INIT_NVAR(match_position);
						phalcon_array_fetch(&match_position, matches, position, PH_NOISY_CC);
						phalcon_array_update_zval(&parts, part, &match_position, PH_COPY | PH_SEPARATE TSRMLS_CC);
					}
					
					zend_hash_move_forward_ex(ah1, &hp1);
					goto ph_cycle_start_1;
					
				ph_cycle_end_1:
				
				phalcon_update_property_zval(this_ptr, SL("_matches"), matches TSRMLS_CC);
			}
			
			phalcon_update_property_zval(this_ptr, SL("_matchedRoute"), route TSRMLS_CC);
			goto ph_cycle_end_0;
		}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
		
	ph_cycle_end_0:
	
	if (zend_is_true(route_found)) {
		eval_int = phalcon_array_isset_string(parts, SS("module"));
		if (eval_int) {
			PHALCON_INIT_VAR(module);
			phalcon_array_fetch_string(&module, parts, SL("module"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_module"), module TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SS("module"));
		} else {
			PHALCON_INIT_VAR(default_module);
			phalcon_read_property(&default_module, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_module"), default_module TSRMLS_CC);
		}
		eval_int = phalcon_array_isset_string(parts, SS("controller"));
		if (eval_int) {
			PHALCON_INIT_VAR(controller);
			phalcon_array_fetch_string(&controller, parts, SL("controller"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_controller"), controller TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SS("controller"));
		} else {
			PHALCON_INIT_VAR(default_controller);
			phalcon_read_property(&default_controller, this_ptr, SL("_defaultController"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_controller"), default_controller TSRMLS_CC);
		}
		
		eval_int = phalcon_array_isset_string(parts, SS("action"));
		if (eval_int) {
			PHALCON_INIT_VAR(action);
			phalcon_array_fetch_string(&action, parts, SL("action"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_action"), action TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SS("action"));
		} else {
			PHALCON_INIT_VAR(default_action);
			phalcon_read_property(&default_action, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_action"), default_action TSRMLS_CC);
		}
		
		eval_int = phalcon_array_isset_string(parts, SS("params"));
		if (eval_int) {
			PHALCON_INIT_VAR(params_str);
			phalcon_array_fetch_string(&params_str, parts, SL("params"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(one);
			ZVAL_LONG(one, 1);
			
			PHALCON_INIT_VAR(str_params);
			PHALCON_CALL_FUNC_PARAMS_2(str_params, "substr", params_str, one);
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
		PHALCON_INIT_NVAR(default_module);
		phalcon_read_property(&default_module, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_module"), default_module TSRMLS_CC);
		
		PHALCON_INIT_NVAR(default_controller);
		phalcon_read_property(&default_controller, this_ptr, SL("_defaultController"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_controller"), default_controller TSRMLS_CC);
		
		PHALCON_INIT_NVAR(default_action);
		phalcon_read_property(&default_action, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_action"), default_action TSRMLS_CC);
		
		PHALCON_INIT_VAR(default_params);
		phalcon_read_property(&default_params, this_ptr, SL("_defaultParams"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_params"), default_params TSRMLS_CC);
		phalcon_update_property_bool(this_ptr, SL("_wasMatched"), 0 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Adds a route to the router on any HTTP method
 *
 * @param string $pattern
 * @param string/array $paths
 * @param string $httpMethods
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, add){

	zval *pattern, *paths = NULL, *http_methods = NULL, *route;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &pattern, &paths, &http_methods) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_INIT_NVAR(paths);
	}
	
	if (!http_methods) {
		PHALCON_INIT_NVAR(http_methods);
	}
	
	/** 
	 * Every route is internally stored as a Phalcon\Mvc\Router\Route
	 */
	PHALCON_INIT_VAR(route);
	object_init_ex(route, phalcon_mvc_router_route_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(route, "__construct", pattern, paths, http_methods, PH_CHECK);
	
	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_routes"), PH_NOISY_CC);
	phalcon_array_append(&t0, route, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_routes"), t0 TSRMLS_CC);
	
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
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_INIT_NVAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "GET", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, method, PH_NO_CHECK);
	
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
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_INIT_NVAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "POST", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, method, PH_NO_CHECK);
	
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
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_INIT_NVAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "PUT", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, method, PH_NO_CHECK);
	
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
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_INIT_NVAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "DELETE", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, method, PH_NO_CHECK);
	
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
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_INIT_NVAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "OPTIONS", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, method, PH_NO_CHECK);
	
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
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_INIT_NVAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "HEAD", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, method, PH_NO_CHECK);
	
	RETURN_CCTOR(route);
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
 * Returns processed module name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getModuleName){


	RETURN_MEMBER(this_ptr, "_module");
}

/**
 * Returns processed controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getControllerName){


	RETURN_MEMBER(this_ptr, "_controller");
}

/**
 * Returns processed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getActionName){


	RETURN_MEMBER(this_ptr, "_action");
}

/**
 * Returns processed extra params
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
 * Return the sub expressions in the regular expression matched
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatches){


	RETURN_MEMBER(this_ptr, "_matches");
}

/**
 * Check if the router macthes any of the defined routes
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Router, wasMatched){


	RETURN_MEMBER(this_ptr, "_wasMatched");
}

/**
 * Return all the routes defined in the router
 *
 * @return Phalcon\Mvc\Router\Route[]
 */
PHP_METHOD(Phalcon_Mvc_Router, getRoutes){


	RETURN_MEMBER(this_ptr, "_routes");
}

/**
 * Returns a route object by its id
 *
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteById){

	zval *id, *routes, *route = NULL, *route_id = NULL, *is_equal = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &id) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(routes);
	phalcon_read_property(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(routes TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(routes);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(route);
		
		PHALCON_INIT_NVAR(route_id);
		PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
		
		PHALCON_INIT_NVAR(is_equal);
		is_equal_function(is_equal, route_id, id TSRMLS_CC);
		if (PHALCON_IS_TRUE(is_equal)) {
			
			RETURN_CCTOR(route);
		}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
		
	ph_cycle_end_0:
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Returns a route object by its name
 *
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName){

	zval *name, *routes, *route = NULL, *route_name = NULL, *is_equal = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(routes);
	phalcon_read_property(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(routes TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(routes);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(route);
		
		PHALCON_INIT_NVAR(route_name);
		PHALCON_CALL_METHOD(route_name, route, "getname", PH_NO_CHECK);
		
		PHALCON_INIT_NVAR(is_equal);
		is_equal_function(is_equal, route_name, name TSRMLS_CC);
		if (PHALCON_IS_TRUE(is_equal)) {
			
			RETURN_CCTOR(route);
		}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
		
	ph_cycle_end_0:
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

