
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Generates random text in accordance with the template. The template is
 * defined by the left and right delimiter and it can contain values separated
 * by the separator
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Dynamic)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, Dynamic, phalcon, support_helper_str_dynamic, phalcon_support_helper_str_dynamic_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $text
 * @param string $leftDelimiter
 * @param string $rightDelimiter
 * @param string $separator
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Dynamic, __invoke)
{
	zend_bool _8$$6, _17$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *leftDelimiter_param = NULL, *rightDelimiter_param = NULL, *separator_param = NULL, ldS, rdS, matches, match, words, word, sub, _0, _1, _4, _5, _2$$3, *_6$$5, _7$$5, _9$$6, _10$$6, _12$$6, _13$$6, _14$$6, _15$$6, _18$$8, _19$$8, _20$$8, _21$$8, _22$$8, _23$$8;
	zval text, leftDelimiter, rightDelimiter, separator, pattern, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&leftDelimiter);
	ZVAL_UNDEF(&rightDelimiter);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&ldS);
	ZVAL_UNDEF(&rdS);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&words);
	ZVAL_UNDEF(&word);
	ZVAL_UNDEF(&sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(leftDelimiter)
		Z_PARAM_STR(rightDelimiter)
		Z_PARAM_STR(separator)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &text_param, &leftDelimiter_param, &rightDelimiter_param, &separator_param);
	zephir_get_strval(&text, text_param);
	if (!leftDelimiter_param) {
		ZEPHIR_INIT_VAR(&leftDelimiter);
		ZVAL_STRING(&leftDelimiter, "{");
	} else {
		zephir_get_strval(&leftDelimiter, leftDelimiter_param);
	}
	if (!rightDelimiter_param) {
		ZEPHIR_INIT_VAR(&rightDelimiter);
		ZVAL_STRING(&rightDelimiter, "}");
	} else {
		zephir_get_strval(&rightDelimiter, rightDelimiter_param);
	}
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "|");
	} else {
		zephir_get_strval(&separator, separator_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "substr_count", NULL, 0, &text, &leftDelimiter);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "substr_count", NULL, 0, &text, &rightDelimiter);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_IDENTICAL(&_0, &_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, "Syntax error in string '", &text, "'");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Support/Helper/Str/Dynamic.zep", 43);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&ldS, "preg_quote", NULL, 439, &leftDelimiter);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&rdS, "preg_quote", NULL, 439, &rightDelimiter);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVSVVSVS(&_4, "/", &ldS, "([^", &ldS, &rdS, "]+)", &rdS, "/");
	zephir_get_strval(&pattern, &_4);
	ZEPHIR_INIT_VAR(&matches);
	array_init(&matches);
	ZEPHIR_INIT_VAR(&_5);
	zephir_preg_match(&_5, &pattern, &text, &matches, 1, 2 , 0 );
	if (!(zephir_is_true(&_5))) {
		RETURN_CTOR(&text);
	}
	if (Z_TYPE_P(&matches) == IS_ARRAY) {
		zephir_is_iterable(&matches, 0, "phalcon/Support/Helper/Str/Dynamic.zep", 66);
		if (Z_TYPE_P(&matches) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _6$$5)
			{
				ZEPHIR_INIT_NVAR(&match);
				ZVAL_COPY(&match, _6$$5);
				_8$$6 = !(zephir_array_isset_long(&match, 0));
				if (!(_8$$6)) {
					_8$$6 = !(zephir_array_isset_long(&match, 1));
				}
				if (_8$$6) {
					continue;
				}
				zephir_array_fetch_long(&_9$$6, &match, 1, PH_NOISY | PH_READONLY, "phalcon/Support/Helper/Str/Dynamic.zep", 61);
				ZEPHIR_INIT_NVAR(&words);
				zephir_fast_explode(&words, &separator, &_9$$6, LONG_MAX);
				ZEPHIR_OBS_NVAR(&word);
				ZEPHIR_CALL_FUNCTION(&_10$$6, "array_rand", &_11, 221, &words);
				zephir_check_call_status();
				zephir_array_fetch(&word, &words, &_10$$6, PH_NOISY, "phalcon/Support/Helper/Str/Dynamic.zep", 62);
				zephir_array_fetch_long(&_12$$6, &match, 0, PH_NOISY | PH_READONLY, "phalcon/Support/Helper/Str/Dynamic.zep", 63);
				ZEPHIR_CALL_FUNCTION(&sub, "preg_quote", NULL, 439, &_12$$6, &separator);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$6);
				ZEPHIR_CONCAT_SVS(&_13$$6, "/", &sub, "/");
				ZVAL_LONG(&_14$$6, 1);
				ZEPHIR_CALL_FUNCTION(&_15$$6, "preg_replace", &_16, 50, &_13$$6, &word, &text, &_14$$6);
				zephir_check_call_status();
				zephir_get_strval(&text, &_15$$6);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &matches, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_7$$5, &matches, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&match, &matches, "current", NULL, 0);
				zephir_check_call_status();
					_17$$8 = !(zephir_array_isset_long(&match, 0));
					if (!(_17$$8)) {
						_17$$8 = !(zephir_array_isset_long(&match, 1));
					}
					if (_17$$8) {
						continue;
					}
					zephir_array_fetch_long(&_18$$8, &match, 1, PH_NOISY | PH_READONLY, "phalcon/Support/Helper/Str/Dynamic.zep", 61);
					ZEPHIR_INIT_NVAR(&words);
					zephir_fast_explode(&words, &separator, &_18$$8, LONG_MAX);
					ZEPHIR_OBS_NVAR(&word);
					ZEPHIR_CALL_FUNCTION(&_19$$8, "array_rand", &_11, 221, &words);
					zephir_check_call_status();
					zephir_array_fetch(&word, &words, &_19$$8, PH_NOISY, "phalcon/Support/Helper/Str/Dynamic.zep", 62);
					zephir_array_fetch_long(&_20$$8, &match, 0, PH_NOISY | PH_READONLY, "phalcon/Support/Helper/Str/Dynamic.zep", 63);
					ZEPHIR_CALL_FUNCTION(&sub, "preg_quote", NULL, 439, &_20$$8, &separator);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_21$$8);
					ZEPHIR_CONCAT_SVS(&_21$$8, "/", &sub, "/");
					ZVAL_LONG(&_22$$8, 1);
					ZEPHIR_CALL_FUNCTION(&_23$$8, "preg_replace", &_16, 50, &_21$$8, &word, &text, &_22$$8);
					zephir_check_call_status();
					zephir_get_strval(&text, &_23$$8);
				ZEPHIR_CALL_METHOD(NULL, &matches, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&match);
	}
	RETURN_CTOR(&text);
}

