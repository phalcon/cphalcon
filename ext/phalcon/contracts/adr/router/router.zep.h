
extern zend_class_entry *phalcon_contracts_adr_router_router_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Router_Router);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_adr_router_router_candidatesfor, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_router_match, 0, 1, Phalcon\\Contracts\\ADR\\Router\\RouterMatch, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_adr_router_router_pathfor, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_router_setactiondirectory, 0, 1, Phalcon\\Contracts\\ADR\\Router\\Router, 0)
	ZEND_ARG_TYPE_INFO(0, actionDirectory, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_router_setbasenamespace, 0, 1, Phalcon\\Contracts\\ADR\\Router\\Router, 0)
	ZEND_ARG_TYPE_INFO(0, baseNamespace, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_router_setmiddlewaremap, 0, 1, Phalcon\\Contracts\\ADR\\Router\\Router, 0)
	ZEND_ARG_ARRAY_INFO(0, middlewareMap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_router_router_setwordseparator, 0, 1, Phalcon\\Contracts\\ADR\\Router\\Router, 0)
	ZEND_ARG_TYPE_INFO(0, wordSeparator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_adr_router_router_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, candidatesFor, arginfo_phalcon_contracts_adr_router_router_candidatesfor)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, match, arginfo_phalcon_contracts_adr_router_router_match)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, pathFor, arginfo_phalcon_contracts_adr_router_router_pathfor)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, setActionDirectory, arginfo_phalcon_contracts_adr_router_router_setactiondirectory)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, setBaseNamespace, arginfo_phalcon_contracts_adr_router_router_setbasenamespace)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, setMiddlewareMap, arginfo_phalcon_contracts_adr_router_router_setmiddlewaremap)
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_Router, setWordSeparator, arginfo_phalcon_contracts_adr_router_router_setwordseparator)
	PHP_FE_END
};
