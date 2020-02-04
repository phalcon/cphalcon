
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "phalcon/url/utils.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This components helps in the generation of: URIs, URLs and Paths
 *
 *```php
 * // Generate a URL appending the URI to the base URI
 * echo $url->get("products/edit/1");
 *
 * // Generate a URL for a predefined route
 * echo $url->get(
 *     [
 *         "for"   => "blog-post",
 *         "title" => "some-cool-stuff",
 *         "year"  => "2012",
 *     ]
 * );
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Url) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon, Url, phalcon, url, phalcon_di_abstractinjectionaware_ce, phalcon_url_method_entry, 0);

	/**
	 * @var null | string
	 */
	zend_declare_property_null(phalcon_url_ce, SL("baseUri"), ZEND_ACC_PROTECTED);

	/**
	 * @var null | string
	 */
	zend_declare_property_null(phalcon_url_ce, SL("basePath"), ZEND_ACC_PROTECTED);

	/**
	 * @var RouterInterface | null
	 */
	zend_declare_property_null(phalcon_url_ce, SL("router"), ZEND_ACC_PROTECTED);

	/**
	 * @var null | string
	 */
	zend_declare_property_null(phalcon_url_ce, SL("staticBaseUri"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_url_ce, 1, phalcon_url_urlinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Url, __construct) {

	zval *router = NULL, router_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&router_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params_without_memory_grow(0, 1, &router);

	if (!router) {
		router = &router_sub;
		router = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("router"), router);

}

/**
 * Generates a URL
 *
 *```php
 * // Generate a URL appending the URI to the base URI
 * echo $url->get("products/edit/1");
 *
 * // Generate a URL for a predefined route
 * echo $url->get(
 *     [
 *         "for"   => "blog-post",
 *         "title" => "some-cool-stuff",
 *         "year"  => "2015",
 *     ]
 * );
 *
 * // Generate a URL with GET arguments (/show/products?id=1&name=Carrots)
 * echo $url->get(
 *     "show/products",
 *     [
 *         "id"   => 1,
 *         "name" => "Carrots",
 *     ]
 * );
 *
 * // Generate an absolute URL by setting the third parameter as false.
 * echo $url->get(
 *     "https://phalcon.io/",
 *     null,
 *     false
 * );
 *```
 *
 * @param array|string uri = [
 *     'for' => '',
 * ]
 */
PHP_METHOD(Phalcon_Url, get) {

	zval strUri, _23$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local, _0$$3, _1$$3, _27$$16;
	zval *uri = NULL, uri_sub, *args = NULL, args_sub, *local_param = NULL, *baseUri = NULL, baseUri_sub, __$null, router, container, routeName, route, queryString, _2$$4, _3$$4, _4$$4, _5$$4, _6$$9, _18$$9, _21$$9, _22$$9, _7$$11, _12$$11, _13$$11, _17$$11, _8$$12, _9$$12, _11$$12, _14$$13, _15$$13, _16$$13, _19$$14, _20$$14, _24$$15, _25$$15, _26$$15, _28$$17, _29$$17, _30$$18, _31$$19;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&args_sub);
	ZVAL_UNDEF(&baseUri_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&queryString);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_29$$17);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&strUri);
	ZVAL_UNDEF(&_23$$15);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &uri, &args, &local_param, &baseUri);

	if (!uri) {
		uri = &uri_sub;
		ZEPHIR_CPY_WRT(uri, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(uri);
	}
	if (!args) {
		args = &args_sub;
		args = &__$null;
	}
	if (!local_param) {
		local = 0;
	} else {
		local = zephir_get_boolval(local_param);
	}
	if (!baseUri) {
		baseUri = &baseUri_sub;
		ZEPHIR_CPY_WRT(baseUri, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(baseUri);
	}


	if (local == 0) {
		_0$$3 = Z_TYPE_P(uri) == IS_STRING;
		if (_0$$3) {
			_1$$3 = zephir_memnstr_str(uri, SL("//"), "phalcon/Url.zep", 107);
			if (!(_1$$3)) {
				_1$$3 = zephir_memnstr_str(uri, SL(":"), "phalcon/Url.zep", 107);
			}
			_0$$3 = _1$$3;
		}
		if (_0$$3) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "#^((//)|([a-z0-9]+://)|([a-z0-9]+:))#i");
			ZEPHIR_INIT_VAR(&_4$$4);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "#^((//)|([a-z0-9]+://)|([a-z0-9]+:))#i");
			zephir_preg_match(&_4$$4, &_5$$4, uri, &_2$$4, 0, 0 , 0 );
			if (zephir_is_true(&_4$$4)) {
				local = 0;
			} else {
				local = 1;
			}
		} else {
			local = 1;
		}
	}
	if (Z_TYPE_P(baseUri) != IS_STRING) {
		ZEPHIR_CALL_METHOD(baseUri, this_ptr, "getbaseuri", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(uri) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&routeName);
		if (UNEXPECTED(!(zephir_array_isset_string_fetch(&routeName, uri, SL("for"), 0)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_url_exception_ce, "It's necessary to define the route name with the parameter 'for'", "phalcon/Url.zep", 126);
			return;
		}
		zephir_read_property(&_6$$9, this_ptr, SL("router"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&router, &_6$$9);
		if (UNEXPECTED(!zephir_is_true(&router))) {
			zephir_read_property(&_7$$11, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&container, &_7$$11);
			if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
				ZEPHIR_INIT_VAR(&_8$$12);
				object_init_ex(&_8$$12, phalcon_url_exception_ce);
				ZEPHIR_INIT_VAR(&_11$$12);
				ZVAL_STRING(&_11$$12, "the 'router' service");
				ZEPHIR_CALL_CE_STATIC(&_9$$12, phalcon_url_exception_ce, "containerservicenotfound", &_10, 0, &_11$$12);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_8$$12, "__construct", NULL, 8, &_9$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_8$$12, "phalcon/Url.zep", 142);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_13$$11);
			ZVAL_STRING(&_13$$11, "router");
			ZEPHIR_CALL_METHOD(&_12$$11, &container, "has", NULL, 0, &_13$$11);
			zephir_check_call_status();
			if (UNEXPECTED(!zephir_is_true(&_12$$11))) {
				ZEPHIR_INIT_VAR(&_14$$13);
				object_init_ex(&_14$$13, phalcon_url_exception_ce);
				ZEPHIR_INIT_VAR(&_16$$13);
				ZVAL_STRING(&_16$$13, "the 'router' service");
				ZEPHIR_CALL_CE_STATIC(&_15$$13, phalcon_url_exception_ce, "containerservicenotfound", &_10, 0, &_16$$13);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_14$$13, "__construct", NULL, 8, &_15$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_14$$13, "phalcon/Url.zep", 150);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_13$$11);
			ZVAL_STRING(&_13$$11, "router");
			ZEPHIR_CALL_METHOD(&_17$$11, &container, "getshared", NULL, 0, &_13$$11);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&router, &_17$$11);
			zephir_update_property_zval(this_ptr, SL("router"), &router);
		}
		ZEPHIR_CALL_METHOD(&_18$$9, &router, "getroutebyname", NULL, 0, &routeName);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&route, &_18$$9);
		if (UNEXPECTED(Z_TYPE_P(&route) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_19$$14);
			object_init_ex(&_19$$14, phalcon_url_exception_ce);
			ZEPHIR_INIT_VAR(&_20$$14);
			ZEPHIR_CONCAT_SVS(&_20$$14, "Cannot obtain a route using the name '", &routeName, "'");
			ZEPHIR_CALL_METHOD(NULL, &_19$$14, "__construct", NULL, 8, &_20$$14);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_19$$14, "phalcon/Url.zep", 165);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_21$$9);
		ZEPHIR_CALL_METHOD(&_18$$9, &route, "getpattern", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_22$$9, &route, "getreversedpaths", NULL, 0);
		zephir_check_call_status();
		phalcon_replace_paths(&_21$$9, &_18$$9, &_22$$9, uri TSRMLS_CC);
		ZEPHIR_CPY_WRT(uri, &_21$$9);
	}
	if (local) {
		zephir_get_strval(&_23$$15, uri);
		ZEPHIR_CPY_WRT(&strUri, &_23$$15);
		ZEPHIR_INIT_VAR(&_24$$15);
		ZEPHIR_CONCAT_VV(&_24$$15, baseUri, &strUri);
		ZEPHIR_INIT_VAR(&_25$$15);
		ZVAL_STRING(&_25$$15, "#(?<!:)//+#");
		ZEPHIR_INIT_VAR(&_26$$15);
		ZVAL_STRING(&_26$$15, "/");
		ZEPHIR_CALL_FUNCTION(uri, "preg_replace", NULL, 49, &_25$$15, &_26$$15, &_24$$15);
		zephir_check_call_status();
	}
	if (zephir_is_true(args)) {
		ZEPHIR_CALL_FUNCTION(&queryString, "http_build_query", NULL, 0, args);
		zephir_check_call_status();
		_27$$16 = Z_TYPE_P(&queryString) == IS_STRING;
		if (_27$$16) {
			_27$$16 = ((zephir_fast_strlen_ev(&queryString)) ? 1 : 0);
		}
		if (_27$$16) {
			ZEPHIR_INIT_VAR(&_28$$17);
			ZVAL_STRING(&_28$$17, "?");
			ZEPHIR_INIT_VAR(&_29$$17);
			zephir_fast_strpos(&_29$$17, uri, &_28$$17, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&_29$$17)) {
				ZEPHIR_INIT_VAR(&_30$$18);
				ZEPHIR_CONCAT_SV(&_30$$18, "&", &queryString);
				zephir_concat_self(uri, &_30$$18);
			} else {
				ZEPHIR_INIT_VAR(&_31$$19);
				ZEPHIR_CONCAT_SV(&_31$$19, "?", &queryString);
				zephir_concat_self(uri, &_31$$19);
			}
		}
	}
	RETVAL_ZVAL(uri, 1, 0);
	RETURN_MM();

}

/**
 * Returns the base path
 */
PHP_METHOD(Phalcon_Url, getBasePath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "basePath");

}

/**
 * Returns the prefix for all the generated urls. By default /
 */
PHP_METHOD(Phalcon_Url, getBaseUri) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _SERVER, baseUri, phpSelf, uri, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&baseUri);
	ZVAL_UNDEF(&phpSelf);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	zephir_read_property(&_0, this_ptr, SL("baseUri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&baseUri, &_0);
	if (Z_TYPE_P(&baseUri) == IS_NULL) {
		ZEPHIR_OBS_VAR(&phpSelf);
		if (zephir_array_isset_string_fetch(&phpSelf, &_SERVER, SL("PHP_SELF"), 0)) {
			ZEPHIR_INIT_VAR(&uri);
			phalcon_get_uri(&uri, &phpSelf);
		} else {
			ZEPHIR_INIT_NVAR(&uri);
			ZVAL_NULL(&uri);
		}
		ZEPHIR_INIT_NVAR(&baseUri);
		if (!(zephir_is_true(&uri))) {
			ZVAL_STRING(&baseUri, "/");
		} else {
			ZEPHIR_CONCAT_SVS(&baseUri, "/", &uri, "/");
		}
		zephir_update_property_zval(this_ptr, SL("baseUri"), &baseUri);
	}
	RETURN_CCTOR(&baseUri);

}

/**
 * Generates a URL for a static resource
 *
 *```php
 * // Generate a URL for a static resource
 * echo $url->getStatic("img/logo.png");
 *
 * // Generate a URL for a static predefined route
 * echo $url->getStatic(
 *     [
 *         "for" => "logo-cdn",
 *     ]
 * );
 *```
 *
 * @param array|string uri = [
 *     'for' => ''
 * ]
 */
PHP_METHOD(Phalcon_Url, getStatic) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, uri_sub, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = &uri_sub;
		uri = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getstaticbaseuri", NULL, 0);
	zephir_check_call_status();
	ZVAL_NULL(&_1);
	ZVAL_NULL(&_2);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, uri, &_1, &_2, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the prefix for all the generated static urls. By default /
 */
PHP_METHOD(Phalcon_Url, getStaticBaseUri) {

	zval staticBaseUri, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&staticBaseUri);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("staticBaseUri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&staticBaseUri, &_0);
	if (Z_TYPE_P(&staticBaseUri) != IS_NULL) {
		RETURN_CCTOR(&staticBaseUri);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbaseuri", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets a base path for all the generated paths
 *
 *```php
 * $url->setBasePath("/var/www/htdocs/");
 *```
 */
PHP_METHOD(Phalcon_Url, setBasePath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *basePath_param = NULL;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath_param);

	if (UNEXPECTED(Z_TYPE_P(basePath_param) != IS_STRING && Z_TYPE_P(basePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'basePath' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(basePath_param) == IS_STRING)) {
		zephir_get_strval(&basePath, basePath_param);
	} else {
		ZEPHIR_INIT_VAR(&basePath);
		ZVAL_EMPTY_STRING(&basePath);
	}


	zephir_update_property_zval(this_ptr, SL("basePath"), &basePath);
	RETURN_THIS();

}

/**
 * Sets a prefix for all the URIs to be generated
 *
 *```php
 * $url->setBaseUri("/invo/");
 *
 * $url->setBaseUri("/invo/index.php/");
 *```
 */
PHP_METHOD(Phalcon_Url, setBaseUri) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *baseUri_param = NULL, _0;
	zval baseUri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&baseUri);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &baseUri_param);

	if (UNEXPECTED(Z_TYPE_P(baseUri_param) != IS_STRING && Z_TYPE_P(baseUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'baseUri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(baseUri_param) == IS_STRING)) {
		zephir_get_strval(&baseUri, baseUri_param);
	} else {
		ZEPHIR_INIT_VAR(&baseUri);
		ZVAL_EMPTY_STRING(&baseUri);
	}


	zephir_update_property_zval(this_ptr, SL("baseUri"), &baseUri);
	zephir_read_property(&_0, this_ptr, SL("staticBaseUri"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("staticBaseUri"), &baseUri);
	}
	RETURN_THIS();

}

/**
 * Sets a prefix for all static URLs generated
 *
 *```php
 * $url->setStaticBaseUri("/invo/");
 *```
 */
PHP_METHOD(Phalcon_Url, setStaticBaseUri) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *staticBaseUri_param = NULL;
	zval staticBaseUri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&staticBaseUri);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &staticBaseUri_param);

	if (UNEXPECTED(Z_TYPE_P(staticBaseUri_param) != IS_STRING && Z_TYPE_P(staticBaseUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'staticBaseUri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(staticBaseUri_param) == IS_STRING)) {
		zephir_get_strval(&staticBaseUri, staticBaseUri_param);
	} else {
		ZEPHIR_INIT_VAR(&staticBaseUri);
		ZVAL_EMPTY_STRING(&staticBaseUri);
	}


	zephir_update_property_zval(this_ptr, SL("staticBaseUri"), &staticBaseUri);
	RETURN_THIS();

}

/**
 * Generates a local path
 */
PHP_METHOD(Phalcon_Url, path) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *path_param = NULL, _0;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path_param);

	if (!path_param) {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_STRING(&path, "");
	} else {
		zephir_get_strval(&path, path_param);
	}


	zephir_read_property(&_0, this_ptr, SL("basePath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_0, &path);
	RETURN_MM();

}

