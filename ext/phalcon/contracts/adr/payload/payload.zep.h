
extern zend_class_entry *phalcon_contracts_adr_payload_payload_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Payload_Payload);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_payload_payload_getexception, 0, 0, Throwable, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_adr_payload_payload_getextras, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_adr_payload_payload_getinput, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_adr_payload_payload_getmessages, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_adr_payload_payload_getresult, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_adr_payload_payload_getstatus, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_payload_payload_withexception, 0, 1, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_payload_payload_withextras, 0, 1, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, extras)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_payload_payload_withinput, 0, 1, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_payload_payload_withmessages, 0, 1, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_payload_payload_withresult, 0, 1, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_payload_payload_withstatus, 0, 1, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_adr_payload_payload_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Payload_Payload, getException, arginfo_phalcon_contracts_adr_payload_payload_getexception)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Payload_Payload, getExtras, arginfo_phalcon_contracts_adr_payload_payload_getextras)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Payload_Payload, getInput, arginfo_phalcon_contracts_adr_payload_payload_getinput)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Payload_Payload, getMessages, arginfo_phalcon_contracts_adr_payload_payload_getmessages)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Payload_Payload, getResult, arginfo_phalcon_contracts_adr_payload_payload_getresult)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Payload_Payload, getStatus, arginfo_phalcon_contracts_adr_payload_payload_getstatus)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Payload_Payload, withException, arginfo_phalcon_contracts_adr_payload_payload_withexception)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Payload_Payload, withExtras, arginfo_phalcon_contracts_adr_payload_payload_withextras)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Payload_Payload, withInput, arginfo_phalcon_contracts_adr_payload_payload_withinput)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Payload_Payload, withMessages, arginfo_phalcon_contracts_adr_payload_payload_withmessages)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Payload_Payload, withResult, arginfo_phalcon_contracts_adr_payload_payload_withresult)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Payload_Payload, withStatus, arginfo_phalcon_contracts_adr_payload_payload_withstatus)
	PHP_FE_END
};
