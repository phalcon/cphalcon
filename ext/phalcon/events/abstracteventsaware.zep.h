
extern zend_class_entry *phalcon_events_abstracteventsaware_ce;

ZEPHIR_INIT_CLASS(Phalcon_Events_AbstractEventsAware);

PHP_METHOD(Phalcon_Events_AbstractEventsAware, getEventsManager);
PHP_METHOD(Phalcon_Events_AbstractEventsAware, setEventsManager);
PHP_METHOD(Phalcon_Events_AbstractEventsAware, fireManagerEvent);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_events_abstracteventsaware_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_abstracteventsaware_seteventsmanager, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_abstracteventsaware_firemanagerevent, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO(0, cancellable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_events_abstracteventsaware_method_entry) {
	PHP_ME(Phalcon_Events_AbstractEventsAware, getEventsManager, arginfo_phalcon_events_abstracteventsaware_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_AbstractEventsAware, setEventsManager, arginfo_phalcon_events_abstracteventsaware_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_AbstractEventsAware, fireManagerEvent, arginfo_phalcon_events_abstracteventsaware_firemanagerevent, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
