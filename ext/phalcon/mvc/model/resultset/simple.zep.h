
extern zend_class_entry *phalcon_mvc_model_resultset_simple_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Simple);

PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, current);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, toArray);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, serialize);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_simple___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, result)
	ZEND_ARG_OBJ_INFO(0, cache, Phalcon\\Cache\\BackendInterface, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, keepSnapshots, _IS_BOOL, 1)
#else
	ZEND_ARG_INFO(0, keepSnapshots)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_simple_toarray, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_simple_toarray, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, renameColumns, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, renameColumns)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_simple_serialize, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_simple_serialize, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_simple_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_resultset_simple_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, __construct, arginfo_phalcon_mvc_model_resultset_simple___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, current, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, toArray, arginfo_phalcon_mvc_model_resultset_simple_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, serialize, arginfo_phalcon_mvc_model_resultset_simple_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, unserialize, arginfo_phalcon_mvc_model_resultset_simple_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
