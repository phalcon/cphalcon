
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
 * Encapsulates request information for easy and secure access from application controllers.
 *
 * The request object is a simple value object that is passed between the dispatcher and controller classes.
 * It packages the HTTP request environment.
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
 * $request->getServer("HTTP_HOST"); // Retrieve SERVER variables
 * $request->getMethod();            // GET, POST, PUT, DELETE, HEAD, OPTIONS, PATCH, PURGE, TRACE, CONNECT
 * $request->getLanguages();         // An array of languages the client accepts
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Request) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http, Request, phalcon, http_request, phalcon_http_request_method_entry, 0);

	zend_declare_property_null(phalcon_http_request_ce, SL("container"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_ce, SL("filterLocator"), ZEND_ACC_PRIVATE TSRMLS_CC);

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
 * Gets a variable from the $_REQUEST superglobal applying filters if needed.
 * If no parameters are given the $_REQUEST superglobal is returned
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
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, *_REQUEST, __$null, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 252, _REQUEST, &name, filters, defaultValue, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets an array with mime/types and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getqualityheader", NULL, 253, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets auth info accepted by the browser/client from $_SERVER["PHP_AUTH_USER"]
 */
PHP_METHOD(Phalcon_Http_Request, getBasicAuth) {

	zend_bool _0;
	zval *_SERVER, auth, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	_0 = zephir_array_isset_string(_SERVER, SL("PHP_AUTH_USER"));
	if (_0) {
		_0 = zephir_array_isset_string(_SERVER, SL("PHP_AUTH_PW"));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&auth);
		array_init(&auth);
		zephir_array_fetch_string(&_1$$3, _SERVER, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 104 TSRMLS_CC);
		zephir_array_update_string(&auth, SL("username"), &_1$$3, PH_COPY | PH_SEPARATE);
		zephir_array_fetch_string(&_2$$3, _SERVER, SL("PHP_AUTH_PW"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 105 TSRMLS_CC);
		zephir_array_update_string(&auth, SL("password"), &_2$$3, PH_COPY | PH_SEPARATE);
		RETURN_CCTOR(&auth);
	}
	RETURN_MM_NULL();

}

/**
 * Gets best mime/type accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbestquality", NULL, 254, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best charset accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbestquality", NULL, 254, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best language accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbestquality", NULL, 254, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets most possible client IPv4 Address. This method searches in
 * $_SERVER["REMOTE_ADDR"] and optionally in $_SERVER["HTTP_X_FORWARDED_FOR"]
 */
PHP_METHOD(Phalcon_Http_Request, getClientAddress) {

	zval *trustForwardedHeader_param = NULL, *_SERVER, address, _0$$7, _1$$7;
	zend_bool trustForwardedHeader;
	zval *this_ptr = getThis();

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
		zephir_array_isset_string_fetch(&address, _SERVER, SL("HTTP_X_FORWARDED_FOR"), 0);
		if (Z_TYPE_P(&address) == IS_NULL) {
			ZEPHIR_OBS_NVAR(&address);
			zephir_array_isset_string_fetch(&address, _SERVER, SL("HTTP_CLIENT_IP"), 0);
		}
	}
	if (Z_TYPE_P(&address) == IS_NULL) {
		ZEPHIR_OBS_NVAR(&address);
		zephir_array_isset_string_fetch(&address, _SERVER, SL("REMOTE_ADDR"), 0);
	}
	if (Z_TYPE_P(&address) == IS_STRING) {
		if (zephir_memnstr_str(&address, SL(","), "phalcon/http/request.zep", 159)) {
			ZEPHIR_INIT_VAR(&_0$$7);
			zephir_fast_explode_str(&_0$$7, SL(","), &address, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_1$$7, &_0$$7, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 163 TSRMLS_CC);
			RETURN_CTOR(&_1$$7);
		}
		RETURN_CCTOR(&address);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Gets a charsets array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getqualityheader", NULL, 253, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets content type which request has been made
 */
PHP_METHOD(Phalcon_Http_Request, getContentType) {

	zval *_SERVER, contentType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contentType);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_OBS_VAR(&contentType);
	if (zephir_array_isset_string_fetch(&contentType, _SERVER, SL("CONTENT_TYPE"), 0)) {
		RETURN_CCTOR(&contentType);
	} else {
		ZEPHIR_OBS_NVAR(&contentType);
		if (zephir_array_isset_string_fetch(&contentType, _SERVER, SL("HTTP_CONTENT_TYPE"), 0)) {
			RETURN_CCTOR(&contentType);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Http_Request, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * Gets auth info accepted by the browser/client from $_SERVER["PHP_AUTH_DIGEST"]
 */
PHP_METHOD(Phalcon_Http_Request, getDigestAuth) {

	zval auth;
	zval *_SERVER, digest, matches, match, _0$$3, _1$$3, _2$$3, *_3$$5, _4$$6, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&digest);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&auth);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&auth);
	array_init(&auth);
	ZEPHIR_OBS_VAR(&digest);
	if (zephir_array_isset_string_fetch(&digest, _SERVER, SL("PHP_AUTH_DIGEST"), 0)) {
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
			zephir_is_iterable(&matches, 0, "phalcon/http/request.zep", 227);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _3$$5)
			{
				ZEPHIR_INIT_NVAR(&match);
				ZVAL_COPY(&match, _3$$5);
				zephir_array_fetch_long(&_4$$6, &match, 3, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 225 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&_5$$6);
				zephir_array_fetch_long(&_5$$6, &match, 1, PH_NOISY, "phalcon/http/request.zep", 225 TSRMLS_CC);
				zephir_array_update_zval(&auth, &_5$$6, &_4$$6, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
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
	zephir_array_fetch_string(&_1, &_0, SL("get"), PH_READONLY, "phalcon/http/request.zep", 240 TSRMLS_CC);
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
	zephir_array_fetch_string(&_1, &_0, SL("post"), PH_READONLY, "phalcon/http/request.zep", 254 TSRMLS_CC);
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
	zephir_array_fetch_string(&_1, &_0, SL("put"), PH_READONLY, "phalcon/http/request.zep", 268 TSRMLS_CC);
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
	zval *header_param = NULL, *_SERVER, value, name, _0, _1, _2, _3;
	zval header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header);
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
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 50, &header, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	zephir_fast_strtoupper(&name, &_2);
	ZEPHIR_OBS_VAR(&value);
	if (zephir_array_isset_fetch(&value, _SERVER, &name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&value);
	}
	ZEPHIR_OBS_NVAR(&value);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "HTTP_", &name);
	if (zephir_array_isset_fetch(&value, _SERVER, &_3, 0 TSRMLS_CC)) {
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

	zend_string *_2;
	zend_ulong _1;
	zval headers, contentHeaders;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_9 = NULL;
	zval __$true, *_SERVER, name, value, authHeaders, *_0, _3$$4, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _10$$4, _11$$4, _12$$4, _13$$3, _14$$5, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5, _21$$6;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&authHeaders);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$6);
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
	zephir_is_iterable(_SERVER, 0, "phalcon/http/request.zep", 335);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_SERVER), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&name, _2);
		} else {
			ZVAL_LONG(&name, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		if (zephir_start_with_str(&name, SL("HTTP_"))) {
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_LONG(&_5$$4, 5);
			ZEPHIR_INIT_NVAR(&_6$$4);
			zephir_substr(&_6$$4, &name, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_NVAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "_");
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_STRING(&_8$$4, " ");
			zephir_fast_str_replace(&_4$$4, &_7$$4, &_8$$4, &_6$$4 TSRMLS_CC);
			zephir_fast_strtolower(&_3$$4, &_4$$4);
			ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_9, 193, &_3$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZEPHIR_INIT_NVAR(&_11$$4);
			ZVAL_STRING(&_11$$4, " ");
			ZEPHIR_INIT_NVAR(&_12$$4);
			ZVAL_STRING(&_12$$4, "-");
			zephir_fast_str_replace(&_10$$4, &_11$$4, &_12$$4, &name TSRMLS_CC);
			ZEPHIR_CPY_WRT(&name, &_10$$4);
			zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
			continue;
		}
		ZEPHIR_INIT_NVAR(&_13$$3);
		zephir_fast_strtoupper(&_13$$3, &name);
		ZEPHIR_CPY_WRT(&name, &_13$$3);
		if (zephir_array_isset(&contentHeaders, &name)) {
			ZEPHIR_INIT_NVAR(&_14$$5);
			ZEPHIR_INIT_NVAR(&_15$$5);
			ZEPHIR_INIT_NVAR(&_16$$5);
			ZVAL_STRING(&_16$$5, "_");
			ZEPHIR_INIT_NVAR(&_17$$5);
			ZVAL_STRING(&_17$$5, " ");
			zephir_fast_str_replace(&_15$$5, &_16$$5, &_17$$5, &name TSRMLS_CC);
			zephir_fast_strtolower(&_14$$5, &_15$$5);
			ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_9, 193, &_14$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_18$$5);
			ZEPHIR_INIT_NVAR(&_19$$5);
			ZVAL_STRING(&_19$$5, " ");
			ZEPHIR_INIT_NVAR(&_20$$5);
			ZVAL_STRING(&_20$$5, "-");
			zephir_fast_str_replace(&_18$$5, &_19$$5, &_20$$5, &name TSRMLS_CC);
			ZEPHIR_CPY_WRT(&name, &_18$$5);
			zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_CALL_METHOD(&authHeaders, this_ptr, "resolveauthorizationheaders", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&authHeaders) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_21$$6);
		zephir_fast_array_merge(&_21$$6, &headers, &authHeaders TSRMLS_CC);
		ZEPHIR_CPY_WRT(&headers, &_21$$6);
	}
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
		if (zephir_memnstr_str(&host, SL(":"), "phalcon/http/request.zep", 408)) {
			ZEPHIR_INIT_VAR(&_5$$6);
			ZVAL_STRING(&_5$$6, "/:[[:digit:]]+$/");
			ZEPHIR_INIT_VAR(&_6$$6);
			ZVAL_STRING(&_6$$6, "");
			ZEPHIR_CALL_FUNCTION(&_7$$6, "preg_replace", NULL, 23, &_5$$6, &_6$$6, &host);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&host, &_7$$6);
		}
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "/[a-z0-9-]+\\.?/");
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "");
		ZEPHIR_CALL_FUNCTION(&_10$$5, "preg_replace", NULL, 23, &_8$$5, &_9$$5, &host);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_11$$5);
		ZVAL_STRING(&_11$$5, "");
		if (!ZEPHIR_IS_IDENTICAL(&_11$$5, &_10$$5)) {
			ZEPHIR_INIT_VAR(&_12$$7);
			object_init_ex(&_12$$7, spl_ce_UnexpectedValueException);
			ZEPHIR_INIT_VAR(&_13$$7);
			ZEPHIR_CONCAT_SV(&_13$$7, "Invalid host ", &host);
			ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", NULL, 255, &_13$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_12$$7, "phalcon/http/request.zep", 417 TSRMLS_CC);
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

	zval *_SERVER, httpReferer;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpReferer);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string_fetch(&httpReferer, _SERVER, SL("HTTP_REFERER"), 1)) {
		RETURN_CTORW(&httpReferer);
	}
	RETURN_STRING("");

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
 * Gets languages array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getqualityheader", NULL, 253, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets HTTP method which request has been made
 *
 * If the X-HTTP-Method-Override header is set, and if the method is a POST,
 * then it is used to determine the "real" intended HTTP method.
 *
 * The _method request parameter can also be used to determine the HTTP method,
 * but only if setHttpMethodParameterOverride(true) has been called.
 *
 * The method is always an uppercased string.
 */
