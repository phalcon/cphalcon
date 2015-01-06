
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

#include "mvc/url.h"
#include "mvc/urlinterface.h"
#include "mvc/url/exception.h"
#include "mvc/routerinterface.h"
#include "diinterface.h"
#include "di/injectionawareinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/framework/url.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/framework/router.h"

#include "interned-strings.h"

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
zend_class_entry *phalcon_mvc_url_ce;

PHP_METHOD(Phalcon_Mvc_Url, setDI);
PHP_METHOD(Phalcon_Mvc_Url, getDI);
PHP_METHOD(Phalcon_Mvc_Url, setBaseUri);
PHP_METHOD(Phalcon_Mvc_Url, setStaticBaseUri);
PHP_METHOD(Phalcon_Mvc_Url, getBaseUri);
PHP_METHOD(Phalcon_Mvc_Url, getStaticBaseUri);
PHP_METHOD(Phalcon_Mvc_Url, setBasePath);
PHP_METHOD(Phalcon_Mvc_Url, getBasePath);
PHP_METHOD(Phalcon_Mvc_Url, get);
PHP_METHOD(Phalcon_Mvc_Url, getStatic);
PHP_METHOD(Phalcon_Mvc_Url, path);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_setstaticbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, staticBaseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_getstatic, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_url_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Url, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, setBaseUri, arginfo_phalcon_mvc_urlinterface_setbaseuri, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, setStaticBaseUri, arginfo_phalcon_mvc_url_setstaticbaseuri, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getBaseUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getStaticBaseUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, setBasePath, arginfo_phalcon_mvc_urlinterface_setbasepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getBasePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, get, arginfo_phalcon_mvc_urlinterface_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getStatic, arginfo_phalcon_mvc_url_getstatic, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, path, arginfo_phalcon_mvc_urlinterface_path, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_url_exception_ce, 0);
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
 * Sets a prefix for all the URIs to be generated
 *
 *<code>
 *	$url->setBaseUri('/invo/');
 *	$url->setBaseUri('/invo/index.php/');
 *</code>
 *
 * @param string $baseUri
 * @return Phalcon\Mvc\Url
 */
PHP_METHOD(Phalcon_Mvc_Url, setBaseUri){

	zval *base_uri, *static_base_uri;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &base_uri);
	
	phalcon_update_property_this(this_ptr, SL("_baseUri"), base_uri TSRMLS_CC);
	
	PHALCON_OBS_VAR(static_base_uri);
	phalcon_read_property_this(&static_base_uri, this_ptr, SL("_staticBaseUri"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(static_base_uri) == IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_staticBaseUri"), base_uri TSRMLS_CC);
	}
	
	RETURN_THIS();
}

/**
 * Sets a prefix for all static URLs generated
 *
 *<code>
 *	$url->setStaticBaseUri('/invo/');
 *</code>
 *
 * @param string $staticBaseUri
 * @return Phalcon\Mvc\Url
 */
