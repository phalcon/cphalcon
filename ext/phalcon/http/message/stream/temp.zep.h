
extern zend_class_entry *phalcon_http_message_stream_temp_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Stream_Temp);

PHP_METHOD(Phalcon_Http_Message_Stream_Temp, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_stream_temp___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_stream_temp_method_entry) {
	PHP_ME(Phalcon_Http_Message_Stream_Temp, __construct, arginfo_phalcon_http_message_stream_temp___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
