
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Representation of an outgoing, server-side response.
 *
 * Per the HTTP specification, this interface includes properties for
 * each of the following:
 *
 * - Protocol version
 * - Status code and reason phrase
 * - Headers
 * - Message body
 *
 * Responses are considered immutable; all methods that might change state MUST
 * be implemented such that they retain the internal state of the current
 * message and return an instance that contains the changed state.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Response) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, Response, phalcon, http_message_response, phalcon_http_message_response_method_entry, 0);

	/**
	 * @var <StreamInterface>
	 */
	zend_declare_property_null(phalcon_http_message_response_ce, SL("body"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_http_message_response_ce, SL("code"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_message_response_ce, SL("headers"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_response_ce, SL("protocol"), "1.1", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_response_ce, SL("reason"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	phalcon_http_message_response_ce->create_object = zephir_init_properties_Phalcon_Http_Message_Response;

	zend_class_implements(phalcon_http_message_response_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\responseinterface")));
	return SUCCESS;

}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Http_Message_Response, __construct) {

	zval headers;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval *body = NULL, body_sub, *code_param = NULL, *headers_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&headers);

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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcode", NULL, 218, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the body of the message.
 *
 * @return StreamInterface Returns the body as a stream.
 */
PHP_METHOD(Phalcon_Http_Message_Response, getBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "body");

}

/**
 * Retrieves a message header value by the given case-insensitive name.
 *
 * This method returns an array of all the header values of the given
 * case-insensitive header name.
 *
 * If the header does not appear in the message, this method MUST return an
 * empty array.
 *
 * @param string $name Case-insensitive header field name.
 * @return string[] An array of string values as provided for the given
 *    header. If the header does not appear in the message, this method MUST
 *    return an empty array.
 */
PHP_METHOD(Phalcon_Http_Message_Response, getHeader) {

	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);

	zephir_fetch_params(0, 1, 0, &name);




}

/**
 * Retrieves a comma-separated string of the values for a single header.
 *
 * This method returns all of the header values of the given
 * case-insensitive header name as a string concatenated together using
 * a comma.
 *
 * NOTE: Not all header values may be appropriately represented using
 * comma concatenation. For such headers, use getHeader() instead
 * and supply your own delimiter when concatenating.
 *
 * If the header does not appear in the message, this method MUST return
 * an empty string.
 *
 * @param string $name Case-insensitive header field name.
 * @return string A string of values as provided for the given header
 *    concatenated together using a comma. If the header does not appear in
 *    the message, this method MUST return an empty string.
 */
PHP_METHOD(Phalcon_Http_Message_Response, getHeaderLine) {

	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);

	zephir_fetch_params(0, 1, 0, &name);




}

/**
 * Retrieves all message header values.
 *
 * The keys represent the header name as it will be sent over the wire, and
 * each value is an array of strings associated with the header.
 *
 *     // Represent the headers as a string
 *     foreach ($message->getHeaders() as $name => $values) {
 *         echo $name . ': ' . implode(', ', $values);
 *     }
 *
 *     // Emit headers iteratively:
 *     foreach ($message->getHeaders() as $name => $values) {
 *         foreach ($values as $value) {
 *             header(sprintf('%s: %s', $name, $value), false);
 *         }
 *     }
 *
 * While header names are not case-sensitive, getHeaders() will preserve the
 * exact case in which headers were originally specified.
 *
 * @return string[][] Returns an associative array of the message's headers.
 *     Each key MUST be a header name, and each value MUST be an array of
 *     strings for that header.
 */
PHP_METHOD(Phalcon_Http_Message_Response, getHeaders) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "headers");

}

/**
 * Retrieves the HTTP protocol version as a string.
 *
 * The string MUST contain only the HTTP version number (e.g., "1.1", "1.0").
 *
 * @return string HTTP protocol version.
 */
PHP_METHOD(Phalcon_Http_Message_Response, getProtocolVersion) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "protocol");

}

/**
 * Gets the response reason phrase associated with the status code.
 *
 * Because a reason phrase is not a required element in a response
 * status line, the reason phrase value MAY be empty. Implementations MAY
 * choose to return the default RFC 7231 recommended reason phrase (or those
 * listed in the IANA HTTP Status Code Registry) for the response's
 * status code.
 *
 * @see http://tools.ietf.org/html/rfc7231#section-6
 * @see http://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml
 * @return string Reason phrase; must return an empty string if none present.
 */
PHP_METHOD(Phalcon_Http_Message_Response, getReasonPhrase) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "reason");

}

/**
 * Gets the response status code.
 *
 * The status code is a 3-digit integer result code of the server's attempt
 * to understand and satisfy the request.
 *
 * @return int Status code.
 */
PHP_METHOD(Phalcon_Http_Message_Response, getStatusCode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "code");

}

/**
 * Checks if a header exists by the given case-insensitive name.
 *
 * @param string $name Case-insensitive header field name.
 * @return bool Returns true if any header names match the given header
 *     name using a case-insensitive string comparison. Returns false if
 *     no matching header name is found in the message.
 */
