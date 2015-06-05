
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
	ZEND_ARG_OBJ_INFO(0, cache, Phalcon\\Cache\\BackendInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_complex_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_resultset_complex_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, __construct, arginfo_phalcon_mvc_model_resultset_complex___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, current, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, unserialize, arginfo_phalcon_mvc_model_resultset_complex_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
