
extern zend_class_entry *phalcon_contracts_adr_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Dispatcher);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_dispatcher_dispatch, 0, 2, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Contracts\\Http\\AttributeRequestInterface, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, routeMiddleware, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_adr_dispatcher_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Dispatcher, dispatch, arginfo_phalcon_contracts_adr_dispatcher_dispatch)
	PHP_FE_END
};
