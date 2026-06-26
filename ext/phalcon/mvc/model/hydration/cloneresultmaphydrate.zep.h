
extern zend_class_entry *phalcon_mvc_model_hydration_cloneresultmaphydrate_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Hydration_CloneResultMapHydrate);

PHP_METHOD(Phalcon_Mvc_Model_Hydration_CloneResultMapHydrate, cloneResultMapHydrate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_hydration_cloneresultmaphydrate_cloneresultmaphydrate, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_TYPE_INFO(0, hydrationMode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, calledClass, IS_STRING, 0, "'Phalcon\\\\Mvc\\\\Model'")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_hydration_cloneresultmaphydrate_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Hydration_CloneResultMapHydrate, cloneResultMapHydrate, arginfo_phalcon_mvc_model_hydration_cloneresultmaphydrate_cloneresultmaphydrate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
