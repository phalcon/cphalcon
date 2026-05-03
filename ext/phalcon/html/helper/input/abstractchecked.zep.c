
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
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
 * @property array $label
 * @property bool  $strict
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_AbstractChecked)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, AbstractChecked, phalcon, html_helper_input_abstractchecked, phalcon_html_helper_input_abstractinput_ce, phalcon_html_helper_input_abstractchecked_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_helper_input_abstractchecked_ce, SL("label"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_html_helper_input_abstractchecked_ce, SL("strict"), 0, ZEND_ACC_PROTECTED);
	phalcon_html_helper_input_abstractchecked_ce->create_object = zephir_init_properties_Phalcon_Html_Helper_Input_AbstractChecked;

	return SUCCESS;
}

/**
 * @param EscaperInterface $escaper
 * @param Doctype          $doctype
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractChecked, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *escaper, escaper_sub, *doctype = NULL, doctype_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&doctype_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_escaperinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(doctype, phalcon_html_helper_doctype_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &escaper, &doctype);
	if (!doctype) {
		doctype = &doctype_sub;
		doctype = &__$null;
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_html_helper_input_abstractchecked_ce, getThis(), "__construct", NULL, 0, escaper, doctype);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	add_assoc_stringl_ex(&_0, SL("start"), SL(""));
	add_assoc_stringl_ex(&_0, SL("text"), SL(""));
	add_assoc_stringl_ex(&_0, SL("end"), SL(""));
	zephir_update_property_zval(this_ptr, ZEND_STRL("label"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the HTML for the input, optionally surrounded by the label
 * fragment configured via `label()` and preceded by the hidden companion
 * input emitted when an `unchecked` attribute is supplied.
 *
 * @return string
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processchecked", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&unchecked, this_ptr, "processunchecked", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(&element, phalcon_html_helper_input_abstractchecked_ce, getThis(), "__tostring", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("label"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&label, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0);
	add_assoc_stringl_ex(&_1, SL("start"), SL(""));
	add_assoc_stringl_ex(&_1, SL("text"), SL(""));
	add_assoc_stringl_ex(&_1, SL("end"), SL(""));
	zephir_update_property_zval(this_ptr, ZEND_STRL("label"), &_1);
	zephir_array_fetch_string(&_2, &label, SL("start"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 84);
	zephir_array_fetch_string(&_3, &label, SL("text"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 86);
	zephir_array_fetch_string(&_4, &label, SL("end"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 86);
	ZEPHIR_CONCAT_VVVVV(return_value, &unchecked, &_2, &element, &_3, &_4);
	RETURN_MM();
}

/**
 * Attaches a wrapping `<label>` to the element. The supplied attributes
 * are merged with a default `for` pointing at the input's `id`. A `text`
 * pseudo-attribute, if present, becomes the label text and is stripped
 * from the rendered attributes.
 *
 * @param array $attributes
 *
 * @return AbstractChecked
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractChecked, label)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, text, _0, _2, _3, _5, _6;
	zval attributes, _1, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
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
	}
	zephir_array_unset_string(&attributes, SL("text"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_3);
	zephir_array_fetch_string(&_3, &_2, SL("id"), PH_NOISY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 112);
	zephir_array_update_string(&_1, SL("for"), &_3, PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(&_0, &_1, &attributes);
	ZEPHIR_CPY_WRT(&attributes, &_0);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 3, 0);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "label");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "rendertag", NULL, 0, &_6, &attributes);
	zephir_check_call_status();
	zephir_array_update_string(&_4, SL("start"), &_5, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("text"), &text, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_4, SL("end"), SL("</label>"));
	zephir_update_property_zval(this_ptr, ZEND_STRL("label"), &_4);
	RETURN_THIS();
}

/**
 * Toggles strict (`===`) comparison between the `checked` attribute and
 * the `value` attribute when deciding whether to render the input as
 * checked. Defaults to loose (`==`), which matches typical form-input
 * round-tripping where types may differ between the source data and the
 * value rendered into the markup.
 *
 * @param bool $flag
 *
 * @return AbstractChecked
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractChecked, strict)
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&attributes, &_0);
	zephir_memory_observe(&checked);
	if (!(zephir_array_isset_string_fetch(&checked, &attributes, SL("checked"), 0))) {
		ZEPHIR_INIT_NVAR(&checked);
		ZVAL_NULL(&checked);
	}
	zephir_array_unset_string(&attributes, SL("checked"), PH_SEPARATE);
	if (Z_TYPE_P(&checked) != IS_NULL) {
		matched = 0;
		_1$$4 = Z_TYPE_P(&checked) == IS_STRING;
		if (_1$$4) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_fast_strtolower(&_2$$4, &checked);
			_1$$4 = ZEPHIR_IS_STRING_IDENTICAL(&_2$$4, "checked");
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(&checked)) {
			matched = 1;
		} else if (_1$$4) {
			matched = 1;
		} else {
			zephir_memory_observe(&value);
			if (!(zephir_array_isset_string_fetch(&value, &attributes, SL("value"), 0))) {
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_NULL(&value);
			}
			zephir_read_property(&_3$$7, this_ptr, ZEND_STRL("strict"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_3$$7)) {
				matched = ZEPHIR_IS_IDENTICAL(&checked, &value);
			} else {
				matched = ZEPHIR_IS_EQUAL(&checked, &value);
			}
		}
		if (matched) {
			ZEPHIR_INIT_VAR(&_4$$11);
			ZVAL_STRING(&_4$$11, "checked");
			zephir_array_update_string(&attributes, SL("checked"), &_4$$11, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the markup for the optional hidden companion input that lets
 * a checkbox/radio submit a value when unchecked.
 *
 * @return string
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
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
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_3$$4);
		zephir_array_fetch_string(&_3$$4, &_2$$4, SL("name"), PH_NOISY, "phalcon/Html/Helper/Input/AbstractChecked.zep", 211);
		zephir_array_update_string(&_1$$4, SL("name"), &_3$$4, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_1$$4, SL("value"), &unchecked, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "hidden");
		ZEPHIR_CALL_METHOD(&unchecked, this_ptr, "rendertag", NULL, 0, &_4$$4, &_1$$4);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	RETURN_CCTOR(&unchecked);
}

zend_object *zephir_init_properties_Phalcon_Html_Helper_Input_AbstractChecked(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("attributes"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("label"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("label"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

