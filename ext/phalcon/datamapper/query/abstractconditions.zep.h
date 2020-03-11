
extern zend_class_entry *phalcon_datamapper_query_abstractconditions_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_AbstractConditions);

PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, limit);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, offset);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, andWhere);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, appendWhere);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, orderBy);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, orWhere);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, where);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, whereEquals);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, addCondition);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, buildBy);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, buildCondition);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, buildLimitEarly);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, buildLimit);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, buildLimitCommon);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, buildLimitSqlsrv);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, appendCondition);
PHP_METHOD(Phalcon_DataMapper_Query_AbstractConditions, processValue);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_limit, 0, 1, Phalcon\\DataMapper\\Query\\AbstractConditions, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_limit, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\AbstractConditions", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, limit, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, limit)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_offset, 0, 1, Phalcon\\DataMapper\\Query\\AbstractConditions, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_offset, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\AbstractConditions", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, offset)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_andwhere, 0, 1, Phalcon\\DataMapper\\Query\\AbstractConditions, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_andwhere, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\AbstractConditions", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, condition, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, condition)
#endif
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_appendwhere, 0, 1, Phalcon\\DataMapper\\Query\\AbstractConditions, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_appendwhere, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\AbstractConditions", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, condition, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, condition)
#endif
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_orderby, 0, 1, Phalcon\\DataMapper\\Query\\AbstractConditions, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_orderby, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\AbstractConditions", 0)
#endif
	ZEND_ARG_INFO(0, orderBy)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_orwhere, 0, 1, Phalcon\\DataMapper\\Query\\AbstractConditions, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_orwhere, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\AbstractConditions", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, condition, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, condition)
#endif
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_where, 0, 1, Phalcon\\DataMapper\\Query\\AbstractConditions, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_where, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\AbstractConditions", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, condition, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, condition)
#endif
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_whereequals, 0, 1, Phalcon\\DataMapper\\Query\\AbstractConditions, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_whereequals, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Query\\AbstractConditions", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, columnsValues, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_addcondition, 0, 3, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_addcondition, 0, 3, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_addcondition, 0, 0, 3)
#define arginfo_phalcon_datamapper_query_abstractconditions_addcondition NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, store, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, store)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, andor, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, andor)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, condition, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, condition)
#endif
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_buildby, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_buildby, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_buildcondition, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_buildcondition, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_buildlimitearly, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_buildlimitearly, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_buildlimit, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_buildlimit, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_buildlimitcommon, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_buildlimitcommon, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_buildlimitsqlsrv, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_buildlimitsqlsrv, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_appendcondition, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_appendcondition, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_appendcondition, 0, 0, 2)
#define arginfo_phalcon_datamapper_query_abstractconditions_appendcondition NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, store, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, store)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, condition, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, condition)
#endif
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_processvalue, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_processvalue, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_query_abstractconditions_processvalue, 0, 0, 2)
#define arginfo_phalcon_datamapper_query_abstractconditions_processvalue NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, store, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, store)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_query_abstractconditions_method_entry) {
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, limit, arginfo_phalcon_datamapper_query_abstractconditions_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, offset, arginfo_phalcon_datamapper_query_abstractconditions_offset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, andWhere, arginfo_phalcon_datamapper_query_abstractconditions_andwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, appendWhere, arginfo_phalcon_datamapper_query_abstractconditions_appendwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, orderBy, arginfo_phalcon_datamapper_query_abstractconditions_orderby, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, orWhere, arginfo_phalcon_datamapper_query_abstractconditions_orwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, where, arginfo_phalcon_datamapper_query_abstractconditions_where, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, whereEquals, arginfo_phalcon_datamapper_query_abstractconditions_whereequals, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, addCondition, arginfo_phalcon_datamapper_query_abstractconditions_addcondition, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, buildBy, arginfo_phalcon_datamapper_query_abstractconditions_buildby, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, buildCondition, arginfo_phalcon_datamapper_query_abstractconditions_buildcondition, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, buildLimitEarly, arginfo_phalcon_datamapper_query_abstractconditions_buildlimitearly, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, buildLimit, arginfo_phalcon_datamapper_query_abstractconditions_buildlimit, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, buildLimitCommon, arginfo_phalcon_datamapper_query_abstractconditions_buildlimitcommon, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, buildLimitSqlsrv, arginfo_phalcon_datamapper_query_abstractconditions_buildlimitsqlsrv, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, appendCondition, arginfo_phalcon_datamapper_query_abstractconditions_appendcondition, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_DataMapper_Query_AbstractConditions, processValue, arginfo_phalcon_datamapper_query_abstractconditions_processvalue, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
