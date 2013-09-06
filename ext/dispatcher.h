
extern zend_class_entry *phalcon_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_Dispatcher);

PHP_METHOD(Phalcon_Dispatcher, setDI);
PHP_METHOD(Phalcon_Dispatcher, getDI);
PHP_METHOD(Phalcon_Dispatcher, setEventsManager);
PHP_METHOD(Phalcon_Dispatcher, getEventsManager);
PHP_METHOD(Phalcon_Dispatcher, setActionSuffix);
PHP_METHOD(Phalcon_Dispatcher, setModuleName);
PHP_METHOD(Phalcon_Dispatcher, getModuleName);
PHP_METHOD(Phalcon_Dispatcher, setNamespaceName);
PHP_METHOD(Phalcon_Dispatcher, getNamespaceName);
PHP_METHOD(Phalcon_Dispatcher, setDefaultNamespace);
PHP_METHOD(Phalcon_Dispatcher, getDefaultNamespace);
PHP_METHOD(Phalcon_Dispatcher, setDefaultAction);
PHP_METHOD(Phalcon_Dispatcher, setActionName);
PHP_METHOD(Phalcon_Dispatcher, getActionName);
PHP_METHOD(Phalcon_Dispatcher, setParams);
PHP_METHOD(Phalcon_Dispatcher, getParams);
PHP_METHOD(Phalcon_Dispatcher, setParam);
PHP_METHOD(Phalcon_Dispatcher, getParam);
PHP_METHOD(Phalcon_Dispatcher, getActiveMethod);
PHP_METHOD(Phalcon_Dispatcher, isFinished);
PHP_METHOD(Phalcon_Dispatcher, setReturnedValue);
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue);
PHP_METHOD(Phalcon_Dispatcher, dispatch);
PHP_METHOD(Phalcon_Dispatcher, forward);
PHP_METHOD(Phalcon_Dispatcher, wasForwarded);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setDI, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setEventsManager, 0, 0, 0)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setActionSuffix, 0, 0, 0)
	ZEND_ARG_INFO(0, actionSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setModuleName, 0, 0, 0)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setNamespaceName, 0, 0, 0)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setDefaultNamespace, 0, 0, 0)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setDefaultAction, 0, 0, 0)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setActionName, 0, 0, 0)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setParams, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setParam, 0, 0, 0)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_getParam, 0, 0, 0)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setReturnedValue, 0, 0, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_forward, 0, 0, 0)
	ZEND_ARG_INFO(0, forward)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_dispatcher_method_entry) {
	PHP_ME(Phalcon_Dispatcher, setDI, arginfo_phalcon_dispatcher_setDI, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setEventsManager, arginfo_phalcon_dispatcher_setEventsManager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setActionSuffix, arginfo_phalcon_dispatcher_setActionSuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setModuleName, arginfo_phalcon_dispatcher_setModuleName, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setNamespaceName, arginfo_phalcon_dispatcher_setNamespaceName, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getNamespaceName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setDefaultNamespace, arginfo_phalcon_dispatcher_setDefaultNamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getDefaultNamespace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setDefaultAction, arginfo_phalcon_dispatcher_setDefaultAction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setActionName, arginfo_phalcon_dispatcher_setActionName, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setParams, arginfo_phalcon_dispatcher_setParams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setParam, arginfo_phalcon_dispatcher_setParam, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getParam, arginfo_phalcon_dispatcher_getParam, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getActiveMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, isFinished, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setReturnedValue, arginfo_phalcon_dispatcher_setReturnedValue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getReturnedValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, dispatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, forward, arginfo_phalcon_dispatcher_forward, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, wasForwarded, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
