
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
#include "kernel/fcall.h"
#include "kernel/array.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Line)
{
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
PHP_METHOD(Phalcon_Logger_Formatter_Line, getFormat)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "format");
}

/**
 * Format applied to each message
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, setFormat)
{
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
PHP_METHOD(Phalcon_Logger_Formatter_Line, __construct)
{
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
		ZVAL_STRING(&format, "[%date%][%level%] %message%");
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
PHP_METHOD(Phalcon_Logger_Formatter_Line, format)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, context, format, interpolate, time, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&interpolate);
	ZVAL_UNDEF(&time);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);


	ZEPHIR_CALL_METHOD(&context, item, "getcontext", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("format"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&format, &_0);
	ZEPHIR_CALL_METHOD(&time, item, "gettime", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&interpolate);
	object_init_ex(&interpolate, phalcon_support_helper_str_interpolate_ce);
	if (zephir_has_constructor(&interpolate)) {
		ZEPHIR_CALL_METHOD(NULL, &interpolate, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_read_property(&_0, this_ptr, ZEND_STRL("dateFormat"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &time, "format", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_array_update_string(&context, SL("date"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, item, "getlevelname", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&context, SL("level"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, item, "getmessage", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&context, SL("message"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(&interpolate, "__invoke", NULL, 429, &format, &context);
	zephir_check_call_status();
	RETURN_MM();
}

