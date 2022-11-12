
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/filter.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Html\Escaper
 *
 * Escapes different kinds of text securing them. By using this component you
 * may prevent XSS attacks.
 *
 * This component only works with UTF-8. The PREG extension needs to be compiled
 * with UTF-8 support.
 *
 *```php
 * $escaper = new \Phalcon\Html\Escaper();
 *
 * $escaped = $escaper->escapeCss("font-family: <Verdana>");
 *
 * echo $escaped; // font\2D family\3A \20 \3C Verdana\3E
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html, Escaper, phalcon, html_escaper, phalcon_html_escaper_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_html_escaper_ce, SL("doubleEncode"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_escaper_ce, SL("encoding"), "utf-8", ZEND_ACC_PROTECTED);
	/**
	 * ENT_QUOTES | ENT_SUBSTITUTE | ENT_HTML401
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_html_escaper_ce, SL("flags"), 11, ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_html_escaper_ce, 1, phalcon_html_escaper_escaperinterface_ce);
	return SUCCESS;
}

/**
 * Escapes a HTML attribute string or array
 *
 * If the input is an array, the keys are the attribute names and the
 * values are attribute values. If a value is boolean (true/false) then
 * the attribute will have no value:
 * `['disabled' => true]` -> `'disabled``
 *
 * The resulting string will have attribute pairs separated by a space.
 *
 * @param array|string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, attributes)
{
	zend_bool _5$$4, _13$$8;
	zval _0$$3, _9$$4, _11$$7, _17$$8, _19$$11;
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input, input_sub, key, result, value, *_1, _2, _6$$4, _8$$4, _7$$6, _10$$7, _12$$7, _14$$8, _16$$8, _15$$10, _18$$11, _20$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_19$$11);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);


	if (EXPECTED((Z_TYPE_P(input) != IS_ARRAY))) {
		zephir_cast_to_string(&_0$$3, input);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phphtmlspecialchars", NULL, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	zephir_is_iterable(input, 0, "phalcon/Html/Escaper.zep", 96);
	if (Z_TYPE_P(input) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(input), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			_5$$4 = Z_TYPE_P(&value) == IS_NULL;
			if (!(_5$$4)) {
				_5$$4 = ZEPHIR_IS_FALSE_IDENTICAL(&value);
			}
			if (_5$$4) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_6$$4);
			zephir_fast_trim(&_6$$4, &key, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_CPY_WRT(&key, &_6$$4);
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_7$$6);
				zephir_fast_join_str(&_7$$6, SL(" "), &value);
				ZEPHIR_CPY_WRT(&value, &_7$$6);
			}
			zephir_cast_to_string(&_9$$4, &key);
			ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "phphtmlspecialchars", NULL, 0, &_9$$4);
			zephir_check_call_status();
			zephir_concat_self(&result, &_8$$4);
			if (!ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
				zephir_cast_to_string(&_11$$7, &value);
				ZEPHIR_CALL_METHOD(&_10$$7, this_ptr, "phphtmlspecialchars", NULL, 0, &_11$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$7);
				ZEPHIR_CONCAT_SVS(&_12$$7, "=\"", &_10$$7, "\"");
				zephir_concat_self(&result, &_12$$7);
			}
			zephir_concat_self_str(&result, SL(" "));
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, input, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, input, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, input, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, input, "current", NULL, 0);
			zephir_check_call_status();
				_13$$8 = Z_TYPE_P(&value) == IS_NULL;
				if (!(_13$$8)) {
					_13$$8 = ZEPHIR_IS_FALSE_IDENTICAL(&value);
				}
				if (_13$$8) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_14$$8);
				zephir_fast_trim(&_14$$8, &key, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_CPY_WRT(&key, &_14$$8);
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_15$$10);
					zephir_fast_join_str(&_15$$10, SL(" "), &value);
					ZEPHIR_CPY_WRT(&value, &_15$$10);
				}
				zephir_cast_to_string(&_17$$8, &key);
				ZEPHIR_CALL_METHOD(&_16$$8, this_ptr, "phphtmlspecialchars", NULL, 0, &_17$$8);
				zephir_check_call_status();
				zephir_concat_self(&result, &_16$$8);
				if (!ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
					zephir_cast_to_string(&_19$$11, &value);
					ZEPHIR_CALL_METHOD(&_18$$11, this_ptr, "phphtmlspecialchars", NULL, 0, &_19$$11);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_20$$11);
					ZEPHIR_CONCAT_SVS(&_20$$11, "=\"", &_18$$11, "\"");
					zephir_concat_self(&result, &_20$$11);
				}
				zephir_concat_self_str(&result, SL(" "));
			ZEPHIR_CALL_METHOD(NULL, input, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_fast_trim(return_value, &result, NULL , ZEPHIR_TRIM_RIGHT);
	RETURN_MM();
}

