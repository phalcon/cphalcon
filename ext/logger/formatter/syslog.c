
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

#include "kernel/array.h"

/**
 * Phalcon\Logger\Formatter\Syslog
 *
 * Prepares a message to be used in a Syslog backend
 */


/**
 * Phalcon\Logger\Formatter\Syslog initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Formatter_Syslog){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Syslog, logger_formatter_syslog, "phalcon\\logger\\formatter", phalcon_logger_formatter_syslog_method_entry, 0);

	zend_class_implements(phalcon_logger_formatter_syslog_ce TSRMLS_CC, 1, phalcon_logger_formatterinterface_ce);

	return SUCCESS;
}

/**
 * Applies a format to a message before sent it to the internal log
 *
 * @param string $message
 * @param int $type
 * @param int $timestamp
 * @return array
 */
PHP_METHOD(Phalcon_Logger_Formatter_Syslog, format){

	zval *message, *type, *timestamp, *log;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &message, &type, &timestamp);
	
	PHALCON_INIT_VAR(log);
	array_init_size(log, 2);
	phalcon_array_append(&log, type, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&log, message, PH_SEPARATE TSRMLS_CC);
	RETURN_CTOR(log);
}

