
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/hash.h"
#include "kernel/string.h"

/**
 * Phalcon\Forms\Element
 *
 * This is a base class for form elements
 */


/**
 * Phalcon\Forms\Element initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Element){

	PHALCON_REGISTER_CLASS(Phalcon\\Forms, Element, forms_element, phalcon_forms_element_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_forms_element_ce, SL("_form"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_element_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_element_ce, SL("_value"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_element_ce, SL("_label"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_element_ce, SL("_attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_element_ce, SL("_validators"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_element_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_element_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_element_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Forms\Element constructor
 *
 * @param string $name
 * @param array $attributes
 */
PHP_METHOD(Phalcon_Forms_Element, __construct){

	zval *name, *attributes = NULL;

	phalcon_fetch_params(0, 1, 1, &name, &attributes);
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_forms_exception_ce, "The element's name must be a string");
		return;
	}

	phalcon_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	if (attributes && Z_TYPE_P(attributes) == IS_ARRAY) {
		phalcon_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	}
}

/**
 * Sets the parent form to the element
 *
 * @param Phalcon\Forms\Form $form
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setForm){

	zval *form;

	phalcon_fetch_params(0, 1, 0, &form);
	
	phalcon_update_property_this(this_ptr, SL("_form"), form TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the parent form to the element
 *
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, getForm){


	RETURN_MEMBER(this_ptr, "_form");
}

/**
 * Sets the element's name
 *
 * @param string $name
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setName){

	zval *name;

	phalcon_fetch_params(0, 1, 0, &name);
	
	phalcon_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the element's name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element, getName){


	RETURN_MEMBER(this_ptr, "_name");
}

/**
 * Sets the element's filters
 *
 * @param array|string $filters
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setFilters){

	zval *filters;

	phalcon_fetch_params(0, 1, 0, &filters);
	
	phalcon_update_property_this(this_ptr, SL("_filters"), filters TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Adds a filter to current list of filters
 *
 * @param string $filter
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, addFilter){

	zval *filter, *filters, *new_filters;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &filter);
	
	PHALCON_OBS_VAR(filters);
	phalcon_read_property_this(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
	if (Z_TYPE_P(filters) == IS_ARRAY) { 
		phalcon_update_property_array_append(this_ptr, SL("_filters"), filter TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(new_filters);
		array_init_size(new_filters, 2);
		if (Z_TYPE_P(filters) == IS_STRING) {
			phalcon_array_append(&new_filters, filters, 0);
		}

		phalcon_array_append(&new_filters, filter, 0);
		phalcon_update_property_this(this_ptr, SL("_filters"), new_filters TSRMLS_CC);
	}
	
	RETURN_THIS();
}

/**
 * Returns the element's filters
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Element, getFilters){


	RETURN_MEMBER(this_ptr, "_filters");
}

/**
 * Adds a group of validators
 *
 * @param Phalcon\Validation\ValidatorInterface[]
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, addValidators){

	zval *validators, *merge = NULL, *current_validators;
	zval *merged_validators = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &validators, &merge);
	
	if (!merge) {
		merge = PHALCON_GLOBAL(z_true);
	}
	
	if (Z_TYPE_P(validators) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The validators parameter must be an array");
		return;
	}

	if (zend_is_true(merge)) {
		current_validators = phalcon_fetch_nproperty_this(this_ptr, SL("_validators"), PH_NOISY_CC);
		if (Z_TYPE_P(current_validators) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_validators);
			phalcon_fast_array_merge(merged_validators, &current_validators, &validators TSRMLS_CC);
		} else {
			merged_validators = validators;
		}
	
		phalcon_update_property_this(this_ptr, SL("_validators"), merged_validators TSRMLS_CC);
	}
	
	RETURN_THIS();
}

/**
 * Adds a validator to the element
 *
 * @param Phalcon\Validation\ValidatorInterface
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, addValidator){

	zval *validator;

	phalcon_fetch_params(0, 1, 0, &validator);
	
	if (Z_TYPE_P(validator) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_forms_exception_ce, "The validators parameter must be an object");
		return;
	}
	phalcon_update_property_array_append(this_ptr, SL("_validators"), validator TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Returns the validators registered for the element
 *
 * @return Phalcon\Validation\ValidatorInterface[]
 */
