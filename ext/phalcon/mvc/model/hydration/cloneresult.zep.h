
extern zend_class_entry *phalcon_mvc_model_hydration_cloneresult_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Hydration_CloneResult);

PHP_METHOD(Phalcon_Mvc_Model_Hydration_CloneResult, cloneResult);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_hydration_cloneresult_cloneresult, 0, 2, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, base, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, dirtyState, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_hydration_cloneresult_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Hydration_CloneResult, cloneResult, arginfo_phalcon_mvc_model_hydration_cloneresult_cloneresult, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
