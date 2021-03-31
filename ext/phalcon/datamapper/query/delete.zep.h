
extern zend_class_entry *phalcon_datamapper_query_delete_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_Delete);

PHP_METHOD(Phalcon_DataMapper_Query_Delete, __construct);
PHP_METHOD(Phalcon_DataMapper_Query_Delete, from);
PHP_METHOD(Phalcon_DataMapper_Query_Delete, returning);
PHP_METHOD(Phalcon_DataMapper_Query_Delete, getStatement);
PHP_METHOD(Phalcon_DataMapper_Query_Delete, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_query_delete___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\DataMapper\\Pdo\\Connection, 0)
	ZEND_ARG_OBJ_INFO(0, bind, Phalcon\\DataMapper\\Query\\Bind, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_delete_from, 0, 1, Phalcon\\DataMapper\\Query\\Delete, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_delete_returning, 0, 1, Phalcon\\DataMapper\\Query\\Delete, 0)
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_delete_getstatement, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_delete_reset, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_query_delete_method_entry) {
	PHP_ME(Phalcon_DataMapper_Query_Delete, __construct, arginfo_phalcon_datamapper_query_delete___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_DataMapper_Query_Delete, from, arginfo_phalcon_datamapper_query_delete_from, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Delete, returning, arginfo_phalcon_datamapper_query_delete_returning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Delete, getStatement, arginfo_phalcon_datamapper_query_delete_getstatement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Delete, reset, arginfo_phalcon_datamapper_query_delete_reset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
