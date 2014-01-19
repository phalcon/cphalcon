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

#include "logger/formatter.h"
#include "kernel/main.h"

/**
 * Phalcon\Logger\Formatter
 *
 * This is a base class for logger formatters
 */
zend_class_entry *phalcon_logger_formatter_ce;

PHP_METHOD(Phalcon_Logger_Formatter, getTypeString);

static const zend_function_entry phalcon_logger_formatter_method_entry[] = {
	PHP_ME(Phalcon_Logger_Formatter, getTypeString, arginfo_phalcon_logger_formatter_gettypestring, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Logger\Formatter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Formatter){

	PHALCON_REGISTER_CLASS(Phalcon\\Logger, Formatter, logger_formatter, phalcon_logger_formatter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;
}

/**
 * Returns the string meaning of a logger constant
 *
 * @param  integer $type
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter, getTypeString){

	static const char *lut[10] = {
		"EMERGENCY", "CRITICAL", "ALERT", "ERROR",  "WARNING",
		"NOTICE",    "INFO",     "DEBUG", "CUSTOM", "SPECIAL"
	};

	zval **type;
	int itype;

	phalcon_fetch_params_ex(1, 0, &type);
	PHALCON_ENSURE_IS_LONG(type);
	
	itype = Z_LVAL_PP(type);
	if (itype >= 0 && itype < 10) {
		RETURN_STRING(lut[itype], 1);
	}
	
	RETURN_STRING("CUSTOM", 1);
}
