
extern zend_class_entry *phalcon_adr_router_router_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_Router);

PHP_METHOD(Phalcon_ADR_Router_Router, candidatesFor);
PHP_METHOD(Phalcon_ADR_Router_Router, classFor);
PHP_METHOD(Phalcon_ADR_Router_Router, match);
PHP_METHOD(Phalcon_ADR_Router_Router, methodFor);
PHP_METHOD(Phalcon_ADR_Router_Router, pathFor);
PHP_METHOD(Phalcon_ADR_Router_Router, setActionDirectory);
PHP_METHOD(Phalcon_ADR_Router_Router, setBaseNamespace);
PHP_METHOD(Phalcon_ADR_Router_Router, setMiddlewareMap);
PHP_METHOD(Phalcon_ADR_Router_Router, setWordSeparator);
PHP_METHOD(Phalcon_ADR_Router_Router, actionParams);
PHP_METHOD(Phalcon_ADR_Router_Router, camelize);
PHP_METHOD(Phalcon_ADR_Router_Router, decamelize);
PHP_METHOD(Phalcon_ADR_Router_Router, deriveCandidates);
PHP_METHOD(Phalcon_ADR_Router_Router, hasSubNamespace);
PHP_METHOD(Phalcon_ADR_Router_Router, locate);
PHP_METHOD(Phalcon_ADR_Router_Router, middlewareFor);
PHP_METHOD(Phalcon_ADR_Router_Router, verbOf);
PHP_METHOD(Phalcon_ADR_Router_Router, verbs);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_candidatesfor, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_classfor, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_router_match, 0, 1, Phalcon\\Contracts\\ADR\\Router\\RouterMatch, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_methodfor, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_pathfor, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_router_setactiondirectory, 0, 1, Phalcon\\Contracts\\ADR\\Router\\Router, 0)
	ZEND_ARG_TYPE_INFO(0, actionDirectory, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_router_setbasenamespace, 0, 1, Phalcon\\Contracts\\ADR\\Router\\Router, 0)
	ZEND_ARG_TYPE_INFO(0, baseNamespace, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_router_setmiddlewaremap, 0, 1, Phalcon\\Contracts\\ADR\\Router\\Router, 0)
	ZEND_ARG_ARRAY_INFO(0, middlewareMap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_router_setwordseparator, 0, 1, Phalcon\\Contracts\\ADR\\Router\\Router, 0)
	ZEND_ARG_TYPE_INFO(0, wordSeparator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_actionparams, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_camelize, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, segment, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_decamelize, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, part, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_derivecandidates, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_hassubnamespace, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, subNamespace, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_locate, 0, 2, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_middlewarefor, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_verbof, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_verbs, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_router_router_method_entry) {
	PHP_ME(Phalcon_ADR_Router_Router, candidatesFor, arginfo_phalcon_adr_router_router_candidatesfor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Router, classFor, arginfo_phalcon_adr_router_router_classfor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Router, match, arginfo_phalcon_adr_router_router_match, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Router, methodFor, arginfo_phalcon_adr_router_router_methodfor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Router, pathFor, arginfo_phalcon_adr_router_router_pathfor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Router, setActionDirectory, arginfo_phalcon_adr_router_router_setactiondirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Router, setBaseNamespace, arginfo_phalcon_adr_router_router_setbasenamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Router, setMiddlewareMap, arginfo_phalcon_adr_router_router_setmiddlewaremap, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Router, setWordSeparator, arginfo_phalcon_adr_router_router_setwordseparator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Router, actionParams, arginfo_phalcon_adr_router_router_actionparams, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Router_Router, camelize, arginfo_phalcon_adr_router_router_camelize, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Router_Router, decamelize, arginfo_phalcon_adr_router_router_decamelize, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Router_Router, deriveCandidates, arginfo_phalcon_adr_router_router_derivecandidates, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Router_Router, hasSubNamespace, arginfo_phalcon_adr_router_router_hassubnamespace, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Router_Router, locate, arginfo_phalcon_adr_router_router_locate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Router_Router, middlewareFor, arginfo_phalcon_adr_router_router_middlewarefor, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Router_Router, verbOf, arginfo_phalcon_adr_router_router_verbof, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Router_Router, verbs, arginfo_phalcon_adr_router_router_verbs, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
