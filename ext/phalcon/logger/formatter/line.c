
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
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

	zend_class_implements(phalcon_logger_formatter_line_ce TSRMLS_CC, 1, phalcon_logger_formatterinterface_ce);

	return SUCCESS;

}

/**
 * Default date format
 *
 * @var string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, getDateFormat) {



}

/**
 * Default date format
 *
 * @var string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, setDateFormat) {

	zval *dateFormat;

	zephir_fetch_params(0, 1, 0, &dateFormat);




}

/**
 * Format applied to each message
 *
 * @var string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, getFormat) {



}

/**
 * Format applied to each message
 *
 * @var string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, setFormat) {

	zval *format;

	zephir_fetch_params(0, 1, 0, &format);




}

/**
 * Phalcon\Logger\Formatter\Line construct
 *
 * @param string format
 * @param string dateFormat
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, __construct) {

	zval *format = NULL, *dateFormat = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &format, &dateFormat);

	if (!format) {
		ZEPHIR_CPY_WRT(format, ZEPHIR_GLOBAL(global_null));
	}
	if (!dateFormat) {
		ZEPHIR_CPY_WRT(dateFormat, ZEPHIR_GLOBAL(global_null));
	}


	if (zephir_is_true(format)) {
		zephir_update_property_this(this_ptr, SL("_format"), format TSRMLS_CC);
	}
	if (zephir_is_true(dateFormat)) {
		zephir_update_property_this(this_ptr, SL("_dateFormat"), dateFormat TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Applies a format to a message before sent it to the internal log
 *
 * @param string message
 * @param int type
 * @param int timestamp
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, format) {

	int timestamp;
	zval *message, *type, *timestamp_param = NULL, *format = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &message, &type, &timestamp_param);

		timestamp = zephir_get_intval(timestamp_param);


	ZEPHIR_OBS_VAR(format);
	zephir_read_property_this(&format, this_ptr, SL("_format"), PH_NOISY_CC);
	if (zephir_memnstr_str(format, SL("%date%"), "/Users/gutierrezandresfelipe/cphalcon/phalcon/logger/formatter/line.zep", 77)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dateFormat"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, timestamp);
		ZEPHIR_INIT_VAR(_2);
		zephir_call_func_p2(_2, "date", _0, &_1);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "%date%", 0);
		ZEPHIR_INIT_VAR(_3);
		zephir_call_func_p3(_3, "str_replace", &_1, _2, format);
		ZEPHIR_CPY_WRT(format, _3);
	}
	if (zephir_memnstr_str(format, SL("%type%"), "/Users/gutierrezandresfelipe/cphalcon/phalcon/logger/formatter/line.zep", 84)) {
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_method_p1(_2, this_ptr, "gettypestring", type);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "%type%", 0);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_func_p3(_3, "str_replace", &_1, _2, format);
		ZEPHIR_CPY_WRT(format, _3);
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "%message%", 0);
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_func_p3(_2, "str_replace", &_1, message, format);
	ZEPHIR_CONCAT_VS(return_value, _2, "\n");
	RETURN_MM();

}

