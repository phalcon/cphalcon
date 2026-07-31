
extern zend_class_entry *phalcon_mvc_model_exceptions_eagerrowlimitexceeded_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Exceptions_EagerRowLimitExceeded);

PHP_METHOD(Phalcon_Mvc_Model_Exceptions_EagerRowLimitExceeded, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_exceptions_eagerrowlimitexceeded___construct, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, rowCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, limit, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_exceptions_eagerrowlimitexceeded_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Exceptions_EagerRowLimitExceeded, __construct, arginfo_phalcon_mvc_model_exceptions_eagerrowlimitexceeded___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
