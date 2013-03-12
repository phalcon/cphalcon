
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
#include "kernel/file.h"
#include "kernel/array.h"
#include "kernel/concat.h"

/**
 * Phalcon\Forms\Form
 *
 * This component allows to build forms
 */


/**
 * Phalcon\Forms\Form initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Form){

	PHALCON_REGISTER_CLASS(Phalcon\\Forms, Form, forms_form, phalcon_forms_form_method_entry, 0);

	zend_declare_property_null(phalcon_forms_form_ce, SL("_entity"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_elements"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Forms\Form constructor
 *
 * @param boolean $entity
 */
PHP_METHOD(Phalcon_Forms_Form, __construct){

	zval *entity = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &entity) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!entity) {
		PHALCON_INIT_VAR(entity);
	}
	
	if (Z_TYPE_P(entity) != IS_NULL) {
		if (Z_TYPE_P(entity) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The base entity is not valid");
			return;
		}
		phalcon_update_property_zval(this_ptr, SL("_entity"), entity TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 *
 * @param array|object $data
 * @param object $entity
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Form, isValid){

	zval *data = NULL, *entity = NULL, *elements, *failed = NULL, *messages;
	zval *element = NULL, *validators = NULL, *validation = NULL, *element_messages = NULL;
	zval *name = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &data, &entity) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!data) {
		PHALCON_INIT_VAR(data);
	}
	
	if (!entity) {
		PHALCON_INIT_VAR(entity);
	} else {
		PHALCON_SEPARATE_PARAM(entity);
	}
	
	PHALCON_OBS_VAR(elements);
	phalcon_read_property(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (Z_TYPE_P(elements) == IS_ARRAY) { 
	
		/** 
		 * If the user doesn't pass an entity we use the one in this_ptr->_entity
		 */
		if (Z_TYPE_P(entity) != IS_OBJECT) {
			PHALCON_OBS_NVAR(entity);
			phalcon_read_property(&entity, this_ptr, SL("_entity"), PH_NOISY_CC);
		}
	
		PHALCON_INIT_VAR(failed);
		ZVAL_BOOL(failed, 0);
	
		PHALCON_INIT_VAR(messages);
		array_init(messages);
	
		if (!phalcon_is_iterable(elements, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(element);
	
			PHALCON_INIT_NVAR(validators);
			PHALCON_CALL_METHOD(validators, element, "getvalidators");
			if (Z_TYPE_P(validators) == IS_ARRAY) { 
	
				PHALCON_INIT_NVAR(validation);
				object_init_ex(validation, phalcon_validation_ce);
	
				PHALCON_INIT_NVAR(element_messages);
				PHALCON_CALL_METHOD_PARAMS_2(element_messages, validation, "validate", data, entity);
				if (phalcon_fast_count_ev(element_messages TSRMLS_CC)) {
					PHALCON_INIT_NVAR(name);
					PHALCON_CALL_METHOD(name, element, "getname");
					phalcon_array_update_zval(&messages, name, &element_messages, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
					PHALCON_INIT_NVAR(failed);
					ZVAL_BOOL(failed, 1);
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		/** 
		 * If the validation fails
		 */
		if (zend_is_true(failed)) {
			phalcon_update_property_zval(this_ptr, SL("_messages"), messages TSRMLS_CC);
		}
	
	
		RETURN_NCTOR(failed);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the messages generated in the validation
 *
 * @return array
 */
PHP_METHOD(Phalcon_Forms_Form, getMessages){

	zval *by_item_name = NULL, *messages, *group = NULL, *element_messages = NULL;
	zval *element = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &by_item_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!by_item_name) {
		PHALCON_INIT_VAR(by_item_name);
		ZVAL_BOOL(by_item_name, 1);
	}
	
	PHALCON_OBS_VAR(messages);
	phalcon_read_property(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (zend_is_true(by_item_name)) {
		if (Z_TYPE_P(messages) != IS_ARRAY) { 
			PHALCON_INIT_VAR(group);
			object_init_ex(group, phalcon_validation_message_group_ce);
			PHALCON_CALL_METHOD_NORETURN(group, "__construct");
	
			RETURN_CTOR(group);
		}
	
		RETURN_CCTOR(messages);
	}
	
	PHALCON_INIT_NVAR(group);
	object_init_ex(group, phalcon_validation_message_group_ce);
	PHALCON_CALL_METHOD_NORETURN(group, "__construct");
	
	
	if (!phalcon_is_iterable(messages, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_KEY(element, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(element_messages);
	
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(group, "appendmessages", element_messages);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	RETURN_CTOR(group);
}

/**
 * Returns the messages generated by
 *
 * @return Phalcon\Validation\Message\Group[]
 */
PHP_METHOD(Phalcon_Forms_Form, getMessagesFor){

	zval *name, *messages, *element_messages, *group;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(messages);
	phalcon_read_property(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (phalcon_array_isset(messages, name)) {
		PHALCON_OBS_VAR(element_messages);
		phalcon_array_fetch(&element_messages, messages, name, PH_NOISY_CC);
		RETURN_CCTOR(element_messages);
	}
	
	PHALCON_INIT_VAR(group);
	object_init_ex(group, phalcon_validation_message_group_ce);
	PHALCON_CALL_METHOD_NORETURN(group, "__construct");
	
	
	RETURN_CTOR(group);
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &element) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(element) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The element is not valid");
		return;
	}
	
	PHALCON_INIT_VAR(name);
	PHALCON_CALL_METHOD(name, element, "getname");
	phalcon_update_property_array(this_ptr, SL("_elements"), name, element TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Renders an specific item in the form
 *
 * @param string $name
 * @param array $attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Form, render){

	zval *name, *attributes = NULL, *elements, *exception_message;
	zval *element, *code;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &name, &attributes) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	PHALCON_OBS_VAR(elements);
	phalcon_read_property(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (!phalcon_array_isset(elements, name)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Element with ID=", name, " is not part of the form");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_forms_exception_ce, exception_message);
		return;
	}
	
	PHALCON_OBS_VAR(element);
	phalcon_array_fetch(&element, elements, name, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(code);
	PHALCON_CALL_METHOD_PARAMS_1(code, element, "render", attributes);
	
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(elements);
	phalcon_read_property(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
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

