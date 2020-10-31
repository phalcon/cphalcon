
extern zend_class_entry *phalcon_datamapper_query_update_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_Update);

PHP_METHOD(Phalcon_DataMapper_Query_Update, __construct);
PHP_METHOD(Phalcon_DataMapper_Query_Update, column);
PHP_METHOD(Phalcon_DataMapper_Query_Update, columns);
PHP_METHOD(Phalcon_DataMapper_Query_Update, from);
PHP_METHOD(Phalcon_DataMapper_Query_Update, getStatement);
PHP_METHOD(Phalcon_DataMapper_Query_Update, hasColumns);
PHP_METHOD(Phalcon_DataMapper_Query_Update, returning);
PHP_METHOD(Phalcon_DataMapper_Query_Update, reset);
PHP_METHOD(Phalcon_DataMapper_Query_Update, set);
PHP_METHOD(Phalcon_DataMapper_Query_Update, buildColumns);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_query_update___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\DataMapper\\Pdo\\Connection, 0)
	ZEND_ARG_OBJ_INFO(0, bind, Phalcon\\DataMapper\\Query\\Bind, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_update_column, 0, 1, Phalcon\\DataMapper\\Query\\Update, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_update_column, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\Update", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, column, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, column)
#endif
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_update_columns, 0, 1, Phalcon\\DataMapper\\Query\\Update, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_update_columns, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\Update", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_update_from, 0, 1, Phalcon\\DataMapper\\Query\\Update, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_update_from, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\Update", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, table)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_update_getstatement, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_update_getstatement, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_update_hascolumns, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_update_hascolumns, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_update_returning, 0, 1, Phalcon\\DataMapper\\Query\\Update, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_update_returning, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\Update", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_update_reset, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_update_reset, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_phalcon_datamapper_query_update_reset NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_update_set, 0, 1, Phalcon\\DataMapper\\Query\\Update, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_update_set, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\Update", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, column, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, column)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_update_buildcolumns, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_update_buildcolumns, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_query_update_method_entry) {
	PHP_ME(Phalcon_DataMapper_Query_Update, __construct, arginfo_phalcon_datamapper_query_update___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_DataMapper_Query_Update, column, arginfo_phalcon_datamapper_query_update_column, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Update, columns, arginfo_phalcon_datamapper_query_update_columns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Update, from, arginfo_phalcon_datamapper_query_update_from, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Update, getStatement, arginfo_phalcon_datamapper_query_update_getstatement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Update, hasColumns, arginfo_phalcon_datamapper_query_update_hascolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Update, returning, arginfo_phalcon_datamapper_query_update_returning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Update, reset, arginfo_phalcon_datamapper_query_update_reset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Update, set, arginfo_phalcon_datamapper_query_update_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Update, buildColumns, arginfo_phalcon_datamapper_query_update_buildcolumns, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
