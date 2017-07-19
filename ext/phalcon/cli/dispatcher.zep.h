
extern zend_class_entry *phalcon_cli_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Dispatcher);

PHP_METHOD(Phalcon_Cli_Dispatcher, setTaskSuffix);
PHP_METHOD(Phalcon_Cli_Dispatcher, setDefaultTask);
PHP_METHOD(Phalcon_Cli_Dispatcher, setTaskName);
PHP_METHOD(Phalcon_Cli_Dispatcher, getTaskName);
PHP_METHOD(Phalcon_Cli_Dispatcher, _throwDispatchException);
PHP_METHOD(Phalcon_Cli_Dispatcher, _handleException);
PHP_METHOD(Phalcon_Cli_Dispatcher, getLastTask);
PHP_METHOD(Phalcon_Cli_Dispatcher, getActiveTask);
PHP_METHOD(Phalcon_Cli_Dispatcher, setOptions);
PHP_METHOD(Phalcon_Cli_Dispatcher, getOptions);
PHP_METHOD(Phalcon_Cli_Dispatcher, getOption);
PHP_METHOD(Phalcon_Cli_Dispatcher, hasOption);
PHP_METHOD(Phalcon_Cli_Dispatcher, callActionMethod);
zend_object_value zephir_init_properties_Phalcon_Cli_Dispatcher(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_settasksuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, taskSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_setdefaulttask, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_settaskname, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher__throwdispatchexception, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, exceptionCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher__handleexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, exception, Exception, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_hasoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_callactionmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, actionMethod)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_dispatcher_method_entry) {
	PHP_ME(Phalcon_Cli_Dispatcher, setTaskSuffix, arginfo_phalcon_cli_dispatcher_settasksuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, setDefaultTask, arginfo_phalcon_cli_dispatcher_setdefaulttask, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, setTaskName, arginfo_phalcon_cli_dispatcher_settaskname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, getTaskName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, _throwDispatchException, arginfo_phalcon_cli_dispatcher__throwdispatchexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cli_Dispatcher, _handleException, arginfo_phalcon_cli_dispatcher__handleexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cli_Dispatcher, getLastTask, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, getActiveTask, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, setOptions, arginfo_phalcon_cli_dispatcher_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, getOption, arginfo_phalcon_cli_dispatcher_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, hasOption, arginfo_phalcon_cli_dispatcher_hasoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, callActionMethod, arginfo_phalcon_cli_dispatcher_callactionmethod, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