PHP_METHOD(Phalcon_Forms_Element, getValidators){


	RETURN_MEMBER(this_ptr, "_validators");
}

/**
 * Returns an array of prepared attributes for Phalcon\Tag helpers
 * according to the element's parameters
 *
 * @param array $attributes
 * @param boolean $useChecked
 * @return array
 */
PHP_METHOD(Phalcon_Forms_Element, prepareAttributes){

	zval *attributes = NULL, *use_checked = NULL, *name, *widget_attributes = NULL;
	zval *default_attributes, *merged_attributes = NULL;
	zval *value, *current_value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &attributes, &use_checked);
	
	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}
	
	if (!use_checked) {
		use_checked = PHALCON_GLOBAL(z_false);
	}
	
	name = phalcon_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	
	/** 
	 * Create an array of parameters
	 */
	if (Z_TYPE_P(attributes) != IS_ARRAY) { 
		PHALCON_INIT_VAR(widget_attributes);
		array_init(widget_attributes);
	} else {
		PHALCON_CPY_WRT(widget_attributes, attributes);
	}
	
	phalcon_array_update_long(&widget_attributes, 0, &name, PH_COPY | PH_SEPARATE);
	
	/** 
	 * Merge passed parameters with default ones
	 */
	default_attributes = phalcon_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
	if (Z_TYPE_P(default_attributes) == IS_ARRAY) { 
		PHALCON_INIT_VAR(merged_attributes);
		phalcon_fast_array_merge(merged_attributes, &default_attributes, &widget_attributes TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(merged_attributes, widget_attributes);
	}
	
	/** 
	 * Get the current element's value
	 */
	PHALCON_INIT_VAR(value);
	phalcon_call_method(value, this_ptr, "getvalue");
	
	/** 
	 * If the widget has a value set it as default value
	 */
	if (Z_TYPE_P(value) != IS_NULL) {
		if (zend_is_true(use_checked)) {
	
			/** 
			 * Check if the element already has a default value, compare it with the one in the
			 * attributes, if they are the same mark the element as checked
			 */
			if (phalcon_array_isset_string_fetch(&current_value, merged_attributes, SS("value"))) {
				if (PHALCON_IS_EQUAL(current_value, value)) {
					phalcon_array_update_string_string(&merged_attributes, SL("checked"), SL("checked"), PH_SEPARATE);
				}
			} else {
				/** 
				 * Evaluate the current value and mark the check as checked
				 */
				if (zend_is_true(value)) {
					phalcon_array_update_string_string(&merged_attributes, SL("checked"), SL("checked"), PH_SEPARATE);
				}
				phalcon_array_update_string(&merged_attributes, SL("value"), &value, PH_COPY | PH_SEPARATE);
			}
		} else {
			phalcon_array_update_string(&merged_attributes, SL("value"), &value, PH_COPY | PH_SEPARATE);
		}
	}
	
	RETURN_CTOR(merged_attributes);
}

