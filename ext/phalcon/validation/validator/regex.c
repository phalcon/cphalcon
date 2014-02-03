
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
 * @param  Phalcon\Validation validation
 * @param  string field
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_Regex, validate) {

	zend_bool failed, _2;
	zval *validation, *field, *matches, *message = NULL, *value, *label = NULL, *replacePairs, *_0, *_1, *_3, *_4, *_5, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);
	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, validation, "getvalue", field);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "allowEmpty", 1);
	zephir_call_method_p1(_0, this_ptr, "issetoption", _1);
	_2 = zephir_is_true(_0);
	if (_2) {
		_2 = ZEPHIR_IS_EMPTY(value);
	}
	if (_2) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_BNVAR(_1);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "pattern", 1);
	zephir_call_method_p1(_3, this_ptr, "getoption", _4);
	zephir_preg_match(_1, &(_1), _3, value, matches, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_1)) {
		zephir_array_fetch_long(&_5, matches, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		failed = !ZEPHIR_IS_EQUAL(_5, value);
	} else {
		failed = 1;
	}
	if ((failed == 1)) {
		ZEPHIR_INIT_BNVAR(_4);
		ZVAL_STRING(_4, "label", 1);
		ZEPHIR_INIT_VAR(label);
		zephir_call_method_p1(label, this_ptr, "getoption", _4);
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_INIT_NVAR(label);
			zephir_call_method_p1(label, validation, "getlabel", field);
			if (ZEPHIR_IS_EMPTY(label)) {
				ZEPHIR_CPY_WRT(label, field);
			}
		}
		ZEPHIR_INIT_BNVAR(_4);
		ZVAL_STRING(_4, "message", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _4);
		ZEPHIR_INIT_VAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_BNVAR(_4);
			ZVAL_STRING(_4, "Regex", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, validation, "getdefaultmessage", _4);
		}
		ZEPHIR_INIT_VAR(_6);
		object_init_ex(_6, phalcon_validation_message_ce);
		ZEPHIR_INIT_BNVAR(_4);
		zephir_call_func_p2(_4, "strtr", message, replacePairs);
		ZEPHIR_INIT_VAR(_7);
		ZVAL_STRING(_7, "Regex", 1);
		zephir_call_method_p3_noret(_6, "__construct", _4, field, _7);
		zephir_call_method_p1_noret(validation, "appendmessage", _6);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

