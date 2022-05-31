
extern zend_class_entry *phalcon_logger_logger_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Logger);

PHP_METHOD(Phalcon_Logger_Logger, alert);
PHP_METHOD(Phalcon_Logger_Logger, critical);
PHP_METHOD(Phalcon_Logger_Logger, debug);
PHP_METHOD(Phalcon_Logger_Logger, emergency);
PHP_METHOD(Phalcon_Logger_Logger, error);
PHP_METHOD(Phalcon_Logger_Logger, info);
PHP_METHOD(Phalcon_Logger_Logger, log);
PHP_METHOD(Phalcon_Logger_Logger, notice);
PHP_METHOD(Phalcon_Logger_Logger, warning);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_alert, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_critical, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_debug, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_emergency, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_error, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_info, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_log, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, level)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_notice, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_warning, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_logger_method_entry) {
	PHP_ME(Phalcon_Logger_Logger, alert, arginfo_phalcon_logger_logger_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, critical, arginfo_phalcon_logger_logger_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, debug, arginfo_phalcon_logger_logger_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, emergency, arginfo_phalcon_logger_logger_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, error, arginfo_phalcon_logger_logger_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, info, arginfo_phalcon_logger_logger_info, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, log, arginfo_phalcon_logger_logger_log, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, notice, arginfo_phalcon_logger_logger_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, warning, arginfo_phalcon_logger_logger_warning, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
