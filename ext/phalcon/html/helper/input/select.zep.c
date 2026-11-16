
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
#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"


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
 * Class Select
 *
 * @phpstan-import-type html_attributes from HtmlTypes
 * @phpstan-import-type html_select_attributes from HtmlTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Select)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, Select, phalcon, html_helper_input_select, phalcon_html_helper_abstractlist_ce, phalcon_html_helper_input_select_method_entry, 0);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "option", sizeof("option") - 1);
		zephir_declare_typed_property(phalcon_html_helper_input_select_ce, SL("elementTag"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_html_helper_input_select_ce, SL("inOptGroup"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_html_helper_input_select_ce, SL("selected"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_html_helper_input_select_ce, SL("strict"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Add an element to the list
 *
 * @phpstan-param html_attributes $attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval attributes, _1, _3;
	zval text_zv, value_zv, *attributes_param = NULL, *raw_param = NULL, _0, _2, _4, _5;
	zend_string *text = NULL, *value = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elementTag", 10, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(value)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		attributes_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		raw_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	if (!value) {
		ZEPHIR_INIT_VAR(&value_zv);
	} else {
		zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!raw_param) {
		raw = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "processValue", &_zephir_call_cache[0], &attributes, &value_zv);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&_0) != IS_ARRAY)) {
		zephir_throw_variable_type_error(&_0, "attributes", "array");
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&attributes, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "renderFullElement");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 4, 0);
	zephir_memory_observe(&_4);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 856, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fast_append(&_3, &_4);
	zephir_array_fast_append(&_3, &text_zv);
	zephir_array_fast_append(&_3, &attributes);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_BOOL(&_2, raw);
	zephir_array_fast_append(&_3, &_2);
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_CALL_METHOD_CACHED(&_5, this_ptr, "indent", &_zephir_call_cache[1]);
	zephir_check_call_status();
	zephir_array_fast_append(&_1, &_5);
	zephir_update_property_array_append(this_ptr, SL("store"), &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Add a placeholder to the element
 *
 * @phpstan-param html_attributes $attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, addPlaceholder)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval attributes, _0, _2;
	zval text_zv, value_zv, *attributes_param = NULL, *raw_param = NULL, _1, _3, _4;
	zend_string *text = NULL, *value = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elementTag", 10, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(value)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		attributes_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		raw_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	if (!value) {
		ZEPHIR_INIT_VAR(&value_zv);
	} else {
		zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!raw_param) {
		raw = 0;
	} else {
		}
	if (Z_TYPE_P(&value_zv) != IS_NULL) {
		zephir_array_update_string(&attributes, SL("value"), &value_zv, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "renderFullElement");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 4, 0);
	zephir_memory_observe(&_3);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 856, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fast_append(&_2, &_3);
	zephir_array_fast_append(&_2, &text_zv);
	zephir_array_fast_append(&_2, &attributes);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_BOOL(&_1, raw);
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_CALL_METHOD_CACHED(&_4, this_ptr, "indent", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_4);
	zephir_update_property_array_append(this_ptr, SL("store"), &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Populates the select from a data provider.
 *
 * Flat entries: key = option value, value = label string.
 * Optgroup entries: key = group label, value = [value => label] array.
 *
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, fromData)
{
	zval _6$$4, _20$$4, _13$$5, _14$$5, _18$$6, _19$$6, _22$$7, _23$$7, _26$$9, _40$$9, _33$$10, _34$$10, _38$$11, _39$$11, _42$$12, _43$$12;
	zend_bool _25, _16$$4, _12$$5, _17$$6, _21$$7, _36$$9, _32$$10, _37$$11, _41$$12;
	zend_string *_5, *_11$$4, *_31$$9;
	zend_ulong _4, _10$$4, _30$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, attributes, key, optionAttrs, subAttrs, subKey, subValue, value, _0, *_1, _2, *_3, _24, *_7$$4, _8$$4, *_9$$4, _15$$4, *_27$$9, _28$$9, *_29$$9, _35$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&optionAttrs);
	ZVAL_UNDEF(&subAttrs);
	ZVAL_UNDEF(&subKey);
	ZVAL_UNDEF(&subValue);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_35$$9);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_38$$11);
	ZVAL_UNDEF(&_39$$11);
	ZVAL_UNDEF(&_42$$12);
	ZVAL_UNDEF(&_43$$12);
	ZEND_TLS zephir_method_cache _zephir_call_cache[27];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(data, phalcon_contracts_html_helper_input_selectdata_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data);
	ZEPHIR_CALL_METHOD_CACHED(&attributes, data, "getAttributes", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_0, data, "getOptions", &_zephir_call_cache[1]);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Html/Helper/Input/Select.zep", 121);
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
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				zephir_cast_to_string(&_6$$4, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "optGroup", &_zephir_call_cache[2], &_6$$4);
				zephir_check_call_status();
				if (Z_TYPE_P(&value) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_8$$4);
					zephir_string_to_char_array(&_8$$4, &value);
					_7$$4 = &_8$$4;
				} else {
					_7$$4 = &value;
				}
				zephir_is_iterable(_7$$4, 0, "phalcon/Html/Helper/Input/Select.zep", 113);
				if (Z_TYPE_P(_7$$4) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_7$$4), _10$$4, _11$$4, _9$$4)
					{
						ZEPHIR_INIT_NVAR(&subKey);
						if (_11$$4 != NULL) { 
							ZVAL_STR_COPY(&subKey, _11$$4);
						} else {
							ZVAL_LONG(&subKey, _10$$4);
						}
						ZEPHIR_INIT_NVAR(&subValue);
						ZVAL_COPY(&subValue, _9$$4);
						_12$$5 = zephir_array_isset_value(&attributes, &subKey);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_12$$5) {
							ZEPHIR_OBS_NVAR(&subAttrs);
							zephir_array_fetch(&subAttrs, &attributes, &subKey, PH_NOISY, "phalcon/Html/Helper/Input/Select.zep", 108);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_INIT_NVAR(&subAttrs);
							array_init(&subAttrs);
						}
						zephir_cast_to_string(&_13$$5, &subValue);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_cast_to_string(&_14$$5, &subKey);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "add", &_zephir_call_cache[3], &_13$$5, &_14$$5, &subAttrs);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _7$$4, "rewind", &_zephir_call_cache[4]);
					zephir_check_call_status();
					_16$$4 = 1;
					while (1) {
						if (_16$$4) {
							_16$$4 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _7$$4, "next", &_zephir_call_cache[5]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_15$$4, _7$$4, "valid", &_zephir_call_cache[6]);
						zephir_check_call_status();
						if (!zend_is_true(&_15$$4)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&subKey, _7$$4, "key", &_zephir_call_cache[7]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&subValue, _7$$4, "current", &_zephir_call_cache[8]);
						zephir_check_call_status();
							_17$$6 = zephir_array_isset_value(&attributes, &subKey);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_17$$6) {
								ZEPHIR_OBS_NVAR(&subAttrs);
								zephir_array_fetch(&subAttrs, &attributes, &subKey, PH_NOISY, "phalcon/Html/Helper/Input/Select.zep", 108);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_INIT_NVAR(&subAttrs);
								array_init(&subAttrs);
							}
							zephir_cast_to_string(&_18$$6, &subValue);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_cast_to_string(&_19$$6, &subKey);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "add", &_zephir_call_cache[9], &_18$$6, &_19$$6, &subAttrs);
							zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&subValue);
				ZEPHIR_INIT_NVAR(&subKey);
				zephir_cast_to_string(&_20$$4, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "optGroup", &_zephir_call_cache[10], &_20$$4);
				zephir_check_call_status();
			} else {
				_21$$7 = zephir_array_isset_value(&attributes, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_21$$7) {
					ZEPHIR_OBS_NVAR(&optionAttrs);
					zephir_array_fetch(&optionAttrs, &attributes, &key, PH_NOISY, "phalcon/Html/Helper/Input/Select.zep", 115);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&optionAttrs);
					array_init(&optionAttrs);
				}
				zephir_cast_to_string(&_22$$7, &value);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_23$$7, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "add", &_zephir_call_cache[11], &_22$$7, &_23$$7, &optionAttrs);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[12]);
		zephir_check_call_status();
		_25 = 1;
		while (1) {
			if (_25) {
				_25 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[13]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_24, _1, "valid", &_zephir_call_cache[14]);
			zephir_check_call_status();
			if (!zend_is_true(&_24)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, _1, "key", &_zephir_call_cache[15]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, _1, "current", &_zephir_call_cache[16]);
			zephir_check_call_status();
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					zephir_cast_to_string(&_26$$9, &key);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "optGroup", &_zephir_call_cache[17], &_26$$9);
					zephir_check_call_status();
					if (Z_TYPE_P(&value) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_28$$9);
						zephir_string_to_char_array(&_28$$9, &value);
						_27$$9 = &_28$$9;
					} else {
						_27$$9 = &value;
					}
					zephir_is_iterable(_27$$9, 0, "phalcon/Html/Helper/Input/Select.zep", 113);
					if (Z_TYPE_P(_27$$9) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_27$$9), _30$$9, _31$$9, _29$$9)
						{
							ZEPHIR_INIT_NVAR(&subKey);
							if (_31$$9 != NULL) { 
								ZVAL_STR_COPY(&subKey, _31$$9);
							} else {
								ZVAL_LONG(&subKey, _30$$9);
							}
							ZEPHIR_INIT_NVAR(&subValue);
							ZVAL_COPY(&subValue, _29$$9);
							_32$$10 = zephir_array_isset_value(&attributes, &subKey);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_32$$10) {
								ZEPHIR_OBS_NVAR(&subAttrs);
								zephir_array_fetch(&subAttrs, &attributes, &subKey, PH_NOISY, "phalcon/Html/Helper/Input/Select.zep", 108);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_INIT_NVAR(&subAttrs);
								array_init(&subAttrs);
							}
							zephir_cast_to_string(&_33$$10, &subValue);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_cast_to_string(&_34$$10, &subKey);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "add", &_zephir_call_cache[18], &_33$$10, &_34$$10, &subAttrs);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _27$$9, "rewind", &_zephir_call_cache[19]);
						zephir_check_call_status();
						_36$$9 = 1;
						while (1) {
							if (_36$$9) {
								_36$$9 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _27$$9, "next", &_zephir_call_cache[20]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_35$$9, _27$$9, "valid", &_zephir_call_cache[21]);
							zephir_check_call_status();
							if (!zend_is_true(&_35$$9)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&subKey, _27$$9, "key", &_zephir_call_cache[22]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&subValue, _27$$9, "current", &_zephir_call_cache[23]);
							zephir_check_call_status();
								_37$$11 = zephir_array_isset_value(&attributes, &subKey);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_37$$11) {
									ZEPHIR_OBS_NVAR(&subAttrs);
									zephir_array_fetch(&subAttrs, &attributes, &subKey, PH_NOISY, "phalcon/Html/Helper/Input/Select.zep", 108);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									ZEPHIR_INIT_NVAR(&subAttrs);
									array_init(&subAttrs);
								}
								zephir_cast_to_string(&_38$$11, &subValue);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_cast_to_string(&_39$$11, &subKey);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "add", &_zephir_call_cache[24], &_38$$11, &_39$$11, &subAttrs);
								zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&subValue);
					ZEPHIR_INIT_NVAR(&subKey);
					zephir_cast_to_string(&_40$$9, &key);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "optGroup", &_zephir_call_cache[25], &_40$$9);
					zephir_check_call_status();
				} else {
					_41$$12 = zephir_array_isset_value(&attributes, &key);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_41$$12) {
						ZEPHIR_OBS_NVAR(&optionAttrs);
						zephir_array_fetch(&optionAttrs, &attributes, &key, PH_NOISY, "phalcon/Html/Helper/Input/Select.zep", 115);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&optionAttrs);
						array_init(&optionAttrs);
					}
					zephir_cast_to_string(&_42$$12, &value);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_cast_to_string(&_43$$12, &key);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "add", &_zephir_call_cache[26], &_42$$12, &_43$$12, &optionAttrs);
					zephir_check_call_status();
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();
}

