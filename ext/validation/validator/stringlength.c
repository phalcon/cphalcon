
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

#include "validation/validator/stringlength.h"
#include "validation/validator.h"
#include "validation/validatorinterface.h"
#include "validation/message.h"
#include "validation/exception.h"
#include "validation.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/object.h"

#include "interned-strings.h"

/**
 * Phalcon\Validation\Validator\StringLength
 *
 * Validates that a string has the specified maximum and minimum constraints
 *
 *<code>
 *use Phalcon\Validation\Validator\StringLength as StringLength;
 *
 *$validation->add('name_last', new StringLength(array(
 *      'max' => 50,
 *      'min' => 2,
 *      'messageMaximum' => 'We don\'t like really long names',
 *      'messageMinimum' => 'We want more than just their initials'
 *)));
 *</code>
 *
 */
zend_class_entry *phalcon_validation_validator_stringlength_ce;

PHP_METHOD(Phalcon_Validation_Validator_StringLength, validate);
PHP_METHOD(Phalcon_Validation_Validator_StringLength, valid);

static const zend_function_entry phalcon_validation_validator_stringlength_method_entry[] = {
	PHP_ME(Phalcon_Validation_Validator_StringLength, validate, arginfo_phalcon_validation_validatorinterface_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator_StringLength, valid, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Validation\Validator\StringLength initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Validator_StringLength){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, StringLength, validation_validator_stringlength, phalcon_validation_validator_ce, phalcon_validation_validator_stringlength_method_entry, 0);

	zend_class_implements(phalcon_validation_validator_stringlength_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation $validator
 * @param string $attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_StringLength, validate){

	zval *validator, *attribute, *value = NULL, *allow_empty;
	zval *valid = NULL, *type, *maximum, *minimum, *label;
	zval *code, *pairs, *message_str = NULL, *prepared = NULL, *message;
	zend_class_entry *ce = Z_OBJCE_P(getThis());

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &validator, &attribute);
	
	PHALCON_VERIFY_CLASS_EX(validator, phalcon_validation_ce, phalcon_validation_exception_ce, 1);

	PHALCON_CALL_METHOD(&value, validator, "getvalue", attribute);

	PHALCON_OBS_VAR(allow_empty);
	RETURN_MM_ON_FAILURE(phalcon_validation_validator_getoption_helper(ce, &allow_empty, getThis(), phalcon_interned_allowEmpty TSRMLS_CC));
	if (zend_is_true(allow_empty) && phalcon_validation_validator_isempty_helper(value)) {
		RETURN_MM_TRUE;
	}

	PHALCON_OBS_VAR(maximum);
	RETURN_MM_ON_FAILURE(phalcon_validation_validator_getoption_helper(ce, &maximum, getThis(), "max" TSRMLS_CC));

	PHALCON_OBS_VAR(minimum);
	RETURN_MM_ON_FAILURE(phalcon_validation_validator_getoption_helper(ce, &minimum, getThis(), "min" TSRMLS_CC));

	PHALCON_CALL_SELF(&valid, "valid", value, minimum, maximum);

	if (PHALCON_IS_FALSE(valid)) {
		type = phalcon_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY TSRMLS_CC);

		PHALCON_OBS_VAR(label);
		RETURN_MM_ON_FAILURE(phalcon_validation_validator_getoption_helper(ce, &label, getThis(), phalcon_interned_label TSRMLS_CC));
		if (!zend_is_true(label)) {
			PHALCON_CALL_METHOD(&label, validator, "getlabel", attribute);
			if (!zend_is_true(label)) {
				PHALCON_CPY_WRT(label, attribute);
			}
		}

		PHALCON_OBS_VAR(code);
		RETURN_MM_ON_FAILURE(phalcon_validation_validator_getoption_helper(ce, &code, getThis(), phalcon_interned_code TSRMLS_CC));
		if (Z_TYPE_P(code) == IS_NULL) {
			ZVAL_LONG(code, 0);
		}

		if (phalcon_compare_strict_string(type, SL("TooLong"))) {
			PHALCON_ALLOC_GHOST_ZVAL(pairs);
			array_init_size(pairs, 2);
			Z_ADDREF_P(label); add_assoc_zval_ex(pairs, SS(":field"), label);
			Z_ADDREF_P(maximum); add_assoc_zval_ex(pairs, SS(":max"), maximum);

			PHALCON_OBS_VAR(message_str);
			RETURN_MM_ON_FAILURE(phalcon_validation_validator_getoption_helper(ce, &message_str, getThis(), "messageMaximum" TSRMLS_CC));
			if (!zend_is_true(message_str)) {
				PHALCON_OBSERVE_OR_NULLIFY_VAR(message_str);
				RETURN_MM_ON_FAILURE(phalcon_validation_getdefaultmessage_helper(Z_OBJCE_P(validator), &message_str, validator, "TooLong" TSRMLS_CC));
			}

			PHALCON_CALL_FUNCTION(&prepared, "strtr", message_str, pairs);

			message = phalcon_validation_message_construct_helper(prepared, attribute, "TooLong", code TSRMLS_CC);
		} else {
			PHALCON_ALLOC_GHOST_ZVAL(pairs);
			array_init_size(pairs, 2);
			Z_ADDREF_P(label); add_assoc_zval_ex(pairs, SS(":field"), label);
			Z_ADDREF_P(minimum); add_assoc_zval_ex(pairs, SS(":min"), minimum);

			PHALCON_OBS_VAR(message_str);
			RETURN_MM_ON_FAILURE(phalcon_validation_validator_getoption_helper(ce, &message_str, getThis(), "messageMinimum" TSRMLS_CC));
			if (!zend_is_true(message_str)) {
				PHALCON_OBSERVE_OR_NULLIFY_VAR(message_str);
				RETURN_MM_ON_FAILURE(phalcon_validation_getdefaultmessage_helper(Z_OBJCE_P(validator), &message_str, validator, "TooShort" TSRMLS_CC));
			}

			PHALCON_CALL_FUNCTION(&prepared, "strtr", message_str, pairs);

			message = phalcon_validation_message_construct_helper(prepared, attribute, "TooShort", code TSRMLS_CC);
		}

		Z_DELREF_P(message);

		PHALCON_CALL_METHOD(NULL, validator, "appendmessage", message);
		RETURN_MM_FALSE;
	}
	
	RETURN_MM_TRUE;
}

