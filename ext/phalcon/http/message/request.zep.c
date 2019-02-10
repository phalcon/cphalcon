
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_message_request_ce, SL("headers"), ZEND_ACC_PRIVATE TSRMLS_CC);

	phalcon_http_message_request_ce->create_object = zephir_init_properties_Phalcon_Http_Message_Request;

	zend_class_implements(phalcon_http_message_request_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\requestinterface")));
	return SUCCESS;

}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Http_Message_Request, __construct) {

	zval headers;
	zval method;
	zval *uri = NULL, uri_sub, *method_param = NULL, *body = NULL, body_sub, *headers_param = NULL, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&body_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &uri, &method_param, &body, &headers_param);

	if (!uri) {
		uri = &uri_sub;
		uri = &__$null;
	}
	if (!method_param) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "");
	} else {
		zephir_get_strval(&method, method_param);
	}
	if (!body) {
		body = &body_sub;
		ZEPHIR_INIT_VAR(body);
		ZVAL_STRING(body, "php://temp");
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}



}

/**
 * Gets the body of the message.
 *
 * @return StreamInterface Returns the body as a stream.
 */
PHP_METHOD(Phalcon_Http_Message_Request, getBody) {

	zval *this_ptr = getThis();



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
PHP_METHOD(Phalcon_Http_Message_Request, getHeader) {

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
PHP_METHOD(Phalcon_Http_Message_Request, getHeaderLine) {

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
PHP_METHOD(Phalcon_Http_Message_Request, getHeaders) {

	zval *this_ptr = getThis();



}

/**
 * Checks if a header exists by the given case-insensitive name.
 *
 * @param string $name Case-insensitive header field name.
 * @return bool Returns true if any header names match the given header
 *     name using a case-insensitive string comparison. Returns false if
 *     no matching header name is found in the message.
 */
PHP_METHOD(Phalcon_Http_Message_Request, hasHeader) {

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
 * Retrieves the HTTP method of the request.
 *
 * @return string Returns the request method.
 */
PHP_METHOD(Phalcon_Http_Message_Request, getMethod) {

	zval *this_ptr = getThis();



}

/**
 * Retrieves the HTTP protocol version as a string.
 *
 * The string MUST contain only the HTTP version number (e.g., "1.1", "1.0").
 *
 * @return string HTTP protocol version.
 */
PHP_METHOD(Phalcon_Http_Message_Request, getProtocolVersion) {

	zval *this_ptr = getThis();



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
 *
 * If no URI is available, and no request-target has been specifically
 * provided, this method MUST return the string "/".
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_Request, getRequestTarget) {

	zval *this_ptr = getThis();



}

/**
 * Retrieves the URI instance.
 *
 * This method MUST return a UriInterface instance.
 *
 * @see http://tools.ietf.org/html/rfc3986#section-4.3
 * @return UriInterface Returns a UriInterface instance
 *     representing the URI of the request.
 */
PHP_METHOD(Phalcon_Http_Message_Request, getUri) {

	zval *this_ptr = getThis();



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
PHP_METHOD(Phalcon_Http_Message_Request, withAddedHeader) {

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
 *
 * @param StreamInterface $body Body.
 * @return static
 * @throws \InvalidArgumentException When the body is not valid.
 */
PHP_METHOD(Phalcon_Http_Message_Request, withBody) {

	zval *body, body_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);

	zephir_fetch_params(0, 1, 0, &body);




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
PHP_METHOD(Phalcon_Http_Message_Request, withHeader) {

	zval *name, name_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 2, 0, &name, &value);




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
 * @param string $method Case-sensitive method.
 * @return static
 * @throws \InvalidArgumentException for invalid HTTP methods.
 */
PHP_METHOD(Phalcon_Http_Message_Request, withMethod) {

	zval *method, method_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);

	zephir_fetch_params(0, 1, 0, &method);




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
 * @param mixed $requestTarget
 * @return static
 */
PHP_METHOD(Phalcon_Http_Message_Request, withRequestTarget) {

	zval *requestTarget, requestTarget_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requestTarget_sub);

	zephir_fetch_params(0, 1, 0, &requestTarget);




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
 * @param UriInterface $uri New request URI to use.
 * @param bool $preserveHost Preserve the original state of the Host header.
 * @return static
 */
PHP_METHOD(Phalcon_Http_Message_Request, withUri) {

	zval *uri, uri_sub, *preserveHost = NULL, preserveHost_sub, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&preserveHost_sub);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 1, &uri, &preserveHost);

	if (!preserveHost) {
		preserveHost = &preserveHost_sub;
		preserveHost = &__$false;
	}



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
PHP_METHOD(Phalcon_Http_Message_Request, withoutHeader) {

	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);

	zephir_fetch_params(0, 1, 0, &name);




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
PHP_METHOD(Phalcon_Http_Message_Request, withProtocolVersion) {

	zval *version, version_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version_sub);

	zephir_fetch_params(0, 1, 0, &version);




}

zend_object *zephir_init_properties_Phalcon_Http_Message_Request(zend_class_entry *class_type TSRMLS_DC) {

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

