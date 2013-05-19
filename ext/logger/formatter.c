
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/operators.h"

/**
 * Phalcon\Logger\Formatter
 *
 * This is a base class for logger formatters
 */


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

	zval *type, *type_str = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &type);
	
	
	switch (phalcon_get_intval(type)) {
	
		case 7:
			PHALCON_INIT_VAR(type_str);
			ZVAL_STRING(type_str, "DEBUG", 1);
			break;
	
		case 3:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "ERROR", 1);
			break;
	
		case 4:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "WARNING", 1);
			break;
	
		case 1:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "CRITICAL", 1);
			break;
	
		case 8:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "CUSTOM", 1);
			break;
	
		case 2:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "ALERT", 1);
			break;
	
		case 5:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "NOTICE", 1);
			break;
	
		case 6:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "INFO", 1);
			break;
	
		case 0:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "EMERGENCE", 1);
			break;
	
		case 9:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "SPECIAL", 1);
			break;
	
		default:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "CUSTOM", 1);
	
	}
	RETURN_CTOR(type_str);
}