PHP_METHOD(Phalcon_Http_Message_Response, hasHeader) {

	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);

	zephir_fetch_params(0, 1, 0, &name);




}

/**
 * Return an instance with the specified header appended with the given value.
 *
 * Existing values for the specified header will be maintained. The new
 * value(s) will be appended to the existing list. If the header did not
 * exist previously, it will be added.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * new header and/or value.
 *
 * @param string $name Case-insensitive header field name to add.
 * @param string|string[] $value Header value(s).
 * @return static
 * @throws \InvalidArgumentException for invalid header names.
 * @throws \InvalidArgumentException for invalid header values.
 */
PHP_METHOD(Phalcon_Http_Message_Response, withAddedHeader) {

	zval *name, name_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 2, 0, &name, &value);




}

/**
 * Return an instance with the specified message body.
 *
 * The body MUST be a StreamInterface object.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return a new instance that has the
 * new body stream.
 */
PHP_METHOD(Phalcon_Http_Message_Response, withBody) {

	zval *body, body_sub, newInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &body);



	zephir_read_property(&_0, this_ptr, SL("body"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_IDENTICAL(body, &_0)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&newInstance, SL("body"), body);
	RETURN_CCTOR(&newInstance);

}

/**
 * Return an instance with the provided value replacing the specified header.
 *
 * While header names are case-insensitive, the casing of the header will
 * be preserved by this function, and returned from getHeaders().
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * new and/or updated header and value.
 *
 * @param string $name Case-insensitive header field name.
 * @param string|string[] $value Header value(s).
 * @return static
 * @throws \InvalidArgumentException for invalid header names or values.
 */
PHP_METHOD(Phalcon_Http_Message_Response, withHeader) {

	zval *name, name_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 2, 0, &name, &value);




}

/**
 * Return an instance with the specified HTTP protocol version.
 *
 * The version string MUST contain only the HTTP version number (e.g.,
 * "1.1", "1.0").
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * new protocol version.
 *
 * @param string $version HTTP protocol version
 * @return static
 */
PHP_METHOD(Phalcon_Http_Message_Response, withProtocolVersion) {

	zval *version, version_sub, newInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version);



	zephir_read_property(&_0, this_ptr, SL("protocol"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_IDENTICAL(version, &_0)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&newInstance, SL("protocol"), version);
	RETURN_CCTOR(&newInstance);

}

/**
 * Return an instance with the specified status code and, optionally, reason phrase.
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
 * @param int $code The 3-digit integer result code to set.
 * @param string $reasonPhrase The reason phrase to use with the
 *     provided status code; if none is provided, implementations MAY
 *     use the defaults as suggested in the HTTP specification.
 * @return static
 * @throws \InvalidArgumentException For invalid status code arguments.
 */
PHP_METHOD(Phalcon_Http_Message_Response, withStatus) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, code_sub, *reasonPhrase = NULL, reasonPhrase_sub, newInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&reasonPhrase_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &code, &reasonPhrase);

	if (!reasonPhrase) {
		reasonPhrase = &reasonPhrase_sub;
		ZEPHIR_INIT_VAR(reasonPhrase);
		ZVAL_STRING(reasonPhrase, "");
	}


	zephir_read_property(&_0, this_ptr, SL("code"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_IDENTICAL(code, &_0)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, &newInstance, "processcode", NULL, 0, code, reasonPhrase);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);

}

/**
 * Return an instance without the specified header.
 *
 * Header resolution MUST be done without case-sensitivity.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that removes
 * the named header.
 *
 * @param string $name Case-insensitive header field name to remove.
 * @return static
 */
PHP_METHOD(Phalcon_Http_Message_Response, withoutHeader) {

	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);

	zephir_fetch_params(0, 1, 0, &name);




}

/**
 * Returns the list of status codes available
 */
