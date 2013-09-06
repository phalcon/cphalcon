
extern zend_class_entry *phalcon_cli_console_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Console);

PHP_METHOD(Phalcon_Cli_Console, __construct);
PHP_METHOD(Phalcon_Cli_Console, setDI);
PHP_METHOD(Phalcon_Cli_Console, getDI);
PHP_METHOD(Phalcon_Cli_Console, setEventsManager);
PHP_METHOD(Phalcon_Cli_Console, getEventsManager);
PHP_METHOD(Phalcon_Cli_Console, registerModules);
PHP_METHOD(Phalcon_Cli_Console, addModules);
PHP_METHOD(Phalcon_Cli_Console, getModules);
PHP_METHOD(Phalcon_Cli_Console, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_setDI, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_setEventsManager, 0, 0, 0)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_registerModules, 0, 0, 0)
	ZEND_ARG_INFO(0, modules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_addModules, 0, 0, 0)
	ZEND_ARG_INFO(0, modules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_console_method_entry) {
	PHP_ME(Phalcon_Cli_Console, __construct, arginfo_phalcon_cli_console___construct, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, setDI, arginfo_phalcon_cli_console_setDI, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, setEventsManager, arginfo_phalcon_cli_console_setEventsManager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, registerModules, arginfo_phalcon_cli_console_registerModules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, addModules, arginfo_phalcon_cli_console_addModules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, handle, arginfo_phalcon_cli_console_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
