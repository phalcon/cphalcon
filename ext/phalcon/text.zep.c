
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
#include "kernel/memory.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/math.h"
#include "kernel/object.h"
#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Text
 *
 * Provides utilities to work with texts
 */
ZEPHIR_INIT_CLASS(Phalcon_Text) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Text, phalcon, text, phalcon_text_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zephir_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_ALNUM"), 0);

	zephir_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_ALPHA"), 1);

	zephir_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_HEXDEC"), 2);

	zephir_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_NUMERIC"), 3);

	zephir_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_NOZERO"), 4);

	zephir_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_DISTINCT"), 5);

	return SUCCESS;

}

/**
 * Converts strings to camelize style
 *
 * <code>
 * echo Phalcon\Text::camelize("coco_bongo"); // CocoBongo
 * echo Phalcon\Text::camelize("co_co-bon_go", "-"); // Co_coBon_go
 * echo Phalcon\Text::camelize("co_co-bon_go", "_-"); // CoCoBonGo
 * </code>
 */
PHP_METHOD(Phalcon_Text, camelize) {

	zval *str_param = NULL, *delimiter = NULL, delimiter_sub, __$null, _0;
	zval str;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&delimiter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &delimiter);

	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(&str, str_param);
	} else {
		ZEPHIR_INIT_VAR(&str);
		ZVAL_EMPTY_STRING(&str);
	}
	if (!delimiter) {
		delimiter = &delimiter_sub;
		delimiter = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_camelize(&_0, &str, delimiter );
	RETURN_CCTOR(&_0);

}

/**
 * Uncamelize strings which are camelized
 *
 * <code>
 * echo Phalcon\Text::uncamelize("CocoBongo"); // coco_bongo
 * echo Phalcon\Text::uncamelize("CocoBongo", "-"); // coco-bongo
 * </code>
 */
PHP_METHOD(Phalcon_Text, uncamelize) {

	zval *str_param = NULL, *delimiter = NULL, delimiter_sub, __$null, _0;
	zval str;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&delimiter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &delimiter);

	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(&str, str_param);
	} else {
		ZEPHIR_INIT_VAR(&str);
		ZVAL_EMPTY_STRING(&str);
	}
	if (!delimiter) {
		delimiter = &delimiter_sub;
		delimiter = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_uncamelize(&_0, &str, delimiter );
	RETURN_CCTOR(&_0);

}

/**
 * Adds a number to a string or increment that number if it already is defined
 *
 * <code>
 * echo Phalcon\Text::increment("a"); // "a_1"
 * echo Phalcon\Text::increment("a_1"); // "a_2"
 * </code>
 */
PHP_METHOD(Phalcon_Text, increment) {

	zval *str_param = NULL, *separator_param = NULL, parts, number, _0;
	zval str, separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &separator_param);

	zephir_get_strval(&str, str_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "_");
	} else {
		zephir_get_strval(&separator, separator_param);
	}


	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode(&parts, &separator, &str, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(&number);
	if (zephir_array_isset_long_fetch(&number, &parts, 1, 0 TSRMLS_CC)) {
		ZEPHIR_SEPARATE(&number);
		zephir_increment(&number);
	} else {
		ZEPHIR_INIT_NVAR(&number);
		ZVAL_LONG(&number, 1);
	}
	zephir_array_fetch_long(&_0, &parts, 0, PH_NOISY | PH_READONLY, "phalcon/text.zep", 80 TSRMLS_CC);
	ZEPHIR_CONCAT_VVV(return_value, &_0, &separator, &number);
	RETURN_MM();

}

/**
 * Generates a random string based on the given type. Type is one of the RANDOM_* constants
 *
 * <code>
 * use Phalcon\Text;
 *
 * // "aloiwkqz"
 * echo Text::random(Text::RANDOM_ALNUM);
 * </code>
 */
