
extern zend_class_entry *phalcon_adr_events_event_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Events_Event);

PHP_METHOD(Phalcon_ADR_Events_Event, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_events_event___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_events_event_method_entry) {
PHP_ME(Phalcon_ADR_Events_Event, __construct, arginfo_phalcon_adr_events_event___construct, ZEND_ACC_FINAL|ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_FE_END
};
