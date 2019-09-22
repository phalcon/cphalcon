
extern zend_class_entry *phalcon_firewall_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Firewall_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, getActiveIdentity);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, getActiveRole);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, getDefaultAccess);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, getEventsManager);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, getRoleCallback);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, isAlwaysResolvingRole);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, setCache);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, setDefaultAccess);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, setEventsManager);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, setRoleCallback);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, setAlwaysResolvingRole);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, callRoleCallback);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, getAccessFromCache);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, handleException);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, fireEventOrThrowException);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, saveAccessInCache);
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, throwFirewallException);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_getdefaultaccess, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_getdefaultaccess, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_geteventsmanager, 0, 0, IS_OBJECT, "Phalcon\\Events\\ManagerInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_getrolecallback, 0, 0, Closure, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_getrolecallback, 0, 0, IS_OBJECT, "Closure", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_isalwaysresolvingrole, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_isalwaysresolvingrole, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_setcache, 0, 1, Phalcon\\Firewall\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_setcache, 0, 1, IS_OBJECT, "Phalcon\\Firewall\\Adapter\\AdapterInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, cache, Phalcon\\Cache\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_setdefaultaccess, 0, 1, Phalcon\\Firewall\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_setdefaultaccess, 0, 1, IS_OBJECT, "Phalcon\\Firewall\\Adapter\\AdapterInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultAccess, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, defaultAccess)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_seteventsmanager, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_seteventsmanager, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_seteventsmanager, 0, 0, 1)
#define arginfo_phalcon_firewall_adapter_abstractadapter_seteventsmanager NULL
#endif

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_setrolecallback, 0, 1, Phalcon\\Firewall\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_setrolecallback, 0, 1, IS_OBJECT, "Phalcon\\Firewall\\Adapter\\AdapterInterface", 0)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_setalwaysresolvingrole, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_setalwaysresolvingrole, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_setalwaysresolvingrole, 0, 0, 1)
#define arginfo_phalcon_firewall_adapter_abstractadapter_setalwaysresolvingrole NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, alwaysResolvingRole, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, alwaysResolvingRole)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_callrolecallback, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_callrolecallback, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_callrolecallback, 0, 0, 1)
#define arginfo_phalcon_firewall_adapter_abstractadapter_callrolecallback NULL
#endif

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_getaccessfromcache, 0, 1, _IS_BOOL, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_getaccessfromcache, 0, 1, _IS_BOOL, NULL, 1)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_handleexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, exception, Exception, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_fireeventorthrowexception, 0, 0, 4)
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

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_saveaccessincache, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_saveaccessincache, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_saveaccessincache, 0, 0, 2)
#define arginfo_phalcon_firewall_adapter_abstractadapter_saveaccessincache NULL
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

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_throwfirewallexception, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_abstractadapter_throwfirewallexception, 0, 1, _IS_BOOL, NULL, 0)
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

ZEPHIR_INIT_FUNCS(phalcon_firewall_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, getActiveIdentity, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, getActiveRole, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, getDefaultAccess, arginfo_phalcon_firewall_adapter_abstractadapter_getdefaultaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, getEventsManager, arginfo_phalcon_firewall_adapter_abstractadapter_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, getRoleCallback, arginfo_phalcon_firewall_adapter_abstractadapter_getrolecallback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, isAlwaysResolvingRole, arginfo_phalcon_firewall_adapter_abstractadapter_isalwaysresolvingrole, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, setCache, arginfo_phalcon_firewall_adapter_abstractadapter_setcache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, setDefaultAccess, arginfo_phalcon_firewall_adapter_abstractadapter_setdefaultaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, setEventsManager, arginfo_phalcon_firewall_adapter_abstractadapter_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, setRoleCallback, arginfo_phalcon_firewall_adapter_abstractadapter_setrolecallback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, setAlwaysResolvingRole, arginfo_phalcon_firewall_adapter_abstractadapter_setalwaysresolvingrole, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, callRoleCallback, arginfo_phalcon_firewall_adapter_abstractadapter_callrolecallback, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, getAccessFromCache, arginfo_phalcon_firewall_adapter_abstractadapter_getaccessfromcache, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, handleException, arginfo_phalcon_firewall_adapter_abstractadapter_handleexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, fireEventOrThrowException, arginfo_phalcon_firewall_adapter_abstractadapter_fireeventorthrowexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, saveAccessInCache, arginfo_phalcon_firewall_adapter_abstractadapter_saveaccessincache, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter_AbstractAdapter, throwFirewallException, arginfo_phalcon_firewall_adapter_abstractadapter_throwfirewallexception, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
