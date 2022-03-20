
extern zend_class_entry *phalcon_http_message_responsefactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_ResponseFactory);

PHP_METHOD(Phalcon_Http_Message_ResponseFactory, createResponse);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_responsefactory_createresponse, 0, 0, PsrExt\\Http\\Message\\ResponseInterface, 0)
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, reasonPhrase, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_responsefactory_method_entry) {
	PHP_ME(Phalcon_Http_Message_ResponseFactory, createResponse, arginfo_phalcon_http_message_responsefactory_createresponse, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
