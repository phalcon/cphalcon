
extern zend_class_entry *phalcon_adr_responder_statusmapper_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_StatusMapper);

PHP_METHOD(Phalcon_ADR_Responder_StatusMapper, __construct);
PHP_METHOD(Phalcon_ADR_Responder_StatusMapper, toHttpCode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_responder_statusmapper___construct, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, overrides, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_responder_statusmapper_tohttpcode, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, status, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_responder_statusmapper_method_entry) {
	PHP_ME(Phalcon_ADR_Responder_StatusMapper, __construct, arginfo_phalcon_adr_responder_statusmapper___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Responder_StatusMapper, toHttpCode, arginfo_phalcon_adr_responder_statusmapper_tohttpcode, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
