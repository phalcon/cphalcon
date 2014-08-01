
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"


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
/**
 * Phalcon\Logger\Formatter\Json
 *
 * Formats messages using JSON encoding
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Json, phalcon, logger_formatter_json, phalcon_logger_formatter_ce, phalcon_logger_formatter_json_method_entry, 0);

	zend_class_implements(phalcon_logger_formatter_json_ce TSRMLS_CC, 1, phalcon_logger_formatterinterface_ce);
	return SUCCESS;

}

/**
 * Applies a format to a message before sent it to the internal log
 *
 * @param string message
 * @param int type
 * @param int timestamp
 * @param array $context
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, format) {

	zval *context = NULL, *_2;
	int type, timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type_param = NULL, *timestamp_param = NULL, *context_param = NULL, *_0, *_1 = NULL, *_3;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &message_param, &type_param, &timestamp_param, &context_param);

	zephir_get_strval(message, message_param);
	ZEPHIR_SEPARATE_PARAM(message);
	type = zephir_get_intval(type_param);
	timestamp = zephir_get_intval(timestamp_param);
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	ZVAL_NULL(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_gettype(_0, context TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_0, "array")) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "interpolate", NULL, message, context);
		zephir_check_call_status();
		zephir_get_strval(message, _1);
	}
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 5);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, type);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "gettypestring", NULL, _3);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL("type"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("message"), &message, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, timestamp);
	zephir_array_update_string(&_2, SL("timestamp"), &_3, PH_COPY | PH_SEPARATE);
	zephir_json_encode(return_value, &(return_value), _2, 0  TSRMLS_CC);
	RETURN_MM();

}

