
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
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *isSetMin = NULL, *isSetMax = NULL, *value = NULL, *length = NULL, *message = NULL, *minimum = NULL, *maximum = NULL, *label = NULL, *replacePairs = NULL, *_0 = NULL, *_2$$7, *_3$$8 = NULL, *_5$$8 = NULL, *_7$$8 = NULL, *_8$$8 = NULL, *_4$$9, *_10$$10, *_11$$11 = NULL, *_13$$11 = NULL, *_14$$11 = NULL, *_15$$11 = NULL, *_12$$12;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "A minimum or maximum must be set", "phalcon/validation/validator/stringlength.zep", 62);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "label", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(label)) {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
		zephir_check_call_status();
	}
	if ((zephir_function_exists_ex(SS("mb_strlen") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 360, value);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(length);
		ZVAL_LONG(length, zephir_fast_strlen_ev(value));
	}
	if (zephir_is_true(isSetMax)) {
		ZEPHIR_INIT_VAR(_2$$7);
		ZVAL_STRING(_2$$7, "max", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&maximum, this_ptr, "getoption", NULL, 0, _2$$7);
		zephir_check_temp_parameter(_2$$7);
		zephir_check_call_status();
		if (ZEPHIR_GT(length, maximum)) {
			ZEPHIR_INIT_VAR(_3$$8);
			ZVAL_STRING(_3$$8, "messageMaximum", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _3$$8);
			zephir_check_temp_parameter(_3$$8);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_VAR(_4$$9);
				ZVAL_STRING(_4$$9, "TooLong", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _4$$9);
				zephir_check_temp_parameter(_4$$9);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_3$$8);
			object_init_ex(_3$$8, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_5$$8, "strtr", &_6, 54, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_8$$8);
			ZVAL_STRING(_8$$8, "code", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7$$8, this_ptr, "getoption", NULL, 0, _8$$8);
			zephir_check_temp_parameter(_8$$8);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_8$$8);
			ZVAL_STRING(_8$$8, "TooLong", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _3$$8, "__construct", &_9, 440, _5$$8, field, _8$$8, _7$$8);
			zephir_check_temp_parameter(_8$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _3$$8);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	if (zephir_is_true(isSetMin)) {
		ZEPHIR_INIT_VAR(_10$$10);
		ZVAL_STRING(_10$$10, "min", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&minimum, this_ptr, "getoption", NULL, 0, _10$$10);
		zephir_check_temp_parameter(_10$$10);
		zephir_check_call_status();
		if (ZEPHIR_LT(length, minimum)) {
			ZEPHIR_INIT_VAR(_11$$11);
			ZVAL_STRING(_11$$11, "messageMinimum", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _11$$11);
			zephir_check_temp_parameter(_11$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":min"), &minimum, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_VAR(_12$$12);
				ZVAL_STRING(_12$$12, "TooShort", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _12$$12);
				zephir_check_temp_parameter(_12$$12);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_11$$11);
			object_init_ex(_11$$11, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_13$$11, "strtr", &_6, 54, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_15$$11);
			ZVAL_STRING(_15$$11, "code", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_14$$11, this_ptr, "getoption", NULL, 0, _15$$11);
			zephir_check_temp_parameter(_15$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_15$$11);
			ZVAL_STRING(_15$$11, "TooShort", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _11$$11, "__construct", &_9, 440, _13$$11, field, _15$$11, _14$$11);
			zephir_check_temp_parameter(_15$$11);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _11$$11);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

