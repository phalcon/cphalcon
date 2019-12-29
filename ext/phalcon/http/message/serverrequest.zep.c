
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
#include "kernel/exception.h"


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
 * PSR-7 ServerRequest
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_ServerRequest) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http\\Message, ServerRequest, phalcon, http_message_serverrequest, phalcon_http_message_abstractrequest_ce, phalcon_http_message_serverrequest_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var Collection
	 */
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("attributes"), ZEND_ACC_PRIVATE);

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
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("cookieParams"), ZEND_ACC_PRIVATE);

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
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("parsedBody"), ZEND_ACC_PRIVATE);

	/**
	 * Retrieve query string arguments.
	 *
	 * Retrieves the deserialized query string arguments, if any.
	 *
	 * Note: the query params might not be in sync with the URI or server
	 * params. If you need to ensure you are only getting the original
	 * values, you may need to parse the query string from
	 * `getUri()->getQuery()` or from the `QUERY_STRING` server param.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("queryParams"), ZEND_ACC_PRIVATE);

	/**
	 * Retrieve server parameters.
	 *
	 * Retrieves data related to the incoming request environment,
	 * typically derived from PHP's $_SERVER superglobal. The data IS NOT
	 * REQUIRED to originate from $_SERVER.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("serverParams"), ZEND_ACC_PRIVATE);

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
	zend_declare_property_null(phalcon_http_message_serverrequest_ce, SL("uploadedFiles"), ZEND_ACC_PRIVATE);

	phalcon_http_message_serverrequest_ce->create_object = zephir_init_properties_Phalcon_Http_Message_ServerRequest;

	zend_class_implements(phalcon_http_message_serverrequest_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\serverrequestinterface")));
	return SUCCESS;

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
 * Retrieve query string arguments.
 *
 *
 * Retrieves the deserialized query string arguments, if any.
 * 
 * Note: the query params might not be in sync with the URI or server
 * params. If you need to ensure you are only getting the original
 * values, you may need to parse the query string from
 * `getUri()->getQuery()` or from the `QUERY_STRING` server param.
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
 * ServerRequest constructor.
 *
 * @param string                   $method
 * @param UriInterface|string|null $uri
 * @param array                    $serverParams
 * @param StreamInterface|string   $body
 * @param array                    $headers
 * @param array                    $cookies
 * @param array                    $queryParams
 * @param array                    $uploadFiles
 * @param null|array|object        $parsedBody
 * @param string                   $protocol
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php://input");
	if (UNEXPECTED(ZEPHIR_IS_IDENTICAL(&_0, body))) {
		ZEPHIR_INIT_NVAR(body);
		object_init_ex(body, phalcon_http_message_stream_input_ce);
		ZEPHIR_CALL_METHOD(NULL, body, "__construct", NULL, 281);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkuploadedfiles", NULL, 292, &uploadFiles);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "processprotocol", NULL, 37, &protocol);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("protocolVersion"), &_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "processmethod", NULL, 101, &method);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("method"), &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "processheaders", NULL, 283, headers);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("headers"), &_3);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "processuri", NULL, 282, uri);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("uri"), &_4);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "w+b");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "processbody", NULL, 36, body, &_6);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("body"), &_5);
	zephir_update_property_zval(this_ptr, SL("uploadedFiles"), &uploadFiles);
	zephir_update_property_zval(this_ptr, SL("parsedBody"), parsedBody);
	zephir_update_property_zval(this_ptr, SL("serverParams"), &serverParams);
	zephir_update_property_zval(this_ptr, SL("cookieParams"), &cookies);
	zephir_update_property_zval(this_ptr, SL("queryParams"), &queryParams);
	ZEPHIR_INIT_NVAR(&_6);
	object_init_ex(&_6, phalcon_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 21);
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
 *
 * @param string        $name
 * @param mixed|null    $defaultValue
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
 * The request 'attributes' may be used to allow injection of any
 * parameters derived from the request: e.g., the results of path
 * match operations; the results of decrypting cookies; the results of
 * deserializing non-form-encoded message bodies; etc. Attributes
 * will be application and request specific, and CAN be mutable.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getAttributes) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
 * Return an instance with the specified derived request attribute.
 *
 * This method allows setting a single derived request attribute as
 * described in getAttributes().
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * updated attribute.
 *
 * @param string $name
 * @param mixed  $value
 *
 * @return ServerRequest
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	if (zephir_clone(&_1, &_0) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&attributes, &_1);
	ZEPHIR_CALL_METHOD(NULL, &attributes, "set", NULL, 0, name, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "attributes");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 20, &attributes, &_2);
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
 *
 * @param array $cookies
 *
 * @return ServerRequest
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withCookieParams) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 20, &cookies, &_0);
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
 * structured data, and, as such, this method ONLY accepts arrays or
 * objects, or a null value if nothing was available to parse.
 *
 * As an example, if content negotiation determines that the request data
 * is a JSON payload, this method could be used to create a request
 * instance with the deserialized parameters.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * updated body parameters.
 *
 * @param array|object|null $data
 *
 * @return ServerRequest
 * @throws InvalidArgumentException if an unsupported argument type is provided.
 *
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withParsedBody) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "parsedBody");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 20, data, &_0);
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
 *
 * @param array $query
 *
 * @return ServerRequest
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withQueryParams) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 20, &query, &_0);
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
 * @param array $uploadedFiles
 *
 * @return ServerRequest
 * @throws InvalidArgumentException if an invalid structure is provided.
 *
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withUploadedFiles) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uploadedFiles_param = NULL, _0;
	zval uploadedFiles;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uploadedFiles);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uploadedFiles_param);

	zephir_get_arrval(&uploadedFiles, uploadedFiles_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkuploadedfiles", NULL, 292, &uploadedFiles);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "uploadedFiles");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 20, &uploadedFiles, &_0);
	zephir_check_call_status();
	RETURN_MM();

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
 *
 * @param string $name
 *
 * @return ServerRequest
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withoutAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	if (zephir_clone(&_1, &_0) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&attributes, &_1);
	ZEPHIR_CALL_METHOD(NULL, &attributes, "remove", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "attributes");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 20, &attributes, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks the uploaded files
 *
 * @param array $files
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequest, checkUploadedFiles) {

	zend_bool _3$$5, _4$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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


	zephir_is_iterable(&files, 0, "phalcon/Http/Message/ServerRequest.zep", 353);
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&files), _0)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _0);
			if (UNEXPECTED(Z_TYPE_P(&file) == IS_ARRAY)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkuploadedfiles", &_2, 292, &file);
				zephir_check_call_status();
			} else {
				_3$$5 = Z_TYPE_P(&file) == IS_OBJECT;
				if (_3$$5) {
					_3$$5 = zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface"));
				}
				if (UNEXPECTED(!(_3$$5))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Invalid uploaded file", "phalcon/Http/Message/ServerRequest.zep", 349);
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
				if (UNEXPECTED(Z_TYPE_P(&file) == IS_ARRAY)) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkuploadedfiles", &_2, 292, &file);
					zephir_check_call_status();
				} else {
					_4$$9 = Z_TYPE_P(&file) == IS_OBJECT;
					if (_4$$9) {
						_4$$9 = zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface"));
					}
					if (UNEXPECTED(!(_4$$9))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Invalid uploaded file", "phalcon/Http/Message/ServerRequest.zep", 349);
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

zend_object *zephir_init_properties_Phalcon_Http_Message_ServerRequest(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

