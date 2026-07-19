
extern zend_class_entry *phalcon_adr_middleware_timingmiddleware_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Middleware_TimingMiddleware);

PHP_METHOD(Phalcon_ADR_Middleware_TimingMiddleware, __invoke);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_middleware_timingmiddleware___invoke, 0, 2, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Contracts\\Http\\AttributeRequest, 0)
	ZEND_ARG_OBJ_INFO(0, next, Phalcon\\Contracts\\ADR\\Handler, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_middleware_timingmiddleware_method_entry) {
	PHP_ME(Phalcon_ADR_Middleware_TimingMiddleware, __invoke, arginfo_phalcon_adr_middleware_timingmiddleware___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