PHP_METHOD(Phalcon_Mvc_Url, setStaticBaseUri){

	zval *static_base_uri;

	phalcon_fetch_params(0, 1, 0, &static_base_uri);
	
	phalcon_update_property_this(this_ptr, SL("_staticBaseUri"), static_base_uri TSRMLS_CC);
	RETURN_THISW();
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
	phalcon_read_property_this(&base_uri, this_ptr, SL("_baseUri"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(base_uri) == IS_NULL) {
	
		PHALCON_INIT_VAR(slash);
		ZVAL_STRING(slash, "/", 1);
		_SERVER = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
		if (phalcon_array_isset_string_fetch(&php_self, _SERVER, SS("PHP_SELF"))) {
			PHALCON_INIT_VAR(uri);
			phalcon_get_uri(uri, php_self);
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
 * Returns the prefix for all the generated static urls. By default /
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, getStaticBaseUri){

	zval *static_base_uri;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(static_base_uri);
	phalcon_read_property_this(&static_base_uri, this_ptr, SL("_staticBaseUri"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(static_base_uri) != IS_NULL) {
		RETURN_CCTOR(static_base_uri);
	}
	
	PHALCON_RETURN_CALL_METHOD(this_ptr, "getbaseuri");
	RETURN_MM();
}

/**
 * Sets a base path for all the generated paths
 *
 *<code>
 *	$url->setBasePath('/var/www/htdocs/');
 *</code>
 *
 * @param string $basePath
 * @return Phalcon\Mvc\Url
 */
PHP_METHOD(Phalcon_Mvc_Url, setBasePath){

	zval *base_path;

	phalcon_fetch_params(0, 1, 0, &base_path);
	
	phalcon_update_property_this(this_ptr, SL("_basePath"), base_path TSRMLS_CC);
	RETURN_THISW();
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
 *<code>
 *
 * //Generate a URL appending the URI to the base URI
 * echo $url->get('products/edit/1');
 *
 * //Generate a URL for a predefined route
 * echo $url->get(array('for' => 'blog-post', 'title' => 'some-cool-stuff', 'year' => '2012'));
 *
 *</code>
 *
 * @param string|array $uri
 * @param array|object args Optional arguments to be appended to the query string
 * @param bool|null $local
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, get){

	zval **uri = NULL, *base_uri = NULL, *router = NULL, *dependency_injector;
	zval *service, *route_name, *route = NULL, *exception_message;
	zval *pattern = NULL, *paths = NULL, *processed_uri, **args = NULL, *query_string;
	zval *matched, *regexp;
	zval **z_local = NULL;
	int local = 1;

	phalcon_fetch_params_ex(0, 3, &uri, &args, &z_local);

	PHALCON_MM_GROW();

	if (!uri) {
		uri = &PHALCON_GLOBAL(z_null);
	}
	else if (z_local && Z_TYPE_PP(z_local) != IS_NULL) {
		if (!zend_is_true(*z_local)) {
			local = 0;
		}
	}
	else if (Z_TYPE_PP(uri) == IS_STRING && strstr(Z_STRVAL_PP(uri), ":")) {
		PHALCON_INIT_VAR(matched);
		PHALCON_INIT_VAR(regexp);
		ZVAL_STRING(regexp, "/^[^:\\/?#]++:/", 1);
		RETURN_MM_ON_FAILURE(phalcon_preg_match(matched, regexp, *uri, NULL TSRMLS_CC));
		if (zend_is_true(matched)) {
			local = 0;
		}
	}

	PHALCON_CALL_METHOD(&base_uri, this_ptr, "getbaseuri");

	if (Z_TYPE_PP(uri) == IS_ARRAY) {
		if (!phalcon_array_isset_string_fetch(&route_name, *uri, SS("for"))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_url_exception_ce, "It's necessary to define the route name with the parameter \"for\"");
			return;
		}
	
		router = phalcon_fetch_nproperty_this(this_ptr, SL("_router"), PH_NOISY TSRMLS_CC);
	
		/** 
		 * Check if the router has not previously set
		 */
		if (Z_TYPE_P(router) != IS_OBJECT) {
			dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
			if (!zend_is_true(dependency_injector)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_url_exception_ce, "A dependency injector container is required to obtain the \"url\" service");
				return;
			}
	
			PHALCON_INIT_VAR(service);
			PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_router);
	
			router = NULL;
			PHALCON_CALL_METHOD(&router, dependency_injector, "getshared", service);
			PHALCON_VERIFY_INTERFACE(router, phalcon_mvc_routerinterface_ce);
			phalcon_update_property_this(this_ptr, SL("_router"), router TSRMLS_CC);
		}
	
		/** 
		 * Every route is uniquely identified by a name
		 */
		PHALCON_CALL_METHOD(&route, router, "getroutebyname", route_name);
		if (Z_TYPE_P(route) != IS_OBJECT) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Cannot obtain a route using the name \"", route_name, "\"");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_url_exception_ce, exception_message);
			return;
		}

		PHALCON_CALL_METHOD(&pattern, route, "getpattern");
	
		/** 
		 * Return the reversed paths
		 */
		PHALCON_CALL_METHOD(&paths, route, "getreversedpaths");

		/** 
		 * Replace the patterns by its variables
		 */
		PHALCON_INIT_VAR(processed_uri);
		phalcon_replace_paths(processed_uri, pattern, paths, *uri TSRMLS_CC);

		PHALCON_CONCAT_VV(return_value, base_uri, processed_uri);
	}
	else {
		if (local) {
			PHALCON_CONCAT_VV(return_value, base_uri, *uri);
		}
		else {
			ZVAL_ZVAL(return_value, *uri, 1, 0);
		}
	}
	
	if (args) {
		PHALCON_INIT_VAR(query_string);
		phalcon_http_build_query(query_string, *args, "&" TSRMLS_CC);
		if (Z_TYPE_P(query_string) == IS_STRING && Z_STRLEN_P(query_string)) {
			if (phalcon_memnstr_str(return_value, "?", 1)) {
				PHALCON_SCONCAT_SV(return_value, "&", query_string);
			}
			else {
				PHALCON_SCONCAT_SV(return_value, "?", query_string);
			}
		}
	}

	RETURN_MM();
}

/**
 * Generates a URL for a static resource
 *
 * @param string|array $uri
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, getStatic){

	zval **uri = NULL, *static_base_uri, *base_uri = NULL;
	zval *matched, *pattern;

	phalcon_fetch_params_ex(0, 1, &uri);

	PHALCON_MM_GROW();

	if (!uri) {
		uri = &PHALCON_GLOBAL(z_null);
	}
	else {
		PHALCON_ENSURE_IS_STRING(uri);

		if (strstr(Z_STRVAL_PP(uri), "://")) {
			PHALCON_INIT_VAR(matched);
			PHALCON_INIT_VAR(pattern);
			ZVAL_STRING(pattern, "/^[^:\\/?#]++:/", 1);
			RETURN_MM_ON_FAILURE(phalcon_preg_match(matched, pattern, *uri, NULL TSRMLS_CC));
			if (zend_is_true(matched)) {
				RETURN_CTOR(*uri);
			}
		}
	}
	
	static_base_uri = phalcon_fetch_nproperty_this(this_ptr, SL("_staticBaseUri"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(static_base_uri) != IS_NULL) {
		PHALCON_CONCAT_VV(return_value, static_base_uri, *uri);
		RETURN_MM();
	}
	
	PHALCON_CALL_METHOD(&base_uri, this_ptr, "getbaseuri");
	PHALCON_CONCAT_VV(return_value, base_uri, *uri);
	
	RETURN_MM();
}

/**
 * Generates a local path
 *
 * @param string $path
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, path){

	zval *path = NULL, *base_path;

	phalcon_fetch_params(0, 0, 1, &path);
	
	if (!path) {
		path = PHALCON_GLOBAL(z_null);
	}
	
	base_path = phalcon_fetch_nproperty_this(this_ptr, SL("_basePath"), PH_NOISY TSRMLS_CC);
	PHALCON_CONCAT_VV(return_value, base_path, path);
}
