
extern zend_class_entry *phalcon_contracts_adr_application_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Application);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_application_handle, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Contracts\\Http\\AttributeRequestInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_adr_application_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Application, handle, arginfo_phalcon_contracts_adr_application_handle)
	PHP_FE_END
};
