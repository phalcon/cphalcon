
extern zend_class_entry *phalcon_datamapper_query_insert_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_Insert);

PHP_METHOD(Phalcon_DataMapper_Query_Insert, __construct);
PHP_METHOD(Phalcon_DataMapper_Query_Insert, column);
PHP_METHOD(Phalcon_DataMapper_Query_Insert, columns);
PHP_METHOD(Phalcon_DataMapper_Query_Insert, into);
PHP_METHOD(Phalcon_DataMapper_Query_Insert, getLastInsertId);
PHP_METHOD(Phalcon_DataMapper_Query_Insert, getStatement);
PHP_METHOD(Phalcon_DataMapper_Query_Insert, returning);
PHP_METHOD(Phalcon_DataMapper_Query_Insert, reset);
PHP_METHOD(Phalcon_DataMapper_Query_Insert, set);
PHP_METHOD(Phalcon_DataMapper_Query_Insert, buildColumns);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_query_insert___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\DataMapper\\Pdo\\Connection, 0)
	ZEND_ARG_OBJ_INFO(0, bind, Phalcon\\DataMapper\\Query\\Bind, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_insert_column, 0, 1, Phalcon\\DataMapper\\Query\\Insert, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_insert_columns, 0, 1, Phalcon\\DataMapper\\Query\\Insert, 0)
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_insert_into, 0, 1, Phalcon\\DataMapper\\Query\\Insert, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_insert_getlastinsertid, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_insert_getstatement, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_insert_returning, 0, 1, Phalcon\\DataMapper\\Query\\Insert, 0)
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_insert_reset, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_insert_set, 0, 1, Phalcon\\DataMapper\\Query\\Insert, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_insert_buildcolumns, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_query_insert_method_entry) {
	PHP_ME(Phalcon_DataMapper_Query_Insert, __construct, arginfo_phalcon_datamapper_query_insert___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_DataMapper_Query_Insert, column, arginfo_phalcon_datamapper_query_insert_column, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Insert, columns, arginfo_phalcon_datamapper_query_insert_columns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Insert, into, arginfo_phalcon_datamapper_query_insert_into, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Insert, getLastInsertId, arginfo_phalcon_datamapper_query_insert_getlastinsertid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Insert, getStatement, arginfo_phalcon_datamapper_query_insert_getstatement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Insert, returning, arginfo_phalcon_datamapper_query_insert_returning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Insert, reset, arginfo_phalcon_datamapper_query_insert_reset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Insert, set, arginfo_phalcon_datamapper_query_insert_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Insert, buildColumns, arginfo_phalcon_datamapper_query_insert_buildcolumns, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