PHP_METHOD(Phalcon_Http_Request, getMethod) {

	zval returnMethod;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, *_REQUEST, overridedMethod, spoofedMethod, requestMethod, _0, _3, _1$$5, _2$$5;
	zval *this_ptr = getThis();

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
	if (EXPECTED(zephir_array_isset_string_fetch(&requestMethod, _SERVER, SL("REQUEST_METHOD"), 0))) {
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
		ZEPHIR_CALL_METHOD(&overridedMethod, this_ptr, "getheader", NULL, 256, &_1$$5);
		zephir_check_call_status();
		zephir_read_property(&_2$$5, this_ptr, SL("httpMethodParameterOverride"), PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_IS_EMPTY(&overridedMethod))) {
			ZEPHIR_INIT_NVAR(&returnMethod);
			zephir_fast_strtoupper(&returnMethod, &overridedMethod);
		} else if (zephir_is_true(&_2$$5)) {
			ZEPHIR_OBS_VAR(&spoofedMethod);
			if (zephir_array_isset_string_fetch(&spoofedMethod, _REQUEST, SL("_method"), 0)) {
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

	zval host, pos, _0, _7, _1$$4, _2$$5, _3$$5, _4$$3, _5$$3, _6$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_HOST");
	ZEPHIR_CALL_METHOD(&host, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&host)) {
		if (zephir_memnstr_str(&host, SL(":"), "phalcon/http/request.zep", 511)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			ZVAL_STRING(&_1$$4, ":");
			ZEPHIR_CALL_FUNCTION(&pos, "strrpos", NULL, 143, &host, &_1$$4);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
				ZVAL_LONG(&_2$$5, (zephir_get_numberval(&pos) + 1));
				ZEPHIR_INIT_VAR(&_3$$5);
				zephir_substr(&_3$$5, &host, zephir_get_intval(&_2$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				RETURN_MM_LONG(zephir_get_intval(&_3$$5));
			}
		}
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getscheme", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_6$$3);
		ZVAL_STRING(&_6$$3, "https");
		if (ZEPHIR_IS_IDENTICAL(&_6$$3, &_5$$3)) {
			ZVAL_LONG(&_4$$3, 443);
		} else {
			ZVAL_LONG(&_4$$3, 80);
		}
		RETURN_CCTOR(&_4$$3);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "SERVER_PORT");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(&_7));

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
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, *_POST, __$null, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 252, _POST, &name, filters, defaultValue, &_0, &_1);
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
			ZEPHIR_CALL_FUNCTION(&_2$$3, "stripos", NULL, 257, &contentType, &_1$$3);
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
			ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 258, &_4$$6, &put);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 252, &put, &name, filters, defaultValue, &_5, &_6);
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
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, *_GET, __$null, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 252, _GET, &name, filters, defaultValue, &_0, &_1);
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

	zval https, scheme, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&https);
	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTPS");
	ZEPHIR_CALL_METHOD(&https, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&https)) {
		ZEPHIR_INIT_VAR(&scheme);
		if (ZEPHIR_IS_STRING(&https, "off")) {
			ZVAL_STRING(&scheme, "http");
		} else {
			ZVAL_STRING(&scheme, "https");
		}
	} else {
		ZEPHIR_INIT_NVAR(&scheme);
		ZVAL_STRING(&scheme, "http");
	}
	RETURN_CCTOR(&scheme);

}

