
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
#include "kernel/string.h"
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
	zval *body = NULL, body_sub, *code_param = NULL, *headers_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
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
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "w+");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processstream", NULL, 219, body, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processheaders", NULL, 220, &headers);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the body of the message.
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

	zval *name, name_sub, header, key, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_INIT_VAR(&key);
	zephir_fast_strtolower(&key, name);
	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&header, &_0, &key, 1 TSRMLS_CC)) {
		zephir_array_fetch_string(&_1$$3, &header, SL("value"), PH_NOISY | PH_READONLY, "phalcon/http/message/response.zep", 99 TSRMLS_CC);
		RETURN_CTOR(&_1$$3);
	}
	array_init(return_value);
	RETURN_MM();

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
 */
PHP_METHOD(Phalcon_Http_Message_Response, getHeaderLine) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&header);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_CALL_METHOD(&header, this_ptr, "getheader", NULL, 0, name);
	zephir_check_call_status();
	if (1 != ZEPHIR_IS_EMPTY(&header)) {
		zephir_fast_join_str(return_value, SL(","), &header TSRMLS_CC);
		RETURN_MM();
	}
	RETURN_MM_STRING("");

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
 */
PHP_METHOD(Phalcon_Http_Message_Response, getHeaders) {

	zval headers;
	zval element, _0, *_1, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/http/message/response.zep", 162);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&element);
		ZVAL_COPY(&element, _1);
		zephir_array_fetch_string(&_2$$3, &element, SL("value"), PH_NOISY | PH_READONLY, "phalcon/http/message/response.zep", 159 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&_3$$3);
		zephir_array_fetch_string(&_3$$3, &element, SL("name"), PH_NOISY, "phalcon/http/message/response.zep", 159 TSRMLS_CC);
		zephir_array_update_zval(&headers, &_3$$3, &_2$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&element);
	RETURN_CTOR(&headers);

}

/**
 * Retrieves the HTTP protocol version as a string.
 *
 * The string MUST contain only the HTTP version number (e.g., "1.1", "1.0").
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
 */
PHP_METHOD(Phalcon_Http_Message_Response, getStatusCode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "code");

}

/**
 * Checks if a header exists by the given case-insensitive name.
 */
PHP_METHOD(Phalcon_Http_Message_Response, hasHeader) {

	zval *name, name_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, name);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &_1));

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
 */
PHP_METHOD(Phalcon_Http_Message_Response, withAddedHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value, value_sub, key, headers, newInstance, values, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasheader", NULL, 0, name);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "withheader", NULL, 0, name, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&key);
	zephir_fast_strtolower(&key, name);
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_1, &newInstance, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&headers, &_1);
	zephir_array_fetch(&_2, &headers, &key, PH_NOISY | PH_READONLY, "phalcon/http/message/response.zep", 234 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&values);
	zephir_array_fetch_string(&values, &_2, SL("value"), PH_NOISY, "phalcon/http/message/response.zep", 234 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_array_merge(&_3, &values, value TSRMLS_CC);
	ZEPHIR_CPY_WRT(&values, &_3);
	zephir_array_update_multi(&headers, &values TSRMLS_CC, SL("zs"), 3, &key, SL("value"));
	zephir_update_property_zval(&newInstance, SL("headers"), &headers);
	RETURN_CCTOR(&newInstance);

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
 */
PHP_METHOD(Phalcon_Http_Message_Response, withHeader) {

	zval *name, name_sub, *value, value_sub, key, newInstance;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&newInstance);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	ZEPHIR_INIT_VAR(&key);
	zephir_fast_strtolower(&key, name);
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_array(&newInstance, SL("headers"), &key, value TSRMLS_CC);
	RETURN_CCTOR(&newInstance);

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
 */
PHP_METHOD(Phalcon_Http_Message_Response, withProtocolVersion) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *version, version_sub, newInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processprotocol", NULL, 221, version);
	zephir_check_call_status();
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
 */
PHP_METHOD(Phalcon_Http_Message_Response, withoutHeader) {

	zval *name, name_sub, key, newInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_INIT_VAR(&key);
	zephir_fast_strtolower(&key, name);
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &newInstance, SL("headers"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &key, PH_SEPARATE);
	RETURN_CCTOR(&newInstance);

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


	ZEPHIR_CALL_METHOD(&phrases, this_ptr, "getphrases", NULL, 222);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&keys);
	zephir_array_keys(&keys, &phrases TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&min, "min", NULL, 223, &keys);
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
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 224, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/http/message/response.zep", 494 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1 != Z_TYPE_P(phrase) == IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid response reason", "phalcon/http/message/response.zep", 498);
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
		zephir_array_fetch(phrase, &phrases, code, PH_NOISY, "phalcon/http/message/response.zep", 502 TSRMLS_CC);
	}
	zephir_update_property_zval(this_ptr, SL("code"), code);
	zephir_update_property_zval(this_ptr, SL("reason"), phrase);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the headers
 */
PHP_METHOD(Phalcon_Http_Message_Response, processHeaders) {

	zend_string *_2;
	zend_ulong _1;
	zval *headers_param = NULL, key, name, value, *_0;
	zval headers, headerData, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&headerData);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_arrval(&headers, headers_param);


	ZEPHIR_INIT_VAR(&headerData);
	array_init(&headerData);
	zephir_is_iterable(&headers, 0, "phalcon/http/message/response.zep", 527);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&name, _2);
		} else {
			ZVAL_LONG(&name, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_INIT_NVAR(&key);
		zephir_fast_strtolower(&key, &name);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_create_array(&_3$$3, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_3$$3, SL("name"), &name, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$3, SL("value"), &value, PH_COPY | PH_SEPARATE);
		zephir_array_update_zval(&headerData, &key, &_3$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	zephir_update_property_zval(this_ptr, SL("headers"), &headerData);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks the protocol
 */
PHP_METHOD(Phalcon_Http_Message_Response, processProtocol) {

	zend_bool _0;
	zval protocols;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *protocol = NULL, protocol_sub, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&protocol_sub);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&protocols);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &protocol);

	if (!protocol) {
		protocol = &protocol_sub;
		ZEPHIR_INIT_VAR(protocol);
		ZVAL_STRING(protocol, "");
	}


	ZEPHIR_INIT_VAR(&protocols);
	zephir_create_array(&protocols, 4, 0 TSRMLS_CC);
	add_assoc_long_ex(&protocols, SL("1.0"), 1);
	add_assoc_long_ex(&protocols, SL("1.1"), 1);
	add_assoc_long_ex(&protocols, SL("2.0"), 1);
	add_assoc_long_ex(&protocols, SL("3.0"), 1);
	_0 = 1 == ZEPHIR_IS_EMPTY(protocol);
	if (!(_0)) {
		_0 = (1 != Z_TYPE_P(protocol) == IS_STRING);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid protocol value", "phalcon/http/message/response.zep", 545);
		return;
	}
	if (1 != zephir_array_isset(&protocols, protocol)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "Unsupported protocol ", protocol);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 224, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/http/message/response.zep", 549 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Set a valid stream
 */
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
		_0 = (1 != Z_TYPE_P(body) == IS_RESOURCE);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid stream passed as a parameter", "phalcon/http/message/response.zep", 563);
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

