
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
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/file.h"

/**
 * Phalcon\Forms\Form
 *
 * This component allows to build forms using an object-oriented interface
 */


/**
 * Phalcon\Forms\Form initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Form){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Forms, Form, forms_form, "phalcon\\di\\injectable", phalcon_forms_form_method_entry, 0);

	zend_declare_property_null(phalcon_forms_form_ce, SL("_position"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_entity"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_elements"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_elementsIndexed"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_forms_form_ce TSRMLS_CC, 2, spl_ce_Countable, zend_ce_iterator);

	return SUCCESS;
}

/**
 * Phalcon\Forms\Form constructor
 *
 * @param object $entity
 * @param array $userOptions
 */
PHP_METHOD(Phalcon_Forms_Form, __construct){

	zval *entity = NULL, *user_options = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &entity, &user_options);
	
	if (!entity) {
		PHALCON_INIT_VAR(entity);
	}
	
	if (!user_options) {
		PHALCON_INIT_VAR(user_options);
	}
	
	if (Z_TYPE_P(entity) != IS_NULL) {
		if (Z_TYPE_P(entity) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The base entity is not valid");
			return;
		}
		phalcon_update_property_this(this_ptr, SL("_entity"), entity TSRMLS_CC);
	}
	
	/** 
	 * Update the user options
	 */
	if (Z_TYPE_P(user_options) == IS_ARRAY) { 
		phalcon_update_property_this(this_ptr, SL("_options"), user_options TSRMLS_CC);
	}
	
	/** 
	 * Check for an 'initialize' method and call it
	 */
	if (phalcon_method_exists_ex(this_ptr, SS("initialize") TSRMLS_CC) == SUCCESS) {
		phalcon_call_method_p2_noret(this_ptr, "initialize", entity, user_options);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the form's action
 *
 * @param string $action
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, setAction){

	zval *action;

	phalcon_fetch_params(0, 1, 0, &action);
	
	phalcon_update_property_this(this_ptr, SL("_action"), action TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the form's action
 *
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Form, getAction){


	RETURN_MEMBER(this_ptr, "_action");
}

/**
 * Sets an option for the form
 *
 * @param string $option
 * @param mixed $value
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, setUserOption){

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
PHP_METHOD(Phalcon_Forms_Form, getUserOption){

	zval *option, *default_value = NULL, *options, *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &option, &default_value);
	
	if (!default_value) {
		PHALCON_INIT_VAR(default_value);
	}
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (phalcon_array_isset(options, option)) {
		PHALCON_OBS_VAR(value);
		phalcon_array_fetch(&value, options, option, PH_NOISY_CC);
		RETURN_CCTOR(value);
	}
	
	RETURN_CCTOR(default_value);
}

/**
 * Sets options for the element
 *
 * @param array $options
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Form, setUserOptions){

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
PHP_METHOD(Phalcon_Forms_Form, getUserOptions){


	RETURN_MEMBER(this_ptr, "_options");
}

/**
 * Sets the entity related to the model
 *
 * @param object $entity
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, setEntity){

	zval *entity;

	phalcon_fetch_params(0, 1, 0, &entity);
	
	phalcon_update_property_this(this_ptr, SL("_entity"), entity TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the entity related to the model
 *
 * @return object
 */
PHP_METHOD(Phalcon_Forms_Form, getEntity){


	RETURN_MEMBER(this_ptr, "_entity");
}

/**
 * Returns the form elements added to the form
 *
 * @return Phalcon\Forms\ElementInterface[]
 */
PHP_METHOD(Phalcon_Forms_Form, getElements){


	RETURN_MEMBER(this_ptr, "_elements");
}

/**
 * Binds data to the entity
 *
 * @param array $data
 * @param object $entity
 * @param array $whitelist
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, bind){

	zval *data, *entity, *whitelist = NULL, *elements, *filter = NULL;
	zval *value = NULL, *key = NULL, *element = NULL, *filters = NULL, *service_name = NULL;
	zval *dependency_injector = NULL, *filtered_value = NULL;
	zval *method = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &data, &entity, &whitelist);
	
	if (!whitelist) {
		PHALCON_INIT_VAR(whitelist);
	}
	
	/** 
	 * The data must be an array
	 */
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The data must be an array");
		return;
	}
	
	PHALCON_OBS_VAR(elements);
	phalcon_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (Z_TYPE_P(elements) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "There are no elements in the form");
		return;
	}
	
	PHALCON_INIT_VAR(filter);
	
	phalcon_is_iterable(data, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);
	
		if (!phalcon_array_isset(elements, key)) {
			zend_hash_move_forward_ex(ah0, &hp0);
			continue;
		}
	
		/** 
		 * Check if the item is in the whitelist
		 */
		if (Z_TYPE_P(whitelist) == IS_ARRAY) { 
			if (!phalcon_fast_in_array(key, whitelist TSRMLS_CC)) {
				zend_hash_move_forward_ex(ah0, &hp0);
				continue;
			}
		}
	
		/** 
		 * Get the element
		 */
		PHALCON_OBS_NVAR(element);
		phalcon_array_fetch(&element, elements, key, PH_NOISY_CC);
	
		/** 
		 * Check if the method has filters
		 */
		PHALCON_INIT_NVAR(filters);
		phalcon_call_method(filters, element, "getfilters");
		if (zend_is_true(filters)) {
			if (Z_TYPE_P(filter) != IS_OBJECT) {
				PHALCON_INIT_NVAR(service_name);
				ZVAL_STRING(service_name, "filter", 1);
	
				PHALCON_INIT_NVAR(dependency_injector);
				phalcon_call_method(dependency_injector, this_ptr, "getdi");
	
				PHALCON_INIT_NVAR(filter);
				phalcon_call_method_p1(filter, dependency_injector, "getshared", service_name);
			}
	
			/** 
			 * Sanitize the filters
			 */
			PHALCON_INIT_NVAR(filtered_value);
			phalcon_call_method_p2(filtered_value, filter, "sanitize", value, filters);
		} else {
			PHALCON_CPY_WRT(filtered_value, value);
		}
	
		PHALCON_INIT_NVAR(method);
		PHALCON_CONCAT_SV(method, "set", key);
	
		/** 
		 * Use the setter if any available
		 */
		if (phalcon_method_exists(entity, method TSRMLS_CC) == SUCCESS) {
			phalcon_call_method_zval_p1_noret(entity, method, filtered_value);
			zend_hash_move_forward_ex(ah0, &hp0);
			continue;
		}
	
		/** 
		 * Use the public property if it doesn't have a setter
		 */
		phalcon_update_property_zval_zval(entity, key, filtered_value TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Validates the form
 *
 * @param array $data
 * @param object $entity
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Form, isValid){

	zval *data = NULL, *entity = NULL, *elements, *status, *not_failed = NULL;
	zval *messages, *element = NULL, *validators = NULL, *name = NULL, *prepared_validators = NULL;
	zval *validator = NULL, *scope = NULL, *validation = NULL, *filters = NULL;
	zval *element_messages = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &data, &entity);
	
	if (!data) {
		PHALCON_INIT_VAR(data);
	} else {
		PHALCON_SEPARATE_PARAM(data);
	}
	
	if (!entity) {
		PHALCON_INIT_VAR(entity);
	}
	
	PHALCON_OBS_VAR(elements);
	phalcon_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (Z_TYPE_P(elements) != IS_ARRAY) { 
		RETURN_MM_TRUE;
	}
	
	/** 
	 * If the user doesn't pass an entity we use the one in this_ptr->_entity
	 */
	if (Z_TYPE_P(entity) == IS_OBJECT) {
		phalcon_call_method_p2_noret(this_ptr, "bind", data, entity);
	}
	
	/** 
	 * If the data is not an array use the one passed previously
	 */
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_OBS_NVAR(data);
		phalcon_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	}
	
	/** 
	 * Check if there is a method 'beforeValidation'
	 */
	if (phalcon_method_exists_ex(this_ptr, SS("beforevalidation") TSRMLS_CC) == SUCCESS) {
	
		PHALCON_INIT_VAR(status);
		phalcon_call_method_p2(status, this_ptr, "beforevalidation", data, entity);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_CCTOR(status);
		}
	}
	
	PHALCON_INIT_VAR(not_failed);
	ZVAL_BOOL(not_failed, 1);
	
	PHALCON_INIT_VAR(messages);
	array_init(messages);
	
	phalcon_is_iterable(elements, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(element);
	
		PHALCON_INIT_NVAR(validators);
		phalcon_call_method(validators, element, "getvalidators");
		if (Z_TYPE_P(validators) == IS_ARRAY) { 
			if (phalcon_fast_count_ev(validators TSRMLS_CC)) {
	
				/** 
				 * Element's name
				 */
				PHALCON_INIT_NVAR(name);
				phalcon_call_method(name, element, "getname");
	
				/** 
				 * Prepare the validators
				 */
				PHALCON_INIT_NVAR(prepared_validators);
				array_init(prepared_validators);
	
				phalcon_is_iterable(validators, &ah1, &hp1, 0, 0);
	
				while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
					PHALCON_GET_HVALUE(validator);
	
					PHALCON_INIT_NVAR(scope);
					array_init_size(scope, 2);
					phalcon_array_append(&scope, name, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&scope, validator, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&prepared_validators, scope, PH_SEPARATE TSRMLS_CC);
	
					zend_hash_move_forward_ex(ah1, &hp1);
				}
	
				/** 
				 * Create an implicit validation
				 */
				PHALCON_INIT_NVAR(validation);
				object_init_ex(validation, phalcon_validation_ce);
				phalcon_call_method_p1_noret(validation, "__construct", prepared_validators);
	
				/** 
				 * Get filters in the element
				 */
				PHALCON_INIT_NVAR(filters);
				phalcon_call_method(filters, element, "getfilters");
	
				/** 
				 * Assign the filters to the validation
				 */
				if (Z_TYPE_P(filters) == IS_ARRAY) { 
					PHALCON_INIT_NVAR(name);
					phalcon_call_method(name, element, "getname");
					phalcon_call_method_p2_noret(validation, "setfilters", name, filters);
				}
	
				/** 
				 * Perform the validation
				 */
				PHALCON_INIT_NVAR(element_messages);
				phalcon_call_method_p2(element_messages, validation, "validate", data, entity);
				if (phalcon_fast_count_ev(element_messages TSRMLS_CC)) {
					PHALCON_INIT_NVAR(name);
					phalcon_call_method(name, element, "getname");
					phalcon_array_update_zval(&messages, name, &element_messages, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
					PHALCON_INIT_NVAR(not_failed);
					ZVAL_BOOL(not_failed, 0);
				}
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * If the validation fails update the messages
	 */
	if (!zend_is_true(not_failed)) {
		phalcon_update_property_this(this_ptr, SL("_messages"), messages TSRMLS_CC);
	}
	
	/** 
	 * Check if there is a method 'afterValidation'
	 */
	if (phalcon_method_exists_ex(this_ptr, SS("aftervalidation") TSRMLS_CC) == SUCCESS) {
		phalcon_call_method_p1_noret(this_ptr, "aftervalidation", messages);
	}
	
	/** 
	 * Return the validation status
	 */
	
	RETURN_NCTOR(not_failed);
}

/**
 * Returns the messages generated in the validation
 *
 * @param boolean $byItemName
 * @return array
 */
PHP_METHOD(Phalcon_Forms_Form, getMessages){

	zval *by_item_name = NULL, *messages, *group = NULL, *element_messages = NULL;
	zval *element = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &by_item_name);
	
	if (!by_item_name) {
		PHALCON_INIT_VAR(by_item_name);
		ZVAL_BOOL(by_item_name, 0);
	}
	
	PHALCON_OBS_VAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (zend_is_true(by_item_name)) {
		if (Z_TYPE_P(messages) != IS_ARRAY) { 
			PHALCON_INIT_VAR(group);
			object_init_ex(group, phalcon_validation_message_group_ce);
			phalcon_call_method_noret(group, "__construct");
	
			RETURN_CTOR(group);
		}
	
		RETURN_CCTOR(messages);
	}
	
	PHALCON_INIT_NVAR(group);
	object_init_ex(group, phalcon_validation_message_group_ce);
	phalcon_call_method_noret(group, "__construct");
	
	phalcon_is_iterable(messages, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(element, ah0, hp0);
		PHALCON_GET_HVALUE(element_messages);
	
		phalcon_call_method_p1_noret(group, "appendmessages", element_messages);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_CTOR(group);
}

/**
 * Returns the messages generated for a specific element
 *
 * @return Phalcon\Validation\Message\Group[]
 */
PHP_METHOD(Phalcon_Forms_Form, getMessagesFor){

	zval *name, *messages, *element_messages, *group;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (phalcon_array_isset(messages, name)) {
		PHALCON_OBS_VAR(element_messages);
		phalcon_array_fetch(&element_messages, messages, name, PH_NOISY_CC);
		RETURN_CCTOR(element_messages);
	}
	
	PHALCON_INIT_VAR(group);
	object_init_ex(group, phalcon_validation_message_group_ce);
	phalcon_call_method_noret(group, "__construct");
	
	phalcon_update_property_array(this_ptr, SL("_messages"), name, group TSRMLS_CC);
	
	RETURN_CTOR(group);
}

/**
 * Check if messages were generated for a specific element
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Form, hasMessagesFor){

	zval *name, *messages, *element_messages;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (phalcon_array_isset(messages, name)) {
		PHALCON_OBS_VAR(element_messages);
		phalcon_array_fetch(&element_messages, messages, name, PH_NOISY_CC);
		RETURN_CCTOR(element_messages);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Adds an element to the form
 *
 * @param Phalcon\Forms\ElementInterface $element
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, add){

	zval *element, *name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &element);
	
	if (Z_TYPE_P(element) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The element is not valid");
		return;
	}
	
	/** 
	 * Gets the element's name
	 */
	PHALCON_INIT_VAR(name);
	phalcon_call_method(name, element, "getname");
	
	/** 
	 * Link the element to the form
	 */
	phalcon_call_method_p1_noret(element, "setform", this_ptr);
	
	/** 
	 * Append the element by its name
	 */
	phalcon_update_property_array(this_ptr, SL("_elements"), name, element TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Renders a specific item in the form
 *
 * @param string $name
 * @param array $attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Form, render){

	zval *name, *attributes = NULL, *elements, *exception_message;
	zval *element, *code;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &name, &attributes);
	
	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The name must be a string");
		return;
	}
	
	PHALCON_OBS_VAR(elements);
	phalcon_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (!phalcon_array_isset(elements, name)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Element with ID=", name, " is not part of the form");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_forms_exception_ce, exception_message);
		return;
	}
	
	PHALCON_OBS_VAR(element);
	phalcon_array_fetch(&element, elements, name, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(code);
	phalcon_call_method_p1(code, element, "render", attributes);
	
	RETURN_CCTOR(code);
}

/**
 * Returns an element added to the form by its name
 *
 * @param string $name
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Form, get){

	zval *name, *elements, *exception_message, *element;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(elements);
	phalcon_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (!phalcon_array_isset(elements, name)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Element with ID=", name, " is not part of the form");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_forms_exception_ce, exception_message);
		return;
	}
	
	PHALCON_OBS_VAR(element);
	phalcon_array_fetch(&element, elements, name, PH_NOISY_CC);
	
	RETURN_CCTOR(element);
}

/**
 * Generate the label of a element added to the form including HTML
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Form, label){

	zval *name, *elements, *exception_message, *element;
	zval *html;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(elements);
	phalcon_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (!phalcon_array_isset(elements, name)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Element with ID=", name, " is not part of the form");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_forms_exception_ce, exception_message);
		return;
	}
	
	PHALCON_OBS_VAR(element);
	phalcon_array_fetch(&element, elements, name, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(html);
	phalcon_call_method(html, element, "label");
	
	RETURN_CCTOR(html);
}

/**
 * Returns a label for an element
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Form, getLabel){

	zval *name, *elements, *exception_message, *element;
	zval *label;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(elements);
	phalcon_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (!phalcon_array_isset(elements, name)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Element with ID=", name, " is not part of the form");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_forms_exception_ce, exception_message);
		return;
	}
	
	PHALCON_OBS_VAR(element);
	phalcon_array_fetch(&element, elements, name, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(label);
	phalcon_call_method(label, element, "getlabel");
	
	/** 
	 * Use the element's name as label if the label is not available
	 */
	if (!zend_is_true(label)) {
		RETURN_CCTOR(name);
	}
	
	RETURN_CCTOR(label);
}

