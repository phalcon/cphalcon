
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
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Class Select
 *
 * @property string $elementTag
 * @property bool   $inOptGroup
 * @property string $selected
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
 * @return Select
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval attributes, _1, _3;
	zval *text_param = NULL, *value_param = NULL, *attributes_param = NULL, *raw_param = NULL, _0, _2, _4, _5;
	zval text, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(value)
		Z_PARAM_ARRAY(attributes)
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &text_param, &value_param, &attributes_param, &raw_param);
	zephir_get_strval(&text, text_param);
	if (!value_param) {
		ZEPHIR_INIT_VAR(&value);
	} else {
		zephir_get_strval(&value, value_param);
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
		raw = zephir_get_boolval(raw_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "processvalue", NULL, 295, &attributes, &value);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&attributes, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "renderFullElement");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 4, 0);
	ZEPHIR_OBS_VAR(&_4);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("elementTag"), PH_NOISY_CC);
	zephir_array_fast_append(&_3, &_4);
	zephir_array_fast_append(&_3, &text);
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
 * @return Select
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, addPlaceholder)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval attributes, _1, _3;
	zval *text_param = NULL, *value = NULL, value_sub, *attributes_param = NULL, *raw_param = NULL, __$null, _2, _4, _5;
	zval text, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(value)
		Z_PARAM_ARRAY(attributes)
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &text_param, &value, &attributes_param, &raw_param);
	zephir_get_strval(&text, text_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
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
		raw = zephir_get_boolval(raw_param);
	}


	if (Z_TYPE_P(value) != IS_NULL) {
		zephir_cast_to_string(&_0$$3, value);
		zephir_array_update_string(&attributes, SL("value"), &_0$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "renderFullElement");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 4, 0);
	ZEPHIR_OBS_VAR(&_4);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("elementTag"), PH_NOISY_CC);
	zephir_array_fast_append(&_3, &_4);
	zephir_array_fast_append(&_3, &text);
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
 * Creates an option group
 *
 * @param string $label
 * @param array  $attributes
 *
 * @return Select
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, optGroup)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _1$$3, _3$$3, _8$$4;
	zval *label_param = NULL, *attributes_param = NULL, __$true, __$false, _0, _11, _2$$3, _4$$3, _5$$3, _6$$4, _7$$4, _9$$4, _10$$4;
	zval label;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&label);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(label)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &label_param, &attributes_param);
	if (!label_param) {
		ZEPHIR_INIT_VAR(&label);
	} else {
		zephir_get_strval(&label, label_param);
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
		zephir_array_fast_append(&_3$$3, &label);
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
	ZEPHIR_OBS_VAR(&_11);
	zephir_read_property(&_11, this_ptr, ZEND_STRL("inOptGroup"), PH_NOISY_CC);
	if (!zephir_is_true(&_11)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("inOptGroup"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("inOptGroup"), &__$false);
	}
	RETURN_THIS();
}

/**
 * @param string $selected
 *
 * @return Select
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, selected)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *selected_param = NULL;
	zval selected;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&selected);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(selected)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &selected_param);
	zephir_get_strval(&selected, selected_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("selected"), &selected);
	RETURN_THIS();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, getTag)
{
	zval *this_ptr = getThis();



	RETURN_STRING("select");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select, optGroupEnd)
{
	zval *this_ptr = getThis();



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
	zval *label_param = NULL, *attributes_param = NULL, _0;
	zval label;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(label)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &label_param, &attributes_param);
	zephir_get_strval(&label, label_param);
	zephir_get_arrval(&attributes, attributes_param);


	zephir_array_update_string(&attributes, SL("label"), &label, PH_COPY | PH_SEPARATE);
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
	zend_bool _0, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attributes_param = NULL, *value = NULL, value_sub, __$null, _1$$3, _3$$3, _4$$4;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(attributes)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &attributes_param, &value);
	zephir_get_arrval(&attributes, attributes_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	_0 = zephir_is_numeric(value);
	if (!(_0)) {
		_0 = !(ZEPHIR_IS_EMPTY(value));
	}
	if (_0) {
		zephir_array_update_string(&attributes, SL("value"), value, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("selected"), PH_NOISY_CC | PH_READONLY);
		_2$$3 = !(ZEPHIR_IS_EMPTY(&_1$$3));
		if (_2$$3) {
			zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("selected"), PH_NOISY_CC | PH_READONLY);
			_2$$3 = ZEPHIR_IS_IDENTICAL(value, &_3$$3);
		}
		if (_2$$3) {
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "selected");
			zephir_array_update_string(&attributes, SL("selected"), &_4$$4, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CTOR(&attributes);
}

