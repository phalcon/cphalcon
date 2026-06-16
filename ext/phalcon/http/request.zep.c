
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/math.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Encapsulates request information for easy and secure access from application
 * controllers.
 *
 * The request object is a simple value object that is passed between the
 * dispatcher and controller classes. It packages the HTTP request environment.
 *
 *```php
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
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Request)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http, Request, phalcon, http_request, phalcon_di_abstractinjectionaware_ce, phalcon_http_request_method_entry, 0);

	/**
	 * @var FilterInterface|null
	 */
	zend_declare_property_null(phalcon_http_request_ce, SL("filterService"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_request_ce, SL("methodOverride"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_request_ce, SL("queryFilters"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|null
	 */
	zend_declare_property_null(phalcon_http_request_ce, SL("postCache"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_request_ce, SL("rawBody"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_request_ce, SL("strictHostCheck"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_request_ce, SL("trustedProxies"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_request_ce, SL("trustedProxyHeader"), "", ZEND_ACC_PROTECTED);
	phalcon_http_request_ce->create_object = zephir_init_properties_Phalcon_Http_Request;

	zend_class_implements(phalcon_http_request_ce, 1, phalcon_http_requestinterface_ce);
	zend_class_implements(phalcon_http_request_ce, 1, phalcon_http_message_requestmethodinterface_ce);
	return SUCCESS;
}

/**
 * Gets a variable from the $_REQUEST superglobal applying filters if
 * needed. If no parameters are given the $_REQUEST superglobal is returned
 *
 *```php
 * // Returns value from $_REQUEST["user_email"] without sanitizing
 * $userEmail = $request->get("user_email");
 *
 * // Returns value from $_REQUEST["user_email"] with sanitizing
 * $userEmail = $request->get("user_email", "email");
 *```
 */
PHP_METHOD(Phalcon_Http_Request, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval name_zv, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _REQUEST, __$null, _0, _1;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(filters)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_BOOL(notAllowEmpty)
		Z_PARAM_BOOL(noRecursive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	if (ZEND_NUM_ARGS() > 1) {
		filters = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		defaultValue = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		notAllowEmpty_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		noRecursive_param = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
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
		}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 0, &_REQUEST, &name_zv, filters, defaultValue, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets an array with mime/types and their quality accepted by the
 * browser/client from _SERVER["HTTP_ACCEPT"]
 */
PHP_METHOD(Phalcon_Http_Request, getAcceptableContent)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "accept");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getqualityheader", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets auth info accepted by the browser/client from
 * $_SERVER["PHP_AUTH_USER"]
 */
PHP_METHOD(Phalcon_Http_Request, getBasicAuth)
{
	zval password, server, username;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&username);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&server, this_ptr, "getserverarray", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_array_isset_string_fetch(&username, &server, SL("PHP_AUTH_USER"), 1))) {
		RETURN_MM_NULL();
	}
	zephir_memory_observe(&password);
	if (!(zephir_array_isset_string_fetch(&password, &server, SL("PHP_AUTH_PW"), 0))) {
		ZEPHIR_INIT_NVAR(&password);
		ZVAL_NULL(&password);
	}
	zephir_create_array(return_value, 2, 0);
	zephir_array_update_string(return_value, SL("username"), &username, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("password"), &password, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Gets best mime/type accepted by the browser/client from
 * _SERVER["HTTP_ACCEPT"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestAccept)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getacceptablecontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "accept");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbestquality", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets best charset accepted by the browser/client from
 * _SERVER["HTTP_ACCEPT_CHARSET"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestCharset)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclientcharsets", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "charset");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbestquality", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets best language accepted by the browser/client from
 * _SERVER["HTTP_ACCEPT_LANGUAGE"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestLanguage)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getlanguages", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "language");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbestquality", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets most possible client IP Address. This method searches in
 * `$_SERVER["REMOTE_ADDR"]` and optionally in
 * `$_SERVER["HTTP_X_FORWARDED_FOR"]` and returns the first non-private or non-reserved IP address
 *
 * The user provided trusted header takes priority before checking X-Forwarded-For header.
 *
 * Using trusted proxies list, user has to provide a trusted list of proxy IPs
 * ```
 * $request
 *     ->setTrustedProxies($trustedProxies)
 *     ->getClientAddress(true);
 * ```
 * Using user provided trusted header, header should only ever contain 1 IP address, eg. HTTP_CLIENT_IP
 * ```
 * $request
 *     ->setTrustedProxyHeader('HTTP_CLIENT_IP')
 *     ->setTrustedProxies($trustedProxies)
 *     ->getClientAddress(true);
 * ```
 *
 * @param bool $trustForwardedHeader
 *
 * @return string|false
 * @throws \Exception
 */
PHP_METHOD(Phalcon_Http_Request, getClientAddress)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *trustForwardedHeader_param = NULL, server, address, trustedProxyHeaderIp, forwarded, forwardedIps, reverseForwardedIps, forwardedIp, filteredIp, _0$$4, _2$$4, _4$$4, _1$$5, _5$$8, _6$$8, *_7$$8, _12$$8, _8$$9, _10$$9, _14$$12, _16$$12;
	zend_bool trustForwardedHeader, _3$$4, _13$$8, _9$$9, _15$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&address);
	ZVAL_UNDEF(&trustedProxyHeaderIp);
	ZVAL_UNDEF(&forwarded);
	ZVAL_UNDEF(&forwardedIps);
	ZVAL_UNDEF(&reverseForwardedIps);
	ZVAL_UNDEF(&forwardedIp);
	ZVAL_UNDEF(&filteredIp);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_16$$12);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(trustForwardedHeader)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &trustForwardedHeader_param);
	if (!trustForwardedHeader_param) {
		trustForwardedHeader = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&server, this_ptr, "getserverarray", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&address);
	zephir_array_isset_string_fetch(&address, &server, SL("REMOTE_ADDR"), 0);
	if (!(Z_TYPE_P(&address) == IS_STRING)) {
		RETURN_MM_BOOL(0);
	}
	if (trustForwardedHeader) {
		zephir_read_property(&_0$$4, this_ptr, ZEND_STRL("trustedProxyHeader"), PH_NOISY_CC | PH_READONLY);
		if (!ZEPHIR_IS_STRING_IDENTICAL(&_0$$4, "")) {
			zephir_memory_observe(&trustedProxyHeaderIp);
			zephir_read_property(&_1$$5, this_ptr, ZEND_STRL("trustedProxyHeader"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset_fetch(&trustedProxyHeaderIp, &server, &_1$$5, 0)) {
				RETURN_CCTOR(&trustedProxyHeaderIp);
			}
		}
		zephir_memory_observe(&_2$$4);
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("trustedProxies"), PH_NOISY_CC);
		_3$$4 = !(ZEPHIR_IS_EMPTY(&_2$$4));
		if (_3$$4) {
			ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "isproxytrusted", NULL, 0, &address);
			zephir_check_call_status();
			_3$$4 = !zephir_is_true(&_4$$4);
		}
		if (_3$$4) {
			RETURN_CCTOR(&address);
		}
		zephir_memory_observe(&forwarded);
		zephir_array_isset_string_fetch(&forwarded, &server, SL("HTTP_X_FORWARDED_FOR"), 0);
		if (!(ZEPHIR_IS_EMPTY(&forwarded))) {
			ZEPHIR_INIT_VAR(&_5$$8);
			zephir_fast_explode_str(&_5$$8, SL(","), &forwarded, LONG_MAX);
			ZEPHIR_INIT_VAR(&_6$$8);
			ZVAL_STRING(&_6$$8, "trim");
			ZEPHIR_CALL_FUNCTION(&forwardedIps, "array_map", NULL, 21, &_6$$8, &_5$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&reverseForwardedIps, "array_reverse", NULL, 202, &forwardedIps);
			zephir_check_call_status();
			zephir_is_iterable(&reverseForwardedIps, 0, "phalcon/Http/Request.zep", 257);
			if (Z_TYPE_P(&reverseForwardedIps) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&reverseForwardedIps), _7$$8)
				{
					ZEPHIR_INIT_NVAR(&forwardedIp);
					ZVAL_COPY(&forwardedIp, _7$$8);
					ZEPHIR_OBS_NVAR(&_8$$9);
					zephir_read_property(&_8$$9, this_ptr, ZEND_STRL("trustedProxies"), PH_NOISY_CC);
					_9$$9 = !(ZEPHIR_IS_EMPTY(&_8$$9));
					if (_9$$9) {
						ZEPHIR_CALL_METHOD(&_10$$9, this_ptr, "isproxytrusted", NULL, 0, &forwardedIp);
						zephir_check_call_status();
						_9$$9 = zephir_is_true(&_10$$9);
					}
					if (_9$$9) {
						continue;
					}
					ZEPHIR_CALL_METHOD(&filteredIp, this_ptr, "isvalidpublicip", &_11, 0, &forwardedIp);
					zephir_check_call_status();
					if (zephir_is_true(&filteredIp)) {
						RETURN_CCTOR(&filteredIp);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &reverseForwardedIps, "rewind", NULL, 0);
				zephir_check_call_status();
				_13$$8 = 1;
				while (1) {
					if (_13$$8) {
						_13$$8 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &reverseForwardedIps, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_12$$8, &reverseForwardedIps, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_12$$8)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&forwardedIp, &reverseForwardedIps, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&_14$$12);
						zephir_read_property(&_14$$12, this_ptr, ZEND_STRL("trustedProxies"), PH_NOISY_CC);
						_15$$12 = !(ZEPHIR_IS_EMPTY(&_14$$12));
						if (_15$$12) {
							ZEPHIR_CALL_METHOD(&_16$$12, this_ptr, "isproxytrusted", NULL, 0, &forwardedIp);
							zephir_check_call_status();
							_15$$12 = zephir_is_true(&_16$$12);
						}
						if (_15$$12) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&filteredIp, this_ptr, "isvalidpublicip", &_11, 0, &forwardedIp);
						zephir_check_call_status();
						if (zephir_is_true(&filteredIp)) {
							RETURN_CCTOR(&filteredIp);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&forwardedIp);
		}
	}
	RETURN_CCTOR(&address);
}

/**
 * Gets a charsets array and their quality accepted by the browser/client
 * from _SERVER["HTTP_ACCEPT_CHARSET"]
 */
PHP_METHOD(Phalcon_Http_Request, getClientCharsets)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT_CHARSET");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "charset");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getqualityheader", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets content type which request has been made
 */
PHP_METHOD(Phalcon_Http_Request, getContentType)
{
	zval contentType, server;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contentType);
	ZVAL_UNDEF(&server);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&server, this_ptr, "getserverarray", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_array_isset_string_fetch(&contentType, &server, SL("CONTENT_TYPE"), 1))) {
		RETURN_MM_NULL();
	}
	RETURN_CTOR(&contentType);
}

/**
 * Gets auth info accepted by the browser/client from
 * $_SERVER["PHP_AUTH_DIGEST"]
 */
PHP_METHOD(Phalcon_Http_Request, getDigestAuth)
{
	zval auth;
	zval digest, matches, match, server, _0$$3, _1$$3, _2$$3, *_3$$5, _4$$6, _5$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&digest);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&auth);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&auth);
	array_init(&auth);
	ZEPHIR_CALL_METHOD(&server, this_ptr, "getserverarray", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&digest);
	if (zephir_array_isset_string_fetch(&digest, &server, SL("PHP_AUTH_DIGEST"), 0)) {
		ZEPHIR_INIT_VAR(&matches);
		array_init(&matches);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "#(\\w+)=(['\"]?)([^'\" ,]+)\\2#");
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "#(\\w+)=(['\"]?)([^'\" ,]+)\\2#");
		zephir_preg_match(&_1$$3, &_2$$3, &digest, &matches, 1, 2 , 0 );
		if (!(zephir_is_true(&_1$$3))) {
			RETURN_CTOR(&auth);
		}
		if (Z_TYPE_P(&matches) == IS_ARRAY) {
			zephir_is_iterable(&matches, 0, "phalcon/Http/Request.zep", 311);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _3$$5)
			{
				ZEPHIR_INIT_NVAR(&match);
				ZVAL_COPY(&match, _3$$5);
				zephir_array_fetch_long(&_4$$6, &match, 3, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 309);
				ZEPHIR_OBS_NVAR(&_5$$6);
				zephir_array_fetch_long(&_5$$6, &match, 1, PH_NOISY, "phalcon/Http/Request.zep", 309);
				zephir_array_update_zval(&auth, &_5$$6, &_4$$6, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&match);
		}
	}
	RETURN_CTOR(&auth);
}

/**
 * Gets filtered data
 */
PHP_METHOD(Phalcon_Http_Request, getFilteredData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval methodKey_zv, method_zv, name_zv, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, filters, _0, _1, _2, _3;
	zend_string *methodKey = NULL, *method = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&methodKey_zv);
	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 6)
		Z_PARAM_STR(methodKey)
		Z_PARAM_STR(method)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_BOOL(notAllowEmpty)
		Z_PARAM_BOOL(noRecursive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 3) {
		defaultValue = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		notAllowEmpty_param = ZEND_CALL_ARG(execute_data, 5);
	}
	if (ZEND_NUM_ARGS() > 5) {
		noRecursive_param = ZEND_CALL_ARG(execute_data, 6);
	}
	zephir_memory_observe(&methodKey_zv);
	ZVAL_STR_COPY(&methodKey_zv, methodKey);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		}
	zephir_memory_observe(&filters);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("queryFilters"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, &methodKey_zv, PH_READONLY, "phalcon/Http/Request.zep", 330);
	if (!(zephir_array_isset_fetch(&filters, &_1, &name_zv, 0))) {
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
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method_zv, NULL, 0, &name_zv, &filters, defaultValue, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Retrieves a patch value always sanitized with the preset filters
 */
PHP_METHOD(Phalcon_Http_Request, getFilteredPatch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval name_zv, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, _0, _1, _2, _3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_BOOL(notAllowEmpty)
		Z_PARAM_BOOL(noRecursive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		notAllowEmpty_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		noRecursive_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PATCH");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "getPatch");
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfiltereddata", NULL, 0, &_0, &_1, &name_zv, defaultValue, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Retrieves a post value always sanitized with the preset filters
 */
PHP_METHOD(Phalcon_Http_Request, getFilteredPost)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval name_zv, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, _0, _1, _2, _3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_BOOL(notAllowEmpty)
		Z_PARAM_BOOL(noRecursive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		notAllowEmpty_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		noRecursive_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "POST");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "getPost");
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfiltereddata", NULL, 0, &_0, &_1, &name_zv, defaultValue, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Retrieves a put value always sanitized with the preset filters
 */
PHP_METHOD(Phalcon_Http_Request, getFilteredPut)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval name_zv, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, _0, _1, _2, _3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_BOOL(notAllowEmpty)
		Z_PARAM_BOOL(noRecursive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		notAllowEmpty_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		noRecursive_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PUT");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "getPut");
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfiltereddata", NULL, 0, &_0, &_1, &name_zv, defaultValue, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Retrieves a query/get value always sanitized with the preset filters
 */
PHP_METHOD(Phalcon_Http_Request, getFilteredQuery)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval name_zv, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, _0, _1, _2, _3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_BOOL(notAllowEmpty)
		Z_PARAM_BOOL(noRecursive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		notAllowEmpty_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		noRecursive_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GET");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "getQuery");
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfiltereddata", NULL, 0, &_0, &_1, &name_zv, defaultValue, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets HTTP header from request data
 */
PHP_METHOD(Phalcon_Http_Request, getHeader)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval header_zv, value, name, server, _0, _1, _2, _3;
	zend_string *header = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(header)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&header_zv);
	ZVAL_STR_COPY(&header_zv, header);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "-");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_");
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 4, &header_zv, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	zephir_fast_strtoupper(&name, &_2);
	ZEPHIR_CALL_METHOD(&server, this_ptr, "getserverarray", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&value);
	if (zephir_array_isset_fetch(&value, &server, &name, 0)) {
		RETURN_CCTOR(&value);
	}
	ZEPHIR_OBS_NVAR(&value);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "HTTP_", &name);
	if (zephir_array_isset_fetch(&value, &server, &_3, 0)) {
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
PHP_METHOD(Phalcon_Http_Request, getHeaders)
{
	zend_bool _22;
	zend_string *_2;
	zend_ulong _1;
	zval headers, contentHeaders;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, name, value, authHeaders, server, *_0, _21, _40, _3$$4, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _10$$4, _11$$4, _12$$4, _13$$3, _14$$5, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5, _23$$7, _24$$7, _25$$7, _26$$7, _27$$7, _28$$7, _29$$7, _30$$7, _31$$7, _32$$6, _33$$8, _34$$8, _35$$8, _36$$8, _37$$8, _38$$8, _39$$8;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&authHeaders);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_40);
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
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_32$$6);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_35$$8);
	ZVAL_UNDEF(&_36$$8);
	ZVAL_UNDEF(&_37$$8);
	ZVAL_UNDEF(&_38$$8);
	ZVAL_UNDEF(&_39$$8);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&contentHeaders);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	ZEPHIR_INIT_VAR(&contentHeaders);
	zephir_create_array(&contentHeaders, 3, 0);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_TYPE"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_LENGTH"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_MD5"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&server, this_ptr, "getserverarray", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&server, 0, "phalcon/Http/Request.zep", 507);
	if (Z_TYPE_P(&server) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&server), _1, _2, _0)
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
				zephir_fast_str_replace(&_4$$4, &_7$$4, &_8$$4, &_6$$4);
				zephir_fast_strtolower(&_3$$4, &_4$$4);
				ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_9, 0, &_3$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$4);
				ZEPHIR_INIT_NVAR(&_11$$4);
				ZVAL_STRING(&_11$$4, " ");
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZVAL_STRING(&_12$$4, "-");
				zephir_fast_str_replace(&_10$$4, &_11$$4, &_12$$4, &name);
				ZEPHIR_CPY_WRT(&name, &_10$$4);
				zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
				continue;
			}
			ZEPHIR_INIT_NVAR(&_13$$3);
			zephir_fast_strtoupper(&_13$$3, &name);
			ZEPHIR_CPY_WRT(&name, &_13$$3);
			if (zephir_array_isset_value(&contentHeaders, &name)) {
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZEPHIR_INIT_NVAR(&_15$$5);
				ZEPHIR_INIT_NVAR(&_16$$5);
				ZVAL_STRING(&_16$$5, "_");
				ZEPHIR_INIT_NVAR(&_17$$5);
				ZVAL_STRING(&_17$$5, " ");
				zephir_fast_str_replace(&_15$$5, &_16$$5, &_17$$5, &name);
				zephir_fast_strtolower(&_14$$5, &_15$$5);
				ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_9, 0, &_14$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_18$$5);
				ZEPHIR_INIT_NVAR(&_19$$5);
				ZVAL_STRING(&_19$$5, " ");
				ZEPHIR_INIT_NVAR(&_20$$5);
				ZVAL_STRING(&_20$$5, "-");
				zephir_fast_str_replace(&_18$$5, &_19$$5, &_20$$5, &name);
				ZEPHIR_CPY_WRT(&name, &_18$$5);
				zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &server, "rewind", NULL, 0);
		zephir_check_call_status();
		_22 = 1;
		while (1) {
			if (_22) {
				_22 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &server, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_21, &server, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_21)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &server, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &server, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_start_with_str(&name, SL("HTTP_"))) {
					ZEPHIR_INIT_NVAR(&_23$$7);
					ZEPHIR_INIT_NVAR(&_24$$7);
					ZVAL_LONG(&_25$$7, 5);
					ZEPHIR_INIT_NVAR(&_26$$7);
					zephir_substr(&_26$$7, &name, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					ZEPHIR_INIT_NVAR(&_27$$7);
					ZVAL_STRING(&_27$$7, "_");
					ZEPHIR_INIT_NVAR(&_28$$7);
					ZVAL_STRING(&_28$$7, " ");
					zephir_fast_str_replace(&_24$$7, &_27$$7, &_28$$7, &_26$$7);
					zephir_fast_strtolower(&_23$$7, &_24$$7);
					ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_9, 0, &_23$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_29$$7);
					ZEPHIR_INIT_NVAR(&_30$$7);
					ZVAL_STRING(&_30$$7, " ");
					ZEPHIR_INIT_NVAR(&_31$$7);
					ZVAL_STRING(&_31$$7, "-");
					zephir_fast_str_replace(&_29$$7, &_30$$7, &_31$$7, &name);
					ZEPHIR_CPY_WRT(&name, &_29$$7);
					zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
					continue;
				}
				ZEPHIR_INIT_NVAR(&_32$$6);
				zephir_fast_strtoupper(&_32$$6, &name);
				ZEPHIR_CPY_WRT(&name, &_32$$6);
				if (zephir_array_isset_value(&contentHeaders, &name)) {
					ZEPHIR_INIT_NVAR(&_33$$8);
					ZEPHIR_INIT_NVAR(&_34$$8);
					ZEPHIR_INIT_NVAR(&_35$$8);
					ZVAL_STRING(&_35$$8, "_");
					ZEPHIR_INIT_NVAR(&_36$$8);
					ZVAL_STRING(&_36$$8, " ");
					zephir_fast_str_replace(&_34$$8, &_35$$8, &_36$$8, &name);
					zephir_fast_strtolower(&_33$$8, &_34$$8);
					ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_9, 0, &_33$$8);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_37$$8);
					ZEPHIR_INIT_NVAR(&_38$$8);
					ZVAL_STRING(&_38$$8, " ");
					ZEPHIR_INIT_NVAR(&_39$$8);
					ZVAL_STRING(&_39$$8, "-");
					zephir_fast_str_replace(&_37$$8, &_38$$8, &_39$$8, &name);
					ZEPHIR_CPY_WRT(&name, &_37$$8);
					zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_CALL_METHOD(&authHeaders, this_ptr, "resolveauthorizationheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_40);
	zephir_fast_array_merge(&_40, &headers, &authHeaders);
	ZEPHIR_CPY_WRT(&headers, &_40);
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
 * ```php
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
 * ```
 */
PHP_METHOD(Phalcon_Http_Request, getHttpHost)
{
	zval _13;
	zend_bool _3;
	zval host, strict, cleanHost, _0, _1$$3, _2$$4, _4$$5, _8$$5, _9$$5, _10$$5, _11$$5, _5$$6, _6$$6, _7$$6, _12$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&strict);
	ZVAL_UNDEF(&cleanHost);
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
	ZVAL_UNDEF(&_13);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&strict);
	zephir_read_property(&strict, this_ptr, ZEND_STRL("strictHostCheck"), PH_NOISY_CC);
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
		zephir_fast_trim(&_4$$5, &host, NULL , ZEPHIR_TRIM_BOTH);
		ZEPHIR_INIT_VAR(&cleanHost);
		zephir_fast_strtolower(&cleanHost, &_4$$5);
		if (zephir_memnstr_str(&cleanHost, SL(":"), "phalcon/Http/Request.zep", 581)) {
			ZEPHIR_INIT_VAR(&_5$$6);
			ZVAL_STRING(&_5$$6, "/:[[:digit:]]+$/");
			ZEPHIR_INIT_VAR(&_6$$6);
			ZVAL_STRING(&_6$$6, "");
			ZEPHIR_CALL_FUNCTION(&_7$$6, "preg_replace", NULL, 79, &_5$$6, &_6$$6, &cleanHost);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&cleanHost, &_7$$6);
		}
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "/[a-z0-9-]+\\.?/");
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "");
		ZEPHIR_CALL_FUNCTION(&_10$$5, "preg_replace", NULL, 79, &_8$$5, &_9$$5, &cleanHost);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_11$$5);
		ZVAL_STRING(&_11$$5, "");
		if (UNEXPECTED(!ZEPHIR_IS_IDENTICAL(&_11$$5, &_10$$5))) {
			ZEPHIR_INIT_VAR(&_12$$7);
			object_init_ex(&_12$$7, phalcon_http_request_exceptions_invalidhost_ce);
			ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", NULL, 0, &host);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_12$$7, "phalcon/Http/Request.zep", 591);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CPY_WRT(&cleanHost, &host);
	}
	zephir_cast_to_string(&_13, &cleanHost);
	RETURN_CTOR(&_13);
}

/**
 * Return the HTTP method parameter override flag
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Http_Request, getHttpMethodParameterOverride)
{

	RETURN_MEMBER(getThis(), "methodOverride");
}

/**
 * Gets web page that refers active request. ie: http://www.google.com
 */
PHP_METHOD(Phalcon_Http_Request, getHTTPReferer)
{
	zval httpReferer, server;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpReferer);
	ZVAL_UNDEF(&server);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&server, this_ptr, "getserverarray", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_array_isset_string_fetch(&httpReferer, &server, SL("HTTP_REFERER"), 1))) {
		RETURN_MM_STRING("");
	}
	RETURN_CTOR(&httpReferer);
}

/**
 * Gets decoded JSON HTTP raw request body
 */
PHP_METHOD(Phalcon_Http_Request, getJsonRawBody)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *associative_param = NULL, rawBody, _0, _1;
	zend_bool associative;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawBody);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(associative)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &associative_param);
	if (!associative_param) {
		associative = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&rawBody, this_ptr, "getrawbody", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&rawBody) != IS_STRING) {
		RETURN_MM_BOOL(0);
	}
	if (ZEPHIR_IS_STRING(&rawBody, "")) {
		ZEPHIR_INIT_NVAR(&rawBody);
		ZVAL_STRING(&rawBody, "{}");
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_helper_json_decode_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	if (associative) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(&_0, "__invoke", NULL, 312, &rawBody, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets languages array and their quality accepted by the browser/client
 * from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 */
PHP_METHOD(Phalcon_Http_Request, getLanguages)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT_LANGUAGE");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "language");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getqualityheader", NULL, 0, &_0, &_1);
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
PHP_METHOD(Phalcon_Http_Request, getMethod)
{
	zval returnMethod;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _REQUEST, overridedMethod, spoofedMethod, requestMethod, server, _0, _3, _1$$5, _2$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_REQUEST);
	ZVAL_UNDEF(&overridedMethod);
	ZVAL_UNDEF(&spoofedMethod);
	ZVAL_UNDEF(&requestMethod);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&returnMethod);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_REQUEST, SL("_REQUEST"));

	ZEPHIR_INIT_VAR(&returnMethod);
	ZVAL_STRING(&returnMethod, "");
	ZEPHIR_CALL_METHOD(&server, this_ptr, "getserverarray", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&requestMethod);
	if (EXPECTED(zephir_array_isset_string_fetch(&requestMethod, &server, SL("REQUEST_METHOD"), 0))) {
		ZEPHIR_INIT_NVAR(&returnMethod);
		zephir_fast_strtoupper(&returnMethod, &requestMethod);
	} else {
		RETURN_MM_STRING("GET");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "POST");
	if (ZEPHIR_IS_IDENTICAL(&_0, &returnMethod)) {
		ZEPHIR_INIT_VAR(&_1$$5);
		ZVAL_STRING(&_1$$5, "X-HTTP-METHOD-OVERRIDE");
		ZEPHIR_CALL_METHOD(&overridedMethod, this_ptr, "getheader", NULL, 0, &_1$$5);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&overridedMethod))) {
			ZEPHIR_INIT_NVAR(&returnMethod);
			zephir_fast_strtoupper(&returnMethod, &overridedMethod);
		} else {
			zephir_read_property(&_2$$5, this_ptr, ZEND_STRL("methodOverride"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_2$$5)) {
				zephir_memory_observe(&spoofedMethod);
				if (zephir_array_isset_string_fetch(&spoofedMethod, &_REQUEST, SL("_method"), 0)) {
					ZEPHIR_INIT_NVAR(&returnMethod);
					zephir_fast_strtoupper(&returnMethod, &spoofedMethod);
				}
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
 * Gets a variable from put request
 *
 *```php
 * // Returns value from $_PATCH["user_email"] without sanitizing
 * $userEmail = $request->getPatch("user_email");
 *
 * // Returns value from $_PATCH["user_email"] with sanitizing
 * $userEmail = $request->getPatch("user_email", "email");
 *```
 */
PHP_METHOD(Phalcon_Http_Request, getPatch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval name_zv, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, _0, _1, _2, _3, _4;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(filters)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_BOOL(notAllowEmpty)
		Z_PARAM_BOOL(noRecursive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filters = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		defaultValue = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		notAllowEmpty_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		noRecursive_param = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
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
		}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("postCache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpostdata", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("postCache"), &_0);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("postCache"), PH_NOISY_CC | PH_READONLY);
	if (notAllowEmpty) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 0, &_2, &name_zv, filters, defaultValue, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets information about the port on which the request is made.
 */
PHP_METHOD(Phalcon_Http_Request, getPort)
{
	zval host, pos, _0, _6, _7, _1$$3, _2$$3, _3$$4, _4$$5, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	if (zephir_memnstr_str(&host, SL(":"), "phalcon/Http/Request.zep", 744)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, ":");
		ZEPHIR_CALL_FUNCTION(&pos, "strrpos", NULL, 510, &host, &_3$$4);
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
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "https");
	if (ZEPHIR_IS_IDENTICAL(&_7, &_6)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, 443);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, 80);
	}
	RETURN_CCTOR(&_0);
}

/**
 * Gets a variable from the $_POST superglobal applying filters if needed
 * If no parameters are given the $_POST superglobal is returned
 *
 *```php
 * // Returns value from $_POST["user_email"] without sanitizing
 * $userEmail = $request->getPost("user_email");
 *
 * // Returns value from $_POST["user_email"] with sanitizing
 * $userEmail = $request->getPost("user_email", "email");
 *```
 */
PHP_METHOD(Phalcon_Http_Request, getPost)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval name_zv, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _POST, __$null, _0, _1, _2, _3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_POST);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(filters)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_BOOL(notAllowEmpty)
		Z_PARAM_BOOL(noRecursive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_POST, SL("_POST"));
	if (ZEND_NUM_ARGS() > 1) {
		filters = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		defaultValue = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		notAllowEmpty_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		noRecursive_param = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
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
		}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpostdata", NULL, 0, &_POST);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("postCache"), &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("postCache"), PH_NOISY_CC | PH_READONLY);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 0, &_1, &name_zv, filters, defaultValue, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets the preferred ISO locale variant.
 *
 * Gets the preferred locale accepted by the client from the
 * "Accept-Language" request HTTP header and returns the
 * base part of it i.e. `en` instead of `en-US`.
 *
 * Note: This method relies on the `$_SERVER["HTTP_ACCEPT_LANGUAGE"]` header.
 *
 * @link https://www.iso.org/standard/50707.html
 */
PHP_METHOD(Phalcon_Http_Request, getPreferredIsoLocaleVariant)
{
	zval language, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&language);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&language, this_ptr, "getbestlanguage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_explode_str(&_0, SL("-"), &language, LONG_MAX);
	ZEPHIR_CPY_WRT(&language, &_0);
	zephir_array_fetch_long(&_1, &language, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 803);
	ZEPHIR_CPY_WRT(&language, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "*");
	if (ZEPHIR_IS_IDENTICAL(&_3, &language)) {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "");
	} else {
		ZEPHIR_CPY_WRT(&_2, &language);
	}
	ZEPHIR_CPY_WRT(&language, &_2);
	RETURN_CCTOR(&language);
}

/**
 * Gets a variable from the PUT request
 *
 *```php
 * // Returns value from PUT stream without sanitizing
 * $userEmail = $request->getPut("user_email");
 *
 * // Returns value from PUT stream with sanitizing
 * $userEmail = $request->getPut("user_email", "email");
 *```
 */
PHP_METHOD(Phalcon_Http_Request, getPut)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval name_zv, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, _0, _1, _2, _3, _4;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(filters)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_BOOL(notAllowEmpty)
		Z_PARAM_BOOL(noRecursive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filters = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		defaultValue = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		notAllowEmpty_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		noRecursive_param = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
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
		}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("postCache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpostdata", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("postCache"), &_0);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("postCache"), PH_NOISY_CC | PH_READONLY);
	if (notAllowEmpty) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 0, &_2, &name_zv, filters, defaultValue, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets variable from $_GET superglobal applying filters if needed
 * If no parameters are given the $_GET superglobal is returned
 *
 *```php
 * // Returns value from $_GET["id"] without sanitizing
 * $id = $request->getQuery("id");
 *
 * // Returns value from $_GET["id"] with sanitizing
 * $id = $request->getQuery("id", "int");
 *
 * // Returns value from $_GET["id"] with a default value
 * $id = $request->getQuery("id", null, 150);
 *```
 */
PHP_METHOD(Phalcon_Http_Request, getQuery)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval name_zv, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _GET, __$null, _0, _1;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_GET);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(filters)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_BOOL(notAllowEmpty)
		Z_PARAM_BOOL(noRecursive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_GET, SL("_GET"));
	if (ZEND_NUM_ARGS() > 1) {
		filters = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		defaultValue = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		notAllowEmpty_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		noRecursive_param = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
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
		}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 0, &_GET, &name_zv, filters, defaultValue, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets HTTP raw request body
 */
PHP_METHOD(Phalcon_Http_Request, getRawBody)
{
	zval rawBody, contents, _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawBody);
	ZVAL_UNDEF(&contents);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("rawBody"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&rawBody, &_0);
	if (ZEPHIR_IS_EMPTY(&rawBody)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "php://input");
		ZEPHIR_INIT_VAR(&contents);
		zephir_file_get_contents(&contents, &_1$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("rawBody"), &contents);
		RETURN_CCTOR(&contents);
	}
	RETURN_CCTOR(&rawBody);
}

/**
 * Gets HTTP schema (http/https)
 */
PHP_METHOD(Phalcon_Http_Request, getScheme)
{
	zend_bool _1;
	zval https, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&https);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
PHP_METHOD(Phalcon_Http_Request, getServer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, serverValue, server;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&serverValue);
	ZVAL_UNDEF(&server);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&server, this_ptr, "getserverarray", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_array_isset_fetch(&serverValue, &server, &name_zv, 1))) {
		RETURN_MM_NULL();
	}
	RETURN_CTOR(&serverValue);
}

/**
 * Gets active server address IP
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress)
{
	zval serverAddr, _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serverAddr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "SERVER_ADDR");
	ZEPHIR_CALL_METHOD(&serverAddr, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&serverAddr) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "localhost");
		ZEPHIR_RETURN_CALL_FUNCTION("gethostbyname", NULL, 0, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&serverAddr);
}

/**
 * Gets active server name
 */
PHP_METHOD(Phalcon_Http_Request, getServerName)
{
	zval serverName, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serverName);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "SERVER_NAME");
	ZEPHIR_CALL_METHOD(&serverName, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	if (zephir_is_true(&serverName)) {
		ZEPHIR_CPY_WRT(&_0, &serverName);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "localhost");
	}
	RETURN_CCTOR(&_0);
}

/**
 * Gets attached files as Phalcon\Http\Request\File instances
 */
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles)
{
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zval files;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *onlySuccessful_param = NULL, *namedKeys_param = NULL, _FILES, superFiles, prefix, input, smoothInput, file, dataFile, *_0$$3, _3$$4, _4$$5, _5$$5, _6$$5, _7$$5, _8$$5, *_10$$5, _18$$5, _12$$6, _13$$7, _14$$7, _15$$7, _16$$7, _21$$8, _22$$9, _23$$9, _24$$9, _25$$9, _26$$9, _28$$10, _29$$11, _30$$11;
	zend_bool onlySuccessful, namedKeys, _19$$5, _11$$6, _20$$8, _27$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_FILES);
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
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&files);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(onlySuccessful)
		Z_PARAM_BOOL(namedKeys)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_fetch_params(1, 0, 2, &onlySuccessful_param, &namedKeys_param);
	if (!onlySuccessful_param) {
		onlySuccessful = 0;
	} else {
		}
	if (!namedKeys_param) {
		namedKeys = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	ZEPHIR_CPY_WRT(&superFiles, &_FILES);
	if (zephir_fast_count_int(&superFiles) > 0) {
		zephir_is_iterable(&superFiles, 0, "phalcon/Http/Request.zep", 1007);
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
			zephir_array_fetch_string(&_3$$4, &input, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 968);
			if (Z_TYPE_P(&_3$$4) == IS_ARRAY) {
				zephir_array_fetch_string(&_4$$5, &input, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 970);
				zephir_array_fetch_string(&_5$$5, &input, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 971);
				zephir_array_fetch_string(&_6$$5, &input, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 972);
				zephir_array_fetch_string(&_7$$5, &input, SL("size"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 973);
				zephir_array_fetch_string(&_8$$5, &input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 974);
				ZEPHIR_CALL_METHOD(&smoothInput, this_ptr, "smoothfiles", &_9, 0, &_4$$5, &_5$$5, &_6$$5, &_7$$5, &_8$$5, &prefix);
				zephir_check_call_status();
				zephir_is_iterable(&smoothInput, 0, "phalcon/Http/Request.zep", 996);
				if (Z_TYPE_P(&smoothInput) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&smoothInput), _10$$5)
					{
						ZEPHIR_INIT_NVAR(&file);
						ZVAL_COPY(&file, _10$$5);
						_11$$6 = onlySuccessful == 0;
						if (!(_11$$6)) {
							zephir_array_fetch_string(&_12$$6, &file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 979);
							_11$$6 = ZEPHIR_IS_LONG(&_12$$6, 0);
						}
						if (_11$$6) {
							ZEPHIR_INIT_NVAR(&dataFile);
							zephir_create_array(&dataFile, 5, 0);
							ZEPHIR_OBS_NVAR(&_13$$7);
							zephir_array_fetch_string(&_13$$7, &file, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 981);
							zephir_array_update_string(&dataFile, SL("name"), &_13$$7, PH_COPY | PH_SEPARATE);
							ZEPHIR_OBS_NVAR(&_13$$7);
							zephir_array_fetch_string(&_13$$7, &file, SL("type"), PH_NOISY, "phalcon/Http/Request.zep", 982);
							zephir_array_update_string(&dataFile, SL("type"), &_13$$7, PH_COPY | PH_SEPARATE);
							ZEPHIR_OBS_NVAR(&_13$$7);
							zephir_array_fetch_string(&_13$$7, &file, SL("tmp_name"), PH_NOISY, "phalcon/Http/Request.zep", 983);
							zephir_array_update_string(&dataFile, SL("tmp_name"), &_13$$7, PH_COPY | PH_SEPARATE);
							ZEPHIR_OBS_NVAR(&_13$$7);
							zephir_array_fetch_string(&_13$$7, &file, SL("size"), PH_NOISY, "phalcon/Http/Request.zep", 984);
							zephir_array_update_string(&dataFile, SL("size"), &_13$$7, PH_COPY | PH_SEPARATE);
							ZEPHIR_OBS_NVAR(&_13$$7);
							zephir_array_fetch_string(&_13$$7, &file, SL("error"), PH_NOISY, "phalcon/Http/Request.zep", 986);
							zephir_array_update_string(&dataFile, SL("error"), &_13$$7, PH_COPY | PH_SEPARATE);
							zephir_array_fetch_string(&_15$$7, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 993);
							if (namedKeys) {
								ZVAL_BOOL(&_16$$7, 1);
							} else {
								ZVAL_BOOL(&_16$$7, 0);
							}
							ZEPHIR_CALL_METHOD(&_14$$7, this_ptr, "processfiles", &_17, 0, &files, &_16$$7, &dataFile, &_15$$7);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&files, &_14$$7);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &smoothInput, "rewind", NULL, 0);
					zephir_check_call_status();
					_19$$5 = 1;
					while (1) {
						if (_19$$5) {
							_19$$5 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &smoothInput, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_18$$5, &smoothInput, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_18$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&file, &smoothInput, "current", NULL, 0);
						zephir_check_call_status();
							_20$$8 = onlySuccessful == 0;
							if (!(_20$$8)) {
								zephir_array_fetch_string(&_21$$8, &file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 979);
								_20$$8 = ZEPHIR_IS_LONG(&_21$$8, 0);
							}
							if (_20$$8) {
								ZEPHIR_INIT_NVAR(&_22$$9);
								zephir_create_array(&_22$$9, 5, 0);
								ZEPHIR_OBS_NVAR(&_23$$9);
								zephir_array_fetch_string(&_23$$9, &file, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 981);
								zephir_array_update_string(&_22$$9, SL("name"), &_23$$9, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_23$$9);
								zephir_array_fetch_string(&_23$$9, &file, SL("type"), PH_NOISY, "phalcon/Http/Request.zep", 982);
								zephir_array_update_string(&_22$$9, SL("type"), &_23$$9, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_23$$9);
								zephir_array_fetch_string(&_23$$9, &file, SL("tmp_name"), PH_NOISY, "phalcon/Http/Request.zep", 983);
								zephir_array_update_string(&_22$$9, SL("tmp_name"), &_23$$9, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_23$$9);
								zephir_array_fetch_string(&_23$$9, &file, SL("size"), PH_NOISY, "phalcon/Http/Request.zep", 984);
								zephir_array_update_string(&_22$$9, SL("size"), &_23$$9, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_23$$9);
								zephir_array_fetch_string(&_23$$9, &file, SL("error"), PH_NOISY, "phalcon/Http/Request.zep", 986);
								zephir_array_update_string(&_22$$9, SL("error"), &_23$$9, PH_COPY | PH_SEPARATE);
								ZEPHIR_CPY_WRT(&dataFile, &_22$$9);
								zephir_array_fetch_string(&_25$$9, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 993);
								if (namedKeys) {
									ZVAL_BOOL(&_26$$9, 1);
								} else {
									ZVAL_BOOL(&_26$$9, 0);
								}
								ZEPHIR_CALL_METHOD(&_24$$9, this_ptr, "processfiles", &_17, 0, &files, &_26$$9, &dataFile, &_25$$9);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&files, &_24$$9);
							}
					}
				}
				ZEPHIR_INIT_NVAR(&file);
			} else {
				_27$$10 = onlySuccessful == 0;
				if (!(_27$$10)) {
					zephir_array_fetch_string(&_28$$10, &input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 997);
					_27$$10 = ZEPHIR_IS_LONG(&_28$$10, 0);
				}
				if (_27$$10) {
					if (namedKeys) {
						ZVAL_BOOL(&_30$$11, 1);
					} else {
						ZVAL_BOOL(&_30$$11, 0);
					}
					ZEPHIR_CALL_METHOD(&_29$$11, this_ptr, "processfiles", &_17, 0, &files, &_30$$11, &input, &prefix);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&files, &_29$$11);
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&input);
		ZEPHIR_INIT_NVAR(&prefix);
	}
	RETURN_CTOR(&files);
}

/**
 * Gets HTTP URI which request has been made to
 *
 *```php
 * // Returns /some/path?with=queryParams
 * $uri = $request->getURI();
 *
 * // Returns /some/path
 * $uri = $request->getURI(true);
 *```
 *
 * @param bool onlyPath If true, query part will be omitted
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getURI)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *onlyPath_param = NULL, requestURI, _0, _1$$4, _2$$4, _3$$4;
	zend_bool onlyPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requestURI);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(onlyPath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &onlyPath_param);
	if (!onlyPath_param) {
		onlyPath = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "REQUEST_URI");
	ZEPHIR_CALL_METHOD(&requestURI, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&requestURI) == IS_NULL) {
		RETURN_MM_STRING("");
	}
	if (onlyPath) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "?");
		zephir_fast_explode(&_1$$4, &_2$$4, &requestURI, LONG_MAX);
		zephir_array_fetch_long(&_3$$4, &_1$$4, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1036);
		ZEPHIR_CPY_WRT(&requestURI, &_3$$4);
	}
	RETURN_CCTOR(&requestURI);
}

/**
 * Gets HTTP user agent used to made the request
 */
PHP_METHOD(Phalcon_Http_Request, getUserAgent)
{
	zval userAgent, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&userAgent);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_USER_AGENT");
	ZEPHIR_CALL_METHOD(&userAgent, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&userAgent) == IS_NULL) {
		RETURN_MM_STRING("");
	}
	RETURN_CCTOR(&userAgent);
}

/**
 * Checks whether $_REQUEST superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, has)
{
	zval name_zv, _REQUEST;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_REQUEST);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	ZVAL_STR(&name_zv, name);
	RETURN_BOOL(zephir_array_key_exists(&_REQUEST, &name_zv));
}

/**
 * Returns if the request has files or not
 */
PHP_METHOD(Phalcon_Http_Request, hasFiles)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "numfiles", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(&_0, 0));
}

/**
 * Checks whether headers has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasHeader)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval header_zv, name, _0, _1, _2, _3, _5, _6;
	zend_string *header = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header_zv);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(header)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&header_zv);
	ZVAL_STR_COPY(&header_zv, header);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "-");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_");
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 4, &header_zv, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	zephir_fast_strtoupper(&name, &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "hasserver", NULL, 0, &name);
	zephir_check_call_status();
	_4 = zephir_is_true(&_3);
	if (!(_4)) {
		ZEPHIR_INIT_VAR(&_6);
		ZEPHIR_CONCAT_SV(&_6, "HTTP_", &name);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "hasserver", NULL, 0, &_6);
		zephir_check_call_status();
		_4 = zephir_is_true(&_5);
	}
	RETURN_MM_BOOL(_4);
}

/**
 * Checks whether the PATCH data has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPatch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, patch;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&patch);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&patch, this_ptr, "getpatch", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_key_exists(&patch, &name_zv));
}

/**
 * Checks whether $_POST superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPost)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, post;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&post);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&post, this_ptr, "getpost", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_key_exists(&post, &name_zv));
}

/**
 * Checks whether the PUT data has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPut)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, put;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&put);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&put, this_ptr, "getput", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_key_exists(&put, &name_zv));
}

/**
 * Checks whether $_GET superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasQuery)
{
	zval name_zv, _GET;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_GET);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_get_global(&_GET, SL("_GET"));
	ZVAL_STR(&name_zv, name);
	RETURN_BOOL(zephir_array_key_exists(&_GET, &name_zv));
}

/**
 * Checks whether $_SERVER superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasServer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, server;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&server);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&server, this_ptr, "getserverarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_key_exists(&server, &name_zv));
}

/**
 * Checks whether request has been made using ajax
 */
PHP_METHOD(Phalcon_Http_Request, isAjax)
{
	zend_bool _2;
	zval _0, _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HTTP_X_REQUESTED_WITH");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasserver", NULL, 0, &_1);
	zephir_check_call_status();
	_2 = zephir_is_true(&_0);
	if (_2) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "HTTP_X_REQUESTED_WITH");
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "getserver", NULL, 0, &_1);
		zephir_check_call_status();
		_2 = ZEPHIR_IS_STRING_IDENTICAL(&_3, "XMLHttpRequest");
	}
	RETURN_MM_BOOL(_2);
}

/**
 * Checks whether HTTP method is CONNECT.
 * if _SERVER["REQUEST_METHOD"]==="CONNECT"
 */
PHP_METHOD(Phalcon_Http_Request, isConnect)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "CONNECT"));
}

/**
 * Checks whether HTTP method is DELETE.
 * if _SERVER["REQUEST_METHOD"]==="DELETE"
 */
PHP_METHOD(Phalcon_Http_Request, isDelete)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "DELETE"));
}

/**
 * Checks whether HTTP method is GET.
 * if _SERVER["REQUEST_METHOD"]==="GET"
 */
PHP_METHOD(Phalcon_Http_Request, isGet)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "GET"));
}

/**
 * Checks whether HTTP method is HEAD.
 * if _SERVER["REQUEST_METHOD"]==="HEAD"
 */
PHP_METHOD(Phalcon_Http_Request, isHead)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "HEAD"));
}

/**
 * Checks whether request content type contains json data
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Http_Request, isJson)
{
	zend_bool _2;
	zval _0, _1, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "CONTENT_TYPE");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasserver", NULL, 0, &_1);
	zephir_check_call_status();
	_2 = zephir_is_true(&_0);
	if (_2) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "CONTENT_TYPE");
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "getserver", NULL, 0, &_1);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "json");
		ZEPHIR_CALL_FUNCTION(&_4, "stripos", NULL, 0, &_3, &_1);
		zephir_check_call_status();
		_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_4);
	}
	RETURN_MM_BOOL(_2);
}

/**
 * Check if HTTP method match any of the passed methods
 * When strict is true it checks if validated methods are real HTTP methods
 */
PHP_METHOD(Phalcon_Http_Request, isMethod)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool strict, _0$$3, _8$$5;
	zval *methods, methods_sub, *strict_param = NULL, httpMethod, method, _1$$3, _2$$4, *_3$$5, _7$$5, _4$$6, _5$$6, _9$$8, _10$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&methods_sub);
	ZVAL_UNDEF(&httpMethod);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(methods)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(strict)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &methods, &strict_param);
	if (!strict_param) {
		strict = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&httpMethod, this_ptr, "getmethod", NULL, 0);
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
			object_init_ex(&_2$$4, phalcon_http_request_exceptions_invalidhttpmethod_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0, methods);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "phalcon/Http/Request.zep", 1209);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(methods, &httpMethod));
	}
	if (Z_TYPE_P(methods) == IS_ARRAY) {
		zephir_is_iterable(methods, 0, "phalcon/Http/Request.zep", 1222);
		if (Z_TYPE_P(methods) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(methods), _3$$5)
			{
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _3$$5);
				if (strict) {
					ZVAL_BOOL(&_5$$6, 1);
				} else {
					ZVAL_BOOL(&_5$$6, 0);
				}
				ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "ismethod", &_6, 0, &method, &_5$$6);
				zephir_check_call_status();
				if (zephir_is_true(&_4$$6)) {
					RETURN_MM_BOOL(1);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, methods, "rewind", NULL, 0);
			zephir_check_call_status();
			_8$$5 = 1;
			while (1) {
				if (_8$$5) {
					_8$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, methods, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_7$$5, methods, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&method, methods, "current", NULL, 0);
				zephir_check_call_status();
					if (strict) {
						ZVAL_BOOL(&_10$$8, 1);
					} else {
						ZVAL_BOOL(&_10$$8, 0);
					}
					ZEPHIR_CALL_METHOD(&_9$$8, this_ptr, "ismethod", &_6, 0, &method, &_10$$8);
					zephir_check_call_status();
					if (zephir_is_true(&_9$$8)) {
						RETURN_MM_BOOL(1);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&method);
		RETURN_MM_BOOL(0);
	}
	if (UNEXPECTED(strict)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exceptions_invalidhttpmethod_ce, "non-string", "phalcon/Http/Request.zep", 1226);
		return;
	}
	RETURN_MM_BOOL(0);
}

/**
 * Checks whether HTTP method is OPTIONS.
 * if _SERVER["REQUEST_METHOD"]==="OPTIONS"
 */
PHP_METHOD(Phalcon_Http_Request, isOptions)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "OPTIONS"));
}

/**
 * Checks whether HTTP method is PATCH.
 * if _SERVER["REQUEST_METHOD"]==="PATCH"
 */
PHP_METHOD(Phalcon_Http_Request, isPatch)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "PATCH"));
}

/**
 * Checks whether HTTP method is POST.
 * if _SERVER["REQUEST_METHOD"]==="POST"
 */
PHP_METHOD(Phalcon_Http_Request, isPost)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "POST"));
}

/**
 * Checks whether HTTP method is PURGE (Squid and Varnish support).
 * if _SERVER["REQUEST_METHOD"]==="PURGE"
 */
PHP_METHOD(Phalcon_Http_Request, isPurge)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "PURGE"));
}

/**
 * Checks whether HTTP method is PUT.
 * if _SERVER["REQUEST_METHOD"]==="PUT"
 */
PHP_METHOD(Phalcon_Http_Request, isPut)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "PUT"));
}

/**
 * Checks whether request has been made using any secure layer
 */
PHP_METHOD(Phalcon_Http_Request, isSecure)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getscheme", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "https"));
}

/**
 * Checks whether request has been made using SOAP
 */
PHP_METHOD(Phalcon_Http_Request, isSoap)
{
	zval contentType, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contentType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HTTP_SOAPACTION");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasserver", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&contentType)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(zephir_memnstr_str(&contentType, SL("application/soap+xml"), "phalcon/Http/Request.zep", 1302));
}

/**
 * Checks if the `Request::getHttpHost` method will be use strict validation
 * of host name or not
 */
PHP_METHOD(Phalcon_Http_Request, isStrictHostCheck)
{

	RETURN_MEMBER(getThis(), "strictHostCheck");
}

/**
 * Checks whether HTTP method is TRACE.
 * if _SERVER["REQUEST_METHOD"]==="TRACE"
 */
PHP_METHOD(Phalcon_Http_Request, isTrace)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "TRACE"));
}

/**
 * Checks if a method is a valid HTTP method
 */
PHP_METHOD(Phalcon_Http_Request, isValidHttpMethod)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval method_zv, _0;
	zend_string *method = NULL;

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(method)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtoupper(&_0, &method_zv);
	do {
		if (ZEPHIR_IS_STRING(&_0, "CONNECT") || ZEPHIR_IS_STRING(&_0, "DELETE") || ZEPHIR_IS_STRING(&_0, "GET") || ZEPHIR_IS_STRING(&_0, "HEAD") || ZEPHIR_IS_STRING(&_0, "OPTIONS") || ZEPHIR_IS_STRING(&_0, "PATCH") || ZEPHIR_IS_STRING(&_0, "POST") || ZEPHIR_IS_STRING(&_0, "PURGE") || ZEPHIR_IS_STRING(&_0, "PUT") || ZEPHIR_IS_STRING(&_0, "TRACE")) {
			RETURN_MM_BOOL(1);
		}
	} while(0);

	RETURN_MM_BOOL(0);
}

/**
 * Returns the number of files available
 */
PHP_METHOD(Phalcon_Http_Request, numFiles)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zval *onlySuccessful_param = NULL, _FILES, files, file, error, *_0, _2$$8, _3$$8;
	zend_bool onlySuccessful, _1$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_3$$8);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(onlySuccessful)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_fetch_params(1, 0, 1, &onlySuccessful_param);
	if (!onlySuccessful_param) {
		onlySuccessful = 0;
	} else {
		}
	numberFiles = 0;
	ZEPHIR_CPY_WRT(&files, &_FILES);
	if (Z_TYPE_P(&files) != IS_ARRAY) {
		RETURN_MM_LONG(0);
	}
	zephir_is_iterable(&files, 0, "phalcon/Http/Request.zep", 1376);
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
				ZEPHIR_CALL_METHOD(&_2$$8, this_ptr, "hasfilehelper", &_4, 0, &error, &_3$$8);
				zephir_check_call_status();
				numberFiles += zephir_get_numberval(&_2$$8);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&file);
	RETURN_MM_LONG(numberFiles);
}

/**
 * Set the HTTP method parameter override flag
 *
 * @param bool $override
 *
 * @return static
 */
PHP_METHOD(Phalcon_Http_Request, setHttpMethodParameterOverride)
{
	zval *override_param = NULL, __$true, __$false;
	zend_bool override;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(override)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &override_param);
	if (override) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("methodOverride"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("methodOverride"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets automatic sanitizers/filters for a particular field and for
 * particular methods
 */
PHP_METHOD(Phalcon_Http_Request, setParameterFilters)
{
	zend_bool _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filters, scope;
	zval name_zv, *filters_param = NULL, *scope_param = NULL, filterService, sanitizer, localScope, scopeMethod, *_1, _6, *_12, _0$$3, _2$$4, _4$$5, _8$$6, _10$$7, _11$$8, _13$$10;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&sanitizer);
	ZVAL_UNDEF(&localScope);
	ZVAL_UNDEF(&scopeMethod);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&scope);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(filters, filters_param)
		ZEPHIR_Z_PARAM_ARRAY(scope, scope_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filters_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		scope_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
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
	if (UNEXPECTED(zephir_fast_count_int(&filters) < 1)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_http_request_exceptions_missingfilters_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Http/Request.zep", 1405);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&filterService, this_ptr, "getfilterservice", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&filters, 0, "phalcon/Http/Request.zep", 1416);
	if (Z_TYPE_P(&filters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&filters), _1)
		{
			ZEPHIR_INIT_NVAR(&sanitizer);
			ZVAL_COPY(&sanitizer, _1);
			ZEPHIR_CALL_METHOD(&_2$$4, &filterService, "has", &_3, 0, &sanitizer);
			zephir_check_call_status();
			if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_2$$4))) {
				ZEPHIR_INIT_NVAR(&_4$$5);
				object_init_ex(&_4$$5, phalcon_http_request_exceptions_sanitizernotfound_ce);
				ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", &_5, 0, &sanitizer);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$5, "phalcon/Http/Request.zep", 1412);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &filters, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &filters, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &filters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&sanitizer, &filters, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$6, &filterService, "has", &_9, 0, &sanitizer);
				zephir_check_call_status();
				if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_8$$6))) {
					ZEPHIR_INIT_NVAR(&_10$$7);
					object_init_ex(&_10$$7, phalcon_http_request_exceptions_sanitizernotfound_ce);
					ZEPHIR_CALL_METHOD(NULL, &_10$$7, "__construct", &_5, 0, &sanitizer);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$7, "phalcon/Http/Request.zep", 1412);
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&sanitizer);
	if (zephir_fast_count_int(&scope) < 1) {
		ZEPHIR_INIT_VAR(&localScope);
		zephir_create_array(&localScope, 4, 0);
		ZEPHIR_INIT_VAR(&_11$$8);
		ZVAL_STRING(&_11$$8, "GET");
		zephir_array_fast_append(&localScope, &_11$$8);
		ZEPHIR_INIT_NVAR(&_11$$8);
		ZVAL_STRING(&_11$$8, "PATCH");
		zephir_array_fast_append(&localScope, &_11$$8);
		ZEPHIR_INIT_NVAR(&_11$$8);
		ZVAL_STRING(&_11$$8, "POST");
		zephir_array_fast_append(&localScope, &_11$$8);
		ZEPHIR_INIT_NVAR(&_11$$8);
		ZVAL_STRING(&_11$$8, "PUT");
		zephir_array_fast_append(&localScope, &_11$$8);
	} else {
		ZEPHIR_CPY_WRT(&localScope, &scope);
	}
	zephir_is_iterable(&localScope, 0, "phalcon/Http/Request.zep", 1431);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&localScope), _12)
	{
		ZEPHIR_INIT_NVAR(&scopeMethod);
		ZVAL_COPY(&scopeMethod, _12);
		ZEPHIR_INIT_NVAR(&_13$$10);
		zephir_fast_strtoupper(&_13$$10, &scopeMethod);
		zephir_update_property_array_multi(this_ptr, SL("queryFilters"), &filters, SL("zz"), 2, &_13$$10, &name_zv);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&scopeMethod);
	RETURN_THIS();
}

/**
 * Sets if the `Request::getHttpHost` method must be use strict validation
 * of host name or not
 */
PHP_METHOD(Phalcon_Http_Request, setStrictHostCheck)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(0, 1, &flag_param);
	if (!flag_param) {
		flag = 1;
	} else {
		}
	if (flag) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("strictHostCheck"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("strictHostCheck"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Set a trusted proxy list for X-Forwarded-For header
 *
 * @param array $trustedProxies
 * @return static
 * @throws Exception
 */
PHP_METHOD(Phalcon_Http_Request, setTrustedProxies)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *trustedProxies_param = NULL, filterService, trustedProxy, filtered, *_0, _3, _1$$3, _5$$5;
	zval trustedProxies;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&trustedProxies);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&trustedProxy);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(trustedProxies, trustedProxies_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &trustedProxies_param);
	zephir_get_arrval(&trustedProxies, trustedProxies_param);
	ZEPHIR_CALL_METHOD(&filterService, this_ptr, "getfilterservice", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&trustedProxies, 0, "phalcon/Http/Request.zep", 1466);
	if (Z_TYPE_P(&trustedProxies) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&trustedProxies), _0)
		{
			ZEPHIR_INIT_NVAR(&trustedProxy);
			ZVAL_COPY(&trustedProxy, _0);
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "ip");
			ZEPHIR_CALL_METHOD(&filtered, &filterService, "sanitize", &_2, 0, &trustedProxy, &_1$$3);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&filtered)) {
				zephir_update_property_array_append(this_ptr, SL("trustedProxies"), &filtered);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &trustedProxies, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &trustedProxies, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &trustedProxies, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&trustedProxy, &trustedProxies, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_STRING(&_5$$5, "ip");
				ZEPHIR_CALL_METHOD(&filtered, &filterService, "sanitize", &_6, 0, &trustedProxy, &_5$$5);
				zephir_check_call_status();
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&filtered)) {
					zephir_update_property_array_append(this_ptr, SL("trustedProxies"), &filtered);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&trustedProxy);
	RETURN_THIS();
}

/**
 * This header takes priority when parsing HTTP headers
 * The header return only 1 single IP address, prefixed with HTTP_ eg. HTTP_CLIENT_IP.
 *
 * @param  string $trustedProxyHeader
 * @return static
 */
PHP_METHOD(Phalcon_Http_Request, setTrustedProxyHeader)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval trustedProxyHeader_zv, trustedHeader, _0, _1, _2, _3, _4, _5$$3;
	zend_string *trustedProxyHeader = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&trustedProxyHeader_zv);
	ZVAL_UNDEF(&trustedHeader);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(trustedProxyHeader)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&trustedProxyHeader_zv);
	ZVAL_STR_COPY(&trustedProxyHeader_zv, trustedProxyHeader);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "-");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "_");
	zephir_fast_str_replace(&_0, &_1, &_2, &trustedProxyHeader_zv);
	ZEPHIR_INIT_VAR(&trustedHeader);
	zephir_fast_strtoupper(&trustedHeader, &_0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "HTTP_");
	ZEPHIR_CALL_FUNCTION(&_4, "str_starts_with", NULL, 0, &trustedHeader, &_3);
	zephir_check_call_status();
	if (!zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_SV(&_5$$3, "HTTP_", &trustedHeader);
		ZEPHIR_CPY_WRT(&trustedHeader, &_5$$3);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("trustedProxyHeader"), &trustedHeader);
	RETURN_THIS();
}

/**
 * Process a request header and return the one with best quality
 */
PHP_METHOD(Phalcon_Http_Request, getBestQuality)
{
	zend_bool _4;
	double quality = 0, acceptQuality = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0;
	zend_string *name = NULL;
	zval *qualityParts_param = NULL, name_zv, selectedName, accept, *_0, _3, _1$$4, _2$$5, _5$$8, _6$$9;
	zval qualityParts;

	ZVAL_UNDEF(&qualityParts);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&selectedName);
	ZVAL_UNDEF(&accept);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(qualityParts, qualityParts_param)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	qualityParts_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&qualityParts, qualityParts_param);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	i = 0;
	quality =  (0.0);
	ZEPHIR_INIT_VAR(&selectedName);
	ZVAL_STRING(&selectedName, "");
	zephir_is_iterable(&qualityParts, 0, "phalcon/Http/Request.zep", 1519);
	if (Z_TYPE_P(&qualityParts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&qualityParts), _0)
		{
			ZEPHIR_INIT_NVAR(&accept);
			ZVAL_COPY(&accept, _0);
			if (i == 0) {
				ZEPHIR_OBS_NVAR(&_1$$4);
				zephir_array_fetch_string(&_1$$4, &accept, SL("quality"), PH_NOISY, "phalcon/Http/Request.zep", 1505);
				quality =  (zephir_get_doubleval(&_1$$4));
				ZEPHIR_OBS_NVAR(&selectedName);
				zephir_array_fetch(&selectedName, &accept, &name_zv, PH_NOISY, "phalcon/Http/Request.zep", 1506);
			} else {
				ZEPHIR_OBS_NVAR(&_2$$5);
				zephir_array_fetch_string(&_2$$5, &accept, SL("quality"), PH_NOISY, "phalcon/Http/Request.zep", 1508);
				acceptQuality =  (zephir_get_doubleval(&_2$$5));
				if (acceptQuality > quality) {
					quality =  acceptQuality;
					ZEPHIR_OBS_NVAR(&selectedName);
					zephir_array_fetch(&selectedName, &accept, &name_zv, PH_NOISY, "phalcon/Http/Request.zep", 1512);
				}
			}
			i++;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &qualityParts, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &qualityParts, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &qualityParts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&accept, &qualityParts, "current", NULL, 0);
			zephir_check_call_status();
				if (i == 0) {
					ZEPHIR_OBS_NVAR(&_5$$8);
					zephir_array_fetch_string(&_5$$8, &accept, SL("quality"), PH_NOISY, "phalcon/Http/Request.zep", 1505);
					quality =  (zephir_get_doubleval(&_5$$8));
					ZEPHIR_OBS_NVAR(&selectedName);
					zephir_array_fetch(&selectedName, &accept, &name_zv, PH_NOISY, "phalcon/Http/Request.zep", 1506);
				} else {
					ZEPHIR_OBS_NVAR(&_6$$9);
					zephir_array_fetch_string(&_6$$9, &accept, SL("quality"), PH_NOISY, "phalcon/Http/Request.zep", 1508);
					acceptQuality =  (zephir_get_doubleval(&_6$$9));
					if (acceptQuality > quality) {
						quality =  acceptQuality;
						ZEPHIR_OBS_NVAR(&selectedName);
						zephir_array_fetch(&selectedName, &accept, &name_zv, PH_NOISY, "phalcon/Http/Request.zep", 1512);
					}
				}
				i++;
		}
	}
	ZEPHIR_INIT_NVAR(&accept);
	RETURN_CCTOR(&selectedName);
}

/**
 * Helper to get data from superglobals, applying filters if needed.
 * If no parameters are given the superglobal is returned.
 */
PHP_METHOD(Phalcon_Http_Request, getHelper)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive, _0, _1;
	zend_string *name = NULL;
	zval *source_param = NULL, name_zv, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, value, filterService, _2$$6, _3$$6;
	zval source;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 6)
		ZEPHIR_Z_PARAM_ARRAY(source, source_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(filters)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_BOOL(notAllowEmpty)
		Z_PARAM_BOOL(noRecursive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	source_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		filters = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		defaultValue = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		notAllowEmpty_param = ZEND_CALL_ARG(execute_data, 5);
	}
	if (ZEND_NUM_ARGS() > 5) {
		noRecursive_param = ZEND_CALL_ARG(execute_data, 6);
	}
	zephir_get_arrval(&source, source_param);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
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
		}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		}
	if (ZEPHIR_IS_NULL(&name_zv)) {
		RETURN_CTOR(&source);
	}
	zephir_memory_observe(&value);
	if (!(zephir_array_isset_fetch(&value, &source, &name_zv, 0))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	_0 = !(zephir_is_numeric(&value));
	if (_0) {
		_0 = ZEPHIR_IS_EMPTY(&value);
	}
	_1 = _0;
	if (_1) {
		_1 = notAllowEmpty;
	}
	if (_1) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(filters) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&filterService, this_ptr, "getfilterservice", NULL, 0);
		zephir_check_call_status();
		if (noRecursive) {
			ZVAL_BOOL(&_3$$6, 1);
		} else {
			ZVAL_BOOL(&_3$$6, 0);
		}
		ZEPHIR_CALL_METHOD(&_2$$6, &filterService, "sanitize", NULL, 0, &value, filters, &_3$$6);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&value, &_2$$6);
		if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
	}
	RETURN_CCTOR(&value);
}

/**
 * Process a request header and return an array of values with their qualities
 */
PHP_METHOD(Phalcon_Http_Request, getQualityHeader)
{
	zend_bool _29, _19$$3, _44$$14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval serverIndex_zv, name_zv, headerPart, headerParts, headerSplit, part, parts, returnedParts, serverValue, split, _0, _1, _2, _3, *_4, _28, _5$$3, _6$$3, _7$$3, _8$$3, *_9$$3, _18$$3, _10$$4, _11$$4, _12$$5, _13$$6, _14$$6, _15$$7, _16$$7, _17$$8, _20$$9, _21$$9, _22$$10, _23$$11, _24$$11, _25$$12, _26$$12, _27$$13, _30$$14, _31$$14, _32$$14, _33$$14, *_34$$14, _43$$14, _35$$15, _36$$15, _37$$16, _38$$17, _39$$17, _40$$18, _41$$18, _42$$19, _45$$20, _46$$20, _47$$21, _48$$22, _49$$22, _50$$23, _51$$23, _52$$24;
	zend_string *serverIndex = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serverIndex_zv);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&headerPart);
	ZVAL_UNDEF(&headerParts);
	ZVAL_UNDEF(&headerSplit);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&returnedParts);
	ZVAL_UNDEF(&serverValue);
	ZVAL_UNDEF(&split);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_33$$14);
	ZVAL_UNDEF(&_43$$14);
	ZVAL_UNDEF(&_35$$15);
	ZVAL_UNDEF(&_36$$15);
	ZVAL_UNDEF(&_37$$16);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_40$$18);
	ZVAL_UNDEF(&_41$$18);
	ZVAL_UNDEF(&_42$$19);
	ZVAL_UNDEF(&_45$$20);
	ZVAL_UNDEF(&_46$$20);
	ZVAL_UNDEF(&_47$$21);
	ZVAL_UNDEF(&_48$$22);
	ZVAL_UNDEF(&_49$$22);
	ZVAL_UNDEF(&_50$$23);
	ZVAL_UNDEF(&_51$$23);
	ZVAL_UNDEF(&_52$$24);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(serverIndex)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&serverIndex_zv);
	ZVAL_STR_COPY(&serverIndex_zv, serverIndex);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_INIT_VAR(&returnedParts);
	array_init(&returnedParts);
	ZEPHIR_CALL_METHOD(&serverValue, this_ptr, "getserver", NULL, 0, &serverIndex_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(&serverValue) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "");
	} else {
		ZEPHIR_CPY_WRT(&_0, &serverValue);
	}
	ZEPHIR_CPY_WRT(&serverValue, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/,\\s*/");
	ZVAL_LONG(&_2, -1);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&parts, "preg_split", NULL, 135, &_1, &serverValue, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&parts, 0, "phalcon/Http/Request.zep", 1605);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parts), _4)
		{
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _4);
			ZEPHIR_INIT_NVAR(&headerParts);
			array_init(&headerParts);
			ZEPHIR_INIT_NVAR(&_5$$3);
			zephir_fast_trim(&_5$$3, &part, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZVAL_STRING(&_6$$3, "/\\s*;\\s*/");
			ZVAL_LONG(&_7$$3, -1);
			ZVAL_LONG(&_8$$3, 1);
			ZEPHIR_CALL_FUNCTION(&headerSplit, "preg_split", NULL, 135, &_6$$3, &_5$$3, &_7$$3, &_8$$3);
			zephir_check_call_status();
			zephir_is_iterable(&headerSplit, 0, "phalcon/Http/Request.zep", 1602);
			if (Z_TYPE_P(&headerSplit) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&headerSplit), _9$$3)
				{
					ZEPHIR_INIT_NVAR(&headerPart);
					ZVAL_COPY(&headerPart, _9$$3);
					ZEPHIR_INIT_NVAR(&_10$$4);
					ZVAL_STRING(&_10$$4, "=");
					ZEPHIR_INIT_NVAR(&_11$$4);
					zephir_fast_strpos(&_11$$4, &headerPart, &_10$$4, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_11$$4)) {
						ZEPHIR_INIT_NVAR(&split);
						zephir_fast_explode_str(&split, SL("="), &headerPart, 2 );
						zephir_array_fetch_long(&_12$$5, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1591);
						if (ZEPHIR_IS_STRING_IDENTICAL(&_12$$5, "q")) {
							ZEPHIR_OBS_NVAR(&_13$$6);
							zephir_array_fetch_long(&_13$$6, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1592);
							ZEPHIR_INIT_NVAR(&_14$$6);
							ZVAL_DOUBLE(&_14$$6, zephir_get_doubleval(&_13$$6));
							zephir_array_update_string(&headerParts, SL("quality"), &_14$$6, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_fetch_long(&_15$$7, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1594);
							ZEPHIR_OBS_NVAR(&_16$$7);
							zephir_array_fetch_long(&_16$$7, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1594);
							zephir_array_update_zval(&headerParts, &_16$$7, &_15$$7, PH_COPY | PH_SEPARATE);
						}
					} else {
						zephir_array_update_zval(&headerParts, &name_zv, &headerPart, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_17$$8);
						ZVAL_DOUBLE(&_17$$8, 1.0);
						zephir_array_update_string(&headerParts, SL("quality"), &_17$$8, PH_COPY | PH_SEPARATE);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &headerSplit, "rewind", NULL, 0);
				zephir_check_call_status();
				_19$$3 = 1;
				while (1) {
					if (_19$$3) {
						_19$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &headerSplit, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_18$$3, &headerSplit, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_18$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&headerPart, &headerSplit, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_20$$9);
						ZVAL_STRING(&_20$$9, "=");
						ZEPHIR_INIT_NVAR(&_21$$9);
						zephir_fast_strpos(&_21$$9, &headerPart, &_20$$9, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_21$$9)) {
							ZEPHIR_INIT_NVAR(&split);
							zephir_fast_explode_str(&split, SL("="), &headerPart, 2 );
							zephir_array_fetch_long(&_22$$10, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1591);
							if (ZEPHIR_IS_STRING_IDENTICAL(&_22$$10, "q")) {
								ZEPHIR_OBS_NVAR(&_23$$11);
								zephir_array_fetch_long(&_23$$11, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1592);
								ZEPHIR_INIT_NVAR(&_24$$11);
								ZVAL_DOUBLE(&_24$$11, zephir_get_doubleval(&_23$$11));
								zephir_array_update_string(&headerParts, SL("quality"), &_24$$11, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_fetch_long(&_25$$12, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1594);
								ZEPHIR_OBS_NVAR(&_26$$12);
								zephir_array_fetch_long(&_26$$12, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1594);
								zephir_array_update_zval(&headerParts, &_26$$12, &_25$$12, PH_COPY | PH_SEPARATE);
							}
						} else {
							zephir_array_update_zval(&headerParts, &name_zv, &headerPart, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_27$$13);
							ZVAL_DOUBLE(&_27$$13, 1.0);
							zephir_array_update_string(&headerParts, SL("quality"), &_27$$13, PH_COPY | PH_SEPARATE);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&headerPart);
			zephir_array_append(&returnedParts, &headerParts, PH_SEPARATE, "phalcon/Http/Request.zep", 1602);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parts, "rewind", NULL, 0);
		zephir_check_call_status();
		_29 = 1;
		while (1) {
			if (_29) {
				_29 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_28, &parts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_28)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&part, &parts, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&headerParts);
				array_init(&headerParts);
				ZEPHIR_INIT_NVAR(&_30$$14);
				zephir_fast_trim(&_30$$14, &part, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_INIT_NVAR(&_31$$14);
				ZVAL_STRING(&_31$$14, "/\\s*;\\s*/");
				ZVAL_LONG(&_32$$14, -1);
				ZVAL_LONG(&_33$$14, 1);
				ZEPHIR_CALL_FUNCTION(&headerSplit, "preg_split", NULL, 135, &_31$$14, &_30$$14, &_32$$14, &_33$$14);
				zephir_check_call_status();
				zephir_is_iterable(&headerSplit, 0, "phalcon/Http/Request.zep", 1602);
				if (Z_TYPE_P(&headerSplit) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&headerSplit), _34$$14)
					{
						ZEPHIR_INIT_NVAR(&headerPart);
						ZVAL_COPY(&headerPart, _34$$14);
						ZEPHIR_INIT_NVAR(&_35$$15);
						ZVAL_STRING(&_35$$15, "=");
						ZEPHIR_INIT_NVAR(&_36$$15);
						zephir_fast_strpos(&_36$$15, &headerPart, &_35$$15, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_36$$15)) {
							ZEPHIR_INIT_NVAR(&split);
							zephir_fast_explode_str(&split, SL("="), &headerPart, 2 );
							zephir_array_fetch_long(&_37$$16, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1591);
							if (ZEPHIR_IS_STRING_IDENTICAL(&_37$$16, "q")) {
								ZEPHIR_OBS_NVAR(&_38$$17);
								zephir_array_fetch_long(&_38$$17, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1592);
								ZEPHIR_INIT_NVAR(&_39$$17);
								ZVAL_DOUBLE(&_39$$17, zephir_get_doubleval(&_38$$17));
								zephir_array_update_string(&headerParts, SL("quality"), &_39$$17, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_fetch_long(&_40$$18, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1594);
								ZEPHIR_OBS_NVAR(&_41$$18);
								zephir_array_fetch_long(&_41$$18, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1594);
								zephir_array_update_zval(&headerParts, &_41$$18, &_40$$18, PH_COPY | PH_SEPARATE);
							}
						} else {
							zephir_array_update_zval(&headerParts, &name_zv, &headerPart, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_42$$19);
							ZVAL_DOUBLE(&_42$$19, 1.0);
							zephir_array_update_string(&headerParts, SL("quality"), &_42$$19, PH_COPY | PH_SEPARATE);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &headerSplit, "rewind", NULL, 0);
					zephir_check_call_status();
					_44$$14 = 1;
					while (1) {
						if (_44$$14) {
							_44$$14 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &headerSplit, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_43$$14, &headerSplit, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_43$$14)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&headerPart, &headerSplit, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_45$$20);
							ZVAL_STRING(&_45$$20, "=");
							ZEPHIR_INIT_NVAR(&_46$$20);
							zephir_fast_strpos(&_46$$20, &headerPart, &_45$$20, 0 );
							if (!ZEPHIR_IS_FALSE_IDENTICAL(&_46$$20)) {
								ZEPHIR_INIT_NVAR(&split);
								zephir_fast_explode_str(&split, SL("="), &headerPart, 2 );
								zephir_array_fetch_long(&_47$$21, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1591);
								if (ZEPHIR_IS_STRING_IDENTICAL(&_47$$21, "q")) {
									ZEPHIR_OBS_NVAR(&_48$$22);
									zephir_array_fetch_long(&_48$$22, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1592);
									ZEPHIR_INIT_NVAR(&_49$$22);
									ZVAL_DOUBLE(&_49$$22, zephir_get_doubleval(&_48$$22));
									zephir_array_update_string(&headerParts, SL("quality"), &_49$$22, PH_COPY | PH_SEPARATE);
								} else {
									zephir_array_fetch_long(&_50$$23, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1594);
									ZEPHIR_OBS_NVAR(&_51$$23);
									zephir_array_fetch_long(&_51$$23, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1594);
									zephir_array_update_zval(&headerParts, &_51$$23, &_50$$23, PH_COPY | PH_SEPARATE);
								}
							} else {
								zephir_array_update_zval(&headerParts, &name_zv, &headerPart, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_52$$24);
								ZVAL_DOUBLE(&_52$$24, 1.0);
								zephir_array_update_string(&headerParts, SL("quality"), &_52$$24, PH_COPY | PH_SEPARATE);
							}
					}
				}
				ZEPHIR_INIT_NVAR(&headerPart);
				zephir_array_append(&returnedParts, &headerParts, PH_SEPARATE, "phalcon/Http/Request.zep", 1602);
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	RETURN_CCTOR(&returnedParts);
}

/**
 * Recursively counts file in an array of files
 */
PHP_METHOD(Phalcon_Http_Request, hasFileHelper)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zend_bool onlySuccessful, _6, _1$$5, _7$$9;
	zval *data, data_sub, *onlySuccessful_param = NULL, value, *_0, _5, _2$$7, _3$$7, _8$$11, _9$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(data)
		Z_PARAM_BOOL(onlySuccessful)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &data, &onlySuccessful_param);
	numberFiles = 0;
	if (Z_TYPE_P(data) != IS_ARRAY) {
		RETURN_MM_LONG(1);
	}
	zephir_is_iterable(data, 0, "phalcon/Http/Request.zep", 1632);
	if (Z_TYPE_P(data) == IS_ARRAY) {
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
				ZEPHIR_CALL_METHOD(&_2$$7, this_ptr, "hasfilehelper", &_4, 0, &value, &_3$$7);
				zephir_check_call_status();
				numberFiles += zephir_get_numberval(&_2$$7);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, data, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, data, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, data, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&value) != IS_ARRAY) {
					_7$$9 = !zephir_is_true(&value);
					if (!(_7$$9)) {
						_7$$9 = !onlySuccessful;
					}
					if (_7$$9) {
						numberFiles++;
					}
				}
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					if (onlySuccessful) {
						ZVAL_BOOL(&_9$$11, 1);
					} else {
						ZVAL_BOOL(&_9$$11, 0);
					}
					ZEPHIR_CALL_METHOD(&_8$$11, this_ptr, "hasfilehelper", &_4, 0, &value, &_9$$11);
					zephir_check_call_status();
					numberFiles += zephir_get_numberval(&_8$$11);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	RETURN_MM_LONG(numberFiles);
}

/**
 * Check if an IP address exists in CIDR range
 *
 * @param string $ip The IP address to check.
 * @param string $cidr The CIDR range to compare against.
 * @return bool True if the IP is in range, false otherwise.
 */
PHP_METHOD(Phalcon_Http_Request, isIpAddressInCIDR)
{
	zend_bool _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, maskBytes = 0, tempMask = 0, remainingBits = 0;
	zval ip_zv, cidr_zv, parts, mask, subnet, maskLength, ipBin, subnetBin, ipBits, subnetBits, ipByte, subnetByte, _0, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12;
	zend_string *ip = NULL, *cidr = NULL;

	ZVAL_UNDEF(&ip_zv);
	ZVAL_UNDEF(&cidr_zv);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&mask);
	ZVAL_UNDEF(&subnet);
	ZVAL_UNDEF(&maskLength);
	ZVAL_UNDEF(&ipBin);
	ZVAL_UNDEF(&subnetBin);
	ZVAL_UNDEF(&ipBits);
	ZVAL_UNDEF(&subnetBits);
	ZVAL_UNDEF(&ipByte);
	ZVAL_UNDEF(&subnetByte);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(ip)
		Z_PARAM_STR(cidr)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&ip_zv);
	ZVAL_STR_COPY(&ip_zv, ip);
	zephir_memory_observe(&cidr_zv);
	ZVAL_STR_COPY(&cidr_zv, cidr);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/");
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode(&parts, &_0, &cidr_zv, LONG_MAX);
	zephir_memory_observe(&subnet);
	zephir_array_fetch_long(&subnet, &parts, 0, PH_NOISY, "phalcon/Http/Request.zep", 1648);
	zephir_memory_observe(&maskLength);
	zephir_array_fetch_long(&maskLength, &parts, 1, PH_NOISY, "phalcon/Http/Request.zep", 1649);
	ZEPHIR_CALL_FUNCTION(&ipBin, "inet_pton", NULL, 0, &ip_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&subnetBin, "inet_pton", NULL, 0, &subnet);
	zephir_check_call_status();
	_1 = ZEPHIR_IS_FALSE_IDENTICAL(&ipBin);
	if (!(_1)) {
		_1 = ZEPHIR_IS_FALSE_IDENTICAL(&subnetBin);
	}
	_2 = _1;
	if (!(_2)) {
		_2 = zephir_fast_strlen_ev(&ipBin) != zephir_fast_strlen_ev(&subnetBin);
	}
	if (_2) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "H*");
	ZEPHIR_CALL_FUNCTION(&ipBits, "unpack", NULL, 446, &_3, &ipBin);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "H*");
	ZEPHIR_CALL_FUNCTION(&subnetBits, "unpack", NULL, 446, &_3, &subnetBin);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &ipBits, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1661);
	ZEPHIR_CPY_WRT(&ipBits, &_4);
	zephir_array_fetch_long(&_4, &subnetBits, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1662);
	ZEPHIR_CPY_WRT(&subnetBits, &_4);
	ZVAL_LONG(&_5, zephir_fast_strlen_ev(&ipBits));
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "0");
	ZEPHIR_CALL_FUNCTION(&_6, "str_pad", NULL, 37, &ipBits, &_5, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&ipBits, "hex2bin", NULL, 38, &_6);
	zephir_check_call_status();
	ZVAL_LONG(&_5, zephir_fast_strlen_ev(&subnetBits));
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "0");
	ZEPHIR_CALL_FUNCTION(&_7, "str_pad", NULL, 37, &subnetBits, &_5, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&subnetBits, "hex2bin", NULL, 38, &_7);
	zephir_check_call_status();
	ZVAL_DOUBLE(&_5, zephir_safe_div_zval_long(&maskLength, 8));
	maskBytes = (int) zephir_floor(&_5);
	remainingBits = (long) (zephir_safe_mod_zval_long(&maskLength, 8));
	ZVAL_LONG(&_8, maskBytes);
	ZEPHIR_CALL_FUNCTION(&_9, "strncmp", NULL, 348, &ipBits, &subnetBits, &_8);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_9, 0)) {
		RETURN_MM_BOOL(0);
	}
	if (remainingBits == 0) {
		RETURN_MM_BOOL(1);
	}
	zephir_array_fetch_long(&_4, &ipBits, maskBytes, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1680);
	ZEPHIR_CALL_FUNCTION(&ipByte, "ord", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_array_fetch_long(&_10, &subnetBits, maskBytes, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1681);
	ZEPHIR_CALL_FUNCTION(&subnetByte, "ord", NULL, 0, &_10);
	zephir_check_call_status();
	tempMask = (((1 << ((8 - remainingBits)))) - 1);
	ZEPHIR_INIT_VAR(&mask);
	ZVAL_LONG(&mask, (0xFF ^ tempMask));
	ZEPHIR_INIT_VAR(&_11);
	zephir_bitwise_and_function(&_11, &ipByte, &mask);
	ZEPHIR_INIT_VAR(&_12);
	zephir_bitwise_and_function(&_12, &subnetByte, &mask);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_11, &_12));
}

/**
 * Resolve authorization headers.
 */
PHP_METHOD(Phalcon_Http_Request, resolveAuthorizationHeaders)
{
	zend_bool _4, _9, _35, _22$$11;
	zval headers, _5$$5, _36$$19;
	zval resolved, eventsManager, hasEventsManager, container, exploded, digest, authHeader, server, _0, _8, _10, _1$$3, _2$$4, _3$$4, _6$$5, _7$$6, _11$$7, _12$$7, _13$$7, _14$$8, _15$$8, _16$$8, _17$$9, _18$$10, _19$$11, _20$$11, _21$$11, _23$$11, _24$$11, _25$$12, _26$$12, _27$$12, _28$$13, _29$$13, _30$$17, _31$$17, _32$$17, _33$$17, _34$$17, _37$$19, _38$$20;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&hasEventsManager);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&exploded);
	ZVAL_UNDEF(&digest);
	ZVAL_UNDEF(&authHeader);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$13);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$17);
	ZVAL_UNDEF(&_31$$17);
	ZVAL_UNDEF(&_32$$17);
	ZVAL_UNDEF(&_33$$17);
	ZVAL_UNDEF(&_34$$17);
	ZVAL_UNDEF(&_37$$19);
	ZVAL_UNDEF(&_38$$20);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_36$$19);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&authHeader);
	ZVAL_NULL(&authHeader);
	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&container, &_0);
	ZEPHIR_CALL_METHOD(&server, this_ptr, "getserverarray", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "eventsManager");
		ZEPHIR_CALL_METHOD(&hasEventsManager, &container, "has", NULL, 0, &_1$$3);
		zephir_check_call_status();
		if (zephir_is_true(&hasEventsManager)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "eventsManager");
			ZEPHIR_CALL_METHOD(&_2$$4, &container, "getshared", NULL, 0, &_3$$4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&eventsManager, &_2$$4);
		}
	}
	_4 = zephir_is_true(&hasEventsManager);
	if (_4) {
		_4 = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	}
	if (_4) {
		ZEPHIR_INIT_VAR(&_5$$5);
		zephir_create_array(&_5$$5, 1, 0);
		zephir_array_update_string(&_5$$5, SL("server"), &server, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "request:beforeAuthorizationResolve");
		ZEPHIR_CALL_METHOD(&resolved, &eventsManager, "fire", NULL, 0, &_6$$5, this_ptr, &_5$$5);
		zephir_check_call_status();
		if (Z_TYPE_P(&resolved) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_7$$6);
			zephir_fast_array_merge(&_7$$6, &headers, &resolved);
			ZEPHIR_CPY_WRT(&headers, &_7$$6);
		}
	}
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "PHP_AUTH_USER");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasserver", NULL, 0, &_8);
	zephir_check_call_status();
	_9 = zephir_is_true(&_0);
	if (_9) {
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_STRING(&_8, "PHP_AUTH_PW");
		ZEPHIR_CALL_METHOD(&_10, this_ptr, "hasserver", NULL, 0, &_8);
		zephir_check_call_status();
		_9 = zephir_is_true(&_10);
	}
	if (_9) {
		ZEPHIR_INIT_VAR(&_12$$7);
		ZVAL_STRING(&_12$$7, "PHP_AUTH_USER");
		ZEPHIR_CALL_METHOD(&_11$$7, this_ptr, "getserver", NULL, 0, &_12$$7);
		zephir_check_call_status();
		zephir_array_update_string(&headers, SL("Php-Auth-User"), &_11$$7, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_12$$7);
		ZVAL_STRING(&_12$$7, "PHP_AUTH_PW");
		ZEPHIR_CALL_METHOD(&_13$$7, this_ptr, "getserver", NULL, 0, &_12$$7);
		zephir_check_call_status();
		zephir_array_update_string(&headers, SL("Php-Auth-Pw"), &_13$$7, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(&_15$$8);
		ZVAL_STRING(&_15$$8, "HTTP_AUTHORIZATION");
		ZEPHIR_CALL_METHOD(&_14$$8, this_ptr, "hasserver", NULL, 0, &_15$$8);
		zephir_check_call_status();
		if (zephir_is_true(&_14$$8)) {
			ZEPHIR_INIT_VAR(&_17$$9);
			ZVAL_STRING(&_17$$9, "HTTP_AUTHORIZATION");
			ZEPHIR_CALL_METHOD(&authHeader, this_ptr, "getserver", NULL, 0, &_17$$9);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&_15$$8);
			ZVAL_STRING(&_15$$8, "REDIRECT_HTTP_AUTHORIZATION");
			ZEPHIR_CALL_METHOD(&_16$$8, this_ptr, "hasserver", NULL, 0, &_15$$8);
			zephir_check_call_status();
			if (zephir_is_true(&_16$$8)) {
				ZEPHIR_INIT_VAR(&_18$$10);
				ZVAL_STRING(&_18$$10, "REDIRECT_HTTP_AUTHORIZATION");
				ZEPHIR_CALL_METHOD(&authHeader, this_ptr, "getserver", NULL, 0, &_18$$10);
				zephir_check_call_status();
			}
		}
		if (zephir_is_true(&authHeader)) {
			ZEPHIR_INIT_VAR(&_19$$11);
			ZVAL_STRING(&_19$$11, "basic ");
			ZEPHIR_CALL_FUNCTION(&_20$$11, "stripos", NULL, 0, &authHeader, &_19$$11);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_20$$11, 0)) {
				ZVAL_LONG(&_25$$12, 6);
				ZEPHIR_INIT_VAR(&_26$$12);
				zephir_substr(&_26$$12, &authHeader, 6 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CALL_FUNCTION(&_27$$12, "base64_decode", NULL, 490, &_26$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&exploded);
				zephir_fast_explode_str(&exploded, SL(":"), &_27$$12, 2 );
				if (zephir_fast_count_int(&exploded) == 2) {
					zephir_array_fetch_long(&_28$$13, &exploded, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1745);
					zephir_array_update_string(&headers, SL("Php-Auth-User"), &_28$$13, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_long(&_29$$13, &exploded, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1746);
					zephir_array_update_string(&headers, SL("Php-Auth-Pw"), &_29$$13, PH_COPY | PH_SEPARATE);
				}
			} else {
				ZEPHIR_INIT_NVAR(&_19$$11);
				ZVAL_STRING(&_19$$11, "digest ");
				ZEPHIR_CALL_FUNCTION(&_21$$11, "stripos", NULL, 0, &authHeader, &_19$$11);
				zephir_check_call_status();
				_22$$11 = ZEPHIR_IS_LONG_IDENTICAL(&_21$$11, 0);
				if (_22$$11) {
					ZEPHIR_INIT_NVAR(&_19$$11);
					ZVAL_STRING(&_19$$11, "PHP_AUTH_DIGEST");
					ZEPHIR_CALL_METHOD(&_23$$11, this_ptr, "hasserver", NULL, 0, &_19$$11);
					zephir_check_call_status();
					_22$$11 = !zephir_is_true(&_23$$11);
				}
				if (_22$$11) {
					zephir_array_update_string(&headers, SL("Php-Auth-Digest"), &authHeader, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_19$$11);
					ZVAL_STRING(&_19$$11, "bearer ");
					ZEPHIR_CALL_FUNCTION(&_24$$11, "stripos", NULL, 0, &authHeader, &_19$$11);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_24$$11, 0)) {
						zephir_array_update_string(&headers, SL("Authorization"), &authHeader, PH_COPY | PH_SEPARATE);
					}
				}
			}
		}
	}
	if (!(zephir_array_isset_value_string(&headers, SL("Authorization")))) {
		if (zephir_array_isset_value_string(&headers, SL("Php-Auth-User"))) {
			zephir_array_fetch_string(&_30$$17, &headers, SL("Php-Auth-User"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1758);
			zephir_array_fetch_string(&_31$$17, &headers, SL("Php-Auth-Pw"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1758);
			ZEPHIR_INIT_VAR(&_32$$17);
			ZEPHIR_CONCAT_VSV(&_32$$17, &_30$$17, ":", &_31$$17);
			ZEPHIR_CALL_FUNCTION(&_33$$17, "base64_encode", NULL, 493, &_32$$17);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_34$$17);
			ZEPHIR_CONCAT_SV(&_34$$17, "Basic ", &_33$$17);
			zephir_array_update_string(&headers, SL("Authorization"), &_34$$17, PH_COPY | PH_SEPARATE);
		} else {
			zephir_memory_observe(&digest);
			if (zephir_array_isset_string_fetch(&digest, &headers, SL("Php-Auth-Digest"), 0)) {
				zephir_array_update_string(&headers, SL("Authorization"), &digest, PH_COPY | PH_SEPARATE);
			}
		}
	}
	_35 = zephir_is_true(&hasEventsManager);
	if (_35) {
		_35 = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	}
	if (_35) {
		ZEPHIR_INIT_VAR(&_36$$19);
		zephir_create_array(&_36$$19, 2, 0);
		zephir_array_update_string(&_36$$19, SL("headers"), &headers, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_36$$19, SL("server"), &server, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_37$$19);
		ZVAL_STRING(&_37$$19, "request:afterAuthorizationResolve");
		ZEPHIR_CALL_METHOD(&resolved, &eventsManager, "fire", NULL, 0, &_37$$19, this_ptr, &_36$$19);
		zephir_check_call_status();
		if (Z_TYPE_P(&resolved) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_38$$20);
			zephir_fast_array_merge(&_38$$20, &headers, &resolved);
			ZEPHIR_CPY_WRT(&headers, &_38$$20);
		}
	}
	RETURN_CTOR(&headers);
}

/**
 * Smooth out $_FILES to have plain array with all files uploaded
 */
PHP_METHOD(Phalcon_Http_Request, smoothFiles)
{
	zend_bool _15, _13$$5, _25$$10;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *prefix = NULL, *_2;
	zval *names_param = NULL, *types_param = NULL, *tmp_names_param = NULL, *sizes_param = NULL, *errors_param = NULL, prefix_zv, idx, name, file, files, parentFiles, p, *_0, _14, _4$$4, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, *_11$$5, _12$$5, _17$$9, _18$$10, _19$$10, _20$$10, _21$$10, _22$$10, *_23$$10, _24$$10;
	zval names, types, tmp_names, sizes, errors, _3$$4, _16$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&tmp_names);
	ZVAL_UNDEF(&sizes);
	ZVAL_UNDEF(&errors);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&idx);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&parentFiles);
	ZVAL_UNDEF(&p);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_24$$10);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		ZEPHIR_Z_PARAM_ARRAY(names, names_param)
		ZEPHIR_Z_PARAM_ARRAY(types, types_param)
		ZEPHIR_Z_PARAM_ARRAY(tmp_names, tmp_names_param)
		ZEPHIR_Z_PARAM_ARRAY(sizes, sizes_param)
		ZEPHIR_Z_PARAM_ARRAY(errors, errors_param)
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	names_param = ZEND_CALL_ARG(execute_data, 1);
	types_param = ZEND_CALL_ARG(execute_data, 2);
	tmp_names_param = ZEND_CALL_ARG(execute_data, 3);
	sizes_param = ZEND_CALL_ARG(execute_data, 4);
	errors_param = ZEND_CALL_ARG(execute_data, 5);
	ZEPHIR_OBS_COPY_OR_DUP(&names, names_param);
	ZEPHIR_OBS_COPY_OR_DUP(&types, types_param);
	ZEPHIR_OBS_COPY_OR_DUP(&tmp_names, tmp_names_param);
	ZEPHIR_OBS_COPY_OR_DUP(&sizes, sizes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&errors, errors_param);
	zephir_memory_observe(&prefix_zv);
	ZVAL_STR_COPY(&prefix_zv, prefix);
	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	zephir_is_iterable(&names, 0, "phalcon/Http/Request.zep", 1822);
	if (Z_TYPE_P(&names) == IS_ARRAY) {
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
			ZEPHIR_CONCAT_VSV(&p, &prefix_zv, ".", &idx);
			if (Z_TYPE_P(&name) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_3$$4);
				zephir_create_array(&_3$$4, 6, 0);
				zephir_array_update_string(&_3$$4, SL("name"), &name, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_array_fetch(&_4$$4, &types, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1798);
				zephir_array_update_string(&_3$$4, SL("type"), &_4$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_array_fetch(&_4$$4, &tmp_names, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1799);
				zephir_array_update_string(&_3$$4, SL("tmp_name"), &_4$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_array_fetch(&_4$$4, &sizes, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1800);
				zephir_array_update_string(&_3$$4, SL("size"), &_4$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_array_fetch(&_4$$4, &errors, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1801);
				zephir_array_update_string(&_3$$4, SL("error"), &_4$$4, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_3$$4, SL("key"), &p, PH_COPY | PH_SEPARATE);
				zephir_array_append(&files, &_3$$4, PH_SEPARATE, "phalcon/Http/Request.zep", 1803);
			}
			if (Z_TYPE_P(&name) == IS_ARRAY) {
				zephir_array_fetch(&_5$$5, &names, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1808);
				zephir_array_fetch(&_6$$5, &types, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1809);
				zephir_array_fetch(&_7$$5, &tmp_names, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1810);
				zephir_array_fetch(&_8$$5, &sizes, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1811);
				zephir_array_fetch(&_9$$5, &errors, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1812);
				ZEPHIR_CALL_METHOD(&parentFiles, this_ptr, "smoothfiles", &_10, 0, &_5$$5, &_6$$5, &_7$$5, &_8$$5, &_9$$5, &p);
				zephir_check_call_status();
				zephir_is_iterable(&parentFiles, 0, "phalcon/Http/Request.zep", 1819);
				if (Z_TYPE_P(&parentFiles) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parentFiles), _11$$5)
					{
						ZEPHIR_INIT_NVAR(&file);
						ZVAL_COPY(&file, _11$$5);
						zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/Http/Request.zep", 1817);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &parentFiles, "rewind", NULL, 0);
					zephir_check_call_status();
					_13$$5 = 1;
					while (1) {
						if (_13$$5) {
							_13$$5 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &parentFiles, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_12$$5, &parentFiles, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_12$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&file, &parentFiles, "current", NULL, 0);
						zephir_check_call_status();
							zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/Http/Request.zep", 1817);
					}
				}
				ZEPHIR_INIT_NVAR(&file);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &names, "rewind", NULL, 0);
		zephir_check_call_status();
		_15 = 1;
		while (1) {
			if (_15) {
				_15 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &names, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_14, &names, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&idx, &names, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&name, &names, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&p);
				ZEPHIR_CONCAT_VSV(&p, &prefix_zv, ".", &idx);
				if (Z_TYPE_P(&name) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_16$$9);
					zephir_create_array(&_16$$9, 6, 0);
					zephir_array_update_string(&_16$$9, SL("name"), &name, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_17$$9);
					zephir_array_fetch(&_17$$9, &types, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1798);
					zephir_array_update_string(&_16$$9, SL("type"), &_17$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_17$$9);
					zephir_array_fetch(&_17$$9, &tmp_names, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1799);
					zephir_array_update_string(&_16$$9, SL("tmp_name"), &_17$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_17$$9);
					zephir_array_fetch(&_17$$9, &sizes, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1800);
					zephir_array_update_string(&_16$$9, SL("size"), &_17$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_17$$9);
					zephir_array_fetch(&_17$$9, &errors, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1801);
					zephir_array_update_string(&_16$$9, SL("error"), &_17$$9, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_16$$9, SL("key"), &p, PH_COPY | PH_SEPARATE);
					zephir_array_append(&files, &_16$$9, PH_SEPARATE, "phalcon/Http/Request.zep", 1803);
				}
				if (Z_TYPE_P(&name) == IS_ARRAY) {
					zephir_array_fetch(&_18$$10, &names, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1808);
					zephir_array_fetch(&_19$$10, &types, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1809);
					zephir_array_fetch(&_20$$10, &tmp_names, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1810);
					zephir_array_fetch(&_21$$10, &sizes, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1811);
					zephir_array_fetch(&_22$$10, &errors, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1812);
					ZEPHIR_CALL_METHOD(&parentFiles, this_ptr, "smoothfiles", &_10, 0, &_18$$10, &_19$$10, &_20$$10, &_21$$10, &_22$$10, &p);
					zephir_check_call_status();
					zephir_is_iterable(&parentFiles, 0, "phalcon/Http/Request.zep", 1819);
					if (Z_TYPE_P(&parentFiles) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parentFiles), _23$$10)
						{
							ZEPHIR_INIT_NVAR(&file);
							ZVAL_COPY(&file, _23$$10);
							zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/Http/Request.zep", 1817);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &parentFiles, "rewind", NULL, 0);
						zephir_check_call_status();
						_25$$10 = 1;
						while (1) {
							if (_25$$10) {
								_25$$10 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &parentFiles, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_24$$10, &parentFiles, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_24$$10)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&file, &parentFiles, "current", NULL, 0);
							zephir_check_call_status();
								zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/Http/Request.zep", 1817);
						}
					}
					ZEPHIR_INIT_NVAR(&file);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_NVAR(&idx);
	RETURN_CCTOR(&files);
}

/**
 * Checks the filter service and assigns it to the class parameter
 */
PHP_METHOD(Phalcon_Http_Request, getFilterService)
{
	zval container, filterService, _0, _1$$3, _3$$3, _4$$3, _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_2$$4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("filterService"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&filterService, &_0);
	if (Z_TYPE_P(&filterService) != IS_OBJECT) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_1$$3);
		if (Z_TYPE_P(&container) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_http_request_exceptions_filterserviceunavailable_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "phalcon/Http/Request.zep", 1838);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "filter");
		ZEPHIR_CALL_METHOD(&_3$$3, &container, "getshared", NULL, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&filterService, &_3$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("filterService"), &filterService);
	}
	RETURN_MM_MEMBER(getThis(), "filterService");
}

/**
 * parse multipart/form-data from raw data
 */
PHP_METHOD(Phalcon_Http_Request, getFormData)
{
	zend_bool _53, _32$$3, _76$$19;
	zval dataset, headers$$3, headers$$19;
	zval boundary, matches, _0, _1, _2, _3, bodyParts, _4, _5, _6, _7, bodyPart, *_8, _52, splited$$3, _9$$3, _10$$3, headerParts$$3, headerPart$$3, _11$$3, _12$$3, *_13$$3, _31$$3, _49$$3, _50$$3, _51$$3, _14$$5, _15$$5, exploded$$5, headerName$$5, headerValue$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5, explodedHeader$$7, part$$7, *_21$$7, _22$$8, _23$$8, _24$$8, explodedPart$$9, namePart$$9, valuePart$$9, _26$$9, _27$$9, _28$$9, _29$$9, _30$$9, _33$$12, _34$$12, exploded$$12, headerName$$12, headerValue$$12, _35$$12, _36$$12, _37$$12, _38$$12, _39$$12, explodedHeader$$14, part$$14, *_40$$14, _41$$15, _42$$15, _43$$15, explodedPart$$16, namePart$$16, valuePart$$16, _44$$16, _45$$16, _46$$16, _47$$16, _48$$16, splited$$19, _54$$19, _55$$19, headerParts$$19, headerPart$$19, _56$$19, _57$$19, *_58$$19, _75$$19, _93$$19, _94$$19, _95$$19, _59$$21, _60$$21, exploded$$21, headerName$$21, headerValue$$21, _61$$21, _62$$21, _63$$21, _64$$21, _65$$21, explodedHeader$$23, part$$23, *_66$$23, _67$$24, _68$$24, _69$$24, explodedPart$$25, namePart$$25, valuePart$$25, _70$$25, _71$$25, _72$$25, _73$$25, _74$$25, _77$$28, _78$$28, exploded$$28, headerName$$28, headerValue$$28, _79$$28, _80$$28, _81$$28, _82$$28, _83$$28, explodedHeader$$30, part$$30, *_84$$30, _85$$31, _86$$31, _87$$31, explodedPart$$32, namePart$$32, valuePart$$32, _88$$32, _89$$32, _90$$32, _91$$32, _92$$32;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_25 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&boundary);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&bodyParts);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&bodyPart);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&splited$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&headerParts$$3);
	ZVAL_UNDEF(&headerPart$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_31$$3);
	ZVAL_UNDEF(&_49$$3);
	ZVAL_UNDEF(&_50$$3);
	ZVAL_UNDEF(&_51$$3);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&exploded$$5);
	ZVAL_UNDEF(&headerName$$5);
	ZVAL_UNDEF(&headerValue$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&explodedHeader$$7);
	ZVAL_UNDEF(&part$$7);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&explodedPart$$9);
	ZVAL_UNDEF(&namePart$$9);
	ZVAL_UNDEF(&valuePart$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_34$$12);
	ZVAL_UNDEF(&exploded$$12);
	ZVAL_UNDEF(&headerName$$12);
	ZVAL_UNDEF(&headerValue$$12);
	ZVAL_UNDEF(&_35$$12);
	ZVAL_UNDEF(&_36$$12);
	ZVAL_UNDEF(&_37$$12);
	ZVAL_UNDEF(&_38$$12);
	ZVAL_UNDEF(&_39$$12);
	ZVAL_UNDEF(&explodedHeader$$14);
	ZVAL_UNDEF(&part$$14);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_42$$15);
	ZVAL_UNDEF(&_43$$15);
	ZVAL_UNDEF(&explodedPart$$16);
	ZVAL_UNDEF(&namePart$$16);
	ZVAL_UNDEF(&valuePart$$16);
	ZVAL_UNDEF(&_44$$16);
	ZVAL_UNDEF(&_45$$16);
	ZVAL_UNDEF(&_46$$16);
	ZVAL_UNDEF(&_47$$16);
	ZVAL_UNDEF(&_48$$16);
	ZVAL_UNDEF(&splited$$19);
	ZVAL_UNDEF(&_54$$19);
	ZVAL_UNDEF(&_55$$19);
	ZVAL_UNDEF(&headerParts$$19);
	ZVAL_UNDEF(&headerPart$$19);
	ZVAL_UNDEF(&_56$$19);
	ZVAL_UNDEF(&_57$$19);
	ZVAL_UNDEF(&_75$$19);
	ZVAL_UNDEF(&_93$$19);
	ZVAL_UNDEF(&_94$$19);
	ZVAL_UNDEF(&_95$$19);
	ZVAL_UNDEF(&_59$$21);
	ZVAL_UNDEF(&_60$$21);
	ZVAL_UNDEF(&exploded$$21);
	ZVAL_UNDEF(&headerName$$21);
	ZVAL_UNDEF(&headerValue$$21);
	ZVAL_UNDEF(&_61$$21);
	ZVAL_UNDEF(&_62$$21);
	ZVAL_UNDEF(&_63$$21);
	ZVAL_UNDEF(&_64$$21);
	ZVAL_UNDEF(&_65$$21);
	ZVAL_UNDEF(&explodedHeader$$23);
	ZVAL_UNDEF(&part$$23);
	ZVAL_UNDEF(&_67$$24);
	ZVAL_UNDEF(&_68$$24);
	ZVAL_UNDEF(&_69$$24);
	ZVAL_UNDEF(&explodedPart$$25);
	ZVAL_UNDEF(&namePart$$25);
	ZVAL_UNDEF(&valuePart$$25);
	ZVAL_UNDEF(&_70$$25);
	ZVAL_UNDEF(&_71$$25);
	ZVAL_UNDEF(&_72$$25);
	ZVAL_UNDEF(&_73$$25);
	ZVAL_UNDEF(&_74$$25);
	ZVAL_UNDEF(&_77$$28);
	ZVAL_UNDEF(&_78$$28);
	ZVAL_UNDEF(&exploded$$28);
	ZVAL_UNDEF(&headerName$$28);
	ZVAL_UNDEF(&headerValue$$28);
	ZVAL_UNDEF(&_79$$28);
	ZVAL_UNDEF(&_80$$28);
	ZVAL_UNDEF(&_81$$28);
	ZVAL_UNDEF(&_82$$28);
	ZVAL_UNDEF(&_83$$28);
	ZVAL_UNDEF(&explodedHeader$$30);
	ZVAL_UNDEF(&part$$30);
	ZVAL_UNDEF(&_85$$31);
	ZVAL_UNDEF(&_86$$31);
	ZVAL_UNDEF(&_87$$31);
	ZVAL_UNDEF(&explodedPart$$32);
	ZVAL_UNDEF(&namePart$$32);
	ZVAL_UNDEF(&valuePart$$32);
	ZVAL_UNDEF(&_88$$32);
	ZVAL_UNDEF(&_89$$32);
	ZVAL_UNDEF(&_90$$32);
	ZVAL_UNDEF(&_91$$32);
	ZVAL_UNDEF(&_92$$32);
	ZVAL_UNDEF(&dataset);
	ZVAL_UNDEF(&headers$$3);
	ZVAL_UNDEF(&headers$$19);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcontenttype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/boundary=(.*)$/is");
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/boundary=(.*)$/is");
	zephir_preg_match(&_2, &_3, &_0, &matches, 0, 0 , 0 );
	zephir_memory_observe(&boundary);
	zephir_array_fetch_long(&boundary, &matches, 1, PH_NOISY, "phalcon/Http/Request.zep", 1857);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/");
	ZEPHIR_CALL_FUNCTION(&_5, "preg_quote", NULL, 0, &boundary, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVS(&_6, "/\\R?-+", &_5, "/s");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getrawbody", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&bodyParts, "preg_split", NULL, 135, &_6, &_7);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&bodyParts);
	ZEPHIR_CALL_FUNCTION(NULL, "array_pop", NULL, 0, &bodyParts);
	ZEPHIR_UNREF(&bodyParts);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&dataset);
	array_init(&dataset);
	zephir_is_iterable(&bodyParts, 0, "phalcon/Http/Request.zep", 1918);
	if (Z_TYPE_P(&bodyParts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&bodyParts), _8)
		{
			ZEPHIR_INIT_NVAR(&bodyPart);
			ZVAL_COPY(&bodyPart, _8);
			if (ZEPHIR_IS_EMPTY(&bodyPart)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "/\\R\\R/");
			ZVAL_LONG(&_10$$3, 2);
			ZEPHIR_CALL_FUNCTION(&splited$$3, "preg_split", NULL, 135, &_9$$3, &bodyPart, &_10$$3);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&splited$$3, &splited$$3);
			ZEPHIR_INIT_NVAR(&headers$$3);
			array_init(&headers$$3);
			zephir_array_fetch_long(&_11$$3, &splited$$3, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1879);
			ZEPHIR_INIT_NVAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "/\\R/s");
			ZVAL_LONG(&_10$$3, -1);
			ZVAL_LONG(&_12$$3, 1);
			ZEPHIR_CALL_FUNCTION(&headerParts$$3, "preg_split", NULL, 135, &_9$$3, &_11$$3, &_10$$3, &_12$$3);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&headerParts$$3, &headerParts$$3);
			zephir_is_iterable(&headerParts$$3, 0, "phalcon/Http/Request.zep", 1915);
			if (Z_TYPE_P(&headerParts$$3) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&headerParts$$3), _13$$3)
				{
					ZEPHIR_INIT_NVAR(&headerPart$$3);
					ZVAL_COPY(&headerPart$$3, _13$$3);
					ZEPHIR_INIT_NVAR(&_14$$5);
					ZVAL_STRING(&_14$$5, ":");
					ZEPHIR_INIT_NVAR(&_15$$5);
					zephir_fast_strpos(&_15$$5, &headerPart$$3, &_14$$5, 0 );
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_15$$5)) {
						continue;
					}
					ZEPHIR_INIT_NVAR(&exploded$$5);
					zephir_fast_explode_str(&exploded$$5, SL(":"), &headerPart$$3, 2 );
					ZEPHIR_CPY_WRT(&exploded$$5, &exploded$$5);
					ZEPHIR_INIT_NVAR(&_16$$5);
					zephir_array_fetch_long(&_17$$5, &exploded$$5, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1889);
					zephir_fast_trim(&_16$$5, &_17$$5, NULL , ZEPHIR_TRIM_BOTH);
					ZEPHIR_INIT_NVAR(&headerName$$5);
					zephir_fast_strtolower(&headerName$$5, &_16$$5);
					ZEPHIR_CPY_WRT(&headerName$$5, &headerName$$5);
					zephir_array_fetch_long(&_18$$5, &exploded$$5, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1890);
					ZEPHIR_INIT_NVAR(&headerValue$$5);
					zephir_fast_trim(&headerValue$$5, &_18$$5, NULL , ZEPHIR_TRIM_BOTH);
					ZEPHIR_CPY_WRT(&headerValue$$5, &headerValue$$5);
					ZEPHIR_INIT_NVAR(&_19$$5);
					ZVAL_STRING(&_19$$5, ";");
					ZEPHIR_INIT_NVAR(&_20$$5);
					zephir_fast_strpos(&_20$$5, &headerValue$$5, &_19$$5, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_20$$5)) {
						ZEPHIR_INIT_NVAR(&explodedHeader$$7);
						zephir_fast_explode_str(&explodedHeader$$7, SL(";"), &headerValue$$5, LONG_MAX);
						ZEPHIR_CPY_WRT(&explodedHeader$$7, &explodedHeader$$7);
						zephir_is_iterable(&explodedHeader$$7, 0, "phalcon/Http/Request.zep", 1910);
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&explodedHeader$$7), _21$$7)
						{
							ZEPHIR_INIT_NVAR(&part$$7);
							ZVAL_COPY(&part$$7, _21$$7);
							ZEPHIR_INIT_NVAR(&_22$$8);
							zephir_fast_trim(&_22$$8, &part$$7, NULL , ZEPHIR_TRIM_BOTH);
							ZEPHIR_INIT_NVAR(&_23$$8);
							ZVAL_STRING(&_23$$8, "/\"/");
							ZEPHIR_INIT_NVAR(&_24$$8);
							ZVAL_STRING(&_24$$8, "");
							ZEPHIR_CALL_FUNCTION(&part$$7, "preg_replace", &_25, 79, &_23$$8, &_24$$8, &_22$$8);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&part$$7, &part$$7);
							ZEPHIR_INIT_NVAR(&_23$$8);
							ZVAL_STRING(&_23$$8, "=");
							ZEPHIR_INIT_NVAR(&_24$$8);
							zephir_fast_strpos(&_24$$8, &part$$7, &_23$$8, 0 );
							if (!ZEPHIR_IS_FALSE_IDENTICAL(&_24$$8)) {
								ZEPHIR_INIT_NVAR(&explodedPart$$9);
								zephir_fast_explode_str(&explodedPart$$9, SL("="), &part$$7, 2 );
								ZEPHIR_CPY_WRT(&explodedPart$$9, &explodedPart$$9);
								ZEPHIR_INIT_NVAR(&_26$$9);
								zephir_array_fetch_long(&_27$$9, &explodedPart$$9, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1902);
								zephir_fast_trim(&_26$$9, &_27$$9, NULL , ZEPHIR_TRIM_BOTH);
								ZEPHIR_INIT_NVAR(&namePart$$9);
								zephir_fast_strtolower(&namePart$$9, &_26$$9);
								ZEPHIR_CPY_WRT(&namePart$$9, &namePart$$9);
								ZEPHIR_INIT_NVAR(&_28$$9);
								zephir_array_fetch_long(&_29$$9, &explodedPart$$9, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1903);
								zephir_fast_trim(&_28$$9, &_29$$9, NULL , ZEPHIR_TRIM_BOTH);
								ZEPHIR_INIT_NVAR(&_30$$9);
								ZVAL_STRING(&_30$$9, "\"");
								ZEPHIR_INIT_NVAR(&valuePart$$9);
								zephir_fast_trim(&valuePart$$9, &_28$$9, &_30$$9, ZEPHIR_TRIM_BOTH);
								ZEPHIR_CPY_WRT(&valuePart$$9, &valuePart$$9);
								zephir_array_update_multi(&headers$$3, &valuePart$$9, SL("zz"), 2, &headerName$$5, &namePart$$9);
							} else {
								zephir_array_update_multi(&headers$$3, &part$$7, SL("za"), 2, &headerName$$5);
							}
						} ZEND_HASH_FOREACH_END();
						ZEPHIR_INIT_NVAR(&part$$7);
					} else {
						zephir_array_update_zval(&headers$$3, &headerName$$5, &headerValue$$5, PH_COPY | PH_SEPARATE);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &headerParts$$3, "rewind", NULL, 0);
				zephir_check_call_status();
				_32$$3 = 1;
				while (1) {
					if (_32$$3) {
						_32$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &headerParts$$3, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_31$$3, &headerParts$$3, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_31$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&headerPart$$3, &headerParts$$3, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_33$$12);
						ZVAL_STRING(&_33$$12, ":");
						ZEPHIR_INIT_NVAR(&_34$$12);
						zephir_fast_strpos(&_34$$12, &headerPart$$3, &_33$$12, 0 );
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_34$$12)) {
							continue;
						}
						ZEPHIR_INIT_NVAR(&exploded$$12);
						zephir_fast_explode_str(&exploded$$12, SL(":"), &headerPart$$3, 2 );
						ZEPHIR_CPY_WRT(&exploded$$12, &exploded$$12);
						ZEPHIR_INIT_NVAR(&_35$$12);
						zephir_array_fetch_long(&_36$$12, &exploded$$12, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1889);
						zephir_fast_trim(&_35$$12, &_36$$12, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_INIT_NVAR(&headerName$$12);
						zephir_fast_strtolower(&headerName$$12, &_35$$12);
						ZEPHIR_CPY_WRT(&headerName$$12, &headerName$$12);
						zephir_array_fetch_long(&_37$$12, &exploded$$12, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1890);
						ZEPHIR_INIT_NVAR(&headerValue$$12);
						zephir_fast_trim(&headerValue$$12, &_37$$12, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_CPY_WRT(&headerValue$$12, &headerValue$$12);
						ZEPHIR_INIT_NVAR(&_38$$12);
						ZVAL_STRING(&_38$$12, ";");
						ZEPHIR_INIT_NVAR(&_39$$12);
						zephir_fast_strpos(&_39$$12, &headerValue$$12, &_38$$12, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_39$$12)) {
							ZEPHIR_INIT_NVAR(&explodedHeader$$14);
							zephir_fast_explode_str(&explodedHeader$$14, SL(";"), &headerValue$$12, LONG_MAX);
							ZEPHIR_CPY_WRT(&explodedHeader$$14, &explodedHeader$$14);
							zephir_is_iterable(&explodedHeader$$14, 0, "phalcon/Http/Request.zep", 1910);
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&explodedHeader$$14), _40$$14)
							{
								ZEPHIR_INIT_NVAR(&part$$14);
								ZVAL_COPY(&part$$14, _40$$14);
								ZEPHIR_INIT_NVAR(&_41$$15);
								zephir_fast_trim(&_41$$15, &part$$14, NULL , ZEPHIR_TRIM_BOTH);
								ZEPHIR_INIT_NVAR(&_42$$15);
								ZVAL_STRING(&_42$$15, "/\"/");
								ZEPHIR_INIT_NVAR(&_43$$15);
								ZVAL_STRING(&_43$$15, "");
								ZEPHIR_CALL_FUNCTION(&part$$14, "preg_replace", &_25, 79, &_42$$15, &_43$$15, &_41$$15);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&part$$14, &part$$14);
								ZEPHIR_INIT_NVAR(&_42$$15);
								ZVAL_STRING(&_42$$15, "=");
								ZEPHIR_INIT_NVAR(&_43$$15);
								zephir_fast_strpos(&_43$$15, &part$$14, &_42$$15, 0 );
								if (!ZEPHIR_IS_FALSE_IDENTICAL(&_43$$15)) {
									ZEPHIR_INIT_NVAR(&explodedPart$$16);
									zephir_fast_explode_str(&explodedPart$$16, SL("="), &part$$14, 2 );
									ZEPHIR_CPY_WRT(&explodedPart$$16, &explodedPart$$16);
									ZEPHIR_INIT_NVAR(&_44$$16);
									zephir_array_fetch_long(&_45$$16, &explodedPart$$16, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1902);
									zephir_fast_trim(&_44$$16, &_45$$16, NULL , ZEPHIR_TRIM_BOTH);
									ZEPHIR_INIT_NVAR(&namePart$$16);
									zephir_fast_strtolower(&namePart$$16, &_44$$16);
									ZEPHIR_CPY_WRT(&namePart$$16, &namePart$$16);
									ZEPHIR_INIT_NVAR(&_46$$16);
									zephir_array_fetch_long(&_47$$16, &explodedPart$$16, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1903);
									zephir_fast_trim(&_46$$16, &_47$$16, NULL , ZEPHIR_TRIM_BOTH);
									ZEPHIR_INIT_NVAR(&_48$$16);
									ZVAL_STRING(&_48$$16, "\"");
									ZEPHIR_INIT_NVAR(&valuePart$$16);
									zephir_fast_trim(&valuePart$$16, &_46$$16, &_48$$16, ZEPHIR_TRIM_BOTH);
									ZEPHIR_CPY_WRT(&valuePart$$16, &valuePart$$16);
									zephir_array_update_multi(&headers$$3, &valuePart$$16, SL("zz"), 2, &headerName$$12, &namePart$$16);
								} else {
									zephir_array_update_multi(&headers$$3, &part$$14, SL("za"), 2, &headerName$$12);
								}
							} ZEND_HASH_FOREACH_END();
							ZEPHIR_INIT_NVAR(&part$$14);
						} else {
							zephir_array_update_zval(&headers$$3, &headerName$$12, &headerValue$$12, PH_COPY | PH_SEPARATE);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&headerPart$$3);
			zephir_array_fetch_long(&_49$$3, &splited$$3, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1915);
			zephir_array_fetch_string(&_50$$3, &headers$$3, SL("content-disposition"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1915);
			ZEPHIR_OBS_NVAR(&_51$$3);
			zephir_array_fetch_string(&_51$$3, &_50$$3, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 1915);
			zephir_array_update_zval(&dataset, &_51$$3, &_49$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &bodyParts, "rewind", NULL, 0);
		zephir_check_call_status();
		_53 = 1;
		while (1) {
			if (_53) {
				_53 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &bodyParts, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_52, &bodyParts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_52)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&bodyPart, &bodyParts, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_EMPTY(&bodyPart)) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_54$$19);
				ZVAL_STRING(&_54$$19, "/\\R\\R/");
				ZVAL_LONG(&_55$$19, 2);
				ZEPHIR_CALL_FUNCTION(&splited$$19, "preg_split", NULL, 135, &_54$$19, &bodyPart, &_55$$19);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&splited$$19, &splited$$19);
				ZEPHIR_INIT_NVAR(&headers$$19);
				array_init(&headers$$19);
				zephir_array_fetch_long(&_56$$19, &splited$$19, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1879);
				ZEPHIR_INIT_NVAR(&_54$$19);
				ZVAL_STRING(&_54$$19, "/\\R/s");
				ZVAL_LONG(&_55$$19, -1);
				ZVAL_LONG(&_57$$19, 1);
				ZEPHIR_CALL_FUNCTION(&headerParts$$19, "preg_split", NULL, 135, &_54$$19, &_56$$19, &_55$$19, &_57$$19);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&headerParts$$19, &headerParts$$19);
				zephir_is_iterable(&headerParts$$19, 0, "phalcon/Http/Request.zep", 1915);
				if (Z_TYPE_P(&headerParts$$19) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&headerParts$$19), _58$$19)
					{
						ZEPHIR_INIT_NVAR(&headerPart$$19);
						ZVAL_COPY(&headerPart$$19, _58$$19);
						ZEPHIR_INIT_NVAR(&_59$$21);
						ZVAL_STRING(&_59$$21, ":");
						ZEPHIR_INIT_NVAR(&_60$$21);
						zephir_fast_strpos(&_60$$21, &headerPart$$19, &_59$$21, 0 );
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_60$$21)) {
							continue;
						}
						ZEPHIR_INIT_NVAR(&exploded$$21);
						zephir_fast_explode_str(&exploded$$21, SL(":"), &headerPart$$19, 2 );
						ZEPHIR_CPY_WRT(&exploded$$21, &exploded$$21);
						ZEPHIR_INIT_NVAR(&_61$$21);
						zephir_array_fetch_long(&_62$$21, &exploded$$21, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1889);
						zephir_fast_trim(&_61$$21, &_62$$21, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_INIT_NVAR(&headerName$$21);
						zephir_fast_strtolower(&headerName$$21, &_61$$21);
						ZEPHIR_CPY_WRT(&headerName$$21, &headerName$$21);
						zephir_array_fetch_long(&_63$$21, &exploded$$21, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1890);
						ZEPHIR_INIT_NVAR(&headerValue$$21);
						zephir_fast_trim(&headerValue$$21, &_63$$21, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_CPY_WRT(&headerValue$$21, &headerValue$$21);
						ZEPHIR_INIT_NVAR(&_64$$21);
						ZVAL_STRING(&_64$$21, ";");
						ZEPHIR_INIT_NVAR(&_65$$21);
						zephir_fast_strpos(&_65$$21, &headerValue$$21, &_64$$21, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_65$$21)) {
							ZEPHIR_INIT_NVAR(&explodedHeader$$23);
							zephir_fast_explode_str(&explodedHeader$$23, SL(";"), &headerValue$$21, LONG_MAX);
							ZEPHIR_CPY_WRT(&explodedHeader$$23, &explodedHeader$$23);
							zephir_is_iterable(&explodedHeader$$23, 0, "phalcon/Http/Request.zep", 1910);
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&explodedHeader$$23), _66$$23)
							{
								ZEPHIR_INIT_NVAR(&part$$23);
								ZVAL_COPY(&part$$23, _66$$23);
								ZEPHIR_INIT_NVAR(&_67$$24);
								zephir_fast_trim(&_67$$24, &part$$23, NULL , ZEPHIR_TRIM_BOTH);
								ZEPHIR_INIT_NVAR(&_68$$24);
								ZVAL_STRING(&_68$$24, "/\"/");
								ZEPHIR_INIT_NVAR(&_69$$24);
								ZVAL_STRING(&_69$$24, "");
								ZEPHIR_CALL_FUNCTION(&part$$23, "preg_replace", &_25, 79, &_68$$24, &_69$$24, &_67$$24);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&part$$23, &part$$23);
								ZEPHIR_INIT_NVAR(&_68$$24);
								ZVAL_STRING(&_68$$24, "=");
								ZEPHIR_INIT_NVAR(&_69$$24);
								zephir_fast_strpos(&_69$$24, &part$$23, &_68$$24, 0 );
								if (!ZEPHIR_IS_FALSE_IDENTICAL(&_69$$24)) {
									ZEPHIR_INIT_NVAR(&explodedPart$$25);
									zephir_fast_explode_str(&explodedPart$$25, SL("="), &part$$23, 2 );
									ZEPHIR_CPY_WRT(&explodedPart$$25, &explodedPart$$25);
									ZEPHIR_INIT_NVAR(&_70$$25);
									zephir_array_fetch_long(&_71$$25, &explodedPart$$25, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1902);
									zephir_fast_trim(&_70$$25, &_71$$25, NULL , ZEPHIR_TRIM_BOTH);
									ZEPHIR_INIT_NVAR(&namePart$$25);
									zephir_fast_strtolower(&namePart$$25, &_70$$25);
									ZEPHIR_CPY_WRT(&namePart$$25, &namePart$$25);
									ZEPHIR_INIT_NVAR(&_72$$25);
									zephir_array_fetch_long(&_73$$25, &explodedPart$$25, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1903);
									zephir_fast_trim(&_72$$25, &_73$$25, NULL , ZEPHIR_TRIM_BOTH);
									ZEPHIR_INIT_NVAR(&_74$$25);
									ZVAL_STRING(&_74$$25, "\"");
									ZEPHIR_INIT_NVAR(&valuePart$$25);
									zephir_fast_trim(&valuePart$$25, &_72$$25, &_74$$25, ZEPHIR_TRIM_BOTH);
									ZEPHIR_CPY_WRT(&valuePart$$25, &valuePart$$25);
									zephir_array_update_multi(&headers$$19, &valuePart$$25, SL("zz"), 2, &headerName$$21, &namePart$$25);
								} else {
									zephir_array_update_multi(&headers$$19, &part$$23, SL("za"), 2, &headerName$$21);
								}
							} ZEND_HASH_FOREACH_END();
							ZEPHIR_INIT_NVAR(&part$$23);
						} else {
							zephir_array_update_zval(&headers$$19, &headerName$$21, &headerValue$$21, PH_COPY | PH_SEPARATE);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &headerParts$$19, "rewind", NULL, 0);
					zephir_check_call_status();
					_76$$19 = 1;
					while (1) {
						if (_76$$19) {
							_76$$19 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &headerParts$$19, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_75$$19, &headerParts$$19, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_75$$19)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&headerPart$$19, &headerParts$$19, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_77$$28);
							ZVAL_STRING(&_77$$28, ":");
							ZEPHIR_INIT_NVAR(&_78$$28);
							zephir_fast_strpos(&_78$$28, &headerPart$$19, &_77$$28, 0 );
							if (ZEPHIR_IS_FALSE_IDENTICAL(&_78$$28)) {
								continue;
							}
							ZEPHIR_INIT_NVAR(&exploded$$28);
							zephir_fast_explode_str(&exploded$$28, SL(":"), &headerPart$$19, 2 );
							ZEPHIR_CPY_WRT(&exploded$$28, &exploded$$28);
							ZEPHIR_INIT_NVAR(&_79$$28);
							zephir_array_fetch_long(&_80$$28, &exploded$$28, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1889);
							zephir_fast_trim(&_79$$28, &_80$$28, NULL , ZEPHIR_TRIM_BOTH);
							ZEPHIR_INIT_NVAR(&headerName$$28);
							zephir_fast_strtolower(&headerName$$28, &_79$$28);
							ZEPHIR_CPY_WRT(&headerName$$28, &headerName$$28);
							zephir_array_fetch_long(&_81$$28, &exploded$$28, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1890);
							ZEPHIR_INIT_NVAR(&headerValue$$28);
							zephir_fast_trim(&headerValue$$28, &_81$$28, NULL , ZEPHIR_TRIM_BOTH);
							ZEPHIR_CPY_WRT(&headerValue$$28, &headerValue$$28);
							ZEPHIR_INIT_NVAR(&_82$$28);
							ZVAL_STRING(&_82$$28, ";");
							ZEPHIR_INIT_NVAR(&_83$$28);
							zephir_fast_strpos(&_83$$28, &headerValue$$28, &_82$$28, 0 );
							if (!ZEPHIR_IS_FALSE_IDENTICAL(&_83$$28)) {
								ZEPHIR_INIT_NVAR(&explodedHeader$$30);
								zephir_fast_explode_str(&explodedHeader$$30, SL(";"), &headerValue$$28, LONG_MAX);
								ZEPHIR_CPY_WRT(&explodedHeader$$30, &explodedHeader$$30);
								zephir_is_iterable(&explodedHeader$$30, 0, "phalcon/Http/Request.zep", 1910);
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&explodedHeader$$30), _84$$30)
								{
									ZEPHIR_INIT_NVAR(&part$$30);
									ZVAL_COPY(&part$$30, _84$$30);
									ZEPHIR_INIT_NVAR(&_85$$31);
									zephir_fast_trim(&_85$$31, &part$$30, NULL , ZEPHIR_TRIM_BOTH);
									ZEPHIR_INIT_NVAR(&_86$$31);
									ZVAL_STRING(&_86$$31, "/\"/");
									ZEPHIR_INIT_NVAR(&_87$$31);
									ZVAL_STRING(&_87$$31, "");
									ZEPHIR_CALL_FUNCTION(&part$$30, "preg_replace", &_25, 79, &_86$$31, &_87$$31, &_85$$31);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&part$$30, &part$$30);
									ZEPHIR_INIT_NVAR(&_86$$31);
									ZVAL_STRING(&_86$$31, "=");
									ZEPHIR_INIT_NVAR(&_87$$31);
									zephir_fast_strpos(&_87$$31, &part$$30, &_86$$31, 0 );
									if (!ZEPHIR_IS_FALSE_IDENTICAL(&_87$$31)) {
										ZEPHIR_INIT_NVAR(&explodedPart$$32);
										zephir_fast_explode_str(&explodedPart$$32, SL("="), &part$$30, 2 );
										ZEPHIR_CPY_WRT(&explodedPart$$32, &explodedPart$$32);
										ZEPHIR_INIT_NVAR(&_88$$32);
										zephir_array_fetch_long(&_89$$32, &explodedPart$$32, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1902);
										zephir_fast_trim(&_88$$32, &_89$$32, NULL , ZEPHIR_TRIM_BOTH);
										ZEPHIR_INIT_NVAR(&namePart$$32);
										zephir_fast_strtolower(&namePart$$32, &_88$$32);
										ZEPHIR_CPY_WRT(&namePart$$32, &namePart$$32);
										ZEPHIR_INIT_NVAR(&_90$$32);
										zephir_array_fetch_long(&_91$$32, &explodedPart$$32, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1903);
										zephir_fast_trim(&_90$$32, &_91$$32, NULL , ZEPHIR_TRIM_BOTH);
										ZEPHIR_INIT_NVAR(&_92$$32);
										ZVAL_STRING(&_92$$32, "\"");
										ZEPHIR_INIT_NVAR(&valuePart$$32);
										zephir_fast_trim(&valuePart$$32, &_90$$32, &_92$$32, ZEPHIR_TRIM_BOTH);
										ZEPHIR_CPY_WRT(&valuePart$$32, &valuePart$$32);
										zephir_array_update_multi(&headers$$19, &valuePart$$32, SL("zz"), 2, &headerName$$28, &namePart$$32);
									} else {
										zephir_array_update_multi(&headers$$19, &part$$30, SL("za"), 2, &headerName$$28);
									}
								} ZEND_HASH_FOREACH_END();
								ZEPHIR_INIT_NVAR(&part$$30);
							} else {
								zephir_array_update_zval(&headers$$19, &headerName$$28, &headerValue$$28, PH_COPY | PH_SEPARATE);
							}
					}
				}
				ZEPHIR_INIT_NVAR(&headerPart$$19);
				zephir_array_fetch_long(&_93$$19, &splited$$19, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1915);
				zephir_array_fetch_string(&_94$$19, &headers$$19, SL("content-disposition"), PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1915);
				ZEPHIR_OBS_NVAR(&_95$$19);
				zephir_array_fetch_string(&_95$$19, &_94$$19, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 1915);
				zephir_array_update_zval(&dataset, &_95$$19, &_93$$19, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&bodyPart);
	RETURN_CTOR(&dataset);
}

/**
 * Return post data from rawBody, form data, or urlencoded form data
 *
 * @param array|null $data
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getPostData)
{
	zend_bool _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, result, _0$$3, _1$$3, _3$$3, _4$$3, _5$$3, _6$$4, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data);
	if (ZEPHIR_IS_EMPTY(data)) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "isjson", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_0$$3)) {
			ZVAL_BOOL(&_6$$4, 1);
			ZEPHIR_CALL_METHOD(&result, this_ptr, "getjsonrawbody", NULL, 0, &_6$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getcontenttype", NULL, 0);
			zephir_check_call_status();
			_2$$3 = zephir_is_true(&_1$$3);
			if (_2$$3) {
				ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "getcontenttype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_4$$3);
				ZVAL_STRING(&_4$$3, "multipart/form-data");
				ZEPHIR_CALL_FUNCTION(&_5$$3, "stripos", NULL, 0, &_3$$3, &_4$$3);
				zephir_check_call_status();
				_2$$3 = !ZEPHIR_IS_FALSE_IDENTICAL(&_5$$3);
			}
			if (_2$$3) {
				ZEPHIR_CALL_METHOD(&result, this_ptr, "getformdata", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&result);
				array_init(&result);
				ZEPHIR_CALL_METHOD(&_7$$6, this_ptr, "getrawbody", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_MAKE_REF(&result);
				ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 0, &_7$$6, &result);
				ZEPHIR_UNREF(&result);
				zephir_check_call_status();
			}
		}
	} else {
		ZEPHIR_CPY_WRT(&result, data);
	}
	if (Z_TYPE_P(&result) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&result);
		array_init(&result);
	}
	RETURN_CCTOR(&result);
}

PHP_METHOD(Phalcon_Http_Request, getServerArray)
{
	zval _SERVER;

	ZVAL_UNDEF(&_SERVER);
	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_is_true(&_SERVER)) {
		RETVAL_ZVAL(&_SERVER, 1, 0);
		return;
	}
	array_init(return_value);
	return;
}

/**
 * Verify if given IP address is trusted
 *
 * @param string $ip
 * @return bool
 */
PHP_METHOD(Phalcon_Http_Request, isProxyTrusted)
{
	zend_bool _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval ip_zv, trusted, _0, *_1, _5, _2$$3, _3$$3, _7$$6, _8$$6;
	zend_string *ip = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ip_zv);
	ZVAL_UNDEF(&trusted);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(ip)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&ip_zv);
	ZVAL_STR_COPY(&ip_zv, ip);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("trustedProxies"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Http/Request.zep", 1981);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&trusted);
			ZVAL_COPY(&trusted, _1);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "/");
			ZEPHIR_INIT_NVAR(&_3$$3);
			zephir_fast_strpos(&_3$$3, &trusted, &_2$$3, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&_3$$3)) {
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "isipaddressincidr", &_4, 0, &ip_zv, &trusted);
				zephir_check_call_status();
				RETURN_MM();
			} else {
				RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&ip_zv, &trusted));
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&trusted, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$6);
				ZVAL_STRING(&_7$$6, "/");
				ZEPHIR_INIT_NVAR(&_8$$6);
				zephir_fast_strpos(&_8$$6, &trusted, &_7$$6, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_8$$6)) {
					ZEPHIR_RETURN_CALL_METHOD(this_ptr, "isipaddressincidr", &_4, 0, &ip_zv, &trusted);
					zephir_check_call_status();
					RETURN_MM();
				} else {
					RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&ip_zv, &trusted));
				}
		}
	}
	ZEPHIR_INIT_NVAR(&trusted);
	RETURN_MM_BOOL(0);
}

/**
 * Verify if given IP address is public, eg. not private or reserved IP
 *
 * @param string $forwardedIp
 * @return string|false
 * @throws \Phalcon\Filter\Exception
 */
PHP_METHOD(Phalcon_Http_Request, isValidPublicIp)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval forwardedIp_zv, filterService, filtered;
	zend_string *forwardedIp = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&forwardedIp_zv);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(forwardedIp)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&forwardedIp_zv);
	ZVAL_STR_COPY(&forwardedIp_zv, forwardedIp);
	ZEPHIR_CALL_METHOD(&filterService, this_ptr, "getfilterservice", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	add_assoc_long_ex(&_1, SL("filter"), (8388608 | 4194304));
	zephir_array_update_string(&_0, SL("ip"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&filtered, &filterService, "sanitize", NULL, 0, &forwardedIp_zv, &_0);
	zephir_check_call_status();
	RETURN_CCTOR(&filtered);
}

/**
 * Helper to build the uploaded files array
 */
PHP_METHOD(Phalcon_Http_Request, processFiles)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *key = NULL;
	zend_bool namedKeys;
	zval *files_param = NULL, *namedKeys_param = NULL, *input_param = NULL, key_zv, _0$$3, _1$$4;
	zval files, input;

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		ZEPHIR_Z_PARAM_ARRAY(files, files_param)
		Z_PARAM_BOOL(namedKeys)
		ZEPHIR_Z_PARAM_ARRAY(input, input_param)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	files_param = ZEND_CALL_ARG(execute_data, 1);
	namedKeys_param = ZEND_CALL_ARG(execute_data, 2);
	input_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_get_arrval(&files, files_param);
	zephir_get_arrval(&input, input_param);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (namedKeys == 1) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_http_request_file_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &input, &key_zv);
		zephir_check_call_status();
		zephir_array_update_zval(&files, &key_zv, &_0$$3, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_http_request_file_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0, &input, &key_zv);
		zephir_check_call_status();
		zephir_array_append(&files, &_1$$4, PH_SEPARATE, "phalcon/Http/Request.zep", 2017);
	}
	RETURN_CTOR(&files);
}

zend_object *zephir_init_properties_Phalcon_Http_Request(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("trustedProxies"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("trustedProxies"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("queryFilters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("queryFilters"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

