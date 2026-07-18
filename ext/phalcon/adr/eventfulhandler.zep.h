
extern zend_class_entry *phalcon_adr_eventfulhandler_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_EventfulHandler);

PHP_METHOD(Phalcon_ADR_EventfulHandler, __construct);
PHP_METHOD(Phalcon_ADR_EventfulHandler, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_eventfulhandler___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, action, Phalcon\\Contracts\\ADR\\Action, 0)
	ZEND_ARG_OBJ_INFO(0, events, Phalcon\\Contracts\\Events\\Manager, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_eventfulhandler___invoke, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Contracts\\Http\\AttributeRequestInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_eventfulhandler_method_entry) {
	PHP_ME(Phalcon_ADR_EventfulHandler, __construct, arginfo_phalcon_adr_eventfulhandler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_EventfulHandler, __invoke, arginfo_phalcon_adr_eventfulhandler___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
