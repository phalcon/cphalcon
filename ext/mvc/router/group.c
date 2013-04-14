
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Mvc\Router\Group
 *
 * Helper class to create a group of routes with common attributes
 *
 *<code>
 * $router = new Phalcon\Mvc\Router();
 *
 * //Create a group with a common module and controller
 * $blog = new Phalcon\Mvc\Router\Group(array(
 * 	'module' => 'blog',
 * 	'controller' => 'index'
 * ));
 *
 * //All the routes start with /blog
 * $blog->setPrefix('/blog');
 *
 * //Add a route to the group
 * $blog->add('/save', array(
 * 	'action' => 'save'
 * ));
 *
 * //Add another route to the group
 * $blog->add('/edit/{id}', array(
 * 	'action' => 'edit'
 * ));
 *
 * //This route maps to a controller different than the default
 * $blog->add('/blog', array(
 * 	'controller' => 'about',
 * 	'action' => 'index'
 * ));
 *
 * //Add the group to the router
 * $router->mount($blog);
 *</code>
 *
 */


/**
 * Phalcon\Mvc\Router\Group initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Router_Group){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Router, Group, mvc_router_group, phalcon_mvc_router_group_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_paths"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_routes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Router\Group constructor
 *
 * @param array $paths
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, __construct){

	zval *paths = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	if (Z_TYPE_P(paths) != IS_ARRAY) { 
		if (Z_TYPE_P(paths) != IS_STRING) {
			RETURN_MM_NULL();
		}
	}
	phalcon_update_property_zval(this_ptr, SL("_paths"), paths TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Set a common uri prefix for all the routes in this group
 *
 * @param string $prefix
 * @return Phalcon\Mvc\Router\Group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, setPrefix){

	zval *prefix;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &prefix) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the common prefix for all the routes
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getPrefix){


	RETURN_MEMBER(this_ptr, "_prefix");
}

/**
 * Set common paths for all the routes in the group
 *
 * @param array $paths
 * @return Phalcon\Mvc\Router\Group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, setPaths){

	zval *paths;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &paths) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_paths"), paths TSRMLS_CC);
	
}

/**
 * Returns the common paths defined for this group
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getPaths){


	RETURN_MEMBER(this_ptr, "_paths");
}

/**
 * Returns the routes added to the group
 *
 * @return Phalcon\Mvc\Router\Route[]
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getRoutes){


	RETURN_MEMBER(this_ptr, "_routes");
}

/**
 * Adds a route applying the common attributes
 *
 * @param string $patten
 * @param array $paths
 * @param array $httpMethods
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, _addRoute){

	zval *pattern, *paths = NULL, *http_methods = NULL, *prefix, *prefix_pattern;
	zval *default_paths, *merged_paths = NULL, *route;

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
	
	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	/** 
	 * Add the prefix to the pattern
	 */
	PHALCON_INIT_VAR(prefix_pattern);
	PHALCON_CONCAT_VV(prefix_pattern, prefix, pattern);
	
	PHALCON_OBS_VAR(default_paths);
	phalcon_read_property_this(&default_paths, this_ptr, SL("_paths"), PH_NOISY_CC);
	
	/** 
	 * Check if the paths need to be merged with current paths
	 */
	if (Z_TYPE_P(default_paths) == IS_ARRAY) { 
		if (Z_TYPE_P(paths) == IS_ARRAY) { 
			/** 
			 * Merge the paths with the default paths
			 */
			PHALCON_INIT_VAR(merged_paths);
			PHALCON_CALL_FUNC_PARAMS_2(merged_paths, "array_merge", default_paths, paths);
		} else {
			PHALCON_CPY_WRT(merged_paths, default_paths);
		}
	} else {
		PHALCON_CPY_WRT(merged_paths, paths);
	}
	
	/** 
	 * Every route is internally stored as a Phalcon\Mvc\Router\Route
	 */
	PHALCON_INIT_VAR(route);
	object_init_ex(route, phalcon_mvc_router_route_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(route, "__construct", prefix_pattern, merged_paths, http_methods);
	
	phalcon_update_property_array_append(this_ptr, SL("_routes"), route TSRMLS_CC);
	
	RETURN_CTOR(route);
}

/**
 * Adds a route to the router on any HTTP method
 *
 *<code>
 * $router->add('/about', 'About::index');
 *</code>
 *
 * @param string $pattern
 * @param string/array $paths
 * @param string $httpMethods
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, add){

	zval *pattern, *paths = NULL, *http_methods = NULL, *route;

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
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addroute", pattern, paths, http_methods);
	RETURN_CCTOR(route);
}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addGet){

	zval *pattern, *paths = NULL, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "GET", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addroute", pattern, paths, method);
	RETURN_CCTOR(route);
}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPost){

	zval *pattern, *paths = NULL, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "POST", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addroute", pattern, paths, method);
	RETURN_CCTOR(route);
}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPut){

	zval *pattern, *paths = NULL, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "PUT", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addroute", pattern, paths, method);
	RETURN_CCTOR(route);
}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPatch){

	zval *pattern, *paths = NULL, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "PATCH", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addroute", pattern, paths, method);
	RETURN_CCTOR(route);
}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addDelete){

	zval *pattern, *paths = NULL, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "DELETE", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addroute", pattern, paths, method);
	RETURN_CCTOR(route);
}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addOptions){

	zval *pattern, *paths = NULL, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "OPTIONS", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addroute", pattern, paths, method);
	RETURN_CCTOR(route);
}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addHead){

	zval *pattern, *paths = NULL, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &pattern, &paths) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!paths) {
		PHALCON_INIT_VAR(paths);
	}
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "HEAD", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addroute", pattern, paths, method);
	RETURN_CCTOR(route);
}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, clear){

	zval *empty_routes;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(empty_routes);
	array_init(empty_routes);
	phalcon_update_property_zval(this_ptr, SL("_routes"), empty_routes TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

