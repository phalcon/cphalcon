
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
 * @phpstan-param non-empty-string $separator
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Dynamic, __invoke)
{
	zend_bool _10$$6, _11$$6, _12$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_15 = NULL, *_20 = NULL;
	zend_string *leftDelimiter = NULL, *rightDelimiter = NULL, *separator = NULL;
	zval *text_param = NULL, leftDelimiter_zv, rightDelimiter_zv, separator_zv, ldS, rdS, matches, match, words, word, sub, _0, _2, _5, _6, _3$$3, *_7$$5, _8$$5, *_9$$5, _13$$6, _14$$6, _16$$6, _17$$6, _18$$6, _19$$6;
	zval text, pattern;

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&leftDelimiter_zv);
	ZVAL_UNDEF(&rightDelimiter_zv);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&ldS);
	ZVAL_UNDEF(&rdS);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&words);
	ZVAL_UNDEF(&word);
	ZVAL_UNDEF(&sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_ZVAL(text_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(leftDelimiter)
		Z_PARAM_STR(rightDelimiter)
		Z_PARAM_STR(separator)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	text_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_strval(&text, text_param);
	if (!leftDelimiter) {
		leftDelimiter = zend_string_init(ZEND_STRL("{"), 0);
		zephir_memory_observe(&leftDelimiter_zv);
		ZVAL_STR(&leftDelimiter_zv, leftDelimiter);
	} else {
		zephir_memory_observe(&leftDelimiter_zv);
	ZVAL_STR_COPY(&leftDelimiter_zv, leftDelimiter);
	}
	if (!rightDelimiter) {
		rightDelimiter = zend_string_init(ZEND_STRL("}"), 0);
		zephir_memory_observe(&rightDelimiter_zv);
		ZVAL_STR(&rightDelimiter_zv, rightDelimiter);
	} else {
		zephir_memory_observe(&rightDelimiter_zv);
	ZVAL_STR_COPY(&rightDelimiter_zv, rightDelimiter);
	}
	if (!separator) {
		separator = zend_string_init(ZEND_STRL("|"), 0);
		zephir_memory_observe(&separator_zv);
		ZVAL_STR(&separator_zv, separator);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	ZEPHIR_CALL_FUNCTION(&_0, "mb_substr_count", &_1, 0, &text, &leftDelimiter_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "mb_substr_count", &_1, 0, &text, &rightDelimiter_zv);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_IDENTICAL(&_0, &_2))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_support_helper_str_exceptions_syntaxerror_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 0, &text);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Support/Helper/Str/Dynamic.zep", 36);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&ldS, "preg_quote", &_4, 0, &leftDelimiter_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&rdS, "preg_quote", &_4, 0, &rightDelimiter_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVSVVSVS(&_5, "/", &ldS, "([^", &ldS, &rdS, "]+)", &rdS, "/");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&pattern, &_5);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&matches);
	array_init(&matches);
	ZEPHIR_INIT_VAR(&_6);
	zephir_preg_match(&_6, &pattern, &text, &matches, 1, 2 , 0 );
	if (!(zephir_is_true(&_6))) {
		RETURN_CTOR(&text);
	}
	if (Z_TYPE_P(&matches) == IS_ARRAY) {
		if (Z_TYPE_P(&matches) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_8$$5);
			zephir_string_to_char_array(&_8$$5, &matches);
			_7$$5 = &_8$$5;
		} else {
			_7$$5 = &matches;
		}
		zephir_is_iterable(_7$$5, 0, "phalcon/Support/Helper/Str/Dynamic.zep", 59);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_7$$5), _9$$5)
		{
			ZEPHIR_INIT_NVAR(&match);
			ZVAL_COPY(&match, _9$$5);
			_10$$6 = zephir_array_isset_value_long(&match, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_11$$6 = !(_10$$6);
			if (!(_11$$6)) {
				_12$$6 = zephir_array_isset_value_long(&match, 1);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_11$$6 = !(_12$$6);
			}
			if (_11$$6) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&_13$$6);
			zephir_array_fetch_long(&_13$$6, &match, 1, PH_NOISY, "phalcon/Support/Helper/Str/Dynamic.zep", 54);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&words);
			zephir_fast_explode(&words, &separator_zv, &_13$$6, NULL);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&word);
			ZEPHIR_CALL_FUNCTION(&_14$$6, "array_rand", &_15, 0, &words);
			zephir_check_call_status();
			zephir_array_fetch(&word, &words, &_14$$6, PH_NOISY, "phalcon/Support/Helper/Str/Dynamic.zep", 55);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_16$$6);
			zephir_array_fetch_long(&_16$$6, &match, 0, PH_NOISY, "phalcon/Support/Helper/Str/Dynamic.zep", 56);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_FUNCTION(&sub, "preg_quote", &_4, 0, &_16$$6, &separator_zv);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_17$$6);
			ZEPHIR_CONCAT_SVS(&_17$$6, "/", &sub, "/");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_LONG(&_18$$6, 1);
			ZEPHIR_CALL_FUNCTION(&_19$$6, "preg_replace", &_20, 4, &_17$$6, &word, &text, &_18$$6);
			zephir_check_call_status();
			zephir_get_strval(&text, &_19$$6);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&match);
	}
	RETURN_CTOR(&text);
}

