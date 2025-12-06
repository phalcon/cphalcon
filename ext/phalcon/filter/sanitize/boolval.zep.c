
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
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
 * Phalcon\Filter\Sanitize\BoolVal
 *
 * Sanitizes a value to boolean
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_BoolVal)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, BoolVal, phalcon, filter_sanitize_boolval, phalcon_filter_sanitize_boolval_method_entry, 0);

	return SUCCESS;
}

/**
 * @param mixed $input The text to sanitize
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Filter_Sanitize_BoolVal, __invoke)
{
	zend_bool _1, _2, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input = NULL, input_sub, falseArray, trueArray, _0, _3;

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&falseArray);
	ZVAL_UNDEF(&trueArray);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &input);
	ZEPHIR_SEPARATE_PARAM(input);
	ZEPHIR_INIT_VAR(&trueArray);
	zephir_create_array(&trueArray, 5, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "true");
	zephir_array_fast_append(&trueArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "on");
	zephir_array_fast_append(&trueArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "yes");
	zephir_array_fast_append(&trueArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "y");
	zephir_array_fast_append(&trueArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "1");
	zephir_array_fast_append(&trueArray, &_0);
	ZEPHIR_INIT_VAR(&falseArray);
	zephir_create_array(&falseArray, 5, 0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "false");
	zephir_array_fast_append(&falseArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "off");
	zephir_array_fast_append(&falseArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "no");
	zephir_array_fast_append(&falseArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "n");
	zephir_array_fast_append(&falseArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "0");
	zephir_array_fast_append(&falseArray, &_0);
	_1 = Z_TYPE_P(input) == IS_STRING;
	if (!(_1)) {
		_1 = Z_TYPE_P(input) == IS_LONG;
	}
	_2 = _1;
	if (!(_2)) {
		_2 = (Z_TYPE_P(input) == IS_TRUE || Z_TYPE_P(input) == IS_FALSE);
	}
	if (1 != _2) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_3);
	if (Z_TYPE_P(input) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_fast_trim(&_0, input, NULL , ZEPHIR_TRIM_BOTH);
		ZEPHIR_CALL_FUNCTION(&_3, "mb_strtolower", NULL, 10, &_0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_3, input);
	}
	ZEPHIR_CPY_WRT(input, &_3);
	_4 = ZEPHIR_IS_TRUE_IDENTICAL(input);
	if (!(_4)) {
		_4 = 1 == zephir_fast_in_array(input, &trueArray);
	}
	if (_4) {
		RETURN_MM_BOOL(1);
	}
	_5 = ZEPHIR_IS_FALSE_IDENTICAL(input);
	if (!(_5)) {
		_5 = 1 == zephir_fast_in_array(input, &falseArray);
	}
	if (_5) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(zephir_get_boolval(input));
}

