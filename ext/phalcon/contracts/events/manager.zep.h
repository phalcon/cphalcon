
extern zend_class_entry *phalcon_contracts_events_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Events_Manager);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_addsubscriber, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, subscriber, Phalcon\\Contracts\\Events\\Subscriber, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_areprioritiesenabled, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_attach, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, eventType, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, priority, IS_LONG, 0, "100")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_clearsubscribers, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_collectresponses, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, collect, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_detach, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, eventType, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_detachall, 0, 0, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, type, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_enablepriorities, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, enablePriorities, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_events_manager_fire, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, eventType, IS_STRING, 0)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cancelable, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_getlisteners, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_getresponses, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_getsubscribers, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_haslisteners, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_iscollecting, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_isvalidhandler, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_manager_removesubscriber, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, subscriber, Phalcon\\Contracts\\Events\\Subscriber, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_events_manager_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, addSubscriber, arginfo_phalcon_contracts_events_manager_addsubscriber)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, arePrioritiesEnabled, arginfo_phalcon_contracts_events_manager_areprioritiesenabled)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, attach, arginfo_phalcon_contracts_events_manager_attach)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, clearSubscribers, arginfo_phalcon_contracts_events_manager_clearsubscribers)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, collectResponses, arginfo_phalcon_contracts_events_manager_collectresponses)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, detach, arginfo_phalcon_contracts_events_manager_detach)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, detachAll, arginfo_phalcon_contracts_events_manager_detachall)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, enablePriorities, arginfo_phalcon_contracts_events_manager_enablepriorities)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, fire, arginfo_phalcon_contracts_events_manager_fire)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, getListeners, arginfo_phalcon_contracts_events_manager_getlisteners)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, getResponses, arginfo_phalcon_contracts_events_manager_getresponses)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, getSubscribers, arginfo_phalcon_contracts_events_manager_getsubscribers)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, hasListeners, arginfo_phalcon_contracts_events_manager_haslisteners)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, isCollecting, arginfo_phalcon_contracts_events_manager_iscollecting)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, isValidHandler, arginfo_phalcon_contracts_events_manager_isvalidhandler)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Manager, removeSubscriber, arginfo_phalcon_contracts_events_manager_removesubscriber)
	PHP_FE_END
};
