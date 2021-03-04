
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
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
	 * Format applied to each message
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_logger_formatter_line_ce, SL("format"), ZEND_ACC_PROTECTED);

	return SUCCESS;

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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *format_param = NULL;
	zval format;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(format)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &format_param);

	zephir_get_strval(&format, format_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("format"), &format);
	RETURN_THIS();

}

/**
 * Phalcon\Logger\Formatter\Line construct
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *format_param = NULL, *dateFormat_param = NULL;
	zval format, dateFormat;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&dateFormat);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(format)
		Z_PARAM_STR(dateFormat)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &format_param, &dateFormat_param);

	if (!format_param) {
		ZEPHIR_INIT_VAR(&format);
		ZVAL_STRING(&format, "[%date%][%type%] %message%");
	} else {
		zephir_get_strval(&format, format_param);
	}
	if (!dateFormat_param) {
		ZEPHIR_INIT_VAR(&dateFormat);
		ZVAL_STRING(&dateFormat, "c");
	} else {
		zephir_get_strval(&dateFormat, dateFormat_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("format"), &format);
	zephir_update_property_zval(this_ptr, ZEND_STRL("dateFormat"), &dateFormat);
	ZEPHIR_MM_RESTORE();

}

/**
 * Applies a format to a message before sent it to the internal log
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, format) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, format, _0, _7, _8, _9, _10, _1$$3, _2$$3, _3$$3, _4$$4, _5$$4, _6$$4, _11$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_11$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("format"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&format, &_0);
	if (zephir_memnstr_str(&format, SL("%date%"), "phalcon/Logger/Formatter/Line.zep", 51)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getformatteddate", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "%date%");
		zephir_fast_str_replace(&_1$$3, &_3$$3, &_2$$3, &format);
		ZEPHIR_CPY_WRT(&format, &_1$$3);
	}
	if (zephir_memnstr_str(&format, SL("%type%"), "phalcon/Logger/Formatter/Line.zep", 62)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CALL_METHOD(&_5$$4, item, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "%type%");
		zephir_fast_str_replace(&_4$$4, &_6$$4, &_5$$4, &format);
		ZEPHIR_CPY_WRT(&format, &_4$$4);
	}
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CALL_METHOD(&_8, item, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "%message%");
	zephir_fast_str_replace(&_7, &_9, &_8, &format);
	ZEPHIR_CPY_WRT(&format, &_7);
	ZEPHIR_CALL_METHOD(&_10, item, "getcontext", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_10) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_11$$5, item, "getcontext", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "interpolate", NULL, 0, &format, &_11$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&format);

}

