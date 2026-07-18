
extern zend_class_entry *phalcon_contracts_adr_router_route_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Router_Route);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_route_withmiddleware, 0, 0, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_VARIADIC_TYPE_INFO(0, classes, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_route_withname, 0, 1, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_adr_router_route_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Route, withMiddleware, arginfo_phalcon_contracts_adr_router_route_withmiddleware)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Route, withName, arginfo_phalcon_contracts_adr_router_route_withname)
	PHP_FE_END
};
