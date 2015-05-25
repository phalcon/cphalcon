
extern zend_class_entry *phalcon_acl_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter);

PHP_METHOD(Phalcon_Acl_Adapter, getActiveRole);
PHP_METHOD(Phalcon_Acl_Adapter, getActiveResource);
PHP_METHOD(Phalcon_Acl_Adapter, getActiveAccess);
PHP_METHOD(Phalcon_Acl_Adapter, setEventsManager);
PHP_METHOD(Phalcon_Acl_Adapter, getEventsManager);
PHP_METHOD(Phalcon_Acl_Adapter, setDefaultAction);
PHP_METHOD(Phalcon_Acl_Adapter, getDefaultAction);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAccess)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_adapter_method_entry) {
	PHP_ME(Phalcon_Acl_Adapter, getActiveRole, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, getActiveResource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, getActiveAccess, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, setEventsManager, arginfo_phalcon_acl_adapter_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, setDefaultAction, arginfo_phalcon_acl_adapter_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, getDefaultAction, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
