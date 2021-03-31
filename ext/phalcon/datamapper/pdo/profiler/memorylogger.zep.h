
extern zend_class_entry *phalcon_datamapper_pdo_profiler_memorylogger_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger);

PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, getMessages);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, log);
zend_object *zephir_init_properties_Phalcon_DataMapper_Pdo_Profiler_MemoryLogger(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_getmessages, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_memorylogger_zephir_init_properties_phalcon_datamapper_pdo_profiler_memorylogger, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_pdo_profiler_memorylogger_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, getMessages, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_getmessages, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, getMessages, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, log, arginfo_phalcon_datamapper_pdo_profiler_memorylogger_log, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
