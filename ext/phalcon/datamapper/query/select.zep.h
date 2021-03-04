
extern zend_class_entry *phalcon_datamapper_query_select_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_Select);

PHP_METHOD(Phalcon_DataMapper_Query_Select, __call);
PHP_METHOD(Phalcon_DataMapper_Query_Select, andHaving);
PHP_METHOD(Phalcon_DataMapper_Query_Select, asAlias);
PHP_METHOD(Phalcon_DataMapper_Query_Select, appendHaving);
PHP_METHOD(Phalcon_DataMapper_Query_Select, appendJoin);
PHP_METHOD(Phalcon_DataMapper_Query_Select, columns);
PHP_METHOD(Phalcon_DataMapper_Query_Select, distinct);
PHP_METHOD(Phalcon_DataMapper_Query_Select, from);
PHP_METHOD(Phalcon_DataMapper_Query_Select, forUpdate);
PHP_METHOD(Phalcon_DataMapper_Query_Select, getStatement);
PHP_METHOD(Phalcon_DataMapper_Query_Select, groupBy);
PHP_METHOD(Phalcon_DataMapper_Query_Select, hasColumns);
PHP_METHOD(Phalcon_DataMapper_Query_Select, having);
PHP_METHOD(Phalcon_DataMapper_Query_Select, join);
PHP_METHOD(Phalcon_DataMapper_Query_Select, orHaving);
PHP_METHOD(Phalcon_DataMapper_Query_Select, reset);
PHP_METHOD(Phalcon_DataMapper_Query_Select, subSelect);
PHP_METHOD(Phalcon_DataMapper_Query_Select, union);
PHP_METHOD(Phalcon_DataMapper_Query_Select, unionAll);
PHP_METHOD(Phalcon_DataMapper_Query_Select, getCurrentStatement);
PHP_METHOD(Phalcon_DataMapper_Query_Select, buildColumns);
PHP_METHOD(Phalcon_DataMapper_Query_Select, buildFrom);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_query_select___call, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_andhaving, 0, 1, Phalcon\\DataMapper\\Query\\Select, 0)
	ZEND_ARG_TYPE_INFO(0, condition, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_asalias, 0, 1, Phalcon\\DataMapper\\Query\\Select, 0)
	ZEND_ARG_TYPE_INFO(0, asAlias, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_appendhaving, 0, 1, Phalcon\\DataMapper\\Query\\Select, 0)
	ZEND_ARG_TYPE_INFO(0, condition, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_appendjoin, 0, 1, Phalcon\\DataMapper\\Query\\Select, 0)
	ZEND_ARG_TYPE_INFO(0, condition, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_columns, 0, 0, Phalcon\\DataMapper\\Query\\Select, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_distinct, 0, 0, Phalcon\\DataMapper\\Query\\Select, 0)
	ZEND_ARG_TYPE_INFO(0, enable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_from, 0, 1, Phalcon\\DataMapper\\Query\\Select, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_forupdate, 0, 0, Phalcon\\DataMapper\\Query\\Select, 0)
	ZEND_ARG_TYPE_INFO(0, enable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_select_getstatement, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_groupby, 0, 1, Phalcon\\DataMapper\\Query\\Select, 0)
	ZEND_ARG_INFO(0, groupBy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_select_hascolumns, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_having, 0, 1, Phalcon\\DataMapper\\Query\\Select, 0)
	ZEND_ARG_TYPE_INFO(0, condition, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_join, 0, 3, Phalcon\\DataMapper\\Query\\Select, 0)
	ZEND_ARG_TYPE_INFO(0, join, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, condition, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_orhaving, 0, 1, Phalcon\\DataMapper\\Query\\Select, 0)
	ZEND_ARG_TYPE_INFO(0, condition, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_reset, 0, 0, Phalcon\\DataMapper\\Query\\Select, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_subselect, 0, 0, Phalcon\\DataMapper\\Query\\Select, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_union, 0, 0, Phalcon\\DataMapper\\Query\\Select, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_select_unionall, 0, 0, Phalcon\\DataMapper\\Query\\Select, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_select_getcurrentstatement, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, suffix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_select_buildcolumns, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_select_buildfrom, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_query_select_method_entry) {
	PHP_ME(Phalcon_DataMapper_Query_Select, __call, arginfo_phalcon_datamapper_query_select___call, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, andHaving, arginfo_phalcon_datamapper_query_select_andhaving, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, asAlias, arginfo_phalcon_datamapper_query_select_asalias, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, appendHaving, arginfo_phalcon_datamapper_query_select_appendhaving, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, appendJoin, arginfo_phalcon_datamapper_query_select_appendjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, columns, arginfo_phalcon_datamapper_query_select_columns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, distinct, arginfo_phalcon_datamapper_query_select_distinct, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, from, arginfo_phalcon_datamapper_query_select_from, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, forUpdate, arginfo_phalcon_datamapper_query_select_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, getStatement, arginfo_phalcon_datamapper_query_select_getstatement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, groupBy, arginfo_phalcon_datamapper_query_select_groupby, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, hasColumns, arginfo_phalcon_datamapper_query_select_hascolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, having, arginfo_phalcon_datamapper_query_select_having, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, join, arginfo_phalcon_datamapper_query_select_join, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, orHaving, arginfo_phalcon_datamapper_query_select_orhaving, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, reset, arginfo_phalcon_datamapper_query_select_reset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, subSelect, arginfo_phalcon_datamapper_query_select_subselect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, union, arginfo_phalcon_datamapper_query_select_union, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, unionAll, arginfo_phalcon_datamapper_query_select_unionall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Select, getCurrentStatement, arginfo_phalcon_datamapper_query_select_getcurrentstatement, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_DataMapper_Query_Select, buildColumns, arginfo_phalcon_datamapper_query_select_buildcolumns, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_DataMapper_Query_Select, buildFrom, arginfo_phalcon_datamapper_query_select_buildfrom, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
