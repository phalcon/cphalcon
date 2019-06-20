
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "phalcon/url/utils.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Url
 *
 * This components helps in the generation of: URIs, URLs and Paths
 *
 *<code>
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
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Url) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Url, phalcon, url, phalcon_url_method_entry, 0);

	/**
	 * @var null | string
	 */
	zend_declare_property_null(phalcon_url_ce, SL("baseUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var null | string
	 */
	zend_declare_property_null(phalcon_url_ce, SL("basePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var <DiInterface>
	 */
	zend_declare_property_null(phalcon_url_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_url_ce, SL("router"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var null | string
	 */
	zend_declare_property_null(phalcon_url_ce, SL("staticBaseUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_url_ce TSRMLS_CC, 1, phalcon_urlinterface_ce);
	zend_class_implements(phalcon_url_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Generates a URL
 *
 *<code>
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
 *     "https://phalconphp.com/",
 *     null,
 *     false
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Url, get) {

	unsigned char _24$$14, _26$$14, _31$$16;
	zval strUri, _19$$14;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local, _0$$3, _1$$3, _22$$14, _23$$14, _25$$14, _29$$16, _30$$16, _32$$19;
	zval *uri = NULL, uri_sub, *args = NULL, args_sub, *local_param = NULL, *baseUri = NULL, baseUri_sub, __$null, router, container, routeName, route, queryString, _2$$4, _3$$4, _4$$4, _5$$4, _6$$9, _14$$9, _17$$9, _18$$9, _7$$11, _12$$11, _13$$11, _8$$12, _9$$12, _11$$12, _15$$13, _16$$13, _20$$14, _21$$14, _27$$15, _28$$15, _33$$20, _34$$20, _35$$21, _36$$22;
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
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&strUri);
	ZVAL_UNDEF(&_19$$14);

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
			_1$$3 = zephir_memnstr_str(uri, SL("//"), "phalcon/Url.zep", 102);
			if (!(_1$$3)) {
				_1$$3 = zephir_memnstr_str(uri, SL(":"), "phalcon/Url.zep", 102);
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
			zephir_preg_match(&_4$$4, &_5$$4, uri, &_2$$4, 0, 0 , 0  TSRMLS_CC);
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_url_exception_ce, "It's necessary to define the route name with the parameter 'for'", "phalcon/Url.zep", 121);
			return;
		}
		zephir_read_property(&_6$$9, this_ptr, SL("router"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&router, &_6$$9);
		if (Z_TYPE_P(&router) != IS_OBJECT) {
			zephir_read_property(&_7$$11, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&container, &_7$$11);
			if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
				ZEPHIR_INIT_VAR(&_8$$12);
				object_init_ex(&_8$$12, phalcon_url_exception_ce);
				ZEPHIR_INIT_VAR(&_11$$12);
				ZVAL_STRING(&_11$$12, "the 'router' service");
				ZEPHIR_CALL_CE_STATIC(&_9$$12, phalcon_url_exception_ce, "containerservicenotfound", &_10, 0, &_11$$12);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_8$$12, "__construct", NULL, 1, &_9$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_8$$12, "phalcon/Url.zep", 137 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_13$$11);
			ZVAL_STRING(&_13$$11, "router");
			ZEPHIR_CALL_METHOD(&_12$$11, &container, "getshared", NULL, 0, &_13$$11);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&router, &_12$$11);
			zephir_update_property_zval(this_ptr, SL("router"), &router);
		}
		ZEPHIR_CALL_METHOD(&_14$$9, &router, "getroutebyname", NULL, 0, &routeName);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&route, &_14$$9);
		if (UNEXPECTED(Z_TYPE_P(&route) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_15$$13);
			object_init_ex(&_15$$13, phalcon_url_exception_ce);
			ZEPHIR_INIT_VAR(&_16$$13);
			ZEPHIR_CONCAT_SVS(&_16$$13, "Cannot obtain a route using the name '", &routeName, "'");
			ZEPHIR_CALL_METHOD(NULL, &_15$$13, "__construct", NULL, 1, &_16$$13);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_15$$13, "phalcon/Url.zep", 152 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_17$$9);
		ZEPHIR_CALL_METHOD(&_14$$9, &route, "getpattern", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_18$$9, &route, "getreversedpaths", NULL, 0);
		zephir_check_call_status();
		phalcon_replace_paths(&_17$$9, &_14$$9, &_18$$9, uri TSRMLS_CC);
		ZEPHIR_CPY_WRT(uri, &_17$$9);
	}
	if (local) {
		zephir_get_strval(&_19$$14, uri);
		ZEPHIR_CPY_WRT(&strUri, &_19$$14);
		ZVAL_LONG(&_20$$14, -1);
		ZEPHIR_INIT_VAR(&_21$$14);
		zephir_substr(&_21$$14, baseUri, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		_22$$14 = ZEPHIR_IS_STRING(&_21$$14, "/");
		if (_22$$14) {
			_22$$14 = zephir_fast_strlen_ev(&strUri) > 2;
		}
		_23$$14 = _22$$14;
		if (_23$$14) {
			_24$$14 = ZEPHIR_STRING_OFFSET(&strUri, 0);
			_23$$14 = _24$$14 == '/';
		}
		_25$$14 = _23$$14;
		if (_25$$14) {
			_26$$14 = ZEPHIR_STRING_OFFSET(&strUri, 1);
			_25$$14 = _26$$14 != '/';
		}
		if (_25$$14) {
			ZVAL_LONG(&_27$$15, 1);
			ZEPHIR_INIT_VAR(&_28$$15);
			zephir_substr(&_28$$15, &strUri, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_NVAR(uri);
			ZEPHIR_CONCAT_VV(uri, baseUri, &_28$$15);
		} else {
			_29$$16 = ZEPHIR_IS_STRING(baseUri, "/");
			if (_29$$16) {
				_29$$16 = zephir_fast_strlen_ev(&strUri) == 1;
			}
			_30$$16 = _29$$16;
			if (_30$$16) {
				_31$$16 = ZEPHIR_STRING_OFFSET(&strUri, 0);
				_30$$16 = _31$$16 == '/';
			}
			if (_30$$16) {
				ZEPHIR_CPY_WRT(uri, baseUri);
			} else {
				ZEPHIR_INIT_NVAR(uri);
				ZEPHIR_CONCAT_VV(uri, baseUri, &strUri);
			}
		}
	}
	if (zephir_is_true(args)) {
		ZEPHIR_CALL_FUNCTION(&queryString, "http_build_query", NULL, 0, args);
		zephir_check_call_status();
		_32$$19 = Z_TYPE_P(&queryString) == IS_STRING;
		if (_32$$19) {
			_32$$19 = ((zephir_fast_strlen_ev(&queryString)) ? 1 : 0);
		}
		if (_32$$19) {
			ZEPHIR_INIT_VAR(&_33$$20);
			ZVAL_STRING(&_33$$20, "?");
			ZEPHIR_INIT_VAR(&_34$$20);
			zephir_fast_strpos(&_34$$20, uri, &_33$$20, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&_34$$20)) {
				ZEPHIR_INIT_VAR(&_35$$21);
				ZEPHIR_CONCAT_SV(&_35$$21, "&", &queryString);
				zephir_concat_self(uri, &_35$$21 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(&_36$$22);
				ZEPHIR_CONCAT_SV(&_36$$22, "?", &queryString);
				zephir_concat_self(uri, &_36$$22 TSRMLS_CC);
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
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Url, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * Generates a URL for a static resource
 *
 *<code>
 * // Generate a URL for a static resource
 * echo $url->getStatic("img/logo.png");
 *
 * // Generate a URL for a static predefined route
 * echo $url->getStatic(
 *     [
 *         "for" => "logo-cdn",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Url, getStatic) {

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
 *<code>
 * $url->setBasePath("/var/www/htdocs/");
 *</code>
 */
PHP_METHOD(Phalcon_Url, setBasePath) {

	zval *basePath_param = NULL;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath_param);

	if (UNEXPECTED(Z_TYPE_P(basePath_param) != IS_STRING && Z_TYPE_P(basePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'basePath' must be of the type string") TSRMLS_CC);
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
 *<code>
 * $url->setBaseUri("/invo/");
 *
 * $url->setBaseUri("/invo/index.php/");
 *</code>
 */
PHP_METHOD(Phalcon_Url, setBaseUri) {

	zval *baseUri_param = NULL, _0;
	zval baseUri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&baseUri);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &baseUri_param);

	if (UNEXPECTED(Z_TYPE_P(baseUri_param) != IS_STRING && Z_TYPE_P(baseUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'baseUri' must be of the type string") TSRMLS_CC);
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
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Url, setDI) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

/**
 * Sets a prefix for all static URLs generated
 *
 *<code>
 * $url->setStaticBaseUri("/invo/");
 *</code>
 */
PHP_METHOD(Phalcon_Url, setStaticBaseUri) {

	zval *staticBaseUri_param = NULL;
	zval staticBaseUri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&staticBaseUri);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &staticBaseUri_param);

	if (UNEXPECTED(Z_TYPE_P(staticBaseUri_param) != IS_STRING && Z_TYPE_P(staticBaseUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'staticBaseUri' must be of the type string") TSRMLS_CC);
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

