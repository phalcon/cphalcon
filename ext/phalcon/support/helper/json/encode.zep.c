
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
#include "kernel/exception.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon.
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
 * JSON_UNESCAPED_SLASHES, JSON_THROW_ON_ERROR
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
 * @param int   $options Bitmask of JSON decode options.
 * @param int   $depth   Recursion depth.
 *
 * @return string
 *
 * @throws JsonException if the JSON cannot be encoded.
 * @link http://www.php.net/manual/en/function.json-encode.php
 */
PHP_METHOD(Phalcon_Support_Helper_Json_Encode, __invoke)
{
	zval _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long options, depth, ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, *options_param = NULL, *depth_param = NULL, encoded, _0, _1, _2, _3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&encoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(options)
		Z_PARAM_LONG(depth)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &data, &options_param, &depth_param);
	if (!options_param) {
		options = 4194383;
	} else {
		options = zephir_get_intval(options_param);
	}
	if (!depth_param) {
		depth = 512;
	} else {
		depth = zephir_get_intval(depth_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	ZEPHIR_INIT_VAR(&encoded);
	zephir_json_encode(&encoded, &_0, 0 );
	ZVAL_LONG(&_1, options);
	ZVAL_LONG(&_2, depth);
	ZEPHIR_INIT_NVAR(&encoded);
	zephir_json_encode(&encoded, data, zephir_get_intval(&_1) );
	ZEPHIR_CALL_FUNCTION(&_3, "json_last_error", NULL, 210);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_3, 0)) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, zephir_get_internal_ce(SL("jsonexception")));
		ZEPHIR_CALL_FUNCTION(&_5$$3, "json_last_error_msg", NULL, 211);
		zephir_check_call_status();
		ZVAL_LONG(&_6$$3, 5);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 0, &_5$$3, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/Support/Helper/Json/Encode.zep", 56);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_cast_to_string(&_7, &encoded);
	RETURN_CTOR(&_7);
}

