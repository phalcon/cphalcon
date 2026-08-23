
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
	zval _0$$3, _10$$5, _12$$8, _21$$9, _23$$12;
	zend_bool _15, _4$$5, _16$$9;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input = NULL, input_sub, __$null, key, result, value, *_1, _14, _5$$5, _6$$5, _7$$5, _9$$7, _11$$8, _13$$8, _17$$9, _18$$9, _19$$9, _20$$11, _22$$12, _24$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_23$$12);
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
	zephir_is_iterable(input, 0, "phalcon/Html/Escaper/AttributeEscaper.zep", 81);
	if (Z_TYPE_P(input) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(input), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			_4$$5 = Z_TYPE_P(&value) == IS_NULL;
			if (!(_4$$5)) {
				_4$$5 = ZEPHIR_IS_FALSE_IDENTICAL(&value);
			}
			if (_4$$5) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_5$$5);
			zephir_fast_trim(&_5$$5, &key, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_CPY_WRT(&key, &_5$$5);
			ZEPHIR_INIT_NVAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "~[\\s/=]~");
			ZEPHIR_INIT_NVAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "");
			ZEPHIR_CALL_FUNCTION(&_7$$5, "preg_replace", &_8, 6, &_5$$5, &_6$$5, &key);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&key, &_7$$5);
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_9$$7);
				zephir_fast_join_str(&_9$$7, SL(" "), &value);
				ZEPHIR_CPY_WRT(&value, &_9$$7);
			}
			zephir_cast_to_string(&_10$$5, &key);
			ZEPHIR_CALL_METHOD(&_7$$5, this_ptr, "escapevalue", NULL, 0, &_10$$5);
			zephir_check_call_status();
			zephir_concat_self(&result, &_7$$5);
			if (!ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
				zephir_cast_to_string(&_12$$8, &value);
				ZEPHIR_CALL_METHOD(&_11$$8, this_ptr, "escapevalue", NULL, 0, &_12$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$8);
				ZEPHIR_CONCAT_SVS(&_13$$8, "=\"", &_11$$8, "\"");
				zephir_concat_self(&result, &_13$$8);
			}
			zephir_concat_self_str(&result, SL(" "));
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, input, "rewind", NULL, 0);
		zephir_check_call_status();
		_15 = 1;
		while (1) {
			if (_15) {
				_15 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, input, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_14, input, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, input, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, input, "current", NULL, 0);
			zephir_check_call_status();
				_16$$9 = Z_TYPE_P(&value) == IS_NULL;
				if (!(_16$$9)) {
					_16$$9 = ZEPHIR_IS_FALSE_IDENTICAL(&value);
				}
				if (_16$$9) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_17$$9);
				zephir_fast_trim(&_17$$9, &key, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_CPY_WRT(&key, &_17$$9);
				ZEPHIR_INIT_NVAR(&_17$$9);
				ZVAL_STRING(&_17$$9, "~[\\s/=]~");
				ZEPHIR_INIT_NVAR(&_18$$9);
				ZVAL_STRING(&_18$$9, "");
				ZEPHIR_CALL_FUNCTION(&_19$$9, "preg_replace", &_8, 6, &_17$$9, &_18$$9, &key);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&key, &_19$$9);
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_20$$11);
					zephir_fast_join_str(&_20$$11, SL(" "), &value);
					ZEPHIR_CPY_WRT(&value, &_20$$11);
				}
				zephir_cast_to_string(&_21$$9, &key);
				ZEPHIR_CALL_METHOD(&_19$$9, this_ptr, "escapevalue", NULL, 0, &_21$$9);
				zephir_check_call_status();
				zephir_concat_self(&result, &_19$$9);
				if (!ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
					zephir_cast_to_string(&_23$$12, &value);
					ZEPHIR_CALL_METHOD(&_22$$12, this_ptr, "escapevalue", NULL, 0, &_23$$12);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_24$$12);
					ZEPHIR_CONCAT_SVS(&_24$$12, "=\"", &_22$$12, "\"");
					zephir_concat_self(&result, &_24$$12);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 809, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 810, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_2, 811, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 196, &input_zv, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

