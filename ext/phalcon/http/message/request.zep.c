
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
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
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */
/**
 * Representation of an outgoing, client-side request.
 *
 * Per the HTTP specification, this interface includes properties for
 * each of the following:
 *
 * - Protocol version
 * - HTTP method
 * - URI
 * - Headers
 * - Message body
 *
 * During construction, implementations MUST attempt to set the Host header from
 * a provided URI if no Host header is provided.
 *
 * Requests are considered immutable; all methods that might change state MUST
 * be implemented such that they retain the internal state of the current
 * message and return an instance that contains the changed state.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Request) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, Request, phalcon, http_message_request, phalcon_http_message_request_method_entry, 0);

	/**
	 * Gets the body of the message.
	 *
	 * @var <StreamInterface>
	 */
	zend_declare_property_null(phalcon_http_message_request_ce, SL("body"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var <Collection>
	 */
	zend_declare_property_null(phalcon_http_message_request_ce, SL("headers"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieves the HTTP method of the request.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_request_ce, SL("method"), "GET", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieves the HTTP protocol version as a string.
	 *
	 * The string MUST contain only the HTTP version number (e.g., "1.1", "1.0").
	 *
	 * @return string HTTP protocol version.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_request_ce, SL("protocolVersion"), "1.1", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The request-target, if it has been provided or calculated.
	 *
	 * @var null|string
	 */
	zend_declare_property_null(phalcon_http_message_request_ce, SL("requestTarget"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieves the URI instance.
	 *
	 * This method MUST return a UriInterface instance.
	 *
	 * @see http://tools.ietf.org/html/rfc3986#section-4.3
	 *
	 * @var <UriInterface>
	 */
	zend_declare_property_null(phalcon_http_message_request_ce, SL("uri"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(phalcon_http_message_request_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\requestinterface")));
	return SUCCESS;

}

/**
 * Gets the body of the message.
 */
PHP_METHOD(Phalcon_Http_Message_Request, getBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "body");

}

/**
 * Retrieves the HTTP method of the request.
 */
PHP_METHOD(Phalcon_Http_Message_Request, getMethod) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "method");

}

/**
 * Retrieves the HTTP protocol version as a string.
 *
 *
 * The string MUST contain only the HTTP version number (e.g., "1.1", "1.0").
 *
 */
PHP_METHOD(Phalcon_Http_Message_Request, getProtocolVersion) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "protocolVersion");

}

/**
 * Retrieves the URI instance.
 *
 *
 * This method MUST return a UriInterface instance.
 *
 */
PHP_METHOD(Phalcon_Http_Message_Request, getUri) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "uri");

}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Http_Message_Request, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *uri = NULL, uri_sub, *body = NULL, body_sub, *headers = NULL, headers_sub, __$null, _0, _1, _2, _3, _4, _5;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&headers_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &method_param, &uri, &body, &headers);

	if (!method_param) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "GET");
	} else {
		zephir_get_strval(&method, method_param);
	}
	if (!uri) {
		uri = &uri_sub;
		uri = &__$null;
	}
	if (!body) {
		body = &body_sub;
		ZEPHIR_INIT_VAR(body);
		ZVAL_STRING(body, "php://memory");
	} else {
		ZEPHIR_SEPARATE_PARAM(body);
	}
	if (!headers) {
		headers = &headers_sub;
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "php://input");
	if (ZEPHIR_IS_IDENTICAL(&_0, body)) {
		ZEPHIR_INIT_NVAR(body);
		object_init_ex(body, phalcon_http_message_stream_input_ce);
		ZEPHIR_CALL_METHOD(NULL, body, "__construct", NULL, 211);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "processheaders", NULL, 212, headers);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("headers"), &_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "processuri", NULL, 213, uri);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("uri"), &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "processmethod", NULL, 214, &method);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("method"), &_3);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "w+b");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "processbody", NULL, 215, body, &_5);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("body"), &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * Retrieves a message header value by the given case-insensitive name.
 *
 * This method returns an array of all the header values of the given
 * case-insensitive header name.
 *
 * If the header does not appear in the message, this method MUST return an
 * empty array.
 */
