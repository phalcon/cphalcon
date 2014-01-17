
extern zend_class_entry *phalcon_mvc_model_criteria_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Criteria);

PHP_METHOD(Phalcon_Mvc_Model_Criteria, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setModelName);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getModelName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_setmodelname, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_criteria_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Criteria, setDI, arginfo_phalcon_mvc_model_criteria_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, setModelName, arginfo_phalcon_mvc_model_criteria_setmodelname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getModelName, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
