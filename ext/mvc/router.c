
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

#include "mvc/router.h"
#include "mvc/routerinterface.h"
#include "mvc/router/exception.h"
#include "mvc/router/group.h"
#include "mvc/router/route.h"
#include "diinterface.h"
#include "di/injectionawareinterface.h"
#include "http/requestinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/hash.h"

#include "interned-strings.h"

/**
 * Phalcon\Mvc\Router
 *
 * <p>Phalcon\Mvc\Router is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request</p>
 *
 *<code>
 *
 *	$router = new Phalcon\Mvc\Router();
 *
 *  $router->add(
 *		"/documentation/{chapter}/{name}.{type:[a-z]+}",
 *		array(
 *			"controller" => "documentation",
 *			"action"     => "show"
 *		)
 *	);
 *
 *	$router->handle();
 *
 *	echo $router->getControllerName();
 *</code>
 *
 */
zend_class_entry *phalcon_mvc_router_ce;

PHP_METHOD(Phalcon_Mvc_Router, __construct);
PHP_METHOD(Phalcon_Mvc_Router, setDI);
PHP_METHOD(Phalcon_Mvc_Router, getDI);
PHP_METHOD(Phalcon_Mvc_Router, getRewriteUri);
PHP_METHOD(Phalcon_Mvc_Router, setUriSource);
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace);
PHP_METHOD(Phalcon_Mvc_Router, getDefaultNamespace);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule);
PHP_METHOD(Phalcon_Mvc_Router, getDefaultModule);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultController);
PHP_METHOD(Phalcon_Mvc_Router, getDefaultController);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction);
PHP_METHOD(Phalcon_Mvc_Router, getDefaultAction);
PHP_METHOD(Phalcon_Mvc_Router, setDefaults);
PHP_METHOD(Phalcon_Mvc_Router, getDefaults);
PHP_METHOD(Phalcon_Mvc_Router, handle);
PHP_METHOD(Phalcon_Mvc_Router, add);
PHP_METHOD(Phalcon_Mvc_Router, addGet);
PHP_METHOD(Phalcon_Mvc_Router, addPost);
PHP_METHOD(Phalcon_Mvc_Router, addPut);
PHP_METHOD(Phalcon_Mvc_Router, addPatch);
PHP_METHOD(Phalcon_Mvc_Router, addDelete);
PHP_METHOD(Phalcon_Mvc_Router, addOptions);
PHP_METHOD(Phalcon_Mvc_Router, addHead);
PHP_METHOD(Phalcon_Mvc_Router, mount);
PHP_METHOD(Phalcon_Mvc_Router, notFound);
PHP_METHOD(Phalcon_Mvc_Router, clear);
PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName);
PHP_METHOD(Phalcon_Mvc_Router, getModuleName);
PHP_METHOD(Phalcon_Mvc_Router, getControllerName);
PHP_METHOD(Phalcon_Mvc_Router, getActionName);
PHP_METHOD(Phalcon_Mvc_Router, getParams);
PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute);
PHP_METHOD(Phalcon_Mvc_Router, getMatches);
PHP_METHOD(Phalcon_Mvc_Router, wasMatched);
PHP_METHOD(Phalcon_Mvc_Router, getRoutes);
PHP_METHOD(Phalcon_Mvc_Router, getRouteById);
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName);
PHP_METHOD(Phalcon_Mvc_Router, isExactControllerName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultRoutes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_seturisource, 0, 0, 1)
	ZEND_ARG_INFO(0, uriSource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_removeextraslashes, 0, 0, 1)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_mount, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_notfound, 0, 0, 1)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_router_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Router, __construct, arginfo_phalcon_mvc_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Router, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRewriteUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setUriSource, arginfo_phalcon_mvc_router_seturisource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, removeExtraSlashes, arginfo_phalcon_mvc_router_removeextraslashes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultNamespace, arginfo_phalcon_mvc_router_setdefaultnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getDefaultNamespace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultModule, arginfo_phalcon_mvc_routerinterface_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getDefaultModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultController, arginfo_phalcon_mvc_routerinterface_setdefaultcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getDefaultController, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultAction, arginfo_phalcon_mvc_routerinterface_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getDefaultAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaults, arginfo_phalcon_mvc_routerinterface_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getDefaults, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, handle, arginfo_phalcon_mvc_routerinterface_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, add, arginfo_phalcon_mvc_routerinterface_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addGet, arginfo_phalcon_mvc_routerinterface_addget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addPost, arginfo_phalcon_mvc_routerinterface_addpost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addPut, arginfo_phalcon_mvc_routerinterface_addput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addPatch, arginfo_phalcon_mvc_routerinterface_addpatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addDelete, arginfo_phalcon_mvc_routerinterface_adddelete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addOptions, arginfo_phalcon_mvc_routerinterface_addoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addHead, arginfo_phalcon_mvc_routerinterface_addhead, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, mount, arginfo_phalcon_mvc_router_mount, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, notFound, arginfo_phalcon_mvc_router_notfound, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getNamespaceName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getMatchedRoute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getMatches, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, wasMatched, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRoutes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRouteById, arginfo_phalcon_mvc_routerinterface_getroutebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRouteByName, arginfo_phalcon_mvc_routerinterface_getroutebyname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, isExactControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Router initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Router){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, Router, mvc_router, phalcon_mvc_router_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_uriSource"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_namespace"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_module"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_controller"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_routes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_routesNameLookup"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_matchedRoute"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_matches"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_router_ce, SL("_wasMatched"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultNamespace"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultController"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultAction"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_removeExtraSlashes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_notFoundPaths"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_router_ce, SL("_isExactControllerName"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_router_ce, SL("URI_SOURCE_GET_URL"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_router_ce, SL("URI_SOURCE_SERVER_REQUEST_URI"), 1 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_router_ce TSRMLS_CC, 2, phalcon_mvc_routerinterface_ce, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Router constructor
 *
 * @param boolean $defaultRoutes
 */
PHP_METHOD(Phalcon_Mvc_Router, __construct){

	zval *default_routes = NULL, *routes, *paths = NULL, *action_pattern;
	zval *route = NULL, *params_pattern;

	PHALCON_MM_GROW();

	phalcon_update_property_empty_array(this_ptr, SL("_defaultParams") TSRMLS_CC);

	phalcon_fetch_params(1, 0, 1, &default_routes);

	if (!default_routes) {
		default_routes = PHALCON_GLOBAL(z_true);
	}

	PHALCON_INIT_VAR(routes);
	array_init(routes);
	if (PHALCON_IS_TRUE(default_routes)) {

		/**
		 * Two routes are added by default to match /:controller/:action and
		 * /:controller/:action/:params
		 */
		PHALCON_INIT_VAR(paths);
		array_init_size(paths, 1);
		add_assoc_long_ex(paths, ISS(controller), 1);

		PHALCON_INIT_VAR(action_pattern);
		ZVAL_STRING(action_pattern, "#^/([a-zA-Z0-9_-]++)/?+$#", 1);

		PHALCON_INIT_VAR(route);
		object_init_ex(route, phalcon_mvc_router_route_ce);
		PHALCON_CALL_METHOD(NULL, route, "__construct", action_pattern, paths);

		phalcon_array_append(&routes, route, 0);

		PHALCON_INIT_NVAR(paths);
		array_init_size(paths, 3);
		add_assoc_long_ex(paths, ISS(controller), 1);
		add_assoc_long_ex(paths, ISS(action), 2);
		add_assoc_long_ex(paths, ISS(params), 3);

		PHALCON_INIT_VAR(params_pattern);
		ZVAL_STRING(params_pattern, "#^/([a-zA-Z0-9_-]++)/([a-zA-Z0-9\\._]++)(/.*+)?+$#", 1);

		PHALCON_INIT_NVAR(route);
		object_init_ex(route, phalcon_mvc_router_route_ce);
		PHALCON_CALL_METHOD(NULL, route, "__construct", params_pattern, paths);

		phalcon_array_append(&routes, route, 0);
	}

	phalcon_update_property_empty_array(this_ptr, SL("_params") TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_routes"), routes TSRMLS_CC);
	phalcon_update_property_empty_array(this_ptr, SL("_routesNameLookup") TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Router, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_router_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Router, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Get rewrite info. This info is read from $_GET['_url']. This returns '/' if the rewrite information cannot be read
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getRewriteUri){

	zval *uri_source, *_GET, *url = NULL, *_SERVER, *url_parts;
	zval *real_uri;

	/**
	 * The developer can change the URI source
	 */
	uri_source = phalcon_fetch_nproperty_this(this_ptr, SL("_uriSource"), PH_NOISY TSRMLS_CC);

	/**
	 * By default we use $_GET['url'] to obtain the rewrite information
	 */
	if (!zend_is_true(uri_source)) { /* FIXME: Compare with URI_SOURCE_SERVER_REQUEST_URI */
		_GET = phalcon_get_global(SS("_GET") TSRMLS_CC);
		if (phalcon_array_isset_string_fetch(&url, _GET, SS("_url"))) {
			if (PHALCON_IS_NOT_EMPTY(url)) {
				RETURN_ZVAL(url, 1, 0);
			}
		}
	} else {
		/**
		 * Otherwise use the standard $_SERVER['REQUEST_URI']
		 */
		_SERVER = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
		if (phalcon_array_isset_string_fetch(&url, _SERVER, SS("REQUEST_URI"))) {
			ALLOC_INIT_ZVAL(url_parts);
			phalcon_fast_explode_str(url_parts, SL("?"), url);

			phalcon_array_fetch_long(&real_uri, url_parts, 0, PH_NOISY);
			zval_ptr_dtor(&url_parts);
			if (PHALCON_IS_NOT_EMPTY(real_uri)) {
				RETURN_ZVAL(real_uri, 1, 1);
			}

			zval_ptr_dtor(&real_uri);
		}
	}

	RETURN_STRING("/", 1);
}

/**
 * Sets the URI source. One of the URI_SOURCE_* constants
 *
 *<code>
 *	$router->setUriSource(Router::URI_SOURCE_SERVER_REQUEST_URI);
 *</code>
 *
 * @param int $uriSource
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setUriSource){

	zval *uri_source;

	phalcon_fetch_params(0, 1, 0, &uri_source);

	phalcon_update_property_this(this_ptr, SL("_uriSource"), uri_source TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Set whether router must remove the extra slashes in the handled routes
 *
 * @param boolean $remove
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes){

	zval *remove;

	phalcon_fetch_params(0, 1, 0, &remove);

	phalcon_update_property_this(this_ptr, SL("_removeExtraSlashes"), remove TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Sets the name of the default namespace
 *
 * @param string $namespaceName
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace){

	zval *namespace_name;

	phalcon_fetch_params(0, 1, 0, &namespace_name);

	phalcon_update_property_this(this_ptr, SL("_defaultNamespace"), namespace_name TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the name of the default namespace
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaultNamespace){

	RETURN_MEMBER(this_ptr, "_defaultNamespace");
}

/**
 * Sets the name of the default module
 *
 * @param string $moduleName
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule){

	zval *module_name;

	phalcon_fetch_params(0, 1, 0, &module_name);

	phalcon_update_property_this(this_ptr, SL("_defaultModule"), module_name TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the name of the default module
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaultModule){

	RETURN_MEMBER(this_ptr, "_defaultModule");
}

/**
 * Sets the default controller name
 *
 * @param string $controllerName
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultController){

	zval *controller_name;

	phalcon_fetch_params(0, 1, 0, &controller_name);

	phalcon_update_property_this(this_ptr, SL("_defaultController"), controller_name TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the default controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaultController){

	RETURN_MEMBER(this_ptr, "_defaultController");
}

/**
 * Sets the default action name
 *
 * @param string $actionName
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction){

	zval *action_name;

	phalcon_fetch_params(0, 1, 0, &action_name);

	phalcon_update_property_this(this_ptr, SL("_defaultAction"), action_name TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the default action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaultAction){

	RETURN_MEMBER(this_ptr, "_defaultAction");
}

/**
 * Sets an array of default paths. If a route is missing a path the router will use the defined here
 * This method must not be used to set a 404 route
 *
 *<code>
 * $router->setDefaults(array(
 *		'module' => 'common',
 *		'action' => 'index'
 * ));
 *</code>
 *
 * @param array $defaults
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaults){

	zval *defaults, *namespace_name, *module_name;
	zval *controller_name, *action_name, *params;

	phalcon_fetch_params(0, 1, 0, &defaults);

	if (Z_TYPE_P(defaults) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_router_exception_ce, "Defaults must be an array");
		return;
	}

	/* Set the default namespace */
	if (phalcon_array_isset_string_fetch(&namespace_name, defaults, SS("namespace"))) {
		phalcon_update_property_this(this_ptr, SL("_defaultNamespace"), namespace_name TSRMLS_CC);
	}

	/* Set the default module */
	if (phalcon_array_isset_string_fetch(&module_name, defaults, SS("module"))) {
		phalcon_update_property_this(this_ptr, SL("_defaultModule"), module_name TSRMLS_CC);
	}

	/* Set the default controller */
	if (phalcon_array_isset_string_fetch(&controller_name, defaults, SS("controller"))) {
		phalcon_update_property_this(this_ptr, SL("_defaultController"), controller_name TSRMLS_CC);
	}

	/* Set the default action */
	if (phalcon_array_isset_string_fetch(&action_name, defaults, SS("action"))) {
		phalcon_update_property_this(this_ptr, SL("_defaultAction"), action_name TSRMLS_CC);
	}

	/* Set default parameters */
	if (phalcon_array_isset_string_fetch(&params, defaults, SS("params"))) {
		phalcon_update_property_this(this_ptr, SL("_defaultParams"), params TSRMLS_CC);
	}

	RETURN_THISW();
}

/**
 * Returns an array of default parameters
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaults){

	zval *namespace_name, *module_name;
	zval *controller_name, *action_name, *params;

	namespace_name  = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY TSRMLS_CC);
	module_name     = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultModule"), PH_NOISY TSRMLS_CC);
	controller_name = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultController"), PH_NOISY TSRMLS_CC);
	action_name     = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY TSRMLS_CC);
	params          = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultParams"), PH_NOISY TSRMLS_CC);

	array_init_size(return_value, 5);

	phalcon_array_update_string(&return_value, ISL(namespace),  namespace_name,  PH_COPY);
	phalcon_array_update_string(&return_value, ISL(module),     module_name,     PH_COPY);
	phalcon_array_update_string(&return_value, ISL(controller), controller_name, PH_COPY);
	phalcon_array_update_string(&return_value, ISL(action),     action_name,     PH_COPY);
	phalcon_array_update_string(&return_value, ISL(params),     params,          PH_COPY);
}

/**
 * Handles routing information received from the rewrite engine
 *
 *<code>
 * //Read the info from the rewrite engine
 * $router->handle();
 *
 * //Manually passing an URL
 * $router->handle('/posts/edit/1');
 *</code>
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Mvc_Router, handle){

	zval *uri = NULL, *real_uri = NULL;
	zval *handled_uri = NULL, *request = NULL, *current_host_name = NULL;
	zval *route_found = NULL, *parts = NULL, *params = NULL, *matches, *routes;
	zval *route = NULL, *methods = NULL;
	zval *service, *match_method = NULL, *hostname = NULL, *regex_host_name = NULL;
	zval *matched = NULL, *pattern = NULL, *before_match = NULL, *before_match_params = NULL;
	zval *paths = NULL, *converters = NULL, *position = NULL, *part = NULL;
	zval *parameters = NULL, *converted_part = NULL;
	zval *namespace, *module, *controller;
	zval *action, *params_str, *str_params;
	zval *params_merge = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	zval *dependency_injector, *tmp;
	zval *match_position = NULL, *converter = NULL;
	zval *exact = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &uri);

	if (!uri || !zend_is_true(uri)) {
		/**
		 * If 'uri' isn't passed as parameter it reads $_GET['_url']
		 */
		PHALCON_CALL_METHOD(&real_uri, this_ptr, "getrewriteuri");
	} else {
		real_uri = uri;
	}

	/**
	 * Remove extra slashes in the route
	 */
	tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_removeExtraSlashes"), PH_NOISY TSRMLS_CC);
	if (zend_is_true(tmp)) {
		PHALCON_INIT_VAR(handled_uri);
		phalcon_remove_extra_slashes(handled_uri, real_uri);
	} else {
		handled_uri = real_uri;
	}

	PHALCON_INIT_VAR(current_host_name);

	PHALCON_INIT_VAR(route_found);
	ZVAL_FALSE(route_found);

	PHALCON_INIT_VAR(parts);
	array_init(parts);

	PHALCON_INIT_VAR(params);
	array_init(params);

	PHALCON_INIT_VAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_request);

	PHALCON_INIT_VAR(matches);
	phalcon_update_property_bool(this_ptr, SL("_wasMatched"), 0 TSRMLS_CC);
	phalcon_update_property_null(this_ptr, SL("_matchedRoute") TSRMLS_CC);

	/**
	 * Routes are traversed in reversed order
	 */
	routes = phalcon_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY TSRMLS_CC);

	phalcon_is_iterable(routes, &ah0, &hp0, 0, 1);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HVALUE(route);

		/**
		 * Look for HTTP method constraints
		 */
		PHALCON_CALL_METHOD(&methods, route, "gethttpmethods");
		if (Z_TYPE_P(methods) != IS_NULL) {

			/**
			 * Retrieve the request service from the container
			 */
			if (!request) {
				dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
				PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_router_exception_ce, 1);

				PHALCON_CALL_METHOD(&request, dependency_injector, "getshared", service);
				PHALCON_VERIFY_INTERFACE_EX(request, phalcon_http_requestinterface_ce, phalcon_mvc_router_exception_ce, 1);
			}

			/**
			 * Check if the current method is allowed by the route
			 */
			PHALCON_CALL_METHOD(&match_method, request, "ismethod", methods);
			if (PHALCON_IS_FALSE(match_method)) {
				zend_hash_move_backwards_ex(ah0, &hp0);
				continue;
			}
		}

		/**
		 * Look for hostname constraints
		 */
		PHALCON_CALL_METHOD(&hostname, route, "gethostname");
		if (Z_TYPE_P(hostname) != IS_NULL) {

			/**
			 * Retrieve the request service from the container
			 */
			if (!request) {
				dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
				PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_router_exception_ce, 1);

				PHALCON_CALL_METHOD(&request, dependency_injector, "getshared", service);
				PHALCON_VERIFY_INTERFACE_EX(request, phalcon_http_requestinterface_ce, phalcon_mvc_router_exception_ce, 1);
			}

			/**
			 * Check if the current hostname is the same as the route
			 */
			if (Z_TYPE_P(current_host_name) == IS_NULL) {
				PHALCON_CALL_METHOD(&current_host_name, request, "gethttphost");
			}

			/**
			 * No HTTP_HOST, maybe in CLI mode?
			 */
			if (Z_TYPE_P(current_host_name) == IS_NULL) {
				zend_hash_move_backwards_ex(ah0, &hp0);
				continue;
			}

			/**
			 * Check if the hostname restriction is the same as the current in the route
			 */
			PHALCON_INIT_NVAR(matched);
			if (phalcon_memnstr_str(hostname, SL("("))) {
				if (!phalcon_memnstr_str(hostname, SL("#"))) {
					PHALCON_INIT_NVAR(regex_host_name);
					/* FIXME: handle mixed case */
					PHALCON_CONCAT_SVS(regex_host_name, "#^", hostname, "$#");
				} else {
					PHALCON_CPY_WRT(regex_host_name, hostname);
				}

				RETURN_MM_ON_FAILURE(phalcon_preg_match(matched, regex_host_name, current_host_name, NULL TSRMLS_CC));
			} else {
				/* FIXME: handle mixed case */
				is_equal_function(matched, current_host_name, hostname TSRMLS_CC);
			}

			if (!zend_is_true(matched)) {
				zend_hash_move_backwards_ex(ah0, &hp0);
				continue;
			}
		}

		/**
		 * If the route has parentheses use preg_match
		 */
		PHALCON_CALL_METHOD(&pattern, route, "getcompiledpattern");

		PHALCON_INIT_NVAR(route_found);
		if (Z_TYPE_P(pattern) == IS_STRING && Z_STRLEN_P(pattern) > 3 && Z_STRVAL_P(pattern)[1] == '^') {
			RETURN_MM_ON_FAILURE(phalcon_preg_match(route_found, pattern, handled_uri, matches TSRMLS_CC));
		} else {
			is_equal_function(route_found, pattern, handled_uri TSRMLS_CC);
		}

		/**
		 * Check for beforeMatch conditions
		 */
		if (zend_is_true(route_found)) {

			PHALCON_CALL_METHOD(&before_match, route, "getbeforematch");
			if (Z_TYPE_P(before_match) != IS_NULL) {

				/**
				 * Check first if the callback is callable
				 */
				if (!phalcon_is_callable(before_match TSRMLS_CC)) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "Before-Match callback is not callable in matched route");
					return;
				}

				/**
				 * Before-Match parameters
				 */
				PHALCON_INIT_NVAR(before_match_params);
				array_init_size(before_match_params, 3);
				phalcon_array_append(&before_match_params, handled_uri, 0);
				phalcon_array_append(&before_match_params, route, 0);
				phalcon_array_append(&before_match_params, this_ptr, 0);

				/**
				 * Call the function in the PHP userland
				 */
				PHALCON_INIT_NVAR(route_found);/**/
				PHALCON_CALL_USER_FUNC_ARRAY(route_found, before_match, before_match_params);
			}
		}

		if (zend_is_true(route_found)) {

			/**
			 * Start from the default paths
			 */
			PHALCON_CALL_METHOD(&paths, route, "getpaths");
			PHALCON_CPY_WRT(parts, paths);

			/**
			 * Check if the matches has variables
			 */
			if (Z_TYPE_P(matches) == IS_ARRAY) {

				/**
				 * Get the route converters if any
				 */
				PHALCON_CALL_METHOD(&converters, route, "getconverters");

				phalcon_is_iterable(paths, &ah1, &hp1, 0, 0);

				while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {

					PHALCON_GET_HKEY(part, ah1, hp1);
					PHALCON_GET_HVALUE(position);

					if (Z_TYPE_P(part) != IS_STRING || Z_STRVAL_P(part)[0] != '\0') {
						if (phalcon_array_isset_fetch(&match_position, matches, position)) {
							/* Check if the part has a converter */
							if (phalcon_array_isset_fetch(&converter, converters, part)) {
								PHALCON_INIT_NVAR(parameters);
								array_init_size(parameters, 1);
								phalcon_array_append(&parameters, match_position, 0);

								PHALCON_INIT_NVAR(converted_part);/**/
								PHALCON_CALL_USER_FUNC_ARRAY(converted_part, converter, parameters);
								phalcon_array_update_zval(&parts, part, converted_part, PH_COPY);
								zend_hash_move_forward_ex(ah1, &hp1);
								continue;
							}

							/* Update the parts if there is no converter */
							phalcon_array_update_zval(&parts, part, match_position, PH_COPY);
						} else {
							/* Apply the converters anyway */
							if (phalcon_array_isset_fetch(&converter, converters, part)) {
								PHALCON_INIT_NVAR(parameters);
								array_init_size(parameters, 1);
								phalcon_array_append(&parameters, position, 0);

								PHALCON_INIT_NVAR(converted_part);/**/
								PHALCON_CALL_USER_FUNC_ARRAY(converted_part, converter, parameters);
								phalcon_array_update_zval(&parts, part, converted_part, PH_COPY);
							}
						}
					}

					zend_hash_move_forward_ex(ah1, &hp1);
				}

				/**
				 * Update the matches generated by preg_match
				 */
				phalcon_update_property_this(this_ptr, SL("_matches"), matches TSRMLS_CC);
			}

			phalcon_update_property_this(this_ptr, SL("_matchedRoute"), route TSRMLS_CC);
			break;
		}

		zend_hash_move_backwards_ex(ah0, &hp0);
	}

	/**
	 * Update the wasMatched property indicating if the route was matched
	 */
	phalcon_update_property_bool(this_ptr, SL("_wasMatched"), zend_is_true(route_found) TSRMLS_CC);

	/**
	 * The route wasn't found, try to use the not-found paths
	 */
	if (!zend_is_true(route_found)) {

		tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_notFoundPaths"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(tmp) != IS_NULL) {
			PHALCON_CPY_WRT(parts, tmp);

			PHALCON_INIT_NVAR(route_found);
			ZVAL_TRUE(route_found);
		}
	}

	if (zend_is_true(route_found)) {

		/**
		 * Check for a namespace
		 */
		if (phalcon_array_isset_string_fetch(&namespace, parts, SS("namespace"))) {
			phalcon_update_property_this(this_ptr, SL("_namespace"), namespace TSRMLS_CC);
			phalcon_array_unset_string(&parts, SS("namespace"), PH_SEPARATE);
		} else {
			tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY TSRMLS_CC);
			phalcon_update_property_this(this_ptr, SL("_namespace"), tmp TSRMLS_CC);
		}

		/**
		 * Check for a module
		 */
		if (phalcon_array_isset_string_fetch(&module, parts, SS("module"))) {
			phalcon_update_property_this(this_ptr, SL("_module"), module TSRMLS_CC);
			phalcon_array_unset_string(&parts, SS("module"), PH_SEPARATE);
		} else {
			tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultModule"), PH_NOISY TSRMLS_CC);
			phalcon_update_property_this(this_ptr, SL("_module"), tmp TSRMLS_CC);
		}

		if (phalcon_array_isset_string_fetch(&exact, parts, SS("\0exact"))) {
			phalcon_update_property_this(this_ptr, SL("_isExactControllerName"), exact TSRMLS_CC);
			phalcon_array_unset_string(&parts, SS("\0exact"), PH_SEPARATE);
		}
		else {
			PHALCON_INIT_VAR(exact);
			ZVAL_FALSE(exact);
			phalcon_update_property_this(this_ptr, SL("_isExactControllerName"), exact TSRMLS_CC);
		}

		/**
		 * Check for a controller
		 */
		if (phalcon_array_isset_string_fetch(&controller, parts, SS("controller"))) {
			phalcon_update_property_this(this_ptr, SL("_controller"), controller TSRMLS_CC);
			phalcon_array_unset_string(&parts, SS("controller"), PH_SEPARATE);
		} else {
			tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultController"), PH_NOISY TSRMLS_CC);
			phalcon_update_property_this(this_ptr, SL("_controller"), tmp TSRMLS_CC);
		}

		/**
		 * Check for an action
		 */
		if (phalcon_array_isset_string_fetch(&action, parts, SS("action"))) {
			phalcon_update_property_this(this_ptr, SL("_action"), action TSRMLS_CC);
			phalcon_array_unset_string(&parts, SS("action"), PH_SEPARATE);
		} else {
			tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY TSRMLS_CC);
			phalcon_update_property_this(this_ptr, SL("_action"), tmp TSRMLS_CC);
		}

		/**
		 * Check for parameters
		 */
		if (phalcon_array_isset_string_fetch(&params_str, parts, SS("params"))) {
			PHALCON_INIT_VAR(str_params);
			phalcon_substr(str_params, params_str, 1, 0);
			if (zend_is_true(str_params)) {
				zval slash;
				ZVAL_STRINGL(&slash, "/", 1, 0);

				PHALCON_INIT_NVAR(params);
				phalcon_fast_explode(params, &slash, str_params);
			}

			phalcon_array_unset_string(&parts, SS("params"), PH_SEPARATE);
		}

		if (zend_hash_num_elements(Z_ARRVAL_P(params))) {
			PHALCON_INIT_VAR(params_merge);
			phalcon_fast_array_merge(params_merge, &params, &parts TSRMLS_CC);
		} else {
			params_merge = parts;
		}

		phalcon_update_property_this(this_ptr, SL("_params"), params_merge TSRMLS_CC);
	} else {
		/**
		 * Use default values if the route hasn't matched
		 */
		tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_namespace"), tmp TSRMLS_CC);

		tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultModule"), PH_NOISY TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_module"), tmp TSRMLS_CC);

		tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultController"), PH_NOISY TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_controller"), tmp TSRMLS_CC);

		tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_action"), tmp TSRMLS_CC);

		tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultParams"), PH_NOISY TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_params"), tmp TSRMLS_CC);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Adds a route to the router without any HTTP constraint
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
PHP_METHOD(Phalcon_Mvc_Router, add){

	zval *pattern, *paths = NULL, *http_methods = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &pattern, &paths, &http_methods);

	if (!paths) {
		paths = PHALCON_GLOBAL(z_null);
	}

	if (!http_methods) {
		http_methods = PHALCON_GLOBAL(z_null);
	}

	/**
	 * Every route is internally stored as a Phalcon\Mvc\Router\Route
	 */
	object_init_ex(return_value, phalcon_mvc_router_route_ce);
	PHALCON_CALL_METHOD(NULL, return_value, "__construct", pattern, paths, http_methods);

	phalcon_update_property_array_append(this_ptr, SL("_routes"), return_value TSRMLS_CC);
	RETURN_MM();
}

