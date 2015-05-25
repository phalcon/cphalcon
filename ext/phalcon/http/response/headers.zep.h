
extern zend_class_entry *phalcon_http_response_headers_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Response_Headers);

PHP_METHOD(Phalcon_Http_Response_Headers, set);
PHP_METHOD(Phalcon_Http_Response_Headers, get);
PHP_METHOD(Phalcon_Http_Response_Headers, setRaw);
PHP_METHOD(Phalcon_Http_Response_Headers, remove);
PHP_METHOD(Phalcon_Http_Response_Headers, send);
PHP_METHOD(Phalcon_Http_Response_Headers, reset);
PHP_METHOD(Phalcon_Http_Response_Headers, toArray);
PHP_METHOD(Phalcon_Http_Response_Headers, __set_state);
PHP_METHOD(Phalcon_Http_Response_Headers, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers_setraw, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_response_headers_method_entry) {
	PHP_ME(Phalcon_Http_Response_Headers, set, arginfo_phalcon_http_response_headers_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, get, arginfo_phalcon_http_response_headers_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, setRaw, arginfo_phalcon_http_response_headers_setraw, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, remove, arginfo_phalcon_http_response_headers_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, __set_state, arginfo_phalcon_http_response_headers___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Http_Response_Headers, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
