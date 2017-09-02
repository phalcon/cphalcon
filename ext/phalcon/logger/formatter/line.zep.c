
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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_dateFormat");

}

/**
 * Default date format
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, setDateFormat) {

	zval *dateFormat_param = NULL;
	zval dateFormat;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dateFormat);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dateFormat_param);

	zephir_get_strval(&dateFormat, dateFormat_param);


	zephir_update_property_zval(this_ptr, SL("_dateFormat"), &dateFormat);
	RETURN_THIS();

}

/**
 * Format applied to each message
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, getFormat) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_format");

}

/**
 * Format applied to each message
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, setFormat) {

	zval *format_param = NULL;
	zval format;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &format_param);

	zephir_get_strval(&format, format_param);


	zephir_update_property_zval(this_ptr, SL("_format"), &format);
	RETURN_THIS();

}

/**
 * Phalcon\Logger\Formatter\Line construct
 *
 * @param string format
 * @param string dateFormat
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, __construct) {

	zval *format = NULL, format_sub, *dateFormat = NULL, dateFormat_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format_sub);
	ZVAL_UNDEF(&dateFormat_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 2, &format, &dateFormat);

	if (!format) {
		format = &format_sub;
		format = &__$null;
	}
	if (!dateFormat) {
		dateFormat = &dateFormat_sub;
		dateFormat = &__$null;
	}


	if (zephir_is_true(format)) {
		zephir_update_property_zval(this_ptr, SL("_format"), format);
	}
	if (zephir_is_true(dateFormat)) {
		zephir_update_property_zval(this_ptr, SL("_dateFormat"), dateFormat);
	}

}

/**
 * Applies a format to a message before sent it to the internal log
 *
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, format) {

	zend_long type, timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type_param = NULL, *timestamp_param = NULL, *context = NULL, context_sub, __$null, format, _9, _10, _11, _12, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4, _7$$4, _8$$4;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &message_param, &type_param, &timestamp_param, &context);

	zephir_get_strval(&message, message_param);
	type = zephir_get_intval(type_param);
	timestamp = zephir_get_intval(timestamp_param);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}


	ZEPHIR_OBS_VAR(&format);
	zephir_read_property(&format, this_ptr, SL("_format"), PH_NOISY_CC);
	if (zephir_memnstr_str(&format, SL("%date%"), "phalcon/logger/formatter/line.zep", 76)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("_dateFormat"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_2$$3, timestamp);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "date", NULL, 278, &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "%date%");
		zephir_fast_str_replace(&_0$$3, &_4$$3, &_3$$3, &format TSRMLS_CC);
		ZEPHIR_CPY_WRT(&format, &_0$$3);
	}
	if (zephir_memnstr_str(&format, SL("%type%"), "phalcon/logger/formatter/line.zep", 83)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_LONG(&_7$$4, type);
		ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "gettypestring", NULL, 0, &_7$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "%type%");
		zephir_fast_str_replace(&_5$$4, &_8$$4, &_6$$4, &format TSRMLS_CC);
		ZEPHIR_CPY_WRT(&format, &_5$$4);
	}
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "%message%");
	zephir_fast_str_replace(&_9, &_10, &message, &format TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_GET_CONSTANT(&_11, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_VV(&_12, &_9, &_11);
	ZEPHIR_CPY_WRT(&format, &_12);
	if (Z_TYPE_P(context) == IS_ARRAY) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "interpolate", NULL, 0, &format, context);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&format);

}

