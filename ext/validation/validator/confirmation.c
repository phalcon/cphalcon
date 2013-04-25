
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
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Validation\Validator\Confirmation
 *
 * Checks that two values have the same value
 *
 *<code>
 *use Phalcon\Validation\Validator\Confirmation;
 *
 *$validator->add('password', new Confirmation(array(
 *   'message' => 'Password doesn\'t match confirmation',
 *   'with' => 'confirmPassword'
 *)));
 *</code>
 */


/**
 * Phalcon\Validation\Validator\Confirmation initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Validator_Confirmation){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Confirmation, validation_validator_confirmation, "phalcon\\validation\\validator", phalcon_validation_validator_confirmation_method_entry, 0);

	zend_class_implements(phalcon_validation_validator_confirmation_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation $validator
 * @param string $attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_Confirmation, validate){

	zval *validator, *attribute, *with, *with_attribute;
	zval *value, *with_value, *option, *message_str = NULL;
	zval *type, *message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &validator, &attribute) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(with);
	ZVAL_STRING(with, "with", 1);
	
	PHALCON_INIT_VAR(with_attribute);
	PHALCON_CALL_METHOD_PARAMS_1(with_attribute, this_ptr, "getoption", with);
	
	PHALCON_INIT_VAR(value);
	PHALCON_CALL_METHOD_PARAMS_1(value, validator, "getvalue", attribute);
	
	PHALCON_INIT_VAR(with_value);
	PHALCON_CALL_METHOD_PARAMS_1(with_value, validator, "getvalue", with_attribute);
	if (!PHALCON_IS_EQUAL(value, with_value)) {
	
		PHALCON_INIT_VAR(option);
		ZVAL_STRING(option, "message", 1);
	
		PHALCON_INIT_VAR(message_str);
		PHALCON_CALL_METHOD_PARAMS_1(message_str, this_ptr, "getoption", option);
		if (!zend_is_true(message_str)) {
			PHALCON_INIT_NVAR(message_str);
			PHALCON_CONCAT_SVSVS(message_str, "Value of '", attribute, "' and '", with, "' don't match");
		}
	
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "Confirmation", 1);
	
		PHALCON_INIT_VAR(message);
		object_init_ex(message, phalcon_validation_message_ce);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(message, "__construct", message_str, attribute, type);
	
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(validator, "appendmessage", message);
		RETURN_MM_FALSE;
	}
	
	RETURN_MM_TRUE;
}

