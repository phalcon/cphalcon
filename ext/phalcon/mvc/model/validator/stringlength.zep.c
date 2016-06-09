
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

	zval _6$$9, _11$$12;
	zend_bool _1, _3;
	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *record, record_sub, field, isSetMin, isSetMax, value, length, maximum, minimum, message, _0, _2, _4$$8, _5$$9, _7$$9, _9$$11, _10$$12, _12$$12;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&isSetMin);
	ZVAL_UNDEF(&isSetMax);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&maximum);
	ZVAL_UNDEF(&minimum);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_11$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "field");
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&field) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Field name must be a string", "phalcon/mvc/model/validator/stringlength.zep", 67);
		return;
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "min");
	ZEPHIR_CALL_METHOD(&isSetMin, this_ptr, "issetoption", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "max");
	ZEPHIR_CALL_METHOD(&isSetMax, this_ptr, "issetoption", NULL, 0, &_0);
	zephir_check_call_status();
	_1 = !zephir_is_true(&isSetMin);
	if (_1) {
		_1 = !zephir_is_true(&isSetMax);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A minimum or maximum must be set", "phalcon/mvc/model/validator/stringlength.zep", 77);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, record, "readattribute", NULL, 0, &field);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "allowEmpty");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "issetoption", NULL, 0, &_0);
	zephir_check_call_status();
	_3 = zephir_is_true(&_2);
	if (_3) {
		_3 = ZEPHIR_IS_EMPTY(&value);
	}
	if (_3) {
		RETURN_MM_BOOL(1);
	}
	if ((zephir_function_exists_ex(SL("mb_strlen") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 379, &value);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&length);
		ZVAL_LONG(&length, zephir_fast_strlen_ev(&value));
	}
	if (zephir_is_true(&isSetMax)) {
		ZEPHIR_INIT_VAR(&_4$$8);
		ZVAL_STRING(&_4$$8, "max");
		ZEPHIR_CALL_METHOD(&maximum, this_ptr, "getoption", NULL, 0, &_4$$8);
		zephir_check_call_status();
		if (ZEPHIR_GT(&length, &maximum)) {
			ZEPHIR_INIT_VAR(&_5$$9);
			ZVAL_STRING(&_5$$9, "messageMaximum");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_5$$9);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(&message)) {
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_STRING(&message, "Value of field ':field' exceeds the maximum :max characters");
			}
			ZEPHIR_INIT_VAR(&_6$$9);
			zephir_create_array(&_6$$9, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&_6$$9, SL(":field"), &field, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_6$$9, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_7$$9, "strtr", &_8, 55, &message, &_6$$9);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_5$$9);
			ZVAL_STRING(&_5$$9, "TooLong");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, &_7$$9, &field, &_5$$9);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	if (zephir_is_true(&isSetMin)) {
		ZEPHIR_INIT_VAR(&_9$$11);
		ZVAL_STRING(&_9$$11, "min");
		ZEPHIR_CALL_METHOD(&minimum, this_ptr, "getoption", NULL, 0, &_9$$11);
		zephir_check_call_status();
		if (ZEPHIR_LT(&length, &minimum)) {
			ZEPHIR_INIT_VAR(&_10$$12);
			ZVAL_STRING(&_10$$12, "messageMinimum");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_10$$12);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(&message)) {
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_STRING(&message, "Value of field ':field' is less than the minimum :min characters");
			}
			ZEPHIR_INIT_VAR(&_11$$12);
			zephir_create_array(&_11$$12, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&_11$$12, SL(":field"), &field, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_11$$12, SL(":min"), &minimum, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_12$$12, "strtr", &_8, 55, &message, &_11$$12);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$12);
			ZVAL_STRING(&_10$$12, "TooShort");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, &_12$$12, &field, &_10$$12);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

