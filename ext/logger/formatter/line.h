
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

extern zend_class_entry *phalcon_logger_formatter_line_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Formatter_Line);

PHP_METHOD(Phalcon_Logger_Formatter_Line, __construct);
PHP_METHOD(Phalcon_Logger_Formatter_Line, setFormat);
PHP_METHOD(Phalcon_Logger_Formatter_Line, getFormat);
PHP_METHOD(Phalcon_Logger_Formatter_Line, setDateFormat);
PHP_METHOD(Phalcon_Logger_Formatter_Line, getDateFormat);
PHP_METHOD(Phalcon_Logger_Formatter_Line, format);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_line___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, format)
	ZEND_ARG_INFO(0, dateFormat)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_line_setformat, 0, 0, 1)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_line_setdateformat, 0, 0, 1)
	ZEND_ARG_INFO(0, date)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_line_format, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, timestamp)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_logger_formatter_line_method_entry){
	PHP_ME(Phalcon_Logger_Formatter_Line, __construct, arginfo_phalcon_logger_formatter_line___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Logger_Formatter_Line, setFormat, arginfo_phalcon_logger_formatter_line_setformat, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Formatter_Line, getFormat, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Formatter_Line, setDateFormat, arginfo_phalcon_logger_formatter_line_setdateformat, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Formatter_Line, getDateFormat, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Formatter_Line, format, arginfo_phalcon_logger_formatter_line_format, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

