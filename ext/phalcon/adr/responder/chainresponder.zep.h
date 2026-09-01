
extern zend_class_entry *phalcon_adr_responder_chainresponder_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_ChainResponder);

PHP_METHOD(Phalcon_ADR_Responder_ChainResponder, __construct);
PHP_METHOD(Phalcon_ADR_Responder_ChainResponder, __invoke);
PHP_METHOD(Phalcon_ADR_Responder_ChainResponder, with);
zend_object *zephir_init_properties_Phalcon_ADR_Responder_ChainResponder(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_responder_chainresponder___construct, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, links, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_responder_chainresponder___invoke, 0, 3, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, payload, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_responder_chainresponder_with, 0, 1, Phalcon\\ADR\\Responder\\ChainResponder, 0)
	ZEND_ARG_OBJ_INFO(0, link, Phalcon\\Contracts\\ADR\\Responder\\Responder, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_responder_chainresponder_zephir_init_properties_phalcon_adr_responder_chainresponder, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_responder_chainresponder_method_entry) {
	PHP_ME(Phalcon_ADR_Responder_ChainResponder, __construct, arginfo_phalcon_adr_responder_chainresponder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Responder_ChainResponder, __invoke, arginfo_phalcon_adr_responder_chainresponder___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Responder_ChainResponder, with, arginfo_phalcon_adr_responder_chainresponder_with, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
