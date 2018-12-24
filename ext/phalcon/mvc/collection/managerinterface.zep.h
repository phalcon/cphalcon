
extern zend_class_entry *phalcon_mvc_collection_managerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_setcustomeventsmanager, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_getcustomeventsmanager, 0, 1, Phalcon\\Events\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_getcustomeventsmanager, 0, 1, IS_OBJECT, "Phalcon\\Events\\ManagerInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_initialize, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_isinitialized, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_isinitialized, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, modelName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_getlastinitialized, 0, 0, Phalcon\\Mvc\\CollectionInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_getlastinitialized, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\CollectionInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_setconnectionservice, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, connectionService, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, connectionService)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_useimplicitobjectids, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, useImplicitObjectIds, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, useImplicitObjectIds)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_isusingimplicitobjectids, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_isusingimplicitobjectids, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_getconnection, 0, 1, Phalcon\\Db\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_getconnection, 0, 1, IS_OBJECT, "Phalcon\\Db\\AdapterInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_notifyevent, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, eventName)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_addbehavior, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, behavior, Phalcon\\Mvc\\Collection\\BehaviorInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_managerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, setCustomEventsManager, arginfo_phalcon_mvc_collection_managerinterface_setcustomeventsmanager)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, getCustomEventsManager, arginfo_phalcon_mvc_collection_managerinterface_getcustomeventsmanager)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, initialize, arginfo_phalcon_mvc_collection_managerinterface_initialize)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, isInitialized, arginfo_phalcon_mvc_collection_managerinterface_isinitialized)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, getLastInitialized, arginfo_phalcon_mvc_collection_managerinterface_getlastinitialized)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, setConnectionService, arginfo_phalcon_mvc_collection_managerinterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, useImplicitObjectIds, arginfo_phalcon_mvc_collection_managerinterface_useimplicitobjectids)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, isUsingImplicitObjectIds, arginfo_phalcon_mvc_collection_managerinterface_isusingimplicitobjectids)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, getConnection, arginfo_phalcon_mvc_collection_managerinterface_getconnection)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, notifyEvent, arginfo_phalcon_mvc_collection_managerinterface_notifyevent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, addBehavior, arginfo_phalcon_mvc_collection_managerinterface_addbehavior)
	PHP_FE_END
};
