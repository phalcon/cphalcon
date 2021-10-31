
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * This class offers a wrapper for JSON methods to serialize and unserialize
 */
ZEPHIR_INIT_CLASS(Phalcon_Helper_Json)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Helper, Json, phalcon, helper_json, phalcon_helper_json_method_entry, 0);

	return SUCCESS;
}

/**
 * Decodes a string using `json_decode` and throws an exception if the
 * JSON data cannot be decoded
 *
 * ```php
 * use Phalcon\Helper\Json;
 *
 * $data = '{"one":"two","0":"three"}';
 *
 * var_dump(Json::decode($data));
 * // [
 * //     'one' => 'two',
 * //     'three'
 * // ];
 * ```
 *
 * @param string $data        JSON data to parse
 * @param bool   $associative When `true`, objects are converted to arrays
 * @param int    $depth       Recursion depth.
 * @param int    $options     Bitmask of JSON decode options.
 *
 * @return mixed
 *
 * @throws \InvalidArgumentException if the JSON cannot be decoded.
 * @link http://www.php.net/manual/en/function.json-decode.php
 */
PHP_METHOD(Phalcon_Helper_Json, decode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long depth, options, ZEPHIR_LAST_CALL_STATUS;
	zend_bool associative;
	zval *data_param = NULL, *associative_param = NULL, *depth_param = NULL, *options_param = NULL, decoded, _0, _1, _2, _3, _4$$3, _5$$3, _6$$3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(associative)
		Z_PARAM_LONG(depth)
		Z_PARAM_LONG(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &data_param, &associative_param, &depth_param, &options_param);
	if (UNEXPECTED(Z_TYPE_P(data_param) != IS_STRING && Z_TYPE_P(data_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(data_param) == IS_STRING)) {
		zephir_get_strval(&data, data_param);
	} else {
		ZEPHIR_INIT_VAR(&data);
	}
	if (!associative_param) {
		associative = 0;
	} else {
		associative = zephir_get_boolval(associative_param);
	}
	if (!depth_param) {
		depth = 512;
	} else {
		depth = zephir_get_intval(depth_param);
	}
	if (!options_param) {
		options = 0;
	} else {
		options = zephir_get_intval(options_param);
	}


	ZVAL_BOOL(&_0, (associative ? 1 : 0));
	ZVAL_LONG(&_1, depth);
	ZVAL_LONG(&_2, options);
	ZEPHIR_INIT_VAR(&decoded);
	zephir_json_decode(&decoded, &data, zephir_get_intval(&_0) );
	ZEPHIR_CALL_FUNCTION(&_3, "json_last_error", NULL, 296);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_LONG_IDENTICAL(&_3, 0))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "json_last_error_msg", NULL, 297);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SV(&_6$$3, "json_decode error: ", &_5$$3);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 40, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/Helper/Json.zep", 60);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&decoded);
}

/**
 * Encodes a string using `json_encode` and throws an exception if the
 * JSON data cannot be encoded
 *
 * ```php
 * use Phalcon\Helper\Json;
 *
 * $data = [
 *     'one' => 'two',
 *     'three'
 * ];
 *
 * echo Json::encode($data);
 * // {"one":"two","0":"three"}
 * ```
 *
 * @param mixed  $data        JSON data to parse
 * @param int    $options     Bitmask of JSON decode options.
 * @param int    $depth       Recursion depth.
 *
 * @return mixed
 *
 * @throws \InvalidArgumentException if the JSON cannot be encoded.
 * @link http://www.php.net/manual/en/function.json-encode.php
 */
PHP_METHOD(Phalcon_Helper_Json, encode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long options, depth, ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, *options_param = NULL, *depth_param = NULL, encoded, _0, _1, _2, _3$$3, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&encoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
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
		options = 0;
	} else {
		options = zephir_get_intval(options_param);
	}
	if (!depth_param) {
		depth = 512;
	} else {
		depth = zephir_get_intval(depth_param);
	}


	ZVAL_LONG(&_0, options);
	ZVAL_LONG(&_1, depth);
	ZEPHIR_INIT_VAR(&encoded);
	zephir_json_encode(&encoded, data, zephir_get_intval(&_0) );
	ZEPHIR_CALL_FUNCTION(&_2, "json_last_error", NULL, 296);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_LONG_IDENTICAL(&_2, 0))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "json_last_error_msg", NULL, 297);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_SV(&_5$$3, "json_encode error: ", &_4$$3);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 40, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Helper/Json.zep", 104);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&encoded);
}

