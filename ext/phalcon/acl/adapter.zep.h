
extern zend_class_entry *phalcon_acl_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter);

PHP_METHOD(Phalcon_Acl_Adapter, getActiveAccess);
PHP_METHOD(Phalcon_Acl_Adapter, getActiveRole);
PHP_METHOD(Phalcon_Acl_Adapter, getActiveComponent);
PHP_METHOD(Phalcon_Acl_Adapter, getDefaultAction);
PHP_METHOD(Phalcon_Acl_Adapter, getEventsManager);
PHP_METHOD(Phalcon_Acl_Adapter, setDefaultAction);
PHP_METHOD(Phalcon_Acl_Adapter, setEventsManager);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_getactiveaccess, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_getactiveaccess, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_getactiverole, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_getactiverole, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_getactivecomponent, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_getactivecomponent, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_getdefaultaction, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_getdefaultaction, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_acl_adapter_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_geteventsmanager, 0, 0, IS_OBJECT, "Phalcon\\Events\\ManagerInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_setdefaultaction, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultAccess, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, defaultAccess)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_adapter_method_entry) {
	PHP_ME(Phalcon_Acl_Adapter, getActiveAccess, arginfo_phalcon_acl_adapter_getactiveaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, getActiveRole, arginfo_phalcon_acl_adapter_getactiverole, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, getActiveComponent, arginfo_phalcon_acl_adapter_getactivecomponent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, getDefaultAction, arginfo_phalcon_acl_adapter_getdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, getEventsManager, arginfo_phalcon_acl_adapter_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, setDefaultAction, arginfo_phalcon_acl_adapter_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, setEventsManager, arginfo_phalcon_acl_adapter_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
