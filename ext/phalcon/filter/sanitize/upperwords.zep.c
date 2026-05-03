
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Filter\Sanitize\UpperWords
 *
 * Sanitizes a value to uppercase the first character of each word
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_UpperWords)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, UpperWords, phalcon, filter_sanitize_upperwords, phalcon_filter_sanitize_upperwords_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $input The text to sanitize
 *
 * @return false|string|string[]
 */
PHP_METHOD(Phalcon_Filter_Sanitize_UpperWords, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, _0$$3, _1$$3, _2;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&input_zv, input);
	if (1 == (zephir_function_exists_ex(ZEND_STRL("mb_convert_case")) == SUCCESS)) {
		ZVAL_LONG(&_0$$3, 2);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "UTF-8");
		ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_case", NULL, 11, &input_zv, &_0$$3, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_2, "utf8_decode", NULL, 310, &input_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("ucwords", NULL, 313, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

