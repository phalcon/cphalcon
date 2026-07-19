
extern zend_class_entry *phalcon_adr_middleware_methodoverridemiddleware_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Middleware_MethodOverrideMiddleware);

PHP_METHOD(Phalcon_ADR_Middleware_MethodOverrideMiddleware, __invoke);
zend_object *zephir_init_properties_Phalcon_ADR_Middleware_MethodOverrideMiddleware(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_middleware_methodoverridemiddleware___invoke, 0, 2, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Contracts\\Http\\AttributeRequest, 0)
	ZEND_ARG_OBJ_INFO(0, next, Phalcon\\Contracts\\ADR\\Handler, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_middleware_methodoverridemiddleware_zephir_init_properties_phalcon_adr_middleware_methodoverridemiddleware, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_middleware_methodoverridemiddleware_method_entry) {
	PHP_ME(Phalcon_ADR_Middleware_MethodOverrideMiddleware, __invoke, arginfo_phalcon_adr_middleware_methodoverridemiddleware___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
