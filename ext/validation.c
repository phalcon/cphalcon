
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

/**
 * Phalcon\Validation
 */


/**
 * Phalcon\Validation initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation){

	PHALCON_REGISTER_CLASS(Phalcon, Validation, validation, phalcon_validation_method_entry, 0);

	zend_declare_property_null(phalcon_validation_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_validators"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Validation, validate){

	zval *data = NULL, *validators, *scope = NULL, *attribute = NULL, *validator = NULL;
	zval *messages;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &data) == FAILURE) {
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
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Validation, getValidators){


	RETURN_MEMBER(this_ptr, "_validators");
}

PHP_METHOD(Phalcon_Validation, getMessages){


	RETURN_MEMBER(this_ptr, "_messages");
}

PHP_METHOD(Phalcon_Validation, appendMessage){

	zval *message;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_array_append(this_ptr, SL("_messages"), message TSRMLS_CC);
	
}

PHP_METHOD(Phalcon_Validation, bind){

	zval *data;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(data) != IS_ARRAY) { 
		if (Z_TYPE_P(data) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The data to validate must be an array or object");
			return;
		}
	}
	phalcon_update_property_zval(this_ptr, SL("_data"), data TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Validation, getValue){

	zval *key, *data, *value = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key) == FAILURE) {
		RETURN_MM_NULL();
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
		if (phalcon_array_isset(data, key)) {
			PHALCON_OBS_VAR(value);
			phalcon_array_fetch(&value, data, key, PH_NOISY_CC);
			RETURN_CCTOR(value);
		}
	}
	
	if (Z_TYPE_P(data) == IS_OBJECT) {
		if (phalcon_isset_property_zval(data, key TSRMLS_CC)) {
			PHALCON_OBS_NVAR(value);
			phalcon_read_property_zval(&value, data, key, PH_NOISY_CC);
			RETURN_CCTOR(value);
		}
	}
	
	RETURN_MM_NULL();
}

