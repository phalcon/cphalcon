
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Url
 *
 * This components aids in the generation of: URIs, URLs and Paths
 *
 *<code>
 *
 * //Generate a url appending a uri to the base Uri
 * echo $url->get('products/edit/1');
 *
 * //Generate a url for a predefined route
 * echo $url->get(array('for' => 'blog-post', 'title' => 'some-cool-stuff', 'year' => '2012'));
 *
 *</code>
 */

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Url, setDI){

	zval *dependency_injector;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_url_exception_ce, "The dependency injector must be an Object");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Mvc_Url, getDI){

	zval *dependency_injector;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Sets a prefix to all the urls generated
 *
 *<code>
 *$url->setBasePath('/invo/');
 *</code>
 *
 * @param string $baseUri
 */
PHP_METHOD(Phalcon_Mvc_Url, setBaseUri){

	zval *base_uri;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &base_uri) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_baseUri"), base_uri TSRMLS_CC);
	
}

/**
 * Returns the prefix for all the generated urls. By default /
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, getBaseUri){

	zval *base_uri = NULL, *slash, *one, *minus_one = NULL, *php_self;
	zval *dirname, *dir_parts, *slice, *uri = NULL;
	zval *g0 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(base_uri);
	phalcon_read_property(&base_uri, this_ptr, SL("_baseUri"), PH_NOISY_CC);
	if (Z_TYPE_P(base_uri) == IS_NULL) {
		PHALCON_INIT_VAR(slash);
		ZVAL_STRING(slash, "/", 1);
		phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
		eval_int = phalcon_array_isset_string(g0, SS("PHP_SELF"));
		if (eval_int) {
			PHALCON_INIT_VAR(one);
			ZVAL_LONG(one, 1);
			
			PHALCON_INIT_VAR(c0);
			ZVAL_LONG(c0, -1);
			PHALCON_CPY_WRT(minus_one, c0);
			
			PHALCON_INIT_VAR(php_self);
			phalcon_array_fetch_string(&php_self, g0, SL("PHP_SELF"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(dirname);
			PHALCON_CALL_FUNC_PARAMS_1(dirname, "dirname", php_self);
			
			PHALCON_INIT_VAR(dir_parts);
			phalcon_fast_explode(dir_parts, slash, dirname TSRMLS_CC);
			
			PHALCON_INIT_VAR(slice);
			PHALCON_CALL_FUNC_PARAMS_3(slice, "array_slice", dir_parts, one, minus_one);
			
			PHALCON_INIT_VAR(uri);
			phalcon_fast_join(uri, slash, slice TSRMLS_CC);
		} else {
			PHALCON_INIT_NVAR(uri);
			ZVAL_STRING(uri, "", 1);
		}
		
		if (PHALCON_COMPARE_STRING(uri, "")) {
			PHALCON_CPY_WRT(base_uri, slash);
		} else {
			PHALCON_INIT_NVAR(base_uri);
			PHALCON_CONCAT_VVV(base_uri, slash, uri, slash);
		}
		
		phalcon_update_property_zval(this_ptr, SL("_baseUri"), base_uri TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(base_uri);
}

/**
 * Sets a base paths for all the generated paths
 *
 *<code>
 *$url->setBasePath('/var/www/');
 *</code>
 *
 * @param string $basePath
 */
PHP_METHOD(Phalcon_Mvc_Url, setBasePath){

	zval *base_path;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &base_path) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_basePath"), base_path TSRMLS_CC);
	
}

