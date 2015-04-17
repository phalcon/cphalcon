
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

#include "mvc/router/group.h"
#include "mvc/router/route.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"

#include "interned-strings.h"

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
zend_class_entry *phalcon_mvc_router_group_ce;

PHP_METHOD(Phalcon_Mvc_Router_Group, __construct);
PHP_METHOD(Phalcon_Mvc_Router_Group, setHostname);
PHP_METHOD(Phalcon_Mvc_Router_Group, getHostname);
PHP_METHOD(Phalcon_Mvc_Router_Group, setPrefix);
PHP_METHOD(Phalcon_Mvc_Router_Group, getPrefix);
PHP_METHOD(Phalcon_Mvc_Router_Group, beforeMatch);
PHP_METHOD(Phalcon_Mvc_Router_Group, getBeforeMatch);
PHP_METHOD(Phalcon_Mvc_Router_Group, setPaths);
PHP_METHOD(Phalcon_Mvc_Router_Group, getPaths);
PHP_METHOD(Phalcon_Mvc_Router_Group, getRoutes);
PHP_METHOD(Phalcon_Mvc_Router_Group, _addRoute);
PHP_METHOD(Phalcon_Mvc_Router_Group, add);
PHP_METHOD(Phalcon_Mvc_Router_Group, addGet);
PHP_METHOD(Phalcon_Mvc_Router_Group, addPost);
PHP_METHOD(Phalcon_Mvc_Router_Group, addPut);
PHP_METHOD(Phalcon_Mvc_Router_Group, addPatch);
PHP_METHOD(Phalcon_Mvc_Router_Group, addDelete);
PHP_METHOD(Phalcon_Mvc_Router_Group, addOptions);
PHP_METHOD(Phalcon_Mvc_Router_Group, addHead);
PHP_METHOD(Phalcon_Mvc_Router_Group, clear);
PHP_METHOD(Phalcon_Mvc_Router_Group, convert);
PHP_METHOD(Phalcon_Mvc_Router_Group, getConverters);
PHP_METHOD(Phalcon_Mvc_Router_Group, setName);
PHP_METHOD(Phalcon_Mvc_Router_Group, getName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_sethostname, 0, 0, 1)
	ZEND_ARG_INFO(0, hostname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_beforematch, 0, 0, 1)
	ZEND_ARG_INFO(0, beforeMatch)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_setpaths, 0, 0, 1)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addget, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addpost, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addput, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addpatch, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_adddelete, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addhead, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_convert, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, converter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_router_group_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Router_Group, __construct, arginfo_phalcon_mvc_router_group___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Router_Group, setHostname, arginfo_phalcon_mvc_router_group_sethostname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getHostname, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, setPrefix, arginfo_phalcon_mvc_router_group_setprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, beforeMatch, arginfo_phalcon_mvc_router_group_beforematch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getBeforeMatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, setPaths, arginfo_phalcon_mvc_router_group_setpaths, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getPaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getRoutes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, _addRoute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Router_Group, add, arginfo_phalcon_mvc_router_group_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addGet, arginfo_phalcon_mvc_router_group_addget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addPost, arginfo_phalcon_mvc_router_group_addpost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addPut, arginfo_phalcon_mvc_router_group_addput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addPatch, arginfo_phalcon_mvc_router_group_addpatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addDelete, arginfo_phalcon_mvc_router_group_adddelete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addOptions, arginfo_phalcon_mvc_router_group_addoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addHead, arginfo_phalcon_mvc_router_group_addhead, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, convert, arginfo_phalcon_mvc_router_group_convert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getConverters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, setName, arginfo_phalcon_mvc_router_group_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Router\Group initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Router_Group){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Router, Group, mvc_router_group, phalcon_mvc_router_group_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_hostname"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_paths"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_routes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_beforeMatch"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_converters"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_group_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Router\Group constructor
 *
 * @param array $paths
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, __construct){

	zval *paths = NULL;

	phalcon_fetch_params(0, 0, 1, &paths);

	if (!paths) {
		paths = PHALCON_GLOBAL(z_null);
	}

	if (Z_TYPE_P(paths) == IS_ARRAY || Z_TYPE_P(paths) == IS_STRING) {
		phalcon_update_property_this(this_ptr, SL("_paths"), paths TSRMLS_CC);
	}

	if (phalcon_method_exists_ex(this_ptr, SS("initialize") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHODW(NULL, this_ptr, "initialize", paths);
	}
}

/**
 * Set a hostname restriction for all the routes in the group
 *
 * @param string $hostname
 * @return Phalcon\Mvc\Router\Group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, setHostname){

	zval *hostname;

	phalcon_fetch_params(0, 1, 0, &hostname);

	phalcon_update_property_this(this_ptr, SL("_hostname"), hostname TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the hostname restriction
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getHostname){


	RETURN_MEMBER(this_ptr, "_hostname");
}

/**
 * Set a common uri prefix for all the routes in this group
 *
 * @param string $prefix
 * @return Phalcon\Mvc\Router\Group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, setPrefix){

	zval *prefix;

	phalcon_fetch_params(0, 1, 0, &prefix);

	phalcon_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
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
 * Set a before-match condition for the whole group
 *
 * @param string $prefix
 * @return Phalcon\Mvc\Router\Group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, beforeMatch){

	zval *before_match;

	phalcon_fetch_params(0, 1, 0, &before_match);

	phalcon_update_property_this(this_ptr, SL("_beforeMatch"), before_match TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the before-match condition if any
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getBeforeMatch){


	RETURN_MEMBER(this_ptr, "_beforeMatch");
}

/**
 * Set common paths for all the routes in the group
 *
 * @param array $paths
 * @return Phalcon\Mvc\Router\Group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, setPaths){

	zval *paths;

	phalcon_fetch_params(0, 1, 0, &paths);

	phalcon_update_property_this(this_ptr, SL("_paths"), paths TSRMLS_CC);

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
 * @param string $pattern
 * @param array $paths
 * @param array $httpMethods
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, _addRoute){

	zval **pattern, **paths = NULL, **http_methods = NULL, *prefix, *prefix_pattern;
	zval *default_paths, *merged_paths = NULL;

	phalcon_fetch_params_ex(1, 2, &pattern, &paths, &http_methods);
	PHALCON_ENSURE_IS_STRING(pattern);

	PHALCON_MM_GROW();

	if (!paths) {
		paths = &PHALCON_GLOBAL(z_null);
	}

	if (!http_methods) {
		http_methods = &PHALCON_GLOBAL(z_null);
	}

	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(prefix) != IS_STRING) {
		convert_to_string_ex(&prefix);
	}

	/**
	 * Add the prefix to the pattern
	 */
	PHALCON_INIT_VAR(prefix_pattern);
	{
		const char *s_pattern = Z_STRVAL_PP(pattern); /* NUL-terminated */
		const char *s_prefix  = Z_STRVAL_P(prefix);   /* NUL-terminated */
		int pattern_len       = Z_STRLEN_PP(pattern);
		int prefix_len        = Z_STRLEN_P(prefix);
		if (prefix_len && *s_pattern == '/' && s_prefix[prefix_len-1] == '/') {
			char *new_pattern = safe_emalloc(prefix_len - 1 /* slash */ + 1 /* \0 */, 1, pattern_len);
			memcpy(new_pattern, s_prefix, prefix_len - 1);
			memcpy(new_pattern + prefix_len - 1, s_pattern, pattern_len + 1);
			ZVAL_STRINGL(prefix_pattern, new_pattern, prefix_len + pattern_len - 1, 0);
		}
		else {
			PHALCON_CONCAT_VV(prefix_pattern, prefix, *pattern);
		}
	}

	default_paths = phalcon_fetch_nproperty_this(this_ptr, SL("_paths"), PH_NOISY TSRMLS_CC);

	/**
	 * Check if the paths need to be merged with current paths
	 */
	if (Z_TYPE_P(default_paths) == IS_ARRAY && Z_TYPE_PP(paths) == IS_ARRAY) {
		/**
		 * Merge the paths with the default paths
		 */
		PHALCON_INIT_VAR(merged_paths);
		phalcon_fast_array_merge(merged_paths, &default_paths, paths TSRMLS_CC);
	} else {
		merged_paths = *paths;
	}

	/**
	 * Every route is internally stored as a Phalcon\Mvc\Router\Route
	 */
	object_init_ex(return_value, phalcon_mvc_router_route_ce);
	PHALCON_CALL_METHOD(NULL, return_value, "__construct", prefix_pattern, merged_paths, *http_methods);
	PHALCON_CALL_METHOD(NULL, return_value, "setgroup", this_ptr);

	phalcon_update_property_array_append(this_ptr, SL("_routes"), return_value TSRMLS_CC);

	PHALCON_MM_RESTORE();
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

	zval *pattern, *paths = NULL, *http_methods = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &pattern, &paths, &http_methods);

	if (!paths) {
		paths = PHALCON_GLOBAL(z_null);
	}

	if (!http_methods) {
		http_methods = PHALCON_GLOBAL(z_null);
	}

	PHALCON_RETURN_CALL_METHOD(this_ptr, "_addroute", pattern, paths, http_methods);
	RETURN_MM();
}

