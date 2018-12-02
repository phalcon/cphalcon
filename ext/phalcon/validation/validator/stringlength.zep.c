
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
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Validation\Validator\StringLength
 *
 * Validates that a string has the specified maximum and minimum constraints
 * The test is passed if for a string's length L, min<=L<=max, i.e. L must
 * be at least min, and at most max.
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\StringLength as StringLength;
 *
 * $validator = new Validation();
 *
 * $validation->add(
 *     "name_last",
 *     new StringLength(
 *         [
 *             "max"            => 50,
 *             "min"            => 2,
 *             "messageMaximum" => "We don't like really long names",
 *             "messageMinimum" => "We want more than just their initials",
 *         ]
 *     )
 * );
 *
 * $validation->add(
 *     [
 *         "name_last",
 *         "name_first",
 *     ],
 *     new StringLength(
 *         [
 *             "max" => [
 *                 "name_last"  => 50,
 *                 "name_first" => 40,
 *             ],
 *             "min" => [
 *                 "name_last"  => 2,
 *                 "name_first" => 4,
 *             ],
 *             "messageMaximum" => [
 *                 "name_last"  => "We don't like really long last names",
 *                 "name_first" => "We don't like really long first names",
 *             ],
 *             "messageMinimum" => [
 *                 "name_last"  => "We don't like too short last names",
 *                 "name_first" => "We don't like too short first names",
 *             ]
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_StringLength) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, StringLength, phalcon, validation_validator_stringlength, phalcon_validation_validator_ce, phalcon_validation_validator_stringlength_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_StringLength, validate) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *isSetMin = NULL, *isSetMax = NULL, *value = NULL, *length = NULL, *message = NULL, *minimum = NULL, *maximum = NULL, *label = NULL, *replacePairs = NULL, *code = NULL, *_0 = NULL, *_2$$6, *_3$$7, *_4$$8 = NULL, *_5$$8 = NULL, *_6$$8 = NULL, *_7$$9, *_8$$10, *_9$$11 = NULL, *_10$$11 = NULL, *_11$$11 = NULL;

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
	ZVAL_STRING(_0, "min", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&isSetMin, this_ptr, "hasoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "max", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&isSetMax, this_ptr, "hasoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_1 = !zephir_is_true(isSetMin);
	if (_1) {
		_1 = !zephir_is_true(isSetMax);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "A minimum or maximum must be set", "phalcon/validation/validator/stringlength.zep", 95);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, field);
	zephir_check_call_status();
	if ((zephir_function_exists_ex(SS("mb_strlen") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 238, value);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(length);
		ZVAL_LONG(length, zephir_fast_strlen_ev(value));
	}
	if (zephir_is_true(isSetMax)) {
		ZEPHIR_INIT_VAR(_2$$6);
		ZVAL_STRING(_2$$6, "max", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&maximum, this_ptr, "getoption", NULL, 0, _2$$6);
		zephir_check_temp_parameter(_2$$6);
		zephir_check_call_status();
		if (Z_TYPE_P(maximum) == IS_ARRAY) {
			zephir_array_fetch(&_3$$7, maximum, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/stringlength.zep", 116 TSRMLS_CC);
			ZEPHIR_CPY_WRT(maximum, _3$$7);
		}
		if (ZEPHIR_GT(length, maximum)) {
			ZEPHIR_INIT_VAR(_4$$8);
			ZVAL_STRING(_4$$8, "TooLong", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_5$$8);
			ZVAL_STRING(_5$$8, "messageMaximum", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, _4$$8, _5$$8);
			zephir_check_temp_parameter(_4$$8);
			zephir_check_temp_parameter(_5$$8);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_4$$8);
			object_init_ex(_4$$8, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_6$$8, "strtr", NULL, 27, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_5$$8);
			ZVAL_STRING(_5$$8, "TooLong", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _4$$8, "__construct", NULL, 478, _6$$8, field, _5$$8, code);
			zephir_check_temp_parameter(_5$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _4$$8);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	if (zephir_is_true(isSetMin)) {
		ZEPHIR_INIT_VAR(_7$$9);
		ZVAL_STRING(_7$$9, "min", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&minimum, this_ptr, "getoption", NULL, 0, _7$$9);
		zephir_check_temp_parameter(_7$$9);
		zephir_check_call_status();
		if (Z_TYPE_P(minimum) == IS_ARRAY) {
			zephir_array_fetch(&_8$$10, minimum, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/stringlength.zep", 142 TSRMLS_CC);
			ZEPHIR_CPY_WRT(minimum, _8$$10);
		}
		if (ZEPHIR_LT(length, minimum)) {
			ZEPHIR_INIT_VAR(_9$$11);
			ZVAL_STRING(_9$$11, "TooShort", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_10$$11);
			ZVAL_STRING(_10$$11, "messageMinimum", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, _9$$11, _10$$11);
			zephir_check_temp_parameter(_9$$11);
			zephir_check_temp_parameter(_10$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":min"), &minimum, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_9$$11);
			object_init_ex(_9$$11, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_11$$11, "strtr", NULL, 27, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_10$$11);
			ZVAL_STRING(_10$$11, "TooShort", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _9$$11, "__construct", NULL, 478, _11$$11, field, _10$$11, code);
			zephir_check_temp_parameter(_10$$11);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _9$$11);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