/**
 * Gets variable from $_SERVER superglobal
 */
PHP_METHOD(Phalcon_Http_Request, getServer) {

	zval *name_param = NULL, *_SERVER, serverValue;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
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


	if (zephir_array_isset_fetch(&serverValue, _SERVER, &name, 1 TSRMLS_CC)) {
		RETURN_CTOR(&serverValue);
	}
	RETURN_MM_NULL();

}

/**
 * Gets active server address IP
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, serverAddr, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serverAddr);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_OBS_VAR(&serverAddr);
	if (zephir_array_isset_string_fetch(&serverAddr, _SERVER, SL("SERVER_ADDR"), 0)) {
		RETURN_CCTOR(&serverAddr);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "localhost");
	ZEPHIR_RETURN_CALL_FUNCTION("gethostbyname", NULL, 259, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets active server name
 */
PHP_METHOD(Phalcon_Http_Request, getServerName) {

	zval *_SERVER, serverName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serverName);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string_fetch(&serverName, _SERVER, SL("SERVER_NAME"), 1)) {
		RETURN_CTORW(&serverName);
	}
	RETURN_STRING("localhost");

}

/**
 * Gets attached files as Phalcon\Http\Request\File instances
 */
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zval files;
	zephir_fcall_cache_entry *_9 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *onlySuccessful_param = NULL, *namedKeys_param = NULL, *_FILES, superFiles, prefix, input, smoothInput, file, dataFile, *_0$$3, _3$$4, _4$$5, _5$$5, _6$$5, _7$$5, _8$$5, *_10$$5, _12$$6, _13$$7, _14$$8, _15$$8, _17$$8, _18$$9, _19$$9, _21$$10, _22$$12, _23$$13;
	zend_bool onlySuccessful, namedKeys, _11$$6, _20$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&superFiles);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&smoothInput);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&dataFile);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$13);
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
	ZEPHIR_CPY_WRT(&superFiles, _FILES);
	if (zephir_fast_count_int(&superFiles TSRMLS_CC) > 0) {
		zephir_is_iterable(&superFiles, 0, "phalcon/http/request.zep", 728);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&superFiles), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&prefix);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&prefix, _2$$3);
			} else {
				ZVAL_LONG(&prefix, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&input);
			ZVAL_COPY(&input, _0$$3);
			ZEPHIR_OBS_NVAR(&_3$$4);
			zephir_array_fetch_string(&_3$$4, &input, SL("name"), PH_NOISY, "phalcon/http/request.zep", 691 TSRMLS_CC);
			if (Z_TYPE_P(&_3$$4) == IS_ARRAY) {
				zephir_array_fetch_string(&_4$$5, &input, SL("name"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 693 TSRMLS_CC);
				zephir_array_fetch_string(&_5$$5, &input, SL("type"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 694 TSRMLS_CC);
				zephir_array_fetch_string(&_6$$5, &input, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 695 TSRMLS_CC);
				zephir_array_fetch_string(&_7$$5, &input, SL("size"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 696 TSRMLS_CC);
				zephir_array_fetch_string(&_8$$5, &input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 697 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&smoothInput, this_ptr, "smoothfiles", &_9, 260, &_4$$5, &_5$$5, &_6$$5, &_7$$5, &_8$$5, &prefix);
				zephir_check_call_status();
				zephir_is_iterable(&smoothInput, 0, "phalcon/http/request.zep", 718);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&smoothInput), _10$$5)
				{
					ZEPHIR_INIT_NVAR(&file);
					ZVAL_COPY(&file, _10$$5);
					_11$$6 = onlySuccessful == 0;
					if (!(_11$$6)) {
						zephir_array_fetch_string(&_12$$6, &file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 702 TSRMLS_CC);
						_11$$6 = ZEPHIR_IS_LONG(&_12$$6, 0);
					}
					if (_11$$6) {
						ZEPHIR_INIT_NVAR(&dataFile);
						zephir_create_array(&dataFile, 5, 0 TSRMLS_CC);
						ZEPHIR_OBS_NVAR(&_13$$7);
						zephir_array_fetch_string(&_13$$7, &file, SL("name"), PH_NOISY, "phalcon/http/request.zep", 704 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("name"), &_13$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(&_13$$7);
						zephir_array_fetch_string(&_13$$7, &file, SL("type"), PH_NOISY, "phalcon/http/request.zep", 705 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("type"), &_13$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(&_13$$7);
						zephir_array_fetch_string(&_13$$7, &file, SL("tmp_name"), PH_NOISY, "phalcon/http/request.zep", 706 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("tmp_name"), &_13$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(&_13$$7);
						zephir_array_fetch_string(&_13$$7, &file, SL("size"), PH_NOISY, "phalcon/http/request.zep", 707 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("size"), &_13$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(&_13$$7);
						zephir_array_fetch_string(&_13$$7, &file, SL("error"), PH_NOISY, "phalcon/http/request.zep", 709 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("error"), &_13$$7, PH_COPY | PH_SEPARATE);
						if (namedKeys == 1) {
							ZEPHIR_INIT_NVAR(&_14$$8);
							object_init_ex(&_14$$8, phalcon_http_request_file_ce);
							zephir_array_fetch_string(&_15$$8, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 712 TSRMLS_CC);
							ZEPHIR_CALL_METHOD(NULL, &_14$$8, "__construct", &_16, 261, &dataFile, &_15$$8);
							zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&_17$$8);
							zephir_array_fetch_string(&_17$$8, &file, SL("key"), PH_NOISY, "phalcon/http/request.zep", 712 TSRMLS_CC);
							zephir_array_update_zval(&files, &_17$$8, &_14$$8, PH_COPY | PH_SEPARATE);
						} else {
							ZEPHIR_INIT_NVAR(&_18$$9);
							object_init_ex(&_18$$9, phalcon_http_request_file_ce);
							zephir_array_fetch_string(&_19$$9, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 714 TSRMLS_CC);
							ZEPHIR_CALL_METHOD(NULL, &_18$$9, "__construct", &_16, 261, &dataFile, &_19$$9);
							zephir_check_call_status();
							zephir_array_append(&files, &_18$$9, PH_SEPARATE, "phalcon/http/request.zep", 714);
						}
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&file);
			} else {
				_20$$10 = onlySuccessful == 0;
				if (!(_20$$10)) {
					zephir_array_fetch_string(&_21$$10, &input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 719 TSRMLS_CC);
					_20$$10 = ZEPHIR_IS_LONG(&_21$$10, 0);
				}
				if (_20$$10) {
					if (namedKeys == 1) {
						ZEPHIR_INIT_NVAR(&_22$$12);
						object_init_ex(&_22$$12, phalcon_http_request_file_ce);
						ZEPHIR_CALL_METHOD(NULL, &_22$$12, "__construct", &_16, 261, &input, &prefix);
						zephir_check_call_status();
						zephir_array_update_zval(&files, &prefix, &_22$$12, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_INIT_NVAR(&_23$$13);
						object_init_ex(&_23$$13, phalcon_http_request_file_ce);
						ZEPHIR_CALL_METHOD(NULL, &_23$$13, "__construct", &_16, 261, &input, &prefix);
						zephir_check_call_status();
						zephir_array_append(&files, &_23$$13, PH_SEPARATE, "phalcon/http/request.zep", 723);
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&input);
		ZEPHIR_INIT_NVAR(&prefix);
	}
	RETURN_CTOR(&files);

}

/**
 * Gets HTTP URI which request has been made
 */
PHP_METHOD(Phalcon_Http_Request, getURI) {

	zval *_SERVER, requestURI;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requestURI);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string_fetch(&requestURI, _SERVER, SL("REQUEST_URI"), 1)) {
		RETURN_CTORW(&requestURI);
	}
	RETURN_STRING("");

}

/**
 * Gets HTTP user agent used to made the request
 */
PHP_METHOD(Phalcon_Http_Request, getUserAgent) {

	zval *_SERVER, userAgent;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&userAgent);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string_fetch(&userAgent, _SERVER, SL("HTTP_USER_AGENT"), 1)) {
		RETURN_CTORW(&userAgent);
	}
	RETURN_STRING("");

}

/**
 * Checks whether $_REQUEST superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, has) {

	zval *name_param = NULL, *_REQUEST;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

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


	RETURN_MM_BOOL(zephir_array_isset(_REQUEST, &name));

}

/**
 * Returns the number of files available
 *
 * TODO: Check this
 */
PHP_METHOD(Phalcon_Http_Request, hasFiles) {

	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zval *onlySuccessful_param = NULL, *_FILES, files, file, error, *_0, _2$$8, _3$$8;
	zend_bool onlySuccessful, _1$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_3$$8);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_fetch_params(1, 0, 1, &onlySuccessful_param);

	if (!onlySuccessful_param) {
		onlySuccessful = 0;
	} else {
		onlySuccessful = zephir_get_boolval(onlySuccessful_param);
	}


	numberFiles = 0;
	ZEPHIR_CPY_WRT(&files, _FILES);
	if (Z_TYPE_P(&files) != IS_ARRAY) {
		RETURN_MM_LONG(0);
	}
	zephir_is_iterable(&files, 0, "phalcon/http/request.zep", 799);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&files), _0)
	{
		ZEPHIR_INIT_NVAR(&file);
		ZVAL_COPY(&file, _0);
		ZEPHIR_OBS_NVAR(&error);
		if (zephir_array_isset_string_fetch(&error, &file, SL("error"), 0)) {
			if (Z_TYPE_P(&error) != IS_ARRAY) {
				_1$$6 = !zephir_is_true(&error);
				if (!(_1$$6)) {
					_1$$6 = !onlySuccessful;
				}
				if (_1$$6) {
					numberFiles++;
				}
			}
			if (Z_TYPE_P(&error) == IS_ARRAY) {
				if (onlySuccessful) {
					ZVAL_BOOL(&_3$$8, 1);
				} else {
					ZVAL_BOOL(&_3$$8, 0);
				}
				ZEPHIR_CALL_METHOD(&_2$$8, this_ptr, "hasfilehelper", &_4, 262, &error, &_3$$8);
				zephir_check_call_status();
				numberFiles += zephir_get_numberval(&_2$$8);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&file);
	RETURN_MM_LONG(numberFiles);

}

/**
 * Checks whether headers has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *header_param = NULL, *_SERVER, name, _0, _1, _2, _3;
	zval header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header);
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
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 50, &header, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	zephir_fast_strtoupper(&name, &_2);
	if (zephir_array_isset(_SERVER, &name)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "HTTP_", &name);
	if (zephir_array_isset(_SERVER, &_3)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks whether $_POST superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPost) {

	zval *name_param = NULL, *_POST;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

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


	RETURN_MM_BOOL(zephir_array_isset(_POST, &name));

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

	zval *name_param = NULL, *_GET;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

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


	RETURN_MM_BOOL(zephir_array_isset(_GET, &name));

}

/**
 * Checks whether $_SERVER superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasServer) {

	zval *name_param = NULL, *_SERVER;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

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


	RETURN_MM_BOOL(zephir_array_isset(_SERVER, &name));

}

/**
 * Checks whether request has been made using ajax
 */
PHP_METHOD(Phalcon_Http_Request, isAjax) {

	zend_bool _0;
	zval *_SERVER, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	_0 = zephir_array_isset_string(_SERVER, SL("HTTP_X_REQUESTED_WITH"));
	if (_0) {
		zephir_array_fetch_string(&_1, _SERVER, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 863 TSRMLS_CC);
		_0 = ZEPHIR_IS_STRING_IDENTICAL(&_1, "XMLHttpRequest");
	}
	RETURN_BOOL(_0);

}

/**
 * Checks whether HTTP method is CONNECT. if _SERVER["REQUEST_METHOD"]==="CONNECT"
 */
PHP_METHOD(Phalcon_Http_Request, isConnect) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 263);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "CONNECT"));

}

