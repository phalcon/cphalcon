
extern zend_class_entry *phalcon_http_message_request_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Request);

PHP_METHOD(Phalcon_Http_Message_Request, getBody);
PHP_METHOD(Phalcon_Http_Message_Request, getMethod);
PHP_METHOD(Phalcon_Http_Message_Request, getProtocolVersion);
PHP_METHOD(Phalcon_Http_Message_Request, getUri);
PHP_METHOD(Phalcon_Http_Message_Request, __construct);
PHP_METHOD(Phalcon_Http_Message_Request, getHeader);
PHP_METHOD(Phalcon_Http_Message_Request, getHeaderLine);
PHP_METHOD(Phalcon_Http_Message_Request, getHeaders);
PHP_METHOD(Phalcon_Http_Message_Request, getRequestTarget);
PHP_METHOD(Phalcon_Http_Message_Request, hasHeader);
PHP_METHOD(Phalcon_Http_Message_Request, withAddedHeader);
PHP_METHOD(Phalcon_Http_Message_Request, withBody);
PHP_METHOD(Phalcon_Http_Message_Request, withHeader);
PHP_METHOD(Phalcon_Http_Message_Request, withMethod);
PHP_METHOD(Phalcon_Http_Message_Request, withProtocolVersion);
PHP_METHOD(Phalcon_Http_Message_Request, withRequestTarget);
PHP_METHOD(Phalcon_Http_Message_Request, withUri);
PHP_METHOD(Phalcon_Http_Message_Request, withoutHeader);
PHP_METHOD(Phalcon_Http_Message_Request, checkHeaderName);
PHP_METHOD(Phalcon_Http_Message_Request, checkHeaderValue);
PHP_METHOD(Phalcon_Http_Message_Request, cloneInstance);
PHP_METHOD(Phalcon_Http_Message_Request, getHeaderValue);
PHP_METHOD(Phalcon_Http_Message_Request, getUriHost);
PHP_METHOD(Phalcon_Http_Message_Request, processBody);
PHP_METHOD(Phalcon_Http_Message_Request, processHeaders);
PHP_METHOD(Phalcon_Http_Message_Request, processMethod);
PHP_METHOD(Phalcon_Http_Message_Request, processProtocol);
PHP_METHOD(Phalcon_Http_Message_Request, processUri);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_getmethod, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_getmethod, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_getprotocolversion, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_getprotocolversion, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_request___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, body)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_getheader, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_getheader, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_getheaderline, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_getheaderline, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_getheaders, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_getheaders, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_getrequesttarget, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_getrequesttarget, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_hasheader, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_hasheader, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_request_withaddedheader, 0, 2, Phalcon\\Http\\Message\\Request, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_withaddedheader, 0, 2, IS_OBJECT, "Phalcon\\Http\\Message\\Request", 0)
#endif
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_request_withbody, 0, 1, Phalcon\\Http\\Message\\Request, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_withbody, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\Request", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_request_withheader, 0, 2, Phalcon\\Http\\Message\\Request, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_withheader, 0, 2, IS_OBJECT, "Phalcon\\Http\\Message\\Request", 0)
#endif
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_request_withmethod, 0, 1, Phalcon\\Http\\Message\\Request, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_withmethod, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\Request", 0)
#endif
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_request_withprotocolversion, 0, 1, Phalcon\\Http\\Message\\Request, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_withprotocolversion, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\Request", 0)
#endif
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_request_withrequesttarget, 0, 1, Phalcon\\Http\\Message\\Request, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_withrequesttarget, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\Request", 0)
#endif
	ZEND_ARG_INFO(0, requestTarget)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_request_withuri, 0, 1, Phalcon\\Http\\Message\\Request, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_withuri, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\Request", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, uri, Psr\\Http\\Message\\UriInterface, 0)
	ZEND_ARG_INFO(0, preserveHost)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_request_withoutheader, 0, 1, Phalcon\\Http\\Message\\Request, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_withoutheader, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\Request", 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_request_checkheadername, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_request_checkheadervalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_request_cloneinstance, 0, 2, Phalcon\\Http\\Message\\Request, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_cloneinstance, 0, 2, IS_OBJECT, "Phalcon\\Http\\Message\\Request", 0)
#endif
	ZEND_ARG_INFO(0, element)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, property)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_getheadervalue, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_getheadervalue, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_geturihost, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_geturihost, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, uri, Psr\\Http\\Message\\UriInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_request_processbody, 0, 0, Psr\\Http\\Message\\StreamInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_processbody, 0, 0, IS_OBJECT, "Psr\\Http\\Message\\StreamInterface", 0)
#endif
	ZEND_ARG_INFO(0, body)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, mode)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_request_processheaders, 0, 1, Phalcon\\Collection, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_processheaders, 0, 1, IS_OBJECT, "Phalcon\\Collection", 0)
#endif
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_processmethod, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_processmethod, 0, 0, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_processprotocol, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_processprotocol, 0, 0, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, protocol)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_request_processuri, 0, 1, Psr\\Http\\Message\\UriInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_request_processuri, 0, 1, IS_OBJECT, "Psr\\Http\\Message\\UriInterface", 0)
#endif
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_request_method_entry) {
	PHP_ME(Phalcon_Http_Message_Request, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, getMethod, arginfo_phalcon_http_message_request_getmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, getProtocolVersion, arginfo_phalcon_http_message_request_getprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, getUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, __construct, arginfo_phalcon_http_message_request___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Message_Request, getHeader, arginfo_phalcon_http_message_request_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, getHeaderLine, arginfo_phalcon_http_message_request_getheaderline, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, getHeaders, arginfo_phalcon_http_message_request_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, getRequestTarget, arginfo_phalcon_http_message_request_getrequesttarget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, hasHeader, arginfo_phalcon_http_message_request_hasheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, withAddedHeader, arginfo_phalcon_http_message_request_withaddedheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, withBody, arginfo_phalcon_http_message_request_withbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, withHeader, arginfo_phalcon_http_message_request_withheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, withMethod, arginfo_phalcon_http_message_request_withmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, withProtocolVersion, arginfo_phalcon_http_message_request_withprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, withRequestTarget, arginfo_phalcon_http_message_request_withrequesttarget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, withUri, arginfo_phalcon_http_message_request_withuri, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, withoutHeader, arginfo_phalcon_http_message_request_withoutheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Request, checkHeaderName, arginfo_phalcon_http_message_request_checkheadername, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Request, checkHeaderValue, arginfo_phalcon_http_message_request_checkheadervalue, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Request, cloneInstance, arginfo_phalcon_http_message_request_cloneinstance, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Request, getHeaderValue, arginfo_phalcon_http_message_request_getheadervalue, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Request, getUriHost, arginfo_phalcon_http_message_request_geturihost, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Request, processBody, arginfo_phalcon_http_message_request_processbody, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Request, processHeaders, arginfo_phalcon_http_message_request_processheaders, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Request, processMethod, arginfo_phalcon_http_message_request_processmethod, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Request, processProtocol, arginfo_phalcon_http_message_request_processprotocol, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Request, processUri, arginfo_phalcon_http_message_request_processuri, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
