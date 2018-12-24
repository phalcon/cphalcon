
extern zend_class_entry *phalcon_mvc_collection_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Manager);

PHP_METHOD(Phalcon_Mvc_Collection_Manager, getServiceName);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setServiceName);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setDI);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getDI);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setCustomEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getCustomEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, initialize);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isInitialized);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getLastInitialized);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setConnectionService);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getConnectionService);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, useImplicitObjectIds);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isUsingImplicitObjectIds);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getConnection);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, notifyEvent);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, missingMethod);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, addBehavior);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_setservicename, 0, 0, 1)
	ZEND_ARG_INFO(0, serviceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_collection_manager_getdi, 0, 0, Phalcon\\DiInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_manager_getdi, 0, 0, IS_OBJECT, "Phalcon\\DiInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_collection_manager_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_manager_geteventsmanager, 0, 0, IS_OBJECT, "Phalcon\\Events\\ManagerInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_setcustomeventsmanager, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_getcustomeventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_initialize, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_manager_isinitialized, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_manager_isinitialized, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, modelName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_collection_manager_getlastinitialized, 0, 0, Phalcon\\Mvc\\CollectionInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_manager_getlastinitialized, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\CollectionInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_setconnectionservice, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, connectionService, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, connectionService)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_manager_getconnectionservice, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_manager_getconnectionservice, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_useimplicitobjectids, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, useImplicitObjectIds, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, useImplicitObjectIds)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_manager_isusingimplicitobjectids, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_manager_isusingimplicitobjectids, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_getconnection, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_notifyevent, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, eventName)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_manager_missingmethod, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_manager_missingmethod, 0, 3, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, eventName)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_addbehavior, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, behavior, Phalcon\\Mvc\\Collection\\BehaviorInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_manager_method_entry) {
	PHP_ME(Phalcon_Mvc_Collection_Manager, getServiceName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, setServiceName, arginfo_phalcon_mvc_collection_manager_setservicename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, setDI, arginfo_phalcon_mvc_collection_manager_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getDI, arginfo_phalcon_mvc_collection_manager_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, setEventsManager, arginfo_phalcon_mvc_collection_manager_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getEventsManager, arginfo_phalcon_mvc_collection_manager_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, setCustomEventsManager, arginfo_phalcon_mvc_collection_manager_setcustomeventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getCustomEventsManager, arginfo_phalcon_mvc_collection_manager_getcustomeventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, initialize, arginfo_phalcon_mvc_collection_manager_initialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, isInitialized, arginfo_phalcon_mvc_collection_manager_isinitialized, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getLastInitialized, arginfo_phalcon_mvc_collection_manager_getlastinitialized, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, setConnectionService, arginfo_phalcon_mvc_collection_manager_setconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getConnectionService, arginfo_phalcon_mvc_collection_manager_getconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, useImplicitObjectIds, arginfo_phalcon_mvc_collection_manager_useimplicitobjectids, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, isUsingImplicitObjectIds, arginfo_phalcon_mvc_collection_manager_isusingimplicitobjectids, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getConnection, arginfo_phalcon_mvc_collection_manager_getconnection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, notifyEvent, arginfo_phalcon_mvc_collection_manager_notifyevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, missingMethod, arginfo_phalcon_mvc_collection_manager_missingmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, addBehavior, arginfo_phalcon_mvc_collection_manager_addbehavior, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
