
extern zend_class_entry *phalcon_contracts_adr_middleware_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Middleware);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_middleware___invoke, 0, 2, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Contracts\\Http\\AttributeRequest, 0)
	ZEND_ARG_OBJ_INFO(0, next, Phalcon\\Contracts\\ADR\\Handler, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_adr_middleware_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Middleware, __invoke, arginfo_phalcon_contracts_adr_middleware___invoke)
	PHP_FE_END
};
