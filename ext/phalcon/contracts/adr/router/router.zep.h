
extern zend_class_entry *phalcon_contracts_adr_router_router_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Router_Router);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_router_add, 0, 2, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, methods, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_router_delete, 0, 2, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_router_get, 0, 2, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_router_group, 0, 2, Phalcon\\Contracts\\ADR\\Router\\Group, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, configure, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_router_match, 0, 1, Phalcon\\Contracts\\ADR\\Router\\RouterMatch, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_router_patch, 0, 2, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_router_post, 0, 2, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_router_put, 0, 2, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_adr_router_router_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, add, arginfo_phalcon_contracts_adr_router_router_add)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, delete, arginfo_phalcon_contracts_adr_router_router_delete)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, get, arginfo_phalcon_contracts_adr_router_router_get)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, group, arginfo_phalcon_contracts_adr_router_router_group)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, match, arginfo_phalcon_contracts_adr_router_router_match)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, patch, arginfo_phalcon_contracts_adr_router_router_patch)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, post, arginfo_phalcon_contracts_adr_router_router_post)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, put, arginfo_phalcon_contracts_adr_router_router_put)
	PHP_FE_END
};