/**
 * Executes the validation
 *
 * @param string $value
 * @param int $minimum
 * @param int $maximum
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_StringLength, valid){

	zval *value, *minimum = NULL, *maximum = NULL;
	zval *length = NULL, *valid = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &value, &minimum, &maximum);

	if (!minimum) {
		minimum = PHALCON_GLOBAL(z_null);
	}

	if (!maximum) {
		maximum = PHALCON_GLOBAL(z_null);
	}

	/* At least one of 'min' or 'max' must be set */
	if (Z_TYPE_P(minimum) == IS_NULL && Z_TYPE_P(maximum) == IS_NULL) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "A minimum or maximum must be set");
		return;
	}

	/* Check if mbstring is available to calculate the correct length */
	if (phalcon_function_exists_ex(SS("mb_strlen") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_FUNCTION(&length, "mb_strlen", value);
	} else {
		convert_to_string(value);
		PHALCON_INIT_VAR(length);
		ZVAL_LONG(length, Z_STRLEN_P(value));
	}

	/* Maximum length */
	if (Z_TYPE_P(maximum) != IS_NULL) {
		PHALCON_INIT_NVAR(valid);
		is_smaller_function(valid, maximum, length TSRMLS_CC);
		if (PHALCON_IS_TRUE(valid)) {
			phalcon_update_property_string(this_ptr, SL("_type"), SL("TooLong") TSRMLS_CC);
			RETURN_MM_FALSE;
		}
	}

	/* Minimum length */
	if (Z_TYPE_P(minimum) != IS_NULL) {
		PHALCON_INIT_NVAR(valid);
		is_smaller_function(valid, length, minimum TSRMLS_CC);
		if (PHALCON_IS_TRUE(valid)) {
			phalcon_update_property_string(this_ptr, SL("_type"), SL("TooShort") TSRMLS_CC);
			RETURN_MM_FALSE;
		}
	}

	RETURN_MM_TRUE;
}
