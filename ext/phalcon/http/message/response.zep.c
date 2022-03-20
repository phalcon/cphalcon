
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */
/**
 * PSR-7 Response
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Response)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http\\Message, Response, phalcon, http_message_response, phalcon_http_message_abstractmessage_ce, phalcon_http_message_response_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * Gets the response reason phrase associated with the status code.
	 *
	 * Because a reason phrase is not a required element in a response
	 * status line, the reason phrase value MAY be empty. Implementations MAY
	 * choose to return the default RFC 7231 recommended reason phrase (or
	 * those
	 * listed in the IANA HTTP Status Code Registry) for the response's
	 * status code.
	 *
	 * @see http://tools.ietf.org/html/rfc7231#section-6
	 * @see http://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_response_ce, SL("reasonPhrase"), "", ZEND_ACC_PROTECTED);
	/**
	 * Gets the response status code.
	 *
	 * The status code is a 3-digit integer result code of the server's attempt
	 * to understand and satisfy the request.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_http_message_response_ce, SL("statusCode"), 200, ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_http_message_response_ce, 1, zephir_get_internal_ce(SL("psrext\\http\\message\\responseinterface")));
	zend_class_implements(phalcon_http_message_response_ce, 1, phalcon_http_message_responsestatuscodeinterface_ce);
	return SUCCESS;
}

/**
 * Gets the response reason phrase associated with the status code.
 *
 *
 * Because a reason phrase is not a required element in a response
 * status line, the reason phrase value MAY be empty. Implementations MAY
 * choose to return the default RFC 7231 recommended reason phrase (or
 * those
 * listed in the IANA HTTP Status Code Registry) for the response's
 * status code.
 *
 */
PHP_METHOD(Phalcon_Http_Message_Response, getReasonPhrase)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "reasonPhrase");
}

/**
 * Gets the response status code.
 *
 *
 * The status code is a 3-digit integer result code of the server's attempt
 * to understand and satisfy the request.
 *
 */
PHP_METHOD(Phalcon_Http_Message_Response, getStatusCode)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "statusCode");
}

/**
 * Response constructor.
 *
 * @param string $body
 * @param int    $code
 * @param array  $headers
 */
PHP_METHOD(Phalcon_Http_Message_Response, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval headers;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval *body = NULL, body_sub, *code_param = NULL, *headers_param = NULL, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&headers);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(body)
		Z_PARAM_LONG(code)
		Z_PARAM_ARRAY(headers)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &body, &code_param, &headers_param);
	if (!body) {
		body = &body_sub;
		ZEPHIR_INIT_VAR(body);
		ZVAL_STRING(body, "php://memory");
	}
	if (!code_param) {
		code = 200;
	} else {
		code = zephir_get_intval(code_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	ZVAL_LONG(&_0, code);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcode", NULL, 357, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "processheaders", NULL, 355, &headers);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("headers"), &_1);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "w+b");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "processbody", NULL, 37, body, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("body"), &_2);
	ZEPHIR_MM_RESTORE();
}

/**
 * Return an instance with the specified status code and, optionally,
 * reason phrase.
 *
 * If no reason phrase is specified, implementations MAY choose to default
 * to the RFC 7231 or IANA recommended reason phrase for the response's
 * status code.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * updated status and reason phrase.
 *
 * @see http://tools.ietf.org/html/rfc7231#section-6
 * @see http://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml
 *
 * @param int    $code
 * @param string $reasonPhrase
 *
 * @return Response
 */
PHP_METHOD(Phalcon_Http_Message_Response, withStatus)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, code_sub, *reasonPhrase = NULL, reasonPhrase_sub, newInstance;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&reasonPhrase_sub);
	ZVAL_UNDEF(&newInstance);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(code)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(reasonPhrase)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &code, &reasonPhrase);
	if (!reasonPhrase) {
		reasonPhrase = &reasonPhrase_sub;
		ZEPHIR_INIT_VAR(reasonPhrase);
		ZVAL_STRING(reasonPhrase, "");
	}


	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, &newInstance, "processcode", NULL, 0, code, reasonPhrase);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);
}

/**
 * Returns the list of status codes available
 */
