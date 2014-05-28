
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

#include "logger/formatter/json.h"
#include "logger/formatter.h"
#include "logger/formatterinterface.h"

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
zend_class_entry *phalcon_logger_formatter_json_ce;

PHP_METHOD(Phalcon_Logger_Formatter_Json, format);

static const zend_function_entry phalcon_logger_formatter_json_method_entry[] = {
	PHP_ME(Phalcon_Logger_Formatter_Json, format, arginfo_phalcon_logger_formatterinterface_format, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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
 * @param array $context
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, format){

	zval *message, *type, *timestamp, *context, *interpolated = NULL, *type_str = NULL, *log;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &message, &type, &timestamp, &context);
	
	if (Z_TYPE_P(context) == IS_ARRAY) {
		PHALCON_CALL_METHOD(&interpolated, this_ptr, "interpolate", message, context);
	}
	else {
		interpolated = message;
	}

	PHALCON_CALL_METHOD(&type_str, this_ptr, "gettypestring", type);
	
	PHALCON_INIT_VAR(log);
	array_init_size(log, 3);
	phalcon_array_update_string(&log, SL("type"), type_str, PH_COPY);
	phalcon_array_update_string(&log, SL("message"), interpolated, PH_COPY);
	phalcon_array_update_string(&log, SL("timestamp"), timestamp, PH_COPY);
	RETURN_MM_ON_FAILURE(phalcon_json_encode(return_value, log, 0 TSRMLS_CC));
	RETURN_MM();
}
