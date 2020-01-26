
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Provides utilities to work with texts
 */
ZEPHIR_INIT_CLASS(Phalcon_Text) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Text, phalcon, text, phalcon_text_method_entry, 0);

	zephir_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_ALNUM"), 0);

	zephir_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_ALPHA"), 1);

	zephir_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_DISTINCT"), 5);

	zephir_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_HEXDEC"), 2);

	zephir_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_NOZERO"), 4);

	zephir_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_NUMERIC"), 3);

	return SUCCESS;

}

/**
 * Converts strings to camelize style
 *
 * ```php
 * echo Phalcon\Text::camelize("coco_bongo"); // CocoBongo
 * echo Phalcon\Text::camelize("co_co-bon_go", "-"); // Co_coBon_go
 * echo Phalcon\Text::camelize("co_co-bon_go", "_-"); // CoCoBonGo
 * ```
 */
PHP_METHOD(Phalcon_Text, camelize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *text_param = NULL, *delimiter = NULL, delimiter_sub, __$null;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&delimiter_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &delimiter);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!delimiter) {
		delimiter = &delimiter_sub;
		delimiter = &__$null;
	}


	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_str_ce, "camelize", &_0, 0, &text, delimiter);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Concatenates strings using the separator only once without duplication in
 * places concatenation
 *
 * ```php
 * $str = Phalcon\Text::concat(
 *     "/",
 *     "/tmp/",
 *     "/folder_1/",
 *     "/folder_2",
 *     "folder_3/"
 * );
 *
 * // /tmp/folder_1/folder_2/folder_3/
 * echo $str;
 * ```
 *
 * @param string separator
 * @param string a
 * @param string b
 * @param string ...N
 */
PHP_METHOD(Phalcon_Text, concat) {

	zval args, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	zephir_get_args(&args);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Helper\\Str::concat");
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generates random text in accordance with the template
 *
 * ```php
 * // Hi my name is a Bob
 * echo Phalcon\Text::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
 *
 * // Hi my name is a Jon
 * echo Phalcon\Text::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
 *
 * // Hello my name is a Bob
 * echo Phalcon\Text::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
 *
 * // Hello my name is a Zyxep
 * echo Phalcon\Text::dynamic(
 *     "[Hi/Hello], my name is a [Zyxep/Mark]!",
 *     "[", "]",
 *     "/"
 * );
 * ```
 */
PHP_METHOD(Phalcon_Text, dynamic) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *text_param = NULL, *leftDelimiter_param = NULL, *rightDelimiter_param = NULL, *separator_param = NULL;
	zval text, leftDelimiter, rightDelimiter, separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&leftDelimiter);
	ZVAL_UNDEF(&rightDelimiter);
	ZVAL_UNDEF(&separator);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &text_param, &leftDelimiter_param, &rightDelimiter_param, &separator_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!leftDelimiter_param) {
		ZEPHIR_INIT_VAR(&leftDelimiter);
		ZVAL_STRING(&leftDelimiter, "{");
	} else {
	if (UNEXPECTED(Z_TYPE_P(leftDelimiter_param) != IS_STRING && Z_TYPE_P(leftDelimiter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'leftDelimiter' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(leftDelimiter_param) == IS_STRING)) {
		zephir_get_strval(&leftDelimiter, leftDelimiter_param);
	} else {
		ZEPHIR_INIT_VAR(&leftDelimiter);
		ZVAL_EMPTY_STRING(&leftDelimiter);
	}
	}
	if (!rightDelimiter_param) {
		ZEPHIR_INIT_VAR(&rightDelimiter);
		ZVAL_STRING(&rightDelimiter, "}");
	} else {
	if (UNEXPECTED(Z_TYPE_P(rightDelimiter_param) != IS_STRING && Z_TYPE_P(rightDelimiter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rightDelimiter' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(rightDelimiter_param) == IS_STRING)) {
		zephir_get_strval(&rightDelimiter, rightDelimiter_param);
	} else {
		ZEPHIR_INIT_VAR(&rightDelimiter);
		ZVAL_EMPTY_STRING(&rightDelimiter);
	}
	}
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "|");
	} else {
	if (UNEXPECTED(Z_TYPE_P(separator_param) != IS_STRING && Z_TYPE_P(separator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'separator' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(separator_param) == IS_STRING)) {
		zephir_get_strval(&separator, separator_param);
	} else {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_EMPTY_STRING(&separator);
	}
	}


	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_str_ce, "dynamic", &_0, 0, &text, &leftDelimiter, &rightDelimiter, &separator);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if a string ends with a given string
 *
 * ```php
 * echo Phalcon\Text::endsWith("Hello", "llo"); // true
 * echo Phalcon\Text::endsWith("Hello", "LLO", false); // false
 * echo Phalcon\Text::endsWith("Hello", "LLO"); // true
 * ```
 */
PHP_METHOD(Phalcon_Text, endsWith) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_bool ignoreCase;
	zval *text_param = NULL, *end_param = NULL, *ignoreCase_param = NULL, _1;
	zval text, end;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &text_param, &end_param, &ignoreCase_param);

	zephir_get_strval(&text, text_param);
	zephir_get_strval(&end, end_param);
	if (!ignoreCase_param) {
		ignoreCase = 1;
	} else {
		ignoreCase = zephir_get_boolval(ignoreCase_param);
	}


	if (ignoreCase) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_str_ce, "endswith", &_0, 269, &text, &end, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Makes an underscored or dashed phrase human-readable
 *
 * ```php
 * echo Phalcon\Text::humanize("start-a-horse"); // "start a horse"
 * echo Phalcon\Text::humanize("five_cats"); // "five cats"
 * ```
 */
