
extern zend_class_entry *phalcon_firewall_adapter_acl_ce;

ZEPHIR_INIT_CLASS(Phalcon_Firewall_Adapter_Acl);

PHP_METHOD(Phalcon_Firewall_Adapter_Acl, getAclServiceName);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, setAclServiceName);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, getBoundModelsKeyMap);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, setBoundModelsKeyMap);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, getModuleSeparator);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, setModuleSeparator);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, getRoleCacheCallback);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, setRoleCacheCallback);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, __construct);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, afterBinding);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, beforeExecuteRoute);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, getDispatcher);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, isMultiModuleConfiguration);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, useMultiModuleConfiguration);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, getAccessFromCache);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, handleDispatcher);
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, saveAccessInCache);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_acl_getaclservicename, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_acl_getaclservicename, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_acl_setaclservicename, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, aclServiceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, aclServiceName)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_acl_setboundmodelskeymap, 0, 0, 1)
	ZEND_ARG_INFO(0, boundModelsKeyMap)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_acl_getmoduleseparator, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_acl_getmoduleseparator, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_acl_setmoduleseparator, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, moduleSeparator, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, moduleSeparator)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_acl_setrolecachecallback, 0, 0, 1)
	ZEND_ARG_INFO(0, roleCacheCallback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_acl___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, aclServiceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, aclServiceName)
#endif
	ZEND_ARG_ARRAY_INFO(0, boundModelsKeyMap, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_acl_afterbinding, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, dispatcher, Phalcon\\Mvc\\DispatcherInterface, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_acl_beforeexecuteroute, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, dispatcher, Phalcon\\Mvc\\DispatcherInterface, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_firewall_adapter_acl_getdispatcher, 0, 0, Phalcon\\Firewall\\Adapter\\Dispatcher, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_acl_getdispatcher, 0, 0, IS_OBJECT, "Phalcon\\Firewall\\Adapter\\Dispatcher", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_acl_ismultimoduleconfiguration, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_acl_ismultimoduleconfiguration, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_acl_usemultimoduleconfiguration, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, multiModuleConfiguration, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, multiModuleConfiguration)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_acl_getaccessfromcache, 0, 1, _IS_BOOL, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_acl_getaccessfromcache, 0, 1, _IS_BOOL, NULL, 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_ARRAY_INFO(0, originalValues, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, roleCacheKey, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, roleCacheKey)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_acl_handledispatcher, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dispatcher, Phalcon\\Mvc\\DispatcherInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_acl_saveaccessincache, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_acl_saveaccessincache, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_acl_saveaccessincache, 0, 0, 2)
#define arginfo_phalcon_firewall_adapter_acl_saveaccessincache NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, access, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, access)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_firewall_adapter_acl_method_entry) {
	PHP_ME(Phalcon_Firewall_Adapter_Acl, getAclServiceName, arginfo_phalcon_firewall_adapter_acl_getaclservicename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, setAclServiceName, arginfo_phalcon_firewall_adapter_acl_setaclservicename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, getBoundModelsKeyMap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, setBoundModelsKeyMap, arginfo_phalcon_firewall_adapter_acl_setboundmodelskeymap, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, getModuleSeparator, arginfo_phalcon_firewall_adapter_acl_getmoduleseparator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, setModuleSeparator, arginfo_phalcon_firewall_adapter_acl_setmoduleseparator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, getRoleCacheCallback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, setRoleCacheCallback, arginfo_phalcon_firewall_adapter_acl_setrolecachecallback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, __construct, arginfo_phalcon_firewall_adapter_acl___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, afterBinding, arginfo_phalcon_firewall_adapter_acl_afterbinding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, beforeExecuteRoute, arginfo_phalcon_firewall_adapter_acl_beforeexecuteroute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, getDispatcher, arginfo_phalcon_firewall_adapter_acl_getdispatcher, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, isMultiModuleConfiguration, arginfo_phalcon_firewall_adapter_acl_ismultimoduleconfiguration, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, useMultiModuleConfiguration, arginfo_phalcon_firewall_adapter_acl_usemultimoduleconfiguration, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, getAccessFromCache, arginfo_phalcon_firewall_adapter_acl_getaccessfromcache, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, handleDispatcher, arginfo_phalcon_firewall_adapter_acl_handledispatcher, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter_Acl, saveAccessInCache, arginfo_phalcon_firewall_adapter_acl_saveaccessincache, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