/**
 * Gets a value from the internal related entity or from the default value
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Form, getValue){

	zval *name, *entity, *method, *value = NULL, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(entity);
	phalcon_read_property_this(&entity, this_ptr, SL("_entity"), PH_NOISY_CC);
	if (Z_TYPE_P(entity) == IS_OBJECT) {
	
		/** 
		 * Check if the entity has a getter
		 */
		PHALCON_INIT_VAR(method);
		PHALCON_CONCAT_SV(method, "get", name);
		if (phalcon_method_exists(entity, method TSRMLS_CC) == SUCCESS) {
			PHALCON_INIT_VAR(value);
			phalcon_call_method_zval(value, entity, method);
			RETURN_CCTOR(value);
		}
	
		/** 
		 * Check if the entity has a public property
		 */
		if (phalcon_isset_property_zval(entity, name TSRMLS_CC)) {
			PHALCON_OBS_NVAR(value);
			phalcon_read_property_zval(&value, entity, name, PH_NOISY_CC);
			RETURN_CCTOR(value);
		}
	}
	
	PHALCON_OBS_VAR(data);
	phalcon_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (Z_TYPE_P(data) == IS_ARRAY) { 
	
		/** 
		 * Check if the data is in the data array
		 */
		if (phalcon_array_isset(data, name)) {
			PHALCON_OBS_NVAR(value);
			phalcon_array_fetch(&value, data, name, PH_NOISY_CC);
			RETURN_CCTOR(value);
		}
	}
	
	RETURN_MM_NULL();
}

