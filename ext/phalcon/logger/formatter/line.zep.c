
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
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
 * Class Line
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
 * Line constructor.
 *
 * @param string $format
 * @param string $dateFormat
 * @param string $interpolatorLeft
 * @param string $interpolatorRight
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval format_zv, dateFormat_zv, interpolatorLeft_zv, interpolatorRight_zv;
	zend_string *format = NULL, *dateFormat = NULL, *interpolatorLeft = NULL, *interpolatorRight = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format_zv);
	ZVAL_UNDEF(&dateFormat_zv);
	ZVAL_UNDEF(&interpolatorLeft_zv);
	ZVAL_UNDEF(&interpolatorRight_zv);
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(format)
		Z_PARAM_STR(dateFormat)
		Z_PARAM_STR(interpolatorLeft)
		Z_PARAM_STR(interpolatorRight)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!format) {
		format = zend_string_init(ZEND_STRL("[%date%][%level%] %message%"), 0);
		zephir_memory_observe(&format_zv);
		ZVAL_STR(&format_zv, format);
	} else {
		zephir_memory_observe(&format_zv);
	ZVAL_STR_COPY(&format_zv, format);
	}
	if (!dateFormat) {
		dateFormat = zend_string_init(ZEND_STRL("c"), 0);
		zephir_memory_observe(&dateFormat_zv);
		ZVAL_STR(&dateFormat_zv, dateFormat);
	} else {
		zephir_memory_observe(&dateFormat_zv);
	ZVAL_STR_COPY(&dateFormat_zv, dateFormat);
	}
	if (!interpolatorLeft) {
		interpolatorLeft = zend_string_init(ZEND_STRL("%"), 0);
		zephir_memory_observe(&interpolatorLeft_zv);
		ZVAL_STR(&interpolatorLeft_zv, interpolatorLeft);
	} else {
		zephir_memory_observe(&interpolatorLeft_zv);
	ZVAL_STR_COPY(&interpolatorLeft_zv, interpolatorLeft);
	}
	if (!interpolatorRight) {
		interpolatorRight = zend_string_init(ZEND_STRL("%"), 0);
		zephir_memory_observe(&interpolatorRight_zv);
		ZVAL_STR(&interpolatorRight_zv, interpolatorRight);
	} else {
		zephir_memory_observe(&interpolatorRight_zv);
	ZVAL_STR_COPY(&interpolatorRight_zv, interpolatorRight);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("format"), &format_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("dateFormat"), &dateFormat_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("interpolatorLeft"), &interpolatorLeft_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("interpolatorRight"), &interpolatorRight_zv);
	ZEPHIR_MM_RESTORE();
}

/**
 * Applies a format to a message before sent it to the internal log
 *
 * @param Item $item
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, format)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, message, _0, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &item);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("format"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("interpolatorLeft"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("interpolatorRight"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VSV(&_4, &_2, "date", &_3);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getformatteddate", NULL, 0, item);
	zephir_check_call_status();
	zephir_array_update_zval(&_1, &_4, &_5, PH_COPY);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("interpolatorLeft"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("interpolatorRight"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_VSV(&_8, &_6, "level", &_7);
	ZEPHIR_CALL_METHOD(&_5, item, "getlevelname", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_zval(&_1, &_8, &_5, PH_COPY);
	zephir_read_property(&_9, this_ptr, ZEND_STRL("interpolatorLeft"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_10, this_ptr, ZEND_STRL("interpolatorRight"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_CONCAT_VSV(&_11, &_9, "message", &_10);
	ZEPHIR_CALL_METHOD(&_5, item, "getmessage", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_zval(&_1, &_11, &_5, PH_COPY);
	ZEPHIR_CALL_FUNCTION(&message, "strtr", NULL, 6, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getinterpolatedmessage", NULL, 0, item, &message);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return the format applied to each message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, getFormat)
{

	RETURN_MEMBER_TYPED(getThis(), "format", IS_STRING);
}

/**
 * Set the format applied to each message
 *
 * @param string $format
 *
 * @return static
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, setFormat)
{
	zval format_zv;
	zend_string *format = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(format)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&format_zv, format);
	zephir_update_property_zval(this_ptr, ZEND_STRL("format"), &format_zv);
	RETURN_THISW();
}

