
extern zend_class_entry *phalcon_contracts_domain_payload_writeable_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Domain_Payload_Writeable);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_domain_payload_writeable_setexception, 0, 1, Phalcon\\Contracts\\Domain\\Payload\\Payload, 0)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_domain_payload_writeable_setextras, 0, 1, Phalcon\\Contracts\\Domain\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, extras)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_domain_payload_writeable_setinput, 0, 1, Phalcon\\Contracts\\Domain\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_domain_payload_writeable_setmessages, 0, 1, Phalcon\\Contracts\\Domain\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_domain_payload_writeable_setoutput, 0, 1, Phalcon\\Contracts\\Domain\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_domain_payload_writeable_setstatus, 0, 1, Phalcon\\Contracts\\Domain\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_domain_payload_writeable_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Domain_Payload_Writeable, setException, arginfo_phalcon_contracts_domain_payload_writeable_setexception)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Domain_Payload_Writeable, setExtras, arginfo_phalcon_contracts_domain_payload_writeable_setextras)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Domain_Payload_Writeable, setInput, arginfo_phalcon_contracts_domain_payload_writeable_setinput)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Domain_Payload_Writeable, setMessages, arginfo_phalcon_contracts_domain_payload_writeable_setmessages)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Domain_Payload_Writeable, setOutput, arginfo_phalcon_contracts_domain_payload_writeable_setoutput)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Domain_Payload_Writeable, setStatus, arginfo_phalcon_contracts_domain_payload_writeable_setstatus)
	PHP_FE_END
};
