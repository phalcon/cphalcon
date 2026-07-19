
extern zend_class_entry *phalcon_adr_middleware_corsmiddleware_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Middleware_CorsMiddleware);

PHP_METHOD(Phalcon_ADR_Middleware_CorsMiddleware, __construct);
PHP_METHOD(Phalcon_ADR_Middleware_CorsMiddleware, __invoke);
PHP_METHOD(Phalcon_ADR_Middleware_CorsMiddleware, applyHeaders);
PHP_METHOD(Phalcon_ADR_Middleware_CorsMiddleware, isAllowed);
PHP_METHOD(Phalcon_ADR_Middleware_CorsMiddleware, getArrVal);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_middleware_corsmiddleware___construct, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, config, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_middleware_corsmiddleware___invoke, 0, 2, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Contracts\\Http\\AttributeRequest, 0)
	ZEND_ARG_OBJ_INFO(0, next, Phalcon\\Contracts\\ADR\\Handler, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_middleware_corsmiddleware_applyheaders, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_TYPE_INFO(0, origin, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_middleware_corsmiddleware_isallowed, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, origin, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_middleware_corsmiddleware_getarrval, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cast, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_middleware_corsmiddleware_method_entry) {
	PHP_ME(Phalcon_ADR_Middleware_CorsMiddleware, __construct, arginfo_phalcon_adr_middleware_corsmiddleware___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Middleware_CorsMiddleware, __invoke, arginfo_phalcon_adr_middleware_corsmiddleware___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Middleware_CorsMiddleware, applyHeaders, arginfo_phalcon_adr_middleware_corsmiddleware_applyheaders, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Middleware_CorsMiddleware, isAllowed, arginfo_phalcon_adr_middleware_corsmiddleware_isallowed, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Middleware_CorsMiddleware, getArrVal, arginfo_phalcon_adr_middleware_corsmiddleware_getarrval, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
