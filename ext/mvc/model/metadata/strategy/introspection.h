
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

extern zend_class_entry *phalcon_mvc_model_metadata_strategy_introspection_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Introspection);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, get);

PHALCON_INIT_FUNCS(phalcon_mvc_model_metadata_strategy_introspection_method_entry){
	PHP_ME(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, get, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

