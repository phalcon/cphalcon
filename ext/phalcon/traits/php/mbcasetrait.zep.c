
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Multibyte case conversion wrapper method
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_MbCaseTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Php, MbCaseTrait, phalcon, traits_php_mbcasetrait, phalcon_traits_php_mbcasetrait_method_entry);

	return SUCCESS;
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
PHP_METHOD(Phalcon_Traits_Php_MbCaseTrait, phpMbConvertCase)
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

