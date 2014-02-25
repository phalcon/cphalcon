
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/router/route.h"
#include "mvc/router/routeinterface.h"
#include "mvc/router/exception.h"
#include "mvc/router/group.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/framework/router.h"
#include "kernel/hash.h"

/**
 * Phalcon\Mvc\Router\Route
 *
 * This class represents every route added to the router
 */
zend_class_entry *phalcon_mvc_router_route_ce;

PHP_METHOD(Phalcon_Mvc_Router_Route, __construct);
PHP_METHOD(Phalcon_Mvc_Router_Route, compilePattern);
PHP_METHOD(Phalcon_Mvc_Router_Route, via);
PHP_METHOD(Phalcon_Mvc_Router_Route, reConfigure);
PHP_METHOD(Phalcon_Mvc_Router_Route, getName);
PHP_METHOD(Phalcon_Mvc_Router_Route, setName);
PHP_METHOD(Phalcon_Mvc_Router_Route, beforeMatch);
PHP_METHOD(Phalcon_Mvc_Router_Route, getBeforeMatch);
PHP_METHOD(Phalcon_Mvc_Router_Route, getRouteId);
PHP_METHOD(Phalcon_Mvc_Router_Route, getPattern);
PHP_METHOD(Phalcon_Mvc_Router_Route, getCompiledPattern);
PHP_METHOD(Phalcon_Mvc_Router_Route, getPaths);
PHP_METHOD(Phalcon_Mvc_Router_Route, getReversedPaths);
PHP_METHOD(Phalcon_Mvc_Router_Route, setHttpMethods);
PHP_METHOD(Phalcon_Mvc_Router_Route, getHttpMethods);
PHP_METHOD(Phalcon_Mvc_Router_Route, setHostname);
PHP_METHOD(Phalcon_Mvc_Router_Route, getHostname);
PHP_METHOD(Phalcon_Mvc_Router_Route, setGroup);
PHP_METHOD(Phalcon_Mvc_Router_Route, getGroup);
PHP_METHOD(Phalcon_Mvc_Router_Route, convert);
PHP_METHOD(Phalcon_Mvc_Router_Route, getConverters);
PHP_METHOD(Phalcon_Mvc_Router_Route, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_setgroup, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_beforematch, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_sethostname, 0, 0, 1)
	ZEND_ARG_INFO(0, hostname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_convert, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, converter)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_router_route_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Router_Route, __construct, arginfo_phalcon_mvc_router_route___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Router_Route, compilePattern, arginfo_phalcon_mvc_router_routeinterface_compilepattern, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, via, arginfo_phalcon_mvc_router_routeinterface_via, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, reConfigure, arginfo_phalcon_mvc_router_routeinterface_reconfigure, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, setName, arginfo_phalcon_mvc_router_routeinterface_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, beforeMatch, arginfo_phalcon_mvc_router_route_beforematch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getBeforeMatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getRouteId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getPattern, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getCompiledPattern, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getPaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getReversedPaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, setHttpMethods, arginfo_phalcon_mvc_router_routeinterface_sethttpmethods, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getHttpMethods, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, setHostname, arginfo_phalcon_mvc_router_route_sethostname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getHostname, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, setGroup, arginfo_phalcon_mvc_router_route_setgroup, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getGroup, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, convert, arginfo_phalcon_mvc_router_route_convert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getConverters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, reset, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Router\Route initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Router_Route){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Router, Route, mvc_router_route, phalcon_mvc_router_route_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_pattern"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_compiledPattern"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_paths"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_methods"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_hostname"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_converters"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_id"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_beforeMatch"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_group"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_router_route_ce, SL("_uniqueId"), 0, ZEND_ACC_STATIC|ZEND_ACC_PROTECTED TSRMLS_CC);

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
	zval *route_id = NULL;
	int separate = 0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &pattern, &paths, &http_methods);
	
	if (!paths) {
		paths = PHALCON_GLOBAL(z_null);
	}
	
	if (!http_methods) {
		http_methods = PHALCON_GLOBAL(z_null);
	}
	
	/** 
	 * Configure the route (extract parameters, paths, etc)
	 */
	PHALCON_CALL_METHOD(NULL, this_ptr, "reconfigure", pattern, paths);
	
	/** 
	 * Update the HTTP method constraints
	 */
	phalcon_update_property_this(this_ptr, SL("_methods"), http_methods TSRMLS_CC);
	
	/** 
	 * Get the unique Id from the static member _uniqueId
	 */
	unique_id = phalcon_fetch_static_property_ce(phalcon_mvc_router_route_ce, SL("_uniqueId") TSRMLS_CC);
	if (Z_REFCOUNT_P(unique_id) > 1) {
		PHALCON_INIT_VAR(unique_id);
		separate = 1;
	}

	if (Z_TYPE_P(unique_id) == IS_NULL) {
		ZVAL_LONG(unique_id, 0);
	}
	
	PHALCON_CPY_WRT_CTOR(route_id, unique_id); /* route_id is now separated from unique_id */
	phalcon_update_property_this(this_ptr, SL("_id"), route_id TSRMLS_CC);
	
	/* increment_function() will increment the value of the static property as well */
	increment_function(unique_id);
	if (separate) {
		phalcon_update_static_property_ce(phalcon_mvc_router_route_ce, SL("_uniqueId"), unique_id TSRMLS_CC);
	}
	
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
	zval wildcard, *pattern_copy = NULL, *params_pattern;
	zval *int_pattern;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &pattern);
	
	PHALCON_CPY_WRT(compiled_pattern, pattern);
	
	/** 
	 * If a pattern contains ':', maybe there are placeholders to replace
	 */
	if (phalcon_memnstr_str(pattern, SL(":"))) {
	
		/** 
		 * This is a pattern for valid identifiers
		 */
		PHALCON_INIT_VAR(id_pattern);
		ZVAL_STRING(id_pattern, "/([a-zA-Z0-9_-]++)", 1);
	
		/** 
		 * Replace the module part
		 */
		if (phalcon_memnstr_str(pattern, SL("/:module"))) {
			INIT_ZVAL(wildcard);
			ZVAL_STRING(&wildcard, "/:module", 0);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
	
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, &wildcard, id_pattern, pattern_copy);
		}
	
		/** 
		 * Replace the controller placeholder
		 */
		if (phalcon_memnstr_str(pattern, SL("/:controller"))) {
			INIT_ZVAL(wildcard);
			ZVAL_STRING(&wildcard, "/:controller", 0);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
	
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, &wildcard, id_pattern, pattern_copy);
		}
	
		/** 
		 * Replace the namespace placeholder
		 */
		if (phalcon_memnstr_str(pattern, SL("/:namespace"))) {
			INIT_ZVAL(wildcard)
			ZVAL_STRING(&wildcard, "/:namespace", 0);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
	
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, &wildcard, id_pattern, pattern_copy);
		}
	
		/** 
		 * Replace the action placeholder
		 */
		if (phalcon_memnstr_str(pattern, SL("/:action"))) {
			INIT_ZVAL(wildcard);
			ZVAL_STRING(&wildcard, "/:action", 0);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
	
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, &wildcard, id_pattern, pattern_copy);
		}
	
		/** 
		 * Replace the params placeholder
		 */
		if (phalcon_memnstr_str(pattern, SL("/:params"))) {
			INIT_ZVAL(wildcard);
			ZVAL_STRING(&wildcard, "/:params", 0);
	
			PHALCON_INIT_VAR(params_pattern);
			ZVAL_STRING(params_pattern, "(/.*+)?+", 1);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
	
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, &wildcard, params_pattern, pattern_copy);
		}
	
		/** 
		 * Replace the int placeholder
		 */
		if (phalcon_memnstr_str(pattern, SL("/:int"))) {
			INIT_ZVAL(wildcard);
			ZVAL_STRING(&wildcard, "/:int", 0);
	
			PHALCON_INIT_VAR(int_pattern);
			ZVAL_STRING(int_pattern, "/([0-9]++)", 1);
			PHALCON_CPY_WRT(pattern_copy, compiled_pattern);
	
			PHALCON_INIT_NVAR(compiled_pattern);
			phalcon_fast_str_replace(compiled_pattern, &wildcard, int_pattern, pattern_copy);
		}
	}
	
	/** 
	 * Check if the pattern has parantheses in order to add the regex delimiters
	 */
	if (phalcon_memnstr_str(compiled_pattern, SL("("))) {
		PHALCON_CONCAT_SVS(return_value, "#^", compiled_pattern, "$#");
		RETURN_MM();
	}
	
	/** 
	 * Square brackets are also checked
	 */
	if (phalcon_memnstr_str(compiled_pattern, SL("["))) {
		PHALCON_CONCAT_SVS(return_value, "#^", compiled_pattern, "$#");
		RETURN_MM();
	}
	
	RETURN_CCTOR(compiled_pattern);
}

