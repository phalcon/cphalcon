
extern zend_class_entry *phalcon_auth_guard_config_sessionguardconfig_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_Config_SessionGuardConfig);

PHP_METHOD(Phalcon_Auth_Guard_Config_SessionGuardConfig, __construct);
PHP_METHOD(Phalcon_Auth_Guard_Config_SessionGuardConfig, getName);
PHP_METHOD(Phalcon_Auth_Guard_Config_SessionGuardConfig, getRememberName);
PHP_METHOD(Phalcon_Auth_Guard_Config_SessionGuardConfig, derive);
PHP_METHOD(Phalcon_Auth_Guard_Config_SessionGuardConfig, validateNonEmpty);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guard_config_sessionguardconfig___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, suffix, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, name, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, rememberName, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_config_sessionguardconfig_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_config_sessionguardconfig_getremembername, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_config_sessionguardconfig_derive, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, suffix, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_config_sessionguardconfig_validatenonempty, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, param, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, value, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_guard_config_sessionguardconfig_method_entry) {
	PHP_ME(Phalcon_Auth_Guard_Config_SessionGuardConfig, __construct, arginfo_phalcon_auth_guard_config_sessionguardconfig___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Guard_Config_SessionGuardConfig, getName, arginfo_phalcon_auth_guard_config_sessionguardconfig_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Config_SessionGuardConfig, getRememberName, arginfo_phalcon_auth_guard_config_sessionguardconfig_getremembername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Config_SessionGuardConfig, derive, arginfo_phalcon_auth_guard_config_sessionguardconfig_derive, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Auth_Guard_Config_SessionGuardConfig, validateNonEmpty, arginfo_phalcon_auth_guard_config_sessionguardconfig_validatenonempty, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
