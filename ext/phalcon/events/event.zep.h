
extern zend_class_entry *phalcon_events_event_ce;

ZEPHIR_INIT_CLASS(Phalcon_Events_Event);

PHP_METHOD(Phalcon_Events_Event, getData);
PHP_METHOD(Phalcon_Events_Event, getSource);
PHP_METHOD(Phalcon_Events_Event, getType);
PHP_METHOD(Phalcon_Events_Event, __construct);
PHP_METHOD(Phalcon_Events_Event, isCancelable);
PHP_METHOD(Phalcon_Events_Event, isStopped);
PHP_METHOD(Phalcon_Events_Event, setData);
PHP_METHOD(Phalcon_Events_Event, setType);
PHP_METHOD(Phalcon_Events_Event, stop);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_event_getdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_event_getsource, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_event_gettype, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_event_gettype, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_event___construct, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, cancelable, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, cancelable)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_event_iscancelable, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_event_iscancelable, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_event_isstopped, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_event_isstopped, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_events_event_setdata, 0, 0, Phalcon\\Events\\EventInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_event_setdata, 0, 0, IS_OBJECT, "Phalcon\\Events\\EventInterface", 0)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_events_event_settype, 0, 1, Phalcon\\Events\\EventInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_event_settype, 0, 1, IS_OBJECT, "Phalcon\\Events\\EventInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_events_event_stop, 0, 0, Phalcon\\Events\\EventInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_event_stop, 0, 0, IS_OBJECT, "Phalcon\\Events\\EventInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_events_event_method_entry) {
	PHP_ME(Phalcon_Events_Event, getData, arginfo_phalcon_events_event_getdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Event, getSource, arginfo_phalcon_events_event_getsource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Event, getType, arginfo_phalcon_events_event_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Event, __construct, arginfo_phalcon_events_event___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Events_Event, isCancelable, arginfo_phalcon_events_event_iscancelable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Event, isStopped, arginfo_phalcon_events_event_isstopped, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Event, setData, arginfo_phalcon_events_event_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Event, setType, arginfo_phalcon_events_event_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Event, stop, arginfo_phalcon_events_event_stop, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
