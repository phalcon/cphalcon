
extern zend_class_entry *phalcon_time_clock_systemclock_ce;

ZEPHIR_INIT_CLASS(Phalcon_Time_Clock_SystemClock);

PHP_METHOD(Phalcon_Time_Clock_SystemClock, __construct);
PHP_METHOD(Phalcon_Time_Clock_SystemClock, fromSystemTimezone);
PHP_METHOD(Phalcon_Time_Clock_SystemClock, fromUTC);
PHP_METHOD(Phalcon_Time_Clock_SystemClock, now);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_time_clock_systemclock___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, timezone, DateTimeZone, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_time_clock_systemclock_fromsystemtimezone, 0, 0, Phalcon\\Time\\Clock\\SystemClock, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_time_clock_systemclock_fromutc, 0, 0, Phalcon\\Time\\Clock\\SystemClock, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_time_clock_systemclock_now, 0, 0, DateTimeImmutable, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_time_clock_systemclock_method_entry) {
	PHP_ME(Phalcon_Time_Clock_SystemClock, __construct, arginfo_phalcon_time_clock_systemclock___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Time_Clock_SystemClock, fromSystemTimezone, arginfo_phalcon_time_clock_systemclock_fromsystemtimezone, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Time_Clock_SystemClock, fromUTC, arginfo_phalcon_time_clock_systemclock_fromutc, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Time_Clock_SystemClock, now, arginfo_phalcon_time_clock_systemclock_now, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
