
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/**
 * Phalcon\Logger\Formatter\Line
 *
 * Formats messages using an one-line string
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Line) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Line, phalcon, logger_formatter_line, phalcon_logger_formatter_ce, phalcon_logger_formatter_line_method_entry, 0);

	/**
	 * Default date format
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_formatter_line_ce, SL("_dateFormat"), "D, d M y H:i:s O", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Format applied to each message
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_formatter_line_ce, SL("_format"), "[%date%][%type%] %message%", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Default date format
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, getDateFormat) {

	

	RETURN_MEMBER(getThis(), "_dateFormat");

}

/**
 * Default date format
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, setDateFormat) {

	zval *dateFormat_param = NULL;
	zval *dateFormat = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dateFormat_param);

	zephir_get_strval(dateFormat, dateFormat_param);


	zephir_update_property_this(getThis(), SL("_dateFormat"), dateFormat TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Format applied to each message
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, getFormat) {

	

	RETURN_MEMBER(getThis(), "_format");

}

/**
 * Format applied to each message
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, setFormat) {

	zval *format_param = NULL;
	zval *format = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &format_param);

	zephir_get_strval(format, format_param);


	zephir_update_property_this(getThis(), SL("_format"), format TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Phalcon\Logger\Formatter\Line construct
 *
 * @param string format
 * @param string dateFormat
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, __construct) {

	zval *format = NULL, *dateFormat = NULL;

	zephir_fetch_params(0, 0, 2, &format, &dateFormat);

	if (!format) {
		format = ZEPHIR_GLOBAL(global_null);
	}
	if (!dateFormat) {
		dateFormat = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_is_true(format)) {
		zephir_update_property_this(getThis(), SL("_format"), format TSRMLS_CC);
	}
	if (zephir_is_true(dateFormat)) {
		zephir_update_property_this(getThis(), SL("_dateFormat"), dateFormat TSRMLS_CC);
	}

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
PHP_METHOD(Phalcon_Logger_Formatter_Line, format) {

	zend_long type, timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type_param = NULL, *timestamp_param = NULL, *context = NULL, *format = NULL, *_8, _9, *_10, *_11, *_0$$3, *_1$$3, _2$$3 = zval_used_for_init, *_3$$3 = NULL, *_4$$4, *_5$$4 = NULL, *_6$$4, _7$$4;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &message_param, &type_param, &timestamp_param, &context);

	zephir_get_strval(message, message_param);
	type = zephir_get_intval(type_param);
	timestamp = zephir_get_intval(timestamp_param);
	if (!context) {
		context = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(format);
	zephir_read_property_this(&format, this_ptr, SL("_format"), PH_NOISY_CC);
	if (zephir_memnstr_str(format, SL("%date%"), "phalcon/logger/formatter/line.zep", 80)) {
		ZEPHIR_INIT_VAR(_0$$3);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_dateFormat"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_LONG(&_2$$3, timestamp);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "date", NULL, 317, _1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_2$$3);
		ZVAL_STRING(&_2$$3, "%date%", 0);
		zephir_fast_str_replace(&_0$$3, &_2$$3, _3$$3, format TSRMLS_CC);
		ZEPHIR_CPY_WRT(format, _0$$3);
	}
	if (zephir_memnstr_str(format, SL("%type%"), "phalcon/logger/formatter/line.zep", 87)) {
		ZEPHIR_INIT_VAR(_4$$4);
		ZEPHIR_INIT_VAR(_6$$4);
		ZVAL_LONG(_6$$4, type);
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "gettypestring", NULL, 0, _6$$4);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_7$$4);
		ZVAL_STRING(&_7$$4, "%type%", 0);
		zephir_fast_str_replace(&_4$$4, &_7$$4, _5$$4, format TSRMLS_CC);
		ZEPHIR_CPY_WRT(format, _4$$4);
	}
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, "%message%", 0);
	zephir_fast_str_replace(&_8, &_9, message, format TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_GET_CONSTANT(_10, "PHP_EOL");
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_CONCAT_VV(_11, _8, _10);
	ZEPHIR_CPY_WRT(format, _11);
	if (Z_TYPE_P(context) == IS_ARRAY) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "interpolate", NULL, 0, format, context);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(format);

}

