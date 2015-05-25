
extern zend_class_entry *phalcon_validation_messageinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_MessageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, message, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_messageinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, __construct, arginfo_phalcon_validation_messageinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, setType, arginfo_phalcon_validation_messageinterface_settype)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, setMessage, arginfo_phalcon_validation_messageinterface_setmessage)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, getMessage, NULL)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, setField, arginfo_phalcon_validation_messageinterface_setfield)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, getField, NULL)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, __toString, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_validation_messageinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
