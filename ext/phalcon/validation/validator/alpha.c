
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
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
 * Phalcon\Validation\Validator\Alpha
 *
 * Check for alphabetic character(s)
 *
 *<code>
 *use Phalcon\Validation\Validator\Alpha as AlphaValidator;
 *
 *$validator->add('username', new AlphaValidator(array(
 *   'message' => ':field must contain only letters'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Alpha) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Alpha, phalcon, validation_validator_alpha, phalcon_validation_validator_ce, phalcon_validation_validator_alpha_method_entry, 0);

	zend_class_implements(phalcon_validation_validator_alpha_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);
	return SUCCESS;

}

/**
 * Executes the validation
 *
 * @param  Phalcon\Validation validation
 * @param  string             field
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_Alpha, validate) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value, *message = NULL, *label = NULL, *replacePairs, *_0, *_1, *_3 = NULL, *_4, *_5;

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


	if (!(zephir_instance_of_ev(validation, phalcon_validation_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'validation' must be an instance of 'Phalcon\\Validation'");
		return;
	}
	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, validation, "getvalue", field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "allowEmpty", 1);
	zephir_call_method_p1(_0, this_ptr, "issetoption", _1);
	zephir_check_call_status();
	_2 = zephir_is_true(_0);
	if (_2) {
		_2 = ZEPHIR_IS_EMPTY(value);
	}
	if (_2) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_func_p1(_1, "ctype_alpha", value);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "label", 1);
		ZEPHIR_INIT_VAR(label);
		zephir_call_method_p1(label, this_ptr, "getoption", _3);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_INIT_NVAR(label);
			zephir_call_method_p1(label, validation, "getlabel", field);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(label)) {
				ZEPHIR_CPY_WRT(label, field);
			}
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "message", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "Alpha", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, validation, "getdefaultmessage", _3);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_4);
		object_init_ex(_4, phalcon_validation_message_ce);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_func_p2(_3, "strtr", message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "Alpha", 1);
		zephir_call_method_p3_noret(_4, "__construct", _3, field, _5);
		zephir_check_call_status();
		zephir_call_method_p1_noret(validation, "appendmessage", _4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