PHP_METHOD(Phalcon_Http_Message_Request, getHeader) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);

	ZEPHIR_SEPARATE_PARAM(name);


	zephir_get_strval(&_0, name);
	ZEPHIR_CPY_WRT(name, &_0);
	zephir_read_property(&_1, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "get", NULL, 0, name, &_2);
	zephir_check_call_status();
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
PHP_METHOD(Phalcon_Http_Message_Request, getHeaderLine) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&header);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_CALL_METHOD(&header, this_ptr, "getheader", NULL, 0, name);
	zephir_check_call_status();
	if (zephir_fast_count_int(&header TSRMLS_CC) > 0) {
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
PHP_METHOD(Phalcon_Http_Message_Request, getHeaders) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieves the message's request target.
 *
 * Retrieves the message's request-target either as it will appear (for
 * clients), as it appeared at request (for servers), or as it was
 * specified for the instance (see withRequestTarget()).
 *
 * In most cases, this will be the origin-form of the composed URI,
 * unless a value was provided to the concrete implementation (see
 * withRequestTarget() below).
 */
PHP_METHOD(Phalcon_Http_Message_Request, getRequestTarget) {

	zval requestTarget, _0, _1$$3, _2$$3, _3$$3, _4$$4, _5$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requestTarget);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("requestTarget"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&requestTarget, &_0);
	if (Z_TYPE_P(&requestTarget) == IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, SL("uri"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&requestTarget, &_1$$3, "getpath", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, SL("uri"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3$$3, &_2$$3, "getquery", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_3$$3)) {
			zephir_read_property(&_4$$4, this_ptr, SL("uri"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_5$$4, &_4$$4, "getquery", NULL, 0);
			zephir_check_call_status();
			zephir_concat_self(&requestTarget, &_5$$4 TSRMLS_CC);
		}
		if (ZEPHIR_IS_EMPTY(&requestTarget)) {
			ZEPHIR_INIT_NVAR(&requestTarget);
			ZVAL_STRING(&requestTarget, "/");
		}
	}
	RETURN_CCTOR(&requestTarget);

}

/**
 * Checks if a header exists by the given case-insensitive name.
 */
PHP_METHOD(Phalcon_Http_Message_Request, hasHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "has", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

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
PHP_METHOD(Phalcon_Http_Message_Request, withAddedHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value = NULL, value_sub, existing, headers, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&existing);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);

	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadername", NULL, 216, name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_clone(&_1, &_0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&headers, &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_CALL_METHOD(&existing, &headers, "get", NULL, 0, name, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getheadervalue", NULL, 217, value);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(value, &_3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_array_merge(&_4, &existing, value TSRMLS_CC);
	ZEPHIR_CPY_WRT(value, &_4);
	ZEPHIR_CALL_METHOD(NULL, &headers, "set", NULL, 0, name, value);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "headers");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 218, &headers, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return an instance with the specified message body.
 *
 * The body MUST be a StreamInterface object.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return a new instance that has the
 * new body stream.
 *
 * @throws \InvalidArgumentException When the body is not valid.
 */
PHP_METHOD(Phalcon_Http_Message_Request, withBody) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *body, body_sub, newBody, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&newBody);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &body);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "w+b");
	ZEPHIR_CALL_METHOD(&newBody, this_ptr, "processbody", NULL, 215, body, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "body");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 218, &newBody, &_0);
	zephir_check_call_status();
	RETURN_MM();

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
 * @throws \InvalidArgumentException for invalid header names or values.
 */
PHP_METHOD(Phalcon_Http_Message_Request, withHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value = NULL, value_sub, headers, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);

	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadername", NULL, 216, name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_clone(&_1, &_0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&headers, &_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getheadervalue", NULL, 217, value);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(value, &_2);
	ZEPHIR_CALL_METHOD(NULL, &headers, "set", NULL, 0, name, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "headers");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 218, &headers, &_3);
	zephir_check_call_status();
	RETURN_MM();

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
 * @throws \InvalidArgumentException for invalid HTTP methods.
 */
