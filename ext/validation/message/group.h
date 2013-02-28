
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

extern zend_class_entry *phalcon_validation_message_group_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Message_Group);

PHP_METHOD(Phalcon_Validation_Message_Group, __construct);
PHP_METHOD(Phalcon_Validation_Message_Group, offsetGet);
PHP_METHOD(Phalcon_Validation_Message_Group, offsetSet);
PHP_METHOD(Phalcon_Validation_Message_Group, offsetExists);
PHP_METHOD(Phalcon_Validation_Message_Group, offsetUnset);
PHP_METHOD(Phalcon_Validation_Message_Group, appendMessage);
PHP_METHOD(Phalcon_Validation_Message_Group, count);
PHP_METHOD(Phalcon_Validation_Message_Group, rewind);
PHP_METHOD(Phalcon_Validation_Message_Group, current);
PHP_METHOD(Phalcon_Validation_Message_Group, key);
PHP_METHOD(Phalcon_Validation_Message_Group, next);
PHP_METHOD(Phalcon_Validation_Message_Group, valid);
PHP_METHOD(Phalcon_Validation_Message_Group, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_validation_message_group_method_entry){
	PHP_ME(Phalcon_Validation_Message_Group, __construct, arginfo_phalcon_validation_message_group___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Validation_Message_Group, offsetGet, arginfo_phalcon_validation_message_group_offsetget, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message_Group, offsetSet, arginfo_phalcon_validation_message_group_offsetset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message_Group, offsetExists, arginfo_phalcon_validation_message_group_offsetexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message_Group, offsetUnset, arginfo_phalcon_validation_message_group_offsetunset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message_Group, appendMessage, arginfo_phalcon_validation_message_group_appendmessage, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message_Group, count, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message_Group, rewind, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message_Group, current, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message_Group, key, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message_Group, next, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message_Group, valid, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message_Group, __set_state, arginfo_phalcon_validation_message_group___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};

