
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
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
 * Phalcon\Helper\Base64
 *
 * This class offers quick string base64 functions
 */
ZEPHIR_INIT_CLASS(Phalcon_Helper_Base64)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Helper, Base64, phalcon, helper_base64, phalcon_helper_base64_method_entry, 0);

	return SUCCESS;
}

/**
 * Encode a json string in Base64 Url format.
 *
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Base64, encodeUrl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, _0, _1, _2, _3, _4;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	if (UNEXPECTED(Z_TYPE_P(input_param) != IS_STRING && Z_TYPE_P(input_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'input' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(input_param) == IS_STRING)) {
		zephir_get_strval(&input, input_param);
	} else {
		ZEPHIR_INIT_VAR(&input);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "base64_encode", NULL, 191, &input);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "+/");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "-_");
	ZEPHIR_CALL_FUNCTION(&_3, "strtr", NULL, 5, &_0, &_1, &_2);
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
 * Decode a Base64 Url string to a json string
 *
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Base64, decodeUrl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, remainder = 0;
	zval *input_param = NULL, data, _3, _4, _5, _0$$3, _1$$3, _2$$3;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	if (UNEXPECTED(Z_TYPE_P(input_param) != IS_STRING && Z_TYPE_P(input_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'input' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(input_param) == IS_STRING)) {
		zephir_get_strval(&input, input_param);
	} else {
		ZEPHIR_INIT_VAR(&input);
	}


	remainder = (long) (zephir_safe_mod_long_long(zephir_fast_strlen_ev(&input), 4));
	if (remainder) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "=");
		ZVAL_LONG(&_1$$3, (4 - remainder));
		ZEPHIR_CALL_FUNCTION(&_2$$3, "str_repeat", NULL, 1, &_0$$3, &_1$$3);
		zephir_check_call_status();
		zephir_concat_self(&input, &_2$$3);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "-_");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "+/");
	ZEPHIR_CALL_FUNCTION(&_5, "strtr", NULL, 5, &input, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&data, "base64_decode", NULL, 188, &_5);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
		ZEPHIR_INIT_NVAR(&data);
		ZVAL_STRING(&data, "");
	}
	RETURN_CCTOR(&data);
}

