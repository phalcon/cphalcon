
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Validation\Validator\Callback
 *
 * Calls user function for validation
 *
 * <code>
 * use Phalcon\Validation\Validator\Callback as CallbackValidator;
 * use Phalcon\Validation\Validator\Numericality as NumericalityValidator;
 *
 * $validator->add(
 *     ["user", "admin"],
 *     new CallbackValidator(
 *         [
 *             "message" => "There must be only an user or admin set",
 *             "callback" => function($data) {
 *                 if (!empty($data->getUser()) && !empty($data->getAdmin())) {
 *                     return false;
 *                 }
 *
 *                 return true;
 *             }
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     "amount",
 *     new CallbackValidator(
 *         [
 *             "callback" => function($data) {
 *                 if (!empty($data->getProduct())) {
 *                     return new NumericalityValidator(
 *                         [
 *                             "message" => "Amount must be a number."
 *                         ]
 *                     );
 *                 }
 *             }
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Callback) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Callback, phalcon, validation_validator_callback, phalcon_validation_validator_ce, phalcon_validation_validator_callback_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Callback, validate) {

	zend_bool _1$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *code = NULL, *callback = NULL, *returnedValue = NULL, *data = NULL, *_0, *_2$$6 = NULL, *_7$$6 = NULL, *_8$$6, *_3$$7, *_4$$9, *_5$$10, *_6$$11;

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
	ZVAL_STRING(_0, "callback", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&callback, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_callable(callback TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&data, validation, "getentity", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(data)) {
			ZEPHIR_CALL_METHOD(&data, validation, "getdata", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_FUNCTION(&returnedValue, "call_user_func", NULL, 398, callback, data);
		zephir_check_call_status();
		_1$$3 = Z_TYPE_P(returnedValue) == IS_OBJECT;
		if (_1$$3) {
			_1$$3 = zephir_instance_of_ev(returnedValue, phalcon_validation_validator_ce TSRMLS_CC);
		}
		if (Z_TYPE_P(returnedValue) == IS_BOOL) {
			if (!(zephir_is_true(returnedValue))) {
				ZEPHIR_INIT_VAR(_2$$6);
				ZVAL_STRING(_2$$6, "label", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _2$$6);
				zephir_check_temp_parameter(_2$$6);
				zephir_check_call_status();
				if (Z_TYPE_P(label) == IS_ARRAY) {
					zephir_array_fetch(&_3$$7, label, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/callback.zep", 90 TSRMLS_CC);
					ZEPHIR_CPY_WRT(label, _3$$7);
				}
				if (ZEPHIR_IS_EMPTY(label)) {
					ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(_2$$6);
				ZVAL_STRING(_2$$6, "message", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _2$$6);
				zephir_check_temp_parameter(_2$$6);
				zephir_check_call_status();
				if (Z_TYPE_P(message) == IS_ARRAY) {
					zephir_array_fetch(&_4$$9, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/callback.zep", 98 TSRMLS_CC);
					ZEPHIR_CPY_WRT(message, _4$$9);
				}
				ZEPHIR_INIT_VAR(replacePairs);
				zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
				zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				if (ZEPHIR_IS_EMPTY(message)) {
					ZEPHIR_INIT_VAR(_5$$10);
					ZVAL_STRING(_5$$10, "Callback", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _5$$10);
					zephir_check_temp_parameter(_5$$10);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(_2$$6);
				ZVAL_STRING(_2$$6, "code", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&code, this_ptr, "getoption", NULL, 0, _2$$6);
				zephir_check_temp_parameter(_2$$6);
				zephir_check_call_status();
				if (Z_TYPE_P(code) == IS_ARRAY) {
					zephir_array_fetch(&_6$$11, code, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/callback.zep", 107 TSRMLS_CC);
					ZEPHIR_CPY_WRT(code, _6$$11);
				}
				ZEPHIR_INIT_NVAR(_2$$6);
				object_init_ex(_2$$6, phalcon_validation_message_ce);
				ZEPHIR_CALL_FUNCTION(&_7$$6, "strtr", NULL, 26, message, replacePairs);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_8$$6);
				ZVAL_STRING(_8$$6, "Callback", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _2$$6, "__construct", NULL, 464, _7$$6, field, _8$$6, code);
				zephir_check_temp_parameter(_8$$6);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _2$$6);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
			RETURN_MM_BOOL(1);
		} else if (_1$$3) {
			ZEPHIR_RETURN_CALL_METHOD(returnedValue, "validate", NULL, 0, validation, field);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_validator_exception_ce, "Callback must return boolean or Phalcon\\Validation\\Validator object", "phalcon/validation/validator/callback.zep", 119);
		return;
	}
	RETURN_MM_BOOL(1);

}

