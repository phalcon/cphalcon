
extern zend_class_entry *phalcon_firewall_adapter_micro_acl_ce;

ZEPHIR_INIT_CLASS(Phalcon_Firewall_Adapter_Micro_Acl);

PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, getAclServiceName);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, setAclServiceName);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, getBoundModelsKeyMap);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, setBoundModelsKeyMap);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, getComponentName);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, setComponentName);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, getRoleCacheCallback);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, setRoleCacheCallback);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, setRouteNameConfiguration);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, __construct);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, afterBinding);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, beforeExecuteRoute);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, getMicro);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, isRouteNameConfiguration);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, fireEventOrThrowException);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, getAccessFromCache);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, handleRouter);
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, saveAccessInCache);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_getaclservicename, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_getaclservicename, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_setaclservicename, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, aclServiceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, aclServiceName)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_setboundmodelskeymap, 0, 0, 1)
	ZEND_ARG_INFO(0, boundModelsKeyMap)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_getcomponentname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_getcomponentname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_setcomponentname, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, componentName)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_setrolecachecallback, 0, 0, 1)
	ZEND_ARG_INFO(0, roleCacheCallback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_setroutenameconfiguration, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routeNameConfiguration, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, routeNameConfiguration)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, aclServiceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, aclServiceName)
#endif
	ZEND_ARG_ARRAY_INFO(0, boundModelsKeyMap, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_afterbinding, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, micro, Phalcon\\Mvc\\Micro, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_beforeexecuteroute, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, micro, Phalcon\\Mvc\\Micro, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_getmicro, 0, 0, Phalcon\\Mvc\\Micro, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_getmicro, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Micro", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_isroutenameconfiguration, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_isroutenameconfiguration, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_fireeventorthrowexception, 0, 0, 4)
	ZEND_ARG_INFO(0, role)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, actionName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, controllerName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, controllerName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, access, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, access)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_getaccessfromcache, 0, 1, _IS_BOOL, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_getaccessfromcache, 0, 1, _IS_BOOL, NULL, 1)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_handlerouter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, micro, Phalcon\\Mvc\\Micro, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_saveaccessincache, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_saveaccessincache, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_micro_acl_saveaccessincache, 0, 0, 2)
#define arginfo_phalcon_firewall_adapter_micro_acl_saveaccessincache NULL
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

ZEPHIR_INIT_FUNCS(phalcon_firewall_adapter_micro_acl_method_entry) {
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, getAclServiceName, arginfo_phalcon_firewall_adapter_micro_acl_getaclservicename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, setAclServiceName, arginfo_phalcon_firewall_adapter_micro_acl_setaclservicename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, getBoundModelsKeyMap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, setBoundModelsKeyMap, arginfo_phalcon_firewall_adapter_micro_acl_setboundmodelskeymap, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, getComponentName, arginfo_phalcon_firewall_adapter_micro_acl_getcomponentname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, setComponentName, arginfo_phalcon_firewall_adapter_micro_acl_setcomponentname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, getRoleCacheCallback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, setRoleCacheCallback, arginfo_phalcon_firewall_adapter_micro_acl_setrolecachecallback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, setRouteNameConfiguration, arginfo_phalcon_firewall_adapter_micro_acl_setroutenameconfiguration, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, __construct, arginfo_phalcon_firewall_adapter_micro_acl___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, afterBinding, arginfo_phalcon_firewall_adapter_micro_acl_afterbinding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, beforeExecuteRoute, arginfo_phalcon_firewall_adapter_micro_acl_beforeexecuteroute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, getMicro, arginfo_phalcon_firewall_adapter_micro_acl_getmicro, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, isRouteNameConfiguration, arginfo_phalcon_firewall_adapter_micro_acl_isroutenameconfiguration, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, fireEventOrThrowException, arginfo_phalcon_firewall_adapter_micro_acl_fireeventorthrowexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, getAccessFromCache, arginfo_phalcon_firewall_adapter_micro_acl_getaccessfromcache, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, handleRouter, arginfo_phalcon_firewall_adapter_micro_acl_handlerouter, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter_Micro_Acl, saveAccessInCache, arginfo_phalcon_firewall_adapter_micro_acl_saveaccessincache, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
