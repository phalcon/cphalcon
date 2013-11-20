
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
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
 * Phalcon\Validation\Validator\Regex
 *
 * Allows validate if the value of a field matches a regular expression
 *
 *<code>
 *use Phalcon\Validation\Validator\Regex as RegexValidator;
 *
 *$validator->add('created_at', new RegexValidator(array(
 *   'pattern' => '/^[0-9]{4}[-\/](0[1-9]|1[12])[-\/](0[1-9]|[12][0-9]|3[01])$/',
 *   'message' => 'The creation date is invalid'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Regex) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Regex, phalcon, validation_validator_regex, phalcon_validation_validator_ce, phalcon_validation_validator_regex_method_entry, 0);

	zend_class_implements(phalcon_validation_validator_regex_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;

}

/**
 * Executes the validation
 *
 * @param  Phalcon\Validation validator
 * @param  string attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_Regex, validate) {

	zend_bool failed;
	zval *validator, *attribute, *matches, *message = NULL, *value, *_0, *_1, *_2, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validator, &attribute);



	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);
	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, validator, "getvalue", attribute);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "pattern", 1);
	zephir_call_method_p1(_0, this_ptr, "getoption", _1);
	Z_SET_ISREF_P(matches);
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_func_p3(_1, "preg_match", _0, value, matches);
	if (zephir_is_true(_1)) {
		zephir_array_fetch_long(&_2, matches, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		failed = !ZEPHIR_IS_EQUAL(_2, value);
	} else {
		failed = 1;
	}
	if ((failed == 1)) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "message", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _3);
		if (!(zephir_is_true(message))) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVS(message, "Value of field '", attribute, "' doesn't match regular expression");
		}
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, phalcon_validation_message_ce);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "Regex", 1);
		zephir_call_method_p3_noret(_3, "__construct", message, attribute, _4);
		zephir_call_method_p1_noret(validator, "appendmessage", _3);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

