
extern zend_class_entry *phalcon_mvc_model_metadata_strategy_introspection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Introspection);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getColumnMaps);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getMetaData);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategy_introspection_getcolumnmaps, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategy_introspection_getmetadata, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_strategy_introspection_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getColumnMaps, arginfo_phalcon_mvc_model_metadata_strategy_introspection_getcolumnmaps, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getMetaData, arginfo_phalcon_mvc_model_metadata_strategy_introspection_getmetadata, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
