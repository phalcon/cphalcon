
extern zend_class_entry *phalcon_mvc_model_query_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query);

PHP_METHOD(Phalcon_Mvc_Model_Query, getTransaction);
PHP_METHOD(Phalcon_Mvc_Model_Query, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Query, cache);
PHP_METHOD(Phalcon_Mvc_Model_Query, clean);
PHP_METHOD(Phalcon_Mvc_Model_Query, execute);
PHP_METHOD(Phalcon_Mvc_Model_Query, getCache);
PHP_METHOD(Phalcon_Mvc_Model_Query, getCacheOptions);
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindParams);
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindTypes);
PHP_METHOD(Phalcon_Mvc_Model_Query, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Query, getIntermediate);
PHP_METHOD(Phalcon_Mvc_Model_Query, getSingleResult);
PHP_METHOD(Phalcon_Mvc_Model_Query, getSql);
PHP_METHOD(Phalcon_Mvc_Model_Query, getType);
PHP_METHOD(Phalcon_Mvc_Model_Query, getUniqueRow);
PHP_METHOD(Phalcon_Mvc_Model_Query, parse);
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindParams);
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindTypes);
PHP_METHOD(Phalcon_Mvc_Model_Query, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Query, setIntermediate);
PHP_METHOD(Phalcon_Mvc_Model_Query, setSharedLock);
PHP_METHOD(Phalcon_Mvc_Model_Query, setTransaction);
PHP_METHOD(Phalcon_Mvc_Model_Query, setType);
PHP_METHOD(Phalcon_Mvc_Model_Query, setUniqueRow);
PHP_METHOD(Phalcon_Mvc_Model_Query, executeDelete);
PHP_METHOD(Phalcon_Mvc_Model_Query, executeInsert);
PHP_METHOD(Phalcon_Mvc_Model_Query, executeSelect);
PHP_METHOD(Phalcon_Mvc_Model_Query, executeUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Query, getCallArgument);
PHP_METHOD(Phalcon_Mvc_Model_Query, getCaseExpression);
PHP_METHOD(Phalcon_Mvc_Model_Query, getExpression);
PHP_METHOD(Phalcon_Mvc_Model_Query, getFunctionCall);
PHP_METHOD(Phalcon_Mvc_Model_Query, getGroupClause);
PHP_METHOD(Phalcon_Mvc_Model_Query, getLimitClause);
PHP_METHOD(Phalcon_Mvc_Model_Query, getJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query, getJoinType);
PHP_METHOD(Phalcon_Mvc_Model_Query, getJoins);
PHP_METHOD(Phalcon_Mvc_Model_Query, getMultiJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query, getOrderClause);
PHP_METHOD(Phalcon_Mvc_Model_Query, getQualified);
PHP_METHOD(Phalcon_Mvc_Model_Query, getReadConnection);
PHP_METHOD(Phalcon_Mvc_Model_Query, getRelatedRecords);
PHP_METHOD(Phalcon_Mvc_Model_Query, getSelectColumn);
PHP_METHOD(Phalcon_Mvc_Model_Query, getSingleJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query, getTable);
PHP_METHOD(Phalcon_Mvc_Model_Query, getWriteConnection);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareInsert);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareUpdate);
zend_object *zephir_init_properties_Phalcon_Mvc_Model_Query(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_gettransaction, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, phql, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 1)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_cache, 0, 1, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, cacheOptions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_clean, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_execute, 0, 0, 0)
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

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_getcache, 0, 0, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getcacheoptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getbindparams, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getbindtypes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_getdi, 0, 0, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getintermediate, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_getsingleresult, 0, 0, Phalcon\\Mvc\\ModelInterface, 0)
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

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getsql, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_gettype, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getuniquerow, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_parse, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_setbindparams, 0, 1, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_setbindtypes, 0, 1, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_setdi, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_setintermediate, 0, 1, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, intermediate, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_setsharedlock, 0, 0, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_TYPE_INFO(0, sharedLock, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_settransaction, 0, 1, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_settype, 0, 1, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_setuniquerow, 0, 1, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_TYPE_INFO(0, uniqueRow, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_executedelete, 0, 3, Phalcon\\Mvc\\Model\\Query\\StatusInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, intermediate, 0)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_executeinsert, 0, 3, Phalcon\\Mvc\\Model\\Query\\StatusInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, intermediate, 0)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_executeselect, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, intermediate, 0)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
	ZEND_ARG_TYPE_INFO(0, simulate, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_executeupdate, 0, 3, Phalcon\\Mvc\\Model\\Query\\StatusInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, intermediate, 0)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getcallargument, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, argument, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getcaseexpression, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getexpression, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
	ZEND_ARG_TYPE_INFO(0, quoting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getfunctioncall, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getgroupclause, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, group, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getlimitclause, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, limitClause, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getjoin, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, manager, Phalcon\\Mvc\\Model\\ManagerInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, join, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getjointype, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, join, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getjoins, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, select, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getmultijoin, 0, 5, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, joinType, IS_STRING, 0)
	ZEND_ARG_INFO(0, joinSource)
	ZEND_ARG_TYPE_INFO(0, modelAlias, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, joinAlias, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, relation, Phalcon\\Mvc\\Model\\RelationInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getorderclause, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, order)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getqualified, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_getreadconnection, 0, 1, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, intermediate, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, intermediate, 1)
