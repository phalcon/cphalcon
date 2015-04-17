
<<<<<<< HEAD:ext/phalcon/logger/multiple.zep.h
extern zend_class_entry *phalcon_logger_multiple_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Multiple);

PHP_METHOD(Phalcon_Logger_Multiple, getLoggers);
PHP_METHOD(Phalcon_Logger_Multiple, getFormatter);
PHP_METHOD(Phalcon_Logger_Multiple, push);
PHP_METHOD(Phalcon_Logger_Multiple, setFormatter);
PHP_METHOD(Phalcon_Logger_Multiple, log);
PHP_METHOD(Phalcon_Logger_Multiple, emergency);
PHP_METHOD(Phalcon_Logger_Multiple, debug);
PHP_METHOD(Phalcon_Logger_Multiple, error);
PHP_METHOD(Phalcon_Logger_Multiple, info);
PHP_METHOD(Phalcon_Logger_Multiple, notice);
PHP_METHOD(Phalcon_Logger_Multiple, warning);
PHP_METHOD(Phalcon_Logger_Multiple, alert);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_push, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, logger, Phalcon\\Logger\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_setformatter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, formatter, Phalcon\\Logger\\FormatterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_log, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()
=======
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#ifndef PHALCON_LOGGER_MULTIPLE_H
#define PHALCON_LOGGER_MULTIPLE_H

#include "php_phalcon.h"
>>>>>>> master:ext/logger/multiple.h

extern zend_class_entry *phalcon_logger_multiple_ce;

<<<<<<< HEAD:ext/phalcon/logger/multiple.zep.h
ZEPHIR_INIT_FUNCS(phalcon_logger_multiple_method_entry) {
	PHP_ME(Phalcon_Logger_Multiple, getLoggers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, getFormatter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, push, arginfo_phalcon_logger_multiple_push, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, setFormatter, arginfo_phalcon_logger_multiple_setformatter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, log, arginfo_phalcon_logger_multiple_log, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, emergency, arginfo_phalcon_logger_multiple_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, debug, arginfo_phalcon_logger_multiple_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, error, arginfo_phalcon_logger_multiple_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, info, arginfo_phalcon_logger_multiple_info, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, notice, arginfo_phalcon_logger_multiple_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, warning, arginfo_phalcon_logger_multiple_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, alert, arginfo_phalcon_logger_multiple_alert, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
=======
PHALCON_INIT_CLASS(Phalcon_Logger_Multiple);

#endif /* PHALCON_LOGGER_MULTIPLE_H */
>>>>>>> master:ext/logger/multiple.h
