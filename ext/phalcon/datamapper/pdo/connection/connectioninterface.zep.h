
extern zend_class_entry *phalcon_datamapper_pdo_connection_connectioninterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface);

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_connect, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_connect, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_phalcon_datamapper_pdo_connection_connectioninterface_connect NULL
#endif

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_disconnect, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_disconnect, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_phalcon_datamapper_pdo_connection_connectioninterface_disconnect NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchaffected, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchaffected, 0, 1, IS_LONG, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, statement)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchall, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchall, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, statement)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchassoc, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchassoc, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, statement)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchcolumn, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchcolumn, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, statement)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, column)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchgroup, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchgroup, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, statement)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, flags)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchobject, 0, 1, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchobject, 0, 1, IS_OBJECT, "NULL", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, statement)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchobjects, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchobjects, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, statement)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchone, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchone, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, statement)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchpairs, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchpairs, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, statement)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchvalue, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, statement)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_getadapter, 0, 0, PDO, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_getadapter, 0, 0, IS_OBJECT, "PDO", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_getprofiler, 0, 0, Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_getprofiler, 0, 0, IS_OBJECT, "Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_isconnected, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_isconnected, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_perform, 0, 1, PDOStatement, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_perform, 0, 1, IS_OBJECT, "PDOStatement", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, statement)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connectioninterface_setprofiler, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, profiler, Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_pdo_connection_connectioninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, connect, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_connect)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, disconnect, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_disconnect)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchAffected, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchaffected)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchAll, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchall)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchAssoc, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchassoc)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchColumn, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchcolumn)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchGroup, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchgroup)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchObject, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchobject)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchObjects, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchobjects)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchOne, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchone)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchPairs, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchpairs)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchValue, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_fetchvalue)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, getAdapter, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_getadapter)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, getProfiler, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_getprofiler)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, isConnected, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_isconnected)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, perform, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_perform)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, setProfiler, arginfo_phalcon_datamapper_pdo_connection_connectioninterface_setprofiler)
	PHP_FE_END
};
