
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Phalcon\Validation\Validator\Identical
 *
 * Checks if a value is identical to other
 *
 *<code>
 *use Phalcon\Validation\Validator\Identical;
 *
 *$validator->add('terms', new Identical(array(
 *   'accepted' => 'yes',
 *   'message' => 'Terms and conditions must be accepted'
 *)));
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Identical) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Identical, phalcon, validation_validator_identical, phalcon_validation_validator_ce, phalcon_validation_validator_identical_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Identical, validate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool valid;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *message = NULL, *label = NULL, *replacePairs, *value = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4;

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
	ZVAL_STRING(_1, "accepted", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasoption", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "accepted", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getoption", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		valid = ZEPHIR_IS_EQUAL(value, _2);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "value", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "hasoption", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (zephir_is_true(_2)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "value", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "getoption", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			valid = ZEPHIR_IS_EQUAL(value, _3);
		}
	}
	if (!(valid)) {
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
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "Identical", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 54, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "Identical", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 435, _2, field, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _1);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

