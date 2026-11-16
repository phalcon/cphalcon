
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
#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/math.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
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
 *
 * @phpstan-import-type http_basic_auth from HttpTypes
 * @phpstan-import-type http_digest_auth from HttpTypes
 * @phpstan-import-type http_form_data from HttpTypes
 * @phpstan-import-type http_parameter_filters from HttpTypes
 * @phpstan-import-type http_php_files from HttpTypes
 * @phpstan-import-type http_quality_part from HttpTypes
 * @phpstan-import-type http_request_headers from HttpTypes
 * @phpstan-import-type http_smooth_file from HttpTypes
 * @phpstan-import-type http_uploaded_file from HttpTypes
 * @phpstan-import-type http_uploaded_files from HttpTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Request)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http, Request, phalcon, http_request, phalcon_di_abstractinjectionaware_ce, phalcon_http_request_method_entry, 0);

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_http_request_ce, SL("attributes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Http\\Request\\Bag\\AttributeBag"));
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_http_request_ce, SL("filterService"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Filter\\FilterInterface"));
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_http_request_ce, SL("methodOverride"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @var array|null
	 *
	 * @phpstan-var http_form_data|null
	 */
	zend_declare_property_null(phalcon_http_request_ce, SL("postCache"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_request_ce, SL("queryFilters"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_http_request_ce, SL("rawBody"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_http_request_ce, SL("strictHostCheck"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_request_ce, SL("trustedProxies"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_http_request_ce, SL("trustedProxyHeader"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_http_request_ce, SL("eventsManager"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Events\\ManagerInterface"));
	}

	phalcon_http_request_ce->create_object = zephir_init_properties_Phalcon_Http_Request;

	zend_class_implements(phalcon_http_request_ce, 1, phalcon_http_requestinterface_ce);
	zend_class_implements(phalcon_http_request_ce, 1, phalcon_http_message_requestmethodinterface_ce);
	zend_class_implements(phalcon_http_request_ce, 1, phalcon_contracts_http_attributerequest_ce);
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
 *
 * @todo check the filters
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getHelper", &_zephir_call_cache[0], &_REQUEST, &name_zv, filters, defaultValue, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets an array with mime/types and their quality accepted by the
 * browser/client from _SERVER["HTTP_ACCEPT"]
 *
 * @phpstan-return list<http_quality_part>
 */
PHP_METHOD(Phalcon_Http_Request, getAcceptableContent)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "accept");
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getQualityHeader", &_zephir_call_cache[0], &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the request attributes bag. Attributes are arbitrary,
 * application-defined values attached to the request during its
 * lifecycle (router, dispatcher, security components etc.). The bag
 * is created empty on first access and the same instance is returned
 * on every subsequent call.
 *
 *```php
 * $request->getAttributes()->set("user", $user);
 *
 * $user = $request->getAttributes()->get("user");
 *```
 */
PHP_METHOD(Phalcon_Http_Request, getAttributes)
{
	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 900, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_http_request_bag_attributebag_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 900, &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "attributes");
}

/**
 * Gets auth info accepted by the browser/client from
 * $_SERVER["PHP_AUTH_USER"]
 *
 * @phpstan-return http_basic_auth|null
 */
PHP_METHOD(Phalcon_Http_Request, getBasicAuth)
{
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _SERVER, password, server, username;

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&username);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_CPY_WRT(&server, &_SERVER);
	zephir_memory_observe(&username);
	_0 = zephir_array_isset_string_fetch(&username, &server, SL("PHP_AUTH_USER"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		RETURN_MM_NULL();
	}
	zephir_memory_observe(&password);
	_1 = zephir_array_isset_string_fetch(&password, &server, SL("PHP_AUTH_PW"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getAcceptableContent", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "accept");
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getBestQuality", &_zephir_call_cache[1], &_0, &_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getClientCharsets", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "charset");
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getBestQuality", &_zephir_call_cache[1], &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets the best language accepted by the browser/client from
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getLanguages", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "language");
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getBestQuality", &_zephir_call_cache[1], &_0, &_1);
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
 */
PHP_METHOD(Phalcon_Http_Request, getClientAddress)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *trustForwardedHeader_param = NULL, _SERVER, server, address, trustedProxyHeaderIp, forwarded, forwardedIps, reverseForwardedIps, forwardedIp, filteredIp, _1$$4, _6$$4, _2$$5, _8$$8, _9$$8, *_10$$8, *_11$$8, _15$$8, _14$$9, _19$$12;
	zend_bool trustForwardedHeader, _0, _4$$4, _5$$4, _7$$4, _3$$5, _16$$8, _12$$9, _13$$9, _17$$12, _18$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&address);
	ZVAL_UNDEF(&trustedProxyHeaderIp);
	ZVAL_UNDEF(&forwarded);
	ZVAL_UNDEF(&forwardedIps);
	ZVAL_UNDEF(&reverseForwardedIps);
	ZVAL_UNDEF(&forwardedIp);
	ZVAL_UNDEF(&filteredIp);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_19$$12);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("trustedProxyHeader", 18, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("trustedProxies", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(trustForwardedHeader)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 0, 1, &trustForwardedHeader_param);
	if (!trustForwardedHeader_param) {
		trustForwardedHeader = 0;
	} else {
		}
	ZEPHIR_CPY_WRT(&server, &_SERVER);
	zephir_memory_observe(&address);
	_0 = zephir_array_isset_string_fetch(&address, &server, SL("REMOTE_ADDR"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_0;
	if (!((Z_TYPE_P(&address) == IS_STRING))) {
		RETURN_MM_BOOL(0);
	}
	if (trustForwardedHeader) {
		zephir_read_property_cached(&_1$$4, this_ptr, _zephir_prop_0, 901, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!ZEPHIR_IS_STRING_IDENTICAL(&_1$$4, "")) {
			zephir_memory_observe(&trustedProxyHeaderIp);
			zephir_read_property_cached(&_2$$5, this_ptr, _zephir_prop_0, 901, PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_3$$5 = zephir_array_isset_fetch(&trustedProxyHeaderIp, &server, &_2$$5, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_3$$5) {
				RETURN_CCTOR(&trustedProxyHeaderIp);
			}
		}
		_4$$4 = zephir_isempty_property_fast(this_ptr, _zephir_prop_1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_5$$4 = !(_4$$4);
		if (_5$$4) {
			ZEPHIR_CALL_METHOD_CACHED(&_6$$4, this_ptr, "isProxyTrusted", &_zephir_call_cache[0], &address);
			zephir_check_call_status();
			_5$$4 = !zephir_is_true(&_6$$4);
		}
		if (_5$$4) {
			RETURN_CCTOR(&address);
		}
		zephir_memory_observe(&forwarded);
		_7$$4 = zephir_array_isset_string_fetch(&forwarded, &server, SL("HTTP_X_FORWARDED_FOR"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_7$$4;
		if (!(ZEPHIR_IS_EMPTY(&forwarded))) {
			ZEPHIR_INIT_VAR(&_8$$8);
			zephir_fast_explode_str(&_8$$8, SL(","), &forwarded, NULL);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_9$$8);
			ZVAL_STRING(&_9$$8, "trim");
			ZEPHIR_CALL_FUNCTION(&forwardedIps, "array_map", NULL, 59, &_9$$8, &_8$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&reverseForwardedIps, "array_reverse", NULL, 80, &forwardedIps);
			zephir_check_call_status();
			if (Z_TYPE_P(&reverseForwardedIps) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_9$$8);
				zephir_string_to_char_array(&_9$$8, &reverseForwardedIps);
				_10$$8 = &_9$$8;
			} else {
				_10$$8 = &reverseForwardedIps;
			}
			zephir_is_iterable(_10$$8, 0, "phalcon/Http/Request.zep", 280);
			if (Z_TYPE_P(_10$$8) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_10$$8), _11$$8)
				{
					ZEPHIR_INIT_NVAR(&forwardedIp);
					ZVAL_COPY(&forwardedIp, _11$$8);
					_12$$9 = zephir_isempty_property_fast(this_ptr, _zephir_prop_1);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_13$$9 = !(_12$$9);
					if (_13$$9) {
						ZEPHIR_CALL_METHOD_CACHED(&_14$$9, this_ptr, "isProxyTrusted", &_zephir_call_cache[1], &forwardedIp);
						zephir_check_call_status();
						_13$$9 = zephir_is_true(&_14$$9);
					}
					if (_13$$9) {
						continue;
					}
					ZEPHIR_CALL_METHOD_CACHED(&filteredIp, this_ptr, "isValidPublicIp", &_zephir_call_cache[2], &forwardedIp);
					zephir_check_call_status();
					if (zephir_is_true(&filteredIp)) {
						RETURN_CCTOR(&filteredIp);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _10$$8, "rewind", &_zephir_call_cache[3]);
				zephir_check_call_status();
				_16$$8 = 1;
				while (1) {
					if (_16$$8) {
						_16$$8 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _10$$8, "next", &_zephir_call_cache[4]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_15$$8, _10$$8, "valid", &_zephir_call_cache[5]);
					zephir_check_call_status();
					if (!zend_is_true(&_15$$8)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&forwardedIp, _10$$8, "current", &_zephir_call_cache[6]);
					zephir_check_call_status();
						_17$$12 = zephir_isempty_property_fast(this_ptr, _zephir_prop_1);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_18$$12 = !(_17$$12);
						if (_18$$12) {
							ZEPHIR_CALL_METHOD_CACHED(&_19$$12, this_ptr, "isProxyTrusted", &_zephir_call_cache[7], &forwardedIp);
							zephir_check_call_status();
							_18$$12 = zephir_is_true(&_19$$12);
						}
						if (_18$$12) {
							continue;
						}
						ZEPHIR_CALL_METHOD_CACHED(&filteredIp, this_ptr, "isValidPublicIp", &_zephir_call_cache[8], &forwardedIp);
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
 *
 * @phpstan-return list<http_quality_part>
 */
PHP_METHOD(Phalcon_Http_Request, getClientCharsets)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT_CHARSET");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "charset");
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getQualityHeader", &_zephir_call_cache[0], &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets content type which request has been made
 */
PHP_METHOD(Phalcon_Http_Request, getContentType)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _SERVER, contentType, server;

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&contentType);
	ZVAL_UNDEF(&server);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_CPY_WRT(&server, &_SERVER);
	zephir_memory_observe(&contentType);
	_0 = zephir_array_isset_string_fetch(&contentType, &server, SL("CONTENT_TYPE"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&contentType);
}

/**
 * Gets auth info accepted by the browser/client from
 * $_SERVER["PHP_AUTH_DIGEST"]
 *
 * @phpstan-return http_digest_auth
 */
PHP_METHOD(Phalcon_Http_Request, getDigestAuth)
{
	zend_bool _0;
	zval auth;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, digest, matches, match, server, _1$$3, _2$$3, _3$$3, *_4$$3, _5$$3, *_6$$3, _7$$5, _8$$5;

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&digest);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&auth);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&auth);
	array_init(&auth);
	ZEPHIR_CPY_WRT(&server, &_SERVER);
	zephir_memory_observe(&digest);
	_0 = zephir_array_isset_string_fetch(&digest, &server, SL("PHP_AUTH_DIGEST"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&matches);
		array_init(&matches);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "#(\\w+)=(['\"]?)([^'\" ,]+)\\2#");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "#(\\w+)=(['\"]?)([^'\" ,]+)\\2#");
		zephir_preg_match(&_2$$3, &_3$$3, &digest, &matches, 1, 2 , 0 );
		if (!zephir_is_true(&_2$$3)) {
			RETURN_CTOR(&auth);
		}
		if (Z_TYPE_P(&matches) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_5$$3);
			zephir_string_to_char_array(&_5$$3, &matches);
			_4$$3 = &_5$$3;
		} else {
			_4$$3 = &matches;
		}
		zephir_is_iterable(_4$$3, 0, "phalcon/Http/Request.zep", 343);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4$$3), _6$$3)
		{
			ZEPHIR_INIT_NVAR(&match);
			ZVAL_COPY(&match, _6$$3);
			ZEPHIR_OBS_NVAR(&_7$$5);
			zephir_array_fetch_long(&_7$$5, &match, 1, PH_NOISY, "phalcon/Http/Request.zep", 341);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_8$$5);
			zephir_array_fetch_long(&_8$$5, &match, 3, PH_NOISY, "phalcon/Http/Request.zep", 341);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&auth, &_7$$5, &_8$$5, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&match);
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
	zend_bool notAllowEmpty, noRecursive, _2;
	zval methodKey_zv, method_zv, name_zv, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, filters, _0, _1, _3, _4;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("queryFilters", 12, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 902, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_1);
	zephir_array_fetch(&_1, &_0, &methodKey_zv, 0, "phalcon/Http/Request.zep", 361);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_array_isset_fetch(&filters, &_1, &name_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_2)) {
		ZEPHIR_INIT_NVAR(&filters);
		array_init(&filters);
	}
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
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method_zv, NULL, 0, &name_zv, &filters, defaultValue, &_3, &_4);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getFilteredData", &_zephir_call_cache[0], &_0, &_1, &name_zv, defaultValue, &_2, &_3);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getFilteredData", &_zephir_call_cache[0], &_0, &_1, &name_zv, defaultValue, &_2, &_3);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getFilteredData", &_zephir_call_cache[0], &_0, &_1, &name_zv, defaultValue, &_2, &_3);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getFilteredData", &_zephir_call_cache[0], &_0, &_1, &name_zv, defaultValue, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets HTTP header from request data
 */
PHP_METHOD(Phalcon_Http_Request, getHeader)
{
	zend_bool _3, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval header_zv, _SERVER, value, name, server, _0, _1, _2, _4;
	zend_string *header = NULL;

	ZVAL_UNDEF(&header_zv);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(header)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_memory_observe(&header_zv);
	ZVAL_STR_COPY(&header_zv, header);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "-");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_");
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 1, &header_zv, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	zephir_fast_strtoupper(&name, &_2);
	ZEPHIR_CPY_WRT(&server, &_SERVER);
	zephir_memory_observe(&value);
	_3 = zephir_array_isset_fetch(&value, &server, &name, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		RETURN_CCTOR(&value);
	}
	ZEPHIR_OBS_NVAR(&value);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "HTTP_", &name);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = zephir_array_isset_fetch(&value, &server, &_4, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		RETURN_CCTOR(&value);
	}
	RETURN_MM_STRING("");
}

/**
 * Returns the available headers in the request
 *
 * ```php
 * $_SERVER = [
 *     "PHP_AUTH_USER" => "phalcon",
 *     "PHP_AUTH_PW"   => "secret",
 * ];
 *
 * $headers = $request->getHeaders();
 *
 * echo $headers["Authorization"]; // Basic cGhhbGNvbjpzZWNyZXQ=
 * ```
 *
 * @phpstan-return http_request_headers
 */
PHP_METHOD(Phalcon_Http_Request, getHeaders)
{
	zend_bool _16$$3;
	zend_string *_4;
	zend_ulong _3;
	zval headers, contentHeaders;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, _SERVER, name, value, authHeaders, server, *_0, _1, *_2, _24, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4, _12$$4, _13$$4, _14$$4, _15$$3, _17$$5, _18$$5, _19$$5, _20$$5, _21$$5, _22$$5, _23$$5;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&authHeaders);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&contentHeaders);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	ZEPHIR_INIT_VAR(&contentHeaders);
	zephir_create_array(&contentHeaders, 3, 0);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_TYPE"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_LENGTH"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_MD5"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_CPY_WRT(&server, &_SERVER);
	if (Z_TYPE_P(&server) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_string_to_char_array(&_1, &server);
		_0 = &_1;
	} else {
		_0 = &server;
	}
	zephir_is_iterable(_0, 0, "phalcon/Http/Request.zep", 540);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_0), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&name, _4);
		} else {
			ZVAL_LONG(&name, _3);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _2);
		if (zephir_start_with_str(&name, SL("HTTP_"))) {
			ZEPHIR_INIT_NVAR(&_5$$4);
			ZEPHIR_INIT_NVAR(&_6$$4);
			ZVAL_LONG(&_7$$4, 5);
			ZEPHIR_INIT_NVAR(&_8$$4);
			zephir_substr(&_8$$4, &name, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_NVAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "_");
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZVAL_STRING(&_10$$4, " ");
			zephir_fast_str_replace(&_6$$4, &_9$$4, &_10$$4, &_8$$4);
			zephir_fast_strtolower(&_5$$4, &_6$$4);
			ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_11, 104, &_5$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_12$$4);
			ZEPHIR_INIT_NVAR(&_13$$4);
			ZVAL_STRING(&_13$$4, " ");
			ZEPHIR_INIT_NVAR(&_14$$4);
			ZVAL_STRING(&_14$$4, "-");
			zephir_fast_str_replace(&_12$$4, &_13$$4, &_14$$4, &name);
			ZEPHIR_CPY_WRT(&name, &_12$$4);
			zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			continue;
		}
		ZEPHIR_INIT_NVAR(&_15$$3);
		zephir_fast_strtoupper(&_15$$3, &name);
		ZEPHIR_CPY_WRT(&name, &_15$$3);
		_16$$3 = zephir_array_isset_value(&contentHeaders, &name);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_16$$3) {
			ZEPHIR_INIT_NVAR(&_17$$5);
			ZEPHIR_INIT_NVAR(&_18$$5);
			ZEPHIR_INIT_NVAR(&_19$$5);
			ZVAL_STRING(&_19$$5, "_");
			ZEPHIR_INIT_NVAR(&_20$$5);
			ZVAL_STRING(&_20$$5, " ");
			zephir_fast_str_replace(&_18$$5, &_19$$5, &_20$$5, &name);
			zephir_fast_strtolower(&_17$$5, &_18$$5);
			ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_11, 104, &_17$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_21$$5);
			ZEPHIR_INIT_NVAR(&_22$$5);
			ZVAL_STRING(&_22$$5, " ");
			ZEPHIR_INIT_NVAR(&_23$$5);
			ZVAL_STRING(&_23$$5, "-");
			zephir_fast_str_replace(&_21$$5, &_22$$5, &_23$$5, &name);
			ZEPHIR_CPY_WRT(&name, &_21$$5);
			zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_CALL_METHOD_CACHED(&authHeaders, this_ptr, "resolveAuthorizationHeaders", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_24);
	zephir_fast_array_merge(&_24, &headers, &authHeaders);
	if (UNEXPECTED(Z_TYPE_P(&_24) != IS_ARRAY)) {
		zephir_throw_variable_type_error(&_24, "headers", "array");
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&headers, &_24);
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
	zval _14;
	zend_bool _3;
	zval host, strict, cleanHost, _0, _1$$3, _2$$4, _4$$5, _9$$5, _10$$5, _11$$5, _12$$5, _5$$6, _6$$6, _7$$6, _13$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&strict);
	ZVAL_UNDEF(&cleanHost);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("strictHostCheck", 15, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&strict);
	zephir_read_property_cached(&strict, this_ptr, _zephir_prop_0, 903, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_HOST");
	ZEPHIR_CALL_METHOD_CACHED(&host, this_ptr, "getServer", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&host))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "SERVER_NAME");
		ZEPHIR_CALL_METHOD_CACHED(&host, this_ptr, "getServer", &_zephir_call_cache[1], &_1$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(&host))) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "SERVER_ADDR");
			ZEPHIR_CALL_METHOD_CACHED(&host, this_ptr, "getServer", &_zephir_call_cache[2], &_2$$4);
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
		if (zephir_memnstr_str(&cleanHost, SL(":"), "phalcon/Http/Request.zep", 614)) {
			ZEPHIR_INIT_VAR(&_5$$6);
			ZVAL_STRING(&_5$$6, "/:[[:digit:]]+$/");
			ZEPHIR_INIT_VAR(&_6$$6);
			ZVAL_STRING(&_6$$6, "");
			ZEPHIR_CALL_FUNCTION(&_7$$6, "preg_replace", &_8, 2, &_5$$6, &_6$$6, &cleanHost);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&cleanHost, &_7$$6);
		}
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "/[a-z0-9-]+\\.?/");
		ZEPHIR_INIT_VAR(&_10$$5);
		ZVAL_STRING(&_10$$5, "");
		ZEPHIR_CALL_FUNCTION(&_11$$5, "preg_replace", &_8, 2, &_9$$5, &_10$$5, &cleanHost);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_12$$5);
		ZVAL_STRING(&_12$$5, "");
		if (UNEXPECTED((!ZEPHIR_IS_IDENTICAL(&_12$$5, &_11$$5)))) {
			ZEPHIR_INIT_VAR(&_13$$7);
			object_init_ex(&_13$$7, phalcon_http_request_exceptions_invalidhost_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_13$$7, "__construct", &_zephir_call_cache[3], &host);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_13$$7, "phalcon/Http/Request.zep", 624);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CPY_WRT(&cleanHost, &host);
	}
	zephir_cast_to_string(&_14, &cleanHost);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&_14);
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
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _SERVER, httpReferer, server;

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&httpReferer);
	ZVAL_UNDEF(&server);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_CPY_WRT(&server, &_SERVER);
	zephir_memory_observe(&httpReferer);
	_0 = zephir_array_isset_string_fetch(&httpReferer, &server, SL("HTTP_REFERER"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		RETURN_MM_STRING("");
	}
	RETURN_CCTOR(&httpReferer);
}

