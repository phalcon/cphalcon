
extern zend_class_entry *phalcon_mvc_model_query_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query);

PHP_METHOD(Phalcon_Mvc_Model_Query, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Query, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Query, setUniqueRow);
PHP_METHOD(Phalcon_Mvc_Model_Query, getUniqueRow);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getQualified);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCallArgument);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getFunctionCall);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getExpression);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSelectColumn);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getTable);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoinType);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSingleJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getMultiJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query, cache);
PHP_METHOD(Phalcon_Mvc_Model_Query, getCacheOptions);
PHP_METHOD(Phalcon_Mvc_Model_Query, execute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setuniquerow, 0, 0, 1)
	ZEND_ARG_INFO(0, uniqueRow)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getqualified, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getcallargument, 0, 0, 1)
	ZEND_ARG_INFO(0, argument)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getfunctioncall, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getexpression, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, quoting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getselectcolumn, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__gettable, 0, 0, 2)
	ZEND_ARG_INFO(0, manager)
	ZEND_ARG_INFO(0, qualifiedName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getjoin, 0, 0, 2)
	ZEND_ARG_INFO(0, manager)
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
	ZEND_ARG_INFO(0, relation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getmultijoin, 0, 0, 5)
	ZEND_ARG_INFO(0, joinType)
	ZEND_ARG_INFO(0, joinSource)
	ZEND_ARG_INFO(0, modelAlias)
	ZEND_ARG_INFO(0, joinAlias)
	ZEND_ARG_INFO(0, relation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_cache, 0, 0, 1)
	ZEND_ARG_INFO(0, cacheOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_execute, 0, 0, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Query, setDI, arginfo_phalcon_mvc_model_query_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setUniqueRow, arginfo_phalcon_mvc_model_query_setuniquerow, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getUniqueRow, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, _getQualified, arginfo_phalcon_mvc_model_query__getqualified, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getCallArgument, arginfo_phalcon_mvc_model_query__getcallargument, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getFunctionCall, arginfo_phalcon_mvc_model_query__getfunctioncall, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getExpression, arginfo_phalcon_mvc_model_query__getexpression, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getSelectColumn, arginfo_phalcon_mvc_model_query__getselectcolumn, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getTable, arginfo_phalcon_mvc_model_query__gettable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoin, arginfo_phalcon_mvc_model_query__getjoin, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoinType, arginfo_phalcon_mvc_model_query__getjointype, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getSingleJoin, arginfo_phalcon_mvc_model_query__getsinglejoin, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getMultiJoin, arginfo_phalcon_mvc_model_query__getmultijoin, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, cache, arginfo_phalcon_mvc_model_query_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getCacheOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, execute, arginfo_phalcon_mvc_model_query_execute, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
