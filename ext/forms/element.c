
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
#include "kernel/fcall.h"
#include "kernel/array.h"

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
	zend_declare_property_null(phalcon_forms_element_ce, SL("_label"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_element_ce, SL("_attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_element_ce, SL("_validators"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &name, &attributes) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The element's name must be a string");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);
	if (Z_TYPE_P(attributes) == IS_ARRAY) { 
		phalcon_update_property_zval(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the parent form to the element
 *
 * @param Phalcon\Forms\Form $form
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setForm){

	zval *form;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &form) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_form"), form TSRMLS_CC);
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);
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
 * Adds a group of validators
 *
 * @param Phalcon\Validation\ValidatorInterface[]
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, addValidators){

	zval *validators, *merge = NULL, *current_validators;
	zval *merged_validators = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &validators, &merge) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!merge) {
		PHALCON_INIT_VAR(merge);
		ZVAL_BOOL(merge, 1);
	}
	
	if (Z_TYPE_P(validators) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The validators parameter must be an array");
		return;
	}
	if (zend_is_true(merge)) {
	
		PHALCON_OBS_VAR(current_validators);
		phalcon_read_property(&current_validators, this_ptr, SL("_validators"), PH_NOISY_CC);
		if (Z_TYPE_P(current_validators) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_validators);
			PHALCON_CALL_FUNC_PARAMS_2(merged_validators, "array_merge", current_validators, validators);
		} else {
			PHALCON_CPY_WRT(merged_validators, validators);
		}
	
		phalcon_update_property_zval(this_ptr, SL("_validators"), merged_validators TSRMLS_CC);
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

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &validator) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(validator) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The validators parameter must be an object");
		return;
	}
	phalcon_update_property_array_append(this_ptr, SL("_validators"), validator TSRMLS_CC);
	
	RETURN_THIS();
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
 * Returns an array of attributes for Phalcon\Tag helpers prepared
 * according to the element's parameters
 *
 * @param array $attributes
 * @return array
 */
PHP_METHOD(Phalcon_Forms_Element, prepareAttributes){

	zval *attributes, *name, *widget_attributes = NULL;
	zval *default_attributes, *merged_attributes = NULL;
	zval *form, *has_default_value, *value;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &attributes) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(name);
	phalcon_read_property(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
	/** 
	 * Create an array of parameters
	 */
	if (Z_TYPE_P(attributes) != IS_ARRAY) { 
		PHALCON_INIT_VAR(widget_attributes);
		array_init(widget_attributes);
	} else {
		PHALCON_CPY_WRT(widget_attributes, attributes);
	}
	
	phalcon_array_update_long(&widget_attributes, 0, &name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Merge passed parameters with default ones
	 */
	PHALCON_OBS_VAR(default_attributes);
	phalcon_read_property(&default_attributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	if (Z_TYPE_P(default_attributes) == IS_ARRAY) { 
		PHALCON_INIT_VAR(merged_attributes);
		PHALCON_CALL_FUNC_PARAMS_2(merged_attributes, "array_merge", widget_attributes, default_attributes);
	} else {
		PHALCON_CPY_WRT(merged_attributes, widget_attributes);
	}
	
	/** 
	 * Get the related form
	 */
	PHALCON_OBS_VAR(form);
	phalcon_read_property(&form, this_ptr, SL("_form"), PH_NOISY_CC);
	if (Z_TYPE_P(form) == IS_OBJECT) {
	
		/** 
		 * Check if the tag has a default value
		 */
		PHALCON_INIT_VAR(has_default_value);
		PHALCON_CALL_STATIC_PARAMS_1(has_default_value, "phalcon\\tag", "hasvalue", name);
		if (!zend_is_true(has_default_value)) {
			/** 
			 * Gets the possible value for the widget
			 */
			PHALCON_INIT_VAR(value);
			PHALCON_CALL_METHOD_PARAMS_1(value, form, "getvalue", name);
	
			/** 
			 * If the widget has a value assign it to the attributes
			 */
			phalcon_array_update_string(&merged_attributes, SL("value"), &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	
	RETURN_CCTOR(merged_attributes);
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &attribute, &value) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_array(this_ptr, SL("_attribute"), attribute, value TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Sets default attributes for the element
 *
 * @param array $attributes
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setAttributes){

	zval *attributes;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &attributes) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the default attributes for the element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Forms_Element, getAttributes){


	RETURN_MEMBER(this_ptr, "_attributes");
}

/**
 * Sets the element label
 *
 * @param string $label
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setLabel){

	zval *label;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &label) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_label"), label TSRMLS_CC);
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
 * Magic method __toString renders the widget without atttributes
 *
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element, __toString){

	zval *content;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(content);
	PHALCON_CALL_METHOD(content, this_ptr, "render");
	RETURN_CCTOR(content);
}