static void phalcon_mvc_router_add_helper(INTERNAL_FUNCTION_PARAMETERS, const char *method)
{
	zval *pattern, *paths = NULL, *http_method;

	phalcon_fetch_params(0, 1, 1, &pattern, &paths);

	if (!paths) {
		paths = PHALCON_GLOBAL(z_null);
	}

	PHALCON_ALLOC_GHOST_ZVAL(http_method);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(http_method, method);
	PHALCON_RETURN_CALL_METHODW(getThis(), "add", pattern, paths, http_method);
}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addGet){

	phalcon_mvc_router_add_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, phalcon_interned_GET);
}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addPost){

	phalcon_mvc_router_add_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, phalcon_interned_POST);
}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addPut){

	phalcon_mvc_router_add_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, phalcon_interned_PUT);
}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addPatch){

	phalcon_mvc_router_add_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, phalcon_interned_PATCH);
}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addDelete){

	phalcon_mvc_router_add_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, phalcon_interned_DELETE);
}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addOptions){

	phalcon_mvc_router_add_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, phalcon_interned_OPTIONS);
}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string $pattern
 * @param string/array $paths
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, addHead){

	phalcon_mvc_router_add_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, phalcon_interned_HEAD);
}

static int phalcon_router_call_convert(void *pDest TSRMLS_DC, int num_args, va_list args, zend_hash_key *hash_key)
{
	zval *route, key = zval_used_for_init;
	zval *params[2];

	assert(num_args == 1);

	route = va_arg(args, zval*);
	if (hash_key->nKeyLength) {
		ZVAL_STRINGL(&key, hash_key->arKey, hash_key->nKeyLength-1, 0);
	}
	else {
		ZVAL_LONG(&key, hash_key->h);
	}

	params[0] = &key;
	params[1] = *((zval**)pDest);

	if (FAILURE == phalcon_call_method(NULL, route, "convert", 2, params TSRMLS_CC)) {
		return ZEND_HASH_APPLY_STOP;
	}

	return ZEND_HASH_APPLY_KEEP;
}

