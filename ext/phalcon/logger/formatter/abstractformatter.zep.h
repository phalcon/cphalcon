
extern zend_class_entry *phalcon_logger_formatter_abstractformatter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_AbstractFormatter);

PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, interpolate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_abstractformatter_interpolate, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatter_abstractformatter_method_entry) {
	PHP_ME(Phalcon_Logger_Formatter_AbstractFormatter, interpolate, arginfo_phalcon_logger_formatter_abstractformatter_interpolate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
