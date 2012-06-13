
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_Router_Regex
 *
 * Phalcon_Router_Regex is the standard framework router. Routing is the
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
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_router_regex_ce, this_ptr, "_params", strlen("_params"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	add_assoc_stringl_ex(a2, "pattern", strlen("pattern")+1, "#^/([a-zA-Z0-9\\_]+)[/]{0,1}$#", strlen("#^/([a-zA-Z0-9\\_]+)[/]{0,1}$#"), 1);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_assoc_long_ex(a3, "controller", strlen("controller")+1, 1);
	phalcon_array_update_string(&a2, "paths", strlen("paths"), &a3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_array_append(&a1, a2, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	add_assoc_stringl_ex(a4, "pattern", strlen("pattern")+1, "#^/([a-zA-Z0-9\\_]+)/([a-zA-Z0-9\\_]+)(/.*)*$#", strlen("#^/([a-zA-Z0-9\\_]+)/([a-zA-Z0-9\\_]+)(/.*)*$#"), 1);
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	add_assoc_long_ex(a5, "controller", strlen("controller")+1, 1);
	add_assoc_long_ex(a5, "action", strlen("action")+1, 2);
	add_assoc_long_ex(a5, "params", strlen("params")+1, 3);
	phalcon_array_update_string(&a4, "paths", strlen("paths"), &a5, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_array_append(&a1, a4, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_routes", strlen("_routes"), a1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Get rewrite info
 */
PHP_METHOD(Phalcon_Router_Regex, _getRewriteUri){

	zval *g0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, "_GET", sizeof("_GET") TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, "_url", strlen("_url")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, "_url", strlen("_url"), PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_RETURN_CHECK_CTOR(r0);
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

	phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), base_uri TSRMLS_CC);
	
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

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
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "/:controller", 1);
		PHALCON_CALL_FUNC_PARAMS_3(r1, "str_replace", c1, id_pattern, pattern, 0x003);
		PHALCON_CPY_WRT(compiled_pattern, r1);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		
		PHALCON_INIT_VAR(c2);
		ZVAL_STRING(c2, "/:action", 1);
		PHALCON_CALL_FUNC_PARAMS_3(r2, "str_replace", c2, id_pattern, compiled_pattern, 0x003);
		PHALCON_CPY_WRT(compiled_pattern, r2);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		
		PHALCON_INIT_VAR(c3);
		ZVAL_STRING(c3, "/:params", 1);
		
		PHALCON_INIT_VAR(c4);
		ZVAL_STRING(c4, "(/.*)*", 1);
		PHALCON_CALL_FUNC_PARAMS_3(r3, "str_replace", c3, c4, compiled_pattern, 0x003);
		PHALCON_CPY_WRT(compiled_pattern, r3);
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		
		PHALCON_INIT_VAR(c5);
		ZVAL_STRING(c5, "/:int", 1);
		
		PHALCON_INIT_VAR(c6);
		ZVAL_STRING(c6, "/([0-9]+)", 1);
		PHALCON_CALL_FUNC_PARAMS_3(r4, "str_replace", c5, c6, compiled_pattern, 0x003);
		PHALCON_CPY_WRT(compiled_pattern, r4);
	} else {
		PHALCON_CPY_WRT(compiled_pattern, pattern);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CONCAT_SVS(r5, "#^", compiled_pattern, "$#");
	
	PHALCON_RETURN_CTOR(r5);
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
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p4[] = { NULL, NULL, NULL, NULL };
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
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_fast_explode(r0, c0, paths TSRMLS_CC);
		PHALCON_CPY_WRT(parts, r0);
		
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_long(&r2, parts, 0, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "strtolower", r2, 0x005);
		phalcon_array_update_string(&a0, "controller", strlen("controller"), &r1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		PHALCON_CPY_WRT(route_paths, a0);
		eval_int = phalcon_array_isset_long(parts, 1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_long(&r3, parts, 1, PHALCON_NOISY TSRMLS_CC);
			phalcon_array_update_string(&route_paths, "action", strlen("action"), &r3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
	} else {
		PHALCON_CPY_WRT(route_paths, paths);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "#", 1);
	
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "\\#", 1);
	PHALCON_CALL_FUNC_PARAMS_3(r4, "str_replace", c1, c2, pattern, 0x003);
	PHALCON_CPY_WRT(pcre_pattern, r4);
	
	PHALCON_INIT_VAR(c3);
	ZVAL_STRING(c3, "{", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	phalcon_fast_strpos(r5, pcre_pattern, c3 TSRMLS_CC);
	if (zend_is_true(r5)) {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_CPY_WRT(matches, a1);
		
		PHALCON_ALLOC_ZVAL_MM(r6);
		
		PHALCON_INIT_VAR(p4[0]);
		ZVAL_STRING(p4[0], "#{([a-zA-Z0-9\\_\\-]+):([^}]+)}#", 1);
		p4[1] = pcre_pattern;
		Z_SET_ISREF_P(matches);
		p4[2] = matches;
		
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 2);
		p4[3] = t0;
		PHALCON_CALL_FUNC_PARAMS(r6, "preg_match_all", 4, p4, 0x06F);
		Z_UNSET_ISREF_P(p4[2]);
		if (zend_is_true(r6)) {
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
				PHALCON_INIT_VAR(r7);
				PHALCON_INIT_VAR(r8);
				phalcon_array_fetch_long(&r8, match, 0, PHALCON_NOISY TSRMLS_CC);
				PHALCON_INIT_VAR(r9);
				PHALCON_INIT_VAR(r10);
				phalcon_array_fetch_long(&r10, match, 2, PHALCON_NOISY TSRMLS_CC);
				PHALCON_CONCAT_SVS(r9, "(", r10, ")");
				PHALCON_CALL_FUNC_PARAMS_3(r7, "str_replace", r8, r9, pcre_pattern, 0x003);
				PHALCON_CPY_WRT(pcre_pattern, r7);
				
				PHALCON_INIT_VAR(t1);
				ZVAL_LONG(t1, 1);
				
				PHALCON_INIT_VAR(r11);
				phalcon_add_function(r11, n, t1 TSRMLS_CC);
				
				PHALCON_INIT_VAR(r12);
				phalcon_array_fetch_long(&r12, match, 1, PHALCON_NOISY TSRMLS_CC);
				phalcon_array_update(&route_paths, r12, &r11, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_62c6_0;
				fee_62c6_0:
				if(0){}
			} else {
				return;
			}
		}
	}
	
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	
	PHALCON_ALLOC_ZVAL_MM(r13);
	PHALCON_CALL_METHOD_PARAMS_1(r13, this_ptr, "compilepattern", pcre_pattern, PHALCON_NO_CHECK);
	phalcon_array_update_string(&a2, "pattern", strlen("pattern"), &r13, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_array_update_string(&a2, "paths", strlen("paths"), &route_paths, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_routes", sizeof("_routes")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_array_append(&t2, a2, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_routes", strlen("_routes"), t2 TSRMLS_CC);
	
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL;
	zval *t0 = NULL;
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
		PHALCON_INIT_VAR(uri);
		ZVAL_NULL(uri);
	}
	
	if (!zend_is_true(uri)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "_getrewriteuri", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(real_uri, r0);
	} else {
		PHALCON_CPY_WRT(real_uri, uri);
	}
	
	PHALCON_INIT_VAR(route_found);
	ZVAL_BOOL(route_found, 0);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(parts, a0);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_CPY_WRT(params, a1);
	
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	PHALCON_CPY_WRT(matches, a2);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_routes", sizeof("_routes")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "array_reverse", t0, 0x05E);
	if (phalcon_valid_foreach(r1 TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(r1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_62c6_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_62c6_1;
		}
		
		PHALCON_INIT_VAR(route);
		ZVAL_ZVAL(route, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_string(&r2, route, "paths", strlen("paths"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(parts, r2);
		
		PHALCON_INIT_VAR(r3);
		
		PHALCON_INIT_VAR(r4);
		phalcon_array_fetch_string(&r4, route, "pattern", strlen("pattern"), PHALCON_NOISY TSRMLS_CC);
		Z_SET_ISREF_P(matches);
		PHALCON_CALL_FUNC_PARAMS_3(r3, "preg_match", r4, real_uri, matches, 0x006);
		Z_UNSET_ISREF_P(matches);
		if (zend_is_true(r3)) {
			PHALCON_INIT_VAR(r5);
			phalcon_array_fetch_string(&r5, route, "paths", strlen("paths"), PHALCON_NOISY TSRMLS_CC);
			if (phalcon_valid_foreach(r5 TSRMLS_CC)) {
				ah1 = Z_ARRVAL_P(r5);
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
					PHALCON_INIT_VAR(r6);
					phalcon_array_fetch(&r6, matches, position, PHALCON_NOISY TSRMLS_CC);
					phalcon_array_update(&parts, part, &r6, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_62c6_2;
				fee_62c6_2:
				if(0){}
			} else {
				return;
			}
			phalcon_update_property_zval(this_ptr, "_currentRoute", strlen("_currentRoute"), route TSRMLS_CC);
			
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
		eval_int = phalcon_array_isset_string(parts, "controller", strlen("controller")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r7);
			phalcon_array_fetch_string(&r7, parts, "controller", strlen("controller"), PHALCON_NOISY TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_controller", strlen("_controller"), r7 TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, "controller", strlen("controller")+1);
		} else {
			phalcon_update_property_null(this_ptr, "_controller", strlen("_controller") TSRMLS_CC);
		}
		eval_int = phalcon_array_isset_string(parts, "action", strlen("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r8);
			phalcon_array_fetch_string(&r8, parts, "action", strlen("action"), PHALCON_NOISY TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_action", strlen("_action"), r8 TSRMLS_CC);
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, "action", strlen("action")+1);
		} else {
			phalcon_update_property_null(this_ptr, "_action", strlen("_action") TSRMLS_CC);
		}
		
		eval_int = phalcon_array_isset_string(parts, "params", strlen("params")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r9);
			PHALCON_ALLOC_ZVAL_MM(r10);
			phalcon_array_fetch_string(&r10, parts, "params", strlen("params"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(c0);
			ZVAL_LONG(c0, 1);
			PHALCON_CALL_FUNC_PARAMS_2(r9, "substr", r10, c0, 0x002);
			PHALCON_CPY_WRT(str_params, r9);
			if (zend_is_true(str_params)) {
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, "/", 1);
				PHALCON_ALLOC_ZVAL_MM(r11);
				phalcon_fast_explode(r11, c1, str_params TSRMLS_CC);
				PHALCON_CPY_WRT(params, r11);
			}
			
			PHALCON_SEPARATE(parts);
			phalcon_array_unset_string(parts, "params", strlen("params")+1);
		}
		
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CALL_FUNC_PARAMS_2(r12, "array_merge", params, parts, 0x043);
		phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), r12 TSRMLS_CC);
	} else {
		phalcon_update_property_null(this_ptr, "_action", strlen("_action") TSRMLS_CC);
		phalcon_update_property_null(this_ptr, "_controller", strlen("_controller") TSRMLS_CC);
		
		PHALCON_INIT_VAR(a3);
		array_init(a3);
		phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), a3 TSRMLS_CC);
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
	phalcon_read_property(&t0, this_ptr, "_controller", sizeof("_controller")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, "_action", sizeof("_action")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, "_currentRoute", sizeof("_currentRoute")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