PHP_METHOD(Phalcon_Http_Message_Response, getPhrases)
{
	zval *this_ptr = getThis();



	zephir_create_array(return_value, 89, 0);
	add_index_stringl(return_value, 100, SL("Continue"));
	add_index_stringl(return_value, 101, SL("Switching Protocols"));
	add_index_stringl(return_value, 102, SL("Processing"));
	add_index_stringl(return_value, 103, SL("Early Hints"));
	add_index_stringl(return_value, 200, SL("OK"));
	add_index_stringl(return_value, 201, SL("Created"));
	add_index_stringl(return_value, 202, SL("Accepted"));
	add_index_stringl(return_value, 203, SL("Non-Authoritative Information"));
	add_index_stringl(return_value, 204, SL("No Content"));
	add_index_stringl(return_value, 205, SL("Reset Content"));
	add_index_stringl(return_value, 206, SL("Partial Content"));
	add_index_stringl(return_value, 207, SL("Multi-status"));
	add_index_stringl(return_value, 208, SL("Already Reported"));
	add_index_stringl(return_value, 226, SL("IM Used"));
	add_index_stringl(return_value, 300, SL("Multiple Choices"));
	add_index_stringl(return_value, 301, SL("Moved Permanently"));
	add_index_stringl(return_value, 302, SL("Found"));
	add_index_stringl(return_value, 303, SL("See Other"));
	add_index_stringl(return_value, 304, SL("Not Modified"));
	add_index_stringl(return_value, 305, SL("Use Proxy"));
	add_index_stringl(return_value, 306, SL("Switch Proxy"));
	add_index_stringl(return_value, 307, SL("Temporary Redirect"));
	add_index_stringl(return_value, 308, SL("Permanent Redirect"));
	add_index_stringl(return_value, 400, SL("Bad Request"));
	add_index_stringl(return_value, 401, SL("Unauthorized"));
	add_index_stringl(return_value, 402, SL("Payment Required"));
	add_index_stringl(return_value, 403, SL("Forbidden"));
	add_index_stringl(return_value, 404, SL("Not Found"));
	add_index_stringl(return_value, 405, SL("Method Not Allowed"));
	add_index_stringl(return_value, 406, SL("Not Acceptable"));
	add_index_stringl(return_value, 407, SL("Proxy Authentication Required"));
	add_index_stringl(return_value, 408, SL("Request Time-out"));
	add_index_stringl(return_value, 409, SL("Conflict"));
	add_index_stringl(return_value, 410, SL("Gone"));
	add_index_stringl(return_value, 411, SL("Length Required"));
	add_index_stringl(return_value, 412, SL("Precondition Failed"));
	add_index_stringl(return_value, 413, SL("Request Entity Too Large"));
	add_index_stringl(return_value, 414, SL("Request-URI Too Large"));
	add_index_stringl(return_value, 415, SL("Unsupported Media Type"));
	add_index_stringl(return_value, 416, SL("Requested range not satisfiable"));
	add_index_stringl(return_value, 417, SL("Expectation Failed"));
	add_index_stringl(return_value, 418, SL("I'm a teapot"));
	add_index_stringl(return_value, 421, SL("Misdirected Request"));
	add_index_stringl(return_value, 422, SL("Unprocessable Entity"));
	add_index_stringl(return_value, 423, SL("Locked"));
	add_index_stringl(return_value, 424, SL("Failed Dependency"));
	add_index_stringl(return_value, 425, SL("Unordered Collection"));
	add_index_stringl(return_value, 426, SL("Upgrade Required"));
	add_index_stringl(return_value, 428, SL("Precondition Required"));
	add_index_stringl(return_value, 429, SL("Too Many Requests"));
	add_index_stringl(return_value, 431, SL("Request Header Fields Too Large"));
	add_index_stringl(return_value, 451, SL("Unavailable For Legal Reasons"));
	add_index_stringl(return_value, 500, SL("Internal Server Error"));
	add_index_stringl(return_value, 501, SL("Not Implemented"));
	add_index_stringl(return_value, 502, SL("Bad Gateway"));
	add_index_stringl(return_value, 503, SL("Service Unavailable"));
	add_index_stringl(return_value, 504, SL("Gateway Time-out"));
	add_index_stringl(return_value, 505, SL("HTTP Version not supported"));
	add_index_stringl(return_value, 506, SL("Variant Also Negotiates"));
	add_index_stringl(return_value, 507, SL("Insufficient Storage"));
	add_index_stringl(return_value, 508, SL("Loop Detected"));
	add_index_stringl(return_value, 510, SL("Not Extended"));
	add_index_stringl(return_value, 511, SL("Network Authentication Required"));
	add_index_stringl(return_value, 218, SL("This is fine"));
	add_index_stringl(return_value, 419, SL("Page Expired"));
	add_index_stringl(return_value, 420, SL("Method Failure"));
	add_index_stringl(return_value, 440, SL("Login Time-out"));
	add_index_stringl(return_value, 444, SL("No Response"));
	add_index_stringl(return_value, 449, SL("Retry With"));
	add_index_stringl(return_value, 450, SL("Blocked by Windows Parental Controls (Microsoft)"));
	add_index_stringl(return_value, 494, SL("Request header too large"));
	add_index_stringl(return_value, 495, SL("SSL Certificate Error"));
	add_index_stringl(return_value, 496, SL("SSL Certificate Required"));
	add_index_stringl(return_value, 497, SL("HTTP Request Sent to HTTPS Port"));
	add_index_stringl(return_value, 498, SL("Invalid Token (Esri)"));
	add_index_stringl(return_value, 499, SL("Client Closed Request"));
	add_index_stringl(return_value, 509, SL("Bandwidth Limit Exceeded"));
	add_index_stringl(return_value, 520, SL("Unknown Error"));
	add_index_stringl(return_value, 521, SL("Web Server Is Down"));
	add_index_stringl(return_value, 522, SL("Connection Timed Out"));
	add_index_stringl(return_value, 523, SL("Origin Is Unreachable"));
	add_index_stringl(return_value, 524, SL("A Timeout Occurred"));
	add_index_stringl(return_value, 525, SL("SSL Handshake Failed"));
	add_index_stringl(return_value, 526, SL("Invalid SSL Certificate"));
	add_index_stringl(return_value, 527, SL("Railgun Error"));
	add_index_stringl(return_value, 530, SL("Origin DNS Error"));
	add_index_stringl(return_value, 598, SL("Network read timeout error"));
	add_index_stringl(return_value, 599, SL("Network Connect Timeout Error"));
	return;
}

