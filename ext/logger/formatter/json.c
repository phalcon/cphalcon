
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
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"

/**
 * Phalcon\Logger\Formatter\Json
 *
 * Formats messages using JSON encoding
 */


/**
 * Phalcon\Logger\Formatter\Json initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Formatter_Json){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Json, logger_formatter_json, phalcon_logger_formatter_ce, phalcon_logger_formatter_json_method_entry, 0);

	zend_class_implements(phalcon_logger_formatter_json_ce TSRMLS_CC, 1, phalcon_logger_formatterinterface_ce);

	return SUCCESS;
}

/**
 * Applies a format to a message before sent it to the internal log
 *
 * @param string $message
 * @param int $type
 * @param int $timestamp
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, format){

	zval *message, *type, *timestamp, *type_str, *log;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &message, &type, &timestamp);
	
	PHALCON_INIT_VAR(type_str);
	phalcon_call_method_p1(type_str, this_ptr, "gettypestring", type);
	
	PHALCON_INIT_VAR(log);
	array_init_size(log, 3);
	phalcon_array_update_string(&log, SL("type"), &type_str, PH_COPY | PH_SEPARATE);
	phalcon_array_update_string(&log, SL("message"), &message, PH_COPY | PH_SEPARATE);
	phalcon_array_update_string(&log, SL("timestamp"), &timestamp, PH_COPY | PH_SEPARATE);
	phalcon_json_encode(return_value, return_value_ptr, log, 0 TSRMLS_CC);
	RETURN_MM();
}

