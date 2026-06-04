
extern zend_class_entry *phalcon_forms_exceptions_invalidjsonschema_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Exceptions_InvalidJsonSchema);

PHP_METHOD(Phalcon_Forms_Exceptions_InvalidJsonSchema, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_exceptions_invalidjsonschema___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, detail, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_exceptions_invalidjsonschema_method_entry) {
	PHP_ME(Phalcon_Forms_Exceptions_InvalidJsonSchema, __construct, arginfo_phalcon_forms_exceptions_invalidjsonschema___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
