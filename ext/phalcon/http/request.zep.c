
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Http\Request
 *
 * Encapsulates request information for easy and secure access from application
 * controllers.
 *
 * The request object is a simple value object that is passed between the
 * dispatcher and controller classes. It packages the HTTP request environment.
 *
 *<code>
 * use Phalcon\Http\Request;
 *
 * $request = new Request();
 *
 * if ($request->isPost() && $request->isAjax()) {
 *     echo "Request was made using POST and AJAX";
 * }
 *
 * // Retrieve SERVER variables
 * $request->getServer("HTTP_HOST");
 *
 * // GET, POST, PUT, DELETE, HEAD, OPTIONS, PATCH, PURGE, TRACE, CONNECT
 * $request->getMethod();
 *
 * // An array of languages the client accepts
 * $request->getLanguages();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Request) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http, Request, phalcon, http_request, phalcon_http_request_method_entry, 0);

	zend_declare_property_null(phalcon_http_request_ce, SL("container"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_ce, SL("filterService"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_request_ce, SL("httpMethodParameterOverride"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_request_ce, SL("queryFilters"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_ce, SL("putCache"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_ce, SL("rawBody"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_request_ce, SL("strictHostCheck"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	phalcon_http_request_ce->create_object = zephir_init_properties_Phalcon_Http_Request;

	zend_class_implements(phalcon_http_request_ce TSRMLS_CC, 1, phalcon_http_requestinterface_ce);
	zend_class_implements(phalcon_http_request_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Http_Request, getHttpMethodParameterOverride) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "httpMethodParameterOverride");

}

/**
 */
PHP_METHOD(Phalcon_Http_Request, setHttpMethodParameterOverride) {

	zval *httpMethodParameterOverride_param = NULL, __$true, __$false;
	zend_bool httpMethodParameterOverride;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &httpMethodParameterOverride_param);

	httpMethodParameterOverride = zephir_get_boolval(httpMethodParameterOverride_param);


	if (httpMethodParameterOverride) {
		zephir_update_property_zval(this_ptr, SL("httpMethodParameterOverride"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("httpMethodParameterOverride"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Gets a variable from the $_REQUEST superglobal applying filters if
 * needed. If no parameters are given the $_REQUEST superglobal is returned
 *
 *<code>
 * // Returns value from $_REQUEST["user_email"] without sanitizing
 * $userEmail = $request->get("user_email");
 *
 * // Returns value from $_REQUEST["user_email"] with sanitizing
 * $userEmail = $request->get("user_email", "email");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Request, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _REQUEST, __$null, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	if (notAllowEmpty) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 335, &_REQUEST, &name, filters, defaultValue, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets an array with mime/types and their quality accepted by the
 * browser/client from _SERVER["HTTP_ACCEPT"]
 */
PHP_METHOD(Phalcon_Http_Request, getAcceptableContent) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "accept");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getqualityheader", NULL, 336, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets auth info accepted by the browser/client from
 * $_SERVER["PHP_AUTH_USER"]
 */
PHP_METHOD(Phalcon_Http_Request, getBasicAuth) {

	zend_bool _0;
	zval _SERVER, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	_0 = !(zephir_array_isset_string(&_SERVER, SL("PHP_AUTH_USER")));
	if (!(_0)) {
		_0 = !(zephir_array_isset_string(&_SERVER, SL("PHP_AUTH_PW")));
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_1);
	zephir_array_fetch_string(&_1, &_SERVER, SL("PHP_AUTH_USER"), PH_NOISY, "phalcon/Http/Request.zep", 118 TSRMLS_CC);
	zephir_array_update_string(return_value, SL("username"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_array_fetch_string(&_1, &_SERVER, SL("PHP_AUTH_PW"), PH_NOISY, "phalcon/Http/Request.zep", 120 TSRMLS_CC);
	zephir_array_update_string(return_value, SL("password"), &_1, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Gets best mime/type accepted by the browser/client from
 * _SERVER["HTTP_ACCEPT"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestAccept) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getacceptablecontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "accept");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbestquality", NULL, 337, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best charset accepted by the browser/client from
 * _SERVER["HTTP_ACCEPT_CHARSET"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestCharset) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclientcharsets", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "charset");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbestquality", NULL, 337, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best language accepted by the browser/client from
 * _SERVER["HTTP_ACCEPT_LANGUAGE"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestLanguage) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getlanguages", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "language");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbestquality", NULL, 337, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets most possible client IPv4 Address. This method searches in
 * `$_SERVER["REMOTE_ADDR"]` and optionally in
 * `$_SERVER["HTTP_X_FORWARDED_FOR"]`
 */
PHP_METHOD(Phalcon_Http_Request, getClientAddress) {

	zval *trustForwardedHeader_param = NULL, _SERVER, address, _0$$7, _1$$7;
	zend_bool trustForwardedHeader;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&address);
	ZVAL_UNDEF(&_0$$7);
	ZVAL_UNDEF(&_1$$7);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 0, 1, &trustForwardedHeader_param);

	if (!trustForwardedHeader_param) {
		trustForwardedHeader = 0;
	} else {
		trustForwardedHeader = zephir_get_boolval(trustForwardedHeader_param);
	}


	ZEPHIR_INIT_VAR(&address);
	ZVAL_NULL(&address);
	if (trustForwardedHeader) {
		ZEPHIR_OBS_NVAR(&address);
		zephir_array_isset_string_fetch(&address, &_SERVER, SL("HTTP_X_FORWARDED_FOR"), 0);
		if (Z_TYPE_P(&address) == IS_NULL) {
			ZEPHIR_OBS_NVAR(&address);
			zephir_array_isset_string_fetch(&address, &_SERVER, SL("HTTP_CLIENT_IP"), 0);
		}
	}
	if (Z_TYPE_P(&address) == IS_NULL) {
		ZEPHIR_OBS_NVAR(&address);
		zephir_array_isset_string_fetch(&address, &_SERVER, SL("REMOTE_ADDR"), 0);
	}
	if (Z_TYPE_P(&address) != IS_STRING) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_memnstr_str(&address, SL(","), "phalcon/Http/Request.zep", 178)) {
		ZEPHIR_INIT_VAR(&_0$$7);
		zephir_fast_explode_str(&_0$$7, SL(","), &address, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_1$$7, &_0$$7, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 183 TSRMLS_CC);
		RETURN_CTOR(&_1$$7);
	}
	RETURN_CCTOR(&address);

}

/**
 * Gets a charsets array and their quality accepted by the browser/client
 * from _SERVER["HTTP_ACCEPT_CHARSET"]
 */
PHP_METHOD(Phalcon_Http_Request, getClientCharsets) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT_CHARSET");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "charset");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getqualityheader", NULL, 336, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets content type which request has been made
 */
PHP_METHOD(Phalcon_Http_Request, getContentType) {

	zval _SERVER, contentType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&contentType);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (!(zephir_array_isset_string_fetch(&contentType, &_SERVER, SL("CONTENT_TYPE"), 1))) {
		RETURN_NULL();
	}
	RETURN_CTORW(&contentType);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Http_Request, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * Gets auth info accepted by the browser/client from
 * $_SERVER["PHP_AUTH_DIGEST"]
 */
PHP_METHOD(Phalcon_Http_Request, getDigestAuth) {

	zval auth;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, digest, matches, match, _0$$3, _1$$3, _2$$3, *_3$$5, _4$$5, _5$$6, _6$$6, _7$$7, _8$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&digest);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&auth);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&auth);
	array_init(&auth);
	ZEPHIR_OBS_VAR(&digest);
	if (zephir_array_isset_string_fetch(&digest, &_SERVER, SL("PHP_AUTH_DIGEST"), 0)) {
		ZEPHIR_INIT_VAR(&matches);
		array_init(&matches);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "#(\\w+)=(['\"]?)([^'\" ,]+)\\2#");
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "#(\\w+)=(['\"]?)([^'\" ,]+)\\2#");
		zephir_preg_match(&_1$$3, &_2$$3, &digest, &matches, 1, 2 , 0  TSRMLS_CC);
		if (!(zephir_is_true(&_1$$3))) {
			RETURN_CTOR(&auth);
		}
		if (Z_TYPE_P(&matches) == IS_ARRAY) {
			zephir_is_iterable(&matches, 0, "phalcon/Http/Request.zep", 243);
			if (Z_TYPE_P(&matches) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _3$$5)
				{
					ZEPHIR_INIT_NVAR(&match);
					ZVAL_COPY(&match, _3$$5);
					zephir_array_fetch_long(&_5$$6, &match, 3, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 241 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&_6$$6);
					zephir_array_fetch_long(&_6$$6, &match, 1, PH_NOISY, "phalcon/Http/Request.zep", 241 TSRMLS_CC);
					zephir_array_update_zval(&auth, &_6$$6, &_5$$6, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &matches, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_4$$5, &matches, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_4$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&match, &matches, "current", NULL, 0);
					zephir_check_call_status();
						zephir_array_fetch_long(&_7$$7, &match, 3, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 241 TSRMLS_CC);
						ZEPHIR_OBS_NVAR(&_8$$7);
						zephir_array_fetch_long(&_8$$7, &match, 1, PH_NOISY, "phalcon/Http/Request.zep", 241 TSRMLS_CC);
						zephir_array_update_zval(&auth, &_8$$7, &_7$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &matches, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&match);
		}
	}
	RETURN_CTOR(&auth);

}

/**
 * Retrieves a query/get value always sanitized with the preset filters
 */
PHP_METHOD(Phalcon_Http_Request, getFilteredQuery) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, filters, _0, _1, _2, _3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &name_param, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	ZEPHIR_OBS_VAR(&filters);
	zephir_read_property(&_0, this_ptr, SL("queryFilters"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("get"), PH_READONLY, "phalcon/Http/Request.zep", 256 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&filters, &_1, &name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&filters);
		array_init(&filters);
	}
	if (notAllowEmpty) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getquery", NULL, 0, &name, &filters, defaultValue, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieves a post value always sanitized with the preset filters
 */
PHP_METHOD(Phalcon_Http_Request, getFilteredPost) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, filters, _0, _1, _2, _3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &name_param, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	ZEPHIR_OBS_VAR(&filters);
	zephir_read_property(&_0, this_ptr, SL("queryFilters"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("post"), PH_READONLY, "phalcon/Http/Request.zep", 276 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&filters, &_1, &name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&filters);
		array_init(&filters);
	}
	if (notAllowEmpty) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getpost", NULL, 0, &name, &filters, defaultValue, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieves a put value always sanitized with the preset filters
 */
PHP_METHOD(Phalcon_Http_Request, getFilteredPut) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, filters, _0, _1, _2, _3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &name_param, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	ZEPHIR_OBS_VAR(&filters);
	zephir_read_property(&_0, this_ptr, SL("queryFilters"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("put"), PH_READONLY, "phalcon/Http/Request.zep", 296 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&filters, &_1, &name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&filters);
		array_init(&filters);
	}
	if (notAllowEmpty) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getput", NULL, 0, &name, &filters, defaultValue, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets HTTP header from request data
 */
PHP_METHOD(Phalcon_Http_Request, getHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *header_param = NULL, _SERVER, value, name, _0, _1, _2, _3;
	zval header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &header_param);

	if (UNEXPECTED(Z_TYPE_P(header_param) != IS_STRING && Z_TYPE_P(header_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'header' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(header_param) == IS_STRING)) {
		zephir_get_strval(&header, header_param);
	} else {
		ZEPHIR_INIT_VAR(&header);
		ZVAL_EMPTY_STRING(&header);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "-");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_");
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 80, &header, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	zephir_fast_strtoupper(&name, &_2);
	ZEPHIR_OBS_VAR(&value);
	if (zephir_array_isset_fetch(&value, &_SERVER, &name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&value);
	}
	ZEPHIR_OBS_NVAR(&value);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "HTTP_", &name);
	if (zephir_array_isset_fetch(&value, &_SERVER, &_3, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&value);
	}
	RETURN_MM_STRING("");

}

/**
 * Returns the available headers in the request
 *
 * <code>
 * $_SERVER = [
 *     "PHP_AUTH_USER" => "phalcon",
 *     "PHP_AUTH_PW"   => "secret",
 * ];
 *
 * $headers = $request->getHeaders();
 *
 * echo $headers["Authorization"]; // Basic cGhhbGNvbjpzZWNyZXQ=
 * </code>
 */
PHP_METHOD(Phalcon_Http_Request, getHeaders) {

	zend_string *_3;
	zend_ulong _2;
	zval headers, contentHeaders;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, _SERVER, name, value, authHeaders, *_0, _1, _39, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _11$$4, _12$$4, _13$$4, _14$$3, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5, _21$$5, _22$$7, _23$$7, _24$$7, _25$$7, _26$$7, _27$$7, _28$$7, _29$$7, _30$$7, _31$$6, _32$$8, _33$$8, _34$$8, _35$$8, _36$$8, _37$$8, _38$$8;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&authHeaders);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$6);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_35$$8);
	ZVAL_UNDEF(&_36$$8);
	ZVAL_UNDEF(&_37$$8);
	ZVAL_UNDEF(&_38$$8);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&contentHeaders);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	ZEPHIR_INIT_VAR(&contentHeaders);
	zephir_create_array(&contentHeaders, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_TYPE"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_LENGTH"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_MD5"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_is_iterable(&_SERVER, 0, "phalcon/Http/Request.zep", 393);
	if (Z_TYPE_P(&_SERVER) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_SERVER), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (zephir_start_with_str(&name, SL("HTTP_"))) {
				ZEPHIR_INIT_NVAR(&_4$$4);
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZVAL_LONG(&_6$$4, 5);
				ZEPHIR_INIT_NVAR(&_7$$4);
				zephir_substr(&_7$$4, &name, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZVAL_STRING(&_8$$4, "_");
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZVAL_STRING(&_9$$4, " ");
				zephir_fast_str_replace(&_5$$4, &_8$$4, &_9$$4, &_7$$4 TSRMLS_CC);
				zephir_fast_strtolower(&_4$$4, &_5$$4);
				ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_10, 232, &_4$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$4);
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZVAL_STRING(&_12$$4, " ");
				ZEPHIR_INIT_NVAR(&_13$$4);
				ZVAL_STRING(&_13$$4, "-");
				zephir_fast_str_replace(&_11$$4, &_12$$4, &_13$$4, &name TSRMLS_CC);
				ZEPHIR_CPY_WRT(&name, &_11$$4);
				zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
				continue;
			}
			ZEPHIR_INIT_NVAR(&_14$$3);
			zephir_fast_strtoupper(&_14$$3, &name);
			ZEPHIR_CPY_WRT(&name, &_14$$3);
			if (zephir_array_isset(&contentHeaders, &name)) {
				ZEPHIR_INIT_NVAR(&_15$$5);
				ZEPHIR_INIT_NVAR(&_16$$5);
				ZEPHIR_INIT_NVAR(&_17$$5);
				ZVAL_STRING(&_17$$5, "_");
				ZEPHIR_INIT_NVAR(&_18$$5);
				ZVAL_STRING(&_18$$5, " ");
				zephir_fast_str_replace(&_16$$5, &_17$$5, &_18$$5, &name TSRMLS_CC);
				zephir_fast_strtolower(&_15$$5, &_16$$5);
				ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_10, 232, &_15$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_19$$5);
				ZEPHIR_INIT_NVAR(&_20$$5);
				ZVAL_STRING(&_20$$5, " ");
				ZEPHIR_INIT_NVAR(&_21$$5);
				ZVAL_STRING(&_21$$5, "-");
				zephir_fast_str_replace(&_19$$5, &_20$$5, &_21$$5, &name TSRMLS_CC);
				ZEPHIR_CPY_WRT(&name, &_19$$5);
				zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_SERVER, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &_SERVER, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &_SERVER, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_SERVER, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_start_with_str(&name, SL("HTTP_"))) {
					ZEPHIR_INIT_NVAR(&_22$$7);
					ZEPHIR_INIT_NVAR(&_23$$7);
					ZVAL_LONG(&_24$$7, 5);
					ZEPHIR_INIT_NVAR(&_25$$7);
					zephir_substr(&_25$$7, &name, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					ZEPHIR_INIT_NVAR(&_26$$7);
					ZVAL_STRING(&_26$$7, "_");
					ZEPHIR_INIT_NVAR(&_27$$7);
					ZVAL_STRING(&_27$$7, " ");
					zephir_fast_str_replace(&_23$$7, &_26$$7, &_27$$7, &_25$$7 TSRMLS_CC);
					zephir_fast_strtolower(&_22$$7, &_23$$7);
					ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_10, 232, &_22$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_28$$7);
					ZEPHIR_INIT_NVAR(&_29$$7);
					ZVAL_STRING(&_29$$7, " ");
					ZEPHIR_INIT_NVAR(&_30$$7);
					ZVAL_STRING(&_30$$7, "-");
					zephir_fast_str_replace(&_28$$7, &_29$$7, &_30$$7, &name TSRMLS_CC);
					ZEPHIR_CPY_WRT(&name, &_28$$7);
					zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
					continue;
				}
				ZEPHIR_INIT_NVAR(&_31$$6);
				zephir_fast_strtoupper(&_31$$6, &name);
				ZEPHIR_CPY_WRT(&name, &_31$$6);
				if (zephir_array_isset(&contentHeaders, &name)) {
					ZEPHIR_INIT_NVAR(&_32$$8);
					ZEPHIR_INIT_NVAR(&_33$$8);
					ZEPHIR_INIT_NVAR(&_34$$8);
					ZVAL_STRING(&_34$$8, "_");
					ZEPHIR_INIT_NVAR(&_35$$8);
					ZVAL_STRING(&_35$$8, " ");
					zephir_fast_str_replace(&_33$$8, &_34$$8, &_35$$8, &name TSRMLS_CC);
					zephir_fast_strtolower(&_32$$8, &_33$$8);
					ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_10, 232, &_32$$8);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_36$$8);
					ZEPHIR_INIT_NVAR(&_37$$8);
					ZVAL_STRING(&_37$$8, " ");
					ZEPHIR_INIT_NVAR(&_38$$8);
					ZVAL_STRING(&_38$$8, "-");
					zephir_fast_str_replace(&_36$$8, &_37$$8, &_38$$8, &name TSRMLS_CC);
					ZEPHIR_CPY_WRT(&name, &_36$$8);
					zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_SERVER, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_CALL_METHOD(&authHeaders, this_ptr, "resolveauthorizationheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_39);
	zephir_fast_array_merge(&_39, &headers, &authHeaders TSRMLS_CC);
	ZEPHIR_CPY_WRT(&headers, &_39);
	RETURN_CTOR(&headers);

}

