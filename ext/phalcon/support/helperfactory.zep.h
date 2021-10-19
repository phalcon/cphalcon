
extern zend_class_entry *phalcon_support_helperfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_HelperFactory);

PHP_METHOD(Phalcon_Support_HelperFactory, __construct);
PHP_METHOD(Phalcon_Support_HelperFactory, __call);
PHP_METHOD(Phalcon_Support_HelperFactory, newInstance);
PHP_METHOD(Phalcon_Support_HelperFactory, getServices);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_helperfactory___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, services, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_helperfactory___call, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_helperfactory_newinstance, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helperfactory_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helperfactory_method_entry) {
	PHP_ME(Phalcon_Support_HelperFactory, __construct, arginfo_phalcon_support_helperfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Support_HelperFactory, __call, arginfo_phalcon_support_helperfactory___call, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_HelperFactory, newInstance, arginfo_phalcon_support_helperfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_HelperFactory, getServices, arginfo_phalcon_support_helperfactory_getservices, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
