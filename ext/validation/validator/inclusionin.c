
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
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"

/**
 * Phalcon\Validation\Validator\InclusionIn
 *
 * Check if a value is included into a list of values
 *
 *<code>
 *use Phalcon\Validation\Validator\InclusionIn;
 *
 *$validator->add('status', new InclusionIn(array(
 *   'message' => 'The status must be A or B',
 *   'domain' => array('A', 'B')
 *)));
 *</code>
 */


/**
 * Phalcon\Validation\Validator\InclusionIn initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Validator_InclusionIn){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, InclusionIn, validation_validator_inclusionin, phalcon_validation_validator_ce, phalcon_validation_validator_inclusionin_method_entry, 0);

	zend_class_implements(phalcon_validation_validator_inclusionin_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation $validator
 * @param string $attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_InclusionIn, validate){

	zval *validator, *attribute, *value, *option = NULL, *domain;
	zval *message_str = NULL, *joined_domain, *type, *message, *is_set_code, *code;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &validator, &attribute);
	
	PHALCON_INIT_VAR(value);
	phalcon_call_method_p1(value, validator, "getvalue", attribute);
	
	/** 
	 * A domain is an array with a list of valid values
	 */
	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "domain", 1);
	
	PHALCON_INIT_VAR(domain);
	phalcon_call_method_p1(domain, this_ptr, "getoption", option);
	if (Z_TYPE_P(domain) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Option 'domain' must be an array");
		return;
	}
	
	/** 
	 * Check if the value is contained by the array
	 */
	if (!phalcon_fast_in_array(value, domain TSRMLS_CC)) {
	
		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "message", 1);
	
		PHALCON_INIT_VAR(message_str);
		phalcon_call_method_p1(message_str, this_ptr, "getoption", option);
		if (!zend_is_true(message_str)) {
			PHALCON_INIT_VAR(joined_domain);
			phalcon_fast_join_str(joined_domain, SL(", "), domain TSRMLS_CC);
	
			PHALCON_INIT_NVAR(message_str);
			PHALCON_CONCAT_SVSV(message_str, "Value of field '", attribute, "' must be part of list: ", joined_domain);
		}
	
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "InclusionIn", 1);
	
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

		PHALCON_INIT_VAR(message);
		object_init_ex(message, phalcon_validation_message_ce);
		phalcon_call_method_p4_noret(message, "__construct", message_str, attribute, type, code);
	
		phalcon_call_method_p1_noret(validator, "appendmessage", message);
		RETURN_MM_FALSE;
	}
	
	RETURN_MM_TRUE;
}

