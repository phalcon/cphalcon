
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

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
 * Phalcon\Validation\Validator\Between
 *
 * Validates that a value is between a range of two values
 *
 *<code>
 *use Phalcon\Validation\Validator\Between;
 *
 *validator->add('name', new Between(array(
 *   'minimum' => 0,
 *   'maximum' => 100,
 *   'message' => 'The price must be between 0 and 100'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Between) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Between, validation_validator_between, "phalcon\\validation\\validator", phalcon_validation_validator_between_method_entry, 0);


	return SUCCESS;

}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation validator
 * @param string attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_Between, validate) {

	zval *validator, *attribute, *value, *minimum, *maximum, *message = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validator, &attribute);



	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, validator, "getvalue", attribute);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "minimum", 1);
	ZEPHIR_INIT_VAR(minimum);
	zephir_call_method_p1(minimum, this_ptr, "getoption", _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "maximum", 1);
	ZEPHIR_INIT_VAR(maximum);
	zephir_call_method_p1(maximum, this_ptr, "getoption", _0);
	if ((ZEPHIR_GE(value, minimum) || ZEPHIR_LE(value, maximum))) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "message", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _0);
		ZEPHIR_INIT_BNVAR(_0);
		zephir_call_func_p1(_0, "is_empty", message);
		if (zend_is_true(_0)) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_VS(message, attribute, " is not between a valid range");
		}
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_validation_message_ce);
		zephir_call_method_p1_noret(validator, "appendmessage", _1);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

