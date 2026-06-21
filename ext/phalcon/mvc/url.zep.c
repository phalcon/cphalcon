
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
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "phalcon/mvc/url/utils.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This component helps in the generation of: URIs, URLs and Paths
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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Url)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Url, phalcon, mvc_url, phalcon_di_abstractinjectionaware_ce, phalcon_mvc_url_method_entry, 0);

	/**
	 * @var null | string
	 */
	zend_declare_property_null(phalcon_mvc_url_ce, SL("basePath"), ZEND_ACC_PROTECTED);
	/**
	 * @var null | string
	 */
	zend_declare_property_null(phalcon_mvc_url_ce, SL("baseUri"), ZEND_ACC_PROTECTED);
	/**
	 * @var RouterInterface | null
	 */
	zend_declare_property_null(phalcon_mvc_url_ce, SL("router"), ZEND_ACC_PROTECTED);
	/**
	 * @var null | string
	 */
	zend_declare_property_null(phalcon_mvc_url_ce, SL("staticBaseUri"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_mvc_url_ce, 1, phalcon_mvc_url_urlinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_Url, __construct)
{
	zval *router = NULL, router_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&router_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(router, phalcon_mvc_routerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(0, 1, &router);
	if (!router) {
		router = &router_sub;
		router = &__$null;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("router"), router);
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
 *
 * // Override existing query string keys instead of appending duplicates.
 * // Without the fifth argument: "http://example.com?page=1&page=5".
 * // With it set to true:        "http://example.com?page=5".
 * echo $url->get(
 *     "http://example.com?page=1",
 *     ["page" => 5],
 *     null,
 *     null,
 *     true
 * );
 *```
 *
 * @param array|string uri = [
 *     'for' => '',
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Url, get)
{
	zval _33$$20;
	zval strUri, _24$$18, _32$$20, _36$$20;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local, replaceArgs, _0$$3, _1$$3, _18$$9, _29$$19, _37$$19;
	zval *uri = NULL, uri_sub, *arguments = NULL, arguments_sub, *local_param = NULL, *baseUri = NULL, baseUri_sub, *replaceArgs_param = NULL, __$null, container, existing, hostname, queryPos, queryString, router, routeName, route, _2$$4, _3$$4, _4$$4, _5$$4, _6$$10, _7$$9, _14$$9, _16$$9, _17$$9, _8$$11, _10$$11, _11$$11, _13$$11, _9$$12, _12$$13, _15$$14, _19$$15, _20$$15, _21$$15, _22$$16, _23$$17, _25$$18, _26$$18, _27$$18, _28$$19, _30$$20, _31$$20, _34$$20, _35$$20, _38$$22, _39$$23;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_UNDEF(&baseUri_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&existing);
	ZVAL_UNDEF(&hostname);
	ZVAL_UNDEF(&queryPos);
	ZVAL_UNDEF(&queryString);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_38$$22);
	ZVAL_UNDEF(&_39$$23);
	ZVAL_UNDEF(&strUri);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_36$$20);
	ZVAL_UNDEF(&_33$$20);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(uri)
		Z_PARAM_ZVAL_OR_NULL(arguments)
		Z_PARAM_BOOL_OR_NULL(local, is_null_true)
		Z_PARAM_ZVAL_OR_NULL(baseUri)
		Z_PARAM_BOOL(replaceArgs)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 5, &uri, &arguments, &local_param, &baseUri, &replaceArgs_param);
	if (!uri) {
		uri = &uri_sub;
		ZEPHIR_CPY_WRT(uri, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(uri);
	}
	if (!arguments) {
		arguments = &arguments_sub;
		ZEPHIR_CPY_WRT(arguments, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(arguments);
	}
	if (!local_param) {
		local = 0;
	} else {
		}
	if (!baseUri) {
		baseUri = &baseUri_sub;
		ZEPHIR_CPY_WRT(baseUri, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(baseUri);
	}
	if (!replaceArgs_param) {
		replaceArgs = 0;
	} else {
		}
	if (local == 0) {
		_0$$3 = Z_TYPE_P(uri) == IS_STRING;
		if (_0$$3) {
			_1$$3 = zephir_memnstr_str(uri, SL("//"), "phalcon/Mvc/Url.zep", 127);
			if (!(_1$$3)) {
				_1$$3 = zephir_memnstr_str(uri, SL(":"), "phalcon/Mvc/Url.zep", 127);
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
		zephir_memory_observe(&routeName);
		if (UNEXPECTED(!(zephir_array_isset_string_fetch(&routeName, uri, SL("for"), 0)))) {
			ZEPHIR_INIT_VAR(&_6$$10);
			object_init_ex(&_6$$10, phalcon_mvc_url_exceptions_missingroutename_ce);
			ZEPHIR_CALL_METHOD(NULL, &_6$$10, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$10, "phalcon/Mvc/Url.zep", 144);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_7$$9, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&router, &_7$$9);
		if (UNEXPECTED(!zephir_is_true(&router))) {
			zephir_read_property(&_8$$11, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&container, &_8$$11);
			if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
				ZEPHIR_INIT_VAR(&_9$$12);
				object_init_ex(&_9$$12, phalcon_mvc_url_exceptions_routerserviceunavailable_ce);
				ZEPHIR_CALL_METHOD(NULL, &_9$$12, "__construct", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_9$$12, "phalcon/Mvc/Url.zep", 156);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_11$$11);
			ZVAL_STRING(&_11$$11, "router");
			ZEPHIR_CALL_METHOD(&_10$$11, &container, "has", NULL, 0, &_11$$11);
			zephir_check_call_status();
			if (UNEXPECTED(!zephir_is_true(&_10$$11))) {
				ZEPHIR_INIT_VAR(&_12$$13);
				object_init_ex(&_12$$13, phalcon_mvc_url_exceptions_routerserviceunavailable_ce);
				ZEPHIR_CALL_METHOD(NULL, &_12$$13, "__construct", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_12$$13, "phalcon/Mvc/Url.zep", 160);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_11$$11);
			ZVAL_STRING(&_11$$11, "router");
			ZEPHIR_CALL_METHOD(&_13$$11, &container, "getshared", NULL, 0, &_11$$11);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&router, &_13$$11);
			zephir_update_property_zval(this_ptr, ZEND_STRL("router"), &router);
		}
		ZEPHIR_CALL_METHOD(&_14$$9, &router, "getroutebyname", NULL, 0, &routeName);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&route, &_14$$9);
		if (UNEXPECTED(Z_TYPE_P(&route) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_15$$14);
			object_init_ex(&_15$$14, phalcon_mvc_url_exceptions_routenotfound_ce);
			ZEPHIR_CALL_METHOD(NULL, &_15$$14, "__construct", NULL, 0, &routeName);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_15$$14, "phalcon/Mvc/Url.zep", 173);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_16$$9);
		ZEPHIR_CALL_METHOD(&_14$$9, &route, "getpattern", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_17$$9, &route, "getreversedpaths", NULL, 0);
		zephir_check_call_status();
		phalcon_replace_paths(&_16$$9, &_14$$9, &_17$$9, uri);
		ZEPHIR_CPY_WRT(uri, &_16$$9);
		ZEPHIR_CALL_METHOD(&hostname, &route, "gethostname", NULL, 0);
		zephir_check_call_status();
		_18$$9 = Z_TYPE_P(&hostname) != IS_NULL;
		if (_18$$9) {
			_18$$9 = !ZEPHIR_IS_STRING_IDENTICAL(&hostname, "");
		}
		if (_18$$9) {
			ZVAL_LONG(&_19$$15, 0);
			ZVAL_LONG(&_20$$15, 1);
			ZEPHIR_INIT_VAR(&_21$$15);
			zephir_substr(&_21$$15, uri, 0 , 1 , 0);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_21$$15, "/")) {
				ZEPHIR_INIT_VAR(&_22$$16);
				ZEPHIR_CONCAT_SVSV(&_22$$16, "//", &hostname, "/", uri);
				ZEPHIR_CPY_WRT(uri, &_22$$16);
			} else {
				ZEPHIR_INIT_VAR(&_23$$17);
				ZEPHIR_CONCAT_SVV(&_23$$17, "//", &hostname, uri);
				ZEPHIR_CPY_WRT(uri, &_23$$17);
			}
			local = 0;
		}
	}
	if (local) {
		zephir_cast_to_string(&_24$$18, uri);
		ZEPHIR_CPY_WRT(&strUri, &_24$$18);
		ZEPHIR_INIT_VAR(&_25$$18);
		ZEPHIR_CONCAT_VV(&_25$$18, baseUri, &strUri);
		ZEPHIR_INIT_VAR(&_26$$18);
		ZVAL_STRING(&_26$$18, "#(?<!:)//+#");
		ZEPHIR_INIT_VAR(&_27$$18);
		ZVAL_STRING(&_27$$18, "/");
		ZEPHIR_CALL_FUNCTION(uri, "preg_replace", NULL, 84, &_26$$18, &_27$$18, &_25$$18);
		zephir_check_call_status();
	}
	if (zephir_is_true(arguments)) {
		ZEPHIR_INIT_VAR(&_28$$19);
		ZVAL_STRING(&_28$$19, "?");
		ZEPHIR_INIT_VAR(&queryPos);
		zephir_fast_strpos(&queryPos, uri, &_28$$19, 0 );
		_29$$19 = replaceArgs;
		if (_29$$19) {
			_29$$19 = !ZEPHIR_IS_FALSE_IDENTICAL(&queryPos);
		}
		if (_29$$19) {
			ZEPHIR_INIT_VAR(&existing);
			array_init(&existing);
			ZVAL_LONG(&_30$$20, (zephir_get_numberval(&queryPos) + 1));
			ZEPHIR_INIT_VAR(&_31$$20);
			zephir_substr(&_31$$20, uri, zephir_get_intval(&_30$$20), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			zephir_cast_to_string(&_32$$20, &_31$$20);
			ZEPHIR_MAKE_REF(&existing);
			ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 0, &_32$$20, &existing);
			ZEPHIR_UNREF(&existing);
			zephir_check_call_status();
			zephir_get_arrval(&_33$$20, arguments);
			ZEPHIR_INIT_NVAR(arguments);
			zephir_fast_array_merge(arguments, &existing, &_33$$20);
			ZVAL_LONG(&_34$$20, 0);
			ZEPHIR_INIT_VAR(&_35$$20);
			zephir_substr(&_35$$20, uri, 0 , zephir_get_intval(&queryPos), 0);
			zephir_cast_to_string(&_36$$20, &_35$$20);
			ZEPHIR_CPY_WRT(uri, &_36$$20);
			ZEPHIR_INIT_NVAR(&queryPos);
			ZVAL_BOOL(&queryPos, 0);
		}
		ZEPHIR_CALL_FUNCTION(&queryString, "http_build_query", NULL, 0, arguments);
		zephir_check_call_status();
		_37$$19 = Z_TYPE_P(&queryString) == IS_STRING;
		if (_37$$19) {
			_37$$19 = ((zephir_fast_strlen_ev(&queryString)) ? 1 : 0);
		}
		if (_37$$19) {
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&queryPos)) {
				ZEPHIR_INIT_VAR(&_38$$22);
				ZEPHIR_CONCAT_SV(&_38$$22, "&", &queryString);
				zephir_concat_self(uri, &_38$$22);
			} else {
				ZEPHIR_INIT_VAR(&_39$$23);
				ZEPHIR_CONCAT_SV(&_39$$23, "?", &queryString);
				zephir_concat_self(uri, &_39$$23);
			}
		}
	}
	RETVAL_ZVAL(uri, 1, 0);
	RETURN_MM();
}

/**
 * Returns the base path
 */
PHP_METHOD(Phalcon_Mvc_Url, getBasePath)
{

	RETURN_MEMBER(getThis(), "basePath");
}

/**
 * Returns the prefix for all the generated urls. By default /
 */
PHP_METHOD(Phalcon_Mvc_Url, getBaseUri)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _SERVER, baseUri, phpSelf, uri, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&baseUri);
	ZVAL_UNDEF(&phpSelf);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));

	zephir_read_property(&_0, this_ptr, ZEND_STRL("baseUri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&baseUri, &_0);
	if (Z_TYPE_P(&baseUri) == IS_NULL) {
		zephir_memory_observe(&phpSelf);
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("baseUri"), &baseUri);
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
PHP_METHOD(Phalcon_Mvc_Url, getStatic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, uri_sub, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Phalcon_Mvc_Url, getStaticBaseUri)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("staticBaseUri"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER_TYPED(getThis(), "staticBaseUri", IS_STRING);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbaseuri", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a local path
 */
PHP_METHOD(Phalcon_Mvc_Url, path)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval path_zv, _0;
	zend_string *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!path) {
		ZEPHIR_INIT_VAR(&path_zv);
	} else {
		zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("basePath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_0, &path_zv);
	RETURN_MM();
}

/**
 * Sets a base path for all the generated paths
 *
 *```php
 * $url->setBasePath("/var/www/htdocs/");
 *```
 */
PHP_METHOD(Phalcon_Mvc_Url, setBasePath)
{
	zval basePath_zv;
	zend_string *basePath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(basePath)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&basePath_zv, basePath);
	zephir_update_property_zval(this_ptr, ZEND_STRL("basePath"), &basePath_zv);
	RETURN_THISW();
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
PHP_METHOD(Phalcon_Mvc_Url, setBaseUri)
{
	zval baseUri_zv, _0;
	zend_string *baseUri = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&baseUri_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(baseUri)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&baseUri_zv, baseUri);
	zephir_update_property_zval(this_ptr, ZEND_STRL("baseUri"), &baseUri_zv);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("staticBaseUri"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("staticBaseUri"), &baseUri_zv);
	}
	RETURN_THISW();
}

/**
 * Sets a prefix for all static URLs generated
 *
 *```php
 * $url->setStaticBaseUri("/invo/");
 *```
 */
PHP_METHOD(Phalcon_Mvc_Url, setStaticBaseUri)
{
	zval staticBaseUri_zv;
	zend_string *staticBaseUri = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&staticBaseUri_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(staticBaseUri)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&staticBaseUri_zv, staticBaseUri);
	zephir_update_property_zval(this_ptr, ZEND_STRL("staticBaseUri"), &staticBaseUri_zv);
	RETURN_THISW();
}