/**
 * Set a valid status code and phrase
 *
 * @param mixed $code
 * @param mixed $phrase
 */
PHP_METHOD(Phalcon_Http_Message_Response, processCode)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _0;
	zval *code = NULL, code_sub, *phrase = NULL, phrase_sub, phrases, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&phrase_sub);
	ZVAL_UNDEF(&phrases);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(code)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(phrase)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &code, &phrase);
	ZEPHIR_SEPARATE_PARAM(code);
	if (!phrase) {
		phrase = &phrase_sub;
		ZEPHIR_INIT_VAR(phrase);
		ZVAL_STRING(phrase, "");
	} else {
		ZEPHIR_SEPARATE_PARAM(phrase);
	}


	ZEPHIR_CALL_METHOD(&phrases, this_ptr, "getphrases", NULL, 358);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcodetype", NULL, 359, code);
	zephir_check_call_status();
	_0 = zephir_get_intval(code);
	ZEPHIR_INIT_NVAR(code);
	ZVAL_LONG(code, _0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcodevalue", NULL, 360, code);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(phrase) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Invalid response reason", "phalcon/Http/Message/Response.zep", 225);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	_2 = ZEPHIR_IS_IDENTICAL(&_1, phrase);
	if (_2) {
		_2 = zephir_array_isset(&phrases, code);
	}
	if (EXPECTED(_2)) {
		ZEPHIR_OBS_NVAR(phrase);
		zephir_array_fetch(phrase, &phrases, code, PH_NOISY, "phalcon/Http/Message/Response.zep", 229);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("statusCode"), code);
	zephir_update_property_zval(this_ptr, ZEND_STRL("reasonPhrase"), phrase);
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks if a code is integer or string
 *
 * @param mixed $code
 */
PHP_METHOD(Phalcon_Http_Message_Response, checkCodeType)
{
	zend_bool _0;
	zval *code, code_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(code)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &code);


	_0 = Z_TYPE_P(code) != IS_LONG;
	if (_0) {
		_0 = Z_TYPE_P(code) != IS_STRING;
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_http_message_exception_invalidargumentexception_ce, "Invalid status code; it must be an integer or string", "phalcon/Http/Message/Response.zep", 246);
		return;
	}
}

/**
 * Checks if a code is integer or string
 *
 * @param int $code
 */
PHP_METHOD(Phalcon_Http_Message_Response, checkCodeValue)
{
	zval _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *code_param = NULL, _0, _1, _2, _3, _4$$3, _5$$3;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(code)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code_param);
	code = zephir_get_intval(code_param);


	ZVAL_LONG(&_1, code);
	ZVAL_LONG(&_2, 100);
	ZVAL_LONG(&_3, 599);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isbetween", NULL, 361, &_1, &_2, &_3);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, phalcon_http_message_exception_invalidargumentexception_ce);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_LONG(&_5$$3, code);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SVS(&_6$$3, "Invalid status code '", &_5$$3, "', (allowed values 100-599)");
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 40, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/Http/Message/Response.zep", 260);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @todo Remove this when we get traits
 */
PHP_METHOD(Phalcon_Http_Message_Response, isBetween)
{
	zend_bool _0;
	zval *value_param = NULL, *from_param = NULL, *to_param = NULL;
	zend_long value, from, to;
	zval *this_ptr = getThis();

#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(value)
		Z_PARAM_LONG(from)
		Z_PARAM_LONG(to)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(3, 0, &value_param, &from_param, &to_param);
	value = zephir_get_intval(value_param);
	from = zephir_get_intval(from_param);
	to = zephir_get_intval(to_param);


	_0 = value >= from;
	if (_0) {
		_0 = value <= to;
	}
	RETURN_BOOL(_0);
}

