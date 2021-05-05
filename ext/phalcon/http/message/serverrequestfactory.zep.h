
extern zend_class_entry *phalcon_http_message_serverrequestfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_ServerRequestFactory);

PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, createServerRequest);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, load);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, getHeaders);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, calculateUriHost);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, calculateUriHostFromHeader);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, calculateUriPath);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, calculateUriQuery);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, calculateUriScheme);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, checkNullArray);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, createUploadedFile);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, getHeader);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, parseCookieHeader);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, parseHeaders);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, parseProtocol);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, parseServer);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, parseUploadedFiles);
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, parseUri);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_createserverrequest, 0, 2, Psr\\Http\\Message\\ServerRequestInterface, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_INFO(0, uri)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, serverParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, serverParams, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_load, 0, 0, Phalcon\\Http\\Message\\ServerRequest, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, server, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, server, 1)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, get, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, get, 1)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, post, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, post, 1)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cookies, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, cookies, 1)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, files, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, files, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_getheaders, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_calculateurihost, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, server, Phalcon\\Collection\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, headers, Phalcon\\Collection\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_calculateurihostfromheader, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, host, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_calculateuripath, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, server, Phalcon\\Collection\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_calculateuriquery, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, server, Phalcon\\Collection\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_calculateurischeme, 0, 2, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, server, Phalcon\\Collection\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, headers, Phalcon\\Collection\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_checknullarray, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_ARRAY_INFO(0, super, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_createuploadedfile, 0, 1, Phalcon\\Http\\Message\\UploadedFile, 0)
	ZEND_ARG_ARRAY_INFO(0, file, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_getheader, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, headers, Phalcon\\Collection\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_parsecookieheader, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, cookieHeader, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_parseheaders, 0, 1, Phalcon\\Collection\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, server, Phalcon\\Collection\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_parseprotocol, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, server, Phalcon\\Collection\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_parseserver, 0, 1, Phalcon\\Collection\\CollectionInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, server, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_parseuploadedfiles, 0, 1, Phalcon\\Collection\\CollectionInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, files, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequestfactory_parseuri, 0, 2, Phalcon\\Http\\Message\\Uri, 0)
	ZEND_ARG_OBJ_INFO(0, server, Phalcon\\Collection\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, headers, Phalcon\\Collection\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_serverrequestfactory_method_entry) {
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, createServerRequest, arginfo_phalcon_http_message_serverrequestfactory_createserverrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, load, arginfo_phalcon_http_message_serverrequestfactory_load, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, getHeaders, arginfo_phalcon_http_message_serverrequestfactory_getheaders, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, getHeaders, NULL, ZEND_ACC_PROTECTED)
#endif
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, calculateUriHost, arginfo_phalcon_http_message_serverrequestfactory_calculateurihost, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, calculateUriHostFromHeader, arginfo_phalcon_http_message_serverrequestfactory_calculateurihostfromheader, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, calculateUriPath, arginfo_phalcon_http_message_serverrequestfactory_calculateuripath, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, calculateUriQuery, arginfo_phalcon_http_message_serverrequestfactory_calculateuriquery, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, calculateUriScheme, arginfo_phalcon_http_message_serverrequestfactory_calculateurischeme, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, checkNullArray, arginfo_phalcon_http_message_serverrequestfactory_checknullarray, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, createUploadedFile, arginfo_phalcon_http_message_serverrequestfactory_createuploadedfile, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, getHeader, arginfo_phalcon_http_message_serverrequestfactory_getheader, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, parseCookieHeader, arginfo_phalcon_http_message_serverrequestfactory_parsecookieheader, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, parseHeaders, arginfo_phalcon_http_message_serverrequestfactory_parseheaders, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, parseProtocol, arginfo_phalcon_http_message_serverrequestfactory_parseprotocol, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, parseServer, arginfo_phalcon_http_message_serverrequestfactory_parseserver, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, parseUploadedFiles, arginfo_phalcon_http_message_serverrequestfactory_parseuploadedfiles, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_ServerRequestFactory, parseUri, arginfo_phalcon_http_message_serverrequestfactory_parseuri, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
