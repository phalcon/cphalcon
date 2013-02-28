
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

#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"

/**
 * Phalcon\Validation
 */


/**
 * Phalcon\Validation initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation){

	PHALCON_REGISTER_CLASS(Phalcon, Validation, validation, phalcon_validation_method_entry, 0);

	zend_declare_property_null(phalcon_validation_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_entity"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_validators"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Validate a set of data according to a set of rules
 *
 * @param array|object $data
 * @param object $entity
 */
PHP_METHOD(Phalcon_Validation, validate){

	zval *data = NULL, *entity, *validators, *scope = NULL, *attribute = NULL;
	zval *validator = NULL, *messages;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &data, &entity) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!data) {
		PHALCON_INIT_VAR(data);
	}
	
	phalcon_update_property_null(this_ptr, SL("_messages") TSRMLS_CC);
	if (Z_TYPE_P(data) == IS_ARRAY) { 
		phalcon_update_property_zval(this_ptr, SL("_data"), data TSRMLS_CC);
	} else {
		if (Z_TYPE_P(data) == IS_OBJECT) {
			phalcon_update_property_zval(this_ptr, SL("_data"), data TSRMLS_CC);
		}
	}
	
	PHALCON_OBS_VAR(validators);
	phalcon_read_property(&validators, this_ptr, SL("_validators"), PH_NOISY_CC);
	if (Z_TYPE_P(validators) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "There are no validators to validate");
		return;
	}
	
	
	if (!phalcon_is_iterable(validators, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(scope);
	
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_long(&attribute, scope, 0, PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(validator);
		phalcon_array_fetch_long(&validator, scope, 1, PH_NOISY_CC);
		if (Z_TYPE_P(validator) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "One of the validators is not valid");
			return;
		}
	
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(validator, "validate", this_ptr, attribute);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_OBS_VAR(messages);
	phalcon_read_property(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	
	RETURN_CCTOR(messages);
}

/**
 * Adds a validator to a field
 *
 * @param string $attribute
 * @param Phalcon\Validation\ValidatorInterface
 * @return Phalcon\Validator
 */
PHP_METHOD(Phalcon_Validation, add){

	zval *attribute, *validator, *scope;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &attribute, &validator) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(attribute) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The attribute must be an string");
		return;
	}
	if (Z_TYPE_P(validator) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The validator must be an object");
		return;
	}
	
	PHALCON_INIT_VAR(scope);
	array_init_size(scope, 2);
	phalcon_array_append(&scope, attribute, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&scope, validator, PH_SEPARATE TSRMLS_CC);
	phalcon_update_property_array_append(this_ptr, SL("_validators"), scope TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Returns the data that is currently validated
 *
 * @return array
 */
PHP_METHOD(Phalcon_Validation, getValidators){


	RETURN_MEMBER(this_ptr, "_validators");
}

/**
 * Returns the bound entity
 *
 * @return object
 */
PHP_METHOD(Phalcon_Validation, getEntity){


	RETURN_MEMBER(this_ptr, "_entity");
}

/**
 * Returns the registered validators
 *
 * @return Phalcon\Validation\Message\Group
 */
PHP_METHOD(Phalcon_Validation, getMessages){


	RETURN_MEMBER(this_ptr, "_messages");
}

/**
 * Appends a message to the messages list
 *
 * @param Phalcon\Validation\MessageInterface $message
 */
PHP_METHOD(Phalcon_Validation, appendMessage){

	zval *message, *messages = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(messages);
	phalcon_read_property(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	
	/** 
	 * Implicitly creates a Phalcon\Validation\Message\Group object
	 */
	if (Z_TYPE_P(messages) != IS_OBJECT) {
		ce0 = zend_fetch_class(SL("Phalcon_Validation_Message_Group"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		PHALCON_INIT_NVAR(messages);
		object_init_ex(messages, ce0);
		if (phalcon_has_constructor(messages TSRMLS_CC)) {
			PHALCON_CALL_METHOD_NORETURN(messages, "__construct");
		}
		phalcon_update_property_zval(this_ptr, SL("_messages"), messages TSRMLS_CC);
	}
	
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(messages, "appendmessage", message);
	
	PHALCON_MM_RESTORE();
}

/**
 * Assigns the data to an entity
 * The entity is used to obtain the validation values
 *
 * @param string $entity
 * @param string $data
 * @return Phalcon\Validator
 */
PHP_METHOD(Phalcon_Validation, bind){

	zval *entity, *data;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &entity, &data) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(entity) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The entity must be an object");
		return;
	}
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		if (Z_TYPE_P(data) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The data to validate must be an array or object");
			return;
		}
	}
	
	phalcon_update_property_zval(this_ptr, SL("_entity"), entity TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_data"), data TSRMLS_CC);
	
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Validation, getValue){

	zval *attribute, *entity, *method, *value = NULL, *data;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &attribute) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(entity);
	phalcon_read_property(&entity, this_ptr, SL("_entity"), PH_NOISY_CC);
	
	/** 
	 * If the entity is an object use it to retrieve the values
	 */
	if (Z_TYPE_P(entity) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(method);
		PHALCON_CONCAT_SV(method, "get", attribute);
		if (phalcon_method_exists(entity, method TSRMLS_CC) == SUCCESS) {
			PHALCON_INIT_VAR(value);
			PHALCON_CALL_METHOD(value, entity, Z_STRVAL_P(method));
		} else {
			if (phalcon_method_exists_ex(entity, SS("readattribute") TSRMLS_CC) == SUCCESS) {
				PHALCON_INIT_NVAR(value);
				PHALCON_CALL_METHOD(value, entity, "readattribute");
			} else {
				if (phalcon_isset_property_zval(entity, attribute TSRMLS_CC)) {
					PHALCON_OBS_NVAR(value);
					phalcon_read_property_zval(&value, entity, attribute, PH_NOISY_CC);
				} else {
					PHALCON_INIT_NVAR(value);
				}
			}
		}
	
	
		RETURN_CCTOR(value);
	}
	
	PHALCON_OBS_VAR(data);
	phalcon_read_property(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		if (Z_TYPE_P(data) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "There is no data to validate");
			return;
		}
	}
	
	if (Z_TYPE_P(data) == IS_ARRAY) { 
		if (phalcon_array_isset(data, attribute)) {
			PHALCON_OBS_NVAR(value);
			phalcon_array_fetch(&value, data, attribute, PH_NOISY_CC);
			RETURN_CCTOR(value);
		}
	}
	
	if (Z_TYPE_P(data) == IS_OBJECT) {
		if (phalcon_isset_property_zval(data, attribute TSRMLS_CC)) {
			PHALCON_OBS_NVAR(value);
			phalcon_read_property_zval(&value, data, attribute, PH_NOISY_CC);
			RETURN_CCTOR(value);
		}
	}
	
	RETURN_MM_NULL();
}

