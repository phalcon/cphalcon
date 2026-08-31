
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
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
 * Shared base for rendering a group of same-named inputs (checkbox or radio)
 * from an options array.
 *
 * Each option in the $options array may be either:
 *   - a scalar string label:  ['value' => 'Label text']
 *   - a rich definition:      ['value' => ['label' => 'Label text', 'disabled' => true, ...]]
 *
 * The $checked parameter is resolved by the concrete subclass:
 *   - CheckboxGroup compares against an array of selected values
 *   - RadioGroup compares against a single scalar value
 *
 * @phpstan-import-type html_attributes from HtmlTypes
 * @phpstan-import-type html_group_definition from HtmlTypes
 * @phpstan-import-type html_group_options from HtmlTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_AbstractGroup)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, AbstractGroup, phalcon, html_helper_input_abstractgroup, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_input_abstractgroup_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_html_helper_input_abstractgroup_ce, SL("checked"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_html_helper_input_abstractgroup_ce, SL("name"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * @phpstan-var html_group_options
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_helper_input_abstractgroup_ce, SL("options"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var html_attributes
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_helper_input_abstractgroup_ce, SL("sharedAttributes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "checkbox", sizeof("checkbox") - 1);
		zephir_declare_typed_property(phalcon_html_helper_input_abstractgroup_ce, SL("type"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

/**
 * @phpstan-param html_group_options $options
 * @phpstan-param html_attributes     $attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractGroup, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options, attributes;
	zval name_zv, *options_param = NULL, *checked = NULL, checked_sub, *attributes_param = NULL, __$null;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&checked_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&attributes);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("name", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("options", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("checked", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("sharedAttributes", 16, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(name)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(checked)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	options_param = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		checked = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		attributes_param = ZEND_CALL_ARG(execute_data, 4);
	}
	ZVAL_STR(&name_zv, name);
	zephir_get_arrval(&options, options_param);
	if (!checked) {
		checked = &checked_sub;
		checked = &__$null;
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 217, &name_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 218, &options);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 219, checked);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 220, &attributes);
	RETURN_THIS();
}

/**
 * Renders the group of inputs as a string.
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractGroup, __toString)
{
	zval _8$$3, _14$$5;
	zend_bool _11, _6$$3, _12$$5;
	zend_string *_5;
	zend_ulong _4;
	zval lines;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, definition, value, _0, *_1, _2, *_3, _10, _15, _16, _17, _7$$3, _13$$5;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_14$$5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("checked", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("sharedAttributes", 16, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&lines);
	array_init(&lines);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 218, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Html/Helper/Input/AbstractGroup.zep", 89);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&value);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&value, _5);
			} else {
				ZVAL_LONG(&value, _4);
			}
			ZEPHIR_INIT_NVAR(&definition);
			ZVAL_COPY(&definition, _3);
			_6$$3 = Z_TYPE_P(&definition) != IS_STRING;
			if (_6$$3) {
				_6$$3 = Z_TYPE_P(&definition) != IS_ARRAY;
			}
			if (_6$$3) {
				continue;
			}
			zephir_cast_to_string(&_8$$3, &value);
			ZEPHIR_CALL_METHOD(&_7$$3, this_ptr, "renderitem", &_9, 0, &_8$$3, &definition);
			zephir_check_call_status();
			zephir_array_append(&lines, &_7$$3, PH_SEPARATE, "phalcon/Html/Helper/Input/AbstractGroup.zep", 86);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_10, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&definition, _1, "current", NULL, 0);
			zephir_check_call_status();
				_12$$5 = Z_TYPE_P(&definition) != IS_STRING;
				if (_12$$5) {
					_12$$5 = Z_TYPE_P(&definition) != IS_ARRAY;
				}
				if (_12$$5) {
					continue;
				}
				zephir_cast_to_string(&_14$$5, &value);
				ZEPHIR_CALL_METHOD(&_13$$5, this_ptr, "renderitem", &_9, 0, &_14$$5, &definition);
				zephir_check_call_status();
				zephir_array_append(&lines, &_13$$5, PH_SEPARATE, "phalcon/Html/Helper/Input/AbstractGroup.zep", 86);
		}
	}
	ZEPHIR_INIT_NVAR(&definition);
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_VAR(&_15);
	array_init(&_15);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 218, &_15);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 219, &__$null);
	ZEPHIR_INIT_VAR(&_16);
	array_init(&_16);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 220, &_16);
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_GET_CONSTANT(&_17, "PHP_EOL");
	zephir_fast_join(return_value, &_17, &lines);
	RETURN_MM();
}

/**
 * Determines whether the given value is considered checked.
 *
 * @param string $value
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractGroup, isChecked)
{
}

/**
 * Renders a single input + optional label pair.
 *
 * @phpstan-param html_group_definition $definition
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractGroup, renderItem)
{
	zval _2$$6;
	zend_bool _0$$3;
	zval _5, _7, _10, _16, _17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value_zv, *definition, definition_sub, baseId, input, inputAttrs, itemExtras, label, labelText, _3, _4, _6, _8, _9, _11, _12, _13, _15, _1$$3, _14$$7;
	zend_string *value = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&baseId);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&inputAttrs);
	ZVAL_UNDEF(&itemExtras);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&labelText);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("name", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("sharedAttributes", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("type", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(value)
		Z_PARAM_ZVAL(definition)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	if (Z_TYPE_P(definition) == IS_ARRAY) {
		_0$$3 = zephir_array_isset_value_string(definition, SL("label"));
		if (_0$$3) {
			zephir_memory_observe(&_1$$3);
			zephir_array_fetch_string(&_1$$3, definition, SL("label"), PH_NOISY, "phalcon/Html/Helper/Input/AbstractGroup.zep", 115);
			_0$$3 = Z_TYPE_P(&_1$$3) == IS_STRING;
		}
		if (_0$$3) {
			zephir_memory_observe(&labelText);
			zephir_array_fetch_string(&labelText, definition, SL("label"), PH_NOISY, "phalcon/Html/Helper/Input/AbstractGroup.zep", 116);
		} else {
			ZEPHIR_CPY_WRT(&labelText, &value_zv);
		}
		ZEPHIR_CPY_WRT(&itemExtras, definition);
		zephir_array_unset_string(&itemExtras, SL("label"), PH_SEPARATE);
	} else {
		zephir_cast_to_string(&_2$$6, definition);
		ZEPHIR_CPY_WRT(&labelText, &_2$$6);
		ZEPHIR_INIT_NVAR(&itemExtras);
		array_init(&itemExtras);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "[");
	zephir_array_fast_append(&_5, &_6);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "]");
	zephir_array_fast_append(&_5, &_6);
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "_");
	zephir_array_fast_append(&_7, &_6);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "");
	zephir_array_fast_append(&_7, &_6);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_0, 217, PH_NOISY_CC | PH_READONLY);
	zephir_fast_str_replace(&_4, &_5, &_7, &_8);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "_");
	zephir_fast_trim(&_3, &_4, &_6, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_INIT_VAR(&baseId);
	ZEPHIR_CONCAT_VSV(&baseId, &_3, "_", &value_zv);
	zephir_read_property_cached(&_9, this_ptr, _zephir_prop_1, 220, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 3, 0);
	ZEPHIR_INIT_VAR(&_11);
	if (zephir_array_isset_value_string(&itemExtras, SL("id"))) {
		ZEPHIR_OBS_NVAR(&_11);
		zephir_array_fetch_string(&_11, &itemExtras, SL("id"), PH_NOISY, "phalcon/Html/Helper/Input/AbstractGroup.zep", 134);
	} else {
		ZEPHIR_CPY_WRT(&_11, &baseId);
	}
	zephir_array_update_string(&_10, SL("id"), &_11, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_12);
	zephir_read_property_cached(&_12, this_ptr, _zephir_prop_0, 217, PH_NOISY_CC);
	zephir_array_update_string(&_10, SL("name"), &_12, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_10, SL("value"), &value_zv, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&inputAttrs, "array_merge", NULL, 199, &_9, &itemExtras, &_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "ischecked", NULL, 0, &value_zv);
	zephir_check_call_status();
	if (zephir_is_true(&_13)) {
		ZEPHIR_INIT_VAR(&_14$$7);
		ZVAL_STRING(&_14$$7, "checked");
		zephir_array_update_string(&inputAttrs, SL("checked"), &_14$$7, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_unset_string(&inputAttrs, SL("checked"), PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_INIT_VAR(&_16);
	zephir_create_array(&_16, 1, 0);
	ZEPHIR_OBS_NVAR(&_12);
	zephir_read_property_cached(&_12, this_ptr, _zephir_prop_2, 221, PH_NOISY_CC);
	zephir_array_update_string(&_16, SL("type"), &_12, PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(&_15, &_16, &inputAttrs);
	ZEPHIR_CPY_WRT(&inputAttrs, &_15);
	ZEPHIR_INIT_NVAR(&_15);
	ZVAL_STRING(&_15, "input");
	ZEPHIR_CALL_METHOD(&input, this_ptr, "rendertag", NULL, 0, &_15, &inputAttrs);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_17);
	zephir_create_array(&_17, 1, 0);
	ZEPHIR_OBS_NVAR(&_12);
	zephir_array_fetch_string(&_12, &inputAttrs, SL("id"), PH_NOISY, "phalcon/Html/Helper/Input/AbstractGroup.zep", 149);
	zephir_array_update_string(&_17, SL("for"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_15);
	ZVAL_STRING(&_15, "label");
	ZEPHIR_CALL_METHOD(&label, this_ptr, "renderfullelement", NULL, 0, &_15, &labelText, &_17);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &input, &label);
	RETURN_MM();
}