/**
 * Gets host name used by the request.
 *
 * `Request::getHttpHost` trying to find host name in following order:
 *
 * - `$_SERVER["HTTP_HOST"]`
 * - `$_SERVER["SERVER_NAME"]`
 * - `$_SERVER["SERVER_ADDR"]`
 *
 * Optionally `Request::getHttpHost` validates and clean host name.
 * The `Request::$strictHostCheck` can be used to validate host name.
 *
 * Note: validation and cleaning have a negative performance impact because
 * they use regular expressions.
 *
 * <code>
 * use Phalcon\Http\Request;
 *
 * $request = new Request;
 *
 * $_SERVER["HTTP_HOST"] = "example.com";
 * $request->getHttpHost(); // example.com
 *
 * $_SERVER["HTTP_HOST"] = "example.com:8080";
 * $request->getHttpHost(); // example.com:8080
 *
 * $request->setStrictHostCheck(true);
 * $_SERVER["HTTP_HOST"] = "ex=am~ple.com";
 * $request->getHttpHost(); // UnexpectedValueException
 *
 * $_SERVER["HTTP_HOST"] = "ExAmPlE.com";
 * $request->getHttpHost(); // example.com
 * </code>
 */
PHP_METHOD(Phalcon_Http_Request, getHttpHost) {

	zval _14;
	zend_bool _3;
	zval host, strict, _0, _1$$3, _2$$4, _4$$5, _8$$5, _9$$5, _10$$5, _11$$5, _5$$6, _6$$6, _7$$6, _12$$7, _13$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&strict);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&strict);
	zephir_read_property(&strict, this_ptr, SL("strictHostCheck"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_HOST");
	ZEPHIR_CALL_METHOD(&host, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&host))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "SERVER_NAME");
		ZEPHIR_CALL_METHOD(&host, this_ptr, "getserver", NULL, 0, &_1$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(&host))) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "SERVER_ADDR");
			ZEPHIR_CALL_METHOD(&host, this_ptr, "getserver", NULL, 0, &_2$$4);
			zephir_check_call_status();
		}
	}
	_3 = zephir_is_true(&host);
	if (_3) {
		_3 = zephir_is_true(&strict);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_4$$5);
		zephir_fast_trim(&_4$$5, &host, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&host);
		zephir_fast_strtolower(&host, &_4$$5);
		if (zephir_memnstr_str(&host, SL(":"), "phalcon/Http/Request.zep", 467)) {
			ZEPHIR_INIT_VAR(&_5$$6);
			ZVAL_STRING(&_5$$6, "/:[[:digit:]]+$/");
			ZEPHIR_INIT_VAR(&_6$$6);
			ZVAL_STRING(&_6$$6, "");
			ZEPHIR_CALL_FUNCTION(&_7$$6, "preg_replace", NULL, 38, &_5$$6, &_6$$6, &host);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&host, &_7$$6);
		}
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "/[a-z0-9-]+\\.?/");
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "");
		ZEPHIR_CALL_FUNCTION(&_10$$5, "preg_replace", NULL, 38, &_8$$5, &_9$$5, &host);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_11$$5);
		ZVAL_STRING(&_11$$5, "");
		if (UNEXPECTED(!ZEPHIR_IS_IDENTICAL(&_11$$5, &_10$$5))) {
			ZEPHIR_INIT_VAR(&_12$$7);
			object_init_ex(&_12$$7, spl_ce_UnexpectedValueException);
			ZEPHIR_INIT_VAR(&_13$$7);
			ZEPHIR_CONCAT_SV(&_13$$7, "Invalid host ", &host);
			ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", NULL, 338, &_13$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_12$$7, "phalcon/Http/Request.zep", 477 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_get_strval(&_14, &host);
	RETURN_CTOR(&_14);

}

/**
 * Gets web page that refers active request. ie: http://www.google.com
 */
PHP_METHOD(Phalcon_Http_Request, getHTTPReferer) {

	zval _SERVER, httpReferer;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&httpReferer);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (!(zephir_array_isset_string_fetch(&httpReferer, &_SERVER, SL("HTTP_REFERER"), 1))) {
		RETURN_STRING("");
	}
	RETURN_CTORW(&httpReferer);

}

/**
 * Gets decoded JSON HTTP raw request body
 */
PHP_METHOD(Phalcon_Http_Request, getJsonRawBody) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *associative_param = NULL, rawBody, _0;
	zend_bool associative;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawBody);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &associative_param);

	if (!associative_param) {
		associative = 0;
	} else {
		associative = zephir_get_boolval(associative_param);
	}


	ZEPHIR_CALL_METHOD(&rawBody, this_ptr, "getrawbody", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&rawBody) != IS_STRING) {
		RETURN_MM_BOOL(0);
	}
	ZVAL_BOOL(&_0, (associative ? 1 : 0));
	zephir_json_decode(return_value, &rawBody, zephir_get_intval(&_0) );
	RETURN_MM();

}

/**
 * Gets languages array and their quality accepted by the browser/client
 * from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 */
PHP_METHOD(Phalcon_Http_Request, getLanguages) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT_LANGUAGE");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "language");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getqualityheader", NULL, 336, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets HTTP method which request has been made
 *
 * If the X-HTTP-Method-Override header is set, and if the method is a POST,
 * then it is used to determine the "real" intended HTTP method.
 *
 * The _method request parameter can also be used to determine the HTTP
 * method, but only if setHttpMethodParameterOverride(true) has been called.
 *
 * The method is always an uppercased string.
 */
PHP_METHOD(Phalcon_Http_Request, getMethod) {

	zval returnMethod;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, _REQUEST, overridedMethod, spoofedMethod, requestMethod, _0, _3, _1$$5, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_UNDEF(&overridedMethod);
	ZVAL_UNDEF(&spoofedMethod);
	ZVAL_UNDEF(&requestMethod);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&returnMethod);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&returnMethod);
	ZVAL_STRING(&returnMethod, "");
	ZEPHIR_OBS_VAR(&requestMethod);
	if (EXPECTED(zephir_array_isset_string_fetch(&requestMethod, &_SERVER, SL("REQUEST_METHOD"), 0))) {
		ZEPHIR_INIT_NVAR(&returnMethod);
		zephir_fast_strtoupper(&returnMethod, &requestMethod);
	} else {
		RETURN_MM_STRING("GET");
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "POST");
	if (ZEPHIR_IS_IDENTICAL(&_0, &returnMethod)) {
		ZEPHIR_INIT_VAR(&_1$$5);
		ZVAL_STRING(&_1$$5, "X-HTTP-METHOD-OVERRIDE");
		ZEPHIR_CALL_METHOD(&overridedMethod, this_ptr, "getheader", NULL, 339, &_1$$5);
		zephir_check_call_status();
		zephir_read_property(&_2$$5, this_ptr, SL("httpMethodParameterOverride"), PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_IS_EMPTY(&overridedMethod))) {
			ZEPHIR_INIT_NVAR(&returnMethod);
			zephir_fast_strtoupper(&returnMethod, &overridedMethod);
		} else if (zephir_is_true(&_2$$5)) {
			ZEPHIR_OBS_VAR(&spoofedMethod);
			if (zephir_array_isset_string_fetch(&spoofedMethod, &_REQUEST, SL("_method"), 0)) {
				ZEPHIR_INIT_NVAR(&returnMethod);
				zephir_fast_strtoupper(&returnMethod, &spoofedMethod);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "isvalidhttpmethod", NULL, 0, &returnMethod);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		RETURN_MM_STRING("GET");
	}
	RETURN_CTOR(&returnMethod);

}

/**
 * Gets information about the port on which the request is made.
 */
