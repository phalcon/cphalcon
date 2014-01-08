
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

#include "validation/validator/between.h"
#include "validation/validator.h"
#include "validation/validatorinterface.h"
#include "validation/message.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"

/**
 * Phalcon\Validation\Validator\Url
 *
 * Checks if a value has a correct URL format
 *
 *<code>
 *use Phalcon\Validation\Validator\Url as UrlValidator;
 *
 *$validator->add('url', new UrlValidator(array(
 *   'message' => 'The url is not valid'
 *)));
 *</code>
 */
zend_class_entry *phalcon_validation_validator_url_ce;

PHP_METHOD(Phalcon_Validation_Validator_Url, validate);

static const zend_function_entry phalcon_validation_validator_url_method_entry[] = {
	PHP_ME(Phalcon_Validation_Validator_Url, validate, arginfo_phalcon_validation_validatorinterface_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Validation\Validator\Url initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Validator_Url){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Url, validation_validator_url, phalcon_validation_validator_ce, phalcon_validation_validator_url_method_entry, 0);

	zend_class_implements(phalcon_validation_validator_url_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation $validator
 * @param string $attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_Url, validate){

	zval *validator, *attribute, *value, *validate_url;
	zval *validation, *option, *message_str = NULL, *type;
	zval *message, *is_set_code, *code;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &validator, &attribute);
	
	PHALCON_INIT_VAR(value);
	phalcon_call_method_p1(value, validator, "getvalue", attribute);
	
	PHALCON_INIT_VAR(validate_url);
	ZVAL_LONG(validate_url, 273);
	
	PHALCON_INIT_VAR(validation);
	phalcon_call_func_p2(validation, "filter_var", value, validate_url);
	if (!zend_is_true(validation)) {
	
		PHALCON_INIT_VAR(option);
		ZVAL_STRING(option, "message", 1);
	
		PHALCON_INIT_VAR(message_str);
		phalcon_call_method_p1(message_str, this_ptr, "getoption", option);
		if (!zend_is_true(message_str)) {
			PHALCON_INIT_NVAR(message_str);
			PHALCON_CONCAT_SVS(message_str, "Value of field '", attribute, "' must have a valid url format");
		}
	
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "Url", 1);
	
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