PHP_METHOD(Phalcon_Text, random) {

	long length;
	zval *type_param = NULL, *length_param = NULL, pool, str, _0$$3, _1$$3, _2$$3, _3$$3, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _10$$5, _11$$5, _12$$6, _13$$6, _14$$7, _15$$8, _16$$8, _17$$8, _18$$8, _19$$8, _20$$8, _21$$8, _22$$9, _23$$9, _24$$9;
	zend_long type, ZEPHIR_LAST_CALL_STATUS, end = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pool);
	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);

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


	ZEPHIR_INIT_VAR(&str);
	ZVAL_STRING(&str, "");
	do {
		if (type == 1) {
			ZEPHIR_INIT_VAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "a");
			ZEPHIR_INIT_VAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "z");
			ZEPHIR_CALL_FUNCTION(&_2$$3, "range", NULL, 430, &_0$$3, &_1$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "A");
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "Z");
			ZEPHIR_CALL_FUNCTION(&_3$$3, "range", NULL, 430, &_0$$3, &_1$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&pool);
			zephir_fast_array_merge(&pool, &_2$$3, &_3$$3 TSRMLS_CC);
			break;
		}
		if (type == 2) {
			ZVAL_LONG(&_4$$4, 0);
			ZVAL_LONG(&_5$$4, 9);
			ZEPHIR_CALL_FUNCTION(&_6$$4, "range", NULL, 430, &_4$$4, &_5$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "a");
			ZEPHIR_INIT_VAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "f");
			ZEPHIR_CALL_FUNCTION(&_9$$4, "range", NULL, 430, &_7$$4, &_8$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&pool);
			zephir_fast_array_merge(&pool, &_6$$4, &_9$$4 TSRMLS_CC);
			break;
		}
		if (type == 3) {
			ZVAL_LONG(&_10$$5, 0);
			ZVAL_LONG(&_11$$5, 9);
			ZEPHIR_CALL_FUNCTION(&pool, "range", NULL, 430, &_10$$5, &_11$$5);
			zephir_check_call_status();
			break;
		}
		if (type == 4) {
			ZVAL_LONG(&_12$$6, 1);
			ZVAL_LONG(&_13$$6, 9);
			ZEPHIR_CALL_FUNCTION(&pool, "range", NULL, 430, &_12$$6, &_13$$6);
			zephir_check_call_status();
			break;
		}
		if (type == 5) {
			ZEPHIR_INIT_VAR(&_14$$7);
			ZVAL_STRING(&_14$$7, "2345679ACDEFHJKLMNPRSTUVWXYZ");
			ZEPHIR_CALL_FUNCTION(&pool, "str_split", NULL, 63, &_14$$7);
			zephir_check_call_status();
			break;
		}
		ZVAL_LONG(&_15$$8, 0);
		ZVAL_LONG(&_16$$8, 9);
		ZEPHIR_CALL_FUNCTION(&_17$$8, "range", NULL, 430, &_15$$8, &_16$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_18$$8);
		ZVAL_STRING(&_18$$8, "a");
		ZEPHIR_INIT_VAR(&_19$$8);
		ZVAL_STRING(&_19$$8, "z");
		ZEPHIR_CALL_FUNCTION(&_20$$8, "range", NULL, 430, &_18$$8, &_19$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_18$$8);
		ZVAL_STRING(&_18$$8, "A");
		ZEPHIR_INIT_NVAR(&_19$$8);
		ZVAL_STRING(&_19$$8, "Z");
		ZEPHIR_CALL_FUNCTION(&_21$$8, "range", NULL, 430, &_18$$8, &_19$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&pool, "array_merge", NULL, 431, &_17$$8, &_20$$8, &_21$$8);
		zephir_check_call_status();
		break;
	} while(0);

	end = (zephir_fast_count_int(&pool TSRMLS_CC) - 1);
	while (1) {
		if (!(zephir_fast_strlen_ev(&str) < length)) {
			break;
		}
		ZVAL_LONG(&_23$$9, 0);
		ZVAL_LONG(&_24$$9, end);
		zephir_array_fetch_long(&_22$$9, &pool, zephir_mt_rand(zephir_get_intval(&_23$$9), zephir_get_intval(&_24$$9) TSRMLS_CC), PH_NOISY | PH_READONLY, "phalcon/text.zep", 129 TSRMLS_CC);
		zephir_concat_self(&str, &_22$$9 TSRMLS_CC);
	}
	RETURN_CCTOR(&str);

}

/**
 * Check if a string starts with a given string
 *
 * <code>
 * echo Phalcon\Text::startsWith("Hello", "He"); // true
 * echo Phalcon\Text::startsWith("Hello", "he", false); // false
 * echo Phalcon\Text::startsWith("Hello", "he"); // true
 * </code>
 */
PHP_METHOD(Phalcon_Text, startsWith) {

	zend_bool ignoreCase;
	zval *str_param = NULL, *start_param = NULL, *ignoreCase_param = NULL, _0;
	zval str, start;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &str_param, &start_param, &ignoreCase_param);

	zephir_get_strval(&str, str_param);
	zephir_get_strval(&start, start_param);
	if (!ignoreCase_param) {
		ignoreCase = 1;
	} else {
		ignoreCase = zephir_get_boolval(ignoreCase_param);
	}


	ZVAL_BOOL(&_0, (ignoreCase ? 1 : 0));
	RETURN_MM_BOOL(zephir_start_with(&str, &start, &_0));

}

