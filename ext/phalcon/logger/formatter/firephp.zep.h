
extern zend_class_entry *phalcon_logger_formatter_firephp_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Firephp);

PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getTypeString);
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, setShowBacktrace);
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getShowBacktrace);
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, enableLabels);
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, labelsEnabled);
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, format);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_firephp_gettypestring, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_firephp_setshowbacktrace, 0, 0, 0)
	ZEND_ARG_INFO(0, isShow)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_firephp_enablelabels, 0, 0, 0)
	ZEND_ARG_INFO(0, isEnable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_firephp_format, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatter_firephp_method_entry) {
	PHP_ME(Phalcon_Logger_Formatter_Firephp, getTypeString, arginfo_phalcon_logger_formatter_firephp_gettypestring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, setShowBacktrace, arginfo_phalcon_logger_formatter_firephp_setshowbacktrace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, getShowBacktrace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, enableLabels, arginfo_phalcon_logger_formatter_firephp_enablelabels, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, labelsEnabled, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, format, arginfo_phalcon_logger_formatter_firephp_format, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
