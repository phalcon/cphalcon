
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "phalcon/mvc/url/utils.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Url) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, Url, phalcon, mvc_url, phalcon_mvc_url_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_url_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_url_ce, SL("_baseUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_url_ce, SL("_staticBaseUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_url_ce, SL("_basePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_url_ce, SL("_router"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_url_ce TSRMLS_CC, 1, phalcon_mvc_urlinterface_ce);
	zend_class_implements(phalcon_mvc_url_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Url, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	if (!(zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Url, getDI) {


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
 * @param string baseUri
 * @return Phalcon\Mvc\Url
 */
PHP_METHOD(Phalcon_Mvc_Url, setBaseUri) {

	zval *baseUri_param = NULL, *_0;
	zval *baseUri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &baseUri_param);

	if (unlikely(Z_TYPE_P(baseUri_param) != IS_STRING && Z_TYPE_P(baseUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'baseUri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(baseUri_param) == IS_STRING)) {
		zephir_get_strval(baseUri, baseUri_param);
	} else {
		ZEPHIR_INIT_VAR(baseUri);
		ZVAL_EMPTY_STRING(baseUri);
	}


	zephir_update_property_this(this_ptr, SL("_baseUri"), baseUri TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_staticBaseUri"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_staticBaseUri"), baseUri TSRMLS_CC);
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
 * @param string staticBaseUri
 * @return Phalcon\Mvc\Url
 */
PHP_METHOD(Phalcon_Mvc_Url, setStaticBaseUri) {

	zval *staticBaseUri_param = NULL;
	zval *staticBaseUri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &staticBaseUri_param);

	if (unlikely(Z_TYPE_P(staticBaseUri_param) != IS_STRING && Z_TYPE_P(staticBaseUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'staticBaseUri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(staticBaseUri_param) == IS_STRING)) {
		zephir_get_strval(staticBaseUri, staticBaseUri_param);
	} else {
		ZEPHIR_INIT_VAR(staticBaseUri);
		ZVAL_EMPTY_STRING(staticBaseUri);
	}


	zephir_update_property_this(this_ptr, SL("_staticBaseUri"), staticBaseUri TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the prefix for all the generated urls. By default /
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, getBaseUri) {

	zval *baseUri = NULL, *phpSelf, *uri = NULL, *_SERVER;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(baseUri);
	zephir_read_property_this(&baseUri, this_ptr, SL("_baseUri"), PH_NOISY_CC);
	if (Z_TYPE_P(baseUri) == IS_NULL) {
		ZEPHIR_OBS_VAR(phpSelf);
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		if (zephir_array_isset_string_fetch(&phpSelf, _SERVER, SS("PHP_SELF"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(uri);
			phalcon_get_uri(uri, phpSelf);
		} else {
			ZEPHIR_INIT_NVAR(uri);
			ZVAL_NULL(uri);
		}
		ZEPHIR_INIT_NVAR(baseUri);
		if (!(zephir_is_true(uri))) {
			ZVAL_STRING(baseUri, "/", 1);
		} else {
			ZEPHIR_CONCAT_SVS(baseUri, "/", uri, "/");
		}
		zephir_update_property_this(this_ptr, SL("_baseUri"), baseUri TSRMLS_CC);
	}
	RETURN_CCTOR(baseUri);

}

/**
 * Returns the prefix for all the generated static urls. By default /
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, getStaticBaseUri) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *staticBaseUri;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(staticBaseUri);
	zephir_read_property_this(&staticBaseUri, this_ptr, SL("_staticBaseUri"), PH_NOISY_CC);
	if (Z_TYPE_P(staticBaseUri) != IS_NULL) {
		RETURN_CCTOR(staticBaseUri);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbaseuri", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets a base path for all the generated paths
 *
 *<code>
 *	$url->setBasePath('/var/www/htdocs/');
 *</code>
 *
 * @param string basePath
 * @return Phalcon\Mvc\Url
 */
PHP_METHOD(Phalcon_Mvc_Url, setBasePath) {

	zval *basePath_param = NULL;
	zval *basePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath_param);

	if (unlikely(Z_TYPE_P(basePath_param) != IS_STRING && Z_TYPE_P(basePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'basePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(basePath_param) == IS_STRING)) {
		zephir_get_strval(basePath, basePath_param);
	} else {
		ZEPHIR_INIT_VAR(basePath);
		ZVAL_EMPTY_STRING(basePath);
	}


	zephir_update_property_this(this_ptr, SL("_basePath"), basePath TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the base path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, getBasePath) {


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
 * @param string|array uri
 * @param array|object args Optional arguments to be appended to the query string
 * @param bool $local
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_9 = NULL;
	zend_bool local, _0;
	zval *uri = NULL, *args = NULL, *local_param = NULL, *baseUri = NULL, *router = NULL, *dependencyInjector = NULL, *routeName, *route = NULL, *matched = NULL, *queryString = NULL, _1 = zval_used_for_init, *_2 = NULL, *_4 = NULL, *_6, *_7 = NULL, *_8 = NULL, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &uri, &args, &local_param);

	if (!uri) {
		ZEPHIR_CPY_WRT(uri, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(uri);
	}
	if (!args) {
		args = ZEPHIR_GLOBAL(global_null);
	}
	if (!local_param) {
		local = 0;
	} else {
		local = zephir_get_boolval(local_param);
	}


	if (local == 0) {
		_0 = Z_TYPE_P(uri) == IS_STRING;
		if (_0) {
			ZEPHIR_SINIT_VAR(_1);
			ZVAL_STRING(&_1, ":", 0);
			ZEPHIR_CALL_FUNCTION(&_2, "strstr", &_3, uri, &_1);
			zephir_check_call_status();
			_0 = zephir_is_true(_2);
		}
		if (_0) {
			ZEPHIR_INIT_VAR(_4);
			ZVAL_STRING(_4, "/^[^:\\/?#]++:/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&matched, "preg_match", &_5, _4, uri);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
			if (zephir_is_true(matched)) {
				local = 0;
			} else {
				local = 1;
			}
		} else {
			local = 1;
		}
	}
	ZEPHIR_CALL_METHOD(&baseUri, this_ptr, "getbaseuri", NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(uri) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(routeName);
		if (!(zephir_array_isset_string_fetch(&routeName, uri, SS("for"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_url_exception_ce, "It's necessary to define the route name with the parameter 'for'", "phalcon/mvc/url.zep", 220);
			return;
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_router"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(router, _6);
		if (Z_TYPE_P(router) != IS_OBJECT) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(dependencyInjector, _6);
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_url_exception_ce, "A dependency injector container is required to obtain the 'router' service", "phalcon/mvc/url.zep", 232);
				return;
			}
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "router", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_2, dependencyInjector, "getshared", NULL, _4);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(router, _2);
			zephir_update_property_this(this_ptr, SL("_router"), router TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_2, router, "getroutebyname", NULL, routeName);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(route, _2);
		if (Z_TYPE_P(route) != IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_4);
			object_init_ex(_4, phalcon_mvc_url_exception_ce);
			ZEPHIR_INIT_VAR(_7);
			ZEPHIR_CONCAT_SVS(_7, "Cannot obtain a route using the name '", routeName, "'");
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, _7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4, "phalcon/mvc/url.zep", 244 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(_4);
		ZEPHIR_CALL_METHOD(&_2, route, "getpattern", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_8, route, "getreversedpaths", NULL);
		zephir_check_call_status();
		phalcon_replace_paths(_4, _2, _8, uri TSRMLS_CC);
		ZEPHIR_CPY_WRT(uri, _4);
	}
	if (local) {
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_VV(_7, baseUri, uri);
		ZEPHIR_CPY_WRT(uri, _7);
	}
	if (zephir_is_true(args)) {
		ZEPHIR_CALL_FUNCTION(&queryString, "http_build_query", &_9, args);
		zephir_check_call_status();
		_0 = Z_TYPE_P(queryString) == IS_STRING;
		if (_0) {
			_0 = (zephir_fast_strlen_ev(queryString)) ? 1 : 0;
		}
		if (_0) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "?", 0);
			ZEPHIR_INIT_NVAR(_4);
			zephir_fast_strpos(_4, queryString, &_1, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(_4)) {
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_SV(_7, "&", queryString);
				zephir_concat_self(&uri, _7 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(_10);
				ZEPHIR_CONCAT_SV(_10, "?", queryString);
				zephir_concat_self(&uri, _10 TSRMLS_CC);
			}
		}
	}
	RETVAL_ZVAL(uri, 1, 0);
	RETURN_MM();

}

/**
 * Generates a URL for a static resource
 *
 * @param string|array uri
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, getStatic) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getstaticbaseuri", NULL);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, _0, uri);
	RETURN_MM();

}

/**
 * Generates a local path
 *
 * @param string path
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, path) {

	zval *path = NULL, *_0;

	zephir_fetch_params(0, 0, 1, &path);

	if (!path) {
		path = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_basePath"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VV(return_value, _0, path);
	return;

}