/**
 * Check if a string ends with a given string
 *
 * <code>
 * echo Phalcon\Text::endsWith("Hello", "llo"); // true
 * echo Phalcon\Text::endsWith("Hello", "LLO", false); // false
 * echo Phalcon\Text::endsWith("Hello", "LLO"); // true
 * </code>
 */
PHP_METHOD(Phalcon_Text, endsWith) {

	zend_bool ignoreCase;
	zval *str_param = NULL, *end_param = NULL, *ignoreCase_param = NULL, _0;
	zval str, end;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &str_param, &end_param, &ignoreCase_param);

	zephir_get_strval(&str, str_param);
	zephir_get_strval(&end, end_param);
	if (!ignoreCase_param) {
		ignoreCase = 1;
	} else {
		ignoreCase = zephir_get_boolval(ignoreCase_param);
	}


	ZVAL_BOOL(&_0, (ignoreCase ? 1 : 0));
	RETURN_MM_BOOL(zephir_end_with(&str, &end, &_0));

}

/**
 * Lowercases a string, this function makes use of the mbstring extension if available
 *
 * <code>
 * echo Phalcon\Text::lower("HELLO"); // hello
 * </code>
 */
PHP_METHOD(Phalcon_Text, lower) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *encoding_param = NULL;
	zval str, encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&encoding);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &encoding_param);

	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(&str, str_param);
	} else {
		ZEPHIR_INIT_VAR(&str);
		ZVAL_EMPTY_STRING(&str);
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_STRING(&encoding, "UTF-8");
	} else {
	if (UNEXPECTED(Z_TYPE_P(encoding_param) != IS_STRING && Z_TYPE_P(encoding_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoding' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(encoding_param) == IS_STRING)) {
		zephir_get_strval(&encoding, encoding_param);
	} else {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_EMPTY_STRING(&encoding);
	}
	}


	if ((zephir_function_exists_ex(SL("mb_strtolower") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, 432, &str, &encoding);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_fast_strtolower(return_value, &str);
	RETURN_MM();

}

/**
 * Uppercases a string, this function makes use of the mbstring extension if available
 *
 * <code>
 * echo Phalcon\Text::upper("hello"); // HELLO
 * </code>
 */
PHP_METHOD(Phalcon_Text, upper) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *encoding_param = NULL;
	zval str, encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&encoding);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &encoding_param);

	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(&str, str_param);
	} else {
		ZEPHIR_INIT_VAR(&str);
		ZVAL_EMPTY_STRING(&str);
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_STRING(&encoding, "UTF-8");
	} else {
	if (UNEXPECTED(Z_TYPE_P(encoding_param) != IS_STRING && Z_TYPE_P(encoding_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoding' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(encoding_param) == IS_STRING)) {
		zephir_get_strval(&encoding, encoding_param);
	} else {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_EMPTY_STRING(&encoding);
	}
	}


	if ((zephir_function_exists_ex(SL("mb_strtoupper") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strtoupper", NULL, 433, &str, &encoding);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_fast_strtoupper(return_value, &str);
	RETURN_MM();

}

/**
 * Reduces multiple slashes in a string to single slashes
 *
 * <code>
 * echo Phalcon\Text::reduceSlashes("foo//bar/baz"); // foo/bar/baz
 * echo Phalcon\Text::reduceSlashes("http://foo.bar///baz/buz"); // http://foo.bar/baz/buz
 * </code>
 */
PHP_METHOD(Phalcon_Text, reduceSlashes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, _0, _1;
	zval str;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(&str, str_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "#(?<!:)//+#");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 21, &_0, &_1, &str);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Concatenates strings using the separator only once without duplication in places concatenation
 *
 * <code>
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
 * </code>
 *
 * @param string separator
 * @param string a
 * @param string b
 * @param string ...N
 */
PHP_METHOD(Phalcon_Text, concat) {

	zval separator, a, b, _0, _1, _2, c, _14, _15, _3$$3, _4$$3, _5$$3, *_6$$3, _7$$3, _8$$4, _9$$4, _10$$4, _11$$5, _12$$5, _13$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&b);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&c);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&separator);
	ZVAL_LONG(&_0, 0);
	zephir_get_arg(&separator, zephir_get_intval(&_0));
	ZEPHIR_INIT_VAR(&a);
	ZVAL_LONG(&_1, 1);
	zephir_get_arg(&a, zephir_get_intval(&_1));
	ZEPHIR_INIT_VAR(&b);
	ZVAL_LONG(&_2, 2);
	zephir_get_arg(&b, zephir_get_intval(&_2));
	if (ZEND_NUM_ARGS() > 3) {
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_get_args(&_3$$3);
		ZVAL_LONG(&_4$$3, 3);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "array_slice", NULL, 385, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_is_iterable(&_5$$3, 0, "phalcon/text.zep", 253);
		if (Z_TYPE_P(&_5$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5$$3), _6$$3)
			{
				ZEPHIR_INIT_NVAR(&c);
				ZVAL_COPY(&c, _6$$3);
				ZEPHIR_INIT_NVAR(&_8$$4);
				zephir_fast_trim(&_8$$4, &b, &separator, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_9$$4);
				zephir_fast_trim(&_9$$4, &c, &separator, ZEPHIR_TRIM_LEFT TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_10$$4);
				ZEPHIR_CONCAT_VVV(&_10$$4, &_8$$4, &separator, &_9$$4);
				ZEPHIR_CPY_WRT(&b, &_10$$4);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_5$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_7$$3, &_5$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&c, &_5$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_11$$5);
					zephir_fast_trim(&_11$$5, &b, &separator, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_12$$5);
					zephir_fast_trim(&_12$$5, &c, &separator, ZEPHIR_TRIM_LEFT TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_13$$5);
					ZEPHIR_CONCAT_VVV(&_13$$5, &_11$$5, &separator, &_12$$5);
					ZEPHIR_CPY_WRT(&b, &_13$$5);
				ZEPHIR_CALL_METHOD(NULL, &_5$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&c);
	}
	ZEPHIR_INIT_VAR(&_14);
	zephir_fast_trim(&_14, &a, &separator, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_15);
	zephir_fast_trim(&_15, &b, &separator, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	ZEPHIR_CONCAT_VVV(return_value, &_14, &separator, &_15);
	RETURN_MM();

}

/**
 * Generates random text in accordance with the template
 *
 * <code>
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
 * echo Phalcon\Text::dynamic("[Hi/Hello], my name is a [Zyxep/Mark]!", "[", "]", "/");
 * </code>
 */
PHP_METHOD(Phalcon_Text, dynamic) {

	zend_bool _7$$6, _16$$8;
	zephir_fcall_cache_entry *_10 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *leftDelimiter_param = NULL, *rightDelimiter_param = NULL, *separator_param = NULL, ldS, rdS, pattern, matches, match, words, word, sub, _0, _1, _4, _2$$3, *_5$$5, _6$$5, _8$$6, _9$$6, _11$$6, _12$$6, _13$$6, _14$$6, _17$$8, _18$$8, _19$$8, _20$$8, _21$$8, _22$$8;
	zval text, leftDelimiter, rightDelimiter, separator, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&leftDelimiter);
	ZVAL_UNDEF(&rightDelimiter);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&ldS);
	ZVAL_UNDEF(&rdS);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&words);
	ZVAL_UNDEF(&word);
	ZVAL_UNDEF(&sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &text_param, &leftDelimiter_param, &rightDelimiter_param, &separator_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'leftDelimiter' must be of the type string") TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rightDelimiter' must be of the type string") TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'separator' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(separator_param) == IS_STRING)) {
		zephir_get_strval(&separator, separator_param);
	} else {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_EMPTY_STRING(&separator);
	}
	}


	ZEPHIR_CALL_FUNCTION(&_0, "substr_count", NULL, 434, &text, &leftDelimiter);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "substr_count", NULL, 434, &text, &rightDelimiter);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_0, &_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, "Syntax error in string \"", &text, "\"");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 424, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/text.zep", 280 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&ldS, "preg_quote", NULL, 435, &leftDelimiter);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&rdS, "preg_quote", NULL, 435, &rightDelimiter);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&pattern);
	ZEPHIR_CONCAT_SVSVVSVS(&pattern, "/", &ldS, "([^", &ldS, &rdS, "]+)", &rdS, "/");
	ZEPHIR_INIT_VAR(&matches);
	array_init(&matches);
	ZEPHIR_INIT_VAR(&_4);
	zephir_preg_match(&_4, &pattern, &text, &matches, 1, 2 , 0  TSRMLS_CC);
	if (!(zephir_is_true(&_4))) {
		RETURN_CTOR(&text);
	}
	if (Z_TYPE_P(&matches) == IS_ARRAY) {
		zephir_is_iterable(&matches, 0, "phalcon/text.zep", 303);
		if (Z_TYPE_P(&matches) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _5$$5)
			{
				ZEPHIR_INIT_NVAR(&match);
				ZVAL_COPY(&match, _5$$5);
				_7$$6 = !(zephir_array_isset_long(&match, 0));
				if (!(_7$$6)) {
					_7$$6 = !(zephir_array_isset_long(&match, 1));
				}
				if (_7$$6) {
					continue;
				}
				zephir_array_fetch_long(&_8$$6, &match, 1, PH_NOISY | PH_READONLY, "phalcon/text.zep", 298 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&words);
				zephir_fast_explode(&words, &separator, &_8$$6, LONG_MAX TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&word);
				ZEPHIR_CALL_FUNCTION(&_9$$6, "array_rand", &_10, 436, &words);
				zephir_check_call_status();
				zephir_array_fetch(&word, &words, &_9$$6, PH_NOISY, "phalcon/text.zep", 299 TSRMLS_CC);
				zephir_array_fetch_long(&_11$$6, &match, 0, PH_NOISY | PH_READONLY, "phalcon/text.zep", 300 TSRMLS_CC);
				ZEPHIR_CALL_FUNCTION(&sub, "preg_quote", NULL, 435, &_11$$6, &separator);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_12$$6);
				ZEPHIR_CONCAT_SVS(&_12$$6, "/", &sub, "/");
				ZVAL_LONG(&_13$$6, 1);
				ZEPHIR_CALL_FUNCTION(&_14$$6, "preg_replace", &_15, 21, &_12$$6, &word, &text, &_13$$6);
				zephir_check_call_status();
				zephir_get_strval(&text, &_14$$6);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &matches, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$5, &matches, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&match, &matches, "current", NULL, 0);
				zephir_check_call_status();
					_16$$8 = !(zephir_array_isset_long(&match, 0));
					if (!(_16$$8)) {
						_16$$8 = !(zephir_array_isset_long(&match, 1));
					}
					if (_16$$8) {
						continue;
					}
					zephir_array_fetch_long(&_17$$8, &match, 1, PH_NOISY | PH_READONLY, "phalcon/text.zep", 298 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&words);
					zephir_fast_explode(&words, &separator, &_17$$8, LONG_MAX TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&word);
					ZEPHIR_CALL_FUNCTION(&_18$$8, "array_rand", &_10, 436, &words);
					zephir_check_call_status();
					zephir_array_fetch(&word, &words, &_18$$8, PH_NOISY, "phalcon/text.zep", 299 TSRMLS_CC);
					zephir_array_fetch_long(&_19$$8, &match, 0, PH_NOISY | PH_READONLY, "phalcon/text.zep", 300 TSRMLS_CC);
					ZEPHIR_CALL_FUNCTION(&sub, "preg_quote", NULL, 435, &_19$$8, &separator);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_20$$8);
					ZEPHIR_CONCAT_SVS(&_20$$8, "/", &sub, "/");
					ZVAL_LONG(&_21$$8, 1);
					ZEPHIR_CALL_FUNCTION(&_22$$8, "preg_replace", &_15, 21, &_20$$8, &word, &text, &_21$$8);
					zephir_check_call_status();
					zephir_get_strval(&text, &_22$$8);
				ZEPHIR_CALL_METHOD(NULL, &matches, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&match);
	}
	RETURN_CTOR(&text);

}

/**
 * Makes a phrase underscored instead of spaced
 *
 * <code>
 * echo Phalcon\Text::underscore("look behind"); // "look_behind"
 * echo Phalcon\Text::underscore("Awesome Phalcon"); // "Awesome_Phalcon"
 * </code>
 */
PHP_METHOD(Phalcon_Text, underscore) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, _0, _1, _2;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_trim(&_0, &text, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "#\\s+#");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "_");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 21, &_1, &_2, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Makes an underscored or dashed phrase human-readable
 *
 * <code>
 * echo Phalcon\Text::humanize("start-a-horse"); // "start a horse"
 * echo Phalcon\Text::humanize("five_cats"); // "five cats"
 * </code>
 */
PHP_METHOD(Phalcon_Text, humanize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, _0, _1, _2;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_trim(&_0, &text, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "#[_-]+#");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, " ");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 21, &_1, &_2, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

