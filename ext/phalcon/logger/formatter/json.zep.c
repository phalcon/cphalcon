
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
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
 * Formats messages using JSON encoding
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Json)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Json, phalcon, logger_formatter_json, phalcon_logger_formatter_abstractformatter_ce, phalcon_logger_formatter_json_method_entry, 0);

	return SUCCESS;
}

/**
 * Json constructor.
 *
 * @param string $dateFormat
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *dateFormat_param = NULL;
	zval dateFormat;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dateFormat);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(dateFormat)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dateFormat_param);
	if (!dateFormat_param) {
		ZEPHIR_INIT_VAR(&dateFormat);
		ZVAL_STRING(&dateFormat, "c");
	} else {
		zephir_get_strval(&dateFormat, dateFormat_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("dateFormat"), &dateFormat);
	ZEPHIR_MM_RESTORE();
}

/**
 * Applies a format to a message before sent it to the internal log
 *
 * @param Item $item
 *
 * @return string
 * @throws JsonException
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, format)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, message, options, _0, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);


	ZEPHIR_INIT_VAR(&options);
	ZVAL_LONG(&options, (((((1 + 4) + 2) + 8) + 64) + 4194304));
	ZEPHIR_CALL_METHOD(&_0, item, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, item, "getcontext", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&message, this_ptr, "tointerpolate", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 3, 0);
	ZEPHIR_CALL_METHOD(&_3, item, "getlevelname", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL("level"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("message"), &message, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getformatteddate", NULL, 0, item);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL("timestamp"), &_3, PH_COPY | PH_SEPARATE);
	zephir_json_encode(return_value, &_2, zephir_get_intval(&options) );
	RETURN_MM();
}

