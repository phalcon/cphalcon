
extern zend_class_entry *phalcon_cli_dispatcherinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_DispatcherInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_getactivetask, 0, 0, Phalcon\\Cli\\TaskInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_getactivetask, 0, 0, IS_OBJECT, "Phalcon\\Cli\\TaskInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_getlasttask, 0, 0, Phalcon\\Cli\\TaskInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_getlasttask, 0, 0, IS_OBJECT, "Phalcon\\Cli\\TaskInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_getoptions, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_getoptions, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_gettaskname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_gettaskname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_gettasksuffix, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_gettasksuffix, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_setdefaulttask, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_setdefaulttask, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_setdefaulttask, 0, 0, 1)
#define arginfo_phalcon_cli_dispatcherinterface_setdefaulttask NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, taskName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, taskName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_setoptions, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_setoptions, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_setoptions, 0, 0, 1)
#define arginfo_phalcon_cli_dispatcherinterface_setoptions NULL
#endif

	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_settaskname, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_settaskname, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_settaskname, 0, 0, 1)
#define arginfo_phalcon_cli_dispatcherinterface_settaskname NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, taskName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, taskName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_settasksuffix, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_settasksuffix, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_settasksuffix, 0, 0, 1)
#define arginfo_phalcon_cli_dispatcherinterface_settasksuffix NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, taskSuffix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, taskSuffix)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_dispatcherinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, getActiveTask, arginfo_phalcon_cli_dispatcherinterface_getactivetask)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, getLastTask, arginfo_phalcon_cli_dispatcherinterface_getlasttask)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, getOptions, arginfo_phalcon_cli_dispatcherinterface_getoptions)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, getTaskName, arginfo_phalcon_cli_dispatcherinterface_gettaskname)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, getTaskSuffix, arginfo_phalcon_cli_dispatcherinterface_gettasksuffix)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, setDefaultTask, arginfo_phalcon_cli_dispatcherinterface_setdefaulttask)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, setOptions, arginfo_phalcon_cli_dispatcherinterface_setoptions)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, setTaskName, arginfo_phalcon_cli_dispatcherinterface_settaskname)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, setTaskSuffix, arginfo_phalcon_cli_dispatcherinterface_settasksuffix)
	PHP_FE_END
};
