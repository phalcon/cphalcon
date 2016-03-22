
extern zend_class_entry *phalcon_cli_dispatcherinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_settasksuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, taskSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_setdefaulttask, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_settaskname, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_dispatcherinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, setTaskSuffix, arginfo_phalcon_cli_dispatcherinterface_settasksuffix)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, setDefaultTask, arginfo_phalcon_cli_dispatcherinterface_setdefaulttask)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, setTaskName, arginfo_phalcon_cli_dispatcherinterface_settaskname)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, getTaskName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, getLastTask, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, getActiveTask, NULL)
	PHP_FE_END
};
