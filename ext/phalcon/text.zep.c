
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
#include "kernel/hash.h"


/**
 * Phalcon\Text
 *
 * Provides utilities to work with texts
 */
ZEPHIR_INIT_CLASS(Phalcon_Text) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Text, phalcon, text, phalcon_text_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_ALNUM"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_ALPHA"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_HEXDEC"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_NUMERIC"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_NOZERO"), 4 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Converts strings to camelize style
 *
 * <code>
 *    echo Phalcon\Text::camelize('coco_bongo'); //CocoBongo
 * </code>
 */
PHP_METHOD(Phalcon_Text, camelize) {

	zval *str_param = NULL, *_0;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_camelize(_0, str);
	RETURN_CCTOR(_0);

}

/**
 * Uncamelize strings which are camelized
 *
 * <code>
 *    echo Phalcon\Text::camelize('CocoBongo'); //coco_bongo
 * </code>
 */
PHP_METHOD(Phalcon_Text, uncamelize) {

	zval *str_param = NULL, *_0;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_uncamelize(_0, str);
	RETURN_CCTOR(_0);

}

/**
 * Adds a number to a string or increment that number if it already is defined
 *
 * <code>
 *    echo Phalcon\Text::increment("a"); // "a_1"
 *    echo Phalcon\Text::increment("a_1"); // "a_2"
 * </code>
 */
PHP_METHOD(Phalcon_Text, increment) {

	zval *str_param = NULL, *separator = NULL, *parts, *number = NULL, *_0;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &separator);

	zephir_get_strval(str, str_param);
	if (!separator) {
		ZEPHIR_CPY_WRT(separator, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(separator);
	}


	if (Z_TYPE_P(separator) == IS_NULL) {
		ZEPHIR_INIT_NVAR(separator);
		ZVAL_STRING(separator, "_", 1);
	}
	ZEPHIR_INIT_VAR(parts);
	zephir_fast_explode(parts, separator, str, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(number);
	if (zephir_array_isset_long_fetch(&number, parts, 1, 0 TSRMLS_CC)) {
		ZEPHIR_SEPARATE(number);
		zephir_increment(number);
	} else {
		ZEPHIR_INIT_NVAR(number);
		ZVAL_LONG(number, 1);
	}
	zephir_array_fetch_long(&_0, parts, 0, PH_NOISY | PH_READONLY, "phalcon/text.zep", 88 TSRMLS_CC);
	ZEPHIR_CONCAT_VVV(return_value, _0, separator, number);
	RETURN_MM();

}

/**
 * Generates a random string based on the given type. Type is one of the RANDOM_* constants
 *
 * <code>
 *    echo Phalcon\Text::random(Phalcon\Text::RANDOM_ALNUM); //"aloiwkqz"
 * </code>
 */
PHP_METHOD(Phalcon_Text, random) {

	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	long length;
	zval *type_param = NULL, *length_param = NULL, *pool = NULL, *str, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_7;
	int type, end, ZEPHIR_LAST_CALL_STATUS;

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
	ZEPHIR_INIT_VAR(str);
	ZVAL_STRING(str, "", 1);


	do {
		if (type == 1) {
			ZEPHIR_SINIT_VAR(_0);
			ZVAL_STRING(&_0, "a", 0);
			ZEPHIR_SINIT_VAR(_1);
			ZVAL_STRING(&_1, "z", 0);
			ZEPHIR_CALL_FUNCTION(&_2, "range", &_3, 413, &_0, &_1);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "A", 0);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "Z", 0);
			ZEPHIR_CALL_FUNCTION(&_4, "range", &_3, 413, &_0, &_1);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(pool);
			zephir_fast_array_merge(pool, &(_2), &(_4) TSRMLS_CC);
			break;
		}
		if (type == 2) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 0);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 9);
			ZEPHIR_CALL_FUNCTION(&_2, "range", &_3, 413, &_0, &_1);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "a", 0);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "f", 0);
			ZEPHIR_CALL_FUNCTION(&_4, "range", &_3, 413, &_0, &_1);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(pool);
			zephir_fast_array_merge(pool, &(_2), &(_4) TSRMLS_CC);
			break;
		}
		if (type == 3) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 0);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 9);
			ZEPHIR_CALL_FUNCTION(&pool, "range", &_3, 413, &_0, &_1);
			zephir_check_call_status();
			break;
		}
		if (type == 4) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 1);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 9);
			ZEPHIR_CALL_FUNCTION(&pool, "range", &_3, 413, &_0, &_1);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 9);
		ZEPHIR_CALL_FUNCTION(&_2, "range", &_3, 413, &_0, &_1);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "a", 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "z", 0);
		ZEPHIR_CALL_FUNCTION(&_4, "range", &_3, 413, &_0, &_1);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "A", 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "Z", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "range", &_3, 413, &_0, &_1);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&pool, "array_merge", &_6, 414, _2, _4, _5);
		zephir_check_call_status();
		break;
	} while(0);

	end = (zephir_fast_count_int(pool TSRMLS_CC) - 1);
	while (1) {
		if (!(zephir_fast_strlen_ev(str) < length)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, end);
		zephir_array_fetch_long(&_7, pool, zephir_mt_rand(zephir_get_intval(&_0), zephir_get_intval(&_1) TSRMLS_CC), PH_NOISY | PH_READONLY, "phalcon/text.zep", 130 TSRMLS_CC);
		zephir_concat_self(&str, _7 TSRMLS_CC);
	}
	RETURN_CCTOR(str);

}

