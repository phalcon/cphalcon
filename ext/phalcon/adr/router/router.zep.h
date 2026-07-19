
extern zend_class_entry *phalcon_adr_router_router_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_Router);

PHP_METHOD(Phalcon_ADR_Router_Router, match);
PHP_METHOD(Phalcon_ADR_Router_Router, setBaseNamespace);
PHP_METHOD(Phalcon_ADR_Router_Router, setMiddlewareMap);
PHP_METHOD(Phalcon_ADR_Router_Router, camelize);
PHP_METHOD(Phalcon_ADR_Router_Router, locate);
PHP_METHOD(Phalcon_ADR_Router_Router, middlewareFor);
PHP_METHOD(Phalcon_ADR_Router_Router, toNamespace);
zend_object *zephir_init_properties_Phalcon_ADR_Router_Router(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_router_match, 0, 1, Phalcon\\Contracts\\ADR\\Router\\RouterMatch, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_router_setbasenamespace, 0, 1, Phalcon\\Contracts\\ADR\\Router\\Router, 0)
	ZEND_ARG_TYPE_INFO(0, baseNamespace, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_router_setmiddlewaremap, 0, 1, Phalcon\\Contracts\\ADR\\Router\\Router, 0)
	ZEND_ARG_ARRAY_INFO(0, middlewareMap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_camelize, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, segment, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_locate, 0, 2, IS_ARRAY, 1)
	ZEND_ARG_ARRAY_INFO(0, segments, 0)
	ZEND_ARG_TYPE_INFO(0, verb, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_middlewarefor, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_router_tonamespace, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, segments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_router_router_zephir_init_properties_phalcon_adr_router_router, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_router_router_method_entry) {
	PHP_ME(Phalcon_ADR_Router_Router, match, arginfo_phalcon_adr_router_router_match, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Router, setBaseNamespace, arginfo_phalcon_adr_router_router_setbasenamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Router, setMiddlewareMap, arginfo_phalcon_adr_router_router_setmiddlewaremap, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Router, camelize, arginfo_phalcon_adr_router_router_camelize, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Router_Router, locate, arginfo_phalcon_adr_router_router_locate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Router_Router, middlewareFor, arginfo_phalcon_adr_router_router_middlewarefor, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Router_Router, toNamespace, arginfo_phalcon_adr_router_router_tonamespace, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
