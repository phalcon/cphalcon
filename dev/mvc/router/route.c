
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/array.h"

PHP_METHOD(Phalcon_Mvc_Router_Route, __construct){

	zval *pattern = NULL, *paths = NULL, *http_methods = NULL, *unique_id = NULL;
	zval *route_id = NULL, *next_id = NULL;
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
	
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "reconfigure", pattern, paths, PH_NO_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_methods"), http_methods TSRMLS_CC);
	PHALCON_OBSERVE_VAR(unique_id);
	phalcon_read_static_property(&unique_id, SL("phalcon\\mvc\\router\\route"), SL("_uniqueId") TSRMLS_CC);
	if (Z_TYPE_P(unique_id) == IS_NULL) {
		PHALCON_INIT_VAR(unique_id);
		ZVAL_LONG(unique_id, 0);
	}
	
	PHALCON_CPY_WRT(route_id, unique_id);
	phalcon_update_property_zval(this_ptr, SL("_routeId"), route_id TSRMLS_CC);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	
	PHALCON_INIT_VAR(next_id);
	phalcon_add_function(next_id, unique_id, t0 TSRMLS_CC);
	phalcon_update_static_property(SL("phalcon\\mvc\\router\\route"), SL("_uniqueId"), next_id TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Replaces placeholders from pattern returning a valid PCRE regular expression
 *
 * @param string $pattern
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, compilePattern){

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

PHP_METHOD(Phalcon_Mvc_Router_Route, via){

	zval *http_methods = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &http_methods) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_methods"), http_methods TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Router_Route, reConfigure){

	zval *pattern = NULL, *paths = NULL, *parts = NULL, *part_zero = NULL, *controller_name = NULL;
	zval *route_paths = NULL, *part_one = NULL, *one = NULL, *set_order = NULL;
	zval *first = NULL, *pcre_pattern = NULL, *have_bracket = NULL, *matches = NULL;
	zval *match_position = NULL, *have_variables = NULL, *match = NULL;
	zval *match_zero = NULL, *match_one = NULL, *match_two = NULL, *replace_pattern = NULL;
	zval *new_pcre_pattern = NULL, *compiled_pattern = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &pattern, &paths) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(pattern) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "The pattern must be string");
		return;
	}
	if (Z_TYPE_P(paths) != IS_NULL) {
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
	} else {
		PHALCON_INIT_VAR(route_paths);
		array_init(route_paths);
	}
	
	PHALCON_INIT_VAR(one);
	ZVAL_LONG(one, 1);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 2);
	PHALCON_CPY_WRT(set_order, t0);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_LONG(c1, 0);
	
	PHALCON_INIT_VAR(first);
	PHALCON_CALL_FUNC_PARAMS_3(first, "substr", pattern, c1, one);
	if (!PHALCON_COMPARE_STRING(first, "#")) {
		PHALCON_INIT_VAR(c2);
		ZVAL_STRING(c2, "#", 1);
		PHALCON_INIT_VAR(c3);
		ZVAL_STRING(c3, "\\#", 1);
		PHALCON_INIT_VAR(pcre_pattern);
		phalcon_fast_str_replace(pcre_pattern, c2, c3, pattern TSRMLS_CC);
		
		PHALCON_INIT_VAR(have_bracket);
		phalcon_fast_strpos_str(have_bracket, pcre_pattern, SL("{") TSRMLS_CC);
		if (zend_is_true(have_bracket)) {
			PHALCON_INIT_VAR(matches);
			ZVAL_NULL(matches);
			
			PHALCON_INIT_VAR(match_position);
			ZVAL_LONG(match_position, 1);
			
			PHALCON_INIT_VAR(p0[0]);
			ZVAL_STRING(p0[0], "#{([a-zA-Z][a-zA-Z0-9\\_\\-]+)(:([^}]+))*}#", 1);
			p0[1] = pcre_pattern;
			Z_SET_ISREF_P(matches);
			p0[2] = matches;
			p0[3] = set_order;
			
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
				fes_4c98_0:
					if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
						goto fee_4c98_0;
					}
					
					PHALCON_INIT_VAR(match);
					ZVAL_ZVAL(match, *hd, 1, 0);
					PHALCON_INIT_VAR(match_zero);
					phalcon_array_fetch_long(&match_zero, match, 0, PH_NOISY_CC);
					
					PHALCON_INIT_VAR(match_one);
					phalcon_array_fetch_long(&match_one, match, 1, PH_NOISY_CC);
					eval_int = phalcon_array_isset_long(match, 3);
					if (eval_int) {
						PHALCON_INIT_VAR(match_two);
						phalcon_array_fetch_long(&match_two, match, 3, PH_NOISY_CC);
						
						PHALCON_INIT_VAR(replace_pattern);
						PHALCON_CONCAT_SVS(replace_pattern, "(", match_two, ")");
					} else {
						PHALCON_INIT_VAR(replace_pattern);
						ZVAL_STRING(replace_pattern, "(.*)", 1);
					}
					
					PHALCON_INIT_VAR(new_pcre_pattern);
					phalcon_fast_str_replace(new_pcre_pattern, match_zero, replace_pattern, pcre_pattern TSRMLS_CC);
					PHALCON_CPY_WRT(pcre_pattern, new_pcre_pattern);
					phalcon_array_update_zval(&route_paths, match_one, &match_position, PH_COPY | PH_SEPARATE TSRMLS_CC);
					PHALCON_SEPARATE(match_position);
					increment_function(match_position);
					zend_hash_move_forward_ex(ah0, &hp0);
					goto fes_4c98_0;
				fee_4c98_0:
				if(0){}
				
			}
		}
		
		PHALCON_INIT_VAR(compiled_pattern);
		PHALCON_CALL_METHOD_PARAMS_1(compiled_pattern, this_ptr, "compilepattern", pcre_pattern, PH_NO_CHECK);
	} else {
		PHALCON_CPY_WRT(compiled_pattern, pattern);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_pattern"), pattern TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_compiledPattern"), compiled_pattern TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_paths"), route_paths TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Router_Route, getRouteId){

	zval *route_id = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(route_id);
	phalcon_read_property(&route_id, this_ptr, SL("_routeId"), PH_NOISY_CC);
	
	RETURN_CCTOR(route_id);
}

PHP_METHOD(Phalcon_Mvc_Router_Route, getPattern){

	zval *pattern = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(pattern);
	phalcon_read_property(&pattern, this_ptr, SL("_pattern"), PH_NOISY_CC);
	
	RETURN_CCTOR(pattern);
}

PHP_METHOD(Phalcon_Mvc_Router_Route, getCompiledPattern){

	zval *pattern = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(pattern);
	phalcon_read_property(&pattern, this_ptr, SL("_compiledPattern"), PH_NOISY_CC);
	
	RETURN_CCTOR(pattern);
}

PHP_METHOD(Phalcon_Mvc_Router_Route, getPaths){

	zval *paths = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(paths);
	phalcon_read_property(&paths, this_ptr, SL("_paths"), PH_NOISY_CC);
	
	RETURN_CCTOR(paths);
}

PHP_METHOD(Phalcon_Mvc_Router_Route, setHttpMethods){

	zval *http_methods = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &http_methods) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_methods"), http_methods TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Router_Route, getHttpMethods){

	zval *methods = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(methods);
	phalcon_read_property(&methods, this_ptr, SL("_methods"), PH_NOISY_CC);
	
	RETURN_CCTOR(methods);
}

