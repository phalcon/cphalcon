
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Router\Group
 *
 * Helper class to create a group of routes with common attributes
 *
 *```php
 * $router = new \Phalcon\Mvc\Router();
 *
 * //Create a group with a common module and controller
 * $blog = new Group(
 *     [
 *         "module"     => "blog",
 *         "controller" => "index",
 *     ]
 * );
 *
 * //All the routes start with /blog
 * $blog->setPrefix("/blog");
 *
 * //Add a route to the group
 * $blog->add(
 *     "/save",
 *     [
 *         "action" => "save",
 *     ]
 * );
 *
 * //Add another route to the group
 * $blog->add(
 *     "/edit/{id}",
 *     [
 *         "action" => "edit",
 *     ]
 * );
 *
 * //This route maps to a controller different than the default
 * $blog->add(
 *     "/blog",
 *     [
 *         "controller" => "about",
 *         "action"     => "index",
 *     ]
 * );
 *
 * //Add the group to the router
 * $router->mount($blog);
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Group) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Router, Group, phalcon, mvc_router_group, phalcon_mvc_router_group_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("beforeMatch"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("hostname"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("paths"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("prefix"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("routes"), ZEND_ACC_PROTECTED);

	phalcon_mvc_router_group_ce->create_object = zephir_init_properties_Phalcon_Mvc_Router_Group;

	zend_class_implements(phalcon_mvc_router_group_ce, 1, phalcon_mvc_router_groupinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Router\Group constructor
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, __construct) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *paths = NULL, paths_sub, __$null;
	zval *this_ptr = getThis();

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
		zephir_update_property_zval(this_ptr, SL("paths"), paths);
	}
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("initialize")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0, paths);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a route to the router on any HTTP method
 *
 *```php
 * $router->add("/about", "About::index");
 *```
 *
 * @param string|array paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, add) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *httpMethods = NULL, httpMethods_sub, __$null;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&httpMethods_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &httpMethods);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &pattern, paths, httpMethods);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is CONNECT
 *
 * @param string|array paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addConnect) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
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
	ZVAL_STRING(&_0, "CONNECT");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string|array paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addDelete) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string|array paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addGet) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string|array paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addHead) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string|array paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addOptions) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 *
 * @param string|array paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPatch) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string|array paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPost) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PURGE
 *
 * @param string|array paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPurge) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
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
	ZVAL_STRING(&_0, "PURGE");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string|array paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPut) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is TRACE
 *
 * @param string|array paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addTrace) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
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
	ZVAL_STRING(&_0, "TRACE");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &pattern, paths, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets a callback that is called if the route is matched.
 * The developer can implement any arbitrary conditions here
 * If the callback returns false the route is treated as not matched
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, beforeMatch) {

	zval *beforeMatch, beforeMatch_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&beforeMatch_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &beforeMatch);



	zephir_update_property_zval(this_ptr, SL("beforeMatch"), beforeMatch);
	RETURN_THISW();

}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, clear) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("routes"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the 'before match' callback if any
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getBeforeMatch) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "beforeMatch");

}

/**
 * Returns the hostname restriction
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getHostname) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "hostname");

}

/**
 * Returns the common paths defined for this group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getPaths) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "paths");

}

/**
 * Returns the common prefix for all the routes
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getPrefix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "prefix");

}

/**
 * Returns the routes added to the group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getRoutes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "routes");

}

/**
 * Set a hostname restriction for all the routes in the group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, setHostname) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *hostname_param = NULL;
	zval hostname;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hostname);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &hostname_param);

	zephir_get_strval(&hostname, hostname_param);


	zephir_update_property_zval(this_ptr, SL("hostname"), &hostname);
	RETURN_THIS();

}

/**
 * Set common paths for all the routes in the group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, setPaths) {

	zval *paths, paths_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&paths_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &paths);



	zephir_update_property_zval(this_ptr, SL("paths"), paths);
	RETURN_THISW();

}

/**
 * Set a common uri prefix for all the routes in this group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, setPrefix) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *prefix_param = NULL;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	zephir_get_strval(&prefix, prefix_param);


	zephir_update_property_zval(this_ptr, SL("prefix"), &prefix);
	RETURN_THIS();

}

/**
 * Adds a route applying the common attributes
 *
 * @param string|array paths = [
 *     'module => '',
 *     'controller' => '',
 *     'action' => '',
 *     'namespace' => ''
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addRoute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *httpMethods = NULL, httpMethods_sub, __$null, mergedPaths, route, defaultPaths, processedPaths, _1, _2;
	zval pattern;
	zval *this_ptr = getThis();

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

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
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
	zephir_read_property(&defaultPaths, this_ptr, SL("paths"), PH_NOISY_CC);
	if (Z_TYPE_P(&defaultPaths) == IS_ARRAY) {
		if (Z_TYPE_P(paths) == IS_STRING) {
			ZEPHIR_CALL_CE_STATIC(&processedPaths, phalcon_mvc_router_route_ce, "getroutepaths", &_0, 0, paths);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&processedPaths, paths);
		}
		if (Z_TYPE_P(&processedPaths) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&mergedPaths);
			zephir_fast_array_merge(&mergedPaths, &defaultPaths, &processedPaths);
		} else {
			ZEPHIR_CPY_WRT(&mergedPaths, &defaultPaths);
		}
	} else {
		ZEPHIR_CPY_WRT(&mergedPaths, paths);
	}
	ZEPHIR_INIT_VAR(&route);
	object_init_ex(&route, phalcon_mvc_router_route_ce);
	zephir_read_property(&_1, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_1, &pattern);
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 111, &_2, &mergedPaths, httpMethods);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("routes"), &route);
	ZEPHIR_CALL_METHOD(NULL, &route, "setgroup", NULL, 489, this_ptr);
	zephir_check_call_status();
	RETURN_CCTOR(&route);

}

zend_object *zephir_init_properties_Phalcon_Mvc_Router_Group(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("routes"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