/**
 * Checks whether HTTP method is DELETE. if _SERVER["REQUEST_METHOD"]==="DELETE"
 */
PHP_METHOD(Phalcon_Http_Request, isDelete) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 263);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "DELETE"));

}

/**
 * Checks whether HTTP method is GET. if _SERVER["REQUEST_METHOD"]==="GET"
 */
PHP_METHOD(Phalcon_Http_Request, isGet) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 263);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "GET"));

}

/**
 * Checks whether HTTP method is HEAD. if _SERVER["REQUEST_METHOD"]==="HEAD"
 */
PHP_METHOD(Phalcon_Http_Request, isHead) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 263);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "HEAD"));

}

/**
 * Check if HTTP method match any of the passed methods
 * When strict is true it checks if validated methods are real HTTP methods
 */
PHP_METHOD(Phalcon_Http_Request, isMethod) {

	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool strict, _0$$3;
	zval *methods, methods_sub, *strict_param = NULL, httpMethod, method, _1$$3, _2$$4, _3$$4, *_4$$5, _5$$6, _6$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&methods_sub);
	ZVAL_UNDEF(&httpMethod);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &methods, &strict_param);

	if (!strict_param) {
		strict = 0;
	} else {
		strict = zephir_get_boolval(strict_param);
	}


	ZEPHIR_CALL_METHOD(&httpMethod, this_ptr, "getmethod", NULL, 263);
	zephir_check_call_status();
	if (Z_TYPE_P(methods) == IS_STRING) {
		_0$$3 = strict;
		if (_0$$3) {
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "isvalidhttpmethod", NULL, 0, methods);
			zephir_check_call_status();
			_0$$3 = !zephir_is_true(&_1$$3);
		}
		if (_0$$3) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_http_request_exception_ce);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_CONCAT_SV(&_3$$4, "Invalid HTTP method: ", methods);
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 4, &_3$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "phalcon/http/request.zep", 910 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(methods, &httpMethod));
	}
	if (Z_TYPE_P(methods) == IS_ARRAY) {
		zephir_is_iterable(methods, 0, "phalcon/http/request.zep", 922);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(methods), _4$$5)
		{
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_COPY(&method, _4$$5);
			if (strict) {
				ZVAL_BOOL(&_6$$6, 1);
			} else {
				ZVAL_BOOL(&_6$$6, 0);
			}
			ZEPHIR_CALL_METHOD(&_5$$6, this_ptr, "ismethod", &_7, 264, &method, &_6$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_5$$6)) {
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&method);
		RETURN_MM_BOOL(0);
	}
	if (strict) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "Invalid HTTP method: non-string", "phalcon/http/request.zep", 926);
		return;
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks whether HTTP method is OPTIONS. if _SERVER["REQUEST_METHOD"]==="OPTIONS"
 */
