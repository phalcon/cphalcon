
extern zend_class_entry *phalcon_mvc_model_query_builder_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Builder);

PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, addFrom);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, andHaving);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, andWhere);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, autoescape);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, betweenHaving);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, betweenWhere);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, columns);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, distinct);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, forUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, from);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getBindParams);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getBindTypes);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getColumns);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDistinct);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getFrom);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getGroupBy);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getHaving);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getJoins);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getLimit);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getModels);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOffset);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOrderBy);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getPhql);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getQuery);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getWhere);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, groupBy);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, having);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, inHaving);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, innerJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, inWhere);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, join);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, leftJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, limit);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notBetweenHaving);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notBetweenWhere);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notInHaving);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notInWhere);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, offset);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orderBy);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orHaving);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orWhere);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, rightJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setBindParams);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setBindTypes);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, where);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, conditionBetween);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, conditionIn);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, conditionNotBetween);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, conditionNotIn);
zend_object *zephir_init_properties_Phalcon_Mvc_Model_Query_Builder(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_addfrom, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_andhaving, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindTypes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_andwhere, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindTypes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builder_autoescape, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, identifier, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_betweenhaving, 0, 3, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_betweenwhere, 0, 3, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_columns, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_distinct, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_INFO(0, distinct)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_forupdate, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, forUpdate, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_from, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_INFO(0, models)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getbindparams, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getbindtypes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getcolumns, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getdi, 0, 0, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getdistinct, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getfrom, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getgroupby, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builder_gethaving, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getjoins, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getlimit, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getmodels, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getoffset, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getorderby, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getphql, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getquery, 0, 0, Phalcon\\Mvc\\Model\\QueryInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_getwhere, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_groupby, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_having, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindTypes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_inhaving, 0, 2, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_innerjoin, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_inwhere, 0, 2, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_join, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_leftjoin, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_limit, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, limit, IS_LONG, 0)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_notbetweenhaving, 0, 3, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_notbetweenwhere, 0, 3, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_notinhaving, 0, 2, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_notinwhere, 0, 2, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_offset, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_orderby, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_INFO(0, orderBy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_orhaving, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindTypes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_orwhere, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindTypes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_rightjoin, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_setbindparams, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_setbindtypes, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builder_setdi, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_where, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindTypes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_conditionbetween, 0, 5, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, clause, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_conditionin, 0, 4, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, clause, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_conditionnotbetween, 0, 5, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, clause, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builder_conditionnotin, 0, 4, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, clause, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_zephir_init_properties_phalcon_mvc_model_query_builder, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_builder_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, __construct, arginfo_phalcon_mvc_model_query_builder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, addFrom, arginfo_phalcon_mvc_model_query_builder_addfrom, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, andHaving, arginfo_phalcon_mvc_model_query_builder_andhaving, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, andWhere, arginfo_phalcon_mvc_model_query_builder_andwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, autoescape, arginfo_phalcon_mvc_model_query_builder_autoescape, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, betweenHaving, arginfo_phalcon_mvc_model_query_builder_betweenhaving, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, betweenWhere, arginfo_phalcon_mvc_model_query_builder_betweenwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, columns, arginfo_phalcon_mvc_model_query_builder_columns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, distinct, arginfo_phalcon_mvc_model_query_builder_distinct, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, forUpdate, arginfo_phalcon_mvc_model_query_builder_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, from, arginfo_phalcon_mvc_model_query_builder_from, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getBindParams, arginfo_phalcon_mvc_model_query_builder_getbindparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getBindTypes, arginfo_phalcon_mvc_model_query_builder_getbindtypes, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getColumns, arginfo_phalcon_mvc_model_query_builder_getcolumns, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getColumns, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getDI, arginfo_phalcon_mvc_model_query_builder_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getDistinct, arginfo_phalcon_mvc_model_query_builder_getdistinct, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getFrom, arginfo_phalcon_mvc_model_query_builder_getfrom, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getFrom, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getGroupBy, arginfo_phalcon_mvc_model_query_builder_getgroupby, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getHaving, arginfo_phalcon_mvc_model_query_builder_gethaving, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getJoins, arginfo_phalcon_mvc_model_query_builder_getjoins, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getLimit, arginfo_phalcon_mvc_model_query_builder_getlimit, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getLimit, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getModels, arginfo_phalcon_mvc_model_query_builder_getmodels, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getModels, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getOffset, arginfo_phalcon_mvc_model_query_builder_getoffset, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getOrderBy, arginfo_phalcon_mvc_model_query_builder_getorderby, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getOrderBy, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getPhql, arginfo_phalcon_mvc_model_query_builder_getphql, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getQuery, arginfo_phalcon_mvc_model_query_builder_getquery, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getWhere, arginfo_phalcon_mvc_model_query_builder_getwhere, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getWhere, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, groupBy, arginfo_phalcon_mvc_model_query_builder_groupby, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, having, arginfo_phalcon_mvc_model_query_builder_having, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, inHaving, arginfo_phalcon_mvc_model_query_builder_inhaving, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, innerJoin, arginfo_phalcon_mvc_model_query_builder_innerjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, inWhere, arginfo_phalcon_mvc_model_query_builder_inwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, join, arginfo_phalcon_mvc_model_query_builder_join, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, leftJoin, arginfo_phalcon_mvc_model_query_builder_leftjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, limit, arginfo_phalcon_mvc_model_query_builder_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, notBetweenHaving, arginfo_phalcon_mvc_model_query_builder_notbetweenhaving, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, notBetweenWhere, arginfo_phalcon_mvc_model_query_builder_notbetweenwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, notInHaving, arginfo_phalcon_mvc_model_query_builder_notinhaving, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, notInWhere, arginfo_phalcon_mvc_model_query_builder_notinwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, offset, arginfo_phalcon_mvc_model_query_builder_offset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, orderBy, arginfo_phalcon_mvc_model_query_builder_orderby, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, orHaving, arginfo_phalcon_mvc_model_query_builder_orhaving, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, orWhere, arginfo_phalcon_mvc_model_query_builder_orwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, rightJoin, arginfo_phalcon_mvc_model_query_builder_rightjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, setBindParams, arginfo_phalcon_mvc_model_query_builder_setbindparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, setBindTypes, arginfo_phalcon_mvc_model_query_builder_setbindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, setDI, arginfo_phalcon_mvc_model_query_builder_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, where, arginfo_phalcon_mvc_model_query_builder_where, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, conditionBetween, arginfo_phalcon_mvc_model_query_builder_conditionbetween, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, conditionIn, arginfo_phalcon_mvc_model_query_builder_conditionin, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, conditionNotBetween, arginfo_phalcon_mvc_model_query_builder_conditionnotbetween, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, conditionNotIn, arginfo_phalcon_mvc_model_query_builder_conditionnotin, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
