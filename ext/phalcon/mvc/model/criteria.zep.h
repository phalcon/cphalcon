
extern zend_class_entry *phalcon_mvc_model_criteria_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Criteria);

PHP_METHOD(Phalcon_Mvc_Model_Criteria, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setModelName);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getModelName);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bind);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bindTypes);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, columns);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, join);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, innerJoin);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, leftJoin);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, rightJoin);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, where);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, addWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, andWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, betweenWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notBetweenWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, inWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notInWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, conditions);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, order);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orderBy);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, limit);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, forUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, sharedLock);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, cache);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getColumns);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getConditions);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getLimit);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getOrder);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getParams);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, fromInput);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_setmodelname, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_bind, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_bindtypes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_columns, 0, 0, 1)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_join, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_innerjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_leftjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_rightjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_addwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_andwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_orwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_betweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_notbetweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_inwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_notinwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_conditions, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_order, 0, 0, 1)
	ZEND_ARG_INFO(0, orderColumns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, orderColumns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_forupdate, 0, 0, 0)
	ZEND_ARG_INFO(0, forUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_sharedlock, 0, 0, 0)
	ZEND_ARG_INFO(0, sharedLock)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_cache, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, cache, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_frominput, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_criteria_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Criteria, setDI, arginfo_phalcon_mvc_model_criteria_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, setModelName, arginfo_phalcon_mvc_model_criteria_setmodelname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getModelName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, bind, arginfo_phalcon_mvc_model_criteria_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, bindTypes, arginfo_phalcon_mvc_model_criteria_bindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, columns, arginfo_phalcon_mvc_model_criteria_columns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, join, arginfo_phalcon_mvc_model_criteria_join, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, innerJoin, arginfo_phalcon_mvc_model_criteria_innerjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, leftJoin, arginfo_phalcon_mvc_model_criteria_leftjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, rightJoin, arginfo_phalcon_mvc_model_criteria_rightjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, where, arginfo_phalcon_mvc_model_criteria_where, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, addWhere, arginfo_phalcon_mvc_model_criteria_addwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, andWhere, arginfo_phalcon_mvc_model_criteria_andwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, orWhere, arginfo_phalcon_mvc_model_criteria_orwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, betweenWhere, arginfo_phalcon_mvc_model_criteria_betweenwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, notBetweenWhere, arginfo_phalcon_mvc_model_criteria_notbetweenwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, inWhere, arginfo_phalcon_mvc_model_criteria_inwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, notInWhere, arginfo_phalcon_mvc_model_criteria_notinwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, conditions, arginfo_phalcon_mvc_model_criteria_conditions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, order, arginfo_phalcon_mvc_model_criteria_order, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, orderBy, arginfo_phalcon_mvc_model_criteria_orderby, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, limit, arginfo_phalcon_mvc_model_criteria_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, forUpdate, arginfo_phalcon_mvc_model_criteria_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, sharedLock, arginfo_phalcon_mvc_model_criteria_sharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, cache, arginfo_phalcon_mvc_model_criteria_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getWhere, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getColumns, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getConditions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getLimit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getOrder, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, fromInput, arginfo_phalcon_mvc_model_criteria_frominput, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, execute, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
