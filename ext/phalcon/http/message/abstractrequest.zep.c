
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */
/**
 * Request methods
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_AbstractRequest)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http\\Message, AbstractRequest, phalcon, http_message_abstractrequest, phalcon_http_message_abstractmessage_ce, phalcon_http_message_abstractrequest_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Retrieves the HTTP method of the request.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_abstractrequest_ce, SL("method"), "GET", ZEND_ACC_PROTECTED);
	/**
	 * The request-target, if it has been provided or calculated.
	 *
	 * @var null|string
	 */
	zend_declare_property_null(phalcon_http_message_abstractrequest_ce, SL("requestTarget"), ZEND_ACC_PROTECTED);
	/**
	 * Retrieves the URI instance.
	 *
	 * This method MUST return a UriInterface instance.
	 *
	 * @see http://tools.ietf.org/html/rfc3986#section-4.3
	 *
	 * @var UriInterface
	 */
	zend_declare_property_null(phalcon_http_message_abstractrequest_ce, SL("uri"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_http_message_abstractrequest_ce, 1, phalcon_http_message_requestmethodinterface_ce);
	return SUCCESS;
}

/**
 * Retrieves the HTTP method of the request.
 */
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, getMethod)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "method");
}

/**
 * Retrieves the URI instance.
 *
 *
 * This method MUST return a UriInterface instance.
 *
 */
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, getUri)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "uri");
}

/**
 * Retrieves the message's request target.
 *
 * Retrieves the message's request-target either as it will appear (for
 * clients), as it appeared at request (for servers), or as it was
 * specified for the instance (see withRequestTarget()).
 *
 * In most cases, this will be the origin-form of the composed URI, unless a
 * value was provided to the concrete implementation (see
 * withRequestTarget() below).
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, getRequestTarget)
{
	zval requestTarget, _0, _1$$3, _2$$3, _3$$3, _4$$4, _5$$4, _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requestTarget);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("requestTarget"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&requestTarget, &_0);
	if (UNEXPECTED(Z_TYPE_P(&requestTarget) == IS_NULL)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&requestTarget, &_1$$3, "getpath", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3$$3, &_2$$3, "getquery", NULL, 0);
		zephir_check_call_status();
		if (UNEXPECTED(!(ZEPHIR_IS_EMPTY(&_3$$3)))) {
			zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_5$$4, &_4$$4, "getquery", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_6$$4);
			ZEPHIR_CONCAT_SV(&_6$$4, "?", &_5$$4);
			zephir_concat_self(&requestTarget, &_6$$4);
		}
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&requestTarget))) {
			ZEPHIR_INIT_NVAR(&requestTarget);
			ZVAL_STRING(&requestTarget, "/");
		}
	}
	RETURN_CCTOR(&requestTarget);
}

/**
 * Return an instance with the provided HTTP method.
 *
 * While HTTP method names are typically all uppercase characters, HTTP
 * method names are case-sensitive and thus implementations SHOULD NOT
 * modify the given string.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * changed request method.
 *
 * @param string $method
 *
 * @return static
 * @throws InvalidArgumentException for invalid HTTP methods.
 */
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, withMethod)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processmethod", NULL, 112, method);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "method");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 20, method, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return an instance with the specific request-target.
 *
 * If the request needs a non-origin-form request-target — e.g., for
 * specifying an absolute-form, authority-form, or asterisk-form —
 * this method may be used to create an instance with the specified
 * request-target, verbatim.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * changed request target.
 *
 * @see http://tools.ietf.org/html/rfc7230#section-5.3 (for the various
 *     request-target forms allowed in request messages)
 *
 * @param mixed $requestTarget
 *
 * @return static
 */
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, withRequestTarget)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *requestTarget, requestTarget_sub, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requestTarget_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(requestTarget)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &requestTarget);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/\\s/");
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/\\s/");
	zephir_preg_match(&_2, &_3, requestTarget, &_0, 0, 0 , 0 );
	if (UNEXPECTED(zephir_is_true(&_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Invalid request target: cannot contain whitespace", "phalcon/Http/Message/AbstractRequest.zep", 131);
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "requestTarget");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 20, requestTarget, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns an instance with the provided URI.
 *
 * This method MUST update the Host header of the returned request by
 * default if the URI contains a host component. If the URI does not
 * contain a host component, any pre-existing Host header MUST be carried
 * over to the returned request.
 *
 * You can opt-in to preserving the original state of the Host header by
 * setting `$preserveHost` to `true`. When `$preserveHost` is set to
 * `true`, this method interacts with the Host header in the following
 * ways:
 *
 * - If the Host header is missing or empty, and the new URI contains
 *   a host component, this method MUST update the Host header in the
 *   returned request.
 * - If the Host header is missing or empty, and the new URI does not
 * contain a host component, this method MUST NOT update the Host header in
 * the returned request.
 * - If a Host header is present and non-empty, this method MUST NOT update
 *   the Host header in the returned request.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * new UriInterface instance.
 *
 * @see http://tools.ietf.org/html/rfc3986#section-4.3
 *
 * @param UriInterface $uri
 * @param bool         $preserveHost
 *
 * @return static
 */
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, withUri)
{
	double _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri, uri_sub, *preserveHost = NULL, preserveHost_sub, __$false, headers, newInstance, _1, _2, _3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&preserveHost_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(uri, zephir_get_internal_ce(SL("psr\\http\\message\\uriinterface")))
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(preserveHost)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &uri, &preserveHost);
	if (!preserveHost) {
		preserveHost = &preserveHost_sub;
		ZEPHIR_CPY_WRT(preserveHost, &__$false);
	} else {
		ZEPHIR_SEPARATE_PARAM(preserveHost);
	}


	_0 = zephir_get_boolval(preserveHost);
	ZEPHIR_INIT_NVAR(preserveHost);
	ZVAL_BOOL(preserveHost, _0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	if (zephir_clone(&_2, &_1) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&headers, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "uri");
	ZEPHIR_CALL_METHOD(&newInstance, this_ptr, "cloneinstance", NULL, 20, uri, &_3);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(preserveHost))) {
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "checkheaderhost", NULL, 44, &headers);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&headers, &_4$$3);
		zephir_update_property_zval(&newInstance, ZEND_STRL("headers"), &headers);
	}
	RETURN_CCTOR(&newInstance);
}

