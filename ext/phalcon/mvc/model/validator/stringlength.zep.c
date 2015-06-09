
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
 *<code>
 *use Phalcon\Mvc\Model\Validator\StringLength as StringLengthValidator;
 *
 *class Subscriptors extends \Phalcon\Mvc\Model
 *{
 *
 *	public function validation()
 *	{
 *		$this->validate(new StringLengthValidator(array(
 *			"field" => 'name_last',
 *			'max' => 50,
 *			'min' => 2,
 *			'messageMaximum' => 'We don\'t like really long names',
 *			'messageMinimum' => 'We want more than just their initials'
 *		)));
 *		if ($this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_StringLength) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, StringLength, phalcon, mvc_model_validator_stringlength, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_stringlength_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_stringlength_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);
	return SUCCESS;

}

/**
 * Executes the validator
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_StringLength, validate) {

	zephir_fcall_cache_entry *_6 = NULL;
	zval *_4 = NULL;
	zend_bool _1, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *record, *field = NULL, *isSetMin = NULL, *isSetMax = NULL, *value = NULL, *length = NULL, *maximum = NULL, *minimum = NULL, *message = NULL, *_0 = NULL, *_2 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "field", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(field) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Field name must be a string", "phalcon/mvc/model/validator/stringlength.zep", 67);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A minimum or maximum must be set", "phalcon/mvc/model/validator/stringlength.zep", 77);
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
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(message);
				ZVAL_STRING(message, "Value of field ':field' exceeds the maximum :max characters", 1);
			}
			ZEPHIR_INIT_VAR(_4);
			zephir_create_array(_4, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&_4, SL(":field"), &field, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_5, "strtr", &_6, 73, message, _4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "TooLong", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, _5, field, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	if (zephir_is_true(isSetMin)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "min", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&minimum, this_ptr, "getoption", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (ZEPHIR_LT(length, minimum)) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "messageMinimum", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(message);
				ZVAL_STRING(message, "Value of field ':field' is less than the minimum :min characters", 1);
			}
			ZEPHIR_INIT_NVAR(_4);
			zephir_create_array(_4, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&_4, SL(":field"), &field, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4, SL(":min"), &minimum, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_5, "strtr", &_6, 73, message, _4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "TooShort", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, _5, field, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

