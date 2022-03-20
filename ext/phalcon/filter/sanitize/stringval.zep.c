
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
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
 * Sanitizes a value to string
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_StringVal)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, StringVal, phalcon, filter_sanitize_stringval, phalcon_filter_sanitize_stringval_method_entry, 0);

	return SUCCESS;
}

/**
 * @param mixed $input The text to sanitize
 *
 * @return string|false
 */
PHP_METHOD(Phalcon_Filter_Sanitize_StringVal, __invoke)
{
	zval _7, _8;
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input = NULL, input_sub, _0, _1, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);
	ZEPHIR_SEPARATE_PARAM(input);


	if (Z_TYPE_P(input) == IS_ARRAY) {
		RETURN_MM_BOOL(0);
	}
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_FUNCTION(&_1, "chr", NULL, 259, &_0);
	zephir_check_call_status();
	zephir_cast_to_string(&_2, input);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	ZEPHIR_INIT_NVAR(input);
	zephir_fast_str_replace(input, &_1, &_3, &_2);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/<[^>]*>?/");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "");
	ZEPHIR_CALL_FUNCTION(&_6, "preg_replace", NULL, 50, &_4, &_5, input);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(input, &_6);
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "'");
	zephir_array_fast_append(&_7, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "\"");
	zephir_array_fast_append(&_7, &_4);
	ZEPHIR_INIT_VAR(&_8);
	zephir_create_array(&_8, 2, 0);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "&#39;");
	zephir_array_fast_append(&_8, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "&#34;");
	zephir_array_fast_append(&_8, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	zephir_fast_str_replace(&_4, &_7, &_8, input);
	RETURN_CCTOR(&_4);
}