/**
 * Check if a string starts with a given string
 *
 * <code>
 *    echo Phalcon\Text::startsWith("Hello", "He"); // true
 *    echo Phalcon\Text::startsWith("Hello", "he", false); // false
 *    echo Phalcon\Text::startsWith("Hello", "he"); // true
 * </code>
 */
PHP_METHOD(Phalcon_Text, startsWith) {

	zend_bool ignoreCase;
	zval *str_param = NULL, *start_param = NULL, *ignoreCase_param = NULL;
	zval *str = NULL, *start = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &str_param, &start_param, &ignoreCase_param);

	zephir_get_strval(str, str_param);
	zephir_get_strval(start, start_param);
	if (!ignoreCase_param) {
		ignoreCase = 1;
	} else {
		ignoreCase = zephir_get_boolval(ignoreCase_param);
	}


	RETURN_MM_BOOL(zephir_start_with(str, start, (ignoreCase ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false))));

}

/**
 * Check if a string ends with a given string
 *
 * <code>
 *    echo Phalcon\Text::endsWith("Hello", "llo"); // true
 *    echo Phalcon\Text::endsWith("Hello", "LLO", false); // false
 *    echo Phalcon\Text::endsWith("Hello", "LLO"); // true
 * </code>
 */
PHP_METHOD(Phalcon_Text, endsWith) {

	zend_bool ignoreCase;
	zval *str_param = NULL, *end_param = NULL, *ignoreCase_param = NULL;
	zval *str = NULL, *end = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &str_param, &end_param, &ignoreCase_param);

	zephir_get_strval(str, str_param);
	zephir_get_strval(end, end_param);
	if (!ignoreCase_param) {
		ignoreCase = 1;
	} else {
		ignoreCase = zephir_get_boolval(ignoreCase_param);
	}


	RETURN_MM_BOOL(zephir_end_with(str, end, (ignoreCase ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false))));

}

/**
 * Lowercases a string, this function makes use of the mbstring extension if available
 *
 * <code>
 *    echo Phalcon\Text::lower("HELLO"); // hello
 * </code>
 */
