
extern zend_class_entry *phalcon_events_traits_eventsawaretrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Events_Traits_EventsAwareTrait);

PHP_METHOD(Phalcon_Events_Traits_EventsAwareTrait, getEventsManager);
PHP_METHOD(Phalcon_Events_Traits_EventsAwareTrait, setEventsManager);
PHP_METHOD(Phalcon_Events_Traits_EventsAwareTrait, fireManagerEvent);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_events_traits_eventsawaretrait_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_traits_eventsawaretrait_seteventsmanager, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_traits_eventsawaretrait_firemanagerevent, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cancellable, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_events_traits_eventsawaretrait_method_entry) {
	PHP_ME(Phalcon_Events_Traits_EventsAwareTrait, getEventsManager, arginfo_phalcon_events_traits_eventsawaretrait_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Traits_EventsAwareTrait, setEventsManager, arginfo_phalcon_events_traits_eventsawaretrait_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Traits_EventsAwareTrait, fireManagerEvent, arginfo_phalcon_events_traits_eventsawaretrait_firemanagerevent, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
