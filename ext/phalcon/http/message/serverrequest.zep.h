
extern zend_class_entry *phalcon_http_message_serverrequest_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_ServerRequest);

PHP_METHOD(Phalcon_Http_Message_ServerRequest, getAttributes);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getBody);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getCookieParams);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getQueryParams);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getMethod);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getParsedBody);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getProtocolVersion);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getServerParams);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getUploadedFiles);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getUri);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, __construct);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getAttribute);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getHeader);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getHeaderLine);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getHeaders);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getRequestTarget);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, hasHeader);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withAddedHeader);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withAttribute);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withBody);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withCookieParams);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withHeader);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withoutHeader);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withMethod);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withParsedBody);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withProtocolVersion);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withQueryParams);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withRequestTarget);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withUploadedFiles);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withUri);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withoutAttribute);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, cloneInstance);
zend_object *zephir_init_properties_Phalcon_Http_Message_ServerRequest(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getattributes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getattributes, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getcookieparams, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getcookieparams, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getqueryparams, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getqueryparams, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getmethod, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getmethod, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getprotocolversion, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getprotocolversion, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getserverparams, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getserverparams, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getuploadedfiles, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getuploadedfiles, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_serverrequest___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_ARRAY_INFO(0, serverParams, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_serverrequest_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getheader, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getheader, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getheaderline, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getheaderline, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getheaders, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getheaders, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getrequesttarget, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getrequesttarget, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_hasheader, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_hasheader, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withaddedheader, 0, 2, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_withaddedheader, 0, 2, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withattribute, 0, 2, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_withattribute, 0, 2, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withbody, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_withbody, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withcookieparams, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_withcookieparams, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, cookies, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withheader, 0, 2, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_withheader, 0, 2, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withoutheader, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_withoutheader, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withmethod, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_withmethod, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withparsedbody, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_withparsedbody, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withprotocolversion, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_withprotocolversion, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withqueryparams, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_withqueryparams, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, query, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withrequesttarget, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_withrequesttarget, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_INFO(0, requestTarget)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withuploadedfiles, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_withuploadedfiles, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, uploadedFiles, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withuri, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_withuri, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, preserveHost)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withoutattribute, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_withoutattribute, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_cloneinstance, 0, 2, Phalcon\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_cloneinstance, 0, 2, IS_OBJECT, "Phalcon\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_INFO(0, element)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, property)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_serverrequest_method_entry) {
	PHP_ME(Phalcon_Http_Message_ServerRequest, getAttributes, arginfo_phalcon_http_message_serverrequest_getattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getCookieParams, arginfo_phalcon_http_message_serverrequest_getcookieparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getQueryParams, arginfo_phalcon_http_message_serverrequest_getqueryparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getMethod, arginfo_phalcon_http_message_serverrequest_getmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getParsedBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getProtocolVersion, arginfo_phalcon_http_message_serverrequest_getprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getServerParams, arginfo_phalcon_http_message_serverrequest_getserverparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getUploadedFiles, arginfo_phalcon_http_message_serverrequest_getuploadedfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, __construct, arginfo_phalcon_http_message_serverrequest___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getAttribute, arginfo_phalcon_http_message_serverrequest_getattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getHeader, arginfo_phalcon_http_message_serverrequest_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getHeaderLine, arginfo_phalcon_http_message_serverrequest_getheaderline, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getHeaders, arginfo_phalcon_http_message_serverrequest_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getRequestTarget, arginfo_phalcon_http_message_serverrequest_getrequesttarget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, hasHeader, arginfo_phalcon_http_message_serverrequest_hasheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withAddedHeader, arginfo_phalcon_http_message_serverrequest_withaddedheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withAttribute, arginfo_phalcon_http_message_serverrequest_withattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withBody, arginfo_phalcon_http_message_serverrequest_withbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withCookieParams, arginfo_phalcon_http_message_serverrequest_withcookieparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withHeader, arginfo_phalcon_http_message_serverrequest_withheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withoutHeader, arginfo_phalcon_http_message_serverrequest_withoutheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withMethod, arginfo_phalcon_http_message_serverrequest_withmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withParsedBody, arginfo_phalcon_http_message_serverrequest_withparsedbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withProtocolVersion, arginfo_phalcon_http_message_serverrequest_withprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withQueryParams, arginfo_phalcon_http_message_serverrequest_withqueryparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withRequestTarget, arginfo_phalcon_http_message_serverrequest_withrequesttarget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withUploadedFiles, arginfo_phalcon_http_message_serverrequest_withuploadedfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withUri, arginfo_phalcon_http_message_serverrequest_withuri, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withoutAttribute, arginfo_phalcon_http_message_serverrequest_withoutattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, cloneInstance, arginfo_phalcon_http_message_serverrequest_cloneinstance, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