PHP_METHOD(Phalcon_Http_Message_Request, withMethod) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processmethod", NULL, 214, method);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "method");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 218, method, &_0);
	zephir_check_call_status();
	RETURN_MM();

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
PHP_METHOD(Phalcon_Http_Message_Request, withProtocolVersion) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *version, version_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processprotocol", NULL, 219, version);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "protocolVersion");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 218, version, &_0);
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
 */
PHP_METHOD(Phalcon_Http_Message_Request, withRequestTarget) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *requestTarget, requestTarget_sub, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requestTarget_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &requestTarget);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/\\s/");
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/\\s/");
	zephir_preg_match(&_2, &_3, requestTarget, &_0, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid request target: cannot contain whitespace", "phalcon/Http/Message/Request.zep", 346);
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "requestTarget");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 218, requestTarget, &_4);
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
 * `true`, this method interacts with the Host header in the following ways:
 *
 * - If the Host header is missing or empty, and the new URI contains
 *   a host component, this method MUST update the Host header in the returned
 *   request.
 * - If the Host header is missing or empty, and the new URI does not contain a
 *   host component, this method MUST NOT update the Host header in the returned
 *   request.
 * - If a Host header is present and non-empty, this method MUST NOT update
 *   the Host header in the returned request.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * new UriInterface instance.
 *
 * @see http://tools.ietf.org/html/rfc3986#section-4.3
 */
