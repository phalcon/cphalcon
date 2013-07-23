
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Validation\Validator\Regex
 *
 * Allows validate if the value of a field matches a regular expression
 *
 *<code>
 *use Phalcon\Validation\Validator\Regex as RegexValidator;
 *
 *$validator->add('created_at', new RegexValidator(array(
 *   'pattern' => '/^[0-9]{4}[-\/](0[1-9]|1[12])[-\/](0[1-9]|[12][0-9]|3[01])$/',
 *   'message' => 'The creation date is invalid'
 *)));
 *</code>
 */


/**
 * Phalcon\Validation\Validator\Regex initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Validator_Regex){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Regex, validation_validator_regex, "phalcon\\validation\\validator", phalcon_validation_validator_regex_method_entry, 0);

	zend_class_implements(phalcon_validation_validator_regex_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation $validator
 * @param string $attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_Regex, validate){

	zval *validator, *attribute, *value, *option = NULL, *pattern;
	zval *matches, *match_pattern, *match_zero, *failed = NULL;
	zval *message_str = NULL, *type, *message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &validator, &attribute);
	
	PHALCON_INIT_VAR(value);
	phalcon_call_method_p1(value, validator, "getvalue", attribute);
	
	/** 
	 * The regular expression is set in the option 'pattern'
	 */
	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "pattern", 1);
	
	PHALCON_INIT_VAR(pattern);
	phalcon_call_method_p1(pattern, this_ptr, "getoption", option);
	
	PHALCON_INIT_VAR(matches);
	
	/** 
	 * Check if the value match using preg_match in the PHP userland
	 */
	PHALCON_INIT_VAR(match_pattern);
	phalcon_preg_match(match_pattern, pattern, value, matches TSRMLS_CC);
	
	if (zend_is_true(match_pattern)) {
		PHALCON_OBS_VAR(match_zero);
		phalcon_array_fetch_long(&match_zero, matches, 0, PH_NOISY);
	
		PHALCON_INIT_VAR(failed);
		is_not_equal_function(failed, match_zero, value TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(failed);
		ZVAL_BOOL(failed, 1);
	}
	
	if (PHALCON_IS_TRUE(failed)) {
	
		/** 
		 * Check if the developer has defined a custom message
		 */
		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "message", 1);
	
		PHALCON_INIT_VAR(message_str);
		phalcon_call_method_p1(message_str, this_ptr, "getoption", option);
		if (!zend_is_true(message_str)) {
			PHALCON_INIT_NVAR(message_str);
			PHALCON_CONCAT_SVS(message_str, "Value of field '", attribute, "' doesn't match regular expression");
		}
	
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "Regex", 1);
	
		PHALCON_INIT_VAR(message);
		object_init_ex(message, phalcon_validation_message_ce);
		phalcon_call_method_p3_noret(message, "__construct", message_str, attribute, type);
	
		phalcon_call_method_p1_noret(validator, "appendmessage", message);
		RETURN_MM_FALSE;
	}
	
	RETURN_MM_TRUE;
}

