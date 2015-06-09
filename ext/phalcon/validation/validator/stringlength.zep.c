
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
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_StringLength) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, StringLength, phalcon, validation_validator_stringlength, phalcon_validation_validator_ce, phalcon_validation_validator_stringlength_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_StringLength, validate) {

	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	zend_bool _1, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *isSetMin = NULL, *isSetMax = NULL, *value = NULL, *length = NULL, *message = NULL, *minimum = NULL, *maximum = NULL, *label = NULL, *replacePairs = NULL, *_0 = NULL, *_2 = NULL, *_4 = NULL, *_6 = NULL, *_8;

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
	ZEPHIR_CALL_METHOD(&isSetMin, this_ptr, "issetoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "max", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&isSetMax, this_ptr, "issetoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_1 = !zephir_is_true(isSetMin);
	if (_1) {
		_1 = !zephir_is_true(isSetMax);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "A minimum or maximum must be set", "phalcon/validation/validator/stringlength.zep", 60);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "allowEmpty", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "issetoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_3 = zephir_is_true(_2);
	if (_3) {
		_3 = ZEPHIR_IS_EMPTY(value);
	}
	if (_3) {
		RETURN_MM_BOOL(1);
	}
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
		ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 353, value);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(length);
		ZVAL_LONG(length, zephir_fast_strlen_ev(value));
	}
	if (zephir_is_true(isSetMax)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "max", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&maximum, this_ptr, "getoption", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (ZEPHIR_GT(length, maximum)) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "messageMaximum", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_0);
				ZVAL_STRING(_0, "TooLong", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _0);
				zephir_check_temp_parameter(_0);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_0);
			object_init_ex(_0, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_4, "strtr", &_5, 73, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_6);
			ZVAL_STRING(_6, "TooLong", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_7, 425, _4, field, _6);
			zephir_check_temp_parameter(_6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _0);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	if (zephir_is_true(isSetMin)) {
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "min", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&minimum, this_ptr, "getoption", NULL, 0, _6);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		if (ZEPHIR_LT(length, minimum)) {
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "messageMinimum", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _6);
			zephir_check_temp_parameter(_6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":min"), &minimum, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_STRING(_6, "TooShort", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _6);
				zephir_check_temp_parameter(_6);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_6);
			object_init_ex(_6, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_4, "strtr", &_5, 73, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_8);
			ZVAL_STRING(_8, "TooShort", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_7, 425, _4, field, _8);
			zephir_check_temp_parameter(_8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _6);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

