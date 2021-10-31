
extern zend_class_entry *phalcon_logger_logger_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Logger);

PHP_METHOD(Phalcon_Logger_Logger, getAdapters);
PHP_METHOD(Phalcon_Logger_Logger, getLogLevel);
PHP_METHOD(Phalcon_Logger_Logger, getName);
PHP_METHOD(Phalcon_Logger_Logger, __construct);
PHP_METHOD(Phalcon_Logger_Logger, addAdapter);
PHP_METHOD(Phalcon_Logger_Logger, alert);
PHP_METHOD(Phalcon_Logger_Logger, critical);
PHP_METHOD(Phalcon_Logger_Logger, debug);
PHP_METHOD(Phalcon_Logger_Logger, error);
PHP_METHOD(Phalcon_Logger_Logger, emergency);
PHP_METHOD(Phalcon_Logger_Logger, excludeAdapters);
PHP_METHOD(Phalcon_Logger_Logger, getAdapter);
PHP_METHOD(Phalcon_Logger_Logger, info);
PHP_METHOD(Phalcon_Logger_Logger, log);
PHP_METHOD(Phalcon_Logger_Logger, notice);
PHP_METHOD(Phalcon_Logger_Logger, removeAdapter);
PHP_METHOD(Phalcon_Logger_Logger, setAdapters);
PHP_METHOD(Phalcon_Logger_Logger, setLogLevel);
PHP_METHOD(Phalcon_Logger_Logger, warning);
PHP_METHOD(Phalcon_Logger_Logger, addMessage);
PHP_METHOD(Phalcon_Logger_Logger, getLevels);
PHP_METHOD(Phalcon_Logger_Logger, getLevelNumber);
zend_object *zephir_init_properties_Phalcon_Logger_Logger(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_logger_getadapters, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_getloglevel, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_logger___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, adapters, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, adapters, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, timezone, DateTimeZone, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_logger_addadapter, 0, 2, Phalcon\\Logger\\Logger, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, adapter, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_alert, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, message)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_critical, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, message)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_debug, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, message)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_error, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, message)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_emergency, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, message)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_logger_excludeadapters, 0, 0, Phalcon\\Logger\\Logger, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, adapters, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, adapters, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_logger_getadapter, 0, 1, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_info, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, message)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_log, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_notice, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, message)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_logger_removeadapter, 0, 1, Phalcon\\Logger\\Logger, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_logger_setadapters, 0, 1, Phalcon\\Logger\\Logger, 0)
	ZEND_ARG_ARRAY_INFO(0, adapters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_logger_setloglevel, 0, 1, Phalcon\\Logger\\Logger, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_warning, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, message)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_addmessage, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_getlevels, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_logger_getlevelnumber, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_logger_zephir_init_properties_phalcon_logger_logger, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_logger_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Logger_Logger, getAdapters, arginfo_phalcon_logger_logger_getadapters, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Logger_Logger, getAdapters, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Logger_Logger, getLogLevel, arginfo_phalcon_logger_logger_getloglevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, getName, arginfo_phalcon_logger_logger_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, __construct, arginfo_phalcon_logger_logger___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_Logger, addAdapter, arginfo_phalcon_logger_logger_addadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, alert, arginfo_phalcon_logger_logger_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, critical, arginfo_phalcon_logger_logger_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, debug, arginfo_phalcon_logger_logger_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, error, arginfo_phalcon_logger_logger_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, emergency, arginfo_phalcon_logger_logger_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, excludeAdapters, arginfo_phalcon_logger_logger_excludeadapters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, getAdapter, arginfo_phalcon_logger_logger_getadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, info, arginfo_phalcon_logger_logger_info, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, log, arginfo_phalcon_logger_logger_log, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, notice, arginfo_phalcon_logger_logger_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, removeAdapter, arginfo_phalcon_logger_logger_removeadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, setAdapters, arginfo_phalcon_logger_logger_setadapters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, setLogLevel, arginfo_phalcon_logger_logger_setloglevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, warning, arginfo_phalcon_logger_logger_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Logger, addMessage, arginfo_phalcon_logger_logger_addmessage, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger_Logger, getLevels, arginfo_phalcon_logger_logger_getlevels, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger_Logger, getLevelNumber, arginfo_phalcon_logger_logger_getlevelnumber, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
