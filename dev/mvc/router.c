
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

#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"

/**
 * Phalcon\Mvc\Router
 *
 * <p>Phalcon\Mvc\Router is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request</p>
 *
 *<code>
 *$router = new Phalcon\Mvc\Router();
 *$router->handle();
 *echo $router->getControllerName();
 *</code>
 *
 * Settings baseUri first:
 *
 *<code>
 *$router = new Phalcon\Mvc\Router();
 *$router->handle();
 *echo $router->getControllerName();
 *</code>
 *</example>
 */

PHP_METHOD(Phalcon_Mvc_Router, __construct){

	zval *default_routes = NULL, *routes = NULL, *paths = NULL, *route = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_mvc_router_ce, this_ptr, SL("_params"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a1);
	array_init(a1);
	zend_update_property(phalcon_mvc_router_ce, this_ptr, SL("_defaultParams"), a1 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &default_routes) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!default_routes) {
		PHALCON_ALLOC_ZVAL_MM(default_routes);
		ZVAL_BOOL(default_routes, 1);
	}
	
	PHALCON_INIT_VAR(routes);
	array_init(routes);
	if (Z_TYPE_P(default_routes) == IS_BOOL && Z_BVAL_P(default_routes)) {
		PHALCON_INIT_VAR(paths);
		array_init(paths);
		add_assoc_long_ex(paths, SL("controller")+1, 1);
		
		PHALCON_INIT_VAR(route);
		object_init_ex(route, phalcon_mvc_router_route_ce);
		
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "#^/([a-zA-Z0-9\\_]+)[/]{0,1}$#", 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(route, "__construct", c0, paths, PH_CHECK);
		phalcon_array_append(&routes, route, PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_VAR(paths);
		array_init(paths);
		add_assoc_long_ex(paths, SL("controller")+1, 1);
		add_assoc_long_ex(paths, SL("action")+1, 2);
		add_assoc_long_ex(paths, SL("params")+1, 3);
		
		PHALCON_INIT_VAR(route);
		object_init_ex(route, phalcon_mvc_router_route_ce);
		
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "#^/([a-zA-Z0-9\\_]+)/([a-zA-Z0-9\\_]+)(/.*)*$#", 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(route, "__construct", c1, paths, PH_CHECK);
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

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Mvc_Router, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Get rewrite info
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, _getRewriteUri){

	zval *get = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_GET")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(get, g0);
	eval_int = phalcon_array_isset_string(get, SL("_url")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, get, SL("_url"), PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule){

	zval *module_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &module_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultModule"), module_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Router, setDefaultController){

	zval *controller_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &controller_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultController"), controller_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction){

	zval *action_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &action_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultAction"), action_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Router, setDefaults){

	zval *defaults = NULL, *module_name = NULL, *controller_name = NULL;
	zval *action_name = NULL, *params = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &defaults) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(defaults, SL("module")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(module_name);
		phalcon_array_fetch_string(&module_name, defaults, SL("module"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_defaultModule"), module_name TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(defaults, SL("controller")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(controller_name);
		phalcon_array_fetch_string(&controller_name, defaults, SL("controller"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_defaultController"), controller_name TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(defaults, SL("action")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(action_name);
		phalcon_array_fetch_string(&action_name, defaults, SL("action"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_defaultAction"), action_name TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(defaults, SL("params")+1);
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
	zval *params = NULL, *matches = NULL, *routes = NULL, *reversed_routes = NULL;
	zval *route = NULL, *methods = NULL, *dependency_injector = NULL;
	zval *match_method = NULL, *pattern = NULL, *paths = NULL, *position = NULL;
	zval *part = NULL, *match_position = NULL, *module = NULL, *default_module = NULL;
	zval *controller = NULL, *default_controller = NULL, *action = NULL;
	zval *default_action = NULL, *params_str = NULL, *str_params = NULL;
	zval *params_merge = NULL, *default_params = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
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
		PHALCON_ALLOC_ZVAL_MM(uri);
		ZVAL_NULL(uri);
	}
	
	if (!zend_is_true(uri)) {
		PHALCON_INIT_VAR(real_uri);
		PHALCON_CALL_METHOD(real_uri, this_ptr, "_getrewriteuri", PH_NO_CHECK);
	} else {
		PHALCON_CPY_WRT(real_uri, uri);
	}
	
	PHALCON_INIT_VAR(request);
	ZVAL_NULL(request);
	
	PHALCON_INIT_VAR(route_found);
	ZVAL_BOOL(route_found, 0);
	
	PHALCON_INIT_VAR(parts);
	array_init(parts);
	
	PHALCON_INIT_VAR(params);
	array_init(params);
	
	PHALCON_INIT_VAR(matches);
	array_init(matches);
	phalcon_update_property_bool(this_ptr, SL("_wasMatched"), 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(routes);
	phalcon_read_property(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(reversed_routes);
	PHALCON_CALL_FUNC_PARAMS_1(reversed_routes, "array_reverse", routes);
	if (!phalcon_valid_foreach(reversed_routes TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(reversed_routes);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_c9ff_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_c9ff_0;
		}
		
		PHALCON_INIT_VAR(route);
		ZVAL_ZVAL(route, *hd, 1, 0);
		PHALCON_INIT_VAR(methods);
		PHALCON_CALL_METHOD(methods, route, "gethttpmethods", PH_NO_CHECK);
		if (Z_TYPE_P(methods) != IS_NULL) {
			if (Z_TYPE_P(request) == IS_NULL) {
				PHALCON_INIT_VAR(dependency_injector);
				phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_dispatcher_exception_ce, "A dependency injection container is required to access the 'request' service");
					return;
				}
				
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, "request", 1);
				
				PHALCON_INIT_VAR(request);
				PHALCON_CALL_METHOD_PARAMS_1(request, dependency_injector, "getshared", c0, PH_NO_CHECK);
			}
			
			PHALCON_INIT_VAR(match_method);
			PHALCON_CALL_METHOD_PARAMS_1(match_method, request, "ismethod", methods, PH_NO_CHECK);
			if (!zend_is_true(match_method)) {
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_c9ff_0;
			}
		}
		
		PHALCON_INIT_VAR(pattern);
		PHALCON_CALL_METHOD(pattern, route, "getcompiledpattern", PH_NO_CHECK);
		Z_SET_ISREF_P(matches);
		
		PHALCON_INIT_VAR(route_found);
		PHALCON_CALL_FUNC_PARAMS_3(route_found, "preg_match", pattern, real_uri, matches);
		Z_UNSET_ISREF_P(matches);
		if (zend_is_true(route_found)) {
			PHALCON_INIT_VAR(paths);
			PHALCON_CALL_METHOD(paths, route, "getpaths", PH_NO_CHECK);
			PHALCON_CPY_WRT(parts, paths);
			if (!phalcon_valid_foreach(paths TSRMLS_CC)) {
				return;
			}
			
			ah1 = Z_ARRVAL_P(paths);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_c9ff_1:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_c9ff_1;
				}
				
				PHALCON_INIT_VAR(part);
				PHALCON_GET_FOREACH_KEY(part, ah1, hp1);
				PHALCON_INIT_VAR(position);
				ZVAL_ZVAL(position, *hd, 1, 0);
				eval_int = phalcon_array_isset(matches, position);
				if (eval_int) {
					PHALCON_INIT_VAR(match_position);
					phalcon_array_fetch(&match_position, matches, position, PH_NOISY_CC);
					phalcon_array_update_zval(&parts, part, &match_position, PH_COPY | PH_SEPARATE TSRMLS_CC);
				}
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_c9ff_1;
			fee_c9ff_1:
			
			phalcon_update_property_zval(this_ptr, SL("_matches"), matches TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_matchedRoute"), route TSRMLS_CC);
			goto fee_c9ff_0;
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_c9ff_0;
	fee_c9ff_0:
	
	if (zend_is_true(route_found)) {
		eval_int = phalcon_array_isset_string(parts, SL("module")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(module);
			phalcon_array_fetch_string(&module, parts, SL("module"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_module"), module TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SL("module")+1);
		} else {
			PHALCON_INIT_VAR(default_module);
			phalcon_read_property(&default_module, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_module"), default_module TSRMLS_CC);
		}
		eval_int = phalcon_array_isset_string(parts, SL("controller")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(controller);
			phalcon_array_fetch_string(&controller, parts, SL("controller"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_controller"), controller TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SL("controller")+1);
		} else {
			PHALCON_INIT_VAR(default_controller);
			phalcon_read_property(&default_controller, this_ptr, SL("_defaultController"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_controller"), default_controller TSRMLS_CC);
		}
		
		eval_int = phalcon_array_isset_string(parts, SL("action")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(action);
			phalcon_array_fetch_string(&action, parts, SL("action"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_action"), action TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SL("action")+1);
		} else {
			PHALCON_INIT_VAR(default_action);
			phalcon_read_property(&default_action, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_action"), default_action TSRMLS_CC);
		}
		
		eval_int = phalcon_array_isset_string(parts, SL("params")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(params_str);
			phalcon_array_fetch_string(&params_str, parts, SL("params"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(c1);
			ZVAL_LONG(c1, 1);
			
			PHALCON_INIT_VAR(str_params);
			PHALCON_CALL_FUNC_PARAMS_2(str_params, "substr", params_str, c1);
			if (zend_is_true(str_params)) {
				PHALCON_INIT_VAR(c2);
				ZVAL_STRING(c2, "/", 1);
				PHALCON_INIT_VAR(params);
				phalcon_fast_explode(params, c2, str_params TSRMLS_CC);
			}
			
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SL("params")+1);
		}
		
		PHALCON_INIT_VAR(params_merge);
		PHALCON_CALL_FUNC_PARAMS_2(params_merge, "array_merge", params, parts);
		phalcon_update_property_zval(this_ptr, SL("_params"), params_merge TSRMLS_CC);
		phalcon_update_property_bool(this_ptr, SL("_wasMatched"), 1 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(default_module);
		phalcon_read_property(&default_module, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_module"), default_module TSRMLS_CC);
		
		PHALCON_INIT_VAR(default_controller);
		phalcon_read_property(&default_controller, this_ptr, SL("_defaultController"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_controller"), default_controller TSRMLS_CC);
		
		PHALCON_INIT_VAR(default_action);
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
 * Add a route to the router on any HTTP method
 *
 * @param string $pattern
 * @param string/array $paths
 * @param string $httpMethods
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, add){

	zval *pattern = NULL, *paths = NULL, *http_methods = NULL, *route = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &pattern, &paths, &http_methods) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_ALLOC_ZVAL_MM(paths);
		ZVAL_NULL(paths);
	}
	
	if (!http_methods) {
		PHALCON_ALLOC_ZVAL_MM(http_methods);
		ZVAL_NULL(http_methods);
	}
	
	PHALCON_INIT_VAR(route);
	object_init_ex(route, phalcon_mvc_router_route_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(route, "__construct", pattern, paths, http_methods, PH_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_routes"), PH_NOISY_CC);
	phalcon_array_append(&t0, route, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_routes"), t0 TSRMLS_CC);
	
	RETURN_CTOR(route);
}

/**
 * Add a route to the router that only match if the HTTP method is GET
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addGet){

	zval *pattern = NULL, *paths = NULL, *route = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_ALLOC_ZVAL_MM(paths);
		ZVAL_NULL(paths);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "GET", 1);
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, c0, PH_NO_CHECK);
	
	RETURN_CCTOR(route);
}

/**
 * Add a route to the router that only match if the HTTP method is POST
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addPost){

	zval *pattern = NULL, *paths = NULL, *route = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_ALLOC_ZVAL_MM(paths);
		ZVAL_NULL(paths);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "POST", 1);
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, c0, PH_NO_CHECK);
	
	RETURN_CCTOR(route);
}

/**
 * Add a route to the router that only match if the HTTP method is PUT
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addPut){

	zval *pattern = NULL, *paths = NULL, *route = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_ALLOC_ZVAL_MM(paths);
		ZVAL_NULL(paths);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "PUT", 1);
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, c0, PH_NO_CHECK);
	
	RETURN_CCTOR(route);
}

/**
 * Add a route to the router that only match if the HTTP method is DELETE
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addDelete){

	zval *pattern = NULL, *paths = NULL, *route = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_ALLOC_ZVAL_MM(paths);
		ZVAL_NULL(paths);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "DELETE", 1);
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, c0, PH_NO_CHECK);
	
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

	zval *pattern = NULL, *paths = NULL, *route = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_ALLOC_ZVAL_MM(paths);
		ZVAL_NULL(paths);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "OPTIONS", 1);
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, c0, PH_NO_CHECK);
	
	RETURN_CCTOR(route);
}

/**
 * Add a route to the router that only match if the HTTP method is HEAD
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addHead){

	zval *pattern = NULL, *paths = NULL, *route = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_ALLOC_ZVAL_MM(paths);
		ZVAL_NULL(paths);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "HEAD", 1);
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "add", pattern, paths, c0, PH_NO_CHECK);
	
	RETURN_CCTOR(route);
}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, clear){

	zval *empty_routes = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(empty_routes);
	array_init(empty_routes);
	phalcon_update_property_zval(this_ptr, SL("_routes"), empty_routes TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns proccesed module name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getModuleName){

	zval *module = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(module);
	phalcon_read_property(&module, this_ptr, SL("_module"), PH_NOISY_CC);
	
	RETURN_CCTOR(module);
}

/**
 * Returns proccesed controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getControllerName){

	zval *controller = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(controller);
	phalcon_read_property(&controller, this_ptr, SL("_controller"), PH_NOISY_CC);
	
	RETURN_CCTOR(controller);
}

/**
 * Returns proccesed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getActionName){

	zval *action = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(action);
	phalcon_read_property(&action, this_ptr, SL("_action"), PH_NOISY_CC);
	
	RETURN_CCTOR(action);
}

/**
 * Returns proccesed extra params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getParams){

	zval *params = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(params);
	phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	
	RETURN_CCTOR(params);
}

/**
 * Returns the route that matchs the handled URI
 *
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute){

	zval *matched_route = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(matched_route);
	phalcon_read_property(&matched_route, this_ptr, SL("_matchedRoute"), PH_NOISY_CC);
	
	RETURN_CCTOR(matched_route);
}

/**
 * Return the sub expressions in the regular expression matched
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatches){

	zval *matches = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(matches);
	phalcon_read_property(&matches, this_ptr, SL("_matches"), PH_NOISY_CC);
	
	RETURN_CCTOR(matches);
}

/**
 * Check if the router macthes any of the defined routes
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Router, wasMatched){

	zval *was_matched = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(was_matched);
	phalcon_read_property(&was_matched, this_ptr, SL("_wasMatched"), PH_NOISY_CC);
	
	RETURN_CCTOR(was_matched);
}

/**
 * @return Phalcon\Mvc\Router\Route[]
 */
PHP_METHOD(Phalcon_Mvc_Router, getRoutes){

	zval *routes = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(routes);
	phalcon_read_property(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	
	RETURN_CCTOR(routes);
}

PHP_METHOD(Phalcon_Mvc_Router, getRouteById){

	zval *id = NULL, *routes = NULL, *route = NULL, *route_id = NULL;
	zval *r0 = NULL;
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
	fes_c9ff_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_c9ff_2;
		}
		
		PHALCON_INIT_VAR(route);
		ZVAL_ZVAL(route, *hd, 1, 0);
		PHALCON_INIT_VAR(route_id);
		PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(r0);
		is_equal_function(r0, route_id, id TSRMLS_CC);
		if (zend_is_true(r0)) {
			
			RETURN_CCTOR(route);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_c9ff_2;
	fee_c9ff_2:
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

PHP_METHOD(Phalcon_Mvc_Router, getRouteByName){

	zval *name = NULL, *routes = NULL, *route = NULL, *route_name = NULL;
	zval *r0 = NULL;
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
	fes_c9ff_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_c9ff_3;
		}
		
		PHALCON_INIT_VAR(route);
		ZVAL_ZVAL(route, *hd, 1, 0);
		PHALCON_INIT_VAR(route_name);
		PHALCON_CALL_METHOD(route_name, route, "getname", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(r0);
		is_equal_function(r0, route_name, name TSRMLS_CC);
		if (zend_is_true(r0)) {
			
			RETURN_CCTOR(route);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_c9ff_3;
	fee_c9ff_3:
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

