
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"


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
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Select)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, Select, phalcon, html_helper_input_select, phalcon_html_helper_abstractlist_ce, phalcon_html_helper_input_select_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_input_select_ce, SL("elementTag"), "option", ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_html_helper_input_select_ce, SL("inOptGroup"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_input_select_ce, SL("selected"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_html_helper_input_select_ce, SL("strict"), 0, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Add an element to the list
 *
 * @param string      $text
 * @param string|null $value
 * @param array       $attributes
 * @param bool        $raw
 *
 * @return static
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "processvalue", NULL, 0, &attributes, &value_zv);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&attributes, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "renderFullElement");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 4, 0);
	zephir_memory_observe(&_4);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("elementTag"), PH_NOISY_CC);
	zephir_array_fast_append(&_3, &_4);
	zephir_array_fast_append(&_3, &text_zv);
	zephir_array_fast_append(&_3, &attributes);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_BOOL(&_2, raw);
	zephir_array_fast_append(&_3, &_2);
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "indent", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_1, &_5);
	zephir_update_property_array_append(this_ptr, SL("store"), &_1);
	RETURN_THIS();
}

/**
 * Add a placeholder to the element
 *
 * @param string $text
 * @param string $value
 * @param array  $attributes
 * @param bool   $raw
 *
 * @return static
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
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "renderFullElement");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 4, 0);
	zephir_memory_observe(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("elementTag"), PH_NOISY_CC);
	zephir_array_fast_append(&_2, &_3);
	zephir_array_fast_append(&_2, &text_zv);
	zephir_array_fast_append(&_2, &attributes);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_BOOL(&_1, raw);
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "indent", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_4);
	zephir_update_property_array_append(this_ptr, SL("store"), &_0);
	RETURN_THIS();
}

/**
 * Populates the select from a data provider.
 *
 * Flat entries: key = option value, value = label string.
 * Optgroup entries: key = group label, value = [value => label] array.
 *
 * @param SelectData data
 *
 * @return static
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, fromData)
{
	zval _4$$4, _16$$4, _9$$5, _10$$5, _14$$6, _15$$6, _17$$7, _18$$7, _21$$9, _31$$9, _25$$10, _26$$10, _29$$11, _30$$11, _32$$12, _33$$12;
	zend_bool _20, _13$$4, _28$$9;
	zend_string *_3, *_8$$4, *_24$$9;
	zend_ulong _2, _7$$4, _23$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, attributes, key, optionAttrs, subAttrs, subKey, subValue, value, _0, *_1, _19, *_6$$4, _12$$4, *_22$$9, _27$$9;
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
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$12);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(data, phalcon_contracts_html_helper_input_selectdata_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data);
	ZEPHIR_CALL_METHOD(&attributes, data, "getattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, data, "getoptions", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Html/Helper/Input/Select.zep", 145);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				zephir_cast_to_string(&_4$$4, &key);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "optgroup", &_5, 0, &_4$$4);
				zephir_check_call_status();
				zephir_is_iterable(&value, 0, "phalcon/Html/Helper/Input/Select.zep", 137);
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _7$$4, _8$$4, _6$$4)
					{
						ZEPHIR_INIT_NVAR(&subKey);
						if (_8$$4 != NULL) { 
							ZVAL_STR_COPY(&subKey, _8$$4);
						} else {
							ZVAL_LONG(&subKey, _7$$4);
						}
						ZEPHIR_INIT_NVAR(&subValue);
						ZVAL_COPY(&subValue, _6$$4);
						if (zephir_array_isset_value(&attributes, &subKey)) {
							ZEPHIR_OBS_NVAR(&subAttrs);
							zephir_array_fetch(&subAttrs, &attributes, &subKey, PH_NOISY, "phalcon/Html/Helper/Input/Select.zep", 132);
						} else {
							ZEPHIR_INIT_NVAR(&subAttrs);
							array_init(&subAttrs);
						}
						zephir_cast_to_string(&_9$$5, &subValue);
						zephir_cast_to_string(&_10$$5, &subKey);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_11, 0, &_9$$5, &_10$$5, &subAttrs);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
					zephir_check_call_status();
					_13$$4 = 1;
					while (1) {
						if (_13$$4) {
							_13$$4 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_12$$4, &value, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_12$$4)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&subKey, &value, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&subValue, &value, "current", NULL, 0);
						zephir_check_call_status();
							if (zephir_array_isset_value(&attributes, &subKey)) {
								ZEPHIR_OBS_NVAR(&subAttrs);
								zephir_array_fetch(&subAttrs, &attributes, &subKey, PH_NOISY, "phalcon/Html/Helper/Input/Select.zep", 132);
							} else {
								ZEPHIR_INIT_NVAR(&subAttrs);
								array_init(&subAttrs);
							}
							zephir_cast_to_string(&_14$$6, &subValue);
							zephir_cast_to_string(&_15$$6, &subKey);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_11, 0, &_14$$6, &_15$$6, &subAttrs);
							zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&subValue);
				ZEPHIR_INIT_NVAR(&subKey);
				zephir_cast_to_string(&_16$$4, &key);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "optgroup", &_5, 0, &_16$$4);
				zephir_check_call_status();
			} else {
				if (zephir_array_isset_value(&attributes, &key)) {
					ZEPHIR_OBS_NVAR(&optionAttrs);
					zephir_array_fetch(&optionAttrs, &attributes, &key, PH_NOISY, "phalcon/Html/Helper/Input/Select.zep", 139);
				} else {
					ZEPHIR_INIT_NVAR(&optionAttrs);
					array_init(&optionAttrs);
				}
				zephir_cast_to_string(&_17$$7, &value);
				zephir_cast_to_string(&_18$$7, &key);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_11, 0, &_17$$7, &_18$$7, &optionAttrs);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_20 = 1;
		while (1) {
			if (_20) {
				_20 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_19, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_19)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					zephir_cast_to_string(&_21$$9, &key);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "optgroup", &_5, 0, &_21$$9);
					zephir_check_call_status();
					zephir_is_iterable(&value, 0, "phalcon/Html/Helper/Input/Select.zep", 137);
					if (Z_TYPE_P(&value) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _23$$9, _24$$9, _22$$9)
						{
							ZEPHIR_INIT_NVAR(&subKey);
							if (_24$$9 != NULL) { 
								ZVAL_STR_COPY(&subKey, _24$$9);
							} else {
								ZVAL_LONG(&subKey, _23$$9);
							}
							ZEPHIR_INIT_NVAR(&subValue);
							ZVAL_COPY(&subValue, _22$$9);
							if (zephir_array_isset_value(&attributes, &subKey)) {
								ZEPHIR_OBS_NVAR(&subAttrs);
								zephir_array_fetch(&subAttrs, &attributes, &subKey, PH_NOISY, "phalcon/Html/Helper/Input/Select.zep", 132);
							} else {
								ZEPHIR_INIT_NVAR(&subAttrs);
								array_init(&subAttrs);
							}
							zephir_cast_to_string(&_25$$10, &subValue);
							zephir_cast_to_string(&_26$$10, &subKey);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_11, 0, &_25$$10, &_26$$10, &subAttrs);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
						zephir_check_call_status();
						_28$$9 = 1;
						while (1) {
							if (_28$$9) {
								_28$$9 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_27$$9, &value, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_27$$9)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&subKey, &value, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&subValue, &value, "current", NULL, 0);
							zephir_check_call_status();
								if (zephir_array_isset_value(&attributes, &subKey)) {
									ZEPHIR_OBS_NVAR(&subAttrs);
									zephir_array_fetch(&subAttrs, &attributes, &subKey, PH_NOISY, "phalcon/Html/Helper/Input/Select.zep", 132);
								} else {
									ZEPHIR_INIT_NVAR(&subAttrs);
									array_init(&subAttrs);
								}
								zephir_cast_to_string(&_29$$11, &subValue);
								zephir_cast_to_string(&_30$$11, &subKey);
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_11, 0, &_29$$11, &_30$$11, &subAttrs);
								zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&subValue);
					ZEPHIR_INIT_NVAR(&subKey);
					zephir_cast_to_string(&_31$$9, &key);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "optgroup", &_5, 0, &_31$$9);
					zephir_check_call_status();
				} else {
					if (zephir_array_isset_value(&attributes, &key)) {
						ZEPHIR_OBS_NVAR(&optionAttrs);
						zephir_array_fetch(&optionAttrs, &attributes, &key, PH_NOISY, "phalcon/Html/Helper/Input/Select.zep", 139);
					} else {
						ZEPHIR_INIT_NVAR(&optionAttrs);
						array_init(&optionAttrs);
					}
					zephir_cast_to_string(&_32$$12, &value);
					zephir_cast_to_string(&_33$$12, &key);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_11, 0, &_32$$12, &_33$$12, &optionAttrs);
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
 * @param string $label
 * @param array  $attributes
 *
 * @return static
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, optGroup)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _1$$3, _3$$3, _8$$4;
	zval label_zv, *attributes_param = NULL, __$true, __$false, _0, _11, _2$$3, _4$$3, _5$$3, _6$$4, _7$$4, _9$$4, _10$$4;
	zend_string *label = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&label_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$4);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("inOptGroup"), PH_NOISY_CC | PH_READONLY);
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
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "indent", NULL, 0);
		zephir_check_call_status();
		zephir_array_fast_append(&_1$$3, &_4$$3);
		zephir_update_property_array_append(this_ptr, SL("store"), &_1$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_LONG(&_2$$3, 1);
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("indentLevel"), PH_NOISY_CC);
		ZEPHIR_ADD_ASSIGN(&_5$$3, &_2$$3)
		zephir_update_property_zval(this_ptr, ZEND_STRL("indentLevel"), &_5$$3);
	} else {
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_LONG(&_7$$4, 1);
		zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("indentLevel"), PH_NOISY_CC);
		ZEPHIR_SUB_ASSIGN(&_6$$4, &_7$$4)
		zephir_update_property_zval(this_ptr, ZEND_STRL("indentLevel"), &_6$$4);
		ZEPHIR_INIT_VAR(&_8$$4);
		zephir_create_array(&_8$$4, 3, 0);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "optGroupEnd");
		zephir_array_fast_append(&_8$$4, &_9$$4);
		ZEPHIR_INIT_NVAR(&_9$$4);
		array_init(&_9$$4);
		zephir_array_fast_append(&_8$$4, &_9$$4);
		ZEPHIR_CALL_METHOD(&_10$$4, this_ptr, "indent", NULL, 0);
		zephir_check_call_status();
		zephir_array_fast_append(&_8$$4, &_10$$4);
		zephir_update_property_array_append(this_ptr, SL("store"), &_8$$4);
	}
	zephir_memory_observe(&_11);
	zephir_read_property(&_11, this_ptr, ZEND_STRL("inOptGroup"), PH_NOISY_CC);
	if (!zephir_is_true(&_11)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("inOptGroup"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("inOptGroup"), &__$false);
	}
	RETURN_THIS();
}

/**
 * Adds a non-selectable placeholder option as the first entry. Renders
 * as `<option value="" disabled selected>$text</option>`, matching the
 * common HTML idiom for "Choose..."-style prompts.
 *
 * @param string $text
 *
 * @return static
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
	zephir_read_property(&_3, this_ptr, ZEND_STRL("elementTag"), PH_NOISY_CC);
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
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "indent", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_5);
	zephir_update_property_array_append(this_ptr, SL("store"), &_0);
	RETURN_THIS();
}

/**
 * @param string $selected
 *
 * @return static
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, selected)
{
	zval selected_zv;
	zend_string *selected = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&selected_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(selected)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&selected_zv, selected);
	zephir_update_property_zval(this_ptr, ZEND_STRL("selected"), &selected_zv);
	RETURN_THISW();
}

/**
 * Toggles strict (`===`) comparison between an option's `value` and
 * the previously stored `selected` value. Defaults to loose (`==`),
 * matching the round-tripping fix in `AbstractChecked` so mixed
 * int/string form data marks the right option as selected.
 *
 * @param bool $flag
 *
 * @return static
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, strict)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("strict"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("strict"), &__$false);
	}
	RETURN_THISW();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, getTag)
{

	RETURN_STRING("select");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, optGroupEnd)
{

	RETURN_STRING("</optgroup>");
}

/**
 * @param string $label
 * @param array  $attributes
 *
 * @return string
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
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "optgroup");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "rendertag", NULL, 0, &_0, &attributes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks if the value has been passed and if it is the same as the
 * value stored in the object
 *
 * @param array  $attributes
 * @param string $value
 *
 * @return array
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, processValue)
{
	zend_bool matched = 0, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *value = NULL;
	zval *attributes_param = NULL, value_zv, _1$$3, _2$$4, _3$$5, _4$$6, _5$$7;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
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
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("selected"), PH_NOISY_CC | PH_READONLY);
		if (!ZEPHIR_IS_STRING_IDENTICAL(&_1$$3, "")) {
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("strict"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_2$$4)) {
				zephir_read_property(&_3$$5, this_ptr, ZEND_STRL("selected"), PH_NOISY_CC | PH_READONLY);
				matched = ZEPHIR_IS_IDENTICAL(&value_zv, &_3$$5);
			} else {
				zephir_read_property(&_4$$6, this_ptr, ZEND_STRL("selected"), PH_NOISY_CC | PH_READONLY);
				matched = ZEPHIR_IS_EQUAL(&value_zv, &_4$$6);
			}
			if (matched) {
				ZEPHIR_INIT_VAR(&_5$$7);
				ZVAL_STRING(&_5$$7, "selected");
				zephir_array_update_string(&attributes, SL("selected"), &_5$$7, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CTOR(&attributes);
}