PHP_METHOD(Phalcon_Text, humanize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *text_param = NULL;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}


	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_str_ce, "humanize", &_0, 0, &text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a number to a string or increment that number if it already is
 * defined
 *
 * ```php
 * echo Phalcon\Text::increment("a"); // "a_1"
 * echo Phalcon\Text::increment("a_1"); // "a_2"
 * ```
 */
PHP_METHOD(Phalcon_Text, increment) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *text_param = NULL, *separator_param = NULL;
	zval text, separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&separator);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &separator_param);

	zephir_get_strval(&text, text_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "_");
	} else {
		zephir_get_strval(&separator, separator_param);
	}


	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_str_ce, "increment", &_0, 0, &text, &separator);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Lowercases a string, this function makes use of the mbstring extension if
 * available
 *
 * ```php
 * echo Phalcon\Text::lower("HELLO"); // hello
 * ```
 */
PHP_METHOD(Phalcon_Text, lower) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *text_param = NULL, *encoding_param = NULL;
	zval text, encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&encoding);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &encoding_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_STRING(&encoding, "UTF-8");
	} else {
	if (UNEXPECTED(Z_TYPE_P(encoding_param) != IS_STRING && Z_TYPE_P(encoding_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoding' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(encoding_param) == IS_STRING)) {
		zephir_get_strval(&encoding, encoding_param);
	} else {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_EMPTY_STRING(&encoding);
	}
	}


	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_str_ce, "lower", &_0, 0, &text, &encoding);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if a string starts with a given string
 *
 * ```php
 * echo Phalcon\Text::startsWith("Hello", "He"); // true
 * echo Phalcon\Text::startsWith("Hello", "he", false); // false
 * echo Phalcon\Text::startsWith("Hello", "he"); // true
 * ```
 */
PHP_METHOD(Phalcon_Text, startsWith) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_bool ignoreCase;
	zval *text_param = NULL, *start_param = NULL, *ignoreCase_param = NULL, _1;
	zval text, start;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &text_param, &start_param, &ignoreCase_param);

	zephir_get_strval(&text, text_param);
	zephir_get_strval(&start, start_param);
	if (!ignoreCase_param) {
		ignoreCase = 1;
	} else {
		ignoreCase = zephir_get_boolval(ignoreCase_param);
	}


	if (ignoreCase) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_str_ce, "startswith", &_0, 16, &text, &start, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generates a random string based on the given type. Type is one of the
 * RANDOM_* constants
 *
 * ```php
 * use Phalcon\Text;
 *
 * // "aloiwkqz"
 * echo Text::random(Text::RANDOM_ALNUM);
 * ```
 */
PHP_METHOD(Phalcon_Text, random) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	long length;
	zval *type_param = NULL, *length_param = NULL, _1, _2;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &type_param, &length_param);

	if (!type_param) {
		type = 0;
	} else {
		type = zephir_get_intval(type_param);
	}
	if (!length_param) {
		length = 8;
	} else {
		length = zephir_get_intval(length_param);
	}


	ZVAL_LONG(&_1, type);
	ZVAL_LONG(&_2, length);
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_str_ce, "random", &_0, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Reduces multiple slashes in a string to single slashes
 *
 * ```php
 * // foo/bar/baz
 * echo Phalcon\Text::reduceSlashes("foo//bar/baz");
 *
 * // http://foo.bar/baz/buz
 * echo Phalcon\Text::reduceSlashes("http://foo.bar///baz/buz");
 * ```
 */
PHP_METHOD(Phalcon_Text, reduceSlashes) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *text_param = NULL;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}


	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_str_ce, "reduceslashes", &_0, 0, &text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Uncamelize strings which are camelized
 *
 * ```php
 * echo Phalcon\Text::uncamelize("CocoBongo"); // coco_bongo
 * echo Phalcon\Text::uncamelize("CocoBongo", "-"); // coco-bongo
 * ```
 */
PHP_METHOD(Phalcon_Text, uncamelize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *text_param = NULL, *delimiter = NULL, delimiter_sub, __$null;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&delimiter_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &delimiter);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!delimiter) {
		delimiter = &delimiter_sub;
		delimiter = &__$null;
	}


	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_str_ce, "uncamelize", &_0, 0, &text, delimiter);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Makes a phrase underscored instead of spaced
 *
 * ```php
 * echo Phalcon\Text::underscore("look behind"); // "look_behind"
 * echo Phalcon\Text::underscore("Awesome Phalcon"); // "Awesome_Phalcon"
 * ```
 */
PHP_METHOD(Phalcon_Text, underscore) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *text_param = NULL;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}


	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_str_ce, "underscore", &_0, 0, &text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Uppercases a string, this function makes use of the mbstring extension if
 * available
 *
 * ```php
 * echo Phalcon\Text::upper("hello"); // HELLO
 * ```
 */
PHP_METHOD(Phalcon_Text, upper) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *text_param = NULL, *encoding_param = NULL;
	zval text, encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&encoding);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &encoding_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_STRING(&encoding, "UTF-8");
	} else {
	if (UNEXPECTED(Z_TYPE_P(encoding_param) != IS_STRING && Z_TYPE_P(encoding_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoding' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(encoding_param) == IS_STRING)) {
		zephir_get_strval(&encoding, encoding_param);
	} else {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_EMPTY_STRING(&encoding);
	}
	}


	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_str_ce, "upper", &_0, 0, &text, &encoding);
	zephir_check_call_status();
	RETURN_MM();

}

