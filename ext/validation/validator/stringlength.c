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

#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Validation\Validator\StringLength
 *
 * Validates that a string has the specified maximum and minimum constraints
 *
 *<code>
 *use Phalcon\Validation\Validator\StringLength as StringLength;
 *
 *$validation->validate('name_last', new StringLength(array(
 *	'max' => 50,
 *	'min' => 2,
 *	'messageMaximum' => 'We don\'t like really long names',
 *	'messageMinimum' => 'We want more than just their initials'
 *)));
 *</code>
 *
 */


/**
 * Phalcon\Validation\Validator\StringLength initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Validator_StringLength){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, StringLength, validation_validator_stringlength, "phalcon\\validation\\validator", phalcon_validation_validator_stringlength_method_entry, 0);

	zend_class_implements(phalcon_validation_validator_stringlength_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation $validator
 * @param string $attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_StringLength, validate){

	zval *validator, *attribute, *option = NULL, *is_set_min;
	zval *is_set_max, *value, *length = NULL, *invalid_maximum = NULL;
	zval *invalid_minimum = NULL, *maximum, *message_str = NULL;
	zval *type = NULL, *message = NULL, *minimum;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &validator, &attribute) == FAILURE) {
		RETURN_MM_NULL();
	}

	/** 
	 * At least one of 'min' or 'max' must be set
	 */
	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "min", 1);
	
	PHALCON_INIT_VAR(is_set_min);
	PHALCON_CALL_METHOD_PARAMS_1(is_set_min, this_ptr, "issetoption", option);
	
	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "max", 1);
	
	PHALCON_INIT_VAR(is_set_max);
	PHALCON_CALL_METHOD_PARAMS_1(is_set_max, this_ptr, "issetoption", option);
	if (!zend_is_true(is_set_min)) {
		if (!zend_is_true(is_set_max)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A minimum or maximum must be set");
			return;
		}
	}
	
	PHALCON_INIT_VAR(value);
	PHALCON_CALL_METHOD_PARAMS_1(value, validator, "getvalue", attribute);
	
	/** 
	 * Check if mbstring is available to calculate the correct length
	 */
	if (phalcon_function_exists_ex(SS("mb_strlen") TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(length);
		PHALCON_CALL_FUNC_PARAMS_1(length, "mb_strlen", value);
	} else {
		PHALCON_INIT_NVAR(length);
		phalcon_fast_strlen(length, value);
	}
	
	PHALCON_INIT_VAR(invalid_maximum);
	ZVAL_BOOL(invalid_maximum, 0);
	
	PHALCON_INIT_VAR(invalid_minimum);
	ZVAL_BOOL(invalid_minimum, 0);
	
	/** 
	 * Maximum length
	 */
	if (zend_is_true(is_set_max)) {
	
		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "max", 1);
	
		PHALCON_INIT_VAR(maximum);
		PHALCON_CALL_METHOD_PARAMS_1(maximum, this_ptr, "getoption", option);
	
		is_smaller_function(invalid_maximum, maximum, length TSRMLS_CC);
		if (PHALCON_IS_TRUE(invalid_maximum)) {
	
			/** 
			 * Check if the developer has defined a custom message
			 */
			PHALCON_INIT_NVAR(option);
			ZVAL_STRING(option, "messageMaximum", 1);
	
			PHALCON_INIT_VAR(message_str);
			PHALCON_CALL_METHOD_PARAMS_1(message_str, this_ptr, "getoption", option);
			if (!zend_is_true(message_str)) {
				PHALCON_INIT_NVAR(message_str);
				PHALCON_CONCAT_SVSVS(message_str, "Value of field '", attribute, "' exceeds the maximum ", maximum, " characters");
			}
	
			PHALCON_INIT_VAR(type);
			ZVAL_STRING(type, "TooLong", 1);
	
			PHALCON_INIT_VAR(message);
			object_init_ex(message, phalcon_validation_message_ce);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(message, "__construct", message_str, attribute, type);
	
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(validator, "appendmessage", message);
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Minimum length
	 */
	if (zend_is_true(is_set_min)) {
	
		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "min", 1);
	
		PHALCON_INIT_VAR(minimum);
		PHALCON_CALL_METHOD_PARAMS_1(minimum, this_ptr, "getoption", option);
	
		is_smaller_function(invalid_minimum, length, minimum TSRMLS_CC);
		if (PHALCON_IS_TRUE(invalid_minimum)) {
	
			/** 
			 * Check if the developer has defined a custom message
			 */
			PHALCON_INIT_NVAR(option);
			ZVAL_STRING(option, "messageMinimum", 1);
	
			PHALCON_INIT_NVAR(message_str);
			PHALCON_CALL_METHOD_PARAMS_1(message_str, this_ptr, "getoption", option);
			if (!zend_is_true(message_str)) {
				PHALCON_INIT_NVAR(message_str);
				PHALCON_CONCAT_SVSVS(message_str, "Value of field '", attribute, "' is less than the minimum ", minimum, " characters");
			}
	
			PHALCON_INIT_NVAR(type);
			ZVAL_STRING(type, "TooShort", 1);
	
			PHALCON_INIT_NVAR(message);
			object_init_ex(message, phalcon_validation_message_ce);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(message, "__construct", message_str, attribute, type);
	
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(validator, "appendmessage", message);
			RETURN_MM_FALSE;
		}
	}
	
	RETURN_MM_TRUE;
}

