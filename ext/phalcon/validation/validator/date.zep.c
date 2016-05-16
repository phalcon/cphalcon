
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
 * Phalcon\Validation\Validator\Date
 *
 * Checks if a value is a valid date
 *
 *<code>
 *use Phalcon\Validation\Validator\Date as DateValidator;
 *
 *$validator->add('date', new DateValidator(array(
 *   'format' => 'd-m-Y',
 *   'message' => 'The date is invalid'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Date) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Date, phalcon, validation_validator_date, phalcon_validation_validator_ce, phalcon_validation_validator_date_method_entry, 0);

	zend_declare_class_constant_string(phalcon_validation_validator_date_ce, SL("DEFAULT_DATE_FORMAT"), "Y-m-d" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Date, validate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *format = NULL, *label = NULL, *message = NULL, *replacePairs = NULL, *_0, *_1 = NULL, *_2$$4 = NULL, *_4$$4 = NULL, *_5$$4, *_3$$6;

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
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "format", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&format, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(format)) {
		ZEPHIR_INIT_NVAR(format);
		ZVAL_STRING(format, "Y-m-d", 1);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "checkdate", NULL, 442, value, format);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _2$$4);
		zephir_check_temp_parameter(_2$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_2$$4);
		ZVAL_STRING(_2$$4, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _2$$4);
		zephir_check_temp_parameter(_2$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_3$$6);
			ZVAL_STRING(_3$$6, "Date", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _3$$6);
			zephir_check_temp_parameter(_3$$6);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_2$$4);
		object_init_ex(_2$$4, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_4$$4, "strtr", NULL, 55, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5$$4);
		ZVAL_STRING(_5$$4, "Date", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 435, _4$$4, field, _5$$4);
		zephir_check_temp_parameter(_5$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _2$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Validation_Validator_Date, checkDate) {

	zend_bool _3;
	zend_class_entry *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *format, *date = NULL, *errors = NULL, *_2, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &format);



	if (!(Z_TYPE_P(value) == IS_STRING)) {
		RETURN_MM_BOOL(0);
	}
		_0 = zend_fetch_class(SL("DateTime"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&date, _0, "createfromformat", NULL, 0, format, value);
	zephir_check_call_status();
		_1 = zend_fetch_class(SL("DateTime"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&errors, _1, "getlasterrors", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, errors, SL("warning_count"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/date.zep", 90 TSRMLS_CC);
	_3 = ZEPHIR_GT_LONG(_2, 0);
	if (!(_3)) {
		zephir_array_fetch_string(&_4, errors, SL("error_count"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/date.zep", 90 TSRMLS_CC);
		_3 = ZEPHIR_GT_LONG(_4, 0);
	}
	if (_3) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