/**
 * Escape CSS strings by replacing non-alphanumeric chars by their
 * hexadecimal escaped representation
 *
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, css)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, _0;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeencoding", NULL, 322, &input);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "doescapecss", NULL, 323, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Detect the character encoding of a string to be handled by an encoder.
 * Special-handling for chr(172) and chr(128) to chr(159) which fail to be
 * detected by mb_detect_encoding()
 *
 * @param string $input
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Html_Escaper, detectEncoding)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, __$true, charset, _1, *_2, _3, _4$$5, _6$$7;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&charset);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);


	ZEPHIR_INIT_VAR(&charset);
	zephir_is_basic_charset(&charset, &input);
	if (Z_TYPE_P(&charset) == IS_STRING) {
		RETURN_CCTOR(&charset);
	}
	if (!((zephir_function_exists_ex(ZEND_STRL("mb_detect_encoding")) == SUCCESS))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "UTF-32");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "UTF-8");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ISO-8859-1");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ASCII");
	zephir_array_fast_append(&_0, &_1);
	zephir_is_iterable(&_0, 0, "phalcon/Html/Escaper.zep", 158);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _2)
		{
			ZEPHIR_INIT_NVAR(&charset);
			ZVAL_COPY(&charset, _2);
			ZEPHIR_CALL_FUNCTION(&_4$$5, "mb_detect_encoding", &_5, 324, &input, &charset, &__$true);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&_4$$5)) {
				RETURN_CCTOR(&charset);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&charset, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_6$$7, "mb_detect_encoding", &_5, 324, &input, &charset, &__$true);
				zephir_check_call_status();
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_6$$7)) {
					RETURN_CCTOR(&charset);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&charset);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_detect_encoding", &_5, 324, &input);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Escape CSS strings by replacing non-alphanumeric chars by their
 * hexadecimal escaped representation
 *
 * @param string $input
 *
 * @return string
 * @deprecated
 */
PHP_METHOD(Phalcon_Html_Escaper, escapeCss)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "css", NULL, 0, &input);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Escape JavaScript strings by replacing non-alphanumeric chars by their
 * hexadecimal escaped representation
 *
 * @param string $input
 *
 * @return string
 * @deprecated
 */
PHP_METHOD(Phalcon_Html_Escaper, escapeJs)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "js", NULL, 0, &input);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Escapes a HTML string. Internally uses htmlspecialchars
 *
 * @param string|null $input
 *
 * @return string
 * @deprecated
 */
PHP_METHOD(Phalcon_Html_Escaper, escapeHtml)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL;
	zval input, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &input_param);
	if (!input_param) {
		ZEPHIR_INIT_VAR(&input);
	} else {
		zephir_get_strval(&input, input_param);
	}


	zephir_cast_to_string(&_0, &input);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "html", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Escapes a HTML attribute string
 *
 * @param string|null $input
 *
 * @return string
 * @deprecated
 */