PHP_METHOD(Phalcon_Http_Request, isOptions) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 263);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "OPTIONS"));

}

/**
 * Checks whether HTTP method is PATCH. if _SERVER["REQUEST_METHOD"]==="PATCH"
 */
PHP_METHOD(Phalcon_Http_Request, isPatch) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 263);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "PATCH"));

}

/**
 * Checks whether HTTP method is POST. if _SERVER["REQUEST_METHOD"]==="POST"
 */
PHP_METHOD(Phalcon_Http_Request, isPost) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 263);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "POST"));

}

/**
 * Checks whether HTTP method is PUT. if _SERVER["REQUEST_METHOD"]==="PUT"
 */
PHP_METHOD(Phalcon_Http_Request, isPut) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 263);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "PUT"));

}

/**
 * Checks whether HTTP method is PURGE (Squid and Varnish support). if _SERVER["REQUEST_METHOD"]==="PURGE"
 */
PHP_METHOD(Phalcon_Http_Request, isPurge) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 263);
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
 * Checks if the `Request::getHttpHost` method will be use strict validation of host name or not
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
	zval *_SERVER, contentType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contentType);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string(_SERVER, SL("HTTP_SOAPACTION"))) {
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&contentType))) {
			RETURN_MM_BOOL(zephir_memnstr_str(&contentType, SL("application/soap+xml"), "phalcon/http/request.zep", 1000));
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks whether HTTP method is TRACE. if _SERVER["REQUEST_METHOD"]==="TRACE"
 */
PHP_METHOD(Phalcon_Http_Request, isTrace) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 263);
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
 * Sets automatic sanitizers/filters for a particular field and for particular methods
 */