/**
 * Sets a default attribute for the element
 *
 * @param string $attribute
 * @param mixed $value
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setAttribute){

	zval *attribute, *value;

	phalcon_fetch_params(0, 2, 0, &attribute, &value);
	
	phalcon_update_property_array(this_ptr, SL("_attributes"), attribute, value TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the value of an attribute if present
 *
 * @param string $attribute
 * @param mixed $defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Element, getAttribute){

	zval *attribute, *default_value = NULL, *attributes;
	zval *value;

	phalcon_fetch_params(0, 1, 1, &attribute, &default_value);
	
	if (!default_value) {
		default_value = PHALCON_GLOBAL(z_null);
	}
	
	attributes = phalcon_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
	if (phalcon_array_isset_fetch(&value, attributes, attribute)) {
		RETURN_ZVAL(value, 1, 0);
	}
	
	RETURN_ZVAL(default_value, 1, 0);
}

/**
 * Sets default attributes for the element
 *
 * @param array $attributes
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setAttributes){

	zval *attributes;

	phalcon_fetch_params(0, 1, 0, &attributes);
	
	if (Z_TYPE_P(attributes) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_forms_exception_ce, "Parameter 'attributes' must be an array");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Returns the default attributes for the element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Forms_Element, getAttributes){

	zval *attributes;

	attributes = phalcon_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
	if (Z_TYPE_P(attributes) != IS_ARRAY) { 
		array_init(return_value);
		return;
	}
	
	RETURN_ZVAL(attributes, 1, 0);
}

/**
 * Sets an option for the element
 *
 * @param string $option
 * @param mixed $value
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setUserOption){

	zval *option, *value;

	phalcon_fetch_params(0, 2, 0, &option, &value);
	
	phalcon_update_property_array(this_ptr, SL("_options"), option, value TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the value of an option if present
 *
 * @param string $option
 * @param mixed $defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Element, getUserOption){

	zval *option, *default_value = NULL, *options, *value;

	phalcon_fetch_params(0, 1, 1, &option, &default_value);
	
	if (!default_value) {
		default_value = PHALCON_GLOBAL(z_null);
	}
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (phalcon_array_isset_fetch(&value, options, option)) {
		RETURN_ZVAL(value, 1, 0);
	}
	
	RETURN_ZVAL(default_value, 1, 0);
}

/**
 * Sets options for the element
 *
 * @param array $options
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setUserOptions){

	zval *options;

	phalcon_fetch_params(0, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_forms_exception_ce, "Parameter 'options' must be an array");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Returns the options for the element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Forms_Element, getUserOptions){


	RETURN_MEMBER(this_ptr, "_options");
}

/**
 * Sets the element label
 *
 * @param string $label
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setLabel){

	zval *label;

	phalcon_fetch_params(0, 1, 0, &label);
	
	phalcon_update_property_this(this_ptr, SL("_label"), label TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the element's label
 *
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element, getLabel){


	RETURN_MEMBER(this_ptr, "_label");
}

/**
 * Generate the HTML to label the element
 *
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element, label){

	zval *label, *attributes = NULL, *name = NULL, *html = NULL, *key = NULL, *value = NULL;
	zval *escaped;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &attributes);

	label = phalcon_fetch_nproperty_this(this_ptr, SL("_label"), PH_NOISY_CC);
	
	/** 
	 * Check if there is an 'id' attribute defined
	 */
	if (!attributes || !phalcon_array_isset_string_fetch(&name, attributes, SS("id"))) {
		name = phalcon_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	}

	PHALCON_INIT_VAR(escaped);
	phalcon_htmlspecialchars(escaped, name, NULL, NULL TSRMLS_CC);

	PHALCON_INIT_VAR(html);
	PHALCON_CONCAT_SVS(html, "<label for=\"", escaped, "\"");

	zval_dtor(escaped);
	ZVAL_NULL(escaped);

	if (attributes && Z_TYPE_P(attributes) == IS_ARRAY) {	
		phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0);
		
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(value);
		
			if (Z_TYPE_P(key) != IS_LONG) {
				phalcon_htmlspecialchars(escaped, value, NULL, NULL TSRMLS_CC);
				PHALCON_SCONCAT_SVSVS(html, " ", key, "=\"", escaped, "\"");
				zval_dtor(escaped);
				ZVAL_NULL(escaped);
			}
		
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	}
		
	/** 
	 * Use the default label or leave the same name as label
	 */
	if (zend_is_true(label)) {
		PHALCON_CONCAT_VSVS(return_value, html, ">", label, "</label>");
	} else {
		PHALCON_CONCAT_VSVS(return_value, html, ">", name, "</label>");
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a default value in case the form does not use an entity
 * or there is no value available for the element in $_POST
 *
 * @param mixed $value
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setDefault){

	zval *value;

	phalcon_fetch_params(0, 1, 0, &value);
	
	phalcon_update_property_this(this_ptr, SL("_value"), value TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the default value assigned to the element
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Element, getDefault){


	RETURN_MEMBER(this_ptr, "_value");
}

/**
 * Returns the element's value
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Element, getValue){

	zval *name, *value = NULL, *form, *has_default_value;

	PHALCON_MM_GROW();

	name = phalcon_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(value);
	
	/** 
	 * Get the related form
	 */
	form = phalcon_fetch_nproperty_this(this_ptr, SL("_form"), PH_NOISY_CC);
	if (Z_TYPE_P(form) == IS_OBJECT) {
	
		/** 
		 * Check if the tag has a default value
		 */
		PHALCON_INIT_VAR(has_default_value);
		phalcon_call_static_p1(has_default_value, "phalcon\\tag", "hasvalue", name);
		if (!zend_is_true(has_default_value)) {
			/** 
			 * Gets the possible value for the widget
			 */
			phalcon_call_method_p1(value, form, "getvalue", name);
		}
	}
	
	/** 
	 * Assign the default value if there is no form available
	 */
	if (Z_TYPE_P(value) == IS_NULL) {
		PHALCON_OBS_NVAR(value);
		phalcon_read_property_this(&value, this_ptr, SL("_value"), PH_NOISY_CC);
	}
	
	RETURN_CCTOR(value);
}

