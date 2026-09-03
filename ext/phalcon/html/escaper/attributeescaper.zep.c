
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
 * For the full copyright and license information, please view the LICENSE.txt
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
	zval _0$$3, _12$$5, _14$$8, _23$$9, _25$$12;
	zend_bool _17, _6$$5, _18$$9;
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input = NULL, input_sub, __$null, key, result, value, *_1, _2, *_3, _16, _7$$5, _8$$5, _9$$5, _11$$7, _13$$8, _15$$8, _19$$9, _20$$9, _21$$9, _22$$11, _24$$12, _26$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_25$$12);
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
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escapevalue", NULL, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	if (Z_TYPE_P(input) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, input);
		_1 = &_2;
	} else {
		_1 = input;
	}
	zephir_is_iterable(_1, 0, "phalcon/Html/Escaper/AttributeEscaper.zep", 81);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			_6$$5 = Z_TYPE_P(&value) == IS_NULL;
			if (!(_6$$5)) {
				_6$$5 = ZEPHIR_IS_FALSE_IDENTICAL(&value);
			}
			if (_6$$5) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_7$$5);
			zephir_fast_trim(&_7$$5, &key, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_CPY_WRT(&key, &_7$$5);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "~[\\s/=]~");
			ZEPHIR_INIT_NVAR(&_8$$5);
			ZVAL_STRING(&_8$$5, "");
			ZEPHIR_CALL_FUNCTION(&_9$$5, "preg_replace", &_10, 6, &_7$$5, &_8$$5, &key);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&key, &_9$$5);
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_11$$7);
				zephir_fast_join_str(&_11$$7, SL(" "), &value);
				ZEPHIR_CPY_WRT(&value, &_11$$7);
			}
			zephir_cast_to_string(&_12$$5, &key);
			ZEPHIR_CALL_METHOD(&_9$$5, this_ptr, "escapevalue", NULL, 0, &_12$$5);
			zephir_check_call_status();
			zephir_concat_self(&result, &_9$$5);
			if (!ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
				zephir_cast_to_string(&_14$$8, &value);
				ZEPHIR_CALL_METHOD(&_13$$8, this_ptr, "escapevalue", NULL, 0, &_14$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$8);
				ZEPHIR_CONCAT_SVS(&_15$$8, "=\"", &_13$$8, "\"");
				zephir_concat_self(&result, &_15$$8);
			}
			zephir_concat_self_str(&result, SL(" "));
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_16, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _1, "current", NULL, 0);
			zephir_check_call_status();
				_18$$9 = Z_TYPE_P(&value) == IS_NULL;
				if (!(_18$$9)) {
					_18$$9 = ZEPHIR_IS_FALSE_IDENTICAL(&value);
				}
				if (_18$$9) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_19$$9);
				zephir_fast_trim(&_19$$9, &key, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_CPY_WRT(&key, &_19$$9);
				ZEPHIR_INIT_NVAR(&_19$$9);
				ZVAL_STRING(&_19$$9, "~[\\s/=]~");
				ZEPHIR_INIT_NVAR(&_20$$9);
				ZVAL_STRING(&_20$$9, "");
				ZEPHIR_CALL_FUNCTION(&_21$$9, "preg_replace", &_10, 6, &_19$$9, &_20$$9, &key);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&key, &_21$$9);
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_22$$11);
					zephir_fast_join_str(&_22$$11, SL(" "), &value);
					ZEPHIR_CPY_WRT(&value, &_22$$11);
				}
				zephir_cast_to_string(&_23$$9, &key);
				ZEPHIR_CALL_METHOD(&_21$$9, this_ptr, "escapevalue", NULL, 0, &_23$$9);
				zephir_check_call_status();
				zephir_concat_self(&result, &_21$$9);
				if (!ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
					zephir_cast_to_string(&_25$$12, &value);
					ZEPHIR_CALL_METHOD(&_24$$12, this_ptr, "escapevalue", NULL, 0, &_25$$12);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_26$$12);
					ZEPHIR_CONCAT_SVS(&_26$$12, "=\"", &_24$$12, "\"");
					zephir_concat_self(&result, &_26$$12);
				}
				zephir_concat_self_str(&result, SL(" "));
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 811, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 812, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_2, 813, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 197, &input_zv, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

