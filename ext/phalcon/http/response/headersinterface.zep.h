
extern zend_class_entry *phalcon_http_response_headersinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Response_HeadersInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_headersinterface_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_reset, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_headersinterface_send, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_set, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_setraw, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, header, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_response_headersinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, get, arginfo_phalcon_http_response_headersinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, has, arginfo_phalcon_http_response_headersinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, reset, arginfo_phalcon_http_response_headersinterface_reset)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, send, arginfo_phalcon_http_response_headersinterface_send)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, set, arginfo_phalcon_http_response_headersinterface_set)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, setRaw, arginfo_phalcon_http_response_headersinterface_setraw)
	PHP_FE_END
};