/**
 * Check if the form contains an element
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Form, has){

	zval *name, *elements;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(elements);
	phalcon_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	
	/** 
	 * Checks if the element is in the form
	 */
	if (phalcon_array_isset(elements, name)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Removes an element from the form
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Form, remove){

	zval *name, *elements;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(elements);
	phalcon_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	
	/** 
	 * Checks if the element is in the form
	 */
	if (phalcon_array_isset(elements, name)) {
		phalcon_unset_property_array(this_ptr, SL("_elements"), name TSRMLS_CC);
		RETURN_MM_TRUE;
	}
	
	/** 
	 * Clean the iterator index
	 */
	phalcon_update_property_null(this_ptr, SL("_elementsIndexed") TSRMLS_CC);
	RETURN_MM_FALSE;
}

/**
 * Clears every element in the form to its default value
 *
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, clear){

	zval *elements, *element = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(elements);
	phalcon_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (Z_TYPE_P(elements) == IS_ARRAY) { 
	
		phalcon_is_iterable(elements, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(element);
	
			phalcon_call_method_noret(element, "clear");
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	RETURN_THIS();
}

/**
 * Returns the number of elements in the form
 *
 * @return int
 */
PHP_METHOD(Phalcon_Forms_Form, count){

	zval *elements, *number;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(elements);
	phalcon_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number);
	phalcon_fast_count(number, elements TSRMLS_CC);
	RETURN_NCTOR(number);
}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Forms_Form, rewind){

	zval *elements, *elements_indexed;

	PHALCON_MM_GROW();

	phalcon_update_property_long(this_ptr, SL("_position"), 0 TSRMLS_CC);
	
	PHALCON_OBS_VAR(elements);
	phalcon_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(elements_indexed);
	phalcon_call_func_p1(elements_indexed, "array_values", elements);
	phalcon_update_property_this(this_ptr, SL("_elementsIndexed"), elements_indexed TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the current element in the iterator
 *
 * @return Phalcon\Validation\Message
 */
PHP_METHOD(Phalcon_Forms_Form, current){

	zval *position, *elements, *element;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(position);
	phalcon_read_property_this(&position, this_ptr, SL("_position"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(elements);
	phalcon_read_property_this(&elements, this_ptr, SL("_elementsIndexed"), PH_NOISY_CC);
	if (phalcon_array_isset(elements, position)) {
		PHALCON_OBS_VAR(element);
		phalcon_array_fetch(&element, elements, position, PH_NOISY_CC);
		RETURN_CCTOR(element);
	}
	
	RETURN_MM_NULL();
}

/**
 * Returns the current position/key in the iterator
 *
 * @return int
 */
PHP_METHOD(Phalcon_Forms_Form, key){


	RETURN_MEMBER(this_ptr, "_position");
}

/**
 * Moves the internal iteration pointer to the next position
 *
 */
PHP_METHOD(Phalcon_Forms_Form, next){


	phalcon_property_incr(this_ptr, SL("_position") TSRMLS_CC);
	
}

/**
 * Check if the current element in the iterator is valid
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Form, valid){

	zval *position, *elements;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(position);
	phalcon_read_property_this(&position, this_ptr, SL("_position"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(elements);
	phalcon_read_property_this(&elements, this_ptr, SL("_elementsIndexed"), PH_NOISY_CC);
	if (phalcon_array_isset(elements, position)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

