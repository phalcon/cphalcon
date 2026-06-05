
extern zend_class_entry *phalcon_di_exceptions_missingparameterkey_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_Exceptions_MissingParameterKey);

PHP_METHOD(Phalcon_Di_Exceptions_MissingParameterKey, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_exceptions_missingparameterkey___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_exceptions_missingparameterkey_method_entry) {
	PHP_ME(Phalcon_Di_Exceptions_MissingParameterKey, __construct, arginfo_phalcon_di_exceptions_missingparameterkey___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
