
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
 * Phalcon\Validation\Validator\Confirmation
 *
 * Checks that two values have the same value
 *
 *<code>
 *use Phalcon\Validation\Validator\Confirmation;
 *
 *$validator->add('password', new Confirmation(array(
 *   'message' => 'Password doesn\'t match confirmation',
 *   'with' => 'confirmPassword'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Confirmation) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Confirmation, phalcon, validation_validator_confirmation, phalcon_validation_validator_ce, phalcon_validation_validator_confirmation_method_entry, 0);

	zend_class_implements(phalcon_validation_validator_confirmation_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;

}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_Confirmation, validate) {

	zval *field = NULL;
	zval *validation, *field_param = NULL, *withAttribute, *value, *withValue, *message = NULL, *label = NULL, *replacePairs, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

		zephir_get_strval(field, field_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "with", 1);
	ZEPHIR_INIT_VAR(withAttribute);
	zephir_call_method_p1(withAttribute, this_ptr, "getoption", _0);
	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, validation, "getvalue", field);
	ZEPHIR_INIT_VAR(withValue);
	zephir_call_method_p1(withValue, validation, "getvalue", withAttribute);
	if (!ZEPHIR_IS_EQUAL(value, withValue)) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "label", 1);
		ZEPHIR_INIT_VAR(label);
		zephir_call_method_p1(label, this_ptr, "getoption", _0);
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CPY_WRT(label, field);
		}
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "message", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _0);
		ZEPHIR_INIT_VAR(replacePairs);
		array_init(replacePairs);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replacePairs, SL(":with"), &withAttribute, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_BNVAR(_0);
			ZVAL_STRING(_0, "Confirmation", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, validation, "getdefaultmessage", _0);
		}
		ZEPHIR_INIT_BNVAR(_0);
		object_init_ex(_0, phalcon_validation_message_ce);
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func_p2(_1, "strtr", message, replacePairs);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "Confirmation", 1);
		zephir_call_method_p3_noret(_0, "__construct", _1, field, _2);
		zephir_call_method_p1_noret(validation, "appendmessage", _0);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