PHP_METHOD(Phalcon_Html_Escaper, escapeHtmlAttr)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL;
	zval input, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &input_param);
	if (!input_param) {
		ZEPHIR_INIT_VAR(&input);
	} else {
		zephir_get_strval(&input, input_param);
	}


	zephir_cast_to_string(&_0, &input);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "attributes", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Escapes a URL. Internally uses rawurlencode
 *
 * @param string $input
 *
 * @return string
 * @deprecated
 */
PHP_METHOD(Phalcon_Html_Escaper, escapeUrl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "url", NULL, 0, &input);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, getEncoding)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "encoding");
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Html_Escaper, getFlags)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "flags");
}

/**
 * Escapes a HTML string. Internally uses htmlspecialchars
 *
 * @param string|null $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, html)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, _0, _1, _2;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &input_param);
	if (!input_param) {
		ZEPHIR_INIT_VAR(&input);
	} else {
		zephir_get_strval(&input, input_param);
	}


	if (Z_TYPE_P(&input) == IS_NULL) {
		RETURN_MM_STRING("");
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("flags"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("encoding"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("doubleEncode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 284, &input, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Escape javascript strings by replacing non-alphanumeric chars by their
 * hexadecimal escaped representation
 *
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, js)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, _0;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeencoding", NULL, 322, &input);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "doescapejs", NULL, 325, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Utility to normalize a string's encoding to UTF-32.
 *
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, normalizeEncoding)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, _0, _1;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "detectencoding", NULL, 326, &input);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "UTF-32");
	ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_encoding", NULL, 327, &input, &_1, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets the double_encode to be used by the escaper
 *
 *```php
 * $escaper->setDoubleEncode(false);
 *```
 *
 * @param bool $doubleEncode
 */
PHP_METHOD(Phalcon_Html_Escaper, setDoubleEncode)
{
	zval *doubleEncode_param = NULL, __$true, __$false;
	zend_bool doubleEncode;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(doubleEncode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &doubleEncode_param);
	doubleEncode = zephir_get_boolval(doubleEncode_param);


	if (doubleEncode) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("doubleEncode"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("doubleEncode"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the encoding to be used by the escaper
 *
 *```php
 * $escaper->setEncoding("utf-8");
 *```
 *
 * @param string $encoding
 */
PHP_METHOD(Phalcon_Html_Escaper, setEncoding)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *encoding_param = NULL;
	zval encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&encoding);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(encoding)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &encoding_param);
	zephir_get_strval(&encoding, encoding_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("encoding"), &encoding);
	RETURN_THIS();
}

/**
 * Sets the HTML quoting type for htmlspecialchars
 *
 *```php
 * $escaper->setFlags(ENT_XHTML);
 *```
 *
 * @param int $flags
 */
PHP_METHOD(Phalcon_Html_Escaper, setFlags)
{
	zval *flags_param = NULL, _0;
	zend_long flags;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &flags_param);
	flags = zephir_get_intval(flags_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, flags);
	zephir_update_property_zval(this_ptr, ZEND_STRL("flags"), &_0);
	RETURN_THISW();
}

/**
 * Sets the HTML quoting type for htmlspecialchars
 *
 *```php
 * $escaper->setHtmlQuoteType(ENT_XHTML);
 *```
 *
 * @param int $flags
 * @deprecated
 */
PHP_METHOD(Phalcon_Html_Escaper, setHtmlQuoteType)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *flags_param = NULL, _0;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &flags_param);
	flags = zephir_get_intval(flags_param);


	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setflags", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Escapes a URL. Internally uses rawurlencode
 *
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, url)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);


	ZEPHIR_RETURN_CALL_FUNCTION("rawurlencode", NULL, 328, &input);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Proxy method for testing
 *
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, phpHtmlSpecialChars)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, _0, _1, _2;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("flags"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("encoding"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("doubleEncode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 284, &input, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, doEscapeCss)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *input_param = NULL;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);


	zephir_escape_css(return_value, &input);
	RETURN_MM();
}

/**
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, doEscapeJs)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *input_param = NULL;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);


	zephir_escape_js(return_value, &input);
	RETURN_MM();
}

