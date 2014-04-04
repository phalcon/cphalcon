
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

#include "mvc/model/validator/json.h"
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
 * Phalcon\Mvc\Model\Validator\Json
 *
 * Allows to validate if json fields has correct values
 *
 *<code>
 *	use Phalcon\Mvc\Model\Validator\Json as JsonValidator;
 *
 *	class Subscriptors extends Phalcon\Mvc\Model
 *	{
 *
 *		public function validation()
 *		{
 *			$this->validate(new JsonValidator(array(
 *				'field' => 'json_data'
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
zend_class_entry *phalcon_mvc_model_validator_json_ce;

PHP_METHOD(Phalcon_Mvc_Model_Validator_Json, validate);

static const zend_function_entry phalcon_mvc_model_validator_json_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Validator_Json, validate, arginfo_phalcon_mvc_model_validatorinterface_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Validator\Json initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Json){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Json, mvc_model_validator_json, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_json_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_json_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\ModelInterface $record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Json, validate){

	zval *record, *option = NULL, *field_name = NULL, *invalid = NULL;
	zval *value = NULL, *keys = NULL, *assoc, *json = NULL, *constant, *ret = NULL;
	zval *message = NULL, *type, *is_set_code = NULL, *code = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &record);
	
	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "field", 1);
	
	PHALCON_CALL_METHOD(&field_name, this_ptr, "getoption", option);
	if (Z_TYPE_P(field_name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Field name must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(invalid);
	ZVAL_BOOL(invalid, 0);
	
	PHALCON_CALL_METHOD(&value, record, "readattribute", field_name);
	
	PHALCON_INIT_VAR(assoc);
	ZVAL_TRUE(assoc);

	PHALCON_CALL_FUNCTION(&json, "json_decode", value, assoc);
	
	if (Z_TYPE_P(json) == IS_NULL) {
		PHALCON_INIT_VAR(constant);
		if (zend_get_constant(SL("JSON_ERROR_NONE"), constant TSRMLS_CC)) {
			PHALCON_INIT_NVAR(ret);
			PHALCON_CALL_FUNCTION(&ret, "json_last_error");

			if (!PHALCON_IS_EQUAL(ret, constant)) {
				PHALCON_INIT_NVAR(invalid);
				ZVAL_BOOL(invalid, 1);
			}
		}
	}

	if (!PHALCON_IS_TRUE(invalid)) {
		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "keys", 1);

		PHALCON_CALL_METHOD(&keys, this_ptr, "getoption", option);

		if (Z_TYPE_P(keys) != IS_NULL) {
			PHALCON_INIT_NVAR(ret);
			PHALCON_CALL_FUNCTION(&ret, "array_key_exists", keys, json);
			if (!zend_is_true(ret)) {
				PHALCON_INIT_NVAR(invalid);
				ZVAL_BOOL(invalid, 1);
			}
		}
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
			PHALCON_CONCAT_SVS(message, "Value of field '", field_name, "' must have a valid json format");
		}
	
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "Json", 1);

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

