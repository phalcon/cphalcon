
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


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Class Checkbox
 *
 * @property array $label
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Checkbox)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, Checkbox, phalcon, html_helper_input_checkbox, phalcon_html_helper_input_abstractinput_ce, phalcon_html_helper_input_checkbox_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_helper_input_checkbox_ce, SL("label"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_input_checkbox_ce, SL("type"), "checkbox", ZEND_ACC_PROTECTED);
	phalcon_html_helper_input_checkbox_ce->create_object = zephir_init_properties_Phalcon_Html_Helper_Input_Checkbox;

	return SUCCESS;
}

/**
 * AbstractHelper constructor.
 *
 * @param EscaperInterface $escaper
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, __construct)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *escaper, escaper_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_escaperinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &escaper);


	ZEPHIR_CALL_PARENT(NULL, phalcon_html_helper_input_checkbox_ce, getThis(), "__construct", &_0, 0, escaper);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0);
	add_assoc_stringl_ex(&_1, SL("start"), SL(""));
	add_assoc_stringl_ex(&_1, SL("text"), SL(""));
	add_assoc_stringl_ex(&_1, SL("end"), SL(""));
	zephir_update_property_zval(this_ptr, ZEND_STRL("label"), &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the HTML for the input.
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, __toString)
{
	zval _2;
	zval element, label, unchecked, _1, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&unchecked);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processchecked", NULL, 121);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&unchecked, this_ptr, "processunchecked", NULL, 122);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(&element, phalcon_html_helper_input_checkbox_ce, getThis(), "__tostring", &_0, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("label"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&label, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 3, 0);
	add_assoc_stringl_ex(&_2, SL("start"), SL(""));
	add_assoc_stringl_ex(&_2, SL("text"), SL(""));
	add_assoc_stringl_ex(&_2, SL("end"), SL(""));
	zephir_update_property_zval(this_ptr, ZEND_STRL("label"), &_2);
	zephir_array_fetch_string(&_3, &label, SL("start"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Input/Checkbox.zep", 70);
	zephir_array_fetch_string(&_4, &label, SL("text"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Input/Checkbox.zep", 72);
	zephir_array_fetch_string(&_5, &label, SL("end"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Input/Checkbox.zep", 72);
	ZEPHIR_CONCAT_VVVVV(return_value, &unchecked, &_3, &element, &_4, &_5);
	RETURN_MM();
}

/**
 * Attaches a label to the element
 *
 * @param array $attributes
 *
 * @return Checkbox
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, label)
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_OBS_VAR(&text);
	if (!(zephir_array_isset_string_fetch(&text, &attributes, SL("text"), 0))) {
		ZEPHIR_INIT_NVAR(&text);
		ZVAL_STRING(&text, "");
	}
	zephir_array_unset_string(&attributes, SL("text"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_3);
	zephir_array_fetch_string(&_3, &_2, SL("id"), PH_NOISY, "phalcon/Html/Helper/Input/Checkbox.zep", 95);
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
 * Processes the checked value
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, processChecked)
{
	zval attributes;
	zval checked, value, _0, _1$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&checked);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&attributes);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&attributes, &_0);
	ZEPHIR_OBS_VAR(&checked);
	if (!(zephir_array_isset_string_fetch(&checked, &attributes, SL("checked"), 0))) {
		ZEPHIR_INIT_NVAR(&checked);
		ZVAL_STRING(&checked, "");
	}
	zephir_array_unset_string(&attributes, SL("checked"), PH_SEPARATE);
	if (!(ZEPHIR_IS_EMPTY(&checked))) {
		ZEPHIR_OBS_VAR(&value);
		if (!(zephir_array_isset_string_fetch(&value, &attributes, SL("value"), 0))) {
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_STRING(&value, "");
		}
		if (ZEPHIR_IS_IDENTICAL(&checked, &value)) {
			ZEPHIR_INIT_VAR(&_1$$6);
			ZVAL_STRING(&_1$$6, "checked");
			zephir_array_update_string(&attributes, SL("checked"), &_1$$6, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the unchecked hidden element if available
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, processUnchecked)
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


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&attributes, &_0);
	ZEPHIR_OBS_VAR(&unchecked);
	if (!(zephir_array_isset_string_fetch(&unchecked, &attributes, SL("unchecked"), 0))) {
		ZEPHIR_INIT_NVAR(&unchecked);
		ZVAL_STRING(&unchecked, "");
	}
	zephir_array_unset_string(&attributes, SL("unchecked"), PH_SEPARATE);
	if (!(ZEPHIR_IS_EMPTY(&unchecked))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 2, 0);
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_3$$4);
		zephir_array_fetch_string(&_3$$4, &_2$$4, SL("name"), PH_NOISY, "phalcon/Html/Helper/Input/Checkbox.zep", 156);
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

zend_object *zephir_init_properties_Phalcon_Html_Helper_Input_Checkbox(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
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

