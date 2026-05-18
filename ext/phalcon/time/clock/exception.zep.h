
extern zend_class_entry *phalcon_time_clock_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Time_Clock_Exception);

PHP_METHOD(Phalcon_Time_Clock_Exception, invalidModifier);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_time_clock_exception_invalidmodifier, 0, 1, Phalcon\\Time\\Clock\\Exception, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, ex, Throwable, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_time_clock_exception_method_entry) {
	PHP_ME(Phalcon_Time_Clock_Exception, invalidModifier, arginfo_phalcon_time_clock_exception_invalidmodifier, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
