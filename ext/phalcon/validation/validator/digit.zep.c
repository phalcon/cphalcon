
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Phalcon\Validation\Validator\Digit
 *
 * Check for numeric character(s)
 *
 * <code>
 * use Phalcon\Validation\Validator\Digit as DigitValidator;
 *
 * $validator->add('height', new DigitValidator([
 *     'message' => ':field must be numeric'
 * ]));
 *
 * $validator->add(['height', 'width'], new DigitValidator([
 *     'message' => [
 *         'height' => 'height must be numeric',
 *         'width' => 'width must be numeric'
 *     ]
 * ]));
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Digit) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Digit, phalcon, validation_validator_digit, phalcon_validation_validator_ce, phalcon_validation_validator_digit_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Digit, validate) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *code = NULL, *_1 = NULL, *_2 = NULL, *_7 = NULL, *_8, *_3$$4, *_4$$6, *_5$$7, *_6$$8;

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
	_0 = Z_TYPE_P(value) == IS_LONG;
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "ctype_digit", NULL, 469, value);
		zephir_check_call_status();
		_0 = zephir_is_true(_1);
	}
	if (_0) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "label", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (Z_TYPE_P(label) == IS_ARRAY) {
		zephir_array_fetch(&_3$$4, label, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/digit.zep", 64 TSRMLS_CC);
		ZEPHIR_CPY_WRT(label, _3$$4);
	}
	if (ZEPHIR_IS_EMPTY(label)) {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "message", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (Z_TYPE_P(message) == IS_ARRAY) {
		zephir_array_fetch(&_4$$6, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/digit.zep", 72 TSRMLS_CC);
		ZEPHIR_CPY_WRT(message, _4$$6);
	}
	ZEPHIR_INIT_VAR(replacePairs);
	zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
	if (ZEPHIR_IS_EMPTY(message)) {
		ZEPHIR_INIT_VAR(_5$$7);
		ZVAL_STRING(_5$$7, "Digit", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _5$$7);
		zephir_check_temp_parameter(_5$$7);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "code", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&code, this_ptr, "getoption", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (Z_TYPE_P(code) == IS_ARRAY) {
		zephir_array_fetch(&_6$$8, code, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/digit.zep", 81 TSRMLS_CC);
		ZEPHIR_CPY_WRT(code, _6$$8);
	}
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_validation_message_ce);
	ZEPHIR_CALL_FUNCTION(&_7, "strtr", NULL, 26, message, replacePairs);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	ZVAL_STRING(_8, "Digit", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 462, _7, field, _8, code);
	zephir_check_temp_parameter(_8);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _2);
	zephir_check_call_status();
	RETURN_MM_BOOL(0);

}

