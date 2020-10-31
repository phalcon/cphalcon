
extern zend_class_entry *phalcon_datamapper_pdo_profiler_profiler_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Profiler_Profiler);

PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, __construct);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, finish);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, getLogFormat);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, getLogger);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, getLogLevel);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, isActive);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, setActive);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, setLogFormat);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, setLogLevel);
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, start);
zend_object *zephir_init_properties_Phalcon_DataMapper_Pdo_Profiler_Profiler(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, logger, Psr\\Log\\LoggerInterface, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_finish, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_finish, 0, 0, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_finish, 0, 0, 0)
#define arginfo_phalcon_datamapper_pdo_profiler_profiler_finish NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, statement)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_getlogformat, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_getlogformat, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_getlogger, 0, 0, Psr\\Log\\LoggerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_getlogger, 0, 0, IS_OBJECT, "Psr\\Log\\LoggerInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_getloglevel, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_getloglevel, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_isactive, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_isactive, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_setactive, 0, 1, Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_setactive, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, active, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, active)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_setlogformat, 0, 1, Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_setlogformat, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, logFormat, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, logFormat)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_setloglevel, 0, 1, Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_setloglevel, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, logLevel, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, logLevel)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_start, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_start, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profiler_start, 0, 0, 1)
#define arginfo_phalcon_datamapper_pdo_profiler_profiler_start NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_pdo_profiler_profiler_method_entry) {
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_Profiler, __construct, arginfo_phalcon_datamapper_pdo_profiler_profiler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_Profiler, finish, arginfo_phalcon_datamapper_pdo_profiler_profiler_finish, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_Profiler, getLogFormat, arginfo_phalcon_datamapper_pdo_profiler_profiler_getlogformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_Profiler, getLogger, arginfo_phalcon_datamapper_pdo_profiler_profiler_getlogger, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_Profiler, getLogLevel, arginfo_phalcon_datamapper_pdo_profiler_profiler_getloglevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_Profiler, isActive, arginfo_phalcon_datamapper_pdo_profiler_profiler_isactive, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_Profiler, setActive, arginfo_phalcon_datamapper_pdo_profiler_profiler_setactive, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_Profiler, setLogFormat, arginfo_phalcon_datamapper_pdo_profiler_profiler_setlogformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_Profiler, setLogLevel, arginfo_phalcon_datamapper_pdo_profiler_profiler_setloglevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Profiler_Profiler, start, arginfo_phalcon_datamapper_pdo_profiler_profiler_start, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
