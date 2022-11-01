
extern zend_class_entry *phalcon_dispatcher_abstractdispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_Dispatcher_AbstractDispatcher);

PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, callActionMethod);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, dispatch);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, forward);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getActionName);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getActionSuffix);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getActiveMethod);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getBoundModels);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getDefaultNamespace);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getEventsManager);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getHandlerSuffix);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getModelBinder);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getModuleName);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getNamespaceName);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getParam);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getParameter);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getParams);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getParameters);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, hasParam);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, hasParameter);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, isFinished);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setActionName);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setDefaultAction);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setDefaultNamespace);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getHandlerClass);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setParam);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setParameter);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setParams);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setParameters);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setReturnedValue);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setActionSuffix);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setEventsManager);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setHandlerSuffix);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setModelBinder);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setModuleName);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setNamespaceName);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getReturnedValue);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, wasForwarded);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, resolveEmptyProperties);
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, toCamelCase);
zend_object *zephir_init_properties_Phalcon_Dispatcher_AbstractDispatcher(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_callactionmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, actionMethod, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, params, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, params, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_dispatch, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_forward, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, forward, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_getactionname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_getactionsuffix, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_getactivemethod, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_getboundmodels, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_getdefaultnamespace, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_gethandlersuffix, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_getmodelbinder, 0, 0, Phalcon\\Mvc\\Model\\BinderInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_getmodulename, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_getnamespacename, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_getparameter, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_getparams, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_getparameters, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_hasparam, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, param)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_hasparameter, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, param)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_isfinished, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_setactionname, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_setdefaultaction, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_setdefaultnamespace, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, defaultNamespace, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_gethandlerclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_setparam, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_setparameter, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_setparams, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_setparameters, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_setreturnedvalue, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_setactionsuffix, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, actionSuffix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_seteventsmanager, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_sethandlersuffix, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handlerSuffix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_setmodelbinder, 0, 1, Phalcon\\Dispatcher\\DispatcherInterface, 0)
	ZEND_ARG_OBJ_INFO(0, modelBinder, Phalcon\\Mvc\\Model\\BinderInterface, 0)
	ZEND_ARG_INFO(0, cache)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_setmodulename, 0, 0, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, moduleName, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_setnamespacename, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, namespaceName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_getreturnedvalue, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_wasforwarded, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_resolveemptyproperties, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_tocamelcase, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_abstractdispatcher_zephir_init_properties_phalcon_dispatcher_abstractdispatcher, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_dispatcher_abstractdispatcher_method_entry) {
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, callActionMethod, arginfo_phalcon_dispatcher_abstractdispatcher_callactionmethod, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, dispatch, arginfo_phalcon_dispatcher_abstractdispatcher_dispatch, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, dispatch, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, forward, arginfo_phalcon_dispatcher_abstractdispatcher_forward, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getActionName, arginfo_phalcon_dispatcher_abstractdispatcher_getactionname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getActionSuffix, arginfo_phalcon_dispatcher_abstractdispatcher_getactionsuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getActiveMethod, arginfo_phalcon_dispatcher_abstractdispatcher_getactivemethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getBoundModels, arginfo_phalcon_dispatcher_abstractdispatcher_getboundmodels, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getDefaultNamespace, arginfo_phalcon_dispatcher_abstractdispatcher_getdefaultnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getEventsManager, arginfo_phalcon_dispatcher_abstractdispatcher_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getHandlerSuffix, arginfo_phalcon_dispatcher_abstractdispatcher_gethandlersuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getModelBinder, arginfo_phalcon_dispatcher_abstractdispatcher_getmodelbinder, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getModuleName, arginfo_phalcon_dispatcher_abstractdispatcher_getmodulename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getNamespaceName, arginfo_phalcon_dispatcher_abstractdispatcher_getnamespacename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getParam, arginfo_phalcon_dispatcher_abstractdispatcher_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getParameter, arginfo_phalcon_dispatcher_abstractdispatcher_getparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getParams, arginfo_phalcon_dispatcher_abstractdispatcher_getparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getParameters, arginfo_phalcon_dispatcher_abstractdispatcher_getparameters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, hasParam, arginfo_phalcon_dispatcher_abstractdispatcher_hasparam, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, hasParameter, arginfo_phalcon_dispatcher_abstractdispatcher_hasparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, isFinished, arginfo_phalcon_dispatcher_abstractdispatcher_isfinished, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, setActionName, arginfo_phalcon_dispatcher_abstractdispatcher_setactionname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, setDefaultAction, arginfo_phalcon_dispatcher_abstractdispatcher_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, setDefaultNamespace, arginfo_phalcon_dispatcher_abstractdispatcher_setdefaultnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getHandlerClass, arginfo_phalcon_dispatcher_abstractdispatcher_gethandlerclass, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, setParam, arginfo_phalcon_dispatcher_abstractdispatcher_setparam, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, setParameter, arginfo_phalcon_dispatcher_abstractdispatcher_setparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, setParams, arginfo_phalcon_dispatcher_abstractdispatcher_setparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, setParameters, arginfo_phalcon_dispatcher_abstractdispatcher_setparameters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, setReturnedValue, arginfo_phalcon_dispatcher_abstractdispatcher_setreturnedvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, setActionSuffix, arginfo_phalcon_dispatcher_abstractdispatcher_setactionsuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, setEventsManager, arginfo_phalcon_dispatcher_abstractdispatcher_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, setHandlerSuffix, arginfo_phalcon_dispatcher_abstractdispatcher_sethandlersuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, setModelBinder, arginfo_phalcon_dispatcher_abstractdispatcher_setmodelbinder, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, setModuleName, arginfo_phalcon_dispatcher_abstractdispatcher_setmodulename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, setNamespaceName, arginfo_phalcon_dispatcher_abstractdispatcher_setnamespacename, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getReturnedValue, arginfo_phalcon_dispatcher_abstractdispatcher_getreturnedvalue, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, getReturnedValue, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, wasForwarded, arginfo_phalcon_dispatcher_abstractdispatcher_wasforwarded, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, resolveEmptyProperties, arginfo_phalcon_dispatcher_abstractdispatcher_resolveemptyproperties, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Dispatcher_AbstractDispatcher, toCamelCase, arginfo_phalcon_dispatcher_abstractdispatcher_tocamelcase, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
