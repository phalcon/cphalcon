
extern zend_class_entry *phalcon_cli_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Dispatcher);

PHP_METHOD(Phalcon_Cli_Dispatcher, callActionMethod);
PHP_METHOD(Phalcon_Cli_Dispatcher, getActiveTask);
PHP_METHOD(Phalcon_Cli_Dispatcher, getLastTask);
PHP_METHOD(Phalcon_Cli_Dispatcher, getOption);
PHP_METHOD(Phalcon_Cli_Dispatcher, getOptions);
PHP_METHOD(Phalcon_Cli_Dispatcher, getTaskName);
PHP_METHOD(Phalcon_Cli_Dispatcher, getTaskSuffix);
PHP_METHOD(Phalcon_Cli_Dispatcher, hasOption);
PHP_METHOD(Phalcon_Cli_Dispatcher, setDefaultTask);
PHP_METHOD(Phalcon_Cli_Dispatcher, setOptions);
PHP_METHOD(Phalcon_Cli_Dispatcher, setTaskName);
PHP_METHOD(Phalcon_Cli_Dispatcher, setTaskSuffix);
PHP_METHOD(Phalcon_Cli_Dispatcher, handleException);
PHP_METHOD(Phalcon_Cli_Dispatcher, throwDispatchException);
zend_object *zephir_init_properties_Phalcon_Cli_Dispatcher(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_callactionmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, actionMethod, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_dispatcher_getactivetask, 0, 0, Phalcon\\Cli\\TaskInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_dispatcher_getlasttask, 0, 0, Phalcon\\Cli\\TaskInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcher_getoptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcher_gettaskname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcher_gettasksuffix, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcher_hasoption, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcher_setdefaulttask, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, taskName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcher_setoptions, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcher_settaskname, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, taskName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcher_settasksuffix, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, taskSuffix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_handleexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, exception, Exception, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_throwdispatchexception, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, exceptionCode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_zephir_init_properties_phalcon_cli_dispatcher, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_dispatcher_method_entry) {
	PHP_ME(Phalcon_Cli_Dispatcher, callActionMethod, arginfo_phalcon_cli_dispatcher_callactionmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, getActiveTask, arginfo_phalcon_cli_dispatcher_getactivetask, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, getLastTask, arginfo_phalcon_cli_dispatcher_getlasttask, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, getOption, arginfo_phalcon_cli_dispatcher_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, getOptions, arginfo_phalcon_cli_dispatcher_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, getTaskName, arginfo_phalcon_cli_dispatcher_gettaskname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, getTaskSuffix, arginfo_phalcon_cli_dispatcher_gettasksuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, hasOption, arginfo_phalcon_cli_dispatcher_hasoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, setDefaultTask, arginfo_phalcon_cli_dispatcher_setdefaulttask, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, setOptions, arginfo_phalcon_cli_dispatcher_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, setTaskName, arginfo_phalcon_cli_dispatcher_settaskname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, setTaskSuffix, arginfo_phalcon_cli_dispatcher_settasksuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, handleException, arginfo_phalcon_cli_dispatcher_handleexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cli_Dispatcher, throwDispatchException, arginfo_phalcon_cli_dispatcher_throwdispatchexception, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