#endif
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

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_getrelatedrecords, 0, 4, Phalcon\\Mvc\\Model\\ResultsetInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, intermediate, 0)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getselectcolumn, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, column, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_getsinglejoin, 0, 5, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, joinType, IS_STRING, 0)
	ZEND_ARG_INFO(0, joinSource)
	ZEND_ARG_TYPE_INFO(0, modelAlias, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, joinAlias, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, relation, Phalcon\\Mvc\\Model\\RelationInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_gettable, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, manager, Phalcon\\Mvc\\Model\\ManagerInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, qualifiedName, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query_getwriteconnection, 0, 1, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, intermediate, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, intermediate, 1)
#endif
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

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query__preparedelete, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query__prepareinsert, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query__prepareselect, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, ast)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query__prepareupdate, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_zephir_init_properties_phalcon_mvc_model_query, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Query, getTransaction, arginfo_phalcon_mvc_model_query_gettransaction, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Model_Query, getTransaction, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Model_Query, __construct, arginfo_phalcon_mvc_model_query___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Query, cache, arginfo_phalcon_mvc_model_query_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, clean, arginfo_phalcon_mvc_model_query_clean, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model_Query, execute, arginfo_phalcon_mvc_model_query_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getCache, arginfo_phalcon_mvc_model_query_getcache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getCacheOptions, arginfo_phalcon_mvc_model_query_getcacheoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getBindParams, arginfo_phalcon_mvc_model_query_getbindparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getBindTypes, arginfo_phalcon_mvc_model_query_getbindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getDI, arginfo_phalcon_mvc_model_query_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getIntermediate, arginfo_phalcon_mvc_model_query_getintermediate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getSingleResult, arginfo_phalcon_mvc_model_query_getsingleresult, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getSql, arginfo_phalcon_mvc_model_query_getsql, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getType, arginfo_phalcon_mvc_model_query_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getUniqueRow, arginfo_phalcon_mvc_model_query_getuniquerow, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, parse, arginfo_phalcon_mvc_model_query_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setBindParams, arginfo_phalcon_mvc_model_query_setbindparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setBindTypes, arginfo_phalcon_mvc_model_query_setbindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setDI, arginfo_phalcon_mvc_model_query_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setIntermediate, arginfo_phalcon_mvc_model_query_setintermediate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setSharedLock, arginfo_phalcon_mvc_model_query_setsharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setTransaction, arginfo_phalcon_mvc_model_query_settransaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setType, arginfo_phalcon_mvc_model_query_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setUniqueRow, arginfo_phalcon_mvc_model_query_setuniquerow, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, executeDelete, arginfo_phalcon_mvc_model_query_executedelete, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, executeInsert, arginfo_phalcon_mvc_model_query_executeinsert, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, executeSelect, arginfo_phalcon_mvc_model_query_executeselect, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, executeUpdate, arginfo_phalcon_mvc_model_query_executeupdate, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getCallArgument, arginfo_phalcon_mvc_model_query_getcallargument, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getCaseExpression, arginfo_phalcon_mvc_model_query_getcaseexpression, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getExpression, arginfo_phalcon_mvc_model_query_getexpression, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getFunctionCall, arginfo_phalcon_mvc_model_query_getfunctioncall, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getGroupClause, arginfo_phalcon_mvc_model_query_getgroupclause, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getLimitClause, arginfo_phalcon_mvc_model_query_getlimitclause, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getJoin, arginfo_phalcon_mvc_model_query_getjoin, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getJoinType, arginfo_phalcon_mvc_model_query_getjointype, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getJoins, arginfo_phalcon_mvc_model_query_getjoins, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getMultiJoin, arginfo_phalcon_mvc_model_query_getmultijoin, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getOrderClause, arginfo_phalcon_mvc_model_query_getorderclause, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getQualified, arginfo_phalcon_mvc_model_query_getqualified, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getReadConnection, arginfo_phalcon_mvc_model_query_getreadconnection, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getRelatedRecords, arginfo_phalcon_mvc_model_query_getrelatedrecords, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getSelectColumn, arginfo_phalcon_mvc_model_query_getselectcolumn, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getSingleJoin, arginfo_phalcon_mvc_model_query_getsinglejoin, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getTable, arginfo_phalcon_mvc_model_query_gettable, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, getWriteConnection, arginfo_phalcon_mvc_model_query_getwriteconnection, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareDelete, arginfo_phalcon_mvc_model_query__preparedelete, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareInsert, arginfo_phalcon_mvc_model_query__prepareinsert, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareSelect, arginfo_phalcon_mvc_model_query__prepareselect, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareUpdate, arginfo_phalcon_mvc_model_query__prepareupdate, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
