
extern zend_class_entry *phalcon_mvc_model_query_statusinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_StatusInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_statusinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, success)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_statusinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, __construct, arginfo_phalcon_mvc_model_query_statusinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, getModel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, success, NULL)
	PHP_FE_END
};