PHP_METHOD(Phalcon_Http_Request, setParameterFilters) {

	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filters, scope;
	zval *name_param = NULL, *filters_param = NULL, *scope_param = NULL, filterLocator, sanitizer, localScope, scopeMethod, *_2, *_8, _0$$3, _3$$4, _5$$5, _6$$5, _7$$6;
	zval name, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&filterLocator);
	ZVAL_UNDEF(&sanitizer);
	ZVAL_UNDEF(&localScope);
	ZVAL_UNDEF(&scopeMethod);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
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


	if (zephir_fast_count_int(&filters TSRMLS_CC) < 1) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_http_request_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVS(&_1$$3, "Filters have not been defined for '", &name, "'");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 4, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/http/request.zep", 1052 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&filterLocator, this_ptr, "getfilterlocatorservice", NULL, 265);
	zephir_check_call_status();
	zephir_is_iterable(&filters, 0, "phalcon/http/request.zep", 1063);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&filters), _2)
	{
		ZEPHIR_INIT_NVAR(&sanitizer);
		ZVAL_COPY(&sanitizer, _2);
		ZEPHIR_CALL_METHOD(&_3$$4, &filterLocator, "has", &_4, 0, &sanitizer);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_3$$4)) {
			ZEPHIR_INIT_NVAR(&_5$$5);
			object_init_ex(&_5$$5, phalcon_http_request_exception_ce);
			ZEPHIR_INIT_LNVAR(_6$$5);
			ZEPHIR_CONCAT_SVS(&_6$$5, "Sanitizer '", &sanitizer, "' does not exist in the filter locator");
			ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", NULL, 4, &_6$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$5, "phalcon/http/request.zep", 1059 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&sanitizer);
	if (zephir_fast_count_int(&scope TSRMLS_CC) < 1) {
		ZEPHIR_INIT_VAR(&localScope);
		zephir_create_array(&localScope, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_7$$6);
		ZVAL_STRING(&_7$$6, "get");
		zephir_array_fast_append(&localScope, &_7$$6);
		ZEPHIR_INIT_NVAR(&_7$$6);
		ZVAL_STRING(&_7$$6, "post");
		zephir_array_fast_append(&localScope, &_7$$6);
		ZEPHIR_INIT_NVAR(&_7$$6);
		ZVAL_STRING(&_7$$6, "put");
		zephir_array_fast_append(&localScope, &_7$$6);
	} else {
		ZEPHIR_CPY_WRT(&localScope, &scope);
	}
	zephir_is_iterable(&localScope, 0, "phalcon/http/request.zep", 1073);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&localScope), _8)
	{
		ZEPHIR_INIT_NVAR(&scopeMethod);
		ZVAL_COPY(&scopeMethod, _8);
		zephir_update_property_array_multi(this_ptr, SL("queryFilters"), &filters TSRMLS_CC, SL("zz"), 2, &scopeMethod, &name);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&scopeMethod);
	RETURN_THIS();

}

/**
 * Sets if the `Request::getHttpHost` method must be use strict validation of host name or not
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
	zend_long i = 0;
	zval name;
	zval *qualityParts_param = NULL, *name_param = NULL, selectedName, accept, *_0, _1$$4, _2$$5;
	zval qualityParts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&qualityParts);
	ZVAL_UNDEF(&selectedName);
	ZVAL_UNDEF(&accept);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
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
	zephir_is_iterable(&qualityParts, 0, "phalcon/http/request.zep", 1112);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&qualityParts), _0)
	{
		ZEPHIR_INIT_NVAR(&accept);
		ZVAL_COPY(&accept, _0);
		if (i == 0) {
			ZEPHIR_OBS_NVAR(&_1$$4);
			zephir_array_fetch_string(&_1$$4, &accept, SL("quality"), PH_NOISY, "phalcon/http/request.zep", 1101 TSRMLS_CC);
			quality = zephir_get_doubleval(&_1$$4);
			ZEPHIR_OBS_NVAR(&selectedName);
			zephir_array_fetch(&selectedName, &accept, &name, PH_NOISY, "phalcon/http/request.zep", 1102 TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(&_2$$5);
			zephir_array_fetch_string(&_2$$5, &accept, SL("quality"), PH_NOISY, "phalcon/http/request.zep", 1104 TSRMLS_CC);
			acceptQuality = zephir_get_doubleval(&_2$$5);
			if (acceptQuality > quality) {
				quality = acceptQuality;
				ZEPHIR_OBS_NVAR(&selectedName);
				zephir_array_fetch(&selectedName, &accept, &name, PH_NOISY, "phalcon/http/request.zep", 1107 TSRMLS_CC);
			}
		}
		i++;
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&accept);
	RETURN_CCTOR(&selectedName);

}

/**
 * Helper to get data from superglobals, applying filters if needed.
 * If no parameters are given the superglobal is returned.
 */
PHP_METHOD(Phalcon_Http_Request, getHelper) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive, _5;
	zval name;
	zval *source_param = NULL, *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, value, filter, container, _0$$6, _1$$6, _2$$6, _3$$5, _4$$5;
	zval source;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
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
		ZEPHIR_OBS_VAR(&filter);
		zephir_read_property(&filter, this_ptr, SL("filterLocator"), PH_NOISY_CC);
		if (Z_TYPE_P(&filter) != IS_OBJECT) {
			zephir_read_property(&_0$$6, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&container, &_0$$6);
			if (Z_TYPE_P(&container) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/request.zep", 1135);
				return;
			}
			ZEPHIR_INIT_VAR(&_2$$6);
			ZVAL_STRING(&_2$$6, "filter");
			ZEPHIR_CALL_METHOD(&_1$$6, &container, "getshared", NULL, 0, &_2$$6);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filter, &_1$$6);
			zephir_update_property_zval(this_ptr, SL("filterLocator"), &filter);
		}
		if (noRecursive) {
			ZVAL_BOOL(&_4$$5, 1);
		} else {
			ZVAL_BOOL(&_4$$5, 0);
		}
		ZEPHIR_CALL_METHOD(&_3$$5, &filter, "sanitize", NULL, 0, &value, filters, &_4$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&value, &_3$$5);
	}
	_5 = ZEPHIR_IS_EMPTY(&value);
	if (_5) {
		_5 = notAllowEmpty == 1;
	}
	if (_5) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CCTOR(&value);

}

/**
 * Recursively counts file in an array of files
 */
PHP_METHOD(Phalcon_Http_Request, hasFileHelper) {

	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zend_bool onlySuccessful, _1$$5;
	zval *data, data_sub, *onlySuccessful_param = NULL, value, *_0, _2$$7, _3$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data, &onlySuccessful_param);

	onlySuccessful = zephir_get_boolval(onlySuccessful_param);


	numberFiles = 0;
	if (Z_TYPE_P(data) != IS_ARRAY) {
		RETURN_MM_LONG(1);
	}
	zephir_is_iterable(data, 0, "phalcon/http/request.zep", 1176);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(data), _0)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		if (Z_TYPE_P(&value) != IS_ARRAY) {
			_1$$5 = !zephir_is_true(&value);
			if (!(_1$$5)) {
				_1$$5 = !onlySuccessful;
			}
			if (_1$$5) {
				numberFiles++;
			}
		}
		if (Z_TYPE_P(&value) == IS_ARRAY) {
			if (onlySuccessful) {
				ZVAL_BOOL(&_3$$7, 1);
			} else {
				ZVAL_BOOL(&_3$$7, 0);
			}
			ZEPHIR_CALL_METHOD(&_2$$7, this_ptr, "hasfilehelper", &_4, 262, &value, &_3$$7);
			zephir_check_call_status();
			numberFiles += zephir_get_numberval(&_2$$7);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	RETURN_MM_LONG(numberFiles);

}

