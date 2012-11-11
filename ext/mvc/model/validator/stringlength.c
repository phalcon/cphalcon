
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
  |          Jason Rice                                                    |
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
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Model\Validator\StringLength
 *
 * Simply validates specified string length constraints
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\StringLength as StringLengthValidator;
 *
 *class Subscriptors extends Phalcon\Mvc\Model
 *{
 *
 *	public function validation()
 *	{
 *		$this->validate(new StringLengthValidator(array(
 *			'field' => 'name_last',
 *			'max' => 50, //we don't like really long names
 *			'min' => 2, //we want more than just their initials
 *		)));
 *		if ($this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 *
 */


/**
 * Phalcon\Mvc\Model\Validator\StringLength initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_StringLength){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, StringLength, mvc_model_validator_stringlength, "phalcon\\mvc\\model\\validator", phalcon_mvc_model_validator_stringlength_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_stringlength_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\ModelInterface $record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_StringLength, validate){

	zval *record = NULL, *field_name = NULL, *value_length = NULL, *value = NULL, *failed = NULL;
	zval *min = NULL, *max = NULL;
	zval *min_is_set = NULL, *max_is_set = NULL;
	zval *message0 = NULL, *message1 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "field", 1);
	PHALCON_INIT_VAR(field_name);
	PHALCON_CALL_METHOD_PARAMS_1(field_name, this_ptr, "getoption", c0, PH_NO_CHECK);
	if (Z_TYPE_P(field_name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Field name must be a string");
		return;
	}

	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "max", 1);

	PHALCON_INIT_VAR(max_is_set);
	PHALCON_CALL_METHOD_PARAMS_1(max_is_set, this_ptr, "issetoption", c1, PH_NO_CHECK);

	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "min", 1);

	PHALCON_INIT_VAR(min_is_set);
	PHALCON_CALL_METHOD_PARAMS_1(min_is_set, this_ptr, "issetoption", c2, PH_NO_CHECK);
	if (!zend_is_true(max_is_set) && !zend_is_true(min_is_set)) {
		//the user didn't specify a min or a max... time to throw up
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A minimum or maximum must be set.");
		return;
	}

	PHALCON_INIT_VAR(value);
	PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", field_name, PH_NO_CHECK);

	PHALCON_INIT_VAR(value_length);
	PHALCON_CALL_FUNC_PARAMS_1(value_length, "strlen", value);

	PHALCON_INIT_VAR(failed);
	ZVAL_BOOL(failed, 0);

	//validate the max
	if (zend_is_true(max_is_set)) {
		PHALCON_INIT_VAR(max);
		PHALCON_CALL_METHOD_PARAMS_1(max, this_ptr, "getoption", c1, PH_NO_CHECK);
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, max, value_length TSRMLS_CC);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(message0);
			PHALCON_CONCAT_SVSVS(message0, "Value of field '", field_name, "' exceeds the maximum ", max, " characters");
			PHALCON_INIT_VAR(c3);
			ZVAL_STRING(c3, "too_long", 1);

			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", message0, field_name, c3, PH_NO_CHECK);

			ZVAL_BOOL(failed, 1);
		}
	}

	//validate the min
	if (zend_is_true(min_is_set)) {
		PHALCON_INIT_VAR(min);
		PHALCON_CALL_METHOD_PARAMS_1(min, this_ptr, "getoption", c2, PH_NO_CHECK);
		PHALCON_INIT_VAR(r1);
		is_smaller_function(r1, value_length, min TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_INIT_VAR(message1);
			PHALCON_CONCAT_SVSVS(message1, "Value of field '", field_name, "' is less than the minimum ", min, " characters");
			PHALCON_INIT_VAR(c4);
			ZVAL_STRING(c4, "too_short", 1);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", message1, field_name, c4, PH_NO_CHECK);

			ZVAL_BOOL(failed, 1);
		}
	}

	if (zend_is_true(failed)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}

	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