PHP_METHOD(Phalcon_Http_Request, getPort) {

	zval host, pos, _0, _6, _7, _1$$3, _2$$3, _3$$4, _4$$5, _5$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_HOST");
	ZEPHIR_CALL_METHOD(&host, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&host))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "SERVER_PORT");
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getserver", NULL, 0, &_2$$3);
		zephir_check_call_status();
		RETURN_MM_LONG(zephir_get_intval(&_1$$3));
	}
	if (zephir_memnstr_str(&host, SL(":"), "phalcon/Http/Request.zep", 580)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, ":");
		ZEPHIR_CALL_FUNCTION(&pos, "strrpos", NULL, 163, &host, &_3$$4);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
			ZVAL_LONG(&_4$$5, (zephir_get_numberval(&pos) + 1));
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_substr(&_5$$5, &host, zephir_get_intval(&_4$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			RETURN_MM_LONG(zephir_get_intval(&_5$$5));
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getscheme", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "https");
	if (ZEPHIR_IS_IDENTICAL(&_7, &_6)) {
		ZVAL_LONG(&_0, 443);
	} else {
		ZVAL_LONG(&_0, 80);
	}
	RETURN_CCTOR(&_0);

}

/**
 * Gets a variable from the $_POST superglobal applying filters if needed
 * If no parameters are given the $_POST superglobal is returned
 *
 *<code>
 * // Returns value from $_POST["user_email"] without sanitizing
 * $userEmail = $request->getPost("user_email");
 *
 * // Returns value from $_POST["user_email"] with sanitizing
 * $userEmail = $request->getPost("user_email", "email");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Request, getPost) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _POST, __$null, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_POST);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	if (notAllowEmpty) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 335, &_POST, &name, filters, defaultValue, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a variable from put request
 *
 *<code>
 * // Returns value from $_PUT["user_email"] without sanitizing
 * $userEmail = $request->getPut("user_email");
 *
 * // Returns value from $_PUT["user_email"] with sanitizing
 * $userEmail = $request->getPut("user_email", "email");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Request, getPut) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive, _0$$3;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, put, contentType, _5, _6, _1$$3, _2$$3, _3$$4, _4$$6;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&put);
	ZVAL_UNDEF(&contentType);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	ZEPHIR_OBS_VAR(&put);
	zephir_read_property(&put, this_ptr, SL("putCache"), PH_NOISY_CC);
	if (Z_TYPE_P(&put) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL, 0);
		zephir_check_call_status();
		_0$$3 = Z_TYPE_P(&contentType) == IS_STRING;
		if (_0$$3) {
			ZEPHIR_INIT_VAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "json");
			ZEPHIR_CALL_FUNCTION(&_2$$3, "stripos", NULL, 340, &contentType, &_1$$3);
			zephir_check_call_status();
			_0$$3 = !ZEPHIR_IS_FALSE(&_2$$3);
		}
		if (_0$$3) {
			ZVAL_BOOL(&_3$$4, 1);
			ZEPHIR_CALL_METHOD(&put, this_ptr, "getjsonrawbody", NULL, 0, &_3$$4);
			zephir_check_call_status();
			if (Z_TYPE_P(&put) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&put);
				array_init(&put);
			}
		} else {
			ZEPHIR_INIT_NVAR(&put);
			array_init(&put);
			ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "getrawbody", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_MAKE_REF(&put);
			ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 302, &_4$$6, &put);
			ZEPHIR_UNREF(&put);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("putCache"), &put);
	}
	if (notAllowEmpty) {
		ZVAL_BOOL(&_5, 1);
	} else {
		ZVAL_BOOL(&_5, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_6, 1);
	} else {
		ZVAL_BOOL(&_6, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 335, &put, &name, filters, defaultValue, &_5, &_6);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets variable from $_GET superglobal applying filters if needed
 * If no parameters are given the $_GET superglobal is returned
 *
 *<code>
 * // Returns value from $_GET["id"] without sanitizing
 * $id = $request->getQuery("id");
 *
 * // Returns value from $_GET["id"] with sanitizing
 * $id = $request->getQuery("id", "int");
 *
 * // Returns value from $_GET["id"] with a default value
 * $id = $request->getQuery("id", null, 150);
 *</code>
 */
PHP_METHOD(Phalcon_Http_Request, getQuery) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _GET, __$null, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_GET);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	if (notAllowEmpty) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 335, &_GET, &name, filters, defaultValue, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets HTTP raw request body
 */
PHP_METHOD(Phalcon_Http_Request, getRawBody) {

	zval rawBody, contents, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawBody);
	ZVAL_UNDEF(&contents);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("rawBody"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&rawBody, &_0);
	if (ZEPHIR_IS_EMPTY(&rawBody)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "php://input");
		ZEPHIR_INIT_VAR(&contents);
		zephir_file_get_contents(&contents, &_1$$3 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("rawBody"), &contents);
		RETURN_CCTOR(&contents);
	}
	RETURN_CCTOR(&rawBody);

}

/**
 * Gets HTTP schema (http/https)
 */
PHP_METHOD(Phalcon_Http_Request, getScheme) {

	zend_bool _1;
	zval https, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&https);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTPS");
	ZEPHIR_CALL_METHOD(&https, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	_1 = zephir_is_true(&https);
	if (_1) {
		_1 = !ZEPHIR_IS_STRING(&https, "off");
	}
	if (_1) {
		RETURN_MM_STRING("https");
	}
	RETURN_MM_STRING("http");

}

/**
 * Gets variable from $_SERVER superglobal
 */
