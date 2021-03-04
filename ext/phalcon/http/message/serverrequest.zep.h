
extern zend_class_entry *phalcon_http_message_serverrequest_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_ServerRequest);

PHP_METHOD(Phalcon_Http_Message_ServerRequest, getCookieParams);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getParsedBody);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getQueryParams);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getServerParams);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getUploadedFiles);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, __construct);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getAttribute);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, getAttributes);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withAttribute);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withCookieParams);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withParsedBody);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withQueryParams);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withUploadedFiles);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, withoutAttribute);
PHP_METHOD(Phalcon_Http_Message_ServerRequest, checkUploadedFiles);
zend_object *zephir_init_properties_Phalcon_Http_Message_ServerRequest(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getcookieparams, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_serverrequest_getparsedbody, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getqueryparams, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getserverparams, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getuploadedfiles, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_serverrequest___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_ARRAY_INFO(0, serverParams, 0)
	ZEND_ARG_INFO(0, body)
	ZEND_ARG_INFO(0, headers)
	ZEND_ARG_ARRAY_INFO(0, cookies, 0)
	ZEND_ARG_ARRAY_INFO(0, queryParams, 0)
	ZEND_ARG_ARRAY_INFO(0, uploadFiles, 0)
	ZEND_ARG_INFO(0, parsedBody)
	ZEND_ARG_TYPE_INFO(0, protocol, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_serverrequest_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_getattributes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withattribute, 0, 2, Phalcon\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withcookieparams, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_ARRAY_INFO(0, cookies, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withparsedbody, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withqueryparams, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_ARRAY_INFO(0, query, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withuploadedfiles, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_ARRAY_INFO(0, uploadedFiles, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_serverrequest_withoutattribute, 0, 1, Phalcon\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_serverrequest_checkuploadedfiles, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, files, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_serverrequest_zephir_init_properties_phalcon_http_message_serverrequest, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_serverrequest_method_entry) {
	PHP_ME(Phalcon_Http_Message_ServerRequest, getCookieParams, arginfo_phalcon_http_message_serverrequest_getcookieparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getParsedBody, arginfo_phalcon_http_message_serverrequest_getparsedbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getQueryParams, arginfo_phalcon_http_message_serverrequest_getqueryparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getServerParams, arginfo_phalcon_http_message_serverrequest_getserverparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getUploadedFiles, arginfo_phalcon_http_message_serverrequest_getuploadedfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, __construct, arginfo_phalcon_http_message_serverrequest___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getAttribute, arginfo_phalcon_http_message_serverrequest_getattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, getAttributes, arginfo_phalcon_http_message_serverrequest_getattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withAttribute, arginfo_phalcon_http_message_serverrequest_withattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withCookieParams, arginfo_phalcon_http_message_serverrequest_withcookieparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withParsedBody, arginfo_phalcon_http_message_serverrequest_withparsedbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withQueryParams, arginfo_phalcon_http_message_serverrequest_withqueryparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withUploadedFiles, arginfo_phalcon_http_message_serverrequest_withuploadedfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, withoutAttribute, arginfo_phalcon_http_message_serverrequest_withoutattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_ServerRequest, checkUploadedFiles, arginfo_phalcon_http_message_serverrequest_checkuploadedfiles, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
