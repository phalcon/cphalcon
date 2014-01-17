
extern zend_class_entry *phalcon_logger_multiple_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Multiple);

PHP_METHOD(Phalcon_Logger_Multiple, getLoggers);
PHP_METHOD(Phalcon_Logger_Multiple, getFormatter);
PHP_METHOD(Phalcon_Logger_Multiple, push);
PHP_METHOD(Phalcon_Logger_Multiple, setFormatter);
PHP_METHOD(Phalcon_Logger_Multiple, log);
PHP_METHOD(Phalcon_Logger_Multiple, emergence);
PHP_METHOD(Phalcon_Logger_Multiple, debug);
PHP_METHOD(Phalcon_Logger_Multiple, error);
PHP_METHOD(Phalcon_Logger_Multiple, info);
PHP_METHOD(Phalcon_Logger_Multiple, notice);
PHP_METHOD(Phalcon_Logger_Multiple, warning);
PHP_METHOD(Phalcon_Logger_Multiple, alert);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_push, 0, 0, 1)
	ZEND_ARG_INFO(0, logger)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_setformatter, 0, 0, 1)
	ZEND_ARG_INFO(0, formatter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_log, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_emergence, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_multiple_method_entry) {
	PHP_ME(Phalcon_Logger_Multiple, getLoggers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, getFormatter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, push, arginfo_phalcon_logger_multiple_push, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, setFormatter, arginfo_phalcon_logger_multiple_setformatter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, log, arginfo_phalcon_logger_multiple_log, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, emergence, arginfo_phalcon_logger_multiple_emergence, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, debug, arginfo_phalcon_logger_multiple_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, error, arginfo_phalcon_logger_multiple_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, info, arginfo_phalcon_logger_multiple_info, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, notice, arginfo_phalcon_logger_multiple_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, warning, arginfo_phalcon_logger_multiple_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, alert, arginfo_phalcon_logger_multiple_alert, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
