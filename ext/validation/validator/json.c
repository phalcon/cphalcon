
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
  | obtain it through the world-wide-web, please send an json             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
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
#include "kernel/concat.h"

/**
 * Phalcon\Validation\Validator\Json
 *
 * Checks if a value has a correct json format
 *
 *<code>
 *use Phalcon\Validation\Validator\Json as JsonValidator;
 *
 *$validator->add('json', new JsonValidator(array(
 *   'message' => 'The data is not valid'
 *)));
 *</code>
 */


/**
 * Phalcon\Validation\Validator\Json initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Validator_Json){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Json, validation_validator_json, phalcon_validation_validator_ce, phalcon_validation_validator_json_method_entry, 0);

	zend_class_implements(phalcon_validation_validator_json_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation $validator
 * @param string $attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_Json, validate){

	zval *validator, *attribute, *value, *assoc, *keys, *ret;
	zval *validation, *option, *message_str = NULL, *type;
	zval *message, *is_set_code, *code;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &validator, &attribute);
	
	PHALCON_INIT_VAR(value);
	phalcon_call_method_p1(value, validator, "getvalue", attribute);
	
	PHALCON_INIT_VAR(assoc);
	ZVAL_TRUE(assoc);
	
	PHALCON_INIT_VAR(validation);
	phalcon_call_func_p2(validation, "json_decode", value, assoc);
	if (zend_is_true(validation)) {

		PHALCON_INIT_VAR(option);
		ZVAL_STRING(option, "keys", 1);
			
		PHALCON_INIT_VAR(keys);
		phalcon_call_method_p1(keys, this_ptr, "getoption", option);
		if (Z_TYPE_P(keys) == IS_ARRAY) {
			PHALCON_INIT_VAR(ret);
			phalcon_call_func_p2(ret, "array_key_exists", keys, validation);
			if (zend_is_true(validation)) {
				RETURN_MM_TRUE;
			}
		}
	}
	
	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "message", 1);

	PHALCON_INIT_VAR(message_str);
	phalcon_call_method_p1(message_str, this_ptr, "getoption", option);
	if (!zend_is_true(message_str)) {
		PHALCON_INIT_NVAR(message_str);
		PHALCON_CONCAT_SVS(message_str, "Value of field '", attribute, "' must have a valid json format");
	}

	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "Json", 1);

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

