
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Url
 *
 * This components aids in the generation of: URIs, URLs and Paths
 *
 *<code>
 *
 * //Generate a URL appending the URI to the base URI
 * echo $url->get('products/edit/1');
 *
 * //Generate a URL for a predefined route
 * echo $url->get(array('for' => 'blog-post', 'title' => 'some-cool-stuff', 'year' => '2012'));
 *
 *</code>
 */


/**
 * Phalcon\Mvc\Url initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Url){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, Url, mvc_url, phalcon_mvc_url_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_url_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_url_ce, SL("_baseUri"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_url_ce, SL("_staticBaseUri"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_url_ce, SL("_basePath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_url_ce, SL("_router"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_url_ce TSRMLS_CC, 2, phalcon_mvc_urlinterface_ce, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Url, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_url_exception_ce, "The dependency injector must be an Object");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Url, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets a prefix to all the URIs generated
 *
 *<code>
 *	$url->setBaseUri('/invo/');
 *	$url->setBaseUri('/invo/index.php/');
 *</code>
 *
 * @param string $baseUri
 */
PHP_METHOD(Phalcon_Mvc_Url, setBaseUri){

	zval *base_uri;

	phalcon_fetch_params(0, 1, 0, &base_uri);
	
	phalcon_update_property_this(this_ptr, SL("_baseUri"), base_uri TSRMLS_CC);
	
}

/**
 * Sets a prefix for all static URLs generated
 *
 *<code>
 *	$url->setStaticBaseUri('/invo/');
 *</code>
 *
 * @param string $staticBaseUri
 */
PHP_METHOD(Phalcon_Mvc_Url, setStaticBaseUri){

	zval *static_base_uri;

	phalcon_fetch_params(0, 1, 0, &static_base_uri);
	
	phalcon_update_property_this(this_ptr, SL("_staticBaseUri"), static_base_uri TSRMLS_CC);
	
}

/**
 * Returns the prefix for all the generated urls. By default /
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, getBaseUri){

	zval *base_uri = NULL, *slash, *_SERVER, *php_self, *uri = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(base_uri);
	phalcon_read_property_this(&base_uri, this_ptr, SL("_baseUri"), PH_NOISY_CC);
	if (Z_TYPE_P(base_uri) == IS_NULL) {
	
		PHALCON_INIT_VAR(slash);
		ZVAL_STRING(slash, "/", 1);
		phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		if (phalcon_array_isset_string(_SERVER, SS("PHP_SELF"))) {
			PHALCON_OBS_VAR(php_self);
			phalcon_array_fetch_string(&php_self, _SERVER, SL("PHP_SELF"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(uri);
			phalcon_get_uri(uri, php_self TSRMLS_CC);
		} else {
			PHALCON_INIT_NVAR(uri);
		}
	
		if (!zend_is_true(uri)) {
			PHALCON_CPY_WRT(base_uri, slash);
		} else {
			PHALCON_INIT_NVAR(base_uri);
			PHALCON_CONCAT_VVV(base_uri, slash, uri, slash);
		}
	
		phalcon_update_property_this(this_ptr, SL("_baseUri"), base_uri TSRMLS_CC);
	}
	
	RETURN_CCTOR(base_uri);
}

/**
 * Sets a base path for all the generated paths
 *
 *<code>
 *	$url->setBasePath('/var/www/htdocs/');
 *</code>
 *
 * @param string $basePath
 */
PHP_METHOD(Phalcon_Mvc_Url, setBasePath){

	zval *base_path;

	phalcon_fetch_params(0, 1, 0, &base_path);
	
	phalcon_update_property_this(this_ptr, SL("_basePath"), base_path TSRMLS_CC);
	
}

