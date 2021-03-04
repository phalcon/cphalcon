
extern zend_class_entry *phalcon_events_eventsawareinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Events_EventsAwareInterface);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_events_eventsawareinterface_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_eventsawareinterface_seteventsmanager, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_events_eventsawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Events_EventsAwareInterface, getEventsManager, arginfo_phalcon_events_eventsawareinterface_geteventsmanager)
	PHP_ABSTRACT_ME(Phalcon_Events_EventsAwareInterface, setEventsManager, arginfo_phalcon_events_eventsawareinterface_seteventsmanager)
	PHP_FE_END
};
