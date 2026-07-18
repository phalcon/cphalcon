
extern zend_class_entry *phalcon_adr_emitter_sapiemitter_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Emitter_SapiEmitter);

PHP_METHOD(Phalcon_ADR_Emitter_SapiEmitter, emit);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_emitter_sapiemitter_emit, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_emitter_sapiemitter_method_entry) {
	PHP_ME(Phalcon_ADR_Emitter_SapiEmitter, emit, arginfo_phalcon_adr_emitter_sapiemitter_emit, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
