
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Logger\Formatter\Line
 *
 * Formats messages using an one-line string
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Line) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Line, phalcon, logger_formatter_line, phalcon_logger_formatter_abstractformatter_ce, phalcon_logger_formatter_line_method_entry, 0);

	/**
	 * Default date format
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_formatter_line_ce, SL("dateFormat"), "D, d M y H:i:s O", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Format applied to each message
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_formatter_line_ce, SL("format"), "[%date%][%type%] %message%", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Default date format
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, getDateFormat) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "dateFormat");

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


	zephir_update_property_zval(this_ptr, SL("dateFormat"), &dateFormat);
	RETURN_THIS();

}

/**
 * Format applied to each message
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, getFormat) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "format");

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


	zephir_update_property_zval(this_ptr, SL("format"), &format);
	RETURN_THIS();

}

/**
 * Phalcon\Logger\Formatter\Line construct
 *
 * @param string format
 * @param string dateFormat
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, __construct) {

	zval *format_param = NULL, *dateFormat_param = NULL;
	zval format, dateFormat;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&dateFormat);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &format_param, &dateFormat_param);

	if (!format_param) {
		ZEPHIR_INIT_VAR(&format);
		ZVAL_STRING(&format, "");
	} else {
		zephir_get_strval(&format, format_param);
	}
	if (!dateFormat_param) {
		ZEPHIR_INIT_VAR(&dateFormat);
		ZVAL_STRING(&dateFormat, "");
	} else {
		zephir_get_strval(&dateFormat, dateFormat_param);
	}


	if (!(Z_TYPE_P(&format) == IS_UNDEF) && Z_STRLEN_P(&format)) {
		zephir_update_property_zval(this_ptr, SL("format"), &format);
	}
	if (!(Z_TYPE_P(&dateFormat) == IS_UNDEF) && Z_STRLEN_P(&dateFormat)) {
		zephir_update_property_zval(this_ptr, SL("dateFormat"), &dateFormat);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Applies a format to a message before sent it to the internal log
 *
 * @param <Item> item
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, format) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, format, _0, _9, _10, _11, _12, _13, _14, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$4, _7$$4, _8$$4, _15$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_15$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);



	zephir_read_property(&_0, this_ptr, SL("format"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&format, &_0);
	if (zephir_memnstr_str(&format, SL("%date%"), "phalcon/logger/formatter/line.zep", 69)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("dateFormat"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3$$3, item, "gettime", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_4$$3, "date", NULL, 299, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "%date%");
		zephir_fast_str_replace(&_1$$3, &_5$$3, &_4$$3, &format TSRMLS_CC);
		ZEPHIR_CPY_WRT(&format, &_1$$3);
	}
	if (zephir_memnstr_str(&format, SL("%type%"), "phalcon/logger/formatter/line.zep", 76)) {
		ZEPHIR_INIT_VAR(&_6$$4);
		ZEPHIR_CALL_METHOD(&_7$$4, item, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "%type%");
		zephir_fast_str_replace(&_6$$4, &_8$$4, &_7$$4, &format TSRMLS_CC);
		ZEPHIR_CPY_WRT(&format, &_6$$4);
	}
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CALL_METHOD(&_10, item, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "%message%");
	zephir_fast_str_replace(&_9, &_11, &_10, &format TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_GET_CONSTANT(&_12, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_VV(&_13, &_9, &_12);
	ZEPHIR_CPY_WRT(&format, &_13);
	ZEPHIR_CALL_METHOD(&_14, item, "getcontext", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_14) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_15$$5, item, "getcontext", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "interpolate", NULL, 0, &format, &_15$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&format);

}

