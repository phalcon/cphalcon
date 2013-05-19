
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
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_mvc_model_query_builderinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_BuilderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_columns, 0, 0, 1)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_from, 0, 0, 1)
	ZEND_ARG_INFO(0, models)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_addfrom, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_join, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_andwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_orwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_betweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_inwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, orderBy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_having, 0, 0, 1)
	ZEND_ARG_INFO(0, having)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_groupby, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_query_builderinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, __construct, arginfo_phalcon_mvc_model_query_builderinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, columns, arginfo_phalcon_mvc_model_query_builderinterface_columns)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, from, arginfo_phalcon_mvc_model_query_builderinterface_from)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, addFrom, arginfo_phalcon_mvc_model_query_builderinterface_addfrom)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getFrom, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, join, arginfo_phalcon_mvc_model_query_builderinterface_join)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, where, arginfo_phalcon_mvc_model_query_builderinterface_where)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, andWhere, arginfo_phalcon_mvc_model_query_builderinterface_andwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, orWhere, arginfo_phalcon_mvc_model_query_builderinterface_orwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, betweenWhere, arginfo_phalcon_mvc_model_query_builderinterface_betweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, inWhere, arginfo_phalcon_mvc_model_query_builderinterface_inwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getWhere, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, orderBy, arginfo_phalcon_mvc_model_query_builderinterface_orderby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getOrderBy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, having, arginfo_phalcon_mvc_model_query_builderinterface_having)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getHaving, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, limit, arginfo_phalcon_mvc_model_query_builderinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getLimit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, groupBy, arginfo_phalcon_mvc_model_query_builderinterface_groupby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getGroupBy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getPhql, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getQuery, NULL)
	PHP_FE_END
};

