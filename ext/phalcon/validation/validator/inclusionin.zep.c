
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_InclusionIn) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, InclusionIn, phalcon, validation_validator_inclusionin, phalcon_validation_validator_ce, phalcon_validation_validator_inclusionin_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_InclusionIn, validate) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *domain = NULL, *message = NULL, *label = NULL, *replacePairs, *strict = NULL, *_0 = NULL, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "allowEmpty", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "issetoption", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_2 = zephir_is_true(_0);
	if (_2) {
		_2 = ZEPHIR_IS_EMPTY(value);
	}
	if (_2) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "domain", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&domain, this_ptr, "getoption", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (Z_TYPE_P(domain) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'domain' must be an array", "phalcon/validation/validator/inclusionin.zep", 61);
		return;
	}
	ZEPHIR_INIT_VAR(strict);
	ZVAL_BOOL(strict, 0);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "strict", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "issetoption", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		if (Z_TYPE_P(strict) != IS_BOOL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'strict' must be a boolean", "phalcon/validation/validator/inclusionin.zep", 67);
			return;
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "strict", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&strict, this_ptr, "getoption", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_4, "in_array", NULL, 352, value, domain, strict);
	zephir_check_call_status();
	if (!(zephir_is_true(_4))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_1);
		zephir_fast_join_str(_1, SL(", "), domain TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":domain"), &_1, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "InclusionIn", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_5, "strtr", NULL, 73, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "InclusionIn", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 425, _5, field, _6);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _1);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

