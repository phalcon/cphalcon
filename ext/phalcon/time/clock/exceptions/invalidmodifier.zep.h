
extern zend_class_entry *phalcon_time_clock_exceptions_invalidmodifier_ce;

ZEPHIR_INIT_CLASS(Phalcon_Time_Clock_Exceptions_InvalidModifier);

PHP_METHOD(Phalcon_Time_Clock_Exceptions_InvalidModifier, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_time_clock_exceptions_invalidmodifier___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, modifier, IS_STRING, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, ex, Throwable, MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_time_clock_exceptions_invalidmodifier_method_entry) {
	PHP_ME(Phalcon_Time_Clock_Exceptions_InvalidModifier, __construct, arginfo_phalcon_time_clock_exceptions_invalidmodifier___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
