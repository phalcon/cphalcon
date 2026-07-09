
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
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
 * Multibyte case conversion wrapper method
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_MbCaseTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Php, MbCaseTrait, phalcon, traits_php_mbcasetrait, phalcon_traits_php_mbcasetrait_method_entry);

	return SUCCESS;
}

/**
 * Converts the case of a string using `mb_convert_case()` when the
 * `mbstring` extension is available, otherwise applies the passed fallback
 * function to the `utf8_decode()`d input.
 *
 * @param string $input
 * @param int    $mode
 * @param string $fallback
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.mb-convert-case.php
 */
PHP_METHOD(Phalcon_Traits_Php_MbCaseTrait, phpMbConvertCase)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long mode, ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, *mode_param = NULL, fallback_zv, _0$$3, _1$$3, _2;
	zend_string *input = NULL, *fallback = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&fallback_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(input)
		Z_PARAM_LONG(mode)
		Z_PARAM_STR(fallback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	mode_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	zephir_memory_observe(&fallback_zv);
	ZVAL_STR_COPY(&fallback_zv, fallback);
	if (1 == (zephir_function_exists_ex(ZEND_STRL("mb_convert_case")) == SUCCESS)) {
		ZVAL_LONG(&_0$$3, mode);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "UTF-8");
		ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_case", NULL, 0, &input_zv, &_0$$3, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_2, "utf8_decode", NULL, 0, &input_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(&fallback_zv, NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

