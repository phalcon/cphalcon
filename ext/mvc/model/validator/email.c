
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
  +------------------------------------------------------------------------+
*/

#include "mvc/model/validator/email.h"
#include "mvc/model/validator.h"
#include "mvc/model/validatorinterface.h"
#include "mvc/model/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

#include "interned-strings.h"

/**
 * Phalcon\Mvc\Model\Validator\Email
 *
 * Allows to validate if email fields has correct values
 *
 *<code>
 *	use Phalcon\Mvc\Model\Validator\Email as EmailValidator;
 *
 *	class Subscriptors extends Phalcon\Mvc\Model
 *	{
 *
 *		public function validation()
 *		{
 *			$this->validate(new EmailValidator(array(
 *				'field' => 'electronic_mail'
 *      	)));
 *      	if ($this->validationHasFailed() == true) {
 *				return false;
 *      	}
 *  	}
 *
 *	}
 *</code>
 *
 */
zend_class_entry *phalcon_mvc_model_validator_email_ce;

PHP_METHOD(Phalcon_Mvc_Model_Validator_Email, validate);

static const zend_function_entry phalcon_mvc_model_validator_email_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Validator_Email, validate, arginfo_phalcon_mvc_model_validatorinterface_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Validator\Email initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Email){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Email, mvc_model_validator_email, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_email_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_email_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\ModelInterface $record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Email, validate){

	zval *record, *option = NULL, *field_name = NULL, *regs, *invalid = NULL;
	zval *value = NULL, *pattern, *match_pattern, *match_zero;
	zval *message = NULL, *type, *is_set_code = NULL, *code = NULL;
	zval *allow_empty = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &record);
	
	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "field", 1);
	
	PHALCON_CALL_METHOD(&field_name, this_ptr, "getoption", option);
	if (Z_TYPE_P(field_name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Field name must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(regs);
	
	PHALCON_INIT_VAR(invalid);
	ZVAL_BOOL(invalid, 0);
	
	PHALCON_CALL_METHOD(&value, record, "readattribute", field_name);

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
	 * We check if the email has a valid format using a regular expression
	 */
	PHALCON_INIT_VAR(pattern);
	ZVAL_STRING(pattern, "/^([^\\x00-\\x20\\x22\\x28\\x29\\x2c\\x2e\\x3a-\\x3c\\x3e\\x40\\x5b-\\x5d\\x7f-\\xff]+|\\x22([^\\x0d\\x22\\x5c\\x80-\\xff]|\\x5c[\\x00-\\x7f])*\\x22)(\\x2e([^\\x00-\\x20\\x22\\x28\\x29\\x2c\\x2e\\x3a-\\x3c\\x3e\\x40\\x5b-\\x5d\\x7f-\\xff]+|\\x22([^\\x0d\\x22\\x5c\\x80-\\xff]|\\x5c[\\x00-\\x7f])*\\x22))*\\x40([^\\x00-\\x20\\x22\\x28\\x29\\x2c\\x2e\\x3a-\\x3c\\x3e\\x40\\x5b-\\x5d\\x7f-\\xff]+|\\x5b([^\\x0d\\x5b-\\x5d\\x80-\\xff]|\\x5c[\\x00-\\x7f])*\\x5d)(\\x2e([^\\x00-\\x20\\x22\\x28\\x29\\x2c\\x2e\\x3a-\\x3c\\x3e\\x40\\x5b-\\x5d\\x7f-\\xff]+|\\x5b([^\\x0d\\x5b-\\x5d\\x80-\\xff]|\\x5c[\\x00-\\x7f])*\\x5d))*$/", 1);
	
	PHALCON_INIT_VAR(match_pattern);
	RETURN_MM_ON_FAILURE(phalcon_preg_match(match_pattern, pattern, value, regs TSRMLS_CC));
	
	if (zend_is_true(match_pattern)) {
		PHALCON_OBS_VAR(match_zero);
		phalcon_array_fetch_long(&match_zero, regs, 0, PH_NOISY);
	
		is_not_equal_function(invalid, match_zero, value TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(invalid);
		ZVAL_BOOL(invalid, 1);
	}
	
	if (PHALCON_IS_TRUE(invalid)) {
	
		/** 
		 * Check if the developer has defined a custom message
		 */
		PHALCON_INIT_NVAR(option);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(option, phalcon_interned_message);
	
		PHALCON_CALL_METHOD(&message, this_ptr, "getoption", option);
		if (!zend_is_true(message)) {
			PHALCON_INIT_NVAR(message);
			PHALCON_CONCAT_SVS(message, "Value of field '", field_name, "' must have a valid e-mail format");
		}
	
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "Email", 1);

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

		PHALCON_CALL_METHOD(NULL, this_ptr, "appendmessage", message, field_name, type, code);
		RETURN_MM_FALSE;
	}
	
	RETURN_MM_TRUE;
}

