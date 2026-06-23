
extern zend_class_entry *phalcon_auth_exceptions_optionrequiresarray_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Exceptions_OptionRequiresArray);

PHP_METHOD(Phalcon_Auth_Exceptions_OptionRequiresArray, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_exceptions_optionrequiresarray___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, context, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_exceptions_optionrequiresarray_method_entry) {
	PHP_ME(Phalcon_Auth_Exceptions_OptionRequiresArray, __construct, arginfo_phalcon_auth_exceptions_optionrequiresarray___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
