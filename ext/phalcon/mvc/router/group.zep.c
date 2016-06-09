
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

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *paths = NULL, paths_sub, __$null;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &paths);

	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	_0 = Z_TYPE_P(paths) == IS_ARRAY;
	if (!(_0)) {
		_0 = Z_TYPE_P(paths) == IS_STRING;
	}
	if (_0) {
		zephir_update_property_zval(this_ptr, SL("_paths"), paths);
	}
	if ((zephir_method_exists_ex(this_ptr, SL("initialize") TSRMLS_CC) == SUCCESS)) {
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
	zval hostname;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&hostname);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &hostname_param);

	zephir_get_strval(&hostname, hostname_param);


	zephir_update_property_zval(this_ptr, SL("_hostname"), &hostname);
	RETURN_THIS();

}

/**
 * Returns the hostname restriction
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getHostname) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_hostname");

}

/**
 * Set a common uri prefix for all the routes in this group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, setPrefix) {

	zval *prefix_param = NULL;
	zval prefix;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&prefix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	zephir_get_strval(&prefix, prefix_param);


	zephir_update_property_zval(this_ptr, SL("_prefix"), &prefix);
	RETURN_THIS();

}

/**
 * Returns the common prefix for all the routes
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getPrefix) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_prefix");

}

/**
 * Sets a callback that is called if the route is matched.
 * The developer can implement any arbitrary conditions here
 * If the callback returns false the route is treated as not matched
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, beforeMatch) {

	zval *beforeMatch, beforeMatch_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&beforeMatch_sub);

	zephir_fetch_params(0, 1, 0, &beforeMatch);



	zephir_update_property_zval(this_ptr, SL("_beforeMatch"), beforeMatch);
	RETURN_THISW();

}

/**
 * Returns the 'before match' callback if any
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getBeforeMatch) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_beforeMatch");

}

/**
 * Set common paths for all the routes in the group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, setPaths) {

	zval *paths, paths_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&paths_sub);

	zephir_fetch_params(0, 1, 0, &paths);



	zephir_update_property_zval(this_ptr, SL("_paths"), paths);
	RETURN_THISW();

}

/**
 * Returns the common paths defined for this group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getPaths) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_paths");

}

/**
 * Returns the routes added to the group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getRoutes) {

	ZEPHIR_INIT_THIS();


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
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *httpMethods = NULL, httpMethods_sub, __$null;
	zval pattern;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&httpMethods_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &httpMethods);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!httpMethods) {
		httpMethods = &httpMethods_sub;
		httpMethods = &__$null;
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, &pattern, paths, httpMethods);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string pattern
 * @param string/array paths
 * @return \Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GET");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string pattern
 * @param string/array paths
 * @return \Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPost) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "POST");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string pattern
 * @param string/array paths
 * @return \Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPut) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PUT");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 *
 * @param string pattern
 * @param string/array paths
 * @return \Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPatch) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PATCH");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string pattern
 * @param string/array paths
 * @return \Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addDelete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DELETE");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string pattern
 * @param string/array paths
 * @return \Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addOptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "OPTIONS");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string pattern
 * @param string/array paths
 * @return \Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addHead) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HEAD");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, clear) {

	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("_routes"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a route applying the common attributes
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, _addRoute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *httpMethods = NULL, httpMethods_sub, __$null, mergedPaths, route, defaultPaths, processedPaths, _1, _2;
	zval pattern;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&httpMethods_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&mergedPaths);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&defaultPaths);
	ZVAL_UNDEF(&processedPaths);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &httpMethods);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!httpMethods) {
		httpMethods = &httpMethods_sub;
		httpMethods = &__$null;
	}


	ZEPHIR_OBS_VAR(&defaultPaths);
	zephir_read_property(&defaultPaths, this_ptr, SL("_paths"), PH_NOISY_CC);
	if (Z_TYPE_P(&defaultPaths) == IS_ARRAY) {
		if (Z_TYPE_P(paths) == IS_STRING) {
			ZEPHIR_CALL_CE_STATIC(&processedPaths, phalcon_mvc_router_route_ce, "getroutepaths", &_0, 81, paths);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&processedPaths, paths);
		}
		if (Z_TYPE_P(&processedPaths) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&mergedPaths);
			zephir_fast_array_merge(&mergedPaths, &defaultPaths, &processedPaths TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(&mergedPaths, &defaultPaths);
		}
	} else {
		ZEPHIR_CPY_WRT(&mergedPaths, paths);
	}
	ZEPHIR_INIT_VAR(&route);
	object_init_ex(&route, phalcon_mvc_router_route_ce);
	zephir_read_property(&_1, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_1, &pattern);
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 80, &_2, &mergedPaths, httpMethods);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_routes"), &route TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &route, "setgroup", NULL, 381, this_ptr);
	zephir_check_call_status();
	RETURN_CCTOR(route);

}