/**
 * Process a request header and return an array of values with their qualities
 */
PHP_METHOD(Phalcon_Http_Request, getQualityHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serverIndex_param = NULL, *name_param = NULL, returnedParts, part, headerParts, headerPart, split, _0, _1, _2, _3, _4, *_5, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, *_11$$3, _12$$4, _13$$4, _14$$5, _15$$6, _16$$6, _17$$7, _18$$7, _19$$8;
	zval serverIndex, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serverIndex);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&returnedParts);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&headerParts);
	ZVAL_UNDEF(&headerPart);
	ZVAL_UNDEF(&split);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$8);

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
	ZEPHIR_CALL_FUNCTION(&_4, "preg_split", NULL, 58, &_1, &_0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_4, 0, "phalcon/http/request.zep", 1207);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
	{
		ZEPHIR_INIT_NVAR(&part);
		ZVAL_COPY(&part, _5);
		ZEPHIR_INIT_NVAR(&headerParts);
		array_init(&headerParts);
		ZEPHIR_INIT_NVAR(&_6$$3);
		zephir_fast_trim(&_6$$3, &part, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "/\\s*;\\s*/");
		ZVAL_LONG(&_8$$3, -1);
		ZVAL_LONG(&_9$$3, 1);
		ZEPHIR_CALL_FUNCTION(&_10$$3, "preg_split", NULL, 58, &_7$$3, &_6$$3, &_8$$3, &_9$$3);
		zephir_check_call_status();
		zephir_is_iterable(&_10$$3, 0, "phalcon/http/request.zep", 1204);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_10$$3), _11$$3)
		{
			ZEPHIR_INIT_NVAR(&headerPart);
			ZVAL_COPY(&headerPart, _11$$3);
			ZEPHIR_INIT_NVAR(&_12$$4);
			ZVAL_STRING(&_12$$4, "=");
			ZEPHIR_INIT_NVAR(&_13$$4);
			zephir_fast_strpos(&_13$$4, &headerPart, &_12$$4, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&_13$$4)) {
				ZEPHIR_INIT_NVAR(&split);
				zephir_fast_explode_str(&split, SL("="), &headerPart, 2  TSRMLS_CC);
				zephir_array_fetch_long(&_14$$5, &split, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1193 TSRMLS_CC);
				if (ZEPHIR_IS_STRING_IDENTICAL(&_14$$5, "q")) {
					ZEPHIR_OBS_NVAR(&_15$$6);
					zephir_array_fetch_long(&_15$$6, &split, 1, PH_NOISY, "phalcon/http/request.zep", 1194 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_16$$6);
					ZVAL_DOUBLE(&_16$$6, zephir_get_doubleval(&_15$$6));
					zephir_array_update_string(&headerParts, SL("quality"), &_16$$6, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_fetch_long(&_17$$7, &split, 1, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1196 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&_18$$7);
					zephir_array_fetch_long(&_18$$7, &split, 0, PH_NOISY, "phalcon/http/request.zep", 1196 TSRMLS_CC);
					zephir_array_update_zval(&headerParts, &_18$$7, &_17$$7, PH_COPY | PH_SEPARATE);
				}
			} else {
				zephir_array_update_zval(&headerParts, &name, &headerPart, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_19$$8);
				ZVAL_DOUBLE(&_19$$8, 1.0);
				zephir_array_update_string(&headerParts, SL("quality"), &_19$$8, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&headerPart);
		zephir_array_append(&returnedParts, &headerParts, PH_SEPARATE, "phalcon/http/request.zep", 1204);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&part);
	RETURN_CCTOR(&returnedParts);

}

/**
 * Resolve authorization headers.
 */
