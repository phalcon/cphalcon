
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

extern zend_class_entry *phalcon_validation_message_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Message);

PHP_METHOD(Phalcon_Validation_Message, __construct);
PHP_METHOD(Phalcon_Validation_Message, setType);
PHP_METHOD(Phalcon_Validation_Message, getType);
PHP_METHOD(Phalcon_Validation_Message, setCode);
PHP_METHOD(Phalcon_Validation_Message, getCode);
PHP_METHOD(Phalcon_Validation_Message, setMessage);
PHP_METHOD(Phalcon_Validation_Message, getMessage);
PHP_METHOD(Phalcon_Validation_Message, setField);
PHP_METHOD(Phalcon_Validation_Message, getField);
PHP_METHOD(Phalcon_Validation_Message, __toString);
PHP_METHOD(Phalcon_Validation_Message, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_setcode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_validation_message_method_entry){
	PHP_ME(Phalcon_Validation_Message, __construct, arginfo_phalcon_validation_message___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Validation_Message, setType, arginfo_phalcon_validation_message_settype, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message, getType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message, setCode, arginfo_phalcon_validation_message_setcode, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message, getCode, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message, setMessage, arginfo_phalcon_validation_message_setmessage, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message, getMessage, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message, setField, arginfo_phalcon_validation_message_setfield, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message, getField, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message, __toString, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Message, __set_state, arginfo_phalcon_validation_message___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};

