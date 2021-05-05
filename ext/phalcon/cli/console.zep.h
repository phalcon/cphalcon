
extern zend_class_entry *phalcon_cli_console_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Console);

PHP_METHOD(Phalcon_Cli_Console, handle);
PHP_METHOD(Phalcon_Cli_Console, setArgument);
zend_object *zephir_init_properties_Phalcon_Cli_Console(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_handle, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, arguments, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, arguments, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_console_setargument, 0, 0, Phalcon\\Cli\\Console, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, arguments, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, arguments, 1)
#endif
	ZEND_ARG_TYPE_INFO(0, str, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, shift, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_zephir_init_properties_phalcon_cli_console, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_console_method_entry) {
	PHP_ME(Phalcon_Cli_Console, handle, arginfo_phalcon_cli_console_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, setArgument, arginfo_phalcon_cli_console_setargument, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
