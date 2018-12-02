
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
#include "kernel/object.h"


/**
 * Phalcon\Validation\Validator\Confirmation
 *
 * Checks that two values have the same value
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Confirmation;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "password",
 *     new Confirmation(
 *         [
 *             "message" => "Password doesn't match confirmation",
 *             "with"    => "confirmPassword",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "password",
 *         "email",
 *     ],
 *     new Confirmation(
 *         [
 *             "message" => [
 *                 "password" => "Password doesn't match confirmation",
 *                 "email"    => "Email doesn't match confirmation",
 *             ],
 *             "with" => [
 *                 "password" => "confirmPassword",
 *                 "email"    => "confirmEmail",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Confirmation) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Confirmation, phalcon, validation_validator_confirmation, phalcon_validation_validator_ce, phalcon_validation_validator_confirmation_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Confirmation, validate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *fieldWith = NULL, *value = NULL, *valueWith = NULL, *message = NULL, *label = NULL, *labelWith = NULL, *replacePairs = NULL, *code = NULL, *_0, *_2 = NULL, *_1$$3, *_3$$4 = NULL, *_5$$4 = NULL, *_6$$4, *_4$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "with", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&fieldWith, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(fieldWith) == IS_ARRAY) {
		zephir_array_fetch(&_1$$3, fieldWith, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/confirmation.zep", 81 TSRMLS_CC);
		ZEPHIR_CPY_WRT(fieldWith, _1$$3);
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&valueWith, validation, "getvalue", NULL, 0, fieldWith);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "compare", NULL, 481, value, valueWith);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_STRING(_3$$4, "Confirmation", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, _3$$4);
		zephir_check_temp_parameter(_3$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, field);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3$$4);
		ZVAL_STRING(_3$$4, "labelWith", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&labelWith, this_ptr, "getoption", NULL, 0, _3$$4);
		zephir_check_temp_parameter(_3$$4);
		zephir_check_call_status();
		if (Z_TYPE_P(labelWith) == IS_ARRAY) {
			zephir_array_fetch(&_4$$5, labelWith, fieldWith, PH_NOISY | PH_READONLY, "phalcon/validation/validator/confirmation.zep", 94 TSRMLS_CC);
			ZEPHIR_CPY_WRT(labelWith, _4$$5);
		}
		if (ZEPHIR_IS_EMPTY(labelWith)) {
			ZEPHIR_CALL_METHOD(&labelWith, validation, "getlabel", NULL, 0, fieldWith);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replacePairs, SL(":with"), &labelWith, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_3$$4);
		object_init_ex(_3$$4, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_5$$4, "strtr", NULL, 27, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6$$4);
		ZVAL_STRING(_6$$4, "Confirmation", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", NULL, 478, _5$$4, field, _6$$4, code);
		zephir_check_temp_parameter(_6$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _3$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Compare strings
 */
PHP_METHOD(Phalcon_Validation_Validator_Confirmation, compare) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, *b_param = NULL, *_0 = NULL, *_1, *_2, _3$$3 = zval_used_for_init, *_4$$3 = NULL, *_5$$3 = NULL;
	zval *a = NULL, *b = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a_param, &b_param);

	zephir_get_strval(a, a_param);
	zephir_get_strval(b, b_param);


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "ignoreCase", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		if (!((zephir_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Extension 'mbstring' is required", "phalcon/validation/validator/confirmation.zep", 128);
			return;
		}
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_STRING(&_3$$3, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "mb_strtolower", NULL, 215, a, &_3$$3);
		zephir_check_call_status();
		zephir_get_strval(a, _4$$3);
		ZEPHIR_SINIT_NVAR(_3$$3);
		ZVAL_STRING(&_3$$3, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "mb_strtolower", NULL, 215, b, &_3$$3);
		zephir_check_call_status();
		zephir_get_strval(b, _5$$3);
	}
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(a, b));

}

