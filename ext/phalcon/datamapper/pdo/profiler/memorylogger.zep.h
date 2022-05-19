
extern zend_class_entry *phalcon_datamapper_pdo_profiler_memorylogger_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger);

PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, alert);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, critical);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, debug);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, emergency);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, error);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, getAdapter);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, getAdapters);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, getLogLevel);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, getMessages);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, getName);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, info);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, notice);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, warning);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, log);
zend_object *zephir_init_properties_Phalcon_DataMapper_Pdo_Profiler_MemoryLogger(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_alert, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_critical, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_debug, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_emergency, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_error, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_getadapter, 0, 1, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_getadapters, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_getloglevel, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_getmessages, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_info, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_notice, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_warning, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_log, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, level)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_zephir_init_properties_phalcon_datamapper_pdo_profiler_memorylogger, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_pdo_profiler_memorylogger_method_entry) {
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, alert, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, critical, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, debug, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, emergency, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, error, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, getAdapter, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_getadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, getAdapters, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_getadapters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, getLogLevel, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_getloglevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, getMessages, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, getName, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, info, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_info, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, notice, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, warning, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, log, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_log, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
