
extern zend_class_entry *phalcon_datamapper_pdo_connection_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Connection);

PHP_METHOD(Phalcon_DataMapper_Pdo_Connection, __construct);
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection, __debugInfo);
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection, connect);
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection, disconnect);
zend_object *zephir_init_properties_Phalcon_DataMapper_Pdo_Connection(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_connection___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, dsn, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, username, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, password, IS_STRING, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_ARRAY_INFO(0, queries, 0)
	ZEND_ARG_OBJ_INFO(0, profiler, Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection___debuginfo, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_connect, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_disconnect, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_zephir_init_properties_phalcon_datamapper_pdo_connection, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_pdo_connection_method_entry) {
	PHP_ME(Phalcon_DataMapper_Pdo_Connection, __construct, arginfo_phalcon_datamapper_pdo_connection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_DataMapper_Pdo_Connection, __debugInfo, arginfo_phalcon_datamapper_pdo_connection___debuginfo, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Connection, connect, arginfo_phalcon_datamapper_pdo_connection_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Connection, disconnect, arginfo_phalcon_datamapper_pdo_connection_disconnect, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
