
extern zend_class_entry *phalcon_events_exceptions_invalideventtype_ce;

ZEPHIR_INIT_CLASS(Phalcon_Events_Exceptions_InvalidEventType);

PHP_METHOD(Phalcon_Events_Exceptions_InvalidEventType, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_exceptions_invalideventtype___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, eventType, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_events_exceptions_invalideventtype_method_entry) {
	PHP_ME(Phalcon_Events_Exceptions_InvalidEventType, __construct, arginfo_phalcon_events_exceptions_invalideventtype___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
