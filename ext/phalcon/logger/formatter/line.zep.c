
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
#include "kernel/array.h"
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
 *
 * @property string $format
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
 * Line constructor.
 *
 * @param string $format
 * @param string $dateFormat
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
	zval *item, item_sub, message, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("format"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getformatteddate", NULL, 0, item);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("%date%"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, item, "getlevelname", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("%level%"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, item, "getmessage", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("%message%"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&message, "strtr", NULL, 5, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, item, "getcontext", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "tointerpolate", NULL, 0, &message, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

