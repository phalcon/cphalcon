
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
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Decodes a string using `json_decode` and throws an exception if the
 * JSON data cannot be decoded
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Json_Decode)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Json, Decode, phalcon, support_helper_json_decode, phalcon_support_helper_json_decode_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $data        JSON data to parse
 * @param bool   $associative When `true`, objects are converted to arrays
 * @param int    $depth       Recursion depth.
 * @param int    $options     Bitmask of JSON decode options.
 *
 * @return mixed
 *
 * @throws InvalidArgumentException if the JSON cannot be decoded.
 * @link http://www.php.net/manual/en/function.json-decode.php
 */
PHP_METHOD(Phalcon_Support_Helper_Json_Decode, __invoke)
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
	zephir_get_strval(&data, data_param);
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
	ZEPHIR_CALL_FUNCTION(&_3, "json_last_error", NULL, 298);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_3, 0)) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "json_last_error_msg", NULL, 299);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SV(&_6$$3, "json_decode error: ", &_5$$3);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 40, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/Support/Helper/Json/Decode.zep", 45);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&decoded);
}

