
extern zend_class_entry *phalcon_contracts_adr_responder_responder_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Responder_Responder);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_responder_responder___invoke, 0, 3, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, payload, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_adr_responder_responder_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Responder_Responder, __invoke, arginfo_phalcon_contracts_adr_responder_responder___invoke)
	PHP_FE_END
};
