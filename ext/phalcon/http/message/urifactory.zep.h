
extern zend_class_entry *phalcon_http_message_urifactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_UriFactory);

PHP_METHOD(Phalcon_Http_Message_UriFactory, createUri);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_urifactory_createuri, 0, 0, Psr\\Http\\Message\\UriInterface, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_urifactory_method_entry) {
	PHP_ME(Phalcon_Http_Message_UriFactory, createUri, arginfo_phalcon_http_message_urifactory_createuri, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
