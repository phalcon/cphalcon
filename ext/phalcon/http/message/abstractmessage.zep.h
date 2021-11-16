
extern zend_class_entry *phalcon_http_message_abstractmessage_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_AbstractMessage);

PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getBody);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getProtocolVersion);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getUri);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getHeader);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getHeaderLine);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getHeaders);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, hasHeader);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, withAddedHeader);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, withBody);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, withHeader);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, withProtocolVersion);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, withoutHeader);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, checkHeaderHost);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, checkHeaderName);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, checkHeaderValue);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getHeaderValue);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getUriHost);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, populateHeaderCollection);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, processBody);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, processHeaders);
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, processProtocol);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_abstractmessage_getbody, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractmessage_getprotocolversion, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_abstractmessage_geturi, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractmessage_getheader, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractmessage_getheaderline, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractmessage_getheaders, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractmessage_hasheader, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_abstractmessage_withaddedheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_abstractmessage_withbody, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_abstractmessage_withheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_abstractmessage_withprotocolversion, 0, 0, 1)
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_abstractmessage_withoutheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_abstractmessage_checkheaderhost, 0, 1, Phalcon\\Support\\Collection\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Support\\Collection\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractmessage_checkheadername, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractmessage_checkheadervalue, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractmessage_getheadervalue, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractmessage_geturihost, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, uri, Psr\\Http\\Message\\UriInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_abstractmessage_populateheadercollection, 0, 1, Phalcon\\Support\\Collection\\CollectionInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_abstractmessage_processbody, 0, 0, Psr\\Http\\Message\\StreamInterface, 0)
	ZEND_ARG_INFO(0, body)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_abstractmessage_processheaders, 0, 1, Phalcon\\Support\\Collection\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractmessage_processprotocol, 0, 0, IS_STRING, 0)
	ZEND_ARG_INFO(0, protocol)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_abstractmessage_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Http_Message_AbstractMessage, getBody, arginfo_phalcon_http_message_abstractmessage_getbody, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Http_Message_AbstractMessage, getBody, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Http_Message_AbstractMessage, getProtocolVersion, arginfo_phalcon_http_message_abstractmessage_getprotocolversion, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Http_Message_AbstractMessage, getUri, arginfo_phalcon_http_message_abstractmessage_geturi, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Http_Message_AbstractMessage, getUri, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Http_Message_AbstractMessage, getHeader, arginfo_phalcon_http_message_abstractmessage_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, getHeaderLine, arginfo_phalcon_http_message_abstractmessage_getheaderline, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, getHeaders, arginfo_phalcon_http_message_abstractmessage_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, hasHeader, arginfo_phalcon_http_message_abstractmessage_hasheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, withAddedHeader, arginfo_phalcon_http_message_abstractmessage_withaddedheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, withBody, arginfo_phalcon_http_message_abstractmessage_withbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, withHeader, arginfo_phalcon_http_message_abstractmessage_withheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, withProtocolVersion, arginfo_phalcon_http_message_abstractmessage_withprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, withoutHeader, arginfo_phalcon_http_message_abstractmessage_withoutheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, checkHeaderHost, arginfo_phalcon_http_message_abstractmessage_checkheaderhost, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, checkHeaderName, arginfo_phalcon_http_message_abstractmessage_checkheadername, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, checkHeaderValue, arginfo_phalcon_http_message_abstractmessage_checkheadervalue, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, getHeaderValue, arginfo_phalcon_http_message_abstractmessage_getheadervalue, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, getUriHost, arginfo_phalcon_http_message_abstractmessage_geturihost, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, populateHeaderCollection, arginfo_phalcon_http_message_abstractmessage_populateheadercollection, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, processBody, arginfo_phalcon_http_message_abstractmessage_processbody, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, processHeaders, arginfo_phalcon_http_message_abstractmessage_processheaders, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Message_AbstractMessage, processProtocol, arginfo_phalcon_http_message_abstractmessage_processprotocol, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
