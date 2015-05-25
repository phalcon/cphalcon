
extern zend_class_entry *phalcon_logger_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_setformatter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, formatter, Phalcon\\Logger\\FormatterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_setloglevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_log, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, setFormatter, arginfo_phalcon_logger_adapterinterface_setformatter)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, getFormatter, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, setLogLevel, arginfo_phalcon_logger_adapterinterface_setloglevel)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, getLogLevel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, log, arginfo_phalcon_logger_adapterinterface_log)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, begin, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, rollback, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, close, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, debug, arginfo_phalcon_logger_adapterinterface_debug)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, error, arginfo_phalcon_logger_adapterinterface_error)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, info, arginfo_phalcon_logger_adapterinterface_info)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, notice, arginfo_phalcon_logger_adapterinterface_notice)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, warning, arginfo_phalcon_logger_adapterinterface_warning)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, alert, arginfo_phalcon_logger_adapterinterface_alert)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, emergency, arginfo_phalcon_logger_adapterinterface_emergency)
	PHP_FE_END
};
