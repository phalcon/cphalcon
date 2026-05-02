
extern zend_class_entry *phalcon_time_clock_frozenclock_ce;

ZEPHIR_INIT_CLASS(Phalcon_Time_Clock_FrozenClock);

PHP_METHOD(Phalcon_Time_Clock_FrozenClock, __construct);
PHP_METHOD(Phalcon_Time_Clock_FrozenClock, adjust);
PHP_METHOD(Phalcon_Time_Clock_FrozenClock, fromSystemTimezone);
PHP_METHOD(Phalcon_Time_Clock_FrozenClock, fromUTC);
PHP_METHOD(Phalcon_Time_Clock_FrozenClock, now);
PHP_METHOD(Phalcon_Time_Clock_FrozenClock, set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_time_clock_frozenclock___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, now, DateTimeImmutable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_time_clock_frozenclock_adjust, 0, 1, Phalcon\\Time\\Clock\\FrozenClock, 0)
	ZEND_ARG_TYPE_INFO(0, modifier, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_time_clock_frozenclock_fromsystemtimezone, 0, 0, Phalcon\\Time\\Clock\\FrozenClock, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_time_clock_frozenclock_fromutc, 0, 0, Phalcon\\Time\\Clock\\FrozenClock, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_time_clock_frozenclock_now, 0, 0, DateTimeImmutable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_time_clock_frozenclock_set, 0, 1, Phalcon\\Time\\Clock\\FrozenClock, 0)
	ZEND_ARG_OBJ_INFO(0, now, DateTimeImmutable, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_time_clock_frozenclock_method_entry) {
	PHP_ME(Phalcon_Time_Clock_FrozenClock, __construct, arginfo_phalcon_time_clock_frozenclock___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Time_Clock_FrozenClock, adjust, arginfo_phalcon_time_clock_frozenclock_adjust, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Time_Clock_FrozenClock, fromSystemTimezone, arginfo_phalcon_time_clock_frozenclock_fromsystemtimezone, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Time_Clock_FrozenClock, fromUTC, arginfo_phalcon_time_clock_frozenclock_fromutc, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Time_Clock_FrozenClock, now, arginfo_phalcon_time_clock_frozenclock_now, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Time_Clock_FrozenClock, set, arginfo_phalcon_time_clock_frozenclock_set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
