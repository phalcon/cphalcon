
extern zend_class_entry *phalcon_adr_responder_viewresponder_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_ViewResponder);

PHP_METHOD(Phalcon_ADR_Responder_ViewResponder, __construct);
PHP_METHOD(Phalcon_ADR_Responder_ViewResponder, __invoke);
PHP_METHOD(Phalcon_ADR_Responder_ViewResponder, withTemplate);
PHP_METHOD(Phalcon_ADR_Responder_ViewResponder, viewData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_responder_viewresponder___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, renderer, Phalcon\\Contracts\\View\\Renderer, 0)
	ZEND_ARG_OBJ_INFO(0, statusMapper, Phalcon\\ADR\\Responder\\StatusMapper, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, template, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_responder_viewresponder___invoke, 0, 3, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, payload, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_adr_responder_viewresponder_withtemplate, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, template, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_responder_viewresponder_viewdata, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, payload, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_responder_viewresponder_method_entry) {
	PHP_ME(Phalcon_ADR_Responder_ViewResponder, __construct, arginfo_phalcon_adr_responder_viewresponder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Responder_ViewResponder, __invoke, arginfo_phalcon_adr_responder_viewresponder___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Responder_ViewResponder, withTemplate, arginfo_phalcon_adr_responder_viewresponder_withtemplate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Responder_ViewResponder, viewData, arginfo_phalcon_adr_responder_viewresponder_viewdata, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
