
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

	zend_class_implements(phalcon_http_message_response_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\responseinterface")));
	return SUCCESS;

}

/**
 * Gets the body of the message.
 *
 * @return StreamInterface Returns the body as a stream.
 */
PHP_METHOD(Phalcon_Http_Message_Response, getBody) {

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
 *
 * @param StreamInterface $body Body.
 * @return static
 * @throws \InvalidArgumentException When the body is not valid.
 */
PHP_METHOD(Phalcon_Http_Message_Response, withBody) {

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

	zval *version, version_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version_sub);

	zephir_fetch_params(0, 1, 0, &version);




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

	zval *code, code_sub, *reasonPhrase = NULL, reasonPhrase_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&reasonPhrase_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &code, &reasonPhrase);

	if (!reasonPhrase) {
		reasonPhrase = &reasonPhrase_sub;
		ZEPHIR_INIT_VAR(reasonPhrase);
		ZVAL_STRING(reasonPhrase, "");
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
PHP_METHOD(Phalcon_Http_Message_Response, withoutHeader) {

	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);

	zephir_fetch_params(0, 1, 0, &name);




}

