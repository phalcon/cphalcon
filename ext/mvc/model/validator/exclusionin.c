
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Model\Validator\ExclusionIn
 *
 * Check if a value is not included into a list of values
 *
 *<code>
 *	use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionInValidator;
 *
 *	class Subscriptors extends Phalcon\Mvc\Model
 *	{
 *
 *		public function validation()
 *		{
 *			$this->validate(new ExclusionInValidator(array(
 *				'field' => 'status',
 *				'domain' => array('A', 'I')
 *			)));
 *			if ($this->validationHasFailed() == true) {
 *				return false;
 *			}
 *		}
 *
 *	}
 *</code>
 */


/**
 * Phalcon\Mvc\Model\Validator\Exclusionin initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Exclusionin){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Exclusionin, mvc_model_validator_exclusionin, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_exclusionin_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_exclusionin_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\ModelInterface $record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Exclusionin, validate){

	zval *record, *option = NULL, *field_name, *is_set, *domain;
	zval *value, *message = NULL, *joined_domain, *type, *is_set_code, *code;

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
	
	/** 
	 * The 'domain' option must be a valid array of not allowed values
	 */
	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "domain", 1);
	
	PHALCON_INIT_VAR(is_set);
	phalcon_call_method_p1(is_set, this_ptr, "issetoption", option);
	if (PHALCON_IS_FALSE(is_set)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The option 'domain' is required for this validator");
		return;
	}
	
	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "domain", 1);
	
	PHALCON_INIT_VAR(domain);
	phalcon_call_method_p1(domain, this_ptr, "getoption", option);
	if (Z_TYPE_P(domain) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Option 'domain' must be an array");
		return;
	}
	
	PHALCON_INIT_VAR(value);
	phalcon_call_method_p1(value, record, "readattribute", field_name);
	
	/** 
	 * We check if the value contained in the array using "in_array" from the PHP
	 * userland
	 */
	if (phalcon_fast_in_array(value, domain TSRMLS_CC)) {
	
		/** 
		 * Check if the developer has defined a custom message
		 */
		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "message", 1);
	
		PHALCON_INIT_VAR(message);
		phalcon_call_method_p1(message, this_ptr, "getoption", option);
		if (!zend_is_true(message)) {
			PHALCON_INIT_VAR(joined_domain);
			phalcon_fast_join_str(joined_domain, SL(", "), domain TSRMLS_CC);
	
			PHALCON_INIT_NVAR(message);
			PHALCON_CONCAT_SVSV(message, "Value of field '", field_name, "' must not be part of list: ", joined_domain);
		}
	
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "Exclusion", 1);

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

