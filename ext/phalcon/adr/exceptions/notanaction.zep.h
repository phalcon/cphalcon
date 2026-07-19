
extern zend_class_entry *phalcon_adr_exceptions_notanaction_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Exceptions_NotAnAction);

PHP_METHOD(Phalcon_ADR_Exceptions_NotAnAction, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_exceptions_notanaction___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, className, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_exceptions_notanaction_method_entry) {
	PHP_ME(Phalcon_ADR_Exceptions_NotAnAction, __construct, arginfo_phalcon_adr_exceptions_notanaction___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
