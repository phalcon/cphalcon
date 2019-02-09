
extern zend_class_entry *phalcon_http_message_inputstream_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_InputStream);

PHP_METHOD(Phalcon_Http_Message_InputStream, __toString);
PHP_METHOD(Phalcon_Http_Message_InputStream, getContents);
PHP_METHOD(Phalcon_Http_Message_InputStream, isWritable);
PHP_METHOD(Phalcon_Http_Message_InputStream, read);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_inputstream___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_inputstream___tostring, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_inputstream_getcontents, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_inputstream_getcontents, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, length)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_inputstream_iswritable, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_inputstream_iswritable, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_inputstream_read, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_inputstream_read, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_inputstream_method_entry) {
	PHP_ME(Phalcon_Http_Message_InputStream, __toString, arginfo_phalcon_http_message_inputstream___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_InputStream, getContents, arginfo_phalcon_http_message_inputstream_getcontents, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_InputStream, isWritable, arginfo_phalcon_http_message_inputstream_iswritable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_InputStream, read, arginfo_phalcon_http_message_inputstream_read, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
