
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

#include "mvc/model/validator/numericality.h"
#include "mvc/model/validator.h"
#include "mvc/model/validatorinterface.h"
#include "mvc/model/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

#include "interned-strings.h"

/**
 * Phalcon\Mvc\Model\Validator\Numericality
 *
 * Allows to validate if a field has a valid numeric format
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\Numericality as NumericalityValidator;
 *
 *class Products extends Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      $this->validate(new NumericalityValidator(array(
 *          'field' => 'price'
 *      )));
 *      if ($this->validationHasFailed() == true) {
 *          return false;
 *      }
 *  }
 *
 *}
 *</code>
 *
 */
zend_class_entry *phalcon_mvc_model_validator_numericality_ce;

PHP_METHOD(Phalcon_Mvc_Model_Validator_Numericality, validate);

static const zend_function_entry phalcon_mvc_model_validator_numericality_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Validator_Numericality, validate, arginfo_phalcon_mvc_model_validatorinterface_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Validator\Numericality initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Numericality){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Numericality, mvc_model_validator_numericality, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_numericality_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_numericality_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\ModelInterface $record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Numericality, validate){

	zval *record, *option = NULL, *field = NULL, *value = NULL, *message = NULL;
	zval *type, *is_set_code = NULL, *code = NULL;
	zval *allow_empty = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &record);
	
	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "field", 1);
	
	PHALCON_CALL_METHOD(&field, this_ptr, "getoption", option);
	if (Z_TYPE_P(field) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Field name must be a string");
		return;
	}
	
	PHALCON_CALL_METHOD(&value, record, "readattribute", field);

	/*
	 * Allow empty
	 */
	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "allowEmpty", 1);

	PHALCON_CALL_METHOD(&allow_empty, this_ptr, "getoption", option);
	if (allow_empty && zend_is_true(allow_empty) && PHALCON_IS_EMPTY(value)) {
		RETURN_MM_TRUE;
	}
	
	/** 
	 * Check if the value is numeric using is_numeric in the PHP userland
	 */
	if (!phalcon_is_numeric(value)) {
	
		/** 
		 * Check if the developer has defined a custom message
		 */
		PHALCON_INIT_NVAR(option);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(option, phalcon_interned_message);
	
		PHALCON_CALL_METHOD(&message, this_ptr, "getoption", option);
		if (!zend_is_true(message)) {
			PHALCON_INIT_NVAR(message);
			PHALCON_CONCAT_SVS(message, "Value of field '", field, "' must be numeric");
		}
	
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "Numericality", 1);

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

		PHALCON_CALL_METHOD(NULL, this_ptr, "appendmessage", message, field, type, code);
		RETURN_MM_FALSE;
	}
	
	RETURN_MM_TRUE;
}

