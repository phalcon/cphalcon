
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
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
 * PSR-17 ServerRequestFactory
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_ServerRequestFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, ServerRequestFactory, phalcon, http_message_serverrequestfactory, phalcon_http_message_serverrequestfactory_method_entry, 0);

	zend_class_implements(phalcon_http_message_serverrequestfactory_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\serverrequestfactoryinterface")));
	zend_class_implements(phalcon_http_message_serverrequestfactory_ce, 1, phalcon_http_message_requestmethodinterface_ce);
	return SUCCESS;
}

/**
 * Create a new server request.
 *
 * Note that server-params are taken precisely as given - no
 * parsing/processing of the given values is performed, and, in particular,
 * no attempt is made to determine the HTTP method or URI, which must be
 * provided explicitly.
 *
 * @param string              $method       The HTTP method associated with
 *                                          the request.
 * @param UriInterface|string $uri          The URI associated with the
 *                                          request. If the value is a
 *                                          string, the factory MUST create
 *                                          a UriInterface instance based
 *                                          on it.
 * @param array               $serverParams Array of SAPI parameters with
 *                                          which to seed the generated
 *                                          request instance.
 *
 * @return ServerRequestInterface
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, createServerRequest)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval serverParams;
	zval *method_param = NULL, *uri, uri_sub, *serverParams_param = NULL;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&serverParams);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(method)
		Z_PARAM_ZVAL(uri)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(serverParams)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &method_param, &uri, &serverParams_param);
	zephir_get_strval(&method, method_param);
	if (!serverParams_param) {
		ZEPHIR_INIT_VAR(&serverParams);
		array_init(&serverParams);
	} else {
		zephir_get_arrval(&serverParams, serverParams_param);
	}


	object_init_ex(return_value, phalcon_http_message_serverrequest_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 332, &method, uri, &serverParams);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Create a request from the supplied superglobal values.
 *
 * If any argument is not supplied, the corresponding superglobal value will
 * be used.
 *
 * @param array $server  $_SERVER superglobal
 * @param array $get     $_GET superglobal
 * @param array $post    $_POST superglobal
 * @param array $cookies $_COOKIE superglobal
 * @param array $files   $_FILES superglobal
 *
 * @return ServerRequest
 * @see fromServer()
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, load)
{
	zend_bool _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *server_param = NULL, *get_param = NULL, *post_param = NULL, *cookies_param = NULL, *files_param = NULL, _COOKIE, _FILES, _GET, _POST, _SERVER, cookiesCollection, filesCollection, headers, method, protocol, serverCollection, _0, _1, _2, _3, _4, _5, _6, _8, _11, _12, _13, _14, _9$$8, _10$$8;
	zval server, get, post, cookies, files, globalCookies, globalFiles, globalGet, globalPost, globalServer;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&get);
	ZVAL_UNDEF(&post);
	ZVAL_UNDEF(&cookies);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&globalCookies);
	ZVAL_UNDEF(&globalFiles);
	ZVAL_UNDEF(&globalGet);
	ZVAL_UNDEF(&globalPost);
	ZVAL_UNDEF(&globalServer);
	ZVAL_UNDEF(&_COOKIE);
	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&cookiesCollection);
	ZVAL_UNDEF(&filesCollection);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&protocol);
	ZVAL_UNDEF(&serverCollection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(server)
		Z_PARAM_ARRAY_OR_NULL(get)
		Z_PARAM_ARRAY_OR_NULL(post)
		Z_PARAM_ARRAY_OR_NULL(cookies)
		Z_PARAM_ARRAY_OR_NULL(files)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_fetch_params(1, 0, 5, &server_param, &get_param, &post_param, &cookies_param, &files_param);
	if (!server_param) {
		ZEPHIR_INIT_VAR(&server);
	} else {
		zephir_get_arrval(&server, server_param);
	}
	if (!get_param) {
		ZEPHIR_INIT_VAR(&get);
	} else {
		zephir_get_arrval(&get, get_param);
	}
	if (!post_param) {
		ZEPHIR_INIT_VAR(&post);
	} else {
		zephir_get_arrval(&post, post_param);
	}
	if (!cookies_param) {
		ZEPHIR_INIT_VAR(&cookies);
	} else {
		zephir_get_arrval(&cookies, cookies_param);
	}
	if (!files_param) {
		ZEPHIR_INIT_VAR(&files);
	} else {
		zephir_get_arrval(&files, files_param);
	}


	ZEPHIR_INIT_VAR(&globalCookies);
	array_init(&globalCookies);
	ZEPHIR_INIT_VAR(&globalFiles);
	array_init(&globalFiles);
	ZEPHIR_INIT_VAR(&globalGet);
	array_init(&globalGet);
	ZEPHIR_INIT_VAR(&globalPost);
	array_init(&globalPost);
	ZEPHIR_INIT_VAR(&globalServer);
	array_init(&globalServer);
	if (!(ZEPHIR_IS_EMPTY(&_COOKIE))) {
		ZEPHIR_CPY_WRT(&globalCookies, &_COOKIE);
	}
	if (!(ZEPHIR_IS_EMPTY(&_FILES))) {
		ZEPHIR_CPY_WRT(&globalFiles, &_FILES);
	}
	if (!(ZEPHIR_IS_EMPTY(&_GET))) {
		ZEPHIR_CPY_WRT(&globalGet, &_GET);
	}
	if (!(ZEPHIR_IS_EMPTY(&_POST))) {
		ZEPHIR_CPY_WRT(&globalPost, &_POST);
	}
	if (!(ZEPHIR_IS_EMPTY(&_SERVER))) {
		ZEPHIR_CPY_WRT(&globalServer, &_SERVER);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checknullarray", NULL, 333, &server, &globalServer);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&server, &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "checknullarray", NULL, 333, &files, &globalFiles);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&files, &_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "checknullarray", NULL, 333, &cookies, &globalCookies);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&cookies, &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "checknullarray", NULL, 333, &get, &globalGet);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&get, &_3);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "checknullarray", NULL, 333, &post, &globalPost);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&post, &_4);
	ZEPHIR_CALL_METHOD(&serverCollection, this_ptr, "parseserver", NULL, 334, &server);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "REQUEST_METHOD");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "GET");
	ZEPHIR_CALL_METHOD(&method, &serverCollection, "get", NULL, 0, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&protocol, this_ptr, "parseprotocol", NULL, 335, &serverCollection);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&headers, this_ptr, "parseheaders", NULL, 336, &serverCollection);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&filesCollection, this_ptr, "parseuploadedfiles", NULL, 337, &files);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&cookiesCollection, &cookies);
	_7 = ZEPHIR_IS_EMPTY(&cookies);
	if (_7) {
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_STRING(&_5, "cookie");
		ZEPHIR_CALL_METHOD(&_8, &headers, "has", NULL, 0, &_5);
		zephir_check_call_status();
		_7 = zephir_is_true(&_8);
	}
	if (UNEXPECTED(_7)) {
		ZEPHIR_INIT_VAR(&_10$$8);
		ZVAL_STRING(&_10$$8, "cookie");
		ZEPHIR_CALL_METHOD(&_9$$8, &headers, "get", NULL, 0, &_10$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&cookiesCollection, this_ptr, "parsecookieheader", NULL, 338, &_9$$8);
		zephir_check_call_status();
	}
	object_init_ex(return_value, phalcon_http_message_serverrequest_ce);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "parseuri", NULL, 339, &serverCollection, &headers);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, &serverCollection, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_13, &headers, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_14, &filesCollection, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "php://input");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 332, &method, &_11, &_12, &_5, &_13, &cookiesCollection, &get, &_14, &post, &protocol);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the apache_request_headers if it exists
 *
 * @return array|false
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, getHeaders)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	if (EXPECTED((zephir_function_exists_ex(ZEND_STRL("apache_request_headers")) == SUCCESS))) {
		ZEPHIR_RETURN_CALL_FUNCTION("apache_request_headers", NULL, 340);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);
}

/**
 * Calculates the host and port from the headers or the server superglobal
 *
 * @param CollectionInterface $server
 * @param CollectionInterface $headers
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, calculateUriHost)
{
	zval defaults;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *server, server_sub, *headers, headers_sub, __$null, host, port, _0, _1, _2, _4, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&server_sub);
	ZVAL_UNDEF(&headers_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&defaults);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(server, phalcon_support_collection_collectioninterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(headers, phalcon_support_collection_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &server, &headers);


	ZEPHIR_INIT_VAR(&defaults);
	zephir_create_array(&defaults, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_array_fast_append(&defaults, &_0);
	zephir_array_fast_append(&defaults, &__$null);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "host");
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getheader", NULL, 341, headers, &_0, &_2);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "host");
		ZEPHIR_CALL_METHOD(&host, this_ptr, "getheader", NULL, 341, headers, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "calculateurihostfromheader", NULL, 342, &host);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "SERVER_NAME");
	ZEPHIR_CALL_METHOD(&_4, server, "has", NULL, 0, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_4))) {
		RETURN_CTOR(&defaults);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "SERVER_NAME");
	ZEPHIR_CALL_METHOD(&host, server, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "SERVER_PORT");
	ZVAL_NULL(&_2);
	ZEPHIR_CALL_METHOD(&port, server, "get", NULL, 0, &_0, &_2);
	zephir_check_call_status();
	zephir_create_array(return_value, 2, 0);
	zephir_array_fast_append(return_value, &host);
	zephir_array_fast_append(return_value, &port);
	RETURN_MM();
}

/**
 * Get the host and calculate the port if present from the header
 *
 * @param string $host
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, calculateUriHostFromHeader)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *host_param = NULL, matches, port, _0, _1, _2, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3;
	zval host;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(host)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &host_param);
	zephir_get_strval(&host, host_param);


	ZEPHIR_INIT_VAR(&port);
	ZVAL_NULL(&port);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "|:(\\d+)$|");
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "|:(\\d+)$|");
	zephir_preg_match(&_1, &_2, &host, &matches, 0, 0 , 0 );
	if (UNEXPECTED(zephir_is_true(&_1))) {
		zephir_array_fetch_long(&_3$$3, &matches, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Message/ServerRequestFactory.zep", 200);
		ZVAL_LONG(&_4$$3, 0);
		ZVAL_LONG(&_5$$3, (-1 * ((zephir_fast_strlen_ev(&_3$$3) + 1))));
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_substr(&_6$$3, &host, 0 , zephir_get_intval(&_5$$3), 0);
		zephir_get_strval(&host, &_6$$3);
		ZEPHIR_OBS_VAR(&_7$$3);
		zephir_array_fetch_long(&_7$$3, &matches, 1, PH_NOISY, "phalcon/Http/Message/ServerRequestFactory.zep", 201);
		ZEPHIR_INIT_NVAR(&port);
		ZVAL_LONG(&port, zephir_get_intval(&_7$$3));
	}
	zephir_create_array(return_value, 2, 0);
	zephir_array_fast_append(return_value, &host);
	zephir_array_fast_append(return_value, &port);
	RETURN_MM();
}

/**
 * Get the path from the request from IIS7/Rewrite, REQUEST_URL or
 * ORIG_PATH_INFO
 *
 * @param CollectionInterface $server
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, calculateUriPath)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *server, server_sub, iisRewrite, origPathInfo, requestUri, unencodedUrl, _0, _1, _2, _3, _5$$4, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&server_sub);
	ZVAL_UNDEF(&iisRewrite);
	ZVAL_UNDEF(&origPathInfo);
	ZVAL_UNDEF(&requestUri);
	ZVAL_UNDEF(&unencodedUrl);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(server, phalcon_support_collection_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &server);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "IIS_WasUrlRewritten");
	ZVAL_NULL(&_1);
	ZEPHIR_CALL_METHOD(&iisRewrite, server, "get", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "UNENCODED_URL");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_CALL_METHOD(&unencodedUrl, server, "get", NULL, 0, &_0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "1");
	_4 = ZEPHIR_IS_IDENTICAL(&_3, &iisRewrite);
	if (_4) {
		_4 = !(ZEPHIR_IS_EMPTY(&unencodedUrl));
	}
	if (UNEXPECTED(_4)) {
		RETURN_CCTOR(&unencodedUrl);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "REQUEST_URI");
	ZVAL_NULL(&_1);
	ZEPHIR_CALL_METHOD(&requestUri, server, "get", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&requestUri) != IS_NULL)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "#^[^/:]+://[^/]+#");
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "");
		ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 50, &_5$$4, &_6$$4, &requestUri);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "ORIG_PATH_INFO");
	ZVAL_NULL(&_1);
	ZEPHIR_CALL_METHOD(&origPathInfo, server, "get", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&origPathInfo))) {
		RETURN_MM_STRING("/");
	}
	RETURN_CCTOR(&origPathInfo);
}

/**
 * Get the query string from the server array
 *
 * @param CollectionInterface $server
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, calculateUriQuery)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *server, server_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&server_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(server, phalcon_support_collection_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &server);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "QUERY_STRING");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_CALL_METHOD(&_0, server, "get", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "?");
	zephir_fast_trim(return_value, &_0, &_1, ZEPHIR_TRIM_LEFT);
	RETURN_MM();
}

/**
 * Calculates the scheme from the server variables
 *
 * @param CollectionInterface $server
 * @param CollectionInterface $headers
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, calculateUriScheme)
{
	double _7$$3;
	zend_bool _9;
	zval scheme, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *server, server_sub, *headers, headers_sub, header, isHttps, _0, _1, _8, _10, _2$$3, _3$$3, _4$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&server_sub);
	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&isHttps);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&_5$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(server, phalcon_support_collection_collectioninterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(headers, phalcon_support_collection_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &server, &headers);


	ZEPHIR_INIT_VAR(&scheme);
	ZVAL_STRING(&scheme, "https");
	ZEPHIR_INIT_VAR(&isHttps);
	ZVAL_BOOL(&isHttps, 1);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HTTPS");
	ZEPHIR_CALL_METHOD(&_0, server, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "HTTPS");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "on");
		ZEPHIR_CALL_METHOD(&_2$$3, server, "get", NULL, 0, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_cast_to_string(&_5$$3, &_2$$3);
		ZEPHIR_CPY_WRT(&isHttps, &_5$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_fast_strtolower(&_3$$3, &isHttps);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "off");
		_7$$3 = !ZEPHIR_IS_IDENTICAL(&_6$$3, &_3$$3);
		ZEPHIR_INIT_NVAR(&isHttps);
		ZVAL_BOOL(&isHttps, _7$$3);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "x-forwarded-proto");
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "https");
	ZEPHIR_CALL_METHOD(&header, this_ptr, "getheader", NULL, 341, headers, &_1, &_8);
	zephir_check_call_status();
	_9 = !zephir_is_true(&isHttps);
	if (!(_9)) {
		ZEPHIR_INIT_VAR(&_10);
		ZVAL_STRING(&_10, "https");
		_9 = !ZEPHIR_IS_IDENTICAL(&_10, &header);
	}
	if (UNEXPECTED(_9)) {
		ZEPHIR_INIT_NVAR(&scheme);
		ZVAL_STRING(&scheme, "http");
	}
	RETURN_CTOR(&scheme);
}

/**
 * Checks the source if it null and returns the super, otherwise the source
 * array
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, checkNullArray)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval super;
	zval *source, source_sub, *super_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source_sub);
	ZVAL_UNDEF(&super);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(source)
		Z_PARAM_ARRAY(super)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &source, &super_param);
	zephir_get_arrval(&super, super_param);


	if (UNEXPECTED(ZEPHIR_IS_EMPTY(source))) {
		RETURN_CTOR(&super);
	}
	RETVAL_ZVAL(source, 1, 0);
	RETURN_MM();
}

/**
 * Create an UploadedFile object from an $_FILES array element
 *
 * @param array $file The $_FILES element
 *
 * @return UploadedFile
 *
 * @throws InvalidArgumentException If one of the elements is missing
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, createUploadedFile)
{
	zval _3$$3;
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, name, type, _4, _5, _6, _2$$3;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(file)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);
	zephir_get_arrval(&file, file_param);


	_0 = !(zephir_array_isset_string(&file, SL("tmp_name")));
	if (!(_0)) {
		_0 = !(zephir_array_isset_string(&file, SL("size")));
	}
	_1 = _0;
	if (!(_1)) {
		_1 = !(zephir_array_isset_string(&file, SL("error")));
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_http_message_exception_invalidargumentexception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SS(&_3$$3, "The file array must contain tmp_name, size and error; ", "one or more are missing");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 40, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Http/Message/ServerRequestFactory.zep", 319);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_array_isset_string(&file, SL("name"))) {
		ZEPHIR_OBS_VAR(&name);
		zephir_array_fetch_string(&name, &file, SL("name"), PH_NOISY, "phalcon/Http/Message/ServerRequestFactory.zep", 322);
	} else {
		ZEPHIR_INIT_NVAR(&name);
		ZVAL_NULL(&name);
	}
	if (zephir_array_isset_string(&file, SL("type"))) {
		ZEPHIR_OBS_VAR(&type);
		zephir_array_fetch_string(&type, &file, SL("type"), PH_NOISY, "phalcon/Http/Message/ServerRequestFactory.zep", 323);
	} else {
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_NULL(&type);
	}
	object_init_ex(return_value, phalcon_http_message_uploadedfile_ce);
	zephir_array_fetch_string(&_4, &file, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/Http/Message/ServerRequestFactory.zep", 326);
	zephir_array_fetch_string(&_5, &file, SL("size"), PH_NOISY | PH_READONLY, "phalcon/Http/Message/ServerRequestFactory.zep", 327);
	zephir_array_fetch_string(&_6, &file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Http/Message/ServerRequestFactory.zep", 328);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 343, &_4, &_5, &_6, &name, &type);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a header
 *
 * @param CollectionInterface $headers
 * @param string     $name
 * @param mixed|null $defaultValue
 *
 * @return mixed|string
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, getHeader)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *headers, headers_sub, *name_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&name);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(headers, phalcon_support_collection_collectioninterface_ce)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &headers, &name_param, &defaultValue);
	zephir_get_strval(&name, name_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_CALL_METHOD(&value, headers, "get", NULL, 0, &name, defaultValue);
	zephir_check_call_status();
	if (Z_TYPE_P(&value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_fast_join_str(&_0$$3, SL(","), &value);
		ZEPHIR_CPY_WRT(&value, &_0$$3);
	}
	RETURN_CCTOR(&value);
}

/**
 * Parse a cookie header according to RFC 6265.
 *
 * @param string $cookieHeader A string cookie header value.
 *
 * @return array key/value cookie pairs.
 *
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, parseCookieHeader)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cookieHeader_param = NULL, cookies, _1;
	zval cookieHeader;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookieHeader);
	ZVAL_UNDEF(&cookies);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(cookieHeader)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cookieHeader_param);
	zephir_get_strval(&cookieHeader, cookieHeader_param);


	ZEPHIR_INIT_VAR(&cookies);
	array_init(&cookies);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	add_assoc_stringl_ex(&_0, SL("&"), SL("%26"));
	add_assoc_stringl_ex(&_0, SL("+"), SL("%2B"));
	add_assoc_stringl_ex(&_0, SL(";"), SL("&"));
	ZEPHIR_CALL_FUNCTION(&_1, "strtr", NULL, 5, &cookieHeader, &_0);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&cookies);
	ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 344, &_1, &cookies);
	ZEPHIR_UNREF(&cookies);
	zephir_check_call_status();
	RETURN_CCTOR(&cookies);
}

/**
 * Processes headers from SAPI
 *
 * @param CollectionInterface $server
 *
 * @return CollectionInterface
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, parseHeaders)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_18 = NULL, *_30 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *server, server_sub, headers, key, name, serverArray, value, *_0, _1, _4$$3, _5$$4, _6$$4, _11$$4, _12$$4, _19$$4, _20$$4, _7$$5, _8$$5, _9$$5, _13$$7, _14$$7, _15$$7, _16$$7, _17$$7, _21$$8, _22$$8, _23$$8, _24$$9, _25$$10, _26$$10, _31$$10, _32$$10, _38$$10, _39$$10, _27$$11, _28$$11, _29$$11, _33$$13, _34$$13, _35$$13, _36$$13, _37$$13, _40$$14, _41$$14, _42$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&server_sub);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&serverArray);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_31$$10);
	ZVAL_UNDEF(&_32$$10);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_41$$14);
	ZVAL_UNDEF(&_42$$14);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(server, phalcon_support_collection_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &server);


	ZEPHIR_INIT_VAR(&headers);
	object_init_ex(&headers, phalcon_support_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, &headers, "__construct", NULL, 25);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&serverArray, server, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&serverArray, 0, "phalcon/Http/Message/ServerRequestFactory.zep", 438);
	if (Z_TYPE_P(&serverArray) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&serverArray), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "");
			if (EXPECTED(!ZEPHIR_IS_IDENTICAL(&_4$$3, &value))) {
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZVAL_STRING(&_5$$4, "REDIRECT_");
				ZEPHIR_INIT_NVAR(&_6$$4);
				zephir_fast_strpos(&_6$$4, &key, &_5$$4, 0 );
				if (UNEXPECTED(ZEPHIR_IS_LONG_IDENTICAL(&_6$$4, 0))) {
					ZVAL_LONG(&_7$$5, 9);
					ZEPHIR_INIT_NVAR(&_8$$5);
					zephir_substr(&_8$$5, &key, 9 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					ZEPHIR_CPY_WRT(&key, &_8$$5);
					ZEPHIR_CALL_METHOD(&_9$$5, server, "has", &_10, 0, &key);
					zephir_check_call_status();
					if (UNEXPECTED(ZEPHIR_IS_TRUE_IDENTICAL(&_9$$5))) {
						continue;
					}
				}
				ZEPHIR_INIT_NVAR(&_11$$4);
				ZVAL_STRING(&_11$$4, "HTTP_");
				ZEPHIR_INIT_NVAR(&_12$$4);
				zephir_fast_strpos(&_12$$4, &key, &_11$$4, 0 );
				if (EXPECTED(ZEPHIR_IS_LONG_IDENTICAL(&_12$$4, 0))) {
					ZEPHIR_INIT_NVAR(&_13$$7);
					ZVAL_LONG(&_14$$7, 5);
					ZEPHIR_INIT_NVAR(&_15$$7);
					zephir_substr(&_15$$7, &key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_fast_strtolower(&_13$$7, &_15$$7);
					ZEPHIR_INIT_NVAR(&_16$$7);
					ZVAL_STRING(&_16$$7, "_");
					ZEPHIR_INIT_NVAR(&_17$$7);
					ZVAL_STRING(&_17$$7, "-");
					ZEPHIR_INIT_NVAR(&name);
					zephir_fast_str_replace(&name, &_16$$7, &_17$$7, &_13$$7);
					ZEPHIR_CALL_METHOD(NULL, &headers, "set", &_18, 42, &name, &value);
					zephir_check_call_status();
					continue;
				}
				ZEPHIR_INIT_NVAR(&_19$$4);
				ZVAL_STRING(&_19$$4, "CONTENT_");
				ZEPHIR_INIT_NVAR(&_20$$4);
				zephir_fast_strpos(&_20$$4, &key, &_19$$4, 0 );
				if (UNEXPECTED(ZEPHIR_IS_LONG_IDENTICAL(&_20$$4, 0))) {
					ZEPHIR_INIT_NVAR(&_21$$8);
					ZVAL_LONG(&_22$$8, 8);
					ZEPHIR_INIT_NVAR(&_23$$8);
					zephir_substr(&_23$$8, &key, 8 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_fast_strtolower(&_21$$8, &_23$$8);
					ZEPHIR_INIT_NVAR(&name);
					ZEPHIR_CONCAT_SV(&name, "content-", &_21$$8);
					ZEPHIR_CALL_METHOD(NULL, &headers, "set", &_18, 42, &name, &value);
					zephir_check_call_status();
					continue;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &serverArray, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &serverArray, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &serverArray, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &serverArray, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_24$$9);
				ZVAL_STRING(&_24$$9, "");
				if (EXPECTED(!ZEPHIR_IS_IDENTICAL(&_24$$9, &value))) {
					ZEPHIR_INIT_NVAR(&_25$$10);
					ZVAL_STRING(&_25$$10, "REDIRECT_");
					ZEPHIR_INIT_NVAR(&_26$$10);
					zephir_fast_strpos(&_26$$10, &key, &_25$$10, 0 );
					if (UNEXPECTED(ZEPHIR_IS_LONG_IDENTICAL(&_26$$10, 0))) {
						ZVAL_LONG(&_27$$11, 9);
						ZEPHIR_INIT_NVAR(&_28$$11);
						zephir_substr(&_28$$11, &key, 9 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
						ZEPHIR_CPY_WRT(&key, &_28$$11);
						ZEPHIR_CALL_METHOD(&_29$$11, server, "has", &_30, 0, &key);
						zephir_check_call_status();
						if (UNEXPECTED(ZEPHIR_IS_TRUE_IDENTICAL(&_29$$11))) {
							continue;
						}
					}
					ZEPHIR_INIT_NVAR(&_31$$10);
					ZVAL_STRING(&_31$$10, "HTTP_");
					ZEPHIR_INIT_NVAR(&_32$$10);
					zephir_fast_strpos(&_32$$10, &key, &_31$$10, 0 );
					if (EXPECTED(ZEPHIR_IS_LONG_IDENTICAL(&_32$$10, 0))) {
						ZEPHIR_INIT_NVAR(&_33$$13);
						ZVAL_LONG(&_34$$13, 5);
						ZEPHIR_INIT_NVAR(&_35$$13);
						zephir_substr(&_35$$13, &key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_fast_strtolower(&_33$$13, &_35$$13);
						ZEPHIR_INIT_NVAR(&_36$$13);
						ZVAL_STRING(&_36$$13, "_");
						ZEPHIR_INIT_NVAR(&_37$$13);
						ZVAL_STRING(&_37$$13, "-");
						ZEPHIR_INIT_NVAR(&name);
						zephir_fast_str_replace(&name, &_36$$13, &_37$$13, &_33$$13);
						ZEPHIR_CALL_METHOD(NULL, &headers, "set", &_18, 42, &name, &value);
						zephir_check_call_status();
						continue;
					}
					ZEPHIR_INIT_NVAR(&_38$$10);
					ZVAL_STRING(&_38$$10, "CONTENT_");
					ZEPHIR_INIT_NVAR(&_39$$10);
					zephir_fast_strpos(&_39$$10, &key, &_38$$10, 0 );
					if (UNEXPECTED(ZEPHIR_IS_LONG_IDENTICAL(&_39$$10, 0))) {
						ZEPHIR_INIT_NVAR(&_40$$14);
						ZVAL_LONG(&_41$$14, 8);
						ZEPHIR_INIT_NVAR(&_42$$14);
						zephir_substr(&_42$$14, &key, 8 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_fast_strtolower(&_40$$14, &_42$$14);
						ZEPHIR_INIT_NVAR(&name);
						ZEPHIR_CONCAT_SV(&name, "content-", &_40$$14);
						ZEPHIR_CALL_METHOD(NULL, &headers, "set", &_18, 42, &name, &value);
						zephir_check_call_status();
						continue;
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &serverArray, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&headers);
}

/**
 * Parse the $_SERVER array amd check the server protocol. Raise an
 *
 * @param CollectionInterface $server The server variables
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, parseProtocol)
{
	zval _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *server, server_sub, localProtocol, protocol, protocols, _0, _1, _2, _3, _5, _6, _9, _10, _7$$4, _8$$4, _11$$5, _12$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&server_sub);
	ZVAL_UNDEF(&localProtocol);
	ZVAL_UNDEF(&protocol);
	ZVAL_UNDEF(&protocols);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(server, phalcon_support_collection_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &server);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "SERVER_PROTOCOL");
	ZEPHIR_CALL_METHOD(&_0, server, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_STRING("1.1");
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "SERVER_PROTOCOL");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "HTTP/1.1");
	ZEPHIR_CALL_METHOD(&_2, server, "get", NULL, 0, &_1, &_3);
	zephir_check_call_status();
	zephir_cast_to_string(&_4, &_2);
	ZEPHIR_CPY_WRT(&protocol, &_4);
	ZEPHIR_INIT_VAR(&localProtocol);
	zephir_fast_strtolower(&localProtocol, &protocol);
	ZEPHIR_INIT_VAR(&protocols);
	zephir_create_array(&protocols, 4, 0);
	add_assoc_long_ex(&protocols, SL("1.0"), 1);
	add_assoc_long_ex(&protocols, SL("1.1"), 1);
	add_assoc_long_ex(&protocols, SL("2.0"), 1);
	add_assoc_long_ex(&protocols, SL("3.0"), 1);
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 5);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_substr(&_1, &localProtocol, 0 , 5 , 0);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_1, "http/")) {
		ZEPHIR_INIT_VAR(&_7$$4);
		object_init_ex(&_7$$4, phalcon_http_message_exception_invalidargumentexception_ce);
		ZEPHIR_INIT_VAR(&_8$$4);
		ZEPHIR_CONCAT_SV(&_8$$4, "Incorrect protocol value ", &protocol);
		ZEPHIR_CALL_METHOD(NULL, &_7$$4, "__construct", NULL, 40, &_8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$4, "phalcon/Http/Message/ServerRequestFactory.zep", 468);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "http/");
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "");
	zephir_fast_str_replace(&_3, &_9, &_10, &localProtocol);
	ZEPHIR_CPY_WRT(&localProtocol, &_3);
	if (UNEXPECTED(!(zephir_array_isset(&protocols, &localProtocol)))) {
		ZEPHIR_INIT_VAR(&_11$$5);
		object_init_ex(&_11$$5, phalcon_http_message_exception_invalidargumentexception_ce);
		ZEPHIR_INIT_VAR(&_12$$5);
		ZEPHIR_CONCAT_SV(&_12$$5, "Unsupported protocol ", &protocol);
		ZEPHIR_CALL_METHOD(NULL, &_11$$5, "__construct", NULL, 40, &_12$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$5, "phalcon/Http/Message/ServerRequestFactory.zep", 476);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&localProtocol);
}

/**
 * Parse the $_SERVER array amd return it back after looking for the
 * authorization header
 *
 * @param array $server Either verbatim, or with an added
 *                      HTTP_AUTHORIZATION header.
 *
 * @return CollectionInterface
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, parseServer)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *server_param = NULL, collection, headers, headersCollection, _0, _1, _3$$3, _4$$3, _5$$4, _6$$4;
	zval server;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&headersCollection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(server)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &server_param);
	zephir_get_arrval(&server, server_param);


	ZEPHIR_INIT_VAR(&collection);
	object_init_ex(&collection, phalcon_support_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 25, &server);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HTTP_AUTHORIZATION");
	ZEPHIR_CALL_METHOD(&_0, &collection, "has", NULL, 345, &_1);
	zephir_check_call_status();
	_2 = !zephir_is_true(&_0);
	if (_2) {
		_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&headers);
	}
	if (UNEXPECTED(_2)) {
		ZEPHIR_INIT_VAR(&headersCollection);
		object_init_ex(&headersCollection, phalcon_support_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, &headersCollection, "__construct", NULL, 25, &headers);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Authorization");
		ZEPHIR_CALL_METHOD(&_3$$3, &headersCollection, "has", NULL, 345, &_4$$3);
		zephir_check_call_status();
		if (UNEXPECTED(zephir_is_true(&_3$$3))) {
			ZEPHIR_INIT_VAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "Authorization");
			ZEPHIR_CALL_METHOD(&_5$$4, &headersCollection, "get", NULL, 346, &_6$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "HTTP_AUTHORIZATION");
			ZEPHIR_CALL_METHOD(NULL, &collection, "set", NULL, 42, &_6$$4, &_5$$4);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&collection);
}

/**
 * Traverses a $_FILES and creates UploadedFile objects from it. It is used
 * recursively
 *
 * @param array $files
 *
 * @return CollectionInterface
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, parseUploadedFiles)
{
	zend_bool _5$$3, _7$$3, _13$$7, _14$$7;
	zval _4$$3, _12$$7;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *files_param = NULL, collection, data, key, file, *_0, _1, _8$$5, _11$$6, _15$$9, _16$$10;
	zval files;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_12$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(files)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &files_param);
	zephir_get_arrval(&files, files_param);


	ZEPHIR_INIT_VAR(&collection);
	object_init_ex(&collection, phalcon_support_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 25);
	zephir_check_call_status();
	zephir_is_iterable(&files, 0, "phalcon/Http/Message/ServerRequestFactory.zep", 559);
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&files), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _0);
			zephir_cast_to_string(&_4$$3, &key);
			ZEPHIR_CPY_WRT(&key, &_4$$3);
			_5$$3 = Z_TYPE_P(&file) == IS_OBJECT;
			if (_5$$3) {
				_5$$3 = zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface"));
			}
			if (UNEXPECTED(_5$$3)) {
				ZEPHIR_CALL_METHOD(NULL, &collection, "set", &_6, 42, &key, &file);
				zephir_check_call_status();
				continue;
			}
			_7$$3 = Z_TYPE_P(&file) == IS_ARRAY;
			if (_7$$3) {
				_7$$3 = zephir_array_isset_string(&file, SL("tmp_name"));
			}
			if (EXPECTED(_7$$3)) {
				ZEPHIR_CALL_METHOD(&_8$$5, this_ptr, "createuploadedfile", &_9, 347, &file);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &collection, "set", &_6, 42, &key, &_8$$5);
				zephir_check_call_status();
				continue;
			}
			if (UNEXPECTED(Z_TYPE_P(&file) == IS_ARRAY)) {
				ZEPHIR_CALL_METHOD(&data, this_ptr, "parseuploadedfiles", &_10, 337, &file);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_11$$6, &data, "toarray", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &collection, "set", &_6, 42, &key, &_11$$6);
				zephir_check_call_status();
				continue;
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
			ZEPHIR_CALL_METHOD(&key, &files, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&file, &files, "current", NULL, 0);
			zephir_check_call_status();
				zephir_cast_to_string(&_12$$7, &key);
				ZEPHIR_CPY_WRT(&key, &_12$$7);
				_13$$7 = Z_TYPE_P(&file) == IS_OBJECT;
				if (_13$$7) {
					_13$$7 = zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface"));
				}
				if (UNEXPECTED(_13$$7)) {
					ZEPHIR_CALL_METHOD(NULL, &collection, "set", &_6, 42, &key, &file);
					zephir_check_call_status();
					continue;
				}
				_14$$7 = Z_TYPE_P(&file) == IS_ARRAY;
				if (_14$$7) {
					_14$$7 = zephir_array_isset_string(&file, SL("tmp_name"));
				}
				if (EXPECTED(_14$$7)) {
					ZEPHIR_CALL_METHOD(&_15$$9, this_ptr, "createuploadedfile", &_9, 347, &file);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &collection, "set", &_6, 42, &key, &_15$$9);
					zephir_check_call_status();
					continue;
				}
				if (UNEXPECTED(Z_TYPE_P(&file) == IS_ARRAY)) {
					ZEPHIR_CALL_METHOD(&data, this_ptr, "parseuploadedfiles", &_10, 337, &file);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_16$$10, &data, "toarray", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &collection, "set", &_6, 42, &key, &_16$$10);
					zephir_check_call_status();
					continue;
				}
			ZEPHIR_CALL_METHOD(NULL, &files, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&collection);
}

/**
 * Calculates the Uri from the server superglobal or the headers
 *
 * @param CollectionInterface $server
 * @param CollectionInterface $headers
 *
 * @return Uri
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, parseUri)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *server, server_sub, *headers, headers_sub, path, query, scheme, split, uri, _0, _1, _7, _8, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4, _9$$5, _10$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&server_sub);
	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&split);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(server, phalcon_support_collection_collectioninterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(headers, phalcon_support_collection_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &server, &headers);


	ZEPHIR_INIT_VAR(&uri);
	object_init_ex(&uri, phalcon_http_message_uri_ce);
	ZEPHIR_CALL_METHOD(NULL, &uri, "__construct", NULL, 111);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&scheme, this_ptr, "calculateurischeme", NULL, 348, server, headers);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &uri, "withscheme", NULL, 349, &scheme);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&uri, &_0);
	ZEPHIR_CALL_METHOD(&split, this_ptr, "calculateurihost", NULL, 350, server, headers);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_1);
	zephir_array_fetch_long(&_1, &split, 0, PH_NOISY, "phalcon/Http/Message/ServerRequestFactory.zep", 586);
	if (EXPECTED(!(ZEPHIR_IS_EMPTY(&_1)))) {
		zephir_array_fetch_long(&_3$$3, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Message/ServerRequestFactory.zep", 587);
		ZEPHIR_CALL_METHOD(&_2$$3, &uri, "withhost", NULL, 351, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&uri, &_2$$3);
		ZEPHIR_OBS_VAR(&_4$$3);
		zephir_array_fetch_long(&_4$$3, &split, 1, PH_NOISY, "phalcon/Http/Message/ServerRequestFactory.zep", 588);
		if (UNEXPECTED(!(ZEPHIR_IS_EMPTY(&_4$$3)))) {
			zephir_array_fetch_long(&_6$$4, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Message/ServerRequestFactory.zep", 589);
			ZEPHIR_CALL_METHOD(&_5$$4, &uri, "withport", NULL, 352, &_6$$4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&uri, &_5$$4);
		}
	}
	ZEPHIR_CALL_METHOD(&path, this_ptr, "calculateuripath", NULL, 353, server);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&split);
	zephir_fast_explode_str(&split, SL("#"), &path, LONG_MAX);
	zephir_array_fetch_long(&_7, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Message/ServerRequestFactory.zep", 598);
	ZEPHIR_INIT_NVAR(&path);
	zephir_fast_explode_str(&path, SL("?"), &_7, LONG_MAX);
	zephir_array_fetch_long(&_8, &path, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Message/ServerRequestFactory.zep", 599);
	ZEPHIR_CALL_METHOD(&_0, &uri, "withpath", NULL, 354, &_8);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&uri, &_0);
	if (UNEXPECTED(zephir_fast_count_int(&split) > 1)) {
		zephir_array_fetch_long(&_10$$5, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Message/ServerRequestFactory.zep", 602);
		ZEPHIR_CALL_METHOD(&_9$$5, &uri, "withfragment", NULL, 355, &_10$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&uri, &_9$$5);
	}
	ZEPHIR_CALL_METHOD(&query, this_ptr, "calculateuriquery", NULL, 356, server);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &uri, "withquery", NULL, 357, &query);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&uri, &_0);
	RETURN_CCTOR(&uri);
}

