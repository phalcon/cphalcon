
extern zend_class_entry *phalcon_mvc_model_query_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query);

PHP_METHOD(Phalcon_Mvc_Model_Query, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Query, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Query, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Query, setUniqueRow);
PHP_METHOD(Phalcon_Mvc_Model_Query, getUniqueRow);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getQualified);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCallArgument);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCaseExpression);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getFunctionCall);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getExpression);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSelectColumn);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getTable);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoinType);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSingleJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getMultiJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoins);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getOrderClause);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getGroupClause);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getLimitClause);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareInsert);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete);
PHP_METHOD(Phalcon_Mvc_Model_Query, parse);
PHP_METHOD(Phalcon_Mvc_Model_Query, getCache);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeSelect);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeInsert);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeDelete);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getRelatedRecords);
PHP_METHOD(Phalcon_Mvc_Model_Query, execute);
PHP_METHOD(Phalcon_Mvc_Model_Query, getSingleResult);
PHP_METHOD(Phalcon_Mvc_Model_Query, setType);
PHP_METHOD(Phalcon_Mvc_Model_Query, getType);
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindParams);
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindParams);
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindTypes);
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindTypes);
PHP_METHOD(Phalcon_Mvc_Model_Query, setIntermediate);
PHP_METHOD(Phalcon_Mvc_Model_Query, getIntermediate);
PHP_METHOD(Phalcon_Mvc_Model_Query, cache);
PHP_METHOD(Phalcon_Mvc_Model_Query, getCacheOptions);
PHP_METHOD(Phalcon_Mvc_Model_Query, getSql);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, phql)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setuniquerow, 0, 0, 1)
	ZEND_ARG_INFO(0, uniqueRow)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getqualified, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getcallargument, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, argument, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getcaseexpression, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getfunctioncall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getexpression, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, quoting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getselectcolumn, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, column, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__gettable, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, manager, Phalcon\\Mvc\\Model\\ManagerInterface, 0)
	ZEND_ARG_INFO(0, qualifiedName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getjoin, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, manager, Phalcon\\Mvc\\Model\\ManagerInterface, 0)
	ZEND_ARG_INFO(0, join)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getjointype, 0, 0, 1)
	ZEND_ARG_INFO(0, join)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getsinglejoin, 0, 0, 5)
	ZEND_ARG_INFO(0, joinType)
	ZEND_ARG_INFO(0, joinSource)
	ZEND_ARG_INFO(0, modelAlias)
	ZEND_ARG_INFO(0, joinAlias)
	ZEND_ARG_OBJ_INFO(0, relation, Phalcon\\Mvc\\Model\\RelationInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getmultijoin, 0, 0, 5)
	ZEND_ARG_INFO(0, joinType)
	ZEND_ARG_INFO(0, joinSource)
	ZEND_ARG_INFO(0, modelAlias)
	ZEND_ARG_INFO(0, joinAlias)
	ZEND_ARG_OBJ_INFO(0, relation, Phalcon\\Mvc\\Model\\RelationInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getjoins, 0, 0, 1)
	ZEND_ARG_INFO(0, select)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getorderclause, 0, 0, 1)
	ZEND_ARG_INFO(0, order)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getgroupclause, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getlimitclause, 0, 0, 1)
	ZEND_ARG_INFO(0, limitClause)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__prepareselect, 0, 0, 0)
	ZEND_ARG_INFO(0, ast)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__executeselect, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediate)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
	ZEND_ARG_INFO(0, simulate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__executeinsert, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediate)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__executeupdate, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediate)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__executedelete, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediate)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getrelatedrecords, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, intermediate)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_execute, 0, 0, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_getsingleresult, 0, 0, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setbindparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setbindtypes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setintermediate, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, intermediate, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_cache, 0, 0, 1)
	ZEND_ARG_INFO(0, cacheOptions)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Query, __construct, arginfo_phalcon_mvc_model_query___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Query, setDI, arginfo_phalcon_mvc_model_query_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setUniqueRow, arginfo_phalcon_mvc_model_query_setuniquerow, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getUniqueRow, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, _getQualified, arginfo_phalcon_mvc_model_query__getqualified, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getCallArgument, arginfo_phalcon_mvc_model_query__getcallargument, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getCaseExpression, arginfo_phalcon_mvc_model_query__getcaseexpression, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getFunctionCall, arginfo_phalcon_mvc_model_query__getfunctioncall, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getExpression, arginfo_phalcon_mvc_model_query__getexpression, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getSelectColumn, arginfo_phalcon_mvc_model_query__getselectcolumn, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getTable, arginfo_phalcon_mvc_model_query__gettable, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoin, arginfo_phalcon_mvc_model_query__getjoin, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoinType, arginfo_phalcon_mvc_model_query__getjointype, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getSingleJoin, arginfo_phalcon_mvc_model_query__getsinglejoin, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getMultiJoin, arginfo_phalcon_mvc_model_query__getmultijoin, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoins, arginfo_phalcon_mvc_model_query__getjoins, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getOrderClause, arginfo_phalcon_mvc_model_query__getorderclause, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getGroupClause, arginfo_phalcon_mvc_model_query__getgroupclause, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getLimitClause, arginfo_phalcon_mvc_model_query__getlimitclause, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareSelect, arginfo_phalcon_mvc_model_query__prepareselect, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareInsert, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareUpdate, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareDelete, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, parse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getCache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, _executeSelect, arginfo_phalcon_mvc_model_query__executeselect, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _executeInsert, arginfo_phalcon_mvc_model_query__executeinsert, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _executeUpdate, arginfo_phalcon_mvc_model_query__executeupdate, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _executeDelete, arginfo_phalcon_mvc_model_query__executedelete, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getRelatedRecords, arginfo_phalcon_mvc_model_query__getrelatedrecords, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, execute, arginfo_phalcon_mvc_model_query_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getSingleResult, arginfo_phalcon_mvc_model_query_getsingleresult, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setType, arginfo_phalcon_mvc_model_query_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setBindParams, arginfo_phalcon_mvc_model_query_setbindparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getBindParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setBindTypes, arginfo_phalcon_mvc_model_query_setbindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getBindTypes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setIntermediate, arginfo_phalcon_mvc_model_query_setintermediate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getIntermediate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, cache, arginfo_phalcon_mvc_model_query_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getCacheOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getSql, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