/**
 * Returns a base path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, getBasePath){

	zval *base_path;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(base_path);
	phalcon_read_property(&base_path, this_ptr, SL("_basePath"), PH_NOISY_CC);
	
	RETURN_CCTOR(base_path);
}

/**
 * Generates a URL
 *
 * @param string|array $uri
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, get){

	zval *uri = NULL, *base_uri, *dependency_injector, *service;
	zval *router, *route_name, *route, *exception_message;
	zval *pattern, *replaced_pattern = NULL, *controller_name;
	zval *wildcard = NULL, *action_name, *have_bracket;
	zval *matches, *match_position, *set_order = NULL, *names_pattern;
	zval *have_variables = NULL, *match = NULL, *match_zero = NULL, *match_one = NULL;
	zval *value = NULL, *new_pcre_pattern = NULL, *final_uri;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!uri) {
		PHALCON_INIT_NVAR(uri);
	}
	
	PHALCON_INIT_VAR(base_uri);
	PHALCON_CALL_METHOD(base_uri, this_ptr, "getbaseuri", PH_NO_CHECK);
	if (Z_TYPE_P(uri) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_string(uri, SS("for"));
		if (!eval_int) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_url_exception_ce, "It's necessary to define the route name with the parameter \"for\"");
			return;
		}
		
		PHALCON_INIT_VAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (!zend_is_true(dependency_injector)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_url_exception_ce, "A dependency injector container is required to obtain the \"url\" service");
			return;
		}
		
		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "router", 1);
		
		PHALCON_INIT_VAR(router);
		PHALCON_CALL_METHOD_PARAMS_1(router, dependency_injector, "getshared", service, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(route_name);
		phalcon_array_fetch_string(&route_name, uri, SL("for"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(route);
		PHALCON_CALL_METHOD_PARAMS_1(route, router, "getroutebyname", route_name, PH_NO_CHECK);
		if (Z_TYPE_P(route) != IS_OBJECT) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Cannot obtain a route using the name \"", route_name, "\"");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_url_exception_ce, exception_message);
			return;
		}
		
		PHALCON_INIT_VAR(pattern);
		PHALCON_CALL_METHOD(pattern, route, "getpattern", PH_NO_CHECK);
		PHALCON_CPY_WRT(replaced_pattern, pattern);
		eval_int = phalcon_array_isset_string(uri, SS("controller"));
		if (eval_int) {
			PHALCON_INIT_VAR(controller_name);
			phalcon_array_fetch_string(&controller_name, uri, SL("controller"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(wildcard);
			ZVAL_STRING(wildcard, ":controller", 1);
			
			PHALCON_INIT_VAR(r0);
			phalcon_fast_str_replace(r0, wildcard, controller_name, replaced_pattern TSRMLS_CC);
			PHALCON_CPY_WRT(replaced_pattern, r0);
		}
		
		eval_int = phalcon_array_isset_string(uri, SS("action"));
		if (eval_int) {
			PHALCON_INIT_VAR(action_name);
			phalcon_array_fetch_string(&action_name, uri, SL("action"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(wildcard);
			ZVAL_STRING(wildcard, ":action", 1);
			
			PHALCON_INIT_VAR(r1);
			phalcon_fast_str_replace(r1, wildcard, action_name, replaced_pattern TSRMLS_CC);
			PHALCON_CPY_WRT(replaced_pattern, r1);
		}
		
		PHALCON_INIT_VAR(have_bracket);
		phalcon_fast_strpos_str(have_bracket, replaced_pattern, SL("{") TSRMLS_CC);
		if (PHALCON_IS_NOT_FALSE(have_bracket)) {
			PHALCON_INIT_VAR(matches);
			
			PHALCON_INIT_VAR(match_position);
			ZVAL_LONG(match_position, 1);
			
			PHALCON_INIT_VAR(t0);
			ZVAL_LONG(t0, 2);
			PHALCON_CPY_WRT(set_order, t0);
			
			PHALCON_INIT_VAR(names_pattern);
			ZVAL_STRING(names_pattern, "#{([a-zA-Z][a-zA-Z0-9\\_\\-]+)(:([^}]+))*}#", 1);
			p0[0] = names_pattern;
			p0[1] = replaced_pattern;
			Z_SET_ISREF_P(matches);
			p0[2] = matches;
			p0[3] = set_order;
			
			PHALCON_INIT_VAR(r2);
			PHALCON_CALL_FUNC_PARAMS(r2, "preg_match_all", 4, p0);
			Z_UNSET_ISREF_P(p0[2]);
			PHALCON_CPY_WRT(have_variables, r2);
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
					eval_int = phalcon_array_isset(uri, match_one);
					if (eval_int) {
						PHALCON_INIT_NVAR(value);
						phalcon_array_fetch(&value, uri, match_one, PH_NOISY_CC);
						
						PHALCON_INIT_NVAR(new_pcre_pattern);
						phalcon_fast_str_replace(new_pcre_pattern, match_zero, value, replaced_pattern TSRMLS_CC);
						PHALCON_CPY_WRT(replaced_pattern, new_pcre_pattern);
					}
					
					zend_hash_move_forward_ex(ah0, &hp0);
					goto ph_cycle_start_0;
					
				ph_cycle_end_0:
				if(0){}
				
			}
		}
		
		
		RETURN_CCTOR(replaced_pattern);
	} else {
		PHALCON_INIT_VAR(final_uri);
		PHALCON_CONCAT_VV(final_uri, base_uri, uri);
		
		RETURN_CTOR(final_uri);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Generates a local path
 *
 * @param string $path
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, path){

	zval *path = NULL, *base_path, *final_path;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!path) {
		PHALCON_INIT_NVAR(path);
	}
	
	PHALCON_INIT_VAR(base_path);
	phalcon_read_property(&base_path, this_ptr, SL("_basePath"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(final_path);
	PHALCON_CONCAT_VV(final_path, base_path, path);
	
	RETURN_CTOR(final_path);
}

