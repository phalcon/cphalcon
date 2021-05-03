
extern zend_class_entry *phalcon_mvc_model_metadata_apcu_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Apcu);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apcu, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_apcu___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Cache\\AdapterFactory, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 1)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_apcu_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Apcu, __construct, arginfo_phalcon_mvc_model_metadata_apcu___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
