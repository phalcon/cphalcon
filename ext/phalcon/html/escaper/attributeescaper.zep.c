
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * Escapes either a single attribute value (string) or an associative array
 * of attribute pairs. Boolean `true` becomes a bare key (e.g. `disabled`);
 * `false` and `null` skip the entry; arrays are joined with a space.
 *
 * @phpstan-import-type html_escaper_input from HtmlTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper_AttributeEscaper)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Escaper, AttributeEscaper, phalcon, html_escaper_attributeescaper, phalcon_html_escaper_abstractescaper_ce, phalcon_html_escaper_attributeescaper_method_entry, 0);

	return SUCCESS;
}

/**
 * @phpstan-param html_escaper_input $input
 */
PHP_METHOD(Phalcon_Html_Escaper_AttributeEscaper, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input = NULL, input_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &input);
	if (!input) {
		input = &input_sub;
		input = &__$null;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", NULL, 0, input);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @phpstan-param html_escaper_input $input
 */
PHP_METHOD(Phalcon_Html_Escaper_AttributeEscaper, escape)
{
	zval _0$$3, _13$$5, _15$$8, _24$$9, _26$$12;
	zend_bool _18, _7$$5, _19$$9;
	zend_string *_6;
	zend_ulong _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input = NULL, input_sub, __$null, key, result, value, *_2, _3, *_4, _17, _8$$5, _9$$5, _10$$5, _12$$7, _14$$8, _16$$8, _20$$9, _21$$9, _22$$9, _23$$11, _25$$12, _27$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_26$$12);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &input);
	if (!input) {
		input = &input_sub;
		input = &__$null;
	}
	if (EXPECTED((Z_TYPE_P(input) != IS_ARRAY))) {
		if (Z_TYPE_P(input) == IS_NULL) {
			RETURN_MM_STRING("");
		}
		zephir_cast_to_string(&_0$$3, input);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escapeValue", &_1, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	if (Z_TYPE_P(input) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, input);
		_2 = &_3;
	} else {
		_2 = input;
	}
	zephir_is_iterable(_2, 0, "phalcon/Html/Escaper/AttributeEscaper.zep", 81);
	if (Z_TYPE_P(_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_2), _5, _6, _4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&key, _6);
			} else {
				ZVAL_LONG(&key, _5);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _4);
			_7$$5 = Z_TYPE_P(&value) == IS_NULL;
			if (!(_7$$5)) {
				_7$$5 = ZEPHIR_IS_FALSE_IDENTICAL(&value);
			}
			if (_7$$5) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_8$$5);
			zephir_fast_trim(&_8$$5, &key, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_CPY_WRT(&key, &_8$$5);
			ZEPHIR_INIT_NVAR(&_8$$5);
			ZVAL_STRING(&_8$$5, "~[\\s/=]~");
			ZEPHIR_INIT_NVAR(&_9$$5);
			ZVAL_STRING(&_9$$5, "");
			ZEPHIR_CALL_FUNCTION(&_10$$5, "preg_replace", &_11, 4, &_8$$5, &_9$$5, &key);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&key, &_10$$5);
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_12$$7);
				zephir_fast_join_str(&_12$$7, SL(" "), &value);
				ZEPHIR_CPY_WRT(&value, &_12$$7);
			}
			zephir_cast_to_string(&_13$$5, &key);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_10$$5, this_ptr, "escapeValue", &_1, 0, &_13$$5);
			zephir_check_call_status();
			zephir_concat_self(&result, &_10$$5);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
				zephir_cast_to_string(&_15$$8, &value);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_14$$8, this_ptr, "escapeValue", &_1, 0, &_15$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$8);
				ZEPHIR_CONCAT_SVS(&_16$$8, "=\"", &_14$$8, "\"");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&result, &_16$$8);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_concat_self_str(&result, SL(" "));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _2, "rewind", NULL, 0);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _2, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_17, _2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, _2, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _2, "current", NULL, 0);
			zephir_check_call_status();
				_19$$9 = Z_TYPE_P(&value) == IS_NULL;
				if (!(_19$$9)) {
					_19$$9 = ZEPHIR_IS_FALSE_IDENTICAL(&value);
				}
				if (_19$$9) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_20$$9);
				zephir_fast_trim(&_20$$9, &key, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_CPY_WRT(&key, &_20$$9);
				ZEPHIR_INIT_NVAR(&_20$$9);
				ZVAL_STRING(&_20$$9, "~[\\s/=]~");
				ZEPHIR_INIT_NVAR(&_21$$9);
				ZVAL_STRING(&_21$$9, "");
				ZEPHIR_CALL_FUNCTION(&_22$$9, "preg_replace", &_11, 4, &_20$$9, &_21$$9, &key);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&key, &_22$$9);
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_23$$11);
					zephir_fast_join_str(&_23$$11, SL(" "), &value);
					ZEPHIR_CPY_WRT(&value, &_23$$11);
				}
				zephir_cast_to_string(&_24$$9, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_22$$9, this_ptr, "escapeValue", &_1, 0, &_24$$9);
				zephir_check_call_status();
				zephir_concat_self(&result, &_22$$9);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
					zephir_cast_to_string(&_26$$12, &value);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_25$$12, this_ptr, "escapeValue", &_1, 0, &_26$$12);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_27$$12);
					ZEPHIR_CONCAT_SVS(&_27$$12, "=\"", &_25$$12, "\"");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&result, &_27$$12);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_concat_self_str(&result, SL(" "));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_fast_trim(return_value, &result, NULL , ZEPHIR_TRIM_RIGHT);
	RETURN_MM();
}

/**
 * Encodes a single key/value via `htmlspecialchars`.
 */
PHP_METHOD(Phalcon_Html_Escaper_AttributeEscaper, escapeValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, _0, _1, _2;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("flags", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("encoding", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("doubleEncode", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 829, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 830, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_2, 831, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 199, &input_zv, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

