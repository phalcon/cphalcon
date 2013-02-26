
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
 * Phalcon\Validation\Validator\PresenceOf
 *
 * Validates that a value is not null or empty string
 */


/**
 * Phalcon\Validation\Validator\PresenceOf initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Validator_PresenceOf){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, PresenceOf, validation_validator_presenceof, "phalcon\\validation\\validator", phalcon_validation_validator_presenceof_method_entry, 0);

	return SUCCESS;
}

/**
 * Executes the validation
 *
 * @param Phalcon\Validator $validator
 * @param string $attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_PresenceOf, validate){

	zval *validator, *attribute, *value, *type, *option;
	zval *message_str = NULL, *message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &validator, &attribute) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(value);
	PHALCON_CALL_METHOD_PARAMS_1(value, validator, "getvalue", attribute);
	if (PHALCON_IS_EMPTY(value)) {
	
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "PresenceOf", 1);
	
		PHALCON_INIT_VAR(option);
		ZVAL_STRING(option, "message", 1);
	
		PHALCON_INIT_VAR(message_str);
		PHALCON_CALL_METHOD_PARAMS_1(message_str, this_ptr, "getoption", option);
		if (!zend_is_true(message_str)) {
			PHALCON_INIT_NVAR(message_str);
			PHALCON_CONCAT_VS(message_str, attribute, " is required");
		}
	
		PHALCON_INIT_VAR(message);
		object_init_ex(message, phalcon_validation_message_ce);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(message, "__construct", message_str, attribute, type);
	
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(validator, "appendmessage", message);
	}
	
	PHALCON_MM_RESTORE();
}