/**
 * Check the method
 *
 * @param string $method
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, processMethod)
{
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, method_sub, methods, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &method);
	if (!method) {
		method = &method_sub;
		ZEPHIR_INIT_VAR(method);
		ZVAL_STRING(method, "");
	}


	ZEPHIR_INIT_VAR(&methods);
	zephir_create_array(&methods, 10, 0);
	add_assoc_long_ex(&methods, SL("CONNECT"), 1);
	add_assoc_long_ex(&methods, SL("DELETE"), 1);
	add_assoc_long_ex(&methods, SL("GET"), 1);
	add_assoc_long_ex(&methods, SL("HEAD"), 1);
	add_assoc_long_ex(&methods, SL("OPTIONS"), 1);
	add_assoc_long_ex(&methods, SL("PATCH"), 1);
	add_assoc_long_ex(&methods, SL("POST"), 1);
	add_assoc_long_ex(&methods, SL("PURGE"), 1);
	add_assoc_long_ex(&methods, SL("PUT"), 1);
	add_assoc_long_ex(&methods, SL("TRACE"), 1);
	_0 = !(ZEPHIR_IS_EMPTY(method));
	if (_0) {
		_0 = Z_TYPE_P(method) == IS_STRING;
	}
	_1 = _0;
	if (_1) {
		_1 = zephir_array_isset(&methods, method);
	}
	if (UNEXPECTED(!(_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_http_message_exception_invalidargumentexception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Invalid or unsupported method ", method);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 39, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Http/Message/AbstractRequest.zep", 216);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(method, 1, 0);
	RETURN_MM();
}

/**
 * Sets a valid Uri
 *
 * @param UriInterface|string|null $uri
 *
 * @return UriInterface
 */
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, processUri)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri, uri_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(uri)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri);


	_0 = Z_TYPE_P(uri) == IS_OBJECT;
	if (_0) {
		_0 = zephir_is_instance_of(uri, SL("Psr\\Http\\Message\\UriInterface"));
	}
	if (UNEXPECTED(_0)) {
		RETVAL_ZVAL(uri, 1, 0);
		RETURN_MM();
	}
	if (EXPECTED(Z_TYPE_P(uri) == IS_STRING)) {
		object_init_ex(return_value, phalcon_http_message_uri_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 113, uri);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(uri) == IS_NULL) {
		object_init_ex(return_value, phalcon_http_message_uri_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 113);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Invalid uri passed as a parameter", "phalcon/Http/Message/AbstractRequest.zep", 245);
	return;
}

