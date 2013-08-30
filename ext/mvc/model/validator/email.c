
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

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

	zval *record, *option = NULL, *field_name, *regs, *invalid = NULL;
	zval *value, *pattern, *match_pattern, *match_zero;
	zval *message = NULL, *type, *is_set_code, *code;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &record);
	
	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "field", 1);
	
	PHALCON_INIT_VAR(field_name);
	phalcon_call_method_p1(field_name, this_ptr, "getoption", option);
	if (Z_TYPE_P(field_name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Field name must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(regs);
	
	PHALCON_INIT_VAR(invalid);
	ZVAL_BOOL(invalid, 0);
	
	PHALCON_INIT_VAR(value);
	phalcon_call_method_p1(value, record, "readattribute", field_name);
	
	/** 
	 * We check if the email has a valid format using a regular expression
	 */
	PHALCON_INIT_VAR(pattern);
	ZVAL_STRING(pattern, "/^[a-zA-Z0-9\\-_\\.\\+]+@[a-zA-Z0-9_\\-]+(\\.[a-zA-Z0-9_\\-]+)*$/", 1);
	
	PHALCON_INIT_VAR(match_pattern);
	phalcon_preg_match(match_pattern, NULL, pattern, value, regs TSRMLS_CC);
	
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
		ZVAL_STRING(option, "message", 1);
	
		PHALCON_INIT_VAR(message);
		phalcon_call_method_p1(message, this_ptr, "getoption", option);
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
		ZVAL_STRING(option, "code", 1);

		PHALCON_INIT_VAR(is_set_code);
		phalcon_call_method_p1(is_set_code, this_ptr, "issetoption", option);
		PHALCON_INIT_VAR(code);
		if (zend_is_true(is_set_code)) {
			phalcon_call_method_p1(code, this_ptr, "getoption", option);
		} else {
			ZVAL_LONG(code, 0);
		}

		phalcon_call_method_p4_noret(this_ptr, "appendmessage", message, field_name, type, code);
		RETURN_MM_FALSE;
	}
	
	RETURN_MM_TRUE;
}

