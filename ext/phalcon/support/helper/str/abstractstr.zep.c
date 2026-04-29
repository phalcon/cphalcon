
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Abstract class offering methods to help with the Str namespace. This can
 * be moved to a trait once Zephir supports it.
 *
 * @todo move to trait when there is support for it
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_AbstractStr)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, AbstractStr, phalcon, support_helper_str_abstractstr, phalcon_support_helper_str_abstractstr_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;
}

/**
 * Check if a string ends with a given string
 *
 * @param string $haystack
 * @param string $needle
 * @param bool   $ignoreCase
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Helper_Str_AbstractStr, toEndsWith)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ignoreCase;
	zval haystack_zv, needle_zv, *ignoreCase_param = NULL, child, parent, _0;
	zend_string *haystack = NULL, *needle = NULL;

	ZVAL_UNDEF(&haystack_zv);
	ZVAL_UNDEF(&needle_zv);
	ZVAL_UNDEF(&child);
	ZVAL_UNDEF(&parent);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(haystack)
		Z_PARAM_STR(needle)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(ignoreCase)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		ignoreCase_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR_COPY(&haystack_zv, haystack);
	ZVAL_STR_COPY(&needle_zv, needle);
	if (!ignoreCase_param) {
		ignoreCase = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (ZEPHIR_IS_IDENTICAL(&_0, &haystack_zv)) {
		RETURN_MM_BOOL(0);
	}
	if (EXPECTED(ignoreCase)) {
		ZEPHIR_CALL_FUNCTION(&child, "mb_strtolower", NULL, 7, &needle_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&parent, "mb_strtolower", NULL, 7, &haystack_zv);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&child, &needle_zv);
		ZEPHIR_CPY_WRT(&parent, &haystack_zv);
	}
	RETURN_MM_BOOL(zephir_end_with(&parent, &child, NULL));
}

/**
 * Interpolates context values into the message placeholders
 *
 * @see https://www.php-fig.org/psr/psr-3/ Section 1.2 Message
 *
 * @param string $input
 * @param array  $context
 * @param string $left
 * @param string $right
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_AbstractStr, toInterpolate)
{
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval input_zv, *context_param = NULL, left_zv, right_zv, key, replace, value, *_0, _1, _4$$4, _5$$5;
	zend_string *input = NULL, *left = NULL, *right = NULL, *_3;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&left_zv);
	ZVAL_UNDEF(&right_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&context);
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(context, context_param)
		Z_PARAM_STR(left)
		Z_PARAM_STR(right)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context_param = ZEND_CALL_ARG(execute_data, 2);
	}
	ZVAL_STR_COPY(&input_zv, input);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}
	if (!left) {
		left = zend_string_init(ZEND_STRL("%"), 0);
		ZVAL_STR(&left_zv, left);
	} else {
		ZVAL_STR_COPY(&left_zv, left);
	}
	if (!right) {
		right = zend_string_init(ZEND_STRL("%"), 0);
		ZVAL_STR(&right_zv, right);
	} else {
		ZVAL_STR_COPY(&right_zv, right);
	}
	if (ZEPHIR_IS_EMPTY(&context)) {
		RETURN_MM_STR(zend_string_copy(input));
	}
	ZEPHIR_INIT_VAR(&replace);
	array_init(&replace);
	zephir_is_iterable(&context, 0, "phalcon/Support/Helper/Str/AbstractStr.zep", 82);
	if (Z_TYPE_P(&context) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&context), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZEPHIR_CONCAT_VVV(&_4$$4, &left_zv, &key, &right_zv);
			zephir_array_update_zval(&replace, &_4$$4, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &context, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &context, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &context, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &context, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZEPHIR_CONCAT_VVV(&_5$$5, &left_zv, &key, &right_zv);
				zephir_array_update_zval(&replace, &_5$$5, &value, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &context, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 5, &input_zv, &replace);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Lowercases a string using mbstring
 *
 * @param string $text
 * @param string $encoding
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_AbstractStr, toLower)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, encoding_zv, _0;
	zend_string *text = NULL, *encoding = NULL;

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&encoding_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(encoding)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&text_zv, text);
	if (!encoding) {
		encoding = zend_string_init(ZEND_STRL("UTF-8"), 0);
		ZVAL_STR(&encoding_zv, encoding);
	} else {
		ZVAL_STR_COPY(&encoding_zv, encoding);
	}
	ZVAL_LONG(&_0, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_case", NULL, 11, &text_zv, &_0, &encoding_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check if a string starts with a given string
 *
 * @param string $haystack
 * @param string $needle
 * @param bool   $ignoreCase
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Helper_Str_AbstractStr, toStartsWith)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ignoreCase;
	zval haystack_zv, needle_zv, *ignoreCase_param = NULL, child, parent, _0;
	zend_string *haystack = NULL, *needle = NULL;

	ZVAL_UNDEF(&haystack_zv);
	ZVAL_UNDEF(&needle_zv);
	ZVAL_UNDEF(&child);
	ZVAL_UNDEF(&parent);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(haystack)
		Z_PARAM_STR(needle)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(ignoreCase)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		ignoreCase_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR_COPY(&haystack_zv, haystack);
	ZVAL_STR_COPY(&needle_zv, needle);
	if (!ignoreCase_param) {
		ignoreCase = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (ZEPHIR_IS_IDENTICAL(&_0, &haystack_zv)) {
		RETURN_MM_BOOL(0);
	}
	if (EXPECTED(ignoreCase)) {
		ZEPHIR_CALL_FUNCTION(&child, "mb_strtolower", NULL, 7, &needle_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&parent, "mb_strtolower", NULL, 7, &haystack_zv);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&child, &needle_zv);
		ZEPHIR_CPY_WRT(&parent, &haystack_zv);
	}
	RETURN_MM_BOOL(zephir_start_with(&parent, &child, NULL));
}

/**
 * Uppercases a string using mbstring
 *
 * @param string $text
 * @param string $encoding
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_AbstractStr, toUpper)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, encoding_zv, _0;
	zend_string *text = NULL, *encoding = NULL;

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&encoding_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(encoding)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&text_zv, text);
	if (!encoding) {
		encoding = zend_string_init(ZEND_STRL("UTF-8"), 0);
		ZVAL_STR(&encoding_zv, encoding);
	} else {
		ZVAL_STR_COPY(&encoding_zv, encoding);
	}
	ZVAL_LONG(&_0, 0);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_case", NULL, 11, &text_zv, &_0, &encoding_zv);
	zephir_check_call_status();
	RETURN_MM();
}

