
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
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
	zval *text_param = NULL, *separator_param = NULL, parts, _1, _2, _0$$3;
	zval text, separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(separator)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &separator_param);
	zephir_get_strval(&text, text_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "_");
	} else {
		zephir_get_strval(&separator, separator_param);
	}


	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode(&parts, &separator, &text, LONG_MAX);
	number = 1;
	if (1 == zephir_array_isset_long(&parts, 1)) {
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_array_fetch_long(&_0$$3, &parts, 1, PH_NOISY, "phalcon/Support/Helper/Str/Increment.zep", 35);
		number = (zephir_get_intval(&_0$$3) + 1);
	}
	zephir_array_fetch_long(&_1, &parts, 0, PH_NOISY | PH_READONLY, "phalcon/Support/Helper/Str/Increment.zep", 38);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_2, number);
	ZEPHIR_CONCAT_VVV(return_value, &_1, &separator, &_2);
	RETURN_MM();
}

