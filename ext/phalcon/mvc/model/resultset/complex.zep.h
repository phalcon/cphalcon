
extern zend_class_entry *phalcon_mvc_model_resultset_complex_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Complex);

PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, current);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, toArray);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, serialize);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_complex___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, columnTypes)
	ZEND_ARG_OBJ_INFO(0, result, Phalcon\\Db\\ResultInterface, 1)
	ZEND_ARG_OBJ_INFO(0, cache, Phalcon\\Cache\\Adapter\\AdapterInterface, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_complex_toarray, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_complex_toarray, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_complex_serialize, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_complex_serialize, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_complex_unserialize, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_complex_unserialize, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_complex_unserialize, 0, 0, 1)
#define arginfo_phalcon_mvc_model_resultset_complex_unserialize NULL
#endif

	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_resultset_complex_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, __construct, arginfo_phalcon_mvc_model_resultset_complex___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, current, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, toArray, arginfo_phalcon_mvc_model_resultset_complex_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, serialize, arginfo_phalcon_mvc_model_resultset_complex_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, unserialize, arginfo_phalcon_mvc_model_resultset_complex_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
