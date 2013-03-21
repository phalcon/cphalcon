
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
  |          Jason Rice                                                    |
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
 * Phalcon\Mvc\Model\Validator\StringLength
 *
 * Simply validates specified string length constraints
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\StringLength as StringLengthValidator;
 *
 *class Subscriptors extends Phalcon\Mvc\Model
 *{
 *
 *	public function validation()
 *	{
 *		$this->validate(new StringLengthValidator(array(
 *			'field' => 'name_last',
 *			'max' => 50,
 *			'min' => 2,
 *          'messageMaximum' => 'We don't like really long names',
 *          'messageMinimum' => 'We want more than just their initials'
 *		)));
 *		if ($this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 *
 */


/**
 * Phalcon\Mvc\Model\Validator\StringLength initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_StringLength){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, StringLength, mvc_model_validator_stringlength, "phalcon\\mvc\\model\\validator", phalcon_mvc_model_validator_stringlength_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_stringlength_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\ModelInterface $record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_StringLength, validate){

	zval *record, *option = NULL, *field, *is_set_min, *is_set_max;
	zval *value, *length = NULL, *invalid_maximum = NULL, *invalid_minimum = NULL;
	zval *maximum, *message = NULL, *type = NULL, *minimum;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &record) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "field", 1);
	
	PHALCON_INIT_VAR(field);
	PHALCON_CALL_METHOD_PARAMS_1(field, this_ptr, "getoption", option);
	if (Z_TYPE_P(field) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Field name must be a string");
		return;
	}
	
	/** 
	 * At least one of 'min' or 'max' must be set
	 */
	PHALCON_INIT_NVAR(option);
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
	PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", field);
	
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
	
			PHALCON_INIT_VAR(message);
			PHALCON_CALL_METHOD_PARAMS_1(message, this_ptr, "getoption", option);
			if (!zend_is_true(message)) {
				PHALCON_INIT_NVAR(message);
				PHALCON_CONCAT_SVSVS(message, "Value of field '", field, "' exceeds the maximum ", maximum, " characters");
			}
	
			PHALCON_INIT_VAR(type);
			ZVAL_STRING(type, "TooLong", 1);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", message, field, type);
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
	
			PHALCON_INIT_NVAR(message);
			PHALCON_CALL_METHOD_PARAMS_1(message, this_ptr, "getoption", option);
			if (!zend_is_true(message)) {
				PHALCON_INIT_NVAR(message);
				PHALCON_CONCAT_SVSVS(message, "Value of field '", field, "' is less than the minimum ", minimum, " characters");
			}
	
			PHALCON_INIT_NVAR(type);
			ZVAL_STRING(type, "TooShort", 1);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", message, field, type);
			RETURN_MM_FALSE;
		}
	}
	
	RETURN_MM_TRUE;
}

