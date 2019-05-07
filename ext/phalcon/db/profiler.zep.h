
extern zend_class_entry *phalcon_db_profiler_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Profiler);

PHP_METHOD(Phalcon_Db_Profiler, getLastProfile);
PHP_METHOD(Phalcon_Db_Profiler, getNumberTotalStatements);
PHP_METHOD(Phalcon_Db_Profiler, getTotalElapsedSeconds);
PHP_METHOD(Phalcon_Db_Profiler, getProfiles);
PHP_METHOD(Phalcon_Db_Profiler, reset);
PHP_METHOD(Phalcon_Db_Profiler, startProfile);
PHP_METHOD(Phalcon_Db_Profiler, stopProfile);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_profiler_getlastprofile, 0, 0, Phalcon\\Db\\Profiler\\Item, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_getlastprofile, 0, 0, IS_OBJECT, "Phalcon\\Db\\Profiler\\Item", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_getnumbertotalstatements, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_getnumbertotalstatements, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_gettotalelapsedseconds, 0, 0, IS_DOUBLE, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_gettotalelapsedseconds, 0, 0, IS_DOUBLE, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_getprofiles, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_getprofiles, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_profiler_reset, 0, 0, Phalcon\\Db\\Profiler, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_reset, 0, 0, IS_OBJECT, "Phalcon\\Db\\Profiler", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_profiler_startprofile, 0, 1, Phalcon\\Db\\Profiler, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_startprofile, 0, 1, IS_OBJECT, "Phalcon\\Db\\Profiler", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sqlStatement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sqlStatement)
#endif
	ZEND_ARG_INFO(0, sqlVariables)
	ZEND_ARG_INFO(0, sqlBindTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_profiler_stopprofile, 0, 0, Phalcon\\Db\\Profiler, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_stopprofile, 0, 0, IS_OBJECT, "Phalcon\\Db\\Profiler", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_profiler_method_entry) {
	PHP_ME(Phalcon_Db_Profiler, getLastProfile, arginfo_phalcon_db_profiler_getlastprofile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler, getNumberTotalStatements, arginfo_phalcon_db_profiler_getnumbertotalstatements, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler, getTotalElapsedSeconds, arginfo_phalcon_db_profiler_gettotalelapsedseconds, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler, getProfiles, arginfo_phalcon_db_profiler_getprofiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler, reset, arginfo_phalcon_db_profiler_reset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler, startProfile, arginfo_phalcon_db_profiler_startprofile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler, stopProfile, arginfo_phalcon_db_profiler_stopprofile, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
