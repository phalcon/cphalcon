
extern zend_class_entry *phalcon_adr_errorresponder_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_ErrorResponder);

PHP_METHOD(Phalcon_ADR_ErrorResponder, __construct);
PHP_METHOD(Phalcon_ADR_ErrorResponder, handle);
PHP_METHOD(Phalcon_ADR_ErrorResponder, correlationId);
PHP_METHOD(Phalcon_ADR_ErrorResponder, defaultMap);
PHP_METHOD(Phalcon_ADR_ErrorResponder, details);
PHP_METHOD(Phalcon_ADR_ErrorResponder, reason);
PHP_METHOD(Phalcon_ADR_ErrorResponder, resolveStatus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_errorresponder___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, chain, Phalcon\\Contracts\\ADR\\Responder\\Responder, 0)
	ZEND_ARG_OBJ_INFO(0, logger, Phalcon\\Contracts\\Logger\\Logger, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, debug, _IS_BOOL, 0, "false")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, exceptionMap, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_errorresponder_handle, 0, 3, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_errorresponder_correlationid, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_errorresponder_defaultmap, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_errorresponder_details, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
	ZEND_ARG_TYPE_INFO(0, ref, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, status, IS_STRING, 0, "'ERROR'")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_errorresponder_reason, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, status, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_errorresponder_resolvestatus, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_errorresponder_method_entry) {
	PHP_ME(Phalcon_ADR_ErrorResponder, __construct, arginfo_phalcon_adr_errorresponder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_ErrorResponder, handle, arginfo_phalcon_adr_errorresponder_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_ErrorResponder, correlationId, arginfo_phalcon_adr_errorresponder_correlationid, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_ErrorResponder, defaultMap, arginfo_phalcon_adr_errorresponder_defaultmap, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_ErrorResponder, details, arginfo_phalcon_adr_errorresponder_details, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_ErrorResponder, reason, arginfo_phalcon_adr_errorresponder_reason, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_ErrorResponder, resolveStatus, arginfo_phalcon_adr_errorresponder_resolvestatus, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
