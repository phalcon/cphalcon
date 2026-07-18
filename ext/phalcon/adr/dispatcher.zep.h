
extern zend_class_entry *phalcon_adr_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Dispatcher);

PHP_METHOD(Phalcon_ADR_Dispatcher, __construct);
PHP_METHOD(Phalcon_ADR_Dispatcher, dispatch);
PHP_METHOD(Phalcon_ADR_Dispatcher, resolveAll);
PHP_METHOD(Phalcon_ADR_Dispatcher, resolveGlobal);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_dispatcher___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Contracts\\Container\\Ioc\\IocContainer, 0)
	ZEND_ARG_OBJ_INFO(0, events, Phalcon\\Contracts\\Events\\Manager, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, globalMiddleware, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_dispatcher_dispatch, 0, 2, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Contracts\\Http\\AttributeRequestInterface, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, routeMiddleware, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_dispatcher_resolveall, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, classes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_dispatcher_resolveglobal, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_dispatcher_method_entry) {
	PHP_ME(Phalcon_ADR_Dispatcher, __construct, arginfo_phalcon_adr_dispatcher___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Dispatcher, dispatch, arginfo_phalcon_adr_dispatcher_dispatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Dispatcher, resolveAll, arginfo_phalcon_adr_dispatcher_resolveall, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Dispatcher, resolveGlobal, arginfo_phalcon_adr_dispatcher_resolveglobal, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