PHP_METHOD(Phalcon_Http_Request, getServer) {

	zval *name_param = NULL, _SERVER, serverValue;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&serverValue);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	if (!(zephir_array_isset_fetch(&serverValue, &_SERVER, &name, 1 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	RETURN_CTOR(&serverValue);

}

/**
 * Gets active server address IP
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, serverAddr, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&serverAddr);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_OBS_VAR(&serverAddr);
	if (!(zephir_array_isset_string_fetch(&serverAddr, &_SERVER, SL("SERVER_ADDR"), 0))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "localhost");
		ZEPHIR_RETURN_CALL_FUNCTION("gethostbyname", NULL, 341, &_0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&serverAddr);

}

/**
 * Gets active server name
 */
PHP_METHOD(Phalcon_Http_Request, getServerName) {

	zval _SERVER, serverName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&serverName);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (!(zephir_array_isset_string_fetch(&serverName, &_SERVER, SL("SERVER_NAME"), 1))) {
		RETURN_STRING("localhost");
	}
	RETURN_CTORW(&serverName);

}

/**
 * Gets attached files as Phalcon\Http\Request\File instances
 */
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zval files;
	zephir_fcall_cache_entry *_10 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *onlySuccessful_param = NULL, *namedKeys_param = NULL, _FILES, superFiles, prefix, input, smoothInput, file, dataFile, *_0$$3, _1$$3, _4$$4, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, *_11$$5, _12$$5, _14$$6, _15$$7, _16$$8, _17$$8, _19$$8, _20$$9, _21$$9, _23$$10, _24$$11, _25$$11, _26$$12, _27$$12, _28$$12, _29$$13, _30$$13, _32$$14, _33$$16, _34$$17, _35$$18, _36$$19, _37$$19, _38$$19, _39$$19, _40$$19, *_41$$19, _42$$19, _44$$20, _45$$21, _46$$21, _47$$22, _48$$22, _49$$22, _50$$23, _51$$23, _53$$24, _54$$25, _55$$25, _56$$26, _57$$26, _58$$26, _59$$27, _60$$27, _62$$28, _63$$30, _64$$31;
	zend_bool onlySuccessful, namedKeys, _13$$6, _22$$10, _31$$14, _43$$20, _52$$24, _61$$28;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&superFiles);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&smoothInput);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&dataFile);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_34$$17);
	ZVAL_UNDEF(&_35$$18);
	ZVAL_UNDEF(&_36$$19);
	ZVAL_UNDEF(&_37$$19);
	ZVAL_UNDEF(&_38$$19);
	ZVAL_UNDEF(&_39$$19);
	ZVAL_UNDEF(&_40$$19);
	ZVAL_UNDEF(&_42$$19);
	ZVAL_UNDEF(&_44$$20);
	ZVAL_UNDEF(&_45$$21);
	ZVAL_UNDEF(&_46$$21);
	ZVAL_UNDEF(&_47$$22);
	ZVAL_UNDEF(&_48$$22);
	ZVAL_UNDEF(&_49$$22);
	ZVAL_UNDEF(&_50$$23);
	ZVAL_UNDEF(&_51$$23);
	ZVAL_UNDEF(&_53$$24);
	ZVAL_UNDEF(&_54$$25);
	ZVAL_UNDEF(&_55$$25);
	ZVAL_UNDEF(&_56$$26);
	ZVAL_UNDEF(&_57$$26);
	ZVAL_UNDEF(&_58$$26);
	ZVAL_UNDEF(&_59$$27);
	ZVAL_UNDEF(&_60$$27);
	ZVAL_UNDEF(&_62$$28);
	ZVAL_UNDEF(&_63$$30);
	ZVAL_UNDEF(&_64$$31);
	ZVAL_UNDEF(&files);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_fetch_params(1, 0, 2, &onlySuccessful_param, &namedKeys_param);

	if (!onlySuccessful_param) {
		onlySuccessful = 0;
	} else {
		onlySuccessful = zephir_get_boolval(onlySuccessful_param);
	}
	if (!namedKeys_param) {
		namedKeys = 0;
	} else {
		namedKeys = zephir_get_boolval(namedKeys_param);
	}


	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	ZEPHIR_CPY_WRT(&superFiles, &_FILES);
	if (zephir_fast_count_int(&superFiles TSRMLS_CC) > 0) {
		zephir_is_iterable(&superFiles, 0, "phalcon/Http/Request.zep", 823);
		if (Z_TYPE_P(&superFiles) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&superFiles), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&prefix);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&prefix, _3$$3);
				} else {
					ZVAL_LONG(&prefix, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&input);
				ZVAL_COPY(&input, _0$$3);
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_array_fetch_string(&_4$$4, &input, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 780 TSRMLS_CC);
				if (Z_TYPE_P(&_4$$4) == IS_ARRAY) {
					zephir_array_fetch_string(&_5$$5, &input, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 782 TSRMLS_CC);
					zephir_array_fetch_string(&_6$$5, &input, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 783 TSRMLS_CC);
					zephir_array_fetch_string(&_7$$5, &input, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 784 TSRMLS_CC);
					zephir_array_fetch_string(&_8$$5, &input, SL("size"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 785 TSRMLS_CC);
					zephir_array_fetch_string(&_9$$5, &input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 786 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&smoothInput, this_ptr, "smoothfiles", &_10, 342, &_5$$5, &_6$$5, &_7$$5, &_8$$5, &_9$$5, &prefix);
					zephir_check_call_status();
					zephir_is_iterable(&smoothInput, 0, "phalcon/Http/Request.zep", 813);
					if (Z_TYPE_P(&smoothInput) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&smoothInput), _11$$5)
						{
							ZEPHIR_INIT_NVAR(&file);
							ZVAL_COPY(&file, _11$$5);
							_13$$6 = onlySuccessful == 0;
							if (!(_13$$6)) {
								zephir_array_fetch_string(&_14$$6, &file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 791 TSRMLS_CC);
								_13$$6 = ZEPHIR_IS_LONG(&_14$$6, 0);
							}
							if (_13$$6) {
								ZEPHIR_INIT_NVAR(&dataFile);
								zephir_create_array(&dataFile, 5, 0 TSRMLS_CC);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 793 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("name"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("type"), PH_NOISY, "phalcon/Http/Request.zep", 794 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("type"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("tmp_name"), PH_NOISY, "phalcon/Http/Request.zep", 795 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("tmp_name"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("size"), PH_NOISY, "phalcon/Http/Request.zep", 796 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("size"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("error"), PH_NOISY, "phalcon/Http/Request.zep", 798 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("error"), &_15$$7, PH_COPY | PH_SEPARATE);
								if (namedKeys == 1) {
									ZEPHIR_INIT_NVAR(&_16$$8);
									object_init_ex(&_16$$8, phalcon_http_request_file_ce);
									zephir_array_fetch_string(&_17$$8, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 804 TSRMLS_CC);
									ZEPHIR_CALL_METHOD(NULL, &_16$$8, "__construct", &_18, 343, &dataFile, &_17$$8);
									zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&_19$$8);
									zephir_array_fetch_string(&_19$$8, &file, SL("key"), PH_NOISY, "phalcon/Http/Request.zep", 801 TSRMLS_CC);
									zephir_array_update_zval(&files, &_19$$8, &_16$$8, PH_COPY | PH_SEPARATE);
								} else {
									ZEPHIR_INIT_NVAR(&_20$$9);
									object_init_ex(&_20$$9, phalcon_http_request_file_ce);
									zephir_array_fetch_string(&_21$$9, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 809 TSRMLS_CC);
									ZEPHIR_CALL_METHOD(NULL, &_20$$9, "__construct", &_18, 343, &dataFile, &_21$$9);
									zephir_check_call_status();
									zephir_array_append(&files, &_20$$9, PH_SEPARATE, "phalcon/Http/Request.zep", 809);
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &smoothInput, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_12$$5, &smoothInput, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_12$$5)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&file, &smoothInput, "current", NULL, 0);
							zephir_check_call_status();
								_22$$10 = onlySuccessful == 0;
								if (!(_22$$10)) {
									zephir_array_fetch_string(&_23$$10, &file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 791 TSRMLS_CC);
									_22$$10 = ZEPHIR_IS_LONG(&_23$$10, 0);
								}
								if (_22$$10) {
									ZEPHIR_INIT_NVAR(&_24$$11);
									zephir_create_array(&_24$$11, 5, 0 TSRMLS_CC);
									ZEPHIR_OBS_NVAR(&_25$$11);
									zephir_array_fetch_string(&_25$$11, &file, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 793 TSRMLS_CC);
									zephir_array_update_string(&_24$$11, SL("name"), &_25$$11, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_25$$11);
									zephir_array_fetch_string(&_25$$11, &file, SL("type"), PH_NOISY, "phalcon/Http/Request.zep", 794 TSRMLS_CC);
									zephir_array_update_string(&_24$$11, SL("type"), &_25$$11, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_25$$11);
									zephir_array_fetch_string(&_25$$11, &file, SL("tmp_name"), PH_NOISY, "phalcon/Http/Request.zep", 795 TSRMLS_CC);
									zephir_array_update_string(&_24$$11, SL("tmp_name"), &_25$$11, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_25$$11);
									zephir_array_fetch_string(&_25$$11, &file, SL("size"), PH_NOISY, "phalcon/Http/Request.zep", 796 TSRMLS_CC);
									zephir_array_update_string(&_24$$11, SL("size"), &_25$$11, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_25$$11);
									zephir_array_fetch_string(&_25$$11, &file, SL("error"), PH_NOISY, "phalcon/Http/Request.zep", 798 TSRMLS_CC);
									zephir_array_update_string(&_24$$11, SL("error"), &_25$$11, PH_COPY | PH_SEPARATE);
									ZEPHIR_CPY_WRT(&dataFile, &_24$$11);
									if (namedKeys == 1) {
										ZEPHIR_INIT_NVAR(&_26$$12);
										object_init_ex(&_26$$12, phalcon_http_request_file_ce);
										zephir_array_fetch_string(&_27$$12, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 804 TSRMLS_CC);
										ZEPHIR_CALL_METHOD(NULL, &_26$$12, "__construct", &_18, 343, &dataFile, &_27$$12);
										zephir_check_call_status();
										ZEPHIR_OBS_NVAR(&_28$$12);
										zephir_array_fetch_string(&_28$$12, &file, SL("key"), PH_NOISY, "phalcon/Http/Request.zep", 801 TSRMLS_CC);
										zephir_array_update_zval(&files, &_28$$12, &_26$$12, PH_COPY | PH_SEPARATE);
									} else {
										ZEPHIR_INIT_NVAR(&_29$$13);
										object_init_ex(&_29$$13, phalcon_http_request_file_ce);
										zephir_array_fetch_string(&_30$$13, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 809 TSRMLS_CC);
										ZEPHIR_CALL_METHOD(NULL, &_29$$13, "__construct", &_18, 343, &dataFile, &_30$$13);
										zephir_check_call_status();
										zephir_array_append(&files, &_29$$13, PH_SEPARATE, "phalcon/Http/Request.zep", 809);
									}
								}
							ZEPHIR_CALL_METHOD(NULL, &smoothInput, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&file);
				} else {
					_31$$14 = onlySuccessful == 0;
					if (!(_31$$14)) {
						zephir_array_fetch_string(&_32$$14, &input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 814 TSRMLS_CC);
						_31$$14 = ZEPHIR_IS_LONG(&_32$$14, 0);
					}
					if (_31$$14) {
						if (namedKeys == 1) {
							ZEPHIR_INIT_NVAR(&_33$$16);
							object_init_ex(&_33$$16, phalcon_http_request_file_ce);
							ZEPHIR_CALL_METHOD(NULL, &_33$$16, "__construct", &_18, 343, &input, &prefix);
							zephir_check_call_status();
							zephir_array_update_zval(&files, &prefix, &_33$$16, PH_COPY | PH_SEPARATE);
						} else {
							ZEPHIR_INIT_NVAR(&_34$$17);
							object_init_ex(&_34$$17, phalcon_http_request_file_ce);
							ZEPHIR_CALL_METHOD(NULL, &_34$$17, "__construct", &_18, 343, &input, &prefix);
							zephir_check_call_status();
							zephir_array_append(&files, &_34$$17, PH_SEPARATE, "phalcon/Http/Request.zep", 818);
						}
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &superFiles, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &superFiles, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&prefix, &superFiles, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&input, &superFiles, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&_35$$18);
					zephir_array_fetch_string(&_35$$18, &input, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 780 TSRMLS_CC);
					if (Z_TYPE_P(&_35$$18) == IS_ARRAY) {
						zephir_array_fetch_string(&_36$$19, &input, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 782 TSRMLS_CC);
						zephir_array_fetch_string(&_37$$19, &input, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 783 TSRMLS_CC);
						zephir_array_fetch_string(&_38$$19, &input, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 784 TSRMLS_CC);
						zephir_array_fetch_string(&_39$$19, &input, SL("size"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 785 TSRMLS_CC);
						zephir_array_fetch_string(&_40$$19, &input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 786 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(&smoothInput, this_ptr, "smoothfiles", &_10, 342, &_36$$19, &_37$$19, &_38$$19, &_39$$19, &_40$$19, &prefix);
						zephir_check_call_status();
						zephir_is_iterable(&smoothInput, 0, "phalcon/Http/Request.zep", 813);
						if (Z_TYPE_P(&smoothInput) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&smoothInput), _41$$19)
							{
								ZEPHIR_INIT_NVAR(&file);
								ZVAL_COPY(&file, _41$$19);
								_43$$20 = onlySuccessful == 0;
								if (!(_43$$20)) {
									zephir_array_fetch_string(&_44$$20, &file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 791 TSRMLS_CC);
									_43$$20 = ZEPHIR_IS_LONG(&_44$$20, 0);
								}
								if (_43$$20) {
									ZEPHIR_INIT_NVAR(&_45$$21);
									zephir_create_array(&_45$$21, 5, 0 TSRMLS_CC);
									ZEPHIR_OBS_NVAR(&_46$$21);
									zephir_array_fetch_string(&_46$$21, &file, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 793 TSRMLS_CC);
									zephir_array_update_string(&_45$$21, SL("name"), &_46$$21, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_46$$21);
									zephir_array_fetch_string(&_46$$21, &file, SL("type"), PH_NOISY, "phalcon/Http/Request.zep", 794 TSRMLS_CC);
									zephir_array_update_string(&_45$$21, SL("type"), &_46$$21, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_46$$21);
									zephir_array_fetch_string(&_46$$21, &file, SL("tmp_name"), PH_NOISY, "phalcon/Http/Request.zep", 795 TSRMLS_CC);
									zephir_array_update_string(&_45$$21, SL("tmp_name"), &_46$$21, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_46$$21);
									zephir_array_fetch_string(&_46$$21, &file, SL("size"), PH_NOISY, "phalcon/Http/Request.zep", 796 TSRMLS_CC);
									zephir_array_update_string(&_45$$21, SL("size"), &_46$$21, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_46$$21);
									zephir_array_fetch_string(&_46$$21, &file, SL("error"), PH_NOISY, "phalcon/Http/Request.zep", 798 TSRMLS_CC);
									zephir_array_update_string(&_45$$21, SL("error"), &_46$$21, PH_COPY | PH_SEPARATE);
									ZEPHIR_CPY_WRT(&dataFile, &_45$$21);
									if (namedKeys == 1) {
										ZEPHIR_INIT_NVAR(&_47$$22);
										object_init_ex(&_47$$22, phalcon_http_request_file_ce);
										zephir_array_fetch_string(&_48$$22, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 804 TSRMLS_CC);
										ZEPHIR_CALL_METHOD(NULL, &_47$$22, "__construct", &_18, 343, &dataFile, &_48$$22);
										zephir_check_call_status();
										ZEPHIR_OBS_NVAR(&_49$$22);
										zephir_array_fetch_string(&_49$$22, &file, SL("key"), PH_NOISY, "phalcon/Http/Request.zep", 801 TSRMLS_CC);
										zephir_array_update_zval(&files, &_49$$22, &_47$$22, PH_COPY | PH_SEPARATE);
									} else {
										ZEPHIR_INIT_NVAR(&_50$$23);
										object_init_ex(&_50$$23, phalcon_http_request_file_ce);
										zephir_array_fetch_string(&_51$$23, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 809 TSRMLS_CC);
										ZEPHIR_CALL_METHOD(NULL, &_50$$23, "__construct", &_18, 343, &dataFile, &_51$$23);
										zephir_check_call_status();
										zephir_array_append(&files, &_50$$23, PH_SEPARATE, "phalcon/Http/Request.zep", 809);
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &smoothInput, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_42$$19, &smoothInput, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_42$$19)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&file, &smoothInput, "current", NULL, 0);
								zephir_check_call_status();
									_52$$24 = onlySuccessful == 0;
									if (!(_52$$24)) {
										zephir_array_fetch_string(&_53$$24, &file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 791 TSRMLS_CC);
										_52$$24 = ZEPHIR_IS_LONG(&_53$$24, 0);
									}
									if (_52$$24) {
										ZEPHIR_INIT_NVAR(&_54$$25);
										zephir_create_array(&_54$$25, 5, 0 TSRMLS_CC);
										ZEPHIR_OBS_NVAR(&_55$$25);
										zephir_array_fetch_string(&_55$$25, &file, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 793 TSRMLS_CC);
										zephir_array_update_string(&_54$$25, SL("name"), &_55$$25, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_55$$25);
										zephir_array_fetch_string(&_55$$25, &file, SL("type"), PH_NOISY, "phalcon/Http/Request.zep", 794 TSRMLS_CC);
										zephir_array_update_string(&_54$$25, SL("type"), &_55$$25, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_55$$25);
										zephir_array_fetch_string(&_55$$25, &file, SL("tmp_name"), PH_NOISY, "phalcon/Http/Request.zep", 795 TSRMLS_CC);
										zephir_array_update_string(&_54$$25, SL("tmp_name"), &_55$$25, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_55$$25);
										zephir_array_fetch_string(&_55$$25, &file, SL("size"), PH_NOISY, "phalcon/Http/Request.zep", 796 TSRMLS_CC);
										zephir_array_update_string(&_54$$25, SL("size"), &_55$$25, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_55$$25);
										zephir_array_fetch_string(&_55$$25, &file, SL("error"), PH_NOISY, "phalcon/Http/Request.zep", 798 TSRMLS_CC);
										zephir_array_update_string(&_54$$25, SL("error"), &_55$$25, PH_COPY | PH_SEPARATE);
										ZEPHIR_CPY_WRT(&dataFile, &_54$$25);
										if (namedKeys == 1) {
											ZEPHIR_INIT_NVAR(&_56$$26);
											object_init_ex(&_56$$26, phalcon_http_request_file_ce);
											zephir_array_fetch_string(&_57$$26, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 804 TSRMLS_CC);
											ZEPHIR_CALL_METHOD(NULL, &_56$$26, "__construct", &_18, 343, &dataFile, &_57$$26);
											zephir_check_call_status();
											ZEPHIR_OBS_NVAR(&_58$$26);
											zephir_array_fetch_string(&_58$$26, &file, SL("key"), PH_NOISY, "phalcon/Http/Request.zep", 801 TSRMLS_CC);
											zephir_array_update_zval(&files, &_58$$26, &_56$$26, PH_COPY | PH_SEPARATE);
										} else {
											ZEPHIR_INIT_NVAR(&_59$$27);
											object_init_ex(&_59$$27, phalcon_http_request_file_ce);
											zephir_array_fetch_string(&_60$$27, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 809 TSRMLS_CC);
											ZEPHIR_CALL_METHOD(NULL, &_59$$27, "__construct", &_18, 343, &dataFile, &_60$$27);
											zephir_check_call_status();
											zephir_array_append(&files, &_59$$27, PH_SEPARATE, "phalcon/Http/Request.zep", 809);
										}
									}
								ZEPHIR_CALL_METHOD(NULL, &smoothInput, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&file);
					} else {
						_61$$28 = onlySuccessful == 0;
						if (!(_61$$28)) {
							zephir_array_fetch_string(&_62$$28, &input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 814 TSRMLS_CC);
							_61$$28 = ZEPHIR_IS_LONG(&_62$$28, 0);
						}
						if (_61$$28) {
							if (namedKeys == 1) {
								ZEPHIR_INIT_NVAR(&_63$$30);
								object_init_ex(&_63$$30, phalcon_http_request_file_ce);
								ZEPHIR_CALL_METHOD(NULL, &_63$$30, "__construct", &_18, 343, &input, &prefix);
								zephir_check_call_status();
								zephir_array_update_zval(&files, &prefix, &_63$$30, PH_COPY | PH_SEPARATE);
							} else {
								ZEPHIR_INIT_NVAR(&_64$$31);
								object_init_ex(&_64$$31, phalcon_http_request_file_ce);
								ZEPHIR_CALL_METHOD(NULL, &_64$$31, "__construct", &_18, 343, &input, &prefix);
								zephir_check_call_status();
								zephir_array_append(&files, &_64$$31, PH_SEPARATE, "phalcon/Http/Request.zep", 818);
							}
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &superFiles, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&input);
		ZEPHIR_INIT_NVAR(&prefix);
	}
	RETURN_CTOR(&files);

}

/**
 * Gets HTTP URI which request has been made
 */
PHP_METHOD(Phalcon_Http_Request, getURI) {

	zval _SERVER, requestURI;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&requestURI);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (!(zephir_array_isset_string_fetch(&requestURI, &_SERVER, SL("REQUEST_URI"), 1))) {
		RETURN_STRING("");
	}
	RETURN_CTORW(&requestURI);

}

/**
 * Gets HTTP user agent used to made the request
 */
PHP_METHOD(Phalcon_Http_Request, getUserAgent) {

	zval _SERVER, userAgent;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&userAgent);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (!(zephir_array_isset_string_fetch(&userAgent, &_SERVER, SL("HTTP_USER_AGENT"), 1))) {
		RETURN_STRING("");
	}
	RETURN_CTORW(&userAgent);

}

/**
 * Checks whether $_REQUEST superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, has) {

	zval *name_param = NULL, _REQUEST;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_REQUEST);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	RETURN_MM_BOOL(zephir_array_isset(&_REQUEST, &name));

}

/**
 * Returns the number of files available
 *
 * TODO: Check this
 */
PHP_METHOD(Phalcon_Http_Request, hasFiles) {

	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zval *onlySuccessful_param = NULL, _FILES, files, file, error, *_0, _1, _3$$8, _4$$8, _7$$13, _8$$13;
	zend_bool onlySuccessful, _2$$6, _6$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$13);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_fetch_params(1, 0, 1, &onlySuccessful_param);

	if (!onlySuccessful_param) {
		onlySuccessful = 0;
	} else {
		onlySuccessful = zephir_get_boolval(onlySuccessful_param);
	}


	numberFiles = 0;
	ZEPHIR_CPY_WRT(&files, &_FILES);
	if (Z_TYPE_P(&files) != IS_ARRAY) {
		RETURN_MM_LONG(0);
	}
	zephir_is_iterable(&files, 0, "phalcon/Http/Request.zep", 897);
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&files), _0)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _0);
			ZEPHIR_OBS_NVAR(&error);
			if (zephir_array_isset_string_fetch(&error, &file, SL("error"), 0)) {
				if (Z_TYPE_P(&error) != IS_ARRAY) {
					_2$$6 = !zephir_is_true(&error);
					if (!(_2$$6)) {
						_2$$6 = !onlySuccessful;
					}
					if (_2$$6) {
						numberFiles++;
					}
				}
				if (Z_TYPE_P(&error) == IS_ARRAY) {
					if (onlySuccessful) {
						ZVAL_BOOL(&_4$$8, 1);
					} else {
						ZVAL_BOOL(&_4$$8, 0);
					}
					ZEPHIR_CALL_METHOD(&_3$$8, this_ptr, "hasfilehelper", &_5, 344, &error, &_4$$8);
					zephir_check_call_status();
					numberFiles += zephir_get_numberval(&_3$$8);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &files, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &files, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &files, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&error);
				if (zephir_array_isset_string_fetch(&error, &file, SL("error"), 0)) {
					if (Z_TYPE_P(&error) != IS_ARRAY) {
						_6$$11 = !zephir_is_true(&error);
						if (!(_6$$11)) {
							_6$$11 = !onlySuccessful;
						}
						if (_6$$11) {
							numberFiles++;
						}
					}
					if (Z_TYPE_P(&error) == IS_ARRAY) {
						if (onlySuccessful) {
							ZVAL_BOOL(&_8$$13, 1);
						} else {
							ZVAL_BOOL(&_8$$13, 0);
						}
						ZEPHIR_CALL_METHOD(&_7$$13, this_ptr, "hasfilehelper", &_5, 344, &error, &_8$$13);
						zephir_check_call_status();
						numberFiles += zephir_get_numberval(&_7$$13);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &files, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	RETURN_MM_LONG(numberFiles);

}

/**
 * Checks whether headers has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasHeader) {

	zend_bool _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *header_param = NULL, _SERVER, name, _0, _1, _2, _4;
	zval header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &header_param);

	if (UNEXPECTED(Z_TYPE_P(header_param) != IS_STRING && Z_TYPE_P(header_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'header' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(header_param) == IS_STRING)) {
		zephir_get_strval(&header, header_param);
	} else {
		ZEPHIR_INIT_VAR(&header);
		ZVAL_EMPTY_STRING(&header);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "-");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_");
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 80, &header, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	zephir_fast_strtoupper(&name, &_2);
	_3 = zephir_array_isset(&_SERVER, &name);
	if (!(_3)) {
		ZEPHIR_INIT_VAR(&_4);
		ZEPHIR_CONCAT_SV(&_4, "HTTP_", &name);
		_3 = zephir_array_isset(&_SERVER, &_4);
	}
	RETURN_MM_BOOL(_3);

}

/**
 * Checks whether $_POST superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPost) {

	zval *name_param = NULL, _POST;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_POST);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	RETURN_MM_BOOL(zephir_array_isset(&_POST, &name));

}

/**
 * Checks whether the PUT data has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPut) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, put;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&put);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_CALL_METHOD(&put, this_ptr, "getput", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_isset(&put, &name));

}

/**
 * Checks whether $_GET superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasQuery) {

	zval *name_param = NULL, _GET;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_GET);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	RETURN_MM_BOOL(zephir_array_isset(&_GET, &name));

}

/**
 * Checks whether $_SERVER superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasServer) {

	zval *name_param = NULL, _SERVER;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_SERVER);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	RETURN_MM_BOOL(zephir_array_isset(&_SERVER, &name));

}

/**
 * Checks whether request has been made using ajax
 */
PHP_METHOD(Phalcon_Http_Request, isAjax) {

	zend_bool _0;
	zval _SERVER, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_1);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	_0 = zephir_array_isset_string(&_SERVER, SL("HTTP_X_REQUESTED_WITH"));
	if (_0) {
		zephir_array_fetch_string(&_1, &_SERVER, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 953 TSRMLS_CC);
		_0 = ZEPHIR_IS_STRING_IDENTICAL(&_1, "XMLHttpRequest");
	}
	RETURN_BOOL(_0);

}

/**
 * Checks whether HTTP method is CONNECT.
 * if _SERVER["REQUEST_METHOD"]==="CONNECT"
 */
PHP_METHOD(Phalcon_Http_Request, isConnect) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 345);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "CONNECT"));

}