/**
 * Returns the messages that belongs to the element
 * The element needs to be attached to a form
 *
 * @return Phalcon\Validation\Message\Group
 */
PHP_METHOD(Phalcon_Forms_Element, getMessages){

	zval *messages;

	PHALCON_MM_GROW();

	/** 
	 * Get the related form
	 */
	messages = phalcon_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) == IS_OBJECT) {
		RETURN_CTOR(messages);
	}
	
	object_init_ex(return_value, phalcon_validation_message_group_ce);
	phalcon_call_method_noret(return_value, "__construct");
	
	phalcon_update_property_this(this_ptr, SL("_messages"), return_value TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks whether there are messages attached to the element
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Element, hasMessages){

	zval *messages;

	/** 
	 * Get the related form
	 */
	messages = phalcon_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) == IS_OBJECT) {
		if (phalcon_fast_count_ev(messages TSRMLS_CC)) {
			RETURN_TRUE;
		}
	}
	
	RETURN_FALSE;
}

/**
 * Sets the validation messages related to the element
 *
 * @param Phalcon\Validation\Message\Group $group
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setMessages){

	zval *group;

	phalcon_fetch_params(0, 1, 0, &group);
	
	if (Z_TYPE_P(group) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_forms_exception_ce, "The message group is not valid");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_messages"), group TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Appends a message to the internal message list
 *
 * @param Phalcon\Validation\Message $message
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, appendMessage){

	zval *message, *messages = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_OBS_VAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) != IS_OBJECT) {
		PHALCON_INIT_NVAR(messages);
		object_init_ex(messages, phalcon_validation_message_group_ce);
		phalcon_call_method_noret(messages, "__construct");
	
		phalcon_update_property_this(this_ptr, SL("_messages"), messages TSRMLS_CC);
	}
	
	phalcon_call_method_p1_noret(messages, "appendmessage", message);
	
	RETURN_THIS();
}

/**
 * Clears every element in the form to its default value
 *
 * @return Phalcon\Forms\Element
 */
PHP_METHOD(Phalcon_Forms_Element, clear){

	zval *name;

	PHALCON_MM_GROW();

	name = phalcon_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	phalcon_call_static_p2_noret("phalcon\\tag", "setdefault", name, PHALCON_GLOBAL(z_null));
	RETURN_THIS();
}

/**
 * Magic method __toString renders the widget without attributes
 *
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element, __toString) {

	if (FAILURE == phalcon_call_method_params(return_value, return_value_ptr, this_ptr, SL("render"), zend_inline_hash_func(SS("render")) TSRMLS_CC, 0)) {
		if (EG(exception) && return_value_ptr) {
			ALLOC_INIT_ZVAL(*return_value_ptr);
		}
	}
}
