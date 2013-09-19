
extern zend_class_entry *phalcon_events_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Events_Manager);

PHP_METHOD(Phalcon_Events_Manager, fire);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_fire, 0, 0, 0)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, cancelable)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_events_manager_method_entry) {
	PHP_ME(Phalcon_Events_Manager, fire, arginfo_phalcon_events_manager_fire, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
