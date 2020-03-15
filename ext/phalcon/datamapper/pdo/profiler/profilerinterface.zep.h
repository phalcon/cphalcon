
extern zend_class_entry *phalcon_datamapper_pdo_profiler_profilerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface);

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_finish, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_finish, 0, 0, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_finish, 0, 0, 0)
#define arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_finish NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, statement)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_getlogger, 0, 0, Psr\\Log\\LoggerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_getlogger, 0, 0, IS_OBJECT, "Psr\\Log\\LoggerInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_getlogformat, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_getlogformat, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_getloglevel, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_getloglevel, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_isactive, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_isactive, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_setactive, 0, 1, Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_setactive, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, active, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, active)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_setlogformat, 0, 1, Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_setlogformat, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, logFormat, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, logFormat)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_setloglevel, 0, 1, Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_setloglevel, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, logLevel, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, logLevel)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_start, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_start, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_start, 0, 0, 1)
#define arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_start NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_pdo_profiler_profilerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, finish, arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_finish)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, getLogger, arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_getlogger)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, getLogFormat, arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_getlogformat)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, getLogLevel, arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_getloglevel)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, isActive, arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_isactive)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, setActive, arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_setactive)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, setLogFormat, arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_setlogformat)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, setLogLevel, arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_setloglevel)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, start, arginfo_phalcon_datamapper_pdo_profiler_profilerinterface_start)
	PHP_FE_END
};
