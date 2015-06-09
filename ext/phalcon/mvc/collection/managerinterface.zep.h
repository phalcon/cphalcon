
extern zend_class_entry *phalcon_mvc_collection_managerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_setcustomeventsmanager, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_getcustomeventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_initialize, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_isinitialized, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_setconnectionservice, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_useimplicitobjectids, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, useImplicitObjectIds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_isusingimplicitobjectids, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_getconnection, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_notifyevent, 0, 0, 2)
	ZEND_ARG_INFO(0, eventName)
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
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, getLastInitialized, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, setConnectionService, arginfo_phalcon_mvc_collection_managerinterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, useImplicitObjectIds, arginfo_phalcon_mvc_collection_managerinterface_useimplicitobjectids)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, isUsingImplicitObjectIds, arginfo_phalcon_mvc_collection_managerinterface_isusingimplicitobjectids)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, getConnection, arginfo_phalcon_mvc_collection_managerinterface_getconnection)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, notifyEvent, arginfo_phalcon_mvc_collection_managerinterface_notifyevent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, addBehavior, arginfo_phalcon_mvc_collection_managerinterface_addbehavior)
	PHP_FE_END
};
