
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Base64 based wrapper methods
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_Base64Trait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Php, Base64Trait, phalcon, traits_php_base64trait, phalcon_traits_php_base64trait_method_entry);

	return SUCCESS;
}

/**
 * Decode a Base64 URL string
 *
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Traits_Php_Base64Trait, doDecodeUrl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, remainder = 0;
	zval *input_param = NULL, data, _0, _4, _5, _6, _1$$3, _2$$3, _3$$3;
	zval input;

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(input_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);
	ZEPHIR_CALL_FUNCTION(&_0, "mb_strlen", NULL, 0, &input);
	zephir_check_call_status();
	remainder = zephir_safe_mod_zval_long(&_0, 4);
	if (remainder) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "=");
		ZVAL_LONG(&_2$$3, (4 - remainder));
		ZEPHIR_CALL_FUNCTION(&_3$$3, "str_repeat", NULL, 7, &_1$$3, &_2$$3);
		zephir_check_call_status();
		zephir_concat_self(&input, &_3$$3);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "-_");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "+/");
	ZEPHIR_CALL_FUNCTION(&_6, "strtr", NULL, 4, &input, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&data, "base64_decode", NULL, 0, &_6);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
		ZEPHIR_INIT_NVAR(&data);
		ZVAL_STRING(&data, "");
	}
	RETURN_CCTOR(&data);
}

/**
 * Encode a string in Base64 URL format
 *
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Traits_Php_Base64Trait, doEncodeUrl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, _0, _1, _2, _3, _4;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	ZEPHIR_CALL_FUNCTION(&_0, "base64_encode", NULL, 0, &input_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "+/");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "-_");
	ZEPHIR_CALL_FUNCTION(&_3, "strtr", NULL, 4, &_0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "=");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_str_replace(&_4, &_1, &_2, &_3);
	RETURN_CCTOR(&_4);
}

/**
 * @param string $input
 * @param bool   $strict
 *
 * @return string|false
 *
 * @link https://php.net/manual/en/function.base64-decode.php
 */
PHP_METHOD(Phalcon_Traits_Php_Base64Trait, phpBase64Decode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool strict;
	zval input_zv, *strict_param = NULL, _0;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(strict)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		strict_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!strict_param) {
		strict = 0;
	} else {
		}
	ZVAL_BOOL(&_0, (strict ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("base64_decode", NULL, 0, &input_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $input
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.base64-encode.php
 */
PHP_METHOD(Phalcon_Traits_Php_Base64Trait, phpBase64Encode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 0, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

