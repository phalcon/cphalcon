
extern zend_class_entry *phalcon_cli_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_CLI_Dispatcher);

PHP_METHOD(Phalcon_CLI_Dispatcher, setTaskSuffix);
PHP_METHOD(Phalcon_CLI_Dispatcher, setDefaultTask);
PHP_METHOD(Phalcon_CLI_Dispatcher, setTaskName);
PHP_METHOD(Phalcon_CLI_Dispatcher, getTaskName);
PHP_METHOD(Phalcon_CLI_Dispatcher, _throwDispatchException);
PHP_METHOD(Phalcon_CLI_Dispatcher, getLastTask);
PHP_METHOD(Phalcon_CLI_Dispatcher, getActiveTask);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_settasksuffix, 0, 0, 0)
	ZEND_ARG_INFO(0, taskSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_setdefaulttask, 0, 0, 0)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_settaskname, 0, 0, 0)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher__throwdispatchexception, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, exceptionCode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_dispatcher_method_entry) {
	PHP_ME(Phalcon_CLI_Dispatcher, setTaskSuffix, arginfo_phalcon_cli_dispatcher_settasksuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Dispatcher, setDefaultTask, arginfo_phalcon_cli_dispatcher_setdefaulttask, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Dispatcher, setTaskName, arginfo_phalcon_cli_dispatcher_settaskname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Dispatcher, getTaskName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Dispatcher, _throwDispatchException, arginfo_phalcon_cli_dispatcher__throwdispatchexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_CLI_Dispatcher, getLastTask, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Dispatcher, getActiveTask, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
