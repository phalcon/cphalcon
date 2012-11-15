
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

extern zend_class_entry *phalcon_mvc_model_validator_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator);

PHP_METHOD(Phalcon_Mvc_Model_Validator, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Validator, appendMessage);
PHP_METHOD(Phalcon_Mvc_Model_Validator, getMessages);
PHP_METHOD(Phalcon_Mvc_Model_Validator, getOptions);
PHP_METHOD(Phalcon_Mvc_Model_Validator, getOption);
PHP_METHOD(Phalcon_Mvc_Model_Validator, isSetOption);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_validator_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Validator, __construct, arginfo_phalcon_mvc_model_validator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Validator, appendMessage, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Validator, getMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Validator, getOptions, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Validator, getOption, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Validator, isSetOption, NULL, ZEND_ACC_PROTECTED) 
	PHP_FE_END
};

