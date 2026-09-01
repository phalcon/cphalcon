
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Encodes data using `json_encode`, throwing the native `\JsonException` on
 * failure. Any framework-flavored exception is added by the `Support` helper
 * class that wraps this trait.
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Support_Helper_Json_EncodeTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Support\\Helper\\Json, EncodeTrait, phalcon, traits_support_helper_json_encodetrait, phalcon_traits_support_helper_json_encodetrait_method_entry);

	return SUCCESS;
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
PHP_METHOD(Phalcon_Traits_Support_Helper_Json_EncodeTrait, toEncode)
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

