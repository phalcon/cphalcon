
extern zend_class_entry *phalcon_mvc_model_transaction_failed_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Failed);

PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecord);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecordMessages);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_failed___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_transaction_failed_getrecord, 0, 0, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_failed_getrecordmessages, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_transaction_failed_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Transaction_Failed, __construct, arginfo_phalcon_mvc_model_transaction_failed___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Failed, getRecord, arginfo_phalcon_mvc_model_transaction_failed_getrecord, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Failed, getRecordMessages, arginfo_phalcon_mvc_model_transaction_failed_getrecordmessages, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