/**
 * Creates an option group
 *
 * @phpstan-param html_attributes $attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, optGroup)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _1$$3, _3$$3, _11$$4;
	zval label_zv, *attributes_param = NULL, __$true, __$false, _0, _14, _2$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$4, _9$$4, _10$$4, _12$$4, _13$$4;
	zend_string *label = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&label_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_11$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("inOptGroup", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("indentLevel", 11, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(label)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		attributes_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (!label) {
		ZEPHIR_INIT_VAR(&label_zv);
	} else {
		zephir_memory_observe(&label_zv);
	ZVAL_STR_COPY(&label_zv, label);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 857, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 3, 0);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "optGroupStart");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 2, 0);
		zephir_array_fast_append(&_3$$3, &label_zv);
		zephir_array_fast_append(&_3$$3, &attributes);
		zephir_array_fast_append(&_1$$3, &_3$$3);
		ZEPHIR_CALL_METHOD_CACHED(&_4$$3, this_ptr, "indent", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_array_fast_append(&_1$$3, &_4$$3);
		zephir_update_property_array_append(this_ptr, SL("store"), &_1$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_1, 858, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_LONG(&_6$$3, 1);
		ZEPHIR_INIT_VAR(&_7$$3);
		zephir_add_function(&_7$$3, &_5$$3, &_6$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 858, &_7$$3);
	} else {
		zephir_read_property_cached(&_8$$4, this_ptr, _zephir_prop_1, 858, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_LONG(&_9$$4, 1);
		ZEPHIR_INIT_VAR(&_10$$4);
		zephir_sub_function(&_10$$4, &_8$$4, &_9$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 858, &_10$$4);
		ZEPHIR_INIT_VAR(&_11$$4);
		zephir_create_array(&_11$$4, 3, 0);
		ZEPHIR_INIT_VAR(&_12$$4);
		ZVAL_STRING(&_12$$4, "optGroupEnd");
		zephir_array_fast_append(&_11$$4, &_12$$4);
		ZEPHIR_INIT_NVAR(&_12$$4);
		array_init(&_12$$4);
		zephir_array_fast_append(&_11$$4, &_12$$4);
		ZEPHIR_CALL_METHOD_CACHED(&_13$$4, this_ptr, "indent", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_array_fast_append(&_11$$4, &_13$$4);
		zephir_update_property_array_append(this_ptr, SL("store"), &_11$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&_14);
	zephir_read_property_cached(&_14, this_ptr, _zephir_prop_0, 857, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!zephir_is_true(&_14)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 857, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 857, &__$false);
	}
	RETURN_THIS();
}

/**
 * Adds a non-selectable placeholder option as the first entry. Renders
 * as `<option value="" disabled selected>$text</option>`, matching the
 * common HTML idiom for "Choose..."-style prompts.
 *
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, placeholder)
{
	zval _0, _2, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, __$false, _1, _3, _5;
	zend_string *text = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elementTag", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "renderFullElement");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 4, 0);
	zephir_memory_observe(&_3);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 856, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fast_append(&_2, &_3);
	zephir_array_fast_append(&_2, &text_zv);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 3, 0);
	add_assoc_stringl_ex(&_4, SL("value"), SL(""));
	add_assoc_stringl_ex(&_4, SL("disabled"), SL("disabled"));
	add_assoc_stringl_ex(&_4, SL("selected"), SL("selected"));
	zephir_array_fast_append(&_2, &_4);
	zephir_array_fast_append(&_2, &__$false);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_CALL_METHOD_CACHED(&_5, this_ptr, "indent", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_5);
	zephir_update_property_array_append(this_ptr, SL("store"), &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Html_Helper_Input_Select, selected)
{
	zval selected_zv;
	zend_string *selected = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&selected_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("selected", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(selected)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&selected_zv, selected);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 859, &selected_zv);
	RETURN_THISW();
}

/**
 * Toggles strict (`===`) comparison between an option's `value` and
 * the previously stored `selected` value. Defaults to loose (`==`),
 * matching the round-tripping fix in `AbstractChecked` so mixed
 * int/string form data marks the right option as selected.
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, strict)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("strict", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(0, 1, &flag_param);
	if (!flag_param) {
		flag = 1;
	} else {
		}
	if (flag) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 860, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 860, &__$false);
	}
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Html_Helper_Input_Select, getTag)
{

	RETURN_STRING("select");
}

PHP_METHOD(Phalcon_Html_Helper_Input_Select, optGroupEnd)
{

	RETURN_STRING("</optgroup>");
}

/**
 * @phpstan-param html_attributes $attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, optGroupStart)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval label_zv, *attributes_param = NULL, _0;
	zend_string *label = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&label_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(label)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	attributes_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&label_zv);
	ZVAL_STR_COPY(&label_zv, label);
	zephir_get_arrval(&attributes, attributes_param);
	zephir_array_update_string(&attributes, SL("label"), &label_zv, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "optgroup");
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "renderTag", &_zephir_call_cache[0], &_0, &attributes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks if the value has been passed and if it is the same as the
 * value stored in the object
 *
 * @phpstan-param html_attributes $attributes
 *
 * @phpstan-return html_attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, processValue)
{
	zend_bool matched = 0, _0, _5$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *value = NULL;
	zval *attributes_param = NULL, value_zv, _1$$3, _2$$4, _3$$5, _4$$6, _6$$7;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$7);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("selected", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("strict", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	attributes_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&attributes, attributes_param);
	if (!value) {
		ZEPHIR_INIT_VAR(&value_zv);
	} else {
		zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	}
	_0 = zephir_is_numeric(&value_zv);
	if (!(_0)) {
		_0 = !(ZEPHIR_IS_EMPTY(&value_zv));
	}
	if (_0) {
		zephir_array_update_string(&attributes, SL("value"), &value_zv, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 859, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!ZEPHIR_IS_STRING_IDENTICAL(&_1$$3, "")) {
			zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_1, 860, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_true(&_2$$4)) {
				zephir_read_property_cached(&_3$$5, this_ptr, _zephir_prop_0, 859, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				matched = ZEPHIR_IS_IDENTICAL(&value_zv, &_3$$5);
			} else {
				zephir_read_property_cached(&_4$$6, this_ptr, _zephir_prop_0, 859, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_5$$6 = ZEPHIR_IS_EQUAL(&value_zv, &_4$$6);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				matched = _5$$6;
			}
			if (matched) {
				ZEPHIR_INIT_VAR(&_6$$7);
				ZVAL_STRING(&_6$$7, "selected");
				zephir_array_update_string(&attributes, SL("selected"), &_6$$7, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	RETURN_CTOR(&attributes);
}

