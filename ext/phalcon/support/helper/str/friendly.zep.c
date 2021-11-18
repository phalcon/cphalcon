
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
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
 * Changes a text to a URL friendly one. Replaces commonly known accented
 * characters with their Latin equivalents. If a `replace` string or array
 * is passed, it will also be used to replace those characters with a space.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Friendly)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Support\\Helper\\Str, Friendly, phalcon, support_helper_str_friendly, phalcon_support_helper_str_abstractstr_ce, phalcon_support_helper_str_friendly_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string     $text
 * @param string     $separator
 * @param bool       $lowercase
 * @param mixed|null $replace
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Friendly, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool lowercase;
	zval *text_param = NULL, *separator_param = NULL, *lowercase_param = NULL, *replace = NULL, replace_sub, __$null, friendly, matrix, _1, _2, _3, _4, _5, _7, _0$$3, _6$$5;
	zval text, separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&replace_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&friendly);
	ZVAL_UNDEF(&matrix);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_6$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(separator)
		Z_PARAM_BOOL(lowercase)
		Z_PARAM_ZVAL_OR_NULL(replace)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &text_param, &separator_param, &lowercase_param, &replace);
	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
	}
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "-");
	} else {
	if (UNEXPECTED(Z_TYPE_P(separator_param) != IS_STRING && Z_TYPE_P(separator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'separator' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(separator_param) == IS_STRING)) {
		zephir_get_strval(&separator, separator_param);
	} else {
		ZEPHIR_INIT_VAR(&separator);
	}
	}
	if (!lowercase_param) {
		lowercase = 1;
	} else {
		lowercase = zephir_get_boolval(lowercase_param);
	}
	if (!replace) {
		replace = &replace_sub;
		ZEPHIR_CPY_WRT(replace, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(replace);
	}


	if (zephir_is_true(replace)) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "checkreplace", NULL, 0, replace);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(replace, &_0$$3);
	} else {
		ZEPHIR_INIT_NVAR(replace);
		array_init(replace);
	}
	ZEPHIR_CALL_METHOD(&matrix, this_ptr, "getmatrix", NULL, 0, replace);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_array_keys(&_2, &matrix);
	ZEPHIR_CALL_FUNCTION(&_3, "array_values", NULL, 13, &matrix);
	zephir_check_call_status();
	zephir_fast_str_replace(&_1, &_2, &_3, &text);
	zephir_get_strval(&text, &_1);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/[^a-zA-Z0-9\\/_|+ -]/");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "");
	ZEPHIR_CALL_FUNCTION(&friendly, "preg_replace", NULL, 49, &_4, &_5, &text);
	zephir_check_call_status();
	if (lowercase) {
		ZEPHIR_INIT_VAR(&_6$$5);
		zephir_fast_strtolower(&_6$$5, &friendly);
		ZEPHIR_CPY_WRT(&friendly, &_6$$5);
	}
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "/[\\/_|+ -]+/");
	ZEPHIR_CALL_FUNCTION(&_7, "preg_replace", NULL, 49, &_4, &separator, &friendly);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&friendly, &_7);
	zephir_fast_trim(return_value, &friendly, &separator, ZEPHIR_TRIM_BOTH);
	RETURN_MM();
}