/**
 * Checks whether HTTP method is DELETE.
 * if _SERVER["REQUEST_METHOD"]==="DELETE"
 */
PHP_METHOD(Phalcon_Http_Request, isDelete) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 345);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "DELETE"));

}

/**
 * Checks whether HTTP method is GET.
 * if _SERVER["REQUEST_METHOD"]==="GET"
 */
PHP_METHOD(Phalcon_Http_Request, isGet) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 345);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "GET"));

}

/**
 * Checks whether HTTP method is HEAD.
 * if _SERVER["REQUEST_METHOD"]==="HEAD"
 */
PHP_METHOD(Phalcon_Http_Request, isHead) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 345);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "HEAD"));

}

/**
 * Check if HTTP method match any of the passed methods
 * When strict is true it checks if validated methods are real HTTP methods
 */
PHP_METHOD(Phalcon_Http_Request, isMethod) {

	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool strict, _0$$3;
	zval *methods, methods_sub, *strict_param = NULL, httpMethod, method, _1$$3, _2$$4, _3$$4, *_4$$5, _5$$5, _6$$6, _7$$6, _9$$8, _10$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&methods_sub);
	ZVAL_UNDEF(&httpMethod);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &methods, &strict_param);

	if (!strict_param) {
		strict = 0;
	} else {
		strict = zephir_get_boolval(strict_param);
	}


	ZEPHIR_CALL_METHOD(&httpMethod, this_ptr, "getmethod", NULL, 345);
	zephir_check_call_status();
	if (Z_TYPE_P(methods) == IS_STRING) {
		_0$$3 = strict;
		if (_0$$3) {
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "isvalidhttpmethod", NULL, 0, methods);
			zephir_check_call_status();
			_0$$3 = !zephir_is_true(&_1$$3);
		}
		if (UNEXPECTED(_0$$3)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_http_request_exception_ce);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_CONCAT_SV(&_3$$4, "Invalid HTTP method: ", methods);
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 1, &_3$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "phalcon/Http/Request.zep", 1004 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(methods, &httpMethod));
	}
	if (Z_TYPE_P(methods) == IS_ARRAY) {
		zephir_is_iterable(methods, 0, "phalcon/Http/Request.zep", 1017);
		if (Z_TYPE_P(methods) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(methods), _4$$5)
			{
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _4$$5);
				if (strict) {
					ZVAL_BOOL(&_7$$6, 1);
				} else {
					ZVAL_BOOL(&_7$$6, 0);
				}
				ZEPHIR_CALL_METHOD(&_6$$6, this_ptr, "ismethod", &_8, 346, &method, &_7$$6);
				zephir_check_call_status();
				if (zephir_is_true(&_6$$6)) {
					RETURN_MM_BOOL(1);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, methods, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$5, methods, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&method, methods, "current", NULL, 0);
				zephir_check_call_status();
					if (strict) {
						ZVAL_BOOL(&_10$$8, 1);
					} else {
						ZVAL_BOOL(&_10$$8, 0);
					}
					ZEPHIR_CALL_METHOD(&_9$$8, this_ptr, "ismethod", &_8, 346, &method, &_10$$8);
					zephir_check_call_status();
					if (zephir_is_true(&_9$$8)) {
						RETURN_MM_BOOL(1);
					}
				ZEPHIR_CALL_METHOD(NULL, methods, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&method);
		RETURN_MM_BOOL(0);
	}
	if (UNEXPECTED(strict)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "Invalid HTTP method: non-string", "phalcon/Http/Request.zep", 1021);
		return;
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks whether HTTP method is OPTIONS.
 * if _SERVER["REQUEST_METHOD"]==="OPTIONS"
 */
PHP_METHOD(Phalcon_Http_Request, isOptions) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 345);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "OPTIONS"));

}

/**
 * Checks whether HTTP method is PATCH.
 * if _SERVER["REQUEST_METHOD"]==="PATCH"
 */
PHP_METHOD(Phalcon_Http_Request, isPatch) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 345);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "PATCH"));

}

/**
 * Checks whether HTTP method is POST.
 * if _SERVER["REQUEST_METHOD"]==="POST"
 */
PHP_METHOD(Phalcon_Http_Request, isPost) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 345);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "POST"));

}

/**
 * Checks whether HTTP method is PUT.
 * if _SERVER["REQUEST_METHOD"]==="PUT"
 */
PHP_METHOD(Phalcon_Http_Request, isPut) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 345);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "PUT"));

}

/**
 * Checks whether HTTP method is PURGE (Squid and Varnish support).
 * if _SERVER["REQUEST_METHOD"]==="PURGE"
 */
PHP_METHOD(Phalcon_Http_Request, isPurge) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 345);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "PURGE"));

}

/**
 * Checks whether request has been made using any secure layer
 */
PHP_METHOD(Phalcon_Http_Request, isSecure) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getscheme", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "https"));

}

/**
 * Checks if the `Request::getHttpHost` method will be use strict validation
 * of host name or not
 */
PHP_METHOD(Phalcon_Http_Request, isStrictHostCheck) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "strictHostCheck");

}

/**
 * Checks whether request has been made using SOAP
 */
PHP_METHOD(Phalcon_Http_Request, isSoap) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, contentType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&contentType);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string(&_SERVER, SL("HTTP_SOAPACTION"))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&contentType)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(zephir_memnstr_str(&contentType, SL("application/soap+xml"), "phalcon/Http/Request.zep", 1106));

}

/**
 * Checks whether HTTP method is TRACE.
 * if _SERVER["REQUEST_METHOD"]==="TRACE"
 */
PHP_METHOD(Phalcon_Http_Request, isTrace) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 345);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "TRACE"));

}

/**
 * Checks if a method is a valid HTTP method
 */