/**
 * Mounts a group of routes in the router
 *
 * @param Phalcon\Mvc\Router\Group $route
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, mount){

	zval *group, *group_routes = NULL, *before_match = NULL;
	zval *hostname = NULL, *converters = NULL, *routes, *new_routes;
	HashPosition hp0;
	zval **route;

	phalcon_fetch_params(0, 1, 0, &group);
	PHALCON_VERIFY_CLASS_EX(group, phalcon_mvc_router_group_ce, phalcon_mvc_router_exception_ce, 0);

	PHALCON_MM_GROW();

	PHALCON_CALL_METHOD(&group_routes, group, "getroutes");
	if (Z_TYPE_P(group_routes) != IS_ARRAY || !zend_hash_num_elements(Z_ARRVAL_P(group_routes))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "The group of routes does not contain any routes");
		return;
	}

	/* Get the before-match condition */
	PHALCON_CALL_METHOD(&before_match, group, "getbeforematch");

	/* Get the hostname restriction */
	PHALCON_CALL_METHOD(&hostname, group, "gethostname");

	/* Get converters */
	PHALCON_CALL_METHOD(&converters, group, "getconverters");

	if (Z_TYPE_P(before_match) != IS_NULL || Z_TYPE_P(hostname) != IS_NULL || Z_TYPE_P(converters) != IS_NULL) {
		int has_before_match = (Z_TYPE_P(before_match) != IS_NULL);
		int has_hostname     = (Z_TYPE_P(hostname) != IS_NULL);
		int has_converters   = (Z_TYPE_P(converters) != IS_NULL);

		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(group_routes), &hp0);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(group_routes), (void**)&route, &hp0) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(group_routes), &hp0)
		) {
			if (has_before_match) {
				PHALCON_CALL_METHOD(NULL, *route, "beforematch", before_match);
			}

			if (has_hostname) {
				PHALCON_CALL_METHOD(NULL, *route, "sethostname", hostname);
			}

			if (has_converters) {
				zend_hash_apply_with_arguments(Z_ARRVAL_P(converters) TSRMLS_CC, phalcon_router_call_convert, 1, *route);
			}
		}
	}

	routes = phalcon_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(routes) == IS_ARRAY) {
		PHALCON_INIT_VAR(new_routes);
		phalcon_fast_array_merge(new_routes, &routes, &group_routes TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_routes"), new_routes TSRMLS_CC);
	} else {
		phalcon_update_property_this(this_ptr, SL("_routes"), group_routes TSRMLS_CC);
	}

	RETURN_THIS();
}

