
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

#include "validation/validator/inclusionin.h"
#include "validation/validator.h"
#include "validation/validatorinterface.h"
#include "validation/message.h"
#include "validation/exception.h"
#include "validation.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"

#include "interned-strings.h"

/**
 * Phalcon\Validation\Validator\InclusionIn
 *
 * Check if a value is included into a list of values
 *
 *<code>
 *use Phalcon\Validation\Validator\InclusionIn;
 *
 *$validator->add('status', new InclusionIn(array(
 *   'message' => 'The status must be A or B',
 *   'domain' => array('A', 'B')
 *)));
 *</code>
 */
zend_class_entry *phalcon_validation_validator_inclusionin_ce;

PHP_METHOD(Phalcon_Validation_Validator_InclusionIn, validate);

static const zend_function_entry phalcon_validation_validator_inclusionin_method_entry[] = {
	PHP_ME(Phalcon_Validation_Validator_InclusionIn, validate, arginfo_phalcon_validation_validatorinterface_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Validation\Validator\InclusionIn initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Validator_InclusionIn){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, InclusionIn, validation_validator_inclusionin, phalcon_validation_validator_ce, phalcon_validation_validator_inclusionin_method_entry, 0);

	zend_class_implements(phalcon_validation_validator_inclusionin_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation $validator
 * @param string $attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_InclusionIn, validate){

	zval *validator, *attribute, *value, *domain;
	zval *message_str, *joined_domain, *message, *code;
	zval *allow_empty, *label, *pairs, *prepared;
	zend_class_entry *ce = Z_OBJCE_P(getThis());

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &validator, &attribute);
	
	PHALCON_VERIFY_CLASS_EX(validator, phalcon_validation_ce, phalcon_validation_exception_ce, 1);

	PHALCON_OBS_VAR(value);
	phalcon_call_method_p1_ex(value, &value, validator, "getvalue", attribute);

	PHALCON_INIT_VAR(allow_empty);
	RETURN_MM_ON_FAILURE(phalcon_validation_validator_getoption_helper(ce, allow_empty, getThis(), phalcon_interned_allowEmpty TSRMLS_CC));
	if (zend_is_true(allow_empty) && phalcon_validation_validator_isempty_helper(value)) {
		RETURN_MM_TRUE;
	}

	/* A domain is an array with a list of valid values */
	PHALCON_INIT_VAR(domain);
	RETURN_MM_ON_FAILURE(phalcon_validation_validator_getoption_helper(ce, domain, getThis(), phalcon_interned_domain TSRMLS_CC));
	if (Z_TYPE_P(domain) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Option 'domain' must be an array");
		return;
	}
	
	/** 
	 * Check if the value is contained by the array
	 */
	if (!phalcon_fast_in_array(value, domain TSRMLS_CC)) {

		PHALCON_INIT_VAR(label);
		RETURN_MM_ON_FAILURE(phalcon_validation_validator_getoption_helper(ce, label, getThis(), phalcon_interned_label TSRMLS_CC));
		if (!zend_is_true(label)) {
			PHALCON_CPY_WRT(label, attribute);
		}

		ALLOC_INIT_ZVAL(joined_domain);
		phalcon_fast_join_str(joined_domain, SL(", "), domain TSRMLS_CC);

		PHALCON_ALLOC_GHOST_ZVAL(pairs);
		array_init_size(pairs, 2);
		Z_ADDREF_P(label); add_assoc_zval_ex(pairs, SS(":field"), label);
		add_assoc_zval_ex(pairs, SS(":domain"), joined_domain);

		PHALCON_INIT_VAR(message_str);
		RETURN_MM_ON_FAILURE(phalcon_validation_validator_getoption_helper(ce, message_str, getThis(), phalcon_interned_message TSRMLS_CC));
		if (!zend_is_true(message_str)) {
			PHALCON_INIT_NVAR(message_str);
			RETURN_MM_ON_FAILURE(phalcon_validation_getdefaultmessage_helper(Z_OBJCE_P(validator), message_str, validator, "InclusionIn" TSRMLS_CC));
		}
	
		PHALCON_INIT_VAR(code);
		RETURN_MM_ON_FAILURE(phalcon_validation_validator_getoption_helper(ce, code, getThis(), phalcon_interned_code TSRMLS_CC));
		if (Z_TYPE_P(code) == IS_NULL) {
			ZVAL_LONG(code, 0);
		}

		PHALCON_OBS_VAR(prepared);
		PHALCON_CALL_FUNCTION(&prepared, "strtr", message_str, pairs);

		message = phalcon_validation_message_construct_helper(prepared, attribute, "InclusionIn", code TSRMLS_CC);
		Z_DELREF_P(message);
	
		phalcon_call_method_p1_noret(validator, "appendmessage", message);
		RETURN_MM_FALSE;
	}
	
	RETURN_MM_TRUE;
}