PHP_METHOD(Phalcon_Http_Request, isValidHttpMethod) {

	zval *method_param = NULL, _0;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(&method, method_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtoupper(&_0, &method);
	do {
		if (ZEPHIR_IS_STRING(&_0, "GET") || ZEPHIR_IS_STRING(&_0, "POST") || ZEPHIR_IS_STRING(&_0, "PUT") || ZEPHIR_IS_STRING(&_0, "DELETE") || ZEPHIR_IS_STRING(&_0, "HEAD") || ZEPHIR_IS_STRING(&_0, "OPTIONS") || ZEPHIR_IS_STRING(&_0, "PATCH") || ZEPHIR_IS_STRING(&_0, "PURGE") || ZEPHIR_IS_STRING(&_0, "TRACE") || ZEPHIR_IS_STRING(&_0, "CONNECT")) {
			RETURN_MM_BOOL(1);
		}
	} while(0);

	RETURN_MM_BOOL(0);

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Http_Request, setDI) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

/**
 * Sets automatic sanitizers/filters for a particular field and for
 * particular methods
 */
PHP_METHOD(Phalcon_Http_Request, setParameterFilters) {

	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filters, scope;
	zval *name_param = NULL, *filters_param = NULL, *scope_param = NULL, filterService, sanitizer, localScope, scopeMethod, *_2, _3, *_13, _14, _0$$3, _4$$4, _6$$5, _7$$5, _8$$6, _10$$7, _11$$7, _12$$8;
	zval name, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&sanitizer);
	ZVAL_UNDEF(&localScope);
	ZVAL_UNDEF(&scopeMethod);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&scope);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &filters_param, &scope_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!filters_param) {
		ZEPHIR_INIT_VAR(&filters);
		array_init(&filters);
	} else {
		zephir_get_arrval(&filters, filters_param);
	}
	if (!scope_param) {
		ZEPHIR_INIT_VAR(&scope);
		array_init(&scope);
	} else {
		zephir_get_arrval(&scope, scope_param);
	}


	if (UNEXPECTED(zephir_fast_count_int(&filters TSRMLS_CC) < 1)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_http_request_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVS(&_1$$3, "Filters have not been defined for '", &name, "'");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 1, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Http/Request.zep", 1159 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&filterService, this_ptr, "getfilterservice", NULL, 347);
	zephir_check_call_status();
	zephir_is_iterable(&filters, 0, "phalcon/Http/Request.zep", 1172);
	if (Z_TYPE_P(&filters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&filters), _2)
		{
			ZEPHIR_INIT_NVAR(&sanitizer);
			ZVAL_COPY(&sanitizer, _2);
			ZEPHIR_CALL_METHOD(&_4$$4, &filterService, "has", &_5, 0, &sanitizer);
			zephir_check_call_status();
			if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_4$$4))) {
				ZEPHIR_INIT_NVAR(&_6$$5);
				object_init_ex(&_6$$5, phalcon_http_request_exception_ce);
				ZEPHIR_INIT_LNVAR(_7$$5);
				ZEPHIR_CONCAT_SVS(&_7$$5, "Sanitizer '", &sanitizer, "' does not exist in the filter locator");
				ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 1, &_7$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$5, "phalcon/Http/Request.zep", 1168 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &filters, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &filters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&sanitizer, &filters, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$6, &filterService, "has", &_9, 0, &sanitizer);
				zephir_check_call_status();
				if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_8$$6))) {
					ZEPHIR_INIT_NVAR(&_10$$7);
					object_init_ex(&_10$$7, phalcon_http_request_exception_ce);
					ZEPHIR_INIT_LNVAR(_11$$7);
					ZEPHIR_CONCAT_SVS(&_11$$7, "Sanitizer '", &sanitizer, "' does not exist in the filter locator");
					ZEPHIR_CALL_METHOD(NULL, &_10$$7, "__construct", NULL, 1, &_11$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$7, "phalcon/Http/Request.zep", 1168 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			ZEPHIR_CALL_METHOD(NULL, &filters, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&sanitizer);
	if (zephir_fast_count_int(&scope TSRMLS_CC) < 1) {
		ZEPHIR_INIT_VAR(&localScope);
		zephir_create_array(&localScope, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_12$$8);
		ZVAL_STRING(&_12$$8, "get");
		zephir_array_fast_append(&localScope, &_12$$8);
		ZEPHIR_INIT_NVAR(&_12$$8);
		ZVAL_STRING(&_12$$8, "post");
		zephir_array_fast_append(&localScope, &_12$$8);
		ZEPHIR_INIT_NVAR(&_12$$8);
		ZVAL_STRING(&_12$$8, "put");
		zephir_array_fast_append(&localScope, &_12$$8);
	} else {
		ZEPHIR_CPY_WRT(&localScope, &scope);
	}
	zephir_is_iterable(&localScope, 0, "phalcon/Http/Request.zep", 1182);
	if (Z_TYPE_P(&localScope) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&localScope), _13)
		{
			ZEPHIR_INIT_NVAR(&scopeMethod);
			ZVAL_COPY(&scopeMethod, _13);
			zephir_update_property_array_multi(this_ptr, SL("queryFilters"), &filters TSRMLS_CC, SL("zz"), 2, &scopeMethod, &name);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &localScope, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_14, &localScope, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&scopeMethod, &localScope, "current", NULL, 0);
			zephir_check_call_status();
				zephir_update_property_array_multi(this_ptr, SL("queryFilters"), &filters TSRMLS_CC, SL("zz"), 2, &scopeMethod, &name);
			ZEPHIR_CALL_METHOD(NULL, &localScope, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&scopeMethod);
	RETURN_THIS();

}

/**
 * Sets if the `Request::getHttpHost` method must be use strict validation
 * of host name or not
 */
PHP_METHOD(Phalcon_Http_Request, setStrictHostCheck) {

	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 0, 1, &flag_param);

	if (!flag_param) {
		flag = 1;
	} else {
		flag = zephir_get_boolval(flag_param);
	}


	if (flag) {
		zephir_update_property_zval(this_ptr, SL("strictHostCheck"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("strictHostCheck"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Process a request header and return the one with best quality
 */
PHP_METHOD(Phalcon_Http_Request, getBestQuality) {

	double quality = 0, acceptQuality = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0;
	zval name;
	zval *qualityParts_param = NULL, *name_param = NULL, selectedName, accept, *_0, _1, _2$$4, _3$$5, _4$$8, _5$$9;
	zval qualityParts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&qualityParts);
	ZVAL_UNDEF(&selectedName);
	ZVAL_UNDEF(&accept);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &qualityParts_param, &name_param);

	zephir_get_arrval(&qualityParts, qualityParts_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	i = 0;
	quality = 0.0;
	ZEPHIR_INIT_VAR(&selectedName);
	ZVAL_STRING(&selectedName, "");
	zephir_is_iterable(&qualityParts, 0, "phalcon/Http/Request.zep", 1225);
	if (Z_TYPE_P(&qualityParts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&qualityParts), _0)
		{
			ZEPHIR_INIT_NVAR(&accept);
			ZVAL_COPY(&accept, _0);
			if (i == 0) {
				ZEPHIR_OBS_NVAR(&_2$$4);
				zephir_array_fetch_string(&_2$$4, &accept, SL("quality"), PH_NOISY, "phalcon/Http/Request.zep", 1211 TSRMLS_CC);
				quality = zephir_get_doubleval(&_2$$4);
				ZEPHIR_OBS_NVAR(&selectedName);
				zephir_array_fetch(&selectedName, &accept, &name, PH_NOISY, "phalcon/Http/Request.zep", 1212 TSRMLS_CC);
			} else {
				ZEPHIR_OBS_NVAR(&_3$$5);
				zephir_array_fetch_string(&_3$$5, &accept, SL("quality"), PH_NOISY, "phalcon/Http/Request.zep", 1214 TSRMLS_CC);
				acceptQuality = zephir_get_doubleval(&_3$$5);
				if (acceptQuality > quality) {
					quality = acceptQuality;
					ZEPHIR_OBS_NVAR(&selectedName);
					zephir_array_fetch(&selectedName, &accept, &name, PH_NOISY, "phalcon/Http/Request.zep", 1218 TSRMLS_CC);
				}
			}
			i++;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &qualityParts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &qualityParts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&accept, &qualityParts, "current", NULL, 0);
			zephir_check_call_status();
				if (i == 0) {
					ZEPHIR_OBS_NVAR(&_4$$8);
					zephir_array_fetch_string(&_4$$8, &accept, SL("quality"), PH_NOISY, "phalcon/Http/Request.zep", 1211 TSRMLS_CC);
					quality = zephir_get_doubleval(&_4$$8);
					ZEPHIR_OBS_NVAR(&selectedName);
					zephir_array_fetch(&selectedName, &accept, &name, PH_NOISY, "phalcon/Http/Request.zep", 1212 TSRMLS_CC);
				} else {
					ZEPHIR_OBS_NVAR(&_5$$9);
					zephir_array_fetch_string(&_5$$9, &accept, SL("quality"), PH_NOISY, "phalcon/Http/Request.zep", 1214 TSRMLS_CC);
					acceptQuality = zephir_get_doubleval(&_5$$9);
					if (acceptQuality > quality) {
						quality = acceptQuality;
						ZEPHIR_OBS_NVAR(&selectedName);
						zephir_array_fetch(&selectedName, &accept, &name, PH_NOISY, "phalcon/Http/Request.zep", 1218 TSRMLS_CC);
					}
				}
				i++;
			ZEPHIR_CALL_METHOD(NULL, &qualityParts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&accept);
	RETURN_CCTOR(&selectedName);

}

/**
 * Helper to get data from superglobals, applying filters if needed.
 * If no parameters are given the superglobal is returned.
 */
PHP_METHOD(Phalcon_Http_Request, getHelper) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive, _2;
	zval name;
	zval *source_param = NULL, *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, value, filterService, _0$$5, _1$$5;
	zval source;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &source_param, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	zephir_get_arrval(&source, source_param);
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&name, "")) {
		RETURN_CTOR(&source);
	}
	ZEPHIR_OBS_VAR(&value);
	if (!(zephir_array_isset_fetch(&value, &source, &name, 0 TSRMLS_CC))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(filters) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&filterService, this_ptr, "getfilterservice", NULL, 347);
		zephir_check_call_status();
		if (noRecursive) {
			ZVAL_BOOL(&_1$$5, 1);
		} else {
			ZVAL_BOOL(&_1$$5, 0);
		}
		ZEPHIR_CALL_METHOD(&_0$$5, &filterService, "sanitize", NULL, 0, &value, filters, &_1$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&value, &_0$$5);
	}
	_2 = ZEPHIR_IS_EMPTY(&value);
	if (_2) {
		_2 = notAllowEmpty;
	}
	if (_2) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CCTOR(&value);

}

/**
 * Recursively counts file in an array of files
 */
PHP_METHOD(Phalcon_Http_Request, hasFileHelper) {

	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zend_bool onlySuccessful, _2$$5, _6$$9;
	zval *data, data_sub, *onlySuccessful_param = NULL, value, *_0, _1, _3$$7, _4$$7, _7$$11, _8$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data, &onlySuccessful_param);

	onlySuccessful = zephir_get_boolval(onlySuccessful_param);


	numberFiles = 0;
	if (Z_TYPE_P(data) != IS_ARRAY) {
		RETURN_MM_LONG(1);
	}
	zephir_is_iterable(data, 0, "phalcon/Http/Request.zep", 1280);
	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(data), _0)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (Z_TYPE_P(&value) != IS_ARRAY) {
				_2$$5 = !zephir_is_true(&value);
				if (!(_2$$5)) {
					_2$$5 = !onlySuccessful;
				}
				if (_2$$5) {
					numberFiles++;
				}
			}
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				if (onlySuccessful) {
					ZVAL_BOOL(&_4$$7, 1);
				} else {
					ZVAL_BOOL(&_4$$7, 0);
				}
				ZEPHIR_CALL_METHOD(&_3$$7, this_ptr, "hasfilehelper", &_5, 344, &value, &_4$$7);
				zephir_check_call_status();
				numberFiles += zephir_get_numberval(&_3$$7);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, data, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&value) != IS_ARRAY) {
					_6$$9 = !zephir_is_true(&value);
					if (!(_6$$9)) {
						_6$$9 = !onlySuccessful;
					}
					if (_6$$9) {
						numberFiles++;
					}
				}
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					if (onlySuccessful) {
						ZVAL_BOOL(&_8$$11, 1);
					} else {
						ZVAL_BOOL(&_8$$11, 0);
					}
					ZEPHIR_CALL_METHOD(&_7$$11, this_ptr, "hasfilehelper", &_5, 344, &value, &_8$$11);
					zephir_check_call_status();
					numberFiles += zephir_get_numberval(&_7$$11);
				}
			ZEPHIR_CALL_METHOD(NULL, data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	RETURN_MM_LONG(numberFiles);

}

/**
 * Process a request header and return an array of values with their qualities
 */
