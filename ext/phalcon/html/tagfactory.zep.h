
extern zend_class_entry *phalcon_html_tagfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_TagFactory);

PHP_METHOD(Phalcon_Html_TagFactory, __construct);
PHP_METHOD(Phalcon_Html_TagFactory, __call);
PHP_METHOD(Phalcon_Html_TagFactory, has);
PHP_METHOD(Phalcon_Html_TagFactory, newInstance);
PHP_METHOD(Phalcon_Html_TagFactory, set);
PHP_METHOD(Phalcon_Html_TagFactory, getExceptionClass);
PHP_METHOD(Phalcon_Html_TagFactory, getServices);
zend_object *zephir_init_properties_Phalcon_Html_TagFactory(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_tagfactory___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, escaper, Phalcon\\Html\\Escaper\\EscaperInterface, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, services, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_tagfactory___call, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tagfactory_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_tagfactory_newinstance, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tagfactory_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tagfactory_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tagfactory_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_tagfactory_zephir_init_properties_phalcon_html_tagfactory, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_tagfactory_method_entry) {
	PHP_ME(Phalcon_Html_TagFactory, __construct, arginfo_phalcon_html_tagfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Html_TagFactory, __call, arginfo_phalcon_html_tagfactory___call, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_TagFactory, has, arginfo_phalcon_html_tagfactory_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_TagFactory, newInstance, arginfo_phalcon_html_tagfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_TagFactory, set, arginfo_phalcon_html_tagfactory_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_TagFactory, getExceptionClass, arginfo_phalcon_html_tagfactory_getexceptionclass, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_TagFactory, getServices, arginfo_phalcon_html_tagfactory_getservices, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
