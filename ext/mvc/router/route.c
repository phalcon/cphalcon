
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
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/array.h"

/**
 * Phalcon\Mvc\Router\Route
 *
 * This class represents every route added to the router
 */


/**
 * Phalcon\Mvc\Router\Route initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Router_Route){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Router, Route, mvc_router_route, phalcon_mvc_router_route_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_pattern"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_compiledPattern"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_paths"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_methods"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_converters"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_id"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_uniqueId"), ZEND_ACC_STATIC|ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_router_route_ce TSRMLS_CC, 1, phalcon_mvc_router_routeinterface_ce);

	return SUCCESS;
}

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
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	if (!http_methods) {
		PHALCON_INIT_VAR(http_methods);
	}
	
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "reconfigure", pattern, paths);
	phalcon_update_property_zval(this_ptr, SL("_methods"), http_methods TSRMLS_CC);
	
	PHALCON_OBS_VAR(unique_id);
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

	zval *pattern, *compiled_pattern = NULL, *id_pattern;
	zval *wildcard = NULL, *pattern_copy = NULL, *params_pattern;
	zval *int_pattern, *final_pattern = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &pattern) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_CPY_WRT(compiled_pattern, pattern);
	if (phalcon_memnstr_str(pattern, SL(":") TSRMLS_CC)) {
	
		/** 
		 * This is pattern for identifiers
		 */
		PHALCON_INIT_VAR(id_pattern);
		ZVAL_STRING(id_pattern, "/([a-zA-Z0-9\\_\\-]+)", 1);
	
		/** 
		 * Replace the module part
		 */
		if (phalcon_memnstr_str(pattern, SL("/:module") TSRMLS_CC)) {
			PHALCON_INIT_VAR(wildcard);
			ZVAL_STRING(wildcard, "/:module", 1);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
	
			PHALCON_INIT_VAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, wildcard, id_pattern, pattern_copy TSRMLS_CC);
		}
	
		/** 
		 * Replace the controller placeholder
		 */
		if (phalcon_memnstr_str(pattern, SL("/:controller") TSRMLS_CC)) {
			PHALCON_INIT_NVAR(wildcard);
			ZVAL_STRING(wildcard, "/:controller", 1);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
	
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, wildcard, id_pattern, pattern_copy TSRMLS_CC);
		}
	
		/** 
		 * Replace the namespace placeholder
		 */
		if (phalcon_memnstr_str(pattern, SL("/:namespace") TSRMLS_CC)) {
			PHALCON_INIT_NVAR(wildcard);
			ZVAL_STRING(wildcard, "/:namespace", 1);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
	
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, wildcard, id_pattern, pattern_copy TSRMLS_CC);
		}
	
		/** 
		 * Replace the action placeholder
		 */
		if (phalcon_memnstr_str(pattern, SL("/:action") TSRMLS_CC)) {
			PHALCON_INIT_NVAR(wildcard);
			ZVAL_STRING(wildcard, "/:action", 1);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
	
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, wildcard, id_pattern, pattern_copy TSRMLS_CC);
		}
	
		/** 
		 * Replace the params placeholder
		 */
		if (phalcon_memnstr_str(pattern, SL("/:params") TSRMLS_CC)) {
			PHALCON_INIT_NVAR(wildcard);
			ZVAL_STRING(wildcard, "/:params", 1);
	
			PHALCON_INIT_VAR(params_pattern);
			ZVAL_STRING(params_pattern, "(/.*)*", 1);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
	
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, wildcard, params_pattern, pattern_copy TSRMLS_CC);
		}
	
		/** 
		 * Replace the int placeholder
		 */
		if (phalcon_memnstr_str(pattern, SL("/:int") TSRMLS_CC)) {
			PHALCON_INIT_NVAR(wildcard);
			ZVAL_STRING(wildcard, "/:int", 1);
	
			PHALCON_INIT_VAR(int_pattern);
			ZVAL_STRING(int_pattern, "/([0-9]+)", 1);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
	
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, wildcard, int_pattern, pattern_copy TSRMLS_CC);
		}
	}
	
	/** 
	 * Check if the pattern has paranteshes to add the regex delimiters
	 */
	if (phalcon_memnstr_str(compiled_pattern, SL("(") TSRMLS_CC)) {
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
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, via){

	zval *http_methods;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &http_methods) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_methods"), http_methods TSRMLS_CC);
	RETURN_CTORW(this_ptr);
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
	zval *pcre_pattern = NULL, *compiled_pattern = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
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
	
			PHALCON_OBS_VAR(part_zero);
			phalcon_array_fetch_long(&part_zero, parts, 0, PH_NOISY_CC);
	
			PHALCON_INIT_VAR(controller_name);
			phalcon_fast_strtolower(controller_name, part_zero);
	
			PHALCON_INIT_VAR(route_paths);
			array_init_size(route_paths, 1);
			phalcon_array_update_string(&route_paths, SL("controller"), &controller_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
			if (phalcon_array_isset_long(parts, 1)) {
				PHALCON_OBS_VAR(part_one);
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
	
	/** 
	 * If the route starts with '#' we assume that is a regular expression
	 */
	if (!phalcon_start_with_str(pattern, SL("#"))) {
		if (phalcon_memnstr_str(pattern, SL("{") TSRMLS_CC)) {
			PHALCON_INIT_VAR(pcre_pattern);
			phalcon_extract_named_params(pcre_pattern, pattern, route_paths);
		} else {
			PHALCON_CPY_WRT(pcre_pattern, pattern);
		}
	
		/** 
		 * Transform the route to a regular expression
		 */
		PHALCON_INIT_VAR(compiled_pattern);
		PHALCON_CALL_METHOD_PARAMS_1(compiled_pattern, this_ptr, "compilepattern", pcre_pattern);
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


	RETURN_MEMBER(this_ptr, "_name");
}

/**
 * Sets the route's name
 *
 * @param string $name
 * @return Phalcon\Mvc\Router\RouteInterface
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
 * @return Phalcon\Mvc\Router\RouteInterface
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


	RETURN_MEMBER(this_ptr, "_id");
}

/**
 * Returns the route's pattern
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getPattern){


	RETURN_MEMBER(this_ptr, "_pattern");
}

/**
 * Returns the route's compiled pattern
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getCompiledPattern){


	RETURN_MEMBER(this_ptr, "_compiledPattern");
}

/**
 * Returns the paths
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getPaths){


	RETURN_MEMBER(this_ptr, "_paths");
}

/**
 * Returns the paths using positions as keys and names as values
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getReversedPaths){

	zval *reversed, *paths, *position = NULL, *path = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(reversed);
	array_init(reversed);
	
	PHALCON_OBS_VAR(paths);
	phalcon_read_property(&paths, this_ptr, SL("_paths"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(paths TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(paths);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_KEY(path, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(position);
	
		phalcon_array_update_zval(&reversed, position, &path, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	RETURN_CTOR(reversed);
}

/**
 * Returns the HTTP methods that constraint matching the route
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getHttpMethods){


	RETURN_MEMBER(this_ptr, "_methods");
}

/**
 * Adds a converter to perform an additional transformation for certain parameter
 *
 * @param string $name
 * @param callable $converter
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, convert){

	zval *name, *converter;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &name, &converter) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_array(this_ptr, SL("_converters"), name, converter TSRMLS_CC);
	RETURN_CTORW(this_ptr);
}

/**
 * Returns the router converter
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getConverters){


	RETURN_MEMBER(this_ptr, "_converters");
}

/**
 * Resets the internal route id generator
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, reset){

	zval *zero;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(zero);
	ZVAL_LONG(zero, 0);
	phalcon_update_static_property(SL("phalcon\\mvc\\router\\route"), SL("_uniqueId"), zero TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

