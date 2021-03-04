
extern zend_class_entry *phalcon_mvc_model_query_status_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Status);

PHP_METHOD(Phalcon_Mvc_Model_Query_Status, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getMessages);
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getModel);
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, success);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_status___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, success, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_status_getmessages, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_status_getmodel, 0, 0, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_status_success, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_status_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Query_Status, __construct, arginfo_phalcon_mvc_model_query_status___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Query_Status, getMessages, arginfo_phalcon_mvc_model_query_status_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Status, getModel, arginfo_phalcon_mvc_model_query_status_getmodel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Status, success, arginfo_phalcon_mvc_model_query_status_success, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