/**
 * Returns the base path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, getBasePath){


	RETURN_MEMBER(this_ptr, "_basePath");
}

/**
 * Generates a URL
 *
 * @param string|array $uri
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, get){

	zval *uri = NULL, *base_uri, *router = NULL, *dependency_injector;
	zval *service, *route_name, *route, *exception_message;
	zval *pattern, *paths, *processed_uri, *final_uri = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &uri);
	
	if (!uri) {
		PHALCON_INIT_VAR(uri);
	}
	
	PHALCON_INIT_VAR(base_uri);
	phalcon_call_method(base_uri, this_ptr, "getbaseuri");
	if (Z_TYPE_P(uri) == IS_ARRAY) { 
		if (!phalcon_array_isset_string(uri, SS("for"))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_url_exception_ce, "It's necessary to define the route name with the parameter \"for\"");
			return;
		}
	
		PHALCON_OBS_VAR(router);
		phalcon_read_property_this(&router, this_ptr, SL("_router"), PH_NOISY_CC);
	
		/** 
		 * Check if the router has not previously set
		 */
		if (Z_TYPE_P(router) != IS_OBJECT) {
	
			PHALCON_OBS_VAR(dependency_injector);
			phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			if (!zend_is_true(dependency_injector)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_url_exception_ce, "A dependency injector container is required to obtain the \"url\" service");
				return;
			}
	
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "router", 1);
	
			PHALCON_INIT_NVAR(router);
			phalcon_call_method_p1(router, dependency_injector, "getshared", service);
			phalcon_update_property_this(this_ptr, SL("_router"), router TSRMLS_CC);
		}
	
		PHALCON_OBS_VAR(route_name);
		phalcon_array_fetch_string(&route_name, uri, SL("for"), PH_NOISY_CC);
	
		/** 
		 * Every route is uniquely differenced by a name
		 */
		PHALCON_INIT_VAR(route);
		phalcon_call_method_p1(route, router, "getroutebyname", route_name);
		if (Z_TYPE_P(route) != IS_OBJECT) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Cannot obtain a route using the name \"", route_name, "\"");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_url_exception_ce, exception_message);
			return;
		}
	
		PHALCON_INIT_VAR(pattern);
		phalcon_call_method(pattern, route, "getpattern");
	
		/** 
		 * Return the reversed paths
		 */
		PHALCON_INIT_VAR(paths);
		phalcon_call_method(paths, route, "getreversedpaths");
	
		/** 
		 * Replace the patterns by its variables
		 */
		PHALCON_INIT_VAR(processed_uri);
		phalcon_replace_paths(processed_uri, pattern, paths, uri TSRMLS_CC);
	
		PHALCON_INIT_VAR(final_uri);
		PHALCON_CONCAT_VV(final_uri, base_uri, processed_uri);
	
		RETURN_CTOR(final_uri);
	}
	
	PHALCON_INIT_NVAR(final_uri);
	PHALCON_CONCAT_VV(final_uri, base_uri, uri);
	
	RETURN_CTOR(final_uri);
}

/**
 * Generates a URL for a static resource
 *
 * @param string|array $uri
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, getStatic){

	zval *uri = NULL, *static_base_uri, *final_uri, *base_uri;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &uri);
	
	if (!uri) {
		PHALCON_INIT_VAR(uri);
	}
	
	PHALCON_OBS_VAR(static_base_uri);
	phalcon_read_property_this(&static_base_uri, this_ptr, SL("_staticBaseUri"), PH_NOISY_CC);
	if (Z_TYPE_P(static_base_uri) != IS_NULL) {
		PHALCON_INIT_VAR(final_uri);
		PHALCON_CONCAT_VV(final_uri, static_base_uri, uri);
		RETURN_CTOR(final_uri);
	}
	
	PHALCON_INIT_VAR(base_uri);
	phalcon_call_method(base_uri, this_ptr, "getbaseuri");
	
	RETURN_CCTOR(base_uri);
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

	phalcon_fetch_params(1, 0, 1, &path);
	
	if (!path) {
		PHALCON_INIT_VAR(path);
	}
	
	PHALCON_OBS_VAR(base_path);
	phalcon_read_property_this(&base_path, this_ptr, SL("_basePath"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(final_path);
	PHALCON_CONCAT_VV(final_path, base_path, path);
	RETURN_CTOR(final_path);
}

