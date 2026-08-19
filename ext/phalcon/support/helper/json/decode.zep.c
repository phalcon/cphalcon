
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Decodes a string using `json_decode` and throws an exception if the
 * JSON data cannot be decoded
 *
 * The following options are used if none specified for json_encode
 *
 * JSON_HEX_TAG, JSON_HEX_APOS, JSON_HEX_AMP, JSON_HEX_QUOT,
 * JSON_UNESCAPED_SLASHES
 *
 * If JSON_THROW_ON_ERROR is defined in the options a JsonException will be
 * thrown in the case of an error. Otherwise, any error will throw
 * JsonDecodeError
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Json_Decode)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Json, Decode, phalcon, support_helper_json_decode, phalcon_support_helper_json_decode_method_entry, 0);

	return SUCCESS;
}

/**
 * @param int<1, max> $depth       Recursion depth.
 *
 * @throws JsonDecodeError if the JSON cannot be decoded.
 * @link https://www.php.net/manual/en/function.json-decode.php
 */
PHP_METHOD(Phalcon_Support_Helper_Json_Decode, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long depth, options, ZEPHIR_LAST_CALL_STATUS;
	zend_bool associative;
	zval data_zv, *associative_param = NULL, *depth_param = NULL, *options_param = NULL, ex, _3, _0$$3, _1$$3, _2$$3, _4$$4, _5$$4, _6$$4;
	zend_string *data = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(associative)
		Z_PARAM_LONG(depth)
		Z_PARAM_LONG(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		associative_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		depth_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		options_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!associative_param) {
		associative = 0;
	} else {
		}
	if (!depth_param) {
		depth = 512;
	} else {
		}
	if (!options_param) {
		options = 79;
	} else {
		}
	/* try_start_1: */

		if (associative) {
			ZVAL_BOOL(&_0$$3, 1);
		} else {
			ZVAL_BOOL(&_0$$3, 0);
		}
		ZVAL_LONG(&_1$$3, depth);
		ZVAL_LONG(&_2$$3, options);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "todecode", NULL, 0, &data_zv, &_0$$3, &_1$$3, &_2$$3);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_OBJ(&_3, EG(exception));
		Z_ADDREF_P(&_3);
		if (zephir_is_instance_of(&_3, SL("JsonException"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&ex, &_3);
			ZEPHIR_INIT_VAR(&_4$$4);
			object_init_ex(&_4$$4, phalcon_support_helper_json_exceptions_jsondecodeerror_ce);
			ZEPHIR_CALL_METHOD(&_5$$4, &ex, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6$$4, &ex, "getcode", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 0, &_5$$4, &_6$$4, &ex);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$4, "phalcon/Support/Helper/Json/Decode.zep", 51);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
}

/**
 * Decodes a string using `json_decode`
 *
 * @param string $data        JSON data to parse
 * @param bool   $associative When `true`, objects are converted to arrays
 * @param int    $depth       Recursion depth
 * @param int    $options     Bitmask of json_decode options
 *
 * @return mixed
 *
 * @throws \JsonException if the data cannot be decoded
 * @link https://www.php.net/manual/en/function.json-decode.php
 */
PHP_METHOD(Phalcon_Support_Helper_Json_Decode, toDecode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long depth, options, ZEPHIR_LAST_CALL_STATUS;
	zend_bool associative;
	zval data_zv, *associative_param = NULL, *depth_param = NULL, *options_param = NULL, __$null, decoded, error, message, _0, _1, _2, _3$$3, _4$$3;
	zend_string *data = NULL;

	ZVAL_UNDEF(&data_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(associative)
		Z_PARAM_LONG(depth)
		Z_PARAM_LONG(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		associative_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		depth_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		options_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!associative_param) {
		associative = 0;
	} else {
		}
	if (!depth_param) {
		depth = 512;
	} else {
		}
	if (!options_param) {
		options = 79;
	} else {
		}
	ZEPHIR_INIT_VAR(&decoded);
	zephir_json_encode(&decoded, &__$null, 0 );
	ZVAL_BOOL(&_0, (associative ? 1 : 0));
	ZVAL_LONG(&_1, depth);
	ZVAL_LONG(&_2, options);
	ZEPHIR_INIT_NVAR(&decoded);
	zephir_json_decode(&decoded, &data_zv, zephir_get_intval(&_0) );
	ZEPHIR_CALL_FUNCTION(&error, "json_last_error", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&message, "json_last_error_msg", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&error, 0)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_json_encode(&_3$$3, &__$null, 0 );
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, zephir_get_internal_ce(SL("jsonexception")));
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 0, &message, &error);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/Traits/Support/Helper/Json/DecodeTrait.zep", 57);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&decoded);
}

