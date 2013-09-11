
extern zend_class_entry *phalcon_mvc_model_queryinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_QueryInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_queryinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, phql)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_execute, 0, 0, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_queryinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, __construct, arginfo_phalcon_mvc_model_queryinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, parse, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, execute, arginfo_phalcon_mvc_model_queryinterface_execute)
	PHP_FE_END
};
