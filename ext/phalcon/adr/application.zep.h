
extern zend_class_entry *phalcon_adr_application_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Application);

PHP_METHOD(Phalcon_ADR_Application, __construct);
PHP_METHOD(Phalcon_ADR_Application, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_application___construct, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, router, Phalcon\\Contracts\\ADR\\Router\\Router, 0)
	ZEND_ARG_OBJ_INFO(0, dispatcher, Phalcon\\Contracts\\ADR\\Dispatcher, 0)
	ZEND_ARG_OBJ_INFO(0, errorResponder, Phalcon\\ADR\\ErrorResponder, 0)
	ZEND_ARG_OBJ_INFO(0, events, Phalcon\\Contracts\\Events\\Manager, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_application_handle, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Contracts\\Http\\AttributeRequest, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_application_method_entry) {
	PHP_ME(Phalcon_ADR_Application, __construct, arginfo_phalcon_adr_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Application, handle, arginfo_phalcon_adr_application_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
