
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
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper_AttributeEscaper)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Escaper, AttributeEscaper, phalcon, html_escaper_attributeescaper, phalcon_html_escaper_abstractescaper_ce, phalcon_html_escaper_attributeescaper_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array|string|null $input
 *
 * @return string
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
 * @param array|string|null $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper_AttributeEscaper, escape)
{
	zval _0$$3, _8$$5, _10$$8, _18$$9, _20$$12;
	zend_bool _13, _4$$5, _14$$9;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input = NULL, input_sub, __$null, key, result, value, *_1, _12, _5$$5, _7$$5, _6$$7, _9$$8, _11$$8, _15$$9, _17$$9, _16$$11, _19$$12, _21$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_20$$12);
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
	zephir_is_iterable(input, 0, "phalcon/Html/Escaper/AttributeEscaper.zep", 74);
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
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_6$$7);
				zephir_fast_join_str(&_6$$7, SL(" "), &value);
				ZEPHIR_CPY_WRT(&value, &_6$$7);
			}
			zephir_cast_to_string(&_8$$5, &key);
			ZEPHIR_CALL_METHOD(&_7$$5, this_ptr, "escapevalue", NULL, 0, &_8$$5);
			zephir_check_call_status();
			zephir_concat_self(&result, &_7$$5);
			if (!ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
				zephir_cast_to_string(&_10$$8, &value);
				ZEPHIR_CALL_METHOD(&_9$$8, this_ptr, "escapevalue", NULL, 0, &_10$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$8);
				ZEPHIR_CONCAT_SVS(&_11$$8, "=\"", &_9$$8, "\"");
				zephir_concat_self(&result, &_11$$8);
			}
			zephir_concat_self_str(&result, SL(" "));
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, input, "rewind", NULL, 0);
		zephir_check_call_status();
		_13 = 1;
		while (1) {
			if (_13) {
				_13 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, input, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_12, input, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, input, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, input, "current", NULL, 0);
			zephir_check_call_status();
				_14$$9 = Z_TYPE_P(&value) == IS_NULL;
				if (!(_14$$9)) {
					_14$$9 = ZEPHIR_IS_FALSE_IDENTICAL(&value);
				}
				if (_14$$9) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_15$$9);
				zephir_fast_trim(&_15$$9, &key, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_CPY_WRT(&key, &_15$$9);
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_16$$11);
					zephir_fast_join_str(&_16$$11, SL(" "), &value);
					ZEPHIR_CPY_WRT(&value, &_16$$11);
				}
				zephir_cast_to_string(&_18$$9, &key);
				ZEPHIR_CALL_METHOD(&_17$$9, this_ptr, "escapevalue", NULL, 0, &_18$$9);
				zephir_check_call_status();
				zephir_concat_self(&result, &_17$$9);
				if (!ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
					zephir_cast_to_string(&_20$$12, &value);
					ZEPHIR_CALL_METHOD(&_19$$12, this_ptr, "escapevalue", NULL, 0, &_20$$12);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_21$$12);
					ZEPHIR_CONCAT_SVS(&_21$$12, "=\"", &_19$$12, "\"");
					zephir_concat_self(&result, &_21$$12);
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
 *
 * @param string $input
 *
 * @return string
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("flags"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("encoding"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("doubleEncode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 0, &input_zv, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

