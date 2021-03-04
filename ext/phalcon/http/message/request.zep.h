
extern zend_class_entry *phalcon_http_message_request_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Request);

PHP_METHOD(Phalcon_Http_Message_Request, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_request___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, body)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_request_method_entry) {
	PHP_ME(Phalcon_Http_Message_Request, __construct, arginfo_phalcon_http_message_request___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
