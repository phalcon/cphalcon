
extern zend_class_entry *phalcon_contracts_adr_emitter_emitter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Emitter_Emitter);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_adr_emitter_emitter_emit, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_adr_emitter_emitter_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Emitter_Emitter, emit, arginfo_phalcon_contracts_adr_emitter_emitter_emit)
	PHP_FE_END
};