static void phalcon_mvc_router_group_add_helper(INTERNAL_FUNCTION_PARAMETERS, const char *method)
{
	zval *pattern, *paths = NULL, *http_method;

	phalcon_fetch_params(0, 1, 1, &pattern, &paths);

	if (!paths) {
		paths = PHALCON_GLOBAL(z_null);
	}

	PHALCON_ALLOC_GHOST_ZVAL(http_method);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(http_method, method);
	PHALCON_RETURN_CALL_METHODW(getThis(), "_addroute", pattern, paths, http_method);
}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addGet){

	phalcon_mvc_router_group_add_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, phalcon_interned_GET);
}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPost){

	phalcon_mvc_router_group_add_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, phalcon_interned_POST);
}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPut){

	phalcon_mvc_router_group_add_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, phalcon_interned_PUT);
}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addPatch){

	phalcon_mvc_router_group_add_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, phalcon_interned_PATCH);
}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addDelete){

	phalcon_mvc_router_group_add_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, phalcon_interned_DELETE);
}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addOptions){

	phalcon_mvc_router_group_add_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, phalcon_interned_OPTIONS);
}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, addHead){

	phalcon_mvc_router_group_add_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, phalcon_interned_HEAD);
}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, clear){

	zval *empty_routes;

	MAKE_STD_ZVAL(empty_routes);
	array_init(empty_routes);
	phalcon_update_property_this(this_ptr, SL("_routes"), empty_routes TSRMLS_CC);
	zval_ptr_dtor(&empty_routes);
}

/**
 * Adds a converter to perform an additional transformation for certain parameter
 *
 * @param string $name
 * @param callable $converter
 * @return Phalcon\Mvc\Router\Group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, convert){

	zval **name, **converter;

	phalcon_fetch_params_ex(2, 0, &name, &converter);

	phalcon_update_property_array(this_ptr, SL("_converters"), *name, *converter TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the router converter
 *
 * @return array|null
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getConverters) {

	RETURN_MEMBER(this_ptr, "_converters");
}

/**
 * Set the name of the group
 *
 * @param string $hostname
 * @return Phalcon\Mvc\Router\Group
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, setName){

	zval **name;

	phalcon_fetch_params_ex(1, 0, &name);

	phalcon_update_property_this(this_ptr, SL("_name"), *name TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the name of this group
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router_Group, getName){


	RETURN_MEMBER(this_ptr, "_name");
}
