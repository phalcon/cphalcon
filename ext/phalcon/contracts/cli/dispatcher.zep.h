
extern zend_class_entry *phalcon_contracts_cli_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Cli_Dispatcher);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_cli_dispatcher_getactivetask, 0, 0, Phalcon\\Cli\\TaskInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_cli_dispatcher_getlasttask, 0, 0, Phalcon\\Cli\\TaskInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_cli_dispatcher_getoptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_cli_dispatcher_gettaskname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_cli_dispatcher_gettasksuffix, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_cli_dispatcher_setdefaulttask, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, taskName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_cli_dispatcher_setoptions, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_cli_dispatcher_settaskname, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, taskName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_cli_dispatcher_settasksuffix, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, taskSuffix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_cli_dispatcher_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cli_Dispatcher, getActiveTask, arginfo_phalcon_contracts_cli_dispatcher_getactivetask)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cli_Dispatcher, getLastTask, arginfo_phalcon_contracts_cli_dispatcher_getlasttask)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cli_Dispatcher, getOptions, arginfo_phalcon_contracts_cli_dispatcher_getoptions)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cli_Dispatcher, getTaskName, arginfo_phalcon_contracts_cli_dispatcher_gettaskname)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cli_Dispatcher, getTaskSuffix, arginfo_phalcon_contracts_cli_dispatcher_gettasksuffix)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cli_Dispatcher, setDefaultTask, arginfo_phalcon_contracts_cli_dispatcher_setdefaulttask)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cli_Dispatcher, setOptions, arginfo_phalcon_contracts_cli_dispatcher_setoptions)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cli_Dispatcher, setTaskName, arginfo_phalcon_contracts_cli_dispatcher_settaskname)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cli_Dispatcher, setTaskSuffix, arginfo_phalcon_contracts_cli_dispatcher_settasksuffix)
	PHP_FE_END
};
