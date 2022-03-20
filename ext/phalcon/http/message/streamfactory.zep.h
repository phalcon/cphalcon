
extern zend_class_entry *phalcon_http_message_streamfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_StreamFactory);

PHP_METHOD(Phalcon_Http_Message_StreamFactory, createStream);
PHP_METHOD(Phalcon_Http_Message_StreamFactory, createStreamFromFile);
PHP_METHOD(Phalcon_Http_Message_StreamFactory, createStreamFromResource);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_streamfactory_createstream, 0, 0, PsrExt\\Http\\Message\\StreamInterface, 0)
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_streamfactory_createstreamfromfile, 0, 1, PsrExt\\Http\\Message\\StreamInterface, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_streamfactory_createstreamfromresource, 0, 1, PsrExt\\Http\\Message\\StreamInterface, 0)
	ZEND_ARG_INFO(0, phpResource)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_streamfactory_method_entry) {
	PHP_ME(Phalcon_Http_Message_StreamFactory, createStream, arginfo_phalcon_http_message_streamfactory_createstream, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_StreamFactory, createStreamFromFile, arginfo_phalcon_http_message_streamfactory_createstreamfromfile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_StreamFactory, createStreamFromResource, arginfo_phalcon_http_message_streamfactory_createstreamfromresource, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
