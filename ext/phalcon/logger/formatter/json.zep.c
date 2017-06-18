
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * Phalcon\Logger\Formatter\Json
 *
 * Formats messages using JSON encoding
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Json, phalcon, logger_formatter_json, phalcon_logger_formatter_ce, phalcon_logger_formatter_json_method_entry, 0);

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

	zval *_2;
	zend_long type, timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type_param = NULL, *timestamp_param = NULL, *context = NULL, *_0$$3 = NULL, *_1, *_3 = NULL, *_4 = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &message_param, &type_param, &timestamp_param, &context);

	zephir_get_strval(message, message_param);
	type = zephir_get_intval(type_param);
	timestamp = zephir_get_intval(timestamp_param);
	if (!context) {
		context = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(context) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "interpolate", NULL, 0, message, context);
		zephir_check_call_status();
		zephir_get_strval(message, _0$$3);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, type);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "gettypestring", NULL, 0, _4);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL("type"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("message"), &message, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, timestamp);
	zephir_array_update_string(&_2, SL("timestamp"), &_4, PH_COPY | PH_SEPARATE);
	zephir_json_encode(_1, &(_1), _2, 0  TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZEPHIR_GET_CONSTANT(_4, "PHP_EOL");
	ZEPHIR_CONCAT_VV(return_value, _1, _4);
	RETURN_MM();

}

