
extern zend_class_entry *phalcon_mvc_model_query_statusinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_StatusInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_statusinterface_getmodel, 0, 0, Phalcon\\Mvc\\ModelInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_statusinterface_getmodel, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\ModelInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_statusinterface_getmessages, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_statusinterface_getmessages, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_statusinterface_success, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_statusinterface_success, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_statusinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, getModel, arginfo_phalcon_mvc_model_query_statusinterface_getmodel)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, getMessages, arginfo_phalcon_mvc_model_query_statusinterface_getmessages)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, success, arginfo_phalcon_mvc_model_query_statusinterface_success)
	PHP_FE_END
};