PHP_METHOD(Phalcon_Http_Message_Response, getPhrases) {

	zval *this_ptr = getThis();


	zephir_create_array(return_value, 97, 0 TSRMLS_CC);
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
	add_index_stringl(return_value, 218, SL("This is fine"));
	add_index_stringl(return_value, 419, SL("Page Expired"));
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
	add_index_stringl(return_value, 420, SL("Method Failure"));
	add_index_stringl(return_value, 420, SL("Enhance Your Calm"));
	add_index_stringl(return_value, 421, SL("Misdirected Request"));
	add_index_stringl(return_value, 422, SL("Unprocessable Entity"));
	add_index_stringl(return_value, 423, SL("Locked"));
	add_index_stringl(return_value, 424, SL("Failed Dependency"));
	add_index_stringl(return_value, 425, SL("Unordered Collection"));
	add_index_stringl(return_value, 426, SL("Upgrade Required"));
	add_index_stringl(return_value, 428, SL("Precondition Required"));
	add_index_stringl(return_value, 429, SL("Too Many Requests"));
	add_index_stringl(return_value, 431, SL("Request Header Fields Too Large"));
	add_index_stringl(return_value, 440, SL("Login Time-out"));
	add_index_stringl(return_value, 444, SL("No Response"));
	add_index_stringl(return_value, 449, SL("Retry With"));
	add_index_stringl(return_value, 451, SL("Redirect"));
	add_index_stringl(return_value, 494, SL("Request header too large"));
	add_index_stringl(return_value, 495, SL("SSL Certificate Error"));
	add_index_stringl(return_value, 496, SL("SSL Certificate Required"));
	add_index_stringl(return_value, 497, SL("HTTP Request Sent to HTTPS Port"));
	add_index_stringl(return_value, 499, SL("Client Closed Request"));
	add_index_stringl(return_value, 450, SL("Blocked by Windows Parental Controls (Microsoft)"));
	add_index_stringl(return_value, 451, SL("Unavailable For Legal Reasons"));
	add_index_stringl(return_value, 498, SL("Invalid Token (Esri)"));
	add_index_stringl(return_value, 499, SL("Client Closed Request"));
	add_index_stringl(return_value, 500, SL("Internal Server Error"));
	add_index_stringl(return_value, 501, SL("Not Implemented"));
	add_index_stringl(return_value, 502, SL("Bad Gateway"));
	add_index_stringl(return_value, 503, SL("Service Unavailable"));
	add_index_stringl(return_value, 504, SL("Gateway Time-out"));
	add_index_stringl(return_value, 505, SL("HTTP Version not supported"));
	add_index_stringl(return_value, 506, SL("Variant Also Negotiates"));
	add_index_stringl(return_value, 507, SL("Insufficient Storage"));
	add_index_stringl(return_value, 508, SL("Loop Detected"));
	add_index_stringl(return_value, 509, SL("Bandwidth Limit Exceeded"));
	add_index_stringl(return_value, 510, SL("Not Extended"));
	add_index_stringl(return_value, 511, SL("Network Authentication Required"));
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
 */
PHP_METHOD(Phalcon_Http_Message_Response, processCode) {

	zend_bool _0, _2, _3, _7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, code_sub, *phrase = NULL, phrase_sub, keys, max, min, phrases, _1, _6, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&phrase_sub);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&max);
	ZVAL_UNDEF(&min);
	ZVAL_UNDEF(&phrases);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &code, &phrase);

	if (!phrase) {
		phrase = &phrase_sub;
		ZEPHIR_INIT_VAR(phrase);
		ZVAL_STRING(phrase, "");
	} else {
		ZEPHIR_SEPARATE_PARAM(phrase);
	}


	ZEPHIR_CALL_METHOD(&phrases, this_ptr, "getphrases", NULL, 219);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&keys);
	zephir_array_keys(&keys, &phrases TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&min, "min", NULL, 220, &keys);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&max, "max", NULL, 63, &keys);
	zephir_check_call_status();
	_0 = 1 != zephir_is_numeric(code);
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_float", NULL, 171, code);
		zephir_check_call_status();
		_0 = ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	}
	_2 = _0;
	if (!(_2)) {
		_2 = ZEPHIR_LT(code, &min);
	}
	_3 = _2;
	if (!(_3)) {
		_3 = ZEPHIR_GT(code, &max);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_SVSVSVS(&_5$$3, "Invalid status code '", code, "', (allowed values ", &min, "-", &max, ")");
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 221, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/http/message/response.zep", 480 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1 != Z_TYPE_P(phrase) == IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid response reason", "phalcon/http/message/response.zep", 484);
		return;
	}
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "");
	_7 = ZEPHIR_IS_IDENTICAL(&_6, phrase);
	if (_7) {
		_7 = 1 == zephir_array_isset(&phrases, code);
	}
	if (_7) {
		ZEPHIR_OBS_NVAR(phrase);
		zephir_array_fetch(phrase, &phrases, code, PH_NOISY, "phalcon/http/message/response.zep", 488 TSRMLS_CC);
	}
	zephir_update_property_zval(this_ptr, SL("code"), code);
	zephir_update_property_zval(this_ptr, SL("reason"), phrase);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Http_Message_Response, processStream) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval mode;
	zval *body = NULL, body_sub, *mode_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&mode);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &body, &mode_param);

	zephir_get_strval(&mode, mode_param);
	if (!body) {
		body = &body_sub;
		ZEPHIR_INIT_VAR(body);
		ZVAL_STRING(body, "php://memody");
	}


	if (zephir_is_instance_of(body, SL("Psr\\Http\\Message\\StreamInterface") TSRMLS_CC)) {
		RETVAL_ZVAL(body, 1, 0);
		RETURN_MM();
	}
	_0 = Z_TYPE_P(body) != IS_STRING;
	if (_0) {
		_0 = 1 != Z_TYPE_P(body) == IS_RESOURCE;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid stream passed as a parameter", "phalcon/http/message/response.zep", 502);
		return;
	}
	object_init_ex(return_value, phalcon_http_message_stream_ce);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, body, &mode);
		zephir_check_call_status();
	}
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_Http_Message_Response(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("headers"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

