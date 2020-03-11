
extern zend_class_entry *phalcon_datamapper_query_queryfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_QueryFactory);

PHP_METHOD(Phalcon_DataMapper_Query_QueryFactory, __construct);
PHP_METHOD(Phalcon_DataMapper_Query_QueryFactory, newBind);
PHP_METHOD(Phalcon_DataMapper_Query_QueryFactory, newDelete);
PHP_METHOD(Phalcon_DataMapper_Query_QueryFactory, newInsert);
PHP_METHOD(Phalcon_DataMapper_Query_QueryFactory, newSelect);
PHP_METHOD(Phalcon_DataMapper_Query_QueryFactory, newUpdate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_query_queryfactory___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, selectClass, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, selectClass)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_queryfactory_newbind, 0, 0, Phalcon\\DataMapper\\Query\\Bind, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_queryfactory_newbind, 0, 0, IS_OBJECT, "Phalcon\\DataMapper\\Query\\Bind", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_queryfactory_newdelete, 0, 1, Phalcon\\DataMapper\\Query\\Delete, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_queryfactory_newdelete, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\Delete", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\DataMapper\\Pdo\\Connection, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_queryfactory_newinsert, 0, 1, Phalcon\\DataMapper\\Query\\Insert, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_queryfactory_newinsert, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\Insert", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\DataMapper\\Pdo\\Connection, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_queryfactory_newselect, 0, 1, Phalcon\\DataMapper\\Query\\Select, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_queryfactory_newselect, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\Select", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\DataMapper\\Pdo\\Connection, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_queryfactory_newupdate, 0, 1, Phalcon\\DataMapper\\Query\\Update, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_queryfactory_newupdate, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\Update", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\DataMapper\\Pdo\\Connection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_query_queryfactory_method_entry) {
	PHP_ME(Phalcon_DataMapper_Query_QueryFactory, __construct, arginfo_phalcon_datamapper_query_queryfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_DataMapper_Query_QueryFactory, newBind, arginfo_phalcon_datamapper_query_queryfactory_newbind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_QueryFactory, newDelete, arginfo_phalcon_datamapper_query_queryfactory_newdelete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_QueryFactory, newInsert, arginfo_phalcon_datamapper_query_queryfactory_newinsert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_QueryFactory, newSelect, arginfo_phalcon_datamapper_query_queryfactory_newselect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_QueryFactory, newUpdate, arginfo_phalcon_datamapper_query_queryfactory_newupdate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
