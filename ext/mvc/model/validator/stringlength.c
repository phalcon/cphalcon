
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/model/validator/stringlength.h"
#include "mvc/model/validator.h"
#include "mvc/model/validatorinterface.h"
#include "mvc/model/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

#include "interned-strings.h"

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
 *			'messageMaximum' => 'We don\'t like really long names',
 *			'messageMinimum' => 'We want more than just their initials'
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
zend_class_entry *phalcon_mvc_model_validator_stringlength_ce;

PHP_METHOD(Phalcon_Mvc_Model_Validator_StringLength, validate);

static const zend_function_entry phalcon_mvc_model_validator_stringlength_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Validator_StringLength, validate, arginfo_phalcon_mvc_model_validatorinterface_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Validator\StringLength initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_StringLength){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, StringLength, mvc_model_validator_stringlength, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_stringlength_method_entry, 0);

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

	zval *record, *option = NULL, *field = NULL, *is_set_min = NULL, *is_set_max = NULL;
	zval *value = NULL, *length = NULL, *invalid_maximum = NULL, *invalid_minimum = NULL;
	zval *maximum = NULL, *message = NULL, *type = NULL, *minimum = NULL, *is_set_code = NULL, *code = NULL;
	zval *allow_empty = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &record);
	
	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "field", 1);
	
	PHALCON_CALL_METHOD(&field, this_ptr, "getoption", option);
	if (Z_TYPE_P(field) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Field name must be a string");
		return;
	}
	
	/** 
	 * At least one of 'min' or 'max' must be set
	 */
	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "min", 1);
	
	PHALCON_CALL_METHOD(&is_set_min, this_ptr, "issetoption", option);
	
	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "max", 1);
	
	PHALCON_CALL_METHOD(&is_set_max, this_ptr, "issetoption", option);
	if (!zend_is_true(is_set_min)) {
		if (!zend_is_true(is_set_max)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A minimum or maximum must be set");
			return;
		}
	}
	
	PHALCON_CALL_METHOD(&value, record, "readattribute", field);

	/*
	 * Allow empty
	 */
	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "allowEmpty", 1);

	PHALCON_CALL_METHOD(&allow_empty, this_ptr, "getoption", option);
	if (allow_empty && zend_is_true(allow_empty) && PHALCON_IS_EMPTY(value)) {
		RETURN_MM_TRUE;
	}
	
	/** 
	 * Check if mbstring is available to calculate the correct length
	 */
	if (phalcon_function_exists_ex(SS("mb_strlen") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_FUNCTION(&length, "mb_strlen", value);
	} else {
		PHALCON_INIT_VAR(length);
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
	
		PHALCON_CALL_METHOD(&maximum, this_ptr, "getoption", option);
	
		is_smaller_function(invalid_maximum, maximum, length TSRMLS_CC);
		if (PHALCON_IS_TRUE(invalid_maximum)) {
	
			/** 
			 * Check if the developer has defined a custom message
			 */
			PHALCON_INIT_NVAR(option);
			ZVAL_STRING(option, "messageMaximum", 1);
	
			PHALCON_CALL_METHOD(&message, this_ptr, "getoption", option);
			if (!zend_is_true(message)) {
				PHALCON_INIT_NVAR(message);
				PHALCON_CONCAT_SVSVS(message, "Value of field '", field, "' exceeds the maximum ", maximum, " characters");
			}
	
			PHALCON_INIT_VAR(type);
			ZVAL_STRING(type, "TooLong", 1);

			/*
			 * Is code set
			 */
			PHALCON_INIT_NVAR(option);
			PHALCON_ZVAL_MAYBE_INTERNED_STRING(option, phalcon_interned_code);

			PHALCON_CALL_METHOD(&is_set_code, this_ptr, "issetoption", option);
			if (zend_is_true(is_set_code)) {
				PHALCON_CALL_METHOD(&code, this_ptr, "getoption", option);
			} else {
				PHALCON_INIT_VAR(code);
				ZVAL_LONG(code, 0);
			}

			PHALCON_CALL_METHOD(NULL, this_ptr, "appendmessage", message, field, type, code);
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Minimum length
	 */
	if (zend_is_true(is_set_min)) {
	
		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "min", 1);
	
		PHALCON_CALL_METHOD(&minimum, this_ptr, "getoption", option);
	
		is_smaller_function(invalid_minimum, length, minimum TSRMLS_CC);
		if (PHALCON_IS_TRUE(invalid_minimum)) {
	
			/** 
			 * Check if the developer has defined a custom message
			 */
			PHALCON_INIT_NVAR(option);
			ZVAL_STRING(option, "messageMinimum", 1);
	
			PHALCON_CALL_METHOD(&message, this_ptr, "getoption", option);
			if (!zend_is_true(message)) {
				PHALCON_INIT_NVAR(message);
				PHALCON_CONCAT_SVSVS(message, "Value of field '", field, "' is less than the minimum ", minimum, " characters");
			}
	
			PHALCON_INIT_NVAR(type);
			ZVAL_STRING(type, "TooShort", 1);

			/*
			 * Is code set
			 */
			PHALCON_INIT_NVAR(option);
			PHALCON_ZVAL_MAYBE_INTERNED_STRING(option, phalcon_interned_code);

			PHALCON_CALL_METHOD(&is_set_code, this_ptr, "issetoption", option);
			if (zend_is_true(is_set_code)) {
				PHALCON_CALL_METHOD(&code, this_ptr, "getoption", option);
			} else {
				PHALCON_INIT_VAR(code);
				ZVAL_LONG(code, 0);
			}

			PHALCON_CALL_METHOD(NULL, this_ptr, "appendmessage", message, field, type, code);
			RETURN_MM_FALSE;
		}
	}
	
	RETURN_MM_TRUE;
}
