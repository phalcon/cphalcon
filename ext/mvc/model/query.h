
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_mvc_model_query_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query);

PHP_METHOD(Phalcon_Mvc_Model_Query, __construct);
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
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoins);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getOrderClause);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getGroupClause);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getLimitClause);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareInsert);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete);
PHP_METHOD(Phalcon_Mvc_Model_Query, parse);
PHP_METHOD(Phalcon_Mvc_Model_Query, cache);
PHP_METHOD(Phalcon_Mvc_Model_Query, getCacheOptions);
PHP_METHOD(Phalcon_Mvc_Model_Query, getCache);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeSelect);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeInsert);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getRelatedRecords);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeDelete);
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, phql)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setuniquerow, 0, 0, 1)
	ZEND_ARG_INFO(0, uniqueRow)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_cache, 0, 0, 1)
	ZEND_ARG_INFO(0, cacheOptions)
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
	ZEND_ARG_INFO(0, bindParams)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setbindtypes, 0, 0, 1)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setintermediate, 0, 0, 1)
	ZEND_ARG_INFO(0, intermediate)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_query_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Query, __construct, arginfo_phalcon_mvc_model_query___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Query, setDI, arginfo_phalcon_mvc_model_query_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, setUniqueRow, arginfo_phalcon_mvc_model_query_setuniquerow, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, getUniqueRow, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getQualified, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getCallArgument, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getFunctionCall, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getExpression, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getSelectColumn, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getTable, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoin, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoinType, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getSingleJoin, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getMultiJoin, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoins, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getOrderClause, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getGroupClause, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getLimitClause, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareSelect, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareInsert, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareUpdate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareDelete, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, parse, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, cache, arginfo_phalcon_mvc_model_query_cache, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, getCacheOptions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, getCache, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, _executeSelect, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _executeInsert, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getRelatedRecords, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _executeUpdate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _executeDelete, NULL, ZEND_ACC_PROTECTED) 
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
	PHP_FE_END
};

