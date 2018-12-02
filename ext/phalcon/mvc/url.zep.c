
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
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "phalcon/mvc/url/utils.h"


/**
 * Phalcon\Mvc\Url
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
 */
PHP_METHOD(Phalcon_Mvc_Url, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Url, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

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
PHP_METHOD(Phalcon_Mvc_Url, setBaseUri) {

	zval *baseUri_param = NULL, *_0;
	zval *baseUri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &baseUri_param);

	if (UNEXPECTED(Z_TYPE_P(baseUri_param) != IS_STRING && Z_TYPE_P(baseUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'baseUri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(baseUri_param) == IS_STRING)) {
		zephir_get_strval(baseUri, baseUri_param);
	} else {
		ZEPHIR_INIT_VAR(baseUri);
		ZVAL_EMPTY_STRING(baseUri);
	}


	zephir_update_property_this(getThis(), SL("_baseUri"), baseUri TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_staticBaseUri"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		zephir_update_property_this(getThis(), SL("_staticBaseUri"), baseUri TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Sets a prefix for all static URLs generated
 *
 *<code>
 * $url->setStaticBaseUri("/invo/");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Url, setStaticBaseUri) {

	zval *staticBaseUri_param = NULL;
	zval *staticBaseUri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &staticBaseUri_param);

	if (UNEXPECTED(Z_TYPE_P(staticBaseUri_param) != IS_STRING && Z_TYPE_P(staticBaseUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'staticBaseUri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(staticBaseUri_param) == IS_STRING)) {
		zephir_get_strval(staticBaseUri, staticBaseUri_param);
	} else {
		ZEPHIR_INIT_VAR(staticBaseUri);
		ZVAL_EMPTY_STRING(staticBaseUri);
	}


	zephir_update_property_this(getThis(), SL("_staticBaseUri"), staticBaseUri TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the prefix for all the generated urls. By default /
 */
PHP_METHOD(Phalcon_Mvc_Url, getBaseUri) {

	zval *_SERVER, *baseUri = NULL, *phpSelf = NULL, *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_OBS_VAR(baseUri);
	zephir_read_property_this(&baseUri, this_ptr, SL("_baseUri"), PH_NOISY_CC);
	if (Z_TYPE_P(baseUri) == IS_NULL) {
		ZEPHIR_OBS_VAR(phpSelf);
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
		zephir_update_property_this(getThis(), SL("_baseUri"), baseUri TSRMLS_CC);
	}
	RETURN_CCTOR(baseUri);

}

/**
 * Returns the prefix for all the generated static urls. By default /
 */
PHP_METHOD(Phalcon_Mvc_Url, getStaticBaseUri) {

	zval *staticBaseUri = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(staticBaseUri);
	zephir_read_property_this(&staticBaseUri, this_ptr, SL("_staticBaseUri"), PH_NOISY_CC);
	if (Z_TYPE_P(staticBaseUri) != IS_NULL) {
		RETURN_CCTOR(staticBaseUri);
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
PHP_METHOD(Phalcon_Mvc_Url, setBasePath) {

	zval *basePath_param = NULL;
	zval *basePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath_param);

	if (UNEXPECTED(Z_TYPE_P(basePath_param) != IS_STRING && Z_TYPE_P(basePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'basePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(basePath_param) == IS_STRING)) {
		zephir_get_strval(basePath, basePath_param);
	} else {
		ZEPHIR_INIT_VAR(basePath);
		ZVAL_EMPTY_STRING(basePath);
	}


	zephir_update_property_this(getThis(), SL("_basePath"), basePath TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the base path
 */
PHP_METHOD(Phalcon_Mvc_Url, getBasePath) {

	

	RETURN_MEMBER(getThis(), "_basePath");

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
PHP_METHOD(Phalcon_Mvc_Url, get) {

	unsigned char _17$$14, _19$$14, _24$$16;
	zend_bool _0$$3, _1$$3, _15$$14, _16$$14, _18$$14, _22$$16, _23$$16, _25$$19;
	zval *strUri = NULL, *_14$$14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, *args = NULL, *local = NULL, *baseUri = NULL, *router = NULL, *dependencyInjector = NULL, *routeName = NULL, *route = NULL, *queryString = NULL, *_2$$4, *_3$$4, _4$$4, *_5$$9, *_9$$9 = NULL, *_12$$9, *_13$$9 = NULL, *_6$$11, *_7$$11 = NULL, *_8$$11, *_10$$13, *_11$$13, _20$$15, *_21$$15, _26$$20, *_27$$20, *_28$$21, *_29$$22;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &uri, &args, &local, &baseUri);

	if (!uri) {
		ZEPHIR_CPY_WRT(uri, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(uri);
	}
	if (!args) {
		args = ZEPHIR_GLOBAL(global_null);
	}
	if (!local) {
		ZEPHIR_CPY_WRT(local, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(local);
	}
	if (!baseUri) {
		ZEPHIR_CPY_WRT(baseUri, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(baseUri);
	}


	if (Z_TYPE_P(local) == IS_NULL) {
		_0$$3 = Z_TYPE_P(uri) == IS_STRING;
		if (_0$$3) {
			_1$$3 = zephir_memnstr_str(uri, SL("//"), "phalcon/mvc/url.zep", 208);
			if (!(_1$$3)) {
				_1$$3 = zephir_memnstr_str(uri, SL(":"), "phalcon/mvc/url.zep", 208);
			}
			_0$$3 = _1$$3;
		}
		if (_0$$3) {
			ZEPHIR_INIT_VAR(_2$$4);
			ZEPHIR_INIT_VAR(_3$$4);
			ZEPHIR_SINIT_VAR(_4$$4);
			ZVAL_STRING(&_4$$4, "#^((//)|([a-z0-9]+://)|([a-z0-9]+:))#i", 0);
			zephir_preg_match(_3$$4, &_4$$4, uri, _2$$4, 0, 0 , 0  TSRMLS_CC);
			ZEPHIR_INIT_NVAR(local);
			if (zephir_is_true(_3$$4)) {
				ZVAL_BOOL(local, 0);
			} else {
				ZVAL_BOOL(local, 1);
			}
		} else {
			ZEPHIR_INIT_NVAR(local);
			ZVAL_BOOL(local, 1);
		}
	}
	if (Z_TYPE_P(baseUri) != IS_STRING) {
		ZEPHIR_CALL_METHOD(&baseUri, this_ptr, "getbaseuri", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(uri) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(routeName);
		if (!(zephir_array_isset_string_fetch(&routeName, uri, SS("for"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_url_exception_ce, "It's necessary to define the route name with the parameter 'for'", "phalcon/mvc/url.zep", 226);
			return;
		}
		_5$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_router"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(router, _5$$9);
		if (Z_TYPE_P(router) != IS_OBJECT) {
			_6$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(dependencyInjector, _6$$11);
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_url_exception_ce, "A dependency injector container is required to obtain the 'router' service", "phalcon/mvc/url.zep", 238);
				return;
			}
			ZEPHIR_INIT_VAR(_8$$11);
			ZVAL_STRING(_8$$11, "router", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7$$11, dependencyInjector, "getshared", NULL, 0, _8$$11);
			zephir_check_temp_parameter(_8$$11);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(router, _7$$11);
			zephir_update_property_this(getThis(), SL("_router"), router TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_9$$9, router, "getroutebyname", NULL, 0, routeName);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(route, _9$$9);
		if (Z_TYPE_P(route) != IS_OBJECT) {
			ZEPHIR_INIT_VAR(_10$$13);
			object_init_ex(_10$$13, phalcon_mvc_url_exception_ce);
			ZEPHIR_INIT_VAR(_11$$13);
			ZEPHIR_CONCAT_SVS(_11$$13, "Cannot obtain a route using the name '", routeName, "'");
			ZEPHIR_CALL_METHOD(NULL, _10$$13, "__construct", NULL, 9, _11$$13);
			zephir_check_call_status();
			zephir_throw_exception_debug(_10$$13, "phalcon/mvc/url.zep", 250 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(_12$$9);
		ZEPHIR_CALL_METHOD(&_9$$9, route, "getpattern", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_13$$9, route, "getreversedpaths", NULL, 0);
		zephir_check_call_status();
		phalcon_replace_paths(_12$$9, _9$$9, _13$$9, uri TSRMLS_CC);
		ZEPHIR_CPY_WRT(uri, _12$$9);
	}
	if (zephir_is_true(local)) {
		zephir_get_strval(_14$$14, uri);
		ZEPHIR_CPY_WRT(strUri, _14$$14);
		_15$$14 = ZEPHIR_IS_STRING(baseUri, "/");
		if (_15$$14) {
			_15$$14 = zephir_fast_strlen_ev(strUri) > 2;
		}
		_16$$14 = _15$$14;
		if (_16$$14) {
			_17$$14 = ZEPHIR_STRING_OFFSET(strUri, 0);
			_16$$14 = _17$$14 == '/';
		}
		_18$$14 = _16$$14;
		if (_18$$14) {
			_19$$14 = ZEPHIR_STRING_OFFSET(strUri, 1);
			_18$$14 = _19$$14 != '/';
		}
		if (_18$$14) {
			ZEPHIR_SINIT_VAR(_20$$15);
			ZVAL_LONG(&_20$$15, 1);
			ZEPHIR_INIT_VAR(_21$$15);
			zephir_substr(_21$$15, strUri, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_NVAR(uri);
			ZEPHIR_CONCAT_VV(uri, baseUri, _21$$15);
		} else {
			_22$$16 = ZEPHIR_IS_STRING(baseUri, "/");
			if (_22$$16) {
				_22$$16 = zephir_fast_strlen_ev(strUri) == 1;
			}
			_23$$16 = _22$$16;
			if (_23$$16) {
				_24$$16 = ZEPHIR_STRING_OFFSET(strUri, 0);
				_23$$16 = _24$$16 == '/';
			}
			if (_23$$16) {
				ZEPHIR_CPY_WRT(uri, baseUri);
			} else {
				ZEPHIR_INIT_NVAR(uri);
				ZEPHIR_CONCAT_VV(uri, baseUri, strUri);
			}
		}
	}
	if (zephir_is_true(args)) {
		ZEPHIR_CALL_FUNCTION(&queryString, "http_build_query", NULL, 400, args);
		zephir_check_call_status();
		_25$$19 = Z_TYPE_P(queryString) == IS_STRING;
		if (_25$$19) {
			_25$$19 = ((zephir_fast_strlen_ev(queryString)) ? 1 : 0);
		}
		if (_25$$19) {
			ZEPHIR_SINIT_VAR(_26$$20);
			ZVAL_STRING(&_26$$20, "?", 0);
			ZEPHIR_INIT_VAR(_27$$20);
			zephir_fast_strpos(_27$$20, uri, &_26$$20, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(_27$$20)) {
				ZEPHIR_INIT_VAR(_28$$21);
				ZEPHIR_CONCAT_SV(_28$$21, "&", queryString);
				zephir_concat_self(&uri, _28$$21 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(_29$$22);
				ZEPHIR_CONCAT_SV(_29$$22, "?", queryString);
				zephir_concat_self(&uri, _29$$22 TSRMLS_CC);
			}
		}
	}
	RETVAL_ZVAL(uri, 1, 0);
	RETURN_MM();

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
PHP_METHOD(Phalcon_Mvc_Url, getStatic) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getstaticbaseuri", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_NULL(_1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, uri, _1, _2, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generates a local path
 */
PHP_METHOD(Phalcon_Mvc_Url, path) {

	zval *path_param = NULL, *_0;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path_param);

	if (!path_param) {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	} else {
		zephir_get_strval(path, path_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_basePath"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VV(return_value, _0, path);
	RETURN_MM();

}

