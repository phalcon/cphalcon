
extern zend_class_entry *phalcon_adr_router_group_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_Group);

PHP_METHOD(Phalcon_ADR_Router_Group, __construct);
PHP_METHOD(Phalcon_ADR_Router_Group, add);
PHP_METHOD(Phalcon_ADR_Router_Group, delete);
PHP_METHOD(Phalcon_ADR_Router_Group, get);
PHP_METHOD(Phalcon_ADR_Router_Group, patch);
PHP_METHOD(Phalcon_ADR_Router_Group, post);
PHP_METHOD(Phalcon_ADR_Router_Group, put);
PHP_METHOD(Phalcon_ADR_Router_Group, withMiddleware);
PHP_METHOD(Phalcon_ADR_Router_Group, getMiddleware);
PHP_METHOD(Phalcon_ADR_Router_Group, pushMiddleware);
zend_object *zephir_init_properties_Phalcon_ADR_Router_Group(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_router_group___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, router, Phalcon\\ADR\\Router\\Router, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_group_add, 0, 2, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, methods, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_group_delete, 0, 2, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_group_get, 0, 2, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_group_patch, 0, 2, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_group_post, 0, 2, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_group_put, 0, 2, Phalcon\\Contracts\\ADR\\Router\\Route, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_router_group_withmiddleware, 0, 0, Phalcon\\Contracts\\ADR\\Router\\Group, 0)
	ZEND_ARG_VARIADIC_TYPE_INFO(0, classes, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_group_getmiddleware, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_group_pushmiddleware, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, classes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_router_group_zephir_init_properties_phalcon_adr_router_group, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_router_group_method_entry) {
	PHP_ME(Phalcon_ADR_Router_Group, __construct, arginfo_phalcon_adr_router_group___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Router_Group, add, arginfo_phalcon_adr_router_group_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Group, delete, arginfo_phalcon_adr_router_group_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Group, get, arginfo_phalcon_adr_router_group_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Group, patch, arginfo_phalcon_adr_router_group_patch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Group, post, arginfo_phalcon_adr_router_group_post, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Group, put, arginfo_phalcon_adr_router_group_put, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Group, withMiddleware, arginfo_phalcon_adr_router_group_withmiddleware, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Group, getMiddleware, arginfo_phalcon_adr_router_group_getmiddleware, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_Group, pushMiddleware, arginfo_phalcon_adr_router_group_pushmiddleware, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
