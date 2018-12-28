
extern zend_class_entry *phalcon_logger_formatter_syslog_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Syslog);

PHP_METHOD(Phalcon_Logger_Formatter_Syslog, format);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_syslog_format, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_syslog_format, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Logger\\Item, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatter_syslog_method_entry) {
	PHP_ME(Phalcon_Logger_Formatter_Syslog, format, arginfo_phalcon_logger_formatter_syslog_format, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
