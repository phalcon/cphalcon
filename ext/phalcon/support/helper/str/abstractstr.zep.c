
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
 * This file is part of the Phalcon.
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
	zval *haystack_param = NULL, *needle_param = NULL, *ignoreCase_param = NULL, child, parent, _0;
	zval haystack, needle;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&haystack);
	ZVAL_UNDEF(&needle);
	ZVAL_UNDEF(&child);
	ZVAL_UNDEF(&parent);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(haystack)
		Z_PARAM_STR(needle)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(ignoreCase)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &haystack_param, &needle_param, &ignoreCase_param);
	zephir_get_strval(&haystack, haystack_param);
	zephir_get_strval(&needle, needle_param);
	if (!ignoreCase_param) {
		ignoreCase = 1;
	} else {
		ignoreCase = zephir_get_boolval(ignoreCase_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (ZEPHIR_IS_IDENTICAL(&_0, &haystack)) {
		RETURN_MM_BOOL(0);
	}
	if (EXPECTED(ignoreCase)) {
		ZEPHIR_CALL_FUNCTION(&child, "mb_strtolower", NULL, 10, &needle);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&parent, "mb_strtolower", NULL, 10, &haystack);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&child, &needle);
		ZEPHIR_CPY_WRT(&parent, &haystack);
	}
	RETURN_MM_BOOL(zephir_end_with(&parent, &child, NULL));
}

/**
 * Interpolates context values into the message placeholders
 *
 * @see http://www.php-fig.org/psr/psr-3/ Section 1.2 Message
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
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *input_param = NULL, *context_param = NULL, *left_param = NULL, *right_param = NULL, key, replace, value, *_0, _1, _4$$4, _5$$5;
	zval input, left, right;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
		Z_PARAM_STR(left)
		Z_PARAM_STR(right)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &input_param, &context_param, &left_param, &right_param);
	zephir_get_strval(&input, input_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}
	if (!left_param) {
		ZEPHIR_INIT_VAR(&left);
		ZVAL_STRING(&left, "%");
	} else {
		zephir_get_strval(&left, left_param);
	}
	if (!right_param) {
		ZEPHIR_INIT_VAR(&right);
		ZVAL_STRING(&right, "%");
	} else {
		zephir_get_strval(&right, right_param);
	}


	if (ZEPHIR_IS_EMPTY(&context)) {
		RETURN_CTOR(&input);
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
			ZEPHIR_CONCAT_VVV(&_4$$4, &left, &key, &right);
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
				ZEPHIR_CONCAT_VVV(&_5$$5, &left, &key, &right);
				zephir_array_update_zval(&replace, &_5$$5, &value, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &context, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 5, &input, &replace);
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
	zval *text_param = NULL, *encoding_param = NULL, _0;
	zval text, encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&encoding);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(encoding)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &encoding_param);
	zephir_get_strval(&text, text_param);
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_STRING(&encoding, "UTF-8");
	} else {
		zephir_get_strval(&encoding, encoding_param);
	}


	ZVAL_LONG(&_0, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_case", NULL, 11, &text, &_0, &encoding);
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
	zval *haystack_param = NULL, *needle_param = NULL, *ignoreCase_param = NULL, child, parent, _0;
	zval haystack, needle;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&haystack);
	ZVAL_UNDEF(&needle);
	ZVAL_UNDEF(&child);
	ZVAL_UNDEF(&parent);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(haystack)
		Z_PARAM_STR(needle)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(ignoreCase)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &haystack_param, &needle_param, &ignoreCase_param);
	zephir_get_strval(&haystack, haystack_param);
	zephir_get_strval(&needle, needle_param);
	if (!ignoreCase_param) {
		ignoreCase = 1;
	} else {
		ignoreCase = zephir_get_boolval(ignoreCase_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (ZEPHIR_IS_IDENTICAL(&_0, &haystack)) {
		RETURN_MM_BOOL(0);
	}
	if (EXPECTED(ignoreCase)) {
		ZEPHIR_CALL_FUNCTION(&child, "mb_strtolower", NULL, 10, &needle);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&parent, "mb_strtolower", NULL, 10, &haystack);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&child, &needle);
		ZEPHIR_CPY_WRT(&parent, &haystack);
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
	zval *text_param = NULL, *encoding_param = NULL, _0;
	zval text, encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&encoding);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(encoding)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &encoding_param);
	zephir_get_strval(&text, text_param);
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_STRING(&encoding, "UTF-8");
	} else {
		zephir_get_strval(&encoding, encoding_param);
	}


	ZVAL_LONG(&_0, 0);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_case", NULL, 11, &text, &_0, &encoding);
	zephir_check_call_status();
	RETURN_MM();
}

