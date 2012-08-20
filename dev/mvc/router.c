
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

#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Mvc\Router
 *
 * Phalcon\Mvc\Router is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request
 *
 *
 *
 * Settings baseUri first:
 *
 *
 *
 */

PHP_METHOD(Phalcon_Mvc_Router, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;

	PHALCON_MM_GROW();
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_mvc_router_ce, this_ptr, SL("_params"), a0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(a1);
	array_init(a1);
	PHALCON_ALLOC_ZVAL_MM(a2);
	array_init(a2);
	add_assoc_stringl_ex(a2, SL("pattern")+1, SL("#^/([a-zA-Z0-9\\_]+)[/]{0,1}$#"), 1);
	PHALCON_ALLOC_ZVAL_MM(a3);
	array_init(a3);
	add_assoc_long_ex(a3, SL("controller")+1, 1);
	phalcon_array_update_string(&a2, SL("paths"), &a3, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&a1, a2, PH_SEPARATE TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(a4);
	array_init(a4);
	add_assoc_stringl_ex(a4, SL("pattern")+1, SL("#^/([a-zA-Z0-9\\_]+)/([a-zA-Z0-9\\_]+)(/.*)*$#"), 1);
	PHALCON_ALLOC_ZVAL_MM(a5);
	array_init(a5);
	add_assoc_long_ex(a5, SL("controller")+1, 1);
	add_assoc_long_ex(a5, SL("action")+1, 2);
	add_assoc_long_ex(a5, SL("params")+1, 3);
	phalcon_array_update_string(&a4, SL("paths"), &a5, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&a1, a4, PH_SEPARATE TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_routes"), a1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
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

/**
 * Set the base of application
 *
 * @param string $baseUri
 */
PHP_METHOD(Phalcon_Mvc_Router, setBaseUri){

	zval *base_uri = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &base_uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_baseUri"), base_uri TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
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

/**
 * Replaces placeholders from pattern returning a valid PCRE regular expression
 *
 * @param string $pattern
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, compilePattern){

	zval *pattern = NULL, *id_pattern = NULL, *have_double_dot = NULL;
	zval *compiled_pattern = NULL, *final_pattern = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL, *c5 = NULL, *c6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &pattern) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(id_pattern);
	ZVAL_STRING(id_pattern, "/([a-zA-Z0-9\\_]+)", 1);
	
	PHALCON_INIT_VAR(have_double_dot);
	phalcon_fast_strpos_str(have_double_dot, pattern, SL(":") TSRMLS_CC);
	if (zend_is_true(have_double_dot)) {
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "/:module", 1);
		PHALCON_INIT_VAR(compiled_pattern);
		phalcon_fast_str_replace(compiled_pattern, c0, id_pattern, pattern TSRMLS_CC);
		
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "/:controller", 1);
		
		PHALCON_INIT_VAR(compiled_pattern);
		phalcon_fast_str_replace(compiled_pattern, c1, id_pattern, pattern TSRMLS_CC);
		
		PHALCON_INIT_VAR(c2);
		ZVAL_STRING(c2, "/:action", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_fast_str_replace(r0, c2, id_pattern, compiled_pattern TSRMLS_CC);
		PHALCON_CPY_WRT(compiled_pattern, r0);
		
		PHALCON_INIT_VAR(c3);
		ZVAL_STRING(c3, "/:params", 1);
		
		PHALCON_INIT_VAR(c4);
		ZVAL_STRING(c4, "(/.*)*", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_fast_str_replace(r1, c3, c4, compiled_pattern TSRMLS_CC);
		PHALCON_CPY_WRT(compiled_pattern, r1);
		
		PHALCON_INIT_VAR(c5);
		ZVAL_STRING(c5, "/:int", 1);
		
		PHALCON_INIT_VAR(c6);
		ZVAL_STRING(c6, "/([0-9]+)", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_fast_str_replace(r2, c5, c6, compiled_pattern TSRMLS_CC);
		PHALCON_CPY_WRT(compiled_pattern, r2);
	} else {
		PHALCON_CPY_WRT(compiled_pattern, pattern);
	}
	
	PHALCON_INIT_VAR(final_pattern);
	PHALCON_CONCAT_SVS(final_pattern, "#^", compiled_pattern, "$#");
	
	RETURN_CTOR(final_pattern);
}

/**
 * Add a route to the router
 *
 * @param string $pattern
 * @param string/array $paths
 */
PHP_METHOD(Phalcon_Mvc_Router, add){

	zval *pattern = NULL, *paths = NULL, *parts = NULL, *part_zero = NULL, *controller_name = NULL;
	zval *route_paths = NULL, *part_one = NULL, *pcre_pattern = NULL;
	zval *have_bracket = NULL, *matches = NULL, *have_variables = NULL;
	zval *match = NULL, *n = NULL, *match_zero = NULL, *match_one = NULL, *match_two = NULL;
	zval *replace_pattern = NULL, *match_position = NULL, *compiled_pattern = NULL;
	zval *final_route = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &pattern, &paths) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(paths) == IS_STRING) {
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "::", 1);
		PHALCON_INIT_VAR(parts);
		phalcon_fast_explode(parts, c0, paths TSRMLS_CC);
		
		PHALCON_INIT_VAR(part_zero);
		phalcon_array_fetch_long(&part_zero, parts, 0, PH_NOISY_CC);
		
		PHALCON_INIT_VAR(controller_name);
		PHALCON_CALL_FUNC_PARAMS_1(controller_name, "strtolower", part_zero);
		
		PHALCON_INIT_VAR(route_paths);
		array_init(route_paths);
		phalcon_array_update_string(&route_paths, SL("controller"), &controller_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
		eval_int = phalcon_array_isset_long(parts, 1);
		if (eval_int) {
			PHALCON_INIT_VAR(part_one);
			phalcon_array_fetch_long(&part_one, parts, 1, PH_NOISY_CC);
			phalcon_array_update_string(&route_paths, SL("action"), &part_one, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	} else {
		PHALCON_CPY_WRT(route_paths, paths);
	}
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "#", 1);
	
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "\\#", 1);
	
	PHALCON_INIT_VAR(pcre_pattern);
	phalcon_fast_str_replace(pcre_pattern, c1, c2, pattern TSRMLS_CC);
	
	PHALCON_INIT_VAR(have_bracket);
	phalcon_fast_strpos_str(have_bracket, pcre_pattern, SL("{") TSRMLS_CC);
	if (zend_is_true(have_bracket)) {
		PHALCON_INIT_VAR(matches);
		array_init(matches);
		
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "#{([a-zA-Z0-9\\_\\-]+):([^}]+)}#", 1);
		p0[1] = pcre_pattern;
		Z_SET_ISREF_P(matches);
		p0[2] = matches;
		
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 2);
		p0[3] = t0;
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC_PARAMS(r0, "preg_match_all", 4, p0);
		Z_UNSET_ISREF_P(p0[2]);
		PHALCON_CPY_WRT(have_variables, r0);
		if (zend_is_true(have_variables)) {
			if (!phalcon_valid_foreach(matches TSRMLS_CC)) {
				return;
			}
			
			ah0 = Z_ARRVAL_P(matches);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_c9ff_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_c9ff_0;
				}
				
				PHALCON_INIT_VAR(n);
				PHALCON_GET_FOREACH_KEY(n, ah0, hp0);
				PHALCON_INIT_VAR(match);
				ZVAL_ZVAL(match, *hd, 1, 0);
				PHALCON_INIT_VAR(match_zero);
				phalcon_array_fetch_long(&match_zero, match, 0, PH_NOISY_CC);
				
				PHALCON_INIT_VAR(match_one);
				phalcon_array_fetch_long(&match_one, match, 1, PH_NOISY_CC);
				
				PHALCON_INIT_VAR(match_two);
				phalcon_array_fetch_long(&match_two, match, 2, PH_NOISY_CC);
				
				PHALCON_INIT_VAR(replace_pattern);
				PHALCON_CONCAT_SVS(replace_pattern, "(", match_two, ")");
				
				PHALCON_INIT_VAR(r1);
				phalcon_fast_str_replace(r1, match_zero, replace_pattern, pcre_pattern TSRMLS_CC);
				PHALCON_CPY_WRT(pcre_pattern, r1);
				
				PHALCON_INIT_VAR(t1);
				ZVAL_LONG(t1, 1);
				
				PHALCON_INIT_VAR(match_position);
				phalcon_add_function(match_position, n, t1 TSRMLS_CC);
				phalcon_array_update_zval(&route_paths, match_one, &match_position, PH_COPY | PH_SEPARATE TSRMLS_CC);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_c9ff_0;
			fee_c9ff_0:
			if(0){}
			
		}
	}
	
	PHALCON_INIT_VAR(compiled_pattern);
	PHALCON_CALL_METHOD_PARAMS_1(compiled_pattern, this_ptr, "compilepattern", pcre_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(final_route);
	array_init(final_route);
	phalcon_array_update_string(&final_route, SL("pattern"), &compiled_pattern, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&final_route, SL("paths"), &route_paths, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_routes"), PH_NOISY_CC);
	phalcon_array_append(&t2, final_route, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_routes"), t2 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Handles routing information received from the rewrite engine
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Mvc_Router, handle){

	zval *uri = NULL, *real_uri = NULL, *route_found = NULL, *parts = NULL, *params = NULL;
	zval *matches = NULL, *routes = NULL, *reversed_routes = NULL, *route = NULL;
	zval *pattern = NULL, *match_route = NULL, *paths = NULL, *position = NULL;
	zval *part = NULL, *match_position = NULL, *module = NULL, *default_module = NULL;
	zval *controller = NULL, *action = NULL, *params_str = NULL, *str_params = NULL;
	zval *params_merge = NULL, *empty_params = NULL;
	zval *c0 = NULL, *c1 = NULL;
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
	fes_c9ff_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_c9ff_1;
		}
		
		PHALCON_INIT_VAR(route);
		ZVAL_ZVAL(route, *hd, 1, 0);
		PHALCON_INIT_VAR(parts);
		phalcon_array_fetch_string(&parts, route, SL("paths"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(pattern);
		phalcon_array_fetch_string(&pattern, route, SL("pattern"), PH_NOISY_CC);
		Z_SET_ISREF_P(matches);
		
		PHALCON_INIT_VAR(match_route);
		PHALCON_CALL_FUNC_PARAMS_3(match_route, "preg_match", pattern, real_uri, matches);
		Z_UNSET_ISREF_P(matches);
		if (zend_is_true(match_route)) {
			PHALCON_INIT_VAR(paths);
			phalcon_array_fetch_string(&paths, route, SL("paths"), PH_NOISY_CC);
			if (!phalcon_valid_foreach(paths TSRMLS_CC)) {
				return;
			}
			
			ah1 = Z_ARRVAL_P(paths);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_c9ff_2:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_c9ff_2;
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
				goto fes_c9ff_2;
			fee_c9ff_2:
			
			phalcon_update_property_zval(this_ptr, SL("_matches"), matches TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_currentRoute"), route TSRMLS_CC);
			
			PHALCON_INIT_VAR(route_found);
			ZVAL_BOOL(route_found, 1);
			goto fee_c9ff_1;
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_c9ff_1;
	fee_c9ff_1:
	
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
			phalcon_update_property_null(this_ptr, SL("_controller") TSRMLS_CC);
		}
		
		eval_int = phalcon_array_isset_string(parts, SL("action")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(action);
			phalcon_array_fetch_string(&action, parts, SL("action"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_action"), action TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SL("action")+1);
		} else {
			phalcon_update_property_null(this_ptr, SL("_action") TSRMLS_CC);
		}
		
		eval_int = phalcon_array_isset_string(parts, SL("params")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(params_str);
			phalcon_array_fetch_string(&params_str, parts, SL("params"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(c0);
			ZVAL_LONG(c0, 1);
			
			PHALCON_INIT_VAR(str_params);
			PHALCON_CALL_FUNC_PARAMS_2(str_params, "substr", params_str, c0);
			if (zend_is_true(str_params)) {
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, "/", 1);
				PHALCON_INIT_VAR(params);
				phalcon_fast_explode(params, c1, str_params TSRMLS_CC);
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
		phalcon_update_property_null(this_ptr, SL("_controller") TSRMLS_CC);
		phalcon_update_property_null(this_ptr, SL("_action") TSRMLS_CC);
		
		PHALCON_INIT_VAR(empty_params);
		array_init(empty_params);
		phalcon_update_property_zval(this_ptr, SL("_params"), empty_params TSRMLS_CC);
		phalcon_update_property_bool(this_ptr, SL("_wasMatched"), 0 TSRMLS_CC);
	}
	
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
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getCurrentRoute){

	zval *current_route = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(current_route);
	phalcon_read_property(&current_route, this_ptr, SL("_currentRoute"), PH_NOISY_CC);
	
	RETURN_CCTOR(current_route);
}

/**
 *
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatches){

	zval *matches = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(matches);
	phalcon_read_property(&matches, this_ptr, SL("_matches"), PH_NOISY_CC);
	
	RETURN_CCTOR(matches);
}

PHP_METHOD(Phalcon_Mvc_Router, wasMatched){

	zval *was_matched = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(was_matched);
	phalcon_read_property(&was_matched, this_ptr, SL("_wasMatched"), PH_NOISY_CC);
	
	RETURN_CCTOR(was_matched);
}

