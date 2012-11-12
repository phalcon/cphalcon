
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

extern zend_class_entry *phalcon_logger_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Adapter);

PHP_METHOD(Phalcon_Logger_Adapter, getTypeString);
PHP_METHOD(Phalcon_Logger_Adapter, debug);
PHP_METHOD(Phalcon_Logger_Adapter, error);
PHP_METHOD(Phalcon_Logger_Adapter, info);
PHP_METHOD(Phalcon_Logger_Adapter, notice);
PHP_METHOD(Phalcon_Logger_Adapter, warning);
PHP_METHOD(Phalcon_Logger_Adapter, alert);
PHP_METHOD(Phalcon_Logger_Adapter, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_gettypestring, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_log, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_logger_adapter_method_entry){
	PHP_ME(Phalcon_Logger_Adapter, getTypeString, arginfo_phalcon_logger_adapter_gettypestring, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, debug, arginfo_phalcon_logger_adapter_debug, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, error, arginfo_phalcon_logger_adapter_error, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, info, arginfo_phalcon_logger_adapter_info, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, notice, arginfo_phalcon_logger_adapter_notice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, warning, arginfo_phalcon_logger_adapter_warning, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, alert, arginfo_phalcon_logger_adapter_alert, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, log, arginfo_phalcon_logger_adapter_log, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

