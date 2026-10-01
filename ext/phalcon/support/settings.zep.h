
extern zend_class_entry *phalcon_support_settings_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Settings);

PHP_METHOD(Phalcon_Support_Settings, get);
PHP_METHOD(Phalcon_Support_Settings, set);
PHP_METHOD(Phalcon_Support_Settings, reset);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_settings_get, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_settings_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_settings_reset, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_settings_method_entry) {
	PHP_ME(Phalcon_Support_Settings, get, arginfo_phalcon_support_settings_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Support_Settings, set, arginfo_phalcon_support_settings_set, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Support_Settings, reset, arginfo_phalcon_support_settings_reset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
