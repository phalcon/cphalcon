
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 |          Jason Rice                                                    |
 +------------------------------------------------------------------------+
 */
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
 *		this->validate(new StringLengthValidator(array(
 *			"field" => 'name_last',
 *			'max' => 50,
 *			'min' => 2,
 *			'messageMaximum' => 'We don\'t like really long names',
 *			'messageMinimum' => 'We want more than just their initials'
 *		)));
 *		if (this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_StringLength) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, StringLength, phalcon, mvc_model_validator_stringlength, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_stringlength_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_stringlength_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);
	return SUCCESS;

}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\ModelInterface record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_StringLength, validate) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	zval *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool invalidMaximum, invalidMinimum, _1, _3;
	zval *record, *field = NULL, *isSetMin = NULL, *isSetMax = NULL, *value = NULL, *length = NULL, *maximum = NULL, *minimum = NULL, *message = NULL, *_0, *_2 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	if (!(zephir_instance_of_ev(record, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'record' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "field", 0);
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(field) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Field name must be a string", "phalcon/mvc/model/validator/stringlength.zep", 71);
		return;
	}
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "min", 0);
	ZEPHIR_CALL_METHOD(&isSetMin, this_ptr, "issetoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "max", 0);
	ZEPHIR_CALL_METHOD(&isSetMax, this_ptr, "issetoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_1 = !zephir_is_true(isSetMin);
	if (_1) {
		_1 = !zephir_is_true(isSetMax);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A minimum or maximum must be set", "phalcon/mvc/model/validator/stringlength.zep", 81);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, record, "readattribute", NULL, field);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "allowEmpty", 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "issetoption", NULL, _0);
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
		ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, value);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(length);
		ZVAL_LONG(length, zephir_fast_strlen_ev(value));
	}
	invalidMaximum = 0;
	invalidMinimum = 0;
	if (zephir_is_true(isSetMax)) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "max", 0);
		ZEPHIR_CALL_METHOD(&maximum, this_ptr, "getoption", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (ZEPHIR_GT(length, maximum)) {
			ZEPHIR_INIT_BNVAR(_0);
			ZVAL_STRING(_0, "messageMaximum", 0);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(message);
				ZVAL_STRING(message, "Value of field ':field' exceeds the maximum :max characters", 1);
			}
			ZEPHIR_INIT_VAR(_4);
			array_init_size(_4, 3);
			zephir_array_update_string(&_4, SL(":field"), &field, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_5, "strtr", &_6, message, _4);
			zephir_check_call_status();
			ZEPHIR_INIT_BNVAR(_0);
			ZVAL_STRING(_0, "TooLong", 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, _5, field, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	if (zephir_is_true(isSetMin)) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "min", 0);
		ZEPHIR_CALL_METHOD(&minimum, this_ptr, "getoption", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (ZEPHIR_LT(length, minimum)) {
			ZEPHIR_INIT_BNVAR(_0);
			ZVAL_STRING(_0, "messageMinimum", 0);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(message);
				ZVAL_STRING(message, "Value of field ':field' is less than the minimum :min characters", 1);
			}
			ZEPHIR_INIT_NVAR(_4);
			array_init_size(_4, 3);
			zephir_array_update_string(&_4, SL(":field"), &field, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4, SL(":min"), &minimum, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_5, "strtr", &_6, message, _4);
			zephir_check_call_status();
			ZEPHIR_INIT_BNVAR(_0);
			ZVAL_STRING(_0, "TooShort", 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, _5, field, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

