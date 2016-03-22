
extern zend_class_entry *phalcon_mvc_model_query_statusinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_StatusInterface);

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_statusinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, getModel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, success, NULL)
	PHP_FE_END
};
