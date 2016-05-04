
extern zend_class_entry *phalcon_events_eventinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Events_EventInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_eventinterface_setdata, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_eventinterface_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_events_eventinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Events_EventInterface, getData, NULL)
	PHP_ABSTRACT_ME(Phalcon_Events_EventInterface, setData, arginfo_phalcon_events_eventinterface_setdata)
	PHP_ABSTRACT_ME(Phalcon_Events_EventInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Events_EventInterface, setType, arginfo_phalcon_events_eventinterface_settype)
	PHP_ABSTRACT_ME(Phalcon_Events_EventInterface, stop, NULL)
	PHP_ABSTRACT_ME(Phalcon_Events_EventInterface, isStopped, NULL)
	PHP_ABSTRACT_ME(Phalcon_Events_EventInterface, isCancelable, NULL)
	PHP_FE_END
};
