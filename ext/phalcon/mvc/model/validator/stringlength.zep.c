
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * Phalcon\Mvc\Model\Validator\StringLength
 *
 * Simply validates specified string length constraints
 *
 * This validator is only for use with Phalcon\Mvc\Collection. If you are using
 * Phalcon\Mvc\Model, please use the validators provided by Phalcon\Validation.
 *
 *<code>
 * use Phalcon\Mvc\Model\Validator\StringLength as StringLengthValidator;
 *
 * class Subscriptors extends \Phalcon\Mvc\Collection
 * {
 *     public function validation()
 *     {
 *         $this->validate(
 *             new StringLengthValidator(
 *                 [
 *                     "field"          => "name_last",
 *                     "max"            => 50,
 *                     "min"            => 2,
 *                     "messageMaximum" => "We don't like really long names",
 *                     "messageMinimum" => "We want more than just their initials",
 *                 ]
 *             )
 *         );
 *
 *         if ($this->validationHasFailed() === true) {
 *             return false;
 *         }
 *     }
 * }
 *</code>
 *
 * @deprecated 3.1.0
 * @see Phalcon\Validation\Validator\StringLength
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_StringLength) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, StringLength, phalcon, mvc_model_validator_stringlength, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_stringlength_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validator
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_StringLength, validate) {

	zval *_6$$9, *_10$$12;
	zend_bool _1, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *record, *field = NULL, *isSetMin = NULL, *isSetMax = NULL, *value = NULL, *length = NULL, *maximum = NULL, *minimum = NULL, *message = NULL, *_0 = NULL, *_2 = NULL, *_4$$8, *_5$$9 = NULL, *_7$$9 = NULL, *_8$$11, *_9$$12 = NULL, *_11$$12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "field", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(field) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Field name must be a string", "phalcon/mvc/model/validator/stringlength.zep", 75);
		return;
	}
	ZEPHIR_INIT_NVAR(_0);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A minimum or maximum must be set", "phalcon/mvc/model/validator/stringlength.zep", 85);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, record, "readattribute", NULL, 0, field);
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
	if ((zephir_function_exists_ex(SS("mb_strlen") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 238, value);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(length);
		ZVAL_LONG(length, zephir_fast_strlen_ev(value));
	}
	if (zephir_is_true(isSetMax)) {
		ZEPHIR_INIT_VAR(_4$$8);
		ZVAL_STRING(_4$$8, "max", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&maximum, this_ptr, "getoption", NULL, 0, _4$$8);
		zephir_check_temp_parameter(_4$$8);
		zephir_check_call_status();
		if (ZEPHIR_GT(length, maximum)) {
			ZEPHIR_INIT_VAR(_5$$9);
			ZVAL_STRING(_5$$9, "messageMaximum", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _5$$9);
			zephir_check_temp_parameter(_5$$9);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(message);
				ZVAL_STRING(message, "Value of field ':field' exceeds the maximum :max characters", 1);
			}
			ZEPHIR_INIT_VAR(_6$$9);
			zephir_create_array(_6$$9, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&_6$$9, SL(":field"), &field, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_6$$9, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_7$$9, "strtr", NULL, 27, message, _6$$9);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_5$$9);
			ZVAL_STRING(_5$$9, "TooLong", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, _7$$9, field, _5$$9);
			zephir_check_temp_parameter(_5$$9);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	if (zephir_is_true(isSetMin)) {
		ZEPHIR_INIT_VAR(_8$$11);
		ZVAL_STRING(_8$$11, "min", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&minimum, this_ptr, "getoption", NULL, 0, _8$$11);
		zephir_check_temp_parameter(_8$$11);
		zephir_check_call_status();
		if (ZEPHIR_LT(length, minimum)) {
			ZEPHIR_INIT_VAR(_9$$12);
			ZVAL_STRING(_9$$12, "messageMinimum", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _9$$12);
			zephir_check_temp_parameter(_9$$12);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(message);
				ZVAL_STRING(message, "Value of field ':field' is less than the minimum :min characters", 1);
			}
			ZEPHIR_INIT_VAR(_10$$12);
			zephir_create_array(_10$$12, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&_10$$12, SL(":field"), &field, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_10$$12, SL(":min"), &minimum, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_11$$12, "strtr", NULL, 27, message, _10$$12);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_9$$12);
			ZVAL_STRING(_9$$12, "TooShort", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, _11$$12, field, _9$$12);
			zephir_check_temp_parameter(_9$$12);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

