
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
#include "kernel/array.h"
#include "kernel/fcall.h"


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
 * Representation of an incoming, server-side HTTP request.
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
 * Additionally, it encapsulates all data as it has arrived at the
 * application from the CGI and/or PHP environment, including:
 *
 * - The values represented in _SERVER.
 * - Any cookies provided (generally via _COOKIE)
 * - Query string arguments (generally via _GET, or as parsed via parse_str())
 * - Upload files, if any (as represented by _FILES)
 * - Deserialized body parameters (generally from _POST)
 *
 * _SERVER values MUST be treated as immutable, as they represent application
 * state at the time of request; as such, no methods are provided to allow
 * modification of those values. The other values provide such methods, as they
 * can be restored from _SERVER or the request body, and may need treatment
 * during the application (e.g., body parameters may be deserialized based on
 * content type).
 *
 * Additionally, this interface recognizes the utility of introspecting a
 * request to derive and match additional parameters (e.g., via URI path
 * matching, decrypting cookie values, deserializing non-form-encoded body
 * content, matching authorization headers to users, etc). These parameters
 * are stored in an "attributes" property.
 *
 * Requests are considered immutable; all methods that might change state MUST
 * be implemented such that they retain the internal state of the current
 * message and return an instance that contains the changed state.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_ServerRequest) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, ServerRequest, phalcon, http_message_serverrequest, phalcon_http_message_serverrequest_method_entry, 0);

	/**
	 * Retrieve attributes derived from the request.
	 *
	 * The request "attributes" may be used to allow injection of any
	 * parameters derived from the request: e.g., the results of path
	 * match operations; the results of decrypting cookies; the results of
	 * deserializing non-form-encoded message bodies; etc. Attributes
	 * will be application and request specific, and CAN be mutable.
	 *
	 * @var arrau
	 */
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("attributes"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Gets the body of the message.
	 *
	 * @var <StreamInterface>
	 */
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("body"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve cookies.
	 *
	 * Retrieves cookies sent by the client to the server.
	 *
	 * The data MUST be compatible with the structure of the $_COOKIE
	 * superglobal.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("cookieParams"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve query string arguments.
	 *
	 * Retrieves the deserialized query string arguments, if any.
	 *
	 * Note: the query params might not be in sync with the URI or server
	 * params. If you need to ensure you are only getting the original
	 * values, you may need to parse the query string from `getUri()->getQuery()`
	 * or from the `QUERY_STRING` server param.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("queryParams"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieves the HTTP method of the request.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_serverrequest_ce, SL("method"), "GET", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve any parameters provided in the request body.
	 *
	 * If the request Content-Type is either application/x-www-form-urlencoded
	 * or multipart/form-data, and the request method is POST, this method MUST
	 * return the contents of $_POST.
	 *
	 * Otherwise, this method may return any results of deserializing
	 * the request body content; as parsing returns structured content, the
	 * potential types MUST be arrays or objects only. A null value indicates
	 * the absence of body content.
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("parsedBody"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieves the HTTP protocol version as a string.
	 *
	 * The string MUST contain only the HTTP version number (e.g., "1.1", "1.0").
	 *
	 * @return string HTTP protocol version.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_serverrequest_ce, SL("protocolVersion"), "1.1", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve server parameters.
	 *
	 * Retrieves data related to the incoming request environment,
	 * typically derived from PHP's $_SERVER superglobal. The data IS NOT
	 * REQUIRED to originate from $_SERVER.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("serverParams"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve normalized file upload data.
	 *
	 * This method returns upload metadata in a normalized tree, with each leaf
	 * an instance of Psr\Http\Message\UploadedFileInterface.
	 *
	 * These values MAY be prepared from $_FILES or the message body during
	 * instantiation, or MAY be injected via withUploadedFiles().
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("uploadedFiles"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieves the URI instance.
	 *
	 * This method MUST return a UriInterface instance.
	 *
	 * @see http://tools.ietf.org/html/rfc3986#section-4.3
	 *
	 * @var <UriInterface>
	 */
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("uri"), ZEND_ACC_PRIVATE TSRMLS_CC);

	phalcon_http_message_serverrequest_ce->create_object = zephir_init_properties_Phalcon_Http_Message_ServerRequest;

	zend_class_implements(phalcon_http_message_serverrequest_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\serverrequestinterface")));
	return SUCCESS;

}

/**
 * Retrieve attributes derived from the request.
 *
 *
 * The request "attributes" may be used to allow injection of any
 * parameters derived from the request: e.g., the results of path
 * match operations; the results of decrypting cookies; the results of
 * deserializing non-form-encoded message bodies; etc. Attributes
 * will be application and request specific, and CAN be mutable.
 *
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getAttributes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "attributes");

}

/**
 * Gets the body of the message.
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "body");

}

/**
 * Retrieve cookies.
 *
 *
 * Retrieves cookies sent by the client to the server.
 * 
 * The data MUST be compatible with the structure of the $_COOKIE
 * superglobal.
 *
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getCookieParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cookieParams");

}

/**
 * Retrieve query string arguments.
 *
 *
 * Retrieves the deserialized query string arguments, if any.
 * 
 * Note: the query params might not be in sync with the URI or server
 * params. If you need to ensure you are only getting the original
 * values, you may need to parse the query string from `getUri()->getQuery()`
 * or from the `QUERY_STRING` server param.
 *
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getQueryParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "queryParams");

}

/**
 * Retrieves the HTTP method of the request.
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getMethod) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "method");

}

/**
 * Retrieve any parameters provided in the request body.
 *
 *
 * If the request Content-Type is either application/x-www-form-urlencoded
 * or multipart/form-data, and the request method is POST, this method MUST
 * return the contents of $_POST.
 * 
 * Otherwise, this method may return any results of deserializing
 * the request body content; as parsing returns structured content, the
 * potential types MUST be arrays or objects only. A null value indicates
 * the absence of body content.
 *
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getParsedBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "parsedBody");

}

/**
 * Retrieves the HTTP protocol version as a string.
 *
 *
 * The string MUST contain only the HTTP version number (e.g., "1.1", "1.0").
 *
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getProtocolVersion) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "protocolVersion");

}

/**
 * Retrieve server parameters.
 *
 *
 * Retrieves data related to the incoming request environment,
 * typically derived from PHP's $_SERVER superglobal. The data IS NOT
 * REQUIRED to originate from $_SERVER.
 *
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getServerParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "serverParams");

}

/**
 * Retrieve normalized file upload data.
 *
 *
 * This method returns upload metadata in a normalized tree, with each leaf
 * an instance of Psr\Http\Message\UploadedFileInterface.
 * 
 * These values MAY be prepared from $_FILES or the message body during
 * instantiation, or MAY be injected via withUploadedFiles().
 *
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getUploadedFiles) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "uploadedFiles");

}

/**
 * Retrieves the URI instance.
 *
 *
 * This method MUST return a UriInterface instance.
 *
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getUri) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "uri");

}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, __construct) {

	zval serverParams;
	zval *method_param = NULL, *uri = NULL, uri_sub, *serverParams_param = NULL, __$null;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&serverParams);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &method_param, &uri, &serverParams_param);

	if (!method_param) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "");
	} else {
		zephir_get_strval(&method, method_param);
	}
	if (!uri) {
		uri = &uri_sub;
		uri = &__$null;
	}
	if (!serverParams_param) {
		ZEPHIR_INIT_VAR(&serverParams);
		array_init(&serverParams);
	} else {
		zephir_get_arrval(&serverParams, serverParams_param);
	}



}

/**
 * Retrieve a single derived request attribute.
 *
 * Retrieves a single derived request attribute as described in
 * getAttributes(). If the attribute has not been previously set, returns
 * the default value as provided.
 *
 * This method obviates the need for a hasAttribute() method, as it allows
 * specifying a default value to return if the attribute is not found.
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getAttribute) {

	zval *name, name_sub, *defaultValue = NULL, defaultValue_sub, __$null, attribute, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 1, &name, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("attributes"), PH_NOISY_CC | PH_READONLY);
	if (EXPECTED(zephir_array_isset_fetch(&attribute, &_0, name, 1 TSRMLS_CC))) {
		RETURN_CTORW(&attribute);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;

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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getHeader) {

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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getHeaderLine) {

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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getHeaders) {

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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getRequestTarget) {

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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, hasHeader) {

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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withAddedHeader) {

	zval *name, name_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 2, 0, &name, &value);




}

/**
 * Return an instance with the specified derived request attribute.
 *
 * This method allows setting a single derived request attribute as
 * described in getAttributes().
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * updated attribute.
 *
 * @see getAttributes()
 * @param string $name The attribute name.
 * @param mixed $value The value of the attribute.
 * @return static
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withAttribute) {

	zval *name, name_sub, *value, value_sub, newInstance;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&newInstance);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_array(&newInstance, SL("attributes"), name, value TSRMLS_CC);
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
 *
 * @param StreamInterface $body Body.
 * @return static
 * @throws \InvalidArgumentException When the body is not valid.
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withBody) {

	zval *body, body_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);

	zephir_fetch_params(0, 1, 0, &body);




}

/**
 * Return an instance with the specified cookies.
 *
 * The data IS NOT REQUIRED to come from the $_COOKIE superglobal, but MUST
 * be compatible with the structure of $_COOKIE. Typically, this data will
 * be injected at instantiation.
 *
 * This method MUST NOT update the related Cookie header of the request
 * instance, nor related values in the server params.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * updated cookie values.
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withCookieParams) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cookies_param = NULL, _0;
	zval cookies;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookies);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cookies_param);

	zephir_get_arrval(&cookies, cookies_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "cookies");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 235, &cookies, &_0);
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
 * @param string $name Case-insensitive header field name.
 * @param string|string[] $value Header value(s).
 * @return static
 * @throws \InvalidArgumentException for invalid header names or values.
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withHeader) {

	zval *name, name_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 2, 0, &name, &value);




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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withoutHeader) {

	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);

	zephir_fetch_params(0, 1, 0, &name);




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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withMethod) {

	zval *method, method_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);

	zephir_fetch_params(0, 1, 0, &method);




}

/**
 * Return an instance with the specified body parameters.
 *
 * These MAY be injected during instantiation.
 *
 * If the request Content-Type is either application/x-www-form-urlencoded
 * or multipart/form-data, and the request method is POST, use this method
 * ONLY to inject the contents of $_POST.
 *
 * The data IS NOT REQUIRED to come from $_POST, but MUST be the results of
 * deserializing the request body content. Deserialization/parsing returns
 * structured data, and, as such, this method ONLY accepts arrays or objects,
 * or a null value if nothing was available to parse.
 *
 * As an example, if content negotiation determines that the request data
 * is a JSON payload, this method could be used to create a request
 * instance with the deserialized parameters.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * updated body parameters.
 *
 * @param null|array|object $data The deserialized body data. This will
 *     typically be in an array or object.
 * @return static
 * @throws \InvalidArgumentException if an unsupported argument type is
 *     provided.
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withParsedBody) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "parsedBody");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 235, data, &_0);
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
 *
 * @param string $version HTTP protocol version
 * @return static
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withProtocolVersion) {

	zval *version, version_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version_sub);

	zephir_fetch_params(0, 1, 0, &version);




}

/**
 * Return an instance with the specified query string arguments.
 *
 * These values SHOULD remain immutable over the course of the incoming
 * request. They MAY be injected during instantiation, such as from PHP's
 * $_GET superglobal, or MAY be derived from some other value such as the
 * URI. In cases where the arguments are parsed from the URI, the data
 * MUST be compatible with what PHP's parse_str() would return for
 * purposes of how duplicate query parameters are handled, and how nested
 * sets are handled.
 *
 * Setting query string arguments MUST NOT change the URI stored by the
 * request, nor the values in the server params.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * updated query string arguments.
 *
 * @param array $query Array of query string arguments, typically from
 *     $_GET.
 * @return static
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withQueryParams) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, _0;
	zval query;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query_param);

	zephir_get_arrval(&query, query_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "query");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 235, &query, &_0);
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
 * @param mixed $requestTarget
 * @return static
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withRequestTarget) {

	zval *requestTarget, requestTarget_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requestTarget_sub);

	zephir_fetch_params(0, 1, 0, &requestTarget);




}

/**
 * Create a new instance with the specified uploaded files.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * updated body parameters.
 *
 * @param array $uploadedFiles An array tree of UploadedFileInterface instances.
 * @return static
 * @throws \InvalidArgumentException if an invalid structure is provided.
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withUploadedFiles) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uploadedFiles_param = NULL, _0;
	zval uploadedFiles;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uploadedFiles);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uploadedFiles_param);

	zephir_get_arrval(&uploadedFiles, uploadedFiles_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "files");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 235, &uploadedFiles, &_0);
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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withUri) {

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
 * Return an instance that removes the specified derived request attribute.
 *
 * This method allows removing a single derived request attribute as
 * described in getAttributes().
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that removes
 * the attribute.
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withoutAttribute) {

	zval *name, name_sub, attributes, newInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &newInstance, SL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&attributes, &_0);
	zephir_array_unset(&attributes, name, PH_SEPARATE);
	zephir_update_property_zval(&newInstance, SL("attributes"), &attributes);
	RETURN_CCTOR(&newInstance);

}

/**
 * Returns a new instance having set the parameter
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, cloneInstance) {

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


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property_zval(&_0, this_ptr, &property, PH_NOISY_CC);
	if (ZEPHIR_IS_IDENTICAL(element, &_0)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval_zval(&newInstance, &property, element TSRMLS_CC);
	RETURN_CCTOR(&newInstance);

}

zend_object *zephir_init_properties_Phalcon_Http_Message_ServerRequest(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _8, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("uploadedFiles"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("uploadedFiles"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("serverParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("serverParams"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("queryParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("queryParams"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("cookieParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("cookieParams"), &_7$$6);
		}
		zephir_read_property(&_8, this_ptr, SL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval(this_ptr, SL("attributes"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

