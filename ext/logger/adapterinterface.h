
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

extern zend_class_entry *phalcon_logger_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_setformat, 0, 0, 1)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_gettypestring, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_setdateformat, 0, 0, 1)
	ZEND_ARG_INFO(0, date)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_log, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_logger_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, setFormat, arginfo_phalcon_logger_adapterinterface_setformat)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, getFormat, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, getTypeString, arginfo_phalcon_logger_adapterinterface_gettypestring)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, setDateFormat, arginfo_phalcon_logger_adapterinterface_setdateformat)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, getDateFormat, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, log, arginfo_phalcon_logger_adapterinterface_log)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, begin, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, rollback, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, close, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, debug, arginfo_phalcon_logger_adapterinterface_debug)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, error, arginfo_phalcon_logger_adapterinterface_error)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, info, arginfo_phalcon_logger_adapterinterface_info)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, notice, arginfo_phalcon_logger_adapterinterface_notice)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, warning, arginfo_phalcon_logger_adapterinterface_warning)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, alert, arginfo_phalcon_logger_adapterinterface_alert)
	PHP_FE_END
};

