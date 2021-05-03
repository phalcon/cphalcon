
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
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This is a base class for form elements
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_AbstractElement)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Forms\\Element, AbstractElement, phalcon, forms_element_abstractelement, phalcon_forms_element_abstractelement_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("attributes"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("filters"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("form"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("label"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("messages"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("name"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("options"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("validators"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("value"), ZEND_ACC_PROTECTED);
	phalcon_forms_element_abstractelement_ce->create_object = zephir_init_properties_Phalcon_Forms_Element_AbstractElement;

	zend_class_implements(phalcon_forms_element_abstractelement_ce, 1, phalcon_forms_element_elementinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Forms\Element constructor
 *
 * @param string name       Attribute name (value of 'name' attribute of HTML element)
 * @param array  attributes Additional HTML element attributes
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *name_param = NULL, *attributes_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &attributes_param);
	zephir_get_strval(&name, name_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_trim(&_0, &name, NULL , ZEPHIR_TRIM_BOTH);
	zephir_get_strval(&name, &_0);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&name))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Form element name is required", "phalcon/Forms/Element/AbstractElement.zep", 54);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_messages_messages_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 9);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic method __toString renders the widget without attributes
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, __toString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a filter to current list of filters
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, addFilter)
{
	zval _1$$5, _2$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *filter_param = NULL, filters, _0;
	zval filter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filter)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filter_param);
	zephir_get_strval(&filter, filter_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&filters, &_0);
	if (Z_TYPE_P(&filters) == IS_ARRAY) {
		zephir_update_property_array_append(this_ptr, SL("filters"), &filter);
	} else {
		if (Z_TYPE_P(&filters) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_1$$5);
			zephir_create_array(&_1$$5, 2, 0);
			zephir_array_fast_append(&_1$$5, &filters);
			zephir_array_fast_append(&_1$$5, &filter);
			zephir_update_property_zval(this_ptr, ZEND_STRL("filters"), &_1$$5);
		} else {
			ZEPHIR_INIT_VAR(&_2$$6);
			zephir_create_array(&_2$$6, 1, 0);
			zephir_array_fast_append(&_2$$6, &filter);
			zephir_update_property_zval(this_ptr, ZEND_STRL("filters"), &_2$$6);
		}
	}
	RETURN_THIS();
}

/**
 * Adds a validator to the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, addValidator)
{
	zval *validator, validator_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validator_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(validator, phalcon_validation_validatorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &validator);


	zephir_update_property_array_append(this_ptr, SL("validators"), validator);
	RETURN_THISW();
}

/**
 * Adds a group of validators
 *
 * @param \Phalcon\Validation\ValidatorInterface[] validators
 * @param bool                                     merge
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, addValidators)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge;
	zval *validators_param = NULL, *merge_param = NULL, _0$$3, _1$$3;
	zval validators;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(validators)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &validators_param, &merge_param);
	ZEPHIR_OBS_COPY_OR_DUP(&validators, validators_param);
	if (!merge_param) {
		merge = 1;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("validators"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, &validators);
		ZEPHIR_CPY_WRT(&validators, &_0$$3);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("validators"), &validators);
	RETURN_THIS();
}

/**
 * Appends a message to the internal message list
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, appendMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_messages_messageinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "appendmessage", NULL, 0, message);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Clears element to its default value
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, clear)
{
	zval form, _0, name, value;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&form);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("form"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&form, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("value"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&value, &_0);
	if (Z_TYPE_P(&form) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, &form, "clear", NULL, 0, &name);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_tag_ce, "setdefault", &_1, 0, &name, &value);
		zephir_check_call_status();
	}
	RETURN_THIS();
}

/**
 * Returns the value of an attribute if present
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attribute_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, attributes, value, _0;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(attribute)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &attribute_param, &defaultValue);
	zephir_get_strval(&attribute, attribute_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&attributes, &_0);
	if (!(zephir_array_isset_fetch(&value, &attributes, &attribute, 1))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CTOR(&value);
}

/**
 * Returns the default attributes for the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getAttributes)
{
	zval attributes, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&attributes, &_0);
	RETURN_CCTOR(&attributes);
}

/**
 * Returns the default value assigned to the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getDefault)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "value");
}

/**
 * Returns the element filters
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getFilters)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "filters");
}

/**
 * Returns the parent form to the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getForm)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "form");
}

/**
 * Returns the element label
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getLabel)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "label");
}

/**
 * Returns the messages that belongs to the element
 * The element needs to be attached to a form
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getMessages)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "messages");
}

/**
 * Returns the element name
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "name");
}

/**
 * Returns the value of an option if present
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getUserOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *option_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(option)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &option_param, &defaultValue);
	zephir_get_strval(&option, option_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&value, &_0, &option, 1))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CTOR(&value);
}

/**
 * Returns the options for the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getUserOptions)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "options");
}

/**
 * Returns the validators registered for the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getValidators)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "validators");
}

/**
 * Returns the element's value
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getValue)
{
	zval name, _0, form, value, _1, _4$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&form);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$5);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("form"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&form, &_0);
	ZEPHIR_INIT_VAR(&value);
	ZVAL_NULL(&value);
	if (Z_TYPE_P(&form) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(&form, "getvalue", NULL, 0, &name);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_tag_ce, "hasvalue", &_2, 0, &name);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_CE_STATIC(&value, phalcon_tag_ce, "getvalue", &_3, 0, &name);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&value) == IS_NULL) {
		zephir_read_property(&_4$$5, this_ptr, ZEND_STRL("value"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&value, &_4$$5);
	}
	RETURN_CCTOR(&value);
}

/**
 * Checks whether there are messages attached to the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, hasMessages)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_fast_count_int(&_0) > 0);
}

/**
 * Generate the HTML to label the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, label)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, internalAttributes, label, name, code, _2, _3, _0$$3, _5$$5, _6$$6;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&internalAttributes);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
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


	ZEPHIR_CALL_METHOD(&internalAttributes, this_ptr, "getattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&name);
	if (!(zephir_array_isset_string_fetch(&name, &internalAttributes, SL("id"), 0))) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&name, &_0$$3);
	}
	if (!(zephir_array_isset_string(&attributes, SL("for")))) {
		zephir_array_update_string(&attributes, SL("for"), &name, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "<label");
	ZEPHIR_CALL_CE_STATIC(&code, phalcon_tag_ce, "renderattributes", &_1, 0, &_2, &attributes);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("label"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&label, &_3);
	_4 = zephir_is_true(&label);
	if (!(_4)) {
		_4 = zephir_is_numeric(&label);
	}
	if (_4) {
		ZEPHIR_INIT_VAR(&_5$$5);
		ZEPHIR_CONCAT_SVS(&_5$$5, ">", &label, "</label>");
		zephir_concat_self(&code, &_5$$5);
	} else {
		ZEPHIR_INIT_VAR(&_6$$6);
		ZEPHIR_CONCAT_SVS(&_6$$6, ">", &name, "</label>");
		zephir_concat_self(&code, &_6$$6);
	}
	RETURN_CCTOR(&code);
}

/**
 * Returns an array of prepared attributes for Phalcon\Tag helpers
 * according to the element parameters
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, prepareAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useChecked;
	zval *attributes_param = NULL, *useChecked_param = NULL, value, name, mergedAttributes, defaultAttributes, currentValue, _0, _1$$6, _2$$8;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&mergedAttributes);
	ZVAL_UNDEF(&defaultAttributes);
	ZVAL_UNDEF(&currentValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
		Z_PARAM_BOOL(useChecked)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &attributes_param, &useChecked_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!useChecked_param) {
		useChecked = 0;
	} else {
		useChecked = zephir_get_boolval(useChecked_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_0);
	zephir_array_update_long(&attributes, 0, &name, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_OBS_VAR(&defaultAttributes);
	zephir_read_property(&defaultAttributes, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&mergedAttributes);
	zephir_fast_array_merge(&mergedAttributes, &defaultAttributes, &attributes);
	ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&value) != IS_NULL) {
		if (useChecked) {
			if (zephir_array_isset_string_fetch(&currentValue, &mergedAttributes, SL("value"), 1)) {
				if (ZEPHIR_IS_EQUAL(&currentValue, &value)) {
					ZEPHIR_INIT_VAR(&_1$$6);
					ZVAL_STRING(&_1$$6, "checked");
					zephir_array_update_string(&mergedAttributes, SL("checked"), &_1$$6, PH_COPY | PH_SEPARATE);
				}
			} else {
				if (zephir_is_true(&value)) {
					ZEPHIR_INIT_VAR(&_2$$8);
					ZVAL_STRING(&_2$$8, "checked");
					zephir_array_update_string(&mergedAttributes, SL("checked"), &_2$$8, PH_COPY | PH_SEPARATE);
				}
				zephir_array_update_string(&mergedAttributes, SL("value"), &value, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_update_string(&mergedAttributes, SL("value"), &value, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(&mergedAttributes);
}

/**
 * Sets a default attribute for the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attribute_param = NULL, *value, value_sub;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(attribute)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);
	zephir_get_strval(&attribute, attribute_param);


	zephir_update_property_array(this_ptr, SL("attributes"), &attribute, value);
	RETURN_THIS();
}

/**
 * Sets default attributes for the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attributes_param = NULL;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	RETURN_THIS();
}

/**
 * Sets a default value in case the form does not use an entity
 * or there is no value available for the element in _POST
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setDefault)
{
	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &value);


	zephir_update_property_zval(this_ptr, ZEND_STRL("value"), value);
	RETURN_THISW();
}

/**
 * Sets the element filters
 *
 * @param array|string filters
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setFilters)
{
	zend_bool _0;
	zval *filters, filters_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(filters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &filters);


	_0 = Z_TYPE_P(filters) != IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(filters) != IS_ARRAY;
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_forms_exception_ce, "Wrong filter type added", "phalcon/Forms/Element/AbstractElement.zep", 435);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("filters"), filters);
	RETURN_THISW();
}

/**
 * Sets the parent form to the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setForm)
{
	zval *form, form_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&form_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(form, phalcon_forms_form_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &form);


	zephir_update_property_zval(this_ptr, ZEND_STRL("form"), form);
	RETURN_THISW();
}

/**
 * Sets the element label
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setLabel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *label_param = NULL;
	zval label;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&label);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(label)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &label_param);
	zephir_get_strval(&label, label_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("label"), &label);
	RETURN_THIS();
}

/**
 * Sets the validation messages related to the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setMessages)
{
	zval *messages, messages_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(messages, phalcon_messages_messages_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &messages);


	zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), messages);
	RETURN_THISW();
}

/**
 * Sets the element name
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	RETURN_THIS();
}

/**
 * Sets an option for the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setUserOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *option_param = NULL, *value, value_sub;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(option)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &option_param, &value);
	zephir_get_strval(&option, option_param);


	zephir_update_property_array(this_ptr, SL("options"), &option, value);
	RETURN_THIS();
}

/**
 * Sets options for the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setUserOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	RETURN_THIS();
}

zend_object *zephir_init_properties_Phalcon_Forms_Element_AbstractElement(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("validators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("validators"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

