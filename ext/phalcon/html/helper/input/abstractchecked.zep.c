
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/concat.h"
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
 * Shared base for inputs that can be checked: `<input type="checkbox">` and
 * `<input type="radio">`. Holds the optional surrounding `<label>` markup,
 * the `unchecked` companion hidden input, and the rule that decides whether
 * the rendered tag carries `checked="checked"`.
 *
 * The match between `checked` and `value` is loose (`==`) by default so that
 * mixed int/string form input round-trips correctly (e.g. `value=0` against
 * `checked="0"`). Strict (`===`) matching is available via `strict(true)`.
 *
 * @phpstan-import-type html_attributes from HtmlTypes
 * @phpstan-import-type html_checked_label from HtmlTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_AbstractChecked)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, AbstractChecked, phalcon, html_helper_input_abstractchecked, phalcon_html_helper_input_abstractinput_ce, phalcon_html_helper_input_abstractchecked_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @phpstan-var html_checked_label
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 4);
		add_assoc_stringl_ex(&_zc0, SL("start"), SL(""));
		add_assoc_stringl_ex(&_zc0, SL("text"), SL(""));
		add_assoc_stringl_ex(&_zc0, SL("end"), SL(""));
		zephir_declare_typed_property(phalcon_html_helper_input_abstractchecked_ce, SL("label"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_html_helper_input_abstractchecked_ce, SL("strict"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Returns the HTML for the input, optionally surrounded by the label
 * fragment configured via `label()` and preceded by the hidden companion
 * input emitted when an `unchecked` attribute is supplied.
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractChecked, __toString)
{
	zval _1;
	zval element, label, unchecked, _0, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&unchecked);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("label", 5, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processchecked", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&unchecked, this_ptr, "processunchecked", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(&element, phalcon_html_helper_input_abstractchecked_ce, getThis(), "__tostring", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 212, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&label, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0);
	add_assoc_stringl_ex(&_1, SL("start"), SL(""));
	add_assoc_stringl_ex(&_1, SL("text"), SL(""));
	add_assoc_stringl_ex(&_1, SL("end"), SL(""));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 212, &_1);
	zephir_array_fetch_string(&_2, &label, SL("start"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 66);
	zephir_array_fetch_string(&_3, &label, SL("text"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 68);
	zephir_array_fetch_string(&_4, &label, SL("end"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 68);
	ZEPHIR_CONCAT_VVVVV(return_value, &unchecked, &_2, &element, &_3, &_4);
	RETURN_MM();
}

/**
 * Attaches a wrapping `<label>` to the element. The supplied attributes
 * are merged with a default `for` pointing at the input's `id`. A `text`
 * pseudo-attribute, if present, becomes the label text and is stripped
 * from the rendered attributes.
 *
 * @phpstan-param html_attributes $attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractChecked, label)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, text, _2, _4, _5, _7, _8, _0$$4, _1$$4;
	zval attributes, _3, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("escaper", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("attributes", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("label", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &attributes_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	zephir_memory_observe(&text);
	if (!(zephir_array_isset_string_fetch(&text, &attributes, SL("text"), 0))) {
		ZEPHIR_INIT_NVAR(&text);
		ZVAL_STRING(&text, "");
	} else {
		zephir_read_property_cached(&_0$$4, this_ptr, _zephir_prop_0, 213, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_1$$4, &_0$$4, "html", NULL, 0, &text);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&text, &_1$$4);
	}
	zephir_array_unset_string(&attributes, SL("text"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 214, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_5);
	zephir_array_fetch_string(&_5, &_4, SL("id"), PH_NOISY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 94);
	zephir_array_update_string(&_3, SL("for"), &_5, PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(&_2, &_3, &attributes);
	ZEPHIR_CPY_WRT(&attributes, &_2);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 3, 0);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "label");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "rendertag", NULL, 0, &_8, &attributes);
	zephir_check_call_status();
	zephir_array_update_string(&_6, SL("start"), &_7, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("text"), &text, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_6, SL("end"), SL("</label>"));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 212, &_6);
	RETURN_THIS();
}

/**
 * Toggles strict (`===`) comparison between the `checked` attribute and
 * the `value` attribute when deciding whether to render the input as
 * checked. Defaults to loose (`==`), which matches typical form-input
 * round-tripping where types may differ between the source data and the
 * value rendered into the markup.
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractChecked, strict)
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 215, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 215, &__$false);
	}
	RETURN_THISW();
}

/**
 * Decides whether the rendered tag carries `checked="checked"`. Two
 * paths qualify as checked: an unconditional opt-in via
 * `["checked" => "checked"]` (case-insensitive) or `["checked" => true]`,
 * and a value-match path where the supplied `checked` attribute equals
 * the input's `value` (`==` by default, `===` under `strict(true)`).
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractChecked, processChecked)
{
	zval attributes;
	zend_bool matched = 0, _1$$4;
	zval checked, value, _0, _2$$4, _3$$7, _4$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&checked);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&attributes);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("strict", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 214, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&attributes, &_0);
	zephir_memory_observe(&checked);
	if (!(zephir_array_isset_string_fetch(&checked, &attributes, SL("checked"), 0))) {
		ZEPHIR_INIT_NVAR(&checked);
		ZVAL_NULL(&checked);
	}
	zephir_array_unset_string(&attributes, SL("checked"), PH_SEPARATE);
	if (Z_TYPE_P(&checked) != IS_NULL) {
		matched = 0;
		if (ZEPHIR_IS_TRUE_IDENTICAL(&checked)) {
			matched = 1;
		} else {
			_1$$4 = Z_TYPE_P(&checked) == IS_STRING;
			if (_1$$4) {
				ZEPHIR_INIT_VAR(&_2$$4);
				zephir_fast_strtolower(&_2$$4, &checked);
				_1$$4 = ZEPHIR_IS_STRING_IDENTICAL(&_2$$4, "checked");
			}
			if (_1$$4) {
				matched = 1;
			} else {
				zephir_memory_observe(&value);
				if (!(zephir_array_isset_string_fetch(&value, &attributes, SL("value"), 0))) {
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_NULL(&value);
				}
				zephir_read_property_cached(&_3$$7, this_ptr, _zephir_prop_1, 215, PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_3$$7)) {
					matched = ZEPHIR_IS_IDENTICAL(&checked, &value);
				} else {
					matched = ZEPHIR_IS_EQUAL(&checked, &value);
				}
			}
		}
		if (matched) {
			ZEPHIR_INIT_VAR(&_4$$11);
			ZVAL_STRING(&_4$$11, "checked");
			zephir_array_update_string(&attributes, SL("checked"), &_4$$11, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 214, &attributes);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the markup for the optional hidden companion input that lets
 * a checkbox/radio submit a value when unchecked.
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractChecked, processUnchecked)
{
	zval attributes, _1$$4;
	zval unchecked, _0, _2$$4, _3$$4, _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&unchecked);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_1$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 214, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&attributes, &_0);
	zephir_memory_observe(&unchecked);
	if (!(zephir_array_isset_string_fetch(&unchecked, &attributes, SL("unchecked"), 0))) {
		ZEPHIR_INIT_NVAR(&unchecked);
		ZVAL_STRING(&unchecked, "");
	}
	zephir_array_unset_string(&attributes, SL("unchecked"), PH_SEPARATE);
	if (!(ZEPHIR_IS_EMPTY(&unchecked))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 2, 0);
		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_0, 214, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_3$$4);
		zephir_array_fetch_string(&_3$$4, &_2$$4, SL("name"), PH_NOISY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 187);
		zephir_array_update_string(&_1$$4, SL("name"), &_3$$4, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_1$$4, SL("value"), &unchecked, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "hidden");
		ZEPHIR_CALL_METHOD(&unchecked, this_ptr, "rendertag", NULL, 0, &_4$$4, &_1$$4);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 214, &attributes);
	RETURN_CCTOR(&unchecked);
}

