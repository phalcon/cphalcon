
extern zend_class_entry *phalcon_domain_payload_writeableinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Domain_Payload_WriteableInterface);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_writeableinterface_setexception, 0, 1, Phalcon\\Domain\\Payload\\PayloadInterface, 0)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_writeableinterface_setextras, 0, 1, Phalcon\\Domain\\Payload\\PayloadInterface, 0)
	ZEND_ARG_INFO(0, extras)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_writeableinterface_setinput, 0, 1, Phalcon\\Domain\\Payload\\PayloadInterface, 0)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_writeableinterface_setmessages, 0, 1, Phalcon\\Domain\\Payload\\PayloadInterface, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_writeableinterface_setoutput, 0, 1, Phalcon\\Domain\\Payload\\PayloadInterface, 0)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_writeableinterface_setstatus, 0, 1, Phalcon\\Domain\\Payload\\PayloadInterface, 0)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_domain_payload_writeableinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_WriteableInterface, setException, arginfo_phalcon_domain_payload_writeableinterface_setexception)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_WriteableInterface, setExtras, arginfo_phalcon_domain_payload_writeableinterface_setextras)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_WriteableInterface, setInput, arginfo_phalcon_domain_payload_writeableinterface_setinput)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_WriteableInterface, setMessages, arginfo_phalcon_domain_payload_writeableinterface_setmessages)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_WriteableInterface, setOutput, arginfo_phalcon_domain_payload_writeableinterface_setoutput)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_WriteableInterface, setStatus, arginfo_phalcon_domain_payload_writeableinterface_setstatus)
	PHP_FE_END
};
