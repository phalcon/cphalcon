
extern zend_class_entry *phalcon_html_taglocatorfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_TagLocatorFactory);

PHP_METHOD(Phalcon_Html_TagLocatorFactory, newInstance);
PHP_METHOD(Phalcon_Html_TagLocatorFactory, getEscaper);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_taglocatorfactory_newinstance, 0, 0, Phalcon\\Service\\LocatorInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_taglocatorfactory_newinstance, 0, 0, IS_OBJECT, "Phalcon\\Service\\LocatorInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_taglocatorfactory_getescaper, 0, 0, Phalcon\\EscaperInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_taglocatorfactory_getescaper, 0, 0, IS_OBJECT, "Phalcon\\EscaperInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_taglocatorfactory_method_entry) {
	PHP_ME(Phalcon_Html_TagLocatorFactory, newInstance, arginfo_phalcon_html_taglocatorfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_TagLocatorFactory, getEscaper, arginfo_phalcon_html_taglocatorfactory_getescaper, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
