
extern zend_class_entry *phalcon_http_request_exceptions_invalidhost_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Request_Exceptions_InvalidHost);

PHP_METHOD(Phalcon_Http_Request_Exceptions_InvalidHost, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_exceptions_invalidhost___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, host, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_request_exceptions_invalidhost_method_entry) {
	PHP_ME(Phalcon_Http_Request_Exceptions_InvalidHost, __construct, arginfo_phalcon_http_request_exceptions_invalidhost___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