/**
 * Set one or more HTTP methods that constraint the matching of the route
 *
 *<code>
 * $route->via('GET');
 * $route->via(array('GET', 'POST'));
 *</code>
 *
 * @param string|array $httpMethods
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, via){

	zval *http_methods;

	phalcon_fetch_params(0, 1, 0, &http_methods);
	
	phalcon_update_property_this(this_ptr, SL("_methods"), http_methods TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Reconfigure the route adding a new pattern and a set of paths
 *
 * @param string $pattern
 * @param array $paths
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, reConfigure){

	zval *pattern, *paths = NULL, *module_name = NULL, *controller_name = NULL;
	zval *action_name = NULL, *parts, *number_parts, *route_paths = NULL;
	zval *real_class_name = NULL, *namespace_name, *lower_name;
	zval *pcre_pattern = NULL, *compiled_pattern = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &pattern, &paths);
	
	if (!paths) {
		paths = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(pattern) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "The pattern must be string");
		return;
	}
	if (Z_TYPE_P(paths) != IS_NULL) {
		if (Z_TYPE_P(paths) == IS_STRING) {
	
			PHALCON_INIT_VAR(module_name);
	
			PHALCON_INIT_VAR(controller_name);
	
			PHALCON_INIT_VAR(action_name);
	
			/** 
			 * Explode the short paths using the :: separator
			 */
			PHALCON_INIT_VAR(parts);
			phalcon_fast_explode_str(parts, SL("::"), paths);
	
			PHALCON_INIT_VAR(number_parts);
			phalcon_fast_count(number_parts, parts TSRMLS_CC);
	
			/** 
			 * Create the array paths dynamically
			 */
	
			switch (phalcon_get_intval(number_parts)) {
	
				case 3:
					PHALCON_OBS_NVAR(module_name);
					phalcon_array_fetch_long(&module_name, parts, 0, PH_NOISY);
	
					PHALCON_OBS_NVAR(controller_name);
					phalcon_array_fetch_long(&controller_name, parts, 1, PH_NOISY);
	
					PHALCON_OBS_NVAR(action_name);
					phalcon_array_fetch_long(&action_name, parts, 2, PH_NOISY);
					break;
	
				case 2:
					PHALCON_OBS_NVAR(controller_name);
					phalcon_array_fetch_long(&controller_name, parts, 0, PH_NOISY);
	
					PHALCON_OBS_NVAR(action_name);
					phalcon_array_fetch_long(&action_name, parts, 1, PH_NOISY);
					break;
	
				case 1:
					PHALCON_OBS_NVAR(controller_name);
					phalcon_array_fetch_long(&controller_name, parts, 0, PH_NOISY);
					break;
	
			}
	
			PHALCON_INIT_VAR(route_paths);
			array_init(route_paths);
	
			/** 
			 * Process module name
			 */
			if (Z_TYPE_P(module_name) != IS_NULL) {
				phalcon_array_update_string(&route_paths, SL("module"), module_name, PH_COPY | PH_SEPARATE);
			}
	
			/** 
			 * Process controller name
			 */
			if (Z_TYPE_P(controller_name) != IS_NULL) {
	
				/** 
				 * Check if we need to obtain the namespace
				 */
				if (phalcon_memnstr_str(controller_name, SL("\\"))) {
	
					/** 
					 * Extract the real class name from the namespaced class
					 */
					PHALCON_INIT_VAR(real_class_name);
					phalcon_get_class_ns(real_class_name, controller_name, 0 TSRMLS_CC);
	
					/** 
					 * Extract the namespace from the namespaced class
					 */
					PHALCON_INIT_VAR(namespace_name);
					phalcon_get_ns_class(namespace_name, controller_name, 0 TSRMLS_CC);
	
					/** 
					 * Update the namespace
					 */
					if (zend_is_true(namespace_name)) {
						phalcon_array_update_string(&route_paths, SL("namespace"), namespace_name, PH_COPY | PH_SEPARATE);
					}
				} else {
					PHALCON_CPY_WRT(real_class_name, controller_name);
				}
	
				/** 
				 * Always pass the controller to lowercase
				 */
				PHALCON_INIT_VAR(lower_name);
				phalcon_uncamelize(lower_name, real_class_name);
	
				/** 
				 * Update the controller path
				 */
				phalcon_array_update_string(&route_paths, SL("controller"), lower_name, PH_COPY | PH_SEPARATE);
			}
	
			/** 
			 * Process action name
			 */
			if (Z_TYPE_P(action_name) != IS_NULL) {
				phalcon_array_update_string(&route_paths, SL("action"), action_name, PH_COPY | PH_SEPARATE);
			}
		} else {
			PHALCON_CPY_WRT(route_paths, paths);
		}
	} else {
		PHALCON_INIT_NVAR(route_paths);
		array_init(route_paths);
	}
	
	if (Z_TYPE_P(route_paths) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "The route contains invalid paths");
		return;
	}
	
	/** 
	 * If the route starts with '#' we assume that it is a regular expression
	 */
	if (!phalcon_start_with_str(pattern, SL("#"))) {
		if (phalcon_memnstr_str(pattern, SL("{"))) {
			/** 
			 * The route has named parameters so we need to extract them
			 */
			PHALCON_INIT_VAR(pcre_pattern);
			phalcon_extract_named_params(pcre_pattern, pattern, route_paths);
		} else {
			PHALCON_CPY_WRT(pcre_pattern, pattern);
		}
	
		/** 
		 * Transform the route's pattern to a regular expression
		 */
		PHALCON_CALL_METHOD(&compiled_pattern, this_ptr, "compilepattern", pcre_pattern);
	} else {
		PHALCON_CPY_WRT(compiled_pattern, pattern);
	}
	
	/** 
	 * Update the original pattern
	 */
	phalcon_update_property_this(this_ptr, SL("_pattern"), pattern TSRMLS_CC);
	
	/** 
	 * Update the compiled pattern
	 */
	phalcon_update_property_this(this_ptr, SL("_compiledPattern"), compiled_pattern TSRMLS_CC);
	
	/** 
	 * Update the route's paths
	 */
	phalcon_update_property_this(this_ptr, SL("_paths"), route_paths TSRMLS_CC);
	
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
 *<code>
 * $router->add('/about', array(
 *     'controller' => 'about'
 * ))->setName('about');
 *</code>
 *
 * @param string $name
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, setName){

	zval *name;

	phalcon_fetch_params(0, 1, 0, &name);
	
	phalcon_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Sets a callback that is called if the route is matched.
 * The developer can implement any arbitrary conditions here
 * If the callback returns false the route is treaded as not matched
 *
 * @param callback $callback
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, beforeMatch){

	zval *callback;

	phalcon_fetch_params(0, 1, 0, &callback);
	
	phalcon_update_property_this(this_ptr, SL("_beforeMatch"), callback TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the 'before match' callback if any
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getBeforeMatch){


	RETURN_MEMBER(this_ptr, "_beforeMatch");
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

	zval *paths, *position = NULL, *path = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(paths);
	phalcon_read_property_this(&paths, this_ptr, SL("_paths"), PH_NOISY TSRMLS_CC);
	
	phalcon_is_iterable(paths, &ah0, &hp0, 0, 0);

	array_init_size(return_value, zend_hash_num_elements(ah0));

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(path, ah0, hp0);
		PHALCON_GET_HVALUE(position);
	
		phalcon_array_update_zval(&return_value, position, path, PH_COPY);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_MM();
}

/**
 * Sets a set of HTTP methods that constraint the matching of the route (alias of via)
 *
 *<code>
 * $route->setHttpMethods('GET');
 * $route->setHttpMethods(array('GET', 'POST'));
 *</code>
 *
 * @param string|array $httpMethods
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, setHttpMethods){

	zval *http_methods;

	phalcon_fetch_params(0, 1, 0, &http_methods);
	
	phalcon_update_property_this(this_ptr, SL("_methods"), http_methods TSRMLS_CC);
	RETURN_THISW();
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
 * Sets a hostname restriction to the route
 *
 *<code>
 * $route->setHostname('localhost');
 *</code>
 *
 * @param string|array $httpMethods
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, setHostname){

	zval *hostname;

	phalcon_fetch_params(0, 1, 0, &hostname);
	
	phalcon_update_property_this(this_ptr, SL("_hostname"), hostname TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the hostname restriction if any
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getHostname){


	RETURN_MEMBER(this_ptr, "_hostname");
}

/**
 * Sets the group associated with the route
 *
 * @param Phalcon\Mvc\Router\Group $group
 * @return Phalcon\Mvc\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, setGroup) {

	zval *group;

	phalcon_fetch_params(0, 1, 0, &group);
	PHALCON_VERIFY_CLASS_EX(group, phalcon_mvc_router_group_ce, phalcon_mvc_router_exception_ce, 0);

	phalcon_update_property_this(getThis(), SL("_group"), group TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the group associated with the route
 *
 * @return Phalcon\Mvc\Router\Group|null
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getGroup) {

	RETURN_MEMBER(this_ptr, "_group");
}

/**
 * Adds a converter to perform an additional transformation for certain parameter
 *
 * @param string $name
 * @param callable $converter
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, convert){

	zval *name, *converter;

	phalcon_fetch_params(0, 2, 0, &name, &converter);
	
	phalcon_update_property_array(this_ptr, SL("_converters"), name, converter TSRMLS_CC);
	RETURN_THISW();
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

	zend_update_static_property_long(phalcon_mvc_router_route_ce, SL("_uniqueId"), 0 TSRMLS_CC);
}
