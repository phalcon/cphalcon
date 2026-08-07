
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Filter\Sanitize\Upper
 *
 * Sanitizes a value to uppercase
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Upper)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, Upper, phalcon, filter_sanitize_upper, phalcon_filter_sanitize_upper_method_entry, 0);

	zend_class_implements(phalcon_filter_sanitize_upper_ce, 1, phalcon_contracts_filter_sanitizer_ce);
	return SUCCESS;
}

/**
 * @param string $input The text to sanitize
 *
 * @return false|string|string[]
 */
PHP_METHOD(Phalcon_Filter_Sanitize_Upper, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, _0;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phpmbconvertcase", NULL, 0, &input_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Converts the case of a string using `mb_convert_case()`
 *
 * @param string $input
 * @param int    $mode
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.mb-convert-case.php
 */
PHP_METHOD(Phalcon_Filter_Sanitize_Upper, phpMbConvertCase)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long mode, ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, *mode_param = NULL, _0, _1;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(input)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	mode_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	ZVAL_LONG(&_0, mode);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "UTF-8");
	ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_case", NULL, 304, &input_zv, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

