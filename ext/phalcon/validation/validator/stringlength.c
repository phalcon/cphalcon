
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
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


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
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Validation\Validator\StringLength
 *
 * Validates that a string has the specified maximum and minimum constraints
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

	zend_class_implements(phalcon_validation_validator_stringlength_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;

}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_StringLength, validate) {

	zend_bool _1, _3;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *isSetMin, *isSetMax, *value, *length, *message = NULL, *minimum, *maximum, *label = NULL, *replacePairs = NULL, *_0, *_2, *_4 = NULL, *_5 = NULL, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(field_param) == IS_STRING) {
		field = field_param;
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "min", 1);
	ZEPHIR_INIT_VAR(isSetMin);
	zephir_call_method_p1(isSetMin, this_ptr, "issetoption", _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "max", 1);
	ZEPHIR_INIT_VAR(isSetMax);
	zephir_call_method_p1(isSetMax, this_ptr, "issetoption", _0);
	_1 = !zephir_is_true(isSetMin);
	if (_1) {
		_1 = !zephir_is_true(isSetMax);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "A minimum or maximum must be set");
		return;
	}
	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, validation, "getvalue", field);
	ZEPHIR_INIT_BNVAR(_0);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "allowEmpty", 1);
	zephir_call_method_p1(_0, this_ptr, "issetoption", _2);
	_3 = zephir_is_true(_0);
	if (_3) {
		_3 = ZEPHIR_IS_EMPTY(value);
	}
	if (_3) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "label", 1);
	ZEPHIR_INIT_VAR(label);
	zephir_call_method_p1(label, this_ptr, "getoption", _2);
	if (ZEPHIR_IS_EMPTY(label)) {
		ZEPHIR_INIT_BNVAR(label);
		zephir_call_method_p1(label, validation, "getlabel", field);
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CPY_WRT(label, field);
		}
	}
	ZEPHIR_INIT_VAR(length);
	if ((zephir_function_exists_ex(SS("mb_strlen") TSRMLS_CC) == SUCCESS)) {
		zephir_call_func_p1(length, "mb_strlen", value);
	} else {
		ZVAL_LONG(length, zephir_fast_strlen_ev(value));
	}
	if (zephir_is_true(isSetMax)) {
		ZEPHIR_INIT_BNVAR(_2);
		ZVAL_STRING(_2, "max", 1);
		ZEPHIR_INIT_VAR(maximum);
		zephir_call_method_p1(maximum, this_ptr, "getoption", _2);
		if (ZEPHIR_GT(length, maximum)) {
			ZEPHIR_INIT_BNVAR(_2);
			ZVAL_STRING(_2, "messageMaximum", 1);
			ZEPHIR_INIT_VAR(message);
			zephir_call_method_p1(message, this_ptr, "getoption", _2);
			ZEPHIR_INIT_VAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_BNVAR(_2);
				ZVAL_STRING(_2, "TooLong", 1);
				ZEPHIR_INIT_NVAR(message);
				zephir_call_method_p1(message, validation, "getdefaultmessage", _2);
			}
			ZEPHIR_INIT_VAR(_4);
			object_init_ex(_4, phalcon_validation_message_ce);
			ZEPHIR_INIT_BNVAR(_2);
			zephir_call_func_p2(_2, "strtr", message, replacePairs);
			ZEPHIR_INIT_VAR(_5);
			ZVAL_STRING(_5, "TooLong", 1);
			zephir_call_method_p3_noret(_4, "__construct", _2, field, _5);
			zephir_call_method_p1_noret(validation, "appendmessage", _4);
			RETURN_MM_BOOL(0);
		}
	}
	if (zephir_is_true(isSetMin)) {
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "min", 1);
		ZEPHIR_INIT_VAR(minimum);
		zephir_call_method_p1(minimum, this_ptr, "getoption", _5);
		if (ZEPHIR_LT(length, minimum)) {
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "messageMinimum", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, this_ptr, "getoption", _5);
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":min"), &minimum, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_STRING(_5, "TooShort", 1);
				ZEPHIR_INIT_NVAR(message);
				zephir_call_method_p1(message, validation, "getdefaultmessage", _5);
			}
			ZEPHIR_INIT_LNVAR(_4);
			object_init_ex(_4, phalcon_validation_message_ce);
			ZEPHIR_INIT_NVAR(_5);
			zephir_call_func_p2(_5, "strtr", message, replacePairs);
			ZEPHIR_INIT_VAR(_6);
			ZVAL_STRING(_6, "TooShort", 1);
			zephir_call_method_p3_noret(_4, "__construct", _5, field, _6);
			zephir_call_method_p1_noret(validation, "appendmessage", _4);
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

