
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
	 * @var <Collection>
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
	 * @var <Collection>
	 */
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("headers"), ZEND_ACC_PRIVATE TSRMLS_CC);

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
	 * The request-target, if it has been provided or calculated.
	 *
	 * @var null|string
	 */
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("requestTarget"), ZEND_ACC_PRIVATE TSRMLS_CC);

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval serverParams, cookies, queryParams, uploadFiles;
	zval *method_param = NULL, *uri = NULL, uri_sub, *serverParams_param = NULL, *body = NULL, body_sub, *headers = NULL, headers_sub, *cookies_param = NULL, *queryParams_param = NULL, *uploadFiles_param = NULL, *parsedBody = NULL, parsedBody_sub, *protocol_param = NULL, __$null, _0, _1, _2, _3, _4, _5, _6;
	zval method, protocol;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&protocol);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&parsedBody_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&serverParams);
	ZVAL_UNDEF(&cookies);
	ZVAL_UNDEF(&queryParams);
	ZVAL_UNDEF(&uploadFiles);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 10, &method_param, &uri, &serverParams_param, &body, &headers, &cookies_param, &queryParams_param, &uploadFiles_param, &parsedBody, &protocol_param);

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
	if (!serverParams_param) {
		ZEPHIR_INIT_VAR(&serverParams);
		array_init(&serverParams);
	} else {
		zephir_get_arrval(&serverParams, serverParams_param);
	}
	if (!body) {
		body = &body_sub;
		ZEPHIR_INIT_VAR(body);
		ZVAL_STRING(body, "php://input");
	} else {
		ZEPHIR_SEPARATE_PARAM(body);
	}
	if (!headers) {
		headers = &headers_sub;
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	}
	if (!cookies_param) {
		ZEPHIR_INIT_VAR(&cookies);
		array_init(&cookies);
	} else {
		zephir_get_arrval(&cookies, cookies_param);
	}
	if (!queryParams_param) {
		ZEPHIR_INIT_VAR(&queryParams);
		array_init(&queryParams);
	} else {
		zephir_get_arrval(&queryParams, queryParams_param);
	}
	if (!uploadFiles_param) {
		ZEPHIR_INIT_VAR(&uploadFiles);
		array_init(&uploadFiles);
	} else {
		zephir_get_arrval(&uploadFiles, uploadFiles_param);
	}
	if (!parsedBody) {
		parsedBody = &parsedBody_sub;
		parsedBody = &__$null;
	}
	if (!protocol_param) {
		ZEPHIR_INIT_VAR(&protocol);
		ZVAL_STRING(&protocol, "1.1");
	} else {
		zephir_get_strval(&protocol, protocol_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "php://input");
	if (ZEPHIR_IS_IDENTICAL(&_0, body)) {
		ZEPHIR_INIT_NVAR(body);
		object_init_ex(body, phalcon_http_message_stream_input_ce);
		ZEPHIR_CALL_METHOD(NULL, body, "__construct", NULL, 210);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkuploadedfiles", NULL, 240, &uploadFiles);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "processprotocol", NULL, 241, &protocol);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("protocolVersion"), &_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "processmethod", NULL, 242, &method);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("method"), &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "processheaders", NULL, 243, headers);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("headers"), &_3);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "processuri", NULL, 244, uri);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("uri"), &_4);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "w+b");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "processbody", NULL, 245, body, &_6);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("body"), &_5);
	zephir_update_property_zval(this_ptr, SL("uploadedFiles"), &uploadFiles);
	zephir_update_property_zval(this_ptr, SL("parsedBody"), parsedBody);
	zephir_update_property_zval(this_ptr, SL("serverParams"), &serverParams);
	zephir_update_property_zval(this_ptr, SL("cookieParams"), &cookies);
	zephir_update_property_zval(this_ptr, SL("queryParams"), &queryParams);
	ZEPHIR_INIT_NVAR(&_6);
	object_init_ex(&_6, phalcon_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 223);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("attributes"), &_6);
	ZEPHIR_MM_RESTORE();

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *defaultValue = NULL, defaultValue_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, name, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieve attributes derived from the request.
 *
 * The request "attributes" may be used to allow injection of any
 * parameters derived from the request: e.g., the results of path
 * match operations; the results of decrypting cookies; the results of
 * deserializing non-form-encoded message bodies; etc. Attributes
 * will be application and request specific, and CAN be mutable.
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getAttributes) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getHeader) {

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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getHeaderLine) {

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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getHeaders) {

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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getRequestTarget) {

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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, hasHeader) {

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
 * Return an instance with the specified header appended with the given
 * value.
 *
 * Existing values for the specified header will be maintained. The new
 * value(s) will be appended to the existing list. If the header did not
 * exist previously, it will be added.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * new header and/or value.
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withAddedHeader) {

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadername", NULL, 246, name);
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
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getheadervalue", NULL, 247, value);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(value, &_3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_array_merge(&_4, &existing, value TSRMLS_CC);
	ZEPHIR_CPY_WRT(value, &_4);
	ZEPHIR_CALL_METHOD(NULL, &headers, "set", NULL, 0, name, value);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "headers");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 248, &headers, &_4);
	zephir_check_call_status();
	RETURN_MM();

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
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withAttribute) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value, value_sub, attributes, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	zephir_read_property(&_0, this_ptr, SL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_clone(&_1, &_0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&attributes, &_1);
	ZEPHIR_CALL_METHOD(NULL, &attributes, "set", NULL, 0, name, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "attributes");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 248, &attributes, &_2);
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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withBody) {

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
	ZEPHIR_CALL_METHOD(&newBody, this_ptr, "processbody", NULL, 245, body, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "body");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 248, &newBody, &_0);
	zephir_check_call_status();
	RETURN_MM();

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
	ZVAL_STRING(&_0, "cookieParams");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 248, &cookies, &_0);
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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withHeader) {

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadername", NULL, 246, name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_clone(&_1, &_0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&headers, &_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getheadervalue", NULL, 247, value);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(value, &_2);
	ZEPHIR_CALL_METHOD(NULL, &headers, "set", NULL, 0, name, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "headers");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 248, &headers, &_3);
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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withMethod) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processmethod", NULL, 242, method);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "method");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 248, method, &_0);
	zephir_check_call_status();
	RETURN_MM();

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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 248, data, &_0);
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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withProtocolVersion) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *version, version_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processprotocol", NULL, 241, version);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "protocolVersion");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 248, version, &_0);
	zephir_check_call_status();
	RETURN_MM();

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
	ZVAL_STRING(&_0, "queryParams");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 248, &query, &_0);
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
 * immutability of the message, and MUST return an instance that has t
 * changed request target.
 *
 * @see http://tools.ietf.org/html/rfc7230#section-5.3 (for the various
 *     request-target forms allowed in request messages)
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withRequestTarget) {

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid request target: cannot contain whitespace", "phalcon/Http/Message/ServerRequest.zep", 583);
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "requestTarget");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 248, requestTarget, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Create a new instance with the specified uploaded files.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * updated body parameters.
 *
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkuploadedfiles", NULL, 240, &uploadedFiles);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "uploadedFiles");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 248, &uploadedFiles, &_0);
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
		ZEPHIR_CALL_METHOD(&host, this_ptr, "geturihost", NULL, 249, uri);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, attributes, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	zephir_read_property(&_0, this_ptr, SL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_clone(&_1, &_0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&attributes, &_1);
	ZEPHIR_CALL_METHOD(NULL, &attributes, "remove", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "attributes");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 248, &attributes, &_2);
	zephir_check_call_status();
	RETURN_MM();

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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withoutHeader) {

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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 248, &headers, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check the name of the header. Throw exception if not valid
 *
 * @see http://tools.ietf.org/html/rfc7230#section-3.2
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, checkHeaderName) {

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
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 220, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "phalcon/Http/Message/ServerRequest.zep", 704 TSRMLS_CC);
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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, checkHeaderValue) {

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid header value", "phalcon/Http/Message/ServerRequest.zep", 756);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid header value", "phalcon/Http/Message/ServerRequest.zep", 763);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks the uploaded files
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, checkUploadedFiles) {

	zend_bool _3$$5, _4$$9;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *files_param = NULL, file, *_0, _1;
	zval files;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &files_param);

	zephir_get_arrval(&files, files_param);


	zephir_is_iterable(&files, 0, "phalcon/Http/Message/ServerRequest.zep", 784);
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&files), _0)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _0);
			if (Z_TYPE_P(&file) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkuploadedfiles", &_2, 240, &file);
				zephir_check_call_status();
			} else {
				_3$$5 = Z_TYPE_P(&file) == IS_OBJECT;
				if (_3$$5) {
					_3$$5 = zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface") TSRMLS_CC);
				}
				if (!(_3$$5)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid uploaded file", "phalcon/Http/Message/ServerRequest.zep", 779);
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &files, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &files, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &files, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&file) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkuploadedfiles", &_2, 240, &file);
					zephir_check_call_status();
				} else {
					_4$$9 = Z_TYPE_P(&file) == IS_OBJECT;
					if (_4$$9) {
						_4$$9 = zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface") TSRMLS_CC);
					}
					if (!(_4$$9)) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid uploaded file", "phalcon/Http/Message/ServerRequest.zep", 779);
						return;
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &files, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getHeaderValue) {

	zval _4$$5, _5$$6;
	zval valueData;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL, values_sub, value, *_1, _2, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&valueData);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &values);

	ZEPHIR_SEPARATE_PARAM(values);


	if (Z_TYPE_P(values) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_0$$3, values);
		ZEPHIR_CPY_WRT(values, &_0$$3);
	}
	if (ZEPHIR_IS_EMPTY(values)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid header value: must be a string or array of strings; cannot be an empty array", "phalcon/Http/Message/ServerRequest.zep", 816);
		return;
	}
	ZEPHIR_INIT_VAR(&valueData);
	array_init(&valueData);
	zephir_is_iterable(values, 0, "phalcon/Http/Message/ServerRequest.zep", 825);
	if (Z_TYPE_P(values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(values), _1)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadervalue", &_3, 250, &value);
			zephir_check_call_status();
			zephir_get_strval(&_4$$5, &value);
			zephir_array_append(&valueData, &_4$$5, PH_SEPARATE, "phalcon/Http/Message/ServerRequest.zep", 822);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadervalue", &_3, 250, &value);
				zephir_check_call_status();
				zephir_get_strval(&_5$$6, &value);
				zephir_array_append(&valueData, &_5$$6, PH_SEPARATE, "phalcon/Http/Message/ServerRequest.zep", 822);
			ZEPHIR_CALL_METHOD(NULL, values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	RETURN_CTOR(&valueData);

}

/**
 * Return the host and if applicable the port
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getUriHost) {

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
PHP_METHOD(Phalcon_Http_Message_ServerRequest, processBody) {

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid stream passed as a parameter", "phalcon/Http/Message/ServerRequest.zep", 855);
		return;
	}
	object_init_ex(return_value, phalcon_http_message_stream_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 222, body, &mode);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the headers
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, processHeaders) {

	zval _18$$6;
	zval _5$$4, _9$$5;
	zend_bool _13$$3;
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers, headers_sub, collection, host, name, value, *_0$$3, _1$$3, _11$$3, _12$$3, _14$$3, _15$$3, _16$$3, _6$$4, _10$$5, _17$$6, _19$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_18$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers);



	if (Z_TYPE_P(headers) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&collection);
		object_init_ex(&collection, phalcon_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 223);
		zephir_check_call_status();
		zephir_is_iterable(headers, 0, "phalcon/Http/Message/ServerRequest.zep", 880);
		if (Z_TYPE_P(headers) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(headers), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&name);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&name, _3$$3);
				} else {
					ZVAL_LONG(&name, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadername", &_4, 246, &name);
				zephir_check_call_status();
				zephir_get_strval(&_5$$4, &name);
				ZEPHIR_CPY_WRT(&name, &_5$$4);
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "getheadervalue", &_7, 247, &value);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_6$$4);
				ZEPHIR_CALL_METHOD(NULL, &collection, "set", &_8, 224, &name, &value);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, headers, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, headers, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&name, headers, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, headers, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadername", &_4, 246, &name);
					zephir_check_call_status();
					zephir_get_strval(&_9$$5, &name);
					ZEPHIR_CPY_WRT(&name, &_9$$5);
					ZEPHIR_CALL_METHOD(&_10$$5, this_ptr, "getheadervalue", &_7, 247, &value);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&value, &_10$$5);
					ZEPHIR_CALL_METHOD(NULL, &collection, "set", &_8, 224, &name, &value);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, headers, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&name);
		ZEPHIR_INIT_VAR(&_12$$3);
		ZVAL_STRING(&_12$$3, "host");
		ZEPHIR_CALL_METHOD(&_11$$3, &collection, "has", NULL, 225, &_12$$3);
		zephir_check_call_status();
		_13$$3 = ZEPHIR_IS_TRUE_IDENTICAL(&_11$$3);
		if (_13$$3) {
			zephir_read_property(&_14$$3, this_ptr, SL("uri"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_15$$3, &_14$$3, "gethost", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_SINIT_VAR(_16$$3);
			ZVAL_STRING(&_16$$3, "");
			_13$$3 = !ZEPHIR_IS_IDENTICAL(&_16$$3, &_15$$3);
		}
		if (_13$$3) {
			zephir_read_property(&_17$$6, this_ptr, SL("uri"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&host, this_ptr, "geturihost", NULL, 249, &_17$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_18$$6);
			zephir_create_array(&_18$$6, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_18$$6, &host);
			ZEPHIR_INIT_VAR(&_19$$6);
			ZVAL_STRING(&_19$$6, "Host");
			ZEPHIR_CALL_METHOD(NULL, &collection, "set", &_8, 224, &_19$$6, &_18$$6);
			zephir_check_call_status();
		}
	} else {
		if (zephir_instance_of_ev(headers, phalcon_collection_ce TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(&collection, headers);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Headers need to be either an array or instance of Phalcon\\Collection", "phalcon/Http/Message/ServerRequest.zep", 891);
			return;
		}
	}
	RETURN_CCTOR(&collection);

}

/**
 * Check the method
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, processMethod) {

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
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 220, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Http/Message/ServerRequest.zep", 920 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(method, 1, 0);
	RETURN_MM();

}

/**
 * Checks the protocol
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, processProtocol) {

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid protocol value", "phalcon/Http/Message/ServerRequest.zep", 941);
		return;
	}
	if (!(zephir_array_isset(&protocols, protocol))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "Unsupported protocol ", protocol);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 220, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Http/Message/ServerRequest.zep", 947 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(protocol, 1, 0);
	RETURN_MM();

}

/**
 * Sets a valid Uri
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, processUri) {

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
		ZEPHIR_CALL_METHOD(NULL, &localUri, "__construct", NULL, 226, uri);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid uri passed as a parameter", "phalcon/Http/Message/ServerRequest.zep", 967);
		return;
	}
	RETURN_CCTOR(&localUri);

}

zend_object *zephir_init_properties_Phalcon_Http_Message_ServerRequest(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);

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
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

