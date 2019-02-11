
extern zend_class_entry *phalcon_http_message_response_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Response);

PHP_METHOD(Phalcon_Http_Message_Response, __construct);
PHP_METHOD(Phalcon_Http_Message_Response, getBody);
PHP_METHOD(Phalcon_Http_Message_Response, getHeader);
PHP_METHOD(Phalcon_Http_Message_Response, getHeaderLine);
PHP_METHOD(Phalcon_Http_Message_Response, getHeaders);
PHP_METHOD(Phalcon_Http_Message_Response, getProtocolVersion);
PHP_METHOD(Phalcon_Http_Message_Response, getReasonPhrase);
PHP_METHOD(Phalcon_Http_Message_Response, getStatusCode);
PHP_METHOD(Phalcon_Http_Message_Response, hasHeader);
PHP_METHOD(Phalcon_Http_Message_Response, withAddedHeader);
PHP_METHOD(Phalcon_Http_Message_Response, withBody);
PHP_METHOD(Phalcon_Http_Message_Response, withHeader);
PHP_METHOD(Phalcon_Http_Message_Response, withProtocolVersion);
PHP_METHOD(Phalcon_Http_Message_Response, withStatus);
PHP_METHOD(Phalcon_Http_Message_Response, withoutHeader);
PHP_METHOD(Phalcon_Http_Message_Response, getPhrases);
PHP_METHOD(Phalcon_Http_Message_Response, processCode);
PHP_METHOD(Phalcon_Http_Message_Response, processHeaders);
PHP_METHOD(Phalcon_Http_Message_Response, processProtocol);
PHP_METHOD(Phalcon_Http_Message_Response, processStream);
zend_object *zephir_init_properties_Phalcon_Http_Message_Response(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_response___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, body)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, code)
#endif
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_response_getbody, 0, 0, Psr\\Http\\Message\\StreamInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getbody, 0, 0, IS_OBJECT, "Psr\\Http\\Message\\StreamInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getheader, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getheader, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getheaderline, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getheaderline, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getheaders, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getheaders, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getprotocolversion, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getprotocolversion, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getreasonphrase, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getreasonphrase, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getstatuscode, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getstatuscode, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_hasheader, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_hasheader, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_response_withaddedheader, 0, 2, Psr\\Http\\Message\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_withaddedheader, 0, 2, IS_OBJECT, "Psr\\Http\\Message\\ResponseInterface", 0)
#endif
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_response_withbody, 0, 1, Psr\\Http\\Message\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_withbody, 0, 1, IS_OBJECT, "Psr\\Http\\Message\\ResponseInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_response_withheader, 0, 2, Psr\\Http\\Message\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_withheader, 0, 2, IS_OBJECT, "Psr\\Http\\Message\\ResponseInterface", 0)
#endif
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_response_withprotocolversion, 0, 1, Psr\\Http\\Message\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_withprotocolversion, 0, 1, IS_OBJECT, "Psr\\Http\\Message\\ResponseInterface", 0)
#endif
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_response_withstatus, 0, 1, Psr\\Http\\Message\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_withstatus, 0, 1, IS_OBJECT, "Psr\\Http\\Message\\ResponseInterface", 0)
#endif
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, reasonPhrase)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_response_withoutheader, 0, 1, Psr\\Http\\Message\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_withoutheader, 0, 1, IS_OBJECT, "Psr\\Http\\Message\\ResponseInterface", 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getphrases, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getphrases, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_response_processcode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, phrase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_response_processheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_response_processprotocol, 0, 0, 0)
	ZEND_ARG_INFO(0, protocol)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_response_processstream, 0, 1, Psr\\Http\\Message\\StreamInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_processstream, 0, 1, IS_OBJECT, "Psr\\Http\\Message\\StreamInterface", 0)
#endif
	ZEND_ARG_INFO(0, body)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, mode)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_response_method_entry) {
	PHP_ME(Phalcon_Http_Message_Response, __construct, arginfo_phalcon_http_message_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Message_Response, getBody, arginfo_phalcon_http_message_response_getbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, getHeader, arginfo_phalcon_http_message_response_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, getHeaderLine, arginfo_phalcon_http_message_response_getheaderline, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, getHeaders, arginfo_phalcon_http_message_response_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, getProtocolVersion, arginfo_phalcon_http_message_response_getprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, getReasonPhrase, arginfo_phalcon_http_message_response_getreasonphrase, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, getStatusCode, arginfo_phalcon_http_message_response_getstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, hasHeader, arginfo_phalcon_http_message_response_hasheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, withAddedHeader, arginfo_phalcon_http_message_response_withaddedheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, withBody, arginfo_phalcon_http_message_response_withbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, withHeader, arginfo_phalcon_http_message_response_withheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, withProtocolVersion, arginfo_phalcon_http_message_response_withprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, withStatus, arginfo_phalcon_http_message_response_withstatus, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, withoutHeader, arginfo_phalcon_http_message_response_withoutheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, getPhrases, arginfo_phalcon_http_message_response_getphrases, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Response, processCode, arginfo_phalcon_http_message_response_processcode, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Response, processHeaders, arginfo_phalcon_http_message_response_processheaders, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Response, processProtocol, arginfo_phalcon_http_message_response_processprotocol, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Response, processStream, arginfo_phalcon_http_message_response_processstream, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
