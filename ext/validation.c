
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"

/**
 * Phalcon\Validation
 *
 * Allows to validate data using validators
 */


/**
 * Phalcon\Validation initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation){

	PHALCON_REGISTER_CLASS_EX(Phalcon, Validation, validation, "phalcon\\di\\injectable", phalcon_validation_method_entry, 0);

	zend_declare_property_null(phalcon_validation_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_entity"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_validators"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_values"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Validation constructor
 *
 * @param array $validators
 */
PHP_METHOD(Phalcon_Validation, __construct){

	zval *validators = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &validators) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!validators) {
		PHALCON_INIT_VAR(validators);
	}
	
	if (Z_TYPE_P(validators) != IS_NULL) {
		if (Z_TYPE_P(validators) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Validators must be an array");
			return;
		}
		phalcon_update_property_zval(this_ptr, SL("_validators"), validators TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Validate a set of data according to a set of rules
 *
 * @param array|object $data
 * @param object $entity
 */
PHP_METHOD(Phalcon_Validation, validate){

	zval *data = NULL, *entity = NULL, *validators, *status = NULL, *messages = NULL;
	zval *cancel_on_fail, *scope = NULL, *attribute = NULL, *validator = NULL;
	zval *must_cancel = NULL;
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
	}
	
	PHALCON_OBS_VAR(validators);
	phalcon_read_property_this(&validators, this_ptr, SL("_validators"), PH_NOISY_CC);
	if (Z_TYPE_P(validators) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "There are no validators to validate");
		return;
	}
	
	if (phalcon_method_exists_ex(this_ptr, SS("beforevalidation") TSRMLS_CC) == SUCCESS) {
	
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, this_ptr, "beforevalidation", data, entity);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_CCTOR(status);
		}
	}
	
	/** 
	 * Clear pre-calculated values
	 */
	phalcon_update_property_null(this_ptr, SL("_values") TSRMLS_CC);
	
	/** 
	 * Implicitly creates a Phalcon\Validation\Message\Group object
	 */
	PHALCON_INIT_VAR(messages);
	object_init_ex(messages, phalcon_validation_message_group_ce);
	PHALCON_CALL_METHOD_NORETURN(messages, "__construct");
	
	phalcon_update_property_zval(this_ptr, SL("_messages"), messages TSRMLS_CC);
	if (Z_TYPE_P(data) == IS_ARRAY) { 
		phalcon_update_property_zval(this_ptr, SL("_data"), data TSRMLS_CC);
	} else {
		if (Z_TYPE_P(data) == IS_OBJECT) {
			phalcon_update_property_zval(this_ptr, SL("_data"), data TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(cancel_on_fail);
	ZVAL_STRING(cancel_on_fail, "cancelOnFail", 1);
	
	if (!phalcon_is_iterable(validators, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(scope);
	
		if (Z_TYPE_P(scope) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The validator scope is not valid");
			return;
		}
	
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_long(&attribute, scope, 0, PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(validator);
		phalcon_array_fetch_long(&validator, scope, 1, PH_NOISY_CC);
		if (Z_TYPE_P(validator) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "One of the validators is not valid");
			return;
		}
	
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, validator, "validate", this_ptr, attribute);
	
		/** 
		 * Check if the validation must be canceled if this validator fails
		 */
		if (PHALCON_IS_FALSE(status)) {
	
			PHALCON_INIT_NVAR(must_cancel);
			PHALCON_CALL_METHOD_PARAMS_1(must_cancel, validator, "getoption", cancel_on_fail);
			if (zend_is_true(must_cancel)) {
				break;
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_OBS_NVAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (phalcon_method_exists_ex(this_ptr, SS("aftervalidation") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "aftervalidation", messages);
	}
	
	
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
 * Adds filters to the field
 *
 * @param string $attribute
 * @param array|string $attribute
 * @return Phalcon\Validator
 */
PHP_METHOD(Phalcon_Validation, setFilters){

	zval *attribute, *filters;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &attribute, &filters) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_array(this_ptr, SL("_filters"), attribute, filters TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns all the filters or a specific one
 *
 * @param string $attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation, getFilters){

	zval *attribute = NULL, *filters, *attribute_filters;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &attribute) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!attribute) {
		PHALCON_INIT_VAR(attribute);
	}
	
	PHALCON_OBS_VAR(filters);
	phalcon_read_property_this(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
	if (Z_TYPE_P(attribute) == IS_STRING) {
		if (phalcon_array_isset(filters, attribute)) {
			PHALCON_OBS_VAR(attribute_filters);
			phalcon_array_fetch(&attribute_filters, filters, attribute, PH_NOISY_CC);
			RETURN_CCTOR(attribute_filters);
		}
		RETURN_MM_NULL();
	}
	
	
	RETURN_CCTOR(filters);
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

	zval *message, *messages;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
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

/**
 * Gets the a value to validate in the array/object data source
 *
 * @param string $attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation, getValue){

	zval *attribute, *entity, *method, *value = NULL, *data, *values;
	zval *filters = NULL, *service_name, *dependency_injector;
	zval *filter_service, *filtered;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &attribute) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(entity);
	phalcon_read_property_this(&entity, this_ptr, SL("_entity"), PH_NOISY_CC);
	
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
	phalcon_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		if (Z_TYPE_P(data) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "There is no data to validate");
			return;
		}
	}
	
	/** 
	 * Check if there is a calculated value
	 */
	PHALCON_OBS_VAR(values);
	phalcon_read_property_this(&values, this_ptr, SL("_values"), PH_NOISY_CC);
	if (phalcon_array_isset(values, attribute)) {
		PHALCON_OBS_NVAR(value);
		phalcon_array_fetch(&value, values, attribute, PH_NOISY_CC);
		RETURN_CCTOR(value);
	}
	
	PHALCON_INIT_NVAR(value);
	if (Z_TYPE_P(data) == IS_ARRAY) { 
		if (phalcon_array_isset(data, attribute)) {
			PHALCON_OBS_NVAR(value);
			phalcon_array_fetch(&value, data, attribute, PH_NOISY_CC);
		}
	} else {
		if (Z_TYPE_P(data) == IS_OBJECT) {
			if (phalcon_isset_property_zval(data, attribute TSRMLS_CC)) {
				PHALCON_OBS_NVAR(value);
				phalcon_read_property_zval(&value, data, attribute, PH_NOISY_CC);
			}
		}
	}
	
	if (Z_TYPE_P(value) != IS_NULL) {
	
		PHALCON_OBS_VAR(filters);
		phalcon_read_property_this(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
		if (Z_TYPE_P(filters) == IS_ARRAY) { 
			if (phalcon_array_isset(filters, attribute)) {
	
				PHALCON_OBS_VAR(r0);
				phalcon_array_fetch(&r0, filters, attribute, PH_NOISY_CC);
				PHALCON_CPY_WRT(filters, r0);
				if (zend_is_true(filters)) {
	
					PHALCON_INIT_VAR(service_name);
					ZVAL_STRING(service_name, "filter", 1);
	
					PHALCON_INIT_VAR(dependency_injector);
					PHALCON_CALL_METHOD(dependency_injector, this_ptr, "getdi");
	
					PHALCON_INIT_VAR(filter_service);
					PHALCON_CALL_METHOD_PARAMS_1(filter_service, dependency_injector, "getshared", service_name);
					if (Z_TYPE_P(filter_service) != IS_OBJECT) {
						PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Returned 'filter' service is invalid");
						return;
					}
				}
	
				PHALCON_INIT_VAR(filtered);
				PHALCON_CALL_METHOD_PARAMS_2(filtered, filter_service, "sanitize", value, filters);
	
				RETURN_CCTOR(filtered);
			}
		}
	
		/** 
		 * Cache the calculated value
		 */
		phalcon_update_property_array(this_ptr, SL("_values"), attribute, value TSRMLS_CC);
	
		RETURN_CCTOR(value);
	}
	
	RETURN_MM_NULL();
}

