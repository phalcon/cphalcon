
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
#include "kernel/filter.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * Shared base for the per-context escaper objects. Holds the encoding,
 * htmlspecialchars flag, and double-encode toggle, plus the encoding
 * detection / normalization utilities used by the CSS and JS escapers.
 *
 * Each concrete context (`HtmlEscaper`, `AttributeEscaper`, `CssEscaper`,
 * `JsEscaper`, `UrlEscaper`) extends this so that callers can configure
 * one context without affecting the others.
 *
 * @property bool   $doubleEncode
 * @property string $encoding
 * @property int    $flags
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper_AbstractEscaper)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Escaper, AbstractEscaper, phalcon, html_escaper_abstractescaper, phalcon_html_escaper_abstractescaper_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_html_escaper_abstractescaper_ce, SL("doubleEncode"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_escaper_abstractescaper_ce, SL("encoding"), "utf-8", ZEND_ACC_PROTECTED);
	/**
	 * ENT_QUOTES | ENT_SUBSTITUTE | ENT_HTML401
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_html_escaper_abstractescaper_ce, SL("flags"), 11, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Detects the character encoding of a string. Special-handling for
 * chr(172) and chr(128) to chr(159) which fail to be detected by
 * `mb_detect_encoding()`.
 *
 * @param string $input
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Html_Escaper_AbstractEscaper, detectEncoding)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, __$true, charset, _1, *_2, _3, _4$$5, _6$$7;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&charset);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	ZEPHIR_INIT_VAR(&charset);
	zephir_is_basic_charset(&charset, &input_zv);
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
	zephir_is_iterable(&_0, 0, "phalcon/Html/Escaper/AbstractEscaper.zep", 77);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _2)
		{
			ZEPHIR_INIT_NVAR(&charset);
			ZVAL_COPY(&charset, _2);
			ZEPHIR_CALL_FUNCTION(&_4$$5, "mb_detect_encoding", &_5, 42, &input_zv, &charset, &__$true);
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
				ZEPHIR_CALL_FUNCTION(&_6$$7, "mb_detect_encoding", &_5, 42, &input_zv, &charset, &__$true);
				zephir_check_call_status();
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_6$$7)) {
					RETURN_CCTOR(&charset);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&charset);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_detect_encoding", &_5, 42, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return bool
 */
PHP_METHOD(Phalcon_Html_Escaper_AbstractEscaper, getDoubleEncode)
{

	RETURN_MEMBER(getThis(), "doubleEncode");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper_AbstractEscaper, getEncoding)
{

	RETURN_MEMBER_TYPED(getThis(), "encoding", IS_STRING);
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Html_Escaper_AbstractEscaper, getFlags)
{

	RETURN_MEMBER_TYPED(getThis(), "flags", IS_LONG);
}

/**
 * Normalizes a string's encoding to UTF-32, used by the CSS and JS
 * escapers before invoking the C-level escape routines.
 *
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper_AbstractEscaper, normalizeEncoding)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, _0, _1;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "detectencoding", NULL, 43, &input_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "UTF-32");
	ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_encoding", NULL, 44, &input_zv, &_1, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param bool $doubleEncode
 */
PHP_METHOD(Phalcon_Html_Escaper_AbstractEscaper, setDoubleEncode)
{
	zval *doubleEncode_param = NULL, __$true, __$false;
	zend_bool doubleEncode;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(doubleEncode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &doubleEncode_param);
	if (doubleEncode) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("doubleEncode"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("doubleEncode"), &__$false);
	}
	RETURN_THISW();
}

/**
 * @param string $encoding
 */
PHP_METHOD(Phalcon_Html_Escaper_AbstractEscaper, setEncoding)
{
	zval encoding_zv;
	zend_string *encoding = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&encoding_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(encoding)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&encoding_zv, encoding);
	zephir_update_property_zval(this_ptr, ZEND_STRL("encoding"), &encoding_zv);
	RETURN_THISW();
}

/**
 * @param int $flags
 */
PHP_METHOD(Phalcon_Html_Escaper_AbstractEscaper, setFlags)
{
	zval *flags_param = NULL, _0;
	zend_long flags;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flags_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, flags);
	zephir_update_property_zval(this_ptr, ZEND_STRL("flags"), &_0);
	RETURN_THISW();
}