PHP_METHOD(Phalcon_Http_Message_Request, withUri) {

	zval _9$$3;
	zend_bool _3, _6;
	double _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri, uri_sub, *preserveHost = NULL, preserveHost_sub, __$false, headers, host, newInstance, _1, _2, _4, _5, _7, _8, _10$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&preserveHost_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_9$$3);

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
	zephir_read_property(&_1, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	if (zephir_clone(&_2, &_1 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&headers, &_2);
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&newInstance, SL("uri"), uri);
	_3 = ZEPHIR_IS_TRUE_IDENTICAL(preserveHost);
	if (_3) {
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, "Host");
		ZEPHIR_CALL_METHOD(&_4, &headers, "has", NULL, 0, &_5);
		zephir_check_call_status();
		_3 = ZEPHIR_IS_TRUE_IDENTICAL(&_4);
	}
	_6 = _3;
	if (_6) {
		ZEPHIR_CALL_METHOD(&_7, uri, "gethost", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_STRING(&_8, "");
		_6 = !ZEPHIR_IS_IDENTICAL(&_8, &_7);
	}
	if (!(_6)) {
		ZEPHIR_CALL_METHOD(&host, this_ptr, "geturihost", NULL, 220, uri);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_create_array(&_9$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_9$$3, &host);
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "Host");
		ZEPHIR_CALL_METHOD(NULL, &headers, "set", NULL, 0, &_10$$3, &_9$$3);
		zephir_check_call_status();
		zephir_update_property_zval(&newInstance, SL("headers"), &headers);
	}
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
PHP_METHOD(Phalcon_Http_Message_Request, withoutHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, headers, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_clone(&_1, &_0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&headers, &_1);
	ZEPHIR_CALL_METHOD(NULL, &headers, "remove", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "headers");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 218, &headers, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check the name of the header. Throw exception if not valid
 *
 * @see http://tools.ietf.org/html/rfc7230#section-3.2
 */
PHP_METHOD(Phalcon_Http_Message_Request, checkHeaderName) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, _1, _2, _3, _4, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	_0 = Z_TYPE_P(name) != IS_STRING;
	if (!(_0)) {
		ZEPHIR_INIT_VAR(&_1);
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "/^[a-zA-Z0-9\\'`#$%&*+.^_|~!-]+$/");
		ZEPHIR_INIT_VAR(&_3);
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "/^[a-zA-Z0-9\\'`#$%&*+.^_|~!-]+$/");
		zephir_preg_match(&_3, &_4, name, &_1, 0, 0 , 0  TSRMLS_CC);
		_0 = !zephir_is_true(&_3);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SV(&_6$$3, "Invalid header name ", name);
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 221, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "phalcon/Http/Message/Request.zep", 430 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Validates a header value
 *
 * Most HTTP header field values are defined using common syntax
 * components (token, quoted-string, and comment) separated by
 * whitespace or specific delimiting characters.  Delimiters are chosen
 * from the set of US-ASCII visual characters not allowed in a token
 * (DQUOTE and "(),/:;<=>?@[\]{}").
 *
 *     token          = 1*tchar
 *
 *     tchar          = "!" / "#" / "$" / "%" / "&" / "'" / "*"
 *                    / "+" / "-" / "." / "^" / "_" / "`" / "|" / "~"
 *                    / DIGIT / ALPHA
 *                    ; any VCHAR, except delimiters
 *
 * A string of text is parsed as a single value if it is quoted using
 * double-quote marks.
 *
 *     quoted-string  = DQUOTE *( qdtext / quoted-pair ) DQUOTE
 *     qdtext         = HTAB / SP /%x21 / %x23-5B / %x5D-7E / obs-text
 *     obs-text       = %x80-FF
 *
 * Comments can be included in some HTTP header fields by surrounding
 * the comment text with parentheses.  Comments are only allowed in
 * fields containing "comment" as part of their field value definition.
 *
 *     comment        = "(" *( ctext / quoted-pair / comment ) ")"
 *     ctext          = HTAB / SP / %x21-27 / %x2A-5B / %x5D-7E / obs-text
 *
 * The backslash octet ("\") can be used as a single-octet quoting
 * mechanism within quoted-string and comment constructs.  Recipients
 * that process the value of a quoted-string MUST handle a quoted-pair
 * as if it were replaced by the octet following the backslash.
 *
 *     quoted-pair    = "\" ( HTAB / SP / VCHAR / obs-text )
 *
 * A sender SHOULD NOT generate a quoted-pair in a quoted-string except
 * where necessary to quote DQUOTE and backslash octets occurring within
 * that string.  A sender SHOULD NOT generate a quoted-pair in a comment
 * except where necessary to quote parentheses ["(" and ")"] and
 * backslash octets occurring within that comment.
 *
 * @see https://tools.ietf.org/html/rfc7230#section-3.2.6
 */
PHP_METHOD(Phalcon_Http_Message_Request, checkHeaderValue) {

	zval _2;
	zend_bool _0, _1, _7;
	zval *value = NULL, value_sub, _3, _4, _5, _6, _8, _9, _10, _11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);

	ZEPHIR_SEPARATE_PARAM(value);


	_0 = Z_TYPE_P(value) != IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(value) != IS_LONG;
	}
	_1 = _0;
	if (_1) {
		_1 = Z_TYPE_P(value) != IS_DOUBLE;
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid header value", "phalcon/Http/Message/Request.zep", 482);
		return;
	}
	zephir_get_strval(&_2, value);
	ZEPHIR_CPY_WRT(value, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "#(?:(?:(?<!\r)\n)|(?:\r(?!\n))|(?:\r\n(?![ \t])))#");
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "#(?:(?:(?<!\r)\n)|(?:\r(?!\n))|(?:\r\n(?![ \t])))#");
	zephir_preg_match(&_5, &_6, value, &_3, 0, 0 , 0  TSRMLS_CC);
	_7 = zephir_is_true(&_5);
	if (!(_7)) {
		ZEPHIR_INIT_VAR(&_8);
		ZEPHIR_INIT_VAR(&_9);
		ZVAL_STRING(&_9, "/[^\\x09\\x0a\\x0d\\x20-\\x7E\\x80-\\xFE]/");
		ZEPHIR_INIT_VAR(&_10);
		ZEPHIR_INIT_VAR(&_11);
		ZVAL_STRING(&_11, "/[^\\x09\\x0a\\x0d\\x20-\\x7E\\x80-\\xFE]/");
		zephir_preg_match(&_10, &_11, value, &_8, 0, 0 , 0  TSRMLS_CC);
		_7 = zephir_is_true(&_10);
	}
	if (_7) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid header value", "phalcon/Http/Message/Request.zep", 489);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a new instance having set the parameter
 */
