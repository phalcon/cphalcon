
extern zend_class_entry *phalcon_logger_adapter_syslog_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Syslog);

PHP_METHOD(Phalcon_Logger_Adapter_Syslog, __construct);
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, close);
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, process);
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, logLevelToSyslog);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_syslog___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_syslog_close, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_syslog_process, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Logger\\Item, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_syslog_logleveltosyslog, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapter_syslog_method_entry) {
	PHP_ME(Phalcon_Logger_Adapter_Syslog, __construct, arginfo_phalcon_logger_adapter_syslog___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_Adapter_Syslog, close, arginfo_phalcon_logger_adapter_syslog_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Syslog, process, arginfo_phalcon_logger_adapter_syslog_process, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Syslog, logLevelToSyslog, arginfo_phalcon_logger_adapter_syslog_logleveltosyslog, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
