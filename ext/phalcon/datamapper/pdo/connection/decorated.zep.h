
extern zend_class_entry *phalcon_datamapper_pdo_connection_decorated_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Connection_Decorated);

PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_Decorated, __construct);
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_Decorated, connect);
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_Decorated, disconnect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_decorated___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, pdo, PDO, 0)
	ZEND_ARG_OBJ_INFO(0, profiler, Phalcon\\DataMapper\\Pdo\\Profiler\\ProfilerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_decorated_connect, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_decorated_disconnect, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_pdo_connection_decorated_method_entry) {
	PHP_ME(Phalcon_DataMapper_Pdo_Connection_Decorated, __construct, arginfo_phalcon_datamapper_pdo_connection_decorated___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_DataMapper_Pdo_Connection_Decorated, connect, arginfo_phalcon_datamapper_pdo_connection_decorated_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_Connection_Decorated, disconnect, arginfo_phalcon_datamapper_pdo_connection_decorated_disconnect, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
