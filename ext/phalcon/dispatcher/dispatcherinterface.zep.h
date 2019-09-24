
extern zend_class_entry *phalcon_dispatcher_dispatcherinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Dispatcher_DispatcherInterface);

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_forward, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_forward, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_forward, 0, 0, 1)
#define arginfo_phalcon_dispatcher_dispatcherinterface_forward NULL
#endif

	ZEND_ARG_ARRAY_INFO(0, forward, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_getactionname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_getactionname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_getactionsuffix, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_getactionsuffix, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_gethandlersuffix, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_gethandlersuffix, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_getparams, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_getparams, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_hasparam, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_hasparam, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, param)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_isfinished, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_isfinished, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setactionname, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setactionname, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setactionname, 0, 0, 1)
#define arginfo_phalcon_dispatcher_dispatcherinterface_setactionname NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, actionName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setactionsuffix, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setactionsuffix, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setactionsuffix, 0, 0, 1)
#define arginfo_phalcon_dispatcher_dispatcherinterface_setactionsuffix NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, actionSuffix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, actionSuffix)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setdefaultaction, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setdefaultaction, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setdefaultaction, 0, 0, 1)
#define arginfo_phalcon_dispatcher_dispatcherinterface_setdefaultaction NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, actionName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setdefaultnamespace, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setdefaultnamespace, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setdefaultnamespace, 0, 0, 1)
#define arginfo_phalcon_dispatcher_dispatcherinterface_setdefaultnamespace NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultNamespace, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, defaultNamespace)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_sethandlersuffix, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_sethandlersuffix, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_sethandlersuffix, 0, 0, 1)
#define arginfo_phalcon_dispatcher_dispatcherinterface_sethandlersuffix NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, handlerSuffix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, handlerSuffix)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setmodulename, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setmodulename, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setmodulename, 0, 0, 1)
#define arginfo_phalcon_dispatcher_dispatcherinterface_setmodulename NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, moduleName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, moduleName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setnamespacename, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setnamespacename, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setnamespacename, 0, 0, 1)
#define arginfo_phalcon_dispatcher_dispatcherinterface_setnamespacename NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, namespaceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, namespaceName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setparam, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setparam, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setparam, 0, 0, 2)
#define arginfo_phalcon_dispatcher_dispatcherinterface_setparam NULL
#endif

	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setparams, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setparams, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_dispatcherinterface_setparams, 0, 0, 1)
#define arginfo_phalcon_dispatcher_dispatcherinterface_setparams NULL
#endif

	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_dispatcher_dispatcherinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, dispatch, NULL)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, forward, arginfo_phalcon_dispatcher_dispatcherinterface_forward)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, getActionName, arginfo_phalcon_dispatcher_dispatcherinterface_getactionname)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, getActionSuffix, arginfo_phalcon_dispatcher_dispatcherinterface_getactionsuffix)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, getHandlerSuffix, arginfo_phalcon_dispatcher_dispatcherinterface_gethandlersuffix)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, getParam, arginfo_phalcon_dispatcher_dispatcherinterface_getparam)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, getParams, arginfo_phalcon_dispatcher_dispatcherinterface_getparams)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, getReturnedValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, hasParam, arginfo_phalcon_dispatcher_dispatcherinterface_hasparam)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, isFinished, arginfo_phalcon_dispatcher_dispatcherinterface_isfinished)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, setActionName, arginfo_phalcon_dispatcher_dispatcherinterface_setactionname)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, setActionSuffix, arginfo_phalcon_dispatcher_dispatcherinterface_setactionsuffix)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, setDefaultAction, arginfo_phalcon_dispatcher_dispatcherinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, setDefaultNamespace, arginfo_phalcon_dispatcher_dispatcherinterface_setdefaultnamespace)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, setHandlerSuffix, arginfo_phalcon_dispatcher_dispatcherinterface_sethandlersuffix)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, setModuleName, arginfo_phalcon_dispatcher_dispatcherinterface_setmodulename)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, setNamespaceName, arginfo_phalcon_dispatcher_dispatcherinterface_setnamespacename)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, setParam, arginfo_phalcon_dispatcher_dispatcherinterface_setparam)
	PHP_ABSTRACT_ME(Phalcon_Dispatcher_DispatcherInterface, setParams, arginfo_phalcon_dispatcher_dispatcherinterface_setparams)
	PHP_FE_END
};
