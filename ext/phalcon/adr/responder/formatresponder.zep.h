
extern zend_class_entry *phalcon_adr_responder_formatresponder_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_FormatResponder);

PHP_METHOD(Phalcon_ADR_Responder_FormatResponder, __construct);
PHP_METHOD(Phalcon_ADR_Responder_FormatResponder, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_responder_formatresponder___construct, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, formatters, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_responder_formatresponder___invoke, 0, 3, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, payload, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_responder_formatresponder_method_entry) {
	PHP_ME(Phalcon_ADR_Responder_FormatResponder, __construct, arginfo_phalcon_adr_responder_formatresponder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Responder_FormatResponder, __invoke, arginfo_phalcon_adr_responder_formatresponder___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
