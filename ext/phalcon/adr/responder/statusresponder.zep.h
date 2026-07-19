
extern zend_class_entry *phalcon_adr_responder_statusresponder_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_StatusResponder);

PHP_METHOD(Phalcon_ADR_Responder_StatusResponder, __construct);
PHP_METHOD(Phalcon_ADR_Responder_StatusResponder, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_responder_statusresponder___construct, 0, 0, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, mapper, Phalcon\\ADR\\Responder\\StatusMapper, MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_responder_statusresponder___invoke, 0, 3, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, payload, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_responder_statusresponder_method_entry) {
	PHP_ME(Phalcon_ADR_Responder_StatusResponder, __construct, arginfo_phalcon_adr_responder_statusresponder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Responder_StatusResponder, __invoke, arginfo_phalcon_adr_responder_statusresponder___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