PHP_METHOD(Phalcon_Http_Message_Request, cloneInstance) {

	zval property;
	zval *element, element_sub, *property_param = NULL, newInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&property);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element, &property_param);

	zephir_get_strval(&property, property_param);


	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property_zval(&_0, this_ptr, &property, PH_NOISY_CC);
	if (!ZEPHIR_IS_IDENTICAL(element, &_0)) {
		zephir_update_property_zval_zval(&newInstance, &property, element TSRMLS_CC);
	}
	RETURN_CCTOR(&newInstance);

}

/**
 * Returns the header values checked for validity
 */
PHP_METHOD(Phalcon_Http_Message_Request, getHeaderValue) {

	zval _2$$5;
	zval valueData;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL, values_sub, value, *_0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&valueData);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &values);

	ZEPHIR_SEPARATE_PARAM(values);


	if (Z_TYPE_P(values) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(values);
		zephir_create_array(values, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(values, values);
	}
	if (ZEPHIR_IS_EMPTY(values)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid header value: must be a string or array of strings; cannot be an empty array", "phalcon/Http/Message/Request.zep", 523);
		return;
	}
	ZEPHIR_INIT_VAR(&valueData);
	array_init(&valueData);
	zephir_is_iterable(values, 0, "phalcon/Http/Message/Request.zep", 532);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(values), _0)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadervalue", &_1, 222, &value);
		zephir_check_call_status();
		zephir_get_strval(&_2$$5, &value);
		zephir_array_append(&valueData, &_2$$5, PH_SEPARATE, "phalcon/Http/Message/Request.zep", 529);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	RETURN_CTOR(&valueData);

}

/**
 * Return the host and if applicable the port
 */
PHP_METHOD(Phalcon_Http_Message_Request, getUriHost) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri, uri_sub, host, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri);



	ZEPHIR_CALL_METHOD(&host, uri, "gethost", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, uri, "getport", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&_1$$3, uri, "getport", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, ":", &_1$$3);
		zephir_concat_self(&host, &_2$$3 TSRMLS_CC);
	}
	RETURN_CCTOR(&host);

}

/**
 * Set a valid stream
 */
PHP_METHOD(Phalcon_Http_Message_Request, processBody) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval mode;
	zval *body = NULL, body_sub, *mode_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&mode);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &body, &mode_param);

	if (!body) {
		body = &body_sub;
		ZEPHIR_INIT_VAR(body);
		ZVAL_STRING(body, "php://memory");
	}
	if (!mode_param) {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_STRING(&mode, "r+b");
	} else {
		zephir_get_strval(&mode, mode_param);
	}


	if (zephir_is_instance_of(body, SL("Psr\\Http\\Message\\StreamInterface") TSRMLS_CC)) {
		RETVAL_ZVAL(body, 1, 0);
		RETURN_MM();
	}
	_0 = Z_TYPE_P(body) != IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(body) != IS_RESOURCE;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid stream passed as a parameter", "phalcon/Http/Message/Request.zep", 560);
		return;
	}
	object_init_ex(return_value, phalcon_http_message_stream_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 223, body, &mode);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the headers
 */