PHP_METHOD(Phalcon_Http_Request, getQualityHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serverIndex_param = NULL, *name_param = NULL, returnedParts, parts, part, headerParts, headerPart, split, _0, _1, _2, _3, *_4, _5, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, *_11$$3, _12$$3, _13$$4, _14$$4, _15$$5, _16$$6, _17$$6, _18$$7, _19$$7, _20$$8, _21$$9, _22$$9, _23$$10, _24$$11, _25$$11, _26$$12, _27$$12, _28$$13, _29$$14, _30$$14, _31$$14, _32$$14, _33$$14, *_34$$14, _35$$14, _36$$15, _37$$15, _38$$16, _39$$17, _40$$17, _41$$18, _42$$18, _43$$19, _44$$20, _45$$20, _46$$21, _47$$22, _48$$22, _49$$23, _50$$23, _51$$24;
	zval serverIndex, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serverIndex);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&returnedParts);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&headerParts);
	ZVAL_UNDEF(&headerPart);
	ZVAL_UNDEF(&split);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$13);
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_33$$14);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_36$$15);
	ZVAL_UNDEF(&_37$$15);
	ZVAL_UNDEF(&_38$$16);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_41$$18);
	ZVAL_UNDEF(&_42$$18);
	ZVAL_UNDEF(&_43$$19);
	ZVAL_UNDEF(&_44$$20);
	ZVAL_UNDEF(&_45$$20);
	ZVAL_UNDEF(&_46$$21);
	ZVAL_UNDEF(&_47$$22);
	ZVAL_UNDEF(&_48$$22);
	ZVAL_UNDEF(&_49$$23);
	ZVAL_UNDEF(&_50$$23);
	ZVAL_UNDEF(&_51$$24);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &serverIndex_param, &name_param);

	if (UNEXPECTED(Z_TYPE_P(serverIndex_param) != IS_STRING && Z_TYPE_P(serverIndex_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serverIndex' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serverIndex_param) == IS_STRING)) {
		zephir_get_strval(&serverIndex, serverIndex_param);
	} else {
		ZEPHIR_INIT_VAR(&serverIndex);
		ZVAL_EMPTY_STRING(&serverIndex);
	}
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_INIT_VAR(&returnedParts);
	array_init(&returnedParts);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getserver", NULL, 0, &serverIndex);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/,\\s*/");
	ZVAL_LONG(&_2, -1);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&parts, "preg_split", NULL, 87, &_1, &_0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&parts, 0, "phalcon/Http/Request.zep", 1320);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parts), _4)
		{
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _4);
			ZEPHIR_INIT_NVAR(&headerParts);
			array_init(&headerParts);
			ZEPHIR_INIT_NVAR(&_6$$3);
			zephir_fast_trim(&_6$$3, &part, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZVAL_STRING(&_7$$3, "/\\s*;\\s*/");
			ZVAL_LONG(&_8$$3, -1);
			ZVAL_LONG(&_9$$3, 1);
			ZEPHIR_CALL_FUNCTION(&_10$$3, "preg_split", NULL, 87, &_7$$3, &_6$$3, &_8$$3, &_9$$3);
			zephir_check_call_status();
			zephir_is_iterable(&_10$$3, 0, "phalcon/Http/Request.zep", 1317);
			if (Z_TYPE_P(&_10$$3) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_10$$3), _11$$3)
				{
					ZEPHIR_INIT_NVAR(&headerPart);
					ZVAL_COPY(&headerPart, _11$$3);
					ZEPHIR_INIT_NVAR(&_13$$4);
					ZVAL_STRING(&_13$$4, "=");
					ZEPHIR_INIT_NVAR(&_14$$4);
					zephir_fast_strpos(&_14$$4, &headerPart, &_13$$4, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_14$$4)) {
						ZEPHIR_INIT_NVAR(&split);
						zephir_fast_explode_str(&split, SL("="), &headerPart, 2  TSRMLS_CC);
						zephir_array_fetch_long(&_15$$5, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1306 TSRMLS_CC);
						if (ZEPHIR_IS_STRING_IDENTICAL(&_15$$5, "q")) {
							ZEPHIR_OBS_NVAR(&_16$$6);
							zephir_array_fetch_long(&_16$$6, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1307 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(&_17$$6);
							ZVAL_DOUBLE(&_17$$6, zephir_get_doubleval(&_16$$6));
							zephir_array_update_string(&headerParts, SL("quality"), &_17$$6, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_fetch_long(&_18$$7, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1309 TSRMLS_CC);
							ZEPHIR_OBS_NVAR(&_19$$7);
							zephir_array_fetch_long(&_19$$7, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1309 TSRMLS_CC);
							zephir_array_update_zval(&headerParts, &_19$$7, &_18$$7, PH_COPY | PH_SEPARATE);
						}
					} else {
						zephir_array_update_zval(&headerParts, &name, &headerPart, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_20$$8);
						ZVAL_DOUBLE(&_20$$8, 1.0);
						zephir_array_update_string(&headerParts, SL("quality"), &_20$$8, PH_COPY | PH_SEPARATE);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_10$$3, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_12$$3, &_10$$3, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_12$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&headerPart, &_10$$3, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_21$$9);
						ZVAL_STRING(&_21$$9, "=");
						ZEPHIR_INIT_NVAR(&_22$$9);
						zephir_fast_strpos(&_22$$9, &headerPart, &_21$$9, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_22$$9)) {
							ZEPHIR_INIT_NVAR(&split);
							zephir_fast_explode_str(&split, SL("="), &headerPart, 2  TSRMLS_CC);
							zephir_array_fetch_long(&_23$$10, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1306 TSRMLS_CC);
							if (ZEPHIR_IS_STRING_IDENTICAL(&_23$$10, "q")) {
								ZEPHIR_OBS_NVAR(&_24$$11);
								zephir_array_fetch_long(&_24$$11, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1307 TSRMLS_CC);
								ZEPHIR_INIT_NVAR(&_25$$11);
								ZVAL_DOUBLE(&_25$$11, zephir_get_doubleval(&_24$$11));
								zephir_array_update_string(&headerParts, SL("quality"), &_25$$11, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_fetch_long(&_26$$12, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1309 TSRMLS_CC);
								ZEPHIR_OBS_NVAR(&_27$$12);
								zephir_array_fetch_long(&_27$$12, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1309 TSRMLS_CC);
								zephir_array_update_zval(&headerParts, &_27$$12, &_26$$12, PH_COPY | PH_SEPARATE);
							}
						} else {
							zephir_array_update_zval(&headerParts, &name, &headerPart, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_28$$13);
							ZVAL_DOUBLE(&_28$$13, 1.0);
							zephir_array_update_string(&headerParts, SL("quality"), &_28$$13, PH_COPY | PH_SEPARATE);
						}
					ZEPHIR_CALL_METHOD(NULL, &_10$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&headerPart);
			zephir_array_append(&returnedParts, &headerParts, PH_SEPARATE, "phalcon/Http/Request.zep", 1317);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &parts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&part, &parts, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&headerParts);
				array_init(&headerParts);
				ZEPHIR_INIT_NVAR(&_29$$14);
				zephir_fast_trim(&_29$$14, &part, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_30$$14);
				ZVAL_STRING(&_30$$14, "/\\s*;\\s*/");
				ZVAL_LONG(&_31$$14, -1);
				ZVAL_LONG(&_32$$14, 1);
				ZEPHIR_CALL_FUNCTION(&_33$$14, "preg_split", NULL, 87, &_30$$14, &_29$$14, &_31$$14, &_32$$14);
				zephir_check_call_status();
				zephir_is_iterable(&_33$$14, 0, "phalcon/Http/Request.zep", 1317);
				if (Z_TYPE_P(&_33$$14) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_33$$14), _34$$14)
					{
						ZEPHIR_INIT_NVAR(&headerPart);
						ZVAL_COPY(&headerPart, _34$$14);
						ZEPHIR_INIT_NVAR(&_36$$15);
						ZVAL_STRING(&_36$$15, "=");
						ZEPHIR_INIT_NVAR(&_37$$15);
						zephir_fast_strpos(&_37$$15, &headerPart, &_36$$15, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_37$$15)) {
							ZEPHIR_INIT_NVAR(&split);
							zephir_fast_explode_str(&split, SL("="), &headerPart, 2  TSRMLS_CC);
							zephir_array_fetch_long(&_38$$16, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1306 TSRMLS_CC);
							if (ZEPHIR_IS_STRING_IDENTICAL(&_38$$16, "q")) {
								ZEPHIR_OBS_NVAR(&_39$$17);
								zephir_array_fetch_long(&_39$$17, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1307 TSRMLS_CC);
								ZEPHIR_INIT_NVAR(&_40$$17);
								ZVAL_DOUBLE(&_40$$17, zephir_get_doubleval(&_39$$17));
								zephir_array_update_string(&headerParts, SL("quality"), &_40$$17, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_fetch_long(&_41$$18, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1309 TSRMLS_CC);
								ZEPHIR_OBS_NVAR(&_42$$18);
								zephir_array_fetch_long(&_42$$18, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1309 TSRMLS_CC);
								zephir_array_update_zval(&headerParts, &_42$$18, &_41$$18, PH_COPY | PH_SEPARATE);
							}
						} else {
							zephir_array_update_zval(&headerParts, &name, &headerPart, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_43$$19);
							ZVAL_DOUBLE(&_43$$19, 1.0);
							zephir_array_update_string(&headerParts, SL("quality"), &_43$$19, PH_COPY | PH_SEPARATE);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_33$$14, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_35$$14, &_33$$14, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_35$$14)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&headerPart, &_33$$14, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_44$$20);
							ZVAL_STRING(&_44$$20, "=");
							ZEPHIR_INIT_NVAR(&_45$$20);
							zephir_fast_strpos(&_45$$20, &headerPart, &_44$$20, 0 );
							if (!ZEPHIR_IS_FALSE_IDENTICAL(&_45$$20)) {
								ZEPHIR_INIT_NVAR(&split);
								zephir_fast_explode_str(&split, SL("="), &headerPart, 2  TSRMLS_CC);
								zephir_array_fetch_long(&_46$$21, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1306 TSRMLS_CC);
								if (ZEPHIR_IS_STRING_IDENTICAL(&_46$$21, "q")) {
									ZEPHIR_OBS_NVAR(&_47$$22);
									zephir_array_fetch_long(&_47$$22, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1307 TSRMLS_CC);
									ZEPHIR_INIT_NVAR(&_48$$22);
									ZVAL_DOUBLE(&_48$$22, zephir_get_doubleval(&_47$$22));
									zephir_array_update_string(&headerParts, SL("quality"), &_48$$22, PH_COPY | PH_SEPARATE);
								} else {
									zephir_array_fetch_long(&_49$$23, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1309 TSRMLS_CC);
									ZEPHIR_OBS_NVAR(&_50$$23);
									zephir_array_fetch_long(&_50$$23, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1309 TSRMLS_CC);
									zephir_array_update_zval(&headerParts, &_50$$23, &_49$$23, PH_COPY | PH_SEPARATE);
								}
							} else {
								zephir_array_update_zval(&headerParts, &name, &headerPart, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_51$$24);
								ZVAL_DOUBLE(&_51$$24, 1.0);
								zephir_array_update_string(&headerParts, SL("quality"), &_51$$24, PH_COPY | PH_SEPARATE);
							}
						ZEPHIR_CALL_METHOD(NULL, &_33$$14, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&headerPart);
				zephir_array_append(&returnedParts, &headerParts, PH_SEPARATE, "phalcon/Http/Request.zep", 1317);
			ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	RETURN_CCTOR(&returnedParts);

}

/**
 * Resolve authorization headers.
 */
