
extern zend_class_entry *phalcon_cli_console_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Console);

PHP_METHOD(Phalcon_Cli_Console, addModules);
PHP_METHOD(Phalcon_Cli_Console, handle);
PHP_METHOD(Phalcon_Cli_Console, setArgument);
zend_object_value zephir_init_properties_Phalcon_Cli_Console(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_addmodules, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, modules, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_handle, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_setargument, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, shift)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_console_method_entry) {
	PHP_ME(Phalcon_Cli_Console, addModules, arginfo_phalcon_cli_console_addmodules, ZEND_ACC_DEPRECATED|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, handle, arginfo_phalcon_cli_console_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, setArgument, arginfo_phalcon_cli_console_setargument, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
