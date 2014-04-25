
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"


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
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, format) {

	zval *_0;
	int type, timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type_param = NULL, *timestamp_param = NULL, *_1 = NULL, *_2;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &message_param, &type_param, &timestamp_param);

	zephir_get_strval(message, message_param);
	type = zephir_get_intval(type_param);
	timestamp = zephir_get_intval(timestamp_param);


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 5);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, type);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "gettypestring", NULL, _2);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("type"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("message"), &message, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_LONG(_2, timestamp);
	zephir_array_update_string(&_0, SL("timestamp"), &_2, PH_COPY | PH_SEPARATE);
	zephir_json_encode(return_value, &(return_value), _0, 0  TSRMLS_CC);
	RETURN_MM();

}

