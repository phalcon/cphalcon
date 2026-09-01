
extern zend_class_entry *phalcon_adr_responder_redirectresponder_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_RedirectResponder);

PHP_METHOD(Phalcon_ADR_Responder_RedirectResponder, __invoke);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_responder_redirectresponder___invoke, 0, 3, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, payload, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_responder_redirectresponder_method_entry) {
	PHP_ME(Phalcon_ADR_Responder_RedirectResponder, __invoke, arginfo_phalcon_adr_responder_redirectresponder___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
