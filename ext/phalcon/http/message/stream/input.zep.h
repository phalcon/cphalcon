
extern zend_class_entry *phalcon_http_message_stream_input_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Stream_Input);

PHP_METHOD(Phalcon_Http_Message_Stream_Input, __construct);
PHP_METHOD(Phalcon_Http_Message_Stream_Input, __toString);
PHP_METHOD(Phalcon_Http_Message_Stream_Input, getContents);
PHP_METHOD(Phalcon_Http_Message_Stream_Input, isWritable);
PHP_METHOD(Phalcon_Http_Message_Stream_Input, read);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_stream_input___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_input___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_input_getcontents, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_input_iswritable, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_input_read, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_stream_input_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Http_Message_Stream_Input, __construct, arginfo_phalcon_http_message_stream_input___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#else
	PHP_ME(Phalcon_Http_Message_Stream_Input, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#endif
	PHP_ME(Phalcon_Http_Message_Stream_Input, __toString, arginfo_phalcon_http_message_stream_input___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream_Input, getContents, arginfo_phalcon_http_message_stream_input_getcontents, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream_Input, isWritable, arginfo_phalcon_http_message_stream_input_iswritable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream_Input, read, arginfo_phalcon_http_message_stream_input_read, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
