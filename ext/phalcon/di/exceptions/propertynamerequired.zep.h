
extern zend_class_entry *phalcon_di_exceptions_propertynamerequired_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_Exceptions_PropertyNameRequired);

PHP_METHOD(Phalcon_Di_Exceptions_PropertyNameRequired, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_exceptions_propertynamerequired___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_exceptions_propertynamerequired_method_entry) {
	PHP_ME(Phalcon_Di_Exceptions_PropertyNameRequired, __construct, arginfo_phalcon_di_exceptions_propertynamerequired___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
