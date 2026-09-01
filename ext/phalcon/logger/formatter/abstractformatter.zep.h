
extern zend_class_entry *phalcon_logger_formatter_abstractformatter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_AbstractFormatter);

PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, getDateFormat);
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, setDateFormat);
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, getFormattedDate);
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, getInterpolatedMessage);
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, toInterpolate);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_abstractformatter_getdateformat, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_abstractformatter_setdateformat, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, format, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_abstractformatter_getformatteddate, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Logger\\Item, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_abstractformatter_getinterpolatedmessage, 0, 2, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Logger\\Item, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_abstractformatter_tointerpolate, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, left, IS_STRING, 0, "'%'")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, right, IS_STRING, 0, "'%'")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatter_abstractformatter_method_entry) {
	PHP_ME(Phalcon_Logger_Formatter_AbstractFormatter, getDateFormat, arginfo_phalcon_logger_formatter_abstractformatter_getdateformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_AbstractFormatter, setDateFormat, arginfo_phalcon_logger_formatter_abstractformatter_setdateformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_AbstractFormatter, getFormattedDate, arginfo_phalcon_logger_formatter_abstractformatter_getformatteddate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger_Formatter_AbstractFormatter, getInterpolatedMessage, arginfo_phalcon_logger_formatter_abstractformatter_getinterpolatedmessage, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger_Formatter_AbstractFormatter, toInterpolate, arginfo_phalcon_logger_formatter_abstractformatter_tointerpolate, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
