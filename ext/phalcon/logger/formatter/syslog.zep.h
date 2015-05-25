
extern zend_class_entry *phalcon_logger_formatter_syslog_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Syslog);

PHP_METHOD(Phalcon_Logger_Formatter_Syslog, format);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_syslog_format, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatter_syslog_method_entry) {
	PHP_ME(Phalcon_Logger_Formatter_Syslog, format, arginfo_phalcon_logger_formatter_syslog_format, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
