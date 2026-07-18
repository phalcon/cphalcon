
extern zend_class_entry *phalcon_adr_router_route_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_Route);

PHP_METHOD(Phalcon_ADR_Router_Route, __construct);
PHP_METHOD(Phalcon_ADR_Router_Route, allowsMethod);
PHP_METHOD(Phalcon_ADR_Router_Route, getAction);
PHP_METHOD(Phalcon_ADR_Router_Route, getName);
PHP_METHOD(Phalcon_ADR_Router_Route, matches);
PHP_METHOD(Phalcon_ADR_Router_Route, withMiddleware);
PHP_METHOD(Phalcon_ADR_Router_Route, withName);
PHP_METHOD(Phalcon_ADR_Router_Route, compile);
PHP_METHOD(Phalcon_ADR_Router_Route, getMiddleware);
PHP_METHOD(Phalcon_ADR_Router_Route, pushMiddleware);
zend_object *zephir_init_properties_Phalcon_ADR_Router_Route(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_router_route___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, action, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, methods, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_route_allowsmethod, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_route_getaction, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_route_getname, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_adr_router_route_matches, 0, 1, MAY_BE_ARRAY|MAY_BE_BOOL)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_route_withmiddleware, 0, 0, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_VARIADIC_TYPE_INFO(0, classes, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_route_withname, 0, 1, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_route_compile, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_route_getmiddleware, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_route_pushmiddleware, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, classes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_router_route_zephir_init_properties_phalcon_adr_router_route, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_router_route_method_entry) {
	PHP_ME(Phalcon_ADR_Router_Route, __construct, arginfo_phalcon_adr_router_route___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Router_Route, allowsMethod, arginfo_phalcon_adr_router_route_allowsmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Route, getAction, arginfo_phalcon_adr_router_route_getaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Route, getName, arginfo_phalcon_adr_router_route_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Route, matches, arginfo_phalcon_adr_router_route_matches, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Route, withMiddleware, arginfo_phalcon_adr_router_route_withmiddleware, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Route, withName, arginfo_phalcon_adr_router_route_withname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Route, compile, arginfo_phalcon_adr_router_route_compile, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Router_Route, getMiddleware, arginfo_phalcon_adr_router_route_getmiddleware, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Route, pushMiddleware, arginfo_phalcon_adr_router_route_pushmiddleware, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
