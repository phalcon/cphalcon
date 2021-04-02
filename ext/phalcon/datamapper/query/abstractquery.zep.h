
extern zend_class_entry *phalcon_datamapper_query_abstractquery_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_AbstractQuery);

PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, __construct);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, bindInline);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, bindValue);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, bindValues);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, getBindValues);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, getStatement);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, perform);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, setFlag);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, quoteIdentifier);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, reset);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, buildFlags);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, buildReturning);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, indent);
zend_object *zephir_init_properties_Phalcon_DataMapper_Query_AbstractQuery(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_query_abstractquery___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\DataMapper\\Pdo\\Connection, 0)
	ZEND_ARG_OBJ_INFO(0, bind, Phalcon\\DataMapper\\Query\\Bind, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractquery_bindinline, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_abstractquery_bindvalue, 0, 2, Phalcon\\DataMapper\\Query\\AbstractQuery, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_abstractquery_bindvalues, 0, 1, Phalcon\\DataMapper\\Query\\AbstractQuery, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractquery_getbindvalues, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractquery_getstatement, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_query_abstractquery_perform, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractquery_setflag, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, flag, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, enable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractquery_quoteidentifier, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_query_abstractquery_reset, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_query_abstractquery_buildflags, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractquery_buildreturning, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractquery_indent, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_TYPE_INFO(0, glue, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_query_abstractquery_zephir_init_properties_phalcon_datamapper_query_abstractquery, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_query_abstractquery_method_entry) {
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, __construct, arginfo_phalcon_datamapper_query_abstractquery___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, bindInline, arginfo_phalcon_datamapper_query_abstractquery_bindinline, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, bindValue, arginfo_phalcon_datamapper_query_abstractquery_bindvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, bindValues, arginfo_phalcon_datamapper_query_abstractquery_bindvalues, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, getBindValues, arginfo_phalcon_datamapper_query_abstractquery_getbindvalues, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, getStatement, arginfo_phalcon_datamapper_query_abstractquery_getstatement, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, perform, arginfo_phalcon_datamapper_query_abstractquery_perform, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, perform, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, setFlag, arginfo_phalcon_datamapper_query_abstractquery_setflag, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, quoteIdentifier, arginfo_phalcon_datamapper_query_abstractquery_quoteidentifier, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, reset, arginfo_phalcon_datamapper_query_abstractquery_reset, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, reset, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, buildFlags, arginfo_phalcon_datamapper_query_abstractquery_buildflags, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, buildFlags, NULL, ZEND_ACC_PROTECTED)
#endif
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, buildReturning, arginfo_phalcon_datamapper_query_abstractquery_buildreturning, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_DataMapper_Query_AbstractQuery, indent, arginfo_phalcon_datamapper_query_abstractquery_indent, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
