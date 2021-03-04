
extern zend_class_entry *phalcon_http_response_headers_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Response_Headers);

PHP_METHOD(Phalcon_Http_Response_Headers, get);
PHP_METHOD(Phalcon_Http_Response_Headers, has);
PHP_METHOD(Phalcon_Http_Response_Headers, remove);
PHP_METHOD(Phalcon_Http_Response_Headers, reset);
PHP_METHOD(Phalcon_Http_Response_Headers, send);
PHP_METHOD(Phalcon_Http_Response_Headers, set);
PHP_METHOD(Phalcon_Http_Response_Headers, setRaw);
PHP_METHOD(Phalcon_Http_Response_Headers, toArray);
zend_object *zephir_init_properties_Phalcon_Http_Response_Headers(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_headers_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_headers_remove, 0, 1, Phalcon\\Http\\Response\\HeadersInterface, 0)
	ZEND_ARG_TYPE_INFO(0, header, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers_reset, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_headers_send, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_headers_set, 0, 2, Phalcon\\Http\\Response\\HeadersInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_headers_setraw, 0, 1, Phalcon\\Http\\Response\\HeadersInterface, 0)
	ZEND_ARG_TYPE_INFO(0, header, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_headers_toarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers_zephir_init_properties_phalcon_http_response_headers, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_response_headers_method_entry) {
	PHP_ME(Phalcon_Http_Response_Headers, get, arginfo_phalcon_http_response_headers_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, has, arginfo_phalcon_http_response_headers_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, remove, arginfo_phalcon_http_response_headers_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, reset, arginfo_phalcon_http_response_headers_reset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, send, arginfo_phalcon_http_response_headers_send, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, set, arginfo_phalcon_http_response_headers_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, setRaw, arginfo_phalcon_http_response_headers_setraw, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, toArray, arginfo_phalcon_http_response_headers_toarray, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
