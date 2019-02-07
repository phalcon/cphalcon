
extern zend_class_entry *phalcon_filter_filterlocatorfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_FilterLocatorFactory);

PHP_METHOD(Phalcon_Filter_FilterLocatorFactory, newInstance);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filter_filterlocatorfactory_newinstance, 0, 0, Phalcon\\Service\\LocatorInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filterlocatorfactory_newinstance, 0, 0, IS_OBJECT, "Phalcon\\Service\\LocatorInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_filterlocatorfactory_method_entry) {
	PHP_ME(Phalcon_Filter_FilterLocatorFactory, newInstance, arginfo_phalcon_filter_filterlocatorfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
