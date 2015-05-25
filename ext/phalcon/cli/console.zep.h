
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
PHP_METHOD(Phalcon_Cli_Console, setArgument);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_registermodules, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, modules, 0)
ZEND_END_ARG_INFO()

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
	PHP_ME(Phalcon_Cli_Console, __construct, arginfo_phalcon_cli_console___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cli_Console, setDI, arginfo_phalcon_cli_console_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, setEventsManager, arginfo_phalcon_cli_console_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, registerModules, arginfo_phalcon_cli_console_registermodules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, addModules, arginfo_phalcon_cli_console_addmodules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, handle, arginfo_phalcon_cli_console_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, setArgument, arginfo_phalcon_cli_console_setargument, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
