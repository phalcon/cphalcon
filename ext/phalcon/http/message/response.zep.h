
extern zend_class_entry *phalcon_http_message_response_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Response);

PHP_METHOD(Phalcon_Http_Message_Response, getReasonPhrase);
PHP_METHOD(Phalcon_Http_Message_Response, getStatusCode);
PHP_METHOD(Phalcon_Http_Message_Response, __construct);
PHP_METHOD(Phalcon_Http_Message_Response, withStatus);
PHP_METHOD(Phalcon_Http_Message_Response, getPhrases);
PHP_METHOD(Phalcon_Http_Message_Response, processCode);
PHP_METHOD(Phalcon_Http_Message_Response, checkCodeType);
PHP_METHOD(Phalcon_Http_Message_Response, checkCodeValue);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getreasonphrase, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getstatuscode, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_response___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, body)
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, headers, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_response_withstatus, 0, 1, Phalcon\\Http\\Message\\Response, 0)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, reasonPhrase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_getphrases, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_processcode, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, phrase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_checkcodetype, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_response_checkcodevalue, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_response_method_entry) {
	PHP_ME(Phalcon_Http_Message_Response, getReasonPhrase, arginfo_phalcon_http_message_response_getreasonphrase, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, getStatusCode, arginfo_phalcon_http_message_response_getstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, __construct, arginfo_phalcon_http_message_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Message_Response, withStatus, arginfo_phalcon_http_message_response_withstatus, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Response, getPhrases, arginfo_phalcon_http_message_response_getphrases, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Message_Response, processCode, arginfo_phalcon_http_message_response_processcode, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Message_Response, checkCodeType, arginfo_phalcon_http_message_response_checkcodetype, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Response, checkCodeValue, arginfo_phalcon_http_message_response_checkcodevalue, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
