
extern zend_class_entry *phalcon_acl_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Acl_Adapter_AbstractAdapter, getActiveAccess);
PHP_METHOD(Phalcon_Acl_Adapter_AbstractAdapter, getActiveRole);
PHP_METHOD(Phalcon_Acl_Adapter_AbstractAdapter, getActiveComponent);
PHP_METHOD(Phalcon_Acl_Adapter_AbstractAdapter, getDefaultAction);
PHP_METHOD(Phalcon_Acl_Adapter_AbstractAdapter, getEventsManager);
PHP_METHOD(Phalcon_Acl_Adapter_AbstractAdapter, setDefaultAction);
PHP_METHOD(Phalcon_Acl_Adapter_AbstractAdapter, setEventsManager);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_getactiveaccess, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_getactiveaccess, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_getactiverole, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_getactiverole, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_getactivecomponent, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_getactivecomponent, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_getdefaultaction, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_getdefaultaction, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_geteventsmanager, 0, 0, IS_OBJECT, "Phalcon\\Events\\ManagerInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_setdefaultaction, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_setdefaultaction, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_setdefaultaction, 0, 0, 1)
#define arginfo_phalcon_acl_adapter_abstractadapter_setdefaultaction NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultAccess, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, defaultAccess)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_seteventsmanager, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_seteventsmanager, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_abstractadapter_seteventsmanager, 0, 0, 1)
#define arginfo_phalcon_acl_adapter_abstractadapter_seteventsmanager NULL
#endif

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Acl_Adapter_AbstractAdapter, getActiveAccess, arginfo_phalcon_acl_adapter_abstractadapter_getactiveaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_AbstractAdapter, getActiveRole, arginfo_phalcon_acl_adapter_abstractadapter_getactiverole, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_AbstractAdapter, getActiveComponent, arginfo_phalcon_acl_adapter_abstractadapter_getactivecomponent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_AbstractAdapter, getDefaultAction, arginfo_phalcon_acl_adapter_abstractadapter_getdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_AbstractAdapter, getEventsManager, arginfo_phalcon_acl_adapter_abstractadapter_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_AbstractAdapter, setDefaultAction, arginfo_phalcon_acl_adapter_abstractadapter_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_AbstractAdapter, setEventsManager, arginfo_phalcon_acl_adapter_abstractadapter_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
