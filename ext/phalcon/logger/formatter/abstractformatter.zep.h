
extern zend_class_entry *phalcon_logger_formatter_abstractformatter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_AbstractFormatter);

PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, getDateFormat);
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, setDateFormat);
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, interpolate);
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, getFormattedDate);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_abstractformatter_getdateformat, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_abstractformatter_getdateformat, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_abstractformatter_setdateformat, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dateFormat, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, dateFormat)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_abstractformatter_interpolate, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_abstractformatter_getformatteddate, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_abstractformatter_getformatteddate, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatter_abstractformatter_method_entry) {
	PHP_ME(Phalcon_Logger_Formatter_AbstractFormatter, getDateFormat, arginfo_phalcon_logger_formatter_abstractformatter_getdateformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_AbstractFormatter, setDateFormat, arginfo_phalcon_logger_formatter_abstractformatter_setdateformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_AbstractFormatter, interpolate, arginfo_phalcon_logger_formatter_abstractformatter_interpolate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_AbstractFormatter, getFormattedDate, arginfo_phalcon_logger_formatter_abstractformatter_getformatteddate, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
