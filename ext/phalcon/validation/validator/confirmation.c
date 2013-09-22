
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
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * @param Phalcon\Validation validator
 * @param string attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_Confirmation, validate) {

	zval *validator, *attribute, *withAttribute, *value, *withValue, *message = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validator, &attribute);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "with", 1);
	ZEPHIR_INIT_VAR(withAttribute);
	zephir_call_method_p1(withAttribute, this_ptr, "getoption", _0);
	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, validator, "getvalue", attribute);
	ZEPHIR_INIT_VAR(withValue);
	zephir_call_method_p1(withValue, validator, "getvalue", withAttribute);
	if (!ZEPHIR_IS_EQUAL(value, withValue)) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "message", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _0);
		if (0) {
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_CONCAT_SV(_1, "Value of '", attribute);
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_CONCAT_VS(_2, _1, "' and '");
			ZEPHIR_INIT_VAR(_3);
			concat_function(_3, _2, withAttribute TSRMLS_CC);
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_VS(message, _3, "' don\'t match");
		}
		ZEPHIR_INIT_BNVAR(_0);
		object_init_ex(_0, phalcon_validation_message_ce);
		zephir_call_method_p1_noret(validator, "appendmessage", _0);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