PHP_METHOD(Phalcon_Http_Request, resolveAuthorizationHeaders) {

	zval headers, _6$$5, _28$$19;
	zend_bool hasEventsManager = 0, _5, _9, _27, _15$$11;
	zval _SERVER, resolved, eventsManager, container, exploded, digest, authHeader, _0, _1$$3, _2$$3, _3$$4, _4$$4, _7$$5, _8$$6, _10$$7, _11$$7, _12$$11, _13$$11, _14$$11, _16$$11, _17$$12, _18$$12, _19$$12, _20$$13, _21$$13, _22$$17, _23$$17, _24$$17, _25$$17, _26$$17, _29$$19, _30$$20;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&exploded);
	ZVAL_UNDEF(&digest);
	ZVAL_UNDEF(&authHeader);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_28$$19);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&authHeader);
	ZVAL_NULL(&authHeader);
	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "eventsManager");
		ZEPHIR_CALL_METHOD(&_1$$3, &container, "has", NULL, 0, &_2$$3);
		zephir_check_call_status();
		hasEventsManager = zephir_get_boolval(&_1$$3);
		if (hasEventsManager) {
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "eventsManager");
			ZEPHIR_CALL_METHOD(&_3$$4, &container, "getshared", NULL, 0, &_4$$4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&eventsManager, &_3$$4);
		}
	}
	_5 = hasEventsManager;
	if (_5) {
		_5 = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	}
	if (_5) {
		ZEPHIR_INIT_VAR(&_6$$5);
		zephir_create_array(&_6$$5, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_6$$5, SL("server"), &_SERVER, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "request:beforeAuthorizationResolve");
		ZEPHIR_CALL_METHOD(&resolved, &eventsManager, "fire", NULL, 0, &_7$$5, this_ptr, &_6$$5);
		zephir_check_call_status();
		if (Z_TYPE_P(&resolved) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_8$$6);
			zephir_fast_array_merge(&_8$$6, &headers, &resolved TSRMLS_CC);
			ZEPHIR_CPY_WRT(&headers, &_8$$6);
		}
	}
	_9 = zephir_array_isset_string(&_SERVER, SL("PHP_AUTH_USER"));
	if (_9) {
		_9 = zephir_array_isset_string(&_SERVER, SL("PHP_AUTH_PW"));
	}
	if (_9) {
		zephir_array_fetch_string(&_10$$7, &_SERVER, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1358 TSRMLS_CC);
		zephir_array_update_string(&headers, SL("Php-Auth-User"), &_10$$7, PH_COPY | PH_SEPARATE);
		zephir_array_fetch_string(&_11$$7, &_SERVER, SL("PHP_AUTH_PW"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1359 TSRMLS_CC);
		zephir_array_update_string(&headers, SL("Php-Auth-Pw"), &_11$$7, PH_COPY | PH_SEPARATE);
	} else {
		if (zephir_array_isset_string(&_SERVER, SL("HTTP_AUTHORIZATION"))) {
			ZEPHIR_OBS_NVAR(&authHeader);
			zephir_array_fetch_string(&authHeader, &_SERVER, SL("HTTP_AUTHORIZATION"), PH_NOISY, "phalcon/Http/Request.zep", 1362 TSRMLS_CC);
		} else if (zephir_array_isset_string(&_SERVER, SL("REDIRECT_HTTP_AUTHORIZATION"))) {
			ZEPHIR_OBS_NVAR(&authHeader);
			zephir_array_fetch_string(&authHeader, &_SERVER, SL("REDIRECT_HTTP_AUTHORIZATION"), PH_NOISY, "phalcon/Http/Request.zep", 1364 TSRMLS_CC);
		}
		if (zephir_is_true(&authHeader)) {
			ZEPHIR_INIT_VAR(&_12$$11);
			ZVAL_STRING(&_12$$11, "basic ");
			ZEPHIR_CALL_FUNCTION(&_13$$11, "stripos", NULL, 340, &authHeader, &_12$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_12$$11);
			ZVAL_STRING(&_12$$11, "digest ");
			ZEPHIR_CALL_FUNCTION(&_14$$11, "stripos", NULL, 340, &authHeader, &_12$$11);
			zephir_check_call_status();
			_15$$11 = ZEPHIR_IS_LONG_IDENTICAL(&_14$$11, 0);
			if (_15$$11) {
				ZEPHIR_OBS_VAR(&digest);
				_15$$11 = !(zephir_array_isset_string_fetch(&digest, &_SERVER, SL("PHP_AUTH_DIGEST"), 0));
			}
			ZEPHIR_INIT_NVAR(&_12$$11);
			ZVAL_STRING(&_12$$11, "bearer ");
			ZEPHIR_CALL_FUNCTION(&_16$$11, "stripos", NULL, 340, &authHeader, &_12$$11);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_13$$11, 0)) {
				ZVAL_LONG(&_17$$12, 6);
				ZEPHIR_INIT_VAR(&_18$$12);
				zephir_substr(&_18$$12, &authHeader, 6 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CALL_FUNCTION(&_19$$12, "base64_decode", NULL, 169, &_18$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&exploded);
				zephir_fast_explode_str(&exploded, SL(":"), &_19$$12, 2  TSRMLS_CC);
				if (zephir_fast_count_int(&exploded TSRMLS_CC) == 2) {
					zephir_array_fetch_long(&_20$$13, &exploded, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1378 TSRMLS_CC);
					zephir_array_update_string(&headers, SL("Php-Auth-User"), &_20$$13, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_long(&_21$$13, &exploded, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1379 TSRMLS_CC);
					zephir_array_update_string(&headers, SL("Php-Auth-Pw"), &_21$$13, PH_COPY | PH_SEPARATE);
				}
			} else if (_15$$11) {
				zephir_array_update_string(&headers, SL("Php-Auth-Digest"), &authHeader, PH_COPY | PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_16$$11, 0)) {
				zephir_array_update_string(&headers, SL("Authorization"), &authHeader, PH_COPY | PH_SEPARATE);
			}
		}
	}
	if (!(zephir_array_isset_string(&headers, SL("Authorization")))) {
		ZEPHIR_OBS_NVAR(&digest);
		if (zephir_array_isset_string(&headers, SL("Php-Auth-User"))) {
			zephir_array_fetch_string(&_22$$17, &headers, SL("Php-Auth-User"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1391 TSRMLS_CC);
			zephir_array_fetch_string(&_23$$17, &headers, SL("Php-Auth-Pw"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1391 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_24$$17);
			ZEPHIR_CONCAT_VSV(&_24$$17, &_22$$17, ":", &_23$$17);
			ZEPHIR_CALL_FUNCTION(&_25$$17, "base64_encode", NULL, 172, &_24$$17);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_26$$17);
			ZEPHIR_CONCAT_SV(&_26$$17, "Basic ", &_25$$17);
			zephir_array_update_string(&headers, SL("Authorization"), &_26$$17, PH_COPY | PH_SEPARATE);
		} else if (zephir_array_isset_string_fetch(&digest, &headers, SL("Php-Auth-Digest"), 0)) {
			zephir_array_update_string(&headers, SL("Authorization"), &digest, PH_COPY | PH_SEPARATE);
		}
	}
	_27 = hasEventsManager;
	if (_27) {
		_27 = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	}
	if (_27) {
		ZEPHIR_INIT_VAR(&_28$$19);
		zephir_create_array(&_28$$19, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_28$$19, SL("headers"), &headers, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_28$$19, SL("server"), &_SERVER, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_29$$19);
		ZVAL_STRING(&_29$$19, "request:afterAuthorizationResolve");
		ZEPHIR_CALL_METHOD(&resolved, &eventsManager, "fire", NULL, 0, &_29$$19, this_ptr, &_28$$19);
		zephir_check_call_status();
		if (Z_TYPE_P(&resolved) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_30$$20);
			zephir_fast_array_merge(&_30$$20, &headers, &resolved TSRMLS_CC);
			ZEPHIR_CPY_WRT(&headers, &_30$$20);
		}
	}
	RETURN_CTOR(&headers);

}

/**
 * Smooth out $_FILES to have plain array with all files uploaded
 */
PHP_METHOD(Phalcon_Http_Request, smoothFiles) {

	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval prefix;
	zval *names_param = NULL, *types_param = NULL, *tmp_names_param = NULL, *sizes_param = NULL, *errors_param = NULL, *prefix_param = NULL, idx, name, file, files, parentFiles, p, *_0, _1, _5$$4, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, *_12$$5, _13$$5, _15$$9, _16$$10, _17$$10, _18$$10, _19$$10, _20$$10, *_21$$10, _22$$10;
	zval names, types, tmp_names, sizes, errors, _4$$4, _14$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&tmp_names);
	ZVAL_UNDEF(&sizes);
	ZVAL_UNDEF(&errors);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&idx);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&parentFiles);
	ZVAL_UNDEF(&p);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&prefix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 0, &names_param, &types_param, &tmp_names_param, &sizes_param, &errors_param, &prefix_param);

	ZEPHIR_OBS_COPY_OR_DUP(&names, names_param);
	ZEPHIR_OBS_COPY_OR_DUP(&types, types_param);
	ZEPHIR_OBS_COPY_OR_DUP(&tmp_names, tmp_names_param);
	ZEPHIR_OBS_COPY_OR_DUP(&sizes, sizes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&errors, errors_param);
	zephir_get_strval(&prefix, prefix_param);


	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	zephir_is_iterable(&names, 0, "phalcon/Http/Request.zep", 1455);
	if (Z_TYPE_P(&names) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&names), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&idx);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&idx, _3);
			} else {
				ZVAL_LONG(&idx, _2);
			}
			ZEPHIR_INIT_NVAR(&name);
			ZVAL_COPY(&name, _0);
			ZEPHIR_INIT_NVAR(&p);
			ZEPHIR_CONCAT_VSV(&p, &prefix, ".", &idx);
			if (Z_TYPE_P(&name) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_4$$4);
				zephir_create_array(&_4$$4, 6, 0 TSRMLS_CC);
				zephir_array_update_string(&_4$$4, SL("name"), &name, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_5$$4);
				zephir_array_fetch(&_5$$4, &types, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1431 TSRMLS_CC);
				zephir_array_update_string(&_4$$4, SL("type"), &_5$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_5$$4);
				zephir_array_fetch(&_5$$4, &tmp_names, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1432 TSRMLS_CC);
				zephir_array_update_string(&_4$$4, SL("tmp_name"), &_5$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_5$$4);
				zephir_array_fetch(&_5$$4, &sizes, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1433 TSRMLS_CC);
				zephir_array_update_string(&_4$$4, SL("size"), &_5$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_5$$4);
				zephir_array_fetch(&_5$$4, &errors, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1434 TSRMLS_CC);
				zephir_array_update_string(&_4$$4, SL("error"), &_5$$4, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_4$$4, SL("key"), &p, PH_COPY | PH_SEPARATE);
				zephir_array_append(&files, &_4$$4, PH_SEPARATE, "phalcon/Http/Request.zep", 1436);
			}
			if (Z_TYPE_P(&name) == IS_ARRAY) {
				zephir_array_fetch(&_6$$5, &names, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1441 TSRMLS_CC);
				zephir_array_fetch(&_7$$5, &types, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1442 TSRMLS_CC);
				zephir_array_fetch(&_8$$5, &tmp_names, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1443 TSRMLS_CC);
				zephir_array_fetch(&_9$$5, &sizes, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1444 TSRMLS_CC);
				zephir_array_fetch(&_10$$5, &errors, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1445 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&parentFiles, this_ptr, "smoothfiles", &_11, 342, &_6$$5, &_7$$5, &_8$$5, &_9$$5, &_10$$5, &p);
				zephir_check_call_status();
				zephir_is_iterable(&parentFiles, 0, "phalcon/Http/Request.zep", 1452);
				if (Z_TYPE_P(&parentFiles) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parentFiles), _12$$5)
					{
						ZEPHIR_INIT_NVAR(&file);
						ZVAL_COPY(&file, _12$$5);
						zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/Http/Request.zep", 1450);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &parentFiles, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_13$$5, &parentFiles, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_13$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&file, &parentFiles, "current", NULL, 0);
						zephir_check_call_status();
							zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/Http/Request.zep", 1450);
						ZEPHIR_CALL_METHOD(NULL, &parentFiles, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&file);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &names, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &names, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&idx, &names, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&name, &names, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&p);
				ZEPHIR_CONCAT_VSV(&p, &prefix, ".", &idx);
				if (Z_TYPE_P(&name) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_14$$9);
					zephir_create_array(&_14$$9, 6, 0 TSRMLS_CC);
					zephir_array_update_string(&_14$$9, SL("name"), &name, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_15$$9);
					zephir_array_fetch(&_15$$9, &types, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1431 TSRMLS_CC);
					zephir_array_update_string(&_14$$9, SL("type"), &_15$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_15$$9);
					zephir_array_fetch(&_15$$9, &tmp_names, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1432 TSRMLS_CC);
					zephir_array_update_string(&_14$$9, SL("tmp_name"), &_15$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_15$$9);
					zephir_array_fetch(&_15$$9, &sizes, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1433 TSRMLS_CC);
					zephir_array_update_string(&_14$$9, SL("size"), &_15$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_15$$9);
					zephir_array_fetch(&_15$$9, &errors, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1434 TSRMLS_CC);
					zephir_array_update_string(&_14$$9, SL("error"), &_15$$9, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_14$$9, SL("key"), &p, PH_COPY | PH_SEPARATE);
					zephir_array_append(&files, &_14$$9, PH_SEPARATE, "phalcon/Http/Request.zep", 1436);
				}
				if (Z_TYPE_P(&name) == IS_ARRAY) {
					zephir_array_fetch(&_16$$10, &names, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1441 TSRMLS_CC);
					zephir_array_fetch(&_17$$10, &types, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1442 TSRMLS_CC);
					zephir_array_fetch(&_18$$10, &tmp_names, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1443 TSRMLS_CC);
					zephir_array_fetch(&_19$$10, &sizes, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1444 TSRMLS_CC);
					zephir_array_fetch(&_20$$10, &errors, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1445 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&parentFiles, this_ptr, "smoothfiles", &_11, 342, &_16$$10, &_17$$10, &_18$$10, &_19$$10, &_20$$10, &p);
					zephir_check_call_status();
					zephir_is_iterable(&parentFiles, 0, "phalcon/Http/Request.zep", 1452);
					if (Z_TYPE_P(&parentFiles) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parentFiles), _21$$10)
						{
							ZEPHIR_INIT_NVAR(&file);
							ZVAL_COPY(&file, _21$$10);
							zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/Http/Request.zep", 1450);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &parentFiles, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_22$$10, &parentFiles, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_22$$10)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&file, &parentFiles, "current", NULL, 0);
							zephir_check_call_status();
								zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/Http/Request.zep", 1450);
							ZEPHIR_CALL_METHOD(NULL, &parentFiles, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&file);
				}
			ZEPHIR_CALL_METHOD(NULL, &names, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_NVAR(&idx);
	RETURN_CCTOR(&files);

}

/**
 * Checks the filter service and assigns it to the class parameter
 */
PHP_METHOD(Phalcon_Http_Request, getFilterService) {

	zval container, filterService, _0, _1$$3, _6$$3, _7$$3, _2$$4, _3$$4, _5$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("filterService"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&filterService, &_0);
	if (Z_TYPE_P(&filterService) != IS_OBJECT) {
		zephir_read_property(&_1$$3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_1$$3);
		if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_http_request_exception_ce);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "the 'filter' service");
			ZEPHIR_CALL_CE_STATIC(&_3$$4, phalcon_http_request_exception_ce, "containerservicenotfound", &_4, 0, &_5$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 1, &_3$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "phalcon/Http/Request.zep", 1473 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "filter");
		ZEPHIR_CALL_METHOD(&_6$$3, &container, "getshared", NULL, 0, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&filterService, &_6$$3);
		zephir_update_property_zval(this_ptr, SL("filterService"), &filterService);
	}
	RETURN_MM_MEMBER(getThis(), "filterService");

}

zend_object *zephir_init_properties_Phalcon_Http_Request(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("queryFilters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("queryFilters"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

