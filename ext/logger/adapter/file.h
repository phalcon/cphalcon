
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

extern zend_class_entry *phalcon_logger_adapter_file_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Adapter_File);

PHP_METHOD(Phalcon_Logger_Adapter_File, __construct);
PHP_METHOD(Phalcon_Logger_Adapter_File, getFormatter);
PHP_METHOD(Phalcon_Logger_Adapter_File, logInternal);
PHP_METHOD(Phalcon_Logger_Adapter_File, close);
PHP_METHOD(Phalcon_Logger_Adapter_File, __wakeup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_file_loginternal, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, time)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_logger_adapter_file_method_entry){
	PHP_ME(Phalcon_Logger_Adapter_File, __construct, arginfo_phalcon_logger_adapter_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Logger_Adapter_File, getFormatter, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter_File, logInternal, arginfo_phalcon_logger_adapter_file_loginternal, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter_File, close, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter_File, __wakeup, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

