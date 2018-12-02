
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

	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_DISTINCT"), 5 TSRMLS_CC);

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

	zval *str_param = NULL, *delimiter = NULL, *_0;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &delimiter);

	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}
	if (!delimiter) {
		delimiter = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_camelize(_0, str, delimiter );
	RETURN_CCTOR(_0);

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

	zval *str_param = NULL, *delimiter = NULL, *_0;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &delimiter);

	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}
	if (!delimiter) {
		delimiter = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_uncamelize(_0, str, delimiter );
	RETURN_CCTOR(_0);

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

	zval *str_param = NULL, *separator_param = NULL, *parts = NULL, *number = NULL, *_0;
	zval *str = NULL, *separator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &separator_param);

	zephir_get_strval(str, str_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(separator);
		ZVAL_STRING(separator, "_", 1);
	} else {
		zephir_get_strval(separator, separator_param);
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
	zephir_array_fetch_long(&_0, parts, 0, PH_NOISY | PH_READONLY, "phalcon/text.zep", 89 TSRMLS_CC);
	ZEPHIR_CONCAT_VVV(return_value, _0, separator, number);
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
	zval *type_param = NULL, *length_param = NULL, *pool = NULL, *str = NULL, _0$$3 = zval_used_for_init, _1$$3 = zval_used_for_init, *_2$$3 = NULL, *_3$$3 = NULL, _4$$4 = zval_used_for_init, _5$$4 = zval_used_for_init, *_6$$4 = NULL, *_7$$4 = NULL, _8$$5, _9$$5, _10$$6, _11$$6, _12$$7, _13$$8 = zval_used_for_init, _14$$8 = zval_used_for_init, *_15$$8 = NULL, *_16$$8 = NULL, *_17$$8 = NULL, *_18$$9, _19$$9 = zval_used_for_init, _20$$9 = zval_used_for_init;
	zend_long type, ZEPHIR_LAST_CALL_STATUS, end = 0;

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
			ZEPHIR_SINIT_VAR(_0$$3);
			ZVAL_STRING(&_0$$3, "a", 0);
			ZEPHIR_SINIT_VAR(_1$$3);
			ZVAL_STRING(&_1$$3, "z", 0);
			ZEPHIR_CALL_FUNCTION(&_2$$3, "range", NULL, 460, &_0$$3, &_1$$3);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_0$$3);
			ZVAL_STRING(&_0$$3, "A", 0);
			ZEPHIR_SINIT_NVAR(_1$$3);
			ZVAL_STRING(&_1$$3, "Z", 0);
			ZEPHIR_CALL_FUNCTION(&_3$$3, "range", NULL, 460, &_0$$3, &_1$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(pool);
			zephir_fast_array_merge(pool, &(_2$$3), &(_3$$3) TSRMLS_CC);
			break;
		}
		if (type == 2) {
			ZEPHIR_SINIT_VAR(_4$$4);
			ZVAL_LONG(&_4$$4, 0);
			ZEPHIR_SINIT_VAR(_5$$4);
			ZVAL_LONG(&_5$$4, 9);
			ZEPHIR_CALL_FUNCTION(&_6$$4, "range", NULL, 460, &_4$$4, &_5$$4);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_4$$4);
			ZVAL_STRING(&_4$$4, "a", 0);
			ZEPHIR_SINIT_NVAR(_5$$4);
			ZVAL_STRING(&_5$$4, "f", 0);
			ZEPHIR_CALL_FUNCTION(&_7$$4, "range", NULL, 460, &_4$$4, &_5$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(pool);
			zephir_fast_array_merge(pool, &(_6$$4), &(_7$$4) TSRMLS_CC);
			break;
		}
		if (type == 3) {
			ZEPHIR_SINIT_VAR(_8$$5);
			ZVAL_LONG(&_8$$5, 0);
			ZEPHIR_SINIT_VAR(_9$$5);
			ZVAL_LONG(&_9$$5, 9);
			ZEPHIR_CALL_FUNCTION(&pool, "range", NULL, 460, &_8$$5, &_9$$5);
			zephir_check_call_status();
			break;
		}
		if (type == 4) {
			ZEPHIR_SINIT_VAR(_10$$6);
			ZVAL_LONG(&_10$$6, 1);
			ZEPHIR_SINIT_VAR(_11$$6);
			ZVAL_LONG(&_11$$6, 9);
			ZEPHIR_CALL_FUNCTION(&pool, "range", NULL, 460, &_10$$6, &_11$$6);
			zephir_check_call_status();
			break;
		}
		if (type == 5) {
			ZEPHIR_SINIT_VAR(_12$$7);
			ZVAL_STRING(&_12$$7, "2345679ACDEFHJKLMNPRSTUVWXYZ", 0);
			ZEPHIR_CALL_FUNCTION(&pool, "str_split", NULL, 76, &_12$$7);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_SINIT_VAR(_13$$8);
		ZVAL_LONG(&_13$$8, 0);
		ZEPHIR_SINIT_VAR(_14$$8);
		ZVAL_LONG(&_14$$8, 9);
		ZEPHIR_CALL_FUNCTION(&_15$$8, "range", NULL, 460, &_13$$8, &_14$$8);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_13$$8);
		ZVAL_STRING(&_13$$8, "a", 0);
		ZEPHIR_SINIT_NVAR(_14$$8);
		ZVAL_STRING(&_14$$8, "z", 0);
		ZEPHIR_CALL_FUNCTION(&_16$$8, "range", NULL, 460, &_13$$8, &_14$$8);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_13$$8);
		ZVAL_STRING(&_13$$8, "A", 0);
		ZEPHIR_SINIT_NVAR(_14$$8);
		ZVAL_STRING(&_14$$8, "Z", 0);
		ZEPHIR_CALL_FUNCTION(&_17$$8, "range", NULL, 460, &_13$$8, &_14$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&pool, "array_merge", NULL, 461, _15$$8, _16$$8, _17$$8);
		zephir_check_call_status();
		break;
	} while(0);

	end = (zephir_fast_count_int(pool TSRMLS_CC) - 1);
	while (1) {
		if (!(zephir_fast_strlen_ev(str) < length)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_19$$9);
		ZVAL_LONG(&_19$$9, 0);
		ZEPHIR_SINIT_NVAR(_20$$9);
		ZVAL_LONG(&_20$$9, end);
		zephir_array_fetch_long(&_18$$9, pool, zephir_mt_rand(zephir_get_intval(&_19$$9), zephir_get_intval(&_20$$9) TSRMLS_CC), PH_NOISY | PH_READONLY, "phalcon/text.zep", 138 TSRMLS_CC);
		zephir_concat_self(&str, _18$$9 TSRMLS_CC);
	}
	RETURN_CCTOR(str);

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


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_BOOL(&_0, (ignoreCase ? 1 : 0));
	RETURN_MM_BOOL(zephir_start_with(str, start, &_0));

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


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_BOOL(&_0, (ignoreCase ? 1 : 0));
	RETURN_MM_BOOL(zephir_end_with(str, end, &_0));

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
	zval *str = NULL, *encoding = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &encoding_param);

	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(encoding);
		ZVAL_STRING(encoding, "UTF-8", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(encoding_param) != IS_STRING && Z_TYPE_P(encoding_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoding' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(encoding_param) == IS_STRING)) {
		zephir_get_strval(encoding, encoding_param);
	} else {
		ZEPHIR_INIT_VAR(encoding);
		ZVAL_EMPTY_STRING(encoding);
	}
	}


	if ((zephir_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, 215, str, encoding);
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
 * echo Phalcon\Text::upper("hello"); // HELLO
 * </code>
 */
PHP_METHOD(Phalcon_Text, upper) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *encoding_param = NULL;
	zval *str = NULL, *encoding = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &encoding_param);

	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(encoding);
		ZVAL_STRING(encoding, "UTF-8", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(encoding_param) != IS_STRING && Z_TYPE_P(encoding_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoding' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(encoding_param) == IS_STRING)) {
		zephir_get_strval(encoding, encoding_param);
	} else {
		ZEPHIR_INIT_VAR(encoding);
		ZVAL_EMPTY_STRING(encoding);
	}
	}


	if ((zephir_function_exists_ex(SS("mb_strtoupper") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strtoupper", NULL, 216, str, encoding);
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
 * echo Phalcon\Text::reduceSlashes("foo//bar/baz"); // foo/bar/baz
 * echo Phalcon\Text::reduceSlashes("http://foo.bar///baz/buz"); // http://foo.bar/baz/buz
 * </code>
 */
PHP_METHOD(Phalcon_Text, reduceSlashes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_0, *_1;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "#(?<!:)//+#", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 42, _0, _1, str);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
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

	HashTable *_7$$3;
	HashPosition _6$$3;
	zval *separator = NULL, *a = NULL, *b = NULL, _0, _1, _2, *c = NULL, *_12, *_13, *_3$$3, _4$$3, *_5$$3 = NULL, **_8$$3, *_9$$4 = NULL, *_10$$4 = NULL, *_11$$4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(separator);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	zephir_get_arg(separator, zephir_get_intval(&_0) TSRMLS_CC);
	ZEPHIR_INIT_VAR(a);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 1);
	zephir_get_arg(a, zephir_get_intval(&_1) TSRMLS_CC);
	ZEPHIR_INIT_VAR(b);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 2);
	zephir_get_arg(b, zephir_get_intval(&_2) TSRMLS_CC);
	if (ZEND_NUM_ARGS() > 3) {
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_get_args(_3$$3 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_LONG(&_4$$3, 3);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "array_slice", NULL, 411, _3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_is_iterable(_5$$3, &_7$$3, &_6$$3, 0, 0, "phalcon/text.zep", 262);
		for (
		  ; zend_hash_get_current_data_ex(_7$$3, (void**) &_8$$3, &_6$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_7$$3, &_6$$3)
		) {
			ZEPHIR_GET_HVALUE(c, _8$$3);
			ZEPHIR_INIT_NVAR(_9$$4);
			zephir_fast_trim(_9$$4, b, separator, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_10$$4);
			zephir_fast_trim(_10$$4, c, separator, ZEPHIR_TRIM_LEFT TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_11$$4);
			ZEPHIR_CONCAT_VVV(_11$$4, _9$$4, separator, _10$$4);
			ZEPHIR_CPY_WRT(b, _11$$4);
		}
	}
	ZEPHIR_INIT_VAR(_12);
	zephir_fast_trim(_12, a, separator, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_13);
	zephir_fast_trim(_13, b, separator, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	ZEPHIR_CONCAT_VVV(return_value, _12, separator, _13);
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

	zend_bool _9$$6;
	HashTable *_7$$5;
	HashPosition _6$$5;
	zephir_fcall_cache_entry *_12 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *leftDelimiter_param = NULL, *rightDelimiter_param = NULL, *separator_param = NULL, *ldS = NULL, *rdS = NULL, *pattern = NULL, *matches = NULL, *match = NULL, *words = NULL, *word = NULL, *sub = NULL, *_0 = NULL, *_1 = NULL, *_4, *_5 = NULL, *_2$$3, **_8$$5, *_10$$6, *_11$$6 = NULL, *_13$$6, *_14$$6 = NULL, *_15$$6 = NULL, *_16$$6 = NULL;
	zval *text = NULL, *leftDelimiter = NULL, *rightDelimiter = NULL, *separator = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &text_param, &leftDelimiter_param, &rightDelimiter_param, &separator_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(text, text_param);
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	if (!leftDelimiter_param) {
		ZEPHIR_INIT_VAR(leftDelimiter);
		ZVAL_STRING(leftDelimiter, "{", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(leftDelimiter_param) != IS_STRING && Z_TYPE_P(leftDelimiter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'leftDelimiter' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(leftDelimiter_param) == IS_STRING)) {
		zephir_get_strval(leftDelimiter, leftDelimiter_param);
	} else {
		ZEPHIR_INIT_VAR(leftDelimiter);
		ZVAL_EMPTY_STRING(leftDelimiter);
	}
	}
	if (!rightDelimiter_param) {
		ZEPHIR_INIT_VAR(rightDelimiter);
		ZVAL_STRING(rightDelimiter, "}", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(rightDelimiter_param) != IS_STRING && Z_TYPE_P(rightDelimiter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rightDelimiter' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(rightDelimiter_param) == IS_STRING)) {
		zephir_get_strval(rightDelimiter, rightDelimiter_param);
	} else {
		ZEPHIR_INIT_VAR(rightDelimiter);
		ZVAL_EMPTY_STRING(rightDelimiter);
	}
	}
	if (!separator_param) {
		ZEPHIR_INIT_VAR(separator);
		ZVAL_STRING(separator, "|", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(separator_param) != IS_STRING && Z_TYPE_P(separator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'separator' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(separator_param) == IS_STRING)) {
		zephir_get_strval(separator, separator_param);
	} else {
		ZEPHIR_INIT_VAR(separator);
		ZVAL_EMPTY_STRING(separator);
	}
	}


	ZEPHIR_CALL_FUNCTION(&_0, "substr_count", NULL, 462, text, leftDelimiter);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "substr_count", NULL, 462, text, rightDelimiter);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(_0, _1)) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SVS(_3$$3, "Syntax error in string \"", text, "\"");
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 463, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "phalcon/text.zep", 289 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&ldS, "preg_quote", NULL, 464, leftDelimiter);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&rdS, "preg_quote", NULL, 464, rightDelimiter);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(pattern);
	ZEPHIR_CONCAT_SVSVVSVS(pattern, "/", ldS, "([^", ldS, rdS, "]+)", rdS, "/");
	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 2);
	ZEPHIR_MAKE_REF(matches);
	ZEPHIR_CALL_FUNCTION(&_5, "preg_match_all", NULL, 41, pattern, text, matches, _4);
	ZEPHIR_UNREF(matches);
	zephir_check_call_status();
	if (!(zephir_is_true(_5))) {
		RETURN_CTOR(text);
	}
	if (Z_TYPE_P(matches) == IS_ARRAY) {
		zephir_is_iterable(matches, &_7$$5, &_6$$5, 0, 0, "phalcon/text.zep", 312);
		for (
		  ; zend_hash_get_current_data_ex(_7$$5, (void**) &_8$$5, &_6$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_7$$5, &_6$$5)
		) {
			ZEPHIR_GET_HVALUE(match, _8$$5);
			_9$$6 = !(zephir_array_isset_long(match, 0));
			if (!(_9$$6)) {
				_9$$6 = !(zephir_array_isset_long(match, 1));
			}
			if (_9$$6) {
				continue;
			}
			zephir_array_fetch_long(&_10$$6, match, 1, PH_NOISY | PH_READONLY, "phalcon/text.zep", 307 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(words);
			zephir_fast_explode(words, separator, _10$$6, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_NVAR(word);
			ZEPHIR_CALL_FUNCTION(&_11$$6, "array_rand", &_12, 465, words);
			zephir_check_call_status();
			zephir_array_fetch(&word, words, _11$$6, PH_NOISY, "phalcon/text.zep", 308 TSRMLS_CC);
			zephir_array_fetch_long(&_13$$6, match, 0, PH_NOISY | PH_READONLY, "phalcon/text.zep", 309 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&sub, "preg_quote", NULL, 464, _13$$6, separator);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_14$$6);
			ZEPHIR_CONCAT_SVS(_14$$6, "/", sub, "/");
			ZEPHIR_INIT_NVAR(_15$$6);
			ZVAL_LONG(_15$$6, 1);
			ZEPHIR_CALL_FUNCTION(&_16$$6, "preg_replace", &_17, 42, _14$$6, word, text, _15$$6);
			zephir_check_call_status();
			zephir_get_strval(text, _16$$6);
		}
	}
	RETURN_CTOR(text);

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
	zval *text_param = NULL, *_0, *_1, *_2;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(text, text_param);
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_trim(_0, text, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "#\\s+#", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "_", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 42, _1, _2, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
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
	zval *text_param = NULL, *_0, *_1, *_2;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(text, text_param);
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_trim(_0, text, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "#[_-]+#", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, " ", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 42, _1, _2, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM();

}

