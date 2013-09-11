
extern zend_class_entry *phalcon_mvc_model_messageinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MessageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_settype, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_setmessage, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_setfield, 0, 0, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface___set_state, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_messageinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, __construct, arginfo_phalcon_mvc_model_messageinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setType, arginfo_phalcon_mvc_model_messageinterface_settype)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setMessage, arginfo_phalcon_mvc_model_messageinterface_setmessage)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getMessage, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setField, arginfo_phalcon_mvc_model_messageinterface_setfield)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getField, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, __toString, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, __set_state, arginfo_phalcon_mvc_model_messageinterface___set_state)
	PHP_FE_END
};
