
extern zend_class_entry *phalcon_mvc_model_criteriainterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_CriteriaInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_andwhere, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_andwhere, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_betweenwhere, 0, 3, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_betweenwhere, 0, 3, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, expr)
#endif
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bind, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bind, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bindtypes, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bindtypes, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_cache, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_cache, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, cache, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_conditions, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_conditions, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_distinct, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_distinct, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
	ZEND_ARG_INFO(0, distinct)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_execute, 0, 0, Phalcon\\Mvc\\Model\\ResultsetInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_execute, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model\\ResultsetInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_forupdate, 0, 0, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_forupdate, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, forUpdate, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, forUpdate)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_getcolumns, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_getcolumns, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_getconditions, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_getconditions, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_getmodelname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_getmodelname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_getorderby, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_getorderby, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_getparams, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_getparams, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_getwhere, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_getwhere, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_groupby, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_groupby, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_having, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_having, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
	ZEND_ARG_INFO(0, having)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_innerjoin, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_innerjoin, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, model)
#endif
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_inwhere, 0, 2, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_inwhere, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, expr)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_leftjoin, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_leftjoin, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, model)
#endif
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_limit, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_limit, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, limit, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, limit)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, offset)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_notbetweenwhere, 0, 3, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_notbetweenwhere, 0, 3, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, expr)
#endif
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_notinwhere, 0, 2, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_notinwhere, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, expr)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_orderby, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_orderby, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, orderColumns, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, orderColumns)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_orwhere, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_orwhere, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_rightjoin, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_rightjoin, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, model)
#endif
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_setmodelname, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_setmodelname, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, modelName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_sharedlock, 0, 0, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_sharedlock, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sharedLock, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, sharedLock)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_where, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_where, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_criteriainterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, andWhere, arginfo_phalcon_mvc_model_criteriainterface_andwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, betweenWhere, arginfo_phalcon_mvc_model_criteriainterface_betweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, bind, arginfo_phalcon_mvc_model_criteriainterface_bind)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, bindTypes, arginfo_phalcon_mvc_model_criteriainterface_bindtypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, cache, arginfo_phalcon_mvc_model_criteriainterface_cache)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, conditions, arginfo_phalcon_mvc_model_criteriainterface_conditions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, distinct, arginfo_phalcon_mvc_model_criteriainterface_distinct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, execute, arginfo_phalcon_mvc_model_criteriainterface_execute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, forUpdate, arginfo_phalcon_mvc_model_criteriainterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getColumns, arginfo_phalcon_mvc_model_criteriainterface_getcolumns)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getConditions, arginfo_phalcon_mvc_model_criteriainterface_getconditions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getGroupBy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getHaving, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getLimit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getModelName, arginfo_phalcon_mvc_model_criteriainterface_getmodelname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getOrderBy, arginfo_phalcon_mvc_model_criteriainterface_getorderby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getParams, arginfo_phalcon_mvc_model_criteriainterface_getparams)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getWhere, arginfo_phalcon_mvc_model_criteriainterface_getwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, groupBy, arginfo_phalcon_mvc_model_criteriainterface_groupby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, having, arginfo_phalcon_mvc_model_criteriainterface_having)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, innerJoin, arginfo_phalcon_mvc_model_criteriainterface_innerjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, inWhere, arginfo_phalcon_mvc_model_criteriainterface_inwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, leftJoin, arginfo_phalcon_mvc_model_criteriainterface_leftjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, limit, arginfo_phalcon_mvc_model_criteriainterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, notBetweenWhere, arginfo_phalcon_mvc_model_criteriainterface_notbetweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, notInWhere, arginfo_phalcon_mvc_model_criteriainterface_notinwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, orderBy, arginfo_phalcon_mvc_model_criteriainterface_orderby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, orWhere, arginfo_phalcon_mvc_model_criteriainterface_orwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, rightJoin, arginfo_phalcon_mvc_model_criteriainterface_rightjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, setModelName, arginfo_phalcon_mvc_model_criteriainterface_setmodelname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, sharedLock, arginfo_phalcon_mvc_model_criteriainterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, where, arginfo_phalcon_mvc_model_criteriainterface_where)
	PHP_FE_END
};
