
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 * Phalcon\Mvc\Router\Group
 *
 * Helper class to create a group of routes with common attributes
 *
 *<code>
 * $router = new \Phalcon\Mvc\Router();
 *
 * //Create a group with a common module and controller
 * $blog = new Group(array(
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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Group) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Router, Group, phalcon, mvc_router_group, phalcon_mvc_router_group_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_hostname"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_paths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_routes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_beforeMatch"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_router_group_ce TSRMLS_CC, 1, phalcon_mvc_router_groupinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Router\Group constructor
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *paths = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &paths);

	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(paths) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("_paths"), paths TSRMLS_CC);
	} else {
		if (Z_TYPE_P(paths) == IS_STRING) {
			zephir_update_property_this(this_ptr, SL("_paths"), paths TSRMLS_CC);
		}
	}
	if ((zephir_method_exists_ex(this_ptr, SS("initialize") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0, paths);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Set a hostname restriction for all the routes in the group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, setHostname) {

	zval *hostname_param = NULL;
	zval *hostname = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &hostname_param);

	zephir_get_strval(hostname, hostname_param);


	zephir_update_property_this(this_ptr, SL("_hostname"), hostname TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the hostname restriction
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getHostname) {


	RETURN_MEMBER(this_ptr, "_hostname");

}

/**
 * Set a common uri prefix for all the routes in this group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, setPrefix) {

	zval *prefix_param = NULL;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	zephir_get_strval(prefix, prefix_param);


	zephir_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the common prefix for all the routes
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getPrefix) {


	RETURN_MEMBER(this_ptr, "_prefix");

}

/**
 * Sets a callback that is called if the route is matched.
 * The developer can implement any arbitrary conditions here
 * If the callback returns false the route is treated as not matched
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, beforeMatch) {

	zval *beforeMatch;

	zephir_fetch_params(0, 1, 0, &beforeMatch);



	zephir_update_property_this(this_ptr, SL("_beforeMatch"), beforeMatch TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the 'before match' callback if any
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getBeforeMatch) {


	RETURN_MEMBER(this_ptr, "_beforeMatch");

}

/**
 * Set common paths for all the routes in the group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, setPaths) {

	zval *paths;

	zephir_fetch_params(0, 1, 0, &paths);



	zephir_update_property_this(this_ptr, SL("_paths"), paths TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the common paths defined for this group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getPaths) {


	RETURN_MEMBER(this_ptr, "_paths");

}

/**
 * Returns the routes added to the group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getRoutes) {


	RETURN_MEMBER(this_ptr, "_routes");

}

/**
 * Adds a route to the router on any HTTP method
 *
 *<code>
 * router->add('/about', 'About::index');
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *httpMethods = NULL;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &httpMethods);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!httpMethods) {
		httpMethods = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, pattern, paths, httpMethods);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "GET", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, pattern, paths, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPost) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "POST", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, pattern, paths, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPut) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "PUT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, pattern, paths, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPatch) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "PATCH", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, pattern, paths, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addDelete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "DELETE", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, pattern, paths, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addOptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "OPTIONS", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, pattern, paths, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addHead) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HEAD", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, pattern, paths, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, clear) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_routes"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a route applying the common attributes
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, _addRoute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *httpMethods = NULL, *mergedPaths = NULL, *route, *defaultPaths, *_0, *_1;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &httpMethods);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!httpMethods) {
		httpMethods = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(defaultPaths);
	zephir_read_property_this(&defaultPaths, this_ptr, SL("_paths"), PH_NOISY_CC);
	if (Z_TYPE_P(defaultPaths) == IS_ARRAY) {
		if (Z_TYPE_P(paths) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedPaths);
			zephir_fast_array_merge(mergedPaths, &(defaultPaths), &(paths) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedPaths, defaultPaths);
		}
	} else {
		ZEPHIR_CPY_WRT(mergedPaths, paths);
	}
	ZEPHIR_INIT_VAR(route);
	object_init_ex(route, phalcon_mvc_router_route_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, pattern);
	ZEPHIR_CALL_METHOD(NULL, route, "__construct", NULL, 354, _1, mergedPaths, httpMethods);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_routes"), route TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, route, "setgroup", NULL, 357, this_ptr);
	zephir_check_call_status();
	RETURN_CCTOR(route);

}

