
extern zend_class_entry *phalcon_mvc_model_hydration_cloneresultmap_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Hydration_CloneResultMap);

PHP_METHOD(Phalcon_Mvc_Model_Hydration_CloneResultMap, cloneResultMap);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_hydration_cloneresultmap_cloneresultmap, 0, 3, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, dirtyState, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, keepSnapshots, _IS_BOOL, 1, "null")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_hydration_cloneresultmap_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Hydration_CloneResultMap, cloneResultMap, arginfo_phalcon_mvc_model_hydration_cloneresultmap_cloneresultmap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
