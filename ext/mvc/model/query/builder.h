
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

extern zend_class_entry *phalcon_mvc_model_query_builder_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_Builder);

PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setColumns);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getColumns);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setModels);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getModels);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setConditions);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getConditions);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setHaving);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getHaving);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setLimit);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getLimit);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setGroup);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getGroup);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getPhql);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getQuery);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_setcolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_setmodels, 0, 0, 1)
	ZEND_ARG_INFO(0, models)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_setconditions, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_sethaving, 0, 0, 1)
	ZEND_ARG_INFO(0, having)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_setlimit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_setgroup, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_query_builder_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, __construct, arginfo_phalcon_mvc_model_query_builder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, setDI, arginfo_phalcon_mvc_model_query_builder_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, setColumns, arginfo_phalcon_mvc_model_query_builder_setcolumns, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getColumns, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, setModels, arginfo_phalcon_mvc_model_query_builder_setmodels, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getModels, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, setConditions, arginfo_phalcon_mvc_model_query_builder_setconditions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getConditions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, setHaving, arginfo_phalcon_mvc_model_query_builder_sethaving, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getHaving, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, setLimit, arginfo_phalcon_mvc_model_query_builder_setlimit, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getLimit, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, setGroup, arginfo_phalcon_mvc_model_query_builder_setgroup, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getGroup, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getPhql, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getQuery, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

