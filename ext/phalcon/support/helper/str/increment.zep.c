
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
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Adds a number to the end of a string or increments that number if it
 * is already defined
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Increment)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, Increment, phalcon, support_helper_str_increment, phalcon_support_helper_str_increment_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $text
 * @param string $separator
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Increment, __invoke)
{
	zend_long number = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval text_zv, separator_zv, parts, _1, _2, _0$$3;
	zend_string *text = NULL, *separator = NULL;

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(separator)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	if (!separator) {
		separator = zend_string_init(ZEND_STRL("_"), 0);
		zephir_memory_observe(&separator_zv);
		ZVAL_STR(&separator_zv, separator);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode(&parts, &separator_zv, &text_zv, LONG_MAX);
	number = 1;
	if (1 == zephir_array_isset_value_long(&parts, 1)) {
		zephir_memory_observe(&_0$$3);
		zephir_array_fetch_long(&_0$$3, &parts, 1, PH_NOISY, "phalcon/Support/Helper/Str/Increment.zep", 35);
		number = (zephir_get_intval(&_0$$3) + 1);
	}
	zephir_array_fetch_long(&_1, &parts, 0, PH_NOISY | PH_READONLY, "phalcon/Support/Helper/Str/Increment.zep", 38);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_2, number);
	ZEPHIR_CONCAT_VVV(return_value, &_1, &separator_zv, &_2);
	RETURN_MM();
}

