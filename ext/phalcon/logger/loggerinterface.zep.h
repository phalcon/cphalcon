
extern zend_class_entry *phalcon_logger_loggerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_LoggerInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_loggerinterface_alert, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_loggerinterface_critical, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_loggerinterface_debug, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_loggerinterface_emergency, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_loggerinterface_error, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_loggerinterface_getadapter, 0, 1, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_loggerinterface_getadapters, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_loggerinterface_getloglevel, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_loggerinterface_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_loggerinterface_info, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_loggerinterface_log, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, level)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_loggerinterface_notice, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_loggerinterface_warning, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_loggerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Logger_LoggerInterface, alert, arginfo_phalcon_logger_loggerinterface_alert)
	PHP_ABSTRACT_ME(Phalcon_Logger_LoggerInterface, critical, arginfo_phalcon_logger_loggerinterface_critical)
	PHP_ABSTRACT_ME(Phalcon_Logger_LoggerInterface, debug, arginfo_phalcon_logger_loggerinterface_debug)
	PHP_ABSTRACT_ME(Phalcon_Logger_LoggerInterface, emergency, arginfo_phalcon_logger_loggerinterface_emergency)
	PHP_ABSTRACT_ME(Phalcon_Logger_LoggerInterface, error, arginfo_phalcon_logger_loggerinterface_error)
	PHP_ABSTRACT_ME(Phalcon_Logger_LoggerInterface, getAdapter, arginfo_phalcon_logger_loggerinterface_getadapter)
	PHP_ABSTRACT_ME(Phalcon_Logger_LoggerInterface, getAdapters, arginfo_phalcon_logger_loggerinterface_getadapters)
	PHP_ABSTRACT_ME(Phalcon_Logger_LoggerInterface, getLogLevel, arginfo_phalcon_logger_loggerinterface_getloglevel)
	PHP_ABSTRACT_ME(Phalcon_Logger_LoggerInterface, getName, arginfo_phalcon_logger_loggerinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Logger_LoggerInterface, info, arginfo_phalcon_logger_loggerinterface_info)
	PHP_ABSTRACT_ME(Phalcon_Logger_LoggerInterface, log, arginfo_phalcon_logger_loggerinterface_log)
	PHP_ABSTRACT_ME(Phalcon_Logger_LoggerInterface, notice, arginfo_phalcon_logger_loggerinterface_notice)
	PHP_ABSTRACT_ME(Phalcon_Logger_LoggerInterface, warning, arginfo_phalcon_logger_loggerinterface_warning)
	PHP_FE_END
};
