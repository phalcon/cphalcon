
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Encodes a string using `json_encode` and throws an exception if the
 * JSON data cannot be encoded
 *
 * The following options are used if none specified for json_encode
 *
 * JSON_HEX_TAG, JSON_HEX_APOS, JSON_HEX_AMP, JSON_HEX_QUOT,
 * JSON_UNESCAPED_SLASHES
 *
 * Any error will throw InvalidArgumentException, regardless of whether
 * JSON_THROW_ON_ERROR is specified in the options.
 *
 * @see  https://www.ietf.org/rfc/rfc4627.txt
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Json_Encode)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Json, Encode, phalcon, support_helper_json_encode, phalcon_support_helper_json_encode_method_entry, 0);

	return SUCCESS;
}

/**
 * @param mixed $data    JSON data to parse
 * @param int   $options Bitmask of JSON encode options.
 * @param int   $depth   Recursion depth.
 *
 * @return string
 *
 * @throws InvalidArgumentException if the JSON cannot be encoded.
 * @link https://www.php.net/manual/en/function.json-encode.php
 */
PHP_METHOD(Phalcon_Support_Helper_Json_Encode, __invoke)
{
	zval _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long options, depth, ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, *options_param = NULL, *depth_param = NULL, __$null, encoded, error, ex, message, _2, _0$$3, _1$$3, _3$$4, _4$$4, _5$$4, _6$$4, _7$$5, _8$$5, _9$$5;

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&encoded);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10);
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
	/* try_start_1: */

		ZEPHIR_INIT_VAR(&encoded);
		zephir_json_encode(&encoded, &__$null, 0 );
		ZVAL_LONG(&_0$$3, options);
		ZVAL_LONG(&_1$$3, depth);
		ZEPHIR_INIT_NVAR(&encoded);
		zephir_json_encode(&encoded, data, zephir_get_intval(&_0$$3) );
		ZEPHIR_CALL_FUNCTION(&error, "json_last_error", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_FUNCTION(&message, "json_last_error_msg", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_OBJ(&_2, EG(exception));
		Z_ADDREF_P(&_2);
		if (zephir_is_instance_of(&_2, SL("JsonException"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&ex, &_2);
			ZEPHIR_INIT_VAR(&_3$$4);
			object_init_ex(&_3$$4, spl_ce_InvalidArgumentException);
			ZEPHIR_CALL_METHOD(&_4$$4, &ex, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_5$$4);
			ZEPHIR_CONCAT_SV(&_5$$4, "json_encode error: ", &_4$$4);
			ZEPHIR_CALL_METHOD(&_6$$4, &ex, "getcode", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 26, &_5$$4, &_6$$4, &ex);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$4, "phalcon/Support/Helper/Json/Encode.zep", 57);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (!ZEPHIR_IS_LONG_IDENTICAL(&error, 0)) {
		ZEPHIR_INIT_VAR(&_7$$5);
		zephir_json_encode(&_7$$5, &__$null, 0 );
		ZEPHIR_INIT_VAR(&_8$$5);
		object_init_ex(&_8$$5, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_9$$5);
		ZEPHIR_CONCAT_SV(&_9$$5, "json_encode error: ", &message);
		ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", NULL, 26, &_9$$5, &error);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$5, "phalcon/Support/Helper/Json/Encode.zep", 62);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_cast_to_string(&_10, &encoded);
	RETURN_CTOR(&_10);
}

