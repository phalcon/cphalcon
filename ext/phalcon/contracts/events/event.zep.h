
extern zend_class_entry *phalcon_contracts_events_event_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Events_Event);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_events_event_getdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_events_event_gettype, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_event_iscancelable, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_events_event_isstopped, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_events_event_setdata, 0, 0, Phalcon\\Contracts\\Events\\Event, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_events_event_settype, 0, 1, Phalcon\\Contracts\\Events\\Event, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_events_event_stop, 0, 0, Phalcon\\Contracts\\Events\\Event, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_events_event_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Event, getData, arginfo_phalcon_contracts_events_event_getdata)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Event, getType, arginfo_phalcon_contracts_events_event_gettype)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Event, isCancelable, arginfo_phalcon_contracts_events_event_iscancelable)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Event, isStopped, arginfo_phalcon_contracts_events_event_isstopped)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Event, setData, arginfo_phalcon_contracts_events_event_setdata)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Event, setType, arginfo_phalcon_contracts_events_event_settype)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Events_Event, stop, arginfo_phalcon_contracts_events_event_stop)
	PHP_FE_END
};
