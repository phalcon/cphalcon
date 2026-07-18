
extern zend_class_entry *phalcon_contracts_adr_router_group_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Router_Group);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_group_withmiddleware, 0, 0, Phalcon\\Contracts\\ADR\\Router\\Group, 0)
	ZEND_ARG_VARIADIC_TYPE_INFO(0, classes, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_adr_router_group_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Group, withMiddleware, arginfo_phalcon_contracts_adr_router_group_withmiddleware)
	PHP_FE_END
};