PHP_METHOD(Phalcon_Http_Request, resolveAuthorizationHeaders) {

	zval headers, _6$$5, _28$$19;
	zend_bool hasEventsManager = 0, _5, _9, _27, _15$$11;
	zval *_SERVER, resolved, eventsManager, container, exploded, digest, authHeader, _0, _1$$3, _2$$3, _3$$4, _4$$4, _7$$5, _8$$6, _10$$7, _11$$7, _12$$11, _13$$11, _14$$11, _16$$11, _17$$12, _18$$12, _19$$12, _20$$13, _21$$13, _22$$17, _23$$17, _24$$17, _25$$17, _26$$17, _29$$19, _30$$20;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

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
		zephir_array_update_string(&_6$$5, SL("server"), _SERVER, PH_COPY | PH_SEPARATE);
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
	_9 = zephir_array_isset_string(_SERVER, SL("PHP_AUTH_USER"));
	if (_9) {
		_9 = zephir_array_isset_string(_SERVER, SL("PHP_AUTH_PW"));
	}
	if (_9) {
		zephir_array_fetch_string(&_10$$7, _SERVER, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1241 TSRMLS_CC);
		zephir_array_update_string(&headers, SL("Php-Auth-User"), &_10$$7, PH_COPY | PH_SEPARATE);
		zephir_array_fetch_string(&_11$$7, _SERVER, SL("PHP_AUTH_PW"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1242 TSRMLS_CC);
		zephir_array_update_string(&headers, SL("Php-Auth-Pw"), &_11$$7, PH_COPY | PH_SEPARATE);
	} else {
		if (zephir_array_isset_string(_SERVER, SL("HTTP_AUTHORIZATION"))) {
			ZEPHIR_OBS_NVAR(&authHeader);
			zephir_array_fetch_string(&authHeader, _SERVER, SL("HTTP_AUTHORIZATION"), PH_NOISY, "phalcon/http/request.zep", 1245 TSRMLS_CC);
		} else if (zephir_array_isset_string(_SERVER, SL("REDIRECT_HTTP_AUTHORIZATION"))) {
			ZEPHIR_OBS_NVAR(&authHeader);
			zephir_array_fetch_string(&authHeader, _SERVER, SL("REDIRECT_HTTP_AUTHORIZATION"), PH_NOISY, "phalcon/http/request.zep", 1247 TSRMLS_CC);
		}
		if (zephir_is_true(&authHeader)) {
			ZEPHIR_INIT_VAR(&_12$$11);
			ZVAL_STRING(&_12$$11, "basic ");
			ZEPHIR_CALL_FUNCTION(&_13$$11, "stripos", NULL, 257, &authHeader, &_12$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_12$$11);
			ZVAL_STRING(&_12$$11, "digest ");
			ZEPHIR_CALL_FUNCTION(&_14$$11, "stripos", NULL, 257, &authHeader, &_12$$11);
			zephir_check_call_status();
			_15$$11 = ZEPHIR_IS_LONG_IDENTICAL(&_14$$11, 0);
			if (_15$$11) {
				ZEPHIR_OBS_VAR(&digest);
				_15$$11 = !(zephir_array_isset_string_fetch(&digest, _SERVER, SL("PHP_AUTH_DIGEST"), 0));
			}
			ZEPHIR_INIT_NVAR(&_12$$11);
			ZVAL_STRING(&_12$$11, "bearer ");
			ZEPHIR_CALL_FUNCTION(&_16$$11, "stripos", NULL, 257, &authHeader, &_12$$11);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_13$$11, 0)) {
				ZVAL_LONG(&_17$$12, 6);
				ZEPHIR_INIT_VAR(&_18$$12);
				zephir_substr(&_18$$12, &authHeader, 6 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CALL_FUNCTION(&_19$$12, "base64_decode", NULL, 123, &_18$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&exploded);
				zephir_fast_explode_str(&exploded, SL(":"), &_19$$12, 2  TSRMLS_CC);
				if (zephir_fast_count_int(&exploded TSRMLS_CC) == 2) {
					zephir_array_fetch_long(&_20$$13, &exploded, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1254 TSRMLS_CC);
					zephir_array_update_string(&headers, SL("Php-Auth-User"), &_20$$13, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_long(&_21$$13, &exploded, 1, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1255 TSRMLS_CC);
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
			zephir_array_fetch_string(&_22$$17, &headers, SL("Php-Auth-User"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1267 TSRMLS_CC);
			zephir_array_fetch_string(&_23$$17, &headers, SL("Php-Auth-Pw"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1267 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_24$$17);
			ZEPHIR_CONCAT_VSV(&_24$$17, &_22$$17, ":", &_23$$17);
			ZEPHIR_CALL_FUNCTION(&_25$$17, "base64_encode", NULL, 122, &_24$$17);
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
		zephir_array_update_string(&_28$$19, SL("server"), _SERVER, PH_COPY | PH_SEPARATE);
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

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval prefix;
	zval *names_param = NULL, *types_param = NULL, *tmp_names_param = NULL, *sizes_param = NULL, *errors_param = NULL, *prefix_param = NULL, idx, name, file, files, parentFiles, p, *_0, _4$$4, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, *_11$$5;
	zval names, types, tmp_names, sizes, errors, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&tmp_names);
	ZVAL_UNDEF(&sizes);
	ZVAL_UNDEF(&errors);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&idx);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&parentFiles);
	ZVAL_UNDEF(&p);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
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
	zephir_is_iterable(&names, 0, "phalcon/http/request.zep", 1329);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&names), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&idx);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&idx, _2);
		} else {
			ZVAL_LONG(&idx, _1);
		}
		ZEPHIR_INIT_NVAR(&name);
		ZVAL_COPY(&name, _0);
		ZEPHIR_INIT_NVAR(&p);
		ZEPHIR_CONCAT_VSV(&p, &prefix, ".", &idx);
		if (Z_TYPE_P(&name) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_3$$4);
			zephir_create_array(&_3$$4, 6, 0 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("name"), &name, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_4$$4);
			zephir_array_fetch(&_4$$4, &types, &idx, PH_NOISY, "phalcon/http/request.zep", 1305 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("type"), &_4$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_4$$4);
			zephir_array_fetch(&_4$$4, &tmp_names, &idx, PH_NOISY, "phalcon/http/request.zep", 1306 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("tmp_name"), &_4$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_4$$4);
			zephir_array_fetch(&_4$$4, &sizes, &idx, PH_NOISY, "phalcon/http/request.zep", 1307 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("size"), &_4$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_4$$4);
			zephir_array_fetch(&_4$$4, &errors, &idx, PH_NOISY, "phalcon/http/request.zep", 1308 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("error"), &_4$$4, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_3$$4, SL("key"), &p, PH_COPY | PH_SEPARATE);
			zephir_array_append(&files, &_3$$4, PH_SEPARATE, "phalcon/http/request.zep", 1310);
		}
		if (Z_TYPE_P(&name) == IS_ARRAY) {
			zephir_array_fetch(&_5$$5, &names, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1315 TSRMLS_CC);
			zephir_array_fetch(&_6$$5, &types, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1316 TSRMLS_CC);
			zephir_array_fetch(&_7$$5, &tmp_names, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1317 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, &sizes, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1318 TSRMLS_CC);
			zephir_array_fetch(&_9$$5, &errors, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1319 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&parentFiles, this_ptr, "smoothfiles", &_10, 260, &_5$$5, &_6$$5, &_7$$5, &_8$$5, &_9$$5, &p);
			zephir_check_call_status();
			zephir_is_iterable(&parentFiles, 0, "phalcon/http/request.zep", 1326);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parentFiles), _11$$5)
			{
				ZEPHIR_INIT_NVAR(&file);
				ZVAL_COPY(&file, _11$$5);
				zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/http/request.zep", 1324);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&file);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_NVAR(&idx);
	RETURN_CCTOR(&files);

}

/**
 * Checks the filter service and assigns it to the class parameter
 */
PHP_METHOD(Phalcon_Http_Request, getFilterLocatorService) {

	zval container, locator, _0$$3, _1$$3, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&locator);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&locator);
	zephir_read_property(&locator, this_ptr, SL("filterLocator"), PH_NOISY_CC);
	if (Z_TYPE_P(&locator) != IS_OBJECT) {
		zephir_read_property(&_0$$3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_0$$3);
		if (Z_TYPE_P(&container) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/request.zep", 1343);
			return;
		}
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "filter");
		ZEPHIR_CALL_METHOD(&_1$$3, &container, "getshared", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&locator, &_1$$3);
		zephir_update_property_zval(this_ptr, SL("filterLocator"), &locator);
	}
	RETURN_MM_MEMBER(getThis(), "filterLocator");

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

