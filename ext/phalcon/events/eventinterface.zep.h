
extern zend_class_entry *phalcon_events_eventinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Events_EventInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_eventinterface_getdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_eventinterface_gettype, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_eventinterface_iscancelable, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_eventinterface_isstopped, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_events_eventinterface_setdata, 0, 0, Phalcon\\Events\\EventInterface, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_events_eventinterface_settype, 0, 1, Phalcon\\Events\\EventInterface, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_events_eventinterface_stop, 0, 0, Phalcon\\Events\\EventInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_events_eventinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Events_EventInterface, getData, arginfo_phalcon_events_eventinterface_getdata)
	PHP_ABSTRACT_ME(Phalcon_Events_EventInterface, getType, arginfo_phalcon_events_eventinterface_gettype)
	PHP_ABSTRACT_ME(Phalcon_Events_EventInterface, isCancelable, arginfo_phalcon_events_eventinterface_iscancelable)
	PHP_ABSTRACT_ME(Phalcon_Events_EventInterface, isStopped, arginfo_phalcon_events_eventinterface_isstopped)
	PHP_ABSTRACT_ME(Phalcon_Events_EventInterface, setData, arginfo_phalcon_events_eventinterface_setdata)
	PHP_ABSTRACT_ME(Phalcon_Events_EventInterface, setType, arginfo_phalcon_events_eventinterface_settype)
	PHP_ABSTRACT_ME(Phalcon_Events_EventInterface, stop, arginfo_phalcon_events_eventinterface_stop)
	PHP_FE_END
};