/**
 * Set a group of paths to be returned when none of the defined routes are matched
 *
 * @param array|string $paths
 * @return Phalcon\Mvc\Router
 */
PHP_METHOD(Phalcon_Mvc_Router, notFound){

	zval *paths;

	phalcon_fetch_params(0, 1, 0, &paths);

	if (Z_TYPE_P(paths) != IS_ARRAY) {
		if (Z_TYPE_P(paths) != IS_STRING) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_router_exception_ce, "The not-found paths must be an array or string");
			return;
		}
	}
	phalcon_update_property_this(this_ptr, SL("_notFoundPaths"), paths TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, clear){

	zval *empty_routes;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(empty_routes);
	array_init(empty_routes);
	phalcon_update_property_this(this_ptr, SL("_routes"), empty_routes TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_routesNameLookup"), empty_routes TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Returns the processed namespace name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName){


	RETURN_MEMBER(this_ptr, "_namespace");
}

/**
 * Returns the processed module name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getModuleName){


	RETURN_MEMBER(this_ptr, "_module");
}

/**
 * Returns the processed controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getControllerName){


	RETURN_MEMBER(this_ptr, "_controller");
}

/**
 * Returns the processed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Router, getActionName){


	RETURN_MEMBER(this_ptr, "_action");
}

/**
 * Returns the processed parameters
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getParams){


	RETURN_MEMBER(this_ptr, "_params");
}

/**
 * Returns the route that matchs the handled URI
 *
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute){


	RETURN_MEMBER(this_ptr, "_matchedRoute");
}

/**
 * Returns the sub expressions in the regular expression matched
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatches){


	RETURN_MEMBER(this_ptr, "_matches");
}

/**
 * Checks if the router macthes any of the defined routes
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Router, wasMatched){


	RETURN_MEMBER(this_ptr, "_wasMatched");
}

/**
 * Returns all the routes defined in the router
 *
 * @return Phalcon\Mvc\Router\Route[]
 */
PHP_METHOD(Phalcon_Mvc_Router, getRoutes){


	RETURN_MEMBER(this_ptr, "_routes");
}

/**
 * Returns a route object by its id
 *
 * @param string $id
 * @return Phalcon\Mvc\Router\Route | false
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteById){

	zval *id, *routes, **route, *route_id = NULL;
	HashPosition hp0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &id);

	routes = phalcon_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(routes) == IS_ARRAY) {
		for(
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(routes), &hp0);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(routes), (void**)&route, &hp0) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(routes), &hp0)
		) {
			PHALCON_CALL_METHOD(&route_id, *route, "getrouteid");
			if (phalcon_is_equal(route_id, id TSRMLS_CC)) {
				RETURN_CTOR(*route);
			}
		}
	}

	RETURN_MM_FALSE;
}

/**
 * Returns a route object by its name
 *
 * @param string $name
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName){

	zval *name, *routes, **route, *routes_name_lookup, *route_name = NULL;
	HashPosition hp0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);

	if (UNEXPECTED(Z_TYPE_P(name) != IS_STRING)) {
		PHALCON_SEPARATE_PARAM(name);
		convert_to_string(name);
	}

	routes_name_lookup = phalcon_fetch_nproperty_this(this_ptr, SL("_routesNameLookup"), PH_NOISY TSRMLS_CC);
	if (PHALCON_IS_NOT_EMPTY(name) && phalcon_hash_find(Z_ARRVAL_P(routes_name_lookup), Z_STRVAL_P(name), Z_STRLEN_P(name) + 1, (void **)&route) == SUCCESS) {
		RETURN_CTOR(*route);
	}

	routes = phalcon_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(routes) == IS_ARRAY) {
		for(
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(routes), &hp0);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(routes), (void**)&route, &hp0) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(routes), &hp0)
		) {
			PHALCON_CALL_METHOD(&route_name, *route, "getname");
			convert_to_string(route_name);
			if (PHALCON_IS_NOT_EMPTY(route_name)) {
				phalcon_update_property_array_string(this_ptr, SL("_routesNameLookup"), Z_STRVAL_P(route_name), Z_STRLEN_P(route_name) + 1, *route TSRMLS_CC);
			}

			if (phalcon_is_equal(route_name, name TSRMLS_CC)) {
				RETURN_CTOR(*route);
			}
		}
	}

	RETURN_MM_FALSE;
}

/**
 * Returns whether controller name should not be mangled
 */
PHP_METHOD(Phalcon_Mvc_Router, isExactControllerName) {
	RETURN_MEMBER(this_ptr, "_isExactControllerName");
}
