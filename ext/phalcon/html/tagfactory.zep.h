
extern zend_class_entry *phalcon_html_tagfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_TagFactory);

PHP_METHOD(Phalcon_Html_TagFactory, __construct);
PHP_METHOD(Phalcon_Html_TagFactory, newInstance);
PHP_METHOD(Phalcon_Html_TagFactory, getAdapters);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_tagfactory___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, escaper, Phalcon\\Escaper\\EscaperInterface, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, services, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_tagfactory_newinstance, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tagfactory_getadapters, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_tagfactory_method_entry) {
	PHP_ME(Phalcon_Html_TagFactory, __construct, arginfo_phalcon_html_tagfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Html_TagFactory, newInstance, arginfo_phalcon_html_tagfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_TagFactory, getAdapters, arginfo_phalcon_html_tagfactory_getadapters, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
