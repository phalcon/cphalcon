
extern zend_class_entry *phalcon_cli_task_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Task);

PHP_METHOD(Phalcon_Cli_Task, __construct);
PHP_METHOD(Phalcon_Cli_Task, getEventsManager);
PHP_METHOD(Phalcon_Cli_Task, setEventsManager);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_task___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_task_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_task_geteventsmanager, 0, 0, IS_OBJECT, "Phalcon\\Events\\ManagerInterface", 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_task_seteventsmanager, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_task_seteventsmanager, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_task_seteventsmanager, 0, 0, 1)
#define arginfo_phalcon_cli_task_seteventsmanager NULL
#endif

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_task_method_entry) {
	PHP_ME(Phalcon_Cli_Task, __construct, arginfo_phalcon_cli_task___construct, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cli_Task, getEventsManager, arginfo_phalcon_cli_task_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Task, setEventsManager, arginfo_phalcon_cli_task_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