/**
 * Gets decoded JSON HTTP raw request body
 *
 * @phpstan-return array<array-key, mixed>|bool|stdClass
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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
	ZEPHIR_CALL_METHOD_CACHED(&rawBody, this_ptr, "getRawBody", &_zephir_call_cache[0]);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
	}

	if (associative) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "__invoke", &_zephir_call_cache[2], &rawBody, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets languages array and their quality accepted by the browser/client
 * from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 *
 * @phpstan-return list<http_quality_part>
 */
PHP_METHOD(Phalcon_Http_Request, getLanguages)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT_LANGUAGE");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "language");
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getQualityHeader", &_zephir_call_cache[0], &_0, &_1);
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
	zend_bool _0, _4$$7;
	zval returnMethod;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, _REQUEST, overridedMethod, spoofedMethod, requestMethod, _1, _5, _2$$5, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_UNDEF(&overridedMethod);
	ZVAL_UNDEF(&spoofedMethod);
	ZVAL_UNDEF(&requestMethod);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&returnMethod);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("methodOverride", 14, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&returnMethod);
	ZVAL_STRING(&returnMethod, "");
	zephir_memory_observe(&requestMethod);
	_0 = zephir_array_isset_string_fetch(&requestMethod, &_SERVER, SL("REQUEST_METHOD"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (EXPECTED(_0)) {
		ZEPHIR_INIT_NVAR(&returnMethod);
		zephir_fast_strtoupper(&returnMethod, &requestMethod);
	} else {
		RETURN_MM_STRING("GET");
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "POST");
	if (ZEPHIR_IS_IDENTICAL(&_1, &returnMethod)) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "X-HTTP-METHOD-OVERRIDE");
		ZEPHIR_CALL_METHOD_CACHED(&overridedMethod, this_ptr, "getHeader", &_zephir_call_cache[0], &_2$$5);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&overridedMethod))) {
			ZEPHIR_INIT_NVAR(&returnMethod);
			zephir_fast_strtoupper(&returnMethod, &overridedMethod);
		} else {
			zephir_read_property_cached(&_3$$5, this_ptr, _zephir_prop_0, 904, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_true(&_3$$5)) {
				zephir_memory_observe(&spoofedMethod);
				_4$$7 = zephir_array_isset_string_fetch(&spoofedMethod, &_REQUEST, SL("_method"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_4$$7) {
					ZEPHIR_INIT_NVAR(&returnMethod);
					zephir_fast_strtoupper(&returnMethod, &spoofedMethod);
				}
			}
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_5, this_ptr, "isValidHttpMethod", &_zephir_call_cache[1], &returnMethod);
	zephir_check_call_status();
	if (!(zephir_is_true(&_5))) {
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("postCache", 9, 1);
	}

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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 905, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getPostData", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 905, &_0);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 905, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getHelper", &_zephir_call_cache[1], &_2, &name_zv, filters, defaultValue, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets information about the port on which the request is made.
 */
PHP_METHOD(Phalcon_Http_Request, getPort)
{
	zval host, pos, _0, _7, _8, _1$$3, _2$$3, _3$$4, _4$$5, _5$$5, _6$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_HOST");
	ZEPHIR_CALL_METHOD_CACHED(&host, this_ptr, "getServer", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&host))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "SERVER_PORT");
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "getServer", &_zephir_call_cache[1], &_2$$3);
		zephir_check_call_status();
		RETURN_MM_LONG(zephir_get_intval(&_1$$3));
	}
	if (zephir_memnstr_str(&host, SL(":"), "phalcon/Http/Request.zep", 783)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, ":");
		ZEPHIR_CALL_FUNCTION(&pos, "strrpos", NULL, 131, &host, &_3$$4);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_LONG(&_4$$5, 1);
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_add_function(&_5$$5, &pos, &_4$$5);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_6$$5);
			zephir_substr(&_6$$5, &host, zephir_get_intval(&_5$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			RETURN_MM_LONG(zephir_get_intval(&_6$$5));
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_CALL_METHOD_CACHED(&_7, this_ptr, "getScheme", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "https");
	if (ZEPHIR_IS_IDENTICAL(&_8, &_7)) {
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("postCache", 9, 1);
	}

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
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getPostData", &_zephir_call_cache[0], &_POST);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 905, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 905, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getHelper", &_zephir_call_cache[1], &_1, &name_zv, filters, defaultValue, &_2, &_3);
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
 * Note: This method relies on the `$_SERVER["HTTP_ACCEPT_LANGUAGE"]`
 * header.
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&language, this_ptr, "getBestLanguage", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_explode_str(&_0, SL("-"), &language, NULL);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&language, &_0);
	zephir_memory_observe(&_1);
	zephir_array_fetch_long(&_1, &language, 0, PH_NOISY, "phalcon/Http/Request.zep", 843);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
 * Gets a variable from put request
 *
 *```php
 * // Returns value from $_PUT["user_email"] without sanitizing
 * $userEmail = $request->getPut("user_email");
 *
 * // Returns value from $_PUT["user_email"] with sanitizing
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("postCache", 9, 1);
	}

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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 905, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getPostData", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 905, &_0);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 905, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getHelper", &_zephir_call_cache[1], &_2, &name_zv, filters, defaultValue, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets variable from $_GET superglobal applying filters if needed.
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getHelper", &_zephir_call_cache[0], &_GET, &name_zv, filters, defaultValue, &_0, &_1);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawBody);
	ZVAL_UNDEF(&contents);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("rawBody", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 906, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&rawBody, &_0);
	if (ZEPHIR_IS_EMPTY(&rawBody)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "php://input");
		ZEPHIR_CALL_METHOD_CACHED(&contents, this_ptr, "phpFileGetContents", &_zephir_call_cache[0], &_1$$3);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 906, &contents);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTPS");
	ZEPHIR_CALL_METHOD_CACHED(&https, this_ptr, "getServer", &_zephir_call_cache[0], &_0);
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
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, _SERVER, serverValue, server;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&serverValue);
	ZVAL_UNDEF(&server);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CPY_WRT(&server, &_SERVER);
	zephir_memory_observe(&serverValue);
	_0 = zephir_array_isset_fetch(&serverValue, &server, &name_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&serverValue);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "SERVER_ADDR");
	ZEPHIR_CALL_METHOD_CACHED(&serverAddr, this_ptr, "getServer", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&serverAddr) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "localhost");
		ZEPHIR_RETURN_CALL_FUNCTION("gethostbyname", NULL, 169, &_1$$3);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "SERVER_NAME");
	ZEPHIR_CALL_METHOD_CACHED(&serverName, this_ptr, "getServer", &_zephir_call_cache[0], &_0);
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
 *
 * @return FileInterface[]
 */
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles)
{
	zend_string *_4$$3;
	zend_ulong _3$$3;
	zval files;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *onlySuccessful_param = NULL, *namedKeys_param = NULL, _FILES, superFiles, prefix, input, smoothInput, file, dataFile, *_0$$3, _1$$3, *_2$$3, _5$$4, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, *_11$$5, _12$$5, *_13$$5, _19$$5, _15$$6, _16$$7, _17$$7, _18$$7, _22$$8, _23$$9, _24$$9, _25$$9, _26$$9, _28$$10, _29$$11, _30$$11;
	zend_bool onlySuccessful, namedKeys, _20$$5, _14$$6, _21$$8, _27$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&superFiles);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&smoothInput);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&dataFile);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&files);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
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
	if (!(ZEPHIR_IS_EMPTY(&superFiles))) {
		if (Z_TYPE_P(&superFiles) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_string_to_char_array(&_1$$3, &superFiles);
			_0$$3 = &_1$$3;
		} else {
			_0$$3 = &superFiles;
		}
		zephir_is_iterable(_0$$3, 0, "phalcon/Http/Request.zep", 1049);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_0$$3), _3$$3, _4$$3, _2$$3)
		{
			ZEPHIR_INIT_NVAR(&prefix);
			if (_4$$3 != NULL) { 
				ZVAL_STR_COPY(&prefix, _4$$3);
			} else {
				ZVAL_LONG(&prefix, _3$$3);
			}
			ZEPHIR_INIT_NVAR(&input);
			ZVAL_COPY(&input, _2$$3);
			ZEPHIR_OBS_NVAR(&_5$$4);
			zephir_array_fetch_string(&_5$$4, &input, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 1010);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&_5$$4) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&_6$$5);
				zephir_array_fetch_string(&_6$$5, &input, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 1012);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_7$$5);
				zephir_array_fetch_string(&_7$$5, &input, SL("type"), PH_NOISY, "phalcon/Http/Request.zep", 1013);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_8$$5);
				zephir_array_fetch_string(&_8$$5, &input, SL("tmp_name"), PH_NOISY, "phalcon/Http/Request.zep", 1014);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_9$$5);
				zephir_array_fetch_string(&_9$$5, &input, SL("size"), PH_NOISY, "phalcon/Http/Request.zep", 1015);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_10$$5);
				zephir_array_fetch_string(&_10$$5, &input, SL("error"), PH_NOISY, "phalcon/Http/Request.zep", 1016);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&smoothInput, this_ptr, "smoothFiles", &_zephir_call_cache[0], &_6$$5, &_7$$5, &_8$$5, &_9$$5, &_10$$5, &prefix);
				zephir_check_call_status();
				if (Z_TYPE_P(&smoothInput) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_12$$5);
					zephir_string_to_char_array(&_12$$5, &smoothInput);
					_11$$5 = &_12$$5;
				} else {
					_11$$5 = &smoothInput;
				}
				zephir_is_iterable(_11$$5, 0, "phalcon/Http/Request.zep", 1038);
				if (Z_TYPE_P(_11$$5) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_11$$5), _13$$5)
					{
						ZEPHIR_INIT_NVAR(&file);
						ZVAL_COPY(&file, _13$$5);
						_14$$6 = onlySuccessful == 0;
						if (!(_14$$6)) {
							ZEPHIR_OBS_NVAR(&_15$$6);
							zephir_array_fetch_string(&_15$$6, &file, SL("error"), PH_NOISY, "phalcon/Http/Request.zep", 1021);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_14$$6 = ZEPHIR_IS_LONG(&_15$$6, 0);
						}
						if (_14$$6) {
							ZEPHIR_INIT_NVAR(&dataFile);
							zephir_create_array(&dataFile, 5, 0);
							ZEPHIR_OBS_NVAR(&_16$$7);
							zephir_array_fetch_string(&_16$$7, &file, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 1023);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_string(&dataFile, SL("name"), &_16$$7, PH_COPY | PH_SEPARATE);
							ZEPHIR_OBS_NVAR(&_16$$7);
							zephir_array_fetch_string(&_16$$7, &file, SL("type"), PH_NOISY, "phalcon/Http/Request.zep", 1024);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_string(&dataFile, SL("type"), &_16$$7, PH_COPY | PH_SEPARATE);
							ZEPHIR_OBS_NVAR(&_16$$7);
							zephir_array_fetch_string(&_16$$7, &file, SL("tmp_name"), PH_NOISY, "phalcon/Http/Request.zep", 1025);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_string(&dataFile, SL("tmp_name"), &_16$$7, PH_COPY | PH_SEPARATE);
							ZEPHIR_OBS_NVAR(&_16$$7);
							zephir_array_fetch_string(&_16$$7, &file, SL("size"), PH_NOISY, "phalcon/Http/Request.zep", 1026);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_string(&dataFile, SL("size"), &_16$$7, PH_COPY | PH_SEPARATE);
							ZEPHIR_OBS_NVAR(&_16$$7);
							zephir_array_fetch_string(&_16$$7, &file, SL("error"), PH_NOISY, "phalcon/Http/Request.zep", 1028);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_string(&dataFile, SL("error"), &_16$$7, PH_COPY | PH_SEPARATE);
							ZEPHIR_OBS_NVAR(&_16$$7);
							zephir_array_fetch_string(&_16$$7, &file, SL("key"), PH_NOISY, "phalcon/Http/Request.zep", 1035);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (namedKeys) {
								ZVAL_BOOL(&_18$$7, 1);
							} else {
								ZVAL_BOOL(&_18$$7, 0);
							}
							ZEPHIR_CALL_METHOD_CACHED(&_17$$7, this_ptr, "processFiles", &_zephir_call_cache[1], &files, &_18$$7, &dataFile, &_16$$7);
							zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&_17$$7) != IS_ARRAY)) {
								zephir_throw_variable_type_error(&_17$$7, "files", "array");
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CPY_WRT(&files, &_17$$7);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _11$$5, "rewind", &_zephir_call_cache[2]);
					zephir_check_call_status();
					_20$$5 = 1;
					while (1) {
						if (_20$$5) {
							_20$$5 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _11$$5, "next", &_zephir_call_cache[3]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_19$$5, _11$$5, "valid", &_zephir_call_cache[4]);
						zephir_check_call_status();
						if (!zend_is_true(&_19$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&file, _11$$5, "current", &_zephir_call_cache[5]);
						zephir_check_call_status();
							_21$$8 = onlySuccessful == 0;
							if (!(_21$$8)) {
								ZEPHIR_OBS_NVAR(&_22$$8);
								zephir_array_fetch_string(&_22$$8, &file, SL("error"), PH_NOISY, "phalcon/Http/Request.zep", 1021);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								_21$$8 = ZEPHIR_IS_LONG(&_22$$8, 0);
							}
							if (_21$$8) {
								ZEPHIR_INIT_NVAR(&_23$$9);
								zephir_create_array(&_23$$9, 5, 0);
								ZEPHIR_OBS_NVAR(&_24$$9);
								zephir_array_fetch_string(&_24$$9, &file, SL("name"), PH_NOISY, "phalcon/Http/Request.zep", 1023);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_string(&_23$$9, SL("name"), &_24$$9, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_24$$9);
								zephir_array_fetch_string(&_24$$9, &file, SL("type"), PH_NOISY, "phalcon/Http/Request.zep", 1024);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_string(&_23$$9, SL("type"), &_24$$9, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_24$$9);
								zephir_array_fetch_string(&_24$$9, &file, SL("tmp_name"), PH_NOISY, "phalcon/Http/Request.zep", 1025);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_string(&_23$$9, SL("tmp_name"), &_24$$9, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_24$$9);
								zephir_array_fetch_string(&_24$$9, &file, SL("size"), PH_NOISY, "phalcon/Http/Request.zep", 1026);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_string(&_23$$9, SL("size"), &_24$$9, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_24$$9);
								zephir_array_fetch_string(&_24$$9, &file, SL("error"), PH_NOISY, "phalcon/Http/Request.zep", 1028);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_string(&_23$$9, SL("error"), &_24$$9, PH_COPY | PH_SEPARATE);
								ZEPHIR_CPY_WRT(&dataFile, &_23$$9);
								ZEPHIR_OBS_NVAR(&_24$$9);
								zephir_array_fetch_string(&_24$$9, &file, SL("key"), PH_NOISY, "phalcon/Http/Request.zep", 1035);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (namedKeys) {
									ZVAL_BOOL(&_26$$9, 1);
								} else {
									ZVAL_BOOL(&_26$$9, 0);
								}
								ZEPHIR_CALL_METHOD_CACHED(&_25$$9, this_ptr, "processFiles", &_zephir_call_cache[6], &files, &_26$$9, &dataFile, &_24$$9);
								zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&_25$$9) != IS_ARRAY)) {
									zephir_throw_variable_type_error(&_25$$9, "files", "array");
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CPY_WRT(&files, &_25$$9);
							}
					}
				}
				ZEPHIR_INIT_NVAR(&file);
			} else {
				_27$$10 = onlySuccessful == 0;
				if (!(_27$$10)) {
					ZEPHIR_OBS_NVAR(&_28$$10);
					zephir_array_fetch_string(&_28$$10, &input, SL("error"), PH_NOISY, "phalcon/Http/Request.zep", 1039);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_27$$10 = ZEPHIR_IS_LONG(&_28$$10, 0);
				}
				if (_27$$10) {
					if (namedKeys) {
						ZVAL_BOOL(&_30$$11, 1);
					} else {
						ZVAL_BOOL(&_30$$11, 0);
					}
					ZEPHIR_CALL_METHOD_CACHED(&_29$$11, this_ptr, "processFiles", &_zephir_call_cache[7], &files, &_30$$11, &input, &prefix);
					zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&_29$$11) != IS_ARRAY)) {
						zephir_throw_variable_type_error(&_29$$11, "files", "array");
						ZEPHIR_MM_RESTORE();
						return;
					}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_CALL_METHOD_CACHED(&requestURI, this_ptr, "getServer", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&requestURI) == IS_NULL) {
		RETURN_MM_STRING("");
	}
	if (onlyPath) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "?");
		zephir_fast_explode(&_1$$4, &_2$$4, &requestURI, NULL);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_3$$4);
		zephir_array_fetch_long(&_3$$4, &_1$$4, 0, PH_NOISY, "phalcon/Http/Request.zep", 1075);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&requestURI, &_3$$4);
	}
	RETURN_CCTOR(&requestURI);
}

/**
 * Gets HTTP user agent used to make the request
 */
PHP_METHOD(Phalcon_Http_Request, getUserAgent)
{
	zval userAgent, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&userAgent);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_USER_AGENT");
	ZEPHIR_CALL_METHOD_CACHED(&userAgent, this_ptr, "getServer", &_zephir_call_cache[0], &_0);
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
	zend_bool _0;
	zval name_zv, _REQUEST;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_REQUEST);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	ZVAL_STR(&name_zv, name);
	_0 = zephir_array_key_exists(&_REQUEST, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(_0);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "numFiles", &_zephir_call_cache[0], &_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 1, &header_zv, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	zephir_fast_strtoupper(&name, &_2);
	ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "hasServer", &_zephir_call_cache[0], &name);
	zephir_check_call_status();
	_4 = zephir_is_true(&_3);
	if (!(_4)) {
		ZEPHIR_INIT_VAR(&_6);
		ZEPHIR_CONCAT_SV(&_6, "HTTP_", &name);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_5, this_ptr, "hasServer", &_zephir_call_cache[1], &_6);
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
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, patch;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&patch);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD_CACHED(&patch, this_ptr, "getPatch", &_zephir_call_cache[0]);
	zephir_check_call_status();
	_0 = zephir_array_key_exists(&patch, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(_0);
}

/**
 * Checks whether $_POST superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPost)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, post;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&post);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD_CACHED(&post, this_ptr, "getPost", &_zephir_call_cache[0]);
	zephir_check_call_status();
	_0 = zephir_array_key_exists(&post, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(_0);
}

/**
 * Checks whether the PUT data has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPut)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, put;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&put);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD_CACHED(&put, this_ptr, "getPut", &_zephir_call_cache[0]);
	zephir_check_call_status();
	_0 = zephir_array_key_exists(&put, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(_0);
}

/**
 * Checks whether $_GET superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasQuery)
{
	zend_bool _0;
	zval name_zv, _GET;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_GET);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_get_global(&_GET, SL("_GET"));
	ZVAL_STR(&name_zv, name);
	_0 = zephir_array_key_exists(&_GET, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(_0);
}

/**
 * Checks whether $_SERVER superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasServer)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, _SERVER, server;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&server);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CPY_WRT(&server, &_SERVER);
	_0 = zephir_array_key_exists(&server, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(_0);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HTTP_X_REQUESTED_WITH");
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "hasServer", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	_2 = zephir_is_true(&_0);
	if (_2) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "HTTP_X_REQUESTED_WITH");
		ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "getServer", &_zephir_call_cache[1], &_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getMethod", &_zephir_call_cache[0]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getMethod", &_zephir_call_cache[0]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getMethod", &_zephir_call_cache[0]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getMethod", &_zephir_call_cache[0]);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "HEAD"));
}

/**
 * Checks whether request content type contains json data
 */
PHP_METHOD(Phalcon_Http_Request, isJson)
{
	zval _4;
	zend_bool _2;
	zval _0, _1, _3, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "CONTENT_TYPE");
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "hasServer", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	_2 = zephir_is_true(&_0);
	if (_2) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "CONTENT_TYPE");
		ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "getServer", &_zephir_call_cache[1], &_1);
		zephir_check_call_status();
		zephir_cast_to_string(&_4, &_3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "json");
		ZEPHIR_CALL_FUNCTION(&_5, "stripos", NULL, 170, &_4, &_1);
		zephir_check_call_status();
		_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_5);
	}
	RETURN_MM_BOOL(_2);
}

/**
 * Check if HTTP method match any of the passed methods
 * When strict is true it checks if validated methods are real HTTP methods
 *
 * @todo check the $methods type - refactor this !!
 *
 * @param mixed $methods
 */
PHP_METHOD(Phalcon_Http_Request, isMethod)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool strict, _0$$3, _3$$3, _10$$5;
	zval *methods, methods_sub, *strict_param = NULL, httpMethod, method, _1$$3, _2$$4, *_4$$5, _5$$5, *_6$$5, _9$$5, _7$$6, _8$$6, _11$$8, _12$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&methods_sub);
	ZVAL_UNDEF(&httpMethod);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
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
	ZEPHIR_CALL_METHOD_CACHED(&httpMethod, this_ptr, "getMethod", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (Z_TYPE_P(methods) == IS_STRING) {
		_0$$3 = strict;
		if (_0$$3) {
			ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "isValidHttpMethod", &_zephir_call_cache[1], methods);
			zephir_check_call_status();
			_0$$3 = !zephir_is_true(&_1$$3);
		}
		if (UNEXPECTED(_0$$3)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_http_request_exceptions_invalidhttpmethod_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$4, "__construct", &_zephir_call_cache[2], methods);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "phalcon/Http/Request.zep", 1250);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_3$$3 = ZEPHIR_IS_EQUAL(methods, &httpMethod);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(_3$$3);
	}
	if (Z_TYPE_P(methods) == IS_ARRAY) {
		if (Z_TYPE_P(methods) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_string_to_char_array(&_5$$5, methods);
			_4$$5 = &_5$$5;
		} else {
			_4$$5 = methods;
		}
		zephir_is_iterable(_4$$5, 0, "phalcon/Http/Request.zep", 1263);
		if (Z_TYPE_P(_4$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4$$5), _6$$5)
			{
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _6$$5);
				if (strict) {
					ZVAL_BOOL(&_8$$6, 1);
				} else {
					ZVAL_BOOL(&_8$$6, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_7$$6, this_ptr, "isMethod", &_zephir_call_cache[3], &method, &_8$$6);
				zephir_check_call_status();
				if (zephir_is_true(&_7$$6)) {
					RETURN_MM_BOOL(1);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$5, "rewind", &_zephir_call_cache[4]);
			zephir_check_call_status();
			_10$$5 = 1;
			while (1) {
				if (_10$$5) {
					_10$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$5, "next", &_zephir_call_cache[5]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_9$$5, _4$$5, "valid", &_zephir_call_cache[6]);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&method, _4$$5, "current", &_zephir_call_cache[7]);
				zephir_check_call_status();
					if (strict) {
						ZVAL_BOOL(&_12$$8, 1);
					} else {
						ZVAL_BOOL(&_12$$8, 0);
					}
					ZEPHIR_CALL_METHOD_CACHED(&_11$$8, this_ptr, "isMethod", &_zephir_call_cache[8], &method, &_12$$8);
					zephir_check_call_status();
					if (zephir_is_true(&_11$$8)) {
						RETURN_MM_BOOL(1);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&method);
		RETURN_MM_BOOL(0);
	}
	if (UNEXPECTED(strict)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exceptions_invalidhttpmethod_ce, "non-string", "phalcon/Http/Request.zep", 1267);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getMethod", &_zephir_call_cache[0]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getMethod", &_zephir_call_cache[0]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getMethod", &_zephir_call_cache[0]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getMethod", &_zephir_call_cache[0]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getMethod", &_zephir_call_cache[0]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getScheme", &_zephir_call_cache[0]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HTTP_SOAPACTION");
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "hasServer", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD_CACHED(&contentType, this_ptr, "getContentType", &_zephir_call_cache[1]);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&contentType)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(zephir_memnstr_str(&contentType, SL("application/soap+xml"), "phalcon/Http/Request.zep", 1343));
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getMethod", &_zephir_call_cache[0]);
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
	if (ZEPHIR_IS_STRING(&_0, "CONNECT")) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_STRING(&_0, "DELETE")) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_STRING(&_0, "GET")) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_STRING(&_0, "HEAD")) { goto zephir_switch_0_clause_3; }
	if (ZEPHIR_IS_STRING(&_0, "OPTIONS")) { goto zephir_switch_0_clause_4; }
	if (ZEPHIR_IS_STRING(&_0, "PATCH")) { goto zephir_switch_0_clause_5; }
	if (ZEPHIR_IS_STRING(&_0, "POST")) { goto zephir_switch_0_clause_6; }
	if (ZEPHIR_IS_STRING(&_0, "PURGE")) { goto zephir_switch_0_clause_7; }
	if (ZEPHIR_IS_STRING(&_0, "PUT")) { goto zephir_switch_0_clause_8; }
	if (ZEPHIR_IS_STRING(&_0, "TRACE")) { goto zephir_switch_0_clause_9; }
	goto zephir_switch_0_end;
	zephir_switch_0_clause_0: ;
	zephir_switch_0_clause_1: ;
	zephir_switch_0_clause_2: ;
	zephir_switch_0_clause_3: ;
	zephir_switch_0_clause_4: ;
	zephir_switch_0_clause_5: ;
	zephir_switch_0_clause_6: ;
	zephir_switch_0_clause_7: ;
	zephir_switch_0_clause_8: ;
	zephir_switch_0_clause_9: ;
		RETURN_MM_BOOL(1);
	zephir_switch_0_end: ;

	RETURN_MM_BOOL(0);
}

/**
 * Returns the number of files available
 */
PHP_METHOD(Phalcon_Http_Request, numFiles)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zval *onlySuccessful_param = NULL, _FILES, files, file, error, *_0, _1, *_2, _5$$8, _6$$8;
	zend_bool onlySuccessful, _3$$4, _4$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (Z_TYPE_P(&files) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_string_to_char_array(&_1, &files);
		_0 = &_1;
	} else {
		_0 = &files;
	}
	zephir_is_iterable(_0, 0, "phalcon/Http/Request.zep", 1417);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0), _2)
	{
		ZEPHIR_INIT_NVAR(&file);
		ZVAL_COPY(&file, _2);
		ZEPHIR_OBS_NVAR(&error);
		_3$$4 = zephir_array_isset_string_fetch(&error, &file, SL("error"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_3$$4) {
			if (Z_TYPE_P(&error) != IS_ARRAY) {
				_4$$6 = !zephir_is_true(&error);
				if (!(_4$$6)) {
					_4$$6 = !onlySuccessful;
				}
				if (_4$$6) {
					numberFiles++;
				}
			}
			if (Z_TYPE_P(&error) == IS_ARRAY) {
				if (onlySuccessful) {
					ZVAL_BOOL(&_6$$8, 1);
				} else {
					ZVAL_BOOL(&_6$$8, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_5$$8, this_ptr, "hasFileHelper", &_zephir_call_cache[0], &error, &_6$$8);
				zephir_check_call_status();
				numberFiles += zephir_get_numberval(&_5$$8);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&file);
	RETURN_MM_LONG(numberFiles);
}

/**
 * Set the HTTP method parameter override flag
 */
PHP_METHOD(Phalcon_Http_Request, setHttpMethodParameterOverride)
{
	zval *override_param = NULL, __$true, __$false;
	zend_bool override;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("methodOverride", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(override)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &override_param);
	if (override) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 904, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 904, &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets automatic sanitizers/filters for a particular field and for
 * particular methods
 *
 * @phpstan-param list<string> $filters
 * @phpstan-param list<string> $scope
 */
PHP_METHOD(Phalcon_Http_Request, setParameterFilters)
{
	zend_bool _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filters, scope;
	zval name_zv, *filters_param = NULL, *scope_param = NULL, filterService, sanitizer, localScope, scopeMethod, *_1, _4, *_9, _10, *_11, _0$$3, _2$$4, _3$$5, _6$$6, _7$$7, _8$$8, _12$$10;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&sanitizer);
	ZVAL_UNDEF(&localScope);
	ZVAL_UNDEF(&scopeMethod);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&scope);
	ZEND_TLS zephir_method_cache _zephir_call_cache[10];
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
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&filters))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_http_request_exceptions_missingfilters_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[0], &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Http/Request.zep", 1445);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&filterService, this_ptr, "getFilterService", &_zephir_call_cache[1]);
	zephir_check_call_status();
	zephir_is_iterable(&filters, 0, "phalcon/Http/Request.zep", 1456);
	if (Z_TYPE_P(&filters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&filters), _1)
		{
			ZEPHIR_INIT_NVAR(&sanitizer);
			ZVAL_COPY(&sanitizer, _1);
			ZEPHIR_CALL_METHOD_CACHED(&_2$$4, &filterService, "has", &_zephir_call_cache[2], &sanitizer);
			zephir_check_call_status();
			if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_2$$4))) {
				ZEPHIR_INIT_NVAR(&_3$$5);
				object_init_ex(&_3$$5, phalcon_http_request_exceptions_sanitizernotfound_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$5, "__construct", &_zephir_call_cache[3], &sanitizer);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$5, "phalcon/Http/Request.zep", 1452);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &filters, "rewind", &_zephir_call_cache[4]);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &filters, "next", &_zephir_call_cache[5]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_4, &filters, "valid", &_zephir_call_cache[6]);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&sanitizer, &filters, "current", &_zephir_call_cache[7]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_6$$6, &filterService, "has", &_zephir_call_cache[8], &sanitizer);
				zephir_check_call_status();
				if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_6$$6))) {
					ZEPHIR_INIT_NVAR(&_7$$7);
					object_init_ex(&_7$$7, phalcon_http_request_exceptions_sanitizernotfound_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_7$$7, "__construct", &_zephir_call_cache[9], &sanitizer);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_7$$7, "phalcon/Http/Request.zep", 1452);
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&sanitizer);
	if (ZEPHIR_IS_EMPTY(&scope)) {
		ZEPHIR_INIT_VAR(&localScope);
		zephir_create_array(&localScope, 4, 0);
		ZEPHIR_INIT_VAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "GET");
		zephir_array_fast_append(&localScope, &_8$$8);
		ZEPHIR_INIT_NVAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "PATCH");
		zephir_array_fast_append(&localScope, &_8$$8);
		ZEPHIR_INIT_NVAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "POST");
		zephir_array_fast_append(&localScope, &_8$$8);
		ZEPHIR_INIT_NVAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "PUT");
		zephir_array_fast_append(&localScope, &_8$$8);
	} else {
		ZEPHIR_CPY_WRT(&localScope, &scope);
	}
	if (Z_TYPE_P(&localScope) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_10);
		zephir_string_to_char_array(&_10, &localScope);
		_9 = &_10;
	} else {
		_9 = &localScope;
	}
	zephir_is_iterable(_9, 0, "phalcon/Http/Request.zep", 1471);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9), _11)
	{
		ZEPHIR_INIT_NVAR(&scopeMethod);
		ZVAL_COPY(&scopeMethod, _11);
		ZEPHIR_INIT_NVAR(&_12$$10);
		zephir_fast_strtoupper(&_12$$10, &scopeMethod);
		zephir_update_property_array_multi(this_ptr, SL("queryFilters"), &filters, SL("zz"), 2, &_12$$10, &name_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("strictHostCheck", 15, 1);
	}

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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 903, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 903, &__$false);
	}
	RETURN_THISW();
}

/**
 * Set a trusted proxy list for X-Forwarded-For header
 *
 * @phpstan-param list<string> $trustedProxies
 */
PHP_METHOD(Phalcon_Http_Request, setTrustedProxies)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *trustedProxies_param = NULL, filterService, trustedProxy, filtered, *_0, _2, _1$$3, _4$$5;
	zval trustedProxies;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&trustedProxies);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&trustedProxy);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(trustedProxies, trustedProxies_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &trustedProxies_param);
	zephir_get_arrval(&trustedProxies, trustedProxies_param);
	ZEPHIR_CALL_METHOD_CACHED(&filterService, this_ptr, "getFilterService", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_is_iterable(&trustedProxies, 0, "phalcon/Http/Request.zep", 1504);
	if (Z_TYPE_P(&trustedProxies) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&trustedProxies), _0)
		{
			ZEPHIR_INIT_NVAR(&trustedProxy);
			ZVAL_COPY(&trustedProxy, _0);
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "ip");
			ZEPHIR_CALL_METHOD_CACHED(&filtered, &filterService, "sanitize", &_zephir_call_cache[1], &trustedProxy, &_1$$3);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&filtered)) {
				zephir_update_property_array_append(this_ptr, SL("trustedProxies"), &filtered);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &trustedProxies, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_3 = 1;
		while (1) {
			if (_3) {
				_3 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &trustedProxies, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_2, &trustedProxies, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&trustedProxy, &trustedProxies, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_4$$5);
				ZVAL_STRING(&_4$$5, "ip");
				ZEPHIR_CALL_METHOD_CACHED(&filtered, &filterService, "sanitize", &_zephir_call_cache[6], &trustedProxy, &_4$$5);
				zephir_check_call_status();
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&filtered)) {
					zephir_update_property_array_append(this_ptr, SL("trustedProxies"), &filtered);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&trustedProxy);
	RETURN_THIS();
}

/**
 * This header takes priority when parsing HTTP headers
 * The header return only 1 single IP address, prefixed with HTTP_ eg. HTTP_CLIENT_IP.
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("trustedProxyHeader", 18, 1);
	}

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
	ZEPHIR_CALL_FUNCTION(&_4, "str_starts_with", NULL, 171, &trustedHeader, &_3);
	zephir_check_call_status();
	if (!zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_SV(&_5$$3, "HTTP_", &trustedHeader);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&trustedHeader, &_5$$3);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 901, &trustedHeader);
	RETURN_THIS();
}

/**
 * Process a request header and return the one with best quality
 *
 * @phpstan-param list<http_quality_part> $qualityParts
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
	zephir_is_iterable(&qualityParts, 0, "phalcon/Http/Request.zep", 1556);
	if (Z_TYPE_P(&qualityParts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&qualityParts), _0)
		{
			ZEPHIR_INIT_NVAR(&accept);
			ZVAL_COPY(&accept, _0);
			if (i == 0) {
				ZEPHIR_OBS_NVAR(&_1$$4);
				zephir_array_fetch_string(&_1$$4, &accept, SL("quality"), PH_NOISY, "phalcon/Http/Request.zep", 1542);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				quality =  (zephir_get_doubleval(&_1$$4));
				ZEPHIR_OBS_NVAR(&selectedName);
				zephir_array_fetch(&selectedName, &accept, &name_zv, PH_NOISY, "phalcon/Http/Request.zep", 1543);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_OBS_NVAR(&_2$$5);
				zephir_array_fetch_string(&_2$$5, &accept, SL("quality"), PH_NOISY, "phalcon/Http/Request.zep", 1545);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				acceptQuality =  (zephir_get_doubleval(&_2$$5));
				if (acceptQuality > quality) {
					quality =  acceptQuality;
					ZEPHIR_OBS_NVAR(&selectedName);
					zephir_array_fetch(&selectedName, &accept, &name_zv, PH_NOISY, "phalcon/Http/Request.zep", 1549);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			i++;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &qualityParts, "rewind", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &qualityParts, "next", &_zephir_call_cache[1]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_3, &qualityParts, "valid", &_zephir_call_cache[2]);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&accept, &qualityParts, "current", &_zephir_call_cache[3]);
			zephir_check_call_status();
				if (i == 0) {
					ZEPHIR_OBS_NVAR(&_5$$8);
					zephir_array_fetch_string(&_5$$8, &accept, SL("quality"), PH_NOISY, "phalcon/Http/Request.zep", 1542);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					quality =  (zephir_get_doubleval(&_5$$8));
					ZEPHIR_OBS_NVAR(&selectedName);
					zephir_array_fetch(&selectedName, &accept, &name_zv, PH_NOISY, "phalcon/Http/Request.zep", 1543);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_OBS_NVAR(&_6$$9);
					zephir_array_fetch_string(&_6$$9, &accept, SL("quality"), PH_NOISY, "phalcon/Http/Request.zep", 1545);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					acceptQuality =  (zephir_get_doubleval(&_6$$9));
					if (acceptQuality > quality) {
						quality =  acceptQuality;
						ZEPHIR_OBS_NVAR(&selectedName);
						zephir_array_fetch(&selectedName, &accept, &name_zv, PH_NOISY, "phalcon/Http/Request.zep", 1549);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
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
 *
 * @phpstan-param http_form_data $source
 */
PHP_METHOD(Phalcon_Http_Request, getHelper)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive, _0, _1, _2;
	zend_string *name = NULL;
	zval *source_param = NULL, name_zv, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, value, filterService, _3$$6, _4$$6;
	zval source;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	if (Z_TYPE_P(&name_zv) == IS_NULL) {
		RETURN_CTOR(&source);
	}
	zephir_memory_observe(&value);
	_0 = zephir_array_isset_fetch(&value, &source, &name_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	_1 = !(zephir_is_numeric(&value));
	if (_1) {
		_1 = ZEPHIR_IS_EMPTY(&value);
	}
	_2 = _1;
	if (_2) {
		_2 = notAllowEmpty;
	}
	if (_2) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(filters) != IS_NULL) {
		ZEPHIR_CALL_METHOD_CACHED(&filterService, this_ptr, "getFilterService", &_zephir_call_cache[0]);
		zephir_check_call_status();
		if (noRecursive) {
			ZVAL_BOOL(&_4$$6, 1);
		} else {
			ZVAL_BOOL(&_4$$6, 0);
		}
		ZEPHIR_CALL_METHOD_CACHED(&_3$$6, &filterService, "sanitize", &_zephir_call_cache[1], &value, filters, &_4$$6);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&value, &_3$$6);
		if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
	}
	RETURN_CCTOR(&value);
}

/**
 * Process a request header and return an array of values with their
 * qualities
 *
 * @phpstan-return list<http_quality_part>
 */
PHP_METHOD(Phalcon_Http_Request, getQualityHeader)
{
	zend_bool _34, _23$$3, _51$$14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval serverIndex_zv, name_zv, headerPart, headerParts, headerSplit, part, parts, returnedParts, serverValue, split, _0, _1, _2, _3, *_5, *_6, _33, _7$$3, _8$$3, _9$$3, _10$$3, *_11$$3, *_12$$3, _22$$3, _13$$4, _14$$4, _15$$5, _16$$5, _17$$6, _18$$6, _19$$7, _20$$7, _21$$8, _24$$9, _25$$9, _26$$10, _27$$10, _28$$11, _29$$11, _30$$12, _31$$12, _32$$13, _35$$14, _36$$14, _37$$14, _38$$14, *_39$$14, *_40$$14, _50$$14, _41$$15, _42$$15, _43$$16, _44$$16, _45$$17, _46$$17, _47$$18, _48$$18, _49$$19, _52$$20, _53$$20, _54$$21, _55$$21, _56$$22, _57$$22, _58$$23, _59$$23, _60$$24;
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
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_36$$14);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_38$$14);
	ZVAL_UNDEF(&_50$$14);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_42$$15);
	ZVAL_UNDEF(&_43$$16);
	ZVAL_UNDEF(&_44$$16);
	ZVAL_UNDEF(&_45$$17);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_47$$18);
	ZVAL_UNDEF(&_48$$18);
	ZVAL_UNDEF(&_49$$19);
	ZVAL_UNDEF(&_52$$20);
	ZVAL_UNDEF(&_53$$20);
	ZVAL_UNDEF(&_54$$21);
	ZVAL_UNDEF(&_55$$21);
	ZVAL_UNDEF(&_56$$22);
	ZVAL_UNDEF(&_57$$22);
	ZVAL_UNDEF(&_58$$23);
	ZVAL_UNDEF(&_59$$23);
	ZVAL_UNDEF(&_60$$24);
	ZEND_TLS zephir_method_cache _zephir_call_cache[13];
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
	ZEPHIR_CALL_METHOD_CACHED(&serverValue, this_ptr, "getServer", &_zephir_call_cache[0], &serverIndex_zv);
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
	ZEPHIR_CALL_FUNCTION(&parts, "preg_split", &_4, 58, &_1, &serverValue, &_2, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&parts) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_1);
		zephir_string_to_char_array(&_1, &parts);
		_5 = &_1;
	} else {
		_5 = &parts;
	}
	zephir_is_iterable(_5, 0, "phalcon/Http/Request.zep", 1647);
	if (Z_TYPE_P(_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_5), _6)
		{
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _6);
			ZEPHIR_INIT_NVAR(&headerParts);
			array_init(&headerParts);
			ZEPHIR_INIT_NVAR(&_7$$3);
			zephir_fast_trim(&_7$$3, &part, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "/\\s*;\\s*/");
			ZVAL_LONG(&_9$$3, -1);
			ZVAL_LONG(&_10$$3, 1);
			ZEPHIR_CALL_FUNCTION(&headerSplit, "preg_split", &_4, 58, &_8$$3, &_7$$3, &_9$$3, &_10$$3);
			zephir_check_call_status();
			if (Z_TYPE_P(&headerSplit) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_8$$3);
				zephir_string_to_char_array(&_8$$3, &headerSplit);
				_11$$3 = &_8$$3;
			} else {
				_11$$3 = &headerSplit;
			}
			zephir_is_iterable(_11$$3, 0, "phalcon/Http/Request.zep", 1644);
			if (Z_TYPE_P(_11$$3) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_11$$3), _12$$3)
				{
					ZEPHIR_INIT_NVAR(&headerPart);
					ZVAL_COPY(&headerPart, _12$$3);
					ZEPHIR_INIT_NVAR(&_13$$4);
					ZVAL_STRING(&_13$$4, "=");
					ZEPHIR_INIT_NVAR(&_14$$4);
					zephir_fast_strpos(&_14$$4, &headerPart, &_13$$4, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_14$$4)) {
						ZVAL_LONG(&_15$$5, 2);
						ZEPHIR_INIT_NVAR(&split);
						zephir_fast_explode_str(&split, SL("="), &headerPart, &_15$$5);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&_16$$5);
						zephir_array_fetch_long(&_16$$5, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1633);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (ZEPHIR_IS_STRING_IDENTICAL(&_16$$5, "q")) {
							ZEPHIR_OBS_NVAR(&_17$$6);
							zephir_array_fetch_long(&_17$$6, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1634);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_18$$6);
							ZVAL_DOUBLE(&_18$$6, zephir_get_doubleval(&_17$$6));
							zephir_array_update_string(&headerParts, SL("quality"), &_18$$6, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_OBS_NVAR(&_19$$7);
							zephir_array_fetch_long(&_19$$7, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1636);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_20$$7);
							zephir_array_fetch_long(&_20$$7, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1636);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&headerParts, &_19$$7, &_20$$7, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						zephir_array_update_zval(&headerParts, &name_zv, &headerPart, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_21$$8);
						ZVAL_DOUBLE(&_21$$8, 1.0);
						zephir_array_update_string(&headerParts, SL("quality"), &_21$$8, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _11$$3, "rewind", &_zephir_call_cache[1]);
				zephir_check_call_status();
				_23$$3 = 1;
				while (1) {
					if (_23$$3) {
						_23$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _11$$3, "next", &_zephir_call_cache[2]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_22$$3, _11$$3, "valid", &_zephir_call_cache[3]);
					zephir_check_call_status();
					if (!zend_is_true(&_22$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&headerPart, _11$$3, "current", &_zephir_call_cache[4]);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_24$$9);
						ZVAL_STRING(&_24$$9, "=");
						ZEPHIR_INIT_NVAR(&_25$$9);
						zephir_fast_strpos(&_25$$9, &headerPart, &_24$$9, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_25$$9)) {
							ZVAL_LONG(&_26$$10, 2);
							ZEPHIR_INIT_NVAR(&split);
							zephir_fast_explode_str(&split, SL("="), &headerPart, &_26$$10);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_27$$10);
							zephir_array_fetch_long(&_27$$10, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1633);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (ZEPHIR_IS_STRING_IDENTICAL(&_27$$10, "q")) {
								ZEPHIR_OBS_NVAR(&_28$$11);
								zephir_array_fetch_long(&_28$$11, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1634);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_29$$11);
								ZVAL_DOUBLE(&_29$$11, zephir_get_doubleval(&_28$$11));
								zephir_array_update_string(&headerParts, SL("quality"), &_29$$11, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_OBS_NVAR(&_30$$12);
								zephir_array_fetch_long(&_30$$12, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1636);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_31$$12);
								zephir_array_fetch_long(&_31$$12, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1636);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&headerParts, &_30$$12, &_31$$12, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						} else {
							zephir_array_update_zval(&headerParts, &name_zv, &headerPart, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_32$$13);
							ZVAL_DOUBLE(&_32$$13, 1.0);
							zephir_array_update_string(&headerParts, SL("quality"), &_32$$13, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
				}
			}
			ZEPHIR_INIT_NVAR(&headerPart);
			zephir_array_append(&returnedParts, &headerParts, PH_SEPARATE, "phalcon/Http/Request.zep", 1644);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "rewind", &_zephir_call_cache[5]);
		zephir_check_call_status();
		_34 = 1;
		while (1) {
			if (_34) {
				_34 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "next", &_zephir_call_cache[6]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_33, _5, "valid", &_zephir_call_cache[7]);
			zephir_check_call_status();
			if (!zend_is_true(&_33)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&part, _5, "current", &_zephir_call_cache[8]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&headerParts);
				array_init(&headerParts);
				ZEPHIR_INIT_NVAR(&_35$$14);
				zephir_fast_trim(&_35$$14, &part, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_INIT_NVAR(&_36$$14);
				ZVAL_STRING(&_36$$14, "/\\s*;\\s*/");
				ZVAL_LONG(&_37$$14, -1);
				ZVAL_LONG(&_38$$14, 1);
				ZEPHIR_CALL_FUNCTION(&headerSplit, "preg_split", &_4, 58, &_36$$14, &_35$$14, &_37$$14, &_38$$14);
				zephir_check_call_status();
				if (Z_TYPE_P(&headerSplit) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_36$$14);
					zephir_string_to_char_array(&_36$$14, &headerSplit);
					_39$$14 = &_36$$14;
				} else {
					_39$$14 = &headerSplit;
				}
				zephir_is_iterable(_39$$14, 0, "phalcon/Http/Request.zep", 1644);
				if (Z_TYPE_P(_39$$14) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_39$$14), _40$$14)
					{
						ZEPHIR_INIT_NVAR(&headerPart);
						ZVAL_COPY(&headerPart, _40$$14);
						ZEPHIR_INIT_NVAR(&_41$$15);
						ZVAL_STRING(&_41$$15, "=");
						ZEPHIR_INIT_NVAR(&_42$$15);
						zephir_fast_strpos(&_42$$15, &headerPart, &_41$$15, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_42$$15)) {
							ZVAL_LONG(&_43$$16, 2);
							ZEPHIR_INIT_NVAR(&split);
							zephir_fast_explode_str(&split, SL("="), &headerPart, &_43$$16);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_44$$16);
							zephir_array_fetch_long(&_44$$16, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1633);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (ZEPHIR_IS_STRING_IDENTICAL(&_44$$16, "q")) {
								ZEPHIR_OBS_NVAR(&_45$$17);
								zephir_array_fetch_long(&_45$$17, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1634);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_46$$17);
								ZVAL_DOUBLE(&_46$$17, zephir_get_doubleval(&_45$$17));
								zephir_array_update_string(&headerParts, SL("quality"), &_46$$17, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_OBS_NVAR(&_47$$18);
								zephir_array_fetch_long(&_47$$18, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1636);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_48$$18);
								zephir_array_fetch_long(&_48$$18, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1636);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&headerParts, &_47$$18, &_48$$18, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						} else {
							zephir_array_update_zval(&headerParts, &name_zv, &headerPart, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_49$$19);
							ZVAL_DOUBLE(&_49$$19, 1.0);
							zephir_array_update_string(&headerParts, SL("quality"), &_49$$19, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _39$$14, "rewind", &_zephir_call_cache[9]);
					zephir_check_call_status();
					_51$$14 = 1;
					while (1) {
						if (_51$$14) {
							_51$$14 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _39$$14, "next", &_zephir_call_cache[10]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_50$$14, _39$$14, "valid", &_zephir_call_cache[11]);
						zephir_check_call_status();
						if (!zend_is_true(&_50$$14)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&headerPart, _39$$14, "current", &_zephir_call_cache[12]);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_52$$20);
							ZVAL_STRING(&_52$$20, "=");
							ZEPHIR_INIT_NVAR(&_53$$20);
							zephir_fast_strpos(&_53$$20, &headerPart, &_52$$20, 0 );
							if (!ZEPHIR_IS_FALSE_IDENTICAL(&_53$$20)) {
								ZVAL_LONG(&_54$$21, 2);
								ZEPHIR_INIT_NVAR(&split);
								zephir_fast_explode_str(&split, SL("="), &headerPart, &_54$$21);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_55$$21);
								zephir_array_fetch_long(&_55$$21, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1633);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (ZEPHIR_IS_STRING_IDENTICAL(&_55$$21, "q")) {
									ZEPHIR_OBS_NVAR(&_56$$22);
									zephir_array_fetch_long(&_56$$22, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1634);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_INIT_NVAR(&_57$$22);
									ZVAL_DOUBLE(&_57$$22, zephir_get_doubleval(&_56$$22));
									zephir_array_update_string(&headerParts, SL("quality"), &_57$$22, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									ZEPHIR_OBS_NVAR(&_58$$23);
									zephir_array_fetch_long(&_58$$23, &split, 0, PH_NOISY, "phalcon/Http/Request.zep", 1636);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&_59$$23);
									zephir_array_fetch_long(&_59$$23, &split, 1, PH_NOISY, "phalcon/Http/Request.zep", 1636);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_zval(&headerParts, &_58$$23, &_59$$23, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							} else {
								zephir_array_update_zval(&headerParts, &name_zv, &headerPart, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_60$$24);
								ZVAL_DOUBLE(&_60$$24, 1.0);
								zephir_array_update_string(&headerParts, SL("quality"), &_60$$24, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
					}
				}
				ZEPHIR_INIT_NVAR(&headerPart);
				zephir_array_append(&returnedParts, &headerParts, PH_SEPARATE, "phalcon/Http/Request.zep", 1644);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
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
	zend_long ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zend_bool onlySuccessful, _7, _3$$5, _8$$9;
	zval *data, data_sub, *onlySuccessful_param = NULL, value, *_0, _1, *_2, _6, _4$$7, _5$$7, _9$$11, _10$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
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
	if (Z_TYPE_P(data) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_string_to_char_array(&_1, data);
		_0 = &_1;
	} else {
		_0 = data;
	}
	zephir_is_iterable(_0, 0, "phalcon/Http/Request.zep", 1674);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0), _2)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			if (Z_TYPE_P(&value) != IS_ARRAY) {
				_3$$5 = !zephir_is_true(&value);
				if (!(_3$$5)) {
					_3$$5 = !onlySuccessful;
				}
				if (_3$$5) {
					numberFiles++;
				}
			}
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				if (onlySuccessful) {
					ZVAL_BOOL(&_5$$7, 1);
				} else {
					ZVAL_BOOL(&_5$$7, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_4$$7, this_ptr, "hasFileHelper", &_zephir_call_cache[0], &value, &_5$$7);
				zephir_check_call_status();
				numberFiles += zephir_get_numberval(&_4$$7);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _0, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _0, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_6, _0, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&value, _0, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				if (Z_TYPE_P(&value) != IS_ARRAY) {
					_8$$9 = !zephir_is_true(&value);
					if (!(_8$$9)) {
						_8$$9 = !onlySuccessful;
					}
					if (_8$$9) {
						numberFiles++;
					}
				}
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					if (onlySuccessful) {
						ZVAL_BOOL(&_10$$11, 1);
					} else {
						ZVAL_BOOL(&_10$$11, 0);
					}
					ZEPHIR_CALL_METHOD_CACHED(&_9$$11, this_ptr, "hasFileHelper", &_zephir_call_cache[5], &value, &_10$$11);
					zephir_check_call_status();
					numberFiles += zephir_get_numberval(&_9$$11);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	RETURN_MM_LONG(numberFiles);
}

/**
 * Check if an IP address exists in CIDR range
 */
PHP_METHOD(Phalcon_Http_Request, isIpAddressInCIDR)
{
	zend_long _17;
	zend_bool _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, maskBytes = 0, remainingBits = 0, maskLength = 0;
	zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL, *_10 = NULL, *_11 = NULL, *_15 = NULL;
	zval ip_zv, cidr_zv, parts, mask, tempMask, subnet, ipBin, subnetBin, ipBits, subnetBits, ipByte, subnetByte, _0, _1, _5, _7, _8, _9, _12, _13, _14, _16, _18, _19, _20;
	zend_string *ip = NULL, *cidr = NULL;

	ZVAL_UNDEF(&ip_zv);
	ZVAL_UNDEF(&cidr_zv);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&mask);
	ZVAL_UNDEF(&tempMask);
	ZVAL_UNDEF(&subnet);
	ZVAL_UNDEF(&ipBin);
	ZVAL_UNDEF(&subnetBin);
	ZVAL_UNDEF(&ipBits);
	ZVAL_UNDEF(&subnetBits);
	ZVAL_UNDEF(&ipByte);
	ZVAL_UNDEF(&subnetByte);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
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
	zephir_fast_explode(&parts, &_0, &cidr_zv, NULL);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&subnet);
	zephir_array_fetch_long(&subnet, &parts, 0, PH_NOISY, "phalcon/Http/Request.zep", 1686);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_1);
	zephir_array_fetch_long(&_1, &parts, 1, PH_NOISY, "phalcon/Http/Request.zep", 1687);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	maskLength = zephir_get_intval(&_1);
	ZEPHIR_CALL_FUNCTION(&ipBin, "inet_pton", &_2, 172, &ip_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&subnetBin, "inet_pton", &_2, 172, &subnet);
	zephir_check_call_status();
	_3 = ZEPHIR_IS_FALSE_IDENTICAL(&ipBin);
	if (!(_3)) {
		_3 = ZEPHIR_IS_FALSE_IDENTICAL(&subnetBin);
	}
	_4 = _3;
	if (!(_4)) {
		_4 = zephir_fast_strlen_ev(&ipBin) != zephir_fast_strlen_ev(&subnetBin);
	}
	if (_4) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "H*");
	ZEPHIR_CALL_FUNCTION(&ipBits, "unpack", &_6, 120, &_5, &ipBin);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "H*");
	ZEPHIR_CALL_FUNCTION(&subnetBits, "unpack", &_6, 120, &_5, &subnetBin);
	zephir_check_call_status();
	zephir_memory_observe(&_7);
	zephir_array_fetch_long(&_7, &ipBits, 1, PH_NOISY, "phalcon/Http/Request.zep", 1699);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&ipBits, &_7);
	ZEPHIR_OBS_NVAR(&_7);
	zephir_array_fetch_long(&_7, &subnetBits, 1, PH_NOISY, "phalcon/Http/Request.zep", 1700);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&subnetBits, &_7);
	ZVAL_LONG(&_8, zephir_fast_strlen_ev(&ipBits));
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "0");
	ZEPHIR_CALL_FUNCTION(&_9, "str_pad", &_10, 27, &ipBits, &_8, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&ipBits, "hex2bin", &_11, 25, &_9);
	zephir_check_call_status();
	ZVAL_LONG(&_8, zephir_fast_strlen_ev(&subnetBits));
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "0");
	ZEPHIR_CALL_FUNCTION(&_12, "str_pad", &_10, 27, &subnetBits, &_8, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&subnetBits, "hex2bin", &_11, 25, &_12);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_13);
	zephir_div_long_long(&_13, maskLength, 8);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	maskBytes = (int) zephir_floor(&_13);
	remainingBits = zephir_safe_mod_long_long(maskLength, 8);
	ZVAL_LONG(&_8, maskBytes);
	ZEPHIR_CALL_FUNCTION(&_14, "strncmp", NULL, 106, &ipBits, &subnetBits, &_8);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_14, 0)) {
		RETURN_MM_BOOL(0);
	}
	if (remainingBits == 0) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_OBS_NVAR(&_7);
	zephir_array_fetch_long(&_7, &ipBits, maskBytes, PH_NOISY, "phalcon/Http/Request.zep", 1718);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&ipByte, "ord", &_15, 133, &_7);
	zephir_check_call_status();
	zephir_memory_observe(&_16);
	zephir_array_fetch_long(&_16, &subnetBits, maskBytes, PH_NOISY, "phalcon/Http/Request.zep", 1719);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&subnetByte, "ord", &_15, 133, &_16);
	zephir_check_call_status();
	_17 = zephir_safe_shift_left_long(1, ((8 - remainingBits)));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&tempMask);
	ZVAL_LONG(&tempMask, (_17 - 1));
	ZEPHIR_INIT_VAR(&_18);
	ZVAL_LONG(&_18, 0xFF);
	ZEPHIR_INIT_VAR(&mask);
	zephir_bitwise_xor_function(&mask, &tempMask, &_18);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_19);
	zephir_bitwise_and_function(&_19, &ipByte, &mask);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_20);
	zephir_bitwise_and_function(&_20, &subnetByte, &mask);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_19, &_20));
}

/**
 * Resolve authorization headers.
 *
 * @phpstan-return http_request_headers
 */
PHP_METHOD(Phalcon_Http_Request, resolveAuthorizationHeaders)
{
	zend_bool _4, _9, _31, _39, _22$$11, _32$$16, _33$$16;
	zval headers, _5$$5, _40$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _SERVER, container, digest, exploded, resolved, server, authHeader, eventsManager, hasEventsManager, _0, _8, _10, _1$$3, _2$$4, _3$$4, _6$$5, _7$$6, _11$$7, _12$$7, _13$$7, _14$$8, _15$$8, _16$$8, _17$$9, _18$$10, _19$$11, _20$$11, _21$$11, _23$$11, _24$$11, _25$$12, _26$$12, _27$$12, _28$$12, _29$$13, _30$$13, _34$$17, _35$$17, _36$$17, _37$$17, _38$$17, _41$$19, _42$$20;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&digest);
	ZVAL_UNDEF(&exploded);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&authHeader);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&hasEventsManager);
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
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_34$$17);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&_36$$17);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_41$$19);
	ZVAL_UNDEF(&_42$$20);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_40$$19);
	ZEND_TLS zephir_method_cache _zephir_call_cache[14];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&authHeader);
	ZVAL_NULL(&authHeader);
	ZEPHIR_INIT_VAR(&eventsManager);
	ZVAL_NULL(&eventsManager);
	ZEPHIR_INIT_VAR(&hasEventsManager);
	ZVAL_BOOL(&hasEventsManager, 0);
	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getDI", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&container, &_0);
	ZEPHIR_CPY_WRT(&server, &_SERVER);
	if (Z_TYPE_P(&container) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "eventsManager");
		ZEPHIR_CALL_METHOD_CACHED(&hasEventsManager, &container, "has", &_zephir_call_cache[1], &_1$$3);
		zephir_check_call_status();
		if (zephir_is_true(&hasEventsManager)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "eventsManager");
			ZEPHIR_CALL_METHOD_CACHED(&_2$$4, &container, "getShared", &_zephir_call_cache[2], &_3$$4);
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
		ZEPHIR_CALL_METHOD_CACHED(&resolved, &eventsManager, "fire", &_zephir_call_cache[3], &_6$$5, this_ptr, &_5$$5);
		zephir_check_call_status();
		if (Z_TYPE_P(&resolved) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_7$$6);
			zephir_fast_array_merge(&_7$$6, &headers, &resolved);
			if (UNEXPECTED(Z_TYPE_P(&_7$$6) != IS_ARRAY)) {
				zephir_throw_variable_type_error(&_7$$6, "headers", "array");
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&headers, &_7$$6);
		}
	}
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "PHP_AUTH_USER");
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "hasServer", &_zephir_call_cache[4], &_8);
	zephir_check_call_status();
	_9 = zephir_is_true(&_0);
	if (_9) {
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_STRING(&_8, "PHP_AUTH_PW");
		ZEPHIR_CALL_METHOD_CACHED(&_10, this_ptr, "hasServer", &_zephir_call_cache[5], &_8);
		zephir_check_call_status();
		_9 = zephir_is_true(&_10);
	}
	if (_9) {
		ZEPHIR_INIT_VAR(&_12$$7);
		ZVAL_STRING(&_12$$7, "PHP_AUTH_USER");
		ZEPHIR_CALL_METHOD_CACHED(&_11$$7, this_ptr, "getServer", &_zephir_call_cache[6], &_12$$7);
		zephir_check_call_status();
		zephir_array_update_string(&headers, SL("Php-Auth-User"), &_11$$7, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&_12$$7);
		ZVAL_STRING(&_12$$7, "PHP_AUTH_PW");
		ZEPHIR_CALL_METHOD_CACHED(&_13$$7, this_ptr, "getServer", &_zephir_call_cache[7], &_12$$7);
		zephir_check_call_status();
		zephir_array_update_string(&headers, SL("Php-Auth-Pw"), &_13$$7, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&_15$$8);
		ZVAL_STRING(&_15$$8, "HTTP_AUTHORIZATION");
		ZEPHIR_CALL_METHOD_CACHED(&_14$$8, this_ptr, "hasServer", &_zephir_call_cache[8], &_15$$8);
		zephir_check_call_status();
		if (zephir_is_true(&_14$$8)) {
			ZEPHIR_INIT_VAR(&_17$$9);
			ZVAL_STRING(&_17$$9, "HTTP_AUTHORIZATION");
			ZEPHIR_CALL_METHOD_CACHED(&authHeader, this_ptr, "getServer", &_zephir_call_cache[10], &_17$$9);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&_15$$8);
			ZVAL_STRING(&_15$$8, "REDIRECT_HTTP_AUTHORIZATION");
			ZEPHIR_CALL_METHOD_CACHED(&_16$$8, this_ptr, "hasServer", &_zephir_call_cache[9], &_15$$8);
			zephir_check_call_status();
			if (zephir_is_true(&_16$$8)) {
				ZEPHIR_INIT_VAR(&_18$$10);
				ZVAL_STRING(&_18$$10, "REDIRECT_HTTP_AUTHORIZATION");
				ZEPHIR_CALL_METHOD_CACHED(&authHeader, this_ptr, "getServer", &_zephir_call_cache[11], &_18$$10);
				zephir_check_call_status();
			}
		}
		if (zephir_is_true(&authHeader)) {
			ZEPHIR_INIT_VAR(&_19$$11);
			ZVAL_STRING(&_19$$11, "basic ");
			ZEPHIR_CALL_FUNCTION(&_20$$11, "stripos", NULL, 170, &authHeader, &_19$$11);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_20$$11, 0)) {
				ZVAL_LONG(&_25$$12, 6);
				ZEPHIR_INIT_VAR(&_26$$12);
				zephir_substr(&_26$$12, &authHeader, 6 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CALL_FUNCTION(&_27$$12, "base64_decode", NULL, 122, &_26$$12);
				zephir_check_call_status();
				ZVAL_LONG(&_28$$12, 2);
				ZEPHIR_INIT_VAR(&exploded);
				zephir_fast_explode_str(&exploded, SL(":"), &_27$$12, &_28$$12);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_fast_count_int(&exploded) == 2) {
					zephir_memory_observe(&_29$$13);
					zephir_array_fetch_long(&_29$$13, &exploded, 0, PH_NOISY, "phalcon/Http/Request.zep", 1787);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&headers, SL("Php-Auth-User"), &_29$$13, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_memory_observe(&_30$$13);
					zephir_array_fetch_long(&_30$$13, &exploded, 1, PH_NOISY, "phalcon/Http/Request.zep", 1788);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&headers, SL("Php-Auth-Pw"), &_30$$13, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				ZEPHIR_INIT_NVAR(&_19$$11);
				ZVAL_STRING(&_19$$11, "digest ");
				ZEPHIR_CALL_FUNCTION(&_21$$11, "stripos", NULL, 170, &authHeader, &_19$$11);
				zephir_check_call_status();
				_22$$11 = ZEPHIR_IS_LONG_IDENTICAL(&_21$$11, 0);
				if (_22$$11) {
					ZEPHIR_INIT_NVAR(&_19$$11);
					ZVAL_STRING(&_19$$11, "PHP_AUTH_DIGEST");
					ZEPHIR_CALL_METHOD_CACHED(&_23$$11, this_ptr, "hasServer", &_zephir_call_cache[12], &_19$$11);
					zephir_check_call_status();
					_22$$11 = !zephir_is_true(&_23$$11);
				}
				if (_22$$11) {
					zephir_array_update_string(&headers, SL("Php-Auth-Digest"), &authHeader, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_19$$11);
					ZVAL_STRING(&_19$$11, "bearer ");
					ZEPHIR_CALL_FUNCTION(&_24$$11, "stripos", NULL, 170, &authHeader, &_19$$11);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_24$$11, 0)) {
						zephir_array_update_string(&headers, SL("Authorization"), &authHeader, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			}
		}
	}
	_31 = zephir_array_isset_value_string(&headers, SL("Authorization"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_31)) {
		_32$$16 = zephir_array_isset_value_string(&headers, SL("Php-Auth-User"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_32$$16) {
			zephir_memory_observe(&_34$$17);
			zephir_array_fetch_string(&_34$$17, &headers, SL("Php-Auth-User"), PH_NOISY, "phalcon/Http/Request.zep", 1800);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&_35$$17);
			zephir_array_fetch_string(&_35$$17, &headers, SL("Php-Auth-Pw"), PH_NOISY, "phalcon/Http/Request.zep", 1800);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_36$$17);
			ZEPHIR_CONCAT_VSV(&_36$$17, &_34$$17, ":", &_35$$17);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_FUNCTION(&_37$$17, "base64_encode", NULL, 123, &_36$$17);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_38$$17);
			ZEPHIR_CONCAT_SV(&_38$$17, "Basic ", &_37$$17);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&headers, SL("Authorization"), &_38$$17, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			zephir_memory_observe(&digest);
			_33$$16 = zephir_array_isset_string_fetch(&digest, &headers, SL("Php-Auth-Digest"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_33$$16) {
				zephir_array_update_string(&headers, SL("Authorization"), &digest, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	_39 = zephir_is_true(&hasEventsManager);
	if (_39) {
		_39 = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	}
	if (_39) {
		ZEPHIR_INIT_VAR(&_40$$19);
		zephir_create_array(&_40$$19, 2, 0);
		zephir_array_update_string(&_40$$19, SL("headers"), &headers, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_40$$19, SL("server"), &server, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_41$$19);
		ZVAL_STRING(&_41$$19, "request:afterAuthorizationResolve");
		ZEPHIR_CALL_METHOD_CACHED(&resolved, &eventsManager, "fire", &_zephir_call_cache[13], &_41$$19, this_ptr, &_40$$19);
		zephir_check_call_status();
		if (Z_TYPE_P(&resolved) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_42$$20);
			zephir_fast_array_merge(&_42$$20, &headers, &resolved);
			if (UNEXPECTED(Z_TYPE_P(&_42$$20) != IS_ARRAY)) {
				zephir_throw_variable_type_error(&_42$$20, "headers", "array");
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&headers, &_42$$20);
		}
	}
	RETURN_CTOR(&headers);
}

/**
 * Smooth out $_FILES to have plain array with all files uploaded
 *
 * @phpstan-param  array<array-key, mixed> $names
 * @phpstan-param  array<array-key, mixed> $types
 * @phpstan-param  array<array-key, mixed> $tmp_names
 * @phpstan-param  array<array-key, mixed> $sizes
 * @phpstan-param  array<array-key, mixed> $errors
 * @phpstan-return list<http_smooth_file>
 */
PHP_METHOD(Phalcon_Http_Request, smoothFiles)
{
	zend_bool _16, _14$$5, _28$$10;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *prefix = NULL, *_2;
	zval *names_param = NULL, *types_param = NULL, *tmp_names_param = NULL, *sizes_param = NULL, *errors_param = NULL, prefix_zv, idx, name, file, files, parentFiles, p, *_0, _15, _4$$4, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, *_10$$5, _11$$5, *_12$$5, _13$$5, _18$$9, _19$$10, _20$$10, _21$$10, _22$$10, _23$$10, *_24$$10, _25$$10, *_26$$10, _27$$10;
	zval names, types, tmp_names, sizes, errors, _3$$4, _17$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&tmp_names);
	ZVAL_UNDEF(&sizes);
	ZVAL_UNDEF(&errors);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&idx);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&parentFiles);
	ZVAL_UNDEF(&p);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_27$$10);
	ZEND_TLS zephir_method_cache _zephir_call_cache[15];
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
	zephir_get_arrval(&names, names_param);
	zephir_get_arrval(&types, types_param);
	zephir_get_arrval(&tmp_names, tmp_names_param);
	zephir_get_arrval(&sizes, sizes_param);
	zephir_get_arrval(&errors, errors_param);
	zephir_memory_observe(&prefix_zv);
	ZVAL_STR_COPY(&prefix_zv, prefix);
	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	zephir_is_iterable(&names, 0, "phalcon/Http/Request.zep", 1876);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&name) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_3$$4);
				zephir_create_array(&_3$$4, 6, 0);
				zephir_array_update_string(&_3$$4, SL("name"), &name, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_array_fetch(&_4$$4, &types, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1852);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&_3$$4, SL("type"), &_4$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_array_fetch(&_4$$4, &tmp_names, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1853);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&_3$$4, SL("tmp_name"), &_4$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_array_fetch(&_4$$4, &sizes, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1854);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&_3$$4, SL("size"), &_4$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_array_fetch(&_4$$4, &errors, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1855);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&_3$$4, SL("error"), &_4$$4, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_3$$4, SL("key"), &p, PH_COPY | PH_SEPARATE);
				zephir_array_append(&files, &_3$$4, PH_SEPARATE, "phalcon/Http/Request.zep", 1857);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (Z_TYPE_P(&name) == IS_ARRAY) {
				zephir_array_fetch(&_5$$5, &names, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1862);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_6$$5, &types, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1863);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_7$$5, &tmp_names, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1864);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_8$$5, &sizes, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1865);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_9$$5, &errors, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1866);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&parentFiles, this_ptr, "smoothFiles", &_zephir_call_cache[0], &_5$$5, &_6$$5, &_7$$5, &_8$$5, &_9$$5, &p);
				zephir_check_call_status();
				if (Z_TYPE_P(&parentFiles) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_11$$5);
					zephir_string_to_char_array(&_11$$5, &parentFiles);
					_10$$5 = &_11$$5;
				} else {
					_10$$5 = &parentFiles;
				}
				zephir_is_iterable(_10$$5, 0, "phalcon/Http/Request.zep", 1873);
				if (Z_TYPE_P(_10$$5) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_10$$5), _12$$5)
					{
						ZEPHIR_INIT_NVAR(&file);
						ZVAL_COPY(&file, _12$$5);
						zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/Http/Request.zep", 1871);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _10$$5, "rewind", &_zephir_call_cache[1]);
					zephir_check_call_status();
					_14$$5 = 1;
					while (1) {
						if (_14$$5) {
							_14$$5 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _10$$5, "next", &_zephir_call_cache[2]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_13$$5, _10$$5, "valid", &_zephir_call_cache[3]);
						zephir_check_call_status();
						if (!zend_is_true(&_13$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&file, _10$$5, "current", &_zephir_call_cache[4]);
						zephir_check_call_status();
							zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/Http/Request.zep", 1871);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&file);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &names, "rewind", &_zephir_call_cache[5]);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &names, "next", &_zephir_call_cache[6]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_15, &names, "valid", &_zephir_call_cache[7]);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&idx, &names, "key", &_zephir_call_cache[8]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&name, &names, "current", &_zephir_call_cache[9]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&p);
				ZEPHIR_CONCAT_VSV(&p, &prefix_zv, ".", &idx);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&name) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_17$$9);
					zephir_create_array(&_17$$9, 6, 0);
					zephir_array_update_string(&_17$$9, SL("name"), &name, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_18$$9);
					zephir_array_fetch(&_18$$9, &types, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1852);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_17$$9, SL("type"), &_18$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_18$$9);
					zephir_array_fetch(&_18$$9, &tmp_names, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1853);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_17$$9, SL("tmp_name"), &_18$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_18$$9);
					zephir_array_fetch(&_18$$9, &sizes, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1854);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_17$$9, SL("size"), &_18$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_18$$9);
					zephir_array_fetch(&_18$$9, &errors, &idx, PH_NOISY, "phalcon/Http/Request.zep", 1855);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_17$$9, SL("error"), &_18$$9, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_17$$9, SL("key"), &p, PH_COPY | PH_SEPARATE);
					zephir_array_append(&files, &_17$$9, PH_SEPARATE, "phalcon/Http/Request.zep", 1857);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (Z_TYPE_P(&name) == IS_ARRAY) {
					zephir_array_fetch(&_19$$10, &names, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1862);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_20$$10, &types, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1863);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_21$$10, &tmp_names, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1864);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_22$$10, &sizes, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1865);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_23$$10, &errors, &idx, PH_NOISY | PH_READONLY, "phalcon/Http/Request.zep", 1866);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&parentFiles, this_ptr, "smoothFiles", &_zephir_call_cache[10], &_19$$10, &_20$$10, &_21$$10, &_22$$10, &_23$$10, &p);
					zephir_check_call_status();
					if (Z_TYPE_P(&parentFiles) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_25$$10);
						zephir_string_to_char_array(&_25$$10, &parentFiles);
						_24$$10 = &_25$$10;
					} else {
						_24$$10 = &parentFiles;
					}
					zephir_is_iterable(_24$$10, 0, "phalcon/Http/Request.zep", 1873);
					if (Z_TYPE_P(_24$$10) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_24$$10), _26$$10)
						{
							ZEPHIR_INIT_NVAR(&file);
							ZVAL_COPY(&file, _26$$10);
							zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/Http/Request.zep", 1871);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _24$$10, "rewind", &_zephir_call_cache[11]);
						zephir_check_call_status();
						_28$$10 = 1;
						while (1) {
							if (_28$$10) {
								_28$$10 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _24$$10, "next", &_zephir_call_cache[12]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_27$$10, _24$$10, "valid", &_zephir_call_cache[13]);
							zephir_check_call_status();
							if (!zend_is_true(&_27$$10)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&file, _24$$10, "current", &_zephir_call_cache[14]);
							zephir_check_call_status();
								zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/Http/Request.zep", 1871);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("filterService", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("container", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 907, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&filterService, &_0);
	if (Z_TYPE_P(&filterService) != IS_OBJECT) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 908, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&container, &_1$$3);
		if (Z_TYPE_P(&container) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_http_request_exceptions_filterserviceunavailable_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$4, "__construct", &_zephir_call_cache[0]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "phalcon/Http/Request.zep", 1892);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "filter");
		ZEPHIR_CALL_METHOD_CACHED(&_3$$3, &container, "getShared", &_zephir_call_cache[1], &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&filterService, &_3$$3);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 907, &filterService);
	}
	RETURN_MM_MEMBER(getThis(), "filterService");
}

/**
 * Parses multipart/form-data from the raw body.
 *
 * @phpstan-return http_form_data
 */
PHP_METHOD(Phalcon_Http_Request, getFormData)
{
	zval dataset, headers$$4, headers$$22;
	zend_bool _5, _66, _41$$4, _62$$4, _63$$4, _94$$22, _115$$22, _116$$22;
	zval _1;
	zval boundary, matches, _0, _2, _3, _4, bodyParts, _6, _7, _8, _9, bodyPart, *_11, *_12, _65, splited$$4, _13$$4, _14$$4, headerParts$$4, headerPart$$4, _15$$4, _16$$4, *_17$$4, *_18$$4, _40$$4, disposition$$4, dispositionName$$4, _64$$4, _19$$6, _20$$6, exploded$$6, headerName$$6, headerValue$$6, _21$$6, _22$$6, _23$$6, _24$$6, _25$$6, _26$$6, explodedHeader$$8, part$$8, *_27$$8, _28$$8, *_29$$8, _30$$9, _31$$9, _32$$9, explodedPart$$10, namePart$$10, valuePart$$10, _34$$10, _35$$10, _36$$10, _37$$10, _38$$10, _39$$10, _42$$13, _43$$13, exploded$$13, headerName$$13, headerValue$$13, _44$$13, _45$$13, _46$$13, _47$$13, _48$$13, _49$$13, explodedHeader$$15, part$$15, *_50$$15, _51$$15, *_52$$15, _53$$16, _54$$16, _55$$16, explodedPart$$17, namePart$$17, valuePart$$17, _56$$17, _57$$17, _58$$17, _59$$17, _60$$17, _61$$17, splited$$22, _67$$22, _68$$22, headerParts$$22, headerPart$$22, _69$$22, _70$$22, *_71$$22, *_72$$22, _93$$22, disposition$$22, dispositionName$$22, _117$$22, _73$$24, _74$$24, exploded$$24, headerName$$24, headerValue$$24, _75$$24, _76$$24, _77$$24, _78$$24, _79$$24, _80$$24, explodedHeader$$26, part$$26, *_81$$26, _82$$26, *_83$$26, _84$$27, _85$$27, _86$$27, explodedPart$$28, namePart$$28, valuePart$$28, _87$$28, _88$$28, _89$$28, _90$$28, _91$$28, _92$$28, _95$$31, _96$$31, exploded$$31, headerName$$31, headerValue$$31, _97$$31, _98$$31, _99$$31, _100$$31, _101$$31, _102$$31, explodedHeader$$33, part$$33, *_103$$33, _104$$33, *_105$$33, _106$$34, _107$$34, _108$$34, explodedPart$$35, namePart$$35, valuePart$$35, _109$$35, _110$$35, _111$$35, _112$$35, _113$$35, _114$$35;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_33 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&boundary);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&bodyParts);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&bodyPart);
	ZVAL_UNDEF(&_65);
	ZVAL_UNDEF(&splited$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&headerParts$$4);
	ZVAL_UNDEF(&headerPart$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_40$$4);
	ZVAL_UNDEF(&disposition$$4);
	ZVAL_UNDEF(&dispositionName$$4);
	ZVAL_UNDEF(&_64$$4);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&exploded$$6);
	ZVAL_UNDEF(&headerName$$6);
	ZVAL_UNDEF(&headerValue$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&explodedHeader$$8);
	ZVAL_UNDEF(&part$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&explodedPart$$10);
	ZVAL_UNDEF(&namePart$$10);
	ZVAL_UNDEF(&valuePart$$10);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_42$$13);
	ZVAL_UNDEF(&_43$$13);
	ZVAL_UNDEF(&exploded$$13);
	ZVAL_UNDEF(&headerName$$13);
	ZVAL_UNDEF(&headerValue$$13);
	ZVAL_UNDEF(&_44$$13);
	ZVAL_UNDEF(&_45$$13);
	ZVAL_UNDEF(&_46$$13);
	ZVAL_UNDEF(&_47$$13);
	ZVAL_UNDEF(&_48$$13);
	ZVAL_UNDEF(&_49$$13);
	ZVAL_UNDEF(&explodedHeader$$15);
	ZVAL_UNDEF(&part$$15);
	ZVAL_UNDEF(&_51$$15);
	ZVAL_UNDEF(&_53$$16);
	ZVAL_UNDEF(&_54$$16);
	ZVAL_UNDEF(&_55$$16);
	ZVAL_UNDEF(&explodedPart$$17);
	ZVAL_UNDEF(&namePart$$17);
	ZVAL_UNDEF(&valuePart$$17);
	ZVAL_UNDEF(&_56$$17);
	ZVAL_UNDEF(&_57$$17);
	ZVAL_UNDEF(&_58$$17);
	ZVAL_UNDEF(&_59$$17);
	ZVAL_UNDEF(&_60$$17);
	ZVAL_UNDEF(&_61$$17);
	ZVAL_UNDEF(&splited$$22);
	ZVAL_UNDEF(&_67$$22);
	ZVAL_UNDEF(&_68$$22);
	ZVAL_UNDEF(&headerParts$$22);
	ZVAL_UNDEF(&headerPart$$22);
	ZVAL_UNDEF(&_69$$22);
	ZVAL_UNDEF(&_70$$22);
	ZVAL_UNDEF(&_93$$22);
	ZVAL_UNDEF(&disposition$$22);
	ZVAL_UNDEF(&dispositionName$$22);
	ZVAL_UNDEF(&_117$$22);
	ZVAL_UNDEF(&_73$$24);
	ZVAL_UNDEF(&_74$$24);
	ZVAL_UNDEF(&exploded$$24);
	ZVAL_UNDEF(&headerName$$24);
	ZVAL_UNDEF(&headerValue$$24);
	ZVAL_UNDEF(&_75$$24);
	ZVAL_UNDEF(&_76$$24);
	ZVAL_UNDEF(&_77$$24);
	ZVAL_UNDEF(&_78$$24);
	ZVAL_UNDEF(&_79$$24);
	ZVAL_UNDEF(&_80$$24);
	ZVAL_UNDEF(&explodedHeader$$26);
	ZVAL_UNDEF(&part$$26);
	ZVAL_UNDEF(&_82$$26);
	ZVAL_UNDEF(&_84$$27);
	ZVAL_UNDEF(&_85$$27);
	ZVAL_UNDEF(&_86$$27);
	ZVAL_UNDEF(&explodedPart$$28);
	ZVAL_UNDEF(&namePart$$28);
	ZVAL_UNDEF(&valuePart$$28);
	ZVAL_UNDEF(&_87$$28);
	ZVAL_UNDEF(&_88$$28);
	ZVAL_UNDEF(&_89$$28);
	ZVAL_UNDEF(&_90$$28);
	ZVAL_UNDEF(&_91$$28);
	ZVAL_UNDEF(&_92$$28);
	ZVAL_UNDEF(&_95$$31);
	ZVAL_UNDEF(&_96$$31);
	ZVAL_UNDEF(&exploded$$31);
	ZVAL_UNDEF(&headerName$$31);
	ZVAL_UNDEF(&headerValue$$31);
	ZVAL_UNDEF(&_97$$31);
	ZVAL_UNDEF(&_98$$31);
	ZVAL_UNDEF(&_99$$31);
	ZVAL_UNDEF(&_100$$31);
	ZVAL_UNDEF(&_101$$31);
	ZVAL_UNDEF(&_102$$31);
	ZVAL_UNDEF(&explodedHeader$$33);
	ZVAL_UNDEF(&part$$33);
	ZVAL_UNDEF(&_104$$33);
	ZVAL_UNDEF(&_106$$34);
	ZVAL_UNDEF(&_107$$34);
	ZVAL_UNDEF(&_108$$34);
	ZVAL_UNDEF(&explodedPart$$35);
	ZVAL_UNDEF(&namePart$$35);
	ZVAL_UNDEF(&valuePart$$35);
	ZVAL_UNDEF(&_109$$35);
	ZVAL_UNDEF(&_110$$35);
	ZVAL_UNDEF(&_111$$35);
	ZVAL_UNDEF(&_112$$35);
	ZVAL_UNDEF(&_113$$35);
	ZVAL_UNDEF(&_114$$35);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&dataset);
	ZVAL_UNDEF(&headers$$4);
	ZVAL_UNDEF(&headers$$22);
	ZEND_TLS zephir_method_cache _zephir_call_cache[14];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getContentType", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_cast_to_string(&_1, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/boundary=(.*)$/is");
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/boundary=(.*)$/is");
	zephir_preg_match(&_3, &_4, &_1, &matches, 0, 0 , 0 );
	zephir_memory_observe(&boundary);
	_5 = zephir_array_isset_long_fetch(&boundary, &matches, 1, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_5)) {
		ZEPHIR_INIT_NVAR(&boundary);
		ZVAL_STRING(&boundary, "");
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "/");
	ZEPHIR_CALL_FUNCTION(&_7, "preg_quote", NULL, 173, &boundary, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_SVS(&_8, "/\\R?-+", &_7, "/s");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_9, this_ptr, "getRawBody", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&bodyParts, "preg_split", &_10, 58, &_8, &_9);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&bodyParts);
	ZEPHIR_CALL_FUNCTION(NULL, "array_pop", NULL, 103, &bodyParts);
	ZEPHIR_UNREF(&bodyParts);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&dataset);
	array_init(&dataset);
	if (Z_TYPE_P(&bodyParts) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_6);
		zephir_string_to_char_array(&_6, &bodyParts);
		_11 = &_6;
	} else {
		_11 = &bodyParts;
	}
	zephir_is_iterable(_11, 0, "phalcon/Http/Request.zep", 1986);
	if (Z_TYPE_P(_11) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_11), _12)
		{
			ZEPHIR_INIT_NVAR(&bodyPart);
			ZVAL_COPY(&bodyPart, _12);
			if (ZEPHIR_IS_EMPTY(&bodyPart)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_13$$4);
			ZVAL_STRING(&_13$$4, "/\\R\\R/");
			ZVAL_LONG(&_14$$4, 2);
			ZEPHIR_CALL_FUNCTION(&splited$$4, "preg_split", &_10, 58, &_13$$4, &bodyPart, &_14$$4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&splited$$4, &splited$$4);
			ZEPHIR_INIT_NVAR(&headers$$4);
			array_init(&headers$$4);
			ZEPHIR_OBS_NVAR(&_15$$4);
			zephir_array_fetch_long(&_15$$4, &splited$$4, 0, PH_NOISY, "phalcon/Http/Request.zep", 1937);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_13$$4);
			ZVAL_STRING(&_13$$4, "/\\R/s");
			ZVAL_LONG(&_14$$4, -1);
			ZVAL_LONG(&_16$$4, 1);
			ZEPHIR_CALL_FUNCTION(&headerParts$$4, "preg_split", &_10, 58, &_13$$4, &_15$$4, &_14$$4, &_16$$4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&headerParts$$4, &headerParts$$4);
			if (Z_TYPE_P(&headerParts$$4) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_13$$4);
				zephir_string_to_char_array(&_13$$4, &headerParts$$4);
				_17$$4 = &_13$$4;
			} else {
				_17$$4 = &headerParts$$4;
			}
			zephir_is_iterable(_17$$4, 0, "phalcon/Http/Request.zep", 1973);
			if (Z_TYPE_P(_17$$4) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_17$$4), _18$$4)
				{
					ZEPHIR_INIT_NVAR(&headerPart$$4);
					ZVAL_COPY(&headerPart$$4, _18$$4);
					ZEPHIR_INIT_NVAR(&_19$$6);
					ZVAL_STRING(&_19$$6, ":");
					ZEPHIR_INIT_NVAR(&_20$$6);
					zephir_fast_strpos(&_20$$6, &headerPart$$4, &_19$$6, 0 );
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_20$$6)) {
						continue;
					}
					ZVAL_LONG(&_21$$6, 2);
					ZEPHIR_INIT_NVAR(&exploded$$6);
					zephir_fast_explode_str(&exploded$$6, SL(":"), &headerPart$$4, &_21$$6);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&exploded$$6, &exploded$$6);
					ZEPHIR_INIT_NVAR(&_22$$6);
					ZEPHIR_OBS_NVAR(&_23$$6);
					zephir_array_fetch_long(&_23$$6, &exploded$$6, 0, PH_NOISY, "phalcon/Http/Request.zep", 1947);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_fast_trim(&_22$$6, &_23$$6, NULL , ZEPHIR_TRIM_BOTH);
					ZEPHIR_INIT_NVAR(&headerName$$6);
					zephir_fast_strtolower(&headerName$$6, &_22$$6);
					ZEPHIR_CPY_WRT(&headerName$$6, &headerName$$6);
					ZEPHIR_OBS_NVAR(&_24$$6);
					zephir_array_fetch_long(&_24$$6, &exploded$$6, 1, PH_NOISY, "phalcon/Http/Request.zep", 1948);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&headerValue$$6);
					zephir_fast_trim(&headerValue$$6, &_24$$6, NULL , ZEPHIR_TRIM_BOTH);
					ZEPHIR_CPY_WRT(&headerValue$$6, &headerValue$$6);
					ZEPHIR_INIT_NVAR(&_25$$6);
					ZVAL_STRING(&_25$$6, ";");
					ZEPHIR_INIT_NVAR(&_26$$6);
					zephir_fast_strpos(&_26$$6, &headerValue$$6, &_25$$6, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_26$$6)) {
						ZEPHIR_INIT_NVAR(&explodedHeader$$8);
						zephir_fast_explode_str(&explodedHeader$$8, SL(";"), &headerValue$$6, NULL);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CPY_WRT(&explodedHeader$$8, &explodedHeader$$8);
						if (Z_TYPE_P(&explodedHeader$$8) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_28$$8);
							zephir_string_to_char_array(&_28$$8, &explodedHeader$$8);
							_27$$8 = &_28$$8;
						} else {
							_27$$8 = &explodedHeader$$8;
						}
						zephir_is_iterable(_27$$8, 0, "phalcon/Http/Request.zep", 1968);
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_27$$8), _29$$8)
						{
							ZEPHIR_INIT_NVAR(&part$$8);
							ZVAL_COPY(&part$$8, _29$$8);
							ZEPHIR_INIT_NVAR(&_30$$9);
							zephir_fast_trim(&_30$$9, &part$$8, NULL , ZEPHIR_TRIM_BOTH);
							ZEPHIR_INIT_NVAR(&_31$$9);
							ZVAL_STRING(&_31$$9, "/\"/");
							ZEPHIR_INIT_NVAR(&_32$$9);
							ZVAL_STRING(&_32$$9, "");
							ZEPHIR_CALL_FUNCTION(&part$$8, "preg_replace", &_33, 2, &_31$$9, &_32$$9, &_30$$9);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&part$$8, &part$$8);
							ZEPHIR_INIT_NVAR(&_31$$9);
							ZVAL_STRING(&_31$$9, "=");
							ZEPHIR_INIT_NVAR(&_32$$9);
							zephir_fast_strpos(&_32$$9, &part$$8, &_31$$9, 0 );
							if (!ZEPHIR_IS_FALSE_IDENTICAL(&_32$$9)) {
								ZVAL_LONG(&_34$$10, 2);
								ZEPHIR_INIT_NVAR(&explodedPart$$10);
								zephir_fast_explode_str(&explodedPart$$10, SL("="), &part$$8, &_34$$10);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CPY_WRT(&explodedPart$$10, &explodedPart$$10);
								ZEPHIR_INIT_NVAR(&_35$$10);
								ZEPHIR_OBS_NVAR(&_36$$10);
								zephir_array_fetch_long(&_36$$10, &explodedPart$$10, 0, PH_NOISY, "phalcon/Http/Request.zep", 1960);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_fast_trim(&_35$$10, &_36$$10, NULL , ZEPHIR_TRIM_BOTH);
								ZEPHIR_INIT_NVAR(&namePart$$10);
								zephir_fast_strtolower(&namePart$$10, &_35$$10);
								ZEPHIR_CPY_WRT(&namePart$$10, &namePart$$10);
								ZEPHIR_INIT_NVAR(&_37$$10);
								ZEPHIR_OBS_NVAR(&_38$$10);
								zephir_array_fetch_long(&_38$$10, &explodedPart$$10, 1, PH_NOISY, "phalcon/Http/Request.zep", 1961);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_fast_trim(&_37$$10, &_38$$10, NULL , ZEPHIR_TRIM_BOTH);
								ZEPHIR_INIT_NVAR(&_39$$10);
								ZVAL_STRING(&_39$$10, "\"");
								ZEPHIR_INIT_NVAR(&valuePart$$10);
								zephir_fast_trim(&valuePart$$10, &_37$$10, &_39$$10, ZEPHIR_TRIM_BOTH);
								ZEPHIR_CPY_WRT(&valuePart$$10, &valuePart$$10);
								zephir_array_update_multi(&headers$$4, &valuePart$$10, SL("zz"), 2, &headerName$$6, &namePart$$10);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								zephir_array_update_multi(&headers$$4, &part$$8, SL("za"), 2, &headerName$$6);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						} ZEND_HASH_FOREACH_END();
						ZEPHIR_INIT_NVAR(&part$$8);
					} else {
						zephir_array_update_zval(&headers$$4, &headerName$$6, &headerValue$$6, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _17$$4, "rewind", &_zephir_call_cache[2]);
				zephir_check_call_status();
				_41$$4 = 1;
				while (1) {
					if (_41$$4) {
						_41$$4 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _17$$4, "next", &_zephir_call_cache[3]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_40$$4, _17$$4, "valid", &_zephir_call_cache[4]);
					zephir_check_call_status();
					if (!zend_is_true(&_40$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&headerPart$$4, _17$$4, "current", &_zephir_call_cache[5]);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_42$$13);
						ZVAL_STRING(&_42$$13, ":");
						ZEPHIR_INIT_NVAR(&_43$$13);
						zephir_fast_strpos(&_43$$13, &headerPart$$4, &_42$$13, 0 );
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_43$$13)) {
							continue;
						}
						ZVAL_LONG(&_44$$13, 2);
						ZEPHIR_INIT_NVAR(&exploded$$13);
						zephir_fast_explode_str(&exploded$$13, SL(":"), &headerPart$$4, &_44$$13);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CPY_WRT(&exploded$$13, &exploded$$13);
						ZEPHIR_INIT_NVAR(&_45$$13);
						ZEPHIR_OBS_NVAR(&_46$$13);
						zephir_array_fetch_long(&_46$$13, &exploded$$13, 0, PH_NOISY, "phalcon/Http/Request.zep", 1947);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_fast_trim(&_45$$13, &_46$$13, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_INIT_NVAR(&headerName$$13);
						zephir_fast_strtolower(&headerName$$13, &_45$$13);
						ZEPHIR_CPY_WRT(&headerName$$13, &headerName$$13);
						ZEPHIR_OBS_NVAR(&_47$$13);
						zephir_array_fetch_long(&_47$$13, &exploded$$13, 1, PH_NOISY, "phalcon/Http/Request.zep", 1948);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&headerValue$$13);
						zephir_fast_trim(&headerValue$$13, &_47$$13, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_CPY_WRT(&headerValue$$13, &headerValue$$13);
						ZEPHIR_INIT_NVAR(&_48$$13);
						ZVAL_STRING(&_48$$13, ";");
						ZEPHIR_INIT_NVAR(&_49$$13);
						zephir_fast_strpos(&_49$$13, &headerValue$$13, &_48$$13, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_49$$13)) {
							ZEPHIR_INIT_NVAR(&explodedHeader$$15);
							zephir_fast_explode_str(&explodedHeader$$15, SL(";"), &headerValue$$13, NULL);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CPY_WRT(&explodedHeader$$15, &explodedHeader$$15);
							if (Z_TYPE_P(&explodedHeader$$15) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_51$$15);
								zephir_string_to_char_array(&_51$$15, &explodedHeader$$15);
								_50$$15 = &_51$$15;
							} else {
								_50$$15 = &explodedHeader$$15;
							}
							zephir_is_iterable(_50$$15, 0, "phalcon/Http/Request.zep", 1968);
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_50$$15), _52$$15)
							{
								ZEPHIR_INIT_NVAR(&part$$15);
								ZVAL_COPY(&part$$15, _52$$15);
								ZEPHIR_INIT_NVAR(&_53$$16);
								zephir_fast_trim(&_53$$16, &part$$15, NULL , ZEPHIR_TRIM_BOTH);
								ZEPHIR_INIT_NVAR(&_54$$16);
								ZVAL_STRING(&_54$$16, "/\"/");
								ZEPHIR_INIT_NVAR(&_55$$16);
								ZVAL_STRING(&_55$$16, "");
								ZEPHIR_CALL_FUNCTION(&part$$15, "preg_replace", &_33, 2, &_54$$16, &_55$$16, &_53$$16);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&part$$15, &part$$15);
								ZEPHIR_INIT_NVAR(&_54$$16);
								ZVAL_STRING(&_54$$16, "=");
								ZEPHIR_INIT_NVAR(&_55$$16);
								zephir_fast_strpos(&_55$$16, &part$$15, &_54$$16, 0 );
								if (!ZEPHIR_IS_FALSE_IDENTICAL(&_55$$16)) {
									ZVAL_LONG(&_56$$17, 2);
									ZEPHIR_INIT_NVAR(&explodedPart$$17);
									zephir_fast_explode_str(&explodedPart$$17, SL("="), &part$$15, &_56$$17);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CPY_WRT(&explodedPart$$17, &explodedPart$$17);
									ZEPHIR_INIT_NVAR(&_57$$17);
									ZEPHIR_OBS_NVAR(&_58$$17);
									zephir_array_fetch_long(&_58$$17, &explodedPart$$17, 0, PH_NOISY, "phalcon/Http/Request.zep", 1960);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_fast_trim(&_57$$17, &_58$$17, NULL , ZEPHIR_TRIM_BOTH);
									ZEPHIR_INIT_NVAR(&namePart$$17);
									zephir_fast_strtolower(&namePart$$17, &_57$$17);
									ZEPHIR_CPY_WRT(&namePart$$17, &namePart$$17);
									ZEPHIR_INIT_NVAR(&_59$$17);
									ZEPHIR_OBS_NVAR(&_60$$17);
									zephir_array_fetch_long(&_60$$17, &explodedPart$$17, 1, PH_NOISY, "phalcon/Http/Request.zep", 1961);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_fast_trim(&_59$$17, &_60$$17, NULL , ZEPHIR_TRIM_BOTH);
									ZEPHIR_INIT_NVAR(&_61$$17);
									ZVAL_STRING(&_61$$17, "\"");
									ZEPHIR_INIT_NVAR(&valuePart$$17);
									zephir_fast_trim(&valuePart$$17, &_59$$17, &_61$$17, ZEPHIR_TRIM_BOTH);
									ZEPHIR_CPY_WRT(&valuePart$$17, &valuePart$$17);
									zephir_array_update_multi(&headers$$4, &valuePart$$17, SL("zz"), 2, &headerName$$13, &namePart$$17);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									zephir_array_update_multi(&headers$$4, &part$$15, SL("za"), 2, &headerName$$13);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							} ZEND_HASH_FOREACH_END();
							ZEPHIR_INIT_NVAR(&part$$15);
						} else {
							zephir_array_update_zval(&headers$$4, &headerName$$13, &headerValue$$13, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
				}
			}
			ZEPHIR_INIT_NVAR(&headerPart$$4);
			ZEPHIR_OBS_NVAR(&disposition$$4);
			_62$$4 = zephir_array_isset_string_fetch(&disposition$$4, &headers$$4, SL("content-disposition"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_62$$4)) {
				ZEPHIR_INIT_NVAR(&disposition$$4);
				array_init(&disposition$$4);
				ZEPHIR_CPY_WRT(&disposition$$4, &disposition$$4);
			}
			ZEPHIR_OBS_NVAR(&dispositionName$$4);
			_63$$4 = zephir_array_isset_string_fetch(&dispositionName$$4, &disposition$$4, SL("name"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_63$$4)) {
				ZEPHIR_INIT_NVAR(&dispositionName$$4);
				ZVAL_STRING(&dispositionName$$4, "");
			}
			ZEPHIR_OBS_NVAR(&_64$$4);
			zephir_array_fetch_long(&_64$$4, &splited$$4, 1, PH_NOISY, "phalcon/Http/Request.zep", 1983);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&dataset, &dispositionName$$4, &_64$$4, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _11, "rewind", &_zephir_call_cache[6]);
		zephir_check_call_status();
		_66 = 1;
		while (1) {
			if (_66) {
				_66 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _11, "next", &_zephir_call_cache[7]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_65, _11, "valid", &_zephir_call_cache[8]);
			zephir_check_call_status();
			if (!zend_is_true(&_65)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&bodyPart, _11, "current", &_zephir_call_cache[9]);
			zephir_check_call_status();
				if (ZEPHIR_IS_EMPTY(&bodyPart)) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_67$$22);
				ZVAL_STRING(&_67$$22, "/\\R\\R/");
				ZVAL_LONG(&_68$$22, 2);
				ZEPHIR_CALL_FUNCTION(&splited$$22, "preg_split", &_10, 58, &_67$$22, &bodyPart, &_68$$22);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&splited$$22, &splited$$22);
				ZEPHIR_INIT_NVAR(&headers$$22);
				array_init(&headers$$22);
				ZEPHIR_OBS_NVAR(&_69$$22);
				zephir_array_fetch_long(&_69$$22, &splited$$22, 0, PH_NOISY, "phalcon/Http/Request.zep", 1937);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_67$$22);
				ZVAL_STRING(&_67$$22, "/\\R/s");
				ZVAL_LONG(&_68$$22, -1);
				ZVAL_LONG(&_70$$22, 1);
				ZEPHIR_CALL_FUNCTION(&headerParts$$22, "preg_split", &_10, 58, &_67$$22, &_69$$22, &_68$$22, &_70$$22);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&headerParts$$22, &headerParts$$22);
				if (Z_TYPE_P(&headerParts$$22) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_67$$22);
					zephir_string_to_char_array(&_67$$22, &headerParts$$22);
					_71$$22 = &_67$$22;
				} else {
					_71$$22 = &headerParts$$22;
				}
				zephir_is_iterable(_71$$22, 0, "phalcon/Http/Request.zep", 1973);
				if (Z_TYPE_P(_71$$22) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_71$$22), _72$$22)
					{
						ZEPHIR_INIT_NVAR(&headerPart$$22);
						ZVAL_COPY(&headerPart$$22, _72$$22);
						ZEPHIR_INIT_NVAR(&_73$$24);
						ZVAL_STRING(&_73$$24, ":");
						ZEPHIR_INIT_NVAR(&_74$$24);
						zephir_fast_strpos(&_74$$24, &headerPart$$22, &_73$$24, 0 );
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_74$$24)) {
							continue;
						}
						ZVAL_LONG(&_75$$24, 2);
						ZEPHIR_INIT_NVAR(&exploded$$24);
						zephir_fast_explode_str(&exploded$$24, SL(":"), &headerPart$$22, &_75$$24);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CPY_WRT(&exploded$$24, &exploded$$24);
						ZEPHIR_INIT_NVAR(&_76$$24);
						ZEPHIR_OBS_NVAR(&_77$$24);
						zephir_array_fetch_long(&_77$$24, &exploded$$24, 0, PH_NOISY, "phalcon/Http/Request.zep", 1947);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_fast_trim(&_76$$24, &_77$$24, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_INIT_NVAR(&headerName$$24);
						zephir_fast_strtolower(&headerName$$24, &_76$$24);
						ZEPHIR_CPY_WRT(&headerName$$24, &headerName$$24);
						ZEPHIR_OBS_NVAR(&_78$$24);
						zephir_array_fetch_long(&_78$$24, &exploded$$24, 1, PH_NOISY, "phalcon/Http/Request.zep", 1948);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&headerValue$$24);
						zephir_fast_trim(&headerValue$$24, &_78$$24, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_CPY_WRT(&headerValue$$24, &headerValue$$24);
						ZEPHIR_INIT_NVAR(&_79$$24);
						ZVAL_STRING(&_79$$24, ";");
						ZEPHIR_INIT_NVAR(&_80$$24);
						zephir_fast_strpos(&_80$$24, &headerValue$$24, &_79$$24, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_80$$24)) {
							ZEPHIR_INIT_NVAR(&explodedHeader$$26);
							zephir_fast_explode_str(&explodedHeader$$26, SL(";"), &headerValue$$24, NULL);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CPY_WRT(&explodedHeader$$26, &explodedHeader$$26);
							if (Z_TYPE_P(&explodedHeader$$26) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_82$$26);
								zephir_string_to_char_array(&_82$$26, &explodedHeader$$26);
								_81$$26 = &_82$$26;
							} else {
								_81$$26 = &explodedHeader$$26;
							}
							zephir_is_iterable(_81$$26, 0, "phalcon/Http/Request.zep", 1968);
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_81$$26), _83$$26)
							{
								ZEPHIR_INIT_NVAR(&part$$26);
								ZVAL_COPY(&part$$26, _83$$26);
								ZEPHIR_INIT_NVAR(&_84$$27);
								zephir_fast_trim(&_84$$27, &part$$26, NULL , ZEPHIR_TRIM_BOTH);
								ZEPHIR_INIT_NVAR(&_85$$27);
								ZVAL_STRING(&_85$$27, "/\"/");
								ZEPHIR_INIT_NVAR(&_86$$27);
								ZVAL_STRING(&_86$$27, "");
								ZEPHIR_CALL_FUNCTION(&part$$26, "preg_replace", &_33, 2, &_85$$27, &_86$$27, &_84$$27);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&part$$26, &part$$26);
								ZEPHIR_INIT_NVAR(&_85$$27);
								ZVAL_STRING(&_85$$27, "=");
								ZEPHIR_INIT_NVAR(&_86$$27);
								zephir_fast_strpos(&_86$$27, &part$$26, &_85$$27, 0 );
								if (!ZEPHIR_IS_FALSE_IDENTICAL(&_86$$27)) {
									ZVAL_LONG(&_87$$28, 2);
									ZEPHIR_INIT_NVAR(&explodedPart$$28);
									zephir_fast_explode_str(&explodedPart$$28, SL("="), &part$$26, &_87$$28);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CPY_WRT(&explodedPart$$28, &explodedPart$$28);
									ZEPHIR_INIT_NVAR(&_88$$28);
									ZEPHIR_OBS_NVAR(&_89$$28);
									zephir_array_fetch_long(&_89$$28, &explodedPart$$28, 0, PH_NOISY, "phalcon/Http/Request.zep", 1960);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_fast_trim(&_88$$28, &_89$$28, NULL , ZEPHIR_TRIM_BOTH);
									ZEPHIR_INIT_NVAR(&namePart$$28);
									zephir_fast_strtolower(&namePart$$28, &_88$$28);
									ZEPHIR_CPY_WRT(&namePart$$28, &namePart$$28);
									ZEPHIR_INIT_NVAR(&_90$$28);
									ZEPHIR_OBS_NVAR(&_91$$28);
									zephir_array_fetch_long(&_91$$28, &explodedPart$$28, 1, PH_NOISY, "phalcon/Http/Request.zep", 1961);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_fast_trim(&_90$$28, &_91$$28, NULL , ZEPHIR_TRIM_BOTH);
									ZEPHIR_INIT_NVAR(&_92$$28);
									ZVAL_STRING(&_92$$28, "\"");
									ZEPHIR_INIT_NVAR(&valuePart$$28);
									zephir_fast_trim(&valuePart$$28, &_90$$28, &_92$$28, ZEPHIR_TRIM_BOTH);
									ZEPHIR_CPY_WRT(&valuePart$$28, &valuePart$$28);
									zephir_array_update_multi(&headers$$22, &valuePart$$28, SL("zz"), 2, &headerName$$24, &namePart$$28);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									zephir_array_update_multi(&headers$$22, &part$$26, SL("za"), 2, &headerName$$24);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							} ZEND_HASH_FOREACH_END();
							ZEPHIR_INIT_NVAR(&part$$26);
						} else {
							zephir_array_update_zval(&headers$$22, &headerName$$24, &headerValue$$24, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _71$$22, "rewind", &_zephir_call_cache[10]);
					zephir_check_call_status();
					_94$$22 = 1;
					while (1) {
						if (_94$$22) {
							_94$$22 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _71$$22, "next", &_zephir_call_cache[11]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_93$$22, _71$$22, "valid", &_zephir_call_cache[12]);
						zephir_check_call_status();
						if (!zend_is_true(&_93$$22)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&headerPart$$22, _71$$22, "current", &_zephir_call_cache[13]);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_95$$31);
							ZVAL_STRING(&_95$$31, ":");
							ZEPHIR_INIT_NVAR(&_96$$31);
							zephir_fast_strpos(&_96$$31, &headerPart$$22, &_95$$31, 0 );
							if (ZEPHIR_IS_FALSE_IDENTICAL(&_96$$31)) {
								continue;
							}
							ZVAL_LONG(&_97$$31, 2);
							ZEPHIR_INIT_NVAR(&exploded$$31);
							zephir_fast_explode_str(&exploded$$31, SL(":"), &headerPart$$22, &_97$$31);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CPY_WRT(&exploded$$31, &exploded$$31);
							ZEPHIR_INIT_NVAR(&_98$$31);
							ZEPHIR_OBS_NVAR(&_99$$31);
							zephir_array_fetch_long(&_99$$31, &exploded$$31, 0, PH_NOISY, "phalcon/Http/Request.zep", 1947);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_fast_trim(&_98$$31, &_99$$31, NULL , ZEPHIR_TRIM_BOTH);
							ZEPHIR_INIT_NVAR(&headerName$$31);
							zephir_fast_strtolower(&headerName$$31, &_98$$31);
							ZEPHIR_CPY_WRT(&headerName$$31, &headerName$$31);
							ZEPHIR_OBS_NVAR(&_100$$31);
							zephir_array_fetch_long(&_100$$31, &exploded$$31, 1, PH_NOISY, "phalcon/Http/Request.zep", 1948);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&headerValue$$31);
							zephir_fast_trim(&headerValue$$31, &_100$$31, NULL , ZEPHIR_TRIM_BOTH);
							ZEPHIR_CPY_WRT(&headerValue$$31, &headerValue$$31);
							ZEPHIR_INIT_NVAR(&_101$$31);
							ZVAL_STRING(&_101$$31, ";");
							ZEPHIR_INIT_NVAR(&_102$$31);
							zephir_fast_strpos(&_102$$31, &headerValue$$31, &_101$$31, 0 );
							if (!ZEPHIR_IS_FALSE_IDENTICAL(&_102$$31)) {
								ZEPHIR_INIT_NVAR(&explodedHeader$$33);
								zephir_fast_explode_str(&explodedHeader$$33, SL(";"), &headerValue$$31, NULL);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CPY_WRT(&explodedHeader$$33, &explodedHeader$$33);
								if (Z_TYPE_P(&explodedHeader$$33) == IS_STRING) {
									ZEPHIR_INIT_NVAR(&_104$$33);
									zephir_string_to_char_array(&_104$$33, &explodedHeader$$33);
									_103$$33 = &_104$$33;
								} else {
									_103$$33 = &explodedHeader$$33;
								}
								zephir_is_iterable(_103$$33, 0, "phalcon/Http/Request.zep", 1968);
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_103$$33), _105$$33)
								{
									ZEPHIR_INIT_NVAR(&part$$33);
									ZVAL_COPY(&part$$33, _105$$33);
									ZEPHIR_INIT_NVAR(&_106$$34);
									zephir_fast_trim(&_106$$34, &part$$33, NULL , ZEPHIR_TRIM_BOTH);
									ZEPHIR_INIT_NVAR(&_107$$34);
									ZVAL_STRING(&_107$$34, "/\"/");
									ZEPHIR_INIT_NVAR(&_108$$34);
									ZVAL_STRING(&_108$$34, "");
									ZEPHIR_CALL_FUNCTION(&part$$33, "preg_replace", &_33, 2, &_107$$34, &_108$$34, &_106$$34);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&part$$33, &part$$33);
									ZEPHIR_INIT_NVAR(&_107$$34);
									ZVAL_STRING(&_107$$34, "=");
									ZEPHIR_INIT_NVAR(&_108$$34);
									zephir_fast_strpos(&_108$$34, &part$$33, &_107$$34, 0 );
									if (!ZEPHIR_IS_FALSE_IDENTICAL(&_108$$34)) {
										ZVAL_LONG(&_109$$35, 2);
										ZEPHIR_INIT_NVAR(&explodedPart$$35);
										zephir_fast_explode_str(&explodedPart$$35, SL("="), &part$$33, &_109$$35);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CPY_WRT(&explodedPart$$35, &explodedPart$$35);
										ZEPHIR_INIT_NVAR(&_110$$35);
										ZEPHIR_OBS_NVAR(&_111$$35);
										zephir_array_fetch_long(&_111$$35, &explodedPart$$35, 0, PH_NOISY, "phalcon/Http/Request.zep", 1960);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_fast_trim(&_110$$35, &_111$$35, NULL , ZEPHIR_TRIM_BOTH);
										ZEPHIR_INIT_NVAR(&namePart$$35);
										zephir_fast_strtolower(&namePart$$35, &_110$$35);
										ZEPHIR_CPY_WRT(&namePart$$35, &namePart$$35);
										ZEPHIR_INIT_NVAR(&_112$$35);
										ZEPHIR_OBS_NVAR(&_113$$35);
										zephir_array_fetch_long(&_113$$35, &explodedPart$$35, 1, PH_NOISY, "phalcon/Http/Request.zep", 1961);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_fast_trim(&_112$$35, &_113$$35, NULL , ZEPHIR_TRIM_BOTH);
										ZEPHIR_INIT_NVAR(&_114$$35);
										ZVAL_STRING(&_114$$35, "\"");
										ZEPHIR_INIT_NVAR(&valuePart$$35);
										zephir_fast_trim(&valuePart$$35, &_112$$35, &_114$$35, ZEPHIR_TRIM_BOTH);
										ZEPHIR_CPY_WRT(&valuePart$$35, &valuePart$$35);
										zephir_array_update_multi(&headers$$22, &valuePart$$35, SL("zz"), 2, &headerName$$31, &namePart$$35);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} else {
										zephir_array_update_multi(&headers$$22, &part$$33, SL("za"), 2, &headerName$$31);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
								} ZEND_HASH_FOREACH_END();
								ZEPHIR_INIT_NVAR(&part$$33);
							} else {
								zephir_array_update_zval(&headers$$22, &headerName$$31, &headerValue$$31, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
					}
				}
				ZEPHIR_INIT_NVAR(&headerPart$$22);
				ZEPHIR_OBS_NVAR(&disposition$$22);
				_115$$22 = zephir_array_isset_string_fetch(&disposition$$22, &headers$$22, SL("content-disposition"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_115$$22)) {
					ZEPHIR_INIT_NVAR(&disposition$$22);
					array_init(&disposition$$22);
					ZEPHIR_CPY_WRT(&disposition$$22, &disposition$$22);
				}
				ZEPHIR_OBS_NVAR(&dispositionName$$22);
				_116$$22 = zephir_array_isset_string_fetch(&dispositionName$$22, &disposition$$22, SL("name"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_116$$22)) {
					ZEPHIR_INIT_NVAR(&dispositionName$$22);
					ZVAL_STRING(&dispositionName$$22, "");
				}
				ZEPHIR_OBS_NVAR(&_117$$22);
				zephir_array_fetch_long(&_117$$22, &splited$$22, 1, PH_NOISY, "phalcon/Http/Request.zep", 1983);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&dataset, &dispositionName$$22, &_117$$22, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&bodyPart);
	RETURN_CTOR(&dataset);
}

/**
 * Return post data from rawBody, form data, or urlencoded form data
 *
 * @phpstan-param  http_form_data|null $data
 * @phpstan-return http_form_data
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data);
	if (ZEPHIR_IS_EMPTY(data)) {
		ZEPHIR_CALL_METHOD_CACHED(&_0$$3, this_ptr, "isJson", &_zephir_call_cache[0]);
		zephir_check_call_status();
		if (zephir_is_true(&_0$$3)) {
			ZVAL_BOOL(&_6$$4, 1);
			ZEPHIR_CALL_METHOD_CACHED(&result, this_ptr, "getJsonRawBody", &_zephir_call_cache[3], &_6$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "getContentType", &_zephir_call_cache[1]);
			zephir_check_call_status();
			_2$$3 = zephir_is_true(&_1$$3);
			if (_2$$3) {
				ZEPHIR_CALL_METHOD_CACHED(&_3$$3, this_ptr, "getContentType", &_zephir_call_cache[2]);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_4$$3);
				ZVAL_STRING(&_4$$3, "multipart/form-data");
				ZEPHIR_CALL_FUNCTION(&_5$$3, "stripos", NULL, 170, &_3$$3, &_4$$3);
				zephir_check_call_status();
				_2$$3 = !ZEPHIR_IS_FALSE_IDENTICAL(&_5$$3);
			}
			if (_2$$3) {
				ZEPHIR_CALL_METHOD_CACHED(&result, this_ptr, "getFormData", &_zephir_call_cache[4]);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&result);
				array_init(&result);
				ZEPHIR_CALL_METHOD_CACHED(&_7$$6, this_ptr, "getRawBody", &_zephir_call_cache[5]);
				zephir_check_call_status();
				ZEPHIR_MAKE_REF(&result);
				ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 174, &_7$$6, &result);
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

/**
 * Verify if given IP address is trusted
 */
PHP_METHOD(Phalcon_Http_Request, isProxyTrusted)
{
	zend_bool _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval ip_zv, trusted, _0, *_1, _2, *_3, _7, _4$$3, _5$$3, _6$$4, _9$$8, _10$$8, _11$$9;
	zend_string *ip = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ip_zv);
	ZVAL_UNDEF(&trusted);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("trustedProxies", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(ip)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&ip_zv);
	ZVAL_STR_COPY(&ip_zv, ip);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 909, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Http/Request.zep", 2041);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&trusted);
			ZVAL_COPY(&trusted, _3);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "/");
			ZEPHIR_INIT_NVAR(&_5$$3);
			zephir_fast_strpos(&_5$$3, &trusted, &_4$$3, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&_5$$3)) {
				ZEPHIR_CALL_METHOD_CACHED(&_6$$4, this_ptr, "isIpAddressInCIDR", &_zephir_call_cache[0], &ip_zv, &trusted);
				zephir_check_call_status();
				if (zephir_is_true(&_6$$4)) {
					RETURN_MM_BOOL(1);
				}
			} else {
				if (ZEPHIR_IS_IDENTICAL(&ip_zv, &trusted)) {
					RETURN_MM_BOOL(1);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_7, _1, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&trusted, _1, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$8);
				ZVAL_STRING(&_9$$8, "/");
				ZEPHIR_INIT_NVAR(&_10$$8);
				zephir_fast_strpos(&_10$$8, &trusted, &_9$$8, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_10$$8)) {
					ZEPHIR_CALL_METHOD_CACHED(&_11$$9, this_ptr, "isIpAddressInCIDR", &_zephir_call_cache[5], &ip_zv, &trusted);
					zephir_check_call_status();
					if (zephir_is_true(&_11$$9)) {
						RETURN_MM_BOOL(1);
					}
				} else {
					if (ZEPHIR_IS_IDENTICAL(&ip_zv, &trusted)) {
						RETURN_MM_BOOL(1);
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&trusted);
	RETURN_MM_BOOL(0);
}

/**
 * Verify if given IP address is public, eg. not private or reserved IP
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(forwardedIp)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&forwardedIp_zv);
	ZVAL_STR_COPY(&forwardedIp_zv, forwardedIp);
	ZEPHIR_CALL_METHOD_CACHED(&filterService, this_ptr, "getFilterService", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	add_assoc_long_ex(&_1, SL("filter"), (8388608 | 4194304));
	zephir_array_update_string(&_0, SL("ip"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&filtered, &filterService, "sanitize", &_zephir_call_cache[1], &forwardedIp_zv, &_0);
	zephir_check_call_status();
	RETURN_CCTOR(&filtered);
}

/**
 * Helper to build the uploaded files array
 *
 * @phpstan-param  http_uploaded_files $files
 * @phpstan-param  http_uploaded_file  $input
 * @phpstan-return http_uploaded_files
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[0], &input, &key_zv);
		zephir_check_call_status();
		zephir_array_update_zval(&files, &key_zv, &_0$$3, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_http_request_file_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$4, "__construct", &_zephir_call_cache[1], &input, &key_zv);
		zephir_check_call_status();
		zephir_array_append(&files, &_1$$4, PH_SEPARATE, "phalcon/Http/Request.zep", 2077);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&files);
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Http_Request, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Http_Request, setEventsManager)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventsManager, eventsManager_sub, _0, _1, _3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &eventsManager);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "container");
	ZEPHIR_CALL_FUNCTION(&_1, "property_exists", NULL, 7, this_ptr, &_0);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	if (_2) {
		zephir_memory_observe(&_3);
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 908, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_2 = Z_TYPE_P(&_3) != IS_NULL;
	}
	if (_2) {
		zephir_memory_observe(&_4$$3);
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 908, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "eventsManager");
		ZVAL_BOOL(&_6$$3, 1);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$3, "set", &_zephir_call_cache[0], &_5$$3, eventsManager, &_6$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 910, eventsManager);
	ZEPHIR_MM_RESTORE();
}

/**
 * Helper method to fire an event
 * 
 * @throws EventsException
 */
PHP_METHOD(Phalcon_Http_Request, fireManagerEvent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancellable, stopOnFalse, _1$$3;
	zval eventName_zv, *data = NULL, data_sub, *cancellable_param = NULL, *stopOnFalse_param = NULL, __$null, _0, _2$$3, _6$$3, _7$$3, _3$$4, _4$$4, _5$$4;
	zend_string *eventName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(eventName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancellable)
		Z_PARAM_BOOL(stopOnFalse)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		data = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		cancellable_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		stopOnFalse_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&eventName_zv);
	ZVAL_STR_COPY(&eventName_zv, eventName);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!cancellable_param) {
		cancellable = 1;
	} else {
		}
	if (!stopOnFalse_param) {
		stopOnFalse = 0;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 910, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) != IS_NULL) {
		_1$$3 = stopOnFalse;
		if (_1$$3) {
			zephir_memory_observe(&_2$$3);
			zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 910, PH_NOISY_CC);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_1$$3 = zephir_instance_of_ev(&_2$$3, phalcon_events_manager_ce);
		}
		if (_1$$3) {
			zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 910, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (cancellable) {
				ZVAL_BOOL(&_4$$4, 1);
			} else {
				ZVAL_BOOL(&_4$$4, 0);
			}
			ZVAL_BOOL(&_5$$4, 1);
			ZEPHIR_RETURN_CALL_METHOD_CACHED(&_3$$4, "fire", &_zephir_call_cache[0], &eventName_zv, this_ptr, data, &_4$$4, &_5$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_0, 910, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (cancellable) {
			ZVAL_BOOL(&_7$$3, 1);
		} else {
			ZVAL_BOOL(&_7$$3, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD_CACHED(&_6$$3, "fire", &_zephir_call_cache[1], &eventName_zv, this_ptr, data, &_7$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);
}

/**
 * Closes an open file pointer
 *
 * @link https://php.net/manual/en/function.fclose.php
 *
 * @param resource $handle
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Http_Request, phpFclose)
{
	zval *handle, handle_sub;

	ZVAL_UNDEF(&handle_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle);
	RETURN_BOOL(zephir_fclose(handle));
}

/**
 * Gets line from file pointer and parse for CSV fields
 *
 * @param resource $stream
 * @param int      $length
 * @param string   $separator
 * @param string   $enclosure
 * @param string   $escape
 *
 * @return array<array-key, mixed>|false
 *
 * @link https://php.net/manual/en/function.fgetcsv.php
 */
PHP_METHOD(Phalcon_Http_Request, phpFgetCsv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *separator = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *length_param = NULL, separator_zv, *enclosure = NULL, enclosure_sub, *escape = NULL, escape_sub, __$null, _0;

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&enclosure_sub);
	ZVAL_UNDEF(&escape_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_ZVAL(stream)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(length)
		Z_PARAM_STR(separator)
		Z_PARAM_ZVAL_OR_NULL(enclosure)
		Z_PARAM_ZVAL_OR_NULL(escape)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	stream = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 1) {
		length_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 3) {
		enclosure = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		escape = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (!separator) {
		separator = zend_string_init(ZEND_STRL(","), 0);
		zephir_memory_observe(&separator_zv);
		ZVAL_STR(&separator_zv, separator);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	if (!enclosure) {
		enclosure = &enclosure_sub;
		ZEPHIR_CPY_WRT(enclosure, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(enclosure);
	}
	if (!escape) {
		escape = &escape_sub;
		ZEPHIR_CPY_WRT(escape, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(escape);
	}
	if (Z_TYPE_P(enclosure) == IS_NULL) {
		ZEPHIR_INIT_NVAR(enclosure);
		ZVAL_STRING(enclosure, "\"");
	}
	if (Z_TYPE_P(escape) == IS_NULL) {
		ZEPHIR_INIT_NVAR(escape);
		ZVAL_STRING(escape, "\\");
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 44, stream, &_0, &separator_zv, enclosure, escape);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.file-exists.php
 */
PHP_METHOD(Phalcon_Http_Request, phpFileExists)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	RETURN_BOOL((zephir_file_exists(&filename_zv) == SUCCESS));
}

/**
 * @param string        $filename
 * @param bool          $useIncludePath
 * @param resource|null $context
 * @param int           $offset
 * @param int|null      $length
 *
 * @return false|string
 *
 * @link https://php.net/manual/en/function.file-get-contents.php
 */
PHP_METHOD(Phalcon_Http_Request, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long offset, length, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _3, _4, _5;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		context = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		offset_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		length_param = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!offset_param) {
		offset = 0;
	} else {
		}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == (length != 0)) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 45, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_3, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_4, offset);
	ZVAL_LONG(&_5, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 45, &filename_zv, &_3, context, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string   $filename
 * @param mixed    $data
 * @param int      $flags
 * @param resource $context
 *
 * @return false|int
 *
 * @link https://php.net/manual/en/function.file-put-contents.php
 */
PHP_METHOD(Phalcon_Http_Request, phpFilePutContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *data, data_sub, *flags_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		flags_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!flags_param) {
		flags = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 46, &filename_zv, data, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param string        $mode
 * @param bool          $useIncludePath
 * @param resource|null $context
 *
 * @return resource|false
 *
 * @link https://php.net/manual/en/function.fopen.php
 */
PHP_METHOD(Phalcon_Http_Request, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, mode_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL, *mode = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&mode_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	zephir_memory_observe(&mode_zv);
	ZVAL_STR_COPY(&mode_zv, mode);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_BOOL(&_0, (useIncludePath ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 47, &filename_zv, &mode_zv, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Binary-safe file write
 *
 * @link https://php.net/manual/en/function.fwrite.php
 *
 * @param resource $handle
 * @param string   $data
 * @param int|null $length
 *
 * @return false|int
 */
PHP_METHOD(Phalcon_Http_Request, phpFwrite)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zend_string *data = NULL;
	zval *handle, handle_sub, data_zv, *length_param = NULL, _0;

	ZVAL_UNDEF(&handle_sub);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(handle)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handle = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		length_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == (length != 0)) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", &_1, 48, handle, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is a directory
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-dir.php
 */
PHP_METHOD(Phalcon_Http_Request, phpIsDir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_dir", NULL, 49, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is writable
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-writable.php
 */
PHP_METHOD(Phalcon_Http_Request, phpIsWritable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 50, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Makes a directory
 *
 * @param string        $directory
 * @param int           $permissions
 * @param bool          $recursive
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.mkdir.php
 */
PHP_METHOD(Phalcon_Http_Request, phpMkdir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool recursive;
	zend_long permissions, ZEPHIR_LAST_CALL_STATUS;
	zval directory_zv, *permissions_param = NULL, *recursive_param = NULL, *context = NULL, context_sub, __$null, _0, _1;
	zend_string *directory = NULL;

	ZVAL_UNDEF(&directory_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(directory)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(permissions)
		Z_PARAM_BOOL(recursive)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		permissions_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		recursive_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&directory_zv);
	ZVAL_STR_COPY(&directory_zv, directory);
	if (!permissions_param) {
		permissions = 0777;
	} else {
		}
	if (!recursive_param) {
		recursive = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, permissions);
	ZVAL_BOOL(&_1, (recursive ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("mkdir", NULL, 51, &directory_zv, &_0, &_1, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.unlink.php
 */
PHP_METHOD(Phalcon_Http_Request, phpUnlink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *context = NULL, context_sub, __$null;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 52, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
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

