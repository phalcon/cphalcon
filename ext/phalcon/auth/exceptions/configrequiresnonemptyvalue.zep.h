
extern zend_class_entry *phalcon_auth_exceptions_configrequiresnonemptyvalue_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Exceptions_ConfigRequiresNonEmptyValue);

PHP_METHOD(Phalcon_Auth_Exceptions_ConfigRequiresNonEmptyValue, __construct);
PHP_METHOD(Phalcon_Auth_Exceptions_ConfigRequiresNonEmptyValue, assert);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_exceptions_configrequiresnonemptyvalue___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, configName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, configKey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, suffix, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_exceptions_configrequiresnonemptyvalue_assert, 0, 3, IS_VOID, 0)

	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, configName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, configKey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, suffix, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_exceptions_configrequiresnonemptyvalue_method_entry) {
	PHP_ME(Phalcon_Auth_Exceptions_ConfigRequiresNonEmptyValue, __construct, arginfo_phalcon_auth_exceptions_configrequiresnonemptyvalue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Exceptions_ConfigRequiresNonEmptyValue, assert, arginfo_phalcon_auth_exceptions_configrequiresnonemptyvalue_assert, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