PHP_METHOD(Phalcon_Text, lower) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *encoding_param = NULL;
	zval *str = NULL, *encoding = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &encoding_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(encoding);
		ZVAL_STRING(encoding, "UTF-8", 1);
	} else {
	if (unlikely(Z_TYPE_P(encoding_param) != IS_STRING && Z_TYPE_P(encoding_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoding' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(encoding_param) == IS_STRING)) {
		zephir_get_strval(encoding, encoding_param);
	} else {
		ZEPHIR_INIT_VAR(encoding);
		ZVAL_EMPTY_STRING(encoding);
	}
	}


	if ((zephir_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, 168, str, encoding);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_fast_strtolower(return_value, str);
	RETURN_MM();

}

/**
 * Uppercases a string, this function makes use of the mbstring extension if available
 *
 * <code>
 *    echo Phalcon\Text::upper("hello"); // HELLO
 * </code>
 */
PHP_METHOD(Phalcon_Text, upper) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *encoding_param = NULL;
	zval *str = NULL, *encoding = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &encoding_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(encoding);
		ZVAL_STRING(encoding, "UTF-8", 1);
	} else {
	if (unlikely(Z_TYPE_P(encoding_param) != IS_STRING && Z_TYPE_P(encoding_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoding' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(encoding_param) == IS_STRING)) {
		zephir_get_strval(encoding, encoding_param);
	} else {
		ZEPHIR_INIT_VAR(encoding);
		ZVAL_EMPTY_STRING(encoding);
	}
	}


	if ((zephir_function_exists_ex(SS("mb_strtoupper") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strtoupper", NULL, 169, str, encoding);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_fast_strtoupper(return_value, str);
	RETURN_MM();

}

/**
 * Reduces multiple slashes in a string to single slashes
 *
 * <code>
 *    echo Phalcon\Text::reduceSlashes("foo//bar/baz"); // foo/bar/baz
 *    echo Phalcon\Text::reduceSlashes("http://foo.bar///baz/buz"); // http://foo.bar/baz/buz
 * </code>
 */
PHP_METHOD(Phalcon_Text, reduceSlashes) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_0, *_1;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "#(?<!:)//+#", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 82, _0, _1, str);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Concatenates strings using the separator only once without duplication in places concatenation
 *
 * <code>
 *    $str = Phalcon\Text::concat("/", "/tmp/", "/folder_1/", "/folder_2", "folder_3/");
 *    echo $str; // /tmp/folder_1/folder_2/folder_3/
 * </code>
 *
 * @param string separator
 * @param string a
 * @param string b
 * @param string ...N
 */
PHP_METHOD(Phalcon_Text, concat) {

	HashTable *_6;
	HashPosition _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *separator = NULL, *a = NULL, *b = NULL, _0 = zval_used_for_init, *c = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, **_7, *_8 = NULL, *_9 = NULL, *_10 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_FUNCTION(&separator, "func_get_arg", &_1, 415, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_FUNCTION(&a, "func_get_arg", &_1, 415, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&b, "func_get_arg", &_1, 415, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "func_num_args", NULL, 416);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(_2, 3)) {
		ZEPHIR_CALL_FUNCTION(&_3, "func_get_args", NULL, 133);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 3);
		ZEPHIR_CALL_FUNCTION(&_4, "array_slice", NULL, 368, _3, &_0);
		zephir_check_call_status();
		zephir_is_iterable(_4, &_6, &_5, 0, 0, "phalcon/text.zep", 246);
		for (
		  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HVALUE(c, _7);
			ZEPHIR_INIT_NVAR(_8);
			zephir_fast_trim(_8, b, separator, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_9);
			zephir_fast_trim(_9, c, separator, ZEPHIR_TRIM_LEFT TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_VVV(_10, _8, separator, _9);
			ZEPHIR_CPY_WRT(b, _10);
		}
	}
	ZEPHIR_INIT_NVAR(_8);
	zephir_fast_trim(_8, a, separator, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_9);
	zephir_fast_trim(_9, b, separator, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	ZEPHIR_CONCAT_VVV(return_value, _8, separator, _9);
	RETURN_MM();

}

