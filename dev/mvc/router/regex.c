
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
 * Phalcon\Router\Regex
 *
 * Phalcon\Router\Regex is the standard framework router. Routing is the
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

PHP_METHOD(Phalcon_Router_Regex, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;

	PHALCON_MM_GROW();
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_router_regex_ce, this_ptr, SL("_params"), a0 TSRMLS_CC);
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
PHP_METHOD(Phalcon_Router_Regex, _getRewriteUri){

	zval *g0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_GET")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, SL("_url")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, SL("_url"), PH_NOISY_CC);
		
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
PHP_METHOD(Phalcon_Router_Regex, setBaseUri){

	zval *base_uri = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &base_uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_baseUri"), base_uri TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Replaces placeholders from pattern returning a valid PCRE regular expression
 *
 * @param string $pattern
 * @return string
 */
PHP_METHOD(Phalcon_Router_Regex, compilePattern){

	zval *pattern = NULL, *id_pattern = NULL, *compiled_pattern = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL, *c5 = NULL, *c6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &pattern) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(id_pattern);
	ZVAL_STRING(id_pattern, "/([a-zA-Z0-9\\_]+)", 1);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ":", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_strpos(r0, pattern, c0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "/:controller", 1);
		PHALCON_INIT_VAR(compiled_pattern);
		phalcon_fast_str_replace(compiled_pattern, c1, id_pattern, pattern TSRMLS_CC);
		
		PHALCON_INIT_VAR(c2);
		ZVAL_STRING(c2, "/:action", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_fast_str_replace(r1, c2, id_pattern, compiled_pattern TSRMLS_CC);
		PHALCON_CPY_WRT(compiled_pattern, r1);
		
		PHALCON_INIT_VAR(c3);
		ZVAL_STRING(c3, "/:params", 1);
		
		PHALCON_INIT_VAR(c4);
		ZVAL_STRING(c4, "(/.*)*", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_fast_str_replace(r2, c3, c4, compiled_pattern TSRMLS_CC);
		PHALCON_CPY_WRT(compiled_pattern, r2);
		
		PHALCON_INIT_VAR(c5);
		ZVAL_STRING(c5, "/:int", 1);
		
		PHALCON_INIT_VAR(c6);
		ZVAL_STRING(c6, "/([0-9]+)", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_fast_str_replace(r3, c5, c6, compiled_pattern TSRMLS_CC);
		PHALCON_CPY_WRT(compiled_pattern, r3);
	} else {
		PHALCON_CPY_WRT(compiled_pattern, pattern);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_SVS(r4, "#^", compiled_pattern, "$#");
	
	RETURN_CTOR(r4);
}

/**
 * Add a route to the router
 *
 * @param string $pattern
 * @param string/array $paths
 */
PHP_METHOD(Phalcon_Router_Regex, add){

	zval *pattern = NULL, *paths = NULL, *parts = NULL, *route_paths = NULL, *pcre_pattern = NULL;
	zval *matches = NULL, *match = NULL, *n = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *a0 = NULL;
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
		
		PHALCON_INIT_VAR(route_paths);
		array_init(route_paths);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_long(&r0, parts, 0, PH_NOISY_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "strtolower", r0);
		phalcon_array_update_string(&route_paths, SL("controller"), &r1, PH_COPY | PH_SEPARATE TSRMLS_CC);
		eval_int = phalcon_array_isset_long(parts, 1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch_long(&r2, parts, 1, PH_NOISY_CC);
			phalcon_array_update_string(&route_paths, SL("action"), &r2, PH_COPY | PH_SEPARATE TSRMLS_CC);
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
	
	PHALCON_INIT_VAR(c3);
	ZVAL_STRING(c3, "{", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_fast_strpos(r3, pcre_pattern, c3 TSRMLS_CC);
	if (zend_is_true(r3)) {
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
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_FUNC_PARAMS(r4, "preg_match_all", 4, p0);
		Z_UNSET_ISREF_P(p0[2]);
		if (zend_is_true(r4)) {
			if (phalcon_valid_foreach(matches TSRMLS_CC)) {
				ah0 = Z_ARRVAL_P(matches);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_62c6_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_62c6_0;
				} else {
					PHALCON_INIT_VAR(n);
					PHALCON_GET_FOREACH_KEY(n, ah0, hp0);
				}
				PHALCON_INIT_VAR(match);
				ZVAL_ZVAL(match, *hd, 1, 0);
				PHALCON_INIT_VAR(r5);
				phalcon_array_fetch_long(&r5, match, 0, PH_NOISY_CC);
				PHALCON_INIT_VAR(r6);
				phalcon_array_fetch_long(&r6, match, 2, PH_NOISY_CC);
				PHALCON_INIT_VAR(r7);
				PHALCON_CONCAT_SVS(r7, "(", r6, ")");
				PHALCON_INIT_VAR(r8);
				phalcon_fast_str_replace(r8, r5, r7, pcre_pattern TSRMLS_CC);
				PHALCON_CPY_WRT(pcre_pattern, r8);
				
				PHALCON_INIT_VAR(t1);
				ZVAL_LONG(t1, 1);
				
				PHALCON_INIT_VAR(r9);
				phalcon_add_function(r9, n, t1 TSRMLS_CC);
				
				PHALCON_INIT_VAR(r10);
				phalcon_array_fetch_long(&r10, match, 1, PH_NOISY_CC);
				phalcon_array_update(&route_paths, r10, &r9, PH_COPY | PH_SEPARATE TSRMLS_CC);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_62c6_0;
				fee_62c6_0:
				if(0){}
			} else {
				return;
			}
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CALL_METHOD_PARAMS_1(r11, this_ptr, "compilepattern", pcre_pattern, PH_NO_CHECK);
	phalcon_array_update_string(&a0, SL("pattern"), &r11, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&a0, SL("paths"), &route_paths, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_routes"), PH_NOISY_CC);
	phalcon_array_append(&t2, a0, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_routes"), t2 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Handles routing information received from the rewrite engine
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Router_Regex, handle){

	zval *uri = NULL, *real_uri = NULL, *route_found = NULL, *parts = NULL, *params = NULL;
	zval *matches = NULL, *route = NULL, *position = NULL, *part = NULL, *str_params = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *a0 = NULL;
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
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_routes"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "array_reverse", t0);
	if (phalcon_valid_foreach(r0 TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(r0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_62c6_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_62c6_1;
		}
		
		PHALCON_INIT_VAR(route);
		ZVAL_ZVAL(route, *hd, 1, 0);
		PHALCON_INIT_VAR(parts);
		phalcon_array_fetch_string(&parts, route, SL("paths"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(r1);
		phalcon_array_fetch_string(&r1, route, SL("pattern"), PH_NOISY_CC);
		Z_SET_ISREF_P(matches);
		
		PHALCON_INIT_VAR(r2);
		PHALCON_CALL_FUNC_PARAMS_3(r2, "preg_match", r1, real_uri, matches);
		Z_UNSET_ISREF_P(matches);
		if (zend_is_true(r2)) {
			PHALCON_INIT_VAR(r3);
			phalcon_array_fetch_string(&r3, route, SL("paths"), PH_NOISY_CC);
			if (phalcon_valid_foreach(r3 TSRMLS_CC)) {
				ah1 = Z_ARRVAL_P(r3);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_62c6_2:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_62c6_2;
				} else {
					PHALCON_INIT_VAR(part);
					PHALCON_GET_FOREACH_KEY(part, ah1, hp1);
				}
				PHALCON_INIT_VAR(position);
				ZVAL_ZVAL(position, *hd, 1, 0);
				eval_int = phalcon_array_isset(matches, position);
				if (eval_int) {
					PHALCON_INIT_VAR(r4);
					phalcon_array_fetch(&r4, matches, position, PH_NOISY_CC);
					phalcon_array_update(&parts, part, &r4, PH_COPY | PH_SEPARATE TSRMLS_CC);
				}
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_62c6_2;
				fee_62c6_2:
				if(0){}
			} else {
				return;
			}
			phalcon_update_property_zval(this_ptr, SL("_currentRoute"), route TSRMLS_CC);
			
			PHALCON_INIT_VAR(route_found);
			ZVAL_BOOL(route_found, 1);
			goto fee_62c6_1;
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_62c6_1;
		fee_62c6_1:
		if(0){}
	} else {
		return;
	}
	if (zend_is_true(route_found)) {
		eval_int = phalcon_array_isset_string(parts, SL("controller")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r5);
			phalcon_array_fetch_string(&r5, parts, SL("controller"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_controller"), r5 TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SL("controller")+1);
		} else {
			phalcon_update_property_null(this_ptr, SL("_controller") TSRMLS_CC);
		}
		eval_int = phalcon_array_isset_string(parts, SL("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r6);
			phalcon_array_fetch_string(&r6, parts, SL("action"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_action"), r6 TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SL("action")+1);
		} else {
			phalcon_update_property_null(this_ptr, SL("_action") TSRMLS_CC);
		}
		
		eval_int = phalcon_array_isset_string(parts, SL("params")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r7);
			phalcon_array_fetch_string(&r7, parts, SL("params"), PH_NOISY_CC);
			PHALCON_INIT_VAR(c0);
			ZVAL_LONG(c0, 1);
			PHALCON_INIT_VAR(str_params);
			PHALCON_CALL_FUNC_PARAMS_2(str_params, "substr", r7, c0);
			if (zend_is_true(str_params)) {
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, "/", 1);
				PHALCON_INIT_VAR(params);
				phalcon_fast_explode(params, c1, str_params TSRMLS_CC);
			}
			
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, SL("params")+1);
		}
		
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CALL_FUNC_PARAMS_2(r8, "array_merge", params, parts);
		phalcon_update_property_zval(this_ptr, SL("_params"), r8 TSRMLS_CC);
	} else {
		phalcon_update_property_null(this_ptr, SL("_action") TSRMLS_CC);
		phalcon_update_property_null(this_ptr, SL("_controller") TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		phalcon_update_property_zval(this_ptr, SL("_params"), a0 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns proccesed controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Router_Regex, getControllerName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_controller"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Returns proccesed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Router_Regex, getActionName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_action"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Returns proccesed extra params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Router_Regex, getParams){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_params"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Returns the route that matchs the handled URI
 *
 * @return string
 */
PHP_METHOD(Phalcon_Router_Regex, getCurrentRoute){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_currentRoute"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

