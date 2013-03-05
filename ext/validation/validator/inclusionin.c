
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
#include "kernel/concat.h"

/**
 * Phalcon\Validation\Validator\InclusionIn
 *
 * Check if a value is included into a list of values
 */


/**
 * Phalcon\Validation\Validator\InclusionIn initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Validator_InclusionIn){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, InclusionIn, validation_validator_inclusionin, "phalcon\\validation\\validator", phalcon_validation_validator_inclusionin_method_entry, 0);

	return SUCCESS;
}

/**
 * Executes the validation
 *
 * @param Phalcon\Validator $validator
 * @param string $attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_InclusionIn, validate){

	zval *validator, *attribute, *value, *option = NULL, *domain;
	zval *in_array, *message_str = NULL, *joined_domain;
	zval *type, *message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &validator, &attribute) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(value);
	PHALCON_CALL_METHOD_PARAMS_1(value, validator, "getvalue", attribute);
	
	/** 
	 * A domain is an array with a list of valid values
	 */
	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "domain", 1);
	
	PHALCON_INIT_VAR(domain);
	PHALCON_CALL_METHOD_PARAMS_1(domain, this_ptr, "getoption", option);
	if (Z_TYPE_P(domain) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Option 'domain' must be an array");
		return;
	}
	
	/** 
	 * Check if the value is contained by the array
	 */
	PHALCON_INIT_VAR(in_array);
	PHALCON_CALL_FUNC_PARAMS_2(in_array, "in_array", value, domain);
	if (!zend_is_true(in_array)) {
	
		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "message", 1);
	
		PHALCON_INIT_VAR(message_str);
		PHALCON_CALL_METHOD_PARAMS_1(message_str, this_ptr, "getoption", option);
		if (!zend_is_true(message_str)) {
			PHALCON_INIT_VAR(joined_domain);
			phalcon_fast_join_str(joined_domain, SL(", "), domain TSRMLS_CC);
	
			PHALCON_INIT_NVAR(message_str);
			PHALCON_CONCAT_SVSV(message_str, "Value of field '", attribute, "' must be part of list: ", joined_domain);
		}
	
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "InclusionIn", 1);
	
		PHALCON_INIT_VAR(message);
		object_init_ex(message, phalcon_validation_message_ce);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(message, "__construct", message_str, attribute, type);
	
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(validator, "appendmessage", message);
	}
	
	PHALCON_MM_RESTORE();
}

