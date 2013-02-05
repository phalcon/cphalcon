
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
 * //Generate a url appending a uri to the base Uri
 * echo $url->get('products/edit/1');
 *
 * //Generate a url for a predefined route
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
	zend_declare_property_null(phalcon_mvc_url_ce, SL("_basePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_MM_NULL();
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
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Url, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets a prefix to all the urls generated
 *
 *<code>
 *	$url->setBaseUri('/invo/');
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

	zval *base_uri = NULL, *slash, *_SERVER, *one, *minus_one = NULL;
	zval *php_self, *dirname, *dir_parts, *slice, *uri = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(base_uri);
	phalcon_read_property(&base_uri, this_ptr, SL("_baseUri"), PH_NOISY_CC);
	if (Z_TYPE_P(base_uri) == IS_NULL) {
	
		PHALCON_INIT_VAR(slash);
		ZVAL_STRING(slash, "/", 1);
		phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		if (phalcon_array_isset_string(_SERVER, SS("PHP_SELF"))) {
			PHALCON_INIT_VAR(one);
			ZVAL_LONG(one, 1);
	
			PHALCON_INIT_VAR(c0);
			ZVAL_LONG(c0, -1);
			PHALCON_CPY_WRT(minus_one, c0);
	
			PHALCON_OBS_VAR(php_self);
			phalcon_array_fetch_string(&php_self, _SERVER, SL("PHP_SELF"), PH_NOISY_CC);
	
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
		}
	
		if (!zend_is_true(uri)) {
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
 *	$url->setBasePath('/var/www/');
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


	RETURN_MEMBER(this_ptr, "_basePath");
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
	zval *pattern, *paths, *processed_uri, *final_uri = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &uri) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!uri) {
		PHALCON_INIT_VAR(uri);
	}
	
	PHALCON_INIT_VAR(base_uri);
	PHALCON_CALL_METHOD(base_uri, this_ptr, "getbaseuri");
	if (Z_TYPE_P(uri) == IS_ARRAY) { 
		if (!phalcon_array_isset_string(uri, SS("for"))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_url_exception_ce, "It's necessary to define the route name with the parameter \"for\"");
			return;
		}
	
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (!zend_is_true(dependency_injector)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_url_exception_ce, "A dependency injector container is required to obtain the \"url\" service");
			return;
		}
	
		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "router", 1);
	
		PHALCON_INIT_VAR(router);
		PHALCON_CALL_METHOD_PARAMS_1(router, dependency_injector, "getshared", service);
	
		PHALCON_OBS_VAR(route_name);
		phalcon_array_fetch_string(&route_name, uri, SL("for"), PH_NOISY_CC);
	
		/** 
		 * Every route is uniquely differenced by a name
		 */
		PHALCON_INIT_VAR(route);
		PHALCON_CALL_METHOD_PARAMS_1(route, router, "getroutebyname", route_name);
		if (Z_TYPE_P(route) != IS_OBJECT) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Cannot obtain a route using the name \"", route_name, "\"");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_url_exception_ce, exception_message);
			return;
		}
	
		PHALCON_INIT_VAR(pattern);
		PHALCON_CALL_METHOD(pattern, route, "getpattern");
	
		/** 
		 * Return the reversed paths
		 */
		PHALCON_INIT_VAR(paths);
		PHALCON_CALL_METHOD(paths, route, "getreversedpaths");
	
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
 * Generates a local path
 *
 * @param string $path
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, path){

	zval *path = NULL, *base_path, *final_path;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &path) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!path) {
		PHALCON_INIT_VAR(path);
	}
	
	PHALCON_OBS_VAR(base_path);
	phalcon_read_property(&base_path, this_ptr, SL("_basePath"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(final_path);
	PHALCON_CONCAT_VV(final_path, base_path, path);
	RETURN_CTOR(final_path);
}

