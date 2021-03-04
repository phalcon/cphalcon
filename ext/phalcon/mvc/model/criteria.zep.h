
extern zend_class_entry *phalcon_mvc_model_criteria_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Criteria);

PHP_METHOD(Phalcon_Mvc_Model_Criteria, andWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, betweenWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bind);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bindTypes);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, cache);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, columns);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, conditions);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, createBuilder);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, distinct);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, forUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, fromInput);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getColumns);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getConditions);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getGroupBy);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getHaving);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getLimit);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getModelName);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getOrderBy);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getParams);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, groupBy);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, having);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, innerJoin);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, inWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, join);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, leftJoin);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, limit);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notBetweenWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notInWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orderBy);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, rightJoin);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setModelName);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, sharedLock);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, where);
zend_object *zephir_init_properties_Phalcon_Mvc_Model_Criteria(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_andwhere, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_betweenwhere, 0, 3, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_bind, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_bindtypes, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_cache, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, cache, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_columns, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_conditions, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_createbuilder, 0, 0, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_distinct, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_INFO(0, distinct)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_execute, 0, 0, Phalcon\\Mvc\\Model\\ResultsetInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_forupdate, 0, 0, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, forUpdate, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_frominput, 0, 3, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_getcolumns, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteria_getconditions, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_getdi, 0, 0, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_getgroupby, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_gethaving, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_getlimit, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteria_getmodelname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteria_getorderby, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteria_getparams, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteria_getwhere, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_groupby, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_having, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_INFO(0, having)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_innerjoin, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_inwhere, 0, 2, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_join, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_leftjoin, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_limit, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, limit, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_notbetweenwhere, 0, 3, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_notinwhere, 0, 2, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_orderby, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, orderColumns, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_orwhere, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_rightjoin, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteria_setdi, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_setmodelname, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_sharedlock, 0, 0, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, sharedLock, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteria_where, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_zephir_init_properties_phalcon_mvc_model_criteria, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_criteria_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Criteria, andWhere, arginfo_phalcon_mvc_model_criteria_andwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, betweenWhere, arginfo_phalcon_mvc_model_criteria_betweenwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, bind, arginfo_phalcon_mvc_model_criteria_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, bindTypes, arginfo_phalcon_mvc_model_criteria_bindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, cache, arginfo_phalcon_mvc_model_criteria_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, columns, arginfo_phalcon_mvc_model_criteria_columns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, conditions, arginfo_phalcon_mvc_model_criteria_conditions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, createBuilder, arginfo_phalcon_mvc_model_criteria_createbuilder, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, distinct, arginfo_phalcon_mvc_model_criteria_distinct, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, execute, arginfo_phalcon_mvc_model_criteria_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, forUpdate, arginfo_phalcon_mvc_model_criteria_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, fromInput, arginfo_phalcon_mvc_model_criteria_frominput, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getColumns, arginfo_phalcon_mvc_model_criteria_getcolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getConditions, arginfo_phalcon_mvc_model_criteria_getconditions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getDI, arginfo_phalcon_mvc_model_criteria_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getGroupBy, arginfo_phalcon_mvc_model_criteria_getgroupby, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getHaving, arginfo_phalcon_mvc_model_criteria_gethaving, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getLimit, arginfo_phalcon_mvc_model_criteria_getlimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getModelName, arginfo_phalcon_mvc_model_criteria_getmodelname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getOrderBy, arginfo_phalcon_mvc_model_criteria_getorderby, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getParams, arginfo_phalcon_mvc_model_criteria_getparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getWhere, arginfo_phalcon_mvc_model_criteria_getwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, groupBy, arginfo_phalcon_mvc_model_criteria_groupby, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, having, arginfo_phalcon_mvc_model_criteria_having, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, innerJoin, arginfo_phalcon_mvc_model_criteria_innerjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, inWhere, arginfo_phalcon_mvc_model_criteria_inwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, join, arginfo_phalcon_mvc_model_criteria_join, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, leftJoin, arginfo_phalcon_mvc_model_criteria_leftjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, limit, arginfo_phalcon_mvc_model_criteria_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, notBetweenWhere, arginfo_phalcon_mvc_model_criteria_notbetweenwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, notInWhere, arginfo_phalcon_mvc_model_criteria_notinwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, orderBy, arginfo_phalcon_mvc_model_criteria_orderby, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, orWhere, arginfo_phalcon_mvc_model_criteria_orwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, rightJoin, arginfo_phalcon_mvc_model_criteria_rightjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, setDI, arginfo_phalcon_mvc_model_criteria_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, setModelName, arginfo_phalcon_mvc_model_criteria_setmodelname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, sharedLock, arginfo_phalcon_mvc_model_criteria_sharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, where, arginfo_phalcon_mvc_model_criteria_where, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
