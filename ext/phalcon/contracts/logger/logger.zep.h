
extern zend_class_entry *phalcon_contracts_logger_logger_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Logger_Logger);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_logger_alert, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_logger_critical, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_logger_debug, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_logger_emergency, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_logger_error, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_logger_logger_getadapter, 0, 1, Phalcon\\Contracts\\Logger\\Adapter\\Adapter, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_logger_getadapters, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_logger_getloglevel, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_logger_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_logger_info, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_logger_log, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, level)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_logger_notice, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_logger_trace, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_logger_warning, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_logger_logger_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Logger, alert, arginfo_phalcon_contracts_logger_logger_alert)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Logger, critical, arginfo_phalcon_contracts_logger_logger_critical)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Logger, debug, arginfo_phalcon_contracts_logger_logger_debug)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Logger, emergency, arginfo_phalcon_contracts_logger_logger_emergency)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Logger, error, arginfo_phalcon_contracts_logger_logger_error)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Logger, getAdapter, arginfo_phalcon_contracts_logger_logger_getadapter)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Logger, getAdapters, arginfo_phalcon_contracts_logger_logger_getadapters)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Logger, getLogLevel, arginfo_phalcon_contracts_logger_logger_getloglevel)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Logger, getName, arginfo_phalcon_contracts_logger_logger_getname)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Logger, info, arginfo_phalcon_contracts_logger_logger_info)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Logger, log, arginfo_phalcon_contracts_logger_logger_log)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Logger, notice, arginfo_phalcon_contracts_logger_logger_notice)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Logger, trace, arginfo_phalcon_contracts_logger_logger_trace)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Logger, warning, arginfo_phalcon_contracts_logger_logger_warning)
	PHP_FE_END
};
