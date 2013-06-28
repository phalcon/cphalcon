
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

extern zend_class_entry *phalcon_mvc_model_behavior_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Behavior);

PHP_METHOD(Phalcon_Mvc_Model_Behavior, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Behavior, mustTakeAction);
PHP_METHOD(Phalcon_Mvc_Model_Behavior, getOptions);
PHP_METHOD(Phalcon_Mvc_Model_Behavior, notify);
PHP_METHOD(Phalcon_Mvc_Model_Behavior, missingMethod);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_missingmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_behavior_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Behavior, __construct, arginfo_phalcon_mvc_model_behavior___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Behavior, mustTakeAction, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Behavior, getOptions, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Behavior, notify, arginfo_phalcon_mvc_model_behavior_notify, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Behavior, missingMethod, arginfo_phalcon_mvc_model_behavior_missingmethod, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

