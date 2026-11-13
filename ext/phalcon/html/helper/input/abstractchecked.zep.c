
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
#include "kernel/main.h"
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("label", 5, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processChecked", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&unchecked, this_ptr, "processUnchecked", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT_CACHED(&element, phalcon_html_helper_input_abstractchecked_ce, getThis(), "__toString", &_zephir_call_cache[2]);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 218, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&label, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0);
	add_assoc_stringl_ex(&_1, SL("start"), SL(""));
	add_assoc_stringl_ex(&_1, SL("text"), SL(""));
	add_assoc_stringl_ex(&_1, SL("end"), SL(""));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 218, &_1);
	zephir_memory_observe(&_2);
	zephir_array_fetch_string(&_2, &label, SL("start"), PH_NOISY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 66);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_3);
	zephir_array_fetch_string(&_3, &label, SL("text"), PH_NOISY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 68);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_4);
	zephir_array_fetch_string(&_4, &label, SL("end"), PH_NOISY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 68);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CONCAT_VVVVV(return_value, &unchecked, &_2, &element, &_3, &_4);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, text, _3, _5, _6, _8, _9, _1$$4, _2$$4;
	zval attributes, _4, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	_0 = zephir_array_isset_string_fetch(&text, &attributes, SL("text"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		ZEPHIR_INIT_NVAR(&text);
		ZVAL_STRING(&text, "");
	} else {
		zephir_read_property_cached(&_1$$4, this_ptr, _zephir_prop_0, 219, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_2$$4, &_1$$4, "html", &_zephir_call_cache[0], &text);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&text, &_2$$4);
	}
	zephir_array_unset_string(&attributes, SL("text"), PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 1, 0);
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 220, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_6);
	zephir_array_fetch_string(&_6, &_5, SL("id"), PH_NOISY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 94);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_4, SL("for"), &_6, PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(&_3, &_4, &attributes);
	if (UNEXPECTED(Z_TYPE_P(&_3) != IS_ARRAY)) {
		zephir_throw_variable_type_error(&_3, "attributes", "array");
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&attributes, &_3);
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 3, 0);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "label");
	ZEPHIR_CALL_METHOD_CACHED(&_8, this_ptr, "renderTag", &_zephir_call_cache[1], &_9, &attributes);
	zephir_check_call_status();
	zephir_array_update_string(&_7, SL("start"), &_8, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_7, SL("text"), &text, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_7, SL("end"), SL("</label>"));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 218, &_7);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 221, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 221, &__$false);
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
	zend_bool matched = 0, _1, _2$$4, _4$$7, _6$$10;
	zval checked, value, _0, _3$$4, _5$$7, _7$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&checked);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$11);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 220, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&_0) != IS_ARRAY)) {
		zephir_throw_variable_type_error(&_0, "attributes", "array");
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&attributes, &_0);
	zephir_memory_observe(&checked);
	_1 = zephir_array_isset_string_fetch(&checked, &attributes, SL("checked"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		ZEPHIR_INIT_NVAR(&checked);
		ZVAL_NULL(&checked);
	}
	zephir_array_unset_string(&attributes, SL("checked"), PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&checked) != IS_NULL) {
		matched = 0;
		if (ZEPHIR_IS_TRUE_IDENTICAL(&checked)) {
			matched = 1;
		} else {
			_2$$4 = Z_TYPE_P(&checked) == IS_STRING;
			if (_2$$4) {
				ZEPHIR_INIT_VAR(&_3$$4);
				zephir_fast_strtolower(&_3$$4, &checked);
				_2$$4 = ZEPHIR_IS_STRING_IDENTICAL(&_3$$4, "checked");
			}
			if (_2$$4) {
				matched = 1;
			} else {
				zephir_memory_observe(&value);
				_4$$7 = zephir_array_isset_string_fetch(&value, &attributes, SL("value"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_4$$7)) {
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_NULL(&value);
				}
				zephir_read_property_cached(&_5$$7, this_ptr, _zephir_prop_1, 221, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&_5$$7)) {
					matched = ZEPHIR_IS_IDENTICAL(&checked, &value);
				} else {
					_6$$10 = ZEPHIR_IS_EQUAL(&checked, &value);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					matched = _6$$10;
				}
			}
		}
		if (matched) {
			ZEPHIR_INIT_VAR(&_7$$11);
			ZVAL_STRING(&_7$$11, "checked");
			zephir_array_update_string(&attributes, SL("checked"), &_7$$11, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 220, &attributes);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the markup for the optional hidden companion input that lets
 * a checkbox/radio submit a value when unchecked.
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractChecked, processUnchecked)
{
	zend_bool _1;
	zval attributes, _2$$4;
	zval unchecked, _0, _3$$4, _4$$4, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&unchecked);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_2$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 220, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&_0) != IS_ARRAY)) {
		zephir_throw_variable_type_error(&_0, "attributes", "array");
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&attributes, &_0);
	zephir_memory_observe(&unchecked);
	_1 = zephir_array_isset_string_fetch(&unchecked, &attributes, SL("unchecked"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		ZEPHIR_INIT_NVAR(&unchecked);
		ZVAL_STRING(&unchecked, "");
	}
	zephir_array_unset_string(&attributes, SL("unchecked"), PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(ZEPHIR_IS_EMPTY(&unchecked))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 2, 0);
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 220, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_4$$4);
		zephir_array_fetch_string(&_4$$4, &_3$$4, SL("name"), PH_NOISY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 187);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_2$$4, SL("name"), &_4$$4, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_2$$4, SL("value"), &unchecked, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "hidden");
		ZEPHIR_CALL_METHOD_CACHED(&unchecked, this_ptr, "renderTag", &_zephir_call_cache[0], &_5$$4, &_2$$4);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 220, &attributes);
	RETURN_CCTOR(&unchecked);
}

