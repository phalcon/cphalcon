
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


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
 * @param string $interpolatorLeft
 * @param string $interpolatorRight
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval dateFormat_zv, interpolatorLeft_zv, interpolatorRight_zv;
	zend_string *dateFormat = NULL, *interpolatorLeft = NULL, *interpolatorRight = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dateFormat_zv);
	ZVAL_UNDEF(&interpolatorLeft_zv);
	ZVAL_UNDEF(&interpolatorRight_zv);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dateFormat", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("interpolatorLeft", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("interpolatorRight", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(dateFormat)
		Z_PARAM_STR(interpolatorLeft)
		Z_PARAM_STR(interpolatorRight)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 920, &dateFormat_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 921, &interpolatorLeft_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 922, &interpolatorRight_zv);
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
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, message, options, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &item);
	ZEPHIR_CALL_METHOD(&_0, item, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&message, this_ptr, "getinterpolatedmessage", NULL, 0, item, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&options);
	ZVAL_LONG(&options, (((((1 + 4) + 2) + 8) + 64) + 4194304));
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0);
	ZEPHIR_CALL_METHOD(&_2, item, "getlevelname", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("level"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("message"), &message, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getformatteddate", NULL, 0, item);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("timestamp"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toencode", NULL, 0, &_1, &options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Encodes data using `json_encode`
 *
 * @param mixed $data    JSON data to encode
 * @param int   $options Bitmask of json_encode options
 * @param int   $depth   Recursion depth
 *
 * @return string
 *
 * @throws \JsonException if the data cannot be encoded
 * @link https://www.php.net/manual/en/function.json-encode.php
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, toEncode)
{
	zval _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long options, depth, ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, *options_param = NULL, *depth_param = NULL, __$null, encoded, error, message, _0, _1, _2$$3, _3$$3;

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&encoded);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(options)
		Z_PARAM_LONG(depth)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &data, &options_param, &depth_param);
	if (!options_param) {
		options = 79;
	} else {
		}
	if (!depth_param) {
		depth = 512;
	} else {
		}
	ZEPHIR_INIT_VAR(&encoded);
	zephir_json_encode(&encoded, &__$null, 0 );
	ZVAL_LONG(&_0, options);
	ZVAL_LONG(&_1, depth);
	ZEPHIR_INIT_NVAR(&encoded);
	zephir_json_encode(&encoded, data, zephir_get_intval(&_0) );
	ZEPHIR_CALL_FUNCTION(&error, "json_last_error", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&message, "json_last_error_msg", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&error, 0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_json_encode(&_2$$3, &__$null, 0 );
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, zephir_get_internal_ce(SL("jsonexception")));
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 0, &message, &error);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Traits/Support/Helper/Json/EncodeTrait.zep", 55);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_cast_to_string(&_4, &encoded);
	RETURN_CTOR(&_4);
}

