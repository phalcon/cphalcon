
extern zend_class_entry *phalcon_time_clock_clockinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Time_Clock_ClockInterface);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_time_clock_clockinterface_now, 0, 0, DateTimeImmutable, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_time_clock_clockinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Time_Clock_ClockInterface, now, arginfo_phalcon_time_clock_clockinterface_now)
	PHP_FE_END
};
