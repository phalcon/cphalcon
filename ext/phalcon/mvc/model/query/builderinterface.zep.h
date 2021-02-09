
extern zend_class_entry *phalcon_mvc_model_query_builderinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_BuilderInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_addfrom, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_addfrom, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, model)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, alias)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_andwhere, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_andwhere, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_betweenwhere, 0, 3, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_betweenwhere, 0, 3, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, expr)
#endif
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, operator)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_columns, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_columns, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_distinct, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_distinct, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
	ZEND_ARG_INFO(0, distinct)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_forupdate, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_forupdate, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, forUpdate, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, forUpdate)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_from, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_from, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
	ZEND_ARG_INFO(0, models)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getbindparams, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getbindparams, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getbindtypes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getbindtypes, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getcolumns, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getdistinct, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getdistinct, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getfrom, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getgroupby, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getgroupby, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_gethaving, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_gethaving, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getjoins, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getjoins, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getlimit, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getoffset, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getoffset, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getorderby, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getphql, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getphql, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getquery, 0, 0, Phalcon\\Mvc\\Model\\QueryInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getquery, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model\\QueryInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getwhere, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_groupby, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_groupby, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_having, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_having, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, having, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, having)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_innerjoin, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_innerjoin, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, model)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, alias)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_inwhere, 0, 2, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_inwhere, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, expr)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, operator)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_join, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_join, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, model)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, alias)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_leftjoin, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_leftjoin, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, model)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, alias)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_limit, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_limit, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, limit, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, limit)
#endif
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_getmodels, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_notbetweenwhere, 0, 3, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_notbetweenwhere, 0, 3, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, expr)
#endif
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, operator)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_notinwhere, 0, 2, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_notinwhere, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, expr)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, operator)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_offset, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_offset, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, offset)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_orderby, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_orderby, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, orderBy, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, orderBy)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_orwhere, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_orwhere, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_rightjoin, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_rightjoin, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, model)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, alias)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_setbindparams, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_setbindparams, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, merge)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_setbindtypes, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_setbindtypes, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, merge)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_where, 0, 1, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_where, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_builderinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, addFrom, arginfo_phalcon_mvc_model_query_builderinterface_addfrom)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, andWhere, arginfo_phalcon_mvc_model_query_builderinterface_andwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, betweenWhere, arginfo_phalcon_mvc_model_query_builderinterface_betweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, columns, arginfo_phalcon_mvc_model_query_builderinterface_columns)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, distinct, arginfo_phalcon_mvc_model_query_builderinterface_distinct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, forUpdate, arginfo_phalcon_mvc_model_query_builderinterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, from, arginfo_phalcon_mvc_model_query_builderinterface_from)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getBindParams, arginfo_phalcon_mvc_model_query_builderinterface_getbindparams)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getBindTypes, arginfo_phalcon_mvc_model_query_builderinterface_getbindtypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getColumns, arginfo_phalcon_mvc_model_query_builderinterface_getcolumns)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getDistinct, arginfo_phalcon_mvc_model_query_builderinterface_getdistinct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getFrom, arginfo_phalcon_mvc_model_query_builderinterface_getfrom)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getGroupBy, arginfo_phalcon_mvc_model_query_builderinterface_getgroupby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getHaving, arginfo_phalcon_mvc_model_query_builderinterface_gethaving)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getJoins, arginfo_phalcon_mvc_model_query_builderinterface_getjoins)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getLimit, arginfo_phalcon_mvc_model_query_builderinterface_getlimit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getOffset, arginfo_phalcon_mvc_model_query_builderinterface_getoffset)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getOrderBy, arginfo_phalcon_mvc_model_query_builderinterface_getorderby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getPhql, arginfo_phalcon_mvc_model_query_builderinterface_getphql)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getQuery, arginfo_phalcon_mvc_model_query_builderinterface_getquery)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getWhere, arginfo_phalcon_mvc_model_query_builderinterface_getwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, groupBy, arginfo_phalcon_mvc_model_query_builderinterface_groupby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, having, arginfo_phalcon_mvc_model_query_builderinterface_having)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, innerJoin, arginfo_phalcon_mvc_model_query_builderinterface_innerjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, inWhere, arginfo_phalcon_mvc_model_query_builderinterface_inwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, join, arginfo_phalcon_mvc_model_query_builderinterface_join)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, leftJoin, arginfo_phalcon_mvc_model_query_builderinterface_leftjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, limit, arginfo_phalcon_mvc_model_query_builderinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getModels, arginfo_phalcon_mvc_model_query_builderinterface_getmodels)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, notBetweenWhere, arginfo_phalcon_mvc_model_query_builderinterface_notbetweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, notInWhere, arginfo_phalcon_mvc_model_query_builderinterface_notinwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, offset, arginfo_phalcon_mvc_model_query_builderinterface_offset)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, orderBy, arginfo_phalcon_mvc_model_query_builderinterface_orderby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, orWhere, arginfo_phalcon_mvc_model_query_builderinterface_orwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, rightJoin, arginfo_phalcon_mvc_model_query_builderinterface_rightjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, setBindParams, arginfo_phalcon_mvc_model_query_builderinterface_setbindparams)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, setBindTypes, arginfo_phalcon_mvc_model_query_builderinterface_setbindtypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, where, arginfo_phalcon_mvc_model_query_builderinterface_where)
	PHP_FE_END
};
