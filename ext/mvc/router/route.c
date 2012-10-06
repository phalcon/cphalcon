
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

/**
 * Phalcon\Mvc\Router\Route
 *
 * This class represents every route defined in the router.
 */


/**
 * Phalcon\Mvc\Router\Route constructor
 *
 * @param string $pattern
 * @param array $paths
 * @param array|string $httpMethods
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, __construct){

	zval *pattern, *paths = NULL, *http_methods = NULL, *unique_id = NULL;
	zval *route_id = NULL, *one, *next_id;

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
	
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "reconfigure", pattern, paths, PH_NO_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_methods"), http_methods TSRMLS_CC);
	PHALCON_OBSERVE_VAR(unique_id);
	phalcon_read_static_property(&unique_id, SL("phalcon\\mvc\\router\\route"), SL("_uniqueId") TSRMLS_CC);
	if (Z_TYPE_P(unique_id) == IS_NULL) {
		PHALCON_INIT_NVAR(unique_id);
		ZVAL_LONG(unique_id, 0);
	}
	
	PHALCON_CPY_WRT(route_id, unique_id);
	phalcon_update_property_zval(this_ptr, SL("_id"), route_id TSRMLS_CC);
	
	PHALCON_INIT_VAR(one);
	ZVAL_LONG(one, 1);
	
	PHALCON_INIT_VAR(next_id);
	phalcon_add_function(next_id, unique_id, one TSRMLS_CC);
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

	zval *pattern, *compiled_pattern = NULL, *have_double_dot;
	zval *id_pattern, *have_wildcard = NULL, *wildcard = NULL;
	zval *pattern_copy = NULL, *params_pattern, *int_pattern;
	zval *have_parenthesis, *final_pattern = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &pattern) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(compiled_pattern, pattern);
	
	PHALCON_INIT_VAR(have_double_dot);
	phalcon_fast_strpos_str(have_double_dot, pattern, SL(":") TSRMLS_CC);
	if (PHALCON_IS_NOT_FALSE(have_double_dot)) {
		PHALCON_INIT_VAR(id_pattern);
		ZVAL_STRING(id_pattern, "/([a-zA-Z0-9\\_]+)", 1);
		
		PHALCON_INIT_VAR(have_wildcard);
		phalcon_fast_strpos_str(have_wildcard, pattern, SL("/:module") TSRMLS_CC);
		if (PHALCON_IS_NOT_FALSE(have_wildcard)) {
			PHALCON_INIT_VAR(wildcard);
			ZVAL_STRING(wildcard, "/:module", 1);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
			
			PHALCON_INIT_VAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, wildcard, id_pattern, pattern_copy TSRMLS_CC);
		}
		
		PHALCON_INIT_NVAR(have_wildcard);
		phalcon_fast_strpos_str(have_wildcard, pattern, SL("/:controller") TSRMLS_CC);
		if (PHALCON_IS_NOT_FALSE(have_wildcard)) {
			PHALCON_INIT_NVAR(wildcard);
			ZVAL_STRING(wildcard, "/:controller", 1);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
			
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, wildcard, id_pattern, pattern_copy TSRMLS_CC);
		}
		
		PHALCON_INIT_NVAR(have_wildcard);
		phalcon_fast_strpos_str(have_wildcard, pattern, SL("/:action") TSRMLS_CC);
		if (PHALCON_IS_NOT_FALSE(have_wildcard)) {
			PHALCON_INIT_NVAR(wildcard);
			ZVAL_STRING(wildcard, "/:action", 1);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
			
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, wildcard, id_pattern, pattern_copy TSRMLS_CC);
		}
		
		PHALCON_INIT_NVAR(have_wildcard);
		phalcon_fast_strpos_str(have_wildcard, pattern, SL("/:params") TSRMLS_CC);
		if (PHALCON_IS_NOT_FALSE(have_wildcard)) {
			PHALCON_INIT_NVAR(wildcard);
			ZVAL_STRING(wildcard, "/:params", 1);
			
			PHALCON_INIT_VAR(params_pattern);
			ZVAL_STRING(params_pattern, "(/.*)*", 1);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
			
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, wildcard, params_pattern, pattern_copy TSRMLS_CC);
		}
		
		PHALCON_INIT_NVAR(have_wildcard);
		phalcon_fast_strpos_str(have_wildcard, pattern, SL("/:int") TSRMLS_CC);
		if (PHALCON_IS_NOT_FALSE(have_wildcard)) {
			PHALCON_INIT_NVAR(wildcard);
			ZVAL_STRING(wildcard, "/:int", 1);
			
			PHALCON_INIT_VAR(int_pattern);
			ZVAL_STRING(int_pattern, "/([0-9]+)", 1);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
			
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, wildcard, int_pattern, pattern_copy TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(have_parenthesis);
	phalcon_fast_strpos_str(have_parenthesis, compiled_pattern, SL("(") TSRMLS_CC);
	if (PHALCON_IS_NOT_FALSE(have_parenthesis)) {
		PHALCON_INIT_VAR(final_pattern);
		PHALCON_CONCAT_SVS(final_pattern, "#^", compiled_pattern, "$#");
	} else {
		PHALCON_CPY_WRT(final_pattern, compiled_pattern);
	}
	
	
	RETURN_CCTOR(final_pattern);
}

/**
 * Set one or more HTTP methods that constraint the matching of the route
 *
 * @param string|array $httpMethods
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, via){

	zval *http_methods;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &http_methods) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_methods"), http_methods TSRMLS_CC);
	
}

/**
 * Reconfigure the route adding a new pattern and a set of paths
 *
 * @param string $pattern
 * @param array $paths
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, reConfigure){

	zval *pattern, *paths = NULL, *double_colon, *parts, *part_zero;
	zval *controller_name, *route_paths = NULL, *part_one;
	zval *one, *zero, *first, *have_bracket, *sharp, *escaped_sharp;
	zval *pcre_pattern = NULL, *matches, *match_position;
	zval *set_order = NULL, *names_pattern, *have_variables = NULL;
	zval *match = NULL, *match_zero = NULL, *match_one = NULL, *match_two = NULL;
	zval *replace_pattern = NULL, *new_pcre_pattern = NULL;
	zval *compiled_pattern = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!paths) {
		PHALCON_INIT_NVAR(paths);
	}
	
	if (Z_TYPE_P(pattern) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "The pattern must be string");
		return;
	}
	if (Z_TYPE_P(paths) != IS_NULL) {
		if (Z_TYPE_P(paths) == IS_STRING) {
			PHALCON_INIT_VAR(double_colon);
			ZVAL_STRING(double_colon, "::", 1);
			
			PHALCON_INIT_VAR(parts);
			phalcon_fast_explode(parts, double_colon, paths TSRMLS_CC);
			
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
		PHALCON_INIT_NVAR(route_paths);
		array_init(route_paths);
	}
	
	PHALCON_INIT_VAR(one);
	ZVAL_LONG(one, 1);
	
	PHALCON_INIT_VAR(zero);
	ZVAL_LONG(zero, 0);
	
	PHALCON_INIT_VAR(first);
	PHALCON_CALL_FUNC_PARAMS_3(first, "substr", pattern, zero, one);
	if (!PHALCON_COMPARE_STRING(first, "#")) {
		PHALCON_INIT_VAR(have_bracket);
		phalcon_fast_strpos_str(have_bracket, pattern, SL("{") TSRMLS_CC);
		if (PHALCON_IS_NOT_FALSE(have_bracket)) {
			PHALCON_INIT_VAR(sharp);
			ZVAL_STRING(sharp, "#", 1);
			
			PHALCON_INIT_VAR(escaped_sharp);
			ZVAL_STRING(escaped_sharp, "\\#", 1);
			
			PHALCON_INIT_VAR(pcre_pattern);
			phalcon_fast_str_replace(pcre_pattern, sharp, escaped_sharp, pattern TSRMLS_CC);
			
			PHALCON_INIT_VAR(matches);
			
			PHALCON_INIT_VAR(match_position);
			ZVAL_LONG(match_position, 1);
			
			PHALCON_INIT_VAR(t0);
			ZVAL_LONG(t0, 2);
			PHALCON_CPY_WRT(set_order, t0);
			
			PHALCON_INIT_VAR(names_pattern);
			ZVAL_STRING(names_pattern, "#{([a-zA-Z][a-zA-Z0-9\\_\\-]*)(:([^}]+))*}#", 1);
			p0[0] = names_pattern;
			p0[1] = pcre_pattern;
			Z_SET_ISREF_P(matches);
			p0[2] = matches;
			p0[3] = set_order;
			
			PHALCON_INIT_VAR(r0);
			PHALCON_CALL_FUNC_PARAMS(r0, "preg_match_all", 4, p0);
			Z_UNSET_ISREF_P(p0[2]);
			PHALCON_CPY_WRT(have_variables, r0);
			if (zend_is_true(have_variables)) {
				
				if (!phalcon_valid_foreach(matches TSRMLS_CC)) {
					return;
				}
				
				ah0 = Z_ARRVAL_P(matches);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				
				ph_cycle_start_0:
				
					if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
						goto ph_cycle_end_0;
					}
					
					PHALCON_GET_FOREACH_VALUE(match);
					
					PHALCON_INIT_NVAR(match_zero);
					phalcon_array_fetch_long(&match_zero, match, 0, PH_NOISY_CC);
					
					PHALCON_INIT_NVAR(match_one);
					phalcon_array_fetch_long(&match_one, match, 1, PH_NOISY_CC);
					eval_int = phalcon_array_isset_long(match, 3);
					if (eval_int) {
						PHALCON_INIT_NVAR(match_two);
						phalcon_array_fetch_long(&match_two, match, 3, PH_NOISY_CC);
						
						PHALCON_INIT_NVAR(replace_pattern);
						PHALCON_CONCAT_SVS(replace_pattern, "(", match_two, ")");
					} else {
						PHALCON_INIT_NVAR(replace_pattern);
						ZVAL_STRING(replace_pattern, "([^/]*)", 1);
					}
					
					PHALCON_INIT_NVAR(new_pcre_pattern);
					phalcon_fast_str_replace(new_pcre_pattern, match_zero, replace_pattern, pcre_pattern TSRMLS_CC);
					PHALCON_CPY_WRT(pcre_pattern, new_pcre_pattern);
					phalcon_array_update_zval(&route_paths, match_one, &match_position, PH_COPY | PH_SEPARATE TSRMLS_CC);
					PHALCON_SEPARATE(match_position);
					increment_function(match_position);
					
					zend_hash_move_forward_ex(ah0, &hp0);
					goto ph_cycle_start_0;
					
				ph_cycle_end_0:
				if(0){}
				
			}
		} else {
			PHALCON_CPY_WRT(pcre_pattern, pattern);
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

/**
 * Returns the route's name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getName){

	zval *name;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(name);
	phalcon_read_property(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
	RETURN_CCTOR(name);
}

/**
 * Sets the route's name
 *
 * @param string $name
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, setName){

	zval *name;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);
	
	RETURN_CTORW(this_ptr);
}

/**
 * Sets a set of HTTP methods that constraint the matching of the route
 *
 * @param string|array $httpMethods
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, setHttpMethods){

	zval *http_methods;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &http_methods) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_methods"), http_methods TSRMLS_CC);
	
	RETURN_CTORW(this_ptr);
}

/**
 * Returns the route's id
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getRouteId){

	zval *route_id;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(route_id);
	phalcon_read_property(&route_id, this_ptr, SL("_id"), PH_NOISY_CC);
	
	RETURN_CCTOR(route_id);
}

/**
 * Returns the route's pattern
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getPattern){

	zval *pattern;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(pattern);
	phalcon_read_property(&pattern, this_ptr, SL("_pattern"), PH_NOISY_CC);
	
	RETURN_CCTOR(pattern);
}

/**
 * Returns the route's pattern
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getCompiledPattern){

	zval *pattern;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(pattern);
	phalcon_read_property(&pattern, this_ptr, SL("_compiledPattern"), PH_NOISY_CC);
	
	RETURN_CCTOR(pattern);
}

/**
 * Returns the paths
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getPaths){

	zval *paths;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(paths);
	phalcon_read_property(&paths, this_ptr, SL("_paths"), PH_NOISY_CC);
	
	RETURN_CCTOR(paths);
}

/**
 * Returns the HTTP methods that constraint matching the route
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getHttpMethods){

	zval *methods;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(methods);
	phalcon_read_property(&methods, this_ptr, SL("_methods"), PH_NOISY_CC);
	
	RETURN_CCTOR(methods);
}

/**
 * Resets the internal route id generator
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, reset){

	zval *t0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 0);
	phalcon_update_static_property(SL("phalcon\\mvc\\router\\route"), SL("_uniqueId"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

