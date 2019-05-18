
extern zend_class_entry *phalcon_firewall_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Firewall_Adapter);

PHP_METHOD(Phalcon_Firewall_Adapter, getActiveIdentity);
PHP_METHOD(Phalcon_Firewall_Adapter, getActiveRole);
PHP_METHOD(Phalcon_Firewall_Adapter, setAlwaysResolvingRole);
PHP_METHOD(Phalcon_Firewall_Adapter, getDefaultAccess);
PHP_METHOD(Phalcon_Firewall_Adapter, getEventsManager);
PHP_METHOD(Phalcon_Firewall_Adapter, getRoleCallback);
PHP_METHOD(Phalcon_Firewall_Adapter, isAlwaysResolvingRole);
PHP_METHOD(Phalcon_Firewall_Adapter, setCache);
PHP_METHOD(Phalcon_Firewall_Adapter, setDefaultAccess);
PHP_METHOD(Phalcon_Firewall_Adapter, setEventsManager);
PHP_METHOD(Phalcon_Firewall_Adapter, setRoleCallback);
PHP_METHOD(Phalcon_Firewall_Adapter, callRoleCallback);
PHP_METHOD(Phalcon_Firewall_Adapter, getAccessFromCache);
PHP_METHOD(Phalcon_Firewall_Adapter, handleException);
PHP_METHOD(Phalcon_Firewall_Adapter, fireEventOrThrowException);
PHP_METHOD(Phalcon_Firewall_Adapter, saveAccessInCache);
PHP_METHOD(Phalcon_Firewall_Adapter, throwFirewallException);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_setalwaysresolvingrole, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, alwaysResolvingRole, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, alwaysResolvingRole)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_getdefaultaccess, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_getdefaultaccess, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_firewall_adapter_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_geteventsmanager, 0, 0, IS_OBJECT, "Phalcon\\Events\\ManagerInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_firewall_adapter_getrolecallback, 0, 0, Closure, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_getrolecallback, 0, 0, IS_OBJECT, "Closure", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_isalwaysresolvingrole, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_isalwaysresolvingrole, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_firewall_adapter_setcache, 0, 1, Phalcon\\Firewall\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_setcache, 0, 1, IS_OBJECT, "Phalcon\\Firewall\\AdapterInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, cache, Phalcon\\Cache\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_firewall_adapter_setdefaultaccess, 0, 1, Phalcon\\Firewall\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_setdefaultaccess, 0, 1, IS_OBJECT, "Phalcon\\Firewall\\AdapterInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultAccess, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, defaultAccess)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_firewall_adapter_seteventsmanager, 0, 1, Phalcon\\Firewall\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_seteventsmanager, 0, 1, IS_OBJECT, "Phalcon\\Firewall\\AdapterInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_firewall_adapter_setrolecallback, 0, 1, Phalcon\\Firewall\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_setrolecallback, 0, 1, IS_OBJECT, "Phalcon\\Firewall\\AdapterInterface", 0)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_callrolecallback, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_getaccessfromcache, 0, 1, _IS_BOOL, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_getaccessfromcache, 0, 1, _IS_BOOL, NULL, 1)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_handleexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, exception, Exception, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_fireeventorthrowexception, 0, 0, 4)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_saveaccessincache, 0, 0, 2)
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

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_throwfirewallexception, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_throwfirewallexception, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, exceptionCode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, exceptionCode)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_firewall_adapter_method_entry) {
	PHP_ME(Phalcon_Firewall_Adapter, getActiveIdentity, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter, getActiveRole, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter, setAlwaysResolvingRole, arginfo_phalcon_firewall_adapter_setalwaysresolvingrole, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter, getDefaultAccess, arginfo_phalcon_firewall_adapter_getdefaultaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter, getEventsManager, arginfo_phalcon_firewall_adapter_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter, getRoleCallback, arginfo_phalcon_firewall_adapter_getrolecallback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter, isAlwaysResolvingRole, arginfo_phalcon_firewall_adapter_isalwaysresolvingrole, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter, setCache, arginfo_phalcon_firewall_adapter_setcache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter, setDefaultAccess, arginfo_phalcon_firewall_adapter_setdefaultaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter, setEventsManager, arginfo_phalcon_firewall_adapter_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter, setRoleCallback, arginfo_phalcon_firewall_adapter_setrolecallback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter, callRoleCallback, arginfo_phalcon_firewall_adapter_callrolecallback, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter, getAccessFromCache, arginfo_phalcon_firewall_adapter_getaccessfromcache, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter, handleException, arginfo_phalcon_firewall_adapter_handleexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter, fireEventOrThrowException, arginfo_phalcon_firewall_adapter_fireeventorthrowexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter, saveAccessInCache, arginfo_phalcon_firewall_adapter_saveaccessincache, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter, throwFirewallException, arginfo_phalcon_firewall_adapter_throwfirewallexception, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