/**
 * @param mixed $replace
 *
 * @return array
 * @throws Exception
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Friendly, checkReplace)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *replace = NULL, replace_sub, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&replace_sub);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(replace)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &replace);
	ZEPHIR_SEPARATE_PARAM(replace);


	_0 = Z_TYPE_P(replace) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(replace) != IS_STRING;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_support_helper_exception_ce, "Parameter replace must be an array or a string", "phalcon/Support/Helper/Str/Friendly.zep", 74);
		return;
	}
	if (Z_TYPE_P(replace) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 1, 0);
		zephir_array_fast_append(&_1$$4, replace);
		ZEPHIR_CPY_WRT(replace, &_1$$4);
	}
	RETVAL_ZVAL(replace, 1, 0);
	RETURN_MM();
}

/**
 * @param mixed $replace
 *
 * @return array
 * @throws Exception
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Friendly, getMatrix)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *replace_param = NULL, item, *_0, _1, _2$$3, _3$$4;
	zval replace, matrix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&matrix);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(replace)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &replace_param);
	zephir_get_arrval(&replace, replace_param);


	ZEPHIR_INIT_VAR(&matrix);
	zephir_create_array(&matrix, 79, 0);
	add_assoc_stringl_ex(&matrix, SL("Š"), SL("S"));
	add_assoc_stringl_ex(&matrix, SL("š"), SL("s"));
	add_assoc_stringl_ex(&matrix, SL("Đ"), SL("Dj"));
	add_assoc_stringl_ex(&matrix, SL("Ð"), SL("Dj"));
	add_assoc_stringl_ex(&matrix, SL("đ"), SL("dj"));
	add_assoc_stringl_ex(&matrix, SL("Ž"), SL("Z"));
	add_assoc_stringl_ex(&matrix, SL("ž"), SL("z"));
	add_assoc_stringl_ex(&matrix, SL("Č"), SL("C"));
	add_assoc_stringl_ex(&matrix, SL("č"), SL("c"));
	add_assoc_stringl_ex(&matrix, SL("Ć"), SL("C"));
	add_assoc_stringl_ex(&matrix, SL("ć"), SL("c"));
	add_assoc_stringl_ex(&matrix, SL("À"), SL("A"));
	add_assoc_stringl_ex(&matrix, SL("Á"), SL("A"));
	add_assoc_stringl_ex(&matrix, SL("Â"), SL("A"));
	add_assoc_stringl_ex(&matrix, SL("Ã"), SL("A"));
	add_assoc_stringl_ex(&matrix, SL("Ä"), SL("A"));
	add_assoc_stringl_ex(&matrix, SL("Å"), SL("A"));
	add_assoc_stringl_ex(&matrix, SL("Æ"), SL("A"));
	add_assoc_stringl_ex(&matrix, SL("Ç"), SL("C"));
	add_assoc_stringl_ex(&matrix, SL("È"), SL("E"));
	add_assoc_stringl_ex(&matrix, SL("É"), SL("E"));
	add_assoc_stringl_ex(&matrix, SL("Ê"), SL("E"));
	add_assoc_stringl_ex(&matrix, SL("Ë"), SL("E"));
	add_assoc_stringl_ex(&matrix, SL("Ì"), SL("I"));
	add_assoc_stringl_ex(&matrix, SL("Í"), SL("I"));
	add_assoc_stringl_ex(&matrix, SL("Î"), SL("I"));
	add_assoc_stringl_ex(&matrix, SL("Ï"), SL("I"));
	add_assoc_stringl_ex(&matrix, SL("Ñ"), SL("N"));
	add_assoc_stringl_ex(&matrix, SL("Ò"), SL("O"));
	add_assoc_stringl_ex(&matrix, SL("Ó"), SL("O"));
	add_assoc_stringl_ex(&matrix, SL("Ô"), SL("O"));
	add_assoc_stringl_ex(&matrix, SL("Õ"), SL("O"));
	add_assoc_stringl_ex(&matrix, SL("Ö"), SL("O"));
	add_assoc_stringl_ex(&matrix, SL("Ø"), SL("O"));
	add_assoc_stringl_ex(&matrix, SL("Ù"), SL("U"));
	add_assoc_stringl_ex(&matrix, SL("Ú"), SL("U"));
	add_assoc_stringl_ex(&matrix, SL("Û"), SL("U"));
	add_assoc_stringl_ex(&matrix, SL("Ü"), SL("U"));
	add_assoc_stringl_ex(&matrix, SL("Ý"), SL("Y"));
	add_assoc_stringl_ex(&matrix, SL("Þ"), SL("B"));
	add_assoc_stringl_ex(&matrix, SL("ß"), SL("Ss"));
	add_assoc_stringl_ex(&matrix, SL("à"), SL("a"));
	add_assoc_stringl_ex(&matrix, SL("á"), SL("a"));
	add_assoc_stringl_ex(&matrix, SL("â"), SL("a"));
	add_assoc_stringl_ex(&matrix, SL("ã"), SL("a"));
	add_assoc_stringl_ex(&matrix, SL("ä"), SL("a"));
	add_assoc_stringl_ex(&matrix, SL("å"), SL("a"));
	add_assoc_stringl_ex(&matrix, SL("æ"), SL("a"));
	add_assoc_stringl_ex(&matrix, SL("ç"), SL("c"));
	add_assoc_stringl_ex(&matrix, SL("è"), SL("e"));
	add_assoc_stringl_ex(&matrix, SL("é"), SL("e"));
	add_assoc_stringl_ex(&matrix, SL("ê"), SL("e"));
	add_assoc_stringl_ex(&matrix, SL("ë"), SL("e"));
	add_assoc_stringl_ex(&matrix, SL("ì"), SL("i"));
	add_assoc_stringl_ex(&matrix, SL("í"), SL("i"));
	add_assoc_stringl_ex(&matrix, SL("î"), SL("i"));
	add_assoc_stringl_ex(&matrix, SL("ï"), SL("i"));
	add_assoc_stringl_ex(&matrix, SL("ð"), SL("o"));
	add_assoc_stringl_ex(&matrix, SL("ñ"), SL("n"));
	add_assoc_stringl_ex(&matrix, SL("ò"), SL("o"));
	add_assoc_stringl_ex(&matrix, SL("ó"), SL("o"));
	add_assoc_stringl_ex(&matrix, SL("ô"), SL("o"));
	add_assoc_stringl_ex(&matrix, SL("õ"), SL("o"));
	add_assoc_stringl_ex(&matrix, SL("ö"), SL("o"));
	add_assoc_stringl_ex(&matrix, SL("ø"), SL("o"));
	add_assoc_stringl_ex(&matrix, SL("ù"), SL("u"));
	add_assoc_stringl_ex(&matrix, SL("ú"), SL("u"));
	add_assoc_stringl_ex(&matrix, SL("û"), SL("u"));
	add_assoc_stringl_ex(&matrix, SL("ý"), SL("y"));
	add_assoc_stringl_ex(&matrix, SL("þ"), SL("b"));
	add_assoc_stringl_ex(&matrix, SL("ÿ"), SL("y"));
	add_assoc_stringl_ex(&matrix, SL("Ŕ"), SL("R"));
	add_assoc_stringl_ex(&matrix, SL("ŕ"), SL("r"));
	add_assoc_stringl_ex(&matrix, SL("ē"), SL("e"));
	add_assoc_stringl_ex(&matrix, SL("'"), SL(""));
	add_assoc_stringl_ex(&matrix, SL("&"), SL(" and "));
	add_assoc_stringl_ex(&matrix, SL("\r\n"), SL(" "));
	add_assoc_stringl_ex(&matrix, SL("\n"), SL(" "));
	zephir_is_iterable(&replace, 0, "phalcon/Support/Helper/Str/Friendly.zep", 122);
	if (Z_TYPE_P(&replace) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&replace), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, " ");
			zephir_array_update_zval(&matrix, &item, &_2$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &replace, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &replace, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &replace, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_3$$4);
				ZVAL_STRING(&_3$$4, " ");
				zephir_array_update_zval(&matrix, &item, &_3$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &replace, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CTOR(&matrix);
}

