
extern zend_class_entry *phalcon_filter_filterfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_FilterFactory);

PHP_METHOD(Phalcon_Filter_FilterFactory, newInstance);
PHP_METHOD(Phalcon_Filter_FilterFactory, getAdapters);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filter_filterfactory_newinstance, 0, 0, Phalcon\\Filter\\FilterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filterfactory_newinstance, 0, 0, IS_OBJECT, "Phalcon\\Filter\\FilterInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filterfactory_getadapters, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filterfactory_getadapters, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_filterfactory_method_entry) {
	PHP_ME(Phalcon_Filter_FilterFactory, newInstance, arginfo_phalcon_filter_filterfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_FilterFactory, getAdapters, arginfo_phalcon_filter_filterfactory_getadapters, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