PHP_METHOD(Phalcon_Http_Message_Request, processHeaders) {

	zval _15$$5;
	zval _4$$4;
	zend_bool _10$$3;
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers, headers_sub, collection, host, name, value, *_0$$3, _8$$3, _9$$3, _11$$3, _12$$3, _13$$3, _5$$4, _14$$5, _16$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_15$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers);



	if (Z_TYPE_P(headers) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&collection);
		object_init_ex(&collection, phalcon_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 224);
		zephir_check_call_status();
		zephir_is_iterable(headers, 0, "phalcon/Http/Message/Request.zep", 585);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(headers), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&name, _2$$3);
			} else {
				ZVAL_LONG(&name, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0$$3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadername", &_3, 216, &name);
			zephir_check_call_status();
			zephir_get_strval(&_4$$4, &name);
			ZEPHIR_CPY_WRT(&name, &_4$$4);
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getheadervalue", &_6, 217, &value);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_5$$4);
			ZEPHIR_CALL_METHOD(NULL, &collection, "set", &_7, 225, &name, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&name);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "host");
		ZEPHIR_CALL_METHOD(&_8$$3, &collection, "has", NULL, 226, &_9$$3);
		zephir_check_call_status();
		_10$$3 = ZEPHIR_IS_TRUE_IDENTICAL(&_8$$3);
		if (_10$$3) {
			zephir_read_property(&_11$$3, this_ptr, SL("uri"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_12$$3, &_11$$3, "gethost", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_SINIT_VAR(_13$$3);
			ZVAL_STRING(&_13$$3, "");
			_10$$3 = !ZEPHIR_IS_IDENTICAL(&_13$$3, &_12$$3);
		}
		if (_10$$3) {
			zephir_read_property(&_14$$5, this_ptr, SL("uri"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&host, this_ptr, "geturihost", NULL, 220, &_14$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_15$$5);
			zephir_create_array(&_15$$5, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_15$$5, &host);
			ZEPHIR_INIT_VAR(&_16$$5);
			ZVAL_STRING(&_16$$5, "Host");
			ZEPHIR_CALL_METHOD(NULL, &collection, "set", &_7, 225, &_16$$5, &_15$$5);
			zephir_check_call_status();
		}
	} else {
		if (zephir_instance_of_ev(headers, phalcon_collection_ce TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(&collection, headers);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Headers needs to be either an array or instance of Phalcon\\Collection", "phalcon/Http/Message/Request.zep", 596);
			return;
		}
	}
	RETURN_CCTOR(&collection);

}

/**
 * Check the method
 */
PHP_METHOD(Phalcon_Http_Message_Request, processMethod) {

	zend_bool _0, _1;
	zval methods;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, method_sub, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&methods);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &method);

	if (!method) {
		method = &method_sub;
		ZEPHIR_INIT_VAR(method);
		ZVAL_STRING(method, "");
	}


	ZEPHIR_INIT_VAR(&methods);
	zephir_create_array(&methods, 9, 0 TSRMLS_CC);
	add_assoc_long_ex(&methods, SL("GET"), 1);
	add_assoc_long_ex(&methods, SL("CONNECT"), 1);
	add_assoc_long_ex(&methods, SL("DELETE"), 1);
	add_assoc_long_ex(&methods, SL("HEAD"), 1);
	add_assoc_long_ex(&methods, SL("OPTIONS"), 1);
	add_assoc_long_ex(&methods, SL("PATCH"), 1);
	add_assoc_long_ex(&methods, SL("POST"), 1);
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
	if (!(_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Invalid or unsupported method ", method);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 221, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Http/Message/Request.zep", 623 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(method, 1, 0);
	RETURN_MM();

}

/**
 * Checks the protocol
 */
PHP_METHOD(Phalcon_Http_Message_Request, processProtocol) {

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
	_0 = ZEPHIR_IS_EMPTY(protocol);
	if (!(_0)) {
		_0 = Z_TYPE_P(protocol) != IS_STRING;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid protocol value", "phalcon/Http/Message/Request.zep", 644);
		return;
	}
	if (!(zephir_array_isset(&protocols, protocol))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "Unsupported protocol ", protocol);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 221, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Http/Message/Request.zep", 648 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(protocol, 1, 0);
	RETURN_MM();

}

/**
 * Sets a valid Uri
 */
PHP_METHOD(Phalcon_Http_Message_Request, processUri) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri, uri_sub, localUri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&localUri);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri);



	_0 = Z_TYPE_P(uri) == IS_STRING;
	if (!(_0)) {
		_0 = Z_TYPE_P(uri) == IS_NULL;
	}
	if (zephir_is_instance_of(uri, SL("Psr\\Http\\Message\\UriInterface") TSRMLS_CC)) {
		ZEPHIR_CPY_WRT(&localUri, uri);
	} else if (_0) {
		ZEPHIR_INIT_NVAR(&localUri);
		object_init_ex(&localUri, phalcon_http_message_uri_ce);
		ZEPHIR_CALL_METHOD(NULL, &localUri, "__construct", NULL, 227, uri);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid uri passed as a parameter", "phalcon/Http/Message/Request.zep", 666);
		return;
	}
	RETURN_CCTOR(&localUri);

}

